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

static void notecont(void);

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
	/* Preserve u in RARG (R15) for resumption */
	u->r15 = (unsigned long long)u;
	_NOTED(2);	/* NSAVE */
}

static void
notecont(void)
{
	Pcstack *p;
	void(*f)(int, char*, Ureg*);

	if(nstack <= 0)
		_EXITS("notecont: nstack <= 0");

	p = &pcstack[nstack-1];
	p->u->pc = p->restorepc;
	f = p->hdlr;
	(*f)(p->sig, p->msg, p->u);
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
		_NOTED(0); /* NCONT */
	}
	_NOTED(1); /* NDFLT */
	return 0;
}

extern sigset_t	_psigblocked;

/* Layout must match sigsetjmp in setjmp.s (offset 16) */
typedef struct {
	unsigned long long set;
	unsigned long long blocked;
	unsigned long long jmpbuf[8]; /* SP, PC, BP, BX, R12, R13, R14, R15 */
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
		nstack--;
		
		/* 
		 * Synchronize all General Purpose registers into the Ureg 
		 * before restoration to ensure a consistent context.
		 */
		u->ax = (ret == 0) ? 1 : ret;
		u->pc = jb->jmpbuf[1];
		u->sp = jb->jmpbuf[0] + 8;
		u->bp = jb->jmpbuf[2];
		u->bx = jb->jmpbuf[3];
		u->r12 = jb->jmpbuf[4];
		u->r13 = jb->jmpbuf[5];
		u->r14 = jb->jmpbuf[6];
		u->r15 = jb->jmpbuf[7];
		
		_NOTED(3); /* NRSTR */
	}

	longjmp((void*)jb->jmpbuf, ret);
}
