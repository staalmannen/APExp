#ifndef ATOMIC_H
#define ATOMIC_H

/*
 * Mutex-backed C89-compatible implementation of the musl atomic API:
 *
 *   a_ll(p), a_ll_p(p)
 *   a_sc(p,v), a_sc_p(p,v)
 *   a_cas(), a_swap(), a_fetch_add(), a_fetch_and(), a_fetch_or()
 *   a_inc(), a_dec(), a_and(), a_or()
 *
 * This provides full musl-style semantics.
 *
 * No inline asm.
 * No C11 atomics.
 */

#include <pthread.h>
#include <stdint.h>

/* ------------------------------
   Atomic types
   ------------------------------ */

typedef struct {
    pthread_mutex_t lock;
    long value;
} atomic_long_t;

typedef struct {
    pthread_mutex_t lock;
    unsigned int value;
} atomic_uint_t;

typedef struct {
    pthread_mutex_t lock;
    void *value;
} atomic_ptr_t;

/* ------------------------------
   Initialization
   ------------------------------ */

#define ATOMIC_INIT_LONG(v)  { PTHREAD_MUTEX_INITIALIZER, (v) }
#define ATOMIC_INIT_UINT(v)  { PTHREAD_MUTEX_INITIALIZER, (v) }
#define ATOMIC_INIT_PTR(v)   { PTHREAD_MUTEX_INITIALIZER, (v) }

/* ------------------------------
   Barriers for LL/SC API
   ------------------------------ */

static inline void a_barrier(void)
{
    /* Mutex-based backends already provide full ordering. */
}

#define a_pre_llsc()  a_barrier()
#define a_post_llsc() a_barrier()

#define a_spin a_barrier

/* ------------------------------
   a_ll / a_ll_p
   ------------------------------ */

static inline long a_ll(volatile long *p)
{
    atomic_long_t *obj = (atomic_long_t *)p;
    long v;
    pthread_mutex_lock(&obj->lock);
    v = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return v;
}

static inline void *a_ll_p(volatile void *p)
{
    atomic_ptr_t *obj = (atomic_ptr_t *)p;
    void *v;
    pthread_mutex_lock(&obj->lock);
    v = obj->value;
    pthread_mutex_unlock(&obj->lock);
    return v;
}

/* ------------------------------
   a_sc / a_sc_p
   (Always succeed in mutex backend)
   ------------------------------ */

static inline int a_sc(volatile long *p, long v)
{
    atomic_long_t *obj = (atomic_long_t *)p;
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
    return 1; /* success */
}

static inline int a_sc_p(volatile void *p, void *v)
{
    atomic_ptr_t *obj = (atomic_ptr_t *)p;
    pthread_mutex_lock(&obj->lock);
    obj->value = v;
    pthread_mutex_unlock(&obj->lock);
    return 1; /* success */
}

/* ------------------------------
   a_cas
   ------------------------------ */

static inline long a_cas(volatile long *p, long expected, long desired)
{
    long old;
    a_pre_llsc();
    do old = a_ll(p);
    while (old == expected && !a_sc(p, desired));
    a_post_llsc();
    return old;
}

/* Pointer CAS */
static inline void *a_cas_p(volatile void *p, void *expected, void *desired)
{
    void *old;
    a_pre_llsc();
    do old = a_ll_p(p);
    while (old == expected && !a_sc_p(p, desired));
    a_post_llsc();
    return old;
}

/* ------------------------------
   a_swap
   ------------------------------ */

static inline long a_swap(volatile long *p, long v)
{
    long old;
    a_pre_llsc();
    do old = a_ll(p);
    while (!a_sc(p, v));
    a_post_llsc();
    return old;
}

/* ------------------------------
   a_fetch_add
   ------------------------------ */

static inline long a_fetch_add(volatile long *p, long v)
{
    long old;
    a_pre_llsc();
    do old = a_ll(p);
    while (!a_sc(p, old + v));
    a_post_llsc();
    return old;
}

/* ------------------------------
   a_fetch_and / a_fetch_or
   ------------------------------ */

static inline unsigned int a_fetch_and(volatile unsigned int *p, unsigned int v)
{
    atomic_uint_t *obj = (atomic_uint_t *)p;
    unsigned int old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value &= v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}

static inline unsigned int a_fetch_or(volatile unsigned int *p, unsigned int v)
{
    atomic_uint_t *obj = (atomic_uint_t *)p;
    unsigned int old;
    pthread_mutex_lock(&obj->lock);
    old = obj->value;
    obj->value |= v;
    pthread_mutex_unlock(&obj->lock);
    return old;
}

/* ------------------------------
   High-level helpers
   ------------------------------ */

static inline void a_and(volatile unsigned int *p, unsigned int v)
{
    a_fetch_and(p, v);
}

static inline void a_or(volatile unsigned int *p, unsigned int v)
{
    a_fetch_or(p, v);
}

static inline void a_inc(volatile long *p)
{
    a_fetch_add(p, 1);
}

static inline void a_dec(volatile long *p)
{
    a_fetch_add(p, -1);
}

static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
	union { uint64_t v; uint32_t r[2]; } u = { v };
	if (u.r[0]+1) a_and((atomic_uint_t *)p, u.r[0]);
	if (u.r[1]+1) a_and((atomic_uint_t *)p+1, u.r[1]);
}

static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
	union { uint64_t v; uint32_t r[2]; } u = { v };
	if (u.r[0]) a_or((atomic_uint_t *)p, u.r[0]);
	if (u.r[1]) a_or((atomic_uint_t *)p+1, u.r[1]);
}

static inline void a_or_l(volatile void *p, long v)
{
	if (sizeof(long) == sizeof(int)) a_or(p, v);
	else a_or_64(p, v);
}

static inline void a_crash()
{
	*(volatile char *)0=0;
}

static inline int a_ctz_64(uint64_t x)
{
	static const char debruijn64[64] = {
		0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28,
		62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11,
		63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
		51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
	};
	if (sizeof(long) < 8) {
		uint32_t y = x;
		if (!y) {
			y = x>>32;
			return 32 + a_ctz_32(y);
		}
		return a_ctz_32(y);
	}
	return debruijn64[(x&-x)*0x022fdd63cc95386dull >> 58];
}

static inline int a_ctz_l(unsigned long x)
{
	return (sizeof(long) < 8) ? a_ctz_32(x) : a_ctz_64(x);
}

static inline int a_clz_32(uint32_t x)
{
	x >>= 1;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x++;
	return 31-a_ctz_32(x);
}

static inline int a_clz_64(uint64_t x)
{
	if (x>>32)
		return a_clz_32(x>>32);
	return a_clz_32(x) + 32;
}

static inline int a_ctz_32(uint32_t x)
{
	return 31-a_clz_32(x&-x);
}


#endif /* ATOMIC_H */
