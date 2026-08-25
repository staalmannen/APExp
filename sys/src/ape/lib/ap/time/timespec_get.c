/*
 * timespec_get -- C11 7.27.2.5.
 *
 * Sets ts to the current time in the time base named by base, and
 * returns base on success or zero on failure. TIME_UTC is the only
 * base the standard defines; an implementation may add others, and
 * this one does not.
 *
 * Note the return value is base, not 0, when it works -- the reverse of
 * the usual POSIX convention, and the reverse of clock_gettime, which
 * this is written over.
 */

#include <time.h>
#include <errno.h>

int
timespec_get(struct timespec *ts, int base)
{
	if(base != TIME_UTC){
		errno = EINVAL;
		return 0;
	}
	if(clock_gettime(CLOCK_REALTIME, ts) < 0)
		return 0;
	return base;
}
