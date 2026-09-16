#define  _BSDTIME_EXTENSION
#define _LOCK_EXTENSION
#include "lib.h"
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <lock.h>
#include <sys/time.h>
#include <sys/select.h>
#include <unistd.h>
#include "sys9.h"

typedef struct Muxseg {
	Lock	lock;			/* for mutual exclusion access to buffer variables */
	int	curfds;			/* number of fds currently buffered */
	int	selwait;		/* true if selecting process is waiting */
	int	waittime;		/* time for timer process to wait */
	fd_set	rwant;			/* fd's that select wants to read */
	fd_set	ewant;			/* fd's that select wants to know eof info on */
	Muxbuf	bufs[OPEN_MAX];
} Muxseg;

static Muxseg *mux = 0;			/* shared memory segment */

/* _muxsid and _killmuxsid are known in libbsd's listen.c */
int _muxsid = -1;			/* group id of copy processes */
static int _mainpid = -1;
static int timerpid = -1;		/* pid of a timer process */

void _killmuxsid(void);
static void _copyproc(int, Muxbuf*);
static void _timerproc(void);
static void _resettimer(void);

static int copynotehandler(void *, char *);

/* assume FD_SETSIZE is 96 */
#define FD_ANYSET(p)	((p)->fds_bits[0] || (p)->fds_bits[1] || (p)->fds_bits[2])

/*
 * Start making fd read-buffered: make the shared segment, if necessary,
 * allocate a slot (index into mux->bufs), and fork a child to read the fd
 * and write into the slot-indexed buffer.
 * Return -1 if we can't do it.
 */
int
_startbuf(int fd)
{
	int i, pid;
	Fdinfo *f;
	Muxbuf *b;
	void *v;
	Muxseg *m;

	if(mux == 0){
		if(_RFORK(RFREND) == -1){
			_syserrno();
			return -1;
		}
		m = (Muxseg*)_SEGATTACH(0, "shared", 0, sizeof(Muxseg));
		if(m == (void*)-1){
			_syserrno();
			return -1;
		}
		mux = m;
		/* segattach has returned zeroed memory */
		atexit(_killmuxsid);
	}

	if(fd < 0)
		return 0;

	lock(&mux->lock);
	f = &_fdinfo[fd];
	if((f->flags&FD_ISOPEN) == 0){
		unlock(&mux->lock);
		errno = EBADF;
		return -1;
	}
	if((f->flags&FD_BUFFERED) != 0){
		unlock(&mux->lock);
		return 0;
	}
	if((f->flags&FD_BUFFEREDX) != 0){
		unlock(&mux->lock);
		errno = EIO;
		return -1;
	}
	for(b = mux->bufs; b < &mux->bufs[mux->curfds]; b++)
		if(b->fd == -1)
			goto Found;
	if(mux->curfds >= OPEN_MAX){
		unlock(&mux->lock);
		errno = ENFILE;
		return -1;
	}
	mux->curfds++;
Found:
	b->n = 0;
	b->putnext = b->data;
	b->getnext = b->data;
	b->eof = 0;
	b->fd = fd;
	if(_mainpid == -1)
		_mainpid = getpid();
	if((pid = _RFORK(RFFDG|RFPROC|RFNOWAIT)) == 0){
		/* copy process ... */
		if(_muxsid == -1) {
			_RFORK(RFNOTEG);
			_muxsid = getpgrp();
		} else
			setpgid(getpid(), _muxsid);
		_NOTIFY(copynotehandler);
		for(i=0; i<OPEN_MAX; i++)
			if(i!=fd && (_fdinfo[i].flags&FD_ISOPEN))
				_CLOSE(i);
		while(_RENDEZVOUS(&b->copypid, (void*)_muxsid) == (void*)~0)
			;
		_copyproc(fd, b);
	}
	/* parent process continues ... */
	b->copypid = pid;
	f->buf = b;
	f->flags |= FD_BUFFERED;
	unlock(&mux->lock);

	while((v = _RENDEZVOUS(&b->copypid, 0)) == (void*)~0)
		;
	_muxsid = (uintptr_t)v;

	/* leave fd open in parent so system doesn't reuse it */
	return 0;
}

/*
 * The given buffered fd is being closed.
 * Set the fd field in the shared buffer to -1 to tell copyproc
 * to exit, and kill the copyproc.
 */
void
_closebuf(int fd)
{
	Muxbuf *b;
	int i;

	b = _fdinfo[fd].buf;
	if(b == 0 || mux == 0)
		return;
	lock(&mux->lock);
	if(b->fd == fd){
		b->fd = -1;
		for(i=0; i<10 && kill(b->copypid, SIGKILL)==0; i++)
			_SLEEP(1);
	}
	unlock(&mux->lock);
}

/* child copy procs execute this until eof */
static void
_copyproc(int fd, Muxbuf *b)
{
	unsigned char *e;
	int n;
	int nzeros;

	e = &b->data[PERFDMAX];
	for(;;) {
		/* make sure there's room */
		lock(&mux->lock);
		if(b->fd == fd && (e - b->putnext) < READMAX) {
			if(b->getnext == b->putnext) {
				b->getnext = b->putnext = b->data;
				unlock(&mux->lock);
			} else {
				/* sleep until there's room */
				b->roomwait = 1;
				unlock(&mux->lock);
				_RENDEZVOUS(&b->roomwait, 0);
			}
		} else
			unlock(&mux->lock);
		/*
		 * A Zero-length _READ might mean a zero-length write
		 * happened, or it might mean eof; try several times to
		 * disambiguate (posix read() discards 0-length messages)
		 */
		n = 0;
		nzeros = 0;
		do {
			if(b->fd != fd)
				break;
			n = _READ(fd, b->putnext, READMAX);
		} while(b->fd == fd && n == 0 && ++nzeros < 3);
		lock(&mux->lock);
		if(b->fd != fd){
			unlock(&mux->lock);
			_exit(0);	/* we've been closed */
		}
		if(n <= 0) {
			b->eof = 1;
			if(mux->selwait && FD_ISSET(fd, &mux->ewant)) {
				mux->selwait = 0;
				unlock(&mux->lock);
				_RENDEZVOUS(&mux->selwait, (void*)fd);
			} else if(b->datawait) {
				b->datawait = 0;
				unlock(&mux->lock);
				_RENDEZVOUS(&b->datawait, 0);
			} else if(mux->selwait && FD_ISSET(fd, &mux->rwant)) {
				mux->selwait = 0;
				unlock(&mux->lock);
				_RENDEZVOUS(&mux->selwait, (void*)fd);
			} else
				unlock(&mux->lock);
			_exit(0);
		} else {
			b->putnext += n;
			b->n += n;
			if(b->n > 0) {
				/* parent process cannot be both in datawait and selwait */
				if(b->datawait) {
					b->datawait = 0;
					unlock(&mux->lock);
					/* wake up _bufreading process */
					_RENDEZVOUS(&b->datawait, 0);
				} else if(mux->selwait && FD_ISSET(fd, &mux->rwant)) {
					mux->selwait = 0;
					unlock(&mux->lock);
					/* wake up selecting process */
					_RENDEZVOUS(&mux->selwait, (void*)fd);
				} else
					unlock(&mux->lock);
			} else
				unlock(&mux->lock);
		}
	}
}

/* like read(), for a buffered fd; extra arg noblock says don't wait for data if true */
int
_readbuf(int fd, void *addr, int nwant, int noblock)
{
	Muxbuf *b;
	int ngot;

	b = _fdinfo[fd].buf;
	if(b == nil || b->fd != fd){
badfd:
		errno = EBADF;
		return -1;
	}
	if(b->eof && b->n == 0) {
goteof:
		return 0;
	}
	if(b->n == 0 && noblock) {
		errno = EAGAIN;
		return -1;
	}
	lock(&mux->lock);
	if(b->fd != fd){
		unlock(&mux->lock);
		goto badfd;
	}
	/* make sure there's data */
	ngot = b->putnext - b->getnext;
	if(ngot == 0) {
		/* maybe EOF just happened */
		if(b->eof) {
			unlock(&mux->lock);
			goto goteof;
		}
		/* sleep until there's data */
		b->datawait = 1;
		unlock(&mux->lock);
		_RENDEZVOUS(&b->datawait, 0);
		lock(&mux->lock);
		if(b->fd != fd){
			unlock(&mux->lock);
			goto badfd;
		}
		ngot = b->putnext - b->getnext;
	}
	if(ngot == 0) {
		unlock(&mux->lock);
		goto goteof;
	}
	if(ngot > nwant)
		ngot = nwant;
	memcpy(addr, b->getnext, ngot);
	b->getnext += ngot;
	b->n -= ngot;
	if(b->getnext == b->putnext && b->roomwait) {
		b->getnext = b->putnext = b->data;
		b->roomwait = 0;
		unlock(&mux->lock);
		/* wake up copy process */
		_RENDEZVOUS(&b->roomwait, 0);
	} else
		unlock(&mux->lock);
	return ngot;
}

/*
 * Give the copy processes started by this very select() a bounded
 * chance to have read something, and return the moment one of them
 * has. See the long note at the call site: this is the only answer the
 * copy-process design leaves for a zero-timeout poll on a descriptor
 * nothing has read yet, and it is paid once per descriptor.
 */
#define FRESHTRIES	10		/* at most 10ms, once per fd */
#define FRESHMS		1

static void
waitfresh(fd_set *fresh, int nfds)
{
	int i, j;
	Muxbuf *b;

	for(j = 0; j < FRESHTRIES; j++){
		for(i = 0; i < nfds; i++){
			if(!FD_ISSET(i, fresh))
				continue;
			b = _fdinfo[i].buf;
			if(b != 0 && (b->n > 0 || b->eof))
				return;
		}
		_SLEEP(FRESHMS);
	}
}

int
select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *efds, struct timeval *timeout)
{
	int n, i, t, slots, fd, err, nfresh;
	fd_set fresh;
	long long tms;
	Fdinfo *f;
	Muxbuf *b;

	if(timeout) {
		tms = (long long)timeout->tv_sec*1000 + ((long long)timeout->tv_usec+999)/1000;
		/* clamp to INT_MAX; waittime/SLEEP are 32-bit kernel interfaces */
		t = (tms > 0x7fffffff) ? 0x7fffffff : (int)tms;
	} else
		t = -1;
	if(!((rfds && FD_ANYSET(rfds)) || (wfds && FD_ANYSET(wfds))
			|| (efds && FD_ANYSET(efds)))) {
		/* no requested fds */
		if(t > 0)
			_SLEEP(t);
		return 0;
	}

	if(_startbuf(-1) != 0)
		return -1;

	/* make sure all requested rfds and efds are buffered */
	FD_ZERO(&fresh);
	nfresh = 0;
	if(nfds >= OPEN_MAX)
		nfds = OPEN_MAX;
	for(i = 0; i < nfds; i++)
		if((rfds && FD_ISSET(i, rfds)) || (efds && FD_ISSET(i, efds))){
			f = &_fdinfo[i];
			if((f->flags&FD_ISOPEN) == 0){
				errno = EBADF;
				return -1;
			}
			if((f->flags&FD_BUFFERED) == 0){
				if(_startbuf(i) != 0)
					return -1;
				FD_SET(i, &fresh);
				nfresh++;
			}
		}

	/*
	 * A DESCRIPTOR THIS CALL HAS JUST BUFFERED CANNOT BE ANSWERED
	 * YET, and with t == 0 there is nothing else to make us wait.
	 *
	 * Measured by sys/lib/tests/select-test.c: a pipe with six bytes
	 * already in it is reported by a blocking select (section 1) and
	 * not by a zero-timeout poll on the same descriptor (section 2),
	 * while a poll a second later (3b) or straight after a blocking
	 * select (3c) does report it. So it is a race and not a dead
	 * path, and it is a race with the copy process this call has just
	 * forked: _startbuf already rendezvouses, so the child is running
	 * by the time it returns, but its first _READ has not finished.
	 * Everything below then reads b->n and b->eof as zero and the
	 * t == 0 arm returns at once.
	 *
	 * What it costs is every Tcl_DoOneEvent(TCL_DONT_WAIT) in every
	 * Tcl program -- `update`, the suite's `testfilehandler oneevent`
	 * -- on its first look at any descriptor. Tcl's event-1.1 reports
	 * {0 0} {0 0} {0 0} where it wants {0 0} {1 0} {2 0}, which is
	 * exactly this.
	 *
	 * THIS IS AN APPROXIMATION AND THE DESIGN LEAVES NO ALTERNATIVE.
	 * Plan 9 has no non-destructive way to ask whether a file has
	 * data, which is the whole reason select() here is a copy process
	 * rather than a system call -- so a poll on a descriptor nothing
	 * has read yet cannot be answered without giving that process a
	 * moment. Waiting for its first read to COMPLETE would be exact
	 * and is not available: on an idle descriptor that read blocks,
	 * and a poll that blocks for ever is worse than one that answers
	 * "not ready".
	 *
	 * So it is bounded, and it is paid ONCE PER DESCRIPTOR -- the fd
	 * is FD_BUFFERED from here on, so no later poll comes through
	 * here at all. It also returns the moment anything is ready, so
	 * the common case costs a single check.
	 */
	if(nfresh > 0 && t == 0)
		waitfresh(&fresh, nfds);

	/* check wfds;  for now, we'll say they are all ready */
	n = 0;
	if(wfds && FD_ANYSET(wfds)){
		for(i = 0; i<nfds; i++)
			if(FD_ISSET(i, wfds)) {
				f = &_fdinfo[i];
				if((f->flags&FD_ISOPEN) == 0){
					errno = EBADF;
					return -1;
				}
				n++;
			}
	}

	lock(&mux->lock);

	slots = mux->curfds;
	FD_ZERO(&mux->rwant);
	FD_ZERO(&mux->ewant);

	for(i = 0; i<slots; i++) {
		b = &mux->bufs[i];
		fd = b->fd;
		if(fd == -1)
			continue;
		err = 0;
		if(efds && FD_ISSET(fd, efds)) {
			if(b->eof && b->n == 0){
				err = 1;
				n++;
			}else{
				FD_CLR(fd, efds);
				FD_SET(fd, &mux->ewant);
			}
		}
		if(rfds && FD_ISSET(fd, rfds)) {
			if(!err && (b->n > 0 || b->eof))
				n++;
			else{
				FD_CLR(fd, rfds);
				FD_SET(fd, &mux->rwant);
			}
		}
	}
	if(n || !(FD_ANYSET(&mux->rwant) || FD_ANYSET(&mux->ewant)) || t == 0) {
		FD_ZERO(&mux->rwant);
		FD_ZERO(&mux->ewant);
		unlock(&mux->lock);
		return n;
	}

	if(timeout) {
		mux->waittime = t;
		if(timerpid == -1)
			_timerproc();
		else
			_resettimer();
	}
	mux->selwait = 1;
	unlock(&mux->lock);
	fd = (int)(uintptr_t)_RENDEZVOUS(&mux->selwait, 0);
	if(fd >= 0 && fd < nfds) {
		b = _fdinfo[fd].buf;
		if(b == 0 || b->fd != fd) {
		} else  if(FD_ISSET(fd, &mux->rwant)) {
			FD_SET(fd, rfds);
			n = 1;
		} else if(FD_ISSET(fd, &mux->ewant) && b->eof && b->n == 0) {
			FD_SET(fd, efds);
			n = 1;
		}
	}
	return n;
}

static int timerreset;
static int timerpid;

static void
alarmed(int)
{
	timerreset = 1;
}

/* a little over an hour */
#define LONGWAIT 4000001

static void
_killtimerproc(void)
{
	if(timerpid > 0)
		kill(timerpid, SIGKILL);
}

static void
_timerproc(void)
{
	int i;

	if((timerpid = _RFORK(RFFDG|RFPROC|RFNOWAIT)) == 0){
		/* timer process */
		setpgid(getpid(), _muxsid);
		signal(SIGALRM, alarmed);
		for(i=0; i<OPEN_MAX; i++)
				_CLOSE(i);
		while(_RENDEZVOUS(&timerpid, 0) == (void*)~0)
			;
		for(;;) {
			_SLEEP(mux->waittime);
			if(timerreset) {
				timerreset = 0;
			} else {
				lock(&mux->lock);
				if(mux->selwait && mux->waittime != LONGWAIT) {
					mux->selwait = 0;
					mux->waittime = LONGWAIT;
					unlock(&mux->lock);
					_RENDEZVOUS(&mux->selwait, (void*)-2);
				} else {
					mux->waittime = LONGWAIT;
					unlock(&mux->lock);
				}
			}
		}
	}
	/* parent process continues */
	if(timerpid > 0){
		atexit(_killtimerproc);
		while(_RENDEZVOUS(&timerpid, 0) == (void*)~0)
			;
	}
}

static void
_resettimer(void)
{
	kill(timerpid, SIGALRM);
}

void
_killmuxsid(void)
{
	if(_muxsid != -1 && (_mainpid == getpid() || _mainpid == -1))
		kill(-_muxsid,SIGTERM);
}

/* call this on fork(), because reading a BUFFERED fd won't work in child */
void
_detachbuf(void)
{
	int i;
	Fdinfo *f;

	if(mux == 0)
		return;
	_SEGDETACH(mux);
	for(i = 0; i < OPEN_MAX; i++){
		f = &_fdinfo[i];
		if(f->flags&FD_BUFFERED)
			f->flags = (f->flags&~FD_BUFFERED) | FD_BUFFEREDX;
				/* mark 'poisoned' */
	}
	mux = 0;
	_muxsid = -1;
	_mainpid = -1;
	timerpid = -1;
}

static int
copynotehandler(void *, char *)
{
	if(_finishing)
		_finish(0, 0);
	_NOTED(1);
	return 0;
}
