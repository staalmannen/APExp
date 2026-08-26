#include <signal.h>
#include <errno.h>

/*
 * sigsets are longs.  The signal #define'd as i in signal.h is in the
 * set when bit i+1 is on, i.e. BITSIG(i).  Signals run 1..NSIG-1, so the
 * top bit used is NSIG, 28, which fits a 32-bit long with room to spare.
 *
 * The set of signals these calls accept used to be
 *
 *	static sigset_t stdsigs = SIGHUP|SIGINT|SIGQUIT|...|SIGUSR2;
 *
 * which ORs the signal NUMBERS together rather than their bits: 1|2|3|
 * 4|5|6|7|8|9|10|11|12|13 is 15.  Every one of these functions then
 * tested BITSIG(signo) against that, so only signals whose bit landed
 * inside 0xf were accepted -- signals 0, 1 and 2 -- and sigaddset() of
 * anything else returned -1/EINVAL.  sigfillset() filled in 15, a set
 * naming SIGHUP and SIGINT and nothing else.
 *
 * That was quiet, because almost nothing checks sigaddset's return
 * value: the caller got an empty set and blocked or defaulted no
 * signals at all.  Found through posix_spawnattr_setsigdefault, whose
 * test built a set containing SIGTERM (11) and got back a set
 * containing nothing.
 *
 * Every signal in signal.h is now accepted.  There is no reason to
 * refuse the ones Plan 9 cannot deliver -- POSIX only requires that the
 * names exist, and a program that puts SIGCHLD in a mask and gets
 * EINVAL is worse off than one whose mask simply never fires.
 *
 * _psigblocked, the only sigset the rest of libap keeps, is just saved
 * and restored (sigprocmask, notetramp) and never tested a signal
 * against, so no stored set changes meaning here.
 */

#define BITSIG(s)	(2<<(s))

static int
badsig(int signo)
{
	if(signo <= 0 || signo >= NSIG){
		errno = EINVAL;
		return 1;
	}
	return 0;
}

int
sigemptyset(sigset_t *set)
{
	*set = 0;
	return 0;
}

int
sigfillset(sigset_t *set)
{
	sigset_t s;
	int i;

	s = 0;
	for(i = 1; i < NSIG; i++)
		s |= BITSIG(i);
	*set = s;
	return 0;
}

int
sigaddset(sigset_t *set, int signo)
{
	if(badsig(signo))
		return -1;
	*set |= BITSIG(signo);
	return 0;
}

int
sigdelset(sigset_t *set, int signo)
{
	if(badsig(signo))
		return -1;
	*set &= ~BITSIG(signo);
	return 0;
}

int
sigismember(const sigset_t *set, int signo)
{
	if(badsig(signo))
		return -1;
	return (*set & BITSIG(signo)) ? 1 : 0;
}
