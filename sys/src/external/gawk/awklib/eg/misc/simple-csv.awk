# This file and how to use it are described in the manual.
# Therefore, we respectfully advise you to Read The Fine Manual
# for more information.

BEGIN {
    FPAT = "([^,]*)|(\"[^\"]+\")"
}

{
    print "NF =", NF
    for (i = 1; i <= NF; i++) {
        printf("$%d = <%s>\n", i, $i)
    }
}
