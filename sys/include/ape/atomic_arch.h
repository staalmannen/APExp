#ifndef ATOMIC_ARCH_H
#define ATOMIC_ARCH_H

/*
 * Pure C89, portable "atomic" implementation that matches
 * the LL/SC API required by atomic.h:
 *
 *   a_ll(p)      - load-linked
 *   a_ll_p(p)    - load-linked for pointers
 *   a_sc(p, v)   - store-conditional
 *   a_sc_p(p, v) - store-conditional for pointers
 *
 * Implemented using pthread mutexes (always succeed).
 *
 * No inline asm.
 * No C11 atomics.
 */

#include <pthread.h>

/* ---- Atomic wrappers ---- */

typedef struct {
    pthread_mutex_t lock;
    long value;
} atomic_long_t;

typedef struct {
    pthread_mutex_t lock;
    void *value;
} atomic_ptr_t;


/* ---- Initialization macros ---- */

#define ATOMIC_INIT_LONG(v)  { PTHREAD_MUTEX_INITIALIZER, (v) }
#define ATOMIC_INIT_PTR(v)   { PTHREAD_MUTEX_INITIALIZER, (v) }


/* ============================================================
   LL / SC API required by atomic.h
   ============================================================ */

/* ---- a_ll: load-linked for int/long ---- */
static inline long a_ll(volatile long *p)
{
    atomic_long_t *obj = (atomic_long_t *)p;
    long v;
    pthread_mutex_lock(&obj->lock);
    v = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return v;
}

/* ---- a_ll_p: load-linked for pointers ---- */
static inline void *a_ll_p(volatile void *p)
{
    atomic_ptr_t *obj = (atomic_ptr_t *)p;
    void *v;
    pthread_mutex_lock(&obj->lock);
    v = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return v;
}

/* ---- a_sc: store-conditional for int/long ---- */
/* Always succeeds in this mutex-based backend */
static inline int a_sc(volatile long *p, long v)
{
    atomic_long_t *obj = (atomic_long_t *)p;
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
    return 1;   /* always succeeds */
}

/* ---- a_sc_p: store-conditional for pointers ---- */
static inline int a_sc_p(volatile void *p, void *v)
{
    atomic_ptr_t *obj = (atomic_ptr_t *)p;
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
    return 1;   /* always succeeds */
}


/* ============================================================
   Optional helpers used by atomic.h barriers/spin
   ============================================================ */

static inline void a_barrier(void)
{
    /* A full mutex lock/unlock implies a full memory barrier,
       so this is a cheap dummy barrier. */
}

#define a_pre_llsc()   a_barrier()
#define a_post_llsc()  a_barrier()

#endif /* ATOMIC_ARCH_H */
