#ifndef _FUTEX_SHIM_H
#define _FUTEX_SHIM_H

/*
 * Portable futex.h shim for musl compatibility
 * ------------------------------------------------------------
 * This header replaces musl's Linux futex-based synchronization
 * with a portable emulation based on pthread mutex + condition
 * variable.
 *
 * It exposes the constants and function names expected by
 * musl's pthread subsystem, but internally maps everything to
 * generic pthread primitives.
 *
 * NO Linux syscalls.
 * NO atomics beyond what pthread.h provides.
 * NO architecture-dependent code.
 */

#include <pthread.h>
#include <errno.h>

/* ============================================================
   Futex operation codes (musl expects these symbols)
   These values match Linux for compatibility but are unused.
   ============================================================ */

#define FUTEX_WAIT        0
#define FUTEX_WAKE        1
#define FUTEX_PRIVATE     128
#define FUTEX_WAIT_PRIVATE (FUTEX_WAIT | FUTEX_PRIVATE)
#define FUTEX_WAKE_PRIVATE (FUTEX_WAKE | FUTEX_PRIVATE)

/* ============================================================
   Internal waiter object
   A shared waiter is sufficient for the compatibility shim.
   ============================================================ */

typedef struct {
    pthread_mutex_t m;
    pthread_cond_t  c;
} __futex_waiter_t;

static __futex_waiter_t __futex_global = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_COND_INITIALIZER
};

/* ============================================================
   Portable futex_wait
   (Simulates: block while *addr == expected)
   ============================================================ */

static inline int futex_wait(volatile int *addr, int expected)
{
    pthread_mutex_lock(&__futex_global.m);

    /* Wait as long as *addr has not changed */
    while (*addr == expected)
        pthread_cond_wait(&__futex_global.c, &__futex_global.m);

    pthread_mutex_unlock(&__futex_global.m);
    return 0;
}

/* Timed version (timeout ignored in shim) */
static inline int futex_timedwait(volatile int *addr, int expected,
                                  const struct timespec *ts)
{
    (void)ts;
    return futex_wait(addr, expected);
}

/* ============================================================
   Portable futex_wake
   ============================================================ */

static inline int futex_wake(volatile int *addr, int count)
{
    (void)addr;

    pthread_mutex_lock(&__futex_global.m);

    if (count <= 1)
        pthread_cond_signal(&__futex_global.c);
    else
        pthread_cond_broadcast(&__futex_global.c);

    pthread_mutex_unlock(&__futex_global.m);
    return 0;
}

/* ============================================================
   Unified futex() call (musl-compatible signature)
   ------------------------------------------------------------
   Musl internally uses:
       futex(addr, FUTEX_WAIT|FUTEX_PRIVATE, expected, timeout)
       futex(addr, FUTEX_WAKE|FUTEX_PRIVATE, count)
   ============================================================ */

static inline int futex(volatile int *addr, int op, int val,
                        const struct timespec *ts)
{
    int is_private = op & FUTEX_PRIVATE;
    int cmd = op & ~FUTEX_PRIVATE;

    (void)is_private; /* private futex not meaningful here */

    switch (cmd) {
    case FUTEX_WAIT:
        return futex_wait(addr, val);

    case FUTEX_WAKE:
        return futex_wake(addr, val);

    default:
        /* Unsupported futex operations return ENOSYS */
        return ENOSYS;
    }
}

#endif /* _FUTEX_SHIM_H */
