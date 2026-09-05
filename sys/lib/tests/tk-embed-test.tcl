# Does "-container 1" plus "-use" actually embed anything?
#
#	wish tk-embed-test.tcl
#
# Tk_UseWindow used to answer "-use not supported on Plan 9", which is
# every test in safe.test and safePrimarySelection.test -- 34 of them --
# because safe::loadTk always ends in "-use". Even with no -use argument
# it builds a decorated toplevel containing a "frame $w.c -container 1"
# and embeds into that (library/safetk.tcl, tkTopLevel).
#
# Embedding here is much simpler than on X. tkUnixEmbed.c is 1200 lines
# because the container and the embedded application are usually
# separate X clients, needing wrapper windows, a property protocol for
# geometry, and an error handler for when the other client dies. A safe
# interpreter is a child interpreter in this same process, sharing this
# window table, so it reduces to: create the embedded toplevel as a
# child of the container, and keep the sizes in step.

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

proc note {m} { puts $m; flush stdout }

# 1. A container frame must exist and be marked as one.
frame .c -container 1 -width 200 -height 150
pack .c
update
check "container has an id" [expr {[winfo id .c] ne ""}] 1
check "-container reads back" [.c cget -container] 1

# 2. A window that is not a container must be refused, with Tk's own
# wording -- safe.test's failures were reported by message.
frame .plain -width 50 -height 50
pack .plain
update
if {[catch {toplevel .e -use [winfo id .plain]} err]} {
    check "non-container refused" \
	[string match "*doesn't have -container option set*" $err] 1
} else {
    note "FAIL embedding into a non-container was allowed"
    incr fail
    destroy .e
}

# 3. The real thing: a toplevel embedded in the container.
if {[catch {toplevel .e -use [winfo id .c]} err]} {
    note "FAIL toplevel -use raised: $err"
    incr fail
} else {
    update
    check "embedded toplevel exists"  [winfo exists .e] 1
    check "embedded toplevel mapped"  [winfo ismapped .e] 1

    # It must be inside the container, not at the root, and the same
    # size as it.
    check "embedded width follows container" \
	[winfo width .e] [winfo width .c]
    check "embedded height follows container" \
	[winfo height .e] [winfo height .c]
    check "embedded sits at the container" \
	[list [winfo rootx .e] [winfo rooty .e]] \
	[list [winfo rootx .c] [winfo rooty .c]]

    # Resizing the container must carry the embedded window with it.
    .c configure -width 300 -height 200
    update
    check "embedded follows a container resize" \
	[list [winfo width .e] [winfo height .e]] \
	[list [winfo width .c] [winfo height .c]]

    # A widget inside the embedded toplevel should draw and measure.
    label .e.l -text "embedded"
    pack .e.l
    update
    check "widget inside the embedded toplevel is mapped" \
	[winfo ismapped .e.l] 1

    destroy .e
    update
    check "container survives the embedded window going away" \
	[winfo exists .c] 1
}

# 4. safe::loadTk is what all of this is for.
if {[catch {package require Tcl} err]} {
    note "SKIP no safe support: $err"
} elseif {[catch {
    set i [::safe::interpCreate]
    ::safe::loadTk $i
    set r [interp eval $i {winfo children .}]
    ::safe::interpDelete $i
    set r
} err]} {
    note "FAIL safe::loadTk raised: $err"
    incr fail
} else {
    note "PASS safe::loadTk worked (child windows: '$err')"
}

puts "$fail failure(s)"
flush stdout
exit $fail
