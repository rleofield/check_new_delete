/* --------------------------------------------------------------------------
    Copyright 2012 by Richard Albrecht
    richard.albrecht@rleofield.de

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



#include "t_2D_string.h"


using namespace std;

using rlf_minit::float_xy;
using rlf_minit::double_xy;
using rlf_minit::uint32_xy;
using rlf_minit::int32_xy;

namespace rlf_hstring {

   std::string toString( uint32_xy p ) {
      return "(" + toString( p.x() ) + "," + toString( p.y() ) + ")";
   }
   std::string toString( double_xy const& p ) {
      int w = 6;
      int prec = 2;
      return "(" + toString( p.x(), w, prec ) + "," + toString( p.y(), w, prec ) + ")";
   }
   std::string toString( float_xy const& p ) {
      int w = 6;
      int prec = 2;
      return "(" + toString( p.x(), w, prec ) + "," + toString( p.y(), w, prec ) + ")";
   }



} // end ns rlf_hstring

//EOF
