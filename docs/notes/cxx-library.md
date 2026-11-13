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
