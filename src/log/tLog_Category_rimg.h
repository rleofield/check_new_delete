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


#ifndef TLOG_DEFINE_RIMG_H
#define TLOG_DEFINE_RIMG_H


#include "tLog.h"
#include "tLogCategories.h"

// wird bei Auslieferung in 'tLog.h' eingestellt

#ifdef L_RIMG_DEBUG
// bei Auslieferung auskommentiert
//#undef L_A_DEBUG
#endif

#ifndef L_RIMG_DEBUG
// bei Auslieferung auskommentiert
//#define L_A_DEBUG
#endif


using namespace rlf_tlog;

// logline in Code

#ifdef L_RIMG_DEBUG
#define LOGT_RIMG_DEBUG(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_rimg, eLevel::LDEBUG, (exp) )))
#define LOGT_RIMG_INFO(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_rimg, eLevel::INFO, (exp)  )))
#define LOGT_RIMG_WARN(exp)   (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_rimg, eLevel::WARN, (exp) )))
#define LOGT_RIMG_ERROR(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_rimg, eLevel::LERROR, (exp)  )))
#define LOGT_RIMG_FATAL(exp)  (logger().log( LfmCL(__LINE__,__FILE__,__FUNCTION__, eCategory::Cat_rimg, eLevel::FATAL, (exp) )))
#else
#define LOGT_RIMG_DEBUG(exp)   {}
#define LOGT_RIMG_INFO(exp)    {}
#define LOGT_RIMG_WARN(exp)    {}
#define LOGT_RIMG_ERROR(exp)   {}
#define LOGT_RIMG_FATAL(exp)   {}
#endif


#endif  // TLOG_DEFINE_RIMG_H

//EOF
