# =============================================================================
#
# File:		appbar-load.tcl
# Project:	TkDesk
#
# Started:	13.11.94
# Changed:	13.11.94
# Author:	cb
#
# Description:	Implements the "load" application bar special.
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
#s    proc _appbar_load {frame side}
#s    proc _appbar_bind_load {count}
#s    proc _appbar_get_load {}
#
# -----------------------------------------------------------------------------

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_load
# Args:		none
# Returns: 	""
# Desc:		Displays the system load in the appbar.
# Side-FX:	none
#

proc _appbar_load {frame side} {
    global tkdesk dsk_appbar

    if {$frame != ""} {
	set dsk_appbar(load,frame) $frame
    } else {
	set frame $dsk_appbar(load,frame)
    }
    
    set ft .dsk_appbar.fLoad
    if ![winfo exists $ft] {
	frame $ft -class "AppLoad" -cursor top_left_arrow
	pack $ft -fill both -expand yes -side $side -in $frame
    }
    set f .dsk_appbar.fLoad.f
    catch {destroy $f}
    frame $f -bd 2 -relief raised -cursor top_left_arrow
    pack $f -fill both -expand yes -in $ft

    set dsk_appbar(load,size) [_appbar_get_button_width]
    set cw $dsk_appbar(load,size)

    set ipad2 [expr $tkdesk(appbar,ipad) * 2] 
    canvas $f.cLoad -bd 0 -relief flat \
	    -width [expr $cw + $ipad2] -height [expr $cw + $ipad2] \
	    -cursor top_left_arrow -highlightthickness 0

    set adj [expr $tkdesk(appbar,ipad) / 2] 
    $f.cLoad create rectangle $adj $adj [expr $cw + $adj] [expr $cw + $adj] \
	    -fill white -outline black

    set dsk_appbar(load,scale) 1.0
    set dsk_appbar(load,lastx) 0
    set dsk_appbar(load,shrinkcnt) 0
    set dsk_appbar(load,uptime_ok) 0
   
    pack $f.cLoad -in $f
    _appbar_get_load

    return $f
}

proc _appbar_bind_load {count} {
    global dsk_appbar

    set f .dsk_appbar.fLoad.f
    _appbar_bind_special [list $f.cLoad] $count $f
}

proc _appbar_get_load {} {
    global dsk_appbar tkdesk

    set f .dsk_appbar.fLoad.f
    if ![winfo exists $f.cLoad] {
	return
    }

    if [file readable /proc/loadavg] {
	set uptime 0
	dsk_catch {
	    set fd [open /proc/loadavg]
	    set uptime [gets $fd]
	    close $fd
	}
	set load1 [lindex $uptime 0]
    } else {
	set err [catch {set uptime [exec uptime]} errmsg]
	if $err {
	    dsk_errbell
	    cb_alert "Executing uptime gave an error. Disabling load display."
	    return
	}
	set li [llength $uptime]
	set load1 [string trimright [lindex $uptime [incr li -3]] ,\;]
	regsub "," $load1 "." load1
	if !$dsk_appbar(load,uptime_ok) {
	    if ![regexp {[a-zA-Z:]} $load1] {
		set dsk_appbar(load,uptime_ok) 1
	    } else {
		cb_alert "Unknown uptime output. Please mail the output of the uptime command and your system type to Christian.Bolik@mainz.netsurf.de. Disabling load display."
		return
	    }
	}
    }

    set cw $dsk_appbar(load,size)
    set cw1 [expr $dsk_appbar(load,size) + 1]
    set oldscale $dsk_appbar(load,scale)
    if {$load1 >= $dsk_appbar(load,scale)} {
	set dsk_appbar(load,shrinkcnt) 0
	set dsk_appbar(load,scale) [expr ceil($load1)] 
    } else {
	if {$load1 > $dsk_appbar(load,scale) - 1.0} {
	    set dsk_appbar(load,shrinkcnt) 0
	} else {
	    incr dsk_appbar(load,shrinkcnt)
	    if {$dsk_appbar(load,shrinkcnt) >= $cw && $oldscale > 1.0} {
		set dsk_appbar(load,shrinkcnt) 0
		set dsk_appbar(load,scale) [expr $oldscale - 1.0]
	    }
	}
    }
    if {$oldscale != $dsk_appbar(load,scale)} {
	set scale $dsk_appbar(load,scale)
	catch {$f.cLoad delete scale}
	$f.cLoad scale load 1 $cw1 1 [expr $oldscale/$scale]
	if {$scale > 1.0} {
	    for {set y [expr $cw1 - round($cw/$scale)]} {$y > 1} { \
		    set y [expr $y - round($cw/$scale)]} {
		$f.cLoad create line 2 $y $cw1 $y -fill red -tags scale
	    }
	}
    }
    
    set y [expr $cw1 - round($load1 / $dsk_appbar(load,scale) * $cw.)]
    if {$dsk_appbar(load,lastx) < $cw} {
	set x [incr dsk_appbar(load,lastx)]
    } else {
	set x $cw
	$f.cLoad move load -1 0
	#set d [$f.cLoad find closest 1 $cw]
	#if {[$f.cLoad gettags $d] == "load"} {
	#    $f.cLoad delete $d
	#}
	eval $f.cLoad delete [$f.cLoad find enclosed -100 0 1 [expr $cw +2]]
    }
    $f.cLoad create line $x $cw1 $x $y -tags load
    catch {$f.cLoad raise scale load}

    if [info exists dsk_appbar(load,afterid)] {
	catch {after cancel $dsk_appbar(load,afterid)}
    }
    set dsk_appbar(load,afterid) \
	    [after [expr $tkdesk(appbar,load,delay) * 1000] _appbar_get_load]
}

