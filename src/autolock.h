/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Randy Rizun <rrizun@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef S3FS_AUTOLOCK_H_
#define S3FS_AUTOLOCK_H_

#include <pthread.h>

//-------------------------------------------------------------------
// AutoLock Class
//-------------------------------------------------------------------
class AutoLock
{
    public:
      enum Type {
          NO_WAIT        = 1,
          ALREADY_LOCKED = 2,
          NONE           = 0
      };

    private:
        pthread_mutex_t* const auto_mutex;
        bool is_lock_acquired;

    private:
        AutoLock(const AutoLock&) = delete;
        AutoLock& operator=(const AutoLock&) = delete;

    public:
        explicit AutoLock(pthread_mutex_t* pmutex, Type type = NONE);
        ~AutoLock();
        bool isLockAcquired() const;
};

#endif // S3FS_AUTOLOCK_H_

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
