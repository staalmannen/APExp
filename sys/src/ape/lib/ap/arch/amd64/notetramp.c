#include "../../include/lib.h"
#include "../../include/sys9.h"
#include <signal.h>
#include <setjmp.h>
#include <string.h>

/* A stack to hold pcs when signals nest */
#define MAXSIGSTACK 20
typedef struct Pcstack Pcstack;
static struct Pcstack {
	int sig;
	void (*hdlr)(int, char*, Ureg*);
	unsigned long long restorepc;
	Ureg *u;
	char msg[ERRMAX];
} pcstack[MAXSIGSTACK];
static int nstack = 0;

static void notecont(void);

void
_notetramp(int sig, void (*hdlr)(int, char*, Ureg*), Ureg *u, char *msg)
{
	Pcstack *p;

	if(nstack >= MAXSIGSTACK)
		_NOTED(1);	/* nesting too deep; just do system default */
	p = &pcstack[nstack];
	p->restorepc = u->pc;
	p->sig = sig;
	p->hdlr = hdlr;
	p->u = u;
	if(msg)
		strncpy(p->msg, msg, ERRMAX-1);
	else
		p->msg[0] = '\0';
	nstack++;
	u->pc = (unsigned long long) notecont;
	_NOTED(2);	/* NSAVE: clear note but hold state */
}

static void
notecont(void)
{
	Pcstack *p;
	void (*f)(int, char*, Ureg*);
	Ureg *u;

	p = &pcstack[nstack-1];
	f = p->hdlr;
	u = p->u;
	u->pc = p->restorepc;
	nstack--;
	(*f)(p->sig, p->msg, u);
	_NOTED(3);	/* NRSTR */
}

#define JMPBUFPC 1
#define JMPBUFSP 0

extern sigset_t	_psigblocked;

/*
 * sigjmp_buf layout — must match sigsetjmp in setjmp.s:
 *   [0]  set       — savemask flag (low 32 bits; upper 32 undefined)
 *   [8]  blocked   — _psigblocked VALUE (8 bytes)
 *  [16]  jmpbuf[0] = SP
 *  [24]  jmpbuf[1] = PC
 *  [32]  jmpbuf[2] = BP
 *  [40]  jmpbuf[3] = BX
 *  [48]  jmpbuf[4] = R12
 *  [56]  jmpbuf[5] = R13
 *  [64]  jmpbuf[6] = R14
 *  [72]  jmpbuf[7] = R15  (REGEXT global-register cache)
 */
typedef struct {
	unsigned long long	set;
	unsigned long long	blocked;
	unsigned long long	jmpbuf[8];
} sigjmp_buf_amd64;

void
siglongjmp(sigjmp_buf j, int ret)
{
	sigjmp_buf_amd64 *jb;

	jb = (sigjmp_buf_amd64*)j;

	if(jb->set & 0xFFFFFFFF)
		_psigblocked = jb->blocked;

	/*
	 * If we are jumping "out" of one or more signal handlers,
	 * we must pop the corresponding pcstack entries.
	 */
	while(nstack > 0 && pcstack[nstack-1].u->sp < jb->jmpbuf[JMPBUFSP])
		nstack--;

	/*
	 * NUCLEAR OPTION: Bypassing the NRSTR (noted(3)) path.
	 * 
	 * Previous implementations tried to write the target state back into
	 * the kernel's Ureg structure.  However, if the signal arrived when
	 * the stack was near the boundary (0x7ffffffff000), writing to high
	 * offsets in the Ureg triggered a suicide trap.
	 *
	 * Since we have already called NSAVE (_NOTED(2)) in _notetramp, the 
	 * kernel has cleared the note and is simply holding the process state.
	 * We can safely use longjmp() to restore the CPU context and resume
	 * execution in user space.  The kernel will notice the process is
	 * active again and deliver subsequent signals normally.
	 */
	longjmp((void*)jb->jmpbuf, ret);
}
