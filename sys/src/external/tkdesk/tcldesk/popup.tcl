# =============================================================================
#
# File:		popup.tcl
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
#s    proc dsk_popup {lbox file mx my {opt ""}}
#s    proc dsk_build_popup {poplist file lbox mx my {opt ""}}
#
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# dsk_show_popup file:
# Display popup menu for file $file at current mouse pointer position.
#
proc dsk_show_popup {file} {
    dsk_debug "dsk_show_popup file: $file"
    after 1 [list dsk_popup "" $file [winfo pointerx .] [winfo pointery .]]
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_popup
# Args:		lbox		name of calling listbox
#		file		name of file
#		mx		mouse x position on root window
#		my		mouse y position on root window
#               opt             additional options
# Returns: 	
# Desc:		Shows the appropriate popup menu for $file.
# Side-FX:	none
#

proc dsk_popup {lbox file mx my {opt ""}} {
    global tkdesk

    dsk_debug "dsk_popup: $file, mx: $mx, my: $my"
    if {$file == ""} return

    if $tkdesk(append_type_char) {
	set file [dskC_striptc $file]
    }

    if [file isdirectory $file] {
	# DIRECTORY
	dsk_build_popup tkdesk(popup,directories) $file $lbox $mx $my $opt
    } elseif [file_executable $file] {
	# EXECUTABLE
	if {$tkdesk(dot_regular)} {
	    if {[file extension $file] == ""} {
		dsk_build_popup tkdesk(popup,executables) \
			$file $lbox $mx $my $opt
	    } else {
		dsk_build_popup tkdesk(popup,regulars) $file $lbox $mx $my $opt
	    }
	} else {
	    dsk_build_popup tkdesk(popup,executables) $file $lbox $mx $my $opt
	}
    } else {
	# REGULAR (and others)
	dsk_build_popup tkdesk(popup,regulars) $file $lbox $mx $my $opt
    }
}

# -----------------------------------------------------------------------------
# dsk_cli_popup file:
# Returns a list of possible actions for $file.  Also sets a global variable
# to hold a 2-dimensional list of actions and labels.  This is used by the
# TkDesk "command line interface".
#
proc dsk_cli_popup {file} {
    global tkdesk

    if {$file == ""} return
    set file [cb_tilde $file expand]

    if [file isdirectory $file] {
	# DIRECTORY
	set pl [dsk_build_popup tkdesk(popup,directories) $file {} 0 0 CLI]
    } elseif [file_executable $file] {
	# EXECUTABLE
	set pl [dsk_build_popup tkdesk(popup,executables) $file {} 0 0 CLI]
    } else {
	# REGULAR (and others)
	set pl [dsk_build_popup tkdesk(popup,regulars) $file {} 0 0 CLI]
    }

    set tkdesk(cli,filemenu) $pl
    return $pl
}

# -----------------------------------------------------------------------------
# dsk_cli_popup_exec index:
# Executes the action that has index $index in the list returned by the
# previous call to dsk_cli_popup.
#
proc dsk_cli_popup_exec {index} {
    global tkdesk

    set script [lindex [lindex $tkdesk(cli,filemenu) $index] 1]
    eval $script
}


#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_build_popup
# Args:		poplist - list of popup entries
#		file - path and name of file
#		lbox - name of listbox where mousebutton was pressed
#		mx		mouse x position on root window
#		my		mouse y position on root window
#               opt             additional options
# Returns: 	""
# Desc:		builds the appropriate popup menu and brings it on-screen
# Side-FX:	none
#

proc dsk_build_popup {poplist file lbox mx my {opt ""}} {
    global tkdesk tkdesk_anno

    if ![info exists $poplist] {
	dsk_debug "$poplist does not exist!"
    }

    dsk_debug "dsk_build_popup file: $file"
    set fname [file tail $file]
    set dirname [file dirname $file]
    set sfile [_make_fname_safe $file]
    dsk_debug "dsk_build_popup sfile: $sfile"
    set plist {}

    catch "destroy .dsk_popup"
    foreach entry [set $poplist] {
	#
	# the first element of each entry is a list of glob patterns
	#
	set patlist [lindex $entry 0]
	foreach pat $patlist {
	    if [string match $pat $fname] {
		menu .dsk_popup \
			-disabledforeground [cb_col $tkdesk(color,annotation)]
		if [file isdirectory $file] {
		    set ffnt [cb_font $tkdesk(font,directories)]
		    set ffg [cb_col $tkdesk(color,directories)]
		} elseif [file_executable $file] {
		    set ffnt [cb_font $tkdesk(font,executables)]
		    set ffg [cb_col $tkdesk(color,executables)]
		} else {
		    set ffnt [cb_font $tkdesk(font,file_lbs)]
		    set ffg [cb_col $tkdesk(color,foreground)]
		}
		.dsk_popup add cascade -label "$fname " -menu .dsk_popup.fm \
			-font $ffnt -foreground $ffg -activeforeground $ffg
		menu [set m .dsk_popup.fm]
		$m add command -label "Info " -command \
			"catch {destroy .dsk_popup} ;\
			dsk_fileinfo [list $sfile]"
		$m add command -label "Bookmark " -command \
			"catch {destroy .dsk_popup} ;\
			dsk_bookmark add [list $sfile]"
		if {$poplist != "tkdesk(popup,directories)"} {
		    $m add command -label "Open with... " -command \
			    "catch {destroy .dsk_popup} ;\
			    set tkdesk(file_lb,control) 1 ;\
			    dsk_open \"$tkdesk(active_viewer)\" \"$sfile\""
		}
		$m add separator
		$m add command -label "Copy, Move, ... " -command \
			"catch {destroy .dsk_popup} ;\
			dsk_copy [list $sfile]"
		$m add command -label "Rename... " -command \
			"catch {destroy .dsk_popup} ;\
			dsk_rename [list $sfile]"
		$m add command -label "Delete " -command \
			"catch {destroy .dsk_popup} ;\
			dsk_delete [list $sfile]"
		if ![string match "deskitem*" $opt] {
		    $m add separator
		    $m add command -label "Put on Desk " -command \
			    "dsk_DeskItem .di\[dsk_DeskItem :: id\] \
			    -file \"$sfile\""
		}

		if [info exists tkdesk_anno($file)] {
		    set annol [split $tkdesk_anno($file) \n]
		    set anno [lindex $annol 0]
		    if {[string length $anno] > 30} {
			set anno [string range $anno 0 30]...
		    } elseif {[llength $annol] > 1} {
			append anno ...
		    }
		    
		    .dsk_popup add command -label $anno -state disabled
		}

		set cascmd_dirs "dsk_cd %d"
		set cascmd_mixed ""
		if {$opt != ""} {
		    switch -glob $opt {
			"dir *" {
			    .dsk_popup add command -label "Open Directory " \
				    -command "catch {destroy .dsk_popup}
			          dsk_open_dir [file dirname $file]"
			    set cascmd_dirs "dsk_cd %d 1"
			}
			"deskitem*" {
			    if {[info exists tkdesk(deskdir)] && [string first $tkdesk(deskdir) $file] == 0} {
				.dsk_popup add command \
					-label "Delete File & Item " \
					-command "catch \{[lindex $opt 1] discard\}"
			    } else {
				.dsk_popup add command \
					-label "Remove Item " \
					-command "catch \{[lindex $opt 1] discard\}"
			    }
			    set cascmd_dirs "dsk_cd %d 1"
			    set cascmd_mixed "dsk_cd %d 1"
			}
		    }
		}

		if {$poplist == "tkdesk(popup,directories)"} {
		    .dsk_popup add separator
		    .dsk_popup add cascade -label "Subdirectories" \
			    -menu [set m .dsk_popup.ms]
		    menu $m -postcommand "dsk_casdirs [_make_fname_safe $file] $m 1 [list $cascmd_dirs]"
		    $m add command -label "dummy"
		    
		    .dsk_popup add cascade -label "... and Files" \
			    -menu [set m .dsk_popup.mf]
		    menu $m -postcommand "dsk_casdirs [_make_fname_safe $file] $m 1 [list $cascmd_mixed] 1"
		    $m add command -label "dummy"
		}

		.dsk_popup add separator

		set num_entries 2
		set max_chars [expr [string length $fname] + 2]
		set menu_entries [lindex $entry 1]
		foreach me $menu_entries {
		    if {$poplist == "tkdesk(popup,executables)"} {
			#
			# Skip the "Edit" entry if file is not a script:
			#
			if [string match "Edit" [lindex $me 0]] {
			    set ft ""
			    set sig ""
			    set err [catch {set ft [exec file $file]}]
			    if {$ft == ""} {
				# file command failed
				set sig ""
				set err [catch {set fd [open $file]}]
				set err [catch {set sig [read $fd 2]}]
				set err [catch {close $fd}]
			    } else {
				if {[string first "text" $ft] > -1 \
					|| [string first "script" $ft] > -1} {
				    set sig "#!"
				}
			    }
			    if {($sig != "#!") || $err} {
				continue
			    }
			}
		    }

		    if {$me != "-"} {
			set l [lindex $me 0]
			set ll [string length $l]
			if {$ll > $max_chars} {
			    set max_chars $ll
			}
			.dsk_popup add command -label $l \
			  -command "dsk_popup_exec [list [lindex $me 1]] [list $file] [list $sfile]"
			if {$opt == "CLI"} {
			    lappend plist [list $l \
				    "dsk_popup_exec [list [lindex $me 1]] [list $file] [list $sfile]"]
			}
		    } else {
			if {$opt == "CLI"} {
			    lappend plist {-}
			}
			.dsk_popup add separator
		    }
		    incr num_entries
		}

		break
	    }
	}
	if [winfo exists .dsk_popup] {
	    break
	}
    }

    if {[winfo exists .dsk_popup] && $opt != "CLI"} {
	catch {cd $dirname}
	#
	# Post the popup
	#
	#cb_MenuPopupAdd $lbox 3 .dsk_popup "" "" 1 $mx $my
	update
	catch {
	    tk_popup .dsk_popup $mx $my
	    focus -force .dsk_popup
	    tkwait window .dsk_popup
	    update idletasks
	    cd ~
	}
	return ""
    } else {
	catch {destroy .dsk_popup}
	return $plist
    }
}

proc dsk_popup_exec {cmd file sfile} {
    global tkdesk dsk_exec
    
    catch {destroy .dsk_popup}
    dsk_history_file [list $sfile]
    #cd [dsk_active dir]
    set err [catch {eval cd [file dirname $sfile]} errmsg]
    if $err {
	dsk_errbell
	cb_error "Warning: $errmsg"
	cd [dsk_active dir]
    }
    #set err [catch {set dsk_exec(dir) [pwd]}]
    #if $err {
    #	 set dsk_exec(dir) [dsk_active dir]
    #}
    set tkdesk(error_source) Popups
    eval [_expand_pc [dskC_esc $cmd \$] $file]
    set tkdesk(error_source) ""
    cd ~
}

