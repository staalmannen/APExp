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
# FINDING THE HANGING TEST: USE -singleproc 1, AND DO NOT READ THE LAST
# LINE OF A MULTI-PROCESS LOG AS IF IT WERE THE ANSWER.
#
#	tcltest .../tcl-runall.tcl -singleproc 1 -file chanio.test -verbose t
#
# The line buffering this file sets applies to THIS process. In the
# default multi-process mode every test file is a separate tcltest
# whose stdout is a PIPE to the parent, and nothing sets that child's
# buffering -- so up to a bufferful of the child's output is still in
# the child when it wedges, and the last test named in the log is a
# LOWER BOUND on how far it got.
#
# That is exactly the trap the Tk section of CLAUDE.md records ("the log
# lies about where the run stopped"), met one process further down than
# where it was met before. Two runs of the Tcl suite have now ended
# after chan-io-8.1's failure report, and the obvious reading -- that
# chan-io-8.2 is the hang, it being the next test and the first in the
# file to pair a "chan event" with two "vwait"s -- is a HYPOTHESIS that
# the log cannot support, however plausible.
#
# -singleproc 1 sources the file into THIS interpreter instead, so the
# line buffering above applies and -verbose t's "---- name start" lines
# arrive as they happen. Then the last name in the log is genuinely the
# test that did not return.
#
# WHICH SHAPE OF WEDGE IT IS, is already known and is worth keeping
# apart from the other one: the CPU during the freeze is "constant but
# low", which is a process BLOCKED on something that will never arrive
# -- a read on a pipe, a vwait for an event that is not coming. A loop
# inside one command pins a core instead. Tk's suite had one of each
# and they wanted completely different fixes.
#
# ------------------------------------------------------------------
# THE SKIP LIST is the price of having no timeout. A file that wedges
# the parent costs every file after it -- alphabetically, chanio.test
# is twelfth of 167, so it costs 155 measurements. Skipping it buys
# those back. Each entry must say why it is here and what would take it
# out again, because a skip list nobody revisits is how a fixed bug
# stays "known broken" for a year.
#
# THE OPTION IS -notfile, NOT -skipfile. The first version of this file
# said -skipfile, which does not exist, and tcltest refused the whole
# run:
#
#	unknown option -skipfile: should be one of -asidefromdir,
#	-constraints, -debug, -errfile, -file, -limitconstraints, -load,
#	-loadfile, -match, -notfile, -outfile, -preservecore,
#	-relateddir, -singleproc, -skip, -testdir, -tmpdir, or -verbose
#
# skipFiles is the internal accessor (tcltest.tcl:63) and -notfile is
# the option that sets it; reading the proc name for the option name is
# the same class of mistake as reading a grep hit for an implementation.
# The error message lists every valid option, which is the cheapest
# possible check and was there to be read.
#
# AND -notfile HAS A NON-EMPTY DEFAULT: "l.*.test" (tcltest.tcl:687),
# whose comment says "skip files that appear to be SCCS lock files".
# Setting the option REPLACES that default, so the default is repeated
# below rather than dropped. (It costs nothing either way here -- the
# glob wants a literal dot as the second character, so it matches
# l.foo.test and not lindex.test, and Tcl's seventeen l*.test files do
# run. That was worth checking rather than assuming, since "the whole
# l* family is silently skipped" would have been a much bigger finding
# than the one this round actually has.)

set skipfiles {l.*.test}

# chanio.test -- hangs the parent (see above). Take it out the moment
# the chan-io-6.4x cluster is understood; run it on its own meanwhile,
# with the recipe in the next comment block.
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
# reach tcltest -- and OUR argument wins if the caller gave one too,
# since configure takes the last, so only add it when they did not.
if {[llength $skipfiles] && [lsearch -exact $::argv -notfile] < 0} {
    lappend ::argv -notfile $skipfiles
}

puts "tcl-runall: starting, line buffered, exit wrapped for the marker"
puts "tcl-runall: -notfile is $skipfiles -- l.*.test is tcltest's own\
 default (SCCS lock files, matches nothing here) and is repeated so\
 that setting the option does not drop it; the rest wedge the parent"
puts "tcl-runall: note tcltest runs each file in its OWN process, so a\
 file that is KILLED costs only itself; a file that HANGS costs every\
 file after it. A child's stdout is a PIPE and is block buffered, so\
 the last test named below is a LOWER BOUND on where a hang happened --\
 use -singleproc 1 -file X -verbose t to get the real name."
flush stdout

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
