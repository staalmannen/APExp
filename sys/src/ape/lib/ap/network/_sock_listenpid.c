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
 *
 * AND THE ENTRY IS KEYED ON THE FILE, NOT ON THE DESCRIPTOR NUMBER,
 * which the first version of this file got wrong and which cost a whole
 * suite run. A descriptor number is reused constantly; nothing clears an
 * entry when one is retired by dup2() or by a raw _CLOSE() that does not
 * go through close(). So a stale pid could sit against a number that had
 * come back as something else entirely, and the next close() of it would
 * SIGKILL a live and unrelated process.
 *
 * kill() is what makes that certain rather than theoretical: it opens
 * /proc/N/note and CLOSES it, so every kill from here re-enters this
 * function on whatever descriptor number that open happened to get.
 *
 * What it looked like from outside was the suite freezing in chanio.test
 * at low CPU -- and _buf.c already says why that is the expected shape:
 * kill the timer process or a copy process and every blocking select()
 * that needs a wakeup waits for ever. Same family as the timer bug two
 * hundred lines away, reached by a different route.
 *
 * So dev/ino are recorded with the pid and checked with fstat() before
 * the kill. A reused number does not match, and a reused number is
 * exactly the dangerous case.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"
#include "sys9.h"

typedef struct Lproc Lproc;
struct Lproc {
	int		pid;	/* the listening process, 0 for none */
	int		owner;	/* the process that forked it */
	dev_t		dev;	/* the file this descriptor WAS, so that a */
	ino_t		ino;	/* number that came back as something else */
};				/* cannot be mistaken for it */

static Lproc lproc[OPEN_MAX];

/*
 * kill() below opens /proc/N/note and closes it, and close() calls this
 * function, so a kill from here re-enters it. The dev/ino check already
 * makes that harmless; this makes it impossible, so that the reasoning
 * needed to see it is safe does not have to be redone by the next
 * reader. Not a lock: there is one thread of control in a process here,
 * and a fork copies the flag clear because it is only ever set across a
 * call that does not fork.
 */
static int killing;

/*
 * WHAT ACTUALLY HAPPENED, ON DEMAND. Two rounds went on guesses about
 * why a closed listener still held its port -- an ordering that turned
 * out not to matter, and a teardown that turned out not to close the
 * descriptor. Both were reasoning where a printed line would have
 * settled it in one run, which is this tree's oldest rule.
 *
 * $APEXP_LISTENDEBUG turns on one line per decision, on standard error.
 * write(2) and a hand-rolled number: stdio here would pull the whole of
 * it into close.o, which every program links.
 */
static int dbgon = -1;

static void
dbg(const char *what, int fd, int pid)
{
	char buf[128], *p, *q, n[16];
	int v, i;

	if(dbgon < 0)
		dbgon = getenv("APEXP_LISTENDEBUG") != 0;
	if(dbgon == 0)
		return;
	p = buf;
	q = buf + sizeof buf - 2;
	for(i = 0; "listenpid: "[i] && p < q; i++)
		*p++ = "listenpid: "[i];
	for(i = 0; what[i] && p < q; i++)
		*p++ = what[i];
	for(i = 0; " fd="[i] && p < q; i++)
		*p++ = " fd="[i];
	v = fd;
	i = 0;
	if(v < 0){ *p++ = '-'; v = -v; }
	do { n[i++] = '0' + v%10; v /= 10; } while(v && i < (int)sizeof n);
	while(i > 0 && p < q)
		*p++ = n[--i];
	for(i = 0; " pid="[i] && p < q; i++)
		*p++ = " pid="[i];
	v = pid;
	i = 0;
	if(v < 0){ *p++ = '-'; v = -v; }
	do { n[i++] = '0' + v%10; v /= 10; } while(v && i < (int)sizeof n);
	while(i > 0 && p < q)
		*p++ = n[--i];
	*p++ = '\n';
	write(2, buf, p - buf);
}

void
_sock_setlisten(int fd, int pid)
{
	struct stat st;

	if(fd < 0 || fd >= OPEN_MAX)
		return;
	if(fstat(fd, &st) < 0)
		return;			/* cannot identify it: do not record it */
	lproc[fd].pid = pid;
	lproc[fd].owner = getpid();
	lproc[fd].dev = st.st_dev;
	lproc[fd].ino = st.st_ino;
	dbg("recorded a listener", fd, pid);
}

void
_sock_killlisten(int fd)
{
	struct stat st;
	int pid;

	if(fd < 0 || fd >= OPEN_MAX)
		return;
	if((pid = lproc[fd].pid) <= 0){
		dbg("close of a descriptor with no listener", fd, 0);
		return;
	}
	/*
	 * IS THIS STILL THE SAME FILE? If the number has come back as
	 * something else the entry is stale, and killing on it would kill
	 * a live process that has nothing to do with this descriptor.
	 * Clear it and do nothing -- the listener it named is unreachable
	 * from here either way, and a wrong kill is far worse than a
	 * missed one.
	 */
	if(fstat(fd, &st) < 0
	|| st.st_dev != lproc[fd].dev || st.st_ino != lproc[fd].ino){
		lproc[fd].pid = 0;
		lproc[fd].owner = 0;
		dbg("STALE: fstat says this is a different file now", fd, pid);
		return;
	}
	/*
	 * Forget it either way: an inherited entry must not be retried,
	 * and the number is about to be reused.
	 */
	lproc[fd].pid = 0;
	if(lproc[fd].owner != getpid()){
		dbg("NOT OURS: recorded by another process", fd, pid);
		return;			/* not ours to kill -- see above */
	}
	lproc[fd].owner = 0;
	if(killing){
		dbg("RE-ENTERED: declining to kill", fd, pid);
		return;
	}
	killing = 1;
	dbg("killing the listener", fd, pid);
	if(kill(pid, SIGKILL) < 0)
		dbg("...and kill FAILED", fd, pid);
	else
		dbg("...kill returned 0", fd, pid);
	killing = 0;
}
