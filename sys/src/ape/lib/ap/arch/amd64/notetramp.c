#include "../../include/lib.h"
#include "../../include/sys9.h"
#include <signal.h>
#include <setjmp.h>
#include <string.h>
#include <stdlib.h>

/*
 * Plan 9 amd64 note (signal) trampoline.
 *
 * The kernel delivers notes by calling the handler registered via _NOTIFY()
 * with: RARG=nureg*, [sp+0]=0 (retPC), [sp+8]=nureg*, [sp+16]=msg*.
 *
 * The _notehandler assembly stub in setjmp.s fixes up the calling convention
 * before calling _ape_notehandler here (moves msg from [sp+16] to 0(FP)).
 *
 * After _notetramp calls _NOTED(NSAVE), the kernel redirects execution to
 * notecont at the same stack level, reusing the notify stack layout.
 * notecont ignores its second argument (nureg at 0(FP)) and uses p->msg
 * which was saved by _ape_notehandler before calling _notetramp.
 *
 * Key invariant: nstack is decremented AFTER the signal handler returns,
 * so siglongjmp sees nstack>0 and takes the NRSTR path (not longjmp).
 */

#define MAXSIGSTACK 20
typedef struct Pcstack Pcstack;
static struct Pcstack {
	int		sig;
	char		*msg;
	void		(*hdlr)(int, char*, Ureg*);
	unsigned long long restorepc;
	Ureg		*u;
} pcstack[MAXSIGSTACK];
static int nstack = 0;

static void notecont(Ureg*, char*);

void
_notetramp(int sig, void (*hdlr)(int, char*, Ureg*), Ureg *u)
{
	Pcstack *p;

	if(nstack >= MAXSIGSTACK)
		_NOTED(1);	/* nesting too deep; use system default */
	p = &pcstack[nstack];
	p->restorepc = u->pc;
	p->sig = sig;
	p->hdlr = hdlr;
	p->u = u;
	nstack++;

	u->pc = (unsigned long long) notecont;
	_NOTED(2);		/* NSAVE: hold state, redirect to notecont */
	/* NSAVE does not return here — process jumps to notecont */
}

/*
 * notecont — called by the kernel after NSAVE redirects execution.
 * Receives the same delivery layout as the original notify handler.
 * In APExp convention the second arg (0(FP)=[sp+8]) is nureg, not msg;
 * we ignore it and use p->msg stored by _ape_notehandler instead.
 */
static void
notecont(Ureg *u, char *s)
{
	Pcstack *p;
	void (*f)(int, char*, Ureg*);

	if(nstack <= 0)
		_EXITS("notecont: nstack <= 0");

	p = &pcstack[nstack-1];
	u->pc = p->restorepc;		/* restore original interrupted PC */
	f = p->hdlr;
	(*f)(p->sig, p->msg, u);	/* call the POSIX signal handler */
	nstack--;
	_NOTED(3);			/* NRSTR: restore interrupted state */
}

extern void (*_sighdlr[])(int, char*, Ureg*);

/*
 * _ape_notehandler — called from the _notehandler assembly stub in setjmp.s.
 * The stub moves msg from [sp+16] to 0(FP) so this C function receives
 * (Ureg *u, char *msg) correctly per APExp's 6c convention.
 */
int
_ape_notehandler(Ureg *u, char *msg)
{
	int sig;
	void (*f)(int, char*, Ureg*);
	extern int _stringsig(char*);

	sig = _stringsig(msg);
	if(sig > 0){
		f = _sighdlr[sig];
		if(f != SIG_DFL && f != SIG_IGN && f != SIG_ERR){
			pcstack[nstack].msg = msg;
			_notetramp(sig, f, u);
			/* _notetramp calls _NOTED(NSAVE) which redirects to
			 * notecont; execution never returns here */
		}
		if(f == SIG_IGN){
			_NOTED(0);	/* NCONT: continue, ignore signal */
			return 0;
		}
	}
	/* SIG_DFL, SIG_ERR, or unrecognised note: use kernel default action */
	_NOTED(1);			/* NDFLT: terminate */
	return 0;
}

extern sigset_t _psigblocked;

/*
 * sigjmp_buf layout — must match sigsetjmp in setjmp.s:
 *   [0]  set     — savemask flag (non-zero if signal mask should be restored)
 *   [8]  blocked — saved _psigblocked value
 *  [16]  jmpbuf[0] = SP
 *  [24]  jmpbuf[1] = PC (return address of sigsetjmp)
 */
typedef struct {
	unsigned long long	set;
	unsigned long long	blocked;
	unsigned long long	jmpbuf[2];
} sigjmp_buf_amd64;

void
siglongjmp(sigjmp_buf j, int ret)
{
	sigjmp_buf_amd64 *jb = (sigjmp_buf_amd64*)j;
	Ureg *u;

	if(jb->set & 0xFFFFFFFF)
		_psigblocked = jb->blocked;

	if(nstack > 0){
		/*
		 * Called from within a signal handler (notecont context).
		 * Patch the saved Ureg (nureg) to point at the sigsetjmp
		 * return state, then use NRSTR to have the kernel restore it
		 * atomically.
		 */
		u = pcstack[nstack-1].u;
		nstack--;
		u->ax = (ret == 0) ? 1 : ret;
		u->pc = jb->jmpbuf[1];
		u->sp = jb->jmpbuf[0] + 8;	/* skip return-address slot */
		_NOTED(3);			/* NRSTR — does not return */
	}

	/* Outside signal handler: ordinary longjmp restores SP and PC */
	longjmp((void*)jb->jmpbuf, ret);
}
