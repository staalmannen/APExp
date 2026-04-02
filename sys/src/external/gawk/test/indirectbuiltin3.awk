function f(y, ifc)
{
	y[3] = 14
	ifc = "isarray"
	return @ifc(y)
}

BEGIN { 
	print f(z)
}
