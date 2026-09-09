# Does an Enter arrive when the pointer's window changes?
#
#	wish tk-enter-test.tcl
#
# The ten event-9.* failures are all this, and they all report the same
# way -- the suite's own helper gives up after a second:
#
#	wait for <Enter> event on .one timed out (> 1000 ms)
#
# That helper is setup_win_mousepointer in tests/event.test, which is
# the first line of every event-9 case:
#
#	toplevel $w; wm geometry $w 300x300+100+100
#	event generate $w <Motion> -warp 1 -x 250 -y 250
#	waitForWindowEvent $w <Enter>
#
# so the whole family is blocked in its setup and none of them reaches
# the thing it was written to test.
#
# The warp itself is known good -- tk-warp-test.tcl shows the pointer
# landing on the exact screen coordinate asked for -- so what is left is
# the crossing. On X the server sends Enter/Leave; here nothing will, and
# tkPointer.c has to be driven: TkP9UpdatePointer hands the position and
# the window under it (Tk_CoordsToWindow) to Tk_UpdatePointer, which
# compares against its own lastWinPtr and calls TkInOutEvents.
#
# Two failures look identical from Tcl and are not the same bug:
#
#   - no Enter at all: either Tk_UpdatePointer is not being called, or
#     it is called with the window it already believes the pointer is in
#     (winPtr == lastWinPtr, so GenerateEnterLeave returns without
#     queueing anything);
#   - an Enter on the wrong window: Tk_CoordsToWindow disagrees with
#     "winfo containing", i.e. the hit test is wrong.
#
# So this reports which window each Enter actually names, and asks
# "winfo containing" separately, rather than only whether one arrived.
#
# WHAT IT FOUND, first run:
#
#	pointer now at 350 350  (want 350 350)
#	winfo containing -> ''  (want .one)
#	crossings:
#
# The warp is exact and the hit test finds nothing at a point plainly
# inside .one -- so Tk_CoordsToWindow returned NULL, TkP9UpdatePointer
# handed NULL to Tk_UpdatePointer, and no crossing could be generated.
# Behind that: Tk_GetRootCoords walked the parent chain past the
# toplevel, and a toplevel's parentPtr is its logical Tk parent, so
# .one's position had .'s added to it. setup_win_mousepointer moves .
# to +700+400 first, which is what made it fatal rather than merely
# wrong. Hence the "where" proc below -- one line of geometry would
# have pinned this without the round trip that found it.
#
# With Tk_GetRootCoords fixed, all four sections pass:
#
#	.: rootx,rooty 700,400 size 200x200 mapped 1
#	.one: rootx,rooty 100,100 size 300x300 mapped 1
#	pointer now at 350 350; winfo containing -> '.one'
#	crossings: {Enter .one NotifyAncestor}
#	...
#	crossings after destroying .two:
#	    {Enter .one NotifyVirtual} {Enter .one.f1 NotifyAncestor}
#
# -- the hit test agrees with the warp at every level, and the detail
# fields are the ones event-9.* expects.
#
# DO NOT TOUCH THE MOUSE while this runs.

set fail 0

proc note {m} { puts $m; flush stdout }

# The condition is a braced expression, evaluated in the caller's scope:
# "if {$cond}" on a braced argument gets the string, not a boolean, and
# fails with "expected boolean value but got a list".
proc ok {cond what} {
    global fail
    if {[uplevel 1 [list expr $cond]]} {
	note "  PASS $what"
    } else {
	note "  FAIL $what"
	incr fail
    }
}

# Where does Tk think a window is, and how big? Tk_GetRootCoords is the
# thing behind "winfo rootx", and getting it wrong takes winfo
# containing and the whole pointer machinery with it, so print it for
# anything whose position matters.
proc where {w} {
    note "  $w: rootx,rooty [winfo rootx $w],[winfo rooty $w]\
 size [winfo width $w]x[winfo height $w]\
 mapped [winfo ismapped $w]"
}

# Collect every crossing, with the window and the detail field, the way
# event-9.* checks them.
set ::crossings {}
bind all <Enter> {lappend ::crossings "Enter %W %d"}
bind all <Leave> {lappend ::crossings "Leave %W %d"}

proc settle {{ms 300}} {
    after $ms {set ::_settled 1}
    vwait ::_settled
    update
}

proc crossings {} {
    set c $::crossings
    set ::crossings {}
    return $c
}

# Keep . out of the way, as event.test does.
wm geometry . +700+400
settle

note "--- 1. warp into a toplevel: does it get <Enter>? ---"
note "  (this is setup_win_mousepointer, the first line of every event-9)"
toplevel .one
pack propagate .one 0
wm geometry .one 300x300+100+100
tkwait visibility .one
update
crossings

where .
where .one
event generate .one <Motion> -warp 1 -x 250 -y 250
settle
set c [crossings]
note "  pointer now at [winfo pointerxy .]  (want 350 350)"
note "  winfo containing -> '[winfo containing 350 350]'  (want .one)"
note "  crossings: $c"
ok {[winfo pointerxy .] eq {350 350}} "the warp landed on .one"
ok {[winfo containing 350 350] eq ".one"} "winfo containing says .one"
ok {[lsearch -glob $c "Enter .one *"] >= 0} "<Enter> arrived on .one"

note ""
note "--- 2. a child mapped under a stationary pointer ---"
# The frame covers 200,200..400,400 within .one, i.e. screen 300..500
# clipped to .one's 400 -- the pointer at 350,350 is inside it. An X
# server generates the crossing unasked; here gP9.pointerDirty makes the
# next poll re-report the same position so tkPointer.c can.
#
# Clear the log BEFORE the thing being measured. Reading it with
# "[crossings]" after having called "crossings" to clear reports the
# buffer that call just emptied, which is how this section first printed
# an empty result that looked like a missing crossing.
crossings
frame .one.f1 -width 200 -height 200 -bg red
place .one.f1 -x 200 -y 200
update
settle
set c [crossings]
note "  winfo containing 350 350 -> '[winfo containing 350 350]'"
note "  crossings from mapping a frame under the pointer: $c"
ok {[lsearch -glob $c "Enter .one.f1 *"] >= 0} \
    "a child mapped under the pointer gives an <Enter>"

note ""
note "--- 3. destroy the window under the pointer (event-9.1's shape) ---"
toplevel .two
wm geometry .two 200x200+300+300
update idletasks
wm deiconify .two
update idletasks
raise .two
settle
event generate .two <Motion> -warp 1 -x 50 -y 50
settle
note "  pointer at [winfo pointerxy .] (want 350 350), containing '[winfo containing 350 350]'"
crossings
destroy .two
update idletasks
settle
set c [crossings]
note "  crossings after destroying .two: $c"
ok {[lsearch -glob $c "Enter *"] >= 0} "destroying the window under the pointer gives an <Enter>"

note ""
note "--- 4. does a plain motion between windows cross? ---"
# No warp: drive TkP9UpdatePointer through the ordinary path by warping
# to two different windows in turn and watching the pair of events.
crossings
event generate .one <Motion> -warp 1 -x 10 -y 10
settle
set c [crossings]
note "  moving to .one (10,10): $c"

destroy .one
catch {destroy .two}
settle

note ""
note "--- 5. destroy a nested FRAME under the pointer (event-9.11's shape) ---"
# Section 3 destroys a TOPLEVEL and passes; event-9.1 is that case and it
# passes in the suite too. event-9.11/9.12/9.17 destroy a nested FRAME
# and report NO CROSSING AT ALL -- the result is the bare "|" separator,
# not a wrong %d detail:
#
#	---- Result was:                 |
#	---- Result should have been:    |<Enter> NotifyInferior .one.f1|
#
# so the interesting question is which of the two inputs to
# GenerateEnterLeave is wrong. It generates nothing when the window it is
# handed EQUALS the one it already believes the pointer is in, and
# TkPointerDeadWindow has just set that to NULL (TkGetContainer of a
# non-embedded window is NULL) -- so "nothing at all" is what you get
# when Tk_CoordsToWindow also answers NULL.
#
# Hence: print the hit test on both sides of the destroy, and the
# crossings separately. It is NOT a generic Tk bug -- this tree's
# tkPointer.c is byte-identical to upstream's apart from int/bool.
#
# The geometry is event.test's create_and_pack_frames, copied exactly,
# because it is load-bearing: .f1 is 200x200 anchored SE inside .one's
# 300x300, so screen (200,200)-(400,400), and .f2 is 100x100 anchored SE
# inside that, so screen (300,300)-(400,400). The warp to 250,250 in
# .one is screen 350,350, which is inside both.
wm geometry . +700+400
toplevel .one
pack propagate .one 0
wm geometry .one 300x300+100+100
tkwait visibility .one
update
frame .one.f1 -bg blue -width 200 -height 200
pack propagate .one.f1 0
frame .one.f1.f2 -bg yellow -width 100 -height 100
pack .one.f1.f2 .one.f1 -side bottom -anchor se
update idletasks
event generate .one <Motion> -warp 1 -x 250 -y 250
settle

where .one
where .one.f1
where .one.f1.f2
note "  pointer at [winfo pointerxy .] (want 350 350)"
note "  containing 350 350 -> '[winfo containing 350 350]' (want .one.f1.f2)"
ok {[winfo containing 350 350] eq ".one.f1.f2"} \
    "the pointer starts in the innermost frame"

crossings
destroy .one.f1.f2
update
settle
set c [crossings]
note "  containing 350 350 after destroy -> '[winfo containing 350 350]'\
 (want .one.f1)"
note "  crossings: $c"
ok {[winfo containing 350 350] eq ".one.f1"} \
    "the hit test finds the parent frame once the child is gone"
ok {[lsearch -glob $c "Enter .one.f1 *"] >= 0} \
    "<Enter> arrives on the parent frame"
ok {[lsearch -glob $c "Enter .one.f1 NotifyInferior"] >= 0} \
    "and its detail is NotifyInferior"

note ""
note "  now the second step, which is event-9.17:"
crossings
destroy .one.f1
update
settle
set c [crossings]
note "  containing 350 350 -> '[winfo containing 350 350]' (want .one)"
note "  crossings: $c"
ok {[lsearch -glob $c "Enter .one NotifyInferior"] >= 0} \
    "<Enter> NotifyInferior arrives on .one"

destroy .one

puts "$fail failure(s)"
flush stdout
exit $fail
