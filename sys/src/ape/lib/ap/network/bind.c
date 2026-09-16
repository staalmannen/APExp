/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <signal.h>

/* socket extensions */
#include <sys/uio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>

/* plan 9 */
#include "lib.h"
#include "sys9.h"

#include "priv.h"

int
bind(int fd, void *a, int alen)
{
	int n, len, cfd;
	struct sockaddr *sa;
	Rock *r;
	char msg[128];

	/* assign the address */
	r = _sock_findrock(fd, 0);
	if(r == 0){
		errno = ENOTSOCK;
		return -1;
	}
	sa = (struct sockaddr*)a;
	if(sa->sa_family != r->domain){
		errno = EAFNOSUPPORT;
		return -1;
	}
	if(alen > sizeof(r->addr)){
		errno = ENAMETOOLONG;
		return -1;
	}
	memmove(&r->addr, a, alen);

	/* the rest is IP sepecific */
	if (r->domain != PF_INET && r->domain != PF_INET6)
		return 0;

	cfd = open(r->ctl, O_RDWR);
	if(cfd < 0){
		errno = EBADF;
		return -1;
	}

	strcpy(msg, "bind ");
	_sock_inaddr2string(r, msg + 5, sizeof msg - 5);

	n = write(cfd, msg, strlen(msg));
	if(n < 0){
		_syserrno();
		if(errno == EPLAN9){
			/*
			 * Some 9front network stacks reject the standalone "bind"
			 * control message.  Tcl calls getsockname() between bind() and
			 * listen() when it requested port zero, so merely deferring the
			 * operation loses the assigned port.  Announce now and let
			 * listen() only start its accept proxy.
			 *
			 * NOTE THIS IS GATED ON EPLAN9, WHICH MEANS "AN ERROR
			 * NOTHING RECOGNISED" -- so adding an entry to the table
			 * in ap/errno/_errno.c STOPS THIS FALLBACK RUNNING for
			 * that error.  That is a control-flow change out of what
			 * looks like a pure naming change, and it was not noticed
			 * until socket-server-test.c reported listen() moving from
			 * FAIL to PASS across the commit that named "not a local
			 * IP address".
			 *
			 * It is the right way round for the two entries added so
			 * far: an address the stack does not own, and an address
			 * it cannot parse, would fail an "announce" identically,
			 * so retrying buys nothing and only muddies the errno.
			 * But BEFORE ADDING ANOTHER ENTRY, ask whether "announce"
			 * might have succeeded where "bind" did not -- that case
			 * is the whole reason this fallback exists, and naming its
			 * error here would silently disable it.
			 */
			close(cfd);
			cfd = open(r->ctl, O_RDWR);
			if(cfd < 0){
				errno = EBADF;
				return -1;
			}
			strcpy(msg, "announce ");
			_sock_inaddr2string(r, msg + 9, sizeof msg - 9);
			n = write(cfd, msg, strlen(msg));
			if(n < 0)
				_syserrno();
			close(cfd);
			if(n < 0){
				if(errno == EPLAN9)
					errno = EOPNOTSUPP;
				return -1;
			}
			r->announced = 1;
			if(_sock_inport(&r->addr) == 0)
				_sock_ingetaddr(r, &r->addr, 0, "local");
			return 0;
		}
		close(cfd);
		return -1;
	}

	close(cfd);

	if(_sock_inport(&r->addr) == 0)
		_sock_ingetaddr(r, &r->addr, 0, "local");

	return 0;
}
