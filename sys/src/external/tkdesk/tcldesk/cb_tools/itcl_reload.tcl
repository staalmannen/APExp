# ----------------------------------------------------------------------
#  PURPOSE:  Clear all class data and reload a class definition
#
#   AUTHOR:  Michael J. McLennan       Phone: (610)712-2842
#            AT&T Bell Laboratories   E-mail: michael.mclennan@att.com
#
#      RCS:  itcl_reload.tcl,v 1.1.1.1 1994/03/21 22:09:46 mmc Exp
# ----------------------------------------------------------------------
#               Copyright (c) 1993  AT&T Bell Laboratories
# ======================================================================
# Permission to use, copy, modify, and distribute this software and its
# documentation for any purpose and without fee is hereby granted,
# provided that the above copyright notice appear in all copies and that
# both that the copyright notice and warranty disclaimer appear in
# supporting documentation, and that the names of AT&T Bell Laboratories
# any of their entities not be used in advertising or publicity
# pertaining to distribution of the software without specific, written
# prior permission.
#
# AT&T disclaims all warranties with regard to this software, including
# all implied warranties of merchantability and fitness.  In no event
# shall AT&T be liable for any special, indirect or consequential
# damages or any damages whatsoever resulting from loss of use, data or
# profits, whether in an action of contract, negligence or other
# tortuous action, arising out of or in connection with the use or
# performance of this software.
# ======================================================================

# ----------------------------------------------------------------------
#  USAGE:  itcl_unload <className>...
#
#  Destroys all objects in the specified classes, and destroys the
#  class definitions.  Also destroys all objects and class definitions
#  that inherit from the specified classes.
# ----------------------------------------------------------------------
proc itcl_unload {args} {
	foreach class [eval itcl_dependencies $args] {
		foreach o [itcl_info objects -class $class] {
		    $o delete
		}
		rename $class {}
	}

	foreach class $args {
		foreach o [itcl_info objects -class $class] {
		    $o delete
		}
		rename $class {}
	}
}

# ----------------------------------------------------------------------
#  USAGE:  itcl_reload <className>...
#
#  Destroys all objects in the specified classes, and all objects
#  that inherit from the specified classes.  Destroys and re-loads
#  the specified classes and any other classes that inherit from
#  the specified classes.  Useful during debugging to avoid having
#  to restart the program to recognize source changes.
# ----------------------------------------------------------------------
proc itcl_reload {args} {
	eval itcl_unload $args

	#
	# Reload specified classes and dependent classes.
	# NOTE:  Autoloading of class definitions is forced
	#        by invoking the class name with no arguments.
	#
	foreach class $args {
		$class
	}
	foreach class [eval itcl_dependencies $args] {
		$class
	}
}

# ----------------------------------------------------------------------
#  USAGE:  itcl_dependencies <className>...
#
#  Returns a list of classes that have the specified classes in their
#  inheritance hierarchy.  Each element in the return list will be
#  a unique class name.  Used in "itcl_unload" and "itcl_reload" to
#  unload and reload derived classes whenever the base classes change.
# ----------------------------------------------------------------------
proc itcl_dependencies {args} {
	set depends(x) make-this-an-array
	unset depends(x)

	set classes [itcl_info classes]
	foreach class $args {
		foreach dclass $classes {
			if {$dclass != $class} {
				set hier [$dclass :: info heritage]
				if {[lsearch $hier $class] >= 0} {
					set depends($dclass) $class
				}
			}
		}
	}
	return [array names depends]
}
