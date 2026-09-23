# tcl-machexp-probe.tcl -- where does Tcl decide these overflow?
#
# WHERE THIS CAME FROM. Six failures -- expr-28.527, expr-30.1,
# expr-30.2, expr-39.21, expr-50.1 and expr-old-37.21 -- all say the
# same thing: everything at or above 1.7976931348623155e+308 comes back
# infinite, INCLUDING two values that are perfectly representable.
#
# libap has been eliminated from the path. Its strtod is correctly
# rounded (0 wrong in 199887 round-trips against glibc); `maxDigits'
# works out at 308.75, so Tcl's quick overflow check cannot fire for
# these inputs; and frexp and scalbn were cross-checked on the build
# host at 0 wrong in 299876 values. What is left is Tcl's own
# tclStrToD.c, which is instrumented behind $APEXP_STRTOD_DEBUG.
#
# RUN IT AS:
#
#	APEXP_STRTOD_DEBUG=1 tclsh tcl-machexp-probe.tcl
#
# and read the APEXP lines on stderr. MakeHighPrecisionDouble has TWO
# exits that answer HUGE_VAL and each one names itself, because a count
# of failures cannot tell them apart:
#
#	APEXP   QUICK overflow: ...       the exponent/digit check
#	APEXP   MACHEXP overflow: a > b   the computed binary exponent
#
# THE THING TO READ is the `Pow10TimesFrExp' line's machexp beside the
# limit. 1.7976931348623157e+308 is 0.99999... x 2^1024, so machexp
# should be 1024 and the limit is 1024: not greater, no overflow. If it
# says 1025, the fault is one binade in Tcl's own scaling and the
# tables it scales with are pow10_wide and pow_10_2_n.
#
# AND IF NO APEXP LINES APPEAR AT ALL for a value, that is the answer
# for that value rather than a failed run: it reached a different
# function. expr-50.1 is sqrt() of a bignum and may well be one.
#
# Do NOT set the variable for a full suite run: it prints a line per
# conversion.

set values {
    1.7976931348623155e+308
    1.7976931348623157e+308
    1.7976931348623159e+308
    -929963218616126365E290
    1e308
    1.5
}

puts "tcl-machexp-probe, [info patchlevel]"
if {![info exists ::env(APEXP_STRTOD_DEBUG)]} {
    puts "NOTE: APEXP_STRTOD_DEBUG is not set, so no APEXP lines will"
    puts "      print and this run says nothing about where the"
    puts "      overflow is decided. Set it and run again."
}

foreach v $values {
    puts "--- $v"
    flush stdout
    #
    # binary format d is what expr.test's own convertToDouble uses; the
    # parse happens here, when Tcl needs the string as a double.
    #
    if {[catch {binary scan [binary format d $v] H* h} err]} {
	puts "    raised: $err"
    } else {
	puts "    bits (little-endian bytes): $h"
    }
    flush stdout
}
puts "done"
