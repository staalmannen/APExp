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

## A descriptor arrived POISONED from an exec, and it was every APE program

**`select: -> -1, _startbuf fd=0 errno=13` after `_startbuf: EIO,
FD_BUFFEREDX fd=0 flags=42`.** One instrumented run, after three rounds
on vts and on bash, neither of which had anything to do with it.

`0x2A` is `FD_ISOPEN | FD_BUFFEREDX | FD_ISTTY`. bash's fd 0 was marked
**poisoned before bash had buffered anything**, and `read()` and
`select()` both answer EIO for that flag without going near the
descriptor.

**The chain, and none of it is exotic:**

- `apexp-sh` gives you an interactive bash. readline's `rl_getc()`
  calls `select()` on fd 0 for every keystroke, and libap's `select()`
  buffers anything it is asked to watch -- `_startbuf` forks a copy
  process and sets **`FD_BUFFERED`**.
- bash forks. **`fork()`'s child runs `_detachbuf()`**, which turns
  every `FD_BUFFERED` into **`FD_BUFFEREDX`** -- correctly, for that
  child: the shared segment is detached and the copy process belongs to
  the parent.
- the child execs. **`execve` writes the flags word VERBATIM into
  `/env/_fdinfo`** (`process/execve.c`), and the new image's
  `sfdinit()` applies it **verbatim**.

So any program started by an APE parent that had ever `select()`ed on a
descriptor inherited that descriptor **unreadable, permanently**.

**It only became reachable when `READLINE` was turned on in bash's
`config.h`**, because until then nothing in this tree ever asked
`select()` about a terminal. *A fix that makes a process reach code it
never reached before can expose anything on that path* -- the rule was
already written down from the `tcsetattr` round, and this is its next
instance.

**The fix is one line of masking and it goes in the CONSUMER.**
`sfdinit()` already scrubs `FD_ISTTY` and `FD_REGCHECKED|FD_ISREG` for
exactly this reason, with comments about per-process staleness; the
buffering flags are the third member of the same family and were the
one left in. They are not facts about a descriptor at all -- they say
*this process image has a copy process reading it into a shared
segment*, and `_EXEC` replaces the image. `fi->buf` is cleared with
them, being a pointer into a segment that no longer exists.

Deliberately **not** masked in `execve`'s writer: a child cannot trust
those bits whoever wrote them, including a `$_fdinfo` left by an older
libap, so the place that must not believe them is the place that reads
them.

`sys/lib/tests/bufexec-test.c` is the regression test -- pipe on fd 0,
`select()` to force buffering, then fork and exec itself and check that
the child's `select()` and `read()` reach the descriptor instead of
refusing. It calls `_fdinfomark()`, so it **will not link** against a
libap predating the fix; measuring the stale library by accident is
impossible. Fourth use of that idiom after `_sock_listenmark`,
`_execmark` and `_ttymark`.

### CONFIRMED on the rebuilt library, and the run measured the open problem too

```
bufexec-test
_fdinfomark = 1  (libap with the exec scrub)
PASS: fd 0 was usable when this test started
--- child, fd 0 inherited across exec ---
PASS: select() on an exec-inherited fd does not fail -- select returned 0, errno 0
PASS: read() on an exec-inherited fd does not fail with EIO -- read returned -1, errno 3
0 failures
```

`_fdinfomark = 1` says the INSTALLED library is the fixed one, and the
link would have failed rather than the test passing otherwise. Both
calls reach the descriptor instead of refusing: **the scrub is
measured.**

**And `errno 3` is `EWOULDBLOCK`** (`sys/include/ape/errno.h:15`), where
the same child on glibc reads all six seeded bytes. So the bytes were
not there -- which is the parent/copy-process competition below, in its
first sighting.

**But one non-blocking read at one instant cannot tell that from "they
had not arrived yet"**, so the test now carries a bounded PROBE that
waits and prints which. It asserts nothing, so it cannot go flaky.
**gcc caught the first version of that probe being worthless**: run
unconditionally, it found nothing on glibc *because the earlier read
had already taken all six*, and announced the loss -- a refutation
where there was a confirmation. It now runs only when the first read
came back empty. *A check whose negative result has two explanations is
not a check*, and checking a new test on the host first is what said
so, again.

### What it does NOT fix, recorded rather than assumed away

The test asserts the descriptor is **usable**, not that the bytes are
all there, and the difference is a real open problem: **the parent's
copy process is still alive and still reading the same open file.** On
an interactive shell that means bash's fd-0 copy process is sitting in
`_READ` on the terminal while a child runs, and the two compete for
keystrokes. `_detachbuf` in the forked child detaches the segment; it
does not stop the parent's reader.

That is inherent in `select()` being a copy process rather than a system
call, and it wants its own round. Asserting delivery in the test would
have been asserting something the design does not provide -- the
"invent semantics to make a test pass" shape.

### And an unchecked fork on the way

`_startbuf` did not test `_RFORK(RFFDG|RFPROC|RFNOWAIT)`. A failure
stored `-1` as the copy process's pid and the parent went straight to
`_RENDEZVOUS(&b->copypid, 0)` -- waiting for a process that was never
created, inside `read()` or `select()`, printing nothing. Fixed; found
while instrumenting, not measured.

### The other thing the reading turned up

`ioctl(FIONREAD)` stored `*(long*)arg` where the argument is an `int *`
on BSD, on Linux and in every caller here -- readline passes
`&chars_avail`, an `int` local -- so on amd64 it wrote **eight** bytes
and smashed the four beyond, whatever the compiler had put next in the
caller's frame. The store succeeds and nothing complains. Fixed;
recorded as found, not measured. Its ANSWER is still an approximation:
`st_size` is the bytes available only for a file that has a size, so for
a terminal, pipe or socket it says 0 always. Plan 9's `stat` on a pipe
does report what is queued, so a real answer exists for that case and
wants its own round.

## bash as /bin/sh dies out of memory, and select() is the lead

Recorded from a full rebuild with bash in place of dash as `/bin/sh`,
**not measured**:

```
sh 28439: warning: process exceeds 100 file descriptors
sh 28439: warning: process exceeds 200 file descriptors
sh 28439: Killed: Insufficient physical memory
mk: .../amd64/bin/ape/bison -y -d ... : exit status=rc 28429: sh 28439:
    Killed: Insufficient physical memory
```

**The descriptor warnings are the part worth keeping.** A shell running
build recipes has no business holding 200 descriptors, and the kernel
said so twice before the kill. That is a leak with a shape, not a
program that merely wanted more memory.

`plan9/_buf.c` is where to look, and there are two candidates. Both are
consequences of `select()` being a **copy process** here rather than a
system call, so both got newly reachable when `READLINE` was turned on
in bash's `config.h` -- nothing in this tree had asked `select()` about
much before that.

- **`_startbuf` leaves the descriptor open on purpose**: *"leave fd open
  in parent so system doesn't reuse it"*. Every descriptor a process
  ever selects on therefore stays open for the life of the process
  unless `close()` runs `_closebuf` on it, **and forks a copy process
  that stays alive too**. A shell that selects on a pipe per command
  accumulates one of each per command.
- **The shared segment is big.** `Muxseg` is
  `Lock + 3 ints + 2 fd_set + Muxbuf bufs[OPEN_MAX]`, `OPEN_MAX` is
  **256**, and each `Muxbuf` carries `data[PERFDMAX]` = `2*8192` =
  **16 KB**. So the segment `_SEGATTACH`es **about 4.2 MB**, per process
  that ever calls `select()`. *That is address space rather than
  resident memory* -- Plan 9 pages it in on demand, and `INITBUFS = 4`
  says only a few slots are expected to be touched -- so this is the
  weaker of the two and is written down to be excluded rather than
  assumed. It becomes the answer only if something touches many slots.

**The cheap test already exists and needs no new code.** `$APEXP_DEBUG`
prints one line per newly buffered descriptor:

```
select: buffered now fd=N flags=...
```

so running the failing build with `APEXP_DEBUG=1` and counting those
lines says directly whether the buffer count climbs with the descriptor
count. If it does, the leak is the first candidate and the fix is about
when `_closebuf` runs. If it does not, `select()` is exonerated and the
next question is bash's own descriptor handling.

*Back on dash for now. The goal is one shell rather than two, so this
is on the way rather than optional -- but it is a round of its own.*

## The copy process is a keystroke thief, and it has a workaround now

The competition recorded above stopped being theoretical. Under `vts`,
typing `echo $SHELL` reached the session as `hoLL`: vts's own trace
showed five `cons write (from viewer)` bytes, all five HANDED to the
shell and echoed one for one, and **the other six never arrived at
all**.

**The chain**: `apexp-sh` ends in `exec bash -l`; that bash is
interactive, so readline calls `select()` on fd 0; so libap forks a
copy process that reads the rio window's `/dev/cons` **continuously,
for as long as bash lives, whether or not bash wants the data**. While
`vtwin` runs in that window, vtwin's keyboard proc and that copy
process are both blocked reading the same console, and the kernel
wakes exactly one per keystroke.

*Not polling but reading* is the whole of it: `select()` here converts
"a descriptor this process may read later" into "a descriptor this
process is reading right now, always".

**It also outlives the image that made it.** `_killmuxsid` is an
**atexit** handler and `execve` never calls it, so `exec` does not
clear it; and `fork`'s child only `_detachbuf()`s its own view, since
the processes belong to the parent.

**Workaround, not a fix**: `./apexp-sh -r` gives the same environment
with **rc** as the launching shell. rc does not use `select()`, so
there is no copy process and no competition; `$SHELL` stays `bash`, so
a vts session still runs bash. It doubles as the control -- *if typing
works under `-r` and not under bash, the diagnosis is confirmed with
one variable changed.*

**The real fix is its own round** and is not small: either the copy
process reads only on demand, or a process gives up its copy processes
when it is not going to read (there is no `SIGTTIN` here to lean on),
or `execve` tears them down -- which would help a child but not this
case, where the thief is the living parent.

### CONFIRMED, and the partition is exact

`echo $SHELL` typed into vtwin. vts's log shows it received
`e c h $ S L`. Then `kill vtwin | rc`, and the launching bash's prompt
read:

```
$ o HEL
bash: o: command not found
```

**`o ␣ H E L`.** Six bytes plus five is eleven, no byte duplicated and
none lost: **the two readers PARTITION the input.** That is the
signature of two processes blocked in a read on the same file and
nothing else produces it -- a rendering fault would not conserve
bytes, and a dropped write would not deliver them somewhere else.

`ps` names them:

```
1778 Rendez bash    1779 Pread bash     apexp-sh's bash + its copy process
1867 Rendez bash    1868 Pread bash     a leftover pair
1919 Await  bash    1946 Pread bash     another leftover copy process
1964 Rendez bash    1965 Pread bash     the SESSION's shell + its own
```

**`Rendez` is a parent waiting in `_readbuf`; `Pread` is a copy process
inside `_READ` on the console.** Four of them, and only the 1964/1965
pair is legitimate. **Two pairs are leftovers from earlier runs** --
the same accumulation the `bash`-as-`/bin/sh` memory failure pointed
at, seen from the other side.

### The fix, designed here and NOT written in a hurry

`ap/plan9/_buf.c` is the most delicate file in libap and its history
is a list of races. So the design, with the hazards named, and the
code in its own round:

**Read ON DEMAND for a terminal, and only for a terminal.** Add a
`want` flag to `Muxbuf`. `_copyproc` waits for it before each `_READ`
instead of looping straight back; `_readbuf` and `select()` set it
when they actually want data, and it is **cleared on delivery**. One
outstanding read per request rather than a permanent one.

- *It fixes this case exactly*: bash's last read takes the newline,
  `want` clears, the copy process sleeps -- and it is asleep for the
  whole time bash sits in `wait()` while vtwin owns the console.
- *It is gated on `FD_ISTTY`* so pipes and sockets keep the greedy
  path. Tcl's suite drives those hard and there is no reason to
  re-measure it; a human types slowly, so a rendezvous per keystroke
  costs nothing.
- **The residue, stated rather than hidden**: a zero-timeout poll
  leaves one read outstanding, so a program that polls and then walks
  away can still take one keystroke. That is a bounded thief instead
  of an unbounded one, and going further means teaching `select()` to
  withdraw a request.
- **The hazard is deadlock**, and it is the reason this is not a
  five-minute change: the parent already rendezvouses on `datawait`
  for the copy process to fill the buffer, and adding a rendezvous the
  other way makes two, on the same pair of processes. Every arm has to
  be ordered so that "parent wants, copy is asleep" and "copy has
  data, parent is asleep" cannot both be believed at once.

**`execve` killing the copy processes is a separate, smaller fix** and
worth doing on its own terms -- after `_EXEC` the new image cannot
reach them -- but it does **not** cure this: the thief here is a
living parent that never exec'd.

### The fix, written

`Muxbuf` gains three fields, **appended after `data[]`** so every
existing offset is unchanged (`ondemand`, `want`, `readwait`);
`sizeof(Muxbuf)` still moves, so **`mk distclean` before `mk install`**.
`_bufmark()` is the version marker, so a test cannot link against the
old library and report a pass.

**The rule**: for `FD_ISTTY` buffers only, `_copyproc` sleeps at the
top of its loop unless `want` is set, and clears `want` the moment it
delivers. One outstanding read per request instead of one for ever.
Pipes and sockets keep the greedy path untouched -- Tcl's suite drives
those hard and there is no reason to re-measure them; a human types
slowly, so a rendezvous per keystroke costs nothing.

**`want` is STATE, not an event, and that is what makes the handshake
safe.** It is written and tested under `mux->lock`, so a request
arriving while the copy process is between its unlock and its
rendezvous is *seen* rather than lost -- the copy process simply does
not go to sleep. There is no window to miss.

**The deadlock this design could produce is "both asleep", and every
asking site prevents it the same way:** set `want` under the lock,
clear `readwait` under the same lock (so two callers cannot both try
to pair with one sleeper), release the lock, wake, and only then wait.
Three sites ask:

- `_readbuf`, in its empty-buffer branch, before setting `datawait`;
- `select()`, for every watched descriptor as it buffers them --
  **before `waitfresh`**, which would otherwise spin its 10ms against
  a copy process that is deliberately asleep and answer "not ready"
  for ever;
- `wantdata()` itself returns early when `b->n > 0 || b->eof`, so
  asking when the answer is already in hand cannot cause a read.

**An interrupted rendezvous falls through to the read** -- the old
greedy behaviour, which is the safe direction for a note arriving at
the wrong moment.

`_startbuf` resets all three on a recycled slot, for the reason the
`roomwait`/`datawait` note beside it already gives: a slot inheriting
`readwait` has a sleeper that died with the previous descriptor.

**The regression test is the partition itself**, and it is exact: type
`echo $SHELL` into vtwin, quit with `kill vtwin | rc`, and look at the
launching bash's prompt. **Eleven bytes must reach the session and the
prompt must be empty.** Anything in that prompt is a byte the copy
process took. That is a better test than any assertion I could write,
because it conserves bytes -- a partial fix shows up as a shorter
theft rather than as a pass.

### CONFIRMED on the first run

`echo $SHELL` typed into vtwin, with the launching shell an ordinary
interactive **bash** -- the thief itself, deliberately, rather than
`apexp-sh -r`:

```
cons write (from viewer) 1 [e]   tty read: HANDED 1 [e]   tty write 1 [e]
                         1 [c]                    1 [c]                1 [c]
                         1 [h] [o] [ ] [$] [S] [H] [E] [L] [L] [<0a>]
tty write 4 [bash]
```

**Eleven for eleven**, and `kill vtwin | rc` left the outer bash's
prompt **empty**. Nothing was taken.

*The test conserves bytes, which is what makes it worth more than an
assertion*: a fix that only narrowed the race would have shown up as a
shorter theft in that prompt, not as a pass. There was no theft.

No deadlock, no hang, and the session is responsive -- so the
"both asleep" arm the design was most exposed to did not fire, on the
path that exercises it hardest (a read per keystroke, each one finding
the buffer empty and waking a sleeping copy process).

**What is NOT shown by this run**: the pipe and socket paths, which
keep the greedy behaviour and are untouched by the `FD_ISTTY` gate.
Tcl's suite is where those live, and it has not been re-run since.
That is the honest gap, and it is a cheap one to close the next time
the suite runs.

## malloc/ — the heap watchdog, and what the bash Brk storm is not

`$APEXP_MALLOCMAX`, in megabytes, off unless set. It exists because
of the bash-as-`/bin/sh` failure, and the reason it is a *library*
change rather than a bash one is worth stating first.

### The log localised the storm to one burst, and excluded every I/O mechanism

`ratrace /bin/bash run-all >[2] /tmp/rt.log` gave 3458016 lines.
Numbering the non-`Brk` ones — `grep -n -v ' Brk ' /tmp/rt.log |
tail -40` — put the whole storm in one place:

```
   1581:5875 bash Stat 265107 ... "/proc/5875/wait" ... = 71
3458015:5875 bash Noted 2d10a7 1 = 0
3458016:bash 5875: suicide: sys: trap: fault read addr=0x0 pc=0x0
```

`3458015 - 1581 = 3456434`, against 3456769 `Brk` lines in the whole
run. **99.99% of the storm is a single uninterrupted burst**, so it is
one event and not something accumulating over the suite. That alone
retires the "leak with a shape" framing that six rounds used.

The prediction was written before the grep: the gap would open after
the `Pread` of fd 255 and close at the `Noted`, and a gap sitting
*before* the `Await` would put `wait4`'s WNOHANG path back in frame.
Line 1580 is that `Pread`, 1573 is the `Await`, and the gap opens
after both. Confirmed; refutation did not fire.

**The stronger fact is what the gap does NOT contain: any system call
at all.** That is an exclusion rather than a description —

| a loop that... | would show | appears? |
|---|---|---|
| spins on a read | `Pread` | no |
| spins waiting for a child | `Await`, `Stat` | no |
| retries a create | `Open`, `Create` | no |

so the loop is pure computation. It allocates and never frees, and
makes no syscall but the allocator's own.

**`read_comsub` is refuted by that same fact**, which matters because
it was the obvious next suspect: `subst.c:6680` calls `zread` on every
buffer refill and grows `istring` with `RESIZE_MALLOCED_BUFFER`
(doubling `realloc`). A loop there shows `Pread` lines and a handful
of large allocations. Neither is present. **Five mechanisms have now
been argued from source in this hunt — a descriptor leak, `_buf.c`'s
copy processes, `wait4`'s `_dirstat`, `pc=0x0`, `read_comsub` — and
the log has refuted all five.**

### malloc and free were CHECKED, not assumed innocent

- `free()` (`malloc/free.c:31`) sets `magic = 0` and pushes the block
  straight onto `btab[bp->size]`, so the free list does refill. There
  is no path by which a freed small block fails to come back.
- The size class is measured, not guessed: `sizeof(Bucket)` is 24, so
  `BLKSZ(4) = (24+16+15) & ~15 = 48`, and `n = (CUTOFF-4)+2 = 10`
  gives `48 * 10 = 480` — exactly the step the trace shows the break
  taking. Two `Brk` per `_malloc_brk` (`sbrk(0)` then `sbrk(gap+n)`),
  so ~1.73M calls, ten objects each: **about 17 million live
  allocations of ≤ 16 bytes.**
- The batching loop links all nine spare blocks correctly (`nbp`
  walks blocks 1..9, block 0 is returned and gets its `size`/`magic`
  after the unlock).

So the allocator is doing what it is told. The objects are genuinely
live and it is a bash loop. The trace places it after `run-all`'s line
21 — line 1563 shows the `$( )` child writing `"30465"` to fd 1, which
is `$RANDOM + $BASHPID`, so **the child ran and succeeded**; whatever
loops is in the parent, after the reap.

### Why six rounds found nothing: `Insufficient physical memory` is a KILL

This is the part worth keeping regardless of what the bash bug turns
out to be. The kernel *destroys* the process — there is no stack to
take, nothing for `acid` to attach to, no core. Every round of this
hunt was an examination of a corpse the kernel had already disposed
of, and the only evidence obtainable was a 272 MB trace of the one
syscall the loop happened to make.

**So the instrument's job is to fail earlier and more politely than
the kernel does.** With `APEXP_MALLOCMAX=64` a runaway breaks after
64 MB instead of ~800, the process is *Broken* rather than gone, and

```
acid <pid>
stk()
```

names the calling function. That is exactly how gnulib's
self-recursive `strerror` and `_buf.c:544` were both settled after
source reading had failed on them.

### The implementation, and the three things it has to get right

1. **It counts BOTH sbrk sites.** `_malloc_growtop` does `sbrk(0)`
   then `sbrk(want-have)` — the same two-`Brk` signature as
   `_malloc_brk` — so a trace cannot tell them apart, and a watchdog
   watching only one could report a flat heap while the break ran
   away. Same family as *a measurement of the wrong process is not a
   null result, it is a false one*.
2. **Nothing on the path can re-enter malloc.** `getenv` is a plain
   scan of `environ` (`ap/env/getenv.c` — no allocation, checked
   rather than assumed), and the message is built with a hand-rolled
   `wd_num` and written with `write(2, ...)`, which is
   `plan9/_apdbg.c`'s idiom for this exact reason. The `\r\n` is
   there for `_apdbg`'s reason too: since `tcsetattr` started
   working, fd 2 is often a raw terminal.
3. **`wd_fail` unlocks the arena before `abort()`.** `_malloc_brk` is
   called with `__malloc_arena` held; `abort()` runs the signal
   machinery, which may allocate, and doing that under our own lock
   would deadlock — giving a *hang* where a *break* was wanted. The
   process is dying either way, so releasing it first costs nothing.

Off unless set: one load and one branch per sbrk, next to two system
calls. Verified on the host by extracting the block into a standalone
program — clean under `-Wall -Wextra`, fires on the 65th MB with a
64 MB limit, and `wd_calls = 0` after 3000 calls with the variable
unset.

### `sys/lib/tests/bash-comsub-test.sh`, the cheap half

The watchdog needs a rebuild; the bisect does not. Ten sections of
`run-all`'s lines 17–27, each writing a durable marker to
`/tmp/comsub.log` **before** the statement it is about to run, so the
last line in the log names the statement that did not return. Ordered
simplest first, because *every case expected to return must come
before every case expected to hang*.

It forks nothing except in the sections that are about forking —
`echo` is a builtin and `>>` a redirection. That is deliberate: the
same instrument-perturbs-subject mistake was made by `fdwatch` (six
forks per sample against a subject that lived under a second), by
`bash-fdloop-test`'s `expr` counter, and by the same file's `wc -l`
inside `$( )` *in a test about what forking costs*. Three times in
one investigation.

All ten sections return on glibc in 13 ms, which is what makes a
stall on 9front attributable.

### The watchdog's first version broke every APE program, and the reason generalises

It read `$APEXP_MALLOCMAX` lazily on the first `sbrk`. I checked the
question that seemed to matter — *does `getenv` allocate?* — and it
does not; `ap/env/getenv.c` is a plain scan of `environ`.

**That was the wrong question.** `environ` is created BY a malloc:

```c
/* plan9/_envsetup.c:140 */
environ = pp = malloc((1+cnt)*sizeof(char *));
```

So on the **first allocation of every APE program** `environ` is still
null, and getenv has no null check — `char **p = environ; while (*p !=
NULL)` faults at address 0, before `main`. Every APE binary relinked
against that libap died on startup:

```
bash 2487: suicide: sys: trap: fault read addr=0x0 pc=0x263312
```

*It is not a re-entrancy bug. It is a **circular dependency**: the
allocator asked for state that the allocation was being made to
create.* The general form is worth carrying past this instance:

> **"Does it allocate?" is only half of "is it safe to call from the
> allocator". The other half is "does it depend on anything that was
> allocated?" — and for a libc global, the answer is usually yes.**

`_malloc_watchinit()` is now called from **`_apemain`, immediately
after `_envsetup()`** and before `main`. That is the same "one path
every APE program takes" argument that put `argv0` in `callmain.c`.
The allocator now calls nothing at all and only tests a static;
allocations before that point go unwatched, which is the safe
direction to be wrong in. A defensive `environ == 0` test stays in
`_malloc_watchinit` anyway, because the cost is one branch once.

Verified on the host across all three paths before shipping: the
null-`environ` call returns harmlessly, `wd_calls` is **0** after 3000
notes before init (so an unwatched program pays nothing), and with
`APEXP_MALLOCMAX=64` it still fires on the 65th MB.

**This is the fifth time in this one investigation that the instrument
was the visible fault** — fdwatch's sampling period exceeding its
subject's lifetime, fdwatch's `-n` taking the copy process,
`bash-fdloop-test`'s `expr` control that forked, the same file's
`fdcount` forking inside a test about forking, and now this. The tally
is not an accident: every one was an instrument sharing state or
resources with the thing it measured.

**Operational note that cost the user a reboot attempt: a Broken
process KEEPS ITS MEMORY.** `acid` needs the process alive, so the
watchdog deliberately leaves it Broken — but a few aborted 64 MB runs
will exhaust a small VM by themselves. Kill each one after taking the
stack.

### What the one run that did happen says about bash: `ifs_value` is not a pointer

Whatever its provenance, the `acid` stack is specific:

```
bash 1764: suicide: sys: trap: fault read addr=0x2e pc=0x2310ad
list_string(separators=0x428891, quoted=..., string=0x486eb0)  subst.c:3133
expand_word_internal(...)                                      subst.c:12072
  ifs_chars=0x2e
call_expand_word_internal          subst.c:4285
expand_string_assignment           subst.c:4377
expand_string_to_string_internal   subst.c:3855
expand_assignment_string_to_string subst.c:3881
assign_in_env                      variables.c:3598
do_assignment_statements           subst.c:13156
expand_word_list_internal          subst.c:13261
expand_words                       subst.c:12571
execute_simple_command             execute_cmd.c:4617
```

- `subst.c:12072` is `list = list_string (istring, "", quoted);`, so
  `separators` is the string literal `""` — and `0x428891` is a
  plausible text address, so that argument is fine.
- `subst.c:3133` is `for (xflags = 0, s = ifs_value; s && *s; s++)`.

So the faulting dereference is **`*ifs_value`, with `ifs_value` holding
`0x2e`** — the byte `'.'` sitting in a `char *`. The caller's own
`ifs_chars=0x2e` agrees, and `setifs` (subst.c:12309) sets
`ifs_value = (v && value_cell (v)) ? value_cell (v) : " \t\n"`, neither
arm of which can yield 46. Declarations are consistent — `extern char
*ifs_value` at `subst.h:353`, `char *ifs_value` at `subst.c:161` — so
this is runtime corruption rather than the kencc prototype/width family.

**Why it is worth chasing: one corruption would explain both symptoms.**
With `ifs_value` garbage, `list_string` either faults on it (this run)
or, when the garbage happens to address readable bytes, splits its
input into an enormous number of words — and each word is a retained
`WORD_DESC` plus a `WORD_LIST` node, both small, both live until the
list is freed. **That is precisely the storm's signature: ~17 million
live objects of ≤ 16 bytes, no syscall anywhere in the loop.** It is
also the same code path the line numbers had already localised the
storm to: assignment expansion, immediately after line 21's `$( )`.

**Provenance is unsettled and must be settled before anything is built
on it.** The broken libap faults at 0x0 before `main`, yet 1764 reached
`reader_loop` — so 1764 was most likely a bash predating that install,
which would make the stack clean evidence about bash rather than about
the patch. *That is an inference from two observations, not a
measurement.* Re-run it on the fixed tree; if the same stack returns,
it is bash's.

### abort() allocates on Plan 9, so the watchdog re-fired inside its own abort

With the `_apemain` fix in place bash starts again, and the first real
run of the watchdog produced an `acid` stack that was nothing but its
own recursion:

```
wd_fail()             malloc.c
_malloc_brk(n=0x1e0)  malloc.c
malloc()              malloc.c
open(flags=0x1, path=...)  fcntl/open.c:76
note(fmt=..., msg=...)     signal/kill.c:16
kill(sig=0x5, pid=...)     signal/kill.c:58
abort()                    stdlib/abort.c:8
wd_fail()                  <- round again
```

`abort()` raises SIGABRT; libap's `kill()` posts a note; `note()`
opens `/proc/<pid>/note`; and `open()` calls `malloc`. The allocator
is therefore re-entered *from inside its own abort*, still over the
limit, and fires again — thousands of times, printing the message
thousands of times and burying the one stack the instrument exists to
expose.

**The galling part is that the comment two lines above already said
it.** `wd_fail` unlocks the arena before aborting, and the reason
written there is "abort() runs the signal machinery, which may
allocate". Having established that, I guarded against the *deadlock*
and not against the *recursion*. Knowing a fact is not the same as
following it to its second consequence.

The fix is one statement, first in the function:

```c
	wd_max = 0;	/* disarm before aborting; abort() allocates */
```

Every later `wd_note()` then returns 0, the abort path allocates
freely, and the message prints once. Verified on the host against a
deliberately allocating `abort()`: one entry, one message, no
recursion.

**A free confirmation in the same stack**: `_malloc_brk(n=0x1e0)` —
0x1e0 is **480**, exactly the step derived from the ratrace break
addresses, and `BLKSZ(4) * ((CUTOFF-4)+2) = 48 * 10 = 480`. The size
class was inferred from a log; here it is read directly off a live
frame.

### The bisect answered by producing no log at all

`/bin/bash bash-comsub-test.sh` gave the two fd warnings, died
`Insufficient physical memory`, and then:

```
cat: /tmp/comsub.log: No such file or directory
```

The log's first line comes from `mark "bash-comsub-test: pid $$"`,
which is the script's first statement. **The file does not exist, so
bash never ran one line of the script.**

That is a real measurement and it retires the bisect's own premise:
the storm is **not** in `run-all`'s lines 17–27, and none of the ten
sections is the trigger. It sits in bash's startup, or in its very
first statement. Two things already on record agree:

- the histogram's `2 Rfork, 1 Exec` — the process died before the
  suite could run anything;
- the fd warnings printing *before* the script's first line, which was
  attributed to `move_to_high_fd` at startup.

**And it hands over a discriminator that was not asked for:
interactive bash works.** The prompt all of these commands were typed
at is bash, and it is healthy; it is non-interactive `bash <script>`
that dies. So the next reduction is not a script at all:

```
APEXP_MALLOCMAX=32 /bin/bash -c 'echo hi'
```

If that storms, the reproducer has gone from an 83-file test suite to
a single command with no file, no fork and no expansion worth the
name — and the stack taken off it is the smallest this bug can
produce. If it does *not* storm, the difference between it and a
script file is the next thing to bisect, and that is a much smaller
space than bash.

### `bash -c` is clean, and that leaves a very small space

```
$ APEXP_MALLOCMAX=32 /bin/bash -c 'echo hi'
hi
```

No storm, and — the part that was not asked for — **no fd warnings
either**. The `exceeds 100 file descriptors` / `exceeds 200` pair that
has accompanied every failing run did not appear. So the warnings and
the storm arrive together and vanish together.

That does not make them one story; they can still be two effects of a
single cause, which is what `move_to_high_fd()` on the script
descriptor would produce. But "present together, absent together" is a
real constraint where before there was only "printed together", and
the earlier note in this file explicitly refused to treat them as one
thing on the strength of co-printing alone. It can now be treated as a
live hypothesis rather than a conflation.

**The remaining space is the difference between `-c` and a script
file.** `rc/bin/bash-scriptladder` walks it:

| | how bash is started | what it isolates |
|---|---|---|
| 1 | `-c 'echo hi'` | control, known clean |
| 2 | an **empty** file | script-file setup with no parsing at all |
| 3 | a one-line file | same content as 1, through a named file |
| 4 | `< one-line file` | reads a script, but no filename |

- **2 storms** → parsing and execution are innocent; it is opening and
  setting up a script file, which is where fd 255 and
  `move_to_high_fd()` live. That is about as small as a target gets.
- **2 ok, 3 storms** → parsing or executing from a file.
- **3 storms, 4 ok** → the *named file* specifically, not reading a
  script as such.
- **3 and 4 both** → reading a script at all, however supplied.
- **nothing storms** → it needs something `bash-comsub-test.sh` has
  and these do not, and the thing to bisect next is that file's
  header, not its sections.

**It is an rc script on purpose.** The subject dies, and a harness
written in the dying shell dies with it — which is exactly how
`bash-comsub-test.sh` came back with an empty answer. rc survives every
case, so one run yields all four verdicts; each case prints a
`returned` line after it, and a missing one names the case that
stormed. Straight-line, no loop (rc has no `break`), no `^`, and the
only `=` are leading assignments, which rc permits — it is `key=value`
as an *argument* that is a parse error.

**No watchdog in the ladder, deliberately.** Classification only needs
`hi` versus a death message. Setting `APEXP_MALLOCMAX` would leave a
Broken process holding 32 MB *per failing case*, and four of those
would flatten the VM before the ladder finished. Re-run only the
smallest storming case with the watchdog, take `stk()`, then
`echo kill > /proc/<pid>/ctl`.

### The ladder ran, nothing stormed, and the fd warnings are now separated

```
1  bash -c 'echo hi'      hi         no warnings   returned
2  an EMPTY script file   (nothing)  WARNINGS      returned
3  a one-line file        hi         WARNINGS      returned
4  the same on stdin      hi         no warnings   returned
```

Two results, and the second is a correction of my own claim from the
round before.

**The storm is not the script file.** Not parsing, not a named file,
not reading a script at all. Every way in came back.

**And the fd warnings are separated from the storm — which refutes
"present together, absent together".** After `bash -c` returned with
neither, I wrote that the warnings and the storm arrive together and
vanish together, and allowed that as a real constraint where
co-printing had not been. Case 2 breaks it as cleanly as anything
could: an **empty** script file — no parsing, no commands, nothing to
execute — raises `exceeds 100 file descriptors` and `exceeds 200`, and
then **exits successfully**.

So:

- they are `move_to_high_fd()` on the script descriptor, which is what
  they were predicted to be two rounds ago;
- they are produced by the **named file** and by nothing else here
  (stdin and `-c` are both silent);
- **they are harmless.** A run that warns has told you nothing about
  whether it will die.

*The progression is worth keeping as a shape: conflated → linked on
weaker evidence than it looked → separated by one measurement, each
step taking one round.* The middle step is the dangerous one, because
"absent together" felt like data and was a sample of one.

### What every clean case has in common: none of them forks

`echo` is a bash builtin. Cases 1, 3 and 4 run it inside the shell;
case 2 runs nothing at all. Four clean results, zero forks.

Every case that *has* stormed forks:

| | the fork in it |
|---|---|
| `run-all` | line 21, `SUFFIX=$( ${THIS_SH} -c ... )` |
| `bash-comsub-test.sh` | its third statement, `rm -f $LOG` |
| `bash-fdloop-test.sh` | 400 iterations of fork/exec/wait |

and the ratrace histogram over the whole dying run was `2 Rfork,
1 Exec`, with the storm beginning immediately after the one child was
reaped.

`rc/bin/bash-forkladder` asks it, in the same rc harness:

| | |
|---|---|
| 1 | `-c '/bin/echo hi'` — one fork + exec + wait, no file |
| 2 | `-c 'v=$(/bin/echo hi); echo $v'` — fork + pipe + read + reap |
| 3 | a file containing an external echo |
| 4 | a file containing a substitution — run-all's line 21 |
| 5 | `bash-comsub-test.sh`'s first four statements, verbatim in shape |

Reading it: **1 storms** → one fork is enough and the reproducer is a
single command with no file; **1 ok, 2 storms** → it is command
substitution rather than forking, so the pipe, the read of the child's
output, or the reap; **3 or 4 only** → the file and the fork are both
needed, which points at fd 255 interacting with the fork; **only 5** →
bisect its four statements (assignment, external command, function
*definition*, call).

**Case 5 is what keeps the ladder honest.** If even it returns and
writes its log, then the failure has stopped reproducing since
`bash-comsub-test.sh` last died, and everything reasoned above is
about a bug that is no longer present — which is worth discovering in
the same run rather than after another round of reduction.

All five return on glibc, and case 5 writes its log there.

### The fork hypothesis is refuted, and case 5 alone storms

```
1  -c with an EXTERNAL echo        hi            returned
2  -c with a COMMAND SUBSTITUTION  hi            returned
3  a FILE with an external echo    hi            returned
4  a FILE with a substitution      hi            returned
5  bash-comsub-test.sh's opening   KILLED, no log
```

I predicted forking was the discriminator, on the grounds that none of
the four clean cases in `bash-scriptladder` forked while everything
that had ever stormed did — and wrote the refutation condition down.
**It fired.** Cases 1 to 4 fork, exec, build a pipe, read a child's
output and reap it, from `-c` and from a named file, and every one
returned.

That is four mechanisms cleared in one run, which is what a ladder is
for. And case 5 still dying is the other half of the result: the bug
has not evaporated under the rebuilds, so everything reduced so far is
still about a live failure.

### What case 5 has that case 4 has not

```sh
LOG=/tmp/bfl5.log
rm -f $LOG
mark() {
	echo "$*" >> $LOG
}
mark reached-the-first-mark
```

Five candidates: an external command taking a **variable-expanded**
argument (case 1 used a literal); a function **definition**; a
function **call**; a `>>` redirection **inside a function**; and
**`"$*"`**.

**`$*` is the suspect, and not by taste: it is the only construct in
case 5 that reads IFS.** It joins the positional parameters with IFS's
first character, through `string_list_dollar_star` (`subst.c:2900`):

```c
  if (ifs_firstc_len == 1)
    { sep[0] = ifs_firstc[0]; sep[1] = '\0'; }
  else
    { memcpy (sep, ifs_firstc, ifs_firstc_len); sep[ifs_firstc_len] = '\0'; }
  ret = string_list_internal (list, sep);
```

Nothing in cases 1 to 4 touches IFS at all.

**And that is where the one stack this hunt has produced already
pointed.** Two rounds ago the watchdog caught a bash mid-flight and
`acid` gave `fault read addr=0x2e` at `subst.c:3133`, which is
`s = ifs_value; s && *s` — **`ifs_value` holding `0x2e`, a `'.'` in a
`char *`.**

*Two independent lines arriving at IFS from opposite directions: a
stack that faulted on `ifs_value`, and a ladder whose only storming
case is the only one that reads it.* The convergence is worth more
than either on its own, and it also makes the unsettled provenance of
that stack much less load-bearing — it no longer has to be trusted
alone.

### `rc/bin/bash-ifsladder`

Case 5 split into its parts, IFS last:

| | | |
|---|---|---|
| 1 | `${#IFS}` | **direct probe**, pure builtin; a healthy bash says **3** |
| 2 | `rm -f $X` | external command with a *variable* argument |
| 3 | `f() { :; }` | function definition, never called |
| 4 | `f(){ echo hi;}; f` | defined and called |
| 5 | `f(){ echo hi >> $L;}; f` | `>>` inside a function |
| 6 | `set -- a b c; echo "$@"` | joins *without* IFS |
| 7 | `set -- a b c; echo "$*"` | **joins WITH IFS** |
| 8 | case 5 unchanged | the control |

Case 1 is the cheapest thing in the whole investigation: if it answers
anything but 3, IFS is already corrupt before a single command runs
and `setifs` (`subst.c:12303`) is where to look, with no reduction
needed at all.

**`$@` is asked beside `$*` deliberately.** They differ in exactly the
property under suspicion — `$*` joins with IFS's first character, `$@`
does not join — so both dying means IFS reading generally while `$*`
alone dying isolates the join. Asking only one would leave a negative
result with two explanations, which this tree has a named rule about.

All eight return on glibc and case 1 answers 3.

### IFS is refuted, and the one stack turns out to show a victim

```
1  ${#IFS}                      3        returned
2  external with a VARIABLE arg hi       returned
3  function DEFINITION          hi       returned
4  function defined AND CALLED  hi       returned
5  >> inside a function         hi       returned
6  "$@" at top level            a b c    returned
7  "$*" at top level            a b c    returned   <- reads IFS
8  the same thing in a FILE     KILLED, no log
```

`${#IFS}` is **3**, and `"$*"` joins to `a b c`. So IFS is intact and
the one construct in case 8 that reads it works perfectly through
`-c`. That was the suspect, it had two independent lines pointing at
it, and it is wrong.

**The more valuable half is what this does to the `acid` stack.** The
watchdog's catch was:

```
fault read addr=0x2e
list_string(...) subst.c:3133   -- s = ifs_value; s && *s
```

`ifs_value` holding `0x2e`, a `'.'` in a `char *`. If reading IFS is
healthy in isolation — and case 7 says it is — then **memory was
already corrupt by the time that frame executed.** *The stack shows a
victim, not a culprit.* Something had written a character into a
pointer in BSS; `list_string` was simply the next code to read it.

Two consequences worth keeping:

- **Chasing `setifs` would have been chasing the wrong end.** The
  value was not computed wrongly, it was overwritten.
- **The convergence I trusted was two lines pointing at the same
  casualty.** A stack that faults on X and a ladder whose only
  storming case reads X look like corroboration, and are not, when X
  is downstream of the real event. *Corroboration requires the two
  lines to be independent of each other, not merely to arrive at the
  same symbol.*

It also means the earlier provenance question is moot: whichever
binary produced that stack, it was showing damage rather than cause.

### The untested difference: a command that spans lines in a file

Every `-c` case passes. Every file case so far passed too — an empty
file, a one-line file, a file with a command substitution. So it is
not "a file" as such.

**But every file tested held one-line commands, and case 8's function
definition spans three:**

```sh
mark() {
	echo "$*" >> $LOG
}
```

A multi-line compound command is the first thing in this whole
investigation that makes bash's *parser* ask its input for more while
a command is still open — `shell_getc` refilling `shell_input_line`
from fd 255 with a partial command held. Through `-c` the text is
already in memory and that path is never entered. It is the one
structural difference left and it has not been asked once.

`rc/bin/bash-fileladder`, all from files:

| | |
|---|---|
| 1 | a **one-line** function, called |
| 2 | the same function over **three lines** ← the new variable |
| 3 | multi-line, body `echo "$*"` |
| 4 | multi-line, body `echo hi >> $L` |
| 5 | a multi-line **`if/then/fi`** — compound, but not a function |
| 6 | case 8 unchanged, as the control |

**Case 5 is what makes this a bisect rather than a guess.** If a
multi-line `if` storms, functions are cleared entirely and the subject
is the parser's refill; if it does not and case 2 does, the opposite.
Asking only the function form would leave that undecided — the same
reason `$@` was asked beside `$*`, and the same reason that pairing
paid off here by showing `$*` innocent rather than merely unproven.

Indentation is a tab everywhere, as case 8's was, so it is not a
hidden variable between cases. All six return on glibc.

### It is a command that spans a newline in a script file

```
1  a ONE-LINE function in a file       hi      returned
2  the same function over THREE lines  KILLED
3  multi-line + "$*"                   KILLED
4  multi-line + >>                     KILLED
5  a multi-line if/then/fi             KILLED   <- NOT a function
6  case 8 unchanged                    KILLED
```

**Case 5 is what carries it.** A compound command that is not a
function, dying exactly like the rest — so functions are cleared
entirely, and with them `$*`, `>>`, the variable-expanded argument and
the external command. Every one of those was a live suspect an hour
ago and all four went in a single run, which is what the case was put
there for.

The discriminator is the one thing cases 2–6 share and case 1 does
not: **a newline inside a command.** That is the first construct in
this whole investigation that makes bash's input layer deliver more
text *while a command is still open*. `-c` holds the program in memory
and never enters that path; a file containing only one-line commands
never needs it either — which is exactly why every earlier file case
passed and why the storm looked, for two rounds, like it had nothing
to do with files.

**Seven mechanisms have now been refuted by measurement** — a
descriptor leak, `_buf.c`'s copy processes, `wait4`'s `_dirstat`,
`pc=0x0`, `read_comsub`, forking, and IFS — at one run each. Every one
of them was argued from source first.

### The last question that changes which file to read

"Spans a newline" has two quite different implementations behind it:

- **the LEXER wants another line** — a backslash continuation or an
  unterminated quote. `shell_getc` (`parse.y:2475`) refills
  `shell_input_line` and the *grammar* never sees an incomplete
  command at all.
- **the PARSER wants another line** — an open compound command (`if`,
  `{`, a function body, a dangling `|`). The grammar is mid-rule and
  the newline arrives as a token.

They are different code and a fix would be in different files, so
`rc/bin/bash-lineladder` spends one run on it before any reading:

| | | |
|---|---|---|
| 1 | `echo hi \` + `there` | lexer only |
| 2 | `echo "a` + `b"` | lexer only |
| 3 | `{` / `echo hi` / `}` | parser, simplest compound |
| 4 | `echo hi \|` + `cat` | parser, no compound at all |
| 5 | `if/then/fi` | the known-storming control |

**1 or 2 storming** puts it in the lexer's refill — `shell_getc` and
`input.c` — and shrinks the reproducer to two lines. **Only 3, 4 and
5** puts it in the parser holding an incomplete command. **All of
them** is the broadest statement: any second line while anything is
open.

All five return on glibc.

### And then the stack

This is what the watchdog was built for, and it is finally cheap
because the subject is four lines rather than an 83-file suite:

```
APEXP_MALLOCMAX=32 /bin/bash /tmp/bli-5.sh
ps | grep bash                  # find the Broken one
acid <pid>                      # stk()
echo kill > /proc/<pid>/ctl     # a Broken process KEEPS its memory
```

The ladder itself is deliberately unarmed: five armed cases would
leave five Broken processes holding 32 MB each.

### Not any newline: a newline token inside an open COMPOUND command

```
1  backslash continuation   (lexer)   hi there   returned
2  a quote across a newline (lexer)   a / b      returned
3  a { ... } group          (parser)  KILLED
4  a pipeline broken after| (parser)  hi         returned
5  if/then/fi               (parser)  KILLED
```

**Case 4 carries it.** `echo hi |` followed by `cat` spans a newline,
the parser genuinely wants another line to finish the command, and it
**returns**. So "bash's input layer delivering more text while a
command is open" — last round's conclusion — is cleared too, along
with the lexer's refill (cases 1 and 2).

What survives is narrow: **`{ }` and `if/fi`**. The difference from
the three clean cases is what happens to the newline itself:

| | the newline is |
|---|---|
| 1 backslash | removed by the lexer |
| 2 quote | absorbed into the string |
| 4 after `\|` | skipped — bash eats newlines after `\|` |
| 3, 5 | **a token the grammar sees**, inside an open compound |

And a one-line compound is fine: `bash-fileladder`'s case 1 was
`f() { echo hi; }` — a `{ }` group on one line — and it returned.

**Eight mechanisms refuted by measurement**, one run each: descriptor
leak, copy processes, `wait4`, `pc=0x0`, `read_comsub`, forking, IFS,
and now both the lexer refill and the parser's "wants another line".
The reproducer is three lines.

Left open, and cheap once the stack is in hand: whether it is the
**reserved word** or the **compound command**. A multi-line subshell
`( ... )` splits them — compound, but no reserved word.

### The watchdog could never have left a Broken process

The limit fired exactly as designed:

```
libap: APEXP_MALLOCMAX exceeded: 33554656 bytes from the break in
72507 sbrk calls; aborting so a stack can be taken
```

and then the process was **gone**. `ps | grep bash` showed only the
interactive shell and its copy process; `acid 13576` answered
`can't open /proc/13576/text: file does not exist`.

Plan 9 note semantics account for it exactly, and the code is three
lines:

- `abort()` is `kill(getpid(), SIGABRT)` (`stdlib/abort.c:8`);
- that posts a note whose string is an ordinary word;
- libap does not handle it, so `signal/signal.c:102` reaches
  `_NOTED(1)` — NDFLT;
- **the kernel's default for a plain note is to EXIT.** Only a note
  beginning `sys:` — a real trap — makes a process *break* and stay
  for a debugger.

So the instrument promised a Broken process that its own mechanism
could not produce. The earlier `fault read addr=0x2e` stack existed
only because that was a genuine `sys: trap:` note.

**`wd_fail` now sleeps instead.** It disarms, prints the message with
the pid twice — once to attach, once to kill — and naps for up to
fifteen minutes before `_EXITS`.

Faulting on purpose (`*(int*)0 = 0`) would also break the process, and
was the obvious alternative. Sleeping is better for a reason worth
keeping: **it removes note semantics from the instrument altogether.**
A deliberate fault still depends on NDFLT behaving as expected and on
whatever SIGSEGV handler the subject happens to have installed —
exactly the class of assumption that just cost a round. `acid`
attaches to a *live* process perfectly well; that is how `_buf.c:544`
was found in this tree. And `ps` shows the subject sitting in `Sleep`
instead of having to be caught in flight.

The fifteen-minute bound is so a forgotten run releases its memory by
itself. The `_SLEEP` and `_EXITS` prototypes are copied character for
character out of `ap/include/sys9.h` rather than recalled, because
kencc widens an argument at the call site only when a prototype is
visible — a remembered signature is a corrupted argument.

*Seventh time the instrument has been the visible fault.*

### The stack, at last: the LEXER hands the parser endless WORDs

The sleeping watchdog did its job — `ps` showed `33540K Sleep bash`,
`acid <pid>` attached to a live process, and `stk()` gave:

```
_SLEEP(a0=0x3e8)+0xe                  ap/syscall/_SLEEP.s:6
wd_fail()+0x19e                       ap/malloc/malloc.c:195
_malloc_brk(n=0x1e0)+0x65             ap/malloc/malloc.c:261
malloc()+0xe7                         ap/malloc/malloc.c:361
xmalloc(bytes=0x10)+0xe               external/bash/xmalloc.c:104
make_word_list(word=0x247a760, wlink=0x247a730)+0x55   make_cmd.c:156
make_simple_command(command=0x489370, line=0x2, element=0x247a760)+0x4a
                                      make_cmd.c:488
yyparse()+0x1c13                      y.tab.c:2629
parse_command()+0x5d                  eval.c:369
read_command()+0x92                   eval.c:414
reader_loop()+0xe9                    eval.c:147
main(argc=0x2, ...)                   shell.c:836
```

**`y.tab.c:2629` is inside case 62:**

```c
  case 62: /* simple_command: simple_command simple_command_element */
      (yyval.command) = make_simple_command ((yyvsp[0].element),
                                             (yyvsp[-1].command), line_number);
```

— the rule that appends *another word* to an existing simple command.
Case 61 is the same call with `(COMMAND *)NULL` for the command, and
the frame shows `command=0x489370`, **non-null**, so the sample is
unambiguously case 62.

**Therefore `yylex` is returning an endless stream of WORD tokens.**
The parser is behaving correctly: given word after word it keeps
extending one simple command, allocating a `WORD_LIST` node each time.
`xmalloc(bytes=0x10)` is 16 bytes — `sizeof(WORD_LIST)`, two pointers
— which is exactly the `<= 16 byte` size class derived from the
`sbrk` deltas in the ratrace log.

**Those two routes are genuinely independent**, which the last
"convergence" was not: one is arithmetic over break steps in a dead
process, the other an argument in a live frame. Nothing downstream
links them.

**Calibration.** Three rounds ago, reasoning from the `ifs_value`
fault, I wrote that the storm would be *"millions of words — and
every word is a retained `WORD_DESC` plus `WORD_LIST` node, small and
never freed"*. The **object** was right and the **producer** was
wrong: `list_string` versus the parser. *Predicting the artefact
correctly is not predicting the code that makes it*, and the two
should be scored separately.

**So the subject is now the lexer**, and it has to explain a very
specific shape: endless WORDs when a compound command spans a
newline in a file, and clean termination for a backslash
continuation, a quote across a newline, a dangling `|`, and every
one-line command. `shell_getc` (`parse.y:2475`) and the buffered
reader in `input.c` are the two places left, and the lexer's line
state is all `size_t` (`shell_input_line_index`, `_len`, `_size`) with
`shell_input_line_terminator` an `int`.
