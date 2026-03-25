/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_linkcmd_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_metafile_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_exec_link_create_host_tag(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	char *				deffilename)
{
	char *  slash;
	char	hosttag[PATH_MAX];
	char	hostlnk[PATH_MAX];

	/* libfoo.so.def.{flavor} */
	if (slbt_snprintf(hosttag,
			sizeof(hosttag),
			"%s.%s",
			deffilename,
			dctx->x_cctx->x_host.ha_flavor) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	if (slbt_snprintf(hostlnk,
			sizeof(hostlnk),
			"%s.host",
			deffilename) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* libfoo.so.def is under .libs/ */
	if (!(slash = strrchr(deffilename,'/')))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_LINK_FLOW);

	if (slbt_create_symlink(
		dctx,ectx,
		deffilename,
		hosttag,
		SLBT_SYMLINK_DEFAULT))
	return SLBT_NESTED_ERROR(dctx);

	/* libfoo.so.def.{flavor} is under .libs/ */
	if (!(slash = strrchr(hosttag,'/')))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_LINK_FLOW);

	if (slbt_create_symlink(
			dctx,ectx,
			++slash,
			hostlnk,
			SLBT_SYMLINK_DEFAULT))
		return SLBT_NESTED_ERROR(dctx);

	return 0;
}
