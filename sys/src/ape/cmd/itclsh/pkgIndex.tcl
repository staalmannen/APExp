# Tcl package index for itcl, APExp's STATIC build.
#
# WHY THIS FILE IS NOT UPSTREAM'S. itcl's pkgIndex.tcl.in says
#
#	package ifneeded itcl @PACKAGE_VERSION@ \
#		[list load [file join $dir @PKG_LIB_FILE9@] Itcl]
#
# which names a shared library to load. Plan 9 has no dlopen, so itcl
# is compiled into itclsh and registered with Tcl_StaticLibrary; `load'
# with an EMPTY filename is how Tcl reaches a package registered that
# way (tclLoad.c:251 matches by name when fullFileName is empty), and
# it works from any interpreter in the process.
#
# WHAT IT FIXES, which is not obvious. The main interpreter never
# needed this: itclAppInit.c calls Itcl_Init directly, and Itcl_Init
# ends by providing both "Itcl" and "itcl" (itclBase.c:475-476). But a
# SLAVE from `interp create' has never run Itcl_Init, so
# `package require itcl' there had nothing to find and answered
# "can't find package itcl" -- which is what sfbug-254.1, 254.2, 254.3
# and sfbug-257 were reporting. Four of itcl's fourteen failures were
# this missing file rather than anything about the port.
#
# BOTH SPELLINGS, because Tcl package names are case-sensitive and
# itcl's own tests use both. The second line is upstream's, unchanged.

if {![package vsatisfies [package provide Tcl] 8.6-]} {return}

package ifneeded itcl 4.2.3 {load {} Itcl}
package ifneeded Itcl 4.2.3 {package require -exact itcl 4.2.3}
