#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
/*
 * <sys/limits.h> and not <limits.h>: `at_functions.c' in this very
 * directory does the same, under the same mkfile flags, and compiles.
 * <limits.h> here would be read AFTER <unistd.h> has already pulled
 * <sys/limits.h>, which used to be a cpp error -- see the note in
 * limits_generic.h. That is fixed, but the shorter include is the one
 * with a working neighbour beside it.
 */
#include <sys/limits.h>
#include <string.h>
#include <stdio.h>
#include "sys9.h"
#include "dir.h"

/*
 * getcwd -- and the thing it did NOT do was allocate.
 *
 * This used to pass `buf' straight to `_FD2PATH' with no null check, so
 * `getcwd(NULL, n)' handed the kernel address 0 and the process died
 * with
 *
 *	suicide: invalid address 0x0/4096 in sys call
 *
 * **`getcwd(NULL, size)' is how glibc, musl and POSIX.1-2008 all let a
 * caller say "allocate it for me", and a great deal of GNU code uses
 * it.** bash is one: `builtins/common.c:603' is
 * `getcwd (0, PATH_MAX)'.
 *
 * ------------------------------------------------------------------
 * WHY IT TOOK SO LONG TO SURFACE, WHICH IS THE PART WORTH KEEPING.
 *
 * bash had ALREADY DETECTED this and shipped the fix, and the build
 * threw it away. `config.h' says `#define GETCWD_BROKEN 1', so
 * `config-bot.h:66' does `#undef HAVE_GETCWD', so `lib/sh/getcwd.c'
 * compiles a replacement that DOES allocate, and `getcwd.$O' is in the
 * mkfile's OBJSH. But that object lands inside `libsh.a', and the
 * mkfile links deliberately:
 *
 *	#link libap first to already occupy symbols supported by libap
 *	LIB= .../libap.a $BASHLIBS ...
 *
 * so `getcwd' resolved out of libap and bash's own copy was never
 * pulled from the archive. *A program's workaround for a library bug
 * is only as good as the link order* -- the same shape as gnulib's
 * self-recursive `strerror', where libap's correct version lost to
 * gnulib's broken one, pointing the other way.
 *
 * Fixing it HERE rather than reordering the link is the right half of
 * the choice: every other program that calls `getcwd(NULL, ...)' is
 * fixed too, and the mkfile's "libap first" policy stays intact.
 *
 * ------------------------------------------------------------------
 * TRUNCATION, and why the allocation is PATH_MAX rather than a
 * doubling loop.
 *
 * Plan 9's `fd2path' copies the path and **truncates silently** when
 * the buffer is too small -- it returns -1 only for a bad descriptor.
 * So there is no way to grow a buffer until the answer fits, because
 * nothing reports that it did not. PATH_MAX is the bound the rest of
 * this tree uses for a path, so `getcwd(NULL, 0)' takes it, and an
 * explicit size is honoured as asked.
 */

char*
getcwd(char *buf, size_t len)
{
	int fd;
	char *p;

	/*
	 * POSIX: a non-null buf with size 0 is EINVAL. A null buf with
	 * size 0 is the "you choose" form.
	 */
	if(len == 0){
		if(buf != 0){
			errno = EINVAL;
			return 0;
		}
		len = PATH_MAX;
	}

	p = buf;
	if(p == 0){
		p = malloc(len);
		if(p == 0){
			errno = ENOMEM;
			return 0;
		}
	}

	fd = _OPEN(".", OREAD);
	if(fd < 0) {
		if(buf == 0)
			free(p);
		errno = EACCES;
		return 0;
	}
	if(_FD2PATH(fd, p, len) < 0) {
		_CLOSE(fd);
		if(buf == 0)
			free(p);
		errno = EIO;
		return 0;
	}
	_CLOSE(fd);

/* RSC: is this necessary? */
	if(p[0] == '\0')
		strcpy(p, "/");
	return p;
}

/*
 * Version marker. `pcc -o x x.c' relinks against the INSTALLED libap,
 * so a test built from a fresh pull can run days-old library code and
 * say nothing; a test that calls this will not LINK against a libap
 * predating the fix, which is the only way to be sure what was
 * measured. Bump it when this file changes in a way a test must see.
 */
int
_getcwdmark(void)
{
	return 1;
}
