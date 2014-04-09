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

// boost
#include <boost/filesystem.hpp>
#include <boost/assign/list_of.hpp> // for 'list_of()'
#include <boost/thread/mutex.hpp>
#include <boost/thread.hpp>


#include "tLogImpl.h"


using std::stringstream;
using std::string;


namespace rlf_tlog {
   using namespace boost::assign;

   boost::mutex MUTEX;

   namespace fs {

      // slash als string
      const string slash = "/";
      const string dbl_slash = "//";

      // slash als char
      const char char_slash = '/';


      bool file_exists( boost::filesystem::path const& p ) {
         if( !boost::filesystem::is_regular_file( p ) ) {
            return false;
         }

         boost::filesystem::file_status s = status( p );

         if( boost::filesystem::exists( s ) ) {
            return true;
         }

         return false;
      }


      bool file_exists( std::string const& fn ) {
         boost::filesystem::path p( fn );
         return file_exists( p );
      }

      bool path_exists( boost::filesystem::path const& p ) {
         boost::filesystem::file_status s = status( p );

         if( boost::filesystem::is_directory( s ) ) {
            return true;
         }

         return false;
      }

      bool path_exists( string const& path ) {
         boost::filesystem::path p( path );
         return path_exists( p );
      }
      char last_char( string const& s ) {
         if( s.length() == 0 ) {
            return 0;
         }

         return *( s.end() - 1 );
      }

      string working_directory() {
         boost::filesystem::path pwd = boost::filesystem::current_path();
         string pp = pwd.string();

         if( pp.size() > 0 ) {
            if( last_char( pp ) != char_slash ) {
               pp += char_slash;
            }
         }

         string s = pp;
         return s;
      }


      // entferne den Filenamen aus dem Pfad
      string extractPath( string const&  file ) {
         string pathSlash = slash;
         size_t i = file.rfind( pathSlash );

         if( i  != string::npos ) {
            return file.substr( 0, i + 1 );
         }

         string temp = working_directory();
         return temp;
      }
      // entferne den Filenamen aus dem Pfad
      string extractFile( string const&  file ) {
         size_t i = file.rfind( slash );

         if( i  != string::npos ) {
            return file.substr( i + 1 );
         }

         return file;
      }
      bool checkPath( string const& f ) {
         string path = extractPath( f );

         if( path == f ) {
            return true;   // f has no path
         }

         bool b = fs::path_exists( path );
         return b;
      }

   }



   namespace {

      const size_t fieldLognumber = 5;
      const size_t fieldFilename = 20;

      // writes __LINE,__FILE__ to log stream
      void lfm_InfoToStream( std::ofstream& o, size_t line, const string&  cppfile, string const& method = "" ) {
         if( cppfile.length() == 0 ) {
            return;   // never happens, see __FILE__
         }

         o << ' ';
         o << std::setfill( ' ' ) << std::left << std::setw( fieldFilename );
         size_t i = cppfile.rfind( fs::slash );

         if( i  != string::npos ) {
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
               m  = m.substr( 0, 40 );
            }

            o << m;
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
         struct tm* today = localtime( &osBinaryTime );

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

      string dateLogfile( ) {

         time_t osBinaryTime;  // C run-time time (defined in <time.h>)
         time( &osBinaryTime ) ;  // Get the current time from the os
         struct tm* today = localtime( &osBinaryTime );
         stringstream o;
         fill( o, 4, today->tm_year + 1900 );
         fill( o, 2, today->tm_mon + 1 );
         fill( o, 2, today->tm_mday );
         return o.str();
      }
   }



   namespace {
      tCat def = tCat( eCategory::_default, "" );
      tCat rimg = tCat( eCategory::Cat_rimg, "" );
      tCat A = tCat( eCategory::Cat_A, "a" );
      tCat B = tCat( eCategory::Cat_B, "b" );
      tCat C = tCat( eCategory::Cat_C, "c" );
      tCat D = tCat( eCategory::Cat_D, "d" );

      tLev DEBUG = tLev( eLevel::LDEBUG, "DEBUG" );
      tLev INFO  = tLev( eLevel::INFO, "INFO " );
      tLev WARN  = tLev( eLevel::WARN, "WARN " );
      tLev ERROR_ = tLev( eLevel::LERROR, "ERROR" );
      tLev FATAL = tLev( eLevel::FATAL, "FATAL" );
      tLev NONE = tLev( eLevel::NONE, "" );
   }

   std::vector<tCat> tLogImpl::_cats = list_of( def )( rimg )( A )( B )( C )( D );
   std::vector<tLev> tLogImpl::_levs = list_of( DEBUG )( INFO )( WARN )( ERROR_ )( FATAL )( NONE );

   std::string tLogImpl::to_string( eLevel lev_ )const {
      std::vector<tLev>::const_iterator f = find( _levs.begin(), _levs.end(), lev_ );

      if( f != _levs.end() ) {
         return f->name();
      }

      return string();
   }

   std::string tLogImpl::to_string( eCategory cat_ )const {
      std::vector<tCat>::const_iterator f = find( _cats.begin(), _cats.end(), cat_ );

      if( f != _cats.end() ) {
         return f->name();
      }

      return string();
   }


   // internal writer to logfile
   bool tLogImpl::write( tLfmCL const& lfmcl ) const  {

      // releases the lock at end of scope
      boost::lock_guard<boost::mutex> lock( MUTEX );

      std::ofstream fp( _file.c_str(), std::ios_base::app );

      if( fp.bad() ) {
         string s = "logfile: " + _file + " not found." ;
         std::cout << s << std::endl;
         return false;
      }

      // set time at start if line
      logTime( fp );

      // level
      string ls = to_string( lfmcl.level() );
      fp << " " << ls  << " ";

      size_t line = lfmcl.line();
      std::string cppfile = lfmcl.file();
      std::string method = lfmcl.method();

      // append __LINE,__FILE__,__FUCTION__ to line
      lfm_InfoToStream( fp, line, cppfile, method );
      fp << ":";

      // write category, if not default
      string cs = to_string( lfmcl.category() );

      if( cs.size() > 0 ) {
         fp << cs << ":" ;
      }

      // write the log message and finish the line
      fp << " " << lfmcl.txt() << std::endl;
      return true;
      // log file is implicitly closed by destructor from ofstream (RAII)
   }







   bool tLogImpl::setLogfile( string const& file )const {
      bool b = fs::checkPath( file );

      if( !b ) {
         return false;
      }

      _file = file + ".log";
      return true;
   }

   bool tLogImpl::setLogfileWithDate( string const& file )const {
      bool b = fs::checkPath( file );

      if( !b ) {
         return false;
      }

      _file = file + "_" + dateLogfile() + ".log";
      return true;
   }



   void tLogImpl::setLogLevel( eLevel level_, eCategory cat_ )const {
      std::vector<tCat>::iterator category = find( _cats.begin(), _cats.end(), cat_ );

      if( category == _cats.end() ) {
         return;
      }

      std::vector<tLev>::const_iterator level = find( _levs.begin(), _levs.end(), level_ );

      if( level == _levs.end() ) {
         return;
      }

      category->cat_level( *level );
   }

   eLevel tLogImpl::getLogLevel( eCategory cat )const {
      std::vector<tCat>::const_iterator category = find( _cats.begin(), _cats.end(), cat );

      if( category == _cats.end() ) {
         return eLevel::NONE;
      }

      return category->cat_level();
   }

   eLevel tLogImpl::findLevel( int level_ ) {
      std::vector<tLev>::const_iterator level = find( _levs.begin(), _levs.end(), level_ );

      if( level == _levs.end() ) {
         return eLevel::NONE;
      }

      return *level;
   }
   eCategory tLogImpl::findCategory( int cat_ ) {

      std::vector<tCat>::iterator category = find( _cats.begin(), _cats.end(), cat_ );

      if( category == _cats.end() ) {
         return eCategory::_default;
      }

      return *category;
   }


   bool tLogImpl::check( eCategory cat, eLevel levFunction ) const {
      eLevel level_category = getLogLevel( cat );

      if( level_category > levFunction ) {
         return true;
      }

      return false;
   }

   void tLogImpl::log( int2type<false>, tLfmCL const& ) const {
      return;
   }

   void tLogImpl::log( int2type<true>, tLfmCL const& lfmcl ) const {
      if( _file.length() == 0 ) {
         return;
      }

      if( check( lfmcl.category(), lfmcl.level() ) ) {
         return;
      }

      write( lfmcl );
   }






}







//EOF


