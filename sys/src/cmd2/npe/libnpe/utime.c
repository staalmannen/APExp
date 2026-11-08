#include <utime.h>

int
utime(const char *path, const struct utimbuf *times)
{
	Dir d;

	nulldir(&d);
	if(times == nil)
		d.atime = d.mtime = time(nil);
	else{
		d.atime = times->actime;
		d.mtime = times->modtime;
	}
	return dirwstat(path, &d);
}
