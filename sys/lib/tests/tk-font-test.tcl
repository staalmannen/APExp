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
check "family of {Helvetica -12}" \
    [font actual {Helvetica -12} -family] "helvetica"
check "size of {Helvetica -12}" \
    [font actual {Helvetica -12} -size] "-12"
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
