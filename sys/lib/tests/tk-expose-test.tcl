# What damage does this port report when a window goes away?
#
#	wish tk-expose-test.tcl
#
# WHERE THIS COMES FROM. textDisp-7.1..7.8 are eight failures of one
# shape. 7.1 is
#
#	frame .f2 -bg #ff0000
#	place .f2 -in .t -relx 0.2 -relwidth 0.6 -rely 0.22 -relheight 0.55
#	update
#	destroy .f2
#	update
#	list $tk_textRelayout $tk_textRedraw
#
#	got   {1.0 1.20 1.40 2.0 3.0 4.0 5.0 6.0 7.0 8.0}
#	      {borders 1.0 1.20 1.40 2.0 3.0 4.0 5.0 6.0 7.0 8.0}
#	want  {}
#	      {1.40 2.0 3.0 4.0 5.0 6.0}
#
# X reports the uncovered RECTANGLE and Tk redraws the six display lines
# inside it, relaying out nothing. We relaid out and redrew the whole
# widget, borders included.
#
# THE ANSWER IS (a): NO EXPOSE AT ALL, IN ANY OF THE FOUR SECTIONS.
# The first run printed an empty "exposes:" line for every one of them,
# including section 4, which raises a frame -- and that is the result
# that pinned it down, because raising is the one path the code says
# does expose.
#
# Reading plan9/tkPlan9Init.c with that in hand:
#
#   - XUnmapWindow sends UnmapNotify and NO Expose.
#   - XDestroyWindow sent none either.
#   - P9ExposeTree -- the only thing that makes one -- is reached from
#     XMapWindow, XRaiseWindow and XLowerWindow, and always exposes
#     0,0,pw->width,pw->height. There was no partial Expose anywhere.
#   - AND generic Tk only calls XRaiseWindow/XLowerWindow for a
#     TOPLEVEL. Tk_RestackWindow (tkWindow.c) reorders
#     parentPtr->childList itself and tells the server about a sibling
#     with XConfigureWindow + CWStackMode -- which was pure bookkeeping
#     here, no repaint.
#
# So this port repaired damage in exactly ONE case, XMapWindow, and:
#
#	destroy a widget that overlapped another	-> pixels stayed
#	place forget a widget				-> pixels stayed
#	raise/lower a widget among its siblings		-> no repaint
#
# None of it visible from Tcl, because Tk believes it asked. And the
# stacking tests still passed throughout, because Tk_CoordsToWindow
# answers from Tk's own childList: the HIT TEST was right and only the
# pixels were stale -- the trap the stacking section in CLAUDE.md warns
# about, met from the other side.
#
# FIXED by P9ExposeRect/P9DamageUnder in tkPlan9Init.c, called from
# XDestroyWindow, XUnmapWindow and XConfigureWindow's CWStackMode path.
# Erring towards MORE damage is deliberate: too much costs a repaint,
# too little leaves stale pixels that nothing here will ever correct,
# since there is no backing store and no server to ask.
#
# SECOND RUN: IT WORKS, AND THE RECTANGLES ARE RIGHT.
#
#	STEP: 2. destroy .f2, then update
#	      exposes: {.t 52 26 144 55 count=0}
#	      relayout:
#	      redraw:   2.0 2.40 3.0 3.40 4.0 4.40
#	STEP: 3. ... 'place forget' it
#	      exposes: {.t 28 14 96 40 count=0}
#	STEP: 4. ... raise the lower one
#	      exposes: {.t 28 14 120 50} {.fb 0 0 72 30} {.fa 0 0 120 50}
#
# .f2 was 60% x 55% of a 248x108 .t at 20%,22%, so "52 26 144 55" is its
# rectangle -- partial damage, clipped, not the whole widget. Section 4
# shows the recursion right too: the parent over .fa's rectangle, then
# .fb clipped to the INTERSECTION, then .fa whole.
#
# AND THE RELAYOUT LINE IS EMPTY, which is what X does and what
# textDisp-7.1 asks for. The prediction in the commit that added the fix
# -- "probably does not fix textDisp-7.1..7.8" -- was wrong in the good
# direction; the suite says whether those eight go with it.
#
# SECTION 4 WAS RIGHT BY LUCK, AND THAT WAS A SECOND BUG. P9ExposeRect
# walked gP9.wins in SLOT order, roughly creation order, which has
# nothing to do with what is on top -- while the events ARE the
# stacking here, since drawing is immediate with no clipping and
# whoever repaints last wins the pixels. .fa had just been raised above
# .fb and happened to sit in a later slot. Create the two frames the
# other way round and the raise would have repainted .fb last, i.e.
# done nothing visible. P9ExposeRectStacked walks
# parentPtr->childList instead, which is Tk's own order, lowest first.
#
# THIRD RUN CONFIRMS IT: "ok: .fa repaints last, so the raise is
# visible", now by construction rather than by luck.
#
# THIS FILE CHECKS RATHER THAN ADVISES, from here on. Sections 2 and 4
# used to print instructions for reading their own output, which is one
# more thing to get wrong at 2am; they now say "ok" or "REGRESSION" and
# name what to look at only when something is wrong. Section 4 reads the
# ORDER, not the presence: .fa must come after .fb whichever way round
# they were created.
#
# The first run could not measure the redraw half at all:
# tk_textRelayout and tk_textRedraw are only recorded while the widget's
# own debugging is on -- textDisp.test's line 139 is
#
#	.t debug on
#
# and this file did not do it, so every "relayout:" line came back
# empty and said nothing. Worse, `build` here *assigned* the two
# variables, so the "does this Tk report them at all?" check could
# never fail either. A check that cannot fail is not a check.
#
# ORDER: cheap and expected-to-return cases first, each printing a
# flushed marker before it runs.

proc step {m} { puts "STEP: $m"; flush stdout }
proc note {m} { puts "      $m"; flush stdout }

# Every Expose that arrives anywhere we care about, with its rectangle
# and in ARRIVAL ORDER. Both halves matter: the rectangle says whether
# the clipping is right, and the order says whether the stacking is --
# whoever repaints last wins the pixels here.
set exposes {}
proc watch {w} {
    bind $w <Expose> [list lappend ::exposes "$w %x %y %w %h count=%c"]
}
proc exposes {} {
    set e $::exposes
    set ::exposes {}
    return $e
}

# textDisp's own setup, near enough: a text widget with enough lines to
# have display lines to name, and tk_textRelayout/tk_textRedraw turned
# on the way textDisp.test turns them on.
proc build {} {
    destroy .t .f2
    pack [text .t -width 40 -height 10 -wrap char -bd 2 -relief sunken]
    # WITHOUT THIS the two variables are never written and every
    # "relayout:" line below reads empty for the wrong reason.
    .t debug on
    for {set i 1} {$i <= 8} {incr i} {
	.t insert end "Line $i of the text widget, long enough to wrap\n"
    }
    watch .t
    update
    exposes
    set ::tk_textRelayout {}
    set ::tk_textRedraw {}
}

puts "--- does this Tk report relayout/redraw at all? ---"
destroy .t
catch {unset ::tk_textRelayout}
pack [text .tprobe -width 20 -height 4]
.tprobe debug on
.tprobe insert end "probe\n"
update
if {![info exists ::tk_textRelayout]} {
    note "tk_textRelayout still does not exist after '.t debug on' and an"
    note "insert -- this wish records nothing, so the redraw half of this"
    note "file cannot report anything. The Expose half still can."
} else {
    note "yes: tk_textRelayout is '$::tk_textRelayout'"
}
destroy .tprobe
build
note ".t is [winfo width .t]x[winfo height .t] at\
 [winfo rootx .t],[winfo rooty .t]"

puts ""
puts "--- 1. map: the case that is known to work ---"
step "1. create a frame over .t and map it"
frame .f2 -bg red
place .f2 -in .t -relx 0.2 -relwidth 0.6 -rely 0.22 -relheight 0.55
update
note "exposes: [exposes]"
note "relayout: [expr {[info exists ::tk_textRelayout] ? $::tk_textRelayout : {n/a}}]"
set ::tk_textRelayout {}
set ::tk_textRedraw {}

puts ""
puts "--- 2. THE ONE THAT FAILS: destroy it again (textDisp-7.1) ---"
step "2. destroy .f2, then update"
destroy .f2
update
set e [exposes]
note "exposes: $e"
note "relayout: [expr {[info exists ::tk_textRelayout] ? $::tk_textRelayout : {n/a}}]"
note "redraw:   [expr {[info exists ::tk_textRedraw] ? $::tk_textRedraw : {n/a}}]"
puts ""
if {[llength $e] == 0} {
    puts "  => REGRESSION: no Expose reached .t."
    puts "     This is what the first run reported and what P9DamageUnder"
    puts "     was written to fix. Destroying a window is leaving its"
    puts "     pixels on screen again."
} else {
    # CHECK the rectangle and the relayout rather than printing advice
    # about them. .f2 was 60% x 55% of .t placed at 20%,22%, so the
    # damage must be roughly that box -- a whole-widget rectangle means
    # P9ExposeRect's clipping is wrong -- and X relays out NOTHING here,
    # so a non-empty relayout means the second cause behind textDisp-7.1
    # is still present and is not the Expose.
    lassign [lindex $e 0] w rx ry rw rh
    set tw [winfo width .t]; set th [winfo height .t]
    puts "  => an Expose reached .t: [lindex $e 0]  (.t is ${tw}x${th})"
    if {$rw >= $tw && $rh >= $th} {
	puts "     REGRESSION: that is the WHOLE widget. P9ExposeRect is not"
	puts "     clipping to the departing window's rectangle."
    } else {
	puts "     ok: partial damage, roughly .f2's box"
    }
    set rl [expr {[info exists ::tk_textRelayout] ? $::tk_textRelayout : {n/a}}]
    if {$rl eq ""} {
	puts "     ok: relayout is empty, which is what X does"
    } else {
	puts "     REGRESSION: relayout is '$rl'. X relays out nothing here."
	puts "     Look for a ConfigureNotify on .t, or a geometry"
	puts "     re-request from place forgetting the slave."
    }
}

puts ""
puts "--- 3. unmap without destroying, which is the other half ---"
step "3. rebuild, map a frame over .t, then 'place forget' it"
build
frame .f3 -bg blue
place .f3 -in .t -relx 0.1 -relwidth 0.4 -rely 0.1 -relheight 0.4
update
exposes
set ::tk_textRelayout {}
place forget .f3
update
note "exposes: [exposes]"
note "relayout: [expr {[info exists ::tk_textRelayout] ? $::tk_textRelayout : {n/a}}]"
destroy .f3

puts ""
# THE DECISIVE SECTION ON THE FIRST RUN. Reading the code, raising is
# the ONE path that was supposed to expose -- and it reported nothing,
# which is what sent the search to Tk_RestackWindow and found that a
# non-toplevel never reaches XRaiseWindow at all. Keep it as the
# regression test for the CWStackMode path.
puts "--- 4. raise/lower: the sibling path, which reaches XConfigureWindow ---"
step "4. two overlapping frames in .t, raise the lower one"
build
frame .fa -bg green
frame .fb -bg yellow
place .fa -in .t -relx 0.1 -rely 0.1 -relwidth 0.5 -relheight 0.5
place .fb -in .t -relx 0.3 -rely 0.3 -relwidth 0.5 -relheight 0.5
watch .fa
watch .fb
update
exposes
raise .fa
update
set e [exposes]
note "exposes: $e"
note "(.fa is [winfo width .fa]x[winfo height .fa]; .fb is\
 [winfo width .fb]x[winfo height .fb])"
if {[llength $e] == 0} {
    note "REGRESSION: raising a sibling repainted nothing. raise/lower on"
    note "a widget goes through XConfigureWindow with CWStackMode, NOT"
    note "XRaiseWindow -- see Tk_RestackWindow in generic/tkWindow.c."
} else {
    # THE ORDER IS THE POINT, not the presence. .fa was just raised
    # above .fb, so .fa must repaint LAST or the raise is invisible.
    # This was right by luck once, when the walk was in slot order.
    set ia -1; set ib -1
    for {set i 0} {$i < [llength $e]} {incr i} {
	set win [lindex [lindex $e $i] 0]
	if {$win eq ".fa"} { set ia $i }
	if {$win eq ".fb"} { set ib $i }
    }
    if {$ia < 0} {
	note "REGRESSION: .fa was raised and got no Expose at all."
    } elseif {$ib >= 0 && $ia < $ib} {
	note "REGRESSION: .fb repaints AFTER .fa, so the raise is invisible."
	note "The child walk is not in stacking order -- it must follow"
	note "parentPtr->childList (lowest first), not gP9.wins slot order."
    } else {
	note "ok: .fa repaints last, so the raise is visible"
    }
}
destroy .fa .fb

puts ""
puts "reached the end"
flush stdout
exit 0
