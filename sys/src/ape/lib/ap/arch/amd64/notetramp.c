#include "../../include/lib.h"
#include "../../include/sys9.h"
#include <signal.h>
#include <setjmp.h>
#include <string.h>
#include <stdlib.h>

/* A stack to hold pcs when signals nest */
#define MAXSIGSTACK 20
typedef struct Pcstack Pcstack;
static struct Pcstack {
	int sig;
	char *msg;
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
		_NOTED(1);
	p = &pcstack[nstack];
	p->restorepc = u->pc;
	p->sig = sig;
	p->hdlr = hdlr;
	p->u = u;
	p->msg = "signal";
	nstack++;
	
	u->pc = (unsigned long long) notecont;
	_NOTED(2);	/* NSAVE: capture state and clear note */
}

static void
notecont(Ureg *u, char *s)
{
	Pcstack *p;
	void(*f)(int, char*, Ureg*);

	p = &pcstack[nstack-1];
	f = p->hdlr;
	u->pc = p->restorepc;
	(*f)(p->sig, p->msg, u);
	nstack--;
	_NOTED(3);	/* NRSTR */
}

int
_ape_notehandler(Ureg *u, char *msg)
{
	extern void (*_sighdlr[])(int, char*, Ureg*);
	extern int _stringsig(char*);
	int sig;
	void (*f)(int, char*, Ureg*);

	sig = _stringsig(msg);
	if(sig > 0){
		f = _sighdlr[sig];
		if(f != SIG_DFL && f != SIG_IGN && f != SIG_ERR){
			pcstack[nstack].msg = msg;
			_notetramp(sig, f, u);
		}
		_NOTED(0);	/* NCONT */
		return 0;
	}
	_NOTED(1);	/* NDFLT */
	return 0;
}

extern sigset_t	_psigblocked;

/* Layout must match sigsetjmp in setjmp.s */
typedef struct {
	unsigned long long set;
	unsigned long long blocked;
	unsigned long long jmpbuf[8];
} sigjmp_buf_amd64;

void
siglongjmp(sigjmp_buf j, int ret)
{
	sigjmp_buf_amd64 *jb = (sigjmp_buf_amd64*)j;
	Ureg *u;

	if(jb->set & 0xFFFFFFFF){
		_psigblocked = jb->blocked;
	}

	if(nstack > 0){
		u = pcstack[nstack-1].u;
		/* If target SP is above signal SP, we can use NRSTR */
		if(jb->jmpbuf[0] >= u->sp){
			nstack--;
			u->ax = (ret == 0) ? 1 : ret;
			u->pc = jb->jmpbuf[1];
			u->sp = jb->jmpbuf[0];
			_NOTED(3);	/* NRSTR */
		}
	}

	longjmp((void*)jb->jmpbuf, ret);
}
