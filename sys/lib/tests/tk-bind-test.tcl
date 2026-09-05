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
# Everything above uses a frame in "." and now works, while bind.test
# still fails every key case -- and its one structural difference is
# that it builds .t.f inside a toplevel .t:
#
#	toplevel .t -width 100 -height 50
#	frame .t.f -class Test -width 150 -height 100
#	pack .t.f
#	focus -force .t.f
#
# Tk_HandleEvent hands a key event to TkFocusKeyEvent, which redirects
# it to displayFocusPtr->focusWinPtr and returns NULL -- dropping the
# event -- when there is no focus window. TkSetFocusWin refuses to set
# one unless the target AND every ancestor up to the toplevel have
# TK_MAPPED (tkFocus.c, the allMapped loop); it silently defers instead,
# arming a VisibilityChange handler. So a toplevel this port never marks
# mapped would lose every key event and nothing else, which is exactly
# the failure shape.
#
# "focus" reporting .t.f is the discriminator: if it answers empty or
# ".", the focus was never set and the mapping is why.
toplevel .t -width 100 -height 50
wm geom .t +0+0
frame .t.f -class Test -width 150 -height 100
pack .t.f
update
mark "toplevel .t: exists [winfo exists .t], mapped [winfo ismapped .t], id [winfo id .t]"
mark ".t.f:       exists [winfo exists .t.f], mapped [winfo ismapped .t.f], id [winfo id .t.f]"

# Which of the two possible stories is it: the focus was never set, or it
# was set and something during "update" took it away again? The observed
# answer is ".f" -- the frame in "." from section 1c -- and that is not
# what either clearing path in TkFocusFilterEvent leaves behind; both
# assign NULL, which "focus" reports as empty. A real FocusIn arriving
# for toplevel "." would restore exactly ".f", since that is what its
# ToplevelFocusInfo remembers.
#
# Two probes separate the cases, with no C to rebuild:
#
#   "focus" before update       -- did TkSetFocusWin assign at all?
#   "focus -lastfor .t.f"       -- reads .t's ToplevelFocusInfo, which
#                                  TkSetFocusWin fills in *after* the
#                                  allMapped test and *before* the
#                                  assignment. .t.f here means it got
#                                  past the mapped check; .t means it
#                                  bailed there.
#
# A <FocusIn> binding on . and on .f then says whether anything really
# is handing the focus back during update.
bind . <FocusIn>    {mark "  ... FocusIn on . (%d)"}
bind .f <FocusIn>   {mark "  ... FocusIn on .f (%d)"}
bind .t.f <FocusIn> {mark "  ... FocusIn on .t.f (%d)"}
bind .t.f <FocusOut> {mark "  ... FocusOut on .t.f (%d)"}

focus -force .t.f
mark "focus before update:      '[focus]' (want .t.f)"
mark "focus -lastfor .t.f:      '[focus -lastfor .t.f]' (.t.f = passed the mapped test)"
update
mark "focus after update:       '[focus]' (want .t.f)"

bind . <FocusIn> {}
bind .f <FocusIn> {}
bind .t.f <FocusIn> {}
bind .t.f <FocusOut> {}

# Re-assert the focus with nothing running in between, so the key cases
# below test delivery rather than whatever update did to the focus.
focus -force .t.f
mark "focus for the key cases:  '[focus]'"

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
