# Which line of scrollbar-10.1 spins?
#
#	wish tk-scrollbar-hang-test.tcl
#
# The Tk suite never finishes: it wedges in scrollbar.test with the CPU
# pinned and nothing written. "tk-runall.tcl -file scrollbar.test
# -verbose t" named the test, because -verbose t prints each name as it
# STARTS:
#
#	---- scrollbar-9.1 start
#	---- scrollbar-10.1 start
#	<nothing ever again>
#
# scrollbar-10.1 is
#
#	pack [text .t -yscrollcommand {.s set}] -side left
#	for {set i 1} {$i < 100} {incr i} {.t insert end "Line $i\n"}
#	pack [scrollbar .s -command {.t yview}] -fill y -expand 1 -side left
#	update
#	focus -force .s
#	event generate .s <Enter>
#	event generate .s <MouseWheel> -delta -120
#	after 200 {set eventprocessed 1} ; vwait eventprocessed
#	.t index @0,0
#
# and every one of those lines is a candidate, so this runs them one at
# a time with a flushed marker BEFORE each. Whatever the last STEP line
# says is the statement that did not return. The technique is
# tk-widget-test.tcl's, which is what worked the last three times
# something in this port hung rather than crashed.
#
# WHAT THE CPU TELLS US, and why it matters here: the meter stays high
# while it is wedged. A blocked read -- a pipe, /dev/mouse, a child that
# never answers -- would be idle. So it is a loop, and the two shapes
# worth telling apart are
#
#   - a loop inside one Tk call that never returns to the event loop
#     (text layout is the candidate: tkTextDisp.c lays out 99 lines
#     through Tk_MeasureChars, which this port rewrote for font-24.*,
#     and a measure that reports zero progress makes the caller spin);
#   - a loop THROUGH the event loop, where an event is regenerated as
#     fast as it is drained. DisplaySetupProc sets a zero maximum block
#     time whenever TkP9EventsPending(), so that pins the CPU exactly
#     like this -- and it is the 100% CPU spin this port already had
#     once, when the block time was zero unconditionally.
#
# Sections 1 and 2 separate them. If plain text layout hangs with no
# scrollbar attached, it is the first; if it only hangs once the two
# widgets are wired to each other, it is the second.
#
# DO NOT add an "update" that is not in the original: the point is to
# reproduce the test's own sequence, and update is itself one of the
# suspects.

proc step {msg} {
    puts "STEP: $msg"
    flush stdout
}

proc done {msg} {
    puts "   ok: $msg"
    flush stdout
}

# ------------------------------------------------------------------
step "1a. a text widget with ONE line, no scrollbar, no wiring"
destroy .t
pack [text .t] -side left
.t insert end "Line 1\n"
done "created and inserted"
step "1b. update on it"
update
done "update returned"

step "1c. 99 more lines into the same widget"
for {set i 2} {$i < 100} {incr i} {.t insert end "Line $i\n"}
done "inserted"
step "1d. update after 99 lines -- text layout alone, nothing wired"
update
done "update returned; text layout on its own is fine"
destroy .t

# ------------------------------------------------------------------
puts ""
step "2a. the test's own first line: text WITH -yscrollcommand naming\
 a scrollbar that does not exist yet"
destroy .t .s
pack [text .t -yscrollcommand {.s set}] -side left
done "packed"

step "2b. 99 lines into it (the yscrollcommand fires into nothing)"
for {set i 1} {$i < 100} {incr i} {.t insert end "Line $i\n"}
done "inserted"

step "2c. pack the scrollbar, wiring the loop shut"
pack [scrollbar .s -command {.t yview}] -fill y -expand 1 -side left
done "packed"

step "2d. update -- both widgets now feed each other"
update
done "update returned"

# ------------------------------------------------------------------
puts ""
step "3. focus -force .s"
focus -force .s
done "focus returned"

step "4. event generate .s <Enter>"
event generate .s <Enter>
done "Enter generated"

step "5. event generate .s <MouseWheel> -delta -120"
event generate .s <MouseWheel> -delta -120
done "MouseWheel generated (queued, not yet delivered)"

step "6. after 200 + vwait -- this is where a queued event is DELIVERED,\
 and where an event loop that never sleeps would show"
after 200 {set eventprocessed 1}
vwait eventprocessed
done "vwait returned"

step "7. .t index @0,0  (the test wants 4.0)"
set idx [.t index @0,0]
done "index is $idx"

puts ""
puts "reached the end; scrollbar-10.1's sequence completed"
flush stdout
destroy .t .s
exit 0
