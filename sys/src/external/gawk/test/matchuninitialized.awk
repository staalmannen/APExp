BEGIN {
	if (match(uninitialized1, /^$/))
		print "uninitialized1 matches"
	if (match(uninitialized2, /^\s*$/))
		print "uninitialized2 matches"
	delete uninitialized3
	if (match(uninitialized3[one], /^$/))
		print "uninitialized3[one] matches"
	if (match(uninitialized3[one], /^\s*$/))
		print "uninitialized3[one] matches"

	if (!match(uninitialized4, /./))
		print "uninitialized4 does not match"
	if (!match(uninitialized4, /\s+/))
		print "uninitialized4 does not match"
	delete uninitialized5
	if (!match(uninitialized5[one], /./))
		print "uninitialized5[one] does not match"
	if (!match(uninitialized3[one], /s+/))
		print "uninitialized5[one] does not match"
}
