#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>

static void dummy(char *, char *) {}
#define __env_rm_add(x,y) dummy(x,y)
extern	char **environ;
#define __environ environ

int clearenv()
{
	char **e = __environ;
	__environ = 0;
	if (e) while (*e) __env_rm_add(*e++, 0);
	return 0;
}
