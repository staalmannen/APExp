# Stacking order, and the hit-testing that reads it back.
#
#	wish tk-stacking-test.tcl
#
# Three separate things were missing, and they hide each other:
#
#   Tk_CoordsToWindow was a stub returning NULL, so "winfo containing"
#	answered the empty string for every point. raise.test decides the
#	stacking order entirely by asking what is on top at a given pixel,
#	so all eleven of its cases failed on that one line -- with an
#	error about a bad window path name, which names neither stacking
#	nor hit-testing.
#
#   TkWmRestackToplevel was a no-op, so "raise" and "lower" on a
#	toplevel did nothing at all.
#
#   XRaiseWindow and XLowerWindow were no-ops. There is no compositing
#	here: drawing goes straight into the one rio window, so a window
#	that has just been raised stays buried under whatever was drawn
#	over it until something makes it repaint. An X server would send
#	the Expose; nothing on Plan 9 will.
#
# Note the first two are invisible to each other. Restacking with no
# hit-test reports nothing; hit-testing with no restacking reports a
# stale but plausible answer. Test them apart.

set fail 0

proc check {what got want} {
    global fail
    if {$got eq $want} {
	puts "PASS $what"
    } else {
	puts "FAIL $what: got '$got', want '$want'"
	incr fail
    }
    flush stdout
}

proc note {m} { puts $m; flush stdout }

# 1. winfo containing, on plain nested widgets. No stacking involved --
# if this is broken nothing below means anything.
frame .f -width 200 -height 200 -bg red
place .f -x 0 -y 0
frame .f.g -width 50 -height 50 -bg blue
place .f.g -x 100 -y 100
update

set rx [winfo rootx .f]
set ry [winfo rooty .f]
check "containing a point in .f"   [winfo containing [expr $rx+10]  [expr $ry+10]]  ".f"
check "containing a point in .f.g" [winfo containing [expr $rx+120] [expr $ry+120]] ".f.g"

# A point outside everything must answer empty, not the nearest window.
set far [expr [winfo screenwidth .] - 1]
note "containing a far corner: '[winfo containing $far [expr [winfo screenheight .]-1]]'"

# 2. Overlapping siblings: the later one is on top, and raise/lower
# must change that. This is childList order, which Tk keeps itself, so
# it exercises Tk_CoordsToWindow rather than the platform restack.
destroy .f
frame .a -width 100 -height 100 -bg red
frame .b -width 100 -height 100 -bg blue
place .a -x 0 -y 0
place .b -x 0 -y 0
update
set rx [winfo rootx .a]
set ry [winfo rooty .a]
set mid [list [expr $rx+50] [expr $ry+50]]

check "later sibling is on top" [winfo containing {*}$mid] ".b"
raise .a
update
check "after 'raise .a'"        [winfo containing {*}$mid] ".a"
lower .a
update
check "after 'lower .a'"        [winfo containing {*}$mid] ".b"
raise .a .b
update
check "after 'raise .a .b'"     [winfo containing {*}$mid] ".a"
destroy .a .b

# 3. Toplevels. These have no childList to order them -- on X the server
# stacks them, and here dispPtr->firstWmPtr does. This is the part
# TkWmRestackToplevel owns.
toplevel .t1 -width 200 -height 200 -bg red
toplevel .t2 -width 200 -height 200 -bg blue
wm geometry .t1 200x200+100+100
wm geometry .t2 200x200+100+100
update
set p [list [expr [winfo rootx .t1]+100] [expr [winfo rooty .t1]+100]]
note "point $p; .t1 at [wm geometry .t1], .t2 at [wm geometry .t2]"

check "later toplevel is on top"  [winfo toplevel [winfo containing {*}$p]] ".t2"
raise .t1
update
check "after 'raise .t1'"         [winfo toplevel [winfo containing {*}$p]] ".t1"
lower .t1
update
check "after 'lower .t1'"         [winfo toplevel [winfo containing {*}$p]] ".t2"
raise .t1 .t2
update
check "after 'raise .t1 .t2'"     [winfo toplevel [winfo containing {*}$p]] ".t1"

# A withdrawn toplevel is not there to be hit.
wm withdraw .t1
update
check "withdrawn toplevel is skipped" \
    [winfo toplevel [winfo containing {*}$p]] ".t2"
wm deiconify .t1
update

destroy .t1 .t2

puts "$fail failure(s)"
flush stdout
exit $fail
