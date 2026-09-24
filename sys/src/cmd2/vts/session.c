/*
 * vts session management — Phase 1.2 + 1.3
 *
 * For each session, vts:
 *   1) rforks a shell into a namespace of its own
 *   2) binds the session's `tty' and `ttyctl' files -- served by vts
 *      over its own 9P -- over /dev/cons and /dev/consctl there
 *   3) gives the shell that /dev/cons for fd 0, 1 and 2
 *   4) waits, in the forking proc, for it to die
 *
 * THE TWO PIPES ARE GONE, and the bind is why. They worked: vts wrote
 * keystrokes into one and drained the shell's output from the other.
 * But a pipe has no name, and libap's isatty() asks fd2path() and
 * matches the PATH ending in "/dev/cons", so fd 0 was never a terminal
 * and bash compiled its line editing out at run time. With the file
 * bound where a terminal belongs, fd2path answers /dev/cons and
 * readline starts. rio does exactly this for its own windows.
 *
 * What was the shellout reader proc is now session_wait_rc: the shell
 * writes its output straight to `tty', so there is nothing left to
 * drain and the only thing worth watching for is its death.
 */
#include "compat.h"
#include <auth.h>
#include <fcall.h>
#include <thread.h>
#include <9p.h>

#include "dat.h"
#include "fns.h"
#include "cells.h"
#include "engine.h"
#include "session.h"

/* libvterm output sink: terminal replies (DA/DSR/cursor reports) are written
 * to the shell's stdin, exactly as if the user had typed them. No-op until
 * rc is spawned (keyin_wfd<0). */
static void
engine_out(void *ctx, const uchar *bytes, int n)
{
	Session *s = (Session*)ctx;
	session_feed_keystrokes(s, (uchar*)bytes, n);
}

/*
 * Wait for the shell to die, then tear the session down.
 *
 * This replaces the old shellout reader proc. The shell's stdout is
 * now the `tty' file served over vts's own 9P (srv.c), so nothing is
 * left to drain -- but something still has to notice the shell exiting,
 * mark the session dead, and answer any terminal read left queued.
 *
 * It MUST run in the proc that called rfork: Plan 9 reports a death to
 * the process that forked it, so a waiter proccreated elsewhere would
 * wait for a child it does not have. spawn_rc_proc calls this straight
 * after session_spawn_rc for that reason.
 */
void
session_wait_rc(Session *s)
{
	Waitmsg *w;
	int killed;

	for(;;){
		w = wait();
		if(w == nil){
			/* No children left, or interrupted. Either way this
			 * session's shell is not coming back. */
			break;
		}
		if(w->pid == s->rc_pid){
			fprint(2, "vts: shell %d exited: %s\n",
				w->pid, w->msg[0] ? w->msg : "ok");
			free(w);
			break;
		}
		free(w);
	}

	qlock(&s->lock);
	s->rc_alive = 0;
	qunlock(&s->lock);

	/* Hand end of file to whoever is blocked reading the terminal. */
	session_tty_wake(s);

	/* Teardown handshake, unchanged in shape from the reader proc it
	 * replaces: whoever sets its flag second frees the session. */
	qlock(&s->lock);
	s->reader_done = 1;
	killed = s->killed;
	qunlock(&s->lock);
	if(killed)
		session_free(s);
}

/* Free a session's heap resources. Caller must be the last user (see
 * the kill/reader handshake): nothing may touch *s afterward. The
 * static first session (onheap==0) keeps its struct; only its buffers
 * are released. */
void
session_free(Session *s)
{
	engine_free(&s->engine);
	cellbuf_free(&s->buf);
	free(s->name);
	s->name = nil;
	if(s->onheap)
		free(s);
}

/*
 * Work out what to exec. `$SHELL' if it names one, `/bin/rc' otherwise.
 *
 * WHY IT IS NOT HARDCODED ANY MORE. The point of all this is bash's own
 * line editing, and bash is NOT in vts's namespace unless vts was
 * started from inside apexp-sh -- which binds APExp's bin over /bin.
 * Hardcoding /bin/bash would fail on a plain rc and hardcoding /bin/rc
 * makes the whole change pointless, so the environment decides.
 *
 * apexp-sh sets SHELL=bash, a BARE NAME rather than a path (it is
 * visible as `bash' in /env/SHELL), and exec() does not search $PATH.
 * So a name without a slash gets /bin/ put in front of it -- which is
 * right exactly when vts is running under apexp-sh, and that is the
 * case the bare name comes from.
 */
static char *
shellpath(char *buf, int nbuf)
{
	char *sh;

	sh = getenv("SHELL");
	if(sh == nil || sh[0] == '\0'){
		free(sh);
		snprint(buf, nbuf, "/bin/rc");
		return buf;
	}
	if(strchr(sh, '/') != nil)
		snprint(buf, nbuf, "%s", sh);
	else
		snprint(buf, nbuf, "/bin/%s", sh);
	free(sh);
	return buf;
}

/*
 * Give the shell a terminal and start it.
 *
 * THE BIND IS THE WHOLE POINT. libap's isatty() calls fd2path and
 * matches the PATH ending in "/dev/cons" (ap/unistd/isatty.c), so the
 * pipe this used to dup onto fd 0 was never a terminal, bash set
 * no_line_editing, and readline never ran -- which is why tab
 * completion needed a rio window rather than a vts one. Opening the
 * session's `tty' file as /mnt/1/tty would not help either: it behaves
 * correctly and still is not named /dev/cons. So the child takes a
 * namespace of its own, mounts vts, and binds the file where a
 * terminal belongs. rio does the same for its windows.
 *
 * /mnt IS THE MOUNT POINT ON PURPOSE. mount() needs a directory that
 * already exists, and /mnt is the one directory every Plan 9 system
 * has; /n/vts is conventional but is not guaranteed to be there, and a
 * mount that fails here leaves a shell with no terminal at all.
 * MBEFORE rather than MREPL so nothing already in /mnt is hidden.
 */
int
session_spawn_rc(Session *s)
{
	int pid;
	char sh[128];

	shellpath(sh, sizeof sh);

	switch(pid = rfork(RFPROC|RFFDG|RFNOTEG|RFENVG|RFNAMEG)){
	case -1:
		fprint(2, "vts: rfork: %r\n");
		return -1;

	case 0:
		{
			int i, sfd, fd;
			char path[128], num[16];

			/*
			 * Close every inherited descriptor first. The 9P srv
			 * connection is among them, and a shell holding it
			 * stops the server being torn down when the shell
			 * exits. Do it BEFORE mounting, so the fd we are
			 * about to open is not caught by the loop.
			 */
			for(i = 3; i < 100; i++)
				close(i);

			sfd = open("/srv/vts", ORDWR);
			if(sfd < 0){
				fprint(2, "vts: child: open /srv/vts: %r\n");
				_exits("srv");
			}
			if(mount(sfd, -1, "/mnt", MBEFORE, "") < 0){
				fprint(2, "vts: child: mount /mnt: %r\n");
				_exits("mount");
			}
			close(sfd);

			snprint(path, sizeof path, "/mnt/%s/tty", s->name);
			if(bind(path, "/dev/cons", MREPL) < 0){
				fprint(2, "vts: child: bind %s /dev/cons: %r\n", path);
				_exits("bind");
			}

			fd = open("/dev/cons", ORDWR);
			if(fd < 0){
				fprint(2, "vts: child: open /dev/cons: %r\n");
				_exits("cons");
			}
			dup(fd, 0);
			dup(fd, 1);
			dup(fd, 2);
			if(fd > 2)
				close(fd);

			/*
			 * consctl LAST, and deliberately after fd 2 is the
			 * terminal, so that if it fails the complaint lands in
			 * the WINDOW the user is looking at rather than in the
			 * one vts was launched from -- which is easy to lose
			 * behind the session and is not where anyone looks when
			 * a shell misbehaves.
			 *
			 * It is not fatal. Without it tcsetattr fails, the
			 * shell falls back to cooked input, and vts's own line
			 * editor keeps cooking -- worse than raw, still a
			 * working shell. Without /dev/cons there is no shell
			 * at all, which is why that one exits.
			 *
			 * WATCH THIS ONE. Everything the shell needs for raw
			 * mode hangs off it: libap's tcsetattr writes rawon
			 * here (ap/plan9/tty.c), that write is what turns
			 * `lined' off, and with lined ON while bash echoes
			 * there are TWO writers feeding one VT parser --
			 * double echo, and escape sequences torn in half.
			 */
			snprint(path, sizeof path, "/mnt/%s/ttyctl", s->name);
			if(bind(path, "/dev/consctl", MREPL) < 0)
				fprint(2, "vts: child: bind %s /dev/consctl: %r\n"
					"vts: raw mode will not work; expect double echo\n",
					path);

			/*
			 * TERM is the one that changes what the screen looks
			 * like. readline with TERM=dumb has no `ce', `up' or
			 * `cm' to redraw a line with (sys/lib/ape/termcap's
			 * whole dumb entry is ":am:co#80:li#24:"), so it
			 * REPRINTS instead, which is the mangled wrapping seen
			 * under rio. The engine here is libvterm, upstream's
			 * full state machine, so vt100 is an honest claim and
			 * the termcap already carries the entry.
			 *
			 * COLUMNS and LINES are read by libap's TIOCGWINSZ
			 * (ap/misc/ioctl.c) -- that half was already in place
			 * and had nothing telling it the truth. vts has a real
			 * character grid, so here it does.
			 */
			putenv("TERM", "vt100");
			snprint(num, sizeof num, "%d", s->buf.cols);
			putenv("COLUMNS", num);
			snprint(num, sizeof num, "%d", s->buf.rows);
			putenv("LINES", num);
			putenv("vts", s->name);

			/*
			 * Carry $APEXP_DEBUG through to the shell when vts
			 * is being traced. libap's _apdbg() reads it, and
			 * its lines go to fd 2 -- which is this terminal, so
			 * they travel back through the server and land in
			 * vts's own log beside the 9P trace. The two halves
			 * of the conversation in one file, in order.
			 */
			{
				char *dbg = getenv("vtsdebug");

				if(dbg != nil && *dbg != '\0')
					putenv("APEXP_DEBUG", "1");
				free(dbg);
			}

			/*
			 * SAY WHAT THE THREE DESCRIPTORS ACTUALLY ARE.
			 *
			 * Every trace so far proves fd 1 and fd 2 -- the
			 * shell's output arrives at vts. NOTHING has ever
			 * proved fd 0, and the shell reading EOF at its first
			 * prompt is exactly what a wrong fd 0 looks like:
			 * writes land on the terminal, the read lands
			 * somewhere else and ends at once. (vts is started in
			 * the background, and rc gives a background command
			 * /dev/null on fd 0.)
			 *
			 * dup(2)'s return value is not checked above, and a
			 * silent failure there is indistinguishable from
			 * success from the outside -- so ask the kernel which
			 * file each descriptor is on rather than trusting the
			 * three calls. This prints on fd 2, which is the
			 * session's own window.
			 */
			{
				char p0[128], p1[128], p2[128];

				strcpy(p0, "?"); strcpy(p1, "?"); strcpy(p2, "?");
				fd2path(0, p0, sizeof p0);
				fd2path(1, p1, sizeof p1);
				fd2path(2, p2, sizeof p2);
				fprint(2, "vts: child: fd0=%s fd1=%s fd2=%s\n",
					p0, p1, p2);
			}

			execl(sh, sh, "-i", nil);
			fprint(2, "vts: child: exec %s: %r\n", sh);
			_exits("exec");
		}
	}

	/* Parent. */
	s->rc_pid = pid;
	s->rc_alive = 1;
	s->keyin_wfd = -1;
	s->shellout_rfd = -1;

	/*
	 * `lined' is LEFT AS session_init set it -- enabled -- and the
	 * shell turns it off itself by writing rawon to ttyctl. Forcing
	 * raw here looked right and is not, for two reasons:
	 *
	 *   - rc does not echo and does not cook, because 9front's rc
	 *     expects a console driver to do both. A session running rc
	 *     with lined off shows nothing at all of what you type. That
	 *     is a regression for every session that is not bash.
	 *   - and the FAILURE MODE decides it. If bash never reaches
	 *     tcsetattr -- wrong shell, a build without READLINE, isatty
	 *     answering no for a reason not yet found -- then with lined
	 *     on you still have a usable cooked shell, and with it off you
	 *     have a window that swallows keystrokes in silence.
	 *
	 * readline preps and unpreps the terminal around every line, so
	 * lined flips back on between commands. That is harmless: nothing
	 * is being typed while a command runs, and type-ahead merely gets
	 * cooked instead of passed through.
	 */

	fprint(2, "vts: %s forked pid=%d on /mnt/%s/tty\n", sh, pid, s->name);
	return 0;
}

/*
 * Keystrokes on their way to the shell.
 *
 * This is the one choke point every path goes through -- a viewer
 * writing `cons', and libvterm's own replies to DA/DSR through
 * engine_out -- which is why swapping the pipe underneath it for the
 * tty queue is the whole of the input change.
 *
 * It no longer writes a pipe. The shell reads `tty' over 9P, so the
 * bytes go into ttyin and any read already waiting is answered.
 */
int
session_feed_keystrokes(Session *s, uchar *bytes, int n)
{
	int room;

	if(!s->rc_alive)
		return -1;
	if(n <= 0)
		return 0;

	qlock(&s->ttylock);
	room = (int)sizeof s->ttyin - s->ttyin_len;
	if(room <= 0){
		qunlock(&s->ttylock);
		/*
		 * The shell is not reading and the queue is full. DROP, and
		 * drop the NEW bytes rather than shifting the old ones out:
		 * a terminal that loses the keystrokes you typed first would
		 * reorder a command line, which is worse than losing the
		 * ones you typed last. 8K is far past any burst a person
		 * produces; reaching here means the shell is wedged.
		 */
		return -1;
	}
	if(n > room)
		n = room;
	memmove(s->ttyin + s->ttyin_len, bytes, n);
	s->ttyin_len += n;
	qunlock(&s->ttylock);

	/* Outside the lock: session_tty_wake takes it itself. */
	session_tty_wake(s);
	return n;
}

void
session_init(Session *s, char *name, int rows, int cols)
{
	s->name = strdup(name);
	cellbuf_init(&s->buf, rows, cols);
	engine_init(&s->engine, &s->buf, rows, cols, engine_out, s);
	lined_init(&s->editor);
	s->ttyin_len = 0;
	s->ttynq = 0;
	s->raw = 0;
	/* Both allocators hand us zeroed storage today (BSS for session 1,
	 * memset in create_session), so this is insurance rather than a
	 * fix -- but a QLock that is reused without being cleared hangs
	 * the first proc to take it, and that failure is unreadable. */
	memset(&s->ttylock, 0, sizeof s->ttylock);
	/* Default: line editor enabled. mxio's cell-grid terminal (vtwin)
	 * is the only client we ship; it expects local echo + line editing
	 * because rc/9front isn't a tty and won't echo or cook input itself.
	 * vts-attach for headless remote can disable via "edit off\n" on
	 * /sess/ctl. */
	lined_set_enabled(&s->editor, 1);
	s->keyin_wfd = -1;
	s->shellout_rfd = -1;
	s->rc_pid = -1;
	s->rc_alive = 0;
	s->keyin_buf_len = 0;
	s->killed = 0;
	s->reader_done = 0;
	/* onheap is set by the allocator (create_session); leave it so the
	 * static first session stays onheap==0. */
}
