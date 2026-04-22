#include <unistd.h>
#include <sys/limits.h>
#include <string.h>

/*
 * execvpe: execvp with explicit environment.
 * GNU extension; equivalent to execvp but uses envp instead of environ.
 */
int
execvpe(const char *name, char *const argv[], char *const envp[])
{
	char buf[PATH_MAX];

	if(execve(name, (const char **)argv, (const char **)envp) < 0){
		strcpy(buf, "/bin/");
		strcpy(buf+5, name);
		execve(buf, (const char **)argv, (const char **)envp);
	}
	return -1;
}
