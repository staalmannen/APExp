# bash-fdloop-test.sh -- does bash leak descriptors PER FORK?
#
#	cd /sys/lib/tests && /bin/bash bash-fdloop-test.sh
#
# Run it from inside apexp-sh. It takes about a second and needs no
# tracing, no second window and no race to win.
#
# ------------------------------------------------------------------
# THE BUG IT COMES FROM.
#
# bash cannot be /bin/sh here: a full `mk install' dies with
#
#	bash NNNN: warning: process exceeds 100 file descriptors
#	bash NNNN: warning: process exceeds 200 file descriptors
#	bash NNNN: Killed: Insufficient physical memory
#
# and so does bash's own test suite, `run-all', in WELL UNDER A
# SECOND -- fast enough that three rc forks cannot sample /proc before
# the process is gone.
#
# **But run-all's top level barely touches files.** Its whole loop is
#
#	for x in run-*
#	do	echo $x ; sh $x ; rm -f ${BASH_TSTOUT} ;;
#	done
#
# -- about forty iterations of fork, exec and wait. Forty iterations
# cannot reach 200 descriptors by opening files, because it hardly
# opens any. So either the descriptors come from somewhere other than
# `open', or they come a few at a time FROM THE FORK ITSELF.
#
# *Reproduce the call the failing code makes, not the outcome it
# wants.* This is that loop with the tests taken out.
#
# ------------------------------------------------------------------
# HOW TO READ IT: THE TWO SECTIONS ARE A PAIR.
#
# Section 1 loops WITHOUT forking -- `:' is a bash builtin. Section 2
# loops forking and exec'ing a real program, which is what run-all
# does. Both do the same number of iterations.
#
#   both survive        -> not a per-iteration leak at all, and the
#                          suite's own work is back in the frame.
#   1 survives, 2 dies  -> **the leak is in fork/exec/wait**, and it
#                          is libap's, not bash's. That is the
#                          interesting answer and the cheapest one to
#                          act on: a three-line reproducer instead of
#                          an 83-file suite.
#   both die            -> something bash does every iteration
#                          regardless of forking. Look at the loop
#                          itself before libap.
#
# **A SECTION THAT PRINTS ITS `survived' LINE HAS NOT LEAKED ENOUGH TO
# MATTER, WHICH IS NOT THE SAME AS NOT LEAKING.** The kernel warns at
# 100 and 200; below 100 nothing is said. So a clean pass here bounds
# the leak at under 100 per 400 iterations rather than showing zero,
# and the count section at the end is what turns that into a number.
#
# ------------------------------------------------------------------
# WHY IT MIGHT MATTER THAT ratrace CHANGES THE ANSWER.
#
# Under `ratrace' the same suite runs for a long time instead of dying
# at once. If that holds up, the failure is RATE-dependent -- and a
# plain forgotten `close' is not: 100 descriptors is 100 descriptors
# however slowly you reach them.
#
# What speed CAN change is how many things are alive at the same
# time. libap's `select()' forks a copy process per buffered
# descriptor (ap/plan9/_buf.c), and how many exist at once is a race
# between the parent making them and the children exiting. That would
# also explain why the kernel's last word is about MEMORY rather than
# descriptors -- a pile of live copy processes is both at once.
#
# So this file prints the PROCESS COUNT beside the descriptor count.
# If processes named bash or sh pile up while the descriptor count
# stays low, the two numbers have separated and the memory message
# was the true one all along.

echo "bash-fdloop-test: pid $$"
echo

N=400

# The kernel's own warnings go to the console rather than to us, so
# ask /proc directly.
#
# **/proc/<pid>/fd IS A FILE ON PLAN 9 AND A DIRECTORY ON LINUX**, so
# the two need different counts, and this has to run on both: glibc
# is the reference that says the test asserts something about POSIX
# rather than about this tree. Running it on the host is what found
# this -- `wc -l' read a directory and every count came out -1.
#
# Plan 9's file has one line per descriptor, preceded by a line
# holding the CWD, which is not a descriptor -- hence the -1 there.
fdcount() {
	if [ -d /proc/$$/fd ]; then
		ls /proc/$$/fd | wc -l		# linux: one entry per fd
	elif [ -f /proc/$$/fd ]; then
		expr `wc -l < /proc/$$/fd` - 1	# plan 9: cwd line first
	else
		echo '?'
	fi
}

# Copy processes carry the SAME NAME as their parent, so this counts
# the pile rather than just the shells.
pcount() {
	ps 2>/dev/null | grep -c -e ' bash$' -e ' sh$'
}

echo "start: `fdcount` descriptors, `pcount` bash/sh processes"
echo

# --- 1. NO FORK.  `:' is a builtin; nothing is spawned. -------------
echo "1. $N iterations, no fork (: is a builtin)"
i=0
while [ $i -lt $N ]; do
	:
	i=`expr $i + 1`
done
echo "   survived $N: `fdcount` descriptors, `pcount` processes"
echo

# --- 2. FORK AND EXEC, which is what run-all's loop does. -----------
#
# `sh -c :' is deliberately the same shape as run-all's `sh $x': a
# fork, an exec of a real program, and a wait. Nothing is redirected
# and no file is opened, so any descriptor this gains came from the
# machinery rather than from the work.
echo "2. $N iterations of fork + exec + wait (sh -c :)"
i=0
while [ $i -lt $N ]; do
	sh -c :
	i=`expr $i + 1`
done
echo "   survived $N: `fdcount` descriptors, `pcount` processes"
echo

# --- 3. THE SAME AGAIN, with a redirection. -------------------------
#
# Only if 2 survives. A redirection is an open, a dup2 and a close in
# the parent -- the path with the descriptor-number bookkeeping in it
# (close() -> _closebuf, dup2() -> close()), and the one most likely
# to strand a Muxbuf slot if anything does.
echo "3. $N iterations of fork + exec + wait, with a redirection"
i=0
while [ $i -lt $N ]; do
	sh -c : > /dev/null
	i=`expr $i + 1`
done
echo "   survived $N: `fdcount` descriptors, `pcount` processes"
echo

echo "bash-fdloop-test: finished all three sections"
