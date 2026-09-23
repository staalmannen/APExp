# tcl-fltmax-probe.tcl -- what FLT_MAX was libtcl COMPILED with?
#
# RUN IT AS:
#
#	tclsh tcl-fltmax-probe.tcl
#
# WHERE THIS CAME FROM. binary-53.25 and binary-53.26 fail because
# tclBinary.c's FormatNumber compares against FLT_MAX, and APE's
# float_arch.h wrote FLT_MAX, FLT_MIN and FLT_EPSILON without the `F'
# suffix -- so each was a double holding the nearest double to a
# rounded decimal. That is fixed in the header.
#
# AND THE TWO TESTS STILL FAIL after a full mk distclean and mk
# install, while sys/lib/tests/binfloat-test -- which replicates
# FormatNumber line by line and is compiled by hand with pcc -- reports
# 0 failures and prints the marker saying it read THIS TREE's
# float_arch.h. So the first reading, that tclBinary.$O was simply
# stale, has been REFUTED: distclean removes ./$objtype/lib and runs mk
# clean in every directory, so the object was rebuilt and still has the
# wrong constant.
#
# WHAT IS LEFT IS THE HEADER-SHADOWING INVARIANT:
# /$objtype/include/ape is searched before /sys/include/ape, and the
# repo's copies only win through the union mount that ./mount-include
# sets up -- which no-ops entirely if /sys/include/ape/THIS_IS_APExp
# already exists.
#
# AND THERE ARE AT LEAST THREE float.h's IN PLAY, which is why this
# needs measuring rather than arguing. Three constants have been seen:
#
#   3.4028234663852886e+38   this tree's float_arch.h, after the fix
#   3.40282347e+38           this tree's float_arch.h BEFORE the fix,
#                            and what libtcl is compiled with now
#   3.4028235e+38            what binfloat-test measured before the
#                            fix, which is NEITHER of the above
#
# That third value sat in docs/notes/libap.md as a transcription of one
# run and was never reconciled with the header in git. It cannot come
# from this tree, so something else was being read -- stock 9front APE
# ships its own float.h in the architecture directory, and an older
# APExp installed a float_arch.h there too.
#
# THE NUMBER ALONE CANNOT FINISH THIS. 3.40282347e+38 is what a stale
# installed copy of this tree's header would say AND what a machine's
# own leftover copy would say. tclBinary.c therefore prints the marker,
# the sizeof and the spelling of the FLT_MAX it was compiled with, under
# $APEXP_FLOAT_DEBUG -- see the RESULT text below.

# WHAT THIS MEASURES, AND HOW. FormatNumber answers +Inf exactly when
#
#	fabs(d) > FLT_MAX + ldexp(1.0, FLT_MAX_EXP-FLT_MANT_DIG-1)
#
# so the largest double for which it does NOT answer +Inf is that
# threshold itself, and the threshold minus 2^103 is the FLT_MAX the
# object was compiled with. Bisecting on the BIT PATTERN walks doubles
# one representable step at a time, so the boundary comes back exact.
# This reports the constant rather than a verdict about one value --
# a count of failures cannot tell a wrong constant from a missing
# branch, and printing the number itself tells them apart in one run.
#
# NOT CHECKABLE ON A HOST tclsh 8.6, and that is worth saying because
# checking a new test on the host first is the rule here. 8.6 clamps
# every out-of-range value to FLT_MAX and has no +Inf arm at all -- the
# inner `if' is 9.0's. So on 8.6 this prints "no overflow arm", which
# is the correct reading of 8.6 and not a failure of the probe.

set FLT_MAX_BITS  0x47efffffe0000000	;# 2^128 - 2^104, the true FLT_MAX
set TWO128_BITS   0x47f0000000000000	;# 2^128
set TWO103        1.0141204801825835e+31

proc Rbits {d} {
    binary scan [binary format R $d] H* h
    return $h
}
#
# W lays the bit pattern down as a big-endian wide integer; Q reads
# those same bytes back as a big-endian double. Using `binary format Q'
# here would be wrong and silently so -- Q takes a DOUBLE, so it would
# convert the number 5.18e18 rather than reinterpreting its bits, and
# the control below caught exactly that.
#
proc dfrom {bits} {
    binary scan [binary format W $bits] Q d
    return $d
}
proc isinfbits {h} {
    return [expr {$h eq "7f800000"}]
}

puts "tcl-fltmax-probe, [info patchlevel]"

# The control comes FIRST: if ordinary narrowing is broken, nothing
# below can be read at all.
set one [Rbits 1.0]
set max [Rbits [dfrom $FLT_MAX_BITS]]
puts "control: R of 1.0          = $one  (want 3f800000)"
puts "control: R of true FLT_MAX = $max  (want 7f7fffff)"
if {$one ne "3f800000" || $max ne "7f7fffff"} {
    puts "CONTROL FAILED -- narrowing is wrong for ordinary values too,"
    puts "so the measurement below says nothing. Stop here."
    exit 1
}

# Does this tclsh have the +Inf arm at all? 2^128 is above any possible
# threshold, so if even that does not give +Inf there is no arm.
if {![isinfbits [Rbits [dfrom $TWO128_BITS]]]} {
    puts ""
    puts "RESULT: this tclsh has NO +Inf arm in FormatNumber -- even 2^128"
    puts "        comes back as [Rbits [dfrom $TWO128_BITS]]. That is Tcl 8.6's behaviour;"
    puts "        binary-53.25/53.26 are 9.0 tests and this probe does not"
    puts "        apply. On 9.0 this line means the patch is missing."
    exit 0
}

# Bisect on the bit pattern for the largest double that is NOT +Inf.
# lo is known not-Inf, hi is known Inf, and they close to neighbours.
set lo $FLT_MAX_BITS
set hi $TWO128_BITS
while {$hi - $lo > 1} {
    set mid [expr {($lo + $hi) / 2}]
    if {[isinfbits [Rbits [dfrom $mid]]]} {
	set hi $mid
    } else {
	set lo $mid
    }
}
set thresh [dfrom $lo]
puts ""
puts [format "measured threshold        = %.17g   (bits %016llx)" $thresh $lo]
set implied [expr {$thresh - $TWO103}]
puts [format "implied compiled FLT_MAX  = %.17g" $implied]
puts [format "true FLT_MAX              = %.17g" [dfrom $FLT_MAX_BITS]]
puts ""

if {$implied == [dfrom $FLT_MAX_BITS]} {
    puts "RESULT: libtcl was compiled with the CORRECT FLT_MAX."
    puts "        If binary-53.25/53.26 still fail, the header is ruled out"
    puts "        and the next step is FormatNumber itself -- reading (b)."
} else {
    puts [format "RESULT: libtcl's FLT_MAX is too big by %.6g." \
	    [expr {$implied - [dfrom $FLT_MAX_BITS]}]]
    puts "        3.40282347e+38 is stock APE's constant AND what this"
    puts "        tree's float_arch.h said before the F-suffix fix, so the"
    puts "        NUMBER cannot tell 'read the wrong file' from 'read an"
    puts "        old copy of the right file'. Reading (a) -- staleness --"
    puts "        was already refuted once, by a full mk distclean and mk"
    puts "        install that did not move it."
    puts ""
    puts "        To tell them apart, run this again as"
    puts "            APEXP_FLOAT_DEBUG=1 tclsh tcl-fltmax-probe.tcl"
    puts "        which makes tclBinary.c print the marker, sizeof and"
    puts "        spelling of the FLT_MAX it was compiled with, on stderr."
}

# And the test's own value, for the record.
set d [dfrom 0x47effffff0000001]
puts ""
puts [format "binary-53.25's value      = %.17g" $d]
puts "binary format R of it     = [Rbits $d]  (the test wants 7f800000)"
