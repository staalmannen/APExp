# =============================================================================
#
# File:		appbar-mail.tcl
# Project:	TkDesk
#
# Started:	13.11.94
# Changed:	13.11.94
# Author:	cb
#
# Description:	Implements the "mail" application bar special.
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
#s    proc _appbar_mail {but}
#s    proc _appbar_check_mail {}
#
# -----------------------------------------------------------------------------

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_mail
# Args:		none
# Returns: 	""
# Desc:		The appbar's xbiff replacement.
# Side-FX:	none
#

proc _appbar_mail {but} {
    global tkdesk dsk_appbar env

    # sort out location of mail folder:
    if ![info exists tkdesk(appbar,mail,folders)] {
	if [info exists env(MAIL)] {
	    set dsk_appbar(mail,folder) $env(MAIL)
	} else {
	    foreach dir {/usr/mail /var/mail /usr/spool/mail /var/spool/mail} {
		if [file isdirectory $dir] {
		    set dsk_appbar(mail,folder) $dir
		    catch {set dsk_appbar(mail,folder) \
			    $dir/[exec $tkdesk(cmd,whoami)]}
		    break
		}
	    }
	}
    } else {
	set dsk_appbar(mail,folder) $tkdesk(appbar,mail,folders)
    }
    if ![info exists dsk_appbar(mail,folder)] {
	cb_alert "Couldn't locate your incoming mail folder."
	set dsk_appbar(mail,folder) ""
    }
    set dsk_appbar(mail,laststat) ""

    # set images to use:
    foreach img {nomail oldmail newmail} {
	set bitmap $tkdesk(appbar,mail,$img)
	set dsk_appbar(mail,img,$img) [dsk_image $bitmap]
    }

    # create button:
    set dsk_appbar(mail,button) $but
    button $but -image $dsk_appbar(mail,img,nomail) \
	    -activebackground $dsk_appbar(bgcolor) \
	    -activeforeground $dsk_appbar(fgcolor) \
	    -cursor top_left_arrow \
	    -command $dsk_appbar(defaction) \
	    -padx 0 -pady 0 -highlightthickness 0
    
    _appbar_check_mail
}

# Mods:
#
#   - Folder list entries that begin with '|' (horizontal bar) will
#     by treated as commands.  Non-null command output implies unseen
#     mail.
#       J. Chris Coppick, 1998
#

proc _appbar_check_mail {} {
    global dsk_appbar tkdesk

    set b $dsk_appbar(mail,button)
    if ![winfo exists $b] return

    set ns nomail
    set nf ""
    set unseen ""
    foreach f $dsk_appbar(mail,folder) {
        if [regsub {^\|} $f "" f] {
            catch "set unseen \[exec $f]"
            if {$unseen == ""} {
	       set ns nomail
	       catch {destroy .dsk_mail_headers}
            } else {
	       set ns newmail
            }
	} else { 
            catch {
	         set f [cb_tilde $f expand]
	         if [file exists $f] {
		    file stat $f stat
		    if {$stat(size) > 0} {
		        if {$stat(mtime) > $stat(atime)} {
			    set ns newmail
			    set nf $f
		        } else {
			    set ns oldmail
		        }
		    } else {
		        catch {destroy .dsk_mail_headers}
		    }
	         }
	    }
	
        }	
 	if {$ns == "newmail"} break
    }

    if {$ns != $dsk_appbar(mail,laststat)} {
	if {$ns != "nomail"} {
	    dsk_mail_headers
	}

	set dsk_appbar(mail,laststat) $ns
	$b config -image $dsk_appbar(mail,img,$ns)
	if {$ns == "newmail"} {
	    if {$tkdesk(appbar,mail,newbg) != ""} {
		$b config -bg $tkdesk(appbar,mail,newbg)
	    }
	    dsk_sound dsk_new_mail beep
            dsk_show_mail_headers
	    if {$tkdesk(appbar,mail,notifier) == "1"} {
		cb_alert "New mail arrived in\n[cb_tilde $nf collapse]!"
	    } elseif {$tkdesk(appbar,mail,notifier) == "bell"} {
		bell
	    }
	} else {
	    $b config -bg [cb_col $tkdesk(color,background)]
	}
    }
    
    if [info exists dsk_appbar(mail,afterid)] {
	catch {after cancel $dsk_appbar(mail,afterid)}
    }
    set dsk_appbar(mail,afterid) \
	    [after [expr $tkdesk(appbar,mail,delay) * 1000] _appbar_check_mail]
}

# mail.tcl (patched)
#
# Author:       J. Chris Coppick, 1997 
# Description:  Implements a mail-header flasher for TkDesk
#
# Mods:
#
#   - now treats tkdesk(appbar,mail,headers,cmd) as a list of commands
#   - removes empty lines from the display
#   - handles dynamic updates better
#   - only outputs "retrieval failure" message if in debug mode
#      J. Chris Coppick, 1998
#

# background color for headers window
set tkdesk(appbar,mail,headers,bg) black

# background color for headers window
set tkdesk(appbar,mail,headers,fg) yellow

# font for headers window
set tkdesk(appbar,mail,headers,font) 9x15bold

# command for summarizing mail contents
# (there's no default for this as leaving it unset disables the
# headers flasher)
#set tkdesk(appbar,mail,headers,cmd) "/usr/bin/mailx -H"

### Number of seconds to auto-display mail headers when new mail arrives.
### Set to zero to disable auto-display of mail headers.
set tkdesk(appbar,mail,headers,autotime) 5

proc dsk_mail_headers {} {
    global tkdesk dsk_appbar

    if {![info exists tkdesk(appbar,mail,headers,cmd)] \
	&& ![info exists tkdesk(appbar,mail,headers,cmds)]} return
    if {$tkdesk(appbar,mail,headers,cmd) == ""} return
    
    set t .dsk_mail_headers
    if ![winfo exists $t] {
	toplevel $t
	wm withdraw $t
	frame $t.f -bd 1 -relief raised
	pack $t.f -fill x
	
	text $t.lb -width 60 -height 10 \
		-font [cb_font $tkdesk(appbar,mail,headers,font)] \
		-bg [cb_col $tkdesk(appbar,mail,headers,bg)] \
		-fg [cb_col $tkdesk(appbar,mail,headers,fg)]
	
	pack $t.lb -in $t.f -fill both -expand yes
    }

    $t.lb configure -state normal
    $t.lb delete 1.0 end
    set ml 0
    set tl 0
    if {[info exists tkdesk(appbar,mail,headers,cmd)] \
	    && ![info exists tkdesk(appbar,mail,headers,cmds)]} {
	lappend tkdesk(appbar,mail,headers,cmds) \
		$tkdesk(appbar,mail,headers,cmd)
    }
    foreach cmd $tkdesk(appbar,mail,headers,cmds) {
       set cmd [string_replace $cmd \[ \\\[]
       set cmd [string_replace $cmd \] \\\]]
       append cmd " 2>/dev/null"
       if $tkdesk(debug) {
	   catch {puts stderr "$cmd"}
       }

       if [catch {set headers [eval exec $cmd]} errmsg] {
           if $tkdesk(debug) {
	       catch {
	           puts stderr "Mail headers retrieval failed:"
	           puts stderr "$errmsg\n"
	       }
           }
       } else {
	   set hl [split $headers \n]
	   if [set ll [llength $hl]] {
	       foreach h $hl {
	           if {$h == ""} continue
		   incr tl
	           set h [string trim $h { }]
	           set hlen [string length $h]
	           if {$hlen > $ml} {
		       set ml $hlen
	           }
	           $t.lb insert end "$h\n"
	       }
	   }
       }
    }
    $t.lb configure -height $tl -width $ml -state disabled

    cb_centerToplevel $t

    if [winfo exists $dsk_appbar(mail,button)] {
	wm transient $t $dsk_appbar(mail,button)
	wm overrideredirect $t 1
	bind $dsk_appbar(mail,button) <Button-2> \
		"catch {wm deiconify .dsk_mail_headers; raise .dsk_mail_headers}"
	bind $dsk_appbar(mail,button) <ButtonRelease-2> \
		"catch {wm withdraw .dsk_mail_headers}"
    }
    update idletasks
}

proc dsk_show_mail_headers {} {
    global tkdesk

    if ![info exists tkdesk(appbar,mail,headers,autotime)] return

    if {$tkdesk(appbar,mail,headers,autotime) == 0 || \
	    $tkdesk(appbar,mail,headers,autotime) == ""} {
	return
    }

    if [winfo exists .dsk_mail_headers] {
	wm deiconify .dsk_mail_headers
	raise .dsk_mail_headers
	update idletasks
	after [expr 1000 * $tkdesk(appbar,mail,headers,autotime)] {
	    catch {wm withdraw .dsk_mail_headers}
	}
    }
}

