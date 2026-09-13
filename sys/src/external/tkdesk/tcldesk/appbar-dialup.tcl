# =============================================================================
#
# File:		appbar-dialup.tcl
# Project:	TkDesk
#
# Started:	13.11.94
# Changed:	13.11.94
# Author:	cb
#
# Description:	Implements the "dial-up" application bar special.
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
#
# -----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# _appbar_dialup but:
# Creates a button that displays the current status of the
# dial-up link.
#

set dsk_appbar(dialup,button) ""
set dsk_appbar(dialup,currnr) ""

proc _appbar_dialup {but count} {
    global tkdesk dsk_appbar
    
    # set images to use:
    foreach img {up down} {
	set bitmap $tkdesk(appbar,dialup,$img)
	set dsk_appbar(dialup,img,$img) [dsk_image $bitmap]
    }

    # create button:
    set dsk_appbar(dialup,button) $but
    button $but -activebackground $dsk_appbar(bgcolor) \
	    -activeforeground $dsk_appbar(fgcolor) \
	    -cursor top_left_arrow \
	    -command $dsk_appbar(defaction) \
	    -padx 0 -pady 0 -highlightthickness 0 \
	    -image $dsk_appbar(dialup,img,down)

    bind $but <Enter> dsk_dialup_do_update

    set dsk_appbar(dialup,count) $count

    set dsk_appbar(dialup,state) "down"
    set dsk_appbar(dialup,offhook) 0

    catch {after cancel $dsk_appbar(dialup,after)}
    dsk_dialup_update
}

proc dsk_dialup {{phonenr {}}} {
    global tkdesk dsk_appbar

    if {$dsk_appbar(dialup,state) == "down" \
	    && !$dsk_appbar(dialup,offhook)} {
	if {$phonenr == {}} {
	    dsk_HistEntry .he[dsk_HistEntry :: id] \
		    -title "Connect to ISP" \
		    -label "Phone number to dial:" \
		    -history dialup_history \
		    -callback dsk_dialup_ok
	} else {
	    dsk_dialup_ok $phonenr 0
	}
    } else {
	# bring the link down
	dsk_busy
	set cmd $tkdesk(appbar,dialup,cmd_down)
	dsk_debug "cmd_down: $cmd"
	catch {eval exec $cmd >@stdout 2>@stderr </dev/null &}
	foreach t {500 1000 1500 2000 3000 4000 5000} {
	    after $t dsk_dialup_do_update
	}
	dsk_lazy
    }
}

proc dsk_dialup_ok {entry val} {
    global tkdesk dsk_appbar
    
    set nr $entry
    
    if {[string length $nr] == 0} {
	dsk_bell
	return
    }
    
    dialup_history add $nr

    # the following allows for comments after the number:
    set nr [lindex $nr 0]
    
    set dsk_appbar(dialup,currnr) $nr
    set cmd $tkdesk(appbar,dialup,cmd_up)
    
    dsk_busy
    dsk_debug "cmd_up: $cmd"
    catch {eval exec $cmd $nr >@stdout 2>@stderr </dev/null &}
    foreach t {1000 5000 15000 30000 45000 60000 75000 90000 105000 120000} {
	after $t dsk_dialup_do_update
    }
    dsk_lazy
}

proc dsk_dialup_update {} {
    global dsk_appbar
    
    if ![winfo exists $dsk_appbar(dialup,button)] return
    dsk_dialup_do_update
    set dsk_appbar(dialup,after) [after 60000 dsk_dialup_update]
}

proc dsk_dialup_do_update {} {
    global dsk_appbar

    set prevoffhook $dsk_appbar(dialup,offhook)
    set curroffhook [dsk_dialup_is_off_hook]
    #dsk_debug "curroffhook: $curroffhook"
    if {$prevoffhook != $curroffhook} {
	set dsk_appbar(dialup,offhook) $curroffhook
	if $curroffhook {
	    $dsk_appbar(dialup,button) config \
		    -image $dsk_appbar(dialup,img,up)
	} else {
	    $dsk_appbar(dialup,button) config \
		    -image $dsk_appbar(dialup,img,down)
	}
    }

    set prevstate $dsk_appbar(dialup,state)
    set currstate [dsk_dialup_state]
    #dsk_debug "currstate: $currstate"
    if {$currstate == "up" && $prevstate == "down"} {
	set but $dsk_appbar(dialup,button)
	set lab $but.l
	set dsk_appbar(dialup,label) $lab
        label $lab -text "00:00" -font fixed -cursor top_left_arrow
	bind $lab <ButtonPress-1> "$but config -relief sunken"
	bind $lab <ButtonRelease-1> "$but invoke; $but config -relief raised"
	bind $lab <3> "_appbar_show_menu $dsk_appbar(dialup,count) %X %Y"
	bind $lab <B3-Motion> "break"
	bindtags $lab "appbar $lab all"
	update idletasks
	set x 0
	set y [expr [winfo reqheight $but] - [winfo reqheight $lab]]
	place $lab -x $x -y $y
	set dsk_appbar(dialup,secsup) 0
	catch {after cancel $dsk_appbar(dialup,after,secs)}
	after 1000 dsk_dialup_update_secs
    } elseif {$currstate == "down" && $prevstate == "up"} {
	catch {destroy $dsk_appbar(dialup,label)}
    }
}

proc dsk_dialup_update_secs {} {
    global dsk_appbar

    if ![winfo exists $dsk_appbar(dialup,label)] return
    if {$dsk_appbar(dialup,state) == "down"} {
	catch {destroy $dsk_appbar(dialup,label)}
	return
    }
    
    incr dsk_appbar(dialup,secsup)
    set s [expr $dsk_appbar(dialup,secsup) % 60]
    set m [expr $dsk_appbar(dialup,secsup) / 60]
    $dsk_appbar(dialup,label) config -text [format "%02d:%02d" $m $s]
    set dsk_appbar(dialup,after,secs) [after 1000 dsk_dialup_update_secs]
}

proc dsk_dialup_state {} {
    global tkdesk dsk_appbar

    if {[string match $tkdesk(systype) "Linux"] \
	    || [string match $tkdesk(systype) "linux"]} {
	set fd [open /proc/net/route]
	set r [read $fd]
	close $fd
	if {[regexp "\nppp0" $r] || [regexp "\nsl0" $r]} {
	    set state "up"
	} else {
	    set state "down"
	}
    } else {
	set r {}
	catch {set r [exec ifconfig | egrep "^sl|^ppp"]}
	if {$r == {}} {
	    set state "down"
	} else {
	    set state "up"
	}
    }

    set dsk_appbar(dialup,state) $state
    return $state
}

proc dsk_dialup_is_off_hook {} {
    global tkdesk dsk_appbar

    if {$dsk_appbar(dialup,state) == "up"} {
	return 1
    } else {
	if {[string match $tkdesk(systype) "Linux"] \
		|| [string match $tkdesk(systype) "linux"]} {
	    if [file exists /var/lock/LCK..modem] {
		return 1
	    } elseif [file exists /var/lock/LCK..ttyS1] {
		return 1
	    } else {
		return 0
	    }
	} else {
	    return 0
	}
    }
}
