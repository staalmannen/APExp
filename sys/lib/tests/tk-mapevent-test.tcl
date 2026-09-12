# tk-mapevent-test.tcl -- ONE MapNotify per map, ONE UnmapNotify per unmap.
#
# WHERE THIS CAME FROM: for the whole life of this port, every <Map> and
# <Unmap> binding on an ordinary widget fired TWICE. textWind-12.1 is
# what said so:
#
#	got   created mapped mapped modified replaced unmapped unmapped ...
#	want  created mapped        modified replaced unmapped        ...
#
# WHY. Generic Tk synthesises these events itself for the windows an X
# server would not report to it -- the server only tells a client about
# a window it selected StructureNotifyMask on. So the platform's job is
# exactly the COMPLEMENT, and generic/tkWindow.c states it twice with
# two different flags:
#
#	Tk_MapWindow    hands TK_WIN_MANAGED to TkWmMapWindow and
#			returns; everything else it maps and then
#			synthesises MapNotify for.
#	Tk_UnmapWindow  hands TK_WIN_MANAGED to TkWmUnmapWindow, and
#			synthesises UnmapNotify only when !TK_TOP_HIERARCHY.
#
# So XMapWindow reports iff TK_WIN_MANAGED and XUnmapWindow iff
# TK_TOP_HIERARCHY. The asymmetry is upstream's and is what covers an
# EMBEDDED toplevel, which has TK_TOP_HIERARCHY without TK_WIN_MANAGED.
# plan9/tkPlan9Init.c sent both unconditionally.
#
# THE COUNT IS THE WHOLE TEST. A binding that fires twice looks exactly
# like one that fires once unless something is counting, which is why
# this went unnoticed through twelve suite runs -- nothing else in
# sys/lib/tests counts an event.
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

# Count Map and Unmap on one window, for one action.
proc counts {w script} {
    upvar #0 __mapn n __unmapn u
    set n 0
    set u 0
    bind $w <Map>   {incr ::__mapn}
    bind $w <Unmap> {incr ::__unmapn}
    uplevel 1 $script
    update
    bind $w <Map>   {}
    bind $w <Unmap> {}
    return [list $::__mapn $::__unmapn]
}

# ------------------------------------------------------------------
step "1. an ordinary child widget (textWind-12.1's case)"

destroy .f
frame .f -width 60 -height 40 -bg red
update
check "pack a frame"     [counts .f {pack .f}]           {1 0}
check "pack forget"      [counts .f {pack forget .f}]    {0 1}
check "pack it again"    [counts .f {pack .f}]           {1 0}

# ------------------------------------------------------------------
step "2. a child two levels down"

destroy .outer
frame .outer -width 100 -height 80
pack .outer
frame .outer.in -width 40 -height 30 -bg green
update
check "place the inner frame" \
	[counts .outer.in {place .outer.in -x 5 -y 5}] {1 0}
check "place forget" \
	[counts .outer.in {place forget .outer.in}]    {0 1}

# ------------------------------------------------------------------
step "3. a TOPLEVEL, which is the other arm and must still report"

# Nothing synthesises these for a toplevel -- Tk_MapWindow returns
# early for TK_WIN_MANAGED -- so the port is the only source. A gate
# that silenced these would be the menubar freeze all over again.
destroy .t
toplevel .t -width 120 -height 80
update
check "wm withdraw"  [counts .t {wm withdraw .t}]  {0 1}
check "wm deiconify" [counts .t {wm deiconify .t}] {1 0}

# ------------------------------------------------------------------
step "4. a window in a text widget (textWind-12.1 exactly)"

destroy .t2 .w
text .t2
pack .t2
.t2 insert 1.0 "Some sample text"
frame .w -width 30 -height 20 -bg blue
update
check "window create in a text" \
	[counts .w {.t2 window create 1.2 -window .w}] {1 0}
check "unset the window" \
	[counts .w {.t2 window configure .w -window {}}] {0 1}

# ------------------------------------------------------------------
step "5. tkwait visibility still returns (the thing NOT to break)"

# VisibilityNotify is sent unconditionally and is a separate event from
# MapNotify -- "tkwait visibility" and the deferred "focus -force" path
# both wait on it. Gating the map events must not have touched it.
destroy .t3
toplevel .t3 -width 80 -height 60
frame .t3.f -width 40 -height 30
place .t3.f -x 5 -y 5
step "5a. tkwait visibility on a CHILD -- hangs if Visibility was lost"
tkwait visibility .t3.f
puts "  ok: it returned"
flush stdout

destroy .f .outer .t .t2 .w .t3
puts ""
puts "failures: $failures"
exit $failures
