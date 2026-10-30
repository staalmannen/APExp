#!/bin/sh
# Faithful port of cc/mkenam (an `ed' script) to sed, for host builds.
# The ed script is, in order: keep only lines matching ^\tA; turn that
# leading "\tA" into "\t\""; cut from the first space to end of line;
# strip trailing commas and append "\",".
# $1 is the <T>.out.h to read, output goes to stdout.
printf 'char*\tanames[] =\n{\n'
sed -n '/^	A/p' "$1" | sed -e 's/^	A/	"/' -e 's/ .*$//' -e 's/,*$/",/'
printf '};\n'
