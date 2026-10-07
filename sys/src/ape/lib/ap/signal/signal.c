#include "lib.h"
#include "sys9.h"
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <setjmp.h>

extern sigset_t	_psigblocked;

static struct {
	char	*msg;	/* just check prefix */
	int	num;
} sigtab[] = {
	{"hangup",				SIGHUP},
	{"interrupt",				SIGINT},
	{"quit",				SIGQUIT},
	{"alarm",				SIGALRM},
	{"sys: trap: illegal instruction",	SIGILL},
	{"sys: trap: reserved instruction",	SIGILL},
	{"sys: trap: reserved",			SIGILL},
	{"sys: trap: arithmetic overflow",	SIGFPE},
	{"abort",				SIGABRT},
	{"sys: fp:",				SIGFPE},
	{"exit",				SIGKILL},
	{"die",					SIGKILL},
	{"kill",				SIGKILL},
	{"sys: trap: bus error",		SIGSEGV},
	{"sys: trap: address error",		SIGSEGV},
	{"sys: trap: TLB",			SIGSEGV},
	{"sys: write on closed pipe",		SIGPIPE},
	{"term",				SIGTERM},
	{"usr1",				SIGUSR1},
	{"usr2",				SIGUSR2},
	{"virtual alarm",			SIGVTALRM},
	{"profiling alarm",			SIGPROF},
};
#define NSIGTAB ((sizeof sigtab)/(sizeof (sigtab[0])))

/*
 * `_sighdlr[]' HOLDS THE POSIX TYPE NOW, and the three-argument
 * Plan 9 form is reached by a cast at the ONE place that calls a
 * handler -- `_notetramp' below.
 *
 * It used to hold `void (*)(int, char*, Ureg*)' everywhere, which
 * made `<signal.h>' declare `signal()' with an EMPTY parameter list
 * so that an ordinary `void f(int)' could still be installed. That
 * turned off argument checking for every caller in the tree to keep
 * an extension reachable that nothing in the tree uses. The header
 * says `void (*)(int)' now; the extension is unchanged and still
 * dispatched, and a program that wants `msg' and `Ureg*' casts.
 *
 * Keeping the casts HERE rather than at each assignment is the half
 * that matters: `_envsetup.c' and `sigwait.c' store SIG_IGN and
 * saved handlers into this array, and every one of those would
 * otherwise need a cast of its own -- which is how a cast stops
 * being a note that something unusual is happening.
 */
void	(*_sighdlr[MAXSIG+1])(int);	/* 0 initialized: SIG_DFL */

void
(*signal(int sig, void (*func)(int)))(int)
{
	void(*oldf)(int);

	if(sig <= 0 || sig > MAXSIG){
		errno = EINVAL;
		return SIG_ERR;
	}
	oldf = _sighdlr[sig];
	if(sig == SIGKILL)
		return oldf;	/* can't catch or ignore SIGKILL */
	_sighdlr[sig] = func;
	return oldf;
}

/* BAD CODE - see /sys/src/ape/lib/ap/$objtype/setjmp.s for real code
int
sigsetjmp(sigjmp_buf buf, int savemask)
{
	int r;

	buf[0] = savemask;
	buf[1] = _psigblocked;
	return setjmp(&buf[2]);
}
*/

/*
 * Note: in APExp's 6c calling convention the second arg is at 0(FP)=[sp+8],
 * but the kernel delivers msg at [sp+16].  So 'msg' here actually receives
 * the nureg pointer, not the note string.  Any note will fail to match the
 * signal table and fall through to _NOTED(1) (terminate).  This is the same
 * behaviour as upstream 9front APE on APExp — harmless as long as notes are
 * not delivered during critical regions.  A proper fix requires an assembly
 * stub or a 3-arg declaration; left for a later pass.
 */
int
_notehandler(Ureg *u, char *msg)
{
	int i;
	void (*f)(int);
	extern void _doatexits(void);
	extern void _notetramp(int, void(*)(int, char*, Ureg*), Ureg*, char*);

	if(_finishing)
		_finish(0, 0);
	for(i = 0; i < NSIGTAB; i++){
		if(strncmp(msg, sigtab[i].msg, strlen(sigtab[i].msg)) == 0){
			f = _sighdlr[sigtab[i].num];
			if(f == SIG_DFL || f == SIG_ERR)
				break;
			if(f != SIG_IGN){
				/*
				 * THE CAST IS THE EXTENSION. `_notetramp'
				 * hands the handler (sig, msg, Ureg*); a
				 * handler declared `void f(int)' simply
				 * ignores the two it did not ask for, which
				 * is what every caller in this tree does.
				 */
				_notetramp(sigtab[i].num,
					(void(*)(int, char*, Ureg*))f, u, msg);
				/* _notetramp doesn't return */
			}
			_NOTED(0);	/* NCONT */
			return 0;
		}
	}
	_doatexits();
	_NOTED(1);	/* NDFLT */
	return 0;
}

int
_stringsig(char *nam)
{
	int i;

	for(i = 0; i<NSIGTAB; i++)
		if(strncmp(nam, sigtab[i].msg, strlen(sigtab[i].msg)) == 0)
			return sigtab[i].num;
	return 0;
}

char *
_sigstring(int sig)
{
	int i;

	for(i=0; i<NSIGTAB; i++)
		if(sigtab[i].num == sig)
			return sigtab[i].msg;
	return "unknown signal";
}
