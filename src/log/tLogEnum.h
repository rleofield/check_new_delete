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


#ifndef TLOG_ENUM_H
#define TLOG_ENUM_H


namespace rlf_tlog {

   enum class eLevel : int {
      // MS uses DEBUG and ERROR as Macros in MFC,
      // so we can't use this here
      // we use LDEBUG and LERROR
      LDEBUG = 1, INFO, WARN, LERROR,  FATAL, NONE
   };

   enum class eCategory : int {
      _default = 1,
      Cat_rimg,
      Cat_cout,
      Cat_A,
      Cat_B,
      Cat_C,
      Cat_D,
      Cat_Tiff,
      Cat_Alloc
   };



}


#endif
//EOF
