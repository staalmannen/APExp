#include <unistd.h>

extern char **environ;
extern int _execpath(const char *, const char **, const char **);

int
execvp(const char *name, const char **argv)
{
	return _execpath(name, argv, (const char **)environ);
}
