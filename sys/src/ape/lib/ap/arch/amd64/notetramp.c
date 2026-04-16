#include "../../include/lib.h"
#include "../../include/sys9.h"
#include <signal.h>
#include <setjmp.h>

/* A stack to hold pcs when signals nest */
#define MAXSIGSTACK 20
typedef struct Pcstack Pcstack;
static struct Pcstack {
	int sig;
	void (*hdlr)(int, char*, Ureg*);
	unsigned long long restorepc;
	Ureg *u;
} pcstack[MAXSIGSTACK];
static int nstack = 0;

static void notecont(Ureg*, char*);

void
_notetramp(int sig, void (*hdlr)(int, char*, Ureg*), Ureg *u)
{
	Pcstack *p;

	if(nstack >= MAXSIGSTACK)
		_NOTED(1);	/* nesting too deep; just do system default */
	p = &pcstack[nstack];
	p->restorepc = u->pc;
	p->sig = sig;
	p->hdlr = hdlr;
	p->u = u;
	nstack++;
	u->pc = (unsigned long long) notecont;
	_NOTED(2);	/* NSAVE: clear note but hold state */
}

static void
notecont(Ureg *u, char *s)
{
	Pcstack *p;
	void(*f)(int, char*, Ureg*);

	p = &pcstack[nstack-1];
	f = p->hdlr;
	u->pc = p->restorepc;
	/*
	 * Handler is called with nstack including this frame so that
	 * siglongjmp knows we are in a signal context.
	 */
	(*f)(p->sig, s, u);
	nstack--;
	_NOTED(3);	/* NRSTR */
}

extern sigset_t	_psigblocked;

/* Layout must match sigsetjmp in setjmp.s */
typedef struct {
	unsigned long long set;
	unsigned long long blocked;
	unsigned long long jmpbuf[2];
} sigjmp_buf_amd64;

void
siglongjmp(sigjmp_buf j, int ret)
{
	struct Ureg *u;
	sigjmp_buf_amd64 *jb = (sigjmp_buf_amd64*)j;

	if(jb->set & 0xFFFFFFFF){
		_psigblocked = jb->blocked;
	}

	/* 
	 * If not in signal handler, or jumping to a frame that was 
	 * active after the signal, use normal longjmp.
	 */
	if(nstack == 0 || pcstack[nstack-1].u->sp > jb->jmpbuf[0]){
		longjmp((void*)jb->jmpbuf, ret);
	}

	/* kernel-restore path (NRSTR) */
	u = pcstack[nstack-1].u;
	nstack--;
	
	/* 
	 * Use the exact SP saved by setjmp. 
	 * Since u->pc is the return address, having u->sp point 
	 * to that return address is consistent.
	 */
	unsigned long long target_sp = jb->jmpbuf[0];
	
	extern void _notejmp(Ureg*, int, unsigned long long, unsigned long long);
	_notejmp(u, (ret == 0) ? 1 : ret, jb->jmpbuf[1], target_sp);
}
