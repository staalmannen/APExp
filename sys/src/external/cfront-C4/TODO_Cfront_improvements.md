This is a great question, and having worked through every corner of this codebase I have a clear view of what's realistic versus aspirational.

## What cfront-3 already handles well

Cfront 3.0.3 (1994) covers a surprisingly large subset of C++:

- Classes with single and multiple inheritance, virtual functions, vtables
- Operator overloading, constructors/destructors
- Templates (class and function) — this was new in cfront-3 and works reasonably well for non-complex cases
- References, `const`, `inline`, default arguments
- `new`/`delete`, exception-style error handling via `setjmp`/`longjmp` (not try/catch)
- Most of the C++98 type system

## The realistic gaps and how to fill them

**1. Exceptions (`try`/`catch`/`throw`) — highest value**

Cfront has *no* exception support. This is the single biggest blocker for modern C++ code. The cleanest approach is to add a preprocessing pass that transforms exceptions into `setjmp`/`longjmp` chains — the same model cfront uses internally for its own error handling. The generated C stays portable. Libraries like `cexcept` provide a template. This is maybe 2,000 lines of new translation code in the parser (`y.tab.c`/`gram.y`) plus a runtime helper.

**2. Namespaces — medium value, surprisingly tractable**

Cfront predates namespaces entirely. But the translation is mostly mechanical: `namespace foo { ... }` becomes nothing (stripped), and `foo::bar` becomes `foo__bar` in name mangling — which is already exactly what cfront does for class scoping. The main complexity is `using` declarations and ADL (argument-dependent lookup). A preprocessing pass could handle 90% of real-world namespace usage.

**3. The C++ standard library — separate problem**

Cfront has its own ancient `libC` (streams, etc.). For modern code you need `<string>`, `<vector>`, `<iostream>` etc. The cleanest path: provide C implementations of the most-used subset. `std::string` → a simple refcounted char buffer, `std::vector<T>` → a `Block<T>` (which cfront already generates internally). This is a lot of work but very separable from the compiler itself.

**4. `bool`, `wchar_t`, `long long` — already partially handled**

The `-U__GNUC__` flag already enables `enum bool { false, true }` in cfront. `long long` exists in some cfront-3 builds. `wchar_t` needs a `typedef`. These are one-liners.

**5. RTTI (`dynamic_cast`, `typeid`) — low priority**

Very hard to retrofit and rarely needed for the kind of systems code you'd port to Plan 9. Skip.

**6. Nested class definitions and local classes — moderate**

Cfront handles these but has some known bugs. Worth fixing as they come up rather than proactively.

## The most pragmatic path for Plan 9/APE specifically

Given that Plan 9's own C++ usage is essentially zero, the real goal is probably to translate specific C++ codebases (compilers, tools, maybe LLVM subset) to C for Plan 9. For that I'd prioritize in order:

1. **Fix the LLP64 `unsigned long` → `size_t` issue** in `alloc.c` — one afternoon of work, prevents future surprises
2. **Add namespace stripping** — handles probably 80% of post-1998 C++ headers
3. **Add exception translation** — unlocks the remaining 20%
4. **Test against a real target codebase** — nothing reveals gaps like trying to translate something specific

The exception translation is the one I'd spend the most time on — it's the difference between "handles toy examples" and "handles real software."
