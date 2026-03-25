/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <slibtool/slibtool.h>

#include "slibtool_driver_impl.h"
#include "slibtool_readlink_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_visibility_impl.h"

#ifdef HAVE_SYS_SYSCALL_H
#include <sys/syscall.h>
#include <unistd.h>
#endif

#ifdef _MIDIPIX_ABI
#include <sys/fs.h>
#endif

#ifndef ENOTSUP
#define ENOTSUP EOPNOTSUPP
#endif

slbt_hidden int slbt_realpath(
	int             fdat,
	const char *    path,
	int             options,
	char *          buf,
	size_t          buflen)
{
	int             ret;
	int             fd;
	int             fdproc;
	struct stat     st;
	struct stat     stproc;
	char    procfspath[36];

	/* common validation */
	if (!buf || (options & O_CREAT)) {
		errno = EINVAL;
		return -1;
	}

	/* framework-based wrapper */
#ifdef _MIDIPIX_ABI
	return __fs_rpath(fdat,path,options,buf,buflen);
#endif

#ifdef SYS___realpathat
	return syscall(SYS___realpathat,fdat,path,buf,buflen,0);
#endif

	/* buflen */
	if (buflen < PATH_MAX) {
		errno = ENOBUFS;
		return -1;
	}

	/* AT_FDCWD */
	if (fdat == AT_FDCWD) {
		return realpath(path,buf) ? 0 : -1;
	}

	/* /proc/self/fd */
	if ((fd = openat(fdat,path,options,0)) < 0)
		return -1;

	sprintf(procfspath,"/proc/self/fd/%d",fd);

	if (slbt_readlinkat(fdat,procfspath,buf,buflen)) {
		close(fd);
		return -1;
	}

	if ((fdproc = openat(AT_FDCWD,buf,options|O_NOFOLLOW,0)) < 0) {
		close(fd);
		errno = ELOOP;
		return -1;
	}

	ret = fstat(fd,&st) || fstat(fdproc,&stproc);

	close(fd);
	close(fdproc);

	if (ret || (st.st_dev != stproc.st_dev) || (st.st_ino != stproc.st_ino)) {
		errno = ENOTSUP;
		return -1;
	}

	return 0;
}
