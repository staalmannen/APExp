/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#ifndef SLIBTOOL_READLINK_IMPL_H
#define SLIBTOOL_READLINK_IMPL_H

#include <unistd.h>
#include <errno.h>

static inline int slbt_readlinkat(
	int		fdcwd,
	const char *	restrict path,
	char *		restrict buf,
	ssize_t		bufsize)
{
	ssize_t ret;

	if ((ret = readlinkat(fdcwd,path,buf,bufsize)) <= 0) {
		return -1;
	} else if (ret == bufsize) {
		errno = ENOBUFS;
		return -1;
	} else {
		buf[ret] = 0;
		return 0;
	}
}

#endif
