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
