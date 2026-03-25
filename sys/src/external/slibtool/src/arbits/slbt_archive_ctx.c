/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_ar_impl.h"

static int slbt_map_raw_archive(
	const struct slbt_driver_ctx *	dctx,
	int				fd,
	const char *			path,
	int				prot,
	struct slbt_raw_archive *	map)
{
	struct slbt_input mapinfo = {0,0};

	if (slbt_fs_map_input(dctx,fd,path,prot,&mapinfo) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if (mapinfo.map_size == 0)
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_EMPTY_FILE);

	map->map_addr = mapinfo.map_addr;
	map->map_size = mapinfo.map_size;

	return 0;
}

static int slbt_unmap_raw_archive(struct slbt_raw_archive * map)
{
	struct slbt_input mapinfo;

	mapinfo.map_addr = map->map_addr;
	mapinfo.map_size = map->map_size;

	return slbt_fs_unmap_input(&mapinfo);
}

static int slbt_ar_free_archive_ctx_impl(struct slbt_archive_ctx_impl * ctx, int ret)
{
	if (ctx) {
		slbt_ar_free_archive_meta(ctx->meta);
		slbt_unmap_raw_archive(&ctx->map);
		free(ctx->pathbuf);
		free(ctx);
	}

	return ret;
}

int slbt_ar_get_archive_ctx(
	const struct slbt_driver_ctx *	dctx,
	const char *			path,
	struct slbt_archive_ctx **		pctx)
{
	struct slbt_archive_ctx_impl *	ctx;
	struct slbt_archive_meta_impl * mctx;
	int				prot;

	if (!(ctx = calloc(1,sizeof(*ctx))))
		return SLBT_BUFFER_ERROR(dctx);

	slbt_driver_set_arctx(
		dctx,0,path);

	prot = (dctx->x_cctx->x_actflags & SLBT_ACTION_MAP_READWRITE)
		? PROT_READ | PROT_WRITE
		: PROT_READ;

	if (slbt_map_raw_archive(dctx,-1,path,prot,&ctx->map))
		return slbt_ar_free_archive_ctx_impl(ctx,
			SLBT_NESTED_ERROR(dctx));

	if (slbt_ar_get_archive_meta(dctx,&ctx->map,&ctx->meta))
		return slbt_ar_free_archive_ctx_impl(ctx,
			SLBT_NESTED_ERROR(dctx));

	if (!(ctx->pathbuf = strdup(path)))
		return slbt_ar_free_archive_ctx_impl(ctx,
			SLBT_NESTED_ERROR(dctx));

	mctx = slbt_archive_meta_ictx(ctx->meta);

	ctx->dctx       = dctx;
	ctx->path	= ctx->pathbuf;
	ctx->actx.x_path	= &ctx->path;
	ctx->actx.x_map	= &ctx->map;
	ctx->actx.x_meta	= ctx->meta;
	mctx->actx      = &ctx->actx;

	*pctx = &ctx->actx;
	return 0;
}

void slbt_ar_free_archive_ctx(struct slbt_archive_ctx * ctx)
{
	struct slbt_archive_ctx_impl *	ictx;
	uintptr_t			addr;

	if (ctx) {
		addr = (uintptr_t)ctx - offsetof(struct slbt_archive_ctx_impl,actx);
		ictx = (struct slbt_archive_ctx_impl *)addr;
		slbt_ar_free_archive_ctx_impl(ictx,0);
	}
}
