#ifndef SLIBTOOL_SYMLINK_IMPL_H
#define SLIBTOOL_SYMLINK_IMPL_H

#include <stdbool.h>
#include <slibtool/slibtool.h>

#define SLBT_SYMLINK_DEFAULT    0x0000
#define SLBT_SYMLINK_LITERAL    0x0001
#define SLBT_SYMLINK_WRAPPER    0x0002
#define SLBT_SYMLINK_DEVNULL    0x0004

int slbt_create_symlink(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			target,
	const char *			lnkname,
	uint32_t			options);

int slbt_create_symlink_ex(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	int                             fddst,
	const char *			target,
	const char *			lnkname,
	uint32_t			options);

int slbt_symlink_is_a_placeholder(int fdcwd, const char * lnkpath);

#endif
