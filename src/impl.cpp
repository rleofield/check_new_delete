/* --------------------------------------------------------------------------
    Copyright 2012 by Richard Albrecht
    richard.albrecht@rleofield.de
    www.rleofield.de

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ------------------------------------------------------------------------------
*/

#include <vector>
#include <boost/lexical_cast.hpp>

#include <string>
#include <string.h>
#include <new>


#include "impl.h"

#include "tLog.h"

#include "tLog_Category_default.h"

using namespace rlf_tlog;
using std::string;
using rlf_tlog::eCategory;
using rlf_tlog::eLevel;


using std::pair;

namespace strings {

   std::string toString( int val ) {
      return boost::lexical_cast<string>( val );
   }

}


namespace demo {



   tDemoClassNotChecked* tDemoClassNotChecked::Create( const std::string& ) {
      return new tDemoClassNotChecked();
   }


   void* tDemoClass2Checked::operator new( size_t size, tLfm const& lfm ) {
      return alloccheck::LocalAlloc( size, lfm );
   }

   void tDemoClass2Checked::operator delete( void* p ) {
      alloccheck::LocalDelete( p );
   }
   tDemoClass2Checked* tDemoClass2Checked::Create( const std::string& ) {
      return new( lfm_ ) tDemoClass2Checked();
   }


   void* tDemoClass1Checked::operator new( size_t size, tLfm const& lfm ) {
      return alloccheck::LocalAlloc( size, lfm );
   }
   void tDemoClass1Checked::operator delete( void* p ) {
      alloccheck::LocalDelete( p );
   }
   tDemoClass1Checked* tDemoClass1Checked::Create( const std::string& ) {
      return new( lfm_ ) tDemoClass1Checked();
   }


   void* tDemoClass3Checked::operator new( size_t size, tLfm const& lfm ) {
      return alloccheck::LocalAlloc( size, lfm );
   }
   void tDemoClass3Checked::operator delete( void* p ) {
      alloccheck::LocalDelete( p );
   }
   tDemoClass3Checked* tDemoClass3Checked::Create( string const& txt ) {
      return new( lfm_ ) tDemoClass3Checked( txt );
   }


   tException::tException( string const& in )
      : _what( in )   {}


}


/**
     Überladung von new mit Markern:
     Jeder Aufruf von new/delete wird protokolliert.
     Im allozierten Speicher wird am bein Aufruf von new() eine Struktur eingefügt,
     die bei delete geprüft wird.
     Alle new/delete werden in einer STL-Map abglegt.
     Am Programmende wird die Map ausgegeben.
     Wenn es zu jedem new ein delete gibt, ist die Map am Programmende leer.
     */
namespace alloccheck {
   string clip_at_pos( string const& s, size_t pos ) {
      if( s.size() > 0 ) {
         size_t i = pos;

         if( i != string::npos ) {
            return s.substr( 0, i ) ;
         }
      }

      return s;
   }


   tAllocCheckControlMap& alloccheckInstance() {
      static tAllocCheckControlMap _alloccheckInstance;
      return  _alloccheckInstance;
   }

   const char pathSlash = '\\';

   string getFilennameFromPath( string const&  path_file ) {
      size_t i = path_file.rfind( pathSlash );

      if( i  != string::npos ) {
         return path_file.substr( i );
      }

      return path_file;
   }

   // Hilfsstruktur 'AllocHeader', um Informationen abzulegen, die im delete ausgewertet werden

   const size_t maxalloc = 32;      // Platz für Filename, Klassenname, Methodenname im Header'
   const size_t maxallocinfo = 128; // Platz ur die Loghging-Informatiom im Header'
   struct AllocHeader {             // Header, der jedem Speicherbereich vorangestellt wird
      size_t size;               // Grösse des allozierten Speichers
      size_t line;               // Zeiel, in der new() aufgerufen wurde
      size_t magic;              // magic number, am Ende des speichers, Test für Buffer Overflow
      char file[maxalloc];       // filename
      char info[maxallocinfo];   // logging Information
      char _class[maxalloc];     // Name der Klasse, für die new() aufgerufen wurde
      char function[maxalloc];   // Name der Function, in der new() aufgerufen wurde
   };


   // statischer Marker im Logfile,
   //   damit können mit grep die wichtigen Logzeilen gefiltert werden
   string grepMarker = "alloctest";

   //////////////////////////////////////////////////////////////////////////////////////
   // wird von new() aufgerufen, protokolliert Zeile, Name der Methode, Name der Klasse
   void* LocalAlloc( size_t size, tLfm const& lfm )  {

      // es wird Speicher mit new() angefordert, + sizeof(AllocHeader) + Platz für eine magic Number am Ende
      //char* p = ::new( nothrow ) char[sizeof( AllocHeader ) + size + sizeof( size_t )];
      char* p = ::new char[sizeof( AllocHeader ) + size + sizeof( size_t )];

      if( NULL == p ) {
         throw "allocation fails : no free memory";
      }

      char* p_start = p + sizeof( AllocHeader );
      char* p_magicend = p + sizeof( AllocHeader ) + size;

      size_t line = lfm.line();
      string file = lfm.file();
      string method = lfm.method();

      // strip path from file
      size_t i = file.rfind( pathSlash );

      if( i  != string::npos ) {
         file = file.substr( i );
      }

      file = getFilennameFromPath( file );

      // clip file, method and class names
      file = clip_at_pos( file, maxalloc - 1 );
      method = clip_at_pos( method, maxalloc - 1 );

      AllocHeader* pHeader = ( AllocHeader* )p;

      if( file.size() > maxalloc - 1 ) {
         file = file.substr( 0, maxalloc - 1 );
      }

      tAllocCheckControlMap& check = alloccheckInstance();

      // build info message for logging
      string info =   "size: " + strings::toString( static_cast<int>( size ) )
                      + ", total: " + strings::toString( check.totalalloc )
                      + ", file: " +  file
                      + ", method: " +  method
                      + ", line: " + strings::toString( static_cast<int>( line ) );

      if( info.length() > maxallocinfo - 1 ) {
         info = info.substr( 0, maxallocinfo - 1 );
      }

      pHeader->size = size;
      pHeader->line = line;
      pHeader->magic = rand();

      pHeader->file[0] = 0;
      pHeader->info[0] = 0;

      ::strncat( pHeader->file, file.c_str(), file.size() );
      ::strncat( pHeader->info, info.c_str(), info.size() );

      *( ( size_t* )p_magicend ) = pHeader->magic;


      size_t key = ( size_t )pHeader;
      {
         //  u.U. Sperre, wenn mehrere Threads vorhanden sind
         check.alloccount++;
         check.totalalloc += static_cast<int>( size );
         tAllocMap& allocList = check.getMutableAlloclist();
         allocIterator it = allocList.find( key );

         if( it != allocList.end() ) {
            string ll = grepMarker
                        + " key in der map vorhanden, fatal  "
                        + strings::toString( static_cast<int>( key ) )
                        + ", info: " + info + "'";
            LOGT_INFO( ll );
            exit( 0 );
         }

         allocList[key] = info;
      }
      string logLine = grepMarker + " Alloc count:  " + strings::toString( static_cast<int>( check.alloccount ) ) + ", info: " + info;
      LOGT_INFO( logLine );
      return ( void* )( p_start );
   }

   ////////////////////////////////////////////////////////////////////////////////////////////
   // wird von delete() aufgerufen
   void LocalDelete( void* p )  {

      //alloccheck_log::tLog const& logger_ = alloccheck_log::logger();
      // berechne den eigentlichen Beginn des allozierten Speichers
      char* p_start = ( ( char* )p - sizeof( AllocHeader ) );

      AllocHeader* pHeader = ( AllocHeader* )( p_start );
      // wenn eine Bufferoverflow auftrat, sind diese Stellen nicht mehr 0, d.h. hier auf 0 setzen
      pHeader->file[maxalloc - 1] = 0;
      pHeader->info[maxallocinfo - 1] = 0;
      pHeader->_class[maxalloc - 1] = 0;

      string file = pHeader->file;
      string info = pHeader->info;
      //size_t line = pHeader->line;
      size_t size = pHeader->size;
      size_t magic = pHeader->magic;

      char* p_magicend = ( char* )p + size;
      size_t magic_at_end = *( ( size_t* )p_magicend );

      if( magic != magic_at_end ) {
         LOGT_INFO( grepMarker + " buffer overflow at: " + string( info ) );
         exit( 0 );
      }

      size_t key = ( size_t )pHeader;

      tAllocCheckControlMap& check = alloccheckInstance();

      int lastalloccount = 0;
      {
         //nsl::tLock l(m);
         tAllocMap& allocList = check.getMutableAlloclist();
         allocIterator it = allocList.find( key );
         lastalloccount = static_cast<int>( allocList.size() );
         check.alloccount--;

         if( it != allocList.end() ) {
            allocList.erase( key );
         } else {
            LOGT_INFO( grepMarker + " Delete nicht in map gefunden: " + string( info ) );
            exit( 0 );
         }

         check.totalalloc -= static_cast<int>( size );
      }

      string infolog = grepMarker
                       + " Delete: count: "
                       + strings::toString( ( int )check.alloccount )
                       + ", mem left: "
                       + strings::toString( check.totalalloc )
                       + ", info: '" + info + "'";
      LOGT_INFO( infolog );

      // final delete of allocated memory
      delete []( p_start );

      tAllocMap const& allocList2 = check.getAlloclist();

      if( check.alloccount != static_cast<int>( allocList2.size() ) ) {
         int diff = check.alloccount - lastalloccount;
         LOGT_INFO( grepMarker + " Error in 'delete': missingcount: " + strings::toString( diff ) );
      }

      // ok

   }

   void ShowAllocList() {
      alloccheck::tAllocMap const& allocList = alloccheck::alloccheckInstance().getAlloclist();

      if( allocList.size() > 0 ) {
         LOGT_INFO( " not deleted pointers: " + strings::toString( static_cast<int>( allocList.size() ) ) );
         alloccheck::allocIterator itstart = allocList.begin();
         alloccheck::allocIterator itend = allocList.end();

         while( itstart != itend ) {
            pair<size_t, string> pa = *itstart;
            string info = pa.second;
            LOGT_INFO( info );
            ++itstart;
         }
      }

      LOGT_INFO( " end of program, number of not deleted pointers: " + strings::toString( static_cast<int>( allocList.size() ) ) );

   }


}




/////////////////////////////////////////////////////////////////////



// EOF
