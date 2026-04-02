function f(y)
{
	delete a
	print typeof(y)
	print y
	g(y)
}

function g(x)
{
	print "hey", x
}

BEGIN {
	f(a[10])
}
