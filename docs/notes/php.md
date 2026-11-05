# PHP

PHP **8.5.12**, vendored at `sys/src/external/php` (225M). Nothing is
built yet: there is no `sys/src/ape/cmd/php`. This file is the survey
that comes before the mkfile, and it is written down because most of it
is *derived* rather than guessed — the method is below each number.

## What the port is, in size

**508 objects**, with `--disable-all`. That number is not a guess: PHP's
own `configure` was run on the build host with the flags this port
wants, and `PHP_GLOBAL_OBJS` was read out of the generated `Makefile`.
The clisp precedent — derive the file list from upstream's own build
machinery rather than transcribe it.

```sh
./configure --disable-all --enable-cli --disable-cgi --disable-phpdbg \
    --without-pcre-jit --disable-opcache-jit --disable-fiber-asm \
    --disable-zend-signals --disable-huge-code-pages --without-pear
```

Where they live:

| dir | objects | note |
|---|---|---|
| `ext/lexbor` | 186 | **37% of the port**, and not optional |
| `ext/standard` | 68 | the function library |
| `ext/uri` | 34 | includes bundled `uriparser` |
| `ext/pcre` | 29 | bundled pcre2 (see below) |
| `ext/hash` | 23 | includes a bundled Keccak |
| `Zend/Optimizer` | 21 | |
| `ext/opcache` | 14 | **mandatory in 8.5** (see below) |
| `ext/date` | 11 | bundled timelib |
| `main/streams` | 10 | |
| `ext/spl` | 10 | |
| `ext/random` | 10 | |
| `ext/json` | 4 | |
| `Zend`, `main`, `TSRM` | 91 | the engine |

**`--disable-all` does not mean a small build.** `date`, `json`, `pcre`,
`random`, `reflection`, `spl`, `standard`, `hash`, `lexbor`, `uri` and
`opcache` are all unconditional in 8.5.

## What is already free

**The generated parsers and scanners are IN THE TARBALL**, so neither
`bison` nor `re2c` nor a bootstrap PHP is needed:
`Zend/zend_language_parser.c`, `zend_language_scanner.c`,
`zend_ini_parser.c`, `zend_ini_scanner.c` and the 4.2MB
`Zend/zend_vm_execute.h` are all present. *This is the gap `miniperl`
has and php does not.*

**And `zend_vm_execute.h` is dispatch-kind agnostic.** It is generated
with `#if ZEND_VM_KIND == ...` arms for every kind, so the one shipped
file serves CALL as well as HYBRID — `zend_vm_gen.php`, which would
need a working PHP, never has to run. `zend_vm_opcodes.h:40-47` selects:

```c
#elif (defined(__GNUC__) && defined(HAVE_GCC_GLOBAL_REGS))
# define ZEND_VM_KIND		ZEND_VM_KIND_HYBRID
#elif defined(HAVE_MUSTTAIL) && ... && defined(__clang__)
# define ZEND_VM_KIND		ZEND_VM_KIND_TAILCALL
#else
# define ZEND_VM_KIND		ZEND_VM_KIND_CALL
#endif
```

kencc defines none of those, so **CALL falls out by itself** — no
computed gotos, no global register variables, no `musttail`. The
portable path is the default rather than something to force.

**`zend_portability.h` is written for a non-GCC compiler.** Every
attribute and builtin is behind `__GNUC__`, `__has_attribute` or
`__has_builtin`, and lines 83-90 do the right thing when the compiler
has none of them:

```c
#ifndef __has_attribute
# define __has_attribute(x) 0
#endif
#ifndef __has_builtin
# define __has_builtin(x) 0
#endif
#ifndef __has_feature
# define __has_feature(x) 0
#endif
```

So `ZEND_FASTCALL` is empty, the atomics fall to `HAVE_NO_ATOMICS`
(`zend_atomic.h:32`), which is a plain `volatile` implementation plus a
`#warning` — **and kencc's cpp has `#warning`**: `cpp/nlist.c:38` has it
in `kwtab` and `cpp.c:278` raises it at `WARNING`, not `FATAL`. *This
was checked rather than assumed, and a first grep of the wrong two files
said it was missing.*

## The hand-answered `config.h`

`main/php_config.h` is **2239 lines, 217 `#define`s and 462
`/* #undef */`s** on Linux, and 169 of the defines are `HAVE_*`. That is
the inventory of questions, and it is derived from a real configure run
rather than invented — but **every answer still has to be given by hand**,
for the reason clisp's `mprotect` established: *a working configure would
get this machine wrong.* An autoconf probe that compiles and links is not
a probe that the thing works.

`sys/lib/tests/apfunc-sweep.py` was written for exactly this and answers
most of it mechanically. Of the 106 `HAVE_*` names that could plausibly
be functions: **69 defined, 4 declared-only, 33 absent.**

**The declared-only four are the ones that matter**, because a
`config.h` claiming them link-fails a long way from the claim:

| name | state |
|---|---|
| `ctime_r` | declared in `<time.h>`, implemented nowhere — **fixed**, see below |
| `memfd_create` | declared in `<sys/mman.h>`, implemented nowhere |
| `copy_file_range` | the sweep's hit is in `errno.h`; not confirmed as a declaration |
| `alignof` | the hit is a `pstl` header; not a function |

**And the `absent` list must not be read as an answer.** Most of its 33
entries are not functions at all — `asm_goto`, `attribute_aligned`,
`bundled_pcre`, `cpuid_count`, `gcc_global_regs`, `ipv6`, `lexbor`,
`shm_ipc`, `shm_mmap_anon`, `shm_mmap_posix`, `st_blocks`, `tm_zone` —
and two of those are **wrong if taken at face value**:

* `HAVE_TM_ZONE` is **yes**: `sys/include/ape/time.h:68-69` has
  `tm_gmtoff` and `tm_zone` in `struct tm`.
* `HAVE_ST_BLOCKS` is **yes**: `sys/include/ape/sys/stat.h:24-25` has
  `st_blksize` and `st_blocks`.

*A sweep over function names, asked about a struct field, answers
`absent` confidently.* It is the right instrument for the other 104.

The genuine function absences, all of them guarded upstream and none of
them a blocker: `fdatasync` (falls back to `fsync`), `fopencookie`,
`ftok`, `getifaddrs`, `getloadavg`, `gettid`, `getwd`, `lchown`,
`openpty`, `prctl`, `pthread_attr_getstack`, `pthread_getattr_np`,
`res_nsearch`, `statfs`. `explicit_bzero` is absent and php **ships its
own** (`main/explicit_bzero.c`, already in the object list).

## The three things that can still stop it

### 1. Fibers have no context switch here — OPEN

`Zend/zend_fibers.c` is unconditional (`Fiber` is a language class) and
needs one of two implementations:

* boost.context assembly — the default, and the two files configure put
  in the object list before `--disable-fiber-asm` were
  `Zend/asm/make_x86_64_sysv_elf_gas.lo` and
  `jump_x86_64_sysv_elf_gas.lo`. GAS syntax, which this tree has a front
  end for, of unmeasured quality.
* `ZEND_FIBER_UCONTEXT`, which wants `<ucontext.h>` and
  `getcontext`/`makecontext`/`swapcontext` (`zend_fibers.c:426-522`).
  **APExp has no `ucontext.h` and none of the four functions.**

So one of them has to be built. Writing `ucontext` for amd64 is the more
reusable of the two — it is `setjmp`/`longjmp` plus a stack switch, and
libap's amd64 `setjmp` already works (clisp exercises it hard) — but it
is a libap addition with its own invariants, not a line of `config.h`.
*Decide before writing the mkfile, because it changes what the mkfile
has to build.*

### 2. `ext/opcache` is mandatory, and its shared memory is not

There is **no `--disable-opcache`** in 8.5: `ext/opcache/config.m4`
offers only `--disable-opcache-jit`, `--disable-huge-code-pages` and
`--with-capstone`. So the 14 opcache objects compile whatever we do;
`--disable-opcache-jit` is what drops the 13 `jit/ir/*` files, which are
a native code generator and were never going to work.

What saves it is that **opcache only has to COMPILE and register, not
run**: `opcache.enable_cli` defaults to off, so a CLI php never starts
the accelerator. Its three shared-memory backends
(`shared_alloc_mmap.c`, `shared_alloc_posix.c`, `shared_alloc_shm.c`) and
their `HAVE_SHM_MMAP_ANON` / `HAVE_SHM_MMAP_POSIX` / `HAVE_SHM_IPC`
macros should therefore **all be answered no**. This is the
`HAVE_WORKING_MPROTECT` lesson in its exact shape: APExp's `shm_open`
answers success with a file in `/tmp` and its `mmap` is per-process
private, so a probe would say yes to something that cannot share a page.

### 3. The Zend allocator needs a partial `munmap` — FIXED, one half unmeasured

`Zend/zend_alloc.c`'s `zend_mm_chunk_alloc_int` allocates in 2MB chunks
that must be **2MB-aligned**, and gets the alignment the way every POSIX
allocator does: map more than it needs and unmap the overhang, head and
tail. `zend_mm_chunk_truncate` is a third such trim, on a live chunk.

Against libap as it was, both shapes were a **silent disaster**, by two
different routes — `p9_munmap` keyed its table on the mapping's start
address alone, so a head trim detached the whole segment the caller was
about to use, and a tail trim's interior address fell through to
`_SEGDETACH(addr)`, which detaches the segment that address is in.
`p9_munmap` has a partial-unmap arm now; the mechanism, the instruments
and the two deliberate breaks are in `docs/notes/libap.md`.

**The platform half is measured now and this item is CLOSED**, but not
the way it was expected to close. `mmaptrim-probe` on 9front/amd64:

* section 0 — **0 of 8** 2MB mappings are 2MB-aligned, every one
  misaligned by exactly `0x1ff000`, a 2MB grid off by one page. So
  `zend_mm_chunk_alloc_int` does take its trimming branch.
* sections 2 and 3 — **both trims survive**. The partial-unmap arm
  works on the machine as well as on the host.
* section 1 — the over-sized mapping came back aligned, *contradicting
  section 0's five*, so the placement rule is size-dependent and one
  sample of it is not a rule. In zend's real path it means no head
  trim and one tail trim.

***AND THE RUN FOUND A CEILING THAT WOULD HAVE MATTERED MORE.*** Three
of section 0's eight `mmap` calls failed, at 10MB total, which is no
memory limit at all. Section 0b separated it: **five** live mappings
at 2MB and **five** at 16MB — the same count for eight times the
memory — so the limit was Plan 9 segment slots, one spent by
`p9_mmap_impl` on every mapping at or above a 1MB `SEG_THRESHOLD`.
**Zend grows its heap in 2MB chunks, so php would have died at about
10MB of heap**, long before any trimming question arose.
`SEG_THRESHOLD` is 64MB now; `docs/notes/libap.md` has it.

## `__x86_64__` has to be defined, and it is the honest answer

**kencc defines no architecture macro at all**, and php needs one. The
consequence is not a micro-optimisation:

* `Zend/zend_long.h:26` selects `zend_long` from
  `__x86_64__ || __LP64__ || _LP64 || _WIN64` -- *not* from
  `SIZEOF_LONG` -- so without it php's integer type is **32 bits**.
* `ext/date/lib/timelib.h:112` has the identical test for
  `timelib_sll`.
* ***And five arms in `Zend/zend_float.h` read
  `!defined(__x86_64__)`***, selecting x87 control-word code
  (`_controlfp`, `_FPU_SETCW`, `fpsetprec`, inline x86 asm) that is
  wrong for an SSE machine. **Not defining it is itself a positive,
  wrong choice**, which is the argument that settles this: there is no
  neutral option.

`__LP64__` would be the available alternative and it is a **lie** --
kencc is LLP64, `long` is four bytes -- so anything keying on it to
mean "long is 64 bits" would be silently wrong. `__x86_64__` is simply
true of the machine.

**The risk is what else it switches on, and that was measured rather
than assumed.** Of the 30 files mentioning it, every site that emits
GCC inline assembly is separately gated:

| site | also needs | verdict |
|---|---|---|
| `zend_string.h:444`, `.c:394/452`, `zend_multiply.h:45/177`, `zend_execute.c:56`, `zend_cpuinfo.c:31`, `zend_vm_execute.h:364`, `TSRM.c:779` | `__GNUC__` | off |
| `zend_operators.h:566/645/731/835` | `ZEND_USE_ASM_ARITHMETIC`, which is `HAVE_ASM_GOTO` (`:547`) -- answered **0** | off |
| `zend_portability.h:561` | `HAVE_TMMINTRIN_H` / `NMMINTRIN` / `WMMINTRIN` -- all absent | off |
| `php_hash_sha.h:58` | `HAVE_IMMINTRIN_H` -- absent | off |
| `zend_vm_opcodes.h:52` | `ZEND_VM_KIND == HYBRID` -- it is CALL | off |
| `zend_cpuinfo.c:76` | nothing, but `get_xcr0_eax` and `__zend_cpuid` both have a `return 0` / zeroing fallback for a non-GCC compiler | **on, and harmless** |
| `zend_string.h:537` | nothing; a plain C multiplication hash loop | **on, and wanted** |
| `crypt_blowfish.c:56`, `md5.c:160`, murmur, xxhash | nothing; "unaligned access is cheap" | **on, and true** |

So it goes on the compile line (`-D__x86_64__`) rather than in the
`config.h`, because `timelib.h` is reached by files that have not
included `php_config.h` yet and a macro that is defined for only some
translation units is worse than one that is defined for none.

## The headers: 39 of 91 are present

Mechanical, and checkable: every `HAVE_*_H` name in the generated
config resolved against `sys/include/ape` and `amd64/include/ape`.
**39 present**, including everything structural --
`dirent`, `fcntl`, `poll`, `pwd`, `grp`, `langinfo`, `netinet/in`,
`resolv`, `syslog`, `sys/{file,ioctl,mman,param,resource,select,socket,
statvfs,stat,sysmacros,time,uio,utsname,wait}`, `utime`, `wchar`.

The 52 absent are ODBC (14 of them), tidy, the Linux `linux/*` family,
the SSE intrinsic headers, Windows, and `crypt.h` -- php bundles its
own crypt, which is why `crypt_blowfish`, `crypt_freesec`,
`crypt_sha256` and `crypt_sha512` are already in the object list.
Three absences line up with decisions already taken: no
`sys/ipc.h` (opcache's SysV shm), no `*mmintrin.h` (every SSE path),
no `sys/mount.h`/`statfs`/`vfs` (`statvfs` is what we have).

***BUT `HAVE_DLFCN_H` RESOLVES TO YES AND THE ANSWER IS NO.*** APE
ships a `dlfcn.h`, and `apfunc-sweep.py` reports `dlopen` and
`dlerror` as **declared-only** -- the middle state, a header promise
with nothing behind it. *A file-existence check answers this one
confidently and wrongly*, which is the clearest single argument in
this port for hand-answering rather than deriving: the mechanical
method is right 90 times and this is one of the others.

### And the no-atomics arm had never been compiled by anyone

`zend_atomic.c:44` answered
`argument prototype mismatch "IND STRUCT zend_atomic_bool_s" for
"IND STRUCT zend_atomic_int_s"`. It is **upstream's typo**, not
ours: `zend_atomic.h:323` declares
`zend_atomic_bool_compare_exchange_ex(zend_atomic_int *obj, ...)`,
while the other four arms -- C11, GNUC, SYNC and WIN32, at `:106`,
`:161`, `:207`, `:263` -- all say `zend_atomic_bool *`, as does every
sibling `_bool_` function in that same arm.

***IT SURVIVES BECAUSE NOBODY COMPILES THAT ARM.*** It is reached
only by a platform with no C11 atomics, no GCC atomics, no `__sync`
builtins and not Windows -- which until kencc was no platform at all.
And **gcc only warns** (`-Wincompatible-pointer-types`) where kencc
errors, so even someone who did compile it might not have noticed.
Fixed in the vendored source, one word, with the reasoning beside it.
Worth reporting upstream.

**The arm has exactly one bug, which is measured rather than hoped.**
Compiling it in isolation found nothing, because the mismatch is
between a caller and a callee and the arm is self-consistent within
itself. Forcing `HAVE_NO_ATOMICS` in a copy of the header and
compiling the real `zend_atomic.c` against it reproduces the kencc
diagnostic exactly and reports **nothing else** -- and after the fix,
nothing at all.

*Forcing it took two attempts.* The first `-I` did nothing, because
`zend_atomic.c` includes `"zend_atomic.h"` **quoted**, which resolves
next to the source file before any `-I`; the compile silently took
the GNUC arm and reported a clean result. **A forced configuration
that was not actually forced reads exactly like a passing one** --
the tell was that the `#warning` was absent, and checking for it is
what turned a false clean into a real one.

### The atomics: not worth implementing for this build, and here is why

`#warning No atomics support detected` appears on every file and is
cosmetic -- `zend_atomic.h:32` falls to `HAVE_NO_ATOMICS`, a plain
`volatile` implementation. Asked directly whether to implement real
ones, the answer is **no for this configuration**, and the reasoning
is worth keeping because it is about THIS build rather than about
atomics.

**What they actually guard here is two flags.** Across everything
this port compiles, the only consumers are `EG(vm_interrupt)` and
`EG(timed_out)` -- `zend_execute_API.c:175-176`, `:1081-1082`,
`:1466-1553`, and `zend_alloc.c:441`. Both are written from a
signal or timer handler and read by the VM loop. *That is the
`sig_atomic_t` case, not the shared-memory case.*

**This build is non-ZTS**, so there are no threads to race: the only
asynchrony is a Plan 9 note. An aligned naturally-sized load or store
on x86-64 is already indivisible, which is exactly what the
`volatile` fallback emits.

***THE ONE GENUINE GAP IS THE READ-MODIFY-WRITE***, not the loads and
stores: `zend_atomic_bool_exchange_ex` at `zend_execute_API.c:1081`
is a load then a store, and a note arriving between them could lose
a flag. The window is two instructions, and *CLI's
`max_execution_time` is 0 by default so nothing arms the timer that
would set the one flag at risk* -- so it is a real race that this
configuration does not reach.

**The cost is a libap project, not a config line.** kencc has no
`_Atomic`, no `__sync_*` and no `__atomic_*`, so real atomics mean
assembly -- `LOCK XCHG` and `LOCK CMPXCHG` -- per architecture.
`arch/amd64/tas.s` already has the primitive, so the shape is the
same as `ucontext`: amd64 first, the other ten later. **It would not
change this build at all**, since the volatile path compiles and the
warning is noise.

*Revisit if ZTS is ever enabled, or if opcache is made to actually
run with shared memory* -- those are the configurations where real
concurrency appears, and both are deliberately off here.

## Extensions: the ones with a ported library

The user's own framing, and the right one: enable what this tree already
has a library for. Present in `sys/src/ape/lib`: `onig`, `libressl`,
`curl`, `z`, `bz2`, `xml2`, `pcre2`, `sqlite`, `zip`, `zstd`, `lzma`,
`lz4`, `readline`, `history`, `intl`, `png`.

Which maps to: `mbstring` (oniguruma), `openssl` (libressl), `curl`,
`zlib`, `bz2`, `libxml`/`dom`/`simplexml`/`xml`/`xmlreader`/`xmlwriter`,
`sqlite3` + `pdo_sqlite`, `zip`, `readline`, `gd` (png only), `intl`.

***THESE ARE A DIFFERENT RISK CLASS FROM ANYTHING ON PECL, AND THAT IS
THE DISTINCTION TO KEEP.*** Every one of them SHIPS WITH php 8.5, is
tested by upstream against this exact version, and is turned on with a
`--with-X` against a library this tree already has. A PECL package is
a separate source tree with its own maintenance state and its own
target php version. *The first is a flag; the second is a port.*

**`ext/pcre` bundles its own pcre2 and that is what the 29 objects are.**
`--with-external-pcre` would use `sys/src/ape/lib/pcre2` instead; the
bundled copy is the better starting point, because it is the version php
was tested against and it removes a link dependency from the first build.

### php-lua and php-tk: a different risk class, and the answer is no for now

Asked directly, so recorded rather than left to be re-asked. **Neither
is vendored and neither ships with php** -- `sys/src/external/lua` and
`external/tk` are the LIBRARIES, and `php/ext/` has no `lua` or `tk`.
Both would be PECL packages to bring in, and PECL extensions build as
shared modules by default, which Plan 9 cannot load at all; they would
have to be linked statically and listed in the mkfile and
`internal_functions_cli.c` by hand. *That part is mechanical and the
port directory is already arranged for it.* The problem is upstream.

**`tk` is PECL 0.1.1 beta, dated 2004-11-14, and its own page says the
package is unmaintained and invites someone to take it over.** That is
the PHP 4 extension API: no `zend_string`, the PHP 7 zval rework, the
arginfo requirements and the TSRMLS removal all postdate it. This is
not an extension to enable, it is a rewrite -- *bigger than most of
what this tree has ported* -- and a GUI binding additionally needs an
event loop married to php's request lifecycle, on top of our own
`external/tk/plan9` backend. No.

**`lua` is less clear and still not first.** The PECL `lua` package
looks PHP 7-era; **LuaSandbox** is the one actually packaged for PHP
8.0 through 8.5. *Which also means it is a different extension with a
different API*, and it is worth checking before any work whether it
wants Lua **5.1** -- it comes from MediaWiki's Scribunto, which
standardised there -- because this tree ships **5.5.0**. A version
mismatch would be its own port.

**No extension should be enabled in the first build.** The order that
has worked in this tree is: get the thing to compile and print its own
version, then add one library at a time.

## The port directory

`sys/src/ape/cmd/php/` holds six files and **nothing in
`sys/src/external/php` is touched** -- the vendored tree stays vendor
source, and the mkfile puts `-I.` first so our copies win:

| file | what it is |
|---|---|
| `mkfile` | 513 objects, derived from upstream's configure |
| `php_config.h` | the hand-answered one |
| `zend_config.h` | the one line `zend_portability.h:43` wants |
| `timelib_config.h` | routes timelib through the Zend allocator |
| `build-defs.h` | the install paths |
| `internal_functions_cli.c` | the eleven built-in extension entries |

***THE OBJECTS KEEP THEIR PATHS, AND THAT IS NOT COSMETIC.*** Sixteen
basenames collide across the 43 source directories -- `array.c` is
both `ext/standard/array.c` and `ext/lexbor/lexbor/core/array.c`, and
`hash`, `parser`, `state`, `token`, `url` and ten more are the same.
A flat `OFILES` would build one and link it twice, silently. php is a
PROGRAM rather than a library, so there is no archive member to
collide and nested paths cost only a `mkdir` in the rule -- *the
`ar`-member collision that a library would have had is the same shape
as the stale `mcontext.6` in `docs/notes/libap.md`, avoided here by
not having an archive at all.*

Two mkfile details that are rules rather than taste. **Each comment
inside the `OFILES` list ends with a backslash**, which is
`mkcont-sweep.py`'s rule: a comment that ends a continuation ends the
variable, and the rest of the list would vanish without a word. And
**`HFILES` names the four hand-kept headers**, because mk does not
scan `#include`s -- without it, editing `php_config.h` rebuilds
nothing and the next run measures the old binary, which is how
`HELP_BUILTIN` was turned on and did not reach bash.

`mkcont-sweep` and `rceq-sweep` both pass; `apehdr-sweep` is
**identical with and without** the new `<ucontext.h>` (151/152
headers, the same 8 pre-existing TOGETHER errors), which is a control
rather than a reading of the messages.

**php is deliberately NOT in `sys/src/ape/cmd/mkfile`.** One failing
entry aborts the whole tree's `mk`, and a port that has never been
built has not been measured in that position. `cd sys/src/ape/cmd/php
&& mk` is how to try it.

### What the first `mk install` said, and both answers were cheap

**`mkfile:612: syntax error`** -- the `OFILES` list ended one line
early, leaving a tab-indented entry orphaned. `mkcont-sweep` reported
0 over it, and is widened now; see `CLAUDE.md`.

**`basename: invalid option -- d`** -- the rule used Plan 9's idiom
for a dirname, and inside `apexp-sh` the union puts APExp's own
`/bin` first, so `basename` is **GNU coreutils'**. *A command name
here is whatever the union resolves it to.* The rule uses a static
directory list now and runs no external command at all.

***AND `no recipe to make 'ext/json/json_parser.6'` HAD A BETTER
ANSWER THAN EXPECTED.*** `ext/json`'s parser is bison-generated and
**the generated file ships in the tarball** as `json_parser.tab.c`,
so the object upstream calls `json_parser.lo` is built from a source
whose name does not match it. One explicit rule covers it.

The useful half is what the check found rather than what it fixed:
**all 513 objects were resolved against the vendored tree and this was
the only name that does not** -- so **no bison and no re2c are needed
anywhere in this port**. `json_scanner.c` and
`php_json_scanner_defs.h` are shipped too, alongside the four Zend
parsers and scanners and the 4.2MB `zend_vm_execute.h`. *A question
that could have cost two more build tools cost one grep.*

### The include layout, and the four headers under `cfg/`

`TSRM/TSRM.h:20` says `#include <main/php_config.h>` while
`Zend/zend_frameless_function.h` and `ext/opcache/zend_shared_alloc.c`
say `#include <php_config.h>`. **Both spellings have to work**, and
upstream gets that for free because the generated config really does
sit at `main/php_config.h` under the php root.

So the hand-kept headers live in `cmd/php/cfg/`, with the answers in
`cfg/main/php_config.h` and `cfg/php_config.h` a one-line redirect --
*two hand-maintained files that must agree are one file too many*,
which is the warning CLAUDE.md already carries about perl's
`Config.pm` and its `config.h`. One `-Icfg` answers all four
spellings.

***AND `-I.' IS DELIBERATELY ABSENT.*** The build writes its objects
into `main/`, `Zend/`, `TSRM/` and `ext/` in the build directory, so
`.` on the include path would put directories named after php's own
source trees in front of php's own source trees. It is also why the
headers are under `cfg/` rather than in a `main/` beside the mkfile:
**`clean` does `rm -rf main`**, and a committed header there would be
deleted by it.

### Per-directory flags, and why they are 32 explicit rules

Preprocessing all 513 sources on the host found **31 with an
unresolvable include**, in two clusters, and the fix is flags rather
than files:

* **pcre2, 28 files** -- `pcre2_internal.h:68` includes
  `<AbandonCompile>` on purpose when `PCRE2_CODE_UNIT_WIDTH` is unset.
  Upstream passes `-DHAVE_CONFIG_H -DHAVE_MEMMOVE` and
  `-I.../ext/pcre/pcre2lib`, where pcre2's own `config.h` lives.
* **Keccak, 3 files** -- `KeccakP-200-SnP.h` is *excluded by a flag*,
  `-DKeccakP200_excluded` and its two siblings, plus
  `-I.../ext/hash/sha3/generic64lc`.

***THE FLAGS CANNOT GO IN THE GLOBAL CFLAGS, AND THAT WAS MEASURED
RATHER THAN FEARED.*** `-DHAVE_CONFIG_H` together with
`-I.../pcre2lib` would hand `ext/json/json.c:18`,
`json_encoder.c:18` and `main/php_odbc_utils.c:18` -- each of which
is `#ifdef HAVE_CONFIG_H / #include <config.h>` -- **pcre2's**
`config.h`. Not a failure: a different header, silently.

The rules are explicit rather than patterned because mk's precedence
between a general and a specific meta-rule is something I would be
recalling rather than reading, there is no mk on the build host to
check it with, and a wrong guess costs a VM round trip. *Explicit
beats meta-rule in every mk, which needs no checking at all.*

**All 31 were found in one host pass**, `gcc -E` over every source
with the real include paths, filtered to `No such file or directory`.
One sweep instead of 31 round trips.

### The first real C diagnostic, and it was an omission in the config.h

`TSRM/TSRM.c` compiled -- the first object of the port -- and
`Zend/Optimizer/block_pass.c` then answered, from
`Zend/zend_map_ptr.h:82`:

```
not a function
not a parameter: zend_map_ptr_reset
syntax error, last name: ZEND_API
```

`ZEND_API void zend_map_ptr_reset(void);` with `ZEND_API` an
undefined identifier -- and **every `ZEND_API` in php is that shape**,
so the first file to declare anything would have failed whichever one
it was.

***THE CAUSE IS A BLIND SPOT IN HOW THIS FILE WAS WRITTEN.***
`autoheader` emits only `#undef NAME` lines; anything spelled
`#define` in a `.h.in` is **text copied straight through**.
`main/php_config.h.in:7-15` copies three -- `ZEND_API`,
`ZEND_DLEXPORT`, `ZEND_DLIMPORT` -- under an `#if defined(__GNUC__)`
whose `#else` arm makes all three empty. *Reading the generated
config as a list of capabilities, which is exactly the method used
here, does not show them.* The prologue is copied verbatim now; its
guard was already right for kencc.

**21 names were missing in all**, and the one check that shows them
is a diff of the two name sets. That is `sys/lib/tests/cfghdr-sweep.py`
now, which gates on this class and reports two others -- and found
two things on its first run beyond the case it was built for:

* **`PHP_OS_FAMILY` was mine and was a collision.** `main/php.h:38-51`
  computes it from the platform macros, ending in an unconditional
  `#else "Unknown"`, so php.h would have redefined it with a different
  string. Plan 9 defines none of `BSD`, `__linux__` or the rest, so
  php answers `"Unknown"`, which is simply true. Removed.
* **Five in clisp's hand-answered config** -- `_GL_UNUSED`,
  `_UNUSED_PARAMETER_`, `__GNUC_STDC_INLINE__` and two under a dead
  `__SUNPRO_CC` arm. clisp builds and runs, so nothing it compiles
  uses them; *recorded, not acted on*, which is why clisp is not in
  the sweep's gating list.

### `MIN`/`MAX`, and the header at fault was ours

`zend_optimizer.c` stopped on
`/sys/include/ape/sys/param.h:36 ... Macro redefinition of MIN`.
php is careful here -- `Zend/zend_portability.h:479-482` is
`#undef MIN` / `#undef MAX` and then its own spelling -- and
`main/php.h:215` then includes `<sys/param.h>`, which redefined them
with a different token sequence. *This tree's own rule that a macro's
identity includes whether there is white space, arriving from the
other side.*

**The fix is APE's, not php's.** `MIN`/`MAX` are not POSIX, so a
program that wants them defines its own; glibc and the BSDs both wrap
theirs in `#ifndef` for exactly that reason, and APE's copy came from
musl, which is the odd one out. Guarded now. *The guard can only turn
an error into a success*, since it changes nothing unless the name is
already defined and that case is a diagnostic today. A grep for every
other definition of these names in the APE headers found none.

### And the same mistake had a second half: the EPILOGUE

The next build got past `ZEND_API` and stopped at
`zend_operators.h:308`:
`incompatible types: "IND VOID" and "INT" for op "RETURN"`, on
`return mempcpy(dest, src, n);`.

`mempcpy` is declared, unguarded, at `sys/include/ape/string.h:62` --
and **`<string.h>` was not reachable in that translation unit at
all**. `Zend/zend_operators.h` does not include it; the only thing
that does is `main/php.h:208`, which a Zend file never reaches.
***`memcpy`, `memcmp` and `strncasecmp` were undeclared in the same
unit and said nothing***, because an implicit `int` converts to
`size_t` in silence: *the pointer return was the only one loud
enough to notice.*

`main/php_config.h.in:2225-2236` ends with four `#include`s --
`<stdlib.h>`, `<sys/types.h>`, `<sys/select.h>`, `<string.h>` -- and
that is how every unit in php sees them. **The same category as the
prologue, missed for the same reason**, and `cfghdr-sweep` could not
see it either, because its first version compared macro NAMES and an
`#include` has none. It compares both now, and its control carries
both shapes.

*The host reproduced the whole thing* -- `gcc -fsyntax-only` on
`block_pass.c` with the real flags listed the same implicit
declarations -- which is how it was diagnosed without a second round
trip. One residual host-only artifact: `memrchr` still warns there,
because glibc guards it behind `_GNU_SOURCE` while APE declares it
unguarded at `string.h:54`. *Not a finding; the host's limit.*

The other 18 are `_GNU_SOURCE` and its family, `__STDC_WANT_*`, and
two Linux headers. **Left out deliberately**: APE's feature macros are
`_POSIX_SOURCE`, `_BSD_EXTENSION` and `_PLAN9_SOURCE`, which the
mkfile already passes, and `_GNU_SOURCE` would be a claim about
headers this platform does not have.

## What the config.h decided, and why by hand

The long reasoning is in the file itself; what matters as a summary:

***TWO MACROS ARE ANSWERED NO FOR CAPABILITIES THAT ARE PRESENT, LINK,
AND RETURN SUCCESS.*** This is clisp's `mprotect` rule, twice:

* **`HAVE_MPROTECT`** -- `plan9/mman.c:44` is `return 0`, a stub
  answering success. Nothing it is asked to protect is protected.
* **`HAVE_MREMAP`** -- *and this one is worse, because the caller is
  told it succeeded at something else*. APExp's `mremap` allocates and
  copies: it MOVES. `zend_mm_chunk_extend` calls
  `mremap(addr, old, new, 0)` with no `MREMAP_MAYMOVE` precisely
  because it needs the chunk to stay put, and returns success on
  anything that is not `MAP_FAILED`. Zend would record a chunk as
  extended in place while the memory had moved: not a failure, a
  silently wrong heap.

A configure probe that compiles and links cannot tell either of these
from the real thing. *That is the whole argument for hand-answering,
and php supplies it twice without being asked.*

**`STRERROR_R_CHAR_P` is unset and copying the host answer would have
been a real bug**: glibc's `strerror_r` returns `char *`, APE's is
POSIX's returning `int` (`<string.h>:45`). php would have used an
`int` as a pointer.

**`ZEND_CHECK_STACK_LIMIT` is unset, and the cost is recorded rather
than hidden**: `zend_call_stack.c` finds the stack bounds through
`pthread_getattr_np`, `pthread_attr_getstack`, `/proc`, `sysctl` or a
Windows call, and APExp has none. Deep PHP recursion will fault
instead of raising an error.

**`HAVE_IPV6` is unset and that is a CHOICE, not a finding.**
`AF_INET6` and `struct sockaddr_in6` both exist. Nothing in this tree
has ever exercised IPv6 through APE's socket layer, and a port's first
build is the wrong place to open an unmeasured path. Revisit with a
test, not with an edit.

***AND A QUESTION ANSWERED ITSELF.*** The sweep found **37 functions
APE has that the host configure left `#undef`** -- `clock_gettime`,
`select`, `strndup`, `times`, `utimes`, `pread`, `getlogin` and so on
-- which looked like a judgement call about enabling code paths
upstream never compiles on Linux. It is not: **`grep` says all 37 are
referenced in 0 files** of what this port builds. Nothing reads them,
so there was nothing to decide.

## ALL 514 TRANSLATION UNITS COMPILE, AND THE MEASUREMENT IS A HOST ONE

`sh sys/lib/tests/hostkencc/php-mirror.sh --compile` answers
**`compiled 514, errors 0, missing 0`**: the whole build, by a
host-built `6c`, with the mkfile's own flags.

***THE INSTRUMENT IS THE POINT, NOT THE NUMBER.*** The eight rounds
before this one each cost a VM rebuild to learn about one compile
error, the error in the next file being invisible until the first was
fixed. `php-mirror.sh` reads `DEFS`, `INCS`, `PCRE2FLAGS`,
`KECCAKFLAGS` and the 514-entry `OFILES` **out of `cmd/php/mkfile`
with sed** — derived, not transcribed, so a mirror cannot drift from
the build — stages the one shadowing header the host needs
(`stddef_arch.h` includes `<stddef.h>`'s body by absolute path), and
compiles the lot in about a minute. *Eight errors came back in the
first run, in six files, and all six were fixed and re-measured
without the VM.* The fidelity limits are `hostkencc.sh`'s and
unchanged: **sound for "does it compile" and "what does it diagnose",
unsound for anything keyed on `long` being 32 bits**, since the host
build is LP64.

***AND IT MEASURES THE LINK TOO, WHICH THIS SECTION FIRST SAID IT
COULD NOT.*** The claim was "the host has no libap and `hostkencc`
deliberately does not build the linkers, so this one is the VM's" —
and **neither is needed**. `6c -S` prints, per translation unit, every
symbol it defines (`TEXT`/`GLOBL`, with `<>` for a file-local one) and
every symbol it references; the program's undefined set is the
references minus the global definitions minus each unit's own statics,
over all of them at once. `php-mirror.sh --undefined` does that and
hands the result to `apfunc-sweep.py`. *A capability was written off
from the shape of the tool rather than from the question being asked*
— the same error as "kencc cannot be compiled on the build host",
which `cpp-xcheck` then disproved for a whole directory.

### The link: four symbols, two causes

`mk install` reached `6l` and named four undefined names.

**`_volatile__`**, referenced by `__jit_debug_register_code`, is
kencc's: `__asm__ __volatile__("")` — the scanner knew `__asm__` and
not GNU's `[volatile] [inline] [goto]` qualifiers, so the qualifier
was lexed as an identifier and CALLED. 50 vendored files in this tree
use that spelling. Fixed in `cc/lex.c`, and *writing the two-line test
for it found that `__extension__` had been eating the first character
of whatever followed it* — both in `docs/notes/kencc.md`.

**`lxb_dom_collection_create`, `_init` and `_destroy`**, referenced by
`lxb_dom_collection_make`, are a build-list question with a compiler
reason underneath. That function is a `static inline` in
`lexbor/dom/collection.h`, which `node.h` and `element.h` both
include, so **every one of the many units reaching those headers
emits it** — *kencc emits an unused static function and gcc at -O2
discards it*. The three functions it calls live in
`lexbor/dom/collection.c`, and `ext/lexbor/config.m4:51-63` does not
list that file, because upstream never needs them. The mkfile
compiles it; it is lexbor's own code and self-consistent. **The
general form is worth keeping**: a header-only helper that calls into
a file the port does not compile is a link error here and silence on
gcc.

### The four extensions Phoronix needs, and three derivation faults

`php-smoke.php` is **0 failures** on the VM and Phoronix now reaches
its own requirement check instead of crashing. What it asks for is in
`pts-core.php:208`, and the error message is misleading in a way that
matters:

	array(1, extension_loaded('zip') || extension_loaded('zlib'), 'ZIP', ...)

**"MISSING ZIP" is satisfied by ext/zlib**, so libzip is not involved
at all. With JSON already built, the required set is **libxml + dom +
simplexml + zlib** -- 37 + 1 + 3 + 3 = 44 objects against two
libraries this tree already carries, `lib/xml2` (2.15.2) and `lib/z`.
dom also depends on `lexbor`, which this build already has for its own
sake. **559 translation units compile, 0 errors.**

#### Linking is by `#pragma lib`, not by a mkfile variable

`<zlib.h>:34` has always carried `#pragma lib "/$M/lib/ape/libz.a"`;
`<libxml/xmlversion.h>` carries one now. `cc/macbody:728` reads it and
records the archive in the object, and `apexp-sh`'s bind makes that
path this tree's copy -- so no `LIB=` line, and *every* libxml2
consumer links correctly rather than just this one.

**It goes in `xmlversion.h` because that is the header every other one
reaches**: 42 of the 46 installed `<libxml/*.h>` include it, and the
three that do not -- `SAX.h`, `nanoftp.h`, `xmlunicode.h` -- are empty
deprecation stubs that declare nothing and so cannot create a
reference. *Checked, not assumed.* **Measured**: a TU including it
records `<libxml2.a` in the object, exactly as a TU including
`<zlib.h>` records `<libz.a`, and one including neither records
nothing.

*The hazard is that the header is otherwise byte-identical to the
vendored copy*, so a re-sync drops the pragma and every consumer then
fails to link with no hint why. `<zlib.h>` has the same arrangement
and the same exposure; both say so in the file.

#### THREE DERIVATION FAULTS IN ONE LIST, EACH FOUND BY THE NEXT CHECK

The object list was *derived* from each extension's own `config.m4`,
which is this tree's rule -- and the derivation was wrong three times:

1. `^ *[a-z0-9_]+\.c$` **cannot match a path with a slash**, so
   `parentnode/css_selectors.c` and `parentnode/tree.c` vanished.
   ***And the completeness check compared the result against
   `ls *.c`, which cannot see a subdirectory either*** -- 34 against
   34, agreeing because both sides shared the same wrong assumption.
   *A derivation and its check have to fail independently, or the
   check is decoration.* `--undefined` caught it by naming
   `dom_parent_node_append`.

2. Widening the class to allow `/` found those two and **still missed
   `lexbor/selectors-adapted/selectors.c`, for the hyphen**.
   `--undefined` caught that one too, naming `lxb_selectors_init`.

3. Widening it again to `[^ \t"]+\.c` matched fragments mid-token and
   produced `dom/ion.c`, `dom/ype.c`, `zlib/er.c` -- garbage that an
   existence check does filter out, but by then the method was
   plainly wrong.

**The answer was to read the block.** dom's `PHP_NEW_EXTENSION` is 37
plain lines, and the `PHP_ADD_BUILD_DIR` directly under it names both
subdirectories -- which is also where the `OBJDIRS` entries come from.
*Two rounds were spent widening a regular expression against a file
short enough to read.*

#### The instrument had to grow with the build

`--undefined` asked `apfunc-sweep.py`, which knows **libap and
nothing else** -- correct while every port linked only libap, and
wrong the moment php pulled libxml2 and libz: it answered `absent`
for 241 of 539 names. *The same shape as that sweep's own recorded
wrong-`ROOT` failure, from the other direction -- not a corpus that
does not exist, but one that is merely incomplete.* It takes
`--root DIR` now, repeatable, default unchanged, and `php-mirror`
passes the two library trees. **Add a root there for every library a
new extension links.**

### CLOSED: every multiplication over 2**32 was a float

`exit()` fixed, the smoke test runs to completion and **the exit
status is usable again** -- the shell printed `2`, which is the count.
The two that remained were both

	is_int(-9223372036854775807 - 1)   -> false
	(-9223372036854775807 - 1) === PHP_INT_MIN   -> false

while `PHP_INT_MIN` itself was a clean int and `PHP_INT_MIN +
PHP_INT_MAX` was -1. So the constant was fine and something in the
expression produced a float.

***THE SUBTRACTION WAS INNOCENT AND THE COMPILER SAID SO.*** The host
kencc compiled php's real `Zend/zend_operators.c`, and
`fast_long_sub_function` is `SUBQ`, then `ANDQ` with the sign mask in
a register, then `CMPQ` -- 64 bits throughout, and tracing it by hand
with 0x8000000000000001 and 1 takes the integer arm. *Reading the
generated code of the real function beat three rounds of reasoning
about which `#elif` arm the config selects.*

**PHP compiles unary minus as `(-1) * x`**, so the float came from
the MULTIPLY. `zend_multiply.h:132`'s fallback -- the arm taken when
there are no `__builtin_*_overflow`, no `__GNUC__` asm and no Win32,
which is exactly this port -- opens

	long   __lres  = (a) * (b);

**Every other arm in that file is guarded by
`SIZEOF_LONG == SIZEOF_ZEND_LONG` or `SIZEOF_ZEND_LONG == 4`; this one
assumes it.** `long` is 32 bits here and `zend_long` is 64, so
`__lres` held the product's low half, the delta test against
`__dres` reported an overflow that had not happened, and the answer
came back a double.

***SO EVERY INTEGER MULTIPLICATION WHOSE PRODUCT DID NOT FIT IN 32
BITS SILENTLY RETURNED A FLOAT.*** `2000000 * 2000000` was
`float(4.0E+12)`. That is a wrong answer in the commonest arithmetic
there is, it is silent, and it would have reached every php program
ever run here.

`zend_long __lres` now. The before/after `-S` diff is the whole story
in four lines:

	<  IMULQ  SI,DI          >  IMULQ  SI,CX
	<  MOVQL  DI,CX             (the product truncated to 32 bits)
	<  CVTSL2SD CX,X1        >  CVTSQ2SD CX,X1
	<  MOVLQSX CX,SI         >  MOVQ   CX,(DX)

**And the test is the thing to correct, not just the code.** Its
first version covered `+`, `-`, `max`, `strlen` and `str_repeat` and
**not `*`** -- it caught this only sideways, through unary minus, and
nothing in the failing output said the word multiply. Section 3b asks
directly now, including two cases that a fix which simply never
reports an overflow would fail: `PHP_INT_MAX * 2` and `PHP_INT_MIN *
2` must still be floats.

*This is the tree's most-cited invariant -- `long` is 32 bits on
amd64 -- arriving in upstream code that is correct on every LP64
platform, for the second time in two rounds after `sizeof`.*

### CLOSED: `exit()` was kencc's 32-bit `sizeof`

Three one-liners on the VM settled it with no rebuild:

	php -r 'echo "no-exit\n";'          -> clean
	php -r 'echo "exit0\n"; exit(0);'   -> 4294971392
	php -d memory_limit=1 -r 'exit(0);' -> same, same limit

**A script that just ends is clean**, so request shutdown and module
shutdown are both fine and it is `ZEND_EXIT` alone.

`exit` calls `zend_throw_unwind_exit`, which is
`zend_objects_new(&zend_ce_unwind_exit)`, and that is

	emalloc(sizeof(zend_object) + zend_object_properties_size(ce))

with `zend_object_properties_size` (`zend_objects_API.h:83`):

	sizeof(zval) * (ce->default_properties_count -
		((ce->ce_flags & ZEND_ACC_USE_GUARDS) ? 0 : 1))

`UnwindExit` is `INIT_CLASS_ENTRY(..., "UnwindExit", NULL)` -- zero
properties -- and `ZEND_ACC_USE_GUARDS` is set only under
`CG(compiler_options) & ZEND_COMPILE_GUARDS`, **which nothing in php
ever sets**. So the subtraction is `0 - 1`, deliberately: `zend_object`
ends in `zval properties_table[1]`, so a class with no properties wants
one zval less than the struct, and `sizeof(zval) * -1` is 2**64-16,
which the caller's `+ sizeof(zend_object)` wraps back to **40**.

***UPSTREAM IS RIGHT AND THE COMPILER IS THE DEVIATION.*** C makes
`sizeof` a `size_t`, 64 bits here; kencc types it TULONG, 32 bits
(`cc/com.c:894`, on purpose). `6c -J -S` on the expression:

	SUBL / SALL $4 / MOVLQZX

-- 32-bit subtract, 32-bit multiply, **zero-extend** -- so 4294967280
instead of 2**64-16, plus 56 is 4294967336, page-rounded to
**4294971392**. The same source under gcc asks for 40. *Both numbers
were run, not reasoned.*

Fixed in the vendored header by computing in `ptrdiff_t`, which is
signed and size_t's width on every target; kencc then emits
`MOVLQSX` / `SUBQ` / `SALQ` and agrees with gcc. 515 TUs still
compile. **The compiler change is recorded and not taken** --
`docs/notes/kencc.md` has the trade and the controls -- so *the same
idiom elsewhere is still exposed*, and three more instances in php's
optimizer are named there.

**Two reading errors on the way, both worth keeping.** I blamed
`display_text_table`'s padding loop from the line number alone; the
smoke test's reduction of that loop passes, and the real line was
`exit` in both programs. And my first reduction of the size expression
declared `default_properties_count` as `uint32_t` when it is `int`, so
gcc "confirmed" a 68GB request and briefly made upstream look broken on
Linux too. *A reduction that changes a type is not a reduction.*

### The smoke test ran, and it moved the bug

`php-smoke.php` on the VM: **44 of 45 cases pass**, including
`PHP_INT_SIZE` 8, `PHP_INT_MAX`, `strlen`, `max`, `str_repeat` at
100k, every arithmetic case, preg, json, and `/net/tcp/stats` read as
404 bytes. `PHP_OS = Plan9, PHP_VERSION = 8.5.12`. **The interpreter
evaluates correctly.**

***SO THE PHORONIX DIAGNOSIS WAS WRONG, AND THE TEST IS WHAT SAID
SO.*** Section 5 reproduces `display_text_table`'s padding loop over
the exact table php had printed, and it **passes** -- `$m` is 15, not
2**32. The crash is not in the loop.

**It is in `exit`.** The smoke test's own last line is

	Hard memory limit of 268435456 bytes exhausted
	(tried to allocate 4294971392 bytes) in php-smoke.php on line 194

and **line 194 is `exit($fails);`** -- printed *after* the test's own
total, so everything before it ran. Phoronix's line 854 is `exit;` in
the same `if($do_exit)` block. *Two unrelated programs, same line
kind, same byte count to the digit.*

**The size decomposes and the decomposition is the lead**:
4294971392 is 1048577 pages of 4096, i.e. a request of just over
2**32 rounded up by one page -- a length of **exactly 2**32** plus a
small header. And `2**32 == (uint32_t)-1 + 1`. So the shape is a
**32-bit -1 ZERO-extended into a 64-bit size and incremented**, not a
sign-extended one (that would be `(size_t)-1`, and `len+1` would be
0). *An identical size in two programs of different sizes is not
data-dependent.*

**What runs there**: `exit` compiles to ZEND_EXIT, which calls
`zend_bailout`, which is `LONGJMP(*EG(bailout), FAILURE)` --
and `zend_portability.h:427` makes that **`siglongjmp` into a
`sigjmp_buf`, unconditionally on non-Windows**; there is no
`HAVE_SIGSETJMP` test to answer. APExp's `sigsetjmp` is assembly
(`arch/amd64/setjmp.s`) and its `siglongjmp` is C
(`arch/amd64/notetramp.c:83`), and the two agree about the layout on
inspection -- 30 ints is 120 bytes against the 80 the pair uses, and
the C side passes `&jmpbuf[0]`, not the base. **So nothing is yet
ruled in or out**; what is established is that the fault is on the
bailout-and-shutdown path and not in the engine.

**Three one-liners separate the remaining possibilities**, with no
rebuild:

	php -r 'echo "no-exit\n";'            # ends without exit()
	php -r 'echo "exit0\n"; exit(0);'     # bailout
	php -d memory_limit=-1 -r 'exit(0);'  # same, limit removed

A clean first and a dying second puts it on `zend_bailout`; both
dying puts it on request shutdown generally; and the third turns a
clean `_exit(137)` into a real allocation failure or a fault, which
`acid` can name the way it named `zend_string.h:401`.

### The first real program: Phoronix, and a 2**32

`php -v` works, `php -h` works, and **the port has still never been
measured evaluating anything** -- a version string is printed before
the engine runs an opcode. The first real program put on it, the
Phoronix Test Suite, said two things.

**The expected one**: `MISSING DOM`, `MISSING ZIP`, `MISSING
SimpleXML`. That is `--disable-all` working as intended and is not a
fault; what it costs is written up in `plas_stack_readme.md`, together
with the fact that **libxml2, libzip, zlib, SQLite, curl, LibreSSL and
oniguruma are all already ported in `sys/src/ape/lib`** -- so every
one of those extensions is mkfile work against a library that exists.

***THE OTHER ONE IS A REAL BUG AND THE NUMBER NAMES ITS SHAPE.***

	Hard memory limit of 2147483648 bytes exhausted
	(tried to allocate 4294971392 bytes) in pts_client.php on line 854

**4294971392 is 2**32 + 4096.** No program asks for that; it is a
64-bit quantity whose low half is sane and whose high half holds a 1,
page-rounded on the way through the allocator. The 2GB limit is
Phoronix's own `memory_limit`, so only the second number is ours.

Line 854 is `pts_user_io::display_text_table($exts)` -- *printing the
very table of missing extensions that appears above it* -- and that
function's inner loop is six lines:

	$m = max($min, 1 + $extra + $widths[$c]) - strlen($cell);
	if ($m > 0) $line .= str_repeat(' ', $m);

So `$m` came out near 2**32 and `str_repeat` was the victim rather
than the culprit. **The fault is in `strlen` or in integer
arithmetic**, which is the first place to look anyway: `zend_long` is
chosen from `__x86_64__` and is 64 bits, while kencc's `long` is 32
and `php_config.h` answers `SIZEOF_LONG 4`. *Both of those are
correct and they disagree with each other.*

`sys/lib/tests/php-smoke.php` is the instrument that should have
existed before Phoronix was ever started: PHP_INT_SIZE and
PHP_INT_MAX first, then `strlen`, then the exact padding expression,
then `str_repeat`, then the whole failing loop reduced to the table
php had just printed. **It has a real reference implementation** --
the build host's own php -- and nothing in it is newer than PHP 8.0,
so a case that fails on the host is the test's bug. *Its first host
run found one: my own expected padding was 14 and the answer is 15.*
0 failures on 8.3.6 now.

**Also seen and not diagnosed**: `warning: process exceeds 100 file
descriptors`, twice, from the kernel. Phoronix walks directories, so
it may be ordinary; it may also be an `opendir` that never closes.
Recorded, unmeasured.

### It links, it runs, and the first fault was opcache's

`6.out --version` prints

	PHP 8.5.12 (cli) (built: Nov  5 2026 16:19:35) (NTS)
	Copyright (c) The PHP Group
	Zend Engine v4.5.12, Copyright (c) Zend Technologies

and then dies: `suicide: sys: trap: fault read addr=0x4 pc=0x7ef0f7`.

**Two things were wrong and they are unrelated.** `mk install` could
not copy the binary at all -- `null list in concatenation`, because
nothing set `BIN` and `mkone`'s rule is `cp $prereq $BIN/$TARG`; the
mkfile now assigns it like every other APE command's. The fault is
below.

***THE DIAGNOSIS COST ONE COMMAND AND NO REBUILD, BECAUSE THE CLI HAS
AN EXIT PATH THAT SKIPS THE SHUTDOWNS.*** `php_cli.c:1318`'s `-h`
arm does `php_cli_usage(); goto out;` while `module_started` and
`sapi_started` are still 0 -- they are set at `:1337` and `:1359`,
after `exit_loop` -- so `-h` runs `exit()` and neither
`php_module_shutdown()` nor `sapi_shutdown()`. **`./6.out -h` exits
clean**, which cleared libap's `exit`, the stdio teardown and
`php_ini_builder_deinit` in one line and left two functions standing.
*Two outcomes, one command, no acid and no rebuild* -- and the
alternative was nine candidate calls to read.

Then `acid 6.out` and `src(0x7ef0f7)`:

	Zend/zend_string.h:401
	>401       if (!ZSTR_IS_INTERNED(s)) {

`zend_string_free(NULL)`. **The address agrees with the source**:
`zend_refcounted_h` is `{uint32_t refcount; union {uint32_t
type_info;} u;}`, so `GC_FLAGS` reads **offset 4**, and `addr=0x4` is
a null `zend_string *`. *`zend_string_free` is `zend_always_inline`
and kencc does not inline*, so it is a real static function in every
TU that uses it -- which is why there was a pc to resolve at all.

**The caller is `accel_globals_dtor`** (`ZendAccelerator.c:2974`),
found by listing every `zend_string_free` call site in php -- 91 of
them -- and keeping the ones whose enclosing function name looks like
teardown. Exactly one did.

***AND THE MECHANISM IS A PLATFORM CONSEQUENCE, NOT AN ACCIDENT.***
`accel_globals->key` is allocated by `accel_globals_ctor`, whose only
caller is `accel_startup` -- the **zend_extension's** startup. And
`zend_extensions.c:194`'s `zend_extension_startup` has its entire
body inside `#if ZEND_EXTENSIONS_SUPPORT`, which
`zend_portability.h:191-200` sets to 1 for dlopen and for Windows and
**0 otherwise**. Plan 9 has no dlopen, so no zend_extension's startup
ever runs here. opcache's **MSHUTDOWN is an ordinary MODULE
shutdown**, gated by nothing, and calls `accel_shutdown`, which takes
its `!ZCG(enabled) || !accel_startup_ok` arm and destroys the globals
anyway. *A platform that constructs nothing destroys regardless.*

Guarded, which is what the **next statement in the same function**
already does for `preloaded_internal_run_time_cache` and what
`zend_accel_blacklist_shutdown` opens with four lines earlier in the
same call. **Upstream's, and the second upstream php bug this
campaign** after the `zend_atomic.h` typo; both are worth reporting.

*The rest of that path was checked for the same shape rather than
left*: `zend_jit_shutdown` is `#ifdef HAVE_JIT` and we answer no, the
blacklist has its own guard, and `UNREGISTER_INI_ENTRIES` over
entries that were never registered walks an empty set.

**Prediction, written down before the run**: `php -v` now exits 0.
**What would refute it**: a fault at a different address or line --
which would be the next member of the same family, since every
zend_extension on this platform is constructed by nobody.

### The eight, and what each turned out to be

Three were kencc's, three were APE headers', one was php's and one was
the instrument's own. All of them are in `docs/notes/kencc.md` or
`docs/notes/libap.md` with the mechanism; this is the list.

1. **`Zend/zend_lazy_objects.c:117`** — `return` of a `void *` from a
   `bool` function. `cc/sub.c`'s `stcompat` refused it before
   `com.c`'s `boolnorm` could convert it. **kencc, fixed**;
   `sys/lib/tests/boolptr-test.c`.
2. **`ext/reflection/php_reflection.c:3896`** — `bool visible;`
   declared nothing, because `cc/lex.c`'s `indeclname` list of type
   specifiers was missing `LBOOL`, so `visible` was swallowed as a
   GNU visibility attribute. **kencc, fixed.**
3. **`main/debug_gdb_scripts.c`** — `<eof> unexpected EOF in
   __attribute__`: the attribute/`__asm__` argument scanner counted
   parentheses **inside string literals**, and that file is one
   `__asm__` holding 1680 `.ascii` lines of gdb's python with one
   unmatched `(` in the text. **kencc, fixed.**
4. **`main/network.c:406`** — no `timercmp` in APE's `<sys/time.h>`.
   The five BSD `struct timeval` macros are there now, each guarded.
5. **`ext/standard/basic_functions.c`** — `LOG_MAIL` and `LOG_LPR`
   missing from `<syslog.h>`, which had skipped facilities 2, 6, 7, 8
   and 11; four of the five are POSIX.
6. **`ext/standard/dns.c:341`** — no `HEADER`: APE had the `ns_` half
   of `<arpa/nameser.h>` and none of the BIND 4 compat half.
   `<arpa/nameser_compat.h>` is new, included from `<arpa/nameser.h>`
   as every other libc does, and its `HEADER` is byte-for-byte the
   host's (checked both ways). ***Fixing it uncovered that
   `<resolv.h>` had its OWN `MAXDNAME`, `T_A`, `C_IN` and the rest***
   — two definitions of the same constants in two headers, invisible
   until one translation unit included both.
7. **`main/network.c:1423`** — `HAVE_GETHOSTBYNAME_R` yes with every
   arity no, so `gethostname_re` was defined by no arm. libap's is the
   six-argument form; `HAVE_FUNC_GETHOSTBYNAME_R_6` is 1.
8. **`ext/random/csprng.c:194`** — arithmetic on a `void *`, a GNU
   extension. One cast, in the only one of the file's four sites that
   this platform compiles.

**And the instrument's own faults were two**, both recorded in its
header because they are the shapes to recognise: it matched the Keccak
flags on the DIRECTORY, which read as the mkfile's rule but is not it
(`ext/hash/hash_sha3.c` takes them too), and it passed the mkfile's
`CFLAGS` through, whose leading **`-c` means "compile only" to `pcc`
and "print `const if`" to `6c`** — dozens of lines that read exactly
like diagnostics.

***THE SILENT ONE WAS IN THE HARNESS AND COST THE MOST.*** One file
made the host `6c` exit 1, delete its own output and print **nothing
at all**. `strace` showed the `cpp` child exiting 0 and being waited
for correctly; the cause is `go1.4/src/lib9/await.c`, whose
`memset(w, 0, sizeof *w)` leaves the message buffer in the same
allocation **uninitialised**, so a child that exits 0 writes nothing
to it and `compat-unix.c`'s `mywait` reads whatever `malloc` left
there as "the child failed". Fixed in the vendored file, which is
`+build !plan9` and so reaches nothing on the VM. *A harness that
reports a failure the subject does not have is the one fault that
cannot be found by reading the subject.*

## Open, as a list

* fibers: **done** — `ucontext` is in libap and `ucontext-test` is 0
  failures on the VM (`docs/notes/libap.md`). What remains is pointing
  php at it: `ZEND_FIBER_UCONTEXT` in the `config.h`
* **the LINK: predicted to succeed, not yet run.** All 515 objects
  compile and `--undefined` says the program wants **283 symbols from
  outside php**, of which `apfunc-sweep` finds **273 defined in
  libap** and ten that are present but invisible to it — `getcontext`
  and `swapcontext` are assembly, `stdin`/`stdout`/`stderr`/`environ`/
  `h_errno`/`_ctype`/`_errnoloc` are DATA, and `signal` is spelled
  `(*signal(int, void (*)(int)))(int)`, which no definition-shaped
  regex matches. Each of the ten was opened. **So nothing is missing,
  and the refutation condition is a name outside those 283** — which
  is what a newly reached `static inline` would be.
* the 474 unanswered questions in the template are still unanswered,
  and `cfghdr-sweep` gates on none of them. A compile is not evidence
  that an answer is right, only that it is consistent.
* `memfd_create` is declared with no implementation, which is a libap
  trap independent of php
* `sys/src/ape/lib/ap/time/asctime_r.c:30` is
  `return *__asctime_r(*tm, *buf);` — nonsense that compiles nowhere,
  and the file is commented out of `time/mkfile`, which is why nobody
  has noticed. Not live; noted so the next reader does not spend a round
  on it.

## Closed

* **The Zend allocator's memory, §3** — the partial `munmap` is fixed
  and both trims are measured to survive on the VM, and the
  segment-slot ceiling that would have capped the Zend heap at about
  10MB is gone. *The alignment question answered no, so the trims do
  run; they just work.*

* **`ctime_r`** — declared in `<time.h>` and implemented nowhere, found
  by `apfunc-sweep.py` while answering php's `config.h`. It is the
  composition of `localtime_r` and `asctime_r`, both of which were
  already there, and is now in `time/ctime.c`.
