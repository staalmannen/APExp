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

## Second run: 27 ok, 7 error, 1 CRASH -- and the seven were one thing

The sixteen became seven, and **all seven were the same cause**, which
the first round had met and only half fixed.

### The selectors were half the class

Round one found four files choosing by COMPILER IDENTITY and treated
that as the whole of it. The other half is a builtin used with **no
test of any kind** -- no `__has_builtin`, no `#if`, no portable
sibling. Two files:

  * **`common/numeric_limits.h`, nine sites**:
    `__builtin_huge_valf`/`_val`, `__builtin_nanf`/`_nan`,
    `__builtin_nansf`/`_nans`. They sit in the SHARED file, outside
    both `limits_msvc/` and `limits_clang_gcc/`, so neither selector
    could ever reach them. This is why `<forward_list>`,
    `<functional>`, `<list>`, `<map>`, `<memory>`, `<string>`,
    `<string_view>` and `<vector>` all stopped at one line.
  * **`memory/addressof.h`**: `__builtin_addressof`, with no sibling
    implementation anywhere.

***AND `cxxlib-host.sh --portable` COULD NOT HAVE CAUGHT THEM.***
`PSTL_NO_COMPILER_BUILTINS` forces the SELECTORS; a bare `__builtin_x`
answers to no macro at all, and g++ has the builtin, so the portable
run compiled it and reported clean. *A flag that forces the arms you
know about says nothing about code that has no arms.* The instrument
for that is text, not compilation: `sys/lib/tests/cxxbuiltin-sweep.py`,
which **gates** -- unlike `baketype-sweep` there is no
arms-nobody-takes problem, since a bare builtin is a hard error on any
compiler lacking it.

**The sweep's own two faults, both caught by its control:**

  * Its first run reported **its own explanatory prose** -- three hits
    were comments naming the builtin they had just guarded away. It
    blanks comments and string literals first now, which is the
    lesson `truefalse-sweep` already paid for.
  * Its sibling rule hardcoded `builtin/` against `generic/`, and so
    reported two files that are perfectly guarded: upstream uses the
    same indirection under `gcc_clang/`/`msvc/` and
    `buildin_realization/`/`no_realization` as well. *A rule written
    from the examples in front of you fires on the next naming
    convention.* It asks structurally now -- does a header in the
    grandparent include this basename from two or more sister
    directories.

`source_location.stdh` is the one EXEMPT entry, with its reason in the
file: `__builtin_FILE`/`LINE`/`FUNCTION`/`COLUMN` are not a shortcut
there, they are the only possible implementation, and the header
already `#error`s below C++20.

### A second hole, in the switch itself

The new guards were first written
`PSTL_HAS_BUILTIN(x) || defined(__GNUC__)` -- and **that bare clause
is true on the build host whatever `PSTL_NO_COMPILER_BUILTINS` says**,
so `--portable` would have gone on compiling the builtin arm and
reporting it clean. *A switch the thing it switches can ignore is not
a switch.* `PSTL_HAS_GNU_BUILTINS` exists for that, and every such
clause spells it that way.

**It was caught by measuring the switch rather than trusting it**:
`g++ -E` with and without the flag, counting surviving builtin uses,
answered 2 then 1. The residual 1 is glibc's own `<math.h>` defining
`HUGE_VAL` *as* `__builtin_huge_val()`, which is the portable arm
working.

### `constexpr`: the same rule, opposite answers

APExp's `<math.h>` spells `HUGE_VAL` as `Inf(1)` and `NAN` as `NaN()`
-- CALLS. A `constexpr` function returning one can never be evaluated
as a constant, which [dcl.constexpr]/5 makes ill-formed **no
diagnostic required**. g++ accepts it with `-Winvalid-constexpr`;
*probably* is the word to avoid when checking costs a VM rebuild.

  * **`numeric_limits.h` drops the keyword** on the portable arm, via
    `PSTL_FP_CONSTEXPR`, because a grep finds **0 callers of
    `infinity()`, `quiet_NaN()` or `signaling_NaN()` outside that
    file** -- nothing cascades. The conformance loss is real and is
    recorded here: `constexpr double d = numeric_limits<double>::
    infinity();` is a diagnostic on this platform and not on gcc, and
    there is no portable signalling NaN, so `signaling_NaN()` returns
    the quiet one.
  * **`addressof.h` keeps it.** The three-cast idiom is equally
    non-constant, but `addressof` IS called from `constexpr` code
    throughout `functional/` and the iterators, so removing the
    keyword would make every one of those callers ill-formed in turn.
    Ill-formed NDR is the cheaper of the two.

*Same rule, opposite answers, because the callers differ* -- which is
the thing to carry away rather than either verdict.

### What is NOT fixed: the `vector` CRASH

`cpfe 32385: suicide: sys: trap: fault read addr=0x3f4cd pc=0x90c3a1`.
**`pc` is a real code address**, so unlike the `struct stat` crash this
is a genuine dereference inside cpfe and not a smashed return.

**The prediction, written down before the run that will test it: it
goes away.** In both places it was seen, cpfe had already EMITTED a
diagnostic and then died -- in `cxx-bisect` after
`numeric_limits.h:881`, and in `cxx-library-test` after
`addressof.h:26` under about twelve levels of
`detected during instantiation`. Seven other headers hit the identical
error and did NOT crash, so it is the DEPTH of the recovery and not
the error itself. With nothing erroring, nothing reaches that path.

**The refutation condition: a CRASH with 0 errors.** If `cxx-bisect`
reports one, this is a cpfe bug on deep instantiation and a different
investigation -- and the host cannot help with it, since g++ compiles
the same `<vector>` on both arms.

***AND THAT IS EXACTLY WHAT THE NEXT RUN SAID: `34 ok, 0 error,
1 CRASH`.*** The prediction is refuted and the error-recovery reading
is dead. Every header compiles, `<vector>` alone crashes cpfe at
`fault read addr=0x3f4a9 pc=0x9d98a6`, and the seven errors were
HIDING this rather than causing it. *The seven other headers that hit
the identical error and did not crash were the evidence for the wrong
conclusion*: they showed the error was not sufficient, and were read
as showing recovery depth was.

**What the two sightings do say, and it is not nothing**: `addr` is
`0x3f4cd` and then `0x3f4a9` -- thirty-six apart, across two
different cpfe binaries and two different inputs -- while `pc` moved
by nearly a megabyte. *An address that stable under that much change
is computed from the input, not from a corrupted pointer*, and
~0x3f4xx is far too small to be a heap address and too large for a
tag. The shape that fits is a base of zero plus a real offset:
something indexing off a null table.

**The host-built cpfe is NOT the tool for this**, and nearly became
one: `edgbaked-xcheck`'s recorded verdict is that it is sound for
compile-time questions and VOID at run time, because its `long` is 8
bytes where kencc's is 4 -- so every struct layout, every folded
`sizeof` and every offset differs. *A crash is a run-time question.*
Half an hour had gone into a `struct stat` shim for it before that
sentence was re-read.

**`sys/lib/tests/cxx-vecnarrow` is the instrument instead**, and it
needs no debugger. `<vector>`'s include closure is 356 files; the 34
headers that pass between them reach 337 of those, so the finding is
already narrow and still unreadable. The ladder has three phases and
**phase 0 is a control** -- `<vector>` must crash under the ladder
itself, or every clean rung below is clean for the wrong reason.
Phase 1 compiles each of `vector/vector.h`'s 56 includes alone;
phase 2 compiles cumulative prefixes and stops at the first that
crashes, which names the second party to an interaction. **If both
are clean that is itself the answer**: the fault is in
`vector/vector.h`'s own body, below its last `#include`, which is
about 2000 lines rather than 356 files. The include list is DERIVED
from the file at run time and the script gates if the derivation
comes back empty, because a transcribed list goes stale silently and
a ladder with no rungs still prints.

### And the bisect was printing half its own evidence

`cxx-bisect` used `sed 1q` on cpfe's stderr. **A cpfe diagnostic is
wrapped**: line 1 is the file and line number ending in a bare
`error:`, line 2 is the message. So a run reported
`numeric_limits.h", line 881:` eight times and never said what was
wrong, and a round went on reading the file to guess while
`__builtin_huge_valf is undefined` sat on the next line. `sed 3q` now.
*A summary that cuts the sentence in half is worse than no summary.*

## The ladder answered: it is `vector/vector.h` itself, and cpfe is PARSING

`cxx-vecnarrow` reports:

```
control  <vector> -> CRASH
phase 1 -- each include ALONE          no single include crashes
phase 2 -- CUMULATIVE prefixes         no prefix of the 56 crashes
***THE CRASH IS IN vector/vector.h ITSELF***
```

Three errors in phase 1 are correctly classified as `needs a
prerequisite; not a crash` -- `construct_at_noexcept.h`,
`make_exception_guard.h` and `split_buffer.h` are not standalone
headers, which is why the three-way ok/ERROR/CRASH split exists rather
than a pass/fail.

***THE SECOND FINDING IS IN THE SHAPE OF THE QUESTION AND IS BIGGER
THAN THE FIRST.*** The translation unit is `#include <vector>` and
`int main(){return 0;}` -- **nothing instantiates `vector<T>`**. So
cpfe dies PARSING, not instantiating. That rules out template argument
deduction, instantiation, the `--instantiate local` machinery and the
whole back end in one line, and leaves declaration parsing and the
semantic analysis of declarations. *It also finally kills the
error-recovery reading, which had already been refuted once*: there is
no error and nothing to recover from.

### `cxx-vecsplit` bisects the 2581 lines that remain

The file is one class template (88-1297) and 108 out-of-class
definitions. `cxx-vecsplit.cuts` holds the line numbers at which it can
be truncated and still compile; `cxx-vecsplit` bisects them, so a run
costs about **seven cpfe invocations rather than 81**.

**The bisect is sound only because the two ends are measured rather
than assumed**: rung A requires the shortest prefix NOT to crash --
which also cross-checks `cxx-vecnarrow`'s phase 2 from the other side
-- and rung B requires the whole `<vector>` to crash. If either is
wrong the run is REFUSED instead of answered.

***THE CUT LIST IS GENERATED AND VALIDATED ON THE HOST, and that is the
part worth copying.*** `cxxlib-host.sh --vecsplit` produces it. The
obvious rule -- a `template<` at column 0 at brace depth 1 -- gives
**108 candidates of which 27 DO NOT COMPILE**: a member template is
`template<class t_type, class t_allocator>` on one line and
`template<class ...>` on the next, and a cut between the two leaves a
dangling template header. *The fix is not to teach the rule about that
case.* The list is the set **g++ proved compiles**, so a rung that
ERRORS on the VM means cpfe disagrees with g++ -- a finding -- rather
than the harness cutting in the wrong place, which is noise. **An
instrument whose failures have two explanations cannot be read.**

**And the first validation run caught the generator rather than the
library**: all 108 prefixes failed at the same line, because
`vector.h`'s own includes are QUOTED and relative to its directory
while the generated file lives in `/tmp`. One `-I` fixed it. *A
validation pass that reports 108 of 108 is reporting on itself.*

The script carries a **staleness guard**: a cut point is a LINE NUMBER
and rots silently the moment anybody edits the file above it -- a wrong
cut still produces a file and cpfe still answers something. Every cut
must still land on a `template<` at column 0, or the run is refused
with "regenerate".

Two rc faults were caught before it shipped, both from this tree's own
list: `while()` with an empty condition is not rc (the span is computed
before the loop and again at the end of the body), and the nested
backquote for the script's own directory was replaced with a plain
`dirname $0`.

## `cxx-vecsplit` refused, and the refusal convicted `cxx-vecnarrow`

```
cxx-vecsplit: 81 cut points, validated on the host
cxx-vecsplit: rung A  shortest prefix (includes only) -> CRASH
cxx-vecsplit: REFUSED -- the shortest prefix already crashes,
cxx-vecsplit: which contradicts cxx-vecnarrow phase 2
```

**The guard did its job and the contradiction was real.** Two
harnesses disagreed about the same question, and the one that was
wrong is the one that had already given an answer.

### `cxx-vecnarrow` was wrong in two independent ways

**1. Its phase 2 tested `~ $k CRASH` and nothing else.** A prefix that
ERRORED counted as clean. cpfe stops at the first error, so such a
prefix never reaches the code that crashes — *"no prefix of the 56
includes crashes" had two explanations and only one was reported.*
This tree's own rule, in the harness rather than in the library: **a
check whose negative result has two explanations is not a check.**

**2. It derived the include list with `#include` anchored at column
0, and `vector.h` has 58 include directives, not 56.** Two are written
`#  include`, indented inside an `#if` at `:72-76`:

```c
#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif
```

Neither was ever tested, and their absence is a live reason the
cumulative prefixes errored — `split_buffer.h` already errors alone,
per phase 1. *The two missing files are not themselves the culprit*:
`no_exception/throw_on_true.h` is reached by `<array>`, `<functional>`,
`<list>`, `<map>` and `<string>`, all of which pass `cxx-bisect`.

Both are fixed. Phase 2 reports ERROR, stops on it, and the script
gives **no verdict at all** when it stopped that way rather than
claiming the body.

### And `cxx-vecsplit`'s own fault was the same shape

Its cut list covered only top-level `template<` boundaries, so its
shortest prefix was the **entire include block in one step** — which
is exactly the thing that crashes. *A ladder whose first rung already
fails has no rungs.* The list spans the whole file now: `LINE DEPTH`
pairs, `DEPTH` closing braces appended, **137 validated of 164
candidates, 56 of them inside the include block**.

**The generator's own guard fired too, and usefully**: a first attempt
to require "no `#if` open at the cut" answered `0 candidates`, because
**the include guard is itself an open `#if` for the whole file**. The
baseline is the depth at the first `#include`, and the trailer's
single `#endif` closes exactly the guard.

**An ERROR rung now STOPS the bisect** instead of counting as clean,
and says so: cpfe stops at the first error, so an errored prefix
cannot say which side the crash is on. Since every cut was compiled by
g++ first, an ERROR there is cpfe disagreeing with g++ — a finding in
its own right.

### What is known now, and it is narrower than before

The crash is **at or before `vector.h:87`** — the include block plus
`namespace std {`. That is where the next run will bisect, and the
answer will be one `#include` line.

## Bisected to one line: `vector.h:28`, `#include "../iterator/niter_base.h"`

```
rung A  shortest prefix (through line 15) -> ok
rung B  the whole <vector>                -> CRASH
  cut 69 (line 1488) -> CRASH      cut 13 (line 27) -> ok
  cut 35 (line 49)   -> CRASH      cut 15 (line 29) -> CRASH
  cut 18 (line 32)   -> CRASH      cut 14 (line 28) -> CRASH
  cut 9  (line 23)   -> ok
***THE CRASH IS IN vector/vector.h BETWEEN LINE 27 AND LINE 28***
```

Seven cpfe runs over 137 cut points. Line 27 is
`#include "../iterator/next.h"` and is clean; line 28 is
`#include "../iterator/niter_base.h"` and crashes.

***A BOUNDARY IS NOT A REPRODUCER, AND THIS ONE PARTICULARLY IS NOT.***
`cxx-vecnarrow` phase 1 compiled `niter_base.h` **alone** and it was
fine, so what kills cpfe is a COMBINATION of which line 28 is only the
last member. The header is self-contained — it includes
`move_iterator.h`, `reverse_iterator.h` and `wrap_iter.h` itself — and
`niter_base` is declared nowhere else in the library, so the
interaction is with one or more of the thirteen includes above it.

### `cxx-vecsplit` phase C minimises it

Greedy removal: drop each earlier include, keep every drop that still
CRASHES, and **keep an include whose removal makes the file merely
ERROR** — that outcome says the prefix stopped compiling, not that it
stopped crashing, and the two are different answers. What comes out is
the smallest set that reproduces, printed and saved to
`/tmp/cxx-vecmin.cpp`. *That is the thing to read, to attach to a bug
report and to hand to `acid`* — a boundary line is not.

### And one guess, labelled as one

`sys/lib/tests/cxx-niterbase-probe.cpp` is twenty lines of pure C++14
with **no library headers at all**, capturing the one unusual shape in
`niter_base.h`: two of its four overloads are declared with a
**trailing return type that calls `niter_base`**.

```c
template<typename t_iterator>
constexpr auto niter_base(::std::reverse_iterator<t_iterator> it)
  -> decltype(::std::make_reverse_iterator(niter_base(it.base())))
```

The name is in scope from its own declarator onwards, so the overload
set the `decltype` resolves against **includes the function being
declared**, whose return type is the thing being computed. It
terminates, because `it.base()` is one level less wrapped, and g++
accepts it both as written and when instantiated — *both checked
before shipping*. It is the shape a front end is most likely to
recurse on.

**It is a guess and the file says so.** This tree's honest tally for
mechanisms guessed from code alone is about one in eight; the
minimiser is the measurement and this is the cheap shot taken beside
it. If it answers `ok` that is still a result: it rules the shape out
and leaves the interaction. If it CRASHES, the whole bug is twenty
lines and neither the C++ library nor EDG's corpus is implicated.

**Nothing in the probe instantiates anything**, because the crashing
translation unit does not either — it is one `#include` and an empty
`main`. *A probe that needed an instantiation to crash would not be
reproducing what was measured.*

### The guess was wrong: `ok`

`c++ -F cxx-niterbase-probe.cpp` translates cleanly and writes
`cxx-niterbase-probe.eccp.c`. **A self-referential trailing return
type is not what kills `<vector>`**, and the only unusual construct in
`niter_base.h` is cleared.

*That is a real result and the reason to have taken the shot*: one
command ruled the shape out where the alternative was reasoning about
it for a round. The file is kept as a regression ladder — if a later
cpfe starts refusing it, the refusal is a finding, because g++ accepts
it both as written and when instantiated. **One in eight is the
recorded tally for mechanisms guessed from code alone, and this one
went the usual way.**

So the fault is in the INTERACTION, which is what phase C measures.

### Phase D, because phase C leaves the last member whole

Phase C shrinks the thirteen earlier includes and never touches the
culprit — so the reproducer always ends with a header that may be
mostly irrelevant. `niter_base.h` pulls in `move_iterator.h`,
`reverse_iterator.h`, `wrap_iter.h` and two metaprogramming headers
before it declares anything of its own, and **`reverse_iterator.h` and
`wrap_iter.h` are NOT among the thirteen**. Line 28 therefore brings
in three new things at once and only one of them need be the one.

Phase D replaces the culprit with each of its own includes in turn. If
one reproduces, the real last member is that file and the culprit was
the envelope it arrived in; if none does, the last member is
`niter_base.h`'s own content — now known not to be the trailing-return
shape.

It resolves a sub-include against `dirname` of the culprit, because a
header's includes are relative to ITS directory and not to `vector/`,
and leaves the `..` segments for the compiler rather than normalising
them by hand — `../iterator/../metaprogramming/x.h` is a good path and
normalising it is a second thing to get wrong.

## Phase C rebuilt the file instead of shrinking it, and the gap is the finding

```
phase C -- MINIMISING the reproducer
  last include before the crash: ../iterator/niter_base.h
  starting from 14 includes
  the includes ALONE answer ok, not CRASH
```

**The report was honest and the method was wrong.** Phase C collected
the include PATHS out of the crashing prefix and wrote a fresh
`#include "<abs>/vector/<path>"` per line. *A minimiser must SHRINK
the input, never reconstruct it* — a reconstruction differs in every
way you did not think to copy. This one dropped three things: the
copyright block, the `#ifndef`/`#define` guard, and the **relative**
include spelling.

Two of the three are cleared by reading: **nothing in the library
tests `PSTL_VECTOR_H`** (one grep — only its own three lines), and
lines 1-11 are a `//` comment. **And no include is circular**: the
transitive closure of each of the fourteen was computed and none
reaches `vector/vector.h`, so the guard cannot be suppressing a
back-include either.

### ***THE TWO FORMS ARE THE SAME PROGRAM***

`g++ -E` over the crashing prefix and over the rebuilt absolute-path
version produce **byte-identical token streams — 6428 lines each**.

So nothing about the C++ differs, and what is left is the file NAMES
and the search that found them. A relative `#include
"../algorithm/equal.h"` from a file in `/tmp` misses in the including
file's own directory and is then found through `-I`; an absolute one
is found at once. ***This port's entire crash history is `stat` in
`host_envir.c`*** — the 88-against-104 `struct stat` was exactly
there — so a failed lookup preceding a successful one is not an idle
difference.

**That is a different place to look from anywhere this hunt has been**,
and it was free: one `g++ -E` and a `cmp`.

### What the ladder does now

**Phase C minimises in place**, deleting real lines from `vector.h`:
the comment block as a unit, the guard pair as a unit (and then the
trailing `#endif` with it), and each `#include` line. It
**re-establishes its baseline through its own builder first** — a
minimiser whose baseline came by a different path is comparing two
things, which is exactly the fault above — and refuses if that
baseline does not crash.

**Phase C2 asks the spelling question directly**: the same surviving
lines with every include rewritten absolute, which is a line-wise
substitution rather than a reconstruction. `CRASH` clears the
spelling and blames the content; `ok` says the C++ is innocent and
the bug is cpfe's file lookup.

**Phase D** replaces the last include with each of its own, as one
`sed` substitution keyed on the same input line number the deletions
use, so the two compose.

## A six-include reproducer, and the guard is load-bearing

Phase C, minimising in place, got to:

```
baseline (lines 1..28)            -> CRASH
without the comment block (1..11) -> CRASH      (so it was dropped)
without the #ifndef/#define guard -> ok         (so it was KEPT)
dropped lines 19 20 22 23 24 25 26 27
```

leaving

```c
#ifndef PSTL_VECTOR_H
#define PSTL_VECTOR_H

#include "../algorithm/equal.h"
#include "../algorithm/fill_n.h"
#include "../algorithm/lexicographical_compare.h"
#include "../algorithm/min.h"
#include "../algorithm/rotate.h"
#include "../iterator/niter_base.h"
#endif
int main(void){ return 0; }
```

**Phase C2 answers CRASH with every include rewritten absolute**, so
the lookup path is innocent and the content is the cause — which
retires the spelling hypothesis the previous round raised. **Phase D
answers `ok` for all five of `niter_base.h`'s own includes**, so that
file is not an envelope: its own content is the last member.

***AND THE GUARD IS LOAD-BEARING.*** Removing `#ifndef PSTL_VECTOR_H`
/ `#define PSTL_VECTOR_H` / `#endif` turns CRASH into `ok` — and
**nothing in the library ever tests that name**; one grep finds only
its own three lines, and no include is circular. So the guard is not
changing what is compiled. It changes what the PREPROCESSOR does with
the file, and the standard thing a preprocessor does with a file
wrapped entirely in `#ifndef X / #define X ... #endif` is the
**multiple-inclusion optimisation**: record that the file is guarded
and skip reopening it. *That is bookkeeping over a file table, which
is the shape of a fault at a small, input-stable address —* `0x3f4cd`
then `0x3f4a9`, across two cpfe binaries.

### `cxx-guardgen`, which has no C++ in it at all

Four generated translation units: `flat` (N trivial headers included
side by side) and `chain` (N deep), **each with and without the
guard, because the no-guard arm is the control** — a probe that ran
only the guarded case could not tell "the guard matters" from "this
many includes matter". Flat and chain are separate because
`<vector>`'s six includes reach about 230 files transitively, so
depth and count are different variables and a probe that moved both
could not say which.

Any CRASH means the bug reproduces with no library, no templates and
nothing but generated headers, and the whole C++ library is out of
it. All four `ok` is also an answer: the generated headers are too
simple, the content matters too, and the next step is to make them
declare templates.

***THE HOST CHECK PAID FOR ITSELF BEFORE THE VM SAW IT***: at the
first draft's 300-deep chain, g++ answers
`#include nested depth 200 exceeds maximum of 200` — a **documented
limit**, so that arm would have measured the limit rather than the
bug, and an ERROR there would have been the probe reporting on
itself. The chain is capped at 150 separately from the flat count,
and the flat arm carries the count question alone. *A probe generated
from a round number is a probe whose failure has two explanations.*

### And phase C now runs to a fixpoint

A single greedy pass is not minimal: dropping one include can make a
later one droppable that was not before. It repeats until a whole
pass removes nothing, skipping lines already dropped. **Six was the
answer from one pass**; whether six is the floor is a question only
the fixpoint answers.

## `cxx-guardgen`: all four `ok`

```
flat-guarded  -> ok      flat-plain  -> ok
chain-guarded -> ok      chain-plain -> ok
```

300 flat and 150 chained generated headers, with and without the
guard, and cpfe survives every one. **So "a guard plus enough files"
is ruled out on its own** — the guard is necessary and not
sufficient, and the CONTENT of the real six matters too.

*That the control arms also pass is what makes the result readable*:
had `flat-plain` crashed, the probe would have been measuring file
count and not the guard at all.

### The state of the elimination

Everything below was measured, each by one command:

| ruled out | by |
|---|---|
| the C++ in `<vector>` | `g++ -E` over both forms: **byte-identical**, 6428 lines |
| the include spelling | phase C2 CRASHES with every include absolute |
| `niter_base.h` as an envelope | phase D: `ok` for all five of its own includes |
| a self-referential trailing return type | `cxx-niterbase-probe`: `ok` |
| a guard plus volume alone | `cxx-guardgen`: all four `ok` |
| a circular include | closure of each of the fourteen: none reaches `vector.h` |
| the guard being read | one grep: only its own three lines |

**What is left is the guard AND the content together**, and at that
point another guess is worth less than one stack.

## `cxx-vecacid`

The input is twelve lines now and the crash has a **real code
address**, which is the difference from the one time `acid` was tried
on this port and gave nothing: that crash was `pc=0x1`, and `src()`
on an address that is not code cannot answer. `src(pc)` can name the
line in EDG's generated C — which is how every other crash in this
tree was finally read.

The script compiles the reproducer, takes the pid out of cpfe's own
`suicide:` line, and runs `regs()`, `stk()`, `lstk()`, `src(pc)` in
that order — **`regs()` first so that an acid that dies later has
already printed the thing most likely to be readable**. It prefers
`/tmp/cxx-vecmin.cpp`, the file phase C left behind and *measured* to
crash, and says so loudly when it falls back to rebuilding it: a
reproducer rebuilt from a recollection is the exact mistake phase C
made one round ago.

It carries this tree's `acid` rule in its header, because the output
is unreadable without it: ***`lstk()` misreads arguments in an APExp
amd64 binary and the first one is always garbage***, since kencc's
`REGARG` is `D_BP` and `acid` reads every parameter from the frame.
Trust the call chain and `regs()`.

**Its own first draft had a fallback that could not fire**: a `sed`
with `([0-9]+)`, which is ERE written into a BRE tool and matches a
literal paren. *A fallback that cannot fire is not a fallback, it is
a second thing to read wrongly when the first fails.* One extraction
now, checked against the real message text.

## ***`acid` NAMES IT, AND IT IS NOT THE FRONT END***

```
_ZN3edg18free_memory_regionEi(...)+0x21   mem_manage.c:1208
_ZN3edg9fe_wrapupEv()+0x109
cfe_main(...)+0xd1
main+0x13
```

`mem_manage.c:1208` is `next_hdr = hdr->next` inside

```c
for (hdr = mem_region_table[rn]; hdr != 0; ) {
    next_hdr = hdr->next;       /* <-- faults, hdr == 0x3f4a1 */
    free_mem_block(hdr);
    hdr = next_hdr;
}
```

**So it is TEARDOWN, not parsing.** cpfe finishes the translation and
dies freeing its memory regions, and `hdr` is a small garbage value
rather than a heap address (`CX` holds it; `TYPE 0xe`, `ERROR 0x4` is
a user-mode read of a not-present page). *Six rounds of narrowing had
all been looking at the front end* — and the register dump was one
command.

### And the memory manager is `mmap`

`mem_manage.c:524`'s `alloc_new_mem_block` has **no alternative
path**: it opens a tmp file once and then, for every block,

```c
mmap(NULL, incremental_size, PROT_READ|PROT_WRITE,
     MAP_PRIVATE, fileno(tmpfile), file_offset)
```

with `file_offset` accumulating — a growing file-backed store.
`host_envir.c:4285`'s `map_memory_region_file` is where that call is,
preceded by EDG's own `fseek`/`fputc`/`fflush` to extend the file.

***THESE NOTES HAD RECORDED mmap AS CLEARED AND THAT WAS TOO STRONG.***
What was checked is `open_mapped_input_file`, which serves PCH and IFC
modules and never a source file — true, and written down as "*that
also clears `mmap`*". **A verdict about one function was generalised
to the whole mechanism**, and `map_memory_region_file` is a different
function that every allocation goes through. Same shape as the clisp
`~0UL` note: *a verdict about one use of a thing is not a verdict
about the thing.*

**libap does not map files.** `__p9_syscall.c:239` emulates: `malloc`
(under `SEG_THRESHOLD`, 64MB) or `segattach`, then `memset` to zero,
then `read(fd, p, len)`. For `MAP_PRIVATE` that is defensible — writes
are not meant to reach the file — but it is a COPY, and **this release
rewrote all of it**: the threshold moved 1MB → 64MB, the malloc arm
began page-aligning by hand, and partial `munmap` was rebuilt twice.

### `edgmmap-probe.c`

Reproduces the call sequence rather than the outcome, which is this
tree's own rule. Five sections; the one it exists for is **2**:
unmap the regions one at a time, in EDG's own order, and after each
unmap re-read every region still believed live. *That is
`free_memory_region`'s loop*, and a `munmap` that releases more than
it was asked for shows up there and nowhere else.

Sections 0-1 report rather than assert (how many map, are the
addresses distinct, do the regions overlap). **Distinct addresses are
not enough** — two overlapping regions would both be writable and
would corrupt each other, which is what a garbage `hdr` looks like
from outside. Sections 3 and 4 assert, because they are POSIX rules
rather than platform choices.

**Section 3 is a bug read straight out of the source**:
`__p9_syscall.c:241` is `if(off != 0) lseek(fd, off, SEEK_SET)`, and
the fd comes from `fileno()` on a FILE that stdio has just written
through — so its position is never 0 and the guard skips exactly the
seek that would have fixed it. POSIX says the mapping starts at
`off`.

**0 failures on glibc with `-Wall -Wextra` and no diagnostics**, so a
failure on the VM is attributable. *Its one warning was worth having*:
gcc reported `off` set and not used, which was true — the array
recorded the offsets and nothing read them. **An unused array in a
probe is a check somebody meant to write**; section 2 prints the
offset beside the address now, so if a later section disagrees about
which region is which, the offset names it.

## `edgmmap-probe`: the hypothesis it was built for is REFUTED

```
0: 8 file-backed MAP_PRIVATE mappings of 65536 bytes
   region 0 at offset 0      -> 0x410000
   region 1 at offset 65536  -> 0x439000
   ...
   region 7 at offset 458752 -> 0x4F9000
PASS  0: every region mapped          PASS  0: addresses are distinct
PASS  1: regions do not overlap
PASS  2: unmapping one region leaves the others intact
FAIL  3: offset 0 reads the start of the file
PASS  4: earlier mapping still holds its data
1 failure
```

***SECTION 2 PASSES, SO THE NEIGHBOUR-CORRUPTION READING IS DEAD.***
That is the one the probe existed for — unmap the regions one at a
time in EDG's own order and re-read every survivor — and a `munmap`
that released more than it was asked for would have shown there and
nowhere else. It does not.

**And the addresses are worth keeping**: the mappings come back at
`0x410000` upward, 128KB apart for a 64KB request (the malloc arm's
hand page-alignment). So **the heap on this platform starts around
`0x400000`, and `hdr == 0x3f4a1` is BELOW it** — never a pointer into
the heap at all, not a corrupted one.

### Section 3 is a real bug and is fixed

`__p9_syscall.c` read `if(off != 0) lseek(fd, off, SEEK_SET)`, which
assumes the descriptor is already at 0 — true only of a freshly opened
file. EDG hands over `fileno(tmpfile)` *after* `fseek`/`fputc`/`fflush`
on the FILE, so the position is past the end and `read` returned 0
bytes into a buffer the `memset` had zeroed: **a mapping at offset 0
that sees none of the file.** The seek is unconditional now.

*It is almost certainly not the crash* — EDG's backing file is extended
with `fputc(0)` and holds nothing but zeros, which is what the buffer
already had. **A POSIX fix found while hunting something else**, and
said to be that rather than offered as the answer.

**It needed a marker of its own.** `_mmapmark` already existed, so a
probe referencing only that one links against a libap predating this
fix and reports the OLD behaviour as the machine's answer — *the exact
failure the idiom exists to stop, arriving through a marker that is
merely too old rather than absent.* **A version marker is only a marker
for the fix it was added with.** `_mmapoffmark` is the thirteenth use.
(The first draft also declared it `extern int` and took its address,
where it is a function; it linked, because the name matches, and was
simply the wrong declaration.)

### What the next run asks

`fe_wrapup` does **not** call `free_mapped_mem_blocks` before walking
the table — checked — so "the headers are in already-unmapped memory"
is out as well.

That leaves exactly two places `hdr` can come from:
**`mem_region_table[0]`, or a previous `hdr->next`.** Those are
different bugs — a bad table head means whatever wrote the table, a bad
link at position N means whatever allocated or freed block N-1 — and
**no amount of reading separates them, because both end at the same
instruction.**

So `cxx-vecacid` walks the chain now: acid reaches the global by its
mangled name, and `next` is the **first** member of
`a_mem_block_header`, so `*h` is the link. A chain that walks two or
three good entries and then lands below the heap says the link was
overwritten; one that is bad at entry 0 says the table was.

### The walk did not run, and that is the lucky half

acid answered `syntax error, near symbol '1'` and printed nothing. The
cause is trivial — inside `{ }` acid terminates **every** statement
with `;`, the final one included, and the loop body ended
`n = n+1` — but the fault it hid is not.

**`mem_region_table` is a pointer, not an array.** `mem_manage.c:455`
declares `a_mem_block_header_ptr *mem_region_table` and `:7030` grows
it with `realloc_buffer`, so entry 0 is `**table`. The walk asked for
`*table`. *A dereference one level short does not fail; it answers* —
it would have printed a chain, in exactly the right shape, rooted at
the table buffer's own address, and there is nothing in such a listing
that says it is about the wrong object. Caught by opening the
declaration, not by reading the output.

The same round fixed `src(pc)`, which acid rejects with
`pc used but not set`; the idiom is `src(*PC)`, as `/sys/lib/acid/port`
uses it.

**And `region_number=0x0` out of `lstk()` is not evidence.** It is that
frame's first parameter, and this tree's own rule is that the first
parameter is always garbage in an APExp amd64 binary (`REGARG = D_BP`,
so the caller never writes `0(SP)`). It happens to be right, because
`fe_wrapup.c:854` passes a literal `0` and acid resolved the call site
to `fe_wrapup+0x109` — *the source says so, not the debugger*.

### And "the memory manager is mmap" was wrong — the same error one function later

Last round these notes said `alloc_new_mem_block` "has no alternative
path". That is true of the function and false of the manager:
`mem_manage.c:751` reaches it only under
`if (precompiled_header_processing_required)`, and the `else` arm is
`malloc_with_check`. This port compiles no PCH, so **every EDG memory
block is plain `malloc`**, and `free_complete_block` is a plain `free`.

The round before, `open_mapped_input_file` was checked and its verdict
generalised to the whole mechanism; this round `alloc_new_mem_block`
was read and its verdict generalised to its caller's behaviour. *The
identical mistake twice in the same paragraph, one level apart.* The
clisp `~0UL` shape a third time: **a verdict about one function is not
a verdict about the mechanism it belongs to.**

So `edgmmap-probe` was measuring a path this crash never takes. Its
section 3 fix stands on its own merits as a POSIX bug; its section 2
pass says nothing either way about `free_memory_region`.

What the crash is reached through instead is **libap's
`malloc`/`realloc`**, which this release rewrote — the 16-aligned
break and `_malloc_growtop`'s grow-in-place, which EDG's region table
goes straight through (`realloc_with_check` → `realloc`, 16KB and up).

*The baked-type class is cleared here, and was checked rather than
assumed*: `mem_manage.c:4652` typedefs EDG's own `size_t` as
`unsigned long long`, so the `malloc(size_t)` and
`realloc(void *, size_t)` the corpus declares for itself agree with
libap's; and `adjusted_header_size` is baked `48ULL`, which is what
kencc makes `sizeof(a_mem_block_header)` under both layout rules
(`8*5 + 1 + 7`, alignment 8). That matters because the baked-type class
is what produced the original `pc=0x1` crash, so it is the first thing
to eliminate and not the last.

### malloc-xcheck: the allocator is cleared, with its limits named

Since the path is `malloc` and not `mmap`, and since this release
rewrote the allocator, the suspect could be examined without the VM.
`sys/lib/tests/malloc-xcheck.{c,sh}` compiles the **real**
`sys/src/ape/lib/ap/malloc/{malloc,free,realloc,aligned_alloc,mallocwatch}.c`
with gcc — not a copy and not an extract, so there are no markers to
rot — against a fake break, with the public names renamed out of
glibc's way. `-fms-extensions` is required for the unnamed `Lock;` and
`Header;` members.

**418 checks, 0 failures.** Five sections: distinctness and overlap;
grow-by-doubling with neighbours above *and* below; realloc's contract;
**EDG's own pattern** — 48-byte headers at the base of 65536-byte
blocks, chained, with the region table `realloc`'d while blocks are
live, then the chain walked as `free_memory_region` walks it; and the
aligned-allocation back door, where `free` must recognise a second
header shape rather than `abort`.

**Sound** for the allocator's arithmetic over a break it is given.
**Unsound** for Plan 9's `sbrk`: the fake one always succeeds, is
always contiguous and is never moved by anyone else, while
`_malloc_growtop`'s whole correctness rests on `sbrk(0)` telling the
truth about a break something else may have moved. LP64 host against
an LLP64 target, and nothing in these files keys on `long` (`BLKSZ`
casts to `size_t` deliberately, and its comment says why) — but that
is to re-check rather than assume if a section ever disagrees with the
VM.

**The control is a deliberate break** — `_malloc_growtop` forced to
claim success, i.e. grow-in-place with its top-of-heap test removed —
and ***it found two of my own checks that could not fail.***

*One:* the first control died in section 1 on an `abort()` from a
destroyed `MAGIC` and **never reached section 3**, the only section
whose assertion is the one the crash violates. Each section runs in its
own process now, the same rule this tree already has for a case that
can hang and for one that can kill the preprocessor.

*Two:* with that fixed, the control passed **everywhere**. Section 1
had allocated all sixteen neighbours before the growing buffer, which
puts the buffer at the top of the heap — where growing it in place is
*correct*; it had only failed in the first draft because section 0 ran
first and left a tangled heap, which is a reason outside the section.
And section 3's table-growth condition, `(i+1)*3 > tablesize` with
`tablesize` 2048 and 400 blocks, **never fired at all**, so the section
measured a malloc-only pattern while claiming to measure a realloc one.
Half the neighbours sit above the buffer now and the table grows every
40 blocks; the control then reports sections **1 and 3**, and section 3's
failure has the real crash's exact shape — `msize 0 start (nil) end
(nil)`, a header zeroed by a `realloc`'d neighbour growing over it.

*Neither fault was visible in a green run.* The clean run looked the
same before and after.

### The walk answered, about the wrong object — the loop destroys its own evidence

`cxx-vecacid`'s chain walk ran and printed **33 entries in perfect
order**: `start` exactly `hdr+0x30`, each entry's `end` equal to the
*next* entry's `hdr`, `msize` 0 for a block carved by `trim_mem_block`
and `0x10000` for its parent. That is not what a chain containing
`0x3f4a1` looks like.

**It is not the region chain.** `free_mem_block` (`mem_manage.c:817`)
pushes each visited block onto `reusable_blocks_list`, which *overwrites
`hdr->next`*, and `mem_region_table[rn]` is cleared only **after** the
loop. So once the loop has faulted, the table head still points at block
0 — whose `next` now points into the reusable list. A post-mortem walk
from the table head follows blocks that were already freed.

*The loop destroys its own evidence as it goes.* No post-mortem walk can
name the bad entry, however carefully it is written. **A healthy chain,
printed about the wrong object** — the third time in this hunt that an
instrument answered confidently about something adjacent to the question.

What the run does establish is worth keeping: 33 well-formed headers say
the heap is not generally scribbled, which is independent corroboration
of `malloc-xcheck`'s clean result from inside the real process. The
table is sane too — `size_of_mem_region_table` 2048, `table[0]` and
`table[1]` live, `table[2..7]` zero, and the eight words around the
buffer hold nothing resembling allocator bookkeeping.

So `free_memory_region` now records five globals as it walks —
`edg_dbg_cur` (the hdr about to be dereferenced, i.e. the bad value),
`edg_dbg_prev` and `edg_dbg_prev2`, `edg_dbg_n` (how far down the chain)
and `edg_dbg_rn` (which region, **measured**, since `lstk()` cannot say:
`region_number` is the first parameter and the first parameter is always
garbage here). Five stores per block freed, no formatting, no output,
read with acid after the fault. `prev`'s own `next` is overwritten by
then, so its *value* is gone and only its identity survives — which is
why the raw words around it are dumped beside it.

**A prediction, with its refutation condition, written before the run.**
The heap here runs about `0x01c00000`–`0x03e00000`. The three bad values
recorded across three builds are `0x3f4cd`, `0x3f4a9`, `0x3f4a1`, and
each shifted left by eight lands at `0x03f4cd00`, `0x03f4a900`,
`0x03f4a100` — just above the live blocks, where a freshly grown break
would be. Little-endian, that is the same byte sequence **read one byte
late**. So: the bad value is a heap pointer read one byte high, and
`edg_dbg_prev` will sit near `edg_dbg_cur << 8`. Refuted if
`cur << 8` is nowhere near the heap, if `prev` is far from it, or if
`prev`'s raw words show an ordinary header with a plainly different
value in its first slot. *It is guessed from arithmetic on the symptom,
which is weaker than guessing from code, and is labelled so.*

### The recorder answers, and refutes the prediction on its first datum

```
edg_dbg_rn    = 0
edg_dbg_n     = 13
edg_dbg_cur   = 0x0003f4a1   (the bad value)
edg_dbg_prev  = 0x03c9f2c8
edg_dbg_prev2 = 0x03cdcd50
prev  0x03c9f2c8 next=0x03cdcd50 start=0x03c9f2f8 avail=0x03caccc8 end=0x03caccd0 msize=0
prev2 0x03cdcd50 next=0x03ce0628 start=0x03cdcd80 avail=0x03ce0628 end=0x03ce0628 msize=0x10000
```

***The byte-shift prediction is refuted, by `edg_dbg_n` alone.*** It was
**13**: twelve links were read correctly through the *same instruction*
before the thirteenth was not. A load generated one byte high would have
been wrong on the first. *A guess from arithmetic on the symptom, dead
on the first datum it predicted nothing about* — and the refutation
condition written down beforehand (`cur << 8` nowhere near the heap) is
not even the one that fired, which is worth noting: the stated condition
was the weaker test.

**Two things are corroborated.** `prev->next` now reads `0x03cdcd50`,
which *is* `prev2` — exactly what `free_mem_block`'s push order predicts,
so the reusable-list reading of the previous round is confirmed from the
other side. And `edg_dbg_rn` is 0, measured rather than taken from
`lstk()`'s first parameter.

**What `prev` is**: a **carved sub-block** — `msize` 0, `trimmed` 1 (the
raw words show `0x00000001` at `prev+0x28`), payload `0x03c9f2f8` to
`0x03caccd0` with `avail` **eight bytes short of `end`**, i.e. full. Its
header is preceded by live-looking data: a pointer, `9`, a pointer,
`0x4d1b`. So `0x3f4a1` is the kind of value that memory holds as **stale
front-end data**, not a mangled pointer — which is what makes the two
remaining explanations the two they are:

| explanation | what the link ring shows |
|---|---|
| the store of `hdr->next` never happened | `ring_next` is also wrong |
| something overwrote it afterwards | `ring_next` is correct |

So `alloc_mem_block` now records every link into a region chain
**reading the field back** rather than recording what was meant to be
stored — the read-back is the whole design, since recording the intent
would answer neither question — and `trim_mem_block` records which
parent each sub-block was carved from. 256-entry rings with untruncated
counts, so a wrap is visible rather than silent.

**The parent ring exists because of where a carved header sits.**
`trim_mem_block` places the new header at the parent's `next_avail` and
then sets the parent's `after_end_of_block` to that same address — so a
sub-block's header is exactly **one byte past the parent's payload**. If
a parent is ever handed out again from the reusable list, its
`next_avail_in_block` is reset to `start_of_block` and it bumps forward
through its payload again. Whether that can reach the header of a
sub-block still live on a region chain is a question the ring answers and
reading does not.

### The rings wrapped, and the counts are the finding

```
link ring: 1647 links recorded   (WRAPPED -- only the last 256 are present)
trim ring: 1094 carves recorded
prev is in no trim slot -- either it was never carved, or the ring wrapped
```

256 was far too small and that is my sizing error, not a subtlety. **The
untruncated count is what made it legible**: a ring that wrapped
silently would have read as *"prev was never linked"*, which is a
completely different finding and one there would have been no way to
tell apart. 4096 now, which covers 1647 and 1094 with room, and the same
line still reports a wrap if one ever happens.

**But the numbers beside it are worth keeping.** 1647 links and 1094
carves against a chain that faults at **entry 13** — and pushes go at the
head, so entry 13 is the *thirteenth most recent surviving link* to
region 0. Unless hundreds of links went to region 1 after it, `prev`
should have been inside even a 256-entry window. So the next run
distinguishes three things rather than two: a correct read-back (a later
overwrite), a wrong one (the store never happened), and **absent from a
4096-entry ring that did not wrap** — which would say `prev` reached that
chain by some route other than `alloc_mem_block`, and is a finding in
itself.

The run also adds a dump of the last two dozen region-0 links in order,
newest first. That reconstructs the top of the chain **from a record the
teardown loop never touches**, which is the one thing the post-mortem
walk cannot do.

### The bad value is identical in every run while every address moves

`0x0003f4a1` has now come back from **four** cpfe binaries. Their `pc`
differs (`0x9da331`, `0x9da39d`, `0x9da451`), the heap sits at a
different offset each time, and `prev` was `0x03c9f2c8` in one run and
`0x03ca16c8` in the next.

**A value that is stable across builds while the addresses around it are
not is not an address.** It is something computed from the input, and the
input is fixed — twelve lines plus about 6400 lines of headers. 259233 in
decimal: a count, a length, or an index.

That is consistent with "stale front-end data" and sharpens it. The eight
bytes at `prev` were last written by something that stores a *count*
there — which is exactly why the parent ring is worth having: a carved
sub-block's header sits one byte past its parent's payload, and a parent
handed out again re-bumps from `start_of_block` through that payload.

### The ring answers: the store was correct, so something overwrote it

```
LINKED  slot 996  hdr=0x03cc32c8  next-read-back=0x03cd0cf0  region=0
CARVED  slot 469  parent=0x03cc0cd0
parent 0x03cc0cd0 next=0x03c90c70 start=0x03cc0d00 avail=0x03cc32c8 end=0x03cc32c8 msize=0x10000
prev header at 0x03cc32c8, parent after_end_of_block 0x03cc32c8 -- EQUAL
```

`prev->next` held **`0x03cd0cf0`** when it was linked — a valid heap
pointer, and exactly link 995's own `hdr`, which is the block it was
pushed on top of. *The read-back is what makes that a measurement rather
than a restatement of intent.* **So the "store never happened" arm is
dead: something overwrote the field afterwards**, roughly 650 links
later.

**The parent is innocent by its own bookkeeping.** `avail == end ==
0x03cc32c8`, the sub-block's header address, so the carve is intact and
the bump pointer stopped exactly where it should.

And `alloc_in_region` is conservative in a way that explains the numbers
rather than merely permitting them: `true_size = size + 8`, the block is
taken only when `true_size <= remaining`, and then `next_avail` advances
by `size` **alone**. So every block keeps eight bytes of slack — which is
precisely why `prev` reads `avail = end - 8`. The dedicated-block arm
(`true_size >= 2096`) then slams `next_avail = after_end_of_block`, which
is why the parent reads exactly full.

**A write at `after_end_of_block` is therefore past the object and past
EDG's own slack**, not merely past the object. The eight bytes below
`prev` (`0x4d1b` at `prev-8`) are inside that slack, so whatever wrote
them was already at the boundary.

### So bracket it in time

Reading has gone as far as it can: the field was right, the parent is
right, and the write happens during ordinary compilation where
`free_memory_region` cannot see it. `alloc_mem_block` now walks region 0
every sixteenth call and records the **first** moment a link stops being
a plausible heap pointer — `edg_dbg_bad_at` (link count),
`edg_dbg_bad_trim` (carve count), `edg_dbg_bad_pos` (chain position),
plus the offending header and value. About a hundred walks of a chain a
thousand long, a hundred thousand reads against a compile that does
millions.

`edg_dbg_checks` counts the clean walks, and it is load-bearing: **a walk
that never ran and a chain that never went bad print the same `-1`**
without it. The script then dumps the nine links and nine carves ending
at that instant, so the rings say what was being allocated when the
field died — a question no post-mortem can ask.

### The window is sixteen links wide

```
edg_dbg_checks   = 65 clean walks
edg_dbg_bad_at   = 1040
edg_dbg_bad_trim = 507
edg_dbg_bad_pos  = 7
edg_dbg_bad_hdr  = 0x03cc32f8      (== prev this run)
edg_dbg_bad_val  = 0x0003f4a1
link total 1647, trim total 1094
```

`prev` was linked at **996**; the walk ran at every multiple of sixteen
and the last clean one was **1024**. So **the write happened between link
1024 and link 1040** — and the value found is already the final one, so it
was written once rather than drifting.

**What the rings show in that window** is one shape: link 1032 is an
ordinary region-0 block, and links **1033 to 1040 are eight brand-new
regions, 329 to 336, one per link, each with `next = 0`** — a region
created and immediately given its first block, eight times running. The
carves beside them are a **chain**: `carve 500 new=0x03d41c40
parent=0x03d417a0`, `501 new=0x03d42400 parent=0x03d41c40`, `502
new=0x03d42a60 parent=0x03d42400` … each new region's block is the
*carved remainder of the previous one*. That is the reuse path working as
designed — `trim_mem_block` pushes a remainder, `alloc_mem_block` takes
it — but it means eight consecutive regions are all carved out of one
original 64KB block.

None of those addresses is `prev` (`0x03cc3xxx` against `0x03d4xxxx`), so
the write is not one of these headers being placed.

### Narrowing to one interval, with the aim taken from the measurement

The `& 15` is gone: the walk runs on **every** call now, which pins the
event to one allocation interval instead of sixteen. And
`edg_dbg_bad_site` says which of five call sites saw it first, which
separates stories the link count cannot:

| site | what it means |
|---|---|
| 1 | entry to `alloc_mem_block` — it happened *before* this call |
| 2 | exit from `alloc_mem_block` — *this* allocation did it |
| 3 | entry to `trim_mem_block` — the carve chain is implicated |
| 4 | entry to `free_fe_huge` — it writes `*prev_next`, i.e. **into a link** |
| 5 | `alloc_in_region` — an ordinary front-end allocation |

**Site 4 is the one real suspect reading named**: besides
`alloc_mem_block` and `free_mem_block`, `free_fe_huge` is the only code
that writes a region link at all.

**Site 5 is armed rather than always on**, at link 1000 — just under the
measured window. `alloc_in_region` runs orders of magnitude more often
than `alloc_mem_block`, so a walk per call over the whole compile would
cost more than the answer is worth; armed, it costs only the allocations
inside the window. *An instrument aimed by a previous measurement rather
than by a guess.*

**And the block had to move in the file.** It was written beside the
function it was first called from, and two of the five sites —
`free_fe_huge` and `alloc_in_region` — are defined *above* that point, so
they referenced an undeclared `edg_dbg_check` and an undeclared
`edg_dbg_allocs`. In C89 the first is an implicit `int`-returning
function, which is this tree's own undeclared-function trap *inside an
instrument written to hunt a memory bug*. Caught by reading the file
order, not by a build.

### Site 3, and the arithmetic lands on one object

```
edg_dbg_checks  = 3132 clean walks
edg_dbg_bad_at  = 1026   bad_trim = 496   bad_pos = 1
edg_dbg_bad_hdr = 0x03cc32f8   bad_val = 0x0003f4a1
edg_dbg_bad_site= 3      (entry to trim_mem_block)
edg_dbg_bad_allocs = 0 of 0 alloc_in_region calls
```

Link 1023 pushed `0x03d00d80` onto region 0 **with `next = 0x03cc32f8`** —
`prev` — so `prev` sat at position 1. Links 1024 and 1025 created regions
327 and 328 and both checked clean at entry *and* exit. Then link 1026's
allocation reached `trim_mem_block` and the check fired. **The write
happened between the exit of `alloc_mem_block` at link 1025 and the trim
preceding link 1026.**

***And `alloc_in_region` was never called: 0 of 0.*** It is a COMDAT
function and **41 of EDG's translation units define their own copy**, so
instrumenting `mem_manage.c`'s copy measures the one nobody calls. Site 5
is void, and that is worth recording as an instrument rule rather than a
detail: *a COMDAT function instrumented in one translation unit is not
the function the other forty call.*

**The arithmetic is the finding.** `alloc_in_region`'s dedicated arm
(`true_size >= 2096`) allocates a fresh block, advances `next_avail` by
`size` **alone**, and then trims — and `trim_mem_block` cuts at
`next_avail` and sets the parent's `after_end_of_block` there. So a
dedicated block's payload is **exactly its object, with no slack**: the
`+ 8` in `true_size` sized the request, and the surplus went into the
carved remainder.

The measured parent is `start=0x03cc0d30 end=0x03cc32f8`, which is
`0x25c8` = **9672 bytes = 1209 eight-byte words**, and the carved header
begins at the object's last byte plus one. **`prev->next` is the word at
index 1209 of a 1209-word object** — a plain off-by-one — and the `0x4d1b`
at `prev-8` is the object's *own last word*, not padding. *An earlier note
here called it padding and that was wrong; the dedicated arm leaves none.*

### An experiment, with its prediction and its refutation

`EDG_DBG_CARVE_PAD` (64) moves the carved header up by that many bytes and
leaves the gap owned by nobody — the parent still ends at `alloc_addr`, the
new block starts above the pad, and the pad absorbs a small overrun instead
of a chain link.

**Prediction**: with the pad, cpfe completes. **Refuted by**: the same fault
at the same place, which would say the write is not an overrun of the
parent's object but something aimed at the carved header itself.

*It is an experiment and not a fix.* Padding every carve changes EDG's
layout everywhere, which is the kind of change that can move a bug rather
than remove one; set it to 0 for upstream's arrangement. The
`space_remaining` test is raised by the same amount so a carve still leaves
a usable block behind.

The rings now also carry sizes — `link_size` is what each block was asked
for, `trim_size` is `alloc_addr - start_of_block`, the object the carve cut
behind — so the next run states the 9672 rather than leaving it to
subtraction, and names the element count of whatever table this is.

### The pad experiment: prediction held, cpfe completes

`cxx-vecacid` answers **NO CRASH**. With `EDG_DBG_CARVE_PAD` at 64 the
carved header sits 64 bytes above the parent's `after_end_of_block`, the
gap belongs to nobody, and cpfe finishes the twelve-line reproducer.

**The prediction and its refutation were written down first and the
refutation did not fire.** So the write is a *small overrun past a
parent's object*, and the carved block's `next` had been sitting exactly
one word past that object.

***But "no crash" is the weakest possible form of that result.*** A
layout change that moves everything can hide a bug as easily as it can
dodge one — this tree's own rule about a fix that makes a process reach
code it never reached before, read backwards. An absence is not a
measurement.

So the pad now carries a **canary**: `memset(alloc_addr, 0xA5, PAD)` at
carve time, and a walk of the trim ring at the first `free_memory_region`
reporting every pad that is no longer `0xA5` — with the slot, the carved
block, its parent, **the parent's object size**, the offset of the first
dirty byte and the bytes there. That is a positive measurement of the
overrun where the silence was only an absence.

cpfe has no diagnostic channel that reaches a finished run — `mem_manage.c`
declares `free`, `malloc`, `realloc`, `memcpy` and `memset` and nothing
that prints — so the report is formatted by hand and written to fd 2.
`cmd/edg/mkfile` passes `-c -C` and no `-T`, so there are no type
signatures for the `write` declaration to disagree with. **The block was
extracted and compiled alone with `gcc -std=c89 -Wall -Wextra` before
shipping**, which is this tree's own rule about syntax-checking on the
host rather than paying a VM round for a typo.

**The next discriminator, stated before the run.** If the report shows
*one or a few* dirty pads, it is a specific EDG object running past its
end and the `objsize` column names which. If it shows *many*, the overrun
is systematic — which stops being an upstream off-by-one and starts
pointing at a shared idiom or at the compiler. **`dirty=0` with a nonzero
carve count refutes the overrun reading outright** and says the pad merely
moved the layout; `EDG_DBG_CARVE_PAD 0` restores upstream's arrangement.

### The canary fired: one pad in 1120, eight bytes, the same value

```
edg-pad: carves=0x460 checked=0x460 chain-bad-at=0xffffffffffffffff
edg-pad:  slot 0x1d2 new 0x3cb7370 parent 0x3cafd70 objsize 0x7590 off 0x0
          bytes a1 f4 3 0 0 0 0 0 a5 a5 a5 a5 a5 a5 a5
edg-pad: dirty=0x1
```

`a1 f4 03 00 00 00 00 00` little-endian is **`0x0003f4a1`** — the exact
value that had been landing on `prev->next` — written at **offset 0** of
the pad, eight bytes, with every byte after it still `0xA5`. And
`chain-bad-at` is `-1`: with the pad in, the chain never went bad at all.

So the overrun reading is **confirmed positively**, not merely by an
absence: one write, one eight-byte word, at exactly
`parent->after_end_of_block`.

***And `dirty = 1` of 1120 carves settles the discriminator.*** It is
**not** systematic. One object runs past its end; the other 1119 carves
are clean.

**`objsize` is not yet the object's size, and that is a correction to the
last round.** It is `alloc_addr - start_of_block`, which is *how full the
block was when it was trimmed* — 0x25c8 (9672) in the unpadded run,
0x7590 (30096) here. Those are different blocks, not one object changing
size, and a block filled by many small allocations gives a total rather
than an object. So the report now also prints **`blockreq`**, the
`min_size` the block itself was asked for: `alloc_in_region`'s dedicated
arm requests `true_size = size + 8` and then bumps by `size` alone, so a
block whose `blockreq` is exactly `objsize + 8` held **one** allocation
of `objsize` bytes. That is the number that can be matched against EDG's
source; anything else means the total.

### The leading reading, and what the count does to it

`alloc_in_region` reserves `size + 8` — **exactly one word** — and then
advances `next_avail` by `size`, so every allocation is followed by eight
bytes that are checked for but never handed out. `trim_mem_block` cuts
the block at `next_avail`, which **removes that reservation for the last
allocation in any trimmed block**.

That makes a coherent story: upstream's `+8` is slack that absorbs a
one-word write past an object, and it is harmless everywhere *except* at
a carve boundary, where the carved header now occupies the reserved word.

**And the count is what keeps the story honest.** If every allocation
wrote its reserved word, 1120 carves would give many dirty pads; one
does. So the reservation exists and is almost never used — consistent
with one EDG data structure writing a terminator past its end, and
inconsistent with "the `+8` is routinely written".

*This is upstream's arrangement either way*, so if it is a latent bug it
is one that only shows where a carve lands exactly there — which is what
this port does.

### blockreq says the block was not one object

```
slot 0x1d2 new 0x3cb7380 parent 0x3cafd80 objsize 0x7590 blockreq 0x150 rgn 0x0
```

`blockreq` is `0x150` = **336**, and `objsize` is `0x7590` = **30096**. The
test stated last round was `blockreq == objsize + 8` for a single
dedicated object; `336 != 30104`, so **that block was not one allocation**.
336 is the `true_size` of whatever allocation *first* overflowed the
previous block and triggered this one; the block then grew to 30096 by
many small bumps, and the overrun belongs to the **last** of them.

So neither column names the overrunning object. The size that would is the
last `alloc_in_region` call's — and that function is COMDAT with 41 copies,
so instrumenting `mem_manage.c`'s measures the one nobody calls. Naming it
means patching all 41, which is mechanical but is a round of its own.

### The ring wrapped, so `dirty=0` meant nothing

The bigger input (`cxx-library-test.cpp`) answered
`carves=0x1051 checked=0x1000 dirty=0x0` — **4177 carves into 4096 slots**,
so the 81 oldest were never looked at. *A count that can only report what
the ring still holds is a check that cannot fail for anything older*, and a
zero from it is an unread window rather than a clean one.

A slot is checked when it is **evicted** now, as well as at the end, which
makes the scan complete whatever the ring size; and the first dirty pad
found anywhere is kept in full (`edg-pad: FIRST ...`), because that is the
one whose surroundings mean anything.

### Three C++ library errors no header check could reach

`c++ -o cxx-library-test cxx-library-test.cpp` reported three, all in
`vector/split_buffer.h`'s nested `M_destroy_buffer`:

| written | the member actually is |
|---|---|
| `M_clear()` | `clear()` |
| `M_M_alloc()` | `M_alloc()` — the prefix applied **twice** |
| `M_end_cap()` | `end_cap()` |

Upstream's `__clear`, `__alloc` and `__end_cap` put through the rename with
the wrong prefix. ***And nothing could see them until something
INSTANTIATED that class***: the uses are on a `split_buffer &`, a dependent
type, so both cpfe **and g++** defer the lookup to instantiation.
`cxx-bisect` compiles each header alone; `cxxlib-host.sh --headers` and
`--run` exercise the public API and never touch that nested class. **A
header that compiles is not a template that instantiates.**

`cxxlib-host.sh --instantiate` is the instrument: an explicit instantiation
*definition* reaches a class template's member functions and member
classes, so it covers code no use of the public API happens to touch. Five
specialisations, **0 failures** with the fix. It **reports rather than
gates** — some of these templates are exception-free by convention and have
members that are ill-formed to instantiate for an arbitrary argument.

**Its control searches git HISTORY rather than `HEAD`**, since the three
names are now fixed and staging `HEAD` would stage the fix: it walks back
for the last revision still carrying `M_M_alloc`. ***And the first version
of that control fired for the wrong reason*** — it named the staged source
by a hand-written label that did not match the one the loop builds, so g++
answered `No such file or directory`, a non-zero exit the test read as
"the control fired". It demands the string `M_M_alloc` in the diagnostic
now. *Caught by reading the output rather than the exit status.*

### And the crash is back on the bigger input, at a different pc

`cpfe ... fault read addr=0x3f4cd pc=0x90c3a1` — the **same family of
value** (`0x3f4cd` is one of the three recorded earlier) at a **different
code address** from `free_memory_region`'s `0x9da331`. `chain-bad-at` is
`-1`, so the region chain never went bad this time. With the eviction check
in, the next run's `dirty` count can be read; until then that `0` is only
the unread window.

***AND THE RUN AFTER THE FIX COULD NOT BE READ, FOR A REASON THAT IS THIS
TREE'S OWN RULE.*** The next VM run printed the three `split_buffer` errors
gone, `carves=0x1042 checked=0x1000 chain-bad-at=-1`, `dirty=0x0`, and the
fault still at `pc=0x90c3a1`. The three errors vanishing is real — but it
proves the **headers** were updated, and cpfe reads those at run time, so
it says nothing about whether `mem_manage.c` was rebuilt with the eviction
check. **The report's format was byte-identical either way**, so `dirty=0`
had two explanations: a complete scan that found nothing, or an old binary
scanning only the 4096 slots the ring still held.

*A version marker is the standing answer to exactly this, and this file had
already recorded it thirteen times for libap.* The line now reads
**`edg-pad2:`** and carries **`evicted=`**, the number of slots checked as
they were overwritten. An `edg-pad:` line, or `evicted=0` with `carves`
over 4096, means the dirty count is partial. *The instrument was complete
and unreadable, which is the same thing as incomplete.*

`cxx-vecacid` takes an **input file** now, because the crash moved off the
twelve-line reproducer onto `cxx-library-test.cpp` at a different `pc`, and
a ladder hardwired to one input cannot reach the other. It also says, after
the region walk, that the walk means nothing unless `stk()` named
`free_memory_region` — *a healthy chain printed against the wrong question
is exactly what the 33-entry run was.*

### `evicted=0x42` — the carve overrun did not happen on this input

`edg-pad2: evicted=0x42 carves=0x1042 checked=0x1000`. 66 evicted plus 4096
live is 4162, which is `carves` exactly, so **the scan is complete and
`dirty=0` is a real zero.** The carve-boundary overrun did not occur on
`cxx-library-test.cpp`, `chain-bad-at` is `-1`, and the recorder shows
`free_memory_region` at `n=1` with a healthy `cur`. *So this is a different
bug from the one the pad experiment settled*, and the pad result on the
twelve-line reproducer stands on its own.

### And the stack names it: the token cache, not the memory manager

`get_token_from_reusable_cache_stack+0x241`, `<noname>:4869` — which is
`token->base.extra_info_kind`, the **first dereference of `token`** — with
`CX = 0x000000000003f4b1` and the fault at `0x3f4cd`, i.e. CX + 0x1c.
**Plan 9 amd64's text base is 0x200000**, so `0x3f4b1` is below the
executable itself and was never an address. The earlier
`addr=0x3f4cd pc=0x90c3a1` run was *this same fault*, not a second one.

**The connection to the first crash is the value.** `0x3f4a1`, `0x3f4a9`,
`0x3f4b1`, `0x3f4cd` are one family, eight apart, and `0x3f4a1` is what had
been landing on a region link. So there is one producer of bogus small
values showing up in two places — which is what "stale front-end data"
meant, now with the front end's own structure named.

The chain back from the fault is short and entirely read:

* `Shared_obj_control_block<an_immutable_cached_token>` has `object` at
  **offset 0**, so `ptr()` returns the control-block pointer unchanged.
* `Shared_obj` is one 8-byte pointer — `n_allocated = n_bytes_allocated / 8`
  says so from the corpus itself.
* `Dyn_array::operator[]` is `return elems + i`, with **no bounds check at
  all**.

So the array element holds the bad value, and there are exactly two ways:
`offset` past `n_elems` (a bounds bug), or a corrupt stored element.
**Different bugs, one symptom** — the shape this hunt has already mistaken
once — so `edg_tok_note` records five fields and a 64-deep ring before the
dereference, and `cxx-vecacid` prints them first. `edg_tok_calls` is
load-bearing: a recorder that never ran and a first call that went bad
print the same thing without a count.

**The loop's exit rule is why `endcache` is recorded.** `end_it` is built
from the cache reached through the stack entry's `operator->`, while the
element is indexed through `next_token.cache`. If those differ, `next_token`
can never equal `end_it` and the walk runs off the end of a flat array —
possibility one with a named mechanism.

**Two things checked and cleared on the host, so they are not the lead.**
The `memcpy(&next_token, &iterator(0,0), 12ULL)` is not a baked size error:
EDG emits two forms of every struct, the padded one and a `__SO__` one
without tail padding, and copies the object representation excluding
padding — upstream's own correct idiom, and also exactly why `-J` matters.
And `a_token_cache` being `{ unsigned is_reusable:1; Dyn_array tokens; }` —
a bit-field followed by a struct member, with two new bit-field layout
rules landed this release — does not bite here: the host `6c -J -p -a` gives
`a_token_cache` 32, the control block 128, `a_cached_token_base` 120 and the
iterator base 16, and member access in the corpus is **symbolic**, so a
layout difference only matters where a size is *baked*, which
`edgbaked-xcheck` already sweeps. *Both were plausible sentences; one
compile each said no.*

### The prediction was refuted by its own stated condition

The run gave **`off=0`, `n=23`, `cache == endcache == 0x03b8e278`** — so it is
**not** a bounds bug and **not** the sentinel mechanism. `edg_tok_calls` is
742991, so the path ran; `site=1`; and the 64-deep ring shows every one of
the 63 preceding lookups returning a plausible heap pointer (`0x01cbXXXX`),
with `off` climbing 0,1,2…12 through caches of `n=13` and `n=9`. **Element 0
of a 23-element array holds `0x3f4b1`**, and it is the first lookup from that
cache.

`n_allocated = 31` is not a second finding, and that was checked rather than
assumed: `grow` is `new_cap = old_cap + old_cap/2 + 1` (2, 4, 7, 11, 17, 26)
and `alloc_fe_var_size` writes back the *actual* size, so a request of 208
bytes rounded up to 248 is 31 slots.

What `grow` does show is where to look next: after `move_elements` it
**frees the old buffer onto `reusable_fe_list`** (`free_fe_normal` below
2096 bytes, `free_fe_huge` above). A cache still pointing at a recycled
buffer would read whatever its new owner wrote — the same family as the
value that landed on a region link.

**The array dump needs no rebuild**, because `edg_tok_elems` and `edg_tok_n`
are already in the installed binary. It separates three things: only element
0 bad (a construction or move-count bug), several bad (the buffer, so grow /
move / reuse), or all bad (`elems` is not what the cache thinks). The four
words below `elems` go with it, since an FE allocation carries its block
header there and a buffer sitting at a carve boundary is what would tie this
to the first crash.

### Only element 0, and the four words below it are the same tail

`elems[1..22]` are all plausible control blocks (`0x03b84740`, `0x03c08520`,
…); `elems[0]` is `0x0003f4b1`. And below `elems`:

```
0x03c15270: 0x03b59df8      pointer
0x03c15278: 0x00000009      9
0x03c15280: 0x03c486b8      pointer
0x03c15288: 0x00004d1b      0x4d1b
0x03c15290: 0x0003f4b1      elems[0]
```

**That is the four-word tail already recorded for `prev` in the first
crash** — "a pointer, `9`, a pointer, `0x4d1b`" — with `0x4d1b` matching to
the digit. So it is one write with two victims: a carved block header's
`next` then, a `Dyn_array`'s element 0 now. *The two crashes are one bug,
and that is now positive rather than inferred from the value alone.*

**And `grow` says this buffer is recycled.** 23 slots of 8 bytes is 248, and
`alloc_fe_var_size` takes anything under 2096 bytes off `reusable_fe_list` —
which `grow` itself fills, pushing the old buffer there after
`move_elements`. Three questions follow, and all three are free, because the
data is already in the broken process and needs no edg rebuild:

1. **Is `elems` on `reusable_fe_list` right now?** A live cache indexing a
   block that has been handed back names the bug outright.
2. **What is below `elems`,** far enough back to show the preceding object's
   shape and a 48-byte `a_mem_block_header` if the block starts near —
   `start`/`end`/`next`/`msize` are recognisable.
3. **Which recorded block contains `elems`?** The link ring holds every
   `hdr` and the trim ring every carve, so a scan for the one spanning
   `elems` says whether this buffer sits in a carved sub-block, which is how
   the other crash's victim was placed.

*A negative on (1) is as useful as a positive*: it says the block is live and
the word was overwritten in place, which is the overrun reading, and leaves
the 34-copy allocation ring as the way to name the writer. **`alloc_fe` and
`alloc_fe_var_size` are COMDAT in 34 TUs each**, the same trap that made
`alloc_in_region` report `0 of 0`, so that instrument is a uniform sed over
all 34 copies and is worth paying for only once these three have answered.

### All three answered, and the third dictated the next instrument

1. **`elems` is not on `reusable_fe_list`.** The block is live and the word
   was overwritten in place — the overrun reading, against use-after-free.
   *A negative that is a result.*
2. The object below `elems` runs from `0x03c15158` — zeros beneath it, a
   self-pointer at its head — to `elems`: **312 bytes**. But no EDG struct
   among `lexical.c`'s 327 is 312 bytes, so **the boundary is a guess** and
   reading further into the object would be guessing twice.
3. **0 blocks and 0 carves span `elems`**, and that is not a miss. The link
   ring holds the last 4096 of 7459 links and every one is at `0x07…`/`0x0c…`
   while the victim is at `0x03c1…`: this block was allocated early and is
   long-lived.

**(3) is why the next instrument is a watch and not a ring.** Anything keyed
on recency had already evicted the answer, and a bigger ring only moves the
horizon. The question is not "what happened lately" but "what object occupies
the bytes below this address" — and `elems` is **byte-identical across two
runs with different pids**, so the address is a usable handle.

`edg_wat_note` records any allocation that ends at, starts at, or spans the
watch address, and is inserted in every copy of `alloc_fe` and
`alloc_fe_var_size`. **27 copies, not the 34 first counted**: that grep
matched the `extern` prototype as well as the definition, because the
prototype line contains the definition anchor as a substring. *The patch's own
count gate caught it*, and the real number was then confirmed by an
independent anchor — the parameter's temp name, which the prototype does not
carry. All six spot-checked files compile clean under the host `6c -J -p` and
under `gcc -std=c89`.

`rel` is the whole reading: **1** ends at the watch, so `size` names the
overrunning object against EDG's structs; **2** starts at it, the victim
buffer; **3** spans it, which would refute the boundary reading outright and
say the word is interior to a live object. `edg_wat_calls` separates "the
watch address moved" from "the instrument never ran", which print the same
without it.

### The watch missed twice, in two independent ways

**`edg_wat_calls = 0`.** Not "the address moved" — though that was also true,
and is the reason the counter exists.

1. **`alloc_fe` has 41 definitions and `alloc_fe_var_size` 34**, not the 27
   the patch found. `cmd/edg/mkfile` passes `-C`, which marks every symbol
   `dupok` so `6l` keeps the **first** definition and discards the rest — so
   patching a subset can patch a copy that is not the live one, and the
   survivor was one of the 14 missed. *Two true statements, one irrelevant,
   and only `edg_wat_calls` separates them.*
2. **`elems` moved by exactly `0x710` = 1808 bytes**, which is precisely the
   BSS that build added (64 slots of 8+8+4+4+4, plus 16). The FE layout is
   deterministic relative to the **heap base**, and the heap base sits above
   BSS — so an absolute-address watch moves the thing it is watching, by its
   own size. *Apparatus inside the quantity being measured.* "Byte-identical
   across two runs" was true of two runs of **one binary**, and read as a
   property of the program.

**And the first miss was in the verification as much as the patch.** The
patcher keyed on EDG's temp names, assuming COMDAT text is identical across
TUs; 14 files number their `__T<n>` temps differently. The check counted
files matching *the same anchor*, so it agreed with the patch by construction
and reported 27 of 27 — **a check phrased against the thing under test
instead of against something independent of it**. The gate asks structurally
now: every file that *defines* the function, found with no reference to any
temp name, must contain a call. **41 of 41 and 34 of 34**, and eight
spot-checked files compile clean under the host `6c -J -p` and `gcc -std=c89`.

**So the watch keys on a SIZE.** The victim is 248 bytes (31 slots of 8, from
`grow`'s `old + old/2 + 1` rounded up by `alloc_fe_var_size`), and a size does
not move with BSS. `alloc_in_region` bumps sequentially, so the allocation
immediately before a 248-byte one is the object the victim sits on top of, and
`prev_size` is the number to match against EDG's structs. `adj` is the honest
part: `prev_ptr + prev_size == ptr` must hold, or the two are consecutive
*calls* rather than neighbours in memory and `prev_size` names nothing.

A third, smaller fault in the same run: `while i < *edg_wat_n && i < 64`
printed 64 empty rows at a count of 0, while the identical shape over a local
stopped correctly at 24. A dereference in an acid loop condition does not
control the loop; the bound is hoisted now. *A loop bound that cannot bound
the loop prints a table of zeros that reads exactly like data.*

### The 900MB log was mine, and it names an acid rule

The watch section never ran — the run was killed inside the lookup loop — but
the two runs together say why. In the earlier run `while i < *edg_wat_n && i
< 64` printed **64 rows while `print` showed that same counter as 0**, so a
dereference in an acid loop condition reads as something large and the only
thing that stopped it was the literal `i < 64` beside it. I then "fixed" that
by hoisting to `while i < m do` with **no literal at all** — and it ran until
the disk did. *A bound read from memory is not a bound.*

Two changes, and both are about never doing that again: **every loop bound in
this script is a literal** (the watch prints all 32 slots and empty ones read
as `ptr=0x0`), and **every acid pipe is capped with `sed 2000q`**. A runaway
that cannot be read is bad; one that fills a disk before anyone sees it is
worse. The watch section also moved to run **right after the token recorder**,
so the data that matters is written first and a later kill costs nothing.

One datum did survive: `edg_tok_elems = 0x03c157b0`, down **496 bytes** from
`0x03c159a0` — and 496 is the difference between the old watch globals (1808
bytes) and the new ones (1316). **Second confirmation that FE addresses track
the heap base and the heap base tracks BSS**, which is exactly why the watch
had to stop keying on an address.

### `adj=0` on 31 of 32 rows: the free list, which the source already said

The size watch ran — `calls = 627353`, `hits = 1222`, 248 bytes — and
**refuted its own prediction**: `adj=0` on 31 of 32 rows, so the allocation
immediately before a 248-byte one is a consecutive *call* and nowhere near it
in memory. `elems = 0x03c157b0` is not in the table at all, because there were
1222 hits and it records the first 32.

**The reason was in the source and I failed to carry it over.** `grow` frees
the old buffer onto `reusable_fe_list`, and `alloc_fe_var_size` serves
anything under 2096 bytes *from* that list — so bump order and address order
barely relate. The repeats say it plainly: `ptr=0x02230fd8` is handed out
fifteen times in 32 rows. The one `adj=1` row is the single case where the
free list missed and `alloc_in_region` bumped.

So all three keys are dead: an **address** moves with BSS (twice confirmed), a
**size** names 1222 allocations, and **bump order** is not address order.

**The record aims itself now.** Every allocation is appended to a flat table
(1<<20 entries, 12.5 MB; `edg_wat_all_n` reached 627353 for this input), and
the table is searched **once**, from inside `edg_tok_note`, at the first
lookup whose token is below the text base — which is the faulting lookup,
reached *before* the dereference. The one moment the victim's address is known
is also a moment at which code can still run. Nothing is hardcoded: no
address, no size, no ring depth.

**The table stops rather than wraps**, because the victim sits at `0x03c1…`
in the low heap and was allocated early — a ring would evict exactly the entry
wanted, which is the mistake the link ring already made when it held the last
4096 of 7459 and every one was above the victim. `edg_wat_over` separates
"the table was too small" from "nothing ends there".

**The counts are reported, not just the last match.** These blocks are
recycled, so a range is allocated many times; `nbr_cnt == 9` means the most
recent match is a guess at which one was live, and that has to be visible.

### The self-aiming record worked: a 32-byte object ends at the victim

`recorded = 627353`, `overflowed = 0` — the table is complete. `found = 1`
and `target == elems now == 0x048152e0`, so the search fired on the right
address with nothing hardcoded. And:

```
nbr_ptr = 0x048152c0   nbr_size = 32    nbr_cnt = 2
vic_ptr = 0x048152e0   vic_size = 248   vic_cnt = 5
```

**A 32-byte allocation ends exactly at the victim** — and 32 bytes is
precisely the four words already dumped. This run shows them again:

```
0x048152c0: 0x04759e48      pointer
0x048152c8: 0x00000009      9
0x048152d0: 0x04848708      pointer
0x048152d8: 0x00004d1b      19739
```

**The two numbers are identical across runs and across both inputs while the
pointers move**, so 9 and 19739 are data, not addresses — two
`{pointer, number}` pairs. And `elems[0]` is `0x0003f4b1` again, to the digit.

*The address moved a third time* (`0x03c157b0` → `0x048152e0`, by the 12.5 MB
the table added), which is exactly why the address key had to go.

**No 32-byte EDG struct has that shape.** Checked against every aggregate the
host `6c -a` emits for seven TUs: 32 distinct 32-byte structs, and **zero**
with `{ptr@0, num@8, ptr@16, num@24}`. `a_text_buffer` is
`{allocated_size, size, allocation_increment, buffer}`,
`an_include_search_result` is four `char *`, `a_token_cache` is
`{bitfield, Dyn_array}` — none fit.

So `kind` is the next datum: **1** means a fixed `alloc_fe(32)`, i.e. a struct
outside the set checked; **2** means an `alloc_fe_var_size` buffer, i.e. a
`Dyn_array` of two 16-byte elements — which is what two `{pointer, number}`
pairs look like. Both histories now print in full rather than the last match,
because `nbr_cnt = 2` and `vic_cnt = 5`: these blocks live on
`reusable_fe_list` and come back, so "the most recent match" is a guess about
which allocation was live.

### `kind = 1`, and content and layout both fail to identify it

**Refuted.** The neighbour is a fixed `alloc_fe(32)` — a struct, not a
`Dyn_array` buffer — which kills the `{pointer, number}` pair reading with it.

**The indices are the other half, and they are the useful half.** The
neighbour is allocated at **113624**, the victim's five allocations run
113627 → 114085, and then the neighbour is allocated **again at 114548** —
after the live victim buffer was handed out. So whoever receives that second
32-byte block is writing into a buffer that is already live.

**Two ways of naming the object both failed, and each failure is a result:**

* *By content.* The block was allocated **twice**, so what it holds when the
  process dies need not be what it was allocated as. A snapshot of a recycled
  block is not a type.
* *By layout.* Every aggregate the host `6c -a` emits for **all 75 TUs** —
  4812 distinct, **757 of them 32 bytes** — was searched, and **zero** have
  the observed `{ptr, num, ptr, num}` shape. A real negative, and it says the
  inference was the wrong instrument rather than that the object is exotic.

So each `alloc_fe(32ULL)` site is tagged with a number recorded beside the
allocation. **58 sites, of which 24 allocate `struct a_token_cache`** — which
is suggestive in a token-cache bug, and exactly the kind of thing to measure
rather than assume. `sys/lib/tests/edg-wat-sites.txt` is the tag → file:line →
type map. A site of **0** means the 32 bytes came from a call whose size is not
the literal, which is a finding of its own.

### `found = 0`: the instrument was absent, not the bug

The run came back `calls = 627353`, `recorded = 627353`, `overflowed = 0` —
and `found = 0`, `target = 0`, both histories empty. **The cause was mine.**
The corpus had been reverted and re-patched to add the call-site tags, and
the arming of `edg_wat_find` inside `edg_tok_note` was a *separate* edit run
by hand, which did not get re-run. Nothing ever called the search.

*An instrument that is correct in three pieces is not an instrument.* All
three edits are one committed, re-runnable script now —
`sys/lib/tests/edg-wat-patch.py` — and each one gates:

1. every definition of `alloc_fe` (**41**) and `alloc_fe_var_size` (**34**),
   found by parameter spelling and by the first `return (char *)X;` after it,
   **with no temp name in any anchor** — the assumption that missed 14 files;
2. every `alloc_fe(32ULL)` call site (**58**), tagged, with the map written to
   `edg-wat-sites.txt`;
3. the arming in `edg_tok_note`.

The gates are phrased against the temp-agnostic definition lists and against
the files themselves, never against the anchors the patch used.

**And `found = 0` was unreadable, which is the smaller lesson.** "The search
is absent" and "no lookup ever saw a bad token" are opposite findings — one
says the instrument is missing, the other says the crash moved — and they
printed identically. `edg_wat_armed` is set on every `edg_tok_note` call now,
exactly as `edg_wat_calls` already separates "not in the live copy" from "the
address moved". *Three counters, three times the same ambiguity.*

## The crash is an EDG allocation baked for the OLD `ino_t`/`dev_t`

`site = 34` is `lexical.c`'s `alloc_include_file_history`, allocating
`an_include_file_history`. **The corpus bakes `alloc_fe(32)` and kencc lays
that struct out at 48.**

```
'Y'  0 full_name                    observed: a pointer
'U'  8 suppress_subsequent_include  observed: 9 = bits 0 and 3
'U'  8 pragma_once / ifdef_guard / ifndef_guard / use_canonical_name
'Y' 16 controlling_macro_name       observed: a pointer
     24 unique_id, 16 bytes         observed: 0x4d1b …
                                    …and its second half at +32, one word
                                    PAST a 32-byte block
```

`a_unique_file_id` is `{dev_t st_dev; ino_t st_ino;}`, and **this release
widened both from `unsigned short` to `unsigned long long`** — the same change
that took `struct stat` from 88 to 104 and smashed cpfe's return address on
every input. The typedefs were widened in EDG's five files; **the baked
allocation sizes were not**, because nothing looks at them.

Every observation falls out of that one number:

* the stable `9` is the bit-field word, and `0x4d1b`/`0x3f4b1` are the two
  halves of a **file id** — which is why they were identical across builds and
  across a twelve-line input and a 2000-line one while every address around
  them moved. *A value stable while addresses move is not an address*: it was
  a device/inode pair all along.
* exactly **one word** is written past the block, because the struct overruns
  32 by 16 and the first 8 of those are still inside EDG's own slack.
* the victim is **whatever was allocated next** — a carved block header's
  `next` in the first crash, a token array's `elems[0]` in the second. *One
  write, two victims, and they were one bug from the beginning.*

**The fix is spelled `sizeof(struct an_include_file_history)`**, not `48`, so
it cannot go stale again, and the corpus is restored to a pristine base first:
every `edg_dbg_*`, `edg_tok_note` and above all `EDG_DBG_CARVE_PAD` — which
padded every carve by 64 bytes — is gone, so what gets tested is the fix and
not the fix plus a layout experiment.

`sys/lib/tests/edgsize-sweep.py` is the general form and **gates**: for every
`((T *)(alloc_fe(N)))`, is N smaller than kencc's `sizeof(T)`? **209 agree, 0
short, 5 larger (arrays, reported not counted), 52 type unknown.** Its limits
are in its header; the one worth repeating is that `X_ptr` is EDG's own
typedef for `X *` and the mangled length prefix must be *recomputed*, not
suffix-stripped — without that the one real finding sat inside the 52 unknowns.
Its control puts the baked 32 back and requires the sweep to name the site.

***And the root guard fired on its own first run, for the fifth time*** —
`sys/lib/tests` is three levels below the root and the first draft said two.

## The crash is gone, and the next thing on that path is cpp

`cxx-vecacid cxx-library-test.cpp` answers **NO CRASH**. cpfe completes, and
`cc -c` reaches cpfe's **output** for the first time — where it answers
`Syntax error in #line`, dozens of times, once per header switch. *A fix that
makes a process reach code it never reached before can expose anything on
that path*, and this was the next thing on it.

**It is a GNU linemarker.** `c_gen_be.c:782` builds the directive from the
literal `"#line "`, sets `buf[1]` to a **space** when the target is
gcc-or-clang so it becomes `# N`, and appends gcc's system-header flag after
the file name. kencc's `cpp` rejected any token after the name:

```c
tp+3<trp->lp || (tp+3==trp->lp && (tp+1)->type!=STRING) || *(tp+1)->t=='L'
```

Measured with `cpp-xcheck/`, which builds this cpp with gcc on the host:
**the four plain forms were accepted and every flagged one refused.** After
the fix, all eight. The flags — 1 enter, 2 return, 3 system header, 4
`extern "C"` — are **skipped rather than acted on**, which is what a compiler
that is not gcc should do with them.

**The `L` test is kept and is not the precedence slip it looks like.** The old
condition was `(A && B) || C` with `C` evaluated whatever `A` said; it reads
like a misplaced paren and the *effect* was right, since `L"f.h"` is not a
file name in any form of the directive. It is explicit now rather than left to
be re-read as a bug.

`sys/lib/tests/cpp-linemarker.sh` is the instrument: 8 forms that must be
accepted, **4 that must still be refused** — a one-line "accept anything after
the number" passes section 1 and is wrong — and a third section asserting the
position is still *recorded*, since a fix that skipped the whole tail would
leave the file name unset and pass the first two. **0 failures**, and its
control removes the flag-skipping loop and fires on **exactly** the 6 flagged
cases, leaving the other 10 passing.

***It is NOT a `cpp-xcheck.sh` case file, and that was tried first.*** That
harness diffs against `gcc -E -P`, and `-P` is precisely the flag that
suppresses line markers, while kencc's cpp has no `-P` and writes its own — so
a case file made of line directives differs **by construction, in every
line**, however correct both preprocessors are. *A comparison whose two sides
are asked different questions cannot be read*; the tell was that the diff was
100% noise rather than one line of signal. gcc also rejects `# N "f" 1 2 3 4`
("invalid flag 2"), which kencc now accepts — deliberate, since skipping is
cheaper than ordering rules for flags nothing reads.

No regression: `hideset-cases` and `ppnum-cases` still PASS, and
`--regress` over **400 real libap files** reports `same` for every one.

## Past `#line`, and the next one is an empty struct

`6c` now reaches the generated C and stops at
`syntax error, last name: _Z24mainEUliE_` — `main`'s `(int)` lambda. The
host `6c` reproduces it in one line, **message and identifier verbatim**:

```c
struct _Z24mainEUliE_ { };      /* syntax error, last name: _Z24mainEUliE_ */
struct _Z24mainEUliE_ { char __dummy; };   /* OK */
```

An **empty struct**, which C89 has not and kencc refuses. EDG writes one for
any class whose size is ≤ 1 — every captureless lambda's closure type and
every empty C++ class — and it is a target setting, not a compiler
limitation: `use_empty_struct_in_generated_c`. **Its other arm writes
`char __dummy;`**, which is what this corpus's own generated structs contain
on nearly every page. So the fix is upstream's own portable arm, one
assignment in `src/target.c`.

***And the target description is not what runs.*** `kencc_targ.h` already
said `GCC_IS_GENERATED_CODE_TARGET 0` while the baked `target.c` says **1** —
which is exactly where the gcc linemarker flags came from. Nothing reads that
header at run time; it documents what a *regeneration* would be told, and the
corpus was generated once with somebody else's answers. **Two rounds, two
places, one class.**

`sys/lib/tests/edgtarg-sweep.py` gates on it: 5 agree, **3 disagree (all
known, each with a reason)**, 10 not comparable, 18 not in `target.c`.

***Its first version reported two ABI disagreements that do not exist.*** It
said `TARG_ALIGNOF_POINTER` was 8 in the header and 4 in the baked target, and
the same for `TARG_ALIGNOF_LONG_DOUBLE` — either of which would mean every
struct EDG lays out is wrong. **Both were the regex taking the first of eight
assignments**: those variables are set once per *data model*, in arms chosen
at run time, and the first in file order belongs to a 32-bit one. *A rule
written from the examples in front of you fires on the next shape.* A name
assigned more than once is reported as **not comparable** and never counted —
**the finding it refuses to make is the one that would have been believed.**

The three real disagreements are not taken this round and say why:
`GCC_IS_GENERATED_CODE_TARGET` (clearing it moves attributes, builtin varargs
and the line-directive form at once, and the one consequence that bit is
handled in cpp instead), and `INSTANTIATE_EXTERN_INLINE` /
`INSTANTIATE_INLINE_VARIABLES` (link-model changes, and `eccp` already passes
`--instantiate local`). Its control flips a value that currently agrees and
requires exactly one new finding.

## Past the compiler, and the link wants mangled C names

```
main: undefined: _Z6wcslenPKw
main: undefined: _Z8iswalphaj
```

`wcslen(const wchar_t*)` and `iswalpha(unsigned)` — **C++-mangled**, because
`<wchar.h>` and `<wctype.h>` have **no `extern "C"` guard at all**, while
`<stdio.h>`, `<string.h>` and `<ctype.h>` do. A header without the guard is a
link error in C++ and nothing else: it compiles, it preprocesses, every C
program is unaffected, and a C++ call asks the linker for a name no C library
defines.

**Measured on the host by an A/B over one staged copy of the tree**, which is
sound here because the question is a *name* and names are what the two
compilers must agree on:

```
without guards : _Z6wcslenPKw  _Z7imaxabsx      ← the VM's error, to the digit
with guards    : wcslen        imaxabs
```

Guarded: `wchar.h`, `wctype.h`, `inttypes.h`.

***`stddef.h` was guarded too and should not have been.*** Its one declaration
sits inside `#ifndef __cplusplus` — C++ has `std::unreachable` and no
`_Noreturn`, and the header's own comment says so — so C++ never sees it, and
the guard put `extern "C" {` inside a conditional arm whose `}` was outside
it. **An unbalanced brace in the arm nobody compiles**, which is the worst
version of this to ship. Reverted, and the exemption is in the sweep.

`sys/lib/tests/apexternc-sweep.py` gates on it. **165 headers, 31 declare
functions with no guard**, and the gate is the set the C++ library actually
includes — every `c++/*.stdh` names its C headers — while the other **30** are
reported: `lua.h`, `libsec.h`, `mp.h`, `auth.h`, `f2c.h`, `termios.h`,
`uchar.h`, the `unistring` family. Whether C++ should see those at all is a
decision nobody has taken, and *a sweep that gates on a decision nobody has
taken is a sweep that gets switched off*.

***Its first run reported `stddef.h`*** — the one header the edit had just
proved needs no guard — because the not-C++ pattern was anchored at `^ndef`
and the keyword is `ifndef`, so it matched neither spelling. *A sweep whose
first run names a file you have just decided about is the cheapest possible
chance to catch it.* Its control strips the guard from a guarded,
C++-reachable header and requires exactly one new finding; it fires on
`ctype.h`.

## It works: 23 PASS, 1 FAIL, 1 GAP — and the FAIL is win64's `wchar_t`

`cxx-library-test` builds, links and runs. The one failure is
`std::wcslen(L"ape") == 3`, with `std::iswalpha` passing on the next line —
so it is not linkage but **width**.

***EDG's active target is win64, and win64's `wchar_t` is 2 bytes.***
`eccp:250` passes `--target win64` and its own header says the flag is not
optional; `target.c` has **one function per target**, and
`set_target_config_win64` bakes `targ_wchar_t_int_kind = ik_unsigned_short`
while `kencc_targ.h:195` says `ik_unsigned_int` and APE's `stddef.h:50` is
`unsigned int`. So cpfe built `L"ape"` out of 2-byte elements and libap's
`wcslen` walked it 4 bytes at a time. Every other size in that function
already matches APE — int 4, long 4, long long 8, pointer 8, short 2, long
double 8 — `wchar_t` alone did not.

**This is the third finding from one class** (after the gcc linemarker flags
and the empty struct): the baked target disagreeing with the committed target
description.

***And the sweep could not see it, for a reason that was my own mistake.***
It called ten names "not comparable" because each is assigned eight times —
right about the regex, **wrong about the file**. The eight are not arms of a
switch: they are `set_target_config_win64`, `..._linux_i686`,
`..._linux_aarch64` and five more — *one function per target, and exactly one
runs*. The sweep now reads the active target **from the driver** rather than
hardcoding it, because a sweep that hardcoded `win64` would go quietly wrong
the day `eccp` changed, which is this tree's whole complaint about
`kencc_targ.h` in the first place.

It also compares **integer kinds** now, not only numbers — the setting that
bit is `((an_integer_kind)ik_unsigned_int)`, and *a sweep that reads only
integers could not see the setting it was extended for*.

**15 agree → 19 agree, and 10 not comparable → 0.** Its external control is
the bug itself: putting `ik_unsigned_short` back makes the sweep report
`TARG_WCHAR_T_INT_KIND ... *** NEW ***` and exit 1. The deliberate-break
control still fires on `CLANG_IS_GENERATED_CODE_TARGET` with nothing else
moving.

The remaining `GAP` is `std::variant`, which is a name and not an
implementation — an empty class body upstream, nothing to test.

## Real applications: the gap list, measured on the host

`sys/src/external/c++` holds **unrar** and **re2c**, to replace the old C
versions. `hostkencc/cxxapp-host.sh` compiles a package's objects against
`sys/include/ape/c++` with `g++ -nostdinc++`, the same trick `cxxlib-host.sh`
uses, and **reports rather than gates** — these are ports in progress and a
gate would fail every run.

**unrar: 44 objects, 39 compile, 5 fail, and all five are library gaps.**

| gap | where | size of the job |
|---|---|---|
| `std::to_wstring` | 10 sites in `filefn`, `arcread`, `list`, `rar` | **small** — `string/to_string2.h` already has a generic `to_string2<t_string>`, so this is six inline wrappers over upstream's own machinery |
| `basic_string(InputIt, InputIt)` | `win32stm.cpp:240`, `std::string Src(v.begin(), v.end())` with `unsigned char*` iterators | the iterator-pair ctor SFINAEs out (`enable_if_bool_constant<false>`) and cascades onto the `(const char*, size_type, allocator)` overload |
| `<deque>` | `os.hpp` | **smaller than it looks**: unrar never names `std::deque` anywhere, so the header only has to exist — but shipping an empty one is the stub-that-answers-nothing family this tree calls its most common bug, so it is a decision rather than a patch |

**re2c wants 24 standard headers and ten are missing**: `cassert fstream
iomanip iostream ostream sstream` — the whole streams library, of which the
tree has **none** — plus `queue stack unordered_set valarray`. `queue` and
`stack` are adaptors and fall out once `deque` exists; streams are a project.
re2c also has no `OBJECTS` makefile (autotools, 3572 files), so the harness
says `NOT MEASURED` rather than guessing.

### Four things that made earlier runs of this read like results

Each is now in the harness so the next run cannot repeat it:

1. **The four cpfe predefines.** Without them every file dies on
   `__EDG_SIZE_TYPE__ does not name a type` and the run measures the harness.
   `cxxlib-host.sh` already knew them; my ad-hoc command did not.
2. **The include scan missed `.hpp`.** A first survey globbed
   `*.cpp -o *.h -o *.cc` and concluded *"unrar needs nothing we do not
   have"* — while every unrar header is `.hpp`. *A file-type list written
   from the examples in front of you misses the next extension.*
3. **Not every `.cpp` is a translation unit.** unrar `#include`s `arccmt.cpp`
   and `win32stm.cpp` into others, so compiling `*.cpp` reported **38
   failures that were all `wchar does not name a type` at line 1**. The
   object list comes from the package's own makefile — and the first parse of
   that took only the first physical line, 9 objects of 44, reported as a
   tidy "9 failed".
4. **The package's own `-D` set**, without which the platform arms are wrong
   and the errors are about Windows code.

And **missing headers are stubbed with the stub announced on stderr**: without
a stub the first absent header stops every file and the run says nothing about
what else is missing, which is the whole question; without the announcement it
would be exactly the silent-stub shape this tree keeps paying for.

Its control is external and will need re-pointing: the harness must still see
the known `to_wstring` gap, and **when that is fixed the control must be aimed
at the next one** — the honest cost of a control made of a real finding rather
than a planted one.

*That paragraph is kept as written because the very next round proved it
wrong in the cheapest possible way: `to_wstring` was added, the control
failed, and re-pointing it at another real finding would only have bought the
same expiry again. It asks structurally now — see the end of this file.*

## `to_wstring`: six wrappers, and a silent miscompile two layers under it

The user's direction after `cxx-library-test` ran was *"make sure the library
is capable of building real world applications"*, with unrar and re2c in
`sys/src/external/c++` as the two challenges, and *"do `to_wstring` first"*.

**What `to_wstring` itself cost is six wrappers**, because the implementation
was already in the tree: `string/to_string2.h` carries a generic
`to_string2<t_string>` over `base_to_string_converter`, which works for any
`basic_string` whose `value_type` has a `unicode_helper` — and `wchar_t` has
one. So `string/to_wstring.h` is six `inline` forwarders and
`string.stdh` includes it.

### "Already there" was too strong until it was compiled

A grep for `to_string2` over the whole library found **the file and no
user**. Compiling it for the first time:

    convert.h:122: error: 'uint32_t' does not name a type

Three unqualified uses, inside `namespace std`, with nothing declaring
`::std::uint32_t`. One `#include "../common/uint32_t.h"`. *This tree's own
rule about a change that makes code reach code nothing reached before,
arriving on the first command rather than three rounds in.*

### Six overloads and deliberately no float

[string.conversions] gives `to_wstring` nine overloads, the last three
specified as if by `swprintf(..., L"%f", val)`.
`base_to_string_converter`'s floating-point specialisation **works** — it was
run on the host first: `1.5` → `"1.5"`, `0.125` → `"0.125"`, `-1.5` →
`"-1.5"`, `1e20` → `"100000000000000000000"`.

**But `%f` on 100.0 is `"100.000000"` and that converter answers `"100"`.**
Shipping it under the standard's name hands every caller a different string
from the one the standard promises, which is this tree's most common bug
class. The float forms are **absent**, where a caller gets a compile error
naming them; `to_string` has no float overload either, so the two stay
symmetric; and `to_string2<t_string>(double)` is reachable by name for anyone
who wants shortest-form output on purpose.

The six are six for an ABI reason and not for tidiness: kencc is LLP64, so a
`size_t` argument binds `unsigned long long` here and `unsigned long` on an
LP64 host. A set missing either would compile on one and not the other.

### ***AND THEN IT PRINTED THE WRONG STRING***

    std::wstring(L" -md=") + std::to_wstring(3)
      ->  0020 002D 0000 0000 0000 0033        (" -\0\0\0" "3")

Five elements asked for, **five BYTES copied** — one element and a quarter,
the rest left as the zero fill. **Six sites in the library pass an element
count where `memcpy`/`memmove`/`memset` want bytes:**

| file | function | call |
|---|---|---|
| `basic_string.h` | `insert(index, sv)` | `memcpy`, count unscaled |
| | `erase(index, count)` | `memmove`, count unscaled |
| | `append(sv)` | `memcpy`, count unscaled |
| | `replace(pos, n, sv)` | `memcpy`, count unscaled |
| | `replace(pos, n, n2, ch)` | `memset` — see below |
| `short_object_optimization.h` | `replace(...)`, PRIMARY template | `memmove`, count unscaled |

***EVERY ONE IS CORRECT FOR `char`.*** `sizeof(char)` is 1, so nothing
reachable through `std::string` can show it — which is why the whole library,
`cxx-library-test` and `cxxlib-host.sh --instantiate` were green while
`std::wstring` silently corrupted itself on insert, erase, append and
replace. **The library's own neighbours scale theirs**: `insert` nine lines
above the broken `replace` says `* sizeof(value_type)`, and so do both
`memcpy`s in `reserve`.

**The `memset` one is a type bug and not an arithmetic one.** `memset` writes
one byte per unit whatever the count, so `replace(1, 2, 3, L'Q')` put
`0x00515151` in the first element and nothing in the other two. Scaling its
count would not have fixed it; `traits_type::assign(ptr, count, ch)` is the
per-element fill every char_traits specialisation here already provides.

### Two more that look like the same bug and are not

`short_object_optimization.h` holds **two** classes: a primary template and a
`sizeof(value_type) == 1` specialisation. The specialisation carries the same
`replace` line, and its copy constructor wrote

    memset(&temp.get()[size() * sizeof(value_type)], 0, 1);

an index that is scaled and a width that is not — which reads exactly like
the bug above, and **is correct by construction there**, because that class
only ever serves a one-byte type. Both were changed to match the primary
template so the two read the same, and **they are not findings**. *The first
draft of the test's header counted eight bugs; the specialisation condition
is one line above the class and says so.*

The consequence for the test: a case that goes through the specialisation can
never fail, so its `char` section is a control **by construction** and not
merely by intent.

### The instrument, and what its two controls each catch

`sys/lib/tests/cxx-wstring-test.cpp` — the eight mutators once per character
type (`char`, `wchar_t`, `char16_t`, `char32_t`), the six `to_wstring`
overloads, and the four spellings unrar actually writes.

* **Subject**: 0 failures.
* **Reference**: every assertion is a standard-library rule, so
  `g++ -std=c++14 -DREFERENCE` builds it against libstdc++ — **0 failures**,
  which is the strongest control available here and costs one flag.
* **Control**: the pre-fix headers out of git give **21 failures**, all ten
  `char` cases passing.

***EVERY CASE MUST CROSS THE SHORT-STRING BOUNDARY FOR AT LEAST ONE TYPE OR
IT PASSES AGAINST THE BROKEN LIBRARY.*** The SSO buffer is 23 **bytes**, so
it holds 23 `char` and only **5** `wchar_t`: a case sized to look reasonable
for `char` never reallocates. The first draft's `append` case passed against
the broken library for exactly that reason while `+=` on the same data
failed — *and both are kept, because the one that passes is what made the
rule visible.*

The control's own coverage is honestly short in one place: `wchar_t`'s
`append` case passes either way, so that site is caught through `+=` for
`wchar_t` and directly for `char16_t`. The `copy of a heap string` cases pass
both ways and cover nothing — they are legitimate assertions and are not
claimed as coverage.

### unrar: 39 of 44 → 42 of 44

`to_wstring` cleared `filefn.cpp`, `arcread.cpp` and `list.cpp`. What is
left:

* `basic_string(InputIt, InputIt)` — `win32stm.cpp:240` is
  `std::string Src(v.begin(), v.end())` with `unsigned char*` iterators, and
  the iterator-pair constructor SFINAEs out
  (`enable_if_bool_constant<false>`, then a cascade onto the
  `(const char *, size_type, allocator)` overload).
* **The exception hierarchy is TEMPLATES.**
  `template<class = void> class length_error : public logic_error<>`, so
  `catch (std::length_error&)` — `rar.cpp:95`, and what every real program
  writes — does not compile; g++ even offers C++17 CTAD as the explanation.
  Upstream's reason is visible and good: a template member `what()` needs no
  `.cpp`. They also have **none of the standard's `(char const *)`
  constructors**, so `throw std::length_error("too long")` is out too.
* `<deque>`, which unrar includes in `os.hpp` and never names.

*The harness was built to name missing NAMES, and what the first one was
worth was a silent miscompile two layers underneath one.*

### `cxxapp-host.sh --control` is structural now

Its first version required the harness to still report `to_wstring` as
missing. `to_wstring` was added, the control failed, and **what it was
reporting was a success** — and the next reader cannot tell "fixed" from
"harness broke", which is what a control is for. It now asks two structural
things: that at least 35 of unrar's 44 objects compiled (a run that compiles
nothing reports a tidy `0 failed`), and that it still produced a report with
the gaps named. **Measured both ways**: it passes at 42, and with `EDGDEF`
emptied it reports `0 compiled, 44 failed` and fires.

### A pre-existing failure found while regression-testing, and it is NOT this

`cxxlib-host.sh --instantiate` reports **`***CONTROL PASSED, WHICH IS A
FAILURE.***`** — the pre-fix `split_buffer.h` staged out of git instantiates
cleanly, so that mode is not asking what it claims. **This was already true
before any change here**, measured by stashing the whole diff and re-running:
same message. Recorded in 0.6's inventory; not fixed in the same round as a
change to the same library.

## `<stdexcept>`: two faults, and the first one hid the second

unrar's last-but-one failure was `rar.cpp:95`,
`catch (std::length_error &)`, and what it turned out to be is two
independent things in the same place.

**(1) EDG ships `<stdexcept>` empty.** `stdexcept.stdh` is
`namespace std { }` with nothing between the braces; EDG's runtime
(`lib_src/`) supplies `exception`, `bad_alloc` and `type_info` and
nothing else. unrar's `os.hpp:16` is literally

    #include <stdexcept> // For std::length_error.

and it compiled — because `<vector>` drags `language_support/length_error.h`
in by another route. ***A HEADER THAT ANSWERS AN INCLUDE AND DECLARES
NOTHING IS THE STUB-THAT-SAYS-NOTHING FAMILY, ONE LAYER UP FROM A
FUNCTION*** — and the reason it survived a whole port is that the name
arrived anyway, by accident, from a header nobody asked.

**(2) portable_stl's four were templates.**
`template<class = void> class length_error : public logic_error<>`, and
`logic_error`, `out_of_range` and `bad_function_call` the same, so
`catch (std::length_error &)` is *invalid use of template-name without an
argument list* — with g++ offering C++17 CTAD as the explanation, which is
the wrong lead.

### The fix is a rename and an alias, and upstream's reason is kept

A template member `what()` can be defined in a header with no `.cpp` and
no COMDAT question, which is exactly what lets this library stay
header-only. **That is a good reason and the whole point of the shape**, so
it stays: each class becomes `length_error_impl<>` with
`using length_error = length_error_impl<>` beside it. Making them ordinary
classes with inline virtuals would put the vtable and the typeinfo in
COMDAT — a question about the **link model**, where `cmd/edg/mkfile`
already passes `-C` and `--instantiate local` does not touch typeinfo —
and that deserves its own round rather than a ride on this one.

The derivations are preserved by deriving each `_impl` from the **alias**
of its parent, so `length_error_impl<>` has base `logic_error`, which is
`logic_error_impl<>`.

**Six of the nine did not exist in any form**: `runtime_error`,
`domain_error`, `invalid_argument`, `range_error`, `overflow_error`,
`underflow_error`. `stdexcept.stdh` now includes all nine;
`bad_function_call` got the same rename and stays out of it, being
`<functional>`'s.

The cost is that `::std::length_error<>` is no longer valid. The library
spelled it that way at 30-odd sites and they were updated with it; the
pristine vendor copy under `sys/src/external/paragon_portable_stl/` is
untouched.

### `cxx-stdexcept-test.cpp`, and the section that constrains the design

***SECTION 2 IS THE HALF THAT WOULD HAVE CAUGHT THE OBVIOUS
SHORTCUT.*** The cheap way to write ten exception classes is one template
and ten aliases of it — which gives ten **siblings**, passes every line of
section 1, and fails every line of section 2, because
`catch (std::logic_error &)` then does not catch a thrown
`std::length_error`. [stdexcept.syn] fixes those derivations and real code
leans on them.

**The file includes only `<stdexcept>`, and that is fault (1)'s regression
test.** It cannot be written as an assertion: if `<stdexcept>` alone does
not declare these names, the file does not compile. Hence `strcmp` rather
than `std::string` in section 3 — *pulling in `<string>` would reintroduce
exactly the second route that hid the bug.*

Three arms:

* **Subject** — 0 failures.
* **Reference** — libstdc++, 0 failures. ***The `MK` macro is a recorded
  deviation and not a convenience***: the standard gives these a
  `(char const *)` constructor and **no** default constructor, and
  portable_stl's have only a default one, so the reference arm says
  `T("message")` where the subject says `T()`. The two arms therefore ask
  the same question about the **names and the hierarchy**, which is what
  the file is for, and not about construction.
* **Control** — the pre-fix headers staged out of git: **it does not
  compile**, 42 errors, the first `'logic_error' is not a member of
  'std'`. So the control is a compile failure rather than a failure count,
  and *a run that prints nothing is the expected result rather than a lost
  measurement.*

**Also built without `--no_exceptions`**, which `eccp` passes by default:
the file is `throw` and `catch` and nothing else, so a build that drops
exceptions measures the driver. If `eccp` refuses, that refusal is the
result.

### unrar: 42 of 44 → 43 of 44

The one left is `extinfo.cpp`, and reading it turned up a third class
rather than a one-line fix. `basic_string`'s iterator-pair constructor
is

    : basic_string(::std::to_address(first),
                   static_cast<size_type>(::std::distance(first, last)), allocator)

— it takes the **address** of the first element and copies a block. So it
compiles only for an iterator whose `value_type` is exactly `value_type`
(unrar's is `unsigned char *` into a `basic_string<char>`, a perfectly
legal conversion that this cannot express), and ***for a NON-CONTIGUOUS
iterator it would be silently wrong rather than rejected***: `to_address`
on a `list` iterator answers the address inside one node, and the copy
then reads whatever follows it. The guard admits `input_iterator_tag`, so
the implementation promises more than it can do. `append(first, last)`,
`insert(pos, first, last)` and the `make_string` form are the same
expression. *Not fixed in this round*; it wants a real loop and a test
over a non-contiguous iterator, which is its own piece of work.

## The iterator-pair overloads copied a block, and unrar builds clean

unrar's last failing object was `extinfo.cpp`, and the line is
`win32stm.cpp:240` (included into it):

    std::string Src(v.begin(), v.end());   // v is vector<unsigned char>

`basic_string`'s iterator-pair constructor was

    : basic_string(::std::to_address(first),
                   static_cast<size_type>(::std::distance(first, last)),
                   allocator)

and `make_string` and `append(first, last)` said the same thing — it takes
the **address** of the first element and copies a block. Two faults, and
***THE ONE THAT PRODUCED A DIAGNOSTIC IS THE LUCKY ONE.***

**(a) It compiles only for an iterator whose `value_type` IS the string's
`value_type`.** `unsigned char` converts to `char` perfectly well;
`to_address(first)` hands over an `unsigned char *`, which does not. The
overload SFINAE'd out and the diagnostic then named
`(const char *, size_type, allocator)` — *not the constructor anybody
wrote*, which is why it read like a missing overload rather than a broken
body.

**(b) For a non-contiguous iterator it was silently wrong.** `to_address`
on a `list` iterator answers the address of the element inside one node,
and the copy then read `distance` elements of whatever followed that node.
The guard admits `input_iterator_tag`, so **the implementation promised
far more than it could do** — and nothing in this tree had ever handed a
string a non-contiguous range, so there was no symptom.

### The fix, and the one thing that constrains it

A per-element loop, with the reserve **tag-dispatched** on
`has_forward_iterator_category`. That dispatch is the whole design
constraint: the obvious implementation calls `distance(first, last)` to
reserve and then loops, which reads the range **twice**, and a single-pass
input iterator cannot be read twice. `M_reserve_for_range` therefore has a
`true_type` arm that measures and a `false_type` arm that does not.

**The block-copy fast path is deliberately not kept beside the loop.** It
would need a trait for "contiguous AND the same character type", and *a
wrong fast path here is silent* — which is the half of this bug that cost
nothing to find only because nobody had triggered it. `append(1, ch)`
re-enters `reserve`, which returns early once the capacity is there, so
the loop is a byte-at-a-time copy and not a quadratic one.

### `cxx-striter-test.cpp`, and why its control had to be split

Three sections, three different questions: a converting `value_type`
(fault (a), unrar's own line); a `list` range (fault (b), **the only
section that could ever give a wrong ANSWER rather than a wrong
diagnostic**); and a hand-written single-pass iterator with no
`operator->` and no `operator-`, so `to_address` could not even be applied
to it and a two-pass implementation cannot compile against it. *Without
that third section the tag dispatch would be dead code nothing ever took.*

* **Subject** — 0 failures. **Reference** (libstdc++, `-DREFERENCE`) — 0.
* ***The control is split and it has to be.*** Against the pre-fix headers
  the whole file **does not compile** — 19 errors — so a failure count is
  not available that way. Built with `-DCONTROL_SECTION2_ONLY`, which
  drops the two sections that need the fix in order to compile, it
  compiles and reports **3 failures**, and the output is the finding:

      want "a list is not a block, and this payload is well past ..."
      got  "a.......!.......\373";]\360U...#;]\360U.. ......."

  the first element, then 66 bytes of whatever followed that list node, at
  the right length. *A control that could only say "it did not build"
  would have left the silent half of this bug resting on a reading.*

### unrar: 44 of 44, and the fourth gap is fixed in unrar

`<deque>` was the last one, and it is **smaller than it looks**: `deque`
appears nowhere else in the package — not one `std::deque`, not one
mention outside the single `#include` in `os.hpp`. So the include is
dropped, with the reason in a comment beside it, rather than shipping a
`<deque>` that declares nothing — ***which is precisely what EDG's empty
`<stdexcept>` did to this port, and it cost a whole campaign before
anybody noticed.*** A real `deque` is a library decision and is in 0.6's
inventory.

**The walk is worth more than the number:**

| | gap | whose |
|---|---|---|
| 39 → 42 | `std::to_wstring`, and six silent miscompiles under it | library |
| 42 → 43 | `<stdexcept>` empty, and its classes templates | library |
| 43 → 44 | the iterator-pair overloads copying a block | library |
| 44 | `<deque>`, unused in unrar | unrar |

***Every one of the four was the library's*** (the fourth being an unused
include rather than a gap at all), which is the result the harness existed
to get. **And two of the four were SILENT, which a compile-only harness
cannot see by itself**: it named the loud half and
`cxx-wstring-test.cpp`/`cxx-striter-test.cpp` found the rest. *A package
that COMPILES has not been shown to RUN* — the same rule as "a header that
compiles is not a template that instantiates", one level up.

**What is still not measured**: the link, the C side (these compile
against the host's `<unistd.h>`), cpfe's own acceptance, and anything at
run time. There is no unrar mkfile for Plan 9 yet.

### `cxxapp-host.sh --control`, expiring for the second time

Its first version required the harness to still report `to_wstring`
missing; `to_wstring` was added and **what it reported was a success**. It
was re-pointed at a structural pair — a compile floor plus "a gap is still
named" — and ***the second half expired one round later, exactly as its
own comment said it would***: unrar reached 44 of 44 with no header
stubbed, so there was no gap left to require, and the control printed its
"this may be good news" branch and exited 1.

It asserts the **measured state** now: 44 objects, 0 failures, no stubbed
header, with `>=` on the count so a new unrar object does not trip it.
Verified both ways — it passes at 44, and with the cpfe predefines emptied
it answers `0/44` and fires. *A control made of a finding expires when the
finding is fixed; the honest move each time is to re-point it at what is
now true rather than to loosen it, and what is now true here is a result,
so the control has become a regression gate on it.*

### re2c has not moved, and the reason is two things

`--headers` says it wants 24 and is missing **ten**: `cassert fstream
iomanip iostream ostream queue sstream stack unordered_set valarray`.
`unrar` is now `wants 6, missing 0`. And re2c has **no `makefile`** for
the harness to read an object list out of — only `Makefile.in` with
autoconf substitutions and a `CMakeLists.txt` — so even with the headers
it could not be measured as it stands. *The streams family is the large
part of the ten and is a decision rather than a patch*: de novo headers,
or a copy from LLVM libc++ the way musl was copied into libap — and copied
`.cpp` files would need a `libc++` mkfile after `edg`, plus probably a
`sys/src/ape/c++` for things that need C++ built first.

## `sys/src/ape/c++`: unrar gets an mkfile, and there is no `libc++`

The direction: *"Create an mkfile for c++ unrar in sys/src/ape/c++/unrar
and if we need .cpp files and a libc++, create those files and mkfile in
sys/src/ape/c++/libc++."* So the first question is whether a `libc++` is
needed at all.

### It is not, and that is measured rather than read

All 49 of unrar's translation units were compiled to **real objects** on
the build host and `nm -u` taken over them, minus what they define
themselves — the `php-mirror.sh --undefined` idiom. **125 external names,
16 of them C++-mangled:**

    _ZNSt9bad_allocC1Ev  C1ERKS_  D1Ev     std::bad_alloc
    _ZNSt9exceptionC2Ev  D2Ev              std::exception
    _ZTISt9bad_alloc  _ZTISt9exception     their typeinfo
    _Znwm _Znam _ZdlPv _ZdaPv (+sized)     operator new / delete
    _ZTVN10__cxxabiv1{16__enum,17__class,20__si_class}_type_infoE

The first four groups are **`libedg.a`**, which `sys/src/ape/lib/edg`
already builds from EDG's own lowered runtime. The three `__cxxabiv1`
vtables are **gcc's ABI and not cpfe's**, so they are a host artefact.
And `sys/include/ape/c++` is header-only by construction — upstream's
`CMakeLists.txt` has no `install()` rule because the headers *are* the
product.

***So nothing in the C++ library needs compiling, and the place for a
`libc++` is named in `sys/src/ape/c++/mkfile` against the day the LIBRARY
grows a `.cpp` — not because an application asked for one.***

The other 109 are plain C, and `apfunc-sweep.py` answers them: **29
defined, 2 declared-only, 1 absent** over the interesting subset, and
***all three of the non-`defined` answers are the sweep being right about
a function and wrong about availability***:

* `lchown` — `<unistd.h>:147` is `#define lchown chown`. Plan 9 has no
  POSIX symlink ownership, so that is the honest answer, and it is a
  MACRO, which the sweep cannot see.
* `towlower`/`towupper` — `<wctype.h>` declares them at `:38-39` **and
  `#define`s them at `:54-55`** to libutf's `tolowerrune`/`toupperrune`.
  A plain call gets the macro.

*That is a fourth state the sweep's three cannot express: a header that
declares a function and then `#define`s the name over it.* Its
`declared-only` is meant to be the alarming one — the state that costs a
link — so a false alarm there is worth recording. The host's own
`towupper` undefined symbol is glibc declaring it as a function; under
APExp there is no such reference at all.

### What the mkfile is waiting on is exceptions

***unrar IS THE FIRST THING IN THIS TREE TO NEED C++ EXCEPTIONS.***
`unpack.cpp`, `model.cpp` and `unpack50frag.cpp` each
`throw std::bad_alloc()`, and `rar.cpp:90`/`:95` catch `std::bad_alloc &`
and `std::length_error &` — **those two catches are the out-of-memory
path**, so a build with exceptions off would compile and then terminate
where it should report a corrupt archive.

`eccp` passes `--no_exceptions` by DEFAULT and says why: EDG itself is
built `-fno-exceptions -fno-rtti`, so that is the only configuration this
port has exercised, and `lib_src`'s setjmp-based EH **has never been
run**. The mkfile passes `-fexceptions`, so a failure there is a result
and not a blocked build — and the instrument already exists:
`cxx-stdexcept-test.cpp` is `throw` and `catch` and nothing else, and its
section 2 asserts exactly what unrar depends on, that
`catch (std::logic_error &)` catches a thrown `std::length_error`. *It was
written one round earlier for a different reason and answers this question
in isolation.* RTTI stays off; `--no_rtti` disables `typeid` and
`dynamic_cast`, which unrar uses nowhere, and catching by base is the EH
machinery's own type matching.

### `eccp -c` could not be used in a pattern rule at all

Two faults, and ***only a SEPARATE COMPILE could show either***:
`eccp -o prog x.cpp` is internally consistent however the intermediates
are named, because the same script computes the object names it then
links. `eccp -c` hands them to someone else.

1. **The object was named after the generated C.** `objs` was
   `basename $gen .c`^`.o` with `$gen` = `<stem>.eccp.c`, so
   `eccp -c foo.cpp` produced **`foo.eccp.o`**. No mkfile can write
   `%.o: %.cpp` against that — and `-o` was accepted and then **ignored**
   whenever `-c` was given.
2. **The generated C was written beside the source.** `stem` keeps the
   directory, so `eccp -c ../../external/c++/unrar/rar.cpp` dropped
   `rar.eccp.c` into `sys/src/external`, which a build must not write to
   and which no `clean` rule here would remove. `cc -c` then put the
   object there too, since `pcc.c:457` derives it with `changeext` from
   the input path.

gcc's rule is the one to follow and is what it does now: `-c` writes the
object into the **current** directory named from the source's basename,
`-c -o path` names it exactly, and the generated C goes beside the object.
`-c -o` with more than one input is **refused** rather than writing them
all to one name, which is what `pcc` itself would do (one `oname` reused
for every source, `pcc.c:454`). *`pcc` does support `-c -o`*
(`pcc.c:453-457`), which is what makes this possible at all.

### Why not `mkone`, and why its own directory

`mkone`/`mkmany` drive `$CC`/`$LD` over `%.$O` — `.6` on amd64, `.8` on
386 — and `eccp` produces `.o` on **every** architecture, because
`sys/src/ape/9src/cc.c` is one line including `pcc.c` and `pcc.c:75` picks
the extension from the name it was invoked under. So the object suffix
here is architecture-independent and `$O` is the wrong variable; five
hand-written rules say so.

`sys/src/ape/c++` is its own directory rather than a few more entries in
`cmd/mkfile` because a C++ program needs cpfe **and** `libedg.a` **and**
the header set: putting one in `cmd/mkfile` would make the order of that
file's app list load-bearing, and that list is a list — the tree's own
note says it is read rather than recalled, which is the opposite of what
you want an ordering invariant hiding in. It sits last in the top-level
`DIRS`, and ***its own `DIRS` is EMPTY***: one failing entry aborts the
whole tree's `mk`, and a port built only by hand has not been measured in
that position. *The dispatcher goes in before its first port rather than
with it, so neither is unattributable.*

### And 44 was the harness, not the package

***THE FIFTH HARNESS FAULT, AND THE SAME SHAPE AS THE OTHER FOUR.***
`cxxapp-host.sh` read `OBJECTS=` while the makefile's link rule is

    unrar:	$(OBJECTS) $(UNRAR_OBJ)

so five files — `filestr recvol rs scantree qopen` — had **never been
compiled**, and `-DUNRAR` had never been passed either, because that
arrives as `-D$(WHAT)` in the compile rule and not through `DEFINES=`.
All five compile and the define changes nothing, so the finding is about
the harness — *but a clean 44 was being read as "the package builds", and
it was not the package.* **49 of 49 now**, and the control's floor with
it.

*A variable named `OBJECTS` in a makefile that has a second object
variable is a trap the name itself sets*, and the only place that cannot
lie is the rule that builds the program. The rule is found by the
package's own name, every `$(VAR)` in its prerequisites is expanded, and
`OBJECTS` alone is the **fallback, announced when taken** — a silent
fallback to the old behaviour is the bug coming back. Measured: with the
`unrar:` rule renamed, it prints the fallback line and reports 44.

**And the two readings of that list are now required to agree.** The
mkfile writes `OFILES` out by hand, so it and the harness are two
derivations of one thing; `--control` fails if they differ, which is the
shape `gd-xcheck.sh` already gates on. Controlled by planting one extra
entry: it fires, naming the difference in both directions.

### What is NOT measured

The link, the C side (these compile against the host's own C headers),
cpfe's own acceptance, and anything at run time. **Nothing here has been
through `mk` or `eccp`** — there is no rc and no mk on the build host, so
the two mkfiles and the `eccp` change are checked by `rceq-sweep.py`,
`mkcont-sweep.py` and reading. The old C `sys/src/ape/cmd/unrar` (one
file, pre-2.71) and `sys/src/external/unrar` stay until this one runs.

## The first `mk install`: `.o` was the wrong suffix, and `va_copy` is open

Two things came back from the VM, and only one of them is settled.

### `.$O` and not `.o`, and the reason is cross-compilation

***`.o` IS THE SAME NAME ON EVERY ARCHITECTURE, AND THAT IS THE
PROBLEM.*** Plan 9 names an object after what it was compiled **for** —
`.6` amd64, `.8` 386, `.5` arm — so one source directory can hold several
targets' objects at once and `mk` tells them apart. `.o` cannot: a cross
build after a native one reads whichever `rar.o` is there, and the link
either fails on the exec header or does not. *Nothing in that message is
about architectures*, which is this tree's recorded shape for
`bash/mkfile`'s `LD`.

`eccp` ran `cc` rather than `pcc` **precisely to get `.o`**, and said so
in its own note 4: `sys/src/ape/9src/cc.c` is one line including `pcc.c`,
and `pcc.c:75` is
`objext = (strcmp(prog,"cc")==0) ? "o" : ot->o` — one binary, and the
name it is invoked under chooses the extension. Under `cc` that is `.o`
everywhere, so the driver needed no objtype-to-suffix table.

**That trade is paid off by last round's own change.** Since `-c` now
names the object with `-o` explicitly, the extension is the script's
choice rather than the driver's — so it can be the right one. `pcc` now,
and the suffix is read from `/$objtype/mkfile`'s `O=` line, *the same
place mk reads it*: deriving it from the authority rather than
transcribing an eleven-entry table, the same rule as `cxxapp-host.sh`
taking its object list from the link rule.

The argument parser accepts `*.o *.a *.[1-9kqv]` — the ten compilers'
suffixes as a class rather than `*.`^`$OBJEXT`, so a link of objects
built for this target is recognised whatever `$OBJEXT` says, and `.o`
stays because that is what every object this driver made before today is
called.

### `va_copy` is undefined under cpfe, and reading cannot say why

`strfn.cpp:538` stops the build:

    identifier "va_copy" is undefined
      va_copy(argscopy, arglist);

***`va_list` ON THE LINE ABOVE IS FINE***, and so are `va_start`,
`va_arg` and `va_end` elsewhere in the same file. So a `<stdarg.h>` was
found and read — cpfe would otherwise have said `cannot open source
file` — and the one it read defines everything except `va_copy`.

**Every reading of the tree says that cannot happen.**
`amd64/include/ape/stdarg_arch.h` *does* define `va_copy`;
`amd64/include/ape/stdarg.h` and `sys/include/ape/stdarg.h` both chain to
it; `mount-include` binds all of them into place and `apexp-sh` runs
`mount-include`; nothing in `sys/include/ape`, `sys/include/ape/c++` or
EDG's `include_c++` defines `__STDARG` or ships a second `stdarg.h`; and
unrar reaches the header through `os.hpp:148`, inside the `_UNIX` arm
that `raros.hpp:23` turns on for any non-Windows target. *That is the
point at which this tree's own rule says to stop reading and ask the
machine.*

`sys/lib/tests/cxx-stdarg-probe.cpp` asks it. Two candidate mechanisms,
and the probe separates them:

* **cpfe read somebody else's `stdarg.h`** — stock 9front's, which keeps
  it in the architecture directory and has no `va_copy`. APExp's own
  header comments record that stock file taking the same `__STDARG`
  guard, which is how it once *disabled* APExp's. Then `__STDARG` is
  defined and `va_copy` is not.
* **cpfe read no `stdarg.h` at all** and the other four names came from
  its own builtins, which EDG front ends have. Then `__STDARG` is not
  defined. *This is the weaker of the two*: cpfe predefines
  `__builtin_va_list`, not `va_list`.

`--trace_includes` (cpfe has it, `src/cmd_line.c`) names the file
outright and settles it in one command; `--list_macros` says what is
defined rather than what ought to be. **And the C side splits the answer
in half**: `pcc` searches the same two header roots in the same order, so
C right and C++ wrong is cpfe's, both wrong is the header or the bind —
and the second would be the more interesting, since it would have been
true for every C program all along and nothing has needed `va_copy`
before.

***AND THIS IS `cxxapp-host.sh`'s STATED LIMIT BITING FOR THE FIRST
TIME.*** Its header says it is not sound for "the C side — these compile
against the HOST's `<unistd.h>` and friends, not APE's". glibc's
`<stdarg.h>` has `va_copy`, so all 49 files compiled clean on the host
and will go on doing so. *A harness that compiles a package against a
different C library has measured the C++ and nothing else*, and the limit
was written down a round before it cost anything — which is the only
reason this was one line to recognise rather than a round to find.

**The probe's own fault, caught before it shipped**: its `PROBE_` dump
lines are not valid C++, so a plain compile of the file reported six
errors of the probe's own making instead of reproducing unrar's one.
They are behind `-DCXX_STDARG_PROBE_DUMP` now, so `-F` dumps and a
compile reproduces. *A probe whose own syntax is the first thing to fail
cannot report anything about its subject.* Found with
`g++ -fsyntax-only`, and the bracketed subjects (`[va_copy(dst, src)]`)
come from the same host run: gcc splits an expansion across lines, so
verbatim-versus-expanded has to be readable without whole-line matching.
