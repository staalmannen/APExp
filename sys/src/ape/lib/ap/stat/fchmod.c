#include "../include/lib.h"
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include "../include/sys9.h"
#include "../include/dir.h"

int
fchmod(int fd, mode_t mode)
{
	Dir d, *dir;

	dir = _dirfstat(fd);
	if(dir == nil){
		_syserrno();
		return -1;
	}
	_nulldir(&d);
	d.mode = (dir->mode & ~0777) | (mode & 0777);
	free(dir);
	if(_dirfwstat(fd, &d) < 0){
		_syserrno();
		return -1;
	}
	return 0;
}
