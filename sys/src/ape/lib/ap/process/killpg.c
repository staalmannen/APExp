#include <sys/types.h>
#include <signal.h>
#include <errno.h>

int
killpg(pid_t pgrp, int sig)
{
	(void)pgrp; (void)sig;
	errno = ESRCH;
	return -1;
}
