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


/*! \file tLfmCL.h
\brief parameterobject for line, file, method, category, loglevel

*/


#ifndef TLOG_TLFMCL_H
#define TLOG_TLFMCL_H

#include <cstdint>
#include <string>

#include "tLogEnum.h"


namespace rlf_tlog {
   using std::string;

   class tLfmCL {
      uint32_t _line;
      string _file;
      string _method;

      eCategory _cat;
      eLevel _level;
      std::string _txt;
   public:
      tLfmCL(): _line( 0 ), _file(), _method(), _cat( eCategory::_default ), _level( eLevel::NONE ), _txt() {}

      tLfmCL( uint32_t line_, std::string const& file_, std::string const& method_, eCategory cat, eLevel level_, std::string txt_ )
         : _line( line_ ), _file( file_ ), _method( method_ ) , _cat( cat ), _level( level_ ), _txt( txt_ ) {
      }
      size_t line()const {
         return _line;
      }
      std::string file()const {
         return _file;
      }

      std::string method()const {
         return _method;
      }
      eCategory category()const {
         return _cat;
      }
      void level( eLevel level_ ) {
         _level = level_;
      }
      eLevel level()const {
         return _level;
      }
      void txt( std::string s ) {
         _txt = s;
      }
      std::string txt()const {
         return _txt;
      }
      ~tLfmCL() {}
   };



   inline tLfmCL LfmCL( uint32_t line_, string const& file_, string const& method_, eCategory cat, eLevel lev, string txt_ ) {
      return tLfmCL( line_, file_, method_, cat, lev, txt_ );
   }

}



#endif
//EOF
