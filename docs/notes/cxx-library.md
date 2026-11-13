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
