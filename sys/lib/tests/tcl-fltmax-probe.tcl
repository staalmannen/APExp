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
# rounded decimal, and (double)FLT_MAX came out about 3.4e30 too big.
# That is fixed in the header.
#
# AND THE TWO TESTS STILL FAIL, while sys/lib/tests/binfloat-test --
# which replicates FormatNumber line by line and is compiled fresh by
# hand -- reports 0 failures and prints the marker saying it read THIS
# TREE's float_arch.h. Two readings:
#
#   (a) tclBinary.$O was compiled BEFORE the header was fixed and has
#	the old constant baked into it. Nothing in these mkfiles lists
#	a system header as a dependency, so `mk install' will not
#	rebuild an object because <float.h> changed.
#
#   (b) the header fix is not sufficient and something else in
#	FormatNumber's path is wrong.
#
# WHY NOT A MARKER COMPILED IN SOMEWHERE. Because editing a file makes
# mk recompile THAT file: a marker in tclStrToD.c would report a fresh
# header while tclBinary.$O sat stale beside it, which is the very
# thing being asked. The object has to be read as it stands.
#
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
puts [format "measured threshold        = %.17g   (bits %016x)" $thresh $lo]
set implied [expr {$thresh - $TWO103}]
puts [format "implied compiled FLT_MAX  = %.17g" $implied]
puts [format "true FLT_MAX              = %.17g" [dfrom $FLT_MAX_BITS]]
puts ""

if {$implied == [dfrom $FLT_MAX_BITS]} {
    puts "RESULT: libtcl was compiled with the CORRECT FLT_MAX."
    puts "        If binary-53.25/53.26 still fail, the header is ruled out"
    puts "        and the next step is FormatNumber itself -- reading (b)."
} else {
    puts [format "RESULT: libtcl's FLT_MAX is too big by %.6g -- reading (a)." \
	    [expr {$implied - [dfrom $FLT_MAX_BITS]}]]
    puts "        The header is fixed and binfloat-test, compiled fresh,"
    puts "        agrees; so this object predates the fix. A header change"
    puts "        needs mk distclean before mk install -- no mkfile here"
    puts "        lists a system header as a dependency."
}

# And the test's own value, for the record.
set d [dfrom 0x47effffff0000001]
puts ""
puts [format "binary-53.25's value      = %.17g" $d]
puts "binary format R of it     = [Rbits $d]  (the test wants 7f800000)"
