/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

/* bsd extensions */
#include <sys/uio.h>
#include <sys/socket.h>

#include "priv.h"

#include <lock.h>

static Lock _sock_lock;
static Rock *_sock_rock;

Rock*
_sock_findrock(int fd, struct stat *dp)
{
	Rock *r;
	struct stat d;

	if(dp == 0)
		dp = &d;
	if(fstat(fd, dp) < 0)
		return 0;
	lock(&_sock_lock);
	for(r = _sock_rock; r; r = r->next){
		if(r->inode == dp->st_ino
		&& r->dev == dp->st_dev)
			break;
	}
	unlock(&_sock_lock);
	return r;
}

Rock*
_sock_newrock(int fd)
{
	Rock *r;
	struct stat d;

	if(fstat(fd, &d) < 0)
		return 0;
	lock(&_sock_lock);
	for(r = _sock_rock; r; r = r->next){
		if(r->inode == d.st_ino
		&& r->dev == d.st_dev)
			break;
	}
	if(r == 0){
		r = malloc(sizeof(Rock));
		if(r == 0){
			unlock(&_sock_lock);
			return 0;
		}
		r->dev = d.st_dev;
		r->inode = d.st_ino;
		r->next = _sock_rock;
		_sock_rock = r;
	}
	unlock(&_sock_lock);
	memset(&r->raddr, 0, sizeof(r->raddr));
	memset(&r->addr, 0, sizeof(r->addr));
	r->reserved = 0;
	r->other = -1;
	return r;
}

int
_sock_data(int cfd, char *net, int domain, int stype, int protocol, Rock **rp)
{
	int n, fd;
	Rock *r;
	char name[Ctlsize];

	/* get the data file name */
	n = read(cfd, name, sizeof(name)-1);
	if(n < 0){
		close(cfd);
		errno = ENOBUFS;
		return -1;
	}
	name[n] = 0;
	n = strtoul(name, 0, 0);
	snprintf(name, sizeof name, "/net/%s/%d/data", net, n);

	/* open data file */
	fd = open(name, O_RDWR);
	close(cfd);
	if(fd < 0){
		errno = ENOBUFS;
		return -1;
	}

	/* hide stuff under the rock */
	snprintf(name, sizeof name, "/net/%s/%d/ctl", net, n);
	r = _sock_newrock(fd);
	if(r == 0){
		close(fd);
		errno = ENOBUFS;
		return -1;
	}
	r->domain = domain;
	r->stype = stype;
	r->protocol = protocol;
	strcpy(r->ctl, name);
	if(rp)
		*rp = r;
	return fd;
}

int
socket(int domain, int stype, int protocol)
{
	Rock *r;
	int cfd, fd, n;
	int pfd[2];
	char *net;

	switch(domain){
	case PF_INET:
	case PF_INET6:
		/* get a free network directory */
		switch(stype){
		case SOCK_DGRAM:
			net = "udp";
			cfd = open("/net/udp/clone", O_RDWR);
			break;
		case SOCK_STREAM:
			net = "tcp";
			cfd = open("/net/tcp/clone", O_RDWR);
			break;
		case SOCK_RDM:
			net = "il";
			cfd = open("/net/il/clone", O_RDWR);
			break;
		default:
			errno = EPROTONOSUPPORT;
			return -1;
		}
		if(cfd < 0)
			return -1;
		return _sock_data(cfd, net, domain, stype, protocol, 0);
	case PF_UNIX:
		if(pipe(pfd) < 0)
			return -1;
		r = _sock_newrock(pfd[0]);
		if(r == 0){
			close(pfd[0]);
			close(pfd[1]);
			errno = ENOBUFS;
			return -1;
		}
		r->domain = domain;
		r->stype = stype;
		r->protocol = protocol;
		r->other = pfd[1];
		return pfd[0];
	default:
		errno = EPROTONOSUPPORT;
		return -1;
	}
}

int
issocket(int fd)
{
	Rock *r;

	r = _sock_findrock(fd, 0);
	return (r != 0);
}

/*
 * Write a control message to a socket's Plan9 ctl file.
 * Returns 0 on success, -1 on error (errno set).
 */
static int
sockctl(int fd, const char *msg)
{
	Rock *r;
	int cfd, n;

	r = _sock_findrock(fd, NULL);
	if(r == NULL || r->ctl[0] == '\0'){
		errno = ENOTSOCK;
		return -1;
	}
	cfd = open(r->ctl, O_WRONLY);
	if(cfd < 0)
		return -1;
	n = strlen(msg);
	if(write(cfd, msg, n) != n){
		close(cfd);
		return -1;
	}
	close(cfd);
	return 0;
}

int
getsockopt(int fd, int level, int opt, void *v, int *len)
{
	Rock *r;

	r = _sock_findrock(fd, NULL);

	switch(level){
	case SOL_SOCKET:
		switch(opt){
		case SO_ERROR:
			if(*len >= (int)sizeof(int)){
				*(int*)v = 0;
				*len = sizeof(int);
			}
			return 0;
		case SO_TYPE:
			if(r == NULL){ errno = ENOTSOCK; return -1; }
			if(*len >= (int)sizeof(int)){
				*(int*)v = r->stype;
				*len = sizeof(int);
			}
			return 0;
		case SO_RCVBUF:
		case SO_SNDBUF:
			if(*len >= (int)sizeof(int)){
				*(int*)v = 65536;
				*len = sizeof(int);
			}
			return 0;
		case SO_KEEPALIVE:
		case SO_REUSEADDR:
		case SO_BROADCAST:
		case SO_OOBINLINE:
			if(*len >= (int)sizeof(int)){
				*(int*)v = 0;
				*len = sizeof(int);
			}
			return 0;
		default:
			errno = ENOPROTOOPT;
			return -1;
		}
	case IPPROTO_TCP:
		switch(opt){
		case TCP_NODELAY:
			if(*len >= (int)sizeof(int)){
				*(int*)v = 0;
				*len = sizeof(int);
			}
			return 0;
		default:
			errno = ENOPROTOOPT;
			return -1;
		}
	default:
		errno = ENOPROTOOPT;
		return -1;
	}
}

int
setsockopt(int fd, int level, int opt, void *v, int len)
{
	int ival;

	ival = (v != NULL && len >= (int)sizeof(int)) ? *(int*)v : 0;
	(void)ival;

	switch(level){
	case SOL_SOCKET:
		switch(opt){
		case SO_KEEPALIVE:
			if(ival)
				return sockctl(fd, "keepalive 120000");
			return 0;
		case SO_REUSEADDR:
		case SO_BROADCAST:
		case SO_OOBINLINE:
		case SO_SNDBUF:
		case SO_RCVBUF:
		case SO_LINGER:
			/* Plan9 handles these transparently */
			return 0;
		default:
			errno = ENOPROTOOPT;
			return -1;
		}
	case IPPROTO_TCP:
		switch(opt){
		case TCP_NODELAY:
			if(ival)
				return sockctl(fd, "nodelay");
			return 0;
		default:
			errno = ENOPROTOOPT;
			return -1;
		}
	default:
		errno = ENOPROTOOPT;
		return -1;
	}
}

