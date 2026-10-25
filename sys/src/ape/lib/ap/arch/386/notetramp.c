/*
 * `../../include/', not `../plan9/'.  Every other architecture's
 * notetramp.c -- all nine of them -- spells it the first way, and
 * `plan9/' has not been a sibling of `arch/' since libap was
 * reorganised to mirror musl's layout.  386 kept the old spelling and
 * nothing noticed, because nothing had built 386 since.
 *
 * It surfaced as the FIRST error of `objtype=386 mk install' after the
 * compiler was fixed:
 *
 *	cpp: notetramp.c:1 Could not find include file "../plan9/lib.h"
 *
 * The form here appears 26 times across the other architectures and
 * twice in the stale spelling; a sweep of the whole of `lib/ap' finds
 * no other `../plan9/' include.
 */
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
	unsigned long restorepc;
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
	u->pc = (unsigned long) notecont;
	_NOTED(2);	/* NSAVE: clear note but hold state */
}

static void
notecont(void)
{
	Pcstack *p;
	void(*f)(int, char*, Ureg*);
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

void
siglongjmp(sigjmp_buf j, int ret)
{
	struct Ureg *u;

	if(j[0])
		_psigblocked = j[1];
	if(nstack == 0 || pcstack[nstack-1].u->sp > j[2+JMPBUFSP])
		longjmp(j+2, ret);
	u = pcstack[nstack-1].u;
	nstack--;
	u->ax = ret;
	if(ret == 0)
		u->ax = 1;
	u->pc = j[2+JMPBUFPC];
	u->sp = j[2+JMPBUFSP] + 4;
	_NOTED(3);	/* NRSTR */
}
