/* --------------------------------------------------------------------------
    Copyright 2012 by Richard Albrecht
    richard.albrecht@rleofield.de

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
#include <iostream>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <bitset>

#include "stringhelper.h"

#include <iomanip>
#include "gettokens.h"

using namespace std;

namespace rlf_hstring {


   namespace nsloc {

      const char* const de = "de_DE.utf8";
      const char* const ch = "de_CH.utf8";

   }
   string getDE() {
      return nsloc::de;
   }
   string getCH() {
      return nsloc::ch;
   }

   const char*  get_de() {
      return nsloc::de;
   }
   const char* get_ch() {
      return nsloc::ch;
   }





   string stringify( size_t const& val ) {
      return boost::lexical_cast<string>( val );
   }

//   void string_to_list( string const& s, list<string>& l, char sep_ch ) {
//      vector<string>  v = rlf_hstring::split( s, sep_ch );
//      l.assign( v.begin(), v.end() );
//   }
   list<string>  string_to_list( string const& s, char delim ) {
      string d( 1, delim );
      vector<string>  v = rlf_hstring::split( s, d );
      list<string> l( v.begin(), v.end() );
      return std::move(l);
   }

//   void string_to_vector( string const& s, vector<string>& v, char sep_ch ) {
//      vector<string> const& r = rlf_hstring::split( s, sep_ch );
//      v.insert( v.end(), r.begin(), r.end() );
//   }
    vector<string> string_to_vector( string const& s, char sep_ch ) {
      return std::move(rlf_hstring::split( s, sep_ch ));
   }

   // converts a hex string to size_t
   size_t hex_to_size_t( string const& s )  {
      size_t x;
      std::istringstream insx( s );
      insx >> std::hex;
      insx >> x;
      return x;
   }

   bool string2bool( string const& s )  {
      if( s == s_true ) {
         return true;
      }

      if( s == s_false ) {
         return false;
      }

      //string temp = to_upper( s );
      return false;
   }

   string to_hex_0x( size_t val, int w ) {
      string lower = to_hex( val, w );
      to_upper_in_place( lower );
      return "0x" + lower;
   }

   string to_hex( size_t val, int w ) {
      std::ostringstream o;
      o <<  std::setfill( '0' ) << std::setw( w ) << hex << val;
      return o.str();
   }

   string to_bin( size_t val, int w ) {
      static const size_t bits = 64;
      //int sv = sizeof(val) * 8;
      string result = std::bitset<bits>( val ).to_string();
      return result.substr( bits - w ); // string(str);
   }


   void to_lower_in_place( string& s ) {
      boost::algorithm::to_lower( s );
   }
   string to_lower( string const& s ) {
      return boost::algorithm::to_lower_copy( s );
   }
   void to_upper_in_place( string& s ) {
      boost::algorithm::to_upper( s );
   }

   string to_upper( string const& s ) {
      return boost::algorithm::to_upper_copy( s );
   }

   string clip( string const& in, string const& pattern ) {

      if( in.size() > 0 ) {
         size_t i = index( in, pattern );

         if( i != string::npos ) {
            return in.substr( 0, i ) ;
         }
      }

      return in;
   }

   string clip_after( string const& in , string const& pattern ) {
      size_t i = index( in, pattern );

      if( i != string::npos ) {
         return in.substr( 0, i + pattern.size() );
      }

      return in;
   }

   string clip_at_char( string const& s, char ch ) {
      if( s.size() > 0 ) {
         size_t i = index( s, ch );

         if( i != string::npos ) {
            return s.substr( 0, i ) ;
         }
      }

      return s;
   }
   string clip_at_pos( string const& s, size_t pos ) {
      if( s.size() > 0 ) {
         size_t i = pos;

         if( i != string::npos && i < s.size() ) {
            return s.substr( 0, i ) ;
         }
      }

      return s;
   }
   string truncate( string const& s, size_t pos ) {
      return clip_at_pos( s, pos );
   }


   string trim( string const& str, char ch ) {
      if( str.size() == 0 ) {
         return "";
      }

      if( ch == 0 ) {
         return str;
      }

      string::const_iterator begin = str.begin();

      while( begin < str.end() && *begin == ch ) {
         ++begin;
      }

      if( begin == str.end() ) {
         return "";
      }

      string::const_reverse_iterator last = str.rbegin();

      while( *last == ch ) {
         ++last;
      }

      size_t start = begin - str.begin();
      size_t n = last.base() - begin;
      string temp = str.substr( start, n );
      return move( temp );
   }

   string trim_right( string const& str, char ch ) {
      if( str.size() == 0 ) {
         return str;
      }

      string::const_reverse_iterator last = str.rbegin();

      while( last < str.rend() && *last == ch ) {
         ++last;
      }

      if( last == str.rend() ) {
         return "";
      }

      size_t n = str.rend() - last;
      return str.substr( 0, n );
   }

   string trim_left( string const& str, char ch ) {
      if( str.size() == 0 ) {
         return str;
      }

      string::const_iterator begin = str.begin();

      while( begin < str.end() && *begin == ch ) {
         ++begin;
      }

      if( begin == str.end() ) {
         return "";
      }

      if( begin == str.begin() ) {
         return str;
      }

      size_t start = begin - str.begin();
      return str.substr( start );
   }


   size_t index( string const& s, char ch, size_t pos ) {
      return s.find( ch, pos );
   }

   size_t index_right( string const& s, char ch ) {
      return s.rfind( ch );
   }

   size_t index( string const& s, string const& pattern, size_t pos ) {
      return s.find( pattern, pos );
   }



   size_t index_right( string const& s, const string& pattern ) {
      size_t p = s.rfind( pattern );
      //size_t sz = s.size();
      return p;
   }


   string replace_first( string const& in, string const& pattern, string const& replace ) {
      string s = in;
      size_t pos = index( s, pattern );

      if( pos != string::npos ) {
         s.erase( pos, pattern.size() );
         s.insert( pos, replace );
      }

      return s;
   }

   string replace( string const& ins, const string& pattern, const string& replace ) {
      return replace_first( ins, pattern, replace );
   }

   string replace_all( string const& ins, const string& pattern, const string& replace ) {
      string s = ins;
      size_t pos = index( s, pattern );
      size_t oldpos;

      while( pos != string::npos ) {
         s.erase( pos, pattern.size() );
         s.insert( pos, replace );
         oldpos = pos;
         pos = index( s, pattern, oldpos + replace.size() );
      }

      return s;
   }


   string fillup( string const& in, char ch, size_t n ) {
      string s = in;

      if( s.size() < n ) {
         s += string( n - s.size(), ch ) ;
      }

      return s;
   }
   string erase( string const& in, size_t pos, size_t len ) {
      string s = in;
      erase_in_place( s, pos, len );
      return s;
   }
   void erase_in_place( string& s, size_t pos, size_t len ) {
      s.erase( pos, len );
   }

   char last_char( string const& s ) {
      if( s.length() == 0 ) {
         return 0;
      }

      return *( s.end() - 1 );
   }
   char first_char( string const& s ) {
      if( s.length() == 0 ) {
         return 0;
      }

      return s[0];
   }



   string remove_first( string const& in ) {
      return erase( in, 0, 1 );
   }
   string remove_first( string const& in, char ch ) {
      size_t i = index( in, ch );

      if( i != string::npos ) {
         return erase( in, i, 1 );
      }

      return in;
   }

   string remove_first( string const& in, string const& pattern ) {
      size_t i = index( in, pattern );

      if( i != string::npos ) {
         return erase( in, i, pattern.length() );
      }

      return in;
   }


   string remove_last( string const& in ) {
      string s = in;
      remove_last_in_place( s );
      return s;
   }

   void remove_last_in_place( string& s, char ch ) {
      if( s.size() > 0 ) {
         size_t i = s.size() - 1;

         if( s[i] == ch ) {
            s.erase( i, 1 );
         }
      }
   }
   void remove_last_in_place( string& s ) {
      if( s.size() > 0 ) {
         size_t i = s.size() - 1;
         s.erase( i, 1 );
      }
   }

   string remove_quotes( string const& in, char quote ) {
      string temp = in;
      char ch = last_char( temp ) ;

      if( ch == quote ) {
         temp = remove_first( temp );
      }

      ch = last_char( temp ) ;

      if( ch == quote ) {
         temp = remove_last( temp );
      }

      return temp;
   }


   string insert_at( string const& in, char ch, size_t pos ) {
      string s = in;

      if( pos <= s.size() ) {
         s.insert( pos, 1, ch );
      }

      return s;
   }
   string insert_at( string const& str, const string& insert, size_t pos ) {
      string s = str;

      if( pos <= s.length() && insert.length() > 0 ) {
         s.insert( pos, insert );
      }

      return s;
   }

   namespace {
      struct add {
         string s;
         string const& sep;
         add( string const& sep_ ): s(), sep( sep_ ) {}
         void operator()( string const& str ) {
            if( s.empty() ) {
               s += str;
               return;
            }

            s += sep;
            s += str;
         }
      };
   }
   std::string merge( list<string>  const& v, string const& sep ) {
      if( v.empty() ) {
         return string();
      }

      if( v.size() == 1 ) {
         return  *v.begin();
      }

      return for_each( v.begin(), v.end(), add( sep ) ).s;
   }

   std::string merge( vector<string>  const& v, string const& sep ) {
      if( v.empty() ) {
         return string();
      }

      if( v.size() == 1 ) {
         return v[0];
      }

      return for_each( v.begin(), v.end(), add( sep ) ).s;
   }


   vector<string> split( string const& l, string const& delimiters, char trim_ch ) {
      return tTokens( l, delimiters, trim_ch )();
   }
   vector<string> split( string const& l, char delim, char trim_ch ) {
      string d( 1, delim );
      return split( l, d, trim_ch );
   }




} // end ns rlf_hstring

//EOF
