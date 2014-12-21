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


#include <string>

#include <istream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>


#include "gettokens.h"
#include "stringhelper.h"

using namespace std;

namespace rlf_hstring {

   tTokens::tTokens( const string& s, string const& delims, char trim_ch ): _buffer() {
      string temp = s;
      size_t pos = temp.find_first_of( delims );

      while( pos != string::npos ) {
         string t = trim( temp.substr( 0, pos ), trim_ch );

         if( t.length() > 0 ) {
            _buffer.push_back( t );
         }

         temp = trim( temp.substr( pos + 1 ), trim_ch );
         pos = temp.find_first_of( delims );
      }

      _buffer.push_back( trim( temp, trim_ch ) );
   }

} // end ns rlf_hstring


// EOF
