#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <sys/time.h>

#pragma lib "/$M/lib/ape/libap.a"

enum {
	RUSAGE_SELF = 0,
	RUSAGE_CHILDREN = -1
};

#define RUSAGE_SELF		RUSAGE_SELF
#define RUSAGE_CHILDREN		RUSAGE_CHILDREN
struct rusage {
	struct timeval ru_utime;	/* user time used */
	struct timeval ru_stime;	/* system time used */
	long	ru_maxrss;		/* max resident set size */
#define	ru_first	ru_ixrss
	long	ru_ixrss;		/* integral shared memory size */
	long	ru_idrss;		/* integral unshared data " */
	long	ru_isrss;		/* integral unshared stack " */
	long	ru_minflt;		/* page reclaims */
	long	ru_majflt;		/* page faults */
	long	ru_nswap;		/* swaps */
	long	ru_inblock;		/* block input operations */
	long	ru_oublock;		/* block output operations */
	long	ru_msgsnd;		/* messages sent */
	long	ru_msgrcv;		/* messages received */
	long	ru_nsignals;		/* signals received */
	long	ru_nvcsw;		/* voluntary context switches */
	long	ru_nivcsw;		/* involuntary " */
#define	ru_last		ru_nivcsw
};

/* resource limits */
typedef unsigned long long rlim_t;
#define RLIM_INFINITY	((rlim_t)-1)
#define RLIM_SAVED_MAX	RLIM_INFINITY
#define RLIM_SAVED_CUR	RLIM_INFINITY

struct rlimit {
	rlim_t	rlim_cur;	/* current (soft) limit */
	rlim_t	rlim_max;	/* maximum value for rlim_cur */
};

#define RLIMIT_CPU	0	/* max cpu time (seconds) */
#define RLIMIT_FSIZE	1	/* max file size */
#define RLIMIT_DATA	2	/* max data segment size */
#define RLIMIT_STACK	3	/* max stack size */
#define RLIMIT_CORE	4	/* max core file size */
#define RLIMIT_RSS	5	/* max resident set size */
#define RLIMIT_NPROC	6	/* max number of processes */
#define RLIMIT_NOFILE	7	/* max open file descriptors */
#define RLIMIT_MEMLOCK	8	/* max locked memory */
#define RLIMIT_AS	9	/* max address space */
#define RLIMIT_LOCKS	10	/* max file locks */
#define RLIMIT_SIGPENDING 11	/* max pending signals */
#define RLIMIT_MSGQUEUE	12	/* max POSIX msg queue bytes */
#define RLIMIT_NICE	13
#define RLIMIT_RTPRIO	14
#define RLIMIT_NLIMITS	15
#define RLIM_NLIMITS	RLIMIT_NLIMITS

#ifdef __cplusplus
extern "C" {
#endif

extern int getrusage(int, struct rusage *);
extern int getrlimit(int, struct rlimit *);
extern int setrlimit(int, const struct rlimit *);

#ifdef __cplusplus
}
#endif

#endif /* !__RESOURCE_H__ */
