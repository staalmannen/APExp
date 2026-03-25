/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include <slibtool/slibtool_arbits.h>
#include "slibtool_ar_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"

/****************************************************/
/* As elsewhere in slibtool, file-system operations */
/* utilizie the _at variants of the relevant posix  */
/* interfaces. In the case of archives, that means  */
/* passing dctx->x_fdctx->fdcwd as the _fdat_ param,  */
/* where dctx is the driver context which was used  */
/* with slbt_ar_get_archive_ctx().                     */
/************************************************** */

#define PPRIX64 "%"PRIx64

int slbt_ar_store_archive(
	struct slbt_archive_ctx * arctx,
	const char *              path,
	mode_t                    mode)
{
	const struct slbt_driver_ctx *  dctx;
	struct stat                     st;
	int                             fdat;
	int                             fdtmp;
	int64_t                         tint;
	int64_t                         stino;
	void *                          addr;
	char *                          mark;
	char *                          slash;
	size_t                          buflen;
	size_t                          nbytes;
	ssize_t                         written;
	char                            buf[PATH_MAX];

	/* init dctx */
	if (!(dctx = slbt_get_archive_ictx(arctx)->dctx))
		return -1;

	/* validation */
	if (strlen(path) >= PATH_MAX)
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_FLOW_ERROR);

	/**************************************************/
	/* create temporary file in the target directory  */
	/*                                                */
	/* the tmpfile name pattern involes the inode     */
	/* of the target directory, a local stack address */
	/* in the calling thread, the current time, and   */
	/* finally the pid of the current process.        */
	/**************************************************/

	memset(buf,0,sizeof(buf));
	strcpy(buf,path);

	fdat = slbt_driver_fdcwd(dctx);

	addr = buf;
	tint = time(0);
	mark = (slash = strrchr(buf,'/'))
		? slash : buf;

	if (slash) {
		*++mark = '\0';

		slbt_driver_set_ectx(
			dctx,0,buf);

		if (fstatat(fdat,buf,&st,0) < 0)
			return SLBT_SYSTEM_ERROR(
				dctx);
	} else {
		if (fstatat(fdat,".",&st,0) < 0)
			return SLBT_SYSTEM_ERROR(
				dctx);
	}

	stino  = st.st_ino;
	buflen = sizeof(buf) - (mark - buf);
	nbytes = snprintf(
		mark,
		buflen,
		".slibtool.tmpfile"
		".inode."PPRIX64
		".time."PPRIX64
		".salt.%p"
		".pid.%d"
		".tmp",
		stino,
		tint,addr,
		getpid());

	if (nbytes >= buflen)
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_FLOW_ERROR);

	slbt_driver_set_ectx(
		dctx,0,buf);

	if ((fdtmp = openat(fdat,buf,O_WRONLY|O_CREAT|O_EXCL,mode)) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	/* set archive size */
	if (ftruncate(fdtmp,arctx->x_map->map_size) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	/* write archive */
	mark   = arctx->x_map->map_addr;
	nbytes = arctx->x_map->map_size;

	for (; nbytes; ) {
		written = write(fdtmp,mark,nbytes);

		while ((written < 0) && (errno == EINTR))
			written = write(fdtmp,mark,nbytes);

		if (written < 0) {
			unlinkat(fdat,buf,0);
			return SLBT_SYSTEM_ERROR(dctx);
		};

		nbytes -= written;
		mark   += written;
	}

	/* finalize (atomically) */
	slbt_driver_set_ectx(
		dctx,0,buf);

	if (renameat(fdat,buf,fdat,path) < 0) {
		unlinkat(fdat,buf,0);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* yay */
	return 0;
}
