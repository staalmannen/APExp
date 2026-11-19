#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int
lstat(const char *name, struct stat *ans)
{
	return stat(name, ans);
}

/* readlink and symlink re-implemented in symlink.c */
