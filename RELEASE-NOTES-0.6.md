# APExp 0.6 (in development)

APExp is an enhanced ANSI/POSIX compatibility layer for Plan 9 and 9front,
aiming for maximal GNU/POSIX compatibility so that C programs written for
UNIX build on Plan 9 with as little modification as possible.

0.5 replaced the C library's stdio and widened three types. 0.6 is mostly
about what that made possible: GNU coreutils, tar, diff and patch build
and are installed by default, and so do LibreSSL, curl, libzip, pax and
perl. TLS 1.3 works.

It is also the release in which five separate compiler bugs were found,
every one of which produced **silently wrong values** rather than an error.
Two of them had been corrupting output for as long as they had existed.
That is the reason for the rebuild notice below, and it is not a formality.

As always, APExp is intentionally unstable between releases. Download the
latest release rather than upgrading in place.

> **Draft.** A few ports are still being wrapped up before this is tagged.
> Everything described below is in the tree and working.

---

## Rebuild everything — read this first

**Anything built before 0.6 is suspect, whether or not it links.** This is
not the usual ABI-change warning: the compiler was quietly producing wrong
values in ordinary C, so a binary can link cleanly and still be wrong.

Two of the five bugs are the reason:

- **`bool` was a signed char**, so *every* conversion to it truncated to
  the low byte instead of comparing against zero, as C99 6.3.1.2 requires.
  `bool b = 256;` was false. `(bool)p` for any aligned pointer was a coin
  toss on its low byte. The common idiom `bool ok = flags & SOME_MASK;` is
  false whenever the mask is above bit 7 — there are around 350 of that
  exact shape in the ported packages, and curl alone mentions `bool` in
  291 files.
- **`6c` truncated a live 64-bit value across a 32-bit divide or modulo.**
  Every SHA-3 digest was wrong, so ML-KEM was wrong, so every TLS 1.3
  handshake offering X25519MLKEM768 failed. Nothing about that is
  Keccak-specific: a 64-bit value live across a 32-bit `%` is ordinary C.

Rebuilding the compiler is not enough on its own, and neither is
rebuilding libap. Everything here links statically, so a library fix
reaches only the binaries relinked after it — an old `ls` keeps the old
`hash.c` and the old `setlocale` inside it however many times libap is
rebuilt underneath. That is what "everything" means above.

The order matters, because every architecture compiler consumes `y.tab.h`
from `cc`:

```
cd sys/src/cmd/cc && mk nuke && mk install
cd ../6c && mk nuke && mk install        # and the other ten
cd <repo root> && mk install             # twice
```

There are ABI-visible changes as well:

| | 0.5 | 0.6 |
|---|---|---|
| `bool` / `_Bool` | signed char | unsigned char, and converting to it compares against zero |
| `SIZE_MAX` | `0xffffffff` on amd64, beside an 8-byte `size_t` | matches `size_t` |
| `SSIZE_MAX` | `LONG_MAX`, i.e. 32-bit on amd64 | matches `ssize_t` |
| `S_IFSOCK` | the same value as `S_IFIFO` | `0140000`, its own value |
| `struct dirent` | `d_ino`/`d_type` were macros | real members |

`S_IFSOCK` is worth calling out: aliasing it to `S_IFIFO` made
`S_ISSOCK()` true for every FIFO, and gave duplicate `case` labels to any
`switch` over file types.

### Source-level changes

**`<stdio.h>` no longer includes `<errno.h>`, `<unistd.h>`, `<fcntl.h>`
and `<pthread.h>`.** It used to include musl's internal `<stdio_impl.h>`,
which pulls all of those in, so nearly every translation unit in the tree
saw every `O_` and `F_` macro by accident. Code that used `errno`,
`open()` or `pthread_*` while including only `<stdio.h>` compiled by
luck and now needs the right `#include` — a one-line fix per file, and
each one is a real latent bug.

That leak was not harmless. Portable code guards its fallbacks on whether
a name exists, and libzip's `compat.h` defines `O_CLOEXEC` as 0 when it
cannot see one; the definition then collided with the real one arriving
later through `<zip.h>`.

---

## New ports

| | |
|---|---|
| GNU coreutils 9.11 | built and installed **by default**; `sbase` is cut back to what only it provides |
| GNU tar 1.35 | with the compressor programs wired up |
| GNU diffutils 3.12 | `diff`, `diff3`, `sdiff`, `cmp` |
| GNU patch 2.8 | |
| LibreSSL 4.3.2 | `libressl.a` plus the `openssl` command |
| curl 8.21.0 | `libcurl.a` plus the `curl` command |
| libzip 1.11.4 | plus `zipcmp`, `zipmerge` and `ziptool` |
| paxmirabilis 20240817 | installed as `pax` and `cpio`; GNU tar is the `tar` |
| perl 5.42.2 | interpreter and the pure-perl module library |

LibreSSL and curl are built by default, and their public headers are
installed into `sys/include/ape` with `#pragma lib`, so `#include
<openssl/ssl.h>` or `<curl/curl.h>` is enough to link.

**TLS 1.3 works**, including X25519MLKEM768 — `openssl s_client` completes
a handshake with a verified certificate chain. Getting there took the 6c
fix above; the route was upstream's own ML-KEM and SHA-3 vectors, which
now live in `sys/src/ape/lib/libressl/test` and run with `mk test`.

### perl

The interpreter runs and loads modules; `ExtUtils::Miniperl` generates
`perlmain.c` during the build. Two things to know:

- **No XS extensions.** Plan 9 has no `dlopen`, so `xs_init` is empty and
  only the pure-perl `dist/` and `cpan/` trees are installed — the
  fourteen with a `.xs` are deliberately left out, because a `.pm` that
  dies inside `XSLoader` is worse than one that is simply absent.
- **`Config.pm` is hand-maintained**, at `sys/src/ape/cmd/perl/Config.pm`.
  APExp does not run `Configure`, so there is no `config.sh` for
  `configpm`; it is the companion to the hand-answered `config.h` and has
  to be kept in step with it.

---

## Compiler correctness fixes

All five of the first group produced wrong values with no diagnostic.

**Converting to `bool` truncated instead of comparing** (`cc/lex.c`,
`cc.y`, `com.c`). `_Bool` and `bool` were mapped onto `LCHAR`, which the
grammar turns into `BCHAR`. They now have their own token and their own
`Type`, marked with `Type.isbool` — a field rather than the identity of
one object, because `copytyp()` is a struct copy and a type is copied
whenever it is used for a parameter or a `const`. The comparison is
applied at all five places a conversion happens: cast, assignment,
return, argument passing, and auto initialisation, which has its own case
in `tcomo` separate from assignment.

**A fixed register was spilled at the operation's width, not the
register's** (`6c/cgen.c`). `6c` spills AX, CX or DX where the instruction
it is about to emit can only use that register — a divide needs AX and DX,
a variable shift needs CX — and sized the spill slot from the *operation*.
A 32-bit `%` therefore saved four bytes of a register holding eight. The
trigger is `<expression containing / or %> op <64-bit function call>`.
Only `6c` has this: `8c` is 32-bit, and the RISC back-ends need no fixed
register for division.

**Unsigned 64-bit to floating point was wrong in both directions**
(`cc/scon.c`, `6c/txt.c`). Constant folding read the value back as signed,
so `(double)(uvlong)~0` was `-1.0`; at run time the top-bit case computed
the right answer and then never stored it. gnulib's `hash.c` compares
`SIZE_MAX` against a float, so `hash_initialize` returned NULL and every
program that hashes — `cp`, `mv`, `ln`, `du` — died with "memory
exhausted" before looking at its arguments.

**A comma expression's type decayed, so `sizeof` an array compound
literal was the size of a pointer** (`cc/com.c`). `compoundlit()` builds
`(type){...}` as `OCOMMA(initialisation, ONAME)`, and the `OCOMMA` case
typed its right operand with `tcom()` — which is `tcomo(..., ADDROF)`, and
so turned the array into a pointer. `sizeof` types its operand with
`tcomo(l, 0)` precisely to stop that happening, and the flag was being
thrown away one level down:

```c
sizeof((int[]){1,2,3,4,5,6,7})   /* 8, not 28 */
```

That is the standard way of counting variadic arguments, so
`ARRAY_CARDINALITY` over a compound literal answered 1 for any array of
pointers. bison's `muscle_kind_new` uses it to size a table and aborted.

**A designator was resolved in the wrong scope** (`cc/dcl.c`). C99
6.7.8p17 makes a designator relative to the object of the *enclosing*
brace list; `init1()` restarted its member walk at whatever level it had
reached. Two members of the same name at different depths were enough, and
**when the two have the same type there is no diagnostic at all** — the
value simply lands at the wrong offset.

Also fixed:

- **Compound assignment chose its opcode from the wrong type**
  (`cc/com.c`). `E1 op= E2` with a signed `E1` and unsigned `E2` did the
  operation signed. Still wrong, and a larger job: kencc performs the
  operation in the lvalue's own width, so `long x; x /= (uvlong)y;`
  divides in 32 bits on amd64 where C requires 64.
- **`&(struct S){...}`** now works; the comma is hoisted out of `OADDR`.
- **A designator list can walk back out of a nested aggregate.**
- **`char *` against `unsigned char *` warns rather than refusing.** This
  is `-Wpointer-sign`, which gcc and clang do not treat as an error, and
  portable code is full of it. One level only, and only for the five
  signed/unsigned spellings of the same type.
- **cpp:** the `#include` nesting limit was a bare `20` and is now
  `NINCDEPTH`, 200, which is what gcc and clang use — LibreSSL reaches 20
  on an ordinary chain with nothing repeated in it. `#elif` is no longer
  evaluated once a group has been selected, and `#if` does unsigned
  division without relying on the compound-assignment bug above.

---

## Headers and types

**`<string.h>` reached Plan 9's `<u.h>`**, by way of `wchar.h`,
`time.h`, `signal.h`, `pthread.h` and `lock.h` — so asking for `strlen`
also defined `nil`, `uchar`, `ushort`, `ulong` and `uint`. Every link in
that chain existed for a single pointer parameter and is now a forward
declaration; `string.h` and `wchar.h` had also been including each
other, so what a file saw depended on which it asked for first.


**`SIZE_MAX` was 32-bit on amd64** while `size_t` was 8 bytes, and
`SSIZE_MAX` was `LONG_MAX` with the same problem. The cause is worth
knowing because it will recur: stock APE keeps `float.h`, `stdarg.h` and
`stdint.h` in the *architecture* directory, which `pcc` searches **before**
`/sys/include/ape`. APExp's copies were never read on any architecture.
Worse for `stdint.h`, whose stock copy takes the same include guard as
APExp's arch header, so APExp's compiled to nothing. All three are now
shadowed by a real file in every architecture directory.

The symptom was GNU `ls` reading off the end of the heap, via a gnulib
line that means "no length given" when it sees `SIZE_MAX`.

Other header work:

- `__BYTE_ORDER` was never defined on any architecture.
- `O_DIRECTORY` was 0, so the whole `*at` family ignored real directory
  descriptors. The `O_` flags Plan 9 lacks are now defined as 0
  deliberately, and documented as such.
- `<float.h>` gained the C99/C11 macros; `<sys/statvfs.h>` and
  `<sysexits.h>` are new; `<locale.h>` no longer declares two of musl's
  file-local helpers; `<stdint.h>` lost the `u8`/`u32`/`s8`/`s32`
  typedefs that collided with everything.
- Eight headers were made self-contained, and `<netdb.h>` defines
  `socklen_t` itself rather than including `<sys/socket.h>`, which was a
  cycle.
- `S_IXUGO` is spelled the way everyone else spells it. Macro identity in
  C includes *whether* there is white space between tokens, so a
  definition differing only in spacing is a redefinition error.

---

## libap

- **`posix_spawn` honours file actions and attributes.** It was fork+exec
  with everything discarded, so `posix_spawn_file_actions_adddup2()`
  returned 0 and did nothing. Undetectable by the caller, and gnulib's
  `spawn-pipe.c` wires its pipe to the child entirely through `adddup2`.
- **`vsnprintf` left the buffer untouched when it formatted nothing**,
  and reported a truncated length when it ran out of room. It was built
  on `fmemopen`, whose write hook only lays down the terminating NUL
  *after* a write, so `snprintf(buf, n, "%s", "")` returned whatever the
  buffer held before; and the same hook's short write at the end of the
  buffer made the return value the length written rather than the length
  that would have been (C99 7.19.6.5p2 and p3), which quietly breaks
  measure-allocate-format-again. musl's own implementation replaces it.
  GNU m4's `format()` is what found it, and every parser bison generated
  had a doubled comma after each token as a result.
- **Three more stdio bugs, all found by flex.** `objc`'s scanner is the
  only thing in the tree that runs flex, so it had never worked here,
  and it uses all three within twenty lines. **`fseek` set the error
  indicator when the seek failed** — C99 7.19.9.2 says it returns
  nonzero and nothing more, and a stream you cannot seek is not a stream
  that has failed; a pipe is unseekable, so probing one poisoned it for
  good. **`freopen` returned a new stream instead of reopening the one
  it was given** (7.19.5.4), which on a permanent stream did nothing at
  all, leaving `stdout` on the terminal. **`fclose` did not close the
  standard streams** — `F_PERM` means the `FILE` is static, not that the
  file stays open (7.19.5.1), so closing `stdout` to signal end of input
  to a pipeline silently didn't. Each of these breaks ordinary programs,
  not just flex. `fseek` and `fseeko` had also drifted into two copies
  with two further bugs — a relative seek ignored buffered data, and
  neither could seek an `fmemopen` or `open_memstream` stream at all.
- **`ungetc` refused a stream that had not been read from yet**, against
  C99 7.19.7.11's guarantee of one character of pushback. It hit `stdin`
  specifically, whose static `FILE` starts with no read window.
- **`sigset_t` held three signals.** `sigaddset`/`sigdelset` were gated on
  a mask built by ORing signal *numbers* together, so only 0, 1 and 2 were
  accepted; `sigfillset()` produced a set naming SIGHUP and SIGINT alone.
  Silent, because almost nothing checks `sigaddset`'s return value.
- **`execvp` searches `PATH`.** It prepended `/bin/` and gave up, which is
  fine when everything is in `/bin` and wrong under APExp, where the APE
  binaries are reached through `PATH`.
- **`setlocale` reports the locale it set.** It ignored the name and
  answered `"C.UTF-8"` to everything, which fails C99 7.11.1.1p8 on its
  face — ask for `"C"` and you were told you got something else.
- **The `_unlocked` family is real.** It existed only as four macros in
  musl's internal header, visible by accident through the `<stdio.h>`
  leak. All fifteen are functions in libap now, declared in `<stdio.h>`.
- New: `timespec_get`, `fdopendir`, `initgroups`, `arc4random_uniform`,
  `__fpurge`, `strerrorname_np`, `ESTALE`, `EDQUOT` and the tail of
  `sys_errlist`, `IFTODT`/`DTTOIF`, `DT_WHT`.

---

## gnulib

One shared `libgnu.a` now serves coreutils, tar, diff, patch, grep, sed,
m4 and bison, with a `config-common.h` plus a per-package `config.h`.
Roughly forty modules were added over the release for the new packages,
and a dozen dropped because libap supersedes them.

The rule that matters when adding one: gnulib's replacement system
headers are *not* used — they shadow APE's — so a module that needs a
declaration needs it in the real header.

---

## Testing

The tests in `sys/lib/tests` are standalone programs. Each prints
`PASS`/`FAIL` per case, exits with the number of failures, and opens with
a comment recording which bug it came from and what that bug cost:

```
cd sys/lib/tests && pcc -o bool-test bool-test.c && ./bool-test
```

For kencc: `bool-test`, `bitfield-test`, `compound-assign-test`,
`compound-literal-test`, `designated-init-test`, `charptr-test`,
`rol64-test`, `u64float-test`, `cpp-if-test`. For libap: `locale-test`,
`sigset-test`, `posix-spawn-test`, `limits-test`, `dirent-test`,
`stdio-test`.

Anything testing a language or library rule should also be correct on
gcc, and checking a new test against gcc first is how you find out
whether the test or the tree is wrong. It has caught both.

`sys/src/ape/lib/libressl/test` is separate: upstream's own ML-KEM and
SHA-3 known-answer vectors, run with `mk test`.

---

## Known limitations

- **No dynamic loading anywhere.** Plan 9 has no `dlopen`. perl has no XS
  extensions; anything that probes for shared-library support gets a
  truthful no.
- **`static bool b = 256;` still truncates.** A file-scope initialiser is
  folded in `dcl.c` without going through the conversion path. An auto
  `bool b = expr;` is correct.
- **Compound assignment is still performed in the lvalue's width.** See
  above; fixing it means rewriting `E1 op= E2` as `E1 = (T1)(E1 op E2)`.
- **`typeof_unqual` does not strip qualifiers**, `_Alignas` has no layout
  effect, and `_Atomic` is dropped as a qualifier.
- **Sub-second `mtime` comparison is lost** in pax: APE's `struct stat`
  has `st_tim`, not `st_mtimensec`, and Plan 9's file servers do not keep
  nanoseconds anyway.
- **Header dependencies are not tracked in libap.** No mkfile under
  `sys/src/ape/lib/ap` sets `HFILES`, so editing a header rebuilds
  nothing; `mk clean` first.

---

## What's next

The remaining ports — cfront, a rebuilt objc, bacon and go 1.4 — are what
stands between this and a tag.
