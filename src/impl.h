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


#ifndef ALLOCCHECK_H
#define ALLOCCHECK_H

#include "map"

#include "logger.h"

using namespace alloccheck_log;

namespace alloccheck {

   typedef std::map<size_t, std::string>::const_iterator allocIterator;

   typedef std::map<size_t, std::string> tAllocMap;

   class tAllocCheckControlMap {
      tAllocMap alloclist;

      // keine Kopien möglich
      tAllocCheckControlMap( tAllocCheckControlMap const& pos );
      void operator=( tAllocCheckControlMap const& pos );

   public:
      tAllocCheckControlMap(): alloclist(), alloccount( 0 ), totalalloc( 0 ) {}

      tAllocMap const& getAlloclist()const {
         return alloclist;
      }
      tAllocMap& getMutableAlloclist() {
         return alloclist;
      }
      size_t alloccount;
      int totalalloc;

   };
   tAllocCheckControlMap& alloccheckInstance();

   //////////////////////////////////////////////////////////////////////////////////////
   // wird von new() aufgerufen, protokolliert Zeile, Name der Methode, Name der Klasse
   void* LocalAlloc( size_t size, tLineFileMethod const& lfmcIn );

   ////////////////////////////////////////////////////////////////////////////////////////////
   // wird von delete(void* p) aufgerufen
   void LocalDelete( void* p ) ;

   void ShowAllocList();
}


namespace demo {

   class tException: public std::exception {
      std::string _what;
   public:
      tException( std::string const& in );
      const char* what() const throw() {
         return _what.c_str();
      }
      virtual ~tException() throw() {}
   };

   class tDemoClass3Checked  {
      static void* operator new( size_t size, tLfm const& lfm );
      static void operator delete( void* );
      tDemoClass3Checked( const std::string& txt ): v( txt )  {      }
   public:
      string v ;
      static tDemoClass3Checked* Create( const std::string& txt );
   };

   struct tDemoClass2Checked  {
      static void* operator new( size_t size, tLfm const& lfm );
      static void operator delete( void* );
      tDemoClass2Checked(): var1(), var2(), var3() {}
   public:
      std::string var1;
      std::string var2;
      std::string var3;
      static tDemoClass2Checked* Create();
   };

   class tDemoClass1Checked {
      static void* operator new( size_t, tLfm const& lfm );
      static void operator delete( void* );
      tDemoClass1Checked(): value()  {}
   public:
      string value;
      static tDemoClass1Checked* Create();
   };

   class tDemoClassNotChecked {
      tDemoClassNotChecked() : value()   { }
   public:
      std::string value;
      static tDemoClassNotChecked* Create();
   };

} // end of namespace

#endif

//EOF


