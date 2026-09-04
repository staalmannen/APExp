# Can a running wish spawn a second wish and talk to it over a pipe?
#
#	wish   tk-childproc-test.tcl [child-interpreter] [repeats]
#	tclsh  tk-childproc-test.tcl [child-interpreter] [repeats]
#
# The child defaults to whatever is running the script, so
#
#	wish  tk-childproc-test.tcl		wish parent,  wish child
#	tclsh tk-childproc-test.tcl		tclsh parent, tclsh child
#	tclsh tk-childproc-test.tcl /bin/wish	tclsh parent, wish child
#	wish  tk-childproc-test.tcl /bin/tclsh	wish parent,  tclsh child
#
# and a repeat count spawns that many children in turn, reporting how
# many answered:
#
#	wish tk-childproc-test.tcl /bin/wish 20
#
# This is Tk's own childTkProcess (tests/testutils.tcl:382) reduced to
# its essentials. constraints.tcl:42 calls it, main.tcl sources
# constraints.tcl, and every Tk test file sources main.tcl -- so if this
# cannot work, no Tk test file runs at all, whatever the tests
# themselves would do.
#
# What is known so far. Each side works alone: tclsh->wish and
# wish->tclsh both answer correctly, as does tclsh->tclsh. Only
# wish->wish misbehaves, and it is **intermittent** -- one run timed out
# with the child alive and silent, a later identical run answered
# correctly. So this is a race between two graphical processes, not a
# resource that is simply unavailable.
#
# tkp9_open (tk/plan9/tkPlan9DrawImpl.c:64) takes three things that
# belong to one rio window: initdraw's window image, /dev/mouse, and
# /dev/cons for the keyboard. Two wish processes in the same window
# contend for all three, which is the leading explanation -- but a race
# is what wants measuring, so count rather than sample.
#
# Every step flushes, so the last MARK printed is where it stopped even
# if the process dies without a word.

proc mark {msg} {
    puts "MARK $msg"
    flush stdout
}

# One round: spawn a child, ask it to say foo, wait up to 15s.
# Returns ok, wrong, eof, timeout, openfail or writefail.
proc oneround {child} {
    global state reply fd

    set state waiting
    set reply ""

    if {[catch {set fd [open "|[list $child -name tkchild]" r+]} err]} {
	mark "open failed: $err"
	return openfail
    }

    fconfigure $fd -blocking 0
    fileevent $fd readable {
	if {[gets $fd line] >= 0} {
	    set reply $line
	    set state got
	} elseif {[eof $fd]} {
	    set state eof
	}
    }

    if {[catch {puts $fd "puts foo; flush stdout"; flush $fd} err]} {
	mark "write to child failed: $err"
	catch {close $fd}
	return writefail
    }

    set timer [after 15000 {if {$state eq "waiting"} {set state timeout}}]
    vwait state
    after cancel $timer

    catch {puts $fd exit}
    catch {close $fd}

    switch -- $state {
	got     { if {$reply eq "foo"} { return ok } else { return wrong } }
	eof     { return eof }
	default { return timeout }
    }
}

mark "parent start"
mark "parent is [info nameofexecutable]"

set child [info nameofexecutable]
if {[llength $argv] > 0} {
    set child [lindex $argv 0]
}
set reps 1
if {[llength $argv] > 1} {
    set reps [lindex $argv 1]
}
mark "child will be $child, $reps round(s)"

foreach r {ok wrong eof timeout openfail writefail} {
    set tally($r) 0
}

for {set i 1} {$i <= $reps} {incr i} {
    set result [oneround $child]
    incr tally($result)
    mark "round $i: $result"
}

puts ""
puts "child=$child rounds=$reps"
foreach r {ok wrong eof timeout openfail writefail} {
    if {$tally($r) > 0} {
	puts "  $r: $tally($r)"
    }
}
flush stdout

exit [expr {$tally(ok) == $reps ? 0 : 1}]
