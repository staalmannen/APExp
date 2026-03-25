/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>

int slbt_output_mapfile(const struct slbt_symlist_ctx * sctx)
{
	return slbt_util_create_mapfile(sctx,0,0);
}
