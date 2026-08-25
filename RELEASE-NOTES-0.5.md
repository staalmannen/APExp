# APExp 0.5

APExp is an enhanced ANSI/POSIX compatibility layer for Plan 9 and 9front,
aiming for maximal GNU/POSIX compatibility so that C programs written for
UNIX build on Plan 9 with as little modification as possible.

This is a large release. The C library's stdio was replaced wholesale, the
width of `wchar_t` and `size_t` changed, and the Plan 9 C compilers gained
most of C11 and a useful part of C23.

As always, APExp is intentionally unstable between releases. Download the
latest release rather than upgrading in place.

---

## Breaking changes — read this first

**Nothing built against 0.4 links against 0.5.** Three ABI-visible types
changed width. Rebuild everything, and do not mix objects, archives or
installed libraries across the two releases.

| | 0.4 | 0.5 |
|---|---|---|
| `wchar_t` | `unsigned short` (16-bit) | `unsigned int` (32-bit) |
| `size_t` | `unsigned long` (32-bit on Plan 9 amd64) | 64-bit on amd64, arm64, power64 |
| `ssize_t` | `long` (32-bit) | 64-bit on amd64, arm64, power64 |

`wchar_t` had to widen because it contradicted the rest of the system.
`pcc` emits `L"..."` as an array of `Rune`, so a 16-bit `wchar_t *` was
handed a 32-bit array and walked it at the wrong stride; `<wchar.h>`
already defined `WCHAR_MAX` as `Runemax` (0x10FFFF), which does not fit in
16 bits; and 16 bits cannot represent anything above the BMP on a system
that is UTF-8 throughout. `wchar_t` is now exactly `Rune`.

`size_t` had to widen because Plan 9's `6c` has 32-bit `long` even on
amd64, while amd64 argument slots are 8 bytes. A 32-bit `size_t` was
stored in 4 bytes and read back as 8, so callees saw stack garbage in the
upper half. The concrete symptom was `sprintf` faulting in the guard page
via `vsnprintf`. 32-bit architectures are unaffected — `unsigned long` is
pointer-sized there.

**`<wchar.h>` no longer defines the wide functions as macros.** 53 shim
macros that redirected wide functions onto byte functions (`wcscmp` to
`strcmp` and so on) are gone; all of them are now real functions in
`libap`. Third-party code that worked only because those macros made
`wchar_t` strings behave like byte strings will now get true wide
semantics. This is the intended behaviour, but it is a behaviour change.

---

## stdio is now musl's

The Plan 9-derived stdio (`iolib.h`, `_IO_getc`, `sopenr`/`sopenw`) has
been replaced with musl's implementation. `FILE` now has musl's layout —
`rpos`/`rend`/`wpos`/`wbase`, with `F_ERR`, `F_NORD`, `F_NOWR` and an
8-byte `UNGET` area.

This brings correct buffering semantics, working `fmemopen` and
`open_memstream`, a proper open-file list for exit flushing, and
`flockfile`/`funlockfile`.

New in this area:

- `<stdio_ext.h>` with musl's accessors (`__fbufsize`, `__freading`,
  `__fwriting`, `__freadahead`, `__fpending` and friends), which several
  gnulib modules want and which previously had to be supplied by gnulib
  itself.
- `_fpending`, `ofl`/`ofl_add`, `__stdio_exit`, `__towrite`, `__uflow`
  and the rest of musl's internal plumbing.

---

## Wide character support

`<wchar.h>` went from 53 macro shims to 53 implementations. The wide
stdio layer is new:

- Character and string I/O: `fgetwc`, `fputwc`, `getwc`, `putwc`,
  `getwchar`, `putwchar`, `ungetwc`, `fgetws`, `fputws`.
- Formatted output: `vfwprintf`, `vswprintf`, `wprintf`, `fwprintf`,
  `swprintf` and the `v` forms.
- Formatted input: `vfwscanf`, `vswscanf`, `wscanf`, `fwscanf`,
  `swscanf` and the `v` forms.
- `%ls` and `%lc` in the *narrow* `printf` and `scanf`, with C99
  semantics: `%ls` precision is a byte limit that may not split a
  character, and `%ls` scanf field width counts characters.
- The `wcsto*` family: `wcstol`, `wcstoul`, `wcstoll`, `wcstoull`,
  `wcstod`, `wcstof`, `wcstold`.
- `wcsftime`.

`fgetwc` handles a multibyte character split across a buffer refill by
accumulating and retrying.

---

## C11 and C23 in the Plan 9 compilers

All of this is new since 0.4. The work is in `sys/src/cmd/cc` (shared
front end) and the per-architecture back ends.

- `_Generic` (C11 §6.5.1.1), handled in the grammar rather than in
  `tcom()`, so unselected branches are never type-checked.
- `typeof` / `__typeof__`. Previously these were *silently swallowed*
  alongside `__attribute__`: the whole argument was consumed and
  discarded, so `__typeof__(int) y;` became `y;` with no type. Every
  declaration using `__typeof__` was quietly corrupted.
- `_Alignof` / `__alignof__`, likewise previously swallowed.
- `_Static_assert` and C23 `static_assert`, in all three scopes (file,
  function, struct body).
- `nullptr`, `alignof`, `typeof_unqual`, `[[attributes]]`,
  `#elifdef` / `#elifndef`, `<stdcountof.h>`.
- C23 `auto` type deduction, including `auto *p = ptr;` and
  `for (auto x = ...; ...)`.
- Digit separators (`1'000`) in all eight numeric lexer loops,
  including the float paths.
- `_Atomic` / `__atomic` accepted and dropped as qualifiers;
  `__builtin_*` swallowed.
- `<tgmath.h>`, built on `_Generic`.

### Compiler correctness fixes

Several of these were corrupting output rather than merely failing to
compile:

- **`typesuvinit[]` ABI.** `TVLONG` and `TUVLONG` were listed as
  struct-return types, so every `vlong`-returning function used the
  hidden-pointer calling convention. This corrupted the ABI of all
  binaries, including `6l` itself.
- **`sizeof` ABI**: returns `TULONG`, not `TUVLONG`, on 64-bit Plan 9
  targets.
- **`CLOCAL` in `naddr()`**: function-local `static` variables get class
  `CLOCAL`, not `CSTATIC`. Every architecture's `txt.c` handled only
  `CSTATIC` and hit `bad in naddr: NAME`. Fixed in three places per
  architecture.
- **Register allocator**: `maxregion` restored to 600; at 300 it crashed
  in `allocn()` on large functions such as `yyparse`.
- **`ar` duplicate symbols**: `ar r` aborted the whole operation on the
  first duplicate text symbol, leaving 150+ members out of `libap.a`.
  The archive grew from about 3.5 MB to about 6.2 MB once fixed.
- **Compound literal lvalues**: `&(type){...}` no longer reports "not an
  l-value".
- **`cpp`**: `#elif` conditions are no longer evaluated once a group has
  been selected (C11 §6.10.1p6). Evaluating dead arms produced spurious
  diagnostics from code the standard says is never examined.
- **`pcc -p`** is accepted rather than forwarded to the compiler. `pcc`
  always preprocesses with `/bin/cpp` and pipes into the back end, so
  forwarding `-p` made the back end try to preprocess a file literally
  named `stdin`.

---

## One shared gnulib

Eight vendored copies of gnulib have been consolidated into a single
source tree at `sys/src/external/gnulib`, built once into
`sys/src/ape/cmd/gnulib/libgnu.a`.

- `import.sh` regenerates the tree reproducibly from the per-package
  copies, newest vintage winning, with coreutils as the base.
- `config.h` is split into a shared `config-common.h` (platform answers)
  plus a small per-package `config.h` (identity only), so programs no
  longer report whichever package happened to build last.
- `version-etc` is built per package, since it compiles
  `PACKAGE_BUGREPORT`, `PACKAGE_NAME` and `PACKAGE_URL` into the object.
- Modules that `libap` already provides are deliberately excluded — both
  archives are on every link line, so a duplicate is a link error. The
  rules are written down in `sys/src/ape/cmd/gnulib/README`.

bison, sed, m4 and grep now build against the shared archive.

---

## Other library changes

- **`aio`**: a real async I/O implementation on pthreads. `aio_suspend`
  no longer deadlocks, `aio_fsync` actually calls `fsync`, and
  `aio_cancel` exists.
- **`pthread_cond_timedwait`**: implemented with a timer thread, since
  Plan 9's `rendezvous()` has no timeout. Previously it was a macro that
  discarded the timeout and called `pthread_cond_wait`.
- **`fdopendir`** (POSIX.1-2008).
- **`<math.h>`**: 30+ C99 functions were present in `libap.a` but
  undeclared, so `pcc` gave them implicit `int` return type and silently
  truncated their results. All now declared — `acosh`, `cbrt`,
  `copysign`, `exp2`, `fma`, `lgamma`, `nearbyint`, `round`, `trunc`,
  `nextafter` and the rest.
- **`aligned_alloc`, `memalign`, `reallocarray`.**
- **`xmalloc` family** promoted into `libap`, in the full gnulib-
  compatible set including the `idx_t` variants.
- **32-bit time overflow** fixed throughout (2038 correctness and long
  sleeps).
- **Locale** machinery simplified to Plan 9's single UTF-8 locale.
- **`prng`**: `getrandom`, `arc4random` and `truerand`, backed by
  `/dev/random`.
- **`<stdint.h>`**: `WCHAR_WIDTH` corrected to 32, and `WCHAR_MIN` /
  `WCHAR_MAX` added as C99 §7.18.3 requires.

### Startup and signal fixes (amd64)

- `sigsetjmp` stored the *address* of `_psigblocked` rather than its
  value.
- `_main` used `R12`/`R13` as scratch. Those are `REGEXT`-reserved, so
  `sigsetjmp` captured values near `USTKTOP` and a later `longjmp`
  restored them, faulting at `0x7ffffffff000`. Startup now uses only
  caller-saved registers, and `longjmp` never writes to the stack.
- The FP environment is now set to POSIX expectations at startup.
  Plan 9's kernel leaves invalid-operation, divide-by-zero and overflow
  *unmasked* (`MXCSR = 0x1900`); POSIX programs expect them masked.
  Without this, the first floating-point call in a program such as
  Tcl/Tk crashed immediately.

---

## Build system

- **bash builds without GNU make.** The `.def` files are expanded into
  `.c` and `.h` in the local build directory, so the external source
  tree stays clean and there is no bootstrap dependency on `gmake`.
- `mount-include` now binds the local `$cputype/bin` over `/bin`, so a
  rebuild uses APExp's own compilers rather than the host's.
- ELF64 output with DWARF from the linker. `pcc -g` now asks `6l` for it
  directly with `-H5`; `mkelf` and `mkelves` are build templates for the
  same thing. The old route — a `.dwtypes` sidecar per object plus a
  `dw2elf` post-link pass — is gone.
- Assorted `mk` fixes, including `clean` rules that used to stop a
  `mk clean` at the repository root.

---

## Known limitations

- **Combining characters do not render correctly.** Tested with
  PDCursesMod: `getcchar()` returns the right code points (an `A` plus
  U+030A comes back as two characters, and a base plus cedilla plus
  circumflex as three), so the data path is correct, but the composed
  glyphs do not appear. This looks like terminal and font rendering
  rather than the library, but it has not been traced to a specific
  layer. Precomposed characters display correctly.
- **SMP characters** (above the BMP, such as U+1D11E) are read correctly
  but few fonts will display them.
- `vswscanf`'s `%n` counts bytes in the converted string, not wide
  characters.
- `aligned_alloc` with alignment greater than 16 falls back to an
  over-allocating path whose result is **not** safe to pass to `free()`.
  APE's `free()` requires exactly the pointer `malloc()` returned.
- `typeof_unqual` is currently an alias for `typeof`; qualifier
  stripping is not implemented.
- `_Alignas` is accepted as a query (`_Alignof` works) but has no layout
  effect in declarations.
- `_Atomic` is dropped as a qualifier; there is no full `<stdatomic.h>`.
- **`pcc -g` produces ELF only on amd64.** `-H5` means ELF64 to `6l`
  alone; on the other linkers that number already meant something else
  (ipaq on `5l`, sgi elf on `vl`, blue gene on `ql`), so `-g` elsewhere
  links normally and says so.
- Testing has been primarily on amd64. The other ten architectures build
  but have had much less exercise.

### Ports not yet enabled

Still commented out in `sys/src/ape/cmd/mkfile`: GNU coreutils, GNU tar,
GNU diff, GNU patch, perl, the BaCon BASIC transpiler, and Go 1.4.

---

## What's next

- GNU coreutils replacing sbase. `config-common.h` began life as
  coreutils' own `config.h`, so coreutils is the package that fits the
  shared gnulib best.
- GNU tar, the last GNU package still building its own gnulib copy.
- TLS and `curl`. The usual first obstacle is already cleared: `libap`
  has `getrandom`, `arc4random` and `truerand` backed by `/dev/random`.
