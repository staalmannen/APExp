/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>

int slbt_au_output_mapfile(const struct slbt_archive_meta * meta)
{
	return slbt_ar_create_mapfile(meta,0,0);
}
