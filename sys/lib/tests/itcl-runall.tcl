# Run itcl's whole test suite, say where it got to, and then EXIT.
#
#	cd sys/src/external/itcl/tests
#	$home/APExp/$objtype/bin/itclsh \
#		$home/APExp/sys/lib/tests/itcl-runall.tcl >/tmp/itcl-all.out >[2=1]
#
# Everything on the command line is forwarded to tcltest, so its own
# options work -- one file, or one file with every test name printed as
# it STARTS, which is what names a hang rather than guessing at it:
#
#	... itcl-runall.tcl -file inherit.test
#	... itcl-runall.tcl -singleproc 1 -file inherit.test -verbose t
#
# IT MUST BE itclsh AND NOT tclsh. Plan 9 has no dlopen, so `package
# require Itcl' cannot load anything; itcl is compiled into itclsh and
# registered with Tcl_StaticLibrary (sys/src/ape/cmd/itclsh). Under a
# plain tclsh every file here fails at its first line, which looks like
# a catastrophic port failure and is nothing of the kind.
#
# ------------------------------------------------------------------
# This is tcl-runall.tcl with the same four load-bearing pieces and
# none of the history; read that file for why each one is here, since
# every one of them cost a round on the Tcl or Tk suite:
#
#   1. LINE BUFFERING ON STDOUT ONLY. Without it the tail of the log is
#      lost on any abnormal end. Not stderr: it is unbuffered already,
#      which orders a log better, and setting it is what made four of
#      Tcl's io-14.x fail -- the instrument reporting itself.
#   2. THE SAME IN EVERY CHILD, through -load. tcltest leaves
#      -singleproc at 0, so each file runs in its own process whose
#      stdout is a PIPE and block buffered; without this the last test
#      named in the log is a LOWER BOUND on where a hang happened.
#   3. ::exit WRAPPED, so a file that calls exit still leaves a marker
#      instead of a silent stop that reads exactly like a crash.
#   4. A COMPLETION MARKER, because a fault, a kill and a clean finish
#      all just give the shell prompt back.
#
# And the reading rule that goes with the marker: it says the run
# reached the end, not that it was the run you asked for. Read the
# Total line beside it.
#
# ------------------------------------------------------------------
# ONE ITCL-SPECIFIC TRAP, WORTH KNOWING BEFORE IT BITES. itcl's own
# all.tcl may add -loadfile:
#
#	if {[namespace which -command memory] ne "" && "-loadfile" ni $argv} {
#	    lappend argv -loadfile [file join [file dirname [info script]] helpers.tcl]
#	}
#
# and its own comment says "-loadfile overwrites -load". So IF that
# fires, the child buffering in (2) is silently dropped and trap (2) is
# back. It only fires when the `memory' command exists, which is a
# TCL_MEM_DEBUG build and is not this one -- but that is a property of
# how Tcl was compiled, not a guarantee, so the harness checks and says
# so rather than assuming.

package require tcltest 2.5

# (1) stdout only. See the note above.
fconfigure stdout -buffering line
catch {fconfigure $::tcltest::outputChannel -buffering line}

# (2) and the same in every child. tcltest passes every non-default
# option through to the child and evaluates -load there before running
# anything, so this is its own mechanism rather than a trick. APPEND if
# -load is ever wanted for its real purpose, or the buffering goes and
# the trap comes back silently.
if {[::tcltest::configure -load] eq ""} {
    ::tcltest::configure -load {
	catch {fconfigure stdout -buffering line}
	catch {fconfigure $::tcltest::outputChannel -buffering line}
    }
}

# (3) so that a file calling exit still leaves a marker.
rename ::exit ::itcl-runall-realexit

proc ::exit {{code 0}} {
    puts "itcl-runall: exit called (code $code)"
    flush stdout
    ::itcl-runall-realexit $code
}

#
# Say what interpreter this is and whether Itcl is actually here,
# BEFORE running anything. A suite that fails every test because the
# package is missing and one that fails every test because the port is
# broken produce the same count; this is the line that tells them
# apart, and it costs nothing.
#
puts "itcl-runall: [info nameofexecutable]"
if {[catch {package require Itcl} itclver]} {
    puts "itcl-runall: package require Itcl FAILED: $itclver"
    puts "itcl-runall: run this under itclsh, not tclsh -- Plan 9 has no"
    puts "itcl-runall: dlopen, so Itcl is compiled in rather than loaded."
    puts "itcl-runall: every test below would fail for that reason alone."
} else {
    puts "itcl-runall: Itcl $itclver, Tcl [info patchlevel]"
}
if {[namespace which -command memory] ne ""} {
    puts "itcl-runall: NOTE the `memory' command exists, so all.tcl will"
    puts "itcl-runall: add -loadfile, which OVERWRITES the -load above and"
    puts "itcl-runall: drops child line buffering. The last test named in"
    puts "itcl-runall: this log is then a LOWER BOUND, not the answer."
}
puts "itcl-runall: starting, line buffered, exit wrapped for the marker"
flush stdout

set all [file join [pwd] all.tcl]
if {![file exists $all]} {
    puts "itcl-runall: no all.tcl in [pwd] -- run this from\
 sys/src/external/itcl/tests"
    ::itcl-runall-realexit 2
}

source $all

# (4) Reached because tcltest::cleanupTests does not exit for us
# outside wish. Anything below this line is teardown.
puts "itcl-runall: every file ran, now entering exit (code 0)"
puts "itcl-runall: anything below this line is Tcl_Exit teardown"
flush stdout
exit 0
