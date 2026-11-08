#include <errno.h>
#include <time.h>
#include "_npe.h"

int
clock_gettime(clockid_t clockid, struct timespec *tp)
{
	uvlong t;

	if(clockid == CLOCK_REALTIME)
		t = nsec();
	else if(clockid == CLOCK_MONOTONIC)
		t = npe_nanosec();
	else{
		errno = EINVAL;
		return -1;
	}

	tp->tv_nsec = t % 1000000000;
	tp->tv_sec = t / 1000000000;

	return 0;
}
