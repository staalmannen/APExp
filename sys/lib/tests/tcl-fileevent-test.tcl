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

step "7b. readable fileevent at END OF FILE (peer closed)"
if {[catch {
    #
    # UPSTREAM'S SHAPE, deliberately: event-11.5 closes the listener
    # with the connection never accepted, so this does too. Section 7c
    # below is the same question with a peer that really accepted.
    #
    set srv7 [socket -server {apply {{ch a p} {
	puts $ch foobar
	close $ch
    }}} -myaddr 127.0.0.1 0]
    set cli7 [socket 127.0.0.1 [lindex [fconfigure $srv7 -sockname] 2]]
    close $srv7
    #
    # THE HANDLER HAS TO READ BEFORE ASKING [eof], and the first version
    # of this section did not. Tcl's `eof` reports whether a read has
    # ALREADY hit the end, not whether the peer has gone -- so a handler
    # that only asks `eof $ch` answers "data" on the fire that delivers
    # the line AND on the fire that delivers the end of file, and the
    # section failed with 'data' against a channel behaving perfectly.
    # The host caught it, as the convention says it should.
    #
    # So this drains and stays registered: the line arrives on one fire,
    # the EOF on the next, which is select-test.c section 7 in Tcl.
    set ::done TIMEOUT
    fileevent $cli7 readable [list apply {{ch} {
	gets $ch
	if {[eof $ch]} {
	    fileevent $ch readable {}
	    set ::done eof
	}
    }} $cli7]
    set got [waitfor 3000]
    catch {close $cli7}
} err]} {
    ok 0 "readable at EOF ($err)"
} else {
    ok [expr {$got eq "eof"}] "a closed peer reports readable (got '$got')"
    if {$got eq "TIMEOUT"} {
	note "the listener closed with the connection never accepted, and"
	note "the notifier never said so. Section 7c is the same question"
	note "with a peer that really did accept, write and close."
    }
}

step "7c. the same, but the peer REALLY accepted and closed"
# THE CONTROL 7b NEEDS, and the one C has been measuring all along:
# select-test.c's closedpeer() does a blocking accept before writing
# and closing, and sections 4, 5, 7 and 9 all pass on the VM. So if 7c
# passes here and 7b does not, the fault is NOT "a closed peer is never
# readable" -- it is a connection ABANDONED IN THE ACCEPT QUEUE, which
# is a different thing and is what upstream's event-11.5 depends on.
if {[catch {
    set cli7c [closedpeer 1]
    if {$cli7c eq ""} {
	error "the server never accepted the connection"
    }
    set ::done TIMEOUT
    fileevent $cli7c readable [list apply {{ch} {
	gets $ch
	if {[eof $ch]} {
	    fileevent $ch readable {}
	    set ::done eof
	}
    }} $cli7c]
    set got [waitfor 3000]
    catch {close $cli7c}
} err]} {
    ok 0 "readable at EOF, peer accepted ($err)"
} else {
    ok [expr {$got eq "eof"}] "an accepted-and-closed peer reports readable (got '$got')"
    if {$got eq "eof"} {
	note "so a real closed peer IS reported, and 7b's case is the"
	note "abandoned accept queue rather than the close."
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

puts "\n$failures failure(s)"
exit $failures
