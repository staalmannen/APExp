/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

/* bsd extensions */
#include <sys/uio.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

int
ioctl(int fd, unsigned long request, void* arg)
{
	struct stat d;
	struct winsize *ws;
	char *p;
	int n;

	switch(request) {
	/*
	 * FIONREAD'S ARGUMENT IS AN `int *', NOT A `long *'.
	 *
	 * BSD, Linux and every caller in this tree pass the address of an
	 * `int'; readline's rl_gather_tyi() passes `&chars_avail', an int
	 * local. Writing a `long' through it stores EIGHT bytes on amd64
	 * and smashes the four beyond -- whatever the compiler put next in
	 * the caller's frame. The store even succeeds, so nothing
	 * complains; what shows up is the neighbouring variable being zero
	 * for no reason, somewhere else entirely.
	 *
	 * Found while reading a vts trace, NOT measured: it is not what
	 * made bash exit there (the EOF happened with no stat before it).
	 * It is wrong on its own terms, which is enough.
	 *
	 * The ANSWER is still an approximation and worth saying out loud:
	 * st_size is the number of bytes available only for a file that
	 * has a size. For a terminal, a pipe or a socket Plan 9 reports 0,
	 * so this says "nothing to read" always -- which is the safe
	 * direction (a caller waits rather than reading what is not there)
	 * but is not the truth. Plan 9's stat on a PIPE does report what
	 * is queued, so a real answer is available for that case; it needs
	 * its own round and a test, not a guess here.
	 */
	case FIONREAD:
		if(fstat(fd, &d) < 0) {
			errno = EBADF;
			return -1;
		}
		/* this works if the file is buffered somehow */
		*(int*)arg = (int)d.st_size;
		return 0;

	case TIOCGWINSZ:
		ws = (struct winsize*)arg;
		memset(ws, 0, sizeof *ws);
		/* Primary source: $COLUMNS and $LINES, set by 9term/vt on resize. */
		ws->ws_col = 80;
		ws->ws_row = 24;
		if((p = getenv("COLUMNS")) != NULL && (n = atoi(p)) > 0)
			ws->ws_col = (unsigned short)n;
		if((p = getenv("LINES")) != NULL && (n = atoi(p)) > 0)
			ws->ws_row = (unsigned short)n;
		return 0;

	case TIOCSWINSZ:
		/* Plan9 has no kernel ioctl; accept and ignore. */
		return 0;

	default:
		errno = EINVAL;
		return -1;
	}
}
