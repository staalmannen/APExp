#ifndef __SEMAPHORE_H
#define __SEMAPHORE_H
#pragma lib "/$M/lib/ape/libap.a"

/*
 * POSIX semaphores for APExp / Plan9 9front
 *
 * sem_t is implemented using Plan9's QLock and Rendez primitives,
 * which provide the necessary mutual exclusion and condition-wait
 * behaviour. Named semaphores (sem_open/sem_close/sem_unlink) are
 * not supported and return ENOSYS.
 *
 * sem_timedwait is supported with millisecond granularity via
 * Plan9's _SLEEP(); the timeout may fire up to ~1ms late.
 *
 * All functions are async-signal-safe only to the extent that
 * Plan9's underlying lock primitives are.
 */

#define _LOCK_EXTENSION
#define _QLOCK_EXTENSION
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#include <lock.h>
#include <qlock.h>

/* SEM_FAILED: returned by sem_open on failure */
#define SEM_FAILED      ((sem_t *)0)

/* SEM_VALUE_MAX: maximum initial value for a semaphore */
#define SEM_VALUE_MAX   32767

typedef struct {
	QLock   lock;
	Rendez  rendez;
	int     count;
	int     valid;          /* initialisation sentinel */
} sem_t;

#ifdef __cplusplus
extern "C" {
#endif

/*
 * sem_init - initialise an unnamed semaphore
 *
 * pshared != 0 (shared between processes) is not supported on Plan9
 * and returns ENOSYS. pshared == 0 (thread-private) works correctly.
 */
extern int  sem_init(sem_t *, int pshared, unsigned int value);

/*
 * sem_destroy - destroy an unnamed semaphore
 * Any threads blocked on sem_wait at destruction time have
 * undefined behaviour — caller must ensure no waiters.
 */
extern int  sem_destroy(sem_t *);

/*
 * sem_wait - decrement (lock) the semaphore, blocking if zero
 */
extern int  sem_wait(sem_t *);

/*
 * sem_trywait - decrement if non-zero, return EAGAIN if zero
 */
extern int  sem_trywait(sem_t *);

/*
 * sem_timedwait - decrement with timeout
 * abs_timeout is an absolute CLOCK_REALTIME timespec.
 * Returns ETIMEDOUT if the semaphore was not decremented in time.
 */
extern int  sem_timedwait(sem_t *, const struct timespec *abs_timeout);

/*
 * sem_post - increment (unlock) the semaphore, waking one waiter
 */
extern int  sem_post(sem_t *);

/*
 * sem_getvalue - retrieve current semaphore count
 * If threads are blocked, *sval may be zero or negative (POSIX allows
 * either; we return the count which is >= 0).
 */
extern int  sem_getvalue(sem_t *, int *sval);

/*
 * Named semaphore operations — not supported on Plan9
 * All return SEM_FAILED / -1 with errno = ENOSYS.
 */
extern sem_t *sem_open(const char *name, int oflag, ...);
extern int    sem_close(sem_t *);
extern int    sem_unlink(const char *name);

#ifdef __cplusplus
}
#endif

#endif /* __SEMAPHORE_H */
