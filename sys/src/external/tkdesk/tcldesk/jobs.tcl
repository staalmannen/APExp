# =============================================================================
#
# File:		jobs.tcl
# Project:	TkDesk
#
# Started:	12.12.94
# Changed:	29.03.96
# Author:	cb
#
# Description:	Implements procs for searching files and annotations.
#               Also does the bookmarks stuff.
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
#s    proc dsk_jobs {}
#s    proc dsk_jobs_fill {}
#s    proc dsk_jobs_sig {signal}
#s    proc dsk_jobs_update {}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_jobs
# Args:		none
# Returns: 	""
# Desc:		Displays a listing of all started background processes
#		that were started by TkDesk.
# Side-FX:	none
#

set tkdesk(dsk_exec,pids) ""
set tkdesk(dsk_exec,cmds) ""
set dsk_jobs(pids) ""
if ![info exists tkdesk(geometry,dsk_jobs)] {
    set tkdesk(geometry,dsk_jobs) ""
}

proc dsk_jobs {} {
    global tkdesk dsk_jobs

    set t .dsk_jobs
    if [winfo exists $t] {
	cb_raise $t
	return
    }

    dsk_busy 

    toplevel $t
    wm withdraw $t

    frame $t.fl -bd 1 -relief raised
    pack $t.fl -fill x

    label $t.label -text "Background Jobs of TkDesk:"
    pack $t.label -in $t.fl -side left -padx $tkdesk(pad) -pady $tkdesk(pad)

    frame $t.fj
    pack $t.fj -fill both -expand yes

    cb_listbox $t.flb -vscroll 1 -hscroll 1 -lborder 1 -uborder 1 \
		-pad $tkdesk(pad) -font [cb_font $tkdesk(font,file_lbs)] \
		-width 20 -height 5
    $t.flb config -bd 1 -relief raised
    pack $t.flb -in $t.fj -side left -fill both -expand yes

    frame $t.fjb -bd 1 -relief raised
    pack $t.fjb -in $t.fj -side left -fill y

    button $t.bTerm -text "Terminate" -width 9 -command "dsk_jobs_sig term"
    pack $t.bTerm -in $t.fjb -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

    button $t.bHang -text "Hang up" -width 9 -command "dsk_jobs_sig hangup"
    pack $t.bHang -in $t.fjb -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

    button $t.bKill -text "Kill!" -width 9 -command "dsk_jobs_sig kill"
    pack $t.bKill -in $t.fjb -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

    button $t.bStop -text "Stop" -width 9 -command "dsk_jobs_sig stop"
    pack $t.bStop -in $t.fjb -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

    button $t.bCont -text "Continue" -width 9 -command "dsk_jobs_sig cont"
    pack $t.bCont -in $t.fjb -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

    frame $t.fb -bd 1 -relief raised
    pack $t.fb -fill x

    button $t.bClose -text "  Close  " -command {
		set tkdesk(geometry,dsk_jobs) [wm geometry .dsk_jobs]
		destroy .dsk_jobs }
    pack $t.bClose -in $t.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

    button $t.bUpdate -text " Update " -command "dsk_jobs_fill"
    pack $t.bUpdate -in $t.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

    wm protocol $t WM_DELETE_WINDOW {
	set tkdesk(geometry,dsk_jobs) [wm geometry .dsk_jobs]
	destroy .dsk_jobs
    }
    wm minsize $t 276 278
    wm title $t "Job Control"
    wm deiconify $t

    dsk_place_window $t dsk_jobs 422x278

    dsk_jobs_update
    dsk_lazy
}


proc dsk_jobs_fill {} {
    global tkdesk dsk_jobs

    #dsk_busy

    set err [catch {set pslist [split [eval exec $tkdesk(cmd,ps)] \n]} errmsg]
    if $err {
	dsk_errbell
	cb_error $errmsg
	return
    }
    
    set dsk_jobs(pids) ""
    set t .dsk_jobs
    set csel [$t.flb.lbox curselection]
    $t.flb.lbox delete 0 end

    set i 0
    foreach cmd $tkdesk(dsk_exec,cmds) {
	set pid [lindex $tkdesk(dsk_exec,pids) $i]
	if {[lsearch -regexp $pslist "^ *$pid +"] > -1} {
	    lappend dsk_jobs(pids) $pid
	    $t.flb.lbox insert end $cmd
	} else {
	    lreplace $tkdesk(dsk_exec,cmds) $i $i
	    lreplace $tkdesk(dsk_exec,pids) $i $i
	}
	incr i
    }
    if {$csel != ""} {
	$t.flb.lbox selection set [lindex $csel 0]
    }

    set t .dsk_jobs

    #dsk_lazy
}


proc dsk_jobs_sig {signal} {
    global dsk_jobs tkdesk

    switch $signal {
	term	{set signum 15}
	hangup	{set signum 1}
	kill	{set signum 9}
	stop	{set signum 19}
	cont	{set signum 18}
	default {cb_error "Unknown signal $signal!" ; return}
    }

    set sel [.dsk_jobs.flb.lbox curselection]
    if {$sel != ""} {
	foreach i $sel {
	    set pid [lindex $dsk_jobs(pids) $i]
	    set err [catch "exec kill -$signum $pid" m]
	    dsk_debug "exec kill -$signum $pid"
	    if {$err && $tkdesk(in_development)} {
		dsk_errbell
		cb_error "kill $signum failed! ($m)"
	    }
#	    if {$signal == "stop"} {
#		set j [lsearch $tkdesk(dsk_exec,pids) $pid]
#		if {$j > -1} {
#		    set tkdesk(dsk_exec,cmds) [lreplace \
#			$tkdesk(dsk_exec,cmds) $j $j \
#			"[lindex $tkdesk(dsk_exec,cmds) $j] (stopped)"]
#		}
#	    }
	}

	after 500 dsk_jobs_fill
    } else {
	dsk_bell
	cb_info "Please select one or more jobs first."
    }
}


proc dsk_jobs_update {} {
    global tkdesk

    if [winfo exists .dsk_jobs] {
    	dsk_jobs_fill
	after [expr $tkdesk(update,jobs) * 1000] dsk_jobs_update
    }
}

