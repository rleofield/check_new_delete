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

#ifndef ALLOCCHECK_LOG_H
#define ALLOCCHECK_LOG_H

#include <string>


namespace alloccheck_log {


   class tLineFileMethod  {
   public:
      tLineFileMethod( size_t l, std::string const& f, std::string const& m )
         :line( l ), file( f ), method( m )
      {}
      size_t line;
      std::string file;
      std::string method;
      ~tLineFileMethod() {}
   };

   class tLogInternal;

   class tLog {
      tLogInternal *intern;
   public:
      tLog();
      ~tLog();
      void Info(  tLineFileMethod const& lfm , const std::string& txt ) const ;
      enum tagLevel { CLOG_INFO  };
      void setLogfile( std::string const& file )const;
   private:
      // prevents copying of the instance
      tLog( tLog const& s );
      tLog & operator= ( tLog const &s );
   };
   typedef tLineFileMethod tLfm;

   // global singleton instance

   tLog const& logger();
   tLineFileMethod Lfm( size_t line_, std::string const& file_, std::string const& method_ = "" );
   inline void noFunc() {}

}

// short macro for __LINE__,__FILE__, __FUNCTION__
// used as parameter for log methods, gets info for logging

#define lfm_ alloccheck_log::Lfm(__LINE__,__FILE__,__FUNCTION__)




////////////
// locks

#include <mutex>
#include <pthread.h>

using namespace std;



class tMutexLock {
   pthread_mutex_t cs;
public:
   tMutexLock():cs() {
      pthread_mutex_init( &cs,NULL );
   }
   void lock() {
      pthread_mutex_lock( &cs );
   }
   void unlock() {
      pthread_mutex_unlock( &cs );
   }

   ~tMutexLock() {
      pthread_mutex_destroy( &cs );
   }
};

class tLock {
public:
   tLock( tMutexLock &pm ):mutexPtr( pm ) {
      mutexPtr.lock();
   }

   ~tLock() {
      mutexPtr.unlock();
   }


private:
   tMutexLock &mutexPtr;

};



#endif  // ALLOCCHECK_LOG_H

//EOF

