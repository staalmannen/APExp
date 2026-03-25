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

/****************************************************/
/* Generate a linker version script (aka mapfile)   */
/* that could be passed to the host linker.         */
/*                                                  */
/* Since the provided symbol list is host-neautral, */
/* prepend symbol names with an underscore whenever */
/* necessary.                                       */
/****************************************************/

static int slbt_util_output_mapfile_impl(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_symlist_ctx * sctx,
	int                             fdout)
{
	bool            fcoff;
	bool            fmach;
	const char *    dot;
	const char *    mark;
	const char **   symv;
	const char **   symstrv;
	char            strbuf[4096];

	fcoff = slbt_host_objfmt_is_coff(dctx);
	fmach = slbt_host_objfmt_is_macho(dctx);

	if (fcoff) {
		if (slbt_dprintf(fdout,"EXPORTS\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else if (fmach) {
		if (slbt_dprintf(fdout,"# export_list, underscores prepended\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else {
		if (slbt_dprintf(fdout,"{\n" "\t" "global:\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	}

	symstrv = sctx->x_symstrv;

	for (symv=symstrv; *symv; symv++) {
		if (fcoff && slbt_is_strong_coff_symbol(*symv)) {
			if (slbt_dprintf(fdout,"%s\n",*symv) < 0)
				return SLBT_SYSTEM_ERROR(dctx);

		} else if (fcoff && !strncmp(*symv,".weak.",6)) {
			mark = &(*symv)[6];
			dot  = strchr(mark,'.');

			strncpy(strbuf,mark,dot-mark);
			strbuf[dot-mark] = '\0';

			if (slbt_dprintf(fdout,"    %s = %s\n",strbuf,++dot) < 0)
				return SLBT_SYSTEM_ERROR(dctx);

		} else if (fmach) {
			if (slbt_dprintf(fdout,"_%s\n",*symv) < 0)
				return SLBT_SYSTEM_ERROR(dctx);

		} else {
			if (slbt_dprintf(fdout,"\t\t%s;\n",*symv) < 0)
				return SLBT_SYSTEM_ERROR(dctx);
		}
	}

	if (!fcoff && !fmach)
		if (slbt_dprintf(fdout,"\n\t" "local:\n" "\t\t*;\n" "};\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}


static int slbt_util_create_mapfile_impl(
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

	ret = slbt_util_output_mapfile_impl(
		dctx,sctx,fdout);

	if (path) {
		close(fdout);
	}

	return ret;
}


int slbt_util_create_mapfile(
	const struct slbt_symlist_ctx *   sctx,
	const char *                      path,
	mode_t                            mode)
{
	return slbt_util_create_mapfile_impl(sctx,path,mode);
}
