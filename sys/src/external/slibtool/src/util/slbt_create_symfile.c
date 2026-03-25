/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <time.h>
#include <locale.h>
#include <regex.h>
#include <inttypes.h>
#include <slibtool/slibtool.h>
#include <slibtool/slibtool_output.h>
#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_pecoff_impl.h"
#include "slibtool_ar_impl.h"

/********************************************************/
/* Clone a symbol list that could be used by a build    */
/* system for code generation or any other purpose.     */
/********************************************************/

static int slbt_util_output_symfile_impl(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_symlist_ctx * sctx,
	int                             fdout)
{
	const char **   symv;
	const char **   symstrv;

	symstrv = sctx->x_symstrv;

	for (symv=symstrv; *symv; symv++)
		if (slbt_dprintf(fdout,"%s\n",*symv) < 0)
			return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}


static int slbt_util_create_symfile_impl(
	const struct slbt_symlist_ctx *   sctx,
	const char *                      path,
	mode_t                            mode)
{
	int                             ret;
	const struct slbt_driver_ctx *  dctx;
	struct slbt_fd_ctx              fdctx;
	int                             fdout;

	dctx = (slbt_get_symlist_ictx(sctx))->dctx;

	if (slbt_lib_get_driver_fdctx(dctx,&fdctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if (path) {
		if ((fdout = openat(
				fdctx.fdcwd,path,
				O_WRONLY|O_CREAT|O_TRUNC,
				mode)) < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else {
		fdout = fdctx.fdout;
	}

	ret = slbt_util_output_symfile_impl(
		dctx,sctx,fdout);

	if (path) {
		close(fdout);
	}

	return ret;
}


int slbt_util_create_symfile(
	const struct slbt_symlist_ctx *   sctx,
	const char *                      path,
	mode_t                            mode)
{
	return slbt_util_create_symfile_impl(sctx,path,mode);
}
