#include <time.h>
#include "_npe.h"

int
gettimeofday(struct timeval *tp, struct timezone *tzp)
{
	long long t;

	USED(tzp);
	t = npe_nanosec();
	tp->tv_sec = t / Nsec;
	tp->tv_usec = (t / 1000ULL) % Nmsec;

	return 0;
}
