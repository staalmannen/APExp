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

#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_objlist_impl.h"
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_objlist_read(
	int                     fdcwd,
	struct slbt_obj_list *  objlist)
{
	struct slbt_map_info *	mapinfo;
	int			objc;
	char **			objv;
	char *			src;
	char *			dst;
	char *			mark;
	int			skip;

	/* temporarily map the object list */
	if (!(mapinfo = slbt_map_file(fdcwd,objlist->name,SLBT_MAP_INPUT)))
		return -1;

	/* object list, cautionary null termination, vector null termination */
	objlist->size = mapinfo->size;
	objlist->size++;
	objlist->size++;

	if (!(objlist->addr = calloc(1,objlist->size))) {
		slbt_unmap_file(mapinfo);
		return -1;
	}

	/* object list file to normalized object strings */
	objc = 0;
	skip = true;

	for (src=mapinfo->addr,dst=objlist->addr; src<mapinfo->cap; src++) {
		if (!*src || (*src==' ') || (*src=='\n') || (*src=='\r')) {
			if (!skip)
				*dst++ = 0;

			skip = true;
		} else {
			*dst++ = *src;

			objc += !!skip;
			skip  = false;
		}
	}

	/* object vector */
	objlist->objc = objc;

	if (!(objlist->objv = calloc(++objc,sizeof(char *)))) {
		free(objlist->addr);
		slbt_unmap_file(mapinfo);
		return -1;
	}

	for (objv=objlist->objv,mark=objlist->addr; *mark; objv++) {
		*objv = mark;
		mark += strlen(mark) + 1;
	}

	slbt_unmap_file(mapinfo);

	return 0;
}
