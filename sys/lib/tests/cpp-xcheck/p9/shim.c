/*
 * shim.c -- the two definitions `p9/libc.h' declares but cannot inline.
 * See `cpp-xcheck.sh' for what this directory is for.
 */
#include <fcntl.h>

char *argv0;

/*
 * Plan 9's create(name, mode, perm). cpp calls it only for the -o file,
 * so the mode argument (OWRITE etc.) is ignored and the flags are the
 * POSIX equivalent spelled out.
 */
int
create(char *name, int mode, int perm)
{
	(void)mode;
	return open(name, O_WRONLY|O_CREAT|O_TRUNC, perm & 0777);
}
