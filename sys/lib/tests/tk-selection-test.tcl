# Does the clipboard reach /dev/snarf, and does the snarf buffer reach Tk?
#
#	wish tk-selection-test.tcl
#
# Plan 9 has one system-wide cut buffer, /dev/snarf, served by rio, so
# both PRIMARY and CLIPBOARD map onto it. Before this, TkSelGetSelection
# answered "selection not supported" and TkSelUpdateClipboard was an
# empty macro in tkPlan9Port.h -- so nothing a Tk program copied was
# visible to anything else, and nothing snarfed elsewhere could be
# pasted in. clipboard.test failed 12 cases on the first of those.
#
# The two directions fail independently and are tested separately:
#
#   out -- "clipboard append" then read /dev/snarf
#   in  -- write /dev/snarf then "clipboard get"
#
# Note the "in" direction is the only one that exercises
# TkSelGetSelection at all. tkSelect.c serves a selection this
# application owns from its own handlers and never reaches the platform
# hook (Tk_GetSelection), so a "clipboard get" straight after a
# "clipboard append" proves nothing about it -- hence the deliberate
# "selection clear" and the write from outside.

set fail 0

proc check {what got want} {
    global fail
    if {$got eq $want} {
	puts "PASS $what"
    } else {
	puts "FAIL $what: got '$got', want '$want'"
	incr fail
    }
    flush stdout
}

proc snarf {} {
    set f [open /dev/snarf r]
    set s [read $f]
    close $f
    return $s
}

proc setsnarf {s} {
    set f [open /dev/snarf w]
    puts -nonewline $f $s
    close $f
}

# 0. Can we reach /dev/snarf at all? Without rio there is no snarf file,
# and every case below would fail for a reason that has nothing to do
# with Tk.
if {[catch {snarf} err]} {
    puts "SKIP: cannot read /dev/snarf ($err) -- run this under rio"
    exit 0
}

# 1. Out: Tk's clipboard -> /dev/snarf.
clipboard clear
clipboard append "hello snarf"
check "clipboard append reaches /dev/snarf" [snarf] "hello snarf"

# Appends accumulate, and the whole buffer is rewritten each time.
clipboard append " and again"
check "second append accumulates" [snarf] "hello snarf and again"

# A clear empties it: the target list is empty and there is nothing to
# write.
clipboard clear
check "clipboard clear empties /dev/snarf" [snarf] ""

# UTF-8 has to survive both ways; /dev/snarf is UTF-8 and so is Tk.
clipboard clear
clipboard append "åäö 中文"
check "utf-8 out" [snarf] "åäö 中文"

# 2. In: /dev/snarf -> Tk. This is the direction that goes through
# TkSelGetSelection, and only when Tk does not own the selection itself.
clipboard clear
selection clear -selection CLIPBOARD
selection clear -selection PRIMARY

setsnarf "from the outside"
check "clipboard get reads /dev/snarf" \
    [selection get -selection CLIPBOARD] "from the outside"
check "selection get reads /dev/snarf" \
    [selection get -selection PRIMARY] "from the outside"

setsnarf "åäö 中文"
check "utf-8 in" [selection get -selection CLIPBOARD] "åäö 中文"

# An empty snarf buffer is a legitimate empty answer, not an error.
setsnarf ""
if {[catch {selection get -selection CLIPBOARD} got]} {
    puts "FAIL empty snarf raised: $got"
    incr fail
} else {
    check "empty snarf gives empty string" $got ""
}

# 3. A target nothing can supply must still say so in the words Tk's own
# tests expect, rather than "selection not supported".
if {[catch {selection get -selection CLIPBOARD -type NO_SUCH_TARGET} err]} {
    check "unknown target message" \
	[string match "*selection doesn't exist or form*" $err] 1
} else {
    puts "FAIL unknown target returned '$err' instead of raising"
    incr fail
}

# TARGETS is answered from the platform hook and must name what we can
# actually convert to.
if {[catch {selection get -selection CLIPBOARD -type TARGETS} got]} {
    puts "FAIL TARGETS raised: $got"
    incr fail
} else {
    check "TARGETS includes UTF8_STRING" [expr {"UTF8_STRING" in $got}] 1
}

puts "$fail failure(s)"
flush stdout
exit $fail
