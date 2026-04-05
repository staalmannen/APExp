#include "stdio_impl.h"
#include <fcntl.h>
#include <unistd.h>

FILE *freopen(const char *name, const char *mode, FILE *f){
	int fd, flags;

	if (f && f->fd >= 0) {
		fclose(f);
	}

	if (!name) {
		return NULL;
	}

	flags = __fmodeflags(mode);
	fd = open(name, flags, 0666);
	if (fd < 0)
		return NULL;

	FILE *result = __fdopen(fd, mode);
	if (!result) {
		close(fd);
		return NULL;
	}
	return result;
}

