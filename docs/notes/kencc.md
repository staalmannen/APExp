# kencc: compiler patch history and technical details

Split out of `CLAUDE.md` (2026-09). Everything the Plan 9 C compilers
(`sys/src/cmd/cc`, `[1-9]c`, `[1-9]l`, `cpp`) have been patched for, the bugs
behind each patch, and what each one cost. Read this before touching
`sys/src/cmd/`.

Cross-references to "the section above" or "below" may now point into a
sibling file under `docs/notes/`; `CLAUDE.md` has the index.

---

## Compiler Patch History and Technical Details

This section documents the patches applied to `sys/src/cmd/` during the
2025-2026 development cycle, the bugs they fix, and the principles behind them.
It is intended to help Claude Code continue this work without re-deriving
solutions from scratch.

### Critical Bug Fixes (already committed)

#### ABI: typesuvinit[] — TVLONG/TUVLONG removed (cc/sub.c)
`TVLONG`/`TUVLONG` were incorrectly in `typesuvinit[]`, causing all vlong-returning
functions to use the struct-return calling convention (hidden pointer parameter).
This corrupted the ABI of all binaries including 6l itself.
**Fix:** `int typesuvinit[] = { TSTRUCT, TUNION, TCFLOAT, TCDOUBLE, -1 };`

#### Register allocator: maxregion=600 (all *c/reg.c)
`maxregion` was set to 300 (reduced during a rebase), triggering an
`allocn()` crash when compiling large functions like `yyparse`.
**Fix:** Restore `maxregion = 600` in all arch `reg.c` files.

#### CLOCAL missing from naddr() (all *c/txt.c) — THREE locations per file
Function-local `static` variables get class `CLOCAL` (not `CSTATIC`) in `adecl()`.
All arch compiler `naddr()` functions only handled `CSTATIC`, so `CLOCAL` hit
the `bad:` label producing "bad in naddr: NAME" errors.
**Fix:** Add `|| n->class == CLOCAL` / `|| s->class == CLOCAL` at three spots
in each arch's `txt.c`:
1. Global emit loop: `s->class != CSTATIC && s->class != CLOCAL`
2. naddr ONAME case: `n->class == CSTATIC || n->class == CLOCAL`
3. gpseudo D_STATIC selection: `s->class == CSTATIC || s->class == CLOCAL`

#### ar duplicate-symbol abort (ar.c)
Plan9 `ar r` aborted the entire operation on the first duplicate text symbol,
leaving 150+ critical members missing from `libap.a`.
**Fix:** In `rcmd()`, reset `dupfound=0` per member and `continue` rather than
aborting. `libap.a` grew from ~3.5MB to ~6.2MB.

#### Compound literal lvalue (cc/dcl.c, cc/com.c)
`&(type){...}` produced "not an l-value" errors.
**Fix:**
- `dcl.c` `compoundlit()`: `if(!iscmplx(t->etype) && !typesu[t->etype]) seq->addable = 1`
- `com.c` OCOMMA case: same guard for `n->addable = r->addable`
The `iscmplx`/`typesu` guard is critical — without it, complex number OCOMMA
nodes get `addable=1` causing "unknown type in regalloc: UNION" errors.

That guard left `&(struct S){...}` still failing, because struct/union
literals are exactly the ones the guard excludes. **Fix (2026-08):** the
`OADDR` case in `com.c` `tcomo()` now hoists the comma first —
`&(a, b)` → `(a, &b)` — so the `OADDR` lands on the hidden temporary's
`ONAME`, which is addressable whatever its type, and the l-value test is
never reached. Only fires when `l->op == OCOMMA` and the right operand is
already addable and not a bit field. Covered by
`sys/lib/tests/compound-literal-test.c`. Found via gnulib `randperm.c`,
which passes `hash_remove(sv, &(struct sparse_ent_){i, 0})`.

### C99 Feature Status (complete)

All C99 items are implemented. Key patches in `sys/src/cmd/cc/`:

| Feature | Files | Notes |
|---------|-------|-------|
| `\uXXXX` universal chars | `lex.c` escchar() | Returns Rune, runetochar() encodes UTF-8 |
| Binary literals `0b` | `lex.c` tnum: | Already present |
| Digit separators `1'000` | `lex.c` all 8 numeric loops | incl. float: casedot/casee/casedothex/casep |
| `_Static_assert` | `lex.c` itab, `cc.y` prog+slist+edecl | 3 scopes: file, function, struct body |
| `nullptr` | `lex.c` LNULLPTR, `cc.y` pexpr | OCONST with types[TIND], vconst=0 |
| `typeof`/`__typeof__` | `lex.c` LTYPEOF, `cc.y`, `com.c`, `sub.c` | Was SILENTLY SWALLOWED before — corrupted all __typeof__ uses |
| `_Alignof`/`__alignof__` | `lex.c` LALIGNOF, `cc.y`, `com.c` | Was swallowed; now returns align(1,T,Ael1) |
| `[[attributes]]` | `lex.c` case '[' | Depth-counts [[ to ]] |
| `__builtin_*` | `lex.c` | Swallows args, returns LCONST 0 |
| `_Atomic`/`__atomic` | `lex.c` drop-silently | Dropped like __thread |
| `_Generic` | `lex.c` LGENERIC, `cc.y` | See _Generic section below |
| `#elifdef`/`#elifndef` | `cpp/cpp.h`, `cpp/nlist.c`, `cpp/cpp.c` | Also fixed skipping-block dispatch |
| `static_assert` | `lex.c` | C23 alias for _Static_assert |
| `alignof` | `lex.c` | C23 alias for _Alignof |
| `typeof_unqual` | `lex.c` | C23 alias for typeof (qualifier stripping not yet implemented) |
| main() implicit return 0 | `cc/pgen.c` | C99 §5.1.2.2.3; synthesises gen(&ret) with zero |
| non-void fall-off warning | `cc/pgen.c` | Was error; now warn (use -B to suppress) |

**Named initializers for static aggregates (17b):** Works — the localeconv.c
error was caused by missing struct members in `locale.h`, not a compiler bug.
One real bug found later, in the *scope* a designator is resolved in: see
"Designators are relative to the enclosing brace list" below.

**Anonymous struct/union:** Fully implemented in existing `dcl.c`+`sub.c` —
`edecl()` accepts `sym==S`, `sualign()` assigns correct offsets, `dotsearch()`
recurses into anonymous members. No compiler changes needed.

### _Generic Implementation (C11 §6.5.1.1)

Location: `sys/src/cmd/cc/cc.y` (grammar + `generic_select()` helper function)

**Design:** Handled entirely in the grammar action, not in `tcom()`, to avoid
type-checking unselected branches (which may reference wrong-type functions).

Association list: OLIST of OCAST nodes where `->type` = association type
(T = null for `default:`), `->left` = value expression.

`generic_select()` at end of `cc.y` after the final `%%`:
1. Calls `generic_ctrl_type()` to apply lvalue conversion (array→ptr, func→ptr, strip qualifiers)
2. Walks OLIST using `sametype()` for matching
3. Returns matching `->left` node, or `default:` value, or Z on no match

**Token:** `LGENERIC` in `lex.c` itab and `cc.y` `%token`.

### typeof Implementation

**Critical:** `__typeof__` was previously in the swallow block alongside
`__attribute__` — the entire argument `(expr)` was consumed and discarded,
so `__typeof__(int) y;` became `y;` with no type. This silently corrupted
ALL declarations using `__typeof__`.

**Fix:** Remove `__typeof__`/`__typeof` from swallow block. Add `LTYPEOF`
token. Two grammar contexts:
- `uexpr: LTYPEOF '(' cexpr ')'` → OTYPEOF node (for `sizeof(typeof(x))`)
- `complex: LTYPEOF '(' cexpr ')'` → calls `complex($3)`, returns `$3->type`
- `complex: LTYPEOF '(' tlist abdecor ')'` → `dodecl(NODECL,...)`, returns `lastdcl`

`OTYPEOF` in `com.c`: evaluates child type, collapses to typed zero OCONST.
`OTYPEOF` in `sub.c`: added to no-side-effects list and opname table.

### C11/C23 Task List

**Done:** `_Static_assert`, `nullptr`, `[[attributes]]`, `#elifdef`/`#elifndef`,
`_Alignof`/`_Alignas`(query), `_Generic`, `typeof`, `static_assert`, `alignof`,
anonymous structs/unions, digit separators (all 8 loops), `__builtin_*` swallowing,
`auto` type deduction.

**Not yet done (priority order):**
1. `typeof_unqual` qualifier stripping (currently alias)
2. `_Alignas` in declarations (layout effect; `_Alignof` query works)
3. `_Atomic` full stdatomic.h (currently dropped as qualifier)
4. `_Generic` is done; `tgmath.h` now exists using it
5. Digit separators in float exponent (casep loop) — verify
6. `constexpr` objects (C23)

### `auto` Type Deduction (C23 §6.7.10.2)

Location: `sys/src/cmd/cc/cc.y`

**Design:** New `autoadlist` non-terminal entered when LAUTO appears without an
accompanying explicit type specifier. Avoids the mid-rule action timing problem in
the existing `adlist` rule by parsing the full declarator and initializer before
calling `dodecl`.

**How it works:**
- `auto x = expr;` — `complex(expr)` is called to type-check the initializer, then
  `auto_deduct_type()` extracts the type and strips top-level const/volatile (§6.7.10.2).
  `dodecl(adecl, CAUTO, deduced_type, xdecor)` is called with the real type.
- `auto *p = ptr;` — `dcl_ind_depth()` counts OIND levels in the declarator;
  that many TIND layers are stripped from the initializer type before `dodecl` wraps
  them back. Net result: `p` gets the initializer's pointer type.
- `auto x;` (bare, no init) — backward compat: declares `int` (C89 §6.7.1).
- `auto x = e1, y = e2;` — multiple deductions in one declaration.
- `for(auto x = ...; ...)` — supported via `forexpr: LAUTO autoadlist`.

**LALR(1) conflicts:** LAUTO + LNAME/`*`/`(` creates a shift-reduce conflict with
the existing `ctlist adlist` path (where `LAUTO → cname → ...`). Yacc's default
shift-preference picks `autoadlist`, which is correct. For `;` after LAUTO, only
the cname reduce applies (no conflict), so `auto;` still parses normally.

**Limitation:** `auto int x = 5;` (bare auto with explicit type) now causes a parse
error — this syntax is invalid C23 anyway and was never written in practice.

---

### Build order for compiler changes
```
cd sys/src/cmd/cc && mk nuke && mk install   # regenerates y.tab.h
cd sys/src/cmd/6c && mk nuke && mk install   # (and all other *c dirs)
cd sys/src/cmd/cpp && mk nuke && mk install
```
`cc` must build first because `y.tab.h` (with token defines like `LTYPEOF`,
`LALIGNOF`, `LGENERIC`, `LNULLPTR`, `LSTATICASSERT`) is consumed by `lex.c`
in each arch compiler.

### CLOCAL vs CSTATIC
Inside a function, `static` variables get class `CLOCAL` (not `CSTATIC`).
Every arch's `txt.c` must handle both. There are three locations:
global emit loop, naddr ONAME case, gpseudo D_STATIC selection.

### ar duplicate-symbol handling
The `ar` tool's `rcmd()` must use per-member `dupfound` reset + `continue`
(not global abort). The arch/amd64 directory builds last specifically so
assembly implementations overwrite C port versions via the duplicate-skip mechanism.

### typesuvinit[] — do not add TVLONG/TUVLONG
Adding `TVLONG`/`TUVLONG` to `typesuvinit[]` in `cc/sub.c` breaks the entire
ABI by making vlong-returning functions use struct-return convention.
The correct content: `{ TSTRUCT, TUNION, TCFLOAT, TCDOUBLE, -1 }`.

### Integer rules applied to floating point (FIXED)

Three bugs of one shape, all found by musl's `asin()`, all silent. When
something floating-point is subtly wrong, ask whether an integer rule
has been applied to it.

**`double op float` was computed in FLOAT.** `cc/sub.c`'s promotion
table had `tab[TDOUBLE][TFLOAT] == TFLOAT`, so the common type of a
double and a float was the **smaller** of the two -- C99 6.3.1.8 gives
it to the greater rank. The `TFLOAT` row was right
(`tab[TFLOAT][TDOUBLE] == TDOUBLE`), so `float op double` always worked
and only this direction was wrong, which is how it survived.

`asin(1.0)` returns `x*pio2_hi + 0x1p-120f` -- a double plus a float
constant whose only job is to raise `inexact` -- and the answer came
back as **float** pi/2, `1.5707963705062866`, exactly 4.371e-08 above
the double value. **Every mixed-precision expression in the tree was
quietly rounded to 24 bits**, so anything built before this is suspect,
the same warning as the 6c spill and the `bool` fix.

**`0/x` was folded to 0 for floating point.** `cc/com.c`'s `ccom()`
`ODIV` case did `if(vconst(l) == 0 && !side(r)) *n = *l;`. True for
integers; in floating point `0.0/0.0` is NaN and `0.0/-1.0` is `-0.0`.
Worse, `*n = *l` replaces the node with the **integer** constant, so the
answer was a positive integer zero. The divisor-is-zero case two lines
below already carried a `typefd` guard; this one did not.

`asin(2.0)` reports its domain error with `return 0/(x-x);`, which
folded away and returned 0.0 instead of NaN.

**`INFINITY` was `DBL_MAX`.** `<math.h>` had
`#define HUGE_VAL 1.79769313486231e+308` with `INFINITY` on top of it --
a finite number, against C99 7.12p3/p4. `isinf(INFINITY)` was false,
`exp(1000) == INFINITY` was false, and `cos(INFINITY)` computed a real
cosine of a very large angle rather than NaN. It hid unusually well:
`exp(INFINITY)` *passed*, because `exp(1.8e308)` returns `1.0+x`, which
compares equal to that same 1.8e308. `HUGE_VAL` is `Inf(1)` now, as
`NAN` was already `NaN()` -- neither is the constant expression the
standard asks for, and there is no way to write one here.

Covered by `sys/lib/tests/fparith-test.c`.

### The sign of zero was dropped everywhere (FIXED)

The fourth of that family, and the widest: **seven** separate places,
each one a test of the form `x == 0` or `x < 0` written by someone who
did not have two zeros in mind. `-0.0` compares equal to `0.0` and is
not less than it, so every ordinary test misses it and every one of
these was silent.

**Negation was `0 - x`.** x86-64 has no scalar floating-point negate, and
`cc/com.c` rewrites `-x` as `0 - x` whenever the back end says it cannot
do the operation itself -- `machcap()`. 6c's `machcap()` answered for the
integer types only (`typechlv`), so **every** floating-point negation in
the tree went through the rewrite, and `0.0 - 0.0` is `+0.0`. Unary plus
is the same shape one line above, `0 + x`, so `+(-0.0)` was `+0.0` too;
that one is now simply the operand, since floating point has no
promotions to apply.

Negation is a sign-bit flip and `6c/cgen.c` generates one: `XORPS` or
`XORPD` against a mask of `-0.0`. The mask is loaded into a register
first -- the linker lays an `FCONST` literal out four or eight bytes
aligned and the memory form of those instructions wants sixteen.
`AXORPS` had to be added to `reg.c` and `peep.c`, which knew only
`AXORPD` (`gmove` uses it to make a zero); `reg.c`'s default arm is
`diag("reg: unknown op")`, so a missing entry is at least loud.

Five more places lost the sign on the way out, and they are the reason
fixing the negation alone was not enough:

| | |
|---|---|
| `cc/scon.c` | `evconst` folded `-x` with a runtime negation, so it inherited the bug from the compiler compiling it |
| `cc/pswt.c`, `1c`+`2c` `swt.c` | `ieeedtod` tested `native < 0` before `native == 0` |
| `cc/dcl.c` | `init1` skips a **zero** static initialiser, since BSS is already zero -- and `vconst()` answers 0 for `-0.0`, because it truncates to an `int` |
| `6c/txt.c` | `gmove` made any zero constant with `XORPD` of a register against itself, which is `+0.0` |
| every `*l/obj.c` | `ieeedtof` took `-0.0` for a denormal and said `double fp to single fp overflow` |

The `dcl.c` one is the one to remember, because it is the shape that
survives every fix upstream of it: the value was folded correctly, and
then **discarded as a zero** rather than written wrongly. `static double
negzero = -0.0;` was the last case still failing after the other six
were fixed, and it fails on its own -- a file-scope initialiser never
goes through `com.c` or `cgen.c` at all.

**`fpnegzero()` and `fpnegzeroval()` are in `cc/sub.c`**, so they are in
`cc.a` and every back end has them -- `1c` and `2c` do not build
`pswt.c`, which is where they were first put. Both read or write the
sign bit through a `union { double; uvlong; }` rather than writing
`-0.0`: **kencc compiles kencc**, so a `-0.0` in the compiler's own
source would have folded to `+0.0` and the fix would only have taken
effect on the second rebuild. `evconst` is written the same way for the
same reason.

The sign of zero is not decorative. It is what makes `1/x` tell the two
infinities apart, it is the sign of every underflowing product and
quotient, and `atan2`, `copysign` and `log` all branch on it -- so
**anything doing floating-point arithmetic near zero and built before
this is suspect**, the same warning as the 6c spill and the `bool` fix.

Covered by `sys/lib/tests/fparith-test.c`, which reaches a `-0.0` by
each of the routes above separately -- a constant, a static initialiser,
a runtime negation, unary plus and the library -- because they fail
independently.

### Hex floating constants were silently zero (FIXED)

`cc/lex.c` collected the whole literal into `symb` and finished with

```c
yylval.dval = strtod(symb, nil);
```

**Plan 9's `strtod` does not parse C99 hex floats.** It reads the leading
`0`, stops at the `x`, and returns 0.0. So every `0x1.921fb54442d18p-1`
in the tree was **zero**, with no diagnostic from anything -- and hex
floats were on the "implemented" list above, because the *lexer* work
(`casedothex`, `casep`) had been done and the conversion had not.

What it cost, all of it silent:

- musl's math tables are written entirely this way. `exp_data.c`,
  `log_data.c`, `log2_data.c` and `pow_data.c` are **597 constants**,
  every one zero. Nothing had noticed only because nothing used them
  yet -- see the math section.
- `__rem_pio2.c`'s `pio4` threshold and `__rem_pio2_large.c`'s `0x1p24`
  scaling, so the **large-argument** path of sin/cos/tan was still wrong
  after those were replaced with musl's.
- A `0x1p-120f` added to a result purely to raise `inexact` is harmless
  at zero, which is why the small-argument cases looked fine. That is
  the shape of it: harmless where the constant is decorative, fatal
  where it is data.

`hexfloat()` in `lex.c` does the conversion now: mantissa into a
`uvlong`, stopped at 60 bits with round-to-nearest on the first dropped
digit, then `ldexp` by the binary exponent. Checked against `strtod` on
the build host over **every one of the 1921 hex float literals in
`ap/math`** -- all 1921 bit-identical.

The tell for this class: a constant that is *decorative* (an inexact
flag, a threshold that only picks a slower path) hides the bug, and a
constant that is *data* exposes it. When a table-driven routine is
wildly wrong and a polynomial one is fine, suspect the constants before
the algorithm.

### Mixed-signedness compound assignment (FIXED)

`E1 op= E2` where E1 is signed and E2 unsigned does the operation
**signed**. C99 6.5.16.2p3 makes it equivalent to `E1 = E1 op (E2)`, so
the usual arithmetic conversions apply to the operation and only the
result is converted back to E1's type.

```c
vlong  rv1 = -1;
vlong  rv2 = 2;
rv1 /= (uvlong)rv2;     /* gives 0; should give 0x7fffffffffffffff */
rv1 %= (uvlong)rv2;     /* gives -1; should give 1                */
```

Confirmed by `sys/lib/tests/compound-assign-test.c`, which also shows
the fully-cast and simple-assignment forms are correct — so it is `op=`
alone, not the division.

Where: `cc/com.c` `case OASDIV:` (~line 243) and `case OASMOD:` (~line
310). `arith(n, 0)` correctly sets `n->type` to the promoted type, but
then

```c
if(!mixedasop(t, n->type)) {
        if(!sametype(t, n->type)) {
                r = new1(OCAST, n->right, Z);
                r->type = t;      /* casts the RHS back down to E1's type */
                n->right = r;
                n->type = t;
        }
}
if(typeu[n->type->etype]) {       /* n->type is now t, so this misses */
        if(n->op == OASDIV)
                n->op = OASLDIV;  /* ... and the unsigned opcode is never chosen */
```

`mixedasop` only detects an integer lvalue with a *floating* RHS
(`sub.c`: `!typefd[l->etype] && typefd[r->etype]`), so a signed/unsigned
pair takes the first branch. The opcode is selected from `n->type`
*after* it has been overwritten with `t`, so it is chosen from E1's type
rather than from the type the operation is performed in.

Fixed by reading the promoted type's signedness into a local, `uns`,
immediately after `arith(n, 0)` and before those branches overwrite
`n->type`, then selecting the opcode from `uns`. Both sites; `OASMUL`
and `OASLMUL` fall into the `OASDIV` case, so `*=` is covered too.

The shift case above it needs no change and must not get one: C99
6.5.7p3 gives `E1 << E2` the promoted type of the *left* operand, so
reading the lvalue's type there is already right.

Still wrong, and a separate problem: kencc performs a compound
assignment in the lvalue's own width, casting the right operand down
first. `long x; x /= (uvlong)y;` therefore divides in 32 bits on amd64
where C requires 64. Fixing that means rewriting `E1 op= E2` as
`E1 = (T1)(E1 op E2)`, far more than choosing an opcode.
`compound-assign-test.c` reports it without counting it as a failure.

Found via cpp's `#if` evaluator, which did `rv1 /= (uvlong)rv2` to
divide unsigned. `UINTMAX_MAX / 2` came out 0, so GNU tar's

    #if ! (INTMAX_MAX <= UINTMAX_MAX / 2)

fired its `#error`. cpp no longer relies on the implicit conversion.
Any other `signed_lvalue op= (unsigned)x` in the tree is still wrong.

### Spilling a fixed register saved only the operation's width (FIXED)

`6c/cgen.c` spills AX, CX or DX where the instruction it is about to emit
can only use that register — a divide or modulo needs AX and DX, a
variable shift needs CX. The save was

```c
if(nodreg(&nod, nn, D_AX)) {
        regsalloc(&nod2, n);      /* slot sized from n, the divide */
        gmove(&nod, &nod2);       /* ... so a 32-bit save */
```

`regsalloc` takes its size from the node handed to it, and `n` is the
divide or the shift. So a **32-bit** operation spilled **four** bytes of a
register that might be holding eight, and the top half was lost. What is
live in AX at that moment belongs to some earlier part of the
expression and has nothing to do with the type of the operation being
generated.

Found in LibreSSL's Keccak:

```c
t0 = bc[(i + 4) % 5] ^ crypto_rol_u64(bc[(i + 1) % 5], 1);
```

`cgen`'s `OXOR` case evaluates the call first, because `OFUNC` has
`complex == FNX`, and it lands in AX. Then `bc[(i + 4) % 5]` needs AX for
the 32-bit `% 5`, spills it four bytes wide, and `crypto_rol_u64`'s
`uint64_t` result comes back with bits 32..63 cleared. The *identical*
call two lines below, `st[j] = crypto_rol_u64(t0, rotc[i])`, is correct —
no division beside it.

The trigger is exactly `<expression containing / or %> op <64-bit
function call>`, and `%` has to be in the **other operand**, not in the
call's arguments: an argument is evaluated before the call, so nothing
64-bit is live yet.

Fixed with `regwide()`/`regspill()` at the head of `cgen.c`: the save
uses a full-width alias of the register and an 8-byte slot, and the
narrow node is left alone because callers still need it at the
operation's own type for the result. Six sites — AX and DX in
`ODIV`/`OMOD` and in the `OAS*` forms, CX in both shift cases.

Only `6c` has this. `8c` is 32-bit, so a one-register save cannot
truncate; the RISC back-ends need no fixed register for division, and
their one `regsalloc(&nod, n)` is `OFUNC` with a discarded result, where
`n` *is* the call and its type is right.

What it cost: every SHA-3 digest was wrong, so ML-KEM was wrong, so
every TLS 1.3 handshake offering X25519MLKEM768 failed at the first
encrypted record with `bad decrypt` — while TLS 1.2 and
`-groups X25519` worked, because nothing else in a handshake uses
Keccak. **Nothing about this is Keccak-specific.** A 64-bit value live
across a 32-bit `%` is ordinary C, so anything built before this fix is
suspect and wants rebuilding.

Covered by `sys/lib/tests/rol64-test.c`, which isolates the trigger
one variable at a time, and by the Keccak vectors in
`sys/src/ape/lib/libressl/test/`.

### #include nesting limit was 20

`cpp/include.c` had the depth guard written as a bare `20`. That is a guard
against a circular include, and it also stopped LibreSSL, which reaches 20 on
an ordinary chain with nothing repeated in it:

```
pthread.h compat/pthread.h signal.h time.h compat/time.h sys/stat.h
compat/sys/stat.h unistd.h compat/unistd.h stdio_impl.h stdio.h
compat/stdio.h utf.h wchar.h string.h compat/string.h netinet/in.h
compat/netinet/in.h sys/socket.h compat/sys/socket.h  ->  b_sock.c
```

LibreSSL ships a `compat/` header for most system headers, each ending in an
`#include_next` of the real one, so every step of a normal chain counts twice.

Now `NINCDEPTH` in `cpp.h`, set to 200, which is what gcc and clang use for
`-fmax-include-depth`. A genuine cycle passes 200 as fast as it passed 20.
`incdepth` is a depth and not a count — `cpp.c:52` decrements it at each
end-of-file — so this does not make a file with many includes any dearer.

`NIF`, the `#if` nesting limit, is still 32 and has not been a problem.

### Pointer signedness is a warning, not an error

`char *` and `unsigned char *` are distinct types, so passing one where the
other is declared is a constraint violation and C requires a diagnostic. gcc
and clang give a warning — `-Wpointer-sign`, not in `-Werror` by default — so
portable C is full of it, and there is no spelling that avoids a cast at every
call. kencc used to refuse:

```
a_object.c:185 argument prototype mismatch "IND CHAR" for "IND CONST UCHAR":
  CBB_add_bytes
```

from LibreSSL's `CBB_add_bytes(cbb, s, n)` with `char s[22]` against
`int CBB_add_bytes(CBB *, const uint8_t *, size_t)`.

`-Wpointer-sign` is not about `char`, and LibreSSL hit the `int` case next:

```
e_sm4.c:241 argument prototype mismatch "IND INT" for "IND UINT":
  CRYPTO_ctr128_encrypt
```

from `&ctx->num`, an `int *`, against `unsigned int *num`.

There are **two** sites, because static initializers do not go through
`stcompat()`. `cc/dcl.c` `init1()` has its own `sametype()` test and gave

```
s_client.c:540 initialization of incompatible pointers: s_client_options
  IND INT and IND UINT
```

for `.opt.value = &cfg.off` with `unsigned int off` against the union's
`int *value`. Both sites now call `ptrsignonly()` (declared in `cc.h`) and
warn instead.

`cc/sub.c` `stcompat()` calls it in the `BIND`/`TIND` branch. **One level only, and only when the two pointees are the
signed and unsigned spellings of the same type** — the five pairs are listed
in `pairs[]` there. Still errors: `int *` for `char *`; `int *` for
`unsigned long *`, which are the same width on amd64 but are not a
signed/unsigned pair, and which gcc calls incompatible pointer types rather
than a signedness difference; and `char **` for `unsigned char **`, which is
the case where the difference can actually be observed.

This cannot change code generation: a type and its opposite signedness have
the same representation, so the only thing that differs is whether a
diagnostic is fatal. `warn()` is gated on `debug['w']`, so it is quiet unless `-w` is passed.

Note `rsametype()` in `dcl.c` compares `etype` and the `GNORET` bit and
nothing else — it already ignores `const` and `volatile`, which is why
`char *` → `const char *` was never the problem here.

Covered by `sys/lib/tests/charptr-test.c`, whose real test is that it
compiles: every case in it is a constraint violation of that shape.

### Designators are relative to the enclosing brace list (FIXED)

C99 6.7.8p17: a designator is interpreted relative to the object of the
*enclosing brace list*. Reaching into a sub-object with a nested designator
does not leave the current object there, because no braces were opened:

```c
struct s x = { .inner.v = &n, .v = 1 };   /* .v is the OUTER v */
```

`init1()` in `dcl.c` restarted its member walk at whatever level it was in
(`goto again`), so having entered `inner` to satisfy `.inner.v`, the next
designator matched `inner`'s members first. Found via LibreSSL's
`apps/openssl/ciphers.c`, which has an `int *value` inside a named union and
a `const int value` beside it:

```
ciphers.c:55 initialize pointer to an integer: ciphers_options
```

Fixed by breaking out of the member loop instead of `goto again` when
`exflag` is set — `exflag` means "entered implicitly, without braces of our
own", so a designator seen at that point belongs to an enclosing level.
The existing code already returned without consuming when the designator
named *no* member here; this extends that to the case where it names one by
coincidence. The braced case keeps `exflag == 0` (via `doinit`) and so still
restarts, which is correct.

The union is incidental — two members of the same name at different depths
are enough. **When the two have the same type there is no diagnostic at
all**: the value simply lands at the wrong offset. `ciphers.c` was only
caught because `int *` and `const int` disagree.

Covered by `sys/lib/tests/designated-init-test.c`, whose case 3 is the silent
variety.

### Macro identity includes whether there is white space

C99 6.10.3p2: two definitions of the same macro are the same only if the
*presence* of white-space separation matches at every point (the amount does
not matter). `cpp/macro.c`'s `comparetokens()` implements exactly that:

```c
(tp1->wslen==0) != (tp2->wslen==0)
```

So a definition differing only in spacing is a **redefinition error**, not a
harmless repetition. This has now bitten twice, and both times the other
definition was unguarded, so APExp's spelling is the one that had to move:

- `weak_alias` — `<features.h>` said `(old, new)`, gnulib's `libc-config.h`
  says `(name, aliasname)`. Parameter names count as tokens.
- `S_IXUGO` — APE said `(S_IXUSR|S_IXGRP|S_IXOTH)`, and gnulib, gtar,
  diffutils, bison and readline all say `(S_IXUSR | S_IXGRP | S_IXOTH)`.
  readline's `posixstat.h:160` has no guard, so the two met on a full rebuild.

Only *interior* white space counts. `tokens.c` `normtokenrow()` ends with

```c
if (ntrp->lp > ntrp->bp)
        ntrp->bp->wslen = 0;
```

so the first body token's leading space is discarded for both `#define` and
`-D`. That is why `-DO_BINARY=0` on a command line coexists with
`#define O_BINARY	0` in `<fcntl.h>`, while `S_IXUGO`'s spacing *between*
its tokens did not.

**Rule:** when adding a macro to an APE header that portable code also
defines, copy the upstream spelling character for character, and guard it.
Guarding alone is not enough — it only helps when APExp's header is read
second.

**Corollary for `-D` workarounds.** A `-DNAME=VALUE` in a mkfile that exists
only because APE lacked `NAME` becomes a redefinition error the moment APE
gains it. `sys/src/ape/cmd/libtool/mkfile` carried `-DESTALE=EDEADLK` for
exactly that reason and had to lose it when `<errno.h>` gained `ESTALE`. When
adding a name to an APE header, grep the mkfiles for `-D<name>=`.

`/tmp`-style one-off check, if this is suspected again: compare token
sequences *with* leading-whitespace flags between APE's headers and unguarded
`#define`s under `sys/src/external`. The only other whitespace-only pairs
today are inert — `.in.h` templates that are never compiled, and per-package
vendored copies (bison's own `obstack.h`, tk's `MIN`/`MAX`) that never meet
APE's headers.

### Unsigned 64-bit to floating point (FIXED)

Both halves of this conversion were wrong, and neither mattered until
`SIZE_MAX` became a 64-bit constant.

**Constant folding, `cc/scon.c` `OCAST`.** A cast of a constant folds through
`n->vconst`, which is a `vlong`, so an unsigned source with the top bit set
came out negative: `(double)(uvlong)~0` gave `-1.0`. Fixed by reading it back
unsigned when `typeu[et]`.

**Runtime, `6c/txt.c` `CASE(TUVLONG, TDOUBLE)`.** The top-bit case is handled
correctly — halve, convert, double — and then the result was never stored:
the `gmove(&nod1, t)` that the `TULONG` case beside it has was missing.
`regalloc(&nod1, t, t)` reuses `t`'s register when `t` is one, so this was
invisible whenever the destination was a register and silent nonsense when it
was memory.

What it cost: gnulib's `hash.c` has

```c
float new_candidate = candidate / tuning->growth_threshold;
if (SIZE_MAX <= new_candidate)
  return 0;
```

which folded to `-1.0 <= 128.75`, true. `compute_bucket_size` returned 0,
`hash_initialize` returned NULL, and every program that hashes — `cp`, `mv`,
`ln`, `du` — died with "memory exhausted" before looking at its arguments.

Still wrong, and not reached by anything here: the reverse direction in the
same `scon.c` case, `v = l->fconst` for a float constant cast to an unsigned
integer type, for values at or above 2**63.

Covered by `sys/lib/tests/u64float-test.c`, which tests the folded and the
runtime path separately, and the memory destination specifically.

### bool was a signed char, so converting to it truncated (FIXED)

C99 6.3.1.2: "When any scalar value is converted to `_Bool`, the result
is 0 if the value compares equal to 0; otherwise, the result is 1."
It is a **comparison**, not a truncation, and that is what makes `bool`
usable as a flag at all.

kencc had no bool. `lex.c`'s `itab` mapped both `_Bool` and `bool` to
`LCHAR`, and the grammar's `tname: LCHAR` yields `BCHAR` — so `bool` was
a plain **signed char**, and every conversion to it kept the low byte:

```c
bool b = 256;              /* false */
op->moresib = (bool)ptr;   /* 0 for every aligned pointer */
```

An object pointer is 8-byte aligned, so its low byte is always even;
store that in a one-bit bit field, which keeps bit 0, and the answer is
always 0. (The bit field is behaving correctly — the conversion in front
of it is what was wrong.)

**What it cost.** perl's `handy.h` has `#define cBOOL(cbool) ((bool)
(cbool))`, and `op.h` records whether an op has a next sibling with
`OpMAYBESIB_set(o, sib, parent)`, which is the *only* thing that ever
sets `op_moresib` to 1 — `op_prepend_elem` and `op_append_elem` both
reach it through `op_sibling_splice`. So every op in every program perl
compiled came out with `op_moresib = 0` beside a perfectly good
`op_sibparent`. `Perl_op_linklist` walks a node's children with
`OpSIBLING`, which reads that flag, so **every statement list collapsed
to its first element**: the `op_next` chain for `print "hi\n"` was
`enter, leave`. miniperl parsed its input, reported syntax errors
correctly, ran `BEGIN` and `END` blocks, and executed none of the
program in between — no output, no diagnostic, exit status 0.

**Fix.** `bool`/`_Bool` get their own token `LBOOL` and their own
`Type`, `typebool`: unsigned char's representation, width and alignment
under a distinct identity. It is built in the `complex` production
rather than `tname`, because `tname` yields a bit in a type mask and the
mask has **no spare bit** — `BNORET` is already `1<<31` in a 32-bit
`long`. `com.c`'s `boolnorm()` wraps the value in `!!`, which `tcomo`'s
`ONOT` case gives type int, so the narrowing cast that follows sees a
value that is already 0 or 1.

**The mark is `Type.isbool`, a field, not the identity of `typebool`.**
`copytyp()` is a struct copy and a type gets copied whenever it is used
for anything — `dcl.c:996` copies a parameter's type to chain it into a
prototype, `garbt()` copies for `const`/`volatile`. Pointer identity
survives a cast and a return but not a declaration or a parameter, which
is exactly the set that still failed when the first attempt used it.

Applied at **five** sites, one per kind of conversion: the explicit cast
and assignment (`OAS`) and return (`ORETURN`) in `tcomo`, argument
passing in `tcoma` — before the promotion that turns a `bool` parameter
into `unsigned int` — and `OASI`, which is auto initialisation and has
its own copy of the conversion logic separate from `OAS`.

**Still wrong, narrowly:** a static or file-scope initialiser is folded
in `dcl.c` without going through `com.c`, so `static bool b = 256;`
truncates. An auto `bool b = expr;` is an `OASI` and is covered.

Covered by `sys/lib/tests/bool-test.c`.

**Anything using `bool` and built before this is suspect** — the same
warning as the 6c spill fix. gnulib, LibreSSL and curl all use `bool`
heavily. A `bool` that silently reads false for `0x100` is exactly the
class of bug that only shows up much later, somewhere else.

### Compiler self-hosting as correctness test
After any compiler change, have it rebuild itself multiple times:
```
cd sys/src/cmd/cc && mk nuke && mk install
cd sys/src/cmd/6c && mk nuke && mk install
# repeat — if the second build produces identical output, the compiler is consistent
```

### __typeof__ was silently broken
Before the LTYPEOF patch, `__typeof__(x)` was swallowed like `__attribute__`.
The entire argument `(x)` was consumed and the next token returned as if
`__typeof__` never existed. Any code using `__typeof__` in declarations
was silently corrupted. The fix is in `lex.c` — remove from swallow block,
add to itab as LTYPEOF.

### _Generic association type matching
Uses `sametype()` which ignores const/volatile (only checks GNORET bit).
So `_Generic(x, const int: ..., int: ...)` would be ambiguous — both match.
This is correct per C11 §6.5.1.1p2 which says qualified/unqualified are compatible.
The `generic_ctrl_type()` helper also strips qualifiers from the controlling expression.

---

## Missing Declarations Audit (2026-04)

Scan of `sys/src/ape/lib/ap/**/*.c` vs `sys/include/ape/*.h` found ~85
functions in the library with no header declaration. Without a declaration,
kencc gives functions implicit `int` return type — silently truncating
pointer and float return values.

The math.h gap (30 functions) and the other missing declarations has been fixed.



### Every struct's size is rounded to 8, whatever its members are (NOT fixed; worked around)

**`sizeof(struct { char a[500]; })` is 504 here.** C says 500. This is
not a corner case in a corner of the compiler; it is the layout rule
6c uses for every struct in the system, and it is why GNU tar wrote
archives no tar could read.

`sys/src/cmd/6c/swt.c`, `align()`:

```c
case Asu2:	/* padding at end of a struct */
	w = SZ_VLONG;			/* 8 on amd64 */
	if(packflg)
		w = packflg;
	break;

case Ael1:	/* initial align of struct element */
	for(v=t; v->etype==TARRAY; v=v->link)
		;
	...
	w = ewidth[v->etype];
	if(w <= 0 || w >= SZ_VLONG)
		w = SZ_VLONG;
	if(packflg)
		w = packflg;
	break;
```

Two things fall out of those lines. **The end of every struct is
rounded to `SZ_VLONG`** rather than to the alignment its members
actually require; and **a nested struct or union member is aligned to
8 as well**, because `ewidth[TSTRUCT]` fails the `w <= 0 || w >=
SZ_VLONG` test and drops through to the same constant. `sualign()` in
`cc/dcl.c` applies both.

#### The measurement, which is what made it certain

`sys/lib/tests/tarblock-probe.c` on GNU tar's header definitions --
nine sizes, each printed beside gcc's answer for the same file:

```
  BLOCKSIZE                =  512   host says  512   same
  sizeof(union block)      =  520   host says  512   *** DIFFERENT ***
  sizeof(struct sparse)    =   24   host says   24   same
  sizeof(posix_header)     =  504   host says  500   *** DIFFERENT ***
  sizeof(star_header)      =  504   host says  500   *** DIFFERENT ***
  sizeof(oldgnu_header)    =  504   host says  495   *** DIFFERENT ***
  sizeof(sparse_header)    =  512   host says  505   *** DIFFERENT ***
  sizeof(star_in_header)   =  520   host says  512   *** DIFFERENT ***
  sizeof(star_ext_header)  =  512   host says  505   *** DIFFERENT ***
```

Every one of those numbers is predicted by the two `align()` cases,
and two of them only make sense together:

- `oldgnu_header` 495 -> **504**, not 496. Its `struct sparse sp[4]`
  sits at byte 386 on the host; `Ael1` pushes it to 392, which moves
  everything after it by six, and then `Asu2` rounds the tail. *The
  nested-member rule and the tail rule are not the same rule, and this
  struct needs both to explain it.*
- `star_in_header` 512 -> **520**: same push, then a tail round that
  had nowhere to go but the next multiple of 8. **This is the one that
  set `union block`'s size**, since it is the union's largest member.

**`struct sparse` is 24 and agrees**, which is the useful part of the
table rather than filler: it is all char, it is a multiple of 8 by
accident, and it looks perfectly healthy. *A sample of one struct
could have been that one.*

#### What it actually breaks, stated narrowly

**Field offsets are fine.** Members of an all-char struct land where
the format says, which is why tar read its own header back correctly,
checksum and all, and why `memcpy(&hdr, buf, sizeof hdr)` into a local
still gets the right values (it over-reads the source by the padding,
which is harmless when the source is a larger buffer).

**What breaks is `sizeof` used as a STRIDE or a LENGTH**:

- `p + 1` on a pointer to the padded type. tar's whole record walk is
  `union block *` arithmetic (`find_next_block`, `set_next_block_after`,
  `record_end = record_start + blocking_factor`) while every length in
  the tar format is a multiple of `BLOCKSIZE`. 520 put every block
  after the first **eight bytes late**, and the zero-fill -- counted in
  `BLOCKSIZE` -- then missed the gaps, which is the second symptom
  `tarhdr-probe` saw as garbage in blocks 2 and 3.
- `write(fd, &s, sizeof s)` for an on-disk or on-wire record, which
  would emit the padding.
- Any array of the type read or written as a whole.

#### The fix used, and why not the other one

**`#pragma pack on` / `#pragma pack off`** around the on-disk structs.
`pragpack()` in `cc/dpchk.c` sets `packflg`, which is exactly the
override both `align()` cases already read, so the layout becomes the
one the format specifies. It is the established Plan 9 idiom for this
-- `sys/src/cmd/5e/proc.c` and go1.4's `defs_*.h` use it -- and it is
spelled `pack on` rather than `pack 1`, because `pragpack` does
`atoi(s->name+1)`, skipping the first character, and only `on`/`yes`
are matched by name.

In tar it is guarded by `PLAN9`, passed from
`sys/src/ape/cmd/tar/mkfile` the way `-DPLAN9` already is for itcl, so
the host syntax check does not trip over a pragma gcc spells
differently.

**CHANGING `Asu2` TO THE CORRECT ALIGNMENT WAS NOT DONE, and the
reason is the host's libraries rather than timidity.** It would change
the size of a large share of the structs in the system, and this tree
links against `/$objtype/lib/*.a` that 9front built with the current
rule -- `lib9p.a`, `libthread.a`, `libc.a` for `sys/src/cmd2/vts`, and
every native header shared through `sys/include`. A conforming 6c is
the right end state for a project whose stated aim is that C written
for UNIX builds here unmodified, but it is an ABI change across the
whole machine and wants to be decided rather than slipped in beside a
tar fix.

#### The sweep, and its known limit

Looking for all-char structs whose size is not already a multiple of 8,
across `sys/src/external`: **six**, of which two are tar's. The others
-- `psf1_header` in PDCursesMod, `ops_table_s` and `buildid_s` in
libdwarf, `ModeInfo` in sqlite's shell -- are all `memcpy`-into-a-local
or in-memory tables, so the padding costs them nothing by the rule
above.

**That count is a LOWER BOUND and the limitation is specific**: the
sweep only matches structs whose every member is a plain `char` or
`char[N]` declaration, so it misses exactly the three tar structs that
have a nested `struct sparse sp[N]` -- `oldgnu_header`,
`sparse_header`, `star_in_header` -- and it misses anything mixing char
with integers. *The tool that found the bug's family cannot find the
whole family.* A real answer wants `sizeof` compared between pcc and
gcc for every struct in a package, which is what `tarblock-probe` does
by hand for one.
