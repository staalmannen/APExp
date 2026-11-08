#include <dirent.h>
#include "_dirent.h"

int
closedir(DIR *d)
{
	free(d->d);
	close(d->fd);
	free(d);

	return 0;
}
