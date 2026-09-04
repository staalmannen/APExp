# Run a Tk test file with progress marks, and catch whoever exits.
#
#	cd sys/src/external/tk/tests
#	wish ../../../../lib/tests/tk-runtest.tcl bell.test
#
# Run it from the tests directory: the test files locate their harness
# through [tcltest::configure -testdir], which defaults to the current
# directory.
#
# Why this exists. Every Tk test file exits with status 1 and produces
# no output at all -- not on stdout, not on stderr, with the two merged.
# It is not a Tcl error: an erroring script reports through
# TkpDisplayWarning, and that path is known good ("wish /tmp/e.tcl" with
# a bare error prints "Error in startup script: boom"). So something
# calls exit deliberately and says nothing.
#
# tcltest has four exits. Three are argument-parsing failures that print
# first; the fourth is at the end of cleanupTests --
#
#	# exit only if running Tk in non-interactive mode
#	if {[info exists ::tk_version] && ![testConstraint interactive]} {
#	    exit
#	}
#
# -- which is reached only after the per-file summary has been printed,
# and we never see a summary. So either cleanupTests is not reached, or
# something else exits first.
#
# Renaming exit catches all of them and reports the code, which is the
# one thing no amount of reading the harness will tell us.

proc mark {m} {
    puts "MARK $m"
    flush stdout
}

rename exit _real_exit
proc exit {{code 0}} {
    mark "exit called with code $code"
    if {[info exists ::errorInfo] && $::errorInfo ne ""} {
	mark "errorInfo at exit: $::errorInfo"
    }
    _real_exit $code
}

mark "start, parent is [info nameofexecutable]"

if {[llength $argv] < 1} {
    mark "usage: wish tk-runtest.tcl <testfile>"
    _real_exit 2
}
set testfile [lindex $argv 0]

# Clear argv before sourcing. "package require tcltest", which the test
# file does on its first line, parses ::argv as tcltest options -- so
# leaving the file name there makes tcltest report
#
#	missing value for option <path>
#
# and exit 1 (tcltest.tcl:1545), which is not what happens under a plain
# "wish bell.test", where argv is empty. Clearing it keeps this wrapper
# faithful to the real invocation.
set argv {}
set argc 0

mark "sourcing $testfile"

if {[catch {source $testfile} err]} {
    mark "source raised an error: $err"
    mark "errorInfo: $::errorInfo"
    _real_exit 1
}

mark "sourced cleanly"
mark "done"
_real_exit 0
