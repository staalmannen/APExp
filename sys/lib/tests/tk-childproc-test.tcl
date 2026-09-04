# Can a running wish spawn a second wish and talk to it over a pipe?
#
#	wish   tk-childproc-test.tcl [child-interpreter]
#	tclsh  tk-childproc-test.tcl [child-interpreter]
#
# The child defaults to whatever is running the script, so
#
#	wish  tk-childproc-test.tcl		wish parent,  wish child
#	tclsh tk-childproc-test.tcl		tclsh parent, tclsh child
#	tclsh tk-childproc-test.tcl /bin/wish	tclsh parent, wish child
#	wish  tk-childproc-test.tcl /bin/tclsh	wish parent,  tclsh child
#
# which is what separates "the child wish cannot start when spawned from
# a Tcl pipe" from "the child wish cannot start while another wish holds
# the rio window".
#
# This is Tk's own childTkProcess (tests/testutils.tcl:382) reduced to
# its essentials. constraints.tcl:42 calls it, main.tcl sources
# constraints.tcl, and every Tk test file sources main.tcl -- so if this
# cannot work, no Tk test file runs at all, whatever the tests
# themselves would do.
#
# The symptom being chased: every Tk test file exits with status 1 and
# produces no output whatsoever, not even on stderr. A parent that dies
# of SIGPIPE writing to a child that has already gone would look exactly
# like that, since SIGPIPE's default action terminates without a
# message.
#
# Already ruled out, by running these from the shell:
#
#	wish -name tktest2 < /tmp/c.tcl	     -> prints foo, status 0
#	printf ... | wish -name tktest2	     -> prints foo, status 0
#
# so a second wish reading a script from a pipe is fine on its own. What
# is untested, and what this covers, is doing it while a parent wish is
# already running and holding the rio window.
#
# Every step flushes, so the last MARK printed is where it stopped even
# if the process dies without a word.

proc mark {msg} {
    puts "MARK $msg"
    flush stdout
}

mark "parent start"
mark "parent is [info nameofexecutable]"

# Which interpreter to spawn. Defaults to our own, as childTkProcess does.
set child [info nameofexecutable]
if {[llength $argv] > 0} {
    set child [lindex $argv 0]
}
mark "child will be $child"

# Same shape as childTkProcess create, minus the unique-appname counter.
if {[catch {
    set fd [open "|[list $child -name tkchild]" r+]
} err]} {
    mark "open failed: $err"
    exit 1
}
mark "opened"

# Non-blocking with a timeout, so a child that never answers reports
# rather than hanging the test.
fconfigure $fd -blocking 0

set ::state waiting
set ::reply ""

proc onreadable {f} {
    if {[gets $f line] >= 0} {
	set ::reply $line
	set ::state got
    } elseif {[eof $f]} {
	set ::state eof
    }
}
fileevent $fd readable [list onreadable $fd]

if {[catch {
    puts $fd "puts foo; flush stdout"
    flush $fd
} err]} {
    mark "write to child failed: $err"
    exit 1
}
mark "wrote"

after 15000 {if {$::state eq "waiting"} {set ::state timeout}}
vwait ::state

switch -- $::state {
    got {
	if {$::reply eq "foo"} {
	    mark "child said: \"$::reply\" -- CORRECT"
	} else {
	    mark "child said: \"$::reply\" -- WRONG, expected \"foo\""
	}
    }
    eof     { mark "child closed the pipe without replying" }
    timeout { mark "child never replied (15s timeout)" }
}

catch {puts $fd exit}
catch {close $fd}
mark "done"
exit 0
