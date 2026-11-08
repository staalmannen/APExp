#include <dirent.h>
#include <errno.h>
#include "_dirent.h"

int
dirfd(DIR *d)
{
	return d->fd;
}
