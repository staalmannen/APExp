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

## Extensions: the ones with a ported library

The user's own framing, and the right one: enable what this tree already
has a library for. Present in `sys/src/ape/lib`: `onig`, `libressl`,
`curl`, `z`, `bz2`, `xml2`, `pcre2`, `sqlite`, `zip`, `zstd`, `lzma`,
`lz4`, `readline`, `history`, `intl`, `png`.

Which maps to: `mbstring` (oniguruma), `openssl` (libressl), `curl`,
`zlib`, `bz2`, `libxml`/`dom`/`simplexml`/`xml`/`xmlreader`/`xmlwriter`,
`sqlite3` + `pdo_sqlite`, `zip`, `readline`, `gd` (png only), `intl`.

**`ext/pcre` bundles its own pcre2 and that is what the 29 objects are.**
`--with-external-pcre` would use `sys/src/ape/lib/pcre2` instead; the
bundled copy is the better starting point, because it is the version php
was tested against and it removes a link dependency from the first build.

**No extension should be enabled in the first build.** The order that
has worked in this tree is: get the thing to compile and print its own
version, then add one library at a time.

## Open, as a list

* fibers: **done** — `ucontext` is in libap and `ucontext-test` is 0
  failures on the VM (`docs/notes/libap.md`). What remains is pointing
  php at it: `ZEND_FIBER_UCONTEXT` in the `config.h`
* `main/php_config.h` not written yet; the inventory is derived, the
  answers are not
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
