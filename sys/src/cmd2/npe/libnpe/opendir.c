#include <dirent.h>
#include <errno.h>
#include "_dirent.h"

DIR *
opendir(char *name)
{
	Dir *dir;
	DIR *d;
	int fd;

	dir = nil;
	d = nil;
	if((fd = open(name, OREAD|OCEXEC)) >= 0 &&
	    (dir = dirfstat(fd)) != nil &&
	    (dir->qid.type & QTDIR) != 0 &&
	    (d = calloc(1, sizeof(*d))) != nil){
		d->fd = fd;
	}

	free(dir);
	if(d == nil){
		if(fd >= 0)
			close(fd);
		else
			errno = ENOENT;
	}

	return d;
}
