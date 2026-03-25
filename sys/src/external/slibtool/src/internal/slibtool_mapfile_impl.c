/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "slibtool_errinfo_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_visibility_impl.h"

static void slbt_munmap(void * addr, size_t size)
{
	if (addr) {
		munmap(addr,size);
	}
}

slbt_hidden struct slbt_map_info * slbt_map_file(
	int		fdat,
	const char *	path,
	uint32_t	flags)
{
	int 			fd;
	void *			addr;
	struct stat		st;
	uint32_t		oflag;
	uint32_t		mprot;
	struct slbt_map_info *	mapinfo;

	if ((flags & SLBT_MAP_INPUT) && (flags & SLBT_MAP_OUTPUT))  {
		oflag = O_RDWR;
		mprot = PROT_READ|PROT_WRITE;
	} else if (flags & SLBT_MAP_INPUT) {
		oflag = O_RDONLY;
		mprot = PROT_READ;
	} else if (flags & SLBT_MAP_OUTPUT) {
		oflag = O_WRONLY;
		mprot = PROT_WRITE;
	} else {
		errno = EINVAL;
		return 0;
	}

	if ((fd = openat(fdat,path,oflag,0)) < 0)
		return 0;

	if (fstat(fd,&st) < 0) {
		close(fd);
		return 0;
	}

	addr = st.st_size
		? mmap(0,st.st_size,mprot,MAP_SHARED,fd,0)
		: 0;

	if (addr == MAP_FAILED) {
		close(fd);
		return 0;
	}

	if (!(mapinfo = malloc(sizeof(*mapinfo)))) {
		close(fd);
		slbt_munmap(addr,st.st_size);
		return 0;
	}

	close(fd);

	mapinfo->addr = addr;
	mapinfo->size = st.st_size;
	mapinfo->mark = addr;
	mapinfo->cap  = &mapinfo->mark[st.st_size];

	return mapinfo;
}

slbt_hidden void slbt_unmap_file(struct slbt_map_info * mapinfo)
{
	slbt_munmap(mapinfo->addr,mapinfo->size);
	free(mapinfo);
}

slbt_hidden int slbt_mapped_readline(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_map_info *		mapinfo,
	char *				buf,
	size_t				buflen)
{
	const char * ch;
	const char * cap;
	const char * mark;
	const char * newline;
	size_t       len;

	mark = mapinfo->mark;
	cap  = mapinfo->cap;

	for (ch=mark, newline=0; ch<cap && !newline; ch++)
		if (*ch == '\n')
			newline = ch;

	len = ch - mark;

	if (newline && (buflen <= len))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_FLOW_ERROR);

	if (!newline)
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_BAD_DATA);

	memcpy(buf,mark,len);
	buf[len] = 0;

	mapinfo->mark += len;

	return 0;
}
