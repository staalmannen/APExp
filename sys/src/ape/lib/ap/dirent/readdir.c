#include "lib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "sys9.h"
#include "dir.h"

#define DBLOCKSIZE 20

/*
 * st_mode to the d_type value readdir() reports. POSIX gives these as
 * DT_* constants, which are small integers unrelated to the S_IF* bits,
 * so the two have to be mapped rather than aliased.
 *
 * S_ISFIFO and S_ISSOCK are the same test in APE's <sys/stat.h> -- both
 * are mode 0010000 -- so a FIFO and a socket cannot be told apart here.
 * FIFO wins, since mkfifo() can create one and Plan 9 has no Unix-domain
 * sockets in the filesystem.
 */
static unsigned char
_dtype(mode_t m)
{
	if(S_ISREG(m))
		return DT_REG;
	if(S_ISDIR(m))
		return DT_DIR;
	if(S_ISCHR(m))
		return DT_CHR;
	if(S_ISBLK(m))
		return DT_BLK;
	if(S_ISLNK(m))
		return DT_LNK;
	if(S_ISFIFO(m))
		return DT_FIFO;
	return DT_UNKNOWN;
}

struct dirent *
readdir(DIR *d)
{
	int i;
	struct dirent *dr;
	Dir *dirs, *dir;

	if(d == NULL){
		errno = EBADF;
		return NULL;
	}
	if(d->dd_loc >= d->dd_size){
		if(d->dirloc >= d->dirsize){
			free(d->dirs);
			d->dirs = NULL;
			d->dirsize = _dirread(d->dd_fd, &d->dirs);
			d->dirloc = 0;
		}
		if(d->dirsize < 0) {	/* malloc or read failed in _dirread? */
			free(d->dirs);
			d->dirs = NULL;
		}
		if(d->dirs == NULL)
			return NULL;

		dr = (struct dirent *)d->dd_buf;
		dirs = d->dirs;
		for(i=0; i<DBLOCKSIZE && d->dirloc < d->dirsize; i++){
			dir = &dirs[d->dirloc++];
			strncpy(dr[i].d_name, dir->name, MAXNAMLEN);
			dr[i].d_name[MAXNAMLEN] = 0;
			_dirtostat(&dr[i].d_stat, dir, NULL);
			dr[i].d_ino = dr[i].d_stat.st_ino;
			dr[i].d_type = _dtype(dr[i].d_stat.st_mode);
		}
		d->dd_loc = 0;
		d->dd_size = i*sizeof(struct dirent);
	}
	dr = (struct dirent*)(d->dd_buf+d->dd_loc);
	d->dd_loc += sizeof(struct dirent);
	d->dd_seek++;
	return dr;
}

