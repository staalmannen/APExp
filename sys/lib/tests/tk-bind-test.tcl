# Does "event generate" deliver events to bindings?
#
#	wish tk-bind-test.tcl
#
# bind.test accounts for 590 of the 642 failures in the full Tk suite,
# and every one has the same shape: a binding is installed, an event is
# generated for the window, and the binding never fires -- no error, an
# empty result. For example bind-4.1:
#
#	bind .t.f <Enter> {lappend x "%W enter .t.f"}
#	event generate .t.f <Enter>
#	return $x		-> {} , expected four entries
#
# The other files are in much better shape: canvas 20, button 20,
# clipboard 12 (all "selection not supported", a real feature gap), and
# bell, bgerror, bitmap, border, busy and choosedir have no failures at
# all. So this is close to one root cause rather than 642 problems.
#
# HandleEventGenerate (tkBind.c:4457) ends with
#
#	if (synch) {
#	    Tk_HandleEvent(&event.general);
#	} else {
#	    Tk_QueueWindowEvent(&event.general, pos);
#	}
#
# so "-when now" dispatches immediately and anything else queues. This
# separates: which event types arrive at all, and whether the immediate
# and queued paths differ.

proc mark {m} {
    puts $m
    flush stdout
}

frame .f -width 50 -height 50
pack .f
update
mark "frame is [winfo exists .f], mapped [winfo ismapped .f], id [winfo id .f]"

# 1. Immediate delivery, one event type at a time.
foreach {label ev} {
    Enter	<Enter>
    Leave	<Leave>
    Button1	<Button-1>
    Motion	<Motion>
    KeyA	<Key-a>
    Configure	<Configure>
    Expose	<Expose>
    FocusIn	<FocusIn>
} {
    set ::hits {}
    bind .f $ev {lappend ::hits fired}
    if {[catch {event generate .f $ev} err]} {
	mark "$label: event generate raised: $err"
    } else {
	mark "$label: [expr {[llength $::hits] ? "FIRED" : "not delivered"}]"
    }
    bind .f $ev {}
}

# 1c. Key events: is it delivery, or pattern matching?
#
# bind.test's remaining failures are all key events -- <:>, <+>, <_>,
# <Key-a> -- and every one returns empty. Two very different causes look
# identical from Tcl: the event never reaches the binding table, or it
# arrives and fails to match the pattern.
#
# A catch-all <Key> binding separates them. If <Key> fires and <Key-a>
# does not, delivery is fine and the keysym is wrong, in which case %K
# and %k say what Tk actually saw -- that is TkpGetKeySym's answer, and
# on this port it just hands back xkey.keycode, which XKeysymToKeycode
# produced as (keysym & 0xFF).
focus -force .f
update
mark "focus is now [focus]"

set ::hits {}
bind .f <Key> {lappend ::hits "Key: K=%K k=%k"}
event generate .f <Key-a>
mark "catch-all <Key> after <Key-a>: [expr {[llength $::hits] ? $::hits : "not delivered"}]"
bind .f <Key> {}

set ::hits {}
bind .f <Key-a> {lappend ::hits fired}
event generate .f <Key-a>
mark "specific <Key-a>: [expr {[llength $::hits] ? "FIRED" : "not delivered"}]"
bind .f <Key-a> {}

# The same event asked for by keysym rather than by pattern, and a
# couple of the punctuation keys bind.test uses.
foreach k {a colon plus underscore} {
    set ::hits {}
    bind .f <Key> {lappend ::hits "K=%K"}
    if {[catch {event generate .f <Key> -keysym $k} err]} {
	mark "keysym $k: event generate raised: $err"
    } else {
	mark "keysym $k: [expr {[llength $::hits] ? $::hits : "not delivered"}]"
    }
    bind .f <Key> {}
}

# 2. Queued delivery, to see whether the two paths differ.
set ::hits {}
bind .f <Enter> {lappend ::hits fired}
event generate .f <Enter> -when tail
update
mark "Enter -when tail: [expr {[llength $::hits] ? "FIRED" : "not delivered"}]"
bind .f <Enter> {}

# 3. A binding on a class and on "all", which take different paths
# through the binding tables than a widget binding does.
set ::hits {}
bind Frame <Enter> {lappend ::hits class}
bind all <Enter> {lappend ::hits all}
event generate .f <Enter>
mark "class/all bindings: [expr {[llength $::hits] ? $::hits : "not delivered"}]"
bind Frame <Enter> {}
bind all <Enter> {}

# 4. Does a real binding work at all -- i.e. is the binding table sane,
# independent of event delivery?
set ::hits {}
bind .f <<Custom>> {lappend ::hits virtual}
event generate .f <<Custom>>
mark "virtual event: [expr {[llength $::hits] ? "FIRED" : "not delivered"}]"

# 5. The same key test, but inside a second toplevel.
#
# Everything above uses a frame in "." and works, while bind.test failed
# every key case -- and the difference is not the toplevel, it is the
# ORDER of two lines. Every Tk test file opens with
#
#	pack .t.f
#	focus -force .t.f
#	update
#
# and pack maps on the idle queue, so at the moment of the focus command
# .t.f is still unmapped. TkSetFocusWin does not fail on that; it defers
# (tkFocus.c):
#
#	if (!allMapped) {
#	    Tk_CreateEventHandler((Tk_Window) winPtr, VisibilityChangeMask,
#		    FocusMapProc, winPtr);
#	    displayFocusPtr->focusOnMapPtr = winPtr;
#	    return;
#	}
#
# and FocusMapProc finishes the job when the window turns up. XMapWindow
# in this port sent MapNotify and Expose but no VisibilityNotify, so that
# handler never fired and the focus was simply never set.
#
# Key events are the only thing that notices, because they alone are
# redirected through the focus: InvokeFocusHandlers (tkEvent.c:255) calls
# TkFocusKeyEvent, which returns NULL when there is no focus window, and
# Tk_HandleEvent discards the event. Hence a Button-1 binding working on
# the very widget whose Key bindings do nothing -- the control at the end
# of this section.
#
# Order matters here, so keep it exactly as bind.test has it. Writing
# "update" before "focus -force" makes this pass whether the bug is fixed
# or not, which is how it hid for a round trip.
toplevel .t -width 100 -height 50
wm geom .t +0+0
frame .t.f -class Test -width 150 -height 100
pack .t.f
focus -force .t.f
mark "focus before update:      '[focus]'"
mark "focus -lastfor .t.f:      '[focus -lastfor .t.f]' (.t.f = TkSetFocusWin got past the mapped test)"
update
mark "toplevel .t: exists [winfo exists .t], mapped [winfo ismapped .t], id [winfo id .t]"
mark ".t.f:       exists [winfo exists .t.f], mapped [winfo ismapped .t.f], id [winfo id .t.f]"
mark "focus after update:       '[focus]' (want .t.f)"

set ::hits {}
bind .t.f <Key> {lappend ::hits "K=%K k=%k N=%N"}
event generate .t.f <Key-a>
mark ".t.f <Key> after <Key-a>: [expr {[llength $::hits] ? $::hits : "not delivered"}]"

set ::hits {}
event generate .t.f <Key>
mark ".t.f <Key> after bare <Key>: [expr {[llength $::hits] ? $::hits : "not delivered"}]"

set ::hits {}
event generate .t.f <:>
mark ".t.f <Key> after <:>: [expr {[llength $::hits] ? $::hits : "not delivered"}]"
bind .t.f <Key> {}

# A button event to the same window, as a control: if this arrives and
# the key events do not, the difference is the focus redirect and not
# delivery in general.
set ::hits {}
bind .t.f <Button-1> {lappend ::hits fired}
event generate .t.f <Button-1>
mark ".t.f <Button-1>: [expr {[llength $::hits] ? "FIRED" : "not delivered"}]"
bind .t.f <Button-1> {}

mark "done"
exit 0
