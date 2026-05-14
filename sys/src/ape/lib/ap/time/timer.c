/*
 * POSIX interval timers for Plan9/APExp
 *
 * timer_create / timer_settime / timer_gettime / timer_delete / timer_getoverrun
 *
 * Plan9 has no kernel timer objects.  Each POSIX timer is backed by a
 * dedicated pthread that sleeps via pthread_cond_timedwait until the
 * deadline, fires the sigevent notification, then either reloads the
 * interval or disarms itself.
 *
 * Supported sigevent notification modes:
 *   SIGEV_NONE   — no notification (useful for timer_getoverrun callers)
 *   SIGEV_SIGNAL — kill(getpid(), sigev_signo), default SIGALRM
 *   SIGEV_THREAD — call sigev_notify_function(sigev_value) directly in
 *                  the worker thread (no separate thread per fire)
 *
 * timer_getoverrun always returns 0; overrun tracking requires kernel
 * support that Plan9 does not provide.
 */

#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

typedef struct _Timer _Timer;
struct _Timer {
	clockid_t       clkid;
	struct sigevent sevp;
	struct timespec deadline;  /* absolute expiry (valid when armed) */
	struct timespec interval;  /* reload period; zero means one-shot */
	int             armed;
	int             stop;
	int             overrun;
	pthread_t       tid;
	pthread_mutex_t lock;
	pthread_cond_t  cond;
};

static int
tsiszero(struct timespec ts)
{
	return ts.tv_sec == 0 && ts.tv_nsec == 0;
}

static struct timespec
tsadd(struct timespec a, struct timespec b)
{
	struct timespec r;
	r.tv_sec  = a.tv_sec  + b.tv_sec;
	r.tv_nsec = a.tv_nsec + b.tv_nsec;
	if(r.tv_nsec >= 1000000000L){
		r.tv_sec++;
		r.tv_nsec -= 1000000000L;
	}
	return r;
}

static void
fire(_Timer *t)
{
	switch(t->sevp.sigev_notify){
	case SIGEV_SIGNAL:
		kill(getpid(), t->sevp.sigev_signo);
		break;
	case SIGEV_THREAD:
		if(t->sevp.sigev_notify_function)
			t->sevp.sigev_notify_function(t->sevp.sigev_value);
		break;
	case SIGEV_NONE:
	default:
		break;
	}
}

static void *
timer_worker(void *arg)
{
	_Timer *t = (_Timer *)arg;
	int rc;

	pthread_mutex_lock(&t->lock);
	for(;;){
		/* wait until armed or told to stop */
		while(!t->armed && !t->stop)
			pthread_cond_wait(&t->cond, &t->lock);
		if(t->stop)
			break;

		rc = pthread_cond_timedwait(&t->cond, &t->lock, &t->deadline);

		if(t->stop)
			break;
		if(!t->armed)
			continue;  /* disarmed or re-armed while sleeping */

		if(rc == ETIMEDOUT){
			/* advance deadline before firing (interval timers) */
			if(!tsiszero(t->interval)){
				t->deadline = tsadd(t->deadline, t->interval);
				/* armed stays 1 */
			} else {
				t->armed = 0;
			}
			/* fire with lock released so the handler can call timer APIs */
			pthread_mutex_unlock(&t->lock);
			fire(t);
			pthread_mutex_lock(&t->lock);
		}
		/* spurious wakeup or re-arm: loop back to top */
	}
	pthread_mutex_unlock(&t->lock);
	return NULL;
}

int
timer_create(clockid_t clkid, struct sigevent *sevp, timer_t *timerid)
{
	_Timer *t;
	struct sigevent def;
	int rc;

	if(clkid != CLOCK_REALTIME && clkid != CLOCK_MONOTONIC){
		errno = EINVAL;
		return -1;
	}

	t = malloc(sizeof *t);
	if(t == NULL)
		return -1;

	if(sevp == NULL){
		def.sigev_notify = SIGEV_SIGNAL;
		def.sigev_signo  = SIGALRM;
		def.sigev_notify_function = NULL;
		def.sigev_notify_attributes = NULL;
		sevp = &def;
	}

	t->clkid            = clkid;
	t->sevp             = *sevp;
	t->armed            = 0;
	t->stop             = 0;
	t->overrun          = 0;
	t->deadline.tv_sec  = 0;
	t->deadline.tv_nsec = 0;
	t->interval.tv_sec  = 0;
	t->interval.tv_nsec = 0;
	pthread_mutex_init(&t->lock, NULL);
	pthread_cond_init(&t->cond, NULL);

	rc = pthread_create(&t->tid, NULL, timer_worker, t);
	if(rc != 0){
		pthread_mutex_destroy(&t->lock);
		pthread_cond_destroy(&t->cond);
		free(t);
		errno = rc;
		return -1;
	}

	*timerid = (timer_t)t;
	return 0;
}

int
timer_delete(timer_t timerid)
{
	_Timer *t = (_Timer *)timerid;

	pthread_mutex_lock(&t->lock);
	t->stop  = 1;
	t->armed = 0;
	pthread_cond_signal(&t->cond);
	pthread_mutex_unlock(&t->lock);

	pthread_join(t->tid, NULL);
	pthread_mutex_destroy(&t->lock);
	pthread_cond_destroy(&t->cond);
	free(t);
	return 0;
}

int
timer_settime(timer_t timerid, int flags, const struct itimerspec *value,
              struct itimerspec *ovalue)
{
	_Timer *t = (_Timer *)timerid;
	struct timespec now;

	if(value == NULL){
		errno = EINVAL;
		return -1;
	}

	if(ovalue != NULL)
		timer_gettime(timerid, ovalue);

	clock_gettime(t->clkid, &now);

	pthread_mutex_lock(&t->lock);
	t->interval = value->it_interval;

	if(tsiszero(value->it_value)){
		t->armed = 0;
	} else {
		if(flags & TIMER_ABSTIME)
			t->deadline = value->it_value;
		else
			t->deadline = tsadd(now, value->it_value);
		t->armed = 1;
		pthread_cond_signal(&t->cond);
	}
	pthread_mutex_unlock(&t->lock);
	return 0;
}

int
timer_gettime(timer_t timerid, struct itimerspec *value)
{
	_Timer *t = (_Timer *)timerid;
	struct timespec now;

	pthread_mutex_lock(&t->lock);
	value->it_interval = t->interval;

	if(!t->armed){
		value->it_value.tv_sec  = 0;
		value->it_value.tv_nsec = 0;
	} else {
		clock_gettime(t->clkid, &now);
		value->it_value.tv_sec  = t->deadline.tv_sec  - now.tv_sec;
		value->it_value.tv_nsec = t->deadline.tv_nsec - now.tv_nsec;
		if(value->it_value.tv_nsec < 0){
			value->it_value.tv_sec--;
			value->it_value.tv_nsec += 1000000000L;
		}
		if(value->it_value.tv_sec < 0){
			value->it_value.tv_sec  = 0;
			value->it_value.tv_nsec = 0;
		}
	}
	pthread_mutex_unlock(&t->lock);
	return 0;
}

int
timer_getoverrun(timer_t timerid)
{
	_Timer *t = (_Timer *)timerid;
	return t->overrun;
}
