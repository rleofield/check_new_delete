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

//using std::string;

namespace rlf_tlog {

   /*! \class tLogLevel
   \brief parameterobject for LogLevel

   */

   class tLogLevel {
      eLevel _lev;
      std::string _name;
   public:
      tLogLevel(): _lev( eLevel::NONE ), _name() {}
      tLogLevel( eLevel a, std::string n ): _lev( a ), _name( n ) {}
      ~tLogLevel() {}
      operator eLevel()const {
         return _lev;
      }
      // for old code
      operator int()const {
         return static_cast<int>( _lev );
      }
      bool operator==( int val )const {
         if( val == static_cast<int>( _lev ) ) {
            return true;
         }

         return false;
      }
      std::string name()const {
         return _name;
      }
   };

   typedef  tLogLevel tLev;

   /*! \class tLogCategory
   \brief parameterobject for Category, uses tLev

   */
   class tLogCategory {
      eCategory _cat;
      std::string _name;
      tLev _cat_level;
   public:
      tLogCategory(): _cat( eCategory::_default ), _name(), _cat_level() {}
      tLogCategory( eCategory a, std::string n ): _cat( a ), _name( n ), _cat_level() {

      }
      ~tLogCategory() {}
      operator eCategory()const {
         return _cat;
      }
      // for old code
      operator int()const {
         return static_cast<int>( _cat );
      }
      bool operator==( int val )const {
         if( val == static_cast<int>( _cat ) ) {
            return true;
         }

         return false;
      }
      std::string name()const {
         return _name;
      }
      void cat_level( tLev  l ) {
         _cat_level = l;
      }
      tLev const& cat_level()const {
         return _cat_level;
      }
   };
   typedef  tLogCategory tCat;
}

#endif
//EOF
