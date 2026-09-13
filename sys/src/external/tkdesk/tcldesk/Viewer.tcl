# =============================================================================
#
# File:		dsk_FileViewer.tcl
# Project:	TkDesk
#
# Started:	11.10.94
# Changed:	21.12.96
#
# Description:	Implements a class for the main file viewer window.
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
#s    itcl_class dsk_FileViewer
#s    method config {config}
#s    method cget {var}
#s    method close {}
#s    method curdir {}
#s    method refresh {{mode ""}}
#s    method refreshdir {dir}
#s    method status {str {do_update 1}}
#s    method status_ready {{do_update 1}}
#s    method selstatus {}
#s    method select {cmd}
#s    method _set_first_lb {num}
#s    method _dblclick {lb sel}
#s    method _popup {lb sel mx my}
#s    method _resize {}
#s    method _selecting {lb}
#s    method _dd_drophandler {}
#s    method _button_bar {}
#s    proc id {{cmd ""}}
#
# =============================================================================

# this var prevents double printing of status when opening a dir:
set tkdesk(config_nostat) 0

#
# =============================================================================
#
# Class:	dsk_FileViewer
# Desc:		This creates a toplevel that is the (or a) main window
#		for the file viewer (menu, entries, listboxes etc.).
#
# Methods:	
# Procs:	
# Publics:
#

itcl_class dsk_FileViewer {
    inherit dsk_Common Toplevel
    
    constructor {config} {
	global [set this] tkdesk env cb_tools

	if {$tkdesk(tcl_version) < 8.0} {
	    Toplevel::constructor
	    dsk_Common::constructor
	}

	wm withdraw $top
	dsk_busy

	#
	# Create menubar
	#
	frame $top.fMenu -bd 2 -relief raised
	pack $top.fMenu -fill x
	_create_menubar $top.fMenu

	# ---- create button bar
	if {[llength $tkdesk(button_bar)] > 0} {
	    if {$tkdesk(pad) > 0} {
		frame $top.fButtonBar -bd 1 -relief raised
	    } else {
		frame $top.fButtonBar -bd 0 -relief raised
	    }
	    pack $top.fButtonBar -after $top.fMenu -fill x
	    _create_button_bar $top.fButtonBar
	}
	
	# ---- create path entry
	if {$tkdesk(pad) > 0} {
	    frame $top.fPE -bd 1 -relief raised
	} else {
	    frame $top.fPE -bd 0 -relief raised
	}
	pack $top.fPE -fill x

	entry $top.ePE -bd 2 -relief sunken
	bindtags $top.ePE "$top.ePE Entry All"
	pack $top.ePE -in $top.fPE -side left -fill x -expand yes \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2
	bind $top.ePE <Double-1> "[bind Entry <Triple-1>]; break"
	bind $top.ePE <Any-Enter> {
	    if $tkdesk(focus_follows_mouse) {focus %W}
	}
	bind $top.ePE <Return> "$this config -dir \[$top.ePE get\]"
	bind $top.ePE <Control-Return> "set tkdesk(menu,control) 1
				$this config -dir \[$top.ePE get\]
				%W delete 0 end
				%W insert end \[$this curdir\]"
	bind $top.ePE <Tab> "focus $top; break"
	bind $top.ePE <3> "update idletasks; $this _path_popup %X %Y"
	cb_bindForCompletion $top.ePE <Control-Tab>
	cb_balloonHelp $top.ePE {The path displayed in the current window. Change to visit another directory.  The right mouse button gives a popup menu of parent directories.}
    	blt_drag&drop target $top.ePE \
				handler file "dd_handle_text $top.ePE %v 1"

	frame $top.fPE.dis -width $tkdesk(pad)
	pack $top.fPE.dis -side right
	menubutton $top.mbHist -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
		-menu $top.mbHist.menu
	pack $top.mbHist -in $top.fPE -side right -ipadx 2 -ipady 2

	menu $top.mbHist.menu \
		-postcommand "dir_history buildmenu $top.mbHist.menu ; update"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$top.mbHist.menu add command -label "dummy"
	dir_history changed
	bind $top.mbHist.menu <ButtonRelease-1> "
		set tkdesk(menu,control) 0
		[bind Menu <ButtonRelease-1>]"
	bind $top.mbHist.menu <Control-ButtonRelease-1> "
		set tkdesk(menu,control) 1
		[bind Menu <ButtonRelease-1>]"

	# ---- create horizontal scrollbar
	if {$tkdesk(pad) > 0} {
	    frame $top.fsb -bd 1 -relief raised
	} else {
	    frame $top.fsb -bd 0 -relief raised
	}
	pack $top.fsb -fill x
	
	scrollbar $top.hsb -orient horizontal -relief sunken \
		-command "$this _set_first_lb"
	$top.hsb set 1 3 0 2
	pack $top.hsb -in $top.fsb -fill x \
		-padx $tkdesk(pad) -pady $tkdesk(pad)
	
	#
	# ---- Create listboxes
	#
	frame $top.fLBs
	pack $top.fLBs -fill both -expand yes
	set j 0
	for {set i 0} {$i < $num_lbs} {incr i} {
	    if {$tkdesk(tcl_version) >= 8.0} {
		set lbname ::[namespace tail $top.lb$j]
	    } else {
		set lbname $top.lb$j
	    }
	    incr j
	    dsk_FileListbox $lbname -viewer $this  \
		-width $tkdesk(file_lb,minwidth) \
		-height $tkdesk(file_lb,minheight) -pad $tkdesk(pad)
	    update idletasks
	    set lbname [$lbname getFrame]
	    pack $lbname -in $top.fLBs -side left -fill both -expand yes
	    #update
	    pack propagate $lbname 0
	}
	set num_lbs_created $j

	# ---- create status bar
	frame $top.fStatus -bd [expr $tkdesk(pad) > 0] -relief raised
	pack [set f $top.fStatus] -fill x
	label $f.l -anchor w -font [cb_font $tkdesk(font,status)]
	#	-bd [expr $tkdesk(pad) > 0] -relief sunken
	#pack $f.l -fill x -padx $tkdesk(pad) -pady $tkdesk(pad)
	pack $f.l -fill x -padx [expr $tkdesk(pad) / 2] \
		-pady [expr $tkdesk(pad) / 2]

	#
	# Bindings
	#
	bind $top <Any-Enter> \
		"set tkdesk(active_viewer) $this; break"
	bind $top <Tab> "focus $top.ePE; break"

	bind $top <Control-i> "dsk_fileinfo; break"
	bind $top <Control-f> "dsk_find_files; break"
	bind $top <Control-n> "dsk_create file; break"	
	bind $top <Control-d> "dsk_create directory; break"	
	bind $top <Control-c> "dsk_copy; break"
	bind $top <Control-r> "dsk_rename; break"
	bind $top <Delete> "dsk_delete; break"
	bind $top <Control-x> "dsk_ask_exec; break"
	bind $top <Control-e> "dsk_edit; break"
	bind $top <Control-o> "dsk_ask_dir; break"
	bind $top <Control-b> "dsk_bookmark add; break"
	bind $top <Control-p> "dsk_print; break"
	bind $top <Control-w> "dsk_openwith; break"
	bind $top <Control-Home> {dsk_cd ~; break}
	bind $top <Control-Left> {dsk_cd [list [dir_history back]]; break}
	bind $top <Control-Right> {dsk_cd [list [dir_history forward]]; break}
	bind $top <Return> "dsk_openall; break"
	bind $top <F1> "dsk_cbhelp $tkdesk(library)/doc/Guide howto"
	#bind $top <a><b><o><u><t> dsk_about

	bind $top <BackSpace> {dsk_cd ..}
	bind $top <Up> "$this keynav up"
	bind $top <Down> "$this keynav down"
	bind $top <Prior> "$this keynav pgup"
	bind $top <Next> "$this keynav pgdown"
	bind $top <Home> "$this keynav first"
	bind $top <End> "$this keynav last"
	bind $top <Menu> "$this keynav menu"
	bind $top <F11> "$this keynav lbmenu"
	foreach l {a b c d e f g h i j k l m n o p q r s t u v w x y z} {
	    bind $top <Key-$l> "$this keynav $l"
	    bind $top <Shift-$l> "$this keynav $l reverse"
	}
	foreach l {A B C D E F G H I J K L M N O P Q R S T U V W X Y Z} {
	    bind $top <Key-$l> "$this keynav [string tolower $l] reverse"
	    #bind $top <Shift-$l> "$this keynav $l"
	}

	#
	# Window manager settings
	#
	update idletasks
	wm title $top "TkDesk Version $tkdesk(version)"
	wm minsize $top $tkdesk(file_lb,minwidth) $tkdesk(file_lb,minheight)
	#wm geometry $top $tkdesk(file_lb,width)x$tkdesk(file_lb,height)
	dsk_place_window $top fbrowser \
		$tkdesk(file_lb,width)x$tkdesk(file_lb,height) 1
	wm protocol $top WM_DELETE_WINDOW "$this close"

	if $tkdesk(fvwm) {
	    # create the icon window
	    # (this code is based on the code posted by:
	    # kennykb@dssv01.crd.ge.com (Kevin B. Kenny))
	    toplevel $top-icon -bg [cb_col $tkdesk(color,icon)] \
		    -class Icon
	    wm withdraw $top-icon
	    label $top-icon.label \
		    -image [dsk_image $tkdesk(icon,filebrowser)] -bd 0 \
		    -bg [cb_col $tkdesk(color,icon)]
	    pack $top-icon.label -ipadx 2 -ipady 2
	    blt_drag&drop target $top-icon.label handler \
		    file "$this _dd_drophandler %v"
	    update idletasks
	    wm geometry $top-icon \
		    [winfo reqwidth $top-icon]x[winfo reqheight $top-icon]
	    wm protocol $top-icon WM_DELETE_WINDOW "$this delete"
	    wm iconwindow $top $top-icon
	} else {
	    wm iconbitmap $top @$tkdesk(library)/images/xbm/bigfiling.xbm
	}
	
	incr count		;# incr the counter of opened fv windows
	set tkdesk(menu,control) 0
	set tkdesk(file_lb,control) 0

        #                          
        #  Explicitly handle config's that may have been ignored earlier
        #                            
        foreach attr $config {
            config -$attr [set $attr]
        }

	dsk_sound dsk_new_filebrowser
	if !$dontmap {
	    wm deiconify $top
	    tkwait visibility $top
	    catch "lower $top .dsk_welcome"
	    update
	}

	# the status line may become quite large
	#pack propagate $top.fStatus 0
	pack propagate $top 0
	update

	dsk_lazy
    }

    destructor {
	global tkdesk
	
	for {set i 0} {$i < $num_lbs_created} {incr i} {
	    catch "$top.lb$i delete"
	}
	incr count -1
	catch {destroy $top-icon}
	set tkdesk(active_viewer) ""
	foreach fv "[itcl_info objects -class dsk_FileViewer] \
		[itcl_info objects -class dsk_FileList]" {
	    if {"$fv" != "$this"} {
		set tkdesk(active_viewer) $fv
	    }
	}
    }

    #
    # ----- Methods and Procs -------------------------------------------------
    #

    method config {config} {
    }

    method cget {var} {
	return [set [string trimleft $var -]]
    }

    method close {} {
	global tkdesk env

	# add current directory to history before closing window:
	if {[string first $env(HOME) $directory] == 0} {
	    dir_history add [string_replace $directory $env(HOME) ~]
	} else {
	    dir_history add $directory
	}
	
	if [winfo exists .dsk_appbar] {
	    $this delete
	} elseif {[dsk_active viewer] == 1} {
	    # about to close last window
	    dsk_exit 1
	} else {
	    $this delete
	}
    }

    method curdir {} {
	return $directory
    }

    method refresh {{mode ""}} {
	if {$mode == "all"} {
	    foreach fv [itcl_info objects -class dsk_FileViewer] {
	    	$fv refresh
	    }
	} else {
	    for {set i 0} {$i < $num_lbs_created} {incr i} {
		set lbdirs($i) ""
	    }
	    $this config -directory $directory
	}
    }

    method refreshdir {dir} {
	#puts "refreshdir: $dir"
	for {set i 0} {$i < $dir_depth} {incr i} {
	    if {$lbdirs($i) == $dir} {
		$top.lb$i refresh
		#$this status "Ready."
		break
	    }
	}
    }

    method keynav {what {opt ""}} {
	dsk_debug "keynav $what $opt"
	
	# scroll listboxes all to the right:
	_set_first_lb 1000
	for {set i 0} {$i < $dir_depth - 1} {incr i} {
	    ::[$top.lb$i getLbObj] select clear
	    ::$top.lb$i _tag_icons
	}

	set lb ::[$top.lb$i getLbObj]
	switch $what {
	    up {
		$lb select up
	    }
	    down {
		$lb select down
	    }
	    pgup {
		$lb select pgup
	    }
	    pgdown {
		$lb select pgdown
	    }
	    first {
		$lb select first
	    }
	    last {
		$lb select last
	    }
	    menu {
		set file [dsk_active sel]
		if {$file != ""} {
		    dsk_popup "" $file [winfo pointerx .] [winfo pointery .]
		}
	    }
	    lbmenu {
	        set lbf [$top.lb$i getFrame]
		set mb $lbf.mb
		$mb.menu post [winfo rootx $mb] [expr [winfo rooty $mb] + [winfo height $mb]]
		focus $mb.menu
		$mb.menu activate 0
	    }
	    default {
		if {$opt == "reverse"} {
		    $lb select letter $what 1
		} else {
		    $lb select letter $what
		}
	    }
	}
	::$top.lb[expr $dir_depth -1] _tag_icons
    }

    method select {cmd args} {
	global tkdesk
	
	switch -glob -- $cmd {
	    get		{# return a list of all selected files
		set sfl ""
		for {set i 0} {$i < $dir_depth} {incr i} {
		    set err [catch {
			if ![winfo exists [[$top.lb$i getLbObj] getFrame]] {
			    continue
			}
		    } errmsg]
		    if {$err} {
			continue
		    }
		    set sl [::[$top.lb$i getLbObj] select get]
		    if {$sl != ""} {
		        set fl [::[$top.lb$i getLbObj] get]
			foreach s $sl {
			    set file [lindex [split [lindex $fl $s] \t] 0]
			    set file [string trimright $file " "]
			    if $tkdesk(append_type_char) {
				set file [dskC_striptc $file]
			    }
			    lappend sfl "$lbdirs($i)$file"
			}
		    }
		}
		return $sfl
	    }
	    clear	{# clear selection in all listboxes
		for {set i 0} {$i < $num_lbs_created} {incr i} {
		    ::[$top.lb$i getLbObj] select clear
		    $top.lb$i _tag_icons
		}
		$this selstatus
	    }
	    X		{# copy selected filenames to X selection
		set sfl [$this select get] 
		if {$sfl != ""} {
		    if {$args == "names"} {
			selection handle $top "$this _retrieve_X_names"
		    } else {
			selection handle $top "$this _retrieve_X"
		    }
		    selection own $top
		} else {
		    cb_info "Please select one or more files first."
		}
	    }
	    default	{
		error "$this select: unknown option $cmd"
	    }
	}
    }

    method _set_first_lb {num} {
	global tkdesk
	
	# lb$num is to become the leftmost listbox
	#puts "$num, $first_lb, $dir_depth; [$top.hsb get]"

	if $tkdesk(dynamic_scrollbars) {
	    if {$dir_depth > $num_lbs} {
		pack $top.fsb -before $top.fLBs -fill x
	    } else {
		pack forget $top.fsb
	    }
	}

	if {$first_lb == $num && \
		$dir_depth == [lindex [$top.hsb get] 0]} return

	if {$num < 0} {
	    set num 0
	}

	set max_flb [cb_max 0 [expr $dir_depth - $num_lbs]]
	if {$num > $max_flb} {
	    set num $max_flb
	}

	if {$first_lb == 0 && $num == 0} {
	    $top.hsb set $dir_depth $num_lbs $first_lb \
				[expr $first_lb + $num_lbs - 1]
	    return
	}
	if {$first_lb == $max_flb && $num == $max_flb} {
	    $top.hsb set $dir_depth $num_lbs $first_lb \
				[expr $first_lb + $num_lbs - 1]
	    return
	}

	set diff [expr $num - $first_lb]
	#puts "diff: $diff"
	switch -- $diff {
	    1 {
		pack forget [$top.lb$first_lb getFrame]
		if {$num_lbs > 1} {
		    set i [expr $num + $num_lbs - 1]
		    pack [$top.lb$i getFrame] \
			    -after [$top.lb[expr $num + $num_lbs-2] getFrame] \
			    -in $top.fLBs -side left -fill both \
			    -expand yes
		} else {
		    set i [expr $num + $num_lbs - 1]
		    pack [$top.lb$i getFrame] \
			    -in $top.fLBs -side left -fill both \
			    -expand yes
		}
		#update idletasks
		#update
		pack propagate [$top.lb$i getFrame] 0
	    }
	    -1 {
		pack forget [$top.lb[expr $first_lb + $num_lbs - 1] getFrame]
		if {$num_lbs > 1} {
		    pack [$top.lb$num getFrame] \
			    -before [$top.lb$first_lb getFrame] \
			    -side left -fill both \
			    -expand yes
		} else {
		    pack [$top.lb$num getFrame] \
			    -in $top.fLBs -side left -fill both \
			    -expand yes
		}
		#update idletasks
		#update
		pack propagate [$top.lb$num getFrame] 0
	    }
	    default	{
		for {set i $first_lb} \
			{$i < [expr $first_lb + $num_lbs]} {incr i} {
		    pack forget [$top.lb$i getFrame]
		}
		for {set i $num} \
			{$i < [expr $num + $num_lbs]} {incr i} {
		    pack [$top.lb$i getFrame] \
			    -in $top.fLBs -side left -fill both \
			    -expand yes
		    #update idletasks
		    #update
		    pack propagate [$top.lb$i getFrame] 0
		}
	    }
	}

	set first_lb $num
	$top.hsb set $dir_depth $num_lbs $first_lb \
				[expr $first_lb + $num_lbs - 1]

    }

    method _dblclick {lb sel} {
	global tkdesk

	dsk_debug "Viewer $this, lb $lb, sel $sel"
	if {$sel == "" || $lb == ""} {
	    return
	}
	if {$tkdesk(single_click) && [llength $sel] > 1} {
	    return
	}

	set dir [string trimright [$lb info public directory -value] "/"]
	#set file [lindex [lindex [$lb.dlb get] [lindex $sel 0]] 0]
	set file [string trimright [lindex [split \
		[lindex [::[$lb getLbObj] get] \
		[lindex $sel 0]] \t] 0] " "]
	if $tkdesk(append_type_char) {
	    set file [dskC_striptc $file]
	}
	if {[string first "/" $file] == -1} {
	    set file "$dir/$file"
	}
	dsk_debug "file $file"
	if {!$tkdesk(single_click) || \
		($tkdesk(single_click) && [file isdirectory $file])} {
	    ::dsk_open $this "$file"
	}
	if [file isdirectory $file] {
	    select clear
	}
    }

    method _popup {lb sel mx my} {
	if {$sel == "" || $lb == ""} {
	    return
	}
	set dir [string trimright [$lb info public directory -value] "/"]
	#set file [lindex [lindex [$lb.dlb get] [lindex $sel 0]] 0]
	set file [string trimright [lindex [split \
		[lindex [::[$lb getLbObj] get] \
		[lindex $sel 0]] \t] 0] " "]
	::dsk_popup $lb "$dir/$file" $mx $my
	#$this selstatus
    }

    method _resize {} {
	global tkdesk [set this]

	if {$num_lbs != [set [set this](num_lbs)]} {
	    dsk_busy
	    pack propagate $top 1
	    if {$num_lbs_created < [set [set this](num_lbs)]} {
		for {set j $num_lbs_created} \
			{$j < [set [set this](num_lbs)]} {incr j} {
		    if {$tkdesk(tcl_version) >= 8.0} {
			set lbname ::$top.lb$j
		    } else {
			set lbname $top.lb$j
		    }
	    	    dsk_FileListbox $lbname -viewer $this  \
			-width $tkdesk(file_lb,minwidth) -pad $tkdesk(pad)
		    update
		    set lbname [::$lbname getFrame]
	    	    pack $lbname -in $top.fLBs -side left \
			-fill both -expand yes
		    pack propagate $lbname 0
		}
		set num_lbs_created [set [set this](num_lbs)]
	    } else {
		$this _set_first_lb 0
		if {$num_lbs < [set [set this](num_lbs)]} {
		    for {set j $num_lbs} \
			    {$j < [set [set this](num_lbs)]} {incr j} {
		    	pack [$top.lb$j getFrame] -in $top.fLBs -side left \
				-fill both -expand yes
			update
			pack propagate [$top.lb$j getFrame] 0
		    }
		} else {
		    for {set j [set [set this](num_lbs)]} \
			    {$j < $num_lbs} {incr j} {
		    	pack forget [$top.lb$j getFrame]
		    }
		}
	    }
	    set num_lbs [set [set this](num_lbs)]
	    update idletasks
	    pack propagate $top 0
	    $this config -directory $directory
	    dsk_lazy
	}
    }

    method _selecting {lb} {
	global tkdesk

	dsk_debug "_selecting: lb $lb, num_lbs_created $num_lbs_created"
	if {$tkdesk(free_selection)} {
	    return
	}

	for {set i 0} {$i < $num_lbs_created} {incr i} {
	    if {[string trimleft $top.lb$i :] != [string trimleft $lb :]} {
		::[$top.lb$i getLbObj] select clear
		::$top.lb$i _tag_icons
	    }
	}
    }

    method _dd_drophandler {args} {
	global tkdesk

	catch "wm withdraw $tkdesk(dd_token_window)"
	update
	set dest $directory
	set flist $args

	if ![file writable $dest] {
	    dsk_errbell
	    if {$dest != ""} {
	    	cb_error "You don't have write permission for this directory!"
	    } else {
		cb_error "This listbox is not a valid target (since it's empty)."
	    }
	    return
	}

	#dsk_debug "Rec.: $flist"
	#dsk_debug "dest: $dest"
	dsk_ddcopy $flist $dest
    }

    method _button_bar {} {
	_create_button_bar $top.fButtonBar
    }

    method _configDirectory {} {
	# backend private proc of public var "directory"
	global tkdesk env

	#set directory "[string trimright [glob $directory] "/"]/"
	set directory "[string trimright [cb_tilde $directory expand] "/"]/"
	set directory [dsk_canon_path $directory]
	dsk_debug "Directory $directory"

	set strip_i 0
	if $tkdesk(strip_home) {
	    if [string match "$env(HOME)/*" $directory] {
		set strip_i [string length "$env(HOME)"]
	    }
	}

	if [info exists tkdesk(strip_parents)] {
	    foreach d $tkdesk(strip_parents) {
		set d [string trimright $d /]
		if [string match "$d/*" $directory] {
		    set strip_i [string length $d]
		    break
		}
	    }
	}

	# determine depth of directory
	set dir_depth 0
	set first_i 0
	set cmask ""
	set l [string length $directory]
	for {set i $strip_i} {$i < $l} {incr i} {
	    if {[string index $directory $i] == "/"} {
		set ndir [string range $directory 0 $i]
		if ![info exists lbdirs($dir_depth)] {
		    set lbdirs($dir_depth) $ndir
		} elseif {$ndir != $lbdirs($dir_depth)} {
		    set lbdirs($dir_depth) $ndir
		} else {
		    catch {set cmask [$top.lb$first_i cget -mask]}
		    incr first_i
		}
		incr dir_depth
	    }
	}
	#puts $cmask
	if {$first_i == $dir_depth && $first_i} {
	    set first_i [expr $dir_depth - 1]
	}
	for {set i $dir_depth} {$i < $num_lbs_created} {incr i} {
	    set lbdirs($i) ""
	}

	#
	# fill list boxes
	#
	dsk_FileListbox :: print_ready 0
	for {set i $first_i} {$i < $dir_depth} {incr i} {
	    if {$i >= $num_lbs_created && ![winfo exists $top.lb$i]} {
		if {$tkdesk(tcl_version) >= 8.0} {
		    set lbname ::[namespace tail $top.lb$i]
		} else {
		    set lbname $top.lb$i
		}
	        dsk_FileListbox $lbname -viewer $this  \
			-width $tkdesk(file_lb,minwidth) \
			-height $tkdesk(file_lb,minheight) -pad $tkdesk(pad)
		update idletasks
		if {$cmask != ""} {
		    $top.lb$i set_mask $cmask
		}
		pack propagate [$lbname getFrame] 0
	    }

	    $top.lb$i config -directory $lbdirs($i)
	    if {$i > 0} {
		$top.lb[expr $i - 1] tagpath $lbdirs($i)
	    }
	}
	$top.lb[expr $dir_depth - 1] tagpath

	if {$i > $num_lbs_created} {
	    set num_lbs_created $i
	} else {
	    while {$i < $num_lbs_created} {
		$top.lb$i clear
		incr i
	    }
	}

	set flb [cb_max 0 [expr $dir_depth - $num_lbs]]
	#puts "dd: $dir_depth"
	$this _set_first_lb $flb

	# add last directory to the path history:
	if {$last_directory != ""} {
	    if {[string first $env(HOME) $last_directory] == 0} {
		dir_history add [string_replace $last_directory $env(HOME) ~]
	    } else {
		dir_history add $last_directory
	    }
	}
	set last_directory $directory

	# update the path entry:
	$top.ePE delete 0 end
	$top.ePE insert end [cb_tilde $directory collapse]

	#wm title $top [cb_tilde $directory collapse]
	#wm iconname $top [file tail [string trimright $directory "/"]]/
	set_title

	if !$tkdesk(config_nostat) {
	    $this status "Ready. [dsk_fs_status $directory]"
	    #$this status "Ready."
	}
	dsk_FileListbox :: print_ready 1
	dsk_status_ready 0
    }

    proc id {{cmd ""}} {
	if {$cmd == ""} {
	    set i $id
	    incr id
	    return $i
	} elseif {$cmd == "reset"} {
	    set id 0
	    set count 0
	}
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    public num_lbs 3

    public dontmap 0

    public dir {} {
	global tkdesk

	set access_ok 1
	set err [catch {$top config}]
	if !$err {
	    set err [catch {set isdir [file isdirectory $dir]}]
	    if !$err {
		if !$isdir {
		    if [regexp {\.tar\.gz$|\.tgz$} $dir] {
			# it's a compressed tar file
			#set ls_proc {dsk_ls_tar}
			puts "tar: $dir"
		    } else {
			catch {set dir [_make_path_valid $dir]}
			if ![winfo exists .dsk_welcome] {
			    # don't want this during startup
			    catch {dsk_bell}
			    cb_alert "The path you specified is not completely valid."
			}
		    }
		} elseif ![file readable $dir] {
		    dsk_errbell
		    cb_error "[file tail $dir]: Permission denied."
		    set access_ok 0
		}
	    } else {
		cb_error "Path (or user?) does not exist. Opening home directory."
		set dir ~
	    }

	    if {$access_ok} {
		if $tkdesk(menu,control) {
		    if {$tkdesk(tcl_version) >= 8.0} {
			set lname ::.dfl[dsk_FileList :: id]
		    } else {
			set lname .dfl[dsk_FileList :: id]
		    }
		    dsk_FileList $lname -directory $dir
		    set tkdesk(menu,control) 0
		} else {
		    $this config -directory $dir
		}
	    }
	}
    }

    public directory "/" {
	global tkdesk env

	if {[winfo exists $top]} {
	    dsk_busy
	    _configDirectory
	    dsk_lazy
	}
    }

    protected dir_depth 0	;# depth of the current directory
    protected first_lb 0        ;# number of leftmost listbox
    protected num_lbs_created 0	;# number of created listboxes (>= num_lbs)
    protected lbdirs		;# array of each lb's directory
    protected sb_state "packed"
    protected last_directory ""
    protected ls_proc {}

    common count 0
    common id 0
}

