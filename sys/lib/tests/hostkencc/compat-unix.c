/*
 * compat-unix.c -- the Unix half of `cc/compat.h', for host builds.
 *
 * ***IT IS cc/compat WITH ONE FUNCTION CHANGED AND ONE REWRITTEN***,
 * and that is the measurement rather than a design: go1.4's `lib9'
 * implements Plan 9's `open'/`create'/`seek'/`dup'/`exec'/`getwd' and
 * even `wait' returning a `Waitmsg*' on Unix, so eight of the ten
 * portability hooks are the Plan 9 text verbatim.
 *
 *   systemtype()  returns `sys & Unix' instead of `sys & Plan9'
 *   alloc/allocn  use the host allocator
 *
 * Plan 9's `cc/compat' bump-allocates over the `end[]' symbol with
 * brk() and REPLACES malloc/calloc/realloc/free with never-freeing
 * versions. Neither `end[]' nor that brk() behaviour exists here, and
 * overriding malloc under glibc is not something to attempt for an
 * instrument. **go's own portable cc does exactly what is below**
 * (go1.4 `src/cmd/cc/lex.c:1553`), so this is upstream's answer to the
 * same question rather than an invention.
 *
 * *The allocator difference is the one fidelity caveat that is about
 * behaviour rather than width*: Plan 9's `alloc' never frees and hands
 * out 8-aligned bump-allocated memory, so a use-after-free or an
 * overrun in the compiler is INVISIBLE there and may fault here. That
 * makes the host build strictly better at finding such a bug and means
 * a host-only crash is a real lead, not an artifact -- and it is why
 * the harness can run the compiler under valgrind/ASan at all.
 */
#include <u.h>
#include <libc.h>
#include <bio.h>
#include "cc.h"

int
myaccess(char *f)
{
	return access(f, AEXIST);
}

int
mycreat(char *n, int p)
{

	return create(n, 1, p);
}

int
mywait(int *s)
{
	int p;
	Waitmsg *w;

	if((w = wait()) == nil)
		return -1;
	else{
		p = w->pid;
		*s = 0;
		if(w->msg[0])
			*s = 1;
		free(w);
		return p;
	}
}

int
mydup(int f1, int f2)
{
	return dup(f1,f2);
}

int
mypipe(int *fd)
{
	return pipe(fd);
}

int
systemtype(int sys)
{
	return sys & Unix;
}

int
pathchar(void)
{
	return '/';
}

char*
mygetwd(char *path, int len)
{
	return getwd(path, len);
}

int
myexec(char *path, char *argv[])
{
	return exec(path, argv);
}

int
myfork(void)
{
	return fork();
}

void*
alloc(long n)
{
	void *p;

	p = malloc(n);
	if(p == nil)
		sysfatal("alloc: out of memory");
	memset(p, 0, n);
	return p;
}

void*
allocn(void *p, long on, long n)
{
	if(p == nil)
		return alloc(on+n);
	p = realloc(p, on+n);
	if(p == nil)
		sysfatal("allocn: out of memory");
	if(n > 0)
		memset((char*)p+on, 0, n);
	return p;
}
