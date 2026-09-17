# Known invariants and traps

Split out of `CLAUDE.md` (2026-09). The rules that bite silently: ABI widths,
variadic sentinels, missing prototypes, the allocator's `free()` contract,
amd64 setjmp/longjmp, the FP environment, header search order, and the stdio
bugs found through flex. `CLAUDE.md` keeps a one-line index of these; the
reasoning is here.

Cross-references to "the section above" or "below" may now point into a
sibling file under `docs/notes/`; `CLAUDE.md` has the index.

---

## Known Invariants and Traps

### size_t / ssize_t must be 64-bit on amd64

Plan 9 6c has `long` = 32-bit even on amd64.  The original headers defined
`size_t = unsigned long` and `ssize_t = long`, making them 32-bit.  This
causes ABI mismatches: a 32-bit size_t value is stored in 4 bytes, but the
callee reads 8 bytes (amd64 argument slots are always 8-byte aligned), getting
garbage in the upper 32 bits.

**Symptom:** `vsnprintf` called by `sprintf` received `nbuf = INT_MAX = 0x7fffffff`
(correct), but `strncpy(buf, mem, nbuf - 1)` was passed `n = 0x7fff7ffffffe`
(high 32 bits = stack garbage), causing 2-billion-byte zero-padding into the
guard page → `fault write addr=0x7ffffffff000`.

**Fix (2026-04):**
- `amd64/include/ape/stddef_arch.h`: added `typedef unsigned long long _size_t; typedef long long _ssize_t;`
- `sys/include/ape/stddef.h`: `typedef _size_t size_t` (fallback: `unsigned long` for 32-bit arches)
- Same for `sys/include/ape/sys/types.h`, `unistd.h`, `bsd.h`
- `vsnprintf.c`: also fixed to use `memcpy(buf, mem, min(n, nbuf-1))` instead of `strncpy(buf, mem, nbuf-1)` — the strncpy approach is wrong when nbuf = INT_MAX regardless of size_t width

**Other 64-bit arch headers updated (2026-04):** arm64 `stddef_arch.h` updated
with same pattern. power64 `stddef_arch.h` created (power64 had none).
32-bit architectures (386, arm, mips, power, sparc, 68020, spim) are correct
as-is: `unsigned long` = pointer-sized on ILP32.

### A variadic sentinel must be a pointer, not 0

`f(a, b, 0)` where `f` reads its arguments with `va_arg(ap, char *)`
until NULL is undefined behaviour, and on amd64 Plan 9 it does not
work. The `0` is an `int`, and the default argument promotions leave it
an `int` — four bytes. Arguments are passed in eight-byte stack slots,
so `va_arg` reads eight: the zero in the low half and whatever the frame
holds in the high half. The loop then keeps going.

This is the same shape as the `size_t` problem above, and it survives
everywhere else for the same reason a lot of this does: System V amd64
passes small integers in registers, and writing the low half of a
register zeroes the upper half as a side effect. **Nothing zeroes a
stack slot.**

flex is where it turned up. `main.c:383` had

```c
filter_create_ext(output_chain, m4, "-P", 0);
```

and flex pipes its generated scanner through `m4 -P`, so the garbage
pointers became extra `argv` entries; m4 took them for file names,
exited without reading its stdin, and flex died writing into a pipe with
no reader — `flex: sys: write on closed pipe`, with nothing to say which
of the two was at fault.

Note it is stack-layout dependent, so it can appear to work and then
stop when the compiler changes. When a variadic call goes wrong, check
the sentinel before anything else. `execl`, `execle`, `execlp` and
gnulib's `version_etc` are the common ones; all call sites of those in
the tree are correct today.

### sizeof is 32-bit, so a call with no prototype in scope corrupts it

`cc/com.c`'s `OSIZE` case ends with

```c
/* Plan9: long is always 32-bit, even on amd64.  sizeof must return
 * TULONG (unsigned long, 32-bit) so it matches the ABI width of
 * every long/int parameter without corrupting the call stack.
 * Assignments to size_t (uvlong, 64-bit) zero-extend automatically
 * at the call site when the prototype is visible. */
n->type = types[TULONG];
```

**"when the prototype is visible"** is the whole of it. With no prototype
in scope, `sizeof` is written into the argument slot as four bytes, and
a callee compiled against a real `size_t` reads eight -- the low half
right, the high half whatever the stack held.

`plan9/callmain.c` was the case that found it. It includes `lib.h`,
`sys9.h` and `<stdlib.h>`, none of which reach `<string.h>`, and does

```c
memset(privates, 0, sizeof(privates));
```

so `memset` ran with `n = 0xfefefefe00000080` instead of 128 and walked
into the guard page:

```
mkbuiltins: suicide: sys: trap: fault write addr=0x7ffffffff000
```

**Every APE program starts through `_callmain`**, so this was latent in
all of them, and fired only where that garbage happened to be nonzero.
That is why it appeared on a fresh 9front and not on a machine that had
been building for a while, and why the programs that hit it --
`mkbuiltins`, `objc`, `cfront` -- are the ones the build invokes with
very long command lines: argv and the environment sit at the top of the
stack, so their size decides what lands in the slot above.

This is the same family as the variadic sentinel above, and it has the
same tell: a value that is right in its low 32 bits and garbage above.
**When an argument arrives half right, look for a missing prototype
before anything else.** kencc has no diagnostic for calling a function
with no prototype in scope, so nothing warns; adding one would catch
this class at compile time, but a great deal of old Plan 9 code relies
on implicit declarations, so it would need to be a warning rather than
an error.

### APE malloc / free() constraint
`free(ptr)` computes `(Bucket*)((uintptr_t)ptr - datoff)` where `datoff=16`.
Any pointer passed to `free()` MUST be exactly the value returned by `malloc()`.
Aligned-allocation fallback for alignment > 16 returns adjusted pointers that
are NOT free()-safe. Document this in any aligned allocator.

### amd64 sigsetjmp / siglongjmp — bugs and fixes

**Files:** `sys/src/ape/lib/ap/arch/amd64/setjmp.s`, `sys/src/ape/lib/ap/arch/amd64/notetramp.c`, `sys/src/ape/lib/ap/arch/amd64/main9.s`

**Bug 1 (setjmp.s):** `MOVL $_psigblocked(SB), 4(RARG)` stored the ADDRESS of
`_psigblocked` into the jmpbuf. Fix: load the VALUE with an intermediate register.

**Bug 2 (main9.s — suicide trap: fault write addr=0x7ffffffff000):**
Two sub-bugs, both in how `_main` stored a value near USTKTOP in a callee-saved
REGEXT register that sigsetjmp later captured:

- Sub-bug 2a: The copy loop used `MOVQ $0x7ffffffff000, R13` (boundary guard).
  R13 is REGEXT — sigsetjmp saved 0x7ffffffff000 → jmpbuf[5]; longjmp restored
  it; subsequent REGEXT write via R13 faulted at 0x7ffffffff000.
- Sub-bug 2b: After replacing the loop with `REP; MOVSQ`, the code still used
  `MOVQ SP, R12` to save kernel SP (= USTKTOP - ssize - 8 ≈ USTKTOP - 56).
  R12 is also REGEXT — sigsetjmp saved kernel_SP → jmpbuf[4]; longjmp restored
  it; REGEXT code with offset 56 from R12 wrote exactly to 0x7ffffffff000.

**Fix:** Use R11 (caller-saved scratch, NOT in setjmp's save list) instead of
R12 to hold the kernel SP.  Use `CLD; REP; MOVSQ` with only AX/CX/SI/DI/R11.

**Bug 3 (notetramp.c / notetramp ordering):**
`notecont()` decremented `nstack` BEFORE calling the user signal handler; when
the handler called `siglongjmp()`, `nstack==0` so `longjmp()` path was taken.
With the old longjmp (PUSH+RET), this caused a fault when SP was near USTKTOP.
**Fix (current):** `nstack--` is now BEFORE `(*f)()`.  With our new longjmp
(ADDQ $8,SP + JMP, no stack write), the longjmp() path is safe when nstack==0.

**Invariant:** `longjmp` must NEVER write to the stack (uses ADDQ+JMP not PUSH+RET).
`main9.s` must NEVER use R11–R15 as scratch registers — R12–R15 are REGEXT-reserved,
and R11 is the only safe scratch for values that must not survive to sigsetjmp.
Actually: use ONLY AX/CX/DX/SI/DI/R8/R9/R10/R11 (caller-saved) in `_main` startup.

### FP environment: Plan 9 vs POSIX

**File:** `sys/src/ape/lib/ap/arch/amd64/main9.s`

Plan 9's kernel initialises MXCSR to `0x1900`: invalid-operation, divide-by-zero,
and overflow exceptions are **unmasked** (will trap as process notes).  POSIX
programs expect all FP exceptions masked (`0x1f80` — the Linux/glibc default).
Without correction, any early FP call in Tcl/Tk (e.g. `log(2.)` in
`TclInitDoubleConversion`) crashes immediately with
`"sys: fp: invalid operation fppc=... status=0x21"`.

**Fix (2026-04):** In `_main` (before jumping to `_callmain`), explicitly set:
- MXCSR = `0x1f80` via `LDMXCSR` (all SSE FP exceptions masked)
- x87 CW = `0x037f` via `FLDCW`  (all x87 FP exceptions masked, double precision)

**Invariant:** Any new APE startup path that bypasses `main9.s` MUST set the
POSIX FP environment before executing any floating-point code.

### Header search order: the architecture directory wins

**This has now cost two bugs. Read it before adding a header.**

`pcc.c:234-235` passes

```
-I/$objtype/include/ape
-I/sys/include/ape
```

in that order, so **anything the host's stock APE keeps in the architecture
directory shadows everything in this tree**. Stock APE keeps `float.h` and
`stdarg.h` there.

`mount-include` used to bind the repo's `$objtype/include/ape` onto
`/sys/include/ape` and nowhere else, which only makes those files visible on
the path pcc searches *second*. So APExp's `<float.h>` — a wrapper over the
renamed `float_arch.h` — was never read on any architecture, and
`#include <float.h>` silently got the host's stock copy. Invisible until
something wanted a C99 name:

```
dtimespec-bound.h:61 name not declared: DBL_TRUE_MIN
```

**Fix:** `mount-include` also does `bind -b $cputype/include/ape
/$cputype/include/ape`, and every architecture has a real `float.h` that
chains to `float_arch.h` plus the shared `float_ext.h`.

The rename was only half-applied, which is worth knowing: eight architectures
have `float_arch.h`, while sparc, sparc64 and spim still call theirs
`float.h`; same for `stdarg_arch.h` vs sparc's `stdarg.h`. `sys/include/ape/
stdarg.h` is a pure wrapper that adds nothing, so that one is currently
harmless — but it is the same trap.

**Note:** `mount-include` is a no-op if `/sys/include/ape/THIS_IS_APExp`
already exists, so a shell that mounted before this change keeps the old
namespace. Start a fresh `apexp-sh`.

The second bug was `<stdint.h>`, and it was worse than being ignored. Stock
APE keeps a `stdint.h` in the architecture directory too, and that file takes
the guard name `_STDINT_ARCH_H_` — which is the guard on APExp's own
`stdint_arch.h`. So the stock header won the search, defined the guard, and
APExp's arch header then compiled to **nothing**: the typedefs came from the
stock file (right, by luck, on amd64) and `INTPTR_WIDTH` was never defined at
all. `SIZE_MAX` is chosen by `#if INTPTR_WIDTH == 64`, so it came out
`0xffffffff` while `size_t` stayed 8 bytes, and gnulib's

```c
argsize == SIZE_MAX ? arg[i] == '\0' : i == argsize
```

never looked for the NUL. GNU `ls` read its way off the end of the heap.

**Fix, and the shape to copy for any header stock APE keeps per-architecture:**

- every architecture directory has a real `stdint.h`, so the stock one is
  never reached;
- the content lives in `sys/include/ape/stdint_generic.h`, because none of
  those copies could reach "the other stdint.h" by that name — the search
  would find itself;
- `INTPTR_WIDTH` is derived from `_BITS64` as well, and overrides rather than
  defers, so a shadowed or neutralised arch header cannot produce a wrong
  width — only `#error`.

Known to be kept per-architecture by stock APE: `float.h`, `stdarg.h`,
`stdint.h`. **All three are now shadowed** by a real file in each architecture
directory. `stdarg.h` was the same trap twice over: its content is in
`stdarg_arch.h` under the guard `__STDARG`, which is the guard the stock
header uses too, so the stock copy did not merely win the search — it
disabled APExp's. `va_copy` is APExp's addition to those headers, and whether
any of it reached a compile depended entirely on what the host happened to
ship.

`sys/lib/tests/limits-test.c` checks `(size_t)-1 == SIZE_MAX` and the same
identity for the other types, and prints which of these headers were actually
read.

### stdio/ — vsnprintf wrote nothing when there was nothing to write

`vsnprintf` was a wrapper over `fmemopen(buf, nbuf, "w")` plus
`vfprintf`. `fmemopen`'s `mwrite` writes the terminating NUL *after* a
write, so formatting **zero** characters — `snprintf(buf, n, "%s", "")` —
touched the buffer not at all and left whatever was there before. C99
7.19.6.5p2 requires a null-terminated result whenever `n` is nonzero.

Found through GNU m4. `format()` formats each conversion into a fresh
`xasprintf` buffer, and a specifier with no argument left formats the
empty string — so it came back holding the *previous* conversion. bison's
`data/skeletons/c.m4:557` formats `"%s = %s%s%s"` with three arguments,
the last being the separating comma or nothing:

```
YYEOF = 0,,		/* wrong */
YYEOF = 0,		/* right */
```

so every token of every parser bison generated had a doubled comma. Most
C compilers accept `, ,` in an enumerator list often enough that nothing
noticed; the Portable Object Compiler is the first thing in the tree that
*parses* a `y.tab.c` rather than compiling it, and it said
`y.tab.c:138: fatal: syntax error ","`.

The same file had a second bug: `mwrite` short-writes at the end of the
buffer, which makes `vfprintf` count short *and* set the error flag, so
the return value was the truncated length or -1 rather than the length
that would have been written (7.19.6.5p3). That silently breaks the
measure-allocate-format-again idiom.

Now musl's own implementation, which is a cookie writer rather than a
`FILE`: `sn_write` reports every byte as written and copies only what
fits, so the count is right however small `nbuf` is, and the buffer is
terminated before `vfprintf` is called at all. This also retires the
`nbuf > 65536` `open_memstream` path that existed to keep `sprintf`'s
`nbuf = INT_MAX` from overflowing a length computation.

`fmemopen` was fixed alongside: POSIX says `w` and `w+` set the first
byte of the buffer to NUL, and musl did it for `w+` alone.

Covered by `sys/lib/tests/format-arg-test.c`, which separates the two
halves of the m4 line this came from — printf's `%*.*s` with a zero width
and a negative precision, and the `ARG_STR` idiom (a comma expression in
the second arm of a conditional, passed to a variadic function). Both
were suspects; only the library was at fault.

### isatty must follow the descriptor, across dup2 and exec

APE caches the answer in `_fdinfo[fd].flags` as `FD_ISTTY`, and the flag
travels across an exec in the `$_fdinfo` environment variable.
`sfdinit()` in `plan9/_fdinfo.c` restored the inherited value and then
only ever OR'd `FD_ISTTY` back in from the real descriptor -- it never
cleared it:

```c
fi->flags = fl;			/* inherited, may say ISTTY */
if(_isatty(fd))
	fi->flags |= FD_ISTTY;	/* sets, never clears */
```

So a descriptor that was the console in the parent and a pipe in the
child kept `FD_ISTTY`, and `isatty()` lied. Note `readprocfdinit()`
gets this right -- it rebuilds the flags from `/proc/$pid/fd` -- and
then `sfdinit()` runs afterwards and overwrites its work.

Tcl decides whether it is interactive with `isatty(0)`
(`tclMain.c:365`). Tk's test suite drives a child `wish` over a pipe, so
the child believed it had a terminal and wrote its `"% "` prompt into
the pipe the parent was reading results from:

```
Error in startup script: unexpected output from background
process: "% foo"
```

which names neither isatty nor the pipe. The descriptor is the
authority and now wins in both directions.

Covered by `sys/lib/tests/isatty-test.c`, whose three cases -- a pipe, a
pipe moved onto descriptor 0 by dup2, and the same across an exec --
fail independently. Only the third involves `$_fdinfo`, so it is the
one that was broken; run it from an interactive shell, where descriptor
0 really is the console, or the inherited flag is absent and the bug
cannot reproduce.

### Three lines of flex, and three stdio bugs behind them

flex sends its output through a chain of filter processes,

```
flex -> filter_tee_header -> m4 -P -> filter_fix_linedirs -> lex.yy.c
```

and every child has to make the *stdin FILE* refer to a new descriptor,
which C gives no way to do. `filter_apply_chain` dup2s onto
`fileno(stdin)` and then resynchronises the stream (`filter.c:164`):

```c
fseek (stdin, 0, SEEK_CUR);
ungetc (' ', stdin);
(void) fgetc (stdin);
```

push a character and take it straight back, touching the descriptor not
at all. flex's own comment calls it "a Hail Mary situation. It seems to
work." Each of those three lines found a different bug.

**`fseek` set the error indicator when the seek failed.** This is the
one that broke flex. C99 7.19.9.2p5 makes `fseek` "return nonzero only
for a request that cannot be satisfied"; it says nothing about `ferror`,
and neither glibc nor musl touches it -- a stream you cannot seek is not
a stream that has failed. A pipe is not seekable, so the `fseek` above
left `stdin` permanently in error, and this stdio's `fgets` tests that
explicitly:

```c
if(c==EOF && s==as || ferror(f)) return NULL;
```

so the first `fgets` in every filter returned NULL without reading a
byte. Each filter exited at once, m4 saw end of file on its input, and
flex died writing into a pipe with no reader.

Two more bugs sat in the same function, in both `fseek` and `fseeko`,
which were separate copies that had already drifted: a relative seek
ignored data sitting in the read buffer, so `fseek(f, 0, SEEK_CUR)` was
not the no-op it is meant to be and disagreed with `ftell`, which did
account for it; and both went straight to `lseek(f->fd)` and refused
`f->fd < 0`, so a stream from `fmemopen` or `open_memstream` -- no
descriptor, seeking through `f->seek` -- could not be sought at all,
though POSIX requires it. `fseek` delegates to `fseeko` now.
`rewind` also clears the error indicator, which 7.19.9.5 requires and
which is what distinguishes it from `fseek(f, 0L, SEEK_SET)`.

`ftell`/`ftello` still use `lseek(f->fd)` and so still fail on a
memstream. Do not "fix" them by calling `f->seek`: this tree's
`__stdio_seek` flushes and clears the buffers, unlike musl's, so ftell
would acquire side effects.

**`ungetc` refused a stream that had not been read yet.** A separate
bug on the same three lines, and a real one -- C99 7.19.7.11 guarantees
one character of pushback on any input stream, read from or not. It
returned EOF when `f->rpos` was null, with a comment saying `__toread`
must not be called because it resets `rpos`/`rend` and would destroy
buffered data. It only resets them when there are none: musl guards the
call with `!f->rpos`, which is true exactly when no read window exists.

This one only bit `stdin`, whose static `FILE` in `stdio/stdin.c` starts
with `rpos = rend = NULL`; `fopen` and `fdopen` leave a read window set
up, so those were fine. Left unfixed it would have cost the `fgetc`
after it a *real read on a pipe nothing had written to yet* -- every
filter blocking there, and the one that goes on to `execvp("m4")`
swallowing a bufferful into a `FILE` the exec was about to discard.

**`freopen` returned a new stream instead of reopening the given one.**
The third bug, and the one that sent the whole scanner to the terminal.
C99 7.19.5.4p2 makes `freopen` associate the *named file with the
stream it is given*; it returns that stream. This did

```c
if (f && f->fd >= 0) fclose(f);
fd = open(name, flags, 0666);
return __fdopen(fd, mode);
```

so the caller's stream was untouched. On a permanent stream it did
nothing at all: `fclose()` on `F_PERM` -- stdin, stdout, stderr --
flushes and returns *without closing the descriptor*, by design. fd 1
stayed on the terminal, `open()` took a fresh descriptor, and the new
`FILE` was discarded by every caller, since the return value is checked
against NULL and otherwise thrown away.

flex's `main.c:333` is `freopen (outfilename, "w+", stdout)` followed by
writing the scanner to `stdout`, so `lex.yy.c` was created by that
`open()` and never written to again. Now it is musl's: open the file as
a separate stream, `dup2` its descriptor onto the one the caller's
stream already uses, adopt its flags and hooks, close the temporary.
**`fileno(f)` must not change** -- flex then does
`dup2(pipe, fileno(stdout))` and forks children that inherit descriptor
1 expecting it to be the output file.

**What it cost:** an empty `lex.yy.c`, or flex killed by

```
flex: sys: write on closed pipe
```

neither of which mentions stdio. `objc`'s `lex.lm` is the only thing in
the tree that runs flex, so flex had never worked here -- and the empty
output looked like success, because `freopen` creates `lex.yy.c` before
any filter runs.

Covered by `sys/lib/tests/unget-pipe-test.c`. Note that a test here has
to *report* rather than exit: the child has several silent exit paths,
and a quiet child leaves the parent writing into a pipe with no reader,
so it dies of SIGPIPE before printing anything -- which is the same
mechanism that kills flex, and it hid the answer for a round trip.

### fclose left the standard streams open

`F_PERM` says the `FILE` is static and must not be freed. It does not
mean the file stays open. `fclose` returned early for such a stream:

```c
if (f->flags & F_PERM) {
	if (fflush(f) == EOF) error = EOF;
	return error;
}
```

so `fclose(stdout)` flushed and left descriptor 1 open. C99 7.19.5.1
grants no exemption to the standard streams -- fclose "causes the stream
to be flushed and the associated file to be closed" -- and musl calls
the close hook unconditionally, skipping only the `free`.

Closing stdout is how a program at the head of a pipeline says it is
done. flex's cleanup is

```c
fflush (stdout);
fclose (stdout);
while (wait (&child_status) > 0) ...
```

and with the descriptor still open the first filter never saw end of
file, nothing downstream could exit, and flex waited for children that
could not finish. `lex.yy.c` was complete on disk and the build simply
stopped, which `ps` showed exactly:

```
flex  Await		the parent, in wait()
flex  Pread		filter_tee_header
flex  Pread		filter_fix_linedirs
```

### <stdio.h> used to drag errno, unistd, fcntl and pthread in

`<stdio.h>` included `<stdio_impl.h>` — musl's *internal* header, which
opens with `<stdint.h> <stddef.h> <errno.h> <unistd.h> <fcntl.h>
<sys/types.h> <pthread.h>` because the implementation wants all of it.
So nearly every translation unit in the tree got every `O_` and `F_`
macro, all of unistd and all of pthread.

Not merely untidy: portable code guards its fallbacks on whether a name
exists, and a name appearing earlier than the author expected changes
the answer. libzip's `compat.h` does `#ifndef O_CLOEXEC / #define
O_CLOEXEC 0 / #endif` for Windows' sake, having included nothing that
leads to fcntl — but `<zip.h>` asks for stdio a little later, fcntl
arrives through the back door, and the two disagree.

`struct _IO_FILE` now lives in `sys/include/ape/_iofile.h` with only
`<stddef.h>`, `<stdint.h>` and `<sys/types.h>`; both `<stdio.h>` and
`stdio_impl.h` include that, and stdio_impl.h keeps its heavy includes
for the 64 files in `ap/stdio` that use it. This is musl's own
arrangement, restored.

**libap depended on the leak in two places**, and both are the shape to
expect elsewhere:

- `ap/include/musl.h` had `#ifndef errno / extern int errno;` — a
  reference to a symbol that exists nowhere, since APE's `<errno.h>` is
  `extern int *_errnoloc;` plus `#define errno (*_errnoloc)`. It never
  fired only because musl.h includes `<libc.h>` → `<utf.h>` →
  `<stdio.h>` → errno. It includes `<errno.h>` directly now.
- The `_unlocked` family existed *only* as four macros in stdio_impl.h,
  which musl has for its own use. `stdio/unlocked.c` defines all fifteen
  now and `<stdio.h>` declares them — as functions, not macros, because
  code that thinks a system lacks these writes an unguarded `#define
  ferror_unlocked(x) ferror(x)` and cpp rejects a non-identical macro
  redefinition (see the macro-identity section above). bash's config.h
  asserts `HAVE_DECL_{FEOF,FERROR,GETC,PUTC}_UNLOCKED`.

Locking in this stdio is a no-op — `stdio_impl.h`'s `__lockfile`
returns 0 without doing anything — so each `_unlocked` function is its
locked counterpart today. They are separate entry points so that the day
`flockfile` becomes real, `unlocked.c` is the one file to change.

### <string.h> reached Plan 9's <u.h>

The same shape as the `<stdio.h>` leak above, and found the same way —
by a port whose own names collided:

```
string.h -> wchar.h -> time.h -> signal.h -> pthread.h -> lock.h -> u.h
```

`<u.h>` is Plan 9's, and defines `nil`, `uchar`, `ushort`, `ulong` and
`uint`. So asking for `strlen` brought all of them. The Portable Object
Compiler is where it showed:

```
Object.m:28 ... Object.h:32 ... string.h:70 ... u.h:4
  Macro redefinition of nil
```

`objcrt.h:83` defines `nil` as `((id)0)`, as every Objective-C runtime
does, and guards it — so the unguarded definition in `u.h` simply lost
to whichever of the two came second.

**Every link in that chain existed for a pointer parameter**, and each
is now a forward declaration, which is the idiom `signal.h` was already
using one line above the offending include (`struct timespec; /* avoid
pulling in time.h */`):

- `string.h` wanted `wchar_t` for three APExp additions, and
  `<stddef.h>` — already included — provides it. This was also circular:
  `wchar.h` includes `string.h` back, so which definitions a file saw
  depended on which of the two it asked for first.
- `wchar.h` wanted `struct tm` for `wcsftime`.
- `time.h` wanted `struct sigevent` for `timer_create`.
- `signal.h` wanted `pthread_attr_t` for `struct sigevent`. That one is a
  typedef rather than a tag, so it is repeated under a `_PTHREAD_ATTR_T`
  guard in both headers.

`nil` in `u.h` is guarded now as well. `<pthread.h>` still reaches
`<lock.h>` and so `<u.h>` legitimately — `pthread_mutex_t` is built on
`Lock` — so that path stays, and a name as common as `nil` should not
be defined unconditionally at the end of it.
