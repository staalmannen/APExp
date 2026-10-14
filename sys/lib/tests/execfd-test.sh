#!/bin/bash
#
# execfd-test -- can a shell open a descriptor with `exec N>file' and then
# WRITE to it with `>&N'?
#
#	/bin/bash execfd-test.sh
#	host:  bash execfd-test.sh
#
# WHERE IT CAME FROM: clisp's `configure', the first autoconf script this
# tree has run end to end.  It printed
#
#	configure: line 2574: 5: Bad file descriptor
#
# on nearly every line of its own output, hundreds of times, and ended at
# `C compiler cannot create executables' with a `config.log' it could not
# write.  **Autoconf keeps its log on fd 5** -- `exec 5>>config.log' near
# the top, then `echo ... >&5' everywhere after -- so the whole run was a
# configure whose log descriptor was gone, and the compiler verdict at the
# end is downstream of that rather than a statement about pcc.
#
# AND IT IS NOT A NEW SHAPE.  `docs/notes` and CLAUDE.md already carry
# `run-redir`'s `exec 6<>$TMPDIR/bash-c' answering `6: Bad file
# descriptor' -- recorded as fixed-by-something-unidentified, with the
# refutation condition "if it comes back it is flaky".  *This is the same
# construct and the same message*, so the two are one question and this
# file is what asks it.
#
# WHAT EACH SECTION SEPARATES, which is the whole reason it is not one
# case:
#   1  a LOW descriptor (3) -- the ordinary case, and if this fails the
#      construct is broken outright
#   2  fd 5 specifically, autoconf's own number
#   3  APPEND (`>>'), which is what autoconf uses and which libap
#      emulates with two seeks because Plan 9 has no O_APPEND
#   4  a descriptor opened, written, CLOSED and reopened -- autoconf does
#      this, and a stale `Fdinfo' entry keyed on the NUMBER is a bug shape
#      this tree has already paid for twice
#   5  `<>' read-write, which is `run-redir`'s exact line
#   6  a HIGH descriptor (200), because bash's `move_to_high_fd' puts its
#      own bookkeeping up there and the kernel warns at 100 and 200 --
#      *if only this one fails, the fd TABLE is the subject and not the
#      redirection*
#   7  writing to the descriptor from a CHILD (a subshell) -- a FORK and
#      nothing else
#   8  a child that forks AND EXECS, which is the boundary libap's
#      `/env/_fdinfo' has to describe and where a descriptor has arrived
#      poisoned before
#   9  the shell RE-EXECING ITSELF, which is literally configure's first
#      act (`exec $CONFIG_SHELL "$as_myself"')
#  10  SCALE: fd 5 held across hundreds of forks, reporting the iteration
#      it first fails at -- because every other section runs in a shell
#      that has just started, and configure's failure arrives thousands
#      of lines in, right after the kernel's 100/200-descriptor warning
#
# **Sections 0-7 came back 0 failures on 9front**, so the CONSTRUCT is
# not the bug and `redir.tests:83' is cleared with them.  8, 9 and 10
# are the axes that run did not cover, and they are in order of how
# much of configure they reproduce.
#
# **Section 0 is the control.** It writes the same bytes with an ordinary
# `> file' redirection and reads them back, so a run where every section
# fails says the filesystem or $TMPDIR is the problem rather than `exec'.
#
# 0 failures on glibc.  Exit status is the failure count; read the count
# rather than the status if the shell exits for another reason.

: ${TMPDIR:=/tmp}
D=$TMPDIR/execfd-test.$$
failures=0

ck () {					# ck <name> <ok?> [detail]
	if [ "$2" = 1 ]; then
		echo "PASS: $1"
	else
		echo "FAIL: $1 ${3:+($3)}"
		failures=$((failures+1))
	fi
}

mkdir -p "$D" 2>/dev/null
cd "$D" || { echo "cannot use $D"; exit 125; }

# ---- 0: the control.  An ordinary redirection, no exec at all.
echo control > f0 2>/dev/null
got=$(cat f0 2>/dev/null)
ck "0 plain > redirection writes and reads back" \
   $([ "$got" = control ] && echo 1 || echo 0) \
   "a failure here is the filesystem, not exec"

# ---- 1: a low descriptor.
ok=0
if exec 3>f1 2>/dev/null; then
	echo three >&3 2>/dev/null && ok=1
	exec 3>&- 2>/dev/null
fi
got=$(cat f1 2>/dev/null)
ck "1 exec 3>file then >&3" \
   $([ "$ok" = 1 ] && [ "$got" = three ] && echo 1 || echo 0) "got [$got]"

# ---- 2: fd 5, autoconf's own.
ok=0
if exec 5>f2 2>/dev/null; then
	echo five >&5 2>/dev/null && ok=1
	exec 5>&- 2>/dev/null
fi
got=$(cat f2 2>/dev/null)
ck "2 exec 5>file then >&5 (autoconf's log descriptor)" \
   $([ "$ok" = 1 ] && [ "$got" = five ] && echo 1 || echo 0) "got [$got]"

# ---- 3: append, which is what configure actually writes.
echo first > f3 2>/dev/null
ok=0
if exec 5>>f3 2>/dev/null; then
	echo second >&5 2>/dev/null && ok=1
	exec 5>&- 2>/dev/null
fi
got=$(cat f3 2>/dev/null | tr '\n' ' ')
ck "3 exec 5>>file APPENDS rather than truncating" \
   $([ "$ok" = 1 ] && [ "$got" = "first second " ] && echo 1 || echo 0) \
   "got [$got]"

# ---- 4: close and reopen the same NUMBER.
ok=0
exec 5>f4a 2>/dev/null && echo a >&5 2>/dev/null
exec 5>&- 2>/dev/null
if exec 5>f4b 2>/dev/null; then
	echo b >&5 2>/dev/null && ok=1
	exec 5>&- 2>/dev/null
fi
ga=$(cat f4a 2>/dev/null); gb=$(cat f4b 2>/dev/null)
ck "4 the same fd number reopened after a close" \
   $([ "$ok" = 1 ] && [ "$ga" = a ] && [ "$gb" = b ] && echo 1 || echo 0) \
   "got [$ga] [$gb]"

# ---- 5: read-write, run-redir's exact construct.
: > f5
ok=0
if exec 6<>f5 2>/dev/null; then
	echo rw >&6 2>/dev/null && ok=1
	exec 6>&- 2>/dev/null
fi
got=$(cat f5 2>/dev/null)
ck "5 exec 6<>file (redir.tests:83's own line)" \
   $([ "$ok" = 1 ] && [ "$got" = rw ] && echo 1 || echo 0) "got [$got]"

# ---- 6: a HIGH descriptor.  bash dups its own bookkeeping up here.
ok=0
if exec 200>f6 2>/dev/null; then
	echo high >&200 2>/dev/null && ok=1
	exec 200>&- 2>/dev/null
fi
got=$(cat f6 2>/dev/null)
ck "6 exec 200>file -- the fd TABLE rather than the redirection" \
   $([ "$ok" = 1 ] && [ "$got" = high ] && echo 1 || echo 0) "got [$got]"

# ---- 7: a CHILD writing to a descriptor the parent opened.
ok=0
if exec 5>f7 2>/dev/null; then
	( echo child >&5 ) 2>/dev/null && ok=1
	exec 5>&- 2>/dev/null
fi
got=$(cat f7 2>/dev/null)
ck "7 a subshell writes to the parent's exec'd descriptor" \
   $([ "$ok" = 1 ] && [ "$got" = child ] && echo 1 || echo 0) "got [$got]"

# ---- 8: a child that FORKS AND EXECS, rather than a subshell.
# Section 7 is a fork and nothing more; this one puts an EXEC on the
# path, and that is a different question here.  libap's `execve' writes
# every descriptor's state into `/env/_fdinfo' and the new image's
# `sfdinit' applies it -- which is where a descriptor has ALREADY
# arrived poisoned once in this tree (the FD_BUFFEREDX round).  So
# 7 passing and 8 failing would mean the exec boundary rather than the
# redirection.
ok=0
if exec 5>f8 2>/dev/null; then
	"${THIS_SH:-bash}" -c 'echo viaexec >&5' 2>/dev/null && ok=1
	exec 5>&- 2>/dev/null
fi
got=$(cat f8 2>/dev/null)
ck "8 a fork+EXEC'd child writes to the inherited fd 5" \
   $([ "$ok" = 1 ] && [ "$got" = viaexec ] && echo 1 || echo 0) "got [$got]"

# ---- 9: the shell RE-EXECS ITSELF and the new image writes fd 5.
# **This is autoconf's own first act.**  `configure' decides on a
# CONFIG_SHELL and then does `exec $CONFIG_SHELL "$as_myself" ...',
# replacing its own process image while `exec 5>>config.log' is
# supposed to stay open across it.  Section 8 is a child; this is the
# SAME process reaching the new image, which is the only arrangement
# `/env/_fdinfo' has to describe on its own.
cat > f9.sh <<'EOF'
echo reexec >&5
EOF
ok=0
if exec 5>f9 2>/dev/null; then
	( exec "${THIS_SH:-bash}" f9.sh ) 2>/dev/null && ok=1
	exec 5>&- 2>/dev/null
fi
got=$(cat f9 2>/dev/null)
ck "9 the shell re-execs itself and fd 5 survives (configure's own)" \
   $([ "$ok" = 1 ] && [ "$got" = reexec ] && echo 1 || echo 0) "got [$got]"

# ---- 10: SCALE.  Hold fd 5 open across many forks and keep writing.
# configure's failure arrives after thousands of lines, and the kernel's
# `process exceeds 100/200 file descriptors' warning sits two lines
# above the first `5: Bad file descriptor'.  **Every section above runs
# in a shell that has just started**, so none of them can see a
# descriptor that is lost after the table grows -- which is the one
# difference between this file and the run it was written for.
# It reports the ITERATION at which the write first failed rather than
# a bare pass, because "it broke at 140" and "it never worked" are
# different findings.
N=${EXECFD_ROUNDS:-300}
first_bad=0
i=0
if exec 5>f10 2>/dev/null; then
	while [ "$i" -lt "$N" ]; do
		i=$((i+1))
		/bin/true 2>/dev/null
		if ! echo "$i" >&5 2>/dev/null; then
			first_bad=$i
			break
		fi
	done
	exec 5>&- 2>/dev/null
fi
lines=$(wc -l < f10 2>/dev/null | tr -d ' ')
ck "10 fd 5 survives $N forks (first bad write: ${first_bad:-none})" \
   $([ "$first_bad" = 0 ] && [ "$lines" = "$N" ] && echo 1 || echo 0) \
   "wrote $lines of $N, first bad at $first_bad"

cd / 2>/dev/null
rm -rf "$D" 2>/dev/null

echo
echo "$failures failures"
if [ "$failures" != 0 ]; then
	echo "NOTE: autoconf keeps config.log on fd 5 and writes it with >&5."
	echo "      A failure in section 2 or 3 means every configure script"
	echo "      run under this tree has been logging to nothing, and that"
	echo "      its final verdict about the C compiler is downstream of"
	echo "      the descriptor rather than about the compiler."
fi
exit $failures
