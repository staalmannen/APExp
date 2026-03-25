/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_errinfo_impl.h"

/* legacy fallback, no longer in use */
extern int slbt_util_import_archive_mri(
	struct slbt_exec_ctx *  ectx,
	char *			dstarchive,
	char *			srcarchive);

/* use slibtool's in-memory archive merging facility */
static int slbt_util_import_archive_impl(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_exec_ctx *	ectx,
	char *				dstarchive,
	char *				srcarchive)
{
	int                             ret;
	struct slbt_archive_ctx *       arctxv[3] = {0,0,0};
	struct slbt_archive_ctx *       arctx;

	(void)ectx;

	if (slbt_ar_get_archive_ctx(dctx,dstarchive,&arctxv[0]) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if (slbt_ar_get_archive_ctx(dctx,srcarchive,&arctxv[1]) < 0) {
		slbt_ar_free_archive_ctx(arctxv[0]);
		return SLBT_NESTED_ERROR(dctx);
	}

	ret = slbt_ar_merge_archives(arctxv,&arctx);

	slbt_ar_free_archive_ctx(arctxv[0]);
	slbt_ar_free_archive_ctx(arctxv[1]);

	if (ret == 0) {
		ret = slbt_ar_store_archive(arctx,dstarchive,0644);
		slbt_ar_free_archive_ctx(arctx);
	}

	return (ret < 0) ? SLBT_NESTED_ERROR(dctx) : 0;
}


int slbt_util_import_archive(
	const struct slbt_exec_ctx *    ectx,
	char *				dstarchive,
	char *				srcarchive)
{
	const struct slbt_driver_ctx *	dctx;

	dctx = (slbt_get_exec_ictx(ectx))->dctx;

	if (slbt_symlink_is_a_placeholder(
			slbt_driver_fdcwd(dctx),
			srcarchive))
		return 0;

	return slbt_util_import_archive_impl(
		dctx,ectx,
		dstarchive,
		srcarchive);
}
