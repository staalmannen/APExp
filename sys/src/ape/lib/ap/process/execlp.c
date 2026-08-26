#include <unistd.h>

extern char **environ;
extern int _execpath(const char *, const char **, const char **);

int
execlp(const char *name, const char *arg0, ...)
{
	return _execpath(name, &arg0, (const char **)environ);
}
