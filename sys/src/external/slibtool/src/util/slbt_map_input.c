/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2015--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"

int slbt_fs_map_input(
	const struct slbt_driver_ctx *	dctx,
	int				fd,
	const char *			path,
	int				prot,
	struct slbt_input *		map)
{
	int		ret;
	struct stat	st;
	bool		fnew;
	int		fdcwd;

	fdcwd = slbt_driver_fdcwd(dctx);

	slbt_driver_set_ectx(
		dctx,0,path);

	if ((fnew = (fd < 0)))
		fd  = openat(fdcwd,path,O_RDONLY | O_CLOEXEC);

	if (fd < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	if ((ret = fstat(fd,&st) < 0) && fnew)
		close(fd);

	else if ((st.st_size == 0) && fnew)
		close(fd);

	if (ret < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	if (st.st_size == 0) {
		map->map_size = 0;
		map->map_addr = 0;
	} else {
		map->map_size = st.st_size;
		map->map_addr = mmap(0,map->map_size,prot,MAP_PRIVATE,fd,0);
	}

	if (fnew)
		close(fd);

	return (map->map_addr == MAP_FAILED)
		? SLBT_SYSTEM_ERROR(dctx)
		: 0;
}

int slbt_fs_unmap_input(struct slbt_input * map)
{
	return map->map_size ? munmap(map->map_addr,map->map_size) : 0;
}
