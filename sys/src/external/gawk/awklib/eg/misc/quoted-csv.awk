# This file and how to use it are described in the manual.
# Therefore, we respectfully advise you to Read The Fine Manual
# for more information.

BEGIN {
    FPAT = "([^,]*)|(\"([^\"]|\"\")+\")"
    OFS = "\t"    # Print tab-separated values
}

{
    for (i = 1; i <= NF; i++) {
        # Extract data from double-quoted fields
        if (substr($i, 1, 1) == "\"") {
            gsub(/^"|"$/, "", $i)    # Remove enclosing quotes
            gsub(/""/, "\"", $i)    # Convert "" to "
        }
    }
    $1 = $1    # force rebuild of the record
    print
}
