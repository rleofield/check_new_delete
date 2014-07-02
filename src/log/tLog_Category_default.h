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


/*! \file tLog_Category_default.h
\brief macros for logging with line, file, method, eCategory::_default and  eLevel

*/


#ifndef TLOG_DEFINE_DEFAULT_H
#define TLOG_DEFINE_DEFAULT_H

#include <string>

#include "tLog.h"


// wird bei Auslieferung in 'tLog.h' eingestellt

#ifdef L_DEFAULT_DEBUG
// bei Auslieferung auskommentiert
//#undef L_DEFAULT_DEBUG
#endif

#ifndef L_DEFAULT_DEBUG
// bei Auslieferung auskommentiert
//#define L_DEFAULT_DEBUG
#endif

using namespace rlf_tlog;


// logline in Code
#ifdef L_DEFAULT_DEBUG
// enable default category
#define LOGT_DEBUG(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::LDEBUG, exp ) ) )
#define LOGT_INFO(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::INFO, (exp)  )))
#define LOGT_WARN(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::WARN, (exp) )))
#define LOGT_ERROR(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::LERROR, (exp)  )))
#define LOGT_FATAL(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::FATAL, (exp) )))

//#define LOGT_COUT_DEBUG(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::LDEBUG, exp ) ) , std::cout << (exp) << std::endl  )
//#define LOGT_COUT_INFO(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::INFO, (exp)  )) , std::cout << (exp) << std::endl )
//#define LOGT_COUT_WARN(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::WARN, (exp) )) , std::cout << (exp) << std::endl )
//#define LOGT_COUT_ERROR(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::LERROR, (exp)  )) , std::cout << (exp) << std::endl )
//#define LOGT_COUT_FATAL(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::_default, eLevel::FATAL, (exp) )) , std::cout << (exp) << std::endl )

#else
#define LOGT_DEBUG(exp)   (noLogFunc())
#define LOGT_INFO(exp)    (noLogFunc())
#define LOGT_WARN(exp)    (noLogFunc())
#define LOGT_ERROR(exp)   (noLogFunc())
#define LOGT_FATAL(exp)   (noLogFunc())
#endif



#endif  // TLOG_WITH_CATEGORY_H

//EOF

