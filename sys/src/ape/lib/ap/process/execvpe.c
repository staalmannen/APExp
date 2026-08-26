#include <unistd.h>

extern int _execpath(const char *, const char **, const char **);

/*
 * execvpe: execvp with an explicit environment. GNU extension.
 */
int
execvpe(const char *name, char *const argv[], char *const envp[])
{
	return _execpath(name, (const char **)argv, (const char **)envp);
}
