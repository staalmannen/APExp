/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <ctype.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"

static int slbt_lib_free_symlist_ctx_impl(
	struct slbt_symlist_ctx_impl *  ctx,
	struct slbt_input *             mapinfo,
	int                             ret)
{
	if (mapinfo)
		slbt_fs_unmap_input(mapinfo);

	if (ctx) {
		if (ctx->pathbuf)
			free(ctx->pathbuf);

		if (ctx->symstrs)
			free(ctx->symstrs);

		if (ctx->symstrv)
			free(ctx->symstrv);

		free(ctx);
	}

	return ret;
}

int slbt_lib_get_symlist_ctx(
	const struct slbt_driver_ctx *  dctx,
	const char *                    path,
	struct slbt_symlist_ctx **      pctx)
{
	struct slbt_symlist_ctx_impl *  ctx;
	struct slbt_input               mapinfo;
	size_t                          nsyms;
	char *                          ch;
	char *                          cap;
	char *                          src;
	const char **                   psym;
	char                            dummy;
	int                             cint;
	bool                            fvalid;

	/* map symlist file temporarily */
	if (slbt_fs_map_input(dctx,-1,path,PROT_READ,&mapinfo) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* alloc context */
	if (!(ctx = calloc(1,sizeof(*ctx))))
		return slbt_lib_free_symlist_ctx_impl(
			ctx,&mapinfo,
			SLBT_BUFFER_ERROR(dctx));

	/* count symbols */
	src = mapinfo.map_size ? mapinfo.map_addr : &dummy;
	cap = &src[mapinfo.map_size];

	for (; (src<cap) && isspace((cint=*src)); )
		src++;

	for (ch=src,nsyms=0; ch<cap; nsyms++) {
		for (; (ch<cap) && !isspace((cint=*ch)); )
			ch++;

		fvalid = false;

		for (; (ch<cap) && isspace((cint=*ch)); )
			fvalid = (*ch++ == '\n') || fvalid;

		if (!fvalid)
			return slbt_lib_free_symlist_ctx_impl(
				ctx,&mapinfo,
				SLBT_CUSTOM_ERROR(
					dctx,
					SLBT_ERR_FLOW_ERROR));
	}

	/* clone path, alloc string buffer and symbol vector */
	if (!(ctx->pathbuf = strdup(path)))
		return slbt_lib_free_symlist_ctx_impl(
			ctx,&mapinfo,
			SLBT_SYSTEM_ERROR(dctx));

	if (!(ctx->symstrs = calloc(mapinfo.map_size+1,1)))
		return slbt_lib_free_symlist_ctx_impl(
			ctx,&mapinfo,
			SLBT_SYSTEM_ERROR(dctx));

	if (!(ctx->symstrv = calloc(nsyms+1,sizeof(char *))))
		return slbt_lib_free_symlist_ctx_impl(
			ctx,&mapinfo,
			SLBT_SYSTEM_ERROR(dctx));

	/* copy the source to the allocated string buffer */
	memcpy(ctx->symstrs,mapinfo.map_addr,mapinfo.map_size);
	slbt_fs_unmap_input(&mapinfo);

	/* populate the symbol vector, handle whitespace */
	src = ctx->symstrs;
	cap = &src[mapinfo.map_size];

	for (; (src<cap) && isspace((cint=*src)); )
		src++;

	for (ch=src,psym=ctx->symstrv; ch<cap; psym++) {
		*psym = ch;

		for (; (ch<cap) && !isspace((cint=*ch)); )
			ch++;

		for (; (ch<cap) && isspace((cint=*ch)); )
			*ch++ = '\0';
	}

	/* all done */
	ctx->dctx           = dctx;
	ctx->path           = ctx->pathbuf;
	ctx->sctx.x_path    = &ctx->path;
	ctx->sctx.x_symstrv = ctx->symstrv;

	*pctx = &ctx->sctx;

	return 0;
}

void slbt_lib_free_symlist_ctx(struct slbt_symlist_ctx * ctx)
{
	struct slbt_symlist_ctx_impl *	ictx;
	uintptr_t			addr;

	if (ctx) {
		addr = (uintptr_t)ctx - offsetof(struct slbt_symlist_ctx_impl,sctx);
		ictx = (struct slbt_symlist_ctx_impl *)addr;
		slbt_lib_free_symlist_ctx_impl(ictx,0,0);
	}
}
