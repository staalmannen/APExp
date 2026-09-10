# Run Tk's whole test suite, say where it got to, and then EXIT.
#
#	cd sys/src/external/tk/tests
#	wish $home/APExp/sys/lib/tests/tk-runall.tcl >/tmp/tk-all.out 2>&1
#
# To run part of it -- everything here is forwarded to tcltest, so its
# options work. This is how to bisect a hang:
#
#	wish .../tk-runall.tcl -file select.test
#	wish .../tk-runall.tcl -file {s*.test t*.test}
#
# ------------------------------------------------------------------
# WHY THIS EXISTS, in two parts, because they were confused once.
#
# 1. "wish all.tcl" never comes back even when it finishes. The end of
#    Tk's all.tcl is
#
#	if {[tcltest::runAllTests] && [info exists env(ERROR_ON_FAILURES)]} {
#	    exit 1
#	}
#
#    and that is its ONLY exit. Github CI sets that variable; nothing
#    else does. So the script falls off the end, and falling off the end
#    of a script is not how wish stops -- it enters Tk_MainLoop and sits
#    there. Under tclsh the same file exits, which is why upstream does
#    not notice.
#
# 2. The log lies about where the run stopped. stdout redirected to a
#    file is BLOCK buffered, so up to a bufferful of output is still in
#    memory whenever the process is killed or wedged -- and the last
#    file name you can see is therefore an upper bound on progress, not
#    the truth. That is why this script sets line buffering below. It
#    was NOT the reason the logs were short: with the exit in place the
#    run still wedged at the same point, which is what proves there is a
#    genuine hang rather than a formatting artefact.
#
#    Those two look identical from outside and want opposite next steps,
#    so the marker line at the bottom separates them:
#
#	tk-runall: runAllTests returned, N failed
#
#    Present  -> every file ran; anything wedged after it is in exit,
#                i.e. Tcl_Exit -> destroying the main window -> this
#                port's teardown. The leftover windows on screen point
#                the same way.
#    Absent   -> a test file hung, and with line buffering the LAST
#                NAME IN THE LOG is now genuinely where it stopped
#                rather than wherever the buffer happened to end.
#
# The leftover windows are a third thing, and not a mystery: all.tcl
# sets -singleproc 1, so all 97 files are sourced into one wish, and
# every toplevel a test forgets to destroy -- safe.test's "Untrusted Tcl
# applet" containers are the ones you can see -- stays up for the life
# of a process that never exits.

package require Tk
package require tcltest 2.2

# Line buffering, before anything is written. Without this the tail of
# the log is lost on any abnormal end, and the last file named is
# wherever the 4 KB boundary fell -- which is indistinguishable from
# where the suite actually stopped.
fconfigure stdout -buffering line
fconfigure stderr -buffering line
catch {fconfigure $::tcltest::outputChannel -buffering line}
catch {fconfigure $::tcltest::errorChannel -buffering line}

# A background error inside a binding reaches bgerror, and Tk's default
# bgerror puts up a MODAL dialog and waits for a click. Nothing in a
# test run will ever click it, so an unhandled error inside any binding
# stops the whole suite dead -- with the message only on screen, never
# in the log, and the CPU pinned by the dialog's own event loop. That is
# a hang whose cause is invisible from the log alone, which is exactly
# the trap this file spent several rounds inside.
#
# Log it instead. This is a deliberate change to how the suite behaves,
# so note the one place it could matter: bgerror.test tests bgerror
# itself, but each of its cases defines its own bgerror, which overrides
# this one for the duration -- so it is unaffected. Any BGERROR line
# below is a real background error that would otherwise have wedged the
# run.
proc ::bgerror {msg} {
    puts "BGERROR: $msg"
    if {[info exists ::errorInfo]} {
	puts "BGERROR-INFO: $::errorInfo"
    }
    flush stdout
}

puts "tk-runall: starting, line buffered, bgerror logged not dialogged"

# all.tcl reads $argv itself, so options given here reach tcltest.
source [file join [pwd] all.tcl]

# Reaching this line at all is the interesting part -- see above.
set failed 0
catch {set failed $::tcltest::numTests(Failed)}
puts "tk-runall: runAllTests returned, $failed failed"
flush stdout

exit [expr {$failed > 0 ? 1 : 0}]
