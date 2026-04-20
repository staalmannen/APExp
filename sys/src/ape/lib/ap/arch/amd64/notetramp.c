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
	void (*f)(int, char*, Ureg*);

	p = &pcstack[nstack-1];
	f = p->hdlr;
	u->pc = p->restorepc;
	(*f)(p->sig, s, u);
	/*
	 * Decrement AFTER handler returns so that siglongjmp called from
	 * inside the handler sees nstack>0 and takes the NRSTR path instead
	 * of falling through to longjmp (which would crash near USTKTOP).
	 */
	nstack--;
	_NOTED(3);	/* NRSTR */
}

#define JMPBUFPC 1
#define JMPBUFSP 0

extern sigset_t	_psigblocked;

/*
 * sigjmp_buf layout — must match sigsetjmp in setjmp.s:
 *   [0]  set     — savemask flag (low 32 bits; upper 32 undefined)
 *   [8]  blocked — _psigblocked VALUE (8 bytes; upstream stored address in 4 bytes)
 *  [16]  jmpbuf[0] = SP
 *  [24]  jmpbuf[1] = PC
 */
typedef struct {
	unsigned long long	set;
	unsigned long long	blocked;
	unsigned long long	jmpbuf[2];
} sigjmp_buf_amd64;

void
siglongjmp(sigjmp_buf j, int ret)
{
	struct Ureg *u;
	sigjmp_buf_amd64 *jb;

	jb = (sigjmp_buf_amd64*)j;

	if(jb->set & 0xFFFFFFFF)
		_psigblocked = jb->blocked;
	if(nstack == 0 || pcstack[nstack-1].u->sp > jb->jmpbuf[JMPBUFSP])
		longjmp((void*)jb->jmpbuf, ret);
	u = pcstack[nstack-1].u;
	nstack--;
	u->ax = ret;
	if(ret == 0)
		u->ax = 1;
	u->pc = jb->jmpbuf[JMPBUFPC];
	u->sp = jb->jmpbuf[JMPBUFSP] + 8;
	_NOTED(3);	/* NRSTR */
}
