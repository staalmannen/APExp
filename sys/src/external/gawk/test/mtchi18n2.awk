BEGIN {
	match("\342\200\257", /^/, m)
	print RSTART, RLENGTH

	match("\342\200\257", /^(a?)\u202F(b?)$/, m)
	#match("\342\200\257", /^(a?)\342\200\257(b?)$/, m)
	print RSTART, RLENGTH, m[1,"start"], m[1,"length"], m[2, "start"], m[2, "length"]

	match("\342\200\257", /$/, m)
	print RSTART, RLENGTH

	match("\342\200\257ac", /a(b?)c/, m)
	print RSTART, RLENGTH, m[1,"start"], m[1,"length"]
}
