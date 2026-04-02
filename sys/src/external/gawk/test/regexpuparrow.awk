BEGIN { RS = ".^" }

{
        gsub(/.^/, ">&<")
        print NR, $0
        print "RT=<" RT ">"
}
