#define _GNU_SOURCE
#include <unistd.h>
#include <sys/time.h>

unsigned ualarm(unsigned value, unsigned interval)
{
	struct itimerval it, it_old;
	it.it_interval.tv_usec = interval;
	it.it_value.tv_usec = value;
	setitimer(ITIMER_REAL, &it, &it_old);
	return it_old.it_value.tv_sec*1000000 + it_old.it_value.tv_usec;
}
