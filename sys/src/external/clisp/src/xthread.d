/*
 * Cross-platform thread support
 * Bruno Haible 1997-1999
 * Sam Steingold 2001-2009
 * Vladimir Tzankov 2008-2009

 =============================================================================
 This part is heavily influenced by the file <X11/Xthreads.h> from X11R6,
 which carries the following copyright:
 -----------------------------------------------------------------------------
 Copyright (c) 1993  X Consortium

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 Except as contained in this notice, the name of the X Consortium shall not be
 used in advertising or otherwise to promote the sale, use or other dealings
 in this Software without prior written authorization from the X Consortium.
 -----------------------------------------------------------------------------

 Upon entry to this file, one of these symbols shall be defined:
 POSIX_THREADS       POSIX.1c            pthread_*
 SOLARIS_THREADS     Solaris 2.4, 2.5    thr_*
 WIN32_THREADS       Win32               *Thread

 This file defines the following types:
   xthread_t         Type of a thread
   xcondition_t      Type of a condition (wait queue with signalling)
   xmutex_t          Type of a mutex (mutually exclusive lock)
   xthread_key_t     Type of a key for accessing (limited) thread-local storage
 and the following functions/macros:
 - Threads in general:
   - Initialization of the thread subsystem.
   extern void           xthread_init (void);
   - Return the current thread.
   extern xthread_t      xthread_self (void);
   - Create a new thread.
   extern int            xthread_create (xthread_t* thread, void* (*startroutine) (void*), void* arg);
   - Terminate the current thread.
   extern void           xthread_exit (void* retvalue);
   - Give other threads a chance to run.
   extern void           xthread_yield (void);
   - Compare two threads for identity.
   extern bool        xthread_equal (xthread_t thread1, xthread_t thread2);
 - Conditions:
   - Initialize a wait queue.
   extern int            xcondition_init (xcondition_t* c);
   - Destroy a wait queue. The wait queue must be empty (noone waiting).
   extern int            xcondition_destroy (xcondition_t* c);
   - Release a mutex and put the current thread into the wait queue.
   - When the wait ends, the mutex is acquired again.
   extern int            xcondition_wait (xcondition_t* c, xmutex_t* m);
   - Notify and unblock one thread in the wait queue.
   extern int            xcondition_signal (xcondition_t* c);
   - Notify and unblock all threads in the wait queue.
   extern int            xcondition_broadcast (xcondition_t* c);
 - Mutexes:
   - Initialize a mutex.
   extern int            xmutex_init (xmutex_t* m);
   - Destroy a mutex.
   extern int            xmutex_destroy (xmutex_t* m);
   - Lock a mutex.
   extern int            xmutex_lock (xmutex_t* m);
   - Unlock a mutex.
   extern int            xmutex_unlock (xmutex_t* m);
 - Thread-local storage:
   - (This is probably not useful at all. The number of thread-local storage
   - words is limited: 512 on Win32, 128 with LinuxThreads. And it's probably
   - much slower than my current_thread() function.)
   - Create a word of thread-local storage, and return a key to it.
   extern int            xthread_key_create (xthread_key_t* key);
   - Delete a word of thread-local storage.
   extern int            xthread_key_delete (xthread_key_t key);
   - Get the value of the thread-local storage word for the current thread.
   extern void*          xthread_key_get (xthread_key_t key);
   - Set the value of the thread-local storage word for the current thread.
   extern void           xthread_key_set (xthread_key_t key, void* value);
*/


#if !(defined(POSIX_THREADS) || defined(SOLARIS_THREADS) || defined(WIN32_THREADS))
  #error Define your flavour of multithreading
#endif

#if defined(POSIX_THREADS)

#include <pthread.h>
#include <sched.h>

#define THREADPROC_SIGNATURE void *

#define xthread_t  pthread_t
#define xcondition_t  pthread_cond_t
#define xthread_key_t  pthread_key_t
/* raw mutex used for thread suspension/resume */
#define xmutex_raw_t  pthread_mutex_t

#define xthread_init()
#define xthread_self()  pthread_self()
static inline int xthread_create(xthread_t *thread,void *(*startroutine)(void *),
				 void *arg, size_t stacksize)
{
  int r;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  if (stacksize)
    pthread_attr_setstacksize(&attr,stacksize);
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
  r=pthread_create(thread,&attr,startroutine,arg);
  pthread_attr_destroy(&attr);
  return r;
}

#define xthread_exit(v)  pthread_exit(v)
#define xthread_yield()  sched_yield()
#define xthread_equal(t1,t2)  pthread_equal(t1,t2)
#define xthread_signal(t,sig)  pthread_kill(t,sig)
#define xthread_sigmask(how,iset,oset)  pthread_sigmask(how,iset,oset)

#define xcondition_init(c)  pthread_cond_init(c,NULL)
#define xcondition_destroy(c)  pthread_cond_destroy(c)
#define xcondition_signal(c)  pthread_cond_signal(c)
#define xcondition_broadcast(c)  pthread_cond_broadcast(c)

#define xmutex_raw_init(m)  pthread_mutex_init(m,NULL)
#define xmutex_raw_destroy(m)  pthread_mutex_destroy(m)
#define xmutex_raw_lock(m)  pthread_mutex_lock(m)
#define xmutex_raw_trylock(m)  pthread_mutex_trylock(m)
#define xmutex_raw_unlock(m)  pthread_mutex_unlock(m)

#define xthread_key_create(key)  pthread_key_create(key,NULL)
#define xthread_key_delete(key)  pthread_key_delete(key)
#define xthread_key_get(key)  pthread_getspecific(key)
#define xthread_key_set(key,val)  pthread_setspecific(key,val)

#endif  /* POSIX*_THREADS */

#if defined(WIN32_THREADS)

/* include <windows.h>  -- already included by win32.d */
#define MAX_SEMAPHORE_COUNT  0x7fff
/* thread procedure return type and calling convention */
#define THREADPROC_SIGNATURE unsigned WINAPI

#define xthread_t unsigned
/* this is inefficient implementation of condition variables on win32.
   TODO: make it better */
typedef struct _xcondition {
  CRITICAL_SECTION cs;
  HANDLE sem;
  int waiting_count;
} _xcondition;
#define xcondition_t _xcondition
#define xmutex_raw_t CRITICAL_SECTION
#define xthread_key_t DWORD

#define xthread_init()
#define xthread_self()  GetCurrentThreadId()
/* xthread_create() should return 0 on success */
#define xthread_create(thread,startroutine,arg,stacksize)                       \
  (!CloseHandle((HANDLE)_beginthreadex(NULL,stacksize,startroutine,(LPVOID)arg,0,thread)))
#define xthread_exit(v)  _endthreadex((DWORD)(v))
#define xthread_yield()  Sleep(0)
#define xthread_equal(t1,t2)  ((t1)==(t2))
/* xthread_sigmask() and xthread_signal() are not needed here */
#define xcondition_init(c)						\
  (InitializeCriticalSection(&(c)->cs),                                 \
   (c)->sem=CreateSemaphore(NULL,0,MAX_SEMAPHORE_COUNT,NULL),		\
   (c)->waiting_count=0,						\
   GetLastError())
#define xcondition_destroy(c)  do {             \
  DeleteCriticalSection(&(c)->cs);              \
  CloseHandle((c)->sem);                        \
 } while (0)

/* NB: waiting on xcondition_t is implemented in zthread.d */

#define xcondition_signal(c)  do {                                     \
  EnterCriticalSection(&(c)->cs);                                      \
  if ((c)->waiting_count > 0) {                                        \
    ReleaseSemaphore((c)->sem,1,NULL);                                 \
    (c)->waiting_count--;                                              \
  }                                                                    \
  LeaveCriticalSection(&(c)->cs);                                      \
 } while(0)
#define xcondition_broadcast(c)  do {                                   \
  EnterCriticalSection(&(c)->cs);                                       \
  if ((c)->waiting_count > 0) {                                         \
    ReleaseSemaphore((c)->sem,(c)->waiting_count,NULL);                 \
    (c)->waiting_count=0;                                               \
  }                                                                     \
  LeaveCriticalSection(&(c)->cs);                                       \
 } while(0)

/* critical section functions do not return values and do not set
   last error */
#define xmutex_raw_init(m)  (InitializeCriticalSection(m),0)
#define xmutex_raw_destroy(m)  (DeleteCriticalSection(m),0)
#define xmutex_raw_lock(m)  (EnterCriticalSection(m),0)
#define xmutex_raw_trylock(m)  (TryEnterCriticalSection(m)==0)
#define xmutex_raw_unlock(m)  (LeaveCriticalSection(m),0)

#define xthread_key_create(key)  (*(key) = TlsAlloc())
#define xthread_key_delete(key)  TlsFree(key)
#define xthread_key_get(key)  TlsGetValue(key)
#define xthread_key_set(key,val)  TlsSetValue(key,val)

#endif  /* WIN32_THREADS */

/* this is the mutex that we are going to use */
typedef struct xlock_t {
  xmutex_raw_t xl_internal_mutex; /* guarding the internals */
  xcondition_t xl_wait_cv; /* condition variable to wait on */
  xmutex_raw_t xl_mutex; /* real mutex. should be mutex and not boolean since
                            it should be passed to pthread_cond_wait() */
  xthread_t xl_owner; /* who owns the lock */
  bool xl_owned; /* _owner initialized? no known invalid xthread_t values! */
  int xl_recurse_count; /* how many times xl_owned has acquired the lock */
} xlock_t;

/* infinite wait */
#define THREAD_WAIT_INFINITE ((uintL)-1)

/* global functions for managing xlock_t. implementations and descriptions are
   in zthread.d */
int xlock_init(xlock_t *l);
int xlock_destroy(xlock_t *l);
int xlock_lock_helper(xlock_t *l, uintL timeout, bool lock_real);
int xlock_unlock_helper(xlock_t *l, bool unlock_real);
int xcondition_wait_helper(xcondition_t *c,xlock_t *m, uintL timeout);

/* our lisp space mutex */
#define xmutex_t  xlock_t

/* xmutex_t opertions*/
#define xmutex_init(m)  xlock_init(m)
#define xmutex_destroy(m)  xlock_destroy(m)
#define xmutex_lock(m)  xlock_lock_helper(m,THREAD_WAIT_INFINITE,true)
#define xmutex_timedlock(m,millis)  xlock_lock_helper(m,millis,true)
#define xmutex_trylock(m)  xlock_lock_helper(m,0,true)
#define xmutex_unlock(m)  xlock_unlock_helper(m,true)

/* and some xcondition_t operations  */
#define xcondition_wait(c,m)  xcondition_wait_helper(c,m,THREAD_WAIT_INFINITE)
#define xcondition_timedwait(c,m,millis)  xcondition_wait_helper(c,m,millis)


/* ==========================================================================

 Spin-locks.
 This is the most elementary kind of locks.
 Acquiring and releasing of a spin-lock can be considered an atomic operation.
 Differences between spin-locks and mutexes:
 - Spin-locks have to be locked only for a short time; no blocking system
   calls must be performed with a spin-lock held; no other locks can be
   acquired while a spin-lock is held without special care.
 - Therefore spin-locks can be assumed to be unlocked "soon", without any
   particular action to be performed. When trying to acquire a spin-lock which
   is currently locked, all you can do is sit down and spin.
 - Acquiring a lock which is previously unlocked, and releasing a lock are
   fast operations.

   Inline assembly syntax is gcc specific - so we use the gcc extension for
   block expressions in testandset(). On win32 with MSVC - InterlockedXXX
   function should be used .*/


#if defined(GNU) && (defined(MC680X0) || defined(SPARC) || defined(MIPS) || defined(I80386) || defined(DECALPHA) || defined(POWERPC) || defined(AMD64))

  /* A value 0 means unlocked, != 0 means locked. */
  #define spinlock_t int

  /* The following atomic operations are borrowed from LinuxThreads-0.6
   and were mostly written by Richard Henderson <rth@tamu.edu>.

   testandset(spinlock) tries to acquire the spinlock. It returns
   0 if it succeeded (i.e. the old value was 0, the new one is != 0).
   It returns != 0 if it failed (i.e. the old value was != 0). */

  #define spinlock_init(spinlock)  do { *(spinlock) = 0; } while(0)

  #ifdef MC680X0
    #define testandset(spinlock)                                \
      ({ char ret;                                              \
        __asm__ __volatile__("tas %1; sne %0"                   \
                             : "=g" (ret), "=m" (*(spinlock))   \
                             : "1" (*(spinlock))                \
                             : "cc");                           \
        ret;})

    #define spinlock_release(spinlock)  do { *(spinlock) = 0; } while(0)
  #endif
  #ifdef SPARC
    #define testandset(spinlock)                                \
      ({ int ret;                                               \
        __asm__ __volatile__("ldstub %1,%0"                     \
                             : "=r" (ret), "=m" (*(spinlock))   \
                             : "1" (*(spinlock)));              \
        ret;})
    #define spinlock_release(int* spinlock)             \
      do { __asm__ __volatile__("stbar; stb %1,%0"      \
                                : "=m" (*(spinlock))    \
                                : "r" (0));             \
      } while(0)
  #endif
  #ifdef MIPS
    #define testandset(spinlock)                                     \
      ({ long ret;                                                   \
        long temp;                                                   \
        __asm__ __volatile__("#Inline spinlock test & set"           \
                             "\n\t"  ".set mips2"                    \
                             "\n" "1: ll %0,%2"                      \
                             "\n\t"  "bnez %0,2f"                    \
                             "\n\t"  ".set noreorder"                \
                             "\n\t"  "li %1,1"                       \
                             "\n\t"  ".set reorder"                  \
                             "\n\t"  "sc %1,%2"                      \
                             "\n\t"  "beqz %1,1b"                    \
                             "\n" "2: .set mips0"                    \
                             "\n\t"  "#End spinlock test & set"      \
                             : "=&r" (ret), "=&r" (temp), "=m" (*(spinlock)) \
                             : "2" (*(spinlock))                     \
                             : "memory"                              \
                             );                                      \
        ret;})
    #define spinlock_release(spinlock)  do { *(spinlock) = 0; } while(0)
  #endif
  #if defined(I80386) || defined(AMD64)
    #define testandset(spinlock)                                \
      ({ int ret;                                               \
        __asm__ __volatile__("xchgl %0,%1"                      \
                             : "=r" (ret), "=m" (*(spinlock))   \
                             : "0" (1), "m" (*(spinlock))       \
                             : "memory");                       \
        ret;})
    #define spinlock_release(spinlock)                          \
      do {                                                      \
        __asm__ __volatile__("movl $0, %0"                      \
                             : "=m"(*(spinlock))                \
                             : "m" (*(spinlock))                \
                             : "memory");                       \
      } while (0)
  #endif
  #ifdef POWERPC
    #define testandset(spinlock)                        \
      ({ int ret;                                       \
        __asm__ __volatile__(                           \
                             "0:lwarx %0,0,%1 \n"       \
                             " cmpwi %0,0 \n"           \
                             " bne- 1f \n"              \
                             " stwcx. %2,0,%1 \n"       \
                             " bne- 0b \n"              \
                             "1:  isync  \n"            \
                             : "=&r"(ret)               \
                             : "r"(spinlock), "r"(1)    \
                             : "cr0", "memory");        \
        ret;})
    #define spinlock_release(spinlock)                        \
       do {                                                   \
         __asm__ __volatile__("sync" : : : "memory");         \
         *spinlock = 0;                                       \
       } while (0)
  #endif
  #ifdef DECALPHA
    #define testandset(spinlock)                                        \
      { long ret;                                                       \
        long temp;                                                      \
        __asm__ __volatile__("/* Inline spinlock test & set */"         \
                             "\n" "1: ldl_l %0,%2"                      \
                             "\n\t"  "bne %0,2f"                        \
                             "\n\t"  "or $31,1,%1"                      \
                             "\n\t"  "stl_c %1,%2"                      \
                             "\n\t"  "beq %1,1b"                        \
                             "\n" "2: mb"                               \
                             "\n\t"  "/* End spinlock test & set */"    \
                             : "=&r" (ret), "=&r" (temp), "=m" (*(spinlock)) \
                             : "2" (*(spinlock))                        \
                             : "memory");                               \
      ret;})
    #define spinlock_release(spinlock) \
      do { __asm__ __volatile__("mb" : : : "memory"); *(spinlock) = 0; } while(0)
  #endif

  #define spinlock_tryacquire(spinlock) (testandset(spinlock)==0)
  #define spinlock_acquire(spinlock) while (testandset(spinlock)) { xthread_yield(); }
  #define spinlock_destroy(spinlock)

#elif defined(GNU) && defined(HPPA)

  /* This is borrowed from glibc-2.0.4. */
  #define spinlock_t int __attribute__((__aligned__(16)))
  /* A value -1 means unlocked, 0 means locked. */

  /* testandset(spinlock) tries to acquire the spinlock. It returns
   0 if it succeeded (i.e. the old value was -1, the new one is 0).
   It returns != 0 if it failed (i.e. the old value was 0). */

  #define spinlock_init(spinlock)  do { *(spinlock) = -1; } while(0)
  #define testandset(spinlock)                                  \
    ({ int ret;                                                 \
      __asm__ __volatile__("ldcws %0,%1"                        \
                           : "=m" (*(spinlock)), "=r" (ret)     \
                           : "m" (*(spinlock)));                \
      ret;})
  #define spinlock_tryacquire(spinlock) (testandset(spinlock)==0)
  #define spinlock_acquire(spinlock) while (testandset(spinlock)) { xthread_yield(); }
  #define spinlock_release(spinlock)  do { *(spinlock) = -1; } while(0)
  #define spinlock_destroy(spinlock)

#else /* not know architecture with inline asm implementation */
  #ifdef GENERATIONAL_GC
    #error Generational GC is not compatible with "slow" spinlocks.
  #endif
  /* Slow, but portable. */
  #define spinlock_t xmutex_t
  /* do not check for errors from xmutex_xxxx() even if there is
     problem it is too generic in order to be handled properly.*/
  #define spinlock_init(spinlock) xmutex_init(spinlock)
  #define spinlock_tryacquire(spinlock) xmutex_trylock(spinlock)
  #define spinlock_acquire(spinlock) xmutex_lock(spinlock)
  #define spinlock_release(spinlock) xmutex_unlock(spinlock)
  #define spinlock_destroy(spinlock) xmutex_destroy(spinlock)

#endif


/* ====================================================================== */
