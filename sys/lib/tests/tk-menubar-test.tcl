# tk-menubar-test.tcl -- TkUnixSetMenubar, which was an empty stub.
#
# WHERE THIS CAME FROM, AND WHAT IT COST: the whole Tk test suite froze.
# unixWm-50.5 does
#
#	testmenubar window .t .t.menu
#	tkwait visibility .t.menu
#
# and TkUnixSetMenubar in plan9/tkPlan9Stubs.c was "(void)tkwin;
# (void)menubar;" -- so the menubar window was never mapped, no
# VisibilityNotify was ever sent for it, and tkwait waited forever. That
# stopped unixWm.test dead and with it the last five files of the suite
# (visual, winfo, winWm, wm, xmfbox), which had never been measured.
#
# RUN IT WITH tktest, NOT wish -- "testmenubar" is one of Tk's own test
# commands and exists only in that binary:
#
#	cd sys/src/ape/cmd/wish && mk tktest
#	./tktest $home/APExp/sys/lib/tests/tk-menubar-test.tcl
#
# THE POINT OF SECTION 1 IS THAT IT RETURNS AT ALL. Every marker is
# printed and flushed BEFORE the statement it names, so if this hangs
# again the last line names the statement that did not return. Sections
# expected to return come first, in file order -- appending a case that
# hangs above the questions that matter is how a whole round trip was
# once wasted.

set failures 0

proc step {msg} {
    puts "STEP: $msg"
    flush stdout
}
proc check {name got want} {
    global failures
    if {$got eq $want} {
	puts "  PASS $name: $got"
    } else {
	incr failures
	puts "  FAIL $name: got '$got' want '$want'"
    }
    flush stdout
}
proc note {name got} {
    puts "  note $name: $got"
    flush stdout
}

if {[catch {testmenubar window} msg] && [string match "invalid command name*" $msg]} {
    puts "SKIP: no testmenubar command -- run this with tktest, not wish"
    exit 0
}

# ------------------------------------------------------------------
step "1. set a menubar, then tkwait visibility on it (THE FREEZE)"

destroy .t
toplevel .t -width 300 -height 400 -bd 2 -relief raised
frame .t.f -width 150 -height 120 -bg green
place .t.f -x 10 -y 150
wm geom .t +0+50
frame .t.menu -width 100 -height 30 -bd 2 -relief raised
frame .t.menu.f -width 40 -height 20 -bg purple
place .t.menu.f -x 30 -y 10

step "1a. testmenubar window .t .t.menu"
testmenubar window .t .t.menu

step "1b. tkwait visibility .t.menu -- this is what used to hang"
tkwait visibility .t.menu

step "1c. update"
update
puts "  ok: it returned"
flush stdout

# The two things the map has to have done. ismapped is the one tkwait
# was waiting on; the width is the menubar following its toplevel, which
# is what WmUpdateGeometry does for it.
check "menubar ismapped" [winfo ismapped .t.menu] 1
check "menubar width follows toplevel" \
	[winfo width .t.menu] [winfo width .t]
check "menubar height" [winfo height .t.menu] 30

# ------------------------------------------------------------------
step "2. cancel the menubar"

testmenubar window .t {}
update
check "unmapped after cancel" [winfo ismapped .t.menu] 0

# ------------------------------------------------------------------
step "3. replace one menubar with another"

frame .t.menu2 -width 100 -height 20 -bd 2 -relief raised
testmenubar window .t .t.menu
update
testmenubar window .t .t.menu2
update
check "old menubar unmapped" [winfo ismapped .t.menu] 0
check "new menubar mapped"   [winfo ismapped .t.menu2] 1
check "new menubar height"   [winfo height .t.menu2] 20

# ------------------------------------------------------------------
step "4. destroy the menubar while it is in force"

# MenubarDestroyProc has to clear wmPtr->menubar, or WmUpdateGeometry
# keeps sizing a freed TkWindow on the next resize -- the use-after-free
# shape this port has hit twice before (TkpDeleteFont, TkpFreeColor).
destroy .t.menu2
update
step "4a. resize the toplevel, which is what would touch a stale pointer"
wm geometry .t 250x300
update
puts "  ok: no fault"
flush stdout

# ------------------------------------------------------------------
step "5. destroy the TOPLEVEL while a menubar is in force"

# This is the half section 4 does not cover, and it is where the suite
# faulted: run 9 crashed immediately after unixWm-49.2, which is a
# menubar test, with
#
#	tktest: suicide: sys: trap: fault write addr=0x3a3a79007393
#
# -- a write through a pointer whose bytes read like text, i.e. one
# fetched out of a block that has been freed and reused. Two orderings
# have to be told apart, so they are separate steps.

step "5a. menubar is a CHILD of the toplevel (what unixWm-49.2 does)"
destroy .t
toplevel .t -width 300 -height 200 -bd 2 -relief raised
frame .t.m -bd 2 -relief raised -width 100 -height 30
testmenubar window .t .t.m
update
destroy .t
update
puts "  ok: no fault"
flush stdout

# The ordinary way a program sets a menubar is "$w configure -menu .m",
# and tkUnixMenu.c then hands TkUnixSetMenubar the MENU WIDGET -- which
# is a SIBLING, not a child. Nothing destroys it with the toplevel, so
# this is the ordering where the menubar can outlive the WmInfo it
# points at. Upstream's TkWmDeadWindow destroys it explicitly.
step "5b. menubar is NOT a child of the toplevel"
destroy .t .m
toplevel .t -width 300 -height 200
frame .m -bd 2 -relief raised -width 100 -height 30
testmenubar window .t .m
update
destroy .t
update
check "menubar went with its toplevel" [winfo exists .m] 0

step "5c. what unixWm.test does next: withdraw . and build a toplevel"
destroy .t
wm geom . +700+700
wm withdraw .
toplevel .t -width 200 -height 200 -bg green
update
destroy .t
wm deiconify .
update
puts "  ok: no fault"
flush stdout

# ------------------------------------------------------------------
step "6. KNOWN WRONG, recorded rather than asserted"

# There are no wrapper windows in this port, so a menubar stays an
# ordinary child of its toplevel instead of sitting above it in a
# wrapper. Two consequences follow, and neither can be fixed without a
# wrapper -- see the menubar note in plan9/tkPlan9Wm.c. They are printed
# rather than checked, because asserting today's answer would freeze the
# limitation in place as if it were the requirement.
#
# X says: contents pushed down by menuHeight, and a point above the
# toplevel hits the menubar.

destroy .t
toplevel .t -width 300 -height 200 -bd 2 -relief raised
wm geom .t +0+0
update
set x [winfo rootx .t]
set y [winfo rooty .t]
frame .t.m -bd 2 -relief raised -width 100 -height 30
frame .t.f -width 20 -height 30 -bd 2 -relief raised
place .t.f -x 10 -y 30
testmenubar window .t .t.m
update
note "content offset (unixWm-49.2 wants 62, a wrapper would give it)" \
	[expr {[winfo rooty .t.f] - $y}]
note "hit test above the toplevel (unixWm-50.5 wants .t.m)" \
	[winfo containing $x [expr {$y - 15}]]

destroy .t
puts ""
puts "failures: $failures"
exit $failures
