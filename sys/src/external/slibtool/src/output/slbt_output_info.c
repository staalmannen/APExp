/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_errinfo_impl.h"

#ifndef SLBT_TAB_WIDTH
#define SLBT_TAB_WIDTH 8
#endif

#ifndef SLBT_KEY_WIDTH
#define SLBT_KEY_WIDTH 16
#endif

static bool slbt_output_info_line(
	int		fd,
	const char *	key,
	const char *	value,
	const char *	annotation,
	int		midwidth)
{
	return (slbt_dprintf(fd,"%-*s%-*s%s\n",
			SLBT_KEY_WIDTH, key,
			midwidth, value ? value : "",
			annotation ? annotation : "") < 0)
		? true : false;
}

int slbt_output_info(const struct slbt_driver_ctx * dctx)
{
	const struct slbt_common_ctx *	cctx;
	const char *			compiler;
	const char *			target;
	int				len;
	int				midwidth;
	int				fdout;

	cctx     = dctx->x_cctx;
	compiler = cctx->x_cargv[0] ? cctx->x_cargv[0] : "";
	target   = cctx->x_target   ? cctx->x_target   : "";
	midwidth = strlen(compiler);
	fdout    = slbt_driver_fdout(dctx);

	if ((len = strlen(target)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_host)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_flavor)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_ar)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_as)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_nm)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_ranlib)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_windres)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_dlltool)) > midwidth)
		midwidth = len;

	if ((len = strlen(cctx->x_host.ha_mdso)) > midwidth)
		midwidth = len;

	midwidth += SLBT_TAB_WIDTH;
	midwidth &= (~(SLBT_TAB_WIDTH-1));

	if (slbt_output_info_line(fdout,"key","value","annotation",midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"---","-----","----------",midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"compiler",cctx->x_cargv[0],"",midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"target",cctx->x_target,"",midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"host",cctx->x_host.ha_host,cctx->x_cfgmeta.ha_host,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"flavor",cctx->x_host.ha_flavor,cctx->x_cfgmeta.ha_flavor,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"ar",cctx->x_host.ha_ar,cctx->x_cfgmeta.ha_ar,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"as",cctx->x_host.ha_as,cctx->x_cfgmeta.ha_as,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"nm",cctx->x_host.ha_nm,cctx->x_cfgmeta.ha_nm,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"ranlib",cctx->x_host.ha_ranlib,cctx->x_cfgmeta.ha_ranlib,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"windres",cctx->x_host.ha_windres,cctx->x_cfgmeta.ha_windres,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"dlltool",cctx->x_host.ha_dlltool,cctx->x_cfgmeta.ha_dlltool,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_output_info_line(fdout,"mdso",cctx->x_host.ha_mdso,cctx->x_cfgmeta.ha_mdso,midwidth))
		return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}
