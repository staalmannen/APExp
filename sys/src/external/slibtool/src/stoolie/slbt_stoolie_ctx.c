/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_stoolie_impl.h"
#include "slibtool_txtline_impl.h"
#include "slibtool_m4fake_impl.h"

static const char slbt_this_dir[2] = {'.',0};

static int slbt_st_free_stoolie_ctx_impl(
	struct slbt_stoolie_ctx_impl *  ctx,
	int                             fdsrc,
	int                             ret)
{
	char ** parg;

	if (ctx) {
		if (fdsrc >= 0)
			close(fdsrc);

		if (ctx->fdtgt >= 0)
			close(ctx->fdtgt);

		if (ctx->fdaux >= 0)
			close(ctx->fdaux);

		if (ctx->fdm4 >= 0)
			close(ctx->fdm4);

		if (ctx->fdltdl >= 0)
			close(ctx->fdltdl);

		for (parg=ctx->m4argv; parg && *parg; parg++)
			free(*parg);

		free(ctx->m4buf);
		free(ctx->m4argv);
		free(ctx->auxbuf);
		free(ctx->ltdlbuf);
		free(ctx->pathbuf);

		slbt_lib_free_txtfile_ctx(ctx->acinc);
		slbt_lib_free_txtfile_ctx(ctx->cfgac);
		slbt_lib_free_txtfile_ctx(ctx->makam);

		free(ctx);
	}

	return ret;
}

int slbt_st_get_stoolie_ctx(
	const struct slbt_driver_ctx *	dctx,
	const char *			path,
	struct slbt_stoolie_ctx **	pctx)
{
	struct slbt_stoolie_ctx_impl *	ctx;
	int                             cint;
	int                             fdcwd;
	int                             fdtgt;
	int                             fdsrc;
	int                             fltdl;
	const char *                    ltdlarg;
	const char **                   pline;
	char **                         margv;
	const char *                    mark;
	const char *                    dpath;
	char                            pathbuf[PATH_MAX];

	/* target directory: fd and real path*/
	fdcwd = slbt_driver_fdcwd(dctx);

	slbt_driver_set_ectx(
		dctx,0,path);

	if ((fdtgt = openat(fdcwd,path,O_DIRECTORY|O_CLOEXEC,0)) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_realpath(fdtgt,".",0,pathbuf,sizeof(pathbuf)) < 0) {
		close(fdtgt);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* context alloc and init */
	if (!(ctx = calloc(1,sizeof(*ctx)))) {
		close(fdtgt);
		return SLBT_BUFFER_ERROR(dctx);
	}

	ctx->fdtgt = fdtgt;
	ctx->fdaux = (-1);
	ctx->fdm4  = (-1);
	ctx->fdltdl= (-1);

	/* target directory real path */
	if (!(ctx->pathbuf = strdup(pathbuf)))
		return slbt_st_free_stoolie_ctx_impl(ctx,(-1),
			SLBT_NESTED_ERROR(dctx));

	/* acinclude.m4, configure.ac, Makefile.am */
	slbt_driver_set_ectx(
		dctx,0,
		"acinclude.m4");

	if ((fdsrc = openat(fdtgt,"acinclude.m4",O_RDONLY,0)) < 0) {
		if (errno != ENOENT)
			return slbt_st_free_stoolie_ctx_impl(ctx,fdsrc,
				SLBT_SYSTEM_ERROR(dctx));
	} else {
		if (slbt_impl_get_txtfile_ctx(dctx,"acinclude.m4",fdsrc,&ctx->acinc) < 0)
			return slbt_st_free_stoolie_ctx_impl(ctx,fdsrc,
				SLBT_NESTED_ERROR(dctx));

		close(fdsrc);
	}

	slbt_driver_set_ectx(
		dctx,0,
		"configure.ac");

	if ((fdsrc = openat(fdtgt,"configure.ac",O_RDONLY,0)) < 0) {
		if (errno != ENOENT)
			return slbt_st_free_stoolie_ctx_impl(ctx,fdsrc,
				SLBT_SYSTEM_ERROR(dctx));
	} else {
		if (slbt_impl_get_txtfile_ctx(dctx,"configure.ac",fdsrc,&ctx->cfgac) < 0)
			return slbt_st_free_stoolie_ctx_impl(ctx,fdsrc,
				SLBT_NESTED_ERROR(dctx));

		close(fdsrc);
	}

	slbt_driver_set_ectx(
		dctx,0,
		"Makefile.am");

	if ((fdsrc = openat(fdtgt,"Makefile.am",O_RDONLY,0)) < 0) {
		if (errno != ENOENT)
			return slbt_st_free_stoolie_ctx_impl(ctx,fdsrc,
				SLBT_SYSTEM_ERROR(dctx));
	} else {
		if (slbt_impl_get_txtfile_ctx(dctx,"Makefile.am",fdsrc,&ctx->makam) < 0)
			return slbt_st_free_stoolie_ctx_impl(ctx,fdsrc,
				SLBT_NESTED_ERROR(dctx));

		close(fdsrc);
	}

	/* aux dir */
	if (ctx->acinc) {
		if (slbt_m4fake_expand_cmdarg(
				dctx,ctx->acinc,
				"AC_CONFIG_AUX_DIR",
				&pathbuf) < 0)
			return slbt_st_free_stoolie_ctx_impl(
				ctx,(-1),
				SLBT_NESTED_ERROR(dctx));

		if (pathbuf[0])
			if (!(ctx->auxbuf = strdup(pathbuf)))
				return slbt_st_free_stoolie_ctx_impl(
					ctx,(-1),
					SLBT_NESTED_ERROR(dctx));
	}

	if (!ctx->auxbuf && ctx->cfgac) {
		if (slbt_m4fake_expand_cmdarg(
				dctx,ctx->cfgac,
				"AC_CONFIG_AUX_DIR",
				&pathbuf) < 0)
			return slbt_st_free_stoolie_ctx_impl(
				ctx,(-1),
				SLBT_NESTED_ERROR(dctx));

		if (pathbuf[0])
			if (!(ctx->auxbuf = strdup(pathbuf)))
				return slbt_st_free_stoolie_ctx_impl(
					ctx,(-1),
					SLBT_NESTED_ERROR(dctx));
	}

	/* m4 dir */
	if (ctx->acinc) {
		if (slbt_m4fake_expand_cmdarg(
				dctx,ctx->acinc,
				"AC_CONFIG_MACRO_DIR",
				&pathbuf) < 0)
			return slbt_st_free_stoolie_ctx_impl(
				ctx,(-1),
				SLBT_NESTED_ERROR(dctx));

		if (pathbuf[0])
			if (!(ctx->m4buf = strdup(pathbuf)))
				return slbt_st_free_stoolie_ctx_impl(
					ctx,(-1),
					SLBT_NESTED_ERROR(dctx));
	}

	if (!ctx->m4buf && ctx->cfgac) {
		if (slbt_m4fake_expand_cmdarg(
				dctx,ctx->cfgac,
				"AC_CONFIG_MACRO_DIR",
				&pathbuf) < 0)
			return slbt_st_free_stoolie_ctx_impl(
				ctx,(-1),
				SLBT_NESTED_ERROR(dctx));

		if (pathbuf[0])
			if (!(ctx->m4buf = strdup(pathbuf)))
				return slbt_st_free_stoolie_ctx_impl(
					ctx,(-1),
					SLBT_NESTED_ERROR(dctx));
	}
	if (!ctx->m4buf && ctx->makam) {
		for (pline=ctx->makam->x_txtlinev; !ctx->m4argv && *pline; pline++) {
			if (!strncmp(*pline,"ACLOCAL_AMFLAGS",15)) {
				if (isspace((cint = (*pline)[15])) || ((*pline)[15] == '=')) {
					mark = &(*pline)[15];

					for (; isspace(cint = *mark); )
						mark++;

					if (mark[0] != '=')
						return slbt_st_free_stoolie_ctx_impl(
							ctx,(-1),
							SLBT_CUSTOM_ERROR(
								dctx,
								SLBT_ERR_FLOW_ERROR));

					if (slbt_txtline_to_string_vector(++mark,&margv) < 0)
						return slbt_st_free_stoolie_ctx_impl(
							ctx,(-1),
							SLBT_CUSTOM_ERROR(
								dctx,
								SLBT_ERR_FLOW_ERROR));

					ctx->m4argv = margv;

					if (!strcmp((mark = margv[0]),"-I")) {
						ctx->m4buf = strdup(margv[1]);

					} else if (!strncmp(mark,"-I",2)) {
						ctx->m4buf = strdup(&mark[2]);
					}

					if (!ctx->m4buf)
						return slbt_st_free_stoolie_ctx_impl(
							ctx,(-1),
							SLBT_CUSTOM_ERROR(
								dctx,
								SLBT_ERR_FLOW_ERROR));
				}
			}
		}
	}

	/* ltdl dir */
	fltdl = (dctx->x_cctx->x_drvflags & SLBT_DRIVER_STOOLIE_LTDL) ? true : false;

	if (!fltdl && ctx->cfgac)
		for (pline=ctx->cfgac->x_txtlinev; !fltdl && *pline; pline++)
			if ((fltdl = !strncmp(*pline,"LTDL_INIT",9)))
				if (pline[0][9] && (pline[0][9] != '('))
					if (pline[0][9] != ' ')
						if (pline[0][9] != '\t')
							fltdl = false;

	if (fltdl && ctx->cfgac) {
		if (slbt_m4fake_expand_cmdarg(
				dctx,ctx->cfgac,
				"LT_CONFIG_LTDL_DIR",
				&pathbuf) < 0)
			return slbt_st_free_stoolie_ctx_impl(
				ctx,(-1),
				SLBT_NESTED_ERROR(dctx));

		if (pathbuf[0])
			if (!(ctx->ltdlbuf = strdup(pathbuf)))
				return slbt_st_free_stoolie_ctx_impl(
					ctx,(-1),
					SLBT_NESTED_ERROR(dctx));
	}

	if (fltdl && !ctx->ltdlbuf)
		if ((ltdlarg = (slbt_get_driver_ictx(dctx))->ltdlarg))
			if (!(ctx->ltdlbuf = strdup(ltdlarg)))
				return slbt_st_free_stoolie_ctx_impl(
					ctx,(-1),
					SLBT_NESTED_ERROR(dctx));

	if (fltdl && !ctx->ltdlbuf)
		if (!(ctx->ltdlbuf = strdup("libltdl")))
			return slbt_st_free_stoolie_ctx_impl(
				ctx,(-1),
				SLBT_NESTED_ERROR(dctx));

	/* build-aux directory */
	if (!(dpath = ctx->auxbuf))
		dpath = slbt_this_dir;

	slbt_driver_set_ectx(
		dctx,0,dpath);

	if ((ctx->fdaux = openat(fdtgt,dpath,O_DIRECTORY,0)) < 0)
		if (errno == ENOENT)
			if (!mkdirat(fdtgt,dpath,0755))
				ctx->fdaux = openat(fdtgt,dpath,O_DIRECTORY,0);

	if (ctx->fdaux < 0)
		return slbt_st_free_stoolie_ctx_impl(
			ctx,(-1),
			SLBT_SYSTEM_ERROR(dctx));

	/* m4 directory */
	if ((dpath = ctx->m4buf))
		if ((ctx->fdm4 = openat(fdtgt,dpath,O_DIRECTORY,0)) < 0)
			if (errno == ENOENT)
				if (!mkdirat(fdtgt,dpath,0755))
					ctx->fdm4 = openat(fdtgt,dpath,O_DIRECTORY,0);

	slbt_driver_set_ectx(
		dctx,0,dpath);

	if (dpath && (ctx->fdm4 < 0))
		return slbt_st_free_stoolie_ctx_impl(
			ctx,(-1),
			SLBT_SYSTEM_ERROR(dctx));

	/* ltdl directory */
	if ((dpath = fltdl ? ctx->ltdlbuf : 0))
		if ((ctx->fdltdl = openat(fdtgt,dpath,O_DIRECTORY,0)) < 0)
			if (errno == ENOENT)
				if (!mkdirat(fdtgt,dpath,0755))
					ctx->fdltdl = openat(fdtgt,dpath,O_DIRECTORY,0);

	slbt_driver_set_ectx(
		dctx,0,dpath);

	if (dpath && (ctx->fdltdl < 0))
		return slbt_st_free_stoolie_ctx_impl(
			ctx,(-1),
			SLBT_SYSTEM_ERROR(dctx));

	/* all done */
	ctx->path        = ctx->pathbuf;
	ctx->auxarg      = ctx->auxbuf;
	ctx->m4arg       = ctx->m4buf;
	ctx->ltdldir     = ctx->ltdlbuf;

	ctx->zctx.x_path   = &ctx->path;
	ctx->zctx.x_acinc  = ctx->acinc;
	ctx->zctx.x_cfgac  = ctx->cfgac;
	ctx->zctx.x_makam  = ctx->makam;
	ctx->zctx.x_auxarg = &ctx->auxarg;
	ctx->zctx.x_m4arg  = &ctx->m4arg;
	ctx->zctx.x_ltdldir= &ctx->ltdldir;

	*pctx = &ctx->zctx;
	return 0;
}

void slbt_st_free_stoolie_ctx(struct slbt_stoolie_ctx * ctx)
{
	struct slbt_stoolie_ctx_impl *	ictx;
	uintptr_t			addr;

	if (ctx) {
		addr = (uintptr_t)ctx - offsetof(struct slbt_stoolie_ctx_impl,zctx);
		ictx = (struct slbt_stoolie_ctx_impl *)addr;
		slbt_st_free_stoolie_ctx_impl(ictx,(-1),0);
	}
}
