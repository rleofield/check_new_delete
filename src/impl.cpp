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

#include "alloccheck.h"

#include "impl.h"

#include "tLog.h"
#include "tLog_Category_default.h"

#include "win32.h"

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



   tNotChecked* tNotChecked::Create( const std::string& ) {
      return new tNotChecked();
   }


   void* tChecked2::operator new( size_t size, t_lfm const& lfm ) {
      return alloccheck::checked_alloc( size, lfm );
   }

   void tChecked2::operator delete( void* p ) {
      alloccheck::checked_delete( p );
   }
   tChecked2* tChecked2::Create( const std::string& ) {
      return new( tlfm_ ) tChecked2();
   }


   void* tChecked1::operator new( size_t size, t_lfm const& lfm ) {
      return alloccheck::checked_alloc( size, lfm );
   }
   void tChecked1::operator delete( void* p ) {
      alloccheck::checked_delete( p );
   }
   tChecked1* tChecked1::Create( const std::string& ) {
      return new( tlfm_ ) tChecked1();
   }


   void* tChecked3::operator new( size_t size, t_lfm const& lfm ) {
      return alloccheck::checked_alloc( size, lfm );
   }
   void tChecked3::operator delete( void* p ) {
      alloccheck::checked_delete( p );
   }
   tChecked3* tChecked3::Create( string const& txt ) {
      return new( tlfm_ ) tChecked3( txt );
   }


   tException::tException( string const& in )
      : _what( in )   {}


}



// EOF
