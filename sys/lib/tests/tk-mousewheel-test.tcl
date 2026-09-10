# What spins when a <MouseWheel> reaches a scrollbar?
#
#	wish tk-mousewheel-test.tcl
#
# tk-scrollbar-hang-test.tcl narrowed the suite's hang to one statement
# of scrollbar-10.1. Everything before it returns:
#
#	1d. update after 99 lines -- text layout alone     ok
#	2d. update -- both widgets now feed each other     ok
#	3.  focus -force .s                                ok
#	4.  event generate .s <Enter>                      ok
#	5.  event generate .s <MouseWheel> -delta -120     ok (queued)
#	6.  after 200 + vwait                              HANGS
#
# So text layout is exonerated, and so is the -yscrollcommand/-command
# wiring at rest: both were exercised and both returned. Generating the
# event is fine too -- "event generate" only queues. What has never
# happened until step 6 is the queued wheel event being DELIVERED, which
# runs the Scrollbar class binding, which scrolls the text widget.
#
# Note "after 200 + vwait" by itself is known to work: tk-enter-test.tcl
# uses exactly that idiom in its settle proc and passes. So the event
# loop is not broken in general -- something about this delivery is.
#
# Three things happen inside step 6 and they want different fixes, so
# this asks them separately and in order of sharpness. The early ones
# bypass the event machinery completely: if the text widget spins when
# scrolled by a direct command, no amount of looking at the notifier
# will help, and vice versa.
#
# ORDER MATTERS. A hang has to be killed by hand, so the probe that
# distinguishes the most comes first and the whole-event-loop case comes
# last. Whatever the last STEP line says is the one that did not return.
#
# WHERE THIS HAS GOT TO. Steps 0-7d all return, and between them they
# exonerate: crossing delivery (0 -- the <Enter> class binding does run,
# so Priv(xEvents) is set), the plain event loop (1), every shape of
# yview scroll including the ceil rounding and both signs (2, 2b, 2c,
# 2d), moveto (3), .s set (4), update after all of it (5), the
# ScrollByUnits body called directly with the binding's exact arguments
# (6, 7c) and twelve times over so the counting branch is reached (7d),
# and delivery of a wheel event with the class binding removed (7).
#
# 7e is where it stops, and its binding is a bare
# ".t yview scroll 3.0 units" -- no ScrollByUnits at all. So the
# statement of the bug is now exactly:
#
#	scroll alone		returns
#	delivery alone		returns
#	scroll INSIDE delivery	spins
#
# and sections 7e0..7e4 split that sentence, since "inside delivery"
# still covers four different things.

proc step {msg} { puts "STEP: $msg"; flush stdout }
proc done {msg} { puts "   ok: $msg"; flush stdout }

# A background error inside a binding otherwise reaches Tk's bgerror
# dialog, which is MODAL and waits for a click that no test will ever
# give it -- so an error turns into a hang and the message is only
# visible on screen. Log it instead.
proc ::bgerror {msg} {
    puts "BGERROR: $msg"
    flush stdout
}

# The suite's setup, minus the wheel.
proc build {} {
    destroy .t .s
    pack [text .t -yscrollcommand {.s set}] -side left
    for {set i 1} {$i < 100} {incr i} {.t insert end "Line $i\n"}
    pack [scrollbar .s -command {.t yview}] -fill y -expand 1 -side left
    update
}

puts "--- what the binding actually is on this build ---"
puts "Scrollbar <MouseWheel>: [bind Scrollbar <MouseWheel>]"
puts "Text <MouseWheel>:      [bind Text <MouseWheel>]"
flush stdout
puts ""

# ------------------------------------------------------------------
# Section 0, and it is the one that matters now.
#
# tk::ScrollByUnits reads $Priv(xEvents) and $Priv(yEvents) on every
# wheel event, and the ONLY place in the whole library that ever sets
# them is scrlbar.tcl:132
#
#	bind Scrollbar <Enter> {+
#	    set tk::Priv(xEvents) 0; set tk::Priv(yEvents) 0
#	}
#
# So a wheel event delivered to a scrollbar that has never seen an
# <Enter> raises
#
#	can't read "Priv(xEvents)": no such element in array
#
# That is upstream's design, not a port bug: any Tk would do the same.
# scrollbar-10.1 knows it, which is why it sends <Enter> first.
#
# The question this section asks is therefore whether the <Enter> is
# actually DELIVERED here -- because if it is not, the wheel event
# raises that error, the error reaches bgerror, and on a suite run the
# modal dialog is the hang.
build
catch {unset ::tk::Priv(xEvents)}
catch {unset ::tk::Priv(yEvents)}
step "0. deliver <Enter> to the scrollbar and ask whether the class\
 binding ran"
event generate .s <Enter>
update
puts "   Priv(xEvents) exists: [info exists ::tk::Priv(xEvents)]\
 (1 means the <Enter> class binding ran)"
puts "   Priv(yEvents) exists: [info exists ::tk::Priv(yEvents)]"
flush stdout
done "probe complete"

# ------------------------------------------------------------------
build
step "1. after+vwait with the widgets built but NOTHING queued\
 -- does the plain event loop return here at all?"
after 200 {set ::v1 1}
vwait ::v1
done "vwait returned, so the event loop and after are fine in this setup"

# ------------------------------------------------------------------
# The binding is
#	tk::ScrollByUnits %W vh %D -40.0
# and ScrollByUnits (library/scrlbar.tcl:391) ends in
#	uplevel #0 $cmd scroll [expr {$amount/$factor}] units
# so with %D = -120 and factor -40.0 the text widget is asked for
#	.t yview scroll 3.0 units
# -- a DOUBLE, not an integer, and positive. Both of those matter:
# tkTextDisp.c's GetScrollInfo does
#	*intPtr = (d > 0) ? ceil(d) : floor(d);
# and YScrollByLines takes a different branch for each sign. So ask for
# the exact form first, then the variants. (ceil and floor are both
# declared in sys/include/ape/math.h -- checked -- so the implicit-int
# trap that has bitten this tree before is not in play here.)
#
# What to watch for in the negative branch, because it is the one shape
# here that spins rather than misbehaves -- YScrollByLines has
#
#	do {
#	    dlPtr = LayoutDLine(textPtr, &index);
#	    ...
#	    bytesToCount -= dlPtr->byteCount;
#	} while ((bytesToCount > 0)
#	         && (index.linePtr == dlPtr->index.linePtr));
#
# which never ends if LayoutDLine yields a display line of ZERO bytes:
# bytesToCount stops falling and index stops moving. LayoutDLine reaches
# Tk_MeasureChars through TkTextCharLayoutProc, and Tk_MeasureChars is
# this port's rewrite -- so a measure that reports no progress lands
# exactly here. Section 1d of tk-scrollbar-hang-test.tcl does NOT cover
# it: laying lines out for display and laying them out to count a scroll
# are different calls.

step "2. .t yview scroll 3.0 units  -- exactly what the binding asks\
 for: a positive DOUBLE, no events involved"
.t yview scroll 3.0 units
done "returned; index is now [.t index @0,0]"

step "2b. .t yview scroll 3 units  -- the same as an integer"
.t yview scroll 3 units
done "returned; index is now [.t index @0,0]"

step "2c. .t yview scroll -3.0 units  -- the negative branch, which is\
 the one with the do/while above"
.t yview scroll -3.0 units
done "returned; index is now [.t index @0,0]"

step "2d. .t yview scroll 0.5 units  -- a fraction that ceil must round\
 to 1; if ceil is broken this is where it shows"
.t yview scroll 0.5 units
done "returned; index is now [.t index @0,0]"

step "3. .t yview moveto 0.5  -- the other scroll entry point"
.t yview moveto 0.5
done "yview moveto returned; index is now [.t index @0,0]"

step "4. .s set 0.1 0.2  -- driving the scrollbar directly"
.s set 0.1 0.2
done "set returned"

step "5. update after all that scrolling"
update
done "update returned"

# ------------------------------------------------------------------
step "6. tk::ScrollByUnits .s v -4  -- the class binding's BODY,\
 called directly, so delivery is not involved"
if {[catch {tk::ScrollByUnits .s v -4} err]} {
    done "raised an error rather than hanging: $err"
} else {
    done "ScrollByUnits returned"
}

# ------------------------------------------------------------------
# Delivery, with the class binding taken out of the way. If this returns
# and the next section does not, the binding is the thing; if THIS hangs,
# it is event delivery itself and the binding is innocent.
step "7. deliver a <MouseWheel> to a scrollbar whose class binding is\
 removed -- delivery without the binding"
build
set saved [bind Scrollbar <MouseWheel>]
bind Scrollbar <MouseWheel> {}
event generate .s <MouseWheel> -delta -120
update
done "delivered with no binding; update returned"
bind Scrollbar <MouseWheel> $saved

# ------------------------------------------------------------------
# Between step 6 (returned) and step 8 (hangs) there are THREE
# differences, not one, and each wants a different fix. Step 6 called
#
#	tk::ScrollByUnits .s v -4
#
# and the real binding is
#
#	tk::ScrollByUnits %W vh %D -40.0		-> .s vh -120 -40.0
#
# so step 6 skipped, all at once:
#
#   a. the counting branch. It is guarded by
#	  [string length $orient] == 2 && $factor != 1.0
#      (scrlbar.tcl:375), and "v" with the default 1.0 fails BOTH halves
#      -- so Priv(xEvents)/Priv(yEvents) were never read, and the
#      "> 10 and non-dominant" early return was never reachable;
#   b. the division. -4/1.0 is -4.0; -120/-40.0 is 3.0. Opposite signs,
#      and sign picks the branch in YScrollByLines;
#   c. delivery. Step 6 ran at the top level, step 8 runs inside the
#      event loop with a redisplay pending.
#
# These sections take them one at a time, and they are placed BEFORE
# step 8 on purpose: a hang has to be killed by hand, so everything
# cheaper than the hang must have already printed.

step "7b. what does .s get return, and how long is it? (ScrollByUnits\
 branches on llength: 2 picks 'yview scroll N units', anything else\
 picks 'yview <fraction>', a different command entirely)"
build
event generate .s <Enter>
update
puts "   .s get -> [.s get]  (llength [llength [.s get]])"
flush stdout
done "probe complete"

step "7c. tk::ScrollByUnits .s vh -120 -40.0 -- the binding's exact\
 arguments, called directly, so delivery is NOT involved"
if {[catch {tk::ScrollByUnits .s vh -120 -40.0} err]} {
    done "raised an error rather than hanging: $err"
} else {
    done "returned; index is [.t index @0,0]"
}

step "7d. the same call twelve times -- the counting branch's early\
 return needs xEvents+yEvents > 10 to fire at all, so it is unreachable\
 in one call"
if {[catch {
    for {set i 0} {$i < 12} {incr i} {tk::ScrollByUnits .s vh -120 -40.0}
} err]} {
    done "raised an error rather than hanging: $err"
} else {
    done "returned; index is [.t index @0,0], xEvents\
 $::tk::Priv(xEvents) yEvents $::tk::Priv(yEvents)"
}

# ------------------------------------------------------------------
# 7e HANGS, and that is the result everything below is built on. Its
# binding was a bare
#
#	bind Scrollbar <MouseWheel> {.t yview scroll 3.0 units}
#
# so tk::ScrollByUnits is INNOCENT: 7c called it with the binding's
# exact arguments and returned, 7d called it twelve times and returned.
# Three facts, and only their combination spins:
#
#	scroll alone (step 2)		returns
#	delivery alone (step 7)		returns
#	scroll from inside delivery	HANGS
#
# "Inside delivery" is doing a lot of work in that sentence, and it
# hides at least four different things. These sections take them one at
# a time, cheapest first, with the known hang LAST so everything else
# has printed before the machine has to be poked.
#
# The single most useful thing to know is whether the BINDING ITSELF is
# running over and over -- that separates "the event is being
# redelivered forever" from "one delivery, and something else will not
# settle". So every binding here counts itself and prints, which costs
# nothing when it returns and tells us the answer when it does not.

proc wheelcount {} {
    set ::n 0
    set ::trace {}
}

step "7e0. delivery whose binding does something TRIVIAL -- is a\
 non-empty binding enough on its own? (step 7's was empty)"
build
set saved [bind Scrollbar <MouseWheel>]
wheelcount
bind Scrollbar <MouseWheel> {incr ::n}
event generate .s <Enter>
event generate .s <MouseWheel> -delta -120
update
bind Scrollbar <MouseWheel> $saved
done "returned; the binding ran $::n time(s).  More than 1 means the\
 wheel event is being REDELIVERED, which would be this port's event\
 source rather than anything in Tk."

step "7e1. binding touches the SCROLLBAR only (.s set), not the text --\
 a widget command from inside delivery, with no text layout involved"
build
set saved [bind Scrollbar <MouseWheel>]
wheelcount
bind Scrollbar <MouseWheel> {incr ::n; .s set 0.1 0.2}
event generate .s <Enter>
event generate .s <MouseWheel> -delta -120
update
bind Scrollbar <MouseWheel> $saved
done "returned; the binding ran $::n time(s)"

# ------------------------------------------------------------------
# 7e2 HANGS, and its text widget is NOT wired to the scrollbar -- so
# the -yscrollcommand callback is not the loop either. Combined with
# 7e0 and 7e1, which each ran their binding exactly once and returned:
#
#	delivery + trivial binding	returns
#	delivery + .s set		returns
#	delivery + a text scroll	HANGS
#	a text scroll on its own	returns	(step 2)
#
# So it is not delivery, and it is not the scroll, and it is not the
# scrollbar. What is left is the pair, and the next question is whether
# "delivery" is even the operative half -- an X event handler is only
# one of the ways to end up running a script from inside the event
# loop, and the cheap ones do not need an event at all.

# The unwired pair, built once for the four sections below.
proc build2 {} {
    destroy .t .s .u
    pack [scrollbar .s] -fill y -expand 1 -side left
    pack [text .u] -side left
    for {set i 1} {$i < 100} {incr i} {.u insert end "Line $i\n"}
    update
}

step "7e1b. scroll the text widget from an IDLE handler -- inside the\
 event loop, but no event and no binding"
build2
after idle {incr ::n; .u yview scroll 3.0 units}
wheelcount
update
done "returned; ran $::n time(s), index is [.u index @0,0]"

step "7e1c. the same from a TIMER handler (after 0) rather than an idle\
 -- a different queue, still no X event"
build2
wheelcount
after 0 {incr ::n; .u yview scroll 3.0 units}
after 200 {set ::v7e1c 1}
vwait ::v7e1c
done "returned; ran $::n time(s), index is [.u index @0,0]"

step "7e1d. the same from a <Key> binding -- a real X event, but a\
 keyboard one, so nothing in the pointer machinery is involved"
build2
focus -force .s
update
bind .s <Key-a> {incr ::n; .u yview scroll 3.0 units}
wheelcount
event generate .s <Key-a>
update
bind .s <Key-a> {}
done "returned; ran $::n time(s), index is [.u index @0,0].  If a key\
 event is fine and the wheel is not, it is the POINTER path."

step "7e2. THE HANG: binding scrolls a text widget that is NOT wired to\
 the scrollbar.  Watch the wheel# lines"
build2
set saved [bind Scrollbar <MouseWheel>]
wheelcount
bind Scrollbar <MouseWheel> {
    incr ::n
    if {$::n <= 8} { puts "  wheel #$::n"; flush stdout }
    .u yview scroll 3.0 units
}
event generate .s <Enter>
event generate .s <MouseWheel> -delta -120
update
bind Scrollbar <MouseWheel> $saved
done "returned after all; ran $::n time(s), index is [.u index @0,0]"

step "7e2b. the same WITHOUT the preceding <Enter> -- this binding does\
 not read Priv(xEvents), so the crossing is not needed here, and\
 leaving it out asks whether the crossing is part of the loop"
build2
set saved [bind Scrollbar <MouseWheel>]
wheelcount
bind Scrollbar <MouseWheel> {
    incr ::n
    if {$::n <= 8} { puts "  wheel-noenter #$::n"; flush stdout }
    .u yview scroll 3.0 units
}
event generate .s <MouseWheel> -delta -120
update
bind Scrollbar <MouseWheel> $saved
done "returned; ran $::n time(s), index is [.u index @0,0]"
destroy .u

step "7e3. the wired pair, but delivered through after+vwait rather\
 than update -- is it 'update' that will not drain, or the event loop?"
build
set saved [bind Scrollbar <MouseWheel>]
wheelcount
bind Scrollbar <MouseWheel> {incr ::n; .t yview scroll 3.0 units}
event generate .s <Enter>
event generate .s <MouseWheel> -delta -120
after 400 {set ::v7e3 1}
vwait ::v7e3
bind Scrollbar <MouseWheel> $saved
done "returned; the binding ran $::n time(s), index is [.t index @0,0]"

# ------------------------------------------------------------------
# THE KNOWN HANG. Everything above has printed by now. The binding
# prints its own invocation number, so the log says which of the two
# shapes this is even though the script never gets to its "ok" line:
#
#   "  wheel #1" and nothing more	one delivery, and the drain after
#					it never settles -- look at what
#					the redisplay queues (Expose,
#					pointerDirty, an idle handler that
#					re-posts itself).
#   "  wheel #1 #2 #3 ..." forever	the event is being redelivered,
#					which is this port's event source.
#
# The count is capped so a redelivery loop does not fill the disk; after
# the cap it goes quiet, and a quiet hang after exactly 8 lines is still
# the second answer, not the first.
step "7e4. THE HANG: the wired pair, binding scrolls .t, delivered\
 through update.  Watch the wheel# lines below"
build
set saved [bind Scrollbar <MouseWheel>]
wheelcount
bind Scrollbar <MouseWheel> {
    incr ::n
    if {$::n <= 8} { puts "  wheel #$::n"; flush stdout }
    .t yview scroll 3.0 units
}
event generate .s <Enter>
event generate .s <MouseWheel> -delta -120
update
bind Scrollbar <MouseWheel> $saved
done "returned after all; the binding ran $::n time(s), index is\
 [.t index @0,0]"

step "7f. the real binding body, but run from 'after idle' rather than\
 from an event -- inside the event loop, without the wheel event"
build
event generate .s <Enter>
update
after idle {tk::ScrollByUnits .s vh -120 -40.0}
update
done "returned; index is [.t index @0,0]"

# ------------------------------------------------------------------
# NOTE: this used to omit the <Enter>, which made it an invalid
# sequence on ANY Tk -- ScrollByUnits would raise "can't read
# Priv(xEvents)" upstream too. The hang that produced was Tk's modal
# bgerror dialog waiting for a click, not a loop. Send the <Enter>, as
# scrollbar-10.1 does.
step "8. the same delivery WITH the binding and a preceding <Enter>,\
 through update rather than vwait"
build
event generate .s <Enter>
event generate .s <MouseWheel> -delta -120
update
done "update returned; index is [.t index @0,0]"

# ------------------------------------------------------------------
step "9. scrollbar-10.1 exactly: generate, then after+vwait"
build
focus -force .s
event generate .s <Enter>
event generate .s <MouseWheel> -delta -120
after 200 {set ::v9 1}
vwait ::v9
done "vwait returned; index is [.t index @0,0] (the test wants 4.0)"

puts ""
puts "reached the end -- nothing hung this time"
flush stdout
destroy .t .s
exit 0
