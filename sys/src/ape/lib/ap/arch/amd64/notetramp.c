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
 * with stack layout: [sp+0]=0 (retPC), [sp+8]=nureg*, [sp+16]=msg*.
 * RARG (BP) also = nureg*.
 *
 * APExp's 6c convention: first arg in RARG, second arg at 0(FP)=8(SP).
 * The kernel puts msg at [sp+16]=8(FP), but 6c expects it at 0(FP)=8(SP).
 * The _notehandler assembly stub in setjmp.s fixes this up before calling
 * _ape_notehandler here.
 *
 * After _notetramp calls _NOTED(NSAVE), the kernel redirects execution to
 * notecont at the same stack level (sp_nsave == sp_notify), reusing the
 * same argument layout, so notecont also receives (Ureg *u, char *s).
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
 * Receives the same (Ureg*, char*) arguments as _notehandler because
 * the kernel's NSAVE reuses the notify() stack frame (sp_nsave == sp_notify).
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
 * _ape_notehandler — called from the _notehandler assembly wrapper in setjmp.s.
 * The assembly wrapper fixes up the calling convention (moves msg from [sp+16]
 * to 0(SP) before CALL) so this C function receives (Ureg *u, char *msg)
 * correctly per APExp's 6c convention (RARG=u, msg at 0(FP)).
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
 *  [32]  jmpbuf[2] = BP
 *  [40]  jmpbuf[3] = BX
 *  [48]  jmpbuf[4] = R12
 *  [56]  jmpbuf[5] = R13
 *  [64]  jmpbuf[6] = R14
 *  [72]  jmpbuf[7] = R15
 */
typedef struct {
	unsigned long long	set;
	unsigned long long	blocked;
	unsigned long long	jmpbuf[8];
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
		 * atomically.  This avoids any write near USTKTOP.
		 */
		u = pcstack[nstack-1].u;
		nstack--;
		u->ax  = (ret == 0) ? 1 : ret;
		u->pc  = jb->jmpbuf[1];
		u->sp  = jb->jmpbuf[0] + 8;	/* skip return-address slot */
		u->bp  = jb->jmpbuf[2];
		u->bx  = jb->jmpbuf[3];
		u->r12 = jb->jmpbuf[4];
		u->r13 = jb->jmpbuf[5];
		u->r14 = jb->jmpbuf[6];
		u->r15 = jb->jmpbuf[7];
		_NOTED(3);			/* NRSTR */
		/* NRSTR does not return */
	}

	/* Outside signal handler: ordinary longjmp restores all regs */
	longjmp((void*)jb->jmpbuf, ret);
}
