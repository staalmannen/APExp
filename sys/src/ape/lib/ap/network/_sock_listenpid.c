/*
 * _sock_listenpid.c -- remember which process is listening on a socket,
 * so that close() can end it.
 *
 * WHERE THIS CAME FROM. `socket -server dodo 1` in Tcl, followed by
 * `close $msg`, and then, in a fresh tclsh on a machine with no suite
 * running:
 *
 *	% socket -server {apply {{c a p} {}}} 1
 *	couldn't open socket: address already in use
 *
 * The port was still announced. A closed listening socket must release
 * its port, and this one did not -- for days, across reboots of the
 * interpreter, because nothing but the death of the process group ever
 * freed it.
 *
 * WHY close() COULD NOT DO IT. listen() does not keep the socket in the
 * calling process at all: ap/network/listen.c replaces the descriptor
 * with a PIPE (so that select() works) and forks a child that holds the
 * real network descriptor and blocks in open("/net/tcp/N/listen"). So
 * the parent's close() shuts a pipe, while the announcement is held by
 * a descriptor in another process. Nothing connected the two.
 *
 * `_killmuxsid` is an atexit handler that kills the whole group when the
 * program exits, and it is not enough for two reasons: a program that
 * closes a listener and keeps running holds the port for its whole life,
 * which is what Tcl's socket tests do; and a run that ends any way other
 * than exit() -- an interrupt, a note, a fault -- runs no atexit handler
 * at all. That is how "over a hundred leaked listenproc processes
 * accumulate across runs" got into the notes.
 *
 * WHAT THIS COSTS IF IT IS WRONG, which is why the owner is recorded.
 * These entries are inherited by every fork, exactly like the atexit
 * handlers. A child that closed an inherited descriptor would kill its
 * PARENT's listener. _buf.c has the same rule written on it in capitals
 * after it cost a round:
 *
 *	ONLY THE PROCESS THAT FORKED THE TIMER MAY KILL IT
 *
 * -- the asymmetry there meant any forked child leaving through exit()
 * took the parent's timer with it. So the owner is stored beside the
 * pid and checked before the kill, and a table inherited by a fork is
 * inert in the child rather than dangerous.
 *
 * SIGKILL rather than SIGTERM: the listener is blocked in an open() that
 * will not return until a call arrives, and the point is to stop it now.
 * _closebuf kills its copy processes the same way.
 */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "lib.h"
#include "sys9.h"

typedef struct Lproc Lproc;
struct Lproc {
	int	pid;		/* the listening process, 0 for none */
	int	owner;		/* the process that forked it */
};

static Lproc lproc[OPEN_MAX];

void
_sock_setlisten(int fd, int pid)
{
	if(fd < 0 || fd >= OPEN_MAX)
		return;
	lproc[fd].pid = pid;
	lproc[fd].owner = getpid();
}

void
_sock_killlisten(int fd)
{
	int pid;

	if(fd < 0 || fd >= OPEN_MAX)
		return;
	if((pid = lproc[fd].pid) <= 0)
		return;
	/*
	 * Forget it either way: an inherited entry must not be retried,
	 * and a descriptor number is about to be reused.
	 */
	lproc[fd].pid = 0;
	if(lproc[fd].owner != getpid())
		return;			/* not ours to kill -- see above */
	lproc[fd].owner = 0;
	kill(pid, SIGKILL);
}
