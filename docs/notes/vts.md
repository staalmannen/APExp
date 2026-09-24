# vts: a VT emulator as a 9P file server

`sys/src/cmd2/vts` and its two clients. This file starts where the
`vts` block in CLAUDE.md leaves off, and exists because vts is about to
stop being a want and become a work area.

## What the three programs are, and why none of them is the missing piece

The question that prompted this was a good one: *do we need `vts-attach`
and `vtwin`, or should we write a custom glue between vts and bash?*

**Keep both, and write no glue.** They are not glue and never were --
they are two front ends onto the same 9P interface, and the thing that
is missing is not between vts and the shell at all.

| | lines | what it is |
|---|---|---|
| `vts` | 2647 | the server: cell grid, VT parser (libvterm), sessions, `/srv/vts` |
| `vtwin` | 1281 | the **graphical** front end: a rio window |
| `vts-attach` | 302 | the **dumb-TTY** front end: ssh, drawterm, a bare `rc` |

Both clients do exactly the same two things, and that is the point:

```
	/n/vts/<sess>/cells   read  -- one diff frame per read
	/n/vts/<sess>/cons    write -- keystrokes in
```

`vtwin` mounts `/srv/vts`, `initdraw`s, polls `cells` and forwards keys
from `/dev/cons` (`main.c:961-969`, `:785`). `vts-attach` mounts the
same server, polls the same file, and re-serialises the frames into
**VT100 escapes on its own stdout** while forwarding its stdin
(`main.c:243-256`).

So:

- **`vtwin` is the display half of what we want.** Rewriting it is
  rewriting 1281 lines of the same program.
- **`vts-attach` is the session-persistence half** -- detach the
  window, reattach from drawterm or over ssh, which is the whole reason
  to have a server rather than a terminal. It costs nothing to keep.
- **And keeping two clients is itself worth something**: it is what
  makes `cells`/`cons` a real interface rather than vtwin's private
  back door. A second implementation is the cheapest check that an
  interface is one.

## The missing piece is inside `vts/session.c`

**The shell never gets a terminal.** `session.c` spawns it with

```c
	rfork(RFPROC|RFFDG|RFNOTEG|RFENVG)
	...
	dup(pkeyin[0], 0);
	dup(pshellout[1], 1);
	dup(pshellout[1], 2);
	...
	execl("/bin/rc", "rc", "-i", nil);
```

Three things in that are the whole remaining job, and all three are in
vts rather than in a new program:

1. **fd 0 is a PIPE.** `isatty(0)` is therefore false and bash never
   starts readline at all -- which is the first blocker, ahead of
   `$TERM` and ahead of columns.
2. **No `RFNAMEG`**, so the child shares vts's namespace and has
   nowhere private to put a terminal.
3. **`/bin/rc` is hardcoded.**

### `isatty` matches on the PATH, and that decides the design

`ap/unistd/isatty.c`:

```c
	if(_FD2PATH(fd, buf, sizeof buf) < 0)
		return 0;
	/* might be /mnt/term/dev/cons */
	return strlen(buf) >= 9 && strcmp(buf+strlen(buf)-9, "/dev/cons") == 0;
```

**So a session cons opened as `/n/vts/1/cons` is not a tty**, however
well it behaves. Two ways past that, and only one of them is right:

- **Bind it.** `rfork(RFNAMEG)` in the child, `bind` the session's
  `cons` onto `/dev/cons` and its `consctl` onto `/dev/consctl`, then
  open `/dev/cons` for 0, 1 and 2. `fd2path` then answers `/dev/cons`,
  `isatty` is true, and **no libap change is needed**. It is also what
  rio does for its own windows, so it is the idiom rather than a trick.
- Loosening `_isatty` -- **no**. The path test is doing real work
  (`/mnt/term/dev/cons` is why it matches a suffix), and widening it to
  make one program happy is the "invent semantics to make a test pass"
  shape.

**That bind is also where the per-session `consctl` lands**, which is
the other recorded step: `plan9/tty.c` opens `/dev/consctl` and writes
`rawon`/`rawoff`, so once it is bound per window, raw mode is per
window instead of namespace-wide. The two steps are one edit.

## Order of work, and what each step buys

1. **`RFNAMEG` + bind cons/consctl + open `/dev/cons` for 0/1/2**, and
   exec bash. *Buys: `isatty(0)` true, so readline runs at all, and raw
   mode per session.* Nothing else works before this.
2. **`$TERM=vt100`** in the child's environment. *Buys: the redraw.*
   `sys/lib/ape/termcap`'s whole `dumb` entry is `:am:co#80:li#24:` --
   no `ce`, no `up`, no `cm` -- which is why `export COLUMNS=136`
   fixes the wrap column and the line still comes out mangled: readline
   reprints where it should redraw. The engine is libvterm, upstream's
   full state machine, so `vt100` is an honest claim; the termcap
   already ships `vt100|vt100-am` and `xterm`.
3. **A real grid size.** `srv.c:488` and `:594` hardcode
   `session_init(s, name, 24, 80)`. `cellbuf_resize()` exists
   (`cells.h:77`) and nothing calls it from a window-size path.
4. **`putenv("COLUMNS")`/`putenv("LINES")`** beside the
   `putenv("vts", ...)` already there -- `RFENVG` copies the
   environment, and libap's `TIOCGWINSZ` already reads exactly those
   two names -- plus a note to the shell on resize, since Plan 9 has no
   `SIGWINCH`. *The difference is not that vts can measure and rio
   cannot; it is that vts can TELL.*

**And one thing to undo on the way**: `lined.c` batches keystrokes and
flushes whole LINES to the shell. That is the opposite of what bash's
completion needs -- it wants every keystroke as it happens -- so the
session must run with `edit off`.

## vts cannot be syntax-checked on the host, so read the diff twice

The gcc sweep in `docs/notes/tk-plan9.md` does not reach here: vts is
native Plan 9 and needs `<9p.h>`, `<thread.h>` and `<libc.h>`, none of
which this tree vendors. **Every vts change is VM-only**, so a typo
costs a full round trip where a Tcl or libap change would not.

The first build of the tty change proved it, and the way it failed is
worth the line: two `enum` members were missing, because the script
that added them asserted on a *later* edit in the same pass and wrote
nothing. **The file was pushed in a state I believed I had edited.**
That is the same shape as this tree's oldest rule -- *a measurement of
a build that does not contain the change measures nothing* -- one step
earlier, at the source rather than the binary. Re-read the hunks
before pushing, and grep for each new identifier's **declaration** as
well as its uses.
