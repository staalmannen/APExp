#include "stdio_impl.h"
#include <fcntl.h>
#include <errno.h>

FILE *fopen(const char *name, const char *mode){
	int fd;
	int flags = __fmodeflags(mode);

	fd = open(name, flags, 0666);
	if (fd < 0)
		return NULL;
	return __fdopen(fd, mode);
}


