#include <u.h>
#include <libc.h>
#include <draw.h>

/*
 * Default version: treat as file name
 */

Subfont*
_getsubfont(Display *d, char *name)
{
	int fd;
	Subfont *f;

	fd = open(name, OREAD|OCEXEC);
	if(fd < 0) {
		fprint(2, "getsubfont: can't open %s: %r\n", name);
		f = nil;
	} else {
		f = readsubfont(d, name, fd, 0);
		if(f == nil)
			fprint(2, "getsubfont: can't read %s: %r\n", name);
		close(fd);
	}

	return f;
}
