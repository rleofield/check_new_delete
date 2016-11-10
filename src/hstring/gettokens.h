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


#ifndef GETTOKENS_H
#define GETTOKENS_H

#include <string>
#include <vector>


namespace rlf_hstring {

   class tTokens {
      std::vector<std::string> _buffer;
      tTokens( tTokens const& );
      void operator=( tTokens const& );
   public:
      tTokens( const std::string& str, std::string const& delims = " ", char trim_ch = ' ' );
      ~tTokens() {}
      std::vector<std::string> operator()()const {
         return std::move(_buffer);
      }

   };

} // end ns rlf_hstring




#endif // GETTOKENS_H

