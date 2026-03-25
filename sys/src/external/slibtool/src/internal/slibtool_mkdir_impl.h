/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#ifndef SLIBTOOL_MKDIR_IMPL_H
#define SLIBTOOL_MKDIR_IMPL_H

#include <errno.h>
#include <unistd.h>

#include "slibtool_driver_impl.h"

#ifndef O_DIRECTORY
#define O_DIRECTORY 0
#endif

static inline int slbt_mkdir(
	const struct slbt_driver_ctx *	dctx,
	const char *			path)
{
	int fdcwd;
	int fdlibs;

	fdcwd = slbt_driver_fdcwd(dctx);

	if ((fdlibs = openat(fdcwd,path,O_DIRECTORY,0)) >= 0)
		close(fdlibs);
	else if ((errno != ENOENT) || mkdirat(fdcwd,path,0777))
		if (errno != EEXIST)
			return -1;

	return 0;
}

#endif
