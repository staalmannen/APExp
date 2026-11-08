#ifndef _npe_signal_h_
#define _npe_signal_h_

#include <npe.h>

enum {
	SA_RESETHAND = 1<<0, /* not used */

	/* all are treated as SIGSEGV */
	SIGINT = 2,
	SIGILL = 4,
	SIGABRT = 6,
	SIGFPE = 8,
	SIGSEGV = 11,
	SIGTERM = 15,
};

typedef u64int sigset_t;

typedef void (*sa_handler)(int);

struct sigaction {
	sa_handler sa_handler;
	int sa_flags;
	sigset_t sa_mask;
};

extern sa_handler SIG_DFL, SIG_IGN;

void sigaction(int, struct sigaction *, struct sigaction *);
int sigemptyset(sigset_t *set);

#endif
