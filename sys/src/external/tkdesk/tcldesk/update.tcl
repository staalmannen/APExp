# =============================================================================
#
# File:		update.tcl
# Project:	TkDesk
#
# Started:	24.10.94
# Changed:	24.10.94
# Author:	cb
#
# Description:	Contains procs that are used to keep the file lists in
#		all the opened windows up to date.
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
#s    proc dsk_refresh {files}
#s    proc dsk_update_flbs {}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_refresh
# Args:		files		list of filenames/directories
# Returns: 	""
# Desc:		For each file the appropriate listbox is reread.
# Side-FX:	none
#

proc dsk_refresh {files} {
    global tkdesk

    set refreshed_dirs ""

    dsk_debug "Refreshing $files"
    foreach dir $files {
	if ![file isdirectory $dir] {
	    set dir [file dirname $dir]
	}
	set dir [string trimright $dir "/"]/
	set dir [_make_path_valid $dir]
	set dir [cb_tilde $dir expand]

	#puts "dsk_refresh: $dir"
	if {[lsearch $refreshed_dirs $dir] < 0} {
	    lappend refreshed_dirs $dir

	    foreach fv [itcl_info objects -class dsk_FileViewer] {
		catch {$fv refreshdir $dir}
		#$fv refreshdir $dir
	    }

	    foreach fl [itcl_info objects -class dsk_FileList] {
		catch {$fl refreshdir $dir}
	    }
	    
	    if {$dir == "$tkdesk(trashdir)/"} {
		_appbar_trash_refresh
	    }
	    
	    if {$dir == $tkdesk(deskdir)} {
		dsk_desktop_update
	    }
	}
    }

    catch {after cancel $tkdesk(afterid,update_flbs)}
    dsk_update_flbs

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_update_flbs
# Args:		none
# Returns: 	""
# Desc:		This proc will be periodically executed to update the
#		contents of the file listboxes.
# Side-FX:	affects the contents of file LBs
#

set tkdesk(bgexec,working) 0

proc dsk_update_flbs {{lblist {}}} {
    global tkdesk

    #dsk_debug "dsk_update_flbs entry, lblist: $lblist"
    set refreshed_toplevels ""

    if {[llength $lblist] == 0} {
	set lblist [itcl_info objects -class dsk_FileListbox]
	set revisit 1
    } else {
	set revisit 0
    }

    set err [catch {
	if {!$tkdesk(bgexec,working)} {
	    foreach lb $lblist {
		set dir ""
		catch {set dir [$lb info public directory -value]}
		if {$dir == ""} {
		    continue
		}
		set mtime [$lb info protected mtime -value]
		if [file exists $dir] {
		    # take care of a possible race condition
		    set rmtime [expr $mtime + 1]
		    catch {set rmtime [file mtime $dir]}
		    if {$rmtime > $mtime} {
			#puts "dsk_update_flbs1: $dir"
			if {$dir != "$tkdesk(trashdir)/"} {
			    #$lb config -directory $dir
			    $lb refresh
			} else {
			    [$lb cget -viewer] refreshdir $dir
			}
		    }
		} else {
		    set toplevel [$lb cget -viewer]
		    if {[lsearch $refreshed_toplevels $toplevel] < 0} {
			$toplevel config -directory [_make_path_valid $dir]
			lappend refreshed_toplevels $toplevel
		    }
		}
	    }
	    
	    if $tkdesk(auto_reload_conf) {
		set mt [file mtime $tkdesk(configdir)]
		if {$mt > $tkdesk(configdir_mtime)} {
		    #puts "Setting configdir_mtime to $mt"
		    set tkdesk(configdir_mtime) $mt
		    foreach cf $tkdesk(configfiles) {
		        if [file readable $tkdesk(configdir)/$cf] {
			   set fmt [file mtime $tkdesk(configdir)/$cf]
			   #puts "Comparing $cf: $fmt - $mt"
			   if {$fmt >= $mt} {
			       #puts "Reloading $cf"
			       dsk_reread_config $cf
			   }
			}
		    }
		}
	    }
	    
	    set mt [file mtime $tkdesk(deskdir)]
	    if {$mt > $tkdesk(deskdir_mtime)} {
		set tkdesk(deskdir_mtime) $mt
		dsk_desktop_update
	    }
	}
    } errmsg]

    if $err {
	puts stderr $errmsg
    }

    if {$revisit} {
	set tkdesk(afterid,update_flbs) \
		[after [expr int($tkdesk(update,file_lists) * 1000)] \
		dsk_update_flbs]
    }
    #dsk_debug "dsk_update_flbs exit"
}

