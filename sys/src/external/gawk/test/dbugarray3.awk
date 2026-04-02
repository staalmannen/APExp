function walk_array(arr, name,      i)
{
    for (i in arr) {
        if (isarray(arr[i]))
            walk_array(arr[i], (name "[" i "]"))
        else
            printf("%s[%s] = %s\n", name, i, arr[i])
    }
}

BEGIN {
	$0 = "1 2 3"
	split($0, a[0])
	a[1][1]
	split($0, a[1])

	walk_array(a, "a")
}
