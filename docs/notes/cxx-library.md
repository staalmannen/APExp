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
