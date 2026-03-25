#ifndef SLIBTOOL_MAPFILE_IMPL_H
#define SLIBTOOL_MAPFILE_IMPL_H

#define SLBT_MAP_INPUT	0x0001
#define SLBT_MAP_OUTPUT	0x0002

struct slbt_map_info {
	void *	addr;
	size_t	size;
	char *	mark;
	char *	cap;
};

struct slbt_map_info * slbt_map_file(
	int, const char *,
	uint32_t);

void slbt_unmap_file(struct slbt_map_info *);

int  slbt_mapped_readline(
	const struct slbt_driver_ctx *,
	struct slbt_map_info *,
	char *, size_t);

#endif
