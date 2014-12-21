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


#ifndef STRINGHELPER_H
#define STRINGHELPER_H


#include <string>
#include <sstream>
#include <iomanip>

#include <typeinfo>
#include <stdexcept>
#include <vector>
#include <assert.h>
#include <boost/tr1/regex.hpp>


namespace rlf_hstring {



   /*! BadConversion,

      Exception, wenn eine Konvertierung mit 'toString()' nicht erfolgreich war
      \param [in] msg  Fehlermeldung
      */
   class BadConversion : public std::runtime_error {
   public:
      BadConversion( const std::string& msg )
         : std::runtime_error( msg ) { }
   };



   /*! Konvertiert einen Wert in einen String.

        Das Template sollte nicht 'to_string' genannt werden, ergibt u.U. Konflikt mit Namespace 'std' und C++11


    Definition von to_string() in C++11 (aktueller GCC und VS2010)

   \li \c  std::string to_string( int value );
   \li \c   std::string to_string( long value );
   \li \c   std::string to_string( long long value );
   \li \c   std::string to_string( unsigned value );
   \li \c   std::string to_string( unsigned long value );
   \li \c   std::string to_string( unsigned long long value );
   \li \c   std::string to_string( float value );
   \li \c   std::string to_string( double value );
   \li \c   std::string to_string( long double value );



        \param val Wert, der konvertiert werden soll
      */
   template<class T >
   inline std::string toString( T val ) {
      std::ostringstream o;

      if( !( o << val ) ) {
         throw BadConversion( std::string( "toString(" ) + typeid( val ).name() + ")" );
      }

      return o.str();
   }

   std::string stringify( size_t const& val ) ;


   /*! Konvertiert einen Wert in einen String, Spezialisierung mit 'double'.

        \param val double Wert, der konvertiert werden soll
        \param w   Ausgabebreite, default = 6
        \param prec Gleitkommaformat, default: "%6.3lf"
      */
   inline std::string toString( double val, size_t w = 6, size_t prec = 3 ) {
      std::ostringstream o;
      o << std::setw( w ) << std::fixed << std::setprecision( prec ) << std::right << std::setfill( ' ' ) << val ;
      return  o.str();
   }
   inline std::string toString( double val, size_t w, size_t prec, char fill ) {
      std::ostringstream o;
      o << std::setw( w ) << std::fixed << std::setprecision( prec ) << std::right << std::setfill( fill ) << val ;
      return  o.str();
   }

   inline std::string toString( int val, size_t w = 3 ) {
      std::ostringstream o;
      o << std::setw( w ) << std::fixed << std::right << std::setfill( ' ' ) << val ;
      return  o.str();
   }


   void string_to_list( std::string const& s, std::list<std::string>& l, char trim_ch = ' ' ) ;
   void string_to_vector( std::string const& s, std::vector<std::string>& l, char trim_ch = ' ' ) ;


   namespace {
      const std::string s_true = "true";
      const std::string s_false = "false";
   }

   /*! Konvertiert einen Wert in einen String, Spezialisierung mit 'bool'.

        \param b bool Wert, der konvertiert werden soll
      */

   inline std::string toString( bool b ) {
      if( b ) {
         return s_true;
      }

      return s_false;
   }


   /*! Konvertiert einen String in einen Wert

     Der Template Parameter 'T' gibt den Typ, in den der String konvertiert werden soll, an.

        \param s String, der konvertiert werden soll
      */
   template<class T>
   inline T string2type( std::string const& s )  {
      T x;
      std::istringstream insx( s );

      //insx >> x;
      if( !( insx >> x ) ) {
         throw BadConversion( "couldn't convert '"  + s + "'" );
      }

      return x;
   }

   /*! Konvertierung eines Strings mit 'true' oder 'false' in einen boolschen Wert

        \param s String, der in ein 'bool' konvertiert werden soll
      */
   bool string2bool( std::string const& s );


   ////////
   // to bin, hex
   ////////

   size_t hex_to_size_t( std::string const& s )  ;

   /*! konvertiert einen Wert in einen Hex-String, mit '0x Prefix'

        \param val Wert, der in einen Hex-String konvertiert werden soll
        \param w Feldbreite, default = 8
   */
   std::string to_hex_0x( size_t val, size_t w = 8 ) ;

   /*! konvertiert einen Wert in einen Hex-String, ohne '0x' Prefix

        \param val Wert, der in einen Hex-String konvertiert werden soll
        \param w Feldbreite, default = 8
   */
   std::string to_hex( size_t val, size_t w = 8 ) ;

   /*! konvertiert einen Wert in einen Bin-String, ohne '0x' Prefix

        \param val Wert, der in einen Bin-String konvertiert werden soll
        \param w Feldbreite, default = 32
   */
   std::string to_bin( size_t val, size_t w = 32 );

   /*! \brief konvertiert einen String nach Kleinbuchstaben.
               String wird geändert, es wird keine Kopie intern erzeugt.

      \param   s String, der konvertiert werden soll
      \return  nichts
    */
   void to_lower_in_place( std::string& s );


   /*! \brief konvertiert einen String nach Kleinbuchstaben.
               String wird nicht geändert, es wird eine Kopie intern erzeugt.

      \param[in] s String, der konvertiert werden soll
      \return    konvertierter String
    */
   std::string to_lower( std::string const& s );


   /*! \brief konvertiert einen String nach Grossbuchstaben.
               String wird geändert, es wird keine Kopie intern erzeugt.

      \param   s String, der konvertiert werden soll
      \return  nichts
    */
   void to_upper_in_place( std::string& s );

   /*! \brief konvertiert einen String nach Grossbuchstaben.
               String wird nicht geändert, es wird eine Kopie intern erzeugt.

      \param   s String, der konvertiert werden soll
      \return  konvertierter String
    */
   std::string  to_upper( std::string const& s );


   ////////
   // string am Ende kappen
   ////////

   /// kappt einen string vor 'pattern'
   std::string clip( std::string const& s, std::string const& pattern );

   /// kappt einen string nach 'pattern'
   std::string clip_after( std::string const& in , std::string const& pattern ) ;

   /// kappt einen string vor Position 'pos', Position beginnt mit '0'
   std::string clip_at_pos( std::string const& s, size_t pos = 0 );

   /// kappt einen string nach Char 'ch'
   std::string clip_at_char( std::string const& s, char ch ) ;

   /// kappt einen string nach Position 'pos', siehe 'clip_at_pos'
   std::string truncate( std::string const& s, size_t pos );


   ////////
   // trim, rechts, links, beide Seiten, mit ' ' oder char
   ////////

   /// Leerzeichen entfernen, am Anfang und/oder am Ende, nicht in der Mitte
   std::string trim( std::string const& str, char char2remove = ' ' );
   std::string trim_right( std::string const& str, char char2remove = ' ' );
   std::string trim_left( std::string const& str, char char2remove = ' ' );


   ////////
   // index
   ////////


   /// Index eines Char/String in einem String
   /// wenn nicht gefunden, return npos;
   size_t index( std::string const& s, char ch, size_t pos = 0 ) ;
   size_t index_right( std::string const& s, char ch ) ;

   size_t index( std::string const& s, std::string const& pattern, size_t pos = 0 ) ;
   size_t index_right( std::string const& s, const std::string& pattern ) ;


   ////////
   // ersetzen, einmalig oder alle
   ////////


   // wie replace_first
   std::string replace( std::string const& in, std::string const& pattern, std::string const& replace );

   std::string replace_first( std::string const& in, std::string const& pattern, std::string const& replace ) ;
   std::string replace_all( std::string const& source, const std::string& pattern, const std::string& replace ) ;

   ////////
   // auffuellen rechts
   ////////

   std::string fillup( std::string const& in, char ch, size_t n ) ;

   char last_char( std::string const& s ) ;
   char first_char( std::string const& s ) ;


   ////////
   // loeschen, erase bzw. remove ist synonym
   ////////

   std::string erase( std::string const& in, size_t pos, size_t len ) ;
   void erase_in_place( std::string& s, size_t pos, size_t len ) ;

   std::string remove_first( std::string const& in ) ;
   std::string remove_first( std::string const& in, std::string const& pattern ) ;

   std::string remove_after( std::string const& in , std::string const& pattern ) ;
   std::string remove_last( std::string const& in );
   void remove_last_in_place( std::string& s );
   std::string remove_quotes( std::string const& in, char quote = '\"' );

   ////////
   // einfuegen
   ////////

   std::string insert_at( std::string const& in, char ch, size_t pos ) ;
   std::string insert_at( std::string const& str, const std::string& insert, size_t pos ) ;


   // merge with delimiter
   std::string merge( std::list<std::string>  const& v, std::string const& sep ) ;
   std::string merge( std::vector<std::string>  const& v, std::string const& sep ) ;




   ////////
   // zerlegen in Tokens
   ////////

   std::vector<std::string> tokenize( std::string const& str, const std::string& delimiters = " " );
   std::vector<std::string> split( std::string const& line,
                                   std::string const& delimiters = " ",
                                   char trim_ch = ' ' );
   std::vector<std::string> split( std::string const& l, char delim, char trim_ch = ' ' );


} // end ns



#endif // STRINGHELPER_H

//EOF
