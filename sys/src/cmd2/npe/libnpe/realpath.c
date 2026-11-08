#include <u.h>
#include <libc.h>
#include "limits.h"

char *
realpath(char *path, char *buffer)
{
	char *s, p[PATH_MAX];
	int f, pathlen, n;

	s = nil;
	if((f = open(path, OREAD)) >= 0){
		if(fd2path(f, p, sizeof(p)) == 0)
			s = buffer == nil ? strdup(p) : strcpy(buffer, p);
		close(f);
	}
	if(s == nil){
		if(path[0] != '/'){
			pathlen = strlen(path);
			if(getwd(p, sizeof(p)) == nil || (n = strlen(p))+1+pathlen >= sizeof(p))
				return nil;
			p[n++] = '/';
			strcpy(p+n, path);
			path = p;
		}else if(strlen(path) >= sizeof(p))
			return nil;

		s = cleanname(buffer == nil ? strdup(path) : strcpy(buffer, path));
	}

	return s;
}
