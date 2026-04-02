function f(y)
{
	y[3] = 14
}

BEGIN {
	f(a[10])
	a[10]
}
