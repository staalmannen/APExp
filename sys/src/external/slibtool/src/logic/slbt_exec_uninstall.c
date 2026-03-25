/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_uninstall_impl.h"
#include "slibtool_readlink_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_errinfo_impl.h"
#include "argv/argv.h"

static int slbt_uninstall_usage(
	int				fdout,
	const char *			program,
	const char *			arg,
	const struct argv_option **	optv,
	struct argv_meta *		meta,
	int				noclr)
{
	char header[512];

	snprintf(header,sizeof(header),
		"Usage: %s --mode=uninstall <rm> [options] [DEST]...\n"
		"Options:\n",
		program);

	switch (noclr) {
		case 0:
			slbt_argv_usage(fdout,header,optv,arg);
			break;

		default:
			slbt_argv_usage_plain(fdout,header,optv,arg);
			break;
	}

	slbt_argv_free(meta);

	return SLBT_USAGE;
}

static int slbt_exec_uninstall_fail(
	struct slbt_exec_ctx *	ectx,
	struct argv_meta *	meta,
	int			ret)
{
	slbt_argv_free(meta);
	slbt_ectx_free_exec_ctx(ectx);
	return ret;
}

static int slbt_exec_uninstall_fs_entry(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	char **				parg,
	char *				path,
	uint32_t			flags)
{
	struct stat	st;
	int		fdcwd;
	char *		slash;
	char		dpath[PATH_MAX];

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* needed? */
	if (fstatat(fdcwd,path,&st,0) && (errno == ENOENT))
		if (fstatat(fdcwd,path,&st,AT_SYMLINK_NOFOLLOW))
			if (errno == ENOENT)
				return 0;

	/* output */
	*parg = path;

	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
		if (slbt_output_uninstall(ectx))
			return SLBT_NESTED_ERROR(dctx);

	slbt_driver_set_ectx(
		dctx,0,path);

	/* directory? */
	if (S_ISDIR(st.st_mode)) {
		if (!unlinkat(fdcwd,path,AT_REMOVEDIR))
			return 0;

		else if ((errno == EEXIST) || (errno == ENOTEMPTY))
			return 0;

		else
			return SLBT_SYSTEM_ERROR(dctx);
	}

	/* remove file or symlink entry */
	if (unlinkat(fdcwd,path,0))
		return SLBT_SYSTEM_ERROR(dctx);

	/* remove empty containing directory? */
	if (flags & SLBT_UNINSTALL_RMDIR) {
		strcpy(dpath,path);

		/* invalid (current) directory? */
		if (!(slash = strrchr(dpath,'/')))
			return 0;

		*slash = 0;

		slbt_driver_set_ectx(
			dctx,0,dpath);

		if (unlinkat(fdcwd,dpath,AT_REMOVEDIR))
			return SLBT_SYSTEM_ERROR(dctx);
	}

	return 0;
}

static int slbt_exec_uninstall_versioned_library(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	char **				parg,
	char *				rpath,
	char *				lpath,
	const char *			suffix,
	uint32_t			flags)
{
	char *	slash;
	char *	dot;
	char *	path;
	char	apath[PATH_MAX];

	/* normalize library link path */
	if (lpath[0] == '/') {
		path = lpath;

	} else if (!(slash = strrchr(rpath,'/'))) {
		path = lpath;

	} else {
		strcpy(apath,rpath);
		strcpy(&apath[slash-rpath+1],lpath);
		path = apath;
	}

	/* delete associated version files */
	while ((dot = strrchr(path,'.')) && (strcmp(dot,suffix))) {
		if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
			return SLBT_NESTED_ERROR(dctx);

		*dot = 0;
	}

	return 0;
}

static int slbt_exec_uninstall_entry(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	struct argv_entry *		entry,
	char **				parg,
	uint32_t			flags)
{
	int		fdcwd;
	const char *	dsosuffix;
	char *		dot;
	char		path [PATH_MAX];
	char		lpath[PATH_MAX];

	if (slbt_snprintf(path,
			PATH_MAX - 8,
			"%s",entry->arg) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	*parg = (char *)entry->arg;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* remove explicit argument */
	if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
		return SLBT_NESTED_ERROR(dctx);

	/* non-.la-wrapper argument? */
	if (!(dot = strrchr(path,'.')))
		return 0;

	else if (strcmp(dot,".la"))
		return 0;

	/* remove .a archive as needed */
	strcpy(dot,".a");

	if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
		return SLBT_NESTED_ERROR(dctx);

	/* dsosuffix */
	dsosuffix = dctx->x_cctx->x_settings.fa_dsosuffix;

	/* .so symlink? */
	strcpy(dot,dsosuffix);

	if (!(slbt_readlinkat(fdcwd,path,lpath,sizeof(lpath))))
		if (slbt_exec_uninstall_versioned_library(
				dctx,ectx,parg,
				path,lpath,
				dsosuffix,flags))
			return SLBT_NESTED_ERROR(dctx);

	/* .lib.a symlink? */
	strcpy(dot,".lib.a");

	if (!(slbt_readlinkat(fdcwd,path,lpath,sizeof(lpath))))
		if (slbt_exec_uninstall_versioned_library(
				dctx,ectx,parg,
				path,lpath,
				".lib.a",flags))
			return SLBT_NESTED_ERROR(dctx);

	/* .dll symlink? */
	strcpy(dot,".dll");

	if (!(slbt_readlinkat(fdcwd,path,lpath,sizeof(lpath))))
		if (slbt_exec_uninstall_versioned_library(
				dctx,ectx,parg,
				path,lpath,
				".dll",flags))
			return SLBT_NESTED_ERROR(dctx);

	/* remove .so library as needed */
	strcpy(dot,dsosuffix);

	if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
		return SLBT_NESTED_ERROR(dctx);

	/* remove .lib.a import library as needed */
	strcpy(dot,".lib.a");

	if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
		return SLBT_NESTED_ERROR(dctx);

	/* remove .dll library as needed */
	strcpy(dot,".dll");

	if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
		return SLBT_NESTED_ERROR(dctx);

	/* remove .exe image as needed */
	strcpy(dot,".exe");

	if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
		return SLBT_NESTED_ERROR(dctx);

	/* remove binary image as needed */
	*dot = 0;

	if (slbt_exec_uninstall_fs_entry(dctx,ectx,parg,path,flags))
		return SLBT_NESTED_ERROR(dctx);

	return 0;
}

int slbt_exec_uninstall(const struct slbt_driver_ctx * dctx)
{
	int				fdout;
	char **				argv;
	char **				iargv;
	uint32_t			flags;
	struct slbt_exec_ctx *		ectx;
	struct argv_meta *		meta;
	struct argv_entry *		entry;
	const struct argv_option *	optv[SLBT_OPTV_ELEMENTS];

	/* dry run */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_DRY_RUN)
		return 0;

	/* context */
	if (slbt_ectx_get_exec_ctx(dctx,&ectx) < 0)
		return  SLBT_NESTED_ERROR(dctx);

	/* initial state, uninstall mode skin */
	slbt_ectx_reset_arguments(ectx);
	slbt_disable_placeholders(ectx);
	iargv = ectx->x_cargv;
	fdout = slbt_driver_fdout(dctx);

	/* missing arguments? */
	slbt_optv_init(slbt_uninstall_options,optv);

	if (!iargv[1] && (dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_USAGE))
		return slbt_uninstall_usage(
			fdout,
			dctx->x_program,
			0,optv,0,
			dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER);

	/* <uninstall> argv meta */
	if (!(meta = slbt_argv_get(
			iargv,optv,
			dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS
				? ARGV_VERBOSITY_ERRORS
				: ARGV_VERBOSITY_NONE,
			fdout)))
		return slbt_exec_uninstall_fail(
			ectx,meta,
			SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_UNINSTALL_FAIL));

	/* dest, alternate argument vector options */
	argv  = ectx->x_altv;
	flags = 0;

	*argv++ = iargv[0];

	for (entry=meta->entries; entry->fopt || entry->arg; entry++) {
		if (entry->fopt) {
			switch (entry->tag) {
				case TAG_UNINSTALL_SYSROOT:
					break;

				case TAG_UNINSTALL_HELP:
					flags |= SLBT_UNINSTALL_HELP;
					break;

				case TAG_UNINSTALL_VERSION:
					flags |= SLBT_UNINSTALL_VERSION;
					break;

				case TAG_UNINSTALL_FORCE:
					*argv++ = "-f";
					flags |= SLBT_UNINSTALL_FORCE;
					break;

				case TAG_UNINSTALL_RMDIR:
					*argv++ = "-d";
					flags |= SLBT_UNINSTALL_RMDIR;
					break;

				case TAG_UNINSTALL_VERBOSE:
					*argv++ = "-v";
					flags |= SLBT_UNINSTALL_VERBOSE;
					break;
			}
		}
	}

	/* --help */
	if (flags & SLBT_UNINSTALL_HELP) {
		slbt_uninstall_usage(
			fdout,
			dctx->x_program,
			0,optv,meta,
			dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER);
		return 0;
	}

	/* uninstall */
	ectx->x_argv    = ectx->x_altv;
	ectx->x_program = ectx->x_altv[0];

	/* uninstall entries one at a time */
	for (entry=meta->entries; entry->fopt || entry->arg; entry++)
		if (!entry->fopt)
			if (slbt_exec_uninstall_entry(dctx,ectx,entry,argv,flags))
				return slbt_exec_uninstall_fail(
					ectx,meta,
					SLBT_NESTED_ERROR(dctx));

	slbt_argv_free(meta);
	slbt_ectx_free_exec_ctx(ectx);

	return 0;
}
