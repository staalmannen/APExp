#include "lib.h"
#include "sys9.h"
#include <signal.h>
#include <errno.h>
#include <time.h>

extern void (*_sighdlr[MAXSIG+1])(int, char *, Ureg*);

/*
 * sigwait: wait for one of the signals in set to be delivered.
 *
 * We install a temporary handler for each requested signal that records
 * the signal number in a volatile, then sleep in 1ms increments until
 * one fires.  Plan9 notes are delivered asynchronously and interrupt
 * the _SLEEP syscall, so this works correctly.
 */

static volatile int _sigwait_caught;

static void
sigwait_handler(int sig)
{
	_sigwait_caught = sig;
}

static void
install_handlers(const sigset_t *set,
                 void (**saved)(int, char*, Ureg*))
{
	int i;
	for(i = 1; i < NSIG; i++) {
		if(*set & (1L << (i-1))) {
			saved[i] = _sighdlr[i];
			signal(i, (void(*)())sigwait_handler);
		} else {
			saved[i] = NULL;
		}
	}
}

static void
restore_handlers(const sigset_t *set,
                 void (**saved)(int, char*, Ureg*))
{
	int i;
	for(i = 1; i < NSIG; i++) {
		if(*set & (1L << (i-1)))
			signal(i, saved[i]);
	}
}

int
sigwait(const sigset_t *restrict set, int *restrict sig)
{
	void (*saved[NSIG])(int, char *, Ureg*);

	if(set == NULL || sig == NULL) {
		errno = EINVAL;
		return EINVAL;
	}

	_sigwait_caught = 0;
	install_handlers(set, saved);

	while(_sigwait_caught == 0)
		_SLEEP(1);

	*sig = _sigwait_caught;
	restore_handlers(set, saved);
	return 0;
}

int
sigwaitinfo(const sigset_t *restrict set, siginfo_t *restrict info)
{
	int sig, r;

	r = sigwait(set, &sig);
	if(r != 0) {
		errno = r;
		return -1;
	}
	if(info != NULL) {
		info->si_signo = sig;
		info->si_errno = 0;
		info->si_code  = SI_USER;
	}
	return sig;
}

int
sigtimedwait(const sigset_t *restrict set, siginfo_t *restrict info,
             const struct timespec *restrict timeout)
{
	void (*saved[NSIG])(int, char *, Ureg*);
	struct timespec now;
	long deadline_ms, now_ms;
	int sig;

	if(set == NULL) {
		errno = EINVAL;
		return -1;
	}

	_sigwait_caught = 0;
	install_handlers(set, saved);

	if(timeout != NULL) {
		clock_gettime(CLOCK_REALTIME, &now);
		deadline_ms = (now.tv_sec + timeout->tv_sec) * 1000L
		            + (now.tv_nsec + timeout->tv_nsec) / 1000000L;
	} else {
		deadline_ms = -1;
	}

	for(;;) {
		if(_sigwait_caught != 0)
			break;
		if(deadline_ms >= 0) {
			clock_gettime(CLOCK_REALTIME, &now);
			now_ms = now.tv_sec * 1000L + now.tv_nsec / 1000000L;
			if(now_ms >= deadline_ms) {
				restore_handlers(set, saved);
				errno = EAGAIN;
				return -1;
			}
		}
		_SLEEP(1);
	}

	sig = _sigwait_caught;
	restore_handlers(set, saved);

	if(info != NULL) {
		info->si_signo = sig;
		info->si_errno = 0;
		info->si_code  = SI_USER;
	}
	return sig;
}

int
sigqueue(pid_t pid, int signo, const union sigval value)
{
	(void)value;
	return kill(pid, signo);
}
