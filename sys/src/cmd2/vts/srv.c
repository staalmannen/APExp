/*
 * vts 9P file server.
 *
 * Posts /srv/vts. Tree layout:
 *
 *   /                directory
 *   /ctl             daemon control (read: status; write: new/kill/list)
 *   /<sess>/         per session
 *   /<sess>/ctl      per-session control
 *   /<sess>/cons     bidirectional shell I/O
 *   /<sess>/cells    binary cell-diff stream
 *
 * Phase 6 adds multi-session via /ctl commands.
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
#include "celldiff.h"
#include "session.h"

Session *gsessions[MAXSESS];
int nsessions = 0;

/* /srv name to post under; overridable via `vts -s name` (default "vts").
 * Lets a freshly-built vts be smoke-tested alongside a running one. */
char *vts_srvname = "vts";

/* Flag set by main.c via -n (no rc) for testing. */
int vts_spawn_rc_at_start = 1;

enum {
	Faux_root_ctl = 1,
	Faux_sess_ctl,
	Faux_sess_cons,
	Faux_sess_cells,
	Faux_sess_scroll,
	/* The shell's side of the terminal; see add_session_files. */
	Faux_sess_tty,
	Faux_sess_ttyctl,
};

/* Find session by name. Returns NULL if not found. */
static Session*
session_by_name(const char *name)
{
	int i;
	for(i = 0; i < nsessions; i++){
		if(gsessions[i] && strcmp(gsessions[i]->name, name) == 0)
			return gsessions[i];
	}
	return nil;
}

/* Get the session for a per-session file (cons, cells, ctl).
 * The file's parent's name is the session name. */
static Session*
sessof(File *f)
{
	File *parent;
	if(f == nil)
		return nil;
	parent = f->parent;
	if(parent == nil)
		return nil;
	return session_by_name(parent->name);
}

static char Estatus[1024];
static Srv vts_srv;

/*
 * Terminal tracing, gated on $vtsdebug.
 *
 * The shell exits the moment it starts and says `ok', so the question
 * is what its very first exchange with the terminal looked like -- and
 * that is three lines of log rather than another round of reasoning.
 * Only the shell touches `tty' (viewers write `cons'), so this is not
 * noisy: vtwin polls `cells' and never appears here.
 */
static int vtsdebug = -1;

static int
dbglevel(void)
{
	char *p;

	if(vtsdebug < 0){
		p = getenv("vtsdebug");
		vtsdebug = 0;
		if(p != nil && *p != '\0')
			vtsdebug = atoi(p) > 1 ? 2 : 1;
		free(p);
	}
	return vtsdebug;
}

static int
dbg(void)
{
	return dbglevel() >= 1;
}

/* Print up to n bytes readably -- a terminal stream is mostly escapes,
 * and "1b 5b 3f" says more here than a row of dots. */
static void
dbgbytes(char *what, uchar *b, long n)
{
	char buf[128];
	int i, o;

	o = 0;
	for(i = 0; i < n && o < (int)sizeof buf - 8; i++){
		if(b[i] >= 32 && b[i] < 127)
			o += snprint(buf+o, sizeof buf - o, "%c", b[i]);
		else
			o += snprint(buf+o, sizeof buf - o, "<%02x>", b[i]);
	}
	buf[o] = 0;
	fprint(2, "vts: %s %ld [%s]%s\n", what, n, buf,
		i < n ? "..." : "");
}

/*
 * THE BLOCKING TERMINAL READ.
 *
 * A read of `tty' is the shell asking for a keystroke, so with nothing
 * queued it must WAIT rather than answer zero -- a zero-length read is
 * end of file, and a shell told its terminal had closed would exit at
 * once. lib9p's way to wait is to keep the Req and respond() to it
 * later, so the request goes on s->ttyq (linked through Req.aux) and
 * comes back here when session_feed_keystrokes has something, or when
 * the session dies.
 *
 * Because a Req can sit there indefinitely, the server MUST answer
 * Tflush -- see fsflush below. Without it an interrupted client hangs
 * for ever holding a fid, which is the classic way a lib9p server with
 * deferred replies wedges.
 */
/* Caller holds s->ttylock. respond() under a QLock is fine: lib9p
 * does its own locking and does not call back into us. */
static void
tty_serve(Session *s, Req *r)
{
	long n;

	n = s->ttyin_len;
	if(n > (long)r->ifcall.count)
		n = r->ifcall.count;
	memmove(r->ofcall.data, s->ttyin, n);
	r->ofcall.count = n;

	/* A terminal is a stream: the read CONSUMES what it took, and
	 * ifcall.offset means nothing. (The viewer-facing `cons' file is
	 * the opposite -- a snapshot indexed by offset.) */
	s->ttyin_len -= n;
	if(s->ttyin_len > 0)
		memmove(s->ttyin, s->ttyin + n, s->ttyin_len);
	respond(r, nil);
}

/* Take the oldest queued read off the front. */
static Req*
tty_pop(Session *s)
{
	Req *r;
	int i;

	if(s->ttynq <= 0)
		return nil;
	r = (Req*)s->ttyq[0];
	for(i = 1; i < s->ttynq; i++)
		s->ttyq[i-1] = s->ttyq[i];
	s->ttynq--;
	return r;
}

void
session_tty_wake(Session *s)
{
	Req *r;

	qlock(&s->ttylock);
	while(s->ttynq > 0){
		/* Nothing to hand over and the shell is still alive: the
		 * reader keeps waiting, which is the whole point. */
		if(s->ttyin_len == 0 && s->rc_alive){
			qunlock(&s->ttylock);
			return;
		}
		r = tty_pop(s);
		if(s->ttyin_len == 0){
			/* The session is gone. Answer end of file rather than
			 * leave a reader hanging on a dead shell. */
			r->ofcall.count = 0;
			respond(r, nil);
			continue;
		}
		tty_serve(s, r);
	}
	qunlock(&s->ttylock);
}

/*
 * Tflush: a client gave up on a read that is still queued. Take it off
 * the queue and respond to the FLUSHED request; lib9p answers the
 * Tflush itself once we respond to this one. A Req that is on no queue
 * has already been answered, and flushing it is a no-op.
 */
static void
fsflush(Req *r)
{
	Req *v;
	Session *s;
	int i, j, k;

	for(i = 0; i < nsessions; i++){
		s = gsessions[i];
		if(s == nil)
			continue;
		qlock(&s->ttylock);
		for(j = 0; j < s->ttynq; j++){
			if(s->ttyq[j] != (void*)r->oldreq)
				continue;
			v = (Req*)s->ttyq[j];
			for(k = j+1; k < s->ttynq; k++)
				s->ttyq[k-1] = s->ttyq[k];
			s->ttynq--;
			qunlock(&s->ttylock);
			respond(v, "interrupted");
			respond(r, nil);
			return;
		}
		qunlock(&s->ttylock);
	}
	respond(r, nil);
}

static void
fsread(Req *r)
{
	int aux = (uintptr)r->fid->file->aux;
	Session *s;
	long off, n;
	int i, p;

	switch(aux){
	case Faux_root_ctl:
		p = snprint(Estatus, sizeof Estatus,
			"vts %s; sessions=%d\n", VTBUILD, nsessions);
		for(i = 0; i < nsessions && p < (int)sizeof Estatus - 100; i++){
			Session *ss = gsessions[i];
			if(!ss) continue;
			p += snprint(Estatus + p, sizeof Estatus - p,
				"  %s: %dx%d cur=%d,%d rc=%d alive=%d\n",
				ss->name, ss->buf.rows, ss->buf.cols,
				ss->buf.cur_row, ss->buf.cur_col,
				ss->rc_pid, ss->rc_alive);
		}
		readstr(r, Estatus);
		respond(r, nil);
		return;

	case Faux_sess_ctl:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		snprint(Estatus, sizeof Estatus,
			"session %s; size=%dx%d; cursor=%d,%d; visible=%d; rc_alive=%d; raw=%d; lined=%d\n",
			s->name, s->buf.rows, s->buf.cols,
			s->buf.cur_row, s->buf.cur_col,
			(int)s->buf.cur_visible,
			s->rc_alive, s->raw, s->editor.enabled);
		readstr(r, Estatus);
		respond(r, nil);
		return;

	case Faux_sess_cons:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		off = r->ifcall.offset;
		if(off >= s->keyin_buf_len){
			r->ofcall.count = 0;
			respond(r, nil);
			return;
		}
		n = s->keyin_buf_len - off;
		if(n > (long)r->ifcall.count)
			n = r->ifcall.count;
		memmove(r->ofcall.data, s->keyin_buf + off, n);
		r->ofcall.count = n;
		respond(r, nil);
		return;

	case Faux_sess_tty:
		s = sessof(r->fid->file);
		if(s == nil){
			/*
			 * An error answer reads as EOF to the shell, exactly
			 * as a zero count does -- so this arm must not be
			 * silent either.
			 */
			if(dbg())
				fprint(2, "vts: tty read: NO SESSION\n");
			respond(r, "no session");
			return;
		}
		qlock(&s->ttylock);
		if(s->ttyin_len > 0){
			if(dbg())
				fprint(2, "vts: tty read: serving %d queued byte(s)\n",
					s->ttyin_len);
			tty_serve(s, r);
			qunlock(&s->ttylock);
			return;
		}
		if(!s->rc_alive){
			qunlock(&s->ttylock);
			/*
			 * END OF FILE, and it is the one answer that kills a
			 * shell outright -- bash reads EOF on stdin and exits
			 * 0, which looks exactly like a clean quit. If this
			 * line appears before anything was typed, the shell
			 * was told its terminal had closed.
			 */
			if(dbg())
				fprint(2, "vts: tty read: EOF (rc_alive=0)\n");
			r->ofcall.count = 0;
			respond(r, nil);
			return;
		}
		/* Block: queue it and do NOT respond. See tty_serve above. */
		if(s->ttynq >= (int)(sizeof s->ttyq / sizeof s->ttyq[0])){
			qunlock(&s->ttylock);
			respond(r, "vts: too many readers on tty");
			return;
		}
		s->ttyq[s->ttynq++] = r;
		if(dbg())
			fprint(2, "vts: tty read: blocked (%d waiting)\n", s->ttynq);
		qunlock(&s->ttylock);
		return;

	case Faux_sess_ttyctl:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		/* Readable so a program can ASK rather than assume. Plan 9's
		 * own consctl is write-only; answering here costs nothing and
		 * is how the smoke tests check that rawon arrived. */
		readstr(r, s->raw ? "rawon\n" : "rawoff\n");
		respond(r, nil);
		return;

	case Faux_sess_cells:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		if(r->ifcall.offset != 0){
			r->ofcall.count = 0;
			respond(r, nil);
			return;
		}
		qlock(&s->lock);
		{
			int max = r->ifcall.count;
			int written = celldiff_encode(&s->buf,
				(uchar*)r->ofcall.data, max);
			r->ofcall.count = written;
		}
		qunlock(&s->lock);
		respond(r, nil);
		return;

	case Faux_sess_scroll:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		/* Read scrollback as UTF-8 lines separated by '\n'.
		 * Offset-aware: caller can seek into the stream. */
		qlock(&s->lock);
		{
			int total = cellbuf_scrollback_count(&s->buf);
			long off = r->ifcall.offset;
			long want = r->ifcall.count;
			long produced = 0;
			char *out = (char*)r->ofcall.data;
			int i;

			/* Render lines into a temporary aware of where we are
			 * in the byte stream. We iterate one line at a time. */
			long pos = 0;
			char *linebuf = (char*)malloc(SCROLL_LINE_BYTES);
			for(i = 0; i < total && produced < want; i++){
				cellbuf_scrollback_lines(&s->buf, i, 1, linebuf);
				int llen = strlen(linebuf);
				/* This line spans bytes [pos, pos+llen+1) where +1 is '\n' */
				long line_end = pos + llen + 1;
				if(line_end <= off){
					pos = line_end;
					continue;
				}
				/* Some part of this line is in our window. */
				long start_in_line = (off > pos) ? off - pos : 0;
				long to_copy = (long)(llen + 1) - start_in_line;
				if(to_copy > want - produced) to_copy = want - produced;
				const char *src;
				if(start_in_line < llen){
					src = linebuf + start_in_line;
					long cn = llen - start_in_line;
					if(cn > to_copy) cn = to_copy;
					memmove(out + produced, src, cn);
					produced += cn;
					to_copy -= cn;
				}
				if(to_copy > 0 && produced < want){
					out[produced++] = '\n';
				}
				pos = line_end;
			}
			free(linebuf);
			r->ofcall.count = produced;
		}
		qunlock(&s->lock);
		respond(r, nil);
		return;
	}

	/*
	 * Reached only if `aux' matched no case. If a tty read ever lands
	 * here, the file's aux is not what add_session_files set -- which
	 * would explain a read that never appears in the trace while
	 * writes on the same fid do.
	 */
	if(dbg())
		fprint(2, "vts: READ of unknown file (aux=%d)\n", aux);
	respond(r, "vts: unknown file");
}

/* Forward decl */
static int create_session(const char *name, int spawn_rc);
static int kill_session(const char *name);

static void
fswrite(Req *r)
{
	int aux = (uintptr)r->fid->file->aux;
	Session *s;
	long n;
	char cmd[256];
	char *argv[8];
	int argc;

	n = r->ifcall.count;

	switch(aux){
	case Faux_root_ctl:
		/* Phase 6: parse commands.
		 *   new <name>      create session
		 *   kill <name>     destroy session  */
		if(n >= (long)sizeof cmd){
			respond(r, "command too long");
			return;
		}
		memmove(cmd, r->ifcall.data, n);
		cmd[n] = 0;
		/* strip trailing newline */
		while(n > 0 && (cmd[n-1] == '\n' || cmd[n-1] == '\r')){
			cmd[--n] = 0;
		}
		argc = tokenize(cmd, argv, nelem(argv));
		if(argc == 0){
			r->ofcall.count = r->ifcall.count;
			respond(r, nil);
			return;
		}
		if(strcmp(argv[0], "new") == 0 && argc >= 2){
			if(create_session(argv[1], 1) < 0){
				respond(r, "create_session failed");
				return;
			}
		} else if(strcmp(argv[0], "kill") == 0 && argc >= 2){
			if(kill_session(argv[1]) < 0){
				respond(r, "kill_session failed");
				return;
			}
		} else {
			respond(r, "unknown command");
			return;
		}
		r->ofcall.count = r->ifcall.count;
		respond(r, nil);
		return;

	case Faux_sess_ctl:
		/* Per-session control commands:
		 *   edit on    enable in-process line editor
		 *   edit off   disable
		 *   size R C   resize the cell buffer (rows, cols)
		 */
		s = sessof(r->fid->file);
		if(s != nil && n > 0){
			char cmd[64];
			int cn = n < (long)sizeof cmd - 1 ? n : (long)sizeof cmd - 1;
			memmove(cmd, r->ifcall.data, cn);
			cmd[cn] = 0;
			while(cn > 0 && (cmd[cn-1] == '\n' || cmd[cn-1] == '\r'))
				cmd[--cn] = 0;
			if(strcmp(cmd, "edit on") == 0)
				lined_set_enabled(&s->editor, 1);
			else if(strcmp(cmd, "edit off") == 0)
				lined_set_enabled(&s->editor, 0);
			else if(strcmp(cmd, "redraw") == 0){
				/* Force re-emit of every cell on the next cells
				 * read. Used by vtwin when it (re)gains focus or
				 * suspects its display is stale. */
				qlock(&s->lock);
				s->buf.all_dirty = 1;
				qunlock(&s->lock);
			}
			else if(strncmp(cmd, "size ", 5) == 0){
				char *fields[3];
				char tmp[64];
				strncpy(tmp, cmd, sizeof tmp - 1);
				tmp[sizeof tmp - 1] = 0;
				int nf = tokenize(tmp, fields, 3);
				if(nf == 3){
					int newrows = atoi(fields[1]);
					int newcols = atoi(fields[2]);
					if(newrows > 0 && newcols > 0 &&
					   newrows < 1000 && newcols < 1000){
						qlock(&s->lock);
						engine_resize(&s->engine, newrows, newcols);
						cellbuf_resize(&s->buf, newrows, newcols);
						qunlock(&s->lock);
					}
				}
			}
		}
		r->ofcall.count = n;
		respond(r, nil);
		return;

	case Faux_sess_cons:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		/*
		 * If line editor is enabled, intercept the byte stream:
		 *   - run each byte through lined_feed_byte
		 *   - on LINEED_COMPLETE: flush completed line + '\n' to rc
		 *   - on LINEED_CONSUMED: emit any redraw bytes to the cell buffer
		 *   - on LINEED_PASSTHROUGH: forward raw
		 * If editor disabled, write straight through.
		 */
		if(s->editor.enabled){
			long i;
			for(i = 0; i < n; i++){
				uchar *line_out;
				int line_len;
				uchar redraw[256];
				int rl = 0;
				int rc = lined_feed_byte(&s->editor,
					((uchar*)r->ifcall.data)[i],
					&line_out, &line_len,
					redraw, sizeof redraw, &rl);
				if(rl > 0){
					qlock(&s->lock);
					engine_feed(&s->engine, redraw, rl);
					qunlock(&s->lock);
				}
				if(rc == LINEED_COMPLETE){
					if(s->rc_alive){
						session_feed_keystrokes(s, line_out, line_len);
						uchar nl = '\n';
						session_feed_keystrokes(s, &nl, 1);
					} else {
						qlock(&s->lock);
						engine_feed(&s->engine, line_out, line_len);
						engine_feed(&s->engine, (uchar*)"\r\n", 2);
						qunlock(&s->lock);
					}
				} else if(rc == LINEED_PASSTHROUGH){
					if(s->rc_alive){
						uchar b = ((uchar*)r->ifcall.data)[i];
						session_feed_keystrokes(s, &b, 1);
					}
				}
			}
		} else if(s->rc_alive){
			session_feed_keystrokes(s, (uchar*)r->ifcall.data, n);
		} else {
			qlock(&s->lock);
			engine_feed(&s->engine, (uchar*)r->ifcall.data, n);
			qunlock(&s->lock);
		}
		/* Record recent input for read-back via fsread cons. Bound
		 * against keyin_buf: a single write larger than the buffer
		 * (e.g. a big paste from vtwin) must NOT memmove past its end
		 * — that overflows the Session struct and corrupts the heap,
		 * faulting later. Keep only the most recent bytes. */
		if(n >= (long)sizeof s->keyin_buf){
			memmove(s->keyin_buf,
				(uchar*)r->ifcall.data + (n - (long)sizeof s->keyin_buf),
				sizeof s->keyin_buf);
			s->keyin_buf_len = sizeof s->keyin_buf;
		} else {
			if(s->keyin_buf_len + n > (int)sizeof s->keyin_buf)
				s->keyin_buf_len = 0;
			memmove(s->keyin_buf + s->keyin_buf_len, r->ifcall.data, n);
			s->keyin_buf_len += n;
		}
		r->ofcall.count = n;
		respond(r, nil);
		return;

	case Faux_sess_tty:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		/*
		 * The shell's stdout and stderr. Straight into the VT parser,
		 * with no line editor in the way -- `lined' exists to cook
		 * INPUT for a viewer, and cooking output would be nonsense.
		 * This is the half that replaces the old shellout pipe and
		 * its reader proc: the shell writes here, so there is nothing
		 * left to drain.
		 */
		if(dbg())
			dbgbytes("tty write", (uchar*)r->ifcall.data, n);
		qlock(&s->lock);
		engine_feed(&s->engine, (uchar*)r->ifcall.data, n);
		qunlock(&s->lock);
		r->ofcall.count = n;
		respond(r, nil);
		return;

	case Faux_sess_ttyctl:
		s = sessof(r->fid->file);
		if(s == nil){
			respond(r, "no session");
			return;
		}
		/*
		 * `rawon'/`rawoff', which is the whole of what Plan 9's
		 * /dev/consctl accepts and therefore the whole of what
		 * libap's tcsetattr writes (ap/plan9/tty.c). Neither a pipe
		 * nor a 9P file has a line discipline to switch, so what this
		 * actually does is turn vts's OWN line editor off: `lined'
		 * batches keystrokes and flushes whole lines, and a shell
		 * doing its own editing needs every keystroke as it happens.
		 *
		 * It must SUCCEED even when there is nothing to do. A stub
		 * answering "failure" would fail tcsetattr, and a program
		 * told it could not have raw mode behaves differently from
		 * one that got it silently -- which is the most common bug
		 * shape in this tree.
		 */
		if(dbg())
			dbgbytes("ttyctl write", (uchar*)r->ifcall.data, n);
		if(n >= 5 && strncmp((char*)r->ifcall.data, "rawon", 5) == 0)
			s->raw = 1;
		else if(n >= 6 && strncmp((char*)r->ifcall.data, "rawoff", 6) == 0)
			s->raw = 0;
		lined_set_enabled(&s->editor, !s->raw);
		r->ofcall.count = n;
		respond(r, nil);
		return;

	case Faux_sess_cells:
		respond(r, "cells is read-only");
		return;
	}

	/* Reached only if `aux' matched no case. */
	if(dbg())
		fprint(2, "vts: WRITE of unknown file (aux=%d)\n", aux);
	respond(r, "vts: unknown file");
}

/* Add a session's files to the tree. */
static int
add_session_files(Session *s)
{
	File *sess_dir;
	void *axp;

	sess_dir = createfile(vts_srv.tree->root, s->name, "vts", DMDIR|0555, nil);
	if(sess_dir == nil){
		fprint(2, "vts: createfile %s failed: %r\n", s->name);
		return -1;
	}

	/* Keep every File* createfile hands back: each carries one
	 * reference that teardown must release with exactly one removefile.
	 * (The previous code discarded these and re-derived them with
	 * walkfile at teardown — which takes an EXTRA ref and, combined
	 * with child-removal dropping the parent's ref, corrupted lib9p's
	 * accounting and faulted freefile() after a handful of sessions.) */
	s->files[0] = sess_dir;

	axp = (void*)(uintptr)Faux_sess_ctl;
	s->files[1] = createfile(sess_dir, "ctl", "vts", 0666, axp);

	axp = (void*)(uintptr)Faux_sess_cons;
	s->files[2] = createfile(sess_dir, "cons", "vts", 0666, axp);

	axp = (void*)(uintptr)Faux_sess_cells;
	s->files[3] = createfile(sess_dir, "cells", "vts", 0444, axp);

	axp = (void*)(uintptr)Faux_sess_scroll;
	s->files[4] = createfile(sess_dir, "scroll", "vts", 0444, axp);

	/*
	 * The shell's side. `cons' above is the VIEWER's file and keeps
	 * the meaning it has always had; these two are what get bound
	 * over /dev/cons and /dev/consctl in the shell's own namespace.
	 * Keeping them separate is what lets vtwin and vts-attach go on
	 * working unchanged -- and it is honest, because the two sides of
	 * a terminal really are different files here: a viewer WRITES
	 * keystrokes, the shell READS them.
	 */
	axp = (void*)(uintptr)Faux_sess_tty;
	s->files[5] = createfile(sess_dir, "tty", "vts", 0666, axp);

	axp = (void*)(uintptr)Faux_sess_ttyctl;
	s->files[6] = createfile(sess_dir, "ttyctl", "vts", 0666, axp);

	return 0;
}

static int
remove_session_files(Session *s)
{
	int i;

	if(s->files[0] == nil)
		return -1;
	/* Children first, then the directory. removefile unlinks the file
	 * and drops the createfile reference; if a client still has the
	 * file open, lib9p keeps the (now unlinked) File alive until the
	 * last fid clunks, so this is safe even mid-use. No walkfile. */
	for(i = 1; i < 7; i++){
		if(s->files[i] != nil){
			removefile((File*)s->files[i]);
			s->files[i] = nil;
		}
	}
	removefile((File*)s->files[0]);
	s->files[0] = nil;
	return 0;
}

static void
spawn_rc_proc(void *arg)
{
	Session *s = (Session*)arg;
	if(session_spawn_rc(s) < 0){
		fprint(2, "vts: warning: could not spawn a shell for %s\n", s->name);
		threadexits(nil);
	}
	/*
	 * And then WAIT here, in the proc that forked. Plan 9's wait
	 * reports to the process that did the rfork, so this cannot be
	 * moved to a proc of its own -- and it is safe to block, because
	 * this proc exists to do nothing else. It is also what replaces
	 * the old reader proc: the shell writes its output to `tty' over
	 * 9P now, so there is no pipe left to drain and the only thing
	 * still worth watching for is the shell's death.
	 */
	session_wait_rc(s);
	threadexits(nil);
}

static int
create_session(const char *name, int spawn_rc)
{
	Session *s;
	int slot;

	if(session_by_name(name) != nil)
		return -1;
	for(slot = 0; slot < MAXSESS; slot++)
		if(gsessions[slot] == nil) break;
	if(slot >= MAXSESS)
		return -1;

	s = (Session*)malloc(sizeof(Session));
	if(s == nil)
		return -1;
	memset(s, 0, sizeof(Session));
	session_init(s, (char*)name, 24, 80);
	s->onheap = 1;	/* heap-allocated; teardown may free(s) */
	gsessions[slot] = s;
	if(slot >= nsessions) nsessions = slot + 1;

	if(add_session_files(s) < 0){
		session_free(s);
		gsessions[slot] = nil;
		return -1;
	}

	if(spawn_rc){
		proccreate(spawn_rc_proc, s, 32*1024);
	}

	fprint(2, "vts: created session %s (slot %d)\n", name, slot);
	return 0;
}

static int
kill_session(const char *name)
{
	int i;
	Session *s = nil;
	for(i = 0; i < nsessions; i++){
		if(gsessions[i] && strcmp(gsessions[i]->name, name) == 0){
			s = gsessions[i];
			gsessions[i] = nil;
			break;
		}
	}
	if(s == nil) return -1;

	if(s->rc_alive && s->rc_pid > 0){
		char path[64];
		int fd;
		snprint(path, sizeof path, "/proc/%d/note", s->rc_pid);
		fd = open(path, OWRITE);
		if(fd >= 0){
			fprint(fd, "kill");
			close(fd);
		}
	}

	/* Reclaim the keyin write end. (The reader proc closes the shellout
	 * read end when rc's death makes its read return EOF.) Killing rc
	 * via the note above also makes that happen. Marking rc_alive=0 +
	 * keyin_wfd=-1 keeps any late session_feed_keystrokes a no-op. */
	s->rc_alive = 0;
	if(s->keyin_wfd >= 0){
		close(s->keyin_wfd);
		s->keyin_wfd = -1;
	}
	/* Answer any tty read still queued, or its client waits for ever
	 * on a shell that is not coming back. */
	session_tty_wake(s);

	remove_session_files(s);
	fprint(2, "vts: killed session %s\n", name);

	/* Teardown handshake (see session.c). The reader proc may still be
	 * unwinding out of its blocking read on this session. Mark it killed;
	 * if the reader has already finished, we're the last user and free
	 * now. Otherwise the reader frees when it exits and sees `killed`.
	 * gsessions[i] is already nil and the files are removed, so no 9P
	 * request can reach `s` after this point. */
	{
		int reader_done;
		qlock(&s->lock);
		s->killed = 1;
		reader_done = s->reader_done;
		qunlock(&s->lock);
		if(reader_done)
			session_free(s);
	}
	return 0;
}

static void
fsstart(Srv *srv)
{
	Session *s;
	USED(srv);
	if(nsessions == 0)
		return;
	s = gsessions[0];
	if(vts_spawn_rc_at_start && !s->rc_alive){
		proccreate(spawn_rc_proc, s, 32*1024);
	}
}

static Srv vts_srv = {
	.read = fsread,
	.write = fswrite,
	.flush = fsflush,
	.start = fsstart,
};

static Session sess1_storage;

void
srvinit(int spawn_rc)
{
	File *root;
	void *axp;

	vts_spawn_rc_at_start = spawn_rc;

	/* Initialize the FIRST session statically. Additional sessions
	 * are heap-allocated by create_session. */
	session_init(&sess1_storage, "1", 24, 80);
	gsessions[0] = &sess1_storage;
	nsessions = 1;

	vts_srv.tree = alloctree("vts", "vts", DMDIR|0555, nil);
	root = vts_srv.tree->root;

	axp = (void*)(uintptr)Faux_root_ctl;
	createfile(root, "ctl", "vts", 0666, axp);

	add_session_files(&sess1_storage);
}

void
srvstart(void)
{
	/*
	 * $vtsdebug=2 turns on lib9p's own message trace.
	 *
	 * IT ANSWERS A QUESTION NOTHING ELSE CAN. The shell's writes all
	 * arrive at fswrite and not one read arrives at fsread -- on the
	 * SAME fid, since fds 0, 1 and 2 are dups of one open. So either
	 * libap never issued a Tread, or one arrived and was answered
	 * before reaching us. `chatty9p' prints every T- and R-message,
	 * so the walk, the open and any read are all visible, and the
	 * two cases stop looking alike.
	 */
	if(dbglevel() >= 2){
		chatty9p = 1;
		fprint(2, "vts: chatty9p on ($vtsdebug=2)\n");
	}
	threadpostsrv(&vts_srv, vts_srvname);
	print("vts: posted at /srv/%s\n", vts_srvname);
}
