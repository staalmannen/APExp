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
`compound-literal-test` (**1 known failure, and it is NOT the merge's**:
an array literal's frame slot is reserved as ZERO bytes, because
`dcl.c:261` leaves `t->width` 0 for a declarator with no dimension and
`compoundlit()` calls `adecl()` before `doinit()` learns the size --
`sizeof` is unaffected, which is why bison never saw it; 0.6's
inventory has the mechanism), `designated-init-test`, `charptr-test`,
`rol64-test`, `u64float-test`, `initzero-test` (a compound literal must
zero the members its list omits — muon's crash), `longconst-test` (an
`L` is a floor on a constant's type, not a ceiling), `switchcase-test`
(a wide case LABEL is truncated, not discarded), `structalign-test`
(`-J`, conforming layout, **three runs** — gcc, then `pcc -9 -DPLAN9`
which must FAIL, then plain `pcc` which must pass), `bitinit-test` (a
static initialiser must write the bit-field GROUP's bytes, not the
container's), **`punoffset-test`** (***the worst compiler bug found
here***: `[1-9]c/reg.c`'s `mkvar` keys an optimizer variable on
(sym, name, **OFFSET**), so writing an object and reading part of it
through a cast pointer makes two UNRELATED variables and `regopt`
EXCISES the store — in either direction, with no diagnostic.
**Sections 3/6/7/8 are controls that PASS against a broken compiler**,
because an address kept in a pointer variable spells a `LEAQ`, which is
a `D_ADDR`, which `mkvar` already marked. *The bug was never "the
address was taken", it was "the address was taken and FOLDED INTO the
memory reference"* — and it cannot be written with a union, which would
test the path that already worked), **`leawide-test`** (***the third
member of the wide-constant family***: x86-64 has `MOV r64, imm64` and
NO 64-bit `CMP` immediate and NO 64-bit address DISPLACEMENT.
`6c/cgen.c:346` folds `(x<<k) + C` into `LEAQ C(base)(index*2^k)` and
refused only a SMALL `C`, never a wide one. **Sections 4 and 5 are
controls that pass against a broken compiler.**),
**`boolptr-test`** (a POINTER converted to `bool`, at the four sites
that CONVERT rather than cast — return, initialiser, assignment,
argument. C99 6.5.16.1 allows it outright; `sub.c`'s `stcompat`
refused it, **and `com.c`'s `boolnorm` was already there and sat
behind the check that refused the operand** at all four. *The cast
form worked all along*, since `tcast[TUCHAR]` carries BIND.
**Sections 1 and 2 are why it is a test and not a compile**: the
plausible wrong fix keeps the LOW BYTE, so section 2 uses
`0x0000555500000000`, non-null and zero in every byte a `char`,
`short` or `int` conversion would keep — the perl `cBOOL` bug's shape
by another route).
**`truefalse-test.c` is the one NATIVE test here** — `6c`/`6l`, not
`pcc` — and has to be: APE's `<stdbool.h>` `#define`s `true`/`false`, so
a TU that INCLUDES that header never reaches kencc's own C23 keywords.
***THIS LINE USED TO SAY "an APE build" AND THAT WAS TOO STRONG***: the
masking is a property of the translation unit, not of the driver, and
go's C sources do not include `<stdbool.h>` while go's bootstrap IS
`pcc` (`cmd/go/mkfile.bootstrap:44`) — so an APE build hit the keywords
on `go.h:1093`, `int true` as a PARAMETER NAME, legal in C89.
**A `-std`-style switch to turn the keywords off is NOT worth building,
and that is measured rather than assumed**: `truefalse-sweep.py` reports
**go1.4 as the only package** in 20471 vendored `.c`/`.h` files with the
shape (311 mask the names themselves; the 3 remaining hits are prose and
macro pastes), and *go1.4 is FROZEN* — the last C implementation of Go,
which is why it is the bootstrap — so its 130 renamed sites are a cost
paid once and not on every import.

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
`select-test`, `cxaatexit-test`,
`statvfs-test` (**TWO RUNS, and one alone proves nothing**: the
default mode must report space and `APEXP_STATVFS=strict` must answer
ENOSYS, and *a run of only the first cannot tell a working switch
from a switch that is never read*. Its `-DHOSTCHECK` build is the gcc
control and drops the APExp-only sections, because the host's statvfs
reports a real disk and asserting 8 TiB against it would be asserting
the answer rather than the rule. **The version marker matters more
here than usual**: the OLD library's ENOSYS is a legitimate output of
the NEW one under `strict`, so a stale libap looks exactly like a
working `strict` run),
`fsync-test` (**a stub that answers
FAILURE is not one that answers NOTHING TO DO** — and its section 2 is
there because section 0 passes for an `fsync` that returns 0 to
everything), `pthread-test` (**the one test here
that can HANG, so the only one that arms a `SIGALRM`** — a thread must
reach its start routine and `pthread_cond_timedwait` must actually
wait; the two are different bugs and the sections are split so), `poll-test` (the count is
of pollfd ENTRIES, a negative fd is ignored, a closed one is POLLNVAL —
the two rules whose absence makes a `while(poll())` caller SPIN),
`ucontext-test` (**the one test here with a REAL REFERENCE
IMPLEMENTATION** — glibc has ucontext, so all six sections were checked
against a working one before the VM saw them, 0 failures; *a failure on
Plan 9 that also fails on gcc is the test's bug*. Section 1 asks whether
the function ran **on the stack it was given**, which a switch that
quietly used the caller's would otherwise pass; section 3 passes the
maximum arguments because the ucontext cell sits just above them and the
failure mode of an off-by-one is `exit(0)`, so it prints a marker first),
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
`_syncmark`, `_mmapmark`, `_ucmark`, `_statvfsmark` each make the test **fail to LINK** against a libap
predating its fix. The idiom has paid thirteen times; bump one when a file changes in a way a test must see — and
it matters most where the bug's whole symptom is that nothing is
printed.

**`gd-test.c` and `gd-xcheck.sh`** are the newest pair and the shape
is worth copying: **there is no reference implementation of libgd**,
so the cross-check builds the SAME vendored sources with gcc and runs
the SAME test file, making it an A/B of two compilers over one source
rather than a comparison against an oracle. *All 47 files compiled
clean under kencc on the first attempt*, which is exactly why the test
exists — every bug this exercise can still find is a RUNTIME bug.
Every assertion is exactly checkable without a golden image: rotate 90
four times is the identity whichever way gd turns it, a PNG round trip
must return its own pixels, and scaling a FLAT image must leave it
flat whatever the filter does. ***ITS FIRST TWO DRAFTS WERE BOTH THE
TEST'S BUG AND gcc FOUND BOTH***: `gdImageRotate90` is INTERNAL
(`gd_intern.h`, not installed) so the call was implicit-`int`, the
pointer truncated and the test SEGFAULTED — this tree's own
undeclared-function invariant, inside a test written to hunt that
class — and the harness builds the test `-Werror=implicit-function-
declaration` now; then section 8 asserted that ≤256 distinct colours
survive palette conversion EXACTLY, and 1024 of 1024 pixels "changed"
because gd takes colour-cube CENTROIDS, so (0,0,0) comes back (4,2,4).
*What is exact is that the mapping is a FUNCTION OF COLOUR* — equal
colours in, equal indices out — and the drift is measured and bounded
instead. **Its control breaks `gdImageGetPixel` by one column** and
gates if the `sed` matches nothing.

**Host cross-checks** (not Plan 9 tests — they run on the build host):
`tz-xcheck`, `ctype-xcheck`, `strtod-xcheck`, `strtof-xcheck`,
`dtoa-xcheck`, `tty-xcheck` (needs `-I ttystub`), `strftime-xcheck`,
`random-xcheck`, `regcoll-xcheck` (needs a staged `regex.h`),
`strtoint-xcheck` (THREE compiles — a `-D` rename collides with the
header, so it renames the SOURCE with `sed`), and `strerror-xcheck.py`,
which has to be a script because **APE's errno NUMBERS are its own**, so
only the NAMES line up.
**`edgbaked-xcheck.sh` asks which ABI a GENERATED CORPUS is baked
for**, which is a different question from any of the above: EDG's C
back end folds `sizeof` into integer literals, so the 2.9M lines can
only be built by a compiler that lays those structs out the same way.
91 sites, named by the one shape that carries its own type
(`((T *)(alloc_fe(NULL)))`), each against the DWARF of a real
`gcc -g -c`: **83 agree, 4 arrays, 4 disagree — `+8`, `+8`, `+24`,
`+8`.** *One direction and one modulus is the finding, not the four
names* — the corpus wants `long` to be 4 bytes, which kencc is and gcc
is not. **So the host-built cpfe is sound for compile-time questions
and VOID for anything at run time**, the same bargain `hostkencc`
strikes; `docs/notes/edg.md` has the watchpoint chain that proved it,
and the thing it replaced was a confident reading that the crash was
the static-init gap. Its `array` column is a HEURISTIC, reported and
not counted, and **its control has two halves because the first alone
passes for a regex that matches everything**.
**`munmaptrim-xcheck.{c,sh}`** is the one that checks a function's
BOOKKEEPING rather than its arithmetic: the script cuts `p9_munmap` and
its table out of `__p9_syscall.c` **by marker** (never transcribed, and
it gates if a marker stops matching) and links them against a fake
`_SEGDETACH` that records what was released. *The bug it guards is not
a crash in the function but the function freeing a segment the caller
is still using*, which is invisible from inside and expensive from the
VM. No external oracle, so its control is a deliberate break and has
been run **four times**: the old start-address-only rule gives **8**
failures, the old `_SEGDETACH` fallback **2**, deleting the malloc
arm's page round-up **1**, and `*basep = p` **3**.
***AND THAT LAST ONE GAVE 0 THE FIRST TIME.*** Its sections read
`mmap_table[0].base` and then checked that what was released matched
it — both sides from the same field, so it held however wrong the
field was. The harness wraps `malloc` now, as it already wrapped
`free`. *The assertion had been phrased against the thing under test
instead of against something independent of it*, which is the shape
to look for when a break does not fire.
**`makectx-xcheck.{c,sh}`** checks `makecontext`'s FRAME on the host,
and **it compiles the real `ucontext.c` rather than a copy** — no
extraction and no markers to rot, which is possible only because
everything structural in that file is C and the assembly knows just
"eight slots". It exists because the one number spanning the two
languages (where the ucontext pointer sits in the new frame) fails
SILENTLY on the VM. No external oracle, so its control is a deliberate
break: the cell off by one gives **3** failures, `SP` not one slot below
**1**. ***Its first run reported its own STUB***: the real
`_setmcontext` never returns, the fake recorded and returned, and
section 3 duly failed — *the assertion was right and the fake was
wrong*, which is the shape to recognise rather than argue with.
**`hostkencc/clisp-mirror.sh` stages clisp's generated tree on the
host** so the host kencc can compile and inspect it -- `--flags` prints
the compile line, `--compile` builds all 31 TUs and GATES. *Its
`intparam.h` is a MODEL*: the probe is built with gcc, so
`long_bitsize` is patched 64 -> 32 afterwards, and leaving that out
makes `oint` 32 bits and wastes a round concluding the object
representation is broken.
**`hostkencc/php-mirror.sh` is its php counterpart and `--compile`
answers `compiled 514, errors 0`** -- the whole php build, by a
host-built `6c`, in about a minute. ***UNLIKE clisp's THERE IS NOTHING
TO STAGE***, since php's generated parsers, scanners and
`zend_vm_execute.h` all ship in the tarball -- so the file is the FLAG
SET and the source list, **both DERIVED from `cmd/php/mkfile` with
sed** (`DEFS`, `INCS`, `PCRE2FLAGS`, `KECCAKFLAGS`, `OFILES`), with a
gate if a variable comes back unexpanded. It replaced eight rounds
that each cost a VM rebuild to learn about ONE compile error; its
first run returned all eight at once. **Its own two faults are the
shapes to recognise**: it matched the Keccak flags on the DIRECTORY,
which reads like the mkfile's rule and is not it
(`ext/hash/hash_sha3.c` takes them too, from `ext/hash`), and it
passed `CFLAGS` through, whose leading **`-c` means "compile only" to
`pcc` and "print `const if`" to `6c`** -- dozens of lines that read
exactly like diagnostics.
***AND `--undefined` ASKS THE LINK'S QUESTION WITHOUT A LINKER, WHICH
THIS PARAGRAPH FIRST SAID IT COULD NOT***: `6c -S` names every symbol
each unit DEFINES (`<>` marks a file-local one) and REFERENCES, so
references minus global definitions minus each unit's own statics,
over all 515, is what `6l` would complain about -- handed to
`apfunc-sweep.py` for "does libap have it". **READ, do not gate**: the
sweep sees C function definitions only, so assembly reads as
`declared` and DATA as `absent` (ten of php's 283 are one or the
other, all present). *Its positive control is one command and names
the three symbols the VM's `6l` actually named.*
***AND `hostkencc/` BUILDS ALL TEN C COMPILERS WITH gcc***, from the
shipped `sys/src/cmd/cc` and `[1-9kqv]c` plus go1.4's `lib9`/`libbio`,
already vendored at `sys/src/external/go1.4` — which **compiled with gcc
on the first attempt, 89 objects, no diagnostics.** `--probe` runs the
ten-backend construct sweep this tree otherwise does on the VM and
**reproduces the recorded answer exactly** (ten compile `regpair-min`,
eight compile `regpair-probe`, `kc` and `vc` fail at `:242`). It found
two real defects at once: `cc.h:47`'s `NVAR` (a latent out-of-bounds
write once `ulong` is not 32 bits) and three backends declaring
`swcmp(void*,void*)` against the shared definition's `const`. **LP64
host against an LLP64 target**, so sound for compiles/crashes/diagnostics
and for A/B of two builds of the same sources, UNSOUND for anything
keyed on `long` being 32 bits — `specbits-model.py` still exists for
that. ***`agree.c`, THE CODEGEN CONTROL, HAS BEEN RUN AND PAID FOR ITSELF ON
THE FIRST DIFF***: 131 lines each, and `widecase` differed
SEMANTICALLY — the host emitted `CMPQ BP,$4294967296`, **an immediate
x86-64 does not have**, because `6c/cgen.c`'s `immconst()` tested
`n->vconst == (vlong)v` with `long v`, a round trip that answers "fits
in 32 bits" only where `long` IS 32 bits. `int v` now (same number on
Plan 9), and `widecase` matches instruction for instruction. *The
second member of the family `NVAR` opened, and the one that mattered.*
**What remains is the ORDER of commutative terms** in two functions —
identical multisets, same value — from `cc/scon.c`'s `acom2`, whose
comparators tie-break on **the addresses of the array elements qsort is
permuting**, so the order is whatever the host's qsort does. *Not
fixed*: a stable tie-break would change every binary's code on Plan 9
for no correctness. **So codegen from the harness is sound with one
named exception**, and a diff showing anything beyond those two
orderings is a finding. ***And the qsort mechanism was "refuted" first
by a control that could not separate the hypotheses*** — an insertion
sort agreed with glibc because both reverse runs of ties.
**The LINKERS are deliberately not built**: `[1-9]l/pass.c` uses
`sizeof(long)` to size TARGET data. *Its first `--probe` reported all
ten passing, because kencc's `diag()` writes to STDOUT* — a check that
passed for the wrong reason, caught only by the recorded number.
***AND `hostkencc/cxxlib-host.sh` COMPILES THE WHOLE C++ LIBRARY WITH
g++***, which is possible only because of the rename: with the
implementation namespace changed to `std`, `sys/include/ape/c++` is a
REPLACEMENT standard library, so `g++ -nostdinc++` puts it in exactly
cpfe's position. The one adaptation is the FILE NAMES — cpfe finds
`<algorithm>` as `algorithm.stdh` and the plain name is a DIRECTORY —
plus the four predefined macros cpfe has and gcc has not
(`__EDG_RUNTIME_USES_NAMESPACES` above all, without which
`class exception` lands in the global namespace). ***`--portable` AND
`--headers` ARE BOTH LOAD-BEARING AND EACH WAS PROVED BY A RUN THAT
HID FAILURES***: g++ defines `__GNUC__` so a plain run takes the gcc
arm of all four selectors, and a combined TU stops at the error limit
— **combining the flags turned up ten failures the gcc-arm run had not
shown**, which is why the parser reads every word and not `$1`.
`--run` builds and executes the test. **Sound for everything that is
not cpfe itself**; it says nothing about the C output, the template
model or the ABI. It found `split_buffer.h`, which cpfe never reached.

***AND `cpp-xcheck/` IS THE CHEAPEST INSTRUMENT IN THIS TREE***:
`cpp-xcheck.sh` builds kencc's OWN `cpp` with gcc on the build host and
diffs it against `gcc -E`. **`cpp` needs eleven Plan 9 names in total**
— about sixty lines in `p9/` — so preprocessor questions do not need the
VM, which *three probes and five refuted readings were spent not knowing*.
`hideset-cases.c` holds the cases and `R8`-`R11` are **C99 6.10.3.5
EXAMPLE 3 verbatim**; `--regress A B` diffs two builds of cpp over real
files (clisp's 31 TUs, and all 1128 `.c` under `lib/ap`). *Sound for
TOKEN questions only* — the binary is gcc's, so ILP64 where kencc is
LLP64, and `#if` arithmetic stays the VM's. Its root guard fired on its
own first run, for the FOURTH time: this directory is four levels below
the root, not three.
***Several of these need TWO compiles*** and the reason is the same every
time: a `-D` that renames libap's function out of the reference's way
applies to the CHECKER as well, and the sweep then compares libap against
itself and reports a clean number. *Break the unit on purpose and check
that the instrument notices.*

**Sweeps** — `apdecl-sweep.py` (a call whose non-`int` return type
nothing declares), `apehdr-sweep.py` (every `sys/include/ape` header
standalone, plus a TOGETHER case for collisions only a combination can
show), `rceq-sweep.py` (**gates**: a bare `=` in an mkfile recipe cannot
parse. ***ITS `RULE` WANTED TWO COLONS AND SO READ ONLY ATTRIBUTE
RULES*** — `install:V:` and nothing else — so every ordinary
`target: prereq` recipe in the tree was invisible to it: **870
recipe lines before, 1859 after**, with 0 findings both times. *A
gating sweep reporting 0 over lines it cannot see* is the failure its
own header already warned about for backquotes. **Found by control,
not by reading**: a bare `=` planted in `cmd/php/mkfile`'s `clean:V:`
was reported and the same `=` in one of that file's `%.$O:` rules was
not — *planting the break in one place would have passed*, which is
why `--control` now covers an attribute rule, a PLAIN rule and a
backquote, plus two that must NOT fire, and fails on exactly the
plain rule against the old regex), `mkcont-sweep.py` (**gates**: a logical line mk cannot parse. TWO
shapes, and *the second was added after the first reported 0 over
it*: a comment ending a continuation, and an INDENTED line that is
not a recipe — `cmd/php/mkfile` ended its `OFILES` at an ordinary
entry and left a tab-indented one orphaned five comment lines later.
**Recipes are the whole difficulty**, since every recipe body is
indented and has no `:` or `=`, so the discriminator is what the last
non-indented logical line was; `--control` carries one of each shape
*and a real recipe*, because a control without one would pass for a
version that reports every mkfile),
`ishadow-sweep.py` (does NOT gate — most hits are deliberate),
`hosthelper-sweep.py` (**does NOT gate, on purpose**: which mkfile
recipes run a binary the same mkfile builds, and whether it was built
with `hostcc`. A `no` is a QUESTION — a build-time helper should use
`hostcc`, a bootstrap stage cannot — so a gate would demand a change
that must not be made. Its first run **missed its own positive
control**, because it expanded `NAME=./thing` in recipes and not in
targets, and bash's rule is `$MKBUILTINS:`),
`bfmove-sweep.py` (which bit-field groups the sharing rule moves; a
LOWER bound, with an UNKNOWN column it reports rather than counts),
`apfunc-sweep.py` (**does NOT gate**: for each name, does libap
DEFINE it, only DECLARE it, or neither — **three states, and the
middle one is the point**, since a `config.h` claiming a
declared-only name link-fails far from the claim. `dlopen` and
`dlerror` are that state. Written for clisp's hand-answered
`config.h`; **its control caught two faults in two runs** — a `ROOT`
three `dirname`s deep where `sys/lib/tests` needs four, which made
every answer a confident `absent`, and a missing `\b` that reported
`setenv` as defined in `fenv/fenv.c` by eating the `fe` of
`fesetenv`. *The second is the worse shape: a hit, naming a real
file.* The control checks WHERE and not just whether, for that
reason),
`cfghdr-sweep.py` (**gates on ONE thing**: a `#define` in an
autoconf TEMPLATE that the hand-answered `config.h` does not carry.
`autoheader` emits only `#undef NAME`, so anything spelled `#define`
in a `.h.in` is text copied STRAIGHT THROUGH -- and *reading the
GENERATED config as a list of capabilities, which is how php's was
written, does not show it*. php's template copies three, and without
them `zend_map_ptr.h:82` answered `not a function` / `syntax error,
last name: ZEND_API`: an undefined identifier where a storage class
belongs, in a shape **every `ZEND_API` in php has**. 21 names were
missing in all. It does NOT gate on an unanswered `#undef` -- php's
template asks 696 questions and 474 are deliberately silent -- nor on
a name the answered file invents, which is reported because only the
author can tell a port's own addition from a typo. *It found one of
each on its first run*: `PHP_OS_FAMILY`, which `main/php.h:38` computes
itself so defining it was a collision, and five in clisp's config
that nobody has looked at. **Its LIMIT is that it reads names and not
arms** -- a `#define` inside a platform arm nobody takes is reported
though the omission is right -- so `PAIRS` holds only pairs whose
findings someone has read. **Its control caught two faults in two
runs**: the include guard is a `#define` like any other and was
demanded of the answered file, and a name the template both `#define`s
in a dead arm and `#undef`s elsewhere is a QUESTION rather than
verbatim text),
`asmout-sweep.py` (**does NOT gate**: 403 GNU extended asm sites
with an OUTPUT operand under `external/`, classified by their
enclosing `#if`. **278 are guarded by `__GNUC__`/`_MSC_VER` and so
are correct as written**, 97 are other-arch, and **28 are the
dangerous class** -- an x86 guard with no compiler guard, libwebp's
shape -- *of which not one is compiled by this tree*. It answers the
question a STRICTER compiler creates, "where would the next build
stop", and ***the answer was confirmed by a full `mk install`
completing*** afterwards. It cannot gate because nothing here reads a
mkfile. **Two of the 28 were already solved independently**: zstd's
`cpu.h` reads `!defined(Plan9)` and its mkfile passes `-DPlan9`, which
is corroboration the class is real. **Control in two halves** --
libwebp's pre-fix header out of git MUST classify X86-REACHABLE and
the current one must NOT, since the first alone passes for a
classifier that fires on everything),
`baketype-sweep.py` (**does NOT gate**: a vendored package
declaring an APExp `sys/` typedef ITSELF has taken a copy of the
platform ABI that no header change can reach. **50 disagree, 48
inside `#if` arms this platform never takes** (gnulib and friends),
and the unguarded ones are the class that bites: EDG's
`unsigned short ino_t/dev_t` made its `struct stat` 88 bytes where
libap's `stat()` writes 104, smashing cpfe's return address on every
input. *It found the second unguarded pair by itself.* **Limits are
in the header**: it reads `#if` TEXT not arithmetic, it searches BOTH
header roots because APExp has arch arms (`_ptrdiff_t` was a false
positive on the first run against the generic arm alone), and it does
not resolve alias chains. **Control in two halves** -- the pre-fix
`host_envir.c` out of git MUST come back UNGUARDED+divergent and the
current one must NOT),
`cxxbuiltin-sweep.py` (**GATES**, unlike `baketype-sweep`, because
there is no arms-nobody-takes problem: a `__builtin_x` reached with
no capability test is a hard error on any compiler without one, and
cpfe is one. It exists because the four compiler-identity SELECTORS
were fixed and called the whole class — the other half is a builtin
with no test at all, nine in `numeric_limits.h` and one in
`addressof.h`, and ***`cxxlib-host.sh --portable` could not see
them***. **Its control caught two faults in two runs**: it reported
its own explanatory PROSE (comments and string literals are blanked
now, `truefalse-sweep`'s lesson), and its sibling rule hardcoded
`builtin/`/`generic/` so it reported two files that are perfectly
guarded — upstream uses the same indirection as `gcc_clang/`/`msvc/`
and `buildin_realization/`/`no_realization`, *a rule written from the
examples in front of you fires on the next naming convention*, so it
asks structurally now. One EXEMPT entry with its reason),
`truefalse-sweep.py` (**does NOT gate**: which vendored TUs use
`true`/`false` as an IDENTIFIER without defining the names themselves —
the shape kencc's C23 keywords break. **Its positive control is
EXTERNAL and has to be**, since the one package it found is already
fixed: `--control` stages the pre-rename `go.h` out of git and fires on
it. *Its pattern was widened twice before any number was written down* —
8148 hits when `return true;` matched, 379 when block-comment
continuation lines did, 3 once comments and literals are blanked).

**Models** — `clitzero-model.py`, `sualign-model.py`, `bitinit-model.py`,
`specbits-model.py` (after the `a68335214` merge: do the specifier
bits still fit a 32-bit `long`, and does anything alias? It READS the
enum out of `cc.h` rather than transcribing it, and **`--old` replays
the numbering the merge replaced**, which is what makes the headroom a
number: `TNORET` was `1L<<31` with **0 shifts spare**, and `TCFLOAT`
aliased `TAUTO` and `TCDOUBLE` aliased `TEXTERN`).
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
`cppelif-probe` and `cppskip-probe` (**`pcc -c`, result is whether
they COMPILE**, and BOTH are measured now. ***`cppelif-probe` passes:
cpp's skipping is FINE*** — `#elif` after `#ifdef`, after
`#if defined()`, and `asm volatile` with extended operands in a
skipped arm are all skipped correctly, so *the mechanism it was built
to catch does not exist* and `unix.c:851` had another cause, still
unexplained and no longer live. **The clue it was built on did not
hold either**: two `[stdin:N]` numbers ten apart were read as proving
cpp emitted the skipped arms, and they prove nothing, because cpp
removes lines AND inserts `#line` directives. ***`cppskip-probe` is
the one that found something***: cpp tokenises skipped blocks: an unterminated quote or a bare
apostrophe inside `#if 0` is a hard error under kencc and a warning
under gcc, *so prose containing `don't` inside an untaken arm will not
compile here*. **They are two files because one killed the other**:
cpp aborted on that line and `6c` never ran, so the other three cases
were unreported rather than cleared — a case that can kill the
preprocessor belongs in its own file, the same rule this tree has
about cases that can hang. The macros are INVENTED because the first
draft used `__x86_64__`, which gcc defines, so the arm meant to be
skipped was compiled),
**`asmout-probe` and `asmok-probe`** (**`pcc -c`, and the result is
whether they COMPILE — the first MUST FAIL and the second MUST
NOT.** *Neither is readable alone*: a compiler that refused every
`__asm__` would pass the first and break php's 50 files. kencc
swallows `__asm__ ( ... )` whole, which for a barrier loses a FENCE
and for an asm with an OUTPUT operand loses the VALUE — `6c -S`
emitted `MOVL swapped_bytes+-4(SP),AX`, *a read of an uninitialised
stack slot returned as the answer*, with only a `used and not set`
warning that reads like dead-code noise. Reachable because **APExp
defines `__x86_64__` itself**, which is right for architecture
questions and is also how a package picks its x86 asm; `__GNUC__` is
defined by nobody here, which is why packages guarding on the
COMPILER were never affected. Blast radius measured with `hostkencc`
BEFORE shipping: php 581 TUs 0 errors, libwebp 7 of 125. Two files for
the `cppelif`/`cppskip` reason, and `asmok-probe`'s WARNINGS ARE
EXPECTED — read the exit status),
`cppaste-probe` and `cpplimit-probe` (**BOTH ANSWERED AND BOTH
NEGATIVE, kept as regression ladders.** `cppaste` is 7 paste shapes,
`cpplimit` is a token limit (16405), a length limit (135221 chars) and
two-CONCATs-per-expansion — *three probes built UPWARD from guesses,
three negative results.* The fault was the HIDESET and
`cppclisp-probe` — the real `GEN_F_op2` copied character for character,
built DOWNWARD from the source — reproduced it on the first run.
**And the correlation these files were built on was an ARTIFACT TWICE
OVER**: the twelve residual `CONCAT`s are at `flo_rest.d:303`/`:310`
inside `GEN_LF_op2_0`, two per `s=0` call site, not at the six sites
these notes named — *six pairs cannot make twelve, and twelve was
already written down*),
`regpair-probe` and `regpair-min` (**native, and their result is
whether they COMPILE** — the bug they found is FIXED, so they are
regression tests now, and **the only things here that ask a non-amd64
backend anything**: run both against all ten `[1-9kqv]c` after any
change to `cc/`'s type tables),
`tagconst-probe` (**native, `6c -S` AND `6l -l -a`, and its answer is
now fixed**: `MOVQ $subr_tab_data+281474976716536(SB)` from both. It
was built with THREE outcomes rather than two, because compiler,
object file and linker each lose a wide link-time constant with the
same symptom — and the third is the one that happened. *Its first
command refuted the reading the file itself was written on*),
`devreg-probe` (**no host form and `pcc` only** — which files APE calls
regular and whether `select()` then reports them readable; the subject
is what *rio* serves, so run it in a rio window with no wish running,
and note that it never READS any of them, since reading `/dev/mouse` is
the call that hangs),
**`mmaptrim-probe`** (**ANSWERED, and the answer it was not built to
ask is the one that mattered.** Section 0: *0 of 8* 2MB mappings come
back 2MB-aligned, every one misaligned by exactly `0x1ff000` — a 2MB
grid, off by one page — so php's Zend allocator does trim; sections 2
and 3 say both trims survive. **But three of the eight `mmap` calls
FAILED**, and 10MB is not a memory limit, so **section 0b** asks how
many mappings a process may HOLD, at three sizes, *with the prediction
written down first*: slots give the same count at every size, address
space gives one falling as 1/size. It was **5 at 2MB and 5 at 16MB**,
and 64 at a size below `SEG_THRESHOLD` — the control. ***AND THE FIX
DISARMED IT***: with `SEG_THRESHOLD` at 64MB all three of 0b's sizes
take the malloc arm, so it answers 64/64/64 — right, worth keeping as
the regression check that `mmap` spends no slot, and *unable to say
how many slots exist*. **Section 0c** asks the platform instead,
`_SEGATTACH` in a loop at 64KB: **5**, the same number over a 256-fold
range of sizes for a total of 320KB, which excludes memory outright.
*A section whose cases have collapsed onto one path is a check that
can only pass.* **Two of its
sections can kill the process, so it takes an ARGUMENT**: no argument
runs the tail trim, `3` runs the head trim, never sharing a run,
because a section that can kill the process hides every section after
it. Calls `_mmapmark`, since a probe built against stale library code
reports a lie shaped like the platform's answer), and
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

**rc harnesses** live in **`sys/lib/tests`** beside everything else --
*this line said `rc/bin` and that was wrong; only `fdwatch` and
`vts-bash` are there* -- namely `bash-runtests` (which prints its own
validity line FIRST and refuses the result if it is not 0), the five
ladders `bash-scriptladder`, `bash-forkladder`, `bash-ifsladder`,
`bash-fileladder`, `bash-lineladder`, and **`go-ladder`** (**does NOT
gate, on purpose**: seven rungs from `go version` to
`go test sort strings`, and the useful output is the HIGHEST RUNG
REACHED, which a gate would throw away at rung 1. Rungs 4 and 5 are
split because *a linker can emit a file that is not a working
program* -- `miniperl`'s gap -- and rung 7 is the first that measures
CORRECTNESS rather than plumbing. `$GOROOT/src/run.bash` is the real
suite and is deliberately NOT a rung, because it can hang and a ladder
whose last rung hangs cannot be read for position). **They are rc on
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

**portable_stl: MERGED, and one of the two "no"s this paragraph used to
carry was wrong.** The install question stands: its `CMakeLists.txt` has
**no `install()` rule and no `configure_file`** — the single target is
the gtest binary, so *the headers are the product* and installing is a
copy, which is what was done (`sys/include/ape/c++`, 80 entries, plus
`.stdh` public entrypoints for the common headers).
***THE NAMESPACE ONE WAS WRONG AND IS WITHDRAWN.*** This file said the
implementation namespace "cannot become `std`" because the library
already declares `namespace std` itself for `initializer_list` and
`type_info`. That is true and is **not an obstacle**: those two are
declarations the core language requires in `std`, so after the rename
they simply coincide with the rest of the library instead of sitting
beside it. *A fact about the code was read as a conclusion about the
change.* It is `std` now.
**What does NOT go away is the convention underneath**, and that was
the half worth keeping: `vector::push_back` returns
`expected<void, ...>` because the library is exception-free by
construction, so this is a usable library and **not a drop-in `std`**.
`docs/notes/cxx-library.md` has the limitations and the conformance
roadmap.

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

**The clisp campaign — A WORKING PORT NOW, still out of the default
build.** It is kept as its own section rather than folded into the list
below because the nine bugs it flushed out are the reason the list
below is shorter than it was, and four of them were in the COMPILER and
silent:
- **clisp** — ***THE NEXT STOP WAS A KENCC PREPROCESSOR BUG AFFECTING
  EVERY PACKAGE IN THE TREE, AND IT IS FIXED.*** `lisparit.c` answered
  `flo_rest.d:338 name not declared: TO_F_`: `cpp/expand()` painted a
  macro's expansion with `HS(name) | {macro}` where Prosser's algorithm
  specifies `(HS(name) & HS(')')) | {macro}` for a CALL, so **a macro
  whose NAME was manufactured by `##` carried the paste machinery's own
  hideset into its body** and any macro that helped build the name
  stayed hidden there for good — clisp's two-level `CONCAT`, twelve
  times. **The first half of the fix HANGS**: with the intersection but
  the old NAME-only painting, a `)` written in a macro body has hideset
  0, so mutually recursive `a(x)->b(x)`/`b(x)->a(x)` preprocesses for
  ever; the loop now paints `NAME` and `RP`, which are the only two
  types whose hideset is ever read. ***AND THE FIX CAME WITH A 27x
  SPEEDUP***, because painting RP made an EXISTING cost visible —
  `newhideset` compared its candidate against every hideset seen so far,
  quadratic per file — so it is hash-interned now: `spvw.c` 15429ms ->
  579ms. *A correctness fix whose cost exposed a bigger win than the fix
  itself.* **The instrument matters more than the bug**: see
  `cpp-xcheck/` above, which was available for the whole campaign while
  these notes said kencc "cannot be compiled on the build host at all" —
  true of `cc/` and the backends, generalised to a directory it did not
  cover. *Check which sources actually need `<u.h>` before accepting
  that a question needs the VM.*
  `config.h` is hand-answered, `ARCHDEF` covers every `$objtype`.
  ***PAST `lisparit` NOW, AND THE SECOND OF THE THREE BLOCKERS WOULD
  HAVE BUILT AND NOT WORKED.*** (1) `modules.c` wanted the GENERATED
  `clisp.h`; `makemake.in:2606` takes that only for
  `unix && !cross` and otherwise passes **`-DNO_CLISP_H`**, which
  includes `lispbibl.c` like every other `$CPARTS` file — upstream's
  own route, and right here because `clisp.h` is for EXTERNAL MODULE
  WRITERS and this port is `--without-dynamic-modules`. (2)
  **`lispbibl.d`'s `bit(n)` is `(1UL<<(n))` and `wbit` falls back to
  it**, while `WIDE_HARD` (defined for AMD64) puts the type tags at
  bit 48+ — `cons_bit_o` is 54. On every other `WIDE_HARD` platform
  `unsigned long` is 64 bits so the fallback is fine; **kencc is the
  first LLP64 one**. *Measured*: `x & (1UL<<54)` folds to `MOVL $0,AX`,
  so `consp`/`atomp`/`symbolp` were all constant false in a GC'd Lisp.
  Widened at `bit`/`bitm`/`minus_bit` rather than at `wbit`, because
  `constant_var_p` reaches the same hazard through `header_flags`
  without touching `wbit` — two families, one cause — and because
  widening there makes kencc agree with LP64, where `bit()` is already
  64-bit. (3) `config.h` said `/* #undef vfork */`, which is autoconf's
  "vfork WORKS" answer; APExp has none, so `#define vfork fork` (its
  own fallback). *The prose beside the macro already said "vfork is not
  provided"* — the hand-answered-capability shape again, after
  `VALID_FILENAME_CHAR`.
  ***AND THE GC CRASH WAS `~0UL`, THE SAME LLP64 FAMILY A THIRD TIME.***
  `lisp.run` ran, got to `init_subr_tab_2`, and died in `gc_mark` with
  a general protection violation; acid showed `DX = BP =
  0x000100000041a7c0` — `subr_type` 0x01 over a good heap address —
  being dereferenced at `6(DX)` with **no mask**.
  `lispbibl.d:4010`'s `hardware_addressbus_mask` is `~0UL`, which means
  "nothing is dropped" and is 64 bits on every LP64 platform CLISP is
  built on; under kencc it is `0x00000000FFFFFFFF`, so the tag bits read
  as *dropped by the address bus* and `type_pointable()` takes its
  UNMASKED arm. On a 68000 or an Alpha that is upstream's intended
  optimisation; x86-64 traps on a non-canonical address.
  ***THE SAME EXPRESSION IS EVALUATED TWICE, TWO WAYS***: the `#elif`
  that selects the form tests the mask in the PREPROCESSOR, where `#if`
  arithmetic is 64-bit, decides the mask is needed and emits a runtime
  check — which the COMPILER then evaluates in 32 bits and answers the
  other way. *A constant that disagrees with itself between cpp and cc.*
  Fixed as `0xFFFFFFFFFFFFFFFFUL` (upstream's own spelling at `:2768`);
  1087 sites move to the masked form and `gc_mark` now ANDs with
  `0x0000FFFFFFFFFFFF` before dereferencing.
  ***AND I HAD WAVED THAT `~0UL` THROUGH A ROUND EARLIER***:
  `STACK_ADDRESS_RANGE`'s `~0UL` was checked and correctly cleared
  because it occurs only in `#if` — and the verdict was generalised to
  the other `~0UL` eleven lines away, which is used in a C expression.
  **A verdict about one use of a constant is not a verdict about the
  constant.**
  **All 31 TUs compile clean under `hostkencc` (`6c -J -p`)**, and
  ***`lisp.run` LINKS AND RUNS***. `base:V:` is now the three-stage bootstrap
  from `makemake.in:2870-2920` — `interpreted.mem`, then
  `compiler.fas`+`halfcompiled.mem` (*the same command as stage 1
  re-run*: `LOAD` prefers a `.fas`, so the image comes back with a
  compiled compiler), then `lispinit.mem` from `init.fas`.
  **Nothing needs installing first**: `init.lisp` loads by BARE NAME,
  so `-lp <srcdir>` plus the build dir as cwd resolves everything and
  `-o ./` lands the `.fas`; *the one file that must be created* is
  `config.lisp`, a copy of `cfgunix.lisp`. **The 86-name list is
  DERIVED from `makemake.in`'s own shell, not transcribed** — run with
  this port's settings and diffed against the mkfile, 86 and 86,
  identical including order, and each feature test matches a `#+`
  guard at the end of `init.lisp`.
  ***STAGE 1 COMPLETES.*** `interpreted.mem` is built: every file in
  the 86-name list loads, `config.lisp` last, the GC stats print and
  it exits clean. So the derived list and the whole `-lp`/`-o ./`
  arrangement are measured rather than swept, and the three
  wide-constant compiler bugs plus `mkvar` were what stood between
  `lisp.run' running and the bootstrap working. **Stage 2 now stops
  compiling `compiler.lisp`**: `trap: fault read addr=0x1a`, a small
  offset off a null-ish pointer, unattributed.
  `sys/src/ape/cmd/clisp/debug-stage1` runs stage 1 with
  `EXT::SHOW-STACK` armed; its header carries the three ways the
  invocation was got wrong by hand.
  ***AND `-J` IS NOT OPTIONAL WHEN `6c` STANDS IN FOR `pcc`***: without
  it `stream.d:17311` answers `duplicate cases in switch 8`, because
  `sizeof(ffloatjanus)` is 4 under `-J` and 8 under the 9front rule.
  *That was written down as a clisp bug before the flag was checked.*
  Historically: `configure` reaches `C compiler cannot create executables`
  under hundreds of `5: Bad file descriptor`, and the fd mechanism is
  **cleared** (`execfd-test.sh`, 11 sections, 0 failures), so that is a
  configure that could not write its own log. **`config.h` is
  hand-answered now** (`cmd/clisp/config.h`), and `configure:V:` builds
  and RUNS upstream's own `intparam`/`floatparam` probes for the other
  two generated headers — *those must not be hand-answered and must not
  use `hostcc`*, because they measure the compiler and kencc is LLP64,
  so a host run reports the wrong widths rather than none.
  ***AND THE STRONGER REASON TO HAND-ANSWER IS THAT A WORKING CONFIGURE
  WOULD GET THIS MACHINE WRONG.*** `mman.c:44`'s `mprotect` is
  `return 0` — a stub answering SUCCESS — so a configure probe passes
  and sets `HAVE_WORKING_MPROTECT`, which `lispbibl.d:3013` reads to
  switch on the GENERATIONAL GC, whose write barrier is page protection
  plus SIGSEGV. *The barrier would never fire and the collector would
  free live objects.* The memory model is forced the same way and is
  not a preference: `p9_mmap_impl` refuses `MAP_FIXED` to an address,
  so `SINGLEMAP_MEMORY` is impossible, and a mapping cannot grow in
  place, so `TRIVIALMAP` is too — `lispbibl.d:4259` then selects the
  malloc-backed `SPVW_BLOCKS`/`SPVW_MIXED`, a supported upstream mode.
  ***AND THE FOURTH LLP64 ONE WAS `(long)&x` ON A STACK ADDRESS.***
  `lispbibl.d:9320`'s `sp_jmp_buf_to_jmp_buf` rounds the address of a
  local `sp_jmp_buf` and hands it to `setjmp`; `(long)` truncated it
  and the compiler sign-extended it back, so
  `0x00007ffffffde498` reached `setjmp.s:34`'s `MOVQ SP,0(BP)` as
  `0xfffffffffffde498` and faulted. **The registers named it before
  the stack did** — `SI` held the true address and `BP` its low 32
  bits sign-extended, to the digit — and *a STACK address is what made
  it visible*: non-canonical, so it traps, where a heap pointer
  mangled the same way would have scribbled and survived. `uintP`
  now. **The control is `6c`'s own output**: `MOVQL BP,BP` then
  `MOVLQSX BP,BP` around the `ANDL`, and neither after. **A sweep
  found no second LIVE site** — the other `(long)`-on-an-address casts
  are in `foreign.d` and `MULTITHREAD`, neither of which this port
  compiles.
  ***ALL THREE BOOTSTRAP STAGES COMPLETE AND IT INSTALLS.***
  `lispinit.mem` is 3,048,296 bytes. `install` lays out
  `$objtype/lib/ape/clisp/{base,data}` — `lisp.run`, `lispinit.mem`,
  and the two data files, which are **already tracked source**
  (`utils/unicode/UnicodeDataFull.txt`, `doc/Symbol-Table.text`), so
  nothing needed pre-installing. `linkkit`/`build-aux`/`full` are for
  EXTERNAL MODULES and `--without-dynamic-modules` rules them out.
  **`rc/bin/ape/clisp` replaces upstream's `clisp.c` driver**, whose
  only job is to find its own executable and supply `-B`/`-M`:
  `execname.c:153` is `#error "not implemented: find_executable()"`
  for every platform it does not know, and rc says the same thing in
  one line *and* stays architecture-independent, because `$objtype` is
  a runtime variable where `-DLISPLIBDIR` would have been baked in.
  ***AND IT EVALUATES LISP***: `clisp -x '(print (+ 1 2))'` answers
  `3`. **It answers it TWICE and prints the banner, and both are
  upstream's**, checked at source rather than assumed: `-x` forms go
  to `SYS::MAIN-LOOP` through a string input stream (`spvw.d:3601`),
  which is a read-eval-PRINT loop, so `print` writes 3 and the REPL
  echoes the returned 3; and `argv_verbose` defaults to 2
  (`spvw.d:2418`) with `print_banner()` at `>=2` (`:3316`), suppressed
  automatically only for `SYS::*QUIET*` or batch mode. For a script,
  `clisp -q -x '(progn (print (+ 1 2)) (values))'` — no banner, and
  zero values means no echo.
  **NOT in `_OPTIONAL_APPS` yet, and the blocker is now purely the
  BUILD COST**: `install` depends on `build` depends on `base`, a `V:`
  target, so a tree-wide `mk install` would re-run the whole
  three-stage bootstrap every time. Making `install` depend on
  `$BUILD/lispinit.mem` as a FILE instead is the change that would
  make enabling it cheap.

**Ports built and running**, each with what is NOT measured:
- **go** — ***SIX OF SEVEN RUNGS, INCLUDING THE CORRECTNESS ONE.***
  `sys/lib/tests/go-ladder` reports: `go version go1.4.3 plan9/amd64`;
  GOROOT/GOOS/GOARCH/CGO_ENABLED all as `-DGOROOT_FINAL` baked them;
  **`go build` and the binary RUNS**; `go run` runs; and
  **`go test sort strings` is `ok` for both** — upstream's own
  assertions against this compiler and runtime, which is the first
  thing in this port that is a capability rather than a stage.
  *Rungs 4 and 5 are separate deliberately and both passed, so this is
  not `miniperl`'s gap.*
  **The one failure is `go list std`**, and it is specific rather
  than general: the GC reports `invalid heap pointer`, and the span
  it names is `0x8d0c000-0x0-0x8d10000` with the object INSIDE it —
  `start<<PageShift` and `(start+npages)<<PageShift` are both right
  and **`s->limit` is 0**, which alone fails `mgc0.c:379`. `limit` is
  written in only two places (`malloc.c:391`, `mcentral.c:204`), and
  since `start<<PageShift` printed correctly either would have given
  a non-zero value. The stack is `scanstack` → `gentraceback` →
  `scanframe`, i.e. the bad word was found **scanning a goroutine's
  frame**, under `os.(*File).readdir` (`os/dir_plan9.go:15`) —
  go's own Plan 9 directory path, walking the whole of `$GOROOT/src`.
  ***THAT `go test` PASSES REFUTES "the collector is broken"***: those
  test binaries allocate and collect freely. So this is one path, not
  the runtime.
  ***`GOGC=off go list std` PRINTS 156, THE RIGHT NUMBER***, so the
  heap data is fine and it is purely the collector on that path.
  ***AND THE OBVIOUS READING OF THAT MESSAGE IS WRONG***: `state=2`
  is `MSpanFree` (`malloc.h:404`), and a free span having `limit` 0
  is simply what a free span looks like — *the field that looked
  broken was the one field behaving*. What it actually says is that a
  word in a goroutine FRAME was scanned as a pointer and points into
  FREED memory; go1.4 scans stacks PRECISELY, so a non-pointer is
  scanned only if that frame's STACK MAP claims the slot is one.
  ***AND THE READDIR PATH IS INNOCENT***, measured:
  `sys/lib/tests/go-readdir-probe.go` walks `$GOROOT/src` with
  `runtime.GC()` every 200 entries and completes — 297 dirs, 2759
  files — **both with the GC on and with `GOGC=off`**. So the frame
  that is scanned wrongly is elsewhere in `go list std`
  (`go/build`, the package graph, `matchPackages`), and
  `os/dir_plan9.go` being at the bottom of the traceback was where
  the GC happened to fire, not what caused it. *The obvious
  candidate was refuted by the cheapest instrument available.*
  **Whose bug it is is NOT established**: go1.4's plan9/amd64 port was
  new and thinly exercised in that release, so upstream is a live
  candidate beside `6g`/`6l`, which this tree's `pcc` builds and which
  this release found four silent miscompiles in. **Out of the default build**; four earlier
  stops were all this tree's own mkfile (the `bool` keyword, a missing
  `-c`, Makefile backslashes in a `-D`, `-DPLAN9` doing two unrelated
  jobs) and are long past.
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
  ***IT CRASHED ON EVERYTHING, INCLUDING AN EMPTY FILE — FIXED, see
  the `struct stat` entry above; the bracketing below is kept because
  it is what found it.***
  `sys/lib/tests/cxx-bisect`'s case 0 — an empty translation unit, run
  before any header — answers `fault read addr=0x1 pc=0x1`, so **this
  is not about the C++ headers** and the 35 header runs after it would
  only reprint one crash. *That is what the case-0 control is for*: a
  bisect that cannot say "everything fails" cannot tell "this header
  breaks cpfe" from "cpfe is broken", and the first version of the
  script went straight to the headers.
  ***`cpfe-ladder` BRACKETS IT: `--version` WORKS AND `-E` CRASHES.***
  A bad option is diagnosed, `--version` prints, and then
  **preprocessing an empty file dies with `pc=0x1`** -- so semantic
  analysis, IL and the whole C back end are cleared in one line. *Its
  rung 3 was mine to get wrong*: bare `-E` answers
  `check_target_config: must use SoftFloat library`, the DOCUMENTED
  refusal without `--target win64`, so it measured a missing flag
  rather than the preprocessor.
  ***AND IT IS FOUND: EDG's OWN `struct stat` WAS 88 BYTES AND libap
  WRITES 104.*** `cmd/edg/mkfile` passes **NO -I and NO -D** -- "each
  file declares everything it uses" -- so the generated corpus carries
  its own `typedef unsigned short ino_t/dev_t` and its own
  `struct stat` built from them, member-identical to APExp's. **This
  release widened both to `unsigned long long`** (64-bit qids,
  `struct stat` 88 -> 104) and *a header change cannot reach a copy*.
  `get_file_modification_time` puts that 88-byte struct ON THE STACK
  and `stat()` writes 104 -- sixteen past the end, over the return
  address, which is exactly why the fault is `pc=0x1`: Plan 9 has no
  stack protector, so a smashed return address is returned to.
  **Measured with the host `6c`: 88 old, 104 new, 104 for APExp's real
  header.** Fixed in five files. *It accounts for every observation
  the ladder made*, above all the one rung that PASSES -- a
  nonexistent file makes `stat()` fail, so nothing is written and
  nothing is smashed. **`baketype-sweep.py` is the general form**: 50
  vendored declarations of an APExp `sys/` typedef disagree, 48 inside
  `#if` arms nobody takes, and the sweep found the second unguarded
  pair (`util/edg_prelink.c`) that I had missed by hand.
  ***AND RUNG 3, A NONEXISTENT INPUT FILE, PASSES*** -- so the 27
  `fe_translation_unit_init` calls (direct, no function-pointer
  dispatch), `fe_init_part_2` and the LEXER's own `fopen`
  (`lexical.c:30694` -> `host_envir.c:10072`) all ran, and **the fault
  is after the source is successfully opened**, on a path common to
  `-E` and full translation, independent of content. *That also
  clears `mmap`*, which this release changed heavily:
  `open_mapped_input_file` serves PCH and IFC modules only, never a
  source file -- checked, because "EDG maps its input" is a plausible
  sentence and is not true. **Its pass condition had to be tightened
  first**: any non-zero exit passed it, which a command-line error
  gives too, so it now requires a diagnostic NAMING the file. Every
  crashing rung also reports its stdout byte count now -- cpfe emits
  a `#line` before any token, so 0 means it died before the first
  emit and non-zero means inside the output loop.
  ***A FULL REBUILD DID NOT MOVE IT, AND `regs()` SAYS WHY IT WILL
  NOT.*** `PC` is **1 exactly**, `TYPE` 0xe with `ERROR` 0x14 decodes
  to a user-mode **INSTRUCTION FETCH**, and `SP` is an ordinary stack
  address -- so this is a CALL through a function pointer holding 1,
  not a dereference and not the stack. **A table entry of 1 is not an
  uninitialised one** (a static-init gap leaves zeros), and EDG's
  generated C indexes functions by `a_function_number`, so a function
  NUMBER reaching a call site where a POINTER belongs is the shape
  that fits. **`acid: src(*SP)` names the caller in one command** --
  the `CALL` pushed the return address before the fetch faulted.
  *That also refutes the cheapest of the three readings below*, which
  was the half-rebuilt corpus.
  **What bears on it otherwise is that TWO LAYOUT RULES HAVE
  LANDED since cpfe last translated a toy** — the bit-field
  head-sharing `follow` rule in `cc/dcl.c` and `gbitagg`'s static
  initialiser — and EDG's corpus **folds `sizeof` and `offsetof` into
  integer literals**, so it can only be built by a compiler that
  agrees with the one that generated it. `mk distclean` before
  `mk install` (a half-rebuilt 2.9M-line corpus with two struct
  layouts in it is exactly what a jump to address 1 looks like from
  outside), then `edgtuoff-probe` for whether pcc still puts those
  two members at 400/416, then `edgscope-probe` and
  `structalign-test`.
  ***THE HOST-BUILT cpfe CRASHES TOO AND IT IS A DIFFERENT BUG, now
  on a measured mechanism rather than an absence***: it needs `long`
  to be 8 bytes and kencc's is 4. `edgbaked-xcheck.sh` has the four
  short allocations and `docs/notes/edg.md` the watchpoint chain. *So
  the host build is sound for compile-time questions and void at run
  time*, and **the static-init gap is still open but has stopped being
  the suspect for either crash** — the only evidence pointing it at one
  was that backtrace.
  **Also open**: `__thread` silently dropped.
  ***THE CRASH IS FIXED AND THE C++ LIBRARY IS MEASURED FOR THE FIRST
  TIME.*** `cxx-bisect` answers **19 ok, 16 error, 0 CRASH**, and all
  16 are fixed. **Eleven of them were ONE SHAPE**: four files chose an
  implementation with `#if defined(_MSC_VER)` ... `#else /* clang and
  gcc */`, a split by COMPILER IDENTITY where the question is
  CAPABILITY — and cpfe is a third thing, defining neither `_MSC_VER`
  nor `__GNUC__`, so it took the gcc arm and reached `__integer_pack`,
  `__builtin_is_constant_evaluated` and `__LONG_LONG_MAX__`.
  `common/compiler_builtins.h` asks directly now. **Two of the four had
  no portable arm to select**: `make_integer_seq_generic.h` is new (the
  doubling recursion, whose obvious shape is ill-formed — a partial
  specialisation may not have a non-type argument whose type depends on
  its own parameter), and `limits_msvc/` turned out to BE the portable
  arm with only its directory name saying otherwise.
  The rest: `std::std_error` did not exist (the rename rewrote 21 USES
  and left the 1 DEFINITION), `using max_align_t = ;` was an alias to
  nothing, `<cstdint>` declared `imaxdiv_t` (`<cinttypes>`'s) and not
  `int32_t`, five names were re-exported from `::` into `std` that the
  library defines in `std` itself, EDG's C++98 `std::unexpected`
  function collided with C++23's class template, the **no-RTTI**
  `typeid_wrap` called `typeid`, and `move_algo.h` had a stray
  `template` disambiguator — **the one of the sixteen where cpfe is
  right and g++ is lenient**.
  ***AND THE SELECTORS WERE ONLY HALF THE CLASS***: the next VM run
  gave **27 ok, 7 error, 1 CRASH**, and all seven errors were a
  builtin used with NO test of any kind — nine `__builtin_nan`/
  `huge_val` sites in the SHARED `numeric_limits.h`, outside both
  limits directories, plus `memory/addressof.h`, which has no sibling
  at all. **`--portable` could not have caught them**: it forces the
  SELECTORS, and a bare `__builtin_x` answers to no macro while g++
  has the builtin — *a flag that forces the arms you know about says
  nothing about code with no arms*. `cxxbuiltin-sweep.py` is the
  instrument and it GATES. **A second hole was in the switch itself**:
  the new guards first read `|| defined(__GNUC__)`, true on the host
  whatever the flag says, so `PSTL_HAS_GNU_BUILTINS` exists —
  *a switch the thing it switches can ignore is not a switch*, caught
  by counting surviving builtins in `g++ -E` rather than trusting it.
  **`constexpr` went two ways on one rule**: APE's `HUGE_VAL` is
  `Inf(1)`, a CALL, so the portable arm is ill-formed NDR —
  `numeric_limits` DROPS the keyword (0 callers outside the file, so
  nothing cascades) and `addressof` KEEPS it (called from `constexpr`
  code throughout `functional/`). *Same rule, opposite answers,
  because the callers differ.*
  **All 50 public headers compile now on both arms** but `<compare>`
  and `<source_location>`, which `#error` because they are C++20 and
  `eccp` passes `--c++14`; `cxx-library-test.cpp` builds and runs clean.
  **The one thing NOT fixed is a `vector` CRASH**, and ***THE
  PREDICTION WAS REFUTED BY ITS OWN STATED CONDITION***: it was
  predicted to be error RECOVERY, the refutation written down was "a
  CRASH with 0 errors", and the next run was **34 ok, 0 error, 1
  CRASH**. *The seven headers that hit the identical error without
  crashing showed the error was not SUFFICIENT, and were read as
  showing recovery depth was the cause.*
  **`cxx-vecnarrow` then put it inside `vector/vector.h` itself** — no
  single include of that file crashes and no cumulative prefix of its
  56 does. ***And the shape of the question is the bigger finding***:
  the TU is `#include <vector>` plus an empty `main`, so **nothing
  instantiates `vector<T>`** and cpfe is dying in PARSING — which
  rules out deduction, instantiation, `--instantiate local` and the
  whole back end at once. ***AND `cxx-vecnarrow` WAS WRONG***: `cxx-vecsplit` refused
  because its SHORTEST prefix already crashed, and the guard that
  caught the contradiction convicted the earlier harness. Two faults,
  independent: **phase 2 tested `~ $k CRASH` and nothing else**, so an
  ERRORED prefix counted as clean though cpfe stops at the first error
  and never reaches the crash — *a negative result with two
  explanations* — and **it derived the include list with `#include` at
  column 0, where the file has 58 directives and not 56**, two being
  `#  include` inside an `#if`. Both fixed; the script gives NO VERDICT
  when it stops on an error.
  **`cxx-vecsplit`'s own fault was the same shape**: its cut list
  covered only `template<` boundaries, so its first rung was the whole
  include block in one step — *a ladder whose first rung fails has no
  rungs*. It spans the file now (`LINE DEPTH`, **137 validated of
  164**, 56 in the include block), generated and validated by g++, and
  **an ERROR rung STOPS the bisect** rather than counting as clean.
  *The generator's first attempt answered `0 candidates`, because the
  include guard is itself an open `#if` for the whole file.*
  ***AND IT IS ONE LINE: `vector.h:28`,
  `#include "../iterator/niter_base.h"`*** — seven cpfe runs over 137
  cut points, line 27 clean and line 28 CRASH. **But a boundary is
  not a reproducer**: `cxx-vecnarrow` phase 1 compiled that header
  ALONE and it was fine, so the crash is a COMBINATION and line 28 is
  only its last member. `cxx-vecsplit` phase C minimises it by greedy
  removal — **keeping any include whose removal makes the file merely
  ERROR**, since that says the prefix stopped compiling rather than
  stopped crashing — and prints the smallest reproducing file.
  Beside it, **`cxx-niterbase-probe.cpp` is twenty lines of pure
  C++14 with no library headers**, capturing the one unusual shape in
  that header: two overloads declared with a **trailing return type
  that calls the function being declared**, so the overload set the
  `decltype` resolves against includes it. g++ accepts it as written
  and instantiated. *It is a guess and the file says so*; `ok` rules
  the shape out, `CRASH` makes the whole bug twenty lines.
  **The host build is NOT the tool here and nearly became one** —
  `edgbaked-xcheck`'s verdict is sound-for-compile-time,
  VOID-at-run-time, and a crash is a run-time question.
  ***`std::variant` IS A NAME AND NOT AN IMPLEMENTATION*** — an empty
  class body, the only one of 53 in the library that is a public
  header's own principal type. What also does not go away is the
  exception-free convention, `vector::push_back` returning
  `expected<void, ...>`, so it is not a drop-in `std`.
  `docs/notes/cxx-library.md` has all sixteen and the instrument.
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

**php — ***IT LINKS, IT RUNS AND IT EVALUATES***: `PHP 8.5.12 (cli)
(NTS)`, and `php-smoke.php` is **44 of 45** on the VM -- PHP_INT_SIZE
8, strlen, max, str_repeat at 100k, preg, json, and `/net/tcp/stats`
read as 404 bytes. Notes in `docs/notes/php.md`.**
***AND THIRTEEN EXTENSIONS ARE BUILT NOW***: the four Phoronix
REQUIRES (libxml, dom, simplexml, zlib -- `system-info` runs), eight
of the nine it calls OPTIONAL -- posix, pcntl, bz2, readline, openssl
(LibreSSL), curl, sqlite3, zip -- **and gd, which was the ninth and
was impossible until `lib/gd` existed**. php takes upstream's
EXTERNAL arm, so it is `gd.c` + `gd_compat.c`, **two objects and not
the forty of php's bundled libgd** -- which is also the copy not
worth keeping, since it announces `2.0.35` while carrying AVIF, WebP
and the interpolation code. *`HAVE_LIBGD` is the gate, not
`HAVE_GD`*, and the first probe got the empty-TU result again.
***ITS FORMAT ANSWERS ARE A CONFIGURE PROBE THAT WOULD LIE, THE
FOURTH OF THAT FAMILY***: php asks the installed libgd what it can do
by LINKING `gdImageCreateFromJpeg`/`...Avif`/`...Webp`/`...Xpm`, and
**all four link** -- upstream compiles those files with no library
present and stubs each to `gd_error("... has been disabled")`. `nm`
over the archive says so. Answered **no** by hand, because otherwise
`function_exists('imagejpeg')` and `imagetypes() & IMG_JPG`, the two
documented ways to ask, both lie. *`HAVE_GD_FREETYPE` is the one
where probe and truth agree* -- `gdFontCacheShutdown` is genuinely
absent. **579 TUs compile and `--undefined`
resolves 1120 symbols** against libap and eight library trees, all of
which come in by `#pragma lib` from their own headers, so `cmd/php`
still has no `LIB=` line. **`ext/sockets` is deferred to a libap change**: no `struct cmsghdr`, no `CMSG_*`, no `msg_flags`, `sendmsg`
a stub and **`recvmsg` declared-by-the-header-and-defined-nowhere**.
***THE MEASUREMENT THAT NEARLY SHIPPED WAS AN EMPTY TRANSLATION
UNIT***: five of these wrap their whole body in `#ifdef HAVE_<X>`, so
with the name unanswered they compile to nothing and report 0 errors
-- and *counting `TEXT` symbols does not separate them either*,
because kencc emits php's header `static inline`s that gcc at -O2
discards, putting the floor at ~360. **The discriminator is whether
the assembly mentions `<ext>_module_entry`**: 0 against 10-14, one
grep. Three findings, all upstream's: LibreSSL has no
`sk_X509_new_reserve` (a capacity hint, so `sk_X509_new_null()`);
readline reaches its CLI callbacks through `dlsym`, where APE's
`<dlfcn.h>` would have answered NULL and installed nothing *silently*,
and upstream's own commented-out direct call is the fix; and
`return <void expr>;` in a `void` function, which gcc accepts and C11
6.8.6.4p1 forbids -- fixed in php, **deviation recorded in 0.6 and not
taken**, since `ORETURN` with a left operand means "compute into the
return location" and accepting void is a statement-tree rewrite.
***`system-info` RUNS AND ASKS FOR NOTHING MORE.*** What is left on
its output is three messages and only one is ours:
`disk_free_space(): Function not implemented`, which was libap's
`statvfs` stub. ***THAT IS FIXED AND THE FIX IS A SWITCH***:
`statvfs` now SUCCEEDS by default with a recognisable synthetic
figure, and `APEXP_STATVFS=strict` restores ENOSYS. The platform
limit is real -- *9P2000 has no `Tstatfs`*, and hjfs's `df` console
command prints to the SYSTEM CONSOLE rather than to the caller, which
is what closes it rather than the protocol alone -- but ENOSYS
becomes ZERO in any caller that does not check, which is how
Phoronix got `Lock creation failed due to lack of disk space` on a
disk with plenty. `lib/ap/stat/statvfs.c` carries the argument. **And php's `config.h` answers `HAVE_STATVFS` YES against this
tree's own rule, deliberately**: with it yes php checks the return and
gives `false`; with it **no** php compiles neither arm, keeps
`bytesfree = 0` and returns SUCCESS -- *a silent `0.0`, which is the
quiet version of the same failure.* The other two are not ours: the
`strpos()/substr(): Passing null` deprecations are Phoronix's own code
not guarding a phodevi probe that read a Linux `/proc` path, and
`process exceeds 100 file descriptors` occurs nowhere under `sys/src`
-- it is the kernel growing an fd table, a notice and not a limit.
***AND THE SECOND ONE WAS EVERY MULTIPLICATION.***
`zend_multiply.h:135`'s fallback arm -- the one this port takes --
declared the product `long`, which is 64 bits on LP64 and **32
here**, so any product over 2**32 was truncated, the overflow check
fired on an overflow that had not happened, and PHP returned a
FLOAT: `2000000 * 2000000` was `float(4.0E+12)`. *Every other arm in
that file is guarded by `SIZEOF_LONG == SIZEOF_ZEND_LONG`; that one
assumes it.* Found sideways, because php compiles unary minus as
`(-1) * x` -- **the smoke test covered `+`, `-`, `max`, `strlen` and
`str_repeat` and not `*`**, and a test with five operators and not
the sixth catches the sixth only by luck. Section 3b asks directly
now, with two cases a never-report-overflow fix would fail.
***THE ONE BEFORE IT WAS `exit()`, AND IT WAS kencc's 32-BIT
`sizeof`***: `zend_object_properties_size` is `sizeof(zval) * (count -
1)` with count 0, which C makes 2**64-16 and kencc makes 4294967280 by
multiplying in 32 bits and zero-extending -- so every `exit()` asked
for 4GB and died. *A script with no `exit()` was always clean*, which
is the one-command bisect that found it (`php_cli.c:1318` returns
before `module_started` is set), and `acid`'s `src(pc)` named the line
the round before. Fixed locally in php; **the compiler deviation is
recorded and not taken**, see the invariant above. **`php -v` then FAULTED at exit and the cause
is a platform consequence**: `ZEND_EXTENSIONS_SUPPORT` is 0 without
dlopen (`zend_portability.h:200`), so `zend_extension_startup`'s body
is compiled out and **no zend_extension's startup ever runs here** --
while opcache's MSHUTDOWN is an ordinary MODULE shutdown, gated by
nothing, and destroys globals its ctor never built:
`zend_string_free(NULL)`, `GC_FLAGS` reading offset 4, which is what
`fault read addr=0x4` said. Guarded, as the next line of the same
function and `zend_accel_blacklist_shutdown` already are; upstream's,
and the second upstream php bug this campaign.
***THE DIAGNOSIS COST ONE COMMAND AND NO REBUILD***: `php -h` returns
before `module_started`/`sapi_started` are set (`php_cli.c:1318`
against `:1337`/`:1359`), so it runs `exit()` and neither shutdown --
it exits clean, which cleared libap's teardown and left two functions
standing where nine calls had been candidates. Then `acid 6.out` and
`src(pc)` named `zend_string.h:401` outright. *A CLI with an early
exit path is a bisect someone else already wrote.*
**Also `mk install` could not copy the binary**: `mkone`'s rule is
`cp $prereq $BIN/$TARG` and nothing set `BIN`, which in rc is a null
list in a concatenation rather than an empty string -- every other
APE command mkfile assigns it, and nothing could notice until a link
succeeded.
**ALL 515 TRANSLATION UNITS COMPILE**, measured on the HOST. 8.5.12, vendored at
`sys/src/external/php`; `--compile` answers `compiled 515, errors 0,
missing 0` and **`--undefined` says the program wants 283 symbols
from outside php, every one of which libap has** (273 the sweep
names outright; ten it misreports because they are assembly or DATA,
each opened by hand). **So the link is PREDICTED to succeed and has
not been run**, and the refutation condition is a name outside those
283 — which is what a newly reached `static inline` would be.
***`mk install` DID reach `6l` and named four***: `_volatile__`, from
`__asm__ __volatile__("")`, which kencc lexed as a function call
because it knew `__asm__` and not GNU's qualifiers (50 vendored files
use that spelling, and the two-line test for it found
`__extension__` eating the next character); and three lexbor
`lxb_dom_collection_*`, because **kencc emits an unused `static
inline` where gcc at -O2 discards it**, so a header-only helper
calling into a file upstream's `config.m4` does not list is a link
error here and silence there. Both fixed.
**The first sweep returned EIGHT errors in six files and all six were
fixed without a VM round trip** — three of them kencc's (a pointer
assigned to a `bool`; `bool visible;` declaring nothing, because
`indeclname` had every type specifier but `LBOOL`; and the
`__attribute__`/`__asm__` paren scanner counting delimiters INSIDE
string literals, which ate php's 1680-line inlined gdb script), three
APE headers' (no BSD `timeval` macros, five missing `syslog`
facilities, no `<arpa/nameser_compat.h>`), one php's (`void *`
arithmetic) and one the `config.h`'s (`HAVE_GETHOSTBYNAME_R` yes with
every arity no). ***And the nameser fix uncovered that `<resolv.h>`
had been defining the same sixteen constants itself*** — two
definitions with nothing making them agree, invisible until one TU
included both.
**508 objects with `--disable-all`**, derived from a real configure run
on the host rather than guessed, and `ext/lexbor` is 186 of them —
*`--disable-all` does not mean a small build in 8.5*. **Three things
are free and were checked rather than assumed**: the generated
parsers, scanners and the 4.2MB `zend_vm_execute.h` are all in the
tarball, so no bison, no re2c and *no bootstrap PHP* — the gap
`miniperl` has; that file is dispatch-kind AGNOSTIC, so
`ZEND_VM_KIND_CALL` falls out of `zend_vm_opcodes.h:40` by itself with
no computed gotos and no global register variables; and
`zend_portability.h` `#define`s `__has_attribute`/`__has_builtin`/
`__has_feature` to 0 when absent, so every GCC-ism takes its portable
arm and the atomics fall to a plain `volatile` implementation plus a
`#warning` — **which kencc's cpp has**, at WARNING and not FATAL
(`cpp/nlist.c:38`, `cpp.c:278`). *A first grep of the wrong two files
said it did not.*
**`main/php_config.h` is 2239 lines, 169 of them a `HAVE_*` define**,
and that is an INVENTORY of questions rather than a set of answers —
clisp's `mprotect` rule: a working configure would get this machine
wrong. `apfunc-sweep.py` answers 106 of them mechanically: **69
defined, 4 declared-only, 33 absent**. ***And the absent list must not
be read at face value***: most of its entries are not functions, and
two are the opposite of what it says — `HAVE_TM_ZONE` and
`HAVE_ST_BLOCKS` are both YES, `struct tm` and `struct stat` having
those members. *A sweep over function names, asked about a struct
field, answers `absent` confidently.*
**What can still stop it, in order**: (1) fibers — **CLOSED and
MEASURED**: `zend_fibers.c` is unconditional and wants either
boost.context's GAS assembly or `<ucontext.h>`, and APExp now has the
second (`lib/ap/arch/amd64/ucontext.s` + `makecontext.c`), with
`ucontext-test` at **0 failures on the VM**. amd64 only; the other ten
follow the same shape when wanted. *php has not been pointed at it
yet* — that is `ZEND_FIBER_UCONTEXT` in the `config.h`.
`docs/notes/libap.md` has the two bugs it cost, both of them
`long`-width and both invisible to the host check.
(2) **`ext/opcache` is mandatory in 8.5** — there is no
`--disable-opcache`, only `--disable-opcache-jit`, which is what drops
the 13-file `jit/ir` code generator; opcache only has to COMPILE, since
`opcache.enable_cli` is off by default, and all three of its shared
memory macros must be answered NO — *`shm_open` answering success with
a file in `/tmp` over a per-process `mmap` is `HAVE_WORKING_MPROTECT`
in its exact shape.* (3) the Zend allocator's memory, which is
**CLOSED**: the partial `munmap` is fixed and both trims are measured
to survive on the VM, and the segment-slot ceiling that would have
capped the Zend heap at about 10MB is gone with `SEG_THRESHOLD` at
64MB. *The alignment question answered no — 0 of 8 — so the trims do
run; they just work now.*
**No extension in the first build**, whatever its library's state.
***AND THE PHORONIX CRASH IS libap's `posix_spawn`, LOCALISED BUT NOT
EXPLAINED.*** `php-smoke.php` is **0 failures** now (the zip block
included, so `P_tmpdir` reached php), yet `system-info` still ends
with two php processes dead -- and `acid` puts both in
`lib/ap/process/posix_spawn.c`, a GP violation at `:461` and a stack
exception at `:133`. **`FA_FCHDIR` is 4 and php never adds it**, so
`a->op` came out of something that is not a `Faction`. *Four readings
refuted four candidates and none found it*, including the obvious
shared-memory race -- `fork()` is `RFENVG|RFFDG|RFPROC` with no
`RFMEM`. `posix-spawn-test`'s `test_proc_open_loop` reproduces php's
call sequence 200 times; 0 on glibc **and 200 of 200 on the VM**, so
the suspect moves to php's own heap -- *a narrowing, not a clearing*. **And `ZEND_CHECK_STACK_LIMIT` is
neither confirmed nor refuted by this**: it guards the PHP VM, and a
C recursion never reaches the check.

- **libwebp 1.6.0** — **125 files, 0 errors, installed as one archive**
  (`lib/webp`), with the public headers committed to
  `sys/include/ape/webp` and `sys/include/ape/sharpyuv` and ONE
  `#pragma lib` in `types.h`, which every other public header
  includes. 55 of the 125 are SIMD files that compile to nothing,
  which is upstream's arrangement for a target without SIMD.
  **It confirmed the cpp pp-number fix** — `src/dsp/lossless.c:611` is
  `IN##0_C`, plain C rather than SIMD-gated — ***but what it FOUND was
  `__asm__`***: `BSwap32`/`BSwap64`/`GetCPUInfo`/`xgetbv` are GNU
  extended asm gated on ARCHITECTURE alone, APExp defines
  `__x86_64__`, and kencc swallowed them and returned uninitialised
  stack. 14 occurrences, 7 TUs, every one silently wrong; see
  `asmout-probe` above. **Not wired to gd yet, on purpose** — gd's
  `HAVE_LIBWEBP` is still no, so this is one change to attribute
  rather than two, and enabling it compiles gd's webp code for the
  first time.

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
| `docs/notes/php.md` | the php 8.5.12 survey: the 508-object file list derived from upstream's own configure, why CALL dispatch falls out by itself, the `config.h` inventory and what `apfunc-sweep` answers of it, and the three things that can still stop it |
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
- ***BUT `acid`'s `lstk()` MISREADS ARGUMENTS IN AN APExp amd64 BINARY,
  AND THE FIRST ONE IS ALWAYS GARBAGE.*** kencc's amd64 `REGARG` is
  `D_BP` (`6c/6.out.h:811`), so the first argument is passed in a
  REGISTER and the caller never writes `0(SP)` -- but `acid` reads every
  parameter from the frame, so **parameter one is whatever stale bytes
  are in that slot**. It cost a round here: `funcall(...,fun=0x41d5b0)`
  was read as a function object that had lost its type tag, and the
  caller's own code is `MOVQ $subr_tab_data+281474976722416(SB),BP` --
  the tag is there, in a register, and `0x41d5b0` was leftover stack.
  **The tell is beside it**: a 4-byte parameter comes back as eight,
  `args_on_stack=0x7fff00000004` and `errtype=0x18e4c1f50000000e`, two
  32-bit values read as one. *So in any acid stack here, trust the CALL
  CHAIN and the `regs()` dump, and treat `lstk()`'s values as a hint.*
  `regs()` is reliable, and **BP holds argument one at a function's
  entry**, which is how the clisp GC crash was read correctly.
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
- **`farith: double fp to single fp overflow` while building
  `sys/src/cmd` means the HOST's `6l`, not APExp's, and there is
  NOTHING TO FIX.** It comes with `ctime:` on the next line, out of
  `ieeedtof` in `*l/obj.c`, and `sys/src/cmd/ki` is byte-identical to
  upstream -- *the input is not the variable, the linker is*. APExp's
  own `-0.0` guard is committed in **all ten** linkers
  (`(e->h & ~0x80000000L) == 0`), so ours cannot print it. **The same
  directory builds inside a working `apexp-sh`**; `docs/notes/kencc.md`
  files it under *A free control for the `ieeedtof` -0.0 fix*, which is
  not a heading anyone hunting the error would look under, which is why
  it is repeated here. *Check which `6l` answers before reading
  anything into it*, and see the bind rule immediately below for how a
  window quietly acquires the host's.
- **A command name inside `apexp-sh` is whatever the UNION resolves it
  to, and Plan 9's own flags are the ones most likely to be missing.**
  `cmd/php/mkfile` used `` `{basename -d $target} `` -- the Plan 9
  idiom for a dirname -- and got `basename: invalid option -- d`,
  because the union puts APExp's `/bin` first and that `basename` is
  **GNU coreutils'**. *mk then reported the failure of the compile,
  not of the `mkdir`*, so the message named the victim again. Same
  family as "check which `6l` answers". A recipe that needs a Plan 9
  flag should not assume it is reachable; the php mkfile dropped the
  external command entirely and uses a static directory list.
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
- **RENAMING a source file in a library directory leaves its OBJECT in
  the archive, and `clean` does not remove it.** `mksyslib`'s `clean`
  is `rm -f *.[$OS] ...`, which touches the directory and never
  `$LIB`; only `nuke` removes the archive, and `ar vu` replaces
  members by NAME, so an object whose source no longer exists is
  simply never revisited. *Renaming `mcontext.s` to `ucontext.s` left
  `mcontext.6` defining `_ctxreturn` beside the new `ucontext.6`
  defining it too*, and the next build said `duplicate text symbol:
  _ctxreturn`. **The loud case is the lucky one**: when the stale
  object does NOT collide, its code stays linked into every program
  in the tree for ever with no diagnostic from anyone. One
  `ar d <lib> <stale>.$O` fixes it; `mk distclean` fixes it at the
  cost of a full rebuild. *There is no instrument for "a member of
  `libap.a` whose source is gone" and it would be cheap* -- `ar t`
  against the directory -- but the archive exists only on the VM.
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
- **A hand-answered `config.h` macro whose body is an EXPRESSION over a
  free variable is coupled to the VARIABLE NAME at its expansion site,
  and that site is invisible from the `config.h`.** Almost every
  autoconf macro is a type name or a constant, which is self-contained;
  the exception is a PREDICATE spliced into a function body. clisp's
  `VALID_FILENAME_CHAR` was written here as `(c != '/' && c != '\0')`
  and upstream expands it inside `legal_namebyte (uintB ch)`, giving
  `pathname.d:825 name not declared: c`. ***The warning beside it is
  the tell***: `set and not used: ch`, a parameter reported unused in a
  one-line function that exists to test it, which means the test never
  mentioned it. **Grep for the macro's own name in the package before
  writing its body** -- there was exactly one expansion site. This
  tree hand-maintains four such files (perl, bash, clisp, chicken), so
  the shape can recur; a sweep of clisp's found this the only `#define`
  of that kind.
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
  ***AND THAT RULE IS NOT ABOUT TCL***, which is how it was filed and
  how it got misread. **rc does NOT word-split a quoted string**, so
  `CDEFS='-D_PLAN9_SOURCE -D_POSIX_SOURCE -D_BSD_EXTENSION'` is ONE
  word, and `pcc $CDEFS` hands cpp a single `-D` argument holding all
  three: `cpp: <cmdarg>:1 Illegal -D or -U argument -D_POSIX_SOURCE
  -D_BSD_EXTENSION`. A list of flags built in a recipe takes `()`, and
  `'-I'^$srcroot^/src` is the way to get ONE word with a path in it.
  *The sh habit is the trap*: there `"$CDEFS"` quotes and bare
  `$CDEFS` splits, so the quoting reflex is backwards for rc. **Not
  swept for and deliberately**: after the two in `cmd/clisp` were
  fixed the shape occurs 0 times in 253 mkfiles, so a standing sweep
  would have no positive control and nothing to find. `rc/bin/ape/
  install:34`'s `*=($1 $2)` is the working precedent for the `()`
  form.
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
  ***AND THE ARGUMENT IS ONLY HALF OF IT: `sizeof` BREAKS ARITHMETIC
  TOO, WITH NO MISSING PROTOTYPE AND NO DIAGNOSTIC.*** C requires
  `sizeof` to yield `size_t`, which is 64 bits here; `cc/com.c:894`
  gives it TULONG, which is 32. So `sizeof(T) * (n - 1)` with `n == 0`
  -- php's `zend_object_properties_size`, ordinary correct C that
  relies on the wraparound -- multiplies in 32 bits and then
  **ZERO-extends**: `SUBL` / `SALL $4` / `MOVLQZX`, 4294967280 where
  gcc gives 2**64-16. **Every `exit()` in every php script then asked
  the allocator for 4GB.** The conformant fix is one line and is NOT
  taken, because a 64-bit `sizeof` hands a variadic `%d` eight bytes;
  `docs/notes/kencc.md` has the measurement, the trade and the control
  set to run if anyone takes it.
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
- **kencc amd64 has NO callee-saved registers, measured.** A host
  `6c -S` on a function that computes three values, calls through a
  function pointer and then uses them spills all three to the stack and
  touches BX and R12-R15 not at all. *So nothing may be kept in a
  register across a call into arbitrary code* — which is why libap's
  `ucontext` puts its bookkeeping pointer on the new stack. `main9.s:7`
  calls R12-R15 "callee-saved REGEXT registers" and both can be true: a
  register the allocator never hands out is trivially preserved.
- **A process gets FIVE spare segment slots, measured twice and the
  second time at 64KB**, so `mmap` cannot be backed by `segattach` in
  general. `mmaptrim-probe` section 0b got 5 at 2MB and 5 at 16MB
  through `mmap`; **section 0c calls `_SEGATTACH` directly and gets 5
  at 64KB**. *Five, over a 256-fold range of sizes and a total of
  320KB* -- so memory and address space are excluded outright, and the
  number is the kernel's rather than the library's. `SEG_THRESHOLD` is
  64MB for that reason and anything below it is `malloc`-backed,
  page-aligned by hand since `malloc` is not. **0c is the one that
  still asks**: every size 0b uses is now under the threshold, so it
  answers 64/64/64 and can only confirm that `mmap` spends no slot.
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
it wrote**; **a partial `munmap` destroying the whole segment, by two
different routes** — a head trim matched the table on its start address
and detached the segment the caller was about to use, and a tail trim's
interior address fell through to `_SEGDETACH(addr)`, which detaches the
segment that address is in; *the idiom both of those break is how every
POSIX program gets an ALIGNED allocation*, php's Zend allocator
included, and the unknown-address `_SEGDETACH` fallback is gone
deliberately, because destroying a stranger's segment to free a mapping
we are not sure we made is worse than leaking; **`mmap` spending a
SEGMENT SLOT on every mapping over 1MB when a process has only five**
— the prose above the constant already said "Plan9 allows only ~8
segments (NSEG)" and the threshold was set to 1MB anyway, *the limit
known and the constant chosen as though it were not*; 64MB now, which
exposed the deviation it had been hiding, namely that the
`malloc`-backed arm returned a pointer that was **not page-aligned**
as POSIX requires; **`ctime_r` declared in
`<time.h>` and implemented nowhere**, found by `apfunc-sweep.py` while
answering php's `config.h` and already the composition of two functions
that were there — ***and writing a caller for it found `asctime_r`
declared by NO header at all***, defined 120 lines down its own file
and returning implicit `int` to everyone, which `apdecl-sweep.py`
cannot report because it compares a call against a DECLARED return
type and there was none (*the inverse question — what does libap define
that no header declares — has no instrument*); `poll()`'s three POSIX violations and `select()` on a
regular file; itcl's
four `sfbug`s; kencc's `false` keyword, the `L`-suffix width cap, the
wide case label, the compound-literal zero fill, and both bit-field
rules with the static initialiser underneath them; **cpp's missing
hideset INTERSECTION, which stopped a macro expanding inside the body
of any macro whose name was built by `##`** — and the hash-interning
underneath it, which made cpp 27x faster on clisp's biggest file;
**`cc/cc.h`'s `Node.xoffset` being `long`, so `6c` silently dropped the
top half of any address offset above 2^31** — `xcom` folds
`ADD(CONST, ADDR(NAME))' into the NAME, and clisp's `L(name)` puts its
type tag at bit 48, so every CLISP SUBR object arrived untyped.
`vlong` now, with `sconst`'s own 32-bit `v` in `6c`/`8c` beside it
(a wide constant came through as 0 and was called *small*).
***The control is the thing to copy***: a gcc-built host `6c` has a
64-bit `long` and cannot reproduce the fault, so the field was
NARROWED on purpose and the host then printed the VM's answer to the
digit. `tagconst-probe.c` is the five-line case and is a regression
test now; `agree.c` is identical before and after.
***AND IT EXPOSED ITS OWN SECOND HALF, WHICH IS THE PART TO REMEMBER***:
x86-64 has `MOV r64, imm64` and **no `CMP r64, imm64`**, and `6l`'s
`oclass` returned `Yi32` for `$sym+off(SB)` whatever the offset, so
`CMPQ BP,$sym+(1<<50)(SB)` was encoded with `put4`. clisp's `nullp()`
is that shape, so every list looked dotted. *The two bugs CANCELLED* —
while `xoffset` was 32 bits both sides of the comparison were equally
wrong — so fixing the compiler alone moved the failure EARLIER.
`6c`'s `hardconst` now loads such a constant into a register
(**2001 such compares in clisp's 31 TUs, 0 after**) and `6l` returns
`Yi64`, which `MOVQ` can encode and `CMPQ` cannot, so the next one
fails loudly in `asmins` instead of silently.
***AND THE ONE UNDERNEATH BOTH OF THEM IS `reg.c`'s `mkvar`, WHICH
KEYED A VARIABLE ON ITS OFFSET.*** `x+0(SP)` and `x+6(SP)` were two
UNRELATED variables, so an ordinary type pun — write the object, read
part of it through a cast pointer — left the store with no readers and
`regopt` excised it, in either direction and with no diagnostic. **Not
a `REGARG` bug**: a plain local loses its store too, and the amd64
parameter case is only the sharpest form, since `REGARG = D_BP` means
the frame copy exists solely because `cc/pgen.c` spills it. clisp's
`mtypecode(obj)` is `(*((tint*)&(obj)+3))`, so `mconsp` answered "not
a cons" for a slot that provably held one. `varalias()` marks
overlapping accesses in `addrs`; `agree.c` is identical before and
after, which is what says ordinary code does not move. **6c only** —
all ten carry the keying but their `mkvar` signatures differ, so the
other nine are in 0.6's inventory with the mechanism, 8c first.
***AND THE THIRD WIDE-CONSTANT ONE WAS `LEAQ`.*** `6c/cgen.c:346`
folds `(x<<k) + C` into `genmuladd`, an
`LEAQ C(base)(index*2^k)`, and refused only a SMALL `C` — so
`((u64)3<<48) + ((n<<1)+1)` compiled to
`LEAQ 844424930131969(NONE)(BP*2)`, correct arithmetic and **not an
instruction**, which `6l` wrote with `put4`. clisp's
`make_small_read_label` is that shape, so every `#n#` reader label
lost its TYPE TAG and became oint 3. `immconst` guards the fold now,
and `6l`'s `asmandsz` **diags** instead of truncating — *making the
linker loud FIRST is what named the two sites*, and the host count
agrees from the other end: 2 wide `LEAQ` displacements in clisp's 31
TUs before, 0 after. ***AND THE OBJECT WAS MISIDENTIFIED FOR FOUR
ROUNDS***: `#<ADDRESS #x3>` matches `make_small_read_label(1)`'s
arithmetic, so four instruments were built hunting a substitution
failure that never existed. A read label prints `#<READ-LABEL n>`;
`#<ADDRESS ...>` is `pr_machine`, a different type. **An object's
value matching a constructor's arithmetic is not that object — ask
what PRINTS it.**

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
