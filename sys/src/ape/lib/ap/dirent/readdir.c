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
		}
		d->dd_loc = 0;
		d->dd_size = i*sizeof(struct dirent);
	}
	dr = (struct dirent*)(d->dd_buf+d->dd_loc);
	d->dd_loc += sizeof(struct dirent);
	d->dd_seek++;
	return dr;
}

