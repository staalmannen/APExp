#include <unistd.h>
#include <errno.h>

#undef stat

int
npe_stat(char *filename, struct npe_stat *buf)
{
	Dir *d;

	if((d = dirstat(filename)) == nil){
		errno = ENOENT;
		return -1;
	}

	buf->st_size = d->length;
	buf->st_mtime = d->mtime;
	buf->st_atime = d->atime;
	buf->st_mode = d->mode & 0777;
	if(d->mode & DMDIR)
		buf->st_mode |= S_IFDIR;
	else
		buf->st_mode |= S_IFREG;

	free(d);

	return 0;
}
