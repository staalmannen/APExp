# What "wm" stores, what it refuses, and what it reports back.
#
#	wish tk-wm-test.tcl
#
# WHERE THIS COMES FROM. wm.test and unixWm.test were 121 of the 268
# failures left in Tk's suite, and reading all 121 gave a much better
# answer than the number: NONE of them needs a second wish, none needs
# tktest, and only four carry upstream's own "failsOnUbuntu
# failsOnXQuartz". That is the opposite of select/unixSelect/systray,
# where 103 of 106 needed something this machine does not have.
#
# The reason is structural and worth remembering before reading any wm
# failure as a platform limit: "wm" is a QUERY AND VALIDATE surface.
# rio makes most of these operations do nothing on the screen, and that
# is irrelevant to what the tests check -- they set a value and read it
# back, or pass a bad argument and expect a particular message.
#
# So the failures split into clusters that are all bookkeeping:
#
#	~35  argument validation	"wm minsize . a" succeeded
#	 15  negative geometry		"-0-0" read back as "+0+0"
#	~12  icon windows		wm state never said "icon"
#	~10  wm transient tracking
#	  8  wm manage / wm forget	real reparenting, not done here
#	  6  wm resizable		never stored at all
#	  5  wm colormapwindows		never maintained
#
# THIS FILE COVERS THE FIRST THREE plus the singles, which is what has
# been implemented so far. Each section is one cluster and reports
# PASS/FAIL per case, so a regression names the rule it broke rather
# than a test number in someone else's suite.
#
# THE RULE THIS FILE EXISTS TO PROTECT, and the one this port has got
# wrong more than any other: A STUB THAT ANSWERS PLAUSIBLY IS WORSE
# THAN ONE THAT ADMITS IT DID NOTHING. "wm resizable" answered "1 1" to
# every query, "wm geometry .b" on a button answered "1x1+0+0", "wm
# minsize . a" succeeded. Every one of those is a believable answer to
# a question that should have been refused or answered truthfully, and
# nothing upstream can tell.

set fails 0

proc ok {name got want} {
    global fails
    if {$got eq $want} {
	puts "PASS $name"
    } else {
	puts "FAIL $name"
	puts "       got  '$got'"
	puts "       want '$want'"
	incr fails
    }
}

# Expect an error, and check its message.
proc err {name script want} {
    global fails
    if {[catch {uplevel 1 $script} msg]} {
	if {$msg eq $want} {
	    puts "PASS $name"
	} else {
	    puts "FAIL $name (right to refuse, wrong message)"
	    puts "       got  '$msg'"
	    puts "       want '$want'"
	    incr fails
	}
    } else {
	puts "FAIL $name (no error at all; answered '$msg')"
	incr fails
    }
}

proc fresh {} {
    foreach w [winfo children .] { destroy $w }
    update
}

puts "--- 1. a non-toplevel is refused ONCE, for every subcommand ---"
# This used not to happen at all: wmInfoPtr was NULL for such a window
# and every case guarded on it and returned TCL_OK. wm-1.5, unixWm-11.4,
# wm-iconbadge-1.2.
fresh
button .b -text hello
frame .f
err "geometry on a button" {wm geometry .b} \
    {window ".b" isn't a top-level window}
err "iconbadge on a frame" {wm iconbadge .f 3} \
    {window ".f" isn't a top-level window}
err "state on a button"    {wm state .b} \
    {window ".b" isn't a top-level window}
# ... but the two whose whole job is to take one must still reach it.
ok "manage is exempt" [expr {[catch {wm manage .f}] ? "refused" : "reached"}] \
    "reached"
fresh

puts ""
puts "--- 2. argument validation ---"
err "minsize, too few"   {wm minsize . a} \
    {wrong # args: should be "wm minsize window ?width height?"}
err "minsize, too many"  {wm minsize . a b c} \
    {wrong # args: should be "wm minsize window ?width height?"}
# A SCREEN DISTANCE, not an integer -- "wm minsize . 10c" is legal, and
# the message says "screen distance" (wm-minsize-1.4).
err "minsize, not a distance" {wm minsize . x 10} \
    {expected screen distance but got "x"}
ok  "minsize accepts a distance" \
    [expr {[catch {wm minsize . 10 10}] ? "refused" : "ok"}] "ok"
err "resizable, one arg"  {wm resizable . 1} \
    {wrong # args: should be "wm resizable window ?width height?"}
err "resizable, not bool" {wm resizable . bad 0} \
    {expected boolean value but got "bad"}
err "withdraw, extra arg" {wm withdraw . _} \
    {wrong # args: should be "wm withdraw window"}
err "deiconify, extra arg" {wm deiconify . _} \
    {wrong # args: should be "wm deiconify window"}
err "frame, extra arg"    {wm frame . _} \
    {wrong # args: should be "wm frame window"}
err "state, extra arg"    {wm state . _ _} \
    {wrong # args: should be "wm state window ?state?"}
# ALPHABETICAL: Tcl builds this message by listing the table in order,
# and the test checks it verbatim (unixWm-35.1.1).
err "state, bad value"    {wm state . 1} \
    {bad argument "1": must be iconic, normal, or withdrawn}
# FOUR SEPARATE MESSAGES, one per argument -- naming the argument that
# is wrong is the whole value of the diagnostic (wm-grid-1.9..1.12).
err "grid baseWidth"  {wm grid . -1 1 1 1} {baseWidth can't be < 0}
err "grid baseHeight" {wm grid . 1 -1 1 1} {baseHeight can't be < 0}
err "grid widthInc"   {wm grid . 1 1 0 1}  {widthInc can't be <= 0}
err "grid heightInc"  {wm grid . 1 1 1 0}  {heightInc can't be <= 0}
wm grid . {} {} {} {}
err "iconphoto, not a photo" {wm iconphoto . notanimage} \
    {can't use "notanimage" as iconphoto: not a photo image}
err "attributes, unknown" {wm attributes . -nosuchthing} \
    {bad attribute "-nosuchthing": must be -alpha, -fullscreen, -topmost, -type, or -zoomed}

puts ""
puts "--- 3. wm resizable is stored, not answered '1 1' ---"
# It used to answer a hardcoded "1 1" to every query. Nothing here can
# stop a user resizing a window -- rio owns the frame -- but what the
# caller set is still what a query has to report (wm-resizable-2.1,
# unixWm-33.6).
fresh
toplevel .t
set r {}
foreach pair {{0 0} {0 1} {1 0} {1 1}} {
    wm resizable .t {*}$pair
    lappend r [wm resizable .t]
}
ok "resizable round-trips" $r {{0 0} {0 1} {1 0} {1 1}}
fresh

puts ""
puts "--- 4. negative geometry keeps its sign ---"
# X geometry has a SIGN as well as a value: "-10+5" is ten pixels from
# the RIGHT edge. sscanf could not tell "+0" from "-0" once the value
# was an int, so all four corners stored 0,0 and read back "+0+0".
# unixWm-2.4..2.9.
fresh
toplevel .t -width 100 -height 50
update
set r {}
foreach g {+0+0 -0-0 +0-0 -0+0 -10-5 -10+5 +10-5} {
    wm geometry .t $g
    # only the position half, since the size is whatever it settled on
    regexp {[-+][0-9]+[-+][0-9]+$} [wm geometry .t] pos
    lappend r $pos
}
ok "every corner round-trips" $r {+0+0 -0-0 +0-0 -0+0 -10-5 -10+5 +10-5}

# A negative offset is resolved against the SCREEN, and the far edge is
# what it is measured to -- so the left edge is screenwidth - width - 10
# (unixWm-44.7, 44.8).
wm geometry .t 121x50-10+5
update
ok "negative x lands near the right edge" \
    [expr {[winfo rootx .t] == [winfo screenwidth .] - 121 - 10}] 1

puts ""
puts "--- 5. the geometry parser ---"
# "=" is part of the standard X geometry syntax and optional by
# definition; trailing junk is not (unixWm-48.1, 48.10).
ok "leading = is accepted" \
    [expr {[catch {wm geometry .t =100x120}] ? "refused" : "ok"}] "ok"
err "trailing junk is refused" {wm geometry .t +20+10z} \
    {bad geometry specifier "+20+10z"}
# Nothing is written until the whole string parses, so a bad specifier
# must leave the window exactly as it was.
wm geometry .t 100x120+30+40
catch {wm geometry .t +20+10z}
ok "a refused specifier changes nothing" [wm geometry .t] {100x120+30+40}
fresh

puts ""
puts "--- 6. icon windows ---"
# A window named by someone else's "wm iconwindow". On X the window
# manager draws it while the toplevel is iconified; rio has no icons, so
# nothing is drawn -- but the STATE is real and is what is asked about.
fresh
toplevel .t
toplevel .icon -width 50 -height 50
update
wm iconwindow .t .icon
update
ok "state is 'icon', not 'withdrawn'" [wm state .icon] icon
ok "and it is off the screen"         [winfo ismapped .icon] 0
ok "the holder reports it"            [wm iconwindow .t] .icon

# It is no longer its own to show or hide. Note the quoting differs by
# subcommand and that is upstream's, not a slip: iconify quotes both
# names, withdraw and deiconify quote neither.
err "can't withdraw an icon"  {wm withdraw .icon} \
    {can't withdraw .icon: it is an icon for .t}
err "can't deiconify an icon" {wm deiconify .icon} \
    {can't deiconify .icon: it is an icon for .t}
err "can't iconify an icon"   {wm iconify .icon} \
    {can't iconify ".icon": it is an icon for ".t"}
err "can't change its state"  {wm state .icon withdrawn} \
    {can't change state of .icon: it is an icon for .t}

toplevel .t2
err "and it is not free to be reused" {wm iconwindow .t2 .icon} \
    {.icon is already an icon for .t}

# Releasing it clears both ends.
wm iconwindow .t {}
ok "released: state" [wm state .icon] withdrawn
ok "released: holder" [wm iconwindow .t] {}
ok "released: can withdraw again" \
    [expr {[catch {wm withdraw .icon}] ? "refused" : "ok"}] "ok"

# DESTROYING EITHER END MUST CLEAR THE OTHER, or the survivor holds a
# freed WmInfo -- and on this allocator a freed block stays readable, so
# the first thing that would fail is the pathName chase inside an error
# message, a long way from here.
wm iconwindow .t .icon
destroy .icon
ok "destroying the icon clears the holder" [wm iconwindow .t] {}
fresh

puts ""
puts "--- 7. iconify refuses what it cannot iconify ---"
fresh
toplevel .t2
wm overrideredirect .t2 1
err "override-redirect" {wm iconify .t2} \
    {can't iconify ".t2": override-redirect flag is set}
fresh
toplevel .t
frame .t.f -container 1
pack .t.f
toplevel .embed -use [winfo id .t.f]
update
err "embedded, iconify"   {wm iconify .embed} \
    {can't iconify ".embed": it is an embedded window}
err "embedded, deiconify" {wm deiconify .embed} \
    {can't deiconify .embed: it is an embedded window}
fresh

puts ""
puts "--- 8. deiconify clears iconified, not just withdrawn ---"
# It used to clear only the latter, so a window was shown again and went
# on reporting that it was not (unixWm-16.3, 35.3, wm-state-2.15/2.17).
fresh
toplevel .t
update
wm iconify .t
ok "iconified"   [wm state .t] iconic
wm deiconify .t
ok "and back"    [wm state .t] normal
fresh

puts ""
puts "--- 9. wm transient refuses loops of any length ---"
# The self case is not the only loop: "a transient of b, b transient of
# a" is one too, and the old "can't make %s its own master" caught only
# the first and used the wrong message for it (wm-transient-1.7..1.9).
fresh
toplevel .top
frame .top.f
err "its own container" {wm transient .top .top} \
    {can't set ".top" as container: would cause management loop}
err "via a child frame" {wm transient .top .top.f} \
    {can't set ".top" as container: would cause management loop}
toplevel .t1
toplevel .t2
wm transient .t2 .t1
err "a two-step loop"   {wm transient .t1 .t2} \
    {can't set ".t2" as container: would cause management loop}
# The container resolves to its nearest TOPLEVEL ancestor and reads back
# as that, not as the frame that was named.
toplevel .t3
wm transient .t3 .top.f
ok "resolved to the toplevel" [wm transient .t3] .top

# A DESTROYED CONTAINER LEAVES NO TRANSIENTS BEHIND: the query must
# answer empty, not the name of a window that is gone (wm-transient-5.2,
# 5.3, 7.2) -- and the stored pointer would otherwise dangle.
destroy .top
ok "container destroyed" [wm transient .t3] {}
fresh

puts ""
puts "--- 10. wm attributes reports in alphabetical order ---"
# That is the order X reports them in, and unixWm-60.1.1 compares the
# whole string.
ok "order" [wm attributes .] \
    {-alpha 1.0 -fullscreen 0 -topmost 0 -type {} -zoomed 0}

puts ""
if {$fails == 0} {
    puts "all cases passed"
} else {
    puts "$fails case(s) failed"
}
flush stdout
exit $fails
