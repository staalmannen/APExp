/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "slibtool_mkvars_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_readlink_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_visibility_impl.h"

static int slbt_get_mkvars_var(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_txtfile_ctx * tctx,
	const char *                    var,
	const char                      space,
	char                            (*val)[PATH_MAX])
{
	const char **   pline;
	const char *    mark;
	const char *    match;
	char *          ch;
	ssize_t         len;
	int             cint;

	/* init */
	match = 0;
	len   = strlen(var);

	/* search for ^var= */
	for (pline=tctx->x_txtlinev; !match && *pline; pline++) {
		if (!strncmp(*pline,var,len)) {
			if (isspace((cint = (*pline)[len])) || ((*pline)[len] == '=')) {
				mark = &(*pline)[len];

				for (; isspace(cint = *mark); )
					mark++;

				if (mark[0] != '=')
					return SLBT_CUSTOM_ERROR(
						dctx,
						SLBT_ERR_MKVARS_PARSE);

				mark++;

				for (; isspace(cint = *mark); )
					mark++;

				match = mark;
			}
		}
	}

	/* not found? */
	if (!match || !match[0]) {
		(*val)[0] = '\0';
		return 0;
	}

	/* special case the SLIBTOOL make variable */
	if (!strcmp(var,"SLIBTOOL")) {
		mark = match;
		ch   = *val;

		for (; *mark; ) {
			if (isspace(cint = *mark)) {
				*ch = '\0';
				return 0;
			}

			*ch++ = *mark++;
		}
	}

	/* validate */
	for (mark=match; *mark; mark++) {
		if ((*mark >= 'a') && (*mark <= 'z'))
			(void)0;

		else if ((*mark >= 'A') && (*mark <= 'Z'))
			(void)0;

		else if ((*mark >= '0') && (*mark <= '9'))
			(void)0;

		else if ((*mark == '+') || (*mark == '-'))
			(void)0;

		else if ((*mark == '/') || (*mark == '@'))
			(void)0;

		else if ((*mark == '.') || (*mark == '_'))
			(void)0;

		else if ((*mark == ':') || (*mark == space))
			(void)0;

		else
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_MKVARS_PARSE);
	}

	/* all done */
	strcpy(*val,match);

	return 0;
}

slbt_hidden int slbt_get_mkvars_flags(
	struct slbt_driver_ctx *	dctx,
	const char *			mkvars,
	uint64_t *			flags)
{
	struct slbt_driver_ctx_impl *   ctx;
	struct slbt_txtfile_ctx *       confctx;
	char *                          dash;
	uint64_t			optshared;
	uint64_t			optstatic;
	char                            val[PATH_MAX];

	/* driver context (ar, ranlib, cc) */
	ctx = slbt_get_driver_ictx(dctx);

	/* cache the makefile in library friendly form) */
	if (slbt_lib_get_txtfile_ctx(dctx,mkvars,&ctx->mkvarsctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	confctx = ctx->mkvarsctx;

	/* scan */
	optshared = 0;
	optstatic = 0;

	/* slibtool */
	if (slbt_get_mkvars_var(dctx,confctx,"SLIBTOOL",0,&val) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if ((dash = strrchr(val,'-'))) {
		if (!strcmp(dash,"-shared")) {
			optshared = SLBT_DRIVER_SHARED;
			optstatic = SLBT_DRIVER_DISABLE_STATIC;

		} else if (!strcmp(dash,"-static")) {
			optshared = SLBT_DRIVER_DISABLE_SHARED;
			optstatic = SLBT_DRIVER_STATIC;
		} else {
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_MKVARS_PARSE);
		}
	} else if (!strcmp(val,"false")) {
		optshared = SLBT_DRIVER_DISABLE_SHARED;
		optstatic = SLBT_DRIVER_DISABLE_STATIC;
	} else {
		optshared = SLBT_DRIVER_SHARED;
		optstatic = SLBT_DRIVER_STATIC;
	}

	*flags = optshared | optstatic;

	/* host */
	if (!ctx->cctx.x_host.ha_host) {
		if (slbt_get_mkvars_var(dctx,confctx,"host",0,&val) < 0)
			return SLBT_NESTED_ERROR(dctx);

		if (val[0] && !(ctx->host.host = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_host = ctx->host.host;
	}


	/* ar tool */
	if (!ctx->cctx.x_host.ha_ar) {
		if (slbt_get_mkvars_var(dctx,confctx,"AR",0x20,&val) < 0)
			return SLBT_NESTED_ERROR(dctx);

		if (val[0] && !(ctx->host.ar = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_ar = ctx->host.ar;
	}


	/* nm tool */
	if (!ctx->cctx.x_host.ha_nm) {
		if (slbt_get_mkvars_var(dctx,confctx,"NM",0x20,&val) < 0)
			return SLBT_NESTED_ERROR(dctx);

		if (val[0] && !(ctx->host.nm = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_nm = ctx->host.nm;
	}


	/* ranlib tool */
	if (!ctx->cctx.x_host.ha_ranlib) {
		if (slbt_get_mkvars_var(dctx,confctx,"RANLIB",0x20,&val) < 0)
			return SLBT_NESTED_ERROR(dctx);

		if (val[0] && !(ctx->host.ranlib = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_ranlib = ctx->host.ranlib;
	}


	/* as tool (optional) */
	if (!ctx->cctx.x_host.ha_as) {
		if (slbt_get_mkvars_var(dctx,confctx,"AS",0x20,&val) < 0)
			return SLBT_NESTED_ERROR(dctx);

		if (val[0] && !(ctx->host.as = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);


		ctx->cctx.x_host.ha_as = ctx->host.as;
	}


	/* dlltool tool (optional) */
	if (!ctx->cctx.x_host.ha_dlltool) {
		if (slbt_get_mkvars_var(dctx,confctx,"DLLTOOL",0x20,&val) < 0)
			return SLBT_NESTED_ERROR(dctx);

		if (val[0] && !(ctx->host.dlltool = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_dlltool = ctx->host.dlltool;
	}


	/* all done */
	return 0;
}
