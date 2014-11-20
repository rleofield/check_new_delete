
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

#include <iomanip>
#include <fstream>
#include <iostream>


#include "tLfm.h"

#include "tLog.h"
#include "tLogImpl.h"


namespace rlf_tlog {

   using std::string;
   using std::stringstream;

   bool tLog::setLogfile( string const& file )const {
      return pImpl->setLogfile( file );
   }
   bool tLog::setLogfileWithDate( string const& file )const {
      return pImpl->setLogfileWithDate( file );
   }
   tLog::tLog(): pImpl( new rlf_tlog::tLogImpl() ) {}
   tLog::~tLog() {
      delete pImpl;
   }

   eLevel tLog::setLogLevelDebug( eCategory cat )const {
      return setLogLevel( eLevel::LDEBUG, cat );
   }
   eLevel tLog::setLogLevelInfo( eCategory cat )const {
      return setLogLevel( eLevel::INFO, cat );
   }
   eLevel tLog::setLogLevelWarn( eCategory cat )const {
      return setLogLevel( eLevel::WARN, cat );
   }
   eLevel tLog::setLogLevelError( eCategory cat )const {
      return setLogLevel( eLevel::LERROR, cat );
   }
   eLevel tLog::setLogLevelFatal( eCategory cat )const {
      return setLogLevel( eLevel::FATAL, cat );
   }



   eLevel tLog::setLogLevel( eLevel level_, eCategory cat )const {
      eLevel tmp = pImpl->getLogLevel( cat );
      pImpl->setLogLevel( level_, cat );
      return tmp;
   }
   eLevel tLog::getLogLevel( eCategory cat )const {
      eLevel tmp = pImpl->getLogLevel( cat );
      return tmp;
   }
   eLevel tLog::findLevel( int level ) {
      return tLogImpl::findLevel( level );
   }
   eCategory tLog::findCategory( int cat ) {
      return tLogImpl::findCategory( cat );
   }



   void tLog::log( tLfmCL const& lfm ) const {
      //      std::cout << abc << std::endl;
      //      std::cout << abc_ << std::endl;
      pImpl->log( int2type<useLog>(), lfm );
   }


   // gets singleton instance
   tLog const& logger() {
      static tLog loggerInstance;
      return  loggerInstance;
   }

}

namespace rlf_tlfm {
   // implemented here, no other place found
   t_lfm tlog_lfm( uint32_t line_, std::string const& file_, std::string const& method_ ) {
      return t_lfm( line_, file_, method_ );
   }


   t_lfm::operator std::string()const {
      return "File: " + file() + ", Line: " + std::to_string( line() ) + ",Method: " + method();
   }

}









//EOF

