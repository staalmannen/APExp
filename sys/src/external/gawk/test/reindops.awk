{ 
	if ($1 !~ /^+[2-9]/)
		print "gawk now follows posix"
	else
		print "gawk is using gnu regex"
}
