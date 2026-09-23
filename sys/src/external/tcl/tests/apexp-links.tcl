# apexp-links.tcl -- symbolic links are a CAPABILITY, so ask for them.
#
# WHY THIS EXISTS. Tcl's suite declares linkDirectory, linkFile and
# symbolicLinkFile to be 1 and lets only Windows turn them off, so every
# other platform is assumed to have symbolic links. **9front has none**
# -- `file link -symbolic' raises ENOSYS -- and most of the tests that
# use one do not carry a link constraint at all, because on every unix
# upstream builds on there was never a reason to.
#
# The cost is not only the tests that want a link. fileName.test showed
# that: filename-11.17.7 is
#
#	cd $globname
#	file mkdir nonexistent
#	file link -symbolic link nonexistent	;# raises here
#	file delete nonexistent			;# so this never runs
#
# and its -cleanup removes only `link'. `nonexistent' stays in globTest,
# and ELEVEN later tests in that file then see one extra entry and fail
# for a reason that has nothing to do with what they test. Making the
# five skip is what stopped the eleven misreporting.
#
# WHAT IT DOES, and the limit is deliberate:
#
#   - it defines the constraint `symlinks', which is APExp's own name.
#     The tests patched to carry it are the ones that use a symbolic
#     link without declaring that they need one.
#   - if, and only if, the probe FAILS, it also forces upstream's
#     linkDirectory, linkFile and symbolicLinkFile to 0, for the tests
#     that do already declare them.
#
# On a system that has symbolic links it touches none of upstream's
# constraints: `symlinks' is 1, the three others are left exactly as the
# test file left them, and nothing that Windows -- or any other platform
# -- deliberately disabled can be switched back on.
#
# IT CANNOT ASK WHETHER A CONSTRAINT WAS DECLARED, and that is a fact
# about tcltest rather than a shortcut. `testConstraints' carries a read
# trace, tcltest::SafeFetch, whose comment says "sets testConstraints($n2)
# to 0 if it's referenced but never before used" -- so *looking*
# creates the entry as 0, and "absent" and "false" are the same
# observation. An earlier version of this file tried to tell them apart
# and silently read back 0 for two constraints on a host that has links.
# Hence the separate name.
#
# Source it AFTER the test file's own constraint declarations.

namespace eval ::apexp {}

if {![info exists ::apexp::haveSymlinks]} {
    set ::apexp::probe [file join [temporaryDirectory] apexp-symlink-probe]
    catch {file delete -force $::apexp::probe}
    set ::apexp::haveSymlinks [expr {![catch {
	file link -symbolic $::apexp::probe [temporaryDirectory]
    }]}]
    catch {file delete -force $::apexp::probe}
    unset -nocomplain ::apexp::probe
}

testConstraint symlinks $::apexp::haveSymlinks

if {!$::apexp::haveSymlinks} {
    testConstraint linkDirectory 0
    testConstraint linkFile 0
    testConstraint symbolicLinkFile 0
}
