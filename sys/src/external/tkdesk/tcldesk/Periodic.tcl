# =============================================================================
#
# File:		periodic.tcl
# Project:	TkDesk
#
# Started:	14.10.94
# Changed:	17.10.94
# Author:	cb
#
# Description:	Implements procs for opening & executing files and for popups.
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
#s    itcl_class dsk_Periodic
#s    method config {config}
#s    method execute {}
#s    method update {}
#s    proc id {}
#s    proc dsk_periodic {{cmd ""} {period 10}}
#s    proc dsk_periodic_cb {t cmd}
#
# =============================================================================
#


if ![info exists tkdesk(geometry,periodic)] {
    set tkdesk(geometry,periodic) ""
}


# =============================================================================
#
# Class:	dsk_Periodic
# Desc:		Implements a window that periodically executes a shell
#		command and collects its output in a text widget.
#
# Methods:	
# Procs:	
# Publics:
#

itcl_class dsk_Periodic {
    inherit Toplevel

    constructor {args} {
	global tkdesk [set this]

	if {$tkdesk(tcl_version) < 8.0} {
	    Toplevel::constructor
	}
	
	wm withdraw $top

	frame $top.fe -bd 1 -relief raised
	pack $top.fe -fill x

	label $top.lCmd -text "Command:"
	entry $top.eCmd -bd 2 -relief sunken -width 10
	bind $top.eCmd <Return> "$top.bExec.button invoke"
	bind $top.eCmd <Tab> "focus $top.eSec"
    	menubutton $top.mbHist -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
		-menu $top.mbHist.menu
    	menu $top.mbHist.menu \
		-postcommand "pcmd_history buildmenu $top.mbHist.menu"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$top.mbHist.menu add command -label "dummy"
	pcmd_history changed

	frame $top.fSep -width 16
	label $top.lu1 -text "Exec every"
	entry $top.eSec -bd 2 -relief sunken -width 4
	bind $top.eSec <Return> "$top.bExec.button invoke"
	bind $top.eSec <Tab> "focus $top.eCmd"
	$top.eSec insert end $period
	label $top.lu2 -text "seconds"

	pack $top.lCmd $top.eCmd $top.mbHist $top.fSep $top.lu1 \
		$top.eSec $top.lu2 \
		-in $top.fe -side left -ipady 2 \
		-padx $tkdesk(pad) -pady $tkdesk(pad)
	pack configure $top.eCmd -fill x -expand yes
	pack configure $top.mbHist  -ipadx 2 -ipady 2

	frame $top.ft -bd 1 -relief raised
	pack $top.ft -fill both -expand yes

	cb_text $top.ftext -vscroll 1 -hscroll 1 -lborder 1 -wrap none \
		-pad $tkdesk(pad) -width 20 -height 2 -state disabled
	pack $top.ftext -in $top.ft -fill both -expand yes \
		-pady $tkdesk(pad)

	frame $top.fb -bd 1 -relief raised
	pack $top.fb -fill x

	cb_button $top.bExec -text "  Exec  " -default 1 \
		-command "$this config -period \[$top.eSec get\]
				$this config -command \[$top.eCmd get\]
				focus $top
				pcmd_history add \[$top.eCmd get\]"
	cb_button $top.bClose -text "  Close  " -command "$this close"
	pack $top.bExec $top.bClose -in $top.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad)
	set [set this](dont_exec) 0
	checkbutton $top.cbExec -text "Don't execute" \
		-variable [set this](dont_exec) \
		-command "if !\[set [set this](dont_exec)\] \
		             \{$top.bExec.button invoke\}"
	pack $top.cbExec -in $top.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	bind $top <Any-Enter> "+focus $top"
	bind $top <Tab> "focus $top.eCmd"

    	wm minsize $top 354 124
	#wm geometry $top 592x278
	dsk_place_window $top periodic 592x278
	wm title $top "Periodic Execution"
	wm protocol $top WM_DELETE_WINDOW "$this close"

	eval config $args
	wm deiconify $top
    }

    destructor {
    }

    #
    # ----- Methods and Procs -------------------------------------------------
    #

    method config {config} {
    }

    method close {} {
	global tkdesk

	set tkdesk(geometry,periodic) [wm geometry $top]
	delete
    }

    method execute {} {
	global [set this] tkdesk
	
	if [set [set this](dont_exec)] return
	if ![winfo exists $top] return
	
	if {[grab current] == ""} {
	    dsk_busy ;# dsk_Periodic
	    set err [catch {eval blt_bgexec [set this](var) \
		    -output [set this](result) \
		    -error [set this](error) \
		    $command </dev/null &} m]
	    if $err {
		dsk_lazy
	    	set update_started 0
		dsk_errbell
		if {[string length $m] < 100} {
	    	    cb_error "Couldn't execute $command! ($m)"
		} else {
	    	    cb_error \
			"Couldn't execute $command for some strange reason..."
		}
	    	return
	    }

	    tkwait variable [set this](var)
	    set result [set [set this](result)]
	    set errout [set [set this](error)]

	    if [winfo exists $top] {
		set oldy [lindex [cb_old_sb_get $top.ftext.vscroll] 2]
		$top.ftext.text config -state normal
		$top.ftext.text delete 1.0 end
		if {$errout == ""} {
		    $top.ftext.text insert end $result
		} else {
		    $top.ftext.text insert end $errout
		}
		$top.ftext.text yview $oldy
		$top.ftext.text config -state disabled
	    }
	    dsk_lazy ;# dsk_Periodic
	}
    }

    method update {} {
	$this execute

	if $period {
	    set update_started 1
	    after [expr $period * 1000] "catch \"$this update\""
	} else {
	    set update_started 0
	}
    }

    proc id {} {
	set i $id
	incr id
	return $i
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    public command "" {
	if {$command != ""} {
	    if !$update_started {
	    	$this update
	    } else {
	    	$this execute
	    }
	}
	catch {
	    $top.eCmd delete 0 end
	    $top.eCmd insert end $command
	}
    }

    public period 10 {
	$top.eSec delete 0 end
	$top.eSec insert end $period
    }

    protected update_started 0

    common id 0
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_periodic (~_cb is the callback for the history menu)
# Args:		none
# Returns: 	""
# Desc:		Creates a window for periodic execution of shell commands.
# Side-FX:	none (hopefully)
#

proc dsk_periodic {{cmd ""} {period 10}} {

    if {$cmd != ""} {
    	dsk_Periodic .pe[dsk_Periodic :: id] -command $cmd -period $period
    } else {
    	dsk_Periodic .pe[dsk_Periodic :: id] -period $period
    }
    return
}

proc dsk_periodic_cb {t cmd} {
    set e [$t getToplevel].eCmd
    $e delete 0 end
    $e insert end $cmd
}

