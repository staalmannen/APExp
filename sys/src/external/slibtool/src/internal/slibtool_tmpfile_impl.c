/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#define _GNU_SOURCE
#include <time.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "slibtool_visibility_impl.h"

#define PPRIX64 "%"PRIx64

/* mkostemp might be guarded by non-standard macros */
/* unless HAVE_NO_MKOSTEMP, assume it is available */
extern int mkstemp(char *);
extern int mkostemp(char *, int);

/* __fs_tmpfile() atomically provides a private tmpfile */
static int slbt_tmpfile_by_framework(void)
{
#ifdef _MIDIPIX_ABI
	extern int __fs_tmpfile(int);
	return __fs_tmpfile(O_CLOEXEC);
#else
	return (-1);
#endif
}

/* O_TMPFILE atomically provides a private tmpfile */
static int slbt_tmpfile_by_kernel(void)
{
#ifdef O_TMPFILE
	return openat(AT_FDCWD,"/tmp",O_RDWR|O_TMPFILE|O_CLOEXEC,0);
#else
	return (-1);
#endif
}

/* mk{o}stemp() provides a non-private tmpfile */
static int slbt_mkostemp(char * tmplate)
{
	int fd;
#ifdef HAVE_NO_MKOSTEMP
	if ((fd = mkstemp(tmplate)) >= 0)
		fcntl(fd,F_SETFD,FD_CLOEXEC);
#else
	fd = mkostemp(tmplate,O_CLOEXEC);
#endif
	return fd;
}

slbt_hidden int slbt_tmpfile(void)
{
	int             fd;
	void *          addr;
	int64_t         tint;
	char            tmplate[128];

	/* try with __fs_tmpfile() */
	if ((fd = slbt_tmpfile_by_framework()) >= 0)
		return fd;

	/* try with O_TMPFILE */
	if ((fd = slbt_tmpfile_by_kernel()) >= 0)
		return fd;

	/* fallback to mk{o}stemp */
	addr = tmplate;
	tint = time(0);
	memset(tmplate,0,sizeof(tmplate));
	snprintf(tmplate,sizeof(tmplate),
		"/tmp/"
		".slibtool.tmpfile"
		".time."PPRIX64
		".salt.%p"
		".pid.%d"
		".XXXXXXXXXXXX",
		tint,addr,
		getpid());

	return slbt_mkostemp(tmplate);
}
