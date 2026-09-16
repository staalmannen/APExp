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

puts "\n$failures failure(s)"
exit $failures
