#include <stdio.h>
#include <sys/time.h>
#include <sys/select.h>
#include <poll.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>

/*
 * poll() -- THREE POSIX RULES THIS GOT WRONG, and the first two can
 * spin a caller at full speed rather than merely answer oddly.
 *
 * 1. THE RETURN VALUE IS A COUNT OF ENTRIES, NOT OF BITS.  POSIX:
 *    "poll() shall return the number of pollfd structures that have
 *    selected events (nonzero revents)".  This returned select()'s
 *    value, which counts BITS ACROSS THREE fd_sets -- so one
 *    descriptor ready for both reading and writing counted twice, and
 *    poll could report a number larger than the number of entries it
 *    had marked.  **A caller that loops while the return is positive
 *    and the entry it cares about is unmarked then never sleeps**, and
 *    that loop is not hypothetical: `xz's file_io.c io_wait() is
 *    `while(true){ ret = poll(...); if(ret==0) return TIMEOUT;
 *    if(pfd[0].revents) return MORE; }' with nothing in the fall-through
 *    path at all.
 *
 * 2. A NEGATIVE fd WAS SKIPPED WHEN BUILDING THE SETS AND NOT WHEN
 *    READING THEM.  The first loop has `if(p->fd < 0) continue;' and
 *    the second went straight to `FD_ISSET(p->fd, &rfds)' -- an
 *    out-of-bounds read, and whatever it finds becomes a revents the
 *    caller believes.  POSIX says a negative fd is IGNORED and its
 *    revents set to zero.  *The asymmetry between two loops over the
 *    same array is the whole bug*, and `xz' passes exactly this: its
 *    second pollfd is `user_abort_pipe[0]', which is -1 whenever that
 *    pipe was not created.
 *
 * 3. POLLNVAL DID NOT EXIST.  POSIX reports a closed descriptor
 *    per-ENTRY, so the other entries still get answered; this handed
 *    the fd to select(), which fails the WHOLE call with EBADF.  The
 *    fds are checked first now and a bad one is marked and kept out of
 *    the sets.
 *
 * POLLERR, POLLHUP and POLLNVAL are output-only: they are reported
 * whether or not the caller asked for them, which is why they are not
 * consulted when building the sets.
 */
int
poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	int n, nset, ready;
	fd_set rfds, wfds, efds;
	struct timeval w, *wp;
	struct pollfd *p, *ep;

	n = -1;
	nset = 0;
	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	FD_ZERO(&efds);

	ep = fds + nfds;
	for(p = fds; p < ep; p++){
		p->revents = 0;
		if(p->fd < 0)
			continue;
		/* a descriptor that is not open is this ENTRY's error */
		if(fcntl(p->fd, F_GETFD, 0) == -1){
			p->revents = POLLNVAL;
			continue;
		}
		if((p->events&(POLLIN|POLLPRI|POLLOUT)) == 0)
			continue;
		if(p->events&POLLIN)
			FD_SET(p->fd, &rfds);
		if(p->events&POLLOUT)
			FD_SET(p->fd, &wfds);
		if(p->events&POLLPRI)
			FD_SET(p->fd, &efds);
		if(p->fd > n)
			n = p->fd;
		nset++;
	}

	/*
	 * Nothing to wait on. POSIX still wants the timeout honoured,
	 * and any POLLNVAL found above is a result to report at once.
	 */
	if(nset == 0){
		ready = 0;
		for(p = fds; p < ep; p++)
			if(p->revents != 0)
				ready++;
		if(ready == 0 && timeout > 0){
			/*
			 * select() with an empty set is libap's own sleep
			 * (its "no requested fds" arm), so this needs no
			 * Plan 9 header that `select/' cannot reach.
			 */
			w.tv_sec = timeout/1000;
			w.tv_usec = (timeout%1000)*1000;
			select(0, 0, 0, 0, &w);
		}
		return ready;
	}

	wp = NULL;
	if(timeout >= 0){
		w.tv_sec = timeout/1000;
		w.tv_usec = (timeout%1000)*1000;
		wp = &w;
	}
	if(select(n+1, &rfds, &wfds, &efds, wp) < 0)
		return -1;

	/* POLLHUP means the socket is no longer connected. (FIN) */
	/* POLLERR means the socket got an asynchronous error. (RST) */

	ready = 0;
	for(p = fds; p < ep; p++){
		if(p->fd < 0)
			continue;		/* revents already 0 */
		if(p->revents == POLLNVAL){
			ready++;		/* found above, still a result */
			continue;
		}
		if(FD_ISSET(p->fd, &rfds))
			p->revents |= POLLIN;
		if(FD_ISSET(p->fd, &wfds))
			p->revents |= POLLOUT;
		if(FD_ISSET(p->fd, &efds))
			p->revents |= POLLPRI|POLLHUP;
		if(p->revents != 0)
			ready++;
	}
	return ready;
}

/*
 * ppoll — like poll but with nanosecond timeout and atomic signal mask swap.
 * Plan9 has no atomic sigmask+select primitive, so we approximate:
 * convert timespec → milliseconds and delegate to poll().
 * The sigmask argument is ignored (Plan9 signal masking is coarse-grained).
 */
int
ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *ts,
      const sigset_t *sigmask)
{
	long long timeout_ms;
	int timeout;
	(void)sigmask;

	if(ts == NULL) {
		timeout = -1;
	} else {
		timeout_ms = (long long)ts->tv_sec * 1000 + ts->tv_nsec / 1000000;
		/* poll() takes int ms; clamp to INT_MAX (~24.8 days) */
		timeout = (timeout_ms > 0x7fffffff) ? 0x7fffffff : (int)timeout_ms;
	}
	return poll(fds, nfds, timeout);
}
