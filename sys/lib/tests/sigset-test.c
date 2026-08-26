/*
 * sigset-test.c -- sigemptyset/sigfillset/sigaddset/sigdelset/sigismember.
 *
 * libap's ap/signal/sigset.c had
 *
 *	static sigset_t stdsigs = SIGHUP|SIGINT|SIGQUIT|SIGILL|SIGABRT|
 *		SIGFPE|SIGKILL|SIGSEGV|SIGPIPE|SIGALRM|SIGTERM|
 *		SIGUSR1|SIGUSR2;
 *
 * which ORs the signal NUMBERS together rather than their bits, giving
 * 15. Every one of these functions then tested its signal's bit against
 * that, so only signals 0, 1 and 2 were accepted; sigaddset (SIGTERM)
 * returned -1/EINVAL and added nothing, and sigfillset() produced a set
 * naming SIGHUP and SIGINT alone.
 *
 * It was quiet because almost nothing checks sigaddset's return value:
 * the caller just got an empty mask and blocked nothing. Found through
 * posix_spawnattr_setsigdefault, whose test built a set holding SIGTERM
 * and got back a set holding nothing.
 *
 * Build and run:  pcc -o sigset-test sigset-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s%s%s\n", what, detail ? ": " : "",
		       detail ? detail : "");
		failures++;
	}
}

/* Signals every POSIX system has, spread across the range so that a
   mask that only covers the low bits cannot pass by accident. */
static const struct {
	int	sig;
	const char *name;
} sigs[] = {
	{ SIGHUP,  "SIGHUP"  },
	{ SIGINT,  "SIGINT"  },
	{ SIGQUIT, "SIGQUIT" },
	{ SIGILL,  "SIGILL"  },
	{ SIGABRT, "SIGABRT" },
	{ SIGFPE,  "SIGFPE"  },
	{ SIGKILL, "SIGKILL" },
	{ SIGSEGV, "SIGSEGV" },
	{ SIGPIPE, "SIGPIPE" },
	{ SIGALRM, "SIGALRM" },
	{ SIGTERM, "SIGTERM" },
	{ SIGUSR1, "SIGUSR1" },
	{ SIGUSR2, "SIGUSR2" },
	{ SIGCHLD, "SIGCHLD" },
	{ SIGCONT, "SIGCONT" },
	{ SIGSTOP, "SIGSTOP" },
	{ SIGTSTP, "SIGTSTP" },
	{ SIGTTIN, "SIGTTIN" },
	{ SIGTTOU, "SIGTTOU" },
};
#define NSIGS ((int)(sizeof sigs / sizeof sigs[0]))

int
main(void)
{
	sigset_t set;
	char detail[128];
	int i, bad;

	/* Every one of them must be addable, then reported present. */
	bad = -1;
	sigemptyset(&set);
	for (i = 0; i < NSIGS; i++)
		if (sigaddset(&set, sigs[i].sig) != 0) {
			bad = i;
			break;
		}
	if (bad >= 0)
		sprintf(detail, "sigaddset(%s=%d) failed, errno %d",
		        sigs[bad].name, sigs[bad].sig, errno);
	check("sigaddset accepts every standard signal", bad < 0, detail);

	bad = -1;
	for (i = 0; i < NSIGS; i++)
		if (sigismember(&set, sigs[i].sig) != 1) {
			bad = i;
			break;
		}
	if (bad >= 0)
		sprintf(detail, "%s=%d is not in the set it was added to",
		        sigs[bad].name, sigs[bad].sig);
	check("sigismember finds every signal added", bad < 0, detail);

	/* Distinctness: deleting one must not disturb the others. This is
	   what catches an encoding where several signals share a bit. */
	sigdelset(&set, SIGTERM);
	check("sigdelset removes exactly one signal",
	      sigismember(&set, SIGTERM) == 0
	      && sigismember(&set, SIGINT) == 1
	      && sigismember(&set, SIGUSR1) == 1
	      && sigismember(&set, SIGCHLD) == 1, "neighbours changed too");

	/* An empty set holds nothing. */
	bad = -1;
	sigemptyset(&set);
	for (i = 0; i < NSIGS; i++)
		if (sigismember(&set, sigs[i].sig) != 0) {
			bad = i;
			break;
		}
	if (bad >= 0)
		sprintf(detail, "%s is in an empty set", sigs[bad].name);
	check("sigemptyset empties the set", bad < 0, detail);

	/* A full set holds everything. This was the most visible symptom:
	   sigfillset returned a set naming two signals. */
	bad = -1;
	sigfillset(&set);
	for (i = 0; i < NSIGS; i++)
		if (sigismember(&set, sigs[i].sig) != 1) {
			bad = i;
			break;
		}
	if (bad >= 0)
		sprintf(detail, "%s=%d missing from a full set",
		        sigs[bad].name, sigs[bad].sig);
	check("sigfillset fills the set", bad < 0, detail);

	/* Out-of-range signals are still refused. */
	sigemptyset(&set);
	errno = 0;
	check("sigaddset rejects signal 0",
	      sigaddset(&set, 0) == -1 && errno == EINVAL, "not EINVAL");
	errno = 0;
	check("sigaddset rejects a negative signal",
	      sigaddset(&set, -1) == -1 && errno == EINVAL, "not EINVAL");
	errno = 0;
	check("sigaddset rejects a signal above the range",
	      sigaddset(&set, 1000) == -1 && errno == EINVAL, "not EINVAL");

	/* sigprocmask round-trip: whatever the encoding, a mask set and
	   read back has to name the same signals. */
	{
		sigset_t old, got;

		sigemptyset(&set);
		sigaddset(&set, SIGTERM);
		sigaddset(&set, SIGUSR2);
		if (sigprocmask(SIG_SETMASK, &set, &old) == 0
		 && sigprocmask(SIG_SETMASK, &set, &got) == 0) {
			check("sigprocmask round-trips a mask",
			      sigismember(&got, SIGTERM) == 1
			      && sigismember(&got, SIGUSR2) == 1
			      && sigismember(&got, SIGINT) == 0,
			      "mask came back different");
			sigprocmask(SIG_SETMASK, &old, NULL);
		} else
			check("sigprocmask round-trips a mask", 0,
			      "sigprocmask failed");
	}

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
