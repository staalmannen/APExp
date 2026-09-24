/*
 * vts session — shared types and functions.
 *
 * A Session owns one shell process and its cell buffer + parser.
 *
 * Plan 9 only.
 *
 * Note: we do NOT #include <thread.h> here, because the .c files that
 * include this header also include <thread.h> directly. Plan 9 system
 * headers have no include guards. We forward-declare what we need.
 */
#ifndef VTS_SESSION_H
#define VTS_SESSION_H

#include "compat.h"

#include "cells.h"
#include "engine.h"
#include "lined.h"

/* QLock from thread.h. Forward declaration is enough since we only use
 * it as a struct field (sizeof must be known when including session.h,
 * so we duplicate the field layout). Safer alternative: include the
 * header before this file. We rely on session.c and srv.c including
 * <thread.h> BEFORE this file. */
typedef struct QLock VTQLock;

enum { MAXSESS = 64 };

typedef struct Session Session;
struct Session {
	char *name;
	Buffer buf;
	Engine engine;
	LineEditor editor;

	/* Cast as QLock; using opaque size from the include order. */
	QLock lock;

	int keyin_wfd;
	int shellout_rfd;
	int rc_pid;
	int rc_alive;

	uchar keyin_buf[4096];
	int keyin_buf_len;

	/*
	 * THE SHELL'S TERMINAL.
	 *
	 * `tty' is a per-session file served over vts's own 9P, and the
	 * shell gets it BOUND OVER /dev/cons in a namespace of its own.
	 * That bind is the whole reason the file exists rather than the
	 * pipe that used to be here: libap's isatty() asks fd2path() and
	 * matches the PATH ending in "/dev/cons" (ap/unistd/isatty.c --
	 * the suffix test is there for /mnt/term/dev/cons), so a pipe, or
	 * this same file opened as /mnt/1/tty, is not a terminal however
	 * well it behaves. With the bind, fd2path answers /dev/cons and
	 * bash starts readline. It is also what rio does for its windows.
	 *
	 * ttyin is what the shell will READ: keystrokes that arrived from
	 * a viewer through session_feed_keystrokes(). It is a stream, so a
	 * read CONSUMES it -- unlike keyin_buf above, which is a snapshot
	 * read by offset for the viewer-facing `cons' file.
	 *
	 * ttyq holds the reads that arrived with ttyin empty. A terminal
	 * read BLOCKS, and lib9p's way to block is to keep the Req and
	 * respond() to it later.
	 *
	 * IT IS AN ARRAY RATHER THAN A LIST THREADED THROUGH Req.aux, and
	 * that is deliberate: lib9p owns Req, this tree does not vendor
	 * <9p.h>, and whether that field is free for a server to use
	 * could not be checked from the source in hand. An array borrows
	 * nothing. Eight is far more than a terminal sees -- the shell
	 * has one read outstanding -- and overflow is answered rather
	 * than dropped. Req* stored as void* for the same reason files[]
	 * below is.
	 */
	uchar ttyin[8192];
	int   ttyin_len;
	void *ttyq[8];
	int   ttynq;

	/*
	 * ttylock guards the four fields above, and it is a SECOND lock
	 * rather than `lock' for a reason that would otherwise be found
	 * the hard way: the paths cross.
	 *
	 * fswrite on `tty' takes `lock' and calls engine_feed, libvterm
	 * answers a DA/DSR query through engine_out, and engine_out calls
	 * session_feed_keystrokes -- so a keystroke can be queued from
	 * INSIDE a section already holding `lock', and a QLock is not
	 * recursive. Meanwhile session_wait_rc runs in the forking proc
	 * and wakes the queue from outside any of that.
	 *
	 * So: nothing holding ttylock may take `lock', and the ordering
	 * question does not arise.
	 */
	QLock ttylock;

	/*
	 * Set when the shell writes "rawon" to ttyctl (bound over
	 * /dev/consctl), cleared by "rawoff". It turns vts's own line
	 * editor OFF: `lined' batches keystrokes and flushes whole LINES,
	 * which is the opposite of what a shell doing its own editing
	 * needs -- bash's completion wants every keystroke as it happens.
	 * A pipe or a 9P file has no line discipline of its own, so there
	 * is nothing else for rawon to switch; refusing the write would
	 * fail tcsetattr for no reason.
	 */
	int   raw;

	/* lib9p File* handles owned by this session, kept so teardown can
	 * removefile() each exactly once (the only correct way to balance
	 * createfile's reference). Stored as void* to avoid pulling <9p.h>
	 * into this header. Index 0 = session dir, 1..6 = ctl/cons/cells/
	 * scroll/tty/ttyctl. */
	void *files[7];

	/* Teardown handshake. kill_session and the reader proc both race
	 * to be the last to touch a killed session; "last one out frees"
	 * avoids both the use-after-free (freeing while the reader is mid
	 * read/parse) and the leak (never freeing). Both flags are written
	 * under `lock`; whoever sets its flag second sees the other's and
	 * calls session_free. onheap=0 for the static first session, whose
	 * struct must not be free()d. */
	int   killed;
	int   reader_done;
	uchar onheap;
};

void session_init(Session *s, char *name, int rows, int cols);
int  session_spawn_rc(Session *s);
int  session_feed_keystrokes(Session *s, uchar *bytes, int n);
void session_free(Session *s);

/* Wait for the shell to die and tear the session down. MUST be called
 * from the proc that called session_spawn_rc: Plan 9 reports a death
 * to the process that forked it. */
void session_wait_rc(Session *s);

/* srv.c: answer whatever tty reads ttyin can now satisfy. Called from
 * session_feed_keystrokes, and again with the session dead so a shell
 * that exits does not leave a viewer's read hanging for ever. */
void session_tty_wake(Session *s);

#endif
