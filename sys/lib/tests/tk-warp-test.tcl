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
# write.
#
# The first attempt at this script tried to ask rio directly, by
# opening /dev/mouse from Tcl and writing "m150 150". That cannot work,
# and the failure is the useful part of the answer:
#
#	couldn't open "/dev/mouse": file in use
#
# /dev/mouse opens once, and this process is holding it -- which does
# at least prove the descriptor exists, so tkp9_warpmouse is not
# failing for want of one. Everything else about it (whether the open
# got O_RDWR or fell back to O_RDONLY, what the write returned, what
# rio put in the errstr) is only visible from inside the process.
#
# Hence $TKP9DEBUG, which traces the whole chain:
#
#	TKP9DEBUG=1 wish tk-warp-test.tcl
#
# Run it both ways. Section 1 decides whether the warp is the bug or
# merely downstream of a mouse poll that delivers nothing, and it needs
# you to move the mouse.
#
# WHAT THIS ACTUALLY FOUND, and why the script is kept: the warp was
# never the bug. The trace reads
#
#	tkp9: /dev/mouse fd=7 writable=1
#	XWarpPointer: dw=11 dx=20 dy=20 -> screen 120,120
#	tkp9_warpmouse: wrote "m120 120" ok
#	  FAIL to a window (bind-34.1): pointerxy unchanged at 0 0
#
# -- written, and acknowledged, and still 0 0. The answer is in section
# 1 of the same run: a real <Motion> reported 397 124 and "winfo
# pointerxy" said 0 0 on the very next line, so gP9.lastmouse was right
# and only the READBACK was wrong. TkGetPointerCoords in tkPlan9Wm.c
# was a stub assigning 0 to both, next door to an XQueryPointer that
# works.
#
# The moral for the next one of these: a value that is read back wrong
# looks identical to a value that was never written. Prove the readback
# before chasing the write -- one line comparing %X against winfo
# pointerxy would have saved two rounds here.

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

# 1. Does a real mouse report reach Tk at all? This is the question
# that decides whether the warp is the bug or a symptom, so it waits
# long enough to actually be answered: MOVE THE MOUSE OVER THE wish
# WINDOW while it counts down. Doing nothing reports "no motion seen",
# which is not the same as a failure and is not counted as one.
note ""
note "--- 1. real motion ---"
note "  MOVE THE MOUSE OVER THE wish WINDOW now (10s)..."
set ::sawmotion {}
bind . <Motion> {set ::sawmotion "%X %Y"}
for {set i 10} {$i > 0 && $::sawmotion eq ""} {incr i -1} {
    after 1000 {set ::tick 1}
    vwait ::tick
    update
}
bind . <Motion> {}
if {$::sawmotion eq ""} {
    note "  no <Motion> seen. If you did move the mouse over the window,"
    note "  the poll is the bug and the warp is downstream of it; run"
    note "  with TKP9DEBUG set to see what tkp9_readmouse got."
} else {
    note "  PASS <Motion> reported screen coords $::sawmotion"
    note "  winfo pointerxy . -> [pxy]"
}

# 2. /dev/mouse cannot be opened twice, and this process holds it, so
# asking rio from Tcl is not possible -- "file in use" is all that can
# come back, which at least proves Tk has the descriptor. The state
# that matters (was it opened for writing, and what did the warp write
# return) is only visible from inside, hence $TKP9DEBUG.
note ""
note "--- 2. who holds /dev/mouse ---"
if {[catch {open /dev/mouse r+} f]} {
    note "  open /dev/mouse: $f"
    note "  'file in use' here is the expected answer and means Tk has it."
} else {
    note "  open /dev/mouse SUCCEEDED -- so Tk does NOT have it, which is"
    note "  the bug: no descriptor means no events and no warp."
    catch {close $f}
    incr fail
}

# 3. Tk's own warp, both forms. bind-34.2 is the second of these.
#
# The check is WHERE the pointer landed, not merely that it moved. An
# earlier version of this script asked only whether pointerxy changed,
# and reported PASS for
#
#	to a window (bind-34.1): pointerxy 407 188 -> 369 52
#
# with a warp target of 120,120 -- the reading had changed because a
# hand was still on the mouse from section 1, and "it changed" is not
# "it went where it was told". bind-34.1 itself warps twice and requires
# the two readings to differ by exactly the amount the window moved, so
# nothing less than the exact position is worth reporting.
#
# DO NOT TOUCH THE MOUSE from here on: a real report overwrites
# gP9.lastmouse and invalidates the reading.
note ""
note "--- 3. event generate -warp (do not touch the mouse) ---"
set rx [winfo rootx .]
set ry [winfo rooty .]
foreach {what cmd wantx wanty} [list \
    "to a window (bind-34.1)"   {event generate . <Motion> -x 20 -y 20 -warp 1} \
        [expr {$rx + 20}] [expr {$ry + 20}] \
    "to the screen (bind-34.2)" {event generate {} <Motion> -x 200 -y 200 -warp 1} \
        200 200 \
] {
    if {[catch $cmd err]} {
	note "  FAIL $what: command raised: $err"
	incr fail
	continue
    }
    after 100
    update
    after 100
    update
    set got [pxy]
    if {$got eq [list $wantx $wanty]} {
	note "  PASS $what: pointer is at $got"
    } else {
	note "  FAIL $what: pointer is at $got, want $wantx $wanty"
	incr fail
    }
}

# 4. If section 3 failed with a position that is neither the target nor
# the last place the mouse physically was, rio is not honouring the
# write. XWarpPointer sets gP9.lastmouse itself right after the write,
# so Tk believes the warp until the next real mouse report overwrites
# it -- which means a warp can look right for as long as nothing moves
# and then quietly revert.
note ""
note "--- 4. notes ---"
note "  . is at [winfo rootx .],[winfo rooty .]; pointer reads [pxy]"
note ""
note "Run again with TKP9DEBUG set for the trace from inside:"
note "    TKP9DEBUG=1 wish tk-warp-test.tcl"
note "which reports the /dev/mouse descriptor and mode, every"
note "TkpWarpPointer/XWarpPointer call, and the warp write with its errstr."

puts "$fail failure(s)"
flush stdout
exit $fail
