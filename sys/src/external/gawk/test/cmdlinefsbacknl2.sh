#!/bin/sh

awk="$AWK -v BINMODE=2"
SED="sed -e '/^\$/d' -e 's/[ 	][ 	]*/ /g' -e 's/  *\$//'"

# Both of these succeeded:
# export LC_CTYPE=C
export LC_CTYPE="en_US.UTF-8"


# Test terminal backslash handling. Each test should produce "5c 0a"
# (a backslash followed by a newline). Presently, master produces "0a".
#
$awk -F'\' 'BEGIN { print FS }' | od -An -tx1 | eval $SED
$awk -v s='\' 'BEGIN { print s }' | od -An -tx1 | eval $SED
echo | $awk '{ print s }' s='\' | od -An -tx1 | eval $SED


# These are the same terminal backslash handling tests we just ran, but
# with a line-continuation pair immediately preceding the terminal
# backslash. Let's make sure these two special sequences play well.
# Their output should be the same as before, "5c 0a". Again, master
# produces only "0a". The backslash is lost.
#
$awk -F'\
\' 'BEGIN { print FS }' | od -An -tx1 | eval $SED
$awk -v s='\
\' 'BEGIN { print s }' | od -An -tx1 | eval $SED
echo | $awk '{ print s }' s='\
\' | od -An -tx1 | eval $SED


# \uffffffff (-1)
# \ufffffffe (-2)
#
# A properly handled invalid \u sequence yields a literal '?' (3f).
# This test should print "3f 0a 3f 0a", but master prints "5c 0a 5c 0a".
#
# The code point overflows parse_escape's int return value, yielding one
# of the reserved, negative values. In this case, make_str_node is
# confused into preserving a terminal backslash that doesn't exist.
#
$awk 'BEGIN {
	print "\uFFFFFFFF"	# "?\n"
	print "\uFFFFFFFE"	# "?\n"
}' | od -An -tx1 | eval $SED	# 3f 0a 3f 0a


# Again, a negative return value causes confusion, this time producing a
# fatal error in make_regexp.
#
$awk 'BEGIN {
	if ("xy?z" ~ /xy\uFFFFFFFFz/)
		print "right: literal ? is literal"
	else
		print "wrong: literal ? is meta"
}'

# \uD800 to \uDFFF are invalid Unicode code points. They're reserved
# for UTF-16 surrogates. Let's use them to test \u conversion error
# handling. The correct output is a true expression, 0 == 0 or 1 == 1.
#
$awk 'BEGIN {
	print "1 == " ("xy?z" ~ /xy\uD800z/)
	print "1 == " ("xy?z" ~ "xy\\uD800z")

	print "0 == " ("xyz" ~ /xy\uD800z/)
	print "0 == " ("xyz" ~ "xy\\uD800z")

	print "0 == " ("xz" ~ /xy\uD800z/)
	print "0 == " ("xz" ~ "xy\\uD800z")
}'

exit 0
