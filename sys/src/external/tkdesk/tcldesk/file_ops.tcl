# =============================================================================
#
# File:		file_ops.tcl
# Project:	TkDesk
#
# Started:	22.10.94
# Changed:	22.10.94
# Author:	cb
#
# Description:	Implements classes and procs for file operations like
#		copy, move, delete, file info and disk usage (and others).
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
#s    proc dsk_bgexec {cmd label}
#s    proc dsk_create {type}
#s    proc dsk_create_callback {type name check}
#s    proc dsk_select {cmd args}
#s    proc _dsk_add_dir_to_menu {menu mdir entry}
#s    proc dsk_on_rofs {file}
#s    proc dsk_check_perm {file}
#s    proc dsk_casdirs {dir m {reset 0} {cmd ""} {mixed 0}}
#s    proc dsk_rename {args}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_bgexec
# Args:		cmd 	command to execute
#		label	label for "stand by" window
# Returns: 	Result of cmd of "break".
# Desc:		Executes dsk_bgexec in the background and waits for the
#		command to be finished. Also displays a "stand by" window,
#		which contains a button to interrupt the execution.
# Side-FX:	none
#

global dsk_bgexec
set dsk_bgexec(cnt) 0
set tkdesk(bgexec,working) 0
if ![info exists tkdesk(geometry,dsk_bgexec)] {
    set tkdesk(geometry,dsk_bgexec) ""
}

proc dsk_bgexec {cmd label args} {
    global dsk_bgexec tkdesk env

    set pad 8

    # ---- first create the "stand by" window

    set cnt [incr dsk_bgexec(cnt)]
    set t ".dsk_bgexec$cnt"
    catch "destroy $t"
    toplevel $t
    wm withdraw $t

    frame $t.fl -bd 1 -relief raised
    pack $t.fl -fill x

    set f [cb_font $tkdesk(font,labels)]
    catch {set f [join [lreplace [split $f -] 7 7 14] -]}
    label $t.label -text "$label" -font [cb_font $f]
    pack $t.label -in $t.fl -side left -padx $pad -pady $pad

    frame $t.fb -bd 1 -relief raised
    pack $t.fb -fill x

    button $t.bBreak -text "  Stop  " \
	    -command "set dsk_bgexec(stat$cnt) {} ;\
	    set dsk_bgexec(out$cnt) break ;\
	    destroy .dsk_bgexec$cnt"
    pack $t.bBreak -in $t.fb -side top -padx $pad -pady $pad -ipady 2

    #grab $t
    wm title $t "Background #$cnt"
    wm protocol $t WM_DELETE_WINDOW {# ignore}
    if {$tkdesk(geometry,dsk_bgexec) == ""} {
    	 cb_centerToplevel $t
    	 wm deiconify $t
    } else {
    	 set g [split $tkdesk(geometry,dsk_bgexec) +x]
    	 set vw [winfo vrootwidth .]
    	 if {$vw == ""} {set vw [winfo screenwidth .]}
    	 set vh [winfo vrootheight .]
    	 if {$vh == ""} {set vh [winfo screenheight .]}
    	 set x [lindex $g 2]
    	 while {$x < 0} {incr x $vw}
    	 while {$x > $vw} {incr x -$vw}
    	 set y [lindex $g 3]
    	 while {$y < 0} {incr y $vh}
    	 while {$y > $vh} {incr y -$vh}
    	 wm geometry $t +$x+$y
    	 wm deiconify $t
    }
    update

    # ---- now execute cmd

    catch "unset dsk_bgexec(cmd$cnt)"
    catch "unset dsk_bgexec(err$cnt)"
    set owd [pwd]
    # change into current directory, but not if deleting:
    if ![string match "$tkdesk(cmd,rm) *" $cmd] {
	catch {cd [dsk_active dir]}
    } else {
	# cd into a directory that's unlikely to be deleted
	cd $env(HOME)
    }
    set tkdesk(bgexec,working) 1
    #eval blt_bgexec -errorvar dsk_bgexec(err$cnt) dsk_bgexec(out$cnt) $cmd
    eval blt_bgexec dsk_bgexec(stat$cnt) \
	    -output dsk_bgexec(out$cnt) \
	    -error dsk_bgexec(err$cnt) \
	    -killsignal SIGINT \
	    $args $cmd &
    tkwait variable dsk_bgexec(stat$cnt)
    
    set tkdesk(bgexec,working) 0
    catch {set tkdesk(geometry,dsk_bgexec) [wm geometry $t]}
    catch "destroy $t"
    if [catch {cd $owd}] {
	# maybe $owd has just been deleted
	cd $tkdesk(startdir)
    }
    incr dsk_bgexec(cnt) -1

    if ![info exists dsk_bgexec(err$cnt)] {
	return $dsk_bgexec(out$cnt)
    } elseif {$dsk_bgexec(err$cnt) != ""} {
	dsk_errbell
	cb_error "$dsk_bgexec(err$cnt)"
    	return "error"
    } else {
	return $dsk_bgexec(out$cnt)
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_create
# Args:		type		"file" or "directory"
# Returns: 	""
# Desc:		Creates a new file or directory in the current directory.
# Side-FX:	none
#

set dsk_create(win,file) ""
set dsk_create(win,directory) ""
set dsk_create(open,file) 0
set dsk_create(open,directory) 0

proc dsk_create {type} {
    global tkdesk dsk_create

    if [winfo exists $dsk_create(win,$type)] {
	wm deiconify $dsk_create(win,$type)
	raise $dsk_create(win,$type)
	return
    }

    if {$type == "file"} {
	set dsk_create(win,file) [dsk_HistEntry .dhe[dsk_HistEntry :: id] \
		-label "Name of new file:" \
		-title "New File" \
		-checklabel "Open in Editor" \
		-checkvalue $dsk_create(open,file) \
		-callback {dsk_create_callback file} \
		-nograb 1]
    } else {
	set dsk_create(win,directory) [dsk_HistEntry .dhe[dsk_HistEntry :: id] \
		-label "Name of new directory:" \
		-title "New Directory" \
		-checklabel "Open after Creation" \
		-checkvalue $dsk_create(open,directory) \
		-callback {dsk_create_callback directory} \
		-nograb 1]
    }
}

# -----------------------------------------------------------------------------
# dsk_create_callback type name edit:
# Callback function of the file/dir create dialog.
#
proc dsk_create_callback {type name check} {
    global tkdesk dsk_create

    if {[string length $name] > 0} {
	catch {set name [cb_tilde $name expand]}

	if {$type == "file"} {
	    set cmd touch
	} else {
	    set cmd mkdir
	}

	if {[string index $name 0] != "/"} {
	    set name [string trimright [dsk_active dir] "/"]/$name
	}
	if [file exists $name] {
	    dsk_errbell
	    cb_error "$name already exists!"
	    dsk_create $type
	    return
	}
	set err [catch {eval exec $tkdesk(cmd,$cmd) [list $name]} errmsg]
	if $err {
	    dsk_errbell
	    cb_error "Couldn't create $name! ($errmsg)"
	    return
	}
	set win [dsk_active win]
	dsk_refresh [file dirname $name]
	dsk_select file $name

	set dsk_create(open,$type) $check
	if $check {
	    if {$type == "file"} {
		dsk_edit $name
	    } else {
		dsk_open $win $name
	    }
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_select
# Args:		cmd		command argument (X or clear or file)
# Returns: 	""
# Desc:		Copies the selected files of calling viewer to the X sel. or
#		clears the selection.
# Side-FX:	none
#

proc dsk_select {cmd args} {
    global tkdesk

    switch -glob -- $cmd {
	file {
	    set d [file dirname $args]
	    set t [file tail $args]
	    foreach fl [itcl_info objects -class dsk_FileListbox] {
		if {$d == [string trimright \
			[$fl info public directory -value] "/"]} {
		    [$fl getLbObj] select name $t
		}
	    }
	}
	X {
	    if {[itcl_info objects $tkdesk(active_viewer)] != ""} {
		$tkdesk(active_viewer) select X $args
	    }
	}
   	clear {
	    if {[itcl_info objects $tkdesk(active_viewer)] != ""} {
		$tkdesk(active_viewer) select clear
	    }
	}
    }
}

proc _dsk_add_dir_to_menu {menu mdir entry} {
    global tkdesk _dsk_dmenu

    #set mdir [string trimleft $mdir *]
    if {[llength $mdir] == 1} {
	#$menu add command -label $mdir -command "
	#$entry delete 0 end
	#$entry insert end $mdir" \
	#	-font $tkdesk(font,file_lbs)
	if {[string index $mdir 0] == "*"} {
	    set mdir [string range $mdir 1 end]
	    incr tkdesk(_dirmenu,cnt)
	    set m ${menu}.cas$tkdesk(_dirmenu,cnt)
	    catch {destroy $m}
	    menu $m -postcommand "\
		    dsk_casdirs $mdir $m 1 \{$entry delete 0 end;\
		    $entry insert end %d\}"
	    $menu add cascade -label "$mdir (*)" \
		    -font [cb_font $tkdesk(font,file_lbs)] \
		    -menu $m
	} elseif {[string index $mdir 0] == "&"} {
	    set mdir [string range $mdir 1 end]
	    incr tkdesk(_dirmenu,cnt)
	    set m ${menu}.cas$tkdesk(_dirmenu,cnt)
	    catch {destroy $m}
	    menu $m -postcommand "\
		    dsk_casdirs $mdir $m 1 \{$entry delete 0 end;\
		    $entry insert end %d\} 1"
	    $menu add cascade -label "$mdir (&)" \
		    -font [cb_font $tkdesk(font,file_lbs)] \
		    -menu $m
	} else {
	    $menu add command -label $mdir \
		    -command "$entry delete 0 end;\
		    $entry insert end $mdir" \
		    -font [cb_font $tkdesk(font,file_lbs)]
	}
    } else {
	incr _dsk_dmenu(num_cas_dirs)
	set m ${menu}.$_dsk_dmenu(num_cas_dirs)
	$menu add cascade -label [lindex $mdir 0] -menu $m \
		-font [cb_font $tkdesk(font,file_lbs)]
	catch {destroy $m}
	menu $m

	foreach d $mdir {
	    if {$d == "-"} {
		$m add separator
	    } elseif {$d == "."} {
		$m config -tearoff 1
	    } else {
		_dsk_add_dir_to_menu $m $d $entry
	    }
	}
    }
}

# -----------------------------------------------------------------------------
# dsk_on_rofs file:
# Checks if $file lives on a read-only filesystem. Returns 1 if it does.
#

proc dsk_on_rofs {file} {
    set dfo ""
    catch {set dfo [split [exec df $file] \n]}
    if {$dfo == ""} {return 0}
    set fs [lindex [lindex $dfo 1] 0]

    set fd ""
    catch {set fd [open /etc/mtab]}
    if {$fd == ""} {return 0}
    set mtab [split [read -nonewline $fd] \n]
    close $fd
    
    foreach mfs $mtab {
	if {$fs == [lindex $mfs 0]} {
	    if [regexp {^ro$|,ro$|^ro,|,ro,} [lindex $mfs 3]] {
		return 1
	    } else {
		return 0
	    }
	}
    }
    return 0
}

# -----------------------------------------------------------------------------
# dsk_check_perm file:
# Checks if $file (which can also be a directory) is deletable etc.
# by the current user.
#
proc dsk_check_perm {file} {
    set perm 1
    if ![file writable [file dirname $file]] {
	set perm 0
    }
    if [file isdirectory $file] {
	if ![file writable $file] {
	    if [file readable $file] {
		# if dir is empty it may be deleted
		set lso [exec ls $file]
		if {$lso != ""} {
		    set perm 0
		}
	    } else {
		set perm 0
	    }
	}
    }
    #else {
    #	 if ![file writable $file] {
    #	     set perm 0
    #	 }
    #}

    return $perm
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_casdirs
# Args:		dir - directory
#               m - menu's widget name
# Returns: 	""
# Desc:		Builds a cascaded menu for directory $dir.
# Side-FX:	none
#


set dsk_casdirs(menunum) 0

proc dsk_casdirs {dir m {reset 0} {cmd ""} {mixed 0}} {
    global tkdesk dsk_casdirs tk_version

    set err [catch {set fm [winfo containing [winfo pointerx .] \
	    [winfo pointery .]]}]
    if !$err {
	if {[string first "tearoff" $fm] > -1} {
	    # we're inside a torn-off menu
	    if ![info exists dsk_casdirs($fm:fixed)] {
		# adjust -menu and -postcommand options
		set li [$fm index last]
		for {set mi 0} {$mi <= $li} {incr mi} {
		    if {[$fm type $mi] == "cascade"} {
			set mm [$fm entrycget $mi -menu]
			if {[$fm index active] == $mi} {
			    set m $mm
			}
			# the submenus already exist
			set pc [$mm cget -postcommand]
			catch {set pc [lreplace $pc 2 2 $mm]}
			$mm config -postcommand $pc
		    }
		}
		wm protocol $fm WM_DELETE_WINDOW \
			"unset dsk_casdirs($fm:fixed); destroy $fm"
		set dsk_casdirs($fm:fixed) 1
	    }
	}
    }
    
    #catch "destroy $m"
    bind $m <ButtonRelease-1> "
      set tkdesk(menu,control) 0
      [bind Menu <ButtonRelease-1>]"
    bind $m <Control-ButtonRelease-1> "
      set tkdesk(menu,control) 1
      [bind Menu <ButtonRelease-1>]"
    bind $m <Shift-ButtonRelease-1> "
      set tkdesk(menu,control) 2
      [bind Menu <ButtonRelease-1>]"
    bind $m <ButtonRelease-3> [bind $m <ButtonRelease-1>]
    bind $m <Control-ButtonRelease-3> [bind $m <Control-ButtonRelease-1>]
    bind $m <Shift-ButtonRelease-3> [bind $m <Shift-ButtonRelease-1>]

    bind $m <B3-ButtonPress-1> {
	#puts "[%W entrycget [%W index active] -label]"
	dsk_casdirs_popup %W [%W index active] %X %Y
	break
    }
    bind $m <B3-ButtonRelease-1> break
    bind $m <B1-ButtonPress-3> [bind $m <B3-ButtonPress-1>]
    bind $m <B1-ButtonRelease-3> break
    

    if {$cmd == ""} {
	#set mcmd "$tkdesk(active_viewer) config -dir [list $dir]"
	set mcmd "dsk_cd [list $dir]"
    } else {
	set mcmd [string_replace $cmd "%d" [list $dir]]
    }
    
    $m delete 0 last
    if ![file readable $dir] {
	$m config -disabledforeground [cb_col $tkdesk(color,foreground)]
	$m add command -label (unreadable) \
		-font [cb_font $tkdesk(font,file_lbs)] \
		-state disabled
	update idletasks
	return
    }

    if {$dir != "/"} {
	$m add command -label [file tail [cb_tilde $dir collapse]] \
		-command $mcmd
    } else {
	$m add command -label "/" -command $mcmd
    }
    
    if {$reset} {
	for {set i 0} {$i < $dsk_casdirs(menunum)} {incr i} {
	    catch "destroy ${m}_$i"
	}
	set dsk_casdirs(menunum) 0
	set reset 0
    }

    if $mixed {
	set err [catch {set dirs [dskC_ls -P -f -p [lindex [glob $dir] 0]]}]
    } else {
	set err [catch {set dirs [dskC_ls -P -d -p [lindex [glob $dir] 0]]}]
    }
    
    if !$err {
	set c 0
	if {$dirs != ""} {
	    $m add separator
	}
	foreach d $dirs {
	    set d [string trimright $d]
	    set isdir 0
	    catch {set isdir [file isdirectory $d]}
	    if $isdir {
		set nm ${m}.$dsk_casdirs(menunum)
		if ![winfo exists $nm] {
		    menu $nm -postcommand "dsk_casdirs [list $d] $nm $reset \{$cmd\} $mixed"
		} else {
		    $nm config -postcommand "dsk_casdirs [list $d] $nm $reset \{$cmd\} $mixed"
		    #$nm delete 0 last
		}
		$m add cascade -label [file tail $d] -menu $nm \
			-font [cb_font $tkdesk(font,file_lbs)]
		incr dsk_casdirs(menunum)
	    } else {
		set t [file tail $d]
		set ignit 0
		foreach ign $tkdesk(file_tags,ignore) {
		    if [string match $ign $t] {
			set ignit 1
			break
		    }
		}
		if $ignit continue

		if {$cmd == ""} {
		    $m add command -label [file tail $d] \
			    -command "dsk_open {} [list $d]" \
			    -font [cb_font $tkdesk(font,file_lbs)]
		} else {
		    $m add command -label [file tail $d] \
			    -command [string_replace $cmd "%d" [list $d]] \
			    -font [cb_font $tkdesk(font,file_lbs)]
		}
	    }
	    incr c
	    if {$c >= $tkdesk(_max_menu_entries)} {
		set om $m
		$m add cascade -label "More..." -menu [set m $m.c$c]
		catch {destroy $m}
		menu $m
		foreach b [bind $om] {
		    bind $m $b [bind $om $b]
		}
		# set to -1 because of >= condition above
		set c -1
	    }
	}
    }
    update idletasks
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_rename
# Args:		file - name of file to rename
# Returns: 	""
# Desc:		Opens an entry dialog to rename the given file.
# Side-FX:	none
#

proc dsk_rename {args} {
    global tmpnewname tkdesk tkdesk_anno

    set files $args
    if {$files == ""} {
    	set files [_make_fnames_safe]
    }

    if {$files == ""} {
	dsk_bell
	cb_info "Please select one or more files first."
	return
    }

    foreach file $files {
	set file [subst $file]
	if ![dsk_check_perm $file] {
	    set rc [cb_dialog .trename "Permission denied" \
		    "[file tail $file]:\nYou don't have permission to rename this item." \
		    error 0 " OK " "Cancel"]
	    if {$rc == 1} {
		return
	    } else {
		continue
	    }
	}
	if [file exists $file] {
	    set tmpnewname [file tail [dskC_striptc $file]]
	    set path [file dirname [dskC_striptc $file]]
	    cb_readString "Rename $tmpnewname to:" tmpnewname "Rename File"
	    if {$tmpnewname != "" && \
		    [list $file] != [list $path/$tmpnewname]} {
		if [file exists [list $path/$tmpnewname]] {
		    if {[cb_okcancel "File \"$tmpnewname\" already exists. Overwrite?"] == 1} {
			unset tmpnewname
			continue
		    }
		}
		set err [catch {eval exec $tkdesk(cmd,mv) \
			    [list $file] [list $path/$tmpnewname]} errmsg]
		if $err {
		    cb_error $errmsg
		} else {
		    dsk_refresh $path/
		    dsk_select file [list $path/$tmpnewname]
		    dsk_DeskItem :: move [list $file] [list $path/$tmpnewname]
		    # move annotations:
		    if [info exists tkdesk_anno($file)] {
			set tkdesk_anno($path/$tmpnewname) $tkdesk_anno($file)
			unset tkdesk_anno($file)
		    }
		}
	    }
	    unset tmpnewname
	} else {
	    dsk_errbell
	    cb_error "File does not exist."
	}
    }
}

proc dsk_casdirs_popup {menu id x y} {

    # search full filename in menu entry $id's command:
    set label [$menu entrycget $id -label]
    set cmd [$menu entrycget $id -command]
    set e [lsearch -glob $cmd */$label]
    if {$e > -1} {
	set file [lindex $cmd $e]
	after 100
	dsk_popup {} $file $x $y
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_diff_files
# Arg:		files - array of two file names
# Returns: 	""
# Desc:		Runs the diff command [tkdesk(cmd,diff)] on the two files
# Side-FX:	Depends on the diff command used...
#
proc dsk_diff_files {{files ""}} {

   global tkdesk

   if {$files == ""} {
      set files [dsk_active sel]
   }

   set numfiles [llength $files]

   if {$numfiles == 0} {
      set file1 [cb_fileSelector \
      		-filter [string trimright [dsk_active dir] /]/* \
		-label "First file for comparison:" -showall 1]
      if {$file1 == ""} {
         return
      }
      incr numfiles
   } else {
      set file1 [lindex $files 0]
   }

   if {$numfiles == 1} {
      set file2 [cb_fileSelector \
      		-filter [string trimright [dsk_active dir] /]/* \
		-label "File to compare with $file1:" -showall 1]

      if {$file2 == ""} {
         return
      }
   } else {
      set file2 [lindex $files 1]
   }

   if {[catch {set tkdesk(cmd,diff)}]} {
      dsk_view diff $file1 $file2
   } else {
      eval [concat dsk_exec $tkdesk(cmd,diff) "\"$file1\"" "\"$file2\""]
   }
   return
}

