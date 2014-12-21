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


#ifndef imgrw_t_2D_xy_string_H
#define imgrw_t_2D_xy_string_H

#include <assert.h>
#include <string>
#include <float.h>
#include <vector>
#include <cmath>
#include <cstdint>



#include "t_2D_xy.h"
#include "stringhelper.h"


namespace rlf_hstring {

   std::string toString( rlf_minit::uint32_xy p );
   std::string toString( rlf_minit::double_xy const& p );
   std::string toString( rlf_minit::float_xy const& p );

}

#endif // imgrw_t_2D_xy_string_H
