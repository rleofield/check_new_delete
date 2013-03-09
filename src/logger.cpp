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


#include <string.h>
#include <sstream>
#include <iomanip>

#include <iostream>
#include <fstream>


#include "logger.h"




using namespace std;

namespace alloccheck_log {

   const int MAX_PATH_LENGTH = 255; //PATH_MAX;



   namespace {

      // slash als string
      const std::string slash = "/";

      const size_t fieldLognumber = 5;
      const size_t fieldFilename = 20;


      // writes __LINE,__FILE__ to log stream
      void lfm_InfoToStream( std::ofstream& o, long line, const string&  cppfile, string const& method = "" ) {
         if( cppfile.length() == 0 ) return; // never happens, see __FILE__
         o << ' ';
         o << std::setfill( ' ' ) << std::left << std::setw( fieldFilename );
         size_t i = cppfile.rfind( slash );
         if (   i  != string::npos ) {
            o << cppfile.substr( i + 1 );
         } else {
            o << cppfile;
         }

         o << std::setfill( ' ' ) << std::setw( fieldLognumber ) << std::right  << line;
         o << ' ';
         if( method.size() > 0 ) {
            o << std::setfill( ' ' ) << std::left << std::setw( 40 );
            string m = method;
            if( m.size() > 40 ) {
               m  = m.substr( 0,40 );
            }
            o << m;
            o << ": ";
         }
      }

      void fill( std::ostream& o, size_t w, int val ) {
         char fill = '0';
         o << std::setfill( fill ) << std::setw( w )  << val;
      }


      // writes current time to log stream, no year
      void logTime( std::ofstream& o ) {
         time_t osBinaryTime;  // C run-time time (defined in <time.h>)
         time( &osBinaryTime ) ;  // Get the current time from the os
         struct tm *today = localtime( &osBinaryTime );

         fill( o, 2, today->tm_mon + 1 );
         o << ".";
         fill( o, 2, today->tm_mday );
         o <<  " ";
         fill( o, 2, today->tm_hour );
         o << ":";
         fill( o, 2, today->tm_min );
         o << ":";
         fill( o, 2, today->tm_sec );
         o << ":";
      }


      // internal writer to logfile
      bool write_( std::string const& logfile, tLfm const& lfm , string const& level, string const& txt )  {

         int line = lfm.line;
         std::string cppfile = lfm.file;
         std::string method =lfm.method;

         // open log file
         std::ofstream fp( logfile.c_str(), std::ios_base::app );
         if ( fp.bad() ) {
            string s;
            s  = "logfile: " + logfile + " not found." ;
            std::cout << s << std::endl;
            return false;
         }

         // set time at start in line
         logTime( fp );

         // level
         fp << " " << level  << " ";

         // append __LINE,__FILE__ __func__ to line
         lfm_InfoToStream( fp, line, cppfile, method );

         // write the log message an finish the line
         fp << " " << txt << std::endl;

         return true;
         // log file is implicitly closed by destructor if ofstream (RAII)
      }




   }

   bool write( string const& _file, string const& level, tLfm const& lfm, string const& txt )  {
      if ( _file.length() == 0 ) {
         return false;
      }
      return write_( _file, lfm, level, txt);
   }

   class tLogInternal {
   public:
      tLogInternal():_file(){}
      std::string  _file;
   };

   void tLog::setLogfile( string const& file )const {
      intern->_file = file + ".log";
   }

   tLog::tLog(): intern( new tLogInternal() ) {}

   tLog::~tLog() {
   }

   void tLog::Info( tLfm const& lfm , const std::string& txt ) const {
      write( intern->_file, "INFO", lfm, txt );
   }

   tLfm Lfm( size_t line_, std::string const& file_, std::string const& method_ ) {
      return tLfm( line_,file_,method_ );
   }


   // gets singleton instance
   tLog const& logger() {
      static tLog loggerInstance;
      return  loggerInstance;
   }

}







//EOF

