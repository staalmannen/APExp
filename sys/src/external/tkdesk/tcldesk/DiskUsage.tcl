# =============================================================================
#
# File:		DiskUsage.tcl
# Project:	TkDesk
#
# Started:	22.10.94
# Changed:	22.10.94
# Author:	cb
#
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
#s    itcl_class dsk_DiskUsage
#s    method config {config}
#s    method refresh {}
#s    proc id {}
#s    proc dsk_du {dir}
#
# -----------------------------------------------------------------------------

#
# =============================================================================
#
# Class:	dsk_DiskUsage
# Desc:		Creates a window for displaying the disk usage
#		of a directory.
#
# Methods:	
# Procs:	
# Publics:	directory	name of directory
#

itcl_class dsk_DiskUsage {
    inherit Toplevel

    constructor {args} {
	global tkdesk

	if {$tkdesk(tcl_version) < 8.0} {
	    Toplevel::constructor
	}
	
	wm withdraw $top

	frame $top.fl -bd 1 -relief raised
	pack $top.fl -fill x

	label $top.lDir -text ""
	pack $top.lDir -in $top.fl -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	cb_listbox $top.flb -vscroll 1 -hscroll 1 -lborder 1 -uborder 1 \
		-width 5 -height 1 -font [cb_font $tkdesk(font,mono)] \
		-selectmode single
	$top.flb config -bd 1 -relief raised
	pack $top.flb -fill both -expand yes

	bind $top.flb.lbox <Double-1> {
	    dsk_open_dir [lindex [%W get [%W nearest %y]] 1]
	}
	bind $top.flb.lbox <3> {
	    dsk_popup {} [lindex [%W get [%W nearest %y]] 1] %X %Y
	}

	frame $top.fb -bd 1 -relief raised
	pack $top.fb -fill x

	button $top.bClose -text " Close " -command "$this delete"
	button $top.bRefresh -text " Refresh " -command "$this refresh"
	pack $top.bClose $top.bRefresh -in $top.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

	wm minsize $top 40 16
	#wm geometry $top 40x15
	wm title $top "Disk Usage"
	wm protocol $top WM_DELETE_WINDOW "$this delete"

	eval config $args
    }

    destructor {
    }

    #
    # ----- Methods and Procs -------------------------------------------------
    #

    method config {config} {
    }

    method refresh {} {
	$this config -directory $directory
    }

    proc id {} {
	set i $id
	incr id
	return $i
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    public dir "/" {
	$this config -directory $dir
    }

    public directory "/" {
	global tkdesk
	
	#dsk_busy
	dsk_status "Determining disk usage..."

	if {$directory != "/"} {
	    set directory [cb_tilde [string trimright $directory "/"] expand]
	}
	$top.lDir config -text "Disk Usage of [cb_tilde $directory collapse]:"

	# automatically read linked directories
	set err [catch {set d [file readlink $directory]}]
	if !$err {
	    if [file exists $d] {
		set directory $d
	    }
	}

	$top.bClose config -state disabled
	$top.bRefresh config -state disabled
	set du_list \
		[dsk_bgexec "$tkdesk(cmd,du) [list $directory] | $tkdesk(cmd,sort) 2>@stderr" \
		"Determining disk usage..."]
	$top.bClose config -state normal
	$top.bRefresh config -state normal
	if {$du_list != "break"} {
	    set du_list [split $du_list \n]
	    $top.flb.lbox delete 0 end
	    foreach d $du_list {
	    	$top.flb.lbox insert end [string trimright [format "%6s %s" \
	    	    [lindex $d 0] [cb_tilde [lrange $d 1 1000] collapse]] "\n"]
	    }
	    $top.flb.lbox config -width 40 \
		    -height [cb_min 15 [cb_max 2 [llength $du_list]]]
	    update idletasks
	    if {[wm state $top] == "withdrawn"} {
		dsk_place_window $top diskusage ""
		wm deiconify $top
	    }
	} else {
	    if {[wm state $top] == "withdrawn"} {
		after 200 $this delete
	    }
	}
	dsk_status "Ready."
	#dsk_lazy
    }

    common id 0
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_du
# Args:		dir	name of directory
# Returns: 	""
# Desc:		Creates an object of class dsk_DiskUsage on $dir.
# Side-FX:	
#

proc dsk_du {dir} {
    if ![file isdirectory $dir] {
	set dir [file dirname $dir]
    }

    if {$dir != ""} {
    	dsk_DiskUsage .du[dsk_DiskUsage :: id] -directory $dir
    }
}

