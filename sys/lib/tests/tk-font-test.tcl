# Does Tk parse font specifications, and do sizes do anything?
#
#	wish tk-font-test.tcl
#
# TkpGetNativeFont used to accept every string as a native font name and
# open the default font for it, so tkFont.c never got to parse anything:
# an XLFD came back whole as the family, sizes and styles were ignored,
# and an empty font name was accepted where it must be an error.
#
#	font actual {Helvetica -12}  ->  -family {Helvetica -12} -size 18
#
# That was 45 of font.test's failures plus button-1.104..110 and
# canvasText-1.7. The contract is that TkpGetNativeFont *fails* for
# anything that is not a native name -- here, the path of a Plan 9 font
# file -- so that Tk parses the string itself and comes back through
# TkpGetFontFromAttributes.
#
# Section 0 is the one that cannot be got from the source: which font
# files this machine actually has. The size table in tkPlan9Font.c is a
# guess at what a 9front install ships, and a candidate that will not
# open is skipped, so a wrong guess costs size accuracy and nothing
# else -- but it should be corrected against this list.

set fail 0

proc check {what got want} {
    global fail
    if {$got eq $want} {
	puts "PASS $what"
    } else {
	puts "FAIL $what: got '$got', want '$want'"
	incr fail
    }
    flush stdout
}

proc note {m} { puts $m; flush stdout }

# 0. What font files exist here?
note "--- /lib/font/bit inventory ---"
foreach dir [lsort [glob -nocomplain -type d /lib/font/bit/*]] {
    set files [lsort [glob -nocomplain $dir/*.font]]
    set names {}
    foreach f $files { lappend names [file tail $f] }
    note "  [file tail $dir]: $names"
}

note "--- font families Tk reports ---"
note "  [lsort [font families]]"

# 1. An empty font name is an error, not the default font.
foreach cmd {{font actual {}} {font metrics {}}} {
    if {[catch $cmd err]} {
	note "PASS '$cmd' raised: $err"
    } else {
	note "FAIL '$cmd' returned '$err' instead of raising"
	incr fail
    }
}

# The widget option path, which is where button.test and canvasText.test
# noticed this.
label .l -text hello
pack .l
update
if {[catch {.l configure -font {}} err]} {
    note "PASS '.l configure -font {}' raised: $err"
} else {
    note "FAIL '.l configure -font {}' was accepted"
    incr fail
}

# 2. A "{family} size style" list must be parsed, not swallowed whole.
#
# "font actual" reports the family that was RESOLVED, not the one asked
# for, as tkUnixFont.c does -- there are three families here whatever
# was requested. font.test relies on that: it asks whether
# "font actual {avantgarde 12} -family" is still "avantgarde" to decide
# whether the machine really has that family.
check "family of {Helvetica -12}" \
    [string tolower [font actual {Helvetica -12} -family]] "helvetica"
check "family of {Courier 10}" \
    [string tolower [font actual {Courier 10} -family]] "courier"
check "family of {Times 10}" \
    [string tolower [font actual {Times 10} -family]] "times"
check "an unknown family resolves to something else" \
    [expr {[font actual {avantgarde 12} -family] ne "avantgarde"}] 1
# In POINTS, so a request for -12 pixels at scaling 1.0 reads back as 12.
# font-44.1 is the same rule with scaling 0.5, in section 5b.
check "size of {Helvetica -12}" \
    [font actual {Helvetica -12} -size] "12"
check "size of {Courier 10}" \
    [font actual {Courier 10} -size] "10"
check "weight of {Helvetica 12 bold}" \
    [font actual {Helvetica 12 bold} -weight] "bold"
check "slant of {Helvetica 12 italic}" \
    [font actual {Helvetica 12 italic} -slant] "italic"

# 3. An XLFD must be parsed. This is font-38.1 and font-40.1 exactly.
check "XLFD family" \
    [font actual -xyz-times-*-*-*-*-*-*-*-*-*-*-*-* -family] "times"

# 4. -option/value form.
check "-family/-size form" \
    [font actual {-family courier -size 14} -size] "14"

# 5. Sizes must actually differ. Plan 9 has bitmap fonts in discrete
# sizes, so a request is answered with the nearest file -- but a big
# font must not measure the same as a small one, which is what happened
# when every request opened the same default font.
set small [font measure {Courier 8} "0000000000"]
set large [font measure {Courier 20} "0000000000"]
note "measure of ten chars: 8pt=$small 20pt=$large"
if {$large > $small} {
    note "PASS a larger size measures wider"
} else {
    note "FAIL size has no effect: $small vs $large"
    incr fail
}

set m8  [font metrics {Courier 8}]
set m20 [font metrics {Courier 20}]
note "metrics  8pt: $m8"
note "metrics 20pt: $m20"
if {[dict get $m20 -linespace] > [dict get $m8 -linespace]} {
    note "PASS a larger size has a taller linespace"
} else {
    note "FAIL linespace does not follow size"
    incr fail
}

# 5b. "font actual -size" is in POINTS, so it follows "tk scaling"; Tk
# stores a negative size as pixels. At scaling 0.5 a request for -13
# pixels is 26 points. This is font-44.1.
set oldscaling [tk scaling]
tk scaling 0.5
check "size in points follows tk scaling" [font actual {times -13} -size] 26
tk scaling $oldscaling

# 5c. Text layout across lines.
#
# font-28.* and font-30.* ask a canvas text item which character is at a
# given point, and get 0 where they want the start of line 2. Both the
# label that defines the reference height and the canvas item use
# "Courier -12", so they should agree.
#
# Tk_PointToChar picks a line with
#
#	if (y < baseline + fontPtr->fm.descent)
#
# and the first line's baseline is fm.ascent, so line 1 is chosen for
# y < ascent+descent. Returning 0 therefore means ay came out SMALLER
# than the font's own ascent+descent -- but ay is the reqheight of a
# label with no padding, which is exactly one line. These numbers say
# which of the two is wrong.
destroy .t 2>/dev/null
toplevel .t
label .t.l -padx 0 -pady 0 -bd 0 -highlightthickness 0 -justify left \
    -text "0" -font "Courier -12"
pack .t.l
update
set ax [winfo reqwidth .t.l]
set ay [winfo reqheight .t.l]
note "label reqwidth  (ax) = $ax"
note "label reqheight (ay) = $ay"
note "metrics of Courier -12: [font metrics "Courier -12"]"
note "  ascent+descent = [expr {[font metrics {Courier -12} -ascent] + \
    [font metrics {Courier -12} -descent]}] (ay must equal this)"
note "  actual: [font actual "Courier -12"]"

canvas .t.c -closeenough 0
.t.c create text 0 0 -tags text -anchor nw -just left -font "Courier -12"
pack .t.c
update
.t.c dchars text 0 end
.t.c insert text 0 "000\n000\n000"
update
note "canvas bbox of 3 lines: [.t.c bbox text]"
note "canvas item coords: [.t.c coords text], angle [.t.c itemcget text -angle]"
foreach probe [list 0 [expr {$ay - 1}] $ay [expr {$ay + 1}] \
                    [expr {2 * $ay}] [expr {2 * $ay + 1}]] {
    note "  index @0,$probe -> [.t.c index text @0,$probe]"
}
check "index at the start of line 2" [.t.c index text @0,$ay] 4

# The boundaries land one pixel late -- at 13 and 25 where the metrics
# allow only 12 and 24. That cannot come from the metrics: the bbox says
# the layout is 3 * 12 tall, and ascent+descent is 12, so the two
# disagree with each other. What sits between "@0,12" and Tk_PointToChar
# is tkCanvText.c:1529
#
#	Tk_PointToChar(layout, (int)(x*cs - y*s), (int)(y*cs + x*s));
#
# with cs/s the item's cosine and sine. For an unrotated item they must
# be exactly 1.0 and 0.0 -- and if cs were a hair under 1.0, (int)(12*cs)
# truncates to 11 and (int)(13*cs) to 12, which is precisely the shift
# seen. Tcl's expr calls libap's libm, so this asks the same question
# directly.
note "cos(0.0) = [expr {cos(0.0)}]   (must be exactly 1.0)"
note "sin(0.0) = [expr {sin(0.0)}]   (must be exactly 0.0)"
check "cos(0.0) is exactly 1.0" [expr {cos(0.0) == 1.0}] 1
check "sin(0.0) is exactly 0.0" [expr {sin(0.0) == 0.0}] 1

# And separate the item's origin from any scaling of y: move the item
# down and see whether the boundary moves by the same amount or by more.
.t.c coords text 0 100
update
note "item moved to y=100; bbox now [.t.c bbox text]"
foreach probe [list 100 [expr {100 + $ay}] [expr {100 + $ay + 1}]] {
    note "  index @0,$probe -> [.t.c index text @0,$probe]"
}
destroy .t

# 6. A real Plan 9 font path is a native name and must still work.
set p /lib/font/bit/fixed/unicode.6x13.font
if {[file readable $p]} {
    if {[catch {font measure $p "0"} w]} {
	note "FAIL native path '$p' rejected: $w"
	incr fail
    } else {
	note "PASS native path works (width of '0' is $w)"
    }
} else {
    note "SKIP no $p on this machine"
}

# 7. A font that cannot exist must be reported, not silently accepted.
if {[catch {font actual /no/such/font.font -family} err]} {
    note "PASS a bad font path raised: $err"
} else {
    note "note: bad font path answered '$err' (Tk may treat it as a family)"
}

puts "$fail failure(s)"
flush stdout
exit $fail
