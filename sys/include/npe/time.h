#ifndef _npe_time_h_
#define _npe_time_h_

#include <npe.h>

typedef long time_t;
typedef int clockid_t;

struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
	char *tm_zone;
};

struct timespec {
	time_t tv_sec;
	long tv_nsec;
};

enum {
	CLOCK_REALTIME,
	CLOCK_MONOTONIC,
};

#include <sys/time.h>

#define localtime npe_localtime
struct tm *npe_localtime(time_t *timep);
#define gmtime npe_gmtime
struct tm *npe_gmtime(time_t *timep);
size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);
time_t mktime(struct tm *tm);
int clock_gettime(clockid_t clockid, struct timespec *tp);

#endif
