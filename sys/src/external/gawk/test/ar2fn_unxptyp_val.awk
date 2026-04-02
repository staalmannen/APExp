function f1(y)
{
	delete a1
	y
	print typeof(a1)
	print typeof(y)
}

BEGIN {
	a1[10] = 14
	delete a1[10]
	f1(a1[10])
}

function f2(y)
{
	delete a2
	y
	print typeof(a2)
	print typeof(y)
}

BEGIN {
	f2(a2[10])
}
