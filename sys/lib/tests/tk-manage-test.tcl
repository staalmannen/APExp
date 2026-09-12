# tk-manage-test.tcl -- "wm manage" makes a widget a toplevel, and
# "wm forget" turns it back.
#
# WHERE THIS CAME FROM: both were `return TCL_OK` -- silent no-ops --
# under a note in CLAUDE.md saying they were "real generic-Tk
# reparenting" and that doing them wrongly was worse than not doing
# them. Eight tests: wm-manage-1.1, 1.3..1.8, wm-forget-2, winWm-9.2.
#
# THE NOTE OVERSTATED IT. Upstream's WmManageCmd and WmForgetCmd are
# generic Tk with ONE X-specific step: they set TK_HAS_WRAPPER and
# reparent the frame into the wrapper just made for it. There are no
# wrappers in this port -- a toplevel IS its own window -- so the flag
# is not set and the reparent target is the ROOT, which is what being a
# toplevel means here. Same reduction as the embedding and stacking
# work.
#
# Everything else is shared and was already present: Tk_IsManageable,
# TkFocusSplit/TkFocusJoin, TkMapTopFrame, and TkWmDeadWindow ending
# with wmInfoPtr = NULL so a later "wm manage" starts clean.
#
# Runs under wish.

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

# ------------------------------------------------------------------
step "1. manage a frame (wm-manage-1.1)"

destroy .t
toplevel .t
frame .t.f
pack [label .t.f.l -text hello]
wm manage .t.f
raise .t.f
update
check "manager is wm"   [winfo manage .t.f]   wm
check "it is its own toplevel" [winfo toplevel .t.f] .t.f
check "and its child agrees"   [winfo toplevel .t.f.l] .t.f

# ------------------------------------------------------------------
step "2. a labelframe too (wm-manage-1.3)"

destroy .t2
toplevel .t2
labelframe .t2.f -text Labelframe
pack [label .t2.f.l -text hello]
wm manage .t2.f
raise .t2.f
update
check "manager is wm" [winfo manage .t2.f] wm
check "own toplevel"  [winfo toplevel .t2.f] .t2.f

# ------------------------------------------------------------------
step "3. WHAT MUST BE REFUSED (wm-manage-1.4, 1.5, 1.6)"

# Tk_IsManageable is the whole test: a ttk::frame, a text and a button
# are not frames, labelframes or toplevels, and "wm manage" on them has
# to RAISE AN ERROR rather than quietly succeed. Three of the eight
# failures were the refusal, not the action -- a silent no-op returns
# TCL_OK and so fails them in the same direction as doing nothing.
destroy .t3
toplevel .t3
text .t3.txt
button .t3.b -text Button
check "text is refused"   [catch {wm manage .t3.txt}] 1
check "button is refused" [catch {wm manage .t3.b}]   1
if {[catch {package require Tk::ttk}] && [catch {ttk::frame .t3.tf}]} {
    puts "  SKIP: no ttk::frame here"
} else {
    check "ttk::frame is refused" [catch {wm manage .t3.tf}] 1
}
check "the message names the three kinds" \
	[string match "*must be a frame, labelframe or toplevel*" \
		[catch {wm manage .t3.b} m; set m]] 1

# ------------------------------------------------------------------
step "4. manage, then forget, and pack it again (wm-manage-1.7)"

destroy .t4
toplevel .t4
frame .t4.f
pack [label .t4.f.l -text Label]
pack .t4.f
update
check "starts packed"      [winfo manage .t4.f]   pack
wm manage .t4.f
raise .t4.f
update
check "becomes wm"         [winfo manage .t4.f]   wm
check "becomes a toplevel" [winfo toplevel .t4.f] .t4.f
wm forget .t4.f
pack .t4.f
update
check "packed again"       [winfo manage .t4.f]   pack
check "a child again"      [winfo toplevel .t4.f] .t4

# ------------------------------------------------------------------
step "5. forget a REAL toplevel, and manage it back (wm-manage-1.8)"

# Both commands are called twice on purpose: the second must be a
# no-op, not an error and not a second teardown.
destroy .t5
toplevel .t5
toplevel .t5.t
pack [button .t5.t.b -text "Manage This"]
update
check "a toplevel to start"  [winfo manage .t5.t] wm
check "child's toplevel"     [winfo toplevel .t5.t.b] .t5.t
wm forget .t5.t
wm forget .t5.t
pack .t5.t
update
check "packs as a child now" [winfo manage .t5.t] pack
check "child's toplevel is the outer one" [winfo toplevel .t5.t.b] .t5
wm manage .t5.t
wm manage .t5.t
wm deiconify .t5.t
update
check "a toplevel again"     [winfo manage .t5.t] wm
check "child's toplevel again" [winfo toplevel .t5.t.b] .t5.t

# ------------------------------------------------------------------
step "6. the contents are still laid out afterwards (winWm-9.2)"

# winWm-9.2's real question: after manage/forget/repack, does a
# grandchild still land somewhere sensible? It checks rooty != 0.
destroy .t6
toplevel .t6
frame .t6.f
pack [button .t6.f.x -text x]
pack .t6.f
update
wm manage .t6.f
update
wm forget .t6.f
pack .t6.f
update
check "grandchild is not at the top of the screen" \
	[expr {[winfo rooty .t6.f.x] != 0}] 1

destroy .t .t2 .t3 .t4 .t5 .t6
puts ""
puts "failures: $failures"
exit $failures
