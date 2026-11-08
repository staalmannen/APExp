#include <unistd.h>
#include <errno.h>

#undef stat

int
fstatat(int dirfd, char *path, struct npe_stat *buf, int flags)
{
	char *s, p[8192];
	int r;

	USED(flags);

	if(fd2path(dirfd, p, sizeof(p)-1) != 0)
		return -1;
	if((s = smprint("%s/%s", p, path)) == nil)
		return -1;
	r = npe_stat(s, buf);
	free(s);

	return r;
}
