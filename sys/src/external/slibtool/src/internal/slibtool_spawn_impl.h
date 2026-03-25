/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#ifndef SLIBTOOL_SPAWN_IMPL_H
#define SLIBTOOL_SPAWN_IMPL_H

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/wait.h>

#ifndef PATH_MAX
#define PATH_MAX (_XOPEN_PATH_MAX < 4096) ? 4096 : _XOPEN_PATH_MAX
#endif

#ifndef SLBT_USE_FORK
#ifndef SLBT_USE_VFORK
#ifndef SLBT_USE_POSIX_SPAWN
#define SLBT_USE_POSIX_SPAWN
#endif
#endif
#endif

#ifdef  SLBT_USE_POSIX_SPAWN
#include <spawn.h>
#endif

#ifdef __midipix__
static pid_t slbt_fork(void) {return vfork();}
#else
static pid_t slbt_fork(void) {return fork();}
#endif

static inline int slbt_spawn(
	struct slbt_exec_ctx *	ectx,
	bool			fwait)
{
	pid_t	pid;

#ifdef SLBT_USE_POSIX_SPAWN

	if (posix_spawnp(
			&pid,
			ectx->x_program,
			0,0,
			ectx->x_argv,
			ectx->x_envp))
		pid = -1;

#else

#ifdef SLBT_USE_FORK
	pid = fork();
#else
	pid = vfork();
#endif

#endif

	(void)slbt_fork;

	if (pid < 0) {
		ectx->x_pid      = pid;
		ectx->x_exitcode = errno;
		return -1;
	}

	if (pid == 0) {
		execvp(
			ectx->x_program,
			ectx->x_argv);
		_exit(errno);
	}

	errno     = 0;
	ectx->x_pid = pid;

	if (fwait)
		return waitpid(
			pid,
			&ectx->x_exitcode,
			0);

	return 0;
}

#endif
