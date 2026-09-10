# Which text-widget scroll makes the redisplay never finish?
#
#	wish tk-textscroll-hang-test.tcl
#
# This is what tk-mousewheel-test.tcl narrowed down to, extracted so it
# can be asked in seconds instead of after four hundred lines of
# already-answered probes. The whole bug is four lines:
#
#	pack [text .t -yscrollcommand {.s set}] -side left
#	pack [scrollbar .s -command {.t yview}] -fill y -expand 1 -side left
#	.t yview scroll 20 units
#	update idletasks		<- never returns
#
# HOW WE GOT HERE, because every one of these was a suspect and each is
# now excluded by an experiment rather than by argument:
#
#   tk::ScrollByUnits		called directly with the binding's exact
#				arguments, twelve times over: returns.
#   event delivery		a wheel event with a trivial binding runs
#				it exactly once and returns.
#   the <MouseWheel> binding	a bare "yview scroll" binding hangs the
#				same way, so the library proc is out.
#   -yscrollcommand		hangs with the two widgets not wired.
#   pack order / geometry	hangs in build's own arrangement, .t at
#				0,0 486x246 and mapped.
#   the event loop		the SCROLL returns; the update after it is
#				what hangs. Nothing need be delivered.
#   Expose regeneration		"update idletasks" alone hangs, and that
#				runs idle handlers only. So the loop is
#				inside the redisplay, not around it.
#
# WHAT IS LEFT is DisplayText in tkTextDisp.c -- either one call that
# never returns, or an idle handler that re-posts itself forever -- and
# the question this file asks is which scrolls reach that state.
#
# Known before this file was written:
#
#	moveto 1.0		index 77 (the end)	ok
#	moveto 0.5		index 51		ok
#	scroll 100 units	index 77 (clamped)	ok
#	scroll 20 units		index 21		HANGS
#	scroll 3 units		index 4			HANGS
#
# which looks like a distance rule and is not one: moveto 0.5 lands in
# the middle of the file and survives. Those two rows differ in the
# COMMAND as well as the position, so the cases below reach the same
# top index by both routes. That is the whole design of this file, and
# it exists because reading two-things-at-once as one thing has now
# gone wrong four times on this bug.
#
#	"yview scroll N units" -> YScrollByLines, which walks display
#	    lines with LayoutDLine
#	"yview moveto f"       -> no walk
#	"yview scroll N pixels", "yview <index>" -> other routes again
#
# If scroll-to-51 hangs where moveto-to-51 survived, it is the command
# and the walk. If it survives, it is the position and both commands
# are innocent.
#
# ORDER MATTERS: a hang has to be killed by hand, so every case
# expected to return comes before every case expected to hang, and each
# prints a flushed marker BEFORE it runs. Whatever the last STEP line
# says is the statement that did not return.

proc step {msg} { puts "STEP: $msg"; flush stdout }
proc done {msg} { puts "   ok: $msg"; flush stdout }

# One arrangement throughout, and it is build's: text packed first,
# wired to the scrollbar. Rebuilt for every case so nothing carries
# over -- a stale display state would be indistinguishable from the bug.
proc pair {{nlines 100}} {
    destroy .t .s
    pack [text .t -yscrollcommand {.s set}] -side left
    pack [scrollbar .s -command {.t yview}] -fill y -expand 1 -side left
    for {set i 1} {$i < $nlines} {incr i} {.t insert end "Line $i\n"}
    update
}

# Every case is the same three moves: scroll, then the redisplay alone,
# then the redisplay plus events. Splitting the last two is what said
# the loop was inside the redisplay, so keep them apart.
proc try {tag what script} {
    step "$tag. $what"
    pair
    uplevel 1 $script
    done "the scroll itself returned; top index is [.t index @0,0]"

    step "$tag. ... update idletasks (redisplay ONLY)"
    update idletasks
    done "update idletasks returned"

    step "$tag. ... update (redisplay AND events)"
    update
    done "update returned"
}

# ------------------------------------------------------------------
# THE ANSWER, found by case 3 below plus one grep.
#
# "moveto 0.2" reaches index 21 and hangs; "moveto 0.5" reaches 51 and
# does not. Same command, so the display-line walk this file was built
# to accuse is innocent -- it is the POSITION, or rather the distance.
#
# unix/tkUnixDraw.c's TkScrollWindow, which this port builds, issues the
# XCopyArea and then waits for the X server to say how much of it
# succeeded:
#
#	while (!info.done) {
#	    Tcl_ServiceEvent(TCL_WINDOW_EVENTS);
#	}
#
# info.done is set ONLY by a NoExpose or the last GraphicsExpose for
# that window, and neither event name appears anywhere in plan9/. So
# the loop has no exit: an infinite loop inside one Tk call, which is
# precisely "update idletasks never returns, CPU pinned, nothing
# written". win/tkWinDraw.c and macosx/tkMacOSXImage.c define
# TkScrollWindow themselves for this reason; plan9/tkPlan9Draw.c now
# does too.
#
# WHY ONLY SHORT SCROLLS. tkTextDisp.c copies only when the old and new
# views overlap, and repaints outright when they do not -- so only the
# copying path reaches TkScrollWindow at all. The widget here shows
# about 24 lines ("moveto 1.0" reports a top index of 77 of 100), so:
#
#	moveto 1.0	 76 lines	no overlap	ok
#	moveto 0.5	 50 lines	no overlap	ok
#	moveto 0.2	 20 lines	OVERLAP		hung
#	scroll 20 units	 20 lines	OVERLAP		hung
#	scroll 3 units	  3 lines	OVERLAP		hung
#
# The overlap theory was dropped one round earlier on the strength of a
# guess that ~15 lines were visible. It is 24. Measure the widget.
#
# WITH THE FIX IN, every case below returns and the file runs to the
# end. It is kept as the regression test: case 10 is the wheel scroll
# scrollbar-10.1 actually performs.

puts "--- visible lines, since the whole rule turns on this ---"
pair
puts "   .t is [winfo height .t]px tall, top index [.t index @0,0],\
 bottom index [.t index @0,[expr {[winfo height .t]-1}]]"
flush stdout

puts ""
puts "--- cases expected to return ---"
flush stdout

try 1 "yview moveto 1.0 -- to the very end"            {.t yview moveto 1.0}
try 2 "yview moveto 0.5 -- to the middle, index 51"    {.t yview moveto 0.5}
try 3 "yview moveto 0.2 -- index ~21, which is where\
 'scroll 20 units' hangs.  SAME PLACE, OTHER COMMAND"  {.t yview moveto 0.2}
try 4 "yview scroll 100 units -- clamps to the end"    {.t yview scroll 100 units}

step "5. yview scroll 300 pixels -- lands near index 21 with NO display\
 line walk, so this separates the walk from the destination"
pair
if {[catch {.t yview scroll 300 pixels} err]} {
    done "not supported on this Tk: $err"
} else {
    done "the scroll itself returned; top index is [.t index @0,0]"
    step "5. ... update idletasks"
    update idletasks
    done "update idletasks returned"
}

step "6. the old 'yview <index>' form to line 21 -- another route to\
 the same place"
pair
if {[catch {.t yview 20} err]} {
    done "not supported on this Tk: $err"
} else {
    done "the scroll itself returned; top index is [.t index @0,0]"
    step "6. ... update idletasks"
    update idletasks
    done "update idletasks returned"
}

# A window that cannot scroll at all. If this hangs, the trigger is not
# scrolling but merely asking to scroll, which would move the search
# from what DisplayText copies to what it is asked for. Built by hand
# because try's pair always makes 99 lines.
step "7. yview scroll 20 units on a text of THREE lines -- there is\
 nothing to scroll, so the request is a no-op"
pair 4
.t yview scroll 20 units
done "the scroll itself returned; top index is [.t index @0,0]"
step "7. ... update idletasks"
update idletasks
done "update idletasks returned"

puts ""
puts "--- the sharp one, and then the known hangs ---"
flush stdout

try 8 "yview scroll 50 units -- index 51, the SAME place case 2 reached\
 by moveto and survived.  Hanging here means the COMMAND\
 (YScrollByLines and its display-line walk); surviving means the\
 POSITION and both commands are innocent" {.t yview scroll 50 units}

try 9 "yview scroll 20 units -- the known hang" {.t yview scroll 20 units}
try 10 "yview scroll 3 units -- the smallest known hang, and what the\
 <MouseWheel> binding actually asks for" {.t yview scroll 3 units}

puts ""
puts "reached the end -- nothing hung"
flush stdout
exit 0
