#include "../include/lib.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <spawn.h>

/*
 * posix_spawn / posix_spawnp -- spawn a process.
 *
 * Implemented as fork() + exec() with the file actions replayed in the
 * child, which is what POSIX describes and what glibc does when it has
 * no better primitive.  The earlier version here ignored file actions
 * and attributes entirely; that is not a stub a caller can detect, it
 * just silently gives the child the parent's file descriptors.  gnulib's
 * spawn-pipe.c, for one, wires up its pipe purely through adddup2, so it
 * would have got a child talking to the wrong fds.
 *
 * Types come from <spawn.h>.  The old code declared its own
 *	typedef void posix_spawnattr_t;
 * which worked only because every use was through a pointer.
 *
 * Child setup failures are reported back to the parent through a
 * close-on-exec pipe: the child writes errno into it and _exit()s, and
 * the parent, seeing a short read, knows exec succeeded.  Without that,
 * a failed dup2 or open would look to the caller like a successful spawn
 * followed by a mysterious exit status.
 *
 * A failed EXEC, though, cannot be reported this way in APE, and shows
 * up only as the child exiting 127.  APE's execve() closes every
 * FD_CLOEXEC descriptor (and rewrites /env/_fdinfo, and does
 * _RFORK(RFCENVG)) BEFORE it attempts the exec, so by the time exec
 * fails and returns, the report pipe the child would write to is
 * already gone.  POSIX allows this -- whether posix_spawn() diagnoses
 * an exec failure in the parent or leaves it as a 127 exit status is
 * explicitly unspecified -- but it differs from glibc, where both are
 * reported through the return value.
 *
 * Returns 0 on success with the child pid in *pid, or an error number
 * directly -- posix_spawn does NOT set errno.
 */

enum {
	FA_CLOSE,
	FA_DUP2,
	FA_OPEN,
	FA_CHDIR,
	FA_FCHDIR,
};

typedef struct Faction Faction;
typedef struct Falist Falist;

struct Faction {
	int	op;
	int	fd;
	int	newfd;
	int	oflag;
	mode_t	mode;
	char	*path;		/* malloc'd, owned by the Falist */
};

struct Falist {
	int	n;
	int	cap;
	Faction	*a;
};

/*
 * The header gives posix_spawn_file_actions_t a void* plus padding; we
 * keep a Falist* in it and nothing else, so that sizeof stays whatever
 * the header says.
 */
#define FALIST(fa)	(*(Falist**)&((posix_spawn_file_actions_t*)(fa))->__actions)

static Faction*
addaction(posix_spawn_file_actions_t *fa, int op)
{
	Falist *l;
	Faction *a;
	int cap;

	if(fa == NULL)
		return NULL;
	l = FALIST(fa);
	if(l == NULL){
		l = malloc(sizeof *l);
		if(l == NULL)
			return NULL;
		l->n = 0;
		l->cap = 0;
		l->a = NULL;
		FALIST(fa) = l;
	}
	if(l->n >= l->cap){
		cap = l->cap ? 2*l->cap : 8;
		a = realloc(l->a, cap*sizeof *a);
		if(a == NULL)
			return NULL;
		l->a = a;
		l->cap = cap;
	}
	a = &l->a[l->n++];
	memset(a, 0, sizeof *a);
	a->op = op;
	return a;
}

int
posix_spawn_file_actions_init(posix_spawn_file_actions_t *fa)
{
	if(fa == NULL)
		return EINVAL;
	memset(fa, 0, sizeof *fa);
	return 0;
}

int
posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *fa)
{
	Falist *l;
	int i;

	if(fa == NULL)
		return EINVAL;
	l = FALIST(fa);
	if(l != NULL){
		for(i = 0; i < l->n; i++)
			free(l->a[i].path);
		free(l->a);
		free(l);
		FALIST(fa) = NULL;
	}
	return 0;
}

int
posix_spawn_file_actions_addclose(posix_spawn_file_actions_t *fa, int fd)
{
	Faction *a;

	if(fd < 0)
		return EBADF;
	if((a = addaction(fa, FA_CLOSE)) == NULL)
		return fa == NULL ? EINVAL : ENOMEM;
	a->fd = fd;
	return 0;
}

int
posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *fa, int fd, int newfd)
{
	Faction *a;

	if(fd < 0 || newfd < 0)
		return EBADF;
	if((a = addaction(fa, FA_DUP2)) == NULL)
		return fa == NULL ? EINVAL : ENOMEM;
	a->fd = fd;
	a->newfd = newfd;
	return 0;
}

int
posix_spawn_file_actions_addopen(posix_spawn_file_actions_t *fa, int fd,
	const char *path, int oflag, mode_t mode)
{
	Faction *a;
	char *p;

	if(fd < 0)
		return EBADF;
	if(path == NULL)
		return EINVAL;
	if((p = strdup(path)) == NULL)
		return ENOMEM;
	if((a = addaction(fa, FA_OPEN)) == NULL){
		free(p);
		return fa == NULL ? EINVAL : ENOMEM;
	}
	a->fd = fd;
	a->path = p;
	a->oflag = oflag;
	a->mode = mode;
	return 0;
}

int
posix_spawn_file_actions_addchdir(posix_spawn_file_actions_t *fa, const char *path)
{
	Faction *a;
	char *p;

	if(path == NULL)
		return EINVAL;
	if((p = strdup(path)) == NULL)
		return ENOMEM;
	if((a = addaction(fa, FA_CHDIR)) == NULL){
		free(p);
		return fa == NULL ? EINVAL : ENOMEM;
	}
	a->path = p;
	return 0;
}

int
posix_spawn_file_actions_addfchdir(posix_spawn_file_actions_t *fa, int fd)
{
	Faction *a;

	if(fd < 0)
		return EBADF;
	if((a = addaction(fa, FA_FCHDIR)) == NULL)
		return fa == NULL ? EINVAL : ENOMEM;
	a->fd = fd;
	return 0;
}

int
posix_spawn_file_actions_addchdir_np(posix_spawn_file_actions_t *fa, const char *path)
{
	return posix_spawn_file_actions_addchdir(fa, path);
}

int
posix_spawn_file_actions_addfchdir_np(posix_spawn_file_actions_t *fa, int fd)
{
	return posix_spawn_file_actions_addfchdir(fa, fd);
}

/*
 * Attributes.  Every field is real and is honoured by posix_spawn below,
 * except the scheduling ones -- Plan 9 has no POSIX scheduler to set, so
 * those are stored and returned faithfully but have no effect, and
 * POSIX_SPAWN_SETSCHEDPARAM / SETSCHEDULER are quietly ignored rather
 * than failing the spawn.
 */

int
posix_spawnattr_init(posix_spawnattr_t *a)
{
	if(a == NULL)
		return EINVAL;
	memset(a, 0, sizeof *a);
	return 0;
}

int
posix_spawnattr_destroy(posix_spawnattr_t *a)
{
	if(a == NULL)
		return EINVAL;
	return 0;
}

int
posix_spawnattr_setflags(posix_spawnattr_t *a, short f)
{
	static const short known =
		POSIX_SPAWN_RESETIDS|POSIX_SPAWN_SETPGROUP|
		POSIX_SPAWN_SETSIGDEF|POSIX_SPAWN_SETSIGMASK|
		POSIX_SPAWN_SETSCHEDPARAM|POSIX_SPAWN_SETSCHEDULER|
		POSIX_SPAWN_USEVFORK|POSIX_SPAWN_SETSID;

	if(a == NULL)
		return EINVAL;
	if(f & ~known)
		return EINVAL;
	a->__flags = f;
	return 0;
}

int
posix_spawnattr_getflags(const posix_spawnattr_t *a, short *f)
{
	if(a == NULL || f == NULL)
		return EINVAL;
	*f = (short)a->__flags;
	return 0;
}

int
posix_spawnattr_setpgroup(posix_spawnattr_t *a, pid_t pgrp)
{
	if(a == NULL)
		return EINVAL;
	a->__pgrp = pgrp;
	return 0;
}

int
posix_spawnattr_getpgroup(const posix_spawnattr_t *a, pid_t *pgrp)
{
	if(a == NULL || pgrp == NULL)
		return EINVAL;
	*pgrp = a->__pgrp;
	return 0;
}

int
posix_spawnattr_setsigmask(posix_spawnattr_t *a, const sigset_t *s)
{
	if(a == NULL || s == NULL)
		return EINVAL;
	a->__mask = *s;
	return 0;
}

int
posix_spawnattr_getsigmask(const posix_spawnattr_t *a, sigset_t *s)
{
	if(a == NULL || s == NULL)
		return EINVAL;
	*s = a->__mask;
	return 0;
}

int
posix_spawnattr_setsigdefault(posix_spawnattr_t *a, const sigset_t *s)
{
	if(a == NULL || s == NULL)
		return EINVAL;
	a->__def = *s;
	return 0;
}

int
posix_spawnattr_getsigdefault(const posix_spawnattr_t *a, sigset_t *s)
{
	if(a == NULL || s == NULL)
		return EINVAL;
	*s = a->__def;
	return 0;
}

int
posix_spawnattr_setschedpolicy(posix_spawnattr_t *a, int pol)
{
	if(a == NULL)
		return EINVAL;
	a->__pol = pol;
	return 0;
}

int
posix_spawnattr_getschedpolicy(const posix_spawnattr_t *a, int *pol)
{
	if(a == NULL || pol == NULL)
		return EINVAL;
	*pol = a->__pol;
	return 0;
}

/*
 * <spawn.h> declares these with struct sched_param, which <sched.h>
 * defines as a single sched_priority member.  Store the priority in
 * __prio.
 */
int
posix_spawnattr_setschedparam(posix_spawnattr_t *a, const struct sched_param *p)
{
	if(a == NULL || p == NULL)
		return EINVAL;
	a->__prio = p->sched_priority;
	return 0;
}

int
posix_spawnattr_getschedparam(const posix_spawnattr_t *a, struct sched_param *p)
{
	if(a == NULL || p == NULL)
		return EINVAL;
	p->sched_priority = a->__prio;
	return 0;
}

/*
 * Child side.  Returns the error number to report, or 0 to go on and
 * exec.  Nothing here may allocate or use stdio -- we are between fork
 * and exec.
 */
static int
childsetup(const posix_spawn_file_actions_t *fa, const posix_spawnattr_t *at,
	int errfd)
{
	Falist *l;
	Faction *a;
	sigset_t mask;
	int i, fd, flags;

	if(at != NULL){
		flags = at->__flags;
		if(flags & POSIX_SPAWN_SETSID)
			if(setsid() < 0)
				return errno;
		if(flags & POSIX_SPAWN_SETPGROUP)
			if(setpgid(0, at->__pgrp) < 0)
				return errno;
		if(flags & POSIX_SPAWN_SETSIGDEF)
			for(i = 1; i < NSIG; i++)
				if(sigismember(&at->__def, i) == 1)
					if(signal(i, SIG_DFL) == SIG_ERR)
						return errno;
		if(flags & POSIX_SPAWN_SETSIGMASK){
			mask = at->__mask;
			if(sigprocmask(SIG_SETMASK, &mask, NULL) < 0)
				return errno;
		}
		/* RESETIDS, SETSCHEDPARAM and SETSCHEDULER have no
		 * meaning on Plan 9 and are ignored. */
	}

	if(fa == NULL)
		return 0;
	l = FALIST(fa);
	if(l == NULL)
		return 0;
	for(i = 0; i < l->n; i++){
		a = &l->a[i];
		switch(a->op){
		case FA_CLOSE:
			if(a->fd == errfd)
				break;	/* ours; it goes at exec */
			if(close(a->fd) < 0 && errno != EBADF)
				return errno;
			break;
		case FA_DUP2:
			if(a->fd == a->newfd){
				/* POSIX: clear FD_CLOEXEC, do not dup. */
				if(fcntl(a->newfd, F_SETFD, 0) < 0)
					return errno;
				break;
			}
			if(dup2(a->fd, a->newfd) < 0)
				return errno;
			break;
		case FA_OPEN:
			fd = open(a->path, a->oflag, a->mode);
			if(fd < 0)
				return errno;
			if(fd != a->fd){
				if(dup2(fd, a->fd) < 0){
					i = errno;
					close(fd);
					return i;
				}
				close(fd);
			}
			break;
		case FA_CHDIR:
			if(chdir(a->path) < 0)
				return errno;
			break;
		case FA_FCHDIR:
			if(fchdir(a->fd) < 0)
				return errno;
			break;
		}
	}
	return 0;
}

static int
spawn(pid_t *pid, const char *path,
	const posix_spawn_file_actions_t *fa, const posix_spawnattr_t *at,
	char *const argv[], char *const envp[], int usepath)
{
	int p[2], err, n, status;
	pid_t child;

	/*
	 * Error-reporting pipe.  Close-on-exec, so a successful exec
	 * closes the write end and the parent's read returns 0.
	 */
	if(pipe(p) < 0)
		return errno;
	if(fcntl(p[1], F_SETFD, FD_CLOEXEC) < 0){
		err = errno;
		close(p[0]);
		close(p[1]);
		return err;
	}

	child = fork();
	if(child < 0){
		err = errno;
		close(p[0]);
		close(p[1]);
		return err;
	}
	if(child == 0){
		close(p[0]);
		err = childsetup(fa, at, p[1]);
		if(err == 0){
			if(usepath)
				execvp(path, (const char **)argv);
			else if(envp != NULL)
				execve(path, (const char **)argv, (const char **)envp);
			else
				execv(path, (const char **)argv);
			err = errno;
			if(err == 0)
				err = ENOEXEC;
			/* The write below is very likely to go nowhere:
			 * see the note on exec failure at the top. */
		}
		write(p[1], &err, sizeof err);
		_exit(127);
	}

	close(p[1]);
	err = 0;
	n = read(p[0], &err, sizeof err);
	close(p[0]);
	if(n == (int)sizeof err && err != 0){
		/* Reap the child so it does not linger as a zombie; the
		 * caller was never told a pid, so nobody else will. */
		while(waitpid(child, &status, 0) < 0 && errno == EINTR)
			;
		return err;
	}
	if(pid != NULL)
		*pid = child;
	return 0;
}

int
posix_spawn(pid_t *pid, const char *path,
	const posix_spawn_file_actions_t *fa, const posix_spawnattr_t *at,
	char *const argv[], char *const envp[])
{
	return spawn(pid, path, fa, at, argv, envp, 0);
}

int
posix_spawnp(pid_t *pid, const char *file,
	const posix_spawn_file_actions_t *fa, const posix_spawnattr_t *at,
	char *const argv[], char *const envp[])
{
	return spawn(pid, file, fa, at, argv, envp, 1);
}
