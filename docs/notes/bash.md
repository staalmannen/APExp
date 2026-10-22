# bash

bash is `/bin/sh` here and it builds APExp.  Getting there took a long
campaign whose most useful product was not any one fix but the tally at
the end: **twelve times in this investigation the INSTRUMENT was the
visible fault**, and eight mechanisms were refuted by measurement after
being argued confidently from source.  The rules distilled from that are
in `CLAUDE.md`'s *Method* section; this is the evidence for them.


---

## The bash campaign: from the allocation storm to 49 of 86

*Moved verbatim out of `CLAUDE.md` when that file
was split for 0.6.  Only the one-line consequence stayed behind there;
this is the whole record, including the wrong turns.*

**BASH IS `/bin/sh` AND IT BUILDS APExp. The whole hunt below is
CLOSED -- read it as history, not as an open problem.** `cmd/bash/mkfile`'s
`install:V:` adds `cp $BIN/bash $BIN/sh`, `dash` is gone from
`_CORE_APPS` and from `sys/src/external`, and a full `mk distclean`
plus `mk install` completes with bash serving every `sh` the build
asks for. *One shell in the tree instead of two*, which was the goal
named at the end of the fdwatch round below.
**What actually got it there, in order**: `isblank('\t')` (the
allocation storm -- the one that mattered), `getcwd(NULL,n)`, the
fourteen `config.h` features, the `FD_BUFFEREDX` exec poison, and
`mktemp`'s 26 names. **Not one of them was the descriptor leak the
first six rounds were spent on**, and the histogram that ended that
framing -- 142 opens, 251 dups, 447 closes -- is in the section below.
**AND THE SUITE WENT 0 PASSING -> 46**, measured twice in a row with
the same count. The kernel's fd warnings fell from **176 lines across
all 87 sections to 4**, and `move_to_high_fd` was never the thing to
change -- see the next paragraph.
**THE fd WARNINGS WERE THE `sh` SWAP, NOT `move_to_high_fd`, AND THE
CHAIN IS CORRECT AS IT STANDS.** `shell.c:1701` -> `getdtablesize()`
-> `sysconf(_SC_OPEN_MAX)` -> `OPEN_MAX` **256**, capped by
`HIGH_FD_MAX` 256; the loop walks DOWN from 255 for the first free
descriptor and `dup2`s there. *Every link of that is right*, and
shrinking `getdtablesize()` to dodge a kernel message would have been
the "invent semantics" shape -- **and it would also have been
unnecessary**, which is the part worth keeping.
**What changed is WHO runs the wrapper.** Before, `sh` was dash:
`dash run-X` never dups high, then forks bash for the `.tests` **with
`2>&1`**, and that bash inherits dash's SMALL fd group, grows it past
100 and 200, and puts two warnings **inside `$BASH_TSTOUT`** -- in
every one of 87 sections. Now `sh` IS bash: the top-level
`bash run-all` grows the table **once**, and Plan 9's fd group is
copied by fork and kept across exec, so every descendant starts at
`nfd` 256 and never crosses a threshold again. The surviving two
warnings sit at the very top of the log, before any section header,
from one pid. *A harmless message stopped being captured, rather than
stopping.*
**The rule: a message that corrupts a measurement can be fixed by
changing who is measured, not only by silencing the message.** The
recorded plan had been to touch `getdtablesize()` -- a wrong fix to a
problem that then dissolved on its own.
**NOT FULLY EXPLAINED, and held loosely because of it**:
`run-input-test` is the one descendant that still warns, and the
inheritance reading says it should not. It is also the only test that
feeds the script on **stdin** (`${THIS_SH} < ./input-line.sh`) and the
only one without `2>&1` -- so its warnings land in the log rather than
in a comparison, and it passes.
**`run-test` 33 -> PASS is UNEXPLAINED and BOTH readings were
REFUTED.** Its old failures were `chgrp: missing operand`,
`/dev/tty: No such file or directory`, **`ln: ... Too many links`** and
`rm: cannot remove '/tmp/ghi'` -- `Too many links` is STATEFUL, so the
first reading was litter in `/tmp` from the storm-era aborted runs,
with the refutation condition "it fails on a second consecutive run".
**Two runs back to back give the same count**, so that is refuted.
*And the replacement reading was REFUTED BY THE MACHINE*, which is
what the probe was for. I argued that `getgroups()` being a stub
returning -1 leaves `GROUPS` empty, so `chgrp ${GROUPS[0]} <file>`
gets one operand and must still fail. **`echo ${#GROUPS[@]}
"[${GROUPS[0]}]"` answers `0 [0]`** -- the element expands to **`0`**,
so chgrp gets two operands and never prints `missing operand`.
**bash seeds the array from `getgid()` when `getgroups()` reports
nothing** (`general.c:1341`, `get_group_list`), and I had read
`get_groupset` and stopped one function short. *A grep hit is a name,
not an implementation* -- a rule quoted in this file two rounds
earlier.
**And the probe found something nobody asked for**: `${#GROUPS[@]}` is
**0** while `${GROUPS[0]}` has a value, so the count and the element
disagree -- the dynamic getter fills the element but not the array the
count reads. Recorded, not chased.
**What is still unexplained is the REST of run-test**: `t -t 0 <
/dev/tty` sits OUTSIDE both `(( $UID != 0 ))` guards, so neither it
nor the `ln: ... Too many links` line was gated, and both are gone
too. The chgrp family is accounted for and the other two are not.
`run-trap` 16 -> 14 is unattributed as well. *Stop here rather than
offer a fourth story: the pass is stable over two runs and the real
list is where the work is.*
*Everything from here to the ratrace histogram is the record of how it
was found; the standing lesson is the instrument tally, not the bug.*

**(HISTORICAL, now fixed)** **bash could not be `/bin/sh`: it died `Killed: Insufficient physical
memory` during a full rebuild** -- but the log warns twice first, at
**100 and then 200 file descriptors**, and a shell running build
recipes has no business holding 200. So it is a leak with a shape.
`plan9/_buf.c` is the lead: `_startbuf` deliberately *"leave[s] fd open
in parent so system doesn't reuse it"* and forks a copy process per
buffered descriptor, both for the life of the process unless `close()`
reaches `_closebuf`. (`Muxseg` is also ~4.2 MB -- `Muxbuf bufs[256]`
at 16 KB of `data` each -- but that is demand-paged address space, so
it is the weaker candidate and is written down to be excluded.)
**Newly reachable when `READLINE` went on**, like the `FD_BUFFEREDX`
bug.
**THERE IS A REPRODUCER NOW, and it is far smaller than a full
rebuild**: `cd sys/src/external/bash/tests && /bin/bash run-all`
warns at 100 and 200 descriptors and then dies. (`THIS_SH` unset
makes line 21 run `-c` as a command; that is an artefact of running
`run-all` outside `make tests` and is **not** related -- the warnings
fire regardless, which is itself useful, since it means the leak
does not need the suite to work.)
**Three obvious suspects are already ELIMINATED by reading**, so the
next round should not spend itself there: `close()` calls
`_closebuf`, clears the flags and `_CLOSE`s the fd; Muxbuf slots
**are** recycled (`_startbuf` scans for `b->fd == -1`, which
`_closebuf` sets, so `curfds` never falling is a scan bound and not
a leak); and `dup2()` goes through `close()` rather than round it.
**The recorded plan -- `APEXP_DEBUG=1` and count
`select: buffered now fd=` -- CAN ONLY CONFIRM WHAT IS ALREADY
ASSUMED.** It counts buffering events, so it measures the
hypothesis rather than the leak: if the descriptors are ordinary
`open()`s, or pipes, or something of bash's own, it reports zero,
and zero would be read as exoneration.
**`rc/bin/fdwatch` is the instrument instead, and its FIRST version
was wrong in a way worth keeping.** It found the process by name and
took the last match -- but **a buffered descriptor gives its process
a copy process of the SAME NAME** (`ps` shows the shell in `Rendez`
and the copy process in `Pread`), so it would have watched the copy
process, which holds almost nothing, reported a flat count, and read
as *no leak*. *A measurement of the wrong process is not a null
result, it is a false one.* `-n` now prints every match and refuses
to choose; **`-c` runs the program itself**
(`THIS_SH=bash fdwatch -c /bin/bash run-all`), which removes both the
ambiguity and the race the user had to win by hand. `/proc/<pid>/fd`
lists every open descriptor of a live process **with its path**, so
one run says *what* is leaking rather than *that* something is; the
script samples it, counts (subtracting the cwd line at the top,
which is not a descriptor) and groups the paths commonest first. A
hundred lines of one path names the call site; many distinct paths
under `$TMPDIR` is a create/unlink loop; pipes are a third answer
and a different bug. *Print what the machine says rather than what
the code implies*, and **`ratrace` comes after**, once a path is
named -- ratrace on a whole suite is unreadable, which is why it is
second and not first.
**AND THE SECOND VERSION MEASURED NOTHING EITHER, for a reason worth
more than the leak**: `run-all` exhausts its descriptors and dies in
**well under a second**, while the script slept one second *before*
its first sample and then did six forks per sample (sed, wc, awk,
sort, uniq, sort) to group paths inside the loop. Its entire output
was `/proc/4314/fd does not exist -- no such process`, *which reads
exactly like a pid that was never right*. **An instrument whose
sampling period exceeds the lifetime of its subject reports a
missing subject, not a missing measurement.** Fixed by inverting
both: sample FIRST and sleep after, default interval **0** (flat
out), **one `cat` per sample** appended raw, and all the grouping
moved to a `summarise` that runs once at the end over the log --
`-s` re-runs just that, so a log can be re-read without re-running
anything.
**AND THE THIRD VERSION TOOK 0 SAMPLES TOO, WHICH IS NOW A
MEASUREMENT RATHER THAN A FAILURE.** The pid was right -- fdwatch
said 5579 and the kernel's warnings said `bash 5579` -- the loop was
reached, and `/proc/5579/fd` was **already gone at the first
`test -e`**. Between the fork and that test an rc script must run
`date`, `echo` and `test`, each a fork and an exec, and **rc cannot
read a file without forking at all**. So `run-all` dies in less time
than three forks, and *no amount of tuning makes an rc loop win
this*: it is a property of the shell, not of the interval.
**`ratrace` is therefore the tool now, and the objection to it has
expired.** It runs the command under control from the first
instruction, so there is no race:
`ratrace /bin/bash run-all >[2] /tmp/rt.log`, then the difference
between `grep -c ' open'` and `grep -c ' close'` is the leak and the
`open` lines name the paths. It was second before because ratrace on
a whole suite is unreadable -- **but a run that dies in under a
second is not a whole suite**, and that is what changed.
fdwatch keeps its job for the case it was built for: the long
`mk install` this leak was first seen in.
**Also fixed there: `^` in rc is a CROSS PRODUCT, not concatenation.**
`'x'^(a b c)` is `xa xb xc`, and `` `{date} `` is a list of six
words, so one log line came out as
`==== fdwatch pid=5579 Sun ==== fdwatch pid=5579 Sep ...`. Pass
separate arguments to `echo` rather than concatenating with a list.
**AND ratrace APPEARS TO CHANGE THE OUTCOME, WHICH WOULD RETIRE MOST
OF THE ABOVE.** Under `ratrace` the same suite runs for a long time
with heavy load instead of dying at once. *Not yet confirmed -- it
may still die later* -- but if it holds, **the failure is
RATE-dependent, and a forgotten `close` is not**: 100 descriptors is
100 descriptors however slowly you reach them, so a count-leak
cannot be outrun. What speed CAN change is how many things are alive
at once, and libap's `select()` forks a copy process per buffered
descriptor whose number at any instant is a race between the parent
making them and the children exiting. **That would also explain why
the kernel's last word is `Insufficient physical memory` rather than
anything about descriptors** -- a pile of live copy processes is
both at once, and I have been treating the two warnings as one story
without evidence.
**AND run-all's TOP LEVEL BARELY TOUCHES FILES**, which is the
reading that should have come first: its whole loop is
`for x in run-*; do echo $x ; sh $x ; rm -f $BASH_TSTOUT ; done` --
about forty iterations of fork, exec and wait. **Forty iterations
cannot reach 200 descriptors by opening files, because it hardly
opens any.** So the descriptors come a few at a time from the
machinery rather than from the work, and the suite is incidental.
**`sys/lib/tests/bash-fdloop-test.sh` is that loop with the tests
taken out** -- three sections of 400 iterations: no fork, fork plus
exec, and fork plus exec plus a redirection, each printing the
descriptor count *and the bash/sh process count* from `/proc`. **The
pair is what carries the result**: 1 surviving while 2 dies puts the
leak in fork/exec/wait and turns an 83-file suite into three lines.
**Reference measured on glibc: 5 descriptors, flat throughout.**
*`/proc/<pid>/fd` is a FILE on Plan 9 and a DIRECTORY on Linux*,
which the host run caught by reporting -1 everywhere.
**IT REPLICATES THE CRASH -- 400 iterations of a shell loop, no test
suite at all.** So the 83-file suite really was incidental.
**But the first version could not say WHICH loop**, and both faults
were mine: (1) section 1 was meant to be the fork-free control and
was not, because the counter was `` `expr $i + 1` `` and **`expr` is
an external command** -- all three sections forked 400 times, so the
pair that carried the whole result distinguished nothing. *A control
that does the thing it is controlling for is not a control.* Bash's
`$((i+1))` is a builtin. (2) everything went to **stdout, which is
buffered**, while the kernel's warnings go straight to the console --
so the run printed `exceeds 100 file descriptors` *before* the
script's own first line, which reads like the descriptors being gone
before the script started and is only a buffer. Everything goes to
**stderr** now, and a **section 0** forks 200 times printing the
counts every 25, so the output is a RATE rather than a verdict --
and it comes first, because a run that dies having printed a slope
has still answered.
**AND THE ratrace LOG ALREADY HELD THE ANSWER while I asked it the
wrong question.** I said I would not guess the format and then told
the user to `grep -c ' open'`; ratrace capitalises, so all four
counts came back 0 from a 272 MB, 3.4-million-line log. Its last
twenty lines are `Brk` over and over, the break climbing ~480 bytes
a time, ending in `fault read addr=0x0` -- **a null dereference,
which is `malloc` returning 0.** So the primary phenomenon is MEMORY
and the descriptors may be the side effect, which is the opposite of
the framing every round so far has used. The histogram
(`awk '{print $3}' /tmp/rt.log | sort | uniq -c | sort -nr`) names
every syscall by frequency and needs no re-run.
**THE INSTRUMENT WAS STILL THE PROBLEM, A THIRD TIME, AND THE SHAPE
IS ALWAYS THE SAME.** Moving to stderr did NOT fix the ordering: the
warnings still printed before the script's first line, and `start:`
never appeared at all. **Because counting the descriptors FORKED** --
`fdcount` ran `wc -l` inside `$( )`, a subshell plus an exec, per
sample, *in a test whose entire subject is what forking costs*. The
run could die inside its own first measurement, which is exactly
what "pid, then nothing" looks like. `fdcount()` now forks NOTHING:
a `read` loop on Plan 9 (where `/proc/<pid>/fd` is a FILE), a glob
on Linux (where it is a DIRECTORY), both builtins, answering in a
**variable** rather than through `$( )`. And every step appends to
**`/tmp/fdloop.log`**, which survives the kill and is in the order
it happened -- *console ordering is not evidence when one writer is
the kernel*. Counts at 1, 2, 5, 10, 20, 50, 100, 200 forks, so the
slope near zero is visible before anything can die. glibc: flat at
5 throughout.
Back on dash meanwhile, and the goal is one shell rather than two.
*(That goal is MET -- bash is `/bin/sh` and dash is out of the tree.
See the top of this section.)*

**coreutils `sort` COULD NOT MAKE A TEMPORARY FILE, AND IT IS OURS
-- FIXED, NOT YET MEASURED ON THE VM.** `sort: cannot create
temporary file in '/tmp': empty file name`, hit while trying to
histogram a 272 MB ratrace log. **libap's `mktemp` could produce 26
names per process, ever**: it wrote `getpid() % 100000` into five of
the six X's and tried one trailing letter `a`..`z`, then set
`*template = 0`. So the 27th temporary any program asked for failed,
the caller opened `""`, and Plan 9 said `empty file name` -- **a
Plan 9 errstr arriving through libap's `EPLAN9` arm, so the text
after the colon describes the last system call rather than the
directory the message names.** Read as a `/tmp` problem it leads
nowhere. `mkstemp`'s twenty retries re-derived *the same twenty-six*,
since nothing in them varied but the pid: **a retry is only a retry
if something varies between the tries.**
**The tree already had the right generator and was not using it** --
musl's `__randname` sits in the same directory, is already in
`OFILES`, and `mkdtemp.c` beside it has always used it. So libap
held a working name generator and a broken one at once. Both now use
it (~1.07e9 names); `mkstemp` is shaped like `mkdtemp`, retries only
on `EEXIST`, and restores the template on failure; `mkostemp` now
applies `O_CLOEXEC` with `fcntl` rather than dropping it.
**Measured, not argued**: the old algorithm replicated on the host
gives up at **exactly file 27**, 26 of 64. `mkstemp-test.c` asks for
**64 at once** precisely because anything at or below 26 would have
passed against the bug; 0 failures on glibc. `_tempmark()` is the
version marker, so the test will not LINK against a libap predating
the fix.
**Why it survived**: the failure arrives only at the 27th, so a
program making a handful of temporaries is fine for ever and one
making dozens dies.
**CONFIRMED ON THE VM**: `_tempmark = 1`, 5 of 5, 0 failures.

**THE BASH FAILURE IS NOT A DESCRIPTOR LEAK. IT IS MALLOC, AND THE
HISTOGRAM SAYS SO IN ONE LINE.** Over the whole 3.4-million-line
ratrace log:

```
3456769 Brk          447 Close       142 Open
    251 Dup          160 Pread        86 Stat
     58 Create        56 Pwrite        2 Rfork      1 Exec
```

**142 opens and 251 dups against 447 closes** -- it closes MORE than
it opens, so there is no descriptor leak at all, and every round of
this hunt was chasing one. **`Brk` outnumbers everything else by four
orders of magnitude.**
**And `2 Rfork`, `1 Exec`: the process died before the suite ran a
single test**, so the storm is the whole run rather than something
the tests provoked.
**THE KERNEL'S fd WARNINGS ARE ALMOST CERTAINLY NOT A LEAK EITHER.**
bash's `move_to_high_fd()` dups its internal bookkeeping descriptors
up near the reported limit, and Plan 9's fd *table* grows to the
highest index used -- so 251 dups give `exceeds 100/200 file
descriptors` with a handful of files actually open. That is why the
warnings arrive **before the script's first line**: it is bash
starting up, not the script leaking. *Two warnings printed together
are not one story, and I treated them as one for six rounds.*
**THE ARITHMETIC NAMES THE SIZE CLASS.** `_malloc_brk` does
`sbrk(0)` then `sbrk(gap+n)` -- **two Brk syscalls per call**, which
is why the log shows each address twice. So ~1.73M allocations. The
break moves ~480 bytes each, and with `CUTOFF = 12` and
`BLKSZ(pow) = 32 + 2^pow` batched `(CUTOFF-pow)+2` at a time, **pow 4
gives 48 x 10 = 480 exactly**. So these are allocations of **<= 16
bytes, ten per sbrk pair: about 17 million tiny objects, none
freed.**
**THE DEATH IS A JUMP TO ZERO, AND IT IS THE CONSEQUENCE RATHER THAN
THE EVENT.** The last non-`Brk` lines:

```
5878 bash Exits ... = process exited            <- the $( ) child
5875 bash Await ... "5878 0 0 40 ''" = 14       <- parent reaps it
5875 bash Pread ... 255 ... ".BASH_TSTOUT=${TMPDIR}/..." = 1149
5875 bash Stat  ... "/proc/5875/wait"    (x3)
5875 bash Noted 2d10a7 1 = 0
bash 5875: suicide: sys: trap: fault read addr=0x0 pc=0x0
```

**`pc=0x0` is a JUMP to address zero** -- a call through a null
function pointer, not a bad data pointer -- and `Noted 1` is
`noted(NDFLT)`, libap's note handler returning, immediately before
it. Plan 9's `Insufficient physical memory` **is a note**, so the
order reads: memory exhausted -> kernel posts the note -> libap's
handler runs -> control goes to 0. *The crash is downstream of the
storm; do not chase `pc=0` as the bug.*
**`fd 255` is bash reading its own script** -- which is also the
`move_to_high_fd` that explains the descriptor warnings.
**`wait4`'s WNOHANG path allocates (`_dirstat`) but is NOT the
storm**: the trace shows THREE stats of `/proc/5875/wait`, not
millions. *It does hold a real bug, recorded not measured*: when
`_dirstat` returns nil it falls through to the **blocking** `_WAIT()`
with `WNOHANG` set, and the same happens when the pending message
belongs to a different pid.
**THE LINE NUMBERS LOCALISED IT TO ONE BURST, AND EXCLUDED EVERY I/O
MECHANISM.** `grep -n -v ' Brk ' /tmp/rt.log | tail -40`:

```
   1581:5875 bash Stat ... "/proc/5875/wait" = 71
3458015:5875 bash Noted 2d10a7 1 = 0
3458016:bash 5875: suicide: fault read addr=0x0 pc=0x0
```

**3458015 - 1581 = 3456434 of the 3456769 `Brk` lines -- 99.99% -- in
a SINGLE gap**, so the storm is one event rather than something
accumulating across the run. The prediction written before the grep
(gap opens after the `Pread` of fd 255, closes at the `Noted`) held,
and its refutation condition (a gap before the `Await`, which would
have put `wait4` back in frame) did not fire.
**And the gap contains NO SYSCALL OF ANY KIND**, which is an
exclusion rather than a detail: a spinning READ loop would show
`Pread`, a spinning WAIT loop `Await`/`Stat`, a create/retry loop
`Open`/`Create`. None appear. So the loop is pure computation holding
~17M objects of <= 16 bytes.
**`read_comsub` is refuted by that same fact** -- it calls `zread`
every iteration and grows by doubling `realloc`, so a loop there
would show `Pread` lines. Five mechanisms argued from source now,
five refuted by the log.
**malloc and free are NOT at fault, checked rather than assumed**:
`free()` pushes straight onto `btab[size]` so the free list does
refill, `BLKSZ(4)=48` and `(CUTOFF-4)+2 = 10` give the observed 480
exactly, and the batching loop links all nine spare blocks
correctly. The 17 million objects are genuinely live. It is a bash
loop, and the trace places it after line 21's `$( )` child was
reaped -- line 1563 shows that child writing `"30465"` to fd 1, so
it RAN AND SUCCEEDED.
**AND THAT IS WHY SIX ROUNDS FOUND NOTHING: `Insufficient physical
memory` IS A KILL.** The kernel destroys the process, so there is no
stack to take and nothing for `acid` to attach to -- every round of
this hunt examined a corpse the kernel had already disposed of, and
the only evidence available was a trace of the one syscall the loop
happened to make. **Two instruments now, and neither needs the
other:**
- **`sys/lib/tests/bash-comsub-test.sh`** bisects run-all's lines
  17-27 into ten sections, each writing a durable marker to
  `/tmp/comsub.log` *before* the statement it runs, so **the last
  line names the statement that did not return**. Simplest first,
  every case expected to return ahead of every case expected to
  hang. Nothing in it forks but the sections about forking -- `echo`
  plus `>>` is a builtin and a redirection, the mistake `fdwatch`
  and `bash-fdloop-test` each made twice. glibc: all ten ok in 13ms.
- **`$APEXP_MALLOCMAX` (megabytes), a heap watchdog in
  `malloc/malloc.c`.** Abort EARLY, while the machine is healthy:
  `APEXP_MALLOCMAX=64` breaks the process after 64 MB instead of
  ~800, leaving it Broken rather than gone, and `acid <pid>` then
  `stk()` names the calling function -- how gnulib's self-recursive
  `strerror` and `_buf.c:544` were both settled after source reading
  failed on them. Counts **both** sbrk sites: `_malloc_growtop` has
  the same two-`Brk` signature as `_malloc_brk`, so a trace cannot
  tell them apart and a watchdog watching one could report a flat
  heap while the break ran away. `wd_fail` unlocks the arena before
  `abort()`, since aborting under our own lock would hang where a
  break was wanted. Off unless set, at one load and one branch per
  sbrk.
  **ITS FIRST VERSION BROKE EVERY APE PROGRAM IN THE TREE, and the
  reason is worth more than the instrument.** It read
  `$APEXP_MALLOCMAX` lazily on the first sbrk, and I checked the
  thing that seemed to matter -- *does `getenv` allocate?* It does
  not (`ap/env/getenv.c` is a plain scan). **That was the wrong
  question.** `environ` is CREATED BY a malloc:
  `plan9/_envsetup.c:140` is `environ = pp = malloc(...)`. So on the
  first allocation of every APE program `environ` is still null, and
  getenv has no null check -- so `while(*p != NULL)` faults at
  address 0 before `main`. *Not a re-entrancy bug but a CIRCULAR
  DEPENDENCY: the allocator asked for state that the allocation was
  being made to create.* The general form is worth carrying:
  **"does it allocate?" is only half of "is it safe to call from the
  allocator" -- the other half is "does it depend on anything
  allocated?"**, and for libc globals the answer is usually yes.
  `_malloc_watchinit()` is now called from **`_apemain`, right after
  `_envsetup()`** -- the same "one path every APE program takes"
  that `argv0` uses -- so the allocator calls nothing at all and
  only tests a static. Allocations before that point are unwatched,
  which is the safe direction to be wrong in.
*The general shape, and it is new: a failure mode that KILLS leaves
nothing to measure, so the instrument's job is to fail earlier and
more politely than the kernel does.* **And its cost, immediately:
that is the FIFTH time in this investigation the instrument has been
the visible fault** (fdwatch's sampling period, fdwatch's `-n`,
fdloop's `expr` control, fdloop's forking `fdcount`, and now this).
**A Broken process KEEPS ITS MEMORY**, so `acid` must be followed by
a kill, or a few aborted runs exhaust a small VM by themselves.

**AND THE ACCIDENT NAMED A LINE IN bash: `ifs_value` IS NOT A
POINTER.** The one run that happened gave a full `acid` stack:

```
bash 1764: suicide: sys: trap: fault read addr=0x2e pc=0x2310ad
list_string(separators=0x428891, ...) subst.c:3133
expand_word_internal(...)  subst.c:12072   ifs_chars=0x2e
call_expand_word_internal / expand_string_assignment / 
expand_assignment_string_to_string / assign_in_env variables.c:3598
do_assignment_statements / expand_words / execute_simple_command
```

`subst.c:3133` is `for (xflags = 0, s = ifs_value; s && *s; s++)`,
and 12072 is `list = list_string (istring, "", quoted)` -- so
`separators` is the literal `""` and the fault is
**`*ifs_value` with `ifs_value == 0x2e`**, i.e. the byte `'.'` in a
`char *`. The caller's `ifs_chars=0x2e` agrees. Declarations are
consistent (`char *` in `subst.h:353` and `subst.c:161`), so it is
runtime corruption, not a type mismatch.
**One corruption would explain BOTH symptoms**, which is why it is
worth chasing: with `ifs_value` garbage, `list_string` either faults
on it (this run) or, if the garbage happens to address readable
bytes, splits a string into millions of words -- and every word is a
retained `WORD_DESC` plus `WORD_LIST` node, small and never freed.
*That is exactly the storm's signature: ~17M live objects of <= 16
bytes and no syscall in the loop.* And the path is the same one the
line numbers localised the storm to: assignment expansion, straight
after line 21's `$( )`.
**PROVENANCE IS UNSETTLED AND MUST BE BEFORE THIS IS BUILT ON.**
The new libap faults at 0x0 before `main`, yet 1764 reached
`reader_loop` -- so 1764 was most likely a bash predating the libap
install, which would make the stack clean evidence about bash. That
is an inference, not a measurement. **Re-run it after the rebuild**;
if the same stack comes back, it is bash's and this is the bug.

**SECOND INSTRUMENT BUG, SAME FUNCTION: `abort()` ALLOCATES ON
PLAN 9, so the watchdog re-fired inside its own abort.** The fixed
libap starts bash again, and the run gave an `acid` stack that was
nothing but its own recursion, thousands of frames deep:

```
wd_fail()             malloc.c
_malloc_brk(n=0x1e0)  malloc.c
malloc()              malloc.c
open(flags=0x1, ...)  fcntl/open.c:76
note(...)             signal/kill.c:16
kill(sig=0x5, ...)    signal/kill.c:58
abort()               stdlib/abort.c:8
wd_fail()             <- round again
```

`abort()` raises SIGABRT, libap's `kill()` posts a note, `note()`
OPENS `/proc/<pid>/note`, and `open()` mallocs -- so the over-limit
allocator is re-entered from inside its own abort and buries the
stack it exists to expose. **I had written "abort() may allocate" in
the comment justifying the unlock and then not drawn the
conclusion**: `wd_fail` now clears `wd_max` as its FIRST statement,
so the abort path allocates freely and the message prints once.
*Sixth instrument fault; and unlike the others this one was named in
my own comment one line above the bug.*
**One thing that stack settles for free**: `_malloc_brk(n=0x1e0)` is
**480**, which independently confirms the size class derived from
the trace's break steps -- `BLKSZ(4) * ((CUTOFF-4)+2) = 48 * 10`.

**AND THE BISECT ANSWERED BY RETURNING NOTHING, WHICH RETIRES ITS
OWN PREMISE.** `/bin/bash bash-comsub-test.sh` printed the two fd
warnings, died `Insufficient physical memory`, and then
`cat: /tmp/comsub.log: No such file or directory`. The log's first
line is written by `mark "bash-comsub-test: pid $$"`, the script's
first statement -- **so bash never executed one line of it.**
Therefore the storm is NOT in `run-all`'s lines 17-27, and none of
the ten sections is the trigger; it is in bash's startup or its
first statement. That agrees with two things already recorded: the
histogram's `2 Rfork, 1 Exec` (dead before the suite ran anything)
and the fd warnings arriving before the script's first line.
**And it gives a sharp discriminator nobody had asked for:
INTERACTIVE bash works -- the prompt those commands were typed at is
bash -- while NON-INTERACTIVE `bash <script>` dies.** So the next
reproducer is not a script at all:

```
APEXP_MALLOCMAX=32 /bin/bash -c 'echo hi'
```

**AND IT IS CLEAN: `hi`, no storm, AND NO fd WARNINGS EITHER.** The
second half was not asked for and is the more useful of the two: the
`exceeds 100/200 file descriptors` pair did not appear at all, so the
warnings and the storm arrive *together*. They may still be two
effects of one cause rather than one story -- but "printed together
and absent together" is a good deal more than they had before.
**So the whole remaining search space is the gap between `-c` and a
script file**, and it is small. `rc/bin/bash-scriptladder` walks it
in one run: `-c` (the control), an **EMPTY** file, a one-line file,
and the same content on **stdin**. **It is an rc script on purpose**
-- the subject dies, and a harness written in the dying shell dies
with it; rc survives every case and prints a `returned` line after
each, so a missing one names the case that storms. No loop (rc has
no `break`), no `^`, and the only `=` are leading assignments, which
rc does allow.
Reading it: **empty file storms** -> parsing and execution are
innocent and it is the script-FILE setup, where fd 255 and
`move_to_high_fd()` live, which is the smallest possible target;
**3 storms but 4 does not** -> the NAMED FILE specifically rather
than reading a script as such; **3 and 4 both** -> reading a script
at all; **nothing storms** -> it needs something
`bash-comsub-test.sh` has and these do not, and its HEADER is what
to bisect next, not its sections.
**No watchdog in the ladder, deliberately**: it only needs to know
*which* cases storm, and `hi` versus a death message answers that,
while `APEXP_MALLOCMAX` would leave a Broken process holding 32 MB
*per failing case*. Re-run only the smallest storming case with the
watchdog, take the stack, then `echo kill > /proc/<pid>/ctl`.

**THE LADDER RAN AND NOTHING STORMED -- AND IT REFUTED WHAT I WROTE
ONE ROUND EARLIER.**

```
1  bash -c 'echo hi'      hi         no warnings   returned
2  an EMPTY script file   (nothing)  WARNINGS      returned
3  a one-line file        hi         WARNINGS      returned
4  the same on stdin      hi         no warnings   returned
```

**The fd warnings are now SEPARATED from the storm.** Having seen
`bash -c` come back with neither, I recorded that they "arrive
together and vanish together" -- and case 2 breaks that in the
cleanest way available: an **empty** script file raises both
warnings and then **exits successfully**. So they are
`move_to_high_fd()` on the script descriptor exactly as predicted,
they are produced by the NAMED FILE and nothing else here, and
**they are harmless**. *A run that warns has said nothing about
whether it will die.* Two rounds ago they were conflated with the
storm; one round ago I linked them on evidence that looked stronger
than it was; a single measurement has now separated them. **Stop
reading them as a symptom.**
**And the storm is not the script file at all** -- not parsing, not
a named file, not reading a script.
**WHAT ALL FOUR CLEAN CASES SHARE IS THAT NOT ONE OF THEM FORKS.**
`echo` is a bash builtin, so 1, 3 and 4 run it in the shell itself
and 2 runs nothing. Against that, **every case that has ever
stormed forks**: run-all's line 21 is `SUFFIX=$( ... )`,
`bash-comsub-test.sh`'s third statement is `rm -f $LOG`,
`bash-fdloop-test.sh` is 400 iterations of fork/exec/wait -- and
the histogram over the whole dying run was `2 Rfork, 1 Exec`, with
the storm starting right after the one child was reaped.
**`rc/bin/bash-forkladder` asks that**, same rc harness: `-c` with
an EXTERNAL echo (one fork), `-c` with a command substitution
(fork + pipe + reap), each again from a FILE, and **case 5, the
first four statements of `bash-comsub-test.sh` verbatim in shape**
-- an assignment, an external command, a function definition and a
call. *Case 5 is what keeps the ladder honest*: if even that
returns and writes its log, the failure has stopped reproducing and
the whole reading above is about a bug that is no longer there,
which is worth knowing at once rather than after another reduction.

**IT RAN, AND THE FORK HYPOTHESIS IS REFUTED -- CASE 5 ALONE
STORMS.**

```
1  -c with an EXTERNAL echo        hi            returned
2  -c with a COMMAND SUBSTITUTION  hi            returned
3  a FILE with an external echo    hi            returned
4  a FILE with a substitution      hi            returned
5  bash-comsub-test.sh's opening   KILLED, no log
```

The refutation condition was written down and it fired: 1 to 4
fork, exec, build a pipe, read a child's output and reap it, from
`-c` and from a file, and **every one came back**. *Four mechanisms
cleared in a single run, which is what a ladder is for -- and case
5 still dying is what says the bug has not evaporated under us.*
**So it is what case 5 has and case 4 has not**: an external command
taking a VARIABLE-expanded argument, a function DEFINITION, a
function CALL, a `>>` redirection inside a function, and **`"$*"`**.
**`$*` IS THE SUSPECT, AND THE REASON IS NOT TASTE: it is the one
construct in case 5 that reads IFS.** It joins the positional
parameters with IFS's first character through
`string_list_dollar_star` (`subst.c:2900`), which reads
`ifs_firstc`/`ifs_firstc_len`; nothing in cases 1 to 4 touches IFS
at all. **And that is where the single stack this hunt has produced
already pointed** -- `fault read addr=0x2e` in `list_string` on
`s = ifs_value`, with `ifs_value` holding `'.'`. *Two independent
lines arriving at IFS from opposite directions -- a stack that
faulted on it, and a ladder whose only storming case is the only
one that reads it -- and the convergence is worth more than either
alone.* It also makes the unsettled provenance of that stack much
less important.
**`rc/bin/bash-ifsladder` splits case 5 into its five parts**, IFS
last: `${#IFS}` as a **direct probe** (pure builtin, and a healthy
bash answers **3**), an external with a variable argument, a
function definition, a definition plus call, a `>>` inside a
function, then `"$@"` and `"$*"` at top level, then case 5 again
unchanged. **`$@` is asked beside `$*` deliberately**: they differ
in exactly the thing under suspicion, since `$*` JOINS with IFS's
first character and `$@` does not join at all -- *asking only one
would leave a negative result with two explanations*. All eight
return on glibc and case 1 answers 3.

**IT RAN, AND IFS IS REFUTED TOO -- ONLY THE FILE STORMS.**
`${#IFS}` answers **3**, `"$*"` joins to `a b c`, `"$@"` likewise,
and the variable argument, the function definition, the call and
the `>>` inside a function all return. **Cases 1 to 7 clean; case
8, the same thing in a FILE, killed.** So the construct my two
converging lines pointed at works perfectly.
**AND THAT REFRAMES THE ONE STACK THIS HUNT HAS PRODUCED.** The
watchdog's `fault read addr=0x2e` was `s = ifs_value` with
`ifs_value` holding a `'.'`. If reading IFS is healthy in isolation
-- and case 7 says it is -- then **memory was ALREADY corrupt by
the time that frame ran**. *The stack shows a VICTIM, not a
culprit*: something had written a character into a `char *` in BSS.
Chasing `setifs` would have been chasing the wrong end, and the
convergence I called worth more than either line alone was two
lines pointing at the same casualty.
**ONE STRUCTURAL DIFFERENCE HAS NEVER BEEN ASKED.** Every `-c` case
passes and every FILE case so far passed -- empty, one-line, with a
substitution -- so it is not "a file" as such. **But every file
tested held ONE-LINE commands, and case 8's function definition
spans three lines.** A multi-line compound command is the first
thing in this investigation that makes bash's PARSER ask its input
for more *while a command is still open* -- `shell_getc` refilling
`shell_input_line` from fd 255 mid-command. Through `-c` the whole
text is in memory and that path is never entered.
**`rc/bin/bash-fileladder` asks it**, all from files: a ONE-LINE
function; the same function over THREE lines; multi-line with
`"$*"`; multi-line with `>>`; **a multi-line `if/then/fi`, which is
a compound command that is not a function**; and case 8 unchanged.
*That fifth case is what makes it a bisect rather than a guess* --
if a multi-line `if` storms, functions are cleared entirely and the
subject is the parser's refill; if it does not and the multi-line
function does, the opposite. Same reason `$@` was asked beside
`$*`. Indentation is a TAB everywhere, as case 8's was, so it is
not a hidden variable. All six return on glibc.

**AND IT ANSWERED: A COMMAND THAT SPANS A NEWLINE IN A SCRIPT
FILE.**

```
1  a ONE-LINE function in a file       hi      returned
2  the same function over THREE lines  KILLED
3  multi-line + "$*"                   KILLED
4  multi-line + >>                     KILLED
5  a multi-line if/then/fi             KILLED   <- NOT a function
6  case 8 unchanged                    KILLED
```

**Case 5 carries the result**: a compound command that is not a
function, dying exactly like the rest. So **functions are cleared
entirely**, and with them `$*`, `>>`, the variable argument and the
external command. The discriminator is the single thing cases 2-6
share and case 1 does not -- a newline *inside* a command -- which
is the first thing in this investigation that makes bash's input
layer deliver more text **while a command is still open**. `-c` has
the program in memory and never enters it; a file of one-line
commands never needs it, which is why every earlier file case
passed. *Seven mechanisms refuted by measurement now -- descriptor
leak, copy processes, `wait4`, `pc=0`, `read_comsub`, forking, IFS
-- one run each.*
**`rc/bin/bash-lineladder` asks the one remaining question that
changes WHICH FILE to read**, since "spans a newline" has two
implementations behind it: the **LEXER** wanting another line (a
backslash continuation, an unterminated quote -- `shell_getc` at
`parse.y:2475` refills `shell_input_line` and the grammar never
sees an incomplete command) versus the **PARSER** wanting one (an
open `if`, `{`, function body or dangling `|`, where the grammar is
mid-rule). Five cases: a continuation, a quote across a newline, a
`{ }` group, a pipeline broken after `|`, and the `if` as control.
All five return on glibc.
**Then the stack, which is finally cheap** -- the subject is four
lines instead of an 83-file suite:
`APEXP_MALLOCMAX=32 /bin/bash /tmp/bli-5.sh`, `ps | grep bash`,
`acid <pid>`, `stk()`, then `echo kill > /proc/<pid>/ctl`.

**IT RAN, AND "ANY COMMAND SPANNING A NEWLINE" IS REFUTED TOO.**

```
1  backslash continuation   (lexer)   hi there   returned
2  a quote across a newline (lexer)   a / b      returned
3  a { ... } group          (parser)  KILLED
4  a pipeline broken after| (parser)  hi         returned
5  if/then/fi               (parser)  KILLED
```

**Case 4 is the one that carries it.** `echo hi |` then `cat` spans
a newline, the parser wants another line, and it **returns** -- so
"the input layer delivering more text mid-command" is cleared as
well, and so is the lexer's refill (1 and 2). What is left is
**`{ }` and `if/fi`: a newline token reaching the GRAMMAR inside an
open COMPOUND command.** In 1, 2 and 4 the newline never becomes a
token -- the backslash removes it, the quote absorbs it, and bash
skips newlines after `|`. *Eight mechanisms refuted by measurement
now, and the reproducer is three lines: `{`, `echo hi`, `}`.*
**Still open and cheap after the stack**: whether it is the
RESERVED WORD or the compound command, which a multi-line
**subshell** `( ... )` would split, since it is compound and not a
reserved word.
**AND THE WATCHDOG COULD NEVER HAVE LEFT A BROKEN PROCESS -- note
semantics, measured.** The limit fired at 33554656 bytes in 72507
sbrk calls, and then the process was simply GONE: `ps` showed
nothing, `acid 13576` answered `can't open /proc/13576/text`.
`abort()` is `kill(getpid(), SIGABRT)`, which posts a note whose
string is an ordinary word; libap does not handle it, so
`signal.c:102` reaches `_NOTED(1)` (NDFLT) and **the kernel's
default for a plain note is to EXIT**. Only a `sys:` note -- a real
trap -- makes a process break and stay. *So the instrument promised
a Broken process that its own mechanism could not produce.*
**`wd_fail` now SLEEPS instead**, printing the pid twice (to attach
and to kill) and napping for up to fifteen minutes before
`_EXITS`. Faulting deliberately would also break it, but that puts
the instrument back on note semantics and on whatever SIGSEGV
handler the subject has installed; **sleeping removes the question
-- `acid` attaches to a LIVE process**, which is how `_buf.c:544`
was found here, and `ps` shows the subject sitting in `Sleep`
rather than needing to be caught. *Seventh instrument fault.* The
`_SLEEP`/`_EXITS` prototypes are copied exactly from `sys9.h`
rather than recalled, since kencc widens an argument only when a
prototype is visible.

**AND THE SLEEPING WATCHDOG WORKED: `33540K Sleep bash`, `acid`
attached, FULL STACK.**

```
_SLEEP(a0=0x3e8)                      syscall/_SLEEP.s:6
wd_fail()                             malloc.c:195
_malloc_brk(n=0x1e0)                  malloc.c:261
malloc()                              malloc.c:361
xmalloc(bytes=0x10)                   bash/xmalloc.c:104
make_word_list(word=.., wlink=..)     bash/make_cmd.c:156
make_simple_command(command=0x489370, line=0x2, element=..)  make_cmd.c:488
yyparse()+0x1c13                      y.tab.c:2629
parse_command() / read_command() / reader_loop() / main
```

**`y.tab.c:2629` is inside case 62, `simple_command: simple_command
simple_command_element`** -- the rule that appends ANOTHER WORD to
an existing simple command. Case 61 is the same call with
`(COMMAND *)NULL`, and the frame's `command=0x489370` is non-null,
**so it is case 62 and not 61**.
**So the parser is appending word after word to one simple command
for ever, which means `yylex` is returning an ENDLESS STREAM OF
WORD TOKENS.** The parser is doing exactly the right thing with the
tokens it is handed; **the bug is in the LEXER**, and every
allocation is a 16-byte `WORD_LIST` node.
**`xmalloc(bytes=0x10)` is `sizeof(WORD_LIST)` exactly** -- two
pointers -- which is the `<= 16 bytes` class the ratrace break
steps predicted. *Those two routes really are independent*: one is
arithmetic over `sbrk` deltas in a dead process, the other a live
frame's argument. Unlike the `ifs_value` "convergence", neither is
downstream of the other.
**Calibration worth keeping**: the `ifs_value` reading got the
OBJECT right -- "every word is a retained `WORD_DESC` plus
`WORD_LIST` node, small and never freed" -- and the PRODUCER wrong,
naming `list_string` where it is the parser. *A correct prediction
about the artefact is not a correct prediction about the code that
makes it.*

**FOUND, AND IT IS ONE MISSING FLAG ON ONE TABLE ENTRY:
`isblank('\t')` ANSWERED FALSE.** The second sample named it --
`read_token_word(character=0x9)`, TAB, with `xmalloc(bytes=0x1)`,
so `1 + token_index` is 1 and **the word is EMPTY**.
The chain, every link measured:
1. `ap/ctype/ctype.c` gave TAB `_ISspace|_IScntrl` with **no
   `_ISblank`** (the offsets in that file are OCTAL: entry 11 is 9).
   C99 7.4.1.3 wants isblank true for exactly space and tab.
2. bash's `syntax.c` is **generated** by its own `mksyntax`, whose
   `addblanks()` is `if (isblank (uc)) lsyntax[uc] |= CBLANK;` --
   with the comment *"the default blank characters will be space and
   tab"*. So the shipped table gave TAB `CSHBRK` and no `CBLANK`,
   **contradicting its own generator's stated intent**, which is what
   proves it was generated against a broken `isblank`.
3. `shellblank()` reads CBLANK, `shellbreak()` reads CSHBRK. So a tab
   was **not whitespace to skip** but **was a word delimiter**.
4. `read_token` therefore handed the tab to `read_token_word`, which
   ungot it and returned a zero-length WORD; the parser appended the
   empty word (case 62) and asked for another token. For ever, one
   16-byte `WORD_LIST` per turn.
**EVERY LADDER RESULT FALLS OUT OF IT**: one-line commands, the
backslash continuation, the quote across a newline and the dangling
`|` have no tab; `{`/`if`/the function bodies were all written
TAB-INDENTED. So "compound command" was never the discriminator.
**AND I MADE IT INVISIBLE MYSELF.** `bash-fileladder`'s header says
*"Indentation is a TAB everywhere, as case 8's was, so it is not a
hidden variable between the cases."* Holding a variable constant
removes it as a confound **and removes any chance of detecting it**
-- it was the cause, and I had frozen it deliberately in every case
of three ladders. *Control for a variable and you also blind
yourself to it; the things you standardise are the things a bisect
can never name.*
**FIXED IN FOUR PLACES, and the library alone would not have been
enough**: `_ctype[9]` gains `_ISblank`; **`isprint` had to change
with it**, because its mask was `(graph bits | _ISblank)` and used
_ISblank as a stand-in for "space" -- correct only while space was
the sole character carrying it, so the tab fix alone would have made
`isprint('\t')` true. It is a FUNCTION now, not a macro, since
`isgraph(c) || c == ' '` cannot be a macro without evaluating `c`
twice. And **`bash/syntax.c` is corrected by hand**, because it is
checked in and the mkfile compiles rather than regenerates it, so
the wrong answer was frozen there at generation time.
**`ctype-xcheck.c` sweeps all 256 x 12 rather than asking about
tab**, since the table is hand-written and one wrong entry is as
likely as another: **0 of 3072 wrong** now, and the old table
replicated beside it gives **exactly 1** -- `TAB isblank glibc=1
libap=0` -- which both confirms the fix and says nothing else in the
table was wrong.
**The sweep for other frozen answers is bounded and clean**:
`mksyntax` is the only build-time generator in `external/` that asks
`isblank`, and `syntax.c` the only file it produces. Every other
`isblank` caller is a runtime one and simply gets the right answer
now.
**CONFIRMED ON THE VM: `run-all` GETS PAST THE STORM.** The same
command that has died for weeks now runs real tests and prints real
output -- `comsub-posix.tests`, `comsub-posix6.sub`, the
syntax-error cases, `argv[1] = <abcde>` and the rest. **bash no
longer dies of the allocation storm**, and since the only changes
were `_ctype[9]`, `isprint` and one entry in `syntax.c`, the chain
is measured end to end rather than argued.
**It then FROZE at `run-comsub2`, and that one is NOT OURS: the
test picks a command name that EXISTS on Plan 9.**
`comsub2.tests:68` is `echo NOT${ p; }FOUND`, under the comment
*"command not found should still echo error messages to stderr"* --
the name `p` is chosen precisely because a unix has no such
command. **9front's `/bin/p` is the pager.** bash found it, exec'd
it, and `p` blocked reading stdin for ever.
**Measured end to end, and `ps` did most of it.** Four processes,
one chain: `1771 bash` (`/bin/bash run-all`) -> `2298 sh`
(`sh run-comsub2`) -> `2299 bash` (`bash ./comsub2.tests`) ->
**`2306 p`, in `Pread`** -- every one of the first three in
`Await` at 0:00 CPU. Both stacks name their child by pid and the
arithmetic closes it: 2299's `wait_for(pid=0x8fa)` is **2298**,
and 2299's `wait_for(pid=0x902)` is **2306**, the pager. 1771's
frames are `execute_for_command`/`execute_case_command`, which is
`run-all`'s own `for x in run-*` loop. *No libap call is
misbehaving*: `wait4` is blocked on a child that genuinely has not
exited.
**The output file is what placed it, with no instrument at all.**
`$BASH_TSTOUT` survives the freeze (the `trap ... 0` that removes
it never fires), and its last line is line 65's `set: +m: invalid
option`. Normally a block-buffered log's tail is a lower bound --
but that line is **stderr**, unbuffered, and line 68's whole
purpose is to write to stderr too, so its ABSENCE is real position.
*Check which stream a log's last line came from before discounting
it for buffering.*
**The collision is checkable and `p` may not be alone.** The
`.right` files expect these to be missing: `a`, `after`, `foobar`,
`hijkl`, `notthere`, `p`, `qfoo`, `quux`. **A collision only HANGS
if the program reads stdin**; one that exits produces a wrong diff
and reads as an ordinary failure, so the hang is the loud case
rather than the only one.
**With `</dev/null` the suite RUNS TO THE END** -- `p` reads EOF and
exits, `comsub2` fails its diff (correctly -- it wanted
`p: command not found`), and the loop reaches `run-vredir` and
beyond. Read that as "the rest of the suite" rather than a clean
number: it changes every test's stdin, not just this one's.

**AND THAT FIRST COMPLETE RUN MEASURED NOTHING -- 14795 lines, 86
test files, and `../bash: not found` in 75 of them.** `run-all:49`
is `: ${THIS_SH:=../bash}`, upstream's default, because bash is
normally built in its own source directory and the Makefile sets
`THIS_SH = $(BUILD_DIR)/$(Program)`. **APExp installs bash to
`/bin/bash` and never builds it at `../bash`**, so almost every file
invoked a program that does not exist. *The log is indistinguishable
at a glance from a real one*: right shape, right file names, a
plausible amount of diff -- `run-array` 855 lines, `run-new-exp` 813
-- and those are whole `.right` files showing as ABSENT OUTPUT, not
failures. **Zero files passed.** Same family as the stale suite log
and the `tclBinary` staleness: *anything measured from outside the
source in front of you should say where it came from.*
**THREE conditions, each failing silently on its own**: `THIS_SH`
naming a bash that exists; `recho`, `zecho`, `printenv` and `xcase`
built in `tests/` (the Makefile's `TESTS_SUPPORT`, built from
`../support/*.c` -- **nothing in APExp's build makes them**, which is
what the earlier `recho: command not found` was); and stdin on
`/dev/null` for `/bin/p`.
**`rc/bin/bash-runtests` is the harness**, and it exists because
three preconditions that fail silently are three ways to spend a
round on a worthless log. It builds the four helpers, sets `THIS_SH`,
redirects stdin, prints `bash-runtests: COMPLETE`, and **prints the
`../bash` count FIRST and refuses the result if it is not 0**. rc,
like the five ladders, because a harness written in the shell under
test cannot report that shell dying.
**Its own summary had the bug it is meant to catch, twice.** The
"passed" list printed every section unconditionally; and `/^run-/`
also matches an ERROR line -- `run-rhs-exp: 1: ../bash: not found` --
which reads as a header with nothing after it, *i.e. as a PASS*, and
was the one file the first summary reported as passing. Anchored at
both ends (`/^run-[-A-Za-z0-9_.]+$/`) it reports 86 sections and none
passing, which is the true answer. *Eighth time in this campaign the
instrument was the visible fault.*
**Read which SIDE of a diff a line is on before reading what it
says.** `run-vredir`'s screenful of `cannot duplicate fd: Invalid
argument` and `$fd: Bad file descriptor` looked exactly like a libap
`fcntl` bug, and `fcntl.c`'s `F_DUPFD` does carry an `EGREG` arm for
buffered descriptors -- but `run-vredir` is `diff $BASH_TSTOUT
vredir.right`, so `<` is ours and `>` is expected, every line on
screen was `>`, and those were `vredir.right` lines 95-123 verbatim.
`vredir6.sub` sets `ulimit -n 6` and *wants* the failure. Nothing of
ours was in frame.
**`set -m` is a red herring and was excluded by reading**: the two
`set: -m: invalid option` lines are `config.h:33`'s
`/* #undef JOB_CONTROL */` showing through, an expected diff.
**`function_substitute` does not fork** (`subst.c:6925` dup2s
stdout onto an anonymous file) and `anonopen` falls through to
`sh_mktmpfd`, a real unlinked temp file rather than a pipe -- so
there was never a funsub child or a pipe deadlock to look for.

**AND THE FIRST VALID RUN HUNG FOR 1h36m -- WHICH FOUND THE REAL
STATE OF THIS PORT: bash is built with most of its own features
COMPILED OUT.** The harness worked (`built recho zecho printenv
xcase`, `THIS_SH=/bin/bash`), and `tail` on the log was one line
repeating: `./set-e.tests: line 66: x: command not found`. Line 66 is
`until (( x == 4 )); do`. **Without `DPAREN_ARITHMETIC` `((` is not
an arithmetic command**, so `(( x == 4 ))` parses as two nested
SUBSHELLS running the command `x`, which is never found, so the
`until` condition never succeeds. *An infinite loop, not a freeze* --
and `run-all` has no timeout, so one looping test stops the suite.
**It is `READLINE` eleven times over.** `sys/src/external/bash/config.h`
had `#undef` on `ALIAS`, `PUSHD_AND_POPD`, `BRACE_EXPANSION`,
`DISABLED_BUILTINS`, `PROMPT_STRING_DECODE`, `SELECT_COMMAND`,
`COMMAND_TIMING`, `ARRAY_VARS`, `DPAREN_ARITHMETIC`, `EXTENDED_GLOB`,
`COND_COMMAND`, `ARITH_FOR_COMMAND`, `PROGRAMMABLE_COMPLETION` and
both `CASEMOD_*`. Upstream ships them all off and `configure` turns
them on; APExp hand-maintains the file as it does perl's.
**Nothing was missing from the build**: `alias.c`, `array.c`,
`arrayfunc.c`, `assoc.c`, `braces.c`, `pcomplete.c` and `pcomplib.c`
are all in OFILES, and `bi-alias`, `bi-pushd`, `bi-declare`,
`bi-test`, `bi-let`, `bi-shopt`, `bi-complete` all in OBJBUILTINS --
compiled, linked, switched off by commented-out lines. *A capability
present and not declared*, for the third time (READLINE, zipfs's two
`file stat` keys, this).
**The suite had been saying so and I read it as boilerplate.** The log
carries `warning: all of these tests will fail if arrays have not
been compiled into the shell`, `...if the conditional command has not
been compiled`, `...if extended pattern matching has not been`. Every
one was accurate. *A warning printed unconditionally is still a
warning about something.*
**`COND_REGEXP` was defined while `COND_COMMAND` was not**, and
`COND_REGEXP` does nothing except add `=~` to `[[ ]]`. A switch whose
only purpose is to extend a feature that is off is a tell.
**Left OFF deliberately, and the reason is a CLAIM nothing checked**:
`PROCESS_SUBSTITUTION` needs `/dev/fd` or named pipes, and
`config.h:597` already says `#define HAVE_DEV_FD 1` -- while Plan 9
binds the fd device at **`/fd`**. That is the OPPOSITE shape to the
fourteen above: a capability *declared* but possibly absent. `ls
/dev/fd` settles it, and declaring a second feature on top of an
unverified one would make any failure unattributable.
**gcc-swept before shipping, because a rebuild plus a suite run costs
hours.** `builtins/builtext.h` is generated by the build, so the check
needed `mkbuiltins` built on the host first and the 43 `.def` files
expanded; then `-fsyntax-only` over the main sources and all 43
builtins came back **clean**. **And the control fires**: preprocessing
y.tab.c and subst.c against the old config.h and the new gives
**+1579 and +1824 lines**, so the sweep really did examine newly
reachable code rather than passing vacuously. (`variables.c`'s one
complaint, `CONF_HOSTTYPE`, is a `-D` the mkfile passes -- a harness
artefact, confirmed by supplying it.)
**NOT YET MEASURED ON THE VM.** Predict: `set-e` stops looping, and
the per-file failure list shrinks a great deal rather than a little,
since `array`, `assoc`, `cond`, `extglob`, `braces`, `dollars`,
`new-exp` and `arith-for` are gated wholesale. Refuted if the suite
fails to BUILD, or if the list barely moves -- which would mean the
features are reaching the shell but something underneath them is
wrong, and that is a different investigation.

**AND THE REBUILD WOULD NOT START: `getcwd(NULL, n)` KILLED THE
PROCESS, AND IT IS LIBAP'S, NOT THE CONFIG CHANGE.**

```
bash 7263782: suicide: invalid address 0x0/4096 in sys call
_FD2PATH(a0=0x5)             syscall/_FD2PATH.s:6
getcwd(buf=0x0, len=0x1000)  ap/unistd/getcwd.c:21
get_working_directory(...)   bash/builtins/common.c:603
set_pwd() / initialize_shell_variables() / shell_initialize()
```

**`buf=0x0` is the whole bug.** libap's getcwd passed its argument
straight to `_FD2PATH` with no null check, so `getcwd(NULL, n)` -- the
glibc/musl/POSIX.1-2008 "allocate it for me" form, which a great deal
of GNU code uses -- handed the kernel address zero. `0x1000` is 4096,
`PATH_MAX`, which is what bash asks for at `builtins/common.c:603`.
**bash HAD ALREADY DETECTED THIS AND SHIPPED THE FIX, AND THE LINK
ORDER THREW IT AWAY.** `config.h` says `#define GETCWD_BROKEN 1`, so
`config-bot.h:66` does `#undef HAVE_GETCWD`, so `lib/sh/getcwd.c`
compiles a getcwd that DOES allocate, and `getcwd.$O` is in the
mkfile's `OBJSH`. But that object lands inside **`libsh.a`**, and
`sys/src/ape/cmd/bash/mkfile` links deliberately:
`#link libap first to already occupy symbols supported by the system
libap` / `LIB= .../libap.a $BASHLIBS ...`. So `getcwd` resolved out of
libap and bash's own copy was never pulled from the archive.
*A program's workaround for a library bug is only as good as the link
order* -- **the gnulib `strerror` finding pointing the other way**:
there libap's correct version lost to gnulib's broken one, here bash's
correct version lost to libap's broken one. *A symbol libap provides
decides which implementation runs, whichever direction the quality
runs in.*
**And libap held the right idiom NEXT DOOR**: `misc/get_current_dir.c`
implements `get_current_dir_name()` with the comment *"like
getcwd(NULL, 0) on Linux -- allocates"*, by malloc'ing PATH_MAX and
calling getcwd into it. Same shape as `mktemp` ignoring `__randname`
in its own directory -- *the library contained a working version of
the thing it could not do*, for the second time.
**FIXED IN LIBAP rather than by reordering the link**, which is the
right half of the choice: every program calling `getcwd(NULL, ...)` is
fixed, and the mkfile's "libap first" policy stays intact.
`getcwd(NULL,0)` takes PATH_MAX because **Plan 9's `fd2path` truncates
SILENTLY** -- it returns -1 only for a bad descriptor -- so a
grow-until-it-fits loop has nothing to test. `_getcwdmark()` is the
version marker. `getcwd-test.c`'s **section 2 is bash's exact call and
used to KILL rather than fail**, so reaching section 3 at all is the
result; **section 4 is the control** (`getcwd(buf,0)` must be EINVAL),
since an implementation that allocated unconditionally would pass
everything else. 0 failures on glibc.
**CONFIRMED ON THE VM**: `_getcwdmark = 1`, all four sections PASS,
0 failures -- and section 2 is bash's exact `getcwd(NULL, PATH_MAX)`,
which used to kill the process rather than fail, so reaching section 3
was itself the result.
**Why it had not bitten before is NOT settled and is not worth a
round**: `set_pwd` reaches `get_working_directory` only when `PWD` is
absent from the environment or does not match `.`, so the path was
always one import away. Recorded as unexplained rather than guessed.
**`/dev/fd` DOES NOT EXIST -- measured, and `HAVE_DEV_FD 1` was a
lie.** `ls /dev/fd` says `file does not exist`; `ls /fd` lists
`/fd/0 /fd/0ctl /fd/1 ...`. **Not re-pointed at `/fd`**: a Plan 9
`/fd` entry is the descriptor of *the process that opens it*, so
handing the name to a CHILD -- the whole point of `<(...)` -- names
the child's own descriptor. *Do not invent semantics to make a feature
compile.*
**`NAMED_PIPES_MISSING` was also wrong**, i.e. bash was told FIFOs
work: `unistd/mkfifo.c` is a stub returning -1. Defined now. **And the
stub set `errno = 0` while failing** -- the most common bug shape in
this tree, here in its purest form: a failure that refuses to say why,
so `perror` prints whatever the last call left behind. ENOSYS now, as
`symlink()` gives.
*Two false claims and fourteen false denials in one config.h: a
hand-maintained capability file is wrong in BOTH directions, and the
two kinds fail differently -- a denial costs a feature silently, a
claim costs a crash.*

**AND THE libap REBUILD WOULD NOT COMPILE, which found a THIRD
constant with two definitions.**

```
cpp: limits_generic.h:137 /amd64/include/ape/limits.h:30 getcwd.c:6
     Macro redefinition of NGROUPS_MAX
cpp: limits_generic.h:143 ... Macro redefinition of PIPE_BUF
cc: 6c: cpp errors
```

`limits_generic.h` said `NGROUPS_MAX 10` and `PIPE_BUF
_POSIX_PIPE_BUF`; `sys/limits.h` says **32** and **8192**. **Neither
value in `limits_generic.h` was ever in effect**: that file ends with
`#include <sys/limits.h>`, `sys/limits.h` `#undef`s before every
`#define`, and it has **no include guard**, so it is re-read and wins
every time. The two dead values existed only to break any translation
unit that reached `<sys/limits.h>` FIRST and `<limits.h>` second --
i.e. one `#include <unistd.h>` before `#include <limits.h>`.
**The other shared names did not fail because their values AGREE**
(`NAME_MAX` 255, `PATH_MAX` 4096, `MAXPATHLEN`), and an identical
redefinition is legal. *That is why the trap was invisible: the same
file is both correct and fatal depending on include order, and only
the two disagreeing macros say so.*
**This is `PATH_MAX` for the third time** -- two definitions in two
files that include each other -- and the rule written after the first
one is the rule that found it: **when a constant is wrong, grep for
EVERY definition of it.** Applied properly this round rather than
trusting the two cpp happened to name, since **cpp stops at the first
errors**: the full overlap of the two files is now exactly three
macros and all three agree.
*No effective value changes*, so stale objects stay consistent and
this needs no `distclean` of its own. `getcwd.c` takes
`<sys/limits.h>` as `at_functions.c` beside it already does -- *the
include with a working neighbour under the same flags beats the one
that only ought to work*.

**AND THE SUITE NOW MEASURES REAL THINGS -- then STOPS at
`run-jobs`.** The diffs are genuine at last: `< 1.0000` against
`> 1,0000` (a decimal comma, so `LC_NUMERIC`), and `Passed all 1318
Unicode tests` against `1770`. That shape is only possible with
`THIS_SH` resolving and the fourteen features compiled in, so the
config change reached the shell.
**`run-jobs` is the stop**, and the log stood still for four minutes
while the longest thing in `jobs.tests` is `sleep 30`. The file is
`sleep N &` and `wait` throughout -- `wait %1`, `kill -n9 $pid; wait
$pid`, `kill -sHUP $pid2; wait $pid2`, and two bare `wait`s with
several children outstanding. **This tree already records a
never-measured bug exactly there**: `wait4`'s `WNOHANG` path falls
through to the BLOCKING `_WAIT()` when `_dirstat` returns nil, and
again when the pending message belongs to a different pid -- which is
what `wait -n` and a bare `wait` do. *A live suspect rather than a
guess, but `ps` decides it, not the reading.*
**AND THE KERNEL'S fd WARNINGS NOW CORRUPT TEST OUTPUT, which is new
and is NOT a new bug.** `< bash NNNN: warning: process exceeds 100
file descriptors` appears as a diff line in `run-invert`,
`run-invocation` and `run-iquote` -- files with nothing to do with
descriptors. The mechanism was settled two rounds ago and is
`move_to_high_fd` (`general.c:681`): with `maxfd < 20` it takes
`getdtablesize()`, capped by `HIGH_FD_MAX` **256**, and libap reports
`OPEN_MAX` 256, so bash `dup2`s its script to ~254 and Plan 9's fd
table grows past both thresholds. **Recorded, not fixed**:
`getdtablesize()` is telling the truth, and shrinking it to dodge a
kernel message is the "invent semantics" shape. *The warnings were
proven HARMLESS by the empty-script case; what is new is that they are
now LOUD -- a harmless message that lands in a captured stream stops
being harmless to the measurement.* Size it from the harness summary
before touching anything.

**`date` CRASHES, and `/proc/n/ppid` is what stopped me blaming it.**
The full `ps` -- ungrepped, after two rounds of grep hiding things --
showed **two `Broken date` processes** beside the stalled harness, and
a `Broken` process is ALIVE to the kernel (stopped at a fault), so
`await` on one can never return. That fit the `Await` perfectly and
was wrong: `ppid` says 7273473 and 7287195, **both gone**, so the two
dates are ORPHANS and nothing waits on them. The actual child of
`bash-runtests` is an **`awk` in `Pwrite`** -- my own summary, so that
stall is mine. *Three mechanisms offered, the right one not among
them: a list of alternatives is only exhaustive over what you thought
of.* **`ppid` costs nothing and would have saved the whole detour.**
**The crash itself is real and new**, with a complete stack:

```
save_abbr(...)+0x3d        gnulib/time_rz.c:127
mktime_z(tm=.., tz=0x43f480) gnulib/time_rz.c:310
__strftime_internal(...)   gnulib/strftime.c:2092   <- the %s arm
fprintftime(...)           gnulib/strftime.c:1198
show_date(...)             coreutils/src/show-date.c:32
show_date_helper(...)      coreutils/src/date.c:397
main                       coreutils/src/date.c:709
```

`time_rz.c:127` is `char const *zone = tm->tm_zone;` and the only
dereference below it is `if (*zone)`, guarded by `if (!zone || zone
points INSIDE tm) return true;`. **So the fault is `*zone` with a
non-null `tm_zone` that is neither NULL nor internal** -- a stale or
invalid pointer.
**Sitting directly under it: libap's `mktime` never writes
`tm_zone`, `tm_gmtoff` or `tm_isdst` back into `*t`.** It is 132
lines and only normalises the date fields. glibc and the BSDs set all
three, and `mktime_z` is written around that -- it does
`struct tm tm_1 = *tm; mktime(&tm_1); save_abbr(tz, &tm_1);`.
*Recorded as a conformance gap, NOT as the diagnosis*: `localtime_rz`
should already have repointed `tm_zone` into the `tz` object, so the
chain is not closed.
**It prints correct output and THEN dies** -- both manual runs showed
the right time -- which points at teardown or at a later `%`
conversion rather than at the formatting that produced the visible
line. *A program that answers correctly and then faults is reporting
something after the answer.*
**Next, and cheap, because a Broken process keeps everything**:
`acid <pid>` then `lstk()` prints the LOCALS, so `zone`'s actual
value is one command away -- NULL, inside-tm, or garbage are three
different bugs. And `date` twice in a row with `ps | grep date`
between says whether it leaves a corpse every time.

**THE FIRST VALID COMPLETE RUN OF BASH'S SUITE: `lines mentioning
../bash (MUST be 0): 0`, `COMPLETE` marker, ~85 files with a
non-empty diff and NONE passing.** The harness's own validity line is
what makes that readable at all.
**But about 35 of those files show exactly `3`, and 3 is one diff
position header plus the two kernel fd warnings.** They agree with
their `.right` in every respect except a message from the KERNEL --
`pprint` sends it to the process's own fd 2, and every `run-<name>`
captures stderr with `2>&1`, so it lands inside the comparison. *So
the single largest entry in the failure list is not bash and not
libap.*
**The harness now buckets three ways** -- REAL diff / warnings-only /
passed -- and that is a MEASUREMENT, not a fix: nothing is suppressed
or rewritten, the noise is counted apart so the remaining list is the
one worth reading. **Position lines (`2,3d1`) are skipped** as
structure rather than content, and a real file's number is now its
differing lines with the warnings subtracted. *Lumping ~35 noise
entries in with the real ones makes every later per-file comparison
unreadable, and comparing per file is this tree's rule.*
**`run-jobs` WAS NEVER A STOP, and I spent a round on it.** It shows
`231` in the list, so it ran to completion; the log looked static
because `jobs.tests` legitimately sleeps for minutes. *I had even
computed its longest sleep and still read "the log stopped changing
for four minutes" as a hang.* **A log that is not growing is not a
stopped run when the test it is inside is a sleep** -- the `ps` STATE
would have said so, and the one I took was of the wrong process.
**The real stall was my own `awk`, at the very end**, blocked in
`Pwrite` with `bash-runtests` waiting on it; killing it let the
summary print. *Ninth instrument fault.* **Why an awk writing to the
terminal blocked is UNEXPLAINED** -- the committed harness has no pipe
-- and the evidence is gone, because the `/proc/<pid>/fd` listing was
not taken before the kill. *Take the cheap reading BEFORE the
remedy; a kill destroys the only copy.*
**And `lstk()` named `date`'s bad pointer exactly: `zone =
0x834383635`.** Bytes `34 38 36 35` are ASCII **`4865`** -- a `char *`
holding digit TEXT, which is the `ifs_value` shape a second time, and
the fault is in strftime's **`%s` arm**, the one conversion that
formats a number. *Two independent bugs in this tree have now been a
pointer containing characters.*

**THE SUITE RAN TO THE END AGAIN -- 21 minutes, not stuck -- AND THE
LOG HELD A LIBAP BUG NOBODY WAS LOOKING FOR: `printf` DID NOT KNOW
`%td`, `%jd` OR `%hhd`.** `stdio/vfprintf.c`'s `tflag` table had `h`,
`l`, `L` and `z` and not `t` (ptrdiff_t), `j` (intmax_t) or a second-`h`
rule for `hh`. **An unrecognised conversion prints the letter and
CONSUMES NO ARGUMENT**, so `printf("%td", n)` printed the literal text
`td` and left `n` in the va_list -- *every conversion after it in that
format string took the wrong argument*. A `%s` after a `%td` reads a
string from an integer. *A conversion that prints garbage is a bug in
one value; one that eats no argument is a bug in every value after it.*
**So EVERY DIFF POSITION LINE ON THIS SYSTEM HAS ALWAYS BEEN GARBAGE**:
diffutils has `#define pI "t"` and prints every line number through
`fprintf(outfile, "%"pI"d%c%"pI"d", trans_a, sepchar, trans_b)`, so
`1,2d0` came out `td\x01tddtd` -- `td` per number, and the `%c` taking
`trans_a` instead of the comma. **The corruption decodes, which is the
only reason it was readable**: `td(tdctd,td` is `(`=40 and `,`=44, and
40 and 44 are that hunk's own first lines; `tdM-9...M-;` is 185/187,
likewise. *A wrong value that decodes back to the right one names the
mechanism, not just the fault.*
**~370 literal sites** across coreutils, gnulib, diffutils, patch,
bison, tar, flex, pcre2, grep and sed. **Two things hid it**: `z` --
1439 of the ~1800 uses -- was the one modifier someone had already
added; and **the `PRI*` macros dodge it**, since APE's `<inttypes.h>`
spells `PRIdMAX` as `"lld"` rather than `"jd"`.
**And `vfscanf.c` HAS HANDLED ALL THREE SINCE IT WAS WRITTEN** --
`case 'j'`, `case 'z'`, `case 't'`, right pointer types. The library
knew these on the INPUT side and not the output side: third time it
contained a working version of the thing it could not do, after
`mktemp` ignoring `__randname` and `getcwd` beside
`get_current_dir_name`.
**Measured old beside new, which is cheaper than a rebuild**: the real
tables and the real cracking loop lifted verbatim into a host program
give **5 failures before and 0 after**, `%zu`/`%hd`/`%lld`/`%ld`/`%Lf`
identical both ways -- and the old run reports `conv='t'`, the
conversion character *being* the modifier letter, which is exactly the
`td` on screen. `printfmod-test.c` is the regression test, 0 failures
on glibc; **its section 4 is the one that matters**, putting a second
conversion after the first and asking what THAT printed, because an
implementation with the number right and the argument wrong passes
everything else. `_printfmark()` is the marker. `vfwprintf` needs no
change -- it narrows and calls `vfprintf`.
**CONFIRMED ON THE VM**: `_printfmark = 1`, all six sections PASS,
**0 failures** -- and the marker is what makes that readable, since the
test could not have LINKED against the libap that had the bug. The
idiom has now paid five times (`_sock_listenmark`, `_execmark`,
`_ttymark`, `_getcwdmark`, this).
**It changes NO test result** -- diff's exit status and its `<`/`>`
lines were always right -- and it is **not** `date`'s crash, since
`strftime.c`/`time_rz.c` use none of these modifiers. *The suite's
value here was as a corpus, not as a scoreboard.*

**AND THE HARNESS WAS DEFEATED BY THE BUG IN THE LOG IT WAS READING.**
`bash-runtests` identified a diff position line by its leading DIGIT
(`/^[0-9]/ { next }`) -- true of `2,3d1`, and false of `td^Atddtd`. So
~37 files whose only real difference was the two kernel fd warnings
were each counted as having one differing line, and the summary
reported **9 warnings-only against 76 real where the truth is 46
against 40**. *Tenth instrument fault, and the sharpest: it assumed
diff can print a number.* A section's content is now exactly its `<`
and `>` lines -- which assumes only that diff marks which side a line
came from, the one thing the format is for -- and that rule holds
whether or not printf is fixed.
**The prediction written down last round was RIGHT and the instrument
said otherwise**: ~35 warnings-only and ~50 real, against 46 and 40.
*When a measurement contradicts a prediction, ask what sits between
them* -- the rule was already in this file from `io-14.1`, and the
thing between them was the same log the measurement came from.
**So the real failure list is 40 files**, largest first: `run-histexpand`
287, `run-builtins` 225, `run-jobs` 176, `run-glob-bracket` 103,
`run-printf` 86, `run-redir` 78, `run-func` 70, `run-glob-test` 63,
`run-dirstack` 53, `run-procsub` 35. **AND THAT PREDICTION CAME IN: 46 OF 86 NOW PASS**, the same count on
two consecutive runs. 45 are the warnings-only set exactly as called,
plus `run-test`; `run-input-test` is clean as well. The real list is
**39**, with the same ten at the top and the same counts --
`run-histexpand` 287, `run-builtins` 225, `run-jobs` 176 -- so
*nothing in the real list moved*, which is what says the 46 were noise
rather than a shared cause.
**The fd warnings are CLOSED as an item** (see the top of this
section): they were the largest single entry in the failure list and
they went without one line of libap changing.

**AND THE TWO BIGGEST REAL FILES ARE THREE SWITCHES AND ONE STUB.**
`run-histexpand` 287 and `run-builtins` 225 are 512 of the remaining
~1500 differing lines, and reading them cost one round rather than
several because each partitions cleanly.
- **`run-histexpand` is `BANG_HISTORY`, ALL 287 lines of it.**
  `set: -H: invalid option` and `!!: command not found` throughout;
  the switch is `#undef` and gates **43 sites**, `set -H`
  (`flags.c:199`, `histexp_flag`) among them. **The file's own first
  line says so** -- *"warning: all of these tests will fail if history
  has not been compiled into the shell"* -- which is the third time a
  suite's unconditional warning turned out to be accurate.
  **It was LEFT OFF as a decision rather than an oversight** -- it
  changes what `!` MEANS in every interactive line, where `READLINE`
  and `HISTORY` only changed how a line is edited -- **and it is now
  ON, chosen rather than swept in.** Nothing was missing from the
  build, as with READLINE before it: `histexpand.$O` is already in
  `libreadline.a` (lib/readline's HISTOBJ), which `cmd/bash/mkfile`
  already links, so `history_expand` resolves with no mkfile change.
  `config-bot.h:104` makes it imply HISTORY, already defined.
  **MEASURED: 287 -> 35, and the 35 are ONE OTHER SWITCH.** Every
  remaining line is `syntax error near unexpected token '('` on
  `<(...)` in `histexp4.sub`, `histexp5.sub` and `histexp7.sub` --
  **process substitution**, off deliberately because `/dev/fd` does
  not exist. So `run-histexpand` is now accounted for end to end: 252
  BANG_HISTORY + 35 procsub, nothing unexplained. The prediction said
  "near 0" and a surviving remainder would mean something *under* `!`
  was wrong; it is a second known absence instead, which is the
  better of the two ways to be off.
  **And `run-history` 33 -> 0: it PASSES.** That file was never read
  and was not predicted.
  ***AND THE `HFILES` FIX IS CONFIRMED BY THE SAME RUN***: the user
  ran `mk install` with no `mk clean` in `cmd/bash`, and a `config.h`
  edit reached the binary. That was the stated refutation condition --
  "if `run-histexpand` does not move, suspect the rebuild" -- and it
  moved.
  **Per file, nothing else changed in substance.** 39 real -> 38,
  46 passing -> 47. `run-shopt` 24 -> 19, `run-nquote` 18 -> 16 and
  `run-complete` 20 -> 19 went with BANG_HISTORY; every other count is
  identical. **`run-trap` 14 -> 16 is the one that ROSE and it is not
  a regression**: both runs hold the same two things (JOB_CONTROL's
  `set -m`, and xtrace lines run together without newlines), and the
  count moved only because the `+[8] false` hunk regrouped -- two
  concatenated trace lines in one run, three in the next. *A count
  that rises because a diff hunk realigns is not a new failure;
  reading the section is what separates them.*
  **CONFIRMED two runs later: it went back to 14 with nothing
  touching it**, which is what an unstable hunk does and what a
  regression does not. *The reading was right and the cheap evidence
  for it arrived by itself.*
- **`run-builtins` 225 partitions 175 / 42 / 6 / 2**, and only the
  second is ours:
  **175 are `HELP_BUILTIN`** -- `help: command not found`,
  `builtin: help: not a shell builtin`, and pages of `help <name>`
  usage on the expected side. `bi-help.$O` is already in OBJBUILTINS
  and `help.def` in DEFFILES, and `help.def` opens `$DEPENDS_ON
  HELP_BUILTIN`, so mkbuiltins emitted no builtin. **A capability
  present and not declared, for the FIFTH time** (READLINE, zipfs's
  two `file stat` keys, the fourteen features, this). **Turned ON.**
  **42 are `umask` and they ARE ours** -- see below.
  **6 are `enable -f`** (dynamic loading; Plan 9 has no dlopen, the
  same wall as perl's XS) and **2 are process substitution**, off
  deliberately because `/dev/fd` does not exist.
- **gcc-swept before shipping, and the control was VACUOUS the first
  time.** `help.c` and `builtins.c` give **0 errors** in the class 6c
  treats as fatal (`-Werror=incompatible-pointer-types`,
  `implicit-function-declaration`, `int-conversion`) -- gcc's own
  `-Wparentheses` and `-Wdiscarded-qualifiers` complaints are
  upstream's style. But my first control compared `-DHELP_BUILTIN`
  against nothing *while `-DHAVE_CONFIG_H` was supplying the define
  from the header both ways*, and reported 5537 lines twice.
  Preprocessed against a `config.h` with the line reverted it is
  **625 -> 5537**. *A control that cannot differ is not a control* --
  the same trap as the check that cannot fail, met from a new angle.

**`umask()` DISCARDED ITS ARGUMENT AND ALWAYS ANSWERED 0 -- FIXED.**
The whole of `ap/stat/umask.c` was `mode_t umask(mode_t){ return 0; }`
under the comment *"No such concept in plan9, but supposed to be
always successful"*. The first half is true of the KERNEL and false of
this library; the second half is not what the call is for. **This is
the most common bug shape in this tree** -- a stub answering the wrong
thing rather than "nothing to do" -- and the rule it breaks is already
written down: *a platform having nothing to DISPLAY is no reason for a
value not to read back.*
**Storing it is not "inventing semantics", for a locatable reason**:
libap is the code that chooses the permission it hands `_CREATE`, at
exactly **two** user-facing sites (`fcntl/open.c`'s O_CREAT arm and
`unistd/mkdir.c`). The other `_CREATE` callers are internal
(`/env/_fdinfo`, `/env/_sighdlr`, `tmpfile`, `access`'s probe) or copy
an existing mode (`rename`), and POSIX puts no umask on any of them.
**And it composes with the file server rather than fighting it**: Plan
9 already hands out `perm & (dirperm | ~0666)`, so the result is the
intersection -- a umask may only ever REMOVE bits, which is exactly
its contract.
**Two limits, both deliberate and both recorded**: the initial mask is
**0, not 022**, so by default nothing differs and only a program that
calls `umask()` sees any change -- *a conformance fix should not also
be a default change*; and it does **not survive `exec`**, since the
static lives in the process image and carrying it over means another
`/env/` variable beside `_fdinfo` and `_sighdlr`. `umask-test.c`
**section 4 is a PROBE that measures that gap** rather than asserting
it, so the next reader gets a number instead of this paragraph.
**Section 3 is the one that matters**: an implementation that stored
the mask and never applied it -- *a value that reads back and does
nothing* -- passes sections 1 and 2 and fails only there. It asserts
only that the masked bits are ABSENT, never that the others are
present, because the latter would be a test of the file server.
**Measured old beside new**: 0 failures on glibc, and the old stub
replicated beside it gives **5**, with section 3 printing `0755` under
mask 027. `_umaskmark()` is the version marker.

**MEASURED, AND THE PREDICTION WAS REFUTED TWICE -- usefully both
times.** Predicted `run-builtins` 225 -> ~8.
**Run 1 gave 177**, and the 48 that went were EXACTLY the umask block:
`umask`-shaped lines **42 -> 0**, so *that fix is CONFIRMED* and
nothing else in the suite moved. But `help: command not found` was
still there, with the commit provably in `main`.
**Because `mk` DOES NOT REBUILD BASH WHEN `config.h` CHANGES.** No
bash source file changed, and the mkfile names `config.h` nowhere --
so not one bash object was recompiled, while libap rebuilt only
because `umask.c`, `open.c` and `mkdir.c` are *sources* that changed.
**This is `tclBinary.c` for the THIRD time**, and the rule was already
in this file: *a header not in `HFILES` is a header `mk` does not
rebuild for.*
**Run 2, after `mk clean` in `cmd/bash`: 177 -> 85**, and
`help: command not found` is **0**. `run-complete` 23 -> 20 and
`run-redir` 78 -> 77 moved with it; nothing else did.
**The remaining 85 are ONE capability, not 85 faults.** `help`'s
two-column table lists `bg disown fg jobs suspend` on the expected
side and not on ours -- **`JOB_CONTROL`** -- and *one missing entry
shifts every row after it*, so five absences diff most of the table.
**It is out of reach rather than off**: libap has **no `tcsetpgrp` and
no `tcgetpgrp` at all** -- absent, not stubbed -- so job control could
not link, and Plan 9 has no controlling-terminal foreground group to
give them meaning (`setpgid` answers ESRCH, `setsid` returns
`getpgrp()`). **`JOB_CONTROL_MISSING` is now DEFINED**: it only undefs
a switch already undef, so the binary is identical, but the file says
which kind of "off" it is -- the `NAMED_PIPES_MISSING` precedent.
*A prediction refuted by a build-system fault and then by a platform
limit taught more than a correct number would have.*

**AND THE `HFILES` GAP IS TREE-WIDE: THIRTEEN PACKAGES, NOT ONE.**
Starting from every `sys/src/external/*/config.h` and asking who
builds it -- rather than from the mkfiles, which name their sources
through `$BASHSRC`-style variables a grep cannot follow -- gives
bash, gawk, ggrep, gsed, gtar, libdwarf, libpng, libxml2, patch, perl,
readline, unace and xz, across **18 mkfiles**. Every one could be
edited with nothing rebuilt. `HFILES` added to 17 of them.
**Two traps on the way, both caught by measurement rather than
reading**:
- **`tar` was a FALSE POSITIVE of my own sweep.** Its `HFILES` is
  multi-line and lists `config.h` on a continuation line, which a grep
  anchored at `^HFILES` cannot see. It was already correct and is left
  alone.
- **FOUR packages have a LOCAL `config.h` that SHADOWS the external
  one** -- grep, sed, tar, patch, each with `-I.` ahead of the package
  include. tar's are 4512 and 113703 bytes, so they are not the same
  file at all. I had already written the external path for two of them
  before checking; reverted. *Name the file that is compiled, not the
  file with the right name* -- the `PATH_MAX` lesson in a new place.
  (`patch` nearly slipped through a second time: its `-I.` is on the
  CFLAGS **continuation** line, so a `^CFLAGS.*-I\.` grep missed it.)
Every path was verified to exist before writing, because an `HFILES`
naming a missing file makes `mk` fail outright.

**AND THE gcc SWEEP FOR `BANG_HISTORY` WAS WRONG TWICE BEFORE IT WAS
RIGHT, in two NEW ways.** The sweep itself came back **0 errors** in
the class 6c treats as fatal, across all eight `.c` files and the
generated builtins -- but getting an answer that meant anything took
three attempts:
- **`-I` CANNOT override `config.h` for bash's own sources.**
  `#include "config.h"` searches the INCLUDING FILE'S directory first,
  and bash's sources sit beside `config.h`, so pointing `-I` at a
  reverted copy changed nothing and the control reported "same" six
  times. *It had worked for `HELP_BUILTIN` only because `help.c` is
  generated into a different directory* -- the same technique, right
  once by accident. Swapping the real file in place is what works:
  `bashhist.c` **+115** lines, `flags.c` +50, `shell.c` +6, the rest
  +3.
- **A missing file counted as an error.** `reserved.c` showed 1 error
  OFF *and* ON, which is what flagged it as pre-existing rather than
  mine -- and it is neither: `reserved.def` has no `$PRODUCES`, so
  that `.c` is never generated and my sweep was compiling a file that
  does not exist. *Counting OFF beside ON is what caught it; a
  one-sided sweep would have reported a real error.*
- The other two complaints were the recorded harness artefacts
  (`builtins/builtext.h` needs an `-I` with a `builtins/`
  subdirectory, and `CONF_MACHTYPE` is a `-D` the mkfile passes).
  Supplied rather than dismissed, which is what turned 6 into 0.

**The watchdog now SAYS WHEN IT IS ARMED, and a wasted round is
why.** A run went out as `APEX__MALLOCMAX=8` -- two underscores, no
`P` -- so the watchdog never armed, bash ran to full exhaustion and
was killed exactly as it had been for weeks, and `acid` found
nothing. **That output is indistinguishable from a watchdog that
armed and never reached its limit.** The instrument's silence when
unset is correct and must stay, so the repair is one line when it
IS set: `libap: heap watchdog ARMED at N MB`. No line now means not
armed. *Same family as everything else here -- an instrument has to
say whether it is running, or a null result has two explanations.*

**THE REMAINING 38 WERE READ IN ONE COMMAND, AND SIX OF THE TEN
BIGGEST ARE NOT BUGS AT ALL.** Taking the head of each section
instead of one file at a time:
- **`run-jobs` 176 -- JOB_CONTROL.** `set: -m: invalid option`,
  `jobs/fg: command not found`. Out of reach: libap has no
  `tcsetpgrp`/`tcgetpgrp` and Plan 9 has no foreground process group.
  The file's own warning says so in its first line.
- **`run-builtins` 85 -- JOB_CONTROL**, already settled (help's table
  shifting around five absent entries).
- **`run-glob-bracket` 103 -- ONE LINE, and not ours**: `glob-bracket:
  shared objects not supported, cannot continue`. The whole 103 is
  expected output absent (`0a1,103`) because the test needs a
  LOADABLE BUILTIN. Plan 9 has no dlopen; the same wall as perl's XS
  and `enable -f`.
- **`run-dirstack` 53 -- `/etc` does not exist on 9front.** `pushd
  /etc` fails and every later line of a stack test shifts. Not ours,
  and the same shape as `/bin/p`: *a test naming a unix directory.*
- **`run-glob-test` 63 -- `locale: command not found`** plus absent
  `zh_TW.big5` and `en_US.UTF-8`. Part missing program, part missing
  locale data.
  **AND IT IS THE ONE SECTION WHOSE CONTENT CHANGES BETWEEN
  IDENTICAL RUNS** -- the count stays 63 and the words move. Not
  ours, and the cause is one line of arithmetic: `glob11.sub` tests
  **`GLOBSORT`**, creating six files `sleep 0.1` apart under the
  comment *"try to impose some kind of testable ordering"*, then
  sorting them by `+atime`/`-atime` and `+mtime`/`-mtime`.
  **Plan 9 file times are WHOLE SECONDS** -- 9P's `Dir.mtime`, and
  `dirtostat.c` sets every `tv_nsec` to 0 -- so six files written
  within half a second share one timestamp, bash's secondary sort on
  name takes over, and whether the six straddle a second boundary is
  luck. That is exactly the shape observed: one run name-sorted all
  six, the next put `mksyntax` alone in front and name-sorted the
  rest. *The test cannot pass here and cannot be stable here*, and
  the `size` pair beside it is unaffected because sizes are real.
  **The `.right` file settles the rest**: it names `mksyntax.dSYM`,
  a macOS debug bundle, so the expected output was generated on a Mac
  against that machine's directory.
- **`run-func` 70 and `run-procsub` 35 -- process substitution**,
  joining `run-histexpand`'s 35. **Four files and ~140 lines are one
  switch**, and it stays off until `/dev/fd` means something here.
- **`run-redir` 77 -- mixed, and one part IS ours**: `/etc/passwd`
  missing (not ours), and **`Bad file number` where POSIX says `Bad
  file descriptor`** -- `string/strerror.c`. It shows up in
  `run-vredir` too. **It was NOT one string: 40 of the 76 were
  wrong** -- see the strerror entry below.
- **`run-printf` 86 -- FOUR causes, three of them libap's**; see
  below. That makes it the largest genuinely ours.
*So of the ~1500 differing lines, the share that is a bug in this
tree is far smaller than the list's shape suggests -- and reading
eight sections' HEADS cost one command where reading one file at a
time had been costing a round each.*

**`printf` AGAIN, AND `%F` IS THE `%td` BUG IN A SECOND PLACE.**
`run-printf` partitions 6 / 8 / 9 / 1 / 28 (hexdump, a program this
tree has not got):
- **`%F` was missing from `vfprintf`'s dispatch table**, so it fell
  through to the arm that prints the conversion character and
  **consumes no argument** -- the value lost, and every conversion
  after it in the same format string taking the wrong one.
  `printf.tests` lines 320 and 325 are literally `printf "%F\n" 0`
  and `printf "%F\n" 4`, and this tree answered `F`. *The `%td` round
  fixed the three LENGTH MODIFIERS and did not sweep the CONVERSION
  table beside them; `A` and `a` are still absent and nothing has
  measured them.*
- **`%g` with precision 0.** C99: "if the precision is zero, it is
  taken as 1". `%+010.0g` of 123 printed `+000000123` where
  `+00001e+02` is wanted.
- **The `0` flag with a precision.** C99: for `d i o u x X`, a
  specified precision makes `0` ignored -- and **a precision of ZERO
  is specified.** The test read `precision <= 0`, conflating `%.0d`
  with no precision at all (-1), so `%+010.0d` gave `+000000123` for
  `      +123`. One character.
- **`printf "%08X" 2604292517` -> `FFFFFFFF9B3A59A5`: SOLVED by the
  probe, and libap's printf was INNOCENT.** Section 9 on the VM:

  ```
    %08X  of unsigned int  -> 9B3A59A5     <- all three widths right
    %08lX of unsigned long -> 9B3A59A5
    %08llX of ull          -> 9B3A59A5
    strtoumax("2604292517") -> FFFFFFFF9B3A59A5
    assigned to unsigned long -> 9B3A59A5
    bash takes the PRIdMAX/ll branch (p != pp)
  ```

  **`string/strtoumax.c` included `<inttypes.h>` and `<stdint.h>` and
  NOT `<stdlib.h>`**, and neither reaches a declaration of
  `strtoull` -- so the call had no prototype, returned implicit
  `int`, and every value with bit 31 set came back sign-extended.
  `printf.def`'s x/X arm does `p = pp = getuintmax()` and compares
  them, so `p != pp` sent bash down the `%08llX` branch with the
  sign-extended value. *Chain closed end to end, one line of output.*
  **FOUR mechanisms had been refuted by reading first** -- `strtoull`
  saturating (2604292517 is nowhere near a threshold), `mklong`
  building the format wrongly (bash NUL-terminates after the
  conversion character, so it really is `%08lX`), amd64's `va_arg`
  (`stdarg_arch.h` gives every argument an 8-byte slot and reads a
  4-byte type from its low half, which is right), and a missing
  prototype *in bash* (`printf.def` does include `<inttypes.h>`).
  **The fifth was one level down and reading never reached it.**
  **And the probe REPRODUCED the bug by accident before it measured
  it**: its own first version omitted `<inttypes.h>`, so `strtoumax`
  had no prototype either and it printed `FFFFFFFF9B3A59A5` *on
  glibc* -- the bash output character for character, from the same
  cause one level up. *The accident was the diagnosis and I nearly
  filed it as an instrument fault.*
- **Two conformance gaps noticed and NOT fixed**, because nothing
  measured them: `_dtoa` hands back `"Infinity"` and `"NaN"`, so
  `printf("%f", INFINITY)` prints `Infinity` where C wants `inf` --
  which is also why `%F` does not upper-case them here, since that
  would turn one wrong spelling into another. And `%a`/`%A` do not
  exist.

**AND `strftime` WAS MISSING FIFTEEN CONVERSIONS, WITH THE SAME
SILENT FAILURE MODE.** Its `default:` arm writes the conversion
character out as a literal, so `%F` printed `F`, `%r` printed `r`,
`%T` printed `T` and `%e` printed `e`. Measured in bash's
`printf3.sub`, whose `%(...)T` feeds its argument straight to
strftime: `current time: %(%F %r)T` came out `current time: F r`.
Absent: **C D e F G g h n r R s t T u V**, and `%%` worked only by
falling through `default:`. All are POSIX.1 and C99 7.23.3.5.
**And `%c` and `%x` were WRONG rather than missing**: POSIX fixes
both in the C locale (`%a %b %e %H:%M:%S %Y` and `%m/%d/%y`) and this
file had `%a %b %d ...` and `%a %b %d, %Y`. The log is what found the
second -- `%(%x %X)T` wanted `05/30/10 15:09:15` and gave
`Sun May 30, 2010 15:09:15`.
**`strftime-xcheck.c` is a HOST program** on the `tz-xcheck` pattern:
it links libap's strftime into a glibc program and sweeps 40
conversions over every day of fourteen years -- **204960 checks, 0
wrong**. The range is chosen so the ISO-week edges (a January date in
last year's week 53, a December date in next year's week 1) occur
hundreds of times rather than by luck.
**ITS FIRST VERSION WAS VACUOUS AND THE CONTROL IS WHAT SAID SO.**
`-Dstrftime=ap_strftime` in a single gcc command applies to the
CHECKER as well, so its own reference call became `ap_strftime` and
the sweep compared libap against ITSELF -- reporting `204960 checked,
0 wrong`, which is the same sentence a real run prints. A
deliberately broken ISO-week branch reported 0 wrong too; with two
compiles it reports **27**, naming `%G`, `%g` and `%G-W%V-%u` on
exactly the January dates. *Eleventh instrument fault, and the
cheapest possible catch: break the thing on purpose and see whether
the instrument notices.* The command is in the file and it is two
compiles for the same reason `ctype-xcheck` is.

**MEASURED: `run-printf` 86 -> 45, AND IT IS THE ONLY FILE THAT
MOVED.** Per-file diff against the previous run is one line, so the
three printf fixes and the fifteen strftime conversions are confirmed
with nothing else disturbed. What is left is the `%08X` probe above
and `hexdump: command not found` -- a program this tree has not got,
in `printf6.sub` alone. So `run-printf` is accounted for end to end
like `run-histexpand` before it.
**AND THE strtoumax FIX IS CONFIRMED: 45 -> 43, `FFFFFFFF9B3A59A5`
GONE.** *I predicted 44 and the arithmetic was mine, not the
library's*: the bucket counts a section's `<` AND `>` lines, so
removing a one-line `149c149` hunk removes **two**. A per-file count
here is differing LINES, not differing facts, and a `c` hunk always
costs at least two. **43 is `hexdump` and nothing else.**

**AND READING `strtoull` ON THE WAY FOUND THREE BUGS NOTHING HAD
MEASURED -- one by eye and TWO by the sweep that was written to
confirm the first.** None of them is the `%08X` question; they were
found looking for it, and saying so matters, because a fix found
beside a bug is not a fix for it.
- **`strtoull.c` opened `#define UVLONG_MAX (1LL<<63)`**, which is
  not the largest `unsigned long long` -- while `strtoul.c` in the
  same directory uses `ULONG_MAX`. *The library held a correct
  version of the thing it got wrong, for the fourth time* (after
  `mktemp`/`__randname`, `getcwd`/`get_current_dir_name`, and
  `vfscanf` knowing `t`/`j`/`z` while `vfprintf` did not).
  **And my first comment on it was wrong in a way the control
  caught.** I wrote that the overflow threshold was "halved" and
  predicted a band of false ERANGEs. The literal is **signed**:
  `1LL<<63` is LLONG_MIN, `UVLONG_MAX/base` is a signed division, and
  the negative quotient converts to an unsigned value just under
  ULLONG_MAX -- so the threshold was effectively **disabled**, not
  halved, and detection fell back on a `nn < n` wrap test that misses
  a multi-wrap. `strtoull("0777777777777777777777", 16)` returned
  8608480567731124087 and no error. *An expression read rather than
  evaluated is a guess*, and restoring the exact original line is
  what said so: 28 wrong against 0.
- **`strtoll(LLONG_MIN)` answered ERANGE** for a value that is
  exactly representable -- its magnitude is one MORE than LLONG_MAX
  and the loop used one limit for both signs. Now accumulated
  unsigned against a sign-dependent cutoff.
- **`strtoX("0x")` with no hex digit reported NO CONVERSION.** C says
  the subject sequence is the longest *initial* subsequence of the
  expected form, so `strtol("0x", &e, 16)` converts the `0` and
  leaves `e` on the `x`; this consumed the `0x` and then set
  `endptr = nptr`, so a caller testing `endptr == nptr` rejected a
  valid zero. Fixed in **all four** files -- the defect is one shape
  copied four times, and leaving two of them wrong would be worse
  than either state.
**`strtoint-xcheck.c` is the host cross-check**, and it carries the
`strftime-xcheck` lesson forward: the rename must not reach the
checker, and here even `-D` cannot do it (libap's prototypes take
`char *` where glibc's take `const char *`, so the renamed
declaration conflicts) -- so it renames the SOURCE with `sed` into a
temporary and compiles that. 1419 checks, **0 wrong**, 38 before.
**`strtol`/`strtoul` are deliberately NOT swept**: kencc's `long` is
32-bit and the host's is 64, so the two disagree about the right
answer by construction. *A cross-check needs both sides to agree on
what is being computed* -- they get the `0x` fix and their signed-min
arithmetic is recorded, unmeasured, rather than rewritten blind.

**AND THE SWEEP THAT FOLLOWED IT FOUND ONE MORE, THEN CAME BACK
CLEAN.** A missing declaration is never alone, so
`sys/lib/tests/apdecl-sweep.py` asks every `.c` under `lib/ap` whether
it calls a function with a NON-`int` return type that no header in its
include closure declares. It found **`errno/err.c` and
`errno/warn.c`** calling `strerror` with no `<string.h>`, handing a
truncated `char *` straight to `%s` -- *in the two functions a program
reaches once something has already gone wrong*, so the failure lands
on top of another one. 0 hits now.
**Three versions of that sweep reported 491, 79 and 2, and the first
two were almost all NOISE.** The cuts that mattered: strip comments
and string literals (the first version counted `rendezvous()` named in
a COMMENT as a call); limit the declaring headers to the standard set
(the APE include directory also holds `sqlite3ext.h`, `chicken.h`,
`zlib.h`, `libdwarf.h`); and **put `lib/ap/include` on the search
path, which is the mkfiles' own `-I../include`** -- without it every
file under `math/` and `complex/` reads as undeclared, because
`libm.h` lives there and is what includes `<math.h>`. *An instrument
whose include path is not the BUILD's include path is measuring a
different program.* It is a lower bound by construction and says so in
its own header, like the all-char struct sweep.

**`strerror` WAS WRONG IN 40 OF 76 ENTRIES, AND TWO OF THEM NAMED
THE WRONG ERROR.** `run-redir`'s `Bad file number` was the way in,
and reading that one entry would have fixed that one entry. Asking
the WHOLE table against glibc found 40.
**The pair that matters is EACCES and EPERM.** The table said
`EACCES "Access denied"` and `EPERM "Permission denied"` -- and
`Permission denied` is what every other system prints for **EACCES**.
So the one message a reader is most likely to recognise named the
wrong errno: a program failing with EPERM reported EACCES's text, and
anything matching on it -- a test, a log, a person -- drew the
opposite conclusion. *A wrong message is a bug in one line; a message
that is another error's correct message is a bug in the reader.* This
tree already spent a round on `_errno.c` mapping Plan 9's "permission
denied" to EPERM where POSIX wants EACCES, and the two errors have
now been confused at both ends of the same path.
The other 38 were merely terse -- `Too big`, `Try again`,
`No buffers`, `Shut down`. **Nothing in POSIX fixes the wording**, so
this is not conformance: it is that the tree exists to run GNU
software, whose suites compare against the text glibc produces.
`EDOM`/`ERANGE` are 1000 and 1001, outside the table, spelled in
`strerror()`'s own arms -- they had the same defect and are fixed
with it.
**Generated rather than transcribed**, which is the part worth
keeping: the mapping came from parsing `errno.h` for the names and
asking glibc for each one, so no entry was typed and none can be off
by a row. **Every line now carries its name**, because a table
indexed by errno with unnamed rows is exactly how an entry drifts.
**`strerror-xcheck.py` is the instrument and is checked in.** It
cannot be a C cross-check like the others, and the reason is the
whole difficulty: **APE's errno NUMBERS are its own** -- EBADF is 4
here and 9 on glibc -- so comparing by index would be nonsense
dressed as a measurement, and only the NAMES line up. **Both controls
fire**: reverting one word reports 1 and names `EBADF`; inserting one
row reports **68**, which is the drift case it exists to catch.
`EGREG` is reported UNCHECKABLE rather than passed over -- it is
APE's own (`_errno.c` maps Plan 9's "ken has left the building" to
it), glibc has no such error, and its text is left alone. It reads
`Unknown error`, which is also what the fallback returns for an errno
out of range, so the two are indistinguishable from outside.
*Recorded rather than changed: a new wording would be invented and
nothing has measured it.*
**MEASURED, AND BOTH NUMBERS WERE TOO LOW: `run-redir` 77 -> 63
(predicted ~70) and `run-vredir` 11 -> 5 (predicted ~9).** And the
refutation condition fired usefully: **`run-errors` 8 -> 4 moved too**
-- the same two `Bad file number` lines, in a third file I had never
opened. *Three files, one fix, nothing up.*
**Why the predictions were low is the same mistake in both**: I sized
them from the one section head I had read rather than counting the
string across the whole log. The sweep that settles it takes one
command and I only ran it AFTER the run -- `Access denied` **7 -> 0**,
`Bad file number` **9 -> 0**, and `Permission denied` **10 -> 0**
while `Operation not permitted` went 1 -> 4, which is the EPERM/EACCES
swap unwinding exactly as read. *Count the string in the corpus, not
in the paragraph you happened to read.*
**TWO occurrences of `No such system call` SURVIVE, and they are not
the table.** They are `ln: failed to create symbolic link` and
`mkfifo: cannot create fifo` -- ENOSYS from `symlink()` and
`mkfifo()`, printed by **coreutils binaries that were not relinked**.
APE is statically linked, so every program carries its own copy of
`sys_errlist[]`, and `mk install` rebuilds `libap.a` without relinking
programs already built against it. bash was rebuilt and changed; `ln`
and `mkfifo` were not and did not. *That is the rule already in this
file -- a libap fix can sit unused for rounds -- showing up as two
lines rather than as a silence*, and `mk distclean` before the next
`mk install` is what would finish it.
**IT DID, AND THE WHOLE REBUILD MOVED NOTHING ELSE.** After a full
`mk distclean` plus `mk install`, both lines read
`Function not implemented` -- glibc's ENOSYS wording, from the new
table -- at the same two line numbers in the same two sections.
*The prediction named the exact two lines and the exact two files,
and nothing else in 1601 lines changed*, which is as clean a
confirmation of the static-linking reading as this corpus can give.
**And that is the more valuable half of the run.** `REAL 38 /
WARNONLY 1 / PASS 47` are identical to the previous run, and the
per-file diff is **one line** -- `run-trap` 14 -> 16, the xtrace hunk
that regroups between identical runs and has already gone back and
forth twice. So the first relink of the ENTIRE tree since
`ctype`/`getcwd`/`umask`/`mktemp`/`printf`/`strftime`/`strtoull`/
`strtoumax`/`strerror` **broke nothing anywhere in bash's suite**.
*A green run after a distclean is the only control that covers
programs no test names*, and until now every one of those fixes had
only ever been measured through a binary that happened to be
rebuilt. The errno sweep closes with it: `Access denied`,
`Bad file number`, `Too big`, `Try again`, `No buffers` and
`Shut down` are **0 in the corpus**, `Operation not permitted` holds
at 4.
**And it left one new item, which is the EGREG arm becoming
visible.** `run-read`'s `read7.sub` prints
`redirection error: cannot duplicate fd: Unknown error`, and the
next line is `line 60: 5174752: Unknown error` -- a garbage fd number
downstream of the failed dup. `Unknown error` is the table's text for
**EGREG**, which `fcntl.c`'s `F_DUPFD` sets for a buffered
descriptor. *An errno naming the wrong category, printed to a user* --
the commonest bug shape here -- and it is only legible now because
the rest of the table stopped saying `Unknown error` by accident.
Recorded, not fixed: `run-read`'s other 27 lines are `/dev/tty`
(absent on Plan 9) and the `mkfifo` stub.

**FIXED THE NEXT ROUND, AND IT WAS MUCH WIDER THAN THREE LOG LINES:
`dup()` AND `dup2()` ARE EACH ONE LINE OF `fcntl(.., F_DUPFD, ..)`,
so all three refused.** A descriptor becomes buffered the first time
anything `select()`s it -- libap's select forks a copy process rather
than polling -- so **any program with an event loop had lost the
ability to dup the descriptors it was watching**, select() being how
an event loop works and dup being how a shell redirects. *Three lines
in one test file, and the reachable surface is most interactive
programs.* `read7.sub` line 60 is `read -e -t .001 a <<<abcde`,
counted rather than guessed: `-e` is readline, which select()s fd 0;
the here-string is a redirection of fd 0, so bash saves the original
with a dup first.
**The arm was protecting against something real, which is why the fix
is two lines and not a deletion.** `Muxbuf` is keyed on the descriptor
NUMBER (`_buf.c`'s `b->fd`) and `Fdinfo` holds a `buf` POINTER beside
the flag, so copying `fi->flags` wholesale onto a new number makes
`_readbuf` find `b->fd != fd` and answer **EBADF on every read** -- a
dup that succeeds and hands back something broken, which is worse
than the refusal. **But those two bits are facts about a descriptor
number in one process image, not about the open file** -- the
invariant `_fdinfo.c` already states for `FD_BUFFEREDX`, and
`sfdinit` already scrubs this exact pair on exec in exactly these two
lines. Copied whole, pointer included; `FD_ISTTY` and `FD_ISREG` are
facts about the FILE and carry over unchanged. *The second line is
the one that would have been forgotten.*
**The limit is recorded rather than hidden**: bytes the copy process
has already drained into the Muxbuf are not visible through the new
descriptor, so the two do not share a read position the way POSIX
says two dups of one open file description do. There is nowhere to
put them, a reader of the dup was *already* competing with the copy
process (the measured keystroke-thief hazard), and the dominant use
of dup -- a shell saving a descriptor to restore later -- never reads
it.
**`_dupmark()` is the marker** (sixth use of the idiom), and
**both controls fire on the host**: replicating the old refusal gives
**4** failures, replicating the HALF-FIX -- dup succeeds, reads give
EBADF -- gives **exactly 1**, section 5, which the header says is
there for it. *A control that fires on one section is better evidence
than one that fires on four*: it says the section is not decorative.
0 failures on glibc.
**CONFIRMED ON THE VM: `_dupmark = 1`, all seven sections PASS, 0
failures** -- and the two lines that carry it are section 4b,
`fcntl(buffered, F_DUPFD, 25)` answering **>= 25** where it used to
refuse, and section 5, `read(dup) -> -1, errno 3` rather than EBADF.
*Errno 3 is EWOULDBLOCK, which is the test's own non-blocking reads
and not a failure*: the bytes are in the copy process, which is the
limit the header records rather than a defect. Section 6 then reads
all eight from the original, so the dup did not cost the original
its data.
**And `dupbuf-test` HUNG on its first host run, in the way its own
header had just finished describing** -- section 5 drains the pipe
through the dup and section 6 then blocks reading the original.
*Writing the hazard down one paragraph above the bug did not prevent
the bug*, which is the `abort()`-allocates lesson again. Every read is
non-blocking now, set once at pipe creation so it is true by
construction rather than by argument, and stdout is unbuffered so a
future hang names its section -- the kill took the buffered output
with it and left nothing at all to read. *Twelfth instrument fault.*

**AND THE REST OF THE REAL LIST WAS SURVEYED IN ONE COMMAND, by
counting each cause across the whole corpus rather than reading
files.** 1094 differing lines over 38 files. **The share that is a
bug in this tree is small, and two of the four are new:**
- **`. ` and `..` missing from a glob -- OURS, and now measured in a
  SECOND suite.** `run-extglob` wants `. .. .a .foo` and gets
  `.a .foo`. This is Tcl's `filename-14.9` exactly -- **Plan 9
  directories contain neither entry** -- recorded there as wanting
  its own round because synthesising them in `readdir()` changes
  what every directory read in every program sees. *One measurement
  made it a deferred curiosity; a second, independent one makes it
  the biggest thing here that is ours.*
  **DONE, NOT YET MEASURED ON THE VM. The sweep came before the code**,
  because the risk is not whether POSIX wants the entries -- it does --
  but whether anything here walks a directory WITHOUT skipping them,
  since such a caller recurses for ever. All six `readdir()` callers in
  libap were read: `rmdir.c` (strcmp), `fts.c` (`ISDOT` unless
  `FTS_SEEDOT`), `nftw.c` (open-coded ISDOT) and `seekdir.c` (replays
  readdir) are safe; `scandir.c` does not skip and is **correct** not
  to, since scandir reports everything and the caller's filter decides.
  **Two of them were WRITTEN EXPECTING these entries**, which is the
  strongest evidence available that their absence is the anomaly:
  `rmdir.c` spends a strcmp per entry skipping names Plan 9 never
  produced, and musl's `glob` does not skip them at all -- it relies on
  `fnmatch` with `FNM_PERIOD`, so `*` excludes them and `.*` matches
  them. **That is exactly what both failing tests ask for, so glob
  needs no change and starts answering correctly on its own.**
  **`d_ino` is real, not 0**: `.` is `fstat`ed from the stream's own
  descriptor and `..` stat'ed through `fd2path` + `/..`, two stats per
  directory TRAVERSAL rather than per entry. Zero would be the zipfs
  `st_rdev` trap -- *a field that is always zero reads as information
  and is not* -- and `find`'s loop detection, the classic `getcwd` and
  `du`'s hard-link check all read it. At the root `/..` is `/` here as
  on a unix, so no special case; if the parent cannot be stat'ed the
  directory's own identity is used rather than a zero.
  **NO NEW FIELD, so `sizeof(DIR)` does not move and this is NOT an
  ABI change.** `dd_seek` is already the stream's entry counter and
  the synthetic entries genuinely ARE entries 0 and 1, so the counter
  describing them is the same fact rather than a second one -- and
  `telldir`/`seekdir` come right for nothing, since seekdir rewinds and
  replays `readdir()`. **A full rebuild is still needed, for the OTHER
  reason**: a libap fix does not reach binaries already linked.
  **`_dotdirmark()` is the marker** (seventh use). `dotdir-test.c` is
  0 failures on glibc, and the host control -- an `LD_PRELOAD` readdir
  dropping both entries -- gives **5**, naming sections 3, 4a, 4b, 4c
  and 6a, with section 5 correctly unmoved.
  **But the host control did NOT cover section 7, and that is written
  in the file rather than left to be assumed**: glibc's `glob` does not
  route through an interposed `readdir`, so section 7's host PASS
  measures glibc and says nothing about the chain. *On Plan 9 it is the
  only section that asks the question the two suites actually compare*
  -- `glob("*")` must not match them and `glob(".*")` must. Section 6b
  likewise never crossed the synthetic/real boundary on the host,
  because glibc put a real entry at position 0.
  **`fts.c:600` is a pre-existing oddity found on the way and NOT
  touched**: `nlinks = fts_nlink - 2` assumes a directory's link count
  includes `.` and `..`, while `dirtostat.c` sets `st_nlink = 1`
  always -- so that arithmetic has been giving -1 here all along.
  Recorded, unmeasured, and independent of this change.
  **MEASURED AFTER A FULL `mk distclean`: `run-extglob` 20 -> 0, it
  PASSES**, and all twenty lines were the same thing -- ten `c` hunks,
  each `.a .foo` against `. .. .a .foo`. **`run-glob-test` 63 -> 61 is
  a SECOND confirmation and was not predicted**: `.a .aa .b .bb`
  against `. .. .a .aa .b .bb`, in a file whose other 61 lines are the
  GLOBSORT/locale problems that cannot pass here. **Zero `. ..`
  expectations remain anywhere in the corpus.**
  **AND THE SAFETY EVIDENCE IS THE BETTER HALF.** A change that
  touches every directory read in every program, measured across 86
  test files, added **SEVEN lines corpus-wide and not one of them is
  a directory entry**: three are run-to-run noise (the oscillating
  xtrace hunk, and two `jobs*.sub` lines that carry a pid), four are
  the run's own environment. *The sweep of libap's six readdir callers
  predicted exactly this, and "nothing arrived" is the only form the
  confirmation could take* -- a recursing walker would have hung the
  suite, and a leaking entry would be a new line somewhere.
- **`[=x=]` and `[.x.]` answer `Unknown collating element`**, 9 lines
  in `run-cond`. `ap/regex/regcomp.c` is musl's TRE and the line is
  **musl's own** -- `/* collating symbols and equivalence classes are
  not supported */` -- so this is a vendored gap, not an APExp
  regression. **But the C-locale answer is mechanical**: every
  equivalence class is a singleton there, so `[[=d=]]` IS `[d]`.
  Accepting the single-character form and keeping `REG_ECOLLATE` for
  multi-character ones is conformance rather than invention, and
  small.
  **DONE, and the justification is sharper than "the C locale" alone:
  there is no collation table anywhere in TRE** -- the engine compares
  encoded values, as its own `XXX - Should use collation order instead
  of encoding values` comment says -- so the C locale is what every
  comparison already implements and no second reading is available.
  A collating symbol naming one character IS that character in any
  locale; a multi-character element still answers ECOLLATE, because
  this locale has none to name. `parse_collating()` is a helper rather
  than inline code because the construct is legal as a RANGE ENDPOINT
  too, and the two call sites would otherwise disagree about what a
  bracket may hold.
  **THE CROSS-CHECK CORRECTED THE FIX TWICE, and reading alone would
  have shipped both** -- each agreed with glibc everywhere else:
  - **`[[=d=]-z]` was accepted and glibc answers `REG_ERANGE`.** An
    equivalence class names a SET and so has no position in the
    order; a collating symbol names one element and can bound a
    range. The helper now reports which it parsed, and both call
    sites refuse the equivalence class. *The corpus asks all four
    combinations -- each construct on each side -- for the reason
    `$@` was asked beside `$*`.*
  - **`[[.d]]` answered ECOLLATE where glibc says `REG_EBRACK`.** An
    unterminated `[.` is an unclosed bracket expression; only a
    TERMINATED one naming something unsupported is ECOLLATE. The
    helper scans for the closing delimiter FIRST so the two stay
    distinguishable.
  **`regcoll-xcheck.c`: 1906 checks, 0 wrong; the old blanket refusal
  replicated beside it gives 1652** -- and its section 3 (ordinary
  brackets, no collation) stays at **0 in both runs**, which is the
  half that matters, since a control that moved with the collation
  code would not be a control at all.
  **MEASURED: `run-cond` 18 -> 0, it PASSES**, and the `ok 1`..`ok 9`
  lines on the expected side now match -- so the fix produces correct
  MATCHING, not merely a non-error. `[[.d.][.D.]]o.` answering
  `ok 7 -- d` is the chain end to end.
  ***And my "drop by 9" prediction was wrong by arithmetic I had
  already recorded once***: 9 is the count of lines mentioning
  `collating element`, and the bucket counts a section's `<` AND `>`
  lines, so two `c` hunks of 5 and 4 cost **18**. *A `c` hunk always
  costs at least two* -- written down after `run-printf` predicted 44
  and gave 43, and repeated here anyway.
- **`set -r` -- `RESTRICTED_SHELL`, the same switch shape a sixth
  time.** `run-rsh` 33. Inert unless invoked as `rbash` or with `-r`,
  so unlike `BANG_HISTORY` it costs nothing to turn on.
  **TURNED ON, gcc-swept, NOT YET MEASURED ON THE VM.** Nothing was
  missing from the build, as with READLINE, HELP_BUILTIN and
  BANG_HISTORY before it: the switch gates 55 sites across eight `.c`
  files and nine `.def` files, every one already in OFILES or
  DEFFILES, so no mkfile change. **0 errors** in the class 6c treats
  as fatal, across the six `.c` files and the nine generated
  builtins. **And the control is the preprocessed line count, not the
  error count** -- `shell.c` **+93**, `flags.c` +20, `variables.c`
  +29, `execute_cmd.c` +24, `builtins/common.c` +10, `redir.c` +8 --
  because 0 errors with the switch off is the same number and says
  nothing. The real `config.h` is swapped in place to get that:
  *`-I` cannot override `config.h` for bash's own sources*, which is
  already recorded here and is still true.
  **`builtext.h` had to be generated first** or `execute_cmd.c` and
  `variables.c` report a fatal missing-header "error" and the sweep
  reads as two real failures. Same harness artefact as last time.
  **MEASURED: `run-rsh` 33 -> 1, and THREE files moved that were not
  predicted** -- `run-shopt` 19 -> 16 (`restricted_shell` now in the
  `shopt` table), `run-invocation` 9 -> 6 (`--restricted` in the long
  options) and `run-complete` 19 -> 18 (`restricted_shell` in the
  completion list). Each attributed by diffing the section's own lines
  rather than inferred: `restricted` across the corpus goes **17 -> 0**.
  **The one line left in `run-rsh` is `ln: failed to create hard link
  to 'sh': Too many links`** -- the test makes `rbash` with a hard
  link, and Plan 9 has none. *That is the `link()`/`LINK_MAX 1` item
  examined and deliberately NOT filed as a bug last round, and the
  reading holds*: the errno is internally consistent, the capability
  is simply absent, and the test cannot pass here.

**THE WHOLE ROUND MEASURED, AND THE F_DUPFD FIX CAME WITH IT.**
`REAL 38 -> 37`, `PASS 47 -> 48`, 1094 -> 1033 differing lines,
**nothing rose**. Everything is attributed:
RESTRICTED_SHELL 39 lines, collating 18 (`run-cond` passes),
**F_DUPFD 2** -- and `run-trap` 16 -> 14, the xtrace hunk oscillating
for the fourth time, which is not a change.
**`read7.sub`'s two lines are gone exactly**: `cannot duplicate fd:
Unknown error` and the garbage-fd line below it, so the dup fix is
confirmed where it was found. **The corpus count is what made that
readable** -- `cannot duplicate fd` went 3 -> 2 and `Unknown error`
2 -> 0, and the two survivors were always different cases:
`redir5.sub`'s is `Bad file descriptor` and unchanged, and
`vredir6.sub`'s is on the `>` side, the `ulimit -n 6` line the suite
*wants*. *Counting the string beside reading the section is what
separated a surviving instance of the bug from two things that were
never it.*

**AND THE NEXT ROUND, AFTER A FULL `mk distclean`: `REAL 37 -> 36`,
`PASS 48 -> 49`, 1033 -> 1015 lines.** `run-extglob` and
`run-glob-test` are the readdir fix (above). Two others moved and
**neither is the tree**:
- **`run-nameref` 1 -> 5 ROSE, and it is the RUN'S OWN ENVIRONMENT.**
  The test prints `declare -x` for everything exported, and the new
  run carries `vts`, `vtsdebug`, `vtslog` and `vtspid` beside the
  `vgasize` the old one had -- so this suite was run from inside a
  **vts session** where the previous one was not. `session.c`'s
  `putenv("vts"...)` and `vts-bash`'s `$vtsdebug` are where they come
  from. *A test that compares the whole environment measures the
  environment it was run in*, which joins the harness's own
  `fconfigure`, the kernel's fd warnings and the `awk` that blocked:
  **the fifth time something outside the tree has shown up inside a
  measurement of it.** Nothing to fix, and nothing to read as a
  regression -- but a run from a plain `apexp-sh` would answer 1.
- **`run-redir` 63 -> 61 is UNEXPLAINED and recorded as such.** One
  hunk went: `exec 6<>$TMPDIR/bash-c` at `redir.tests:83` used to
  answer `6: Bad file descriptor` and now works. Two things changed
  in this build -- the readdir entries and the first full relink of
  every binary in the tree -- and *`exec N<>file` is a dup onto a
  chosen descriptor, which is F_DUPFD's path*, but that fix was
  already in the previous run's bash and that run still failed here.
  **So the vehicle is not identified and guessing one would be the
  third story in a row.** Cheap refutation: if it comes back next
  run with nothing touching it, it is flaky like `run-trap`'s hunk.
- `run-trap` 14 -> 16 is that hunk oscillating for the **fifth** time.
**AND `dotdir-test` IS NOW RUN ON THE VM: `_dotdirmark = 1`, every
section PASS, 0 failures -- INCLUDING THE TWO THE HOST COULD NOT
REACH.**
- **Section 6b answered in the exact shape predicted**, and the
  output says so rather than leaving it to be argued: it prints
  **`seekdir(2) -> f0`**. On the host that line read `seekdir(0)`,
  because glibc put a real entry at position 0 and the seek never
  crossed the synthetic/real boundary; here the first real entry is
  at **2**, so `telldir`/`seekdir` are measured ACROSS the boundary
  for the first time. *The prediction was written into the file
  before the run and the number in the output is what confirms it.*
- **Section 7 is the chain end to end, and only here does it mean
  anything**: `glob("*")` matched 5 with **0** dot entries,
  `glob(".*")` matched 3 with **2**. glibc's glob does not route
  through an interposed `readdir`, so its host PASS measured glibc;
  libap's glob calls libap's readdir directly, so this one measures
  the thing the two suites compare. *Four independent confirmations
  now -- `run-extglob`, `run-glob-test`, and both halves of this.*
- **Section 4 passed for the right reason, which is the half a
  name-only fix would have failed**: `. d_ino 37897` against
  `stat(dotdirtest.d) 37897` and `.. d_ino 52201` against
  `stat(.) 52201`, both `d_type 4`. The inodes are real and they are
  the right two files.
**The readdir item is CLOSED**: confirmed from outside in two suite
files and from inside in all seven sections.
- **`recho: command not found`, 9 lines, identical in both runs.**
  `bash-runtests` guarantees the four helpers are built, and most
  files find them -- `run-assoc`, `run-ifs` and `run-new-exp` do not.
  A precondition question about the harness, like the `../bash`
  check, and stable rather than flaky.
  **FOUND AND FIXED, AND IT WAS HIDING TESTS RATHER THAN FAILING
  THEM.** `run-all` line 29 is `PATH=.:$PATH`, under upstream's own
  comment *"just to get recho/zecho/printenv if not run via `make
  tests'"* -- while the real route, `Makefile.in:682`, is
  `PATH=$(BUILD_DIR)/tests:$$PATH`, an **ABSOLUTE** path. With `.`
  the helpers are found only while the cwd is still `tests/`, so
  **every test that `cd`s loses them**. *Fourth silently-failing
  precondition in this harness, and the same family as `THIS_SH`:
  upstream's standalone default is a degraded fallback and APExp
  takes the standalone route.*
  **What named the cause was one file disagreeing with itself**:
  `assoc.tests` calls recho at line 63 and it WORKS, then at line 132
  and it does not -- and `cd ${TMPDIR:=/tmp}` sits between them, at
  line 128. *A difference inside one file beats a difference between
  files, because everything else is held constant for free.*
  **They are HIDDEN rather than failed, which is why this is worth a
  round**: recho's whole job is to print its arguments visibly, so a
  missing recho means those assertions are not made at all. `ifs1.sub`
  cds into `$TMPDIR` to test **IFS field splitting with glob
  characters in IFS**; `assoc.tests:128` does the same to test
  associative-array index expansion **against a file literally named
  `[sfiri]`** -- a bracket expression as a filename, next door to the
  readdir and regex-bracket work of the last two rounds.
  **Predict**: `run-ifs` 4 -> 0 (it is recho and nothing else),
  `run-assoc` 6 -> 2 (the `wait: usage` hunk is a different bug and
  stays), `run-new-exp` 34 -> ~28. **And the interesting outcome is
  the other one**: if any of them comes back with DIFFERENT content
  rather than going away, that is a real bug *newly measured* -- the
  rule about a rising count after new tests become runnable -- and
  `assoc.tests:132` is the one to read first.
  The fix is `PATH` set to this directory absolutely, before
  `run-all`; `^` is guarded against an empty `$PATH`, since a cross
  product with the empty list is the EMPTY LIST rather than the other
  operand.
**NOT ours, with the arithmetic**: `JOB_CONTROL` **148** lines (no
`tcsetpgrp`/`tcgetpgrp`, no foreground process group), process
substitution (`/dev/fd` absent and `/fd` has the wrong semantics for
a child), `hexdump` 14 and `locale` 1 (programs this tree has not
got), `/etc` 17, `glob-bracket` 103 (loadable builtin, no dlopen),
`/bin/p` 3 (a name collision), `run-glob-test` 63 (whole-second
mtimes, and unstable by construction).
**One I nearly filed as a bug and did not**: `link()` returns
**EMLINK**, which reads like the stub-answering-the-wrong-thing
family -- but `sys/limits.h` declares **`LINK_MAX 1`**, and POSIX
says EMLINK is exactly what a link past LINK_MAX gives. *It is
internally consistent and the file's own comment says so.* Checking
the constant before writing the entry is what separated it from
`mkfifo`'s `errno = 0`.

**One PROBE, not a claim**: `run-rsh`'s `date` line prints the zone
as **`CES`**, and Central European Summer Time is `CEST`. It is not
a parser truncation -- `tzone.c`'s `Maxname` is 16 -- so it is either
what the machine's `/env/timezone` holds or what `$TZ` says, and
`cat /env/timezone; echo $TZ` answers it in one command. The line is
a timestamp and differs between runs anyway, so it costs nothing to
leave until something else needs that file.
**ANSWERED, AND IT IS NOT OURS: the FILE says `CES`.**
`/env/timezone`'s first line is literally
**`CET 3600 CES 7200`**, followed by its transition times, and
`$TZ` is empty -- so the chain is `$TZ` unset -> `tzone.c` falls back
to `/env/timezone` -> the file names the summer zone `CES` -> `%Z`
prints `CES`. **Every link is behaving correctly**, including ours:
`Maxname` is 16 and the copy guards at 15, so a four-character `CEST`
would fit with room to spare -- *the parser was never truncating, and
the measurement is what turned that from a reading into a fact.*
Nothing in APExp writes or ships timezone data either (one `git
ls-files` hit, and it is diffutils' own test fixture), so this is the
machine's `/adm/timezone` and a fix belongs there rather than here.
*The probe cost one command and closed an item that three rounds of
reading could not have.*

**IS BASH DONE? NOT QUITE, AND THE HONEST ANSWER IS A LIST.** Every
section was classified in one sweep of the heads -- 36 files, 1015
lines. **~950 of them are settled**, almost all platform limits:
JOB_CONTROL (`run-jobs` 176, `run-builtins` 85, `run-complete` 18,
`run-shopt` 16, `run-trap` 16, `run-errors` 4 -- `bg: command not
found` against `bg: no job control` is that switch exactly), process
substitution (`run-func` 70, `run-procsub` 35, `run-histexpand` 35,
`run-new-exp` 34, `run-quotearray` 27 -- `<(` inside `[[ ]]`),
no dlopen (`run-glob-bracket` 103), `/etc` absent (`run-dirstack` 53,
part of `run-coproc`), whole-second mtimes (`run-glob-test` 61),
`hexdump` (`run-printf` 43), `/dev/tty` and `mkfifo` (`run-read` 27),
symlinks (`run-globstar` 5), `/bin/p` (`run-comsub2` 19), a hard link
(`run-rsh` 1), `ulimit -n 6` on the expected side (`run-vredir` 5),
and the run's own environment (`run-nameref` 5).
**What is NOT yet attributed is about SEVEN files and ~65 lines**, and
that is the list the next bash round should start from rather than
re-deriving:
- **`run-invocation` 6 -- almost certainly the switch shape a SEVENTH
  time.** The expected side carries `--dump-po-strings` and
  `--dump-strings`, which `shell.c:260` gates on
  **`TRANSLATABLE_STRINGS`**, and `config.h:1425` has it `#undef`.
  32 sites, and `-I$BASHSRC/lib/intl` is already on CFLAGS. *Needs a
  decision rather than a sweep-in*, like BANG_HISTORY: it changes what
  `$"..."` means.
- **`run-intl` 5 -- locale, and possibly ours.** The test wants
  `1,0000` and we answer `1.0000`, i.e. **`LC_NUMERIC` is not taking
  effect**, plus `Passed all 1318 Unicode tests` against 1770.
- **`run-posixpat` 15 -- every line is `>`**, i.e. expected output
  ABSENT, which is the shape a missing capability makes. Unread.
- **`run-nquote` 16, `run-lastpipe` 14, `run-heredoc` 8** -- unread.
  `run-heredoc`'s `1: no<TAB>OK` against `1: OK` is a field
  difference rather than a missing feature.
- **`run-attr` 2 -- `declare -rx p="1"` against `declare -r p="1"`.**
  A variable marked EXPORTED that should not be; small, specific and
  plausibly ours.
- **`wait: usage: wait [pid ...]`** in `run-assoc` and `run-array`:
  bash's own `wait` refusing its arguments, in two files.
*So the remaining genuinely-ours surface in bash is small and named,
and two of the seven have shapes this campaign has repeatedly found
to be real and cheap.* **The big blocks will not move without
`tcsetpgrp`, `/dev/fd` or `dlopen`**, none of which Plan 9 has.
