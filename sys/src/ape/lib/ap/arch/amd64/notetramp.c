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

/* Write a label + hex value to stderr, safe to call from signal context */
static void
dbg(const char *label, unsigned long long val)
{
	int n;
	char buf[19];
	int i;
	unsigned long long v;

	for(n = 0; label[n]; n++)
		;
	_WRITE(2, label, n);

	/* 0xHHHHHHHHHHHHHHHH\n — 19 bytes */
	v = val;
	buf[0] = '0';
	buf[1] = 'x';
	buf[18] = '\n';
	for(i = 17; i >= 2; i--){
		buf[i] = "0123456789abcdef"[v & 0xf];
		v >>= 4;
	}
	_WRITE(2, buf, 19);
}

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

	if(nstack == 0 || pcstack[nstack-1].u->sp > jb->jmpbuf[0]){
		/* adjust SP for longjmp because it expects SP pointing to return PC */
		unsigned long long *sp = (void*)jb->jmpbuf[0];
		sp[0] = jb->jmpbuf[1];
		longjmp((void*)jb->jmpbuf, ret);
	}

	u = pcstack[nstack-1].u;
	nstack--;

	dbg("siglongjmp: u=         ", (unsigned long long)u);
	dbg("siglongjmp: target pc= ", jb->jmpbuf[1]);
	dbg("siglongjmp: target sp= ", jb->jmpbuf[0]);

	u->ax = (ret == 0) ? 1 : ret;
	u->pc = jb->jmpbuf[1];
	u->sp = jb->jmpbuf[0] + 8;
	_NOTED(3);	/* NRSTR */
	
	/* If _NOTED returns, it failed */
	_EXITS("siglongjmp failed");
}
