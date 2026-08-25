#include "lib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define DBLOCKSIZE 20

/*
 * fdopendir - POSIX.1-2008. Wrap an already-open descriptor in a DIR.
 *
 * The descriptor becomes owned by the stream: closedir() closes it,
 * exactly as it does for one that opendir() opened, so the caller must
 * not close or otherwise use fd afterwards.
 *
 * Everything but where the descriptor comes from is opendir()'s tail,
 * and FD_CLOEXEC is set on it for the same reason opendir sets it, and
 * because POSIX requires fdopendir to.
 */
DIR *
fdopendir(int fd)
{
	struct stat st;
	DIR *d;

	if(fstat(fd, &st) < 0)
		return NULL;
	if(!S_ISDIR(st.st_mode)){
		errno = ENOTDIR;
		return NULL;
	}

	d = (DIR *)malloc(sizeof(DIR) + DBLOCKSIZE*sizeof(struct dirent));
	if(d == NULL){
		errno = ENOMEM;
		return NULL;
	}
	_fdinfo[fd].flags |= FD_CLOEXEC;
	d->dd_buf = (char *)d + sizeof(DIR);
	d->dd_fd = fd;
	d->dd_loc = 0;
	d->dd_size = 0;
	d->dirs = NULL;
	d->dirsize = 0;
	d->dirloc = 0;
	d->dd_seek = 0;	/* entry count for telldir/seekdir */
	return d;
}
