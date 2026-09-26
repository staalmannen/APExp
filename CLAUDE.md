# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What This Is

APExp (APE with experimental patches) is an enhanced ANSI/POSIX compatibility layer for Plan9/9front. Its goal is maximal GNU/POSIX compatibility — the pragmatic opposite of Plan9's NIH philosophy — so that C programs written for UNIX can be built on Plan9 with minimal modification.

**Important:** APExp is intentionally unstable between releases. Breaking changes are expected between releases; the best option for users is to download the latest release.

## Build System

The build tool is `mk` (Plan9's native make equivalent). Mkfiles use rc shell syntax, not POSIX sh.

```sh
# Full build and install (run from repo root, on Plan9/9front)
mk install

# Clean build artifacts
mk clean

# clean, plus everything installed into $objtype/bin and $objtype/lib
mk distclean

# Nuke everything -- clean plus each library's $LIB; see the warning below
mk nuke
```

**`mk install` used to need running twice** -- syscalls were not always
integrated into libap on the first pass -- and no longer does.

**Prefer `distclean` to `nuke`, and the reason is specific rather than
general.** `nuke` is `clean` plus `rm -f ... $LIB` (`sys/src/cmd/mksyslib`,
`mklib`, `mkone`), and `$LIB` is `$APEXPROOT/$objtype/lib/ape/libap.a`.
**With `$APEXPROOT` empty that is `/$objtype/lib/ape/libap.a`** -- an
absolute path into the host's own stock APE, not into this tree. Every
mkfile here assigns `APEXPROOT` itself as a literal, so it takes a
command-line override or a bad edit to get there; the exposure is one
named file per library directory rather than a tree, so the failure is
bounded, but it is a real way to delete something outside the repo and
there is no reason to run into it. `distclean` touches only
`./$arch/bin` and `./$arch/lib`, looping over the **literal** `$_ARCHS`
list, so no expansion can produce an absolute path.

**And it EMPTIES those directories rather than removing them, because
`apexp-sh` binds two of them.** A Plan 9 bind captures the directory's
**channel** at bind time; `rm -rf` destroys what that channel names,
`mk install`'s `mkdir -p` then makes a new directory with a new qid,
and the shell still running goes on looking at the removed one. Every
lookup in that union component falls through to the host's own
`/$objtype/bin` -- so the next native compile runs **stock 9front's
`6c`** and dies on `syntax error, last name: bool`, `bool` being
exactly what APExp's kencc adds. *A library that built yesterday stops
building and nothing in the message is about binds.* **CONFIRMED by the cleanest
control available**: the window was killed, a fresh `apexp-sh` started,
and `mk install` run again with no other change -- and it built. Only
the namespace differed. **A fresh `apexp-sh` is the fix whenever this
shape appears**, since any `rm -rf` of a bound directory, by any means,
leaves a window whose `/bin` is quietly the host's.

**Those two trees are build output in full.** `git ls-files amd64` is
`amd64/include/ape` and nothing else, and `.gitignore` carries
`*/bin/*` and `*/lib/*` for every architecture -- which is why
`distclean` can remove them outright and `install` recreates them with
its own `mkdir -p`.

**An ABI change still needs the full removal before the rebuild**, and
`distclean` is the way to ask for it: nothing in these mkfiles lists a
system header as a dependency, so `mk` will not rebuild an object
because `<sys/select.h>` changed. See the `HFILES` note in
`docs/notes/tk-plan9.md` for what a half-rebuilt shared struct looks
like from the outside.

The install target:
1. Removes old arch-specific lib/ape files
2. Creates output directories for all 11 supported architectures
3. Runs `./mount-include` to bind APExp headers over the system headers via union mount
4. Recursively builds: `sys/src/cmd`, `sys/src/ape/9src`, `sys/src/ape/lib`, `sys/src/ape/cmd`

**APExp does NOT install to the filesystem root.** It installs into the local repo directory tree (e.g., `amd64/lib/ape/`, `amd64/bin/ape/`), then `apexp-sh` overlays these via Plan9 union mounts at runtime.

### Running APExp

```sh
# Launch a shell with APExp overlaid on the native APE environment
./apexp-sh
```

### Supported Architectures

386, 68020, amd64, arm, arm64, mips, power, power64, sparc, sparc64, spim

The current architecture defined by the variable $objtype, for example $objtype=amd64 for x86_64.

Architecture-specific code for libap.a lives under `sys/src/ape/lib/ap/arch/$objtype/`.

### Compiler Configuration

`sys/src/ape/config` defines the APE build environment:
- `CC=pcc` (Plan9 C compiler, not gcc)
- `CFLAGS=-Fw`
- Binaries install to `/$objtype/bin/ape`
- Helper scripts install to `/rc/bin/ape`

## Source Tree Architecture

```
sys/src/
├── cmd/              # Plan9 native compilers (6c/6l/6a for amd64, 8c for 386, etc.)
│   └── cc/, cpp/     # C compiler driver and preprocessor
├── ape/
│   ├── 9src/         # APE-specific utilities (cc wrapper, stty, tar)
│   ├── lib/          # Compatibility libraries
│   │   ├── ap/       # Core ANSI/POSIX C library (organized like musl src)
│   │   ├── curses/   # PDCursesMod (with wchar support)
│   │   ├── edit/     # libedit (line editing)
│   │   ├── lua/      # Lua 5.5.0 runtime
│   │   ├── pcre2/    # PCRE2 regex
│   │   ├── bz2/, z/, lzma/, xml2/  # Compression/XML libraries
│   │   └── [auth, bio, draw, l, plumb, sec]  # Core Plan9 libs
│   └── cmd/          # APE utilities
│       ├── make/     # GNU make 4.4.1
│       ├── sed/      # GNU sed 4.2.1
│       ├── grep/     # pcre2grep 10.43
│       ├── awk/      # GNU awk 5.3.0
│       ├── lex/, yacc/, m4/  # Build tools (flex, byacc, GNU m4)
│       ├── gettext/  # GNU gettext 0.22.5
│       ├── lua/      # Lua interpreter
│       ├── bash/     # Bash port
│       ├── f2c/, p2c/, objc/  # Transpilers (Fortran, Pascal, ObjC → C)
│       └── [bzip2, xz, unrar, unace, unarj, clzip]  # Archivers
sys/include/ape/      # All architecture-independent APE/POSIX headers
sys/lib/
├── ape/locale/       # Locale data
├── perl/             # perl module library (installed by cmd/perl, not by hand)
├── pascal/           # Pascal runtime
└── tests/            # Test programs (currently just stdio-test.c)
sys/man/1/, sys/man/3/  # Manual pages
$objtype/include/ape  # All architecture-dependent APE/POSIX headers
```

### libap (Core Library)

`sys/src/ape/lib/ap/` is reorganized to mirror the musl libc source layout. Key subdirectories:

- `stdio/` — migrated to musl implementation
- `thread/` — POSIX pthread implementation on Plan9
- `aio/` — async I/O
- `math/`, `complex/`, `fenv/` — C99 math
- `network/`, `select/` — network APIs
- `arch/` — per-architecture assembly/C implementations

Multiple upstream libraries are **merged into libap**: lib9, libbsd, libutf, libfmt, libv, libmp, libnet.

### Headers

`sys/include/ape/` contains APE/POSIX headers sourced from: musl libc, NetBSD (libnbcompat), OpenBSD (queue.h via sbase), GNU, and custom Plan9 shims.
`$objtype/include/ape/` contains APE/POSIX headers that are architecture-dependent

## Compiler Enhancements

The Plan9 C compilers (`sys/src/cmd/[1-9]c/`) have been patched extensively for C99/C11/C23 compatibility:

- **C99:** VLA, compound literals, hex floats (lexed since the start, but *converted* only since the `hexfloat()` fix -- see `docs/notes/kencc.md`), complex numbers, `//` comments, `_Bool`, designated initializers, `__alignof__`, `_Generic` (C11/C23), unicode escapes
- **Bitfield support** (from @jamoson's kencc patch)
- **GAS-compatible `as` front-end** to native Plan9 assemblers (vibe-coded with claude.ai)

When editing compiler sources, changes affect all architectures — the compilers share common front-end code in `sys/src/cmd/cc/` with arch-specific backends.

## Minimizing the Build

The default build is intentionally "bloated" to catch bugs early. To build a minimal subset, comment out subdirectories in the relevant mkfiles:

- `sys/src/ape/lib/mkfile` — disable libraries
- `sys/src/ape/cmd/mkfile` — disable utilities

Safe to disable: non-C language libraries, transpilers (f2c, p2c, objc), archivers.

## Testing

`sys/lib/tests/` holds standalone programs, each built and run by hand:

```
cd sys/lib/tests && pcc -o bool-test bool-test.c && ./bool-test
```

The convention: print `PASS`/`FAIL` per case, exit with the number of
failures, and open with a comment saying which bug the test came from
and what it cost. `tk-childproc-test.tcl` is the exception to the C
convention -- it is a Tcl script, run with `wish`, because the thing it
reproduces is Tk spawning a second Tk. Anything testing a language or library rule should be
correct on gcc too — checking a new test against gcc first is how you
find out whether the test or the tree is wrong, and it has caught both.

Every test named in `docs/notes/` sits here; the ones for kencc
itself are `bool-test.c`, `bitfield-test.c`, `compound-assign-test.c`,
`compound-literal-test.c`, `designated-init-test.c`, `charptr-test.c`,
`rol64-test.c` and `u64float-test.c`, and for libap `locale-test.c`,
`sigset-test.c`, `posix-spawn-test.c`, `limits-test.c`,
`format-arg-test.c`, `unget-pipe-test.c`, `isatty-test.c`,
`execve-env-test.c`, `tz-test.c`, `rename-test.c`, `listenleak-test.c`,
`asyncconnect-test.c`, `nbread-test.c`, `epipe-test.c`,
`ldexp-test.c`, `binfloat-test.c`, `rawmode-test.c`,
`execfail-test.c`, `append-test.c`, `strerror-test.c`,
`sincos-test.c`, `explog-test.c`, `fparith-test.c`,
`float-overflow-test.c`, `malloc-reuse-test.c`,
`socket-server-test.c`, `dup-fdinfo-test.c`, `rmdir-test.c`,
`copyfile-test.c`, `deeppath-test.c`, `bufexec-test.c` and `stdio-test.c`.
**`truefalse-test.c` is the one NATIVE test in this directory** --
`6c`/`6l`, not `pcc` -- and it has to be, because APE's `<stdbool.h>`
`#define`s `true`/`false` to 1 and 0, so an APE build never reaches
kencc's own C23 keywords. *A test here measures the APE dialect; a
bug in the native dialect needs a native test.* The twenty-five `tk-*.tcl` scripts there are Tcl, run
with `wish` -- except `tk-menubar-test.tcl`, which needs `tktest` and
skips itself under `wish`, and `tk-transient-test.tcl`, whose last
section alone does; see `docs/notes/tk-plan9.md`. `tk-runall.tcl` is the harness for
Tk's own suite rather than a test of its own, and `tk-runtest.tcl` runs
a single file from it. `tcl-runall.tcl` is the same thing for Tcl's own
suite, run under `tcltest`; both harnesses exist because a fault, a
kill and a clean finish are indistinguishable from the shell, so a run
without a completion marker cannot be read at all.
`itcl-runall.tcl` is the third, for itcl's 26 `.test` files, and it
**must be run under `itclsh` rather than `tclsh`** -- it says so itself
and reports whether `package require Itcl` worked before running
anything, because a suite failing every test for a missing package and
one failing because the port is broken give the same count.
`tarhdr-probe.c` is a PROBE rather than a test -- it prints a tar
file block by block and asserts nothing; the host reference output to
compare it against is in `docs/notes/libap.md`. `tarblock-probe.c` is
its companion and **must be built with tar's own `-I` flags**, which
are in the file: it measures `sizeof(union block)` against the host's
512, and with a different include order it would measure a different
`tar.h` and say nothing.
`tcl-stdchan-test.tcl` asks what buffering the three standard
channels get, and is a PROBE rather than a rule -- report what it
prints. `tcl-machexp-probe.tcl` is the same kind of thing for
Tcl's own float parser, and needs `$APEXP_STRTOD_DEBUG` set or it
says nothing. **It paid for itself in one run**: it named
`scalbn`'s `2^1023`. `ldexp-test.c` is the regression test that came
out of it, and it walks the WHOLE exponent range because the host
cross-check that had passed `scalbn` used a window that never reached
the broken branch. `tcl-fileevent-test.tcl` is a test rather than a harness -- it runs
under plain `tclsh` and isolates the `chan-io-44.1` and `event-11.5`
hangs, with a timeout on every section so it reports where the suite
would wait; `select-test.c` takes the two bugs it found down to the
`select()` call underneath them.
`tty-xcheck.c` is a host program too: it links `ap/plan9/tty.c`
with counting fakes for open/write/close and asserts the raw/cooked
contract, which is awkward to provoke on a live console. It needs
`-I ttystub`.
`strtod-xcheck.c`, `strtof-xcheck.c` and `dtoa-xcheck.c` are the same
idea for `strtod`, `strtof` and `_dtoa`, and are likewise HOST programs, not Plan 9 tests. The
second checks the two against each other -- the shortest string that
reads back -- which is a real test of both. `tz-xcheck.c` is not a Plan 9 test at all: it links
`lib/ap/time/tzone.c` into a **glibc** program on the build host and
sweeps ~1.4 million instants against `localtime_r`, so libap's own
parser can be checked without a VM round. It found two bugs that way.
That pattern -- link the unit under test into a host program beside the
reference implementation -- is worth reaching for whenever the thing
being written is a pure function of its input.
`sys/src/ape/lib/libressl/test/` is separate: it is
upstream's own ML-KEM and SHA-3 vectors, run by `mk test` there.

Beyond that, testing is still mostly ad-hoc — compile a program under
APExp and see whether it builds and runs.

## Current Development Focus (as of 2026-09)

- POSIX threading (`pthread`) — `sys/src/ape/lib/ap/thread/`
- Async I/O (`aio`) — `sys/src/ape/lib/ap/aio/aio.c`
- C11/C23 compiler features — `_Generic`, and `bool` as a real type
- perl 5.42.2 — see the section below

**Queued after Tcl/Tk: two more ports, chosen as stress tests.**
**`tkblt` was one of three and is GONE from the tree**: 3.2 is C++, 48
`.C` files with `namespace Blt {` and `#include <cfloat>`, and kencc
has no C++ (`external/cfront-C4` is pre-standard cfront: no
namespaces, no templates, no STL). **tkdesk never needed it** -- it
ships its own BLT subset in **C**, `tkdesk/blt/`, 12 `.c` files and
not one `.C`.
So: **itcl** (4.2.3, 22 `.c` files, an ordinary autoconf extension)
becomes a regular APExp package under `sys/src/ape/lib` and
`sys/src/ape/cmd`, and **tkdesk** gets its mkfile in
**`sys/src/ape/app`** and is **not built by default**, being a
proof-of-concept rather than part of APExp.
**itcl goes first, and the reason is measurability**: it ships its own
test suite, so it is new surface that can be counted, where tkdesk is
an application that either runs or does not and whose failures are
hard to localise. Tcl and Tk have been the most productive bug-finders
here, and every large find in this tree came from new software
reaching an untouched path rather than from grinding a suite already
at its floor.

### perl

`sys/src/ape/lib/perl` builds `libperl.a`; `sys/src/ape/cmd/perl` builds
`miniperl`, uses it to generate `perlmain.c`, links `perl`, and installs
the module library into `sys/lib/perl` (config.h's `PRIVLIB`).

Working: the interpreter runs, module loading works, and
`ExtUtils::Miniperl` generates `perlmain.c`.

**No XS extensions.** Plan 9 has no dlopen, so `usedl` is empty,
`dlsrc` is `dl_none.xs`, `xs_init` in `perlmain.c` has an empty body,
and only the pure-perl `dist/` and `cpan/` trees are installed — the
fourteen with a `.xs` are deliberately left out, listed in the mkfile.
A `.pm` that dies in `XSLoader` is worse than one that is absent.
PathTools is the exception: `File::Spec` is pure perl and `Cwd.pm` takes
a pure-perl path when DynaLoader is missing.

**`Config.pm` is hand-maintained**, at `sys/src/ape/cmd/perl/Config.pm`.
APExp does not run `Configure`, so there is no `config.sh` for `configpm`
to read; it is the companion to the hand-answered
`sys/src/external/perl/config.h` and has to be kept in step with it. It
provides `%Config` plus `import`, `myconfig`, `_V` (which `perl -V`
calls, at perl.c:2356), `config_vars`, `config_sh` and `config_re`.

**Getting perl to run at all turned up four bugs, and only one was
perl's.** They are worth reading as a set, because three of them were
silent:

- `bool` was a signed char in kencc, so every conversion to it truncated
  — see `docs/notes/kencc.md`. This is why miniperl compiled programs and
  then executed nothing.
- `setlocale` reported a locale it had not set — see libap, locale/.
- `<stdio.h>` leaked errno, unistd, fcntl and pthread, and libap itself
  relied on the leak.
- perl's `config.h` claimed an 80-bit long double. kencc has none:
  `sub.c`'s `simplet()` maps `BDOUBLE|BLONG` to `types[TDOUBLE]`, so
  `long double` is `double`. `NVTYPE` is `double`, `NVSIZE` 8, the
  `NVef`/`NVff`/`NVgf` formats lose their `L`, `USE_LONG_DOUBLE` is off,
  and the `LONGDBL*` byte patterns and mantissa bit counts follow. A
  format asking printf for a type nothing passes it is how `use 5.006`
  came out as "Invalid version format (non-numeric data)".

---

## The detailed notes

**This file is read in full at the start of every session, so it is kept
short on purpose.** The history -- every bug, what it cost, and how it was
found -- lives under `docs/notes/`, one file per area. Read the one that
covers what you are about to touch; do not re-derive from scratch.

| file | what is in it |
|---|---|
| `docs/notes/kencc.md` | the Plan 9 compilers: every patch to `cc`, `[1-9]c`, `[1-9]l` and `cpp`, C99/C11/C23 status, and the silent code-generation bugs (the 6c spill, the sign of zero, hex floats, `bool`, mixed-signedness `op=`) |
| `docs/notes/libap.md` | `sys/src/ape/lib/ap/` by directory: locale, math, malloc, thread, signal, process, aio |
| `docs/notes/invariants.md` | the traps that bite silently: ABI widths, variadic sentinels, missing prototypes, `free()`'s contract, amd64 setjmp/longjmp, the FP environment, header search order, and the stdio bugs found through flex |
| `docs/notes/tk-plan9.md` | the `sys/src/external/tk/plan9/` backend and Tk's own suite, runs 1 to 16. Also the `HFILES` trap and the gcc syntax check, which apply tree-wide |
| `docs/notes/vts.md` | the VT emulator and its two clients: what `vtwin` and `vts-attach` are, why the missing piece is inside `vts/session.c`, and the order of work |
| `docs/notes/tcl-suite.md` | Tcl's suite: the allocator, sockets and the missing loopback, `shutdown()`, `listen()`, `select()` and `ap/plan9/_buf.c`, `fd_set`, and the `chan-io` hangs |

Two more under `docs/`, which are surveys rather than history:
`posix-coverage.md` (what of POSIX/musl is present, missing or stubbed,
compared file by file against musl's `src/`) and
`compiler-improvements.md` (the state of the Plan 9 C compilers and what
is still open). `docs/releases/` holds the release notes.

**When a round finishes, the finding goes in the topic file and only the
one-line consequence comes back here.** That is what keeps this file from
growing back to the 8000 lines it was.

## Method: rules that each cost at least one round

These are distilled from the notes above; each one is a mistake that was
actually made here, most of them more than once. The evidence for each is
in the topic file.

**Reading a log**

- **A log's last line is not where the run stopped.** Four separate
  causes: block buffering; a child whose stdout is a pipe; a marker that
  could not print; and `-verbose t` being off, so only *failures* print
  and the last failure is not the last test.
- **`-verbose t` is what makes "last printed" mean "last started".**
  Without it a log cannot be read for position at all.
- **A fault, a kill and a clean finish all just give the shell prompt
  back.** Hence the completion marker in `tk-runall.tcl` and
  `tcl-runall.tcl`; check for it before reading any total.
- **A marker says the run reached the end, not that it was the run you
  asked for.** Read the `Total` line beside it.
- **And check the log's own `Tests ended at` line before reading
  anything from it.** A copied file that was never committed leaves the
  previous run in place, and a stale log reads exactly like a real one.
  It happened: a suite log was fetched, opened and nearly analysed while
  being byte-identical to the frozen run three rounds earlier. Same
  family as the libap mark -- *anything measured from outside the source
  in front of you should say where it came from.*
- **A constraint says what a test *needs*; only the log says whether it
  ran.** Three tests were written off for three rounds on a constraint
  line while `---- chan-io-41.7 start` sat in the log.
- **A crash or freeze after test N is evidence about N only if nothing
  between N and the stop could have armed it.**
- **Compare runs per file, never by total.** A total cannot tell "nine
  fixed" from "fifteen fixed and six broken"; diff the failing test
  *names*.
- **A rising failure count after new tests become runnable is newly
  *measured*, not newly broken.**
- **And its coin's other face: a test that newly FAILS may be one that
  was passing for the wrong reason.** Before blaming the change in hand,
  read what the test asserts and ask whether anything else in its file
  moved. `socket_inet-5.1` wants a port bind refused, and a leftover
  listener had been refusing it.

**Before believing a result**

- **A measurement of a build that does not contain the change measures
  nothing.** Three instances, two of which nearly reversed a correct
  decision. `git merge-base --is-ancestor <fix> origin/main` before
  reading anything, and number the sections of a hand-built test so the
  output says which source ran.
- **And its opposite face: a build that DOES contain the change cannot
  tell you the change was needed.** A green run looks the same for a fix
  that was necessary and one that was not. To ask *that*, replicate the
  old code beside the new -- which is usually cheaper than a rebuild.
- **When a run comes back green, ask what the new case would have
  printed and look for it.** A test that could not run is
  indistinguishable from one that passed.
- **A fix that demonstrably changed the output has still not been shown
  to fix the test.** Two of `env-2.1`'s three unwanted lines went away
  and not one count moved: a test comparing exactly does not care how
  much of the difference is left. Count what remains before calling a
  cluster closed.
- **A check that cannot fail is not a check** -- and its twin, a check
  that can PASS for the wrong reason, and its other twin, a check whose
  *negative* result has two explanations.
- **A test that draws its own conclusion must do the arithmetic the
  reader would**, or it reports a refutation where there is a
  confirmation.

**Diagnosing**

- **Ask the harness which test before reasoning about which mechanism.**
  Five times a confident mechanism was wrong and one printed
  intermediate settled it in a single run.
- **Print what the machine says rather than what the code implies.** The
  missing loopback, the announce spelling and the `fd_set` width were all
  settled that way after rounds of reasoning went the wrong way.
- **...but `errstr` is only trustworthy when the errno came FROM a
  system call.** It is per-process and sticky, so when libap sets errno
  itself (`EINPROGRESS`, `EALREADY`, `ENOTSOCK`) the Plan 9 string
  beside it is left over from something else -- `asyncconnect-test`
  printed `file does not exist: '/proc/25180'` next to a perfectly
  correct EINPROGRESS.
- **An asynchronous call returning 0 says it was ACCEPTED, not done.**
  `kill()` posts a note; the target dies later and its descriptors close
  later still. A closed listener's port stayed held for exactly that
  reason, and the fix was a wait, not a different approach.
- **Predict the OBSERVATION, never the conclusion.** "Kill succeeds and
  the port is held -> therefore revert" smuggled a mechanism into what
  looked like a reading rule, and nearly threw away a working fix on the
  strength of my own earlier sentence.
- **A grep hit is a name, not an implementation.** Open the function.
- **When a constant is wrong, grep for EVERY definition of it.**
  `PATH_MAX` had two, and the second was in a file the first one
  includes at its own last line.
- **Replicate the code in the tree, line by line, not the code you
  remember.** A probe written from a recollection of `DoCopyFile`
  skipped its `unlink(dst)` and so reported 0 failures for a copy that
  did not work -- a probe that skips a call cannot clear it.
- **Plan 9 has `ratrace`**, and it names a failing system call outright
  where elimination takes rounds. It found the `utime()` return-value
  bug in one run, after six readings of the source had chased an errno
  the failing call never set.
- **Read what a test *compares*, not what it mentions.**
- **A fact that contradicts the diagnosis is not a loose end to come
  back to.** `HOME` was missing from a child's environment in the very
  first log, which alone refuted the `/env` leak; it was filed as an
  anomaly and four more source files were read looking for what had
  hidden it. Nothing had.
- **A flag one letter from another flag is checked, not recalled**, and
  a comment restating what a call does is a claim like any other.
  `RFCENVG` was read as "copy the group" from a comment I had written
  myself, and a committed change rested on it.
- **Every case expected to return must come before every case expected to
  hang**, in file order, each behind a flushed marker naming the
  statement about to run.
- **A freeze and a timeout are different evidence**: a timeout proves the
  event loop still ran, a freeze proves the process is blocked in a call.
- **Blocked and spinning are different bugs**: constant *light* CPU is a
  wait, a pinned core is a loop.
- **Read the `ps` STATES before taking a stack.** Seven `tcltest`
  processes and not one in `Sleep` said the timer process was missing,
  a round before `acid` said the same thing -- and a live timer sits in
  `_SLEEP(mux->waittime)`.
- **A stack's ARGUMENTS can refute the mechanism you predicted for the
  line you predicted.** `select` was blocked exactly where expected, and
  `timeout != 0`, `t = 200` in the same frame showed the reason was the
  opposite of the one argued.
- **A bisect that narrows to nothing is evidence** -- of a cumulative
  cause -- not a failed bisect.
- **When upstream does something from an event, ask what the event costs
  in time before reimplementing it as a call**, and the reverse. Copying
  upstream's mechanism is not copying its timing.
- **A fix that makes a process reach code it never reached before can
  expose anything on that path.**

**Writing the code**

- **A stub that answers "failure" is not the same as one that answers
  "nothing to do"**, and a stub that does nothing is not the same as a
  platform with nothing to do. This family (`XLoadFont`, `wm title`,
  `testembed`, `TkUnixSetMenubar`, `shutdown`, an errno naming the wrong
  category) is the single most common bug in this tree.
- **A platform having nothing to *display* is no reason for a value not
  to read back.**
- **The condition is not the operating system, it is that there is no X
  server** -- so `PLAN9` belongs in upstream's own `_WIN32 || MAC_OSX_TK`
  lists, not in a forked copy of a generic file.
- **Do not invent semantics to make a test pass.** No `bind()` fallback
  to `*`, no error on an empty `/dev/snarf`, no unmapping of
  descendants, no fabricated install paths.
- **When a struct is recycled, reset every field that means something**,
  not just the ones about the data.
- **A table keyed on a descriptor NUMBER needs invalidating when the
  number is retired, and there is no single place that happens.**
  `dup2()` and raw `_CLOSE()` retire one without going through
  `close()`. Key on something the file itself carries (`dev`/`ino`), or
  a stale entry will be believed -- one SIGKILL'd the wrong process and
  froze a suite.
- **Append to a shared global struct, never insert** -- and see the
  `HFILES` rule below.
- **Err towards more damage** when repairing pixels: too much costs a
  repaint, too little cannot be corrected.

**Build system**

- **A header not in `HFILES` is a header `mk` does not rebuild for.** A
  logically inert change followed by broad, unattributable breakage is a
  layout problem; ask which objects were actually recompiled.
- **A subdirectory called `test` is a mk directory, whether or not it
  has an mkfile.** `mkone`, `mkmany`, `mkelf`, `mkelves`, `mklib` and
  `mksyslib` all carry `test -d ./test && @{cd test && mk $MKFLAGS
  clean}` and the matching `test:QV:`. `cmd2/vts/test` had the name and
  no mkfile, so `mk distclean` stopped there -- and because mk
  propagates the failure up through every enclosing directory, **one
  missing file failed the whole tree's distclean**. The sweep (a `test`
  dir beside an mkfile, without one of its own) found exactly that one.
- **`rm -rf` on a directory something has BOUND does not unbind it.**
  The bind still names the removed directory, a recreated one has a new
  qid, and the union component silently falls through to whatever is
  next. That is why `distclean` empties `./$arch/bin` and `./$arch/lib`
  instead of removing them, and why a fresh `apexp-sh` fixes a build
  that suddenly cannot compile `bool`.
- **An ABI change needs `mk distclean` before `mk install`**; no mkfile
  here lists a system header as a dependency. **The same goes for a
  library change that has to reach an existing binary**: `mk install`
  rebuilds `libap.a` without relinking programs already built against
  it, so a libap fix can sit unused for rounds. Prefer `distclean` to
  `nuke` (see the Build System section).
- **Check every object built against a library for the flags that library
  was built with**, not just the ones the linker complained about.
  `nm -g --defined-only x.o | wc -l` is a one-second check.
- **Prefer the link over the patch** when missing symbols live in a file
  the upstream tree already ships.
- **When the library already does the thing you are adding, copy the
  whole idiom, not the call.** `_closebuf` was cited for `SIGKILL`; the
  signal was taken and the loop that waits for the death was left
  behind, which cost two rounds.
- **Put a test binary in the directory whose flags it shares** -- but it
  does not follow that every object in it takes the same flags.
- **A macro's identity includes whether there is white space.** Copy an
  upstream spelling character for character, and guard it; and grep the
  mkfiles for `-D<name>=` before adding a name to an APE header.
- **Syntax-check vendored backends on the host with gcc before shipping**
  (the command is in `docs/notes/tk-plan9.md`); gcc is stricter than pcc
  and a round trip to the VM costs a full rebuild.
- **A Tcl list literal has to survive rc first.** `{}` is a block, `()`
  is a list, only `''` quotes.

**Testing**

- Check a new test against gcc or a Linux `tclsh` *first*: it tells you
  whether the test or the tree is wrong, and it has caught both. It
  caught a *third* thing in `tz-test.c`: that POSIX lets `localtime_r`
  skip the `tzset()` a `localtime` must do, and glibc takes it
  literally. The test asserted otherwise and the library was about to
  match the test.
- **Better still, link the code under test into a host program beside
  the reference implementation.** A test run on glibc passes by asking
  glibc for the answers; it says nothing about your parser until it
  reaches the VM. `tz-xcheck.c` linked `tzone.c` into a glibc program
  and swept 1.4M instants -- two bugs, two recompiles, no rebuilds.
  Applies to anything that is a pure function of its input.
- **Reproduce the CALL the failing code makes, not the outcome it
  wants.** `socket_inet-2.11` wants a connection accepted and gets there
  through `select()`; a reduction that used a blocking `accept()` passed
  three rounds and proved nothing, because `accept()` reads the pipe
  itself while `select()` goes through a copy process.
- **An instrument built for one question goes where the SECOND question
  can reach it.** `$APEXP_LISTENDEBUG` lived in `_sock_listenpid.c` and
  the next question arrived in `_buf.c`; `plan9/_apdbg.c` now serves
  both. There is always a second question.
- Anything asking about one operating system's own behaviour is a probe,
  not a library rule -- report it, do not assert it.
- Write the prediction down before the run, including what would refute
  it. The honest tally in these notes runs about one in eight for
  mechanisms guessed from code alone.

## Known invariants, one line each

The reasoning for all of these is in `docs/notes/invariants.md`; this is
the index, so that nothing here is a surprise.

- `size_t`/`ssize_t` are 64-bit on amd64 and `long` is not.
- **`fconv.h` must be included BEFORE `<float.h>`**: `float_arch.h`
  defines `IEEE_8087` only under `_RESEARCH_SOURCE`, which fconv.h
  defines just before pulling `<float.h>` -- include them the other way
  round and fconv.h reaches its own deliberate syntax error.
- **amd64 underflow is GRADUAL**: `fenv.s` loads MXCSR `0x1f80`, FTZ
  and DAZ both clear, so `Sudden_Underflow` is not defined for it any
  more. The other seven architectures still claim it, unchecked.
- `sizeof` is 32-bit, so a call with **no prototype in scope** corrupts
  the argument. An argument that arrives half right means a missing
  prototype.
- A variadic sentinel must be a pointer, never `0`.
- `free()` needs exactly the pointer `malloc()` returned.
- `longjmp` must never write to the stack; `main9.s` must use only
  caller-saved registers.
- Any startup path bypassing `main9.s` must set the POSIX FP environment.
- `/$objtype/include/ape` is searched **before** `/sys/include/ape`, so
  stock APE's per-architecture `float.h`, `stdarg.h` and `stdint.h`
  shadow this tree unless a real file shadows them back.
- Adding an entry to `_errno.c`'s table changes control flow, because
  `bind()` gates its fallback on `EPLAN9`.
- `RFCENVG`, `RFCNAMEG` and `RFCFDG` create **empty** groups; the `C` is
  *clear*. `RFENVG`, `RFNAMEG` and `RFFDG` are the ones that copy. So
  `execve` has no environment at all after its first line.
- **kencc rounds EVERY struct's size up to 8, and aligns a nested
  struct member to 8 too** (`6c/swt.c`'s `align()`, cases `Asu2` and
  `Ael1`). So `sizeof(struct{char a[500];})` is **504**, not 500.
  Field offsets are still right, so a `memcpy` into a local is fine --
  **what breaks is `sizeof` used as a STRIDE or a LENGTH**: `p + 1` on
  a pointer to the type, or writing it as an on-disk record.
  `#pragma pack on`/`off` is the override (both cases read `packflg`),
  spelled `on` and not `1`. This made `union block` 520 and every
  archive GNU tar wrote malformed.
- **kencc's type signatures follow POINTERS into the struct they point
  at**, and 9front's `CFLAGS=-FTVw` turns them on for every native
  build. So a struct that is opaque in a public header and completed in
  one `.c` makes that one file disagree with every other about every
  function that can *reach* it, transitively through members. The fix is
  `#pragma incomplete` on the opaque types; it is read only by
  `signat()`, and completing the struct afterwards does not clear it.
  Fifteen link errors in `libvterm` were this one thing.
- **`FD_BUFFERED`/`FD_BUFFEREDX` are facts about a PROCESS IMAGE, not
  about a descriptor**, and `sfdinit` scrubs them on exec for the same
  reason it scrubs `FD_ISTTY` and `FD_ISREG`. `FD_BUFFEREDX` is poison:
  `read()` and `select()` both answer EIO for it without touching the
  fd.
- `/dev/snarf` is the clipboard and has no concept of ownership.
- Plan 9 has no loopback unless `ip/ipconfig loopback /dev/null 127.1`
  has been run -- and that belongs in the machine's startup, not in
  `apexp-sh`.

## Where things stand

**Tk's suite**: 97 files, `Total 10027 Passed 8925 Skipped 924
Failed 178` -> **177** after the whole Tcl campaign, clean exit. **One
test.** That is information rather than a disappointment: Tk's
remaining 177 do not share a cause with Tcl's, so the Tk list can be
worked without waiting on Tcl -- and Tcl was one of its three items. The remaining 178 are mostly out of reach here
(a second wish process, an X property, a system tray, a scalable font,
or a constraint that fails on Linux too). The port's own share is
`focus-6.1`, `geometry-4.7`, `event-9.13`/`9.14` and `visual-3.1`.

**Tcl's suite**: **it finishes and nothing aborts.**
`Total 68118 Passed 62138 Skipped 5916 Failed 64`, 167 files, marker,
exit 0, and no `Test files exiting with errors` section. **The whole
float rewrite -- Gay's `strtod`, `strtof`, `strtold`, and
`Sudden_Underflow` off for amd64, which switches `_dtoa` to its
gradual arm -- moved NOTHING: identical totals, empty per-name diff
both ways.** That is the confirmation it was safe, and the only one
available, since no test here formats a denormal. The listener
leak fix took **14** (all eleven of `socket_inet-11.*`, plus `12.1`,
`2.6`, `socket-14.11.1`); async connect took **13** more with nothing
moving the other way: `socket-14.2/14.6.0/14.7.0/14.7.2/14.8.2/
14.11.0/14.12/14.14/14.15/14.18`, `socket_inet-8.1`, and
`http-4.14.0/4.14.1`. **A feature that has never worked does not fail
in one place** -- `http.test`'s two were never connected to `-async`
until it worked.

**136 -> 96 CONFIRMED: forty fixed, none broken, all forty named.**
`Total` identical, `Skipped` **+5 exactly** (the symlink probe),
`Passed` +35, empty new-failure column. 12 were `O_NONBLOCK` on a
regular file, 4 were `6.47`/`8.1`, 2 were `29.27`, 16 were `filename`,
and **6 were `io`'s encoding tests -- which were on the UNREAD list**
(`io-75.6.3/75.6.4/75.11/75.13`, `io-bug-73bb42fb-1`,
`io-bug-73bb43fb-2`). The previous note said a fall of more than twelve
would mean the reading was incomplete; **it fired and it pointed at the
right six.** Write the refutation condition down.
**EPIPE is confirmed twice**: `29.27` passes, and `io-29.33b` -- still
failing -- changed from `cannot send after transport endpoint shutdown`
to `broken pipe`, so the mapping reaches the code and `29.33b` is a
different bug the wrong errno was dressing up as a socket problem.

**A count in the per-file table is executions, not tests**: `clock`'s
16 were 4 tests run twice each (`.vm:0`/`.vm:1`). Size a cluster from
the names, not the number.

Open, in order of what the next run should touch:

- **`env` 9: understood, and not ours.** All nine are one line,
  `path=/bin<0x01>.`, in a child's environment. Tcl never unsets `path`
  (`envprep` keeps anything whose upper case is in its keep-list, which
  has `PATH`), and the child's filter `lrem` removes **one** match --
  while this environment has two spellings, rc's `path` and the `PATH`
  that `apexp-sh` sets for bash. Checked on a host `tclsh`. Do not fix
  by hiding `path`. The `_fdinfo`/`_sighdlr` leak into `environ` **is**
  fixed and confirmed. **The `execve` half was withdrawn: there was no
  second bug.** `RFCENVG` creates an *empty* environment group -- the
  `C` is *clear*, `RFENVG` is the one that copies -- so `execve` already
  delivered exactly `envp`, and the loop added to clear `/env` was
  removing an empty directory on every exec. `execve-env-test`'s
  section 3 measured it in one run without rebuilding libap.
- **`posix_spawnp` discards the `envp` it is handed**: libap's `spawn()`
  tests `usepath` first and the child calls `execvp`, which passes
  `environ`. POSIX says `envp` is the child's environment either way.
  Recorded, not fixed, not measured. Tcl's `exec` is the caller.
- **`clock` 16 -> 0, CONFIRMED**, and nothing else moved: `Passed` +8,
  `Total` and `Skipped` identical, no new failure anywhere -- so `%Z`
  printing the real zone name instead of always `EST`/`EDT` broke
  nothing. The cause: `$TZ` reached nothing.
  `tzset()` parsed `getenv("timezone")`, Plan 9's spelling, while
  `localtime_r` separately read `/env/timezone` **once per process** into
  a static of its own, and neither had heard of `TZ`. Nothing set
  `tm_gmtoff`/`tm_zone` either, so `strftime`'s `%Z` was a hardcoded
  `{"EST","EDT"}` ("hack for now: assume eastern time zone") and `%z`
  did not exist. `time/tzone.c` is now the single engine -- POSIX TZ
  strings with DST rules, `/env/timezone` as the fallback, UTC with an
  **empty** name when neither parses. **`%Z` changing for every zone is
  the thing to watch beyond `clock`.** No zoneinfo, so
  `TZ=America/New_York` is UTC; glibc does the same here without tzdata.
- **`fCmd` 35 -> 22, CONFIRMED, and everything left is out of reach.**
  The 16 that went were the two bugs: `rename()` of a directory into a
  *different* directory always failed (the cross-directory copy path did
  `_CREATE(to, OWRITE, s->mode)` and a directory cannot be opened for
  writing), which also produced the "invalid operation" two *permission*
  tests were reading; plus `EINVAL` for a directory moved into itself,
  compared **by qid up the tree, not by string**; plus `_errno.c` mapping
  Plan 9's "permission denied" to `EPERM` where POSIX wants `EACCES`.
  The remaining 22 + `unixFCmd` 2 are 14 symlink, 8 `~USER`,
  `unixFCmd-1.1` and `unixFCmd-2.2.2`. **24 of 24 accounted for** --
  reading a cluster all the way through before touching it is what made
  that possible. **The symlink half is now constrained rather than
  failing** -- see the `symlinks` entry below.
- **`close()` on a listening socket freed nothing -- FIXED and
  CONFIRMED.** `listen()` replaces the descriptor with a **pipe** and
  forks a child holding the real network fd, so `close()` shut a pipe
  while the announcement lived in another process. **This was the
  hundred leaked `listenproc` processes.** `_sock_listenpid.c` records
  the pid keyed on `dev`/`ino` (a descriptor NUMBER is retired by
  `dup2()` and raw `_CLOSE()` without clearing, and a stale entry
  SIGKILLed the wrong process and froze a suite); `close()` kills it,
  only if `getpid()` matches the recorded owner, and **waits for the
  death with `_closebuf`'s loop** -- `for(i=0; i<10 &&
  kill(pid,SIGKILL)==0; i++) _SLEEP(1);` -- because `kill()` POSTS a
  note and returns. `listenleak-test` 0 failures at mark 3;
  `chanio.test` passes, so the `chan-io-29.34` freeze belonged to the
  descriptor-keyed version.
  **`_sock_listenmark()` is the library's version marker** -- `pcc -o x
  x.c` relinks against the INSTALLED libap, so a test built from a fresh
  pull can run days-old library code and say nothing; bump it when the
  file changes in a way a test must see. `$APEXP_LISTENDEBUG=1` prints
  one line per decision.
- **The suite freezes in `socket_inet-2.11`**, file 129 of 167 (it was
  file 14). The debug lines place it exactly: tcltest runs `-setup`
  before printing `---- $name start`, so the listener recorded just
  before that line is 2.11's own, and the body blocks at `vwait sock` --
  **the connection is never accepted**. The previous test's listener was
  at the same `fd=10` and had been killed. `listenleak-test` **section 4**
  (three rounds of listen/connect/accept/exchange/close) **passes**, so
  that reduction was wrong. Section 5 adds `select()` before the
  accept and **also passes**, so two reductions have failed and the next
  step is the frozen process, not a third guess. Reading narrows it:
  2.11's `vwait sock` has no `after` outstanding, so `select()` arms **no
  timer** and its only possible wakeup is a copy process reaching
  `_RENDEZVOUS(&mux->selwait, 0)` -- which matches the debug output, where
  the timer-reset lines tick eight times and stop. **That is the shape of
  the recorded, never-measured hazard**: *a copy process reaching EOF
  before the parent sets `selwait`*. `socket_inet-2.10`, just before,
  closes its server socket **from inside the accept callback**, so the
  listener is killed at an unusual point and 2.11 reuses the descriptor.
  `acid` CONFIRMED the line -- `_buf.c:544`, select's
  `_RENDEZVOUS(&mux->selwait, 0)`, under `TclpWaitForEvent`/`vwait` --
  **but refuted the mechanism**: the frame's own arguments show
  `timeout` non-null and `t = 200ms`, so a timer WAS armed and never
  fired. **`ps` shows no process in `Sleep`**, and a live timer sits in
  `_SLEEP`. So this is the failure `_killtimerproc` already describes:
  `timerpid` stale, `_resettimer()` signalling a corpse, every blocking
  `select()` that needs a timeout waiting for ever. `acid 12935` shows a SECOND interpreter
  (a `socket.test` helper), not the timer -- so the timer simply does
  not exist. **`_resettimer()` now notices and restarts it** (mark 5):
  `kill` failing with ESRCH is exact, the failure it prevents is total,
  and the repair is local. What killed the timer is still unknown and is
  now a separate, non-blocking question -- `_detachbuf` sets
  `timerpid = -1` in a forked child, so the documented "child took the
  parent's timer" route is shut.
  **`plan9/_apdbg.c`** is the shared debug line-printer
  (`$APEXP_DEBUG` or `$APEXP_LISTENDEBUG`), moved out of
  `_sock_listenpid.c` because the next question arrived in a file that
  could not reach it. 2.11 was already failing before this change
  (a timing result), so the hang is new but the test was never healthy.
  **With mark 5 `socket.test` COMPLETES** -- `Total 114 Passed 54
  Skipped 41 Failed 19`, same command that froze -- and `grep
  resettimer` shows the repair firing **twice**, so the timer really was
  dead and the diagnosis held end to end.
  **What KILLS the timer is now the open question and blocks nothing.**
  `fork()`'s child runs `_detachbuf`, which clears `timerpid`, `_muxsid`
  and `_mainpid`, so no child can fire either atexit handler; and the
  `_RFORK` children all leave through `_exit(0)`. Mark 6 is
  instrumentation only: `_timerproc` prints when a timer is forked and
  by whom, `_killtimerproc` prints when it fires. If the latter never
  appears, the killer is elsewhere and `_sock_killlisten`'s ten-note
  loop is the suspect, being the only new source of SIGKILLs.
- **`socket_inet-5.1`/`5.3` were passing for the WRONG REASON** -- a
  leftover listener was refusing the bind, not the system. **Confirmed**:
  they stayed failing once ports were genuinely released, as predicted.
  `notRoot` tests a user *name* as a proxy for a capability and glenda
  is the host owner, so these are not ours.
- **`socket-14.14`/`14.15` are the same story, and expose a real gap.**
  They were passing because `randport` certifies a port free by opening
  and closing a server socket on it -- and the leak left a listener
  holding the port it had just certified, which then ANSWERED the
  connection the test needs refused. Now refused honestly, and that
  raises the error at `socket -async` rather than on a `fileevent`:
  **`network/connect.c` has no `O_NONBLOCK`/`EINPROGRESS` path at all,
  so `socket -async` has never worked.** Nothing broke; something that
  never worked stopped being hidden. **Async connect is implemented and CONFIRMED**
  at the library level (mark 7, `asyncconnect-test` 0 failures): `connect()` on an `O_NONBLOCK` descriptor forks
  `_RFORK(RFFDG|RFPROC|RFNOWAIT)` to do the ctl write and returns
  `EINPROGRESS`; the child reports its errno down a pipe;
  `getsockopt(SO_ERROR)` -- which returned a hard-coded 0 -- now gives
  the real answer. **The remaining approximation**: `select()` calls
  every write descriptor ready at once, so `SO_ERROR` is asked before
  the connect resolves and therefore WAITS rather than answering 0. The
  real fix is `select()` learning about a pending connect. `Rock` gained
  three APPENDED fields; `unistd/mkfile` gained `HFILES` for `priv.h`.
  **`socket-14.14`/`14.15` are FIXED**, which was deliberately not
  predicted: 14.14 needs the failed connect to make the socket
  *readable*, through the copy process on the data file. It does --
  now measured rather than assumed.
- **`filename` 17 -> 1, CONFIRMED** (`Skipped` rose by exactly the five
  predicted). Read in full, it was three things. Five need
  symbolic links (ENOSYS, out of reach). **Eleven fail only because
  those five litter**: `11.17.7` does `file mkdir nonexistent`, then
  `file link -symbolic` raises, so its `file delete nonexistent` never
  runs and `-cleanup` removes only `link` -- every later glob test then
  sees one extra entry, and all eleven differ from expected by exactly
  that word. The constraint that should have stopped this is hardcoded
  to 1 outside Windows, so **`fileName.test` now PROBES for the
  capability** -- the only Tcl test patched, justified because the
  litter makes eleven tests misreport something unrelated.
  *(`fCmd.test`/`cmdAH.test` were deliberately left alone at the time;
  that was reversed the next round with explicit permission -- see
  `symlinks` below.)*
  **One is ours and is recorded, not fixed**: `filename-14.9` wants
  `glob globTest/.*` to yield `.` and `..`, and **Plan 9 directories
  contain neither**. Synthesising them in `readdir()` changes what every
  directory read in every program sees, for one measured test; it wants
  its own round.
- **`io` 23 and `chan-io` 19 are ~16 questions, not 42** -- `io.test`
  drives `fconfigure` and `chanio.test` drives `chan`, and `6.31`,
  `6.43`-`6.47`, `8.1`, `14.1/2`, `29.27`, `32.7/8`, `35.4`, `36.5/6`,
  `39.9` and `40.3` are in both. **Twelve were one line**: `read()`
  sent any `O_NONBLOCK` descriptor into the buffered copy-process path
  whatever kind of file it was, so a REGULAR file reported "would
  block" when the copy process had not caught up -- an empty file said
  `fblocked 1, eof 0` for ever. POSIX: `O_NONBLOCK` does nothing to a
  regular file. Now cached in two free `flags` bits beside `FD_ISTTY`
  (`FD_ISREG`, `FD_REGCHECKED`), **cleared on the exec-restore path in
  `_fdinfo.c` for the reason FD_ISTTY records there**. **CONFIRMED.**
- **`6.47` and `8.1` were that same line -- CONFIRMED**, and called for
  before the run by reading `PeekAhead()` rather than the tests: when
  `gets` sees `\r` at the end of a buffer, **Tcl sets the channel
  non-blocking itself for one read** and puts it back, so an ordinary
  blocking read of a regular file went through `O_NONBLOCK` after all.
  `io` 23 -> 10 and `chan-io` 19 -> 10, better than the 15 and 11
  predicted, by the six encoding tests nobody had opened.
- **`6.31` and `6.43`-`6.46` are NOT that**, and are recorded rather
  than fixed: every one uses `openpipe w+ $path(cat)`, and that `cat` is
  a second tclsh doing **non-blocking reads of its own**, so the bytes
  cross two copy processes and two event loops. `6.43`/`6.44` give the
  right values *shifted by one extra blocked result*. **Do not pay for
  it in `_readbuf`** -- `select()`'s `waitfresh()` is defensible because
  it is once per descriptor; the same wait in the `noblock` read path
  would tax every poll of every idle descriptor to make six tests agree
  about scheduling. The honest fix is a real non-blocking read for
  pipes (Plan 9's `stat` reports what a pipe has queued), and it is its
  own round.
- **`29.27`: `i/o on hungup channel` mapped to ESHUTDOWN, POSIX wants
  EPIPE** -- one write with no reader left, one answer, pipe and socket
  alike. **FIXED and CONFIRMED**; `epipe-test.c` asks it without Tcl.
- **`40.3` is not ours**: no umask on Plan 9, and the file server hands
  out `perm & (dirperm | ~0666)`, so **0644** where the test computes
  0666. *(The note said 0664 before the log was read. The mechanism was
  right and the number was a guess written as though measured.)*
- **`zipfs` 13 is the biggest unread cluster and ten of it is two
  `#define`s.** Every `zipfs-file-stat-*`/`-lstat-*` regexp-matches the
  whole key list of `file stat`, and ours was two keys short: Tcl wraps
  them in `HAVE_STRUCT_STAT_ST_BLKSIZE`/`_ST_BLOCKS`, which
  `sys/src/ape/lib/tcl/tclConfig.h` never declared **although APE's
  `struct stat` has both fields and `dirtostat.c` fills both**. Not a
  missing capability, a capability not declared -- `file stat` has been
  short two keys for every program. Declared now; `st_rdev` deliberately
  NOT, because `dirtostat.c` always sets it to 0 and *a field that is
  always zero reads as information and is not*. Predict 13 -> 3 (the
  three left are zipfs's own `invalid password`). **13 -> 3 CONFIRMED**
  after `mk install`: all ten `-stat-`/`-lstat-` gone, `Passed` +9,
  `Skipped` and `Total` identical, nothing else moved.
- **`14.1`/`14.2` (four tests) were the HARNESS, not the library.**
  `tcl-stdchan-test.tcl` under a plain `tclsh` on 9front answers
  `line line none` -- correct, at a terminal and redirected alike. That
  took libap out of it and left only what sits between `tclsh` and the
  test, and one grep found it: `tcl-runall.tcl` set
  `fconfigure stderr -buffering line`, **in every child through
  `-load`**, which is the very interpreter `io-14.1` then asks. *Four
  failures produced by the instrument measuring them.* It was working
  against its own purpose too -- stderr starts **unbuffered**, which
  orders a log better than line buffering -- and `errorChannel` is
  stderr, so that line was the same bug twice. Fixed in both harnesses;
  `stdout` keeps its line buffering, which is the half that was needed.
  **68 -> 64 CONFIRMED**: exactly those four, empty new column, and the
  log's tail did not truncate -- the thing those lines were for.
  **The general shape, met three times now**: a table keyed on a
  descriptor number, a constraint claiming a capability, a log's own
  buffering. *An instrument that shares state with the thing it
  measures can be the thing it reports* -- when a measurement disagrees
  with a direct probe, ask what sits between them.
  *(The earlier one-line version came back as `bash: fconfigure:
  command not found` -- **an instruction for the other machine has to
  name the program that runs it**, and a file is the way to say it.)*
- **`cmdAH-25.3` is NOT OURS -- settled.** `ls -ld /` says
  `glenda glenda`, `/dev/user` says `glenda`, so `file owned /`
  answering 1 is *correct*; the test wants 0 because on a unix `/` is
  root's. `notRoot` again, joining `socket_inet-5.1`/`5.3` and
  `unixFCmd-1.1`. **The `/adm/users` mechanism was refuted twice over**:
  the file exists, and glenda is uid **2** there while the fallback
  default is 1 (`tor`) -- so even had `_getpw` failed, `/` would have
  read as someone else's and the test would have *passed* for the wrong
  reason. `cmdAH-20.5` remains: `file atime $f $t` reads back the
  current time, so the wstat did not carry it -- `ratrace` first.
- **`chan-io-28.7`, one test and ours**: `close $s w` (half-close) and
  the far end reads `{}` where it should read `{Hey DONE}`. `shutdown()`
  is already in this tree's list of stubs that answered the wrong thing.
- **`lseq-4.21.4`, read and not diagnosed.** Eight cases; the first
  five raise `domain error` correctly and the last three do not. The
  discriminator is not NaN as such -- `lseq NaN count 5` and
  `lseq NaN count 5 by 100` both raise -- it is **`by NaN`**, which
  turns the error OFF even for `lseq NaN count 5 by NaN`, where the
  start alone was enough a line earlier. So a NaN step takes a
  different path in `tclArithSeries.c` rather than a NaN check being
  broken, and the next step is to read that path before blaming an
  `isnan` here. `expr`'s five and `lseq`'s other two went with
  `scalbn`.
- **Still unread**: `socket_inet` 4 and
  eleven singletons (`io-29.33b`, `io-52.22.1`, `chan-io-41.8`,
  `scan-15.1`, `event-1.1`, `unixInit-1.2`, `Tcl_Main-5.10`,
  `socket-14.19`, `expr-old-37.21`, `unixFCmd-2.2.2`).
- **`file home ~USER` / `file tildeexpand ~USER`**, ten tests. Needs a
  password database mapping a user to a home directory, which Plan 9
  has not -- read it before writing it off.
- **A failed `execve()` destroyed the caller -- FIXED and CONFIRMED,
  56 -> 54.** POSIX: "If the exec
  function returns to the calling process image, an error has occurred;
  ... the process image is unchanged." libap's did the opposite --
  `_RFORK(RFCENVG)` on its first line, then `/env/_fdinfo` and
  `/env/_sighdlr` rewritten, then every `FD_CLOEXEC` descriptor closed,
  all before `_EXEC` was so much as tried. **`exec-10.20.1`/`10.21.1`
  are what that costs**: Tcl's child reports a failed exec down an
  error pipe whose *closing* is how the parent tells success from
  failure -- so it is close-on-exec, so libap had already closed it,
  so the write got EBADF and Tcl panicked `unable to write to
  errPipeOut` instead of naming the missing program. Now `execve`
  **opens the file `OEXEC` first** -- which is the same question Plan
  9's own exec asks, `namec(..., Aopen, OEXEC, 0)` -- and returns
  with nothing touched if that fails; and the `FD_CLOEXEC` closes moved
  from the first loop to immediately before `_EXEC`. **Not a
  guarantee**: an exec can still fail *after* a successful open, and
  that case is as destructive as the whole function used to be.
  `_execpath` already did this with `access(X_OK)`, **but only when it
  searches** -- a name containing `/` is used as given, and
  `~non_existent_user/foo/bar` is such a name, which is why the check
  had to move into `execve`. `execfail-test.c` asks it without Tcl,
  and its **section 5 is the control that matters**: "never close them"
  passes everything else and breaks `FD_CLOEXEC` for every program in
  the tree. `_execmark()` is the version marker, as `_sock_listenmark`
  is for the listener fix -- and it earned its place: the run reported
  `_execmark = 1`, so the INSTALLED library was the one measured.
  **Exactly `exec-10.20.1` and `exec-10.21.1` went, empty new-failure
  column, `execfail-test` 0 failures.**
- **`exec-19.1` is the append race, and it is a platform limit.** Four
  shells `>>` the same file; the test checks only the SIZE, so 24
  against 26 cannot distinguish "truncated at open, losing the seeded
  two bytes" from "one two-byte `echo` lost to an overlapping append".
  `append-test.c` asks the two separately. Plan 9 has no `O_APPEND`:
  9P's `Twrite` carries an explicit offset and there is no write-at-end
  request, so libap emulates it with a seek in `open()` and another in
  `write()` -- **two calls with a window between them**, which is
  exactly what the test is built to catch. Plan 9's one atomic append
  is `DMAPPEND`, a permanent mode bit on the **file**; setting it would
  change that file for every other program and every later open, which
  is not what `O_APPEND` means for a descriptor. Recorded, not fixed.
  **MEASURED, and it is not marginal**: `append-test` section 3 loses
  **1280 of 2050 bytes** with four processes appending flat out, while
  section 2 shows no truncation and section 4 (one writer, same loop)
  is exact. So reading (b) is confirmed and (a) is excluded -- and the
  256-round count was what made the answer unambiguous rather than a
  coin toss. On glibc the same file reports 0 lost.
- **libap's `strtod` is now Gay's, and it is CORRECT**: `strtod-xcheck`
  against glibc gives **0 wrong** in all four sections -- 199887
  round-trips through `%.17g`, the 629 powers of ten, the seven strings
  Tcl's `expr` tests use, and the exact values. **The file it replaced
  was wrong on 148018 of those 199887 (74%)**, and said so in its own
  first line for as long as it existed. Built on `stdio/_fconv.c`'s
  Bigint kit, which is Gay's other half; `string/mkfile` gained
  `HFILES=../include/fconv.h`.
  **Six bugs, and FOUR were in the shared kit** -- `ULong` for the
  bignum word, `Long` for the borrow arithmetic in `_diff`/`quorem`,
  `Bcopy`'s `sizeof(long)`, and **`_d2b` leaving `i` unset** while its
  denormal arm reads `x[i-1]`. All four are one sentence: *Gay's
  arithmetic needs a 32-bit word and spells it `long`*, true under
  kencc and false under gcc -- correct on Plan 9 by accident, and why
  the cross-check could not run at all until they were fixed.
  **`_dtoa` was broken by the same `_d2b` bug**, in the shipping printf
  path: `dtoa-xcheck.c` measures 52 of 99941 wrong before and 3 after,
  and **subnormals printed as `?`** -- Gay's internal "cannot happen"
  marker. No test in the tree had ever formatted one.
  **The freelist was never the bug**, though disabling it took failures
  169725 -> 3656: it was `ulp()` returning `-0x1p+1023` for the ulp of
  2.1e-293 (the same `long` wrap), and the *damage* varied with what
  the freelist handed back. **An experiment that isolates a variable
  says the variable matters, not which way the causation runs.**
  The last 52 were the scale-up-by-2^53 arm, which upstream guards with
  `#ifdef Sudden_Underflow` -- for machines that FLUSH to zero. IEEE
  has gradual underflow; applying it made `1e-308` come out `0`.
- **`strtof` and `strtold` are done too.** `strtold` forwards to
  `strtod`: kencc has no extended precision, so `long double` IS
  `double` here. **`strtof` needed more than `(float)strtod`** --
  rounding to 53 bits and then to 24 is not rounding to 24, and when
  the double lands on a midpoint between two floats the narrowing has
  no tie-break left. Measured, not argued: `strtof-xcheck` found
  200000 float round-trips and 200000 random 17-digit decimals all
  correct, and **12709 of 39694 wrong among decimals BUILT to sit on a
  float midpoint** -- a sweep of random numbers would have called it
  clean. `_strtod_cmp()` now returns the nearest double *and* which
  side of it the decimal lay (strtod's loop has the decimal exactly;
  the fast paths are skipped when the comparison is wanted), and one
  `nextafter` moves it off the tie. **Conditional on being exactly on a
  midpoint**: an unconditional nudge would move a double one ulp away
  ONTO one. All five sections 0 wrong, with `strtod-xcheck` and
  `dtoa-xcheck` unchanged.
- **`expr`'s six are FOUND, and it was `2^1023` in `math/scalbn.c`.**
  That is `2 XOR 1023` -- an integer exclusive-or, **1021** -- where
  musl writes `0x1p1023`, a hex float. Someone read the `p` as "power
  of". `scalbnf.c` had the same with 127 (`2 XOR 127` = 125). The
  `machexp` probe said it in one run: every constant right, `machexp`
  1024 against a limit of 1024, and then `SafeLdExp -> 2041.9999999`
  -- 1021 x 2 exactly. **Not a compiler bug**: 89 other `math/` files
  use `0x1p...` and are fine.
  **It was never only those six.** Replicating the old code beside the
  new, `ldexp-test` fails 13 checks on it: **52 of 2098 double
  exponents and 23 of 277 float ones**, `scalbn(1.0,-1074)` giving
  **-2.27e-13** from +1.0 and `scalbn(1.0,1024)` giving 2042 instead of
  infinity. *Every subnormal any program reached through `ldexp` was
  wrong, some with the wrong sign.* The arms are only entered when
  `|n|` exceeds one multiplication's range, which is why nothing had
  noticed.
  **And the host cross-check had already passed `scalbn`** -- 299876
  values, 0 wrong, with `n` from `rand()%200 - 100`, so it never
  entered the broken branch. *A check that cannot fail is not a check*,
  and a sweep that cannot reach a branch has not tested it.
  `ldexp-test.c` bounds every section by the format's own limits
  instead. **64 -> 56 CONFIRMED**, eight gone and nothing new, with
  `ldexp-test` 0 failures on the rebuilt library. **The number was
  right for the wrong reason**: the six were called, `binary-53.25`/
  `53.26` did NOT move, and `lseq-4.21.2`/`4.21.3` did -- they are
  lists of `1e5555`, `Inf`, `1e308`, `5e307`. Read by the total alone
  this would have been logged as "binary fixed", exactly backwards.
  *Compare per name, never by total.*
- **`binary-53.25`/`53.26`: FLT_MAX was not FLT_MAX.** C says
  `FLT_MAX`, `FLT_MIN` and `FLT_EPSILON` have type **float**, and
  `float_arch.h` wrote them with **no `F` suffix** -- so each was a
  double holding the nearest double to a rounded decimal.
  `(double)FLT_MAX` came out `3.4028234999999998e+38` against a true
  `3.4028234663852886e+38`, about 3.4e30 too big, so the boundary Tcl
  computes (`FLT_MAX + 2^103`) sat above the value the test feeds it
  and `binary format R` wrote FLT_MAX where +Inf was required. Fixed
  with the suffix and full precision.
  **`binfloat-test.c` named it in ONE run** by listing four suspects
  and printing all four; every one of them was innocent, including the
  one the file's own comment called "not an idle suspect". It also
  prints a `__APEXP_FLOAT_ARCH` marker and the stringified macro,
  because a wrong constant and the WRONG HEADER look identical from
  outside -- the `/$objtype/include/ape` shadowing invariant is exactly
  that trap. Predict `Failed` 56 -> 54; refuted if the marker says the
  header read was not this tree's.
  **It took three rounds and the answer was the FIRST one, which I had
  then argued my way out of.** `tcl-fltmax-probe.tcl` measures what
  libtcl was actually compiled with -- `binary format R` answers +Inf
  exactly above `FLT_MAX + 2^103`, so bisecting on the BIT PATTERN
  recovers the constant exactly, and it prints the constant rather than
  a verdict. Round 1: `Failed` stayed 56 and the probe said
  `3.40282347e+38`. Round 2: `mk distclean` **and** `mk install`, and
  the probe said `3.40282347e+38` again -- from which I concluded the
  object had been rebuilt and staleness was out. **That conclusion was
  read off the `distclean` target, not measured.** Round 3: a marker
  added to `tclBinary.c` -- which is itself an edit, so `mk` recompiled
  that file -- and the probe now says the CORRECT constant, the marker
  says `PRESENT (this tree)`, `sizeof(FLT_MAX)=4`, and `binary format
  R` of `binary-53.25`'s own input gives **`7f800000`**, which is what
  the test wants.
  **54 -> 52 CONFIRMED**: exactly those two, empty new-failure column,
  `Total` and `Skipped` identical, `Passed` +2. The probe is removed
  from `tclBinary.c` again -- it was an instrument and it answered.
  **What is left is a BUILD-SYSTEM question, and it is not small**:
  `tclBinary.$O` was not rebuilt with the current header until the
  source file changed, so `mk distclean; mk install` did not do it.
  **`mk clean` was the suspect and is REFUTED by measurement**: run in
  `sys/src/ape/lib/tcl` it removes `libtcl.a` and `*.6`, and
  `tclBinary.6` is gone afterwards. So the objects do get cleaned, and
  the two `clean:V:` rules -- the mkfile's own, after `mklib`'s -- are
  not the problem.
  **Which puts the NAMESPACE back, and my refutation of it was
  UNSOUND.** I argued that a build without the union mount would have
  given the fixing recompile the old header too; that assumes both
  builds ran in the same namespace, and they need not have.
  `./mount-include` no-ops entirely when
  `/sys/include/ape/THIS_IS_APExp` exists, and on this machine it does
  (`-rw-r--r-- glenda 32 Sun 19 2026`) -- so `mk install` from a plain
  `rc` compiles against the machine's INSTALLED headers while the same
  command inside `apexp-sh` compiles against the repo's. That explains
  both readings exactly, and it would mean every `mk install` not
  started from `apexp-sh` has been building against an old APExp.
  **One word settles it**: the build prints `APExp mounted` or
  `APExp already mounted`. This is not specific to float and is worth
  knowing before the next port goes in.
  **The rule that failed here is one already in this file**: *a
  measurement of a build that does not contain the change measures
  nothing* -- and its harder half, which is that **arguing a build
  DOES contain the change, from the build system's source, is not a
  measurement either.** The marker is what settled it, and it had to be
  in `tclBinary.c`: a marker in `tclStrToD.c` answers for
  `tclStrToD.c`.
  A loose end that turned out not to be one: three different constants
  appear across the rounds -- `3.4028234663852886e+38` (correct),
  `3.40282347e+38` (this tree before the fix, and stock APE) and
  `3.4028235e+38` transcribed in `docs/notes/libap.md`. The third is in
  neither version of the header in git, so it came from a build reading
  something outside the repo. Worth remembering, not worth chasing now.
  Two host-check lessons on the way: `binary format Q` takes a
  **double**, not a bit pattern (`W` then `Q` is the reinterpretation),
  **Tcl's `%x` truncates to 32 bits** without `ll`, and **tclsh 8.6 has
  no +Inf arm at all**, so the host cannot validate this probe and it
  says so rather than reporting a false result. Both arms were
  exercised against a modelled `FormatNumber`.
- **9front has no symbolic links** (confirmed by grep), so `symlink()`
  stays ENOSYS. **Do not emulate it with a copy** -- see
  `docs/notes/tcl-suite.md`. **`tests/apexp-links.tcl` is the one probe
  for it**, sourced by `fCmd`, `cmdAH`, `chanio`, `unixFCmd` and
  `fileName`. It declares **`symlinks`**, APExp's own constraint name,
  and touches upstream's `linkDirectory`/`linkFile`/`symbolicLinkFile`
  **only when the probe fails** -- so on a system with links it changes
  nothing and cannot re-enable what Windows disabled. Fourteen tests
  that used a link without declaring they needed one now carry
  `symlinks`. **It cannot ask whether a constraint was declared**:
  `tcltest::SafeFetch` is a read trace that "sets testConstraints($n2)
  to 0 if it's referenced but never before used", so looking creates it
  as 0 and absent and false are one observation. The host tclsh caught
  the first version doing exactly that.
  **96 -> 77 CONFIRMED, and the refutation condition fired usefully.**
  Predicted `Skipped` +18; it rose **24**, and `Passed` fell **5**. The
  per-constraint skip table at the end of every run is what named the
  difference -- 35 new skips, 11 of them **reattributions** (tcltest
  charges a skip to one constraint of the list, so `notWine` -7,
  `win` -2). **The five lost passes were FALSE passes**: `fCmd-28.5`,
  `28.7`, `28.10`, `28.10.1`, `28.20` are `-returnCodes error` tests
  asserting only that `file link` RAISES, and on Plan 9 it raises
  ENOSYS -- so they passed for a reason unrelated to what they test.
  **A constraint that removes passes is doing its job as much as one
  that removes failures.**
  The nineteenth, `io-6.46`, is **flaky not fixed**: its twin
  `chan-io-6.46` still fails, so count that group by whether the twins
  agree. **CONFIRMED the next run** -- it came back with nothing
  touching it.

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
**`./vts-bash` IS THE LAUNCHER, and it must run from inside
`apexp-sh`** -- that is the mechanism, not a convenience: apexp-sh's
two `bind -b` lines are what put `vts`/`vtwin` and `bash` on the path,
and its `SHELL=bash` is what vts reads to know what to exec. vts forks
with `RFNAMEG|RFENVG`, both of which COPY, so the shell inherits both.
From a plain `rc` none of it is true and vts falls back to `/bin/rc`.
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

**itcl BUILDS AND RUNS, first try: `Total 792 Passed 712 Skipped 66
Failed 14`**, marker present, exit 0, no file errors. The header line
that matters reads `Itcl 4.2.3, Tcl 9.0.3` -- so `Tcl_StaticLibrary`
did its job and `package require Itcl` found the compiled-in package
with nothing to load. See the itcl section of `docs/notes/tcl-suite.md`
for the 14. `sys/src/ape/lib/itcl` builds
`libitcl.a` from configure.ac's own `TEA_ADD_SOURCES` list -- taken
from there and not from `ls generic/*.c`, because the two differ:
`itclStubLib.c` is `TEA_ADD_STUB_SOURCES` and is the one file that
forces `USE_TCL_STUBS` on itself, so building it in would put a second
stub-indirected copy of the entry points beside the real ones.
`itclTestRegisterC.c` IS in the main list, which is upstream's own
placement -- so unlike Tcl and Tk **there is no separate `itcltest`
binary to write**, and looking for one is how a round gets spent.
**Nothing uses stubs**: Plan 9 has no dlopen, so itcl is linked
straight into `sys/src/ape/cmd/itclsh` -- Tcl's shell plus an appInit
we write, since itcl ships none. **`Tcl_StaticLibrary` is the
load-bearing call there, not `Itcl_Init`**: without it the commands
exist but `package require Itcl` goes looking for something to load,
and that is the first line of every test file. Same wall as perl's XS.
The script library installs to `/sys/lib/itcl4.2.3`, which is where
`itclBase.c`'s embedded search script looks
(`[file dirname $tcl_library]/itcl$patchLevel`); `$ITCL_LIBRARY`
overrides it. The extra `install:V:` rule copies **only** the scripts
-- `mkone`'s own rule already copies the binary, and in Plan 9 mk every
`V:` rule for a target runs. *(That is also why `clean` worked in
`lib/tcl`: both its rule and `mklib`'s ran.)*
**Four things had to be fixed before it compiled, and the HOST found
three of them** -- the gcc sweep in `docs/notes/tk-plan9.md` applied to
a whole package rather than one backend, which is the cheapest thing
in this round by a wide margin:
- **`-DBUILD_itcl` is not optional and does not look like a missing
  define.** `itcl.h:105` turns `USE_ITCL_STUBS` **on** in its absence,
  so the package compiles as a stub CONSUMER of itself and
  `itclDecls.h` rewrites every entry point as `(itclStubsPtr->x)`.
  `itclStubInit.c`, whose whole job is to build the table those macros
  read, produced **152 errors**. Exactly Tk's `-DBUILD_tk`.
- **`itclUuid.h` is generated upstream from fossil**, which APExp has
  not; hand-written now in `lib/itcl` from the tarball's own
  `manifest.uuid`, the counterpart of `lib/tcl/tclUuid.h`.
- **`PACKAGE_VERSION` collides.** `tclConfig.h:5` defines it as an
  UNQUOTED `9.0.3`; `itclBase.c` concatenates it as a string literal.
  Defining itcl's on the command line is a redefinition cpp refuses,
  and letting Tcl's stand is a syntax error -- so `itclBase.c` uses
  itcl's own already-quoted `ITCL_PATCH_LEVEL`.
- **Two `Tcl_Size` sites**, `itcl2TclOO.c:186` and `itclParse.c:1367`:
  Tcl 9's `Tcl_GetStringFromObj` takes a `Tcl_Size *` and itcl 4.2.3
  passes an `int *` in two places, being `Tcl_Size`-aware everywhere
  else. **6c ERRORS where gcc only WARNS**, which is why a sweep
  counting errors alone found one of them and a second sweep for
  `-Wincompatible-pointer-types` found the other. *Sweep for the
  warning class the target compiler treats as fatal, not for gcc's
  errors.*
- **And one the fix itself introduced**: `%.*s` reads an **int**
  precision from the variadic list, so `(overflow ? limit : nameLen)`
  with `nameLen` retyped would promote to 64 bits and shift every
  argument after it. Cast back, explicitly. *A fix in a variadic call
  changes an ABI, not just a type.*

**"They all look upstream" WAS WRONG, and reading the eight unread
ones is what showed it.** FOUR of the fourteen were OURS -- a missing
file -- and the comfortable conclusion would have shipped without
them:
- **`sfbug-254.1/.2/.3` and `sfbug-257`: `can't find package itcl`,
  inside a slave `interp create`. OURS, FIXED, not yet measured.**
  The main interpreter never needed a package index: `itclAppInit.c`
  calls `Itcl_Init` directly and it ends by providing both `Itcl` and
  `itcl` (`itclBase.c:475-476`). **A slave has never run `Itcl_Init`**,
  and no `pkgIndex.tcl` was installed, so `package require itcl` there
  had nothing to find. `cmd/itclsh/pkgIndex.tcl` is ours rather than
  upstream's, because upstream's names a shared library to load and
  Plan 9 has none: **`load` with an EMPTY filename** is how Tcl reaches
  a `Tcl_StaticLibrary` registration (`tclLoad.c:251` matches by name
  when `fullFileName` is empty) and it works from any interpreter in
  the process. Both spellings, since Tcl package names are
  case-sensitive.
  *The general shape: `Tcl_StaticLibrary` makes the package reachable;
  a pkgIndex is what makes it FINDABLE. Two different things, and the
  main interp needs only the first.*
- **`local-1.2`/`1.3`/`1.4` -- upstream, settled at source.**
  `library/itcl.tcl:35` calls `trace variable`, and **Tcl 9 removed
  it**: `tclTrace.c:196` lists the options as exactly `add`, `info`,
  `remove`. `itcl::local` cannot work on this Tcl at all.
- **`mkindex-1.3` -- upstream, settled at source.** Three of fifteen
  index entries read `source -encoding utf-8` where the test wants a
  bare `source`. `auto.tcl:597` emits that string literally, and the
  three are the plain `proc`s (`mkindex.itcl:59,67,68`) Tcl's own
  parser handles while itcl's class-aware one writes the rest. No
  path, no filesystem encoding, nothing platform-shaped.
- **`fossil-9.0` -- the bug the test regression-tests, still failing;
  `fossil-9.1` is its cascade.** `9.0`'s setup makes class `N::B`,
  which creates `::N` as an ordinary namespace; the body then asks for
  class `N` and must adopt it (fossil `d0126511d9`). It answers
  `can't create namespace "N": already exists`. `9.1`'s SETUP then
  finds `N::B` still there from `9.0`'s failed cleanup, so it is one
  bug and one consequence. No platform surface -- pure namespace
  bookkeeping -- but not proven upstream either.
- **`rename-1.3`/`1.4`, `destroy-1.1`, `import-2.5` -- consistent with
  Tcl 9, not proven.** The first three differ by an extra `oo` child:
  `namespace children ::dog` answers `{::dog:: oo }` where the test
  wants it empty.
**14 -> 10 CONFIRMED, exactly the four `sfbug`s**: `Total` and
`Skipped` identical, `Passed` 712 -> 716, empty new-failure column.
**itcl is DONE as a port** -- the remaining ten are upstream or
Tcl-9's, two of them settled at source, and none is ours.

**GNU tar's messages had NO PROGRAM NAME, and it was every GNU
program in the tree.** `tar xf` on a `.tgz` printed
`: This does not look like a tar archive` where tar anywhere else
says `tar:`. gnulib's `error()` is literally
`#define program_name getprogname ()` (`gnulib/error.c:128`), and
libap's `getprogname()` returned **`argv0`** -- lib9's global, which
lib9 fills from `ARGBEGIN`, **an rc idiom no APE program executes**.
So it was NULL unless the program happened to call `getopt_long`,
which set it as a side effect -- which is why some programs named
themselves and others did not, and why nobody had chased it.
`argv0` is now set in **`plan9/callmain.c`**, the one path every APE
program takes, and its DEFINITION moved there from
`misc/getopt_long.c` for a linking reason: `_callmain` is in every
binary and `getopt_long` is not. `getprogname()` returns the
**basename** -- what BSD, Solaris, glibc and gnulib's own fallback all
return, and what `tar:` rather than `/bin/tar:` depends on -- and
never NULL, since every caller prints it with `%s`.
`progname-test.c` asks all four; its section 3 is what separates a fix
from a half-fix, since returning `argv[0]` whole would pass the rest.
**This is NOT the tar extraction bug** -- it is a second one that was
standing next to it, and the extraction failure is still open. See the
tar entry below.
**CONFIRMED, and by the very next command run**: `tar cf` now prints
``tar: Removing leading `/' from member names`` where the previous
round's run printed `: `. That one prefix certifies the whole chain --
`_callmain` sets `argv0`, `getprogname()` takes the basename, gnulib's
`error()` reaches it -- and `tar:` rather than `/bin/tar:` says the
basename half works too.

**`tar` CANNOT READ A PLAIN TAR FILE, and decompression was never
involved.** The split settled it in one round and eliminated
everything I had been looking at:
- `xd -c` shows `1f 8b 08` -- genuinely gzip;
- `minigzip -d <x.tgz >/tmp/n.tar` exits **status=0**;
- `tar tf /tmp/n.tar` on the ALREADY-DECOMPRESSED file gives the
  **byte-identical** failure, same `A lone zero block at 580`.
Identical output from both runs also says run 1's tar had decompressed
correctly all along, so `Child returned status 1` was minigzip taking
EPIPE when tar gave up -- *a consequence, not a cause*. **Every one of
`GZIP_PROGRAM`, `minigzip` and the exec plumbing is innocent.**
**WHERE IT ACTUALLY FAILS**, read off the source: the message comes
from `buffer.c:451`/`456` in `open_compressed_archive`, and it is
printed when `shortfile` is true -- which is
`*pshort = find_next_block () == 0` in `check_compressed_archive`.
**So tar's FIRST read of the archive yields no block at all.**
That also explains the `.tgz` run's shape exactly: with no bytes to
inspect, the magic test could not fire, so tar fell through to
`set_compression_program_by_suffix` -- it ran minigzip because the
NAME ended in `.tgz`, not because it had seen `1f 8b`.
`O_BINARY` is 0 in all four places that define it, so the `rmtopen
(..., O_RDONLY|O_BINARY)` is not it, and tar's `config.h` makes no
type-size claims.
**NEXT STEP IS `ratrace`, not more source.** It names a failing system
call outright where elimination takes rounds -- it found the `utime()`
bug in one run after six readings chased an errno the failing call
never set. Ask it on the smallest case: whether `tar` can read an
archive **it wrote itself** separates "tar's read path is broken" from
"this archive is unusual", and `ratrace` on that says which call
returns what.
**THE `tar cf` CRASH IS SOLVED, AND IT WAS NEVER TAR'S: gnulib's
`strerror` CALLED ITSELF FOR EVER.** `nohandle=1` named it in one run
and `acid` on the Broken process finished it:

```
tar 2459: suicide: sys: trap: fault write addr=0x7ffffeffefc8 pc=0x247ba3
strerror(n=0x14)+0x1e  .../external/gnulib/strerror.c:56   (x N)
```

`strerror.c:52` is `msg = strerror (n);` and is *meant* to be the
system's; gnulib arranges that with one macro in its **generated**
`string.h` (`#define strerror rpl_strerror`), so the definition defines
`rpl_strerror` and the `#undef` between declarator and body makes the
inner call reach the real one. **Nothing generates those headers here**
-- `sys/src/external/gnulib` has `string.in.h` and no `string.h` -- so
`<string.h>` was APE's, the function defined the plain name, and line
52 was a call to itself. Legal C, no warning. `n=0x14` is ENOENT.
**And it was every GNU program in the tree**: `strerror.$O` was in
`libgnu.a`, which every GNU package links, and `error(0, errno, ...)`
is how all of them report a failed system call -- so tar, sed, awk,
grep, m4, gettext, diff, patch and bison each died with a stack fault
instead of a message, reading as a different bug every time.
**No link error said so, and the reason is worth keeping**: the
archive's own README rule 1 is *never add a module libap already
provides*, and libap provides `strerror` -- but libap's is an archive
MEMBER THE LINKER NEVER HAD A REASON TO PULL, since gnulib's satisfied
the symbol first. *A module libap already provides is a problem whether
or not `ar` says so.* Fixed by one line out of OFILES; libap's has an
`EPLAN9` arm that returns Plan 9's own `errstr`, so this improves
diagnostics rather than costing anything.
**`nm` for the handler address was the WRONG QUESTION and is closed.**
The faulting address is ~16MB below the stack top: tar had run out of
stack, so the kernel could not push the note frame, which is exactly
what `bad address in notify` means. **A crash whose own message is
about the crash-reporting machinery is reporting the SECOND failure**
-- take the machinery out (`nohandle`) rather than investigate it.
**The sweep matters more than the instance**: the idiom (a definition
of NAME followed by `#undef NAME`) is in **34 places across 24 files**
in the gnulib tree and **exactly one, `strerror.c`, was in OFILES**.
The command is README rule 6 so it can be repeated when OFILES grows --
the next module added could be `fcntl`, `readdir`, `access` or `raise`.
**`strerror-test.c` must be linked against `libgnu.a`** or it passes
against the broken tree and proves nothing; the command is in the file.
**CONFIRMED, all three outcomes.** `tar cf` completes; `strerror-test`
reports **0 failures** linked against `libgnu.a`, section 1 included --
whose only possible failure was to kill the process; **and `tar tf` on
the archive tar had just written FAILED**, which was the third outcome
and the useful one. *The read bug is now proven independent of
`strerror`* -- the question the two rounds before this could not reach,
because tar never finished writing an archive to try.

**THE READ BUG IS OPEN, AND THE SYMPTOM HAS CHANGED -- which retires
part of the old diagnosis.**

```
$ tar tf /tmp/t.tar
tmp/h
tar: Skipping to next header
tar: Exiting with failure status due to previous errors
```

**`tmp/h` is listed correctly**, so the first header parsed AND its
checksum verified -- tar does not print a member name it has not
accepted. And `list.c:294` prints `Skipping to next header` **only when
the previous status was `HEADER_STILL_OK`**, so the failure is on the
**SECOND** `read_header`: a block that is neither a valid header nor
all zeros. **So "tar's FIRST read yields no block" was about the
original archive and does NOT generalise** -- here the first read
plainly yields one. Whether the two failures share a cause is open, and
assuming it would put the next round on the wrong file.
For a one-file archive nothing sits between the member and the zero
blocks, so exactly one of two things is true and they need completely
different fixes: **(a) the archive is malformed** and tar's WRITE path
is broken, or **(b) the archive is fine** and tar's READ path is --
most likely in how far it advances past the data, since landing one
block short would read the file's own contents as a header and give
exactly this.
**`tarhdr-probe.c` SPLIT THEM IN ONE RUN, and it is (a): the archive
is MALFORMED, so it is tar's WRITE path.** The header block is perfect
-- name, size, magic, and the checksum recomputes, so the reader was
right to accept it and right to refuse what came next. But **`hello\n`
sits 8 bytes INTO block 1** where the host reference has it at offset
0, and **blocks 2 and 3 are not zero**.
**The offset of the data is itself a measurement.**
`create.c`'s `dump_regular_file()` does `start_header` (which returns
`record_start`), `finish_header` (which advances to `record_start + 1`)
and then `blocking_read (fd, blk->buffer, ...)` -- so the file offset
of the member's data is exactly **`1 * sizeof(union block)`**. It came
out **520**. Every member of that union is an array of `char` and gcc
makes it 512, so 520 would mean kencc pads one of them: every block
after the first shifted, and a **compiler** question rather than a tar
one. **`tarblock-probe.c` asks it directly**, each member's size beside
the host's answer, and **must be built with tar's own flags** (the
command is in the file) or it measures a different `tar.h`.
**CONFIRMED: `union block` is 520, and SEVEN of the nine sizes
disagree with the host.** It is not tar's bug at all -- it is 6c's
struct layout, and `tarblock-probe`'s whole table is predicted by two
lines of `sys/src/cmd/6c/swt.c`'s `align()`: `Asu2` rounds the end of
**every** struct to `SZ_VLONG` rather than to what its members need,
and `Ael1` aligns a **nested** struct member to 8 as well, because
`ewidth[TSTRUCT]` drops through the same test.

```
  sizeof(union block)      =  520   host says  512   *** DIFFERENT ***
  sizeof(posix_header)     =  504   host says  500   *** DIFFERENT ***
  sizeof(oldgnu_header)    =  504   host says  495   *** DIFFERENT ***
  sizeof(star_in_header)   =  520   host says  512   *** DIFFERENT ***
  sizeof(struct sparse)    =   24   host says   24   same
```

**Two of those numbers need BOTH rules to explain**: `oldgnu_header`
495 -> **504** rather than 496, because its `struct sparse sp[4]` is
pushed from 386 to 392 first; and `star_in_header` 512 -> **520**, the
same push then a tail round -- **and that is the member that set the
union's size.** *`struct sparse` is 24 and agrees, because it is a
multiple of 8 by accident* -- a sample of one struct could have been
that one.
**What breaks is narrow and worth stating narrowly**: field offsets
are still right, which is why tar read its own header back correctly,
checksum and all. **`sizeof` used as a STRIDE or a LENGTH** is what
fails -- tar's entire record walk is `union block *` arithmetic while
every length in the format is a multiple of `BLOCKSIZE`, so 520 put
every block eight bytes late, and the zero-fill (counted in
`BLOCKSIZE`) then missed the gaps, which **is the second symptom**.
Both are one cause after all.
**FIXED with `#pragma pack on`/`off` around tar.h's on-disk structs
only** -- `pragpack()` sets `packflg`, the override both `align()`
cases already read -- guarded by `PLAN9` from `cmd/tar/mkfile`, as
itcl already does. It is spelled `pack on`, not `pack 1`: `pragpack`
does `atoi(s->name+1)` and only matches `on`/`yes` by name. tar's own
`tar_stat_info`/`xheader` are deliberately left unpacked; they hold
real `off_t` and pointers.
**`6c` ITSELF WAS NOT CHANGED, and the way to change it is a FLAG.**
The blast radius is smaller than it looks: `sys/src/cmd/mkfile` has
`BIN=$APEXPROOT/$objtype/bin`, so APExp's compilers install into the
**repo**, and the machine's own `6c` and the `/$objtype/lib/*.a` it
built are untouched. What is exposed is only what this tree links from
the host -- `cmd2/vts` (lib9p, libthread, libc) and `cmd2/vtwin`
(libdraw, libthread, libc).
**Porting those to APE would be a rewrite, not a port**: `ape/lib` has
`draw` but **no `9p` and no `thread`**, and vts *is* a 9P server on
libthread. **And a two-stage bootstrap does not close the gap** --
stage two's compiler would be built with the new rule and still link
the host's `libc.a` built with the old one (`Lock`, one `int`, is 4
naturally and 8 under the current rule, and sits inside `QLock`,
`Ref` and `Rendez`). It would need the whole native world rebuilt from
source, which this tree does not vendor.
**So: `-P` in `sys/src/ape/config`'s CFLAGS.** APE is already a
separate ABI -- own libc, own headers, own include path -- and
everything it links is built in this tree, so it is self-consistent by
construction; native code keeps the 9front ABI; **and the compilers,
being native, are unaffected, so there is no bootstrap question at
all.** The flag costs nothing to parse: `cc/lex.c`'s `ARGBEGIN`
`default:` arm does `debug[c]++` for any unknown letter.
**The work is NOT flipping a constant**: `struct Type` in `cc/cc.h`
has `width`, `offset` and `alignas_req` and **no natural alignment**,
which is exactly why `align()` reaches for `SZ_VLONG`. A conforming
rule means tracking max member alignment in `sualign()` and storing it
on the Type -- the type system, ~40 lines in `cc/` plus one per
backend.
**Measure first with `cc -a`** (acid definitions carry sizes; it is
what `mkone`'s `%.acid` rule uses): diff old against new over the APE
headers and libap, and it names every struct whose layout moves
*inside APE*.
**Order: after the archiver sweep.** If bzip2, xz, unrar, unace,
unarj and clzip come back clean, `#pragma pack` at the two or three
places that model bytes is the whole cost in practice and the flag
buys conformance rather than a bug fix. Detail in `docs/notes/kencc.md`.
**The sweep found six all-char structs in `external/` whose size is
not already a multiple of 8**, two of them tar's; the rest are
`memcpy`-into-a-local and cost nothing. **That is a LOWER BOUND with a
named limit**: the sweep only matches structs whose every member is a
plain `char`, so it misses the three tar structs with a nested
`struct sparse sp[N]` -- *the tool that found the bug's family cannot
find the whole family.*
**CONFIRMED END TO END, AND TAR IS CLOSED.** `tarblock-probe` reports
PASS and 0 disagreements with its `-DPLAN9` marker; all nine sizes
match the host and the block table reads 0/512/1024/1536 with
`record_end` at 10240. Then the same command on the same archive,
across the rebuild:

```
Before rebuild                     After rebuild
$ tar cf /tmp/t2.tar /tmp/h        $ tar cf /tmp/t2.tar /tmp/h
tar: Removing leading `/' ...      tar: Removing leading `/' ...
$ tar tf /tmp/t2.tar               $ tar tf /tmp/t2.tar
tar: This does not look like       tmp/h
     a tar archive                 $
tar: Skipping to next header
tar: Exiting with failure status
```

**And the ORIGINAL archive extracts**: `rm -rf NetHack-5.0.0`,
`tar xf nethack-500-src.tgz`, and the tree is back. **That was the
last open question and it is answered -- BOTH failures were the same
bug.** With `union block` at 520 the *reader* mis-strides exactly as
the writer did, so a correctly-formed foreign archive walked into its
own payload and reported `This does not look like a tar archive` /
`A lone zero block at 580`. **I was right to refuse to assume they
shared a cause, and the measurement is what joined them** -- the
before/after pair is the control, since only the build changed.
*(The before-rebuild run of `tar tf` on tar's OWN archive printed the
foreign archive's message this time, where the earlier run printed
`tmp/h` first: the same bug, differing only in what heap garbage the
mis-strided blocks happened to land on. Another reason not to have
matched them by message.)*
**WORTH A LOOK NEXT, and not urgent**: the archivers -- bzip2, xz,
unrar, unace, unarj, clzip -- are exactly the class of program that
walks on-disk records with struct pointers, which is the one thing the
padding breaks. None has been tested since. The `external/` sweep is a
lower bound by construction (see the note), so *the way to find these
is to run each archiver on a real archive*, not to grep.
Detail in `docs/notes/kencc.md` and `docs/notes/libap.md`.

**A DESCRIPTOR ARRIVED POISONED FROM AN EXEC, and it was every APE
program, not bash and not vts.** bash under vts printed its prompt and
exited 0 with no read of fd 0 ever reaching the server. One
instrumented run: `_startbuf: EIO, FD_BUFFEREDX fd=0 flags=42`, then
`select: -> -1`. readline's `rl_getc()` guards its `read()` with
`if (result >= 0)` on what `select()` returned, so a negative answer
means the read never happens and readline calls it EOF.
**The chain is ordinary**: readline `select()`s on fd 0, so libap
buffers it (`FD_BUFFERED`); `fork()`'s child runs `_detachbuf`, which
turns that into `FD_BUFFEREDX`, "poisoned"; and `execve` wrote the
flags word **verbatim** into `/env/_fdinfo`, where the new image's
`sfdinit` applied it **verbatim**. So any program started by an APE
parent that had ever select()ed on a descriptor inherited it
unreadable. **It only became reachable when `READLINE` was turned on**
-- nothing here had ever asked select() about a terminal before. *A fix
that makes a process reach code it never reached before can expose
anything on that path*, twice now.
Fixed in the CONSUMER (`sfdinit`), beside the existing `FD_ISTTY` and
`FD_ISREG` scrubs, because a child cannot trust those bits whoever
wrote them. `bufexec-test.c` is the regression test and calls
`_fdinfomark()`, so it **will not link** against a libap predating the
fix. **CONFIRMED on the rebuilt library**: `_fdinfomark = 1`, both
calls reach the descriptor, 0 failures.
**Not fixed, and the same run gave it its first measurement**: the
child's read answered `errno 3` = **EWOULDBLOCK** where glibc's reads
all six seeded bytes, so the parent's copy process -- still alive and
reading the same open file -- had them. Parent and child compete;
inherent in select() being a copy process, and its own round. The test
now carries a bounded PROBE (asserting nothing) that waits and says
whether the bytes ever arrive, because one non-blocking read cannot
tell "taken" from "not yet here". **gcc caught the first version of
that probe being worthless** -- run unconditionally it found nothing on
glibc *because the earlier read had already taken the six*, and
announced a loss that had not happened.
**Four rounds of diagnosis and vts was innocent from the first**, which
is the part worth keeping: `chatty9p` said no read ever arrived;
`fd2path` said the descriptor was right; **`SHELL=/bin/rc` gave a
prompt that stayed** and put the fault on the APE side in one command;
then `$APEXP_DEBUG` named the flag. *Three of the four were controls
rather than measurements of the thing itself, and each was cheaper than
the reading it replaced.*
**Two more found on the way, both recorded as found-not-measured**:
`_startbuf` never checked its `_RFORK`, so a failed fork left the
parent waiting for ever on a rendezvous with a process that did not
exist; and `ioctl(FIONREAD)` stored `*(long*)arg` where every caller
passes an `int *`, writing eight bytes and smashing four of the
caller's frame.
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
**Predict: those four FAIL on 9front and `sizeof` is 8.** Refuted if
they pass -- then the overlap story is wrong and the next suspect is
`vterm_input_write` chunking its input. (The far-right
indentation is separate and mine: `session.c`'s child prints with `
`
and no `
` into a raw console.)

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

**Fixed this round**: `NAME_MAX` was 27 and `PATH_MAX` 1023, set in
`sys/include/ape/sys/limits.h`, which `<limits.h>` includes at its very
end and which `#undef`s and redefines what the outer file had just set.
255 and 4096 now. **The header marker in `deeppath-test` is what found
it** -- it reported `came from THIS TREE` while the numbers stayed
stock-looking, which refuted my own architecture-directory diagnosis.
**When a constant is wrong, grep for every definition of it.**

**And the deep-path abort was cleared by the full rebuild, not by any
constant** -- most likely the `fts_alloc` fix from four rounds ago
finally reaching `tcltest`, which gives the new build rule below.

**Not ours**: `unixFCmd-1.1` wants `EACCES` from walking *through* a
mode-0 directory; Plan 9 answers "does not exist". The file server's
choice, so a probe rather than a library rule.

**bash cannot be `/bin/sh` yet: it dies `Killed: Insufficient physical
memory` during a full rebuild** -- but the log warns twice first, at
**100 and then 200 file descriptors**, and a shell running build
recipes has no business holding 200. So it is a leak with a shape.
`plan9/_buf.c` is the lead: `_startbuf` deliberately *"leave[s] fd open
in parent so system doesn't reuse it"* and forks a copy process per
buffered descriptor, both for the life of the process unless `close()`
reaches `_closebuf`. (`Muxseg` is also ~4.2 MB -- `Muxbuf bufs[256]`
at 16 KB of `data` each -- but that is demand-paged address space, so
it is the weaker candidate and is written down to be excluded.)
**Newly reachable when `READLINE` went on**, like the `FD_BUFFEREDX`
bug. **The test needs no new code**: run the failing build with
`APEXP_DEBUG=1` and count `select: buffered now fd=` lines against the
descriptor warnings. Recorded, not measured; back on dash meanwhile,
and the goal is one shell rather than two.

**Smaller open items**: `unlink()` of a directory reports `EPLAN9`
where POSIX allows EPERM or EISDIR.

**Open hazards recorded but not measured**: the lost wakeup in
`select()`'s rendezvous (a copy process reaching EOF before the parent
sets `selwait`). *(The `_closebuf` "kills ten times without waiting"
entry was withdrawn: the loop IS the wait -- it ends when `kill` fails
-- and misreading it is what left `_sock_killlisten` without one.)* *(The third -- a closed `socket -server`
leaving its `listenproc` for ever -- was measured and fixed; see above.
It had sat here unmeasured while it silently decided the result of two
tests.)*
