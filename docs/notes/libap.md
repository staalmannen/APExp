# libap: patch history

Split out of `CLAUDE.md` (2026-09). Per-directory history of
`sys/src/ape/lib/ap/` -- locale, math, malloc, thread, signal, process, aio.
The `select()`/`_buf.c` work lives in `tcl-suite.md`, because that is where it
was found.

Cross-references to "the section above" or "below" may now point into a
sibling file under `docs/notes/`; `CLAUDE.md` has the index.

---

## libap Patch History

### locale/ — simplified for Plan9's single UTF-8 locale

Replaced complex musl locale machinery with Plan9-appropriate stubs:
- `locale_stubs.c`: replaces `setlocale.c`, `uselocale.c`, `newlocale.c`, `locale_map.c`
  — no `libc.global_locale` or pthread->locale references
- `dcngettext.c`: stub — always returns untranslated string
- `localeconv.c`: positional initializers (no designated initializers at file scope)
- `locale.h`: added 6 C99 `int_p_*`/`int_n_*` members to `struct lconv`

#### setlocale must report the locale it set, even when there is only one

Plan 9 has one locale, so `setlocale` changes no behaviour whatever it
is asked for. Keeping the **names** straight is a separate contract, and
the one callers actually test — C99 7.11.1.1p8 makes the return value a
string associated with the locale now in effect for that category, which
a later call can use to restore it.

`locale_stubs.c` used to ignore `name` entirely and answer `"C.UTF-8"`
to every set and every query. perl says so out loud:

```
locale.c: 3441: panic: Can't change locale for LC_NUMERIC (4)
  from 'C.UTF-8' to 'C'
```

That is `Perl_set_numeric_standard`, which pins LC_NUMERIC to `"C"` so
the radix character stays a dot whatever LC_CTYPE is doing — exactly the
case where one category's name must differ from the others, and exactly
what "everything is C.UTF-8" cannot express. miniperl died before
running a line of perl.

Now each category remembers the name it was last set to, a query returns
that name, and a set returns the name just stored. `""` resolves through
`LC_ALL`, the category's own variable and `LANG` (POSIX XBD 8.2), and
with none set gives C.UTF-8 — UTF-8 is Plan 9's native encoding, and the
native locale is what 7.11.1.1p3 leaves to the implementation. The
initial value is `"C"`, as 7.11.1.1p4 requires.

`setlocale(LC_ALL, NULL)` returns the bare name while every category
agrees, as glibc does, so the common case stays something a caller can
hand straight back; a mixture — which perl reaches the moment it pins
LC_NUMERIC — gives the `LC_CTYPE=x;LC_NUMERIC=y;...` composite. Setting
LC_ALL accepts that form **and** musl's bare `x;y;...`, because p8
requires whatever a query returned to be settable.

Note `LOCALE_NAME_MAX` is musl's, in `locale_impl.h` (23, the name field
in `struct __locale_map`); the limit for names kept here is `LCNAMEMAX`.

Covered by `sys/lib/tests/locale-test.c`. Every case in it is required
of any conforming `setlocale`, so it passes on glibc, which is how it
and the implementation were both checked.

### math/ — sin, cos and tan were Plan 9's, and cos(0) was not 1

`sin.c` was Plan 9's libc: a Hart & Cheney rational approximation from
1980 with a crude argument reduction, defining `sin` **and** `cos`.
Every musl helper it should have been using was already in the tree and
unreachable -- `__sin.c`, `__cos.c`, `__tan.c`, `__rem_pio2.c`,
`__rem_pio2_large.c`, and musl's own `sincos.c` -- because only the
double `sin`/`cos`/`tan` entry points were missing. They are musl's now.

It was wrong in two separate ways.

**It never returned exactly 1 for cos(0).** Plan 9's `cos` is
`sinus(x, 1)`, which shifts the quadrant and evaluates the polynomial at
the *end* of its interval instead of taking a shortcut for a tiny
argument:

```
cos(0.0) = 0.99999999999999956
```

Two ulp, and invisible in almost everything. Tk's canvas rotates every
text item by its `-angle` with

```c
Tk_PointToChar(layout, (int)(x*cs - y*s), (int)(y*cs + x*s));
```

and for an unrotated item `cs` is `cos(0)`. `(int)(12 * 0.999...956)` is
**11**, so `canvas index @x,y` was one pixel out everywhere and
`font-28.*`/`font-30.*` asked which character sat at the start of line 2
and were told line 1 -- 13 tests. **An exactness bug is not a rounding
bug**: truncation turns 2 ulp into a whole pixel, and that is the shape
to expect when a tiny error has a visible effect.

**The argument reduction fell apart away from zero**, which is the more
serious half. Against glibc:

| x | cos error, old | new |
|---|---|---|
| pi/2 | 5e15 ulp | 0 |
| 100 | 44 ulp | 0 |
| 1e6 | 162415 ulp | 0 |
| 1e15 | 4e14 ulp | 1 |

`cos(1e6)` had five wrong decimal digits and `cos(1e15)` no correct ones,
because the reduction was done in double alone (`x > 32764` fell back to
two `modf` calls). Anything doing trigonometry on a large angle -- a plot
axis, an accumulated phase, a time in seconds -- was quietly getting
noise. **Anything that called sin, cos or tan and was built before this
is suspect**, the same warning as the 6c spill and the `bool` fix.

Covered by `sys/lib/tests/sincos-test.c`. Every case in it is required of
any conforming libm, so it passes on glibc -- which is how both it and
the replacement were checked, by building the new files on the host and
diffing them against glibc ulp for ulp.

**The inverse functions were worse, and are musl's now too.** Measuring
the whole directory the same way -- building each file on the host and
diffing against glibc over its domain -- gave:

| | old | new |
|---|---|---|
| `atan` | 1.4e11 ulp | 1 |
| `acos` | 3029 ulp | 1 |
| `asin` | 12 ulp | 1 |

`atan(-1.02)` had six correct digits. `asin.c` defined `acos` as well,
which is why both moved together.

**`atan2` stays Plan 9's**, and deliberately: it only works out the
quadrant and calls `atan`, so with the new `atan` under it it measures
1 ulp. A musl `atan2` written for it measured worse and was dropped --
see the harness note below.

**exp, log, log2, log10 and pow are musl's now too**, which finishes the
elementary functions:

| | old | new |
|---|---|---|
| `exp` | 430 ulp near \|x\|=700 | 1 |
| `log` | 1 ulp | 0 |
| `log2` | 2 ulp, **not exact** | 1 |
| `log10` | 2 ulp, **not exact** | 1 |
| `pow` | 6 ulp | 1 |

`log` was already respectable; the reason to move it is the pair beside
it. `log2(8)` was 2.9999999999999996 and `log10(100)` 1.9999999999999998,
so **`(int)log2(8)` was 2** -- the same truncation trap as `cos(0)`, and
the one bug in the family that changes control flow rather than a last
digit. Plan 9's `log.c` defined all three, so they moved together.

These are ARM's optimized-routines, table-driven, and the tables
(`exp_data.c`, `log_data.c`, `log2_data.c`, `pow_data.c`) were **already
in the tree and already in the mkfile** -- compiled and unreferenced,
because only the double entry points had ever been written. They could
not have worked before the `hexfloat()` fix in any case: the tables are
nothing but hex floating constants, and every one was zero.

Covered by `sys/lib/tests/explog-test.c`.

**What is still Plan 9's, with its measured error**, so the next person
knows where to look rather than re-deriving it:

| | max error vs glibc | note |
|---|---|---|
| `erfc` | 4e6 ulp | far tail only, value ~1e-17 |
| `tanh` | 4 ulp | |
| `erf`, `sinh` | 2-3 ulp | |
| `gamma` (lgamma) | 1931 ulp near its zero | ulp is a poor measure at a zero crossing; not re-checked |
| `sqrt`, `hypot`, `atan2`, `fmod` | 1-2 ulp | fine |

**Measure before replacing, and give the harness a prototype.** Building
these on the host against glibc is what settled every one of the numbers
above, and it twice reported a function as catastrophically broken when
the fault was the harness: renaming `atan` to `n_atan` with a `#define`
placed *after* `<math.h>` leaves the call inside `atan2.c` with **no
prototype in scope**, so it returns `int`. That is the same trap as
`sizeof` and the variadic sentinel above, met from the other side -- and
it nearly cost a good `atan2` on both sides of the comparison.

### math/ — missing declarations added to math.h

30+ C99 functions were in `libap.a` (from musl) but undeclared in `math.h`.
Without declarations, kencc gives them implicit `int` return type, silently
truncating floating-point results. All added to `sys/include/ape/math.h`.

Key missing functions: `acosh`, `asinh`, `atanh`, `cbrt`, `copysign`, `exp2`,
`expm1`, `fma`, `fmax`, `fdim`, `lgamma`, `tgamma`, `nearbyint`, `rint`,
`round`, `trunc`, `remainder`, `scalbn`, `scalbln`, `nextafter`, etc.

### tgmath.h — new file

`sys/include/ape/tgmath.h` uses `_Generic` to dispatch to correct variant.
Helper macros use parameter name `fn` (not `f`) to avoid token-paste collision:
`f##f` with param `f` would paste param with param → `acosacos`, not `acosf`.
With `fn`: `fn##f` → `acosf`. ✓

### malloc/ — aligned allocation

Three files ported from musl to work with APE's `malloc`/`free` internals:
- `reallocarray.c`: overflow-checked `realloc(ptr, m*n)`
- `aligned_alloc.c`: retry loop (≤8 tries) to get naturally-aligned malloc pointer;
  falls back to unsafe over-allocate for alignment > 16 (with free() caveat)
- `memalign.c`: wrapper over `aligned_alloc`

**APE malloc constraint:** `free()` computes `bp = ptr - datoff` and checks
`bp->magic == MAGIC`. So the returned pointer MUST be exactly the value
malloc() returned. Adjusted pointers (ptr + offset) will abort in free().

### thread/ — pthread_cond_timedwait

New file `sys/src/ape/lib/ap/thread/cond_timedwait.c`.

Plan9's `rsleep()` uses `rendezvous()` which has no timeout. Implementation
uses a **timer thread**: spawns a detached thread that `nanosleep(remaining)`
then calls `pthread_cond_signal()`. Waiter calls `pthread_cond_wait()` then
checks `clock_gettime()` to determine if timeout elapsed.

`pthread.h`: replaced `#define pthread_cond_timedwait(x,y,z) pthread_cond_wait(x,y)`
with proper `extern` declaration.

**Note:** `ts` parameter to `pthread_cond_timedwait` is **absolute** CLOCK_REALTIME
time (POSIX). `aio_suspend`'s `ts` is **relative** — convert before calling timedwait.

### signal/ — sigset_t held only three signals

`ap/signal/sigset.c` gated every operation on

```c
static sigset_t stdsigs = SIGHUP|SIGINT|SIGQUIT|...|SIGUSR2;
```

which ORs the signal **numbers** together, not their bits: `1|2|3|…|13` is
15. `sigaddset`/`sigdelset`/`sigismember` all tested `BITSIG(signo)` (i.e.
`2<<signo`) against that, so only signals 0, 1 and 2 were accepted — everything
else returned `-1`/`EINVAL` and changed nothing, and `sigfillset()` produced a
set naming SIGHUP and SIGINT alone.

Silent, because almost nothing checks `sigaddset`'s return value: the caller
just got an empty mask and blocked nothing. Fixed to accept every signal in
`signal.h` (1..NSIG-1). `_psigblocked` is the only sigset the rest of libap
keeps, and it is only saved and restored (`sigprocmask`, `notetramp`) — never
tested against a signal number — so no stored set changed meaning.
Covered by `sys/lib/tests/sigset-test.c`. Found via
`posix_spawnattr_setsigdefault`, whose test put SIGTERM (11) in a set and got
an empty one back.

### process/ — execvp searches PATH

`execvp`, `execvpe` and `execlp` each carried

```
BUG: instead of looking at PATH env variable,
just try prepending /bin/ if name fails...
```

Fine while everything is in `/bin`; wrong under APExp, where the APE binaries
live in `/$objtype/bin/ape` and are reached through PATH. Every coreutils
program that ends in `execvp()` — `env`, `nohup`, `timeout`, `chroot`,
`stdbuf` — could therefore only run things in `/bin`.

New `ap/process/execpath.c` holds `_execpath()`, shared by all three: a name
containing `/` is used as given, otherwise each PATH element is tried
(empty element = cwd), and the reported errno is EACCES if some candidate
existed but could not be run, else ENOENT. `/bin` is the fallback when PATH
is unset, and is also tried last, so nothing that worked before stops.

Each candidate is `access(X_OK)`-checked before exec is attempted, because in
APE **a failed `execve()` is not free**: it has already done
`_RFORK(RFCENVG)`, rewritten `/env/_fdinfo` and `/env/_sighdlr`, and closed
every `FD_CLOEXEC` descriptor by the time the exec itself is tried. Which is
also why `posix_spawn` cannot report exec failures in the parent — its
close-on-exec report pipe is gone before exec is attempted, so an exec failure
surfaces only as the child exiting 127. POSIX leaves that unspecified;
glibc reports it, APE does not.

### termios/ — tcsetattr said "done" and did nothing

The single reason bash's tab completion has never worked under APE,
and it is this tree's most common bug shape rather than anything
exotic. `termios/tcgetattr.c`, handed a real `/dev/cons`:

	int
	tcsetattr(int fd, int optional_actions, const struct termios *t)
	{
		if(!isptty(fd)) {
			if(!isatty(fd)) { errno = ENOTTY; return -1; }
			else return 0;        /* <- and nothing else */
		}
		...

It reported success and changed nothing. `tcgetattr` was the matching
half: for a tty it returned a hardcoded
`c_lflag = ISIG|ICANON|ECHO|ECHOE|ECHOK` whatever the console was
actually doing, described in its own comment as "sensible defaults".

**So readline's sequence could not work and could not fail visibly.**
It reads the state, clears `ICANON` and `ECHO`, calls `tcsetattr`, is
told it worked — and the Plan 9 console driver carries on assembling
lines. Tab arrives as a byte inside a finished line, which is far too
late to complete anything. Every part of that is silent.

*A stub that answers "failure" is not the same as one that answers
"nothing to do"* — and neither is the same as one that answers "done".
Same family as `shutdown()`, `wm title`, `TkUnixSetMenubar`.

**Plan 9 has the switch, and libap was already using it.**
`/dev/consctl` takes `rawon` and `rawoff`, and `plan9/tty.c` had been
writing them for `getpass()` since for ever. What it does not have is
per-flag control: raw stops echo AND line assembly together, it is
namespace-wide rather than per descriptor, and **the descriptor has to
stay open** — the console reverts when the last consctl descriptor
closes.

**One owner, because two would have fought.** `tty.c` now holds the
state and both callers go through it. Two files each keeping their own
consctl descriptor would have raced: whichever closed last would drop
the console back to cooked under the other one.

- `_tty_raw(on)` is absolute and returns the **previous** state, or -1.
  Asking for the state it is already in does not touch consctl and is
  not a failure.
- `_tty_israw()` reports what **this process** has set. `/dev/consctl`
  is write-only, so there is no way to ask the console; a console left
  raw by another process reads as cooked here, and a fresh `exec`
  starts out believing cooked. Said plainly rather than papered over,
  since pretending to report the console is the failure being undone.
- The descriptor is opened `O_CLOEXEC`, so a child started by a shell
  in raw mode does not inherit a consctl it knows nothing about. The
  parent keeps its own, so the shell stays raw.

`getpass()` now **saves and restores** instead of "off then on". The
old `tty_echoon()` cooked the console unconditionally, which would
have quietly ended a caller's raw mode the first time anything asked
for a password.

`tcsetattr` reduces the request to that one bit: **raw if either
`ICANON` or `ECHO` is being cleared.** When only `ECHO` is wanted off —
a password prompt asking for cooked input with no echo — raw is the
closer of the two available answers, because echoing a password is the
worse failure. `VMIN`/`VTIME` have no equivalent and are ignored; raw
delivers each byte as it arrives, which is `VMIN=1 VTIME=0`.

**Two tests, and they ask different things.**
`sys/lib/tests/rawmode-test.c` runs on 9front and asks the real
question: set raw, then **read the state back** and check the bits
asked for are clear. Not "did tcsetattr return 0" — the broken version
returned 0 too, which is exactly how this survived. Its section 5 is
the end-to-end proof (a keystroke arriving before Enter) and needs a
human, so it sits behind `$APEXP_RAWTEST_KEYS`; sections 3 and 4
separate the fixed library from the old one with no keystrokes at all.

`sys/lib/tests/tty-xcheck.c` is a **host** program in the `*-xcheck`
family: it links `tty.c` with counting fakes for open/write/close and
asserts the contract — that a redundant request is nothing-to-do
rather than failure, that the return value is the previous state, that
a consctl which will not open leaves the state cooked rather than
half-set, and that the cooked path *closes* the descriptor. None of
those is comfortable to provoke on a live console. It needs
`-I ttystub`, two three-line headers, because the real `lib.h` has no
include guard and pulls `<ureg.h>`.

**What this opens, and what it does not.** readline emits VT100 cursor
and erase sequences, so raw mode alone is not a terminal — it wants an
emulator and a termcap entry (`sys/lib/ape/termcap` is present). The
deeper limit is unchanged: **Plan 9 has no PTYs**, so `tcsetpgrp`,
job control and a controlling terminal stay out of reach, and
`vts`'s own man page lists the same gap.

### process/ — a failed execve destroyed the caller

POSIX is unusually blunt about this: *"If the exec function returns to
the calling process image, an error has occurred; ... the process image
is unchanged."* libap's `execve` did the opposite. Before `_EXEC` was so
much as attempted it had

- run `_RFORK(RFCENVG)`, which creates an **empty** environment group
  (the `C` is *clear*; `RFENVG` is the one that copies), so the caller
  had no environment left;
- rewritten `/env/_fdinfo` and `/env/_sighdlr`;
- **closed every `FD_CLOEXEC` descriptor**, zeroing its `_fdinfo` entry.

None of that can be undone, so a caller that got control back was a
different process from the one that made the call.

**What it cost: Tcl's `exec-10.20.1` and `exec-10.21.1`.**

	exec ~non_existent_user/foo/bar
	  wanted: couldn't execute "~non_existent_user/foo/bar":
		  no such file or directory
	  got:    TclpCreateProcess: unable to write to errPipeOut

`TclpCreateProcess` forks, execs, and on failure writes the reason down
an error pipe for the parent. That pipe is close-on-exec **because its
closing is how the parent tells a successful exec from a failed one** --
EOF means the exec took. So libap had already closed it, the child's
`write` got EBADF, and `Tcl_Panic` fired. The actual error, which is the
only thing the test is asking about, was never sent.

**The fix is a preflight.** `execve` now opens the file with `OEXEC`
before touching anything, and returns `-1` with that errno if the open
fails. This is the same question Plan 9's own exec asks -- `namec(file,
Aopen, OEXEC, 0)` -- of the same namespace, so a missing file, a
directory, a file without execute permission and an unreachable path all
fail here for free. The `FD_CLOEXEC` closes also moved from the first
loop to immediately before `_EXEC`: they cannot be avoided (Plan 9 has
no close-on-exec for a descriptor not opened `OCEXEC`, and
`fcntl(F_SETFD)` cannot add it afterwards), so the only thing available
is to do them as late as possible.

**Not a guarantee, and worth saying rather than implying.** An exec can
still fail *after* a successful open -- a bad binary format, or the file
changing underneath -- and that case is exactly as destructive as the
whole function used to be. What the preflight buys is that the
overwhelmingly common failure, "no such file", is free.

**`_execpath` already did this and it was not enough**, which is the
part worth remembering. It checks each PATH candidate with
`access(X_OK)` before exec'ing it, and its comment said why. But it only
checks *when it searches*: a name containing `/` is used as given, with
no search and no check -- and `~non_existent_user/foo/bar` is such a
name. A guard placed at the call site covers the call sites it knows
about.

`sys/lib/tests/execfail-test.c` asks all of it without Tcl in the way.
**Section 5 is the control and is not optional**: "stop closing
close-on-exec descriptors" passes every other section and breaks
`FD_CLOEXEC` for every program in the tree, Tcl included -- its parent
would wait for an EOF that never came. It checks a *successful* exec
still closes them, through the same pipe-EOF mechanism Tcl uses.
`_execmark()` is the library version marker, the same idiom as
`_sock_listenmark()` and for the same reason: `pcc -o x x.c` links
against the installed library, so the test declares it `extern` and an
old libap fails to **link** rather than passing quietly.

### fcntl/, unistd/ — O_APPEND is not atomic, and cannot be

Tcl's `exec-19.1` appends to one file from four shells at once and
checks the size. It wants 26 and gets 24. Its own comment says what it
is for: *"Check that no bytes have got lost through mixups with
overlapping appends."*

**Plan 9 has no `O_APPEND`.** 9P's `Twrite` carries an explicit offset;
there is no write-at-the-end request for an ordinary file. libap
emulates it with `_SEEK(fd, 0, 2)` in `fcntl/open.c` once at open, and
again in `unistd/write.c` before every write. That is **two calls with a
window between them**, so two processes can both seek to N and both
write at N. `exec-19.1` puts a `sleep 1` between echoes, which makes
four shells wake on the same second boundary -- the collision is the
thing it is provoking.

**The size alone cannot say which bug it is**, which is why
`sys/lib/tests/append-test.c` exists rather than a second reading of the
test: 24 is equally consistent with the file being truncated at open
(losing the two seeded bytes) and with one two-byte `echo` being lost.
Sections 2 and 3 ask those separately, and section 3 uses 256 rounds
rather than three, because a clean run with a handful of writes means
"they never overlapped" just as readily as "they cannot overlap" -- *a
negative result with two explanations is not a result.*

**Not fixed, and deliberately.** Plan 9's one atomic append is
`DMAPPEND`, a permanent mode bit on the **file**. Setting it would change
that file for every other program and every later open, which is not
what `O_APPEND` means for a descriptor. This is the same shape as
`symlink()`: do not invent semantics to make a test pass.

### process/ — posix_spawn honours file actions

`sys/src/ape/lib/ap/process/posix_spawn.c` was fork+exec with every file
action and attribute discarded — `posix_spawn_file_actions_adddup2()` and
friends returned 0 and did nothing, so the child just inherited the parent's
descriptors. Undetectable by the caller: gnulib's `spawn-pipe.c` wires its
pipe to the child purely through `adddup2`, and would have got a child on the
wrong fds with no error anywhere.

Now: actions are recorded in a growable array hung off
`posix_spawn_file_actions_t.__actions`, replayed in the child between fork
and exec, with `SETSID`/`SETPGROUP`/`SETSIGDEF`/`SETSIGMASK` applied first.
Setup failures come back to the caller as the return value through a
close-on-exec report pipe. `RESETIDS` and the scheduling flags are stored and
returned faithfully but ignored — Plan 9 has no POSIX scheduler.

The old file declared its own `typedef void posix_spawnattr_t;` rather than
including `<spawn.h>`; it worked only because every use was through a
pointer. Covered by `sys/lib/tests/posix-spawn-test.c`.

Missing before, and the reason gnulib's own spawn replacement got pulled in:
`posix_spawnattr_setsigdefault`/`getsigdefault`, `setpgroup`/`getpgroup`,
`setschedparam`/`setschedpolicy` and their getters were declared in
`spawn.h` but undefined in libap. **Do not build gnulib's `spawn*.c` into the
shared archive** — gnulib's `posix_spawnattr_t` has glibc's `_sd`/`_ss`
members and does not compile against APE's `<spawn.h>`.

`execute.c` and `spawn-pipe.c` *are* built, and are the reason libap's
implementation has to be real rather than a stub: bison and m4 both link the
shared `libgnu.a` rather than a `lib/` of their own (`libbison.a` is two
objects, `main` and `yyerror`), and they reach `create_pipe_bidi` and
`execute`, which wire up a child entirely through file actions.

### aio/ — async I/O on pthreads

`sys/src/ape/lib/ap/aio/aio.c` — complete rewrite from Copilot-generated stub.

Bugs fixed vs original:
- `aio_suspend` deadlocked (waited on local cond never signalled by worker)
- `pthread_cond_timedwait` timeout was ignored (now properly used)
- `aio_fsync` was a NOP (now calls real `fsync(2)`)
- `aio_cancel` was missing (now implemented)
- Worker thread not detached (now created PTHREAD_CREATE_DETACHED)
- Missing `#include <pthread.h>`

`aio_suspend` relative→absolute conversion:
```c
clock_gettime(CLOCK_REALTIME, &deadline);
deadline.tv_sec  += ts->tv_sec;
deadline.tv_nsec += ts->tv_nsec;
if(deadline.tv_nsec >= 1000000000L) { deadline.tv_sec++; deadline.tv_nsec -= 1000000000L; }
```

#### Gay's strtod, round two: four bugs, three of them in the shared kit

`string/strtod-gay.c` is a correctly-rounded `strtod` on the Bigint kit
in `stdio/_fconv.c`. **Still not in any mkfile.** Section 1 of
`strtod-xcheck` -- the seven strings Tcl's `expr` tests use, including
DBL_MAX, the value one ulp past it, and an 18-digit case -- is now
**7 of 7 exact**, where the shipping file gets 0 of 7. Section 2, the
200000 round-trips, is not clean and the reason is no longer arithmetic.

**Three of the four bugs were not in the new file at all, and all three
are one assumption**: Gay's code needs a 32-bit word and spells it
`long`, which is true under kencc and false under every LP64 compiler
-- so the kit was correct on Plan 9 *by accident* and wrong on the
build host the cross-check has to run on.

- **`typedef unsigned int ULong`** for the Bigint word. `Pack_32`,
  `n = k >> 5`, `k &= 0x1f` and `Storeinc`'s two `unsigned short`
  halves all assume it.
- **`typedef int Long`** for the borrow arithmetic in `_diff` and
  `quorem`. They write `borrow = y >> 16` and need an *arithmetic*
  shift of a negative 32-bit value; the subtraction happens in
  `unsigned int` and wraps, and a 32-bit `long` reinterprets that as
  the intended negative number while a 64-bit one converts it to a
  large positive and the shift yields `0xffff`. **Off by 0x10001 per
  word** -- which is exactly what a dumped `bd`/`bb` pair showed, and
  what made the 18-digit case 128 ulp out.
- **`Bcopy` copied `wds*sizeof(long)`** of an array whose element is
  `ULong`: twice as much as it should, off the end of the allocation.
- and **`fconv.h` had no include guard**, which only shows when
  something includes it twice.

`_dtoa.c` shares `quorem` and `Bcopy`, so it carried the same latent
hazards; none of this changes a byte of behaviour under kencc.

**The two bugs that were mine** are in the file's own header: the
correction loop's `j`, and Gay's sign-scan idiom, whose fall-through
switch inside `for(s = s00;;s++)` advances past the sign and then lets
the loop advance again, losing the first digit -- every negative number
came back at 0.44 of its size.

**What remains is two separate problems and they have been separated by
experiment rather than by reading.** Disabling the freelist -- `_Balloc`
always mallocs, `_Bfree` returns at once -- over the same 200000 inputs:

```
wrong  169725 -> 3656
spin       40 -> 2334
```

So **~98% of the errors are a Bigint lifetime bug**: something is freed
while still referenced, or freed twice, and the freelist hands it back.
The symptom in the failing cases is a *single corrupted nibble* on
inputs the parser gets exactly right when called on its own -- which is
what sent the search to state rather than to arithmetic in the first
place. The residue, 3656, is all near the bottom of the range
(2.1e-293 and neighbours) and mostly spins: the denormal arm does not
converge. Neither is the rounding logic.

**The freelist experiment is also the acceptance test for the fix**:
with the lifetime bug repaired, the counts with the freelist ON must
meet the counts with it OFF.

#### strtod finished: 0 of 199887 wrong, and the last two bugs were both `long`

`string/strtod.c` **is now Gay's parser** and the old one is gone.
`strtod-xcheck` against glibc, all four sections:

```
the seven strings Tcl's expr tests use     7 checked, 0 wrong   PASS
200000 round-trips through "%.17g"    199887 checked, 0 wrong   PASS
the powers of ten, 1e-320..1e308         629 checked, 0 wrong   PASS
values a naive parser still gets right    10 checked, 0 wrong   PASS
```

The file it replaced was wrong on **148018** of those 199887.

**The freelist was never the bug, and the experiment that said so was
still the right one.** Disabling `_Balloc`'s freelist took the failures
from 169725 to 3656, which was read as "a Bigint lifetime bug". It was
not: it was `ulp()` returning garbage, and the *damage* varied with
what the freelist handed back. **An experiment that isolates a variable
tells you the variable matters, not which way the causation runs** --
and the way to tell them apart was to keep instrumenting rather than to
act on the first reading.

Two bugs remained after that, and both were the `long` assumption again:

- **`ulp()`**. `(word0(a) & Exp_mask) - (P-1)*Exp_msk1` is
  `unsigned int` minus `int`, so it wraps; a 32-bit signed `L`
  reinterprets the wrap as the negative number that was meant, a
  64-bit one keeps `0xffe00000`, takes the `L > 0` arm and returns
  **-0x1p+1023 as the ulp of 2.1e-293**. Every value whose ulp is
  subnormal went through that, and the correction loop then chased its
  own tail: **169673 of the 169725 failures and every one of the spins
  were this single line.** `Long L;`.
- **The scale-up-by-2^53 dance** in the correction loop's underflow
  arm is guarded upstream by `#ifdef Sudden_Underflow`, which is for
  machines that *flush* to zero. IEEE has gradual underflow and takes
  the plain arm. Applying it anyway meant that for a subnormal --
  exponent field 0 -- `word0(rv) += P*Exp_msk1` makes the field exactly
  `P`, which is the very test the next line uses to decide the value
  underflowed. So every subnormal was rewritten to the smallest
  subnormal and then driven to zero. `1e-308` came out `0`. That was
  the last 52.

**Six bugs in all, and four were in the shared kit rather than in the
new file**: `ULong`, `Long` in `_diff`/`quorem`, `Bcopy`'s
`sizeof(long)`, and `_d2b` leaving `i` unset. Every one of them is the
same sentence -- *Gay's arithmetic needs a 32-bit word and says
`long'* -- and every one was correct under kencc and wrong under gcc,
which is why none had ever been seen and why the cross-check could not
run until they were fixed.

#### And _dtoa was broken too, in the shipping printf path

`_d2b`'s missing `i` is read by its **denormal** arm, `x[i-1]`, and
`_dtoa` calls `_d2b` for every conversion. `sys/lib/tests/dtoa-xcheck.c`
is the new host program that measures what mode 0 promises -- the
shortest string that reads back as the same double -- with the same
100000 values, before and after:

```
before:  99941 checked, 52 wrong   (subnormals printed as "?")
after:   99941 checked,  3 wrong   (all at 2^-1016 and below, 1 ulp)
```

**`?` is Gay's internal "cannot happen" marker**, and it was what this
system printed for a denormal. Nothing in the tree would have noticed:
there was no test that formatted one. AddressSanitizer with the
freelist disabled named the line in a single run, after the symptom --
*correct in isolation, one corrupted nibble in bulk* -- had already said
the fault was state rather than arithmetic.

**`strtof` and `strtold` are still the old algorithm**, the same
91-line file twice more, and still wrong in the same way.

#### strtof and strtold: one forwards, and one needed a real fix

**`strtold` forwards to `strtod`.** kencc has no extended precision --
`sub.c`'s `simplet()` maps `BDOUBLE|BLONG` to `types[TDOUBLE]`, so
`long double` IS `double` on every architecture here, which is the same
fact perl's `config.h` had to be corrected to admit. The file it
replaced was a third copy of the old parser, with the same bug as the
other two. On this platform forwarding is not a shortcut, it is what
the function means; and three copies of a parser is three places for
the next bug to live.

**`strtof` looked like the same one-liner and was not.** The obvious
`(float)strtod(s)` rounds twice -- decimal to 53 bits, then 53 to 24 --
and that is not the same operation as rounding once to 24. When the
correctly rounded double lands exactly on a midpoint between two
floats, the narrowing has no tie-break left and falls back on
round-half-to-even, which is right only by luck.

**The question was settled by measurement, not by argument.**
`sys/lib/tests/strtof-xcheck.c`, against glibc:

```
1. 200000 float round-trips through "%.9g"    0 wrong
2. 200000 random 17-digit decimals            0 wrong
3. the powers of ten, 1e-50..1e40             0 wrong
4. the edges of the float range               1 wrong
5. decimals BUILT to sit on a float midpoint  12709 of 39694 wrong
```

Sections 1 to 3 say ordinary use never notices. **Section 5 is the
point of the file**: for a float `f` the midpoint `M` between it and
the next float up is exactly representable as a double and its decimal
expansion is finite, so `M` and `M` with a digit appended can both be
written exactly -- and a third of those come out wrong. A sweep that
only drew random numbers would have reported this as correct.

Section 4's single failure was the same thing at the top end:
`3.4028235677973366e+38` is below the overflow boundary and must give
FLT_MAX; it gave infinity, because the boundary is itself a midpoint.

**The fix asks strtod a question it already knows the answer to.** The
correction loop holds the decimal as an exact Bigint, so
`_strtod_cmp()` returns the nearest double *and* which side of it the
decimal lay (`decimalcmp` does one more exact scaled comparison at the
end; the floating-point fast paths are skipped when the comparison is
wanted, since they never build the Bigint). If the double is a float
midpoint and the decimal was not on it, one `nextafter` in the right
direction moves it off the tie before the narrowing. If the decimal
*was* the midpoint, the tie is real and half-to-even is correct, so
nothing is done.

**The nudge is conditional on being exactly on a midpoint, and that is
not fussiness**: a double one ulp away from a midpoint would be moved
*onto* one by an unconditional nudge, turning a decided case into a
tie. `floatmidpoint()` asks by averaging the two floats that bracket
the double -- exact, and still right in the subnormal range where a
float's step is a fixed 2^-149 and the bit-pattern argument does not
hold.

After it: **all five sections 0 wrong**, and `strtod-xcheck` and
`dtoa-xcheck` are unchanged, which is the check that the plumbing added
to `strtod` cost nothing.

*(One guard worth naming: `retfree` is also reached from the overflow
and underflow exits, where the result is an infinity or a zero and
`_d2b` has nothing to take apart. The comparison is computed only for
a finite non-zero result -- and no caller needs it otherwise, since
neither an infinity nor a zero is a midpoint between floats.)*

#### The first Plan 9 build broke, and it found a lie in float_arch.h

```
.../string/../include/fconv.h:55 not a function
.../string/../include/fconv.h:55 syntax error, last name: one
```

Line 55 is Gay's deliberate trap -- *"Exactly one of IEEE_8087,
IEEE_MC68k, VAX, or IBM should be defined."* -- a sentence that is a
syntax error unless the `#if` above it is satisfied. So none of the
four was defined while compiling `strtof.c`, and `strtod.c` next to it
compiled fine.

**The difference was include order, and the reason is a macro gate.**
`amd64/include/ape/float_arch.h` defines `IEEE_8087` only under
`#ifdef _RESEARCH_SOURCE`, and `fconv.h` defines `_RESEARCH_SOURCE`
itself immediately before pulling `<float.h>`. `strtod.c` includes
`fconv.h` first, so that works. `strtof.c` included `<stdlib.h>`,
`<math.h>`, `<float.h>` and `<errno.h>` first out of habit, `float.h`
set its own `__FLOAT` guard with `IEEE_8087` undefined, and fconv.h's
later `#include <float.h>` was a no-op. **`fconv.h` first is
load-bearing in any file that uses it**, and it says so now.

**And two lines below IEEE_8087 sat `#define Sudden_Underflow 1`.**

That tells Gay's code the machine FLUSHES denormals to zero. **It does
not.** `arch/amd64/fenv.s` loads MXCSR `0x1f80` for the default
environment -- all exceptions masked, round to nearest, and bit 15
(FTZ) and bit 6 (DAZ) both **clear**. Underflow on amd64 under APExp is
gradual.

It is not cosmetic. `_d2b` has two arms: under `Sudden_Underflow` it
reports `*bits = P - k` for everything and has no denormal case at all.
So on Plan 9, strtod's correction loop was being told that subnormal
inputs carry 53 significand bits, and `_dtoa` was printing them on the
same assumption -- while every measurement in `strtod-xcheck`,
`strtof-xcheck` and `dtoa-xcheck` was made on the build host, where no
`float_arch.h` is in sight and the macro was never defined. **The two
configurations were different, and only one of them had been
measured.** They are the same one now.

The claim is stock APE's, inherited from a Plan 9 that did flush.
**Seven other architectures still carry it and none has been checked**
-- this is a statement about one machine's floating-point environment,
so it is a probe rather than a library rule, and only the machine that
was looked at is changed.

*(Also from that build: kencc's `used and not set: bd bb bs delta`. It
is right -- `retfree` frees all four and is reachable from the overflow
and underflow exits before the loop has run. `Bfree(0)` is a no-op by
design, so they are initialised to 0.)*

#### `2^1023` is not a power of two, and every subnormal from ldexp was wrong

The `machexp` probe answered in one run, and it did not say what was
predicted. `MakeHighPrecisionDouble` had the right answer in hand:

```
APEXP MakeHighPrecisionDouble: numSigDigs=17 exponent=292 | maxDigits=308 minDigits=-324 log2FLT_RADIX=1 mantBits=53
APEXP   Pow10TimesFrExp(292) -> 0.99999999999999967 machexp=1024 | limit 1024
APEXP   SafeLdExp -> 2041.9999999999993
APEXP   after two RefineApproximation -> Infinity
```

Every constant is right, `machexp` is **1024** against a limit of 1024,
so neither overflow test fires -- and then `SafeLdExp`, which is
`ldexp`, which is `scalbn`, turns `0.99999999999999967 x 2^1024` into
**2042**.

`math/scalbn.c`:

```c
	if (n > 1023) {
		y *= 2^1023 ;
```

**`2^1023` is `2 XOR 1023` -- an integer bitwise exclusive-or, 1021.**
musl writes `0x1p1023`, a C99 hex float; someone read the `p` as
"power of" and wrote it out with a caret. It compiles without a
murmur, because both operands are integers, and multiplies by 1021.
The observed factor was 2042 = 1021 x 2, the second 2 being scalbn's
own `u.f` for the leftover exponent. `scalbnf.c` had the same thing
with 127, where `2 XOR 127` is 125.

**This is not a compiler bug.** 89 other files under `math/` use
`0x1p...` literals and are fine, so kencc's hex floats work. These two
were mistyped, not miscompiled -- and `^` on two doubles would not
compile at all, which is why the mistake could only survive where both
operands happened to be integers.

**It was never only Tcl's six tests.** Replicating the old code beside
the new -- cheaper than a rebuild, and this tree's rule for asking
whether a fix was needed -- `ldexp-test` fails **13** checks on it:

```
52 of 2098 double exponents wrong, first at e=-1074
23 of  277 float exponents wrong, first at e=-149
scalbn(1.0, -1074) = -2.2693e-13     (a NEGATIVE number, from +1.0)
scalbn(1.0, 1024)  = 2042            (should be infinity)
```

**Every subnormal that any program reached through `ldexp` or
`scalbn` was wrong, and some had the wrong sign.** The two arms are
only entered when `|n|` exceeds what one multiplication can do -- above
1023, or below -1022, which is exactly the subnormal range -- so
ordinary use never went near them.

#### And the host cross-check had already passed scalbn

That is the part worth keeping. `scalbn` was swept against glibc's over
**299876 values and reported 0 wrong** two rounds ago, in the same
program that cleared `frexp`. The sweep drew its exponent from
`rand()%200 - 100`.

**It never once entered the branch that was wrong.** *A check that
cannot fail is not a check* -- this file's own rule -- and a sweep that
cannot reach a branch has not tested it. The window looked generous
and was chosen without asking what the code does differently outside
it.

`sys/lib/tests/ldexp-test.c` is the replacement, and every section is
bounded by the format's own limits rather than by a comfortable
window: all 2098 double exponents from the smallest subnormal to the
largest power of two, all 277 float ones, both multi-step arms, and
overflow and underflow at both ends. The expected values are built
from IEEE bit patterns, never from `ldexp` itself, because a test that
asks the unit under test for its own answer cannot fail either. 0
failures on glibc, 13 on the old code.

**Prediction for the next suite run**: `expr` 5 and `expr-old-37.21`
go, so `Failed` 64 -> 58. `binary-53.25`/`53.26` -- "a double one ulp
past the float range must round to infinity" -- are the same shape and
may go with them, which would make it 56. **What would refute it**: any
of the six staying, which would mean `RefineApproximation` has a
second fault behind this one; or a count below 56, which would mean
something else in the suite was also reaching a subnormal through
`ldexp` and nobody had connected it.

#### FLT_MAX was not FLT_MAX, and the probe named it in one run

`binfloat-test` was written with four suspects listed -- `fabs`,
`ldexp(1.0,103)`, the `INFINITY` macro and the plain cast -- because a
failing test cannot tell them apart. The run:

```
  note FLT_MAX         = 3.4028234999999998e+38
  note threshold       = 3.4028235714120479e+38
  PASS  fabs, ldexp(1.0,103), INFINITY, and the plain cast
  FAIL  dvalue is above the overflow threshold TOO
  FAIL  binary format R of that double is +Inf
```

**The real FLT_MAX is 3.4028234663852886e+38.** APE's was about 3.4e30
too big, so the boundary Tcl computes -- `FLT_MAX + 2^103` -- sat
*above* the value `binary-53.25` feeds it, and `binary format R` wrote
FLT_MAX where it had to write +Inf.

**The cause is one missing letter.** C says `FLT_MAX`, `FLT_MIN` and
`FLT_EPSILON` have type **float**; `float_arch.h` wrote them with no
`F` suffix:

```c
#define FLT_MAX		3.40282347e+38
```

so each was a *double* holding the nearest double to a rounded
decimal, rather than the float it names. With the suffix, even that
short spelling rounds to the right float and `(double) FLT_MAX` is
exact. They now carry the suffix and full precision both -- the suffix
alone leaves about half a digit of margin and there is no reason to
spend it.

**Every one of the four named suspects was innocent**, including the
one this file's own comment called "not an idle suspect". Listing them
and printing all four is what turned that into one run instead of four.

**And the numbers alone could not have finished it.** A constant that
is wrong and a *header* that is the wrong file look identical from
outside -- the invariant that `/$objtype/include/ape` is searched
before `/sys/include/ape` is exactly this trap, and `deeppath-test`
has been caught by it before. So section 6 prints three things: a
`__APEXP_FLOAT_ARCH` marker saying which file was read, the
stringified macro saying what it contained, and `sizeof(FLT_MAX)`
saying whether it is a float at all. It also audits `FLT_MIN`,
`FLT_EPSILON`, `DBL_MAX`, `DBL_MIN` and `DBL_EPSILON` against bit
patterns while it is there.

*The comparisons use bit patterns rather than long decimal literals on
purpose: whether this compiler converts a 39-digit constant exactly is
a separate question, and a test that leaned on it would misreport if
the answer were no.*

**Prediction**: `binary-53.25` and `binary-53.26` go, `Failed` 56 ->
54, and `binfloat-test` reports 0 failures with the marker line saying
`THIS TREE`. **What would refute it**: the marker saying *not* this
tree, which would mean the header being read is not the one that was
edited and the whole diagnosis is about the wrong file.

### signal/ — `tar cf` dies in note delivery, and the ratrace names where

`getprogname` is CONFIRMED by the same screenshot that produced this:
`tar cf /tmp/t.tar /tmp/h` now prints

```
tar: Removing leading `/' from member names
```

where before the fix the same diagnostic came out as `: ...`. gnulib's
`error()` reaches `getprogname()`, so that one line certifies the whole
chain — `_callmain` sets `argv0`, `getprogname()` takes its basename,
and `tar:` rather than `/bin/tar:` says the basename half works too.

**And then tar dies:**

```
tar 2288: suicide: bad address in notify
```

**This is not the extraction bug.** The recorded diagnosis — *tar's
first read of the archive yields no block* — was measured on `tar tf`.
This is `tar cf`, a different code path, and a crash rather than a
wrong answer. They may share a cause and they may not; nothing measured
so far connects them, so they are two entries until something does.

#### What the trace says, and what it does not

`ratrace -c tar cf /tmp/t.tar /tmp/h` (270 lines, `tmp/rt.out` on
`main`) is completely ordinary up to its last line:

```
2292 tar Notify   2827ff 0x292f63 = 0
...
2292 tar Open     0x7fffffffefa6/"/tmp/t.tar" 0x11 = 4
2292 tar Fstat    4 ... = 72
2292 tar Open     0x42c518/"/adm/users" 0x0 = 5
2292 tar Pread    5 ... = 139
2292 tar Pwrite   2 "t" ... "a" ... "r" ... ":" ...      (the message, a byte at a time)
2292 tar Brk      0x47d0c0 = 0
2292 tar Stat     0x7ffffffdd8c0/"/tmp/h" 0x478400 115 = 68
```

and stops. **Every call succeeds, including the last.** So the fault is
in user code after `Stat` returned, not in a system call, and `ratrace`
cannot see notes — it traces syscalls, and note delivery is not one.

Two facts fall out of this that are worth keeping:

- **`suicide: bad address in notify` is a SECOND failure standing on a
  first.** The kernel only enters `notify()` because a note was already
  posted, and the only thing that posts a note to a process doing
  nothing unusual is a trap — a fault in tar. The suicide message
  *replaces* the note text we actually want (`sys: trap: fault
  read addr=0x... pc=0x...`), which is why this trace names nothing.
- **The handler registered is `0x292f63`**, from the one `Notify` call
  (`_envsetup.c:151`, `_NOTIFY(_notehandler)`). Whether that address is
  `_notehandler` at all, and whether its low bits matter to this
  kernel, are both questions `nm` answers in a second on the VM. Do not
  reason about the kernel's exact test from memory — 9front's source is
  not in this tree and was not reachable from here.

#### The two probes, in order — and the first one answered in one run

1. **`nohandle=1 tar cf /tmp/t.tar /tmp/h`.** `_envsetup` scans `/env`
   and skips `_NOTIFY(_notehandler)` entirely when it finds a variable
   named `nohandle` (the value is not read). With no handler installed
   the kernel takes the default action and **prints the note itself**.
   It did:

   ```
   tar 2459: suicide: sys: trap: fault write addr=0x7ffffeffefc8 pc=0x247ba3
   ```

2. **`acid` on a Broken process.** All three dead tars were still in
   `/proc` — `pexit` keeps the image — and `lstk()` printed one frame
   over and over:

   ```
   strerror(n=0x14)+0x19  .../external/gnulib/strerror.c:52
   strerror(n=0x14)+0x1e  .../external/gnulib/strerror.c:56
   strerror(n=0x14)+0x1e  .../external/gnulib/strerror.c:56
   ...
   ```

**`nm` for the handler address was the wrong question and is closed.**
The faulting address is `0x7ffffeffefc8`, about 16MB below the top of
the stack: tar had *run out of stack*. So `suicide: bad address in
notify` was never about the handler at all — the kernel could not push
the note frame onto an exhausted stack, which is precisely what that
message is for. **A crash whose own error message is about the crash
reporting machinery is reporting the second failure, not the first**,
and the way past it is to take the machinery out (`nohandle`) rather
than to investigate it.

#### gnulib's `strerror` called itself, and it was every GNU program

`strerror.c:52` is `msg = strerror (n);`, and it is *meant* to be the
system's. gnulib arranges that with one macro in its **generated**
`string.h` — `#define strerror rpl_strerror` — so that

```c
char *
strerror (int n)
#undef strerror
{
  ...
  msg = strerror (n);
```

defines `rpl_strerror`, and the `#undef` between the declarator and the
body makes the inner call reach the real one. **The whole mechanism is
that macro.**

**Nothing generates those headers here.** `sys/src/external/gnulib`
holds `string.in.h` and no `string.h`, so `<string.h>` was APE's, the
macro did not exist, the function defined the plain `strerror`, and
line 52 was a call to itself. No warning: it is a legal recursive call.

`n=0x14` is **20, ENOENT** in APE's `errno.h`. tar reached an ENOENT,
called `error (0, errno, ...)`, and `error.c:203` reached `strerror`.

**It was never tar's, and it was never one program.** `strerror.$O` was
in `libgnu.a`, which is on the link line of every GNU package in this
tree — tar, sed, awk, grep, m4, gettext, diff, patch, bison — and
`error (0, errno, ...)` is gnulib's standard way for all of them to
report a failed system call. **Every one of them died on its first
one**, and died with a stack fault rather than a message, which is why
it read as a different bug each time it was met.

#### Why no link error said so

`sys/src/ape/cmd/gnulib/README` rule 1 has always been *never add a
module that libap already provides*, and libap provides `strerror`
(`string/strerror.c`, complete, and with an `EPLAN9` arm that returns
Plan 9's own `errstr` — so dropping gnulib's **improves** diagnostics
rather than costing anything). The reason that rule did not fire is
worth keeping: **libap's is an archive member the linker never had a
reason to pull.** gnulib's definition satisfied the symbol first, so
`ar` saw no duplicate and the link was clean. *A module libap already
provides is a problem whether or not the linker says so.*

The fix is one line out of OFILES. `strerror-override.$O` stays: it is
now unreferenced, but it is the companion of `strerror_r.c`, which is
how gnulib's `strerror_r` would be supplied if a package ever wants it.

#### The sweep, because one instance of a mechanism is never the question

The idiom is a definition of NAME immediately followed by `#undef NAME`.
Across `sys/src/external/gnulib` it appears in **34 places in 24
files**; **exactly one of them, `strerror.c`, was in OFILES.** The
command is in the README's rule 6 so the check can be repeated when
OFILES grows — which is the point, since the next module added could
be `fcntl`, `readdir`, `access` or `raise` and would fail the same
silent way.

#### `strerror-test.c`, and why the usual build command would have passed

`sys/lib/tests/strerror-test.c` reproduces it, and it **must be linked
against `libgnu.a`**:

```
pcc -o strerror-test strerror-test.c $home/APExp/$objtype/lib/ape/libgnu.a
```

A test built the ordinary way links `libap.a` alone and would have
passed against the broken tree, proving nothing — *reproduce the call
the failing code makes, not the outcome it wants*. Section 1 either
returns or kills the process, so there is no failing answer it can
print; every section therefore flushes a marker **before** the call, and
the last line on the screen names the call that did not come back. It
passes on glibc, which says the test is right rather than that the tree
is.

#### What this does not explain

**`tar tf` is still open and is still a separate bug.** That one
returns a wrong answer (`This does not look like a tar archive`, first
read yields no block) rather than crashing, and its messages come out
of `error (0, 0, ...)` — errnum zero, so `strerror` is never reached.
Consistent with this finding, unified by nothing. Do not assume.

**Prediction**: after `mk distclean; mk install` — a full one, because
`libgnu.a` changing has to reach every GNU binary already linked
against it — `tar cf /tmp/t.tar /tmp/h` completes silently apart from
the "Removing leading /" note, and `strerror-test` reports 0 failures.
**Refuted if** `tar cf` still faults. **And the useful third outcome**:
if `tar cf` works but `tar tf` on the archive it just wrote still says
`does not look like a tar archive`, the read bug is confirmed
independent of this one — which is the question the last two rounds
could not reach because tar never finished writing an archive.

### The strerror fix is CONFIRMED, and the tar read bug is now proven separate

Both halves of the prediction came back, and so did the third outcome
that was the point of writing it down.

```
$ tar cf /tmp/t.tar /tmp/h
tar: Removing leading `/' from member names
$ tar tf /tmp/t.tar
tmp/h
tar: Skipping to next header
tar: Exiting with failure status due to previous errors
```

- **`tar cf` completes.** No fault, no `suicide`. gnulib's
  self-recursive `strerror` was the whole of that crash.
- **`strerror-test` reports 0 failures**, linked against `libgnu.a`,
  every section — including section 1, whose only possible failure was
  to kill the process.
- **And `tar tf` on the archive tar just wrote fails.** That is the
  third outcome: the read bug is **CONFIRMED independent** of
  `strerror`, which the last two rounds could not establish because tar
  never finished writing an archive to try.

#### What the new symptom says, and what it retires

**It is not the same failure as the original archive.** That one said
`This does not look like a tar archive` and `A lone zero block at 580`.
This one **lists `tmp/h` correctly** and then fails. So:

- the first header parsed, **and its checksum verified** — tar does not
  print a member name it has not accepted;
- `list.c:294` prints `Skipping to next header` **only when the
  previous status was `HEADER_STILL_OK`**, so the failure is on the
  *second* `read_header`: a block that is neither a valid header nor
  all zeros.

**So the recorded conclusion "tar's FIRST read of the archive yields no
block" is about that archive, and does not generalise.** Here the first
read plainly yields a block. Whether the two failures share a cause is
open; nothing measured connects them, and assuming it would put the
next round on the wrong file.

For a one-file archive there is nothing between the member and the
end-of-archive zero blocks, so exactly one of two things is true and
they need completely different fixes:

- **(a) the archive is malformed** — tar's WRITE path is broken and the
  read is correctly refusing garbage;
- **(b) the archive is fine** — tar's READ path is broken, most likely
  in how far it advances past the member's data. Landing one block
  short would make it read the file's own contents as a header, which
  is exactly this symptom.

#### `tarhdr-probe.c`, and the reference output to compare against

`sys/lib/tests/tarhdr-probe.c` prints what is in a tar file block by
block — every header field as raw bytes, the size and checksum decoded,
the computed checksum beside the stored one, where the data blocks are,
and where the zero blocks start. **It asserts nothing**; it is a probe,
and anything it could assert would be an assertion about GNU tar's
format rather than about this tree.

It decodes the octal fields with its own three-line loop rather than
tar's `from_header()`, deliberately: *a probe that reuses the code under
suspicion cannot clear it.*

Checked on the host against an archive made by a working tar, which is
what says whether the probe or the tree is wrong. That run is the
reference:

```
size   10240 bytes = 20 blocks of 512, remainder 0
block 0: member 1, ustar header
  name       [h\0\0...]
  size       [00000000006\0]
  chksum     [007724\0 ]
  magic      [ustar ]
  decoded size   = 6
  decoded chksum = 4052, computed = 4052  -- MATCH
  1 data block, so the next header belongs at block 2
    block 1 (the member's data):
      first 16 bytes: 68 65 6c 6c 6f 0a 00 00 ...
blocks 2..19: ALL ZERO (18 blocks)
```

Anything the 9front run says that this does not is the bug.

### readline wraps at 80 columns under rio, and the mechanism is already there

Turning `READLINE` on made bash redraw the input line, and a long
command now wraps in the wrong place. **libap already answers
`TIOCGWINSZ`** (`misc/ioctl.c`) and answers it the right way: `80x24`
by default, overridden by **`$COLUMNS`** and **`$LINES`**. Nothing under
rio sets either, so readline gets 80 while the window is whatever it
is.

```
export COLUMNS=136        # or whatever the window really is
```

fixes it, and it stays fixed: bash's `checkwinsize` re-asks through the
same ioctl, which reads the variable bash exported, so the two agree
rather than fighting.

**There is no better answer available under rio, and that is a fact
about rio rather than a gap here.** rio is graphical: a window is a
pixel rectangle (`/dev/wctl`), the font is proportional in general, and
there is no character grid to ask about and no `SIGWINCH` when the
window is resized. Computing columns would mean libc opening a font
file and measuring glyphs, which is not a libc's job and would still be
a guess for a proportional font.

**It joins arrow keys and colour on the list of things `vts` would
buy**, and it is the strongest of the three as an argument for it: vts
keeps a real character grid (`cells.c`), so it knows the answer exactly
and can set `$COLUMNS` per session. Same shape as the earlier finding
that the blocker for completion was never vts — this one genuinely is.

#### Would vts fix the columns and the wrapping? Partly, and they are two fixes

Asked directly, and worth answering from the source rather than the
shape of the question, because the two halves come apart.

**COLUMNS: yes, and exactly -- but vts has to be made to say it, and
its grid is a constant today.**

vts has what rio has not: a real character grid. `cells.h` carries
`rows`/`cols` and a `rows x cols` cell array, so there IS an exact
number to report. What is missing is two things, both small and
neither automatic:

- **The number is hardcoded.** `srv.c:488` and `srv.c:594` both call
  `session_init(s, name, 24, 80)`. So today vts would report a
  *correct* 80 rather than a *guessed* 80 -- no visible change.
  `cellbuf_resize()` exists (`cells.h:77`) and nothing calls it from a
  window-size path, so making the grid follow the rio window it draws
  into is the real work.
- **Nothing carries it to the shell.** The spawn in `session.c` is
  `rfork(RFPROC|RFFDG|RFNOTEG|RFENVG)` -- and `RFENVG` **copies** the
  environment, so the child gets a private one -- followed by
  `putenv("vts", ...)` and `putenv("prompt", ...)`. Two more `putenv`
  calls for `COLUMNS` and `LINES` is the whole of it at that end,
  because **libap's `TIOCGWINSZ` already reads exactly those two
  names**. That half is done.

**Resize still is not automatic, and cannot be made so in libap.** Plan
9 has no `SIGWINCH`. But vts owns both ends -- it knows when its grid
changed and it knows the shell's pid -- so it can post a note itself,
which is precisely what rio cannot do for us. *The difference is not
that vts can measure and rio cannot; it is that vts can TELL.*

**WRAPPING: that is `$TERM`, a different fix, and the bigger half.**

Correct width alone would not have fixed what was on the screen. The
line was garbled rather than merely wrapped in the wrong column, and
the reason is the terminal description:

```
dumb|dumb terminal:\
	:am:co#80:li#24:
```

That is the whole entry in `sys/lib/ape/termcap`. **No `ce`** (clear to
end of line), **no `up`**, **no `cm`** -- so readline has almost
nothing to redraw a changed line with and falls back to reprinting.
`terminal.c:584` also makes `dumb` one of three names that force
`_rl_term_isansi = 0`. And note `co#80` is hardcoded *in the termcap
entry*, a second place the 80 comes from.

**vts is what makes a real `$TERM` honest**, and that is the point
rather than which VT level it claims: the engine is **libvterm**,
upstream's full state machine, and `sys/lib/ape/termcap` already ships
`vt100|vt100-am` and `xterm` entries. Naming either one is then a
statement that is true, which is the only reason to make it -- *a
capability declared and not present is the same bug as one present and
not declared, from the other side.*

**Neither reaches bash until the fd question is fixed, and that comes
first.** `session.c:124` dups a **pipe** onto the shell's fd 0, so
`isatty(0)` is false and bash never starts readline at all; and the
spawn is a hardcoded `execl("/bin/rc", ...)`. So the order is:

1. bash under vts, on a `cons` bound to `/dev/cons` rather than a pipe;
2. a per-session `consctl`, so raw mode is per window;
3. `$TERM=vt100` (or `xterm`) -- this is the one that fixes the redraw;
4. vts's grid driven by its real window size, `cellbuf_resize()` wired
   to it;
5. `putenv("COLUMNS"/"LINES")` at spawn, and a note on resize.

Steps 1 and 2 are already on the list for tab completion. 3 to 5 are
what this question adds, and 3 is the one that changes what the screen
looks like.

#### The archive is MALFORMED: it is tar's WRITE path, and the data sits 8 bytes late

`tarhdr-probe` on `/tmp/t.tar` -- the archive tar itself had just
written -- settles (a) against (b) in one run:

```
size   10240 bytes = 20 blocks of 512, remainder 0
block 0: member 1, ustar header
  size       [00000000006\0]      decoded size   = 6
  chksum     [011250\0 ]          decoded chksum = 4776, computed = 4776  -- MATCH
  magic      [ustar ]
  1 data block, so the next header belongs at block 2
    block 1 (the member's data):
      first 16 bytes: 00 00 00 00 00 00 00 00 68 65 6c 6c 6f 0a 00 00
      as text:      "........hello..."
block 2: NOT a ustar header and NOT zero
      first 32 bytes: 00 ... 00 b6 01 00 00 cd 98 b4 6a 00 ...
block 3: NOT a ustar header and NOT zero
      first 32 bytes: 00 ... 00 b5 65 47 00 ...
blocks 4..19: ALL ZERO (16 blocks)
```

Against the host reference for the same one-file archive, where block 1
begins `68 65 6c 6c 6f 0a` at **offset 0** and blocks 2..19 are all
zero. Three things follow, and the first two are firm:

- **The header block is perfect** -- name, size, magic, typeflag, and
  the checksum recomputes. So tar's reader was right to accept it, and
  right to refuse what came next.
- **"hello\n" is 8 bytes into block 1.** The archive is malformed;
  tar's *write* path is the bug, and the reader is behaving correctly.
  This closes the (a)/(b) split.
- **Blocks 2 and 3 are not zero, and the bytes are not random.**
  `b6 01 00 00` is 0x1b6 = **0666**, and `cd 98 b4 6a` read
  little-endian is a plausible 2026 `time_t`. Those are the fields of a
  `struct stat`, not heap litter -- and on Plan 9 a fresh allocation
  comes from newly sbrk'd pages, which are **zero**, so every non-zero
  byte in there was *written* by something. That is a second question
  and it is recorded, not folded into the first.

#### The offset of the data IS a measurement, and it named a suspect

`create.c`'s `dump_regular_file()`:

```c
  blk = start_header (st);        /* record_start */
  finish_header (st, blk, ...);   /* set_next_block_after -> record_start + 1 */
  ...
  blk = find_next_block ();       /* record_start + 1 */
  count = blocking_read (fd, blk->buffer, bufsize);
```

so the file offset of the member's data is exactly
`1 * sizeof(union block)`. It came out **520**.

Every member of that union is an array of `char`, and gcc makes the
whole thing 512, so 520 would mean kencc pads one of them -- shifting
every block after the first, and a compiler question rather than a tar
one. **`sys/lib/tests/tarblock-probe.c` asks it directly**, printing
each member's size beside the host's answer.

**It must be built with tar's own flags** -- the command is in the file
-- because tar.h is reached through tar's include path and its
`config.h`, and a different `-I` order measures a different header.

**What each answer means, written down before the run:**

- **not 512: CONFIRMED.** The member printed as oversized is the one to
  look at, every archive this tar has written is malformed the same
  way, and it would explain the second symptom too, since the zero-fill
  in `dump_regular_file` and `write_eot` counts in `BLOCKSIZE` while
  the pointers step in `sizeof(union block)`.
- **512: REFUTED, and worth as much.** The union is innocent, the shift
  is in the copy loop or in what `read()` does with the buffer it is
  handed, and the next probe belongs there. *Do not go on believing the
  union.*

The host run of `tarblock-probe` is 0 disagreements and prints
`REFUTED` for gcc, which is what says the probe is right rather than
that the tree is.
