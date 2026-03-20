#include "../plan9/lib.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 * sigaction - examine and change signal action
 *
 * Plan9 APE has signal() but not sigaction(). We implement sigaction()
 * as a wrapper over signal(), handling the most common usage patterns.
 * SA_RESTART, SA_RESETHAND and sigaction's sa_mask are silently ignored
 * since Plan9's signal model has no direct equivalent.
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
		/* query only */
		if(oldact != NULL){
			memset(oldact, 0, sizeof *oldact);
			/* we can't recover old handler without tracking it */
			oldact->sa_handler = SIG_DFL;
		}
		return 0;
	}

	old = (void(*)(void))signal(signum, (void(*)())act->sa_handler);

	if(oldact != NULL){
		memset(oldact, 0, sizeof *oldact);
		oldact->sa_handler = (void(*)())old;
	}
	return 0;
}

/*
 * psignal - print signal description to stderr
 * Equivalent to: fprintf(stderr, "%s: %s\n", s, strsignal(signum))
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
