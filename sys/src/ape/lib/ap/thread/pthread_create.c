#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include "lib.h"

extern int	_RFORK(int);

/*
 * pthread_create -- AND THE THREE BUGS IT CARRIED, all of which `xz'
 * found at once and none of which anything else in the tree had ever
 * reached.  The evidence is two acid stacks, not an argument:
 *
 *	79207  Rendez  0:00 0:00
 *	    _RENDEZVOUS  <- pthread_create+0x63
 *	                 <- mythread_create <- initialize_new_thread
 *	                 <- get_thread <- stream_encode_in <- main
 *
 *	79206  Ready   0:18 0:34        <- note the SYSTEM figure
 *	    _PREAD <- _NSEC <- nsec <- clock_gettime
 *	           <- pthread_cond_timedwait+0x40
 *	           <- mythread_cond_timedwait <- wait_for_work <- main
 *
 * 1. **THE CHILD'S RENDEZVOUS HAD NO PARTNER.**  The child called
 *    `_RENDEZVOUS(tag, 0)' and the parent fell straight through to
 *    `return 0'.  A grep for `_RENDEZVOUS' across the whole thread
 *    directory finds that ONE call, so nothing could ever answer it:
 *    **every thread this function created blocked for ever before
 *    reaching `f', and the creator was told it had succeeded.**  That
 *    is process 79207 above -- xz's first worker, parked in the
 *    handshake, 0:00 of CPU, while xz waited for work nobody was going
 *    to do.
 *
 *    *The handshake is not decoration.*  `pthread_exit' does
 *    `_pthreadget(pthread_self())' and ASSERTS the result is not null,
 *    and `pthread_join' looks the thread up the same way -- so the
 *    parent has to register the child's pid before the child runs any
 *    of its own code.  The rendezvous is exactly that barrier, and the
 *    half that does the registering was missing.
 *
 * 2. **`*t' WAS NEVER WRITTEN.**  The out parameter was simply unused,
 *    so every caller got whatever was on its stack and handed that to
 *    `pthread_join'.  `_pthreadsetpid' already existed for this and
 *    had no callers at all.
 *
 * 3. **`attr != NULL' RETURNED EINVAL, AND libap ITSELF ALWAYS PASSES
 *    ONE.**  `thread/cond_timedwait.c:107' does `pthread_attr_init',
 *    `pthread_attr_setdetachstate(PTHREAD_CREATE_DETACHED)' and then
 *    `pthread_create(&tid, &attr, ...)' -- which this function rejected
 *    out of hand, so `pthread_cond_timedwait' returned EAGAIN
 *    **without ever waiting**, on every call, for its whole existence.
 *    That is process 79206: `wait_for_work' is a loop, an instant
 *    return makes it a busy one, and each turn costs a `clock_gettime'
 *    -- which on Plan 9 is a `_PREAD'.  **A spin made of syscalls,
 *    which is why the `s' figure was pinned and the `l' figure was
 *    not.**
 *
 *    `pthread_ext.c' said so in a comment -- "pthread_create() in
 *    APExp currently returns EINVAL if attr != NULL. These stubs allow
 *    code that ... compile and link" -- and then a second libap file
 *    was written against the stubs.  *A capability declared and not
 *    present, which is this tree's commonest bug wearing its other
 *    face.*
 *
 * EVERY ATTRIBUTE REMAINS A NO-OP, and accepting the struct says only
 * that: `pthread_attr_t' is an `int', the setters ignore it, and
 * detachstate in particular is NOT honoured -- a detached thread still
 * leaves a Waitmsg for somebody to collect.  **Rejecting the attr did
 * not make detachstate work, it only made the call fail**, so this
 * trades a loud wrong answer for a quiet incomplete one and the
 * incompleteness is written down here and in the release notes rather
 * than implied.
 */
int
pthread_create(pthread_t *t, pthread_attr_t *attr, void *(*f)(void*), void *arg)
{
	void *p;
	int pid;
	Thread *priv;
	void *tag;

	(void)attr;	/* NOT `USED' -- APE's lib.h has no such macro */
	priv = _pthreadalloc();
	if(priv == NULL)
		return EAGAIN;
	tag = (void *)priv;
	pid = _RFORK(RFFDG|RFPROC|RFMEM);
	switch(pid){
	case -1:
		_syserrno();
		_pthreadfree(priv);
		return errno;
	case 0:
		/*
		 * Wait for the parent to put our pid in the Thread record.
		 * Until it has, pthread_self() names a thread _pthreadget()
		 * cannot find, and pthread_exit's assert would fire on the
		 * way out of f().
		 *
		 * RFMEM shares data and bss, which is where `privileges[]'
		 * lives, so both ends see the same record and the same tag.
		 * The STACK is not shared -- dupseg() gives SG_STACK a new
		 * segment whatever RFMEM says -- so the parent returning
		 * through this frame does not disturb the child sitting in
		 * it.
		 */
		_RENDEZVOUS(tag, (void *)0);
		p = f(arg);
		pthread_exit(p);
		abort(); /* can't reach here */
	}
	_pthreadsetpid(priv, pid);
	if(t != NULL)
		*t = pid;
	_RENDEZVOUS(tag, (void *)0);
	return 0;
}

/*
 * Version marker for `pthread-test.c'.  `pcc -o x x.c' relinks against
 * the INSTALLED libap, so a test built from a fresh pull can run
 * days-old library code and report on it.  A test that calls this will
 * not LINK against a libap predating the three fixes above.  Tenth use
 * of the idiom, after _sock_listenmark, _execmark, _ttymark,
 * _getcwdmark, _printfmark, _dupmark, _dotdirmark, _tempmark,
 * _fdinfomark, _umaskmark, _bufmark, _rdevmark and _selregmark.
 */
int
_pthreadmark(void)
{
	return 1;
}
