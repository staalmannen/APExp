# =============================================================================
#
# File:		util.tcl
# Project:	TkDesk
#
# Started:	11.10.94
# Changed:	11.10.94
# Author:	cb
#
# Description:	Misc. utility procs.
#
# Copyright (C) 1996  Christian Bolik
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
# See the file "COPYING" in the base directory of this distribution
# for more.
#
# -----------------------------------------------------------------------------
#
# Sections:
#s    proc dsk_debug {args}
#s    proc dsk_busy {{what ""}}
#s    proc dsk_busy_config {}
#s    proc dsk_lazy {{what ""} {force 0}}
#s    proc dsk_status {str {do_update 1}}
#s    proc dsk_status_ready {{do_update 1}}
#s    proc dsk_fs_status {{file ""}}
#s    proc dsk_logname {}
#s    proc dsk_hostname {}
#s    proc dd_handle_text {w {replace 0}}
#s    proc _make_path_valid {path {fallback ""}}
#s    proc dsk_maplist {list args}
#s    proc dsk_active {what {arg ""}}
#s    proc dsk_place_window {top name defgeom {grid 0} {center 0}}
#s    proc dsk_image {file args}
#s    proc dsk_auto_execok {cmd}
#s    proc dsk_catch {script {format "%s"}}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_debug
# Args:		args		Optional -nonewline and string to print.
# Returns: 	""
# Desc:		Prints an arbitrary string on stderr if tkdesk(debug) is != 0.
# Side-FX:	none
#

proc dsk_debug {args} {
    global tkdesk

    if {!$tkdesk(debug)}  {
	return
    }

    if {[llength $args] < 1} {
	error "too few arguments to dsk_debug"
    }

    set str [join $args]
    set nonewline 0
    if [string match "-nonew*" [lindex $args 0]] {
	set nonewline 1
	catch {set str [lreplace $str 0 0]}
    }

    if $nonewline {
    	catch {puts -nonewline stderr $str}
    } else {
    	catch {puts stderr $str}
    }
    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_busy
# Args:		windows (opt.) list of busy windows
# Returns: 	""
# Desc:		Displays the cursor in busy state.
# Side-FX:	none
#

global dsk_busy
set dsk_busy(still_busy) 0
set dsk_busy(ms) 200
set dsk_busy(windows) {}
set dsk_busy(busy) {}

proc dsk_busy {{windows ""}} {
    global cb_tools tkdesk dsk_busy cb_balloonHelp

    #if {[info level] <= 1} {
    #	 puts "toplevel: dsk_busy $windows"
    #} else {
    #	 puts "[info level]: [info level -1]: dsk_busy $windows"
    #}
    if {$windows != ""} {
	foreach win $windows {
	    #puts "blt_busy(1) hold $win"
	    catch {blt_busy hold $win \
		    -cursor "@$cb_tools(path)/bitmaps/timer1.xbm \
		    $cb_tools(path)/bitmaps/timer.mask.xbm black white"}
	    if {[lsearch $dsk_busy(windows) $win] < 0} {
		lappend dsk_busy(windows) $win
	    }
	}
	return
    }

    incr dsk_busy(still_busy)
    set tkdesk(status) busy
    set dsk_busy(busy) {}
    
    foreach class {dsk_FileViewer dsk_FileList dsk_DiskUsage dsk_FileInfo
                   dsk_Periodic dsk_Editor dsk_DeskItem} {
	foreach obj [itcl_info objects -class $class] {
	    lappend dsk_busy(busy) [$obj getToplevel]
	}
    }
    foreach w [winfo children .] {
	if {[winfo class $w] == "Toplevel"} {
	    lappend dsk_busy(busy) $w
	}
    }

    set cb_balloonHelp(bltbusy) 1
    foreach win $dsk_busy(busy) {
	#puts "blt_busy(2) hold $win"
	catch {blt_busy hold $win \
		-cursor "@$cb_tools(path)/bitmaps/timer1.xbm \
		$cb_tools(path)/bitmaps/timer.mask.xbm black white"}
    }

    # Let the <Leave> event be transferred first:
    update
    set cb_balloonHelp(bltbusy) 0
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_lazy
# Args:		windows (opt.) list of now lazy windows
# Returns: 	""
# Desc:		Displays the cursor in normal state.
# Side-FX:	none
#

proc dsk_lazy {{windows ""} {force ""}} {
    global tkdesk dsk_busy

    if {$windows == "force" && $force == ""} {
	set force "force"
	set windows ""
    }

    #if {[info level] <= 1} {
    #	 puts "toplevel: dsk_lazy $windows $dsk_busy(still_busy) $force"
    #} else {
    #	 puts "[info level -1]: dsk_lazy $windows $dsk_busy(still_busy) $force"
    #}
    if {$windows != ""} {
    	 foreach win $windows {
    	     catch {blt_busy release $win}
	     set l [lsearch $dsk_busy(windows) $win]
	     if {$l >= 0} {
		 set dsk_busy(windows) [lreplace $dsk_busy(windows) $l $l]
	     } else {
		 puts stderr "$win: not busy ?!"
	     }
    	 }
    	 return
    }

    if {$force != ""} {
	set dsk_busy(still_busy) 0
    } else {
	if {$tkdesk(status) == "lazy"} {
	    return
	}
	incr dsk_busy(still_busy) -1
	if {$dsk_busy(still_busy) > 0} {
	    return
	}
    }
    
    foreach win $dsk_busy(busy) {
	if {([lsearch $dsk_busy(windows) $win] < 0) || ($force != "")} {
	    catch {blt_busy release $win}
	}
    }
    
    set tkdesk(status) lazy
    update idletasks
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_status
# Args:		str	string to display
# Returns: 	""
# Desc:		Displays $str in the status bar of all file viewers.
# Side-FX:	none
#

global tkdesk
if ![info exists tkdesk(inhibit_status)] {
    set tkdesk(inhibit_status) 0
}

proc dsk_status {str {do_update 1}} {
    global tkdesk

    if $tkdesk(inhibit_status) return
    
    if [winfo exists .dsk_welcome] {
	dsk_progress $str
    }
    
    foreach fv [itcl_info objects -class dsk_FileViewer] {
	catch {$fv status $str $do_update}
    }
    foreach fv [itcl_info objects -class dsk_FileList] {
	catch {$fv status $str $do_update}
    }
}

proc dsk_status_ready {{do_update 1}} {
    global tkdesk

    if $tkdesk(inhibit_status) return

    if [winfo exists .dsk_welcome] {
	dsk_progress "Waiting..."
    }
    
    foreach fv [itcl_info objects -class dsk_FileViewer] {
	catch {$fv status_ready $do_update}
    }
    foreach fv [itcl_info objects -class dsk_FileList] {
	catch {$fv status_ready $do_update}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_fs_status
# Args:		file - opt. name of file
# Returns: 	A string that contains the available disk space.
# Desc:		...
# Side-FX:	none
#

proc dsk_fs_status {{file ""}} {
    global tkdesk

    if {$file == ""} {
	set file [dsk_active dir]
    }

    #dsk_busy
    set err [catch {set dfout [dskC_statfs [cb_tilde $file expand]]} errmsg]
    if $err {
	catch {puts stderr "dsk_fs_status $file: $errmsg"}
	return ""
    }

    set fsstr ""
    if {$dfout != ""} {
	ot_maplist $dfout total avail perc
	catch {set fsstr " [format %.1f [expr $avail./1000]] MB available (${perc}%)."}
    }

    return $fsstr
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_logname
# Args:		none
# Returns: 	The user's login name.
# Desc:		
# Side-FX:	none
#

set dsk_logname(name) ""

proc dsk_logname {} {
    global tkdesk dsk_logname

    if {$dsk_logname(name) == ""} {
	set err [catch {
	    set dsk_logname(name) [eval exec $tkdesk(cmd,whoami)]
	} errmsg]
	if $err {
	    puts stderr "TkDesk: error executing $tkdesk(cmd,whoami): $errmsg"
	}
    }
    return $dsk_logname(name)
}

# ----------------------------------------------------------------------------
# dsk_is_superuser:
# Returns 1 if the current user has uid 0 or is "root", 0 otherwise.
#

proc dsk_is_superuser {} {
    set uid -1
    set err [catch {set uid [exec id -u]}]
    if $err {
	return [string match [dsk_logname] "root"]
    } else {
	return [expr $uid == 0]
    }
}

# ----------------------------------------------------------------------------
# dsk_hostname:
# Returns the name of the machine TkDesk is running on.

set dsk_hostname(name) ""

proc dsk_hostname {} {
    global dsk_hostname

    if {$dsk_hostname(name) == ""} {
	set err [catch {set dsk_hostname(name) [exec hostname]}]
	if $err {
	    set err [catch {set dsk_hostname(name) [exec uname -n]}]
	    if $err {
		set dsk_hostname(name) "unknown"
	    }
	}
    }
    return $dsk_hostname(name)
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dd_handle_text
# Args:		w		widget name
#		replace 	(opt.) set to 1 if ex. text should be deleted
# Returns: 	""
# Desc:		Drop handler for entry and text widgets.
# Side-FX:	none
#

proc dd_handle_text {w text {replace 0}} {

    if !$replace {
    	$w insert insert $text
    } else {
	$w delete 0 end
	$w insert end $text
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_make_path_valid
# Args:		path		path to shorten to a valid path
#		fallback	fallback path if $path is totally broken
# Returns: 	a valid path
# Desc:		see above
# Side-FX:	none
#

set _make_path_valid(barrier) 0

proc _make_path_valid {path {fallback ""}} {
    global tkdesk env _make_path_valid

    if {$fallback == ""} {
	set fallback $env(HOME)
	if ![file isdirectory $fallback] {
	    set fallback "/"
	}
    }

    catch {set path [cb_tilde $path collapse]}
    if {[string index $path 0] != "/" && [string index $path 0] != "~"} {
	if !$_make_path_valid(barrier) {
	    set _make_path_valid(barrier) 1
	    set path [dsk_active dir]/$path
	} else {
	    set _make_path_valid(barrier) 0
	    set path $fallback
	}
    }

    set isdir 0
    set err [catch {set isdir [file isdirectory $path]}]
    if $isdir {
	return $path
    }

    set vpath ""
    for {set i 1} {$i < [string length $path]} {incr i} {
	if {[string index $path $i] == "/"} {
	    set tpath [string range $path 0 [expr $i - 1]]
	    set isdir 0
	    set err [catch {set isdir [file isdirectory $tpath]}]
	    if $isdir {
		set vpath $tpath
	    } else {
		break
	    }
	}
    }

    if {$vpath == ""} {
	set vpath $fallback
    }

    return $vpath
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_maplist
# Args:		list - a tcl list
#               args - a list of variable name that will be set to the elements
#                      of $list
# Returns: 	""
# Desc:		see Args
# Side-FX:	none
#

proc dsk_maplist {list args} {

    set i 0
    foreach var $args {
	upvar $var v
	set v [lindex $list $i]
	incr i
    }

    return ""
}

# ----------------------------------------------------------------------------
# dsk_active what:
# what can be one of: directory/dir, selection/sel, viewer.
# Returns the current directory, selection, number of viewer/list windows.
# Also set the environment variable TKDESKDIR if $what is dir.
#
# [What an odd proc... :-) --JCC]
#
proc dsk_active {what {arg ""}} {
    global tkdesk env

    if {[itcl_info objects $tkdesk(active_viewer)] == ""} {
	set fvl "[itcl_info objects -class dsk_FileViewer] \
		[itcl_info objects -class dsk_FileList]"
	set tkdesk(active_viewer) [lindex $fvl 0]
    }
    if {[itcl_info objects $tkdesk(active_viewer)] == ""} {
	set tkdesk(active_viewer) ""
    }
    dsk_debug "tkdesk(active_viewer) $tkdesk(active_viewer)"

    switch -glob $what {
	win* {
	    return $tkdesk(active_viewer)
	}
	dir* {
	    if {$tkdesk(active_viewer) != ""} {
		if {$arg == ""} {
		    set adir [$tkdesk(active_viewer) curdir]
		} else {
		    $tkdesk(active_viewer) config -dir $arg
		    return
		}
	    } else {
		set adir [pwd]
	    }
	    if ![file isdirectory $adir] {
		set adir [_make_path_valid $adir]
	    }
	    return $adir
	}
	sel* {
	    if {$tkdesk(active_viewer) != ""} {
		return [$tkdesk(active_viewer) select get]
	    } else {
		return ""
	    }
	}
	viewer {
	    return [llength "[itcl_info objects -class dsk_FileViewer] \
		[itcl_info objects -class dsk_FileList]"]
	}
    }
}

# ----------------------------------------------------------------------------
# dsk_place_window top name default
# Positions the window $top on the screen. $default is the default
# geometry of the form <width>x<height>. $name will be used for accessing
# the windows saved geometry.
#
proc dsk_place_window {top name defgeom {grid 0} {center 0}} {
    global tkdesk

    if {![info exists tkdesk(geometry,$name)]} {
	set tkdesk(geometry,$name) ""
    }

    if {$defgeom == ""} {
	update idletasks
	set defgeom "[winfo reqwidth $top]x[winfo reqheight $top]"
    }
    
    if {$tkdesk(at_pointer)} {
	if {$tkdesk(geometry,$name) == ""} {
	    set l [split $defgeom x]
	} else {
	    set l [split $tkdesk(geometry,$name) x+]
	}
	set w [lindex $l 0]
	set h [lindex $l 1]
	set sw [winfo screenwidth $top]
	set sh [winfo screenheight $top]
	if $grid {
	    update idletasks
	    set gw [winfo reqwidth $top]
	    set gh [winfo reqheight $top]
	} else {
	    set gw $w
	    set gh $h
	}
	while {1} {
	    set oldgw $gw
	    set oldgh $gh
	    set x [winfo pointerx $top]
	    set y [winfo pointery $top]
	    incr x -[expr $gw / 2]
	    incr y -[expr $gh / 2]
	    #incr y -[expr $h - 0]
	    if {$x < 0} {set x 0}
	    if {$x + $gw > $sw} {set x [expr $sw - $gw - 6]}
	    if {$y < 0} {set y 0}
	    if {$y + $gh > $sh} {set y [expr $sh - $gh - 34]}
	    #puts "$top ${w}x${h}+${x}+${y}, ${gw}x${gh}"
	    wm geometry $top ${w}x${h}+${x}+${y}
	    update
	    set gw [winfo width $top]
	    set gh [winfo height $top]
	    #puts "gw $gw, oldgw $oldgw"
	    #puts "gh $gh, oldgh $oldgh"
	    if {$oldgw >= $gw && $oldgh >= $gh} {
		break
	    }
	}
    } else {
	if {$tkdesk(geometry,$name) == ""} {
	    if $center {
		cb_centerToplevel $top
	    } else {
		wm geometry $top $defgeom
	    }
	} else {
	    wm geometry $top $tkdesk(geometry,$name)
	}
	update
    }
    wm sizefrom $top program
}

# ----------------------------------------------------------------------------
# dsk_image:
# Front end for cb_image, looks in $tkdesk(path,images) for $file.
#
proc dsk_image {file args} {
    global tkdesk

    set unknown $tkdesk(library)/images/xlogo16.xpm

    if {[string index $file 0] == "/" || \
	    [string index $file 0] == "~"} {
	set file $file
    } else {
	foreach p [split $tkdesk(path,images) ":"] {
	    if [file exists $p/$file] {
		set file $p/$file
		break
	    }
	}
    }
    if ![file exists $file] {set file $unknown}

    set err [catch {set img [eval cb_image [list $file] $args]} errmsg]
    if $err {
	puts stderr $errmsg
	set img [eval cb_image $unknown $args]
    }
    return $img
}

# ----------------------------------------------------------------------------
# dsk_auto_execok cmd
# Returns 1 if $cmd is in $PATH, 0 otherwise.  "Virtualizes" the Tcl
# version-specific auto_execok.
#
proc dsk_auto_execok {cmd} {
    global tcl_version auto_execs

    if {[file dirname $cmd] != "."} {
	if ![file exists $cmd] {
	    return 0
	} else {
	    if ![file_executable $cmd] {
		return 0
	    }
	}
    }

    if {$tcl_version > 7.5} {
	if {[auto_execok $cmd] != ""} {
	    set ret 1
	} else {
	    set ret 0
	}
    } else {
	set ret [auto_execok $cmd]
    }

    if {!$ret} {
	# don't cache commands not found yet
	catch {unset auto_execs($cmd)}
    }
    return $ret
}

# ----------------------------------------------------------------------------
# dsk_catch script ?format?
# Evaluates $script in the context of the calling proc. If an error
# occurs inside this script, the error message is displayed in a
# dialog box.  If $format is given, it's a printf format string
# in which %s will be replaced with the error message.
#
proc dsk_catch {script {format "%s"}} {
    set err [catch {uplevel 1 $script} errmsg]
    if $err {
	# [todo] where does this dsk_lazy come from???
	#dsk_lazy force
	dsk_errbell
	cb_error [format $format $errmsg]
    }
    return $err
}

# ----------------------------------------------------------------------------
# dsk_canon_path path
# Removes all "/./" and "/../" from $path.  Any "~" characters in $path will
# not be expanded!
#
proc dsk_canon_path {path} {

    if {[string first "/./" $path] > -1 || [string first "/../" $path] > -1} {
	set dlist [split $path "/"]
	set plist {}
	set plen 0
	foreach d $dlist {
	    if {$d == "."} {
		continue
	    } elseif {$d == ".."} {
		if {$plen > 0} {
		    incr plen -1
		    set plist [lreplace $plist $plen 1000]
		}
	    } else {
		lappend plist $d
		incr plen
	    }
	}
	set path [join $plist "/"]
	if {$path == ""} {
	    set path "/"
	}
    }
    
    return $path
}
