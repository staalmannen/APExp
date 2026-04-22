#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
pipe2(int pipefd[2], int flags)
{
	if(pipe(pipefd) < 0)
		return -1;
	if(flags & O_CLOEXEC){
		if(fcntl(pipefd[0], F_SETFD, FD_CLOEXEC) < 0 ||
		   fcntl(pipefd[1], F_SETFD, FD_CLOEXEC) < 0)
			goto fail;
	}
	if(flags & O_NONBLOCK){
		if(fcntl(pipefd[0], F_SETFL, O_NONBLOCK) < 0 ||
		   fcntl(pipefd[1], F_SETFL, O_NONBLOCK) < 0)
			goto fail;
	}
	return 0;
fail:;
	int e = errno;
	close(pipefd[0]);
	close(pipefd[1]);
	errno = e;
	return -1;
}

int
dup3(int oldfd, int newfd, int flags)
{
	int r;
	if(oldfd == newfd){
		errno = EINVAL;
		return -1;
	}
	r = dup2(oldfd, newfd);
	if(r < 0)
		return r;
	if(flags & O_CLOEXEC)
		fcntl(newfd, F_SETFD, FD_CLOEXEC);
	return r;
}
