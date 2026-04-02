BEGIN {
	# Numerator > denominator. Integer and fractional code paths.
	printf " 15 %  7 = % g\n",  15 %  7
	printf " 15 % -7 = % g\n",  15 % -7
	printf "-15 %  7 = % g\n", -15 %  7
	printf "-15 % -7 = % g\n", -15 % -7
	printf " 15.0 %  7 = % g\n",  15.0 %  7
	printf " 15.0 % -7 = % g\n",  15.0 % -7
	printf "-15.0 %  7 = % g\n", -15.0 %  7
	printf "-15.0 % -7 = % g\n", -15.0 % -7
	print ""

	# Numerator < denominator. Integer and fractional code paths.
	printf " 2 %  7 = % g\n",  2 %  7
	printf " 2 % -7 = % g\n",  2 % -7
	printf "-2 %  7 = % g\n", -2 %  7
	printf "-2 % -7 = % g\n", -2 % -7
	printf " 2 %  7.0 = % g\n",  2 %  7.0
	printf " 2 % -7.0 = % g\n",  2 % -7.0
	printf "-2 %  7.0 = % g\n", -2 %  7.0
	printf "-2 % -7.0 = % g\n", -2 % -7.0
	print ""

	# These arguments require the fractional code path.
	printf " 8.911 %  4.2 = % g\n",  8.911 %  4.2
	printf " 8.911 % -4.2 = % g\n",  8.911 % -4.2
	printf "-8.911 %  4.2 = % g\n", -8.911 %  4.2
	printf "-8.911 % -4.2 = % g\n", -8.911 % -4.2
}
