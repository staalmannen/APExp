# =============================================================================
#
# File:		action.tcl
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
#s    proc dsk_open {viewer file}
#s    proc dsk_default_action {popuplist file {matchedvar ""}}
#s    proc dsk_history_file {file}
#s    proc dsk_openall {args}
#s    proc dsk_exec {args}
#s    proc dsk_exec_trace {arr idx op}
#s    proc dsk_path_exec {path args}
#s    proc dsk_ask_exec {{cmd ""} {file ""}}
#s    proc dsk_ask_exec_ok {entry val}
#s    proc dsk_ask_dir {{browser ""}}
#s    proc dsk_ask_dir_ok {entry val}
#s    proc dsk_ask_dir {{browser ""}}
#s    proc dsk_ask_dir_ok {entry val}
#s    proc dsk_filesel {label filter args}
#s    proc dsk_filesel_ok {entry val}
#s    proc dsk_filesel_browse {entry val}
#s    proc dsk_cd {{dir ""}}
#s    proc dsk_open_dir {dir}
#s    proc dsk_open_browser {dir}
#s    proc _expand_pc {cmd {file ""} {file1 ""} {file2 ""}}
#s    proc _make_fnames_safe {{flist ""}}
#s    proc _make_fname_safe {{file ""}}
#s    proc dsk_edit {args}
#s    proc dsk_view {args}
#s    proc dsk_confirm {msg script}
#s    proc dsk_read_string {msg script args}
#s    proc dsk_read_string_ok {entry val}
#s    proc dsk_read_string-old {msg script args}
#s    proc dsk_cbhelp {file {regexp ""}}
#s    proc dsk_print {args}
#s    proc dsk_netscape {type {loc ""} {args ""}}
#s    proc dsk_textview {file}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_open
# Args:		viewer		name of calling file viewer window
#		file		name of file
# Returns: 	
# Desc:		Performs the default action for $file. Gets called after
#		a double click in a file listbox. Or from the Bookmarks
#               menu.
# Side-FX:	none
#

set dsk_open(lastcmd) ""
set tkdesk(dont_add_cmd_to_history) 0

proc dsk_open {viewer file} {
    global tkdesk cmd dsk_open env

    dsk_debug "dsk_open: viewer $viewer, file $file"
    if [catch {$viewer getToplevel}] {
	set viewer ""
    }
    
    if ![file exists $file] {
	if {$viewer != ""} {
	    $viewer config -dir [$viewer curdir]
	}
	cb_error "No such file or directory:\n$file"
	return
    }

    if ![file readable $file] {
	dsk_errbell
	cb_error "Permission denied."
	return
    }
    
    if [file isdirectory $file] {
	# DIRECTORY

	if ![file executable $file] {
	    dsk_errbell
	    cb_error "Permission denied (directory not executable)."
	    return
	}
	
	set file [subst -nocommands -novariables [_make_fname_safe $file]]
	set dname [file tail $file]
	if [string match $dname "."] {
	    set file [file dirname $file]
	} elseif [string match $dname ".."] {
	    set file [file dirname $file]
	    set file [file dirname $file]
	}

	dsk_debug "tkdesk(file_lb,control) $tkdesk(file_lb,control), viewer $viewer"
	if $tkdesk(file_lb,control) {
	    if $tkdesk(in_browser) {
		dsk_FileViewer .fv[dsk_FileViewer :: id] \
			-dir "$file" -num_lbs $tkdesk(num_lbs)
	    } else {
		dsk_FileList .dfl[dsk_FileList :: id] -dir "$file"
	    }
	    set tkdesk(file_lb,control) 0
	} elseif {$viewer != ""} {
	    #puts "$viewer config -dir \"$file\""
	    set action [dsk_default_action directories $file]
	    if {$action != ""} {
		dsk_debug "action $action"
		eval [_expand_pc $action $file]
	    }
	}

    } elseif [file_executable $file] {
	# EXECUTABLE

	if !$tkdesk(file_lb,control) {
	    dsk_busy
	    if {$tkdesk(dot_regular)} {
		if {[file extension $file] == ""} {
		    set action [dsk_default_action executables $file]
		} else {
		    set action [dsk_default_action regulars $file]
		}
	    } else {
		set action [dsk_default_action executables $file]
	    }
	    set isf 0
	    if {$action != ""} {
		if {$isf} {
		    dsk_history_file $file
		}
		cd [dsk_active dir]
		eval [_expand_pc $action $file]
		cd ~
	    }
	    dsk_lazy
	} else {
	    set cmd [file tail $file]
	    dsk_ask_exec $cmd
	    set tkdesk(file_lb,control) 0
	}

    } else {
	# REGULAR FILE

	if {$tkdesk(file_lb,control) == 1 || $tkdesk(menu,control) == 1} {
	    #set ft [file tail $file]
	    set ft [_make_fname_safe $file]
	    if {[llength $ft] == 1} {
		set cmd "$dsk_open(lastcmd) $ft"
	    } else {
		set cmd "$dsk_open(lastcmd) \"$ft\""
	    }
	    set cmd [dsk_ask_exec $cmd]
	    set tkdesk(file_lb,control) 0
	    set tkdesk(menu,control) 0
	    
	} elseif {$tkdesk(file_lb,control) == 2} {
	    # called from one of the appbar special menus with Shift pressed
	    dsk_DeskItem .di[dsk_DeskItem :: id] \
		    -file [cb_tilde $file expand]
	    set tkdesk(file_lb,control) 0
	    
	} else {
	    dsk_busy
	    update idletasks
	    set action [dsk_default_action regulars $file]
	    
	    if {$action != "" && $action != "-"} {
		# add file to file history
		dsk_history_file $file
		
		cd [dsk_active dir]
		# make TkDesk "lazy" before background execution
		dsk_lazy
		
		eval [_expand_pc $action $file]
		cd ~
	    } else {
		dsk_lazy
	    }
	}

    }
}

# ----------------------------------------------------------------------------
# dsk_default_action popuplist file ?matchedvar?
# Returns the default action for $file in list $tkdesk(popup,$popuplist).
# If matchedvar is specified it's the name of a variable that will be
# set to the matching pattern.
#

proc dsk_default_action {popuplist file {matchedvar ""}} {
    global tkdesk

    dsk_debug "dsk_default_action: popuplist $popuplist, file $file, matchedvar $matchedvar"
    if ![info exists tkdesk(popup,$popuplist)] return
    if {$matchedvar != ""} {
	upvar 1 $matchedvar mpat
    }

    set action_found 0
    set action ""
    set fname [file tail $file]
    foreach entry $tkdesk(popup,$popuplist) {
	set patlist [lindex $entry 0]

	foreach pat $patlist {
	    if [string match $pat $fname] {
		set elist [lindex $entry 1]
		set action "set tkdesk(error_source) Popups ;\
			[lindex [lindex $elist 0] 1] ;\
			set tkdesk(error_source) {}"
		set action_found 1
		set mpat $pat
		break
	    }
	}

	if $action_found  break
    }

    return $action
}

proc dsk_history_file {file} {
    global tkdesk env
    
    set tkdesk(dont_add_cmd_to_history) 1
    if {[string first $env(HOME) $file] == 0} {
	file_history add [string_replace $file $env(HOME) ~]
    } else {
	file_history add $file
    }
    set tkdesk(dont_add_cmd_to_history) 0
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_openall
# Args:		files		(opt.) list of files
# Returns: 	""
# Desc:		Opens all selected files (or $files). "Open" means it
#		performs the default action for each file.
# Side-FX:	
#

proc dsk_openall {args} {
    global tkdesk

    set files $args
    if {$files == ""} {
    	set files [dsk_active sel]
    }

    if {$files == ""} {
	dsk_bell
	cb_info "Please select one or more files first."
	return
    }

    dsk_busy
    foreach file $files {
	dsk_open [dsk_active window] $file
    }
    dsk_lazy

    return
}

# ----------------------------------------------------------------------------
# dsk_openwith files:
# Asks for command to open $files with.

proc dsk_openwith {{files ""}} {
    global tkdesk dsk_open

    if {$files == ""} {
    	set files [dsk_active sel]
    }
    
    if {$files == ""} {
	dsk_bell
	cb_info "Please select one or more files first."
	return
    }

    set ft {}
    foreach file $files {
	lappend ft [_make_fname_safe $file]
    }
    set cmd "$dsk_open(lastcmd) $ft"
    set cmd [dsk_ask_exec $cmd]
    set tkdesk(file_lb,control) 0
    set tkdesk(menu,control) 0
	    
    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_exec
# Args:		args		command line to execute
# Returns: 	pid or ""
# Desc:		Executes command $args in the background.
#               If $args matches dsk_*, $args is evaluated.
# Side-FX:	none
#

set tkdesk(dsk_exec,pids) ""
set tkdesk(dsk_exec,cmds) ""
global dsk_exec
if ![info exists dsk_exec(bgcnt)] {set dsk_exec(bgcnt) 0}
if ![info exists dsk_exec(shell)] {set dsk_exec(shell) 0}

proc dsk_exec {args} {
    global tkdesk env dsk_exec

    if {$args == ""} {
	return
    }

    set cmd $args
    set p [lindex $cmd 0]
    if [string match dsk_* $p] {
	#if {[info procs $p] != ""} {
	    set err [catch {eval $cmd} errmsg]
	    if $err {
		dsk_errbell
		cb_error "Malformed internal command.\n($errmsg)"
	    }
	    return
	#} else {
	#    dsk_errbell
	#    cb_alert "Not an internal command: $p"
	#    return
	#}
    } else {
	if ![dsk_auto_execok $p] {
	    dsk_errbell
	    cb_alert "Can't execute: $p"
	    return
	}
    }

    dsk_busy
    if !$tkdesk(dont_add_cmd_to_history) {
	if {[string first $env(HOME) $cmd] == 0} {
	    exec_history add [string_replace $cmd $env(HOME) ~]
	} else {
	    exec_history add $cmd
	}
    }
    set cnt [incr dsk_exec(bgcnt)]
    dsk_sound dsk_exec_launch
    if [file_executable $cmd] {
	# then dsk_exec is called from dsk_open

    	cd [file dirname $cmd]
	if $tkdesk(exec_as_root) {
	    set cmd [string_replace $tkdesk(cmd,su,exec) %c $cmd]
	    dsk_debug "SU: $cmd"
	}
	set err [catch {set pid \
		[eval blt_bgexec dsk_exec(bgvar,$cnt) \
		$cmd >@stdout </dev/null &]} errmsg]
    	cd ~
	if $err {
	    dsk_lazy
	    dsk_errbell
	    cb_error $errmsg
	    return 0
	}
    } else {
	set shell_args ""
	set cmd ""

	set inredir 0
	foreach token $args {
	    if [string match {<*} $token] {
		lappend shell_args $token
		set inredir 1
	    } elseif [string match {>*} $token] {
		lappend shell_args $token
	    } elseif [string match {2>*} $token] {
		lappend shell_args $token
	    } elseif [string match {&} $token] {
		continue
	    } else {
		lappend cmd $token
	    }
	}
	if !$inredir {
	    lappend shell_args "</dev/null"
	}

	set cmd [string_replace $cmd \{ \"]
	set cmd [string_replace $cmd \} \"]
	set cmd [dskC_esc $cmd \[\]]
	if {[string first " ~" $cmd] > -1} {
	    set cmd [string_replace $cmd " ~" " $env(HOME)"]
	}
	if [info exists dsk_exec(dir)] {
	    if [file isdirectory $dsk_exec(dir)] {
		set dsk_exec(bgdir,$cnt) $dsk_exec(dir)
		cd $dsk_exec(dir)
	    }
	    unset dsk_exec(dir)
	} else {
	    set dsk_exec(bgdir,$cnt) [dsk_active dir]
	    cd $dsk_exec(bgdir,$cnt)
	}
	dsk_debug "Executing: sh -c \"exec $cmd\" $shell_args &"
	set err 0
	if $tkdesk(exec_as_root) {
	    set cmd [string_replace $tkdesk(cmd,su,exec) %c $cmd]
	    dsk_debug "SU: $cmd"
	}
	if $dsk_exec(shell) {
	    set dsk_exec(shell) 0
	    set err [catch {set pid [eval blt_bgexec dsk_exec(bgvar,$cnt) \
		    sh -c [list "exec $cmd"] >@stdout $shell_args &]} errmsg]
	} else {
	    if !$tkdesk(in_development) {
		set err [catch {set pid [eval blt_bgexec dsk_exec(bgvar,$cnt) \
			$cmd >@stdout $shell_args &]} errmsg]
	    } else {
		set pid [eval blt_bgexec dsk_exec(bgvar,$cnt) \
			$cmd >@stdout $shell_args &]
	    }
	}
	cd ~
	if {$err && !$tkdesk(in_development)} {
	    dsk_errbell
	    dsk_lazy
	    cb_error $errmsg
	    return
	}
	#set pid [exec sh -c \"exec $cmd\" $shell_args &]
    }
    set dsk_exec(bgcmd,$cnt) $cmd
    trace variable dsk_exec(bgvar,$cnt) w dsk_exec_trace
    regsub -all "\n" $cmd "; " cmd2
    regsub -all "\[\t \]\[\t \]*" $cmd2 " " cmd2
    dsk_status "Launched:  $cmd2"
    dsk_lazy

    lappend tkdesk(dsk_exec,pids) $pid
    if {[llength $args] > 1} {
    	lappend tkdesk(dsk_exec,cmds) "$args"
    } else {
    	lappend tkdesk(dsk_exec,cmds) $args
    }

    if [winfo exists .dsk_jobs] {
	dsk_jobs_fill
    }

    return $pid
}

# this proc will be invoked when a dsk_exec'ed command exits:
proc dsk_exec_trace {arr idx op} {
    global dsk_exec tkdesk

    set num [lindex [split $idx ,] 1]
    set cmd $dsk_exec(bgcmd,$num)
    set exit_code [lindex $dsk_exec(bgvar,$num) 2]
    unset dsk_exec(bgvar,$num)
    unset dsk_exec(bgcmd,$num)

    dsk_sound dsk_exec_exit
    regsub -all "\n" $cmd "; " cmd2
    regsub -all "\[\t \]\[\t \]*" $cmd2 " " cmd2
    dsk_status "Exit ($exit_code):  $cmd2"

    if [info exists dsk_exec(bgdir,$num)] {
	set tkdesk(inhibit_status) 1
	dsk_refresh $dsk_exec(bgdir,$num)
	set tkdesk(inhibit_status) 0
	unset dsk_exec(bgdir,$num)
    }
}

# -----------------------------------------------------------------------------
# dsk_path_exec path args:
# Execute $args in $path.
#

proc dsk_path_exec {path args} {
    global dsk_exec

    set dsk_exec(dir) $path
    eval dsk_exec $args
}

# -----------------------------------------------------------------------------
# dsk_path_view path args:
# Execute $args in $path.
#

proc dsk_path_view {path args} {
    global dsk_exec

    set dsk_exec(dir) $path
    eval dsk_view $args
}

# -----------------------------------------------------------------------------
# dsk_raise_or_exec interp cmd raisewin
# Checks whether $interp is already running.  If it does sends it the command
# to raise $raisewin (default ".").  If it doesn't executes $cmd.
#

proc dsk_raise_or_exec {interp cmd {raisewin .}} {
    foreach int [winfo interps] {
        if {$int == $interp} {
            send -async $interp "wm deiconify $raisewin; raise $raisewin"
            dsk_status "Raised already running $interp"
            return 1
        }
    }
    return [dsk_exec $cmd]
}

# -----------------------------------------------------------------------------
# dsk_exec_as_root args:
# Execute $args in $path.
#

proc dsk_exec_as_root {args} {
    global tkdesk

    set ov $tkdesk(exec_as_root)
    set tkdesk(exec_as_root) 1
    eval dsk_exec $args
    set tkdesk(exec_as_root) $ov
}

# -----------------------------------------------------------------------------
# dsk_view_as_root args:
# Execute $args in $path.
#

proc dsk_view_as_root {args} {
    global tkdesk

    set ov $tkdesk(exec_as_root)
    set tkdesk(exec_as_root) 1
    eval dsk_view $args
    set tkdesk(exec_as_root) $ov
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_ask_exec
# Args:		none
# Returns: 	pid
# Desc:		Asks the user which command to execute.
# Side-FX:	none
#

if ![info exists tkdesk(cmd_history)] {
    set tkdesk(cmd_history) ""
}

global dsk_ask_exec
set dsk_ask_exec(cnt) 0

proc dsk_ask_exec {{cmd ""} {file ""}} {
    global tkdesk dsk_ask_exec

    set t .he_ask_exec

    if [winfo exists $t] {
	wm deiconify $t
	raise $t
	return
    }

    # cope with a bug in itcl 1.5
    if {[itcl_info objects $t] != {}} {
	incr dsk_ask_exec(cnt)
	set t "$t$dsk_ask_exec(cnt)"
    }

    if $tkdesk(exec_as_root) {
	set lab "Open or Execute as root:"
	set dsk_ask_exec(as_root) 1
    } else {
	set lab "Open or Execute:"
	set dsk_ask_exec(as_root) 0
    }
    
    set dsk_asc_exec(cmd) ""
    dsk_HistEntry $t \
	    -title "Execute" \
	    -label $lab \
	    -checklabel "View Output" \
	    -checkvalue 0 \
	    -entrydefault $cmd \
	    -history cmd_history \
	    -callback dsk_ask_exec_ok \
	    -nograb 1
}

proc dsk_ask_exec_ok {entry val} {
    global tkdesk dsk_open dsk_ask_exec
    
    set tmpcmd $entry
    
    if {$tmpcmd == ""} {
	dsk_bell
	return
    }

    set asr $tkdesk(exec_as_root)
    set tkdesk(exec_as_root) $dsk_ask_exec(as_root)
    
    cmd_history add $tmpcmd
    cd [dsk_active dir]
    if [file isdirectory $tmpcmd] {
	dsk_open_dir $tmpcmd
    } elseif {[file_executable $tmpcmd] || \
	    [dsk_auto_execok [lindex $tmpcmd 0]]} {
	set tmpcmd [_expand_pc $tmpcmd]
	if $val {
	    set err [catch {eval dsk_view $tmpcmd} errmsg]
	} else {
	    set err [catch {eval dsk_exec $tmpcmd} errmsg]
	}

	if $err {
	    dsk_errbell
	    cb_error $errmsg
	}

	set cmd $tmpcmd
	if {$cmd != ""} {
	    set dsk_open(lastcmd) [string range $cmd 0 \
		    [expr [string first " " $cmd] - 1]]
	    if {[set og [string first \" $dsk_open(lastcmd)]] > -1} {
		set dsk_open(lastcmd) [string range $dsk_open(lastcmd) \
			0 [expr $og - 2]]
		
	    }
	}
	
    } elseif [file readable $tmpcmd] {
	dsk_open "" $tmpcmd
    } else {
	dsk_errbell
	cb_error "Couldn't open/execute $tmpcmd."
    }
    set tkdesk(exec_as_root) $asr
    cd ~
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_ask_dir
# Args:		none
# Returns: 	""
# Desc:		Asks the user which directory to open.
# Side-FX:	none
#

proc dsk_ask_dir {{browser ""}} {
    global tkdesk
    
    dsk_HistEntry .he[dsk_HistEntry :: id] \
	    -title "Open Directory" \
	    -label "Directory to open:" \
	    -checklabel "In Browser" \
	    -checkvalue [expr [string match "browser" $browser] || \
	                $tkdesk(in_browser)] \
	    -history dir_history \
	    -callback dsk_ask_dir_ok
}


proc dsk_ask_dir_ok {entry val} {
    global tkdesk
    
    set tmpdir $entry
    
    if {$tmpdir != ""} {
	if ![file exists $tmpdir] {
	    dsk_bell
	    cb_alert "The path you specified is not completely valid."
	    set tmpdir [_make_path_valid $tmpdir]
	}
	if [file readable $tmpdir] {
	    dsk_busy
	    if $val {
		dsk_FileViewer .fv[dsk_FileViewer :: id] \
			-dir $tmpdir -num_lbs $tkdesk(num_lbs)
	    } else {
		dsk_FileList .dfl[dsk_FileList :: id] -dir $tmpdir
	    }
	    dsk_lazy
	} else {
	    dsk_errbell
	    cb_error "Permission denied."
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_ask_dir
# Args:		none
# Returns: 	""
# Desc:		Asks the user which directory to open.
# Side-FX:	none
#

proc dsk_ask_dir {{browser ""}} {
    global tkdesk
    
    dsk_HistEntry .he[dsk_HistEntry :: id] \
	    -title "Open Directory" \
	    -label "Directory to open:" \
	    -checklabel "In Browser" \
	    -checkvalue [expr [string match "browser" $browser] || \
	                $tkdesk(in_browser)] \
	    -history dir_history \
	    -callback dsk_ask_dir_ok
}


proc dsk_ask_dir_ok {entry val} {
    global tkdesk
    
    set tmpdir $entry
    
    if {$tmpdir != ""} {
	if ![file exists $tmpdir] {
	    dsk_bell
	    cb_alert "The path you specified is not completely valid."
	    set tmpdir [_make_path_valid $tmpdir]
	}
	if [file readable $tmpdir] {
	    dsk_busy
	    if $val {
		dsk_FileViewer .fv[dsk_FileViewer :: id] \
			-dir $tmpdir -num_lbs $tkdesk(num_lbs)
	    } else {
		dsk_FileList .dfl[dsk_FileList :: id] -dir $tmpdir
	    }
	    dsk_lazy
	} else {
	    dsk_errbell
	    cb_error "Permission denied."
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_filesel
# Args:		none
# Returns: 	""
# Desc:		Asks the user which directory to open.
# Side-FX:	none
#

proc dsk_filesel {label filter args} {
    global tkdesk dsk_filesel

    set dsk_filesel(file) ""
    set dsk_filesel(filter) $filter
    set dsk_filesel(label) $label
    set dsk_filesel(args) $args

    set filter [cb_tilde $filter collapse]
    if [string match {*[Ss]ave*} $label] {
	set dsk_filesel(use_old_box) 1
	set dsk_filesel(saving) 1
    } else {
	set dsk_filesel(use_old_box) 1
	set dsk_filesel(saving) 0
    }

    dsk_HistEntry .he[dsk_HistEntry :: id] \
	    -title "Select A File" \
	    -entrydefault [string trimright [file dirname $filter] /]/ \
	    -entrypopupproc dsk_filesel_file_menu \
	    -label $label \
	    -history file_history \
	    -callback dsk_filesel_ok \
	    -addbutton "Browse..." \
	    -addcallback "dsk_filesel_browse"

    if {$dsk_filesel(file) != ""} {
	file_history add [cb_tilde $dsk_filesel(file) collapse]
    }
    return $dsk_filesel(file)
}

proc dsk_filesel_ok {entry val} {
    global tkdesk dsk_filesel

    return [set dsk_filesel(file) $entry]
}

proc dsk_filesel_file_menu {entry} {

    set path [$entry get]
    if {![file isdirectory $path]} {
	set path [_make_path_valid $path /]
    }
    dsk_debug "path: $path"

    if [file isdirectory $path] {
	set m [winfo toplevel $entry].m
	catch {destroy $m}
	menu $m -postcommand "dsk_casdirs [_make_fname_safe $path] $m 1 \"dsk_filesel_menu_cb $entry %d\" 1"
	
	update
	tk_popup $m [winfo pointerx $m] [winfo pointery $m]
	focus -force $m
	tkwait window $m
	update idletasks
    }
    
}

proc dsk_filesel_menu_cb {entry sel} {
    $entry delete 0 end
    $entry insert end $sel
}

proc dsk_filesel_browse {entry val} {
    global tkdesk dsk_filesel

    set showall 0
    foreach arg $dsk_filesel(args) {
	switch $arg {
	    "showall" {
		set showall 1
	    }
	}
    }

    set dir [_make_path_valid $entry]
    set file ""
    set isdir 0
    set err 0
    
    catch {set isdir [file isdirectory $entry]}
    if $isdir {
	if {$entry != "/"} {
	    set entry [string trimright $entry /]
	}
	if !$dsk_filesel(use_old_box) {
	    set tkdesk(_ed_browser) [dsk_open_dir $entry]
	} else {
	    if {[info command tk_getSaveFile] == {}} {
		set file [cb_fileSelector \
			-filter $entry/[file tail $dsk_filesel(filter)] \
			-label $dsk_filesel(label) -showall $showall]
	    } else {
		global tk_strictMotif

		if {$tkdesk(file_selector_type) != "default"} {
		    set osm $tk_strictMotif
		    if {$tkdesk(file_selector_type) == "tk"} {
			set tk_strictMotif 0
		    } else {
			set tk_strictMotif 1
		    }
		}
		if $dsk_filesel(saving) {
		    set err [catch {set file [tk_getSaveFile \
			    -title $dsk_filesel(label) \
			    -initialdir $entry]} errmsg]
		} else {
		    set err [catch {set file [tk_getOpenFile \
			    -title $dsk_filesel(label) \
			    -initialdir $entry]} errmsg]
		}
		if {$tkdesk(file_selector_type) != "default"} {
		    set tk_strictMotif $osm
		}
	    }
	}
    } else {
	if !$dsk_filesel(use_old_box) {
	    set tkdesk(_ed_browser) [dsk_open_dir [file dirname $entry]]
	} else {
	    if {[info command tk_getSaveFile] == {}} {
		set file [cb_fileSelector -filter $dir/$dsk_filesel(filter) \
			-label $dsk_filesel(label) -showall $showall]
	    } else {
		global tk_strictMotif

		#set osm $tk_strictMotif
		#set tk_strictMotif 0
		if $dsk_filesel(saving) {
		    set err [catch {set file [tk_getSaveFile \
			    -title $dsk_filesel(label) \
			    -initialdir $dir]} errmsg]
		} else {
		    set err [catch {set file [tk_getOpenFile \
			    -title $dsk_filesel(label) \
			    -initialdir $dir]} errmsg]
		}
		#set tk_strictMotif $osm
	    }
	}
    }
    if !$dsk_filesel(use_old_box) {
	return ""
    } else {
	if {$err} {
	    dsk_errbell
	    cb_error "Error: $errmsg"
	}
	return [set dsk_filesel(file) $file]
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_cd
# Args:		dir	name of directory
# Returns: 	""
# Desc:		Display directory $dir in the active file viewer.
# Side-FX:	none
#

proc dsk_cd {{dir ""} {openNew 0}} {
    global tkdesk env

    if {$dir == ""} return
    if {$dir == "\{\}"} {dsk_errbell; return}

    set special ""
    
    if $tkdesk(menu,control) {
	set openNew 1
	set tkdesk(menu,control) 0
    }

    if {$dir == ".."} {
	set ad [dsk_active dir]
	if {$ad == "/"} {
	    dsk_bell
	    return
	}
	set dir [file dirname [string trimright $ad /]]
    } elseif ![file isdirectory $dir] {
	if [regexp {\.tar\.gz$|\.tgz$} $dir] {
	    # it's a compressed tar file
	    set special "tar"
	} elseif !$openNew {
	    set dir [file dirname $dir]
	} else {
	    dsk_open {} $dir
	    return
	}
    }

    if {$dir != "" && \
	    [string length [itcl_info objects $tkdesk(active_viewer)]] > 0} {
	if {![file isdirectory $dir] && $special == ""} {
	    set dir [_make_path_valid $dir]
	    catch {dsk_bell}
	    cb_alert "The path you specified does not exist."
	}
	if {[info command dsk_cd_callback] != ""} {
	    dsk_cd_callback $dir
	}
	if !$openNew {
	    $tkdesk(active_viewer) config -directory $dir
	} else {
	    dsk_open_dir $dir
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_open_dir
# Args:		dir		directory to open
# Returns: 	""
# Desc:		Opens a window for directory $dir
# Side-FX:	none
#

proc dsk_open_dir {dir} {
    global tkdesk

    set f ""
    
    if [file readable $dir] {
	if $tkdesk(in_browser) {
	    set f [dsk_FileViewer .fv[dsk_FileViewer :: id] \
		    -directory "$dir" -num_lbs $tkdesk(num_lbs)]
	} else {
	    set f [dsk_FileList .dfl[dsk_FileList :: id] -directory "$dir"]
	}
    } else {
	dsk_errbell
	cb_error "Permission denied."
    }

    return $f
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_open_browser
# Args:		dir		directory to open
# Returns: 	""
# Desc:		Opens a browser window for directory $dir
# Side-FX:	none
#

proc dsk_open_browser {dir} {
    global tkdesk
    
    if [file readable $dir] {
	dsk_FileViewer .fv[dsk_FileViewer :: id] -dir $dir \
		-num_lbs $tkdesk(num_lbs)
    } else {
	dsk_errbell
	cb_error "Permission denied."
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_expand_pc
# Args:		cmd	command line with %?
#		file	(opt.) name of selected file (with path)
# Returns: 	cmd with %? expanded
# Desc:		Expands all %? shortcuts in the given command line.
#		Does also some preprocessing of the command.
# Side-FX:	none
#

proc _expand_pc {cmd {file ""} {file1 ""} {file2 ""}} {
    global tkdesk

    dsk_debug -nonewline "Expanding \"$cmd\" to "

    if {$file == ""} {
	set files [_make_fnames_safe]
	set file [lindex $files 0]
    } else {
	set file [_make_fname_safe $file]
	set files $file
    }

    if {$file == ""} {
	if {[string first "%A" $cmd] > -1 || \
	    [string first "%a" $cmd] > -1} {
	    dsk_bell
	    cb_info "Please select one or more files first."
	    return ""
	} elseif {[string first "%" $cmd] > -1} {
	    if {[string first "%B" $cmd] == -1 && \
		[string first "%D" $cmd] == -1 && \
		[string first "%X" $cmd] == -1 && \
		[string first "%x" $cmd] == -1} {
	    	cb_info "Please select a file first."
	    	return ""
	    }
	}
    }

    set xsel ""
    if {[string first "%x" $cmd] > -1} {
	set err [catch {set xsel [selection get]}]
	if $err {
	    cb_info "The X-selection is empty."
	    return ""
	}
    } elseif {[string first "%X" $cmd] > -1} {
	catch {set xsel [selection get]}
    }

    if {[string first % $file] > -1} {
	# temporarily replace % in the filename:
	set file [string_replace $file "%" "_!percent!_"]
	set percent_in_file 1
    } else {
	set percent_in_file 0
    }
    if {[string first % $files] > -1} {
	# temporarily replace % in the filenames:
	set files [string_replace $files "%" "_!percent!_"]
	set percent_in_files 1
    } else {
	set percent_in_files 0
    }

    set dir [dsk_active dir]
    if {$dir != "/"} {
	set dir [string trimright $dir /]
    }
    set ocmd $cmd
    set pcmd ""
    foreach cmd [split $ocmd \n] {
	if {[string first "%s" $cmd] > -1} {
	    set cmd [string_replace $cmd %s [list $file]]
	}
	if {[string first "%S" $cmd] > -1} {
	    set cmd [string_replace $cmd %S $file1]
	}
	if {[string first "%T" $cmd] > -1} {
	    set cmd [string_replace $cmd %T [list $file2]]
	}
	if {[string first "%d" $cmd] > -1} {
	    set cmd [string_replace $cmd %d [list [file dirname $file]]]
	}
	if {[string first "%f" $cmd] > -1} {
	    set cmd [string_replace $cmd %f [list [file tail $file]]]
	}
	if {[string first "%b" $cmd] > -1} {
	    set ft [file tail $file]
	    set cmd [string_replace $cmd %b [list [string range \
		    $ft 0 [expr [string last "." $ft] - 1 ]]]]
	}
 	if {[string first "%c" $cmd] > -1} {
 	    set cmd [string_replace $cmd %c [list [file tail [list [string \
		    range $file 0 [expr [string last "." $file] - 1 ]]]]]]
 	}
	if {[string first "%A" $cmd] > -1} {
	    set cmd [string_replace $cmd %A $files]
	}
	if {[string first "%a" $cmd] > -1} {
	    # currently, files of a specific browser may only be
	    # selected in the same directory
	    set result {}
	    foreach fname $files {
		lappend result [file tail $fname]
	    }
	    set cmd [string_replace $cmd %a $result]
        }
	if {[string first "%B" $cmd] > -1} {
	    if {$files != ""} {
		set cmd [string_replace $cmd %B $files]
	    } else {
		set cmd [string_replace $cmd %B ""]
	    }
	}
	if {[string first "%D" $cmd] > -1} {
	    set cmd [string_replace $cmd %D [list $dir]]
	}
	if {[string first "%x" $cmd] > -1} {
	    set cmd [string_replace $cmd %x [string trimright $xsel \;]]
	}
	if {[string first "%X" $cmd] > -1} {
	    set cmd [string_replace $cmd %X [string trimright $xsel \;]]
	}

	if {$percent_in_file || $percent_in_files} {
	    set cmd [string_replace $cmd "_!percent!_" "%"]
	}

	append pcmd "$cmd\n"
    }

    dsk_debug "\"$pcmd\""
    return [subst -nocommands -novariables $pcmd]
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_make_fnames_safe
# Args:		none
# Returns: 	Names of currently selected files with all Tcl-special chars
#               ([ etc.) backslashed. Calls _make_fname_safe.
# Desc:		...
# Side-FX:	none
#

proc _make_fnames_safe {{flist ""}} {
    global tkdesk

    if {$flist == ""} {
	set flist [dsk_active sel]
    }
    if {$flist == ""} {return ""}

    foreach file $flist {
	#if {[string first "\\" $file] > -1} continue

	set nfile [_make_fname_safe $file]
	if {$nfile != ""} {
	    lappend rlist $nfile
	}
    }

    #puts $rlist
    #if {[llength $rlist] == 1} {
    #	 return [lindex $rlist 0]
    #} else {
    #	 return $rlist
    #}
    return $rlist
}

# -----------------------------------------------------------------------------
#
# Proc:		_make_fname_safe
# Args:		file - filename
# Returns: 	filename with all Tcl-special chars ([ etc.) backslashed
# Desc:		...
# Side-FX:	none
#

proc _make_fname_safe {{file ""}} {

    if {$file == ""} {return ""}

    set nfile [dskC_esc $file { \"[]{}$;}]
    return $nfile
}


#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_edit
# Args:		args		a list of filenames to edit
# Returns: 	""
# Desc:		Calls the in "System" specified editor on the given files.
#		The editor will run in the background.
# Side-FX:	none
#

proc dsk_edit {args} {
    global tkdesk

    set files ""
    set linenum ""
    set e ""
    foreach f $args {
	if [regexp {^\+[1-90]+$} $f] {
	    set linenum $f
	} elseif ![file isdirectory $f] {
	    if {$linenum != ""} {
		lappend files [list $linenum $f]
		set linenum ""
	    } else {
		lappend files $f
	    }
	}
    }

    if {$files == "{New File}"} {
	if {$tkdesk(editor,cmd) == "builtin"} {
	    set files ""
	} else {
	    set files "new_file"
	}
    } elseif {$files == ""} {
	#set files [cb_fileSelector \
	#	 -filter [string trimright [dsk_active dir] /]/* \
	#	 -label "File to edit:" -showall 1]
	while {1} {
	    set files [dsk_filesel "File to edit:" \
		    [string trimright [dsk_active dir] /]/* showall]
	    set isdir 0
	    catch {set isdir [file isdirectory $files]}
	    if {$files == ""} {
		return
	    } elseif $isdir {
		dsk_errbell
		cb_error "$files is a directory. Please choose a file."
	    } else {
		break
	    }
	}
    }
    
    if $tkdesk(editor,mfiles) {
	if {$tkdesk(editor,cmd) != "builtin"} {
	    eval dsk_exec $tkdesk(editor,cmd) $files
	} else {
	    if {$files != ""} {
		dsk_Editor [set e .de[dsk_Editor :: id]] -files $files
		if {[string length [$e cget -files]] == 0} {$e delete}
		#dsk_editor load $files
	    } else {
		set e [dsk_editor new]
	    }
	}
    } else {
	foreach file $files {
	    if {$tkdesk(editor,cmd) != "builtin"} {
		dsk_exec $tkdesk(editor,cmd) $file
	    } else {
		dsk_Editor [set e .de[dsk_Editor :: id]] -files $file
		if {[string length [$e cget -files]] == 0} {$e delete}
		#dsk_editor load $file
	    }
	}
    }

    return $e
}


proc dsk_edit_wait {args} {
    set e [eval dsk_edit $args]
    if {$e != ""} {
	set ew ""
	catch {set ew [$e getToplevel]}
	if {[winfo exists $ew]} {
	    tkwait window $ew
	} else {
	    puts stderr "no such win: $ew"
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_view
# Args:		args - shell command
# Returns: 	""
# Desc:		Displays the standard output of command $args in the builtin
#               editor.
# Side-FX:	none
#

proc dsk_view {args} {

    set p [lindex $args 0]
    if ![dsk_auto_execok $p] {
	dsk_errbell
	cb_alert "Can't execute: $p"
	return
    }
    eval dsk_editor cmd $args
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_confirm
# Args:         msg - message to display in the dialog box
#               args - tcl script
# Returns: 	""
# Desc:		Evaluates $args after a positive confirmation.
# Side-FX:	none
#

proc dsk_confirm {msg script} {

    if ![cb_okcancel $msg] {
	eval $script
    }
}

proc dsk_msg_alert {msg} {
    cb_alert $msg
}

proc dsk_msg_info {msg} {
    cb_info $msg
}

proc dsk_msg_error {msg} {
    cb_error $msg
}


#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_read_string
# Args:         msg - message to display in the dialog box
#               args - tcl script
# Returns: 	""
# Desc:		Evaluates $args if the entered string is != "".
# Side-FX:	none
#

proc dsk_read_string {msg {script {}} args} {
    global dsk_read_string dsk_read_string_script

    set dontpaste 0
    foreach a $args {
	switch $a {
	    "dontpaste" {
		set dontpaste 1
	    }
	}
    }

    set tmpvar ""
    if !$dontpaste {
	catch {set tmpvar [selection get]}
    }
    #if {[string first " " $tmpvar] > -1} {
    #	 set tmpvar ""
    #}
    set tmpvar [string trimleft $tmpvar " "]
    set dsk_read_string_script $script
    set dsk_read_string {}
    if {[string length $script] == 0} {
	set noapply 1
    } else {
	set noapply 0
    }

    dsk_HistEntry .he[dsk_HistEntry :: id] \
	    -title "Enter String" \
	    -label $msg \
	    -entrydefault $tmpvar \
	    -history string_history \
	    -noapply $noapply \
	    -callback dsk_read_string_ok

    return $dsk_read_string
}

proc dsk_read_string_ok {entry val} {
    global dsk_read_string dsk_read_string_script tkdesk

    if {$entry != ""} {
	update
	string_history add $entry
	set dsk_read_string $entry
	if {$dsk_read_string_script != {}} {
	    eval $dsk_read_string_script
	}
    }
}

proc dsk_read_string-old {msg script args} {
    global dsk_read_string tmpvar

    set dontpaste 0
    foreach a $args {
	switch $a {
	    "dontpaste" {
		set dontpaste 1
	    }
	}
    }

    set tmpvar ""
    if !$dontpaste {
	catch {set tmpvar [selection get]}
    }
    if {[string first " " $tmpvar] > -1} {
	set tmpvar ""
    }
    set dsk_read_string [cb_readString $msg tmpvar]
    update
    if {$dsk_read_string != ""} {
	eval $script
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_cbhelp
# Args:		file, (opt.) mode/regexp
# Returns: 	""
# Desc:		Invokes the cb_Help::show class procedure.
# Side-FX:	none
#

proc dsk_cbhelp {file {regexp ""}} {
    global tkdesk

    dsk_busy
    if {[string first "|" $file] > -1} {
	dsk_status "Launched:  [string trimleft $file {| }]"
    }
    cb_help show $file $regexp
    if {[string first "|" $file] > -1} {
	dsk_status "Exit:  [string trimleft $file {| }]"
    }
    dsk_lazy
}

# ---------------------------------------------------------------------------
# dsk_print:
# Asks for the command to use when printing files.
#
proc dsk_print {args} {
    global tkdesk dsk_print

    set files $args
    if {$files == ""} {
    	set files [_make_fnames_safe]
    }
    if {$files == ""} {
	dsk_bell
	cb_info "Please select one or more files first."
	return
    }
    set dsk_print(files) $files
    set dsk_print(string) ""

    set cmd [printer_history last]
    if {$cmd == ""} {
	if [info exists tkdesk(cmd,print)] {
	    set cmd $tkdesk(cmd,print)
	} else {
	    set cmd "lpr"
	}
    }

    dsk_HistEntry .he[dsk_HistEntry :: id] \
	    -title "Print" \
	    -label "Print command (file names will be appended):" \
	    -entrydefault $cmd \
	    -history printer_history \
	    -callback dsk_print_ok
    
}

# ---------------------------------------------------------------------------
# dsk_print_string:
# Asks for the command to use when printing strings.
#
proc dsk_print_string {string} {
    global tkdesk dsk_print

    set dsk_print(string) $string
    set dsk_print(files) ""

    if [info exists tkdesk(cmd,print)] {
	set cmd $tkdesk(cmd,print)
    } else {
	set cmd "lpr"
    }

    dsk_HistEntry .he[dsk_HistEntry :: id] \
	    -title "Print" \
	    -label "Print command (pipe):" \
	    -entrydefault $cmd \
	    -history printer_history \
	    -callback dsk_print_ok
    
}

proc dsk_print_ok {entry val} {
    global tkdesk dsk_print
    
    set cmd $entry
    
    if {$cmd == ""} {
	dsk_bell
	return
    }
    
    printer_history add $cmd
    set tkdesk(cmd,print) $cmd
    dsk_busy
    if {$dsk_print(files) != ""} {
	set fs $dsk_print(files)
	set fs [string_replace $fs \{ \"]
	set fs [string_replace $fs \} \"]
	set fs [dskC_esc $fs \[\]]
	dsk_debug "dsk_print: $cmd $fs"
	set err [catch {eval exec $cmd $fs &} errmsg]
    } else {
	set err [catch {set fd [open "|$cmd" "w"]} errmsg]
	if !$err {
	    catch {
		puts -nonewline $fd $dsk_print(string)
		close $fd
	    }
	}
    }
    dsk_lazy
    if $err {
	dsk_errbell
	cb_error $errmsg
    }
}

# ---------------------------------------------------------------------------
# dsk_netscape:
# Makes use of Ken Hornstein's netscape-remote extension to communicate
# with Netscape.  If Netscape has not been started yet, TkDesk starts it.
# Extension by Paul P.H. Wilson to handle various Netscape v4.03 modes
# (06.10.97)
#
proc dsk_netscape {type {loc ""} {args ""}} {
    global tkdesk

    if {[lsearch "window" $args] > -1} {set win 1} {set win 0}
    if {[lsearch "raise" $args] > -1} {set raise "raise"} {set raise "noraise"}

    set url ""
    if {$type == "file"} {
	set url "file:$loc"
    } elseif {$type == "url"} {
	set url "$loc"
    } elseif {$type == "rcmd"} {
        if {$loc == "messenger" || $loc == "mail"} {
            set cmd "xfeDoCommand(openInbox)"
        } elseif {$loc == "discussions" || $loc == "news"} {
            set cmd "xfeDoCommand(openNewsgroups)"
        } elseif {$loc == "composer" || $loc == "edit"} {
            set cmd "xfeDoCommand(openEditor)"
        } elseif {$loc == "send"} {
            set cmd "xfeDoCommand(composeMessage)"
            set loc "mail"
        } else {
            error "dsk_netscape: unkown remote command $loc"
        }
    } else {
	error "dsk_netscape: unknown type $type"
    }
    if {$url != ""} {
	if $win {
	    set cmd "openURL($url,new-window,$raise)"
	} else {
	    set cmd "openURL($url,$raise)"
	}
    }

    #puts $cmd
    if [info exists tkdesk(netscapeWinId)] {
	set err [catch {send-netscape -id $tkdesk(netscapeWinId) $cmd}]
	if $err {
	    unset tkdesk(netscapeWinId)
	    set err [catch {send-netscape -idvar tkdesk(netscapeWinId) $cmd}]
	}
    } else {
	set err [catch {send-netscape -idvar tkdesk(netscapeWinId) $cmd}]
    }
    
    if $err {
	set start_netscape 0
	if {$tkdesk(confirm_netscape)} {
	    if {[cb_yesno "Netscape doesn't seem to be running yet on your display. Start it now?"] == 0} {
		set start_netscape 1
	    }
	} else {
	    if {![file exists ~/.netscape/lock]} {
		set start_netscape 1
	    } else {
		puts stderr "tkdesk: Netscape already running"
	    }
	}
	
	if {$start_netscape} {
	    # start new netscape
	    if {$type == "rcmd"} {
		eval dsk_exec $tkdesk(cmd,netscape) -$loc
	    } else {
		if {$url != ""} {
		    eval dsk_exec $tkdesk(cmd,netscape) $url
		} else {
		    eval dsk_exec $tkdesk(cmd,netscape)
		}
	    }
	}
    }
}

# ----------------------------------------------------------------------------
# dsk_textview file:
# Displays $file in the built-in editor. The created window and buffer
# is bound to the browser/list window that was active when this proc
# was invoked.
#
proc dsk_textview {file} {
    
    set w [dsk_active window]
    if {$w != ""} {
	set dir [file dirname $file]
	if {$dir == "."} {
	    set dir [dsk_active dir]
	    if {$dir != "/"} {
		set dir [string trimright $dir /]
	    }
	}
	$w textview $dir/[file tail $file]
    } else {
	cb_error "No active viewer!"
    }
}

# ----------------------------------------------------------------------------
# dsk_exec_here cmd dir:
#
set dsk_exec(here,view) 0
proc dsk_exec_here {cmd dir} {
    global dsk_exec tkdesk

    set dsk_exec(here,dir) $dir
    
    if $tkdesk(exec_as_root) {
	set lab "Execute as root (%A: all selected):"
    } else {
	set lab "Enter Command (%A: all selected):"
    }
    
    dsk_HistEntry .dsk_exec_here \
	    -title "Execute here" \
	    -label $lab \
	    -checklabel "View Output" \
	    -checkvalue $dsk_exec(here,view) \
	    -entrydefault $cmd \
	    -history xhere_history \
	    -callback "dsk_exec_here_do" \
	    -nograb 0
}

proc dsk_exec_here_do {cmd val} {
    global tkdesk dsk_exec

    set dsk_exec(here,view) $val
    if {$cmd != ""} {
	xhere_history add $cmd
	if {![string match "dsk_*" [lindex $cmd 0]]} {
	    if $val {
		set cmd "dsk_view $cmd"
	    } else {
		set cmd "dsk_exec $cmd"
	    }
	}
	update
	dsk_busy
	set dsk_exec(dir) $dsk_exec(here,dir)
	set dsk_exec(shell) 1
	set cmd [_expand_pc $cmd]
	set err [catch {eval $cmd} errmsg]
	dsk_lazy
	if $err {
	    cb_error $errmsg
	}
    } else {
	dsk_bell
	return
    }
}

# ----------------------------------------------------------------------------
# dsk_mail file ?string?:
# Send $file via email.  If $file is the empty string, $string is piped
# to the mail command $tkdesk(cmd,mail).
#
proc dsk_mail {file {string ""}} {
    global tkdesk dsk_mail

    if {$file != ""} {
	set dsk_mail(file) $file
	set dsk_mail(string) ""
	dsk_HistEntry .dsk_mail \
		-title "Send File" \
		-label "Send file to:" \
		-history mail_history \
		-callback dsk_mail_ok
    } else {
	set dsk_mail(file) ""
	set dsk_mail(string) $string
	dsk_HistEntry .dsk_mail \
		-title "Send Buffer" \
		-label "Send buffer to:" \
		-history mail_history \
		-callback dsk_mail_ok
    }
}

proc dsk_mail_ok {entry val} {
    global tkdesk dsk_mail
    
    set address $entry
    
    if {$address == ""} {
	dsk_bell
	return
    }
    
    mail_history add $address
    set cmd $tkdesk(cmd,mail)

    if {$dsk_mail(file) != ""} {
	set cmd [string_replace $cmd %s [file tail $dsk_mail(file)]]
	set cmd [string_replace $cmd %a $address]
	dsk_busy
	set err [catch {eval exec cat $dsk_mail(file) | $cmd} errmsg]
	dsk_lazy
	if $err {
	    dsk_errbell
	    cb_error $errmsg
	}
    } else {
	set cmd [string_replace $cmd %s TkDesk-Buffer]
	set cmd [string_replace $cmd %a $address]
	dsk_busy
	set err [catch {eval exec echo [list $dsk_mail(string)] | $cmd} errmsg]
	dsk_lazy
	if $err {
	    dsk_errbell
	    cb_error $errmsg
	}
    }
}

# ---------------------------------------------------------------------------
# dsk_man names:
# Lookup manual pages for each of $names.
# Example for $names: "col socket(2) malloc(3)"

proc dsk_man {{names ""}} {

    if {$names == ""} {
	set names [dsk_read_string "Show manual page for: (e.g. col(1))"]
    }
    
    foreach name $names {
	set l [split $name ()]
	if {[llength $l] == 1} {
	    dsk_view man $l | col -b
	    #dsk_cbhelp "| man $l | col -b" man
	} else {
	    dsk_view man [lindex $l 1] [lindex $l 0] | col -b
	    #dsk_cbhelp "| man [lindex $l 1] [lindex $l 0] | col -b" man
	}
    }
}
