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
#include <random>

#include <cstdint>


#include "stringhelper.h"
#include "tLog.h"

#include "alloccheck.h"

using rlf_tlfm::t_lfm;
using std::string;
using std::vector;
using std::map;

using std::uintptr_t;


/**
     overload of new()/delete() with magic markers in memory

     each call of new/delete ist logged in a map
     in new() an info structure is written to allocated memory
     at delete() this structure ist checked and logged
     at end of program, the content of the map can be displayed,
     if all is ok, the map is empty
     */


// logline in Code
using namespace rlf_tlog;

namespace alloccheck {


   void log( string const& s ) {
      if( !use_alloc_check_log ) {
         return;
      }

      tLfmCL l( __LINE__, __FILE__, __FUNCTION__, eCategory::Cat_Alloc, eLevel::INFO, s );
      logger().log( s );

   }
   void err( string const& s ) {
      if( !use_alloc_check_log ) {
         return;
      }

      tLfmCL l( __LINE__, __FILE__, __FUNCTION__, eCategory::Cat_Alloc, eLevel::LERROR, s );
      logger().log( s );
   }

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

   namespace {

      class t_alloccheck {

         // singleton, don't allow a copy
         t_alloccheck( t_alloccheck const& pos );
         void operator=( t_alloccheck const& pos );

         // bookeeping of allocated pointers
         std::map<uintptr_t, std::string> _alloc_list;

         size_t _total;
         size_t _count;
         std::random_device rd;
         std::uniform_int_distribution<size_t> dist; // size_t is guaranteed to be 32/64 bits, dependend from CPU


      public:

         t_alloccheck(): _alloc_list(), _total( 0 ), _count( 0 ), rd(), dist() {}
         std::map<size_t, std::string> const& alloc_list() const {
            return _alloc_list;
         }
         std::map<uintptr_t, std::string>& alloc_list() {
            return _alloc_list;
         }


         string allocliststring() {
            struct get_second {
               string operator()( const std::map<uintptr_t, std::string>::value_type& value ) const {
                  return "memoryleak, allocated at: " + value.second;
               }
            };
            vector<string> v;
            transform( _alloc_list.begin(), _alloc_list.end(), back_inserter( v ), get_second() );
            return rlf_hstring::merge( v, "\n" );
         }
         size_t count()const {
            return _count;
         }
         void count_add( size_t v ) {
            _count += v;
         }
         void count_subtract( size_t v ) {
            _count -= v;
         }

         size_t total()const {
            return _total;
         }
         void total_add( size_t v ) {
            _total += v;
         }
         void total_subtract( size_t v ) {
            _total -= v;
         }

         string scount()const {
            return stringify( _count );
         }
         string stotal()const {
            return stringify( _total );
         }

         size_t alloc_list_size()const {
            return _alloc_list.size();
         }
         void add( size_t k, string const& s ) {
            _alloc_list[k] = s;
         }

         size_t getrand() {
            return dist( rd );
         }

      };



      t_alloccheck& alloccheckInstance() {
         static t_alloccheck _alloccheckInstance;
         return  _alloccheckInstance;
      }

      const char pathSlash = '/';



      const size_t maxname  = 32; // max length of filename, methodname
      const size_t maxallocinfo = 128; // max length of logging info in 'AllocHeader'
      struct alloc_header {     // header, at start of allocated mem
         char info[maxallocinfo]; // short info msg
         size_t size;           // size of allocaed memory
         size_t line;           // line where new() was called
         size_t ptr;            // value of allocatedc pointer
         size_t magic;          // random magic number, added also at end of allocated memory, test buffer overflows
         alloc_header(): size( 0 ), line( 0 ), ptr( 0 ), magic( 0 ) {
            memset( info, 0, maxallocinfo );
         }
      };


      static boost::mutex MUTEX;   // locking new/delete in concurrent threads


      // marker string in log,
      //   useful for searching with grep in logs
      string grepMarker = "alloc";

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
         char* const p __attribute__( ( aligned( __BIGGEST_ALIGNMENT__ ) ) )
            = ::new( std::nothrow ) char[ s ];


         if( nullptr == p ) {
            throw  std::bad_alloc();
         }

         char* const p_return = p + sizeof( alloc_header );
         size_t* p_magicend = reinterpret_cast<size_t*>( p_return + size );

         auto line = lfm.line();
         auto file = lfm.file();
         auto method = lfm.method();

         // strip path from file
         boost::filesystem::path path( file );
         file = boost::filesystem::path( file ).filename().string();


         // placement new, object is created in place, no mem is allocated
         alloc_header* ptr_alloc_header =   new( p ) alloc_header;

         auto& check = alloccheckInstance();



         // build info message for logging
         string sum = "cnt/alloc/sum: "
                      + check.scount() + "/" + stringify( size ) + "/" + stringify( check.total() + size );
         sum = rlf_hstring::fillup( sum, ' ', 25 );

         // clip file, method names
         file = file.substr( 0, maxname - 1 );
         method = method.substr( 0, maxname - 1 );

         // fil, method , line info
         string fn =   ": fn: " +  file
                       + ", m: " +  method
                       + ", l: " + stringify( line );

         // info line, copied to allocated RAM
         string info = sum + fn;

         // clip info line
         info = info.substr( 0, maxallocinfo - 1 );

         // copy to RAM
         ptr_alloc_header->size = size;
         ptr_alloc_header->line = line;
         ptr_alloc_header->magic = check.getrand(); // rand();
         ptr_alloc_header->ptr = reinterpret_cast<size_t>( p );
         *p_magicend  = ptr_alloc_header->magic;

         //         ptr_alloc_header->info[0] = 0;

         // use low level string functions
         ::strncat( ptr_alloc_header->info, info.c_str(), info.size() );

         {

            // releases the lock at end of scope
            boost::lock_guard<boost::mutex> lock( MUTEX );

            check.count_add( 1 );
            check.total_add( size );
            auto& allocList = check.alloc_list();
            auto it = allocList.find( reinterpret_cast<size_t>( ptr_alloc_header ) );

            if( it != allocList.end() ) {
               string ll = grepMarker + " 'alloc map has used key':  " + stringify( reinterpret_cast<size_t>( ptr_alloc_header ) ) + ", info: " + info + "'";
               err( ll );
               exit( 0 );
            }

            check.add( reinterpret_cast<size_t>( p ), info );
         }
         auto logLine = grepMarker + ", new, cnt: " + check.scount() + ", info: " + info;
         log( logLine );
         return p_return;

      }
      ////////////////////////////////////////////////////////////////////////////////////////////

      // wird von delete() aufgerufen
      // empty variant, used, if use_alloc_check == false;
      void checked_delete( int2type<false>, void* p )  {
         delete []( static_cast<char*>( p ) );
         return;
      }

      // wird von delete() aufgerufen
      // implemented variant, used, if use_alloc_check == true;
      void checked_delete( int2type<true>, void* p )  {

         char* p_to_delete = reinterpret_cast<char*>( p );
         auto p_allocated = ( reinterpret_cast<char*>( p ) - sizeof( alloc_header ) );

         alloc_header* header = reinterpret_cast<alloc_header*>( p_allocated );
         // protect aginst buffer overflow, if end of str in changed
         header->info[maxallocinfo - 1] = 0;

         //auto file = pHeader->file;
         auto info = header->info;
         size_t size = header->size;
         size_t magic = header->magic;

         char* p_magicend = p_to_delete + size;

         size_t magic_at_end = *( reinterpret_cast<size_t*>( p_magicend ) );

         if( magic != magic_at_end ) {
            err( grepMarker + ", buffer underflow/overflow at: " + string( info ) );
            exit( 0 );
         }


         auto& check = alloccheckInstance();

         size_t lastalloccount = 0;
         {
            // releases the lock at end of scope
            boost::lock_guard<boost::mutex> lock( MUTEX );
            auto& allocList = check.alloc_list();
            auto it = allocList.find( reinterpret_cast<uintptr_t>( header ) );
            lastalloccount = check.alloc_list_size();

            if( it != allocList.end() ) {
               allocList.erase( reinterpret_cast<uintptr_t>( header ) );
            } else {
               err( grepMarker + ", delete nicht in map gefunden: " + string( info ) );
               exit( 0 );
            }

            check.count_subtract( 1 );
            check.total_subtract( size );
         }

         auto infolog = grepMarker
                        + ", del, cnt: "
                        + check.scount()
                        + ", left: "
                        + check.stotal()
                        + ", stored info: '" + info + "'";
         log( infolog );

         // final delete of allocated memory
         delete []( p_allocated );


         if( check.count() != check.alloc_list_size() ) {
            ptrdiff_t diff = static_cast<ptrdiff_t>( check.count() ) - static_cast<ptrdiff_t>( lastalloccount );
            log( grepMarker + ", Error in 'delete': missingcount: " + stringify( diff ) );
         }

      }
   } // end of anon ns


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
      return alloccheck::alloccheckInstance().alloc_list_size();
   }

   string allocliststring() {
      auto sum = "\n" + alloccheck::alloccheckInstance().allocliststring();
      return sum;
   }


} // end of namespace alloccheck





//EOF
