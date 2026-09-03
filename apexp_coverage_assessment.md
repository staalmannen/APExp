# APExp POSIX/musl coverage assessment

*Last updated: 2026-09*

## File count comparison vs musl src/

| Directory     | APExp | musl |  %  | Notes |
|---------------|------:|-----:|----:|-------|
| math/         |   227 |  223 | 102% | Complete |
| search/       |     8 |    8 | 100% | Complete |
| stdlib/       |    24 |   20 | 120% | Complete + extras |
| stdio/        |    95 |   72 | 132% | Complete — musl buffering model, plus fseek/freopen/fclose/vsnprintf/ungetc correctness fixes this cycle |
| regex/        |     6 |    5 | 120% | Complete + glob/fnmatch |
| conf/         |     6 |    5 | 120% | Complete |
| string/       |    93 |   80 | 116% | Complete + wchar suite |
| multibyte/    |    61 |   26 | 235% | Complete + Plan9 rune extras |
| dirent/       |    11 |    8 | 138% | Complete + versionsort |
| env/          |     5 |    8 |  62% | Near-complete |
| misc/         |    19 |   20 |  95% | Near-complete — getopt_long, fts, nftw, realpath, syslog all present |
| locale/       |    21 |   30 |  70% | Good — iconv + gettext stubs present |
| malloc/       |    13 |    8 | 163% | Complete — aligned allocation suite done |
| prng/         |     4 |    5 |  80% | Good — arc4random_uniform added |
| time/         |    20 |   30 |  67% | Reasonable — strptime/timegm/_r variants; clock_nanosleep + POSIX interval timers done |
| unistd/       |    50 |   50 | 100% | Complete — at() family, initgroups, dup/dup2/pipe2 all present |
| stat/         |    13 |   16 |  81% | Good — chmod/chown/fchmod/fstat/lstat/utimens family present |
| fcntl/        |     4 |    5 |  80% | Good — fcntl/open/creat/flock |
| temp/         |     5 |    5 | 100% | Complete — mkstemp/mkdtemp/mktemp/tmpfile |
| passwd/       |    10 |   18 |  56% | Reasonable — getpw*/getgr* with _r and array variants |
| complex/      |    69 |  140 |  49% | Half coverage |
| fenv/         |     7 |   15 |  47% | Half coverage |
| exit/         |     4 |    7 |  57% | Good — quick_exit added |
| process/      |    12 |   22 |  55% | Reasonable — posix_spawn honours file actions now (see CLAUDE.md) |
| signal/       |    12 |   36 |  33% | Core only — sigaction present, sigset_t fixed this cycle; the amd64 notify/trampoline path is where the outstanding GNU tar and bash crashes likely live — see priorities below |
| network/      |    64 |   90 |  71% | Sockets + full musl DNS resolver stack present |
| errno/        |     3 |    3 | 100% | Complete — errno accessor, err()/warn() |
| thread/       |    32 |   85 |  38% | Functional — cond_timedwait, semaphores, pthread_key_* destructors added |
| aio/          |     1 |    5 |  20% | Initial implementation present, complete rewrite this cycle (see CLAUDE.md) |
| select/       |     1 |    5 |  60% | poll() in select/; select()+FD_SET family in plan9/_buf.c |
| termios/      |     2 |   12 |  92% | Near-complete — tcgetattr.c has tcsetattr/tcdrain/tcflush/tcflow/tcsendbreak/tcgetsid/tcsetpgrp/tcgetpgrp; cfgetospeed.c has cfmakeraw/cfset*/cfget* |
| ctype/        |    35 |   52 |  67% | Good — now one function per file matching musl's layout (was a single table-driven file) |
| legacy/       |     1 |   14 |   7% | Thin |
| crypt/        |     0 |    6 |   0% | Not present (covered by libsec) |
| ldso/         |     0 |   12 |   0% | N/A — static linking |
| linux/        |     0 |   35 |   0% | N/A — Linux-specific |
| mman/         |     1 |    8 |  ~60% | plan9/mman.c: mmap/munmap/mprotect/msync/mremap/shm_open; MAP_ANONYMOUS+MAP_PRIVATE work |
| mq/           |     0 |    6 |   0% | **Non-goal.** POSIX message queues; no `mq_*` call exists anywhere in the tree (checked against every port, including go1.4's syscall tables, which only *name* mq_open for other OSes). Plan 9 has no kernel primitive to build it on, so this would be a from-scratch implementation — `mq_notify`'s signal/thread delivery and priority-ordered messages are the hard parts — for zero known consumers. Revisit only if a port is found that actually calls it. |
| sched/        |     1 |    6 |  80% | sched_yield, sched_get_priority_min/max, sched_getscheduler, sched_setscheduler, sched_getparam, sched_setparam, sched_rr_get_interval |
| setjmp/       |     0 |   12 |   0% | Covered by arch/ assembly |

---

## What changed since the previous assessment

### stdio/ — three correctness bugs found while bringing up flex

`fseek` set the error indicator on any seek that failed rather than
returning nonzero as C99 7.19.9.2 requires, which permanently poisoned
any stream probed on an unseekable descriptor (a pipe, in flex's case).
`freopen` returned a *new* `FILE` instead of reopening the stream it was
given, so it silently did nothing on a permanent stream (`stdin`,
`stdout`, `stderr`). `fclose` on a permanent stream flushed but never
closed the descriptor, so a program that closes `stdout` to signal
end-of-input to a pipeline — ordinary Unix practice — hung waiting for a
child that would never see EOF. `ungetc` refused a stream that had not
yet been read from, against the C99 7.19.7.11 guarantee. `fseek`/`fseeko`
had also drifted into two copies with two more bugs each (a relative
seek ignoring buffered data; neither could seek a memstream). None of
these are flex-specific — see CLAUDE.md for the mechanism and the
`unget-pipe-test.c` regression test that exercises all of them together.

### string.h/ — a header leak into Plan 9's own namespace

`<string.h>` reached `<u.h>` (Plan 9's `nil`/`uchar`/`ushort`/`ulong`)
through `wchar.h → time.h → signal.h → pthread.h → lock.h`, entirely for
pointer-parameter forward references. Cut to forward declarations at
every link; see CLAUDE.md.

### ctype/ — real per-function files, matching musl's layout

Was a single table-driven file (3 files total) that the previous
assessment flagged as "misleading — covers everything, counts badly."
Now genuinely one function per file (35 files), which is both a more
accurate count and easier to audit against musl function-by-function.

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

### network/ — full DNS resolver stack

File count grew from 35 to 65. The musl DNS resolver was imported wholesale
and adapted to Plan9's network interface: `res_msend`, `res_state`, `res_init`,
`res_query`, `res_send`, `res_mkquery`, `res_querydomain`, plus full `getaddrinfo`
using the resolver backend. `arpa/nameser.h` and `ns_parse.c` were added.
Ether support (`ether.c`) and `SOCK_CLOEXEC`/`SOCK_NONBLOCK` stubs added.
DNS resolution now falls back to Plan9's `/net/dns` via the ndb interface
when the resolver stack finds no traditional `/etc/resolv.conf`.

### mman/ — mmap in plan9/mman.c

`plan9/mman.c` provides `mmap`, `munmap`, `mprotect`, `msync`, `mremap`,
`madvise`, `mlock`/`munlock`, and `shm_open`/`shm_unlink`. The `__p9_syscall`
backend handles `MAP_ANONYMOUS` (via `segattach`) and file-backed `MAP_PRIVATE`
(via `read()`). `MAP_SHARED` write-back is not supported; `mprotect`/`msync`
are no-ops. The file count was always 0 in the table because the implementation
lives in `plan9/` rather than a dedicated `mman/` subdirectory.

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

**Weighted POSIX compatibility: approximately 90-93%**

Unchanged from the 2026-05 estimate — this update is a file-count refresh
and a correctness pass, not new surface. The per-directory table above
had drifted from the tree (several directories were undercounted by a
third or more, e.g. `unistd/` 39→50, `stat/` 9→13, `ctype/` 3→35 after
being split into one function per file); those numbers are now taken
directly from the tree rather than carried forward. The `mq/` row is
reclassified from an apparent gap to a documented non-goal — see the
table note.

The autoconf probe coverage estimate is unchanged at **roughly 92%** of
the ~200 most-commonly probed functions.

---

## Top musl import priorities going forward

Ranked by (impact on porting real software) × (implementation effort).

### Tier 1 — thin gaps with outsized configure impact

**termios/ — DONE**
All key functions are already implemented across 2 files: `tcsetattr`,
`tcdrain`, `tcflush`, `tcflow`, `tcsendbreak`, `tcgetsid`, `tcsetpgrp`,
`tcgetpgrp` in `tcgetattr.c`; `cfmakeraw`, `cfset*/cfget*` in `cfgetospeed.c`.
The low file count was misleading — coverage is ~92%.

**exit/ — DONE**
`at_quick_exit` and `quick_exit` are both present in `exit/quick_exit.c`.

**select/ — DONE**
`select()` + `FD_SET`/`FD_CLR`/`FD_ISSET`/`FD_ZERO` are in `plan9/_buf.c`.
`poll()` is in `select/poll.c` (wraps select). Both declared in `sys/select.h`.
`ppoll()` added (2026-05): wraps `poll()`, converts `struct timespec *` timeout
to milliseconds; `sigmask` argument is ignored (Plan9 has no atomic mask swap).

**sched/ — DONE**
`sched_yield`, `sched_get_priority_min/max`, `sched_getscheduler`,
`sched_setscheduler`, `sched_getparam`, `sched_setparam`,
`sched_rr_get_interval` are all in `sched/sched.c`.

### Tier 2 — moderate effort, clear payoff

**thread/ — rwlock and barrier — DONE**
`pthread_rwlock_*` backed by Plan9 native `RWLock` (qlock.h) in `pthread_ext.c`.
`pthread_barrier_*` implemented (wait always returns `PTHREAD_BARRIER_SERIAL_THREAD`
since Plan9 has no multi-threaded barrier primitive).
`pthread_spin_*` added (2026-05) in `spinlock.c` — backed by Plan9 `tas(int*)`.
`pthread_kill` added (2026-05) in `pthread_kill.c` — delegates to `kill(pid, sig)`.

**time/ — POSIX interval timers — DONE**
`timer_create`, `timer_delete`, `timer_settime`, `timer_gettime`,
`timer_getoverrun`, and `clock_nanosleep` are all implemented.
`timer.c` backs each timer with a worker pthread sleeping via
`pthread_cond_timedwait`; supports `SIGEV_NONE`, `SIGEV_SIGNAL` (default
`SIGALRM`), and `SIGEV_THREAD`. `timer_getoverrun` always returns 0.

**stat/ — at() and timestamp family — DONE**
`fstatat` is in `unistd/at_functions.c` (AT_FDCWD wrapper).
`utimensat`/`futimens` added (2026-05) in `stat/utimens.c`: convert
`struct timespec` to Plan9 Dir `atime`/`mtime` via `_dirwstat`/`_dirfwstat`;
`UTIME_NOW` → `time(NULL)`, `UTIME_OMIT` → leave `~0UL` sentinel from
`_nulldir` (Plan9 "don't change" value). Macros declared in `sys/stat.h`.
`mknodat` added (2026-05) to `unistd/at_functions.c` as AT_FDCWD wrapper.
`clock_getres` added (2026-05) to `time/clock_gettime.c`; reports 1ns
resolution for CLOCK_REALTIME/CLOCK_MONOTONIC (Plan9 nsec() granularity).

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

**network/ — DNS resolver — DONE**
The musl resolver stack was imported and adapted to Plan9. Full `getaddrinfo`
and `gethostbyname` now use the resolver. The remaining network gap is
`setsockopt`/`getsockopt` option mapping and IPv6 routing socket support.

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

Updated priorities (2026-09):

1. ~~`thread/` — rwlock and barrier~~ — DONE (rwlock/barrier/spinlock/pthread_kill all implemented)
2. ~~`stat/` — `utimensat`, `futimens`, `mknodat`~~ — DONE (2026-05)
3. ~~`select/` — `ppoll`~~ — DONE (2026-05)
4. ~~`time/` — `clock_getres`~~ — DONE (2026-05)
5. ~~`network/` — `setsockopt`/`getsockopt` for more socket options~~ — DONE (2026-05): added IPPROTO_IPV6/IPV6_V6ONLY, SO_RCVTIMEO/SO_SNDTIMEO (mapped to Plan9 readtimeout/writetimeout), SO_DEBUG, SO_DONTROUTE, SO_ACCEPTCONN, IP_TTL/IP_TOS, TCP_MAXSEG
6. ~~`fcntl/` — `O_CLOEXEC` flag on `open()`~~ — DONE (2026-05): maps to Plan9 OCEXEC; also sets FD_CLOEXEC in fi->flags
7. ~~`thread/` — `pthread_cancel` / `pthread_testcancel`~~ — DONE (2026-05): `pthread_cancel.c` with deferred (flag) and async (SIGTERM) modes; `pthread_setcanceltype`; `PTHREAD_CANCELED` sentinel
8. ~~`signal/` — `sigwait`/`sigwaitinfo`/`sigtimedwait`/`sigqueue`~~ — DONE (2026-05): `sigwait.c` uses temporary handler + 1ms _SLEEP poll; `sigqueue` delegates to `kill()`; `SI_USER`/`SI_QUEUE`/`SI_TIMER` constants added to signal.h
9. ~~`passwd/` — `getgrgid_r`/`getgrnam_r`~~ — DONE (2026-05): `getgr_r.c` iterates via getgrent() into caller-supplied buffer
10. ~~`aio/` — `lio_listio`~~ — DONE (already implemented in prior session)
11. ~~`ctype/` — split the table-driven file into one function per file~~ — DONE (2026-09), matching musl's layout for easier audit
12. ~~`stdio/` — `fseek`/`freopen`/`fclose`/`ungetc` correctness~~ — DONE (2026-09), found via bringing up flex; see CLAUDE.md
13. `mman/` — `MAP_SHARED` write-back; `mprotect` mapping to Plan9 segment permissions
14. `thread/` — `pthread_attr` full coverage (setstacksize wired to Plan9 thread stack)
15. `complex/` — long double variants (`l` suffix functions) for full musl parity
16. **`mq/` — not a priority. Deliberately unimplemented; see the table note above.**

### Not a coverage gap, but the next place to look for bugs

`signal/` at 33% is the thinnest directory with real, active consumers,
and it is where the outstanding GNU tar (`suicide: bad address in
notify`) and bash-script-crash bugs most likely live — `signal/signal.c`
and `arch/amd64/notetramp.c` are the note-handler registration and
trampoline, the same machinery behind the amd64 `sigsetjmp`/`siglongjmp`
fixes documented in CLAUDE.md. This is bug-hunting, not a missing-file
gap, so it will not move the percentage in this table much even when
fixed — but it is worth doing before adding more musl surface to a
signal path that is already known to be fragile.
