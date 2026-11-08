#ifndef _npe_sys_time_h_
#define _npe_sys_time_h_

#include <npe.h>
#include <time.h>

struct timeval {
	time_t tv_sec;
	ulong tv_usec;
};

int gettimeofday(struct timeval *tv, struct timezone *tz);

#endif
