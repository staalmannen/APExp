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

# 1b. Key events again, with the focus set. Tk_HandleEvent redirects
# KeyPress/KeyRelease to the focus window and drops them when there is
# none, so a bare "event generate .f <Key-a>" proves nothing on its own.
focus -force .f
update
mark "focus is now [focus]"
set ::hits {}
bind .f <Key-a> {lappend ::hits fired}
event generate .f <Key-a>
mark "KeyA with focus: [expr {[llength $::hits] ? "FIRED" : "not delivered"}]"
bind .f <Key-a> {}

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

mark "done"
exit 0
