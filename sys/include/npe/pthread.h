#ifndef _npe_pthread_h_
#define _npe_pthread_h_

#pragma lib "libnpe_pthread.a"

#ifndef nil
#include <u.h>
#endif
#ifndef nelem
#include <libc.h>
#include <thread.h>
#endif

typedef struct pthread_attr_t pthread_attr_t;
typedef struct pthread_cond_t pthread_cond_t;
typedef struct pthread_mutex_t pthread_mutex_t;
typedef struct pthread_once_t pthread_once_t;
typedef uintptr pthread_t;

#pragma incomplete pthread_attr_t

struct pthread_cond_t {
	Rendez;
	QLock lock;
};

struct pthread_once_t {
	QLock;
	int done;
};

struct pthread_mutex_t {
	QLock;
};

#define PTHREAD_COND_INITIALIZER {0}
#define PTHREAD_ONCE_INIT {0}
#define PTHREAD_MUTEX_INITIALIZER {0}

int pthread_create(pthread_t *pt, pthread_attr_t *attr, void *(*f)(void *), void *arg);
int pthread_join(pthread_t thread, void **retval);

int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
int pthread_attr_setstacksize(pthread_attr_t *attr, int stack_size);

int pthread_once(pthread_once_t *once_control, void (*init_routine)(void));

int pthread_mutex_init(pthread_mutex_t *mutex, void *attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

int pthread_cond_init(pthread_cond_t *cond, void *attr);
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int pthread_cond_signal(pthread_cond_t *cond);
int pthread_cond_broadcast(pthread_cond_t *cond);

#endif
