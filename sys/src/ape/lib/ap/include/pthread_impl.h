#ifndef _PTHREAD_IMPL_H
#define _PTHREAD_IMPL_H

/*
 * Header-only compatibility shim for musl's internal pthread_impl.h,
 * adapted to work with the APExp pthread implementation (pthread.h).
 *
 * This file provides just enough of musl's internal API for musl
 * components to compile, without depending on:
 *
 *   - TLS register access (__get_tp)
 *   - clone(), futex(), raw syscalls
 *   - musl's internal thread structure and ABI
 *   - architecture-dependent pthread_arch.h
 *
 * All thread operations are mapped onto your existing pthread
 * implementation defined in pthread.h.
 */

#include <pthread.h>        /* APExp pthread implementation */
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
   Thread Self
   ------------------------------------------------------------
   musl uses __pthread_self() to get the TCB pointer.

   We simply map it to pthread_self(), since in your pthread
   implementation pthread_t is a pid_t and not a TCB.
   ============================================================ */

static inline pthread_t __pthread_self(void)
{
    return pthread_self(); /* from your pthread.h */
}

/* Dummy macros for TLS handling */

#define TP_OFFSET 0
#define DTP_OFFSET 0
#define TP_ADJ(p) (p)

/* No TLS ABI to initialize */
static inline int __init_tp(void *p) { return 0; }
static inline void *__copy_tls(unsigned char *p) { return NULL; }
static inline void __reset_tls(void) { }

/* ============================================================
   Cancellation + cleanup stubs
   ============================================================ */

static inline void __testcancel(void) { }
struct __ptcb { void *dummy; }; /* placeholder */

static inline void __do_cleanup_push(struct __ptcb *cb) { }
static inline void __do_cleanup_pop(struct __ptcb *cb) { }

/* No tsd dtors beyond what your system already provides */
static inline void __pthread_tsd_run_dtors(void) { }

/* ============================================================
   Key deletion sync call (unused)
   ============================================================ */

static inline void __pthread_key_delete_synccall(void (*dtor)(void *), void *p) { }
static inline int __pthread_key_delete_impl(pthread_key_t k)
{
    return pthread_key_delete(k); /* your pthread */
}

/* ============================================================
   Cancellation control
   ============================================================ */

static inline void __inhibit_ptc(void) { }
static inline void __acquire_ptc(void) { }
static inline void __release_ptc(void) { }

/* ============================================================
   Thread list & locking stubs
   ============================================================ */

static volatile int __thread_list_lock = 0;
static volatile int __abort_lock[1] = {0};

static inline void __tl_lock(void) { }
static inline void __tl_unlock(void) { }
static inline void __tl_sync(pthread_t t) { }

/* ============================================================
   Waiting / waking primitives
   ------------------------------------------------------------
   musl uses futex-based __wait() and __wake().

   We implement these in terms of mutex+cond (best possible for A).
   ============================================================ */

typedef struct {
    pthread_mutex_t m;
    pthread_cond_t  c;
} __waiter_t;

/* global waiter for all wait operations (simplified model) */
static __waiter_t __waiter = { PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER };

/* Simulated wait: waits while *addr == val */
static inline void __wait(volatile int *addr, volatile int *cond, int val, int priv)
{
    (void)cond; (void)priv;

    pthread_mutex_lock(&__waiter.m);
    while (*addr == val)
        pthread_cond_wait(&__waiter.c, &__waiter.m);
    pthread_mutex_unlock(&__waiter.m);
}

/* Wake cnt waiters */
static inline void __wake(volatile void *addr, int cnt, int priv)
{
    (void)addr; (void)priv;
    pthread_mutex_lock(&__waiter.m);
    if (cnt <= 1)
        pthread_cond_signal(&__waiter.c);
    else
        pthread_cond_broadcast(&__waiter.c);
    pthread_mutex_unlock(&__waiter.m);
}

/* Timed wait maps to normal wait (ignores timeout) */
static inline int __timedwait(volatile int *addr, int val,
    clockid_t clk, const struct timespec *ts, int priv)
{
    (void)clk; (void)ts; (void)priv;
    __wait(addr, NULL, val, priv);
    return 0;
}

static inline int __timedwait_cp(volatile int *addr, int val,
    clockid_t clk, const struct timespec *ts, int priv)
{
    return __timedwait(addr, val, clk, ts, priv);
}

/* ============================================================
   Misc stubs
   ============================================================ */

static inline void __membarrier_init(void) { }
static inline void __dl_thread_cleanup(void) { }

static inline void __unmapself(void *addr, size_t sz)
{
    /* cannot unmap current stack in this model */
}

static inline int __libc_sigaction(int s,
    const struct sigaction *a, struct sigaction *o)
{
    return sigaction(s, a, o);
}

/* Default stack/guard sizes (dummy values) */
static unsigned __default_stacksize = 1 << 20;
static unsigned __default_guardsize = 4096;

#define DEFAULT_STACK_SIZE  (__default_stacksize)
#define DEFAULT_GUARD_SIZE  (__default_guardsize)

#endif /* _PTHREAD_IMPL_H */


