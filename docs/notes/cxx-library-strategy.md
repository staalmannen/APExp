# APExp C++ library: feature gaps and implementation strategy

This note reviews the initial Paragon Portable STL (PSTL) integration in
`sys/include/ape/c++`, identifies the next useful features, and separates
C++ library work from changes that may be needed in APExp's C library
(`libap`). The inventory is a source-tree review, not a claim that every
installed header currently compiles with EDC.

## Recommendation

Keep PSTL as the working foundation. Do not replace it wholesale with
LLVM libc++, and do not generate major library components from prompts.
Use a selective upstream port as the main way to add substantial
facilities: prefer implementation code whose dependencies fit EDC and
APExp, retain its license and provenance, and integrate it behind APExp's
public headers. Use libc++ as a specification-quality reference and
potential source for isolated components after dependency and compiler
checks. Use generated code only for small, well-bounded work such as
forwarding headers, simple traits, or a single algorithm, with review and
tests against a known implementation or conformance cases.

This hybrid keeps the usable PSTL base, avoids importing libc++'s full
configuration and ABI assumptions, and avoids making generated code the
unreviewed source of truth. LLVM's vendor documentation describes a
runtime build involving libc++, libc++abi, and libunwind, and its platform
documentation lists compiler and platform combinations it tests. APExp's
EDC and Plan 9 APE target are outside that supported matrix, so a full
libc++ drop-in would be a porting project, not a header copy. See
[libc++ vendor documentation](https://libcxx.llvm.org/VendorDocumentation.html)
and [libc++ platform support](https://libcxx.llvm.org/).

## Current public surface and gaps

The top-level EDC entrypoints currently cover algorithms, array, compare,
concepts, size/integer types, functional, iterator, limits, memory, ranges,
set, strings/string_view, tuple, type traits, utility, variant, and vector,
alongside EDG language support. The subdirectories also contain
implementation headers for `list`, `forward_list`, and `map`, but there
are no corresponding `list.stdh`, `forward_list.stdh`, or `map.stdh`
entrypoints. PSTL has an `expected` implementation under
`utility/expected`, but no public `expected.stdh`.

The major absent components include:

| Priority | Standard facilities missing or incomplete | Notes |
| --- | --- | --- |
| P0: expose and stabilize | `<list>`, `<forward_list>`, `<map>`, `<expected>`; public exception types; standard signatures for current containers | Some implementation code already exists. `expected` is currently also used internally as PSTL's error channel. The public exception headers remain EDG language-support stubs or PSTL-specific templated types. |
| P1: common application code | `<optional>`, `<deque>`, `<queue>`, `<stack>`, `<unordered_map>`, `<unordered_set>`, `<numeric>`, `<bit>`, `<bitset>`, `<charconv>`, `<span>`, `<chrono>`, `<random>`, and the `<c...>` wrappers for APExp C headers | `std::chrono` can build on the existing time API. Several utilities are largely header-only. C++ wrappers such as `<cstdio>` and `<cstdlib>` are absent even where `<stdio.h>` and `<stdlib.h>` exist. |
| P2: hosted facilities | `<iostream>` and stream headers, `<filesystem>`, `<locale>`, `<regex>`, `<format>`/`<print>`, `<valarray>`, and broader wide-character support | These need a clear contract for Plan 9 paths, locale behavior, file errors, formatting, and character encodings. |
| P3: concurrency and newer standards | `<atomic>`, `<thread>`, `<mutex>`, `<condition_variable>`, `<future>`, `<barrier>`, `<latch>`, `<stop_token>`, `<execution>`, and newer C++23/26 headers | This depends on which C++ language modes and compiler operations EDC can reliably lower, plus the precise guarantees of APE's thread and atomic layers. |

This is a practical project backlog rather than an exhaustive list of
every current C++ standard header. The live C++ draft lists the full
header surface and defines the distinction between hosted and
freestanding implementations. APExp should document its selected
language/library baseline and supported subset explicitly rather than
implying full hosted conformance. See the [C++ library header
list](https://eel.is/c++draft/headers) and [freestanding
requirements](https://eel.is/c++draft/tab:headers.cpp.fs).

## Implementation strategy

### 1. Close the cheap surface gaps first

Before importing another large codebase, add public entrypoints for
already-present `list`, `forward_list`, and `map` code, and inspect the
`expected` implementation for its public standard header. Treat each
entrypoint as a claim that the header is usable: compile a minimal
translation unit and a small behavior case under EDC before marking it
supported. The existing PSTL `vector`, `string`, and associative
container interfaces need a conformance pass, particularly where
fallible operations return `expected` instead of following standard
signatures.

Then add inexpensive, high-demand facilities in dependency order:
`optional`, `span`, `bit`, `numeric`, `charconv`, and the C++ wrappers
around existing C headers. Pure templates and constexpr utilities should
not require new `libap` functions unless a concrete dependency shows
otherwise.

### 2. Import components, not entire libraries

For each missing component, make a short dependency and compatibility
record before choosing an upstream source. Prefer self-contained
components; port one component at a time; adapt compiler intrinsics,
configuration, and ABI hooks at a narrow boundary; retain upstream
copyright/license notices; and keep a local patch record with the source
revision. Add tests with the component rather than importing its entire
build system.

LLVM libc++ is valuable as a reference and as a possible source for
individual components, but its internal headers depend on libc++
configuration macros, compiler feature detection, and its ABI/runtime
model. The project itself describes a modified/reshaped integration for
its Parallel STL rather than treating upstream PSTL as a direct
drop-in. That is a useful precedent for selective adaptation, not
evidence that all libc++ headers can be copied unchanged. See the
[libc++ PSTL integration design](https://libcxx.llvm.org/DesignDocs/PSTLIntegration.html)
and [vendor build/ABI options](https://libcxx.llvm.org/VendorDocumentation.html).

### 3. Keep generated code small and testable

Generated implementation code can accelerate routine work, but a
prompt-generated container, locale facet system, stream library, or
filesystem layer is too large to trust without extensive review and
conformance testing. Generated code is suitable for repetitive forwarding
headers, small independent algorithms, or mechanical adaptation of a
known source. Every generated component should cite the standard/source
it follows and have tests that catch edge cases, exception/error
behavior, iterator invalidation, and overload/signature mistakes.

### 4. Define feature states and the support baseline

Maintain a table per public header with `absent`, `entrypoint only`,
`partial`, or `supported` status, the selected C++ language mode, known
deviations, and a compile/use fixture. Avoid advertising a feature-test
macro until the implementation and its required behavior are present.
Choose one practical initial target (for example, a carefully scoped
C++17 hosted subset) and add newer components only when EDC supports the
required language constructs. PSTL currently mixes facilities from
different standard generations, so header presence alone cannot define
the target version.

## `libap` assessment

Most missing C++ facilities are library-layer work and do not by
themselves justify changes to `libap`. The tree already has substantial
C support under `sys/src/ape/lib/ap`, including allocation, stdio,
stdlib, string, math, time, locale, filesystem-adjacent POSIX interfaces,
and a pthread implementation. Add or change a C library interface only
when a C++ component has a specific unmet primitive, and first check
whether the required behavior is already available through APE headers
or Plan 9 APIs.

| C++ facility | Likely `libap` relationship | Assessment |
| --- | --- | --- |
| Containers, algorithms, `optional`, `span`, `variant`, `tuple`, ranges | Allocation and memory primitives | Existing `malloc`/`free` and C memory functions should cover the initial work. No broad libc expansion is indicated. |
| `<chrono>` | `clock_gettime`, `time`, `nanosleep` | These facilities exist under `libap/time`; verify clock IDs, resolution, and error behavior against `std::chrono` requirements before extending libc. |
| `<iostream>` / `<print>` | stdio and file descriptors | `libap/stdio` exists. A C++ stream layer can initially adapt `FILE`/fd operations; add libc support only for a demonstrated gap such as synchronization or a required conversion primitive. |
| `<filesystem>` | `open`, `stat`, directory iteration, mkdir/unlink/rename, path encoding | APE has POSIX-like headers and Plan 9-backed implementations, but filesystem semantics are the largest platform mapping risk. Audit operations individually; do not add Linux syscall emulation wholesale. |
| `<locale>` / wide strings | locale, multibyte, ctype | `libap/locale` exists, but `locale_stubs.c` documents a single UTF-8 locale and no real locale switching/database. A C++ locale layer can start with a documented C/C.UTF-8 subset; full locale support would need data and behavior beyond header shims. |
| `<thread>`, mutexes, condition variables, futures | pthread and Plan 9 synchronization | `libap/thread` contains pthread create/join, mutex, condition, and related code. Audit guarantees, cancellation, timing, and thread-local behavior before claiming standard semantics. Do not add a second scheduler in the C++ library. |
| `<atomic>` | compiler atomics or lock-based support | `sys/include/ape/atomic.h` provides a limited lock-backed APE atomic API. It is not itself a complete C++ atomic implementation. First determine what atomic operations/orderings EDC can lower; only then add missing compiler/runtime primitives to `libap` or a dedicated runtime. |
| `<random>` / `random_device` | PRNG and entropy source | `libap/prng` exists, but deterministic PRNG support is not automatically a nondeterministic entropy source. Decide whether `random_device` can read a Plan 9 entropy device; otherwise document its limitation. |
| `<regex>`, `<charconv>`, numeric utilities | mostly algorithms and conversion code | These are primarily C++ implementation work. Reuse existing `strtod`, `snprintf`, math, and string functionality where semantics match; extend `libap` only for an uncovered primitive or correctness issue. |

The C library already has directories for many of these dependencies, but
directory presence does not establish complete behavior. For example,
`locale_stubs.c` explicitly describes a single UTF-8 locale, and the APE
atomic interface is a narrow lock-backed API. The correct policy is
feature-driven libc work: add a regression case showing which C-level
contract is missing, implement that contract in the existing subsystem,
and keep C++-specific ABI symbols out of `libap` when they belong in
`libedg` or a future C++ runtime.

## Runtime issues to resolve before broad hosted coverage

Some blockers sit below both the C++ headers and `libap`:

* The EDG runtime archive and its notes record that translated
  translation-unit static constructors are not currently invoked by the
  startup path. This blocks reliable use of namespace-scope objects and
  standard stream globals until startup integration is fixed.
* EDC's exception runtime is setjmp/longjmp based. Standard exception
  behavior and libraries built around a different unwinding ABI must be
  validated against `libedg`, not assumed from their headers.
* RTTI, allocation, thread-local initialization, and process finalization
  must each have a documented and exercised contract before importing
  facilities that depend on them.

These issues favor a staged library implementation around EDC's existing
runtime. They do not imply that libc++ is unusable as a source, but they
make a wholesale libc++/libc++abi/libunwind port a much larger project
than adding missing header components.

## Suggested order of work

1. Establish EDC compile/use fixtures and a per-header support table.
2. Expose and validate already-present containers and `expected`; fix
   standard-signature deviations in the common containers.
3. Add `optional`, `span`, `bit`, `numeric`, `charconv`, and C++ C-header
   wrappers from small audited components.
4. Resolve static initialization and verify exception, RTTI, `new`/`delete`,
   and finalization behavior in the EDC runtime.
5. Add chrono and stream facilities using existing `libap` time/stdio,
   then filesystem with a Plan 9 semantics map.
6. Add atomics and threading only after measuring the EDC lowering and
   `libap/thread` contracts; implement locale/random-device limits
   explicitly.
7. Import larger components from libc++ or another source selectively,
   with dependency maps, licenses, conformance cases, and APExp patches.

## Sources

* [C++ draft: library headers](https://eel.is/c++draft/headers)
* [C++ draft: freestanding header minimum](https://eel.is/c++draft/tab:headers.cpp.fs)
* [C++ draft: hosted and freestanding implementations](https://eel.is/c++draft/intro)
* [LLVM libc++ documentation and platform support](https://libcxx.llvm.org/)
* [LLVM libc++ vendor documentation](https://libcxx.llvm.org/VendorDocumentation.html)
* [LLVM libc++ PSTL integration design](https://libcxx.llvm.org/DesignDocs/PSTLIntegration.html)

Repository evidence reviewed: `sys/include/ape/c++` public entrypoints;
`sys/src/ape/lib/ap/mkfile` and its `thread`, `locale`, `stdio`, `malloc`,
and `time` implementations; `sys/include/ape/atomic.h`;
`sys/src/ape/lib/edg/mkfile`; and `sys/src/ape/lib/edg/cxa_atexit.c`.
