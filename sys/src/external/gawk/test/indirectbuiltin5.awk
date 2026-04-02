BEGIN {
	print "test 1"
	if (1) {
		f = "awk::match"
		@f(a, b, c)
		# error: gawk: ./bug.gwk:7: fatal error: internal error
	}
	print "test 2"
	if (1) {
		f = "f1"
		f1_ = "awk::patsplit"	# or split, asort, asorti, index, substr ...
		@f(a, b, c, d)
		# error: Assertion failed: r->valref > 0, file awk.h, line 1295
	}
}

function f1(a, b, c, d)
{
	return @f1_(a, b)
}
