#include <dirent.h>
#include "_dirent.h"

struct dirent *
readdir(DIR *d)
{
	if(d->i >= d->n){
		free(d->d);
		if((d->n = dirread(d->fd, &d->d)) <= 0)
			return nil;
		d->i = 0;
	}

	d->de.d_type = (d->d[d->i].qid.type & QTDIR) ? DT_DIR : DT_FILE;
	d->de.d_name = d->d[d->i].name;
	d->i++;

	return &d->de;
}
