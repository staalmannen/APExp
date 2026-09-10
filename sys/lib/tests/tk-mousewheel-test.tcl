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
