# gawk --lint -f lintwarn.awk
BEGINFILE {
	getline var
	getline
}

BEGIN {
        PROCINFO["sorted_in"]
	print
	nextfile
	delete a
	delete(a)
	y = /a/
	y == /a/
	/b/ ~ x
	length
	switch(s) {
	case 1:
	default:
	case 1:
	default:
	}
	break
	continue
	next
	a[]
	f(/pqr/)
	//
	/* */
}
END {
	getline
}
function zz(aa, aa)
{
	return aa
}
@include ""
