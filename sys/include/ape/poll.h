#ifndef __POLL_H
#define __POLL_H
#pragma lib "/$M/lib/ape/libap.a"

/*
 * FD_SETSIZE lived here as a second 96, independent of the three
 * copies of fd_set. It is <fdset_generic.h>'s now, so the constant and
 * the struct it sizes cannot drift apart again -- which they had, and
 * which select-test.c section 11 measured as `FD_SETSIZE 96, fd_set
 * holds 128`.
 */
#include <fdset_generic.h>

#include <sys/types.h>
#include <time.h>
#include <signal.h>

struct pollfd {
	int fd;			/* file descriptor */
	short events;	/* events to look for */
	short revents;	/* events returned */
};

typedef size_t nfds_t;

#define	POLLIN		0x001
#define	POLLPRI		0x002
#define	POLLOUT		0x004
#define	POLLERR		0x008
#define	POLLHUP		0x010
#define	POLLNVAL	0x020

#define	POLLRDNORM	0x040
#define	POLLRDBAND	0x080
#define	POLLWRNORM	POLLOUT
#define	POLLWRBAND	0x100

#define	INFTIM	-1

#ifdef __cplusplus
extern "C" {
#endif

extern int poll(struct pollfd fds[], nfds_t nfds, int timeout);
extern int ppoll(struct pollfd fds[], nfds_t nfds, const struct timespec *,
                 const sigset_t *);

#ifdef __cplusplus
}
#endif

#endif
