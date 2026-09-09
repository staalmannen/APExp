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
note "--- 2. a child under the pointer ---"
frame .one.f1 -width 200 -height 200 -bg red
place .one.f1 -x 200 -y 200
update
settle
crossings
# The frame covers 300,300..500,500 in .one, i.e. screen 300..500 --
# the pointer at 350,350 is inside it, so mapping it must give an Enter.
note "  winfo containing 350 350 -> '[winfo containing 350 350]'"
note "  crossings from mapping a frame under the pointer: [crossings]"

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

puts "$fail failure(s)"
flush stdout
exit $fail
