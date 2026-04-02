BEGIN {
        str = "ABCDE"
        print str, split(str, arr, /^/)
        for (ch in arr) {
                print ch, arr[ch]
        }
	print "-----------"

        str = "ABCDE"
        print str, split(str, arr, "^")
        for (ch in arr) {
                print ch, arr[ch]
        }
	print "-----------"


        str = "ABCDE"
        print str, split(str, arr, @/^/)
        for (ch in arr) {
                print ch, arr[ch]
        }
}
