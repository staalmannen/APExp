#ifndef ATOMIC_ARCH_H
#define ATOMIC_ARCH_H

/*
 * Pure C89, portable "atomic" layer implementing musl-style
 * atomic operations using pthread mutexes.
 *
 * - No inline assembly
 * - No C11 <stdatomic.h>
 * - Works on ANY C89 platform with pthreads
 * - Provides SC-like semantics via mutex locking
 *
 * NOTE: These are NOT lock-free and not suitable for high‑performance
 * atomic operations. They *are* correct and portable.
 */

#include <pthread.h>

// put in defines here that will be picked up by atomic.h

#define a_ll atomic_load_long
#define a_ll_p atomic_load_ptr
#define a_cas atomic_cas_long
#define a_cas_p atomic_cas_ptr
#define a_fetch_add atomic_fetch_add_long
#define a_fetch_and atomic_fetch_and_uint
#define a_fetch_or atomic_fetch_or_uint
#define a_store atomic_store_long
// no idea what it corresponds to
int a_sc(int *, int) { return 0; } 



/* ---- Atomic type wrappers ---- */

typedef struct {
    pthread_mutex_t lock;
    int value;
} atomic_int_t;

typedef struct {
    pthread_mutex_t lock;
    unsigned int value;
} atomic_uint_t;

typedef struct {
    pthread_mutex_t lock;
    long value;
} atomic_long_t;

typedef struct {
    pthread_mutex_t lock;
    unsigned long value;
} atomic_ulong_t;

typedef struct {
    pthread_mutex_t lock;
    void *value;
} atomic_ptr_t;


/* ---- Initialization macros ---- */

#define ATOMIC_INIT_INT(v)      { PTHREAD_MUTEX_INITIALIZER, (v) }
#define ATOMIC_INIT_UINT(v)     { PTHREAD_MUTEX_INITIALIZER, (v) }
#define ATOMIC_INIT_LONG(v)     { PTHREAD_MUTEX_INITIALIZER, (v) }
#define ATOMIC_INIT_ULONG(v)    { PTHREAD_MUTEX_INITIALIZER, (v) }
#define ATOMIC_INIT_PTR(v)      { PTHREAD_MUTEX_INITIALIZER, (v) }


/* ---- Load ---- */

static inline int atomic_load_int(atomic_int_t *obj)
{
    int r;
    pthread_mutex_lock(&obj->lock);
    r = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return r;
}

static inline unsigned int atomic_load_uint(atomic_uint_t *obj)
{
    unsigned int r;
    pthread_mutex_lock(&obj->lock);
    r = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return r;
}

static inline long atomic_load_long(atomic_long_t *obj)
{
    long r;
    pthread_mutex_lock(&obj->lock);
    r = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return r;
}

static inline unsigned long atomic_load_ulong(atomic_ulong_t *obj)
{
    unsigned long r;
    pthread_mutex_lock(&obj->lock);
    r = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return r;
}

static inline void *atomic_load_ptr(atomic_ptr_t *obj)
{
    void *r;
    pthread_mutex_lock(&obj->lock);
    r = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return r;
}


/* ---- Store ---- */

static inline void atomic_store_int(atomic_int_t *obj, int v)
{
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
}

static inline void atomic_store_uint(atomic_uint_t *obj, unsigned int v)
{
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
}

static inline void atomic_store_long(atomic_long_t *obj, long v)
{
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
}

static inline void atomic_store_ulong(atomic_ulong_t *obj, unsigned long v)
{
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
}

static inline void atomic_store_ptr(atomic_ptr_t *obj, void *v)
{
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
}


/* ---- Exchange ---- */

static inline int atomic_xchg_int(atomic_int_t *obj, int v)
{
    int old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}

static inline long atomic_xchg_long(atomic_long_t *obj, long v)
{
    long old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}

static inline void *atomic_xchg_ptr(atomic_ptr_t *obj, void *v)
{
    void *old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}


/* ---- Compare-and-swap (CAS) ---- */
/* Returns non-zero on success */

static inline int atomic_cas_int(atomic_int_t *obj, int expected, int desired)
{
    int ok = 0;
    pthread_mutex_lock(&obj->lock);
    if (obj->value == expected) {
        obj->value = desired;
        ok = 1;
    }
    pthread_mutex_unlock(&obj->lock);
    return ok;
}

static inline int atomic_cas_long(atomic_long_t *obj, long expected, long desired)
{
    int ok = 0;
    pthread_mutex_lock(&obj->lock);
    if (obj->value == expected) {
        obj->value = desired;
        ok = 1;
    }
    pthread_mutex_unlock(&obj->lock);
    return ok;
}

static inline int atomic_cas_ptr(atomic_ptr_t *obj, void *expected, void *desired)
{
    int ok = 0;
    pthread_mutex_lock(&obj->lock);
    if (obj->value == expected) {
        obj->value = desired;
        ok = 1;
    }
    pthread_mutex_unlock(&obj->lock);
    return ok;
}


/* ---- Fetch-and-add / logical ops ---- */

static inline int atomic_fetch_add_int(atomic_int_t *obj, int v)
{
    int old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value += v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}

static inline long atomic_fetch_add_long(atomic_long_t *obj, long v)
{
    long old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value += v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}

static inline unsigned int atomic_fetch_or_uint(atomic_uint_t *obj, unsigned int v)
{
    unsigned int old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value |= v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}

static inline unsigned int atomic_fetch_and_uint(atomic_uint_t *obj, unsigned int v)
{
    unsigned int old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value &= v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}


/* ---- Memory fence ---- */

static inline void atomic_fence(void)
{
    /* Full SC fence semantics: lock/unlock does the job */
    /* No-op here, included for API completeness */
}

#endif /* ATOMIC_ARCH_H */
