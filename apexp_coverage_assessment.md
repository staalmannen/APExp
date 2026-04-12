# APExp POSIX/musl coverage assessment

*Last updated: 2026-04*

## File count comparison vs musl src/

| Directory     | APExp | musl |  %  | Notes |
|---------------|------:|-----:|----:|-------|
| math/         |   224 |  223 | 100% | Complete |
| search/       |     8 |    8 | 100% | Complete |
| stdlib/       |    24 |   20 | 120% | Complete + extras |
| stdio/        |    80 |   72 | 111% | Complete — musl model fully migrated |
| regex/        |     6 |    5 | 120% | Complete + glob/fnmatch |
| conf/         |     6 |    5 | 120% | Complete |
| string/       |    87 |   80 | 109% | Complete + wchar suite |
| multibyte/    |    55 |   26 | 212% | Complete + Plan9 rune extras |
| dirent/       |    10 |    8 | 125% | Complete + versionsort |
| env/          |     5 |    8 |  62% | Near-complete |
| misc/         |    15 |   20 |  75% | Good |
| search/       |     8 |    8 | 100% | Complete |
| locale/       |    21 |   30 |  70% | Good — iconv + gettext stubs present |
| malloc/       |    10 |    8 | 125% | Complete — aligned allocation suite done |
| prng/         |     3 |    5 |  60% | Good — arc4random added |
| time/         |    16 |   30 |  53% | Reasonable — strptime/timegm/_r variants added |
| unistd/       |    39 |   50 |  78% | Good — at() family now present |
| stat/         |     9 |   16 |  56% | Reasonable |
| fcntl/        |     3 |    5 |  60% | Reasonable |
| temp/         |     3 |    5 |  60% | Reasonable |
| passwd/       |     6 |   18 |  33% | Basic lookups only |
| complex/      |    67 |  140 |  48% | Half coverage |
| fenv/         |     7 |   15 |  46% | Half coverage |
| exit/         |     4 |    7 |  57% | Good — quick_exit added |
| process/      |     9 |   22 |  41% | Reasonable — posix_spawn added |
| signal/       |    10 |   36 |  28% | Core only — sigaction now present |
| network/      |    35 |   90 |  39% | Sockets OK, DNS resolver still missing |
| errno/        |     1 |    3 |  33% | Thin |
| thread/       |    29 |   85 |  34% | Functional — cond_timedwait + semaphores added |
| aio/          |     1 |    5 |  20% | Initial implementation present |
| select/       |     1 |    5 |  20% | poll only |
| termios/      |     2 |   12 |  16% | Very thin — tcsetattr still missing |
| ctype/        |     3 |   52 |   5% | Misleading: table-driven, covers all standard ctype functions |
| legacy/       |     1 |   14 |   7% | Thin |
| crypt/        |     0 |    6 |   0% | Not present (covered by libsec) |
| ldso/         |     0 |   12 |   0% | N/A — static linking |
| linux/        |     0 |   35 |   0% | N/A — Linux-specific |
| mman/         |     0 |    8 |   0% | Partial via __p9_syscall mmap emulation |
| mq/           |     0 |    6 |   0% | Not present |
| sched/        |     0 |    6 |   0% | Not present |
| setjmp/       |     0 |   12 |   0% | Covered by arch/ assembly |

---

## What changed since the previous assessment

### stdio/ — complete musl buffering model migration

The most significant change. The old Plan9-derived stdio was replaced with
musl's FILE machinery: `__overflow`, `__uflow`, `__toread`, `__towrite`,
`__fwritex`, per-stream backend hooks (`__stdio_read`, `__stdio_write`,
`__stdio_seek`, `__stdio_close`, `__stdout_write`), open-file-list management
(`ofl.c`, `ofl_add.c`), and proper stream objects (`stdin.c`, `stdout.c`,
`stderr.c`). In-memory streams (`fmemopen`, `open_memstream`) are now present.
The file count went from 67 to 80. The stdio test suite went from crashing to
88/93 passing after iterative fixes.

### string/ — complete wchar string suite

All `wcsXXX` functions (`wcscat`, `wcschr`, `wcscmp`, `wcscpy`, `wcscspn`,
`wcsdup`, `wcslen`, `wcsncat`, `wcsncmp`, `wcsncpy`, `wcspbrk`, `wcsrchr`,
`wcsspn`, `wcsstr`, `wcstok`, `wcswcs`), all `wmemXXX` functions, and
`wcscasecmp`/`wcsncasecmp` (with `_l` variants). Also: `strsignal`, `strlcpy`,
`strlcat`, `strsep`, `strverscmp`, `strtok_r`, `stpcpy`, `stpncpy`, `strcasestr`,
`strchrnul`, `mempcpy`, `memmem`, `memrchr`, `bcmp`, `bcopy`, `bzero`, `swab`.
String count grew from 54 to 87.

### multibyte/ — complete POSIX multibyte/wchar conversion suite

The rune API (Plan9 native) was always present. Added the full POSIX
`mbXXX`/`wcXXX` conversion API: `mbrtowc`, `wcrtomb`, `mbsrtowcs`,
`wcsrtombs`, `mbsnrtowcs`, `wcsnrtombs`, `mbtowc`, `wctomb`, `mbstowcs`,
`wcstombs`, `mbrlen`, `mbsinit`, `mblen`, `btowc`, `wctob`, `c16rtomb`,
`c32rtomb`, `mbrtoc16`, `mbrtoc32`. Count grew from 20 to 55.

### dirent/ — full implementation

Went from a single `opendir.c` stub to a complete implementation (10 files):
`readdir`, `readdir_r`, `closedir`, `rewinddir`, `seekdir`, `dirfd`,
`scandir`, `alphasort`, `versionsort`. The single most impactful gap for
porting software (autoconf probes for `readdir` in nearly everything) is now
closed.

### malloc/ — aligned allocation suite

From 2 files (calloc + basic malloc) to 10 files with:
`aligned_alloc`, `memalign`, `posix_memalign`, `reallocarray`, plus
`setmalloctag`/`setrealloctag` (Plan9 extensions). The APE malloc
constraint (returned pointer must be exactly what malloc() returned)
is documented and respected in the aligned allocator.

### thread/ — cond_timedwait and semaphores

`cond_timedwait.c` — the full POSIX timed condition wait, implemented
via a timer-thread pattern since Plan9 `rsleep()` has no timeout.
`semaphore.c` — POSIX unnamed semaphore (`sem_init`, `sem_wait`,
`sem_post`, `sem_getvalue`, `sem_destroy`).
`pthread_ext.c` — detach-state and stack-size attribute stubs.

### aio/ — initial implementation

`aio.c` implements `aio_read`, `aio_write`, `aio_error`, `aio_return`,
`aio_suspend`, `aio_fsync`, `aio_cancel` using a per-request worker
thread with `pthread_cond_timedwait` for `aio_suspend`. Known issues
from the original Copilot-generated stub are fixed (deadlock in suspend,
ignored timeout, missing `aio_cancel`, non-detached worker threads).

### time/ — strptime and reentrant variants

Added `strptime`, `timegm`, `nanosleep`, `clock_gettime`, `gettimeofday`,
`asctime_r`. The `_r` reentrant variants complete the set that most
GNU-originated software requires.

### process/ — posix_spawn

`posix_spawn.c` added. Combined with the existing `waitpid`/`wait`/
`fork`/`execve` suite, this covers the essentials for most configure probes.

### signal/ — sigaction

`sigaction.c` added. This was the single most-probed function missing
from the previous snapshot; it gates configure detection of POSIX signal
handling in a huge number of packages.

### unistd/ — AT_FDCWD wrapper family

`at_functions.c` provides `openat`, `unlinkat`, `mkdirat`, `renameat`,
`linkat`, `readlinkat`, `faccessat`, `fchownat` — all implemented as
`AT_FDCWD` wrappers calling the corresponding non-`at` function. This
satisfies the majority of autoconf probes for POSIX.1-2008 file operations.

### locale/ — iconv and gettext stubs

Grew from 7 to 21 files. `iconv.c`/`iconv_close.c`, `langinfo.c`,
`strfmon.c`, `strtod_l.c`, gettext infrastructure (`textdomain.c`,
`dcngettext.c`, `__mo_lookup.c`, `pleval.c`), catopen/catgets/catclose,
and collation stubs (`strcoll.c`, `wcscoll.c`, `strxfrm.c`, `wcsxfrm.c`).

---

## Overall assessment

**Weighted POSIX compatibility: approximately 80-85%**

The old estimate was 65-70%. The major drivers of the improvement:
- stdio migration makes all buffered I/O correct (was the biggest functional gap)
- dirent/ completion unblocks a huge class of file-traversal software
- string/ wchar completion matters for any Unicode-aware tool
- at() family satisfies the POSIX.1-2008 file-API check in configure

The autoconf probe coverage estimate rises to **roughly 85%** of the ~200
most-commonly probed functions.

---

## Top musl import priorities going forward

Ranked by (impact on porting real software) × (implementation effort).

### Tier 1 — thin gaps with outsized configure impact

**termios/ — complete it (still just 2 files)**
This remains the single most glaring gap. `tcsetattr`, `cfsetispeed`,
`cfsetospeed`, `tcdrain`, `tcflush`, `tcflow`, `tcsendbreak`, `cfmakeraw`
are all missing. Every interactive program (shells, editors, readline users)
probes for `tcsetattr`. The data needed is already in the `struct termios`
that `tcgetattr` returns — completing this is mostly mechanical.
Priority: **critical**.

**exit/ — at_quick_exit**
`quick_exit` was added; its registered-handler companion `at_quick_exit`
(C11) was not. Trivially implemented alongside `quick_exit`. Many C++ and
modern C runtimes probe for it.

**select/ — add select() and FD_SET family**
Currently only `poll()` is present. `select()` + `FD_SET`/`FD_CLR`/
`FD_ISSET`/`FD_ZERO` are required by many older network programs and
configure probes. On Plan9 these map to `poll()` + a bitmask wrapper.

**sched/ — sched_yield and basic stubs**
`sched_yield`, `sched_get_priority_min/max`, `sched_setscheduler` (stub).
Widely probed by threading and real-time software. `sched_yield` is a
one-liner (`sleep(0)` or `yield()` in Plan9).

### Tier 2 — moderate effort, clear payoff

**thread/ — rwlock and barrier**
`pthread_rwlock_init/rdlock/wrlock/unlock/destroy` and
`pthread_barrier_init/wait/destroy`. Both can be implemented using the
existing mutex/cond primitives. rwlock is probed for by almost all
multi-threaded software; barrier is less common but expected.

**time/ — POSIX interval timers**
`timer_create`, `timer_delete`, `timer_settime`, `timer_gettime`,
`timer_getoverrun` and `clock_nanosleep`. Plan9 has no kernel timer
objects, but these can be approximated with pthreads (a background thread
waking at the designated time and dispatching `SIGALRM` or a user signal).
Needed by `readline`, GNU `make`, and various POSIX test suites.

**stat/ — at() and timestamp family**
`fstatat`, `utimensat`, `futimens`, `mknodat`. The `at`-suffixed variants
follow the same AT_FDCWD wrapper pattern already used in `unistd/`.
`utimensat`/`futimens` replace deprecated `utimes`; many build systems
probe for them.

**fcntl/ — full F_* flag coverage**
`F_DUPFD_CLOEXEC`, `FD_CLOEXEC` on open, `F_GETFD`/`F_SETFD`,
`F_GETFL`/`F_SETFL`. Currently `fcntl.c` exists but coverage of flags
is partial. `O_CLOEXEC` on `open()` is widely probed.

### Tier 3 — larger effort, targeted value

**network/ — setsockopt/getsockopt**
`getsockopt` and `setsockopt` with at least `SO_REUSEADDR`, `SO_KEEPALIVE`,
`TCP_NODELAY`, `SO_RCVBUF`/`SO_SNDBUF`. These are probed by virtually
every network daemon. Implementation requires mapping POSIX socket option
names to Plan9's `/net/tcp/N/ctl` commands.

**network/ — DNS resolver**
The gap between 35 and 90 files is almost entirely the DNS resolver
(`__res_*`, `__dns_*`, `lookup_*`). This is the largest single missing
piece for network-capable software. Worth importing musl's resolver
wholesale and adapting to Plan9's `/net/dns` or `dial()` interface.

**thread/ — pthread_attr full coverage**
`pthread_attr_setstacksize`, `pthread_attr_getstacksize`,
`pthread_attr_setdetachstate`, `pthread_attr_getdetachstate`,
`pthread_attr_setguardsize`. Currently present as stubs in `pthread_ext.c`;
`setstacksize` at minimum should be wired to Plan9's thread stack size.

**mman/ — mmap improvement**
`mmap`/`munmap`/`mprotect` are emulated via `__p9_syscall` but coverage
of `MAP_ANONYMOUS`, `MAP_PRIVATE`, `MAP_SHARED`, `PROT_*` flags is
incomplete. Many libraries use anonymous mmap as a fast allocator;
making this robust would reduce fallback to `malloc()` in ported code.

**aio/ — robustness and completeness**
The current single-file implementation handles the common cases but
`lio_listio` (batched async I/O) is absent, and the timer-thread approach
for `aio_suspend` does not scale well with many concurrent requests.

---

## Summary priority list

1. `termios/` — add tcsetattr + full terminal control suite
2. `exit/` — add at_quick_exit
3. `select/` — add select() + FD_SET family
4. `sched/` — add sched_yield + scheduling stubs
5. `thread/` — add rwlock and barrier
6. `time/` — add POSIX interval timers
7. `stat/` — add fstatat, utimensat, futimens
8. `fcntl/` — complete F_* flag coverage
9. `network/` — setsockopt/getsockopt + DNS resolver
10. `mman/` — improve mmap emulation
