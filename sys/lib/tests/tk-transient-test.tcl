# tk-transient-test.tcl -- a transient follows its container's state.
#
# WHERE THIS CAME FROM: "wm transient" in plan9/tkPlan9Wm.c honoured the
# container's state only at the MOMENT OF THE CALL. Upstream also tracks
# it afterwards, with a StructureNotify handler registered on the
# container (tkUnixWm.c's WmWaitMapProc), so withdrawing the container
# withdraws the dialog and deiconifying it brings the dialog back. Five
# tests wanted that: wm-transient-3.3, 4.3, 5.1, 6.2 and 8.1.
#
# The one case that is NOT simply "follow the container" is 6.2: a
# transient the caller withdrew ITSELF must stay withdrawn when the
# container comes back. wmPtr->withdrawn cannot say which of the two
# withdrew it, so there is a second flag (withdrawnExplicit, upstream's
# WM_WITHDRAWN). Section 4 is that case, and it is the one a naive
# implementation gets wrong.
#
# Runs under wish. Section 6 needs tktest ("testwrapper") and says so
# rather than failing.
#
# Every marker is printed and flushed BEFORE the statement it names.

set failures 0

proc step {msg} { puts "STEP: $msg"; flush stdout }
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
proc note {name got} { puts "  note $name: $got"; flush stdout }

proc fresh {} {
    destroy .top .subject
    toplevel .top
    toplevel .subject
    update
    wm transient .subject .top
    update
}

# ------------------------------------------------------------------
step "1. withdraw/deiconify the container (wm-transient-3.3)"
fresh
wm withdraw .top
update
check "state after container withdraw"   [wm state .subject]      withdrawn
check "ismapped after container withdraw" [winfo ismapped .subject] 0
wm deiconify .top
update
check "state after container deiconify"   [wm state .subject]      normal
check "ismapped after container deiconify" [winfo ismapped .subject] 1

# ------------------------------------------------------------------
step "2. iconify/deiconify the container (wm-transient-4.3)"

# The transient goes WITHDRAWN, not iconic -- it is not the thing that
# was iconified.
#
# NOTE THE "update idletasks", WHICH IS THE WHOLE POINT OF THIS SECTION
# and is what 4.3 uses. It services idle handlers, NOT events -- so a
# first version of this that tracked the container with an event handler
# passed section 1 (which says "update") and failed here. The state
# change has to have happened by the time the command returns.
fresh
wm iconify .top
update idletasks
check "state after container iconify"   [wm state .subject]      withdrawn
check "ismapped after container iconify" [winfo ismapped .subject] 0
wm deiconify .top
update idletasks
check "state after container deiconify"  [wm state .subject]      normal

step "2a. and with NO update at all (wm-transient-6.2 reads it so)"
fresh
wm withdraw .top
check "state immediately after container withdraw" [wm state .subject] withdrawn
wm deiconify .top
check "state immediately after container deiconify" [wm state .subject] normal
update

# ------------------------------------------------------------------
step "3. a failed 'wm transient' must not lose the tracking (5.1)"

# "wm transient .subject .bad" is an error, and the handler registered
# for the GOOD container has to survive it -- which it does only if the
# error returns before anything is unregistered.
fresh
check "bad container is an error" [catch {wm transient .subject .bad}] 1
wm withdraw .top
update
check "still tracking after the error" [wm state .subject] withdrawn
wm deiconify .top
update
check "still tracking, the other way"  [wm state .subject] normal

# ------------------------------------------------------------------
step "4. a transient withdrawn BY THE CALLER does not track (6.2)"
fresh
wm withdraw .subject
wm withdraw .top
wm deiconify .top
update
check "container back, transient stays withdrawn" [wm state .subject] withdrawn
wm deiconify .subject
check "deiconified by hand"                       [wm state .subject] normal
wm withdraw .top
update
check "and tracks again once it is normal"        [wm state .subject] withdrawn
wm deiconify .top
update
check "back with its container"                   [wm state .subject] normal

# ------------------------------------------------------------------
step "5. transient of a container that is withdrawn already (8.1)"
destroy .t1 .t2
toplevel .t1; wm withdraw .t1; update
toplevel .t2; wm transient .t2 .t1; update
check "neither mapped" \
	[list [winfo ismapped .t1] [winfo ismapped .t2]] {0 0}
wm deiconify .t1
update
check "both mapped once the container is shown" \
	[list [winfo ismapped .t1] [winfo ismapped .t2]] {1 1}
check "both in the stacking order" \
	[lsearch -all -inline -glob [wm stackorder .] ".t?"] {.t1 .t2}

# A transient stays ABOVE the window it belongs to, and moves with it.
# On X the window manager enforces this; here TkWmRestackToplevel does,
# and without it "raise .t1" reads back as {.t2 .t1}.
raise .t1
update
check "raising the container keeps the transient above it" \
	[lsearch -all -inline -glob [wm stackorder .] ".t?"] {.t1 .t2}

# ------------------------------------------------------------------
step "6. destroy the container while it is being tracked"

# The tracking walks dispPtr->firstWmPtr at map and unmap time, so a
# destroyed end has to be off that list or out of the container field
# before anything maps again -- the use-after-free shape this port has
# hit three times (TkpDeleteFont, TkpFreeColor, the menubar). The first
# version of this used an event handler holding the transient as client
# data, which had the same hazard in a worse place.
fresh
destroy .top
update
check "transient forgets a destroyed container" [wm transient .subject] {}
step "6a. map and unmap the survivor, which is what would touch it"
wm withdraw .subject
update
wm deiconify .subject
update
puts "  ok: no fault"
flush stdout

step "6b. the other order: destroy the TRANSIENT first"
fresh
destroy .subject
update
wm withdraw .top
update
wm deiconify .top
update
puts "  ok: no fault"
flush stdout

# ------------------------------------------------------------------
step "7. wm group creates the leader's window (unixWm-21.5)"

# Upstream's WmGroupCmd calls Tk_MakeWindowExist on the leader and then
# creates its wrapper, because the group hint has to name a window id.
# There are no wrappers here -- a toplevel IS its window -- so the first
# half alone is the whole of it, and "testwrapper" is how the suite
# looks at it.
destroy .t2 .t3
toplevel .t2 -width 120 -height 300
toplevel .t3 -width 120 -height 300
if {[catch {testwrapper .t2} before]} {
    puts "  SKIP: no testwrapper command -- run this with tktest for section 7"
} else {
    check "leader has no window before" $before {}
    wm group .t3 .t2
    check "leader has a window after"   [expr {[testwrapper .t2] ne ""}] 1
    check "group reads back"            [wm group .t3] .t2
}
destroy .t2 .t3

destroy .top .subject .t1 .t2
puts ""
puts "failures: $failures"
exit $failures
