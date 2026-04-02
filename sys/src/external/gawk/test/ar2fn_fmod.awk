function f(y)
{
	delete a
	g(y)
	print typeof(a)
	print typeof(y)
}

function g(x)
{
	x
}

BEGIN {
	f(a[10])
}
