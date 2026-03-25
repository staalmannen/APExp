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
#include "slibtool_visibility_impl.h"

/********************************************************/
/* Read a text file, and create an in-memory vecotr of  */
/* normalized text lines, stripped of both leading and  */
/* trailing white space.                                */
/********************************************************/

static int slbt_lib_free_txtfile_ctx_impl(
	struct slbt_txtfile_ctx_impl *  ctx,
	struct slbt_input *             mapinfo,
	int                             ret)
{
	if (mapinfo)
		slbt_fs_unmap_input(mapinfo);

	if (ctx) {
		if (ctx->pathbuf)
			free(ctx->pathbuf);

		if (ctx->txtlines)
			free(ctx->txtlines);

		if (ctx->txtlinev)
			free(ctx->txtlinev);

		free(ctx);
	}

	return ret;
}

static int slbt_lib_get_txtfile_ctx_impl(
	const struct slbt_driver_ctx *  dctx,
	const char *                    path,
	int                             fdsrc,
	struct slbt_txtfile_ctx **      pctx)
{
	struct slbt_txtfile_ctx_impl *  ctx;
	struct slbt_input               mapinfo;
	size_t                          nlines;
	char *                          ch;
	char *                          cap;
	char *                          src;
	char *                          mark;
	const char **                   pline;
	char                            dummy;
	int                             cint;

	/* map txtfile file temporarily */
	if (slbt_fs_map_input(dctx,fdsrc,path,PROT_READ,&mapinfo) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* alloc context */
	if (!(ctx = calloc(1,sizeof(*ctx))))
		return slbt_lib_free_txtfile_ctx_impl(
			ctx,&mapinfo,
			SLBT_BUFFER_ERROR(dctx));

	/* count lines */
	src = mapinfo.map_size ? mapinfo.map_addr : &dummy;
	cap = &src[mapinfo.map_size];

	for (; (src<cap) && isspace((cint=*src)); )
		src++;

	for (ch=src,nlines=0; ch<cap; ch++)
		nlines += (*ch == '\n');

	nlines += (ch[-1] != '\n');

	/* clone path, alloc string buffer and line vector */
	if (!(ctx->pathbuf = strdup(path)))
		return slbt_lib_free_txtfile_ctx_impl(
			ctx,&mapinfo,
			SLBT_SYSTEM_ERROR(dctx));

	if (!(ctx->txtlines = calloc(mapinfo.map_size+1,1)))
		return slbt_lib_free_txtfile_ctx_impl(
			ctx,&mapinfo,
			SLBT_SYSTEM_ERROR(dctx));

	if (!(ctx->txtlinev = calloc(nlines+1,sizeof(char *))))
		return slbt_lib_free_txtfile_ctx_impl(
			ctx,&mapinfo,
			SLBT_SYSTEM_ERROR(dctx));

	/* copy the source to the allocated string buffer */
	memcpy(ctx->txtlines,mapinfo.map_addr,mapinfo.map_size);
	slbt_fs_unmap_input(&mapinfo);

	/* populate the line vector, handle whitespace */
	src = ctx->txtlines;
	cap = &src[mapinfo.map_size];

	for (; (src<cap) && isspace((cint=*src)); )
		*src++ = '\0';

	for (ch=src,pline=ctx->txtlinev; ch<cap; pline++) {
		for (; (ch<cap) && isspace((cint = *ch)); )
			ch++;

		if (ch < cap)
			*pline = ch;

		for (; (ch<cap) && (*ch != '\n'); )
			ch++;

		mark = ch;

		for (--ch; (ch > *pline) && isspace((cint = *ch)); ch--)
			*ch = '\0';

		if ((ch = mark) < cap)
			*ch++ = '\0';
	}

	/* all done */
	ctx->dctx             = dctx;
	ctx->path             = ctx->pathbuf;
	ctx->tctx.x_path      = &ctx->path;
	ctx->tctx.x_txtlinev  = ctx->txtlinev;

	*pctx = &ctx->tctx;

	return 0;
}

slbt_hidden int slbt_impl_get_txtfile_ctx(
	const struct slbt_driver_ctx *  dctx,
	const char *                    path,
	int                             fdsrc,
	struct slbt_txtfile_ctx **      pctx)
{
	return slbt_lib_get_txtfile_ctx_impl(dctx,path,fdsrc,pctx);
}

int slbt_lib_get_txtfile_ctx(
	const struct slbt_driver_ctx *  dctx,
	const char *                    path,
	struct slbt_txtfile_ctx **      pctx)
{
	return slbt_lib_get_txtfile_ctx_impl(dctx,path,(-1),pctx);
}

void slbt_lib_free_txtfile_ctx(struct slbt_txtfile_ctx * ctx)
{
	struct slbt_txtfile_ctx_impl *	ictx;
	uintptr_t			addr;

	if (ctx) {
		addr = (uintptr_t)ctx - offsetof(struct slbt_txtfile_ctx_impl,tctx);
		ictx = (struct slbt_txtfile_ctx_impl *)addr;
		slbt_lib_free_txtfile_ctx_impl(ictx,0,0);
	}
}
