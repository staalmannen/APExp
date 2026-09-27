# bash-fdloop-test.sh -- does bash leak descriptors PER FORK, and how fast?
#
#	cd /sys/lib/tests && /bin/bash bash-fdloop-test.sh
#	cat /tmp/fdloop.log          # <- the real output; read this
#
# Run it from inside apexp-sh. It needs no tracing and no second
# window, and **the log is the artefact**: the process is expected to
# die, so anything only on screen may be lost or out of order.
#
# ------------------------------------------------------------------
# THE BUG.
#
# bash cannot be /bin/sh here. A full `mk install' and bash's own
# `run-all' both die with
#
#	bash NNNN: warning: process exceeds 100 file descriptors
#	bash NNNN: warning: process exceeds 200 file descriptors
#	bash NNNN: Killed: Insufficient physical memory
#
# run-all's top level is forty iterations of `echo $x ; sh $x ; rm -f
# $BASH_TSTOUT' -- it hardly opens a file, so 200 descriptors cannot
# come from its work. They come from the fork/exec/wait machinery, and
# this file is that loop with the tests removed.
#
# ------------------------------------------------------------------
# THREE THINGS EARLIER VERSIONS GOT WRONG. All three are the same
# mistake in different clothes: **the instrument perturbed or hid what
# it was measuring.**
#
#   1. The "no fork" control forked. Its counter was `i=`expr $i + 1``
#      and **expr is an external command**, so all three sections
#      forked 400 times and the control controlled for nothing.
#      Bash's `$((i+1))' is a builtin.
#
#   2. Output went to stdout, which is buffered, while the kernel's
#      warnings go straight to the console -- so the two streams
#      interleaved meaninglessly. Moving to stderr did NOT fix it: the
#      warnings still printed before the script's first line.
#      **So this version does not rely on console ordering at all.**
#      Every step appends a line to /tmp/fdloop.log, which survives
#      the kill and is in the order it happened.
#
#   3. **Counting the descriptors FORKED.** `fdcount` ran `wc -l` in a
#      command substitution -- a subshell plus an exec, per sample, in
#      a test whose whole subject is what forking costs. A run could
#      die inside its own first measurement, which is consistent with
#      what the last one did: it printed the pid and then nothing, and
#      `start:' never appeared.
#      **fdcount() now forks NOTHING**: it counts with a `read' loop
#      (Plan 9, where /proc/<pid>/fd is a FILE) or a glob (Linux,
#      where it is a DIRECTORY), both builtins, and returns the answer
#      in a variable rather than through `$( )', which would itself be
#      a subshell.
#
# *An instrument that shares state with the thing it measures can be
# the thing it reports* -- already in CLAUDE.md, now paid for three
# more times in one file.
#
# ------------------------------------------------------------------
# READING /tmp/fdloop.log.
#
# The counts come first and early, at 1, 2, 5, 10, 20, 50, 100 forks,
# because the slope near zero is what says how bad it is and the
# process may not survive to 100.
#
#   descriptors rise ~N per fork   -> the leak, and N sizes it
#   descriptors flat, then death   -> NOT descriptors; the kernel's
#                                     `Insufficient physical memory'
#                                     is the true message and the
#                                     warnings are a side effect
#   rise and fall                  -> a busy shell, not a leak
#
# The last line in the log is where it died, which is the one thing
# the previous versions could never say.
#
# Correct on glibc, where every count stays flat -- run it there
# first; that is what makes a rise on 9front attributable.

LOG=/tmp/fdloop.log
rm -f $LOG

# Durable, ordered, and not a fork: a redirection on a builtin.
mark() {
	echo "$*" >> $LOG
	echo "$*" >&2
}

# **NO FORK IN HERE.** Sets FDN. Called as `fdcount' and then read as
# $FDN -- never as `$(fdcount)', which would be a subshell.
FDN=0
fdcount() {
	FDN=0
	if [ -d /proc/$$/fd ]; then
		# linux: a directory, one entry per descriptor. The glob
		# is a builtin; ls would not be.
		for _f in /proc/$$/fd/*; do
			FDN=$((FDN+1))
		done
	elif [ -f /proc/$$/fd ]; then
		# plan 9: a file, one line per descriptor, preceded by a
		# line holding the CWD -- which is not a descriptor.
		while read -r _l; do
			FDN=$((FDN+1))
		done < /proc/$$/fd
		FDN=$((FDN-1))
	else
		FDN=-1
	fi
}

mark "bash-fdloop-test: pid $$"

fdcount
mark "start: $FDN descriptors (before anything forks)"

# --- 1. NO FORK AT ALL.  Both : and $((...)) are builtins, and
#        fdcount forks nothing, so this section spawns NOTHING. If the
#        count moves here, forking is not the mechanism.
i=0
while [ $i -lt 400 ]; do
	:
	i=$((i+1))
done
fdcount
mark "1. after 400 iterations with NO fork: $FDN descriptors"

# --- 2. THE SLOPE.  One fork+exec per iteration, counted at 1, 2, 5,
#        10, 20, 50, 100, 200 -- close together at the start, because
#        the first few forks are what say whether it is one descriptor
#        per fork or twenty, and the process may not reach 200.
mark "2. fork + exec + wait (sh -c :), counting as it goes"
i=0
while [ $i -lt 200 ]; do
	sh -c :
	i=$((i+1))
	case $i in
	1|2|5|10|20|50|100|200)
		fdcount
		mark "   after $i forks: $FDN descriptors" ;;
	esac
done
mark "   section 2 survived 200 forks"

# --- 3. THE SAME WITH A REDIRECTION, which adds an open, a dup2 and a
#        close in the parent -- the path with the descriptor
#        bookkeeping in it (close() -> _closebuf, dup2() -> close()).
mark "3. fork + exec + wait with a redirection, counting as it goes"
i=0
while [ $i -lt 200 ]; do
	sh -c : > /dev/null
	i=$((i+1))
	case $i in
	1|2|5|10|20|50|100|200)
		fdcount
		mark "   after $i forks: $FDN descriptors" ;;
	esac
done
mark "   section 3 survived 200 forks"

# --- 4. PROCESSES, not descriptors.  This one DOES fork (ps and grep
#        are external), so it is last and runs once: if the shells and
#        their copy processes are piling up, the descriptor count may
#        be innocent and the memory message the true one.
mark "4. processes named bash or sh right now: `ps | grep -c -e ' bash$' -e ' sh$'`"

mark "bash-fdloop-test: finished all sections"
