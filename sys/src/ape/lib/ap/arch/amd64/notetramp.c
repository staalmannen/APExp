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

	dbg("notecont: u=            ", (unsigned long long)u);
	dbg("notecont: u->sp=        ", u->sp);
	dbg("notecont: u->pc=        ", u->pc);
	p = &pcstack[nstack-1];
	f = p->hdlr;
	u->pc = p->restorepc;
	/*
	 * Do NOT decrement nstack before calling f.  If the handler calls
	 * siglongjmp, siglongjmp needs nstack > 0 so it can take the
	 * _NOTED(3) (NRSTR) path rather than calling longjmp().  The longjmp
	 * path on amd64 crashes because the kernel-delivered context has
	 * SP near USTKTOP, outside the mapped stack.  siglongjmp decrements
	 * nstack itself in the NRSTR path.  If the handler returns normally
	 * (no longjmp), we decrement nstack here and fall through to NRSTR.
	 */
	(*f)(p->sig, s, u);
	nstack--;
	_NOTED(3);	/* NRSTR */
}

#define JMPBUFPC 1
#define JMPBUFSP 0

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
	sigjmp_buf_amd64 *jb;

	jb = (sigjmp_buf_amd64*)j;

	if(jb->set & 0xFFFFFFFF){
		_psigblocked = jb->blocked;
	}

	/*
	 * If we're not in a signal handler (nstack == 0),
	 * or we're jumping to a frame that was active AFTER the last signal
	 * happened (which shouldn't happen but if it did), use normal longjmp.
	 *
	 * A signal context u->sp is the stack pointer when the signal occurred.
	 * The target frame's SP is jb->jmpbuf[SP].
	 * Since stack grows down, the signal frame (happened later) must have
	 * u->sp <= jb->jmpbuf[SP].
	 */
	if(nstack == 0 || pcstack[nstack-1].u->sp > jb->jmpbuf[JMPBUFSP]){
		/* adjust SP for longjmp because it expects SP pointing to return PC */
		unsigned long long *sp = (void*)jb->jmpbuf[JMPBUFSP];
		sp[0] = jb->jmpbuf[JMPBUFPC];
		longjmp((void*)jb->jmpbuf, ret);
	}

	u = pcstack[nstack-1].u;
	nstack--;
	u->ax = ret;
	if(ret == 0)
		u->ax = 1;
	u->pc = jb->jmpbuf[JMPBUFPC];
	u->sp = jb->jmpbuf[JMPBUFSP] + 8;
	_NOTED(3);	/* NRSTR */
}
