#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/limits.h>

/*
 * _execpath -- the PATH search behind execvp, execvpe and execlp.
 *
 * Those three used to share this instead:
 *
 *	BUG: instead of looking at PATH env variable,
 *	just try prepending /bin/ if name fails...
 *
 * which is fine while everything lives in /bin, and wrong the moment it
 * does not.  Under APExp the APE binaries are in /$objtype/bin/ape,
 * reached through PATH, so "env foo", "nohup foo", "timeout 5 foo" and
 * every other coreutils program that ends in execvp() could only run
 * things in /bin.
 *
 * POSIX rules, as far as they apply here:
 *   - a name containing '/' is used as given, with no search;
 *   - otherwise each PATH element is tried in turn, an empty element
 *     meaning the current directory;
 *   - the errno reported is the most informative of those seen: EACCES
 *     if some candidate existed but could not be run, else ENOENT.
 * The ENOEXEC-means-run-it-as-a-shell-script rule is not implemented,
 * as it was not before.
 *
 * Each candidate is checked with access(X_OK) before exec is attempted,
 * because in APE a failed execve() is not free: it has already done
 * _RFORK(RFCENVG), rewritten /env/_fdinfo and /env/_sighdlr, and closed
 * every FD_CLOEXEC descriptor by the time the exec itself is tried.  A
 * search that blindly exec'd each candidate would pay all of that once
 * per PATH element.
 *
 * If PATH is unset, "/bin" is used -- the same place the old code
 * looked.  /bin is also tried as a last resort when PATH is set but
 * yielded nothing, so no caller that worked before stops working.
 */

extern char **environ;

static int
tryexec(const char *path, const char **argv, const char **envp, int *saved)
{
	if(access(path, X_OK) < 0){
		if(errno == EACCES)
			*saved = EACCES;
		return -1;
	}
	execve(path, argv, envp);
	/* Only reached if the exec failed. */
	if(errno == EACCES)
		*saved = EACCES;
	return -1;
}

int
_execpath(const char *file, const char **argv, const char **envp)
{
	char buf[PATH_MAX];
	const char *path, *p, *e;
	int saved;
	size_t flen, dlen;

	if(file == NULL || *file == '\0'){
		errno = ENOENT;
		return -1;
	}
	if(strchr(file, '/') != NULL){
		execve(file, argv, envp);
		return -1;
	}

	flen = strlen(file);
	saved = ENOENT;

	path = getenv("PATH");
	if(path == NULL)
		path = "/bin";

	for(p = path; ; p = e + 1){
		e = strchr(p, ':');
		if(e == NULL)
			e = p + strlen(p);
		dlen = e - p;
		if(dlen == 0){
			/* Empty element: the current directory. */
			if(flen + 3 > sizeof buf)
				goto next;
			memcpy(buf, "./", 2);
			memcpy(buf + 2, file, flen + 1);
		}else{
			if(dlen + 1 + flen + 1 > sizeof buf)
				goto next;
			memcpy(buf, p, dlen);
			if(buf[dlen-1] != '/')
				buf[dlen++] = '/';
			memcpy(buf + dlen, file, flen + 1);
		}
		tryexec(buf, argv, envp, &saved);
	next:
		if(*e == '\0')
			break;
	}

	/* Last resort, matching what execvp did before it searched PATH. */
	if(flen + 6 <= sizeof buf){
		memcpy(buf, "/bin/", 5);
		memcpy(buf + 5, file, flen + 1);
		tryexec(buf, argv, envp, &saved);
	}

	errno = saved;
	return -1;
}
