#ifndef SLIBTOOL_MKVARS_IMPL_H
#define SLIBTOOL_MKVARS_IMPL_H

#include <stdint.h>

struct slbt_driver_ctx;

int slbt_get_mkvars_flags(
	struct slbt_driver_ctx *	dctx,
	const char *			mkvars,
	uint64_t *			flags);

#endif
