#ifndef SLIBTOOL_REALPATH_IMPL_H
#define SLIBTOOL_REALPATH_IMPL_H

#include <stdlib.h>

int slbt_realpath(
	int             fdat,
	const char *    path,
	int             options,
	char *          buf,
	size_t          buflen);

#endif
