#ifndef SLIBTOOL_M4FAKE_IMPL_H
#define SLIBTOOL_M4FAKE_IMPL_H

#include <slibtool/slibtool.h>

int slbt_m4fake_expand_cmdarg(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_txtfile_ctx *       sctx,
	const char *                    cmdname,
	char                            (*argbuf)[PATH_MAX]);

#endif
