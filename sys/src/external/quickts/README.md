# quickts

[QuickJS](https://bellard.org/quickjs/) that parses TypeScript and JSX
directly. No transpiler, no generated source, no source maps: the parser
erases type syntax as it goes, lowers the handful of constructs that need
code (enums, parameter properties, JSX) straight into bytecode, and reports
errors against the original `.ts` line.

```sh
$ cat hello.tsx
enum Mode { Draft, Live }
interface Props { title: string; mode?: Mode }
const Card = ({ title, mode = Mode.Draft }: Props) => <card mode={Mode[mode]}>{title}</card>;
console.log(JSON.stringify(Card({ title: "hi" })));

$ ./qjs hello.tsx        # needs a JSX factory in scope, see "JSX" below
{"type":"card","props":{"mode":"Draft","children":"hi"}}
```

This is upstream QuickJS (release 2026-06-04) plus a few commits. Every
upstream file is untouched except for the small set of insertion points
listed under [How it is wired in](#how-it-is-wired-in); the implementation
lives in three new headers. The intent is that `git merge upstream/master`
keeps working forever, so the TypeScript support rides along with each new
QuickJS release. See [Merging upstream](#merging-upstream).

It was built for [FrameOS](https://github.com/FrameOS/frameos), where scene
apps ship as `.ts` and run on ESP32 boards with a couple of megabytes to
spare. The transpiler it replaces held a ~1 MB token array for a 36 KB app;
quickts holds nothing, because it consumes types through the parser's own
one-token window. The whole addition is about 16 KB of code.

## Using it

**Command line.** `qjs` and `qjsc` switch the passes on by file extension:

| extension | TypeScript erasure | JSX lowering |
|---|---|---|
| `.ts`, `.mts` | on | off |
| `.tsx` | on | on |
| `.jsx` | off | on |
| anything else | off | off |

The same rule applies to modules loaded through `import`. `QJSC_TYPESCRIPT=1`
and `QJSC_JSX=1` force a pass on in `qjsc` regardless of extension, which is
what the bytecode-diff test uses.

**C API.** Two new `JS_Eval` flags:

```c
#define JS_EVAL_FLAG_TYPESCRIPT (1 << 8)   /* erase TypeScript syntax */
#define JS_EVAL_FLAG_JSX        (1 << 9)   /* lower JSX to factory calls */

/* the flags an extension implies: .ts .mts .tsx .jsx */
static inline int quickts_eval_flags(const char *filename);
```

```c
JSValue v = JS_Eval(ctx, src, len, "app.tsx",
                    JS_EVAL_TYPE_MODULE | quickts_eval_flags("app.tsx"));
```

A file evaluated without the flags goes through the byte-for-byte unmodified
parser. Nothing about JavaScript changes unless you ask for it.

**JSX.** An element lowers to a call:

```jsx
<tag a={x} b="y" flag>text{child}</tag>
// → __frameosJsx("tag", {a: x, b: "y", flag: true}, "text", child)
<Comp.Inner />         // → __frameosJsx(Comp.Inner, null)
<>a</>                 // → __frameosJsx(__frameosFragment, null, "a")
```

Lower-case tags, and tags containing `-` or `:`, become strings; anything
else is an expression. Attributes with no value are `true`; `{...spread}`
spreads; string values have HTML entities decoded. Child text follows
TypeScript's and Babel's rule: whitespace that touches a line break goes, a
line with nothing else on it goes, and the lines left are joined with a single
space and entity-decoded. Whitespace with no line break in it stays, so
`{n} items` passes `" items"` and `<b>a</b> <i>b</i>` passes the `" "` between
the two elements. An element with no
attributes passes `null`, so a factory can tell `<a />` from `<a {...{}} />`.

The factory and fragment names default to `__frameosJsx` and
`__frameosFragment` and are resolved as ordinary free variables at the call
site. Change them at build time:

```sh
make 'CFLAGS_OPT=$(CFLAGS) -O2 -DTS_JSX_FACTORY=\"h\" -DTS_JSX_FRAGMENT=\"Fragment\"'
```

or, in your own build, define `TS_JSX_FACTORY` / `TS_JSX_FRAGMENT` when
compiling `quickjs.c`. They are read in `quickts_jsx.h`.

**Small devices and embedders.** Three things an embedded build used to patch
into `quickjs.c` from the outside:

- `JS_MALLOC_ARENA_SIZE` (default 4096) is the arena the allocator carves
  small blocks from, one list per size class. A heap keeps a partly empty
  arena per class in use, which is most of the slack on a small one: FrameOS
  builds its ESP32 firmware with `-DJS_MALLOC_ARENA_SIZE=1024`. One block of
  the largest small size (512 bytes) must fit, or the build stops.
- newlib (the ESP32's libc) has no `tm_gmtoff` and no `malloc_usable_size`.
  quickts notices newlib and takes the local offset from `mktime()` instead,
  and counts no usable size in the default allocator. `-DCONFIG_NO_TM_GMTOFF`
  and `-DCONFIG_NO_MALLOC_USABLE_SIZE` ask for the same on another libc.
- `JS_SetTimezoneOffsetFunc(func)` gives `Date` a local time zone that is not
  libc's, for the whole process. `func(time)` returns what
  `getTimezoneOffset()` would, minutes west of UTC, for `time` in
  milliseconds since the epoch; `NULL` goes back to libc. FrameOS's browser
  preview uses it to run on the frame's zone instead of the browser's.

## What is supported

Everything below is exercised by `tests/quickts/cases/`, and every case file
is also checked with `tsc` to make sure it is real TypeScript, not something
only this parser accepts.

**Erased** — consumed as tokens, nothing emitted, bytecode identical to the
stripped source:

- type annotations on `let`/`const`/`var`, parameters, return types,
  destructuring patterns, `catch` bindings, `for`/`for-of`/`for-in`
  bindings, class fields; `?` optional and `!` definite-assignment markers
- `interface`, `type` aliases, `declare ...`, `declare global`, `declare
  module`, type-only `namespace`s, `abstract` on classes
- generics everywhere: declarations, `extends` constraints and defaults,
  call sites (`f<T>(x)`, `` tag<T>`s` ``), `new X<T>()`, `new X<T>` without
  parentheses, instantiation expressions (`const g = f<string>`), generic
  arrows (`<T,>(x: T) => x`, `async <T>(x: T) => x`), JSX elements
  (`<List<Item> items={…} />`)
- `x as T`, `x as const`, `x satisfies T`, `x!`
- class members: `public` / `private` / `protected` / `readonly` /
  `override` / `abstract` / `declare` modifiers, `implements`, index
  signatures, optional methods, `this` parameters
- **bodiless declarations erased whole**: function and method overload
  signatures, constructor overloads, abstract methods and accessors,
  `abstract` and `declare` fields (leaving those as fields would define an
  own property that shadows the subclass accessor they were declared for)
- `import type`, `export type`, `export type *`, inline `{ type A, B }`
  specifiers
- the full type grammar inside all of the above: unions, intersections,
  conditional and mapped types, `keyof` / `typeof` / `infer` / `readonly` /
  `unique`, tuples, template literal types, function and constructor types,
  type predicates (`x is T`, `asserts x`), `typeof import("m")`, and
  `Map<string, Array<number>>` with its merged `>>` token split correctly

**Lowered** — real bytecode is emitted:

- `enum`, including auto-increment, computed members that reference earlier
  members by name (`AB = A | B`), string members, and reverse mappings
- constructor parameter properties (`constructor(private readonly x: T)`),
  assigned at the top of a base-class constructor and immediately after
  `super(...)` in a derived one
- JSX and fragments, as above

## What is not supported

Each of these has a file in `tests/quickts/xfail/` that must keep failing.

- **Decorators.** They have runtime semantics, and QuickJS itself does not
  implement the (now stage 3) proposal. An upstream feature, not a quickts
  one.
- **`namespace` that declares values.** Lowering it means an IIFE and a
  merged object. quickts *rejects* it (`a namespace that declares values is
  not supported`) rather than erasing it — silently dropping the values
  would be the worst possible failure. Type-only and `declare` namespaces
  erase fine.
- **`accessor` fields** (TypeScript 4.9). Rare; write the accessor pair.
- **`import x = require("m")` and `export = x`.** ES modules only, which is
  all QuickJS loads.
- **The legacy `<T>value` assertion.** Unparseable alongside JSX; `tsc`
  rejects it in `.tsx` too. Use `as`.
- **`f < a > (b)` means the generic call `f<a>(b)`.** `tsc` reads it the
  same way, so this is TypeScript being TypeScript, but it is the one place
  valid JavaScript changes meaning with the pass on. It cannot bite a `.js`
  file, because the pass is off there.

quickts is a parser, not a type checker: it accepts a superset of
TypeScript (for example an overload signature on a generator, which `tsc`
refuses). Keep running `tsc` for diagnostics.

## How it works

Two ideas carry the whole thing.

**Erasure is a type parser that emits nothing.** `quickts.h` contains a
recursive-descent parser for the TypeScript *type* grammar (`ts_skip_type`)
plus a balanced-bracket skipper. Where the JavaScript grammar has a slot
that TypeScript fills with a type — after a binding name, after a parameter,
after `)`, after `as` — a one-line hook calls into it and the tokens vanish.
Nothing is allocated, nothing is emitted, and the surrounding parser never
knows.

**Lowering emits bytecode in place.** `quickts_enum.h` and `quickts_jsx.h`
use the same `emit_op` / `emit_atom` primitives the parser uses for
everything else. An enum becomes `let E = {}` plus a block scope holding one
`const` per member — so `B = A << 1` resolves lexically, the way `tsc`
resolves it to `E.A`. JSX needs no second tokenizer: element syntax is
scanned as raw bytes, and every `{expression}` hands control back to the real
tokenizer (`s->buf_ptr` one past the `{`, `next_token()`,
`js_parse_assign_expr()`, resume from one past the `}`).

Four details are where a first attempt goes wrong, and are worth knowing
before touching the code:

1. **Splitting `>`.** The tokenizer merges `>>`, `>>>`, `>=`, `>>=`. Inside
   `Map<string, Array<number>>` the closers arrive as one `TOK_SAR`.
   `ts_next_gt()` re-lexes from one byte past the token start.
2. **A speculative parse must not raise.** `f<T>(x)` versus `f < T > (x)`
   and `(a): T => b` versus `c ? (a) : b` are decided by trying a type parse
   and backing out. The first version built a `JSError` with a backtrace for
   every failed guess — every `<` comparison in the file — and cost 54% of
   parse time. `s->ts_quiet` turns `ts_error()` into a bare `-1`.
3. **The arrow / conditional ambiguity** is resolved the way `tsc` resolves
   it: the return-type parse after `(...)` is greedy (so `c ? (a) : (b) => d`
   eats `(b) => d` as a function *type*, finds no `=>` after it, and stays a
   conditional), `(` starts a function type only if it passes TypeScript's
   own "unambiguously a parameter list" lookahead (so `(a): ((b) => c) => d`
   is an arrow), and inside the `?` branch an arrow with a return type is
   accepted only if the conditional's `:` still follows its body (so
   `a ? (x): number => x : e` is an arrow while `a ? (b) : c => d` is a
   conditional). Every one of those is checked against `tsc` in
   `tests/quickts/cases/14-corners.ts`.
4. **JSX errors must point at the raw scan position** (`js_parse_error_pos`),
   because the scanner runs ahead of the tokenizer and `s->token` is stale.

### Files

```
quickts.h        erasure: ts_skip_type and the hook entry points
quickts_enum.h   enum lowering
quickts_jsx.h    JSX lowering
tests/quickts/   cases, xfail, runners, a benchmark harness, sample apps
```

`quickts.h` is `#include`d into `quickjs.c` right after
`js_parse_seek_token()`, so it can use the tokenizer, the save/restore
helpers and `js_parse_error()`; the other two are included from it.

### How it is wired in

The hooks in `quickjs.c`, in file order. Each is a few lines guarded by
`s->ts` or `s->jsx`, except the three for small devices; the whole set is
272 added lines in 45 hunks, with 6 upstream lines modified, and `git diff 3d5e064e9d -- quickjs.c` shows all
of them.

| where | what it handles |
|---|---|
| `JSFunctionDef` | lazily allocated list of constructor parameter properties |
| JS malloc defines, `JSMallocArena` | `JS_MALLOC_ARENA_SIZE` as a default, and the check that a block fits |
| `js_def_malloc_usable_size` | newlib, `CONFIG_NO_MALLOC_USABLE_SIZE` |
| `getTimezoneOffset` | `JS_SetTimezoneOffsetFunc`; newlib, `CONFIG_NO_TM_GMTOFF` |
| `JSParseState` | the `ts` / `jsx` flags and four bits of lookahead state |
| `js_parse_skip_parens_token` | the arrow lookahead continues past a return type |
| `js_parse_property_name` | `foo<T>() {}` methods, in classes and object literals |
| `js_parse_class` | class type parameters, `extends B<T>`, `implements`, member modifiers, index signatures, bodiless members, `?` / `!` / `: T` on fields |
| `js_parse_destructuring_element` | `({a}: T = {})` |
| `js_parse_postfix_expr` | `x!`, `f<T>(y)`, JSX at the head of an expression |
| `js_parse_expr_binary` (relational level) | `as`, `satisfies` |
| `js_parse_cond_expr` / `js_parse_assign_expr2` | the `?`-branch arrow rule, generic arrows |
| `js_parse_var` | `let x!: T` |
| `js_parse_for_in_of` | `for (const x: T of …)` |
| `js_parse_statement_or_decl` | `interface`, `type`, `declare`, `namespace`, `enum`, `abstract class`, `catch (e: T)` |
| `js_parse_export` / `js_parse_import` | `export type`, `export enum`, `export default abstract class`, `import type`, inline `type` specifiers |
| `js_parse_function_decl2` | overload signatures, type parameters, `this` and typed parameters, return types, parameter-property assignment |
| `__JS_EvalInternal` | reads the two flags |

`quickjs.h` gains the two flags, `quickts_eval_flags()` and
`JS_SetTimezoneOffsetFunc()`. `qjs.c`,
`qjsc.c` and the module loader in `quickjs-libc.c` map file extensions to
flags. The `Makefile` gains `test-quickts`.

## Tests

```sh
make            # builds qjs and qjsc as usual
make test       # upstream's suite, unchanged
make test-quickts
```

`test-quickts` runs five things:

- **`tests/quickts/run.py`** — self-checking `.ts` / `.tsx` files that must
  print `ok`, plus `xfail/` files that must keep failing. A `.js` case is run
  twice, as itself and renamed to `.tsx`, and both must agree.
- **`upstream_as_ts.sh`** — QuickJS's own test suite copied to `.ts` and
  `.tsx`. Every file is plain JavaScript; the passes must change nothing.
- **`bytecode_diff.sh`** — compiles JavaScript with `qjsc` twice, both passes
  off and both forced on, and requires byte-identical output. This is the
  direct check on the only failure that matters for shipped code.
- **`tz.sh`** — builds `tests/quickts/test_tz.c` twice, once with
  `CONFIG_NO_TM_GMTOFF`, and checks `getTimezoneOffset()` and the local date
  fields against libc in seven zones, summer and winter, then the hook.
- **`corpus_parse.sh`** — parses a corpus and reports syntax errors by
  message. With no arguments it uses the bundled sample apps; point it at a
  real project with `$(git ls-files '*.ts' '*.tsx')`. The FrameOS repository
  (671 `.ts` + 356 React `.tsx`) parses 1026 of 1027, the holdout being
  `import './index.css'`.

`tests/quickts/probe.sh` is a scratchpad of one-liners for checking a
construct quickly; `tests/quickts/bench.c` measures parse time and peak
parser heap through a wrapping allocator.

## Cost

Measured on arm64 with clang against pristine QuickJS 2026-06-04, on a 36 KB
TypeScript module:

| | pristine | quickts |
|---|---|---|
| `quickjs.o` `__text`, `-Os` | 482,460 B | 498,220 B (+15.8 KB, +3.3%) |
| parse time, flags off | 0.649 ms | 0.650 ms |
| parse time, flags on | — | 0.685 ms (+4%) |
| peak parser heap | 159,452 B | 159,764 B (+312 B) |

The 312 bytes are a pointer and a count on each `JSFunctionDef`. Erasure
alone is about 7 KB of the code; JSX and enums are the rest.

## Releases

A quickts release is named after the upstream release it sits on plus a
counter: `2026-06-04-quickts.1` is the first quickts on top of QuickJS
2026-06-04. `VERSION` carries that string, so `qjs --version` and
`CONFIG_VERSION` say which one they are. Each release is a git tag
(`v2026-06-04-quickts.1`) with a source tarball attached that unpacks to
`quickjs-<version>/`, the same layout as Bellard's tarballs, so a build that
fetched `quickjs-2026-06-04.tar.xz` only needs a new URL and checksum.

FrameOS mirrors the tarball at
`https://archive.frameos.net/source/vendor/quickjs-<version>.tar.xz` and
publishes prebuilt `libquickjs.a` archives per distro/arch from it
(`tools/prebuilt-deps` in the FrameOS repository).

## Merging upstream

Add Bellard's repository as a remote and merge:

```sh
git remote add upstream https://github.com/bellard/quickjs
git fetch upstream
git merge upstream/master
make && make test && make test-quickts
```

Because the change is insertions into a handful of functions, upstream edits
elsewhere in `quickjs.c` merge cleanly, and an upstream edit *inside* one of
the hooked functions shows up as an ordinary conflict next to a clearly
marked block. After resolving, the four test runs above are the check that
matters; `bytecode_diff.sh` in particular will catch a hook that started
firing on JavaScript.

Things that would need attention if upstream changed them:

- the token constants (`TOK_SAR`, `TOK_SHR`, `TOK_GTE`, …) that
  `ts_starts_with_gt()` splits;
- `js_parse_skip_parens_token()`'s contract of returning the token after the
  closing parenthesis;
- the `OP_*` opcodes used by the two lowering headers (`OP_define_field`,
  `OP_put_array_el`, `OP_copy_data_properties`, `OP_call`, …) — all of them
  are used the same way by upstream's own object-literal and call code, so
  a change there would be visible in `js_parse_object_literal` too.

quickts adds no atoms to `quickjs-atom.h` on purpose: contextual keywords
(`type`, `as`, `satisfies`, `readonly`, …) are matched by comparing source
bytes, so the atom table and `TOK_*` numbering stay exactly upstream's.

## License

MIT, the same as QuickJS. The QuickJS copyright notices are unchanged; the
quickts additions are Copyright (c) 2026 Marius Andra and released under the
same terms.
