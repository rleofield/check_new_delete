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


#ifndef TLOG_IMPL_H
#define TLOG_IMPL_H

#include <vector>


#include "tLfmCL.h"
#include "tLogCategories.h"

const bool useLog = true;


template<bool v>
struct int2type {
   enum { value = v };
};

namespace rlf_tlog {

   class tLogImpl {
      bool write( tLfmCL const& w_ ) const ;
      std::string to_string( eLevel lev_ )const;
      std::string to_string( eCategory cat_ )const;
      static std::vector<tCat> _cats;
      static std::vector<tLev> _levs;
   public:
      tLogImpl():
         _file() {
      }

      // is mutable, to use logging in const environments
      mutable std::string  _file;

      void setLogLevel( eLevel level, eCategory cat )const;
      bool check( eCategory cat, eLevel levFunction )const;
      eLevel getLogLevel( eCategory cat )const;

      // sets the logfile, doesn't change loglevel
      bool setLogfile( std::string const& file )const;
      bool setLogfileWithDate( std::string const& file )const;

      // writes to logfile
      void log( int2type<false>, tLfmCL const& lfmcl ) const ;
      void log( int2type<true>, tLfmCL const& lfmcl ) const ;


      static eLevel findLevel( int level );
      static eCategory findCategory( int cat );


   };
}
#endif
//EOF

