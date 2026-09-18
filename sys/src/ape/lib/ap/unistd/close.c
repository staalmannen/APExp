#include "lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "sys9.h"

int
close(int d)
{
	int n;
	Fdinfo *f;

	n = -1;
	f = &_fdinfo[d];
	if(d<0 || d>=OPEN_MAX || !(f->flags&FD_ISOPEN))
		errno = EBADF;
	else{
		/*
		 * FIRST, before anything else about this descriptor is taken
		 * apart: a listening socket is a pipe here and the port is
		 * held by the process listen() forked, so closing this
		 * descriptor would otherwise free nothing. No-op for every
		 * descriptor that is not one. See
		 * ap/network/_sock_listenpid.c for why it is keyed on the
		 * file and the owner rather than on the number.
		 */
		_sock_killlisten(d);
		if(f->flags&(FD_BUFFERED|FD_BUFFEREDX)) {
			if(f->flags&FD_BUFFERED)
				_closebuf(d);
			f->flags &= ~FD_BUFFERED;
		}
		_fdinfo[d].flags = 0;
		_fdinfo[d].oflags = 0;
		if(_fdinfo[d].name){
			free(_fdinfo[d].name);
			_fdinfo[d].name = 0;
		}
		n = _CLOSE(d);
		if(n < 0)
			_syserrno();
	}
	return n;
}
