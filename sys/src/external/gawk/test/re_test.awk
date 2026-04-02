BEGIN {
	x = @/bar/
	y[0] = @/bar/
	y[1] = @/baz/
	y[2] = "bar"
	y[3] = "baz"
	printf("* set: x = @/%s/\n", x)
	for (i in y) {
		yfmt = typeof(y[i]) == "regexp" ? sprintf("@/%s/", y[i]) : ""y[i]
		printf("* set: y = %s\n", yfmt)
		printf("@/%s/ == %s --> %d\n", x, yfmt, x == y[i])
		printf("@/%s/ ~  %s --> %d\n", x, yfmt, x ~ y[i])
		printf("@/%s/ <= %s --> %d\n", x, yfmt, x <= y[i])
		printf("@/%s/ <  %s --> %d\n", x, yfmt, x < y[i])
	}
}
