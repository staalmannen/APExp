#include "../plan9/lib.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

/*
 * posix_spawn / posix_spawnp - spawn a process
 *
 * Full posix_spawn requires spawn file actions and attributes which
 * would need substantial infrastructure. We implement the common
 * case: no file actions, no special attributes — equivalent to
 * fork() + exec(). This satisfies configure probes and programs
 * that use posix_spawn as a portable fork+exec.
 *
 * Returns 0 on success with child pid in *pid, or errno on failure.
 * posix_spawn does NOT set errno — it returns the error value directly.
 */

/* Opaque types — enough for link-time satisfaction */
typedef void posix_spawn_file_actions_t;
typedef void posix_spawnattr_t;

int
posix_spawn(pid_t *pid, const char *path,
            const posix_spawn_file_actions_t *fa,
            const posix_spawnattr_t *attr,
            char *const argv[], char *const envp[])
{
	pid_t child;
	(void)fa; (void)attr; (void)envp;

	child = fork();
	if(child < 0)
		return errno;
	if(child == 0){
		execv(path, (const char **)argv);
		_exit(127);
	}
	if(pid != NULL)
		*pid = child;
	return 0;
}

int
posix_spawnp(pid_t *pid, const char *file,
             const posix_spawn_file_actions_t *fa,
             const posix_spawnattr_t *attr,
             char *const argv[], char *const envp[])
{
	pid_t child;
	(void)fa; (void)attr; (void)envp;

	child = fork();
	if(child < 0)
		return errno;
	if(child == 0){
		execvp(file, (const char **)argv);
		_exit(127);
	}
	if(pid != NULL)
		*pid = child;
	return 0;
}

/* spawn file actions stubs — enough to satisfy link-time references */
int posix_spawn_file_actions_init(posix_spawn_file_actions_t *fa)
	{ (void)fa; return 0; }
int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *fa)
	{ (void)fa; return 0; }
int posix_spawn_file_actions_addclose(posix_spawn_file_actions_t *fa, int fd)
	{ (void)fa; (void)fd; return 0; }
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *fa,
                                     int fd, int newfd)
	{ (void)fa; (void)fd; (void)newfd; return 0; }
int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t *fa,
                                     int fd, const char *path,
                                     int flags, mode_t mode)
	{ (void)fa; (void)fd; (void)path; (void)flags; (void)mode; return 0; }

/* spawnattr stubs */
int posix_spawnattr_init(posix_spawnattr_t *a)      { (void)a; return 0; }
int posix_spawnattr_destroy(posix_spawnattr_t *a)   { (void)a; return 0; }
int posix_spawnattr_setflags(posix_spawnattr_t *a, short f)
	{ (void)a; (void)f; return 0; }
int posix_spawnattr_getflags(const posix_spawnattr_t *a, short *f)
	{ (void)a; if(f) *f=0; return 0; }
int posix_spawnattr_setsigmask(posix_spawnattr_t *a, const sigset_t *s)
	{ (void)a; (void)s; return 0; }
int posix_spawnattr_getsigmask(const posix_spawnattr_t *a, sigset_t *s)
	{ (void)a; (void)s; return 0; }
