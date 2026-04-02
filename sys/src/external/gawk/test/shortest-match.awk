# shortest-match.awk --- Demonstrate shortest match operators
#
# Arnold Robbins, arnold@skeeve.com, Public Domain
# March, 2025
BEGIN {
    text[1] = "aaaxxxzzz";
        shortpat[1] = @/x+?/
        longpat[1] = @/x+/
    text[2] = "aaaxxxyzzz";
        shortpat[2] = @/x+?y/
        longpat[2] = @/x+y/
    text[3] = "aaaxxxxxxxxxxxxxxxxzzz";
        shortpat[3] = @/(x+?)(x+)(x+?)(x+)/
        longpat[3] = @/(x+)(x+)(x+)(x+)/
    text[4] = "aaaxyxxyxxyxzzz"
        shortpat[4] = @/((x+)(y+?)(x+))+/
        longpat[4] = @/((x+)(y+)(x+))+/
    text[5] = "aaaxyxxyxxyxzzz"
        shortpat[5] = @/((x+)(y+?)(x+)){2}/
        longpat[5] = @/((x+)(y+)(x+)){2}/

    count = length(text)
    for (i = 1; i <= count; i++) {
        show(text[i], shortpat[i], longpat[i])
    }
}

# show --- show the results of using shortest- and longest-match operators

function show(text, shortpat, longpat,
          s_offsets, l_offsets, i, n)   # locals
{
    printf("\"%s\"\n", text)

    match(text, shortpat, s_offsets)
    subresult = gensub(shortpat, "X", 1, text)
    printf("\tshortpat: /%s/, result: \"%s\"\n", shortpat, subresult)
    dump(text, s_offsets)

    match(text, longpat, l_offsets)
    subresult = gensub(longpat, "X", 1, text)
    printf("\tlongpat: /%s/, result: \"%s\"\n", longpat, subresult)
    dump(text, l_offsets)
}

# dump --- dump out the start and length of subpattern matches

function dump(text, offsets,    i, n, s, l)
{
    n = length(offsets)
    for (i = 0; i <= n; i++) {
        if ((i, "start") in offsets) {
            s = offsets[i, "start"]
            l = offsets[i, "length"]
            printf("\t\t%d: (s: %d, l: %d) -> \"%s\"\n", i,
                s, l, substr(text, s, l))
        }
    }
}
