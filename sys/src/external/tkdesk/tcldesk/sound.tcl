# =============================================================================
#
# File:		sound.tcl
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
#s    proc dsk_sound {snd {opts ""}}
#s    proc dsk_bell {}
#s    proc dsk_errbell {}
#
# -----------------------------------------------------------------------------

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_sound
# Args:		snd: name of sound event, e.g. welcome, launch.
#               The soundfile is accessed by $tkdesk(sound,$snd).
# Returns: 	""
# Desc:		Plays a sound file via $tkdesk(soundcmd).
# Side-FX:	none
#

proc dsk_sound {snd {opts ""}} {
    global tkdesk

    if !$tkdesk(use_sound) return
    if ![info exists tkdesk(soundcmd)] {
	if {$opts == "beep"} bell
	return
    }
    if {$tkdesk(soundcmd) == ""} return
    if ![dsk_auto_execok [lindex $tkdesk(soundcmd) 0]] {
	unset tkdesk(soundcmd)
	if {$opts == "beep"} bell
	return
    }
    
    if ![info exists tkdesk(sound,$snd)] {
	set snd [cb_tilde $snd expand]
	if ![file readable $snd] {
	    #puts stderr "tkdesk: no associated sound file for $snd"
	    return
	} else {
	    set sound $snd
	}
    } else {
	if {$tkdesk(sound,$snd) == ""} return
	set sound $tkdesk(sound,$snd)
    }
    
    if {[string index [list $sound] 0] == "/" || \
	    [string index [list $sound] 0] == "~"} {
	set sound $sound
    } else {
	foreach p [split $tkdesk(path,sounds) ":"] {
	    if [file exists [list $p/$sound]] {
		set sound $p/$sound
		break
	    }
	}
    }
    if ![file exists $sound] {
	cb_error "Can't find sound: [file tail $tkdesk(sound,$snd)]."
	set tkdesk(sound,$snd) ""
	return
    } else {
	set tkdesk(sound,$snd) $sound
    }
    
    #update
    set errmsg ""
    set cmd [format "$tkdesk(soundcmd)" \
	    [cb_tilde $tkdesk(sound,$snd) expand]]
    catch {eval exec $cmd} errmsg
    # prevent the pid in $errmsg from being printed
    if {$errmsg != "" && [string first " " $errmsg] > -1} {
	catch {puts stderr $errmsg}
    }
}

# ---------------------------------------------------------------------------
# dsk_bell:
# Rings the bell or plays the corresponding sound file:
#
proc dsk_bell {} {
    global tkdesk

    if {![info exists tkdesk(soundcmd)] || \
	    ![info exists tkdesk(sound,dsk_bell)]} {
	bell
    } else {
	dsk_sound dsk_bell
    }
}

# ---------------------------------------------------------------------------
# dsk_errbell:
# Rings the bell or plays the corresponding sound file:
#
proc dsk_errbell {} {
    global tkdesk

    if {![info exists tkdesk(soundcmd)] || \
	    ![info exists tkdesk(sound,dsk_error)]} {
	bell
    } else {
	dsk_sound dsk_error
    }
}

