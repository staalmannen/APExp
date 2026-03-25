/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_readlink_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_errinfo_impl.h"

#define PPRIX64 "%"PRIx64

static char * slbt_mri_argument(
	int	fdat,
	char *	arg,
	char *	buf)
{
	char *	lnk;
	char *	target;
	char 	mricwd[PATH_MAX];
	char 	dstbuf[PATH_MAX];

	if ((!(strchr(arg,'+'))) && (!(strchr(arg,'-'))))
		return arg;

	if (arg[0] == '/') {
		target = arg;
	} else {
		if (slbt_realpath(
				fdat,".",O_DIRECTORY,
				mricwd,sizeof(mricwd)) < 0)
			return 0;

		if (slbt_snprintf(dstbuf,sizeof(dstbuf),
				"%s/%s",mricwd,arg) < 0)
			return 0;

		target = dstbuf;
	}

	lnk = 0;

	{
		struct stat st;

		if (fstatat(fdat,target,&st,0) < 0)
			return 0;

		sprintf(buf,
			".mri.tmplnk"
			".dev."PPRIX64
			".inode."PPRIX64
			".size."PPRIX64
			".tmp",
			st.st_dev,
			st.st_ino,
			st.st_size);

		unlinkat(fdat,buf,0);

		if (!(symlinkat(target,fdat,buf)))
			lnk = buf;
	}

	return lnk;
}

static void slbt_util_import_archive_child(
	char *	program,
	int	fd[2])
{
	char *	argv[3];

	argv[0] = program;
	argv[1] = "-M";
	argv[2] = 0;

	close(fd[1]);

	if (dup2(fd[0],0) == 0)
		execvp(program,argv);

	_exit(EXIT_FAILURE);
}

int slbt_util_import_archive_mri(
	struct slbt_exec_ctx *  ectx,
	char *			dstarchive,
	char *			srcarchive)
{
	int	fdcwd;
	pid_t	pid;
	pid_t	rpid;
	int	fd[2];
	char *	dst;
	char *	src;
	char *	fmt;
	char	mridst [96];
	char	mrisrc [96];
	char	program[PATH_MAX];

	const struct slbt_driver_ctx * dctx;

	/* driver context */
	dctx = (slbt_get_exec_ictx(ectx))->dctx;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* not needed? */
	if (slbt_symlink_is_a_placeholder(fdcwd,srcarchive))
		return 0;

	/* program */
	if (slbt_snprintf(program,sizeof(program),
			"%s",dctx->x_cctx->host.ar) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* fork */
	if (pipe(fd))
		return SLBT_SYSTEM_ERROR(dctx,0);

	if ((pid = slbt_fork()) < 0) {
		close(fd[0]);
		close(fd[1]);
		return SLBT_SYSTEM_ERROR(dctx,0);
	}

	/* child */
	if (pid == 0)
		slbt_util_import_archive_child(
			program,
			fd);

	/* parent */
	close(fd[0]);

	ectx->pid = pid;

	dst = slbt_mri_argument(fdcwd,dstarchive,mridst);
	src = slbt_mri_argument(fdcwd,srcarchive,mrisrc);

	if (!dst || !src) {
		close(fd[1]);
		return SLBT_SYSTEM_ERROR(dctx,0);
	}

	fmt = "OPEN %s\n"
	      "ADDLIB %s\n"
	      "SAVE\n"
	      "END\n";

	if (slbt_dprintf(fd[1],fmt,dst,src) < 0) {
		close(fd[1]);
		return SLBT_SYSTEM_ERROR(dctx,0);
	}

	close(fd[1]);

	rpid = waitpid(
		pid,
		&ectx->exitcode,
		0);

	if (dst == mridst)
		unlinkat(fdcwd,dst,0);

	if (src == mrisrc)
		unlinkat(fdcwd,src,0);

	return (rpid == pid) && (ectx->exitcode == 0)
		? 0 : SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_ARCHIVE_IMPORT);
}
