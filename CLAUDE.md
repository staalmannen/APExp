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

# Note: run twice — syscalls are not always integrated into libap on the first run

# Clean build artifacts
mk clean

# Nuke everything
mk nuke
```

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

- **C99:** VLA, compound literals, hex floats, complex numbers, `//` comments, `_Bool`, designated initializers, `__alignof__`, `_Generic` (C11/C23), unicode escapes
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

Every test named in the sections below sits here; the ones for kencc
itself are `bool-test.c`, `bitfield-test.c`, `compound-assign-test.c`,
`compound-literal-test.c`, `designated-init-test.c`, `charptr-test.c`,
`rol64-test.c` and `u64float-test.c`, and for libap `locale-test.c`,
`sigset-test.c`, `posix-spawn-test.c`, `limits-test.c`,
`format-arg-test.c`, `unget-pipe-test.c`, `isatty-test.c` and
`stdio-test.c`. The three `tk-*.tcl` scripts there are Tcl, run with
`wish`; see the Tk section below. `sys/src/ape/lib/libressl/test/` is separate: it is
upstream's own ML-KEM and SHA-3 vectors, run by `mk test` there.

Beyond that, testing is still mostly ad-hoc — compile a program under
APExp and see whether it builds and runs.

## Current Development Focus (as of 2026-09)

- POSIX threading (`pthread`) — `sys/src/ape/lib/ap/thread/`
- Async I/O (`aio`) — `sys/src/ape/lib/ap/aio/aio.c`
- C11/C23 compiler features — `_Generic`, and `bool` as a real type
- perl 5.42.2 — see the section below

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
  — see the section below. This is why miniperl compiled programs and
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

## Compiler Patch History and Technical Details

This section documents the patches applied to `sys/src/cmd/` during the
2025-2026 development cycle, the bugs they fix, and the principles behind them.
It is intended to help Claude Code continue this work without re-deriving
solutions from scratch.

### Critical Bug Fixes (already committed)

#### ABI: typesuvinit[] — TVLONG/TUVLONG removed (cc/sub.c)
`TVLONG`/`TUVLONG` were incorrectly in `typesuvinit[]`, causing all vlong-returning
functions to use the struct-return calling convention (hidden pointer parameter).
This corrupted the ABI of all binaries including 6l itself.
**Fix:** `int typesuvinit[] = { TSTRUCT, TUNION, TCFLOAT, TCDOUBLE, -1 };`

#### Register allocator: maxregion=600 (all *c/reg.c)
`maxregion` was set to 300 (reduced during a rebase), triggering an
`allocn()` crash when compiling large functions like `yyparse`.
**Fix:** Restore `maxregion = 600` in all arch `reg.c` files.

#### CLOCAL missing from naddr() (all *c/txt.c) — THREE locations per file
Function-local `static` variables get class `CLOCAL` (not `CSTATIC`) in `adecl()`.
All arch compiler `naddr()` functions only handled `CSTATIC`, so `CLOCAL` hit
the `bad:` label producing "bad in naddr: NAME" errors.
**Fix:** Add `|| n->class == CLOCAL` / `|| s->class == CLOCAL` at three spots
in each arch's `txt.c`:
1. Global emit loop: `s->class != CSTATIC && s->class != CLOCAL`
2. naddr ONAME case: `n->class == CSTATIC || n->class == CLOCAL`
3. gpseudo D_STATIC selection: `s->class == CSTATIC || s->class == CLOCAL`

#### ar duplicate-symbol abort (ar.c)
Plan9 `ar r` aborted the entire operation on the first duplicate text symbol,
leaving 150+ critical members missing from `libap.a`.
**Fix:** In `rcmd()`, reset `dupfound=0` per member and `continue` rather than
aborting. `libap.a` grew from ~3.5MB to ~6.2MB.

#### Compound literal lvalue (cc/dcl.c, cc/com.c)
`&(type){...}` produced "not an l-value" errors.
**Fix:**
- `dcl.c` `compoundlit()`: `if(!iscmplx(t->etype) && !typesu[t->etype]) seq->addable = 1`
- `com.c` OCOMMA case: same guard for `n->addable = r->addable`
The `iscmplx`/`typesu` guard is critical — without it, complex number OCOMMA
nodes get `addable=1` causing "unknown type in regalloc: UNION" errors.

That guard left `&(struct S){...}` still failing, because struct/union
literals are exactly the ones the guard excludes. **Fix (2026-08):** the
`OADDR` case in `com.c` `tcomo()` now hoists the comma first —
`&(a, b)` → `(a, &b)` — so the `OADDR` lands on the hidden temporary's
`ONAME`, which is addressable whatever its type, and the l-value test is
never reached. Only fires when `l->op == OCOMMA` and the right operand is
already addable and not a bit field. Covered by
`sys/lib/tests/compound-literal-test.c`. Found via gnulib `randperm.c`,
which passes `hash_remove(sv, &(struct sparse_ent_){i, 0})`.

### C99 Feature Status (complete)

All C99 items are implemented. Key patches in `sys/src/cmd/cc/`:

| Feature | Files | Notes |
|---------|-------|-------|
| `\uXXXX` universal chars | `lex.c` escchar() | Returns Rune, runetochar() encodes UTF-8 |
| Binary literals `0b` | `lex.c` tnum: | Already present |
| Digit separators `1'000` | `lex.c` all 8 numeric loops | incl. float: casedot/casee/casedothex/casep |
| `_Static_assert` | `lex.c` itab, `cc.y` prog+slist+edecl | 3 scopes: file, function, struct body |
| `nullptr` | `lex.c` LNULLPTR, `cc.y` pexpr | OCONST with types[TIND], vconst=0 |
| `typeof`/`__typeof__` | `lex.c` LTYPEOF, `cc.y`, `com.c`, `sub.c` | Was SILENTLY SWALLOWED before — corrupted all __typeof__ uses |
| `_Alignof`/`__alignof__` | `lex.c` LALIGNOF, `cc.y`, `com.c` | Was swallowed; now returns align(1,T,Ael1) |
| `[[attributes]]` | `lex.c` case '[' | Depth-counts [[ to ]] |
| `__builtin_*` | `lex.c` | Swallows args, returns LCONST 0 |
| `_Atomic`/`__atomic` | `lex.c` drop-silently | Dropped like __thread |
| `_Generic` | `lex.c` LGENERIC, `cc.y` | See _Generic section below |
| `#elifdef`/`#elifndef` | `cpp/cpp.h`, `cpp/nlist.c`, `cpp/cpp.c` | Also fixed skipping-block dispatch |
| `static_assert` | `lex.c` | C23 alias for _Static_assert |
| `alignof` | `lex.c` | C23 alias for _Alignof |
| `typeof_unqual` | `lex.c` | C23 alias for typeof (qualifier stripping not yet implemented) |
| main() implicit return 0 | `cc/pgen.c` | C99 §5.1.2.2.3; synthesises gen(&ret) with zero |
| non-void fall-off warning | `cc/pgen.c` | Was error; now warn (use -B to suppress) |

**Named initializers for static aggregates (17b):** Works — the localeconv.c
error was caused by missing struct members in `locale.h`, not a compiler bug.
One real bug found later, in the *scope* a designator is resolved in: see
"Designators are relative to the enclosing brace list" below.

**Anonymous struct/union:** Fully implemented in existing `dcl.c`+`sub.c` —
`edecl()` accepts `sym==S`, `sualign()` assigns correct offsets, `dotsearch()`
recurses into anonymous members. No compiler changes needed.

### _Generic Implementation (C11 §6.5.1.1)

Location: `sys/src/cmd/cc/cc.y` (grammar + `generic_select()` helper function)

**Design:** Handled entirely in the grammar action, not in `tcom()`, to avoid
type-checking unselected branches (which may reference wrong-type functions).

Association list: OLIST of OCAST nodes where `->type` = association type
(T = null for `default:`), `->left` = value expression.

`generic_select()` at end of `cc.y` after the final `%%`:
1. Calls `generic_ctrl_type()` to apply lvalue conversion (array→ptr, func→ptr, strip qualifiers)
2. Walks OLIST using `sametype()` for matching
3. Returns matching `->left` node, or `default:` value, or Z on no match

**Token:** `LGENERIC` in `lex.c` itab and `cc.y` `%token`.

### typeof Implementation

**Critical:** `__typeof__` was previously in the swallow block alongside
`__attribute__` — the entire argument `(expr)` was consumed and discarded,
so `__typeof__(int) y;` became `y;` with no type. This silently corrupted
ALL declarations using `__typeof__`.

**Fix:** Remove `__typeof__`/`__typeof` from swallow block. Add `LTYPEOF`
token. Two grammar contexts:
- `uexpr: LTYPEOF '(' cexpr ')'` → OTYPEOF node (for `sizeof(typeof(x))`)
- `complex: LTYPEOF '(' cexpr ')'` → calls `complex($3)`, returns `$3->type`
- `complex: LTYPEOF '(' tlist abdecor ')'` → `dodecl(NODECL,...)`, returns `lastdcl`

`OTYPEOF` in `com.c`: evaluates child type, collapses to typed zero OCONST.
`OTYPEOF` in `sub.c`: added to no-side-effects list and opname table.

### C11/C23 Task List

**Done:** `_Static_assert`, `nullptr`, `[[attributes]]`, `#elifdef`/`#elifndef`,
`_Alignof`/`_Alignas`(query), `_Generic`, `typeof`, `static_assert`, `alignof`,
anonymous structs/unions, digit separators (all 8 loops), `__builtin_*` swallowing,
`auto` type deduction.

**Not yet done (priority order):**
1. `typeof_unqual` qualifier stripping (currently alias)
2. `_Alignas` in declarations (layout effect; `_Alignof` query works)
3. `_Atomic` full stdatomic.h (currently dropped as qualifier)
4. `_Generic` is done; `tgmath.h` now exists using it
5. Digit separators in float exponent (casep loop) — verify
6. `constexpr` objects (C23)

### `auto` Type Deduction (C23 §6.7.10.2)

Location: `sys/src/cmd/cc/cc.y`

**Design:** New `autoadlist` non-terminal entered when LAUTO appears without an
accompanying explicit type specifier. Avoids the mid-rule action timing problem in
the existing `adlist` rule by parsing the full declarator and initializer before
calling `dodecl`.

**How it works:**
- `auto x = expr;` — `complex(expr)` is called to type-check the initializer, then
  `auto_deduct_type()` extracts the type and strips top-level const/volatile (§6.7.10.2).
  `dodecl(adecl, CAUTO, deduced_type, xdecor)` is called with the real type.
- `auto *p = ptr;` — `dcl_ind_depth()` counts OIND levels in the declarator;
  that many TIND layers are stripped from the initializer type before `dodecl` wraps
  them back. Net result: `p` gets the initializer's pointer type.
- `auto x;` (bare, no init) — backward compat: declares `int` (C89 §6.7.1).
- `auto x = e1, y = e2;` — multiple deductions in one declaration.
- `for(auto x = ...; ...)` — supported via `forexpr: LAUTO autoadlist`.

**LALR(1) conflicts:** LAUTO + LNAME/`*`/`(` creates a shift-reduce conflict with
the existing `ctlist adlist` path (where `LAUTO → cname → ...`). Yacc's default
shift-preference picks `autoadlist`, which is correct. For `;` after LAUTO, only
the cname reduce applies (no conflict), so `auto;` still parses normally.

**Limitation:** `auto int x = 5;` (bare auto with explicit type) now causes a parse
error — this syntax is invalid C23 anyway and was never written in practice.

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

---

## Known Invariants and Traps

### size_t / ssize_t must be 64-bit on amd64

Plan 9 6c has `long` = 32-bit even on amd64.  The original headers defined
`size_t = unsigned long` and `ssize_t = long`, making them 32-bit.  This
causes ABI mismatches: a 32-bit size_t value is stored in 4 bytes, but the
callee reads 8 bytes (amd64 argument slots are always 8-byte aligned), getting
garbage in the upper 32 bits.

**Symptom:** `vsnprintf` called by `sprintf` received `nbuf = INT_MAX = 0x7fffffff`
(correct), but `strncpy(buf, mem, nbuf - 1)` was passed `n = 0x7fff7ffffffe`
(high 32 bits = stack garbage), causing 2-billion-byte zero-padding into the
guard page → `fault write addr=0x7ffffffff000`.

**Fix (2026-04):**
- `amd64/include/ape/stddef_arch.h`: added `typedef unsigned long long _size_t; typedef long long _ssize_t;`
- `sys/include/ape/stddef.h`: `typedef _size_t size_t` (fallback: `unsigned long` for 32-bit arches)
- Same for `sys/include/ape/sys/types.h`, `unistd.h`, `bsd.h`
- `vsnprintf.c`: also fixed to use `memcpy(buf, mem, min(n, nbuf-1))` instead of `strncpy(buf, mem, nbuf-1)` — the strncpy approach is wrong when nbuf = INT_MAX regardless of size_t width

**Other 64-bit arch headers updated (2026-04):** arm64 `stddef_arch.h` updated
with same pattern. power64 `stddef_arch.h` created (power64 had none).
32-bit architectures (386, arm, mips, power, sparc, 68020, spim) are correct
as-is: `unsigned long` = pointer-sized on ILP32.

### A variadic sentinel must be a pointer, not 0

`f(a, b, 0)` where `f` reads its arguments with `va_arg(ap, char *)`
until NULL is undefined behaviour, and on amd64 Plan 9 it does not
work. The `0` is an `int`, and the default argument promotions leave it
an `int` — four bytes. Arguments are passed in eight-byte stack slots,
so `va_arg` reads eight: the zero in the low half and whatever the frame
holds in the high half. The loop then keeps going.

This is the same shape as the `size_t` problem above, and it survives
everywhere else for the same reason a lot of this does: System V amd64
passes small integers in registers, and writing the low half of a
register zeroes the upper half as a side effect. **Nothing zeroes a
stack slot.**

flex is where it turned up. `main.c:383` had

```c
filter_create_ext(output_chain, m4, "-P", 0);
```

and flex pipes its generated scanner through `m4 -P`, so the garbage
pointers became extra `argv` entries; m4 took them for file names,
exited without reading its stdin, and flex died writing into a pipe with
no reader — `flex: sys: write on closed pipe`, with nothing to say which
of the two was at fault.

Note it is stack-layout dependent, so it can appear to work and then
stop when the compiler changes. When a variadic call goes wrong, check
the sentinel before anything else. `execl`, `execle`, `execlp` and
gnulib's `version_etc` are the common ones; all call sites of those in
the tree are correct today.

### sizeof is 32-bit, so a call with no prototype in scope corrupts it

`cc/com.c`'s `OSIZE` case ends with

```c
/* Plan9: long is always 32-bit, even on amd64.  sizeof must return
 * TULONG (unsigned long, 32-bit) so it matches the ABI width of
 * every long/int parameter without corrupting the call stack.
 * Assignments to size_t (uvlong, 64-bit) zero-extend automatically
 * at the call site when the prototype is visible. */
n->type = types[TULONG];
```

**"when the prototype is visible"** is the whole of it. With no prototype
in scope, `sizeof` is written into the argument slot as four bytes, and
a callee compiled against a real `size_t` reads eight -- the low half
right, the high half whatever the stack held.

`plan9/callmain.c` was the case that found it. It includes `lib.h`,
`sys9.h` and `<stdlib.h>`, none of which reach `<string.h>`, and does

```c
memset(privates, 0, sizeof(privates));
```

so `memset` ran with `n = 0xfefefefe00000080` instead of 128 and walked
into the guard page:

```
mkbuiltins: suicide: sys: trap: fault write addr=0x7ffffffff000
```

**Every APE program starts through `_callmain`**, so this was latent in
all of them, and fired only where that garbage happened to be nonzero.
That is why it appeared on a fresh 9front and not on a machine that had
been building for a while, and why the programs that hit it --
`mkbuiltins`, `objc`, `cfront` -- are the ones the build invokes with
very long command lines: argv and the environment sit at the top of the
stack, so their size decides what lands in the slot above.

This is the same family as the variadic sentinel above, and it has the
same tell: a value that is right in its low 32 bits and garbage above.
**When an argument arrives half right, look for a missing prototype
before anything else.** kencc has no diagnostic for calling a function
with no prototype in scope, so nothing warns; adding one would catch
this class at compile time, but a great deal of old Plan 9 code relies
on implicit declarations, so it would need to be a warning rather than
an error.

### APE malloc / free() constraint
`free(ptr)` computes `(Bucket*)((uintptr_t)ptr - datoff)` where `datoff=16`.
Any pointer passed to `free()` MUST be exactly the value returned by `malloc()`.
Aligned-allocation fallback for alignment > 16 returns adjusted pointers that
are NOT free()-safe. Document this in any aligned allocator.

### amd64 sigsetjmp / siglongjmp — bugs and fixes

**Files:** `sys/src/ape/lib/ap/arch/amd64/setjmp.s`, `sys/src/ape/lib/ap/arch/amd64/notetramp.c`, `sys/src/ape/lib/ap/arch/amd64/main9.s`

**Bug 1 (setjmp.s):** `MOVL $_psigblocked(SB), 4(RARG)` stored the ADDRESS of
`_psigblocked` into the jmpbuf. Fix: load the VALUE with an intermediate register.

**Bug 2 (main9.s — suicide trap: fault write addr=0x7ffffffff000):**
Two sub-bugs, both in how `_main` stored a value near USTKTOP in a callee-saved
REGEXT register that sigsetjmp later captured:

- Sub-bug 2a: The copy loop used `MOVQ $0x7ffffffff000, R13` (boundary guard).
  R13 is REGEXT — sigsetjmp saved 0x7ffffffff000 → jmpbuf[5]; longjmp restored
  it; subsequent REGEXT write via R13 faulted at 0x7ffffffff000.
- Sub-bug 2b: After replacing the loop with `REP; MOVSQ`, the code still used
  `MOVQ SP, R12` to save kernel SP (= USTKTOP - ssize - 8 ≈ USTKTOP - 56).
  R12 is also REGEXT — sigsetjmp saved kernel_SP → jmpbuf[4]; longjmp restored
  it; REGEXT code with offset 56 from R12 wrote exactly to 0x7ffffffff000.

**Fix:** Use R11 (caller-saved scratch, NOT in setjmp's save list) instead of
R12 to hold the kernel SP.  Use `CLD; REP; MOVSQ` with only AX/CX/SI/DI/R11.

**Bug 3 (notetramp.c / notetramp ordering):**
`notecont()` decremented `nstack` BEFORE calling the user signal handler; when
the handler called `siglongjmp()`, `nstack==0` so `longjmp()` path was taken.
With the old longjmp (PUSH+RET), this caused a fault when SP was near USTKTOP.
**Fix (current):** `nstack--` is now BEFORE `(*f)()`.  With our new longjmp
(ADDQ $8,SP + JMP, no stack write), the longjmp() path is safe when nstack==0.

**Invariant:** `longjmp` must NEVER write to the stack (uses ADDQ+JMP not PUSH+RET).
`main9.s` must NEVER use R11–R15 as scratch registers — R12–R15 are REGEXT-reserved,
and R11 is the only safe scratch for values that must not survive to sigsetjmp.
Actually: use ONLY AX/CX/DX/SI/DI/R8/R9/R10/R11 (caller-saved) in `_main` startup.

### FP environment: Plan 9 vs POSIX

**File:** `sys/src/ape/lib/ap/arch/amd64/main9.s`

Plan 9's kernel initialises MXCSR to `0x1900`: invalid-operation, divide-by-zero,
and overflow exceptions are **unmasked** (will trap as process notes).  POSIX
programs expect all FP exceptions masked (`0x1f80` — the Linux/glibc default).
Without correction, any early FP call in Tcl/Tk (e.g. `log(2.)` in
`TclInitDoubleConversion`) crashes immediately with
`"sys: fp: invalid operation fppc=... status=0x21"`.

**Fix (2026-04):** In `_main` (before jumping to `_callmain`), explicitly set:
- MXCSR = `0x1f80` via `LDMXCSR` (all SSE FP exceptions masked)
- x87 CW = `0x037f` via `FLDCW`  (all x87 FP exceptions masked, double precision)

**Invariant:** Any new APE startup path that bypasses `main9.s` MUST set the
POSIX FP environment before executing any floating-point code.

### Header search order: the architecture directory wins

**This has now cost two bugs. Read it before adding a header.**

`pcc.c:234-235` passes

```
-I/$objtype/include/ape
-I/sys/include/ape
```

in that order, so **anything the host's stock APE keeps in the architecture
directory shadows everything in this tree**. Stock APE keeps `float.h` and
`stdarg.h` there.

`mount-include` used to bind the repo's `$objtype/include/ape` onto
`/sys/include/ape` and nowhere else, which only makes those files visible on
the path pcc searches *second*. So APExp's `<float.h>` — a wrapper over the
renamed `float_arch.h` — was never read on any architecture, and
`#include <float.h>` silently got the host's stock copy. Invisible until
something wanted a C99 name:

```
dtimespec-bound.h:61 name not declared: DBL_TRUE_MIN
```

**Fix:** `mount-include` also does `bind -b $cputype/include/ape
/$cputype/include/ape`, and every architecture has a real `float.h` that
chains to `float_arch.h` plus the shared `float_ext.h`.

The rename was only half-applied, which is worth knowing: eight architectures
have `float_arch.h`, while sparc, sparc64 and spim still call theirs
`float.h`; same for `stdarg_arch.h` vs sparc's `stdarg.h`. `sys/include/ape/
stdarg.h` is a pure wrapper that adds nothing, so that one is currently
harmless — but it is the same trap.

**Note:** `mount-include` is a no-op if `/sys/include/ape/THIS_IS_APExp`
already exists, so a shell that mounted before this change keeps the old
namespace. Start a fresh `apexp-sh`.

The second bug was `<stdint.h>`, and it was worse than being ignored. Stock
APE keeps a `stdint.h` in the architecture directory too, and that file takes
the guard name `_STDINT_ARCH_H_` — which is the guard on APExp's own
`stdint_arch.h`. So the stock header won the search, defined the guard, and
APExp's arch header then compiled to **nothing**: the typedefs came from the
stock file (right, by luck, on amd64) and `INTPTR_WIDTH` was never defined at
all. `SIZE_MAX` is chosen by `#if INTPTR_WIDTH == 64`, so it came out
`0xffffffff` while `size_t` stayed 8 bytes, and gnulib's

```c
argsize == SIZE_MAX ? arg[i] == '\0' : i == argsize
```

never looked for the NUL. GNU `ls` read its way off the end of the heap.

**Fix, and the shape to copy for any header stock APE keeps per-architecture:**

- every architecture directory has a real `stdint.h`, so the stock one is
  never reached;
- the content lives in `sys/include/ape/stdint_generic.h`, because none of
  those copies could reach "the other stdint.h" by that name — the search
  would find itself;
- `INTPTR_WIDTH` is derived from `_BITS64` as well, and overrides rather than
  defers, so a shadowed or neutralised arch header cannot produce a wrong
  width — only `#error`.

Known to be kept per-architecture by stock APE: `float.h`, `stdarg.h`,
`stdint.h`. **All three are now shadowed** by a real file in each architecture
directory. `stdarg.h` was the same trap twice over: its content is in
`stdarg_arch.h` under the guard `__STDARG`, which is the guard the stock
header uses too, so the stock copy did not merely win the search — it
disabled APExp's. `va_copy` is APExp's addition to those headers, and whether
any of it reached a compile depended entirely on what the host happened to
ship.

`sys/lib/tests/limits-test.c` checks `(size_t)-1 == SIZE_MAX` and the same
identity for the other types, and prints which of these headers were actually
read.

### stdio/ — vsnprintf wrote nothing when there was nothing to write

`vsnprintf` was a wrapper over `fmemopen(buf, nbuf, "w")` plus
`vfprintf`. `fmemopen`'s `mwrite` writes the terminating NUL *after* a
write, so formatting **zero** characters — `snprintf(buf, n, "%s", "")` —
touched the buffer not at all and left whatever was there before. C99
7.19.6.5p2 requires a null-terminated result whenever `n` is nonzero.

Found through GNU m4. `format()` formats each conversion into a fresh
`xasprintf` buffer, and a specifier with no argument left formats the
empty string — so it came back holding the *previous* conversion. bison's
`data/skeletons/c.m4:557` formats `"%s = %s%s%s"` with three arguments,
the last being the separating comma or nothing:

```
YYEOF = 0,,		/* wrong */
YYEOF = 0,		/* right */
```

so every token of every parser bison generated had a doubled comma. Most
C compilers accept `, ,` in an enumerator list often enough that nothing
noticed; the Portable Object Compiler is the first thing in the tree that
*parses* a `y.tab.c` rather than compiling it, and it said
`y.tab.c:138: fatal: syntax error ","`.

The same file had a second bug: `mwrite` short-writes at the end of the
buffer, which makes `vfprintf` count short *and* set the error flag, so
the return value was the truncated length or -1 rather than the length
that would have been written (7.19.6.5p3). That silently breaks the
measure-allocate-format-again idiom.

Now musl's own implementation, which is a cookie writer rather than a
`FILE`: `sn_write` reports every byte as written and copies only what
fits, so the count is right however small `nbuf` is, and the buffer is
terminated before `vfprintf` is called at all. This also retires the
`nbuf > 65536` `open_memstream` path that existed to keep `sprintf`'s
`nbuf = INT_MAX` from overflowing a length computation.

`fmemopen` was fixed alongside: POSIX says `w` and `w+` set the first
byte of the buffer to NUL, and musl did it for `w+` alone.

Covered by `sys/lib/tests/format-arg-test.c`, which separates the two
halves of the m4 line this came from — printf's `%*.*s` with a zero width
and a negative precision, and the `ARG_STR` idiom (a comma expression in
the second arm of a conditional, passed to a variadic function). Both
were suspects; only the library was at fault.

### isatty must follow the descriptor, across dup2 and exec

APE caches the answer in `_fdinfo[fd].flags` as `FD_ISTTY`, and the flag
travels across an exec in the `$_fdinfo` environment variable.
`sfdinit()` in `plan9/_fdinfo.c` restored the inherited value and then
only ever OR'd `FD_ISTTY` back in from the real descriptor -- it never
cleared it:

```c
fi->flags = fl;			/* inherited, may say ISTTY */
if(_isatty(fd))
	fi->flags |= FD_ISTTY;	/* sets, never clears */
```

So a descriptor that was the console in the parent and a pipe in the
child kept `FD_ISTTY`, and `isatty()` lied. Note `readprocfdinit()`
gets this right -- it rebuilds the flags from `/proc/$pid/fd` -- and
then `sfdinit()` runs afterwards and overwrites its work.

Tcl decides whether it is interactive with `isatty(0)`
(`tclMain.c:365`). Tk's test suite drives a child `wish` over a pipe, so
the child believed it had a terminal and wrote its `"% "` prompt into
the pipe the parent was reading results from:

```
Error in startup script: unexpected output from background
process: "% foo"
```

which names neither isatty nor the pipe. The descriptor is the
authority and now wins in both directions.

Covered by `sys/lib/tests/isatty-test.c`, whose three cases -- a pipe, a
pipe moved onto descriptor 0 by dup2, and the same across an exec --
fail independently. Only the third involves `$_fdinfo`, so it is the
one that was broken; run it from an interactive shell, where descriptor
0 really is the console, or the inherited flag is absent and the bug
cannot reproduce.

### Three lines of flex, and three stdio bugs behind them

flex sends its output through a chain of filter processes,

```
flex -> filter_tee_header -> m4 -P -> filter_fix_linedirs -> lex.yy.c
```

and every child has to make the *stdin FILE* refer to a new descriptor,
which C gives no way to do. `filter_apply_chain` dup2s onto
`fileno(stdin)` and then resynchronises the stream (`filter.c:164`):

```c
fseek (stdin, 0, SEEK_CUR);
ungetc (' ', stdin);
(void) fgetc (stdin);
```

push a character and take it straight back, touching the descriptor not
at all. flex's own comment calls it "a Hail Mary situation. It seems to
work." Each of those three lines found a different bug.

**`fseek` set the error indicator when the seek failed.** This is the
one that broke flex. C99 7.19.9.2p5 makes `fseek` "return nonzero only
for a request that cannot be satisfied"; it says nothing about `ferror`,
and neither glibc nor musl touches it -- a stream you cannot seek is not
a stream that has failed. A pipe is not seekable, so the `fseek` above
left `stdin` permanently in error, and this stdio's `fgets` tests that
explicitly:

```c
if(c==EOF && s==as || ferror(f)) return NULL;
```

so the first `fgets` in every filter returned NULL without reading a
byte. Each filter exited at once, m4 saw end of file on its input, and
flex died writing into a pipe with no reader.

Two more bugs sat in the same function, in both `fseek` and `fseeko`,
which were separate copies that had already drifted: a relative seek
ignored data sitting in the read buffer, so `fseek(f, 0, SEEK_CUR)` was
not the no-op it is meant to be and disagreed with `ftell`, which did
account for it; and both went straight to `lseek(f->fd)` and refused
`f->fd < 0`, so a stream from `fmemopen` or `open_memstream` -- no
descriptor, seeking through `f->seek` -- could not be sought at all,
though POSIX requires it. `fseek` delegates to `fseeko` now.
`rewind` also clears the error indicator, which 7.19.9.5 requires and
which is what distinguishes it from `fseek(f, 0L, SEEK_SET)`.

`ftell`/`ftello` still use `lseek(f->fd)` and so still fail on a
memstream. Do not "fix" them by calling `f->seek`: this tree's
`__stdio_seek` flushes and clears the buffers, unlike musl's, so ftell
would acquire side effects.

**`ungetc` refused a stream that had not been read yet.** A separate
bug on the same three lines, and a real one -- C99 7.19.7.11 guarantees
one character of pushback on any input stream, read from or not. It
returned EOF when `f->rpos` was null, with a comment saying `__toread`
must not be called because it resets `rpos`/`rend` and would destroy
buffered data. It only resets them when there are none: musl guards the
call with `!f->rpos`, which is true exactly when no read window exists.

This one only bit `stdin`, whose static `FILE` in `stdio/stdin.c` starts
with `rpos = rend = NULL`; `fopen` and `fdopen` leave a read window set
up, so those were fine. Left unfixed it would have cost the `fgetc`
after it a *real read on a pipe nothing had written to yet* -- every
filter blocking there, and the one that goes on to `execvp("m4")`
swallowing a bufferful into a `FILE` the exec was about to discard.

**`freopen` returned a new stream instead of reopening the given one.**
The third bug, and the one that sent the whole scanner to the terminal.
C99 7.19.5.4p2 makes `freopen` associate the *named file with the
stream it is given*; it returns that stream. This did

```c
if (f && f->fd >= 0) fclose(f);
fd = open(name, flags, 0666);
return __fdopen(fd, mode);
```

so the caller's stream was untouched. On a permanent stream it did
nothing at all: `fclose()` on `F_PERM` -- stdin, stdout, stderr --
flushes and returns *without closing the descriptor*, by design. fd 1
stayed on the terminal, `open()` took a fresh descriptor, and the new
`FILE` was discarded by every caller, since the return value is checked
against NULL and otherwise thrown away.

flex's `main.c:333` is `freopen (outfilename, "w+", stdout)` followed by
writing the scanner to `stdout`, so `lex.yy.c` was created by that
`open()` and never written to again. Now it is musl's: open the file as
a separate stream, `dup2` its descriptor onto the one the caller's
stream already uses, adopt its flags and hooks, close the temporary.
**`fileno(f)` must not change** -- flex then does
`dup2(pipe, fileno(stdout))` and forks children that inherit descriptor
1 expecting it to be the output file.

**What it cost:** an empty `lex.yy.c`, or flex killed by

```
flex: sys: write on closed pipe
```

neither of which mentions stdio. `objc`'s `lex.lm` is the only thing in
the tree that runs flex, so flex had never worked here -- and the empty
output looked like success, because `freopen` creates `lex.yy.c` before
any filter runs.

Covered by `sys/lib/tests/unget-pipe-test.c`. Note that a test here has
to *report* rather than exit: the child has several silent exit paths,
and a quiet child leaves the parent writing into a pipe with no reader,
so it dies of SIGPIPE before printing anything -- which is the same
mechanism that kills flex, and it hid the answer for a round trip.

### fclose left the standard streams open

`F_PERM` says the `FILE` is static and must not be freed. It does not
mean the file stays open. `fclose` returned early for such a stream:

```c
if (f->flags & F_PERM) {
	if (fflush(f) == EOF) error = EOF;
	return error;
}
```

so `fclose(stdout)` flushed and left descriptor 1 open. C99 7.19.5.1
grants no exemption to the standard streams -- fclose "causes the stream
to be flushed and the associated file to be closed" -- and musl calls
the close hook unconditionally, skipping only the `free`.

Closing stdout is how a program at the head of a pipeline says it is
done. flex's cleanup is

```c
fflush (stdout);
fclose (stdout);
while (wait (&child_status) > 0) ...
```

and with the descriptor still open the first filter never saw end of
file, nothing downstream could exit, and flex waited for children that
could not finish. `lex.yy.c` was complete on disk and the build simply
stopped, which `ps` showed exactly:

```
flex  Await		the parent, in wait()
flex  Pread		filter_tee_header
flex  Pread		filter_fix_linedirs
```

### <stdio.h> used to drag errno, unistd, fcntl and pthread in

`<stdio.h>` included `<stdio_impl.h>` — musl's *internal* header, which
opens with `<stdint.h> <stddef.h> <errno.h> <unistd.h> <fcntl.h>
<sys/types.h> <pthread.h>` because the implementation wants all of it.
So nearly every translation unit in the tree got every `O_` and `F_`
macro, all of unistd and all of pthread.

Not merely untidy: portable code guards its fallbacks on whether a name
exists, and a name appearing earlier than the author expected changes
the answer. libzip's `compat.h` does `#ifndef O_CLOEXEC / #define
O_CLOEXEC 0 / #endif` for Windows' sake, having included nothing that
leads to fcntl — but `<zip.h>` asks for stdio a little later, fcntl
arrives through the back door, and the two disagree.

`struct _IO_FILE` now lives in `sys/include/ape/_iofile.h` with only
`<stddef.h>`, `<stdint.h>` and `<sys/types.h>`; both `<stdio.h>` and
`stdio_impl.h` include that, and stdio_impl.h keeps its heavy includes
for the 64 files in `ap/stdio` that use it. This is musl's own
arrangement, restored.

**libap depended on the leak in two places**, and both are the shape to
expect elsewhere:

- `ap/include/musl.h` had `#ifndef errno / extern int errno;` — a
  reference to a symbol that exists nowhere, since APE's `<errno.h>` is
  `extern int *_errnoloc;` plus `#define errno (*_errnoloc)`. It never
  fired only because musl.h includes `<libc.h>` → `<utf.h>` →
  `<stdio.h>` → errno. It includes `<errno.h>` directly now.
- The `_unlocked` family existed *only* as four macros in stdio_impl.h,
  which musl has for its own use. `stdio/unlocked.c` defines all fifteen
  now and `<stdio.h>` declares them — as functions, not macros, because
  code that thinks a system lacks these writes an unguarded `#define
  ferror_unlocked(x) ferror(x)` and cpp rejects a non-identical macro
  redefinition (see the macro-identity section above). bash's config.h
  asserts `HAVE_DECL_{FEOF,FERROR,GETC,PUTC}_UNLOCKED`.

Locking in this stdio is a no-op — `stdio_impl.h`'s `__lockfile`
returns 0 without doing anything — so each `_unlocked` function is its
locked counterpart today. They are separate entry points so that the day
`flockfile` becomes real, `unlocked.c` is the one file to change.

### <string.h> reached Plan 9's <u.h>

The same shape as the `<stdio.h>` leak above, and found the same way —
by a port whose own names collided:

```
string.h -> wchar.h -> time.h -> signal.h -> pthread.h -> lock.h -> u.h
```

`<u.h>` is Plan 9's, and defines `nil`, `uchar`, `ushort`, `ulong` and
`uint`. So asking for `strlen` brought all of them. The Portable Object
Compiler is where it showed:

```
Object.m:28 ... Object.h:32 ... string.h:70 ... u.h:4
  Macro redefinition of nil
```

`objcrt.h:83` defines `nil` as `((id)0)`, as every Objective-C runtime
does, and guards it — so the unguarded definition in `u.h` simply lost
to whichever of the two came second.

**Every link in that chain existed for a pointer parameter**, and each
is now a forward declaration, which is the idiom `signal.h` was already
using one line above the offending include (`struct timespec; /* avoid
pulling in time.h */`):

- `string.h` wanted `wchar_t` for three APExp additions, and
  `<stddef.h>` — already included — provides it. This was also circular:
  `wchar.h` includes `string.h` back, so which definitions a file saw
  depended on which of the two it asked for first.
- `wchar.h` wanted `struct tm` for `wcsftime`.
- `time.h` wanted `struct sigevent` for `timer_create`.
- `signal.h` wanted `pthread_attr_t` for `struct sigevent`. That one is a
  typedef rather than a tag, so it is repeated under a `_PTHREAD_ATTR_T`
  guard in both headers.

`nil` in `u.h` is guarded now as well. `<pthread.h>` still reaches
`<lock.h>` and so `<u.h>` legitimately — `pthread_mutex_t` is built on
`Lock` — so that path stays, and a name as common as `nil` should not
be defined unconditionally at the end of it.

### Tk on Plan 9: a Tkp* hook never owns the struct

Tk's platform hooks are handed a generic Tk struct and are responsible
for the **platform resources hanging off it, never the struct itself**.
Generic Tk keeps using the struct the moment the hook returns, and frees
it when it is ready. This was got wrong twice, in
`sys/src/external/tk/plan9/`:

- `TkpDeleteFont` did `ckfree(p9f)`. `Tk_FreeFont` then reads
  `fontPtr->objRefCount` and frees it again.
- `TkpFreeColor` did `ckfree(tkColPtr)`. `Tk_FreeColor` then reads
  `hashPtr`, `nextPtr` and `objRefCount` and frees it again.

Both are a use-after-free followed by a double free, and both were
invisible until something released the resource **for real**. That is
the trap: a refcounted resource with more than one reference returns
early from `Tk_FreeX` and never reaches the hook, so a frame could be
created and destroyed all day while a label -- whose `-activebackground`
border was the first genuinely released -- killed the process. Compare
`tkUnixFont.c`'s `ReleaseFont` and `tkUnixColor.c`'s `TkpFreeColor`:
neither touches the struct.

Neither hook has anything to release on Plan 9 anyway. `XAllocColor`
here packs an RGB triple into a pixel value and allocates nothing, so
`TkpFreeColor` is empty.

**A stub that answers "failure" is not the same as a stub that answers
"nothing to do".** `XLoadFont` returned `None`, which Tk reads as *that
font could not be loaded* rather than *there is no font server*, so
`TkGetCursorByName` failed every widget with a `-cursor` default -- most
of them. It returns a non-zero id now; the value is only handed back to
`XCreateGlyphCursor`, which ignores it, because rio owns the pointer.

**The event source must let the notifier sleep.** `DisplaySetupProc` set
a zero maximum block time unconditionally, so every `wish` spun at 100%
CPU for its whole life. One `wish` still worked, having the machine to
itself; two starved each other, and Tk's test suite drives a child
`wish` over a pipe. `tkUnixEvent.c` sets zero only when events are
already queued; we cap the sleep at 20ms and poll on wakeup, since
`/dev/mouse` and `/dev/cons` are polled rather than registered with the
notifier.

Three scripts in `sys/lib/tests` came out of this and are the way back
in: `tk-childproc-test.tcl` (the two-wish handshake, with a repeat
count), `tk-runtest.tcl` (runs a test file with `source` traced and
`exit` intercepted) and `tk-widget-test.tcl` (font calls and widget
create/destroy, one at a time). The technique that actually worked, all
three times, was a `fprintf(stderr, ...)` at each step of the suspect
function -- not acid, which fights `wish` for the rio window.

### Tk on Plan 9: a keycode here is a keysym, whole

There is no keyboard map on Plan 9. `/dev/cons` gives a **rune**, not a
scan code, so the X two-step of keycode -> keysym has nothing to do and
the two are the same thing. Every function in `plan9/` that converts
between them is therefore the identity, and the one that was not is the
one that broke.

`XKeysymToKeycode` masked with `0xFF`. That is fine for Latin-1 and
wrong for everything else, because **every special key lives in the
0xFF00 page**: `XK_Up` is 0xFF52, so it arrived as 0x52, `R`. Down was
`T`, Return 0x0D, and the whole page collapsed onto ASCII. `KeyCode` is
an `unsigned int` in this shim (`xlib/X11/X.h:112`, widened for the Mac
IME) and `XKeyEvent.keycode` is one too, so there was never a reason to
narrow it.

Three hooks `tkBind.c` needs were empty stubs, in
`plan9/tkPlan9Stubs.c`:

- `TkpSetKeycodeAndState` -- `event generate` calls it at
  `tkBind.c:4156` and then refuses the event if `keycode == 0`. Doing
  nothing is how `event generate .f <Key-a>` became
  `no keycode for keysym "a"`, and it is why `bind.test` alone had 146
  failures, all of them key events.
- `TkpGetKeySym` -- returned `NoSymbol` for anything that was not a
  `KeyPress`, so the release half of every binding was lost.
- `TkpGetString` -- `%A` in a binding script.

**A key event must name a window Tk knows.** `GenerateKeyEvent` sent
every keystroke to the root, and `Tk_HandleEvent` drops an event whose
window has no `TkWindow` -- so real typing was discarded before
`TkFocusKeyEvent` could redirect it to the focus widget. Nothing here
can ask who has focus (rio owns the keyboard), so Tk is the authority:
`TkpChangeFocus` records the toplevel through `XSetInputFocus`, and
`TkP9FocusWindow` hands it back, falling back to the first mapped child
of the root. Note this is invisible to `event generate`, which names its
own window -- so the synthetic and the real path fail separately, and
`tk-bind-test.tcl` only covers the synthetic one.

### Tk on Plan 9: no VisibilityNotify, so `focus -force` before `update` did nothing

`focus -force .w` on a window that is not yet mapped cannot set the
focus, so `TkSetFocusWin` does not fail -- it **defers**:

```c
if (!allMapped) {
	Tk_CreateEventHandler((Tk_Window) winPtr, VisibilityChangeMask,
	        FocusMapProc, winPtr);
	displayFocusPtr->focusOnMapPtr = winPtr;
	return;
}
```

and `FocusMapProc` finishes the job when the window turns up. `XMapWindow`
here sent `MapNotify` and `Expose` but no `VisibilityNotify`, so that
handler never fired and the focus was never set.

The idiom this breaks is the one every Tk test file opens with:

```tcl
pack .t.f
focus -force .t.f
update
```

`pack` maps on the idle queue, so at the moment of the focus command
`.t.f` is still unmapped and the deferred path is the *only* path.

**Key events are the only thing that notices.** They alone are
redirected through the focus -- `InvokeFocusHandlers` (`tkEvent.c:255`)
calls `TkFocusKeyEvent`, which returns NULL when there is no focus
window, and `Tk_HandleEvent` then discards the event. So a `<Button-1>`
binding on a widget worked while every `<Key>` binding on the *same*
widget silently did nothing, and `bind.test` failed 134 cases with empty
results and no errors anywhere.

Reordering the two lines makes it work, which is what made this hard to
see: `sys/lib/tests/tk-bind-test.tcl` passed its key cases because it
had `update` before `focus -force`, the one order bind.test never uses.
`focus` answering `.f` rather than empty was the tell -- neither
clearing path in `TkFocusFilterEvent` leaves a name behind, both assign
NULL, so the focus had never moved in the first place.

`TkP9EnqueueEvent`'s ring is 1024 entries now (`TKP9_EVQUEUE`, and the
wrap derives from it rather than a hardcoded `& 255`): mapping one
window costs three events, and a full ring is dropped silently.

### Tk on Plan 9: the clipboard is /dev/snarf

Plan 9 has one system-wide cut buffer, `/dev/snarf`, served by rio, so
PRIMARY and CLIPBOARD both map onto it -- which is what a user wants
anyway: snarf in an editor, paste into a Tk entry.

Both directions were missing, and they fail independently:

- `TkSelGetSelection` answered `"selection not supported"`. That is the
  hook for a selection **this application does not own**; a locally
  owned one is served by `tkSelect.c` from its own handlers and never
  reaches the platform (`Tk_GetSelection`), so `clipboard get` right
  after `clipboard append` worked and hid half the gap.
- `TkSelUpdateClipboard` was `#define TkSelUpdateClipboard(a,b) {}` in
  `tkPlan9Port.h`, so nothing a Tk program copied ever left the process.

`tkp9_getsnarf`/`tkp9_putsnarf` in `tkPlan9DrawImpl.c` open, do their
business and close every time: rio serves the whole buffer from offset 0
of a freshly opened `/dev/snarf` and there is no change notification, so
a held descriptor reads a stale copy. The contents are UTF-8, which is
what a `UTF8_STRING` target wants and what Plan 9 uses natively, so
nothing is converted.

`TkSelUpdateClipboard` rebuilds the whole buffer from
`dispPtr->clipTargetPtr` on every clear and every append rather than
trying to append -- rio offers no way to append to `/dev/snarf`, and a
clear then correctly leaves it empty.

Covered by `sys/lib/tests/tk-selection-test.tcl`, which tests the two
directions separately and skips itself when `/dev/snarf` cannot be
opened (there is no snarf file without rio).

### Tk on Plan 9: modifier keys are not events of their own

`tkBind.c` consults `dispPtr->modKeyCodes` twice, and both uses are
about *not* letting a modifier press count as an event in its own right:

- `tkBind.c:2226` -- a modifier press must not reset the repetition
  count for buttons, or `<Double-Button-1>` is lost the moment a shift
  key is touched between the two clicks.
- `tkBind.c:2809` -- a modifier-only press must not drop a partly
  matched pattern sequence, or `<Escape><Control-c>` can never be
  triggered from a real keyboard: what arrives is Escape, then
  `Control_L` repeating while held, then `Control-c`.

`TkpInitKeymapInfo` set the three modifier masks and left the array
empty, so neither rule could fire. There is no modifier map to read --
`/dev/cons` gives a rune -- so it is now simply the list of modifier
keysyms, which are the keycodes here. `lockUsage` is `LU_IGNORE`:
nothing sets `LockMask`, so there is no Lock modifier to reinterpret.

Related, and the same "no keyboard map" problem: X decides whether a
key event carries `ShiftMask` by asking which shift level of the keycode
produced the keysym. `TkP9KeysymShifted` answers it from the keysym
alone -- a character with a lowercase form is the shifted one -- which
covers A-Z and the accented capitals and is what makes
`bind .e <Shift-Key-A>` fire. Which *punctuation* needs Shift is a
property of the physical layout and is not knowable here, so those are
reported unshifted.

### Build order for compiler changes
```
cd sys/src/cmd/cc && mk nuke && mk install   # regenerates y.tab.h
cd sys/src/cmd/6c && mk nuke && mk install   # (and all other *c dirs)
cd sys/src/cmd/cpp && mk nuke && mk install
```
`cc` must build first because `y.tab.h` (with token defines like `LTYPEOF`,
`LALIGNOF`, `LGENERIC`, `LNULLPTR`, `LSTATICASSERT`) is consumed by `lex.c`
in each arch compiler.

### CLOCAL vs CSTATIC
Inside a function, `static` variables get class `CLOCAL` (not `CSTATIC`).
Every arch's `txt.c` must handle both. There are three locations:
global emit loop, naddr ONAME case, gpseudo D_STATIC selection.

### ar duplicate-symbol handling
The `ar` tool's `rcmd()` must use per-member `dupfound` reset + `continue`
(not global abort). The arch/amd64 directory builds last specifically so
assembly implementations overwrite C port versions via the duplicate-skip mechanism.

### typesuvinit[] — do not add TVLONG/TUVLONG
Adding `TVLONG`/`TUVLONG` to `typesuvinit[]` in `cc/sub.c` breaks the entire
ABI by making vlong-returning functions use struct-return convention.
The correct content: `{ TSTRUCT, TUNION, TCFLOAT, TCDOUBLE, -1 }`.

### Mixed-signedness compound assignment (FIXED)

`E1 op= E2` where E1 is signed and E2 unsigned does the operation
**signed**. C99 6.5.16.2p3 makes it equivalent to `E1 = E1 op (E2)`, so
the usual arithmetic conversions apply to the operation and only the
result is converted back to E1's type.

```c
vlong  rv1 = -1;
vlong  rv2 = 2;
rv1 /= (uvlong)rv2;     /* gives 0; should give 0x7fffffffffffffff */
rv1 %= (uvlong)rv2;     /* gives -1; should give 1                */
```

Confirmed by `sys/lib/tests/compound-assign-test.c`, which also shows
the fully-cast and simple-assignment forms are correct — so it is `op=`
alone, not the division.

Where: `cc/com.c` `case OASDIV:` (~line 243) and `case OASMOD:` (~line
310). `arith(n, 0)` correctly sets `n->type` to the promoted type, but
then

```c
if(!mixedasop(t, n->type)) {
        if(!sametype(t, n->type)) {
                r = new1(OCAST, n->right, Z);
                r->type = t;      /* casts the RHS back down to E1's type */
                n->right = r;
                n->type = t;
        }
}
if(typeu[n->type->etype]) {       /* n->type is now t, so this misses */
        if(n->op == OASDIV)
                n->op = OASLDIV;  /* ... and the unsigned opcode is never chosen */
```

`mixedasop` only detects an integer lvalue with a *floating* RHS
(`sub.c`: `!typefd[l->etype] && typefd[r->etype]`), so a signed/unsigned
pair takes the first branch. The opcode is selected from `n->type`
*after* it has been overwritten with `t`, so it is chosen from E1's type
rather than from the type the operation is performed in.

Fixed by reading the promoted type's signedness into a local, `uns`,
immediately after `arith(n, 0)` and before those branches overwrite
`n->type`, then selecting the opcode from `uns`. Both sites; `OASMUL`
and `OASLMUL` fall into the `OASDIV` case, so `*=` is covered too.

The shift case above it needs no change and must not get one: C99
6.5.7p3 gives `E1 << E2` the promoted type of the *left* operand, so
reading the lvalue's type there is already right.

Still wrong, and a separate problem: kencc performs a compound
assignment in the lvalue's own width, casting the right operand down
first. `long x; x /= (uvlong)y;` therefore divides in 32 bits on amd64
where C requires 64. Fixing that means rewriting `E1 op= E2` as
`E1 = (T1)(E1 op E2)`, far more than choosing an opcode.
`compound-assign-test.c` reports it without counting it as a failure.

Found via cpp's `#if` evaluator, which did `rv1 /= (uvlong)rv2` to
divide unsigned. `UINTMAX_MAX / 2` came out 0, so GNU tar's

    #if ! (INTMAX_MAX <= UINTMAX_MAX / 2)

fired its `#error`. cpp no longer relies on the implicit conversion.
Any other `signed_lvalue op= (unsigned)x` in the tree is still wrong.

### Spilling a fixed register saved only the operation's width (FIXED)

`6c/cgen.c` spills AX, CX or DX where the instruction it is about to emit
can only use that register — a divide or modulo needs AX and DX, a
variable shift needs CX. The save was

```c
if(nodreg(&nod, nn, D_AX)) {
        regsalloc(&nod2, n);      /* slot sized from n, the divide */
        gmove(&nod, &nod2);       /* ... so a 32-bit save */
```

`regsalloc` takes its size from the node handed to it, and `n` is the
divide or the shift. So a **32-bit** operation spilled **four** bytes of a
register that might be holding eight, and the top half was lost. What is
live in AX at that moment belongs to some earlier part of the
expression and has nothing to do with the type of the operation being
generated.

Found in LibreSSL's Keccak:

```c
t0 = bc[(i + 4) % 5] ^ crypto_rol_u64(bc[(i + 1) % 5], 1);
```

`cgen`'s `OXOR` case evaluates the call first, because `OFUNC` has
`complex == FNX`, and it lands in AX. Then `bc[(i + 4) % 5]` needs AX for
the 32-bit `% 5`, spills it four bytes wide, and `crypto_rol_u64`'s
`uint64_t` result comes back with bits 32..63 cleared. The *identical*
call two lines below, `st[j] = crypto_rol_u64(t0, rotc[i])`, is correct —
no division beside it.

The trigger is exactly `<expression containing / or %> op <64-bit
function call>`, and `%` has to be in the **other operand**, not in the
call's arguments: an argument is evaluated before the call, so nothing
64-bit is live yet.

Fixed with `regwide()`/`regspill()` at the head of `cgen.c`: the save
uses a full-width alias of the register and an 8-byte slot, and the
narrow node is left alone because callers still need it at the
operation's own type for the result. Six sites — AX and DX in
`ODIV`/`OMOD` and in the `OAS*` forms, CX in both shift cases.

Only `6c` has this. `8c` is 32-bit, so a one-register save cannot
truncate; the RISC back-ends need no fixed register for division, and
their one `regsalloc(&nod, n)` is `OFUNC` with a discarded result, where
`n` *is* the call and its type is right.

What it cost: every SHA-3 digest was wrong, so ML-KEM was wrong, so
every TLS 1.3 handshake offering X25519MLKEM768 failed at the first
encrypted record with `bad decrypt` — while TLS 1.2 and
`-groups X25519` worked, because nothing else in a handshake uses
Keccak. **Nothing about this is Keccak-specific.** A 64-bit value live
across a 32-bit `%` is ordinary C, so anything built before this fix is
suspect and wants rebuilding.

Covered by `sys/lib/tests/rol64-test.c`, which isolates the trigger
one variable at a time, and by the Keccak vectors in
`sys/src/ape/lib/libressl/test/`.

### #include nesting limit was 20

`cpp/include.c` had the depth guard written as a bare `20`. That is a guard
against a circular include, and it also stopped LibreSSL, which reaches 20 on
an ordinary chain with nothing repeated in it:

```
pthread.h compat/pthread.h signal.h time.h compat/time.h sys/stat.h
compat/sys/stat.h unistd.h compat/unistd.h stdio_impl.h stdio.h
compat/stdio.h utf.h wchar.h string.h compat/string.h netinet/in.h
compat/netinet/in.h sys/socket.h compat/sys/socket.h  ->  b_sock.c
```

LibreSSL ships a `compat/` header for most system headers, each ending in an
`#include_next` of the real one, so every step of a normal chain counts twice.

Now `NINCDEPTH` in `cpp.h`, set to 200, which is what gcc and clang use for
`-fmax-include-depth`. A genuine cycle passes 200 as fast as it passed 20.
`incdepth` is a depth and not a count — `cpp.c:52` decrements it at each
end-of-file — so this does not make a file with many includes any dearer.

`NIF`, the `#if` nesting limit, is still 32 and has not been a problem.

### Pointer signedness is a warning, not an error

`char *` and `unsigned char *` are distinct types, so passing one where the
other is declared is a constraint violation and C requires a diagnostic. gcc
and clang give a warning — `-Wpointer-sign`, not in `-Werror` by default — so
portable C is full of it, and there is no spelling that avoids a cast at every
call. kencc used to refuse:

```
a_object.c:185 argument prototype mismatch "IND CHAR" for "IND CONST UCHAR":
  CBB_add_bytes
```

from LibreSSL's `CBB_add_bytes(cbb, s, n)` with `char s[22]` against
`int CBB_add_bytes(CBB *, const uint8_t *, size_t)`.

`-Wpointer-sign` is not about `char`, and LibreSSL hit the `int` case next:

```
e_sm4.c:241 argument prototype mismatch "IND INT" for "IND UINT":
  CRYPTO_ctr128_encrypt
```

from `&ctx->num`, an `int *`, against `unsigned int *num`.

There are **two** sites, because static initializers do not go through
`stcompat()`. `cc/dcl.c` `init1()` has its own `sametype()` test and gave

```
s_client.c:540 initialization of incompatible pointers: s_client_options
  IND INT and IND UINT
```

for `.opt.value = &cfg.off` with `unsigned int off` against the union's
`int *value`. Both sites now call `ptrsignonly()` (declared in `cc.h`) and
warn instead.

`cc/sub.c` `stcompat()` calls it in the `BIND`/`TIND` branch. **One level only, and only when the two pointees are the
signed and unsigned spellings of the same type** — the five pairs are listed
in `pairs[]` there. Still errors: `int *` for `char *`; `int *` for
`unsigned long *`, which are the same width on amd64 but are not a
signed/unsigned pair, and which gcc calls incompatible pointer types rather
than a signedness difference; and `char **` for `unsigned char **`, which is
the case where the difference can actually be observed.

This cannot change code generation: a type and its opposite signedness have
the same representation, so the only thing that differs is whether a
diagnostic is fatal. `warn()` is gated on `debug['w']`, so it is quiet unless `-w` is passed.

Note `rsametype()` in `dcl.c` compares `etype` and the `GNORET` bit and
nothing else — it already ignores `const` and `volatile`, which is why
`char *` → `const char *` was never the problem here.

Covered by `sys/lib/tests/charptr-test.c`, whose real test is that it
compiles: every case in it is a constraint violation of that shape.

### Designators are relative to the enclosing brace list (FIXED)

C99 6.7.8p17: a designator is interpreted relative to the object of the
*enclosing brace list*. Reaching into a sub-object with a nested designator
does not leave the current object there, because no braces were opened:

```c
struct s x = { .inner.v = &n, .v = 1 };   /* .v is the OUTER v */
```

`init1()` in `dcl.c` restarted its member walk at whatever level it was in
(`goto again`), so having entered `inner` to satisfy `.inner.v`, the next
designator matched `inner`'s members first. Found via LibreSSL's
`apps/openssl/ciphers.c`, which has an `int *value` inside a named union and
a `const int value` beside it:

```
ciphers.c:55 initialize pointer to an integer: ciphers_options
```

Fixed by breaking out of the member loop instead of `goto again` when
`exflag` is set — `exflag` means "entered implicitly, without braces of our
own", so a designator seen at that point belongs to an enclosing level.
The existing code already returned without consuming when the designator
named *no* member here; this extends that to the case where it names one by
coincidence. The braced case keeps `exflag == 0` (via `doinit`) and so still
restarts, which is correct.

The union is incidental — two members of the same name at different depths
are enough. **When the two have the same type there is no diagnostic at
all**: the value simply lands at the wrong offset. `ciphers.c` was only
caught because `int *` and `const int` disagree.

Covered by `sys/lib/tests/designated-init-test.c`, whose case 3 is the silent
variety.

### Macro identity includes whether there is white space

C99 6.10.3p2: two definitions of the same macro are the same only if the
*presence* of white-space separation matches at every point (the amount does
not matter). `cpp/macro.c`'s `comparetokens()` implements exactly that:

```c
(tp1->wslen==0) != (tp2->wslen==0)
```

So a definition differing only in spacing is a **redefinition error**, not a
harmless repetition. This has now bitten twice, and both times the other
definition was unguarded, so APExp's spelling is the one that had to move:

- `weak_alias` — `<features.h>` said `(old, new)`, gnulib's `libc-config.h`
  says `(name, aliasname)`. Parameter names count as tokens.
- `S_IXUGO` — APE said `(S_IXUSR|S_IXGRP|S_IXOTH)`, and gnulib, gtar,
  diffutils, bison and readline all say `(S_IXUSR | S_IXGRP | S_IXOTH)`.
  readline's `posixstat.h:160` has no guard, so the two met on a full rebuild.

Only *interior* white space counts. `tokens.c` `normtokenrow()` ends with

```c
if (ntrp->lp > ntrp->bp)
        ntrp->bp->wslen = 0;
```

so the first body token's leading space is discarded for both `#define` and
`-D`. That is why `-DO_BINARY=0` on a command line coexists with
`#define O_BINARY	0` in `<fcntl.h>`, while `S_IXUGO`'s spacing *between*
its tokens did not.

**Rule:** when adding a macro to an APE header that portable code also
defines, copy the upstream spelling character for character, and guard it.
Guarding alone is not enough — it only helps when APExp's header is read
second.

**Corollary for `-D` workarounds.** A `-DNAME=VALUE` in a mkfile that exists
only because APE lacked `NAME` becomes a redefinition error the moment APE
gains it. `sys/src/ape/cmd/libtool/mkfile` carried `-DESTALE=EDEADLK` for
exactly that reason and had to lose it when `<errno.h>` gained `ESTALE`. When
adding a name to an APE header, grep the mkfiles for `-D<name>=`.

`/tmp`-style one-off check, if this is suspected again: compare token
sequences *with* leading-whitespace flags between APE's headers and unguarded
`#define`s under `sys/src/external`. The only other whitespace-only pairs
today are inert — `.in.h` templates that are never compiled, and per-package
vendored copies (bison's own `obstack.h`, tk's `MIN`/`MAX`) that never meet
APE's headers.

### Unsigned 64-bit to floating point (FIXED)

Both halves of this conversion were wrong, and neither mattered until
`SIZE_MAX` became a 64-bit constant.

**Constant folding, `cc/scon.c` `OCAST`.** A cast of a constant folds through
`n->vconst`, which is a `vlong`, so an unsigned source with the top bit set
came out negative: `(double)(uvlong)~0` gave `-1.0`. Fixed by reading it back
unsigned when `typeu[et]`.

**Runtime, `6c/txt.c` `CASE(TUVLONG, TDOUBLE)`.** The top-bit case is handled
correctly — halve, convert, double — and then the result was never stored:
the `gmove(&nod1, t)` that the `TULONG` case beside it has was missing.
`regalloc(&nod1, t, t)` reuses `t`'s register when `t` is one, so this was
invisible whenever the destination was a register and silent nonsense when it
was memory.

What it cost: gnulib's `hash.c` has

```c
float new_candidate = candidate / tuning->growth_threshold;
if (SIZE_MAX <= new_candidate)
  return 0;
```

which folded to `-1.0 <= 128.75`, true. `compute_bucket_size` returned 0,
`hash_initialize` returned NULL, and every program that hashes — `cp`, `mv`,
`ln`, `du` — died with "memory exhausted" before looking at its arguments.

Still wrong, and not reached by anything here: the reverse direction in the
same `scon.c` case, `v = l->fconst` for a float constant cast to an unsigned
integer type, for values at or above 2**63.

Covered by `sys/lib/tests/u64float-test.c`, which tests the folded and the
runtime path separately, and the memory destination specifically.

### bool was a signed char, so converting to it truncated (FIXED)

C99 6.3.1.2: "When any scalar value is converted to `_Bool`, the result
is 0 if the value compares equal to 0; otherwise, the result is 1."
It is a **comparison**, not a truncation, and that is what makes `bool`
usable as a flag at all.

kencc had no bool. `lex.c`'s `itab` mapped both `_Bool` and `bool` to
`LCHAR`, and the grammar's `tname: LCHAR` yields `BCHAR` — so `bool` was
a plain **signed char**, and every conversion to it kept the low byte:

```c
bool b = 256;              /* false */
op->moresib = (bool)ptr;   /* 0 for every aligned pointer */
```

An object pointer is 8-byte aligned, so its low byte is always even;
store that in a one-bit bit field, which keeps bit 0, and the answer is
always 0. (The bit field is behaving correctly — the conversion in front
of it is what was wrong.)

**What it cost.** perl's `handy.h` has `#define cBOOL(cbool) ((bool)
(cbool))`, and `op.h` records whether an op has a next sibling with
`OpMAYBESIB_set(o, sib, parent)`, which is the *only* thing that ever
sets `op_moresib` to 1 — `op_prepend_elem` and `op_append_elem` both
reach it through `op_sibling_splice`. So every op in every program perl
compiled came out with `op_moresib = 0` beside a perfectly good
`op_sibparent`. `Perl_op_linklist` walks a node's children with
`OpSIBLING`, which reads that flag, so **every statement list collapsed
to its first element**: the `op_next` chain for `print "hi\n"` was
`enter, leave`. miniperl parsed its input, reported syntax errors
correctly, ran `BEGIN` and `END` blocks, and executed none of the
program in between — no output, no diagnostic, exit status 0.

**Fix.** `bool`/`_Bool` get their own token `LBOOL` and their own
`Type`, `typebool`: unsigned char's representation, width and alignment
under a distinct identity. It is built in the `complex` production
rather than `tname`, because `tname` yields a bit in a type mask and the
mask has **no spare bit** — `BNORET` is already `1<<31` in a 32-bit
`long`. `com.c`'s `boolnorm()` wraps the value in `!!`, which `tcomo`'s
`ONOT` case gives type int, so the narrowing cast that follows sees a
value that is already 0 or 1.

**The mark is `Type.isbool`, a field, not the identity of `typebool`.**
`copytyp()` is a struct copy and a type gets copied whenever it is used
for anything — `dcl.c:996` copies a parameter's type to chain it into a
prototype, `garbt()` copies for `const`/`volatile`. Pointer identity
survives a cast and a return but not a declaration or a parameter, which
is exactly the set that still failed when the first attempt used it.

Applied at **five** sites, one per kind of conversion: the explicit cast
and assignment (`OAS`) and return (`ORETURN`) in `tcomo`, argument
passing in `tcoma` — before the promotion that turns a `bool` parameter
into `unsigned int` — and `OASI`, which is auto initialisation and has
its own copy of the conversion logic separate from `OAS`.

**Still wrong, narrowly:** a static or file-scope initialiser is folded
in `dcl.c` without going through `com.c`, so `static bool b = 256;`
truncates. An auto `bool b = expr;` is an `OASI` and is covered.

Covered by `sys/lib/tests/bool-test.c`.

**Anything using `bool` and built before this is suspect** — the same
warning as the 6c spill fix. gnulib, LibreSSL and curl all use `bool`
heavily. A `bool` that silently reads false for `0x100` is exactly the
class of bug that only shows up much later, somewhere else.

### Compiler self-hosting as correctness test
After any compiler change, have it rebuild itself multiple times:
```
cd sys/src/cmd/cc && mk nuke && mk install
cd sys/src/cmd/6c && mk nuke && mk install
# repeat — if the second build produces identical output, the compiler is consistent
```

### __typeof__ was silently broken
Before the LTYPEOF patch, `__typeof__(x)` was swallowed like `__attribute__`.
The entire argument `(x)` was consumed and the next token returned as if
`__typeof__` never existed. Any code using `__typeof__` in declarations
was silently corrupted. The fix is in `lex.c` — remove from swallow block,
add to itab as LTYPEOF.

### _Generic association type matching
Uses `sametype()` which ignores const/volatile (only checks GNORET bit).
So `_Generic(x, const int: ..., int: ...)` would be ambiguous — both match.
This is correct per C11 §6.5.1.1p2 which says qualified/unqualified are compatible.
The `generic_ctrl_type()` helper also strips qualifiers from the controlling expression.

---

## Missing Declarations Audit (2026-04)

Scan of `sys/src/ape/lib/ap/**/*.c` vs `sys/include/ape/*.h` found ~85
functions in the library with no header declaration. Without a declaration,
kencc gives functions implicit `int` return type — silently truncating
pointer and float return values.

The math.h gap (30 functions) and the other missing declarations has been fixed.


