#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

/*
 * setitimer/getitimer emulation for APE.
 *
 * Plan 9 has no per-process virtual or profiling interval timers exposed
 * here, so ITIMER_VIRTUAL and ITIMER_PROF are approximated with wall-clock
 * timers that raise SIGVTALRM and SIGPROF respectively.
 */

typedef struct Itimer Itimer;
struct Itimer {
	timer_t timerid;
	int initialized;
	int signo;
};

static pthread_mutex_t itimerlock = PTHREAD_MUTEX_INITIALIZER;
static Itimer timers[3] = {
	{ 0, 0, SIGALRM },
	{ 0, 0, SIGVTALRM },
	{ 0, 0, SIGPROF },
};

static int
timerindex(int which)
{
	switch(which){
	case ITIMER_REAL:
		return 0;
	case ITIMER_VIRTUAL:
		return 1;
	case ITIMER_PROF:
		return 2;
	default:
		errno = EINVAL;
		return -1;
	}
}

static int
validtimeval(struct timeval tv)
{
	return tv.tv_sec >= 0 && tv.tv_usec >= 0 && tv.tv_usec < 1000000L;
}

static void
tv2ts(struct timeval tv, struct timespec *ts)
{
	ts->tv_sec = tv.tv_sec;
	ts->tv_nsec = tv.tv_usec * 1000L;
}

static void
ts2tv(struct timespec ts, struct timeval *tv)
{
	tv->tv_sec = ts.tv_sec;
	tv->tv_usec = ts.tv_nsec / 1000L;
}

static void
itv2its(const struct itimerval *itv, struct itimerspec *its)
{
	tv2ts(itv->it_value, &its->it_value);
	tv2ts(itv->it_interval, &its->it_interval);
}

static void
its2itv(const struct itimerspec *its, struct itimerval *itv)
{
	ts2tv(its->it_value, &itv->it_value);
	ts2tv(its->it_interval, &itv->it_interval);
}

static int
inititimer(Itimer *it)
{
	struct sigevent sev;
	int rc;

	if(it->initialized)
		return 0;

	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = it->signo;
	sev.sigev_notify_function = 0;
	sev.sigev_notify_attributes = 0;

	rc = timer_create(CLOCK_REALTIME, &sev, &it->timerid);
	if(rc == 0)
		it->initialized = 1;
	return rc;
}

int
getitimer(int which, struct itimerval *curr_value)
{
	struct itimerspec its;
	Itimer *it;
	int i, rc;

	if(curr_value == 0){
		errno = EINVAL;
		return -1;
	}

	i = timerindex(which);
	if(i < 0)
		return -1;

	it = &timers[i];

	pthread_mutex_lock(&itimerlock);
	if(!it->initialized){
		curr_value->it_value.tv_sec = 0;
		curr_value->it_value.tv_usec = 0;
		curr_value->it_interval.tv_sec = 0;
		curr_value->it_interval.tv_usec = 0;
		pthread_mutex_unlock(&itimerlock);
		return 0;
	}

	rc = timer_gettime(it->timerid, &its);
	if(rc == 0)
		its2itv(&its, curr_value);
	pthread_mutex_unlock(&itimerlock);
	return rc;
}

int
setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value)
{
	struct itimerspec its, oldits;
	Itimer *it;
	int i, rc;

	if(new_value == 0 ||
	   !validtimeval(new_value->it_value) ||
	   !validtimeval(new_value->it_interval)){
		errno = EINVAL;
		return -1;
	}

	i = timerindex(which);
	if(i < 0)
		return -1;

	itv2its(new_value, &its);
	it = &timers[i];

	pthread_mutex_lock(&itimerlock);
	rc = inititimer(it);
	if(rc == 0){
		rc = timer_settime(it->timerid, 0, &its, old_value ? &oldits : 0);
		if(rc == 0 && old_value)
			its2itv(&oldits, old_value);
	}
	pthread_mutex_unlock(&itimerlock);
	return rc;
}
