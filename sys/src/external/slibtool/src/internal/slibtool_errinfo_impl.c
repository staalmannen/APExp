/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_record_error(
	const struct slbt_driver_ctx *	dctx,
	int				esyscode,
	int				elibcode,
	const char *			efunction,
	int				eline,
	unsigned			eflags,
	int                             excidx)
{
	struct slbt_driver_ctx_impl *	ictx;
	struct slbt_error_info *	erri;
	ptrdiff_t                       eidx;
	char *                          eunit;

	ictx = slbt_get_driver_ictx(dctx);

	if (ictx->errinfp == ictx->erricap)
		return -1;


	eidx            = ictx->errinfp - ictx->erriptr;
	erri            = &ictx->erribuf[eidx];

	eunit           = ictx->eunit ? strdup(ictx->eunit) : 0;

	erri->euctx     = ictx->euctx;
	erri->eunit     = eunit;

	erri->edctx     = dctx;
	erri->esyscode  = esyscode;
	erri->elibcode  = elibcode;
	erri->efunction = efunction;
	erri->eline     = eline;
	erri->eflags    = eflags;
	erri->excidx    = excidx;

	ictx->erristr[eidx] = eunit;

	*ictx->errinfp++ = erri;

	return -1;
}
