#ifndef __SYSTIME_H
#define __SYSTIME_H
#pragma lib "/$M/lib/ape/libap.a"

#ifndef __TIMEVAL__
#define __TIMEVAL__

struct timeval {
	long long	tv_sec;		/* seconds since epoch — 64-bit to survive 2038 */
	long		tv_usec;	/* microseconds [0, 999999] — 32-bit is fine */
};

struct itimerval {
	struct timeval it_interval;
	struct timeval it_value;
};

struct timezone {
	int	tz_minuteswest;
	int	tz_dsttime;
};

#endif /* __TIMEVAL__ */

#define ITIMER_REAL 0
#define ITIMER_VIRTUAL 1
#define ITIMER_PROF 3

extern int gettimeofday(struct timeval *, struct timezone *);
int getitimer(int, struct itimerval *);
int setitimer(int, const struct itimerval *, struct itimerval *);
int utimes(const char *, const struct timeval [2]);
int futimes(int, const struct timeval [2]);


#endif /* __SYSTIME_H */
