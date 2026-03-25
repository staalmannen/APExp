/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>

#include <slibtool/slibtool.h>
#include "slibtool_spawn_impl.h"
#include "slibtool_snprintf_impl.h"

static void slbt_util_dump_machine_child(
	char *	program,
	int	fd[2])
{
	char *	compiler;
	char *	argv[3];

	close(fd[0]);

	if ((compiler = strrchr(program,'/')))
		compiler++;
	else
		compiler = program;

	argv[0] = compiler;
	argv[1] = "-dumpmachine";
	argv[2] = 0;

	if ((fd[0] = openat(AT_FDCWD,"/dev/null",O_RDONLY,0)) >= 0)
		if (dup2(fd[0],0) == 0)
			if (dup2(fd[1],1) == 1)
				execvp(program,argv);

	_exit(EXIT_FAILURE);
}

int slbt_util_dump_machine(
	const char *	compiler,
	char *		machine,
	size_t		buflen)
{
	ssize_t	ret;
	pid_t	pid;
	pid_t	rpid;
	int	code;
	int	fd[2];
	char *	mark;
	char	program[PATH_MAX];

	/* setup */
	if (!machine || !buflen || !--buflen) {
		errno = EINVAL;
		return -1;
	}

	if (slbt_snprintf(program,sizeof(program),
			"%s",compiler) < 0)
		return -1;

	/* fork */
	if (pipe(fd))
		return -1;

	if ((pid = slbt_fork()) < 0) {
		close(fd[0]);
		close(fd[1]);
		return -1;
	}

	/* child */
	if (pid == 0)
		slbt_util_dump_machine_child(
			program,
			fd);

	/* parent */
	close(fd[1]);

	mark = machine;

	for (; buflen; ) {
		ret = read(fd[0],mark,buflen);

		while ((ret < 0) && (errno == EINTR))
			ret = read(fd[0],mark,buflen);

		if (ret > 0) {
			buflen -= ret;
			mark   += ret;

		} else if (ret == 0) {
			close(fd[0]);
			buflen = 0;

		} else {
			close(fd[0]);
			return -1;
		}
	}

	/* execve verification */
	rpid = waitpid(
		pid,
		&code,
		0);

	if ((rpid != pid) || code) {
		errno = ESTALE;
		return -1;
	}

	/* newline verification */
	if ((mark == machine) || (*--mark != '\n')) {
		errno = ERANGE;
		return -1;
	}

	*mark = 0;

	/* portbld <--> unknown synonym? */
	if ((mark = strstr(machine,"-portbld-")))
		memcpy(mark,"-unknown",8);

	/* all done */
	return 0;
}
