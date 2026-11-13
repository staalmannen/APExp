# APExp C++ standard library: initial PSTL integration

EDC can translate C++ to C, and its language-support headers and ABI
runtime are installed. This work establishes the first general-purpose
header library by merging Paragon Portable STL into
`sys/include/ape/c++` and exposing public headers through EDG's `.stdh`
include suffix. Implementation headers keep their component layout and
relative includes. The imported `portable_stl` namespace has been
renamed to `std`; no namespace alias is used.

This is a starting point for a standard library, not a conformance claim.
Paragon PSTL is an exception-free, expected-based implementation. Many
fallible operations, including `vector::push_back`, return
`std::expected<..., std::portable_stl_error>` where the standard library
API returns `void` (or a reference for `emplace_back`). Code depending on
standard exception behavior, exact signatures, or broad header coverage
will need additional work. Existing EDC language support headers own
special declarations such as `std::initializer_list` and `std::type_info`;
PSTL internal support headers now include EDG's `<exception>`, `<new>`,
`<initializer_list>`, and `<typeinfo>` declarations; PSTL-only helper
exceptions remain implementation details.

For the current feature inventory, libc++ versus generated-code assessment,
and `libap` dependency review, see
[`docs/notes/cxx-library-strategy.md`](cxx-library-strategy.md).

## Follow-up roadmap

1. **Validate the public headers with EDC.** Compile minimal translation
   units for every public `.stdh` entrypoint, record unsupported EDG
   language features, and catch conflicts with the existing `.stdh`
   language-support headers. Add small APExp-specific compile fixtures.
2. **Integrate allocation and runtime behavior.** Connect allocation,
   deallocation, exceptions or the chosen error model, atomics, threading,
   locale, time, and C library facilities to APExp's APE environment.
   Document which facilities intentionally remain unavailable.
3. **Improve API conformance.** Replace expected-returning signatures where
   required, implement standard exception behavior and overload sets, and
   compare public declarations against the selected C++ standard version.
   Keep implementation-specific fallible helpers internal where possible.
4. **Expand the standard surface.** Prioritize core utilities and containers,
   then algorithms, strings, iterators, numerics, I/O, filesystem, and
   concurrency according to port demand. Track each header as absent,
   partial, or supported, with a compile/use example.
5. **Import additional implementations selectively.** Evaluate sources such
   as LLVM libc++ for missing facilities after checking license, target
   assumptions, compiler support, ABI compatibility, and overlap with PSTL.
   Integrate in small components and retain provenance and local patch notes.
6. **Maintain upstream and APExp changes.** Record the imported PSTL
   revision/license and local modifications, keep an update procedure, and
   avoid losing APExp compatibility fixes during future imports.

## Initial coverage

The current public entrypoints include algorithms, array, compare,
concepts, fixed-width and size types, functional, iterator, limits, memory,
ranges, set, strings/string_view, tuple, type traits, utility, variant,
vector, and recently exposed list, forward_list, map, expected, and C++ C
header wrappers. Entry points are a practical starting subset; the imported
implementation's header inventory is not evidence that every facility
builds or conforms under EDC. The current gap inventory and strategy are
in [`cxx-library-strategy.md`](cxx-library-strategy.md).

## The first run that said anything: 16 errors, and what they were

**cpfe stopped crashing** -- the `struct stat` fix in
`docs/notes/edg.md` -- and `sys/lib/tests/cxx-bisect` answered
**19 ok, 16 error, 0 CRASH** instead of one jump to address 1. Every
one of the 16 was real and every one is fixed. *The crash had been
hiding the library, not the other way round.*

### The instrument came first, and it cost one hour instead of one round

**`sys/lib/tests/hostkencc/cxxlib-host.sh` compiles this library with
g++ on the build host**, and the reason it can is the rename: with
the implementation namespace changed to `std` this is a REPLACEMENT
standard library, so `g++ -nostdinc++` pointed at it puts it in
exactly the position cpfe does. Nothing here needs Plan 9 -- it is
header-only C++14 over the C library, and glibc serves the C half.

The only adaptation is the **file names**: cpfe finds `<algorithm>`
as `algorithm.stdh` through its own `include_file_suffixes`, and the
plain name is taken by a DIRECTORY. The script stages a shim of
extensionless forwarders and puts it first. It also supplies the four
**predefined macros cpfe has and gcc does not** --
`__EDG_RUNTIME_USES_NAMESPACES` above all, without which
`class exception` lands in the GLOBAL namespace and every
`: public ::std::exception` answers `expected class-name`.

***`--portable` IS NOT OPTIONAL AND `--headers` IS NOT EITHER***, and
each was proved by a run that hid failures:

  * A plain run takes the **gcc arms** of the four compiler-identity
    selectors, because g++ defines `__GNUC__`. `--portable` defines
    `PSTL_NO_COMPILER_BUILTINS` and forces the arms cpfe takes.
  * A combined translation unit stops at the error limit.
    `--headers` compiles each public header alone. **Combining the
    two flags turned up ten failures the gcc-arm run had not shown**,
    which is why the argument parser reads every word and not `$1`:
    the first version silently ran `--portable` and dropped
    `--headers`.

**It is sound for everything that is not cpfe itself** -- a missing
type, a name that does not exist, a using-declaration that collides,
a stray keyword. It says nothing about cpfe's C output, its template
model or the ABI: g++ is a second front end over one source, so a
disagreement is a finding and an agreement is not a proof.

### The one shape that accounted for eleven of the sixteen

**Four files chose an implementation by COMPILER IDENTITY where the
question is CAPABILITY.** Each was
`#if defined(_MSC_VER)` ... `#else /* clang and gcc */`, a two-way
split that answers CLANG-AND-GCC for every compiler that is not
Microsoft's. cpfe is a third thing -- it defines neither `_MSC_VER`
nor `__GNUC__` -- so it took the gcc arm and reached
`__integer_pack`, `__builtin_is_constant_evaluated` and
`__LONG_LONG_MAX__`, none of which it has outside g++ emulation mode.

`common/compiler_builtins.h` asks the question directly now
(`__has_builtin` plus a version test), and a compiler that answers
neither gets a portable path instead of a guess. The four are
`make_index_sequence.h`, `is_constant_evaluated.h`,
`common/numeric_limits.h` and `algorithm/ctz.h`.

***TWO OF THE FOUR HAD NO PORTABLE ARM TO SELECT***, which is the
half that was work rather than editing:

  * **`make_integer_sequence`**: upstream has `__make_integer_seq`
    (clang, MSVC) and `__integer_pack` (gcc 8+) and nothing else.
    `make_integer_seq_generic.h` is new and is the standard DOUBLING
    recursion -- logarithmic, because the naive one-at-a-time version
    is why the builtins exist and would be swapped out again by
    whoever next compiles a large `tuple`. **Its obvious shape is
    ill-formed**: a partial specialisation may not have a non-type
    argument whose TYPE depends on a parameter of that same
    specialisation, so the count is fixed at `size_t` -- making the
    two base cases FULL specialisations -- and cast to `t_type` once
    at the end.
  * **`limits_msvc/`** turned out to BE the portable arm and only its
    directory name said otherwise: it reads `<limits.h>` and
    `<float.h>` where `limits_clang_gcc/` reads `__SCHAR_MAX__`. It
    included neither header, because under `_MSC_VER` they had always
    arrived by another route -- and `WCHAR_MAX` is in `<stdint.h>`
    rather than `<limits.h>`, which is the one that then failed in
    nine headers at once.

### The rest, one line each

  * **`std::std_error` did not exist.** The namespace rename rewrote
    every USE -- `::portable_stl::portable_stl_error` became
    `::std::std_error` -- and left the one DEFINITION alone. 21 users,
    1 definition. Renamed, with an alias for upstream's spelling.
  * **`using max_align_t = ;`** -- an alias to nothing, so `<cstddef>`
    and `<cwchar>` could not be read at all. Upstream leaves it for
    the platform; nothing filled it in.
  * **`<cstdint>` declared `imaxdiv_t`**, which is `<cinttypes>`'s,
    and did NOT declare `int16_t`/`int32_t`/`int64_t` or their
    unsigned forms. *The missing half is the larger one*:
    `::std::int32_t`, which this library uses throughout, resolved
    only because `common/int32_t.h` defines its own.
  * **Five names were re-exported from `::` into `std` that this
    library DEFINES in `std` itself** -- `memcpy`, `memmove`,
    `memcmp`, `memset`, `wmemcmp`. Which declaration arrives first is
    a property of INCLUDE ORDER, so `<cstring>` alone compiled and
    `<cstring>` after anything reaching `memory/` did not. cpfe named
    two before its hundred-error limit; a sweep named all five.
  * **`std::unexpected`**: EDG's `<exception>` declares the C++98
    handler FUNCTION, removed in C++17, and C++23 gave the name to
    the class template that is the error half of `std::expected`. A
    function and a class template of one name in one namespace is
    `redeclared as different kind of entity`, and every header
    reaching `<expected>` reaches both. The removed one is gone.
  * **`functional/no_rtti/typeid_wrap.h` called `typeid`** -- the
    no-RTTI arm, whose own comment says RTTI is disabled. `target` is
    a PURE VIRTUAL, so it is instantiated for every `std::function`
    that exists; `<functional>` could not compile without RTTI, which
    is `eccp`'s default. `std::type_info` cannot be manufactured
    (no accessible constructor, by design), so the arm cannot return
    one -- and does not need to: the value is only ever compared.
    Both arms carry a `typeid_token` now.
  * **`split_buffer.h`**: two out-of-class definitions spelled a
    SFINAE parameter `typename split_buffer<...>::value_type` where
    the declaration says `value_type`. A dependent type the compiler
    cannot reduce while it is still looking for the declaration to
    match, so both answered `no declaration matches` and `<vector>`
    did not compile. *The host found this one; cpfe never got to it.*
  * **`incrementable_traits.h` used a bare `ptrdiff_t`** and included
    nothing that declares one. A name that depends on include order
    is not declared, it is lucky.
  * **`move_algo.h` had a stray `template` disambiguator** before a
    call with deduced arguments. [temp.names]/5 wants a template-id
    there; **cpfe is right and g++ lets it pass**, which is the only
    one of the sixteen that went the other way.
  * **`<signal.h>` and `__restrict`** -- not this library's, and in
    `docs/notes/invariants.md`'s territory. kencc lexes `__restrict`;
    EDG's default C++ mode does not enter it as a keyword at all
    (`fe_init.c:54193` gates it on `gnu_restrict_keyword_enabled`), so
    the prototypes read as two parameters named `__restrict`.
    `features.h` already answers it and three of the four headers
    using that spelling already included it; `<signal.h>` was the one
    that did not.

### Where it stands

**All 50 public headers compile on both arms** except `<compare>` and
`<source_location>`, which `#error` because they are C++20 and `eccp`
passes `--c++14`. `cxx-library-test.cpp` builds and RUNS clean on the
host with `--portable`, 0 failures.

***`std::variant` IS A NAME AND NOT AN IMPLEMENTATION.*** The list
above under *Initial coverage* includes it, and the class is
`template<class...> class variant final { public: };` -- no
constructor, no `get`, no members. An empty-body sweep over the whole
library finds 53 such classes and 52 are legitimate (tag types,
primary templates specialised elsewhere); `variant` is the only one
that is a public header's own principal type. The test prints a
`GAP` line for it rather than asserting, because the assertion that
was there could not COMPILE and took every check after it down.

**The generic `make_integer_sequence` is checked for CONTENT and not
only for length**, and the control is why: with the doubling
recursion's SHIFT deleted, `index_sequence size` still PASSES and
only the sum checks fail. 5 and 9 are used because they are not
powers of two, so both split unevenly.
***The control's first attempt proved nothing***: the shim forwards
to ABSOLUTE paths, so staging a broken copy and pointing `-I` at it
compiled the real library and reported PASS. To break something on
purpose here, edit the file in the repository and put it back.
