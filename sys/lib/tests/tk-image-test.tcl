# Do pixels survive the trip out of a drawable and back?
#
#	wish tk-image-test.tcl
#	TKP9DEBUG=1 wish tk-image-test.tcl        (prints the RGBA order)
#
# XGetImage and XPutImage were both stubs until now, so no pixel had
# ever made this trip: "canvas image" could not work (canvas-23.* failed
# with "failed to copy Pixmap to XImage") and no photo image drew at
# all, since TkPutImage is how Tk paints one.
#
# With them implemented, canvas-23.2 passes and 23.1 and 23.3 do not.
# The first guess was a red/blue swap, because the three differ only in
# colour -- 23.1 blue, 23.2 green, 23.3 red -- and green is the middle
# byte, invariant under exchanging the other two.
#
# THAT WAS WRONG, and section 1 is what refuted it: every colour makes
# the trip exactly, red and blue included, and under $TKP9DEBUG the
# port reports
#
#	tkp9: RGBA32 memory order R=3 G=2 B=1 A=0
#
# which is A,B,G,R -- the documented order, measured correctly by
# rgbacalibrate(). The byte order was never wrong.
#
# Section 2 has the real answer, and it is not a colour at all: the
# filled column reads back as the BACKGROUND. The rectangle is not
# drawn. What separates the three tests is not their colour but their
# shape:
#
#	23.1  rectangle 0 0 0 9   zero width    FAIL
#	23.2  rectangle 0 0 1 9   width 1       pass
#	23.3  rectangle 0 0 9 0   zero height   FAIL
#
# The SECOND wrong guess was that a zero-width rectangle reaches the
# platform and has to be drawn as a line. It does not: tkRectOval.c
# widens a degenerate box itself, "x1 -= 1" here, so what arrives is one
# pixel wide starting at -1.
#
# The answer is X's outline convention. XDrawRectangle draws a
# five-point path through the corners, so it covers w+1 by h+1 pixels --
# and for this item the fill lands on column -1, off the canvas, while
# column 0 is painted by that extra outline pixel and by nothing else.
# Plan 9's border() draws inside the rectangle it is given, one short.
#
# Three differences between these tests (colour, width, height) and only
# the third mattered. Both wrong guesses fitted the evidence.
#
# Section 3 is still open: a photo drawn onto the canvas reads back as
# the canvas background, so nothing of it rendered, even though a photo
# does now draw on screen. That is XPutImage or the path from the photo
# instance to it, and it is a separate question from the rectangle.
#
# Run with $TKP9DEBUG to see the measured order:
#
#	tkp9: RGBA32 memory order R=? G=? B=? A=?

set fail 0

proc note {m} { puts $m; flush stdout }

proc ok {cond what} {
    global fail
    if {[uplevel 1 [list expr $cond]]} {
	note "  PASS $what"
    } else {
	note "  FAIL $what"
	incr fail
    }
}

# Read the canvas back into a photo and return the pixel at (x,y).
proc pixelat {x y} {
    catch {image delete probe}
    image create photo probe
    .c image probe
    set row [lindex [probe data] $y]
    return [lindex $row $x]
}

canvas .c
pack .c
update

note "--- 1. a primary colour out and back ---"
note "  (green is invariant under a red/blue swap; red and blue are not)"
foreach {name want} {red #ff0000 green #00ff00 blue #0000ff
                     navy #000080 maroon #800000 grey #c0c0c0} {
    .c configure -background $want -scrollregion {0 0 9 9}
    update
    set got [pixelat 5 5]
    note "  $name: drew $want, read back $got"
    ok {$got eq $want} "$name survives the round trip"
}

note ""
note "--- 2. the canvas-23.1 case exactly ---"
.c configure -background #c0c0c0 -scrollregion {0 0 9 9}
.c create rectangle 0 0 0 9 -fill #000080 -outline #000080
update
set left [pixelat 0 0]
set right [pixelat 5 0]
note "  column 0 (filled #000080): $left"
note "  column 5 (background #c0c0c0): $right"
ok {$left eq "#000080"} "the filled column reads back #000080"
ok {$right eq "#c0c0c0"} "the background reads back #c0c0c0"

note ""
note "--- 3. a photo drawn INTO the canvas, i.e. XPutImage ---"
# The other direction: put a known photo on the canvas and read it back.
# This is a round trip through both halves, so it passes even if both
# are wrong by the same permutation -- which is exactly why section 1
# and 2 above, which only read, are the ones that decide.
image create photo src -width 4 -height 4
src put #123456 -to 0 0 4 4
.c delete all
.c configure -background #ffffff
.c create image 0 0 -anchor nw -image src
update
set got [pixelat 1 1]
note "  put #123456 as a photo, read back $got"
ok {$got eq "#123456"} "a photo round-trips through put and get"

note ""
note "Section 1 passing means the byte order is right -- that was the"
note "first guess and it was wrong. Section 2 is the one that matters:"
note "XDrawRectangle covers w+1 by h+1 pixels, because X draws the"
note "outline as a five-point path through the corners, and column 0"
note "here is painted by that extra pixel and by nothing else."

puts "$fail failure(s)"
flush stdout
exit $fail
