# =============================================================================
#
# File:		bookmarks.tcl
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
#s    proc dsk_bookmark {cmd args}
#
# =============================================================================

# ===========================================================================
# ---------------------------------------------------------------------------
# bookmark cmd ?args ...?
# Manages the bookmarks menu and the bookmarks list.
#
proc dsk_bookmark {cmd args} {
    global tkdesk env

    switch $cmd {
	menu {
	    set m [lindex $args 0]
	    
	    bind $m <B3-ButtonPress-1> {
		#puts "[%W entrycget [%W index active] -label]"
		set e [%W entrycget [%W index active] -label]
		set f [string trimright [lindex [split $e "("] 0] " "]
		set d [cb_tilde [string trim [lindex [split $e "("] 1] ()] \
			expand]
		after 100
		dsk_popup {} $d/$f %X %Y
		break
	    }
	    bind $m <B3-ButtonRelease-1> break
	    bind $m <B1-ButtonPress-3> [bind $m <B3-ButtonPress-1>]
	    bind $m <B1-ButtonRelease-3> break

	    catch {$m delete 0 last}
	    $m add command -label "Add Bookmark" -underline 0 \
		    -command "dsk_bookmark add"
	    if {[llength $tkdesk(bookmarks)] > 0} {
		$m add separator
	    }

	    set l {}
	    foreach bm $tkdesk(bookmarks) {
		lappend l [list [file tail $bm] [file dirname $bm]]
	    }
	    set bms [lsort $l]
	    set i 0
	    foreach bm $bms {
		set f [lindex $bm 0]
		set d [lindex $bm 1]
		set l "$f  ($d)"
		set ld "$f/  ($d)"
		set sf [_make_fname_safe $d/$f]
		if {[file isdirectory $sf]} {
		    if {$tkdesk(expand_dir_bookmarks)} {
			set cm $m.cm$i
			catch {destroy $cm}
			$m add cascade -label "$l" \
				-font [cb_font $tkdesk(font,file_lbs)] \
				-menu $cm
			menu $cm -postcommand "dsk_casdirs \"$sf\" $cm 1 {} 1"
			$cm add command -label "dummy"
			incr i
		    } else {
			$m add command -label "$ld" \
			   -font [cb_font $tkdesk(font,file_lbs)] \
			   -command "dsk_open \$tkdesk(active_viewer) \"$sf\""
		    }
		} else {
		    $m add command -label "$l" \
			    -font [cb_font $tkdesk(font,file_lbs)] \
			    -command "dsk_open \$tkdesk(active_viewer) \"$sf\""
		}
	    }
	    
	    $m add separator
	    $m add cascade -label "Remove Bookmark" -menu $m.rb
	    catch {destroy $m.rb}
	    menu [set m $m.rb]

	    foreach bm $bms {
		set f [lindex $bm 0]
		set d [lindex $bm 1]
		set l "$f  ($d)"
		set sf [_make_fname_safe $d/$f]
		$m add command -label "$l" \
			-font [cb_font $tkdesk(font,file_lbs)] \
			-command "dsk_bookmark remove \"$sf\""
	    }
	    
	}
	add {
	    if {$args == ""} {
		# set files to path that's displayed by current browser
		set files [string trimright [_make_fnames_safe] /]
	    } else {
		set files $args
	    }
	    if {$files == ""} {
		set dir [dsk_active dir]
		if {$dir != ""} {
		    set files [string trimright $dir /]
		} else {
		    cb_info "Please select one or more files first."
		    return
		}
	    }
	    foreach file $files {
		set file [subst $file]
		if {[string first $env(HOME) $file] == 0} {
		    set file [string_replace $file $env(HOME) ~]
		}
		if {[lsearch $tkdesk(bookmarks) $file] == -1} {
		    lappend tkdesk(bookmarks) $file
		}
	    }
	}
	remove {
	    set bm [_make_fname_safe [lindex $args 0]]
	    set nr [lsearch $tkdesk(bookmarks) $bm]
	    if {$nr > -1} {
		set tkdesk(bookmarks) \
			[lreplace $tkdesk(bookmarks) $nr $nr]
	    } else {
		dsk_debug "not in bookmarks: $bm"
		dsk_debug "bookmarks:\n$tkdesk(bookmarks)"
	    }
	}
    }
}
