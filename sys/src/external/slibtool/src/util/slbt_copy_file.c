/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_errinfo_impl.h"

int slbt_util_copy_file(
	struct slbt_exec_ctx *	ectx,
	const char *		from,
	const char *		to)
{
	int	ret;
	int	fdcwd;
	char **	oargv;
	char *	oprogram;
	char *  src;
	char *  dst;
	char *	cp[4];

	const struct slbt_driver_ctx *  dctx;

	/* driver context */
	dctx = (slbt_get_exec_ictx(ectx))->dctx;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* placeholder? */
	if (slbt_symlink_is_a_placeholder(fdcwd,from))
		return 0;

	/* until we perform an in-memory copy ... */
	if (!(src = strdup(from)))
		return SLBT_SYSTEM_ERROR(dctx);

	if (!(dst = strdup(to))) {
		free(src);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* cp argv */
	cp[0] = "cp";
	cp[1] = src;
	cp[2] = dst;
	cp[3] = 0;

	/* alternate argument vector */
	oprogram      = ectx->x_program;
	oargv         = ectx->x_argv;
	ectx->x_argv    = cp;
	ectx->x_program = "cp";

	/* step output */
	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT)) {
		if (dctx->x_cctx->x_mode == SLBT_MODE_LINK) {
			if (slbt_output_link(ectx)) {
				ectx->x_argv = oargv;
				ectx->x_program = oprogram;
				free(src); free(dst);
				return SLBT_NESTED_ERROR(dctx);
			}
		} else {
			if (slbt_output_install(ectx)) {
				ectx->x_argv = oargv;
				ectx->x_program = oprogram;
				free(src); free(dst);
				return SLBT_NESTED_ERROR(dctx);
			}
		}
	}

	/* cp spawn */
	if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
		ret = SLBT_SPAWN_ERROR(dctx);

	} else if (ectx->x_exitcode) {
		ret = SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_COPY_ERROR);
	} else {
		ret = 0;
	}

	free(src);
	free(dst);

	ectx->x_argv = oargv;
	ectx->x_program = oprogram;
	return ret;
}
