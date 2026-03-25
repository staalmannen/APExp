/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_spawn_impl.h"
#include "slibtool_mkdir_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_metafile_impl.h"

static int slbt_exec_compile_remove_file(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			target)
{
	int fdcwd;

	(void)ectx;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* remove target (if any) */
	if (!unlinkat(fdcwd,target,0) || (errno == ENOENT))
		return 0;

	return SLBT_SYSTEM_ERROR(dctx);
}

static int slbt_exec_compile_finalize_argument_vector(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx)
{
	char *		sargv[1024];
	char **		sargvbuf;
	char **		base;
	char **		parg;
	char **		aarg;
	char **		aargv;
	char **		cap;
	char **		src;
	char **		dst;
	char **		cmp;
	char *		ccwrap;
	char *          custom;

	/* vector size */
	base = ectx->x_argv;
	parg = ectx->x_argv;

	for (; *parg; )
		parg++;

	/* buffer */
	if (parg - base < 1024) {
		aargv    = sargv;
		aarg     = aargv;
		sargvbuf = 0;

	} else if (!(sargvbuf = calloc(parg-base+1,sizeof(char *)))) {
		return SLBT_SYSTEM_ERROR(dctx);

	} else {
		aargv = sargvbuf;
		aarg  = aargv;
	}

	/* (program name) */
	parg = &base[1];

	/* avoid -I deduplication with project specific drivers */
	custom = strchr(ectx->x_program,'/');

	/* split object args from all other args, record output */
	/* annotation, and remove redundant -l arguments       */
	for (; *parg; ) {
		if (ectx->x_lout[0] == parg) {
			ectx->x_lout[0] = &aarg[0];
			ectx->x_lout[1] = &aarg[1];
		}

		if (ectx->x_mout[0] == parg) {
			ectx->x_mout[0] = &aarg[0];
			ectx->x_mout[1] = &aarg[1];
		}

		/* placeholder argument? */
		if (!strncmp(*parg,"-USLIBTOOL_PLACEHOLDER_",23)) {
			parg++;
		} else {
			*aarg++ = *parg++;
		}
	}

	/* program name, ccwrap */
	if ((ccwrap = (char *)dctx->x_cctx->x_ccwrap)) {
		base[1] = base[0];
		base[0] = ccwrap;
		base++;
	}

	/* join all other args, starting with de-duplicated -I arguments, */
	/* and filter out all -f switches when compiling in --tag=RC mode */
	src = aargv;
	cap = aarg;
	dst = &base[1];

	for (; !custom && src<cap; ) {
		if (((*src)[0] == '-') && ((*src)[1] == 'I')) {
			cmp = &base[1];

			for (; cmp && cmp<dst; ) {
				if (!strcmp(*src,*cmp)) {
					cmp = 0;
				} else {
					cmp++;
				}
			}

			if (cmp)
				*dst++ = *src;
		}

		src++;
	}

	src = aargv;

	for (; src<cap; ) {
		if ((dctx->x_cctx->x_tag == SLBT_TAG_RC)
				&& ((*src)[0] == '-')
				&& ((*src)[1] == 'f'))
			(void)0;

		else if (((*src)[0] != '-') || ((*src)[1] != 'I'))
			*dst++ = *src;

		else if (custom)
			*dst++ = *src;

		src++;
	}

	/* properly null-terminate argv, accounting for redundant arguments */
	*dst = 0;

	/* output annotation */
	if (ectx->x_lout[0]) {
		ectx->x_lout[0] = &base[1] + (ectx->x_lout[0] - aargv);
		ectx->x_lout[1] = ectx->x_lout[0] + 1;
	}

	if (ectx->x_mout[0]) {
		ectx->x_mout[0] = &base[1] + (ectx->x_mout[0] - aargv);
		ectx->x_mout[1] = ectx->x_mout[0] + 1;
	}

	/* all done */
	if (sargvbuf)
		free(sargvbuf);

	return 0;
}

int  slbt_exec_compile(const struct slbt_driver_ctx * dctx)
{
	int				ret;
	char *				fpic;
	char *				ccwrap;
	bool                            fshared;
	bool                            fstatic;
	struct slbt_exec_ctx *		ectx;
	const struct slbt_common_ctx *	cctx = dctx->x_cctx;

	/* dry run */
	if (cctx->x_drvflags & SLBT_DRIVER_DRY_RUN)
		return 0;

	/* context */
	if (slbt_ectx_get_exec_ctx(dctx,&ectx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* remove old .lo wrapper */
	if (slbt_exec_compile_remove_file(dctx,ectx,ectx->x_ltobjname))
		return SLBT_NESTED_ERROR(dctx);

	/* fshared, fstatic */
	fshared = (cctx->x_drvflags & (SLBT_DRIVER_SHARED | SLBT_DRIVER_PREFER_SHARED));
	fstatic = (cctx->x_drvflags & (SLBT_DRIVER_STATIC | SLBT_DRIVER_PREFER_STATIC));

	/* .libs directory */
	if (fshared) {
		slbt_driver_set_ectx(
			dctx,0,
			ectx->x_ldirname);

		if (slbt_mkdir(dctx,ectx->x_ldirname)) {
			ret = SLBT_SYSTEM_ERROR(dctx);
			slbt_ectx_free_exec_ctx(ectx);
			return ret;
		}
	}

	/* compile mode */
	ccwrap        = (char *)cctx->x_ccwrap;
	ectx->x_program = ccwrap ? ccwrap : ectx->x_compiler;
	ectx->x_argv    = ectx->x_cargv;

	/* -fpic */
	switch (cctx->x_tag) {
		case SLBT_TAG_CC:
		case SLBT_TAG_CXX:
		case SLBT_TAG_F77:
		case SLBT_TAG_FC:
			fpic = cctx->x_settings.fa_picswitch
				? cctx->x_settings.fa_picswitch
				: *ectx->x_fpic;
			break;

		default:
			fpic = *ectx->x_fpic;
	}

	/* shared library object */
	if (fshared) {
		if (!(cctx->x_drvflags & SLBT_DRIVER_ANTI_PIC)) {
			*ectx->x_dpic = "-DPIC";
			*ectx->x_fpic = fpic;
		}

		*ectx->x_lout[0] = "-o";
		*ectx->x_lout[1] = ectx->x_lobjname;

		if (slbt_exec_compile_finalize_argument_vector(dctx,ectx))
			return SLBT_NESTED_ERROR(dctx);

		if (!(cctx->x_drvflags & SLBT_DRIVER_SILENT)) {
			if (slbt_output_compile(ectx)) {
				slbt_ectx_free_exec_ctx(ectx);
				return SLBT_NESTED_ERROR(dctx);
			}
		}

		if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
			slbt_ectx_free_exec_ctx(ectx);
			return SLBT_SYSTEM_ERROR(dctx);

		} else if (ectx->x_exitcode) {
			slbt_ectx_free_exec_ctx(ectx);
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_COMPILE_ERROR);
		}

		if (fstatic)
			slbt_ectx_reset_argvector(ectx);
	}

	/* static archive object */
	if (fstatic) {
		slbt_reset_placeholders(ectx);

		if (cctx->x_drvflags & SLBT_DRIVER_PRO_PIC) {
			*ectx->x_dpic = "-DPIC";
			*ectx->x_fpic = fpic;
		}

		*ectx->x_lout[0] = "-o";
		*ectx->x_lout[1] = ectx->x_aobjname;

		if (slbt_exec_compile_finalize_argument_vector(dctx,ectx))
			return SLBT_NESTED_ERROR(dctx);

		if (!(cctx->x_drvflags & SLBT_DRIVER_SILENT)) {
			if (slbt_output_compile(ectx)) {
				slbt_ectx_free_exec_ctx(ectx);
				return SLBT_NESTED_ERROR(dctx);
			}
		}

		if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
			slbt_ectx_free_exec_ctx(ectx);
			return SLBT_SYSTEM_ERROR(dctx);

		} else if (ectx->x_exitcode) {
			slbt_ectx_free_exec_ctx(ectx);
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_COMPILE_ERROR);
		}
	}

	ret = slbt_create_object_wrapper(dctx,ectx);
	slbt_ectx_free_exec_ctx(ectx);

	return ret ? SLBT_NESTED_ERROR(dctx) : 0;
}
