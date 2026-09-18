#include "lib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "sys9.h"
#include "dir.h"

/*
 * Called before main to initialize environ.
 * Some plan9 environment variables
 * have 0 bytes in them (notably $path);
 * we change them to 1's (and execve changes back)
 *
 * Also, register the note handler.
 */

char **environ;
int *_errnoloc;
unsigned long _clock;
static void sigsetup(char *, char *);

enum {
	Envhunk=7000,
};

#pragma profile off

void
_envsetup(void)
{
	int dfd;
	int n, nd, m, i, j, f;
	int psize, cnt;
	int nohandle;
	int fdinited;
	char *ps, *p;
	char **pp;
	Dir *d9, *d9a;

	ps = 0;
	psize = 0;
	nohandle = 0;
	fdinited = 0;
	cnt = 0;
	dfd = _OPEN("/env", OREAD|OCEXEC);
	if(dfd < 0) {
		_fdinit(0, 0);
		goto done;
	}
	psize = Envhunk;
	ps = p = malloc(psize);
	nd = _dirreadall(dfd, &d9a);
	_CLOSE(dfd);
	for(j=0; j<nd; j++){
		d9 = &d9a[j];
		n = strlen(d9->name);
		m = d9->length;
		i = p - ps;
		if(i+n+5+m+1 > psize) {
			psize += (n+m+6 < Envhunk)? Envhunk : n+m+6;
			ps = realloc(ps, psize);
			p = ps + i;
		}
		memcpy(p, "/env/", 5);
		memcpy(p+5, d9->name, n+1);
		f = _OPEN(p, OREAD|OCEXEC);
		if(f < 0)
			continue;
		if(n > 3 && memcmp(d9->name, "fn#", 3)==0){
			if(m > 3
			&& _READ(f, p+3, m) == m
			&& memcmp(p+3, "fn ", 3) == 0
			&& memcmp(p+3+3, d9->name+3, n-3) == 0
			&& memchr(p+3+n, '{', m-n) != 0){
				memcpy(p, "#()", 3);
				p[3+m] = '\0';
				p += m+4;
				cnt++;
			}
			_CLOSE(f);
			continue;
		}
		memcpy(p, d9->name, n);
		p[n] = '=';
		if(_READ(f, p+n+1, m) != m)
			m = 0;
		_CLOSE(f);
		if(p[n+m]=='\0')
			m--;
		for(i=0; i<m; i++)
			if(p[n+1+i]=='\0')
				p[n+1+i] = '\1';
		p[n+1+m] = '\0';
		/*
		 * `_fdinfo` and `_sighdlr` ARE LIBAP'S OWN BOOKKEEPING AND
		 * MUST NOT APPEAR IN environ. They are how descriptor flags
		 * and ignored signals cross an exec (see execve.c, which
		 * writes both), they are consumed right here by `_fdinit` and
		 * `sigsetup`, and a program has no business seeing them --
		 * Tcl's env.test asks a child to list its environment and got
		 *
		 *	_fdinfo=0 34 0\n1 2 2\n...
		 *	_sighdlr=
		 *
		 * back. Private bookkeeping leaking into a public interface is
		 * the `XLoadFont` family inverted: not a stub answering for
		 * work it did not do, but an implementation detail answering
		 * as though it were data.
		 *
		 * Dropping them is safe because `environ` is not the
		 * transport: `execve` writes `/env/_fdinfo` and
		 * `/env/_sighdlr` itself, and a child reads `/env` rather
		 * than inheriting this array. Both are parsed into tables
		 * before the buffer is reused, so not advancing `p` simply
		 * lets the next entry overwrite them.
		 *
		 * `nohandle` stays visible: it is a knob a user sets, not
		 * something libap writes.
		 */
		if(strcmp(d9->name, "_fdinfo") == 0) {
			_fdinit(p+n+1, p+n+1+m);
			fdinited = 1;
			continue;
		} else if(strcmp(d9->name, "_sighdlr") == 0) {
			sigsetup(p+n+1, p+n+1+m);
			continue;
		} else if(strcmp(d9->name, "nohandle") == 0)
			nohandle = 1;
		p += n+m+2;
		cnt++;
	}
	free(d9a);
	if(!fdinited)
		_fdinit(0, 0);
done:
	environ = pp = malloc((1+cnt)*sizeof(char *));
	p = ps;
	for(i = 0; i < cnt; i++) {
		*pp++ = p;
		p = memchr(p, 0, ps+psize-p);
		if (!p)
			break;
		p++;
	}
	*pp = 0;
	if(!nohandle)
		_NOTIFY(_notehandler);
}

static void
sigsetup(char *s, char *se)
{
	int sig;
	char *e;

	while(s < se){
		sig = strtoul(s, &e, 10);
		if(s == e)
			break;
		s = e;
		if(sig <= MAXSIG)
			_sighdlr[sig] = SIG_IGN;
	}
}

#pragma profile on
