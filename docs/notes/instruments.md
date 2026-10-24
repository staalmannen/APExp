# The instruments

Every test, probe, sweep, model and cross-check in `sys/lib/tests` and
`rc/bin`, with what each one came from and what it cost.  `CLAUDE.md`
carries the LIST -- the name of each and the one question it answers --
because that is what you need to pick one; this file carries the
history, because that is what you need before changing one.

**The convention**, repeated here because it governs everything below:
print `PASS`/`FAIL` per case, exit with the number of failures, and open
with a comment saying which bug the test came from and what it cost.
Anything testing a language or library rule should be correct on gcc
too -- checking a new test against gcc first is how you find out whether
the test or the tree is wrong, and it has caught both.


---

## The instruments, one by one

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

## Testing

`sys/lib/tests/` holds standalone programs, each built and run by hand:

```
cd sys/lib/tests && pcc -o bool-test bool-test.c && ./bool-test
```

The convention: print `PASS`/`FAIL` per case, exit with the number of
failures, and open with a comment saying which bug the test came from
and what it cost. `tk-childproc-test.tcl` is the exception to the C
convention -- it is a Tcl script, run with `wish`, because the thing it
reproduces is Tk spawning a second Tk. Anything testing a language or library rule should be
correct on gcc too — checking a new test against gcc first is how you
find out whether the test or the tree is wrong, and it has caught both.

Every test named in `docs/notes/` sits here; the ones for kencc
itself are `bool-test.c`, `bitfield-test.c`, `compound-assign-test.c`,
`compound-literal-test.c`, `designated-init-test.c`, `charptr-test.c`,
`rol64-test.c` and `u64float-test.c`, and for libap `locale-test.c`,
`sigset-test.c`, `posix-spawn-test.c`, `limits-test.c`,
`format-arg-test.c`, `unget-pipe-test.c`, `isatty-test.c`,
`execve-env-test.c`, `tz-test.c`, `rename-test.c`, `listenleak-test.c`,
`asyncconnect-test.c`, `nbread-test.c`, `epipe-test.c`,
`ldexp-test.c`, `binfloat-test.c`, `rawmode-test.c`,
`execfail-test.c`, `append-test.c`, `strerror-test.c`,
`sincos-test.c`, `explog-test.c`, `fparith-test.c`,
`float-overflow-test.c`, `malloc-reuse-test.c`,
`socket-server-test.c`, `dup-fdinfo-test.c`, `rmdir-test.c`,
`copyfile-test.c`, `deeppath-test.c`, `bufexec-test.c`,
`mkstemp-test.c`, `printfmod-test.c`, `umask-test.c`,
`dupbuf-test.c`, `dotdir-test.c` and
`stdio-test.c`.
**`ctype-xcheck.c` is a HOST program** like `tz-xcheck.c`: it links
libap's own `_ctype[]` into a glibc program and sweeps **256 values
by 12 classifications**, printing every disagreement. It needs TWO
compiles (the command is in the file) because `ctype.c` wants
APExp's `<ctype.h>` for the `_IS*` bits while the checker wants
glibc's headers, and one `-I` cannot serve both.
**`bash-fdloop-test.sh` is a SHELL script rather than a C program**,
and has to be: it asks whether *bash* leaks a descriptor per fork,
so the thing under test is the shell itself. Run it with
`/bin/bash bash-fdloop-test.sh`; it is correct on glibc too, where
it reports 5 descriptors flat.
**`bash-comsub-test.sh` is the second, and is a BISECT rather than a
test**: ten sections of bash's own `run-all` lines 17-27, each
writing a durable marker to `/tmp/comsub.log` before the statement it
runs, so the log's last line names the statement that did not return.
It asserts nothing and has no failure count -- *read the log, not the
exit status*. All ten return on glibc in 13ms.
**`truefalse-test.c` is the one NATIVE test in this directory** --
`6c`/`6l`, not `pcc` -- and it has to be, because APE's `<stdbool.h>`
`#define`s `true`/`false` to 1 and 0, so an APE build never reaches
kencc's own C23 keywords. *A test here measures the APE dialect; a
bug in the native dialect needs a native test.* The twenty-five `tk-*.tcl` scripts there are Tcl, run
with `wish` -- except `tk-menubar-test.tcl`, which needs `tktest` and
skips itself under `wish`, and `tk-transient-test.tcl`, whose last
section alone does; see `docs/notes/tk-plan9.md`. `tk-runall.tcl` is the harness for
Tk's own suite rather than a test of its own, and `tk-runtest.tcl` runs
a single file from it. `tcl-runall.tcl` is the same thing for Tcl's own
suite, run under `tcltest`; both harnesses exist because a fault, a
kill and a clean finish are indistinguishable from the shell, so a run
without a completion marker cannot be read at all.
`itcl-runall.tcl` is the third, for itcl's 26 `.test` files, and it
**must be run under `itclsh` rather than `tclsh`** -- it says so itself
and reports whether `package require Itcl` worked before running
anything, because a suite failing every test for a missing package and
one failing because the port is broken give the same count.
`tarhdr-probe.c` is a PROBE rather than a test -- it prints a tar
file block by block and asserts nothing; the host reference output to
compare it against is in `docs/notes/libap.md`. `tarblock-probe.c` is
its companion and **must be built with tar's own `-I` flags**, which
are in the file: it measures `sizeof(union block)` against the host's
512, and with a different include order it would measure a different
`tar.h` and say nothing.
`tcl-stdchan-test.tcl` asks what buffering the three standard
channels get, and is a PROBE rather than a rule -- report what it
prints. `tcl-machexp-probe.tcl` is the same kind of thing for
Tcl's own float parser, and needs `$APEXP_STRTOD_DEBUG` set or it
says nothing. **It paid for itself in one run**: it named
`scalbn`'s `2^1023`. `ldexp-test.c` is the regression test that came
out of it, and it walks the WHOLE exponent range because the host
cross-check that had passed `scalbn` used a window that never reached
the broken branch. `tcl-fileevent-test.tcl` is a test rather than a harness -- it runs
under plain `tclsh` and isolates the `chan-io-44.1` and `event-11.5`
hangs, with a timeout on every section so it reports where the suite
would wait; `select-test.c` takes the two bugs it found down to the
`select()` call underneath them.
`tty-xcheck.c` is a host program too: it links `ap/plan9/tty.c`
with counting fakes for open/write/close and asserts the raw/cooked
contract, which is awkward to provoke on a live console. It needs
`-I ttystub`.
`strtod-xcheck.c`, `strtof-xcheck.c` and `dtoa-xcheck.c` are the same
idea for `strtod`, `strtof` and `_dtoa`, and are likewise HOST programs, not Plan 9 tests. The
second checks the two against each other -- the shortest string that
reads back -- which is a real test of both. `tz-xcheck.c` is not a Plan 9 test at all: it links
`lib/ap/time/tzone.c` into a **glibc** program on the build host and
sweeps ~1.4 million instants against `localtime_r`, so libap's own
parser can be checked without a VM round. It found two bugs that way.
That pattern -- link the unit under test into a host program beside the
reference implementation -- is worth reaching for whenever the thing
being written is a pure function of its input.
`strftime-xcheck.c` is the newest of them and needs **two compiles**,
like `ctype-xcheck`: the `-D` that renames libap's `strftime` out of
glibc's way applies to the checker too if both are in one command,
and the sweep then compares libap against itself and reports a clean
number. *Break the unit on purpose and check that the instrument
notices* -- that is what caught it.
**`apdecl-sweep.py` is a host SWEEP rather than a test**: it asks
every `.c` under `lib/ap` whether it calls a non-`int`-returning
function that nothing in its include closure declares -- the missing
prototype invariant in its RETURN-value form. Run it after adding
files to libap; its limits are in its own header and it is a lower
bound.
**`rceq-sweep.py` is a host SWEEP and it GATES**: which mkfile RECIPE
line hands rc a bare `=` that is not a leading assignment, and so
cannot parse. Every hit is a recipe that cannot run -- unlike
`ishadow-sweep`, there is no intent case. Run it after editing any
mkfile recipe; its discriminator (a leading assignment is legal, and
`if (cond) NAME=value` is a working precedent) is what keeps it from
reporting 16 lines of which 11 are fine.
**`execfd-test.sh` is a SHELL script for the `bash-fdloop-test` reason**
-- the thing under test is the shell's own `exec N>file` redirection.
clisp's `configure` printed `line NNNN: 5: Bad file descriptor` on
hundreds of lines, and **autoconf keeps `config.log` on fd 5**, so the
run's closing `C compiler cannot create executables` is downstream of a
lost descriptor rather than a statement about pcc. Sections 1-7
separate a low fd from fd 5, append from truncate, a reopened NUMBER, a
high fd (bash's `move_to_high_fd` territory), `<>` and a child writing
the parent's descriptor; **section 0 is the control**, an ordinary
`> file`, so an all-fail run names the filesystem instead. *Section 5 is
`redir.tests:83` verbatim*, the `exec 6<>` hunk CLAUDE.md records as
having moved for an unidentified reason -- so this asks one question
where there were two.
**ALL EIGHT CAME BACK 0 ON 9front, so the CONSTRUCT IS CLEARED and
three sections were added for the axes that run could not cover.**
8 is a child that forks AND EXECS (where `/env/_fdinfo` has to carry
the descriptor, and where one arrived poisoned before); 9 is the shell
**re-execing ITSELF**, which is literally configure's first act
(`exec $CONFIG_SHELL "$as_myself"`); 10 holds fd 5 across 300 forks and
**reports the iteration it first fails at**, because every other
section runs in a shell that has just started while configure's failure
arrives thousands of lines in, immediately after the kernel's
100/200-descriptor warning. 0 failures on glibc, 11 sections.
**`mkrecipe-probe/mkfile` is a PROBE and is a whole mk DIRECTORY**,
which it has to be: the question is what `mk` hands `rc`, so the
instrument is an mkfile rather than a program. `mk -k all` in it runs
six recipes -- a plain comment, a comment holding a bare `=`, a comment
holding backquotes and apostrophes, `} if not {` on one line, a `#`
inside a quoted sed argument, and a leading assignment inside `@{ }` --
and each prints `ok N` or an rc syntax error. **`-k` is not optional**:
mk stops at the first failing recipe and the point is one run rather
than one round each. **Case 1 is the control** (a plain recipe comment
must work -- `external/perl/plan9/mkfile:88` is one and perl builds)
and **case 5 has a known answer** (`cmd/tar/mkfile:126` echoes a
literal `#ifndef` and tar's header comes out right), so a failure there
says the probe is measuring something other than rc.
**IT ANSWERED IN ONE RUN: 1, 2, 3, 5 and 6 pass and CASE 4 FAILS** --
`} if not {` on one line, `token if: syntax error`. *Comments in
recipes are not the hazard; the brace-if-not is*, and the control
(case 1) and the known answer (case 5) both held, which is what makes
the one failure readable.
**`initzero-test.c` asks whether a compound literal ZEROES the members
its initialiser list leaves out** -- muon's crash, `*sb = (struct
tstr){.flags=..,.buf=..,.cap=..}` with `.len` omitted and then used as
a `memset` length. **Its storage is dirtied with 0xAA first and section
0 checks that the poison arrived**, because against a zero destination
every check passes for the wrong reason. Section 7 is muon's own
reduction and is the one whose failure names a program rather than a
rule. **Section 5 is the CONTROL**: a declaration rather than a
literal, so it exercises `contig()` and must pass under both compilers.
**`clitzero-model.py` is a host MODEL rather than a test**, beside
`sualign-model.py` and for the same reason -- kencc's sources need
Plan 9's `<u.h>`, so the first build of any `cc/` change is the VM's.
It extracts `clitzero()` from `cc/dcl.c` verbatim and asks which BYTES
it stores zero into, over six layouts by seven negative FRAME OFFSETS.
**It has no external oracle**, so its control is a deliberate break: a
copy with the tail loop removed must report a gap. Re-run it after any
edit to that function.
**`strerror-xcheck.py` is the second host SWEEP**, and it is a
script for a reason the other xchecks do not have: **APE's errno
NUMBERS are its own**, so libap's table and glibc's cannot be lined
up by index at all -- only by NAME. It parses `errno.h` and
`strerror.c`, asks glibc for each name, and reports every
disagreement. Re-run it after touching either file; one inserted row
shifts every entry after it and nothing else would say so.
`strtoint-xcheck.c` is the same idea for `strtoll` and `strtoull`,
and needs THREE compiles: libap's prototypes take `char *` where
glibc's take `const char *`, so even a `-D` rename collides with the
header -- it renames the SOURCE with `sed` into a temporary instead.
`strtol`/`strtoul` cannot be swept at all here, because kencc's
`long` is 32-bit and the host's is 64.
`apeabi-probe.c` is a PROBE and is never run: it is compiled TWICE,
`pcc -c -a` and `pcc -9 -c -a`, and the DIFF of the two acid dumps
names every APE struct whose layout `-J` moves. Take it before any
tree-wide rebuild. **Running it prints NOTHING and that is correct** --
the output is the acid dump on stdout, not the program. **It now
carries a BIT-FIELD section too**, for the second axis: there the two
sides are two COMPILERS (HEAD's `pcc` against a patched one) with the
same flags, and the `before` dump must be taken and kept first,
because no flag asks for the old allocation afterwards. The baseline
is committed at `tmp/abi-bf-before.acid`.
**`bfmove-sweep.py` is the companion SWEEP and exists because of the
probe's own limit**: an acid dump covers only the structs its one
translation unit lays out, i.e. the public headers, while the change
reaches every APE compile. It asks which bit-field groups anywhere in
`lib/ap` and `external/` are followed by a member small enough to
share the container's tail -- the only shape that moves. It **gates
nothing**: EDG's 266 hits are the change's purpose, not its cost.
**Its second column is a LOWER bound and its third says by how much.**
`sharer` matches a type NAME, so a package spelling its small types as
TYPEDEFS is invisible to it -- **perl's `op.h:55` is `BASEOP`, eight
`PERL_BITFIELD16` fields followed by `U8 op_flags; U8 op_private;`, and
the 268 did not include it.** *The pointer false positive one round
earlier was the same mistake from the other side: a regex over type
names is not a regex over types, and it can be wrong in both
directions.* A typedef cannot be resolved textually, so there is now an
UNKNOWN column (978 under `external/`) reported rather than counted --
read each hit, since `U32 arena_size` is in it and cannot share a
4-byte tail.
`structalign-test.c` measures `pcc -J`, conforming struct layout, and
**needs three runs** -- gcc, then `pcc -9 -DPLAN9`, the control, which
must FAIL (**30** of its 48 checks -- 22 measured, plus eight for the
SECOND bit-field rule, named in the file), then plain `pcc`, which
must pass. *The middle run is the
control*: a pass under `-J` alone cannot distinguish a working flag
from a compiler that never had the bug. **Section 9 carries nine
bit-field shapes, and the two that must NOT move are the valuable
half** -- `bf_aligned` and `bf_trailing` agree with gcc under both
rules, so either failing means a change did more than share a
container's tail.
**`bitinit-model.py` is a host MODEL with an EXTERNAL ORACLE**, which
the other two models have not got: it runs `cc/dcl.c`'s `gbitagg()`
byte loop over seven shapes and compares with the bytes **gcc** puts
in a real object for the same initialiser. **It tracks a written-mask
and reports OVERLAP**, so it reproduces `6l`'s `multiple
initialization` rather than only the final image -- *a model comparing
only the finished bytes scores the old code as correct*. `--old` is
the control: the replaced code reports 6 of 7 shapes, `ftab`
overlapping at 16/17/18, the bytes the real linker named, with the
no-bit-field shape clean in both modes. `bitinit-test.c` is its
regression test and reads back every member, ordinary ones included.
**`sualign-model.py` is a host MODEL rather than a test**, and exists
because kencc's own sources need Plan 9's `<u.h>`, so the first build
of any `cc/` change is the VM's. It transcribes `sualign()`'s TSTRUCT
arm under both rules and checks it against gcc. **Its control is
`__res_state`**: it must reproduce `tmp/abi-bf-before.acid` -- the
real pcc's real answer -- or it refuses to print anything, since a
transcription that cannot reproduce the known answer is modelling some
other compiler.
`edgtuoff-probe.c` is a PROBE and asks ONE question: does the struct
offset EDG folded into its generated C match the offset the compiler
building that C computes? It is a **reduction** of
`a_translation_unit` (pointers to `void *`, scalars as written), and
**its gcc control is what makes the reduction admissible** -- the host
must print 424/440, the numbers `gdb` reads from the DWARF of a real
`gcc -g -c mem_manage.c`. Run it with plain `pcc`, which is the rule
the whole APE world is built under; exit status is the mismatch count.
`random-xcheck.c` is the same idea for `random`/`srandom`/
`initstate`/`setstate`, and needs TWO compiles for the
`strftime-xcheck` reason. Its **section 0 is a control of the
instrument**: it asks whether `random` and `ap_random` are the same
address, and whether the comparison reports anything at all for two
different seeds.
`regcoll-xcheck.c` links libap's `regcomp`/`regexec`/`tre-mem` into a
glibc program and sweeps collating symbols and equivalence classes
against glibc's engine. It needs TWO compiles **and a staged
`regex.h`**: the two libraries disagree about `regex_t`'s layout *and*
about the REG_* numbers, so one translation unit cannot hold both --
a SHIM half is built with APE's header and answers in `int` and
`const char *`. Errors are compared by NAME, as `strerror-xcheck`
does and for the same reason. `regerror.c` is left out (it pulls
Plan 9's `u.h`), which is why the shim names the codes itself.
Its **section 3 is a control of the instrument**, not of the library:
ordinary brackets with no collation in them, which must stay at 0
when the collation code changes.
`sys/src/ape/lib/libressl/test/` is separate: it is
upstream's own ML-KEM and SHA-3 vectors, run by `mk test` there.

Beyond that, testing is still mostly ad-hoc — compile a program under
APExp and see whether it builds and runs.


---

## `rdev-test.c`

Came from `cmp` printing nothing for two files that differ at byte 17,
while Plan 9's own `cmp` one window over answered correctly.

**It transcribes `diffutils/src/system.c`'s `same_file()` verbatim
rather than describing it.** The whole question is what *that* function
answers about two files on this system; a paraphrase would be a
different test, and a test of a paraphrase would have passed.

- **Section 0 is the control and a second measurement at once.** Two
  ordinary files must have different `st_ino` — POSIX requires it, and
  if it fails nothing below means anything, since `same_file` would be
  answering on the dev+ino arm before reaching the one under test. It
  also prints `sizeof(ino_t)` and both inodes, which is where APE's
  **16-bit `ino_t`** shows.
- **Section 1** asserts that two distinct character devices are not one
  file. It finds them rather than naming a pair, since the names differ
  between systems, and SKIPS rather than failing if fewer than two
  exist — *a section that cannot run must say so rather than pass*.
- **Section 2 is a PROBE**: the exact question `cmp` asks about its own
  stdout. It asserts nothing, because the right answer depends on where
  stdout goes — on a terminal it must be "no", and redirected to a file
  the question is moot, since cmp's test requires stdout to be a char
  device. *That dependence is why it is a probe and not a check.*

0 failures on gcc. **The control fires**: the old behaviour replicated
beside it (st_rdev constant) gives **exactly 1**, section 1, with
section 0 still passing — which is what says the instrument isolates the
right arm of `same_file` rather than merely noticing something is wrong.

`_rdevmark()` is the version marker, the eighth use of the idiom and the
one it matters most for: *the bug it guards against is one whose entire
symptom is that nothing is printed*, so a test silently measuring a
stale libap would be indistinguishable from a pass.

## `devreg-probe.c`

**A probe, not a test, and the only instrument here with NO HOST
FORM.** Every other cross-check in this tree exists because the host
can answer the question more cheaply; this one asks what *rio* serves
and over which protocol, so a gcc build would measure a machine that
has neither rio nor `/dev/mouse`. The build line is `pcc` alone, and it
has to be run inside a rio window with no wish running.

**Where it came from.** `select()` was given an arm that reports a
regular file readable at once, which is what POSIX requires and what
`poll-test` had just measured as broken. The predicate was
`_isregular`, i.e. `S_ISREG` -- and on Plan 9 `S_IFREG` is
`_dirtostat`'s FALLBACK for "reached through a 9P mount" rather than a
fact about the file. rio serves `/dev/mouse` that way. The same rebuild
that put `poll-test` at 0 left Tk showing a **white window**, frozen on
the first of 97 files.

**What it prints**: for an ordinary file with bytes in it, an empty
one, rio's four (`mouse`, `cons`, `winname`, `snarf`) and three kernel
devices -- the `S_IS*` kind, the length, and what a zero-timeout
`select` answers. **It never reads any of them**, which is the one
thing it must not do: reading `/dev/mouse` is exactly the call that
hangs, and a probe that hangs measures nothing.

- **Section 0 is the control** -- a file with five bytes in it must be
  `REG` and must select readable. It says so in the output if it is
  not.
- **Section 1 is the deliberate fallback** and is printed only so that
  nobody reads it as a fault: an empty regular file does not take the
  fast arm, because the discriminator is a positive length.
- **Section 2 is the question**, and the header writes down what would
  refute the whole story: `/dev/mouse` reported `chr`, or reported
  `REG` and *not ready*, means the freeze is something else.

`_selregmark()` is the version marker, the ninth use of the idiom, and
the one with the shortest fuse -- the two states it separates are "wish
draws" and "wish freezes with a white window", which look identical
from the prompt for the first second.

**It has not been run yet.** The mechanism above is argued from source,
and this file's own tally for that is about one in eight.

## `pthread-test.c`

**The first instrument in this tree that can HANG, and so the first
that arms an alarm.** `SIGALRM` turns a freeze into a named failure:
the handler prints which section was running and what call it was about
to make, then exits 99. Every section flushes a marker *before* the
call, in file order, so the last line printed names the statement that
did not return. *A frozen test and a failing one are identical from the
prompt* -- this file's own rule -- and the alarm is what separates
them.

**Where it came from.** xz's hang, after two rounds spent on poll(),
select() and O_NONBLOCK, all three of which xz does use and none of
which was the fault. `ps` plus two `acid` stacks named it in one run:
xz is multithreaded, and libap's `pthread_create` had three bugs --
a child rendezvous with no partner, an unwritten `*t`, and an `attr !=
NULL` rejection that `pthread_cond_timedwait` tripped over on every
call. `docs/notes/libap.md` has the stacks.

**Five sections, and the split matters**: 0-2 ask whether a thread ever
*runs*, 3-4 whether `pthread_cond_timedwait` ever *waits*. They are two
bugs that look like one hang -- fixing the spin alone gives a program
that waits patiently for work nobody will do, and fixing the handshake
alone gives one that does the work at 100% of a core.

- **Section 0 is the control**: the bare claim that `pthread_create`
  creates a thread. It returns early if that fails, since nothing below
  would mean anything.
- **Section 4 does the arithmetic the reader would**: ten 100ms waits
  must take about a second. The instant-return bug makes them take
  none, and the loop containing them is what pinned the system figure.

**The control fires.** A `-D` rename substitutes a `pthread_cond_timedwait`
returning EAGAIN at once -- the replaced behaviour exactly -- and the
test reports **3 failures**, with `returned 11 (EAGAIN) after 0 ms` and
`ten 100ms waits took 0 ms`. *xz's spin, reproduced on the build host
in one compile.* 0 failures on glibc.

`_pthreadmark()` is the version marker, the tenth use of the idiom.

## `fsync-test.c`

**Three sections, and section 2 exists because section 0 can pass for
the wrong reason.** The bug was `fsync` returning `EINVAL` always; the
obvious test is "fsync of an open file returns 0", and an `fsync` that
returned 0 to *everything* would pass it. So section 2 requires EBADF
for a closed descriptor and for `-1`: **a function that cannot fail is
its own kind of lie.**

Section 1 reads the bytes back after the call. It cannot fail on either
system, and that is what it is for -- it says the call is a no-op
rather than something that quietly did harm.

**Where it came from**: `unxz` decompressing correctly, printing
`Synchronizing the file failed: Invalid argument`, and **deleting its
own output** -- xz turns a nonzero `fsync` into `success = false` and
then removes the destination, with `opt_synchronous` on by default.
`docs/notes/libap.md` has the chain.

0 on gcc; the control, a one-line `sed` putting the replaced
`errno = EINVAL; return -1` back, reports 1. `_syncmark()` is the
version marker, the eleventh use.

### fsync-test's first run printed nothing, and that is a finding

`pcc -o fsync-test fsync-test.c && ./fsync-test` on 9front produced
**no output at all** -- no header, no PASS, no failure count, no
diagnostic -- and the prompt came back. **That is not a pass**, and it
is the failure mode this file's own rule names: *a fault, a kill and a
clean finish all just give the shell prompt back.*

What settled the direction was a line in the same screenshot rather
than anything about the test: `unxz /tmp/t.xz` still answered
`Synchronizing the file failed: Invalid argument` and `cat /tmp/t`
still said no such file. **So that build did not contain the fix**, and
this tree already carries the reason twice over -- `mk install`
rebuilds `libap.a` without relinking binaries already built against it,
so `xz` keeps the old `fsync` until something forces the relink, and a
`pcc`-built test links fresh against whatever libap is installed.

Three changes so that it can never be ambiguous again, and each one is
a different reading:

- **`setvbuf(stdout, NULL, _IOLBF, 0)` as the first statement.** A
  fully buffered stdout loses every line a process printed if it dies
  before exit -- and `devreg-probe` had just measured `/dev/cons`
  answering `S_ISREG` with `FD_ISTTY` unset, so "stdout is a terminal,
  therefore line buffered" is not safe to assume here.
- **A first line printed and flushed before any work**, so "nothing
  ran" and "stopped at the first call" stop being the same output.
- **`_syncmark()` was already there**, and it is what makes the silence
  worth chasing rather than shrugging at: against an old libap this
  cannot link. So a silent run has to be told apart from a build that
  never happened -- `echo $?`, or `pcc` on its own.

*`pthread-test` had the first two from the start, for the same reason
written down before the fact. `fsync-test` did not, and the round it
cost is the argument for making it the default.*

## `regpair-probe.c`

**The second NATIVE file in this directory**, after `truefalse-test.c`,
and for a related reason: the question is about a *backend*, so it has
to be asked of that backend directly. `8c`/`8l`, not `pcc`. To ask it
of 386 from an amd64 machine, that is `8c` either way -- 8c is the 386
compiler and it runs on the host.

***Its result is whether it COMPILES, not what it prints.*** If it
links it prints its own sums, so that the code cannot be dismissed as
dead, but the measurement is the compile.

**Where it came from.** `objtype=386 mk install`, the first cross build
this tree has attempted, stopped on the fourth command with `ar.c:586
bad in naddr: REGPAIR` -- `as->offset = ap->size;`, both members
`vlong`. A plain 64-bit member-to-member assignment, in a file with one
commit in this repo.

**Why no previous build could have found it**: `OREGPAIR` appears in
`8c/` and `cc/pswt.c` and nowhere else, and `8c/cgen64.c` -- the entire
64-bit code generator -- is 8c's alone, because a vlong is a single
amd64 register and 6c needs no such file. *The 386 backend's 64-bit
path is precisely the part of kencc every build here has been unable to
reach.*

**Six cases, each in its own function so a diagnostic names a line and
therefore a construct**: ar.c's exact shape (two pointers, member to
member), the same between locals, a 32-bit widening into a 64-bit
member, a 64-bit member read with no 64-bit destination, the
single-pointer shape, and a 64-bit member passed as an argument. The
split between "store" and "load" is the one that pays first: if case 1
fails and case 4 passes, the store side is where to look.

***BUT THE HEADER SENDS THE READER AWAY FIRST***, and that is the point
of it. Which construct breaks does not matter until it is known whose
bug it is, and one command settles that: `8c -FTVw /sys/src/cmd/ar.c`
in a plain `term%` window, where `8c` is 9front's own rather than
APExp's. The same message means upstream's; a clean compile means ours,
and `git log --oneline sys/src/cmd/cc/` is a thirteen-commit bisect.
*An instrument that would be read before the question it answers is
worth a paragraph telling the reader not to.*

### The A/B fired, and it also refuted the bisect plan

**Stock `8c` compiles `ar.c` and APExp's does not**, with the same
input file, and the whole of `/sys/src` cross compiles to 386 on the
host. So the fault is the compiler, and it is ours.

***And then the next step as written was wrong.*** The probe's header
said to bisect `git log --oneline sys/src/cmd/cc/` -- thirteen
commits -- and that cannot work: **this repository's root commit
already contains `isbool`, `vlasizevar`, `alignas_req`, `_Generic` and
VLA**, so the import is APExp's compilers at an advanced state and not
9front's. Every kencc patch older than the repository is invisible to
the history.

*A bisect would have run to the root and reported "it was always
broken"* -- which is a wrong answer wearing the shape of a result, and
the most expensive kind, because each step is a compiler rebuild on the
VM. **The git history is not the delta from stock, and nothing in this
tree had ever needed it to be until a second compiler existed to
compare against.**

So the instrument is a source diff against the running system,
`diff -r /sys/src/cmd/cc $home/APExp/sys/src/cmd/cc`, which only the VM
can take -- and which is trustworthy now in a way it was not a month
ago, since `st_rdev` is what stopped `diff` calling two different files
identical.

**And one build halves the search before any reading.** APExp's `8c/`
references names only APExp's `cc.h` defines (`conformalign`, `talign`,
`dupokall`), so stock-`cc` with APExp-`8c` will not compile; the other
pairing will, because stock `8c/` asks for nothing new. Build `8c` from
APExp's `cc/` and stock `8c/`: a failure puts the fault in the shared
front end, a pass puts it in `8c/` -- and the latter would be a surprise
worth having, since the only changes this repository made there are
`-J`'s and `-C`'s and both are behind flags that compile does not pass.

### The ten-backend run: the split is by WORD SIZE, and it is three bugs

`regpair-probe.c` compiled by every kencc backend APExp ships:

```
6c amd64   COMPILES     7c arm64   COMPILES
9c power64 COMPILES     kc sparc64 COMPILES

8c 386     case 1
5c arm     case 2's parameter, case 2's return
qc power   case 2's return
1c 68000   cases 1,2,3,4,5,6 -- and `too many errors'
2c 68020   the same set
```

**Every 64-bit backend passes and every 32-bit backend fails**, which
is what a path only a register PAIR can reach looks like -- and it says
the four that pass prove nothing about the four that fail.

***They are not one bug.*** 5c and qc fail on RETURNING a vlong, which
8c compiles. 8c fails on case 1, which 5c and qc compile. 1c and 2c
fail on everything, which reads as no vlong support rather than a
defect in it. *So "the 32-bit backends are broken" is a summary, not a
diagnosis*, and the cross-compilation item is at least three pieces of
work rather than one.

**8c's result is the sharpest thing in the run: case 1 and nothing
else.** Not the parameter, not the return, not the 32-to-64 widening,
not `d->offset = d->offset + 1`, not the vararg. Its 64-bit support is
broadly working and exactly one shape is not -- *the shape `ar.c:586`
uses*. Cases 7 to 11 were added to split that shape along its three
seams (how many indirections, whether the two structs share a TYPE, and
whether load and store are one expression). **If case 8 -- the same
work in two statements through a local -- compiles where case 1 does
not, the fault is holding two register pairs live at once, which is the
register allocator rather than the shared front end.**

#### And the file demonstrated a reporting trap on itself

**A compile-time result can only name a LINE, so it rots the moment the
file is edited above it.** Cases 7 to 11 were appended *below* case6
for exactly that reason -- and then writing the results table into the
header pushed every measured line down 48 anyway. *Appending to the
code is not enough when the prose is at the top.*

The table is keyed on CASE now, with both the run's line numbers and
the current ones, and the header says to re-key rather than renumber.
It is the same family as the stale-log rule already in CLAUDE.md:
*anything measured from outside the file in front of you should say
where it came from*, and a line number is measured from outside.

#### Still missing

**Stock `8c` on this file.** The `ar.c` A/B says APExp's compiler is at
fault; this file says which construct; *only the two together say the
construct is a regression rather than something kencc never had.* And
if stock 8c also fails on case 1, then case 1 differs from `ar.c:586`
in some way that matters and the reduction is not yet faithful.

### Stock 8c compiles the probe: it is a regression, with a three-line repro

```
term% cd APExp/sys/lib/tests
term% 8c regpair-probe.c
term% lc regpair-probe*
regpair-probe.6  regpair-probe.8  regpair-probe.c
regpair-probe.7  regpair-probe.9  regpair-probe.k
```

A `regpair-probe.8` where APExp's own `8c` produced a diagnostic.
**Both halves of the A/B now agree**: stock compiles `ar.c` and the
probe, APExp's fails on both, same inputs. *So the probe is a faithful
reduction and the thing to look for is a change that breaks
`d->offset = s->size` on a 32-bit target and nothing else.*

**That is the whole value of a reduction**, and it is worth saying what
it bought: the search went from "something in a compiler, against a
946-line `ar.c`" to three lines, two structs and one statement, with
eleven neighbouring constructs that all compile and bound it on every
side.

The prediction for cases 7 to 11 is written down **in
`docs/releases/0.7.md` and deliberately not in the probe's header**,
because editing that header is what moved the measured line numbers
last time. *An instrument's results table and the speculation about the
next run do not belong in the same file.*

### Prediction A refuted: the discriminator is that the two structs DIFFER

```
bash-5.3$ 8c regpair-probe.c
regpair-probe.c:181 bad in naddr: REGPAIR
regpair-probe.c:181 bad in naddr: REGPAIR
```

181 is case 1 and nothing else is named, so **cases 7 to 11 all
compile.** Written down before the run: **A** -- two register pairs
live at once, i.e. the allocator -- predicted **case 7 would fail**.
**It compiles.** Case 7 is `d->offset = e->offset` through two `Dst *`:
two indirections, two base pointers, one pair. *Register pressure is
identical to case 1.* A is dead.

**B holds: the two structs being DIFFERENT TYPES is the whole
discriminator.** `Dst *` to `Dst *` is fine; `Dst *` to `Src *` is not.
That is a far smaller target than "the 64-bit path", and it moves the
search from the register allocator to the type machinery in the shared
front end -- which is where this tree's patches actually are.

**`tcopy` was the first guess and reading ruled it out rather than a
run**: it is untouched here, and returns `t` unchanged for a scalar
whose link has not moved, so `Dst.offset` and `Src.size` are the *same*
`types[TVLONG]`. The member types are identical; only the enclosing
ones differ. *A hypothesis that can be killed by opening the function
should be killed that way.*

**And the original reduction had a fault worth naming**: `Src` differs
from `Dst` in THREE ways at once -- no self-pointer, eight bytes
shorter, differently named member. A case that varies three things
cannot say which one matters, which is the same defect as a test with
no control. Cases 12 to 14 hold two constant at a time.

### The tree printed; hypothesis B died too; and I repeated my own mistake

```
 == naddr ==
REGPAIR <11> VLONG regpair-probe.c:181
   REGISTER R9 <11> LONG <eof>
   REGISTER R10 <11> ULONG <eof>
```

The uncommented `prtree` works, and the shape is unremarkable: an
ordinary VLONG register pair reaching a function that can only take an
address, twice.

**Only 181 is named, so cases 12, 13 and 14 compile** -- and **case 14
is `s->size = d->offset`, the SAME two types as case 1 merely
reversed.** So "the two structs are different types" is dead, as
`case 7` killed "two register pairs live at once".

***AND CASES 12 TO 14 EACH VARIED THREE THINGS FROM CASE 1*** -- tag,
layout and member name. That is precisely the fault written down one
entry above them, about the original reduction varying three things.
*Writing a rule down is not the same as following it*, and the cost was
a round: three cases that narrow the space less than one well-chosen
one would have.

What the round does establish is the narrowness:

	d->offset = s->size     case 1   FAILS
	s->size   = d->offset   case 14  passes   same two types
	gdst      = s->size     case 10  passes   same source
	d->offset = gsrc        case 11  passes   same destination
	d->offset = p->offset   case 13  passes   Src's LAYOUT
	return s->size          case 4   passes

`Src.size` loads fine, `Dst.offset` stores fine, and only the two
together fail -- while `Plain`, which has `Src`'s layout, stores into
`Dst.offset` happily.

**Case 15 is one variable**: `Named` is `Plain` with the member renamed
`size`. Fails -> the member NAME, which would point at `dotsearch` and
the Sym. Passes -> `Src` itself, tag or position, and separating those
needs a struct declared early, which moves line 181 and is therefore a
separate round.

### Case 15 passes, and the probe ran out -- `regpair-min.c`

`Named` is `Plain` with its member renamed `size`, and it compiles, so
**the member name is innocent**. Three hypotheses are now dead:
register pressure (case 7), the two struct types differing (case 14),
and the member name (case 15).

*The run was verified with a `grep` for `case15` before being
believed.* Output identical to the previous run is exactly what a file
that never got saved produces, and that check belongs in the same
family as the stale-log rule.

***AND THE PROBE IMPOSED A VARIABLE IT COULD NEVER TEST***: `case1` is
the **first function in the translation unit**, and every case that
passes comes after it. No case added to that file could show this,
because every one of them was added to the same file. **A harness can
hold something constant so thoroughly that it stops looking like a
variable at all.**

So `regpair-min.c`: case 1 and nothing else, ten lines, native `8c`.

- **Fails** -> the construct is self-contained and this is the
  reproduction a bug report carries.
- **Compiles** -> the construct is innocent and the surrounding file is
  the variable, with per-function backend state (`regsalloc`'s stack
  offsets, `maxargsafe`, the register tables) as the live candidate --
  initial for the first function, accumulated for every later one.
  *That would explain why the probe's other fourteen are unanimous.*

**Either answer is worth more than a sixteenth case.** When a reduction
stops narrowing, stop adding to it and ask whether the harness has
become part of the measurement.

### `regpair-min.c` fails: two structs and one assignment

```
regpair-min.c:69 bad in naddr: REGPAIR   (twice, with the tree)
```

**Ten lines reproduce it.** No other cases, no 450-line harness --
`regpair-probe.c` did its job and is now superseded for this question.
*The reduction that matters is the one somebody else can paste into a
bug report.*

**And `8c/cgen.c` is cleared by reading too**: against upstream HEAD its
only non-rename, non-comment difference is the `OALLOCA` case, a new
`case` label unreachable without a VLA. All five of our 8c deltas hold
as inert, which leaves `cc/`.

**The one hypothesis a minimal file cannot kill by being minimal** is
the one the probe imposed: `case1` is the first function here too.
`-DLEADER` puts a trivial function ahead of it, so two compiles of one
file settle it -- and `cpp` keeps line numbering through an `#ifdef`,
so the assignment is on the same line in both builds and the
diagnostics compare directly.

*A toggle inside the file beats a second file*, because the two builds
then differ in exactly the thing being tested and in nothing else --
not in struct layout, not in line numbers, not in what else happens to
be present.

### The -DLEADER run measured nothing, and the LINE NUMBER is what said so

```
bash-5.3$ 8c -DLEADER regpair-min.c
regpair-min.c:69 bad in naddr: REGPAIR
```

**69 is the PRE-LEADER file.** With the `#ifdef LEADER` block present
the assignment is on line **101**, and the header said so in advance:
*"the assignment is line 101 in both"*. So that copy had no `#ifdef
LEADER` for `-DLEADER` to switch, the flag defined a macro nothing
reads, and the compile was the previous one repeated.

***A `-D` that names nothing is silent***, which is the same shape as
the APE header rule about `pcc` dropping an unnamed flag: a switch that
does nothing and a switch that worked and changed nothing produce
identical output. The only thing separating them here was a line number
written down before the run.

**That is the whole value of predicting the OBSERVATION rather than the
conclusion**, and it is worth noting that it cost nothing: one clause
in a comment, which then caught a void measurement the same day. *The
rule this tree already carries -- a measurement of a build that does
not contain the change measures nothing -- usually needs
`git merge-base` to enforce. For a compiler diagnostic, the line number
enforces it for free.*

**Re-run after pulling `d3602728`.** Line 101 in the diagnostic means
the file under test is the right one; 69 means it is not.
