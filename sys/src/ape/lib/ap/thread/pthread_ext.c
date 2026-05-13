#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <alltypes.h>
#include "lib.h"

/*
 * pthread_attr_* stubs for APExp
 *
 * pthread_create() in APExp currently returns EINVAL if attr != NULL.
 * These stubs allow code that initialises and destroys attributes to
 * compile and link. The attr is always treated as default (detached=0,
 * stacksize=default) since we have no real thread scheduler.
 */

int
pthread_attr_init(pthread_attr_t *attr)
{
	if(attr == NULL) return EINVAL;
	*attr = 0;
	return 0;
}

int
pthread_attr_destroy(pthread_attr_t *attr)
{
	if(attr == NULL) return EINVAL;
	*attr = 0;
	return 0;
}

int
pthread_attr_setdetachstate(pthread_attr_t *attr, int state)
{
	(void)attr; (void)state;
	return 0;
}

int
pthread_attr_getdetachstate(const pthread_attr_t *attr, int *state)
{
	(void)attr;
	if(state) *state = PTHREAD_CREATE_JOINABLE;
	return 0;
}

int
pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize)
{
	(void)attr; (void)stacksize;
	return 0;
}

int
pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize)
{
	(void)attr;
	if(stacksize) *stacksize = 65536; /* nominal default */
	return 0;
}

int
pthread_attr_setstackaddr(pthread_attr_t *attr, void *stackaddr)
{
	(void)attr; (void)stackaddr;
	return 0;
}

int
pthread_attr_setscope(pthread_attr_t *attr, int scope)
{
	(void)attr; (void)scope;
	return 0;
}

int
pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy)
{
	(void)attr; (void)policy;
	return 0;
}

int
pthread_attr_setinheritsched(pthread_attr_t *attr, int inherit)
{
	(void)attr; (void)inherit;
	return 0;
}

/*
 * pthread_detach - mark thread as detached
 * APExp threads are always join-able; detach is a no-op.
 */
int
pthread_detach(pthread_t t)
{
	(void)t;
	return 0;
}

/*
 * pthread_rwlock_* — backed by Plan9 native RWLock (qlock.h)
 *
 * Plan9's RWLock allows true concurrent readers and exclusive writers.
 * pthread_rwlock_t is a union big enough (int[14] = 56 bytes) to hold
 * RWLock (≤40 bytes) plus a one-int write-mode flag.
 *
 * pthread_rwlock_unlock needs to know whether to call runlock or wunlock.
 * We track this with 'write_locked' stored after the RWLock in the opaque
 * storage.  Readers set nothing; only the writer sets write_locked=1 after
 * acquiring, clears it before releasing — safe because writers are exclusive.
 */
#include <qlock.h>
#include <string.h>

typedef struct {
	RWLock rw;
	int    write_locked;
} _RWL;

int
pthread_rwlock_init(pthread_rwlock_t *rwl, const pthread_rwlockattr_t *attr)
{
	(void)attr;
	memset(rwl, 0, sizeof *rwl);
	return 0;
}

int
pthread_rwlock_destroy(pthread_rwlock_t *rwl)
{
	(void)rwl;
	return 0;
}

int
pthread_rwlock_rdlock(pthread_rwlock_t *rwl)
{
	rlock(&((_RWL*)rwl)->rw);
	return 0;
}

int
pthread_rwlock_wrlock(pthread_rwlock_t *rwl)
{
	_RWL *r = (_RWL*)rwl;
	wlock(&r->rw);
	r->write_locked = 1;
	return 0;
}

int
pthread_rwlock_tryrdlock(pthread_rwlock_t *rwl)
{
	return canrlock(&((_RWL*)rwl)->rw) ? 0 : EBUSY;
}

int
pthread_rwlock_trywrlock(pthread_rwlock_t *rwl)
{
	_RWL *r = (_RWL*)rwl;
	if(!canwlock(&r->rw))
		return EBUSY;
	r->write_locked = 1;
	return 0;
}

int
pthread_rwlock_unlock(pthread_rwlock_t *rwl)
{
	_RWL *r = (_RWL*)rwl;
	if(r->write_locked){
		r->write_locked = 0;
		wunlock(&r->rw);
	} else {
		runlock(&r->rw);
	}
	return 0;
}

int
pthread_rwlockattr_init(pthread_rwlockattr_t *attr)
{
	(void)attr; return 0;
}

int
pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr)
{
	(void)attr; return 0;
}

/*
 * pthread_barrier_* stubs
 *
 * A barrier releases all waiting threads when count is reached.
 * With a single-threaded runtime this degenerates to: the first
 * (and only) caller is always the "serial" thread.
 */

int
pthread_barrier_init(pthread_barrier_t *b, const pthread_barrierattr_t *attr,
                     unsigned count)
{
	(void)b; (void)attr; (void)count;
	return 0;
}

int
pthread_barrier_destroy(pthread_barrier_t *b)
{
	(void)b; return 0;
}

int
pthread_barrier_wait(pthread_barrier_t *b)
{
	(void)b;
	/* single-threaded: always the serial thread */
	return PTHREAD_BARRIER_SERIAL_THREAD;
}

int
pthread_barrierattr_init(pthread_barrierattr_t *attr)
{
	(void)attr; return 0;
}

int
pthread_barrierattr_destroy(pthread_barrierattr_t *attr)
{
	(void)attr; return 0;
}
