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
# With them implemented, canvas-23.2 passes and 23.1 and 23.3 do not --
# and the three differ only in colour:
#
#	23.1  #000080   blue    FAIL
#	23.2  #008000   green   pass
#	23.3  #800000   red     FAIL
#
# Green is the middle byte and #c0c0c0 is grey, so both are invariant
# under exchanging red and blue. That is the whole diagnosis: something
# on the way out swaps them.
#
# The chain is short and only one link is uncertain:
#
#   .c create rectangle -fill  ->  GCForegroundRGBA -> tkp9_fillrect
#       every widget in the toolkit has drawn through this for months,
#       so it is not the suspect
#   .c image                   ->  XGetImage -> tkp9_getpixels
#       draws the source into an RGBA32 image and unloadimages it,
#       permuting bytes by rgbaidx[], which rgbacalibrate() measures
#   testimage data             ->  tkCanvas.c, which reads a host-order
#       32-bit word and decomposes it with the visual's masks. Neither
#       _WIN32 nor TK_XGETIMAGE_USES_ABGR32 is defined here, so this
#       end is unconditional and matches what XGetImage packs.
#
# So this script prints the colours that come back, and under
# $TKP9DEBUG the port prints the RGBA32 memory order it measured:
#
#	tkp9: RGBA32 memory order R=? G=? B=? A=?
#
# Between the two, one run says whether rgbacalibrate() is wrong, never
# ran, or is right and the fault is elsewhere. Run it BOTH ways.

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
note "If section 1 shows red and blue exchanged while green is right,"
note "rgbacalibrate() has the RGBA32 memory order wrong. Run again with"
note "TKP9DEBUG=1 to see the order it measured."

puts "$fail failure(s)"
flush stdout
exit $fail
