#include <unistd.h>
#include "_npe.h"

int
isatty(int fd)
{
	char buf[64];

	return fd2path(fd, buf, sizeof(buf)) == 0 && strcmp(buf, "/dev/cons") == 0;
}
