# Why does building the Motif file dialog kill wish at the end of the
# Tk suite, and does it need the other 96 files to have run first?
#
#	wish tk-xmfbox-crash-test.tcl
#
# WHERE THIS COMES FROM. The full 97-file run ends:
#
#	==== xmfbox-2.6 FAILED
#	wish 7597: suicide: sys: trap: general protection violation
#	                                pc=0x26f694
#
# and pc=0x26f694 is generic/tkGeometry.c:153, Tk_GeometryRequest,
# faulting on the pointer chase through a garbage geomMgrPtr -- a
# use-after-free of a TkWindow. (APE's malloc never unmaps a freed
# block, so a wild pointer here shows at the first DOUBLE indirection,
# not the first access. See CLAUDE.md.)
#
# TWO FACTS THAT TOGETHER SAY WHERE TO LOOK.
#
# 1. The fault is inside xmfbox.test, not in exit. tk-runall.tcl now
#    wraps ::exit and prints a marker before the real one; the marker
#    is ABSENT, and so is runAllTests' own "Tests ended at" line, which
#    it prints before cleanupTests. So wish died between the last test
#    reporting and the file's own trailing "cleanup; cleanupTests".
#
#    (Do not read the marker's absence as "the suite did not finish" --
#    that was the old, unreachable marker. This one is reachable.)
#
# 2. xmfbox-2.6 itself fails with something impossible:
#
#	bad window path name ".foo.top"
#	    while executing
#	"pack $w.top -side top -expand yes -fill both"
#
#    library/xmfbox.tcl builds the dialog like this:
#
#	329  toplevel $w -class TkMotifFDialog
#	330  set top [frame $w.top -relief raised -bd 1]
#	331  set bot [frame $w.bot -relief raised -bd 1]
#	333  pack $w.bot -side bottom -fill x
#	334> pack $w.top -side top -expand yes -fill both
#
#    .foo.top is created at 330 and gone at 334. Line 331 and line 333
#    are all that happen in between. A window does not leave the name
#    table on its own, so either something destroyed it or the tree it
#    is in is already damaged -- and a damaged tree is what the fault
#    two lines later says as well.
#
# THE QUESTION THIS FILE ASKS, and it is the one the two half-runs
# raised: "wish tk-runall.tcl -file {[a-m]*.test}" and "{[n-z]*.test}"
# BOTH ran to completion, and the second includes xmfbox.test. So
# xmfbox alone is not enough; something accumulated over the other 50
# files is needed too. What accumulates?
#
#	all.tcl sets -singleproc 1, so all 97 files are sourced into
#	ONE wish, and every toplevel a test forgets to destroy stays
#	up for the life of the process.
#
# The first suspect is therefore simply the NUMBER OF LIVE WINDOWS,
# because this port has a fixed-size window table:
#
#	tkPlan9Int.h:  #define TKP9_MAX_WINDOWS 2048
#
# and until now XCreateWindow answered None when it filled up -- which
# every caller above it reads as "no window", never as "no room". A
# frame that exists to Tk and not to this port is exactly the shape of
# ".foo.top is gone".
#
# So the port now PANICS on exhaustion rather than answering None, and
# prints one line per 256 slots as occupancy climbs:
#
#	tkp9: window table 256/2048 in use
#
# Those lines are unconditional, not under $TKP9DEBUG -- the debug flag
# turns on a torrent of drawing traces, and a number that only appears
# beside them is a number nobody reads.
#
# WHAT THIS FILE DOES. Build the dialog with a growing number of live
# toplevels underneath it, and report at each step. Three outcomes,
# wanting three different next steps:
#
#	fails at every count, even 0   -> nothing to do with accumulation;
#	                                  it is xmfbox or this port's
#	                                  toplevel handling, and the
#	                                  suite is a red herring
#	fails only past some count     -> accumulation, and the count is
#	                                  the measurement to take to the
#	                                  window table
#	never fails here               -> it is not window COUNT; the
#	                                  suite leaves something else
#	                                  behind (a grab, a focus, a
#	                                  stale geometry manager)
#
# THE ANSWER WAS THE TABLE, AND THIS FILE SAID OTHERWISE ONCE. Read
# that before trusting a run of it.
#
# On its first run it took the third outcome -- the dialog built at
# every count up to 361 live windows and the table reported only
# 256/2048 -- and the window table was written off. It was the table.
# The very next full suite run printed
#
#	tkp9: window table 2048/2048 in use
#	tkp9: window table full (2048 entries); ...
#
# in xmfbox.test, the exact file that had been crashing.
#
# TWO REASONS THAT FIRST RUN MISLED, and both are worth keeping:
#
#  1. It ran on a build that was itself broken. The same commit that
#     added the occupancy counter moved fields in the middle of
#     P9DisplayState, and mk rebuilt only one of the seven files in
#     plan9/ (see the HFILES note in CLAUDE.md). A measurement taken
#     from a build you have just broken measures the breakage. NEVER
#     draw a negative conclusion from the same run that shows an
#     unexplained regression elsewhere.
#
#  2. "countwins" below is TK's count, not the port's. Section 2 says
#     "1 window before, 1 after" and that is true and irrelevant: Tk
#     had freed its TkWindows, and the P9Window slots behind them had
#     leaked. The two numbers are only equal when nothing leaks, which
#     is precisely the thing under test. The stderr lines are the
#     port's own count, and they are the ones to read.
#
# THE LEAK, now fixed: generic/tkWindow.c:1584 skipped XDestroyWindow
# for a child whose parent was going away, because on X the server
# destroys the subtree implicitly. Nothing here does, and
# XDestroyWindow is the only thing that frees a P9Window slot -- so
# every child of every destroyed toplevel leaked one. PLAN9 is in that
# condition now, beside MAC_OSX_TK and _WIN32, for the same reason it
# is in SendEnterLeaveForDestroy's: there is no X server.
#
# ORDER: cheap and expected-to-pass cases first, then the ramp, because
# a failure here may kill wish rather than raise an error. Each step
# prints a flushed marker BEFORE it runs, so the last STEP line names
# the statement that did not return. That rule is in CLAUDE.md because
# ignoring it has cost whole round trips.

proc step {m} { puts "STEP: $m"; flush stdout }
proc ok   {m} { puts "   ok: $m"; flush stdout }
proc bad  {m} { puts " FAIL: $m"; flush stdout }

# Count every window Tk knows about, so "how many are live" is a number
# in the log rather than a guess. winfo children walks the whole tree.
proc countwins {{w .}} {
    set n 1
    foreach c [winfo children $w] { incr n [countwins $c] }
    return $n
}

# Exactly what xmfbox.tcl's MotifFDialog_BuildUI does for the first six
# lines -- the ones that failed -- with a check after each. Written out
# rather than calling tk::MotifFDialog_Create so that a failure names
# the line, and so this runs without the test suite's machinery.
proc buildui {w} {
    toplevel $w -class TkMotifFDialog
    frame $w.top -relief raised -bd 1
    frame $w.bot -relief raised -bd 1

    set missing {}
    foreach c [list $w.top $w.bot] {
	if {![winfo exists $c]} { lappend missing $c }
    }
    if {[llength $missing]} {
	return "gone right after creation: $missing"
    }

    if {[catch {pack $w.bot -side bottom -fill x} err]} {
	return "pack \$w.bot failed: $err"
    }
    # THE LINE THAT FAILS IN THE SUITE.
    if {![winfo exists $w.top]} {
	return "\$w.top vanished during 'pack \$w.bot' -- the suite's failure"
    }
    if {[catch {pack $w.top -side top -expand yes -fill both} err]} {
	return "pack \$w.top failed: $err"
    }
    return ""
}

step "0. how many windows exist in a bare wish"
ok "[countwins] windows"

step "1. build the dialog with nothing else up -- if THIS fails, the\
 97-file suite is a red herring and the bug is here"
catch {destroy .foo}
set why [buildui .foo]
if {$why eq ""} {
    ok "built; [countwins] windows now"
} else {
    bad "$why"
    puts ""
    puts "It fails with no accumulation at all. Stop reading the suite:"
    puts "reproduce from here."
    flush stdout
    exit 1
}
destroy .foo

step "2. build and destroy it twenty times -- a leak in the port's\
 window table would show as the count not returning to where it started"
set before [countwins]
for {set i 0} {$i < 20} {incr i} {
    catch {destroy .foo}
    set why [buildui .foo]
    if {$why ne ""} { bad "iteration $i: $why"; break }
    destroy .foo
}
set after [countwins]
if {$after == $before} {
    ok "$before windows before, $after after -- Tk's own count is clean"
} else {
    bad "$before before, $after after -- Tk is leaking windows too"
}

# ------------------------------------------------------------------
# The ramp. Each round leaves a toplevel with a few children up, the way
# a test file that forgets to destroy its windows does, and then tries
# the dialog again. If the port's window table is the thing running out,
# there is a count at which this stops working -- and the
# "tkp9: window table N/2048 in use" lines on stderr say how close it
# got, whether or not it fails.
#
# 40 rounds x 8 children is 360 or so windows, which is the order the
# suite leaves behind. Going much past that is the table's job to
# report, not this file's.
step "3. the ramp: leave live toplevels up, retry the dialog after each"

set failedat -1
for {set round 1} {$round <= 40} {incr round} {
    toplevel .leak$round
    for {set j 0} {$j < 8} {incr j} {
	pack [frame .leak$round.f$j -width 20 -height 10]
    }
    update

    catch {destroy .foo}
    set why [buildui .foo]
    if {$why ne ""} {
	bad "round $round ([countwins] windows live): $why"
	set failedat $round
	break
    }
    destroy .foo

    if {$round % 10 == 0} {
	ok "round $round: [countwins] windows live, dialog still builds"
    }
}

puts ""
if {$failedat < 0} {
    puts "reached the end -- the dialog built at every count, up to\
 [countwins] live windows."
    puts "So it is NOT the number of windows. The suite leaves something"
    puts "else behind; look at what survives a test file rather than at"
    puts "the window table."
} else {
    puts "broke at round $failedat, [countwins] live windows."
    puts "That is a count, so take it to the window table:"
    puts "the 'tkp9: window table N/2048 in use' lines above say whether"
    puts "the table was anywhere near full when it happened."
}
flush stdout
exit 0
