#include "lib.h"
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

/*
 * dirfd - return the file descriptor associated with a DIR stream
 *
 * The fd is the one opened by opendir(). Callers must not close it
 * directly; it is closed by closedir().
 */
int
dirfd(DIR *d)
{
	if(d == NULL){
		errno = EINVAL;
		return -1;
	}
	return d->dd_fd;
}
