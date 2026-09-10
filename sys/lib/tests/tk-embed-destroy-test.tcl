# Does a destroyed container leave a dangling pointer behind?
#
#	wish tk-embed-destroy-test.tcl
#
# WHERE THIS COMES FROM. The Tk suite runs all 97 files and then wish
# dies at the very end, always at the same address:
#
#	==== xmfbox-2.6 FAILED
#	wish 16510: suicide: sys: trap: general protection violation
#	                                pc=0x26f694
#
# acid resolves that -- statically, on the binary, with no process, so
# the "acid fights wish for the rio window" warning in CLAUDE.md does
# not apply:
#
#	acid /bin/wish
#	acid: src(0x26f694)
#	.../tk/generic/tkGeometry.c:153
#
# which is Tk_GeometryRequest:
#
#	148  if ((reqWidth == winPtr->reqWidth) && ...) return;
#	151  winPtr->reqWidth = reqWidth;
#	152  winPtr->reqHeight = reqHeight;
#	153> if ((winPtr->geomMgrPtr != NULL)
#	154      && (winPtr->geomMgrPtr->requestProc != NULL)) {
#
# READ THE SHAPE OF THAT FAULT, because it says more than the line
# number does. Lines 148, 151 and 152 read and WRITE through winPtr
# without faulting, and only 153/154 die. A null or unmapped winPtr
# would have faulted at 148. APE's malloc never unmaps a freed block
# (see the malloc note in CLAUDE.md), so a freed TkWindow is still
# perfectly readable and writable -- and the first thing that actually
# fails is the POINTER CHASE through a garbage geomMgrPtr to reach
# requestProc.
#
# So this is a use-after-free of a TkWindow, not a null dereference,
# and "it wrote to the struct first" is not evidence that the struct
# was alive.
#
# THE SUSPECT, and it is a suspect rather than a conclusion. The one
# place in plan9/tkPlan9Wm.c that calls Tk_GeometryRequest on a STORED
# window pointer is TkP9EmbedGeometryRequest:
#
#	containerPtr = FindContainerByEmbedded(winPtr);
#	if (containerPtr == NULL || containerPtr->parentPtr == NULL)
#		return;
#	Tk_GeometryRequest((Tk_Window) containerPtr->parentPtr, w, h);
#
# containerPtr->parentPtr is cleared by EmbedWindowDeleted when the
# container is destroyed, so for it to dangle EmbedWindowDeleted must
# not have run. And there is a hole big enough for that:
#
#	Tk_MakeContainer registers ContainerEventProc with WINPTR as its
#	client data, and the proc opens with
#
#		containerPtr = FindContainer(winPtr->window);
#		if (containerPtr == NULL)
#			return;		<- cleanup skipped
#
#	Upstream's equivalent (unix/tkUnixEmbed.c EmbedStructureProc)
#	registers the Container* ITSELF as the client data, so it never
#	looks anything up and can never fail to find it.
#
# That is a real difference from upstream and a real hole. It is NOT
# yet shown to be this crash: the suite leaves roughly thirty
# toplevels alive at exit -- safe.test's "Untrusted Tcl applet"
# containers among them -- and teardown touches all of them, so there
# is more than one way to reach a dead window. This file is here to
# make the answer a printed line rather than an argument.
#
# ORDER: every case that should survive comes before any case that
# might not, and each prints a flushed marker BEFORE it runs, so the
# last STEP line names the statement that killed wish. That rule is in
# CLAUDE.md because ignoring it has cost whole round trips.

proc step {m} { puts "STEP: $m"; flush stdout }
proc ok   {m} { puts "   ok: $m"; flush stdout }

proc state {what} {
    foreach w {.c .c.f .e} {
	if {[winfo exists $w]} {
	    puts "     $w exists, [winfo class $w],\
 [winfo width $w]x[winfo height $w]"
	} else {
	    puts "     $w gone"
	}
    }
    flush stdout
}

# A container and an embedded toplevel, the way safe::loadTk builds
# them: a frame with -container 1, and a toplevel with -use naming it.
proc pair {} {
    destroy .c .e
    toplevel .c
    pack [frame .c.f -container 1 -width 200 -height 150]
    update
    toplevel .e -use [winfo id .c.f]
    update
}

step "1. build a container/embedded pair at all"
pair
state "after build"
ok "built"

step "2. ask the embedded window to resize -- the ordinary path\
 through TkP9EmbedGeometryRequest, with both halves alive"
.e configure -width 120 -height 90
update
ok "resize returned"

step "3. destroy the EMBEDDED half, then poke the container"
pair
destroy .e
update
.c.f configure -width 210 -height 160
update
state "after destroying .e"
ok "returned"

# ------------------------------------------------------------------
# The suspicious one. Destroying the container should reach
# EmbedWindowDeleted and clear containerPtr->parentPtr; if it does not,
# the next geometry request from the embedded half calls
# Tk_GeometryRequest on freed memory.
#
# Note the request has to be provoked: simply destroying the container
# proves nothing, because nothing dereferences the stale pointer until
# something asks for a resize.
step "4. destroy the CONTAINER half, then provoke a geometry request\
 from the embedded half -- if parentPtr dangles this is the crash"
pair
destroy .c
update
state "after destroying .c"
if {[winfo exists .e]} {
    .e configure -width 130 -height 100
    update
    ok "the embedded half survived its container"
} else {
    ok "the embedded half went with its container, so nothing to poke"
}

step "5. the same, but destroying the container's TOPLEVEL rather than\
 the -container frame, so the frame dies as part of a subtree"
destroy .c .e
toplevel .c
pack [frame .c.f -container 1 -width 200 -height 150]
update
toplevel .e -use [winfo id .c.f]
update
destroy .c
update
state "after destroying the container toplevel"
if {[winfo exists .e]} {
    .e configure -width 140 -height 110
    update
}
ok "returned"

# ------------------------------------------------------------------
# Teardown, which is where the suite actually dies: many pairs alive at
# once, destroyed in whatever order Tk picks rather than by hand.
step "6. five live pairs, then destroy them all in one go -- this is\
 the shape of the suite's exit, where ~30 toplevels are still up"
destroy .c .e
for {set i 0} {$i < 5} {incr i} {
    toplevel .c$i
    pack [frame .c$i.f -container 1 -width 120 -height 90]
    update
    toplevel .e$i -use [winfo id .c$i.f]
    update
}
ok "five pairs built"

step "6b. ... destroy every container first, embedded halves last"
for {set i 0} {$i < 5} {incr i} { destroy .c$i }
update
ok "containers destroyed"
for {set i 0} {$i < 5} {incr i} { if {[winfo exists .e$i]} { destroy .e$i } }
update
ok "returned"

step "7. and the real exit path: build five more and let Tk tear them\
 down itself"
for {set i 0} {$i < 5} {incr i} {
    catch {destroy .c$i .e$i}
    toplevel .c$i
    pack [frame .c$i.f -container 1 -width 120 -height 90]
    update
    toplevel .e$i -use [winfo id .c$i.f]
    update
}
ok "built; exiting now, which destroys them in Tk's own order"

puts ""
puts "reached the end -- nothing crashed"
flush stdout
exit 0
