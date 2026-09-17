# Does a readable fileevent on a pipe ever fire?
#
#	tclsh $home/APExp/sys/lib/tests/tcl-fileevent-test.tcl
#
# WHERE THIS CAME FROM. With the loopback configured, Tcl's chanio.test
# runs sixty tests further than it used to and then stops again. Run in
# the harness's own process, which is the only way the buffering lets
# the last line mean anything,
#
#	tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t
#
# ends
#
#	---- chan-io-43.2 start
#	---- chan-io-44.1 start
#
# with nothing after it. chan-io-44.1 is
#
#	set f2 [open "|[list cat -u]" r+]
#	chan event $f2 readable {set x [chan gets $f2]; ...}
#	chan puts $f2 text; chan flush $f2
#	vwait x
#
# THE PIPE AND cat -u ARE BOTH KNOWN GOOD, which is what makes this
# narrow rather than open-ended. chan-io-29.26 opens the SAME
# bidirectional `cat -u` pipe, writes a line and reads it back -- and
# it passes. The one difference at 44.1 is that the read is driven by a
# READABLE FILEEVENT instead of a blocking `chan gets`.
#
# So the question this file asks is whether Tcl's notifier ever reports
# a pipe as readable here. Sockets are the control: chan-io-28.x fires
# fileevents on sockets and those tests start and return, so if section
# 3 below fires and section 2 does not, the notifier works and it is
# the PIPE that it never reports on.
#
# WHAT TO EXPECT, AND WHY THE ORDER MATTERS. Every section that should
# return comes before every section that might hang, and each prints a
# flushed marker BEFORE it runs -- so the last STEP: line names the
# statement that did not come back. Getting that order wrong wastes the
# whole run; it has cost a round trip once already (see the
# tk-mousewheel note in CLAUDE.md).
#
# Every section also has its own timeout, so this file REPORTS rather
# than hangs. That is the thing tcltest cannot do -- it has no timeout
# anywhere, which is why a single wedged test costs 155 files.
#
# This is correct on a Unix tclsh, which is how the expectations were
# checked; run it there first if a result here looks impossible.

fconfigure stdout -buffering line

set failures 0

proc step {msg} {
    puts "STEP: $msg"
    flush stdout
}

proc ok {cond what} {
    if {$cond} {
	puts "  PASS $what"
    } else {
	puts "  FAIL $what"
	incr ::failures
    }
    flush stdout
}

proc note {what} {
    puts "  note $what"
    flush stdout
}

# A flushed marker before a single STATEMENT, where `step` marks a whole
# section. Section 7c needs this: it stopped being a TIMEOUT and became
# a FREEZE, and a freeze means the process is blocked in a call rather
# than waiting in the event loop -- `waitfor`'s timer cannot fire if
# nothing reaches the loop. So the last `at:` line names the statement
# that did not return, which is the one thing the section could not say
# for itself.
proc at {what} {
    puts "    at: $what"
    flush stdout
}

# Wait for ::done to be set, but never longer than $ms. Returns the
# value, or the string TIMEOUT. THIS IS THE WHOLE REASON THE FILE CAN
# BE RUN AT ALL: the suite's version of each case below has no timeout.
proc waitfor {ms} {
    set ::done TIMEOUT
    set t [after $ms [list set ::done TIMEOUT]]
    vwait ::done
    after cancel $t
    return $::done
}

# Build a loopback pair whose peer has written and CLOSED FOR REAL --
# the accept waited for, the write and the close done here rather than
# from a script -- and return the client channel. select-test.c's
# closedpeer() in Tcl.
#
# THIS IS A CONTROL, NOT A CORRECTION, and the difference matters. The
# first version of this comment claimed sections 7b and 8 had the setup
# wrong, because they do
#
#	set srv [socket -server {... puts $ch foobar; close $ch}]
#	set cli [socket 127.0.0.1 $port]
#	close $srv			;# <- no event loop yet
#
# and an accept script only runs inside the event loop, so the handler
# never runs: nothing is written and nothing is closed. All true -- and
# **upstream's event-11.5 is written exactly that way**, `after 1000`
# and all, and expects `3 3 done`. So the suite really does require a
# client whose listener was closed with the connection never accepted
# to become readable, and 7b/8 were faithful reproductions after all.
#
# What that costs on X11 is worth knowing: the connection sits in the
# kernel's accept queue and closing the listener resets it, so the
# channel goes readable-with-error and every read answers at once. The
# test passes on the strength of an error, not of a conversation.
#
# So this proc is the OTHER case -- a peer that really did accept,
# write and close -- and the pair of them separates "a closed peer is
# never readable" from "a connection abandoned in the accept queue is
# never readable", which want completely different answers.
proc closedpeer {withdata} {
    set ::acc {}
    set srv [socket -server {apply {{ch a p} {set ::acc $ch}}} \
	-myaddr 127.0.0.1 0]
    set cli [socket 127.0.0.1 [lindex [fconfigure $srv -sockname] 2]]
    set t [after 2000 [list set ::acc TIMEOUT]]
    while {$::acc eq ""} { vwait ::acc }
    after cancel $t
    if {$::acc eq "TIMEOUT"} {
	catch {close $cli}
	catch {close $srv}
	return ""
    }
    if {$withdata} {
	fconfigure $::acc -buffering line
	puts $::acc foobar
	flush $::acc
    }
    close $::acc			;# THE PEER IS NOW GONE, for real
    close $srv
    return $cli
}

puts "--- 1. blocking read from a bidirectional pipe (chan-io-29.26) ---"
# The control, and it is known to PASS in the suite. If this fails,
# nothing below means anything -- the pipe itself is broken and the
# fileevent question does not arise.
step "1. open |cat -u, write a line, blocking gets"
if {[catch {
    set f [open "|[list cat -u]" r+]
    puts $f "Line1"
    flush $f
    set got [gets $f]
    catch {close $f}
} err]} {
    ok 0 "blocking round trip through cat -u ($err)"
} else {
    ok [expr {$got eq "Line1"}] "blocking round trip through cat -u (got '$got')"
}

puts "\n--- 2. the same pipe, driven by a READABLE FILEEVENT ---"
# chan-io-44.1, with a timeout bolted on. If section 1 passed and this
# times out, the notifier never reports this pipe as readable and that
# is the bug -- the data is demonstrably there, since section 1 read it
# off an identical pipe.
step "2. open |cat -u, write a line, wait for a readable event"
if {[catch {
    set f2 [open "|[list cat -u]" r+]
    fileevent $f2 readable [list apply {{ch} {
	set ::done [gets $ch]
	fileevent $ch readable {}
    }} $f2]
    puts $f2 text
    flush $f2
    set got [waitfor 3000]
    catch {close $f2}
} err]} {
    ok 0 "readable fileevent on a pipe ($err)"
} else {
    ok [expr {$got eq "text"}] "readable fileevent on a pipe fired (got '$got')"
    if {$got eq "TIMEOUT"} {
	note "no readable event in 3s. Section 1 read the same pipe by"
	note "blocking, so the data arrives and the NOTIFIER is what"
	note "never reports it. This is chan-io-44.1."
    }
}

puts "\n--- 3. a readable fileevent on a SOCKET (the control) ---"
# chan-io-28.x fires fileevents on sockets and those tests return, so
# this should pass. It is here to separate "the notifier is broken" from
# "the notifier does not watch pipes" -- two different bugs wanting two
# different fixes, and section 2 alone cannot tell them apart.
step "3. loopback socket pair, write a line, wait for a readable event"
if {[catch {
    set srv [socket -server {apply {{ch a p} {
	fconfigure $ch -buffering line
	set ::srvchan $ch
    }}} -myaddr 127.0.0.1 0]
    set port [lindex [fconfigure $srv -sockname] 2]
    set cli [socket 127.0.0.1 $port]
    fconfigure $cli -buffering line
    # let the server side accept
    set ::srvchan {}
    set t [after 2000 [list set ::srvchan TIMEOUT]]
    while {$::srvchan eq ""} { vwait ::srvchan }
    after cancel $t
} err]} {
    note "could not set up a loopback pair ($err)"
    note "if this says 'not a local IP address', the machine has no"
    note "loopback -- run socket-server-test first."
} elseif {$::srvchan eq "TIMEOUT"} {
    ok 0 "the server side accepted the connection"
} else {
    set s $::srvchan
    fileevent $s readable [list apply {{ch} {
	set ::done [gets $ch]
	fileevent $ch readable {}
    }} $s]
    puts $cli "hello"
    flush $cli
    set got [waitfor 3000]
    ok [expr {$got eq "hello"}] "readable fileevent on a socket fired (got '$got')"
    catch {close $cli}
    catch {close $s}
    catch {close $srv}
}

puts "\n--- 4. a readable fileevent on a plain FILE ---"
# A file is always readable, so every notifier reports it immediately
# and this is the cheapest possible case. If even this times out the
# fault is in the event loop itself rather than in any one channel type.
step "4. write a file, reopen it, wait for a readable event"
set tmp [file join [pwd] tcl-fileevent-test.tmp]
if {[catch {
    set w [open $tmp w]
    puts $w "filedata"
    close $w
    set r [open $tmp r]
    fileevent $r readable [list apply {{ch} {
	set ::done [gets $ch]
	fileevent $ch readable {}
    }} $r]
    set got [waitfor 3000]
    catch {close $r}
    file delete $tmp
} err]} {
    ok 0 "readable fileevent on a file ($err)"
} else {
    ok [expr {$got eq "filedata"}] "readable fileevent on a file fired (got '$got')"
}

puts "\n--- 5. NON-BLOCKING poll vs blocking wait ---"
# THE SECTION THE FIRST RUN DEMANDED. Sections 2-4 all PASS on 9front,
# so a readable fileevent on a pipe does fire and the chan-io-44.1
# diagnosis in the header above is refuted -- kept as written, because
# the reasoning that produced it is worth more than the conclusion.
#
# But event-1.1 in the suite fails with exactly the shape those
# sections were built to catch:
#
#	testfilehandler fillpartial 0 ; testfilehandler oneevent
#	got  {0 0} {0 0} {0 0}     want  {0 0} {1 0} {2 0}
#
# -- a handler on a pipe that never reports. The difference from
# section 2 is not the channel and not the pipe: it is HOW THE EVENT
# LOOP IS ENTERED. `testfilehandler oneevent` is
# Tcl_DoOneEvent(TCL_FILE_EVENTS|TCL_DONT_WAIT), a non-blocking poll,
# and section 2 uses `vwait`, which blocks.
#
# A notifier that only learns about readiness on the path where it is
# about to sleep answers a blocking wait correctly and a poll not at
# all. `update` is the Tcl-level DONT_WAIT, so these two lines ask the
# question without any test command.
#
# IF 5a FAILS AND 5b PASSES, that is the bug and it is one function.
# If both pass, the difference is somewhere in testfilehandler's own
# raw-fd path rather than in the notifier, and event.test is the place
# to look rather than here.
step "5a. write to a pipe, then poll with \[update\] (non-blocking)"
if {[catch {
    set f5 [open "|[list cat -u]" r+]
    set ::fired 0
    fileevent $f5 readable [list apply {{ch} {
	set ::fired 1
	set ::done [gets $ch]
	fileevent $ch readable {}
    }} $f5]
    puts $f5 poll
    flush $f5
    # give the child a moment to write it back, WITHOUT entering the
    # event loop -- after+vwait would be the blocking path again.
    after 500
    update
    set pollfired $::fired
    catch {close $f5}
} err]} {
    ok 0 "readable fileevent seen by update ($err)"
} else {
    ok [expr {$pollfired}] "a readable pipe is reported to a non-blocking poll"
    if {!$pollfired} {
	note "update did not see it. This is event-1.1's shape: the"
	note "notifier learns about readiness only where it blocks."
    }
}

step "5b. the same pipe, entered with \[vwait\] (blocking)"
if {[catch {
    set f6 [open "|[list cat -u]" r+]
    fileevent $f6 readable [list apply {{ch} {
	set ::done [gets $ch]
	fileevent $ch readable {}
    }} $f6]
    puts $f6 block
    flush $f6
    set got [waitfor 3000]
    catch {close $f6}
} err]} {
    ok 0 "readable fileevent seen by vwait ($err)"
} else {
    ok [expr {$got eq "block"}] "a readable pipe is reported to a blocking wait (got '$got')"
}

puts "\n--- 6. chan-io-44.1 exactly, two pipes and a namespace ---"
# Section 2 is 44.1 SIMPLIFIED, and it passes, so the difference is in
# what was simplified away. 44.1's -setup opens a SECOND pipe it never
# uses, and its variable is namespaced. Both are reproduced here rather
# than assumed irrelevant -- the same mistake as step 6 of
# tk-mousewheel-test.tcl, which differed from the hanging case in three
# ways at once and so settled nothing.
step "6. two |cat -u pipes, read one by fileevent"
if {[catch {
    namespace eval ::t441 {
	variable x initial
	variable f2 [open "|[list cat -u]" r+]
	variable f3 [open "|[list cat -u]" r+]
	chan event $f2 readable [namespace code {
	    variable x
	    variable f2
	    set x [chan gets $f2]
	    chan event $f2 readable {}
	    set ::done $x
	}]
	chan puts $f2 text
	chan flush $f2
    }
    set got [waitfor 3000]
    catch {chan close $::t441::f2}
    catch {chan close $::t441::f3}
} err]} {
    ok 0 "44.1 as written ($err)"
} else {
    ok [expr {$got eq "text"}] "44.1 as written fired (got '$got')"
    if {$got eq "TIMEOUT"} {
	note "so the SECOND pipe is the variable -- section 2 differs"
	note "from this only in opening one instead of two."
    }
}

puts "\n--- 7. WRITABLE, and readable at END OF FILE ---"
# THE HANG IS event-11.5, NOT event-1.1. `-singleproc 1 -verbose t`
# named it: event-1.1 fails and RETURNS, the file runs on through
# 3.1, 5.*, 6.1, 7.*, 8.1, 9.*, 10.1, 11.1, 11.3, 11.4, and stops at
#
#	---- event-11.5 start
#
# with nothing after it. So the 5a/5b sections above are still about a
# real failure -- event-1.1 -- but they are NOT about the hang, and
# saying otherwise would be the "a crash after test N is evidence about
# N" mistake from the Tk section in its other form.
#
# event-11.5 is round-robin scheduling across TWO sources:
#
#	fileevent $f1 writable {incr x; if {$y == 3} {set z done}}
#	fileevent $s2 readable {incr y; if {$x == 3} {set z done}}
#	vwait z
#
# and neither handler can end the wait on its own -- each tests the
# OTHER one's counter. So if either source never reports, `vwait z`
# never returns however busy the other one is. That is a hang with no
# error and no output, which is exactly what the log shows.
#
# Sections 2-4 already cover readable on a pipe, a socket and a file.
# The two things event-11.5 needs that nothing here has asked about are
# WRITABLE, and readable at END OF FILE -- the socket in the test has
# been closed by the server, so what makes it readable is the EOF and
# not data. Both are asked separately, because they fail separately.
step "7a. writable fileevent on a plain file"
if {[catch {
    set wtmp [file join [pwd] tcl-fileevent-test.w]
    set w7 [open $wtmp w]
    set ::done TIMEOUT
    fileevent $w7 writable [list apply {{ch} {
	fileevent $ch writable {}
	set ::done writable
    }} $w7]
    set got [waitfor 3000]
    catch {close $w7}
    file delete $wtmp
} err]} {
    ok 0 "writable fileevent on a file ($err)"
} else {
    ok [expr {$got eq "writable"}] "writable fileevent on a file fired"
    if {$got eq "TIMEOUT"} {
	note "a file open for writing is ALWAYS writable, so this is the"
	note "cheapest possible writable event and it never came. This"
	note "is half of event-11.5."
    }
}

step "7b. readable at END OF FILE, peer REALLY accepted and closed"
# THE CONTROL, AND IT RUNS FIRST NOW. It used to be 7c, after the
# upstream-shaped case -- and when that case stopped merely failing and
# began to FREEZE, the control never ran at all. **Every case expected
# to return must come before every case expected to hang**, which this
# file's own header says and which the ordering broke; one wasted run.
#
# select-test.c's closedpeer() does a blocking accept before writing
# and closing, and its sections 4, 5, 7 and 9 all pass on the VM. So if
# this passes and 7c does not, the fault is NOT "a closed peer is never
# readable" -- it is a connection ABANDONED IN THE ACCEPT QUEUE, which
# is a different thing and is what upstream's event-11.5 depends on.
#
# THE HANDLER HAS TO READ BEFORE ASKING [eof], and the first version of
# this did not. Tcl's `eof` reports whether a read has ALREADY hit the
# end, not whether the peer has gone -- so a handler that only asks
# `eof $ch` answers "data" both on the fire carrying the line and on the
# fire carrying the end of file. The host caught it, as it should.
if {[catch {
    set cli7b [closedpeer 1]
    if {$cli7b eq ""} {
	error "the server never accepted the connection"
    }
    set ::done TIMEOUT
    fileevent $cli7b readable [list apply {{ch} {
	gets $ch
	if {[eof $ch]} {
	    fileevent $ch readable {}
	    set ::done eof
	}
    }} $cli7b]
    set got [waitfor 3000]
    catch {close $cli7b}
} err]} {
    ok 0 "readable at EOF, peer accepted ($err)"
} else {
    ok [expr {$got eq "eof"}] "an accepted-and-closed peer reports readable (got '$got')"
}

step "7c. UPSTREAM'S SHAPE: the listener closed, never accepted"
# event-11.5's own setup, and **the case that now freezes rather than
# failing**. Before the listen() fix it reported TIMEOUT: the handler
# never fired, the event loop kept running, and `waitfor`'s timer ended
# the wait. Now nothing comes back at all -- so the process is blocked
# in a CALL, and the event loop is never reached for the timer to fire.
#
# A section cannot report which of its own statements blocked, so this
# one marks each with `at:` and the last one printed is the answer. That
# is tk-scrollbar-hang-test.tcl's technique, and it is the only thing
# that has ever settled a question of this shape here in one run.
#
# The suspects, in the order they are marked: the listener now exits
# when the parent closes the listening socket, so `close $srv7` is
# doing something it never did before; and the client now reaches a
# real end of file, so `gets` in the handler is running against a
# channel state it never saw. Both are new since the fix, and only one
# printed line separates them.
if {[catch {
    at "socket -server"
    set srv7 [socket -server {apply {{ch a p} {
	puts $ch foobar
	close $ch
    }}} -myaddr 127.0.0.1 0]
    at "socket 127.0.0.1 (connect)"
    set cli7 [socket 127.0.0.1 [lindex [fconfigure $srv7 -sockname] 2]]
    at "close \$srv7 (the listener)"
    close $srv7
    at "fileevent readable"
    set ::done TIMEOUT
    fileevent $cli7 readable [list apply {{ch} {
	at "handler: gets"
	gets $ch
	at "handler: eof?"
	if {[eof $ch]} {
	    fileevent $ch readable {}
	    set ::done eof
	}
    }} $cli7]
    at "waitfor"
    set got [waitfor 3000]
    at "close \$cli7"
    catch {close $cli7}
    at "done"
} err]} {
    ok 0 "readable at EOF, listener closed unaccepted ($err)"
} else {
    ok [expr {$got eq "eof"}] "an abandoned accept queue reports readable (got '$got')"
    if {$got eq "TIMEOUT"} {
	note "the handler never fired and the event loop kept running, so"
	note "this is a silent source rather than a blocked process -- the"
	note "shape it had BEFORE the listen() fix."
    }
}

puts "\n--- 8. event-11.5 itself, with a timeout ---"
# The whole test, reduced, with the one thing tcltest cannot give it.
# THE DECISIVE OUTPUT IS x AND y, not the pass or fail: each handler
# ends the wait only when the OTHER has reached 3, so whichever counter
# is stuck at 0 names the source that never reported. A pass needs
# both; a timeout with one of them climbing is a complete diagnosis.
step "8. two sources, round robin, neither can finish alone"
if {[catch {
    set t8 [file join [pwd] tcl-fileevent-test.rr]
    set f8 [open $t8 w]
    # UPSTREAM'S SHAPE, character for character -- including closing the
    # listener with the connection never accepted, which is what the
    # real event-11.5 does and what 7c exists to contrast.
    set srv8 [socket -server {apply {{ch a p} {
	puts $ch foobar
	close $ch
    }}} -myaddr 127.0.0.1 0]
    set s8 [socket 127.0.0.1 [lindex [fconfigure $srv8 -sockname] 2]]
    close $srv8
    set ::x 0
    set ::y 0
    set ::z 0
    fileevent $s8 readable {incr ::z}
    set tt [after 3000 [list set ::z TIMEOUT1]]
    vwait ::z
    after cancel $tt
    if {$::z eq "TIMEOUT1"} {
	note "the first vwait never saw the socket become readable at all"
    }
    set ::z 0
    fileevent $f8 writable {incr ::x; if {$::y == 3} {set ::z done}}
    fileevent $s8 readable {incr ::y; if {$::x == 3} {set ::z done}}
    set tt [after 3000 [list set ::z TIMEOUT]]
    vwait ::z
    after cancel $tt
    fileevent $f8 writable {}
    fileevent $s8 readable {}
    catch {close $f8}
    catch {close $s8}
    file delete $t8
} err]} {
    ok 0 "event-11.5 reduced ($err)"
} else {
    note "x (writable on the file) = $::x"
    note "y (readable on the socket) = $::y"
    ok [expr {$::z eq "done"}] "both sources were scheduled (z = '$::z')"
    if {$::z ne "done"} {
	if {$::x == 0} {
	    note "x never moved: the WRITABLE source is the starved one."
	} elseif {$::y == 0} {
	    note "y never moved: the socket READABLE source is starved,"
	    note "and section 7b says whether that is the EOF specifically."
	} else {
	    note "both moved but neither reached 3 in 3s -- that is a"
	    note "round-robin fairness problem rather than a dead source,"
	    note "and a different fix from either of the above."
	}
    }
}

puts "\n--- 9. chan-io-44.1 WITH DESCRIPTORS HELD OPEN UNDERNEATH ---"
# WHY THIS EXISTS. Section 6 is chan-io-44.1 character for character
# and it PASSES on the VM, and `-match 'chan-io-44.*'` runs 44.1..44.5
# with zero failures -- so the test is innocent and the variable is
# everything the process did before it. In the suite, forty-three
# sections of chanio.test have run first, several hundred channels have
# been opened and closed, and at least one leaked (41.8's cleanup says
# `can not find channel named "file5"`).
#
# THE FIRST THING TO SUSPECT IS THE DESCRIPTOR NUMBER, because there is
# a measured cliff at 96 and nothing in this file had ever crossed it.
# <sys/select.h> here is `struct fd_set { long fds_bits[3]; }` -- a
# hardcoded three words, 96 bits -- while <sys/limits.h> sets OPEN_MAX
# to 256. Descriptors 96..255 are ordinary descriptors that no fd_set
# in the system can name, and libap answers a select naming only those
# by sleeping out the timeout and returning 0 (FD_ANYSET reads words
# 0..2). See select-test.c section 11, and the CLAUDE.md section beside
# it.
#
# Tcl makes it worse rather than noticing: tclUnixPort.h says
# `#ifdef OPEN_MAX / #define FD_SETSIZE OPEN_MAX`, so Tcl believes an
# fd_set holds 256 and is handed one that holds 96. Its own FD_SET on a
# high descriptor writes past the end of the struct, so a CRASH here is
# as informative as a hang and neither is a surprise.
#
# So this is a RAMP rather than one shot: hold n descriptors open, run
# 44.1, report, release them, and climb. Each step prints before it
# runs, so if one of them never returns the last line names the
# threshold -- and a threshold at 96 is the fd_set and nothing else,
# while a smooth failure anywhere else says the descriptor number was
# the wrong suspect and the accumulation is something else.
#
# It is LAST in the file deliberately: everything above returns, and
# this is the only section written in the expectation that one of its
# cases may not. Every step passes on a Linux tclsh, where FD_SETSIZE
# is 1024 and the cliff is far above anything asked for here.
proc run441 {} {
    namespace eval ::ramp {
	variable x initial
	variable f2 [open "|[list cat -u]" r+]
	variable f3 [open "|[list cat -u]" r+]
	chan event $f2 readable [namespace code {
	    variable f2
	    set ::done [chan gets $f2]
	    chan event $f2 readable {}
	}]
	chan puts $f2 text
	chan flush $f2
    }
    set got [waitfor 3000]
    catch {chan close $::ramp::f2}
    catch {chan close $::ramp::f3}
    namespace delete ::ramp
    return $got
}

set holdpath [file join [pwd] tcl-fileevent-test.hold]
if {[catch {
    set h [open $holdpath w]
    puts $h "hold"
    close $h
} err]} {
    note "could not create $holdpath ($err); skipping the ramp"
} else {
    set held {}
    set prev 0
    # 0..104 ALL PASSED ON THE VM, and that did not clear the
    # descriptor number -- it only said the cliff is not at 96.
    # select-test.c section 11 reported `FD_SETSIZE 96, fd_set holds
    # 128` there: the width comes from stock APE's header in the
    # architecture directory and the constant from this tree, so the
    # struct really holds 128 and 104 was still inside it. The two
    # numbers that matter are therefore 96 -- where _buf.c's own
    # FD_ANYSET stops looking, hardcoded at three words -- and 128,
    # where the struct itself ends. The ramp straddles both.
    foreach n {0 40 80 88 92 96 104 120 126 130 140} {
	while {[llength $held] < $n} {
	    if {[catch {open $holdpath r} c]} {
		note "could only hold [llength $held] descriptors ($c)"
		break
	    }
	    lappend held $c
	}
	at "$n descriptors held, running 44.1"
	set got [run441]
	ok [expr {$got eq "text"}] "44.1 with $n held (got '$got')"
	if {$got ne "text"} {
	    note "IT BROKE BETWEEN $prev AND $n DESCRIPTORS HELD."
	    #
	    # A HELD COUNT IS NOT A DESCRIPTOR NUMBER, and the first
	    # version of this message compared it against 96 and 128 as
	    # though it were -- which read "neither 96 nor 128, so the
	    # descriptor number is the wrong suspect" off a break
	    # between 120 and 126, when that is exactly where the
	    # boundary is. Holding n descriptors puts the next ones at
	    # roughly n + 4 (stdin, stdout, stderr and the hold file),
	    # and 44.1 opens TWO |cat -u pipes, so it needs about four
	    # more on top. So the numbers to compare are the far end of
	    # that span, not the count.
	    #
	    set lo [expr {$prev + 4}]
	    set hi [expr {$n + 8}]
	    note "so the pipes it opened landed at about $lo..$hi."
	    if {$lo < 96 && $hi >= 96} {
		note "that straddles 96, where _buf.c's FD_ANYSET used"
		note "to stop looking -- three words wide by hand."
	    } elseif {$lo < 128 && $hi >= 128} {
		note "that straddles 128, where the fd_set STRUCT ended"
		note "before the widening: see select-test.c section 11."
	    } else {
		note "that is clear of both 96 and 128, so the"
		note "descriptor NUMBER is the wrong suspect and what"
		note "accumulates in chanio.test is something else."
	    }
	    break
	}
	set prev $n
    }
    foreach c $held { catch {close $c} }
    catch {file delete $holdpath}
}

puts "\n--- 10. THE SAME RAMP, BUT EACH HELD DESCRIPTOR IS BUFFERED ---"
# WHY SECTION 9 PASSING DOES NOT CLEAR THE ACCUMULATION. With the
# fd_set widened, section 9 passes EVERY step to 140 held -- and
# chan-io-44.1 still hangs in the suite. So the descriptor NUMBER was a
# real bug and is not this one, and the thing that accumulates over
# forty-three sections of chanio.test is something section 9 cannot
# reach.
#
# THE DIFFERENCE IS ONE WORD: section 9 HOLDS descriptors and never
# SELECTS on them. That matters here more than on any other system,
# because select() on Plan 9 is not a system call -- ap/plan9/_buf.c
# forks a COPY PROCESS per descriptor (`_startbuf`) which reads into a
# slot of a shared segment, and select answers from `b->n > 0 || b->eof`
# rather than from the kernel. So a descriptor that is merely open costs
# a number; a descriptor that has been named to select costs a Muxbuf
# slot (16 KB of shared segment), a process, and an entry in a table of
# OPEN_MAX slots that `_startbuf` linear-scans for a free one.
#
# Every channel chanio.test drives through a fileevent pays that, and
# nothing in section 9 pays it at all. This section pays it: each held
# channel is a |cat -u pipe with a readable fileevent registered and an
# `update` to make the notifier put it in a real select set, so libap
# buffers it and forks its copy process. Nothing is ever written to
# these pipes, so each copy process sits blocked in its first _READ --
# which is the steady state of an idle registered channel.
#
# WHAT EACH OUTCOME MEANS, written down before the run so the result
# cannot be read to taste:
#
#   every step passes  -> buffered descriptors are not the accumulation
#                         either, and the bisect (`-match 'chan-io-4*'`,
#                         then wider) is the way to name the range.
#                         That is a real result and ends this line.
#   a step breaks      -> the count where it breaks is the number of
#                         BUFFERED descriptors the process can carry,
#                         and _buf.c's slot table and copy processes are
#                         where to look. Note the count is not a
#                         descriptor number -- section 9 had to learn
#                         that the hard way -- so it is reported as
#                         itself and nothing is inferred from it.
#
# It is cheap to be wrong here and expensive to guess: this is one more
# section in a run that was happening anyway, and it is independent of
# the bisect, which should be run in the same round.
proc holdbuffered {} {
    # A pipe, registered and serviced once, so libap has really
    # buffered it. The handler is never expected to fire -- nothing is
    # written -- so it only has to exist.
    if {[catch {open "|[list cat -u]" r+} c]} {
	return ""
    }
    chan configure $c -blocking 0
    chan event $c readable [list apply {{ch} {
	catch {chan read $ch}
    }} $c]
    update
    return $c
}

set bheld {}
set bprev 0
set before10 $failures
foreach n {0 4 8 16 24 32 40} {
    set short 0
    while {[llength $bheld] < $n} {
	set c [holdbuffered]
	if {$c eq ""} {
	    note "could only buffer [llength $bheld] descriptors"
	    set short 1
	    break
	}
	lappend bheld $c
    }
    at "[llength $bheld] BUFFERED descriptors held, running 44.1"
    set got [run441]
    ok [expr {$got eq "text"}] "44.1 with [llength $bheld] buffered (got '$got')"
    if {$got ne "text"} {
	note "IT BROKE BETWEEN $bprev AND [llength $bheld] BUFFERED."
	note "that is a COUNT OF COPY PROCESSES AND MUXBUF SLOTS, not a"
	note "descriptor number -- do not compare it against 96 or 128."
	note "_buf.c's _startbuf slot table and _closebuf are where to"
	note "look, and select-test.c is where to reproduce it in C."
	break
    }
    set bprev [llength $bheld]
    if {$short} break
}
foreach c $bheld { catch {chan close $c} }
if {$failures == $before10} {
    note "every buffered step passed too, so the accumulation is"
    note "neither the descriptor number nor the buffered count, and"
    note "the bisect is what names it: -match 'chan-io-4*'."
}

puts "\n--- 11. chan-io-41.6 (A DIRECTORY) AND 41.8, THEN 44.1 ---"
# THE BISECT LANDED HERE. `-match 'chan-io-4.* chan-io-40.* chan-io-44.*'`
# runs 24 tests and finishes clean; `-match 'chan-io-41.* chan-io-44.*'`
# freezes at 44.1. So the whole accumulation is inside `chan-io-41.*`,
# eight tests, and five of those (41.1..41.5) are argument-error checks
# that open no channel at all. 41.7 is skipped here (`specialfiles`).
# That leaves TWO.
#
# **41.6 OPENS A DIRECTORY AND SELECTS ON IT.** That is a shape nothing
# in this port has ever been asked for: `_startbuf` forks a copy process
# that sits in `_READ` on a *directory* descriptor, which on Plan 9
# returns stat entries and then end of file.
#
# 41.8 is the `file link -symbolic` test. It fails with ENOSYS **before**
# `$chan` is assigned, so its cleanup closes 41.6's already-closed
# channel and reports `can not find channel named "file5"`. It therefore
# leaks nothing, and the cleanup error is a consequence of the ENOSYS
# rather than a second fault -- but it is cheap to ask about separately
# rather than assume, so it gets its own step.
#
# **"A PRIOR vwait IS ENOUGH" IS ALREADY REFUTED, AND BY THIS FILE.**
# That was the tempting reading -- the passing half (4.*, 40.*) contains
# no `vwait` at all, so 44.1's was the first blocking select in that
# process, while in the freezing half 41.6's came first. It cannot be
# that: sections 9 and 10 call `run441` eighteen times between them and
# every call passes, so 44.1 after a previous 44.1 demonstrably works.
# Worth writing down because it would have cost a run.
#
# Each statement carries an `at:` marker, because a freeze cannot say
# which line it is in and this is the section most likely to find one.
proc dirstep {} {
    set d [file join [pwd] tcl-fileevent-test.dir]
    at "file mkdir"
    file mkdir $d
    at "open the DIRECTORY"
    if {[catch {open $d} c]} {
	note "this system will not open a directory as a channel ($c)"
	catch {file delete -force $d}
	return skipped
    }
    at "chan event readable on the directory"
    chan event $c readable [list set ::done readable]
    at "waitfor"
    set got [waitfor 3000]
    at "close the directory channel"
    catch {chan close $c}
    catch {file delete -force $d}
    return $got
}

step "11a. run 44.1 with nothing before it (the control)"
set got [run441]
ok [expr {$got eq "text"}] "44.1 with nothing before it (got '$got')"

step "11b. 41.6: select on a DIRECTORY, then run 44.1"
set d [dirstep]
note "the directory reported '$d'"
at "44.1 after the directory"
set got [run441]
ok [expr {$got eq "text"}] "44.1 after a directory was selected on (got '$got')"

step "11c. 41.8: a failed symbolic link, then run 44.1"
at "file link -symbolic"
set tmpf [file join [pwd] tcl-fileevent-test.target]
set tmpl [file join [pwd] tcl-fileevent-test.link]
catch {set h [open $tmpf w]; puts $h "not again"; close $h}
if {[catch {file link -symbolic $tmpl $tmpf} err]} {
    note "file link -symbolic refused it: $err"
} else {
    note "file link -symbolic worked here"
}
catch {file delete -force $tmpl}
catch {file delete -force $tmpf}
at "44.1 after the symbolic link attempt"
set got [run441]
ok [expr {$got eq "text"}] "44.1 after a symlink attempt (got '$got')"

puts "\n--- 12. chan-io-41.7 (/dev/zero) THEN 44.1 ---"
# **41.7 IS THE ONE, AND I HAD WRITTEN IT OFF AS SKIPPED.** Section 11
# asked about 41.6 and 41.8 because those looked like the only two tests
# in `chan-io-41.*` that open anything -- and both pass, singly, while
# the group freezes. 41.7 was assumed skipped on its `specialfiles`
# constraint.
#
# The log said otherwise and it cost nothing to read: tcltest prints
# `---- NAME start` at tcltest.tcl:2070, AFTER the `Skipped` check
# returns at :2032, so a skipped test never prints it. `chan-io-40.9`
# proves the rule -- it is in the file, it is nonPortable here, and the
# passing run jumps 40.8 -> 40.10 with exactly one skip counted. In the
# freezing run **41.7 printed `start`**, so it ran, so `/dev/zero` was
# opened and selected on.
#
# WHY THAT ONE DESCRIPTOR IS DIFFERENT FROM EVERY OTHER IN THIS FILE.
# select() here is a copy process reading into a 16 KB `Muxbuf`, and
# every other source used above either ends (a directory, a file) or
# stays silent (a `|cat -u` pipe nobody writes to). **/dev/zero never
# ends and never pauses**, so its copy process fills the buffer faster
# than anything drains it, sets `roomwait = 1`, and blocks in
# `_RENDEZVOUS(&b->roomwait, 0)`. The test's `vwait` has long since
# fired on the first fill; `close $chan` then SIGKILLs the copy process
# exactly where it is waiting, and `_startbuf`'s slot reset did not
# clear `roomwait`. The next descriptor into that slot inherits a wait
# whose other half died before the slot was freed.
#
# So this section is 41.7 followed by 44.1, with `run441` as the control
# in front. The `after 200` is load-bearing rather than decoration: the
# copy process has to get from "first read delivered" to "buffer full,
# roomwait set" before the close, or the reproducer reproduces nothing.
#
# It is LAST because it is the only case here expected to freeze on an
# unfixed libap, and a freeze costs everything after it -- the rule this
# file has already paid for twice. On a fixed one it passes and the
# totals print as usual.
step "12a. run 44.1 with nothing before it (the control)"
set got [run441]
ok [expr {$got eq "text"}] "44.1 with nothing before it (got '$got')"

step "12b. 41.7: select on /dev/zero, let it FILL, close, then run 44.1"
set zero /dev/zero
if {![file exists $zero]} {
    note "no $zero here; nothing to ask"
} else {
    at "open $zero"
    if {[catch {open $zero} zc]} {
	note "could not open $zero ($zc); nothing to ask"
    } else {
	at "chan event readable on $zero"
	chan event $zc readable [list set ::done readable]
	at "waitfor (fires on the first fill)"
	set got [waitfor 3000]
	note "$zero reported '$got'"
	at "after 200 -- let the copy process fill the buffer and BLOCK"
	after 200
	at "close $zero"
	catch {chan close $zc}
	at "44.1 after /dev/zero was selected on and closed"
	set got [run441]
	ok [expr {$got eq "text"}] "44.1 after /dev/zero (got '$got')"
    }
}

puts "\n$failures failure(s)"
exit $failures
