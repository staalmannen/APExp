#ifndef SLIBTOOL_METAFILE_IMPL_H
#define SLIBTOOL_METAFILE_IMPL_H

#include <slibtool/slibtool.h>

int  slbt_create_object_wrapper(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx);

int  slbt_create_library_wrapper(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			arname,
	const char *			soname,
	const char *			soxyz,
	const char *			solnk);

#endif
