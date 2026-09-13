# =============================================================================
#
# File:		appbar-date.tcl
# Project:	TkDesk
#
# Started:	13.11.94
# Changed:	13.11.94
# Author:	cb
#
# Description:	Implements the "date" application bar special.
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
#s    proc _appbar_date {frame side}
#s    proc _appbar_bind_date {count}
#s    proc _appbar_get_date {}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_date
# Args:		none
# Returns: 	""
# Desc:		Displays the time and date in the application bar.
# Side-FX:	none
#

proc _appbar_date {frame side} {
    global tkdesk dsk_appbar

    if {$frame != ""} {
	set dsk_appbar(date,frame) $frame
    } else {
	set frame $dsk_appbar(date,frame)
    }
    
    set ft .dsk_appbar.fDate
    if ![winfo exists $ft] {
	frame $ft -class "AppDate" -cursor top_left_arrow
	pack $ft -fill both -expand yes -side $side -in $frame
    }
    set f .dsk_appbar.fDate.f
    catch {destroy $f}
    frame $f -bd 2 -relief raised -cursor top_left_arrow
    pack $f -fill both -expand yes -in $ft

    label $f.lTime -font [cb_font $tkdesk(appbar,font,time)] \
	    -pady 0 -cursor top_left_arrow \
	    -bg $tkdesk(appbar,time,background) \
	    -fg $tkdesk(appbar,time,foreground) \
	    -bd $tkdesk(appbar,time,borderwidth) \
	    -relief $tkdesk(appbar,time,relief)
    label $f.lWeekday -font [cb_font $tkdesk(appbar,font,weekday)] \
	    -pady 0 -cursor top_left_arrow
    label $f.lDay -font [cb_font $tkdesk(appbar,font,day)] \
	    -pady 0 -cursor top_left_arrow
    label $f.lMonth -font [cb_font $tkdesk(appbar,font,month)] \
	    -pady 0 -cursor top_left_arrow

    set cw [_appbar_get_button_width]
    set cw4 [expr $cw + ($tkdesk(appbar,ipad) * 2)]
    set cw42 [expr $cw4 / 2]
    
    if {$dsk_appbar(layout) == "vertical"} {
	canvas $f.cDate -bd 0 -relief flat -width $cw4 -height 76 \
		-cursor top_left_arrow -highlightthickness 0

	$f.cDate create window $cw42 2 -window $f.lTime -anchor n
	$f.cDate create window $cw42 20 -window $f.lWeekday -anchor n
	$f.cDate create window $cw42 34 -window $f.lDay -anchor n
	$f.cDate create window $cw42 58 -window $f.lMonth -anchor n

	if {$cw >= 48} {
	    # nasty hack...
	    $f.lTime config -width 6
	}
    } else {
	canvas $f.cDate -bd 0 -relief flat -width 76 -height $cw4 \
		-cursor top_left_arrow -highlightthickness 0

	$f.cDate create window 18 2 -window $f.lTime -anchor n
	$f.cDate create window 18 [expr $cw42 - 1] -window $f.lMonth -anchor n
	$f.cDate create window 58 4 -window $f.lDay -anchor n -height 20
	$f.cDate create window 58 [expr $cw42 + 6] \
		-window $f.lWeekday -anchor n -height 10
    }
    raise $f.lTime
    raise $f.lWeekday
    raise $f.lDay
    raise $f.lMonth

    pack $f.cDate -in $f -fill none -expand yes

    _appbar_get_date
    return $f
}

proc _appbar_bind_date {count} {
    global dsk_appbar

    set f .dsk_appbar.fDate.f
    _appbar_bind_special \
	    [list $f.lTime $f.lWeekday $f.lDay $f.lMonth $f.cDate] \
	    $count $f
}

set _ab_date(wday,0) "Sun"; set _ab_date(wday,1) "Mon"; 
set _ab_date(wday,2) "Tue"; set _ab_date(wday,3) "Wed"; 
set _ab_date(wday,4) "Thu"; set _ab_date(wday,5) "Fri"; 
set _ab_date(wday,6) "Sat";

set _ab_date(mon,0) "Jan"; set _ab_date(mon,1) "Feb"; 
set _ab_date(mon,2) "Mar"; set _ab_date(mon,3) "Apr"; 
set _ab_date(mon,4) "May"; set _ab_date(mon,5) "Jun"; 
set _ab_date(mon,6) "Jul"; set _ab_date(mon,7) "Aug"; 
set _ab_date(mon,8) "Sep"; set _ab_date(mon,9) "Oct"; 
set _ab_date(mon,10) "Nov"; set _ab_date(mon,11) "Dec"; 

proc _appbar_get_date {} {
    global dsk_appbar tkdesk _ab_date

    set f .dsk_appbar.fDate.f
    if ![winfo exists $f.lTime] {
	return
    }

    if {[info command clock] == {}} {
	# Tcl < 7.5 doesn't have clock
	array set time [dskC_localtime]

	if !$tkdesk(appbar,12hour) {
	    $f.lTime config -text "$time(hour):$time(min)"
	} else {
	    # fix contributed by jcc@snm.com (J. Chris Coppick)
	    if {$time(hour) > 12} {
		scan $time(hour) {%d} hour
		$f.lTime config -text \
			[format "%02d:%02s" [expr $hour % 12] $time(min)]
	    } elseif {$time(hour) == 0} {
		$f.lTime config -text "12:$time(min)"
	    } else {
		$f.lTime config -text "$time(hour):$time(min)"
	    }
	}
	if {$time(wday) == 0} {
	    # it's a Sunday
	    set col red
	} else {
	    set col [cb_col $tkdesk(color,foreground)]
	}
	$f.lWeekday config -text $_ab_date(wday,$time(wday)) -fg $col
	$f.lDay config -text $time(mday)
	$f.lMonth config -text $_ab_date(mon,$time(mon))
    } else {
	if !$tkdesk(appbar,12hour) {
	    ot_maplist [clock format [clock seconds] \
		    -format "%M %H %d %b %a"] \
		    time(min) time(hour) time(mday) mon wday
	} else {
	    ot_maplist [clock format [clock seconds] \
		    -format "%M %I %d %b %a"] \
		    time(min) time(hour) time(mday) mon wday
	}
	$f.lTime config -text "$time(hour):$time(min)"
	if {$wday == "Sun"} {
	    # it's a Sunday
	    set col red
	} else {
	    set col [cb_col $tkdesk(color,foreground)]
	}
	$f.lWeekday config -text $wday -fg $col
	$f.lDay config -text [string trimleft $time(mday) "0"]
	$f.lMonth config -text $mon
    }

    if [info exists dsk_appbar(date,afterid)] {
	catch {after cancel $dsk_appbar(date,afterid)}
    }
    set dsk_appbar(date,afterid) [after 60000 _appbar_get_date]
}

