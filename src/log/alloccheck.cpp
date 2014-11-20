/*
www.sourceforge.net/projects/tinyxml
Original code by Lee Thomason (www.grinninglizard.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.


Modified by Richard Albrecht:
- adapted, using more C++
- locator 'xml_locator' for simple searching/changing the xml document
- code simplified, most of the comments removed, code is self explaning
- class 'rawbuffer_pos' for moving through a vector<char>,
- logger (can be used separately)
- some help methods for strings (can be used separately)
- check of new/delete (code is a small howto overload new/delete example)
- an example, how to use  the parser in your code is in 'main.cpp'

www.rleofield.de

Linux User Group Ottobrunn / München Südost (LOMSO)
www.lug-ottobrunn.de
*/


#include <vector>

#include <boost/thread/mutex.hpp>
#include <boost/lexical_cast.hpp>

//#include "stringhelper.h"
#include "tLog_Category_A.h"
#include "tLfm.h"
using rlf_tlfm::t_lfm;

#include "alloccheck.h"

using namespace std;


/**
     Überladung von new mit Markern:

     Jeder Aufruf von new/delete wird prokolliert.
     Im allozierten Speicher wird am bein Aufruf von New() eine Struktur eingefügt,
     die bei Delete geprüft wird.
     Alle new/delete werden in einer STL-Map abglegt.
     Am Programmende wird die Map ausgegeben.
     Wenn es zu jedem new ein Delete gibt, ist die Map am Programmende leer.
     */

namespace alloccheck {

   inline std::string to_str( int val ) {
      std::ostringstream o;
      o << std::fixed << val ;
      return  o.str();
   }


   template<bool v>
   struct int2type {
      enum { value = v };
   };


   string clip_at_pos( string const& s, size_t pos ) {
      if( s.size() > 0 ) {
         size_t i = pos;

         if( i != string::npos ) {
            return s.substr( 0, i ) ;
         }
      }

      return s;
   }


   t_alloccheck& alloccheckInstance() {
      static t_alloccheck _alloccheckInstance;
      return  _alloccheckInstance;
   }

   const char pathSlash = '/';

   string extractFile( string const&  path_file ) {
      size_t i = path_file.rfind( pathSlash );

      if( i  != string::npos ) {
         return "'" + path_file.substr( i + 1 ) + "'";
      }

      //slash not found
      return path_file;
   }

   // help structure 'AllocHeader', to maintain new/delete info

   const size_t maxalloc = 32; // max length of filename, classname, methodname in help struct 'AllocHeader'
   const size_t maxallocinfo = 128; // max length of logging info in 'AllocHeader'
   struct alloc_header {     // Header, der jedem Speicherbereich vorangestellt wird
      size_t size;           // size of allocaed memory
      size_t line;           // line where new() was called
      size_t magic;          // magic number, added at end of allocated memory, test for buffer overflows
      char file[maxalloc];     // filename
      char info[maxallocinfo]; // short info msg
      char _class[maxalloc];   // Name der Klasse, in der new/delete aufgerufen wurde
      char function[maxalloc]; // Name der function, in der new/delete aufgerufen wurde
   };

#ifdef __linux__
   static boost::mutex MUTEX;   // locking new/delete in concurrent threads
#endif



   // marker string in log,
   //   useful for searching with grep in logs
   string grepMarker = "shp";

   //////////////////////////////////////////////////////////////////////////////////////
   // called by new(), logs line, method name, class name
   void* checked_alloc( int2type<false>, size_t size, rlf_tlfm::t_lfm const& )  {
      char* p = ::new char[size];
      return p;
   }


   void* checked_alloc( int2type<true>, size_t size, rlf_tlfm::t_lfm const& lfm )  {


      // request raw memory, size += sizeof(AllocHeader) + magic number at begin and end of memory ( 2 x 32/64bit)
      char* p = ::new( nothrow ) char[sizeof( alloc_header ) + size + sizeof( size_t )];

      if( nullptr == p ) {
         throw "allocation fails : no free memory available";
      }

      auto p_start = p + sizeof( alloc_header );
      auto p_magicend = p + sizeof( alloc_header ) + size;

      auto line = lfm.line();
      auto file = lfm.file();
      auto method = lfm.method();

      // strip path from file
      file = extractFile( file );

      // clip file, method and class names
      file = clip_at_pos( file, maxalloc - 1 );
      method = clip_at_pos( method, maxalloc - 1 );

      auto pHeader = reinterpret_cast<alloc_header*>(p);

      if( file.size() > maxalloc - 1 ) {
         file = file.substr( 0, maxalloc - 1 );
      }

      auto & check = alloccheckInstance();


      // build info message for logging
      auto info = "alloc/sum: " + to_str( ( int )size ) + "/" + to_str( check.totalalloc() )
                    + ", fn: " +  file
                    + ", m: " +  method
                    + ", l: " + to_str( line );

      // clip info
      if( info.length() > maxallocinfo - 1 ) {
         info = info.substr( 0, maxallocinfo - 1 );
      }

      pHeader->size = size;
      pHeader->line = line;
      pHeader->magic = rand();

      pHeader->file[0] = 0;
      pHeader->info[0] = 0;

      // use low level string functions
      ::strncat( pHeader->file, file.c_str(), file.size() );
      ::strncat( pHeader->info, info.c_str(), info.size() );

      *( reinterpret_cast<size_t*>(p_magicend) ) = pHeader->magic;

      auto key = reinterpret_cast< size_t>(pHeader);
      {
         //nsl::tLock l(m);
         check.incr_alloccount();
         check.totalalloc_add( static_cast<int>( size ) );
         auto & allocList = check.getMutableAlloclist();
         auto it = allocList.find( key );

         if( it != allocList.end() ) {
            string ll = grepMarker + " 'allocs map has used key':  " + to_str( key ) + ", info: " + info + "'";
            LOGT_A_INFO( ll );
            exit( 0 );
         }

         allocList[key] = info;
      }
      auto logLine = grepMarker + ", alloc, cnt: " + to_str( check.alloccount() ) + ", info: " + info;
      LOGT_A_INFO( logLine );
      return p_start;

   }
   ////////////////////////////////////////////////////////////////////////////////////////////
   // wird von delete() aufgerufen
   void checked_delete( int2type<false>, void* p )  {
      delete []( ( char* )p );
      return;
   }
   void checked_delete( int2type<true>, void* p )  {

      auto p_start = (reinterpret_cast<char*>( p ) - sizeof( alloc_header ) );

      auto* pHeader = reinterpret_cast<alloc_header*>( p_start );
      pHeader->file[maxalloc - 1] = 0;
      pHeader->info[maxallocinfo - 1] = 0;
      pHeader->_class[maxalloc - 1] = 0;

      auto file = pHeader->file;
      auto info = pHeader->info;
      auto size = pHeader->size;
      auto magic = pHeader->magic;

      char* p_magicend = ( char* )p + size;
      auto magic_at_end = *( reinterpret_cast<size_t*>(p_magicend) );

      if( magic != magic_at_end ) {
         LOGT_A_ERROR( grepMarker + " buffer overflow at: " + string( info ) );
         exit( 0 );
      }

      auto key = reinterpret_cast<size_t>(pHeader);

      auto & check = alloccheckInstance();

      size_t lastalloccount = 0;
      {
         //nsl::tLock l(m);
         auto & allocList = check.getMutableAlloclist();
         auto it = allocList.find( key );
         lastalloccount = allocList.size();
         check.decr_alloccount();

         if( it != allocList.end() ) {
            allocList.erase( key );
         } else {
            LOGT_A_ERROR( grepMarker + " delete nicht in map gefunden: " + string( info ) );
            exit( 0 );
         }

         check.totalalloc_subtract( static_cast<int>( size ) );
      }

      auto infolog = grepMarker
                       + ", del, cnt: "
                       + to_str( check.alloccount() )
                       + ", left: "
                       + to_str( check.totalalloc() )
                       + ", info: '" + info + "'";
      LOGT_A_INFO( infolog );

      // final delete of allocated memory
      delete []( p_start );

      auto const& allocList2 = check.alloclist();

      if( check.alloccount() != allocList2.size() ) {
         int diff = static_cast<int>( check.alloccount() ) - static_cast<int>( lastalloccount );
         LOGT_A_INFO( grepMarker + " Error in 'delete': missingcount: " + to_str( diff ) );
      }

   }

   void* checked_alloc( size_t size, rlf_tlfm::t_lfm const& lfmcIn )  {
      return checked_alloc( int2type<use_alloc_check>(),  size, lfmcIn ) ;
   }
   void checked_delete( void* p )  {
      checked_delete( int2type<use_alloc_check>(),  p );
   }

   string stringify( size_t const& val ) {
      return boost::lexical_cast<string>( val );
   }

   string alloc_list_message() {
      return " end of program, number of not deleted pointers: " + stringify( alloc_list_size() ) ;
   }
   size_t alloc_list_size() {
      return alloccheck::alloccheckInstance().alloclist().size();
   }

   string alloclist() {
      auto const& allocList = alloccheck::alloccheckInstance().alloclist();

      string sum;
      if( allocList.size() > 0 ) {
         auto itstart = allocList.begin();
         auto itend = allocList.end();

         while( itstart != itend ) {
            pair<size_t, string> pa = *itstart;
            auto info = pa.second;
            if( sum.size() > 0 ){
               sum += ", " + info;
            }
            else{
               sum = info;
            }
            ++itstart;
         }
      }
      return sum;
   }


} // end of namespace alloccheck





//EOF
