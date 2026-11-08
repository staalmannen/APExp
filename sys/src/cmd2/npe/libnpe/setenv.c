#include <u.h>
#include <libc.h>

int
setenv(char *name, char *value, int overwrite)
{
	char *s;

	if(overwrite == 0 && (s = getenv(name)) != nil){
		free(s);
		return 0;
	}

	return putenv(name, value);
}
