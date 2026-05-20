#include "../include/lib.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include "sys9.h"
#include "dir.h"

#ifndef AT_FDCWD
#define AT_FDCWD (-100)
#endif

/*
 * applyts: store a POSIX timespec into a Plan9 Dir time field.
 *
 * Dir.atime/mtime are ulong (32-bit on 6c) because Plan9's 9P wire
 * protocol encodes timestamps as 32-bit unsigned integers.  This is
 * a kernel/protocol limitation: timestamps beyond 2038 will wrap
 * until Plan9's 9P is upgraded to 64-bit timestamps.  The (ulong) cast
 * is intentional and not a bug in userspace code.
 */
static void
applyts(ulong *field, const struct timespec *ts)
{
	if(ts->tv_nsec == UTIME_OMIT)
		return;   /* leave ~0UL sentinel from _nulldir — wstat won't touch it */
	if(ts->tv_nsec == UTIME_NOW)
		*field = (ulong)time(NULL);
	else
		*field = (ulong)ts->tv_sec;
}

int
futimens(int fd, const struct timespec times[2])
{
	Dir nd;
	time_t curt;

	_nulldir(&nd);
	if(times == NULL) {
		curt = time(NULL);
		nd.atime = (ulong)curt;
		nd.mtime = (ulong)curt;
	} else {
		applyts(&nd.atime, &times[0]);
		applyts(&nd.mtime, &times[1]);
	}
	if(_dirfwstat(fd, &nd) < 0) {
		_syserrno();
		return -1;
	}
	return 0;
}

int
utimensat(int dirfd, const char *path, const struct timespec times[2], int flags)
{
	Dir nd;
	time_t curt;
	(void)flags;

	if(dirfd != AT_FDCWD && (path == NULL || path[0] != '/')) {
		errno = ENOSYS;
		return -1;
	}

	_nulldir(&nd);
	if(times == NULL) {
		curt = time(NULL);
		nd.atime = (ulong)curt;
		nd.mtime = (ulong)curt;
	} else {
		applyts(&nd.atime, &times[0]);
		applyts(&nd.mtime, &times[1]);
	}
	if(_dirwstat(path, &nd) < 0) {
		_syserrno();
		return -1;
	}
	return 0;
}
