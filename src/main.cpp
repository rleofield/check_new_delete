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
#include <boost/lexical_cast.hpp>


#include "tLog.h"
#include "tLog_Category_default.h"
#include "tLog_Category_A.h"
#include "tLfm.h"
#include "alloccheck.h"

using rlf_tlfm::t_lfm;

#include "impl.h"

using namespace std;
using namespace rlf_tlog;

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



using demo::tNotChecked;
using demo::tChecked1;
using demo::tChecked2;
using demo::tChecked3;


int main() {

   string logfile = "alloc_check";


   bool b2 = logger().setLogfile( logfile );

   if( b2 == false ) {
      cout << "setLogfile: " << logfile << " path for logging dosn't exist: '" << logfile <<  "'" << endl;
   }

   logger().log_level( eLevel::LDEBUG, eCategory::_default );
   logger().log_level( eLevel::LDEBUG, eCategory::Cat_Alloc );

   LOGT_INFO( " Start  " );

   try {
      // unchecked
      tNotChecked* a = tNotChecked::Create( "DemoClassNotChecked" );

      // checked
      tChecked1* d = tChecked1::Create( "tDemoClass1Checked" );
      tChecked2* p_c = tChecked2::Create( "tDemoClass2Checked" );
      tChecked3* t = tChecked3::Create( "tDemoClass3Checked" );



      //         *((char*)p_c-1) = 1;
      //         *((char*)p_c-2) = 1;
      //         *((char*)p_c-3) = 1;
      //         *((char*)p_c-4) = 1;
      //         *((char*)p_c-5) = 1;
      //         *((char*)p_c-6) = 1;
      //         *((char*)p_c-7) = 1;

      delete p_c;
      // d and t are memory leaks


   } catch( demo::tException& ex ) {
      string msg = ex.what();
      LOGT_INFO( "tException: " + msg );
   } catch( std::exception& rt ) {
      LOGT_INFO( string( "Ex rt: " ) + rt.what() );
   }

   LOGT_INFO( alloccheck::alloc_list_message() );
   LOGT_INFO( alloccheck::allocliststring() );
   return 0;
}
