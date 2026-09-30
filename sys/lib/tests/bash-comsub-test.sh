# bash-comsub-test.sh -- WHICH LINE of bash's run-all starts the Brk storm?
#
#	cd /sys/lib/tests && /bin/bash bash-comsub-test.sh
#	cat /tmp/comsub.log          # <- the real output; read this
#
# Run it from inside apexp-sh. **The log is the artefact**: the process
# is expected to die, so anything only on screen may be lost or out of
# order -- the kernel's warnings go straight to the console while the
# shell's output does not.
#
# ------------------------------------------------------------------
# WHAT THE ratrace LOG ALREADY SAID, AND WHY THIS FILE IS SMALL.
#
# `ratrace /bin/bash run-all' produced 3458016 lines. Numbering the
# non-Brk ones located the storm to a SINGLE gap:
#
#	   1581:5875 bash Stat ... "/proc/5875/wait" = 71
#	3458015:5875 bash Noted 2d10a7 1 = 0
#	3458016:bash 5875: suicide: fault read addr=0x0 pc=0x0
#
# 3458015 - 1581 = 3456434 Brk lines, out of 3456769 in the whole run:
# **99.99% of the storm is one uninterrupted burst**, not something
# accumulating across the suite.
#
# **AND THE GAP CONTAINS NO SYSCALL OF ANY KIND.** That is an
# exclusion, not a detail:
#
#	a spinning READ loop would show Pread	-- none
#	a spinning WAIT loop would show Await/Stat -- none
#	a create/retry loop would show Open/Create -- none
#
# So the loop is pure computation that allocates ~17 million objects of
# <= 16 bytes and frees none. (Two Brk per _malloc_brk, the break
# stepping ~480 bytes, and BLKSZ(4)*((CUTOFF-4)+2) = 48*10 = 480
# exactly -- so the size class is measured, not guessed.)
#
# The gap opens after run-all's line 21 has been read and its child
# reaped, which is these lines:
#
#	17  : ${TMPDIR:=/tmp}
#	21  SUFFIX=$( ${THIS_SH} -c 'echo $(( $RANDOM + $BASHPID ))' )
#	23  BASH_TSTOUT=${TMPDIR}/bashtst-$SUFFIX
#
# Line 1563 of the trace shows the child writing "30465" to fd 1, so
# the child RAN AND SUCCEEDED. Whatever loops is in the parent, after
# the reap.
#
# ------------------------------------------------------------------
# WHY A BISECT AND NOT MORE SOURCE READING.
#
# Four mechanisms have now been argued from source in this hunt --
# a descriptor leak, _buf.c's copy processes, wait4's WNOHANG
# _dirstat, and read_comsub -- and the log refuted every one. The last
# is refuted by this file's own header: read_comsub calls zread every
# iteration, so a loop there would show Pread lines, and there are
# none.
#
# So this asks the machine instead. Each section writes a durable
# marker BEFORE the statement it is about to run; **the last line in
# the log names the statement that did not return.** That is the whole
# design.
#
# Ordered simplest first, and deliberately so: *every case expected to
# return comes before every case expected to hang*, in file order, or a
# hang early on hides everything after it.
#
# NOTHING HERE FORKS EXCEPT THE SECTION THAT IS ABOUT FORKING. `echo'
# is a builtin and `>>' is a redirection, so mark() costs one open and
# one write -- it cannot be the thing it measures. That mistake has
# been made three times in this investigation already (fdwatch's six
# forks per sample, fdloop's `expr' counter, fdloop's `wc -l` inside
# $( ) in a test about what forking costs).
#
# ------------------------------------------------------------------
# READING /tmp/comsub.log.
#
#   last line is "N: about to ..."   -> section N is the bug, and the
#                                       text names the exact construct
#   every section reports "ok"       -> the storm needs more than these
#                                       lines; the next step is the
#                                       heap watchdog (see below), not
#                                       another reduction
#
# If it reaches the end, run it again with the watchdog on:
#
#	APEXP_MALLOCMAX=64 /bin/bash bash-comsub-test.sh
#
# which aborts inside the allocator once the break has grown 64 MB,
# while the machine is still healthy -- and then `acid <pid>' and
# `stk()' name the calling function. That is the point of the
# watchdog: `Insufficient physical memory' is a KILL, so it leaves
# nothing to inspect, and every round of this hunt so far has been an
# examination of a corpse the kernel had already destroyed.
#
# Correct on glibc, where every section reports ok and the whole thing
# finishes in well under a second -- run it there first; that is what
# makes a stall on 9front attributable.

LOG=/tmp/comsub.log
rm -f $LOG

# Durable, ordered, and not a fork: a builtin plus a redirection.
mark() {
	echo "$*" >> $LOG
	echo "$*" >&2
}

mark "bash-comsub-test: pid $$"

# --- 1. A PLAIN ASSIGNMENT.  No fork, no expansion, no substitution.
#        If this does not come back, nothing below matters and the
#        problem is not command substitution at all.
mark "1: about to do a plain assignment"
X=hello
mark "1: ok ($X)"

# --- 2. run-all LINE 17.  ${VAR:=default} ASSIGNS as a side effect of
#        expanding, which is a different code path from a plain
#        expansion and is the first thing run-all does.
mark "2: about to do : \${TMPDIR:=/tmp}   (run-all line 17)"
: ${TMPDIR:=/tmp}
mark "2: ok (TMPDIR=$TMPDIR)"

# --- 3. COMMAND SUBSTITUTION OF A BUILTIN.  A fork and a pipe, but no
#        exec: it separates "collecting a child's output" from
#        "running a program".
mark "3: about to do V=\$( echo hi )"
V=$( echo hi )
mark "3: ok ($V)"

# --- 4. THE SAME WITH AN EXEC.  If 3 returns and 4 does not, the
#        storm needs the exec, which puts it near the fd/exec
#        bookkeeping rather than the pipe.
mark "4: about to do V=\$( /bin/echo hi )"
V=$( /bin/echo hi )
mark "4: ok ($V)"

# --- 5. $RANDOM.  A shell variable with a GENERATOR behind it, in the
#        parent. Cheap to ask and worth asking separately, because it
#        is the one construct on line 21 that is not I/O.
mark "5: about to do V=\$RANDOM"
V=$RANDOM
mark "5: ok ($V)"

# --- 6. ARITHMETIC EXPANSION containing those variables.  $(( )) is a
#        recursive-descent parser over a string, which is exactly the
#        shape of thing that allocates many tiny objects with no
#        syscall in sight -- the signature the trace showed.
mark "6: about to do V=\$(( RANDOM + BASHPID ))"
V=$(( RANDOM + BASHPID ))
mark "6: ok ($V)"

# --- 7. run-all LINE 21 ENTIRE, with THIS_SH set the way `make tests'
#        sets it. The arithmetic now happens in the CHILD, which the
#        trace showed succeeding, so a stall here with 6 returning
#        would put it in the parent's handling of the result.
mark "7: about to do the whole of run-all line 21"
THIS_SH=${THIS_SH:-/bin/bash}
SUFFIX=$( ${THIS_SH} -c 'echo $(( $RANDOM + $BASHPID ))' )
mark "7: ok (SUFFIX=$SUFFIX)"

# --- 8. run-all LINE 23.  Two expansions and a concatenation, and the
#        very text the trace caught bash reading from fd 255 on the
#        last Pread before the storm.
mark "8: about to do BASH_TSTOUT=\${TMPDIR}/bashtst-\$SUFFIX  (line 23)"
BASH_TSTOUT=${TMPDIR}/bashtst-$SUFFIX
mark "8: ok ($BASH_TSTOUT)"

# --- 9. THE EXPORT, which copies into the environment -- a separate
#        allocator user, and the one run-all does next.
mark "9: about to export BASH_TSTOUT"
export BASH_TSTOUT
mark "9: ok"

# --- 10. THE TRAPS.  run-all sets two, and a trap stores a string to
#         be re-parsed later. Last because it is the least likely and
#         a stall here would still be reported by the line above.
mark "10: about to set the two traps (run-all lines 26-27)"
trap 'rm -f $BASH_TSTOUT ; exit' 1 2 3 15
trap 'rm -f $BASH_TSTOUT' 0
mark "10: ok"

mark "bash-comsub-test: finished all sections -- none of these is the storm"
