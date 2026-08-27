#ifndef __SYSTIME_H
#define __SYSTIME_H
#pragma lib "/$M/lib/ape/libap.a"

#ifndef __TIMEVAL__
#define __TIMEVAL__

/*
 * POSIX puts suseconds_t in <sys/types.h>, <sys/time.h> and
 * <sys/select.h>, and says tv_usec below has that type. It used to be
 * in <alltypes.h> alone -- which is not a header anyone includes by
 * name -- so portable code that spelled the type could not find it:
 *
 *   timediff.c:52 syntax error, last name: tv_usec
 *
 * from curl's "tv->tv_usec = (suseconds_t)tv_usec;", where an unknown
 * type name turns the cast into a syntax error.
 *
 * It is "long", not the "long long" alltypes.h had, because tv_usec is
 * long and POSIX requires the two to agree. The alltypes.h spelling was
 * musl's, where long is 64-bit; here it is 32, which is ample for
 * [0, 999999] and is what every caller taking &tv->tv_usec expects.
 */
#ifndef __suseconds_t_defined
#define __suseconds_t_defined
typedef long suseconds_t;
#endif

struct timeval {
	long long	tv_sec;		/* seconds since epoch — 64-bit to survive 2038 */
	suseconds_t	tv_usec;	/* microseconds [0, 999999] — 32-bit is fine */
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
