# Run Tk's whole test suite and then EXIT.
#
#	cd sys/src/external/tk/tests
#	wish $home/APExp/sys/lib/tests/tk-runall.tcl >/tmp/tk-all.out 2>&1
#
# WHY THIS EXISTS. "wish all.tcl" never comes back, and the log it
# leaves is short. Both are the same one line -- the end of Tk's
# all.tcl:
#
#	if {[tcltest::runAllTests] && [info exists env(ERROR_ON_FAILURES)]} {
#	    exit 1
#	}
#
# That is the ONLY exit in the file. With ERROR_ON_FAILURES unset --
# Github CI sets it, nothing else does -- the script simply falls off
# the end, and falling off the end of a script is not how wish stops:
# it enters Tk_MainLoop and sits in the event loop forever. Under tclsh
# the same file exits, which is why nobody upstream notices.
#
# The consequence that actually costs you: stdout redirected to a file
# is BLOCK buffered, and a process that never exits never flushes. So
# the tail of the run -- the last few file names, and the summary with
# the totals -- is still sitting in a stdio buffer when you give up and
# kill it. Every tk-all.out collected this way stops mid-suite at
# whatever the last 4 KB boundary was, and "the suite got this far"
# reads that truncation as a hang. It is not a hang.
#
# The leftover windows are the same thing. Tk's all.tcl sets
#
#	tcltest::configure -singleproc 1
#
# so all 97 files are sourced into ONE wish rather than run as separate
# processes. Any toplevel a test file forgets to destroy -- safe.test's
# "Untrusted Tcl applet" containers are the visible ones -- stays on
# screen for the life of that process, which is forever.
#
# exit flushes, so with this wrapper the log ends with tcltest's own
# summary. If the log still stops short of that, THEN it really is a
# hang and the last file named is where to look.
#
# The zero-effort alternative, while the suite still has failures:
#
#	ERROR_ON_FAILURES=1 wish all.tcl >/tmp/tk-all.out 2>&1
#
# which takes the exit branch above -- but only when something failed,
# so it stops working on the day the suite comes out clean.

package require Tk
package require tcltest 2.2

# all.tcl reads $argv itself, so anything passed here is forwarded.
source [file join [pwd] all.tcl]

# runAllTests has returned, so every file has been sourced. Exit with
# the number of failures, as the C tests in this directory do, and let
# exit flush stdout.
set failed 0
catch {set failed $::tcltest::numTests(Failed)}
puts "tk-runall: $failed failed"
exit [expr {$failed > 0 ? 1 : 0}]
