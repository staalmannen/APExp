function foo(a, b, optional, l1)
{
	if (typeof(optional) == "untyped")
		optional = 42

	print "foo:", optional
}

function bar(a, b, optional, l1)
{
	if (length(optional) == 0)
		optional = 42

	print "bar:", optional
}

BEGIN {
	foo(1, 2)
	foo(1, 2, 3)

	bar(1, 2)
	bar(1, 2, 3)
}
