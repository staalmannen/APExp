#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lib.h"
#include <sys/stat.h>
#include "sys9.h"

/*
 * O_NOCTTY has no effect.
 * O_CLOEXEC maps to Plan9 OCEXEC (close on exec).
 *
 * O_DIRECTORY has no Plan 9 equivalent and is enforced here, with an
 * fstat after the open.  It used to be #defined to 0, which is not the
 * harmless simplification it looks: gnulib's targetdir.c decides whether
 * an operand is a directory by whether
 *
 *	open (file, O_PATHSEARCH | O_DIRECTORY)
 *
 * succeeds, so with O_DIRECTORY ignored, cp, mv, ln and install all took
 * an existing plain file for a directory and tried to create the copy
 * inside it:
 *
 *	cp: cannot stat '/amd64/bin/ape/cut/6.cut': No such system call
 */
int
open(const char *path, int flags, ...)
{
	int n;
	long f;
	int mode;
	Fdinfo *fi;
	struct stat st;
	va_list va;

	f = flags&O_ACCMODE;
	if(flags&O_CLOEXEC) f |= OCEXEC;
	if(flags&O_CREAT){
		if(access(path, 0) >= 0){
			if(flags&O_EXCL){
				errno = EEXIST;
				return -1;
			}else{
				if((flags&O_TRUNC)&&(flags&(O_RDWR|O_WRONLY)))
					f |= 16;
				n = _OPEN(path, f);
			}
		}else{
			va_start(va, flags);
			mode = va_arg(va, int);
			va_end(va);
			n = _CREATE(path, f, mode&0777);
		}
		if(n < 0)
			_syserrno();
	}else{
		if((flags&O_TRUNC)&&(flags&(O_RDWR|O_WRONLY)))
			f |= 16;
		n = _OPEN(path, f);
		if(n < 0)
			_syserrno();
	}
	if(n >= OPEN_MAX){
		_CLOSE(n);
		errno = ENFILE;
		return -1;
	}
	if(n >= 0){
		fi = &_fdinfo[n];
		fi->flags = FD_ISOPEN;
		if(flags&O_CLOEXEC) fi->flags |= FD_CLOEXEC;
		fi->oflags = flags&(O_ACCMODE|O_NONBLOCK|O_APPEND);
		fi->uid = -2;
		fi->gid = -2;
		fi->name = malloc(strlen(path)+1);
		if(fi->name)
			strcpy(fi->name, path);
		if(fi->oflags&O_APPEND)
			_SEEK(n, 0, 2);
		/* After _fdinfo[n] is set up: fstat() reads it. */
		if(flags&O_DIRECTORY){
			if(fstat(n, &st) < 0 || !S_ISDIR(st.st_mode)){
				close(n);
				errno = ENOTDIR;
				return -1;
			}
		}
	}
	return n;
}
