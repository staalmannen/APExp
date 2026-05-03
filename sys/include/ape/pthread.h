#ifndef __PTHREAD_H
#define __PTHREAD_H
#pragma lib "/$M/lib/ape/libap.a"

#define _LOCK_EXTENSION
#define _QLOCK_EXTENSION
#include <sys/types.h>
#include <unistd.h>
#include <lock.h>
#include <qlock.h>

typedef struct pthread_once pthread_once_t;
typedef pid_t pthread_t;
typedef int pthread_attr_t;
typedef struct pthread_mutex pthread_mutex_t;
typedef int pthread_mutexattr_t;
typedef struct pthread_cond pthread_cond_t;
typedef int pthread_condattr_t;
typedef struct pthread_key pthread_key_t;

enum {
	PTHREAD_THREADS_MAX = 1000,

	PTHREAD_CANCEL_DISABLE = 1,
};

struct pthread_once {
	Lock l;
	int once;
};
struct pthread_mutex {
	QLock l;

	Lock mu;
	pthread_t pid;
	int ref;
	pthread_mutexattr_t attr;
};
struct pthread_cond {
	QLock l;
	Rendez r;
};
struct pthread_key {
	Lock l;
	void (*destroy)(void*);
	struct {
		pthread_t	pid;
		const void	*p;
	} *arenas;
	int n;
};

typedef int pthread_spinlock_t;
typedef struct { unsigned __attr; } pthread_barrierattr_t;
typedef struct { unsigned __attr[2]; } pthread_rwlockattr_t;


#ifdef _BITS64
typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;
typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;
#else
typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[8]; } __u; } pthread_rwlock_t;
typedef struct { union { int __i[5]; volatile int __vi[5]; void *__p[5]; } __u; } pthread_barrier_t;
#endif


#define PTHREAD_ONCE_INIT		{ 0 }
#define PTHREAD_MUTEX_INITIALIZER	{ 0 }
#define PTHREAD_MUTEX_DEFAULT		0
#define PTHREAD_MUTEX_NORMAL		1
#define PTHREAD_MUTEX_RECURSIVE	2
#define PTHREAD_COND_INITIALIZER	{ 0 }
#define PTHREAD_BARRIER_SERIAL_THREAD (-1)

#ifdef __cplusplus
extern "C" {
#endif

extern int	pthread_atfork(void (*)(void), void (*)(void), void (*)(void));
extern int	pthread_once(pthread_once_t*, void (*)(void));
extern pthread_t	pthread_self(void);
extern int	pthread_equal(pthread_t, pthread_t);
extern int	pthread_create(pthread_t*, pthread_attr_t*, void *(*)(void*), void*);
extern void	pthread_exit(void*);
extern int	pthread_join(pthread_t, void**);

extern int	pthread_mutexattr_init(pthread_mutexattr_t*);
extern int	pthread_mutexattr_destroy(pthread_mutexattr_t*);
extern int	pthread_mutexattr_settype(pthread_mutexattr_t*, int);

extern int	pthread_mutex_init(pthread_mutex_t*, const pthread_mutexattr_t*);
extern int	pthread_mutex_lock(pthread_mutex_t*);
extern int	pthread_mutex_unlock(pthread_mutex_t*);
extern int	pthread_mutex_trylock(pthread_mutex_t*);
extern int	pthread_mutex_destroy(pthread_mutex_t*);

extern int	pthread_cond_init(pthread_cond_t*, pthread_condattr_t*);
extern int	pthread_cond_wait(pthread_cond_t*, pthread_mutex_t*);
extern int	pthread_cond_timedwait(pthread_cond_t*, pthread_mutex_t*, const struct timespec*);
extern int	pthread_cond_signal(pthread_cond_t*);
extern int	pthread_cond_broadcast(pthread_cond_t*);
extern int	pthread_cond_destroy(pthread_cond_t*);

extern int	pthread_key_create(pthread_key_t*, void (*)(void*));
extern int	pthread_key_delete(pthread_key_t);
extern void	*pthread_getspecific(pthread_key_t);
extern int	pthread_setspecific(pthread_key_t, const void*);

extern int	pthread_setcancelstate(int, int*);

#ifndef _PTHREAD_SIGMASK
#define _PTHREAD_SIGMASK
#include <signal.h>
extern int	pthread_sigmask(int, const sigset_t*, sigset_t*);
#endif

// stubs?
extern int pthread_attr_init(pthread_attr_t *);
extern int pthread_attr_destroy(pthread_attr_t *);
extern int pthread_attr_setdetachstate(pthread_attr_t *, int);
extern int pthread_attr_getdetachstate(const pthread_attr_t *, int *);
extern int pthread_attr_setstacksize(pthread_attr_t *, size_t);
extern int pthread_attr_getstacksize(const pthread_attr_t *, size_t *);

#define PTHREAD_CREATE_JOINABLE  0
#define PTHREAD_CREATE_DETACHED  1

extern int pthread_detach(pthread_t);

/* rwlock (in pthread_ext.c, types already in pthread.h): */
extern int pthread_rwlock_init(pthread_rwlock_t *, const pthread_rwlockattr_t *);
extern int pthread_rwlock_destroy(pthread_rwlock_t *);
extern int pthread_rwlock_rdlock(pthread_rwlock_t *);
extern int pthread_rwlock_wrlock(pthread_rwlock_t *);
extern int pthread_rwlock_tryrdlock(pthread_rwlock_t *);
extern int pthread_rwlock_trywrlock(pthread_rwlock_t *);
extern int pthread_rwlock_unlock(pthread_rwlock_t *);
extern int pthread_rwlockattr_init(pthread_rwlockattr_t *);
extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t *);
/* barrier (in pthread_ext.c, types already in pthread.h): */
extern int pthread_barrier_init(pthread_barrier_t *, const pthread_barrierattr_t *, unsigned);
extern int pthread_barrier_destroy(pthread_barrier_t *);
extern int pthread_barrier_wait(pthread_barrier_t *);
extern int pthread_barrierattr_init(pthread_barrierattr_t *);
extern int pthread_barrierattr_destroy(pthread_barrierattr_t *);


#ifdef __cplusplus
}
#endif

#endif
