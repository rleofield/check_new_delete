/* --------------------------------------------------------------------------
    Copyright 2013 by Richard Albrecht
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


#ifndef RLF_ALLOC_CHECK_H
#define RLF_ALLOC_CHECK_H

#include <stdlib.h>
#include <map>

#include "tLfm.h"
using rlf_tlfm::t_lfm;


namespace alloccheck {

   // set to false, to switch off all checked new/delete
   const bool use_alloc_check = true;


   class t_alloccheck {
      std::map<size_t, std::string> _alloc_list;

      // secure singleton, don't allow a copy
      t_alloccheck( t_alloccheck const& pos );
      void operator=( t_alloccheck const& pos );

      size_t _alloccount;
      int _totalalloc;

   public:
      t_alloccheck(): _alloc_list(), _alloccount( 0 ), _totalalloc( 0 ) {}

      std::map<size_t, std::string>  const& alloclist()const {
         return _alloc_list;
      }
      std::map<size_t, std::string> & getMutableAlloclist() {
         return _alloc_list;
      }
      int totalalloc()const{ return _totalalloc; }
      void totalalloc_add( int i ){ _totalalloc += i; }
      void totalalloc_subtract( int i ){ _totalalloc -= i; }

      size_t alloccount()const{ return _alloccount; }
      void incr_alloccount(){ _alloccount++; }
      void decr_alloccount(){ _alloccount--; }

   };

   // get the count of not deleted unchecked pointers, must be zero
   std::string alloc_list_message() ;
   size_t alloc_list_size();

   // gets a list of all undeleted checked pointers
   std::string alloclist();



   // called by new(), logs linenumber, methodname, classname as magic info information in allocated memory
   void* checked_alloc( size_t size, rlf_tlfm::t_lfm const& lfmcIn );

   // calles by delete(void* p), checks, if logging info is present
   void checked_delete( void* p ) ;


} // end of ns alloccheck


#endif //

//EOF


