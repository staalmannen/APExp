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

DIR *
opendir(const char *filename)
{
	int f, n;
	DIR *d;
	char *s;

	n = strlen(filename);
	if(n > 0 && filename[n-1] != '/'){
		s = malloc(n+2);
		if(s == NULL)
			goto Nomem;
		memcpy(s, filename, n);
		s[n++] = '/';
		s[n] = 0;
	} else
		s = (char*)filename;
	f = open(s, O_RDONLY);
	if(s != filename)
		free(s);
	if(f < 0){
		_syserrno();
		return NULL;
	}
	_fdinfo[f].flags |= FD_CLOEXEC;
	d = (DIR *)malloc(sizeof(DIR) + DBLOCKSIZE*sizeof(struct dirent));
	if(d == NULL){
Nomem:
		errno = ENOMEM;
		return NULL;
	}
	d->dd_buf = (char *)d + sizeof(DIR);
	d->dd_fd = f;
	d->dd_loc = 0;
	d->dd_size = 0;
	d->dirs = NULL;
	d->dirsize = 0;
	d->dirloc = 0;
	d->dd_seek = 0;	/* entry count for telldir/seekdir */
	return d;
}



