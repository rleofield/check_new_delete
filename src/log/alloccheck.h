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
   const bool use_alloc_check_log = true;


   // get the count of not deleted unchecked pointers, must be zero
   std::string alloc_list_message();
   size_t alloc_list_size();

   // gets a list of all undeleted checked pointers
   std::string allocliststring();



   // called by new(), logs linenumber, methodname, classname as magic info information in allocated memory
   void* checked_alloc( size_t size, rlf_tlfm::t_lfm const& lfmcIn );

   // calles by delete(void* p), checks, if logging info is present
   void checked_delete( void* p ) ;


} // end of ns alloccheck


#endif //

//EOF


