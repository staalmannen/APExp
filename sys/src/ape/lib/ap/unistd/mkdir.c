#include "lib.h"
#include <sys/stat.h>
#include <errno.h>
#include "sys9.h"

/*
 * BUG: errno mapping
 */
int
mkdir(const char *name, mode_t mode)
{
	int n;
	struct stat st;

	if(stat(name, &st)==0) {
		errno = EEXIST;
		return -1;
	}
	/* POSIX: the file-creation mask applies to mkdir too. */
	n = _CREATE(name, 0, 0x80000000|((mode&0777) & ~_umaskbits()));
	if(n < 0)
		_syserrno();
	else{
		_CLOSE(n);
		n = 0;
	}
	return n;
}
