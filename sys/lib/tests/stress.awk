BEGIN {
    # Thousands of entries (similar to large projects)
    for (i = 1; i <= 2000; i++) {
        sym = sprintf("SYMBOL_%04d", i)
        defs[sym] = i
    }

    # Also test long strings
    defs["LONG_STRING"] = "\"" \
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" \
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" \
        "\""
}

{
    if ($1 == "#undef" && NF == 2) {
        sym = $2
        if (sym in defs)
            print "#define", sym, defs[sym]
        else
            print $0
        next
    }
    print
}

