#include "lib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "sys9.h"
#include "dir.h"

#define DBLOCKSIZE 20

int
closedir(DIR *d)
{
	int fd;

	if(d == NULL){
		errno = EBADF;
		return -1;
	}
	fd = d->dd_fd;
	free(d->dirs);
	free(d);
	return close(fd);
}

