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
