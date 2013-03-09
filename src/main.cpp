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



#include <iostream>

#include "logger.h"
#include "impl.h"

using namespace std;

/*
logs each new and delete
reports wrong usages of new/delete
checks against bufferoverflows
use, if you have memory problems
uses magic numbers in allocated memory
works only for selfmade classes, not for POD (plain old data structure)

overload new/delete in a class
         static void* operator new( size_t size, logger::tLfm const& lfm );
         static void operator delete( void* );

overloaded new/delete call 'alloccheck::LocalAlloc( size,lfm )'
Example:
   void* tDemoClass2Checked::operator new( size_t size, logger::tLfm const& lfm ) {
      return alloccheck::LocalAlloc( size,lfm );
   }

examples are in
impl.h
impl.cpp


*/


int main() {

   string logfile = "alloc_check";
   alloccheck_log::logger().setLogfile( logfile );
   alloccheck_log::logger().Info( lfm_, " Start  " );

   try {
      // unchecked
      demo::tDemoClassNotChecked* a = demo::tDemoClassNotChecked::Create();

      // checked
      demo::tDemoClass1Checked* d = demo::tDemoClass1Checked::Create();
      demo::tDemoClass2Checked* c = demo::tDemoClass2Checked::Create();
      demo::tDemoClass3Checked* t = demo::tDemoClass3Checked::Create( "text" );
      delete c;
      // d and t are memory leaks


   } catch( demo::tException& ex ) {
      string msg = ex.what();
      alloccheck_log::logger().Info( lfm_, "tException: " + msg );
   } catch( std::exception& rt ) {
      alloccheck_log::logger().Info( lfm_, string( "Ex rt: " ) + rt.what() );
   }

   alloccheck::ShowAllocList();
   return 0;
}
