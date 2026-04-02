BEGIN {
	#r = ""
	r = @//
	test(r)
	#      while ( 1 ) { }
}


function test(r, q, rp, c, t)
{
	#q = 500000
	q = 50
	rp = @/ /
	for (c = 0; c < q; c++) {
		s = r
		sub(//, rp, s)
	}
}
