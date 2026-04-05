#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sys9.h"
#undef OPEN
#include <stdio.h>
#include "lib.h"
#include "dir.h"

FILE *
tmpfile(void){
	static char name[]="/tmp/tf0000000000000";
	char *p;
	int n;
	int fd;

	/* Find a unique temporary filename */
	while(access(name, 0) >= 0){
		p = name+7;
		while(*p == '9')
			*p++ = '0';
		if(*p == '\0')
			return NULL;
		++*p;
	}

	/* Create the temporary file with remove-on-close flag */
	n = _CREATE(name, 64|2, 0777); /* remove-on-close */
	if(n==-1){
		_syserrno();
		return NULL;
	}

	_fdinfo[n].flags = FD_ISOPEN;
	_fdinfo[n].oflags = 2;

	/* Use fdopen to create a FILE from the fd */
	FILE *f = fdopen(n, "w+b");
	if (!f) {
		close(n);
		return NULL;
	}

	return f;
}


