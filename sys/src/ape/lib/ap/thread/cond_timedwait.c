#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

/*
 * pthread_cond_timedwait for Plan9/APExp
 *
 * Plan9's rsleep() has no timeout: it uses rendezvous() which is an
 * unconditional rendezvous with no kernel timer support.
 *
 * Implementation strategy: "timer thread"
 *
 *   1. Allocate a small state struct shared between this thread and
 *      a short-lived timer thread.
 *   2. The timer thread sleeps nanosleep(remaining) then calls
 *      pthread_cond_signal() on the cond to break rsleep().
 *   3. The waiter wakes (either from real signal or timer), rechecks
 *      the current time, and returns ETIMEDOUT if the deadline passed.
 *
 * Correctness notes:
 *   - The timer thread may fire after a real signal has already woken
 *     the waiter.  pthread_cond_signal() on a Rendez with no waiters
 *     is a no-op (rwakeup returns 0), so this is harmless.  The next
 *     legitimate waiter on this cond will NOT be spuriously woken
 *     because rwakeup moves the first sleeper to the QLock queue —
 *     if nobody is sleeping, nothing is moved.
 *   - POSIX allows spurious wakeups; callers must recheck their
 *     predicate.  The timer thread adds one possible spurious wakeup
 *     per timedwait call, which is within spec.
 *   - ts is an *absolute* time (CLOCK_REALTIME), matching POSIX.
 *   - If the deadline is already in the past, we return ETIMEDOUT
 *     immediately without sleeping.
 */

typedef struct {
	pthread_cond_t  *cond;
	pthread_mutex_t *mutex;
	struct timespec  deadline;
	int              fired;    /* 1 = timer fired first */
	pthread_mutex_t  lock;
} timedwait_state;

static void *
timer_thread(void *arg)
{
	timedwait_state *s = (timedwait_state *)arg;
	struct timespec now, rem;
	long ns;

	/* compute remaining time */
	clock_gettime(CLOCK_REALTIME, &now);
	ns = (s->deadline.tv_sec  - now.tv_sec)  * 1000000000L
	   + (s->deadline.tv_nsec - now.tv_nsec);

	if(ns > 0) {
		rem.tv_sec  = ns / 1000000000L;
		rem.tv_nsec = ns % 1000000000L;
		nanosleep(&rem, NULL);
	}

	/*
	 * Signal the cond to break the waiter out of rsleep().
	 * We must hold the mutex across cond_signal to match the
	 * protocol used by cond_signal/cond_broadcast (they hold
	 * cond->r.l which is the cond's internal QLock).
	 *
	 * We do NOT hold the user mutex here — that is held by the
	 * waiter inside rsleep().  pthread_cond_signal only needs
	 * the cond's own QLock which cond_signal acquires internally.
	 */
	pthread_mutex_lock(&s->lock);
	s->fired = 1;
	pthread_mutex_unlock(&s->lock);

	pthread_cond_signal(s->cond);
	return NULL;
}

int
pthread_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex,
                       const struct timespec *abstime)
{
	timedwait_state s;
	pthread_t tid;
	pthread_attr_t attr;
	struct timespec now;
	int ret = 0;

	if(!abstime) return EINVAL;

	/* check if deadline already passed */
	clock_gettime(CLOCK_REALTIME, &now);
	if(abstime->tv_sec < now.tv_sec ||
	   (abstime->tv_sec == now.tv_sec &&
	    abstime->tv_nsec <= now.tv_nsec))
		return ETIMEDOUT;

	/* initialise shared state */
	s.cond     = cond;
	s.mutex    = mutex;
	s.deadline = *abstime;
	s.fired    = 0;
	pthread_mutex_init(&s.lock, NULL);

	/* spawn detached timer thread */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(pthread_create(&tid, &attr, timer_thread, &s) != 0) {
		pthread_attr_destroy(&attr);
		pthread_mutex_destroy(&s.lock);
		return EAGAIN;
	}
	pthread_attr_destroy(&attr);

	/* wait — rsleep() releases mutex internally */
	pthread_cond_wait(cond, mutex);

	/* check whether the timer fired (vs legitimate signal) */
	pthread_mutex_lock(&s.lock);
	if(s.fired) {
		/* verify deadline actually passed (guard against spurious) */
		clock_gettime(CLOCK_REALTIME, &now);
		if(now.tv_sec > abstime->tv_sec ||
		   (now.tv_sec == abstime->tv_sec &&
		    now.tv_nsec >= abstime->tv_nsec))
			ret = ETIMEDOUT;
	}
	pthread_mutex_unlock(&s.lock);
	pthread_mutex_destroy(&s.lock);

	return ret;
}
