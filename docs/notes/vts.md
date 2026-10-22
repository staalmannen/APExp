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

## Running it: `vts-bash`, from inside `apexp-sh`

**`./apexp-sh -v` is the one-command form** and is what to reach for:
it builds the namespace and runs `vts-bash` in it, then falls back to
the shell rather than exec'ing, so the log the script prints on the
way out can still be read.

`rc/bin/vts-bash` starts vts and a vtwin window. It is in `rc/bin`
because `apexp-sh` binds that onto `/bin` -- so the command is
`vts-bash`, no `./`. **Not `rc/bin/ape`**, which holds the APE
toolchain wrappers (`c89`, `cc`, `libtool`): this drives `vts`,
`vtwin` and `vts-attach`, which are native `cmd2` binaries built with
`6c`, and filing it under `ape/` would assert something false about
what it is.

**It must be run from inside `apexp-sh`**, and that is the mechanism
rather than a convenience -- these things `apexp-sh` does are
load-bearing:

```
bind -b $cputype/bin /bin        vts, vtwin, vts-attach get on the path
bind -b rc/bin /bin              vts-bash itself gets on the path
bind -b $cputype/bin/ape /bin    bash gets on the path
SHELL=bash                       what vts reads to know what to exec
```

vts forks the shell with `RFNAMEG|RFENVG`, **both of which copy**, so
the shell inherits that namespace and that environment. Started from a
plain `rc`, none of the three is true and vts falls back to `/bin/rc`
having found no bash.

Every check in the script is there because its failure is silent or
reads as something else -- a second vts posting over the first looks
exactly like the new one dying; `vtwin` started before `/srv/vts`
exists looks like a vtwin bug. Two Plan 9 idioms it gets right that are
easy to get wrong: **`sleep` takes whole seconds**, so `sleep 0.1` is a
spin, and **`kill` PRINTS the commands** for piping into a shell rather
than doing anything, so the note is written directly.

### `lined` is left ON at spawn, and the shell turns it off

`session_spawn_rc` deliberately does **not** force raw mode. The shell
does it by writing `rawon` to `ttyctl`, which is what readline's
`tcsetattr` already sends through libap. Two reasons, and the second
decides it:

- **rc does not echo and does not cook.** 9front's rc expects a console
  driver to do both, so a session running rc with `lined` off shows
  nothing of what you type -- a regression for every session that is
  not bash.
- **The failure mode.** If bash never reaches `tcsetattr` -- wrong
  shell, a build without `READLINE`, `isatty` answering no for a reason
  not yet found -- then with `lined` on there is still a usable cooked
  shell, and with it off there is a window swallowing keystrokes in
  silence. *Choose the default whose failure is legible.*

readline preps and unpreps the terminal around **every line**, so
`lined` flips back on between commands. Harmless: nothing is typed
while a command runs, and type-ahead merely gets cooked rather than
passed through.

### What to read if the window comes up blank

vts talks to fd 2 about every step, and the script leaves that pointed
at the window it was launched from rather than `/dev/null`. The child's
own failures print there too, because it closes descriptors 3 and up
*before* mounting and only dups `/dev/cons` over 0/1/2 at the end --
so `open /srv/vts`, `mount /mnt`, `bind ... /dev/cons` and
`open /dev/cons` all report to the launching window. Only the `exec`
failure lands in the session's own grid, where vtwin shows it.

**The first question to ask of a session that runs but does not
complete**, in order:

1. `cat /n/vts/1/ttyctl` -- `rawon` means the shell reached
   `tcsetattr`, so `isatty(0)` was true and readline started. `rawoff`
   means it did not, and the bind is the thing to doubt.
2. `echo $TERM` in the session -- `vt100`, not `dumb`.
3. `echo $COLUMNS` -- 80 today, because `srv.c` still hardcodes
   `session_init(s, name, 24, 80)`. Correct, but not yet true of the
   window.

## First run: readline IS running, and the input is garbled

The first live session came up looking like this:

```
2004h$ 20041
exit
cho Scho SH
echo S
SHL
SHL
```

**Two things are in there, and the first is the good news.**

**`2004h` and `2004l` are readline's bracketed-paste sequences**
(`ESC [ ? 2 0 0 4 h` / `l`), printed as *text* with the `ESC [ ?`
missing. readline only emits those when it is actually driving the
line. **So `isatty(0)` was true, the bind over `/dev/cons` worked, and
bash started readline** -- which is the whole thing this change was
for. That half is CONFIRMED.

**The garbling is two writers feeding one VT parser.** `echo $SHELL`
comes back as `cho Scho SH` / `echo S` / `SHL` -- the same characters
appearing twice in different groupings, with letters missing. That is
double echo, and torn escape sequences are its signature: `engine_feed`
is a bare pass-through to `vterm_input_write`, which holds parser state
across calls perfectly well, so a `ESC [ ?` that loses its tail was
interrupted by *someone else's bytes*, not by a write boundary.

There are exactly two writers into the engine, and only one
circumstance puts them both there at once:

- `fswrite` on `tty` -- the shell's output;
- `lined`'s redraw -- vts's own local echo, which runs **only while
  `s->editor.enabled`**.

So `lined` was on while bash was also echoing, which means the `rawon`
that should have turned it off never arrived. *(The other candidate --
`fsread` on `cells` serialising the grid while the engine mutates it --
is excluded: it holds `s->lock`, and so does the write.)*

### Do not guess which, ask

Two stories fit "rawon never arrived", they need different fixes, and I
have already changed my mind about this once:

1. **The consctl bind failed**, so libap's `tcsetattr` could not open
   `/dev/consctl`, `_tty_raw` returned -1, and readline carried on
   regardless -- which it does.
2. **`rawon` arrived and something put lined back.** readline preps and
   unpreps around *every line*, so `rawoff` follows each Enter.

```
cat /n/vts/1/ctl        raw= and lined= now say it outright
cat /n/vts/1/ttyctl     rawon or rawoff
```

`rawoff` with a bind failure in the launching window is (1).
`rawon` is (2), and then the per-line toggle is the thing to fix --
`lined` would have to stay off once a shell has ever asked for raw.

### Two changes that are not guesses

**The session `ctl` readout now carries `raw=` and `lined=`.** The
question above should never need a round of its own again.

**And the consctl bind moved to LAST, after fd 2 is the terminal**, so
its complaint lands in the window the user is looking at rather than in
the one vts was launched from -- which is easy to lose behind the
session, and is not where anyone looks when a shell misbehaves. The
message now says what the failure will look like (`expect double
echo`), because the symptom and the cause are three layers apart.

### Noted in passing

`vts/parser.c` is 593 lines and **is not in OFILES** -- the engine uses
libvterm. Dead code, not a bug, but it is the file someone will read
first when a sequence goes wrong.

## A mount lives in a namespace, and that invalidated the instructions

`cat /n/vts/1/ctl` came back `file does not exist` -- and `lc /n` showed
`vts/` there all along, so the directory exists and the mount does not.
**That is correct rather than broken, and the instruction was the thing
at fault.**

`/srv/vts` is global; `/srv` is. But **what you get by MOUNTING it is
per-namespace**, and `apexp-sh` opens with `rfork en`, so every
apexp-sh window has a namespace of its own. vtwin mounts for itself.
The session's shell mounts for itself, on `/mnt`. A third window has
neither, and sees an empty `/n/vts`.

So a session's files are reachable from exactly three places:

```
/mnt/<sess>/...     inside the session's own shell   (vts mounts there)
/n/vts/<sess>/...   in the window that ran vts-bash  (it mounts now)
/n/vts/<sess>/...   in vtwin's window                (it mounts itself)
```

**Asking for `cat /n/vts/1/ctl` without saying which window is asking
for nothing.** Same family as the rule about instructions for the other
machine having to name the program that runs them -- on Plan 9 a path
is not an address until you say whose namespace it is in.

### So the script reports for itself

`vts-bash` now mounts `/srv/vts` on `/n/vts` in the launching window --
which is shared with the shell that ran it, since nothing rforks in
between -- and prints the `ctl` readout **twice**: once a second after
the shell starts, and again after vtwin exits. The second is usually
the interesting one, because the state worth seeing is the one after
something went wrong rather than a second after boot.

The readout spells out what each answer means, because `raw=0` on its
own tells you nothing unless you already know that `rawon` is what
`tcsetattr` sends and that it is what moves `lined` out of the way.

### And `/srv/vts` already existing now ATTACHES

Refusing was defensible -- a second vts posts over the first and looks
exactly like the new one having failed -- but it left no way forward
that did not involve knowing which process to kill, which is not
knowledge the error message supplied.

**It still warns, and the warning is the one that matters**: an
attached window shows the session as it is, *including a session
started by an older vts*. Rebuild vts, attach to the server that was
already running, and every conclusion drawn from that window is about
the old binary. The message names the two commands that replace it:

```
kill vts | rc ; rm -f /srv/vts
```

*(`kill` on Plan 9 PRINTS the commands rather than doing anything,
which is why it is piped into `rc`.)*

## The shell exits immediately, and that retires the double-echo story

The launching window, photographed before the session went black:

```
vts-bash: starting vts...
vts: hello (build 2026-06-28.libvterm)
vts: posted at /srv/vts
vts: /bin/bash forked pid=532 on /mnt/1/tty
vts: shell 532 exited: ok
./vts-bash:111: break: file does not exist: './break'   (x4)
vts-bash: /srv/vts posted
```

**Three things, and the middle one changes the question entirely.**

**`/bin/bash forked pid=532 on /mnt/1/tty`** -- `$SHELL` resolved,
bash was found through apexp-sh's bind, and the session's tty path is
right. And **no child complaint appeared**: the child prints to fd 2 on
every failure of `open /srv/vts`, `mount /mnt`, either bind or
`open /dev/cons`, and fd 2 is still the launching window at that point.
So the mount and both binds worked.

**`shell 532 exited: ok`** -- and `ok` is not a figure of speech.
`session_wait_rc` prints `w->msg` when it is non-empty and `ok` when it
is not, and every `_exits` in the child passes a *name*: `srv`,
`mount`, `bind`, `cons`, `exec`. An empty message means **bash itself
ran and exited 0**.

**A shell that exits 0 the instant it starts has read end of file on
stdin.** Which means the double-echo reading from the round before is
about a *different* build and a *different* failure -- the session that
garbled `echo $SHELL` at least stayed alive to be typed at. **Do not
carry that diagnosis forward.**

### Where EOF can come from, and why it is worth instrumenting rather than guessing

`fsread` on `tty` has exactly three arms: serve queued bytes, answer
**EOF when `!s->rc_alive`**, or block. Only the middle one ends a
shell, and `rc_alive` is set by the parent immediately after `rfork` --
before the child has closed 97 descriptors, mounted, bound twice,
opened, dupped, `putenv`'d four times and exec'd a shell that then
runs its own startup. That race is not close.

So either something else answers 0, or bash never reaches the read.
**Both are one log line away, and neither is reachable by reading the
source again** -- which is the point at which this tree's own rule says
to stop reasoning.

`$vtsdebug` now turns on a trace of the shell's side of the terminal:

```
vts: tty write 12 [<1b>[?2004h$ ]          what the shell emitted
vts: ttyctl write 5 [rawon]                whether tcsetattr arrived
vts: tty read: blocked (1 waiting)         the read that should hang
vts: tty read: EOF (rc_alive=0)            the one that kills it
```

It is not noisy: **only the shell touches `tty`.** Viewers write `cons`
and poll `cells`, so nothing else appears. `vts-bash` sets the variable,
and the four lines answer, in order: did bash write a prompt, did it ask
for raw mode, did it read, and was it told the terminal had closed.

### And rc has no `break`

```
./vts-bash:111: break: file does not exist: './break'
```

`break` is not an rc keyword, so rc went looking for a command by that
name -- once per remaining turn of the loop. A flag is the way to leave
an rc loop early; the turns after it then cost one `test` each. That
joins **`sleep` takes whole seconds** on the short list of rc facts
this script has now paid for.

*(`vts: hello (build 2026-06-28.libvterm)` is worth keeping in view:
it is vts's own version marker, and the same idiom as
`_sock_listenmark`/`_execmark`/`_ttymark` in libap. When a session
behaves like the previous build, that line is what says whether it is.)*

## The trace came back, and the interesting line is the one that is missing

```
vts: /bin/bash forked pid=531 on /mnt/1/tty
vts: ttyctl write 5 [rawon]
vts: tty write 8 [<1b>[?2004h]
vts: tty write 2 [$ ]
vts: tty write 9 [<1b>[?2004l<0d>]
vts: tty write 1 [<0a>]
vts: ttyctl write 6 [rawoff]
vts: tty write 4 [exit]
vts: tty write 1 [<0a>]
vts: shell 531 exited: ok
```

**What this settles, and it is most of the earlier guesswork.** The
mount and both binds worked. `isatty(0)` was true -- readline emits
`ESC [ ? 2004 h` only when it is driving the line. `rawon` ARRIVED, so
`tcsetattr` reached `/dev/consctl` and `lined` was turned off; **both
competing "double echo" stories from the previous rounds are dead.**
bash printed its prompt, immediately terminated the line, sent `rawoff`,
printed `exit` and exited 0 -- which is precisely bash's behaviour on
reading **EOF at a prompt**.

**The decisive fact is the absence.** There is no `tty read` line of any
kind, and the trace has one for every arm: served, blocked, EOF, and no
session. So the read that should have hung either never reached vts or
never happened. *A missing line is evidence exactly as much as a present
one, PROVIDED every arm prints* -- which is why the silent arms were
filled in before this run rather than after.

Two instruments, at the two ends, because the source cannot separate
them:

- **`$vtsdebug=2` turns on `chatty9p`**, lib9p's own T/R trace. If a
  `Tread` on the tty fid appears and is answered before `fsread` sees
  it, that is lib9p; if none appears, libap never issued one. The two
  look identical from inside `fsread`.
- **The child prints `fd2path` of 0, 1 and 2 immediately before
  `exec`.** *Every trace so far proves fd 1 and fd 2 -- the shell's
  output arrives. Nothing has ever proved fd 0*, and a wrong fd 0 is
  exactly this shape: writes land on the terminal, the read lands
  somewhere else and ends at once. `dup()`'s return value is unchecked
  in that block, and a silent failure there looks like success from
  outside; and vts is started in the BACKGROUND, where rc gives a
  command `/dev/null` on fd 0 -- so the wrong answer is sitting right
  there waiting to be inherited.

*Ask the kernel which file a descriptor is on rather than trusting the
three calls that were supposed to put it there.*

And the log now goes to a **file** (`/tmp/vts.log`, via `vts >[2]$vtslog
&` in `vts-bash`, catted on the way out). That is not tidiness: vtwin's
window opens over the launching one, so the lines printed in the second
before the session appears were being read off a **photograph of the
screen**. A log that outlives the window can be read twice and pasted.

### fd 0 is the terminal, and the instrument was switched off by its own script

```
vts: child: fd0=/dev/cons fd1=/dev/cons fd2=/dev/cons
```

So `dup()` did what it was written to do, all three descriptors are the
bound `tty`, and **the background-`/dev/null` reading is dead.** That
was one line and it closed a whole branch.

**`chatty9p` never came on, and that was my own bug.** `vtsdebug=2
./vts-bash` was the command; the script then did `vtsdebug=1`
unconditionally, over the top of it. The log came back with the terminal
trace and not one 9P message, which reads exactly like "no `Tread`
arrived" -- the answer being looked for -- when the truth is that
nothing was watching. It now assigns only `if(~ $#vtsdebug 0)`.

*A script that sets the variable its caller passes is an instrument
that overwrites its own input.* Same family as `tcl-runall.tcl`'s
`fconfigure stderr -buffering line`, which produced the four `io-14.*`
failures it was there to measure: **an instrument that shares state
with the thing it measures can be the thing it reports.**

And at level 2 it does **not** start vtwin. vtwin polls `cells` several
times a second, so with every T- and R-message printed the startup
exchange -- the whole question -- would sit at the top of a file with
thousands of `Tread`/`Rread` pairs after it. The shell is forked when
vts starts, viewer or no viewer, and it has been dying before the
window ever mattered.

## chatty9p answered, and it took vts out of it

The whole session, in T-messages (`vtsdebug=2`, no vtwin):

```
Topen  fid 303 mode 2                 the shell's /dev/cons, ORDWR
Twrite fid 303 offset 0  count 54     vts: child: fd0=/dev/cons ...
Tstat  fid 303                        x8, during bash's startup
Topen  fid 329 mode 1                 /dev/consctl
Twrite fid 329 count 5 'rawon'
Twrite fid 303 count 8  ESC[?2004h
Twrite fid 303 count 2  '$ '
Twrite fid 303 count 9  ESC[?2004l CR      <- readline giving up
Twrite fid 303 count 1  '\n'
Tstat  fid 303
Twrite fid 329 count 6 'rawoff'
Twrite fid 303 count 4 'exit'
```

**There is not one `Tread` on the shell's fid in the entire session** --
and reads plainly work, because the `ctl` and `ttyctl` reads a moment
later are right there in the same log. Between the prompt and readline's
`ESC [ ? 2004 l` there is **no 9P message at all**: not a read, not a
stat, nothing. So bash did not ask vts for input and get a wrong answer.
**It never asked.**

*A missing message is the strongest evidence in this log, and it is only
readable because every other message is present.*

`fd0=/dev/cons fd1=/dev/cons fd2=/dev/cons` in the same log says the
descriptor is the right file, so this is not a plumbing mistake either.

### Three mechanisms read out of the source, and all three refuted

Worth recording because each looked convincing and each cost a pass:

- **`FIONREAD` returning `st_size`.** libap implements it as an
  `fstat`, which is what the eight `Tstat`s are, and our served file has
  `l 0` -- so it always answers "nothing to read". That is a real
  approximation and it is *not this*: readline only reaches `FIONREAD`
  through `rl_gather_tyi()`, which `rl_read_key()` calls **only when
  `rl_event_hook` is set**, and this bash never sets it
  (`grep -rn 'rl_event_hook *=' sys/src/external/bash` finds only
  readline's own definition). The decisive point is simpler: there is no
  stat between the prompt and the EOF.
- **`O_NONBLOCK` diverting the read into `_readbuf`**, which could
  answer EOF from a shared buffer with no syscall. Dead on the numbers:
  `readprocfdinit()` sets `oflags` to `O_RDWR`, which is **2**, and
  `O_NONBLOCK` is **4** (`sys/include/ape/fcntl.h`). `isregular()` is
  behind `noblock &&`, so it is never even called -- which independently
  says the stat could not have come from libap's read path.
- **`_fdinfo[0]` not marked open**, giving `EBADF` before the syscall.
  Not refuted, and it is now instrumented rather than argued.

*Three mechanisms, three refutations, one of them by a constant I had to
look up. The honest tally in this tree is about one in eight for
mechanisms guessed from code alone; this round ran true to it.*

### What the next run asks, and the cheap control comes first

**Control, no rebuild at all: run the session's shell as `rc`.**

```
SHELL=/bin/rc ./vts-bash
```

`rc` is a native Plan 9 program and links none of libap. If rc gets EOF
and exits at once too, the fault is in what vts answers and the APE side
is innocent; if rc sits at a prompt and takes typing, vts is exonerated
and everything above stays on the libap side. **One variable, one
command, and it halves the space** -- which is worth more than another
reading of bash.

Then, on the next rebuild, `$APEXP_DEBUG` traces `read()` itself
(`ap/unistd/read.c`, gated on `_apdbgon()` so a normal run costs one
load and one branch):

```
read: enter fd=0 n=1
read:  fdinfo flags=... oflags=...
read:  -> direct n=... errno=...
read: EBADF, no syscall fd=0        <- the answer that never leaves libap
```

**Nothing printed means bash never called `read`**, which sends the next
round into bash rather than libap; `enter` with no `->` means it went in
and did not come out. vts now puts `APEXP_DEBUG` in the shell's
environment whenever `$vtsdebug` is set, and those lines go to fd 2 --
the terminal -- so they travel back through the server and land in
**vts's own log, interleaved with the 9P trace**. Both halves of the
conversation, one file, in order.

### One real bug found on the way, and not the one being hunted

`ioctl(FIONREAD)` wrote its answer as `*(long*)arg`. The argument is an
**`int *`** on BSD, on Linux and in every caller here -- readline passes
`&chars_avail`, an `int` local -- so on amd64 this stored **eight** bytes
and smashed the four beyond it, whatever the compiler had put next in
the caller's frame. The store succeeds, so nothing complains; what shows
up is a neighbouring variable being zero for no reason, somewhere else.
Fixed. **Recorded as found, not measured**: it is not what made bash
exit, and saying so is the point.

## rc lives, bash does not: the split came out on the libap side

`SHELL=/bin/rc ./vts-bash` **gives a `term%` prompt that stays, and
takes typing.** So vts delivers keystrokes, the tty file serves reads,
and the bind is right. **Everything from here is APE-side**, and one
command bought that — the control was worth more than another reading
of bash.

*(Typing still renders badly — a few characters out of what was typed.
That is a separate question, and rc having got far enough to show it is
progress. It belongs to `lined` and the cell diff, not to this.)*

And from the other end, with `read()` traced:

```
read: enter fd=3 n=139     ...  read:  -> direct n=139 errno=20
read: enter fd=5 n=2048    ...  read:  -> direct n=2048 errno=0
read: enter fd=5 n=4220    ...  read:  -> direct n=4220 errno=0
vts: ttyctl write 5 [rawon]
vts: tty write 8 [<1b>[?2004h]
vts: tty write 2 [$ ]
vts: tty write 9 [<1b>[?2004l<0d>]
```

**Not one `read: enter fd=0` in the whole session**, while reads on fd 3
and fd 5 work perfectly. bash never asked for input, confirmed from
inside libap this time rather than inferred from a missing 9P message.

### rl_getc puts select in front of the read, and trusts it

```c
      result = 0;
#if defined (HAVE_PSELECT) || defined (HAVE_SELECT)
      result = _rl_timeout_select (fd + 1, &readfds, NULL, NULL, NULL, ...);
      if (result == 0)
        _rl_timeout_handle ();
#endif
      if (result >= 0)
	result = read (fd, &c, sizeof (unsigned char));
      ...
      if (errno != EINTR)
	return (RL_ISSTATE (RL_STATE_READCMD) ? READERR : EOF);
```

`sys/src/external/readline/config.h` has `HAVE_SELECT 1` and
`/* #undef HAVE_PSELECT */`, so that block is compiled in and
`_rl_timeout_select` is `select()`. **A negative return means `read` is
never called at all, and readline turns it straight into EOF** — which
is the measurement exactly.

So libap's `select(1, {fd 0}, 0, 0, NULL)` answered negative. Reading
the function narrows it to three returns, and **eliminates the rest**:

- a return of **0** cannot be it: `result >= 0` still calls `read`, and
  no read happened;
- **EBADF on `_fdinfo[0]`** is ruled out separately by `_fdinit`'s own
  safety net, which forces `FD_ISOPEN` on 0, 1 and 2;
- and the blocking arm is right: with `timeout == NULL` no timer is
  armed, `rwant` gets fd 0 and the call waits on the rendezvous, which
  is what rc's shell is doing now.

That leaves `_startbuf(-1)` (the `RFORK(RFREND)` and the `SEGATTACH`
that build the shared segment), `_startbuf(0)` (EBADF, `FD_BUFFEREDX`,
ENFILE), and the copy-process fork. **Every one of them now names
itself under `$APEXP_DEBUG`**, so the next run picks one instead of me
picking one.

### And an unchecked fork that hangs for ever

`_startbuf` did not test the result of
`_RFORK(RFFDG|RFPROC|RFNOWAIT)`. A failure stored `-1` as the copy
process's pid and the parent went straight to
`_RENDEZVOUS(&b->copypid, 0)` — **waiting for a process that was never
created, inside `read()` or `select()`, with nothing printed.** Fixed.
**Found while instrumenting, not measured**: bash exits rather than
hangs, so it is not this bug. An unchecked fork whose failure mode is
an unbreakable wait is wrong on its own terms.

## It was never vts, and the trace said so twice before the answer came

```
select: enter nfds=1 t=-1
_startbuf: EIO, FD_BUFFEREDX fd=0 flags=42
select: -> -1, _startbuf fd=0 errno=13
```

fd 0 arrived from the exec already marked poisoned, `select()` refused
with EIO without touching it, and readline turns any error from
`rl_getc`'s select into end of file. **Diagnosed in libap, fixed in
libap** -- see the `FD_BUFFEREDX` section of `docs/notes/libap.md`.

**Four rounds, and vts was innocent from the first one.** Worth reading
as a sequence, because each step removed a whole area and none of them
needed the next guess:

1. `chatty9p` -- no `Tread` on the shell's fid at all, while `ctl` and
   `ttyctl` reads in the same log worked. *bash never asked.*
2. `fd2path` before exec -- `fd0=fd1=fd2=/dev/cons`. *The descriptor
   was right.*
3. `SHELL=/bin/rc` -- an rc prompt that stays and takes typing.
   *vts delivers input; the fault is APE-side.* One command.
4. `$APEXP_DEBUG` in `read()` and then in `select()` -- the flag, the
   fd and the errno, in one line.

*Each of the four was cheaper than the reading it replaced, and three
of them were controls rather than measurements of the thing itself.*

The instruments stay. `$vtsdebug=1` traces the terminal, `=2` adds
lib9p's `chatty9p` and skips vtwin, and vts passes `APEXP_DEBUG` to the
shell so libap's own lines come back through the server into the same
log -- both halves of the conversation, in order, in one file.

**What is open in vts now is rendering, not plumbing**: under rc the
prompt is right but typed characters come back partial, which is
`lined` and the cell diff. That is the next question here, and it is a
better one than the last four.

## bash READS, BLOCKS AND ECHOES: the session works

```
vts: tty write 2 [$ ]
vts: tty read: blocked (1 waiting)          <- waiting for a keystroke
select: buffered now fd=0 flags=38
read: enter fd=0 n=1
read:  fdinfo flags=38 oflags=0
read:  -> buffered n=1 errno=0
vts: tty write 1 [c]                        <- and echoes it
```

**`flags=38` is `0x26` = `FD_ISOPEN|FD_BUFFERED|FD_ISTTY`** -- buffered
and **not** poisoned, where the failing run showed `0x2A` with
`FD_BUFFEREDX` set. The whole chain works: `select()` buffers fd 0,
`read()` takes the buffered path, the shell blocks on `tty read`, vts
serves the keystroke, bash echoes it. **Four rounds of diagnosis and
the fix was one line in `sfdinit`.**

`vts: tty read: blocked (1 waiting)` is the line that never appeared
before and is the one that matters: *the shell is waiting for input
rather than deciding it has none.*

### The diagonal text was the instrument, for the third time

Typing produced text marching diagonally down and right across the
screen. That is not vts and not the VT parser -- it is `_apdbg()`
ending every line with `\n` and no `\r`.

**Since `tcsetattr` started working, fd 2 is often a terminal in RAW
mode**, where `\n` is a pure line feed and the cursor keeps its
column. Each line therefore starts one further right than the last.
Classic staircase, and it looked exactly like a terminal-emulator bug.

`_apdbg` now writes `\r\n`. Harmless elsewhere: a cooked terminal
drops the CR and a log file gains a byte per line. *A debug line that
cannot be read is not a debug line* -- and **the rule that keeps
firing is `a fix that makes a process reach code it never reached
before can expose anything on that path`**: raw mode becoming real is
what made this visible, the third thing that fix has surfaced.

Two more noise fixes, because the useful lines were being drowned:

- **`$APEXP_DEBUG` now reaches the shell only at `$vtsdebug=2`.**
  libap's lines go to fd 2, which under vts is *the session's own
  screen*, so three lines per keystroke bury the session in its own
  diagnostics. Level 1 keeps vts's view -- blocked, served, every
  write -- which goes to vts's fd 2, a **log file**, and never touches
  the screen. The old behaviour was right while the shell was dying
  before its first read and is wrong now that it works.
- **`close of a descriptor with no listener` was printing on EVERY
  close in every program**, under the general `$APEXP_DEBUG`, and
  almost no descriptor has a listener -- so it said nothing and
  drowned the `read()` and `select()` traces beside it. It is now
  under `$APEXP_LISTENDEBUG` alone, whose subject is that table and
  where "nothing recorded for this fd" is a real answer. Cached,
  because `close()` is on everyone's hot path.

*An instrument sized for a dead shell is the wrong size for a live
one.* Worth remembering when the next one goes in.

## Characters are swallowed, and the log cannot yet say by whom

Typing `echo $SHELL` came back as `eho$SELL`.

```
  e  c  h  o     $  S  H  E  L  L      typed
  0  1  2  3  4  5  6  7  8  9 10
     x        x        x               lost
```

**Indices 1, 4 and 7 -- every third byte.** That is not "certain
characters", it is an accounting or racing bug, and it is worth saying
so before looking at the code: a reader that blamed the *characters*
would go hunting for a control-code filter that does not exist.

**bash really did receive less than was typed** -- `bash: S: command
not found` means the word it parsed was `S`. So this is not only a
rendering fault. But `2004h$` on screen *is* rendering: readline's
`ESC [ ? 2004 h` arriving with `ESC [ ?` missing. **Two directions are
losing bytes**, and whether they share a cause is exactly the question
that should not be assumed either way.

### What was read, and what it eliminated

- **`tty_serve` is correct.** It copies `min(queued, count)`, then
  `ttyin_len -= n` and shifts the remainder down. A partial read keeps
  the rest.
- **`session_feed_keystrokes` is correct.** It appends under
  `ttylock`, drops only when the 8K queue is full, and says so.
- **The `cons` write arm is correct when `lined` is off** -- a straight
  `session_feed_keystrokes` of the whole write.
- **A keystroke arriving while no reader is queued is NOT lost**: the
  write appends to `ttyin` regardless, and the copy process's next
  `_READ` collects it. That window was the obvious suspect and it is
  shut by construction.
- **`_readbuf` consumes correctly**: `ngot = putnext - getnext`,
  clamped to `nwant`, `getnext += ngot`.

### So the instrument, not a sixth guess

**The one step the log has never covered is the delivery itself.**
`$vtsdebug=1` traces what the shell *wrote* and whether a read blocked;
it never traced what a viewer *sent* nor what the shell was *handed*.
So a lost keystroke could be dropped in vtwin, in the `cons` arm, in
the tty queue, or inside libap's copy process, and the log could not
tell those four apart.

Two lines fix that:

```
vts: cons write (from viewer) 1 [c]
vts: tty read: HANDED 1 [c]
```

**What the next run decides, written down first:**

- both lines show every byte typed -> vts delivered everything, and
  the loss is **inside libap's buffering**, where *bash reading ONE
  BYTE AT A TIME* is an unusual pattern for code every other caller
  exercises in big chunks;
- `HANDED` is short of `cons write` -> the loss is **in vts**, and
  `lined` is the first place to look;
- `cons write` is itself short of what was typed -> the loss is **in
  vtwin**, before vts sees anything.

And the same log answers the output half independently: every
`tty write` is already traced, so whether bash emitted a whole
`ESC [ ? 2004 h` is readable off the same file. *Two symptoms, one
run, and no need to decide in advance whether they are one bug.*

## The keystrokes never reach vts, and the thief is almost certainly the launching bash

The trace answered on the first run, and it is the third branch of the
three written down before it:

```
vts: tty write 2 [$ ]
vts: cons write (from viewer) 1 [h]
vts: tty read: HANDED 1 [h]
vts: tty write 1 [h]
vts: cons write (from viewer) 1 [o]
vts: tty read: HANDED 1 [o]
vts: tty write 1 [o]
vts: cons write (from viewer) 1 [L]        ... and [L], [<0a>]
```

`echo $SHELL` was typed. **Five `cons write`s arrived: `h o L L \n`.**
Every one of them was HANDED to the shell and echoed, one for one.

**So vts and libap are exact, and the missing bytes never arrived at
all.** The loss is upstream of the server, in or before vtwin. That
also retires "every third byte": with only 4 of 11 surviving and no
pattern, it is a *race*, not an accounting slip -- and the earlier
1/4/7 reading was a four-sample coincidence I should have hedged
harder.

**First suspect, opened and cleared**: `vtwin/main.c` had a
`kbdthread`/`init_kbd_thread` pair calling a SECOND `initkeyboard()`,
which would have been precisely a second reader of `/dev/cons`
splitting the keyboard. **It was never called** -- the channel it read
was never even created. *A grep hit is a name, not an implementation.*
Deleted, because it reads like the bug.

### The mechanism that fits, and it is one we already measured

**libap's `select()` does not poll a descriptor -- it forks a copy
process that READS IT CONTINUOUSLY** into a shared buffer, whether or
not anybody wants the data, for as long as the process lives.

`apexp-sh` ends in `exec bash -l`. That bash is interactive, so
readline calls `select()` on fd 0, so **libap forked a copy process
that is reading the rio window's `/dev/cons` and never stops.** When
`./vts-bash` runs, bash forks and waits -- but its copy process is
still sitting in `_READ` on that same console, beside vtwin's libdraw
keyboard proc. **Each keystroke wakes exactly one of them, and which
one is the kernel's choice.**

That fits every part of the observation: roughly half to two thirds
lost, no pattern, and worse the longer it runs (the thief has 16K of
room and never stops taking). And it is **the same root** as the thing
`bufexec-test` measured two rounds ago and this file already records
as unfixed: *the parent's copy process is still alive and reading the
same open file, so parent and child compete.* This is that, with a
visible consequence.

**It also survives `exec`.** `_killmuxsid` is an **atexit** handler and
`execve` never calls it, so a copy process outlives the image that
created it. So does `fork`'s: the child `_detachbuf()`s its own view,
and the processes belong to the parent regardless.

### The control costs one look and no code

**Type into vtwin, quit vtwin, and look at the bash prompt underneath.**
If the missing characters are sitting there -- a prompt reading
something like `ec $SHE` -- then bash's copy process took them, and
the diagnosis is closed by a glance. If the prompt is clean, they were
lost somewhere else and this whole reading is wrong.

*Predict the observation, not the conclusion*: the prediction is
"the launching shell's command line contains the bytes vts never saw",
and its refutation is an empty prompt.

### And the output half is now isolated too

The same log has `vts: tty write 8 [<1b>[?2004h]` -- bash emitted the
**whole** bracketed-paste sequence, and vts received it whole. So the
`2004h` visible on screen is not a torn write and not an input
problem: either libvterm is not consuming the private-mode form, or
the cell diff is rendering what it should have swallowed. **A separate
bug, now with its own evidence**, and not to be folded into the
keystroke question.

## The keystrokes are fixed; the remaining ugliness is `2004h`

The partition test passed on its first run with an ordinary bash as the
launching shell -- eleven bytes in, eleven handed over, outer prompt
empty. **The input half is done.**

What is left on screen is the output half, and it is now fully
isolated:

```
vts: tty write 8 [<1b>[?2004h]      vts received all eight bytes
screen:  ...cons2004h$ echo $SHELL  and five of them are TEXT
```

**The cursor column proves it arithmetically rather than by eye**: the
session's `ctl` reported `cursor=1,60`, and 53 (the debug line above
it) + **5** (`2004h`) + 2 (`$ `) is exactly 60. So libvterm printed
those five characters; `ESC`, `[` and `?` were consumed.

*(The far-right indentation is a second, separate thing and it is mine:
`session.c`'s child prints its `fd0=... fd2=...` line with `\n` and no
`\r`, and the console is in raw mode. Same staircase `_apdbg` had.)*

### The hypothesis, and how it is settled rather than argued

libvterm consumes that sequence by setting an escape flag on `ESC` and
**clearing it** when the next byte is hoisted into a C1 control:

```c
bool in_esc : 1;		/* vterm_internal.h:205 */
```

**A one-bit field that accepts a 1 and ignores a 0** -- a store that
ORs the new value in without masking the old one out -- leaves the
parser believing it is still inside an escape, and the bytes after it
are then eaten as a bogus escape and printed. That is the shape of
what the screen shows.

**kencc's bit fields came from a patch that predates `bool` being a
real type here**, so a `bool` bit field may take a path `unsigned`
does not.

`sys/lib/tests/bitfield-test.c` **section 10** asks it: set true, clear
to false, clear with `= 0` (libvterm uses both spellings in the same
function), the same two for an `unsigned : 1` **beside it**, and a
check that neighbouring fields survive. *The `unsigned` twin is what
makes the answer attributable* -- bool failing while unsigned passes
names the base type; both failing names clearing in general; both
passing refutes this reading entirely and sends the next round into
libvterm's parser directly. **It passes on gcc**, so a failure on
kencc is kencc's.

```
cd sys/lib/tests && pcc -o bitfield-test bitfield-test.c && ./bitfield-test
```

*Note it is `pcc`, i.e. APE's compiler, while libvterm is built NATIVE
by `6c`. They share the front end (`sys/src/cmd/cc`), which is where
bit fields live, so the test is honest about the mechanism -- but if
section 10 passes and the screen still shows `2004h`, that difference
is the first thing to suspect.*

## The bit-field hypothesis is REFUTED, and cleanly

`bitfield-test.c` section 10 passes on 9front: a `bool` bit field
holds true, **clears to false**, clears when assigned `0`, and the
`unsigned : 1` beside it does the same, with the neighbours intact.

**The caveat I raised closes rather than lingering.** APE's
`<stdbool.h>` deliberately does *not* redefine `bool` -- it is kencc's
own keyword, an `unsigned char`, and the header says so and explains
why (a `#define bool _Bool` round-trip once emitted `_Bool` as an
undefined external symbol). And `pcc` **is** `6c` with APE flags. So
the test measured the same type, compiled by the same compiler, as
libvterm gets natively. *The refutation is total; the reading was
simply wrong.*

**That is the branch written down before the run**, and it cost one
30-second command rather than a rebuild. Worth noting which part did
the work: not the passing `bool` cases on their own, but the
`unsigned : 1` **beside** them. Had both failed it would have been
clearing in general; had bool alone failed it would have been the base
type. Both passing is only informative because the two were asked
together.

### So: libvterm, and a probe that splits it in one run

`sys/src/cmd2/vts/test/vtparse-probe.c` is **native** (libvterm is
built by `6c` against Plan 9's libc, so the probe is too; the build
command is in the file). It feeds exactly the eight bytes the server
logged, one at a time, printing the parser's state and `in_esc` after
each, then writes `$ ` and prints the screen row.

**It separates the two candidates without touching either:**

- screen row 0 is `$ ` -> **libvterm consumed it**, with no vts, no 9P
  and no terminal in the picture. The fault is then in what vts
  *feeds* the engine -- `engine_feed`, the `tty` write arm, or a
  second writer interleaving into one parser, which this file has
  suspected once before.
- row 0 contains `2004h` -> **libvterm printed it**, and the per-byte
  trace names where: byte 1 (`[`) should reach `CSI_LEADER`, byte 2
  (`?`) should stay there, bytes 3-6 should be `CSI_ARGS`.

It prints the evidence and then one verdict line, because the question
is binary and a reader should not have to count columns. *A probe that
reuses the code under suspicion cannot clear it*, so it calls libvterm
directly and formats the screen itself rather than going near
`celldiff`.

## libvterm PRINTS it, and the byte is the first digit

`vtparse-probe`, built the way vts is (`6c -I/sys/include`, no `-T`):

```
first 1 byte  -> 0 chars on row 0  ""
first 2 bytes -> 0 chars on row 0  ""
first 3 bytes -> 0 chars on row 0  ""
first 4 bytes -> 1 char  on row 0  "2"
first 5 bytes -> 2 chars on row 0  "20"
...
first 8 bytes -> 5 chars on row 0  "2004h"
```

**`ESC`, `[` and `?` are all consumed; the first `2` is where text
starts.** So this is libvterm, with no vts, no 9P and no terminal
anywhere near it -- branch (a), and vts is cleared.

### And the source says that byte cannot print, which is the interesting part

After `?` the parser must be in `CSI_LEADER`: `parser.c`'s C1 dispatch
for `0x9b` is exactly `leaderlen = 0; ENTER_STATE(CSI_LEADER)`, and
`?` (0x3f) is stored by the `0x3c..0x3f` arm, which `break`s with the
state unchanged. A digit arriving in `CSI_LEADER` then falls through
to `CSI_ARGS` and is accumulated. It is not being accumulated.

**So one of those assumptions is wrong, and reading further is how the
last two rounds were spent.** The next iteration of the probe asks
instead -- a table of sequences, each to a fresh terminal, each
expected to leave the screen empty:

| sequence | what it isolates |
|---|---|
| `hi` | **positive control** -- must print 2 |
| `ESC M` | a bare escape, no CSI at all |
| `ESC [ H` | CSI with no leader and no arguments |
| `ESC [ 2 J` | CSI with one argument |
| `ESC [ 1 m` | CSI, SGR |
| `ESC [ 2004 h` | arguments, **no leader** |
| `ESC [ ? h` | leader, **no arguments** |
| `ESC [ ? 1 h` | leader plus one digit |
| `ESC [ ? 2004 h` | the failing one |

**The control is not decoration.** Without it, a `row0()` that always
answered 0 would make every other line read as a pass -- *a check that
cannot fail is not a check*, and this table is nine of them.

How it will read: only the control printing means the parser is fine
and the failing sequence is not what we think; `ESC [ H` printing too
means CSI never starts and the fault is the ESC-to-C1 hoist or the
`0x9b` dispatch; `ESC [ H` clean but `ESC [ 2 J` printing means the
arguments; only the leader forms printing means the `?` path.

*Two of my own slips are worth recording, because both were the same
kind.* The table first used `\x` hex escapes (risky on kencc) and
**hand-counted lengths, two of them wrong** -- `ESC [ 2004 h` is seven
bytes, not eight. Octal escapes and `strlen` now, so no length in this
file is written by hand. A probe whose constants are wrong reports
about a string nobody sent.

## Every row consumes exactly three bytes, and that names the bug

```
hi               2 printed  "hi"      <- positive control, good
ESC M            0 printed  ""
ESC [ H          0 printed  ""
ESC [ 2 J        1 printed  "J"
ESC [ 1 m        1 printed  "m"
ESC [ ? h        1 printed  "h"
ESC [ ? 1 h      2 printed  "1h"
ESC [ 2004 h     4 printed  "004h"
ESC [ ? 2004 h   5 printed  "2004h"
```

Subtract: **every sequence consumes exactly three bytes and prints the
rest.** `ESC [ H` looked healthy only because it *is* three bytes long
-- and reading the table row by row would have called it a pass. *The
information was in the arithmetic across rows, not in any one of
them.*

So after `[`, exactly ONE more byte is handled in a CSI state and the
parser is back in `NORMAL` for the next -- `vt->parser.state` is not
surviving from one iteration of the byte loop to the next, while
`in_esc`, in the same struct, plainly survives from `ESC` to `[`.

### One mechanism explains all seven rows, with no slack

```c
    enum { NORMAL, CSI_LEADER, ... } state;
    bool in_esc : 1;
```

**Suppose a store to `state` sets the `in_esc` bit** -- the two
overlap. Then:

- `ESC [ 2 J`: `[` hoists to CSI and `ENTER_STATE(CSI_LEADER)` writes
  **1**, which lights `in_esc`. `2` therefore finds `in_esc` true,
  fails the hoist test (0x32 is below 0x40), takes the `else` --
  **`state = NORMAL`** -- and is then eaten by `do_escape`. `J`
  arrives in NORMAL with `in_esc` clear: **printed**. Consumed three.
- `ESC [ ? h`: identical with `?` (0x3f, also below 0x40). `h`
  printed.
- `ESC [ H`: `H` is **0x48**, which IS in `0x40..0x60`, so it hoists
  to `0x88` and `do_control` consumes it as HTS. Clean -- *for the
  wrong reason*, and that is why the row looked fine.
- `ESC M`: same hoist, `M` is 0x4d. Clean, genuinely.
- the three long ones: first post-`[` byte eaten by `do_escape`, all
  the rest printed. `2004h`, `004h`, `1h` -- exactly what the table
  shows.

Seven rows, one mechanism, no leftovers.

### The test already had this struct and still missed it

`bitfield-test.c` section 10 declares that exact shape -- an `enum`
followed by `bool b : 1` -- and checks `bit field stores leave their
neighbours alone`. It passes. **Because it only ever writes the BIT
FIELD and reads the neighbour.** An overlap is symmetric; testing one
direction and treating the pair as covered is the
"negative result with two explanations" trap one level up.

The missing direction is now there: set the bit, **write the enum**,
read the bit back -- both polarities, for `bool` and for
`unsigned : 1`, and the struct's size printed rather than asserted so
an overlap is visible without inferring it from four FAILs. Passes on
gcc (`sizeof` 12: enum 4, the two bit fields sharing one word, int 4).

**Prediction: on 9front those four lines FAIL and `sizeof` is 8**, one
word short, with `state` and the bit fields sharing it. Refuted if
they pass -- and then the overlap story is wrong and the next place is
`vterm_input_write`'s chunking, since the probe feeds whole prefixes
in one call and libvterm may not.

## The overlap is refuted too, and on the WRONG SIDE of the number

`bitfield-test` section 10 passes on 9front, all four new directions,
and `sizeof struct flags` came back **16** where gcc says 12. I
predicted 8. **An overlap would have made it smaller; padding made it
bigger** -- 12 rounded up to 16 is the tail-rounding rule already in
the invariants list, not a new bug. So the reading was wrong and the
number contradicted it in a direction I had not even allowed for.

*Two mechanisms proposed for libvterm, two refuted, both by tests that
took thirty seconds because the refutation condition was written down
first.* The honest tally in this file says about one in eight for
mechanisms guessed from code alone; this investigation is running
worse than that.

### And the reason the test could pass while the bug is real

**The struct in `bitfield-test` is one I RETYPED.** libvterm's is not
that struct:

```c
  struct { unsigned int utf8:1; unsigned int ctrl8bit:1; } mode;
  struct {
    enum VTermParserState { NORMAL, CSI_LEADER, ... } state;
    bool in_esc : 1;
    int intermedlen;
    ...
  } parser;
```

`parser` is a **nested anonymous struct inside `VTerm`, preceded by
another nested struct of bit fields**, and kencc has a documented rule
about nested struct members (`6c/swt.c`'s `align()`, case `Ael1`).
A retyped copy can pass while the original does not.

*A model of a struct is not the struct* -- which is
"replicate the code in the tree, line by line, not the code you
remember" with a different noun, and I have now paid for it twice
inside one investigation.

### So ask the real one

`sys/src/cmd2/vts/test/vtlayout-probe.c` includes libvterm's own
`vterm_internal.h` and pokes the actual declaration with the actual
compiler:

```
6c -I../../../lib/libvterm vtlayout-probe.c
6l -o vtlayout-probe vtlayout-probe.6
./vtlayout-probe
```

**It links, and that is not luck**: completing the opaque types is
what broke `vtparse-probe`, but only because that one *calls*
libvterm. This calls nothing from the library, so there is no second
object to disagree with.

It writes `state` and reads `in_esc` (the direction the parser
actually takes), then the reverse, then checks that a store to
`intermedlen` leaves `state` alone -- and **hex-dumps the first
sixteen bytes after each**, so an overlap is visible rather than
inferred. Section 4 is the positive control: all three fields set to
distinct values at once. If the control fails, every section above it
is meaningless and *that* is the finding.

**If it comes back clean, the layout is innocent** and the state is
being kept but lost some other way -- and the next suspect is named in
the output: whether `vterm_input_write` hands the parser one byte per
call, since the probe feeds whole prefixes and libvterm may not.

## It came back clean, and the answer was the spelling of the constant

```
in_esc=1 then =0        -> in_esc=0 (want 0)
in_esc=true then =false -> in_esc=1 (want 0)
*** `= false' does NOT clear it, while `= 0' above did.
after state=CSI_LEADER: 01 00 00 00 00 00 ...
after in_esc=1:         00 00 00 00 01 00 ...
CONTROL, all three set: state=3 in_esc=1 intermedlen=7
1 problem
```

`state` at offset 0, `in_esc` at offset 4, **no overlap**, and the
control passes -- so the layout is innocent, as section 2 of the probe
was written to be able to say. What named the bug was **section 2b,
asking `= 0` and `= false` side by side on the same field in the same
run**: one clears and the other does not, which leaves nothing about
the struct to blame and only the constant.

**It is `false` itself.** kencc's C23 keywords never set
`yylval.vval`; see `docs/notes/kencc.md`. libvterm's parser.c clears
the flag in two places with two different constants -- the ESC-to-C1
hoist uses `= false` and the `NORMAL` case uses `= 0` -- so the hoist's
clear never took, `[` was swallowed as an unhandled escape byte, the
next byte was eaten by `do_escape`, and everything after it printed.
**That is the three-byte consumption, all seven rows, from one line.**

## Confirmed, and the probe's own conclusion had to be rewritten

Rebuilt compilers, rebuilt libvterm, `vtparse-probe` again:
**0 chars for all eight prefixes, `0 of 9 unexpected`, `CONSUMED`**,
with `hi` still printing 2. Predicted before the run, including the
refutation condition (any CSI row still printing would have meant
`false` was only part of it).

**And the probe was saying something false by then.** Its `CONSUMED`
arm read *"the fault is NOT in libvterm -- it is in what vts feeds the
engine"*: correct as the branch to take while libvterm was the
suspect, wrong the moment the table came back clean *because libvterm
had been recompiled*. Left alone it would have sent the next round to
`engine_feed` with a confident false lead.

So the arm now says what a clean run actually licenses: it clears
**the libvterm in front of you, built by the compiler in front of
you**. A stale `libvterm.a`, or a `vts` still linked against one,
reads identically. **A clean table beside a dirty screen is a BUILD
question first** -- relink vts -- and only a disagreement on the
*same* build puts the next round in `engine_feed`, the tty write arm
or a second writer.

*An instrument that bakes in the conclusion for one branch goes on
asserting it after that branch stops being the live one.* Same family
as the harness that set `-buffering line` in the interpreter it was
measuring, and the `vts-bash` that overwrote the `$vtsdebug` its
caller passed.


---

## Raw mode, readline, and what vts is for

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

**Next after Tcl: a vt, and the first step is DONE but NOT MEASURED.**
The goal is bash's own tab completion under `vts`, and the blocker was
not `vts` at all. **`tcsetattr` on a real `/dev/cons` returned 0 and
changed nothing**, while `tcgetattr` reported a hardcoded
`ICANON|ECHO` whatever the console was doing -- so readline asked for
raw, was told it got it, and waited for keystrokes the driver was
holding until Enter. Tab arrived inside a finished line. Both halves
silent. `plan9/tty.c` now owns the one switch Plan 9 offers
(`rawon`/`rawoff` on `/dev/consctl`) and termios drives it; see
`docs/notes/libap.md`.
**CONFIRMED**, and the refutation condition did better than refute:
against the OLD library the test would not LINK -- `main: undefined:
_ttymark` -- so measuring the stale libap and calling it a pass was
impossible. That idiom has now paid three times (`_sock_listenmark`,
`_execmark`, `_ttymark`). On the rebuilt library `_ttymark = 1` and
`c_lflag` runs `0x57 -> 0x40 -> 0x57` across sections 3 and 4, with
`ICANON` and `ECHO` reading back clear and then set again. 0 failures.
**`tcsetattr` now does something.**
**Watch for**: this makes raw mode actually happen, so every program
that asked for it and silently did not get it now does -- bash,
libedit, PDCurses. *A fix that makes a process reach code it never
reached before can expose anything on that path.* A crash while raw
self-heals, because the console reverts when the last consctl
descriptor closes and a dead process has closed it.
**Section 5 CONFIRMED too**: `read(0) -> 1, byte 0x6a` -- one
keystroke, no Enter. Raw mode works end to end on 9front.
**But bash's Tab still only inserted a tab, and that was a SECOND
bug in a different place.** `sys/src/external/bash/config.h` said
`/* #undef READLINE */` -- upstream's unconfigured default, since bash
ships everything off and `configure` turns it on, and APExp
hand-maintains that file the way it does perl's. So
`no_line_editing` was 1 from `shell.c:230` and line editing was
compiled out of the shell; bash read whole lines with `getc` and the
console echoed the Tab. **Nothing was missing**: `libreadline.a` is
built from `sys/src/ape/lib/readline`, its headers are installed,
`bashline.c`/`bashhist.c`/`pcomplete.c`/`pcomplib.c` are all in
OFILES, and `bi-bind`/`bi-complete`/`bi-fc`/`bi-history`/`bi-shopt`
are all in OBJBUILTINS. The entire apparatus was compiled, linked and
switched off by one commented-out line -- *a capability present and
not declared*, the same shape as zipfs's two missing `file stat` keys.
`READLINE` and `HISTORY` are now on; `BANG_HISTORY` deliberately is
not, being a change to what `!` means rather than to line editing.
**TAB COMPLETION WORKS.** Built, and it took on the first try --
kencc had no opinions about four files' worth of code that had never
been compiled here. `$TERM` is **`dumb`**, which is the honest value
for rio and costs nothing: `terminal.c:583` only clears
`_rl_term_isansi`, `sys/lib/ape/termcap` has a `dumb` entry, and Tab
is bound from the keymap regardless.
**ARROW KEYS DO NOT WORK, AND THAT IS rio, NOT US.** They scroll the
window instead -- measured with readline running and raw mode on, so
rio is eating them before bash sees them; a program cannot get those
keys back under rio at all. **`^P`/`^N` give history today**
(`emacs_keymap.c:49`/`51`), which is the whole of what the arrows
would have bought.
**So vts is no longer on the critical path for completion** -- but it
is still what would buy arrow keys, colour, cursor addressing and
anything else needing escape sequences rio does not speak, plus
session persistence. Keep it; it is a want rather than a blocker.
**KEEP `vtwin` AND `vts-attach`, AND WRITE NO GLUE.** They are not
glue -- they are two front ends onto the same 9P interface
(`/n/vts/<sess>/cells` read for diff frames, `.../cons` written for
keys). `vtwin` (1281 lines) is the **graphical** half, a rio window;
`vts-attach` (302 lines) is the **dumb-TTY** half for ssh, drawterm or
a bare `rc`, which is the session persistence. *Two clients is also
what makes `cells`/`cons` a real interface rather than vtwin's private
back door.*
**The missing piece is not between vts and bash -- it is inside
`vts/session.c`**, which gives the shell a **pipe** on fd 0, does not
take `RFNAMEG`, and execs a hardcoded `/bin/rc`.
**And `isatty` decides the design**: `ap/unistd/isatty.c` matches on
the PATH ending in `/dev/cons` (the suffix test is there for
`/mnt/term/dev/cons`), so a cons opened as `/n/vts/1/cons` is not a
tty however well it behaves. **`rfork(RFNAMEG)` and BIND** the
session's `cons` and `consctl` over `/dev/cons` and `/dev/consctl`,
then open `/dev/cons` for 0/1/2 -- `fd2path` then answers `/dev/cons`,
**no libap change is needed**, and it is what rio does for its own
windows. Loosening `_isatty` instead would be the "invent semantics to
make a test pass" shape. That bind is also where the **per-session
`consctl`** lands, so the two recorded steps are one edit.
**`vts-bash` IS THE LAUNCHER, and it must run from inside
`apexp-sh`** -- that is the mechanism, not a convenience: apexp-sh's
`bind -b` lines are what put `vts`/`vtwin` and `bash` on the path,
and its `SHELL=bash` is what vts reads to know what to exec. vts forks
with `RFNAMEG|RFENVG`, both of which COPY, so the shell inherits both.
From a plain `rc` none of it is true and vts falls back to `/bin/rc`.
**It lives in `rc/bin/vts-bash`**, which `apexp-sh` binds onto `/bin`,
so it is `vts-bash` and not `./vts-bash` -- and **`./apexp-sh -v` does
both steps in one**, dropping back to the shell afterwards rather than
exec'ing, because the script ends by printing the whole server log and
a window that closes on it makes that log unreadable. `rc/bin` rather
than `rc/bin/ape`: it drives NATIVE `cmd2` binaries, and `rc/bin/ape`
is the APE toolchain wrappers.
**`lined` is left ON at spawn and the shell turns it off** by writing
`rawon` to `ttyctl` (which readline's `tcsetattr` already sends):
9front's rc neither echoes nor cooks, so lined-off would blank every
non-bash session -- and *the failure mode decides it*, since lined-on
still gives a usable cooked shell if bash never reaches `tcsetattr`.
**SECOND RUN: THE SHELL NOW EXITS IMMEDIATELY, AND THAT RETIRES THE
DOUBLE-ECHO STORY BELOW.** The launching window says
`/bin/bash forked pid=532 on /mnt/1/tty` -- so `$SHELL` resolved, the
bind path is right, and **no child complaint appeared**, which clears
`open /srv/vts`, `mount /mnt`, both binds and `open /dev/cons`, since
each prints to fd 2 and fd 2 is still that window. Then
`shell 532 exited: ok` -- and `ok` is not a figure of speech: every
`_exits` in the child passes a NAME (`srv`, `mount`, `bind`, `cons`,
`exec`), so an empty message means **bash ran and exited 0**.
**A shell that exits 0 the instant it starts read EOF on stdin.**
`fsread` on `tty` has three arms -- serve, **EOF when `!rc_alive`**, or
block -- and only the middle one ends a shell; `rc_alive` is set right
after `rfork`, long before the child finishes mounting and exec'ing, so
that race is not close. **So either something else answers 0 or bash
never reaches the read, and both are one log line away.**
`$vtsdebug` now traces the shell's side: what it wrote, whether
`rawon` arrived, whether it blocked, whether it got EOF. **Not noisy --
only the shell touches `tty`**; viewers write `cons` and poll `cells`.
`vts-bash` sets it.
**And rc HAS NO `break`** (it looked for `./break` four times). A flag
is how to leave an rc loop; that joins *`sleep` takes whole seconds* on
the list this script has paid for.
*(The garbling below is a DIFFERENT build and a different failure --
that session at least stayed alive to be typed at. Do not carry it
forward.)*

**FIRST RUN: readline IS RUNNING -- the bind works -- AND THE INPUT IS
GARBLED.** The session printed `2004h$ 20041`, which is readline's
bracketed-paste `ESC [ ? 2004 h`/`l` with the `ESC [ ?` missing, and
`echo $SHELL` came back as `cho Scho SH` / `echo S` / `SHL`. readline
only emits those sequences when it is driving the line, so
**`isatty(0)` was true and `/dev/cons` is a real terminal** -- the half
this change was for is CONFIRMED.
**The garbling is TWO WRITERS FEEDING ONE VT PARSER.** `engine_feed`
is a bare pass-through to `vterm_input_write`, which holds parser state
across calls, so a torn `ESC [ ?` was interrupted by someone else's
bytes rather than by a write boundary; and the doubled character groups
are double echo. The only two writers are `fswrite` on `tty` (the
shell's output) and **`lined`'s redraw, which runs only while
`s->editor.enabled`** -- so `lined` was on while bash echoed, and the
`rawon` that should have turned it off never arrived. *(The `cells`
read is excluded: it holds `s->lock`, and so does the write.)*
**Two stories fit, they need different fixes, and I have changed my
mind about this once already -- so the script now ASKS for me.** `ctl`
carries `raw=` and `lined=`, and `vts-bash` prints it twice: a second
after the shell starts and again after vtwin exits. `rawoff` plus a
consctl bind complaint means the bind failed; `rawon` means readline's
per-line unprep put lined back, and lined must then stay off once a
shell has ever asked for raw.
**AND THE FIRST ASKING WAS UNANSWERABLE, WHICH WAS MY FAULT**:
`cat /n/vts/1/ctl` in another window says `file does not exist`, and
that is CORRECT. `/srv/vts` is global but **a MOUNT is
per-namespace**, and `apexp-sh` opens with `rfork en`, so every window
has its own. The files are reachable from exactly three places --
`/mnt/<sess>/` inside the session's shell, and `/n/vts/<sess>/` in
vtwin's window or the one that ran `vts-bash` (which now mounts).
*On Plan 9 a path is not an address until you say whose namespace it
is in* -- the same family as an instruction for the other machine
having to name the program that runs it.
**`/srv/vts` already existing now ATTACHES rather than refusing**, and
warns that an already-running server is the OLD binary if vts was
rebuilt since -- so every conclusion drawn from that window is about
the old code. `kill vts | rc ; rm -f /srv/vts` replaces it.
**The consctl bind now happens LAST, after fd 2 is the terminal**, so
its complaint lands in the window being looked at rather than the one
vts was launched from.
**And vts's key interception is the OPPOSITE of what is wanted here**:
`lined.c` batches keystrokes and flushes whole LINES to the shell, so
bash's completion needs `edit off`, not `edit on`. The remaining three
steps are a per-session `consctl` in vts, the shell's fds being a
`cons` bound to `/dev/cons` rather than the pipe `session.c:124` dups
(with a pipe, `isatty(0)` is false and bash never starts readline at
all), and vts spawning bash rather than hardcoded `/bin/rc`.
**And vts would fix the 80-column wrapping too -- but as TWO fixes, and
the bigger one is `$TERM`.** *Columns*: vts has a real character grid
(`cells.h`), so there is an exact number where rio has none -- but
`srv.c:488`/`594` hardcode `session_init(s, name, 24, 80)`, so today it
would report a *correct* 80 rather than a *guessed* one. `cellbuf_resize()`
exists and nothing calls it from a window-size path. Carrying it to the
shell is two `putenv` calls beside the `putenv("vts"...)` already in
`session.c` -- `RFENVG` **copies** the environment, and libap's
`TIOCGWINSZ` already reads `$COLUMNS`/`$LINES`. Resize is still not
automatic (no `SIGWINCH`), but vts owns both ends and can post a note:
*the difference is not that vts can measure and rio cannot, it is that
vts can TELL.* *Wrapping*: correct width alone would NOT have fixed the
screen. `sys/lib/ape/termcap`'s whole `dumb` entry is
`:am:co#80:li#24:` -- **no `ce`, no `up`, no `cm`**, so readline
reprints instead of redrawing, and `terminal.c:584` forces
`_rl_term_isansi = 0` for that name. vts is what makes a real `$TERM`
honest, since the engine is **libvterm** (upstream's full state
machine) and the termcap already ships `vt100|vt100-am` and `xterm`.
Which VT level is claimed is not the question; having anything true to
claim is. **Order**: bash on a `cons` not a pipe, per-session
`consctl`, then `$TERM` (the one that changes the screen), then the
real grid size, then `COLUMNS`/`LINES` at spawn plus a note on resize.


---

## The keystroke thief, kencc's `false`, and the output half

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

**THE COPY PROCESS IS A KEYSTROKE THIEF -- CONFIRMED, AND THE
PARTITION IS EXACT.** `echo $SHELL` typed into vtwin: vts received
`e c h $ S L`, and after `kill vtwin | rc` the launching bash's prompt
read `o HEL`. **Six plus five is eleven, nothing duplicated, nothing
lost** -- the two readers *partition* the input, which only two
processes blocked on one file can do. `ps` shows four `bash` in
**`Pread`** (a copy process inside `_READ`) beside their parents in
`Rendez`; only one pair is legitimate and **two are leftovers from
earlier runs**, which is the `bash`-as-`/bin/sh` accumulation seen
from the other side. Cause: **libap's `select()` does not poll, it
forks a process that reads CONTINUOUSLY for the life of the caller**,
so an interactive bash permanently reads its window's `/dev/cons`.
**Workaround shipped: `./apexp-sh -r`** runs the same environment with
**rc** as the launching shell -- no `select()`, no copy process, no
competition -- while `$SHELL` stays `bash` so the session still runs
bash. **FIXED AND CONFIRMED** -- all eleven bytes of `echo $SHELL` show
`cons write -> HANDED -> tty write`, bash ran it and printed `bash`,
and **the outer prompt is EMPTY**: no theft at all, on a test that
conserves bytes so a partial fix would have shown as a shorter theft.
`Muxbuf` gains `ondemand`/`want`/
`readwait`, **appended after `data[]`** so no existing offset moves
(but `sizeof` does -- **`mk distclean` first**), and for `FD_ISTTY`
only the copy process sleeps unless `want` is set, clearing it on
delivery. One outstanding read per request instead of one for ever;
pipes and sockets keep the greedy path Tcl exercises. **`want` is
STATE, tested under `mux->lock`**, so a request arriving while the
copy process is between its unlock and its rendezvous is seen rather
than lost -- there is no window to miss. The "both asleep" deadlock is
prevented identically at all three asking sites: set `want` under the
lock, clear `readwait` under the same lock, release, wake, *then*
wait. `select()` asks **before `waitfresh`**, which would otherwise
spin against a deliberately sleeping copy process. `_bufmark()` is the
marker. **The regression test is the partition**: `echo $SHELL` into
vtwin, `kill vtwin | rc`, and the outer bash's prompt must be EMPTY --
it conserves bytes, so a partial fix shows as a shorter theft rather
than a pass. **It passed on the first run.** **`execve` killing copy processes is a separate smaller
fix that does NOT cure this** -- the thief is a living parent.
**And a win: ARROW KEYS WORK under vtwin**, which rio could never give
-- one of the three things vts was for.

**What is left in vts is the OUTPUT half, and it is isolated**: vts
receives `<1b>[?2004h` whole and the screen shows `2004h` as text --
proved arithmetically, since `ctl` said `cursor=1,60` and 53+5+2 = 60.
**My kencc hypothesis is REFUTED** -- `bool in_esc : 1` being a
one-bit field that takes a 1 and ignores a 0. `bitfield-test.c`
**section 10** passes on 9front: bool holds true, clears to false,
clears when assigned `0`, and the `unsigned : 1` beside it does the
same. **The caveat closes too**: APE's `<stdbool.h>` does NOT redefine
`bool` (it is kencc's own keyword, an `unsigned char`) and `pcc` IS
`6c` with APE flags, so the test measured the same type and compiler
libvterm uses. *The branch was written down beforehand and cost one
30-second command.* **What did the work was the `unsigned : 1` beside
it** -- both failing would have meant clearing in general, bool alone
failing the base type; both passing is informative only because they
were asked together.
**FOUND, AND IT IS `false` ITSELF: kencc's C23 `false` keyword did
not evaluate to 0.** `itab` in `cc/lex.c` is
`{char *name; ushort lexical; ushort type;}` -- the third column is a
**type index** applied by `lexinit()` as `s->type = types[...]` -- and
`true`/`false` were written into it as `1` and `0` as though it were a
value. Nothing set **`yylval.vval`**, which is what the grammar reads
for `LCONST` (`cc.y`: `$$->vconst = $1`), and `yylex` had already done
`yylval.sym = s` into the same union member. **So both keywords
arrived carrying a pointer.** Fixed in `yylex`, which now supplies the
value on the `LCONST` arm; the table entries are 0/0 with a note
saying why a value cannot live there.
**FIX CONFIRMED on the rebuilt compilers**: `truefalse-test` reports
**0 failures**, 8 of 8, and the two that carry the finding are
**section 3** (`bool:1 = false clears, straight after = true`) beside
**section 4** (`= 0`, the control). Section 4 passed before the fix
too -- *both passing in one run is what separates a fixed keyword
from a working bit field*, and either alone would have been the
"two explanations" trap again. Still to measure: libvterm rebuilt
with this compiler, which is what `vtparse-probe` asks.
**Not bit-field-specific and not libvterm-specific**: every
`x = false`, `return true;` and `flag == false` in every **native**
C23 program had the same junk. **APE code was untouched** because
APE's `<stdbool.h>` `#define`s them to 1 and 0 -- *which is exactly
why no test under `sys/lib/tests` could catch it*, and why
`truefalse-test.c` is native.
**It cost two refuted hypotheses**, a bit-field overlap and a
bit-field clear bug, and **both passed their tests because the tests
were APE, where `false` is a macro** -- `bitfield-test`'s two "clear"
checks were literally the same line twice after preprocessing.
`vtlayout-probe` named it by asking `= 0` and `= false` side by side
on the real struct in the native dialect: `= 0` cleared, `= false`
did not, and the hex dump showed `state` at offset 0 and `in_esc` at
offset 4 with no overlap at all.

**`vtparse-probe` CLEARED vts and named the byte**: libvterm prints
it with no vts, no 9P and no terminal involved. **And its table of
nine sequences says the shape exactly -- EVERY CSI consumes exactly
THREE bytes and prints the rest** (`ESC [ 2 J` -> `J`, `ESC [ ? h` ->
`h`, `ESC [ ? 2004 h` -> `2004h`). `ESC [ H` is clean only because it
*is* three bytes; *the information was in the arithmetic across rows,
not in any one row*.
**One mechanism fits all seven with no slack**: libvterm holds
`enum {...} state;` immediately followed by `bool in_esc : 1`, and if
a store to `state` sets the `in_esc` bit, then `ENTER_STATE(CSI_LEADER)`
(== 1) lights `in_esc`, the next byte takes the escape path instead of
the CSI path, resets state to NORMAL, and everything after is text.
`ESC [ H` survives because `H` is 0x48 and hoists to a C1 control.
**`bitfield-test.c` section 10 HAD that struct and still missed it**,
because it only ever wrote the bit field and read the neighbour -- an
overlap is symmetric, and testing one direction is the
"two explanations" trap one level up. The missing direction is added:
write the enum, read the bit back, both polarities, both field types,
with `sizeof` printed. Passes on gcc at 12 bytes.
**AND IT IS CLOSED: `0 of 9 unexpected`, `CONSUMED`, on the rebuilt
compiler.** All eight prefixes give 0 chars, every CSI row is empty,
and the `hi` control still prints -- exactly the prediction, written
down before the run. libvterm's source did not change a character;
only `cc/lex.c` did. *The chain is measured end to end: fixed
keyword -> `in_esc = false` clears -> the parser stays in CSI ->
`ESC [ ? 2004 h` is swallowed whole.*
**The probe's own closing text had to be corrected**, and that is
worth more than the result. It said *"the fault is NOT in libvterm"*
on a clean run -- true as a branch written while libvterm was
suspected, false now, because the run came back clean for the OTHER
reason: libvterm was recompiled. **A clean run of this probe is
ambiguous from here on** -- it clears the libvterm in front of it,
built by the compiler in front of it, and a stale `libvterm.a` or a
vts still linked against one reads identically. So a clean table
beside a dirty screen is a BUILD question before it is a vts
question. *An instrument that bakes in the conclusion for a branch
keeps asserting it after the branch stops being the live one.* (The far-right
indentation is separate and mine: `session.c`'s child prints with `
`
and no `
` into a raw console.)

**THE SCREEN IS CLEAN: `2004h` IS GONE AND THE WHOLE CHAIN IS
MEASURED.** A session shows a bare `$` prompt, `echo $SHELL` answers
`bash`, `echo $TERM` answers **`vt100`**. So: fixed `false` ->
`in_esc = false` clears -> the parser stays in CSI -> vts consumes the
bracketed-paste sequence instead of printing it.
**Two things in that run were better than what was asked for.**
*`$TERM` is already `vt100`*, not `dumb` -- vts sets it, so the item
listed as "next" was done, the termcap entry with `ce`/`up`/`cm` is in
play and readline is redrawing rather than reprinting. And *the run
was from a PLAIN `apexp-sh`, not `-r`* -- which is a better control
than the one I proposed, since `-r` existed to dodge the copy-process
thief and running without it exercises the `want` fix in the exact
configuration that used to fail. **`-r` is a fallback now, not the
recommended path**, and it is kept for one good reason: if input ever
goes missing again, "-r works and plain apexp-sh does not" splits the
copy process from every other explanation in one command.
**And the far-right staircase was `\n` into a VT, as recorded** --
fixed at last: `session.c`'s child now writes `\r\n` for the three
messages printed AFTER the dup that makes fd 2 the session terminal,
and `\n` for the ones before it, which go to the launching rio
window. *The boundary is the `dup()`, not the file* -- the same
fprint is correct above it and wrong below. Fourth time an instrument
or a diagnostic has been the visible fault in this area.

**AND THEN `ls` STAIRCASED, WHICH IS THE SAME BUG ONE LAYER OUT.**
Fixing `session.c`'s own `fprint`s fixed only vts's own messages;
every *program* ending a line with `\n` still walked down and to the
right, and `ls` was unreadable. **On a unix the TTY DRIVER does this
translation** -- `OPOST|ONLCR` -- and the terminal never sees a bare
LF. Plan 9 has no output post-processing, and libap's termios has
nowhere to put `ONLCR`: `/dev/cons` offers one switch, `rawon`/
`rawoff`. **vts is the driver here as well as the terminal**, so the
translation belongs on its side, and the terminal already has the
mechanism -- **LNM** (ANSI X3.4-1977), set at `engine_init` by
feeding `ESC [ 20 h` through upstream's own parser, since `set_mode`
is static and there is no public setter.
**Safe for a MEASURED reason, not an assumed one.** On a real DEC
terminal LNM is symmetric -- it changes what RETURN sends, so a shell
would read CR LF for one keypress. **In this libvterm it is not**:
`state->mode.newline` is read in exactly one place, the LF arm at
`state.c:471`, and nothing in the key path reads it. *That was
checked before relying on it, because the failure it would have
caused looks nothing like the one being fixed.* A program emitting
`\r\n` itself gets CR twice, which is idempotent.
**CONFIRMED**: clean columns, every line at the left margin, prompt
at column 0, `ls` readable. **And the refutation condition answered
too** -- four commands ran in that session, each producing one line,
so Enter did not double. That is what would have fired had LNM been
symmetric here, and it confirms the reading of `state.c` rather than
only the fix.
**The width did not need fixing after all, at that window size**:
`ls` columnated correctly. The hardcoded `session_init(s, name, 24,
80)` is still a hardcode and still wrong for a window that is not
80 wide -- but it is now the only thing left on the vts list, and it
is a feature rather than a bug to chase.

**AND THE SESSION NOW WORKS**: `tty read: blocked (1 waiting)`,
`read: enter fd=0 n=1`, `-> buffered n=1`, then `tty write 1 [c]` --
bash waits for a keystroke, gets it and echoes it, with `flags=38`
(`FD_ISOPEN|FD_BUFFERED|FD_ISTTY`) where the failing run had `0x2A`.
**The diagonal text on screen was the INSTRUMENT, for the third
time**: `_apdbg` ended lines with `
` and no `
`, and since
`tcsetattr` started working fd 2 is a RAW terminal, where `
` keeps
its column -- a staircase that looked exactly like a VT bug. It writes
`
` now. Two noise fixes with it: `$APEXP_DEBUG` reaches the shell
only at `$vtsdebug=2` (its lines land on the session's own SCREEN,
where vts's own trace goes to a log file), and `close of a descriptor
with no listener` -- which fired on every close in every program and
said nothing -- is under `$APEXP_LISTENDEBUG` alone. *An instrument
sized for a dead shell is the wrong size for a live one.*

**readline wraps at 80 columns under rio, and the mechanism is already
there.** `READLINE` being on means bash redraws the line, and a long
command wraps in the wrong place. libap **already** answers
`TIOCGWINSZ` (`misc/ioctl.c`) correctly: 80x24 by default, overridden
by **`$COLUMNS`**/**`$LINES`**. Nothing under rio sets either.
`export COLUMNS=<real width>` fixes it and stays fixed -- bash's
`checkwinsize` re-asks through the same ioctl, which reads the variable
bash exported, so the two agree rather than fight.
**There is no better answer under rio, and that is about rio**: a
window is a pixel rectangle, the font is proportional, there is no
character grid to ask and no `SIGWINCH` on resize. **It joins arrow
keys and colour on the list of what `vts` would buy, and it is the
strongest of the three** -- vts keeps a real character grid
(`cells.c`), so it knows the answer exactly and can set `$COLUMNS` per
session.
