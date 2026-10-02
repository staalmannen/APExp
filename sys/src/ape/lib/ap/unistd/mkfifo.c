#include	<sys/types.h>
#include	<sys/stat.h>
#include	<errno.h>

/*
 * Plan 9 has no FIFOs in the file system, so this cannot be done --
 * but it used to answer `-1' with `errno = 0', which tells the caller
 * it failed and refuses to say why. perror() then prints whatever the
 * last call left behind, or "no error at all".
 *
 * ENOSYS is the honest answer and is what every other unimplementable
 * call in this tree gives (symlink(), for one).
 */
int
mkfifo(char *, mode_t)
{
#pragma ref path
#pragma ref mode
	errno = ENOSYS;
	return -1;
}
