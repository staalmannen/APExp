#include "lib.h"
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "sys9.h"

/*
 * POSIX semaphore implementation for APExp / Plan9 9front
 *
 * sem_t contains:
 *   QLock lock   - mutual exclusion around count
 *   Rendez rendez - condition wait for count > 0
 *   int count    - current semaphore value
 *   int valid    - initialisation check
 *
 * The Rendez must be bound to the QLock at init time.
 * Plan9 convention: rendez.l = &lock before first use.
 */

#define VALID_MAGIC 0x5E4A0001

int
sem_init(sem_t *s, int pshared, unsigned int value)
{
	if(s == NULL){
		errno = EINVAL;
		return -1;
	}
	if(pshared != 0){
		/* Plan9 has no shared-memory semaphores */
		errno = ENOSYS;
		return -1;
	}
	if(value > SEM_VALUE_MAX){
		errno = EINVAL;
		return -1;
	}
	memset(s, 0, sizeof *s);
	s->rendez.l = &s->lock;
	s->count = (int)value;
	s->valid = VALID_MAGIC;
	return 0;
}

int
sem_destroy(sem_t *s)
{
	if(s == NULL || s->valid != VALID_MAGIC){
		errno = EINVAL;
		return -1;
	}
	s->valid = 0;
	return 0;
}

int
sem_wait(sem_t *s)
{
	if(s == NULL || s->valid != VALID_MAGIC){
		errno = EINVAL;
		return -1;
	}
	qlock(&s->lock);
	while(s->count <= 0)
		rsleep(&s->rendez);
	s->count--;
	qunlock(&s->lock);
	return 0;
}

int
sem_trywait(sem_t *s)
{
	if(s == NULL || s->valid != VALID_MAGIC){
		errno = EINVAL;
		return -1;
	}
	if(!canqlock(&s->lock)){
		errno = EAGAIN;
		return -1;
	}
	if(s->count <= 0){
		qunlock(&s->lock);
		errno = EAGAIN;
		return -1;
	}
	s->count--;
	qunlock(&s->lock);
	return 0;
}

int
sem_timedwait(sem_t *s, const struct timespec *abs_timeout)
{
	long long now_ns, abs_ns, rem_ms;

	if(s == NULL || s->valid != VALID_MAGIC){
		errno = EINVAL;
		return -1;
	}
	if(abs_timeout == NULL ||
	   abs_timeout->tv_nsec < 0 || abs_timeout->tv_nsec >= 1000000000L){
		errno = EINVAL;
		return -1;
	}

	qlock(&s->lock);
	while(s->count <= 0){
		/* compute remaining time in milliseconds */
		now_ns = nsec();
		abs_ns = (long long)abs_timeout->tv_sec * 1000000000LL
		         + abs_timeout->tv_nsec;
		rem_ms = (abs_ns - now_ns) / 1000000LL;

		if(rem_ms <= 0){
			qunlock(&s->lock);
			errno = ETIMEDOUT;
			return -1;
		}

		/*
		 * Plan9 has no timed rsleep. We poll with short sleeps.
		 * Release the lock, sleep briefly, reacquire and recheck.
		 * This is not ideal but correct — worst case latency is
		 * one sleep interval (capped at 10ms).
		 */
		qunlock(&s->lock);
		_SLEEP((int)(rem_ms < 10 ? rem_ms : 10));
		qlock(&s->lock);

		/* recheck timeout after reacquiring */
		now_ns = nsec();
		if(now_ns >= abs_ns){
			qunlock(&s->lock);
			errno = ETIMEDOUT;
			return -1;
		}
	}
	s->count--;
	qunlock(&s->lock);
	return 0;
}

int
sem_post(sem_t *s)
{
	if(s == NULL || s->valid != VALID_MAGIC){
		errno = EINVAL;
		return -1;
	}
	qlock(&s->lock);
	s->count++;
	rwakeup(&s->rendez);
	qunlock(&s->lock);
	return 0;
}

int
sem_getvalue(sem_t *s, int *sval)
{
	if(s == NULL || s->valid != VALID_MAGIC || sval == NULL){
		errno = EINVAL;
		return -1;
	}
	qlock(&s->lock);
	*sval = s->count;
	qunlock(&s->lock);
	return 0;
}

/*
 * Named semaphores — not supported
 */
sem_t *
sem_open(const char *name, int oflag, ...)
{
	(void)name;
	(void)oflag;
	errno = ENOSYS;
	return SEM_FAILED;
}

int
sem_close(sem_t *s)
{
	(void)s;
	errno = ENOSYS;
	return -1;
}

int
sem_unlink(const char *name)
{
	(void)name;
	errno = ENOSYS;
	return -1;
}
