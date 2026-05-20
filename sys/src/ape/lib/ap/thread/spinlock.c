#include <pthread.h>
#include <errno.h>
#include <lock.h>

/*
 * pthread spinlock on Plan9 / APExp
 *
 * pthread_spinlock_t is typedef int.  Plan9's tas(int*) does a
 * hardware test-and-set: stores 1, returns the old value.
 * Convention: 0 = unlocked, non-zero = locked.
 *
 * pshared is ignored — Plan9 has no cross-process shared memory.
 */

int
pthread_spin_init(pthread_spinlock_t *s, int pshared)
{
	(void)pshared;
	if(s == NULL) return EINVAL;
	*s = 0;
	return 0;
}

int
pthread_spin_destroy(pthread_spinlock_t *s)
{
	if(s == NULL) return EINVAL;
	*s = 0;
	return 0;
}

int
pthread_spin_lock(pthread_spinlock_t *s)
{
	if(s == NULL) return EINVAL;
	while(tas((int*)s) != 0)
		;
	return 0;
}

int
pthread_spin_trylock(pthread_spinlock_t *s)
{
	if(s == NULL) return EINVAL;
	if(tas((int*)s) != 0)
		return EBUSY;
	return 0;
}

int
pthread_spin_unlock(pthread_spinlock_t *s)
{
	if(s == NULL) return EINVAL;
	*s = 0;
	return 0;
}
