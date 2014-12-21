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




   // parameterobject for line, file, method
   class t_lfm {
      std::size_t _line;
      std::string _file;
      std::string _method;
   public:
      t_lfm(): _line( 0 ), _file( "" ), _method( "" ) {}

      t_lfm( size_t line_, std::string const& file_, std::string const& method_ )
         : _line( line_ ), _file( file_ ), _method( method_ ) {
      }
      size_t line()const {
         return _line;
      }
      std::string const& file()const {
         return _file;
      }

      std::string const& method()const {
         return _method;
      }
      operator std::string()const;

      ~t_lfm() {}
   };

   // use of parameterobject for line, file, method
   t_lfm tlog_lfm( uint32_t line_, std::string const& file_, std::string const& method_ );


}

#define tlfm_ rlf_tlfm::tlog_lfm( __LINE__,__FILE__,__FUNCTION__)


#endif
//EOF
