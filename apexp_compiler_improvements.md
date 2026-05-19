# APExp compiler improvements and future challenges

*Covers: `sys/src/cmd/cc/` (common front-end) and all arch backends (`6c`, `8c`,
`5c`, `7c`, `kc`, `vc`, `qc`, `tc`, `zc`, etc.)*

*Last updated: 2026-05*

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
| `typeof_unqual` (C23) | `lex.c` LTYPEOF_UNQUAL; `cc.y`; `com.c` | Now properly strips const/volatile qualifiers |

| `bool`, `true`, `false` | `lex.c` `itab[]` | C23 keywords; `bool` mapped to `TUCHAR`, `true`/`false` to `1`/`0` |
| `__has_include` | `cpp/eval.c`; `cpp/include.c` | C23 builtin; checks file existence in include path |
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
| `static_assert`, `alignof` | Done (C23 aliases) | Now also supports single-argument `static_assert` |
| `typeof_unqual` | `lex.c` LTYPEOF_UNQUAL; `cc.y`; `com.c` | Now properly strips const/volatile qualifiers |
| `__VA_OPT__` | `macro.c` `substargs` | Fully compliant C23/C++20 implementation |
| `_Alignas` in declarations | `cc/dcl.c` `adecl()`, `sualign()` | Layout effect done: struct members + auto vars; `LALIGN` token in `cc.y` |
| `_Atomic` / `stdatomic.h` | `lex.c` drop qualifier; `sys/include/ape/stdatomic.h` | Header provides non-atomic typedefs + Plan9 spinlock-based ops |
| `constexpr` objects (C23) | Not implemented |
| `auto` type deduction (C23) | Done — implemented in `cc.y` `autoadlist` rule |

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

### 1. `_Alignas` in declarations — DONE (2026-05)

`_Alignas(N)` as a declaration specifier is now implemented (`cc/dcl.c`).
- Struct members: `sualign()` pads before the member to meet the requested
  alignment. The alignment value is stored in the type's `garb.c2` field.
- Auto variables: `adecl()` rounds up the frame offset to the requested alignment.
- `LALIGN` token added to the grammar.
`_Alignof` (the query) was already done; `_Alignas` now completes the pair.

### 3. `_Atomic` / stdatomic.h — PARTIAL (2026-05)

`_Atomic` is still dropped as a qualifier. `<stdatomic.h>` now exists at
`sys/include/ape/stdatomic.h` providing:
- `_Atomic(T)` as a no-op macro (typedef equivalent)
- `atomic_*` type aliases for all C11 atomic types
- `atomic_load`, `atomic_store`, `atomic_exchange` backed by Plan9 spinlocks
- `atomic_compare_exchange_strong/weak` with spinlock-based CAS emulation
- `atomic_fetch_add/sub/and/or/xor` operations
- `ATOMIC_FLAG_INIT`, `atomic_flag_test_and_set`, `atomic_flag_clear`
This satisfies portable code that uses atomics for documentation and basic
coordination; genuine lock-free algorithms are not supported.

### 4. Digit separators in float exponent (casep loop)

Digit separators (`1'000`) were added to all 8 numeric lexer loops. Verify
that the `casep:` loop (hex float exponent, `p`/`P`) correctly handles
`0x1.8p+1'0`. Likely a one-line fix identical to the other loops.

### 5. `constexpr` objects (C23)

`constexpr int N = 42;` at file scope should behave like `static const int`.
In function scope it should behave like a constant expression. Low impact
for now (few real-world headers use it yet), but will become necessary as
C23 adoption increases.

### 6. `auto` type deduction (C23) — DONE

Implemented in `cc.y` via `autoadlist` non-terminal. Handles `auto x = expr;`,
`auto *p = ptr;`, multiple declarations per statement, and `for(auto x = ...)`.
See CLAUDE.md for full design notes.

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

## Part VII — Preprocessor: Deep Macro Rescanning and Token Pasting

Standard C (C89/C99) requires that after a macro is expanded, the resulting
tokens are rescanned for more macros. This process must repeat until no more
macros are found. Both the integrated preprocessor in `cc` and the standalone
`cpp` (used by `pcc`) historically hit limits on deep expansion chains,
particularly those involving token joining (`##`) or deep nested definitions.

### The Problem

In complex chains such as `PNG_KNOWN_CHUNKS` → `PNG_CHUNK(iCCP, 14)` →
`CDiCCP` → `LKMin` → `LZ77Min`, the preprocessor often failed at the final
steps. This was due to two structural weaknesses in the original `kencc`
preprocessors:
1.  **Single-Pass Iteration**: The token loop typically advanced past newly
    expanded tokens, skipping rescanning of the expansion result in the
    same pass.
2.  **Pointer Invalidation**: Macro expansion often triggers buffer
    reallocations. The original use of pointers (`Token *tp`) for iteration
    made the logic unstable during deep expansions.

### Implementation Fixes (Standalone `cpp`)

The following improvements were applied to `sys/src/cmd/cpp/` to stabilize
the preprocessor for complex software like `libpng` and `f2c`:

1.  **Exhaustive Rescanning**: Modified `expandrow` in `macro.c` to use
    **index-based iteration** and, crucially, **reset the iteration index to 0**
    after every expansion. This ensures that every token on a line is
    continuously re-evaluated until no more macros remain, satisfying the
    Standard's "repeat until no more macros are found" requirement.
2.  **Indexed Loop Safety**: Converted token iteration from pointers to
    integer indices. This prevents "use-after-realloc" bugs, ensuring that
    the loop remains valid even if the token row buffer is resized during
    an expansion.
3.  **Hideset Expansion**: Increased `HSSIZ` (recursion prevention buffer)
    in `hideset.c` from 32 to **128**. This provides the necessary headroom
    for the extremely deep macro hierarchies found in modern portable C.

### Identifier Handling Improvements (`cc/lex.c`)

To support software that uses GNU attributes or linkage hints as variable names,
the `indeclname` macro in the compiler's lexer was expanded. This ensures that
keywords like `hidden` and `visible` are only swallowed when they appear in
declaration-specifier positions, but are returned as `LNAME` tokens when they
appear after type keywords (`int`, `char`), struct/union specifiers, or
pointer operators. This fixes regressions where common English words used as
identifiers were being incorrectly dropped.

### Remaining Challenges

-   **Concatenation Rescanning**: While exhaustive rescanning is implemented,
    certain cases involving `##` producing a macro name (like `CDiCCP`) may
    still fail to expand in the final step. This suggests a subtle interaction
    where the resulting token might be inheriting a hideset from the operator
    itself or hitting an edge case in the `quicklook` bitmask optimization.
-   **Integrated Preprocessor**: The integrated preprocessor in `sys/src/cmd/cc/`
    requires a similar index-based refactoring to match the robustness of
    the updated standalone `cpp`.

---

## Part VIII — Preprocessor: __VA_OPT__ Support (C23)

Standard C23 (and C++20) introduces `__VA_OPT__(tokens)`, which expands to
`tokens` if the variadic argument list (`__VA_ARGS__`) is non-empty, and to
nothing otherwise. This is essential for handling trailing commas in macros.

### Implementation Fixes (Standalone `cpp`)

Implemented `__VA_OPT__` support in `sys/src/cmd/cpp/macro.c` (`substargs`):
1.  **Keyword Detection**: The preprocessor now recognizes `__VA_OPT__` within
    variadic macros.
2.  **Parentheses Grouping**: Corrected logic to identify the tokens within
    the `__VA_OPT__(...)` construct, supporting nested parentheses.
3.  **Emptiness Check**: Added a check to determine if `__VA_ARGS__` contains
    any non-whitespace tokens.
4.  **Conditional Expansion**: If `__VA_ARGS__` is non-empty, the contents of
    `__VA_OPT__` are rescanned and inserted; otherwise, they are discarded.

---

## Part IX — Preprocessor: #pragma once Support

The standalone preprocessor (`cpp`) supports `#pragma once` as an alternative
to traditional include guards. This ensures that a header file is only included
once per compilation unit, improving build times and simplifying header management.

### Implementation Details

1.  **File Identification**: The preprocessor uses `dirfstat` to uniquely
    identify files based on their device (`dev`) and QID (`qid.path`),
    preventing multiple inclusions even if reached through different paths
    (e.g., symlinks or multiple `-I` flags).
2.  **Blocking List**: A global list of "once-blocked" files is maintained
    during compilation. When `#pragma once` is encountered, the current file's
    identity is added to this list.
3.  **Include Guard**: The `doinclude` logic checks every candidate file
    against the blocking list before opening it, silently skipping any matches.

---

## Part X — Roadmap for Remaining C11/C23 Features

The current implementation provides robust support for core C23 features. The
remaining tasks focus on language-level primitives that require deeper
integration with the compiler's code-generation backend.

### Priority Roadmap

| Feature | Standard | Difficulty | Impact | Notes |
|:---|:---|:---|:---|:---|
| **`_Alignas`** | C11 | Medium | High | Requires `sualign` struct-layout and local frame offset updates. |
| **`auto`** | C23 | High | High | **Done** — `autoadlist` rule in `cc.y`. |
| **`constexpr`** | C23 | High | Medium | File-scope maps to `static const`; function-scope is complex. |
| **`_Atomic` / CAS** | C11 | High | High | Requires mapping to libap atomics or backend intrinsics. |

### Technical Analysis

1.  **`_Alignas` (Priority 1)**: This is the highest-value missing feature. Many
    portable libraries require strict memory alignment for SIMD or cache
    efficiency. Implementation involves passing alignment metadata from the
    parser to the backend's layout pass (`sualign`) and ensuring the stack
    frame allocator respects these requirements.

2.  **`auto` Type Deduction (Priority 2)**: **Done.** Implemented via `autoadlist`
    in `cc.y`. Handles local declarations, pointer depth inference, and `for` loops.

3.  **`constexpr` Objects (Priority 3)**: While C23 makes this more formal,
    the compiler already handles constant expression folding well. The primary
    challenge is managing the `static`-like linkage for file-scope `constexpr`.
    This is generally lower impact than `_Alignas` or `auto`.

4.  **`_Atomic` Operations (Priority 4)**: A full `stdatomic.h` implementation
    requires backend support for CAS (Compare-and-Swap) instructions. Without
    it, atomic operations must be stubbed or implemented via memory barriers
    (which are also incomplete). This is high-effort but necessary for
    multithreaded code.

| Standard | Coverage | Confidence |
|----------|----------|------------|
| C89 / ANSI C | ~100% | High — this is the baseline |
| C99 | ~95% | High — all major features present |
| C11 | ~75% | Medium — `_Generic`, `_Static_assert`, `_Alignof`, threads via libap |
| C23 | ~65% | Medium — aliases, `nullptr`, `[[attrs]]`, `static_assert`, `__VA_OPT__`, `auto` done |

The preprocessor is now significantly more robust and aligns closely with
modern C standards, supporting deep macro recursion, exhaustive rescanning,
variadic macro optimizations (`__VA_OPT__`), and efficient header management
(`#pragma once`).

---

## Part XI — Compound Literal Support (verified 2026-05)

Compound literals (`(Type){...}`) are fully implemented. The following
summarises the implementation so it can be found quickly in future work.

### Implementation locations

| File | Lines | Role |
|:-----|:------|:-----|
| `cc/cc.y` | `xuexpr` production | Grammar: parses `'(' tlist abdecor ')' '{' ilist '}'` and `'{' ilist ',' '}'` (trailing-comma) |
| `cc/dcl.c` | `compoundlit()` | Lowering: creates a hidden auto/static variable (`.clit0`, `.clit1`, …), calls `doinit()` for initialization, converts OLIST → OCOMMA chain, marks OCOMMA `addable=1` for scalar/pointer types |
| `cc/com.c` | `tcom()` OCOMMA case | Type-check: propagates `addable` from right child with same scalar/pointer guard |

### Key design decisions

- **Hidden variable**: `compoundlit` creates a uniquely named `.clitN` variable.
  Inside a function it gets class `CAUTO`; at file scope (`autobn == 0`) it gets
  `CSTATIC` (C99 §6.5.2.5 lifetime semantics).
- **Addable guard**: Only scalar and pointer compound literals are marked
  `addable=1`. Struct/union and complex literals are intentionally NOT marked
  addable to prevent them from entering the `cgen()` register-allocation path
  (which can't handle UNION/STRUCT), forcing them through `sugen()` instead.
  Without this guard you get `"unknown type in regalloc: UNION"` errors.
  The guard appears in both `dcl.c:compoundlit()` and `com.c` OCOMMA.
- **`&(Type){...}`**: Works for scalar/pointer types because `addable=1` causes
  `tlvalue()` to succeed. Struct/union address-of does NOT work (addable=0),
  but this matches the limitation of the whole `cgen` path for aggregates.
- **OLIST → OCOMMA conversion**: Multi-element initializers produce a
  left-leaning OLIST tree from the parser. `compoundlit()` flattens this with
  an explicit stack walk to avoid `"unknown op in cgen: LIST"` errors.

### Known limitations

- `&(struct S){...}` does not produce an addressable lvalue (aggregate compound
  literals are not addable). Workarounds: assign to a named temp, then take
  its address. This mirrors the `cgen`/`sugen` split in the code generator.
- C99 static storage duration at file scope is supported but the hidden
  variable has internal linkage only.

---

## Part XII — DWARF Debug Information in the Plan9 Linkers

### Status (WIP as of 2026-05)

DWARF support has been ported into the APExp linker infrastructure.
The implementation is **in progress** — sections are emitted but integration
with the new `adbg` debugger is not yet complete.

### Source locations

| Path | Contents |
|:-----|:---------|
| `sys/src/cmd/ld/dwarf.c` | Shared DWARF emitter (~1000 lines). Emits `.debug_abbrev`, `.debug_info`, `.debug_line`, `.debug_frame` sections. Walks the linker's prog table to build DIE tree and line program. |
| `sys/src/cmd/ld/dwarf.h` | Public interface: `dwarfaddfrag()`, `dwarfemitdebugsections()` |
| `sys/src/cmd/ld/dwarf_defs.h` | DWARF constants (DW_TAG_*, DW_AT_*, DW_FORM_*, etc.) |
| `sys/src/cmd/6l/mkfile` | Compiles `../ld/dwarf.c` as `dwarf.$O` and links it into 6l |
| `sys/src/ape/lib/dwarf/` | libdwarf (reader) — ported from upstream libdwarf |
| `sys/src/ape/lib/dwarfp/` | libdwarfp (producer/writer) — ported from upstream libdwarf |
| `sys/src/ape/cmd/dwarfdump/` | `dwarfdump` utility (WIP — mkfile has a stale `DWSRC` path pointing to `external/chicken` instead of `external/libdwarf`) |
| `sys/src/ape/cmd/adbg/` | New DWARF-aware debugger (preliminary, not yet committed) |

### Architecture

The linker DWARF emitter in `ld/dwarf.c` is adapted from the Go toolchain's
Plan9 linker. It:
1. Builds an abbreviation table (compile-unit, subprogram, base-type DIEs)
2. Walks the linker's `Prog` list to collect line-number → PC mappings and
   builds the `.debug_line` state machine
3. Emits `.debug_frame` CIE/FDE entries using the stack-pointer adjustment
   records already tracked by the linker (`getspadj` / `AADJSP`)
4. All four sections are appended after the program text in the output binary

### Using DWARF output today

The `dwarfdump` utility (once built) can decode the sections. Example:
```
dwarfdump -a binary
```

The `adbg` debugger is intended as the primary consumer once it stabilises.
Until then, Plan9's native `acid` debugger remains the main debugging tool.

### Known issues / TODOs

- `dwarfdump` mkfile has wrong `DWSRC=../../../external/chicken` — should be
  `../../../external/libdwarf`.
- DWARF sections may not be written to ELF when building APE binaries (the
  APE linker path differs from the native 6l path). Needs verification.
- `adbg` source not yet committed to the repository.
- `libdwarfp` (producer) is ported but not yet wired into the compiler front-end
  to emit type information from the C compiler itself.
