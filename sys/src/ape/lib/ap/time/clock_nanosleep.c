#include <time.h>
#include <errno.h>

int
clock_nanosleep(clockid_t clk, int flags, const struct timespec *req,
                struct timespec *rem)
{
	struct timespec rel, now;
	const struct timespec *p;

	switch(clk){
	case CLOCK_REALTIME:
	case CLOCK_MONOTONIC:
		break;
	default:
		return EINVAL;
	}

	if(flags & TIMER_ABSTIME){
		if(clock_gettime(clk, &now) < 0)
			return errno;
		rel.tv_sec  = req->tv_sec  - now.tv_sec;
		rel.tv_nsec = req->tv_nsec - now.tv_nsec;
		if(rel.tv_nsec < 0){
			rel.tv_sec--;
			rel.tv_nsec += 1000000000L;
		}
		if(rel.tv_sec < 0)
			return 0;
		p = &rel;
	} else {
		p = req;
	}

	if(nanosleep(p, rem) < 0)
		return errno;
	return 0;
}
