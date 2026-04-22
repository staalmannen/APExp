#include "../include/lib.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 * SA_SIGINFO trampoline: stores per-signal sa_sigaction handlers and
 * calls them with a zero-filled siginfo_t, since Plan 9 has no siginfo.
 */
static void (*siginfo_handlers[NSIG])(int, siginfo_t *, void *);
static siginfo_t zero_siginfo;

static void
siginfo_trampoline(int sig)
{
	if(sig >= 0 && sig < NSIG && siginfo_handlers[sig] != NULL)
		siginfo_handlers[sig](sig, &zero_siginfo, NULL);
}

/*
 * sigaction - examine and change signal action
 *
 * Plan9 APE has signal() but not sigaction(). We implement sigaction()
 * as a wrapper over signal(), handling the most common usage patterns.
 * SA_RESTART, SA_RESETHAND and sigaction's sa_mask are silently ignored
 * since Plan9's signal model has no direct equivalent.
 *
 * SA_SIGINFO: installs sa_sigaction via a trampoline; the siginfo_t
 * passed to the handler is always zero (Plan 9 doesn't provide it).
 */
int
sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
{
	void (*old)(void);

	if(signum <= 0 || signum >= NSIG){
		errno = EINVAL;
		return -1;
	}

	if(act == NULL){
		if(oldact != NULL){
			memset(oldact, 0, sizeof *oldact);
			oldact->sa_handler = SIG_DFL;
		}
		return 0;
	}

	if(act->sa_flags & SA_SIGINFO){
		siginfo_handlers[signum] = act->sa_sigaction;
		old = (void(*)(void))signal(signum, (void(*)())siginfo_trampoline);
	} else {
		siginfo_handlers[signum] = NULL;
		old = (void(*)(void))signal(signum, (void(*)())act->sa_handler);
	}

	if(oldact != NULL){
		memset(oldact, 0, sizeof *oldact);
		oldact->sa_handler = (void(*)())old;
	}
	return 0;
}

/*
 * psignal - print signal description to stderr
 */
void
psignal(int signum, const char *s)
{
	const char *desc = strsignal(signum);
	if(s != NULL && *s != '\0')
		fprintf(stderr, "%s: %s\n", s, desc);
	else
		fprintf(stderr, "%s\n", desc);
}
