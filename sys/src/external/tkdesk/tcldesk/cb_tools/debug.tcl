# =============================================================================
#
# File:		cb_debug.tcl
# Project:	cb_tools
# Started:	06.10.94
# Changed:	06.10.94
#
# Description:	Implements functions for simple debugging of Tcl/Tk apps.
#
# -----------------------------------------------------------------------------
#
# Sections:
#
# =============================================================================

# -----------------------------------------------------------------------------
# cb_debug: Meta-proc for all debugging facilities
#	Syntax: cb_debug <cmd> ?options?

proc cb_debug {cmd args} {

    set result {}
    switch -glob -- $cmd {
	proc*	{set result [eval cb_debug_procs $args]}
	trace	{set result [eval cb_debug_trace $args]}
	var*	{set result [eval cb_debug_var $args]}
	default	{error "cb_debug: unknown command $cmd"}
    }

    return $result
}

# -----------------------------------------------------------------------------
# cb_debug_procs: Inserts code into the body of procs to print its name,
#		  arguments, entry and exit.
#	Syntax: cb_debug procs ?options?
#	Options: -exclude	list of glob pattern for procs to exclude
#		 -only		list of glob pattern that procs must match
#

proc cb_debug_procs {args} {
    set proc_exclude {}
    set proc_only {*}

    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [lindex $args $i]
	    switch -glob -- $o {
		-ex*	{incr i
			set proc_exclude [lindex $args $i]
			}
		-only	{incr i
			set proc_only [lindex $args $i]
			}
		default {error "cd_debug procs: unknown option $o"}
	    }
	}
    }

    puts stderr "Preparing for procs debugging..."

    set procs [info procs]
    set skip 0
    foreach proc $procs {
	foreach ex $proc_exclude {
	    if [string match $ex $proc] {
		#
		# Skip this procedure
		#
		set skip 1
		break
	    }
	}

	if $skip {
	    set skip 0
	    continue
	}

	if ![string match $proc_only $proc] {
	    continue
	}

	set proc_args [info args $proc]
	set proc_body [info body $proc]

	set prolog "puts stderr \"\n$proc \t(level: \[info level\])\"\n"
	foreach arg $proc_args {
	    append prolog "puts stderr \"\t$arg: \$$arg\"\n"
	}
	append prolog "puts stderr \"\tEntry ($proc)\"\n"

	set epilog "puts stderr \"\tExit ($proc)\"\n"

	proc $proc $proc_args "
	    [set prolog]
	    [set proc_body]
	    [set epilog]
	"
    }

    puts stderr "Done."
}


proc cb_debug_trace {cmd} {
    rename $cmd ${cmd}-original
    proc $cmd {args} "
	puts -nonewline \"$cmd \$args \"
        catch \{puts \"(\[info level -1\])\"\}
        return \[eval ${cmd}-original \$args\]
    "
    return ${cmd}-original
}


# ----------------------------------------------------------------------------
# cb_trace var ?what?:
# A frontend to Tcl's trace command. Creates a trace on var, which outputs
# a line on stderr whenever the variable is accessed. $what may be one of
# w (write, default), r (read) and u (unset).
#
proc cb_trace {var {what w}} {
    uplevel 1 trace variable $var $what _cb_trace
}

proc _cb_trace {n1 n2 op} {
    if {$n2 != ""} {
	puts -nonewline stderr "$op ${n1}($n2) = [uplevel 1 set [set n1]($n2)]: "
    } else {
	puts -nonewline stderr "$op ${n1} = [uplevel 1 set [set n1]]: "
    }
    puts stderr "[info level [uplevel 1 info level]]"
}

# ----------------------------------------------------------------------------
# cb_debug_var var:
# Prints name and value of var to stderr.
#
proc cb_debug_var {var} {
    upvar 2 $var v
    if ![info exists v] {
	puts stderr "$var: does not exist"
    } else {
	puts stderr "$var: \"$v\""
    }
}
