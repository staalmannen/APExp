/* stdio_locks.h – APExp locking glue for musl stdio */

#ifndef APE_STDIO_LOCKS_H
#define APE_STDIO_LOCKS_H

#include <pthread.h>
#include <stdint.h>

/*
 * -------------------------------------------------------------
 * FILE lock structure
 *
 * musl stores a pthread_mutex inside FILE. We do the same.
 * APExp's pthread layer provides mutex primitives as seen in the
 * extracted thread sources (mutex_lock.c, mutex_unlock.c, etc.).
 * -------------------------------------------------------------
 */
typedef struct StdioLock {
    pthread_mutex_t lock;
    pthread_once_t init_once;
} StdioLock;

/*
 * Initialize the mutex the first time it is used.
 */
static void __stdio_lock_init(StdioLock *s)
{
    pthread_mutex_init(&s->lock, NULL);
}

/*
 * Acquire lock (THREAD=YES uses pthreads).
 */
static inline void __stdio_lock(StdioLock *s)
{
    pthread_once(&s->init_once, (void(*)(void))__stdio_lock_init);
    pthread_mutex_lock(&s->lock);
}

/*
 * Release lock.
 */
static inline void __stdio_unlock(StdioLock *s)
{
    pthread_mutex_unlock(&s->lock);
}

#endif /* APE_STDIO_LOCKS_H */

