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


/*! \file tLogCategories.h
\brief parameterobjects for Category and  LogLevel

*/


#ifndef TLOG_CATEGORIES_H
#define TLOG_CATEGORIES_H

#include <string>

#include "tLogEnum.h"

using std::string;

namespace rlf_tlog {

   /*! \class tLev
   \brief parameterobject for LogLevel

   */

   class tLev {
      eLevel _lev;
      string _name;
   public:
      tLev(): _lev( eLevel::NONE ), _name() {}
      tLev( eLevel a, string n ): _lev( a ), _name( n ) {}
      ~tLev() {}
      operator eLevel()const {
         return _lev;
      }
      string name()const {
         return _name;
      }
   };

   /*! \class tCat
   \brief parameterobject for Category, uses tLev

   */
   class tCat {
      eCategory _cat;
      string _name;
      tLev _cat_level;
   public:
      tCat(): _cat( eCategory::_default ), _name(), _cat_level() {}
      tCat( eCategory a, string n ): _cat( a ), _name( n ), _cat_level() {

      }
      ~tCat() {}
      operator eCategory()const {
         return _cat;
      }
      string name()const {
         return _name;
      }
      void cat_level( tLev  l ) {
         _cat_level = l;
      }
      tLev const& cat_level()const {
         return _cat_level;
      }
   };

}

#endif
//EOF
