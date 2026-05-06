# cfront-C4

AT&T cfront-3 (1994), translated to plain C, patched for 64-bit systems, and
extended with modern C++ features as a transpiler for Plan 9 / APExp.

The "C4" name captures two ideas:

- **C** — all cfront `.cpp` source files have been machine-translated to plain
  `.c` files, eliminating the bootstrapping problem of needing a C++ compiler
  to build a C++ compiler. Transpilers that target C should themselves be
  implementable in C.

- **4** — this is a 4th-generation enhancement, not a museum piece. The goal is
  to turn cfront into a practical C++11/14 transpiler, covering enough of modern
  C++ to compile real programs on Plan 9 with minimal source changes.

Sources were taken from:
- <https://github.com/mingodad/cfront-3>
- <http://plan9.bell-labs.com/sources/extra/c++.2e.tgz>
- <http://9p.io/sources/contrib/john/package/packages/cfront.iso.bz2>
- <http://www.quintile.net/plan9/c++/c++src.tbz>

---

## Feature Status

### Implemented and working

| Feature | Notes |
|---------|-------|
| 64-bit / LLP64 portability | `unsigned long` → `size_t` throughout |
| `long long` type | |
| Namespace stripping | `ns_strip` preprocessor: strips `namespace` / `using namespace` |
| Exceptions | `try`/`catch`/`throw` via setjmp/longjmp runtime |
| Range-based `for` | `for (T v : container)` — arrays and begin()/end() containers |
| `//` comments | |
| Anonymous structs/unions | |
| Modern C++ headers | `algorithm`, `vector`, `list`, `string`, `iostream`, `fstream`, `strstream`, `iomanip`, `new`, `stdexcept`, `utility`, `functional` |

### Known limitations

| Feature | Status |
|---------|--------|
| Templates | Simple class/function templates work; SFINAE, partial specialisation, dependent names are unreliable |
| RTTI (`dynamic_cast`, `typeid`) | Not supported |
| `bool` as keyword | On APExp: `bool`/`true`/`false` are C23 keywords in pcc — works transparently. On Linux/gcc: requires `-U__GNUC__` (enables `enum bool { false, true }` in `template.h`). |
| `mutable`, `explicit` | Silently ignored or require workarounds |
| `constexpr`, `auto`, lambdas | Not supported (C++11 beyond range-for); `auto` type deduction is also a pending item in the APExp C compiler |
| Standard library completeness | AT&T iostream; newer STL idioms may not work |
| Wide characters | Supported via Plan 9 Rune mapping: `wchar_t` = 16-bit, `wint_t` = Rune (32-bit). Wide string functions are in libap; wide format I/O is macro-mapped to narrow UTF-8 equivalents. |
| `volatile`, `signed` keywords | Not supported |

---

## Repository Layout

```
cfront-C4/
├── src/            ← C-translated cfront sources (34 .c files + headers)
│   ├── *.c         ← one per original .cpp file
│   ├── *.h         ← headers from cfront-3/src/
│   ├── generic.h   ← macro-template helper (moved from old incl/)
│   ├── cfront_stubs.c  ← runtime shims: _main, __vec_new/delete, early init
│   └── _stdio.c    ← provides _get_stdin/stdout/stderr()
├── h/              ← modern C++ headers (installed to sys/include/ape/c++/)
│   ├── algorithm.h, vector.h, list.h, string.h
│   ├── iostream.h, fstream.h, strstream.h, iomanip.h
│   ├── new.h, stdexcept.h, utility.h, functional.h
│   └── mkfile      ← installs headers to $APEXPROOT/sys/include/ape/c++/
├── lib/            ← C++ runtime library sources (cfront-compiled on Plan9)
│   ├── new/        ← operator new/delete, __vec_new/__vec_delete
│   ├── static/     ← global constructor/destructor support
│   ├── stream/     ← iostream implementation (AT&T libC streams)
│   ├── complex/    ← complex number library
│   ├── generic/    ← macro-template runtime
│   ├── string/     ← string.npos and iostream operators for string
│   ├── task/       ← coroutine library (historical)
│   ├── mk/         ← Makefile-based build (Linux/macOS)
│   └── mkfile      ← mk-based build (Plan9/APExp → libc++.a)
├── tools/
│   ├── CC-driver/  ← reference CC driver script (cfront + cc pipeline)
│   ├── munch/      ← global ctor list generator (_main.c, dtors.c)
│   ├── demangler/  ← C++ name demangler
│   ├── szal/       ← size/alignment checker
│   ├── patch/      ← patch-style ctor support (alternative to munch)
│   └── pt/         ← template instantiation support
├── demo/           ← example programs
│   ├── hello/      ← Hello World (sanity check)
│   ├── stream/     ← iostream demo
│   ├── generic/    ← old-style macro template demo
│   ├── string/     ← string class demo
│   └── complex/    ← complex number demo
├── doc/            ← AT&T cfront documentation
├── man/            ← manual pages
├── Makefile        ← Linux/macOS build (cfront binary + libC.a)
└── mkfile          ← Plan9/APExp build
```

---

## Building

### Plan 9 / APExp (canonical build)

On 9front with APExp, the build is driven by the `mkfile` at the root of the
APExp repository (`sys/src/ape/cmd/cfront/mkfile`), which builds the `cfront`
binary. The C++ headers are installed separately:

```
cd sys/src/external/cfront-C4/h && mk install
cd sys/src/external/cfront-C4/lib && mk install   # builds libc++.a
```

### Linux / macOS (development and testing)

```sh
# Build cfront binary
make

# Build cfront + runtime library
make libC.a

# Run demos (requires cfront in PATH or demo/hello/hello.sh adjusted)
make demo
```

The default Linux build compiles library sources with `g++`. To test with the
cfront binary itself, pass `CC=./tools/cfront-cc-wrapper` where the wrapper
runs `cfront | gcc -x c`.

#### Building cfront from source only

```sh
cd src
make
# produces ../cfront
```

The `src/Makefile` compiles with `cc` (or set `CC=gcc`). No special flags or
`-I` paths outside `src/` are required.

---

## How the C Translation Was Done

Each `.cpp` source file was preprocessed with `gcc -E` then piped through the
original g++-built cfront binary, producing C output. The resulting `.c` files
were then hand-patched for the issues documented below.

```bash
gcc -E -I$SRC -I$INCL -D__HAVE_SIZE_T -D__cfront__ -D__cplusplus=1 \
    -D__signed__= -D__null=0 -U__GNUC__ $FILE.cpp 2>/dev/null \
  | /path/to/cfront-3 +a1 2>/dev/null > $FILE.c
# -U__GNUC__ is critical for this Linux translation step: without it,
# template.h's `enum bool { false, true }` is suppressed and cfront
# dies with "bool is not a type name".
```

`y.tab.cpp` (yacc output) was also passed through cfront, not copied raw.
`_stdio.c` and `cfront_stubs.c` are kept as plain C.

### Fixes applied to the translated C

1. **cfront version boilerplate** — `char __cfront_version_303_xxxxxxxx;` emitted
   in every TU. Kept in `Bits.c` only; removed from all others with `sed`.

2. **Multiple-definition link errors** — cfront emits a global definition for
   every static class member in every TU that includes the header. Fixed by
   making all but one TU use `extern`:
   - `alloc.c` owns pool freelists
   - `template.c` owns template statics
   - `lalex.c` owns `free_toks__7toknode`

3. **FILE\* globals initialised to NULL** — `lex.c` has `void *out_file = 0`
   because cfront could not evaluate `stdout` at translation time. Fixed in
   `cfront_stubs.c`: `_main()` (called by cfront's generated startup code
   before user `main()`) calls `early_init()` which sets `out_file = stdout`
   and `in_file = stdin`. Note: `__attribute__((constructor))` is NOT used
   because Plan 9's pcc does not support GCC constructor attributes.

4. **`setbuf` crash in `error_init`** — the old `incl/stdio.h` defined `FILE`
   as `void`, so the struct layout differed from the 64-bit system FILE.
   The `setbuf` call (a performance hint only) was removed from `error.c`.

5. **`__vec_new` ignoring constructors** — the original stub discarded the
   `ctor` argument. Fixed in `cfront_stubs.c` to call `ctor(element)` for
   each array element. `__vec_delete` similarly calls `dtor`.

6. **LLP64 allocation sizes** — on Plan 9 amd64, `sizeof(unsigned long) = 4`
   but `sizeof(size_t) = 8`. All `(unsigned long)(sizeof(...))` casts and
   `extern void *__nw__FUl(unsigned long)` declarations changed to `size_t`
   in all 34 files.

---

## Architecture Reference

### Translation pipeline

```
stdin → lex (lalex.c/lex.c) → parse (y.tab.c / gram.y)
      → normalize (norm.c / norm2.c)
      → type-check / declare (dcl*.c, typ*.c, expr*.c, find.c)
      → simplify to C (simpl*.c, expand.c)
      → print C output (print*.c, repr.c)
```

### Key source files

| File | Role |
|------|------|
| `cfront_stubs.c` | Runtime shims: `_main`, `__vec_new/delete`, early init. Compile WITHOUT `-I../incl`. |
| `_stdio.c` | `_get_stdin/stdout/stderr()`. Compile WITHOUT `-I../incl`. |
| `main.c` | Entry point: `error_init → otbl_init → lex_init → syn_init → typ_init → simpl_init → run`. |
| `y.tab.c` | Parser (yacc output from `gram.y`). Grammar is the entry point for new features. |
| `norm.c` | Post-parse normalisation. Combines declaration specifiers with declarators. |
| `dcl.c / dcl2.c / dcl3.c / dcl4.c` | Declaration processing, class/function/template handling. |
| `simpl.c / simpl2.c` | Simplifier: converts C++ constructs to C. Constructors, `new`/`delete`, range-for, try/catch. |
| `print.c / print2.c` | C output emitter. |
| `alloc.c` | Pool allocator for all AST nodes. `__nw__FUl` = generic operator new. |
| `block.c` | `Block<T>` — cfront's internal growable array. |

### AST node types

Every AST node has a `base` field (`TOK = unsigned char`). The complete list is
in `token.h` (`keys[]` array for string names). Notable extensions:
- `215` — `RANGE_FOR` (range-based for, added in C4)
- `TRY`, `CATCH`, `THROW` — exception nodes (added in C4)

### Memory management

All AST nodes are pool-allocated via the freelists in `alloc.c`.
`PERM(p)` marks a node permanent (never freed). Used for built-in types etc.

### Name resolution

- `gtbl` — global symbol table (`Ptable`)
- `table_look` / `k_find_name` — lookup functions
- `name_dcl` in `dcl.c` — inserts a name into the current scope

### Type system

Types are structs with a `base` TOK field:
- `struct type` — base type (INT, CHAR, VOID, etc.)
- `struct fct` — function type (`returns`, `argtype`)
- `struct ptr` — pointer/reference type (`typ`, `memof`)
- `struct vec` — array type
- `struct classdef` — class type (`memtbl`, `c_ctor`, etc.)

---

## Implementation Notes

### Range-based for (token 215 / RANGE_FOR)

Added in `token.h`, `gram.y`, `dcl2.c`, `simpl2.c`, `print.c`.

Arrays desugar to pointer arithmetic:
```cpp
for (T v : arr)  →  for (T *__r = arr, *__e = arr+N; __r != __e; ++__r) { T v = *__r; ... }
```

Containers desugar to `begin()`/`end()`:
```cpp
for (T v : c)  →  for (auto __b = c.begin(), __e = c.end(); __b != __e; ++__b) { T v = *__b; ... }
```

The loop variable is declared with temporary ARG scope (136) during type-checking
to suppress the "uninitialized const/reference" checks — the initialisation is
supplied by the desugared loop header.

### Exceptions (TRY/CATCH/THROW)

Implemented via a per-thread exception frame stack (setjmp/longjmp).
The runtime stack (`__cfront_eh_top`) lives in `cfront_stubs.c`.

```c
/* try { S } catch (T& e) { H } → */
struct __cfront_eh_frame __frame;
__frame.prev = __cfront_eh_top;
__cfront_eh_top = &__frame;
if (setjmp(__frame.env) == 0) {
    /* S */
    __cfront_eh_top = __frame.prev;
} else {
    __cfront_eh_top = __frame.prev;
    if (__frame.exception_type == TYPE_TAG_T) {
        T *e_ptr = (T*)__frame.exception; /* H uses (*e_ptr) */
    } else { longjmp(__cfront_eh_top->env, 1); } /* rethrow */
}
```

### Namespace stripping (ns_strip)

A separate preprocessor pass (`tools/ns_strip` or built from `src/ns_strip.c`)
strips `namespace foo { ... }` blocks and `using namespace foo;` directives
before cfront sees the source. The two-stage pipeline becomes:

```
ns_strip foo.cpp | cfront | cc -x c -
```

### C++ headers (h/)

All headers in `h/` are fully inline (header-only) to avoid cfront's template
instantiation repository complexity. The `#pragma lib "ape/libc++.a"` in each
header causes Plan 9's pcc to auto-link the runtime library.

`string::npos` is the one out-of-line definition, living in `lib/string/string.cpp`.

---

## Next Steps (priority order)

1. **Template reliability improvements** — partial specialisation and dependent
   name resolution are the main gaps. Many STL-style programs that don't use
   these features already work. Filling these gaps would allow more real-world
   C++ code to compile.

2. **`<complex>` header** — add `h/complex.h` wrapping the existing `lib/complex/`
   implementation with a proper `template <class T> class complex` interface.

3. **`auto` type deduction** — cfront does not support C++11 `auto`. This is
   also a pending item in the APExp C compiler (`apexp_compiler_improvements.md`).
   Both improvements are linked: once the Plan 9 pcc can deduce types for `auto`
   declarations in generated C, cfront can be taught to emit `auto`-carrying
   constructs. See APExp compiler work for status.

4. **`mutable` and `explicit`** — silently ignore `mutable` (add to the
   attribute-swallow list in `lex.c`); for `explicit`, add a token that is
   accepted by the grammar and dropped.

5. **Better diagnostics** — cfront's error messages are very terse. Improving
   the `error()` calls in `dcl.c`, `typ.c`, and `expr.c` to include more
   context would help users debug template and overload errors.

6. **Integration testing** — the bootstrap test (34/34 cfront source files
   translate identically) verifies correctness. Adding a suite of real-world
   C++ programs (Boost.Filesystem, a JSON parser, etc.) would catch regressions
   from future changes.

7. **RTTI** (`dynamic_cast`, `typeid`) — substantial effort; requires a type
   descriptor table and runtime library support. Low priority unless a specific
   program needs it.

### APExp C compiler / cfront overlap

Several improvements benefit both the Plan 9 C compiler and cfront-C4:

| Item | APExp compiler status | cfront status |
|------|-----------------------|---------------|
| `bool`/`true`/`false` as keywords | Done (C23) | Done (template.h guarded with `-D__cfront_have_bool`) |
| `auto` type deduction | Not implemented | Not implemented |
| `typeof_unqual` | Done | N/A (cfront emits C) |
| `__VA_OPT__` | Done | N/A |
| Wide character support | Available (`wchar_t` via Rune mapping, libap) | Usable — cfront-compiled code can call wchar functions |

---

## Bootstrap Verification

The canonical correctness test: translate all 34 of cfront's own `.cpp` source
files using both the g++-built reference binary and this C binary, then compare
output (normalising address-derived temp names).

**Current result: 34/34 pass.**

The only differences are internal temp variable names like
`__0__X__V1400qrh3lctewcnm` vs `__0__X__V1400qmlnnfrtvcnm` — these encode
memory addresses and differ between builds but are semantically identical.
