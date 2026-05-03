# Simulated Autoconf config.h generator

BEGIN {
    # Simulate confdefs.h content
    defs["HAVE_STDIO_H"] = 1
    defs["HAVE_UNISTD_H"] = 1
    defs["SIZEOF_INT"] = "4"
    defs["PACKAGE_NAME"] = "\"testpkg\""
}

{
    # Match "#undef SYMBOL"
    if (match($0, /^#[ \t]*undef[ \t]+([A-Za-z_][A-Za-z0-9_]*)/, m)) {
        sym = m[1]
        if (sym in defs) {
            print "#define " sym " " defs[sym]
        } else {
            print $0
        }
        next
    }

    # Pass through everything else unchanged
    print
}

