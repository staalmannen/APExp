#include "lib.h"
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include "sys9.h"
#include "dir.h"

int
futimes(int fd, const struct timeval times[2])
{
	int n;
	Dir nd;
	time_t curt;

	_nulldir(&nd);
	if(times == 0) {
		curt = time(0);
		nd.atime = curt;
		nd.mtime = curt;
	} else {
		nd.atime = (time_t)times[0].tv_sec;
		nd.mtime = (time_t)times[1].tv_sec;
	}
	n = _dirfwstat(fd, &nd);
	if(n < 0)
		_syserrno();
	return n;
}
