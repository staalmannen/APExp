#include "../include/lib.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/dir.h"
#include "../include/sys9.h"

int
truncate(const char *path, off_t length)
{
	Dir d;

	if(length < 0){
		errno = EINVAL;
		return -1;
	}
	_nulldir(&d);
	d.length = length;
	if(_dirwstat((char*)path, &d) < 0){
		_syserrno();
		return -1;
	}
	return 0;
}
