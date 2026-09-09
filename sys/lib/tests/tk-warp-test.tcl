# Can the pointer be warped, and in which coordinate system?
#
#	wish tk-warp-test.tcl
#
# bind-34.1 (-warp relative to a window) and bind-34.2 (-warp relative
# to the screen) both fail, and so do the ten event-9.* cases, which
# position the pointer with -warp before destroying a window over it.
# All of them read back
#
#	winfo pointerxy .   ->   0 0
#
# Tk's chain for the screen case is short and has no grab machinery in
# it: HandleEventGenerate -> TkpWarpPointer -> XWarpPointer ->
# tkp9_warpmouse, then winfo pointerxy -> XQueryPointer, which answers
# from gP9.lastmouse. XWarpPointer sets lastmouse itself, immediately
# after the write, and returns EARLY without setting it when
# tkp9_warpmouse fails:
#
#	if (tkp9_warpmouse(x, y) < 0)
#		return 0;
#	gP9.lastmouse.x = x;
#
# so an unchanged 0 0 means the write to /dev/mouse did not happen.
# tkp9_warpmouse fails in exactly two ways: no descriptor, or a short
# write. This script asks rio directly, from Tcl, so the answer costs
# no rebuild.
#
# Section 2 is the one that matters. Plan 9's mouse file takes "m x y",
# and what it does with a window's file is the question: rio may refuse
# the write when the window is not the current one, and the coordinates
# may be the window's or the screen's. Section 3 asks which by warping
# to a point whose two readings differ.

set fail 0

proc note {m} { puts $m; flush stdout }

proc pxy {} { return [winfo pointerxy .] }

wm geometry . 300x200+100+100
update
after 200
update

note "--- where things are ---"
note "  screen:        [winfo screenwidth .]x[winfo screenheight .]"
note "  . rootx,rooty: [winfo rootx .],[winfo rooty .]"
note "  . width,height: [winfo width .]x[winfo height .]"
note "  winfo pointerxy . -> [pxy]"
note ""
note "  If pointerxy is 0 0 here and you have NOT touched the mouse,"
note "  that is expected: gP9.lastmouse starts at 0 0 and only a real"
note "  mouse report or a warp changes it. Move the mouse over the"
note "  window and run again -- if it is still 0 0 then the poll is"
note "  the bug and the warp is a red herring."

# 1. Does a real mouse report reach Tk at all? Bind <Motion> and ask
# the user to move the pointer. This separates "the poll never updates
# lastmouse" from "the warp cannot write".
note ""
note "--- 1. real motion (move the mouse over this window) ---"
set ::sawmotion {}
bind . <Motion> {set ::sawmotion "%X %Y"}
set after_id [after 3000 {set ::sawmotion timeout}]
vwait ::sawmotion
after cancel $after_id
if {$::sawmotion eq "timeout"} {
    note "  FAIL no <Motion> in 3s -- the mouse poll is not delivering"
    incr fail
} else {
    note "  PASS <Motion> reported screen coords $::sawmotion"
    note "  winfo pointerxy . -> [pxy]"
}
bind . <Motion> {}

# 2. Write to /dev/mouse by hand. This is exactly what tkp9_warpmouse
# does -- "m" then the two numbers, no newline -- so a failure here is
# the failure, and the error message names it.
note ""
note "--- 2. writing \"m x y\" to /dev/mouse by hand ---"
foreach mode {r+ w} {
    if {[catch {open /dev/mouse $mode} f]} {
	note "  open /dev/mouse $mode: FAILED: $f"
	continue
    }
    note "  open /dev/mouse $mode: ok"
    fconfigure $f -translation binary -buffering none
    set target "m150 150"
    if {[catch {puts -nonewline $f $target; flush $f} err]} {
	note "  write '$target': FAILED: $err"
	incr fail
    } else {
	note "  write '$target': ok"
	after 100
	update
	note "  winfo pointerxy . -> [pxy]"
    }
    catch {close $f}
    break
}

# 3. Tk's own warp, both forms. bind-34.2 is the second of these.
note ""
note "--- 3. event generate -warp ---"
foreach {what cmd} {
    "to a window (bind-34.1)"  {event generate . <Motion> -x 20 -y 20 -warp 1}
    "to the screen (bind-34.2)" {event generate {} <Motion> -x 200 -y 200 -warp 1}
} {
    set before [pxy]
    if {[catch $cmd err]} {
	note "  $what: command FAILED: $err"
	incr fail
	continue
    }
    after 100
    update
    after 100
    update
    set after [pxy]
    if {$before eq $after} {
	note "  FAIL $what: pointerxy unchanged at $after"
	incr fail
    } else {
	note "  PASS $what: pointerxy $before -> $after"
    }
}

# 4. Which coordinate system did the write use? Warp to a point well
# inside the window and compare the two readings. If rio takes the
# coordinates as window-relative it will land at rootx+150, and if as
# screen coordinates at 150.
note ""
note "--- 4. window-relative or screen coordinates? ---"
note "  . is at [winfo rootx .],[winfo rooty .]"
note "  after 'm150 150' the pointer is at [pxy]"
note "  screen-relative would read 150 150"
note "  window-relative would read [expr {[winfo rootx .]+150}] [expr {[winfo rooty .]+150}]"

puts "$fail failure(s)"
flush stdout
exit $fail
