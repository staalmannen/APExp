#ifndef SLIBTOOL_LCONF_IMPL_H
#define SLIBTOOL_LCONF_IMPL_H

#include <stdint.h>

struct slbt_driver_ctx;

int slbt_get_lconf_flags(
	struct slbt_driver_ctx *	dctx,
	const char *			lconf,
	uint64_t *			flags,
	bool                            fsilent);

#endif
