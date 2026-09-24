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

## Running it: `./vts-bash`, from inside `apexp-sh`

`vts-bash` at the repo root starts vts and a vtwin window. **It must be
run from inside `apexp-sh`**, and that is the mechanism rather than a
convenience -- three things `apexp-sh` does are load-bearing:

```
bind -b $cputype/bin /bin        vts, vtwin, vts-attach get on the path
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
