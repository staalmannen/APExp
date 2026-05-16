#define _GNU_SOURCE
#include <unistd.h>
#include <sys/time.h>

unsigned ualarm(unsigned value, unsigned interval)
{
	struct itimerval it, it_old;

	it.it_interval.tv_sec = interval/1000000;
	it.it_interval.tv_usec = interval%1000000;
	it.it_value.tv_sec = value/1000000;
	it.it_value.tv_usec = value%1000000;
	setitimer(ITIMER_REAL, &it, &it_old);
	return it_old.it_value.tv_sec*1000000 + it_old.it_value.tv_usec;
}
