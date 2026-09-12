# tk-appname-test.tcl -- "tk appname" registers, and "winfo interps"
# reports what was registered.
#
# WHERE THIS CAME FROM: Tk_SetAppName in plan9/tkPlan9Stubs.c handed
# its argument straight back and recorded nothing, which loses two
# separate contracts:
#
#  - the name it RETURNS is the name actually registered. Every Tk
#    appends " #2", " #3" ... when the name is taken, and
#    Tk_CreateMainWindow does
#	winPtr->nameUid = Tk_GetUid(Tk_SetAppName(tkwin, baseName));
#    so two Tk main windows in one process both came out with the SAME
#    name here. That is not hypothetical: "interp create child;
#    load {} Tk child" is what unixWm-50.3 and the unixEmbed "-Na"
#    variants do, and this port has had two main windows since tktest.
#
#  - "winfo interps" reports it, and answered the empty list -- so it
#    denied that even the asking interpreter existed. tk-2.3,
#    winfo-5.4, winfo-5.5.
#
# NO "send" IS IMPLIED. There is no transport here and none is
# registered; listing the interpreters that exist is a different
# question from being able to reach them. Section 4 says so out loud
# rather than leaving it to be rediscovered.
#
# Runs under wish.

set failures 0

proc step {msg} { puts "STEP: $msg"; flush stdout }
proc check {name got want} {
    global failures
    if {$got eq $want} {
	puts "  PASS $name: $got"
    } else {
	incr failures
	puts "  FAIL $name: got '$got' want '$want'"
    }
    flush stdout
}
proc note {name got} { puts "  note $name: $got"; flush stdout }

# ------------------------------------------------------------------
step "1. the name reads back, and the list contains it (tk-2.3)"

tk appname bazfoogarply
check "appname reads back"   [tk appname] bazfoogarply
check "interps contains it" \
	[expr {[lsearch -exact [winfo interps] [tk appname]] >= 0}] 1
check "with -displayof too (winfo-5.5)" \
	[expr {[lsearch -exact [winfo interps -displayof .] [tk appname]] >= 0}] 1

# ------------------------------------------------------------------
step "2. setting the SAME name again must not push it to \" #2\""

# The uniquifier has to skip this interpreter's own entry, or every
# "tk appname [tk appname]" renames the application.
tk appname bazfoogarply
check "unchanged" [tk appname] bazfoogarply

# ------------------------------------------------------------------
step "3. a second interpreter gets a DIFFERENT name"

catch {interp delete child}
interp create child
if {[catch {load {} Tk child} msg]} {
    puts "  SKIP: cannot load Tk into a child interpreter: $msg"
} else {
    child eval {wm withdraw .}
    child eval [list tk appname bazfoogarply]
    set childName [child eval {tk appname}]
    check "child did not get the same name" \
	    [expr {$childName ne [tk appname]}] 1
    note "child is called" $childName
    check "both are listed" \
	    [expr {[lsearch -exact [winfo interps] $childName] >= 0
		   && [lsearch -exact [winfo interps] [tk appname]] >= 0}] 1

    step "3a. deleting the child removes it from the list"
    # A registry naming an interpreter that has gone is the same class
    # of lie as "wm colormapwindows" naming a destroyed window.
    interp delete child
    check "child is gone from interps" \
	    [expr {[lsearch -exact [winfo interps] $childName] >= 0}] 0
    check "this one is still there" \
	    [expr {[lsearch -exact [winfo interps] [tk appname]] >= 0}] 1
}

# ------------------------------------------------------------------
step "4. RECORDED, NOT ASSERTED: send is not implemented here"

# winfo interps lists the interpreters that exist. It does not promise
# a transport, and none is registered -- there is no cross-application
# send on Plan 9, and a "send" that reported success and delivered
# nothing would be the systray mistake. Printed so that the absence is
# a decision on the record rather than a surprise.
note "is there a send command?" [expr {[llength [info commands send]] ? "yes" : "no"}]

puts ""
puts "failures: $failures"
exit $failures
