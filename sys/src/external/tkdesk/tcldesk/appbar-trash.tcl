# =============================================================================
#
# File:		appbar-trash.tcl
# Project:	TkDesk
#
# Started:	13.11.94
# Changed:	13.11.94
# Author:	cb
#
# Description:	Implements the "trash" application bar special.
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
#s    proc _appbar_trash {but}
#s    proc _appbar_trash_refresh {{state unknown}}
#
# -----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# _appbar_trash but:
# Creates a trash button that's displays the current fill state of the
# trash can.
#

set dsk_appbar(trash,button) ""

proc _appbar_trash {but} {
    global tkdesk dsk_appbar

    set no_refresh 0

    # is there a trash dir?
    if ![file exists $tkdesk(trashdir)] {
       if [cb_yesno "Create trash directory $tkdesk(trashdir)?"] {
          set no_refresh 1
       } else {
          if [dsk_catch {file mkdir $tkdesk(trashdir)}] {
              return
	  }
       }
    }
    
    # set images to use:
    foreach img {empty full} {
	set bitmap $tkdesk(appbar,trash,$img)
	set dsk_appbar(trash,img,$img) [dsk_image $bitmap]
    }

    # create button:
    set dsk_appbar(trash,button) $but
    button $but -activebackground $dsk_appbar(bgcolor) \
	    -activeforeground $dsk_appbar(fgcolor) \
	    -cursor top_left_arrow \
	    -command $dsk_appbar(defaction) \
	    -padx 0 -pady 0 -highlightthickness 0

    # create label:
    if $tkdesk(appbar,trash,label) {
	set dsk_appbar(trash,label) [winfo parent $but].lDu
	catch {destroy $dsk_appbar(trash,label)}
	label $dsk_appbar(trash,label) \
		-font [cb_font $tkdesk(appbar,trash,font)] \
		-cursor top_left_arrow
    } else {
	catch {unset dsk_appbar(trash,label)}
    }

    if $no_refresh {
        $but config -image $dsk_appbar(trash,img,empty)
        return
    }

    # initialize display:
    _appbar_trash_refresh
}

proc _appbar_trash_refresh {{state unknown}} {
    global tkdesk dsk_appbar

    if ![winfo exists $dsk_appbar(trash,button)] return
    set but $dsk_appbar(trash,button)

    if ![file isdirectory $tkdesk(trashdir)] {
       cb_error "File $tkdesk(trashdir) exists, but isn't a directory!"
       return
    }

    switch $state {
	"empty" {
	    $but config -image $dsk_appbar(trash,img,empty)
	}
	"full" {
	    $but config -image $dsk_appbar(trash,img,full)
	}
	unknown {
	    set tlen [llength [dskC_ls -a $tkdesk(trashdir)]]
	    if {$tlen > 2} {
		$but config -image $dsk_appbar(trash,img,full)
	    } else {
		$but config -image $dsk_appbar(trash,img,empty)
	    }
	}
    }

    if [info exists dsk_appbar(trash,label)] {
	set du -1
	catch {set du [lindex [eval exec \
		$tkdesk(cmd,du) -s $tkdesk(trashdir)] 0]}
	if {$du == -1} {
	    set dus "?"
	} elseif {$du == 0 || $tlen <= 2} {
	    set dus "Empty"
	} elseif {$du < 1000} {
	    set dus "${du}kB"
	} elseif {$du < 1000000} {
	    set dus "[expr round($du./1000)]MB"
	} else {
	    set dus "[expr round($du./1000000)]GB"
	}

	$dsk_appbar(trash,label) config -text $dus
    }
}
