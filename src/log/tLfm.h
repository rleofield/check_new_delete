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


/*! \file tLfm.h
\brief parameterobject for line, file, method

*/



#ifndef TLFM_H
#define TLFM_H

#include <cstdint>
#include <string>



namespace rlf_tlfm {
   using std::string;

   class tLfm {
      uint32_t _line;
      string _file;
      string _method;

   public:
      tLfm(): _line( 0 ), _file(), _method() {}

      tLfm( uint32_t line_, std::string const& file_, std::string const& method_ )
         : _line( line_ ), _file( file_ ), _method( method_ )
      {}
      size_t line()const {
         return _line;
      }
      std::string file()const {
         return _file;
      }

      std::string method()const {
         return _method;
      }
      ~tLfm() {}
   };

   // use of parameterobject for line, file, method
   inline tLfm Lfm( uint32_t line_, string const& file_, string const& method_ ) {
      return tLfm( line_, file_, method_ );
   }


}

#define lfm_ Lfm( __LINE__,__FILE__,__FUNCTION__)

#endif
//EOF
