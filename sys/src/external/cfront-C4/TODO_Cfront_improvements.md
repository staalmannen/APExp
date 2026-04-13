# cfront-3 → C Translation Project: Handoff Document

## Project Goal

Translate the cfront-3 C++ compiler (AT&T, 1994) into pure C, with:
1. Correct 64-bit / LLP64 operation (Plan 9 amd64 / 9front)
2. Ability to translate modern C++ to C (namespace and exception support — in progress)

The deliverable so far is `cfront-c-llp64.tar.gz`: a fully bootstrapped, LLP64-patched
set of C source files that build into a working `cfront` binary.

---

## Repository Structure

```
cfront-c/
├── src/            ← the translated C sources (your working tree)
│   ├── *.c         ← one per original .cpp file (34 files) + _stdio.c + cfront_stubs.c
│   ├── *.h         ← headers copied verbatim from cfront-3/src/
│   └── README.md   ← build instructions and fix history
└── incl/           ← cfront-3's bundled C++ headers (32-bit era, needs APE replacement)


```

---

## How the Translation Was Done

```bash
# Preprocess each .cpp through gcc, then pipe through the working cfront binary:
gcc -E -I$SRC -I$INCL -D__HAVE_SIZE_T -D__cfront__ -D__cplusplus=1 \
    -D__signed__= -D__null=0 -U__GNUC__ $FILE.cpp 2>/dev/null \
  | /path/to/cfront-3/cfront +a1 2>/dev/null > $FILE.c

# -U__GNUC__ is CRITICAL: without it, the `enum bool { false, true }` in template.h
# is suppressed, and cfront dies with "bool is not a type name".

# y.tab.cpp (yacc output) is also run through cfront rather than copied raw.
# _stdio.c is kept as plain C (provides _get_stdin/stdout/stderr wrappers).
```

---

## Build Instructions

```bash
cd cfront-c/src

# All main .c files — with ../incl for cfront's own type declarations:
for f in Bits.c alloc.c block.c dcl.c dcl2.c dcl3.c dcl4.c del.c discrim.c \
         error.c expand.c expr.c expr2.c expr3.c find.c hash.c lalex.c lex.c \
         main.c norm.c norm2.c print.c print2.c repr.c simpl.c simpl2.c \
         size.c table.c template.c tree_copy.c tree_walk.c typ.c typ2.c \
         y.tab.c; do
    gcc -I. -I../incl -D__HAVE_SIZE_T -w -g -c $f
done

# CRITICAL: _stdio.c and cfront_stubs.c WITHOUT -I../incl
# (incl/stdio.h redefines stderr as _get_stderr() — causes infinite recursion)
gcc -I. -D__HAVE_SIZE_T -w -g -c _stdio.c
gcc -I. -D__HAVE_SIZE_T -w -g -c cfront_stubs.c

gcc -g -o ../cfront *.o
```

---

## Fixes Applied (Full History)

### 1. cfront boilerplate in every TU
Every translated file starts with `char __cfront_version_303_xxxxxxxx;`.
**Fix:** Kept in `Bits.c` only; removed from all other files with `sed`.

### 2. Multiple-definition link errors (C++ static members)
cfront emits a global definition for every C++ static class member in every TU
that includes the header defining that class.
**Fix:** In all TUs except the "owner", change bare definitions to `extern`:
- `alloc.c` owns: pool freelists (`name_free__4name`, `stmt_free__4stmt`,
  `expr_free__4expr`, `fct_free__3fct`, `ptr_free__3ptr`, `table_free__5table`,
  `table_free__6ktable`, `vec_free__3vec`, `ptfct_free__9templ_fct`)
- `template.c` owns: template statics (`actuals__17templ_compilation`, etc.)
- `lalex.c` owns: `free_toks__7toknode`

### 3. FILE* globals initialised to NULL
`lex.c` has `void *out_file = 0` and `void *in_file = 0` (cfront couldn't
evaluate `stdout`/`stdin` at translation time). Same for `pt_file`, `dtpt_file`.
**Fix:** `cfront_stubs.c` uses `__attribute__((constructor(101)))` to set
`out_file = stdout` and `in_file = stdin` before `main()` runs.

### 4. `setbuf` crash in `error_init`
`error_init__Fv()` calls `setbuf(_get_stderr(), errbuf)`. Crashes because
`incl/stdio.h` defines `FILE` as `void`, so the FILE struct layout differs
from the 64-bit glibc FILE struct that `setbuf` actually uses internally.
**Fix:** Removed the `setbuf` call from `error.c`. It's a performance hint only.

### 5. `__vec_new` ignored constructors
The original stub `__vec_new(p, n, sz, ctor)` discarded `ctor`. cfront's
`Block<T>` template allocates arrays of objects; without constructor calls,
the internal pointer fields (`p`, `n`) were garbage, causing `free()` crashes
when those elements were later cleared/transferred.
**Fix:** `cfront_stubs.c` now loops and calls `ctor(element)` for each element.
`__vec_delete` similarly calls `dtor(element, 0)` before `free()`.

### 6. `_stdio.c` recursive stderr (the subtle one)
`incl/stdio.h` (line ~139) defines:
```c
#define stderr  _get_stderr()
#define stdout  _get_stdout()
#define stdin   _get_stdin()
```
When `_stdio.c` was compiled with `-I../incl`, `return stderr` expanded to
`return _get_stderr()` — infinite recursion, stack overflow.
**Fix:** Compile `_stdio.c` and `cfront_stubs.c` **without** `-I../incl`.

### 7. LLP64 allocation sizes (`unsigned long` → `size_t`)
On LLP64 (Plan 9 amd64): `sizeof(unsigned long) = 4`, `sizeof(size_t) = 8`.
cfront translates `new T` as `__nw__FUl((unsigned long)(sizeof(T)))`.
**Fix:**
- All `(unsigned long)(sizeof(...))` → `(size_t)(sizeof(...))` in 34 files
- All `extern void *__nw__FUl (unsigned long)` → `(size_t)` declarations
- `expand.c`: `(unsigned long)pointer` → `(size_t)pointer` in `temp__FPCcP4name`
  (the function that generates unique temp names from pointer addresses)

---

## Key Source Files to Know

| File | Role | Notes |
|------|------|-------|
| `cfront_stubs.c` | Runtime shims | The "glue" between C++ ABI and plain C. Contains `_main`, `__vec_new`, `__vec_delete`, early init. Compile WITHOUT `-I../incl`. |
| `_stdio.c` | stdio wrappers | Provides `_get_stdin/stdout/stderr`. Compile WITHOUT `-I../incl`. |
| `main.c` | Entry point | `main()` + init sequence: `error_init → otbl_init → lex_init → syn_init → typ_init → simpl_init → run`. |
| `y.tab.c` | Parser | Translated from `y.tab.cpp` (byacc output from `gram.y`). The grammar is the heart of any new feature work. |
| `norm.c` | Normaliser | Post-parse tree normalisation. Where declaration specifiers get combined with declarators. |
| `dcl.c/dcl2.c/dcl3.c/dcl4.c` | Declaration processing | Class, function, template declaration handling. |
| `simpl.c/simpl2.c` | Simplifier | Converts C++ constructs to C-compatible form. Constructor calls, `new`/`delete`, etc. |
| `alloc.c` | Memory pools | Pool allocator for all AST nodes. Contains `__nw__FUl` (generic operator new). |
| `block.c` | Block template | `Block<T>` — cfront's internal growable array. Used heavily in the parser and overload resolution. |

---

## Bootstrap Verification

The canonical test: translate all 34 of cfront's own `.cpp` source files using
both the g++ reference binary and the C binary, and compare output.

```bash
#!/bin/bash
CFRONT1=/path/to/cfront-3/cfront     # g++ reference
CFRONT2=/path/to/cfront-c/cfront     # C build
SRC=/path/to/cfront-3/src
INCL=/path/to/incl-linux32
FLAGS="-E -I$SRC -I$INCL -D__HAVE_SIZE_T -D__cfront__ -D__cplusplus=1 -D__signed__= -D__null=0 -U__GNUC__"

ok=0; fail=0
for f in $SRC/*.cpp; do
    out1=$(gcc $FLAGS $f 2>/dev/null | $CFRONT1 +a1 2>/dev/null)
    out2=$(gcc $FLAGS $f 2>/dev/null | $CFRONT2 +a1 2>/dev/null)
    # Normalise address-derived temp names before comparing:
    n1=$(echo "$out1" | sed 's/__[0-9]__X\([^[:space:];,()*]*\)vc[a-z]*/TMPNAME/g')
    n2=$(echo "$out2" | sed 's/__[0-9]__X\([^[:space:];,()*]*\)vc[a-z]*/TMPNAME/g')
    if [ "$n1" = "$n2" ]; then ok=$((ok+1)); else fail=$((fail+1)); echo "FAIL: $f"; fi
done
echo "$ok/34 pass"
```

**Current result: 34/34 pass** (after LLP64 fixes).

The only differences between the two binaries are internal temporary variable
names like `__0__X__V1400qrh3lctewcnm` vs `__0__X__V1400qmlnnfrtvcnm` — these
encode memory addresses and differ between builds but are semantically identical.

---

## Next Steps: Namespace Support

### What cfront does not handle
- `namespace foo { ... }` — no concept of namespaces
- `using namespace std;` — unknown
- `foo::bar` (non-class) — confused with class scope

### Recommended approach

**Phase 1: Preprocessing pass** (new file, e.g. `ns_strip.c`)

A simple C program that reads preprocessed C++ and:
1. Strips `namespace foo {` / `}` (matching braces, tracking depth)
2. Converts `using namespace foo;` to nothing (or a comment)
3. Handles `using foo::bar;` by emitting a typedef/alias at the use site

**Phase 2: Name mangling extension**

cfront already mangles `class::member` as `member__Nclass`.
Extend this to `ns::name` → `name__Sns` (using `S` prefix for namespace,
`N` for class — already cfront's convention).

**Phase 3: ADL (argument-dependent lookup)**

Only needed for operator overloads. Can be stubbed: emit a warning and
fall back to unqualified lookup.

### Key grammar entry points for namespace work
In `gram.y` (→ `y.tab.c`):
- Look for where `TNAME` tokens are handled in declarations
- The `declaration` rule is where top-level names enter the symbol table
- `name_dcl` in `dcl.c` is the workhorse for binding names

---

## Next Steps: Exception Support

### What cfront does not handle
- `try` / `catch` / `throw` — no exception support whatsoever

### Recommended approach: `setjmp`/`longjmp` transformation

cfront already uses `error()` + `exit()` for its own "exceptions".
The generated C needs a runtime exception stack.

**Runtime structure** (add to `cfront_stubs.c`):
```c
#include <setjmp.h>
struct __cfront_eh_frame {
    jmp_buf env;
    struct __cfront_eh_frame *prev;
    void *exception;        /* thrown object */
    int   exception_type;   /* type tag */
};
extern struct __cfront_eh_frame *__cfront_eh_top;
```

**Translation of `try { S } catch(T& e) { H }`:**
```c
struct __cfront_eh_frame __frame;
__frame.prev = __cfront_eh_top;
__cfront_eh_top = &__frame;
if (setjmp(__frame.env) == 0) {
    /* S */
    __cfront_eh_top = __frame.prev;
} else {
    __cfront_eh_top = __frame.prev;
    if (__frame.exception_type == TYPE_TAG_T) {
        T& e = *(T*)__frame.exception;
        /* H */
    } else {
        /* rethrow */
        longjmp(__cfront_eh_top->env, 1);
    }
}
```

**Translation of `throw expr`:**
```c
__cfront_eh_top->exception = (void*)&(expr);
__cfront_eh_top->exception_type = TYPE_TAG_FOR_TYPEOF_EXPR;
longjmp(__cfront_eh_top->env, 1);
```

### Key grammar entry points for exception work
- Add `TRY`, `CATCH`, `THROW` tokens to `token.h`
- Add grammar rules to `gram.y` (try-statement, throw-expression)
- `simpl.c`/`simpl2.c` — add `simpl` methods for try/catch/throw nodes
- `print.c` — add C output for the transformed nodes

---

## Architecture Quick Reference

### AST Node Types (TOK enum in token.h)
Every AST node has a `base` field (type `TOK = unsigned char`) indicating kind.
Key values: `NAME`, `FCT`, `CLASS`, `STMT`, `EXPR`, `BLOCK`, `TYPE`, etc.
The complete list is in `token.h` (the `keys[]` array gives string names).

### Memory Management
All AST nodes are pool-allocated via the freelists in `alloc.c`.
Pattern: `new name(...)` → `__nw__4nameSFUl(sizeof(name))` → pool or malloc.
`PERM(p)` marks a node permanent (never freed). Used for built-in types etc.

### Name Resolution
- `gtbl` — global symbol table (`Ptable`)
- `Ctbl`/`Gtbl` — ktable (key-based hash table) wrappers
- `table_look` / `k_find_name` — lookup functions
- `name_dcl` in `dcl.c` — inserts a name into the current scope

### Type System
Types are structs with a `base` TOK field:
- `struct type` — base type (INT, CHAR, VOID, etc.)
- `struct fct` — function type (has `returns`, `argtype`)
- `struct ptr` — pointer/reference type (has `typ`, `memof`)
- `struct vec` — array type
- `struct classdef` — class type (has `memtbl`, `c_ctor`, etc.)

### The Translation Pipeline
```
stdin → lex (lalex.c/lex.c) → parse (y.tab.c/gram.y)
     → normalize (norm.c/norm2.c)
     → type-check/declare (dcl*.c, typ*.c, expr*.c, find.c)
     → simplify to C (simpl*.c, expand.c)
     → print C output (print*.c, repr.c)
```

---

## Known Limitations of cfront-3

1. **No exceptions** (`try`/`catch`/`throw`)
2. **No namespaces**
3. **Templates**: handles simple class/function templates; SFINAE, partial
   specialisation, and dependent names are unreliable
4. **`bool`**: handled via `enum bool { false, true }` (enabled by `-U__GNUC__`)
5. **`long long`**: partially supported
6. **RTTI** (`dynamic_cast`, `typeid`): not supported
7. **STL**: no `<string>`, `<vector>` etc. — only ancient `libC` streams
8. **`constexpr`**, `auto`, lambdas, range-for: not supported (post-C++11)

