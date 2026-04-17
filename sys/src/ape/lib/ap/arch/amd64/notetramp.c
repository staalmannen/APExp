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
	void (*hdlr)(int, char*, Ureg*);
	unsigned long long restorepc;
	Ureg *u;
} pcstack[MAXSIGSTACK];
static int nstack = 0;

void
_notetramp(int sig, void (*hdlr)(int, char*, Ureg*), Ureg *u)
{
	Pcstack *p;
	extern void _notecont_trampoline(void);

	if(nstack >= MAXSIGSTACK)
		_NOTED(1);
	p = &pcstack[nstack];
	p->restorepc = u->pc;
	p->sig = sig;
	p->hdlr = hdlr;
	p->u = u;
	nstack++;
	u->pc = (unsigned long long) _notecont_trampoline;
	_NOTED(2);	/* NSAVE */
}

void
notecont(Ureg *u, char *s)
{
	Pcstack *p;
	void(*f)(int, char*, Ureg*);

	p = &pcstack[nstack-1];
	f = p->hdlr;
	u->pc = p->restorepc;
	(*f)(p->sig, s, u);
	nstack--;
	
	/* Return to kernel via NRSTR to restore original context */
	_NOTED(3);
}

/*
 * _ape_notehandler is called by the assembly trampoline _notehandler.
 * u is in RARG, msg is at 8(FP).
 */
static struct {
	char	*msg;
	int	num;
} sigtab[] = {
	{"hangup",				SIGHUP},
	{"interrupt",				SIGINT},
	{"quit",				SIGQUIT},
	{"alarm",				SIGALRM},
	{"sys: trap: illegal instruction",	SIGILL},
	{"sys: trap: arithmetic overflow",	SIGFPE},
	{"sys: fp:",				SIGFPE},
	{"sys: trap: bus error",		SIGSEGV},
	{"sys: trap: address error",		SIGSEGV},
	{"sys: write on closed pipe",		SIGPIPE},
	{"term",				SIGTERM},
	{"usr1",				SIGUSR1},
	{"usr2",				SIGUSR2},
};

extern void (*_sighdlr[])(int, char*, Ureg*);

int
_ape_notehandler(Ureg *u, char *msg)
{
	int i;
	void (*f)(int, char*, Ureg*);

	for(i = 0; i < sizeof(sigtab)/sizeof(sigtab[0]); i++){
		if(strncmp(msg, sigtab[i].msg, strlen(sigtab[i].msg)) == 0){
			f = _sighdlr[sigtab[i].num];
			if(f != SIG_DFL && f != SIG_IGN && f != SIG_ERR){
				_notetramp(sigtab[i].num, f, u);
			}
			_NOTED(0);
			return 0;
		}
	}
	_NOTED(1);
	return 0;
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
		unsigned long long *sp = (void*)jb->jmpbuf[0];
		sp[0] = jb->jmpbuf[1];
		longjmp((void*)jb->jmpbuf, ret);
	}

	u = pcstack[nstack-1].u;
	nstack--;

	u->ax = (ret == 0) ? 1 : ret;
	u->pc = jb->jmpbuf[1];
	u->sp = jb->jmpbuf[0] + 8;

	_NOTED(3);	/* NRSTR */
	_EXITS("siglongjmp failed");
}
