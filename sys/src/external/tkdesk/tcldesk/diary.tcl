# =============================================================================
#
# File:		diary.tcl
# Project:	TkDesk
#
# Started:	5.4.97
# Changed:	5.4.97
# Author:	cb
#
# Description:	Implements the diary.
#
# Copyright (C) 1996, 1997  Christian Bolik
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
#s    proc dsk_diary_init {}
#s    proc dsk_diary_process_date {date}
#s    proc dsk_diary_process_time {time}
#s    proc dsk_diary_check {}
#s    proc dsk_diary_list {{date today} {show_none 1}}
#
# =============================================================================

global env
set dsk_diary(filename) $env(HOME)/Diary.tcl
set dsk_diary(list_after_startup) 1
set dsk_diary(list_at_midnight) 1

# fill weekday map:
foreach d {Mon Tue Wed Thu Fri Sat Sun} \
	fd {monday tuesday wednesday thursday friday saturday sunday} \
	gd {mo di mi do fr sa so} \
	gfd {montag dienstag mittwoch donnerstag freitag samstag sonntag} {
    
    set dsk_diary(map,$d) $d
    set dsk_diary(map,$fd) $d
    set dsk_diary(map,$gd) $d
    set dsk_diary(map,$gfd) $d
}
set dsk_diary(map,Sonnabend) Sat
set dsk_diary(map,heute) today


# -----------------------------------------------------------------------------
# dsk_diary_init:
# Initializes the diary background procs.
#
proc dsk_diary_init {} {
    global tkdesk dsk_diary dsk_diary_entry

    # read Diary:
    set err [catch {source $dsk_diary(filename)} errmsg]
    if $err {
	cb_error $errmsg
	return
    }

    set dsk_diary(listwin) ""
    if [info exists dsk_diary(after_id)] {
	catch {after cancel $dsk_diary(after_id)}
	catch {unset dsk_diary(entries)}
	foreach ent [array names dsk_diary_entry] {
	    unset dsk_diary_entry($ent)
	}
    }
    
    if [info exists tkdesk(diary)] {
	# process diary list:
	foreach app $tkdesk(diary) {
	    ot_maplist $app date time message
	    set date [string trim $date]
	    set time [string tolower [string trim $time]]

	    # process date:
	    catch {unset wd}
	    ot_maplist [dsk_diary_process_date $date] wd d m y
	    if ![info exists wd] {
		cb_error "Unknown date format: $date"
		continue
	    }

	    # process time:
	    ot_maplist [dsk_diary_process_time $time] H M

	    # set internal diary entry:
	    #puts "set dsk_diary_entry($wd-$d.$m.$y-$H:$M) $message"
	    lappend dsk_diary(entries) $wd-$d.$m.$y-$H:$M
	    set dsk_diary_entry($wd-$d.$m.$y-$H:$M) [list $date $time $message]
	}

	if ![info exists dsk_diary(after_id)] {
	    if $dsk_diary(list_after_startup) {
		dsk_diary_list today 0
	    }
	}
	
	# normalize period:
	set tkdesk(diary,period) [expr 60 / \
		round (60./$tkdesk(diary,period))]
	#puts "using period: $tkdesk(diary,period)"
	set dsk_diary(period) [expr $tkdesk(diary,period) * 60 * 1000]

	# determine time to first check:
	set min [clock format [clock seconds] -format %M]
	set min [string trimleft $min 0]
	if {$min == ""} {set min 0}
	set p $tkdesk(diary,period)
	set t [expr (($min/$p + 1) * $p - $min) * 60 * 1000]
	#puts "first check in [expr $t / 60000] minutes"
	set dsk_diary(after_id) [after $t dsk_diary_check]
    }
}

# -----------------------------------------------------------------------------
# dsk_diary_process_date date:
# Normalizes $date. Returns a list of {weekday day month year}.
#
proc dsk_diary_process_date {date} {
    global dsk_diary

    set date [string tolower $date]
    set wd "*"
    if {[string first "." $date] > -1} {
	# european format
	ot_maplist [split $date .] d m y
    } elseif {[string first "/" $date] > -1} {
	# US-american format
	set y ""
	ot_maplist [split $date /] m d y
    } elseif {$date == "*"} {
	set d "*"
	set m "*"
	set y "*"
    } else {
	# maybe a single weekday?
	set err [catch {set wd $dsk_diary(map,$date)}]
	if $err {
	    return ""
	} else {
	    if {$wd == "today"} {
		ot_maplist [clock format [clock seconds] -format "%d %m %Y"] \
			d m y
		set wd "*"
	    } else {
		set d "*"
		set m "*"
		set y "*"
	    }
	}
    }
    set $d [string trimleft $d 0]
    set $m [string trimleft $m 0]
    set cury [clock format [clock seconds] -format %Y]
    if {$y == ""} {
	set y $cury
    } else {
	set $y [string trimleft $y 0]
	if {$y == ""} {set y 0}
    }
    if {$y != "*"} {
	if {[string length $y] != 4} {
	    set y [expr $y + ($cury / 100) * 100]
	}
    }

    return [list $wd $d $m $y]
}

# -----------------------------------------------------------------------------
# dsk_diary_process_time time:
# Normalizes $time. Returns a list of {hour minute}.
#
proc dsk_diary_process_time {time} {
    global dsk_diary
    
    set add12 0
    if {[string first "am" $time] > -1} {
	set time [string trimleft $time "am"]
    } elseif {[string first "pm" $time] > -1} {
	set time [string trimleft $time "pm"]
	set add12 1
    }
    set M ""
    if {$time == "-"} {
	set H ""
	set M ""
    } elseif {$time == "*"} {
	set H "*"
	set M "*"
    } else {
	ot_maplist [split $time :] H M
	set $H [string trimleft $H 0]
	if {$H == ""} {set H 0}
	set $M [string trimleft $M 0]
	if {$M == ""} {set M 0}
	if $add12 {
	    incr H 12
	}
    }

    return [list $H $M]
}

# -----------------------------------------------------------------------------
# dsk_diary_check:
# Periodically checks for any events.
#
proc dsk_diary_check {} {
    global tkdesk dsk_diary dsk_diary_entry

    #puts "diary-check at [clock format [clock seconds]]"
    ot_maplist [clock format [clock seconds] -format {%a %d %m %Y %H %M}] \
	    wday day month year hours minutes
    set day [string trimleft $day 0]
    set month [string trimleft $month 0]
    set hours [string trimleft $hours 0]
    if {$hours == ""} {set hours 0}
    set minutes [string trimleft $minutes 0]
    if {$minutes == ""} {set minutes 0}

    foreach ent $dsk_diary(entries) {
	#puts "string match $ent \"$wday-$day.$month.$year-$hours:$minutes\""
	if [string match $ent "$wday-$day.$month.$year-$hours:$minutes"] {
	    ot_maplist $dsk_diary_entry($ent) date time msg
	    if {[string first "tcl:" $msg] > -1} {
		eval [string trimleft $msg "tcl:"]
	    } else {
		dsk_bell
		cb_info [subst -nocommands $msg]
	    }
	}
    }

    if {$hours == 0 && $minutes == 0 && $dsk_diary(list_at_midnight)} {
	dsk_diary_list today 0
    }

    # determine time to next check:
    set min [clock format [clock seconds] -format %M]
    set min [string trimleft $min 0]
    if {$min == ""} {set min 0}
    set p $tkdesk(diary,period)
    set t [expr (($min/$p + 1) * $p - $min) * 60 * 1000]
    #puts "next check in [expr $t / 60000] minutes"
    set dsk_diary(after_id) [after $t dsk_diary_check]
}

# -----------------------------------------------------------------------------
# dsk_diary_list date:
# Opens an editor window listing today's appointments.
# TODO: Check for weekdays of $date other than "today".
#
proc dsk_diary_list {{date today} {show_none 1}} {
    global tkdesk dsk_diary dsk_diary_entry

    if {$date == "today"} {
	ot_maplist [clock format [clock seconds] -format {%a %A %d %m %B %Y}] \
		wday fwday day month fmonth year
	set day [string trimleft $day 0]
	set month [string trimleft $month 0]
	set listing "Appointments for $fwday, $day. $fmonth $year:\n\n"
    } else {
	ot_maplist [dsk_diary_process_date $date] wday day month year
	set listing "Appointments for $day.$month.$year:\n\n"
    }

    set matched 0
    foreach ent $dsk_diary(entries) {
	#puts "string match $ent \"$wday-$day.$month.$year-$hours:$minutes\""
	ot_maplist [split $ent -] ewday edate etime
	if [string match "$ewday-$edate" "$wday-$day.$month.$year"] {
	    ot_maplist $dsk_diary_entry($ent) date time msg
	    #if {$time == ":"} {set time ""}
	    append listing [format "%-8s%s\n" $time $msg]
	    incr matched
	}
    }
    if {$matched == 0} {
	if $show_none {
	    append listing "None.\n"
	} else {
	    return
	}
    }
    if ![winfo exists dsk_diary(listwin)] {
	set ed [dsk_editor string $listing]
	set dsk_diary(listwin) $ed
	wm title $ed "Diary"
	wm iconname $ed "Diary"
    } else {
	set tw [$ed textWidget]
	$tw delete 1.0 end
	$tw insert end $listing
    }
}

