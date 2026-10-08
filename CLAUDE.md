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
`copyfile-test.c`, `deeppath-test.c`, `bufexec-test.c`,
`mkstemp-test.c`, `printfmod-test.c`, `umask-test.c`,
`dupbuf-test.c`, `dotdir-test.c` and
`stdio-test.c`.
**`ctype-xcheck.c` is a HOST program** like `tz-xcheck.c`: it links
libap's own `_ctype[]` into a glibc program and sweeps **256 values
by 12 classifications**, printing every disagreement. It needs TWO
compiles (the command is in the file) because `ctype.c` wants
APExp's `<ctype.h>` for the `_IS*` bits while the checker wants
glibc's headers, and one `-I` cannot serve both.
**`bash-fdloop-test.sh` is a SHELL script rather than a C program**,
and has to be: it asks whether *bash* leaks a descriptor per fork,
so the thing under test is the shell itself. Run it with
`/bin/bash bash-fdloop-test.sh`; it is correct on glibc too, where
it reports 5 descriptors flat.
**`bash-comsub-test.sh` is the second, and is a BISECT rather than a
test**: ten sections of bash's own `run-all` lines 17-27, each
writing a durable marker to `/tmp/comsub.log` before the statement it
runs, so the log's last line names the statement that did not return.
It asserts nothing and has no failure count -- *read the log, not the
exit status*. All ten return on glibc in 13ms.
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
`strftime-xcheck.c` is the newest of them and needs **two compiles**,
like `ctype-xcheck`: the `-D` that renames libap's `strftime` out of
glibc's way applies to the checker too if both are in one command,
and the sweep then compares libap against itself and reports a clean
number. *Break the unit on purpose and check that the instrument
notices* -- that is what caught it.
**`apdecl-sweep.py` is a host SWEEP rather than a test**: it asks
every `.c` under `lib/ap` whether it calls a non-`int`-returning
function that nothing in its include closure declares -- the missing
prototype invariant in its RETURN-value form. Run it after adding
files to libap; its limits are in its own header and it is a lower
bound.
**`strerror-xcheck.py` is the second host SWEEP**, and it is a
script for a reason the other xchecks do not have: **APE's errno
NUMBERS are its own**, so libap's table and glibc's cannot be lined
up by index at all -- only by NAME. It parses `errno.h` and
`strerror.c`, asks glibc for each name, and reports every
disagreement. Re-run it after touching either file; one inserted row
shifts every entry after it and nothing else would say so.
`strtoint-xcheck.c` is the same idea for `strtoll` and `strtoull`,
and needs THREE compiles: libap's prototypes take `char *` where
glibc's take `const char *`, so even a `-D` rename collides with the
header -- it renames the SOURCE with `sed` into a temporary instead.
`strtol`/`strtoul` cannot be swept at all here, because kencc's
`long` is 32-bit and the host's is 64.
`apeabi-probe.c` is a PROBE and is never run: it is compiled TWICE,
`pcc -a` and `pcc -J -a`, and the DIFF of the two acid dumps names
every APE struct whose layout `-J` moves. Take it before any
tree-wide rebuild.
`structalign-test.c` measures `pcc -J`, conforming struct layout, and
**needs three runs** -- gcc, then `pcc -DPLAN9` WITHOUT `-J` (which
must fail ~12 checks), then with it. *The middle run is the control*:
a pass under `-J` alone cannot distinguish a working flag from a
compiler that never had the bug.
`random-xcheck.c` is the same idea for `random`/`srandom`/
`initstate`/`setstate`, and needs TWO compiles for the
`strftime-xcheck` reason. Its **section 0 is a control of the
instrument**: it asks whether `random` and `ap_random` are the same
address, and whether the comparison reports anything at all for two
different seeds.
`regcoll-xcheck.c` links libap's `regcomp`/`regexec`/`tre-mem` into a
glibc program and sweeps collating symbols and equivalence classes
against glibc's engine. It needs TWO compiles **and a staged
`regex.h`**: the two libraries disagree about `regex_t`'s layout *and*
about the REG_* numbers, so one translation unit cannot hold both --
a SHIM half is built with APE's header and answers in `int` and
`const char *`. Errors are compared by NAME, as `strerror-xcheck`
does and for the same reason. `regerror.c` is left out (it pulls
Plan 9's `u.h`), which is why the shim names the codes itself.
Its **section 3 is a control of the instrument**, not of the library:
ordinary brackets with no collation in them, which must stay at 0
when the collation code changes.
`sys/src/ape/lib/libressl/test/` is separate: it is
upstream's own ML-KEM and SHA-3 vectors, run by `mk test` there.

Beyond that, testing is still mostly ad-hoc — compile a program under
APExp and see whether it builds and runs.

## Current Development Focus (as of 2026-09)

- POSIX threading (`pthread`) — `sys/src/ape/lib/ap/thread/`
- Async I/O (`aio`) — `sys/src/ape/lib/ap/aio/aio.c`
- C11/C23 compiler features — `_Generic`, and `bool` as a real type
- perl 5.42.2 — see the section below

## The 0.6 ports: cfront and bacon

**BOTH WERE "BUILDING FINE" AND NEITHER WAS BUILDING ANYTHING, AND THE
TWO FAILURES ARE THE SAME SHAPE FROM OPPOSITE ENDS**: generated C
checked into git, so `mk' never regenerated it and never had to.

**cfront/c++lib: ALL FORTY `.c' WERE COMMITTED AT ZERO BYTES.** So
`mk install' in `cmd/c++lib' compiled forty empty translation units,
`libc++.a' built clean with no symbols in it, and the build reported
success -- *a check that cannot fail*, and one that reads exactly like
a port that has started working. The user's memory of "a crash here
before" was right and the crash had become a silent pass.
**The mechanism is the rule, `> $target'.** Every `%.c:' rule was
`c++ -F ... > $target', and a shell redirection CREATES the file
whatever the command then does. They are `-o $target' now: the
driver's -F arm only `cp's once cfront has returned, so a failure
leaves no target and mk stops where the fault is. The forty files are
`git rm --cached' and `.gitignore'd -- the mkfile's own `CLEANFILES'
says `"*.c"', so they were build output all along.
**cfront CANNOT produce an empty file, which is what makes the empty
files evidence rather than a symptom.** Built on the host with gcc
(`make -C src', first try, no patches) and measured: fed a ZERO-BYTE
input it exits **0 and writes 409 bytes** -- version stamp, `__mptr'
typedef, `__ptbl_vec' declaration; fed a TRUNCATED input it exits
**14** and writes partial output. *There is no input for which cfront
both succeeds and emits nothing.* So an empty result means cfront did
not run, and `c++' now refuses it by name instead of passing it on.
**AND READING THE DRIVER FOUND A SECOND BUG THAT HAS ALWAYS BEEN
THERE: `rc' HAS NO `continue'.** The -F arm ended in `continue', which
rc looked up as an external command, did not find, and fell straight
through into step 4 -- so **every `c++ -F' has also been running `pcc
-c' over its own output.** Worse with `-o': the `obj' chain put
`$outfile' on the object path in -F mode, so the fix to `-o $target'
would have had pcc OVERWRITE the generated C with an object file. Both
halves are fixed, and the `if not' chain became one guarded
assignment. *This is the recorded "rc has no `break'" rule arriving in
its other spelling, in a file written after that rule was written
down.*
**WHICH STAGE IS NOW ONE RUN RATHER THAN ONE ROUND EACH.** The
pipeline is `pcc -E' -> `ns_strip' -> `cfront', and "the output is
empty" says nothing about which of the three went quiet; they fail
differently and need different fixes. `fn stages' prints the byte
count of all three, always on a failure and under `-v' otherwise, with
`-' for a stage not reached. *Not reaching a stage is itself the
answer.* **The host cannot settle it**: a host `pcc -E' dies in
`amd64/include/ape/stddef_arch.h' on `#include "/sys/include/ape/..."',
the same absolute-path wall the `readdir.c' syntax check hit, so the
preprocessing half is only measurable on the VM.

**bacon/BASIC: THE COMMITTED GENERATED C WAS A TRUNCATED CONVERSION,
AND gcc SAYS SO -- 50 ERRORS.** Not a kencc question and not a libap
question: `src/bacon.bac.c' was **276KB against a correct 531KB**, and
the damage is what half a transpilation looks like -- `char*
b2c_loop_result` immediately followed by `long b2c_loop_result`,
`FILE* g_CFILE` three lines above `char* g_CFILE`, `IIF`, `INDEX`,
`LOOP`, `MAX`, `MIN` and `MONTH` each `#define`d twice with different
bodies, and string literals cut open mid-escape. *The one-command
check against gcc is what separated "kencc cannot build this" from
"nothing could build this", and the screenful of `Macro redefinition'
and `external redeclaration' from pcc reads exactly like a kencc
complaint.*
**REGENERATED with the tree's own `bacon.sh' (shell BaCon, bash
5.2.21) from the tree's own `bacon.bac', and the new output is
clean**: `gcc -fsyntax-only` **0 errors, 0 warnings**, 0 in the
classes 6c treats as fatal (`incompatible-pointer-types',
`implicit-function-declaration', `int-conversion'), and **every header
it includes exists under `sys/include/ape' or `amd64/include/ape'** --
nothing missing, including `sys/socket.h', `netdb.h', `arpa/inet.h',
`sys/utsname.h' and `wctype.h'. Four stale per-function headers
(`Get_Var', `Mini_Parser', `Parse_Equation',
`Pre_Tokenize_Functions') are gone; they are inlined now.
**And it is not only a compile**: built on the host it answers
`BaCon version 5.0.3` and converts a `FOR`/`PRINT` program, so the
generated converter runs. *That is the control a syntax check cannot
give.*
**`cmd/basic/mkfile` carried `LIB=.../liblua.a'**, copy-pasted from
`cmd/lua'. In `mkone' `$LIB' is a PREREQUISITE of `$O.out' handed
straight to `$LD', so bacon was linked against Lua's archive and could
not be built until lua had been. Removed; bacon needs only libap.
`HFILES' now lists all 81 generated headers -- `bacon.bac.c' includes
`bacon.bac.h', which includes the other 78, so a regeneration changes
files that appear nowhere in OFILES. *The `tclBinary.c'/`config.h'
rule for the fourth time.*
**TK'S HEADERS ARE INSTALLED NOW -- AND DOING IT FOUND THAT `tcl.h'
HAS NEVER BEEN USABLE.** `sys/include/ape/tcl.h' was installed ALONE,
and its line 2433 is `#include "tclDecls.h"', which was not installed
at all. So `#include <tcl.h>` from anything outside Tcl's own build
has always been a fatal error on the first line -- *the `#pragma lib'
in it has never once been reached*, and the convention bacon's Tk
support was to be modelled on did not work. **The control fires
exactly**: with the old set staged, `tcl.h` alone gives
`fatal error: tclDecls.h: No such file or directory`; with the new
set, 0 errors.
**The closure was MEASURED rather than reasoned**: a `#include <tk.h>`
probe compiled against a staged copy, files added until it was clean,
then `gcc -M` asked which of them were actually reached. Twelve:
`tcl.h`, `tclDecls.h`, `tclPlatDecls.h`, `tk.h`, `tkDecls.h`,
`tkIntXlibDecls.h` and `X11/{X,Xfuncproto,Xlib,Xutil,keysym,keysymdef}.h`.
**Tk bundles its own X11** in `external/tk/xlib/X11` (the stub set it
uses where there is no X server), and `Xlib.h` there ends by including
**`tkIntXlibDecls.h`** -- an *internal* Tk header reached from a public
one, which is upstream's design on a non-X platform and not something
to tidy away. All 15 of the bundled X11 headers are installed, not
just the six: a Tk client that uses an atom or a cursor reaches
`Xatom.h`/`cursorfont.h` directly, and six would make that fail for no
reason. *The six are a measurement; the other nine are a judgement and
are marked as one.*
**`#pragma lib` placement is load-bearing.** `tk.h`'s goes BEFORE its
`#include <tcl.h>`, because a kencc static link resolves archives in
the order recorded and libtk needs libtcl -- tcl.h carries its own
pragma, so putting libtk's first is what makes the order libtk, libtcl
rather than the reverse. **And it names four libraries where the rest
of `sys/include/ape` names one**, which is a deliberate departure:
`cmd/wish/mkfile` links `libtk libtcl libdraw libpng libz libap` in
that order, because Tk's Plan 9 backend draws through libdraw and its
photo reader uses libpng. With `libtk.a` alone a program that includes
the header compiles and then fails to link.
**Verified against the REAL include tree, not a staging guess**:
`Tk_Window` and `Display *` both resolve, 0 errors, with the APE
headers staged and their `"/sys/include/ape/..."` absolute includes
sed'ed out -- the same host wall `readdir.c` hit, and the same way
round it. **The Tcl and Tk builds are untouched**: both mkfiles put
`-I$TCLSRC/generic`/`-I$TKSRC/generic` ahead of `sys/include/ape`, so
each still compiles its own copy.

**THE VM RUN FOUND THE REAL CAUSE OF THE SILENCE, AND IT WAS MINE TO
FIND EARLIER: `$status' IS CLOBBERED BY THE VERY NEXT COMMAND.**
Every failure arm of `rc/bin/ape/c++' read
`if(! ~ $status ''){ cleanup; exit $status }' -- and `cleanup' is
`rm -rf', which SUCCEEDS, so `$status' was the empty string by the
time `exit' evaluated it, and `exit '''` is exit 0. **Seven arms,
every one, since the file was written.** *That is the complete
explanation of the forty zero-byte `.c' files*: mk saw a recipe that
had "succeeded" and went on. It is also why the run with cfront
crashing on thirty files walked through all thirty and only stopped
afterwards at `pcc: Can't open input file abs.c' -- a message about
the consequence, two steps from the cause. `$status' is captured into
a variable first now and `die' exits a fixed one-word token, because
a Plan 9 trap status is several words and `exit' takes one. *I had
named `continue' and the `> $target' redirection as the mechanism and
both were real, but neither was load-bearing: this was.*
**`mk clean' DID NOT CLEAN, for a third reason**: `CLEANFILES= "*.c"'
-- mk gives double quotes no meaning and passes them through, so the
recipe asked rc to remove one file literally named `"*.c"'. So a
stale or empty generation survived every clean and was compiled
again. `cmd/perl/mkfile' has had `CLEANFILES = *.c' right all along.
**THE INSTRUMENT PAID IMMEDIATELY**: every line of the run reads
`c++: <file> bytes: cpp N ns_strip N cfront N', and cfront's column
is 1200-3500 rather than 0 -- so **cfront runs, parses, emits its
preamble and then dies**, which is a completely different problem
from the one the empty files suggested. The crashes group by
DIRECTORY and each group shares one pc exactly: `complex/` 13 files
at `general protection violation pc=0x280db8`, `stream/` 16 files at
`fault write addr=0x480010 pc=0x200ed6`, `in`/`intin` at
`fault read addr=0x0 pc=0x297a82`. *A fixed faulting ADDRESS across
sixteen different inputs is a fixed object, not a wandering pointer.*
Five files already convert cleanly (`_ctor`, `_delete`, `_dtor`,
`_handler`, `pure`), which are the ones with no class member
functions.
**AND THE HOST DOES NOT CRASH AT ALL.** cfront built with gcc and
**AddressSanitizer** (`src/cfront_stubs_asan.c`, which needed one
missing `__cfront_pre_main` added locally) was run over EVERY source
in `lib/`: **0 ASAN findings, no crash, exit 5 or 14 with real C++
diagnostics instead.** So the two runs differ in exactly two things
-- the compiler that built cfront (kencc against gcc) and the
PREPROCESSED INPUT, since the two cpps do not emit the same bytes
(25768 against 26557 for `abs.cpp`). **`c++ -K' keeps the
intermediates** so the VM's own `$pp` can be run through the host's
ASAN cfront: a crash there means the input, no crash means the code
generation. *One file settles a question that reading cfront cannot.*
**The host diagnostics are worth their own round and need no VM**:
`sys/include/ape/c++/iostream.h:224` gives
`ostream::operator <<() cannot be redeclared in class declaration`
four times, `_arr_map.cpp` gives
`operator delete()'s 2nd argument must be a size_t`, `placenew.cpp`
`two definitions of operator new()`, `abs.cpp` `two definitions of
norm()`. Several of these are cfront failing to tell two OVERLOADS
apart, which on a 64-bit target is the shape of a type-signature
comparison that collapses `int` and `long`.
**`<values.h>` DID NOT EXIST and fourteen files include it.** Three
use its macros for real (`perl/pp_sys.c`, `p2c/src/trans.h`,
Devel-PPPort's `limits`), and `cfront-C4/lib/new/_arr_map.cpp` -- in
cmd/c++lib's OFILES -- includes it and uses NOTHING from it, so a
whole object failed over a vestigial line. Written now, and **every
value is DERIVED from `<limits.h>`/`<float.h>` rather than
transcribed**: kencc's `long` is 32-bit where the host's is 64, and
this tree has already spent three rounds on constants that existed
twice and disagreed. One definition, and it is somewhere else. With
it `_arr_map` preprocesses and reaches real diagnostics.
**`TCIFLUSH`, `TCOFLUSH` and `TCIOFLUSH` were missing from
`<termios.h>`** while `tcflush(int, int)' was declared in it -- a
function the header promises whose second argument could not be
named. Of POSIX's four groups it was the only one absent, so the gap
read as nothing at all until bacon's `__b2c__getch' used it and the
build stopped at `name not declared: TCIFLUSH'. 0/1/2, the glibc and
musl assignment; nothing in libap reads the value, since
`termios/tcgetattr.c' casts `queue_selector' to void. **NOTICED, NOT
FIXED**: that no-op is right for the KERNEL and questionable for this
LIBRARY, whose select() copy process does hold unread bytes a
conforming TCIFLUSH would discard. Nothing has measured it.

**THE TERMIOS FIX BROKE EVERY APE BUILD, AND IT WAS A COMMENT.** The
block added beside `TCIFLUSH` named the tcflow group with a glob
rather than spelling the macros out, and that glob contained a star
followed by a slash -- **the two characters that END a C comment**.
It closed itself mid-sentence, everything after became code, and the
apostrophes in the prose then read as character constants: four
`Unterminated string or char const` and a
`syntax error, last name: TC`, *not one of which mentions a comment*.
*A comment containing the close sequence is not a comment*, and a
header is the one file where that breaks every translation unit
rather than one. **I had compile-verified `values.h` in the same
commit and not `termios.h`** -- the check existed and was not applied
to both.

**SO `apehdr-sweep.py` EXISTS NOW, AND IT PAID BEFORE IT WAS
FINISHED.** It compiles a file whose whole content is
`#include <that header>` for each of the 149 in `sys/include/ape`,
with the BUILD's include path in the BUILD's order. **149 headers,
23 known-not-standalone, 0 findings** -- and the control fires:
reintroducing the comment bug reports `termios.h: unknown type name
'TC'` and nothing else.
**Its first version reported 39 failures and 16 of them were ITS
OWN**: it flattened `$objtype/include/ape` and `sys/include/ape` into
one directory, where the two collide, instead of passing them as two
`-I` in order. *An instrument whose include path is not the build's
include path is measuring a different program* -- `apdecl-sweep`
learned that exact lesson the exact same way, and I made the mistake
again in the next sweep I wrote.
**THE OTHER 16 WERE REAL: `Lock` IS DEFINED TWICE.**
`qlock.h` includes `<lock.h>`, which typedefs `Lock`, and then
carries its own copy guarded by **`#ifndef Lock`** -- and `Lock` is a
TYPEDEF, not a macro, so the preprocessor has never heard of it and
that test is always true. The duplicate was always emitted. Textually
identical is not compatible: each `typedef struct { int val; } Lock;`
defines its own ANONYMOUS struct, so they are distinct types sharing
a name, which C forbids. `<pthread.h>` includes both files, so
**sixteen of the 149 headers could not be compiled by a
standards-strict compiler at all**; kencc tolerated it, which is
exactly why it survived. *This is the `PATH_MAX`/`NGROUPS_MAX` rule
-- when a name is wrong, grep for EVERY definition of it -- arriving
for a TYPE, where the cost is a layout rather than a value.*
**And three entries of the sweep's own exemption list were WRONG**,
which it reported rather than hid: `qlock.h`, `tclPlatDecls.h` and
`tkIntXlibDecls.h` were listed as not-standalone and all three
compile. An exemption that starts passing is a finding too, or the
list becomes a set of excuses nobody shortens.

**cfront: THE DRIVER WORKS NOW AND mk STOPS AT THE FAULT.** The run
reads `c++: FAILED at cfront on arg.cpp -- cfront 250970: sys: trap:
general protection violation pc=0x280db8` followed by `cpp 25897
ns_strip 25897 cfront 1265`, and `mk` exits `cxxfail` on the FIRST
file instead of marching through forty. *The `$status` fix is
confirmed where it was found.*
**The crash is ONE LINE: `table.c:1455`, `while ((*__2p))`** --
`table::grow` walking its name array and dereferencing
`np[j]->expr.string`. **One line above it sits a hand-added guard,
`if ((long long)__2s < 0x200000) continue;`** -- so a garbage string
pointer in this table is a phenomenon this fork already knew about
and papered over with a magic number rather than diagnosed.
**TWO MECHANISMS OFFERED BY THE STACK AND BOTH REFUTED BEFORE BEING
BUILT ON.** `acid` showed
`insert__5tableFP4nameUc(__1nn=.., __0this=.., __1k=0x7fff00000000)`,
and `0x7fff00000000` is a 64-bit slot holding the high half of a
stack address with the low half zeroed -- the exact shape of this
tree's 32-bit-`long` invariant. **But the real declaration is
`(__0this, __1nx, __1k)`, `this` FIRST**, and acid printed `__1nn`
first: *its argument order does not match the declaration, so its
value-to-name assignment cannot be trusted here*, and the lead
dissolves. The second was the build-flag difference -- the host
passes `-D__HAVE_SIZE_T` and the mkfile does not: **referenced
nowhere in the sources**, inert. `-D__cfront_have_bool` likewise
changes nothing the host does not already get, since the `enum bool`
it suppresses is already behind `!defined(__GNUC__)`.
**So the decisive experiment is still the one `-K` was built for**,
and it is now one file: the VM's own `$pp` through the host's ASAN
cfront. **And `lstk()` rather than `stk()` is the better command**
-- it prints LOCALS, so `__1j`, `__2s` and `__2p` say directly
whether the index is in range and what the pointer holds, where the
arguments have already proved misleading once.

**AND `lstk()` NAMED IT: A `const char *` HOLDING ITS OWN TEXT.**
`__2s = 0x6f69736963657270` and those eight bytes little-endian are
**"precisio"** -- the first eight characters of the identifier
`precision`. `table.c:1450` is
`__2s = (__1np[__1j])->__O2__4expr.string;` and 1455 dereferences it.
*Third time in this tree a pointer has contained characters*, after
bash's `ifs_value` holding `'.'` and `date`'s `tm_zone` holding
`4865`.
**AND acid HAD TO BE CALIBRATED FIRST, which is what stopped a fourth
false lead.** Every int local looked like garbage -- until the pairs
line up:

```
  __1j = 0x474c200000001a      __1hash = 0x474c20
  __1i = 0x2b2cfb00000003      __1sick = 0x2b2cfb
  __2oerror_count = 0x47552000000000   __1n = 0x475520
```

**In every pair the HIGH half of the "garbage" IS the neighbouring
variable**: acid reads eight bytes for a four-byte `int`, so the low
half is the value and the high half is the next slot. `__1mx` reads
`0xa5` = **165**, and `(g*3)/2` for `g = 0x6e` is 165 exactly. *So
every int in that dump is correct and merely mis-printed, and `__2s`
-- a genuine eight-byte pointer slot -- is the one value that is
really wrong.* Three independent pairs agree on the artefact before
anything was built on the one that did not. This is the `stk()`
lesson again one level down: **acid's own display is a claim like any
other.**
**THE TRANSLATOR WROTE ITS OWN ANSWER INTO THE SOURCE, AND THAT IS AN
ORACLE THIS TREE HAS USED BEFORE.** Every generated struct in
cfront's C carries the size the translator computed --
`struct expr { /* sizeof expr == 40 */`, `name == 144`,
`node == 3` -- **132 of them across the `.c` files**, against tar's
nine. GNU tar's `union block` was 520 here where everything else says
512, because `6c/swt.c`'s `align()` rounds every struct up to 8
(`Asu2`) and aligns a nested struct member to 8 (`Ael1`). *A wrong
field OFFSET is exactly what puts an identifier's text where a
pointer should be*, so the sizes are the cheapest proxy for the
question the crash asks.
**`struct node` is already a guaranteed disagreement**: `TOK` and
`bit` are both `unsigned char` (`typedef.h:19-20`), so it is **3 on
gcc and 8 under kencc**. Whether that matters depends on whether
anything strides over a `node`; field offsets stay right and what
breaks is `sizeof` used as a stride. *The probe reports the fact and
does not decide the consequence.*
**`sys/lib/tests/cfrontsz-probe.py` is the instrument**, the
`tarblock-probe` idiom generalised: it extracts `main.c`'s preamble
(the file whose declarations are the largest superset, 47 tagged
types), emits a probe asking `sizeof` for each beside the recorded
number, and **runs the gcc control itself** -- 47 of 47, **0
disagreements**, which is what says the extraction is right. *An
instrument that cannot reproduce the known answer has not earned the
right to report an unknown one*, and a bad extraction would otherwise
produce a probe that compiles and measures nothing. It refuses to
print the VM command unless the control passes. The pcc flags are
cfront's own from `cmd/cfront/mkfile`, for the reason `tarblock-probe`
records: built with different flags it measures a different header.
Each type is asked with the KEYWORD it was declared with, since the
`__Q2_4expr4__C1` family are unions.
**TWO cfront HYPOTHESES REFUTED BEFORE THIS ONE**, both cheaply: the
host passes `-D__HAVE_SIZE_T` and the mkfile does not -- **referenced
nowhere in the sources**, inert; and `-D__cfront_have_bool` suppresses
an `enum bool` that is already behind `!defined(__GNUC__)`, so the
host gets the same thing.

**bacon's REMAINING GAP WAS ASKED ALL AT ONCE RATHER THAN ONE PER
ROUND, and the answer was TWO names.** Preprocessing the whole of
`bacon.bac.c` against the staged APE headers and collecting every
`undeclared` identifier gives exactly `IP_MULTICAST_LOOP` and
`IP_MULTICAST_TTL` -- *a complete answer where `TCIFLUSH` had been a
sample of one*. One command instead of one round each, which is the
rule this file already carries for counting a string in the corpus.
**The IPv6 spellings were all there and the IPv4 ones were not**:
`network/socket.c` already accepts `IPV6_MULTICAST_HOPS`, `_IF` and
`_LOOP` and had no IPv4 counterpart at all, so a program could name
the v6 option and not the v4 one. Added with `IP_MULTICAST_IF`,
`IP_ADD_MEMBERSHIP`, `IP_DROP_MEMBERSHIP` and **`struct ip_mreq`** --
the struct deliberately, because declaring `IP_ADD_MEMBERSHIP`
without the type of its argument is the gap `<termios.h>` had for
`tcflush` one round earlier: an option a program can name and cannot
call.
**The NUMBERS are this file's own and the comment says so.** 1/7/8/9
match neither 4.4BSD nor Linux, so there is no external numbering to
be consistent with and none is needed -- nothing transmits these and
`socket.c` is the only consumer in the tree. Distinctness is the only
requirement.
**AND THE THREE OPTIONS GET THREE DIFFERENT ANSWERS, which is the
whole content of the change.** `IP_MULTICAST_IF`/`_TTL` join the
accept-silently list beside `IP_TTL`. **`IP_MULTICAST_LOOP` is split
by its VALUE**: enabling it asks for the state the socket is already
in, so 0 is true; disabling it asks for something this stack cannot
do, and 0 would say the packets had stopped coming back when they had
not -- ENOPROTOOPT. *A stub that answers "failure" is not the same as
one that answers "nothing to do", and the two halves of this one
option fall on opposite sides of that line.* And
`IP_ADD_MEMBERSHIP`/`IP_DROP_MEMBERSHIP` are deliberately NOT listed,
so they reach the default and refuse: Plan 9 **can** do this
(`/net/udp/N/ctl` takes `addmulti`/`remmulti`), so it is a gap rather
than a limit, and accepting silently would be the worst of the three
-- a program would believe it had joined a group and then receive
nothing, with no error anywhere to say why.

**AND THAT RUN FOUND A SECOND BUG THE PER-HEADER SWEEP CANNOT SEE:
`<stdlib.h>` DECLARED `uname` AND `getrusage`.** It defines neither
`struct utsname` nor `struct rusage` and includes neither header, so
each struct named in those parameter lists was a **new, incomplete
type scoped to the declaration** -- distinct from the real one. Any
translation unit including `<stdlib.h>` and then the right header got
`conflicting types`, and bacon includes both. *This is the `Lock`
bug a second time*: one name declared twice, the two spellings not
compatible, kencc tolerating what the standard forbids. Removed --
POSIX puts them in `<sys/resource.h>` and `<sys/utsname.h>`, both
already declare them correctly beside the struct, and the only caller
in the tree (`plan9/__p9_syscall.c`) includes `<sys/resource.h>`
itself. **bacon's undeclared count is now 0.**

**AND THE SAME QUESTION AT THE LINK STAGE GAVE THE SAME SHAPE OF
ANSWER: `random' AND `srandom' DID NOT EXIST.** With the undeclared
count at 0 bacon compiled and then failed to link --
`Handle_Tree: undefined: random', `main: undefined: srandom in main'.
**Asked all at once rather than one per round**, as the header gap
was: compile `bacon.bac.c` on the host, take `nm -u`, and subtract
every name libap defines. 120 undefined symbols, and after those two
the remainder is **nine glibc artefacts of the host compile**
(`__errno_location`, `__isoc99_sscanf`, `__stack_chk_fail`,
`__xpg_basename`, `_setjmp`) and four VARIABLES my function-shaped
grep could not match (`optind`, `opterr`, `optarg`, `stdin`), all of
which are present. *So the link gap was exactly two names, and that
is a complete answer rather than the first of a series.*
**`rand.c` was NOT reusable, which is the one case in this tree where
reaching for the neighbour would have been wrong.** It is Mitchell &
Reeds with a state of 607 longs -- **2428 bytes** -- and
`initstate()` is handed 8 to 256 bytes and must keep the generator's
whole state INSIDE it. There is no arrangement under which that fits.
*Four times now the library has held a working version of the thing
it could not do; this is the fifth look and the first where the
answer is no.*
**BIT-COMPATIBLE WITH glibc AND 4.4BSD, deliberately.** A seeded
sequence is something programs reproduce across machines, so "a
generator with the right distribution" is not the specification --
the numbers are.
**AND THE DEFAULT STREAM COSTS NO TABLE.** glibc ships 31 magic words
for the unseeded state; 4.3BSD's own comment says that table is the
state `initstate(1, randtbl, 128)` leaves, the rear pointer returning
to 0 because srandom discards exactly `10*deg` values. So `srandom(1)`
on first use reproduces it, and **section 1 of the cross-check
measures that claim rather than assuming it** -- a 31-word table typed
by hand would have been this tree's fourth duplicated constant, and
its failure would arrive as a wrong number rather than a diagnostic.
**`random-xcheck.c` is the instrument** (host program, TWO compiles,
the `strftime-xcheck` rule): 2000 default draws, 400 seeds x 50, all
**five** `initstate` sizes including the state word each writes, a
`setstate` round trip, the previous-state return value and the
under-8-bytes refusal. **0 failures**, and section 4 **found the one
real bug**: `setstate` read word 0 BEFORE saving the old state, so
handing it the state already in use rewound to the last `srandom()`
where glibc continues. Every other section passed. *The ordering is
the whole content of that function and reading alone would have
shipped it backwards.*
**TWO CONTROLS, AND THE FIRST VERSION OF THE SECOND WAS WORTHLESS.**
Section 0 asks the MACHINE whether `random` and `ap_random` are the
same address, since the vacuous-rename trap is what strftime-xcheck
fell into; then it asks whether the comparison can report anything at
all. That second control was first written as `b & 0x7fffffff` for the
"wrong" value -- and `random()` never returns anything above 2^31, so
the mask was a no-op and the broken number was the right one. It
printed a note and passed. *A control whose wrong answer is the right
answer is not a control* -- thirteenth instrument fault, and the only
one so far caught before it shipped. It is two different seeds now,
and it reports 32/32.
**Section 4 had the same defect and the fix found the bug**: restoring
the state already in use is a no-op in glibc, so that version asserted
nothing. Switching away to a second state of a *different size* and
back is what asks the question.

**AND THE PROBE'S OWN ANSWER WAS SEVEN-EIGHTHS NOT ABOUT kencc.**
The VM run said `8 of 47 disagree with the translator', and the
recorded sizes are the **generating machine's**: cfront's C was
produced on Linux, so every system type in it carries glibc's answer.
`__sigset_t` 128 against APE's 64, `_fpstate`/`_libc_fpstate` 512
against 504, `_xsave_hdr` 64 against 32, `__pthread_rwlock_arch_t` 56
against 48 -- *differences APE is not obliged to match and mostly
should not*. Two more are kencc's 32-bit `long` showing through a
`__clock_t` and an `si_band`. **The oracle is an oracle only for the
translator's OWN structs**, and exactly one of those disagrees:
`node`, 3 against 8, the case predicted before the run.
**And `node` cannot be the crash**: `struct name` **inlines** node's
three fields (`base__4node`, `permanent__4node`, `baseclass__4node`)
rather than embedding a `struct node`, because cfront's C flattens
inheritance -- so node's size never enters name's layout.
**BUT THE PROBE WAS ASKING THE WRONG 47 TYPES, AND ITS CONTROL COULD
NOT SEE THAT.** It extracted main.c's PREAMBLE -- everything above
the first function definition -- and cfront's generated C
**interleaves** declarations with definitions, so it got 47 of
main.c's **97**. The gcc control reproduced all 47 and reported 0
disagreements, which was *true*. **Correctness and completeness are
different properties and only one of them was being checked.** Among
the fifty left out were `name`, `expr` and the whole
`__Q2_4expr4__C*` family -- **the exact types the faulting line
dereferences**. *The probe ran, passed its control, and could not
have answered the question it was built for.* Extraction skips
function bodies now, and the missing half of the control is one line:
every tagged type in the file must survive into the probe. 97 of 97.

**AND `-P` WAS ALREADY TAKEN, WHICH THIS FILE'S OWN PLAN DID NOT
NOTICE.** The recorded plan said "`-P` in `sys/src/ape/config`'s
CFLAGS" and justified it with *"the flag costs nothing to parse:
`cc/lex.c`'s ARGBEGIN `default:` arm does `debug[c]++` for any unknown
letter"* -- true, and `P` is not unknown. **Every backend's `peep.c`
uses `debug['P']` for peephole tracing and `reg.c` reads it to
disable register allocation**, so `-P` would have changed CODE
GENERATION while claiming to change layout. *A flag one letter from
another flag is checked, not recalled* -- the rule was already in this
file, and the plan it would have caught was also already in this file.
**It is `-J` now, and a NAMED global `conformalign` rather than a
debug letter**, so the collision cannot recur by someone counting
free letters again. Free uppercase were E, J, O: `E` is `pcc -E`, `O`
reads as an optimisation flag.
**AND pcc HAD TO BE TAUGHT IT EXPLICITLY.** `sys/src/cmd/pcc.c`'s
`ARGBEGIN` has **no `default:`**, so a flag it does not name is
silently dropped -- the build would look exactly right and the layout
would not change. *For a layout flag that is the worst available
failure*, and it would have read as "the compiler change did not
work".
**THE CHANGE IS SMALLER THAN THE SLOGAN.** "kencc aligns everything
to 8" is not what the code does: `Ael1` already answers
`ewidth[etype]` for scalars, which IS their natural alignment on
these targets. The defect is two cases -- `Asu2`'s unconditional
`SZ_VLONG` tail padding, and `Ael1`'s `w <= 0` arm, which catches
struct and union members because `ewidth[TSTRUCT]` is negative. So
`-J` is two lines in each of the ten backends plus one computation in
the shared front end: `sualign()` now records each struct's own
alignment in `Type.talign`, as the max over its members of
`align(1, member, Ael1)` -- *the same identity `__alignof__` already
uses*, rather than a second expression of the same fact that could
drift from it. It follows `packflg` for free, since under
`#pragma pack on` every member aligns to 1.
**IT IS NOT A PER-PACKAGE FLAG, which is the opposite of how it is
natural to reach for it.** -J changes every struct the translation
unit sees, `<stdio.h>`'s and `<sys/stat.h>`'s included, so one package
built with it against a libap built without it disagrees about
`FILE`, `struct stat` and `DIR` -- **silently, with no link error,
because every symbol still resolves.** The safe unit is a whole
self-consistent world: all of APE after a `distclean`, or nothing.
For a few on-disk structs in one package `#pragma pack` is still the
right tool and costs no rebuild. **It is therefore NOT enabled in
`sys/src/ape/config`.**
**`structalign-test.c` is the instrument and it needs THREE runs**:
gcc (0 failures, and the numbers in the file came from that run --
my own arithmetic said 149 where gcc says 150), then `pcc -DPLAN9`
**without** `-J`, which must FAIL about twelve checks, then with it,
which must pass. *The middle run is the whole point*: a test that
passes under `-J` looks identical whether the flag works or the
compiler was always conforming. It checks **offsets as well as
sizes** -- a wrong size breaks a stride, a wrong offset puts one
member's bytes where another is read, which is the shape of a
`const char *` holding the text `precisio`. `-DPLAN9` is not
decoration: section 5's `#pragma pack` is behind it exactly as
tar.h's is.
**One non-conformance `-J` does NOT fix, reported as a PROBE rather
than asserted**: kencc allocates bit fields in whole `tfield` units,
so `struct{unsigned x:3; unsigned y:5; char c;}` is 8 here and 4 on
gcc. Different code, different question; asserting it would make the
test report a failure the flag never promised.
**NOT COMPILED ANYWHERE YET.** kencc's sources need Plan 9's `<u.h>`
and `<libc.h>`, so the gcc sweep this tree uses before shipping
cannot be run on them -- the first build is the VM's. *That is a
weaker position than every other change this round and is worth
saying rather than leaving to be discovered.*

**THE 97-TYPE PROBE RAN, AND `name` -- THE CRASH'S OWN STRUCT -- IS
EIGHT BYTES TOO BIG.** `14 of 97 disagree, 83 agree`, and seven of
the fourteen are cfront's own types rather than glibc's:
`node` 3 -> **8**, **`name` 144 -> 152**, `basic_inst` 168 -> 176,
`funct_inst` 200 -> 208, `state` 88 -> 96, `templ_compilation`
1 -> 8, `templ_inst` 200 -> 208. The other seven are the platform
types already accounted for.
**`name` is the type `table.c:1450` dereferences** --
`__2s = (__1np[__1j])->__O2__4expr.string` -- and `__O2__4expr` is
the SECOND of four unions inside it, so a member that grows ahead of
it moves that union's offset and `.string` reads the wrong eight
bytes. *That is exactly a `const char *` holding the identifier's own
text.* **The padding hypothesis is live again**, and the 47-type run
could not have seen it: `name` was one of the fifty types the
preamble extraction dropped.

**BUT THE TWO INSTRUMENTS DISAGREE ABOUT THE SAME COMPILER, AND THAT
IS THE ROUND'S REAL FINDING.** Minutes apart, same `pcc`:
`cfrontsz-probe` says kencc PADS (`node` 8, `name` 152), and
`structalign-test` says it does NOT -- `struct{char a[3];}` is **3**,
`struct{char a[500];}` is **500**, and **all three runs report 0
failures, including the one without `-J` that was predicted to fail
about twelve checks.** `round()` and `SZ_VLONG` are exactly as read,
so the old rule must answer 8. **Both cannot be true of one
compiler**, so one run is not measuring what its output says -- and
*neither instrument recorded which compiler built its binary*.
**`-J` NOW PREDEFINES `__APEXP_CONFORMALIGN__`**, because `pcc` drops
a flag its ARGBEGIN does not name and `6c` turns an unknown letter
into a debug counter, so **a stale compiler and a working one print
the same thing**. *A null result with two explanations is not a
measurement* -- the `_ttymark`/`_getcwdmark` idiom, for a COMPILER
rather than a library, and the first thing this flag should have had.
`structalign-test` prints it before anything else and gained a
**section 7 PROBE** carrying cfront's own `node` shape -- three
TYPEDEF'd unsigned chars -- beside the char ARRAY section 1 uses, so
one run tells the two instruments apart rather than two rounds.
*The predicted failure did not fire and the prediction was written
down; that is the condition doing its job, not the flag.*

**AND `-J` WAS WORKING THE WHOLE TIME -- 14 of 97 -> 7, EXACTLY THE
PREDICTION.** All seven of cfront's OWN types fall into line under
`pcc -J`: `node` 3, **`name` 144**, `basic_inst` 168, `funct_inst`
200, `state` 88, `templ_compilation` 1, `templ_inst` 200. What is
left is the seven glibc types, which `-J` cannot touch because they
describe the machine that GENERATED the C -- and the two `__Q3_`
entries confirm the reading rather than merely vanishing: `_C4` is
**20** (`__clock_t` four times over at 4 bytes) against Linux's 32,
`_C6` is 8 (`long si_band` + `int si_fd`) against 16. *The 32-bit
`long` invariant showing through, not padding.*
**THE "FLAG NOT PICKED UP" MESSAGE WAS THE MARKER, NOT THE FLAG, AND
IT COST THREE REBUILDS.** `pcc` runs **`/bin/cpp` ITSELF** and pipes
it into `cc` (`pcc.c:299`'s `dopipe`), so the source reaches `cc`
**already preprocessed** -- and neither `dodefine()` in `cc`'s own
symbol table nor `cc`'s `defs[]` can define a macro the source will
ever see. *There are THREE preprocessors in play and only the one
`pcc` spawns actually runs*; the first two attempts configured the
other two. **Name the preprocessor that RUNS, not the one with the
right name** -- the shadowed-`config.h` lesson a third time.
**And the two instruments never disagreed.** `structalign-test` was
compiled **with** `-J` and `cfrontsz-probe` **without** it, and I
read them as the same compile for two rounds. Everything else was
cleared locally first: preprocessing the probe's own translation unit
with cfront's exact flags gives ONE `struct node`, `TOK` and `bit`
both `unsigned char`, and gcc computing 3; `cfront_translated.h`
defines none of the seven; `-B` touches only undeclared-function
diagnostics. *Two compiles differing in one flag is not two compilers
disagreeing, and the flag was in the command line both times.*

**THE OBVIOUS WAY TO TURN `-J` ON TREE-WIDE DOES NOT WORK, and that
is the finding to carry.** `-J` in `sys/src/ape/config`'s CFLAGS
reaches **32 of 137** mkfiles -- the other **105 ASSIGN `CFLAGS=`**
rather than appending `$CFLAGS`, and `cmd/cfront/mkfile:52` is one of
them. `CC` is no better: **59** mkfiles reassign it. *Both of the two
variables a build system offers for exactly this have holes, and
either would have produced the silent ABI split rather than a clean
change* -- 32 packages conforming, 105 not, every symbol still
resolving. **The only mechanism that reaches every APE compile is
`pcc` itself**, since all 59 reassignments still name `pcc`; native
`6c` builds stay on the 9front rule, which is what `cmd2/vts` and
`vtwin` need when they link the host's own `libc.a`.
**`apeabi-probe.c` is what to run BEFORE deciding that**: two
compiles and a diff, `pcc -a` against `pcc -J -a`. `-a` emits acid
definitions carrying every struct's size and every member's offset
(it is `mkone`'s own `%.acid` rule), so the diff is a complete list,
**from the compiler itself**, of everything `-J` moves inside the APE
world. An empty diff would mean the flag is free; a long one is the
cost named struct by struct before a single object is rebuilt. 0
errors against the staged headers on the host.

**AND `-J` WAS ALREADY ON FOR MOST OF THE TREE -- `pcc` ITSELF WAS
PASSING IT, AND HAS BEEN SINCE THE FLAG LANDED.** `pcc.c`'s
`if(!Aflag)` block appended **`-J` to the compiler on every
invocation**, commented *"old/new decl mixture hack"* -- a comment
describing a hack that had stopped existing, because **stock `cc`
names no `-J` at all**: it fell to ARGBEGIN's default, set
`debug['J']`, and **nothing in the whole tree reads `debug['J']`**
(grep: zero hits). A pure no-op for its entire life. Giving the
letter a MEANING therefore turned conforming layout on for every APE
compile that passed neither `-A` nor `-B` -- *the silent ABI split
the flag was built to avoid, created by the flag, live in the tree
for three commits.* **`-P` over again, one level out: I checked `cc`
for a collision and did not check the DRIVER that calls it.**
**It explains both of the round's loose ends with no slack left
over.** `structalign-test` was run as `pcc -DPLAN9` -- no `-A`, no
`-B` -- so the command written down as *the control* was byte for
byte the same compile as the one below it, which is why the twelve
predicted failures did not fire. `cfrontsz-probe` carries cfront's
own flags, which include **`-B`**, so `Aflag` was set, no `-J` was
appended, and it kept the old rule and disagreed on fourteen types
in the same minute. *Two instruments, two layout rules, one `pcc`,
and neither command line said which it was getting.* The earlier
reading -- "one was compiled with `-J` and the other without" -- was
right about the fact and wrong about the cause, and the cause is the
half that needed fixing.
**Removed from the default, so `-J` now means exactly what it says**,
and that makes the tree-wide decision **one line in `pcc.c`** rather
than 137 mkfile edits.
**AND `pcc` NAMED NEITHER `-a` NOR `-Z`, so the probe could not be
taken at all**: `pcc -a apeabi-probe.c` answers `cc: flag -a ignored`
and compiles normally. Both are forwarded now; **`-c` is required
with them** (with `-a` the compiler writes acid to stdout and makes
no object, so pcc would otherwise go on to link one that is not
there). On an older pcc, `pcc -c -W0,-a` passes it by hand. *A driver
that dropped the flag for READING a layout, standing next to one that
dropped the flag for CHANGING it.*
**A run of `apeabi-probe` on a pcc predating this is VOID** -- both
sides would have had `-J` and the diff would come back EMPTY, reading
exactly like a flag that costs nothing.
**Twelve mkfiles said `CC=$APEXPROOT/$objtype/bin/pcc`** where 48
others say plain `pcc`; normalised, since the tree already depends on
`pcc` resolving. *Inconsistent rather than load-bearing* -- and it
does not bear on `-J` either way, since all twelve named the same
program.

**AND THE ACID DIFF IS IN: `-J` MOVES SIXTEEN STRUCTS AND NOT ONE OF
THEM IS IN THE STDIO/STAT CORE.** Two compiles of `apeabi-probe`,
~1400 lines of acid each, and the whole diff is twenty-four hunks
over **two families**:
- **Network addresses**, every one of which becomes the number every
  other system says: `in_addr` 8 -> **4**, `sockaddr_in` 24 -> **16**
  (`sin_addr` 8 -> 4, `sin_zero` 16 -> 8), `sockaddr_in6` 32 -> 28,
  `ip_opts` 48 -> 44, `ip_mreq` 16 -> 8, `sockproto` 8 -> 4,
  `sockaddr`/`sockaddr_storage` 112 -> 110.
- **Locks and pthreads**: `QLock` 32 -> 24, `Rendez` 32 -> 24,
  `pthread_mutex_t` 56 -> **40**, `pthread_cond_t` 56 -> 48,
  `pthread_rwlock_t`'s members, `pthread_once_t` 16 -> 8, and the two
  anonymous lock types `_8_`/`_10_` 8 -> 4. **That is the recorded
  `Lock`-is-one-`int` invariant arriving from the other side** -- the
  very structs the two-stage-bootstrap note said would disagree with
  a native `libc.a`, which is exactly why this stays inside APE.
- Plus `termios` 32 -> 28, on its own.
**WHAT IS ABSENT IS THE RESULT.** `FILE`, `struct stat`, `DIR`,
`jmp_buf`, `sigjmp_buf`, `fd_set`, `tm`, `timeval`, `timespec`,
`dirent`, `passwd`, `group`, `rusage`, `utsname`, `hostent`,
`addrinfo`, `sigaction`, `lconv`, `regex_t`, `mbstate_t`, `sigset_t`
-- **every one unchanged**, and they are the types the flag's own
warning named as the reason it is all-or-nothing. *The feared cost
and the measured cost are different sizes, and only the probe could
have said so.*
**So the blast radius is sockets and threads**, both entirely inside
libap, neither written to disk nor shared with native code.
`/env/_fdinfo` was checked rather than assumed and is **TEXT**, so
there is no cross-`exec` layout hazard there; the one shared BINARY
object is `_buf.c`'s `Muxseg`, between a process and its own copy
process, which `mk distclean` already covers for the reason that
section records.
**SO IT IS ON BY DEFAULT NOW, in `pcc` and nowhere else.** Not CFLAGS
(32 of 137) and not CC (59 reassign it): *both of the two variables a
build system offers for exactly this have holes*, and all 59 still
name `pcc`. **Unconditional, and NOT inside the `if(!Aflag)` block**
-- that block does not run when `-A` or `-B` was given, and
`cmd/cfront` passes `-B`, so putting it there would have missed the
one package the flag was built for. Native `6c` is untouched.
**`pcc -9` is the way BACK**, and it exists for the instruments
rather than for the build: `structalign-test`'s control run and
`apeabi-probe`'s two compiles are both *differences between the two
rules*, and with no way to ask for the old one neither could ever be
taken again. *An irreversible default takes the measurement with it.*
Nothing in the tree passes `-9` and nothing should. `-J` is still
accepted and now does nothing.
**`mk distclean` BEFORE `mk install`**, and the usual reason with an
extra edge: no mkfile lists a system header as a dependency, and
nothing here makes a link fail, so a half-rebuilt tree is silent.
**What to watch, written down before the run**: sockets and threads
are the whole blast radius, so Tcl's `socket.test`/`socket_inet.test`
are the sharpest instruments the tree has for it -- a clean run there
is the confirmation, and a NEW socket failure means something is
computing a length it should not.
**THE TREE BUILDS: `mk distclean` plus `mk install` COMPLETED with
conforming layout everywhere.** *That is the weakest useful result
and is worth saying so plainly*: it confirms nothing fails to compile
or link, and the hazard this flag carries is one that produces
NEITHER. `sockaddr_in` 24 -> 16 and `pthread_mutex_t` 56 -> 40 are
silent by construction -- every symbol resolves either way -- so the
build completing is a precondition for the measurement rather than
the measurement. **The confirmation is behavioural and is still
outstanding.**

**`structalign-test`'s THREE RUNS ARE IN, AND THE MIDDLE ONE FINALLY
FIRED: 14 failures under `pcc -9`, 0 under `pcc`.** That is the first
time the control has produced the predicted failures -- the two
earlier attempts were byte for byte the same compile, because `pcc`
was appending `-J` itself. `struct{char a[3];}` 8 -> 3,
`struct{char a[500];}` 504 -> 500, `offsetof(mixed,n)` 8 -> 1,
`sizeof(struct oldgnu)` 160 -> 150, the packed nested case 10 -> 5,
and section 7's PROBE prints **3** for cfront's own `node` shape. The
`__APEXP_CONFORMALIGN__` banner is what makes the pair readable:
`-J NOT in effect` above the failures, `-J was understood` above the
zero. *A flag, a marker for the flag, and a control run that must
fail -- and only all three together say anything.*
**Section 8 PASSES IN BOTH RUNS, which is correct and is the half
worth checking.** The `sualign` bit-field bug was never gated on
`conformalign`, so a fix that only worked under `-J` would have shown
as section 8 failing under `-9` -- it does not, and `type` survives
every one of the four writes in both runs.

**AND cfront'S CRASH IS GONE -- THE PADDING HYPOTHESIS IS CONFIRMED
BEHAVIOURALLY.** `rm *.c && mk install` in `cmd/c++lib` no longer
reports `general protection violation pc=0x280db8`; cfront exits
**5** with real C++ diagnostics, and its byte column went
**1265 -> 5747**, so it now parses whole headers instead of dying
after its preamble:

```
  iostream.h:224: ostream::operator <<() cannot be redeclared ...
  abs.src.c:40:   two definitions of norm()
  c++: FAILED at cfront on .../complex/abs.cpp -- cfront 62022: 5
  c++: ... bytes: cpp 26553  ns_strip 26553  cfront 5747
```

*That is exactly the prediction written down before the run*:
`name` 144 -> 152 moved the second of its four unions, so
`__O2__4expr.string` read the wrong eight bytes and came back holding
the text `precisio`. `-J` puts `name` back to 144 and the
dereference is of a pointer again.
**AND `pcc -9` SETTLED THE ATTRIBUTION EXACTLY AS ASKED.** cfront
rebuilt with the old layout rule crashes again on the same file at
**`pc=0x280db8`** -- the same address to the digit -- with
`cfront 1265` bytes, byte for byte the pre-`-J` run. **The
`sualign` fix is in BOTH builds**, since that line was never gated on
`conformalign`, so it is excluded and `-J` is the vehicle with
nothing left over. *One flag, one rebuild, two numbers that were
written down before the run* -- and it is the first time this tree
has produced an A/B where the only difference is a layout rule and
the observable is a faulting address.
**THE SEVEN MAGIC GUARDS WERE NEVER WORKING, which is the finding
the pair hands over for free.** `table.c` carries
`if ((long long)...string < 0x200000) continue;` at **1245, 1351,
1451, 1470, 1607, 1671 and 1672** -- this fork papering over a
garbage `const char *` in seven places rather than diagnosing it.
They catch only the case where the misread eight bytes happen to be
a SMALL number, and the one that actually crashed held
`0x6f69736963657270` -- the text `precisio`, far above the
threshold. *A workaround whose own threshold the real case steps
over*, and seven copies of it meant nobody ever asked why.
**REMOVED, and the A/B was confirmed in BOTH directions first**: the
`-J` rebuild was run a second time and gave the same `cfront 5747`
and the same five diagnostics, so neither side of the pair was a
one-off piece of state. Five were a standalone `goto nxt`/`continue`;
`look__6ktable`'s was half of an `&&`; `insert__6ktable`'s was a
two-line `||`. **gcc compiles the file before and after -- which is a
SYNTAX check and not a control**, since both sides pass, and saying
so is the point: the only thing that can confirm this is the VM.
**CONFIRMED: byte-identical.** `cpp 26553  ns_strip 26553
cfront 5747`, the four `iostream.h` redeclarations, `two definitions
of norm()`, exit 5 -- the prediction was written down before the run
and every number in it matched. So none of the seven was
load-bearing, and the garbage pointer they existed for is gone
rather than hidden.
**cfront IS CLOSED AS A QUESTION FOR THIS TREE.** What remains is a
1980s front end that cannot tell two overloads apart on a 64-bit
target, reproduced character for character by the host's own gcc
build -- upstream's, not APExp's. The directory stays, off, for the
three reasons above.
**The diagnostics that remain need no VM and are already recorded**:
the four `iostream.h` redeclarations and `two definitions of norm()`
are character for character what the host ASAN build produced, and
several of them are cfront failing to tell two OVERLOADS apart --
the shape of a type-signature comparison that collapses `int` and
`long` on a 64-bit target.

**AND THE TCL RUN BESIDE THEM IS VOID, FOR A REASON THAT READ EXACTLY
LIKE A RESULT: `mk distclean` DELETED THE TEST INTERPRETER AND
`mk install` DID NOT PUT IT BACK.**

```
  before:  Total 68118  Passed 62138  Skipped  5916  Failed 64
  after:   Total 66970  Passed 55700  Skipped 11233  Failed 37
```

**A failure count that falls by 27 while `Skipped` rises by 5317 is
not an improvement**, and the `Test files exiting with errors:
brodnik.test, mutex.test` line -- absent from every previous run --
is what names the cause. Both files stop on
`package require tcl::test`: mutex.test requires it at the top level,
and **brodnik.test's `try {package require tcl::test}` has no handler
clause, so the error propagates just the same**. Two files aborting
on one line means the package was ABSENT, which means the suite ran
under plain `tclsh`.
**`cmd/tclsh/tcltest` was a `V:` target reachable from nothing while
`CLEANFILES` names it** -- so `clean` removed it and `install` never
rebuilt it. It is a FILE target with `install:V: tcltest` beside it
now (every `V:` rule for a target runs in Plan 9 mk, the idiom
`lib/itcl` already uses), so a distclean plus install leaves the
suite measurable. **`cmd/wish/tktest` had the same asymmetry and the
same fix** -- its `clean:V:` removes it too -- and the degradation
there is milder only because no Tk file aborts: the constrained tests
skip, `Failed` falls, and nothing says why.
**AND BOTH HARNESSES NOW SAY WHICH INTERPRETER THEY ARE.**
`tcl-runall.tcl` REFUSES without `tcl::test`, printing the two
commands to fix it, with `$APEXP_TCL_ANYSHELL=1` as the escape for
the one legitimate case (asking what the *installed* tclsh does);
`tk-runall.tcl` WARNS instead, because there nothing is lost but
comparability. Its marker is `testbitmap`, which `tkTest.c:222`
registers unconditionally -- `testmetrics` and `testmenubar` are
behind platform ifdefs and would report a missing tktest on a
platform that merely has no such command.
*This is the `THIS_SH=../bash` precondition for the fourth time, and
the first time it has been the BUILD SYSTEM rather than a default in
an upstream script.*

**AND THE RE-RUN UNDER `tcltest` IS THE BEHAVIOURAL CONFIRMATION OF
`-J`: EIGHTEEN FIXED, NOTHING BROKEN, NOTHING EVEN MOVED.**

```
  baseline:  Total 68118  Passed 62138  Skipped 5916  Failed 64
  with -J:   Total 68118  Passed 62156  Skipped 5916  Failed 46
```

**`Total` and `Skipped` are IDENTICAL to the digit**, which is what
makes the comparison sound at all: nothing became unrunnable, nothing
newly skipped, no file aborted -- so `Passed` +18 and `Failed` -18 is
one arithmetic statement about the same 68118 executions. The marker
is present, `exit called (code 0)`, and **the `Test files exiting
with errors` section is gone**, so this really is the test
interpreter. *The void run and this one differ in nothing but which
binary ran them, and that is the cleanest control this suite can
give.*
**AND THE SOCKET CONFIRMATION IS WITHDRAWN: THERE IS NO
`socket_inet.test`.** This round recorded *"`socket_inet.test` has
left the failing-file list entirely"* as the behavioural evidence that
`-J` had not broken the socket half of its own blast radius
(`sockaddr_in` 24 -> 16, `in_addr` 8 -> 4). **That file does not exist
and never did**: the suite has one `socket.test`, whose body is
`foreach {af localhost}` with `test socket_$af-1.1 ...`, so every
`socket_inet-*` name is GENERATED with `$af` = `inet`, and a grep for
`socket_inet-5.1` matches no file in the tree. *Its absence from the
list could not have been anything else under any outcome* -- and the
substance fails too: **`socket_inet` has four failures, 2.11, 5.1,
5.3, 7.3**, which is exactly the "`socket_inet` 4" already listed as
unread below. **A name absent from a list is not a measurement until
you have checked the name could ever have appeared there** -- an
absence has two explanations, the thing passed or it was never called
that, and only one is a result.
*The eighteen stand on `Total` and `Skipped` being identical with
`Passed` +18, which is sound. The ATTRIBUTION to sockets does not* --
so with the pthread half already recorded as skipped (`197 thread`,
`12 testmutex`), the behavioural confirmation of `-J` covers neither
family it actually moved.
**THE PTHREAD HALF IS NOT MEASURED HERE, and the skip table says so
rather than leaving it to be assumed**: `197 thread` and `12
testmutex` are SKIPPED, so `pthread_mutex_t` 56 -> 40 and
`pthread_cond_t` 56 -> 48 were barely exercised. *Half the blast
radius is confirmed and half is untouched*, which is a different
statement from "the suite is clean".
**BOTH PER-NAME QUESTIONS ARE NOW ANSWERED, AND A PER-NAME BASELINE
EXISTS AT LAST** -- `docs/notes/tcl-suite.md` carries all 43 names and
the extraction command, because *its absence is what kept this open
for rounds* while every comparison was made by total.
**`Total 68118  Passed 62159  Skipped 5916  Failed 43`**, marker,
exit 0, 167 files, four minutes, `tcl::test 9.0.3 present`.
- **`socket_inet-5.1`/`5.3` were NOT among the eighteen**: both are
  still failing, so the leftover-listener false pass did NOT return.
  That was the stated hazard and this is the good answer.
- **`event.test`/`main.test` were unchanged, not new**: by name they
  are `event-1.1` and `Tcl_Main-5.10`, the two singletons already on
  the list.
**AND 46 -> 43 IS THREE FIXED, NOTHING BROKEN, ALL THREE NAMED**:
`chan-io-41.8`, `expr-old-37.21` and `unixFCmd-2.2.2`, three entries
of the eleven unread singletons. *Three gone and the net is three, so
nothing arrived* -- the only form that confirmation can take, and the
first time this suite's movement has been attributed by name. **None
was predicted or being worked on**, so the vehicle is unidentified and
naming one would be a guess; the baseline makes the next run settle
it. (`io-6.46` and `chan-io-6.46` now both fail, which is the twins
rule working as written; zipfs is **five** `zipfs-password-*` cipher
tests where this file recorded three, one family undercounted from a
prediction rather than a regression.)

**AND THE FIRST REBUILD STOPPED IN bash -- NOT ON `-J`, ON A SHADOWED
HEADER.** `/sys/include/ape/qlock.h:44 syntax error, last name: Lock`,
compiling `general.c`. **`-I$BASHSRC/lib/intl` was on bash's CFLAGS
and that directory holds gettext's own `lock.h`** -- an `-I` is
searched ahead of the system path, so APE's `<pthread.h>`, reaching
its own `#include <lock.h>`, got THAT file, which never typedefs
`Lock`; `<qlock.h>` then hit `Lock lock;` with no such type.
**Nothing in the message says `lock.h`** -- it names the victim's line
in a header bash never mentions, which is why the four-screen command
line was no help. *Name the file that is COMPILED, not the file with
the right name*, for a header a SYSTEM header includes rather than one
the package does.
**AND THE CONFORMANCE FIX IS WHAT MADE IT REACHABLE.** `<qlock.h>`
used to carry its own `Lock` typedef behind an always-true
`#ifndef Lock`, so the shadow cost nothing however the name resolved.
Removing that duplicate was correct -- two anonymous structs sharing a
name is a constraint violation -- and it had been load-bearing.
*A fix that makes a process reach code it never reached before can
expose anything on that path*, this time in a header.
**Removed, and MEASURED rather than hoped**: `ENABLE_NLS` is undef,
the only `<libintl.h>` includes in the compiled set are behind
`#if ENABLE_NLS`, and nothing compiled names any other of that
directory's 29 headers. **`-J` was never in frame** -- the error is a
parse of a type name, and the same file fails the same way under `-9`.
**`sys/lib/tests/ishadow-sweep.py` is the sweep for the class**: which
package `-I` directories hold a header that an APE header includes
with `<>`. **31 (mkfile, directory) pairs, 19 names** -- and it
**gates nothing**, because most are deliberate (Tcl ships `regex.h`
and `tcl.h`, libressl's `include/compat` exists to replace `<stdio.h>`
and friends, zlib owns `zconf.h`). *A sweep that failed on those would
cry wolf*, the rule `apehdr-sweep` already carries. Read a hit as a
question: does the package MEAN to replace that header, or merely
happen to own the name? gettext's `lock.h` was the second kind.
**Its own first version reported 0 of everything and looked healthy**,
because `sys/lib/tests` is THREE levels below the root and it said
two. *A sweep rooted in the wrong tree reports an empty one as a clean
one* -- it now refuses to run unless `sys/include/ape` is under its
root. Fifteenth instrument fault, caught in one run.
**And undoing the control edit with `git checkout <file>` reverted the
FIX in the same file.** *A revert is file-granular and an edit is
not*; the control has to be made and unmade in a copy, or re-applied
deliberately.

**AND THE NEXT STOP WAS `mk: mkfile:96: syntax error; expected one of
:<=` -- IN `cmd/mkfile`, WHICH DOCUMENTS THIS EXACT HAZARD IN ITS OWN
HEADER.** *"Every comment line INSIDE these lists has to end in a
backslash: the list is one continued line, and a comment without it
ends the assignment there."* The block added this round to explain why
`c++lib` and `basic` are off has **four comment lines without one**, so
`_OPTIONAL_APPS` ended at `cfront` and everything from `adeb` to `curl`
became a fresh logical line starting with a bare word. *A rule written
down in a file is not a rule the file obeys* -- and I wrote both.
**THE REPORTED LINE IS WHERE THE RUNAWAY LINE ENDS, NOT WHERE IT
STARTS.** Line 96 is an ordinary `DIRS=\`; the fault is 26 lines
earlier, in a comment. Same shape as the `lock.h` shadow one commit
before -- *the message names the victim* -- and it is why four
hypotheses about the bash mkfile were all wrong: **it was not bash's
mkfile at all**, and every construct in the comment I had suspected
(a lone `#`, `#`+TAB, `<pthread.h>`, an `#include` inside a comment)
has a working precedent elsewhere in the tree. *Checking whether the
suspect construct exists ANYWHERE that already works is one grep and
would have cleared it first.*
**The sweep found it where four readings did not**: every mkfile, every
comment that ends a continuation, reporting only those where the next
logical line is a bare word. `sys/lib/tests/mkcont-sweep.py`, and it
**gates** -- unlike `ishadow-sweep`, each hit is a real break.
**Its discriminator is the whole instrument**: a comment ending a
continuation is usually DELIBERATE (`lib/png/mkfile:42` is the tail of
an OFILES list commented out on purpose), so the naive check is almost
all false positives. 1 finding, 0 after the fix, and the control fires
when one backslash is removed again.
**Watch the first run after this**: ten packages (`adeb`, `dwarfdump`,
`hell`, `pcregrep`, `diff`, `patch`, `mkmk`, `samurai`, `openssl`,
`curl`) re-enter `_OPTIONAL_APPS`. Anything they report is *newly
measured*, not newly broken.

**AND THEN gmake WOULD NOT LINK -- `_convM2D: multiple initialization`
-- AND IT WAS NOT `-J`, IT WAS A REUSED VARIABLE IN `sualign()`.**
`o` is carried ACROSS iterations of the TSTRUCT loop: it holds the
offset of the current BIT-FIELD UNIT, set by the first field of a
group (`l->shift <= 0`) and read back by every later field. The
max-member-alignment loop added for `-J` wrote ITS result into `o`
too -- so **the second and later fields of every bit-field group were
placed at the previous member's ALIGNMENT instead of at the unit's
offset.** `ma` now, in both the TSTRUCT and TUNION arms.
**It was NOT gated on `conformalign`**: that line runs on every
compile, so plain builds were wrong as well, and it has been so since
`81a59a1d`. *A one-line addition to a loop that was already using its
variables for two things.* **No compiler can warn**: both uses are a
`long` holding a small number.
**GNU make's `struct command_switch` is what named it** -- `int c`,
`enum type`, `void *`, then `env:1 toenv:1 no_makefile:1
specified:1` -- so the three later bits moved to offset 4, on top of
`type`, and `6l` answered `multiple initialization` for every array
entry whose two writes to those four bytes were both non-zero. **The
value in the message is the evidence**: `$2` at `+4` with a 56-byte
stride is the bit-field word with `toenv` set, and `string` is also
2, so only entries with both are loud. *The struct's SIZE was 56
either way -- already a multiple of 8 -- so `-J` changed nothing
about it and a size-only check would have passed.*
**`structalign-test.c` SECTION 8 is the regression test**, and it had
to be a new shape rather than a line in section 4: **section 4's
`struct bits` could never have caught this**, because its bit fields
are the FIRST members, so the clobbered `o` was the alignment of
nothing and the offsets came out right anyway. *A bit-field group
needs a member in front of it before a wrong unit offset is visible.*
It also **cannot use `offsetof`** -- C forbids taking a bit field's
address and gcc says so -- so it asserts the COLLISION instead: set
each field of the group in turn and ask whether `type` survived,
which is the question the linker asked. 0 failures on gcc, numbers
measured from that run.
**`cd sys/src/cmd && mk install` BEFORE the tree rebuild**, and this
one matters for every package, not only the ones with `-J` in frame.

**AND `signal()` IS PROTOTYPED NOW -- `void (*signal(int, void
(*)(int)))(int)`, which is what C and POSIX say.** It had been the
UNPROTOTYPED `void (*)()` since the file was written, under a comment
explaining that libap dispatches `void handler(int, char *msg,
Ureg *u)` -- the Plan 9 note string and the trap frame -- and that a
prototype would put the extension out of reach.
**The extension is unchanged and still dispatched**; what went is a
public declaration that turned off argument checking for EVERY caller
in the tree to keep it reachable. *This tree's own invariant is that
a call with no prototype in scope corrupts its arguments under kencc,
and the thing left unchecked here is a FUNCTION POINTER a program
installs and the library later calls.*
**And the header was not even true of libap**: `signal/signal.c`
defined `signal()` with the three-argument type, so the declaration
and the definition have always disagreed and only the empty parameter
list made it legal.
**Nothing in the tree uses it -- swept rather than assumed.** 56
distinct handler names reach `signal()`; exactly two take more than
one argument, and neither is this extension (`diffutils`' own
`signal_handler(int, sighandler)` wrapper, whose `sighandler` is
already `void(*)(int)`, and a `muon` TEST using `SA_SIGINFO`). The
only files outside libap that mention `Ureg` are go1.4's runtime,
which is not built here.
**`SIG_DFL`/`SIG_ERR`/`SIG_IGN` and `sa_handler` MOVE WITH IT** and
could not be left behind: callers compare the return value against
the macros and assign them to `sa_handler`, so a mismatched pair is a
diagnostic in every file that mentions them. `_sighdlr[]` holds the
POSIX type now and **the cast lives at the ONE place that calls a
handler**, `_notetramp` -- not at each assignment, or `_envsetup.c`
and `sigwait.c` would each need one and a cast would stop meaning
"something unusual here". The eleven arch `notetramp.c` are
untouched. `sigaction.c` loses four casts that existed only because
nothing had a type to agree with.
**Measured, with a baseline**: `signal.c`, `sigaction.c`, `sigwait.c`
and `_envsetup.c` syntax-checked on the host against staged headers
in the classes 6c treats as fatal -- **1 error before, 1 after, the
same one** -- and `apehdr-sweep` is 149 headers, 0 findings, with the
together-case holding at its recorded 12.
**That surviving error is a REAL pre-existing find, recorded NOT
fixed**: `lib.h` declares `_notehandler(void *, char *)` and
`signal.c` defines it `(Ureg *, char *)`. *Both sides are right* --
the declaration matches `_NOTIFY`, which is Plan 9's own `void *`,
and the definition matches what the body does -- so narrowing the
declaration only moves the mismatch to the `_NOTIFY` call, which is
exactly what happened when I tried it. Whichever side changes, one
needs a cast. The all-HEAD control is what separates it from this
round: HEAD's `signal.c` gives this one error against HEAD's own
headers.
*(The code for this landed in `6c51444e` by a careless `git add -A`,
whose message describes only the `sualign` fix. Recorded here rather
than rewritten, since that commit was already pushed.)*

**AND THE cfront SIZE PROBE WAS `.gitignore'd, SO THE VM NEVER GOT
IT.** `pcc ... cfrontsz-probe.c` answered `Can't open input file` and
`ls cfront*.c` showed only the two stub files. **git is the only
channel to that machine** -- 9front has no python3 -- so an ignored
generated file is a file the VM cannot see. Both generated files are
committed now. *It is not the shape of the forty zero-byte `c++lib`
files*: those were an INPUT to `mk`, which therefore never regenerated
them, while these two appear in nobody's OFILES and mk never compiles
them. The rule is about what reads the file, not about how it was
made.

**SO `apehdr-sweep.py` GAINED A "TOGETHER" CASE, because compiling
each header ALONE cannot see this class at all** -- each file is fine
by itself and only the COMBINATION conflicts. A pairwise sweep is
149x148/2 compiles; including everything in ONE translation unit is
one, and catches the same class. **Its first run reports 12 errors**,
and they are NOT yet triaged, so it prints them and does **not** gate
the exit status: *failing on an untriaged list makes a sweep cry
wolf, and suppressing the list wastes it.* Some are real
(`uname`/`getrusage` was) and some are design intent -- `<regex.h>`
and `<pcre2posix.h>` both define `regex_t` because they are
ALTERNATIVES and no program includes both.
**TRIAGED NOW, AND TWELVE ERRORS ARE SIX CAUSES** -- which is the
whole reason to triage rather than count, and why the raw list sat
unread for rounds. Only TWO of the six are bugs in this tree:
- **`f2c.h` is FIVE of the twelve, on its own.** `#define min/max/abs`
  collide with `<libv.h>`'s `extern int min(int,int)`, and
  `typedef struct {real r,i;} complex` collides with `<complex.h>`'s
  `#define complex _Complex`. *A transpiler's private runtime header,
  installed PUBLIC, owning four names two C standard headers own.*
  **149 files include it and every one is under `external/f2c`** --
  so it does not belong in `sys/include/ape`. Recommendation, not
  done.
- **`regex.h`/`pcre2posix.h` is THREE, and DESIGN INTENT.** pcre2posix
  spells the `REG_*` codes as an ENUM where `regex.h` `#define`s them,
  so `regex.h:44` turns pcre2posix's enumerator into a numeric
  constant -- the `regex_t`/`regmatch_t` pair is the same collision
  seen twice more. *The "numeric constant" error and the two
  conflicting-struct errors were never three findings.*
- **`Plan9libnet.h` is TWO, and the tree ALREADY FIXED IT ONCE.** It
  declares Plan 9's `accept(int, char*)` and `listen(char*, char*)` --
  different functions wearing POSIX's names -- against
  `<sys/socket.h>`. **`libnet.h` beside it is the same interface with
  `net_` prefixes, and is what all five callers in the tree use;
  NOTHING includes `Plan9libnet.h` at all.** *The library holding a
  working version of the thing it got wrong, for the sixth time, and
  the first time it is a HEADER.* Recommendation: delete it -- a
  header that cannot be combined with `<sys/socket.h>` and that
  nothing includes is only a trap. Not done unasked.
- **`bsd.h:47` is ONE, REAL and OURS**: `getopt(int, char**, char*)`
  where POSIX says `(int, char *const *, const char *)` -- and
  **`<unistd.h>` does not declare `getopt` at all**, so this is the
  tree's only declaration and it is the wrong one. Found
  independently by EDG, which is a stricter compiler than gcc.
- **`features.h:55` is ONE, REAL, OURS, AND IT HAS A VICTIM.**
  `#define hidden` is musl's internal visibility macro **in a public
  header**, reached from `<byteswap.h>`, `<endian.h>`, `<ftw.h>`,
  `<glob.h>`, `<iconv.h>` and more -- and `sqlite3.h:10957` declares
  `unsigned char hidden[48];`, **erased wherever `features.h` came
  first.** *A silent struct-layout change in a public API*, which is
  the `-J` hazard arriving from the preprocessor instead of the
  compiler. `weak_alias` beside it is the same shape with no victim
  found yet.
  **The fix needs care and the care is measurable**: libap's own
  `multibyte/internal.c:25` already carries `#ifndef hidden / #define
  hidden`, so private users can supply their own -- but
  `network/lookup.h:46` relies on the leak, which is the
  `<stdio.h>`-leaked-errno shape. Sweep libap before removing it.
*The sweep PRINTS the triage now rather than the raw lines, and still
does not gate -- three of the six are intent.*

**THE TRIAGE IS WORKED NOW: 12 ERRORS -> 8, AND THE EIGHT THAT REMAIN
ARE THE TWO INTENT CASES.** Each drop was measured by re-running the
sweep rather than argued, and each named its own error.
- **`f2c.h`: RECOMMENDATION WITHDRAWN, and the withdrawal is the
  finding.** The installed copy is byte-identical to the build's own
  `external/f2c/lib/f2c.h` **except for two added lines** --
  `#pragma lib "/$M/lib/ape/libf2c.a"` and a blank. *That is the whole
  reason it exists*: a user compiling `f2c`'s output gets libf2c
  linked, which is the APE convention working as designed. The 149
  includers sit beside their own copy and never see this one, so
  *where the includers live was the wrong question* -- diffing the
  INSTALLED copy against the one next door settles it in one command.
  Its five errors join `regex.h`/`pcre2posix.h` as design intent.
- **`Plan9libnet.h`: DELETED, for a better reason than the one
  recorded.** Nothing includes it, and **it shares the include guard
  `__LIBNET_H` with `libnet.h`**, so the two could never be combined
  anyway. What decides it is that two of its three distinctive
  declarations name functions that DO NOT EXIST: there is no Plan 9
  `accept(int, char*)` or `listen(char*, char*)` in libap, only
  POSIX's.
- **AND `libnet.h` -- the one `<sys/socket.h>` ITSELF INCLUDES -- was
  wrong in both directions.** `net_accept`, `net_listen` and
  `net_reject` were declared here and **defined nowhere and called
  nowhere** (grep: zero hits outside the header), so every program
  including `<sys/socket.h>` carried three promises libap cannot keep
  -- failing at the LINK rather than at the call, which is the later
  and worse of the two places. Removed. *The note said `libnet.h` was
  "the same interface that all five callers use" -- they include it
  and call `announce`/`dial`/`hangup`/`netmkaddr`, never the three
  `net_` names.*
  **AND THE OTHER HALF -- DECLARING `reject` -- BROKE THE BUILD AND
  IS REVERTED.** `plan9/announce.c:139` defines
  `reject(int, char*, char*)` and no header named it, so it looked
  like the "capability present and not declared" shape. flex said
  otherwise on the first compile after it:

  ```
    flexdef.h:366 external redeclaration of: reject
        EXTERN INT reject
        EXTERN FUNC(INT, IND CHAR, IND CHAR) INT   libnet.h:36
  ```

  **flex has `extern int reject;` -- a VARIABLE.** And because this
  header is reached from `<sys/socket.h>`, anything it declares is
  surface for every networked program in the tree: **210 files under
  `external/` use the name**, gnulib spelling two PARAMETERS with it
  (`mbsspn(const char*, const char *reject)`, `u8_strcspn`).
  ***MY SWEEP LOOKED FOR `reject(` AND SO COULD NOT MATCH A
  VARIABLE*** -- which is the mistake this file ALREADY RECORDS, from
  the bacon link round: *"four VARIABLES my function-shaped grep
  could not match (`optind`, `opterr`, `optarg`, `stdin`)"*. Same
  error, two sections apart, in the same session. **Sweep for the
  NAME, not for the shape you expect it to have.**
  **The control fires and is a real one**: a translation unit holding
  `#include <sys/socket.h>` and `extern int reject;` gives 0 errors
  against the fixed header and `redeclared as different kind of
  symbol` with the declaration put back -- gcc's wording for exactly
  what 6c printed.
  **And `apehdr-sweep` could not have caught this, which is a limit
  worth stating**: it compiles APE headers against *each other*, and
  `flexdef.h` is a package's own header. *A public header's real
  blast radius is every package in the tree, and no instrument here
  measures that* -- the cheap guard is to grep `external/` for the
  bare word before adding any name to `sys/include/ape`.
  **CONFIRMED ON THE VM: the revert builds.** `mk distclean` plus
  `mk install` completes, so the tree gets past `lex` and the whole
  order after it was reached for the first time since the header
  changed. *That is the weakest useful result and is worth saying so*
  -- it confirms the collision is gone, and the `net_*` removal
  beside it costs no link, which is all a completed build can say.
- **`getopt`: TWO INSTALLED HEADERS DECLARED IT INCOMPATIBLY, and my
  note said there was only one.** `bsd.h:47` had
  `(int, char**, char*)` while **`getopt.h:8` has had POSIX's
  `(int, char * const [], const char *)` all along**. `bsd.h` and the
  definition in `misc/getopt.c` now match `getopt.h`. Callers are
  unaffected: `char **` converts to `char * const *` because the const
  is at the FIRST level of the pointed-to type (C11 6.5.16.1), which
  is why every program everywhere passes `main`'s `argv` to glibc's
  identically-declared getopt.
- **`features.h`: `hidden` AND `weak_alias` ARE OUT OF THE PUBLIC
  HEADER.** `hidden` had the measured victim -- it expands to nothing
  and `sqlite3.h:10957` declares `unsigned char hidden[48];`, erased
  wherever features.h came first. `weak_alias` had no victim and went
  for a different reason, recorded in its own former comment: gnulib's
  `libc-config.h` defines it with no guard, so the two had to agree
  token for token -- `cpp/macro.c`'s `comparetokens()` compares
  PARAMETER NAMES as well as bodies -- and this file's parameter names
  were chosen to match an external package's. *A public macro that is
  only safe because it was spelled like someone else's is safe by
  coincidence.*
  **Sixteen private files gain the `#ifndef hidden` guard and five
  under `network/` the `weak_alias` one**, which is the idiom
  `include/libm.h` and `multibyte/internal.c` ALREADY used -- copy the
  library's own idiom rather than invent a placement. **Nothing
  outside libap needed either**: every external package using
  `weak_alias` ships its own `libc-config.h`, and bash's `lib/intl`
  (the one exception) is not compiled -- `ENABLE_NLS` is undef and the
  `-I` was removed earlier this session.
**The controls**: `apehdr-sweep` 149 -> 148 headers with **0
standalone findings** throughout, together-case **12 -> 10 -> 9 -> 8**
across the three fixes; `apdecl-sweep` 0. And the twelve touched libap
sources give **3 host errors before and the same 3 after** -- a
pre-existing `FILE *const stdin` qualifier mismatch, unrelated. *The
before-and-after pair is what makes that a control rather than a
syntax check.*
**`sys/include/ape/stdio_impl.h` is the SAME SHAPE and is NOT
touched**: musl's internal stdio header, installed public, reached by
six `stdio/*.c`. No victim has been found for it, so it is recorded
rather than moved.

**AND THE SHARED TRANSPILER RULES CARRIED THE `> $target` BUG THAT
`cmd/c++lib` HAD ALREADY PAID FOR.** `sys/src/cmd/transpilers` is
included by `mkone`/`mkmany`/`mklib` for **every** APE package, and
three of its six rules were wrong.
**NOTHING IN THE TREE TRIGGERS IT, which is why.** There is no `.m`,
`.cpp`, `.p` or `.f` outside `external/`, and everything inside is
built by its own package mkfile -- so these were **traps for the next
person** rather than live bugs. *An untriggered rule gets no
diagnostic from anyone*, and the first `.m` added to a package would
have inherited all three faults at once.
- **The C++ rules were `cfront $stem.cpp > $stem.c`, both halves of
  the c++lib bug.** The redirection creates the target whatever the
  command does; and **cfront is one stage of three** -- handed a
  `.cpp` directly it sees unpreprocessed source. `rc/bin/ape/c++` is
  the driver, takes `.cpp/.cxx/.cc/.C` alike, and `-F` is its
  translate-only mode. `c++ -F -o $target` now.
- **`%.c: %.m` was wrong TWICE, and the driver script says so rather
  than any guess.** `rc/bin/ape/objc` defaults to `link=y` and
  `output="a.out"`, so plain `objc foo.m` compiles **and links**; and
  the `foo.c` it writes on the way is the `.m` with a `#line` on the
  front, listed in its own `junk` and **deleted** -- the translated C
  is `foo.i`. *The rule named a target the command removes.*
  Objective C has no honest `%.c:` rule; it stops at the object.
- **`%.c: %.p` could not run at all.** p2c has no built-in output
  name: `codefnfmt` comes from the `p2crc` file and `trans.c:717`
  exits `Unable to find required system p2crc file` without one.
  `-H $PCHOME` finds `/sys/lib/pascal/p2crc`, whose
  `CodeFileName %Rs.c` is what makes `foo.p` answer `foo.c`.
- `CXXFLAGS` and `FFLAGS` were declared and used by nothing. f2c and
  bacon were already right and are unchanged.
**AND `rc/bin/ape/p2cc` HELD A LIVE BUG FOUND ON THE WAY: it passed
`-H --HOMEDIR--`.** Upstream substitutes that token when it INSTALLS
the script (`src/Makefile:113` is a `sed`); APExp installs it by hand,
and `$homedir`, `$incdir` and `$libdir` were filled in while this one
was not. **The guard is what made it reachable rather than
harmless**: it fires precisely when `$homedir/p2crc` EXISTS, so *the
better configured the tree, the more certainly p2cc added the broken
flag*. `perl -c` passes.

**EDG'S FRONT END IS OPEN SOURCE NOW, AND IT IS THE RIGHT SHAPE OF
TOOL -- investigated, not started.** `github.com/edgcpp/compiler`,
**Apache 2.0 with LLVM exceptions**, so the licence is no obstacle.
The three facts that decide feasibility were measured rather than
assumed, by reading the repository:
- **The `.c` files ARE C++14**, which is the confusing part:
  `BUILD.md` says `g++ -std=c++14 *.c`, and EDG keeps the `.c`
  extension from the decades when the front end really was C. Hosts:
  g++ 5.2, clang 3.4, MSVC 2017.
- **`src/c_gen_be.c` is in the tree** -- the C-generating back end,
  which is the whole reason this is interesting: it emits C SOURCE,
  so kencc decides the layout and the ABI rather than inheriting
  someone else's. *That is exactly the problem EDG's C back end was
  built for -- a target with only a C compiler -- which is APExp.*
- **IT DOES NOT USE THE C++ STANDARD LIBRARY**, and that is the one
  that matters. `basic_hdrs.h` includes only EDG's own headers;
  `host_envir.h`'s only system include is `<locale.h>`. *The thing
  that kills every source-to-source C++ bootstrap is the standard
  library*, because libstdc++ is GCC-specific and libc++ needs C++
  to build -- and EDG sidesteps it by never having used one.
**So the bootstrap has a shape**: build EDG on the host with g++,
run EDG's own `c_gen_be` over EDG's own 150 sources, carry the C to
the VM, build it with pcc. **Two risks worth naming before anyone
starts.** (1) `targ_def.h` has to describe kencc: `int` 4, `long`
**4**, pointer **8** -- and that unusual combination is exactly
LLP64, which EDG must already support because it supports MSVC. (2)
whether EDG's C back end handles the C++ subset EDG itself is
written in, which is the classic self-translation question and is
one host afternoon to answer, with no VM.
**AND `llvm-cbe` IS THE WORSE VERSION OF THE SAME IDEA.** LLVM's own
C backend was **removed in 3.1**; the maintained revival is
out-of-tree and converts **LLVM IR**, not C++ source -- so every C++
semantic has already been lowered against one target's data layout
and calling convention, and you would be recompiling x86-64 SysV
decisions with a compiler whose struct layout this tree has just
spent a round on. It also does not remove the runtime question for
ordinary C++ programs. *EDG's back end works at the SOURCE level,
which is the property that makes the layout kencc's to decide.*
**IT BUILDS AND IT TRANSLATES -- MEASURED ON THE HOST, NOT ARGUED.**
`cmake --preset linux-gcc-release` then `ninja` produces **`cpfe`**
(23 MB), and `cmake/macro-conf/default/cpfe.cmakedef` is literally
`BACK_END_IS_C_GEN_BE=1` / `DO_IL_LOWERING=1` -- **the DEFAULT build
is the C-generating one**, which is better than the README promised.
*(I first read `defines.h`, found `BACK_END_IS_C_GEN_BE` set to 1
nowhere, and reported that the release ships the back end with no
configuration. Wrong: the switch arrives as a cmake `-D`, and the
compile line says `-DBACK_END_IS_C_GEN_BE=1`. **Read the command the
build runs, not the header it might have come from** -- the
`config.h`-that-is-shadowed lesson in a new place.)*
**`eccp -S --g++ --sys_include=...` IS THE TRANSLATOR**: a toy with a
virtual base, an override, a template and `new`/`delete` came out as
86 lines of ordinary C -- templates instantiated, inheritance
flattened to `struct Derived { struct Base __b_4Base; }`, dispatch
through a `__vptr`, Itanium-mangled names -- and **`gcc -c` compiled
it with no errors**. Linking needs EDG's OWN runtime (`lib_src/`:
`new`, `delete`, `vtbl`, `static_init`, `pure_virt`, `rtti`), not
libstdc++, which is the whole reason this is tractable.
**Two obstacles named from the output rather than guessed**: the
generated C carries `__attribute__((__weak__))` and
`((__nothrow__))`, which kencc has not and which will need defining
away or an EDG option; and the host's own runtime build stopped on
`-Wno-error=return-mismatch`, a **gcc 14** flag this box's gcc 13
lacks -- *the driver's flag list, not the translation*.
**EDG is compiled `-fno-exceptions -fno-rtti`**, so the front end
itself needs no unwinder -- the self-translation's runtime surface is
smaller than the general case.

**NOT a reason to stop cfront**, and the reason is this tree's own:
cfront is close (the driver works, mk stops at the fault, five files
convert cleanly) and **its crash is currently flushing out kencc and
libap bugs, which is where every large find here has come from**.
EDG would run on the same libap and want the same bugs fixed.

**THAT REASON HAS NOW EXPIRED, AND SAYING SO IS THE POINT.** The
crash was the last kencc bug cfront had to give, and **the HOST
settles that it is the last**: cfront built with gcc, where `long` is
64-bit and the layout is conforming by construction, produces the
diagnostics that remain **character for character** -- the four
`iostream.h:224/228/266/269` redeclarations, `two definitions of
norm()`, `operator delete()'s 2nd argument must be a size_t`,
`placenew.cpp two definitions of operator new()`. *A fault both
compilers reproduce is upstream's, not this tree's.* So cfront has
stopped being a bug-finder for APExp, and the thing to stop is
**spending rounds on it**, not the directory.
**KEEP IT, OFF, for three reasons that are not sentiment.** (1) The
`-9`/`-J` pair is now the only END-TO-END regression instrument for
the layout rule this tree has: `structalign-test` measures sizes and
offsets, while this measures a *program that behaves differently* --
same input, one flag, `pc=0x280db8` or no fault. Nothing else
reproduces that. (2) `cfrontsz-probe.py` reads cfront's generated C
for its 97 recorded struct sizes, and that oracle is the generated
files. (3) The EDG path, if it is ever taken, wants the same `c++`
driver, the same `ns_strip`, the same `<values.h>` and the c++lib
mkfile; deleting now and rewriting later is strictly worse than
leaving a directory nothing builds. **`c++lib` is already commented
out of `_OPTIONAL_APPS` and stays out; `cfront` itself stays in**,
because building the translator is cheap and is what keeps the
instrument alive.
**The ONE experiment left, and it is bounded**: remove the seven
`< 0x200000` guards and run `cmd/c++lib` by hand under each rule.
Identical output under `-J` plus a worse crash under `-9` is a
second, independent confirmation of the layout fix and removes seven
lines that would MASK a recurrence of exactly the bug `-J` repaired.
*If that comes back clean, cfront is finished as a question for this
tree* -- what remains is a 1980s front end that cannot tell two
overloads apart on a 64-bit target, which is a C++ problem and not a
Plan 9 one.

**NEITHER IS ENABLED IN `cmd/mkfile' YET, deliberately**: one failing
entry aborts the whole tree's `mk', and bacon has never been through
pcc. Build `cmd/basic' by hand first; the line is one character from
live either way.

## What is open, as a list

**Ports not started**, in the order their risk was last measured:
- **EDG** -- **BOTH NAMED RISKS ARE CLOSED AND THE SELF-TRANSLATION IS
  IN THE TREE.** `sys/src/external/edg` holds **133 generated C files,
  ~2.90M lines**: all 75 `src/`, 7 `util/` and 51 `lib_src/`, produced
  by a `cpfe` built from the same commit with a kencc target, plus
  EDG's own 17 C++ headers verbatim. `gcc -fsyntax-only` over all 133
  is **0 errors, 0 warnings** -- which is the host's answer and says
  nothing about kencc. Full detail in `sys/src/external/edg/NOTE`;
  only the consequences are here.
  - **Risk 1, the target description: answered by EDG's own `win64`.**
    kencc on amd64 is LLP64 and win64 is EDG's LLP64 configuration, so
    the values were taken from the build's generated
    `cmake_defines.h` rather than invented. Every scalar width
    matches, **including `long double` 8** -- win64 says 8 because
    MSVC has no extended precision and kencc says 8 because
    `cc/sub.c`'s `simplet()` maps `BDOUBLE|BLONG` to `types[TDOUBLE]`,
    which was not predicted. `size_t`/`ssize_t`/`ptrdiff_t` are
    win64's kinds too, read out of `stddef_arch.h`; **`wchar_t` is the
    one place the two differ** (`unsigned int` here, `unsigned short`
    there). `kencc_targ.h`, committed beside the NOTE, is the whole
    configuration -- a **pre-included header**, so nothing in the EDG
    tree is modified.
  - **Risk 2, self-translation: it translates.** One file does not and
    it is the right one -- `util/cfe_daemon_client.c`, the only file
    in the tree needing a real C++ standard library, and a
    unix-domain-socket client is out of scope here twice over.
  - **The target was inferred from the compiler that BUILT cpfe, which
    is the finding of the round.** `targ_def.h:3505` derives
    `GCC_IS_GENERATED_CODE_TARGET` from `defined(__GNUC__)`, and that
    one variable is the sole gate on both `__weak__` emission sites --
    so cpfe built by g++ decided its OUTPUT was for gcc and emitted
    **26,712 `__attribute__((__weak__))`**, which kencc has not. A
    first round also baked in LP64 and glibc's headers. Setting it to
    0 and staging APExp's own headers takes the applied-attribute
    count **38,245 -> 0**; the 11 textual occurrences left are all
    inside string literals, EDG's own emitter text.
  - **THE LINK MODEL IS THE OPEN PROBLEM, and removing `__weak__`
    exposed it rather than solving it.** Those attributes were COMDAT
    emulation for vague linkage. Measured: two trivial TUs sharing one
    header collide on **10 symbols**, and across `src/` there are
    **3,094 COMDAT symbols named in more than one of the 75 files**.
    `--one_instantiation_per_object` is deliberately NOT used -- it
    covers only the template instantiations (3 of the 10) and makes
    the output depend on an `edg_prelink` phase mk cannot naturally
    express. Upstream's answer for a target without COMDAT is the
    **Cfront-like ABI**, and that was attempted and **backed out**:
    `IA64_ABI=0` makes cpfe fail to *compile* on three
    `TARGET_CONFIGURATION`-suffixed macros the Cfront ABI needs, so it
    is reachable by regenerating the macro configuration rather than
    by setting switches, and it changes mangling, the ctor/dtor model
    and vtable layout. Its own round.
  - **THE MKFILES ARE WRITTEN AND NOTHING HAS BEEN THROUGH pcc YET.**
    **It is THREE products, not one**, which `main` settles rather than
    taste: `src`'s 75 files hold exactly one (`cfe.c`) so they are one
    binary, `cpfe`; `util`'s seven hold six, plus `decode.c` with none
    (it is `edg_decode`'s second object); `lib_src`'s 51 hold none, so
    they are a LIBRARY. Hence `sys/src/ape/lib/edg` -> `libedg.a`
    (`mksyslib`) and `sys/src/ape/cmd/edg` -> `cpfe` (`mkone`); `util`
    is six small binaries and blocks nothing.
    **DELIBERATELY NOT IN `cmd/mkfile`'s lists** -- one failing entry
    aborts the whole tree's `mk`, as `basic` and `c++lib` already
    record. By hand first.
    **ORDER IS A DEPENDENCY RATHER THAN A PREFERENCE.** lib/edg first,
    because an archive sidesteps the link model entirely -- `ar` takes
    duplicate members and the clash only arrives at a LINK -- so it
    answers "does pcc compile EDG's generated C" with nothing else in
    frame. Then cmd/edg, where both remaining questions land.
    **AND `mk -k`, NOT `mk`**: Plan 9 mk stops at the first failing
    recipe, so a plain run costs one round per bad file across 75;
    -k names them all at once. *That is the rule bacon's missing
    headers and bacon's missing link symbols both paid for.*
    **AND THE FIRST pcc RUN STOPPED ON THE FOURTH FILE, FOR A KENCC
    GRAMMAR BUG RATHER THAN ANYTHING OF EDG'S: `auto size_t x;` DID
    NOT PARSE.** `autoadlist` began with `xdecor`, which reaches
    `LNAME | LTYPE`, so after `LAUTO` the parser could SHIFT a typedef
    name as the variable being declared -- and **yacc resolves
    shift/reduce in favour of SHIFT**, so the C23 deduction path won
    over `cname: LAUTO`, the storage class. EDG's C writes
    `auto <type> <name>;` for every local: **116,079 of them across
    103 of the 133 files**, so one conflict blocked essentially the
    whole port.
    **`-std=` WOULD NOT HAVE FIXED IT, and that is the finding rather
    than the fix.** The conflict is resolved when yacc BUILDS THE
    TABLE, so no runtime flag has a say -- and there is no dialect
    disagreement to arbitrate, since C23 kept `auto` as a
    storage-class specifier and its type inference applies only where
    `auto` is the SOLE type specifier. *Both standards want the same
    answer here*, and the grammar can reach it alone because `size_t`
    is LTYPE and `x` is LNAME. A new `autoxdecor` roots the first
    declarator at LNAME; `*` still shifts, because `auto *p = &x;` is
    deduction while `auto *p;` would need implicit int.
    **Measured with bison** (kencc's own sources need Plan 9's `<u.h>`
    and `<libc.h>`, so the first build is the VM's -- the weaker
    position `-J` also shipped from): shift/reduce **26 -> 22**,
    reduce/reduce 6 both ways, and the two states that carry it --
    `adecl` 417 and `forexpr` 517 -- each lose their LTYPE and `(`
    shifts, 4 -> 2. *The same production appears in two places, which
    is why a 26 -> 24 prediction was two short.*
    **AND THE WHOLE CORPUS WAS THEN SWEPT AT ONCE, which named three
    bad files and two missing symbols before the VM reached either.**
    *The stripping is the measurement*: with comments, string and
    character literals and `#line` removed first, every C11/C23
    construct kencc lacks counts **zero** -- where a raw grep reports
    `alignof` 2343, `static_assert` 1156, `_Complex` 702 and `typeof`
    425, all of them the word inside EDG's own mangled names and
    diagnostic text. The exceptions were **`lib_src/c99_complex.c`**
    (`_Float16`, `__bf16`, `__float80`, `__float128`) and
    **`thread_dtor.c`/`dtor_list.c`** (`__thread`) -- a feature of the
    HOST compiler rather than of EDG, *which is exactly why `gcc
    -fsyntax-only` reports 0 errors over them*.
    **`mk -k install` ANSWERED: 50 OF 51 COMPILE, AND ONLY
    `c99_complex.c` FAILS** -- predicted by name and by token
    (`syntax error, last name: _Float16`). Commented out of OFILES
    now the measurement is taken; a C++ front end has no use for a
    `_Complex` runtime, and the extended floats drag libgcc's
    soft-float family in behind them.
    **AND THE TWO `__thread` PREDICTIONS WERE WRONG, WHICH IS THE MORE
    USEFUL HALF.** I checked EDG's constructs against C dialects FROM
    MEMORY rather than against the compiler in this repository, where
    `cc/lex.c:1765` has carried `"__thread", LNAME, 0` and a swallow
    at `:1095` all along -- *"Plan 9 has no TLS; silently drop the
    qualifier."* **An instrument whose keyword list is not the
    COMPILER's keyword list is measuring a different compiler**: the
    include-path lesson `apdecl-sweep` and `apehdr-sweep` each paid
    for, one level down, for a lexer. The list to check against is
    `itab` plus that swallow list and both are in the tree -- and
    asking it about the four float types afterwards is what says
    `c99_complex.c` really is the only one.
    **That pass is not a clean bill, either**: `__thread` dropped makes
    `__thread_needed_destruction_head` one process-wide global shared
    by every thread, which is the stub-answering-the-wrong-thing shape.
    Harmless for single-threaded cpfe, a live hazard for anything cpfe
    translates. Recorded, not fixed.
    **And the limits were asked rather than assumed**: longest line
    430 bytes against cpp's `INS` 32768, longest identifier 295
    against `cc`'s `NSYMB` 1500, 7204 `case` in one file where `6c`'s
    `Case` is a linked list, and **`6c`'s `NSYM 50` is a CACHE, not a
    cap** -- `swt.c:229` wraps the slot to 1 and re-emits the ANAME.
    **The libap half of the link is answered and it is TWO NAMES.**
    All 133 compiled with gcc, then nm's defined set subtracted from
    its undefined set: 679 external, 121 of them plain C names, and
    libap defines every one but `_setjmp` and `__cxa_finalize`.
    `_setjmp` is a **missed line in `kencc_targ.h`** rather than a
    libap gap -- EDG's `TARG_SETJMP_FUNC` defaults to `"_setjmp"` and
    **win64, the same configuration every other value came from, says
    `"setjmp"`** -- and adding the name to a public APE header would
    be `reject` again, since `lua/ldo.c:80` uses it under
    `LUA_USE_POSIX`. `__cxa_finalize` is EDG's own runtime's, not
    libap's. *The first version of that sweep reported two dozen
    absent, because its regex required a character before the name and
    a definition starting in column 0 has none -- the function-shaped
    grep in a new spelling.*
    **ALL 75 COMPILE -- `sys_predef.c''s 315,616 lines included -- AND
    THE LINK IS WHERE IT STOPPED.** That was the question with no
    precedent and it is answered.
    **AND MY LINK PREDICTION WAS WRONG, ABOUT ORDERING.** I predicted
    `6l` would report undefined template instantiations; it reports
    **`redefinition:`** until `too many errors`. `6l` catches
    duplicates as it LOADS each object and only reports undefined
    symbols at the end, so it never reached the pass the prediction was
    about. *What it named was a symbol-for-symbol confirmation of the
    host sweep*: `edg::max_val<unsigned long long>` and
    `edg::skip_typerefs`, the two measured at **41 copies each**, and
    `Ptr_map<...>::get_with_hash` at 39.
    **AND THE FIX WAS ALREADY IN THE LINKER WITH NO WAY TO ASK FOR IT
    -- `-C`, COMDAT.** `6l/obj.c:996` is
    `if(p->from.scale & DUPOK){ skip = 1; goto casdef; }` on a
    duplicate ATEXT, and `6l/asm.c:548` uses `sym->dupok` to suppress
    `multiple initialization` for duplicate DATA; `DUPOK` is `(1<<1)`
    in eight `*.out.h`. **The one missing piece was a way for C to set
    the bit**: `gpseudo()` wrote `p->from.scale = (profileflg ? 0 :
    NOPROF)` and nothing ever OR'd into it. *The sixth time this tree
    has found a working implementation of the thing it could not do
    sitting next to the thing that could not do it.*
    **It is blunt and the mkfile says so**: it marks EVERY TEXT and
    GLOBL in the translation unit, not the vague-linkage ones, so two
    genuinely different functions of one name become first-wins
    instead of a diagnostic. Safe for generated C, where every
    duplicate is the same entity by construction, and nothing else in
    the tree passes it. The precise version is `cc` learning
    `__attribute__((__weak__))` -- which EDG already emits, 26,712 of
    them, when its target is gcc -- and that needs a re-translation.
    **x86 AND RISC USE DIFFERENT FIELDS, which one patch would have
    got wrong.** `6c`/`8c` carry TEXT flags in `p->from.scale`;
    `5c`/`7c`/`kc`/`qc`/`vc` carry them in `p->reg`, assigned only for
    ATEXT, so AGLOBL had to be named too. *And `zprog.reg` is `NREG`,
    not 0* -- so every RISC AGLOBL already reaches its linker carrying
    NREG in the flags field, and whether that was accidentally dupok
    was **checked rather than assumed** (16 and 32 against `1<<1`:
    clear).
    **FOUR TARGETS CANNOT HONOUR IT AND NOW SAY SO.** `9l` **declares
    `dupok` in `l.h` and never reads it** -- zero hits in its `.c`
    where every other linker has two -- a pre-existing gap found by
    this change and recorded, not fixed; `1l`/`2l` have no such field
    at all. On those the backend diagnoses once instead of setting a
    bit the linker ignores, *because a flag that silently does nothing
    produces a link failure that looks like a different bug* -- which
    is `pcc`'s missing ARGBEGIN `default:` for the third time.
    **NOT COMPILED ANYWHERE: kencc needs Plan 9's `<u.h>`/`<libc.h>`,
    so the first build is the VM's** -- the same weaker position `-J`
    shipped from.
    **`-C` WORKS AND THE LINK MODEL'S TWO HALVES ARE NOW BOTH
    MEASURED AT THE LINK.** With `-C` every `redefinition:` is gone,
    and what is underneath is `undefined:` on `_ZN3edg...I...E` names
    -- **template instantiations, every one**, with no vtable, no
    typeinfo, no guard variable and no plain C function among them.
    *That is the prediction written down before the run.*
    **And `LIB=` had to go BEFORE the `<mkone` include**, which is
    load-bearing rather than stylistic: `mkone`'s rule is
    `$O.out: $OFILES $LIB` and mk binds a rule's prerequisites when it
    READS the rule, so an assignment after the include expands to
    nothing. It fails in the quietest way available -- the link runs,
    looks right, and reports the archive's symbols as undefined. The
    link line now ends `.../amd64/lib/ape/libedg.a` and `_ZnwyPv` has
    left the undefined list, which is the confirmation; every other
    `cmd` mkfile here (tclsh, wish, itclsh) already did it this way.
    **AND THE LINK MODEL IS TWO HALVES, WHICH READING THEM AS ONE GOT
    WRONG.** 556 of the 558 `_Z` names are **template instantiations
    emitted NOWHERE**, with **zero** vtables, typeinfo, guard
    variables or thunks among them -- so the output is not
    self-contained for templates *independently of
    `--one_instantiation_per_object`*, and the default already needs a
    prelink step for the very entities OIPO was being weighed for. The
    duplicate half is separate and is now measured from OBJECTS rather
    than annotations: **3124 symbols defined in more than one object,
    6410 surplus definitions**, against the 3094 counted from COMDAT
    annotations -- *two routes to the same number, which is better
    evidence than either alone*.
    **`src/sys_predef.c` IS 315,616 LINES IN ONE TRANSLATION UNIT**
    (`ifc_modules_read.c` 130,330, `expr.c` 120,824; 2.9M lines over
    the 133). A `6c` table limit is the likeliest first answer, and it
    would be kencc's rather than the port's -- worth knowing before
    anything is blamed on EDG.
    **`cpfe` HAS NO `LIB=`, AND THAT IS A QUESTION, NOT A CLAIM.**
    cpfe is itself a translated C++ program so it may want EDG's own
    runtime, and *reading cannot settle it*: `src` holds 145,752
    distinct `_Z`-prefixed tokens, nearly all names it defines itself,
    with ordinary identifiers like `_ZERO` among them. Only the link
    says which are undefined. It is not obviously needed -- EDG is
    built `-fno-exceptions -fno-rtti` and `src` references none of
    `_Znwm`/`_Znam`/`_ZdlPv`/`_ZdaPv`, `__memzero` or
    `__abort_execution` -- so the first link is the measurement and
    the fix, if any, is one line naming `libedg.a`.
  - **AND THE RUNTIME ADDS NOTHING libap ALREADY PROVIDES, checked
    rather than assumed.** `lib_src` holds `exit.c`, `main.c`,
    `error.c` and `memzero.c`, which is the shape that cost this tree
    the gnulib `strerror` round -- but **every DEFINITION there is
    `_Z`-mangled or `__`-prefixed**: `exit.c` defines `_Z4exiti`,
    `memzero.c` defines `__memzero`. The plain C names (`memset`,
    `memcpy`, `malloc`, `free`, `abort`, `exit`) appear only as
    DECLARATIONS and resolve to libap rather than replacing it.
    *The filenames read alarmingly and the definitions do not* --
    the declaration/definition distinction the `reject` round cost a
    build over, asked the right way round this time.
    **And EDG bakes in NO struct sizes**, which is the other thing
    cfront's C did and the reason its oracle existed: zero
    `sizeof X == N` markers against cfront's 132, because EDG emits
    real `sizeof` expressions. *kencc computes every layout here*, so
    conforming `-J` is exactly what the generated code wants and
    `cfrontsz-probe`'s whole class of problem does not recur.
    **Both OFILES lists are sound AND complete** -- 51 and 75, no
    name missing a file and no file missing from a list, which are
    different properties and only one of them was checked the time
    the 47-of-97 probe passed its control and measured the wrong
    types. `mkcont-sweep` 0.
  - **Its staging list doubled as a to-do list for our own headers.**
    Eight APE headers could not be included from C++; **four were
    fixed on their own evidence** later in the same session
    (`signal()`'s prototype, the `SIG_*` casts, `features.h`'s
    `hidden`, `bsd.h`'s `getopt`) and a re-translation need not repeat
    them. **The other four are fixed now too, so the staging list is
    closed**: `stdlib.h`'s unguarded `_Noreturn`, its parameter named
    `template`, `unistd.h`'s parameter named `new`, and `signal.h`'s
    `restrict` read as a duplicate parameter name -- every one a
    parameter name or a keyword, so invisible to a C caller.
    *EDG is a stricter compiler than gcc, and that is what it bought.*
  - **AND THE OBVIOUS FIX FOR TWO OF THEM WAS THE ONE THAT HAD JUST
    BROKEN THE BUILD.** `#define _Noreturn` or `#define restrict`
    under `__cplusplus` would put an UNRESERVED name in a public APE
    header that external packages define themselves -- gnulib ships a
    whole `_Noreturn.h`, and a dozen `config.h` here define
    `restrict` -- which is `reject` again, one round later. **The
    bare-word sweep was run FIRST this time**, and it is what chose
    the spellings: everything used is in the reserved
    double-underscore space, which nothing outside an implementation
    may define.
    **Three of the four need no macro at all.** `restrict` becomes
    `__restrict`, which costs nothing because *kencc lexes all three
    spellings to the same `LRESTRICT`* (`cc/lex.c:1652,1678-1679`) --
    and where a package's own `cdefs.h` defines `__restrict` (twelve
    do) it expands to the qualifier or to nothing, correct either way.
    The two parameters are renamed, which no caller can see.
    `__ape_template` was not invented here: **EDG's generated C
    already carries it**, so the staged edit had used this convention
    and the tree now matches its own output.
  - **The control is a before-and-after pair on IDENTICAL staging, and
    it found a FIFTH item.** A C++ translation unit including
    `<stdlib.h>`, `<unistd.h>` and `<signal.h>` gives **12 errors
    before and 1 after** -- and the survivor is `stddef.h:50`
    typedef'ing **`wchar_t`, which is a built-in type in C++**,
    present in BOTH runs and named nowhere in the NOTE's list of
    eight. *Recorded, not fixed.* The half that could have cost the
    tree is the other one: the same unit compiled as **C is 0
    errors**. `apehdr-sweep` 148 headers / 0 findings with the
    together-case holding at its recorded 8; `apdecl-sweep` 0.
    *The first staging recipe differed slightly between the two runs
    and the after-count was re-taken with the before's exact
    commands* -- two compiles differing in anything but the change
    are not a control, which this file records from the `-J` round.
- **muon** -- in `_OPTIONAL_APPS` commented out. Never built here.
- **go** -- `go1.4` is in the tree, commented out of `_CORE_APPS`,
  and is the only thing that mentions `Ureg` outside libap.

**Ports built but never exercised**, which is a different and cheaper
item -- *a port that builds and has never run is not a port*:
- **chicken** (Scheme) -- `lib/chicken` builds and `cmd/chicken` is in
  `_OPTIONAL_APPS`. Nothing has run a Scheme program.
- **bacon** (BASIC) -- the generated C is clean on gcc and the
  converter RUNS on the host (it answers `BaCon version 5.0.3` and
  converts a `FOR`/`PRINT` program), but **it has never been through
  pcc**. `cmd/basic` is still commented out of `_OPTIONAL_APPS` for
  that reason; build it by hand first.
- **the archivers** -- bzip2, xz, unrar, unace, unarj, clzip. See the
  tar section: `-J` retires the padding hunt, so this is now a check
  rather than a hunt, and the way to do it is to run each one on a
  real archive.

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
- **A NAME absent from a list is not a measurement until you have
  checked that the name could ever have been present.** An absence has
  at least two explanations -- the thing passed, or it was never called
  that -- and only one of them is a result. `socket_inet.test` was
  recorded as having "left the failing-file list" and offered as the
  behavioural confirmation of `-J`; **there is no such file**, the
  names are generated inside `socket.test` by a `foreach {af ...}`
  loop, and `socket_inet`'s four failures never moved. One `ls` would
  have cleared it.
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
- **A binary that `clean` removes and `install` does not rebuild is a
  measurement waiting to be lost.** `cmd/tclsh/tcltest` and
  `cmd/wish/tktest` were both `V:` targets reachable from nothing while
  each mkfile's `CLEANFILES`/`clean:V:` names them, so `mk distclean`
  deleted them and the next suite run used the ordinary shell -- where
  Tcl's suite skips 5317 extra tests and reports **27 FEWER
  failures**. Grep a mkfile's clean rule against what `install`
  actually builds; in Plan 9 mk every `V:` rule for a target runs, so
  `install:V: <thing>` costs one line.
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
- **A symbol `_apemain` references is in EVERY APE binary, and so is
  the whole OBJECT that defines it.** `plan9/callmain.c` names exactly
  two, `_envsetup` and `_malloc_watchinit` -- and while the second
  lived in `malloc/malloc.c`, that reference pulled libap's ALLOCATOR
  into every program in the tree. **f2c supplies its own `malloc`**
  (upstream's optional replacement, off by default in `makefile.u`, on
  in `mkfile.plan9`) and stopped linking: `redefinition: malloc`. So an
  object on that path must define nothing a program might reasonably
  replace; the watchdog's state and init are in `malloc/mallocwatch.c`
  for that reason alone. *The dependency has to run malloc.$O ->
  mallocwatch.$O and never back.*
- **And only `mk distclean` could ever have shown it.** `mk install`
  rebuilds `libap.a` without relinking existing binaries, so a libap
  change that breaks a LINK sits invisible until something forces the
  relink -- rounds later, with nothing nearby to blame. *The rule that
  a library fix can sit unused for rounds has a second edge: so can a
  library BREAKAGE.*
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
- **Before adding ANY name to a public APE header, grep `external/`
  for the BARE WORD** -- not for `name(`, not for `extern int name`.
  A public header's blast radius is every package in the tree, and
  `apehdr-sweep` cannot see it: that sweep compiles APE headers
  against each other, while the collision arrives from a package's
  own header. Declaring `reject` in `libnet.h` -- which
  `<sys/socket.h>` includes -- broke flex, whose `flexdef.h:366` has
  `extern int reject;`, a VARIABLE. **A function-shaped grep cannot
  match a variable**, which is the same miss that let `optind`,
  `opterr`, `optarg` and `stdin` through one round earlier.
- **Syntax-check vendored backends on the host with gcc before shipping**
  (the command is in `docs/notes/tk-plan9.md`); gcc is stricter than pcc
  and a round trip to the VM costs a full rebuild.
- **A Tcl list literal has to survive rc first.** `{}` is a block, `()`
  is a list, only `''` quotes.
- **And `=` is a SYNTAX CHARACTER in rc**, legal only as an assignment
  at the start of a command or inside quotes. `awk -v name=$name` is
  not an argument, it is a parse error -- `token '=': syntax error` --
  and so is any `key=value` passed to any program. Write
  `'name='^$name`, or build the whole thing by concatenation. This
  cost a round on `fdwatch` *after* the `{}`/`()`/`''` rule above was
  already written down, which is why it is its own line.
  **But rc DOES allow white space around it in an assignment** --
  `LC_ALL = C.UTF-8` in `apexp-sh` is valid and always has been, so
  "no spaces" is a sh rule, not an rc one. A checker written from the
  sh habit flags those eight lines and is wrong.

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
  prototype. **And the RETURN value is the half that bites hardest**:
  an undeclared function returns implicit `int`, so a `char *`, a
  `double`, a `size_t` or a `long long` arrives truncated or
  sign-extended with no diagnostic. `strtoumax` calling `strtoull`
  without `<stdlib.h>` is what made bash print `FFFFFFFF9B3A59A5`;
  `sys/lib/tests/apdecl-sweep.py` sweeps libap for the shape.
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
- **NATIVE kencc rounds EVERY struct's size up to 8, and aligns a
  nested struct member to 8 too** (`6c/swt.c`'s `align()`, cases
  `Asu2` and `Ael1`), so `sizeof(struct{char a[500];})` is **504**.
  Field offsets are still right, so a `memcpy` into a local is fine --
  **what breaks is `sizeof` used as a STRIDE or a LENGTH**: `p + 1` on
  a pointer to the type, or writing it as an on-disk record. This made
  `union block` 520 and every archive GNU tar wrote malformed.
  `#pragma pack on`/`off` is the per-struct override (both cases read
  `packflg`), spelled `on` and not `1`.
  **APE IS NOT ON THAT RULE ANY MORE**: `pcc` passes `-J`
  (`conformalign`, not `-P` -- that is the peephole debug flag) on
  every compile, so tail padding is the struct's own alignment and a
  nested struct member takes its own. `pcc -9` is the way back and is
  for the instruments only; `6c` keeps the 9front rule, which is what
  `cmd2/vts` and `vtwin` need against the host's `libc.a`. The switch
  moves sixteen APE structs, all sockets and locks (`sockaddr_in`
  24 -> 16, `pthread_mutex_t` 56 -> 40) plus `termios` -- **and NOT
  `FILE`, `struct stat`, `DIR`, `jmp_buf` or `fd_set`, which the
  earlier warning here asserted and the acid diff refuted.**
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
**`Total 68118 Passed 62159 Skipped 5916 Failed 43`**, 167 files,
marker, exit 0, no `Test files exiting with errors`, four minutes.
**All 43 are listed BY NAME in `docs/notes/tcl-suite.md`** with the
one-command extraction beside them -- the first per-name baseline this
suite has had, and the thing whose absence made every earlier
comparison a total. The log is committed at `tmp/tcl-all.out`.
*(The baseline this is measured against is
`Passed 62138 Failed 64`, same Total and Skipped; the eighteen are
discussed in the `-J` section. A run in between reporting `Failed 37`
was taken under plain `tclsh` after `mk distclean` removed
`cmd/tclsh/tcltest` and is VOID -- both harnesses now say which
interpreter they are.)* The entries below are written against the 64. **The whole
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
**AND `-J` LARGELY RETIRES THAT SWEEP, which is a consequence of the
flag worth stating where the to-do was written.** The tar bug was
`Asu2`'s unconditional 8-byte tail round plus `Ael1` aligning a
nested struct member to 8, and **`-J` fixes both for every APE
compile** -- so an all-char on-disk record now gets its natural size
without anyone reaching for `#pragma pack`. *The predicted failure
mode is gone rather than unmeasured.* Running each archiver on a real
archive is still the only way to know, and is still worth one round,
but it is now a check rather than a hunt. tar's own `#pragma pack`
is a no-op under `-J` (both answers are 500 and 495) and **stays**:
it documents the on-disk intent and keeps the file right under `-9`.

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

**BASH IS `/bin/sh` AND IT BUILDS APExp. The whole hunt below is
CLOSED -- read it as history, not as an open problem.** `cmd/bash/mkfile`'s
`install:V:` adds `cp $BIN/bash $BIN/sh`, `dash` is gone from
`_CORE_APPS` and from `sys/src/external`, and a full `mk distclean`
plus `mk install` completes with bash serving every `sh` the build
asks for. *One shell in the tree instead of two*, which was the goal
named at the end of the fdwatch round below.
**What actually got it there, in order**: `isblank('\t')` (the
allocation storm -- the one that mattered), `getcwd(NULL,n)`, the
fourteen `config.h` features, the `FD_BUFFEREDX` exec poison, and
`mktemp`'s 26 names. **Not one of them was the descriptor leak the
first six rounds were spent on**, and the histogram that ended that
framing -- 142 opens, 251 dups, 447 closes -- is in the section below.
**AND THE SUITE WENT 0 PASSING -> 46**, measured twice in a row with
the same count. The kernel's fd warnings fell from **176 lines across
all 87 sections to 4**, and `move_to_high_fd` was never the thing to
change -- see the next paragraph.
**THE fd WARNINGS WERE THE `sh` SWAP, NOT `move_to_high_fd`, AND THE
CHAIN IS CORRECT AS IT STANDS.** `shell.c:1701` -> `getdtablesize()`
-> `sysconf(_SC_OPEN_MAX)` -> `OPEN_MAX` **256**, capped by
`HIGH_FD_MAX` 256; the loop walks DOWN from 255 for the first free
descriptor and `dup2`s there. *Every link of that is right*, and
shrinking `getdtablesize()` to dodge a kernel message would have been
the "invent semantics" shape -- **and it would also have been
unnecessary**, which is the part worth keeping.
**What changed is WHO runs the wrapper.** Before, `sh` was dash:
`dash run-X` never dups high, then forks bash for the `.tests` **with
`2>&1`**, and that bash inherits dash's SMALL fd group, grows it past
100 and 200, and puts two warnings **inside `$BASH_TSTOUT`** -- in
every one of 87 sections. Now `sh` IS bash: the top-level
`bash run-all` grows the table **once**, and Plan 9's fd group is
copied by fork and kept across exec, so every descendant starts at
`nfd` 256 and never crosses a threshold again. The surviving two
warnings sit at the very top of the log, before any section header,
from one pid. *A harmless message stopped being captured, rather than
stopping.*
**The rule: a message that corrupts a measurement can be fixed by
changing who is measured, not only by silencing the message.** The
recorded plan had been to touch `getdtablesize()` -- a wrong fix to a
problem that then dissolved on its own.
**NOT FULLY EXPLAINED, and held loosely because of it**:
`run-input-test` is the one descendant that still warns, and the
inheritance reading says it should not. It is also the only test that
feeds the script on **stdin** (`${THIS_SH} < ./input-line.sh`) and the
only one without `2>&1` -- so its warnings land in the log rather than
in a comparison, and it passes.
**`run-test` 33 -> PASS is UNEXPLAINED and BOTH readings were
REFUTED.** Its old failures were `chgrp: missing operand`,
`/dev/tty: No such file or directory`, **`ln: ... Too many links`** and
`rm: cannot remove '/tmp/ghi'` -- `Too many links` is STATEFUL, so the
first reading was litter in `/tmp` from the storm-era aborted runs,
with the refutation condition "it fails on a second consecutive run".
**Two runs back to back give the same count**, so that is refuted.
*And the replacement reading was REFUTED BY THE MACHINE*, which is
what the probe was for. I argued that `getgroups()` being a stub
returning -1 leaves `GROUPS` empty, so `chgrp ${GROUPS[0]} <file>`
gets one operand and must still fail. **`echo ${#GROUPS[@]}
"[${GROUPS[0]}]"` answers `0 [0]`** -- the element expands to **`0`**,
so chgrp gets two operands and never prints `missing operand`.
**bash seeds the array from `getgid()` when `getgroups()` reports
nothing** (`general.c:1341`, `get_group_list`), and I had read
`get_groupset` and stopped one function short. *A grep hit is a name,
not an implementation* -- a rule quoted in this file two rounds
earlier.
**And the probe found something nobody asked for**: `${#GROUPS[@]}` is
**0** while `${GROUPS[0]}` has a value, so the count and the element
disagree -- the dynamic getter fills the element but not the array the
count reads. Recorded, not chased.
**What is still unexplained is the REST of run-test**: `t -t 0 <
/dev/tty` sits OUTSIDE both `(( $UID != 0 ))` guards, so neither it
nor the `ln: ... Too many links` line was gated, and both are gone
too. The chgrp family is accounted for and the other two are not.
`run-trap` 16 -> 14 is unattributed as well. *Stop here rather than
offer a fourth story: the pass is stable over two runs and the real
list is where the work is.*
*Everything from here to the ratrace histogram is the record of how it
was found; the standing lesson is the instrument tally, not the bug.*

**(HISTORICAL, now fixed)** **bash could not be `/bin/sh`: it died `Killed: Insufficient physical
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
bug.
**THERE IS A REPRODUCER NOW, and it is far smaller than a full
rebuild**: `cd sys/src/external/bash/tests && /bin/bash run-all`
warns at 100 and 200 descriptors and then dies. (`THIS_SH` unset
makes line 21 run `-c` as a command; that is an artefact of running
`run-all` outside `make tests` and is **not** related -- the warnings
fire regardless, which is itself useful, since it means the leak
does not need the suite to work.)
**Three obvious suspects are already ELIMINATED by reading**, so the
next round should not spend itself there: `close()` calls
`_closebuf`, clears the flags and `_CLOSE`s the fd; Muxbuf slots
**are** recycled (`_startbuf` scans for `b->fd == -1`, which
`_closebuf` sets, so `curfds` never falling is a scan bound and not
a leak); and `dup2()` goes through `close()` rather than round it.
**The recorded plan -- `APEXP_DEBUG=1` and count
`select: buffered now fd=` -- CAN ONLY CONFIRM WHAT IS ALREADY
ASSUMED.** It counts buffering events, so it measures the
hypothesis rather than the leak: if the descriptors are ordinary
`open()`s, or pipes, or something of bash's own, it reports zero,
and zero would be read as exoneration.
**`rc/bin/fdwatch` is the instrument instead, and its FIRST version
was wrong in a way worth keeping.** It found the process by name and
took the last match -- but **a buffered descriptor gives its process
a copy process of the SAME NAME** (`ps` shows the shell in `Rendez`
and the copy process in `Pread`), so it would have watched the copy
process, which holds almost nothing, reported a flat count, and read
as *no leak*. *A measurement of the wrong process is not a null
result, it is a false one.* `-n` now prints every match and refuses
to choose; **`-c` runs the program itself**
(`THIS_SH=bash fdwatch -c /bin/bash run-all`), which removes both the
ambiguity and the race the user had to win by hand. `/proc/<pid>/fd`
lists every open descriptor of a live process **with its path**, so
one run says *what* is leaking rather than *that* something is; the
script samples it, counts (subtracting the cwd line at the top,
which is not a descriptor) and groups the paths commonest first. A
hundred lines of one path names the call site; many distinct paths
under `$TMPDIR` is a create/unlink loop; pipes are a third answer
and a different bug. *Print what the machine says rather than what
the code implies*, and **`ratrace` comes after**, once a path is
named -- ratrace on a whole suite is unreadable, which is why it is
second and not first.
**AND THE SECOND VERSION MEASURED NOTHING EITHER, for a reason worth
more than the leak**: `run-all` exhausts its descriptors and dies in
**well under a second**, while the script slept one second *before*
its first sample and then did six forks per sample (sed, wc, awk,
sort, uniq, sort) to group paths inside the loop. Its entire output
was `/proc/4314/fd does not exist -- no such process`, *which reads
exactly like a pid that was never right*. **An instrument whose
sampling period exceeds the lifetime of its subject reports a
missing subject, not a missing measurement.** Fixed by inverting
both: sample FIRST and sleep after, default interval **0** (flat
out), **one `cat` per sample** appended raw, and all the grouping
moved to a `summarise` that runs once at the end over the log --
`-s` re-runs just that, so a log can be re-read without re-running
anything.
**AND THE THIRD VERSION TOOK 0 SAMPLES TOO, WHICH IS NOW A
MEASUREMENT RATHER THAN A FAILURE.** The pid was right -- fdwatch
said 5579 and the kernel's warnings said `bash 5579` -- the loop was
reached, and `/proc/5579/fd` was **already gone at the first
`test -e`**. Between the fork and that test an rc script must run
`date`, `echo` and `test`, each a fork and an exec, and **rc cannot
read a file without forking at all**. So `run-all` dies in less time
than three forks, and *no amount of tuning makes an rc loop win
this*: it is a property of the shell, not of the interval.
**`ratrace` is therefore the tool now, and the objection to it has
expired.** It runs the command under control from the first
instruction, so there is no race:
`ratrace /bin/bash run-all >[2] /tmp/rt.log`, then the difference
between `grep -c ' open'` and `grep -c ' close'` is the leak and the
`open` lines name the paths. It was second before because ratrace on
a whole suite is unreadable -- **but a run that dies in under a
second is not a whole suite**, and that is what changed.
fdwatch keeps its job for the case it was built for: the long
`mk install` this leak was first seen in.
**Also fixed there: `^` in rc is a CROSS PRODUCT, not concatenation.**
`'x'^(a b c)` is `xa xb xc`, and `` `{date} `` is a list of six
words, so one log line came out as
`==== fdwatch pid=5579 Sun ==== fdwatch pid=5579 Sep ...`. Pass
separate arguments to `echo` rather than concatenating with a list.
**AND ratrace APPEARS TO CHANGE THE OUTCOME, WHICH WOULD RETIRE MOST
OF THE ABOVE.** Under `ratrace` the same suite runs for a long time
with heavy load instead of dying at once. *Not yet confirmed -- it
may still die later* -- but if it holds, **the failure is
RATE-dependent, and a forgotten `close` is not**: 100 descriptors is
100 descriptors however slowly you reach them, so a count-leak
cannot be outrun. What speed CAN change is how many things are alive
at once, and libap's `select()` forks a copy process per buffered
descriptor whose number at any instant is a race between the parent
making them and the children exiting. **That would also explain why
the kernel's last word is `Insufficient physical memory` rather than
anything about descriptors** -- a pile of live copy processes is
both at once, and I have been treating the two warnings as one story
without evidence.
**AND run-all's TOP LEVEL BARELY TOUCHES FILES**, which is the
reading that should have come first: its whole loop is
`for x in run-*; do echo $x ; sh $x ; rm -f $BASH_TSTOUT ; done` --
about forty iterations of fork, exec and wait. **Forty iterations
cannot reach 200 descriptors by opening files, because it hardly
opens any.** So the descriptors come a few at a time from the
machinery rather than from the work, and the suite is incidental.
**`sys/lib/tests/bash-fdloop-test.sh` is that loop with the tests
taken out** -- three sections of 400 iterations: no fork, fork plus
exec, and fork plus exec plus a redirection, each printing the
descriptor count *and the bash/sh process count* from `/proc`. **The
pair is what carries the result**: 1 surviving while 2 dies puts the
leak in fork/exec/wait and turns an 83-file suite into three lines.
**Reference measured on glibc: 5 descriptors, flat throughout.**
*`/proc/<pid>/fd` is a FILE on Plan 9 and a DIRECTORY on Linux*,
which the host run caught by reporting -1 everywhere.
**IT REPLICATES THE CRASH -- 400 iterations of a shell loop, no test
suite at all.** So the 83-file suite really was incidental.
**But the first version could not say WHICH loop**, and both faults
were mine: (1) section 1 was meant to be the fork-free control and
was not, because the counter was `` `expr $i + 1` `` and **`expr` is
an external command** -- all three sections forked 400 times, so the
pair that carried the whole result distinguished nothing. *A control
that does the thing it is controlling for is not a control.* Bash's
`$((i+1))` is a builtin. (2) everything went to **stdout, which is
buffered**, while the kernel's warnings go straight to the console --
so the run printed `exceeds 100 file descriptors` *before* the
script's own first line, which reads like the descriptors being gone
before the script started and is only a buffer. Everything goes to
**stderr** now, and a **section 0** forks 200 times printing the
counts every 25, so the output is a RATE rather than a verdict --
and it comes first, because a run that dies having printed a slope
has still answered.
**AND THE ratrace LOG ALREADY HELD THE ANSWER while I asked it the
wrong question.** I said I would not guess the format and then told
the user to `grep -c ' open'`; ratrace capitalises, so all four
counts came back 0 from a 272 MB, 3.4-million-line log. Its last
twenty lines are `Brk` over and over, the break climbing ~480 bytes
a time, ending in `fault read addr=0x0` -- **a null dereference,
which is `malloc` returning 0.** So the primary phenomenon is MEMORY
and the descriptors may be the side effect, which is the opposite of
the framing every round so far has used. The histogram
(`awk '{print $3}' /tmp/rt.log | sort | uniq -c | sort -nr`) names
every syscall by frequency and needs no re-run.
**THE INSTRUMENT WAS STILL THE PROBLEM, A THIRD TIME, AND THE SHAPE
IS ALWAYS THE SAME.** Moving to stderr did NOT fix the ordering: the
warnings still printed before the script's first line, and `start:`
never appeared at all. **Because counting the descriptors FORKED** --
`fdcount` ran `wc -l` inside `$( )`, a subshell plus an exec, per
sample, *in a test whose entire subject is what forking costs*. The
run could die inside its own first measurement, which is exactly
what "pid, then nothing" looks like. `fdcount()` now forks NOTHING:
a `read` loop on Plan 9 (where `/proc/<pid>/fd` is a FILE), a glob
on Linux (where it is a DIRECTORY), both builtins, answering in a
**variable** rather than through `$( )`. And every step appends to
**`/tmp/fdloop.log`**, which survives the kill and is in the order
it happened -- *console ordering is not evidence when one writer is
the kernel*. Counts at 1, 2, 5, 10, 20, 50, 100, 200 forks, so the
slope near zero is visible before anything can die. glibc: flat at
5 throughout.
Back on dash meanwhile, and the goal is one shell rather than two.
*(That goal is MET -- bash is `/bin/sh` and dash is out of the tree.
See the top of this section.)*

**coreutils `sort` COULD NOT MAKE A TEMPORARY FILE, AND IT IS OURS
-- FIXED, NOT YET MEASURED ON THE VM.** `sort: cannot create
temporary file in '/tmp': empty file name`, hit while trying to
histogram a 272 MB ratrace log. **libap's `mktemp` could produce 26
names per process, ever**: it wrote `getpid() % 100000` into five of
the six X's and tried one trailing letter `a`..`z`, then set
`*template = 0`. So the 27th temporary any program asked for failed,
the caller opened `""`, and Plan 9 said `empty file name` -- **a
Plan 9 errstr arriving through libap's `EPLAN9` arm, so the text
after the colon describes the last system call rather than the
directory the message names.** Read as a `/tmp` problem it leads
nowhere. `mkstemp`'s twenty retries re-derived *the same twenty-six*,
since nothing in them varied but the pid: **a retry is only a retry
if something varies between the tries.**
**The tree already had the right generator and was not using it** --
musl's `__randname` sits in the same directory, is already in
`OFILES`, and `mkdtemp.c` beside it has always used it. So libap
held a working name generator and a broken one at once. Both now use
it (~1.07e9 names); `mkstemp` is shaped like `mkdtemp`, retries only
on `EEXIST`, and restores the template on failure; `mkostemp` now
applies `O_CLOEXEC` with `fcntl` rather than dropping it.
**Measured, not argued**: the old algorithm replicated on the host
gives up at **exactly file 27**, 26 of 64. `mkstemp-test.c` asks for
**64 at once** precisely because anything at or below 26 would have
passed against the bug; 0 failures on glibc. `_tempmark()` is the
version marker, so the test will not LINK against a libap predating
the fix.
**Why it survived**: the failure arrives only at the 27th, so a
program making a handful of temporaries is fine for ever and one
making dozens dies.
**CONFIRMED ON THE VM**: `_tempmark = 1`, 5 of 5, 0 failures.

**THE BASH FAILURE IS NOT A DESCRIPTOR LEAK. IT IS MALLOC, AND THE
HISTOGRAM SAYS SO IN ONE LINE.** Over the whole 3.4-million-line
ratrace log:

```
3456769 Brk          447 Close       142 Open
    251 Dup          160 Pread        86 Stat
     58 Create        56 Pwrite        2 Rfork      1 Exec
```

**142 opens and 251 dups against 447 closes** -- it closes MORE than
it opens, so there is no descriptor leak at all, and every round of
this hunt was chasing one. **`Brk` outnumbers everything else by four
orders of magnitude.**
**And `2 Rfork`, `1 Exec`: the process died before the suite ran a
single test**, so the storm is the whole run rather than something
the tests provoked.
**THE KERNEL'S fd WARNINGS ARE ALMOST CERTAINLY NOT A LEAK EITHER.**
bash's `move_to_high_fd()` dups its internal bookkeeping descriptors
up near the reported limit, and Plan 9's fd *table* grows to the
highest index used -- so 251 dups give `exceeds 100/200 file
descriptors` with a handful of files actually open. That is why the
warnings arrive **before the script's first line**: it is bash
starting up, not the script leaking. *Two warnings printed together
are not one story, and I treated them as one for six rounds.*
**THE ARITHMETIC NAMES THE SIZE CLASS.** `_malloc_brk` does
`sbrk(0)` then `sbrk(gap+n)` -- **two Brk syscalls per call**, which
is why the log shows each address twice. So ~1.73M allocations. The
break moves ~480 bytes each, and with `CUTOFF = 12` and
`BLKSZ(pow) = 32 + 2^pow` batched `(CUTOFF-pow)+2` at a time, **pow 4
gives 48 x 10 = 480 exactly**. So these are allocations of **<= 16
bytes, ten per sbrk pair: about 17 million tiny objects, none
freed.**
**THE DEATH IS A JUMP TO ZERO, AND IT IS THE CONSEQUENCE RATHER THAN
THE EVENT.** The last non-`Brk` lines:

```
5878 bash Exits ... = process exited            <- the $( ) child
5875 bash Await ... "5878 0 0 40 ''" = 14       <- parent reaps it
5875 bash Pread ... 255 ... ".BASH_TSTOUT=${TMPDIR}/..." = 1149
5875 bash Stat  ... "/proc/5875/wait"    (x3)
5875 bash Noted 2d10a7 1 = 0
bash 5875: suicide: sys: trap: fault read addr=0x0 pc=0x0
```

**`pc=0x0` is a JUMP to address zero** -- a call through a null
function pointer, not a bad data pointer -- and `Noted 1` is
`noted(NDFLT)`, libap's note handler returning, immediately before
it. Plan 9's `Insufficient physical memory` **is a note**, so the
order reads: memory exhausted -> kernel posts the note -> libap's
handler runs -> control goes to 0. *The crash is downstream of the
storm; do not chase `pc=0` as the bug.*
**`fd 255` is bash reading its own script** -- which is also the
`move_to_high_fd` that explains the descriptor warnings.
**`wait4`'s WNOHANG path allocates (`_dirstat`) but is NOT the
storm**: the trace shows THREE stats of `/proc/5875/wait`, not
millions. *It does hold a real bug, recorded not measured*: when
`_dirstat` returns nil it falls through to the **blocking** `_WAIT()`
with `WNOHANG` set, and the same happens when the pending message
belongs to a different pid.
**THE LINE NUMBERS LOCALISED IT TO ONE BURST, AND EXCLUDED EVERY I/O
MECHANISM.** `grep -n -v ' Brk ' /tmp/rt.log | tail -40`:

```
   1581:5875 bash Stat ... "/proc/5875/wait" = 71
3458015:5875 bash Noted 2d10a7 1 = 0
3458016:bash 5875: suicide: fault read addr=0x0 pc=0x0
```

**3458015 - 1581 = 3456434 of the 3456769 `Brk` lines -- 99.99% -- in
a SINGLE gap**, so the storm is one event rather than something
accumulating across the run. The prediction written before the grep
(gap opens after the `Pread` of fd 255, closes at the `Noted`) held,
and its refutation condition (a gap before the `Await`, which would
have put `wait4` back in frame) did not fire.
**And the gap contains NO SYSCALL OF ANY KIND**, which is an
exclusion rather than a detail: a spinning READ loop would show
`Pread`, a spinning WAIT loop `Await`/`Stat`, a create/retry loop
`Open`/`Create`. None appear. So the loop is pure computation holding
~17M objects of <= 16 bytes.
**`read_comsub` is refuted by that same fact** -- it calls `zread`
every iteration and grows by doubling `realloc`, so a loop there
would show `Pread` lines. Five mechanisms argued from source now,
five refuted by the log.
**malloc and free are NOT at fault, checked rather than assumed**:
`free()` pushes straight onto `btab[size]` so the free list does
refill, `BLKSZ(4)=48` and `(CUTOFF-4)+2 = 10` give the observed 480
exactly, and the batching loop links all nine spare blocks
correctly. The 17 million objects are genuinely live. It is a bash
loop, and the trace places it after line 21's `$( )` child was
reaped -- line 1563 shows that child writing `"30465"` to fd 1, so
it RAN AND SUCCEEDED.
**AND THAT IS WHY SIX ROUNDS FOUND NOTHING: `Insufficient physical
memory` IS A KILL.** The kernel destroys the process, so there is no
stack to take and nothing for `acid` to attach to -- every round of
this hunt examined a corpse the kernel had already disposed of, and
the only evidence available was a trace of the one syscall the loop
happened to make. **Two instruments now, and neither needs the
other:**
- **`sys/lib/tests/bash-comsub-test.sh`** bisects run-all's lines
  17-27 into ten sections, each writing a durable marker to
  `/tmp/comsub.log` *before* the statement it runs, so **the last
  line names the statement that did not return**. Simplest first,
  every case expected to return ahead of every case expected to
  hang. Nothing in it forks but the sections about forking -- `echo`
  plus `>>` is a builtin and a redirection, the mistake `fdwatch`
  and `bash-fdloop-test` each made twice. glibc: all ten ok in 13ms.
- **`$APEXP_MALLOCMAX` (megabytes), a heap watchdog in
  `malloc/malloc.c`.** Abort EARLY, while the machine is healthy:
  `APEXP_MALLOCMAX=64` breaks the process after 64 MB instead of
  ~800, leaving it Broken rather than gone, and `acid <pid>` then
  `stk()` names the calling function -- how gnulib's self-recursive
  `strerror` and `_buf.c:544` were both settled after source reading
  failed on them. Counts **both** sbrk sites: `_malloc_growtop` has
  the same two-`Brk` signature as `_malloc_brk`, so a trace cannot
  tell them apart and a watchdog watching one could report a flat
  heap while the break ran away. `wd_fail` unlocks the arena before
  `abort()`, since aborting under our own lock would hang where a
  break was wanted. Off unless set, at one load and one branch per
  sbrk.
  **ITS FIRST VERSION BROKE EVERY APE PROGRAM IN THE TREE, and the
  reason is worth more than the instrument.** It read
  `$APEXP_MALLOCMAX` lazily on the first sbrk, and I checked the
  thing that seemed to matter -- *does `getenv` allocate?* It does
  not (`ap/env/getenv.c` is a plain scan). **That was the wrong
  question.** `environ` is CREATED BY a malloc:
  `plan9/_envsetup.c:140` is `environ = pp = malloc(...)`. So on the
  first allocation of every APE program `environ` is still null, and
  getenv has no null check -- so `while(*p != NULL)` faults at
  address 0 before `main`. *Not a re-entrancy bug but a CIRCULAR
  DEPENDENCY: the allocator asked for state that the allocation was
  being made to create.* The general form is worth carrying:
  **"does it allocate?" is only half of "is it safe to call from the
  allocator" -- the other half is "does it depend on anything
  allocated?"**, and for libc globals the answer is usually yes.
  `_malloc_watchinit()` is now called from **`_apemain`, right after
  `_envsetup()`** -- the same "one path every APE program takes"
  that `argv0` uses -- so the allocator calls nothing at all and
  only tests a static. Allocations before that point are unwatched,
  which is the safe direction to be wrong in.
*The general shape, and it is new: a failure mode that KILLS leaves
nothing to measure, so the instrument's job is to fail earlier and
more politely than the kernel does.* **And its cost, immediately:
that is the FIFTH time in this investigation the instrument has been
the visible fault** (fdwatch's sampling period, fdwatch's `-n`,
fdloop's `expr` control, fdloop's forking `fdcount`, and now this).
**A Broken process KEEPS ITS MEMORY**, so `acid` must be followed by
a kill, or a few aborted runs exhaust a small VM by themselves.

**AND THE ACCIDENT NAMED A LINE IN bash: `ifs_value` IS NOT A
POINTER.** The one run that happened gave a full `acid` stack:

```
bash 1764: suicide: sys: trap: fault read addr=0x2e pc=0x2310ad
list_string(separators=0x428891, ...) subst.c:3133
expand_word_internal(...)  subst.c:12072   ifs_chars=0x2e
call_expand_word_internal / expand_string_assignment / 
expand_assignment_string_to_string / assign_in_env variables.c:3598
do_assignment_statements / expand_words / execute_simple_command
```

`subst.c:3133` is `for (xflags = 0, s = ifs_value; s && *s; s++)`,
and 12072 is `list = list_string (istring, "", quoted)` -- so
`separators` is the literal `""` and the fault is
**`*ifs_value` with `ifs_value == 0x2e`**, i.e. the byte `'.'` in a
`char *`. The caller's `ifs_chars=0x2e` agrees. Declarations are
consistent (`char *` in `subst.h:353` and `subst.c:161`), so it is
runtime corruption, not a type mismatch.
**One corruption would explain BOTH symptoms**, which is why it is
worth chasing: with `ifs_value` garbage, `list_string` either faults
on it (this run) or, if the garbage happens to address readable
bytes, splits a string into millions of words -- and every word is a
retained `WORD_DESC` plus `WORD_LIST` node, small and never freed.
*That is exactly the storm's signature: ~17M live objects of <= 16
bytes and no syscall in the loop.* And the path is the same one the
line numbers localised the storm to: assignment expansion, straight
after line 21's `$( )`.
**PROVENANCE IS UNSETTLED AND MUST BE BEFORE THIS IS BUILT ON.**
The new libap faults at 0x0 before `main`, yet 1764 reached
`reader_loop` -- so 1764 was most likely a bash predating the libap
install, which would make the stack clean evidence about bash. That
is an inference, not a measurement. **Re-run it after the rebuild**;
if the same stack comes back, it is bash's and this is the bug.

**SECOND INSTRUMENT BUG, SAME FUNCTION: `abort()` ALLOCATES ON
PLAN 9, so the watchdog re-fired inside its own abort.** The fixed
libap starts bash again, and the run gave an `acid` stack that was
nothing but its own recursion, thousands of frames deep:

```
wd_fail()             malloc.c
_malloc_brk(n=0x1e0)  malloc.c
malloc()              malloc.c
open(flags=0x1, ...)  fcntl/open.c:76
note(...)             signal/kill.c:16
kill(sig=0x5, ...)    signal/kill.c:58
abort()               stdlib/abort.c:8
wd_fail()             <- round again
```

`abort()` raises SIGABRT, libap's `kill()` posts a note, `note()`
OPENS `/proc/<pid>/note`, and `open()` mallocs -- so the over-limit
allocator is re-entered from inside its own abort and buries the
stack it exists to expose. **I had written "abort() may allocate" in
the comment justifying the unlock and then not drawn the
conclusion**: `wd_fail` now clears `wd_max` as its FIRST statement,
so the abort path allocates freely and the message prints once.
*Sixth instrument fault; and unlike the others this one was named in
my own comment one line above the bug.*
**One thing that stack settles for free**: `_malloc_brk(n=0x1e0)` is
**480**, which independently confirms the size class derived from
the trace's break steps -- `BLKSZ(4) * ((CUTOFF-4)+2) = 48 * 10`.

**AND THE BISECT ANSWERED BY RETURNING NOTHING, WHICH RETIRES ITS
OWN PREMISE.** `/bin/bash bash-comsub-test.sh` printed the two fd
warnings, died `Insufficient physical memory`, and then
`cat: /tmp/comsub.log: No such file or directory`. The log's first
line is written by `mark "bash-comsub-test: pid $$"`, the script's
first statement -- **so bash never executed one line of it.**
Therefore the storm is NOT in `run-all`'s lines 17-27, and none of
the ten sections is the trigger; it is in bash's startup or its
first statement. That agrees with two things already recorded: the
histogram's `2 Rfork, 1 Exec` (dead before the suite ran anything)
and the fd warnings arriving before the script's first line.
**And it gives a sharp discriminator nobody had asked for:
INTERACTIVE bash works -- the prompt those commands were typed at is
bash -- while NON-INTERACTIVE `bash <script>` dies.** So the next
reproducer is not a script at all:

```
APEXP_MALLOCMAX=32 /bin/bash -c 'echo hi'
```

**AND IT IS CLEAN: `hi`, no storm, AND NO fd WARNINGS EITHER.** The
second half was not asked for and is the more useful of the two: the
`exceeds 100/200 file descriptors` pair did not appear at all, so the
warnings and the storm arrive *together*. They may still be two
effects of one cause rather than one story -- but "printed together
and absent together" is a good deal more than they had before.
**So the whole remaining search space is the gap between `-c` and a
script file**, and it is small. `rc/bin/bash-scriptladder` walks it
in one run: `-c` (the control), an **EMPTY** file, a one-line file,
and the same content on **stdin**. **It is an rc script on purpose**
-- the subject dies, and a harness written in the dying shell dies
with it; rc survives every case and prints a `returned` line after
each, so a missing one names the case that storms. No loop (rc has
no `break`), no `^`, and the only `=` are leading assignments, which
rc does allow.
Reading it: **empty file storms** -> parsing and execution are
innocent and it is the script-FILE setup, where fd 255 and
`move_to_high_fd()` live, which is the smallest possible target;
**3 storms but 4 does not** -> the NAMED FILE specifically rather
than reading a script as such; **3 and 4 both** -> reading a script
at all; **nothing storms** -> it needs something
`bash-comsub-test.sh` has and these do not, and its HEADER is what
to bisect next, not its sections.
**No watchdog in the ladder, deliberately**: it only needs to know
*which* cases storm, and `hi` versus a death message answers that,
while `APEXP_MALLOCMAX` would leave a Broken process holding 32 MB
*per failing case*. Re-run only the smallest storming case with the
watchdog, take the stack, then `echo kill > /proc/<pid>/ctl`.

**THE LADDER RAN AND NOTHING STORMED -- AND IT REFUTED WHAT I WROTE
ONE ROUND EARLIER.**

```
1  bash -c 'echo hi'      hi         no warnings   returned
2  an EMPTY script file   (nothing)  WARNINGS      returned
3  a one-line file        hi         WARNINGS      returned
4  the same on stdin      hi         no warnings   returned
```

**The fd warnings are now SEPARATED from the storm.** Having seen
`bash -c` come back with neither, I recorded that they "arrive
together and vanish together" -- and case 2 breaks that in the
cleanest way available: an **empty** script file raises both
warnings and then **exits successfully**. So they are
`move_to_high_fd()` on the script descriptor exactly as predicted,
they are produced by the NAMED FILE and nothing else here, and
**they are harmless**. *A run that warns has said nothing about
whether it will die.* Two rounds ago they were conflated with the
storm; one round ago I linked them on evidence that looked stronger
than it was; a single measurement has now separated them. **Stop
reading them as a symptom.**
**And the storm is not the script file at all** -- not parsing, not
a named file, not reading a script.
**WHAT ALL FOUR CLEAN CASES SHARE IS THAT NOT ONE OF THEM FORKS.**
`echo` is a bash builtin, so 1, 3 and 4 run it in the shell itself
and 2 runs nothing. Against that, **every case that has ever
stormed forks**: run-all's line 21 is `SUFFIX=$( ... )`,
`bash-comsub-test.sh`'s third statement is `rm -f $LOG`,
`bash-fdloop-test.sh` is 400 iterations of fork/exec/wait -- and
the histogram over the whole dying run was `2 Rfork, 1 Exec`, with
the storm starting right after the one child was reaped.
**`rc/bin/bash-forkladder` asks that**, same rc harness: `-c` with
an EXTERNAL echo (one fork), `-c` with a command substitution
(fork + pipe + reap), each again from a FILE, and **case 5, the
first four statements of `bash-comsub-test.sh` verbatim in shape**
-- an assignment, an external command, a function definition and a
call. *Case 5 is what keeps the ladder honest*: if even that
returns and writes its log, the failure has stopped reproducing and
the whole reading above is about a bug that is no longer there,
which is worth knowing at once rather than after another reduction.

**IT RAN, AND THE FORK HYPOTHESIS IS REFUTED -- CASE 5 ALONE
STORMS.**

```
1  -c with an EXTERNAL echo        hi            returned
2  -c with a COMMAND SUBSTITUTION  hi            returned
3  a FILE with an external echo    hi            returned
4  a FILE with a substitution      hi            returned
5  bash-comsub-test.sh's opening   KILLED, no log
```

The refutation condition was written down and it fired: 1 to 4
fork, exec, build a pipe, read a child's output and reap it, from
`-c` and from a file, and **every one came back**. *Four mechanisms
cleared in a single run, which is what a ladder is for -- and case
5 still dying is what says the bug has not evaporated under us.*
**So it is what case 5 has and case 4 has not**: an external command
taking a VARIABLE-expanded argument, a function DEFINITION, a
function CALL, a `>>` redirection inside a function, and **`"$*"`**.
**`$*` IS THE SUSPECT, AND THE REASON IS NOT TASTE: it is the one
construct in case 5 that reads IFS.** It joins the positional
parameters with IFS's first character through
`string_list_dollar_star` (`subst.c:2900`), which reads
`ifs_firstc`/`ifs_firstc_len`; nothing in cases 1 to 4 touches IFS
at all. **And that is where the single stack this hunt has produced
already pointed** -- `fault read addr=0x2e` in `list_string` on
`s = ifs_value`, with `ifs_value` holding `'.'`. *Two independent
lines arriving at IFS from opposite directions -- a stack that
faulted on it, and a ladder whose only storming case is the only
one that reads it -- and the convergence is worth more than either
alone.* It also makes the unsettled provenance of that stack much
less important.
**`rc/bin/bash-ifsladder` splits case 5 into its five parts**, IFS
last: `${#IFS}` as a **direct probe** (pure builtin, and a healthy
bash answers **3**), an external with a variable argument, a
function definition, a definition plus call, a `>>` inside a
function, then `"$@"` and `"$*"` at top level, then case 5 again
unchanged. **`$@` is asked beside `$*` deliberately**: they differ
in exactly the thing under suspicion, since `$*` JOINS with IFS's
first character and `$@` does not join at all -- *asking only one
would leave a negative result with two explanations*. All eight
return on glibc and case 1 answers 3.

**IT RAN, AND IFS IS REFUTED TOO -- ONLY THE FILE STORMS.**
`${#IFS}` answers **3**, `"$*"` joins to `a b c`, `"$@"` likewise,
and the variable argument, the function definition, the call and
the `>>` inside a function all return. **Cases 1 to 7 clean; case
8, the same thing in a FILE, killed.** So the construct my two
converging lines pointed at works perfectly.
**AND THAT REFRAMES THE ONE STACK THIS HUNT HAS PRODUCED.** The
watchdog's `fault read addr=0x2e` was `s = ifs_value` with
`ifs_value` holding a `'.'`. If reading IFS is healthy in isolation
-- and case 7 says it is -- then **memory was ALREADY corrupt by
the time that frame ran**. *The stack shows a VICTIM, not a
culprit*: something had written a character into a `char *` in BSS.
Chasing `setifs` would have been chasing the wrong end, and the
convergence I called worth more than either line alone was two
lines pointing at the same casualty.
**ONE STRUCTURAL DIFFERENCE HAS NEVER BEEN ASKED.** Every `-c` case
passes and every FILE case so far passed -- empty, one-line, with a
substitution -- so it is not "a file" as such. **But every file
tested held ONE-LINE commands, and case 8's function definition
spans three lines.** A multi-line compound command is the first
thing in this investigation that makes bash's PARSER ask its input
for more *while a command is still open* -- `shell_getc` refilling
`shell_input_line` from fd 255 mid-command. Through `-c` the whole
text is in memory and that path is never entered.
**`rc/bin/bash-fileladder` asks it**, all from files: a ONE-LINE
function; the same function over THREE lines; multi-line with
`"$*"`; multi-line with `>>`; **a multi-line `if/then/fi`, which is
a compound command that is not a function**; and case 8 unchanged.
*That fifth case is what makes it a bisect rather than a guess* --
if a multi-line `if` storms, functions are cleared entirely and the
subject is the parser's refill; if it does not and the multi-line
function does, the opposite. Same reason `$@` was asked beside
`$*`. Indentation is a TAB everywhere, as case 8's was, so it is
not a hidden variable. All six return on glibc.

**AND IT ANSWERED: A COMMAND THAT SPANS A NEWLINE IN A SCRIPT
FILE.**

```
1  a ONE-LINE function in a file       hi      returned
2  the same function over THREE lines  KILLED
3  multi-line + "$*"                   KILLED
4  multi-line + >>                     KILLED
5  a multi-line if/then/fi             KILLED   <- NOT a function
6  case 8 unchanged                    KILLED
```

**Case 5 carries the result**: a compound command that is not a
function, dying exactly like the rest. So **functions are cleared
entirely**, and with them `$*`, `>>`, the variable argument and the
external command. The discriminator is the single thing cases 2-6
share and case 1 does not -- a newline *inside* a command -- which
is the first thing in this investigation that makes bash's input
layer deliver more text **while a command is still open**. `-c` has
the program in memory and never enters it; a file of one-line
commands never needs it, which is why every earlier file case
passed. *Seven mechanisms refuted by measurement now -- descriptor
leak, copy processes, `wait4`, `pc=0`, `read_comsub`, forking, IFS
-- one run each.*
**`rc/bin/bash-lineladder` asks the one remaining question that
changes WHICH FILE to read**, since "spans a newline" has two
implementations behind it: the **LEXER** wanting another line (a
backslash continuation, an unterminated quote -- `shell_getc` at
`parse.y:2475` refills `shell_input_line` and the grammar never
sees an incomplete command) versus the **PARSER** wanting one (an
open `if`, `{`, function body or dangling `|`, where the grammar is
mid-rule). Five cases: a continuation, a quote across a newline, a
`{ }` group, a pipeline broken after `|`, and the `if` as control.
All five return on glibc.
**Then the stack, which is finally cheap** -- the subject is four
lines instead of an 83-file suite:
`APEXP_MALLOCMAX=32 /bin/bash /tmp/bli-5.sh`, `ps | grep bash`,
`acid <pid>`, `stk()`, then `echo kill > /proc/<pid>/ctl`.

**IT RAN, AND "ANY COMMAND SPANNING A NEWLINE" IS REFUTED TOO.**

```
1  backslash continuation   (lexer)   hi there   returned
2  a quote across a newline (lexer)   a / b      returned
3  a { ... } group          (parser)  KILLED
4  a pipeline broken after| (parser)  hi         returned
5  if/then/fi               (parser)  KILLED
```

**Case 4 is the one that carries it.** `echo hi |` then `cat` spans
a newline, the parser wants another line, and it **returns** -- so
"the input layer delivering more text mid-command" is cleared as
well, and so is the lexer's refill (1 and 2). What is left is
**`{ }` and `if/fi`: a newline token reaching the GRAMMAR inside an
open COMPOUND command.** In 1, 2 and 4 the newline never becomes a
token -- the backslash removes it, the quote absorbs it, and bash
skips newlines after `|`. *Eight mechanisms refuted by measurement
now, and the reproducer is three lines: `{`, `echo hi`, `}`.*
**Still open and cheap after the stack**: whether it is the
RESERVED WORD or the compound command, which a multi-line
**subshell** `( ... )` would split, since it is compound and not a
reserved word.
**AND THE WATCHDOG COULD NEVER HAVE LEFT A BROKEN PROCESS -- note
semantics, measured.** The limit fired at 33554656 bytes in 72507
sbrk calls, and then the process was simply GONE: `ps` showed
nothing, `acid 13576` answered `can't open /proc/13576/text`.
`abort()` is `kill(getpid(), SIGABRT)`, which posts a note whose
string is an ordinary word; libap does not handle it, so
`signal.c:102` reaches `_NOTED(1)` (NDFLT) and **the kernel's
default for a plain note is to EXIT**. Only a `sys:` note -- a real
trap -- makes a process break and stay. *So the instrument promised
a Broken process that its own mechanism could not produce.*
**`wd_fail` now SLEEPS instead**, printing the pid twice (to attach
and to kill) and napping for up to fifteen minutes before
`_EXITS`. Faulting deliberately would also break it, but that puts
the instrument back on note semantics and on whatever SIGSEGV
handler the subject has installed; **sleeping removes the question
-- `acid` attaches to a LIVE process**, which is how `_buf.c:544`
was found here, and `ps` shows the subject sitting in `Sleep`
rather than needing to be caught. *Seventh instrument fault.* The
`_SLEEP`/`_EXITS` prototypes are copied exactly from `sys9.h`
rather than recalled, since kencc widens an argument only when a
prototype is visible.

**AND THE SLEEPING WATCHDOG WORKED: `33540K Sleep bash`, `acid`
attached, FULL STACK.**

```
_SLEEP(a0=0x3e8)                      syscall/_SLEEP.s:6
wd_fail()                             malloc.c:195
_malloc_brk(n=0x1e0)                  malloc.c:261
malloc()                              malloc.c:361
xmalloc(bytes=0x10)                   bash/xmalloc.c:104
make_word_list(word=.., wlink=..)     bash/make_cmd.c:156
make_simple_command(command=0x489370, line=0x2, element=..)  make_cmd.c:488
yyparse()+0x1c13                      y.tab.c:2629
parse_command() / read_command() / reader_loop() / main
```

**`y.tab.c:2629` is inside case 62, `simple_command: simple_command
simple_command_element`** -- the rule that appends ANOTHER WORD to
an existing simple command. Case 61 is the same call with
`(COMMAND *)NULL`, and the frame's `command=0x489370` is non-null,
**so it is case 62 and not 61**.
**So the parser is appending word after word to one simple command
for ever, which means `yylex` is returning an ENDLESS STREAM OF
WORD TOKENS.** The parser is doing exactly the right thing with the
tokens it is handed; **the bug is in the LEXER**, and every
allocation is a 16-byte `WORD_LIST` node.
**`xmalloc(bytes=0x10)` is `sizeof(WORD_LIST)` exactly** -- two
pointers -- which is the `<= 16 bytes` class the ratrace break
steps predicted. *Those two routes really are independent*: one is
arithmetic over `sbrk` deltas in a dead process, the other a live
frame's argument. Unlike the `ifs_value` "convergence", neither is
downstream of the other.
**Calibration worth keeping**: the `ifs_value` reading got the
OBJECT right -- "every word is a retained `WORD_DESC` plus
`WORD_LIST` node, small and never freed" -- and the PRODUCER wrong,
naming `list_string` where it is the parser. *A correct prediction
about the artefact is not a correct prediction about the code that
makes it.*

**FOUND, AND IT IS ONE MISSING FLAG ON ONE TABLE ENTRY:
`isblank('\t')` ANSWERED FALSE.** The second sample named it --
`read_token_word(character=0x9)`, TAB, with `xmalloc(bytes=0x1)`,
so `1 + token_index` is 1 and **the word is EMPTY**.
The chain, every link measured:
1. `ap/ctype/ctype.c` gave TAB `_ISspace|_IScntrl` with **no
   `_ISblank`** (the offsets in that file are OCTAL: entry 11 is 9).
   C99 7.4.1.3 wants isblank true for exactly space and tab.
2. bash's `syntax.c` is **generated** by its own `mksyntax`, whose
   `addblanks()` is `if (isblank (uc)) lsyntax[uc] |= CBLANK;` --
   with the comment *"the default blank characters will be space and
   tab"*. So the shipped table gave TAB `CSHBRK` and no `CBLANK`,
   **contradicting its own generator's stated intent**, which is what
   proves it was generated against a broken `isblank`.
3. `shellblank()` reads CBLANK, `shellbreak()` reads CSHBRK. So a tab
   was **not whitespace to skip** but **was a word delimiter**.
4. `read_token` therefore handed the tab to `read_token_word`, which
   ungot it and returned a zero-length WORD; the parser appended the
   empty word (case 62) and asked for another token. For ever, one
   16-byte `WORD_LIST` per turn.
**EVERY LADDER RESULT FALLS OUT OF IT**: one-line commands, the
backslash continuation, the quote across a newline and the dangling
`|` have no tab; `{`/`if`/the function bodies were all written
TAB-INDENTED. So "compound command" was never the discriminator.
**AND I MADE IT INVISIBLE MYSELF.** `bash-fileladder`'s header says
*"Indentation is a TAB everywhere, as case 8's was, so it is not a
hidden variable between the cases."* Holding a variable constant
removes it as a confound **and removes any chance of detecting it**
-- it was the cause, and I had frozen it deliberately in every case
of three ladders. *Control for a variable and you also blind
yourself to it; the things you standardise are the things a bisect
can never name.*
**FIXED IN FOUR PLACES, and the library alone would not have been
enough**: `_ctype[9]` gains `_ISblank`; **`isprint` had to change
with it**, because its mask was `(graph bits | _ISblank)` and used
_ISblank as a stand-in for "space" -- correct only while space was
the sole character carrying it, so the tab fix alone would have made
`isprint('\t')` true. It is a FUNCTION now, not a macro, since
`isgraph(c) || c == ' '` cannot be a macro without evaluating `c`
twice. And **`bash/syntax.c` is corrected by hand**, because it is
checked in and the mkfile compiles rather than regenerates it, so
the wrong answer was frozen there at generation time.
**`ctype-xcheck.c` sweeps all 256 x 12 rather than asking about
tab**, since the table is hand-written and one wrong entry is as
likely as another: **0 of 3072 wrong** now, and the old table
replicated beside it gives **exactly 1** -- `TAB isblank glibc=1
libap=0` -- which both confirms the fix and says nothing else in the
table was wrong.
**The sweep for other frozen answers is bounded and clean**:
`mksyntax` is the only build-time generator in `external/` that asks
`isblank`, and `syntax.c` the only file it produces. Every other
`isblank` caller is a runtime one and simply gets the right answer
now.
**CONFIRMED ON THE VM: `run-all` GETS PAST THE STORM.** The same
command that has died for weeks now runs real tests and prints real
output -- `comsub-posix.tests`, `comsub-posix6.sub`, the
syntax-error cases, `argv[1] = <abcde>` and the rest. **bash no
longer dies of the allocation storm**, and since the only changes
were `_ctype[9]`, `isprint` and one entry in `syntax.c`, the chain
is measured end to end rather than argued.
**It then FROZE at `run-comsub2`, and that one is NOT OURS: the
test picks a command name that EXISTS on Plan 9.**
`comsub2.tests:68` is `echo NOT${ p; }FOUND`, under the comment
*"command not found should still echo error messages to stderr"* --
the name `p` is chosen precisely because a unix has no such
command. **9front's `/bin/p` is the pager.** bash found it, exec'd
it, and `p` blocked reading stdin for ever.
**Measured end to end, and `ps` did most of it.** Four processes,
one chain: `1771 bash` (`/bin/bash run-all`) -> `2298 sh`
(`sh run-comsub2`) -> `2299 bash` (`bash ./comsub2.tests`) ->
**`2306 p`, in `Pread`** -- every one of the first three in
`Await` at 0:00 CPU. Both stacks name their child by pid and the
arithmetic closes it: 2299's `wait_for(pid=0x8fa)` is **2298**,
and 2299's `wait_for(pid=0x902)` is **2306**, the pager. 1771's
frames are `execute_for_command`/`execute_case_command`, which is
`run-all`'s own `for x in run-*` loop. *No libap call is
misbehaving*: `wait4` is blocked on a child that genuinely has not
exited.
**The output file is what placed it, with no instrument at all.**
`$BASH_TSTOUT` survives the freeze (the `trap ... 0` that removes
it never fires), and its last line is line 65's `set: +m: invalid
option`. Normally a block-buffered log's tail is a lower bound --
but that line is **stderr**, unbuffered, and line 68's whole
purpose is to write to stderr too, so its ABSENCE is real position.
*Check which stream a log's last line came from before discounting
it for buffering.*
**The collision is checkable and `p` may not be alone.** The
`.right` files expect these to be missing: `a`, `after`, `foobar`,
`hijkl`, `notthere`, `p`, `qfoo`, `quux`. **A collision only HANGS
if the program reads stdin**; one that exits produces a wrong diff
and reads as an ordinary failure, so the hang is the loud case
rather than the only one.
**With `</dev/null` the suite RUNS TO THE END** -- `p` reads EOF and
exits, `comsub2` fails its diff (correctly -- it wanted
`p: command not found`), and the loop reaches `run-vredir` and
beyond. Read that as "the rest of the suite" rather than a clean
number: it changes every test's stdin, not just this one's.

**AND THAT FIRST COMPLETE RUN MEASURED NOTHING -- 14795 lines, 86
test files, and `../bash: not found` in 75 of them.** `run-all:49`
is `: ${THIS_SH:=../bash}`, upstream's default, because bash is
normally built in its own source directory and the Makefile sets
`THIS_SH = $(BUILD_DIR)/$(Program)`. **APExp installs bash to
`/bin/bash` and never builds it at `../bash`**, so almost every file
invoked a program that does not exist. *The log is indistinguishable
at a glance from a real one*: right shape, right file names, a
plausible amount of diff -- `run-array` 855 lines, `run-new-exp` 813
-- and those are whole `.right` files showing as ABSENT OUTPUT, not
failures. **Zero files passed.** Same family as the stale suite log
and the `tclBinary` staleness: *anything measured from outside the
source in front of you should say where it came from.*
**THREE conditions, each failing silently on its own**: `THIS_SH`
naming a bash that exists; `recho`, `zecho`, `printenv` and `xcase`
built in `tests/` (the Makefile's `TESTS_SUPPORT`, built from
`../support/*.c` -- **nothing in APExp's build makes them**, which is
what the earlier `recho: command not found` was); and stdin on
`/dev/null` for `/bin/p`.
**`rc/bin/bash-runtests` is the harness**, and it exists because
three preconditions that fail silently are three ways to spend a
round on a worthless log. It builds the four helpers, sets `THIS_SH`,
redirects stdin, prints `bash-runtests: COMPLETE`, and **prints the
`../bash` count FIRST and refuses the result if it is not 0**. rc,
like the five ladders, because a harness written in the shell under
test cannot report that shell dying.
**Its own summary had the bug it is meant to catch, twice.** The
"passed" list printed every section unconditionally; and `/^run-/`
also matches an ERROR line -- `run-rhs-exp: 1: ../bash: not found` --
which reads as a header with nothing after it, *i.e. as a PASS*, and
was the one file the first summary reported as passing. Anchored at
both ends (`/^run-[-A-Za-z0-9_.]+$/`) it reports 86 sections and none
passing, which is the true answer. *Eighth time in this campaign the
instrument was the visible fault.*
**Read which SIDE of a diff a line is on before reading what it
says.** `run-vredir`'s screenful of `cannot duplicate fd: Invalid
argument` and `$fd: Bad file descriptor` looked exactly like a libap
`fcntl` bug, and `fcntl.c`'s `F_DUPFD` does carry an `EGREG` arm for
buffered descriptors -- but `run-vredir` is `diff $BASH_TSTOUT
vredir.right`, so `<` is ours and `>` is expected, every line on
screen was `>`, and those were `vredir.right` lines 95-123 verbatim.
`vredir6.sub` sets `ulimit -n 6` and *wants* the failure. Nothing of
ours was in frame.
**`set -m` is a red herring and was excluded by reading**: the two
`set: -m: invalid option` lines are `config.h:33`'s
`/* #undef JOB_CONTROL */` showing through, an expected diff.
**`function_substitute` does not fork** (`subst.c:6925` dup2s
stdout onto an anonymous file) and `anonopen` falls through to
`sh_mktmpfd`, a real unlinked temp file rather than a pipe -- so
there was never a funsub child or a pipe deadlock to look for.

**AND THE FIRST VALID RUN HUNG FOR 1h36m -- WHICH FOUND THE REAL
STATE OF THIS PORT: bash is built with most of its own features
COMPILED OUT.** The harness worked (`built recho zecho printenv
xcase`, `THIS_SH=/bin/bash`), and `tail` on the log was one line
repeating: `./set-e.tests: line 66: x: command not found`. Line 66 is
`until (( x == 4 )); do`. **Without `DPAREN_ARITHMETIC` `((` is not
an arithmetic command**, so `(( x == 4 ))` parses as two nested
SUBSHELLS running the command `x`, which is never found, so the
`until` condition never succeeds. *An infinite loop, not a freeze* --
and `run-all` has no timeout, so one looping test stops the suite.
**It is `READLINE` eleven times over.** `sys/src/external/bash/config.h`
had `#undef` on `ALIAS`, `PUSHD_AND_POPD`, `BRACE_EXPANSION`,
`DISABLED_BUILTINS`, `PROMPT_STRING_DECODE`, `SELECT_COMMAND`,
`COMMAND_TIMING`, `ARRAY_VARS`, `DPAREN_ARITHMETIC`, `EXTENDED_GLOB`,
`COND_COMMAND`, `ARITH_FOR_COMMAND`, `PROGRAMMABLE_COMPLETION` and
both `CASEMOD_*`. Upstream ships them all off and `configure` turns
them on; APExp hand-maintains the file as it does perl's.
**Nothing was missing from the build**: `alias.c`, `array.c`,
`arrayfunc.c`, `assoc.c`, `braces.c`, `pcomplete.c` and `pcomplib.c`
are all in OFILES, and `bi-alias`, `bi-pushd`, `bi-declare`,
`bi-test`, `bi-let`, `bi-shopt`, `bi-complete` all in OBJBUILTINS --
compiled, linked, switched off by commented-out lines. *A capability
present and not declared*, for the third time (READLINE, zipfs's two
`file stat` keys, this).
**The suite had been saying so and I read it as boilerplate.** The log
carries `warning: all of these tests will fail if arrays have not
been compiled into the shell`, `...if the conditional command has not
been compiled`, `...if extended pattern matching has not been`. Every
one was accurate. *A warning printed unconditionally is still a
warning about something.*
**`COND_REGEXP` was defined while `COND_COMMAND` was not**, and
`COND_REGEXP` does nothing except add `=~` to `[[ ]]`. A switch whose
only purpose is to extend a feature that is off is a tell.
**Left OFF deliberately, and the reason is a CLAIM nothing checked**:
`PROCESS_SUBSTITUTION` needs `/dev/fd` or named pipes, and
`config.h:597` already says `#define HAVE_DEV_FD 1` -- while Plan 9
binds the fd device at **`/fd`**. That is the OPPOSITE shape to the
fourteen above: a capability *declared* but possibly absent. `ls
/dev/fd` settles it, and declaring a second feature on top of an
unverified one would make any failure unattributable.
**gcc-swept before shipping, because a rebuild plus a suite run costs
hours.** `builtins/builtext.h` is generated by the build, so the check
needed `mkbuiltins` built on the host first and the 43 `.def` files
expanded; then `-fsyntax-only` over the main sources and all 43
builtins came back **clean**. **And the control fires**: preprocessing
y.tab.c and subst.c against the old config.h and the new gives
**+1579 and +1824 lines**, so the sweep really did examine newly
reachable code rather than passing vacuously. (`variables.c`'s one
complaint, `CONF_HOSTTYPE`, is a `-D` the mkfile passes -- a harness
artefact, confirmed by supplying it.)
**NOT YET MEASURED ON THE VM.** Predict: `set-e` stops looping, and
the per-file failure list shrinks a great deal rather than a little,
since `array`, `assoc`, `cond`, `extglob`, `braces`, `dollars`,
`new-exp` and `arith-for` are gated wholesale. Refuted if the suite
fails to BUILD, or if the list barely moves -- which would mean the
features are reaching the shell but something underneath them is
wrong, and that is a different investigation.

**AND THE REBUILD WOULD NOT START: `getcwd(NULL, n)` KILLED THE
PROCESS, AND IT IS LIBAP'S, NOT THE CONFIG CHANGE.**

```
bash 7263782: suicide: invalid address 0x0/4096 in sys call
_FD2PATH(a0=0x5)             syscall/_FD2PATH.s:6
getcwd(buf=0x0, len=0x1000)  ap/unistd/getcwd.c:21
get_working_directory(...)   bash/builtins/common.c:603
set_pwd() / initialize_shell_variables() / shell_initialize()
```

**`buf=0x0` is the whole bug.** libap's getcwd passed its argument
straight to `_FD2PATH` with no null check, so `getcwd(NULL, n)` -- the
glibc/musl/POSIX.1-2008 "allocate it for me" form, which a great deal
of GNU code uses -- handed the kernel address zero. `0x1000` is 4096,
`PATH_MAX`, which is what bash asks for at `builtins/common.c:603`.
**bash HAD ALREADY DETECTED THIS AND SHIPPED THE FIX, AND THE LINK
ORDER THREW IT AWAY.** `config.h` says `#define GETCWD_BROKEN 1`, so
`config-bot.h:66` does `#undef HAVE_GETCWD`, so `lib/sh/getcwd.c`
compiles a getcwd that DOES allocate, and `getcwd.$O` is in the
mkfile's `OBJSH`. But that object lands inside **`libsh.a`**, and
`sys/src/ape/cmd/bash/mkfile` links deliberately:
`#link libap first to already occupy symbols supported by the system
libap` / `LIB= .../libap.a $BASHLIBS ...`. So `getcwd` resolved out of
libap and bash's own copy was never pulled from the archive.
*A program's workaround for a library bug is only as good as the link
order* -- **the gnulib `strerror` finding pointing the other way**:
there libap's correct version lost to gnulib's broken one, here bash's
correct version lost to libap's broken one. *A symbol libap provides
decides which implementation runs, whichever direction the quality
runs in.*
**And libap held the right idiom NEXT DOOR**: `misc/get_current_dir.c`
implements `get_current_dir_name()` with the comment *"like
getcwd(NULL, 0) on Linux -- allocates"*, by malloc'ing PATH_MAX and
calling getcwd into it. Same shape as `mktemp` ignoring `__randname`
in its own directory -- *the library contained a working version of
the thing it could not do*, for the second time.
**FIXED IN LIBAP rather than by reordering the link**, which is the
right half of the choice: every program calling `getcwd(NULL, ...)` is
fixed, and the mkfile's "libap first" policy stays intact.
`getcwd(NULL,0)` takes PATH_MAX because **Plan 9's `fd2path` truncates
SILENTLY** -- it returns -1 only for a bad descriptor -- so a
grow-until-it-fits loop has nothing to test. `_getcwdmark()` is the
version marker. `getcwd-test.c`'s **section 2 is bash's exact call and
used to KILL rather than fail**, so reaching section 3 at all is the
result; **section 4 is the control** (`getcwd(buf,0)` must be EINVAL),
since an implementation that allocated unconditionally would pass
everything else. 0 failures on glibc.
**CONFIRMED ON THE VM**: `_getcwdmark = 1`, all four sections PASS,
0 failures -- and section 2 is bash's exact `getcwd(NULL, PATH_MAX)`,
which used to kill the process rather than fail, so reaching section 3
was itself the result.
**Why it had not bitten before is NOT settled and is not worth a
round**: `set_pwd` reaches `get_working_directory` only when `PWD` is
absent from the environment or does not match `.`, so the path was
always one import away. Recorded as unexplained rather than guessed.
**`/dev/fd` DOES NOT EXIST -- measured, and `HAVE_DEV_FD 1` was a
lie.** `ls /dev/fd` says `file does not exist`; `ls /fd` lists
`/fd/0 /fd/0ctl /fd/1 ...`. **Not re-pointed at `/fd`**: a Plan 9
`/fd` entry is the descriptor of *the process that opens it*, so
handing the name to a CHILD -- the whole point of `<(...)` -- names
the child's own descriptor. *Do not invent semantics to make a feature
compile.*
**`NAMED_PIPES_MISSING` was also wrong**, i.e. bash was told FIFOs
work: `unistd/mkfifo.c` is a stub returning -1. Defined now. **And the
stub set `errno = 0` while failing** -- the most common bug shape in
this tree, here in its purest form: a failure that refuses to say why,
so `perror` prints whatever the last call left behind. ENOSYS now, as
`symlink()` gives.
*Two false claims and fourteen false denials in one config.h: a
hand-maintained capability file is wrong in BOTH directions, and the
two kinds fail differently -- a denial costs a feature silently, a
claim costs a crash.*

**AND THE libap REBUILD WOULD NOT COMPILE, which found a THIRD
constant with two definitions.**

```
cpp: limits_generic.h:137 /amd64/include/ape/limits.h:30 getcwd.c:6
     Macro redefinition of NGROUPS_MAX
cpp: limits_generic.h:143 ... Macro redefinition of PIPE_BUF
cc: 6c: cpp errors
```

`limits_generic.h` said `NGROUPS_MAX 10` and `PIPE_BUF
_POSIX_PIPE_BUF`; `sys/limits.h` says **32** and **8192**. **Neither
value in `limits_generic.h` was ever in effect**: that file ends with
`#include <sys/limits.h>`, `sys/limits.h` `#undef`s before every
`#define`, and it has **no include guard**, so it is re-read and wins
every time. The two dead values existed only to break any translation
unit that reached `<sys/limits.h>` FIRST and `<limits.h>` second --
i.e. one `#include <unistd.h>` before `#include <limits.h>`.
**The other shared names did not fail because their values AGREE**
(`NAME_MAX` 255, `PATH_MAX` 4096, `MAXPATHLEN`), and an identical
redefinition is legal. *That is why the trap was invisible: the same
file is both correct and fatal depending on include order, and only
the two disagreeing macros say so.*
**This is `PATH_MAX` for the third time** -- two definitions in two
files that include each other -- and the rule written after the first
one is the rule that found it: **when a constant is wrong, grep for
EVERY definition of it.** Applied properly this round rather than
trusting the two cpp happened to name, since **cpp stops at the first
errors**: the full overlap of the two files is now exactly three
macros and all three agree.
*No effective value changes*, so stale objects stay consistent and
this needs no `distclean` of its own. `getcwd.c` takes
`<sys/limits.h>` as `at_functions.c` beside it already does -- *the
include with a working neighbour under the same flags beats the one
that only ought to work*.

**AND THE SUITE NOW MEASURES REAL THINGS -- then STOPS at
`run-jobs`.** The diffs are genuine at last: `< 1.0000` against
`> 1,0000` (a decimal comma, so `LC_NUMERIC`), and `Passed all 1318
Unicode tests` against `1770`. That shape is only possible with
`THIS_SH` resolving and the fourteen features compiled in, so the
config change reached the shell.
**`run-jobs` is the stop**, and the log stood still for four minutes
while the longest thing in `jobs.tests` is `sleep 30`. The file is
`sleep N &` and `wait` throughout -- `wait %1`, `kill -n9 $pid; wait
$pid`, `kill -sHUP $pid2; wait $pid2`, and two bare `wait`s with
several children outstanding. **This tree already records a
never-measured bug exactly there**: `wait4`'s `WNOHANG` path falls
through to the BLOCKING `_WAIT()` when `_dirstat` returns nil, and
again when the pending message belongs to a different pid -- which is
what `wait -n` and a bare `wait` do. *A live suspect rather than a
guess, but `ps` decides it, not the reading.*
**AND THE KERNEL'S fd WARNINGS NOW CORRUPT TEST OUTPUT, which is new
and is NOT a new bug.** `< bash NNNN: warning: process exceeds 100
file descriptors` appears as a diff line in `run-invert`,
`run-invocation` and `run-iquote` -- files with nothing to do with
descriptors. The mechanism was settled two rounds ago and is
`move_to_high_fd` (`general.c:681`): with `maxfd < 20` it takes
`getdtablesize()`, capped by `HIGH_FD_MAX` **256**, and libap reports
`OPEN_MAX` 256, so bash `dup2`s its script to ~254 and Plan 9's fd
table grows past both thresholds. **Recorded, not fixed**:
`getdtablesize()` is telling the truth, and shrinking it to dodge a
kernel message is the "invent semantics" shape. *The warnings were
proven HARMLESS by the empty-script case; what is new is that they are
now LOUD -- a harmless message that lands in a captured stream stops
being harmless to the measurement.* Size it from the harness summary
before touching anything.

**`date` CRASHES, and `/proc/n/ppid` is what stopped me blaming it.**
The full `ps` -- ungrepped, after two rounds of grep hiding things --
showed **two `Broken date` processes** beside the stalled harness, and
a `Broken` process is ALIVE to the kernel (stopped at a fault), so
`await` on one can never return. That fit the `Await` perfectly and
was wrong: `ppid` says 7273473 and 7287195, **both gone**, so the two
dates are ORPHANS and nothing waits on them. The actual child of
`bash-runtests` is an **`awk` in `Pwrite`** -- my own summary, so that
stall is mine. *Three mechanisms offered, the right one not among
them: a list of alternatives is only exhaustive over what you thought
of.* **`ppid` costs nothing and would have saved the whole detour.**
**The crash itself is real and new**, with a complete stack:

```
save_abbr(...)+0x3d        gnulib/time_rz.c:127
mktime_z(tm=.., tz=0x43f480) gnulib/time_rz.c:310
__strftime_internal(...)   gnulib/strftime.c:2092   <- the %s arm
fprintftime(...)           gnulib/strftime.c:1198
show_date(...)             coreutils/src/show-date.c:32
show_date_helper(...)      coreutils/src/date.c:397
main                       coreutils/src/date.c:709
```

`time_rz.c:127` is `char const *zone = tm->tm_zone;` and the only
dereference below it is `if (*zone)`, guarded by `if (!zone || zone
points INSIDE tm) return true;`. **So the fault is `*zone` with a
non-null `tm_zone` that is neither NULL nor internal** -- a stale or
invalid pointer.
**Sitting directly under it: libap's `mktime` never writes
`tm_zone`, `tm_gmtoff` or `tm_isdst` back into `*t`.** It is 132
lines and only normalises the date fields. glibc and the BSDs set all
three, and `mktime_z` is written around that -- it does
`struct tm tm_1 = *tm; mktime(&tm_1); save_abbr(tz, &tm_1);`.
*Recorded as a conformance gap, NOT as the diagnosis*: `localtime_rz`
should already have repointed `tm_zone` into the `tz` object, so the
chain is not closed.
**It prints correct output and THEN dies** -- both manual runs showed
the right time -- which points at teardown or at a later `%`
conversion rather than at the formatting that produced the visible
line. *A program that answers correctly and then faults is reporting
something after the answer.*
**Next, and cheap, because a Broken process keeps everything**:
`acid <pid>` then `lstk()` prints the LOCALS, so `zone`'s actual
value is one command away -- NULL, inside-tm, or garbage are three
different bugs. And `date` twice in a row with `ps | grep date`
between says whether it leaves a corpse every time.

**THE FIRST VALID COMPLETE RUN OF BASH'S SUITE: `lines mentioning
../bash (MUST be 0): 0`, `COMPLETE` marker, ~85 files with a
non-empty diff and NONE passing.** The harness's own validity line is
what makes that readable at all.
**But about 35 of those files show exactly `3`, and 3 is one diff
position header plus the two kernel fd warnings.** They agree with
their `.right` in every respect except a message from the KERNEL --
`pprint` sends it to the process's own fd 2, and every `run-<name>`
captures stderr with `2>&1`, so it lands inside the comparison. *So
the single largest entry in the failure list is not bash and not
libap.*
**The harness now buckets three ways** -- REAL diff / warnings-only /
passed -- and that is a MEASUREMENT, not a fix: nothing is suppressed
or rewritten, the noise is counted apart so the remaining list is the
one worth reading. **Position lines (`2,3d1`) are skipped** as
structure rather than content, and a real file's number is now its
differing lines with the warnings subtracted. *Lumping ~35 noise
entries in with the real ones makes every later per-file comparison
unreadable, and comparing per file is this tree's rule.*
**`run-jobs` WAS NEVER A STOP, and I spent a round on it.** It shows
`231` in the list, so it ran to completion; the log looked static
because `jobs.tests` legitimately sleeps for minutes. *I had even
computed its longest sleep and still read "the log stopped changing
for four minutes" as a hang.* **A log that is not growing is not a
stopped run when the test it is inside is a sleep** -- the `ps` STATE
would have said so, and the one I took was of the wrong process.
**The real stall was my own `awk`, at the very end**, blocked in
`Pwrite` with `bash-runtests` waiting on it; killing it let the
summary print. *Ninth instrument fault.* **Why an awk writing to the
terminal blocked is UNEXPLAINED** -- the committed harness has no pipe
-- and the evidence is gone, because the `/proc/<pid>/fd` listing was
not taken before the kill. *Take the cheap reading BEFORE the
remedy; a kill destroys the only copy.*
**And `lstk()` named `date`'s bad pointer exactly: `zone =
0x834383635`.** Bytes `34 38 36 35` are ASCII **`4865`** -- a `char *`
holding digit TEXT, which is the `ifs_value` shape a second time, and
the fault is in strftime's **`%s` arm**, the one conversion that
formats a number. *Two independent bugs in this tree have now been a
pointer containing characters.*

**THE SUITE RAN TO THE END AGAIN -- 21 minutes, not stuck -- AND THE
LOG HELD A LIBAP BUG NOBODY WAS LOOKING FOR: `printf` DID NOT KNOW
`%td`, `%jd` OR `%hhd`.** `stdio/vfprintf.c`'s `tflag` table had `h`,
`l`, `L` and `z` and not `t` (ptrdiff_t), `j` (intmax_t) or a second-`h`
rule for `hh`. **An unrecognised conversion prints the letter and
CONSUMES NO ARGUMENT**, so `printf("%td", n)` printed the literal text
`td` and left `n` in the va_list -- *every conversion after it in that
format string took the wrong argument*. A `%s` after a `%td` reads a
string from an integer. *A conversion that prints garbage is a bug in
one value; one that eats no argument is a bug in every value after it.*
**So EVERY DIFF POSITION LINE ON THIS SYSTEM HAS ALWAYS BEEN GARBAGE**:
diffutils has `#define pI "t"` and prints every line number through
`fprintf(outfile, "%"pI"d%c%"pI"d", trans_a, sepchar, trans_b)`, so
`1,2d0` came out `td\x01tddtd` -- `td` per number, and the `%c` taking
`trans_a` instead of the comma. **The corruption decodes, which is the
only reason it was readable**: `td(tdctd,td` is `(`=40 and `,`=44, and
40 and 44 are that hunk's own first lines; `tdM-9...M-;` is 185/187,
likewise. *A wrong value that decodes back to the right one names the
mechanism, not just the fault.*
**~370 literal sites** across coreutils, gnulib, diffutils, patch,
bison, tar, flex, pcre2, grep and sed. **Two things hid it**: `z` --
1439 of the ~1800 uses -- was the one modifier someone had already
added; and **the `PRI*` macros dodge it**, since APE's `<inttypes.h>`
spells `PRIdMAX` as `"lld"` rather than `"jd"`.
**And `vfscanf.c` HAS HANDLED ALL THREE SINCE IT WAS WRITTEN** --
`case 'j'`, `case 'z'`, `case 't'`, right pointer types. The library
knew these on the INPUT side and not the output side: third time it
contained a working version of the thing it could not do, after
`mktemp` ignoring `__randname` and `getcwd` beside
`get_current_dir_name`.
**Measured old beside new, which is cheaper than a rebuild**: the real
tables and the real cracking loop lifted verbatim into a host program
give **5 failures before and 0 after**, `%zu`/`%hd`/`%lld`/`%ld`/`%Lf`
identical both ways -- and the old run reports `conv='t'`, the
conversion character *being* the modifier letter, which is exactly the
`td` on screen. `printfmod-test.c` is the regression test, 0 failures
on glibc; **its section 4 is the one that matters**, putting a second
conversion after the first and asking what THAT printed, because an
implementation with the number right and the argument wrong passes
everything else. `_printfmark()` is the marker. `vfwprintf` needs no
change -- it narrows and calls `vfprintf`.
**CONFIRMED ON THE VM**: `_printfmark = 1`, all six sections PASS,
**0 failures** -- and the marker is what makes that readable, since the
test could not have LINKED against the libap that had the bug. The
idiom has now paid five times (`_sock_listenmark`, `_execmark`,
`_ttymark`, `_getcwdmark`, this).
**It changes NO test result** -- diff's exit status and its `<`/`>`
lines were always right -- and it is **not** `date`'s crash, since
`strftime.c`/`time_rz.c` use none of these modifiers. *The suite's
value here was as a corpus, not as a scoreboard.*

**AND THE HARNESS WAS DEFEATED BY THE BUG IN THE LOG IT WAS READING.**
`bash-runtests` identified a diff position line by its leading DIGIT
(`/^[0-9]/ { next }`) -- true of `2,3d1`, and false of `td^Atddtd`. So
~37 files whose only real difference was the two kernel fd warnings
were each counted as having one differing line, and the summary
reported **9 warnings-only against 76 real where the truth is 46
against 40**. *Tenth instrument fault, and the sharpest: it assumed
diff can print a number.* A section's content is now exactly its `<`
and `>` lines -- which assumes only that diff marks which side a line
came from, the one thing the format is for -- and that rule holds
whether or not printf is fixed.
**The prediction written down last round was RIGHT and the instrument
said otherwise**: ~35 warnings-only and ~50 real, against 46 and 40.
*When a measurement contradicts a prediction, ask what sits between
them* -- the rule was already in this file from `io-14.1`, and the
thing between them was the same log the measurement came from.
**So the real failure list is 40 files**, largest first: `run-histexpand`
287, `run-builtins` 225, `run-jobs` 176, `run-glob-bracket` 103,
`run-printf` 86, `run-redir` 78, `run-func` 70, `run-glob-test` 63,
`run-dirstack` 53, `run-procsub` 35. **AND THAT PREDICTION CAME IN: 46 OF 86 NOW PASS**, the same count on
two consecutive runs. 45 are the warnings-only set exactly as called,
plus `run-test`; `run-input-test` is clean as well. The real list is
**39**, with the same ten at the top and the same counts --
`run-histexpand` 287, `run-builtins` 225, `run-jobs` 176 -- so
*nothing in the real list moved*, which is what says the 46 were noise
rather than a shared cause.
**The fd warnings are CLOSED as an item** (see the top of this
section): they were the largest single entry in the failure list and
they went without one line of libap changing.

**AND THE TWO BIGGEST REAL FILES ARE THREE SWITCHES AND ONE STUB.**
`run-histexpand` 287 and `run-builtins` 225 are 512 of the remaining
~1500 differing lines, and reading them cost one round rather than
several because each partitions cleanly.
- **`run-histexpand` is `BANG_HISTORY`, ALL 287 lines of it.**
  `set: -H: invalid option` and `!!: command not found` throughout;
  the switch is `#undef` and gates **43 sites**, `set -H`
  (`flags.c:199`, `histexp_flag`) among them. **The file's own first
  line says so** -- *"warning: all of these tests will fail if history
  has not been compiled into the shell"* -- which is the third time a
  suite's unconditional warning turned out to be accurate.
  **It was LEFT OFF as a decision rather than an oversight** -- it
  changes what `!` MEANS in every interactive line, where `READLINE`
  and `HISTORY` only changed how a line is edited -- **and it is now
  ON, chosen rather than swept in.** Nothing was missing from the
  build, as with READLINE before it: `histexpand.$O` is already in
  `libreadline.a` (lib/readline's HISTOBJ), which `cmd/bash/mkfile`
  already links, so `history_expand` resolves with no mkfile change.
  `config-bot.h:104` makes it imply HISTORY, already defined.
  **MEASURED: 287 -> 35, and the 35 are ONE OTHER SWITCH.** Every
  remaining line is `syntax error near unexpected token '('` on
  `<(...)` in `histexp4.sub`, `histexp5.sub` and `histexp7.sub` --
  **process substitution**, off deliberately because `/dev/fd` does
  not exist. So `run-histexpand` is now accounted for end to end: 252
  BANG_HISTORY + 35 procsub, nothing unexplained. The prediction said
  "near 0" and a surviving remainder would mean something *under* `!`
  was wrong; it is a second known absence instead, which is the
  better of the two ways to be off.
  **And `run-history` 33 -> 0: it PASSES.** That file was never read
  and was not predicted.
  ***AND THE `HFILES` FIX IS CONFIRMED BY THE SAME RUN***: the user
  ran `mk install` with no `mk clean` in `cmd/bash`, and a `config.h`
  edit reached the binary. That was the stated refutation condition --
  "if `run-histexpand` does not move, suspect the rebuild" -- and it
  moved.
  **Per file, nothing else changed in substance.** 39 real -> 38,
  46 passing -> 47. `run-shopt` 24 -> 19, `run-nquote` 18 -> 16 and
  `run-complete` 20 -> 19 went with BANG_HISTORY; every other count is
  identical. **`run-trap` 14 -> 16 is the one that ROSE and it is not
  a regression**: both runs hold the same two things (JOB_CONTROL's
  `set -m`, and xtrace lines run together without newlines), and the
  count moved only because the `+[8] false` hunk regrouped -- two
  concatenated trace lines in one run, three in the next. *A count
  that rises because a diff hunk realigns is not a new failure;
  reading the section is what separates them.*
  **CONFIRMED two runs later: it went back to 14 with nothing
  touching it**, which is what an unstable hunk does and what a
  regression does not. *The reading was right and the cheap evidence
  for it arrived by itself.*
- **`run-builtins` 225 partitions 175 / 42 / 6 / 2**, and only the
  second is ours:
  **175 are `HELP_BUILTIN`** -- `help: command not found`,
  `builtin: help: not a shell builtin`, and pages of `help <name>`
  usage on the expected side. `bi-help.$O` is already in OBJBUILTINS
  and `help.def` in DEFFILES, and `help.def` opens `$DEPENDS_ON
  HELP_BUILTIN`, so mkbuiltins emitted no builtin. **A capability
  present and not declared, for the FIFTH time** (READLINE, zipfs's
  two `file stat` keys, the fourteen features, this). **Turned ON.**
  **42 are `umask` and they ARE ours** -- see below.
  **6 are `enable -f`** (dynamic loading; Plan 9 has no dlopen, the
  same wall as perl's XS) and **2 are process substitution**, off
  deliberately because `/dev/fd` does not exist.
- **gcc-swept before shipping, and the control was VACUOUS the first
  time.** `help.c` and `builtins.c` give **0 errors** in the class 6c
  treats as fatal (`-Werror=incompatible-pointer-types`,
  `implicit-function-declaration`, `int-conversion`) -- gcc's own
  `-Wparentheses` and `-Wdiscarded-qualifiers` complaints are
  upstream's style. But my first control compared `-DHELP_BUILTIN`
  against nothing *while `-DHAVE_CONFIG_H` was supplying the define
  from the header both ways*, and reported 5537 lines twice.
  Preprocessed against a `config.h` with the line reverted it is
  **625 -> 5537**. *A control that cannot differ is not a control* --
  the same trap as the check that cannot fail, met from a new angle.

**`umask()` DISCARDED ITS ARGUMENT AND ALWAYS ANSWERED 0 -- FIXED.**
The whole of `ap/stat/umask.c` was `mode_t umask(mode_t){ return 0; }`
under the comment *"No such concept in plan9, but supposed to be
always successful"*. The first half is true of the KERNEL and false of
this library; the second half is not what the call is for. **This is
the most common bug shape in this tree** -- a stub answering the wrong
thing rather than "nothing to do" -- and the rule it breaks is already
written down: *a platform having nothing to DISPLAY is no reason for a
value not to read back.*
**Storing it is not "inventing semantics", for a locatable reason**:
libap is the code that chooses the permission it hands `_CREATE`, at
exactly **two** user-facing sites (`fcntl/open.c`'s O_CREAT arm and
`unistd/mkdir.c`). The other `_CREATE` callers are internal
(`/env/_fdinfo`, `/env/_sighdlr`, `tmpfile`, `access`'s probe) or copy
an existing mode (`rename`), and POSIX puts no umask on any of them.
**And it composes with the file server rather than fighting it**: Plan
9 already hands out `perm & (dirperm | ~0666)`, so the result is the
intersection -- a umask may only ever REMOVE bits, which is exactly
its contract.
**Two limits, both deliberate and both recorded**: the initial mask is
**0, not 022**, so by default nothing differs and only a program that
calls `umask()` sees any change -- *a conformance fix should not also
be a default change*; and it does **not survive `exec`**, since the
static lives in the process image and carrying it over means another
`/env/` variable beside `_fdinfo` and `_sighdlr`. `umask-test.c`
**section 4 is a PROBE that measures that gap** rather than asserting
it, so the next reader gets a number instead of this paragraph.
**Section 3 is the one that matters**: an implementation that stored
the mask and never applied it -- *a value that reads back and does
nothing* -- passes sections 1 and 2 and fails only there. It asserts
only that the masked bits are ABSENT, never that the others are
present, because the latter would be a test of the file server.
**Measured old beside new**: 0 failures on glibc, and the old stub
replicated beside it gives **5**, with section 3 printing `0755` under
mask 027. `_umaskmark()` is the version marker.

**MEASURED, AND THE PREDICTION WAS REFUTED TWICE -- usefully both
times.** Predicted `run-builtins` 225 -> ~8.
**Run 1 gave 177**, and the 48 that went were EXACTLY the umask block:
`umask`-shaped lines **42 -> 0**, so *that fix is CONFIRMED* and
nothing else in the suite moved. But `help: command not found` was
still there, with the commit provably in `main`.
**Because `mk` DOES NOT REBUILD BASH WHEN `config.h` CHANGES.** No
bash source file changed, and the mkfile names `config.h` nowhere --
so not one bash object was recompiled, while libap rebuilt only
because `umask.c`, `open.c` and `mkdir.c` are *sources* that changed.
**This is `tclBinary.c` for the THIRD time**, and the rule was already
in this file: *a header not in `HFILES` is a header `mk` does not
rebuild for.*
**Run 2, after `mk clean` in `cmd/bash`: 177 -> 85**, and
`help: command not found` is **0**. `run-complete` 23 -> 20 and
`run-redir` 78 -> 77 moved with it; nothing else did.
**The remaining 85 are ONE capability, not 85 faults.** `help`'s
two-column table lists `bg disown fg jobs suspend` on the expected
side and not on ours -- **`JOB_CONTROL`** -- and *one missing entry
shifts every row after it*, so five absences diff most of the table.
**It is out of reach rather than off**: libap has **no `tcsetpgrp` and
no `tcgetpgrp` at all** -- absent, not stubbed -- so job control could
not link, and Plan 9 has no controlling-terminal foreground group to
give them meaning (`setpgid` answers ESRCH, `setsid` returns
`getpgrp()`). **`JOB_CONTROL_MISSING` is now DEFINED**: it only undefs
a switch already undef, so the binary is identical, but the file says
which kind of "off" it is -- the `NAMED_PIPES_MISSING` precedent.
*A prediction refuted by a build-system fault and then by a platform
limit taught more than a correct number would have.*

**AND THE `HFILES` GAP IS TREE-WIDE: THIRTEEN PACKAGES, NOT ONE.**
Starting from every `sys/src/external/*/config.h` and asking who
builds it -- rather than from the mkfiles, which name their sources
through `$BASHSRC`-style variables a grep cannot follow -- gives
bash, gawk, ggrep, gsed, gtar, libdwarf, libpng, libxml2, patch, perl,
readline, unace and xz, across **18 mkfiles**. Every one could be
edited with nothing rebuilt. `HFILES` added to 17 of them.
**Two traps on the way, both caught by measurement rather than
reading**:
- **`tar` was a FALSE POSITIVE of my own sweep.** Its `HFILES` is
  multi-line and lists `config.h` on a continuation line, which a grep
  anchored at `^HFILES` cannot see. It was already correct and is left
  alone.
- **FOUR packages have a LOCAL `config.h` that SHADOWS the external
  one** -- grep, sed, tar, patch, each with `-I.` ahead of the package
  include. tar's are 4512 and 113703 bytes, so they are not the same
  file at all. I had already written the external path for two of them
  before checking; reverted. *Name the file that is compiled, not the
  file with the right name* -- the `PATH_MAX` lesson in a new place.
  (`patch` nearly slipped through a second time: its `-I.` is on the
  CFLAGS **continuation** line, so a `^CFLAGS.*-I\.` grep missed it.)
Every path was verified to exist before writing, because an `HFILES`
naming a missing file makes `mk` fail outright.

**AND THE gcc SWEEP FOR `BANG_HISTORY` WAS WRONG TWICE BEFORE IT WAS
RIGHT, in two NEW ways.** The sweep itself came back **0 errors** in
the class 6c treats as fatal, across all eight `.c` files and the
generated builtins -- but getting an answer that meant anything took
three attempts:
- **`-I` CANNOT override `config.h` for bash's own sources.**
  `#include "config.h"` searches the INCLUDING FILE'S directory first,
  and bash's sources sit beside `config.h`, so pointing `-I` at a
  reverted copy changed nothing and the control reported "same" six
  times. *It had worked for `HELP_BUILTIN` only because `help.c` is
  generated into a different directory* -- the same technique, right
  once by accident. Swapping the real file in place is what works:
  `bashhist.c` **+115** lines, `flags.c` +50, `shell.c` +6, the rest
  +3.
- **A missing file counted as an error.** `reserved.c` showed 1 error
  OFF *and* ON, which is what flagged it as pre-existing rather than
  mine -- and it is neither: `reserved.def` has no `$PRODUCES`, so
  that `.c` is never generated and my sweep was compiling a file that
  does not exist. *Counting OFF beside ON is what caught it; a
  one-sided sweep would have reported a real error.*
- The other two complaints were the recorded harness artefacts
  (`builtins/builtext.h` needs an `-I` with a `builtins/`
  subdirectory, and `CONF_MACHTYPE` is a `-D` the mkfile passes).
  Supplied rather than dismissed, which is what turned 6 into 0.

**The watchdog now SAYS WHEN IT IS ARMED, and a wasted round is
why.** A run went out as `APEX__MALLOCMAX=8` -- two underscores, no
`P` -- so the watchdog never armed, bash ran to full exhaustion and
was killed exactly as it had been for weeks, and `acid` found
nothing. **That output is indistinguishable from a watchdog that
armed and never reached its limit.** The instrument's silence when
unset is correct and must stay, so the repair is one line when it
IS set: `libap: heap watchdog ARMED at N MB`. No line now means not
armed. *Same family as everything else here -- an instrument has to
say whether it is running, or a null result has two explanations.*

**THE REMAINING 38 WERE READ IN ONE COMMAND, AND SIX OF THE TEN
BIGGEST ARE NOT BUGS AT ALL.** Taking the head of each section
instead of one file at a time:
- **`run-jobs` 176 -- JOB_CONTROL.** `set: -m: invalid option`,
  `jobs/fg: command not found`. Out of reach: libap has no
  `tcsetpgrp`/`tcgetpgrp` and Plan 9 has no foreground process group.
  The file's own warning says so in its first line.
- **`run-builtins` 85 -- JOB_CONTROL**, already settled (help's table
  shifting around five absent entries).
- **`run-glob-bracket` 103 -- ONE LINE, and not ours**: `glob-bracket:
  shared objects not supported, cannot continue`. The whole 103 is
  expected output absent (`0a1,103`) because the test needs a
  LOADABLE BUILTIN. Plan 9 has no dlopen; the same wall as perl's XS
  and `enable -f`.
- **`run-dirstack` 53 -- `/etc` does not exist on 9front.** `pushd
  /etc` fails and every later line of a stack test shifts. Not ours,
  and the same shape as `/bin/p`: *a test naming a unix directory.*
- **`run-glob-test` 63 -- `locale: command not found`** plus absent
  `zh_TW.big5` and `en_US.UTF-8`. Part missing program, part missing
  locale data.
  **AND IT IS THE ONE SECTION WHOSE CONTENT CHANGES BETWEEN
  IDENTICAL RUNS** -- the count stays 63 and the words move. Not
  ours, and the cause is one line of arithmetic: `glob11.sub` tests
  **`GLOBSORT`**, creating six files `sleep 0.1` apart under the
  comment *"try to impose some kind of testable ordering"*, then
  sorting them by `+atime`/`-atime` and `+mtime`/`-mtime`.
  **Plan 9 file times are WHOLE SECONDS** -- 9P's `Dir.mtime`, and
  `dirtostat.c` sets every `tv_nsec` to 0 -- so six files written
  within half a second share one timestamp, bash's secondary sort on
  name takes over, and whether the six straddle a second boundary is
  luck. That is exactly the shape observed: one run name-sorted all
  six, the next put `mksyntax` alone in front and name-sorted the
  rest. *The test cannot pass here and cannot be stable here*, and
  the `size` pair beside it is unaffected because sizes are real.
  **The `.right` file settles the rest**: it names `mksyntax.dSYM`,
  a macOS debug bundle, so the expected output was generated on a Mac
  against that machine's directory.
- **`run-func` 70 and `run-procsub` 35 -- process substitution**,
  joining `run-histexpand`'s 35. **Four files and ~140 lines are one
  switch**, and it stays off until `/dev/fd` means something here.
- **`run-redir` 77 -- mixed, and one part IS ours**: `/etc/passwd`
  missing (not ours), and **`Bad file number` where POSIX says `Bad
  file descriptor`** -- `string/strerror.c`. It shows up in
  `run-vredir` too. **It was NOT one string: 40 of the 76 were
  wrong** -- see the strerror entry below.
- **`run-printf` 86 -- FOUR causes, three of them libap's**; see
  below. That makes it the largest genuinely ours.
*So of the ~1500 differing lines, the share that is a bug in this
tree is far smaller than the list's shape suggests -- and reading
eight sections' HEADS cost one command where reading one file at a
time had been costing a round each.*

**`printf` AGAIN, AND `%F` IS THE `%td` BUG IN A SECOND PLACE.**
`run-printf` partitions 6 / 8 / 9 / 1 / 28 (hexdump, a program this
tree has not got):
- **`%F` was missing from `vfprintf`'s dispatch table**, so it fell
  through to the arm that prints the conversion character and
  **consumes no argument** -- the value lost, and every conversion
  after it in the same format string taking the wrong one.
  `printf.tests` lines 320 and 325 are literally `printf "%F\n" 0`
  and `printf "%F\n" 4`, and this tree answered `F`. *The `%td` round
  fixed the three LENGTH MODIFIERS and did not sweep the CONVERSION
  table beside them; `A` and `a` are still absent and nothing has
  measured them.*
- **`%g` with precision 0.** C99: "if the precision is zero, it is
  taken as 1". `%+010.0g` of 123 printed `+000000123` where
  `+00001e+02` is wanted.
- **The `0` flag with a precision.** C99: for `d i o u x X`, a
  specified precision makes `0` ignored -- and **a precision of ZERO
  is specified.** The test read `precision <= 0`, conflating `%.0d`
  with no precision at all (-1), so `%+010.0d` gave `+000000123` for
  `      +123`. One character.
- **`printf "%08X" 2604292517` -> `FFFFFFFF9B3A59A5`: SOLVED by the
  probe, and libap's printf was INNOCENT.** Section 9 on the VM:

  ```
    %08X  of unsigned int  -> 9B3A59A5     <- all three widths right
    %08lX of unsigned long -> 9B3A59A5
    %08llX of ull          -> 9B3A59A5
    strtoumax("2604292517") -> FFFFFFFF9B3A59A5
    assigned to unsigned long -> 9B3A59A5
    bash takes the PRIdMAX/ll branch (p != pp)
  ```

  **`string/strtoumax.c` included `<inttypes.h>` and `<stdint.h>` and
  NOT `<stdlib.h>`**, and neither reaches a declaration of
  `strtoull` -- so the call had no prototype, returned implicit
  `int`, and every value with bit 31 set came back sign-extended.
  `printf.def`'s x/X arm does `p = pp = getuintmax()` and compares
  them, so `p != pp` sent bash down the `%08llX` branch with the
  sign-extended value. *Chain closed end to end, one line of output.*
  **FOUR mechanisms had been refuted by reading first** -- `strtoull`
  saturating (2604292517 is nowhere near a threshold), `mklong`
  building the format wrongly (bash NUL-terminates after the
  conversion character, so it really is `%08lX`), amd64's `va_arg`
  (`stdarg_arch.h` gives every argument an 8-byte slot and reads a
  4-byte type from its low half, which is right), and a missing
  prototype *in bash* (`printf.def` does include `<inttypes.h>`).
  **The fifth was one level down and reading never reached it.**
  **And the probe REPRODUCED the bug by accident before it measured
  it**: its own first version omitted `<inttypes.h>`, so `strtoumax`
  had no prototype either and it printed `FFFFFFFF9B3A59A5` *on
  glibc* -- the bash output character for character, from the same
  cause one level up. *The accident was the diagnosis and I nearly
  filed it as an instrument fault.*
- **Two conformance gaps noticed and NOT fixed**, because nothing
  measured them: `_dtoa` hands back `"Infinity"` and `"NaN"`, so
  `printf("%f", INFINITY)` prints `Infinity` where C wants `inf` --
  which is also why `%F` does not upper-case them here, since that
  would turn one wrong spelling into another. And `%a`/`%A` do not
  exist.

**AND `strftime` WAS MISSING FIFTEEN CONVERSIONS, WITH THE SAME
SILENT FAILURE MODE.** Its `default:` arm writes the conversion
character out as a literal, so `%F` printed `F`, `%r` printed `r`,
`%T` printed `T` and `%e` printed `e`. Measured in bash's
`printf3.sub`, whose `%(...)T` feeds its argument straight to
strftime: `current time: %(%F %r)T` came out `current time: F r`.
Absent: **C D e F G g h n r R s t T u V**, and `%%` worked only by
falling through `default:`. All are POSIX.1 and C99 7.23.3.5.
**And `%c` and `%x` were WRONG rather than missing**: POSIX fixes
both in the C locale (`%a %b %e %H:%M:%S %Y` and `%m/%d/%y`) and this
file had `%a %b %d ...` and `%a %b %d, %Y`. The log is what found the
second -- `%(%x %X)T` wanted `05/30/10 15:09:15` and gave
`Sun May 30, 2010 15:09:15`.
**`strftime-xcheck.c` is a HOST program** on the `tz-xcheck` pattern:
it links libap's strftime into a glibc program and sweeps 40
conversions over every day of fourteen years -- **204960 checks, 0
wrong**. The range is chosen so the ISO-week edges (a January date in
last year's week 53, a December date in next year's week 1) occur
hundreds of times rather than by luck.
**ITS FIRST VERSION WAS VACUOUS AND THE CONTROL IS WHAT SAID SO.**
`-Dstrftime=ap_strftime` in a single gcc command applies to the
CHECKER as well, so its own reference call became `ap_strftime` and
the sweep compared libap against ITSELF -- reporting `204960 checked,
0 wrong`, which is the same sentence a real run prints. A
deliberately broken ISO-week branch reported 0 wrong too; with two
compiles it reports **27**, naming `%G`, `%g` and `%G-W%V-%u` on
exactly the January dates. *Eleventh instrument fault, and the
cheapest possible catch: break the thing on purpose and see whether
the instrument notices.* The command is in the file and it is two
compiles for the same reason `ctype-xcheck` is.

**MEASURED: `run-printf` 86 -> 45, AND IT IS THE ONLY FILE THAT
MOVED.** Per-file diff against the previous run is one line, so the
three printf fixes and the fifteen strftime conversions are confirmed
with nothing else disturbed. What is left is the `%08X` probe above
and `hexdump: command not found` -- a program this tree has not got,
in `printf6.sub` alone. So `run-printf` is accounted for end to end
like `run-histexpand` before it.
**AND THE strtoumax FIX IS CONFIRMED: 45 -> 43, `FFFFFFFF9B3A59A5`
GONE.** *I predicted 44 and the arithmetic was mine, not the
library's*: the bucket counts a section's `<` AND `>` lines, so
removing a one-line `149c149` hunk removes **two**. A per-file count
here is differing LINES, not differing facts, and a `c` hunk always
costs at least two. **43 is `hexdump` and nothing else.**

**AND READING `strtoull` ON THE WAY FOUND THREE BUGS NOTHING HAD
MEASURED -- one by eye and TWO by the sweep that was written to
confirm the first.** None of them is the `%08X` question; they were
found looking for it, and saying so matters, because a fix found
beside a bug is not a fix for it.
- **`strtoull.c` opened `#define UVLONG_MAX (1LL<<63)`**, which is
  not the largest `unsigned long long` -- while `strtoul.c` in the
  same directory uses `ULONG_MAX`. *The library held a correct
  version of the thing it got wrong, for the fourth time* (after
  `mktemp`/`__randname`, `getcwd`/`get_current_dir_name`, and
  `vfscanf` knowing `t`/`j`/`z` while `vfprintf` did not).
  **And my first comment on it was wrong in a way the control
  caught.** I wrote that the overflow threshold was "halved" and
  predicted a band of false ERANGEs. The literal is **signed**:
  `1LL<<63` is LLONG_MIN, `UVLONG_MAX/base` is a signed division, and
  the negative quotient converts to an unsigned value just under
  ULLONG_MAX -- so the threshold was effectively **disabled**, not
  halved, and detection fell back on a `nn < n` wrap test that misses
  a multi-wrap. `strtoull("0777777777777777777777", 16)` returned
  8608480567731124087 and no error. *An expression read rather than
  evaluated is a guess*, and restoring the exact original line is
  what said so: 28 wrong against 0.
- **`strtoll(LLONG_MIN)` answered ERANGE** for a value that is
  exactly representable -- its magnitude is one MORE than LLONG_MAX
  and the loop used one limit for both signs. Now accumulated
  unsigned against a sign-dependent cutoff.
- **`strtoX("0x")` with no hex digit reported NO CONVERSION.** C says
  the subject sequence is the longest *initial* subsequence of the
  expected form, so `strtol("0x", &e, 16)` converts the `0` and
  leaves `e` on the `x`; this consumed the `0x` and then set
  `endptr = nptr`, so a caller testing `endptr == nptr` rejected a
  valid zero. Fixed in **all four** files -- the defect is one shape
  copied four times, and leaving two of them wrong would be worse
  than either state.
**`strtoint-xcheck.c` is the host cross-check**, and it carries the
`strftime-xcheck` lesson forward: the rename must not reach the
checker, and here even `-D` cannot do it (libap's prototypes take
`char *` where glibc's take `const char *`, so the renamed
declaration conflicts) -- so it renames the SOURCE with `sed` into a
temporary and compiles that. 1419 checks, **0 wrong**, 38 before.
**`strtol`/`strtoul` are deliberately NOT swept**: kencc's `long` is
32-bit and the host's is 64, so the two disagree about the right
answer by construction. *A cross-check needs both sides to agree on
what is being computed* -- they get the `0x` fix and their signed-min
arithmetic is recorded, unmeasured, rather than rewritten blind.

**AND THE SWEEP THAT FOLLOWED IT FOUND ONE MORE, THEN CAME BACK
CLEAN.** A missing declaration is never alone, so
`sys/lib/tests/apdecl-sweep.py` asks every `.c` under `lib/ap` whether
it calls a function with a NON-`int` return type that no header in its
include closure declares. It found **`errno/err.c` and
`errno/warn.c`** calling `strerror` with no `<string.h>`, handing a
truncated `char *` straight to `%s` -- *in the two functions a program
reaches once something has already gone wrong*, so the failure lands
on top of another one. 0 hits now.
**Three versions of that sweep reported 491, 79 and 2, and the first
two were almost all NOISE.** The cuts that mattered: strip comments
and string literals (the first version counted `rendezvous()` named in
a COMMENT as a call); limit the declaring headers to the standard set
(the APE include directory also holds `sqlite3ext.h`, `chicken.h`,
`zlib.h`, `libdwarf.h`); and **put `lib/ap/include` on the search
path, which is the mkfiles' own `-I../include`** -- without it every
file under `math/` and `complex/` reads as undeclared, because
`libm.h` lives there and is what includes `<math.h>`. *An instrument
whose include path is not the BUILD's include path is measuring a
different program.* It is a lower bound by construction and says so in
its own header, like the all-char struct sweep.

**`strerror` WAS WRONG IN 40 OF 76 ENTRIES, AND TWO OF THEM NAMED
THE WRONG ERROR.** `run-redir`'s `Bad file number` was the way in,
and reading that one entry would have fixed that one entry. Asking
the WHOLE table against glibc found 40.
**The pair that matters is EACCES and EPERM.** The table said
`EACCES "Access denied"` and `EPERM "Permission denied"` -- and
`Permission denied` is what every other system prints for **EACCES**.
So the one message a reader is most likely to recognise named the
wrong errno: a program failing with EPERM reported EACCES's text, and
anything matching on it -- a test, a log, a person -- drew the
opposite conclusion. *A wrong message is a bug in one line; a message
that is another error's correct message is a bug in the reader.* This
tree already spent a round on `_errno.c` mapping Plan 9's "permission
denied" to EPERM where POSIX wants EACCES, and the two errors have
now been confused at both ends of the same path.
The other 38 were merely terse -- `Too big`, `Try again`,
`No buffers`, `Shut down`. **Nothing in POSIX fixes the wording**, so
this is not conformance: it is that the tree exists to run GNU
software, whose suites compare against the text glibc produces.
`EDOM`/`ERANGE` are 1000 and 1001, outside the table, spelled in
`strerror()`'s own arms -- they had the same defect and are fixed
with it.
**Generated rather than transcribed**, which is the part worth
keeping: the mapping came from parsing `errno.h` for the names and
asking glibc for each one, so no entry was typed and none can be off
by a row. **Every line now carries its name**, because a table
indexed by errno with unnamed rows is exactly how an entry drifts.
**`strerror-xcheck.py` is the instrument and is checked in.** It
cannot be a C cross-check like the others, and the reason is the
whole difficulty: **APE's errno NUMBERS are its own** -- EBADF is 4
here and 9 on glibc -- so comparing by index would be nonsense
dressed as a measurement, and only the NAMES line up. **Both controls
fire**: reverting one word reports 1 and names `EBADF`; inserting one
row reports **68**, which is the drift case it exists to catch.
`EGREG` is reported UNCHECKABLE rather than passed over -- it is
APE's own (`_errno.c` maps Plan 9's "ken has left the building" to
it), glibc has no such error, and its text is left alone. It reads
`Unknown error`, which is also what the fallback returns for an errno
out of range, so the two are indistinguishable from outside.
*Recorded rather than changed: a new wording would be invented and
nothing has measured it.*
**MEASURED, AND BOTH NUMBERS WERE TOO LOW: `run-redir` 77 -> 63
(predicted ~70) and `run-vredir` 11 -> 5 (predicted ~9).** And the
refutation condition fired usefully: **`run-errors` 8 -> 4 moved too**
-- the same two `Bad file number` lines, in a third file I had never
opened. *Three files, one fix, nothing up.*
**Why the predictions were low is the same mistake in both**: I sized
them from the one section head I had read rather than counting the
string across the whole log. The sweep that settles it takes one
command and I only ran it AFTER the run -- `Access denied` **7 -> 0**,
`Bad file number` **9 -> 0**, and `Permission denied` **10 -> 0**
while `Operation not permitted` went 1 -> 4, which is the EPERM/EACCES
swap unwinding exactly as read. *Count the string in the corpus, not
in the paragraph you happened to read.*
**TWO occurrences of `No such system call` SURVIVE, and they are not
the table.** They are `ln: failed to create symbolic link` and
`mkfifo: cannot create fifo` -- ENOSYS from `symlink()` and
`mkfifo()`, printed by **coreutils binaries that were not relinked**.
APE is statically linked, so every program carries its own copy of
`sys_errlist[]`, and `mk install` rebuilds `libap.a` without relinking
programs already built against it. bash was rebuilt and changed; `ln`
and `mkfifo` were not and did not. *That is the rule already in this
file -- a libap fix can sit unused for rounds -- showing up as two
lines rather than as a silence*, and `mk distclean` before the next
`mk install` is what would finish it.
**IT DID, AND THE WHOLE REBUILD MOVED NOTHING ELSE.** After a full
`mk distclean` plus `mk install`, both lines read
`Function not implemented` -- glibc's ENOSYS wording, from the new
table -- at the same two line numbers in the same two sections.
*The prediction named the exact two lines and the exact two files,
and nothing else in 1601 lines changed*, which is as clean a
confirmation of the static-linking reading as this corpus can give.
**And that is the more valuable half of the run.** `REAL 38 /
WARNONLY 1 / PASS 47` are identical to the previous run, and the
per-file diff is **one line** -- `run-trap` 14 -> 16, the xtrace hunk
that regroups between identical runs and has already gone back and
forth twice. So the first relink of the ENTIRE tree since
`ctype`/`getcwd`/`umask`/`mktemp`/`printf`/`strftime`/`strtoull`/
`strtoumax`/`strerror` **broke nothing anywhere in bash's suite**.
*A green run after a distclean is the only control that covers
programs no test names*, and until now every one of those fixes had
only ever been measured through a binary that happened to be
rebuilt. The errno sweep closes with it: `Access denied`,
`Bad file number`, `Too big`, `Try again`, `No buffers` and
`Shut down` are **0 in the corpus**, `Operation not permitted` holds
at 4.
**And it left one new item, which is the EGREG arm becoming
visible.** `run-read`'s `read7.sub` prints
`redirection error: cannot duplicate fd: Unknown error`, and the
next line is `line 60: 5174752: Unknown error` -- a garbage fd number
downstream of the failed dup. `Unknown error` is the table's text for
**EGREG**, which `fcntl.c`'s `F_DUPFD` sets for a buffered
descriptor. *An errno naming the wrong category, printed to a user* --
the commonest bug shape here -- and it is only legible now because
the rest of the table stopped saying `Unknown error` by accident.
Recorded, not fixed: `run-read`'s other 27 lines are `/dev/tty`
(absent on Plan 9) and the `mkfifo` stub.

**FIXED THE NEXT ROUND, AND IT WAS MUCH WIDER THAN THREE LOG LINES:
`dup()` AND `dup2()` ARE EACH ONE LINE OF `fcntl(.., F_DUPFD, ..)`,
so all three refused.** A descriptor becomes buffered the first time
anything `select()`s it -- libap's select forks a copy process rather
than polling -- so **any program with an event loop had lost the
ability to dup the descriptors it was watching**, select() being how
an event loop works and dup being how a shell redirects. *Three lines
in one test file, and the reachable surface is most interactive
programs.* `read7.sub` line 60 is `read -e -t .001 a <<<abcde`,
counted rather than guessed: `-e` is readline, which select()s fd 0;
the here-string is a redirection of fd 0, so bash saves the original
with a dup first.
**The arm was protecting against something real, which is why the fix
is two lines and not a deletion.** `Muxbuf` is keyed on the descriptor
NUMBER (`_buf.c`'s `b->fd`) and `Fdinfo` holds a `buf` POINTER beside
the flag, so copying `fi->flags` wholesale onto a new number makes
`_readbuf` find `b->fd != fd` and answer **EBADF on every read** -- a
dup that succeeds and hands back something broken, which is worse
than the refusal. **But those two bits are facts about a descriptor
number in one process image, not about the open file** -- the
invariant `_fdinfo.c` already states for `FD_BUFFEREDX`, and
`sfdinit` already scrubs this exact pair on exec in exactly these two
lines. Copied whole, pointer included; `FD_ISTTY` and `FD_ISREG` are
facts about the FILE and carry over unchanged. *The second line is
the one that would have been forgotten.*
**The limit is recorded rather than hidden**: bytes the copy process
has already drained into the Muxbuf are not visible through the new
descriptor, so the two do not share a read position the way POSIX
says two dups of one open file description do. There is nowhere to
put them, a reader of the dup was *already* competing with the copy
process (the measured keystroke-thief hazard), and the dominant use
of dup -- a shell saving a descriptor to restore later -- never reads
it.
**`_dupmark()` is the marker** (sixth use of the idiom), and
**both controls fire on the host**: replicating the old refusal gives
**4** failures, replicating the HALF-FIX -- dup succeeds, reads give
EBADF -- gives **exactly 1**, section 5, which the header says is
there for it. *A control that fires on one section is better evidence
than one that fires on four*: it says the section is not decorative.
0 failures on glibc.
**CONFIRMED ON THE VM: `_dupmark = 1`, all seven sections PASS, 0
failures** -- and the two lines that carry it are section 4b,
`fcntl(buffered, F_DUPFD, 25)` answering **>= 25** where it used to
refuse, and section 5, `read(dup) -> -1, errno 3` rather than EBADF.
*Errno 3 is EWOULDBLOCK, which is the test's own non-blocking reads
and not a failure*: the bytes are in the copy process, which is the
limit the header records rather than a defect. Section 6 then reads
all eight from the original, so the dup did not cost the original
its data.
**And `dupbuf-test` HUNG on its first host run, in the way its own
header had just finished describing** -- section 5 drains the pipe
through the dup and section 6 then blocks reading the original.
*Writing the hazard down one paragraph above the bug did not prevent
the bug*, which is the `abort()`-allocates lesson again. Every read is
non-blocking now, set once at pipe creation so it is true by
construction rather than by argument, and stdout is unbuffered so a
future hang names its section -- the kill took the buffered output
with it and left nothing at all to read. *Twelfth instrument fault.*

**AND THE REST OF THE REAL LIST WAS SURVEYED IN ONE COMMAND, by
counting each cause across the whole corpus rather than reading
files.** 1094 differing lines over 38 files. **The share that is a
bug in this tree is small, and two of the four are new:**
- **`. ` and `..` missing from a glob -- OURS, and now measured in a
  SECOND suite.** `run-extglob` wants `. .. .a .foo` and gets
  `.a .foo`. This is Tcl's `filename-14.9` exactly -- **Plan 9
  directories contain neither entry** -- recorded there as wanting
  its own round because synthesising them in `readdir()` changes
  what every directory read in every program sees. *One measurement
  made it a deferred curiosity; a second, independent one makes it
  the biggest thing here that is ours.*
  **DONE, NOT YET MEASURED ON THE VM. The sweep came before the code**,
  because the risk is not whether POSIX wants the entries -- it does --
  but whether anything here walks a directory WITHOUT skipping them,
  since such a caller recurses for ever. All six `readdir()` callers in
  libap were read: `rmdir.c` (strcmp), `fts.c` (`ISDOT` unless
  `FTS_SEEDOT`), `nftw.c` (open-coded ISDOT) and `seekdir.c` (replays
  readdir) are safe; `scandir.c` does not skip and is **correct** not
  to, since scandir reports everything and the caller's filter decides.
  **Two of them were WRITTEN EXPECTING these entries**, which is the
  strongest evidence available that their absence is the anomaly:
  `rmdir.c` spends a strcmp per entry skipping names Plan 9 never
  produced, and musl's `glob` does not skip them at all -- it relies on
  `fnmatch` with `FNM_PERIOD`, so `*` excludes them and `.*` matches
  them. **That is exactly what both failing tests ask for, so glob
  needs no change and starts answering correctly on its own.**
  **`d_ino` is real, not 0**: `.` is `fstat`ed from the stream's own
  descriptor and `..` stat'ed through `fd2path` + `/..`, two stats per
  directory TRAVERSAL rather than per entry. Zero would be the zipfs
  `st_rdev` trap -- *a field that is always zero reads as information
  and is not* -- and `find`'s loop detection, the classic `getcwd` and
  `du`'s hard-link check all read it. At the root `/..` is `/` here as
  on a unix, so no special case; if the parent cannot be stat'ed the
  directory's own identity is used rather than a zero.
  **NO NEW FIELD, so `sizeof(DIR)` does not move and this is NOT an
  ABI change.** `dd_seek` is already the stream's entry counter and
  the synthetic entries genuinely ARE entries 0 and 1, so the counter
  describing them is the same fact rather than a second one -- and
  `telldir`/`seekdir` come right for nothing, since seekdir rewinds and
  replays `readdir()`. **A full rebuild is still needed, for the OTHER
  reason**: a libap fix does not reach binaries already linked.
  **`_dotdirmark()` is the marker** (seventh use). `dotdir-test.c` is
  0 failures on glibc, and the host control -- an `LD_PRELOAD` readdir
  dropping both entries -- gives **5**, naming sections 3, 4a, 4b, 4c
  and 6a, with section 5 correctly unmoved.
  **But the host control did NOT cover section 7, and that is written
  in the file rather than left to be assumed**: glibc's `glob` does not
  route through an interposed `readdir`, so section 7's host PASS
  measures glibc and says nothing about the chain. *On Plan 9 it is the
  only section that asks the question the two suites actually compare*
  -- `glob("*")` must not match them and `glob(".*")` must. Section 6b
  likewise never crossed the synthetic/real boundary on the host,
  because glibc put a real entry at position 0.
  **`fts.c:600` is a pre-existing oddity found on the way and NOT
  touched**: `nlinks = fts_nlink - 2` assumes a directory's link count
  includes `.` and `..`, while `dirtostat.c` sets `st_nlink = 1`
  always -- so that arithmetic has been giving -1 here all along.
  Recorded, unmeasured, and independent of this change.
  **MEASURED AFTER A FULL `mk distclean`: `run-extglob` 20 -> 0, it
  PASSES**, and all twenty lines were the same thing -- ten `c` hunks,
  each `.a .foo` against `. .. .a .foo`. **`run-glob-test` 63 -> 61 is
  a SECOND confirmation and was not predicted**: `.a .aa .b .bb`
  against `. .. .a .aa .b .bb`, in a file whose other 61 lines are the
  GLOBSORT/locale problems that cannot pass here. **Zero `. ..`
  expectations remain anywhere in the corpus.**
  **AND THE SAFETY EVIDENCE IS THE BETTER HALF.** A change that
  touches every directory read in every program, measured across 86
  test files, added **SEVEN lines corpus-wide and not one of them is
  a directory entry**: three are run-to-run noise (the oscillating
  xtrace hunk, and two `jobs*.sub` lines that carry a pid), four are
  the run's own environment. *The sweep of libap's six readdir callers
  predicted exactly this, and "nothing arrived" is the only form the
  confirmation could take* -- a recursing walker would have hung the
  suite, and a leaking entry would be a new line somewhere.
- **`[=x=]` and `[.x.]` answer `Unknown collating element`**, 9 lines
  in `run-cond`. `ap/regex/regcomp.c` is musl's TRE and the line is
  **musl's own** -- `/* collating symbols and equivalence classes are
  not supported */` -- so this is a vendored gap, not an APExp
  regression. **But the C-locale answer is mechanical**: every
  equivalence class is a singleton there, so `[[=d=]]` IS `[d]`.
  Accepting the single-character form and keeping `REG_ECOLLATE` for
  multi-character ones is conformance rather than invention, and
  small.
  **DONE, and the justification is sharper than "the C locale" alone:
  there is no collation table anywhere in TRE** -- the engine compares
  encoded values, as its own `XXX - Should use collation order instead
  of encoding values` comment says -- so the C locale is what every
  comparison already implements and no second reading is available.
  A collating symbol naming one character IS that character in any
  locale; a multi-character element still answers ECOLLATE, because
  this locale has none to name. `parse_collating()` is a helper rather
  than inline code because the construct is legal as a RANGE ENDPOINT
  too, and the two call sites would otherwise disagree about what a
  bracket may hold.
  **THE CROSS-CHECK CORRECTED THE FIX TWICE, and reading alone would
  have shipped both** -- each agreed with glibc everywhere else:
  - **`[[=d=]-z]` was accepted and glibc answers `REG_ERANGE`.** An
    equivalence class names a SET and so has no position in the
    order; a collating symbol names one element and can bound a
    range. The helper now reports which it parsed, and both call
    sites refuse the equivalence class. *The corpus asks all four
    combinations -- each construct on each side -- for the reason
    `$@` was asked beside `$*`.*
  - **`[[.d]]` answered ECOLLATE where glibc says `REG_EBRACK`.** An
    unterminated `[.` is an unclosed bracket expression; only a
    TERMINATED one naming something unsupported is ECOLLATE. The
    helper scans for the closing delimiter FIRST so the two stay
    distinguishable.
  **`regcoll-xcheck.c`: 1906 checks, 0 wrong; the old blanket refusal
  replicated beside it gives 1652** -- and its section 3 (ordinary
  brackets, no collation) stays at **0 in both runs**, which is the
  half that matters, since a control that moved with the collation
  code would not be a control at all.
  **MEASURED: `run-cond` 18 -> 0, it PASSES**, and the `ok 1`..`ok 9`
  lines on the expected side now match -- so the fix produces correct
  MATCHING, not merely a non-error. `[[.d.][.D.]]o.` answering
  `ok 7 -- d` is the chain end to end.
  ***And my "drop by 9" prediction was wrong by arithmetic I had
  already recorded once***: 9 is the count of lines mentioning
  `collating element`, and the bucket counts a section's `<` AND `>`
  lines, so two `c` hunks of 5 and 4 cost **18**. *A `c` hunk always
  costs at least two* -- written down after `run-printf` predicted 44
  and gave 43, and repeated here anyway.
- **`set -r` -- `RESTRICTED_SHELL`, the same switch shape a sixth
  time.** `run-rsh` 33. Inert unless invoked as `rbash` or with `-r`,
  so unlike `BANG_HISTORY` it costs nothing to turn on.
  **TURNED ON, gcc-swept, NOT YET MEASURED ON THE VM.** Nothing was
  missing from the build, as with READLINE, HELP_BUILTIN and
  BANG_HISTORY before it: the switch gates 55 sites across eight `.c`
  files and nine `.def` files, every one already in OFILES or
  DEFFILES, so no mkfile change. **0 errors** in the class 6c treats
  as fatal, across the six `.c` files and the nine generated
  builtins. **And the control is the preprocessed line count, not the
  error count** -- `shell.c` **+93**, `flags.c` +20, `variables.c`
  +29, `execute_cmd.c` +24, `builtins/common.c` +10, `redir.c` +8 --
  because 0 errors with the switch off is the same number and says
  nothing. The real `config.h` is swapped in place to get that:
  *`-I` cannot override `config.h` for bash's own sources*, which is
  already recorded here and is still true.
  **`builtext.h` had to be generated first** or `execute_cmd.c` and
  `variables.c` report a fatal missing-header "error" and the sweep
  reads as two real failures. Same harness artefact as last time.
  **MEASURED: `run-rsh` 33 -> 1, and THREE files moved that were not
  predicted** -- `run-shopt` 19 -> 16 (`restricted_shell` now in the
  `shopt` table), `run-invocation` 9 -> 6 (`--restricted` in the long
  options) and `run-complete` 19 -> 18 (`restricted_shell` in the
  completion list). Each attributed by diffing the section's own lines
  rather than inferred: `restricted` across the corpus goes **17 -> 0**.
  **The one line left in `run-rsh` is `ln: failed to create hard link
  to 'sh': Too many links`** -- the test makes `rbash` with a hard
  link, and Plan 9 has none. *That is the `link()`/`LINK_MAX 1` item
  examined and deliberately NOT filed as a bug last round, and the
  reading holds*: the errno is internally consistent, the capability
  is simply absent, and the test cannot pass here.

**THE WHOLE ROUND MEASURED, AND THE F_DUPFD FIX CAME WITH IT.**
`REAL 38 -> 37`, `PASS 47 -> 48`, 1094 -> 1033 differing lines,
**nothing rose**. Everything is attributed:
RESTRICTED_SHELL 39 lines, collating 18 (`run-cond` passes),
**F_DUPFD 2** -- and `run-trap` 16 -> 14, the xtrace hunk oscillating
for the fourth time, which is not a change.
**`read7.sub`'s two lines are gone exactly**: `cannot duplicate fd:
Unknown error` and the garbage-fd line below it, so the dup fix is
confirmed where it was found. **The corpus count is what made that
readable** -- `cannot duplicate fd` went 3 -> 2 and `Unknown error`
2 -> 0, and the two survivors were always different cases:
`redir5.sub`'s is `Bad file descriptor` and unchanged, and
`vredir6.sub`'s is on the `>` side, the `ulimit -n 6` line the suite
*wants*. *Counting the string beside reading the section is what
separated a surviving instance of the bug from two things that were
never it.*

**AND THE NEXT ROUND, AFTER A FULL `mk distclean`: `REAL 37 -> 36`,
`PASS 48 -> 49`, 1033 -> 1015 lines.** `run-extglob` and
`run-glob-test` are the readdir fix (above). Two others moved and
**neither is the tree**:
- **`run-nameref` 1 -> 5 ROSE, and it is the RUN'S OWN ENVIRONMENT.**
  The test prints `declare -x` for everything exported, and the new
  run carries `vts`, `vtsdebug`, `vtslog` and `vtspid` beside the
  `vgasize` the old one had -- so this suite was run from inside a
  **vts session** where the previous one was not. `session.c`'s
  `putenv("vts"...)` and `vts-bash`'s `$vtsdebug` are where they come
  from. *A test that compares the whole environment measures the
  environment it was run in*, which joins the harness's own
  `fconfigure`, the kernel's fd warnings and the `awk` that blocked:
  **the fifth time something outside the tree has shown up inside a
  measurement of it.** Nothing to fix, and nothing to read as a
  regression -- but a run from a plain `apexp-sh` would answer 1.
- **`run-redir` 63 -> 61 is UNEXPLAINED and recorded as such.** One
  hunk went: `exec 6<>$TMPDIR/bash-c` at `redir.tests:83` used to
  answer `6: Bad file descriptor` and now works. Two things changed
  in this build -- the readdir entries and the first full relink of
  every binary in the tree -- and *`exec N<>file` is a dup onto a
  chosen descriptor, which is F_DUPFD's path*, but that fix was
  already in the previous run's bash and that run still failed here.
  **So the vehicle is not identified and guessing one would be the
  third story in a row.** Cheap refutation: if it comes back next
  run with nothing touching it, it is flaky like `run-trap`'s hunk.
- `run-trap` 14 -> 16 is that hunk oscillating for the **fifth** time.
**AND `dotdir-test` IS NOW RUN ON THE VM: `_dotdirmark = 1`, every
section PASS, 0 failures -- INCLUDING THE TWO THE HOST COULD NOT
REACH.**
- **Section 6b answered in the exact shape predicted**, and the
  output says so rather than leaving it to be argued: it prints
  **`seekdir(2) -> f0`**. On the host that line read `seekdir(0)`,
  because glibc put a real entry at position 0 and the seek never
  crossed the synthetic/real boundary; here the first real entry is
  at **2**, so `telldir`/`seekdir` are measured ACROSS the boundary
  for the first time. *The prediction was written into the file
  before the run and the number in the output is what confirms it.*
- **Section 7 is the chain end to end, and only here does it mean
  anything**: `glob("*")` matched 5 with **0** dot entries,
  `glob(".*")` matched 3 with **2**. glibc's glob does not route
  through an interposed `readdir`, so its host PASS measured glibc;
  libap's glob calls libap's readdir directly, so this one measures
  the thing the two suites compare. *Four independent confirmations
  now -- `run-extglob`, `run-glob-test`, and both halves of this.*
- **Section 4 passed for the right reason, which is the half a
  name-only fix would have failed**: `. d_ino 37897` against
  `stat(dotdirtest.d) 37897` and `.. d_ino 52201` against
  `stat(.) 52201`, both `d_type 4`. The inodes are real and they are
  the right two files.
**The readdir item is CLOSED**: confirmed from outside in two suite
files and from inside in all seven sections.
- **`recho: command not found`, 9 lines, identical in both runs.**
  `bash-runtests` guarantees the four helpers are built, and most
  files find them -- `run-assoc`, `run-ifs` and `run-new-exp` do not.
  A precondition question about the harness, like the `../bash`
  check, and stable rather than flaky.
  **FOUND AND FIXED, AND IT WAS HIDING TESTS RATHER THAN FAILING
  THEM.** `run-all` line 29 is `PATH=.:$PATH`, under upstream's own
  comment *"just to get recho/zecho/printenv if not run via `make
  tests'"* -- while the real route, `Makefile.in:682`, is
  `PATH=$(BUILD_DIR)/tests:$$PATH`, an **ABSOLUTE** path. With `.`
  the helpers are found only while the cwd is still `tests/`, so
  **every test that `cd`s loses them**. *Fourth silently-failing
  precondition in this harness, and the same family as `THIS_SH`:
  upstream's standalone default is a degraded fallback and APExp
  takes the standalone route.*
  **What named the cause was one file disagreeing with itself**:
  `assoc.tests` calls recho at line 63 and it WORKS, then at line 132
  and it does not -- and `cd ${TMPDIR:=/tmp}` sits between them, at
  line 128. *A difference inside one file beats a difference between
  files, because everything else is held constant for free.*
  **They are HIDDEN rather than failed, which is why this is worth a
  round**: recho's whole job is to print its arguments visibly, so a
  missing recho means those assertions are not made at all. `ifs1.sub`
  cds into `$TMPDIR` to test **IFS field splitting with glob
  characters in IFS**; `assoc.tests:128` does the same to test
  associative-array index expansion **against a file literally named
  `[sfiri]`** -- a bracket expression as a filename, next door to the
  readdir and regex-bracket work of the last two rounds.
  **Predict**: `run-ifs` 4 -> 0 (it is recho and nothing else),
  `run-assoc` 6 -> 2 (the `wait: usage` hunk is a different bug and
  stays), `run-new-exp` 34 -> ~28. **And the interesting outcome is
  the other one**: if any of them comes back with DIFFERENT content
  rather than going away, that is a real bug *newly measured* -- the
  rule about a rising count after new tests become runnable -- and
  `assoc.tests:132` is the one to read first.
  The fix is `PATH` set to this directory absolutely, before
  `run-all`; `^` is guarded against an empty `$PATH`, since a cross
  product with the empty list is the EMPTY LIST rather than the other
  operand.
**NOT ours, with the arithmetic**: `JOB_CONTROL` **148** lines (no
`tcsetpgrp`/`tcgetpgrp`, no foreground process group), process
substitution (`/dev/fd` absent and `/fd` has the wrong semantics for
a child), `hexdump` 14 and `locale` 1 (programs this tree has not
got), `/etc` 17, `glob-bracket` 103 (loadable builtin, no dlopen),
`/bin/p` 3 (a name collision), `run-glob-test` 63 (whole-second
mtimes, and unstable by construction).
**One I nearly filed as a bug and did not**: `link()` returns
**EMLINK**, which reads like the stub-answering-the-wrong-thing
family -- but `sys/limits.h` declares **`LINK_MAX 1`**, and POSIX
says EMLINK is exactly what a link past LINK_MAX gives. *It is
internally consistent and the file's own comment says so.* Checking
the constant before writing the entry is what separated it from
`mkfifo`'s `errno = 0`.

**One PROBE, not a claim**: `run-rsh`'s `date` line prints the zone
as **`CES`**, and Central European Summer Time is `CEST`. It is not
a parser truncation -- `tzone.c`'s `Maxname` is 16 -- so it is either
what the machine's `/env/timezone` holds or what `$TZ` says, and
`cat /env/timezone; echo $TZ` answers it in one command. The line is
a timestamp and differs between runs anyway, so it costs nothing to
leave until something else needs that file.
**ANSWERED, AND IT IS NOT OURS: the FILE says `CES`.**
`/env/timezone`'s first line is literally
**`CET 3600 CES 7200`**, followed by its transition times, and
`$TZ` is empty -- so the chain is `$TZ` unset -> `tzone.c` falls back
to `/env/timezone` -> the file names the summer zone `CES` -> `%Z`
prints `CES`. **Every link is behaving correctly**, including ours:
`Maxname` is 16 and the copy guards at 15, so a four-character `CEST`
would fit with room to spare -- *the parser was never truncating, and
the measurement is what turned that from a reading into a fact.*
Nothing in APExp writes or ships timezone data either (one `git
ls-files` hit, and it is diffutils' own test fixture), so this is the
machine's `/adm/timezone` and a fix belongs there rather than here.
*The probe cost one command and closed an item that three rounds of
reading could not have.*

**IS BASH DONE? NOT QUITE, AND THE HONEST ANSWER IS A LIST.** Every
section was classified in one sweep of the heads -- 36 files, 1015
lines. **~950 of them are settled**, almost all platform limits:
JOB_CONTROL (`run-jobs` 176, `run-builtins` 85, `run-complete` 18,
`run-shopt` 16, `run-trap` 16, `run-errors` 4 -- `bg: command not
found` against `bg: no job control` is that switch exactly), process
substitution (`run-func` 70, `run-procsub` 35, `run-histexpand` 35,
`run-new-exp` 34, `run-quotearray` 27 -- `<(` inside `[[ ]]`),
no dlopen (`run-glob-bracket` 103), `/etc` absent (`run-dirstack` 53,
part of `run-coproc`), whole-second mtimes (`run-glob-test` 61),
`hexdump` (`run-printf` 43), `/dev/tty` and `mkfifo` (`run-read` 27),
symlinks (`run-globstar` 5), `/bin/p` (`run-comsub2` 19), a hard link
(`run-rsh` 1), `ulimit -n 6` on the expected side (`run-vredir` 5),
and the run's own environment (`run-nameref` 5).
**What is NOT yet attributed is about SEVEN files and ~65 lines**, and
that is the list the next bash round should start from rather than
re-deriving:
- **`run-invocation` 6 -- almost certainly the switch shape a SEVENTH
  time.** The expected side carries `--dump-po-strings` and
  `--dump-strings`, which `shell.c:260` gates on
  **`TRANSLATABLE_STRINGS`**, and `config.h:1425` has it `#undef`.
  32 sites, and `-I$BASHSRC/lib/intl` is already on CFLAGS. *Needs a
  decision rather than a sweep-in*, like BANG_HISTORY: it changes what
  `$"..."` means.
- **`run-intl` 5 -- locale, and possibly ours.** The test wants
  `1,0000` and we answer `1.0000`, i.e. **`LC_NUMERIC` is not taking
  effect**, plus `Passed all 1318 Unicode tests` against 1770.
- **`run-posixpat` 15 -- every line is `>`**, i.e. expected output
  ABSENT, which is the shape a missing capability makes. Unread.
- **`run-nquote` 16, `run-lastpipe` 14, `run-heredoc` 8** -- unread.
  `run-heredoc`'s `1: no<TAB>OK` against `1: OK` is a field
  difference rather than a missing feature.
- **`run-attr` 2 -- `declare -rx p="1"` against `declare -r p="1"`.**
  A variable marked EXPORTED that should not be; small, specific and
  plausibly ours.
- **`wait: usage: wait [pid ...]`** in `run-assoc` and `run-array`:
  bash's own `wait` refusing its arguments, in two files.
*So the remaining genuinely-ours surface in bash is small and named,
and two of the seven have shapes this campaign has repeatedly found
to be real and cheap.* **The big blocks will not move without
`tcsetpgrp`, `/dev/fd` or `dlopen`**, none of which Plan 9 has.

**Smaller open items**: `strtol`/`strtoul` have the same
one-limit-for-both-signs shape as `strtoll` had, so `strtol(LONG_MIN)`
is likely ERANGE too -- unmeasurable by cross-check for the reason
above, and untouched for that reason. `unlink()` of a directory reports `EPLAN9`
where POSIX allows EPERM or EISDIR. *(The `strerror(EBADF)` item is
CLOSED -- it was 40 entries, not one; see above.)*

**Open hazards recorded but not measured**: the lost wakeup in
`select()`'s rendezvous (a copy process reaching EOF before the parent
sets `selwait`). *(The `_closebuf` "kills ten times without waiting"
entry was withdrawn: the loop IS the wait -- it ends when `kill` fails
-- and misreading it is what left `_sock_killlisten` without one.)* *(The third -- a closed `socket -server`
leaving its `listenproc` for ever -- was measured and fixed; see above.
It had sat here unmeasured while it silently decided the result of two
tests.)*
