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

Minimal test infrastructure at `sys/lib/tests/stdio-test.c`. Testing is primarily ad-hoc: compile a program under APExp and verify it builds/runs correctly. In the future, more tests will be put in this directory.

## Current Development Focus (as of 2026-04)

- POSIX threading (`pthread`) — `sys/src/ape/lib/ap/thread/` (uncommitted: `cond_timedwait.c`)
- Async I/O (`aio`) — `sys/src/ape/lib/ap/aio/aio.c` (uncommitted)
- C11/C23 compiler features — `_Generic` support recently added
- pthread header — `sys/include/ape/pthread.h` (uncommitted modifications)

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

**Named initializers for static aggregates (17b):** Works — was never broken,
the localeconv.c error was caused by missing struct members in `locale.h`, not a compiler bug.

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
  — always returns C.UTF-8, no `libc.global_locale` or pthread->locale references
- `dcngettext.c`: stub — always returns untranslated string
- `localeconv.c`: positional initializers (no designated initializers at file scope)
- `locale.h`: added 6 C99 `int_p_*`/`int_n_*` members to `struct lconv`

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


