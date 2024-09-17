BEGIN {
	str = "אבג"
	n = gsub(//, "x", str)
	print n, str
}
