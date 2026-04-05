#include "stdio_impl.h"
#include <errno.h>

FILE *fdopen(const int fd, const char *mode){
	if(fd < 0){
		errno = EBADF;
		return NULL;
	}
	return __fdopen(fd, mode);
}

