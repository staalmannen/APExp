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
#   7  writing to the descriptor from a CHILD (a subshell), since libap's
#      exec rewrites `/env/_fdinfo' and that is where a descriptor has
#      arrived poisoned before
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
