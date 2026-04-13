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
	case FIONREAD:
		if(fstat(fd, &d) < 0) {
			errno = EBADF;
			return -1;
		}
		/* this works if the file is buffered somehow */
		*(long*)arg = d.st_size;
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
