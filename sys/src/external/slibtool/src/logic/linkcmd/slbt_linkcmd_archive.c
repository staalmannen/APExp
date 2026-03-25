/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_linkcmd_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_metafile_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_visibility_impl.h"

static int slbt_exec_link_remove_file(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			target)
{
	int fdcwd;
	char * mark;
	char * sbuf;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* remove target (if any) */
	if (unlinkat(fdcwd,target,0) && (errno != ENOENT))
		return SLBT_SYSTEM_ERROR(dctx);

	/* remove a previous .disabled placeholder */
	sbuf  = (slbt_get_exec_ictx(ectx))->sbuf;
	mark  = sbuf;
	mark += sprintf(mark,"%s",target);
	strcpy(mark,".disabled");

	if (unlinkat(fdcwd,sbuf,0) && (errno != ENOENT))
		return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}


static bool slbt_archive_is_convenience_library(int fdcwd, const char * arpath)
{
	int     fd;
	char    laipath[PATH_MAX];
	char *  dot;

	strcpy(laipath,arpath);
	dot = strrchr(laipath,'.');
	strcpy(dot,".lai");

	if ((fd = openat(fdcwd,laipath,O_RDONLY,0)) >= 0) {
		close(fd);
		return false;
	}

	return true;
}


slbt_hidden int slbt_exec_link_create_archive(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			arfilename,
	bool				fpic,
	bool                            fdep)
{
	int		fdcwd;
	char **         argv;
	char ** 	aarg;
	char ** 	parg;
	char		program[PATH_MAX];
	char		output [PATH_MAX];
	char		namebuf[PATH_MAX];

	/* dlopen, dlpreopen: object compilation (derived from dynamic linking) */
	if (ectx->x_dlopenobj) {
		slbt_ectx_reset_arguments(ectx);
		slbt_reset_placeholders(ectx);

		sprintf(namebuf,"%s%s",ectx->x_ldirname,"@ARDLOPEN@");

		if (slbt_exec_link_create_library(
				dctx,ectx,
				namebuf,namebuf,namebuf,
				true,fpic) < 0)
			return SLBT_NESTED_ERROR(dctx);
	}

	/* restore initial state */
	slbt_ectx_reset_arguments(ectx);

	/* placeholders */
	slbt_reset_placeholders(ectx);

	/* output */
	if (slbt_snprintf(output,sizeof(output),
			"%s",arfilename) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* tool-specific argument vector */
	argv = (slbt_get_driver_ictx(dctx))->host.ar_argv;

	/* fdcwd */
	fdcwd   = slbt_driver_fdcwd(dctx);

	/* input argument adjustment */
	aarg    = ectx->x_altv;

	if ((parg = argv)) {
		for (; *parg; )
			*aarg++ = *parg++;
	} else {
		*aarg++ = program;
	}

	*aarg++ = "-crs";
	*aarg++ = output;

	for (parg=ectx->x_cargv; *parg; parg++)
		if (slbt_adjust_object_argument(*parg,fpic,!fpic,fdcwd))
			*aarg++ = *parg;

	if (ectx->x_dlopenobj)
		*aarg++ = ectx->x_dlopenobj;

	*aarg = 0;
	ectx->x_argv = ectx->x_altv;

	/* ar program */
	if (argv) {
		ectx->x_program = argv[0];
	} else {
		if (slbt_snprintf(program,sizeof(program),
				"%s",dctx->x_cctx->x_host.ha_ar) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		ectx->x_program = program;
	}

	/* step output */
	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
		if (slbt_output_link(ectx))
			return SLBT_NESTED_ERROR(dctx);

	/* remove old archive as needed */
	if (slbt_exec_link_remove_file(dctx,ectx,output))
		return SLBT_NESTED_ERROR(dctx);

	/* .deps */
	if (fdep)
		if (slbt_exec_link_create_dep_file(
				dctx,ectx,ectx->x_cargv,
				arfilename,true))
			return SLBT_NESTED_ERROR(dctx);

	/* ar spawn */
	if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
		return SLBT_SPAWN_ERROR(dctx);

	} else if (ectx->x_exitcode) {
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_ERROR);
	}

	/* input objects associated with .la archives */
	for (parg=ectx->x_cargv; *parg; parg++)
		if (slbt_adjust_wrapper_argument(
				*parg,true,
				dctx->x_cctx->x_settings.fa_arsuffix))
			if (slbt_archive_is_convenience_library(fdcwd,*parg))
				if (slbt_util_import_archive(ectx,output,*parg))
					return SLBT_NESTED_ERROR(dctx);
	return 0;
}
