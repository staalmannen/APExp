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

void
rewinddir(DIR *d)
{
	if(d == NULL)
		return;
	d->dd_loc = 0;
	d->dd_size = 0;
	d->dirsize = 0;
	d->dirloc = 0;
	d->dd_seek = 0;
	free(d->dirs);
	d->dirs = NULL;
	if(_SEEK(d->dd_fd, 0, 0) < 0){
		_syserrno();
		return;
	}
}

