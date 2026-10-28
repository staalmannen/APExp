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

**The convention**: print `PASS`/`FAIL` per case, exit with the number of
failures, and open with a comment saying which bug the test came from and
what it cost. **Anything testing a language or library rule should be
correct on gcc too** — checking a new test against gcc first is how you
find out whether the test or the tree is wrong, and it has caught both.

**The history of every instrument below — what it came from, what it
cost, and which of them turned out to be the visible fault — is in
`docs/notes/instruments.md`.** Read that before CHANGING one; this list
is for PICKING one.

**Five kinds, and the difference matters.** A *test* asserts a rule and
exits with a failure count. A *probe* asks a question nobody has promised
an answer to: report what it prints, do not assert it. A *sweep* asks one
question of the whole tree and either gates or does not, and its own
header says which. A *model* transcribes a function that cannot be
compiled here and checks the arithmetic on the host. A *cross-check*
links the unit under test into a host program beside the reference
implementation — the cheapest instrument in this tree, and the one to
reach for whenever the thing being tested is a pure function of its
input.

**kencc** — `bool-test`, `bitfield-test`, `compound-assign-test`,
`compound-literal-test`, `designated-init-test`, `charptr-test`,
`rol64-test`, `u64float-test`, `initzero-test` (a compound literal must
zero the members its list omits — muon's crash), `longconst-test` (an
`L` is a floor on a constant's type, not a ceiling), `switchcase-test`
(a wide case LABEL is truncated, not discarded), `structalign-test`
(`-J`, conforming layout, **three runs** — gcc, then `pcc -9 -DPLAN9`
which must FAIL, then plain `pcc` which must pass), `bitinit-test` (a
static initialiser must write the bit-field GROUP's bytes, not the
container's).
**`truefalse-test.c` is the one NATIVE test here** — `6c`/`6l`, not
`pcc` — and has to be: APE's `<stdbool.h>` `#define`s `true`/`false`, so
an APE build never reaches kencc's own C23 keywords.

**libap** — `locale-test`, `sigset-test`, `posix-spawn-test`,
`limits-test`, `format-arg-test`, `unget-pipe-test`, `isatty-test`,
`execve-env-test`, `tz-test`, `rename-test`, `listenleak-test`,
`asyncconnect-test`, `nbread-test`, `epipe-test`, `ldexp-test`,
`binfloat-test`, `rawmode-test`, `execfail-test`, `append-test`,
`strerror-test`, `sincos-test`, `explog-test`, `fparith-test`,
`float-overflow-test`, `malloc-reuse-test`, `socket-server-test`,
`dup-fdinfo-test`, `rmdir-test`, `copyfile-test`, `deeppath-test`,
`bufexec-test`, `mkstemp-test`, `printfmod-test`, `umask-test`,
`dupbuf-test`, `dotdir-test`, `getcwd-test`, `progname-test`,
`select-test`, `cxaatexit-test`, `fsync-test` (**a stub that answers
FAILURE is not one that answers NOTHING TO DO** — and its section 2 is
there because section 0 passes for an `fsync` that returns 0 to
everything), `pthread-test` (**the one test here
that can HANG, so the only one that arms a `SIGALRM`** — a thread must
reach its start routine and `pthread_cond_timedwait` must actually
wait; the two are different bugs and the sections are split so), `poll-test` (the count is
of pollfd ENTRIES, a negative fd is ignored, a closed one is POLLNVAL —
the two rules whose absence makes a `while(poll())` caller SPIN),
`rdev-test` (two different files must
be distinguishable — it transcribes diffutils' `same_file()` verbatim,
because the question is what THAT function answers), `stdio-test`.
**`strerror-test.c` must be linked against `libgnu.a`** or it passes
against a broken tree and proves nothing; the command is in the file.

**Version markers.** `pcc -o x x.c` relinks against the INSTALLED libap,
so a test built from a fresh pull can run days-old library code and say
nothing. `_sock_listenmark`, `_execmark`, `_ttymark`, `_getcwdmark`,
`_printfmark`, `_dupmark`, `_dotdirmark`, `_tempmark`, `_fdinfomark`,
`_umaskmark`, `_bufmark`, `_rdevmark`, `_selregmark`, `_pthreadmark`,
`_syncmark` each make the test **fail to LINK** against a libap
predating its fix. The idiom has paid eleven times; bump one when a file changes in a way a test must see — and
it matters most where the bug's whole symptom is that nothing is
printed.

**Host cross-checks** (not Plan 9 tests — they run on the build host):
`tz-xcheck`, `ctype-xcheck`, `strtod-xcheck`, `strtof-xcheck`,
`dtoa-xcheck`, `tty-xcheck` (needs `-I ttystub`), `strftime-xcheck`,
`random-xcheck`, `regcoll-xcheck` (needs a staged `regex.h`),
`strtoint-xcheck` (THREE compiles — a `-D` rename collides with the
header, so it renames the SOURCE with `sed`), and `strerror-xcheck.py`,
which has to be a script because **APE's errno NUMBERS are its own**, so
only the NAMES line up.
***Several of these need TWO compiles*** and the reason is the same every
time: a `-D` that renames libap's function out of the reference's way
applies to the CHECKER as well, and the sweep then compares libap against
itself and reports a clean number. *Break the unit on purpose and check
that the instrument notices.*

**Sweeps** — `apdecl-sweep.py` (a call whose non-`int` return type
nothing declares), `apehdr-sweep.py` (every `sys/include/ape` header
standalone, plus a TOGETHER case for collisions only a combination can
show), `rceq-sweep.py` (**gates**: a bare `=` in an mkfile recipe cannot
parse), `mkcont-sweep.py` (**gates**: a comment ending a continuation),
`ishadow-sweep.py` (does NOT gate — most hits are deliberate),
`hosthelper-sweep.py` (**does NOT gate, on purpose**: which mkfile
recipes run a binary the same mkfile builds, and whether it was built
with `hostcc`. A `no` is a QUESTION — a build-time helper should use
`hostcc`, a bootstrap stage cannot — so a gate would demand a change
that must not be made. Its first run **missed its own positive
control**, because it expanded `NAME=./thing` in recipes and not in
targets, and bash's rule is `$MKBUILTINS:`),
`bfmove-sweep.py` (which bit-field groups the sharing rule moves; a
LOWER bound, with an UNKNOWN column it reports rather than counts).

**Models** — `clitzero-model.py`, `sualign-model.py`, `bitinit-model.py`.
They exist because **kencc's own sources need Plan 9's `<u.h>`, so the
first build of any `cc/` change is the VM's**. Each extracts or
transcribes the real function and checks it on the host.
`sualign-model`'s control is `tmp/abi-bf-before.acid` — the real pcc's
real answer; `clitzero-model` has no external oracle so its control is a
deliberate break; `bitinit-model` is the only one with an EXTERNAL oracle
(gcc's own object bytes) and `--old` replays the replaced code.

**Probes** — `apeabi-probe` (compiled twice, `pcc -c -a` against
`pcc -9 -c -a`; the DIFF is the ABI cost, named struct by struct, from
the compiler itself), `edgtuoff-probe`, `edgscope-probe`, `tarhdr-probe`,
`tarblock-probe` (**must be built with tar's own `-I` flags**),
`chickenword-probe`, `vtparse-probe`, `vtlayout-probe`,
`regpair-probe` and `regpair-min` (**native, and their result is
whether they COMPILE** — the bug they found is FIXED, so they are
regression tests now, and **the only things here that ask a non-amd64
backend anything**: run both against all ten `[1-9kqv]c` after any
change to `cc/`'s type tables),
`devreg-probe` (**no host form and `pcc` only** — which files APE calls
regular and whether `select()` then reports them readable; the subject
is what *rio* serves, so run it in a rio window with no wish running,
and note that it never READS any of them, since reading `/dev/mouse` is
the call that hangs), and
`mkrecipe-probe/`, which is a whole mk DIRECTORY because the question is
what `mk` hands `rc` (`mk -k all`; `-k` is not optional).

**Shell and Tcl** — `bash-fdloop-test.sh`, `bash-comsub-test.sh` (a
BISECT, not a test: read `/tmp/comsub.log`, not the exit status),
`execfd-test.sh`; `bacon-test.bac` (the first BASIC test, because BaCon
ships none — and its exit status is NOT the failure count); the 25
`tk-*.tcl`; the harnesses `tk-runall.tcl`, `tk-runtest.tcl`,
`tcl-runall.tcl`, `itcl-runall.tcl` (**must run under `itclsh`**),
`tcl-fileevent-test.tcl`, `tcl-stdchan-test.tcl`, `tcl-machexp-probe.tcl`
(needs `$APEXP_STRTOD_DEBUG`), `tcl-fltmax-probe.tcl`, and
`tests/apexp-links.tcl`, which declares the `symlinks` constraint.
**Both Tcl harnesses REFUSE or WARN unless the test interpreter is
present**, because a suite failing for a missing package and one failing
because the port is broken give the same count.

**rc harnesses** live in `rc/bin`: `fdwatch`, `bash-runtests` (which
prints its own validity line FIRST and refuses the result if it is not
0), and the five ladders `bash-scriptladder`, `bash-forkladder`,
`bash-ifsladder`, `bash-fileladder`, `bash-lineladder`. **They are rc on
purpose**: a harness written in the shell under test dies with it.

`sys/src/ape/lib/libressl/test/` is separate — upstream's own ML-KEM and
SHA-3 vectors, run by `mk test` there.

Beyond that, testing is still mostly ad-hoc — compile a program under
APExp and see whether it builds and runs.

## Current Development Focus: 0.7

**The plan and the running state are in `docs/releases/0.7.md`**; 0.6's
open-bug inventory stays in `docs/releases/0.6.md`. Five items:
the archivers, go/clisp/chicken, cross-compilation, portable_stl, and a
C++ proof-of-concept application.

**`$objtype` is what you compile FOR; `$cputype` is what you run ON.**
Headers and libraries take `$objtype` — they are compiled *against* —
and binaries take `$cputype`, because they are *executed*.
***386 CROSS-COMPILES: `objtype=386 mk install` COMPLETES.*** Ten
blockers, and every one was a thing that stopped being true for
everyone and was only ever checked on amd64. **perl is the only
package still gated out**, for its amd64 `config.h` and not for
anything to do with cross-compiling as such; the other ten
architectures are untried. The walk is in `docs/releases/0.7.md`.
**`tclConfig.sh`/`tkConfig.sh` are GENERATED** by `lib/tcl`/`lib/tk`'s
mkfiles into `$objtype/lib/ape` — a TEA configure needs them, and the
one already in the tree (`external/tcl/unix/tclConfig.sh`, tracked)
is **somebody's Linux configure output**: `TCL_CC='cc'`, `-O2`,
`NOTIFIER_EPOLL`, `.so`. *The answer was not missing, it was wrong.*
`sys/src/ape/config` and `apexp-sh` were already right; **`mount-include`
was not**, and bound the target's headers and libraries using
`$cputype`. *On a native build the two strings are equal, so nothing
could ever have shown it.* Hardcoding is NOT the problem: a grep for
`amd64`/`6c`/`6l`/`6a` across every mkfile in `sys/src/ape` finds two
non-comment hits and both are deliberate.
**The blocker that comes first is `stddef_arch.h`, which existed for
three architectures out of eleven** — the 64-bit ones, which are LLP64
under kencc and need `size_t` forced ahead of `<stddef.h>`'s own arm.
`<stddef.h>`, `<sys/types.h>`, `<limits_generic.h>` and
`<stdint_generic.h>` all include it **unconditionally**, so a missing
copy is a failure at the first `#include <stddef.h>` in the first file
compiled. 386 has one now. *The other seven are left out deliberately:
a cross build stops at the first thing missing and there will be more,
so the next should be found by a build rather than guessed.*
**And a recipe that runs a binary it just built cannot cross-compile**
— but **every such tool in this tree emits architecture-independent
text, so the question is COST and not possibility.** `mkbuiltins`
writes `.c` from `.def`; `embedder` prints a C header from `.meson`
scripts; `objc1` writes the C that `$thecc` then compiles; `miniperl`
writes `perlmain.c`. All four could run on the host. What differs:
*`mkbuiltins` and `embedder` are SINGLE-FILE tools* — one `hostcc` and
they are done, and both are. *`miniperl` and `objc1` ARE the port*, so
they need more than one word — **but "building the port twice" was an
overstatement and the cheaper route is to USE THE HOST BINARY THE TREE
ALREADY REQUIRES.** `apexp-sh`'s own first line is "APExp must already
have been built for `$cputype`", so after any native build
`$cputype/bin/ape/objc1` and `.../perl` exist and can do the
translating. *`objc` is cheaper still than that*: its stage 1 is
**147 files of Objective-C upstream has already translated to C**, so
a host `objc1` builds from them with `hostcc` and nothing needs
translating to get it. What a cross build then wants is stage 1's
BINARIES for `$cputype` and its RUNTIME LIBRARIES for `$objtype` —
the same split as everywhere else, applied inside a two-stage build,
rather than two whole builds. **The cost is version skew**: a host
binary left by an older native build generates from sources that have
since moved, and `perlmain.c` lists the extensions, so it is the kind
of staleness that compiles and is wrong.
**This file twice said a "bootstrap stage" CANNOT be host-built
because the binary it runs is the product. That is wrong**, and it is
what kept `embedder` in the wrong group for a round: *it was
classified from its position in a list instead of from reading
`tools/embedder.c`.* **Open the tool before deciding which kind it
is.**
**THE RULE IS `hostcc`**, `rc/bin/ape/hostcc`: one line of rc that
sets `objtype=$cputype` and execs `pcc`. Use it for anything the build
RUNS rather than ships. It is a command and not a
`HOSTCC=objtype=$cputype pcc` variable for two reasons, both about the
`=`: **a variable holding an assignment is invisible to
`rceq-sweep.py`**, which reads the mkfile TEXT and not what mk expands
it to; and an assignment is legal only LEADING, so such a variable
used anywhere but the start of a recipe line is a parse error in a
mkfile that reads fine. `hosthelper-sweep.py` reports who uses it.
**`mount-include` had to change with it**: every bind there is for
`$objtype`, including one over `/sys/include/ape`, so a host compile
during a cross build would have read **stock 9front's APE** — or the
target's `stddef_arch.h` — and said nothing. It now also binds
`$cputype/include/ape` and `$cputype/lib/ape` when the two differ, and
the header-order invariant is what makes that enough.
**Its companion is `$objtype` where `$cputype` was meant**, which is
the same confusion one level down: a tool that is EXECUTED takes
`$cputype` and only the things it reads or writes take `$objtype`.
`bash/mkfile`'s `LD` was `$objtype/bin/pcc` and answered `exec header
invalid` — a 386 binary handed to an amd64 kernel. *`BIN=` is the
counter-example and is right as it stands*: that is an install
destination, not something the build runs. So is
`cmd/pax/mkfile:189`'s `PAX_SAFE_PATH`, which is a path the finished
binary uses **on the target**.
**But for a TOOL the right answer is usually no path at all.** The
absolute paths on `LD`, `YACC` and `LEX` are residue from early APExp,
when nothing stopped the host's copy answering first; **`apexp-sh`
binds `$cputype/bin` and `$cputype/bin/ape` over `/bin` and sets
`LD=pcc` itself**, so a bare name is already this tree's own — and a
bare name has no architecture in it to get wrong. `LD=pcc`,
`YACC=bison`, `LEX=flex`. *A path is for something read as a
DIRECTORY*, like `objc`'s `OBJCBIN`, which is where the driver looks
for stage 1's `objc1` and so takes `$cputype`.
***THE FIRST CROSS BLOCKER IS FIXED AND IT WAS A TYPE TABLE.***
`objtype=386 mk install` got past `mount-include` and stopped on
`8c -FTVw ar.c`: `ar.c:586 bad in naddr: REGPAIR`, which is
`as->offset = ap->size;`, both members `vlong`, in a file this tree
has never touched. **The cause was `cc/sub.c`'s `typesuvinit[]` having
lost `TVLONG` and `TUVLONG`** — `8c/cgen.c` opens with
`if(typesuv[...]) sugen()`, so a 64-bit value stopped being a memory
object, fell into the register path where it is a PAIR, and a pair
reaches `naddr`, which can only take an address. *Invisible on amd64,
where a vlong is one register and `6c/cgen.c` has no such line.*
**It is now past `sys/src/cmd` entirely** — every compiler, assembler
and linker builds for 386 — and the eleven-round hunt is in
`docs/notes/kencc.md`, which is where to read it rather than here.

**Two consequences that outlive the bug.** First, **`typecmplx` is a
RETURN ABI**: `cc/pgen.c` reads it to decide the hidden `.ret`
pointer, so the same missing entry had moved every `vlong`-returning
function off upstream's convention on all eleven targets. Restoring it
needed a **matched pair** — the array *and* a new `typesuc` for the
64-bit backends to point at — because APExp had made two changes that
cancelled on amd64 and only one of which survived on 32-bit targets.
*A fix that restores upstream's data without restoring upstream's use
of it is half of one, and the half I shipped first broke the build.*
Second, **`regpair-min.c` and `regpair-probe.c` are regression tests
now**, and the only things here that ask a non-amd64 backend anything.
**ALL TEN BACKENDS COMPILE `regpair-min.c` and eight compile the
probe**, against a prediction written down before the run with a
refutation condition per backend. *One clause confirmed, two refuted.*
**The confirmation is the load-bearing one**: 5c's and qc's recorded
failure on *returning* a vlong was this same bug, through `pgen.c`'s
hidden `.ret` pointer — three backends, three symptoms, one cause,
filed at the time as three pieces of work. 1c and 2c, predicted to
stay broken, compile both files.
***The two that fail are kc and vc, on case 3 — and the fault is
UPSTREAM's, newly exposed rather than newly caused.*** `d->offset = v`,
widening into a `vlong` member, answers `unknown op in lcgen: CAST`:
of the six backends whose `cgen` hands a vlong to `sugen`, four have a
way out of `copy:` for a 64-bit value and kc and vc have none.
**Their `cgen.c` differs from 9front HEAD by `OALLOCA` and the
`true` → `cond` rename and nothing else**, and upstream's `typesuv`
carries `TVLONG` as ours does again — so *the emptied table that broke
8c was MASKING this on those two.* **This tree's rule about a fix
reaching code nothing reached before, applied to a compiler.** Not
fixed (sparc64 and mips, nothing builds for either); in 0.6's
open-bug inventory with the mechanism. **And "kc regressed" is only
half right**: vc appears in neither of the first run's two lists, so
its earlier state was never measured — *a name absent from a list is
not a measurement, including a list in these notes.*

**Three reading errors from that hunt, each of which cost rounds:**
*(1)* `git bisect` could not reach it — this repository's ROOT COMMIT
already carries `isbool`, `vlasizevar`, `alignas_req`, `_Generic` and
VLA, so a bisect runs to the root and reports "always broken", a wrong
answer shaped like a result. *(2)* **Read any `diff -r` against
`/sys/src` as two forks, not as a patch set.** `Spec` exists upstream
and nowhere in APExp's `cc.h`, so much of a 3768-line diff was 9front
moving forward rather than our patches — the second attribution error
in the same direction. **APExp's kencc base is dated**: it has
`3ea08ad83` (2025-12-28) and lacks `a68335214` (2026-06-10), so the
fork point is between those, and "stock compiles it" meant "9front
from before December 2025 does". *(3)* A compile-time result can only
name a LINE, so it rots when the file is edited above it; key a
results table on the CASE and re-key rather than renumber.

**portable_stl: both questions are answered and both answers are no.**
Its `CMakeLists.txt` has **no `install()` rule and no `configure_file`**
— the single target is the gtest binary, so *the headers are the
product* and installing is a copy. And the namespace cannot become
`std`: **the library already declares `namespace std` itself**, for
`initializer_list` and `type_info`, which the core language requires to
live there. Renaming would not buy compatibility anyway —
`vector::push_back` returns `expected<void, portable_stl_error>`,
because the library is exception-free by construction. *A conformance
corpus and a usable library, not a drop-in `std`.*

## What is open, as a list

**The whole history of every entry below is in `docs/notes/ports.md`
and `docs/notes/edg.md`.** What is here is the state and the next step.

**`_OPTIONAL_APPS` is read, not recalled.** `grep -n 'optional'
sys/src/ape/cmd/mkfile` and read the list; this paragraph has been stale
twice by naming a state the mkfile had moved past, and line numbers go
stale faster than names. **The reason for caution is unchanged**: one
failing entry aborts the whole tree's `mk`, so anything newly enabled is
a thing the next full rebuild can stop on, and *a port that has only been
built by hand has not been measured in that position*.

**Ports not started:**
- **go** — stopped four times, each one file further in, and every one of
  the four was this tree's own mkfile rather than go: the `bool` keyword,
  a missing `-c`, Makefile backslashes in a `-D`, and `-DPLAN9` doing two
  unrelated jobs. The fourth is structural (`plan9.c` wants `<u.h>`; the
  portable `unix.c` arm is written and satisfied and simply switched
  off). **Out of the default build for 0.6.**
- **clisp** — `configure` runs and reaches `C compiler cannot create
  executables`, with hundreds of `5: Bad file descriptor` around it. The
  fd mechanism is **cleared** (`execfd-test.sh`, 11 sections, 0 failures
  on 9front, self-re-exec and 300 forks included), so that verdict is a
  configure that could not write its own log and not a statement about
  `pcc`. The plan is a hand-answered `config.h` plus an mkfile, as perl
  and bash already have. **Out of the default build for 0.6; it is its
  own release.**

**Ports built and running**, each with what is NOT measured:
- **EDG** — `cpfe` builds, runs, and translates: `c++ -v -K /tmp/t.cpp`
  takes a toy through cpfe and through `cc -c` with no complaint, which
  is the first end-to-end measurement the driver has had. **It then
  fails at the LINK, on a template**: `main: undefined: _Z5twiceIiET_S0_`
  — `int twice<int>(int)` — because under EDG's default mode an
  instantiation is emitted by NO translation unit and a separate
  `edg_prelink` pass is meant to place it. *We have no prelinker and mk
  cannot naturally express one*, so the default can never link a
  template here; the tree had already measured this from the other end,
  556 of 558 undefined `_Z` names in cpfe's own link being
  instantiations emitted nowhere.
  **`eccp` passes `--instantiate local`, and IT LINKS**: the same
  command now runs cpfe, `cc -c` and the link with no complaint and
  `./a.out` returns. *The prediction and its refutation condition were
  written down before the run and the condition did not fire*, so the C
  back end does honour the mode and **C++ with templates is a working
  pipeline on this machine** — which is the first thing in this port
  that is a capability rather than a stage.
  **THE SILENCE IS CORRECT AND THE TOY RETURNS ITS ANSWER INSTEAD.**
  `/tmp/t.cpp` is a virtual base with an override, a destructor, a
  template, and `int main(){ D d; B *p = &d; return p->f() + twice(3); }`
  — no `printf` anywhere, so nothing should print. **But it is not inert
  either: it returns `2 + 6`, and `echo $?` is the measurement.**
  ***8 means virtual dispatch AND the template both work at run time***
  — `p->f()` reaching `D::f()` for 2, `twice(3)` for 6. **7 means the
  vtable resolved to the BASE** (`B::f()` returning 1) with the template
  fine, which is a different bug in a different place. *A program that
  links and runs is not a program that works*, and here one command
  separates three outcomes rather than two.
  **Its cost is named rather than feared**: internal linkage gives each object
  its own copy, so a template's static data member or a static local
  inside a template function stops being one object shared across the
  program — a program whose correctness rests on that identity is
  silently wrong rather than loudly broken, and one translation unit
  cannot show it. `-C` (COMDAT) stays for the runtime's duplicate
  typeinfo, which `local` does not touch.
  **Open**: the static-init gap (nothing
  calls `_Z12__call_ctorsv`), `__thread` silently dropped, and the fact
  that there is **no C++ standard library here and EDG ships none** — the
  reachable subset is the one EDG itself is written in. The best corpus
  available is `paragon_portable_stl` (720 headers, zero system
  includes), as a CONFORMANCE corpus rather than as an STL: its namespace
  is `portable_stl` and `vector::push_back` returns `expected<...>`, so
  no rename recovers it.
- **muon** — builds and prints its own usage. *A port that builds and
  prints a usage is not a port*: `muon setup` on a real `meson.build` is
  the next thing that would say anything.
- **chicken** — both compiler bugs it found are fixed and measured
  (`longconst-test`, `switchcase-test`, both 0). What remains is running
  `chickenword-probe` with chicken's own flags.
- **bacon** — **IT SELF-HOSTS, AND THE FIXPOINT IS PROVEN AT THE
  SOURCE.** `bacon -p -n -q bacon.bac` and then `./bacon -p -n -q
  bacon.bac` produce **identical C**: the compiled converter reproduces
  its own input exactly. Generation 2 doing real work is the half that
  matters — *a compiler that produces a binary has not been shown to
  produce a WORKING one*, the gap `miniperl` had.
  **And that EXPLAINS the equal binary sizes rather than merely agreeing
  with them**: gen 2 was built from C1 and gen 3 from C2, so with
  C1 == C2 and the same `Makefile.bacon` link command both times the two
  binaries must be identical — which is what 3048736 twice was saying.
  *Two observables, one of which accounts for the other.*
  ***THE REMAINING DOUBT IS THE INSTRUMENT, NOT THE RESULT.*** APE's
  `cmp` prints nothing when two files are the SAME, and it also printed
  nothing when it wrongly believed its stdout was `/dev/null` — and
  those are indistinguishable from the prompt. The `st_rdev` fix below
  reaches the VM only after `mk install` in `lib/ap` **and a relink of
  `cmp`**, since a libap fix does not reach a binary already built. Any
  one of three settles it without a rebuild: Plan 9's own `cmp` from
  `term%`; `echo $?` (the status is correct even when it is silent); or
  **the sharpest, running the same `cmp` on a pair KNOWN to differ** —
  if it speaks there and is silent here, the silence means identical.
  *The equal binary sizes were already independent corroboration, so
  this tightens a result rather than doubting it.*
  **Comparing against `src/bacon.bac.c` is a DIFFERENT question and was
  the wrong test**: that file came from `bacon.sh`, a *second,
  independent implementation of BaCon written in bash*, so agreement was
  never the expected outcome — the first difference is at byte 17,
  exactly where `/* Created with BaCon ` and `/* Created with Shell
  BaCon ` diverge, and `/* Created with ` is sixteen characters.
  **Getting the C out at all needs a flag**, because bacon DELETES it
  (`bacon.bac:8294` puts it on the temp list, `:10509` removes it), and
  the flags do not do what their names suggest: **`-n` alone converts
  and then throws the conversion away**, since the cleanup is outside
  the no-compile branch. `-p` is the one that keeps it. ***And `-p`
  also runs `indent` over what it keeps*** (`:10399`), which would
  rewrite the file and make any comparison measure formatting — **safe
  here only because APExp ships no `indent`**, and bacon says which case
  it is: `WARNING: 'indent' not found` means untouched, `Applying
  indentation... done.` means the comparison is void.
  ***And it had to be `./bacon`***: plain `bacon` resolves through
  `$PATH` to generation 1, so the second run would have re-measured the
  first binary and reported a clean, meaningless result.
  `bacon-test.bac` remains 3 failures, all three the 32-bit-`long`
  invariant arriving through a language whose only integer type is that
  `long`.
- **the archivers** — **BOTH HANGS ARE FIXED AND MEASURED, AND THE
  PREDICTION HELD.** `xz -c <sample.txt >/tmp/t.xz` returns and writes
  72 bytes; `unlz4` returns with an error instead of freezing. The
  cause was libap's `pthread_create` (three bugs — a child rendezvous
  the parent never answered, an unwritten `*t`, and an `attr != NULL`
  EINVAL that libap's own `pthread_cond_timedwait` tripped over every
  call, spinning `wait_for_work` through `clock_gettime` → `_PREAD`,
  which is why `s` was pinned and `l` was not). ***The refutation
  condition written down before the run did not fire***: lz4 was
  wedged on the same mechanism, via `programs/threadpool.c`, so the
  earlier "they share no mechanism" claim stays withdrawn. *A grep
  that finds nothing has ruled out what you grepped for and nothing
  else.* `docs/notes/libap.md` has the two `acid` stacks.
  **Then `fsync` DELETED THE OUTPUT.** `unxz /tmp/t.xz` decompressed
  correctly and printed `Synchronizing the file failed: Invalid
  argument` — libap's `fsync` was `errno = EINVAL; return -1`, xz
  turns a nonzero fsync into `success = false`, and
  `io_close_dest(pair, false)` REMOVES the destination;
  `opt_synchronous` is on by default, so this was every `xz`/`unxz` on
  a named file, every time. **The stub-answers-FAILURE family again**,
  and libap already held the right answer in a second place that
  disagreed (`plan9/__p9_syscall.c:594`, "Plan9 writes are
  synchronous; no-op is correct"). Fixed; `fsync-test` 0 on gcc, 1 on
  the replaced line.
  ***AND THE FIRST ATTEMPT TO MEASURE IT MEASURED NOTHING.***
  `fsync-test` printed **nothing at all** — no header, no count — and
  in the SAME run `unxz /tmp/t.xz` still said `Synchronizing the file
  failed` and still deleted the output. *A fault, a kill and a clean
  finish all give the prompt back*, so "no output" is not a pass; and
  the `unxz` line says the build did not contain the fix, which is
  this tree's own rule twice over — **`mk install` rebuilds `libap.a`
  without relinking binaries already built against it**, so `xz` keeps
  the old `fsync` until something forces the relink. The test now sets
  line buffering and prints `fsync-test: starting` before any work, so
  silence and a first-call crash are different outputs. **`/dev/cons`
  answering `S_ISREG` with `FD_ISTTY` unset makes a fully buffered
  stdout a live explanation for the silence**, which is why the
  `setvbuf` is the first statement.
  **WHAT IS LEFT IS TWO DECODE FAILURES, AND NEITHER IS SEPARATED**:
  `unxz xz_sample_file_1MB.xz` says `Compressed data is corrupt` and
  `unlz4 sample.txt.lz4` says `Error 26 : LZ4F frame decoding could
  not complete: invalid frame`, `Decompressed : 0 MiB`. **Both files
  were produced ELSEWHERE**, so each has two explanations — a bad
  download, or a path only those files reach — and *an absence of a
  local round trip is what keeps them unseparated*. ***The positive
  result is hidden inside the sync error***: `unxz /tmp/t.xz` reached
  `io_sync_dest`, which runs AFTER decoding, so **encoder and decoder
  already agree on a small file.** The discriminators are a local
  round trip at 1MB and `-T1` against the default `-T0`, since the
  threaded encoder is ground nothing has ever covered — *a fix that
  makes a process reach code it never reached before can expose
  anything on that path*. `unarj` lists a 1MB archive correctly;
  unrar, unace, zstd and clzip untried.
  **`pcc -9` is NOT available as an A/B**: one package rebuilt under
  the old layout rule against a `-J` libap is the silent ABI split, so
  it cannot separate "`-J` broke it" from "it never worked".
  **`ratrace -c "cmd args >file"` DOES NOT RUN THE COMMAND** — it
  execs the whole string as one argv[0] and answers `file does not
  exist: '/bin/xz -c <sample.txt >'`. A run that reports "cannot
  reproduce" from that line has measured nothing; `ps` and `acid` on
  the pid are what worked.
- **itcl** — done. 10 failures, all upstream or Tcl 9's, two settled at
  source, none ours.

**Queued**: **tkdesk** gets its mkfile in `sys/src/ape/app` and is **not
built by default**, being a proof-of-concept rather than part of APExp.
(`tkblt` was dropped: 3.2 is C++ with namespaces, and tkdesk never needed
it — it ships its own BLT subset in C.)

### perl

`sys/src/ape/lib/perl` builds `libperl.a`; `sys/src/ape/cmd/perl` builds
`miniperl`, uses it to generate `perlmain.c`, links `perl`, and installs
the module library into `sys/lib/perl` (config.h's `PRIVLIB`).

Working: the interpreter runs, module loading works, and
`ExtUtils::Miniperl` generates `perlmain.c`.

**No XS extensions.** Plan 9 has no dlopen, so `usedl` is empty, `dlsrc`
is `dl_none.xs`, `xs_init` has an empty body, and only the pure-perl
`dist/` and `cpan/` trees are installed — the fourteen with a `.xs` are
deliberately left out, listed in the mkfile. *A `.pm` that dies in
`XSLoader` is worse than one that is absent.* PathTools is the exception.

**`Config.pm` is hand-maintained**, at `sys/src/ape/cmd/perl/Config.pm`,
and is the companion to the hand-answered
`sys/src/external/perl/config.h` — the two have to be kept in step.

*Getting perl to run at all turned up four bugs and only one was perl's;
three of them were silent. The set is worth reading as a set, in
`docs/notes/ports.md`.*

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
| `docs/notes/tcl-suite.md` | Tcl's suite: the allocator, sockets and the missing loopback, `shutdown()`, `listen()`, `select()` and `ap/plan9/_buf.c`, `fd_set`, the `chan-io` hangs, the per-name baselines (43, then 42), and itcl |
| `docs/notes/bash.md` | the bash campaign: the allocation storm and the twelve instrument faults it cost, the fourteen `config.h` features, printf, strftime, strtoull, strerror, dup, readdir, and the per-file state of its suite |
| `docs/notes/edg.md` | EDG's C++ front end: the target description, the link model, the `auto` grammar bug, the entry point, the folded `offsetof`, and the two bit-field rules it flushed out of kencc |
| `docs/notes/ports.md` | one section per package — cfront, bacon, muon, go, chicken, perl, GNU tar — what each took to build and what the breakage turned out to be about |
| `docs/notes/instruments.md` | every test, probe, sweep, model and cross-check: what it came from, what it cost, and which of them turned out to be the visible fault |

Two more under `docs/`, which are surveys rather than history:
`posix-coverage.md` (what of POSIX/musl is present, missing or stubbed,
compared file by file against musl's `src/`) and
`compiler-improvements.md` (the state of the Plan 9 C compilers and what
is still open). `docs/releases/` holds the release notes.

**`docs/releases/0.6.md` carries the OPEN-BUG INVENTORY**, and it is the
one place the recorded-not-fixed items are gathered rather than scattered
through this file at the point each was found. Its *Known limitations* is
sorted into platform limits (not bugs and not fixable here), compiler,
libap, headers, and the ports deliberately out of the default build --
each entry saying what it costs and **whether it has been measured**,
because that distinction is the point of the list. Add to it in the same
round a thing is recorded here.

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
  **IT IS MEASURED NOW AND IT IS SWEPT FOR: `sys/lib/tests/rceq-sweep.py`,
  and it GATES.** clisp's `if (test $name = lispbibl)` answered
  `/rc/lib/rcmain:24 *eval*:4: token '=': syntax error` on the VM, which
  closes the question `cmd/clisp/mkfile.runtime` had carried as unmeasured
  -- *there is no rc on the build host*, so until that run the rule was a
  recollection. **Three live breaks and one latent**: both clisp mkfiles,
  the whole `--prefix=`/`--srcdir=` family on its configure line, and
  `lib/ap/mkfile:63`'s `mk objtype=$objtype install`, which sits in an
  `installall:V:` a normal build never reaches -- *an untriggered rule
  gets no diagnostic from anyone*, for the second time after the
  transpiler rules. 693 recipe lines, 0 now, and the control fires.
  **AND mk NAMES THE WRONG LINE**, which is why this is a sweep and not
  a reading: the failure was reported as
  `mk: mkdir -p build-amd64 ...: exit status=rc: syntax error` -- mk
  names a recipe by its FIRST line, and the fault was four lines down in
  a file the message never mentions. *The message names the victim*, a
  third time after the `lock.h` shadow and `cmd/mkfile:96`.
  **`if (cond) NAME=value` IS LEGAL and is the sweep's discriminator**:
  `libc/9syscall/mkfile`'s `if(~ $i seek) j=_seek` is a working
  precedent, so a naive grep reports 16 lines of which 11 are that shape.
  *And the sweep's own first run reported its own comments* -- rc treats
  `#` as a comment too -- which is the cry-wolf failure caught before it
  shipped. **Its root guard fired on the first run as well**, for
  `ishadow-sweep`'s exact miss: `sys/lib/tests` is THREE levels below the
  root and the file said two.
  **AND IT CAME BACK A SECOND TIME WITH THE SWEEP AT 0, WHICH IS WHY
  THE RULE NOW HAS A SECOND HALF: a comment inside a recipe is rc's,
  not mk's.** `mkfile.rebuild` answered
  `/rc/lib/rcmain:24 *eval*:13: token '=': syntax error` after the
  bare-`=` line had been replaced by `~` -- and **the only `=`
  characters left in that recipe were the two inside the COMMENT that
  explained the fix**, plus one leading assignment rc allows. mk hands a
  recipe to rc verbatim, so every tab-indented `#` line is rc source.
  *Writing the rule down inside the recipe is what broke the recipe.*
  **MEASURED NOW, AND THE COMMENTS WERE INNOCENT: THE CONSTRUCT IS
  `} if not {` ON ONE LINE.** `mk -k all` in
  `sys/lib/tests/mkrecipe-probe` answers `ok 1`, `ok 2`, `ok 3`,
  **case 4 `token if: syntax error`**, `ok 5`, `ok 6` -- so a plain
  recipe comment is fine, *a comment holding a bare `=` is fine*, and
  one holding backquotes and apostrophes is fine. rc wants a command
  separator after the closing brace; `}` followed on the same line by
  `if not` is not one, and the fix is a newline.
  ***SO MY DIAGNOSIS OF `mkfile.rebuild` WAS WRONG AND THE FIX WAS
  RIGHT BY ACCIDENT.*** I read `*eval*:13: token '=': syntax error`,
  found the only `=` left inside a COMMENT, and concluded that mk hands
  comments to rc as source -- then rewrote BOTH clisp mkfiles to remove
  every recipe comment *and* to put `if not` on its own line. The
  second edit is what fixed them. *Two changes in one commit and the
  wrong one got the credit*, which is the plainest form of the rule
  this file already carries about experiments that isolate nothing.
  **The sweep is clean**: `} if not` on one line now appears nowhere in
  the tree but inside the probe itself and inside a comment describing
  it. The clisp mkfiles' comment-free recipes can be relaxed whenever
  anyone wants; they cost nothing and are no longer required by
  anything measured.

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
- **amd64 underflow is GRADUAL**: **`main9.s`** loads MXCSR `0x1f80`,
  FTZ and DAZ both clear, so `Sudden_Underflow` is not defined for it
  any more. The other seven architectures still claim it, unchecked.
  **This line used to say `fenv.s` and that was the wrong file** —
  which mattered, because *every* `arch/*/fenv.s` turns out to define
  no symbols at all (see below). The startup load is `main9.s:43` and
  is real; the API is the stub.
- **The fenv API is a STUB on every architecture.** `grep -c '^TEXT'` over
  all six `arch/*/fenv.s` is 0: `as` turned musl's `.globl`/`.type`
  into comments and left a bare `name:`, which Plan 9 asm reads as a
  LOCAL label. `lib/ap/fenv/fenv.c` — musl's fallback for archs with no
  fenv — answers instead, so `fetestexcept()` reports nothing ever
  raised and `fesetround()` does nothing. `fenv.$O` is out of the six
  mkfiles; the entry in 0.6's inventory has the mechanism.
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

**The campaigns that produced these numbers are in
`docs/notes/tcl-suite.md`, `docs/notes/bash.md`, `docs/notes/vts.md`,
`docs/notes/libap.md` and `docs/notes/ports.md`.** What follows is the
state and the open list; every claim here was measured, and where it was
not the entry says so.

**Tcl's suite**: `Total 68118 Passed 62160 Skipped 5916 Failed 42`, 167
files, marker, exit 0, four minutes — re-measured on the tree that
carries this release's whole ABI move (`-J`, 64-bit `ino_t`/`dev_t`,
`struct stat` 88 → 104). **`Total` and `Skipped` are identical to the
digit** against the 43-failure baseline, so the arithmetic is a
statement about the same population: **one fixed, nothing broken, and
the name is `io-52.22.1`** — one of the eleven unattributed singletons,
and still unattributed, since nothing this round was aimed at it. Both
lists are BY NAME in `docs/notes/tcl-suite.md` with the extraction
command; the log is `tmp/tcl-all.out`. *That a change of this size moved
exactly one test is the result the re-run existed to get.*

**Tk's suite**: 97 files, `Total 10027 Passed 8926 Skipped 924 Failed
177`, marker, exit 0 — **restored, and `Failed` is identical to the
pre-regression run.** It had been a white window frozen on `bell.test`,
the first of the 97, and the cause was libap's: `select()`'s new
regular-file arm reported readable *without buffering*, `_dirtostat`
calls rio's `/dev/mouse` regular (every file reached through a 9P mount
is), and `PollP9Events` polls it with a zero timeout and then does a
**blocking read**, so the first poll of the first window never returned.
`_selregular` narrows the predicate by LENGTH and **`devreg-probe`
confirmed the whole mechanism**: `/dev/mouse` and `/dev/cons` come back
`REG size 0 / not ready` while `/dev/winname` and `/dev/snarf`, also
`REG size 0`, come back READABLE — the copy process answering
truthfully for the two that have data and the two that block. The 177's
own share is `focus-6.1`, `geometry-4.7`, `event-9.13`/`9.14` and
`visual-3.1`.
***AND `/dev/cons` ANSWERED `REG`, NOT `chr`***, so `FD_ISTTY` is not
set on a freshly opened one. Not a bug on its own, but it means GNU
grep's "am I writing to the file I am reading" check (`SAME_INODE`
against stdout) now actually RUNS against the terminal instead of being
skipped as a non-regular file. Recorded, not measured.

**bash's suite**: `PASS 49 / REAL 36 / WARNONLY 1` of 86 files, from 0
passing. ~950 of the 1015 remaining differing lines are platform limits —
JOB_CONTROL (no `tcsetpgrp`/`tcgetpgrp`, no foreground process group),
process substitution (`/dev/fd` absent and `/fd` has the wrong semantics
for a child), no dlopen, `/etc` absent, whole-second mtimes, `/dev/tty`,
`mkfifo`, symlinks, hard links, and a `/bin/p` name collision.
**What is NOT attributed is about seven files and ~65 lines**, and that
list is the place for the next bash round to start rather than
re-deriving: `run-invocation` 6 (almost certainly `TRANSLATABLE_STRINGS`,
the capability-present-and-not-declared shape a seventh time),
`run-intl` 5 (`LC_NUMERIC` not taking effect — possibly ours),
`run-posixpat` 15 (every line is expected output ABSENT, which is what a
missing capability looks like), `run-nquote` 16, `run-lastpipe` 14,
`run-heredoc` 8, `run-attr` 2 (a variable marked exported that should not
be), and `wait: usage` in two files.

**vts**: the session works end to end — bash on a real `cons`, raw mode,
readline, tab completion, arrow keys, `$TERM=vt100`, LNM for the `\n`
translation, and no keystroke theft. **The one thing left is a feature
rather than a bug**: `session_init(s, name, 24, 80)` is hardcoded, so a
window that is not 80 wide gets a correct-looking wrong answer.
`cellbuf_resize()` exists and nothing calls it from a window-size path.

**Closed this release, each confirmed behaviourally rather than by a
build completing**: GNU tar (the 520-byte `union block` — reader and
writer were one bug); gnulib's self-recursive `strerror`, which had been
killing every GNU program in the tree; `isblank('\t')` and the bash
allocation storm; `getcwd(NULL,n)`; `mktemp`'s 26 names; `printf`'s
`%td`/`%jd`/`%hhd`/`%F`; fifteen missing `strftime` conversions; 40 wrong
`strerror` entries; `dup`/`dup2`/`F_DUPFD` on a buffered descriptor;
`.`/`..` in `readdir`; collating symbols in `regcomp`; `umask`;
**`st_rdev` being 0 for every file, which made APE's `cmp` compare two
different files in SILENCE** (it believed its own stdout was
`/dev/null`) and made `diff -r` call every pair of special files
identical; **16-bit `ino_t`/`dev_t`**, against a tree of 64799 files;
**`pthread_create` never running the thread it created** — the child
waited on a rendezvous the parent never answered, which was both
archiver hangs; **`fsync` answering FAILURE, so `xz` deleted every file
it wrote**; `poll()`'s three POSIX violations and `select()` on a
regular file; itcl's
four `sfbug`s; kencc's `false` keyword, the `L`-suffix width cap, the
wide case label, the compound-literal zero fill, and both bit-field
rules with the static initialiser underneath them.

**The ABI move of this release is `-J`, conforming struct layout, on by
default in `pcc`.** `pcc -9` is the way back and exists for the
instruments only; `6c` keeps the 9front rule, which is what `cmd2/vts`
and `vtwin` need against the host's own `libc.a`. **The measured cost in
the public headers is sockets, locks and `termios`** — `sockaddr_in`
24 -> 16, `pthread_mutex_t` 56 -> 40 — and **not** `FILE`, `struct stat`,
`DIR`, `jmp_buf` or `fd_set`, which the flag's own warning had named and
the acid diff refuted. *The feared cost and the measured cost were
different sizes, and only the probe could have said so.*

**`ino_t` AND `dev_t` ARE 64 BITS NOW, and `struct stat` is 104 bytes
where it was 88** — so this release carries a SECOND ABI change beside
`-J`, and `mk distclean` before `mk install` covers both. They were
`unsigned short`, and `_dirtostat` assigns `st_ino = d->qid.path`: a
64-bit qid truncated to sixteen bits, so two unrelated files were "the
same file" to anything keyed on dev+ino once a server held more than
65536. ***The APExp tree is 64799 files***, about one percent short of
guaranteeing a collision inside itself.
***Widening a typedef only reaches the copies DECLARED with it***:
`include/priv.h`'s `Rock` held `unsigned long dev, inode` — 32 bits
here — and would have gone on truncating. `acidlib`'s `stat` aggregate
was **already stale by several ABIs** (28 bytes, no `st_rdev`) and is
regenerated from the compiler's own `pcc -c -a` output rather than by
hand; it carries no comment explaining that, because **no acid file in
this tree has ever had one** and the syntax cannot be checked here —
the `<termios.h>` glob rule. The reasoning is in `docs/notes/libap.md`.
*Two things it fixes rather than costs*: musl's `<sys/sysmacros.h>`
already assumed a 64-bit `dev_t` and becomes correct untouched, and
perl's hand-maintained `config.h` already declared `ST_INO_SIZE 8` —
the first hand-maintained capability file in this tree that was right
while the library was not.

**Smaller open items**: `strtol`/`strtoul` have the same
one-limit-for-both-signs shape as `strtoll` had, so `strtol(LONG_MIN)`
is likely ERANGE too -- **unmeasurable by cross-check**, because kencc's
`long` is 32-bit and the host's is 64, so the two sides would disagree
about the right answer by construction; untouched for that reason. `unlink()` of a directory reports `EPLAN9`
where POSIX allows EPERM or EISDIR. *(The `strerror(EBADF)` item is
CLOSED -- it was 40 entries, not one; `docs/notes/bash.md`.)*

**Open hazards recorded but not measured**: the lost wakeup in
`select()`'s rendezvous (a copy process reaching EOF before the parent
sets `selwait`). *(The `_closebuf` "kills ten times without waiting"
entry was withdrawn: the loop IS the wait -- it ends when `kill` fails
-- and misreading it is what left `_sock_killlisten` without one.)* *(The third -- a closed `socket -server`
leaving its `listenproc` for ever -- was measured and fixed; see
`docs/notes/tcl-suite.md`. It had sat here unmeasured while it silently
decided the result of two tests.)*
