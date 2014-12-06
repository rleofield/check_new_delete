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

#include <boost/filesystem.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>


#include "stringhelper.h"
#include "tLog_Category_A.h"
#include "tLfm.h"

#include "alloccheck.h"
//

using rlf_tlfm::t_lfm;
using namespace std;


/**
     overload of new()/delete() with magic markers in memory

     each call of new/delete ist logged in a map
     in new() an info structure is written to allocated memory
     at delete() this structure ist checked and logged
     at end of program, the content of the map can be displayed,
     if all is ok, the map is empty
     */

namespace alloccheck {

   string stringify( size_t const& val ) {
      return boost::lexical_cast<string>( val );
   }
   string stringify( int64_t const& val ) {
      return boost::lexical_cast<string>( val );
   }

   template<bool v>
   struct int2type {
      enum { value = v };
   };


   string clip_at_pos( string const& s, size_t pos ) {
      return s.substr( 0, pos ) ;
   }



   class t_alloccheck {

      // secure singleton, don't allow a copy
      t_alloccheck( t_alloccheck const& pos );
      void operator=( t_alloccheck const& pos );

   public:
      t_alloccheck(): alloc_list(), total( 0 ), count( 0 ) {}


      string allocliststring() {
         struct get_second {
            string operator()( const std::map<void*, std::string>::value_type& value ) const {
               return value.second;
            }
         };
         vector<string> v;
         transform( alloc_list.begin(), alloc_list.end(), back_inserter( v ), get_second() );
         return rlf_hstring::merge( v, "\n" );
      }
      std::map<void*, std::string> alloc_list;
      int64_t total;
      size_t count;
      string scount()const{
         return stringify( count );
      }
      string stotal()const{
         return stringify( total );
      }
   };

   t_alloccheck& alloccheckInstance() {
      static t_alloccheck _alloccheckInstance;
      return  _alloccheckInstance;
   }

   const char pathSlash = '/';



   const size_t maxalloc     = 32; // max length of filename, methodname
   const size_t maxallocinfo = 128; // max length of logging info in 'AllocHeader'
   struct alloc_header {     // header, at start of allocated mem
      size_t size;           // size of allocaed memory
      size_t line;           // line where new() was called
      size_t magic;          // random magic number, added also at end of allocated memory, test buffer overflows
      size_t ptr;            // value of allocatedc pointer
      char info[maxallocinfo]; // short info msg
      alloc_header(): size( 0 ), line( 0 ), magic( 0 ), ptr(0) {
         memset( info, 0, maxallocinfo );
      }
   };


   static boost::mutex MUTEX;   // locking new/delete in concurrent threads


   // marker string in log,
   //   useful for searching with grep in logs
   string grepMarker = "shp";

   //////////////////////////////////////////////////////////////////////////////////////
   // called by new(), logs line, method name, class name
   // empty variant, used, if use_alloc_check == false;
   void* checked_alloc( int2type<false>, size_t size, rlf_tlfm::t_lfm const& )  {
      return ::new char[size];
   }


   // called by new(), logs line, method name, class name
   // implemented variant, used, if use_alloc_check == true;
   void* checked_alloc( int2type<true>, size_t size, rlf_tlfm::t_lfm const& lfm )  {

      // request raw memory, size += sizeof(AllocHeader) + magic number at begin and end of memory ( 2 x 32/64bit)
      // in meme: alloc_header, includes p .. allocated mem, used in program ... magic (is p)
      size_t s = sizeof( alloc_header ) + size + sizeof( size_t );
      char * const p __attribute__( ( aligned( __BIGGEST_ALIGNMENT__ ) ) )
            = ::new( nothrow ) char[ s ];


      if( nullptr == p ) {
         throw  bad_alloc();
      }

      char * const p_return = p + sizeof( alloc_header );
      size_t* p_magicend = reinterpret_cast<size_t*> (p_return + size);

      auto line = lfm.line();
      auto file = lfm.file();
      auto method = lfm.method();

      // strip path from file
      boost::filesystem::path path( file );
      file = boost::filesystem::path( file ).filename().string();

      // clip file, method names
      file = file.substr( 0, maxalloc - 1  );
      method = method.substr( 0, maxalloc - 1 );

      // placement new, object is created in place, no mem is allocated
      alloc_header* ptr_alloc_header =   new( p ) alloc_header;

      auto& check = alloccheckInstance();



      // build info message for logging
      string info = "cnt/alloc/sum: "
                  + check.scount() + "/" + stringify( size ) + "/" + stringify( check.total + size )
                  + ", fn: " +  file
                  + ", m: " +  method
                  + ", l: " + stringify( line );

      // clip info
      info = info.substr( 0, maxallocinfo - 1 );


      ptr_alloc_header->size = size;
      ptr_alloc_header->line = line;
      ptr_alloc_header->magic = rand();
      ptr_alloc_header->ptr = reinterpret_cast<size_t>(p);
      *p_magicend  = ptr_alloc_header->magic;

      ptr_alloc_header->info[0] = 0;

      // use low level string functions
      ::strncat( ptr_alloc_header->info, info.c_str(), info.size() );

      {

         // releases the lock at end of scope
         boost::lock_guard<boost::mutex> lock( MUTEX );

         check.count++;
         check.total += size;
         auto& allocList = check.alloc_list;
         auto it = allocList.find( ptr_alloc_header );

         if( it != allocList.end() ) {
            string ll = grepMarker + " 'alloc map has used key':  " + stringify( ( size_t )ptr_alloc_header ) + ", info: " + info + "'";
            LOGT_A_INFO( ll );
            exit( 0 );
         }

         allocList[p] = info;
      }
      auto logLine = grepMarker + ", alloc, cnt: " + check.scount() + ", info: " + info;
      LOGT_A_INFO( logLine );
      return p_return;

   }
   ////////////////////////////////////////////////////////////////////////////////////////////

   // wird von delete() aufgerufen
   // empty variant, used, if use_alloc_check == false;
   void checked_delete( int2type<false>, void* p )  {
      delete []( ( char* )p );
      return;
   }

   // wird von delete() aufgerufen
   // implemented variant, used, if use_alloc_check == true;
   void checked_delete( int2type<true>, void* p )  {

      auto p_start = ( reinterpret_cast<char*>( p ) - sizeof( alloc_header ) );

      auto* ptr_alloc_header = reinterpret_cast<alloc_header*>( p_start );
      ptr_alloc_header->info[maxallocinfo - 1] = 0;

      //auto file = pHeader->file;
      auto info = ptr_alloc_header->info;
      auto size = ptr_alloc_header->size;
      auto magic = ptr_alloc_header->magic;

      char* p_magicend = reinterpret_cast<char*>( p ) + size;
      size_t magic_at_end = *( reinterpret_cast<size_t*>( p_magicend ) );

      if( magic != magic_at_end ) {
         LOGT_A_ERROR( grepMarker + " buffer overflow at: " + string( info ) );
         exit( 0 );
      }

//      auto key = ptr_alloc_header;

      auto& check = alloccheckInstance();

      size_t lastalloccount = 0;
      {
         // releases the lock at end of scope
         boost::lock_guard<boost::mutex> lock( MUTEX );
         auto& allocList = check.alloc_list;
         auto it = allocList.find( ptr_alloc_header );
         lastalloccount = allocList.size();
         check.count--;

         if( it != allocList.end() ) {
            allocList.erase( ptr_alloc_header );
         } else {
            LOGT_A_ERROR( grepMarker + " delete nicht in map gefunden: " + string( info ) );
            exit( 0 );
         }

         check.total -= size;
      }

      auto infolog = grepMarker
                     + ", del, cnt: "
                     + check.scount()
                     + ", left: "
                     + check.stotal()
                     + ", info: '" + info + "'";
      LOGT_A_INFO( infolog );

      // final delete of allocated memory
      delete []( p_start );

      auto const& allocList2 = check.alloc_list;

      if( check.count != allocList2.size() ) {
         ptrdiff_t diff = static_cast<int>( check.count ) - static_cast<int>( lastalloccount );
         LOGT_A_INFO( grepMarker + " Error in 'delete': missingcount: " + stringify( diff ) );
      }

   }

   void* checked_alloc( size_t size, rlf_tlfm::t_lfm const& lfmcIn )  {
      return checked_alloc( int2type<use_alloc_check>(),  size, lfmcIn ) ;
   }
   void checked_delete( void* p )  {
      checked_delete( int2type<use_alloc_check>(),  p );
   }

   string alloc_list_message() {
      return " end of program, number of not deleted pointers: " + stringify( alloc_list_size() ) ;
   }
   size_t alloc_list_size() {
      return alloccheck::alloccheckInstance().alloc_list.size();
   }

   string allocliststring() {
      auto sum = alloccheck::alloccheckInstance().allocliststring();
      return sum;
   }


} // end of namespace alloccheck





//EOF
