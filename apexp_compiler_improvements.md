# APExp compiler improvements and future challenges

*Covers: `sys/src/cmd/cc/` (common front-end) and all arch backends (`6c`, `8c`,
`5c`, `7c`, `kc`, `vc`, `qc`, `tc`, `zc`, etc.)*

*Last updated: 2026-04*

---

## Background

The Plan9 C compiler suite ("kencc") targets C89 with a handful of extensions.
APExp patches it to understand the C99/C11/C23 dialect used by the portable
software it aims to host. The strategy throughout is minimalism: handle the
syntax enough to not reject code, emit semantically correct output for the
patterns that actually appear in practice, and silently ignore or stub features
that are only needed for runtime library behaviour that APExp provides itself.

All arch compilers share `sys/src/cmd/cc/` as a common front-end (`lex.c`,
`cc.y`, `dcl.c`, `com.c`, `sub.c`, `pgen.c`). Token additions (`LTYPEOF`,
`LALIGNOF`, `LGENERIC`, `LNULLPTR`, `LSTATICASSERT`) are defined in the
grammar and exported through `y.tab.h`, which each arch backend includes via
`lex.c`. Build order is therefore: `cc` first (regenerates `y.tab.h`), then
each arch backend.

---

## Part I — Correctness and ABI fixes

These were showstopper bugs that had to be resolved before the compiler could
build real software. They are committed and should not regress.

### 1. typesuvinit[] — TVLONG/TUVLONG removed (`cc/sub.c`)

`TVLONG`/`TUVLONG` were in `typesuvinit[]`, which marks types that use the
struct-return calling convention (hidden first-argument pointer). This made
every function returning `vlong`/`uvlong` use the wrong ABI, including `6l`
itself. The correct table is:

```c
int typesuvinit[] = { TSTRUCT, TUNION, TCFLOAT, TCDOUBLE, -1 };
```

**Invariant:** never add integer types to this table.

### 2. Register allocator: maxregion=600 (all `*c/reg.c`)

`maxregion` had been reduced to 300 during a rebase. This triggered an
`allocn()` crash when compiling large functions such as `yyparse` in flex
and similar parser-generator output. Restored to 600 in all arch `reg.c`
files.

### 3. CLOCAL missing from naddr() (all `*c/txt.c`) — three locations per file

Inside a function, `static` variables receive class `CLOCAL` (not `CSTATIC`).
All arch `naddr()` functions only handled `CSTATIC`, so `CLOCAL` variables
fell through to the `bad:` label producing "bad in naddr: NAME" errors.

Fixed at three locations in each arch's `txt.c`:
- Global-emit loop: `s->class != CSTATIC && s->class != CLOCAL`
- naddr ONAME case: `n->class == CSTATIC || n->class == CLOCAL`
- gpseudo D_STATIC selection: `s->class == CSTATIC || s->class == CLOCAL`

### 4. ar duplicate-symbol abort (`ar.c`)

Plan9 `ar r` aborted the entire archive operation on the first duplicate
text symbol, leaving 150+ critical members out of `libap.a` (observed size
~3.5 MB vs expected ~6.2 MB). Fixed in `rcmd()`: reset `dupfound=0` per
member and `continue` rather than aborting the whole run. The arch/amd64
assembly directory is built last specifically so assembly implementations
overwrite C-port fallbacks via this duplicate-skip mechanism.

### 5. Compound literal lvalue (`cc/dcl.c`, `cc/com.c`)

`&(type){...}` produced "not an l-value" errors. Fix:

- `dcl.c` `compoundlit()`: set `seq->addable = 1` when the type is not a
  complex number and not a struct/union.
- `com.c` OCOMMA case: same guard for `n->addable = r->addable`.

The `iscmplx`/`typesu` guard is critical — without it, complex-number OCOMMA
nodes get `addable=1`, which causes "unknown type in regalloc: UNION" errors.

---

## Part II — C99 language features

All C99 items are now implemented. The table below maps each feature to the
file(s) it touches and any traps worth remembering.

| Feature | Files | Notes |
|---------|-------|-------|
| `\uXXXX`/`\UXXXXXXXX` universal chars | `lex.c` `escchar()` | Returns Rune; `runetochar()` encodes UTF-8 |
| Binary literals `0b1010` | `lex.c` `tnum:` | Was already present |
| Digit separators `1'000'000` | `lex.c` — all 8 numeric loops | Covers hex, octal, float mantissa, and exponents |
| `_Static_assert` | `lex.c` itab; `cc.y` prog+slist+edecl | Three scopes: file, function, struct body |
| `nullptr` | `lex.c` LNULLPTR; `cc.y` pexpr | OCONST with `types[TIND]`, `vconst=0` |
| `typeof`/`__typeof__` | `lex.c` LTYPEOF; `cc.y`; `com.c`; `sub.c` | Was silently swallowed before (see below) |
| `_Alignof`/`__alignof__` | `lex.c` LALIGNOF; `cc.y`; `com.c` | Was swallowed; now returns `align(1,T,Ael1)` |
| `[[attributes]]` | `lex.c` case `'['` | Depth-counts `[[` to `]]`; ignores content |
| `__builtin_*` | `lex.c` swallow block | Swallows argument list; returns LCONST 0 |
| `_Atomic`/`__atomic_*` | `lex.c` drop-silently | Dropped like `__thread` |
| `_Generic` | `lex.c` LGENERIC; `cc.y` | See §_Generic below |
| `#elifdef`/`#elifndef` | `cpp/cpp.h`; `cpp/nlist.c`; `cpp/cpp.c` | Also fixed skipping-block dispatch |
| `static_assert` (C23 spelling) | `lex.c` | Alias for `_Static_assert` |
| `alignof` (C23 spelling) | `lex.c` | Alias for `_Alignof` |
| `typeof_unqual` (C23) | `lex.c` | Alias for `typeof`; qualifier stripping not yet done |
| `main()` implicit `return 0` | `cc/pgen.c` | C99 §5.1.2.2.3 — synthesises `gen(&ret)` with zero |
| Non-void fall-off | `cc/pgen.c` | Was a hard error; downgraded to warning |
| Designated initialisers | `cc/dcl.c` | Was already present |
| VLA | `cc/vla.c` | Was already present |
| Hex float literals `0x1.8p+1` | `lex.c` | Digit-separator fix extended to hex float exponent |
| Anonymous struct/union | `cc/dcl.c`; `cc/sub.c` | Was already present (no changes needed) |
| Named initialisers for static aggregates | — | Was never broken |

### typeof / `__typeof__` — critical prior bug

Before the LTYPEOF patch, `__typeof__` was in the swallow block alongside
`__attribute__`. The entire argument `(expr)` was consumed and discarded,
turning `__typeof__(int) y;` into `y;` with no type. This silently corrupted
**all** uses of `__typeof__` in header macros (including glibc-compatible
headers). Fixed by removing it from the swallow block and adding `LTYPEOF`
to the itab and grammar.

Two grammar contexts handle it:
- `uexpr: LTYPEOF '(' cexpr ')'` → OTYPEOF node (allows `sizeof(typeof(x))`)
- `complex: LTYPEOF '(' cexpr ')'` → calls `complex($3)`, returns `$3->type`
- `complex: LTYPEOF '(' tlist abdecor ')'` → `dodecl(NODECL,...)`, returns `lastdcl`

`OTYPEOF` in `com.c`: evaluates child type, collapses to typed zero OCONST.
`OTYPEOF` in `sub.c`: added to no-side-effects list and opname table.

---

## Part III — C11 / C23 features

### _Generic (C11 §6.5.1.1)

**Location:** `cc.y` — grammar action + `generic_select()` helper at the end
of the file (after `%%`).

**Design rationale:** handled entirely in the grammar rather than in `tcom()`,
so that type-checking is never applied to unselected association branches
(which may reference identifiers not valid for the controlling type).

Association list representation: OLIST of OCAST nodes where each node's
`->type` holds the association type (NULL for `default:`), and `->left`
holds the value expression.

`generic_select()` algorithm:
1. `generic_ctrl_type()` applies lvalue conversion: array→pointer,
   function→pointer, strip qualifiers — exactly as C11 §6.5.1.1p2 requires.
2. Walk the OLIST with `sametype()` to find a matching association.
3. Return the matching `->left`, or the `default:` branch, or `Z` on no match.

`sametype()` ignores const/volatile (only checks `GNORET`), so
`_Generic(x, const int: ..., int: ...)` would be ambiguous — both match.
This is correct per the standard.

### Other C11/C23 items

| Feature | Status |
|---------|--------|
| `_Static_assert` | Done (file, function, struct scopes) |
| `nullptr` | Done |
| `[[attributes]]` | Done (ignored) |
| `#elifdef`/`#elifndef` | Done |
| `_Alignof` query | Done |
| `_Generic` | Done |
| `typeof`/`__typeof__` | Done |
| `static_assert`, `alignof` | Done (C23 aliases) |
| `typeof_unqual` | Alias only — qualifier stripping not implemented |
| `_Alignas` in declarations | Not implemented (layout effect) |
| `_Atomic` full stdatomic.h | Dropped as qualifier; no CAS operations |
| `constexpr` objects (C23) | Not implemented |
| `auto` type deduction (C23) | Not implemented |

`tgmath.h` was written using `_Generic` to dispatch to the correct variant
of each math function. It uses `fn` (not `f`) as the parameter name in
helper macros to avoid the `f##f` token-paste collision.

---

## Part IV — Infrastructure improvements

### GAS-compatible `as` front-end

A GAS-compatible assembler front-end was added to the native Plan9 assemblers.
This allows software that emits inline assembly in AT&T / GAS syntax to use
the Plan9 assembler backend. Implemented by translating AT&T mnemonics,
register names, and addressing modes to Plan9 assembler conventions.

### Bitfield support

Full C bitfield support was ported from @jamoson's kencc patch. Plan9's
original compiler had partial or broken bitfield handling; this patch adds
correct layout and code generation for signed/unsigned bitfields within
struct members, including bitfields spanning word boundaries.

---

## Part V — Known invariants and build notes

### Build order for compiler changes

```
cd sys/src/cmd/cc  && mk nuke && mk install   # regenerates y.tab.h
cd sys/src/cmd/cpp && mk nuke && mk install
cd sys/src/cmd/6c  && mk nuke && mk install   # (and all other *c dirs)
```

`cc` must build first because `y.tab.h` (containing token definitions like
`LTYPEOF`, `LALIGNOF`, `LGENERIC`, `LNULLPTR`, `LSTATICASSERT`) is included
by `lex.c` in each arch compiler.

### Self-hosting as correctness test

After any change, rebuild the compiler with itself multiple times. If the
second build produces identical object files to the first, the compiler is
internally consistent:

```
cd sys/src/cmd/cc && mk nuke && mk install
cd sys/src/cmd/6c && mk nuke && mk install
# repeat; diff the resulting objects
```

### CLOCAL vs CSTATIC invariant

Every arch's `txt.c` must handle both `CLOCAL` and `CSTATIC` at three
locations (global emit, naddr ONAME, gpseudo D_STATIC). Adding a new arch
or rebasing from upstream kencc requires checking all three.

### typesuvinit[] invariant

Never add `TVLONG`/`TUVLONG` to this table. Doing so breaks the ABI of every
function returning a 64-bit integer.

---

## Part VI — Future challenges

These are listed roughly in order of difficulty and anticipated impact.

### 1. `typeof_unqual` qualifier stripping

Currently `typeof_unqual(T)` is an alias for `typeof(T)` — qualifiers are
not stripped. Correct implementation requires: after resolving the type
from `typeof`, clear the `GCONSTNT`/`GVOLATILE` bits from the type node.
Low effort; high correctness benefit for C23 code.

### 2. `_Alignas` in declarations

`_Alignof` (the query) works. `_Alignas(N)` as a declaration specifier
(affecting struct layout and variable placement) does not. Implementation:
parse the alignment argument; store it in the decl node; in the struct
layout pass (`sualign`), honour the alignment by padding before the member;
for local variables, round up the frame offset.

### 3. `_Atomic` / stdatomic.h

Currently dropped as a qualifier; atomic operations (`__atomic_load`,
`__atomic_store`, `__atomic_compare_exchange`, etc.) are swallowed as
`__builtin_*`. A practical minimum for C11/C23 compatibility:
- Keep dropping `_Atomic` as a storage qualifier (acceptable for Plan9's
  single-address-space model on uniprocessor builds).
- Provide `<stdatomic.h>` with `atomic_*` types as non-atomic equivalents
  and `atomic_load/store/exchange` as memory-barrier-less macros.
  This satisfies the vast majority of portable code that uses atomics for
  documentation rather than genuine lock-free synchronisation.

### 4. Digit separators in float exponent (casep loop)

Digit separators (`1'000`) were added to all 8 numeric lexer loops. Verify
that the `casep:` loop (hex float exponent, `p`/`P`) correctly handles
`0x1.8p+1'0`. Likely a one-line fix identical to the other loops.

### 5. `constexpr` objects (C23)

`constexpr int N = 42;` at file scope should behave like `static const int`.
In function scope it should behave like a constant expression. Low impact
for now (few real-world headers use it yet), but will become necessary as
C23 adoption increases.

### 6. `auto` type deduction (C23)

`auto x = expr;` — infer type from initialiser. This is the largest single
remaining C23 item and touches the declaration parser deeply. Required when
porting C23 code that uses `auto` pervasively (e.g. modern C++ shims). Not
urgent for the current APExp target software base.

### 7. Variadic macro `__VA_OPT__` (C99/C++20)

`__VA_OPT__(tokens)` expands to `tokens` when `__VA_ARGS__` is non-empty,
to nothing otherwise. Used in modern macro-heavy headers. Implemented in
the preprocessor (`cpp/`); requires tracking whether the current `...`
expansion is empty.

### 8. `#pragma` handling improvements

Currently `#pragma` is silently dropped. Several important pragmas affect
compiler behaviour: `#pragma pack(N)`, `#pragma GCC diagnostic`, and
`#pragma once`. `#pragma once` is the highest-value item — it is used as
a guard in many headers as a substitute for or complement to `#ifndef`
guards. Implementation: maintain a set of canonicalised file paths seen
with `#pragma once`; skip re-inclusion.

### 9. Designated initialisers for union types

Designated initialisers for struct types work. For unions (`(union U){ .field = val }`)
there may be edge cases in the existing `dcl.c` code. Worth a targeted test
with union compound literals.

### 10. VLA in struct/union (not standard, but GCC extension)

Some GCC-oriented code uses `struct { int n; char data[]; };` (flexible
array members, C99 §6.7.2.1) or runtime-sized member arrays (GCC extension).
Flexible array members (`char data[];` as the last member) are C99 standard
and should be verified to work. True VLA struct members are a GCC extension
and are lower priority.

### 11. Multi-arch build consistency

Each arch compiler has its own `txt.c`, `reg.c`, `cgen.c`, etc. Patches
applied to `6c` (amd64) must be manually replicated to all other arch
directories. A systematic audit pass after any `txt.c`-touching patch is
good hygiene — particularly for the CLOCAL/CSTATIC fix and any future
`naddr()` additions.

---

## Summary: current C standard support level

| Standard | Coverage | Confidence |
|----------|----------|------------|
| C89 / ANSI C | ~100% | High — this is the baseline |
| C99 | ~95% | High — all major features present |
| C11 | ~70% | Medium — `_Generic`, `_Static_assert`, `_Alignof`, threads via libap; `_Atomic` stubbed |
| C23 | ~40% | Low-medium — aliases, `nullptr`, `[[attrs]]`, `static_assert`, `typeof_unqual`; major items pending |

The gap between nominal support and real-world porting success is small:
the remaining unsupported items (`_Alignas`, full `_Atomic`, `constexpr`,
`auto`) appear rarely in the portable C code that APExp targets. The
compiler successfully builds a broad range of GNU tools, Lua, PCRE2, Tcl,
gettext, flex, byacc, and GNU make.
