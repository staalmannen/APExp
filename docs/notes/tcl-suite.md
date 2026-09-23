# Tcl's own test suite, and the libap bugs it found

Split out of `CLAUDE.md` (2026-09). The whole Tcl suite campaign: the
allocator, `socket -server` and the missing loopback, `shutdown()`,
`listen()`, the `select()` copy-process design in `ap/plan9/_buf.c`, `fd_set`,
and the `chan-io-44.1` and `chan-io-73.1` hangs. The open items are summarised
in `CLAUDE.md`; the route to each answer is here.

Cross-references to "the section above" or "below" may now point into a
sibling file under `docs/notes/`; `CLAUDE.md` has the index.

---

### Tcl's own test suite, and the two things it has found so far

Run from `sys/src/ape/cmd/tclsh`:

```
./tcltest $home/APExp/sys/src/external/tcl/tests/all.tcl >/tmp/tcl-all.out 2>&1
```

**Use the harness, not that command.** `sys/lib/tests/tcl-runall.tcl` is
the counterpart of `tk-runall.tcl` and exists for the same reason: a
fault, a kill and a clean finish all just give the shell prompt back,
so without a completion marker a log cannot be read at all. It sets
line buffering, wraps `::exit` for the marker, and carries the skip
list below.

```
cd sys/src/external/tcl/tests
$home/APExp/sys/src/ape/cmd/tclsh/tcltest \
	$home/APExp/sys/lib/tests/tcl-runall.tcl >/tmp/tcl-all.out >[2=1]
```

**It does not finish**, and that is the most important result in it. Of
167 test files it reaches twelve; the run stops in the middle of
`chanio.test` with no summary line.

**A KILLED FILE AND A HUNG FILE ARE COMPLETELY DIFFERENT HERE, and the
first round of reading this log ran them together.** Tcl's `all.tcl`
leaves `-singleproc` at its default of **0**, so tcltest runs each file
in **its own process** and reads the child's output through a pipe
(`tcltest.tcl:2940`):

```tcl
set cmd [linsert $childargv 0 | $shell $file]
set pipeFd [open $cmd "r"]
while {[gets $pipeFd line] >= 0} { ... }
close $pipeFd
```

- **A child that dies costs only itself.** `close` raises, tcltest
  catches it, prints `Test file error: ...` and goes on. That is
  exactly what the allocator's OOM does to `binary.test`, and the log
  proves it -- `brodnik.test` is the very next line after
  `Test file error: tcltest 69507: Killed: Insufficient physical
  memory`.
- **A child that hangs costs every file after it.** That `gets` is
  blocking and there is no timeout anywhere in tcltest, so the parent
  sits in it forever writing nothing more.

**So the OOM was never what stopped the run**, and CLAUDE.md's own
earlier advice -- "skip the files that cannot fit in the VM so the
other 161 are measured" -- was written before anyone read that loop and
assumed a kill was fatal to the whole suite. It is `chanio.test`
hanging that costs the other 155 files, and skipping *that* is what
buys a measurement. **Read the loop that runs the tests before drawing
conclusions from the shape of the log.**

`chanio.test` is full of `openpipe` and blocking `chan gets` against a
child `cat`, and the `chan-io-6.4x` cluster beside it reports a
blocking `gets` answering `-1` where it should have returned a line --
so a `gets` that never returns is what to expect there.

**Two runs now end at the same place: after `chan-io-8.1`'s failure
report, with nothing after it.** The CPU during the freeze is
**constant but low**, which is the BLOCKED shape rather than the
spinning one -- a process waiting for something that will never arrive,
not a loop inside one command. Tk's suite had one of each and they
wanted completely different fixes; keep them apart.

**And the last line of that log is a LOWER BOUND, not the answer.**
This is the "the log lies about where the run stopped" trap from the Tk
section, met one process further down than before: `tcl-runall.tcl`
sets line buffering on **itself**, but in multi-process mode every test
file is a separate `tcltest` whose stdout is a **pipe**, and nothing
sets that child's buffering. Up to a bufferful of the child's output is
still inside the child when it wedges.

So the obvious reading -- that `chan-io-8.2` is the hang, it being the
next test and the first in the file to pair a `chan event` with two
`vwait`s -- **is a hypothesis the log cannot support**, however
plausible it looks.

**The command that settles it runs the file in the harness's own
process**, where the line buffering does apply:

```
tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t
```

`-verbose t` prints each name as it *starts*, so the last one is
genuinely the test that did not return -- the same one line that
settled `unixWm-50.5`.

**The option is `-notfile`, not `-skipfile`**, and the first version of
the harness said the latter and was refused outright:

```
unknown option -skipfile: should be one of -asidefromdir, -constraints,
-debug, -errfile, -file, -limitconstraints, -load, -loadfile, -match,
-notfile, -outfile, -preservecore, -relateddir, -singleproc, -skip,
-testdir, -tmpdir, or -verbose
```

`skipFiles` is the internal accessor (`tcltest.tcl:63`) and `-notfile`
is the option that sets it. **Reading the proc name for the option name
is the same mistake as reading a grep hit for an implementation**, and
the error message lists every valid option -- the cheapest possible
check, there to be read.

`-notfile` also has a **non-empty default**, `l.*.test`, whose comment
says "skip files that appear to be SCCS lock files"; setting the option
replaces it, so the harness repeats it. It costs nothing either way --
the glob wants a literal dot as the second character, so it matches
`l.foo.test` and **not** `lindex.test`, and Tcl's seventeen `l*.test`
files do run. Worth checking rather than assuming: "the whole `l*`
family is silently skipped" would have been a far bigger finding than
the one that round actually had.

**Do not read the failure list as a survey**: it covers the first 7% of
the suite in alphabetical order.

Two findings, both worth a test of their own.

**1. A double just past the float range may not round to infinity.**
`binary-53.25` and `binary-53.26`:

```tcl
binary scan [binary format H* 47effffff0000001] Q round_to_inf
binary scan [binary format R $round_to_inf] R inf1
expr {$inf1 eq Inf}		;# answers 0, wants 1
```

`binary format R` is a 32-bit float, so this is a double -> float
conversion and a read back. The constant is not arbitrary: FLT_MAX is
`2**128 - 2**104`, the next float is infinity, and the midpoint is
`2**128 - 2**103`, exactly `0x47EFFFFFF0000000`. The test value is that
**plus one ulp of a double**, so round-to-nearest must give infinity
with no tie to break, and `0x47EFFFFFEFFFFFFF` must give FLT_MAX.

Three different things produce a `0` there and they want different
fixes, which is why `sys/lib/tests/float-overflow-test.c` asks them
separately: the conversion itself (6c's `CVTSD2SS`, or the folded path
in `cc/scon.c` -- and note the sign-of-zero work found `ieeedtof` in
every `*l/obj.c` mishandling this boundary); `isinf` and the
`INFINITY`/`HUGE_VAL` macros, which `<math.h>` got wrong once already;
and **printing**, because `eq Inf` is a *string* comparison -- it is
asking whether Tcl's double-to-string gives exactly `"Inf"`, which Tcl
reaches through `TclIsInfinite()` -> `isinf()`.

**2. free() does not give memory back, except to a request of exactly
the same size.** `ap/malloc/malloc.c` is Plan 9's: one free list per
power-of-two class, and `free()` pushes a block onto the list for its
own class and nowhere else. So

- every request is rounded **up to a power of two** -- a 33 MB string
  costs 64 MB;
- **nothing splits or coalesces**, so 64 MB on the `2**26` list does not
  satisfy a 32 MB request; the heap grows instead;
- `realloc` is malloc-copy-free, so growing one buffer to N bytes walks
  the classes and strands a dead block in each, leaving about 2N of
  garbage that only an identically-sized request can reuse, on top of
  the up-to-2N rounding.

Growth by realloc is how every interpreter builds a big string, so this
is the shape behind the OOM.

#### realloc extends at the top of the heap now, and that was the half that mattered

**The third bullet is fixed and the second is not**, and measuring the
two separately is what decided which to do. Building the three files on
the build host against a private `sbrk` -- the same technique as the
libm work -- gives the numbers before and after:

| | before | after |
|---|---|---|
| growing 1 KB -> 1 MB by realloc | 2005575 bytes | **1075488** |
| peak heap for one 32 MB string | 62 MB | **32 MB** |
| three 32 MB strings, total heap | 64 MB | **58 MB** |
| random alloc/realloc/free, 400k ops | 81.6 MB | 81.6 MB |

`realloc` now asks whether the block is the **last thing on the heap**
and, if so, extends the break instead of allocating a new block,
copying, and stranding the old one on its class's free list. A buffer
being grown by doubling nearly always is the last thing on the heap, so
the whole strand ladder disappears. `_malloc_growtop` in `malloc.c`.

**CONFIRMED ON THE VM, AND IT BOUGHT BACK A WHOLE TEST FILE.**
`malloc-reuse-test` reports **0 failures** there, with 1063072 bytes
for 1 KB -> 1 MB against the host's predicted 1075488 -- and, more to
the point, `binary.test` **no longer dies**:

```
binary.test                                      <- used to be followed by
==== binary-53.25 Binary float round to Inf FAILED     "Test file error:
==== binary-53.26 FAILED                                tcltest 69507: Killed:
brodnik.test                                            Insufficient physical
                                                        memory"
```

It now runs to the end and reports only the two `binary-53.2x` Inf
tests, which are the separate and much smaller question below. That was
written down beforehand as a genuine guess -- "`binary.test` may or may
not survive on the halved peak" -- so it is worth recording that
halving the peak was enough.

**MEMORY ALREADY OWNED MUST BEAT MEMORY FROM THE KERNEL, and the first
cut of this got it backwards.** Without a check that the target class's
free list is empty, extending at the break walks straight past the
block the *previous* string freed: three 32 MB strings in a row cost
**97 MB** where the unfixed allocator cost 64. Every other number in
the table improved at the same time, so only the total said so. That is
section 4 of the test, and removing the check makes it fail and nothing
else does -- checked, because a check that cannot fail is not a check.

Two smaller things went with it, and the first is a prerequisite:

- **each large allocation leaked its own alignment slack.** The code
  sbrk'd `size+15` and aligned *inside* the block, throwing the gap
  away -- measurably 47 bytes of overhead on a 1 MB block where the
  layout says 32. It also meant a block did not *end* where the break
  was, so the top-of-heap test above could never have matched.
  `_malloc_brk` aligns the break itself, which costs the gap once.
- **`1<<pow` is an `int`**, so for `pow` 31 it is signed overflow; it
  converts to a vast `size_t` and every allocation above 1 GB quietly
  failed. `(size_t)1<<pow` throughout.

**Splitting is the obvious fix for the second bullet and does not
work.** A block of class k occupies **`32 + 2**k`** bytes -- a 16-byte
header padded for `max_align_t`, the payload, the whole rounded up to
16 -- so two class-k blocks need `64 + 2**(k+1)`, **thirty-two** bytes
more than the single `32 + 2**(k+1)` they would be carved from.
Tightening the padding does not rescue it: with an exact `16 + 2**k`
stride two still need `32 + 2**(k+1)` against `16 + 2**(k+1)`. A header
living outside the power of two cannot buddy-split, whatever the
padding.

**Corrected:** this used to say `16 + 2**k` and so understated the
slack by sixteen bytes a block. The conclusion survives and the
arithmetic did not -- **the stride is one line to measure and was
derived instead.**

And splitting is not clearly wanted even so. Searching upward for any
larger free block means a 1 KB request shreds a 64 MB block that
nothing can reassemble, there being no coalescing; so it would have to
be bounded, and bounded splitting buys much less than the realloc
change did. Section 5 of the test is the adversary that would show it.

**The block layout now lives in one place**, `malloc_impl.h`. It used
to be copied verbatim into `malloc.c`, `free.c` and `realloc.c`, and
realloc.c's copy had already drifted -- it carried a `static Arena
arena` that nothing used, beside the real `__malloc_arena` the other
two share. Three copies of a struct layout is the `HFILES` trap in
miniature. **And `HFILES` in that mkfile was empty**, so the new header
is listed there; without it `mk` rebuilds nothing when the layout
changes, which is precisely how Tk's event source broke once.

`sys/lib/tests/malloc-reuse-test.c` measures all of this through
`sbrk(0)` -- what the process took from the kernel, which is the
quantity the note is about, rather than what malloc believes it handed
out. **Checking it against glibc first caught a bad assertion**, as the
convention says it should: "the finished buffer is reusable at its own
size" is not a library rule but an allocator policy, and glibc hands a
block that size back to the kernel instead. It is reported, not
asserted.

**The rest of the list is not new work.** `chan-16.9` wants
`socket -server`, which libap answers `ENOTSUP`; the seven
`chan-io-6.4x`/`8.1` failures are one cluster, all `-buffersize 16` with
`testchannel inputbuffered` reporting 0 where a partial buffer should
remain, on a pipe and on a file alike. Tcl channels use `read`/`write`
directly, not stdio, so the stdio work above is not implicated.

**Getting a full run is the first job here**, not fixing the ten -- and
the thing in the way is `chanio.test` hanging the parent, not the OOM.
`tcl-runall.tcl` skips that one file and says so loudly; take it out of
the skip list the moment the `chan-io-6.4x` cluster is understood.

**The prediction written before the last run, and how it did.** It said
the run should reach all 167 files and print the marker, and that
`binary.test` might or might not survive the halved peak.
`binary.test` survived -- that half was right. The run did not reach
the marker, for a reason that had nothing to do with the allocator: the
harness named an option that does not exist and tcltest refused
everything (see `-notfile` above). **A harness bug and a suite bug look
identical from the shell**, which is the whole argument for the marker
-- and the marker did its job, reporting `exit called (code 1)` rather
than letting a refused run read as a finished one.

#### The first real measurement: 66 files, 195 failures, and 86 of them are one missing feature

Skipping `chanio.test` bought **twelve files -> about sixty-six**, in
alphabetical order through `io.test`, and a log of 4883 lines against
231. The prediction that it would reach all 167 and print the marker
was **wrong**: it stopped again, in `io.test`, which is `chanio.test`'s
older-API twin. Constant low CPU again -- blocked, not spinning.

**195 failures, and the shape is what matters, not the number:**

| file | | |
|---|---|---|
| `http11` | **86** | one cause -- no `socket -server`; see below |
| `io` | 27 | partial: the file hung part way, so this is a floor |
| `fCmd` | 18 | |
| `clock` | 16 | |
| `filename` | 14 | |
| `cmdAH` | 12 | |
| `env` | 9 | |
| `exec` | 8 | |
| `expr` | 5 | |
| `event`, `binary` | 2 each | `binary` is the two Inf tests above |
| `expr-old`, `chan` | 1 each | |

**`http11` is 86 of 195 and is a single line repeated**, which is the
`testobjconfig` warning from the Tk section arriving on this side:
**one file can dominate a count and say almost nothing about the
tree.** Every one of them is its `-setup` failing:

```
---- Test setup failed:
can't wait for variable(s)/channel(s): would wait forever
    while executing "vwait httpd_output"  (procedure "create_httpd")
```

`create_httpd` starts a local server and waits for it; with no server
the `vwait` has no event source and Tcl refuses it outright. So
**http11 measures one feature, not 86 things**, and the honest count of
distinct problems in this run is closer to 110.

#### `socket -server` answers EOPNOTSUPP, and the real message is thrown away

Seen 30 times in the log as `couldn't open socket: operation not
supported`. **The sockets are not missing** -- `ap/network/` has
`socket.c`, `bind.c`, `listen.c`, `accept.c` and the whole resolver.
`bind()` writes a `bind` control message to `/net/tcp`, falls back to
`announce` when the stack refuses it, and then:

```c
if(n < 0){
	if(errno == EPLAN9)
		errno = EOPNOTSUPP;	/* ap/network/bind.c:87 */
	return -1;
}
```

`EPLAN9` means "a Plan 9 error with no POSIX equivalent" -- **so the
actual message is sitting in `errstr()` unread**, and EOPNOTSUPP is all
that survives. `listen.c:147` and `accept.c:106` do the same.

`sys/lib/tests/socket-server-test.c` prints it. Section 1 walks the
POSIX sequence Tcl uses (`socket`, `bind` to 127.0.0.1 port 0,
`getsockname`, `listen`) so the log names the call that fails -- and
checks that a bind which *succeeds* actually assigned a port, since Tcl
reads it back between bind and listen and a silent zero there is a hang
rather than an error. Section 2 opens `/net/tcp/clone` itself and tries
each spelling of the announce message in turn, printing `errstr()` for
each: **the address syntax is not something to reason about from a
manual page when the machine will say.**

Section 1 is correct on glibc and was checked there; section 2 cannot
be and skips itself where there is no `/net/tcp`. That asymmetry is
deliberate -- a probe of one operating system's network stack is not a
library rule.

**The `__GNUC__` guard in that file is load-bearing and the obvious
spellings are wrong.** `pcc` predefines exactly two things
(`sys/src/cmd/pcc.c:77`), `__STDC__=1` and `_POSIX_SOURCE=`, so
`_PLAN9_SOURCE` and `__plan9__` are both **absent** from an ordinary
`pcc -o x x.c` -- and guarding on either would have compiled section 2
into a function printing "no errstr on this system" on every line. A
whole round trip for a test that cannot report the one thing it exists
to report.

#### The answer: 127.0.0.1 is not a local address on this machine

**The probe ran, and it settles both questions at once.**

```
FAIL bind(127.0.0.1, port 0) (errno 41: OP not supported)
     plan 9 says: not a local IP address
FAIL listen(backlog 5) (errno 38: Connection refused)
     plan 9 says: connection in use

  YES  "announce 0" accepted
  YES  "announce *!0" accepted
  no   "announce 127.0.0.1!0"   -> not a local IP address
  no   "bind 127.0.0.1!0"       -> not a local IP address
  no   "announce tcp!*!0"       -> bad ip address syntax
```

**Binding to ANY address works and binding to the loopback does not.**
Nothing is missing from the stack, from libap, or from Tcl: the machine
simply does not believe 127.0.0.1 is one of its own addresses. Note
`announce tcp!*!0` is refused as well -- the control file does not take
a protocol prefix, which is worth knowing before anyone "fixes" the
address syntax in `_sock_inaddr2string`.

**So the first thing to try is not a code change.** `/net/ipselftab` is
the list the stack decides this from, and on 9front the loopback is
configured by

```
ip/ipconfig loopback /dev/null 127.1
```

which the standard startup normally does. `socket-server-test.c`
section 1a prints that table and says which way it came out.

**CONFIRMED: THE LOOPBACK IS NOT CONFIGURED ON THIS VM.** The whole of
`/net/ipselftab`:

```
10.0.0.0        224.0.0.1       10.0.2.255      ff02::1     10.0.2.0
fec0::5054:ff:fe12:3456         ff02::1:ff12:3456
fe80::5054:ff:fe12:3456         10.0.2.15
255.255.255.255                 10.255.255.255
```

Ten addresses and **no 127.0.0.1**, which is exactly what "not a local
IP address" means. `10.0.2.15` is the QEMU user-mode address, so the
machine has a network; it simply has no loopback. **That one
`ip/ipconfig` line is the fix for the 86 `http11` failures and both
hangs**, and no C change was needed for any of it.

That is worth keeping as a shape: **three rounds of this looked like a
missing feature in libap, and the answer was a line of network
configuration.** What turned it round was printing what the machine
says rather than what the code implies -- the probe, not the reasoning.

**CONFIRMED.** After `ip/ipconfig loopback /dev/null 127.1` the test
reports **0 failures**: bind succeeds, a real port is assigned (53941),
listen succeeds, `/net/ipselftab` grows `127.0.0.0`, `127.0.0.1` and
`127.255.255.255`, and section 2 now answers

```
YES  "announce 0"            YES  "announce 127.0.0.1!0"
YES  "announce *!0"          YES  "bind 127.0.0.1!0"
no   "announce tcp!*!0"   -> bad ip address syntax
```

**`bind 127.0.0.1!0` is accepted, which is new information about the
fallback.** `bind.c`'s comment says "some 9front network stacks reject
the standalone bind control message" -- this stack does not, so the
primary path works and the announce fallback is dead code here. It
stays, because the comment is about *some* stacks and this is one
machine; but nothing on this VM exercises it, so it is not covered by
anything we run.

`announce tcp!*!0` is still refused: the control file does not take a
protocol prefix. Worth knowing before anyone "fixes" the address
syntax in `_sock_inaddr2string`, which is correct as it stands.

#### Do not put ip/ipconfig in apexp-sh

Asked and answered once, so it does not get asked again. **`apexp-sh`
opens with `rfork en`**, and every other thing it does --
`mount-include` and the four `bind -b` lines -- is **namespace-local**
and gone when the shell exits. `ip/ipconfig` writes to `/net`, a kernel
device rather than a namespace mount: it would change the whole
machine's network stack for every process and leave it changed
afterwards. That would be the only line in the script with that
property, and a shell wrapper that silently reconfigures the network is
a surprise for someone who meant to build a program.

Two smaller reasons: it can fail where `/net` is not writable (a cpu
server, say), and `apexp-sh` would then print an error on every launch
for something most users never need; and **whether re-running it on an
already-configured loopback is a clean no-op or adds a duplicate is not
known here** -- which is exactly the sort of thing to measure before
putting it in a startup path.

**It belongs in the machine's own startup** (`/rc/bin/termrc` or
wherever the network is configured), because a machine with no loopback
is misconfigured for anything that uses one, not just APExp. This was
never an APExp bug.

The diagnosis is already in the right place: `socket-server-test.c`
prints `/net/ipselftab` and names the command when 127.0.0.1 is
missing, so **the thing that needs the loopback is the thing that says
it is absent** -- better than a check in `apexp-sh` that runs for
everyone regardless.

**Do NOT make `bind()` fall back to `*` when the requested address is
not local.** It would make these tests pass and it would silently widen
a loopback-only server to every interface -- inventing semantics in the
one direction where it matters, which is the `systray` rule with a
security edge.

#### The errno was lying about the category, and that is ours

`_errno.c` already holds a Plan 9 -> POSIX table with a "from sockets"
section, matched by substring; `_syserrno()` falls back to `EPLAN9`
when nothing matches, and `bind.c` then turns `EPLAN9` into
`EOPNOTSUPP`. "not a local IP address" was not in the table, so:

```
plan 9:  not a local IP address
errno:   EOPNOTSUPP
Tcl:     couldn't open socket: operation not supported
read as: this system has no sockets
```

and that reading cost several rounds. **An error that names the wrong
category sends everyone to the wrong place**, which is the `XLoadFont`
lesson in its errno form. `EADDRNOTAVAIL` is POSIX's "Cannot assign
requested address" and says exactly what happened.

Two entries added, **measured rather than copied out of a header** --
they are the strings the probe printed:

```c
{EADDRNOTAVAIL,	"not a local IP address"},
{EINVAL,	"bad ip address syntax"},
```

**In the table rather than special-cased in `bind()`**, so `connect()`,
`sendto()` and everything else report it too. The errno reads
`48: Address not available` on the VM now, confirmed.

#### ADDING TO THAT TABLE CHANGES CONTROL FLOW, WHICH THIS DID NOT NOTICE

`bind.c`'s announce fallback is gated on

```c
_syserrno();
if(errno == EPLAN9){		/* i.e. "nothing recognised this" */
	... close, reopen, "announce" instead ...
```

so **naming an error in the table stops the fallback running for it**.
A change that looks like pure naming is a change of behaviour, and it
was not predicted.

The tell was in the test's own output, across the two runs:

```
FAIL bind(127.0.0.1, port 0)   not a local IP address
FAIL listen(backlog 5)         connection in use      <- before

FAIL bind(127.0.0.1, port 0)   Address not available
PASS listen(backlog 5)                                 <- after
```

**`listen` moved from FAIL to PASS on a socket with no address and no
port**, because bind no longer makes the second announce attempt that
used to leave the connection in a state listen then tripped over.

It is the right way round for these two entries -- an address the stack
does not own, and one it cannot parse, would fail an `announce`
identically, so retrying buys nothing and only muddies the errno. **But
before adding another entry, ask whether `announce` might have
succeeded where `bind` did not**: that case is the whole reason the
fallback exists, and naming its error would silently disable it. The
comment in `bind.c` says so at the gate.

**And that PASS was hollow, which the test should not have printed.**
The sequence is bind *then* listen; once bind has failed, what listen
does next is undefined and its result is evidence of nothing.
`socket-server-test.c` skips it now and says why. **"A check that
cannot fail is not a check" has a twin: a check that can PASS for the
wrong reason**, and this is the first instance of it in this file.

#### chan-io-28.7, and the hypothesis was wrong by twenty tests

`-singleproc 1 -file chanio.test -verbose t` did what it was supposed
to. The log ends

```
---- chan-io-28.6 start
---- chan-io-28.7 start
```

so the hang is **`chan-io-28.7`**, not `chan-io-8.2`. That guess was
recorded as "a hypothesis the log cannot support, however plausible it
looks", and it was wrong by twenty tests -- the whole `8.x` block
starts *and returns*. **The fifth time in this file a confident
mechanism was wrong and one printed intermediate settled it in a single
run**, and the first where the guess was labelled as one beforehand.

And it is a **socket** test, which the 8.2 guess would have hidden
completely:

```tcl
set ff [openpipe r $echo]	;# child runs "socket -server accept 0"
gets $ff port
set s [socket 127.0.0.1 $port]	;# <- blocking connect to a
                                 ;#    non-local address
```

The child's `socket -server ... 0` binds to any address and works; the
parent then makes a **blocking connect to 127.0.0.1**, and that is the
call that never returns. The `after 1000` timeout that would have
rescued the `vwait` is set on the *next* line and is never reached.

So both hangs and the 86 `http11` failures are one cause after all --
which the previous round guessed and could not show. **The guess being
right about the cause and wrong about the test is worth keeping**: the
mechanism and the location are separate claims, and only one of them
was checkable from the log.

Expect `ioCmd`, `ioTrans`, `iogt` and `socket.test` in the same family.
**Nothing is known about them: no run has ever reached them.**

#### The loopback worked, and chanio now hangs sixty tests later

**The one-line network fix paid for itself and the prediction was still
wrong.** With `ip/ipconfig loopback /dev/null 127.1` run and both files
unskipped, `chan-io-28.7` -- the blocking connect to 127.0.0.1 that had
wedged the parent for two rounds -- **starts, connects and returns**.
It now merely fails. The run gets from `chan-io-28.7` to `chan-io-41.8`,
about sixty tests further in, and then stops again.

The prediction said "all 167 files, the marker printed, the 86 `http11`
failures gone". None of that happened, because the run never leaves
`chanio.test`: twelve files, 455 lines, no marker. **Fixing the cause of
one hang does not mean it was the cause of every hang**, and a file with
several hundred socket tests in it can have more than one.

What did move is real and is worth separating from what did not:

| | before the loopback | after |
|---|---|---|
| `chan-io-28.7` | **hung**, killing 155 files | fails, run continues |
| reached in `chanio.test` | test 28 of ~44 sections | **test 41** |
| failures visible in `chanio` | 8 | 17 |

The nine new ones are **newly measured, not newly broken** -- the same
case as the tktest 25 -> 485 jump, and the third time this file has had
to say so.

**THE LAST LINE IS STILL A LOWER BOUND.** This is multi-process mode, so
`chanio.test` is a child whose stdout is a pipe, and up to a bufferful
of it is still inside the child. `chan-io-41.8` is where the log stops,
not necessarily where the process did. The command that answers it is
the same one that settled `chan-io-28.7`:

```
tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t
```

**Do not guess from what sits after 41.8.** That guess was made once
already, cost a round trip, and was wrong by twenty tests.

**Measuring the other 155 files does not have to wait for it**, and the
two runs are independent. The skip needs no rebuild and no edit --
`-notfile` on the command line replaces the harness's default, and the
harness leaves the caller's alone:

```
tcltest .../tcl-runall.tcl -notfile {l.*.test chanio.test}
```

Keep `l.*.test` in it: that is tcltest's own default for SCCS lock
files, and naming `-notfile` at all replaces it.

#### shutdown() answered success and did nothing, and closed the fd

`chan-io-28.7` is the first test in the suite to reach `shutdown()`, and
`ap/network/shutdown.c` was four lines:

```c
int
shutdown(int fd, int how)
{
	if(how == 2)
		close(fd);
	return 0;
}
```

**Two bugs, and the second is the worse one.**

**It reported success without doing anything** -- the `XLoadFont` family
arriving in libap, and here the cost is a HANG rather than a wrong
answer, because a half-close is a protocol step the peer is waiting on.
The test is

```tcl
set s [socket 127.0.0.1 $port]
puts $s Hey
close $s w			;# shutdown(fd, SHUT_WR)
... vwait for the server's reply ...
```

and the server half reads to end of file before answering. With no FIN
sent, the EOF never arrives, the server never replies:

```
Result was:              Failed Hey
Result should have been: Succeeded {Hey DONE}
```

`Failed` there is the test's own `after 1000` firing. **A program
without a timer waits for ever**, which is exactly the shape of the
hangs this file has spent three rounds on -- and worth noting as a
class: *a stub that returns success in a protocol handshake does not
produce a wrong answer, it produces a wait.*

**And `SHUT_RDWR` closed the descriptor, which POSIX does not.**
`shutdown()` shuts the connection down; the descriptor stays open and
the caller still has to `close()` it -- which every caller does. So
every `shutdown(fd, SHUT_RDWR)` was followed by the caller closing a
descriptor this library had already released, and in between the fd
*number* is free for any `open`, `socket` or `accept` to take. The
caller's `close()` then shuts an unrelated file belonging to someone
else, with no diagnostic anywhere. Nothing in the suite has caught this
yet and it is the reason the file could not simply be left alone.

**What Plan 9 can do about a half-close is NOT guessed at here.** The
candidate control messages are a list in `shutdown.c`, tried in order,
and `socket-server-test.c` section 4 writes the same list to a real
connection's ctl file and prints `errstr()` for each -- the method that
settled the announce spelling, rather than reasoning from a manual page.
Shorten the list to whatever comes back `YES`; if nothing does, this
stack has no half-close and the note below applies.

**A failure is reported rather than swallowed.** With nothing accepted
`shutdown` returns -1 where it used to return 0. A caller that ignores
the result is no worse off; a caller that checks gets an error instead
of a wait, which is the direction this file has preferred every time the
two were in tension -- and it is the only way the absence stays visible.

`SHUT_RD` returns 0 and does nothing, **and that is honest rather than a
fifth instance of the stub**: a socket fd in APE *is* the
`/net/tcp/n/data` file, `read()` goes straight to it with no wrapper in
this library, so there is no point at which a later read could be made
to return 0. There is nothing to intercept and nothing in the kernel to
ask.

`socket-server-test.c` section 3 is `chan-io-28.7` in C -- write,
`shutdown(SHUT_WR)`, then `select()` with a two-second timeout on the
server half -- and **the assertion is on the EOF, not on the write**.
The data arrives whatever `shutdown` does, so a test that only looked
for `Hey` would have passed on the stub. It also checks that the
descriptor survives `SHUT_RDWR`, which is the second bug. Every
assertion in it passes on glibc, which is how both it and the
replacement were checked.

#### Two other things chanio now reports

Newly reachable and recorded rather than chased:

- **`file link -symbolic` gives ENOSYS** (`chan-io-41.8`, and
  `chan-io-41.6`'s neighbours). `symlink()` is not implemented in libap.
  Whether it should be is a real question -- 9front's own file servers
  vary in whether they have symbolic links at all -- so this wants a
  probe before any code.
- The **`chan-io-6.4x` cluster is unchanged** (`6.31`, `6.43`..`6.47`,
  `8.1`): `-buffersize 16` with `testchannel inputbuffered` reporting 0
  where a partial buffer should remain. Nothing this round touched it,
  and it is still the oldest open item in this file.

#### chan-io-44.1, and the pipe is not the variable

`-singleproc 1 -file chanio.test -verbose t` named it in one run, as it
did for `chan-io-28.7` and `unixWm-50.5` before it. The log ends

```
---- chan-io-43.1 start
---- chan-io-43.2 start
---- chan-io-44.1 start
```

so the hang is **`chan-io-44.1`**. Nothing was guessed from what sits
after `41.8` this time, and it is as well: `42.1`..`43.2` all start
**and return**, so a guess from the log's last line would have been
wrong by six tests for the third time running.

```tcl
test chan-io-44.1 {FileEventProc procedure: normal read event} -setup {
    set f2 [open "|[list cat -u]" r+]
} -body {
    chan event $f2 readable {set x [chan gets $f2]; chan event $f2 readable {}}
    chan puts $f2 text; chan flush $f2
    vwait x
}
```

**THE PIPE AND `cat -u` ARE BOTH KNOWN GOOD, and that is what makes
this narrow.** `chan-io-29.26` opens the **same** bidirectional
`cat -u` pipe, writes a line and reads it back with a blocking
`chan gets` -- and it **passes**. So `open "|cat -u" r+` works, the
child runs, the write arrives and the data comes back. The single
difference at `44.1` is that the read is driven by a **readable
fileevent** instead of a blocking read.

So the question is whether Tcl's notifier ever reports a *pipe* as
readable here, and the useful control is that it demonstrably reports a
**socket**: the whole `chan-io-28.x` block fires fileevents on sockets
and every one of them starts and returns. Those are two different bugs
-- "the notifier is broken" and "the notifier does not watch pipes" --
wanting two different fixes, and the suite alone cannot separate them.

`sys/lib/tests/tcl-fileevent-test.tcl` does, in four sections: the
blocking pipe round trip (`29.26`, the control that must pass before
anything else means anything), the same pipe under a readable
fileevent (`44.1`), the same thing on a loopback socket, and on a plain
file. **Every section carries its own timeout** and reports `TIMEOUT`
rather than waiting -- which is the one thing tcltest cannot do, and
the reason a single wedged test there costs 155 files. All four pass on
a Linux tclsh, which is how the expectations were checked; the brace
quoting in `ok {$got eq "x"}` was wrong on the first run and the host
caught it, as the convention says it should.

#### A Tcl list on an rc command line is not a Tcl list

The command written here last round to skip `chanio.test` without an
edit was

```
tcltest .../tcl-runall.tcl -notfile {l.*.test chanio.test}
```

and it does not work, because **`{}` in rc is a brace block, not a
quoting construct**. rc split it, tcltest got `chanio.test}` as its own
word, and refused the lot:

```
unknown option chanio.test}: should be one of -asidefromdir, ...
tcl-runall: exit called (code 1)
```

The marker did its job again -- `exit called (code 1)` rather than a
run that read as finished. The spelling that works quotes it for rc so
that **one** argument reaches Tcl, which then parses it as a list:

```
tcltest .../tcl-runall.tcl -notfile 'l.*.test chanio.test'
```

Worth recording as a class, because this tree writes a lot of Tcl and
runs all of it from rc: **a Tcl list literal has to survive the shell
first, and rc's metacharacters are not sh's.** `{}` is a block, `()` is
a list, and only `''` quotes. The same trap is waiting for any
`-constraints`, `-match` or `-skip` argument with a space in it.

#### The reproducer passed, so the diagnosis above is REFUTED

`tcl-fileevent-test.tcl` reports **0 failures on the VM**. All four
sections pass, including section 2 -- the readable fileevent on a
`|cat -u` pipe that `chan-io-44.1` is built from.

So the prediction written for it ("section 2 times out, sections 3 and
4 pass, 9front's notifier does not watch pipes") was **wrong in every
part**, and the question it was asked to settle is still open. The
reasoning is kept above rather than edited away, because the *method*
was right and produced a clean refutation in one run: 29.26 really does
prove the pipe works, 28.x really does prove the notifier reports
sockets, and the thing left over really was worth isolating. What it
got wrong is that the isolation is not faithful.

**Two sections were added for exactly the ways it is not faithful**,
and they are the next thing to read:

- **5a/5b: a non-blocking poll against a blocking wait.** Section 2
  enters the event loop with `vwait`, which **blocks**. The suite's
  `event-1.1` enters it with `testfilehandler oneevent`, which is
  `Tcl_DoOneEvent(TCL_FILE_EVENTS|TCL_DONT_WAIT)` -- a **poll**. *A
  notifier that only learns about readiness on the path where it is
  about to sleep answers a blocking wait correctly and a poll not at
  all.* `update` is the Tcl-level `DONT_WAIT`, so 5a writes to a pipe,
  sleeps with `after` (which does not enter the loop), and then calls
  `update`. **If 5a fails and 5b passes, that is the bug and it is one
  function.**
- **6: `chan-io-44.1` character for character**, including the second
  `|cat -u` pipe its `-setup` opens and never uses, and the namespaced
  variable. Section 2 is 44.1 *simplified*, and it passes, so the
  difference is in what was simplified away -- which is the
  three-differences-at-once trap from `tk-mousewheel-test.tcl` met
  again. The second pipe is the obvious candidate and is now asked
  about directly.

All six pass on a Linux tclsh. The host caught two mistakes on the way
there, both of them Tcl quoting: `ok {$got eq "x"}` does not
substitute, and `step "...poll with [update]..."` **runs** `update`
inside the message. Neither would have been visible from the VM as
anything but a strange result.

#### The full run now reaches 32 files, and something regressed

With the quoting corrected, `-notfile 'l.*.test chanio.test'` works and
the run gets through **32 files** before stopping in `event.test`,
immediately after

```
==== event-1.1 Tcl_CreateFileHandler, reading FAILED
---- Result was:              {0 0} {0 0} {0 0}
---- Result should have been: {0 0} {1 0} {2 0}
```

**THAT IS EARLIER THAN THE 66-FILE RUN, AND EARLIER IS THE SIGNAL.**
The run that produced the 195-failure table reached `io.test`, far past
`event.test` alphabetically, and recorded `event` with **2** failures --
so `event.test` used to start, report and *return*. It does not now.
Something between those two runs made it stop, and the candidates are
this round's two behaviour changes (the `shutdown()` rewrite and the two
`_errno.c` entries) and one environment change (the loopback now
exists, which `event.test` has socket tests for).

**Do not pick between them by reading `event.test`.** The command that
names the test is the same one that has settled this five times:

```
tcltest .../tcl-runall.tcl -singleproc 1 -file event.test -verbose t
```

**What DID move, and it is real.** Comparing per file against the
195-failure table, over the 32 files both runs reached:

| file | 195-run | now |
|---|---|---|
| `cmdAH` | 12 | **0** |
| `chan` | 1 | **0** |
| `binary` | 2 | 2 |
| `clock` | 16 | 16 |
| `env` | 9 | 9 |

`chan-16.9` is the one that wanted `socket -server`, so the loopback
accounts for it. **`cmdAH`'s twelve are not explained** and are worth a
look before they are assumed to be the loopback as well -- twelve tests
moving with no attribution is the shape that has hidden a regression
elsewhere twice in this file.

**`event-1.1` is the same shape as `chan-io-44.1` and may be the same
bug**, which is why sections 5a/5b exist: a handler on a pipe that never
reports, where the pipe demonstrably carries the data. If 5a fails, the
two are one cause and the fix is in whichever path `DONT_WAIT` takes.

#### The hang is event-11.5, and event-1.1 was the wrong suspect

**`-singleproc 1 -file event.test -verbose t` named it, and it is not
the test that was failing.** The log runs `event-1.1`, `3.1`, the
fifteen `5.*`, `6.1`, the seven `7.*`, `8.1`, the four `9.*`, `10.1`,
`11.1`, `11.3`, `11.4` -- all of them **start and return** -- and ends

```
---- event-11.5 start
```

with nothing after it. So **`event-1.1` fails and returns**; it is
merely the last thing that *printed* in the multi-process log, because
that log is a pipe and block-buffered.

**That is the "a crash after test N is evidence about N" rule from the
Tk section, met in its other form**, and the section above walked into
it: 5a/5b were written on the reading that `event-1.1`'s
`Tcl_DoOneEvent(DONT_WAIT)` shape was the hang. It is not. Those two
sections are still worth having -- `event-1.1` is a real failure and
the poll/block distinction is a real question about this notifier --
but they were aimed at the wrong target, and the prediction attached to
them ("if 5a fails, the two are one cause") was answering a question
nobody had asked.

**`event-11.5` cannot finish if EITHER of its two sources is silent**,
which is what makes it a hang rather than a failure:

```tcl
fileevent $f1 writable {incr x; if {$y == 3} {set z done}}
fileevent $s2 readable {incr y; if {$x == 3} {set z done}}
vwait z
```

Neither handler can end the wait on its own -- **each tests the other
one's counter**. One live source and one dead one spins forever with no
error and no output; `vwait` has nothing to time out against.

**The two things it needs that nothing here had asked about are
WRITABLE and readable AT END OF FILE.** Sections 2, 3 and 4 cover
readable on a pipe, a socket and a file, and all three pass -- but
`$f1` is a plain file opened for *writing*, and `$s2` is a socket whose
server has already `close`d, so what must make it readable is the
**EOF** rather than data. `tcl-fileevent-test.tcl` sections 7a and 7b
ask those separately, because they fail separately.

**Section 8 is `event-11.5` itself with a timeout, and its verdict is
the two counters rather than the pass.** Each handler ends the wait
only when the other has reached 3, so whichever counter is stuck at
**0** names the source that never reported -- a timeout with one of
them climbing is already a complete diagnosis, and the script says
which in so many words. All eight sections pass on a Linux tclsh, where
section 8 reproduces the suite's own `3 3 done`.

**A note on what "writable" costs if it is the dead one.** A file open
for writing is *always* writable, so `fileevent writable` on it is the
cheapest event a notifier can be asked for; if that never fires, the
writable half of the notifier is missing outright, and every Tcl
program that drives an output channel from the event loop -- which is
how `http` posts a body and how any non-blocking write works -- is
affected, not just this test.

#### TWO BUGS IN select(), MEASURED -- and the prediction was half wrong

The run answers both questions and contradicts the half of the
prediction that was specific:

```
5a  FAIL  a readable pipe is reported to a non-blocking poll
5b  PASS  a readable pipe is reported to a blocking wait
7a  PASS  writable fileevent on a plain file fired
7b  FAIL  a closed peer reports readable          (TIMEOUT)
8         x (writable on the file)  = 2533503
          y (readable on the socket) = 0
```

**5a/5b came out exactly as predicted**: the notifier learns about
readiness only where it blocks. **7a and 8 did not.** The prediction
said "7a fails and 8 reports `x = 0`", i.e. the writable half is the
dead one. It is the *live* one -- `x` reached **two and a half
million** while `y` never moved at all, and 7b names what `y` was
waiting for.

**So `event-11.5` is not a fairness problem.** One source ran
2,533,503 times and the other zero times, and the test can only finish
when both reach 3. That is a dead source, and section 8's two counters
said so without anyone having to reason about scheduling.

**A third fact fell out of section 8 that nothing asked for**: its
*first* `vwait` -- plain readable on a socket the server had written to
-- also timed out, and reported so. Section 3 of the same file passes
the same shape. The difference is that section 3's server **stays
open** and section 8's writes and **closes at once**. So it is not
"readable on a socket" that is broken; it is *readable on a connection
whose peer has gone*, which is 7b again from the other side.

#### select() on Plan 9 is a copy process, and that is where to look

`ap/select/` holds only `poll.c`; **`select()` itself is in
`ap/plan9/_buf.c`**, and it is not a system call. It forks a **copy
process** per descriptor -- `_startbuf()`, on the first `select` that
names the fd -- which reads into a shared `Muxbuf`, and select then
answers from

```c
if(!err && (b->n > 0 || b->eof))
	n++;
```

rather than from the kernel.

**That design makes bug 1 nearly predictable.** With `t == 0` select
returns at the bottom of its first pass, which is *before the copy
process it has just forked can have run*. So the first poll on a
descriptor cannot report it ready, whatever is waiting on it.

**Bug 2 is NOT explained by reading that file, and that is the point.**
The copy process does `if(n <= 0) b->eof = 1;` -- which covers a read
*error* as well as a zero read -- and select counts `eof` as readable.
The code says it should work and the machine says it does not. **That
is exactly the position the announce spelling and the missing loopback
were in**, and both were settled by printing what the machine did
rather than by reading more code.

`sys/lib/tests/select-test.c` is that probe, in C, with no notifier, no
channel layer and no event loop in the way. Six sections, every one
correct on glibc, none able to hang (every `select` carries a
two-second timeout):

| | |
|---|---|
| 1 | a pipe with data, blocking -- the control |
| 2 | the same pipe, **zero-timeout poll** (5a in C) |
| 3 | **does a LATER poll see it?** |
| 4 | a socket whose peer wrote and closed (7b in C) |
| 5 | a socket whose peer closed having written **nothing** |
| 6 | writable on a plain file -- the other control |

**Section 3 is the one a fix turns on, and the Tcl test could not ask
it.** "Never ready to a poll" and "not ready to the *first* poll" want
completely different repairs, and `update` does not say how many times
it polled. If polls 2..10 report ready, the fix is about the first call
waiting for the copy process to exist; if none ever does, the copy
process is not the explanation at all.

**Section 5 splits bug 2 once more**, because the two shapes reach the
copy process differently: a peer that writes before closing gives it a
*successful* read followed by a failing one, and a peer that closes
having written nothing makes the very first read the one that ends the
stream. A fix for one need not be a fix for the other.

**What bug 1 costs if it is what it looks like.** Every
`Tcl_DoOneEvent(TCL_DONT_WAIT)` in every Tcl program -- which is what
`update` is, and what `testfilehandler oneevent` is, and what any
program polling its own event loop does -- gets "nothing is ready" on
the first look at any descriptor. `event-1.1`'s `{0 0} {0 0} {0 0}` is
that, exactly.

**What bug 2 costs.** *End of file must be readable* -- that is how
every program learns the other end went away, and a `read` answering 0
is the POSIX way to say so. A connection whose peer has closed and is
never reported readable is a program that waits for ever on a
conversation that is already over: `http` waiting for the end of a
response, any `-server` accepting a client that disconnects, and
`event-11.5`.

#### ONE BUG, NOT TWO: select() handles a closed peer correctly

**The probe ran, and it refuted more of the prediction than it
confirmed.**

```
1  PASS  a pipe with bytes in it is readable to a blocking select
2  FAIL  ... to a zero-timeout poll
3  FAIL  ten more polls, still not ready
4  PASS  a closed peer with data pending is readable   (read gave 7)
5  PASS  a closed peer with no data is readable        (read gave 0)
6  PASS  a file open for writing is writable
2 failure(s)
```

**Bug 1 is real and is in `select()`.** A zero-timeout poll does not
report a pipe that a blocking select on the same descriptor reports
immediately. That is `event-1.1`, `update`, and every
`Tcl_DoOneEvent(TCL_DONT_WAIT)` in every Tcl program.

**BUG 2 DOES NOT EXIST AT THIS LEVEL, and that is the useful half.**
Sections 4 and 5 both pass -- a connection whose peer has closed is
reported readable with data pending *and* with nothing written, and the
`read` that follows answers 7 and 0 exactly as POSIX requires. So
`_buf.c`'s `if(n <= 0) b->eof = 1;` does what reading it said it did,
and the code being right was not the illusion; **the Tcl-level 7b
failure is somewhere above `select()`**, which is a completely
different place to look and was worth one run to learn.

**Section 3's answer had to be thrown away, and it is my mistake rather
than the machine's.** It polled ten more times *back to back* and
printed **"NEVER, not merely late"**. Ten zero-timeout selects take
**microseconds**, and the polling process never yields -- so a copy
process that has only just been forked has not been scheduled either,
and the negative answer has a second explanation. **A check whose
negative result has two explanations is not a check**, which is the
"a check that cannot fail is not a check" rule in its other form, and
the third time this file has had to record it.

It is three cases now and they separate cleanly: **3a** the ten
immediate polls, kept for the record; **3b** a poll after `sleep(1)`,
so lateness is impossible; and **3c** the decisive one -- **a poll
immediately after a blocking select on the same descriptor has already
answered ready.** By then `b->n > 0` is a fact and the copy process
demonstrably exists, and the poll reads the identical test. If 3c still
fails, the copy process is not the explanation at all and no amount of
waiting for it would help.

**Sections 7 and 8 close the gap the run opened**, because every
descriptor in it behaves correctly *on its own* and Tcl's do not:

- **7 is the state section 4 skipped.** 4 selects once, finds seven
  bytes waiting, and reads them. Tcl's 7b then *drains the line and
  asks again* -- and with the data gone the only thing left to report
  is the end of file. Those are different fields (`b->n > 0` against
  `b->eof`) joined by one `||`, so they can come apart. Reading a
  passing section as covering the case after it is the
  `textDisp-6.5`/`6.6` mistake.
- **8 is `event-11.5` in C**, the two descriptors in the *same* select.
  Two things in `_buf.c` make the mixed set worth suspecting rather
  than assuming: the writable count is added to `n` **before** the read
  loop and the function returns as soon as `n` is nonzero, so **a
  select carrying any writable descriptor never blocks** -- it becomes
  a spin, `mux->selwait` is never set, and the copy process's wakeup
  path is never used; and a descriptor the read loop finds not ready is
  `FD_CLR`'d into `mux->rwant`, which the early return then discards.
  `x = 2533503` is exactly what a select that always returns at once
  looks like from Tcl.

**Both outcomes of 8 are worth having, which is the point of running
it.** `nread` at 0 while `nwrite` climbs reproduces the Tcl failure in
C and puts the fault in libap. **Both climbing exonerates `select()`**
and moves the question up to Tcl's notifier and channel layer -- a
result just as useful as the other, and the file says so in its own
output rather than leaving it to be inferred.

All eight sections are correct on glibc, where the extended file
reports 0 failures.

#### The poll is a FIRST-CALL race, and select() is now clear of event-11.5

**The extended probe answers both open questions, and the second answer
is the one that moves the work somewhere else entirely.**

```
2   FAIL  ... to a zero-timeout poll
3a  note  ten more immediate polls: still not ready
3b  PASS  a poll ONE SECOND LATER is ready
3c  PASS  a poll straight after a blocking select agrees
7   PASS  still readable once drained (the EOF), read answers 0
8   note  4 selects, writable 4 times, readable 3 times
    PASS  both sources were reported
1 failure(s)
```

**Bug 1 is a race with the copy process, exactly as reading `_buf.c`
predicted, and NOT "a poll never works".** 3b and 3c both pass: given a
second, or given that a blocking select has already answered on the
same descriptor, a zero-timeout poll reports it. So `_startbuf()` forks
the copy process and `select()` returns on the `t == 0` arm before that
process has been scheduled -- **the first poll on any descriptor cannot
report it, and every later one can.** That is one function's worth of
fix, and the "NEVER" the previous round printed would have sent it
looking somewhere else.

**And section 3a is why that round's conclusion was withdrawn**: the
ten back-to-back polls *still* report nothing, and they still prove
nothing, because they take microseconds. The same output line with
3b/3c beside it now means something; alone it meant nothing at all.

**SECTION 8 CLEARS `select()` OF `event-11.5`.** Four selects, writable
four times, readable **three** -- so the socket was missed once (the
first-call race) and reported every time after. Tcl's `x = 2533503`
with `y = 0` is therefore **not this call misbehaving**: libap reports
both sources, and a fix for bug 1 would only remove the one miss.

Section 8 also confirms the reading of the code beside it: with a
writable descriptor in the set, `n` is nonzero before the read loop and
`select` returns at once, so **it never blocks and `mux->selwait` is
never set**. Four iterations in the time C takes to count to four is
the same spin that gives Tcl two and a half million.

**`recv()` was checked and is not the gap.** `ap/network/send.c`'s
`recv` is `read(fd, a, n)`, and `unistd/read.c` is the **only** caller
of `_readbuf` in the whole library -- so Tcl's socket reads go through
the copy-process buffer like everything else. Worth a minute to check
rather than to assume; it was a plausible way for the copy process to
eat bytes Tcl never saw, and it is closed.

#### listen() replaces the fd with a PIPE, and select has never met one here

**Section 9 exists because C and Tcl still disagree and only one
structural difference is left.** Sections 4, 5, 7 and 8 all build their
loopback pair with a **blocking `accept()`**, so nothing in this file
had ever named a *listening* descriptor to `select()`. Tcl's
`socket -server` has no choice but to -- its accept is an event.

That is not a small difference on Plan 9. `ap/network/listen.c` does
not leave the socket's own file on the descriptor:

```c
/* replace fd with a pipe */
nfd = dup(fd);
dup2(pfd[0], fd);
```

with the function's own comment reading **"this is all to make select
work"**. A forked listener process then opens `/net/tcp/n/listen`,
writes the new connection's **ctl file name** into the pipe, and waits
to `read` an `"OK"` back -- `accept()` supplies it. The descriptor
carries a **two-way handshake between two processes**.

Now put `select()` on it. `_startbuf()` forks a **copy process** that
sits in `_READ()` on that same pipe, so a third party is reading one
direction of someone else's handshake. It can work -- `accept()`'s own
read goes through `_readbuf` and so still sees the name, which is why
section 3 of the Tcl test, whose server stays open, passes. Whether it
keeps working when the accepted end is closed immediately is precisely
what 7b asks and what no C section had reproduced.

**This is a hypothesis and section 9 labels it as one.** The last three
rounds each had a confident mechanism that one printed intermediate
refuted, so the measurement is what counts: **fail and the fault is in
libap after all, with the listener pipe the place to look; pass and
libap is clear for every shape `event-11.5` uses, and the question
belongs to Tcl's notifier and channel layer.** Either answer ends the
search on this side, which is why it is worth a run.

All nine sections are correct on glibc, where the file reports 0
failures.

#### Section 9 passes, so libap is CLEAR -- and the one real bug is fixed

**`7b` end to end in C works.** The select-driven accept, the accept
after it, the data the closed peer left, the EOF after draining, and a
read answering 0 -- five assertions, all `PASS`. So the listener-pipe
hypothesis is **refuted**: a copy process forked onto the pipe
`listen()` puts on a listening descriptor does not break the handshake,
even when the accepted end is closed at once.

That was worth writing precisely because either answer ended the search
here, and this is the answer that ends it: **every shape `event-11.5`
uses behaves correctly in C.** Tcl's `y = 0` is above `select()`, and
the next place to look is Tcl's notifier and channel layer.

**Section 3a differed between the two runs, and that is the tell.**
Run 1: ten immediate polls, still nothing. Run 2: **"poll number 2
reported it ready"**. Same binary, same machine. A result that moves
between runs is a **race**, which is what 3b and 3c had already said
and what the withdrawn "NEVER" would have denied.

#### The fix: a poll cannot answer for a descriptor it has just buffered

`_startbuf` **already rendezvouses** with the copy process -- `select`
does not return until the child is running -- so fork and scheduling
latency were never the gap. What is left is the window between that
rendezvous and the child's **first `_READ` completing**. The scan below
then reads `b->n` and `b->eof` as zero and the `t == 0` arm returns at
once.

`waitfresh()` in `_buf.c` closes it: descriptors buffered **by this
call** are collected in an `fd_set`, and a zero-timeout select waits
for one of them to have something, in 1ms steps, up to 10ms -- 
returning the instant anything is ready.

**It is an approximation and the design leaves no alternative.** Plan 9
has no non-destructive way to ask whether a file has data -- which is
the entire reason `select()` here is a copy process rather than a
system call -- so a poll on a descriptor nothing has read yet cannot be
answered without giving that process a moment. Waiting for the first
read to *complete* would be exact and is not available: on an idle
descriptor that read blocks, and **a poll that blocks for ever is worse
than one that answers "not ready"**.

Two things keep the cost bounded, and both matter:

- **it is paid once per descriptor.** The fd is `FD_BUFFERED` from here
  on, so no later poll reaches this code at all. Tcl registers its
  channels once.
- **it returns the moment anything is ready**, so the common case is a
  single check and no sleep.

It sits *before* the `wfds` scan deliberately. A writable descriptor
makes `n` nonzero and returns immediately, which is exactly the shape
that starves `event-11.5`'s reader; waiting first means the first call
can be right rather than merely recovering on the second.

**CONFIRMED, and the prediction was right for once in every part.**

```
2  PASS a pipe with bytes in it is readable to a zero-timeout poll
3  note section 2 already passed, so there is nothing to ask
0 failure(s)
```

Section 3 going *silent* is the part worth noticing: it only runs when
2 fails, so the file reporting nothing there is the fix confirming
itself. Sections 1 and 4..9 are unchanged, so the wait costs nothing
elsewhere -- and section 8 still reports **both** sources, which is
what says the 10ms grace has not turned the mixed read/write set into
something slower or stranger.

**What this does NOT fix, restated so the next run is read correctly.**
Section 8 was already reporting both sources *before* this change, so
`event-11.5`'s `y = 0` was never this call. It should still hang. Tcl's
`event-1.1` is the one that should move, from `{0 0} {0 0} {0 0}` to
`{0 0} {1 0} {2 0}`, and `tcl-fileevent-test.tcl` section **5a** is the
same question one layer up. **7b and 8 should still fail**: they are
above `select()`, which is exactly what section 9 established.

No header changed, so the `HFILES` trap is not in play for this one.

#### event-11.5 NEVER ACCEPTS THE CONNECTION, and that is the whole of it

**Both predictions landed.** `tcl-fileevent-test.tcl` section **5a now
passes** -- the `update`/`DONT_WAIT` poll, which is the poll fix showing
itself one layer up -- and `event.test` under `-singleproc 1 -verbose t`
prints **no `==== event-1.1 FAILED`** at all, so `event-1.1` passes too.
The file still stops at `---- event-11.5 start`, and 7b and 8 still
fail with `x = 2751547`, `y = 0`.

**Then reading upstream's actual test answered it in one look**, which
is where this should have started:

```tcl
set s1 [socket -server accept -myaddr 127.0.0.1 0]
after 1000
set s2 [socket 127.0.0.1 [lindex [fconfigure $s1 -sockname] 2]]
close $s1
```

**THE ACCEPT SCRIPT NEVER RUNS.** An accept script only runs inside the
event loop; `after 1000` with no argument is a blocking sleep, not an
event loop, and `close $s1` follows the connect immediately. So the
server side never accepts, never writes `foobar`, and never closes --
and the test still expects `3 3 done`. **Upstream is relying on a
connection ABANDONED IN THE ACCEPT QUEUE becoming readable when the
listener goes.** On X11 the kernel resets it, and `select-test.c`
section 10 now says so in as many words on the build host:

```
--- 10. the listener closed with the connection NEVER ACCEPTED ---
  PASS a connection abandoned in the accept queue becomes readable
  note read answered -1 (Connection reset by peer)
```

**That is a completely different question from the one nine sections
have been answering.** "Is a closed peer readable" is YES, measured
four ways on the VM. "Is a connection nobody accepted readable once the
listener closes" had never been asked, in C or in Tcl, and it is the
only thing left that can produce `y = 0`.

**I got the correction backwards first, and the real test is what
caught it.** On seeing that section 3 waits for its accept and 7b/8 do
not, I rewrote 7b and 8 to wait -- and that made them *unfaithful*,
because upstream does not wait either. The sections are restored to
upstream's shape, and the waiting version is **section 7c**, a control
rather than a correction. The pair is the point: 7b failing while 7c
passes says the fault is the abandoned queue and not the close.

**A second, genuine bug in 7b, and the host caught it as the convention
says it should.** The handler asked `[eof $ch]` *without reading*, and
Tcl's `eof` reports whether a read has already hit the end, not whether
the peer has gone -- so it answered `data` both on the fire carrying the
line and on the fire carrying the end of file. The section failed with
`got 'data'` against a channel behaving perfectly. It drains and stays
registered now, which is section 7 of the C file in Tcl.

With both fixed the whole file reports **0 failures on a Linux tclsh**
-- 7b, 7c and 8 included, and section 8 reproduces upstream's own
`3 3 done`. Before this, section 8 could not have been trusted to mean
anything on the VM, since it passed on the host for the wrong reason.

**What the next VM run decides.** If section 10 fails and 7c passes,
`event-11.5` is fully explained: the port does not report an abandoned
accept-queue connection, and upstream's test needs it. That is then a
real question about what `ap/network/listen.c`'s listener process does
with a connection it has opened and never handed over -- it holds the
`/net/tcp` connection open in a separate process, so closing the
*pipe* the parent holds need not close the *connection* at all, which
would leave the client waiting on a peer that is still there.

**And that would make it the `XLoadFont` family again, in its widest
form yet**: a listener process that exits without closing what it
opened leaves a live connection nobody will ever serve.

#### CONFIRMED, and the listener process never exits at all

**Every prediction landed.** C section 10 **fails** and 1..9 are
unchanged; Tcl **7c passes and 7b fails**, with section 8 still
reporting `y = 0`. So `event-11.5` is explained: a connection abandoned
in the accept queue is never reported readable here, and upstream needs
it to be.

**The cause is one commented-out loop, and it is worse than "exits
without closing".** `listenproc` sets the child up like this:

```c
nfd = dup(fd);
dup2(pfd[0], fd);		/* the socket fd IS the pipe now */
...
/*	for(fd = 0; fd < 30; fd++)
		if(fd != nfd && fd != pfd[1])
			close(fd);/**/
```

That loop is **commented out**, so the listener process keeps a copy of
`fd` -- which is `pfd[0]`, *the end the parent uses*. A Plan 9 pipe
reports end of file to one end only when **every** copy of the other
end is shut, so the child's `read(pfd[1], ...)` could never return 0
however thoroughly the parent closed the listening socket.

So the listener does not merely fail to tidy up on the way out: **it
never gets out.** It stays blocked in that read holding `dfd`, a
connection it has already opened and nobody has accepted, and the peer
is never hung up. The client is left waiting on a conversation whose
other party is still there and will never speak -- which is exactly
`y = 0`, and exactly why `select()` was right to report nothing.

**`close(fd)` in the child is the fix**, with the dangling `dfd` closed
explicitly before `exit(0)` rather than left to exit -- exit runs
`atexit` handlers first, and a peer should not wait through them.

Only `fd` is closed. Closing every inherited descriptor would be
tidier, and a forked listener holding the parent's files open is a real
leak, but the commented-out version did it with a hardcoded
`for(fd = 0; fd < 30; fd++)` that both reused the parameter and guessed
at `OPEN_MAX`. That is a separate change wanting its own measurement.
**`nfd` must stay open regardless**: it is the announced socket, and
closing it withdraws the announcement.

**`_sock_data` closes `cfd` on every path**, checked rather than
assumed -- so the loop leaks no control file, and the only descriptor
needing care is `dfd`.

**Prediction:** `select-test` section 10 passes and reports a read of 0
or an error; nothing else moves. Tcl 7b joins 7c in passing, section 8
reports `3 3 done`, and **`event.test` gets past `event-11.5`** -- the
first time this file has predicted a hang clearing. What it reaches
next is unknown; `event.test` has never run to the end here.

**The wider prize, if this is right**: every `socket -server` whose
client goes away without being accepted has been leaking a blocked
process and a live connection for the life of the program, which is
`ioCmd`, `ioTrans`, `iogt` and `socket.test` -- four files no run has
ever reached.

#### C IS FIXED AND TCL GOT WORSE, which is a result and not a setback

**`select-test` reports 0 failures.** Section 10 passes, with
`read answered 0` -- the abandoned connection is hung up and reports a
clean end of file, where before it was never readable at all. At the
`select()` level the port now does the right thing in all ten shapes.

**And Tcl's 7b stopped failing and started FREEZING.** That is a change
in kind and has to be said plainly: before the `listen()` fix the
section reported `TIMEOUT`, and now nothing comes back. `event.test`
still stops at `event-11.5`, which is where it stopped before, so the
suite is no worse -- but the reproduction is, and the fix caused it.

**A freeze and a timeout are completely different evidence here**, and
the distinction is the whole value of the run. `waitfor` arms an
`after` timer, so a section that reports `TIMEOUT` proves the event
loop kept running and the source was merely silent. A section that
never comes back proves **the process is blocked in a call** and the
loop is never reached at all. So the fix turned a silent source into a
blocked one, and what blocks is new since the fix: the listener now
*exits* when the listening socket is closed, and the client now reaches
a real end of file. Only two statements are new, and they are one
printed line apart.

**A section cannot say which of its own statements blocked**, so the
upstream-shaped case now marks each with `at:` and the last line
printed is the answer -- `tk-scrollbar-hang-test.tcl`'s technique,
which is the only thing that has settled a question of this shape here
in one run.

**AND THE ORDER WAS WRONG, WHICH COST THE CONTROL.** The accepted-peer
case was 7c, *after* the upstream-shaped one -- so when that began to
freeze, the control never ran. This file's own header says every case
expected to return must come before every case expected to hang, and
`tk-mousewheel-test.tcl` already paid for that lesson once. The two are
swapped: **7b is the control now and 7c is upstream's shape.**

Both pass on a Linux tclsh, with the markers printing in order, so the
instrumentation itself is not what will hang.

#### `at: waitfor` -- and the listener was killing the parent's TIMER

**One line of output ended it.** 7c prints

```
at: socket -server
at: socket 127.0.0.1 (connect)
at: close $srv7 (the listener)
at: fileevent readable
at: waitfor
```

and stops. The handler markers never appear, so **`vwait` never
serviced its own 3000ms `after`** -- and a `vwait` that cannot reach
its own timer means `select()` did not come back, timeout or no
timeout.

`select()`'s blocking path ends in `_RENDEZVOUS(&mux->selwait, 0)`, and
exactly two things ever wake it: a copy process that has found
something, or **the timer process**. A copy process that reaches end of
file before the parent sets `selwait` simply `_exit(0)`s without waking
anyone, which is a lost wakeup the timer is there to cover. So a freeze
rather than a timeout says the timer is gone.

**It was, and I killed it.** `listenproc`'s child left through
`exit(0)`, which **runs the parent's inherited `atexit` handlers**. Of
the two `_buf.c` registers:

```c
_killmuxsid(void)      { if(_muxsid != -1 && (_mainpid == getpid() || ...)) ... }
_killtimerproc(void)   { if(timerpid > 0) kill(timerpid, SIGKILL); }
```

`_killmuxsid` is guarded by `_mainpid` and does nothing in a child.
**`_killtimerproc` is not**, and `timerpid` is inherited straight from
the parent -- so the listener process killed the parent's timer on its
way out. `timerpid` stays `> 0` afterwards, so `_resettimer()` goes on
signalling a corpse, and **every blocking `select()` that needs a
timeout from then on waits for ever.**

**The previous fix is what exposed it.** Before `close(fd)` the
listener never returned from its read and never reached `exit(0)` at
all, so the handler never ran. Making the process exit *correctly* is
what let it do this -- which is why 7c went from `TIMEOUT` to a freeze
while C, which does not depend on the timer in section 10, stayed
green. **A fix that makes a process reach code it never reached before
is a fix that can expose anything on that path**, and this file has now
met that twice: the errno table's effect on `bind()`'s fallback was the
same shape.

**`_copyproc` has always said `_exit(0)`**, two hundred lines away in
the same file, for exactly this reason. The listener says it now.

`_killtimerproc` also takes `_killmuxsid`'s guard. The `_exit` is the
real fix; the guard closes the class, so the next child that leaves
through `exit()` cannot repeat it.

**Prediction:** 7c stops freezing. Whether it then *passes* is a
separate question and I would not bet on it -- the lost wakeup above is
real, and the timer merely turns it back into a 3s `TIMEOUT`. So the
honest prediction is: **7c reports rather than hangs**, 7b and 8 are
unaffected, and `event.test` either clears `event-11.5` or fails it,
but does not sit there.

#### SOLVED: event.test runs to the end with ZERO failures

```
Tests ended at 2026-09-16 18:38:02 +0200
all.tcl:  Total 65  Passed 55  Skipped 10  Failed 0
Sourced 1 Test Files.
tcl-runall: every file ran, now entering exit (code 0)
```

**`event-11.5` clears, and so does everything after it.** `11.6`,
`11.7`, `11.8`, the four `12.*`, the six `13.*` and the five `14.*` had
**never run here** -- the file stopped at `11.5` in every run this
project has ever taken. Fifty-five tests pass, ten skip on
`nonPortable`, and **nothing fails**, where the last complete-enough
measurement recorded `event` with 2.

`tcl-fileevent-test.tcl` agrees, with 0 failures and 7c reporting
`an abandoned accept queue reports readable (got 'eof')` -- and section
8 giving `x = 3`, `y = 3`, `done`, which is upstream's own expected
result rather than an approximation of it.

**The prediction was deliberately hedged and the hedge was wrong in the
good direction.** It said "7c reports rather than hangs" and explicitly
declined to bet on it passing, because the lost wakeup in `select()`'s
rendezvous is real and the timer only converts it into a 3s `TIMEOUT`.
It passes. The lost wakeup evidently does not arise on this path --
worth remembering as an open hazard rather than a closed one, since
nothing here has measured it directly.

**Two real libap bugs, and the second was invisible until the first was
fixed.** They are worth reading as a pair, because the second is the
price of the first:

1. **`listenproc`'s child kept a copy of the parent's pipe end** --
   the closing loop was commented out -- so `read(pfd[1])` could never
   return 0, the listener never left its loop, and a connection it had
   accepted at the TCP level but never handed over was never hung up.
2. **It then left through `exit(0)`**, running the parent's inherited
   `atexit` handlers, of which `_killtimerproc` was **unguarded** --
   so the listener killed the parent's timer process, and every
   blocking `select()` needing a timeout afterwards waited for ever.

Neither could have been found from the other end. The first needed C to
say that an abandoned accept queue is never readable while every other
closed-peer shape is; the second needed the Tcl reproduction to change
from `TIMEOUT` to a **freeze**, and then one `at:` marker to say which
statement blocked.

**What this predicts for the rest of the suite, and it is the largest
claim this file has made.** Every `socket -server` whose client goes
away unaccepted was leaking a blocked process and a live connection for
the life of the program, and the timer went with the first one to exit.
That is not one test: `ioCmd`, `ioTrans`, `iogt` and `socket.test` are
four files **no run has ever reached**, and `chanio.test` and `io.test`
are the two that had to be skipped to measure anything at all. Both are
unskipped in the harness now.

So the next run is the whole suite with no arguments, and the honest
position is that **nothing is known about those six files** -- the
count will rise as they are measured for the first time, and that is
the "expect the failure count to rise" case, not a regression.

#### The child's buffering is settable, and that trap is closed

**`chanio.test` stops the full run again**, with the log's tail at
`chan-io-41.8` -- and that is a **LOWER BOUND**, for the fourth time.
`all.tcl` leaves `-singleproc` at 0, so each file is a child whose
stdout is a pipe, and up to a bufferful of a wedged child's output dies
with it. Guessing from the last line has been wrong by twenty tests and
by six; every answer has cost a second run with
`-singleproc 1 -file X -verbose t`.

**That was avoidable and is now avoided.** `RunAllTests` passes **every
non-default option** through to the child (`tcltest.tcl:2941`), and each
child evaluates `-load` with `uplevel 1 [loadScript]` (`:3042`) before
running anything. So the harness sets

```tcl
::tcltest::configure -load {
    catch {fconfigure stdout -buffering line}
    ...
}
```

and every child line-buffers itself, at the right moment, with no
wrapper process and no change to how files are run. It is tcltest's own
mechanism rather than a trick.

Two things to know about it:

- **the script must write NOTHING.** Anything a child prints on stderr
  during `-load` is reported by the parent as `Test file error: ...`
  -- measured, not assumed, by giving it a `puts` and watching the
  parent turn the line into an error. Every call is inside `catch` and
  silent.
- **if `-load` is ever wanted for its real purpose** -- loading the
  commands under test -- **append to it**, or the buffering goes and
  the trap comes back with nothing to say so. The harness only sets it
  when it is empty, so a caller who passes `-load` keeps theirs.

Checked on the host against a baseline run with no `-load`: identical
summary, same single pre-existing host failure, so the option is inert
apart from the buffering.

**This does not make the last line the hung test.** `-verbose t` is
still what prints a name as a test *starts*; what it does buy is that
everything a child actually wrote is in the log, so the last line is
the truth about what was reported rather than an artefact of a 4 KB
boundary. The `-singleproc 1 ... -verbose t` run is still the way to
name a hang, and is still one command.

#### chan-io-44.1 confirmed, and the reproducer of it PASSES

`-singleproc 1 -file chanio.test -verbose t` names it again, and the
`-load` line-buffering from the round before means the log is now a
faithful record rather than whatever fitted in a 4 KB pipe buffer:

```
---- chan-io-42.1 start ... ---- chan-io-43.2 start
---- chan-io-44.1 start
```

`41.8` (the `file link -symbolic` ENOSYS) fails **and returns**, and so
does everything through `43.2`. Nothing was guessed from the last line
this time, which is the fourth running.

**AND SECTION 6 OF `tcl-fileevent-test.tcl` IS chan-io-44.1 CHARACTER
FOR CHARACTER -- the unused second `|cat -u` pipe, the namespaced
variable, all of it -- AND IT PASSES ON THE VM.** So the test is not
the variable. What differs is everything the process did before it:
forty-three sections of `chanio.test`, several hundred channels opened
and closed, and at least one that leaked (`41.8`'s cleanup reports
`can not find channel named "file5"`).

**The next question is therefore "what accumulates", and `-match`
answers it with no rebuild and no edit**, narrowing from the end:

```
tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t -match 'chan-io-44.*'
```

If 44.1 passes there, it is accumulation and the bisect continues
(`'chan-io-4*'`, then `'chan-io-[34]*'`, ...). If it hangs with nothing
else in the process, the difference is tcltest's own environment rather
than the suite's history, and the standalone reproducer is what to
compare against.

#### -match 44 PASSES, so it really is accumulation

```
Running tests that match:  chan-io-44.*
---- chan-io-44.1 start ... ---- chan-io-44.5 start
all.tcl:  Total 779  Passed 5  Skipped 774  Failed 0
tcl-runall: every file ran, now entering exit (code 0)
```

**44.1 through 44.5 all run and all pass with nothing before them.**
Between that and section 6 of `tcl-fileevent-test.tcl` -- which is 44.1
character for character and also passes -- the test itself is now
excluded twice over. What hangs it is the state forty-three sections of
`chanio.test` leave behind.

**The blind bisect would be three or four more runs** (`'chan-io-4*'`,
then `'chan-io-[34]*'`, ...), and each one only halves a range. So the
next run asks *what* accumulates instead, and the first suspect is the
**descriptor number**, because there is a measured cliff at 96 and
nothing in this project had ever crossed it -- see the section below.

**Section 9 of `tcl-fileevent-test.tcl` is a ramp, not one shot.** It
holds n descriptors open, runs 44.1, reports, releases them and climbs:
0, 40, 80, 88, 92, 96, 104. Each step prints an `at:` marker *before* it
runs, so if one never returns the last line names the threshold -- and
the script says in its own output which way to read it: a break
straddling 96 is the `fd_set`, and a break anywhere else says the
descriptor number was the wrong suspect and the accumulation is
something else. **Either answer is worth the run**, which is the test
this file keeps asking for.

A crash rather than a hang is no surprise there and is equally
informative: Tcl believes an `fd_set` holds 256 (see below), so its own
`FD_SET` on a high descriptor writes past the end of the struct before
libap is reached at all.

It is the **last** section in the file, because everything above it
returns and this is the only one written expecting that a case may not
-- the ordering rule this file has already paid for once. All seven
steps pass on a Linux tclsh, where `FD_SETSIZE` is 1024.

#### The system gives out descriptors select() cannot be asked about

Found by reading `_buf.c` and its headers while the above was waiting on
a run, so **it is not established to be the 44.1 hang** -- it is a real
bug found on the way past, and section 11 of `select-test.c` measures
it. `<sys/select.h>` is

```c
typedef struct fd_set { long fds_bits[3]; } fd_set;
#define FD_SETSIZE 96
```

-- **the struct is a hardcoded three words whatever `FD_SETSIZE` says**
-- while `<sys/limits.h>` sets `OPEN_MAX` to **256** and `_fdinfo[]` is
that long. Descriptors 96..255 are ordinary, usable descriptors that no
`fd_set` in the system can name.

Three things follow, and they get worse in order:

- **`FD_ANYSET` in `_buf.c` reads words 0..2 only.** A select naming
  only high descriptors takes the `/* no requested fds */` arm: it
  sleeps out the timeout and **returns 0**. A notifier waiting on such a
  descriptor waits for ever and is told nothing -- which is the shape of
  a `vwait` that never returns, and the reason this was worth writing
  down beside a hang.
- **A mixed set does reach the scan**, and then
  `FD_SET(fd, &mux->rwant)` writes past the end of a three-word `fd_set`
  **living inside the shared segment**. `rwant` is followed by `ewant`
  and then `bufs[]`, so it lands on another descriptor's buffer state.
- **`Muxbuf.fd` is a `char`** (`ap/include/lib.h`), so a descriptor is
  truncated to eight signed bits on the way into the slot: 128 and up
  read back negative, and **255 reads back as -1, which is that field's
  marker for a free slot**.

`FD_SETSIZE` is the number *callers* believe, and the callers here do
not agree with the header: `tcl/unix/tclUnixPort.h:461` says
`#ifdef OPEN_MAX / #define FD_SETSIZE OPEN_MAX`, so **Tcl thinks an
`fd_set` holds 256 and is handed one that holds 96.** Its own
`FD_SET` calls on a high descriptor smash Tcl's memory before libap is
reached at all.

**The assertion about `OPEN_MAX <= FD_SETSIZE` was written and then
withdrawn**, because glibc fails it too -- `FD_SETSIZE` 1024 against an
`RLIMIT_NOFILE` of 20000 -- so "every descriptor fits in an fd_set" is
not a library rule and a test must not claim it is. It is reported
instead. What glibc *does* guarantee, and this does not, is that an
`fd_set` really holds `FD_SETSIZE` descriptors, so a program that stays
under the limit is safe; that is the assertion section 11 keeps, plus
the runtime one -- dup a readable pipe end up to `FD_SETSIZE+4` and ask.
The set it uses is padded deliberately, since `FD_SET` on a plain
`fd_set` would smash the test's own stack, which is precisely what Tcl
already does.

**The fix is not batched with the measurement, and deliberately.**
Widening `fd_set` and changing `Muxbuf.fd` to an `int` both change the
layout of something shared -- one an ABI every binary in the tree has
compiled in, the other the mux segment -- so both want a full rebuild
and neither should be spent before the run says whether a high
descriptor is ever reached. Section 11 is one command and needs no
rebuild of libap at all.

#### A NUMBERED TEST SAYS FOR ITSELF WHETHER THE BUILD HAS THE CHANGE

`select-test` came back **0 failures** with sections 1..10 -- and
**section 11 was not in the output**, because the build was from a tree
without it. Sections 1..10 being green is a real result and worth
having (the port still does the right thing in all ten shapes it was
taught), but it says nothing whatever about the question that round was
asked.

**This is the third instance of "a measurement of a build that does not
contain the change measures nothing"** -- the window-table ramp test and
the `TESTCFLAGS` round are the other two, and both cost a reversal of a
correct decision. What is new is that the check here is free and needs
nothing but the output already in front of you: **these files number
their sections, so the highest number printed is the version of the
source that ran.** Read it before reading the verdict, exactly as
`git merge-base` is read before a suite result and the `tk-runall`
marker before a total.

The general form, since every test in `sys/lib/tests` is built by hand
on the machine under test: **when a run comes back green, ask what the
new case would have printed and look for it**, rather than taking the
count. A test that cannot run is indistinguishable from a test that
passes, if nothing names it.

#### FD_SETSIZE AND fd_set DISAGREED, AND IT WAS NOT STOCK APE'S

The run answered every question asked and the headline is one line:

```
--- 11. A DESCRIPTOR ABOVE FD_SETSIZE ---
  note FD_SETSIZE 96, fd_set holds 128, OPEN_MAX 256
```

**No file in this tree can produce that.** All three copies here --
`sys/include/ape/select.h`, `sys/include/ape/sys/select.h` and
`sys/include/ape/sys/types.h` -- are `long fds_bits[3]`, and `long` is
32 bits on amd64, so 96. The width came from somewhere else, and the
constant came from here.

**THE ARCHITECTURE-DIRECTORY EXPLANATION WAS WRONG, AND THE MARKER IS
WHAT SAID SO.** The obvious reading was the trap this file records
three times already -- `pcc.c:234-235` searches `/$objtype/include/ape`
first, stock APE keeps its own `sys/types.h` and `sys/select.h` there,
and `amd64/include/ape/` has no `sys/` directory, so stock's copies
would still be what a compile sees. That was written down as the
answer. `_APEXP_FD_SET_T` then reported

```
  note fd_set came from THIS TREE
```

-- so stock's header was never reached, and the whole paragraph was a
plausible mechanism refuted by one line of output, for the sixth time
in this file. **It was worth adding the marker precisely because the
arithmetic could not distinguish the two**, and the arithmetic is what
the explanation had rested on.

**The 128 is kencc's padding.** `long fds_bits[3]` is twelve bytes and
kencc rounds a struct up to an eight-byte multiple, so there was a
**fourth word of storage** that `FD_SETSIZE` denied, `FD_SET` could
write into, and `FD_ZERO` -- three assignments *by name* -- never
cleared. So every program in the tree sized its loops by 96 and
indexed an object of 128. And `_buf.c` made it a third number, because
its own

```c
/* assume FD_SETSIZE is 96 */
#define FD_ANYSET(p)	((p)->fds_bits[0] || (p)->fds_bits[1] || (p)->fds_bits[2])
```

is three words **by hand**, so descriptors 96..127 are inside the
struct, inside what Tcl believes, and invisible to the one test that
decides whether `select()` looks at the set at all.

**`_APEXP_FD_SET_T` is how the test says so**, defined beside the
typedef in all three copies here -- `limits-test.c`'s technique for
float/stdarg/stdint, and it answers outright instead of by arithmetic.
Section 11 prints which tree the struct came from, and it is the line
to read before anything else in that section.

**Two more things the same run settled, and one of them is a bug:**

- **`FD_ZERO` clears every byte** -- asserted now, against a struct
  pre-filled with `0xff`. This was the sharp risk of a split header:
  this tree's `FD_ZERO` is three assignments *by name*, so on a
  four-word struct it would leave the last word holding whatever the
  stack held, and a select would then act on descriptors nobody asked
  about. Not a missed event but an **invented** one. It passes, so the
  macros and the struct come from the same file and only `FD_SETSIZE`
  is ours.
- **`dup2` to a specific high number is refused.** The section
  reported `could not dup a descriptor up that high` for
  `FD_SETSIZE+4`, while Tcl's ramp held 104 descriptors in the same
  session without complaint (the kernel prints `warning: process
  exceeds 100 file descriptors` and carries on). So it is dup2 to a
  chosen number, not high numbers as such. Section 11 climbs with
  repeated `dup` now, which is also what a real program does, and
  prints the highest number it reached.

#### The descriptor number IS what chan-io-44.1 accumulates, at 128

**The ramp broke between 120 and 126 held.**

```
  PASS 44.1 with 120 held (got 'text')
  FAIL 44.1 with 126 held (got 'TIMEOUT')
```

The first seven steps (0..104) all passed, which is why the round
before this recorded the descriptor number as refuted -- the ramp
stopped at 104 and the struct ends at **128**, so every step had still
been inside it. Extending it two steps found the edge.

**AND THE SCRIPT'S OWN VERDICT READ IT WRONG, which is my mistake and
not the machine's.** It printed *"that is neither 96 nor 128, so the
descriptor NUMBER is the wrong suspect"* -- because it compared the
**held count** against those numbers as though a count were a
descriptor number. It is not: holding n descriptors puts the next one
at about n+4, and 44.1 opens **two** `|cat -u` pipes, so it needs about
four more on top. A break between 120 and 126 held is pipes landing at
roughly **124..134**, which straddles 128 exactly. The script computes
that span and names the boundary now.

**A test that draws its own conclusion has to do the arithmetic the
reader would**, or it reports a refutation where there is a
confirmation -- which is worse than printing the raw numbers and
saying nothing, because it is a wrong answer in the voice of a
measurement.

#### The fix: one fd_set, sized by FD_SETSIZE, and FD_SETSIZE >= OPEN_MAX

Three bugs, all measured above, all in the same two lines of header:

- **`FD_SETSIZE` was 96 and `OPEN_MAX` is 256.** Descriptors 96..255
  are ordinary and reachable -- section 11 climbed to **136** by
  repeated `dup`, with nothing worse than the kernel's `warning:
  process exceeds 100 file descriptors` -- and `select()` could not be
  asked about them. It did not say so either: it took the *"no
  requested fds"* arm, slept out the timeout and **returned 0**.
- **the struct was wider than the constant** (the padding above), so
  `FD_SET` on 96..127 wrote into a word `FD_ZERO` never cleared.
- **`Muxbuf.fd` was a `char`**, so 255 read back as **-1**, which is
  that field's own marker for a free slot.

`sys/include/ape/fdset_generic.h` holds it once now and
`<select.h>`, `<sys/select.h>`, `<sys/types.h>` and `<poll.h>` include
it -- `stdint_generic.h`'s arrangement, and for the same reason: there
were **four** independent copies of these constants, three of the
struct and one more of `FD_SETSIZE` alone, and none could reach another
by name because the search would find itself. `FD_SETSIZE` is 256 and
the array is `long fds_bits[(FD_SETSIZE + 31) / 32]`, so the two cannot
drift again.

**`FD_ZERO` is a function.** A macro clearing elements by name cannot
clear what it does not know about, which is exactly what went wrong; a
`sizeof`-based `do { } while(0)` would fix the clearing and **quietly
break every use as an expression**, which the comma-expression version
allowed. `__fd_zero` in `ap/select/fdzero.c` is one `memset` and stays
an expression.

`_buf.c`'s `FD_ANYSET` derives its width from the struct instead of the
hand-written three words, and `select()`'s early return can no longer
fire for a descriptor merely because it is high.

**THIS IS AN ABI CHANGE AND NEEDS `mk nuke` BEFORE `mk install`.**
`fd_set` grows, so every object that has one on its stack or in a
struct disagrees with every object that has not been rebuilt; and
`Muxbuf.fd` widening **moves every field below it** in the shared mux
segment. An incremental build gives exactly the shape this file already
records under `HFILES` -- logically inert changes followed by broad,
unattributable breakage -- and nothing in these mkfiles lists a system
header as a dependency, so mk will not do it for you.

Tcl needs no change and never did: `tcl/unix/tclUnixPort.h` already
says `#ifdef OPEN_MAX / #define FD_SETSIZE OPEN_MAX`, so it has been
asking for 256 all along and being handed 96.

**What the next run decides.** `select-test` section 11 should report
`FD_SETSIZE 256, fd_set holds 256`, `came from THIS TREE`, both
assertions passing, and a high descriptor reported readable.
`tcl-fileevent-test` section 9 should pass every step to 140. If both
do, the honest next question is whether `chanio.test` really reaches
~128 live descriptors by test 44 -- the ramp says *a* process at that
depth hangs 44.1, not that the suite's process is at that depth -- and
`-match 'chan-io-4*'` is still the bisect if it is not.

#### CONFIRMED: one fd_set, and the ramp clears every step

```
--- 11. A DESCRIPTOR ABOVE FD_SETSIZE ---
  note FD_SETSIZE 256, fd_set holds 256, OPEN_MAX 256
  note fd_set came from THIS TREE
  PASS fd_set is as wide as FD_SETSIZE claims
  PASS FD_ZERO clears every byte of an fd_set
```

and `tcl-fileevent-test` section 9 passes **every** step --
`0 40 80 88 92 96 104 120 126 130 140` -- where **126 timed out** before.
Both files report 0 failures. The constant and the struct agree, the
whole object clears, and `chan-io-44.1` survives a process holding 140
descriptors under it.

`mk distclean` before `mk install` was the right ask: `fd_set` grew and
`Muxbuf.fd` moved every field below it, and no mkfile here lists a
system header as a dependency.

**THE ONE RUNTIME CASE IN SECTION 11 DID NOT RUN, AND THE FILE STILL
SAID 0 FAILURES.** The last two lines were

```
  note highest descriptor reached: 255 (wanted 256)
  note could not climb that high; nothing to ask
```

**`OPEN_MAX` is a COUNT.** The highest descriptor is 255, the climb
asked for `>= 256`, and so it ran to the end of its table, `dup` failed,
and the section skipped the only question it exists to ask -- reporting
two passing assertions and a clean total. That is the *same shape* as
the round where section 11 was missing from the binary altogether: **a
green run whose interesting question never ran**, and this time nothing
even hinted at it except a `note` that reads like housekeeping.

It aims at `sysconf(_SC_OPEN_MAX) - 1` now and, more to the point,
**asks whatever it reached** rather than giving up -- there is no
outcome where the climb succeeds and the probe is skipped. The number
is printed either way, so the line that used to hide the skip is now
the line that proves it happened.

**The rule this file already has covers it and was not applied to my
own test**: *when a run comes back green, ask what the new case would
have printed and look for it.* A `note` is not a result. If a section
can decline to run, it must be impossible to read the output without
seeing that it did.

#### The fd_set was a real bug and was NOT the chan-io-44.1 hang

**`select-test` reports 0 failures with every section running**,
including the runtime probe that used to skip itself: `note highest
descriptor reached: 255 (wanted 255)` followed by `PASS a high
descriptor with data is reported readable`. So descriptor 255 -- the
number that used to read back as **-1** out of `Muxbuf.fd` -- is now
selected on and reported, measured rather than inferred.

**And `chanio.test` still freezes at `chan-io-44.1`.** The
`-singleproc 1 -verbose t` run names it again, with `41.8` (the `file
link -symbolic` ENOSYS) failing and returning as before.

**So the ramp reproduced a DIFFERENT hang from the one in the suite,
and the two were run together.** Section 9 broke between 120 and 126
descriptors held, which straddles 128 exactly, and it passes every step
to 140 now -- that is a genuine confirmation of a genuine fix, and it
was never evidence about `chanio.test`. The prediction written for it
said so in as many words: *"the ramp says **a** process at that depth
hangs 44.1, not that the suite's process is at that depth"*. The hedge
was right and the temptation to read the green ramp as the suite's
answer was exactly what it was written against.

**What the ramp cannot reach is one word: it HOLDS descriptors and
never SELECTS on them.** That is a bigger difference here than on any
other system. `select()` is `ap/plan9/_buf.c` and forks a **copy
process** per descriptor, so a descriptor that is merely open costs a
number, while a descriptor that has been named to `select` costs a
`Muxbuf` slot -- 16 KB of the shared segment -- a process, and an entry
in a table of `OPEN_MAX` slots that `_startbuf` linear-scans for a free
one. Every channel `chanio.test` drives through a fileevent pays that,
and nothing in section 9 pays it at all.

**Section 10 of `tcl-fileevent-test.tcl` pays it**: the same ramp, but
each held channel is a `|cat -u` pipe with a readable fileevent
registered and an `update` to make the notifier put it in a real select
set, so libap buffers it and forks its copy process. Nothing is written
to them, so each copy process sits blocked in its first `_READ`, which
is the steady state of an idle registered channel. It climbs
`0 4 8 16 24 32 40` and passes every step on a Linux tclsh.

**Both outcomes are written into the script before the run**, because
this is the third ramp in a row whose verdict was the thing most likely
to be got wrong: every step passing means buffered descriptors are not
the accumulation either and **that ends this line of attack**; a break
names a count of copy processes and Muxbuf slots, and the script says
outright that a count is **not** a descriptor number and must not be
compared against 96 or 128 -- which is precisely the arithmetic mistake
section 9's own verdict made once already.

**Run the bisect in the same round, because it is independent and needs
no rebuild:**

```
tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t -match 'chan-io-4*'
```

`-match 'chan-io-44.*'` already passes with nothing before it, so if
`'chan-io-4*'` hangs the accumulation is inside the `4x` block and the
range is forty tests rather than forty-three sections; if it passes,
widen (`'chan-io-[23]* chan-io-4*'`). **Quote it for rc** -- `{}` is a
brace block there, not quoting, and that mistake has already cost one
round.

#### The bisect landed: forty tests, and the neighbour is the suspect

**`-match 'chan-io-4*'` freezes at 44.1**, and section 10's buffered
ramp passes every step. So both ramps are now spent and both answered:

| | |
|---|---|
| section 9, descriptors merely **held** | passes to 140 |
| section 10, descriptors **buffered** (a copy process each) | passes to 40 |
| `-match 'chan-io-44.*'` | passes |
| `-match 'chan-io-4*'` | **freezes at 44.1** |

**Neither the descriptor number nor the buffered count is the
accumulation**, which is exactly what section 10 was written to be able
to say, and it says it in its own output rather than leaving it to be
inferred. What is left is the forty tests in the `4x` block, and that is
a far smaller thing than forty-three sections.

**THE FILE'S TOP-LEVEL CODE IS ALREADY EXCLUDED, and that is worth
stating because it is not obvious.** `-match` skips *tests*; tcltest
still evaluates everything between them. So `set f [open $path(foo) w+]`
at chanio.test:5570 -- the plain-file channel `42.x` and `43.x` drive --
runs under `-match 'chan-io-44.*'` too, and that run passes. The
variable is the **test bodies** in `4x`, not the file's own setup.

**`chan-io-43.2` is the nearest neighbour and is nearly 44.1 itself**,
which makes it the one to ask about first rather than bisecting blindly
from the far end:

```tcl
chan-io-43.2  -setup { set f2 [open "|[list cat -u]" r+]
                       set f3 [open "|[list cat -u]" r+] }
              ... chan event on $f, $f2, $f3, then all cleared ...
              -cleanup { catch {chan close $f2}; catch {chan close $f3} }

chan-io-44.1  -setup { set f2 [open "|[list cat -u]" r+]
                       set f3 [open "|[list cat -u]" r+] }
```

It opens **the same two `|cat -u` pipes**, registers readable events on
them, clears the events, and closes both -- and 44.1 then opens two more
which take the descriptor numbers just released. So the state 43.2 hands
over is: two descriptors freshly closed whose **copy processes were
blocked in `_READ`** rather than exited (nothing was ever written to
those pipes), and a `Muxbuf` slot freed for each.

**That is a reuse question, and `_buf.c` has a real race in it.**
`_closebuf` sets `b->fd = -1`, then kills `b->copypid` up to ten times
at 1ms intervals and gives up; it does **not** wait for the process to
be gone. A stale copy process that survives that window wakes up in

```c
n = _READ(fd, b->putnext, READMAX);
lock(&mux->lock);
if(b->fd != fd){ unlock(&mux->lock); _exit(0); }	/* "we've been closed" */
```

-- and that check is against the **fd number**, which the parent has by
then handed to a new pipe, into **the same slot** `_startbuf` reused.
`b->fd == fd` is true again for the wrong reason, and the slot has two
copy processes feeding it, with `b->copypid` naming only the newer one.

**This is a hypothesis and is labelled as one**; it is the seventh
mechanism this file has found plausible and the record for those is
poor. The difference is that it costs one `-match` to test, and the
answer is decisive either way:

```
tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t -match 'chan-io-43.2 chan-io-44.1'
```

**Freeze and the accumulation is ONE test wide**, with the reuse race
above the thing to read and `select-test.c` the place to reproduce it in
C. **Pass and 43.2 is innocent**, and the ladder continues backwards --
`'chan-io-43.* chan-io-44.*'`, then `42.*`, `41.*`, `40.*`, `4.*` added
in turn, stopping at the first freeze. Either way it is seconds, not a
rebuild.

`41.6` is the other thing in that range worth knowing about, since it is
a shape nothing here has ever selected on: it **opens a directory** and
registers a readable fileevent on it, so `_startbuf` forks a copy
process that `_READ`s a directory fd. And `41.8` reports
`can not find channel named "file5"` from its cleanup, which is **not** a
leaked channel: `file link -symbolic` fails with ENOSYS before `$chan`
is assigned, so the cleanup closes 41.6's already-closed channel. The
cleanup error is a consequence of the ENOSYS and not a second fault.

**`chan-io-40.3` is newly visible and is not ours.** It wants
`0o666` from `open {WRONLY CREAT}` and gets `0o644`, and the test's own
comment reads *"This test only works if your umask is 2, like
ouster's."* It carries a `umask` constraint, which is true here, so it
runs and fails on the umask rather than on anything in libap.

#### 43.2 is innocent, so halve rather than walk backwards

```
Running tests that match:  chan-io-43.2 chan-io-44.1
---- chan-io-43.2 start
---- chan-io-44.1 start
all.tcl:  Total 779  Passed 2  Skipped 777  Failed 0
```

**Both run, both pass, no freeze.** So the descriptor-reuse race written
up above is not armed by 43.2 alone -- the eighth plausible mechanism in
this file and the seventh to be refuted by one run. The race in
`_closebuf` is still real on its own terms (it kills up to ten times and
does not wait, and the stale copy process re-checks the fd **number**),
but it is not what 44.1 is waiting for, and it is not worth fixing on
the strength of a guess.

**Walking backwards one group at a time would cost five runs; halving
costs two.** The range before 44.1 is about thirty-four tests -- `4.*`
five, `40.*` sixteen, `41.*` eight, `42.*` three, `43.*` two -- so:

```
A   -match 'chan-io-4.* chan-io-40.* chan-io-44.*'
      freeze -> B1  -match 'chan-io-40.* chan-io-44.*'
                      freeze -> it is 40.*, split 40.1..40.8 / 40.10..40.16
                      pass   -> it is 4.*, five tests
      pass   -> B2  -match 'chan-io-41.* chan-io-44.*'
                      freeze -> it is 41.*, and 41.6 is the standout: it
                                selects on a DIRECTORY
                      pass   -> B3  -match 'chan-io-42.* chan-io-43.* chan-io-44.*'
```

Note `chan-io-4.*` matches `4.1`..`4.5` and **not** `44.1`: the dot is a
literal in a glob, so the group needs naming separately. That is the
whole reason `-match 'chan-io-4*'` caught everything.

**IF BOTH HALVES PASS AND THE WHOLE STILL FREEZES, THAT IS THE ANSWER
AND NOT A FAILED BISECT.** It means the thing is *cumulative* rather
than one test, and the count is what matters. This file has met exactly
that once before and misread it for a round: `tk-runall.tcl -file
'[a-m]*.test'` and `'[n-z]*.test'` both ran clean while the whole suite
crashed, and the window-table leak was the answer. So a bisect that
narrows to nothing is evidence, and the next move then is a prefix ramp
-- keep 44.1 fixed and add groups until it breaks -- rather than a
narrower `-match`.

#### It is chan-io-41.*, and that is eight tests of which two open anything

**One halving, and the answer is unambiguous:**

```
-match 'chan-io-4.* chan-io-40.* chan-io-44.*'   24 tests, finishes clean
-match 'chan-io-41.* chan-io-44.*'               FREEZES at 44.1
```

So everything that arms `chan-io-44.1` is inside `chan-io-41.*`, and the
run before it is worth reading as well: **44.1 through 44.5 all ran and
passed after twenty-four of the `4.x`/`40.x` tests**, so the `4x` block
is not merely innocent of the freeze -- it leaves the process able to
run the whole `44` group.

**Five of the eight open nothing.** `41.1`..`41.5` are argument-error
checks -- `chan event foo`, `chan event gorp readable` -- and `41.7` is
skipped on `specialfiles`. That leaves two:

- **`41.6` OPENS A DIRECTORY AND SELECTS ON IT.** `set chan [open
  $tempdir]`, a readable `chan event`, then `vwait`. That is a shape
  nothing in this port has ever been asked for: `_startbuf` forks a copy
  process that sits in `_READ` on a **directory** descriptor, which on
  Plan 9 returns stat entries and then end of file.
- **`41.8` fails before it opens anything.** `file link -symbolic` is
  ENOSYS, so `$chan` is never assigned and the cleanup closes 41.6's
  already-closed channel -- which is the whole of `can not find channel
  named "file5"`. It leaks nothing, and that error is a consequence of
  the ENOSYS rather than a second fault.

**"A PRIOR `vwait` IS ENOUGH" WAS THE TEMPTING READING AND THIS FILE
ALREADY REFUTES IT.** The passing half contains no `vwait` at all -- the
`4.x` translation tests and the `40.x` open-mode tests never enter the
event loop -- so 44.1's was the first blocking select in that process,
while in the freezing half 41.6's came first. Very neat, and wrong:
**sections 9 and 10 call `run441` eighteen times between them and every
call passes**, so 44.1 after a previous 44.1 demonstrably works. Worth
writing down because believing it would have cost a run, and because it
is the first time in this file that an existing test refuted a new
hypothesis without anything being run at all.

**Section 11 of `tcl-fileevent-test.tcl` is 41.6 and 41.8 standalone**,
with `run441` as a control before them and after each: make a directory,
open it, register a readable event, wait, close, then run 44.1; then
attempt a symbolic link and run 44.1 again. Every statement carries an
`at:` marker, because this is the section most likely to find a freeze
and a freeze cannot say which line it is in. All three steps pass on a
Linux tclsh, where `open` on a directory succeeds and `file link
-symbolic` works -- so the host exercises the machinery and only the VM
can answer the question.

**Two runs, and they are independent of each other:**

```
tclsh sys/lib/tests/tcl-fileevent-test.tcl
tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t -match 'chan-io-41.6 chan-io-44.1'
```

The first reproduces it with no suite at all if the directory is the
cause; the second says whether 41.6 alone is enough inside tcltest. If
11b freezes, the reproducer is **four lines** and the next step is to
write it in C in `select-test.c` -- select on a directory descriptor,
close it, then select on a fresh pipe -- which is where every one of
these has ended up being settled. If 11b passes and 11c passes but the
suite still freezes on `41.6 + 44.1`, then it is the pair or the
`tempdir` machinery around them, and `41.8 + 44.1` is the next `-match`.

#### FOUND: a reused Muxbuf slot inherited a rendezvous nobody would answer

**The two singles pass and the group freezes**, which is the cumulative
case this file predicted one round earlier and is worth reading as the
answer rather than a failed bisect:

```
-match 'chan-io-41.6 chan-io-44.1'   passes    (the directory)
-match 'chan-io-41.8 chan-io-44.1'   passes    (the failed symlink)
-match 'chan-io-41.*  chan-io-44.*'  FREEZES
```

Sections 11b and 11c reproduce both singles standalone and both pass, so
neither is it.

**41.7 IS THE ONE, AND IT HAD BEEN WRITTEN OFF AS SKIPPED.** The whole
of section 11 was built on "five of the eight open nothing and 41.7 is
skipped on `specialfiles`", which is three tests written off by reading
a constraint line instead of the log. **tcltest prints `---- NAME start`
at `tcltest.tcl:2070`, after the `Skipped` check returns at `:2032`**,
so a skipped test never prints it -- and `chan-io-40.9` proves the rule
in the same output, being in the file, `nonPortable` here, and absent
from a run that counted exactly one skip and jumped 40.8 -> 40.10. In
the freezing run **41.7 printed `start`**. It ran. It opened
`/dev/zero`.

**One line of the log I already had, read three rounds late.** The rule
this file states about constraint lines -- *check the constraint before
reading a failure* -- has a converse that was missing: **a constraint
says what a test needs, not whether it ran, and the log says which.**

#### /dev/zero is the one source that never ends and never pauses

Every other descriptor anything here has selected on either **ends** (a
directory, a plain file, a closed peer) or **stays silent** (a `|cat -u`
pipe nobody writes to). `/dev/zero` does neither, and that is the whole
difference: its copy process fills the 16 KB `Muxbuf` faster than
anything drains it, so it reaches

```c
/* _copyproc, making sure there's room */
b->roomwait = 1;
unlock(&mux->lock);
_RENDEZVOUS(&b->roomwait, 0);
```

41.7's `vwait` fired on the first fill long before that, the test
returned, and `close $chan` sent `_closebuf` to SIGKILL the copy process
**exactly where it was waiting**. And `_startbuf`'s slot reset was

```c
Found:
	b->n = 0;
	b->putnext = b->data;
	b->getnext = b->data;
	b->eof = 0;
	b->fd = fd;		/* roomwait and datawait NOT cleared */
```

**`roomwait` and `datawait` are rendezvous flags, and the next
descriptor into that slot inherited one.** Both are addresses handed to
`_RENDEZVOUS`, so a stale flag is not a wrong answer but a **permanent
wait**, in whichever process reads it first:

| | |
|---|---|
| stale `roomwait` | `_readbuf` drains, sees it, clears it and rendezvouses to wake a copy process that no longer exists -- **the parent blocks for ever, inside `read()`** |
| stale `datawait` | `_copyproc` reads, sees it, clears it and rendezvouses instead of waking the selecting parent -- **the copy process blocks for ever and `select()` is never woken** |

`chan-io-44.1` is `chan puts $f2 text; chan flush $f2; vwait x`, and a
`vwait` with no timer calls `select` with a NULL timeout. Either mode is
a freeze with nothing to interrupt it.

**The fix is two assignments**, in `_buf.c`'s `Found:`, with the reasoning
beside them. The general rule it is an instance of: **when a struct is
recycled, reset every field that means something, not the ones that
happen to be about the data.** Four of six were reset and the two left
out were the two that name a sleeping process.

**Why nothing here had caught it.** Section 9's ramp holds descriptors
without selecting on them; section 10's buffers forty of them but writes
to none, so no buffer ever fills and `roomwait` is never set; `43.2`
opens two `|cat -u` pipes and writes nothing. Every reproducer so far
was silent by construction, and **the bug needs a source loud enough to
fill 16 KB**. That is why eighteen `run441` calls in sections 9 and 10
all passed while the suite froze.

**Section 12 of `tcl-fileevent-test.tcl` is 41.7 then 44.1**, with
`run441` as the control in front. The `after 200` in it is load-bearing
rather than decoration: the copy process has to get from "first read
delivered" to "buffer full, `roomwait` set" before the close, or the
reproducer reproduces nothing. It is last in the file because it is the
only case expected to freeze on an unfixed libap. 0 failures on a Linux
tclsh, where there is no copy process and it passes trivially.

**Prediction, and the order matters.** On the **current** binary,
`-match 'chan-io-41.7 chan-io-44.1'` freezes and section 12b freezes --
run both of those *before* rebuilding, because they are the confirmation
and they cost nothing. After `mk install` (no `distclean` needed: no
header, no struct layout, one file of `libap`) both pass, sections 1..11
are unchanged, and `chanio.test` gets past 44.1 for the first time.
What it reaches after that is unknown -- nothing has ever run beyond
`chan-io-44.1` here.

**If 12b passes on the unfixed binary**, the mechanism is wrong and the
fix is still right on its own terms; the next thing to ask is which
*other* test in `41.*` fills a buffer, since the group freeze is a fact
whatever explains it.

#### CONFIRMED, before and after, and every part of it landed

**On the unfixed binary both froze, at exactly the marked statement:**

```
    at: close /dev/zero
    at: 44.1 after /dev/zero was selected on and closed
					<- nothing, section 12b

---- chan-io-41.7 start
---- chan-io-44.1 start
					<- nothing, -match 41.7 + 44.1
```

**On the rebuilt one both pass**, with sections 1..11 unchanged and
`0 failure(s)`:

```
  PASS 44.1 after /dev/zero (got 'text')
all.tcl:  Total 779  Passed 2  Skipped 777  Failed 0
```

**That is a genuine before-and-after on one pair of binaries**, which
this file has not had before: every earlier fix was confirmed by a
result moving, and this one was confirmed by the *same two commands*
freezing and then not. The `at:` marker naming `44.1 after /dev/zero`
rather than the close is what says the stale flag was consumed by the
next descriptor and not by the dying one.

**The prediction landed in every part** -- which test, which mechanism,
which statement, and both sides of the rebuild. Worth recording plainly
because the honest tally in this file runs the other way: this is the
eighth mechanism written down in the `chan-io-44.1` chase and the first
that survived contact.

**And it was found by reading the log rather than the code.** Three
rounds went into `41.6` (a directory) and `41.8` (a failed symlink) on
the strength of "41.7 is skipped on `specialfiles`", which was read off
the constraint line. The `---- chan-io-41.7 start` in the log had been
there the whole time. The rule to carry: **a constraint says what a test
needs; only the log says whether it ran.**

**Two libap bugs in `_buf.c` now, found from opposite ends**, and both
were a rendezvous with no partner:

1. the listener's child killed the parent's timer through an inherited
   `atexit` handler, so every blocking `select()` needing a timeout
   waited for ever;
2. a recycled `Muxbuf` slot inherited `roomwait`/`datawait`, so the
   descriptor that took it over waited on a process that had died
   before the slot was freed.

**What to run next, and nothing is known about any of it.**
`chanio.test` has never run past `chan-io-44.1` in this project, so the
whole-file run is the first measurement of everything after it:

```
tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t
tcltest .../tcl-runall.tcl
```

The second is the whole suite with `chanio.test` and `io.test` both
unskipped, and `ioCmd`, `ioTrans`, `iogt` and `socket.test` are four
files **no run has ever reached**. Expect the failure count to rise as
they are measured for the first time; that is the "newly measured, not
newly broken" case, and it is the fourth time this file has had to say
so.

#### chanio.test FINISHES, and 779 tests are measured for the first time

```
Tests ended at 2026-09-17 10:55:51 +0200
all.tcl:  Total 779  Passed 743  Skipped 16  Failed 20
Sourced 1 Test Files.
tcl-runall: every file ran, now entering exit (code 0)
```

**`chan-io-44.1` clears and so does everything after it**, which is
`44.2` through `73.1` -- roughly six hundred tests that **no run in this
project has ever reached**, the file having stopped at 44.1 or earlier
every time. 743 pass, 16 skip on constraints (`asyncPipeChan` 3,
`emptyTest` 8, `extensive`, `nonPortable`, `thread`, `win` 2), and 20
fail. The marker prints, so the total is the file's own rather than a
prefix.

**Read the 20 per test before anything else**, and the names are not in
the screenshot -- the run needs repeating with the log kept:

```sh
grep '^==== ' /tmp/chanio.out | grep ' FAILED$' | sed 's/^==== //; s/ FAILED$//'
```

The `chan-io-6.4x` cluster (`-buffersize 16`, `testchannel
inputbuffered` reporting 0) and `41.8` (`file link -symbolic`, ENOSYS)
are known and account for about eight of them. **The rest have never
been seen**, so nothing about them should be assumed from this file's
older lists.

#### And the whole suite froze in chanio.test, where the file alone does not

The suite run stops with `chan-io-53.7` as the last thing reported, and
`grep -c FAILED` halved gives **22** -- which is about 20 from
`chanio.test` plus `binary.test`'s two Inf tests, so the child had
reported *every* failure the standalone run reports before it wedged.
The freeze is therefore **after 53.7**, with `53.8`, `53.8a`, `53.9`,
`53.10`, `54.*`, `55.1`, `56.1`, `57.*`, `58.1`, `59.1`, `60.1`, `61.1`,
`70.*` and `73.1` still to come -- all of which the standalone run
completed.

**THE ONE DIFFERENCE IS `-singleproc`, AND IT MOVES THE QUESTION TO A
SECOND PROCESS.** The run that finishes is
`-singleproc 1 -file chanio.test -verbose t`: one process, sourcing the
file. The suite leaves `-singleproc` at 0, so `chanio.test` runs in a
**fresh child** whose stdout is a **pipe** the parent reads with a
blocking `gets`.

**So "the child hung" and "the parent hung" are different answers and
the log cannot tell them apart.** That distinction is new here and is
worth stating before any mechanism is proposed:

- **the child** is a fresh `tcltest` with no accumulated state, which is
  the opposite of everything the last six rounds have been chasing;
- **the parent** has been running since `append.test`, has opened and
  drained a pipe per file, and every one of those pipes is a **loud**
  source -- a child flooding its own test output is exactly the shape
  that fills a 16 KB `Muxbuf` and sets `roomwait`, which is the flag the
  round before this one was about.

`53.7` being the last thing reported is suggestive rather than
evidence -- it is `CopyData: Flooding chan copy from pipe`, a grandchild
writing 3450 bytes in 345 chunks at 10ms with `-buffering none`, driven
by `fcopy` through the event loop. But **a crash or freeze after test N
is evidence about N only if nothing between N and the stop could have
armed it**, and `-verbose t` was not on for the suite run, so 53.7 is
merely the last *report* and not necessarily the last test started.

**One run settles which process and names the test**, and it is the
missing cell of the table:

```
tcltest .../tcl-runall.tcl -file chanio.test -verbose t
```

**No `-singleproc 1`.** That runs `chanio.test` in a child exactly as
the suite does, with one file instead of a hundred and sixty-seven and
with the names printed:

| | |
|---|---|
| **it freezes** | multi-process mode alone reproduces it, with a fresh child and nothing before it. The last `start` names the test, and the two-process pair is the whole reproducer. |
| **it finishes** | the child is fine in isolation, so it is the **parent's** accumulated state -- a hundred and sixty pipes' worth -- and the next question is which files before `chanio.test` are needed, which `-file` takes as a list. |

Either answer is worth the run, and neither is available from the log
that exists.

#### It is chan-io-73.1, the LAST test -- and 53.7 never meant anything

```
tcltest .../tcl-runall.tcl -file chanio.test -verbose t     (no -singleproc)
---- chan-io-73.1 start
                          <- nothing
```

**Multi-process mode alone reproduces it**, with a fresh child, one file
and nothing before it -- so the child's accumulated state is the whole
story and the parent's hundred and sixty pipes are not needed. That was
the question the run was for, and it is answered.

**AND MY READING OF THE SUITE LOG LAST ROUND WAS WRONG.** It said the
freeze was "after 53.7", because `chan-io-53.7` was the last thing the
log printed. **Without `-verbose t`, tcltest prints only FAILURES** --
so 53.7 was merely the last *failure*, and everything after it was
passing silently. The suite run had almost certainly reached 73.1 too.
There is **one** freeze here, not two, and the arithmetic that made the
two look different (22 failures = chanio's 20 + binary's 2) was right
about the count and wrong about what it implied.

That is the fourth time in this file the last line of a log has been
over-read, and it is a new variant worth naming: the earlier three were
**buffering** -- the last line was stale. This one was **verbosity**:
the last line was current and was not the last *test*. `-verbose t` is
what makes "last printed" mean "last started", and a log without it
cannot be read for position at all.

**73.1 CANNOT BLOCK.** It is two lines:

```tcl
test chan-io-73.1 {channel Tcl_Obj SetChannelFromAny} -body {
    chan close [lreplace [list a] 0 end]
} -returnCodes error -match glob -result *
```

`chan close {}` raises an error and that is the expected result. So the
freeze is in what comes **after** it, which is the file's own trailing
cleanup -- `removeFile` thirteen times, `cleanupTests`, `namespace
delete` -- and then the child exiting and the parent seeing end of file
on the pipe.

**So the remaining question is which of two processes, and `ps` answers
it outright.** While it is frozen, on the VM:

```
ps | grep -v Pread
```

A live `cat`, `tcltest` or stray child names the holder directly, and
Plan 9's `ps` shows the state -- `Pread` for something blocked in a
read. This is the most direct evidence available and costs nothing.

**`_timerproc` and `_copyproc` are both cleared, checked rather than
assumed.** Each closes **every** descriptor it does not need:

```c
for(i=0; i<OPEN_MAX; i++)		/* _timerproc */
	_CLOSE(i);
for(i=0; i<OPEN_MAX; i++)		/* _copyproc, via _startbuf */
	if(i!=fd && (_fdinfo[i].flags&FD_ISOPEN))
		_CLOSE(i);
```

so neither holds the child's stdout, and the `listenproc` shape does
not repeat through them. What is left is the test file's own children:
`chanio.test` runs `exec ... &` and `openpipe ... &` in several places,
and a background child that inherited descriptor 1 and is still alive
keeps the parent's `gets` from ever seeing end of file.

**A two-step ladder settles child-versus-parent with no harness at
all**, by running the child exactly as the parent does and changing only
what its stdout is:

```
tcltest $home/APExp/sys/src/external/tcl/tests/chanio.test -verbose t
tcltest $home/APExp/sys/src/external/tcl/tests/chanio.test -verbose t | cat
```

| | |
|---|---|
| **first finishes, second freezes** | the child completes and the **pipe** is the variable: something still holds the write end, so the reader never sees EOF. That is the `listenproc` shape a third time, and `ps` names the process. |
| **both freeze** | the child cannot finish as a standalone `tcltest`, which `-singleproc 1` never is, and the teardown after 73.1 is where to look. |
| **both finish** | it needs the tcltest parent specifically, and the pipe is not enough on its own. |

Note the first command is the child's real command line -- the parent
builds `| $shell $file $childargv` (`tcltest.tcl:2940`) -- so it is not
an approximation of what the suite does, it is the same thing with the
pipe removed.

#### ps names it: TWENTY-FIVE leftover processes, every one blocked in open()

**The child finishes and the harness does not.** The first rung of the
ladder was run and it is unambiguous:

```
tcltest .../tests/chanio.test -verbose t                    finishes
tcltest .../tcl-runall.tcl -file chanio.test -verbose t     freezes at 73.1
```

The second is the same file in a **child** with its stdout on a pipe.
So the test file itself completes, and what does not complete is the
pair: child exits, parent never sees end of file.

**And `ps | grep -v Pread` during the freeze names the holder.** The
useful part of it is one shape repeated twenty-five times:

```
glenda 1785 0:00 0:00  7264K Open      tcltest
glenda 1791 0:00 0:00  7924K Open      tcltest
...                            (25 of them, 7264K..9496K)
glenda 2335 0:00 0:00     0K Wakeme    closeproc
glenda 2407 0:00 0:00     0K Queueing  closeproc
```

Four things to read out of that, and only the last is a guess:

- **There is no `cat` and no `rc` left over.** The test file's
  `|cat -u` children and its `exec ... &` children have all gone. So
  the "a background child inherited descriptor 1" theory written in the
  section above is **refuted**: the leftovers are `tcltest` itself.
- **Twenty-five processes of 7-9.5 MB are forked copies of the child**,
  and the sizes climb with the pid, which is the heap growing through
  the run. Nothing execs -- an exec would have renamed them.
- **The harness parent is not in the listing**, because it is in
  `Pread`, which is what `grep -v` removed: blocked in its `gets` on
  the pipe, exactly as predicted.
- **`Open` is a psstate, not a scheduler state.** Plan 9 sets
  `up->psstate` for the duration of a syscall and `ps` prints it in
  preference to the scheduler state, so these twenty-five are blocked
  **inside an `open()`** -- and they will still print `Open` if the
  thing they are blocked on is a qlock. The two kernel `closeproc`
  procs, one of them `Queueing`, are the kernel's own asynchronous
  channel-close helpers and are consistent with a pile-up.

**So the mechanism is: leftover forked processes hold a copy of the
child's descriptor 1.** A Plan 9 pipe reports end of file only when
*every* copy of the write end is shut, which is the `listenproc` shape
for the third time in this file -- and it explains both rows of the
ladder at once. Standalone, stdout is the console and nobody is waiting
for EOF, so the same leftovers cost nothing and the run "finishes".

**Which forked processes?** libap forks in exactly two places here, and
both close what they do not need (checked above, and unchanged):
`_timerproc` closes every descriptor, and `_copyproc` closes every
descriptor but its own. But **a copy process that is blocked in `open()`
has not reached that loop yet** -- and there is one `open()` on the way
to everything in libap, because `kill()` is implemented as one:

```c
/* ap/signal/kill.c */
sprintf(pname, fmt, pid);		/* "/proc/%d/note" */
f = open(pname, O_WRONLY);
```

and `_closebuf` calls it in a loop:

```c
for(i=0; i<10 && kill(b->copypid, SIGKILL)==0; i++)
	_SLEEP(1);
```

so **every channel close in the file is up to ten opens of a dying
process's note file**, and `chanio.test` closes hundreds of channels.
`kill(pid, 0)` opens it too -- the `sig == 0` arm skips the *write*, not
the open.

**That is the ninth mechanism written down in this chase and the record
for these is one in eight, so it is labelled and not acted on.** Three
measurements settle it, all cheap, none needing a rebuild, and the
first two have to be taken *while it is frozen*:

1. **`acid <pid>` then `lstk()`** on one of the stuck processes. This is
   not the interactive-acid trap the Tk notes warn about -- `tcltest` is
   not a graphical program, so nothing fights it for the rio window --
   and it names the blocked function outright instead of by inference.
   If acid itself hangs attaching, that is an answer too: the target's
   debug qlock is what is jammed.
2. **`cat /proc/<pid>/fd`** on two or three of them. It prints the
   working directory and then one line per descriptor with its path, so
   it says directly whether these processes hold the pipe -- which is
   the whole claim above.
3. **Kill just the leftovers and watch the parent.** If the harness
   immediately prints its summary, the freeze *is* the held write end
   and nothing else:

```
for(i in `{ps | awk '$6=="Open" && $7=="tcltest" {print $2}'})
	echo kill > /proc/$i/ctl
```

   Do not use `slay tcltest`: it would kill the parent too, and a
   harness that dies gives the shell prompt back exactly as one that
   finishes does -- the discriminator this file has already been caught
   by four times.

The remaining rung of the ladder is still worth one command, since it
needs nothing frozen and no `/proc`:

```
tcltest .../tests/chanio.test -verbose t | cat
```

If that freezes, the pipe alone reproduces it with no tcltest parent at
all, and the reproducer is two processes instead of a hundred and
sixty-seven files.

#### A skip list is not a substitute for a timeout

Two files skipped so far, one per round, each found by running the
suite and seeing where it stopped. That is a round trip per hang, and
`ioCmd`/`ioTrans`/`iogt` may well be three more. **tcltest has no
timeout anywhere**, so there is no cheaper way inside it; the only
lever is to fix the cause rather than enumerate the symptoms, which is
the argument for doing the socket work next rather than skipping
onward.

**`-notfile` is applied after `-file`, and the harness got that wrong.**
Asking for exactly the file the skip list skips gave

```
Only running test files that match:  chanio.test
Error: No test files remain after applying your match and skip patterns!
all.tcl:  Total 0  Passed 0  Skipped 0  Failed 0
```

-- the "run the hanging file on its own" recipe defeated by the
convenience default meant for the whole-suite run. The harness no
longer adds its skips when the caller passed `-file`: a caller who
names files has said what they want.

Note the marker **still printed "every file ran"** there, and was not
wrong to: every file that matched did run, all zero of them. **A marker
says the run reached the end, not that the run was the one you asked
for.** The `Total 0` line is what says that, and it is worth reading
beside the marker rather than instead of it.

#### acid named it in one call: the leftovers are listener processes

**`lstk()` on one of the twenty-five is the whole answer**, and it took
one command rather than another round of mechanism-guessing:

```
_OPEN(a0=0x7fffffde620)+0xe            ap/syscall/_OPEN.s:6
open(flags=..., path=...)+0x29e        ap/fcntl/open.c:60
listenproc(r=0xee2580, fd=0x7)+0x1e4   ap/network/listen.c:135
listen(fd=0x7)+0x1cb                   ap/network/listen.c:232
Tcl_OpenTcpServerEx(...)+0x530         tcl/unix/tclUnixSock.c:1818
Tcl_SocketObjCmd(...)                  tcl/generic/tclIOCmd.c:1718
```

so every one of them is **`listenproc`, blocked in
`cfd = open(listen, O_RDWR)`** -- the Plan 9 listener waiting for a call
that in these tests never comes. `socket -server` forks one of these per
server, and `chanio.test` creates a great many.

**Closing the socket cannot end that wait.** The `read(pfd[1])` further
down is what notices a closed pipe, and this process is not at it; it is
one statement earlier and will stay there for ever. So each leftover sat
holding **a copy of descriptor 1**, which in a tcltest child is the pipe
the parent reads results from -- and a Plan 9 pipe reports end of file
only when *every* copy of the other end is shut. The parent's `gets`
never returned. Standalone the same processes leak and nothing notices,
because a terminal has nobody waiting for end of file on stdout, which
is exactly the two rows of the ladder.

**THE FIX WAS ALREADY WRITTEN DOWN HERE AS DEFERRED.** The comment in
`listenproc` said, in as many words:

> Only `fd` is closed. Closing every other inherited descriptor would be
> tidier -- a forked listener holding the parent's files open is a real
> leak -- but ... that is a separate change wanting its own measurement.

The measurement is this stack. The child now closes every inherited
descriptor except the two it needs -- `nfd`, the announced socket, whose
closing would withdraw the announcement, and `pfd[1]`, the end it talks
to `accept()` over -- with `OPEN_MAX` and `_fdinfo[i].flags & FD_ISOPEN`
rather than the hardcoded `for(fd = 0; fd < 30; fd++)` that was commented
out there, which both guessed at the limit and reused the parameter.

**`_CLOSE`, not `close`, and that is not a style choice.** APE's
`close()` calls `_closebuf` on a buffered descriptor, which SIGKILLs a
copy process belonging to the **parent**. `_copyproc` closes its
inherited descriptors with `_CLOSE` for precisely this reason, and the
single `close(fd)` that was there before this change is a latent instance
of it -- safe today only because the listener is forked before Tcl ever
selects on that descriptor. `open()` rewrites `_fdinfo[n].flags`
wholesale, so skipping close()'s bookkeeping strands nothing.

**This is the `listenproc` shape for the third time**, and all three are
one sentence: *a forked child holding something the parent's reader is
waiting on.* First the pipe end, so the listener never left its loop;
then the parent's timer, through an inherited `atexit` handler; now every
other inherited descriptor, chiefly stdout.

**Prediction.** `mk install` (one file of libap, no header, no struct
layout, so no `distclean`) and then:

- `tcltest .../tcl-runall.tcl -file chanio.test -verbose t` -- **no
  `-singleproc`** -- finishes and prints the summary, where it froze at
  `chan-io-73.1`;
- the whole suite gets past `chanio.test` into `clock.test` and beyond,
  and `ioCmd`, `ioTrans`, `iogt` and `socket.test` are measured for the
  first time. Expect the failure count to rise: newly measured, not newly
  broken, for the fifth time in these notes.

**And `ps` should still show leftover listeners**, because this fixes the
descriptors and not the processes: a `socket -server` closed with no
connection still leaves a `listenproc` blocked in that `open()` for ever.
Nothing records the listener's pid, so `close()` cannot kill it today.
That is the next change if it matters, and **whether it matters is
readable off the same `ps`** -- which is why the prediction says to look.
If the freeze does *not* clear, the descriptors were not the whole of it
and the leftover processes are, and that is where to go.

#### CONFIRMED, and the run reaches the 167th file of 167

**`chanio.test` passes through the harness now**, multi-process and all,
where it froze at `chan-io-73.1` before. The stack from the new freeze
proves the fix is in the build without a `git merge-base`: the frames
read `listen.c:159` and `listen.c:256`, which are the line numbers *after*
the comment this change added -- they were 135 and 232 before it.

**And the whole suite now runs to `zlib.test`, which is the last file
alphabetically of the 167.** From twelve files, to thirty-two, to
sixty-six, to all of them. Every one of `ioCmd`, `ioTrans`, `iogt`,
`socket.test` and `io.test` has been measured for the first time on the
way past. `grep -c FAILED` halved gives about **185** failing tests,
which is the first whole-suite number this project has ever had, and it
is a floor: `zlib.test`'s own tail is missing.

**The freeze is `zlib-8.3`, and the stack names it without a second
run.** `lstk()` gives `Tcl_FSEvalFileEx` with `numBytes=0x99f6` and
`TclEvalEx` with `line=0xe5`:

```
39414 bytes  ->  zlib.test, exactly, of the 167
line 229     ->  zlib-8.3 {zlib transformation and fileevent}
```

which opens

```tcl
set srv [socket -myaddr localhost -server {apply {{c a p} {
    fconfigure $c -translation binary -buffering none -blocking 0
    puts -nonewline $c [zlib gzip [string repeat a 81920]]
    close $c
}}} 0]
```

**A byte count and a line number in a backtrace name a test file
outright**, which is worth remembering: `wc -c` over the test directory
has exactly one match at 39414, and it cost one command rather than a
run.

**`localhost` is not the difference**: `socket.test` uses that name 132
times and the run got past it. What is unusual about `zlib-8.3` is the
*shape* -- an accept script that writes 80 KB non-blocking and closes at
once, read back through `zlib push gunzip` and `fcopy`, with the server
and the client in the same process.

**AND THE LISTENER BLOCKED IN `open()` IS NOW NORMAL.** That is exactly
what a Plan 9 listener does while no call has arrived, and `zlib-8.3` has
a live `socket -server` at the moment of the freeze, so one of them is
*expected*. It was pathological last round because there were
twenty-five of them, left over from servers long closed, holding
descriptors. Do not spend another `acid` on it.

The two processes visible in that `ps` are both libap's own helper forks
and both are healthy:

| | |
|---|---|
| `Open` | the listener, `listen.c:159`, waiting for a call |
| `Sleep` | almost certainly the **timer process**, `_buf.c:607`, `_SLEEP(mux->waittime)` -- a fork, hence the near-identical size |

so the screenshot does not contain the blocked process at all; it was cut
off above. **The next `ps` needs to be unfiltered and whole.**

**The round, and it is small.** `zlib.test` alone is a reproducer of
minutes rather than hours:

```
tcltest .../tcl-runall.tcl -file zlib.test -verbose t
```

Predicted last line `---- zlib-8.3 start`. While it is frozen, `ps` in
full, and `acid` on the `tcltest` that is **neither** the listener nor
the timer -- that is the one with something to say.

**And read the log that already exists**, which needs nothing frozen and
is the first whole-suite accounting:

```sh
tail -40 /tmp/tcl-all.out
grep '^==== ' /tmp/tcl-all.out | grep ' FAILED$' |
	sed 's/^==== //; s/-[0-9].*//' | sort | uniq -c | sort -rn
```

The second is the per-file table. **Read that before reading 185 as a
number**: one file dominating a count and saying nothing about the tree
has happened twice already here, `http11`'s 86 and `testobjconfig`'s 215.

#### It is zlib-9.2, and a forked child's backtrace dates from its FORK

**`-file zlib.test -verbose t` stops at `---- zlib-9.2 start`**, not
8.3. The prediction of 8.3 was wrong, and the reason is worth more than
the correction:

**`lstk()` on a process forked by `listenproc` shows where it was
BORN, not where anything is now.** That listener's stack ends in
`Tcl_OpenTcpServerEx` because that is the call that forked it, and it
has been sitting in one `open()` ever since. `zlib-8.3` is where that
particular listener was created; the process that forked it went on to
run 8.4, 9.1 and 9.2 and froze there. A live listener's stack is a
timestamp, not a position.

**`zlib-9.2` ends in a BLOCKING `fcopy` with no timer at all:**

```tcl
after 1000 {set ::total timeout}
vwait ::total			;# the accept script sets ::total -1
after cancel {set ::total timeout}
set total [fcopy $sin [set fout [open $file wb]]]
```

So the handshake completes -- the `vwait` returns, or the test would
report `timeout` rather than hang -- and then the synchronous `fcopy`
reads until end of file with nothing to interrupt it. A channel that
never reports EOF is a permanent block, in a **`read()`**, so the frozen
process is in `Pread` and `grep -v Pread` hides exactly the one worth
looking at.

**80 KB through a 16 KB `Muxbuf` is new here.** Every earlier reproducer
was a line or two, or `/dev/zero` filling the buffer once before being
closed. This is the first thing in the project to make `_copyproc` set
`roomwait`, block, be woken by `_readbuf`, and go round again --
repeatedly, under a select-driven reader. The lost wakeup already
recorded as an unmeasured hazard lives on exactly that path. **Labelled
as a hypothesis**; the two backtraces below settle it.

**Which process to `acid`:**

```
ps | grep tcltest | grep -v Open
```

`Open` is the listeners, and there are now more than a hundred of them
left over from every frozen run since 1785 -- see below. Of what is
left, `Sleep` is the timer process (`_buf.c:607`) and the **newest pid**
is the one running the test. If a `Rendez` tcltest appears beside it,
that is the copy process, and the pair is the answer: reader waiting in
`_RENDEZVOUS(&b->datawait)` while the copy process waits in
`_RENDEZVOUS(&b->roomwait)` is a deadlock with both halves visible.

**TWO PROCESSES ARE IN STATE `Broken`** -- 6185 and 6196, 5 MB each. A
Plan 9 process is `Broken` because it **faulted** and was held rather
than killed, so those are two crashes that no run ever reported. `acid
6185` then `lstk()` prints the faulting stack, and it costs nothing:
they are already dead and waiting.

**And the leak is now measured rather than predicted.** The listener
processes are not merely lingering, they are *accumulating across runs*:
pid 1785 in this listing is the same 1785 from the previous round's
screenshot, hours earlier. Over a hundred of them, each holding `nfd` --
an announced TCP socket -- for a server that was closed long ago. The
descriptor fix stopped them wedging the harness; nothing stops them
existing. The change is to record the listener's pid in the `Rock` and
have `close()` kill it, and this listing is the argument for doing it.

#### The listener is waiting for accept()'s "OK" -- and 9597 is the one to read

**"Acid the newest pid" was wrong advice**, and the ps says why: the
listener is forked *by* the test process, so it always has the **higher**
pid. The four `tcltest` processes of a frozen `zlib.test` run are

```
9588  5832K Pread   the harness parent, blocked on the child's pipe
9597 23604K Pread   the test process          <- THIS ONE
9603 23444K Sleep   the timer process, _buf.c:607
9606 23588K Pread   a listener                <- the one acid'd
```

Size does not separate 9597 from 9606 either, both being forks of the
same 23 MB image. **Read the stack, or read both.**

**What 9606 says is still worth having.** It is not in `open(listen)`
where an idle listener sits; it is at `listen.c:170`:

```c
write(pfd[1], nr->ctl, strlen(nr->ctl));	/* done */
read(pfd[1], name, sizeof(name));		/* HERE */
```

-- the second half of the handover. It has taken a call, opened the
connection, written the control file's name into the pipe, and is
waiting for `accept()` to answer `"OK"` (`accept.c`, after
`_sock_data` succeeds). **So a connection was delivered to the parent
and the parent never completed the handshake**, and the listener will
hold that connection open for ever.

`noblock=0` and the frame being `_PREAD` rather than `_readbuf` also
says the descriptor is neither buffered nor non-blocking, which is
`read.c:29` -- worth knowing, because a *buffered* read blocks in
`_RENDEZVOUS` and shows as `Rendez`, not `Pread`. **The state column
already distinguishes those two waits.**

**What 9597's stack decides.** Two readings are left and they want
different fixes:

- **inside `accept()`, at `read(fd, name, ...)`** -- then the two
  processes are deadlocked over the same pipe, the parent waiting for a
  name the listener has already written, and the question is who
  swallowed it: a copy process forked by `select()` on that same
  descriptor is the obvious candidate, and `_readbuf` is then not
  returning what it holds.
- **inside `fcopy`/`Tcl_Read` on `$sin`** -- then the accept completed,
  the 80 KB data channel never reports end of file, and 9606 is a
  *second* thing to explain rather than the same one.

#### TWO BUGS, AND THE FREEZE IS THAT dup() PICKED A DESCRIPTOR IT DID NOT OWN

**`acid 9597` ended it.** The test process is not in `fcopy` and not in
`accept`. It is here:

```
_PREAD(a0=0x7)                 ap/syscall/_PREAD.s:6
_NSEC()                        ap/plan9/9nsec.c:35
gettimeofday                   ap/time/gettimeofday.c:13
NativeGetTime / GetTime / Tcl_GetTime     tclUnixTime.c
Tcl_AfterObjCmd(ms=0x3e8)      tclTimer.c:869
```

`ms=0x3e8` is **1000**, so the script is executing `zlib-9.2`'s
`after 1000 {set ::total timeout}` -- past the client connect, before
the `vwait`. It never reaches the event loop, which is why the listener
in the other process is still holding a call nobody accepted, and why
the 1000 ms timer that should have rescued the test never armed.

**And it is blocked reading `/dev/bintime`.** That file cannot block.
So descriptor 7 is not `/dev/bintime` any more:

```c
/* plan9/9nsec.c, and the static is the whole problem */
static int fd = -1;
if(fd < 0)
    fd = _OPEN("/dev/bintime", OREAD|OCEXEC);
_PREAD(fd, b, sizeof b, 0);
```

`_OPEN` is the **raw syscall**, so `_fdinfo[7]` never learns the
descriptor exists -- and `fcntl(F_DUPFD)` chose its slot from that
table:

```c
for(i = (arg>0)? arg : 0; i<OPEN_MAX; i++)
    if(!(_fdinfo[i].flags&FD_ISOPEN))
        break;
ans = _DUP(fd, i);        /* SILENTLY CLOSES whatever is really there */
```

`dup()` *is* `fcntl(F_DUPFD, 0)`, and `listen()` opens with
`nfd = dup(fd)`. **The listener's own frame reports `nfd=0x7`** -- the
same descriptor `_NSEC` is reading, in the same frozen run. One
descriptor, two owners, and the evidence for both halves was in the two
backtraces already taken.

Afterwards the parent closes `nfd`, something else takes 7, and every
timestamp in the process reads a pipe or a socket. A read of those does
not return.

**The fix is that the KERNEL picks the descriptor.** `_DUP(fd, -1)`
returns the lowest genuinely free one, which cannot collide with
anything; POSIX wants the lowest free `>= arg`, so anything below `arg`
is held and released afterwards. That closes the class rather than the
instance: any raw-`_OPEN` descriptor anywhere in libap was exposed to
this, and `F_DUPFD` was the only place APE chose a descriptor number
out of its own table instead of the kernel's.

Covered by `sys/lib/tests/dup-fdinfo-test.c` -- 0 failures on glibc,
with `alarm()` round the case under test, because the failure mode is a
read that never returns and a test that hangs reports nothing.

#### The `Broken` pair: `file copy` of a directory faults, every time

`acid 6185` on one of the two held faults:

```
_dirtostat            ap/plan9/dirtostat.c:14
stat / lstat
fts_stat(p=..., follow=0) ap/misc/fts.c:829   <- sbp=0x0
fts_open                  ap/misc/fts.c:133
TraverseUnixTree          tclUnixFCmd.c:1057
TclpObjCopyDirectory / Tcl_FSCopyDirectory / CopyRenameOneFile
```

and `fts_alloc` says why in two lines:

```c
	if (!ISSET(FTS_NOSTAT))
//		len += sizeof(struct stat) + ALIGNBYTES;
	if ((p = malloc(len)) == NULL)
		return (NULL);
```

**An `if` whose body is commented out swallows the next statement.** So
`if (!ISSET(FTS_NOSTAT))` came to govern the `malloc` -- with
FTS_NOSTAT set, `p` was never assigned at all -- and the second
commented line made the other `if` govern the `memcpy` of the name.
Either way `fts_statp` was never set and `memset` had left it **NULL**,
so `fts_stat` handed NULL to `lstat` and `_dirtostat` wrote through it.
`tclUnixFCmd.c` passes `FTS_PHYSICAL|FTS_NOCHDIR`, so the stat buffer
really is required.

**Why nobody had seen it: a Plan 9 process that faults is HELD, not
killed.** The crash waits in `ps` as state `Broken` and prints nothing,
so `file copy` and `file rename` of a directory have been faulting for
as long as `fts.c` has been here and every run reported it as a plain
test failure or not at all. **Read the state column for `Broken` after
any suite run**; it is free evidence and it had been sitting there.

**And the reason those lines were commented out rather than fixed is
probably the macro above them**, which is upstream's:

```c
#define ALIGN(p) (((unsigned long int) (p) + ALIGNBYTES) & ~ALIGNBYTES)
```

`unsigned long` is **32 bits** on amd64 kencc, so that truncates every
pointer and would have produced a `fts_statp` pointing at nothing --
faulting differently rather than not at all. It is `uintptr_t` now.
Commenting out the two lines turned a wrong pointer into a null one,
which is the same bug wearing a quieter symptom.

#### Both fixes land, and the next failure is a SPIN rather than a block

`dup-fdinfo-test` reports **0 failures** on the VM, and `zlib.test`
finishes:

```
all.tcl:  Total 73  Passed 72  Skipped 1  Failed 0
tcl-runall: every file ran, now entering exit (code 0)
```

-- the file that froze the last two runs, now clean end to end with one
`knownBug` skip. So `_NSEC` keeps its clock and the whole
`zlib-8.x`/`9.x` block, which had never been reached, passes.

**The full suite stops again, and this one is a different animal:
HIGH CPU, and the log stops growing at 95076 bytes.** Every hang in this
project so far has been a *block* -- constant light load, a process
waiting on something that will never arrive. This is the other shape,
and the Tk notes' rule applies: **a pinned core is a loop, and the two
want completely different fixes.** Keep them apart from the first
minute; the last time they were run together it cost several rounds.

**Three cheap measurements, in this order:**

1. **`tail -20 /tmp/tcl-all.out`.** `runAllTests` echoes each test
   file's name as it starts it, *independently of `-verbose`*, so the
   last name in the log is the file that is spinning. This is the one
   piece of position information a suite log gives without `-verbose t`,
   and it is at file granularity rather than test.
2. **`ps | grep tcltest` twice, a few seconds apart.** A spin is the one
   case where the CPU-time columns identify the culprit outright: the
   process whose time is *climbing* is the one in the loop, and every
   other one is a bystander. That is cheaper than any backtrace.
3. **`acid <that pid>` and `lstk()` TWICE.** Two samples separate the
   two kinds of spin: **identical frames** mean a loop inside one call,
   and **frames that move** mean a loop through the event loop, an event
   regenerated as fast as it is drained. Tk had one of each and they
   were fixed in completely different places.

Then the usual reproducer on whichever file (1) names:

```
tcltest .../tcl-runall.tcl -file <that>.test -verbose t
```

**`fCmd.test` is worth reading in the same log whatever happens**, since
`file copy` and `file rename` of a directory stopped faulting this
round and nothing has measured what they do now.

#### The spin is fCmd-20.2's own cleanup, and the bug is that a delete fails

`tail -20 /tmp/tcl-all.out` named it without any process hunting:

```
==== fCmd-20.1 TraverseUnixTree : failure opening a subdirectory FAILED
---- Test cleanup failed:
error deleting "tfa": invalid operation
---- errorCode(cleanup): POSIX {unknown error} {invalid operation}
```

**Two things in that errorCode.** `invalid operation` is a Plan 9
errstr, and `unknown error` is Tcl's rendering of an errno libap had no
name for -- i.e. `EPLAN9`, which means the string is in no table in
`_errno.c`. So `file delete -force` on a directory fails, and
`fCmd-20.1` leaves `tfa` behind.

**And the loop is upstream's, one test further on:**

```tcl
test fCmd-20.2 ... -cleanup {
    while {[catch {file delete -force tfa}]} {}
}
```

An unbounded retry with no limit and no delay. A delete that can never
succeed spins there at full CPU writing nothing -- which is exactly the
shape observed, and it is **the first spin in this project's Tcl work**.
Nothing in libap can stop it; the fix has to be that the delete
succeeds.

**This is the third instance of "a fix that makes a process reach code
it never reached before can expose anything on that path".** Before
last round, `fCmd-20.1` *faulted* in `fts_stat` and the process was
held as `Broken`; now `TraverseUnixTree` runs, gets a real answer, and
the next test's cleanup discovers that the delete does not work. The
`fts` fix is not wrong -- it moved a silent crash to a loud failure,
which is the direction this file has preferred every time.

`sys/lib/tests/rmdir-test.c` asks the machine which call fails and
prints Plan 9's own errstr for each step of `fCmd-20.1` -- mkdir,
chmod 0, rmdir at 0, chmod back, rmdir, rmdir the parent. 0 failures on
glibc, where the interesting line is that `rmdir` of a 00000 directory
**succeeds**: removing a directory is governed by the permissions of its
*parent*, not its own. If Plan 9 disagrees, that is the bug and the
probe says so in one line.

**Finding a spinning process mechanically**, since a hundred-line `ps`
defeats reading it by eye -- every leftover listener is `0:00 0:00`, so:

```
ps | awk '$7=="tcltest" && ($3!="0:00" || $4!="0:00")'
```

names the ones that have used any CPU at all. Two of those a few
seconds apart is the comparison; `diff` of two saved listings is the
same thing without the eye. Killing the leftovers first makes every
later `ps` legible:

```
for(i in `{ps | awk '$6=="Open" && $7=="tcltest" {print $2}'}) echo kill > /proc/$i/ctl
```

#### "invalid operation" is Plan 9 for "directory not empty", and rmdir now says so

**The probe answered it in one line**, and section 3 came out identical
to glibc, so the permissions half was never the problem:

```
no   rmdir of a non-empty directory (must fail) -> errno 1002
     (invalid operation); plan 9 says: invalid operation
FAIL ...and it reported ENOTEMPTY or EEXIST
YES  rmdir tfa/a while it is 00000
```

One failure, and it is the whole chain: **1002 is `EPLAN9`** -- libap's
"a Plan 9 error with no POSIX equivalent" -- because `invalid operation`
is in no table in `_errno.c`. Tcl's `DoRemoveDirectory` is

```c
if (rmdir(path) == 0) return TCL_OK;
if (errno == ENOTEMPTY) errno = EEXIST;
if ((errno != EEXIST) || (recursive == 0)) goto end;
... otherwise delete the contents and try again ...
```

so an unrecognised errno is not a worse message, it is **a `file delete
-force` that never recurses**. `fCmd-20.1` left its directory behind,
and `fCmd-20.2`'s unbounded cleanup spun on it for ever.

**NOT an entry in `_errno.c`, and the reason is the rule that section
already carries.** `invalid operation` is a generic 9P error with no
single POSIX meaning -- a write of a control message a device will not
accept reports it too, and answering "Directory not empty" there would
be a wrong answer in a confident voice. Naming a string in that table
also changes control flow, since `bind()` gates its announce fallback on
`errno == EPLAN9`.

So the question is asked where the answer is knowable. `rmdir()` now
looks: if the remove failed and libap could not name the error, open the
directory and see whether anything is in it, and report `ENOTEMPTY` only
then. That holds on any file server whatever string it picks, and it
needs no guess about what hjfs means.

**Prediction.** `rmdir-test` reports 0 failures. `fCmd-20.1`'s *cleanup*
succeeds, so `tfa` does not linger and **`fCmd-20.2` does not spin** --
which is the whole point. `fCmd-20.1` itself may well still fail, and
that is expected rather than a miss: it wants `catch {file delete -force
tfa}` to return **1**, i.e. it expects the delete to be refused, which
on Unix it is because a 00000 directory cannot be traversed. Plan 9
checks the *parent* for a remove, so the probe shows `rmdir tfa/a while
it is 00000` succeeding -- the delete may now work and the test then
fails in the opposite direction. That is the machine differing from
Unix, not libap being wrong, and it belongs with `chan-io-40.3`'s umask.

**Still open and smaller**: `unlink()` of a directory also reports
EPLAN9 where POSIX allows EPERM or EISDIR (section 2 of the probe).
Unfixed deliberately this round -- one measured change at a time, and
`rmdir` is the one the suite is stuck behind.

#### THE SUITE FINISHES. 167 files, 67008 tests, and the first real accounting

```
Tests ended at 2026-09-18 05:03:08 +0200
all.tcl:  Total 67008  Passed 61226  Skipped 5630  Failed 152
Sourced 167 Test Files.
tcl-runall: every file ran, now entering exit (code 0)
```

**No freeze, no spin, no kill -- it ended by itself.** `rmdir-test`
reports 0 failures with `errno 27 (Directory not empty)` where it used to
say 1002, so the `rmdir` fix is confirmed, and `fCmd.test` no longer
pins a core.

**Read `Failed 152` with the five aborts beside it.** Five files exit
with a `Test file error`, and tcltest counts nothing at all for a file
that aborts -- `fCmd.test` reports `Total 0` while the log holds eighty
of its failures. So 152 is the count from the files that *completed*,
and the honest per-file table has to come from the log:

```sh
grep '^==== ' /tmp/tcl-all.out | grep ' FAILED$' |
	grep -v '^==== [A-Za-z0-9._-]* FAILED$' |
	sed 's/^==== //; s/-[0-9].*//' | sort | uniq -c | sort -rn
```

The second `grep -v` drops tcltest's bare repetition of the name, which
is why a naive count doubles.

| | |
|---|---|
| `fCmd` | **80**, and it aborts as well |
| `io` 22, `chan-io` 19 | the old buffering cluster, still the oldest open item |
| `socket_inet` 18, `socket` 10 | first measurement ever -- no run had reached these files |
| `filename` 18 | path handling |
| `clock` 16 | |
| `cmdAH` 10, `env` 9, `expr` 5 | |
| `lseq` 3, `exec` 3, `binary` 2 | `binary` is the two Inf tests |
| `zipfs` ~12 | one per case, mostly the password/cipher block |

**`Skipped 5630` is not a target**: `win` 409, `thread` 197, `bigdata`
99, `bigEndian` 78, `cookiejar` 60 and a long tail of feature
constraints.

**The five aborts, and only one of them is a mystery:**

```
encoding.test   file copy -force cp932.chars shiftjis.chars  -> ENOENT
fCmd.test       file copy abc.file abc.dir                   -> ENOENT
http.test       file copy .../httpd .../httpd_2498           -> ENOENT
unixFCmd.test   file delete of a ~50-deep path  -> invalid operation
winFCmd.test    the same
```

**`fCmd`'s is downstream and is `file link`.** The lines immediately
before it are `fCmd-28.9 file link: success with file FAILED` with
`errorCode POSIX ENOSYS`, and the abort is the file's own top-level
cleanup copying a file those tests should have left behind. `symlink()`
being unimplemented now costs a whole test file rather than a handful of
tests, which moves it up the list.

**`encoding`'s is NOT downstream, and that is the one to chase.** The
file it fails to copy is created two lines earlier, in the same
directory:

```tcl
cd [temporaryDirectory]
foreach enc {cp932 euc-jp iso2022-jp} {
    set f [open $enc.chars w]
    ...
    close $f
}
file copy -force cp932.chars shiftjis.chars     ;# ENOENT
```

So `file copy` of a file that demonstrably exists reports "no such file
or directory". **The line to suspect first is in `DoCopyFile`**, and it
is the *destination* stat rather than the source:

```c
if (TclOSlstat(dst, &dstStatBuf) == 0) {
    if (S_ISDIR(...)) { errno = EISDIR; return TCL_ERROR; }
} else if (errno != ENOENT) {
    return TCL_ERROR;            /* <- a missing destination must be ENOENT */
}
```

A destination that does not exist yet is the normal case, and the whole
copy is refused unless `lstat` reports exactly `ENOENT` -- which in APE
is **20**, not the 2 a reader expects. Whether libap answers that for
every shape of missing path is exactly the sort of thing to measure
rather than reason about.

**The cheapest possible next step, four lines and no rebuild:**

```
tclsh
% cd /tmp
% set f [open a.txt w]; puts $f hi; close $f
% file copy -force a.txt b.txt
```

If that reports ENOENT, the reproducer is two commands and the next
probe writes itself. If it works, the suite's context matters --
`[temporaryDirectory]`, a long path, a freshly written file whose
directory entry has not settled -- and *that* is the variable.

**The deep-path delete is the other one**, and it is its own bug:
`unixFCmd` and `winFCmd` both build a path about fifty components deep
and fail to delete it with `invalid operation`. That is the same errstr
`rmdir` now interprets, so the new code looked and found the directory
**empty** -- the failure is the path, not the contents. A length limit
somewhere in libap's path handling is the obvious suspect and is worth a
probe of its own.

#### `file copy` is reproducible in four lines, and five guesses were wrong

```
% cd /tmp
% set f [open a.txt w]; puts $f hi; close $f
% file copy -force a.txt b.txt
error copying "a.txt" to "b.txt": no such file or directory
```

So it is **not** the suite's context -- not `[temporaryDirectory]`, not a
long path, not a file an earlier test failed to leave behind. A file
written one line earlier cannot be copied, and that alone aborts
`encoding.test`, `http.test` and `fCmd.test`.

**Five candidates were argued from the source and none survived
reading:** the `S_IFMT` dispatch in `DoCopyFile` (the mode bits are set
correctly by `_dirtostat`); `open()`'s `access(path, 0)` precheck (which
handles a missing file correctly); the mode argument carrying `S_IFREG`
(masked to `0777` by `open()`); `utime()`'s wstat; and the destination
`lstat`. **And the error message cannot choose between them**, because
Tcl prints `Tcl_PosixError` at a common `done:` label -- it reports
whatever errno holds by then and names both paths whichever call failed.

`sys/lib/tests/copyfile-test.c` makes the same calls in the same order
instead: `lstat(src)`, `lstat(dst)`, `open(src, O_RDONLY)`,
`open(dst, O_CREAT|O_TRUNC|O_WRONLY, srcStat.st_mode)`, the copy loop,
`chmod`, `utime` -- each reporting errno and Plan 9's own errstr.
0 failures on glibc.

**The assertion to read first is the destination `lstat`**, because it
is the one Tcl's control flow turns on:

```c
if (Tcl_FSLstat(target, &targetStatBuf) != 0) {
    if (errno != ENOENT) { errfile = target; goto done; }
```

A destination that does not exist yet is the *normal* case, and the copy
is abandoned before it starts unless `lstat` reports **exactly**
`ENOENT` -- which in APE is **20**, not the 2 a reader expects. If that
line says `FAIL`, the bug is one errno in one place and every file
operation that checks for a missing file is affected, not just copy.

The probe passes the **full** `st_mode` to `open()`, `S_IFREG` and all
(`0100644`), because that is what `TclUnixCopyFile` does. A faithful
probe makes the same call, not the tidier one.

#### Would `symlink()` as a copy do? No -- and it is ONE test, not many

**The premise does not survive the log, and I had half-endorsed it
myself.** Of `fCmd.test`'s eighty failures, the `28.x` link block
accounts for **one**:

```
 1 fCmd-28.x   the link tests
12 fCmd-6.x    CopyRenameOneFile: lstat(target) != 0 / errno != ENOENT / ...
11 fCmd-18.x   TclFileRenameCmd
11 fCmd-21.x   copy : single file to nonexistant, single dir, into directory
 5 fCmd-2.x    TclFileCopyCmd
```

`fCmd-6.4`, `6.5`, `6.6` and `6.9` are *named after* the branch
`copyfile-test.c` was written around -- `lstat(target) != 0`,
`errno != ENOENT`, `errno == ENOENT`. So the dominant cluster in the
file is copy and rename, and one bug plausibly carries most of it.

**And the abort is the copy bug, not the link bug.** The correction is
mine: last round this file said "`symlink()` being ENOSYS now costs a
whole test file". The aborting line is `file copy abc.file abc.dir`,
which is a *copy*, in top-level code that merely happens to sit after
the link tests. Reading a failure by what precedes it is the same
mistake as reading a freeze by the last line printed.

**On the design question, which is worth answering anyway.** Old APE
made `ln` a `cp`, and the question is whether `symlink()` could do the
same in libap. It should not, and the reason is not squeamishness:

- **`lstat()` must report `S_IFLNK`.** A copy is `S_IFREG`, so
  `file type` answers `file` where every caller expects `link` -- the
  `28.x` tests check exactly that, so the emulation would not even buy
  the one test it is aimed at.
- **`readlink()` has no target to return.** `file link` would succeed
  and `file readlink` fail on the thing it just made, which is worse
  than both failing.
- **Tcl uses `lstat` rather than `stat` deliberately**, to copy and
  rename links instead of their targets. With no distinction that
  choice silently reverses.
- **A link to a directory cannot be a copy** in any useful sense, and
  `linkDirectory` tests do exactly that.
- **A dangling link is a normal state.** A copy outlives its target,
  so the most commonly tested property is inverted.
- **Writes diverge silently.** That is the part that reaches real
  programs rather than tests: a build system that symlinks a config
  file gets two files that drift apart with no error anywhere.

It is also this file's own standing rule -- *do not invent semantics to
make a test pass* -- and the precedents are all recorded: no `bind()`
fallback to `*`, no error on an empty `/dev/snarf`, no unmapping of
descendants, no minted colormaps, no fabricated install paths.

**The distinction worth keeping is between a command and a library
call.** `ln(1)` is a one-shot a person invoked, and substituting a copy
is a defensible convenience with a visible result. `symlink(2)` is an
API that other code builds invariants on and then *tests*, and a
success reported for work not done is the `XLoadFont` family in its
most damaging form -- not a wrong attribute but wrong data.

**What would be worth doing instead**, in order:

1. **Ask whether this 9front has symbolic links at all.** Nothing in
   APE's headers mentions `DMSYML`, but those are APE's headers, not the
   kernel's. One grep on the VM settles it:

   ```
   grep -n DMSYM /sys/include/libc.h
   ```

   If it is there, `symlink`, `readlink` and an `S_IFLNK` arm in
   `_dirtostat` are a real implementation rather than an emulation, and
   the honest way to close the cluster.
2. If it is not, leave `symlink()` at ENOSYS. It is the truthful answer,
   and Tcl's `linkFile`/`linkDirectory` constraints are hardcoded to 1
   on every unix (`fCmd.test:87`), so no amount of libap politeness will
   make those tests skip -- they are simply tests of a feature this
   machine does not have, like `systray` in the Tk notes.
3. Spend the round on `file copy` instead, which is where the eighty
   are.

#### The syscalls are CLEAR, so `file copy` is above them

`copyfile-test` reports **0 failures on the VM**. Every call Tcl makes,
in Tcl's order, works:

```
note lstat of a missing file: errno 20 (No such file or directory)
PASS ...and it is exactly ENOENT, which Tcl requires
YES  open cft-src.txt O_RDONLY
YES  open cft-dst.txt O_CREAT|O_TRUNC|O_WRONLY with that mode
YES  chmod / utime
PASS the copy is the same size as the source
```

So the destination-`lstat` branch is fine, the full `st_mode` reaching
`open()` is fine, `chmod` and `utime` are fine -- **a sixth candidate
refuted, and this one by measurement rather than by reading.** That is
the answer the probe existed to give, and it is worth as much as a
confirmation: the bug is **not in the system calls**, so it is in what
Tcl does to the path before it makes them.

**What Tcl does that the probe does not**, in order of how cheap each is
to rule out:

- **normalises the path.** `Tcl_FSGetNativePath` runs the operand
  through `TclpObjNormalizePath`, which on unix uses `Realpath()` and
  `getcwd()`. A relative name becomes an absolute one first, and a wrong
  cwd or a wrong `realpath` would produce a path that genuinely does not
  exist -- ENOENT, from a call on a string the probe never builds.
- **converts it through the filesystem encoding**
  (`Tcl_UtfToExternalDStringEx`, `TCLFSENCODING`).
- **goes through the virtual filesystem layer**, `Tcl_FSLstat` and
  `Tcl_FSCopyFile`, rather than calling `lstat` directly.

**Four lines in `tclsh` separate the first from the rest**, and they
need nothing built:

```tcl
cd /tmp
set f [open a.txt w]; puts $f hi; close $f
pwd
file normalize a.txt
file normalize b.txt
file copy -force /tmp/a.txt /tmp/b.txt      ;# ABSOLUTE paths
file copy -force a.txt d.txt                ;# relative again
file rename a.txt c.txt
```

| | |
|---|---|
| **absolute works, relative fails** | it is normalisation -- `getcwd()` or `realpath()` -- and `file normalize` prints the wrong answer it is building |
| **both fail** | the path is not the variable; the vfs layer or the encoding conversion is, and the next thing to read is `Tcl_FSGetNativePath` returning NULL |
| **`file rename` also fails** | the two share `CopyRenameOneFile`, so it is above the copy-specific code entirely |

`pwd` and the two `file normalize` lines are the whole diagnosis if it is
the first case: they print the absolute path Tcl is about to use, and a
wrong one is visible on sight.

**And this is why the probe was worth writing even though it passed.**
Six mechanisms had been argued from the source; the probe did not name
the bug, but it removed every one of them at once and moved the search
up a layer. A measurement that refutes is not a wasted round.

#### The path is cleared, rename works -- and my probe was missing a call

```
% pwd                        -> /tmp
% file normalize a.txt       -> /tmp/a.txt
% file normalize b.txt       -> /tmp/b.txt
% file copy -force /tmp/a.txt /tmp/b.txt   -> no such file or directory
% file copy -force a.txt d.txt             -> no such file or directory
% file rename a.txt c.txt                  -> WORKS
```

Three things fall out of six lines:

- **Normalisation is correct.** `file normalize` prints exactly the
  right absolute path, so `getcwd()` and `realpath()` are not it.
- **Absolute and relative fail identically**, so the path is not the
  variable at all.
- **`file rename` works**, and that is the one that narrows hardest.
  `TclFileRenameCmd` and `TclFileCopyCmd` both go through
  `CopyRenameOneFile`, so the entire prologue is shared and
  demonstrably fine: `Tcl_FSConvertToPathType`, the
  `Tcl_UtfToExternalDStringEx` encoding conversion, `Tcl_FSLstat` on
  both operands including the `errno != ENOENT` branch, and the vfs
  dispatch. A successful rename returns before ever reaching the copy.

**So `Tcl_FSGetNativePath` is cleared too**, which is worth stating
because it was the leading suspect: `TclpObjRenameFile` uses it on both
operands exactly as `TclpObjCopyFile` does.

Two more things cleared from the host, for free:
`Tcl_StatBuf` is the ordinary `struct stat` on this arm of `tcl.h`, and
`TclOSlstat` is plain `lstat` because APE defines `S_IFLNK` -- so there
is no `*64` symbol and no struct-layout mismatch between what Tcl
compiled against and what libap provides.

**AND THE PROBE WAS UNFAITHFUL, WHICH IS WHY IT PASSED.** `DoCopyFile`
in *this* tree removes the destination before copying, and tolerates
exactly one error from doing so:

```c
if (unlink(dst) != 0) {
    if (errno != ENOENT) {
	return TCL_ERROR;
    }
}
```

I wrote the probe from the Tcl I remembered, which had no such call, so
it reported 0 failures while `file copy` failed -- **a probe that skips
a call cannot clear it.** The rule to carry, and it is a close cousin of
*a grep hit is a name, not an implementation*: **replicate the code in
the tree, line by line, not the code you remember.** `copyfile-test.c`
has a section 3 for the unlink now, and still 0 failures on glibc.

**That unlink is the last call Tcl makes that nothing here has
measured**, and APE's `unlink()` is not a thin wrapper -- it is a long
function that stats the path, walks all `OPEN_MAX` descriptors calling
`_dirfstat` on each, and renames the file to its qid and reopens it with
`ORCLOSE` when it is open in this process. Its missing-file path looks
right on reading, which is exactly what the last six readings looked
like.

**And if section 3 passes too, stop reading and trace.** Plan 9 has
`ratrace`, which this project has never used and which answers this
question directly:

```
cd /tmp
echo 'set f [open a.txt w]; puts $f hi; close $f
catch {file copy -force a.txt b.txt} m; puts $m' > /tmp/c.tcl
ratrace tclsh /tmp/c.tcl >[2] /tmp/rt.out
grep -n 'a.txt|b.txt' /tmp/rt.out | tail -40
```

Every system call on those two names, with its return value, in order.
That names the failing call outright instead of by elimination -- it is
the `strace` this file has wanted for several rounds without noticing it
was there.

#### FOUND: `utime()` returned the wstat byte count, and `ratrace` named it

**One trace, and every line of it is accounted for.** `ratrace tclsh`
on the four-line reproducer, grepped for the two names:

```
1404 Open   "a.txt"  0x0            = 4
1408 Create "b.txt"  0x1 0x1b4      = 5
1411 Pread  4 ... 4096 -1           = 0
1414 Stat   "b.txt"                 = 72
1415 Wstat  "b.txt" 0x70d520 49     = 49 ""
1416 Wstat  "b.txt" 0x70d520 49     = 49 ""
1417 Stat   "b.txt"                 = 72
1422 Remove "b.txt"                 = 0 ""
1423 Pwrite ... error copying "a.txt" to "b.txt": no such file or directory
```

Read it as libap:

- `Open` + `Create` are `TclUnixCopyFile`'s two opens.
- `Stat` + `Wstat` is `chmod()` -- it stats to keep the non-permission
  bits, then wstats.
- the second `Wstat` is `utime()`, and it **returns 49**, which is the
  size of the wstat message. **A success.**
- `Stat` + `Remove` is libap's own `unlink()`, which stats before
  removing. That is `TclUnixCopyFile` deleting the copy it had just made
  correctly.

```c
/* CopyFileAtts, tclUnixFCmd.c */
if (utime(dst, &tval)) {			/* 49 is true */
    return TCL_ERROR;
}
...
/* TclUnixCopyFile */
if (!dontCopyAtts && CopyFileAtts(...) == TCL_ERROR) {
    unlink(dst);
    return TCL_ERROR;
}
```

**`_dirwstat`/`_dirfwstat` answer the number of bytes written, and
POSIX says `utime` returns 0.** `stat/utime.c`, `stat/utimes.c` and
`stat/futimes.c` all ended `return n;`. Every caller writing the
ordinary `if (utime(path, &tval))` was told a successful call had
failed. `chmod`, `chown`, `truncate`, `ftruncate`, `fchmod`, `rename`
and `utimensat` in the same directory all test `< 0` and return 0, so
these three were the only ones -- checked rather than assumed.

**This is why the message named nothing.** Tcl prints `Tcl_PosixError`
at a common `done:` label, so it reported whatever errno held by then --
the `ENOENT` left over from stat'ing a destination that did not exist
yet, five lines earlier. Six readings of the source chased that ENOENT;
the failing call never set it.

**AND THE PROBE SAID `YES` FOR IT.** `step()` accepts anything `>= 0`,
which is right for `open()` and wrong for `chmod` and `utime`, so
`utime` returning 49 printed as a success in two consecutive runs.
**A check that cannot fail is not a check** -- the third instance of
that rule in these notes, and the first in a test of my own rather than
in the tree. `copyfile-test.c` has a `zero()` helper now that requires
exactly 0 and says so when it gets a positive number.

**What it cost, beyond the three aborted files.** Anything that sets a
timestamp and checks the result: `cp -p`, `tar` restoring mtimes,
`make` touching a target, `install -p`, and every `file copy` in every
Tcl program. It is silent in the other direction too -- the timestamp
*is* set, so nothing looks wrong until a caller believes the error.

**Prediction.** `copyfile-test` reports 1 failure before the rebuild,
at `utime ... returned 0`, and 0 after. `file copy -force a.txt b.txt`
works. `encoding.test`, `http.test` and `fCmd.test` stop aborting, and
`fCmd`'s copy and rename clusters -- `6.x`, `18.x`, `21.x`, `2.x`, which
are 39 of its 80 -- should move substantially. The count in the suite
total will *rise*, because three files that reported nothing now report
their real numbers: newly measured, not newly broken, for the fifth
time.

#### CONFIRMED: the copy works, three aborts become none, and the tally is honest

`copyfile-test` reports 0 failures with `utime ... returned 0`, and
`file copy -force a.txt b.txt` in `tclsh` simply returns. The suite:

```
all.tcl:  Total 67898  Passed 61985  Skipped 5695  Failed 218
Sourced 167 Test Files.
Test files exiting with errors:  unixFCmd.test  winFCmd.test
```

**Five aborting files become two.** `encoding.test`, `http.test` and
`fCmd.test` now run to the end; what is left is the deep-path delete,
which is its own bug. `Total` rises by 890 and `Failed` by 66 -- **the
count going up is three files reporting their real numbers for the first
time**, which is the fifth instance of "newly measured, not newly
broken", and this time it was predicted rather than discovered.

**The honest tally is the log, and it went the other way**: 239 -> 225
by the per-file table, because `Failed` cannot see a file that aborts.
Two numbers moving in opposite directions is what that looks like.

**Per file, and nothing regressed:**

| | old | new | |
|---|---|---|---|
| `cmdAH` | 10 | **4** | sections 23, 24 and 33 to zero |
| `fCmd` | 80 | **73** | 21 fixed, 10 newly reached |
| `filename` | 18 | 17 | |
| `tcltest`, `zipfs-mount-one-arg` | 1 | 0 | |
| `http` | 0 | 2 | newly measured; it used to abort |

`cmdAH-23.x` is `file lstat`, `24.x` is `file mtime`, `33.x` is `file
atime` -- every one of them a timestamp, which is exactly the shape of
the bug.

**And the prediction was half wrong, which is worth recording.** It said
`fCmd`'s copy and rename clusters -- `2.x`, `6.x`, `18.x`, `21.x`, 39
tests -- "should move substantially". **21 moved**, across sections 2
(5->1), 10, 13, 14, 21 (11->8), 22 and 25 (3->0), and `6.x` and `18.x`
did not move at all. So `utime` was one cause among several in those
clusters and the rest are separate bugs; the copy and rename work is not
finished, it is merely unblocked.

**The ten that appeared are newly reachable, and they are one cluster.**
`fCmd.test` used to abort inside the `28.x` block, so everything after
it had never run:

```
fCmd-31.6  file home USER
fCmd-32.5  file tildeexpand ~USER
fCmd-32.9  file tildeexpand ~USER/bar
fCmd-32.17 file tildeexpand ~USER does not mirror HOME
```

`~USER` expansion, which needs a password database mapping a user name
to a home directory. Plan 9 has none -- `_getpw` in libap answers
numeric ids, not homes -- so this is likely the `systray` case again:
the machine has no concept of the thing being asked about. Worth reading
properly before it is written off, since `$home` exists and the four
`31.x`/`32.x` tests that do *not* name a USER pass.

**What is left at the top**, by the per-file table: `fCmd` 73, `io` 22,
`chan-io` 19, `socket_inet` 18, `filename` 17, `clock` 16, `socket` 10,
`env` 9. None of these has been read yet, and `fCmd`'s remaining 73 now
divide into `6.x`/`18.x` (copy and rename, untouched by the timestamp
fix) and the `~USER` cluster.

#### The deep-path delete: PATH_MAX was 255, and that was ours

The last two aborting files, `unixFCmd.test` and `winFCmd.test`, both
die in `fCmd.test`'s `cleanup` on a tree about fifty levels deep:

```
error deleting "./tfad/dir/... x55": invalid operation
```

**`invalid operation` is hjfs's message for a non-empty directory** --
measured in `rmdir-test`, not guessed -- so the recursive delete had
failed to empty it.

**A CORRECTION FIRST, AND IT IS MINE.** This file previously read that
as "with the directory empty, so it is the path and not the contents".
That was wrong. `rmdir()`'s `notempty()` returns 0 **both** when the
directory really is empty and when `opendir()` on it fails -- *a check
whose negative result has two explanations*, which is a rule already in
these notes, in code written two rounds ago. The comment in `rmdir.c`
says so now. The conclusion happened to survive; the evidence for it did
not exist.

**The limit was a definition in our own header:**

```c
#define PATH_MAX _POSIX_PATH_MAX	/* 255 */
#define NAME_MAX _POSIX_NAME_MAX	/*  14 */
```

Those are the numbers POSIX guarantees every implementation supports
**at least**, used as though they were what this one supports at most.
**Plan 9 has no inherent path limit** -- 9P walks one element at a time
and never carries a whole path -- so the wall was entirely APE's.

What sits behind it:

- **`realpath()` is musl's** and declares `char stack[PATH_MAX+1]` and
  `char output[PATH_MAX]`, refusing anything longer outright. Tcl's
  `TclpObjNormalizePath` calls it.
- **Tcl's own buffers**: `TclpObjRenameFile` has
  `char srcPath[MAXPATHLEN], dstPath[MAXPATHLEN]`, `tclUnixFile.c` has
  three more. A 550-character path could be neither normalised nor
  walked.
- **14 was already contradicted next door.** `<dirent.h>` sets
  `MAXNAMLEN` to 255 and `struct dirent` is `char d_name[MAXNAMLEN+1]`,
  so libap has always returned names longer than `NAME_MAX` said were
  possible.

`PATH_MAX` is **4096** now, Linux's value and what portable code is
tested against, with `MAXPATHLEN` derived from it; `NAME_MAX` is 255.
`_POSIX_NAME_MAX` and `_POSIX_PATH_MAX` keep their standard values --
they are the guarantee, and code does compare against them.

`NAME_MAX` is spelled as a literal rather than `MAXNAMLEN`, because that
lives in `<dirent.h>` and a macro expanding to it would break every use
of `NAME_MAX` without that header. Caught on the host in one compile.

**It costs stack.** `realpath()` now has 8 KB of locals in one frame,
which is exactly what it costs on Linux; `at_functions.c` has two
`PATH_MAX` buffers in a few functions.

**THIS NEEDS `mk distclean` BEFORE `mk install`.** `limits.h` is a
system header, no mkfile here lists one as a dependency, and every
object with a `char buf[PATH_MAX]` has the old 255 compiled in. A
partial rebuild is the `HFILES` shape: logically inert, broadly and
unattributably wrong.

`sys/lib/tests/deeppath-test.c` measures it -- builds 140 levels (~700
characters), then `stat`s, `opendir`s and `realpath`s the deepest, then
removes the lot, reporting errno and Plan 9's errstr at whichever step
first refuses. **Its own buffer is 16 KB rather than `PATH_MAX`**,
because the constant is the thing under test and a probe sized by the
value it is measuring cannot report that the value is wrong. It prints
`PATH_MAX` before anything else, so a green run says which build
produced it.

**Prediction.** Before the rebuild: `deeppath-test` fails, most likely
first at `realpath` and then at the `> _POSIX_PATH_MAX` assertion; the
depth it reaches is the interesting number, because `mkdir` and `rmdir`
go straight to 9P and may well have no limit at all. After: 0 failures,
140 levels, and **no test file exits with an error** -- the first suite
run in this project with none. The failure count should barely move,
since the two files aborted near their ends.

#### NO FILE ABORTS -- and two corrections, both mine

```
all.tcl:  Total 68118  Passed 62048  Skipped 5887  Failed 183
```

and **no `Test files exiting with errors:` section at all**. That is the
first run in this project where every one of the 167 files reports its
own result. `Failed` 218 -> 183, and the log-derived count 218 -> 183
with it; the two agree for the first time, because nothing is hiding
behind an abort any more.

**CORRECTION 1: `PATH_MAX` was never 255, and my change was inert.**
`deeppath-test` printed

```
note PATH_MAX 1023, MAXPATHLEN 1023, NAME_MAX 27
```

-- **identical before and after the rebuild**, and matching neither the
255/14 this tree used to define nor the 4096/255 it defines now. Those
are **stock APE's** numbers. `sys/include/ape/limits.h` has never been
read by anything: `pcc` searches `/$objtype/include/ape` first
(`pcc.c:234-235`) and stock keeps a `limits.h` there. It is the same
trap as `float.h`, `stdarg.h` and `stdint.h`, for the **fourth** time,
and the guard made it worse in the same way -- this tree's file opened
`#ifndef __LIMITS`, which is stock's guard too, so whichever was read
second compiled to nothing.

Fixed the way the tree already fixed the other three: the content is
`limits_generic.h`, `limits.h` is a wrapper, and **the wrapper exists in
all eleven architecture directories** so stock's copy is never reached.
`deeppath-test` prints `<limits.h> came from THIS TREE` now, which is
`_APEXP_FD_SET_T`'s trick again -- **ask the header, do not infer from
the numbers.**

**CORRECTION 2: the abort was not the constant, it was the rebuild.**
The two `deeppath-test` runs bracket a `mk distclean; mk install` and
are byte-identical, so nothing about the limit changed; yet
`unixFCmd.test` and `winFCmd.test` stopped aborting. The only other
thing that happened is the full rebuild.

**The likely reason is `fts_alloc`, fixed four rounds ago.** That bug --
two `if` bodies commented out, so `fts_statp` was never allocated -- is
in the traversal `TclpObjRemoveDirectory` uses for a recursive delete,
which is exactly what could not empty that tree. `libap.a` was rebuilt
when the fix went in; **`tcltest` was not necessarily relinked**, and a
static library fix reaches nothing until the binary that uses it is
linked again.

That is a new trap and it belongs with the `HFILES` one, a level up:
**`mk install` rebuilds a library without relinking the binaries that
already exist against it.** Everything in this campaign was measured on
binaries that may have been carrying a mixture of old and new libap, and
the fix is the same as for a header change -- `distclean` when a library
change has to reach a program.

`PATH_MAX` is still worth raising: **1023 is a real wall** and
**`NAME_MAX` 27 is simply wrong**, since `<dirent.h>` gives `struct
dirent` a `d_name[MAXNAMLEN+1]` with `MAXNAMLEN` 255. But it fixes
nothing that is currently failing, and saying otherwise would be the
mistake this section is correcting.

**Prediction.** `deeppath-test` reports `PATH_MAX 4096, NAME_MAX 255`
and `came from THIS TREE`, and 0 failures. The suite should not move at
all; if it does, the eleven new headers changed something that was
depending on stock's values, and the per-file table says which.

#### The marker worked, and it proved my own diagnosis wrong

```
note PATH_MAX 1023, MAXPATHLEN 1023, NAME_MAX 27
note <limits.h> came from THIS TREE
```

**Both lines are true, and together they refute the round before.** The
header *is* this tree's -- so stock APE was never shadowing it, and the
eleven architecture wrappers fixed nothing. The numbers come from a
**second file in the same tree**, three lines below the ones I edited:

```c
/* sys/include/ape/limits_generic.h, last line before the #endif */
#include <sys/limits.h>

/* sys/include/ape/sys/limits.h */
#undef	NAME_MAX
#define	NAME_MAX	27
#undef	PATH_MAX
#define	PATH_MAX	1023
```

`<limits.h>` ends by including `<sys/limits.h>`, which `#undef`s and
redefines what it has just set. Every value in the outer file that this
one names is dead, and the `#undef` is why there is no redefinition
error to notice. Editing the outer file and reading the result measured
nothing at all.

**The rule this is an instance of: when a constant is wrong, grep for
EVERY definition of it, not the first one found.** One `grep -rn 'define
PATH_MAX' sys/include/ape/` answers it in a second, and I did not run it
until the marker forced the question.

**And the marker is what forced it.** It answered the question I asked
-- *which limits.h did this compile read?* -- truthfully, and the
disagreement between a true answer and wrong numbers is what said the
question was the wrong one. That is worth more than a marker that
confirms: `_APEXP_FD_SET_T` did the same thing one round earlier in the
`fd_set` work, refuting the architecture-directory explanation there
too. **Two for two against my favourite theory about these headers.**

**What stands from last round and what does not.** The correction about
the deep-path abort stands: it was cleared by the full rebuild, almost
certainly `fts_alloc` finally reaching `tcltest`, and not by any
constant. The correction *about the correction* is this: the constant
was 1023 rather than 255, and the reason was not the architecture
directory.

**The eleven wrappers stay**, as insurance rather than as a fix, and the
note in them says so. The guard collision they close is real -- this
tree's `limits.h` opened `#ifndef __LIMITS`, which is stock's guard --
even though nothing has shown stock's copy winning.

**Prediction.** `deeppath-test` prints `PATH_MAX 4096, MAXPATHLEN 4096,
NAME_MAX 255` and `came from THIS TREE`, with 0 failures and 141 levels.
The suite should not move; if it does, something was depending on 1023
or 27, and the per-file table says what.

#### env.test: nine failures, one interface, and libap was leaking into it

With nothing aborting, the per-file table is finally readable, and
`env` 9 is the cleanest cluster in it. Every test is "adding", "changing"
or "unsetting" an environment variable, and `env-2.1` shows what a child
actually sees where the test expects **nothing**: three names, and the
first two are libap's own --

```
_fdinfo=0 34 0 / 1 2 2 / 2 2 2 / ...   (newlines escaped by tcltest)
_sighdlr=
path=/bin<0x01>.
```

**Two separate bugs**, and the test is asking a fair question: it clears
the environment and asks a child to list it.

**1. `_fdinfo` and `_sighdlr` are libap's own bookkeeping.** They are how
descriptor flags and ignored signals cross an exec, `execve` writes both,
and `_envsetup` **consumes them on the spot** -- it calls `_fdinit()` and
`sigsetup()` with the value -- and then puts them into `environ` anyway.
A program has no business seeing them. Dropping them is safe precisely
because `environ` is not the transport: `execve` writes `/env/_fdinfo`
directly and a child reads `/env` rather than inheriting the array.

That is the `XLoadFont` family **inverted**: not a stub answering for
work it did not do, but an implementation detail answering as though it
were data. `nohandle` stays visible -- it is a knob a user sets, not
something libap writes.

**2. WITHDRAWN IN FULL -- there was no second bug.** What this section
said, and what the code change beside it did, rested on reading one
rfork flag backwards. It is left here rather than deleted because the
mistake is the useful part; the correction is measured, in the last
section of this file.

The claim was that `unsetenv()` could not reach a child, because the
environment lives in `/env` and `execve` only ever **created**:

```c
_RFORK(RFCENVG);		/* "our own copy of the group" -- WRONG */
...
if(envp)
	for(e = envp; *e; e++)
		_CREATE("/env/NAME", ...);	/* and never removes */
```

**`RFCENVG` does not copy the group, it creates an empty one.** The `C`
in `RFCNAMEG`, `RFCFDG` and `RFCENVG` is *clear*; `RFENVG` is the flag
that copies. So `execve` was already emptying `/env` on its own line
one, the creates below it were already the child's whole environment,
and the behaviour was correct before anything was changed -- exactly
what POSIX asks for. The `/env`-clearing loop added here was removing an
empty directory on every exec, and has been reverted.

Two things should have caught this earlier and both were in hand. First,
`path` was never evidence: the section below shows Tcl does not unset
it. Second -- and this is the one that stings -- **`HOME`'s absence from
the child was a refutation sitting in the log the whole time.** It was
read as an anomaly to be explained later rather than as the measurement
it was, and the chain was then traced through `unsetenv`, `execvp`,
`posix_spawnp` and `_envsetup` looking for the mechanism that hid it.
There was none: it was absent because nothing leaked. **A fact that
contradicts the diagnosis is not a loose end to come back to.**

**Prediction.** `env.test` goes from 9 failures to 0 or nearly 0 -- the
three lines above are all that stood between it and an exact match, and
two of them were ours. **`clock`'s 8 are the watch item**: every one is
`:localtime` with `TZ` changing, so if Tcl's `TZ` was never reaching
anything, these move with it; if they do not, `localtime()` is reading
Plan 9's `/env/timezone` rather than `TZ` and that is a separate and
much smaller question. Nothing else should move; if it does, clearing
`/env` took something a child needed, and the per-file table says what.

#### The `env` result: one half confirmed, the other half unmeasured, and the last line is not a bug

The run came back with the two libap names gone and everything else
unchanged:

```
before:  _fdinfo=0 34 0
1 2 2
...
         _sighdlr=
         path=/bin.
after:   path=/bin.
```

`Total 68118 Passed 62048 Skipped 5887 Failed 183` -- **identical to the
previous run, and the per-file diff is empty.** So the prediction above
("9 failures to 0 or nearly 0") was wrong, and it was wrong in the way
worth recording: the `_envsetup` half demonstrably landed and changed the
output, while the count did not move at all, because one surviving line
is as good as three for a test matching exactly.

**All nine of `env`'s failures are that one line.** `env-2.1`, `2.2`,
`2.3`, `2.4`, `3.1`, `4.1`, `4.3`, `4.4` and `4.5` are every test in the
file that calls `getenv` and compares exactly; nine tests, nine failures.
Nothing else in the file fails. So the cluster is one fact, not nine.

**And the fact is not libap's.** Two things have to be read together.

First, `env.test`'s `envprep` does not clear the environment; it clears
everything *except* a keep-list, and the comparison works because the
child script removes the same list from what it prints:

```tcl
if {[string toupper $name] ni [string toupper $keep]} { unset env($name) }
...
proc lrem {listname name} {
    upvar $listname list
    set i [lsearch -nocase $list $name]
    if {$i >= 0} { set list [lreplace $list $i $i] }
}
foreach name @keep@ { lrem names $name }
```

`keep` contains `PATH`. Both halves are case-insensitive, so Plan 9's
lowercase `path` is *kept* by the parent -- **Tcl never unsets it** --
and then matched by the child's filter.

Second, **`lrem` removes one element, and this environment has two.**
`apexp-sh` sets `PATH=/bin` because bash cannot see rc's `$path`, and rc
already had `path`. So the child's sorted `names` is `... PATH path ...`;
`lrem names PATH` deletes the uppercase one and returns, and the
lowercase one is printed. Checked on the host with a real `tclsh`, which
is the only reason this is stated rather than guessed:

```
names: HOME LANG PATH path
after: HOME path
```

That is upstream's code meeting a genuine property of this environment:
two spellings of one variable, which no Unix has. **Not something to fix
by inventing semantics** -- libap must not hide `path` because `PATH`
exists, and `apexp-sh` cannot drop `PATH` (the comment there explains
what breaks). `env`'s nine stay, and they are now *understood* rather
than open, which is a different thing from fixed.

**The half that is still unmeasured is the `execve` change**, and
noticing that is the useful part of the round. If `/env` had been
leaking, `HOME` should have appeared in the *before* output too:
`envprep` unsets it (it is not in `keep`), so it was not in `environ`,
not in `envp`, and only `/env` could have carried it. It was not there.
So either the leak is not what the code reading says it is, or Tcl's exec
path does something else.

**A `/env`-clearing `execve` is not a change to keep on a reading
alone** -- it empties `/env` on a failed exec, which is a real hazard --
so `sys/lib/tests/execve-env-test.c` now asks the question directly: a
parent omits a variable it really has from the `envp` it passes, and the
child says whether it can still see it. Section 2 passes a variable that
*is* in `envp`, because a child that saw nothing at all would otherwise
pass section 1 while proving nothing. 0 failures on glibc.

**Prediction, written before the run.** Section 2 passes -- `envp` has
always been delivered, or nothing would work at all. Section 1 is the
open question and I am not guessing it; the point of the file is that
both answers are useful. If it FAILS, the `execve` change is
load-bearing, `HOME`'s absence has some other cause, and that cause is
the next thing to find. If it PASSES, the leak was already closed by
something else, and the `execve` change should be reconsidered on its
hazard rather than kept for a bug it did not fix.

**The rule this round pays for**: *a fix that demonstrably changes the
output has still not been shown to fix the test.* Two of three lines
went and not one count moved. Read what the test **compares**, and count
what is left, before calling a cluster closed.

#### The exec boundary is right; whether it was already right is a separate question, and the first probe could not ask it

`execve-env-test` on the VM:

```
  note chosen: LANG=C.UTF-8
  note envp handed to the child is exactly:
  note   APEXP_KEPT=yes
  note   APEXP_OMITTED=LANG
--- child: what the exec boundary delivered ---
  note child env[0] APEXP_KEPT=yes
  note child env[1] APEXP_OMITTED=LANG
  note 2 entries in all
  PASS a variable the parent had but envp omitted is NOT visible
  PASS a variable envp DID pass is visible
  PASS ...and it has the value envp gave it
0 failure(s)
```

**So the boundary is POSIX now: a child's environment is exactly `envp`,
two entries and nothing else.** That is worth having measured; nothing in
this tree had asked before.

**But it does not answer the question the file was written for, and the
prediction beside it was reasoned wrongly.** I wrote "if it PASSES, the
leak was already closed by something else". That does not follow: the
build under test *contains* the `/env`-clearing change. A PASS is what
both worlds look like from here -- a fix that was needed and a fix that
was not. This is the tree's own rule about measuring a build that does
not contain the change, turned around: **a build that DOES contain the
change cannot tell you the change was necessary.** Same trap, opposite
face, and it is the second time this round that a prediction outran what
the measurement could distinguish.

**What reading did settle, and it removes one candidate explanation.**
Tcl does not call `execve`. `tclUnixPipe.c` uses

```c
status = posix_spawnp(&pid, newArgv[0], &actions, &attr, newArgv, environ);
```

and libap's `spawn()` branches on `usepath` **before** it looks at
`envp`:

```c
if(usepath)
	execvp(path, (const char **)argv);
else if(envp != NULL)
	execve(path, (const char **)argv, (const char **)envp);
```

-- so `posix_spawnp` **discards the `envp` it was handed** and the child
takes `execvp`, which is `_execpath(name, argv, environ)`. The
environment a Tcl child gets is the exec'ing process's own `environ`, not
anything Tcl passed. It reaches `execve` in the end, so `env.test` does
exercise this code; but anyone reasoning from the `envp` at Tcl's call
site is reasoning about an argument that is thrown away. (Whether
`posix_spawnp` *should* ignore `envp` is a separate question -- POSIX
says the `envp` argument is the child's environment whether or not the
path is searched. Recorded, not fixed, and not measured.)

**The anomaly that is still open.** If `/env` had been leaking, `HOME`
should have been in the *before* listing: `env.test`'s keep-list does not
contain it, so `envprep` unsets it, `unsetenv` edits `environ` only
(checked -- libap's is musl's, and its `__env_rm_add` is a no-op stub
here), and only `/env` could have carried it to the child. It was not
there. Every step of that chain has now been read and each one holds, so
the reading and the log disagree and the reading is what gets doubted.

**Section 3 is how to ask without rebuilding libap.** It replicates
pre-change `execve` exactly -- `rfork(RFCENVG)`, create the two names,
create nothing else -- and then lists `/env`:

- **other names still present** -> `RFCENVG` copies the group, the old
  `execve` leaked them into every child, clearing `/env` is
  load-bearing, and `HOME`'s absence has a cause still to find.
- **only the two** -> `RFCENVG` hands back an empty group, the old code
  was already correct, and the change should be **reverted**.

*(It was the second. See the last section.)*

It is a probe, not a check -- it asks what one operating system does, so
it prints its finding and says which conclusion follows in words, and
counts no failure either way. A PASS/FAIL there would be asserting the
answer the file exists to find. It runs in a `fork()`, so the parent's
environment group is untouched whichever way it goes, and `rfork` is
declared locally rather than by including `<lib9.h>`, which would bring
its own `Dir`, `uchar` and `open()` in next to `<dirent.h>` and
`<fcntl.h>`. Both branches syntax-check under gcc; sections 1 and 2 give
0 failures there.

**No prediction this time.** The honest tally in these notes is about one
in eight for mechanisms guessed from code alone, I have read every step
of this chain and it contradicts the log, and the two outcomes point in
opposite directions -- keep the change or revert it. Writing a guess down
here would only be something to be wrong about.

#### The probe's answer: RFCENVG was already the clear, and the fix is reverted

```
--- 3. probe: what RFCENVG leaves in /env ---
  note 2 names in /env after rfork(RFCENVG) + 2 creates; 0 of them are the parent's
  note SO: RFCENVG hands back an EMPTY group. The old
  note execve was already correct, and clearing /env
  note buys nothing for the cost of emptying it on a
  note failed exec -- the change should be reverted.
```

**Two names, neither of them the parent's.** `RFCENVG` creates a new
*empty* environment group -- the `C` in `RFCNAMEG`, `RFCFDG` and
`RFCENVG` is **clear**, and `RFENVG` is the flag that copies. I had the
pair the wrong way round, wrote "our own copy of the group" in a comment
next to the line, and built a whole diagnosis on top of it.

So `execve` was correct before this round began: line one empties the
group, and the `_CREATE` calls below are the child's entire environment.
The `/env`-clearing loop was **removing an empty directory on every
exec** -- a `_dirreadall` and a remove per entry, for nothing. Reverted;
the comment now states what the flag does and why it is worth saying.

**What remains from the round is the half that was real.** `_fdinfo` and
`_sighdlr` no longer leak into `environ`, confirmed on the VM; that was
a genuine bug and is fixed. `env`'s nine failures are the lowercase
`path`, explained above and not ours. Nothing else changed.

**The failed-exec hazard is unchanged and was never new.** This file
notes that a failed `execve()` has already rforked the environment
group, rewritten `/env/_fdinfo` and `/env/_sighdlr` and closed every
`FD_CLOEXEC` descriptor. Emptying `/env` was always part of that -- it
is what `RFCENVG` does -- so the line added to CLAUDE.md saying a failed
`execve()` *now* also empties `/env` was wrong in the one word "now".
The hazard is old, real, and correctly described in `execpath.c` and
`posix_spawn.c`, neither of which claims the flag copies.

**Three lessons, and the third is the expensive one.**

**A flag whose name is one letter from another flag's is worth
checking**, not recalling. `RFENVG` and `RFCENVG` differ by a `C` and
differ in meaning by exactly the thing the diagnosis turned on. The same
holds for `RFNAMEG`/`RFCNAMEG` and `RFFDG`/`RFCFDG`, so this is a family,
not a one-off.

**A comment can be the thing that misleads you, and this one was mine.**
`/* our own copy of the group */` was written during the change and then
read back two rounds later as though it were evidence about the kernel.
A comment restating what a call does is a claim, and it gets no more
credit than any other unmeasured claim.

**`HOME`'s absence was a refutation, and it was treated as a loose
end.** It was in the very first log: if `/env` had leaked, `HOME` had to
be there, and it was not. Instead of taking that as the answer, I filed
it as an anomaly and spent the next passes reading `unsetenv`,
`execvp`, `posix_spawnp` and `_envsetup` to find what could have hidden
it. Nothing had. **A fact that contradicts the diagnosis is not a loose
end to come back to -- it is the measurement, and it outranks the
reading.** Every step of that chain was correct; the conclusion they
were being recruited to defend was not.

**What the probe was worth.** One test file, no rebuild of libap,
compiled and run in a minute, and it reversed a committed change. The
rule it came from -- that a build containing a change cannot tell you
the change was needed -- is now in CLAUDE.md, and replicating the old
code beside the new is the cheap way to ask. It was written expecting to
confirm the fix, and its value was entirely in being written so it could
say the opposite: it prints the conclusion for *both* outcomes and counts
no failure either way, which is why the answer was readable as soon as
it ran rather than argued about afterwards.

#### clock 16: $TZ reached nothing, and there were two timezone implementations

The characterisation from two rounds ago held up: every one of `clock`'s
sixteen is `-timezone :localtime`, the mode where Tcl stops using its own
tzdata and asks the C library. The test names say what is wanted outright:

```
clock-38.3sc {ensure cache of base is correct for :localtime
               if TZ-env changing / scan}
```

**libap had two timezone implementations that could not see each other,
and neither had heard of `$TZ`.**

```c
/* tzset.c */		if((p = getenv("timezone")) == 0)	/* Plan 9's spelling */
/* ctime.c */		if(tz.stname[0] == 0) readtimezone();	/* once per process */
/* ctime.c */		i = open("/env/timezone", 0);		/* its own static */
```

So `tzset()` had no effect on `localtime()`, setting `TZ` had no effect
on anything, and `readtimezone()` ran once ever -- there was no path by
which a changed variable could reach an answer. Two more gaps came with
it, and they are the same bug seen from the other end: nothing set
`tm_gmtoff` or `tm_zone`, though `struct tm` here has both, so
`strftime`'s `%Z` was

```c
case 'Z':
	/* hack for now: assume eastern time zone */
	i = t->tm_isdst? 1 : 0;
	sp = strval(sp, se, tz, i, 2);	/* static {"EST", "EDT"} */
```

-- every zone on earth printing as one of two names -- and `%z` did not
exist at all, so it fell to `default:` and printed a literal `z`. **The
hack looked necessary because the field it should have read was never
filled in.**

`time/tzone.c` is now the one place that knows: `$TZ` parsed as a POSIX
TZ string when set, `/env/timezone` in Plan 9's own format when not, UTC
with an empty name when neither parses. `tzset.c` is thirty lines that
publish the result in the four globals; `localtime_r` asks for an offset
and fills in `tm_isdst`, `tm_gmtoff` and `tm_zone`; `%Z` reads the name
and `%z` exists.

**The sign conventions are worth stating once because two of the three
disagree.** A TZ string's offset is positive **west** (`EST5` is five
hours behind); `tm_gmtoff` is positive **east**; and the `timezone`
global is positive **west** again, four lines from `tm_gmtoff` in the
same header. The conversion happens in exactly one function, `getoff()`.

**WHO RE-READS `$TZ`, WHICH THE TEST GOT WRONG BEFORE THE LIBRARY DID.**
POSIX says `localtime()` behaves as if it called `tzset()`, and that
`localtime_r()` *need not*. glibc takes that literally:

```
setenv("TZ","EST5",1); tzset();
setenv("TZ","GMT-11:30",1);	/* no tzset() */
localtime_r -> -18000		(the OLD zone)
localtime   -> +41400		(the new one)
```

`tz-test.c` asserted that `localtime_r` picks the change up, and failed
on glibc -- **writing the test first is what caught it.** libap was about
to refresh on every call and quietly differ from every Linux this code is
developed against. It does not; `_tzrefresh()` is called from
`localtime()` and from `tzset()`, and `localtime_r` uses the state it
finds. Tcl needs nothing more: it watches `$TZ` itself and calls
`tzset()` when it changes (`tclClock.c:4699`), then uses `localtime_r`.

#### tz-xcheck: linking the parser under test into a glibc program

The useful thing this round produced is not the engine, it is how it was
checked. `tz-test.c` on the build host passes by asking glibc for the
answers -- it cannot say whether **libap's** parser is right until it
runs on the VM, and each round trip there is a full rebuild.
`sys/lib/tests/tz-xcheck.c` links `time/tzone.c` into a glibc program and
sweeps ~1.4 million instants over nineteen TZ strings, comparing offset,
`tm_isdst` and zone name against `localtime_r` for each.

**It found two bugs before Plan 9 ever saw the code**, and the counts are
the interesting part:

- **102,970 mismatches.** `TZ=GMT` -- a name with no offset. POSIX
  requires the offset; glibc treats it as +0 and keeps the name. The
  first parser rejected it and fell through to the UTC fallback, losing
  the name. **`tz-test.c` has a `check("GMT", ...)` line, so this would
  have failed on the VM** -- the cross-check turned a rebuild round into
  a recompile.
- **6,048 mismatches.** Rule-less `EST5EDT` before 2007, which turned out
  to be a divergence to document rather than a bug to fix (below).
- **0.**

**Two divergences are deliberate, and deciding that is the whole of the
judgement here.** Both are glibc artifacts, not rules, and the standing
rule is that one operating system's own behaviour is a probe:

- **Before 1970** glibc computes no transitions at all for a POSIX-rule
  zone, so `CET-1CEST,M3.5.0,M10.5.0` is never DST in 1968. That falls
  out of a transition table starting at the epoch. libap applies the
  rules for every year.
- **A DST name with no rule part** is implementation-defined. glibc
  resolves `EST5EDT` against real US historical tzdata -- it has
  1974-01-06 and 1975-02-23, the emergency DST years -- which needs a
  database this system does not carry. libap uses the US rules since
  2007, which is exactly what glibc's own answer becomes from 2007 on.

**No zoneinfo, and that is a limit rather than something unfinished.**
`TZ=America/New_York` needs tzdata. `TZ=US/East-Indiana` appears in
clock.test and gets UTC with an empty `%Z`, which is what glibc does here
too -- measured. Plan 9's `/adm/timezone` files hold the same information
in a different format and could be looked up by name later. Tcl does not
need it: it ships its own tzdata and only falls back to us for
`:localtime`.

**An empty zone name is deliberate, and it is the `XLoadFont` rule
applied to a string.** An unparseable `TZ` gives `%Z` as nothing rather
than `"UTC"`, because a caller can tell "no zone" from a zone that really
is UTC. `"UTC"` would be a confident wrong answer.

**Prediction.** `clock` goes from 16 to single figures or zero; the tests
are named for the mechanism that was missing and the mechanism is there.
`%z` existing at all should move `clock-42.1` (`%z` in `:localtime` west
of Greenwich) on its own. What I am NOT predicting is the rest of the
suite: `strftime` is used well beyond `clock`, `%Z` used to print `EST`
or `EDT` unconditionally and now prints the real name, so anything that
compared against those two strings by luck will change. If a count rises,
that is the place to look first. `mktime` calls `localtime_r` and is
unchanged, which is the other thing to watch.

#### clock: 16 to 0, confirmed, and nothing else moved

`Total 68118 Passed 62056 Skipped 5887 Failed 175`, marker, exit 0.
183 -> 175, and `clock.test` has left the `Files with failing tests`
line altogether.

**The per-name diff is the thing to read, and it is exactly the cluster:**

```
==== clock-38.3fm.vm:0/1  ensure cache of base is correct ... / format
==== clock-38.3sc.vm:0/1  ensure cache of base is correct ... / scan
==== clock-40.1.vm:0/1    regression - bad month with -timezone :localtime
==== clock-42.1.vm:0/1    regression test - %z in :localtime when west of Greenwich
```

Four tests, each run twice (`.vm:0` and `.vm:1`), so the "16" in the
per-file table was 8 executions of 4 tests. **A count in that table is
executions, not tests** -- worth knowing before sizing the next cluster
from it.

`clock-42.1` is the one that `%z` alone would fix, which is what I said
before the run. **And the thing I flagged as the risk did not happen**:
`%Z` now prints the real zone name for every zone instead of always
`EST` or `EDT`, and not one test anywhere in the suite changed because
of it. `Total` and `Skipped` are identical, `Passed` is up by exactly 8,
and the set of failing names is otherwise unchanged.

#### fCmd 35: three groups, and two of them are one bug each

Reading the thirty-five (plus `unixFCmd`'s four) sorts them cleanly:

| group | count | what it needs |
|---|---|---|
| symbolic links | 15 | 9front has none -- out of reach |
| `~USER` | 8 | a password database Plan 9 has not |
| **renaming a directory** | **8** | ours |
| **EPERM where POSIX says EACCES** | **4+** | ours |

**The directory bug is one line, and it made every directory rename
across directories fail.** A wstat can change a name but cannot move a
file to another directory, so `rename()` copies when the two are in
different directories -- and the copy path ran for directories too:

```c
if((tfd = _CREATE(to, OWRITE, s->mode)) < 0)
```

A directory cannot be opened for writing. So `file rename td1 td3/td3`,
which `fCmd-9.11` expects to simply **succeed**, came back as

```
error renaming "td1" to "td3/td3": invalid operation: 'td3/td3'
errorCode: POSIX {unknown error} {invalid operation: 'td3/td3'}
```

**and that also explains two failures that read as if they were about
permissions.** `fCmd-9.1` and `unixFCmd-1.7` set a directory
unwritable and expect "permission denied"; they got "invalid operation"
because the create failed for its own reason before the permission on
the real target was ever tested. **A wrong error can hide the right one,
and a cluster that looks like two bugs can be one.**

An empty directory is now made at the destination with `OREAD` and
`DMDIR` and the original removed. A **non-empty** one still answers
`EXDEV`, and that is an answer rather than a shrug: POSIX's EXDEV means
"you will have to copy this yourself", and Tcl's `CopyRenameOneFile`
already branches on exactly that errno and does the recursive copy. The
divergence is real -- POSIX says a non-empty directory rename within one
file system succeeds, and on glibc it does -- so `rename-test.c`'s
section 4 accepts *either* success *or* exactly EXDEV, and still fails
for the EPLAN9 this bug produced.

**The other half is EINVAL for a directory moved into itself.** POSIX
requires it when the old pathname is an ancestor of the new one.
`file rename td1 td1` becomes `rename("td1", "td1/td1")`
(`unixFCmd-1.3`), and `fCmd-9.14.3` does the same thing through `..`.
**The check compares qids up the tree rather than strings**: a textual
prefix test passes `td1/td1` and fails `../td1/foo`, and this name space
has binds everywhere, so a string is the wrong thing to compare. It
walks up from the parent of the destination appending `/..` and asking
the file server, stopping when a stat fails or the qid stops changing.
`qid.vers` is deliberately not compared -- it changes when a file is
written, and this is a question of identity.

**And a one-word errno fix with four tests behind it.**
`_errno.c` had

```c
{EPERM,	"permission denied"},
```

POSIX splits the two: **EACCES is "the permission bits say no", EPERM is
"you are not the owner and only the owner may do this".** Plan 9's
`Eperm` is raised by the ordinary file permission check, so it is the
first. `fCmd-4.11`, `4.14`, `6.6` and `6.24` all make a directory mode 0
and compare the message exactly:

```
was:    can't create directory "td1/td2/td3": operation not permitted
wanted: can't create directory "td1/td2/td3": permission denied
```

`wstat -- not owner` and `wstat -- not in group` stay EPERM, which is
precisely what EPERM is for. **This is a mapping changed, not an entry
added** -- the standing warning about `_errno.c` is that adding a name
changes control flow because `bind()` gates its fallback on `EPLAN9`,
and this touches neither. Every other EPERM in libap is *set* directly
rather than read back out of the table, checked by grep.

**`rename-test.c`'s section 7 skips itself as root, and that is not
politeness.** A superuser bypasses the permission check, the rename
succeeds, and a test asserting EACCES would report a failure that has
nothing to do with the library -- a green run for the wrong reason,
inverted. It was verified by re-running the binary as uid 65534 on the
build host, which is the only way that section was ever exercised there.

**Prediction, and it is counted rather than hoped.** Twelve failures
have been read individually and put in one of the two groups:
directory rename `fCmd-9.1`, `9.11`, `9.14.3`, `18.3`, `22.4`, `6.30`,
`unixFCmd-1.3`, `1.7`; errno `fCmd-4.11`, `4.14`, `6.6`, `6.24`. Those
should go. `fCmd-6.21`, `6.25` and `6.26` are unread and may be in the
same families -- if they are, sixteen. **`unixFCmd-1.1` is not ours to
fix**: it expects EACCES from walking *through* a mode-0 directory and
Plan 9 answers "does not exist", which is the file server's own choice
and a probe rather than a library rule. The remaining 23 are symlinks
and `~USER`. **What to watch is `rename()` being reached by code that
never got past the old failure**: a fix that lets a process reach code
it never reached before can expose anything on that path.

#### fCmd: every failure that was ours is gone, and the prediction held

`Total 68118 Passed 62070 Skipped 5887 Failed 161`, marker, exit 0.
175 -> 161.

**Sixteen fixed, and fifteen of them were named in advance:**

```
fCmd-9.1  9.11  9.14.3  18.3  22.4  6.30  unixFCmd-1.3  1.7   (directory rename)
fCmd-4.11 4.14  6.6     6.24                              (EPERM -> EACCES)
fCmd-6.21 6.25  6.26                                      (flagged unread; same families)
socket_inet-4.2                                           (not ours -- see below)
```

The twelve predicted all went. `6.21`, `6.25` and `6.26` were recorded
as "unread and may be in the same families" -- they were, which is worth
noting as the one place guessing paid, and it paid only because the
guess was labelled as one.

**What remains in `fCmd` is exactly the two groups that were called out
of reach**, with nothing left over:

```
symlink   18.12 18.13 18.14 18.15 18.16 21.7.2 21.8.2 21.9
          26.1 26.2 26.3 28.9 28.21 28.22 unixFCmd-2.2.2   = 15
~USER     31.6 31.9 32.5 32.5.1 32.9 32.9.1 32.17 32.17.1  = 8
Plan 9    unixFCmd-1.1                                     = 1
```

24 of 24 accounted for. **A cluster read all the way through before
being worked on came apart exactly as the reading said it would**, which
is the argument for reading all thirty-five rather than fixing the first
one and re-running.

`rename-test` on the VM: 0 failures, every section including 5b through
`..` and section 7's EACCES. Note APE's errno *numbers* are its own --
`EINVAL` is 12 and `EACCES` is 2 there -- which is why the test compares
names and never numbers.

#### socket_inet-5.1 and 5.3: a test that had been passing for the wrong reason

Two appeared as the sixteen went, and the first suspicion has to be the
errno change, because `EPERM` -> `EACCES` is exactly the kind of "pure
naming change" this file already records as having altered control flow
once (`bind()`'s fallback is gated on `EPLAN9`, and naming an error stops
it running).

**It is not that, and the checks are cheap enough to state.**

- Both tests' bodies `return` a *fixed string* whichever way the error
  goes. Only success versus failure matters, and an errno cannot turn a
  failure into a success.
- Tcl's server path tests exactly one errno -- `tclUnixSock.c` greps to
  `EADDRINUSE`, twice, both guarded by `port == 0`. Neither `EACCES` nor
  `EPERM` appears anywhere in it.
- `bind()`'s fallback is gated on `EPLAN9`; `EPERM` was not `EPLAN9` and
  `EACCES` is not either, so that gate is unchanged.

**`socket_inet-4.2` is the evidence for what it really is.** In the same
file, in the same run, it went the *other* way: it had been failing with

```
errorCode: POSIX EADDRINUSE {address already in use}
```

for `socket -server dodo -myaddr $localhost 0x3000`, and now passes.
Nothing in this round touches sockets, so **this file's results depend
on what is already holding ports when the run starts** -- and this tree
already records "over a hundred leaked `listenproc` processes accumulate
across runs, since nothing records the listener's pid for `close()` to
kill".

So the reading is that 5.1 and 5.3, which ask that `socket -server dodo 1`
and `... 21` be REFUSED, were previously refused with `EADDRINUSE` by a
leftover listener and **passed for the wrong reason**; with the ports
free they succeed, because on a 9front terminal glenda is the host owner
and may announce a privileged port.

**If that is right the constraint is the thing that is wrong, and it is
upstream's.** `notRoot` comes from

```tcl
ConstraintInitializer root {expr {($::tcl_platform(platform) eq "unix") &&
	($::tcl_platform(user) in {root {}})}}
```

-- a proxy for "may I bind below 1024" that asks about a *user name*.
Plan 9 has no root, so `notRoot` is true and the test runs, while the
capability it stands in for is held all the same. The test even
anticipates it in its own failure message: *"are you running as SU?"*.
That would make these two permanent and correct failures, not ours.

**Not asserted, because the last step is about port occupancy at the
start of a run and nothing here measured it.** One command settles it,
with no rebuild -- in the APExp shell, as glenda, on a machine with no
suite running:

```
tclsh
% socket -server {apply {{c a p} {}}} 1
```

A channel back means glenda can announce port 1, the constraint is the
problem, and the two go in the "not ours" list beside `unixFCmd-1.1`. An
error means the story above is wrong and the cause is still open.

**The rule this pays for**: *a test that newly fails may be a test that
was previously passing for the wrong reason*. This file already has the
converse -- "a rising failure count after new tests become runnable is
newly measured, not newly broken" -- and this is the same coin. Before
attributing a new failure to the change in hand, ask what the test
actually asserts and whether anything else in its file moved.

#### The probe gave a third answer, and it was the useful one

The question was whether glenda can announce a privileged port, with two
expected answers: a channel back (the `notRoot` constraint is the
problem) or an error (the story was wrong). What came back was neither:

```
% socket -server {apply {{c a p} {}}} 1
couldn't open socket: address already in use
```

**The port is held right now**, in a fresh `tclsh`, with no suite
running. So the capability question is still unanswered -- and something
better was answered instead.

**Follow the sequence.** The last suite run's own `socket_inet-5.1` bound
port 1 (which is why it failed), and its body then calls `close $msg`.
The port is still announced afterwards. So `close()` on a listening
socket releases nothing, and **the two tests had been passing for the
wrong reason all along**: a leftover listener from an earlier run was
refusing the bind, not the system. The run that "broke" them was the
first one to find the port free.

That also closes the question of whether the `EPERM` -> `EACCES` change
did it. It did not, and the three reasons stand: both bodies return a
fixed string whichever way the error goes, Tcl's server path tests only
`EADDRINUSE`, and `bind()`'s fallback is gated on `EPLAN9` which neither
errno is. **The probe was worth running even though it refuted its own
two options** -- an answer outside the menu is still an answer, and this
one named a bug that had been sitting in the "open hazards, not
measured" list for months.

#### close() on a listening socket freed nothing, and the reason is the pipe

`listen()` does not keep the socket in the calling process.
`ap/network/listen.c` replaces the descriptor with a **pipe**, so that
`select()` can work on it, and forks a child that holds the real network
descriptor and blocks in `open("/net/tcp/N/listen")`. So:

- the parent's `close()` shuts a pipe;
- the announcement is held by a descriptor in **another process**;
- nothing connected the two.

`_killmuxsid` kills that process group from an `atexit` handler, and it
is not enough twice over. A program that closes a listener and keeps
running holds the port for its whole life -- which is exactly what Tcl's
socket tests do. And a run that ends any way other than `exit()` -- an
interrupt, a note, a fault -- runs no `atexit` handler at all. **That is
where "over a hundred leaked `listenproc` processes accumulate across
runs" came from**, an item that had been in the notes without anyone
connecting it to a test result.

`_sock_listenpid.c` records the listening pid against the descriptor;
`close()` calls `_sock_killlisten()`, which is a no-op for every
descriptor that is not one.

**The owner is recorded beside the pid, and that is not belt and
braces.** The table is inherited by every fork, exactly like the atexit
handlers, so a child closing an inherited descriptor would kill its
PARENT's listener. `_buf.c` has this written on it in capitals after it
cost a round:

> ONLY THE PROCESS THAT FORKED THE TIMER MAY KILL IT

-- the asymmetry there meant any forked child leaving through `exit()`
took the parent's timer with it, and every blocking `select()` that
needed a timeout waited for ever. Same table, same trap, same guard:
`_sock_killlisten` forgets the entry either way and kills only if
`getpid()` matches the recorded owner.

`SIGKILL` rather than `SIGTERM`, because the listener is blocked in an
`open()` that will not return until a call arrives. `_closebuf` kills
its copy processes the same way.

**`network/mkfile` had no `HFILES` at all**, so a change to
`../include/priv.h` -- which defines `struct Rock`, shared by every file
in that directory -- rebuilt nothing. Added, because the shape of that
failure is recorded here already and is unattributable when it happens.

**No struct changed**, so this does not need `mk distclean`: a rebuild of
libap and a relink of whatever uses it is enough.

**Prediction, and it has two parts.** `listenleak-test` should go from
failing section 1 to 0 failures -- that is the whole claim. What happens
to `socket_inet-5.1`/`5.3` is a *separate* question and I expect them to
**stay failing**, because the leftover that was masking them is what this
removes: with ports genuinely free, the tests will honestly report
whether glenda may announce port 1, and on a 9front terminal she is the
host owner and may. That would put them with `unixFCmd-1.1` as
upstream's constraint asking the wrong question -- `notRoot` tests a
*user name* as a proxy for a capability. **A fix that makes two tests
fail honestly instead of passing dishonestly is still the right fix**,
and the count going the wrong way is not evidence against it.

**The leftover on port 1 is still there and must be cleared before any
of this can be measured**, or the first run after the fix will still see
the port held by a process that predates it. A reboot of the VM, or
killing the leftovers, before the next suite run.

#### The listener kill froze the suite, and the bug was mine

The run stopped inside `chanio.test`, the fourteenth file, with low CPU
-- a block, not a spin. Thirteen files had reported; the last failure
printed was `chan-io-29.27` and the previous complete run has
`chan-io-32.7` next, so it stopped somewhere in between. **A child's
stdout is a pipe and block buffered, so that is a lower bound and not a
location**; the first socket test after 29.27 is `29.34`, which makes a
server socket, accepts one connection and closes both ends.

Everything about the shape says it was the change in hand: the previous
run finished, one commit stands between them, and that commit made
`close()` send a SIGKILL.

**And it was, by a route worth writing down.**

```c
static int
note(int pid, char *msg, char *fmt)
{
	f = open(pname, O_WRONLY);
	...
	close(f);		/* <- libap's close() */
}
```

`kill()` opens `/proc/N/note` and **closes it**, and `close()` now calls
`_sock_killlisten()`. So every kill from here re-enters the function on
whatever descriptor number that open happened to get.

That would be harmless on its own. What made it dangerous is that **the
table was keyed on the descriptor NUMBER and nothing ever cleared a
retired one.** `close()` clears its entry, but a number can also be
retired by `dup2()`, or by a raw `_CLOSE()` that does not go through
`close()` -- libap does both. So a stale pid could sit against a number
that had since come back as something else entirely, and the next
`close()` of that number would SIGKILL a live, unrelated process.

**The symptom is one this file has already described, from the other
direction.** `_buf.c`:

> ONLY THE PROCESS THAT FORKED THE TIMER MAY KILL IT ... the asymmetry
> meant any forked child leaving through `exit()` took the parent's
> timer with it, and `timerpid` stayed > 0 afterwards so `_resettimer()`
> went on signalling a corpse -- no timeout ever firing again, and every
> blocking `select()` that needed one waiting for ever.

Kill the timer process, or a copy process, and you get a freeze at low
CPU. Same family, reached by a different route, one round after writing
the owner guard *specifically because* that precedent was in view. **The
guard I copied was the one for the case I had thought of; the table's
key was the part I had not.**

**Two changes, and the first is the real one.**

- **The entry is keyed on the FILE.** `dev`/`ino` are recorded beside
  the pid at `listen()` time and checked with `fstat()` before the kill.
  A number that has come back as something else does not match, is
  cleared, and kills nothing. A missed kill leaks a port; a wrong kill
  stops the machine, so the check fails towards doing nothing.
- **A re-entrancy flag**, so that the `kill()` -> `close()` ->
  `_sock_killlisten()` path cannot loop at all. The dev/ino check already
  makes it harmless; this makes it impossible, so that the reasoning
  needed to see it is safe does not have to be redone by the next reader.

**What this does not prove.** The mechanism is real and is a bug whatever
else is true, but nothing here has *measured* that it was the freeze --
the run that froze is gone and the evidence is circumstantial (position,
timing, one commit). So the next run is not "the suite": it is
`chanio.test` alone, which costs seconds and is where it stopped.

- **`tcltest chanio.test -singleproc 1 -verbose t`** -- if it completes,
  the file is clear and the suite is worth running. If it hangs, the
  `-verbose t` output names the test, which is what the harness note in
  this file has been asking for all along, and the diagnosis above is
  wrong or incomplete.
- `listenleak-test` should be 0 failures either way; it exercises the
  kill path without any of Tcl around it.

**And the rule, which is the general form of the owner guard rather than
a new one**: *a table keyed on a descriptor number needs an entry
invalidated when the number is retired, and there is no single place
that happens.* `_fdinfo` gets away with it because every path that
retires a descriptor updates it; anything alongside `_fdinfo` that does
not is a stale entry waiting to be believed. Key on something the file
itself carries, or be cleared by the same code that clears `_fdinfo`.

#### The harness named it: chan-io-29.34, and the C probe now asks it directly

`-verbose t` on `chanio.test` alone gave what four rounds of totals could
not:

```
---- chan-io-29.34 start
<nothing>
```

That is the first socket test after `29.27`, which is what the position
argument had predicted, and it is the last `start` line printed -- so
this time the name is the answer rather than a lower bound.

**Reading the test is what makes it actionable**, and the order of its
last four statements is the whole thing:

```tcl
writelots $cs $l        ;# 2000 lines into a non-blocking client
chan close $cs
chan close $ss          ;# CLOSE THE LISTENER
vwait x                 ;# wait for the ACCEPTED connection to drain and see EOF
```

The second `vwait` runs **after** the listening socket is closed, and
what it waits for is the *accepted* connection. So the question is
exactly: **does ending the listening process disturb a connection that
has already been accepted?** Nothing before this round made `close()`
end a process at all, so this is new behaviour meeting a test written
for the old.

`listenleak-test` section 3 is that question with no Tcl around it:
listen, connect, accept, read a message (**a control** -- without it, a
failure after the close would not distinguish "the close broke it" from
"it never worked"), close the listener, read another message, close the
client, expect end of file.

**It times out rather than hangs**, ten seconds per blocking call, each
behind a named stage printed from the handler with `write(2)`. The thing
under test hangs when it goes wrong, and a test that hangs reports
nothing; the rule in this file is already that *a freeze and a timeout
are different evidence*, and this one is built to produce the second.
0 failures on glibc.

**Two smaller things found while reading, neither of them the hang.**
`_sock_killlisten` was called after `close()` had already zeroed
`_fdinfo[d].flags`; `fstat()` goes to the descriptor rather than to
`_fdinfo`, so it still worked, but the call now happens first, before
anything about the descriptor is taken apart. And the `setjmp.h`/unused
flag left over from drafting are gone.

**What is NOT known, and it matters before the next run.** Whether the
frozen `chanio.test` above ran against a libap containing the `dev`/`ino`
fix, or against the build that froze the suite. Nothing in the output
says, and *a measurement of a build that does not contain the change
measures nothing*. If it was the old build, this run has told us the
location and nothing about the fix.

So: `listenleak-test` first, on a build that certainly contains the fix.
0 failures means the kill is innocent of `29.34` and the hang is
somewhere else in that test; a TIMED OUT line names the statement, and
if it is the one after the close then ending the listener does break an
accepted connection and the whole approach needs rethinking rather than
patching.

#### Still held after the rebuild, and two guesses in a row were wrong

```
After libap rebuild
  note the system chose port 48153
  note listen -> errno 42 (Address in use); plan 9 says: address in use
  note the port is still held by SOMETHING after the socket was closed
  FAIL the port can be bound again once the socket is closed
2 failure(s)
```

**Two things to read off that before anything else.**

First, **section 3 never printed**, so the binary was built from the test
as it stood before section 3 was added -- which dates the libap under it
too. The `chan-io-29.34` question is still unasked. *A measurement of a
build that does not contain the change measures nothing*, and the way to
notice it here was that a section which should have printed a header did
not print one at all. Numbering the sections is what made that legible.

Second, **it is `listen()` that reports "address in use", not `bind()`**.
On Plan 9 the announcement happens in `listen()`, so the failing call
names the right place; nothing is wrong with the test's reading.

**And the port is still held with the kill in place, which refutes the
obvious diagnosis rather than confirming it.**

Two mechanisms were argued for it and both were wrong, and the way they
were wrong is the same way:

- *"`_sock_killlisten` runs after `close()` has zeroed `_fdinfo`, so
  `fstat()` fails and the guard declines."* `fstat()` goes through
  `_dirfstat()`, a raw call on the descriptor, not through `_fdinfo`. It
  was moved to the front of `close()` anyway, which is tidier, but it
  was not this.
- *"`_closebuf` tears the descriptor down first."* `_closebuf` kills the
  copy process and does not close the descriptor at all.

Both were read out of the source and both were plausible. **That is two
rounds spent on mechanism where one printed line would have settled it**
-- which is the oldest rule in this file, *print what the machine says
rather than what the code implies*, broken twice in succession while
being quoted.

So `$APEXP_LISTENDEBUG` now makes `_sock_listenpid.c` say what it did,
one line per decision, on standard error:

```
listenpid: recorded a listener fd=3 pid=1234
listenpid: killing the listener fd=3 pid=1234
listenpid: ...kill returned 0
```

or one of `close of a descriptor with no listener`, `STALE: fstat says
this is a different file now`, `NOT OURS: recorded by another process`,
`RE-ENTERED: declining to kill`, `...and kill FAILED`. `write(2)` and a
hand-rolled number rather than stdio, because stdio in this file would
pull the whole of it into `close.o`, which every program links.

**The four answers and what each one means:**

- **nothing printed at all** -- `_sock_listenpid.o` is not in the
  library, or `close()` is not calling it; a build question, not a
  logic one.
- **`recorded` but no `killing`** -- the entry is not surviving to the
  close. `STALE` says the descriptor changed identity between `listen()`
  and `close()`, which would mean the pipe is not the thing to key on.
- **`killing` then `kill returned 0`, and the port still held** -- the
  listener is not the only holder of the announcement, and the whole
  approach is wrong rather than buggy. That is the outcome that says
  revert.
- **`kill FAILED`** -- the pid is not reachable; look at what `kill()`
  does with a process in another note group.

No prediction. Three have been offered on this bug and the machine has
refuted each one; the next line should come from the VM, not from here.

#### Section 3 passes, and that is not the good news it looks like

With the tree actually pulled, section 3 ran and passed all three:

```
--- 3. close the LISTENER while a connection is in use ---
  PASS a message arrives before the listener is closed
  PASS ...and one still arrives after it is closed
  PASS the accepted connection reports end of file
```

**But sections 1 and 2 still FAIL -- the port is still held -- and those
two facts together do not say what they appear to.** A PASS in section 3
has two explanations: the listener was killed and the accepted
connection was undisturbed, *or* the listener was never killed at all.
It can **convict** the kill and never clear it.

And sections 1 and 2 are exactly what say whether a kill happened. They
failed. So the reading is **"no kill happened"**, not "the kill is
harmless" -- and section 3 is currently evidence about nothing.

That is this file's own rule, *a check whose negative result has two
explanations is not a check*, met from the positive side, in a test
written three messages ago to avoid precisely this class. The section
now prints the ambiguity in its own output rather than leaving a reader
to reconstruct it:

```
  note a PASS above means the kill did not break this
  note connection -- OR that no kill happened. Sections 1
  note and 2 are what tell those apart; if they FAILED,
  note nothing was killed and this section proves nothing.
```

**A test that can pass for two reasons should say so where the result is
read, not where the source is read.** The comment at the top of the file
had said it; the output had not, and the output is what gets pasted into
a message.

**The code path has been re-read and is right** -- `_sock_listenpid.$O`
is first in `network/mkfile`'s `OFILES`, `pid` is the parent's fork
return, `_sock_setlisten(fd, pid)` is in the `default:` arm against the
socket descriptor. So there is nothing left to find by reading, which
was the conclusion two rounds ago as well.

`APEXP_LISTENDEBUG=1 ./listenleak-test` is the whole of the next step.

#### Nothing printed, and that was ambiguous too: a mark for the library

`APEXP_LISTENDEBUG=1 ./listenleak-test` produced no `listenpid:` line at
all -- and the new `note a PASS above...` lines from the commit before
it were missing too, which is the tell.

**`pcc -o listenleak-test listenleak-test.c` relinks the program against
the INSTALLED library.** A test rebuilt from a freshly pulled source can
therefore be running library code from days earlier, and nothing in its
output says so. That is the same trap as the header search order, and it
has now cost two rounds in a row on the same bug: once when a numbered
section printed no header, and once when a debug line that should have
appeared did not.

**So the library gets a mark, exactly as `<limits.h>` did.**
`_sock_listenmark()` returns 2, the test prints it first, and the number
is bumped whenever this file changes in a way a test needs to see:

```
--- 0. which libap is linked in ---
  note libap listen bookkeeping: mark 2 (this tree is 2)
  note if that is not 2, `mk install' has not reached
  note the installed library and nothing below is
  note about the code you just pulled
```

**A link error is also an answer**, and a blunter one: an undefined
`_sock_listenmark` means the installed libap predates the file entirely.

*`deeppath-test`'s header marker refuted a wrong diagnosis about
architecture directories in one run. The generalisation was available
then and was not taken: **anything a test measures that comes from
somewhere other than its own source should say where it came from.**
A header, a library, a build -- the same rule, and this is its third
instance.*

**What is and is not known, plainly.** Whether a kill ever happens is
still unmeasured; every run so far has been against a library whose
provenance was not established. The mark is what ends that class of
round.

#### The debug line refuted my own stop-condition: kill() posts a note, it does not wait

```
listenpid: recorded a listener fd=4 pid=7898
  note the system chose port 38649
listenpid: killing the listener fd=4 pid=7898
listenpid: ...kill returned 0 fd=4 pid=7898
  note listen -> errno 42 (Address in use)
  FAIL the port can be bound again once the socket is closed
```

**The kill happens, succeeds, and the port is still held on the very next
bind.** I had written down beforehand that this exact outcome -- "kills
successfully and the port is still held" -- means *the approach is wrong
rather than buggy* and the hook should be reverted.

**It was the wrong stop-condition, and the reason is in the word
"posts".** `kill()` writes a note to `/proc/N/note` and returns; the
target dies asynchronously. The listener is blocked in
`open("/net/tcp/N/listen")`, and it has to notice the note, unwind, and
have its descriptors closed before the announcement goes. `close()`
returned long before any of that, and the test re-bound immediately.

So the sequence is not "kill, then the port is free". It is "kill, then
*eventually* the port is free", and nothing was waiting.

**The fix is already in this library, two hundred lines away**, and has
been all along. `plan9/_buf.c`:

```c
for(i=0; i<10 && kill(b->copypid, SIGKILL)==0; i++)
	_SLEEP(1);
```

That loop is not a retry, it is a **wait**: it ends when `kill()`
*fails*, which is when the process is gone. `_sock_killlisten` does the
same now, with the same bound, so a wedged listener costs ten
milliseconds rather than a hang.

*This tree's notes already contained the line "`_closebuf` killing a copy
process up to ten times without waiting for it to die", filed under open
hazards. That reading was wrong twice over: the loop **is** the wait, and
it was the missing half of the code I was writing while the description
of it sat in the same file.*

**Three lessons, and the first is about how the round was run.**

**Writing a prediction down is worth as much when it is wrong as when it
is right -- but only if it is a prediction about the OBSERVATION, not
about the conclusion.** "Kill succeeds and the port is held" was a fine
thing to predict. "...therefore revert" was not: it smuggled a mechanism
("the listener is not the only holder") into what looked like a reading
rule, and if the debug output had arrived without the sequence being
re-examined, a working fix would have been thrown away on the strength of
my own earlier sentence.

**An asynchronous call that returns 0 has told you it was accepted, not
that it was done.** `kill`, and the same shape in every note, signal and
interrupt on this system.

**When a library already does the thing you are adding, copy the whole
idiom, not the call.** `_closebuf` was cited three commits ago for
`SIGKILL` -- the right signal was taken from it and the loop around it
was left behind.

**Prediction, and this one is about the observation only.**
`listenleak-test` sections 1 and 2 go to 0 failures: the port is free
once the listener is actually gone. Section 3 stays passing and now
means something, since a kill demonstrably happens. **`chan-io-29.34`
remains genuinely open** -- the earlier freeze was measured against the
descriptor-keyed version, and nothing since has retested it. Run
`chanio.test -singleproc 1 -verbose t` before the suite.

#### The leak is fixed, confirmed, and the freeze moved 115 files later

```
--- 0. which libap is linked in ---
  note libap listen bookkeeping: mark 3 (this tree is 3)
--- 1. close a listener, then take its port back ---
  PASS the port can be bound again once the socket is closed
--- 2. five times over, which is what makes it sharp ---
  PASS five close-and-rebind rounds all succeeded
--- 3. close the LISTENER while a connection is in use ---
  PASS a message arrives before the listener is closed
  PASS ...and one still arrives after it is closed
  PASS the accepted connection reports end of file
0 failure(s)
```

**Mark 3, so the library under test is the one that was pulled** -- the
first run in this whole sequence where that was not in question, and the
marker is why. Sections 1 and 2 pass, so a kill demonstrably happens and
the port is demonstrably released; section 3 therefore *means* something
now, and what it means is that ending the listener leaves an accepted
connection alone.

`chanio.test` passes too, so the `chan-io-29.34` freeze is gone. It
belonged to the descriptor-keyed version, as suspected but not
previously shown.

**The prediction held, and it is worth noting which kind it was**: it
predicted the OBSERVATION (sections 1 and 2 go to zero) and said nothing
about what to conclude. The three before it, which bundled a conclusion
in, were all wrong.

**The suite now freezes in `socket.test`, file 129 of 167.** It was file
14 before. No marker, no `Total`, and the last line in the log is the
file name with nothing after it.

**Two candidates, and they are not the same thing:**

- **A regression from the kill.** `socket.test` is full of
  `socket -server` followed by `close`, which is exactly the new code
  path, and the file completed in the last full run.
- **A hang that was never reachable before.** This is the first run in
  which ports are actually released. Tests that used to fail fast with
  `EADDRINUSE` -- against a leftover listener from a previous run --
  now get their socket and proceed into code nothing here has ever
  executed. *A fix that makes a process reach code it never reached
  before can expose anything on that path* is already a rule in this
  file, and it was written for exactly this shape.

**The next run is one command and it should carry the debug lines**, so
that the listener decisions interleave with the test names and the last
`recorded`/`killing` before the silence is visible:

```
APEXP_LISTENDEBUG=1 tcltest socket.test -singleproc 1 -verbose t
```

`-verbose t` names the test; `APEXP_LISTENDEBUG` says whether a listener
was being killed when it stopped, and which one. Nothing is predicted
about the cause -- only that those two lines together will name it.

#### socket_inet-2.11: the debug lines put it exactly, and named what every section missed

```
listenpid: killing the listener fd=10 pid=12945
listenpid: ...gone fd=10
listenpid: recorded a listener fd=10 pid=12950
---- socket_inet-2.11 start
listenpid: close of a descriptor with no listener fd=5   (x8)
<nothing>
```

**Three facts, none of them a guess.**

**tcltest runs `-setup` BEFORE it prints `---- $name start`.** Its own
comment says so -- "Verbose notification of $body start" -- so the second
`recorded` line is *2.11's own* `socket -server accept 0`, and the
silence is in the **body**. The body's first wait is `vwait sock`: the
connection is never accepted.

**The `close ... fd=5` flood is the event loop, not a bug.** `kill()`
opens `/proc/N/note` and closes it, so every timer reset from `select()`
prints one line. Eight of them, then they stop -- which is what a
process entering a wait it never leaves looks like from here. *That is
the debug output paying for itself twice: once for what it says and once
for what its stopping says.*

**And the descriptor number came back.** The previous test's listener was
at `fd=10`, was killed, and 2.11's listener is `fd=10` again.

**What every section of `listenleak-test` missed, and it is the same
gap three times over.** Section 1 closes a listener and rebinds; section
2 does that five times; section 3 accepts once on a *first* server.
**Not one of them accepts a connection on a SECOND server made after a
first was killed.** The descriptor number comes back, and with it
whatever the library keeps per descriptor -- and killing a listener is
new, so what it leaves behind has never been exercised twice.

Section 4 is three full rounds of listen / connect / accept / exchange /
close, each behind a named stage and the ten-second alarm. 0 failures on
glibc; three rounds, three ports, three exchanges.

**The rule this exposes about the test, not the library:** *a test built
from a symptom tests the symptom.* Sections 1 and 2 came from "the port
is not released", section 3 from "does the kill break an accepted
connection" -- both real questions, and between them they never made the
library do the same thing twice. **When a change adds an operation
(here, ending a process), the second use of the thing it acted on is the
case to write, not the first.**

**No prediction about the cause.** If section 4 hangs on round 1, the
state left behind by killing a listener is the thing to find, and *When
a struct is recycled, reset every field that means something* is already
in this file. If it passes all three, the reduction is wrong and
`socket_inet-2.11` needs its own next step -- it was already FAILING
before this change (`a: b: c:one` for `a:one b: c:two`, a timing
result), so the hang is new but the test was never healthy.

#### Section 4 passed, which refuted the reduction rather than the library

Mark 4, and sections 1 to 4 all pass: three rounds of listen / connect /
accept / exchange / close, three ports, no hang. **So the plain C
sequence is not what `socket_inet-2.11` does**, and the reduction was
wrong -- the second `recorded` on a reused `fd=10` was a true
observation that I turned into the wrong experiment.

**The difference is one line, and it is the whole mechanism.** 2.11 does
not call `accept()` and wait. It uses `socket -server` with Tcl's event
loop, so the listening socket goes to **`select()`**, and `vwait sock`
returns only when select says it is readable and the accept callback
runs.

In libap a listening socket is a **pipe**, and `select()` on a pipe is a
**copy process** reading it (`plan9/_buf.c`). A blocking `accept()`
reads that pipe *itself* and never involves the copy process at all. So
section 4 exercised everything except the machinery that 2.11 depends
on -- and killing a listener closes the pipe's write end underneath a
running copy process, which is new, and then the descriptor is reused
for the next server.

Section 5 is section 4 with `select()` before the accept, and **select's
own timeout reports the failure**: "the listening socket never became
readable" is a better sentence than "the alarm fired", and it separates
a socket select ignores from a process stuck elsewhere. 0 failures on
glibc.

**The rule, and it is a sharper form of one already here.** *A test built
from a symptom tests the symptom* was the last round's lesson, and
section 4 obeyed it and still missed. The sharper version: **reproduce
the CALL the failing code makes, not the outcome it wants.** 2.11 wants
a connection accepted; it gets there through `select()`, and an
`accept()` that waits by itself is a different program with the same
result. The tree already says *replicate the code in the tree, line by
line, not the code you remember* -- this is that rule pointed at the
test's own shape rather than at a function's body.

**This costs no libap rebuild** -- `pcc -o listenleak-test
listenleak-test.c` and run -- which is worth noting, because the
measurement was available cheaply for two rounds and was not taken.

**Still no prediction about the cause.** If round 0 of section 5 already
times out, the copy-process path is broken generally and the kill is
incidental. If round 0 passes and round 1 times out, it is the state
left behind by killing a listener under a live copy process, and the
order in `close()` -- `_sock_killlisten` before `_closebuf`, which this
round's version does and the pre-`chan-io-29.34` version did not -- is
the first thing to look at.

#### Section 5 passed too: stop reducing, look at the process

Mark 4, sections 1 to 5 all pass -- including three rounds of
listen/connect/**select**/accept/exchange/close. **Two reductions in a
row have failed to reproduce `socket_inet-2.11`**, and that is itself
the finding: whatever the test does, it is not the sequence of calls,
and guessing a third shape would be the fourth guess in a row.

*This tree's own note says `ratrace` "names a failing system call
outright where elimination takes rounds", and that elimination is
exactly what the last two rounds were.*

**What reading DOES give, cheaply, is the place to look.** 2.11's body
is

```tcl
set s2 [socket $localhost port]
vwait sock
```

with no `after` outstanding, so `select()` is called with **no timeout**.
In `_buf.c` that path is:

```c
if(timeout) { ... _resettimer(); }	/* NOT taken */
mux->selwait = 1;
unlock(&mux->lock);
fd = _RENDEZVOUS(&mux->selwait, 0);	/* blocks until a COPY PROCESS wakes it */
```

**No timer is armed, so the only possible wakeup is a copy process.**
That is precisely what the debug output shows from outside: the
`close ... fd=5` lines are timer resets, they tick eight times, and then
they stop -- because the select that never returned is the one that
armed no timer.

So the question has narrowed to: **the copy process for 2.11's listening
socket never reports it readable.** And there is an open hazard in this
file, recorded and never measured, of exactly that shape: *the lost
wakeup in `select()`'s rendezvous -- a copy process reaching EOF before
the parent sets `selwait`*. Killing a listener makes a pipe reach EOF at
a moment nothing here has produced before.

**The predecessor matters and is worth naming.** `socket_inet-2.10` is
"close on accept, accepted socket lives": it closes the **server socket
from inside the accept callback**. So the listener at `fd=10` is killed
at an unusual point, its copy process is torn down, and 2.11 takes the
same descriptor number for a new server immediately afterwards.

**One look should settle which of the two it is**, and `ps` alone may do
it. With the suite frozen:

- **`Rendez`** -- the process is in `_RENDEZVOUS(&mux->selwait, 0)`,
  which is the lost wakeup: select is waiting for a copy process that
  will never come.
- **`Pread`** or **`Open`** -- it is blocked in a call instead, and the
  rendezvous reading is wrong.
- **`Broken`** -- it faulted, and everything above is beside the point.

`acid <pid>` + `lstk()` gives the frame outright, which is how the
`listenproc` leak was named in the first place.

**No prediction.** Three mechanisms have been guessed on this bug and
the machine refuted each one; the next line comes from `ps`.

#### The stack: select's rendezvous, confirmed -- and the timer is the thing that is missing

```
_RENDEZVOUS ... syscall/_RENDEZVOUS.s:6
select(rfds=..., timeout=0x7fffffde4a0, nfds=0xb, ...)+0x30e  _buf.c:544
    t=0x1000000c8
TclpWaitForEvent(timePtr=0x6930c0) ... tclSelectNotfy.c:844
Tcl_WaitForEvent() ... Tcl_DoOneEvent(flags=0xfffffffd) ...
Tcl_VwaitObjCmd(...) ... tclEvent.c:1734
```

`_buf.c:544` is `fd = _RENDEZVOUS(&mux->selwait, 0)`, which is the line
named in advance. **But the reading that went with it was wrong**, and
the stack says so in its own arguments: `timeout` is NOT null and `t` is
`0xc8` -- 200 milliseconds. So this is not the no-timer path at all. The
`if(timeout)` arm was taken, `_resettimer()` ran, and **a timer was
armed that never fired**.

*Predicting the line and the mechanism together, and getting the line
right, is not the same as being right. The arguments in the frame are
what corrected it.*

**And `ps` had already said the same thing, before the stack was taken.**
A live timer process sits in `_SLEEP(mux->waittime)`, which shows as
`Sleep`:

```
12908  5644K Rendez   tcltest    <- the interpreter, in select
12935  2800K Rendez   tcltest
12936  2784K Open     tcltest
12938  2788K Pread    tcltest
12939  2800K Pread    tcltest
12950  5636K Open     tcltest    <- 2.11's listener, where it should be
12952  5644K Pread    tcltest
```

**Not one process is in `Sleep`.** Seven processes and no timer among
them. *That was on the screen a round before the stack, and reading it
would have cost nothing -- `ps` states are already documented in this
file as the cheapest evidence there is.*

**This file already describes this exact failure**, in `_killtimerproc`:

> ...`timerpid` stayed > 0 afterwards so `_resettimer()` went on
> signalling a corpse -- no timeout ever firing again, and every
> blocking `select()` that needed one waiting for ever.

**Two candidates, and `12935` distinguishes them.** It is 2800K and in
`Rendez`, which is the size of the small forked helpers:

- **the timer is DEAD** and `timerpid` is stale, so `_resettimer()`'s
  `kill(timerpid, SIGALRM)` signals nothing -- the recorded failure,
  reached by some new route;
- **`12935` IS the timer**, stuck in its STARTUP rendezvous,
  `while(_RENDEZVOUS(&timerpid, 0) == (void*)~0) ;`, never reaching the
  sleep loop at all. A `SIGALRM` arriving there interrupts the
  rendezvous, the `while` retries, and it can sit there for ever.

`acid 12935` and `lstk()` says which. If the frame is `_timerproc`, it
is the second.

**And the last `close ... fd=5` line in the debug output is this very
select's `_resettimer()`** -- `kill()` opening `/proc/N/note` and
closing it. The instrumentation recorded the moment the timer was armed;
what is missing after it is the tick.

#### 12935 is a second interpreter, and the timer simply is not there

`acid 12935` gives the same stack as 12908, all the way down to
`Tcl_MainEx` and `tclAppInit.c:99`: it is another full interpreter --
one of the helpers `socket.test` spawns with `exec [interpreter]` --
also sitting in `vwait`. Its `select` has `timeout=0x0` and
`t=0x7fffffff`, a genuinely unbounded wait, where 12908's has
`timeout != 0` and `t=200`.

So neither `Rendez` process is the timer, and **of seven `tcltest`
processes not one is in `Sleep`**, which is where `_SLEEP(mux->waittime)`
puts a live timer. **12908 armed a timer that does not exist.**

**What killed it is still not known, and I stopped looking.** Two
readings were tried and both hold up as *correct code*: the child of
`fork()` calls `_detachbuf`, which sets `timerpid = -1` as well as
`_mainpid = -1`, so `_killtimerproc`'s `timerpid > 0` guard fails in a
child and the documented "child took the parent's timer" route is shut.
That would have been the seventh mechanism argued from source on this
bug, after six were refuted.

**So the change is a repair rather than a guard against a cause.**
`_resettimer()` was

```c
static void
_resettimer(void)
{
	kill(timerpid, SIGALRM);
}
```

-- and the comment forty lines above it already said what that costs
once `timerpid` names a corpse: *no timeout ever firing again, and every
blocking `select()` that needs one waiting for ever*. It now notices and
makes another:

```c
if(kill(timerpid, SIGALRM) >= 0)
	return;
_apdbg("resettimer: the timer process is gone, restarting", "was", timerpid, 0, 0);
timerpid = -1;
_timerproc();
```

**This is defensible without knowing the cause, and that is the point.**
The failure is total -- nothing in that process ever times out again --
the detection is exact (`kill` fails with ESRCH on a process that is
gone), and the recovery is local. The worst case is a leaked second
timer if `kill` ever fails on a live process, which is bounded and far
better than a hang. It is *not* "invent semantics to make a test pass":
the semantics are unchanged, a resource is replaced.

**And the debug instrument moved to where anything can reach it.**
`$APEXP_LISTENDEBUG` was written into `network/_sock_listenpid.c`, and
the very next question arrived in `plan9/_buf.c` where it was not.
`plan9/_apdbg.c` is now the one line-printer -- `write(2)`, no stdio,
because it is called from `close()` and `select()` which every program
links -- and it takes **labels from the caller**, so a line reads
`fd=4 pid=7898` and not `a=4 b=7898`. `$APEXP_DEBUG` and the old
`$APEXP_LISTENDEBUG` both switch it on; renaming an environment variable
mid-investigation costs a round for nothing.

*The general form: an instrument built for one question should be put
where the second question can reach it, because there is always a
second question.*

**Prediction, observation only.** With mark 5 installed,
`resettimer: the timer process is gone, restarting` appears in a
`APEXP_LISTENDEBUG=1` run if and only if the timer really was dead. If
it appears and `socket_inet-2.11` then completes, the diagnosis holds
and what killed the timer becomes a separate, non-blocking question. If
it never appears, the timer is alive and `_resettimer` is not the
problem -- and the next thing to ask is why a live timer's `SIGALRM`
does not wake the select.

#### socket.test completes: the repair worked, and one grep says whether the diagnosis did

```
Tests ended at 2026-09-18 16:10:02 +0200
all.tcl:  Total 114  Passed 54  Skipped 41  Failed 19
Files with failing tests: socket.test
```

Same command that froze at `socket_inet-2.11` a round ago --
`APEXP_LISTENDEBUG=1 tcltest socket.test -singleproc 1 -verbose t` --
and the only difference is mark 4 to mark 5, which is `_resettimer()`
noticing a dead timer and forking another. The file runs to the end.

**But the run does not yet say WHY, and the distinction matters.** The
visible tail is all `close of a descriptor with no listener fd=5 pid=0`,
which is `kill()` in `_resettimer` opening `/proc/N/note` and closing
it -- i.e. **resets that SUCCEEDED**. The repair only acts when `kill`
fails. So one grep decides between two readings:

- **`resettimer: the timer process is gone, restarting` appears** -- the
  timer really was dead, the repair is what unblocked it, and the
  diagnosis built from `ps` (no process in `Sleep`) and from the stack
  (`t=200` with nothing to fire) was right.
- **it never appears** -- the timer was alive the whole time and
  something else in mark 5 changed the timing. `_apdbg` writes to
  standard error from inside `close()` and `kill()`, which is a real
  timing change, and a race papered over by a `write(2)` is not fixed.

*That second possibility is why the grep is worth a line rather than
assuming. A hang that stops reproducing is the easiest thing in this
whole file to believe for the wrong reason -- and this file already
records two tests that passed for the wrong reason and one fix that was
nearly reverted on a mis-stated stop-condition.*

**What is certain either way**: the file completes, `Failed 19` is a
number rather than a silence, and the suite can be run again.

#### Confirmed: the timer died twice, and the repair is what unblocked socket.test

```
$ grep resettimer /tmp/socket.out
resettimer: the timer process is gone, restarting was=18102
resettimer: the timer process is gone, restarting was=18148
```

**Twice in one run of `socket.test`.** So the timer really was dead,
`_resettimer()` really was signalling a corpse, and the chain --
`ps` showing no process in `Sleep`, then `acid` showing `select` blocked
at `_buf.c:544` with `timeout != 0` and `t = 200` in its own frame --
was right end to end. The file completing is the repair, not a timing
accident from `_apdbg`'s writes.

*The grep was worth its round. Without it the honest statement would
have been "the hang stopped reproducing", which is the weakest sentence
in this whole file and appears in it twice already.*

**What kills the timer is now the open question, and it is no longer
blocking anything.** Two candidates were read and both hold up as
correct code: `fork()`'s child runs `_detachbuf`, which clears
`timerpid`, `_muxsid` AND `_mainpid`, so neither `_killtimerproc` nor
`_killmuxsid` can fire in a child; and the processes made with `_RFORK`
rather than `fork()` -- the copy processes, the listener, the timer
itself -- all leave through `_exit(0)`, which runs no `atexit` handler
at all.

So instead of an eighth mechanism argued from source, the next debug run
answers it. `_timerproc()` now prints when a timer is forked and by
whom, and `_killtimerproc` prints when it fires and from which process:

```
timer: forked pid=18102 by=17994
timer: _killtimerproc is ending it pid=18102 by=???
```

- **`_killtimerproc` appears** -- the handler is the killer, and `by=`
  names the process that ran it, which settles whether a guard is wrong
  or a `_mainpid` is stale.
- **it never appears** -- the timer is dying some other way entirely:
  a note aimed at a pid that was recycled, or the process group, or a
  fault. `_sock_killlisten`'s ten-note loop is the obvious suspect to
  look at then, since it is the only new source of SIGKILLs in the
  tree.

**This is mark 6 and it is instrumentation only** -- no behaviour
changes -- so it is safe to run the full suite with it, and the debug
lines cost nothing unless `$APEXP_DEBUG` or `$APEXP_LISTENDEBUG` is set.

#### A log that was never pushed reads exactly like one that was

`tmp/tcl-all.out` was fetched after "the full suite completed" and is
**byte-identical to the frozen run's log from three rounds earlier** --
2440 lines, ending at `socket.test` with nothing after it. `git log` on
the path says why: its last commit is `a4c7a962c tcl test freeze at a
later stage now`, and the only newer commits on `main` are merges of
this branch.

**What caught it was `cmp`, not care.** The file had no `all.tcl: Total`
line and no completion marker, which I read as "the run did not finish"
-- a perfectly sensible reading of the wrong file. The `Tests ended at`
timestamp was there to be checked and was not.

*This is the libap mark again in a third guise. A header can be stock's,
a library can predate the pull, and a log can be the previous run --
and in all three the output looks entirely normal.* The rule is in
CLAUDE.md now: read the log's own `Tests ended at` line first.

**What the round DOES say, from the shell:** `grep -c FAILED` is 298,
against 322 in the last complete run. Twenty-four fewer lines, and each
failing test contributes roughly two -- but *compare runs per file,
never by total* is already a rule here, and a raw grep count is a total.
The real comparison needs the log.

#### The suite finishes again: 161 -> 149, and the two new failures are the leak's own shadow

`Tests ended at 2026-09-18 16:22:14`, marker, `Total 68118 Passed 62081
Skipped 5888 Failed 149`, against `Failed 161` in the last complete run.

**Fourteen fixed, and they are one cluster plus two:**

```
socket_inet-11.1 11.2 11.4 11.5 11.7 11.8 11.9 11.10 11.11 11.12 11.13
socket_inet-12.1  socket_inet-2.6  socket-14.11.1
```

The whole of `socket_inet-11.*` went at once. Eleven tests that had been
failing for as long as this file has recorded them, released by ports
being released.

**`socket_inet-5.1` and `5.3` appear in neither list -- they were failing
and they still are, which is what was predicted** when the leak fix went
in: `notRoot` asks about a user *name* as a proxy for a capability, and
glenda is the host owner, so the bind succeeds and the test says so.
That prediction was about the observation and it held.

**Two newly failing, and they were passing for the wrong reason too.**
`socket-14.14` and `socket-14.15` both do

```tcl
set s [socket -async localhost [randport]]
```

and now raise `couldn't open socket: connection refused` at that line.
`randport` is the explanation, and it is worth reading:

```tcl
set port [lindex [fconfigure [set s [socket -server {} 0]] -sockname] 2]
close $s
while {[catch { close [socket -server {} $port] } msg]} { ...try another... }
```

It picks a port, then **verifies it is free by opening and closing a
server socket on it**. With the leak, that verification left a listener
holding the very port it had just certified as free -- so
`socket -async localhost $port` connected happily to the leftover, Tcl
got a working socket, and the test passed. **The leak was answering the
connection that the test needed refused.**

*That is the third pair of tests in this file found to have been passing
for the wrong reason, all three uncovered by the same fix. A leaked
resource does not only waste something; it answers questions, and every
answer it gives is wrong.*

**And the honest failure exposes a real gap.** `network/connect.c` is
109 lines with no `O_NONBLOCK`, no `EINPROGRESS` and no deferred
completion anywhere in it: **`connect()` here is always synchronous, so
`socket -async` has never worked.** Tcl expects the call to return a
socket and the outcome to arrive later on a `fileevent`; libap raises
the error at the `socket` command instead. Nothing was broken by this
round -- something that never worked stopped being hidden.

**Next, and recorded rather than started**: async connect. `connect()`
on a descriptor with `O_NONBLOCK` should start the conversation, return
`-1`/`EINPROGRESS`, and let `select()` report the descriptor writable
when it completes or fails, with `getsockopt(SO_ERROR)` carrying the
result. On Plan 9 the connect is a write to the ctl file, so "in
progress" means a process doing that write while the caller goes back to
its event loop -- the same shape as `listenproc`, and the machinery for
it already exists in `_buf.c`.

#### Asynchronous connect: it had never worked, and the leak had been hiding that

`socket -async` reaches libap as `fcntl(O_NONBLOCK)` then `connect()`,
and `network/connect.c` had **no `O_NONBLOCK`, no `EINPROGRESS`, and no
deferred completion** in its 109 lines -- the ctl write was always done
in the calling process. `getsockopt(SO_ERROR)`, which is how Tcl reads
the outcome (`tclUnixSock.c:1420`), was

```c
case SO_ERROR:
	*(int*)v = 0;
	return 0;
```

-- a hard-coded "no error" for a connection that may never have been
made. **Both halves were stubs, and the second is the kind that rots
quietly**: a test exercising only the first would have passed over it.

**Why it took a leak fix to become visible.** `socket-14.14`/`14.15`
were passing because `randport` certifies a port free by opening and
closing a server socket on it, and the leak left a listener holding the
port it had just certified -- so the async connect reached that leftover
and succeeded. Nothing about `-async` was being tested at all.

**Why an asynchronous connect needs a process.** On Plan 9 a connect is
`write(ctl, "connect a!p")`, and that write does not return until the
conversation is made or refused; there is no "start it and tell me
later" form. So it is another process doing the write while the caller
returns to its event loop -- the same shape as `listenproc`, for the
same reason. `_RFORK(RFFDG|RFPROC|RFNOWAIT)` as `_timerproc` uses, so
there is no wait record for anyone to reap, and the child closes every
inherited descriptor but its report pipe, which is `listen.c`'s lesson
about a held descriptor 1 applied before it could cost anything.

**The approximation that remains, stated rather than hidden.**
`select()` reports every descriptor in the WRITE set ready at once --
"for now, we'll say they are all ready", which predates this by years --
so Tcl is told the socket is writable before the connect has resolved
and asks for `SO_ERROR` immediately. `getsockopt` therefore **waits**
for the answer rather than returning 0. That is a caller blocking
briefly; the alternative is an unresolved connect reported as success,
which is the `XLoadFont` family. The real fix is `select()` learning
about a pending connect, and it belongs in `_buf.c` with its own
measurement.

**`_sock_newrock` reuses a Rock when dev/inode match and `malloc` does
not zero one**, so the three new fields are initialised on the fresh
path and reset on the reuse path -- and the reuse path *closes* a report
pipe whose result nobody collected, which bounds that at one descriptor
per socket rather than one per connect. *When a struct is recycled,
reset every field that means something* was already a rule here; this is
the first time it has been applied before the bug rather than after.

**`priv.h` gained three fields, APPENDED**, and `unistd/mkfile` gained
an `HFILES` for it -- `writev.c` includes `priv.h` without using `Rock`,
and a header not in `HFILES` is a header `mk` does not rebuild for.

**`asyncconnect-test.c` does not assert EINPROGRESS**, and that is the
interesting part of writing it. On Linux a non-blocking connect to a
dead port on the loopback can fail immediately with ECONNREFUSED --
there is no round trip to be in progress -- so asserting EINPROGRESS
would fail on glibc and say nothing about either system. What both must
agree on is the contract: *a non-blocking connect either resolves now or
reports EINPROGRESS, and if it reported EINPROGRESS then SO_ERROR gives
the real answer and never a false 0.* Section 3 is the control, an
ordinary blocking connect still failing with ECONNREFUSED, so a change
that broke normal connects could not hide behind the sections above.
0 failures on glibc, which as it happens does report EINPROGRESS there.

**Prediction, observation only.** `asyncconnect-test` reports 0 failures
on the VM. `socket-14.14` and `14.15` are the reason this was written
but they are NOT predicted: 14.14 needs the failed connect to make the
socket readable, which goes through the copy process on the data file,
and nothing here has measured that it does.

#### Async connect works, and the errstr beside it is a lie

```
--- 1. a non-blocking connect to a dead port ---
  note non-blocking connect -> errno 62 (Operation in progress); plan 9
        says: file does not exist: '/proc/25180'
  PASS it reported EINPROGRESS, or resolved at once with ECONNREFUSED
  note SO_ERROR says 38 (Connection refused)
  PASS ...and SO_ERROR then gives the real failure
--- 2. a non-blocking connect that SUCCEEDS ---
  PASS a connect that will succeed reports EINPROGRESS, not an error
  PASS SO_ERROR is 0 for a connect that succeeded
--- 3. the control: a BLOCKING connect still fails ---
  PASS ...and it is ECONNREFUSED, as it always was
0 failure(s)
```

0 failures, and each section did the interesting thing rather than the
trivial one: Plan 9 reports EINPROGRESS for both the dead and the live
port, `SO_ERROR` then distinguishes them, and an ordinary blocking
connect is unchanged.

**`plan 9 says: file does not exist: '/proc/25180'` is left over, and
worth a rule.** `errstr` is per-process and sticky: it holds whatever
the last *system call* set, and `connect()` here sets `errno =
EINPROGRESS` **itself**, from C, without any failing call behind it. So
the string beside it belongs to something else entirely -- a
`/proc/N/note` open from a `kill()` in the listener or timer machinery,
minutes earlier in the same process.

*Every test in this directory prints `errno` and `errstr` side by side,
and that pairing is trustworthy only when the errno came FROM a system
call. When the library sets errno on its own -- EINPROGRESS, EALREADY,
ENOTSOCK, EAFNOSUPPORT -- the Plan 9 string is stale and can name a file
that has nothing to do with the operation.* It has not misled anyone
yet because errno was checked and the string only read for colour, but
it is exactly the shape that costs a round.

**What is confirmed**: `connect()` understands `O_NONBLOCK`,
`getsockopt(SO_ERROR)` reports the real outcome, and blocking connects
are untouched.

**What is not**: `socket-14.14` and `14.15`, which are why this was
written. 14.14 needs the failed connect to make the socket *readable*,
which goes through the copy process on the data file, and nothing has
measured that it does. They stay unpredicted.

#### Async connect: 149 -> 136, thirteen fixed, nothing broken

`Tests ended at 2026-09-18 17:11:30`, marker, `Total 68118 Passed 62095
Skipped 5887 Failed 136`.

```
FIXED: socket-14.2 14.6.0 14.7.0 14.7.2 14.8.2 14.11.0 14.12
       14.14 14.15 14.18  socket_inet-8.1  http-4.14.0 http-4.14.1
NEWLY FAILING: (none)
```

**Thirteen, and not one thing moved the other way** -- which matters
because `connect()` now forks a process on every non-blocking connect
and `getsockopt(SO_ERROR)` waits where it used to return instantly. Both
are new behaviour on a path a great many tests touch, and that was the
thing to watch rather than the two tests this came from.

**`socket-14.14` and `14.15` are fixed, and I declined to predict them.**
The reason given was that 14.14 needs the failed connect to make the
socket *readable*, which goes through the copy process on the data
file, and nothing had measured that it does. It does. *That is now a
measured fact rather than an assumption, and declining to guess it cost
nothing while guessing wrong would have cost the credibility of the
other predictions in the same message.*

**The cluster is bigger than the two tests that exposed it.** Eight more
`socket-14.*`, `socket_inet-8.1` and two in `http.test` were all waiting
on the same missing feature -- `http` does asynchronous connects too,
and nothing had connected those failures to `-async` at all. **A
feature that has never worked does not fail in one place; it fails
everywhere it is used, and the failures do not look related until it
works.**

**Where the suite stands now:**

```
io 23   fCmd 22   chan-io 19   filename 17   env 9   expr 5
socket_inet 4   cmdAH 4   lseq 3   exec 3   unixFCmd 2   io-bug 2
```

`fCmd`'s 22 and `env`'s 9 are accounted for and out of reach (symlinks,
a password database, and rc's lowercase `path`). The three largest
unread clusters are `io` 23, `chan-io` 19 and `filename` 17 -- and
`filename`'s are all `Tcl_GlobCmd`, which is one function rather than
seventeen questions.

#### filename 17: five need symlinks, eleven are their litter, one is ours

Read all seventeen before touching any, and they are three things.

**Five need symbolic links** -- `11.17.2`, `.3`, `.4`, `.7`, `.8` -- all
doing `file link -symbolic`, which is ENOSYS here and stays that way.

**Eleven fail because of what those five leave behind.** `11.17.7` is

```tcl
cd $globname
file mkdir nonexistent
file link -symbolic link nonexistent	;# raises here
file delete nonexistent			;# so this never runs
```

and its `-cleanup` removes only `link`. `nonexistent` stays in
`globTest`, and `11.18`, `11.19`, `11.20`, `11.22`, `11.23`, `11.24`,
`11.25`, `11.25.1`, `11.25.2`, `14.7` and `14.15` then each report one
extra entry. **Every one of the eleven differs from its expected result
by exactly that one word and nothing else** -- checked across all of
them, not sampled, which is what made it safe to treat as one cause.

**And the constraint that should have prevented it is hardcoded:**

```tcl
testConstraint linkDirectory 1
testConstraint symbolicLinkFile 1
if {[testConstraint win]} { ...only Windows turns them off... }
```

Upstream assumes every non-Windows platform has symbolic links.

**The patch, and the line drawn around it.** `fileName.test` now probes
for the capability instead of assuming it -- the same guard upstream
already writes for Windows, asked rather than assumed. That is the only
Tcl test file touched, and the justification is specific: **the litter
makes eleven tests report a result that is not about their subject.**
The suite is the measuring instrument here, and an instrument
miscalibrated by an assumption in its own setup is worth calibrating.

**`fCmd.test` and `cmdAH.test` hardcode the same constraint and are
deliberately NOT touched.** Their symlink tests fail on their own,
contaminating nothing, and turning fifteen honest "this platform cannot
do that" failures into skips would flatter the count without changing
anything. *The line is: fix the instrument where it misreports something
unrelated; never where it would only make the score look better.*

**One is genuinely ours, and is recorded rather than fixed.**
`filename-14.9`:

```
glob globTest/.*  ->  globTest/.1
wanted                globTest/. globTest/.. globTest/.1
```

**Plan 9 directories contain no `.` or `..` entries at all**, so
`readdir()` never returns them -- a fact already written in
`unistd/rmdir.c` ("Plan 9 directories hold no . or .. , but skip them
anyway"). Synthesising the two in `readdir()` would make this pass and
is a real compatibility question, but it changes what EVERY directory
read in every program sees, and the measured benefit so far is one test.
That is not a trade to make in the same round as eleven other changes;
it wants its own, with its own reduction. Recorded.

**Prediction, observation only.** `filename` goes from 17 failures to 1
(`14.9`), with 5 newly skipped rather than passed -- so `Skipped` rises
by 5 and `Failed` falls by 16. If `Failed` falls by more than 16, or
`Skipped` rises by anything but 5, the reading above is incomplete.

#### io 23 and chan-io 19 are not 42 questions: read() ignored what kind of file it had

**The two clusters are mostly the same tests through two APIs.** `io.test`
drives `fconfigure`, `chanio.test` drives `chan`, and these appear in
both: `6.31`, `6.43`-`6.47`, `8.1`, `14.1`, `14.2`, `29.27`, `32.7`,
`32.8`, `35.4`, `36.5`, `36.6`, `39.9`, `40.3`. So forty-two failures
are about sixteen questions, and reading one file answers two.

**Twelve of them are one line.** `io-39.9` reads an EMPTY file with
`-blocking off` and gets `fblocked 1, eof 0` where it wants `0, 1`;
`io-35.4` asks the same through `eof`; `io-32.7` asks for 20 bytes of a
long file and gets fewer. `unistd/read.c`:

```c
noblock = f->oflags&O_NONBLOCK;
isbuf = f->flags&(FD_BUFFERED|FD_BUFFEREDX);
if(noblock || isbuf){ ...copy process... }
```

**Any descriptor with `O_NONBLOCK` went into the buffered copy-process
path, whatever kind of file it was.** For a pipe or socket that is the
whole design -- Plan 9 has no non-blocking read, so another process does
the reading and the caller asks what arrived. For a regular file it
forks a process for something that cannot block, and then
`_readbuf(..., noblock)` answers "would block" whenever that process has
not caught up. **A file at end of file said "try again later" for ever,
and later never comes for a file that has already ended.**

POSIX is explicit: `O_NONBLOCK` affects pipes, FIFOs, terminals and
sockets. A read of a regular file transfers what is there and returns 0
at end of file, never EAGAIN.

**Cached, because the alternative is a stat per read on every socket.**
`FD_ISREG` and `FD_REGCHECKED` join `FD_ISTTY` in `f->flags` -- two bits,
so "not asked yet" differs from "asked, and it is not". `flags` had
`0x40` and `0x80` free, so this is a bit rather than a field, and no
struct changes size.

**And `_fdinfo.c` already records why that cache is dangerous.** The
flags word travels in `$_fdinfo` across an exec while the descriptor
behind it may have been redirected -- which is the FD_ISTTY bug written
up there at length, where a child believed it had a terminal and printed
`% ` into a pipe. `FD_ISREG`/`FD_REGCHECKED` are therefore cleared on
the same restore path, so the first read in a child asks again. *The
lesson was on the screen while the code was being written, which is the
first time in this sequence that has happened rather than the reverse.*

**`nbread-test.c` section 3 is the point of the file.** Sections 1 and 2
would both pass if `O_NONBLOCK` were ignored on EVERY descriptor, which
would wedge every event loop on the system; section 3 reads an empty
pipe and requires EAGAIN. Without it the test cannot tell a fix from a
catastrophe. 0 failures on glibc.

**Prediction, observation only.** `io` 23 -> 17 and `chan-io` 19 -> 13,
so `Failed` falls by 12. **What is NOT claimed**: `6.31`/`6.43`-`6.47`
(the `Tcl_GetsObj` cr/crlf group, and the oldest open item here),
`8.1`, `14.1`/`14.2`, `29.27`, `40.3`, and `io`'s encoding tests are
unread and untouched. If `Failed` falls by more than 12, something in
those groups shared the cause and the reading above was incomplete.

#### Reading the rest of io/chan-io: two of the six were the same bug, and the prediction goes up before the run

The previous section fixed twelve and explicitly did not claim
`6.31`, `6.43`-`6.47`, `8.1`, `14.1`/`14.2`, `29.27` or `40.3`. Reading
them now, **before the measurement rather than after it**, splits the
six that are left four ways -- and two of them turn out to be the bug
already fixed, which raises the prediction while it can still be wrong.

**`6.47` and `8.1` are the same one line.** Both open a *regular* file,
set `-buffersize 16`, do one blocking `chan gets`, and ask
`testchannel inputbuffered`. Both wanted a residue -- 15 and 7 -- and
both got **0**. `tclIO.c`'s `PeekAhead()`, called when `gets` finds a
`\r` at the end of a buffer and wants to know whether a `\n` follows:

```c
	if (bytesLeft == 0) {
	    if (!IsBufferFull(bufPtr)) {
		goto cleanup;			/* short read: device is empty */
	    }
	    if (!GotFlag(statePtr, CHANNEL_NONBLOCKING)) {
		...
		StackSetBlockMode(chanPtr, TCL_MODE_NONBLOCKING);
	    }
	}
```

**Tcl makes the channel non-blocking itself, for one read, and puts it
back.** So a plain blocking read of an ordinary file went through
`O_NONBLOCK` after all -- into the copy-process path, `EAGAIN`, no
bytes, `inputbuffered 0`. The channel was never non-blocking in the
test; Tcl made it so for the length of a peek. That is why reading the
test body was not enough to find it and reading the *implementation of
the call the test makes* was.

So `io` should go 23 -> **15** and `chan-io` 19 -> **11**, not 17 and 13.
**The earlier prediction said that a fall of more than twelve would mean
the reading was incomplete. It was, this is where, and the correction is
on the record before the run rather than after it.**

**`6.31` and `6.43`-`6.46` are a different thing and are not fixed.**
Every one of them uses `openpipe w+ $path(cat)`, and the `cat` script at
the top of the file is not `cat`:

```tcl
	chan configure $f -translation binary -blocking 0 -eofchar \x1A
	chan event $f readable "foo $f"
	proc foo {f} { set x [chan read $f]; catch {chan puts -nonewline $x} ... }
```

**The child is a second tclsh doing non-blocking reads of its own**, so
the data crosses two copy processes and two event loops before the
parent's next `gets` asks for it. The results say exactly that:
`6.43` and `6.44` produce the right values *shifted by one extra
blocked result*, and `6.31` wants `inputbuffered 16` and gets 0. On
Linux the bytes are in the kernel the instant they are written; here
they are in a process that has not been scheduled yet.

**The cheap fix is wrong and worth naming, because `select()` already
has the expensive version of it.** `waitfresh()` in `_buf.c` gives a
freshly-forked copy process a bounded chance -- ten tries at a
millisecond -- and that is defensible because it is paid once per
descriptor at the moment the descriptor is first watched. Doing the
same in `_readbuf`'s `noblock` path would tax *every* poll of *every*
idle descriptor in every event loop on the system, to make six tests
agree about scheduling. **`EAGAIN` would still be a lie, just a slower
one.** The honest fix is a real non-blocking read for pipes -- Plan 9's
`stat` on a pipe reports what is queued, so the copy process may not be
needed for them at all -- and that is its own round, with its own
measurement, not a rider on this one.

**`29.27` is ours and is one table entry.** It expects
`{posix epipe {broken pipe}}`, and Tcl spells that middle word from
`errno`. `_errno.c` mapped Plan 9's `i/o on hungup channel` and
`write to hungup stream` to **ESHUTDOWN** -- a BSD name for a *socket*
whose transport has been shut down. POSIX gives one answer for the
whole family: a write with no reader left is **EPIPE**, on a pipe and
on a socket alike, and Linux answers EPIPE after `shutdown(SHUT_WR)`
too. The note half was already right: the kernel posts
`sys: write on closed pipe` and `signal/signal.c` already maps it to
SIGPIPE. `sys/lib/tests/epipe-test.c` asks it without Tcl in the way --
section 0 disarms SIGPIPE (or the test would die rather than report),
section 2 is the control that a live pipe still takes a write, and
section 3 does the socket half, because the two entries are reached
through the same table and measuring only the pipe would leave half the
change unobserved. 0 failures on glibc.

**`40.3` is not ours.** It creates a file `{WRONLY CREAT}` and compares
the mode against `0666 & ~umask`. Plan 9 has no umask -- `stat/umask.c`
returns 0 and always has -- so the test computes `0o666`, while the
file server hands out `perm & (dirperm | ~0666)`, which in a 0775
directory is `0o664`. That is the *file server's* rule about creation,
not a library one, and there is nothing to set: a probe, like
`unixFCmd-1.1`.

**`14.1` and `14.2` are still unread**, and deliberately so: they ask
what `chan configure stdout -buffering` says and what
`testchannel open` lists, and the surviving log is the truncated one
that stops at `8.1`, so their actual output is not in hand. *A test
whose failure text has not been seen is not a test that has been read* --
that is what `env`'s nine cost. They wait for the next full run.

#### 136 -> 96: forty gone, none broken, and every one of them named

```
all.tcl:	Total 68118  Passed 62130  Skipped 5892  Failed 96
Sourced 167 Test Files.   marker present, exit 0
```

`Total` identical, `Skipped` **+5 exactly** -- the five symbolic-link
tests the `fileName.test` probe now skips -- `Passed` +35, and the
per-name diff against the 136 run has **forty in the fixed column and
nothing in the new column**. The four library tests agree:
`nbread-test` 0 failures, `epipe-test` 0 failures with
`plan 9 says: i/o on hungup channel` printed beside EPIPE, and
`listenleak-test` reports **mark 8**, so the installed library is the
one that was pulled.

**All forty account for:**

| what | how many |
|---|---|
| `O_NONBLOCK` on a regular file: `32.7`, `32.8`, `35.4`, `36.5`, `36.6`, `39.9`, both APIs | 12 |
| `6.47` and `8.1`, both APIs -- the `PeekAhead()` reading | 4 |
| `29.27`, both APIs -- ESHUTDOWN -> EPIPE | 2 |
| `filename` litter and its five skips | 16 |
| **`io`'s encoding tests, which were on the unread list** | 6 |

**The last row is the one worth keeping.** The previous note said: *if
`Failed` falls by more than predicted, something in the untouched groups
shared the cause and the reading was incomplete.* It did, and it was:
`io-75.6.3`, `io-75.6.4`, `io-75.11`, `io-75.13`, `io-bug-73bb42fb-1`
and `io-bug-73bb43fb-2` all went with the rest, having never been
opened. They are `io`-only, with no `chan-io` twins, which is why the
cluster arithmetic never put them with the others. **The refutation
condition was written down, it fired, and it pointed at the right six.**

**And the raised prediction held.** `6.47`/`8.1` were called for this
run *from reading `PeekAhead()`*, before the measurement, on the
argument that Tcl makes a blocking channel non-blocking for one read.
Both passed, in both files. `io` went 23 -> 10 and `chan-io` 19 -> 10,
against the 15 and 11 predicted -- better by the six encoding tests.

**The EPIPE change is confirmed twice, and the second way is the more
useful.** `29.27` passes in both files; and `io-29.33b`, which still
fails, changed its message:

```
was:	error writing "stdout": cannot send after transport endpoint shutdown
now:	error writing "stdout": broken pipe
```

So the mapping demonstrably reaches the code, and `29.33b` is a
*different* bug that the wrong errno had been dressing up as a socket
problem. It writes 640KB to a non-blocking stdout whose reader sleeps
two seconds and expects no failure at all; EPIPE says the pipe is
closed, not full. Recorded, not diagnosed.

**One correction to my own note.** `40.3` was written up as giving
`0o664` in a `0775` directory. The log says **`0o644`**. The mechanism
is the one described -- Plan 9's file server hands out
`perm & (dirperm | ~0666)` and there is no umask to consult -- but the
number was a guess dressed as a measurement, and the directory is 0755.
*A number that was not read off the machine should not be written as
though it was.*

#### What the 96 are, now that the log has been read rather than counted

`fCmd` 22, `io` 10, `chan-io` 10, `env` 9, **`zipfs` 13**, `expr` 5,
`socket_inet` 4, `cmdAH` 4, `lseq` 3, `exec` 3, and eleven singletons.
Three groups are newly read.

**`zipfs` 13 is ten plus three, and the ten are two `#define`s.**
Every `zipfs-file-stat-*` and `zipfs-file-lstat-*` compares the whole
key list of `file stat` with a regexp, and ours is two keys short:

```
was:	atime .. ctime .. dev 0 gid 0 ino 0 mode 16749 mtime .. nlink 0 size 0 type directory uid 0
want:	atime .. blksize 0 blocks 0 ctime .. dev 0 ...
```

`tclCmdAH.c`'s `StoreStatData` wraps them in
`HAVE_STRUCT_STAT_ST_BLKSIZE` and `HAVE_STRUCT_STAT_ST_BLOCKS`, and
APExp's hand-maintained `sys/src/ape/lib/tcl/tclConfig.h` declared
neither -- **while APE's `struct stat` has had both fields all along and
`plan9/dirtostat.c` fills both**. So this is not a missing capability,
it is a capability not declared: `file stat` has been returning a
dictionary two keys short of every POSIX platform, for every program,
not only in tests. Both are defined now.

**`st_rdev` is deliberately NOT declared**, although the field exists
and Tcl has a third guard for it. `dirtostat.c` sets it to 0
unconditionally, because Plan 9 has no minor number to report. *A field
that is always zero reads as information and is not*; leaving it out
says "this platform has no such thing", which is true. Prediction:
`zipfs` 13 -> 3. The three that remain are `invalid password` from
zipfs's own cipher and are unrelated.

**`14.1`/`14.2` are four tests and one line, and they are a probe rather
than a diagnosis.** The failure text finally came with a complete log:

```
was:	line line line
want:	line line none
```

**stderr's buffering is `line` and must be `none`.** And
`tclUnixChan.c`'s `TclpGetDefaultStdChannel` asks for exactly that --
`bufMode = "none"` for `TCL_STDERR`, then
`Tcl_SetChannelOption(NULL, channel, "-buffering", bufMode)`. So either
that call fails (it is passed a NULL interp, so a failure is silent) or
something afterwards resets it. Reading further would be guessing: the
channel exists and is a `file` channel (`testchannel open` says
`file0 file1 file2`, so `isatty` is answering correctly and this is not
the tty path). **One line settles it**, and it belongs in the next run:

```
echo 'puts [list [fconfigure stderr -buffering] [fconfigure stdout -buffering]]' >/tmp/b.tcl
tclsh /tmp/b.tcl              # at a terminal
tclsh /tmp/b.tcl >/tmp/b.out 2>&1   # redirected, as the suite runs it
```

If both say `line` when redirected and `none` at a terminal, the
difference is the redirect and the next question is `TclOSseek(2,...)`;
if it says `line` either way, the `Tcl_SetChannelOption` call is
failing and the question is which check inside it says no.

**`cmdAH` 4 read in full: two symlink, two ours.**

- **`cmdAH-25.3`: `file owned /` answers 1, and should answer 0.**
  `file owned` compares `st_uid` against `geteuid()`, and
  `plan9/dirtostat.c` gets `st_uid` from `_getpw()`, which parses
  **`/adm/users`**. That is a fossil/kenfs file; a 9front terminal on
  hjfs or cwfs need not have one, and when `_getpw` cannot open it the
  function returns 0 and `dirtostat` leaves the `s->st_uid = 1` it set
  as a default. **Then every file on the system has uid 1, everything
  is owned by whoever geteuid() says, and `file owned` is a constant.**
  That is a one-command probe (`ls -l /adm/users`) before anything is
  written, and if it is the cause the honest repair is to compare the
  Dir's owner *string* against `/dev/user` rather than to invent a
  password database.
- **`cmdAH-20.5`: `file atime $f $newatime` does not take.** The value
  read back is two seconds later than the one set, which is the
  *current* time -- so the wstat either did not carry the atime or was
  ignored. `utime()` has been wrong here before, and `ratrace` named
  that one in a single run where six readings of the source did not.

**`chan-io-28.7` is one test and is ours**: `close $s w` on a socket --
a half-close -- and the far end then reads `{}` where it should read
`{Hey DONE}`. The bytes written before the half-close did not arrive.
`shutdown()` is in this file's list of stubs that answered the wrong
thing once already.

#### The symlink constraint, done properly: one probe file, and a name of our own

Authorised this round: *"it is OK to patch the test files that look for
symlinks to be ignored by Windows AND Plan 9."* The previous round had
patched only `fileName.test`, on the narrow ground that its five
failures **contaminated eleven others**, and had deliberately left
`fCmd.test` and `cmdAH.test` alone because their symlink tests fail
honestly. With the wider permission the right shape is one file,
`tests/apexp-links.tcl`, sourced by the five test files that need it.

**Eighteen tests, and only four of them declared what they needed.**

| file | tests | already constrained? |
|---|---|---|
| `fCmd` `18.12`-`18.16`, `21.7.2`, `21.8.2`, `21.9`, `26.1`-`26.3` | 11 | no -- `{unix notRoot}` |
| `fCmd` `28.9`, `28.21`, `28.22` | 3 | yes (`linkFile`/`linkDirectory`) |
| `cmdAH-29.4` | 1 | no -- `{unix}` |
| `cmdAH-29.4.1` | 1 | yes (`linkDirectory`) |
| `chan-io-41.8` | 1 | no -- `{fileevent unix}` |
| `unixFCmd-2.2.2` | 1 | no -- `{unix notRoot}` |

Upstream guards the `file link` **API** tests and not the tests that
merely *use* a link, because on every unix it builds on there was never
a reason to. So the four constrained ones need the constraint turned
off and the fourteen others need a constraint at all.

**A name of our own, and that is the interesting part.** The first
version tried to tell "this file never declared `linkFile`" from "this
file declared it 0", so that it could default the former to 1. It
cannot be done, and the host tclsh said so in one run: `linkFile` and
`symbolicLinkFile` came back **0 on a machine that has symbolic links**.
`tcltest` puts a read trace on the array --

```tcl
# Side effects:
#	sets testConstraints($n2) to 0 if it's referenced but never
#       before used
proc tcltest::SafeFetch {n1 n2 op} { ... }
```

-- so *looking* creates the entry as 0, and absent and false are the
same observation. Reading `SafeFetch` after the run confirmed what the
run had already shown. **Had this gone to the VM instead, fourteen
tests would have been silently skipped on Linux too and the constraint
would have looked like it worked.**

So `apexp-links.tcl` declares **`symlinks`**, which is APExp's name and
collides with nothing (checked), sets it from the probe, and touches
upstream's three constraints **only when the probe fails**. On a system
that has links it changes nothing at all: `symlinks` is 1 and
`linkDirectory`, `linkFile` and `symbolicLinkFile` are left exactly as
the test file left them, so nothing Windows disabled can be switched
back on. Both branches were run on the host tclsh -- a file that had
declared `linkDirectory 0` keeps 0, and the forced branch takes all
four to 0.

**Prediction: `Failed` 96 -> 78, `Skipped` up by exactly 18**, `Total`
unchanged, and nothing moves in the other direction. `fCmd` 22 -> 8
(the eight `~USER` tests, which are a different question), `cmdAH` 4 ->
2, `chan-io` 10 -> 9, `unixFCmd` 2 -> 1. **What would refute it**: a
`Skipped` rise of anything other than 18, or any test that is neither
skipped nor still failing -- a symlink test that starts *passing* would
mean the probe answered yes and something else is wrong.

#### Tk moved by one, and that is the whole point of the datapoint

`grep -c FAILED` on Tk's log went 356 -> 354, which is 178 -> **177**:
two lines per failure. So the whole Tcl campaign -- forty tests this
round, eighty-seven in all -- bought Tk exactly one. That is not
disappointing, it is *information*: it says Tk's remaining 177 do not
share a cause with Tcl's, and the three-item Tk list can be worked on
without waiting for Tcl to finish. Tcl was one of those three items and
is now effectively off it.

#### 96 -> 77, and the refutation condition fired usefully

```
all.tcl:	Total 68118  Passed 62125  Skipped 5916  Failed 77
```

The prediction was `Failed` 78 with `Skipped` **+18**. What arrived was
77 and **+24**, and `Passed` went **down by 5**:

| | run 5 | run 6 | delta |
|---|---|---|---|
| Passed | 62130 | 62125 | **-5** |
| Skipped | 5892 | 5916 | **+24** |
| Failed | 96 | 77 | **-19** |

The three deltas sum to zero, so nothing was created or lost -- 19
failures became skips, and **five passes became skips**. The written
condition was *"a `Skipped` rise of anything other than 18 refutes
it"*. It rose by 24 and reading out why was the useful part of the
round.

**The per-constraint skip table is the instrument, and it had been sat
on for months.** tcltest prints the number of tests skipped for each
constraint at the end of every run; diffing that table between two runs
says exactly where skips moved:

```
symlinks         0 -> 14     the fourteen newly constrained tests
linkFile         0 ->  4
linkDirectory    4 -> 21
notWine         17 -> 10     reattributed, not newly skipped
win            594 -> 592    ditto
winLessThan10    1 ->  0     ditto
dontCopyLinks    4 ->  3     ditto
```

35 new skips, 11 of them **reattributions**: tcltest charges a skip to
one constraint out of the list, so a test that was charged to `notWine`
is charged to `linkDirectory` once that one is false too. 35 - 11 = 24,
which is the whole of the change. *Nothing else in the suite moved.*

#### The five lost passes were FALSE passes, and they have names

`fCmd-28.5`, `28.7`, `28.10`, `28.10.1`, `28.20` -- and `28.14`, which
makes six candidates for five slots. Five of the six are
`-returnCodes error` tests:

```tcl
test fCmd-28.5 {file link: source already exists} \
    -constraints {linkDirectory} -body {
    file link abc.dir abc2.dir
} -returnCodes error ...
```

**They assert only that `file link` raises.** On Plan 9 it raises
ENOSYS, so every one of them passed -- for a reason that has nothing to
do with what it tests. `28.5` wants "source already exists", `28.10`
wants "the target does not exist", `28.20` wants a relative path
rejected. `28.14` is the same family from the other side: it deletes a
link a previous test made and checks the directory survives, and
without links the link was never there.

**A check that can PASS for the wrong reason is not a check** -- this
tree's own rule, and here are five of them by name. So `Passed` falling
by 5 is not a loss of coverage; it is five false positives leaving the
count. **A constraint that removes passes is doing its job as much as
one that removes failures**, and a round that had only watched `Failed`
would have recorded this as a clean win and learned nothing.

#### io-6.46 is the nineteenth, and it is FLAKY rather than fixed

19 failures went, not 18. The extra is `io-6.46` -- and **its twin
`chan-io-6.46` still fails**. The twins are the same test through two
APIs and they now disagree, which is the signature of the scheduling
race written up for that group: the data crosses two copy processes and
two event loops, and whether it has arrived is a matter of timing.
Nothing was fixed there. **Count that group by whether the twins agree**,
not by either one.

#### zipfs is still 13, and that is unmeasured rather than refuted

The `HAVE_STRUCT_STAT_ST_BLKSIZE`/`_ST_BLOCKS` change is in
`sys/src/ape/lib/tcl/tclConfig.h`, and this run was the suite alone --
no `mk install`, so `libtcl.a` and `tcltest` are the old binaries. The
header **is** in that directory's `HFILES`, so a rebuild will pick it
up. The one-line check that says which world the binary is in, before
reading the suite at all:

```
echo 'file stat /tmp x; puts [lsort [array names x]]' >/tmp/s.tcl; tclsh /tmp/s.tcl
```

`blksize` and `blocks` in that list means the rebuilt Tcl is running.

#### The three queued ports, surveyed before any work

- **itcl 4.2.3** -- 22 `.c`, 7 `.tcl`, an ordinary autoconf extension.
  Nothing in the shape of it says it cannot be an APExp package.
- **tkblt 3.2 is C++ and is therefore BLOCKED.** 48 `.C` files with
  `namespace Blt {`, `class Axis;` and `#include <cfloat>`. kencc has no
  C++, and `sys/src/external/cfront-C4` is pre-standard cfront -- no
  namespaces, no templates, no STL -- so it will not translate this.
  Worth knowing before a directory is created rather than after.
- **tkdesk does not need tkblt.** It ships **its own BLT subset in C**,
  `tkdesk/blt/`: 12 `.c` files and not one `.C` -- `bltBgexec`,
  `bltBusy`, `bltChain`, `bltConfig`, `bltDnd`, `bltInit` and the rest,
  which is the part of BLT tkdesk actually uses. So the stress-test
  application is reachable through itcl plus a bundled C library, and
  the C++ problem is confined to the widget set nobody has asked for
  yet.

#### 77 -> 68: zipfs 13 -> 3 exactly as predicted, and the flake came back on cue

```
all.tcl:	Total 68118  Passed 62134  Skipped 5916  Failed 68
```

`Skipped` and `Total` identical, `Passed` **+9**, `Failed` **-9**, and
the per-name diff is ten out and one in:

- out: every `zipfs-file-stat-*` and `zipfs-file-lstat-*`, all ten.
  **`HAVE_STRUCT_STAT_ST_BLKSIZE`/`_ST_BLOCKS` CONFIRMED**, and the
  three `zipfs-password-*` that remain are zipfs's own cipher, as read.
  13 -> 3, which is what the note said.
- in: **`io-6.46`**, which left last round while its twin
  `chan-io-6.46` stayed. It was called flaky on exactly that evidence,
  and it came back in the very next run without anything touching it.
  That is as clean a confirmation as a flake gives, and it settles how
  that group is to be counted: **by whether the twins agree.**

#### The /adm/users hypothesis is REFUTED, and the probe cost one command

`cmdAH-25.3` has `file owned /` answering 1 where it should answer 0,
and the mechanism argued from the source was: `dirtostat.c` takes
`st_uid` from `_getpw()`, `_getpw()` parses `/adm/users`, that is a
fossil/kenfs file, a 9front hjfs or cwfs terminal need not have one,
and without it every file falls back to the default `st_uid = 1`.

```
% ls -l /adm/users
-rw-rw-r-- 1 adm adm 139 Sun 26  2024 /adm/users
```

**It is there.** So `_getpw` opens it, the fallback is not what is
happening, and the constant-ownership story is wrong as stated. What
remains is much simpler and may not be a bug at all: `file owned /` is
`st_uid == geteuid()`, and on a 9front terminal the owner of `/` may
genuinely *be* the user running the tests. That would put this with
`socket_inet-5.1` -- upstream testing a *name* (`notRoot`) as a proxy
for a capability, on a system where the proxy does not hold.

Three commands settle it and none of them needs a build:

```
ls -ld /          # who owns the root
cat /dev/user     # who we are
cat /adm/users    # 139 bytes: the whole mapping
```

**The guess was cheap and the refutation was cheaper.** It is the
fourth time in this file that a mechanism read off the source was wrong
and one command said so; the running tally is about one in eight
correct for mechanisms guessed from code alone, and this round did not
improve it.

#### An instruction for the other machine has to name the program that runs it

The second probe asked for was

> print `fconfigure stderr -buffering` at a terminal and again under
> `>out 2>&1`

and it came back as

```
$ fconfigure stderr -buffering
bash: fconfigure: command not found
```

**That is my fault, not a misreading.** `fconfigure` is a Tcl command
and the line was written as though it were a shell one; nothing in it
said `tclsh`. The instruction travelled to a machine I cannot see, and
the only thing that can make it unambiguous there is the text itself.

So the probe is now a file, `sys/lib/tests/tcl-stdchan-test.tcl`, which
is this tree's own convention and removes the ambiguity permanently --
and while writing it, it turned out to answer more than the original
line did. **It tells the two hypotheses apart in ONE run** rather than
by comparing two runs by eye:

- section 1 prints all three channels and whether each is a terminal;
- **section 2 tries to SET `-buffering none` itself**, which is the
  same call `TclpGetDefaultStdChannel` makes with a NULL interp and
  therefore cannot see the result of. If the set raises, the option
  call is what fails; if it is accepted and does not take, the same; if
  it works, something reset it afterwards;
- section 3 asks the same of a freshly opened file channel, so "the
  standard channels are special" can be told from "nothing can be set
  to none";
- section 4 says which Tcl ran.

**Section 2 prints no verdict when section 1 already said `none`** --
on a system where nothing is wrong there is nothing to tell apart, and
a verdict printed anyway would be read as one.

**And the host run already refutes one story.** On glibc, redirected
exactly as the suite runs it, Linux still answers `line line none`. So
**the redirect is not the condition**, and APExp's `line line line` is
ours rather than an artefact of how the suite is invoked.

#### The four stderr failures were the HARNESS, and the probe is what sent the search outward

`tcl-stdchan-test.tcl` on 9front, under a plain `tclsh`, at a terminal
and redirected alike:

```
  stdin -buffering    line   (terminal: no)
  stdout -buffering   line   (terminal: no)
  stderr -buffering   none   (terminal: no)
  wanted              line line none
```

**Correct, both ways.** So libap is not in it, `TclpGetDefaultStdChannel`
works, the redirect is not the condition, and section 2 rightly printed
no verdict because there was nothing to tell apart. Every story the
probe was built to distinguish was wrong -- and that is what made it
useful, because it left only one place to look: between `tclsh` and the
test, which is `tcltest` and the harness. One grep:

```
sys/lib/tests/tcl-runall.tcl:199:fconfigure stderr -buffering line
sys/lib/tests/tcl-runall.tcl:201:catch {fconfigure $::tcltest::errorChannel -buffering line}
```

**I wrote those, and they are the bug.** The harness sets line
buffering so that a wedged run's log is not truncated, and it sets it
in every child through `-load` -- which is the very interpreter
`io-14.1` then asks. Four failures produced by the instrument that was
measuring them.

**It was working against its own purpose, too.** stderr starts
*unbuffered*, and `none` orders a log strictly better than `line` does;
there was never anything to gain. And `::tcltest::errorChannel` is
`stderr` by default, so the fourth line was the same bug under a second
name. `stdout` keeps its line buffering, which is the half that was
needed; `outputChannel` is `stdout` and keeps it too.

`tk-runall.tcl` had the same four lines and is fixed the same way.

**Prediction: `io-14.1`, `io-14.2`, `chan-io-14.1`, `chan-io-14.2`
pass, `Failed` 68 -> 64**, `Skipped` and `Total` unchanged, nothing
else moving. `io-14.1` also compares `[lsort [testchannel open]]`, and
the log shows that half already matching (`{file0 file1 file2}`), so
the buffering is the whole of it. **What would refute it**: the log's
tail truncating on an abnormal end -- the thing the removed lines were
for -- or any of the four still failing, which would mean `tcltest`
sets it somewhere else as well.

**The general shape, which this file has now met from three
directions.** The listener table was keyed on a descriptor number; the
`fileName.test` constraint claimed a capability the system did not
have; and now the log's own buffering was a property the tests could
read. *An instrument that shares state with the thing it measures can
be the thing it reports.* The first question about a measurement that
disagrees with a direct probe is what sits between them.

#### cmdAH-25.3 is NOT OURS, and the three commands said so exactly

```
% ls -ld /
dr-xr-xr-x 1 glenda glenda 0 Sun 28  2024 /
% cat /dev/user
glenda
% cat /adm/users
-1:adm:adm:glenda
0:none:adm:
1:tor:tor:
2:glenda:glenda:
10000:sys::glenda
...
```

**`/` is owned by glenda and the user is glenda**, so `file owned /`
answering 1 is *correct*. The test wants 0 because on a unix `/` is
root's and the test user is not root; on a 9front terminal the host
owner owns the root. That is `notRoot` again -- upstream testing a
*name* as a proxy for a capability -- and it joins `socket_inet-5.1`,
`5.3` and `unixFCmd-1.1` as a probe rather than a library rule.

**And the table settles the refuted mechanism twice over.** glenda is
uid **2**, not 1; uid 1 is `tor`. So even if `_getpw` had failed and
the `st_uid = 1` default had stood, `/` would have read as owned by
*tor* and the test would have passed for the wrong reason. The
fallback was not in play, and the reading that said it was would have
been wrong in the other direction as well.

#### 68 -> 64, exactly the four named, nothing else

```
all.tcl:	Total 68118  Passed 62138  Skipped 5916  Failed 64
```

`Skipped` and `Total` identical, `Passed` **+4**, and the per-name diff
is `io-14.1`, `io-14.2`, `chan-io-14.1`, `chan-io-14.2` out and an
**empty** new column. The refutation condition -- the log's tail
truncating now that stderr is left alone -- did not fire: the marker is
there, `Sourced 167 Test Files`, `Tests ended at` present. **The
harness was the whole of it**, and nothing was lost by taking the
stderr lines out.

Remaining 64: `env` 9, `io` 8, `fCmd` 8, `chan-io` 7, `expr` 5,
`socket_inet` 4, `lseq` 3, `exec` 3, `cmdAH` 2, `binary` 2, `zipfs` 3,
and singletons.

#### expr's six are one question, and the cross-check refuted the answer

All six are the top of the double range:

```
expr-30.1    convertToDouble 1.7976931348623155e+308 -> 0x7ff0000000000000
             ...157e+308 -> 0x7ff0000000000000   ...159e+308 -> 0x7ff0000000000000
             wanted        0x7feffffffffffffe, 0x7fefffffffffffff, 0x7ff0000000000000
expr-30.2    the same, negative
expr-28.527  -929963218616126365E290 -> -Inf, wanted -0x7fe08dcc0c505461
expr-39.21 / expr-old-37.21   17976931348623157e292. -> Inf
expr-50.1    sqrt(1e616) == 1e308 -> false
```

**Everything at or above `1.79769313486231 55 e308` comes back as
infinity**, including the two values that are perfectly representable.
`lib/ap/string/strtod.c` was the obvious suspect -- it is the old APE
one, it accumulates digits in a double and multiplies by `pow10(exp)`,
and its own first line says *"bug: should detect overflow"*.

So the unit went into a glibc program beside glibc's own, the way
`tz-xcheck` did: **`sys/lib/tests/strtod-xcheck.c`**. And the first run
**refuted the diagnosis that built it**:

```
  1.7976931348623157e+308    ours 7feffffffffffffd   glibc 7fefffffffffffff
  1.7976931348623159e+308    ours 7fefffffffffffff   glibc 7ff0000000000000 (+inf)
```

libap's `strtod` does **not** return infinity for the value Tcl reports
as infinite -- it returns something two ulp *low*, and where glibc
overflows it stays finite. Whatever produces `expr-30.1`'s Inf, it is
not this function; **Tcl parses numbers in its own `tclStrToD.c`**. The
expr cluster is therefore *unexplained*, and saying so is the result.
The next step for it is the same one that worked for the stderr
cluster: ask what the code actually calls, rather than what looks
guilty.

**And the file found something much larger on the way past.**

```
  2. round-trip of random doubles     199887 checked, 148018 wrong
  3. the powers of ten, 1e-320..1e308    629 checked,    445 wrong
       worst: 1e308, off by 202402253307311 ulp
  4. values that must be exact            10 checked,      0 wrong
```

**Seventy-four per cent of doubles do not survive `printf("%.17g")`
followed by `strtod`.** `%.17g` names a double uniquely, so a correct
`strtod` must return exactly what was printed; three times in four this
one does not. `1e308` is wrong by 2e14 ulp. Every program on this
system that reads a floating-point number gets this, and it has been
true for as long as the file has existed -- the comment at the top says
so and nobody had put a number to it.

Section 4 is the control: ten values a naive parser still gets right,
all correct, so this is a rounding result and not a build mistake.

**The fix has a shape already.** `stdio/_fconv.c` and
`include/fconv.h` are David Gay's bignum kit -- `_Balloc`, `_multadd`,
`_mult`, `_pow5mult`, `_lshift`, `_cmp`, `_diff`, `_d2b`, `_i2b` -- and
`_dtoa.c` is Gay's dtoa built on it. **Gay's `strtod` is the other half
of that package and the half this tree does not have.** So the correct
parser can be written against machinery already here and already
linked, rather than vendored fresh; and `strtod-xcheck` is the harness
that will say whether it worked, before any of it reaches a VM.

`strtof` and `strtold` are the same file three times over and will need
the same treatment.

#### Gay's strtod: two transcription bugs found, a third still open, and it is NOT shipping

Written against the Bigint kit already in the tree --
`stdio/_fconv.c`'s `_Balloc`, `_multadd`, `_mult`, `_pow5mult`,
`_lshift`, `_cmp`, `_diff`, `_d2b`, `_i2b` and the `_tens` tables --
plus `ulp`, `b2d` and `s2b`, which are the three pieces of Gay's
package this tree never kept. It lives at
`lib/ap/string/strtod-gay.c` and is **deliberately not in any
mkfile**; `strtod.c` still ships the old one.

**Two things had to change before the kit could be used at all, and
both are improvements in their own right.**

- **`fconv.h` had no include guard.** It declares a struct and two
  typedefs, and it never showed while `_fconv.c` and `_dtoa.c` were the
  only includers -- separate translation units each see it once. It
  shows the instant anything includes both, which the cross-check does.
- **The bignum word is 32 bits and the code said so only by accident.**
  Gay's arithmetic hard-assumes it -- `n = k >> 5`, `k &= 0x1f`,
  `Storeinc`'s two `unsigned short` halves, `Pack_32` -- while spelling
  the type `unsigned long`, which is 32 bits under kencc and **64 under
  any LP64 compiler**. Correct here, wrong anywhere else, including the
  build host. It is now `typedef unsigned int ULong`, which is 32 bits
  under kencc and gcc alike: no change on Plan 9, and the same source
  becomes testable beside glibc. *This is the `long` invariant from the
  other side -- the tree knows `long` is not 64-bit on amd64, and here
  was code relying on that without saying so.*

**The two transcription bugs, both invisible to reading, each settled
by one instrumented run.**

1. **The scaling.** In the correction loop `j` is `P + 1 - bbbits`
   normally and `bbe + (P - Emin)` for a denormal. An earlier version
   computed `bbe - P + 1` and assigned the normal case to `i` instead
   of `j`. Everything that needed correcting diverged: `1e100` spun
   with `aadj = 8.8e71` and returned -inf. Capping the loop and
   printing `i`, `dsign`, `aadj` and `rv` per pass named it
   immediately; six readings of the source had not.
2. **The sign scan.** Gay writes it as a fall-through switch inside
   `for(s = s00;;s++)`; the `'+'`/`'-'` arm advances `s` past the sign
   and then breaks out of the **switch**, so the loop's own `s++`
   advances again and the first digit is lost. Every negative number
   came back at **0.44** of its size -- which is exactly what
   `-1.797e308` gives when read as `.797e308`. The cross-check named it
   by having all three positive values right and all three negative
   ones wrong, in the same run. It is written out plainly now.

**Where it stands, measured rather than asserted** (the candidate
built, which the cross-check now says in a comment at the include):

```
  section 1, the seven strings Tcl's expr tests use:
      6 of 7 EXACT, including DBL_MAX and the overflow one ulp past it
      (the old file got 0 of 7). The seventh is 18 digits and is
      128 ulp out.
  section 2, 200000 round-trips through "%.17g":
      140173 wrong, against 148018 for the old file. 16 inputs SPIN.
```

**So it is right where the old one was catastrophic and no better
where the old one was merely bad, and that is not good enough to
ship.** Putting it in the mkfile now would trade a known-bad parser for
an unknown-bad one, and the one thing worse than a library that is
wrong is a library that is wrong in a way nobody has characterised.

**The third bug is the same family and the evidence already narrows
it.** For `-5.5098193881687261e+58` the floating-point approximation is
**already bit-exact before the correction loop**, and the loop then
moves it 2048 ulp away: `cmp(delta, bs)` says the error exceeds half an
ulp when it is zero. So `bd` -- the digits as an exact Bigint -- or the
shifts around it disagree with `bb` when they should agree exactly.
**The next step is to print `bd` and `bb` for that one input, not to
read `s2b` again**: two readings have already passed it as correct, and
this file's own tally for mechanisms guessed from code alone is about
one in eight.

**One process note worth keeping.** A `python3` `s.replace()` with a
mismatched anchor silently does nothing, and twice in this round an
edit "succeeded" while changing no bytes -- once leaving a stale binary
that reproduced the previous run's symptom exactly. Every anchored edit
here now asserts its anchor first. It is the same rule as the libap
version mark, one layer up: *a change you have not proved arrived is a
change you cannot measure.*

#### The float rewrite moved nothing, and that is the result it should have

`Total 68118 Passed 62138 Skipped 5916 Failed 64` -- **identical to the
run before it, and the per-name diff is empty in both directions.**

That is worth stating plainly, because the change was not small. Gay's
`strtod` replaced a parser that was wrong on 74% of round-trips;
`strtof` and `strtold` were rewritten on top of it; and
`Sudden_Underflow` was removed for amd64, which switches `_dtoa` --
**the shipping printf path for every float on the system** -- to its
gradual-underflow arm. An empty diff after that is the confirmation
that it was safe, and it is the only confirmation available: no test in
this suite formats a denormal.

It also settles the prediction made when `strtod-xcheck` first refuted
itself: **`expr`'s six are not libap's parser.** They were not going to
move, and they did not.

#### expr's six: three libap suspects eliminated, and the next step is on the VM

All six say the same thing -- everything at or above
`1.7976931348623155e+308` comes back infinite, including two values
that are perfectly representable. Tcl parses numbers in its own
`tclStrToD.c`, and `MakeHighPrecisionDouble()` has exactly two places
that can answer `HUGE_VAL`:

```c
    if (exponent >= 0 && exponent-1 > maxDigits-numSigDigs) {
	retval = HUGE_VAL;			/* the quick check */
...
    retval = BignumToBiasedFrExp(significand, &machexp);
    retval = Pow10TimesFrExp(exponent, retval, &machexp);
    if (machexp > DBL_MAX_EXP*log2FLT_RADIX) {
	retval = HUGE_VAL;			/* the real one */
```

Both are computed from libap at startup, so both had a libap suspect.
**All three are now eliminated:**

- **`maxDigits`** is `(DBL_MAX_EXP*log(2) + 0.5*log(10))/log(10)`,
  which is **308.75**. Reaching 307 needs a 0.6% error in `log`, and
  libap's is ARM's sub-ulp routine. For the failing inputs the quick
  check wants `291 > 308-17` and `289 > 308-18`; both are false.
  *Eliminated by arithmetic, not by a run -- and said so rather than
  dressed up as a measurement.*
- **`log2FLT_RADIX`** comes from `frexp((double)FLT_RADIX, &e)` and a
  `--`, so it is 1, and a wrong `frexp` there would `Tcl_Panic`, not
  overflow.
- **`frexp` and `scalbn`**, which `BignumToBiasedFrExp` and
  `SafeLdExp` rest on, were linked into a host program beside glibc's:
  **299876 random doubles and every boundary value, 0 wrong.**

So the remaining suspects are `Pow10TimesFrExp`, `BignumToBiasedFrExp`
and `RefineApproximation` -- Tcl's own code over libtommath, with none
of libap's floating point left in the path. **The next step is a
one-line `printf` of `machexp` in `MakeHighPrecisionDouble` and a
rebuild of `tclsh`**: if it is 1025 where 1024 is correct, the fault is
one binade in Tcl's own scaling, and the tables it scales with are
`pow10_wide` and `pow_10_2_n`.

*(A note on the probe itself: its first line printed `frexp(2.0)` with
`e=0` for **both** implementations, because `printf` may read `e`
before the call that sets it. The loop underneath, which sequences
properly, found zero differences. A probe that reads its own output
argument inside the same printf is measuring the compiler's argument
order.)*
