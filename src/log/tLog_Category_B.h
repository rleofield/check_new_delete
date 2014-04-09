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


#ifndef TLOG_DEFINE_B_H
#define TLOG_DEFINE_B_H

#include "tLog.h"


// wird bei Auslieferung in 'tLog.h' eingestellt

#ifdef L_B_DEBUG
// bei Auslieferung auskommentiert
//#undef L_B_DEBUG
#endif

#ifndef L_B_DEBUG
// bei Auslieferung auskommentiert
//#define L_B_DEBUG
#endif


using namespace rlf_tlog;

// logline in Code

#ifdef L_B_DEBUG
#define LOGT_B_DEBUG(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_B, eLevel::LDEBUG, (exp) )))
#define LOGT_B_INFO(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_B, eLevel::INFO, (exp)  )))
#define LOGT_B_WARN(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_B, eLevel::WARN, (exp) )))
#define LOGT_B_ERROR(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_B, eLevel::LERROR, (exp)  )))
#define LOGT_B_FATAL(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_B, eLevel::FATAL, (exp) )))
#else
#define LOGT_B_DEBUG(exp)   {}
#define LOGT_B_INFO(exp)    {}
#define LOGT_B_WARN(exp)    {}
#define LOGT_B_ERROR(exp)   {}
#define LOGT_B_FATAL(exp)   {}
#endif


#endif  // TLOG_DEFINE_B_H

//EOF
