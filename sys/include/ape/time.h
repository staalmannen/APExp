#ifndef __TIME_H
#define __TIME_H
#pragma lib "/$M/lib/ape/libap.a"

#include <stddef.h>

#define CLOCKS_PER_SEC 1000

/* obsolsecent, but required */
#define CLK_TCK CLOCKS_PER_SEC

#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1
#ifndef CLOCK_PROCESS_CPUTIME_ID
#define CLOCK_PROCESS_CPUTIME_ID 2
#endif
#ifndef CLOCK_THREAD_CPUTIME_ID
#define CLOCK_THREAD_CPUTIME_ID  3
#endif

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long clock_t;
#endif
#ifndef _TIME_T
#define _TIME_T
typedef long time_t;
#endif
#ifndef _CLOCKID_T
#define _CLOCKID_T
typedef int clockid_t;
#endif

/* musl */
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
	long tm_gmtoff;
	const char *tm_zone;
};

#ifdef __cplusplus
extern "C" {
#endif

extern clock_t clock(void);
extern double difftime(time_t, time_t);
extern time_t mktime(struct tm *);
extern time_t time(time_t *);
extern char *asctime(const struct tm *);
extern char *ctime(const time_t *);
extern struct tm *gmtime(const time_t *);
extern struct tm *localtime(const time_t *);
extern size_t strftime(char *, size_t, const char *, const struct tm *);
extern int clock_gettime(clockid_t, struct timespec *);
extern int clock_settime(clockid_t, struct timespec *);

extern struct tm *gmtime_r(const time_t *, struct tm *);
extern struct tm *localtime_r(const time_t *, struct tm *);
extern char *ctime_r(const time_t *, char *);

extern char *strptime(const char *, const char *, struct tm *);
extern time_t timegm(struct tm *);

extern void tzset(void);

struct timespec {
	time_t tv_sec;
	long tv_nsec;
};
extern int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

extern char *tzname[2];
extern long timezone;
extern long altzone;
extern int daylight;

#endif /* __TIME_H */
