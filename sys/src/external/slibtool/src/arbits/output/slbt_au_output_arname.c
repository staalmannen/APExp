/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>
#include <slibtool/slibtool_output.h>
#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_ar_impl.h"

#define SLBT_PRETTY_FLAGS       (SLBT_PRETTY_YAML      \
	                         | SLBT_PRETTY_POSIX    \
	                         | SLBT_PRETTY_HEXDATA)

static int slbt_au_output_arname_impl(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_archive_ctx * actx,
	const struct slbt_fd_ctx *      fdctx,
	const char *                    fmt)
{
	const char * path;
	const char   mema[] = "<memory_object>";

	path = actx->x_path && *actx->x_path ? *actx->x_path : mema;

	if (slbt_dprintf(fdctx->fdout,fmt,path) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}

static int slbt_au_output_arname_posix(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_archive_ctx * actx,
	const struct slbt_fd_ctx *      fdctx)
{
	if (slbt_au_output_arname_impl(
			dctx,actx,fdctx,
			"%s:\n") < 0)
		return SLBT_NESTED_ERROR(dctx);

	return 0;
}

static int slbt_au_output_arname_yaml(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_archive_ctx * actx,
	const struct slbt_fd_ctx *      fdctx)
{
	if (slbt_au_output_arname_impl(
			dctx,actx,fdctx,
			"Archive:\n"
			"  - Meta:\n"
			"    - [ name: %s ]\n\n") < 0)
		return SLBT_NESTED_ERROR(dctx);

	return 0;
}

int slbt_au_output_arname(const struct slbt_archive_ctx * actx)
{
	const struct slbt_driver_ctx *  dctx;
	struct slbt_fd_ctx              fdctx;

	dctx = (slbt_get_archive_ictx(actx))->dctx;

	if (slbt_lib_get_driver_fdctx(dctx,&fdctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	switch (dctx->x_cctx->x_fmtflags & SLBT_PRETTY_FLAGS) {
		case SLBT_PRETTY_YAML:
			return slbt_au_output_arname_yaml(
				dctx,actx,&fdctx);

		case SLBT_PRETTY_POSIX:
			return slbt_au_output_arname_posix(
				dctx,actx,&fdctx);

		default:
			return slbt_au_output_arname_yaml(
				dctx,actx,&fdctx);
	}
}
