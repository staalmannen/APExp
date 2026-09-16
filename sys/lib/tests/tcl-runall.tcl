# Run Tcl's whole test suite, say where it got to, and then EXIT.
#
#	cd sys/src/external/tcl/tests
#	$home/APExp/sys/src/ape/cmd/tclsh/tcltest \
#		$home/APExp/sys/lib/tests/tcl-runall.tcl >/tmp/tcl-all.out >[2=1]
#
# Everything on the command line is forwarded to tcltest, so its own
# options work. That is how to look at one file:
#
#	... tcl-runall.tcl -file chanio.test
#	... tcl-runall.tcl -file chanio.test -verbose t
#
# and -verbose t prints each test name as it STARTS, which is what
# names a hang rather than guessing at it.
#
# ------------------------------------------------------------------
# WHY THIS EXISTS. The Tk suite had no completion marker for a long
# time and several rounds were spent reading logs that could not be
# read -- see tk-runall.tcl and the Tk section of CLAUDE.md. Tcl's
# suite had no harness at all, so every run so far has had the same
# problem and worse. The three states below look identical from the
# shell, because a fault, a kill and a clean finish all just give the
# prompt back:
#
#	marker present		every file ran
#	marker absent		the run stopped early -- and with line
#				buffering the LAST FILE NAME IN THE LOG is
#				now genuinely where it stopped, rather than
#				wherever the 4 KB buffer boundary fell
#
# ------------------------------------------------------------------
# HOW TCL'S SUITE DIFFERS FROM TK'S, because it changes what a truncated
# log means and this was nearly misread.
#
# Tcl's all.tcl leaves -singleproc at its default of 0, so tcltest runs
# EACH FILE IN ITS OWN PROCESS (tcltest.tcl:2940):
#
#	set cmd [linsert $childargv 0 | $shell $file]
#	set pipeFd [open $cmd "r"]
#	while {[gets $pipeFd line] >= 0} { ... }
#	close $pipeFd
#
# Two consequences, and they point opposite ways:
#
#  - A CHILD THAT DIES DOES NOT STOP THE RUN. close raises an error,
#    tcltest catches it, prints "Test file error: ..." and goes on to
#    the next file. That is exactly what binary.test does today:
#
#	binary.test
#	Test file error: tcltest 69507: Killed: Insufficient physical memory
#	brodnik.test
#
#    So the allocator's OOM costs ONE FILE'S measurement, not the run.
#    Worth stating plainly because CLAUDE.md's advice to "skip the files
#    that cannot fit in the VM" was written before anyone had read this
#    loop, and it assumed a kill was fatal to the whole suite.
#
#  - A CHILD THAT HANGS WEDGES THE PARENT FOREVER. The gets above is
#    blocking and there is no timeout anywhere in tcltest. The parent
#    sits in it with nothing more written to the log, which from outside
#    is indistinguishable from the parent itself hanging.
#
# The run on record stops in the middle of chanio.test with no summary
# and no further file names, which is the second shape. chanio.test is
# full of openpipe and blocking [chan gets] against a child "cat", and
# the chan-io-6.4x failures beside it report a blocking gets answering
# -1 where it should have returned a line -- so a gets that never
# returns is the thing to expect there. THAT IS A HYPOTHESIS, not a
# finding: run the file on its own with -verbose t and the log will
# name the test, the same way one line settled unixWm-50.5.
#
# ------------------------------------------------------------------
# THE SKIP LIST is the price of having no timeout. A file that wedges
# the parent costs every file after it -- alphabetically, chanio.test
# is twelfth of 167, so it costs 155 measurements. Skipping it buys
# those back. Each entry must say why it is here and what would take it
# out again, because a skip list nobody revisits is how a fixed bug
# stays "known broken" for a year.

set skipfiles {}

# chanio.test -- hangs the parent (see above). Take it out the moment
# the chan-io-6.4x cluster is understood; run it on its own meanwhile.
lappend skipfiles chanio.test

# ------------------------------------------------------------------
package require tcltest 2.5

# Line buffering, before anything is written. Without it the tail of
# the log is lost on any abnormal end and the last file named is an
# upper bound on progress rather than the truth.
fconfigure stdout -buffering line
fconfigure stderr -buffering line
catch {fconfigure $::tcltest::outputChannel -buffering line}
catch {fconfigure $::tcltest::errorChannel -buffering line}

# The marker. Under tclsh -- unlike wish -- tcltest::cleanupTests does
# NOT exit the application: that exit is guarded by
#
#	if {[info exists ::tk_version] && ![testConstraint interactive]}
#
# so "source all.tcl" here returns normally and the marker below it is
# reachable. ::exit is wrapped anyway, so that a file calling exit (and
# aaa_exit.test exists precisely to test exit) still leaves a marker
# rather than a silent stop that reads exactly like a crash.
rename ::exit ::tcl-runall-realexit

proc ::exit {{code 0}} {
    puts "tcl-runall: exit called (code $code)"
    flush stdout
    ::tcl-runall-realexit $code
}

# all.tcl reads $argv itself, so options given on OUR command line
# reach tcltest. Append the skips rather than replacing whatever the
# caller asked for.
if {[llength $skipfiles]} {
    lappend ::argv -skipfile $skipfiles
}

puts "tcl-runall: starting, line buffered, exit wrapped for the marker"
puts "tcl-runall: SKIPPING [llength $skipfiles] file(s) that wedge the\
 parent: $skipfiles"
puts "tcl-runall: note tcltest runs each file in its OWN process, so a\
 file that is KILLED costs only itself; a file that HANGS costs every\
 file after it"
flush stdout

set dir [file dirname [info script]]
set all [file join [pwd] all.tcl]
if {![file exists $all]} {
    puts "tcl-runall: no all.tcl in [pwd] -- run this from\
 sys/src/external/tcl/tests"
    ::tcl-runall-realexit 2
}

source $all

# Reached because tcltest does not exit for us under tclsh. Anything
# below this line is teardown.
puts "tcl-runall: every file ran, now entering exit (code 0)"
puts "tcl-runall: anything below this line is Tcl_Exit teardown"
flush stdout
exit 0
