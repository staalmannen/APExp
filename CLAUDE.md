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

- **C99:** VLA, compound literals, hex floats (lexed since the start, but *converted* only since the `hexfloat()` fix -- see below), complex numbers, `//` comments, `_Bool`, designated initializers, `__alignof__`, `_Generic` (C11/C23), unicode escapes
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
`format-arg-test.c`, `unget-pipe-test.c`, `isatty-test.c`,
`sincos-test.c`, `explog-test.c`, `fparith-test.c`,
`float-overflow-test.c`, `malloc-reuse-test.c` and
`stdio-test.c`. The nineteen `tk-*.tcl` scripts there are Tcl, run with
`wish`; see the Tk section below. `tk-runall.tcl` is the harness for
Tk's own suite rather than a test of its own, and `tk-runtest.tcl` runs
a single file from it. `sys/src/ape/lib/libressl/test/` is separate: it is
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

### Tk on Plan 9: a toplevel needs a geometry manager, even with no wm

Tk never sizes a toplevel itself. It hands the job to the window
manager through `Tk_ManageGeometry`, and when the contents of a toplevel
want more room, pack/grid/place call `Tk_GeometryRequest`, which reaches
the wm's `requestProc` **and nowhere else**. `TkWmNewWindow` was an
empty stub, so no toplevel was ever managed and no toplevel was ever
sized: every one stayed 1x1.

pack will not map a slave that does not fit, so this is silent and
looks like a delivery bug:

```tcl
toplevel .t -width 100 -height 50
pack [frame .t.f -width 150 -height 100]
pack [frame .t.g -width 150 -height 100]
```

leaves `.t` at 1x1 and `.t.g` unmapped, with no error. It is also why
widgets in a second toplevel piled into the corner at their minimum
size.

`tkPlan9Wm.c` now keeps a `WmInfo` per toplevel and does the smallest
thing that stands in for a window manager: honour an explicit
`wm geometry`, otherwise take the requested size, clamp to
minsize/maxsize, resize. Updates are deferred to idle time and
suppressed until the first map (`WM_NEVER_MAPPED`), as `tkUnixWm.c`
does, so a window is not resized repeatedly while it is being built.

Two things this depends on:

- **`XMoveWindow`/`XMoveResizeWindow` must report a ConfigureNotify.**
  Only `XResizeWindow` did. On X the server sends it and everything
  that relays out on `<Configure>` hangs off it.
- **The size is written into `winPtr->changes` directly.** On X, Tk
  learns a toplevel's new size from the server's ConfigureNotify; there
  is no server here. The early return when nothing changed is what stops
  the resize/Configure/re-request cycle from looping.

`Tk_WmObjCmd` never resolved its window argument at all, so every
setting form was a silent no-op -- `wm geometry .t 200x100` changed
nothing and reported no error -- and the query was a hardcoded
`"1x1+0+0"`, which is a very convincing wrong answer.

### Tk on Plan 9: TkpGetNativeFont has to be able to fail

`tkFont.c` asks the platform for a *native* font name first, and when
that returns NULL it parses the string itself -- as an XLFD, as a
`{family size style}` list, or as `-family`/`-size` option pairs -- and
comes back through `TkpGetFontFromAttributes`. **Failing is the
contract.** This port accepted every string and opened libdraw's default
font for it, so the parsing never happened:

```
font actual {Helvetica -12}   ->  -family {Helvetica -12} -size 18
font actual -xyz-times-*-...  ->  the whole XLFD as the family
.l configure -font {}         ->  accepted, and must be an error
```

Sizes and styles were therefore ignored everywhere, which is 45 of
font.test's failures plus `button-1.104..110` and `canvasText-1.7`.

The only genuinely native name here is the path of a Plan 9 font file,
so `TkpGetNativeFont` now refuses anything not starting with `/`, and
`tkp9_openfontpath` opens exactly that file or fails -- `tkp9_openfont`
falls back to the default font, which is the wrong answer when the
caller needs to know whether a file exists.

Plan 9 bitmap fonts come in discrete sizes, one file each, so
`TkpGetFontFromAttributes` picks the nearest by pixel height from a
table and skips candidates that will not open. The table began as a
guess at what a 9front install ships; `sys/lib/tests/tk-font-test.tcl`
prints the real `/lib/font/bit` inventory, which is what to correct it
against, and it has now been checked against one. A wrong entry costs
size accuracy and nothing else -- a candidate that will not open is
skipped -- so the one error found (`lucida/unicode.5`, which does not
exist; lucida's `unicode.*` starts at 6) was silent.

**`font families` lists four and `font actual` reports three.** The
list is `courier fixed helvetica times`, but `ChooseFont` resolves every
request to one of `courier`, `times` and `helvetica` -- a request for
`fixed` is monospaced, so it comes back as `courier`. That is the wrong
way round for font.test's idiom, which decides whether a family exists
by asking whether `font actual {X 12} -family` is still `X`: `fixed` is
advertised and then denied. Either drop it from the list or report it.

`fm.fixed` is measured (`width("i") == width("W")`) rather than assumed:
Tk uses it to skip measuring character by character, so claiming it for
a proportional font mislays every string.

**`font actual` reports what was resolved, not what was asked for.**
`tkUnixFont.c` reports the family of the X font it actually found, and
code relies on that: font.test asks

```tcl
if {[font actual {avantgarde 12 roman normal} -family] eq "avantgarde"}
```

to decide whether the machine really has that family, and took the wrong
branch while every request answered with its own name. There are three
families here -- courier, times, helvetica -- whatever was requested.

The **size is reported in points**, which is what makes `font actual
-size` depend on `tk scaling`: Tk stores a negative size as pixels, so at
scaling 0.5 a request for `-13` pixels is 26 points (font-44.1).
`TkFontGetPixels` on the way in, `TkFontGetPoints` on the way out, as
`tkUnixFont.c` does.

### Tk on Plan 9: stacking order, and the two coordinate spaces

Three separate things were missing here, and they hide each other:

- `Tk_CoordsToWindow` was a stub returning NULL, so `winfo containing`
  answered the empty string for every point. `raise.test` decides the
  stacking order **entirely** by asking what is on top at a given pixel,
  so all eleven of its cases failed on that one line -- reporting
  `bad window path name ""`, which names neither stacking nor
  hit-testing.
- `TkWmRestackToplevel` was a no-op, so `raise`/`lower` on a toplevel
  did nothing.
- `XRaiseWindow`/`XLowerWindow` were no-ops. There is no compositing
  here -- drawing goes straight into the one rio window -- so a raised
  window stays buried under whatever was drawn over it until something
  makes it repaint. On X the server sends the Expose; nothing on Plan 9
  will, so `P9ExposeTree` does.

Tk already keeps the stacking order of a window's **children** itself,
in `parentPtr->childList`, later meaning higher (`Tk_RestackWindow`).
Toplevels have no such list, so this port keeps them in
`dispPtr->firstWmPtr` in the same convention: first is bottom, last is
top. `TkWmNewWindow` therefore appends rather than prepending as
`tkUnixWm.c` does -- there the X server owns the order.
`Tk_CoordsToWindow` walks both lists forward and keeps the **last**
match.

**The recurring trap in this file is that `P9Window.x`/`.y` are relative
to the parent, and event coordinates are relative to the screen.**
`WindowAtPoint` compared the two directly, so every nested window was
hit-tested at the wrong place -- a click landed on whichever widget
happened to sit at the same offset inside its own parent, and it looked
correct only for children of the root. `GenerateMouseEvent` then
computed the event's window-relative `x`/`y` with `pw->x` alone, one
level instead of the whole ancestry. `TkP9WindowOffset` is the accumulated
offset and is what both need. This is the same mistake the drawing code
made, and it is worth suspecting first whenever something lands in the
wrong place.

Covered by `sys/lib/tests/tk-stacking-test.tcl`, which tests the sibling
case (Tk's own childList) and the toplevel case (this port's list)
separately, because restacking with no hit-test reports nothing and
hit-testing with no restacking reports a stale but plausible answer.

### Tk on Plan 9: embedding is easy here, because there is one process

`Tk_UseWindow` answered `"-use not supported on Plan 9"`, which is every
test in `safe.test` and `safePrimarySelection.test` -- 34 of them --
because `safe::loadTk` **always** ends in `-use`. Given no `-use`
argument it builds a decorated toplevel containing a
`frame $w.c -container 1` and embeds into that
(`library/safetk.tcl`, `tkTopLevel`).

`tkUnixEmbed.c` is 1200 lines because on X the container and the
embedded application are usually **separate clients**: it needs wrapper
windows, a property protocol to pass geometry between them, and an error
handler for when the other client dies mid-conversation. A safe
interpreter is a child interpreter in this same process, sharing this
window table, so the whole thing reduces to two rules:

- `Tk_MakeWindow` creates an embedded toplevel as a child of the
  container window instead of the root. That substitution *is* the
  embedding.
- The embedded toplevel does not size itself. `WmUpdateGeometry` passes
  its request to the container with `Tk_GeometryRequest` and then takes
  the container's size; a `<Configure>` on the container resizes the
  embedded window to match.

The `Container` list lives in `tkPlan9Wm.c` beside the two halves it
joins. `Tk_GetOtherWindow` walks it in both directions, which is always
answerable here -- on X it can only answer for a container and embedded
window in the same process.

Covered by `sys/lib/tests/tk-embed-test.tcl`, which checks the refusal
message for a non-container as well as the working case, since
safe.test's failures were reported entirely by message.

### Tk on Plan 9: the mouse goes through tkPointer.c, not hand-made events

`tkPointer.c` is the X server's pointer state machine reimplemented in
Tk for the platforms that have no server -- Windows and Mac. It is built
here (it is in the libtk mkfile) and this port never called it: the
event source built `MotionNotify` and `ButtonPress`/`ButtonRelease` by
hand and enqueued them.

What that loses is everything else an X server sends about the pointer.
Chiefly **EnterNotify/LeaveNotify were never generated at all**: no
`<Enter>`/`<Leave>` bindings, no hover highlighting, no grab handling
(so no modal dialogs), and no notion of which window has the mouse after
one is destroyed -- `event-9.*` is that case: destroy a toplevel over
`.` and `.` must see `<Enter>`.

`TkP9UpdatePointer` now hands the position, button state and the window
under the pointer (`Tk_CoordsToWindow`) to `Tk_UpdatePointer`, which
synthesises the lot. Two details it depends on:

- `XDestroyWindow` calls `TkPointerDeadWindow`, which `tkPointer.c`
  exports but declares in no header; the Windows and Mac ports call it
  from their destroy paths.
- A window mapped, unmapped or destroyed under a **stationary** pointer
  sets `gP9.pointerDirty`, and the next poll reports the same position
  again so the crossing events are generated. An X server does this
  unasked; nothing here will.

**`Tk_GetRootCoords` walked past the toplevel, so every toplevel but
`.` was in the wrong place.** The walk up `parentPtr` must **stop at a
window with `TK_TOP_LEVEL`**: a toplevel's `parentPtr` is its logical
Tk parent -- `.one`'s is `.` -- and its `changes.x/y` are already screen
coordinates, so continuing past it adds the parent's position to a
window that is not inside it. `tkUnixWm.c` breaks there; this walked the
whole chain.

Invisible while `.` sits at 0,0, which is why `tk-warp-test.tcl` never
caught it -- `.` is the one toplevel with no `parentPtr`. `event.test`'s
`setup_win_mousepointer` opens with

```tcl
wm geometry . +700+400; # root window out of our way
```

and that is what made it fatal rather than merely wrong: `.one` at
+100+100 was reported at **800,500**.

**Everything that asks where a window is went wrong with it** --
`winfo rootx`/`rooty` for any toplevel, `winfo containing`, and through
`Tk_CoordsToWindow` the entire pointer machinery, because a hit test
that finds nothing hands NULL to `Tk_UpdatePointer` and no crossing is
ever generated. That is the ten `event-9.*` failures, every one of them
stuck in that single setup line waiting for an `<Enter>` that could not
come, never reaching the behaviour it was written to test.

An **embedded** toplevel is the exception and must keep walking, through
its container rather than its parent. `tkUnixWm.c` consults the X server
when the container belongs to another application; here
`Tk_GetOtherWindow` can always answer, since the two share this process.

Covered by `sys/lib/tests/tk-enter-test.tcl`, which prints
`winfo rootx`/`width`/`ismapped` for each window before using it. One
line of that would have found this immediately; the round trip went on
the crossing machinery instead, which was correct all along.

**`winfo pointerxy` answered 0,0 whatever the pointer was doing.**
`TkGetPointerCoords` in `tkPlan9Wm.c` was a stub assigning 0 to both,
sitting a few hundred lines from an `XQueryPointer` that works. It is
`tkUnixWm.c`'s now: ask about the root window and take the coordinates
relative to it, which are the screen coordinates, and answer -1,-1 on
failure rather than a plausible 0,0.

That is the whole of `bind-34.1` and `bind-34.2`, and it is worth
reading as a lesson in reading a symptom. Both tests warp the pointer
and then read it back with `winfo pointerxy`, so `0 0` looks exactly
like a warp that never happened -- and the chain behind a warp is long
enough (`TkpWarpPointer` -> `XWarpPointer` -> `tkp9_warpmouse` -> a
write to `/dev/mouse`) to hold a plausible suspect at every link. It is
also silent at every link: `XWarpPointer` returns early without setting
`gP9.lastmouse` when the write fails, so a failed warp and a failed
readback are indistinguishable from Tcl.

**The tell was one line of `tk-warp-test.tcl`**: a real `<Motion>`
reported `%X %Y` as `397 124`, and `winfo pointerxy` on the next line
said `0 0`. `gP9.lastmouse` was demonstrably right, so nothing upstream
of the readback could be at fault. `$TKP9DEBUG` then confirmed the warp
end to end -- `/dev/mouse fd=7 writable=1`, `-> screen 120,120`,
`wrote "m120 120" ok` -- which is the evidence that the warp was never
the bug. **Two rounds were spent on the write before that**, on the
strength of a deduction that was sound except for assuming the readback
worked.

`Tk_GetPointerCoords` sat beside it, an identical stub, declared and
called nowhere in the tree -- dead code wearing the name of an API that
does not exist. Removed.

`Tk_MeasureChars` was rewritten at the same time to honour
`TK_WHOLE_WORDS` and `TK_AT_LEAST_ONE`, which it ignored:
`Tk_ComputeTextLayout` wraps with both set and expects a break at the
last word boundary that fits, or at least one character. Breaking at any
character put line breaks mid-word and in the wrong place for tabs
(font-24.*). The structure follows `tkUnixFont.c`.

### Tk on Plan 9: what the remaining test failures are, and which are ours

**THE SUITE NOW RUNS ALL 97 FILES AND EXITS CLEANLY**, since the
`TkScrollWindow` fix below and the window-table leak further down.
Everything above this line in the section was a 62-file prefix; the
table below is the whole thing, and the list has been re-derived rather
than extended.

```
all.tcl:  Total 10027  Passed 8427  Skipped 1429  Failed 171
Sourced 97 Test Files.
```

**171 failing tests**, from **485** on the first full run -- which was
up from 25 only because that run was the first to measure 35 files at
all, not a regression. Attributed by file across the runs:

| file | run 1 | run 2 | run 3 | run 4 | run 5 | run 6 | run 7 |
|---|---|---|---|---|---|---|---|
| `wm.test` | 202 | 130 | 74 | 66 | 62 | 62 | **14** |
| `unixWm.test` | 129 | 62 | 60 | 59 | 59 | 59 | **10** |
| `unixEmbed.test` | 29 | 29 | 29 | 29 | 28 | 28 | **30** |
| `textDisp.test` | 23 | 23 | 23 | 23 | 23 | 14 | 14 |
| `select.test` | 23 | 23 | 23 | 23 | 23 | 23 | 23 |
| `unixSelect.test` | 18 | 18 | 18 | 18 | 18 | 18 | 18 |
| `systray.test` | 13 | 13 | 13 | 13 | 12 | 12 | 12 |
| `winfo.test` | 6 | 4 | 4 | 4 | 4 | 4 | 4 |

**Run 7 is the wm work: 268 -> 171, and `wm` plus `unixWm` went 121 to
24.** It is also the run that shows why the per-file comparison is
worth doing rather than reading a total -- **`unixEmbed` went UP, 28 to
30**, and the total falling by 97 would have hidden it completely.

The two are `unixEmbed-10.1` and `10.2`, and `10.2` is one this file
had recorded as *fixed* two runs earlier. Both want `+0+0` from
`wm geometry` on an embedded toplevel and got back what was set. The
cause is the negative-geometry change in the same commit: the query now
reports `wmPtr->x/y` rather than `winPtr->changes.x/y`, which is right
for every other toplevel -- a window asked for at `-0-0` has to read
back as `-0-0`, not as the large positive coordinate it landed on --
and wrong for an embedded one, which has no position of its own.
Upstream zeroes it explicitly, with its own comment saying why:

```c
/* UpdateGeometryInfo, tkUnixWm.c */
wmPtr->x = wmPtr->y = 0;
wmPtr->flags &= ~(WM_NEGATIVE_X|WM_NEGATIVE_Y);
```

"embedded windows are not allowed to move". Upstream gates that on
`TK_EMBEDDED|TK_BOTH_HALVES` -- embedded *and* the container in this
same process, since otherwise it cannot know where the other
application put it; here both halves always share the process, so
`TK_EMBEDDED` alone is the same condition. Fixed in
`WmUpdateGeometry`'s embedded branch.

**Compare two runs by file before reading anything into a total.**
Run 6 differs from run 5 in exactly one line of that table -- textDisp
23 -> 14, nine tests, and every other file identical to the test. That
is the check that matters for a change touching `XDestroyWindow`,
`XUnmapWindow` and `XConfigureWindow`, which every widget in the suite
goes through: a mistake there would have been broad, and a total alone
cannot tell "nine fixed" from "fifteen fixed and six broken". The
commands are

```sh
grep '^==== ' run.out | grep ' FAILED$' |
	grep -v '^==== [a-zA-Z0-9._-]* FAILED$' |
	sed 's/^==== //; s/-[0-9].*//; s/^wm-.*/wm/' | sort | uniq -c
```

on each, then `diff`. The second `grep -v` drops tcltest's bare
repetition of the name, which is why `grep -c FAILED` doubles; the
`wm-*` collapse is because `wm.test` names its tests `wm-transient-1.1`
rather than `wm-1.1`.

Run 4 is the first one that finished, so it is also the first whose
total can be checked against tcltest's own rather than against
`grep -c FAILED` halved. The two agree: 278.

**That was written when everything outside `wm` was untouched**, and it
no longer holds: runs 5 and 6 fixed twelve in `unixEmbed` and
`textDisp`, and the four files that had had no attention have now been
read end to end -- see the section on them below. `wm` and `unixWm` are
still 121 of the 268 and are still where the bulk is.

The first-run breakdown, kept because the reasoning below refers to it:

| file | failing |
|---|---|
| `wm.test` | 202 |
| `unixWm.test` | 129 |
| `unixEmbed.test` | 29 |
| `textDisp.test` | 23 |
| `select.test` | 23 |
| `unixSelect.test` | 18 |
| `systray.test` | 13 |
| `winfo.test` | 6 |
| everything else | 42 across 22 files |

**`wm` is 331 of the 485, and it was mostly one cause -- now fixed.**
`Tk_WmObjCmd` in `tkPlan9Wm.c` lists 33 subcommands and implemented
**eleven**; the other 22 fell through to `default: return TCL_OK`.
All 33 have a real case now, and the `default:` arm **raises an error**
instead of succeeding, so the next subcommand added to `opts[]` without
an implementation cannot repeat this silently. (A check that the two
lists match: `awk` the `enum` block for `OPT_*` and compare against
`grep -o 'case OPT_[A-Z]*'` -- 33 and 33 today.)

**Result: 485 -> 345.** `wm.test` 202 -> 130, `unixWm.test` 129 -> 62.
Every storage subcommand dropped to one remaining failure each, and
that one is the usage case below.

Three of them were worth more than the storage:

- **`wm stackorder` answered an empty list**, 32 tests on its own.
  **The first attempt at this made it worse, on a claim that was
  false.** The note here said `TkWmStackorderToplevel` was "implemented
  in the same file" -- read out of a `grep` of the *name*, never the
  body. It was a three-line stub returning NULL. So rewriting
  `wm stackorder` to call it turned 31 of the 32 from answering an
  empty list into raising an error. **Open the function before saying
  it exists**; a grep hit is a name, not an implementation.

  It is real now. On X this needs `XQueryTree`, because the server owns
  the order and a window manager may have reparented every toplevel;
  here *this port* owns it and `dispPtr->firstWmPtr` is already the
  order the function must return, bottom first. So the whole job is to
  intersect that list with the mapped, non-embedded toplevels under
  `parentPtr` -- upstream's `TkWmStackorderToplevelWrapperMap` walk,
  minus the hash table, since there are no wrapper windows to key on.

- **The usage message was per-subcommand where it must be generic.**
  `wm stackorder` with no window answered
  `wm stackorder window ?isabove|isbelow window?`; every Tk answers
  `wm option window ?arg ...?`. Upstream checks `objc < 3` once, after
  resolving the subcommand index and before dispatching, so a
  subcommand's own `Tcl_WrongNumArgs` is only ever reached with a
  window present. That is **one failing test per subcommand** -- the
  `wm-*-1.1` "usage" cases -- and it is why the storage subcommands
  each still had exactly one failure after being implemented.
- **`wm iconify` and `wm grid` had no case at all**, so the new erroring
  `default:` would have turned two silent no-ops into hard failures --
  caught before shipping only by listing `opts[]` against the cases.
  `wm grid` goes through `Tk_SetGrid`/`Tk_UnsetGrid`, so it shares the
  grid-units convention documented below; `wm iconify` needs `iconic`
  to be **distinct from withdrawn** in `wm state`, hence a separate
  `iconified` field.
- **`wm iconname` was an alias for `wm title`.** They are different
  strings and wm.test sets one and reads the other.

`wm overrideredirect` is kept in `Tk_Attributes(tkwin)->override_redirect`
rather than in `WmInfo`, as upstream does: generic Tk reads it there
(menus and tooltips set it), so a private copy would be a second answer
to the same question.

`wm forget` and `wm manage` are still no-ops -- they are real
generic-Tk reparenting operations, seven tests, and doing them wrongly
is worse than not doing them.

**The remaining wm failures were not this**, as predicted -- `state`,
`iconify`, `minsize`, `maxsize`, `resizable` and `geometry` were all
implemented and still failing. `wm.test` went 202 -> 130 -> 74 over the
three runs. Two more causes found, both real behaviour rather than
bookkeeping:

**`wm minsize`/`maxsize` were clamped in the wrong units.**
`WmUpdateGeometry` converted grid units to pixels *first* and then
clamped, so

```tcl
wm grid .t 1 1 50 50
wm geom .t 4x4			;# 4 grid units = 200 pixels
wm minsize .t 8 8		;# 8 GRID UNITS
```

asked whether `200 < 8` and left the window at 4x4. min/max speak grid
units whenever the toplevel is gridded, exactly as `wm geometry` does --
the convention already documented below, which this one place did not
follow. The clamp now happens in those units and the conversion is last;
both helpers are the identity when `gridWin` is NULL, so the ungridded
path needs no branch. **The note below saying this was "inert today,
since the defaults are 1 and unlimited" was true only while the tests
that exercise it could not run.**

**`wm transient` is behaviour, not just storage**, and three rules were
missing:

- the master is resolved to its nearest **toplevel** ancestor, so
  `wm transient .subject .top.f` records `.top` and reads back as `.top`;
- a transient **cannot be iconified** -- upstream refuses with
  `can't iconify "%s": it is a transient`, because a dialog is shown and
  hidden with the window it belongs to;
- a transient made transient to an **iconic or withdrawn** master is
  withdrawn at once.

Only the state *at the moment of the call* is honoured. Upstream also
tracks the master afterwards through a structure handler on it; that is
a larger change and its tests are separate, so it is deliberately not
done here.

The eleven that were already implemented:
`geometry`, `minsize`, `maxsize`, `withdraw`, `deiconify`, `state`,
`stackorder`, `iconname`, `title`, `resizable`, `frame`. The other 22
answered nothing, which is why almost every failure in those two files
had the shape

```
got   {} {} {}
want  {} {3 4 10 2} {}
```

-- the test queries (empty), sets, queries again expecting what it set,
unsets, queries again. **This was `wm title` again, times 22** (see the
"four wm and keysym stubs that answered plausibly" section): the fact
that rio makes most of these do nothing is irrelevant to the *query*
contract, which is what the tests check and what portable Tk code reads
back -- `wm transient` to find a dialog's master, `wm protocol` to find
the `WM_DELETE_WINDOW` handler. They are stored in `WmInfo` and reported
back now, with upstream's argument checking and error messages, because
the tests check those too.

Storing is not the whole of it where a value can be *validated*:
`wm iconbitmap` resolves its bitmap, `wm iconphoto` its images,
`wm group`/`wm iconwindow`/`wm transient` their windows, and
`wm command`/`wm colormapwindows` must be proper lists. Accepting a
name that cannot be resolved is the same class of lie as answering the
empty string.

**It used not to exit cleanly, and this is how that was chased.**
**FIXED** -- the answer is the window-table leak at the end of this
subsection, and everything between here and there is the route to it,
kept because most of it is method rather than result. After the last
test of the last file `wish` used to die, at the same address every
run:

```
==== xmfbox-2.6 FAILED
wish 16510: suicide: sys: trap: general protection violation pc=0x26f694
```

**`tk-runall.tcl`'s completion marker was measuring nothing, and the
absence of it was not evidence of anything.** `tcltest::cleanupTests`
ends with

```tcl
/* tcltest.tcl:2630 */
if {[info exists ::tk_version] && ![testConstraint interactive]} {
	exit
}
```

so under `wish` **tcltest exits the application itself** once the last
file is summarised, and `source all.tcl` never returns. A marker written
after it could not print however well the run went -- which is exactly
what was seen: a run that printed tcltest's own
`Total 5007 Passed 3945 Skipped 805 Failed 257` and no marker, with no
crash. Nothing was wrong; the marker was unreachable.

`tk-runall.tcl` wraps `::exit` now and prints

```
tk-runall: every file ran, now entering exit
```

from inside the wrapper, **before** the real exit, so everything
`Tcl_Exit` does -- including tearing down every window -- happens after
that line. That makes it a genuine discriminator for the crash below:
marker then fault means the fault is in teardown; fault with no marker
means a test file did it. Do not put a failure count in it --
`cleanupTests` zeroes `numTests` a few lines above that `exit`, so it
would always read 0.

**Resolve a pc with acid, statically, on the binary.** This is *not*
the interactive acid the note above warns about -- there is no process,
so nothing fights `wish` for the rio window:

```
acid /bin/wish
acid: pcfile(0x26f694)
acid: pcline(0x26f694)
acid: src(0x26f694)		/* prints the line, with context */
```

It answers `generic/tkGeometry.c:153`, which is `Tk_GeometryRequest`:

```c
148  if ((reqWidth == winPtr->reqWidth) && ...) return;
151  winPtr->reqWidth = reqWidth;
152  winPtr->reqHeight = reqHeight;
153> if ((winPtr->geomMgrPtr != NULL)
154      && (winPtr->geomMgrPtr->requestProc != NULL)) {
```

**Read the shape of the fault, not just the line number.** Lines 148,
151 and 152 read *and write* through `winPtr` without faulting, and
only 153/154 die. A null or unmapped `winPtr` would have faulted at
148. **APE's malloc never unmaps a freed block** (see the allocator
note below), so a freed `TkWindow` stays readable and writable, and the
first thing that actually fails is the **pointer chase** through a
garbage `geomMgrPtr` to reach `requestProc`. So this is a
use-after-free of a `TkWindow`, and "it wrote to the struct first" is
no evidence the struct was alive. That reasoning generalises: on this
allocator, a wild pointer shows up at the first *double* indirection,
not the first access.

**The suspect, and it is a suspect.** The one place in
`plan9/tkPlan9Wm.c` that calls `Tk_GeometryRequest` on a *stored*
window pointer is `TkP9EmbedGeometryRequest`, which uses
`containerPtr->parentPtr`. `EmbedWindowDeleted` clears that when the
container is destroyed, so for it to dangle that cleanup must not have
run -- and there is a hole big enough:

`Tk_MakeContainer` registers `ContainerEventProc` with **`winPtr`** as
its client data, and the proc opens with

```c
containerPtr = FindContainer(winPtr->window);
if (containerPtr == NULL)
	return;			/* cleanup skipped */
```

Upstream's equivalent, `EmbedStructureProc` in `unix/tkUnixEmbed.c`,
registers the **`Container *` itself** as client data, so it never
looks anything up and can never fail to find it. That is a real
difference and a real hole.

**REFUTED, and the reason is worth more than the result.**
`sys/lib/tests/tk-embed-destroy-test.tcl` runs every ordering --
destroy the embedded half first, the container first, the container's
toplevel, five live pairs at once, and Tk's own exit teardown -- and
**provokes a geometry request after each**, which is the step that
matters, since nothing dereferences a stale pointer until something
asks for a resize. All of it returns.

Section 4 says why, in one line:

```
STEP: 4. destroy the CONTAINER half, then provoke a geometry request
     .c gone      .c.f gone      .e gone
  ok: the embedded half went with its container, so nothing to poke
```

**The embedded half dies with its container**, and that is structural
rather than luck: `Tk_MakeWindow` creates an embedded toplevel as a
*child of the container window* -- that substitution *is* the embedding
here (see the embedding section above). So `containerPtr->parentPtr`
cannot outlive an embedded half that could still make a request, and
the `ContainerEventProc` hole above -- real though it is -- cannot
produce this crash. Fix it on its own merits if you like; do not expect
the crash to go with it.

**So the caller is still unidentified.** The other things that call
`Tk_GeometryRequest` on a window they stored earlier are generic Tk's:
`Tk_MaintainGeometry`, which registers a placed window with *every*
master between it and its parent -- and which is already implicated in
the one known-open port bug, `geometry-4.7`.

**Bisecting by test file: NEITHER HALF CRASHES.** `tk-runall.tcl`
forwards its arguments to tcltest, so this needs no rebuild:

```
wish $home/APExp/sys/lib/tests/tk-runall.tcl -file {[a-m]*.test}
wish $home/APExp/sys/lib/tests/tk-runall.tcl -file {[n-z]*.test}
```

Both run to completion. So **the crash is cumulative or a cross-half
interaction**, and cannot be found by splitting in two -- one half
"containing" it is exactly what did not happen.

**Bisect a prefix instead.** `a-m` is clean and `a-z` crashes, so the
threshold is somewhere in between and the lower bound never moves:

```
wish .../tk-runall.tcl -file {[a-s]*.test}	;# then narrow
```

Three or four runs name the file whose *addition* is fatal, which is a
different and more useful fact than which file contains the bug: with
`-singleproc 1` every file is sourced into one wish, so the answer is
likely "the Nth toplevel" or "the Nth of something" rather than a
misbehaving test.

**The discriminator is the crash message itself**, not the absence of a
marker -- the marker was unreachable until the `::exit` wrapper, and
reading its absence as "did not finish" is what made the two clean
halves look ambiguous when they were not.

**The `[n-z]` half also gave the first proper accounting**, which no
earlier run reached because none of them finished:

```
all.tcl:  Total 5007  Passed 3945  Skipped 805  Failed 257
Sourced 47 Test Files.
```

**That corroborates the counting method used throughout this section.**
`grep -c FAILED` halved gave 287 for all 97 files; tcltest says 257 for
these 47, leaving ~30 for `[a-m]`, which adds up. The numbers in the
table above are not an artefact of how they were counted.

The 805 skips are constraints, and the big ones are all legitimately
absent here: `win` 280, `secureserver` 71, `nonPortable` 69, `nt` 55,
`winSend` 51, `fonts` 50. **Do not read `Total 5007` as a target.**

**The crash hides nothing.** `xmfbox` is the last file alphabetically,
so all 97 files and every failure are already measured; only the
summary line is lost. It is still worth doing early, because a general
protection violation is a memory-safety signal and this port has form
-- `TkpDeleteFont` and `TkpFreeColor` both freed a struct they did not
own (see the hook section above), and both were invisible until
something released a resource for real.

**IT IS NOT IN TEARDOWN.** The `::exit` marker settled that on its
first run: the marker is **absent**, and so is `runAllTests`' own
`Tests ended at` line, which it prints *before* `cleanupTests`
(`tcltest.tcl:2996`). So wish dies between the last test reporting and
`xmfbox.test`'s own trailing `cleanup; cleanupTests` -- inside the test
file. The banner line confirms the wrapper was installed, so the
absence means what it says this time.

**And xmfbox-2.6 itself fails with something impossible**, which is a
better lead than the fault:

```
bad window path name ".foo.top"
    while executing
"pack $w.top -side top -expand yes -fill both"
```

`library/xmfbox.tcl`'s `MotifFDialog_BuildUI` is

```tcl
329  toplevel $w -class TkMotifFDialog
330  set top [frame $w.top -relief raised -bd 1]
331  set bot [frame $w.bot -relief raised -bd 1]
333  pack $w.bot -side bottom -fill x
334> pack $w.top -side top -expand yes -fill both
```

`.foo.top` is created at 330 and **gone** at 334, with one `frame` and
one `pack` in between. A window does not leave the name table on its
own -- and a damaged widget tree is also what the fault two lines later
says, so the two symptoms are probably one cause and the Tcl-level one
is far cheaper to chase.

**Something accumulated is needed**, because both halves ran clean and
`[n-z]` contains `xmfbox.test`. With `-singleproc 1` all 97 files are
sourced into one wish, so what accumulates is **live windows** -- every
toplevel a test forgets to destroy.

**The first suspect is the window table, because it is a fixed array
that used to fail silently.** `tkPlan9Int.h` has `TKP9_MAX_WINDOWS
2048`, and on exhaustion `TkP9AllocWindow` returned NULL and
`XCreateWindow` answered `None` -- which every caller above it reads as
*no window*, never as *no room*. A frame that exists to Tk and not to
this port is exactly the shape of ".foo.top is gone". That is the
`XLoadFont` family again (see "four wm and keysym stubs that answered
plausibly"): **a stub that answers "failure" is not the same as one
that answers "nothing to do", and a table that answers `None` when
full is not answering at all.**

So it is loud now, and measured:

- exhaustion **panics**, naming the table and its size. A panic where
  it happens beats a general protection violation twenty minutes later.
- occupancy is reported as it climbs, one line per 256 slots:
  `tkp9: window table 256/2048 in use`. **Unconditional, not under
  `$TKP9DEBUG`** -- that flag turns on a torrent of drawing traces, and
  a number that only appears beside them is a number nobody reads.
  Eight lines over a process's life is the whole cost, and it makes the
  next full run answer "did we get close?" by itself.

`sys/lib/tests/tk-xmfbox-crash-test.tcl` asks the question without the
suite: build the dialog with a growing number of live toplevels
underneath, reporting at each step.

**IT WAS THE TABLE, AND IT LEAKED.** The very first full run with the
occupancy lines in it says so in two lines, in `xmfbox.test` -- the
exact file that had been crashing:

```
xmfbox.test
tkp9: window table 2048/2048 in use
tkp9: window table full (2048 entries); every XCreateWindow from
      here would answer None
```

The climb is the whole story: 256 at log line 96, then 512, 768, 1024,
1280, 1536 by line 539, 1792 by 1867, and 2048 four thousand lines
later. **A high-water mark that only ever rises is a leak, not a
working set.**

**`generic/tkWindow.c:1584` was the leak**, and it is the same shape as
`SendEnterLeaveForDestroy` twenty lines up:

```c
#if defined(MAC_OSX_TK) || defined(_WIN32)
	XDestroyWindow(winPtr->display, winPtr->window);
#else
	if ((winPtr->flags & TK_TOP_HIERARCHY)
		|| !(winPtr->flags & TK_DONT_DESTROY_WINDOW)) {
	    /* the parent's X window is destroyed; much faster not to */
	    XDestroyWindow(winPtr->display, winPtr->window);
	}
#endif
```

The `#else` skips the destroy for a child whose parent is going away,
because **on X the server destroys the subtree implicitly** and a round
trip per child is waste. Nothing here does that, and `XDestroyWindow`
in `plan9/tkPlan9Init.c` is the *only* thing that frees a `P9Window`
slot -- so every child of every destroyed toplevel leaked one, and a Tk
test file builds and destroys widget trees continuously. `PLAN9` is in
that condition now, for the third time in this port and always for the
same reason: **the condition is not the operating system, it is that
there is no X server.**

**The ramp test said the opposite, and both reasons it was wrong are
worth more than the result.**

- **It ran on a build that was itself broken.** The same commit that
  added the counter moved fields inside `P9DisplayState` and mk
  rebuilt one of the seven files (see the `HFILES` note below). *A
  measurement taken from a build you have just broken measures the
  breakage.* The regression was visible in the same run and was not
  treated as invalidating the measurement beside it. **Never draw a
  negative conclusion from a run that also shows an unexplained
  regression.**
- **It counted the wrong thing.** `countwins` in that script walks
  `winfo children`, which is *Tk's* count. Its section 2 reports "1
  window before, 1 after" and that is true and irrelevant: Tk had
  freed its `TkWindow`s and the `P9Window` slots behind them had
  leaked. The two agree only when nothing leaks, which is the thing
  under test. **The stderr occupancy lines are the port's own count
  and are the ones to read** -- which is exactly why they were made
  unconditional.

So the instrumentation earned its place twice over: the panic named the
table at the point of failure instead of a general protection violation
in another function twenty minutes later, and the climbing high-water
mark distinguished a leak from a working set. Neither was visible from
Tcl at all.

**Both symptoms went with it, and the suite now finishes and exits.**
The next run has no occupancy line at all -- so the table never passed
256, where it used to climb to 2048 -- and it ends:

```
xmfbox.test

Tests ended at 2026-09-10 15:04:38 +0200
all.tcl:  Total 10027  Passed 8320  Skipped 1429  Failed 278
Sourced 97 Test Files.
...
tk-runall: every file ran, now entering exit (code 0)
```

`xmfbox.test` reports **no failure at all** now, and there is no
general protection violation. Both were downstream of the exhaustion,
as expected: with the table full every `XCreateWindow` answered `None`,
so a frame existed to Tk and not to this port -- `bad window path name
".foo.top"` -- and generic Tk keys `dispPtr->winTable` on the window
id, so every such window collided on id 0 and they deleted each other's
entries. A use-after-free of a `TkWindow` reached through that table is
exactly the fault `acid` resolved to `Tk_GeometryRequest`. So
`Tk_MaintainGeometry` is off the list for the crash; it is still the
suspect for `geometry-4.7`, which is a different and much smaller
thing.

**This is the first complete accounting of the whole suite.**
`Total 10027` -- the `[n-z]` half alone had said 5007, and no earlier
run reached a total at all. **It is run 4, and is kept as history: the
current numbers are the six-column table at the top of this section**,
which was re-derived per file rather than extended.

| file | failing (run 4) |
|---|---|
| `wm.test` | 66 |
| `unixWm.test` | 59 |
| `unixEmbed.test` | 29 |
| `textDisp.test` | 23 |
| `select.test` | 23 |
| `unixSelect.test` | 18 |
| `systray.test` | 13 |
| `winfo`, `font`, `event`, `clipboard` | 4 each |
| `tk`, `textTag`, `imgListFormat` | 3 each |
| `textWind`, `place`, `pack` | 2 each |
| `winWm`, `visual`, `unixFont` and 9 more | 1 each |

**278, and `wm` plus `unixWm` are 125 of them.** Everything below
`unixSelect` in that table is a handful, so the shape of the remaining
work is: two files that have had attention and need more, four that
have had none (`unixEmbed`, `textDisp`, `select`, `systray`), and a
long tail of ones and twos that the sections below already account for
individually.

`Skipped 1429` is constraints and is not a target: `win` 337, `fonts`
126, `nonPortable`, `aqua` 30, `winSend` 51, plus the `test*`
constraints (`testwrapper` 54, `testtext` 31, `testutils` 20) which
need `tktest` rather than `wish` -- see the `imgListFormat` note below.

`unixWm.test`, `unixSelect.test`, `unixEmbed.test` and `unixFont.test`
run here because `tcl_platform(platform)` is `unix`, so the `unix`
constraint is true; on Windows they are skipped. **Do not assume they
should all pass** -- they test X server behaviour specifically, and some
of them are asking for things Plan 9 has no concept of, in the way
`clipboard-4.*` asks for X selection ownership. Each cluster needs
reading before it is counted as ours.

`event.test` is down to 2 from 3, which is the `event-9.16`
nondeterminism noted above showing itself again: it passed this run.

#### tktest: 448 skipped tests that have never been measured

**`Skipped 1429` is not all constraints that cannot be met here.** 448
of it is a missing *binary*, and it is the exact counterpart of the
`tcltest` that runs Tcl's suite: `tktest` is wish with Tk's own test
commands compiled in. The `tktest:V:` target in
`sys/src/ape/cmd/wish/mkfile` builds it, and it needed no new code at
all -- five objects, every one of them already in the tree:

```
tkTestInit.$O	unix/tkAppInit.c again, with -DTK_TEST
tkTest.$O	generic/tkTest.c
tkSquare.$O	generic/tkSquare.c
tclStubLib.$O	generic/tclStubLib.c	-- the client side of the
tkStubLib.$O	generic/tkStubLib.c	   stub interfaces; see below
```

That is upstream's `TKTEST_OBJS` exactly. The
`$(@TK_WINDOWINGSYSTEM@_TKTEST_OBJS)` it appends is **empty for X11 in
this Tk**, so there is no fourth, platform-specific object to write --
which is the thing worth checking before assuming a test binary needs
porting. Everything `tkTest.c` reaches on this side already existed:
`TkplatformtestInit` is `#define ... TCL_OK` for anything but Windows
(`tkInt.h:1341`), `TkpTestembedCmd` is in `plan9/tkPlan9Stubs.c`, and
`TkpTesttextCmd` is generic Tk's in `tkText.c`. Both files pass the host
gcc syntax check under `-DPLAN9` unmodified.

**The two stub objects are the whole of why a first attempt did not
link**, and they are the part worth reading. `tkTest.c` and
`tkSquare.c` both open with

```c
#undef STATIC_BUILD
#ifndef USE_TCL_STUBS
#   define USE_TCL_STUBS
```

so they compile as a stub-using **extension** whatever the command line
says -- that `#undef` is there precisely to stop `-DSTATIC_BUILD`
turning it off. Six symbols then go missing:

```
Tktest_Init: undefined: Tcl_InitStubs
Tktest_Init: undefined: Tk_InitStubs
_convM2D: tclStubsPtr: not defined
_convM2D: tkStubsPtr / tkIntStubsPtr / tkIntPlatStubsPtr: not defined
```

all of them in `generic/tclStubLib.c` and `generic/tkStubLib.c`, which
are the **client** side of the stub interfaces and are therefore in
neither archive: `libtcl.a` and `libtk.a` are the *core* and carry the
stub tables, not the things that reach them. `../tclsh/mkfile` hit
exactly this for `tcltest` and answers it the same way.

**The tempting alternative is wrong, and was tried first.** Plan 9 has
no dlopen, so nothing is ever loaded at run time and the stubs
mechanism has nothing to do; disabling it under `#ifdef PLAN9` in those
two files works. It is still the wrong trade -- it edits two vendored
*generic* files that the next Tk update would silently revert, to avoid
compiling two vendored files that already exist and already build
clean. **Prefer the link over the patch** whenever the missing symbols
turn out to live in a file the upstream tree already ships.

**A STUB OBJECT IS COMPILED AGAINST THE TREE IT IS THE CLIENT OF, not
against the binary it is being linked into.** This is the second thing
a first attempt got wrong, and half of it is silent. Both stub files
were built with `cmd/wish/mkfile`'s `CFLAGS`, and they must not be:

- **The include path.** `tclStubLib.c` reaches `tclInt.h` ->
  `tclPort.h` -> `tclUnixPort.h`, and neither that nor `tclConfig.h` is
  on Tk's. It needs `$TCLSRC/plan9`, `$TCLSRC/unix`,
  `$TCLSRC/libtommath` and `sys/src/ape/lib/tcl`, which is what
  `cmd/tclsh/mkfile` passes. This half announces itself --
  `tclUnixPort.h: No such file`.
- **`-DMODULE_SCOPE=/***/`, and this one does not.** Emptying it turns
  every `MODULE_SCOPE const Tcl_ObjType tclFooType;` in `tclInt.h` from
  an extern *declaration* into a tentative *definition*, so the object
  defines them. Measured on the build host with `nm`:

| object | flags | symbols |
|---|---|---|
| `tclStubLib.o` | tclsh's | **6** |
| `tclStubLib.o` | wish's | 38 |
| `tkStubLib.o` | `MODULE_SCOPE` kept | **6** |
| `tkStubLib.o` | `MODULE_SCOPE` empty | 30 |

The extras are `tclEmptyString`, `tclBignumType`, `tkPhotoImageType`,
`tkImgFmtGIF`, `tkMainWindowList` and the rest -- every one of which
`libtcl.a` and `libtk.a` also define, properly initialised. Which copy
the linker keeps is not a thing to leave to chance: take the stub
object's and Tk has a **NULL photo image type**. `tkStubLib.c` linked
anyway in the attempt before this one, so that would have been a
working `tktest` with quietly wrong image tables -- a fault that would
have surfaced as image tests failing and been chased in `plan9/`.

**AND THE SCOPE OF THAT WAS MISJUDGED TWICE.** The first attempt built
all four extra objects with `CFLAGS` and did not link. The second moved
only the two **stub** files -- because the link error named only the
stub symbols -- and left `tkTest.c` and `tkSquare.c` on `CFLAGS`. They
linked, and `tktest` then died before printing a byte:

```
tktest 10315: suicide: sys: trap: fault read addr=0x0 pc=0x5523a1
acid: src(0x5523a1)  ->  ap/arch/amd64/strlen.s:11, REPN SCASB
```

`strlen(NULL)` -- which is what a string table that should have been
initialised and is all zeroes gives you. `tkTest.o` was defining 35
extra symbols including `tkMainWindowList`, `tkPhotoImageType`,
`tkImgFmtGIF`, `tkStateStrings` and `tkTextCharType`, and the linker
kept the zeroed copies.

| object | `CFLAGS` | `TESTCFLAGS` |
|---|---|---|
| `tkTest.o` | 36 | **1** |
| `tkSquare.o` | 25 | **1** |
| `tclStubLib.o` | 38 | **6** |
| `tkStubLib.o` | 30 | **6** |

**A link error is a poor guide to which objects are wrong**: the two it
named were wrong, and so were the two it did not. The right value is
not a judgement call either -- `sys/src/ape/lib/tk/mkfile:198` and
`lib/tcl/mkfile:107` build the libraries with `-DMODULE_SCOPE=extern`,
so that is simply what anything linked beside them wants.

`TESTCFLAGS` in `cmd/wish/mkfile` carries both trees' include paths and
`-DMODULE_SCOPE=extern`, and all four use it. `CFLAGS` keeps the empty
`MODULE_SCOPE` and is harmless for the two objects that use it, because
`tkAppInit.c` includes `tk.h` and **not** `tkInt.h` -- 2 symbols either
way, measured. That is why the flag survived there for the life of the
port, and why anything else added to that directory needs `TESTCFLAGS`.

**Check every object built against a library for the flags that library
was built with, not just the ones the linker complained about.** One
`nm -g --defined-only x.o | wc -l` per object answers it, and it is the
cheapest check in this whole file -- no VM, no link, one second.

**AND THEN CHECK THAT THE FIX WAS IN THE BINARY BEFORE READING THE NEXT
RUN.** The round after that one, `tktest` failed at the same
`strlen(NULL)` with the pc moved by nineteen bytes, and the obvious
reading -- "the flags fix was necessary but not sufficient, so the Tk
stub table must be at fault too" -- was wrong. The commit carrying
`TESTCFLAGS` had **not been merged**; the build under test still had
`tkTest.c` on `CFLAGS`. The pc had moved because a *different* commit,
the one before it, changed those objects' sizes.

That nearly cost a reversal of a correct decision: three rounds of
inference had made "disable the stubs under `#ifdef PLAN9`" look like
the pragmatic call, and it was written and then thrown away again. It
is the ramp-test mistake from the window-table section in another form
-- *a measurement of a build that does not contain the change measures
nothing* -- and the pc moving is exactly the kind of detail that makes
a stale build look like a fresh one.

```sh
git merge-base --is-ancestor <fix> origin/main && echo in || echo NOT in
```

One command, before reading any result, whenever the build happens
somewhere this session cannot see.


What it unlocks, from the skip tally of run 6:

| constraint | tests |
|---|---|
| `testobjconfig` | 215 |
| `testImageType` | 154 |
| `testtext` | 31 |
| `testembed` | 18 |
| `testborder`, `testmakeexist` | 7 each |
| `testbitmap`, `testcursor`, `testfont` | 5 each |
| `testprintf` | 1 |

448, plus the fourteen `unixEmbed` `-3.3a`/`-5.1a` variants that report
`no library with prefix "Tktest" is loaded statically`, plus
`imgListFormat-3.*` and `image-6.2`.

**Still skipped, and correctly**: `testwrapper` 54, `testmenubar` 21,
`testmetrics` 11, `testwinevent` 7, `testpressbutton` 3, `testmovemouse`
1 -- every one of those is inside `#if defined(_WIN32)` in `tkTest.c`.
`testutils` 20 is a Tcl-side thing and is unaffected.

**EXPECT THE FAILURE COUNT TO RISE, and do not read that as a
regression.** A skipped test is not a passing test; these 448 are
*unmeasured*, and measuring them is the point. This has happened once
already and was misread once already: the first run to reach all 97
files took the count from 25 to 485, and none of it was new breakage --
34 of those files had simply never been measured. Compare per file, as
the table at the top of this section says, and read the tktest run as a
new baseline rather than against run 6.

`testobjconfig` alone being 215 is worth a word of warning: it is one
test file exercising Tk's option-database machinery very thoroughly, so
if it goes badly it will dominate every count taken afterwards and say
little about the rest of the port.

**Both test binaries live beside the shipped binary they extend**, as a
`:V:` target rather than `default` -- `tktest` in `cmd/wish/mkfile`,
`tcltest` in `cmd/tclsh/mkfile` -- so `mk` and `mk install` in either
directory still build and install only the real command, and neither
test binary is ever installed:

```
cd sys/src/ape/cmd/wish && mk tktest
./tktest $home/APExp/sys/lib/tests/tk-runall.tcl >/tmp/tk-all.out >[2=1]
```

**A separate `cmd/tktest` directory was written first and thrown away**,
and the reason generalises. It had to copy `cmd/wish/mkfile`'s entire
`CFLAGS` block -- including the `-DWCHAR=char` that file's own comment
calls load-bearing -- and its whole `LIB` list. A copy of a build rule
is a copy that silently stops matching: the day wish gains a `-D`, the
test binary is built differently and nothing says so. That is the
`HFILES` lesson in another form, and on this build system a
configuration that drifts is expensive to diagnose. **Put a test binary
in the directory whose flags it shares.**

**But read that rule with the stub note above beside it**, because as
first written it was too simple and it is what produced the second bad
attempt. `tktest` shares wish's flags for the three Tk objects and
*does not* for `tclStubLib.c`, which belongs to the other tree. "The
directory whose flags it shares" is the right home for a test binary;
it does not follow that every object in it takes the same flags.

No object collides between the two targets in `cmd/wish`: `tkAppInit.$O`
is wish's and `tkTestInit.$O` is tktest's, from the same source built
with and without `-DTK_TEST`, which is why upstream renames it too
(`Makefile.in:992`).

#### The four untouched files: 106 failures, and three of them are ours

`unixEmbed` 29, `select` 23, `textDisp` 23, `unixSelect` 18, `systray`
13 had had no attention at all. Read end to end, and the answer is much
better than the number: **three are real bugs here, two of them now
fixed, and the other 103 are asking for things this machine does not
have.**

**`systray` -- 13, none ours, none reachable.** Every one is
`invalid command name "_systray"` (or `_sysnotify`). That command is
registered by `unix/tkUnixSysTray.c`, which speaks the XEmbed system
tray protocol to a `_NET_SYSTEM_TRAY_S<n>` owner, and by
`unix/tkUnixSysNotify.c`, which **dlopens libnotify at runtime**. rio
has no tray and Plan 9 has no dlopen, so neither file is built and
neither ever could be. Do not stub `_systray`: a tray icon that reports
success and appears nowhere is the `XLoadFont` mistake with a bigger
blast radius.

**`unixSelect` -- 18, none ours.** All eighteen failures are the
`unixSelect-1.*` block and all eighteen run `childTkProcess eval`,
i.e. they hand the selection to a **second wish** and read it back.
`unixSelect-1.19`, the one test in the file that does not, passes.

**`select` -- 23, none ours, and the interesting one is the exception
that proves it.** 22 use a second wish. The 23rd, `select-5.8`, is
entirely in-process and **still is not ours**:

```tcl
selection handle .f1 {apply {{type offset count} {
    selection clear
    handler $type $offset $count
}} STRING}
list [selection get] $selInfo [catch {selection get} msg] $msg
```

The whole 16 KB value and `$selInfo` come back **byte-identical**; the
only difference is the last two elements. The handler clears the
selection while serving it, so the second `selection get` must fail
with "PRIMARY selection doesn't exist"; here it succeeds and returns
the empty string, because with no owner the request falls through to
`/dev/snarf`, which was empty.

**Do not "fix" this by making an empty snarf buffer an error.** It is
tempting -- it would make this one test pass, and every other Tk errors
on an empty clipboard -- but the pass would be incidental: PRIMARY here
*is* the system cut buffer, so what the second `selection get` returns
depends on what was snarfed last, not on who owns anything. The test is
asking about **ownership**, which `/dev/snarf` has no concept of, so it
belongs with `clipboard-4.*` and the other 22. `tk-selection-test.tcl`
asserts the opposite decision deliberately ("an empty snarf buffer is a
legitimate empty answer, not an error") and that decision stands. Same
rule as `font-21.19..22`: **do not change a documented fallback to dodge
a test.**

**`unixEmbed` -- 29, and TWO are ours.** The split is mechanical once
the messages are read:

| | |
|---|---|
| 14 | the `-3.3a`, `-5.1a`, … variants: `no library with prefix "Tktest" is loaded statically`. They `load {} Tktest child`, so they need `tktest` rather than `wish` -- the same harness limit as `imgListFormat-3.*` |
| 13 | the plain ids: `childTkProcess`, i.e. a second wish embedding into this one's container. **Cross-application embedding is the one thing this port's embedding cannot do**, and deliberately: the whole reduction in `Tk_MakeWindow` rests on both halves sharing this process |
| 2 | `unixEmbed-8.2` and `unixEmbed-10.2`, both in-process, both real |

`unixEmbed-8.2` is the useful kind of exception: it loads **Tk** (not
Tktest) into a child *interpreter*, so it is one of the few embedding
tests that can run here at all. It found `TkpClaimFocus` still an empty
stub under a comment reading "no embedding on Plan 9" -- left from
before `Tk_UseWindow` existed. See the focus-claim note below.

`unixEmbed-10.2` found `WmUpdateGeometry` discarding an explicit
`wm geometry` on an embedded toplevel; see the note below that.

**`textDisp` -- 23, none cheaply ours, and they are three different
things.** Worth splitting because only one third is even about this
port's code:

- **13 are font metrics** (`3.1`, the six `9.*`, the six `16.*`).
  `textDisp-9.1` wants the wrapped display lines to be `2.0 2.1[78]`
  and gets `2.0 2.13 2.33`; `16.11` wants `.t index @0,0` to be `103.0`
  and gets `102.5`. The test file's own comment says the glob is "to
  have some tolerance on actually used font size" -- the tolerance is
  one character, and Plan 9 bitmap fonts come in whole sizes. Same
  family as `frame-14.1`. Nothing to fix without a scalable font.
- **1 is the `TkScrollWindow` trade-off, already documented above.**
  `6.5` places a frame over the text, scrolls **while it is still
  there**, and expects the obscured source region to be repaired --
  which is precisely the `GraphicsExpose` case the note above says this
  port gives up: "a copy whose source was overlapped by a sibling
  window has already picked up the sibling's pixels, and with no
  backing store there is no record of it". It reports

```
got   {1.0 9.0 10.0} {1.0 9.0 10.0}
want  {1.0 9.0 10.0} {1.0 4.0 5.0 9.0 10.0}
```

  -- relayout identical, the redraw short by exactly the two display
  lines that were under the frame. Redrawing *less* than X is the
  expected direction.
- **9 were the damage bug, and all nine are fixed** -- `7.1`..`7.8`,
  which chasing found it, and `6.6`. **`6.6` was attributed to the
  `TkScrollWindow` trade-off here and that was wrong**, on nothing
  better than its sitting beside `6.5` and reading similarly. The two
  differ in one line of ordering, and it is the whole difference:
  `6.5` calls `update` with the frame still up and never updates after
  the `destroy`, so it asks only what the *scroll* redrew while
  obscured; `6.6` destroys the frame **before** its `update`, so the
  destroy's damage is folded into the same redisplay -- which this port
  simply never reported. **Read what a test does in order before
  putting it in a group**; a pair that looks like one cause was two.

The arithmetic for the whole exercise, **settled by run 6 rather than
predicted**: of 106 failures in the four untouched files, **12 were
ours and all 12 are fixed** -- `unixEmbed-8.2` (half) and `-10.2`, and
the nine damage ones -- and the other 94 need a second wish (53),
`tktest` (14), a system tray (13), a scalable font (13), or the backing
store this port does not have (1). Nothing is left open in them.

That ratio is the thing to carry into the next file rather than the raw
count, and it is better than it looked: the first pass through these
four said "3 are ours" and the real answer was four times that. **A
failure that reads as environmental is worth one look at what the test
actually does** -- nine of these twelve were sitting under "Expose
granularity", a heading that sounds like a platform limit and was a
missing call.

#### Tk on Plan 9: nothing repaired what a window had been covering

**Destroying a widget left its pixels on the screen.** So did
`place forget`. So did raising a widget above its siblings. This port
repaired damage in exactly **one** place -- `XMapWindow`, which exposes
the window that has just appeared -- and nowhere else, for the whole
life of the port.

`sys/lib/tests/tk-expose-test.tcl` says it in four empty lines: it
binds `<Expose>`, prints `%x %y %w %h`, and reported

```
STEP: 2. destroy .f2, then update
      exposes:
STEP: 3. rebuild, map a frame over .t, then 'place forget' it
      exposes:
STEP: 4. two overlapping frames in .t, raise the lower one
      exposes:
```

**Section 4 is what pinned it down**, and it is the one that reads as a
contradiction: `XRaiseWindow` *does* call `P9ExposeTree`, so raising
was the one path the code said should work. It reported nothing, which
sends you to `Tk_RestackWindow` in `generic/tkWindow.c`:

```c
if (winPtr->window != None) {
    XWindowChanges changes;
    unsigned int mask = CWStackMode;
    ...
    XConfigureWindow(winPtr->display, winPtr->window, mask, &changes);
```

**A non-toplevel never reaches `XRaiseWindow` at all.** Tk reorders
`parentPtr->childList` itself and tells the server about a *sibling*
with `CWStackMode`; only a toplevel goes through `TkWmRestackToplevel`
and so through `XRaiseWindow`. And `XConfigureWindow` here was pure
bookkeeping -- it copied x/y/width/height into the `P9Window` and
returned.

**Why every test still passed.** `Tk_CoordsToWindow` answers from Tk's
own `childList`, so `winfo containing` was right the whole time and
`raise.test` was satisfied: **the hit test was correct and only the
pixels were stale.** That is precisely the trap the stacking section
above warns about -- "restacking with no hit-test reports nothing and
hit-testing with no restacking reports a stale but plausible answer" --
met from the other side, and it hid this for the whole port.

**The fix** is `P9ExposeRect` and `P9DamageUnder` in `tkPlan9Init.c`.
`P9ExposeRect` is `P9ExposeTree` over a rectangle: expose a window and
its mapped children, each clipped to the part of the rectangle that
falls inside it, children after their parent so they repaint on top --
drawing here goes straight into the one rio window with no clipping, so
the order of the events *is* the stacking. `P9DamageUnder` takes a
window's rectangle **in its parent's coordinates**, which is where
`P9Window.x/y` already are, and exposes the parent over it. Called from
`XDestroyWindow` (before the slot is freed -- the rectangle and the
parent are both gone the moment `TkP9FreeWindow` runs), `XUnmapWindow`,
and `XConfigureWindow`'s `CWStackMode` path.

**Err towards more damage, always.** Too much costs a repaint; too
little leaves stale pixels that nothing here will ever correct, because
there is no backing store and no server to ask. That asymmetry is why
this went in as "expose the parent subtree over the rectangle" rather
than anything cleverer.

**It works, and the rectangles are right.** With `.t debug on` added
so the redraw half reports at all -- `tk_textRelayout` and
`tk_textRedraw` are only recorded while the widget's own debugging is
on, `textDisp.test:139` -- the second run of the script says:

```
STEP: 2. destroy .f2, then update
      exposes: {.t 52 26 144 55 count=0}
      relayout:
      redraw:   2.0 2.40 3.0 3.40 4.0 4.40
STEP: 3. rebuild, map a frame over .t, then 'place forget' it
      exposes: {.t 28 14 96 40 count=0}
STEP: 4. two overlapping frames in .t, raise the lower one
      exposes: {.t 28 14 120 50} {.fb 0 0 72 30} {.fa 0 0 120 50}
```

`.f2` was 60% x 55% of a 248x108 `.t` at 20%,22%, so `52 26 144 55` is
its rectangle: **partial damage, clipped correctly**, not the whole
widget. Section 4 shows the recursion doing the right thing too -- the
parent over `.fa`'s rectangle, then `.fb` clipped to the *intersection*
(72x30), then `.fa` whole.

**And the relayout line is empty**, which is exactly what X does and
what `textDisp-7.1` asks for (`{}` relayout, a redraw of the display
lines in the damaged strip). **So the prediction written here -- "this
is not yet known to fix textDisp-7.1..7.8, and probably does not" --
was wrong, in the good direction.**

**The suite agrees: all eight are fixed, and so is `textDisp-6.6`,
which nothing here predicted.** `textDisp.test` went 23 -> 14 and no
other file moved by a single test, which is the whole of the 277 -> 268
difference. The prediction being wrong twice in a row -- once
pessimistic about the eight, once silent about the ninth -- is the
argument for `tk-expose-test.tcl` asserting rather than advising: what
it measured (a clipped rectangle, an empty relayout, `.fa` repainting
last) was right every time, and only the inferences drawn from it were
not.

**Section 4 was right by luck, though, and that is a second bug.**
`P9ExposeRect` walks `gP9.wins` in **slot order**, which is roughly
creation order and has nothing to do with what is on top -- while the
events *are* the stacking here, because drawing is immediate into the
one rio window with no clipping and whoever repaints last wins the
pixels. `.fa` had just been raised above `.fb` and happened to sit in a
later slot. Create the two frames the other way round and the raise
would have repainted `.fb` last, i.e. done nothing visible.

Tk owns the order and always has: `parentPtr->childList`, lowest first
(`Tk_RestackWindow`). `P9ExposeRectStacked` walks that instead, falling
back to the slot walk when `Tk_IdToWindow` cannot answer -- during
teardown it returns NULL for a window this table still has. The comment
claiming "the order of the events is the stacking" is true now rather
than accidentally true, and the third run confirms it: **`ok: .fa
repaints last, so the raise is visible`**.

**The script checks rather than advises now.** Sections 2 and 4 used to
print a paragraph explaining how to read their own output -- what the
rectangle ought to be, what an empty relayout would mean. That is one
more thing to get wrong at two in the morning, so they assert instead:
the rectangle must be smaller than the widget, the relayout must be
empty, and `.fa` must repaint after `.fb`. They say `ok` or
`REGRESSION` and name what to look at only when something is wrong.

**A check that cannot fail is not a check**, and the first run of this
script had one: its `build` proc *assigned* `tk_textRelayout`, so the
"does this Tk report it at all?" test could never fire, and every
`relayout:` line read empty for the wrong reason. It probes with a
separate widget before `build` touches anything now.

#### Tk on Plan 9: TkpClaimFocus, and an embedded wm geometry

Two one-function bugs, both found by the only two `unixEmbed` tests
that can run here.

**`TkpClaimFocus` was an empty stub**, under a comment saying "no
embedding on Plan 9" that predated `Tk_UseWindow`. Generic Tk calls it
when something focuses a window inside an embedded toplevel while the
focus is elsewhere, and `unix/tkUnixEmbed.c` answers by sending the
container a synthetic `FocusIn` with mode `EMBEDDED_APP_WANTS_FOCUS`,
which generic Tk turns straight back into a `TkSetFocusWin` on the
receiving side (`tkFocus.c:295`). **The event is the round trip, not
the mechanism** -- on X the container is usually a different client.
Here both halves share this process and this window table, so the round
trip is the identity: `Tk_GetOtherWindow` to find the container, then
`TkSetFocusWin` on it. Same reduction as the rest of this port's
embedding.

**Result: `unixEmbed-10.2` passes; `8.2` is half fixed.** `[focus]` in
the container's interpreter is `.f1` now, where it used to be `.f2`, so
the claim reaches the container. What is still wrong is the *other*
half -- the embedded application's own `[focus]` is `{}` where it
should be `.`.

That is `displayFocusPtr->focusWinPtr`, which is per main window, and
`TkSetFocusWin` (tkFocus.c:633) deliberately leaves it NULL on the
claiming side: on X the application learns it has the focus from the
**real FocusIn the server then delivers to the embedded window**, and
`TkFocusFilterEvent`'s ordinary path sets it. Windows does the same
thing concretely -- its container answers `TK_CLAIMFOCUS` with
`SetFocus(containerPtr->embeddedHWnd)`, i.e. it moves the OS focus *to
the embedded window*, and Tk sees `WM_SETFOCUS` there.

So the missing step is generating that second FocusIn on the embedded
toplevel. **Do not send it with mode `EMBEDDED_APP_WANTS_FOCUS`**: that
mode routes back into `TkSetFocusWin` (tkFocus.c:295) and would claim
again, which is a loop. It wants an ordinary FocusIn, and getting the
mode and detail wrong in the focus machinery is how `bind.test` went
from 3 failures to 116 once already -- so it is left alone until it can
be measured rather than guessed.

**`WmUpdateGeometry` threw away an explicit `wm geometry` on an
embedded toplevel.** The `TK_EMBEDDED` branch sat *above* the size
computation and passed `Tk_ReqWidth`/`Tk_ReqHeight` straight through,
so

```tcl
toplevel .t1 -use [winfo id .f1] -width 150 -height 80
wm geometry .t1 70x300+10+20
wm geometry .t1			;# answered 150x80+0+0
```

kept the `-width`/`-height`. An embedded window's request is its
*wanted* size, and an explicit `wm geometry` is exactly what overrides
a requested one -- as it does for every other toplevel three lines
further down the same function. The branch moved below the computation,
so it now gets the min/max clamp and the grid conversion too, which the
early return also skipped. `tkUnixWm.c`'s `UpdateGeometryInfo` computes
width and height first and only then asks the container, for the same
reason.

---

**The rest of this section predates that run** and describes the 62-file
prefix. It is kept because the reasoning about each individual failure
is still good, but **the counts in it are stale**; the table above
supersedes them.

The prefix was at **25 failing tests** (`grep -c FAILED` counts two lines
each, so 50 lines).

**It was 24, and the twenty-fifth is `event-9.16` -- which passed the
previous run, with no C change in between.** The only difference between
the two runs was `tk-runall.tcl`'s bgerror handling, which cannot reach
a crossing event. So **at least one `event-9.*` test is
nondeterministic here**, and the likely reason is worth knowing before
anything is concluded from that group again: those tests warp the
pointer and then depend on what is under it, while this port has no
server and **polls the real `/dev/mouse`**. `gP9.pointerDirty` makes the
next poll re-report the true position, so a mouse that moves during the
run -- or a rio window that takes the pointer -- can overrule the warp.

The practical rule: **an `event-9.*` result is only evidence if it
repeats.** `9.16` reports the same empty `|` as `9.11`/`9.12`/`9.17`
did, which is the "no crossing at all" failure the
`SendEnterLeaveForDestroy` change fixed for its siblings; it is
therefore also possible that the fix is racy rather than that the run
was. Run `tk-enter-test.tcl` twice before touching it.

**Read that number with the caveat below: the suite does not finish.**
Every `tk-all.out` collected so far stops after `scrollbar.test`, 62
files of 97, and **`grep -c FAILED` has therefore always been counting a
62-file prefix**. 35 files -- `select`, `send`, `spinbox`, `systray`,
all of `text*`, `unixFont`, `unixWm`, `winfo`, `wm` and the `ttk` set --
have never been measured at all.

Three separate things were tangled here, and they were sorted out in the
wrong order, so keep them apart:

- **`wish all.tcl` never exits, even on success.** Its only `exit` is
  inside `if {... && [info exists env(ERROR_ON_FAILURES)]}`; Github CI
  sets that variable and nothing else does, so the script falls off the
  end and wish enters `Tk_MainLoop`. Under `tclsh` the same file exits,
  which is why upstream does not notice.
- **The log lies about where the run stopped.** stdout redirected to a
  file is block buffered, so the last file name visible is an upper
  bound on progress, not the truth.
- **There is also a real hang**, and this is the one that matters.
  Adding the exit did *not* change the log: `tk-runall.tcl` produced a
  byte-identical 535 lines. The first two explanations were both true
  and neither was the cause. (The reasoning written here at the time --
  "so `runAllTests` never returned" -- leant on a marker that could not
  print in any case; see the marker note above. The byte-identical log
  is the evidence, and it stands on its own. The hang was later
  confirmed directly, by `-verbose t` ending at `scrollbar-10.1 start`.)

`sys/lib/tests/tk-runall.tcl` sets line buffering before anything is
written and prints a marker from inside a wrapper around `::exit`. With
both in place the answer is settled:

**A background error is a hang, and neutralising it means replacing the
default handler, not `::bgerror`.** Tk's default background-error
handler puts up a **modal** dialog and waits for a click, so any
unhandled error inside any binding stops the suite dead -- with the
message only on screen, never in the log, and the CPU pinned by the
dialog's own event loop. That is indistinguishable from a real spin.

The obvious cure makes it worse. `::bgerror` is a `namespace import` of
`::tk::dialog::error::bgerror` (`library/bgerror.tcl:281`), and the
**`tkerror` compatibility delegation lives inside that handler**
(`bgerror.tcl:107`), not in the dispatcher. Overriding `::bgerror`
therefore threw the delegation away along with the dialog, and
`bgerror-1.1..1.3` -- which each install a `::tkerror` and then
`vwait errRes` for it to fire -- waited forever. The suite stopped
three files in with a 632-byte log: the file that tests bgerror is
exactly the one a careless bgerror override breaks, and it is early in
the alphabet.

`tk-runall.tcl` replaces `::tk::dialog::error::bgerror` instead,
keeping the `::tkerror` call (and its return code, which `bgerror-1.3`
relies on) and dropping only the dialog. A test's own `::bgerror` still
wins, being consulted first. Note the override has to come **after**
`bgerror.tcl` is sourced -- it is autoloaded on first use, so an
override written first is silently undone the first time a background
error arrives; `catch {::bgerror}` forces the load.

**The hang is in `scrollbar.test`.** The marker is absent, so
`runAllTests` never returned, and with line buffering the last name in
the log is now genuinely where it stopped rather than wherever the 4 KB
boundary fell. It is not `select.test` -- that was a guess from the
buffered log, and the buffered log could not have supported it.

**It spins rather than blocks.** The CPU meter stays high for as long as
it is wedged while nothing is written. That rules out a blocked read --
a child wish that never answers, a `/dev/mouse` read, a pipe -- and
points at a loop: either the notifier never sleeping, or a layout or
event cycle that never settles.

**The notifier is prior art for exactly this.** `DisplaySetupProc` sets
a zero maximum block time whenever `TkP9EventsPending()`, and only
otherwise sleeps `P9_POLL_US`. An event that is regenerated as fast as
it is drained therefore pins the CPU with no progress -- which is the
100% CPU spin this port already had once, when the block time was zero
unconditionally. `gP9.pointerDirty` is the obvious way to reach that
state: `DisplayCheckProc` clears it and calls `TkP9UpdatePointer`, so
anything that maps, unmaps or destroys a window from a crossing handler
sets it again.

**The test is `scrollbar-10.1`**, established rather than guessed.
`-verbose t` prints each name as it *starts*, and the log ends

```
---- scrollbar-9.1 start
---- scrollbar-10.1 start
```

with nothing after it. The command needs no rebuild:

```
wish $home/APExp/sys/lib/tests/tk-runall.tcl -file scrollbar.test -verbose t
```

That run also surfaced **two failures nobody had seen** --
`scrollbar-6.41.1` (`ScrollbarPosition` answers `trough2` where `slider`
is wanted) and `scrollbar-6.44` (answers empty where `trough2` is
wanted). They were never in any count because the file hangs before
tcltest reports anything, so `scrollbar.test`'s output never reached the
log at all. **Any file at or after the hang may be hiding failures the
same way.**

`scrollbar-10.1` is the first test to wire a text widget and a scrollbar
to each other -- `text .t -yscrollcommand {.s set}` against `scrollbar
.s -command {.t yview}` -- and then aim `<Enter>` and `<MouseWheel>` at
it. Neither ingredient is new alone: four earlier files create a text
widget and `bind.test` sends MouseWheel.

**`sys/lib/tests/tk-scrollbar-hang-test.tcl` splits its eight lines**,
printing a flushed marker before each, so the last `STEP:` line names
the statement that did not return. Its first two sections are the ones
that matter, because they separate the two shapes a spin can have:

- **a loop inside one Tk call**, never returning to the event loop.
  `tkTextDisp.c` lays out 99 lines through `Tk_MeasureChars`, which this
  port rewrote for `font-24.*`; a measure that reports no progress makes
  the caller spin. Section 1 lays out the same text with **nothing
  wired** -- if that hangs, it is this.
- **a loop through the event loop**, an event regenerated as fast as it
  is drained. Section 2 wires the two widgets together and does nothing
  else -- if only that hangs, it is this.

Do not skip to a fix from the mechanism: this file has now recorded four
occasions where a confident mechanism was wrong and a printed
intermediate value settled it in one round.

**`sys/lib/tests/tk-mousewheel-test.tcl` has narrowed it to one
sentence**, and the sentence is not what either shape above predicted.
Its steps 0-7d all return, and between them they exonerate: crossing
delivery (the `<Enter>` class binding demonstrably runs, so
`Priv(xEvents)` is set and the "can't read Priv(xEvents)" error is not
in play); the plain event loop and `after`; every shape of `yview
scroll` -- positive, negative, integer, and the 0.5 that `ceil` must
round to 1, so `GetScrollInfo`, `YScrollByLines`' do/while and this
port's `Tk_MeasureChars` rewrite are all clear; `yview moveto`; `.s
set`; `update` after all of it; `tk::ScrollByUnits` called directly with
the binding's **exact** arguments (`.s vh -120 -40.0`) and twelve times
over so the counting branch is reached; and delivery of a `<MouseWheel>`
with the class binding removed.

**The first thing that hangs is 7e, whose binding is a bare
`.t yview scroll 3.0 units`** -- no `tk::ScrollByUnits` at all. So the
library proc is innocent, and the statement of the bug is

| | |
|---|---|
| scroll alone | returns |
| delivery alone | returns |
| **scroll from inside delivery** | **spins** |

Note how nearly this went wrong: step 6 called `tk::ScrollByUnits .s v
-4`, which with a one-character orient and the default factor 1.0 fails
**both** halves of the `[string length $orient] == 2 && $factor != 1.0`
guard, so it skipped the counting branch, and `-4/1.0` is the opposite
sign of the binding's `-120/-40.0`. Three differences at once between a
step that returned and a step that hung -- the same trap as
`canvas-23.*`. 7c and 7d exist to close each of them, and both returned.

Sections 7e0..7e2 then split "inside delivery", and narrow it twice
more. **`7e0` (a binding that only does `incr`) and `7e1` (a binding
that does `.s set`) each ran exactly once and returned**, so delivery
itself is sound and the binding is not being re-run; it is *what the
binding does* that matters. **`7e2` hangs with the text widget not
wired to the scrollbar at all**, which disposes of the
`-yscrollcommand` callback as well. The table is now

| | |
|---|---|
| delivery + trivial binding | returns |
| delivery + `.s set` | returns |
| **delivery + a text scroll** | **hangs** |
| a text scroll on its own | returns |

so it is not delivery, not the scroll, and not the scrollbar -- it is
the pair. `7e1b`..`7e1d` ask whether "delivery" is even the operative
half, since an X event handler is only one way to run a script from
inside the event loop: the same scroll from an **idle** handler, from a
**timer** (`after 0`), and from a **`<Key>`** binding, none of which
touch the pointer machinery.

**The event loop is not the operative half, and every sentence above
about "inside delivery" was describing the wrong thing.** The control
settled it: `build2`'s widgets scrolled **at the top level** --
nothing delivered, no binding, no idle handler -- and the *scroll
returned*. The **`update` after it** is what hangs. So the sequence is
scroll completes, then the **redisplay** that follows never settles;
every earlier section that hung was hanging in its trailing `update`,
not in the delivery it was written to test.

Geometry is ruled out too, and cheaply: both text widgets come out
`486x246` and mapped, so a text widget laid out into no height -- a
good way to make `tkTextDisp.c` loop -- is not it.

**The arrangement was never the variable either.** The 2x2 written for
that -- pack order against whether the pair is wired -- was answered by
its first cell: **A hangs**, and A is `build`'s own arrangement, `.t`
at `0,0` and `.s` at `486,0`. So pack order, the wiring, and the
`x=10` offset are all out together.

**What is left is how far the widget was scrolled**, which is the only
remaining difference from step 2 + step 5 on these same widgets:

| | | |
|---|---|---|
| `7e1A` | `scroll 3.0 units`, index 4 | **hangs** |
| steps 2..4 | ending in `moveto 0.5`, index 51 | returns |

That is not a coincidence of numbers. `tkTextDisp.c` does not repaint
the whole window for a small scroll: when the old and new views
overlap it **copies the overlapping rectangle** to its new position and
repaints only the strip uncovered. A jump to the middle of a 99-line
file has no overlap, so it takes the plain full-repaint path. "Scrolled
a little" and "scrolled a lot" are therefore two different code paths,
and **only the first moves a rectangle** -- the operation this port has
most often got wrong.

Section 8 asked the distance directly and split the `update` in two,
and it gave one decisive answer and one misleading one.

**Decisive: `update idletasks` hangs.** That runs only idle handlers,
so **the loop is inside the redisplay** -- `DisplayText` either never
returns or re-posts its own idle handler forever. No event is involved
and the Expose theory is dead. Everything from here is `tkTextDisp.c`
and what this port's drawing does underneath it.

**FOUND: `TkScrollWindow` waits for an event this port never sends.**
`unix/tkUnixDraw.c` -- which `sys/src/ape/lib/tk/mkfile:147` builds --
issues the `XCopyArea` and then waits for the X server to say how much
of it succeeded:

```c
while (!info.done) {
	Tcl_ServiceEvent(TCL_WINDOW_EVENTS);
}
```

`info.done` is set **only** by a `NoExpose` or the last
`GraphicsExpose` for that window, and **neither event name appears
anywhere in `plan9/`** -- `XCopyArea` there begins `(void)gc;` and
never looks at `graphics_exposures`. So the loop has no exit at all: an
infinite loop inside one Tk call, which is exactly "`update idletasks`
never returns, CPU pinned, nothing written".

`win/tkWinDraw.c` and `macosx/tkMacOSXImage.c` each define
`TkScrollWindow` themselves for precisely this reason and neither waits
for an event. **The condition is not the operating system, it is that
there is no X server to answer** -- the same shape as
`SendEnterLeaveForDestroy` above. `plan9/tkPlan9Draw.c` now defines it:
copy, then return 0, which is what a `NoExpose` means. The unix version
is wrapped in `#ifndef PLAN9` rather than dropped from the mkfile,
because the same file's `Tk_DrawHighlightBorder` and `TkpDrawFrameEx`
are still wanted.

**Do not "fix" this by sending NoExpose from `XCopyArea` instead.**
`tkGC.c:188` defaults `graphics_exposures` to **True** for every GC Tk
creates, so that would enqueue an event for every copy in the program
-- every photo blit, every 3D border -- into a 1024-entry ring that
drops silently when full.

The one thing lost is the case X repairs and this port cannot: a copy
whose source was overlapped by a sibling window has already picked up
the sibling's pixels, and with no backing store there is no record of
it. Returning the whole rectangle as damage would repaint correctly and
make every scroll a full redraw, which is the cost the copy exists to
avoid.

**Misleading, and the reason this took four extra rounds: the distances
do not mean what they look like.**

| | reaches | |
|---|---|---|
| `moveto 1.0` | 77, the end | ok |
| `moveto 0.5` | 51 | ok |
| `scroll 100 units` | 77, clamped to the end | ok |
| `scroll 20 units` | **21** | **hangs** |

**`moveto 0.2` reaches index 21 and hangs**, while `moveto 0.5` reaches
51 and does not -- same command, so `YScrollByLines` and its
display-line walk are innocent, and so is the command/position question
the test was built to settle.

The overlap story *was* right; **the arithmetic used to refute it was
wrong.** `moveto 1.0` reports a top index of 77 on a 100-display-line
widget, so about **24 lines are visible**, not the ~15 assumed when the
theory was dropped. Measured from the freshly-built top:

| | distance | overlap? | |
|---|---|---|---|
| `moveto 1.0` | 76 | no | ok |
| `moveto 0.5` | 50 | no | ok |
| `moveto 0.2` | 20 | **yes** | **hangs** |
| `scroll 20 units` | 20 | **yes** | **hangs** |
| `scroll 3 units` | 3 | **yes** | **hangs** |

Every row fits: `tkTextDisp.c` copies only when the old and new views
overlap and repaints outright when they do not, so only the copying
path reaches `TkScrollWindow`. **Check what a widget's actual geometry
is before ruling a mechanism out on line counts** -- one `winfo height`
divided by the line height would have kept this on the right track two
rounds earlier.

**This now lives in `sys/lib/tests/tk-textscroll-hang-test.tcl`**, and
`tk-mousewheel-test.tcl` is finished -- kept as the record of how the
suspects were excluded, not as something to run. The bug reproduces in
four lines:

```tcl
pack [text .t -yscrollcommand {.s set}] -side left
pack [scrollbar .s -command {.t yview}] -fill y -expand 1 -side left
.t yview scroll 20 units
update idletasks		;# never returns
```

**Put a new case in the right place or the run is wasted.** The distance
loop was appended *after* the section it was meant to inform, so it hung
at its fourth case and the run never reached the questions that mattered
-- a whole round trip for a sequencing mistake. Every case expected to
return must come before every case expected to hang, in file order, and
each must print a flushed marker before it runs.

**Every binding counts and prints its own invocation number**, because
the one fact that decides the shape is whether the binding runs once or
forever: `wheel #1` and then silence means one delivery whose drain
never settles (look at what the redisplay queues -- Expose,
`pointerDirty`, an idle handler that re-posts itself); `wheel #1 #2
#3 ...` means the event is being redelivered, which is this port's
event source. `7e2` originally lacked that printing and so could not
say which -- worth remembering, since it is one line and the run that
omits it is wasted.

The leftover windows are a third thing and not a mystery: `all.tcl` sets
`-singleproc 1`, so all 97 files are sourced into one wish and every
toplevel a test forgets to destroy stays up for the life of a process
that never ends.

**23 of the 25 are known not to be the Plan 9 backend's** -- the two
that are, or may be, ours are `geometry-4.7` and the intermittent
`event-9.16` above. The rest are worth recording so they are not chased
again:

**Three of the five `event-9.*` were ours, and are fixed; `9.13` and
`9.14` remain and are generic Tk's.** An
earlier note here said they were generic Tk's, on the strength of
`event-9.14`'s `%d` details. **That was wrong twice over**, and both
errors are worth keeping as a warning about reasoning from one member of
a group:

- **`generic/tkPointer.c` in this tree is upstream's.** Diffed against
  `tcltk/tk` `main`, the only differences in the whole file are `int` vs
  `bool`, `TkpGetMS` vs `TkGetMS`, one cast, and an `#include`. So
  `TkPointerDeadWindow` is not stale, and the comment in `event-9.16`
  and `9.17` about "overwriting the dead window struct in
  `TkPointerDeadWindow()`" simply describes the `lastWinPtr =
  TkGetContainer(winPtr)` that is already there. Check the vendored file
  against upstream *before* concluding it is out of date.
- **Three of the five report no crossing at all**, not a wrong detail.
  `event-9.11`, `9.12` and `9.17` come back as the bare `|` separator:

```
event-9.11  got   |
            want  |<Enter> NotifyInferior .one.f1|
```

  Only `9.13`/`9.14` show the `NotifyVirtual`-for-`NotifyNonlinear`
  substitution, which is what `TkInOutEvents` does with a NULL
  `sourcePtr`. Two different failures, and reading the group from its
  loudest member got the quiet three wrong.

**The answer, from section 5 of `tk-enter-test.tcl`.** That section is
`event-9.11` copied exactly -- including `create_and_pack_frames`'
geometry, which is load-bearing -- and it prints the hit test on both
sides of the destroy:

```
containing 350 350 -> '.one.f1.f2'        (want .one.f1.f2)   PASS
containing 350 350 after destroy -> '.one.f1'                 PASS
crossings:
```

So `Tk_CoordsToWindow` is right at both ends and **the pointer update
never runs at all**. It is not the hit test and it is not tkPointer.c:

`generic/tkWindow.c` calls `SendEnterLeaveForDestroy(tkwin)` at the very
top of `Tk_DestroyWindow`, before anything is torn down, and that
function is **real only under `MAC_OSX_TK` or `_WIN32`** -- everywhere
else it compiles to an empty stub, because on X the server sends the
crossings. This port drives `tkPointer.c` exactly as those two do, so
`PLAN9` belongs in that condition; the condition is not the operating
system, it is *there is no X server to generate the crossings*.

That is a one-token change to a shared generic file, and it is the right
place rather than a copy under `plan9/`: forking a generic file means
the next Tk update silently skips the fix, and this is upstream's own
"no X server" list, not a Plan 9 peculiarity.

Note the gate on the call, `(winPtr->flags & TK_DONT_DESTROY_WINDOW) ==
0`, is what keeps `event-9.16` right: a child destroyed as part of its
parent carries that flag, so the subtree yields one crossing rather than
one per level.

The distinction every passing case hid: `event-9.1` and section 3 of
`tk-enter-test.tcl` both destroy a **toplevel**, which is the branch
`TkPointerDeadWindow` plus the deferred `pointerDirty` poll happens to
cover. Every failing one destroys a nested **frame**.

With `PLAN9` in that condition, section 5 gives the details the suite
asks for, both steps:

```
containing 350 350 after destroy -> '.one.f1'
crossings: {Enter .one.f1 NotifyInferior}	;# event-9.11
...
crossings: {Enter .one NotifyInferior}		;# event-9.17's second half
```

and sections 1-4 are unchanged, so the toplevel path did not regress.
The suite agrees: `9.11`, `9.12` and `9.17` are gone.

**`9.13` and `9.14` remain, and they are the other failure** -- the
`NotifyVirtual`-for-`NotifyNonlinear` substitution `TkInOutEvents`
makes with a NULL `sourcePtr`, described above. Both destroy a
**toplevel**, which is the path `SendEnterLeaveForDestroy` deliberately
leaves alone (`if (!Tk_IsTopLevel(tkwin))`), so it was never going to
touch them. Fixing those means giving `TkPointerDeadWindow` a live
stand-in for the dead window, which is a real change to generic Tk
rather than a one-token one -- and the two tests that document that
mechanism, `9.16` and `9.17`, both pass now.

**The four `place-8.*`/`pack-18.*` fail on X11 too.** All four have the
shape

```
got   1 1 W H 1 1
want  1 0 W H 0 1
```

and all four ask whether a **child** reports `winfo ismapped` as 0 after
`wm iconify` on its toplevel. On Windows the OS sends `WM_SHOWWINDOW`
with `SW_PARENTCLOSING` to the children and Tk turns that into
`UnmapNotify`; X sends nothing for a child of an unmapped window, and
neither `Tk_UnmapWindow` nor either port's `TkWmUnmapWindow` walks the
children. The tests carry `-constraints {failsOnUbuntu failsOnXQuartz}`,
and that constraint is

```tcl
testConstraint failsOnUbuntu [expr {![info exists ::env(CI)] || ![string match Linux $::tcl_platform(os)]}]
```

-- true (so the test *runs*) everywhere except CI on Linux. They
therefore fail on an ordinary Linux/X11 desktop as well. **Do not
"fix" these by unmapping descendants**: that would be inventing
semantics X does not have, in the one direction where this port
deliberately follows X.

`clipboard-4.1/4.2/4.4/6.2` are the third such group, and were already
known: they turn on X selection *ownership*, which `/dev/snarf` has no
concept of.

**The four `font-21.19..22` are an upstream test bug**, and the block
they sit in shows it. Sixteen tests there all ask the *same* question
and compare it against a *different* name:

```tcl
if {[font actual {avantgarde 12 roman normal} -family] == "helvetica"} {
    set x [psfontname avantgarde 12 roman normal]      ;# four arguments
} else {
    set x Helvetica
}
```

`proc psfontname {name}` takes **one** argument, and every other call
site in the file quotes it (`psfontname "arial 10"`). So the `then`
branch raises `wrong # args`. It is dead code on a normal machine --
21.7..21.10 compare against `avantgarde`, 21.11..18 against `bookman`
and so on, and only a machine where avantgarde resolves to *helvetica*
ever enters it. `ChooseFont` here resolves any unknown proportional
family to helvetica, so we do.

**Do not change the fallback to dodge this.** Reporting the family that
was actually resolved is the contract (see the font section above), and
`tk-font-test.tcl` asserts the real requirement -- that an unknown
family does *not* come back as itself.

**`imgListFormat-3.1/3.2/3.3` and `image-6.2` need `tktest`, not
`wish`**: `invalid command name "testphotostringmatch"`, and `image
types` must list `test`, which `generic/tkTest.c` registers only in Tk's
own test binary. A harness limitation, not a port bug -- **and it is
built now**; see the tktest section below.

**`focus-1.19` needs two applications.** `focusClear` in `focus.test` is
`childTkProcess eval {focus -force .}` -- it takes the focus away by
giving it to *another* wish. rio owns the keyboard here and Tk is the
only authority on focus within a process (see `TkP9FocusWindow` above),
so a second wish cannot take this one's focus and `focus` stays `.t.b1`
where the test wants `{}`. Not fixable without a cross-application focus
protocol that Plan 9 does not have.

**`imgPhoto-4.75` and `filebox-7.1-0` are the environment**, not Tk:
the first needs `file copy` to a name beginning with `-` and reports
ENOENT, the second needs a directory that cannot be read.

`pkgconfig-1.1` wants the twelve `CFG_INSTALL_*`/`CFG_RUNTIME_*` keys,
which the unix Makefile passes as `-D`s and `sys/src/ape/lib/tk/mkfile`
does not. **Left undefined deliberately**: APExp has no install prefix
to name -- it builds into the repo tree and overlays it with a union
mount -- so every one of those paths would be a fabrication, and
`tcl_findLibrary` is what actually locates the scripts at runtime.

**`frame-14.1` is the discrete font sizes**, and it is arithmetic rather
than a guess. `tkFrame.c:1243` gives a labelframe a minimum width of
`labelReqWidth + 2*(borderWidth + LABELMARGIN)` -- 12 with the defaults
-- and the test's content is 50x50 inside a 2-pixel border, so 54 is the
answer whenever the label needs no more than 42. `.l` is
`label .l -text Mupp -font {helvetica 8}`, and here it asks for 46: the
string is **four pixels wider** than on X, one per character, because
Plan 9 bitmap fonts come in whole sizes and the nearest to 8 points is
not 8 points. Nothing to fix without a scalable font.

**`geometry-4.7` is the one still open and still ours**, and the
ConfigureNotify guard below **did not fix it** -- it reports two
`configure` events exactly as before. So the extra event is either a
second, genuinely different move of `.b1`, or a redundant one escaping
by a path that never reaches those three X entry points;
`Tk_MoveResizeWindow` sets `TK_NEED_CONFIG_NOTIFY` itself when a window
has no X window yet, so generic Tk can synthesise one without going
near this port. `sys/lib/tests/tk-geometry-test.tcl` prints `%x %y %w
%h` for every `<Configure>` rather than counting them, which is what
separates those two.

That accounts for all 25: 23 are upstream, environment or harness
limitations, `geometry-4.7` is the known-open port bug, and
`event-9.16` is the intermittent one described at the top of this
section.

`canvas-23.*`, `listbox-4.7`, `bind-13.14`, `embed-1.1`,
`fontchooser-2.0/2.1` and `event-9.11/9.12/9.17` **were** ours and are
fixed -- see the sections below.

**When the next full run lands, re-derive this list rather than
trusting it.** Every count in this section is a snapshot of a 62-file
prefix, and four times now something has been misread from one member
of a group -- including, twice, a fix declared on a test's evidence
before the suite confirmed it.

### Tk on Plan 9: the image path was a stub in both directions

`canvas-23.1/23.2/23.3` fail with

```
failed to copy Pixmap to XImage
```

which is `tkCanvas.c` reporting that `XGetImage` returned NULL. It was
a stub, and so were `XPutImage` and `TkPutImage`; `tkp9_putpixels`
existed but **nothing called it**. So the whole pixel path was
unimplemented in both directions, and the three canvas tests are only
the corner of it the suite happens to poke -- `TkPutImage` is how Tk
draws every photo image.

The awkward part is the pixel format, and it has a trap in it.

**The XImage side.** `XCreateImage` here declares 32 bits per pixel and
`byte_order`, and generic Tk reads a pixel with a plain 32-bit load and
then decomposes it with the *visual's* masks -- `tkCanvas.c`'s
`DrawCanvas` does exactly that, and `screen->root_visual` says
`0xFF0000`/`0x00FF00`/`0x0000FF`. So an XImage pixel is the host-order
word `0x00RRGGBB`, and the only way to agree on both endiannesses is a
32-bit access rather than naming bytes. `XImagePixel()` is that
accessor. `P9GetPixel`/`P9PutPixel` used to store R,G,B,A in *memory*
order, which contradicts the `LSBFirst` the same file declared -- on a
little-endian machine that puts blue where the red mask looks. Nothing
had noticed because no pixel ever made the trip. `byte_order` now
follows the host rather than being hardcoded, since this tree builds
big-endian architectures too.

**The Plan 9 side, and the trap.** `tkp9_putpixels`/`tkp9_getpixels`
speak R,G,B,A bytes and convert to Plan 9's `RGBA32`. Plan 9 names a
channel from the most significant bits down and stores the pixel
little-endian, which makes `RGBA32` A,B,G,R in memory -- but **that is
not assumed**, because getting it wrong is *invisible in a round trip*:
put and get would permute and unpermute by the same amount and cancel,
and the error would surface only where these bytes meet the XImage
layout, as red and blue exchanged in every photo, a long way from here.
So `rgbacalibrate()` asks instead, once: fill a pixel with four
components that are all different (`0x4080C0FF` -- the colour argument
to `allocimage` is `0xRRGGBBAA`, documented and stable, and an alpha of
`0xFF` makes premultiplication the identity) and see where each lands.
The documented order is the fallback if the probe cannot run.
`$TKP9DEBUG` prints what it found.

`tkp9_getpixels` draws the source into an `RGBA32` temporary before
unloading it rather than unloading the source directly: a pixmap is
allocated in the *screen's* channel (`tkp9_allocimage`), which varies by
machine, and `draw()` does that conversion for us.

**A round-trip test cannot check this.** The absolute colour is what
matters, so `sys/lib/tests/tk-image-test.tcl` only *reads*: it draws
each of red, green, blue, navy, maroon and grey with the ordinary
drawing path and asks what comes back.

**The calibration works, and the first diagnosis from these tests was
wrong.** With the path implemented, `canvas-23.2` passed and `23.1` and
`23.3` did not, and the three differ only in colour -- blue, green, red
-- with green the middle byte and `#c0c0c0` grey, both invariant under
exchanging red and blue. That is a very convincing red/blue swap, and it
is not what was happening: every colour makes the trip exactly, and
`$TKP9DEBUG` reports

```
tkp9: RGBA32 memory order R=3 G=2 B=1 A=0
```

which is A,B,G,R, the documented order, measured correctly.

### Tk on Plan 9: XDrawRectangle covers w+1 by h+1 pixels

**X's rectangle outline is a five-point path through the corners** --
`(x,y) (x+w,y) (x+w,y+h) (x,y+h) (x,y)` -- so it covers **w+1 by h+1**
pixels, one more than the width and height it is given. Plan 9's
`border()` draws *inside* the rectangle handed to it, so `tkp9_drawrect`
has to widen by one in each direction to mean the same thing.
`XFillRectangle` is **not** like this: a fill really is `w` by `h`, and
`tkp9_fillrect` is right as it stands.

That extra pixel is not a rounding detail, it is load-bearing, and
`canvas-23.1` is the proof:

```tcl
.c create rectangle 0 0 0 9 -fill #000080 -outline #000080
```

`tkRectOval.c`'s `DisplayRectOval` **already widens a degenerate box
itself** -- for `x2 == x1` at a coordinate of 0 it does `x1 -= 1` -- so
what arrives at the platform is one pixel wide starting at **-1**. The
fill covers only column -1, off the canvas; column 0 is painted by the
outline's extra pixel and by nothing else. Drawing the outline one short
lost the whole column.

**This was diagnosed wrong twice, and both wrong answers were
plausible.** First as a red/blue swap, because 23.1/23.2/23.3 differ in
colour (blue, green, red) and green is the invariant middle byte --
refuted by `tk-image-test.tcl` section 1, where every colour makes the
trip exactly. Then as a *zero-width* rectangle reaching X, which is
wrong because Tk normalises that before the platform ever sees it; the
special case written for it was dead code. The lesson both times: the
tests differed in three ways at once (colour, width, height), and only
the third mattered.

`canvas-23.2` passes throughout because its rectangle is `0 0 1 9` --
genuinely one wide, so the *fill* covers column 0 and nothing depends on
the outline.

### Tk on Plan 9: an empty validRegion means no photo is ever dithered

A photo drawn onto a canvas read back as the canvas background --
section 3 of `tk-image-test.tcl` -- and it was **not** `XPutImage`.
Under `$TKP9DEBUG` the trace shows `XCopyArea: 4x4 from 30 (pixmap)` and
**no `XPutImage` line at all**: the instance pixmap was copied
faithfully and was empty.

`TkPutImage` is reached from exactly one place, `TkImgDitherInstance`
(`tkImgPhInstance.c:1983`), and that is gated on

```c
TkClipBox(modelPtr->validRegion, &validBox);
if ((validBox.width > 0) && (validBox.height > 0))
	TkImgDitherInstance(...);
```

`TkpBuildRegionFromAlphaData` is what fills that region, and it was an
empty stub in `plan9/tkPlan9Stubs.c`. `Tk_PhotoPutBlock` calls it for any
block with alpha, which is **every** photo -- `pix32` always carries an
alpha byte -- so `validRegion` was empty for every photo ever created,
the dither never ran, and the pixmap stayed blank. The same empty region
is then set as the gc's clip mask for the `XCopyArea` that paints it, so
it fails twice over.

It is upstream's run-by-run loop now rather than a single bounding box:
the region here is a bbox (`struct _XRegion`, same file), so the two
agree today, but a real region implementation later needs no change.

**The trace had to be on the entry of `XPutImage`.** An exit-side trace
cannot tell *never called* from *called and turned the image away*, and
those two want opposite fixes -- the first round of tracing here sat
after the early returns and proved nothing.

`XSubtractRegion` in that file is still deliberately approximate (it
returns `sra`), which with a bbox region means a re-put with
transparency does not shrink the valid area.

### Tk on Plan 9: four wm and keysym stubs that answered plausibly

Four small ones, all of the same family as `XLoadFont` above -- a stub
that returns a *plausible* answer rather than admitting it did nothing,
so nothing upstream can tell.

**`XKeysymToString` returned `""` for a keysym it could not name.**
Xlib returns NULL, and every caller here tells the two apart:
`tkBind.c`'s `%K` keeps its `"??"` default only while the name is NULL.
So `event generate <Key> -keycode -1` substituted the empty string
(`bind-13.14`). An empty *name* is not the same as *no name*.

**`TkpScanWindowId` used `strtoul` and could not fail.** `toplevel .t
-use xyz` therefore reached the container lookup with id 0 and reported
`couldn't create child of window "xyz"` -- a believable message for the
wrong reason, and one that equally describes a real id naming a window
that has gone. It is `Tcl_GetWideIntFromObj` now, so a non-number gives
the ordinary Tcl integer error (`embed-1.1`).

**`wm title` was write-only.** rio owns the frame, so nothing displays a
title -- but `wm title` is a *query* as well, and answering the empty
string to a title the caller has just set is simply wrong.
`fontchooser-2.0/2.1` identify the dialog they raised by reading it
back. Stored in `WmInfo` now, defaulting to the toplevel's `nameUid` as
Tk does on X.

**`Tk_SetGrid`/`Tk_UnsetGrid` were empty, so `-setgrid 1` did nothing.**
Gridding is not decoration: with it in force `wm geometry` speaks in
**characters** rather than pixels, in both directions --

```tcl
listbox .l2 -font $fixed -width 30 -height 20 -setgrid 1
wm geometry .           ;# must say 30x20, and said 190x308
wm geometry . 26x15     ;# 26 characters, not 26 pixels
```

The convention is `tkUnixWm.c`'s and is the thing to remember: while
`wmPtr->gridWin` is non-NULL, **`wmPtr->width`/`height` hold grid units,
not pixels**. The conversion is confined to the three places a size
crosses that boundary -- `WmUpdateGeometry` on the way out, and the `wm
geometry` query and setter -- plus `Tk_SetGrid` itself, which must
reinterpret a size that was set in pixels *before* gridding, or a
`wm geometry` from earlier silently becomes a character count a few
hundred times too large. `Tk_UnsetGrid` converts back.

Note `wm minsize`/`maxsize` are also in grid units on X and are still
clamped as pixels here; inert today, since the defaults are 1 and
unlimited.

### Tk on Plan 9: a configure that changes nothing must report nothing

`XMoveWindow`, `XResizeWindow` and `XMoveResizeWindow` sent a
ConfigureNotify unconditionally. X generates one when a window is
*actually* reconfigured -- moving a window to where it already is is
silent -- and that is not a detail, because **Tk counts these events**
and everything that relays out on `<Configure>` is written expecting one
per real change.

`geometry-4.7` is where this came from: `Tk_MaintainGeometry` registers
a placed window with **every** master between it and its parent, so one
`place .f -x 25 -y 35` runs the callback several times. The test wants
`init configure |` and gets `init configure configure |`.

**The guard did not fix that test**, which is worth recording as a
correction rather than deleting: the rule is still right -- X really is
silent for a reconfigure that changes nothing, and `WmUpdateGeometry`
needs it against the re-request loop -- but it was not what
`geometry-4.7` was reporting. See `sys/lib/tests/tk-geometry-test.tcl`,
which prints each `<Configure>`'s `%x %y %w %h` so that "the same
position twice" and "two different positions" stop looking alike.

`WmUpdateGeometry` in `tkPlan9Wm.c` already carried this rule, and
against a worse symptom -- without it, resize -> Configure ->
re-request loops -- so the fix is the same guard at the three X entry
points. `XConfigureWindow` sends no ConfigureNotify at all and is left
alone.

### A header not in HFILES is a header mk does not rebuild for

`sys/src/cmd/mklib` makes every object depend on `$HFILES`:

```
%.$O:	$HFILES		# don't combine with following %.$O rules
```

so a header **not listed there changes nothing**. mk rebuilds only the
`.c` files that themselves changed, and every other object keeps the
layout it was compiled against. Plan 9 mkfiles do not scan `#include`s,
and `HFILES` in `sys/src/ape/lib/tk/mkfile` was the single line
`tkConfig.h`.

**This cost a whole suite run, and the symptom named nothing.** Two
`int` fields were added to `P9DisplayState` in `plan9/tkPlan9Int.h` --
the struct behind `gP9`, the **one global all seven files in `plan9/`
share** -- and they were put beside `nwins`, which sits *above*
`evqueue`. Only `tkPlan9Init.c` was recompiled, because only its `.c`
had changed. The other six went on reading `evqueue`, `evhead`,
`focuswin` and `lastmouse` at the old offsets **of the same object**.

```
bind.test	3 failures  ->  116, every one an empty result
		(no key event was delivered at all)
canvWind, clipboard, clrpick	up as well
the run				died in cmds.test
```

Every one of those is a plausible Tk regression, and the group as a
whole reads as "the event source broke". Nothing in it points at a
header, let alone at a build system.

Two fixes, and both are wanted:

- **`HFILES` now lists the port's own headers** -- `tkPlan9Int.h`,
  `tkPlan9Port.h`, `tkPlan9Default.h`, `tkP9Draw.h`. Those are the ones
  that change; the vendored `generic/` and `xlib/` headers do not, and
  listing several hundred of them would make every build walk the tree.
- **Append to a shared global struct, never insert.** The comment at
  the end of `P9DisplayState` says so. Appending cannot move an
  existing field, so a stale object still reads everything it knew
  about correctly.

**The same trap is waiting in every vendored tree here**, since
`mklib`'s rule is shared and most of these mkfiles have a short
`HFILES` or none. The tells to remember: a change that is *logically
inert* (a counter, a field nothing reads yet) followed by *broad,
unrelated* breakage is a layout problem, not a logic one -- and on this
build system the first thing to suspect is which objects were actually
recompiled. `mk nuke` in the library directory settles it in one run.

### Syntax-check Tk's Plan 9 backend on the host before shipping it

A round trip to the VM costs a full rebuild, and twice now it has been
spent on a typo. gcc will parse these files on the build host -- it
never links, and it does not need Plan 9 -- so a bad edit is caught in
a second instead of a rebuild:

```sh
cd sys/src/external/tk
for f in plan9/*.c; do
	[ "$f" = plan9/tkPlan9DrawImpl.c ] && continue	# needs <draw.h>
	gcc -fsyntax-only -w -Igeneric -Igeneric/ttk -Ixlib -Ibitmaps \
	    -Iplan9 -I../tcl/generic -I../tcl/plan9 \
	    -DHAVE_TCL_CONFIG_H -DHAVE_TK_CONFIG_H -DPLAN9 \
	    -DMODULE_SCOPE=extern -DWCHAR=char -DTK_PLATFORM='"plan9"' \
	    -DSTATIC_BUILD "$f" || echo "FAILED $f"
done
```

All seven files are clean today, so any output is a regression. Note
gcc is *stricter* than pcc here and that is the point: it rejects the
prototype mismatches `rsametype()` waves through, which is how
`TkpBuildRegionFromAlphaData` was found taking a `const unsigned char *`
against a declaration with no `const`, and `XCreateGlyphCursor` taking
non-const `XColor *` against Xlib's `_Xconst`.

The mistake it would have caught both times is putting a comment
*between* a function's return type and its declarator, which strands the
old return type above it:

```c
const char *
/* ... comment ... */
char *
TkpGetString(...)
```

pcc reports that as `syntax error, last name: char`, which names neither
the function nor the real problem.

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

### Tcl's own test suite, and the two things it has found so far

Run from `sys/src/ape/cmd/tclsh`:

```
./tcltest $home/APExp/sys/src/external/tcl/tests/all.tcl >/tmp/tcl-all.out 2>&1
```

**It does not finish**, and that is the most important result in it. Of
167 test files it reaches six -- `binary.test` is killed and the run
stops during `chanio.test`, with no summary line:

```
Test file error: tcltest 69507: Killed: Insufficient physical memory
```

That note is the 9front kernel refusing to grow the process, and the
same wall is expected to stop bash on a configure script. **Do not read
the failure list as a survey**: it covers the first 4% of the suite in
alphabetical order, so everything after `chanio` is simply unmeasured.

Two findings, both worth a test of their own.

**1. A double just past the float range may not round to infinity.**
`binary-53.25` and `binary-53.26`:

```tcl
binary scan [binary format H* 47effffff0000001] Q round_to_inf
binary scan [binary format R $round_to_inf] R inf1
expr {$inf1 eq Inf}		;# answers 0, wants 1
```

`binary format R` is a 32-bit float, so this is a double -> float
conversion and a read back. The constant is not arbitrary: FLT_MAX is
`2**128 - 2**104`, the next float is infinity, and the midpoint is
`2**128 - 2**103`, exactly `0x47EFFFFFF0000000`. The test value is that
**plus one ulp of a double**, so round-to-nearest must give infinity
with no tie to break, and `0x47EFFFFFEFFFFFFF` must give FLT_MAX.

Three different things produce a `0` there and they want different
fixes, which is why `sys/lib/tests/float-overflow-test.c` asks them
separately: the conversion itself (6c's `CVTSD2SS`, or the folded path
in `cc/scon.c` -- and note the sign-of-zero work found `ieeedtof` in
every `*l/obj.c` mishandling this boundary); `isinf` and the
`INFINITY`/`HUGE_VAL` macros, which `<math.h>` got wrong once already;
and **printing**, because `eq Inf` is a *string* comparison -- it is
asking whether Tcl's double-to-string gives exactly `"Inf"`, which Tcl
reaches through `TclIsInfinite()` -> `isinf()`.

**2. free() does not give memory back, except to a request of exactly
the same size.** `ap/malloc/malloc.c` is Plan 9's: one free list per
power-of-two class, and `free()` pushes a block onto the list for its
own class and nowhere else. So

- every request is rounded **up to a power of two** -- a 33 MB string
  costs 64 MB;
- **nothing splits or coalesces**, so 64 MB on the `2**26` list does not
  satisfy a 32 MB request; the heap grows instead;
- `realloc` is malloc-copy-free, so growing one buffer to N bytes walks
  the classes and strands a dead block in each, leaving about 2N of
  garbage that only an identically-sized request can reuse, on top of
  the up-to-2N rounding.

Growth by realloc is how every interpreter builds a big string, so this
is the shape behind the OOM.

**Splitting is the obvious fix and does not work as written.** A block
of class k occupies `16 + 2**k` bytes -- the header is padded to 16 for
`max_align_t` -- so two class-k blocks need `32 + 2**(k+1)`, which is
sixteen bytes **more** than the class-(k+1) block they would be carved
from. The layout has no room for it, which is presumably why Plan 9
never did it. Making this allocator return memory means changing the
block layout or replacing the allocator.

`sys/lib/tests/malloc-reuse-test.c` measures it through `sbrk(0)` --
what the process took from the kernel, which is the quantity the note is
about, rather than what malloc believes it handed out. Its sizes are
under glibc's 128 KB mmap threshold on purpose, so both assertions hold
on glibc, which is how it was checked.

**The rest of the list is not new work.** `chan-16.9` wants
`socket -server`, which libap answers `ENOTSUP`; the seven
`chan-io-6.4x`/`8.1` failures are one cluster, all `-buffersize 16` with
`testchannel inputbuffered` reporting 0 where a partial buffer should
remain, on a pipe and on a file alike. Tcl channels use `read`/`write`
directly, not stdio, so the stdio work above is not implicated.

**Getting a full run is the first job here**, not fixing the ten. Skip
the files that cannot fit in the VM (`bigdata.test`, and `binary.test`
until the allocator is dealt with) so the other 161 are measured at all.

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

### Integer rules applied to floating point (FIXED)

Three bugs of one shape, all found by musl's `asin()`, all silent. When
something floating-point is subtly wrong, ask whether an integer rule
has been applied to it.

**`double op float` was computed in FLOAT.** `cc/sub.c`'s promotion
table had `tab[TDOUBLE][TFLOAT] == TFLOAT`, so the common type of a
double and a float was the **smaller** of the two -- C99 6.3.1.8 gives
it to the greater rank. The `TFLOAT` row was right
(`tab[TFLOAT][TDOUBLE] == TDOUBLE`), so `float op double` always worked
and only this direction was wrong, which is how it survived.

`asin(1.0)` returns `x*pio2_hi + 0x1p-120f` -- a double plus a float
constant whose only job is to raise `inexact` -- and the answer came
back as **float** pi/2, `1.5707963705062866`, exactly 4.371e-08 above
the double value. **Every mixed-precision expression in the tree was
quietly rounded to 24 bits**, so anything built before this is suspect,
the same warning as the 6c spill and the `bool` fix.

**`0/x` was folded to 0 for floating point.** `cc/com.c`'s `ccom()`
`ODIV` case did `if(vconst(l) == 0 && !side(r)) *n = *l;`. True for
integers; in floating point `0.0/0.0` is NaN and `0.0/-1.0` is `-0.0`.
Worse, `*n = *l` replaces the node with the **integer** constant, so the
answer was a positive integer zero. The divisor-is-zero case two lines
below already carried a `typefd` guard; this one did not.

`asin(2.0)` reports its domain error with `return 0/(x-x);`, which
folded away and returned 0.0 instead of NaN.

**`INFINITY` was `DBL_MAX`.** `<math.h>` had
`#define HUGE_VAL 1.79769313486231e+308` with `INFINITY` on top of it --
a finite number, against C99 7.12p3/p4. `isinf(INFINITY)` was false,
`exp(1000) == INFINITY` was false, and `cos(INFINITY)` computed a real
cosine of a very large angle rather than NaN. It hid unusually well:
`exp(INFINITY)` *passed*, because `exp(1.8e308)` returns `1.0+x`, which
compares equal to that same 1.8e308. `HUGE_VAL` is `Inf(1)` now, as
`NAN` was already `NaN()` -- neither is the constant expression the
standard asks for, and there is no way to write one here.

Covered by `sys/lib/tests/fparith-test.c`.

### The sign of zero was dropped everywhere (FIXED)

The fourth of that family, and the widest: **seven** separate places,
each one a test of the form `x == 0` or `x < 0` written by someone who
did not have two zeros in mind. `-0.0` compares equal to `0.0` and is
not less than it, so every ordinary test misses it and every one of
these was silent.

**Negation was `0 - x`.** x86-64 has no scalar floating-point negate, and
`cc/com.c` rewrites `-x` as `0 - x` whenever the back end says it cannot
do the operation itself -- `machcap()`. 6c's `machcap()` answered for the
integer types only (`typechlv`), so **every** floating-point negation in
the tree went through the rewrite, and `0.0 - 0.0` is `+0.0`. Unary plus
is the same shape one line above, `0 + x`, so `+(-0.0)` was `+0.0` too;
that one is now simply the operand, since floating point has no
promotions to apply.

Negation is a sign-bit flip and `6c/cgen.c` generates one: `XORPS` or
`XORPD` against a mask of `-0.0`. The mask is loaded into a register
first -- the linker lays an `FCONST` literal out four or eight bytes
aligned and the memory form of those instructions wants sixteen.
`AXORPS` had to be added to `reg.c` and `peep.c`, which knew only
`AXORPD` (`gmove` uses it to make a zero); `reg.c`'s default arm is
`diag("reg: unknown op")`, so a missing entry is at least loud.

Five more places lost the sign on the way out, and they are the reason
fixing the negation alone was not enough:

| | |
|---|---|
| `cc/scon.c` | `evconst` folded `-x` with a runtime negation, so it inherited the bug from the compiler compiling it |
| `cc/pswt.c`, `1c`+`2c` `swt.c` | `ieeedtod` tested `native < 0` before `native == 0` |
| `cc/dcl.c` | `init1` skips a **zero** static initialiser, since BSS is already zero -- and `vconst()` answers 0 for `-0.0`, because it truncates to an `int` |
| `6c/txt.c` | `gmove` made any zero constant with `XORPD` of a register against itself, which is `+0.0` |
| every `*l/obj.c` | `ieeedtof` took `-0.0` for a denormal and said `double fp to single fp overflow` |

The `dcl.c` one is the one to remember, because it is the shape that
survives every fix upstream of it: the value was folded correctly, and
then **discarded as a zero** rather than written wrongly. `static double
negzero = -0.0;` was the last case still failing after the other six
were fixed, and it fails on its own -- a file-scope initialiser never
goes through `com.c` or `cgen.c` at all.

**`fpnegzero()` and `fpnegzeroval()` are in `cc/sub.c`**, so they are in
`cc.a` and every back end has them -- `1c` and `2c` do not build
`pswt.c`, which is where they were first put. Both read or write the
sign bit through a `union { double; uvlong; }` rather than writing
`-0.0`: **kencc compiles kencc**, so a `-0.0` in the compiler's own
source would have folded to `+0.0` and the fix would only have taken
effect on the second rebuild. `evconst` is written the same way for the
same reason.

The sign of zero is not decorative. It is what makes `1/x` tell the two
infinities apart, it is the sign of every underflowing product and
quotient, and `atan2`, `copysign` and `log` all branch on it -- so
**anything doing floating-point arithmetic near zero and built before
this is suspect**, the same warning as the 6c spill and the `bool` fix.

Covered by `sys/lib/tests/fparith-test.c`, which reaches a `-0.0` by
each of the routes above separately -- a constant, a static initialiser,
a runtime negation, unary plus and the library -- because they fail
independently.

### Hex floating constants were silently zero (FIXED)

`cc/lex.c` collected the whole literal into `symb` and finished with

```c
yylval.dval = strtod(symb, nil);
```

**Plan 9's `strtod` does not parse C99 hex floats.** It reads the leading
`0`, stops at the `x`, and returns 0.0. So every `0x1.921fb54442d18p-1`
in the tree was **zero**, with no diagnostic from anything -- and hex
floats were on the "implemented" list above, because the *lexer* work
(`casedothex`, `casep`) had been done and the conversion had not.

What it cost, all of it silent:

- musl's math tables are written entirely this way. `exp_data.c`,
  `log_data.c`, `log2_data.c` and `pow_data.c` are **597 constants**,
  every one zero. Nothing had noticed only because nothing used them
  yet -- see the math section.
- `__rem_pio2.c`'s `pio4` threshold and `__rem_pio2_large.c`'s `0x1p24`
  scaling, so the **large-argument** path of sin/cos/tan was still wrong
  after those were replaced with musl's.
- A `0x1p-120f` added to a result purely to raise `inexact` is harmless
  at zero, which is why the small-argument cases looked fine. That is
  the shape of it: harmless where the constant is decorative, fatal
  where it is data.

`hexfloat()` in `lex.c` does the conversion now: mantissa into a
`uvlong`, stopped at 60 bits with round-to-nearest on the first dropped
digit, then `ldexp` by the binary exponent. Checked against `strtod` on
the build host over **every one of the 1921 hex float literals in
`ap/math`** -- all 1921 bit-identical.

The tell for this class: a constant that is *decorative* (an inexact
flag, a threshold that only picks a slower path) hides the bug, and a
constant that is *data* exposes it. When a table-driven routine is
wildly wrong and a polynomial one is fine, suspect the constants before
the algorithm.

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


