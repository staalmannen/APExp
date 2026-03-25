/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_readlink_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_visibility_impl.h"

#define SLBT_DEV_NULL_FLAGS	(SLBT_DRIVER_ALL_STATIC      \
				| SLBT_DRIVER_DISABLE_SHARED \
				| SLBT_DRIVER_DISABLE_STATIC)

slbt_hidden int slbt_create_symlink_ex(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	int                             fddst,
	const char *			target,
	const char *			lnkname,
	uint32_t			options)
{
	int		fliteral;
	int		fwrapper;
	int		fdevnull;
	size_t          slen;
	char **		oargv;
	const char *	slash;
	char *		ln[5];
	char *          dot;
	char *		dotdot;
	char *          mark;
	char		tmplnk [PATH_MAX];
	char		lnkarg [PATH_MAX];
	char		alnkarg[PATH_MAX];
	char		atarget[PATH_MAX];
	char *		suffix = 0;

	/* options */
	fliteral = (options & SLBT_SYMLINK_LITERAL);
	fwrapper = (options & SLBT_SYMLINK_WRAPPER);
	fdevnull = (options & SLBT_SYMLINK_DEVNULL);

	/* symlink is a placeholder? */
	if (fliteral) {
		slash = target;

	/* .disabled .so or .a file */
	} else if (fdevnull) {
		slash  = target;
		suffix = ".disabled";

	/* symlink target contains a dirname? */
	} else if ((slash = strrchr(target,'/'))) {
		slash++;

	/* symlink target is a basename */
	} else {
		slash = target;
	}

	/* .la wrapper? */
	dotdot = fwrapper ? "../" : "";

	/* atarget */
	if (slbt_snprintf(atarget,sizeof(atarget),
			"%s%s",dotdot,slash) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* tmplnk */
	if (slbt_snprintf(tmplnk,sizeof(tmplnk),
			"%s.symlink.tmp",
			lnkname) <0)
		return SLBT_BUFFER_ERROR(dctx);

	/* placeholder? */
	if (fdevnull) {
		if (unlinkat(fddst,lnkname,0) && (errno != ENOENT))
			return SLBT_SYSTEM_ERROR(dctx);

		if ((dot = strrchr(lnkname,'.'))) {
			if (!strcmp(dot,dctx->x_cctx->x_settings.fa_dsosuffix)) {
				strcpy(dot,".expsyms.a");

				if (unlinkat(fddst,lnkname,0) && (errno != ENOENT))
					return SLBT_SYSTEM_ERROR(dctx);

				strcpy(dot,dctx->x_cctx->x_settings.fa_dsosuffix);
			}
		}
	}

	if (suffix) {
		sprintf(alnkarg,"%s%s",lnkname,suffix);
		lnkname = alnkarg;
	}

	/* lnkarg */
	if (fddst == slbt_driver_fdcwd(dctx)) {
		strcpy(lnkarg,lnkname);
	} else {
		if (slbt_realpath(fddst,".",0,lnkarg,sizeof(lnkarg)) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		if ((slen = strlen(lnkarg)) + strlen(lnkname) + 1 >= PATH_MAX)
			return SLBT_BUFFER_ERROR(dctx);

		mark    = &lnkarg[slen];
		mark[0] = '/';
		strcpy(++mark,lnkname);
	}

	/* ln argv (fake) */
	ln[0] = "ln";
	ln[1] = "-s";
	ln[2] = atarget;
	ln[3] = lnkarg;
	ln[4] = 0;

	oargv      = ectx->x_argv;
	ectx->x_argv = ln;

	/* step output */
	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT)) {
		if (dctx->x_cctx->x_mode == SLBT_MODE_LINK) {
			if (slbt_output_link(ectx)) {
				ectx->x_argv = oargv;
				return SLBT_NESTED_ERROR(dctx);
			}
		} else {
			if (slbt_output_install(ectx)) {
				ectx->x_argv = oargv;
				return SLBT_NESTED_ERROR(dctx);
			}
		}
	}

	/* restore execution context */
	ectx->x_argv = oargv;

	/* create symlink */
	slbt_driver_set_ectx(
		dctx,0,
		tmplnk);

	if (symlinkat(atarget,fddst,tmplnk))
		return SLBT_SYSTEM_ERROR(dctx);

	return renameat(fddst,tmplnk,fddst,lnkname)
		? SLBT_SYSTEM_ERROR(dctx)
		: 0;
}

slbt_hidden int slbt_create_symlink(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			target,
	const char *			lnkname,
	uint32_t			options)
{
	return slbt_create_symlink_ex(
		dctx,ectx,
		slbt_driver_fdcwd(dctx),
		target,lnkname,options);
}

slbt_hidden int slbt_symlink_is_a_placeholder(int fdcwd, const char * lnkpath)
{
	size_t		len;
	char		slink [PATH_MAX];
	char		target[PATH_MAX];
	const char	suffix[] = ".disabled";

	if ((sizeof(slink)-sizeof(suffix)) < (len=strlen(lnkpath)))
		return 0;

	memcpy(slink,lnkpath,len);
	memcpy(&slink[len],suffix,sizeof(suffix));

	return (!slbt_readlinkat(fdcwd,slink,target,sizeof(target)))
		&& (!strcmp(target,"/dev/null"));
}
