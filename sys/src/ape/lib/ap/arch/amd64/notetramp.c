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

/*
 * _notetramp is called by the signal dispatcher.
 * The standard Plan 9 signature is (Ureg *u, char *msg).
 * APE's signal.c wraps this to provide (int sig, void(*hdlr)(int, char*, Ureg*), Ureg *u).
 */
void
_notetramp(int sig, void (*hdlr)(int, char*, Ureg*), Ureg *u)
{
	Pcstack *p;

	if(nstack >= MAXSIGSTACK)
		_NOTED(1);
	p = &pcstack[nstack];
	p->restorepc = u->pc;
	p->sig = sig;
	p->hdlr = hdlr;
	p->u = u;
	nstack++;
	u->pc = (unsigned long long) notecont;
	_NOTED(2);	/* NSAVE */
}

static void
notecont(Ureg *u, char *s)
{
	Pcstack *p;
	void(*f)(int, char*, Ureg*);

	p = &pcstack[nstack-1];
	f = p->hdlr;
	u->pc = p->restorepc;
	(*f)(p->sig, s, u);
	nstack--;
	_NOTED(3);	/* NRSTR */
}

extern sigset_t	_psigblocked;

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
	 * If we're not in a signal handler, or jumping to a frame that was 
	 * active AFTER the signal, use normal longjmp.
	 */
	if(nstack == 0 || pcstack[nstack-1].u->sp > jb->jmpbuf[0]){
		longjmp((void*)jb->jmpbuf, ret);
	}

	u = pcstack[nstack-1].u;
	nstack--;

	u->ax = (ret == 0) ? 1 : ret;
	u->pc = jb->jmpbuf[1];
	u->sp = jb->jmpbuf[0];
	_NOTED(3);	/* NRSTR */
	_EXITS("siglongjmp failed");
}
