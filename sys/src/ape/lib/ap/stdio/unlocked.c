/*
 * The _unlocked family: POSIX's four, plus the GNU ones portable code
 * reaches for.
 *
 * These existed here before only as four macros in stdio_impl.h --
 * getc_unlocked, putc_unlocked, feof_unlocked, ferror_unlocked -- which
 * musl has for its own internal use. <stdio.h> used to include that
 * header, so every program saw them and nothing in libap had to define
 * them. When <stdio.h> stopped including it the macros went away and
 * the references became link errors:
 *
 *	shell_getc: undefined: ferror_unlocked in shell_getc
 *	check_mail: undefined: putc_unlocked in check_mail
 *
 * from bash, which uses them throughout its input path.
 *
 * Functions rather than macros in <stdio.h>, deliberately. Portable
 * code that thinks a system lacks these writes
 *
 *	#ifndef ferror_unlocked
 *	#define ferror_unlocked(x) ferror(x)
 *	#endif
 *
 * unguarded and often with different spacing, and cpp treats a macro
 * redefinition that is not token-for-token identical, white space
 * included, as an error -- see the note on macro identity in CLAUDE.md.
 * A declaration cannot collide with that: the program's macro simply
 * wins in its own translation unit. It also means &getc_unlocked is a
 * valid expression, which the macro form does not give.
 *
 * Locking in this stdio is a no-op -- stdio_impl.h's __lockfile returns
 * 0 without doing anything -- so each of these is exactly its locked
 * counterpart today. They are still worth having as their own entry
 * points: the day flockfile becomes real, this is the one file that has
 * to change, and callers that hold the lock across a run of operations
 * are already saying so.
 *
 * getc/putc are written out rather than delegated because those two are
 * the ones used in a loop, and the fast path is a pointer compare.
 */

#include "stdio_impl.h"
#include <stdio.h>

#undef getc_unlocked
#undef putc_unlocked
#undef getchar_unlocked
#undef putchar_unlocked
#undef feof_unlocked
#undef ferror_unlocked

int
getc_unlocked(FILE *f)
{
	return f->rpos != f->rend ? *f->rpos++ : __uflow(f);
}

int
fgetc_unlocked(FILE *f)
{
	return f->rpos != f->rend ? *f->rpos++ : __uflow(f);
}

int
getchar_unlocked(void)
{
	FILE *f = stdin;

	return f->rpos != f->rend ? *f->rpos++ : __uflow(f);
}

int
putc_unlocked(int c, FILE *f)
{
	if((unsigned char)c != f->lbf && f->wpos != f->wend)
		return *f->wpos++ = (unsigned char)c;
	return __overflow(f, (unsigned char)c);
}

int
fputc_unlocked(int c, FILE *f)
{
	if((unsigned char)c != f->lbf && f->wpos != f->wend)
		return *f->wpos++ = (unsigned char)c;
	return __overflow(f, (unsigned char)c);
}

int
putchar_unlocked(int c)
{
	FILE *f = stdout;

	if((unsigned char)c != f->lbf && f->wpos != f->wend)
		return *f->wpos++ = (unsigned char)c;
	return __overflow(f, (unsigned char)c);
}

int
feof_unlocked(FILE *f)
{
	return f->flags & F_EOF;
}

int
ferror_unlocked(FILE *f)
{
	return f->flags & F_ERR;
}

void
clearerr_unlocked(FILE *f)
{
	f->flags &= ~(F_EOF | F_ERR);
}

int
fileno_unlocked(FILE *f)
{
	return f->fd;
}

int
fflush_unlocked(FILE *f)
{
	return fflush(f);
}

size_t
fread_unlocked(void *p, size_t sz, size_t n, FILE *f)
{
	return fread(p, sz, n, f);
}

size_t
fwrite_unlocked(const void *p, size_t sz, size_t n, FILE *f)
{
	return fwrite(p, sz, n, f);
}

char *
fgets_unlocked(char *s, int n, FILE *f)
{
	return fgets(s, n, f);
}

int
fputs_unlocked(const char *s, FILE *f)
{
	return fputs(s, f);
}
