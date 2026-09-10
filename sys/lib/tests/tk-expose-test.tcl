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
# TWO PREDICTIONS FROM THE CODE, AND THEY WANT OPPOSITE FIXES. Reading
# plan9/tkPlan9Init.c:
#
#   - XUnmapWindow sends UnmapNotify and NO Expose.
#   - XDestroyWindow sends no Expose either.
#   - P9ExposeTree -- the only thing that makes one, and it is reached
#     only from XMapWindow, XRaiseWindow and XLowerWindow -- always
#     exposes 0,0,pw->width,pw->height. THE WHOLE WINDOW, NEVER A
#     RECTANGLE. There is no partial Expose anywhere in this port.
#
# So either
#
#   (a) no Expose reaches .t at all, in which case destroying a window
#       leaves its pixels on screen -- a visible bug quite apart from
#       the test -- and the full relayout comes from somewhere else
#       entirely (a resize, a ConfigureNotify, a geometry re-request),
#       which is where to look next; or
#
#   (b) one whole-window Expose reaches .t, in which case the fix is
#       damage RECTANGLES: on unmap or destroy, expose each sibling
#       below with the departing window's rectangle intersected with
#       that sibling and translated into its coordinates.
#
# Those are different bugs in different files. Print the events rather
# than guessing which -- the record in CLAUDE.md is that a confident
# mechanism has been wrong here five times, and a printed intermediate
# value settled it in one round each time.
#
# BE CAREFUL WITH (b). Sending too LITTLE damage is worse than sending
# too much: too much costs a repaint, too little leaves stale pixels
# that nothing will ever correct, because there is no backing store and
# no server to ask. Any move in that direction wants this file re-run
# with the rectangles printed, not just the test suite.
#
# ORDER: cheap and expected-to-return cases first, each printing a
# flushed marker before it runs.

proc step {m} { puts "STEP: $m"; flush stdout }
proc note {m} { puts "      $m"; flush stdout }

# Every Expose that arrives anywhere we care about, with its rectangle.
# The rectangle is the whole point: "0 0 <full width> <full height>" is
# prediction (b), nothing at all is (a).
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
    catch {unset ::tk_textRelayout}
    catch {unset ::tk_textRedraw}
    pack [text .t -width 40 -height 10 -wrap char -bd 2 -relief sunken]
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
build
note ".t is [winfo width .t]x[winfo height .t] at\
 [winfo rootx .t],[winfo rooty .t]"
if {![info exists ::tk_textRelayout]} {
    note "tk_textRelayout does not exist -- this wish was not built with"
    note "the text widget's debugging hooks, so the redraw half of this"
    note "file cannot report anything. The Expose half still can."
}

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
    puts "  => (a) NO Expose reached .t."
    puts "     Destroying a window leaves its pixels on screen here, and"
    puts "     the relayout above came from something else. Look at what"
    puts "     else fired: a ConfigureNotify on .t, or a geometry"
    puts "     re-request from place forgetting the slave."
} else {
    set r [lindex $e 0]
    puts "  => (b) an Expose DID reach .t: $r"
    puts "     Compare its w/h against .t's [winfo width .t]x[winfo height .t]."
    puts "     Equal means whole-window damage and the fix is rectangles;"
    puts "     smaller means the granularity is already there and the"
    puts "     relayout has another cause."
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
puts "--- 4. raise/lower, the paths that DO expose today ---"
step "4. two overlapping frames in .t, raise the lower one"
build
frame .fa -bg green
frame .fb -bg yellow
place .fa -in .t -relx 0.1 -rely 0.1 -relwidth 0.5 -relheight 0.5
place .fb -in .t -relx 0.3 -rely 0.3 -relwidth 0.5 -relheight 0.5
watch .fa
update
exposes
raise .fa
update
note "exposes: [exposes]"
note "(.fa is [winfo width .fa]x[winfo height .fa] -- an Expose of exactly"
note " that size is P9ExposeTree doing whole-window damage, by design)"
destroy .fa .fb

puts ""
puts "reached the end"
flush stdout
exit 0
