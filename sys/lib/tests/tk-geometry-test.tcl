# How many <Configure> events does moving a placed-in master send?
#
#	wish tk-geometry-test.tcl
#
# geometry-4.7 wants one and gets two:
#
#	got   init configure configure |
#	want  init configure |
#
# Tk_MaintainGeometry is the machinery. A window placed "-in" some
# window that is not its parent has to follow that master around, so
# tkGeometry.c registers a MaintainMaster on EVERY window between the
# master and the common ancestor -- here .f.f.f, .f.f and .f -- and any
# <Configure> on any of them recomputes the slave's position.
#
# The first guess was that the extra event was a REDUNDANT one: a move
# to a position the window already had. X is silent for those, and this
# port was not, so XMoveWindow/XResizeWindow/XMoveResizeWindow now
# return early when nothing changed (see the CLAUDE.md section). THAT
# DID NOT FIX IT -- the test still reports two.
#
# So the two events are not the same position reported twice, or they
# are and the guard is not being reached. Those want different fixes
# and the log below tells them apart, which is the whole point of this
# script: it prints %x %y %w %h for every <Configure> rather than
# counting them.
#
#   - two DIFFERENT geometries: .b1 really is being moved twice, so
#     something computes an intermediate position -- look at
#     MaintainMasterProc's order against place's own idle handler.
#   - two IDENTICAL geometries: a redundant event is still getting out,
#     so find the path that emits it. XConfigureWindow sends none, and
#     Tk_MoveResizeWindow sets TK_NEED_CONFIG_NOTIFY when the window
#     has no X window yet -- generic Tk can synthesise one without
#     going near this port's X shims at all.
#
# The geometry is geometry-4.7's, copied exactly, because the nesting
# depth is the thing being tested: .b1 is placed in .f.f.f, three
# levels below the window that moves.

set fail 0

proc note {m} { puts $m; flush stdout }

proc ok {cond what} {
    global fail
    if {[uplevel 1 [list expr $cond]]} {
	note "  PASS $what"
    } else {
	note "  FAIL $what"
	incr fail
    }
}

# Every Configure, with the geometry it reports -- not just a count.
set ::log {}
proc watch {w} {
    bind $w <Configure> {lappend ::log "%W %x,%y %wx%h"}
}
proc drain {} {
    set l $::log
    set ::log {}
    return $l
}

frame .f
frame .f.f
frame .f.f.f
frame .f.f.b4 -width 20 -height 20
frame .b1 -width 30 -height 20

place .f -x 20 -y 30 -width 200 -height 200
place .f.f -x 15 -y 5 -width 150 -height 120
place .f.f.f -width 100 -height 80
place .f.f.b4 -in .f.f.f -x 50 -y 5
place .b1 -in .f.f.f -x 10 -y 25
update

note "--- where everything sits before the move ---"
foreach w {.f .f.f .f.f.f .b1} {
    note "  $w: rootx,rooty [winfo rootx $w],[winfo rooty $w]\
 x,y [winfo x $w],[winfo y $w]\
 size [winfo width $w]x[winfo height $w]"
}

note ""
note "--- 1. move .f by 5,5; .b1 should see exactly one <Configure> ---"
watch .b1
drain
place .f -x 25 -y 35
update
set c [drain]
note "  <Configure> on .b1: $c"
note "  (geometry-4.7 wants one; two IDENTICAL entries means a redundant"
note "   event still escapes, two DIFFERENT ones mean .b1 moved twice)"
ok {[llength $c] == 1} "one <Configure> for one move of the master"

note ""
note "--- 2. move .f and .f.f together, as the test's second half does ---"
drain
place .f -x 30 -y 40
place .f.f -x 10 -y 0
update
set c [drain]
note "  <Configure> on .b1: $c"
note "  (both masters really moved, so more than one is legitimate here;"
note "   reported rather than asserted -- geometry-4.7 stops counting"
note "   at the | separator, before this)"

note ""
note "--- 3. a move that changes nothing at all ---"
# X sends no ConfigureNotify when a window is reconfigured to where it
# already is. This is the guard that was added for geometry-4.7, tested
# on its own so that it is not confused with section 1.
drain
place .f -x 30 -y 40
update
set c [drain]
note "  <Configure> on .b1 after re-placing .f at the same spot: $c"
ok {[llength $c] == 0} "re-placing at the same position is silent"

note ""
note "--- 4. and the same for the window that moved ---"
watch .f
drain
place .f -x 30 -y 40
update
set c [drain]
note "  <Configure> after a no-op place on .f itself: $c"
ok {[llength $c] == 0} "a no-op place sends nothing to .f either"

destroy .f .b1

puts "$fail failure(s)"
flush stdout
exit $fail
