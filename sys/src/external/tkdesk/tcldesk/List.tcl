# =============================================================================
#
# File:		dsk_FileList.tcl
# Project:	TkDesk
#
# Started:	09.10.94
# Changed:	09.10.94
# Author:	cb
#
# Description:	Implements a class that opens a file-list toplevel.
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
#s    itcl_class dsk_FileList
#s    method config {config}
#s    method cget {var}
#s    method close {}
#s    method curdir {}
#s    method refresh {{mode ""}}
#s    method refreshdir {dir}
#s    method select {cmd}
#s    method _dblclick {lb sel}
#s    method _popup {lb sel mx my}
#s    method _selecting {lb}
#s    method _dd_drophandler {}
#s    method _button_bar {}
#s    proc id {{cmd ""}}
#
# =============================================================================

#
# =============================================================================
#
# Class:	dsk_FileList
# Desc:		Creates file-list toplevels.
#
# Methods:	
# Procs:	
# Publics:
#

itcl_class dsk_FileList {
    inherit dsk_Common Toplevel

    constructor {args} {
	global tkdesk env
	
	wm withdraw $top
	dsk_busy

	frame $top.fMenu -bd 2 -relief raised
	pack $top.fMenu -fill x
	_create_menubar $top.fMenu

	# ---- Button Bar
	if {[llength $tkdesk(small_button_bar)] > 0} {
	    frame $top.fButtonBar -bd 1 -relief raised
	    pack $top.fButtonBar -after $top.fMenu -fill x
	    _create_button_bar $top.fButtonBar
	}

	# ---- Path Entry

	frame $top.fEntry -bd 1 -relief raised
	pack $top.fEntry -fill x

	entry $top.entry -bd 2 -relief sunken -width 5
	bindtags $top.entry "$top.entry Entry All"
	bind $top.entry <Double-1> "[bind Entry <Triple-1>]; break"
	bind $top.entry <Any-Enter> {
	    if $tkdesk(focus_follows_mouse) {focus %W}
	}
	bind $top.entry <Return> "
	    $this config -dir \[%W get\]
	"
	bind $top.entry <Tab> "focus $top"
	bind $top.entry <3> "update idletasks; $this _path_popup %X %Y"
	cb_bindForCompletion $top.entry <Control-Tab>
	cb_balloonHelp $top.entry {The path displayed in the current window. Change to visit another directory.  The right mouse button gives a popup menu of parent directories.}
    	blt_drag&drop target $top.entry \
			handler file "dd_handle_text $top.entry %v 1"

	pack $top.entry -in $top.fEntry -side left -fill x \
		-expand yes -padx $pad -pady $pad -ipady 2

	frame $top.fEntry.dis -width $tkdesk(pad)
	pack $top.fEntry.dis -side right
	menubutton $top.mbHist -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
		-menu $top.mbHist.menu
	pack $top.mbHist -in $top.fEntry -side right -ipadx 2 -ipady 2

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

	# --- File Listbox
	
	set lbname ::[namespace tail $top.flb]
	dsk_FileListbox $lbname -viewer $this  \
		-width $tkdesk(file_lb,minwidth) \
		-height $tkdesk(file_lb,minheight) \
		-pad $tkdesk(pad) -toplevel $top -notrivialdirs 0
	pack [$lbname getFrame] -fill both -expand yes

	# ---- create status bar
	if $statbar {
	    frame $top.fStatus -bd [expr $tkdesk(pad) > 0] -relief raised
	    pack [set f $top.fStatus] -fill x
	    label $f.l -anchor w -font [cb_font $tkdesk(font,status)]
	    pack $f.l -fill x -padx [expr $tkdesk(pad) / 2] \
		    -pady [expr $tkdesk(pad) / 2]
	}

	# ---- bindings
	bind $top <Any-Enter> \
		"set tkdesk(active_viewer) $this; break"
	bind $top <Tab> "focus $top.entry; break"

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
	bind $top <Control-p> "dsk_print; break"
	bind $top <Control-w> "dsk_openwith; break"
	bind $top <Control-Home> {dsk_cd ~; break}
	bind $top <Control-Left> {dsk_cd [list [dir_history back]]; break}
	bind $top <Control-Right> {dsk_cd [list [dir_history forward]]; break}
	bind $top <Return> "dsk_openall; break"
	bind $top <F1> "dsk_cbhelp $tkdesk(library)/doc/Guide howto"

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
	    bind $top <$l> "$this keynav $l"
	    bind $top <Shift-$l> "$this keynav $l reverse"
	}
	foreach l {A B C D E F G H I J K L M N O P Q R S T U V W X Y Z} {
	    bind $top <Key-$l> "$this keynav [string tolower $l] reverse"
	    #bind $top <Shift-$l> "$this keynav $l"
	}
	    
	update idletasks
	wm title $top "File List"
	wm minsize $top $tkdesk(file_lb,minwidth) $tkdesk(file_lb,minheight)
	set w [cb_max $tkdesk(file_lb,minwidth) \
		[expr $tkdesk(file_lb,width) - 10]]
	dsk_place_window $top flist ${w}x$tkdesk(file_lb,height) 1
	wm protocol $top WM_DELETE_WINDOW "$this close"

	if $tkdesk(fvwm) {
	    # create the icon window
	    # (this code is based upon the code posted by:
	    # kennykb@dssv01.crd.ge.com (Kevin B. Kenny))
	    toplevel $top-icon -bg [cb_col $tkdesk(color,icon)] \
		    -class Icon
	    wm withdraw $top-icon
	    label $top-icon.label \
		    -image [dsk_image $tkdesk(icon,filelist)] -bd 0 \
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
	    wm iconbitmap $top @$tkdesk(library)/images/xbm/filing_open.xbm
	}

	eval config $args
	dsk_sound dsk_new_filelist

	if {$isFileSel} {
	    #
	    # We're a file selector
	    #
	    if $statbar {
		destroy $top.fStatus
	    }
	    frame $top.fFileSel -bd [expr $tkdesk(pad) > 0] -relief raised
	    pack [set f $top.fFileSel] -fill x

	    label $f.lSel -text $fileSelLabel -anchor w
	    pack $f.lSel -fill x -padx $tkdesk(pad)
	    
	    entry $f.eSel -bd 2 -relief sunken
	    pack $f.eSel -fill x -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2

	    bindtags $f.eSel "$f.eSel Entry all"
	    bind $f.eSel <Any-Enter> {
		if $tkdesk(focus_follows_mouse) {focus %W}
	    }

	    frame $f.fButs
	    pack $f.fButs -fill x

	    button $f.bOK \
		    -command "$this _fs_ok; $this delete" \
		    -text " OK " -width 7
	    button $f.bCancel \
		    -command "$this _fs_cancel; $this delete" \
		    -text "Cancel" -width 7
	    pack $f.bOK $f.bCancel -in $f.fButs -side left -expand y \
		    -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1

	    $lbname _add_binding <ButtonRelease-1> "$this _fs_select"
	    $lbname _set_binding <Double-1> "
	       catch \{after cancel \$tkdesk(_show_tip_id)\}
               set tkdesk(file_lb,control) 0
	       set tmpsc \$tkdesk(single_click)
	       set tkdesk(single_click) 0
	       set tkdesk(config_nostat) 1
	       set tkdesk(_doubleclick) 1
	       $this _fs_ok; $this delete;
	       set tkdesk(config_nostat) 0
	       catch {set tkdesk(single_click) \$tmpsc}
	       catch {unset tmpsc}
	       break
	    "

	    wm protocol $top WM_DELETE_WINDOW \
		    "$this _fs_cancel; $this delete"
	    wm title $top $fileSelTitle
	    catch {wm transient $top [[dsk_active win] getToplevel]}
	    raise $top
	}
	
	if {!$dontmap} {
	    wm deiconify $top
	    tkwait visibility $top
	    catch "lower $top .dsk_welcome"
	    update
	}
	
	$top.entry icursor end
	$top.entry xview end
	
	pack propagate $top 0
	update

	dsk_lazy
    }

    destructor {
	global env tkdesk
	
	# add current directory to the path history:
	if {$last_directory != ""} {
	    if {[string first $env(HOME) $last_directory] == 0} {
		dir_history add [string_replace $last_directory $env(HOME) ~]
	    } else {
		dir_history add $last_directory
	    }
	}
	
	$top.flb delete
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

    method keynav {what {opt ""}} {
	set lb ::[$top.flb getLbObj]
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
	        set lbf [$lbname getFrame]
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
	$top.flb _tag_icons
    }

    method display_statbar {display} {
	global tkdesk

	catch {destroy $top.fStatus}
	if $display {
	    frame $top.fStatus -bd [expr $tkdesk(pad) > 0] -relief raised
	    pack [set f $top.fStatus] -fill x
	    label $f.l -anchor w -font [cb_font $tkdesk(font,status)]
	    pack $f.l -fill x -padx [expr $tkdesk(pad) / 2] \
		    -pady [expr $tkdesk(pad) / 2]
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
	}
    }

    method refreshdir {dir} {
	global tkdesk

	if {$dir == $directory} {
	    # $top.flb config -directory $directory
	    $top.flb refresh
	    if {$directory == "$tkdesk(trashdir)/"} {
		if $tkdesk(fvwm) {
		    if {[llength [[$top.flb getLbObj] get]] == 0} {
			$top-icon.label config \
				-image [dsk_image $tkdesk(icon,trash-empty)]
		    } else {
			$top-icon.label config \
				-image [dsk_image $tkdesk(icon,trash-full)]
		    }
		} else {
		    if {[llength [[$top.flb getLbObj] get]] == 0} {
			wm iconbitmap $top \
				@$tkdesk(library)/images/xbm/trashcan.xbm
		    } else {
			wm iconbitmap $top \
				@$tkdesk(library)/images/xbm/trashcan_full.xbm
		    }
		}
	    }
	}
    }

    method select {cmd args} {
	global tkdesk
	
	switch -glob -- $cmd {
	    get		{# return a list of all selected files
		    set sfl ""
		    set sl [[$top.flb getLbObj] select get]
		    if {$sl != ""} {
		        set fl [[$top.flb getLbObj] get]
			foreach s $sl {
			    set file [lindex [split [lindex $fl $s] \t] 0]
			    set file [string trimright $file " "]
			    #if {$file == "." || $file == ".."} continue
			    if $tkdesk(append_type_char) {
				set file [dskC_striptc $file]
			    }
			    lappend sfl "$directory$file"
			}
		    }
		    return $sfl
			}
	    clear	{# clear selection in listbox
		    [$top.flb getLbObj] select clear
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

    method _dblclick {lb sel} {
	global tkdesk
	
	if {$sel == "" || $lb == ""} {
	    return
	}
	if {$tkdesk(single_click) && [llength $sel] > 1} {
	    return
	}

	set dir [string trimright [$lb info public directory -value] "/"]
	#set file [lindex [lindex [$lb.dlb get] [lindex $sel 0]] 0]
	set file [string trimright [lindex [split \
		[lindex [[$lb getLbObj] get] \
		[lindex $sel 0]] \t] 0] " "]
	if $tkdesk(append_type_char) {
	    set file [dskC_striptc $file]
	}
	if {[string first "/" $file] == -1} {
	    set file "$dir/$file"
	}
	if {!$tkdesk(single_click) || \
		($tkdesk(single_click) && [file isdirectory $file])} {
	    ::dsk_open $this "$file"
	}
    }

    method _popup {lb sel mx my} {
	if {$sel == "" || $lb == ""} {
	    return
	}
	set dir [string trimright [$lb info public directory -value] "/"]
	#set file [lindex [lindex [$lb.dlb get] [lindex $sel 0]] 0]
	set file [string trimright [lindex [split \
		[lindex [[$lb getLbObj] get] \
		[lindex $sel 0]] \t] 0] " "]
	::dsk_popup $lb "$dir/$file" $mx $my
    }

    method _selecting {lb} {
	# do nothing
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
	}

	#dsk_debug "Rec.: $flist"
	#dsk_debug "dest: $dest"
	if {[string first "$tkdesk(trashdir)/" $dest] == -1} {
	    dsk_ddcopy $flist $dest
	} else {
	    if !$tkdesk(quick_dragndrop) {
		dsk_delete $flist
	    } else {
		if {!$tkdesk(file_lb,control) && !$tkdesk(really_delete)} {
		    dsk_ddcopy $flist $dest
		} else {
		    if {[cb_yesno "Really deleting! Are you sure that this is what you want?"] == 0} {
			dsk_sound dsk_really_deleting
			dsk_bgexec "$tkdesk(cmd,rm) $flist" \
				"Deleting [llength $flist] File(s)..."
			dsk_refresh "$flist $dest"
		    }
		}		    
	    }
	}
    }

    method _button_bar {} {
	_create_button_bar $top.fButtonBar
    }

    method _fs_select {} {
	set sel [file tail [lindex [dsk_active sel] 0]]
	if {[string length $sel] > 0} {
	    set e $top.fFileSel.eSel
	    $e delete 0 end
	    $e insert end $sel
	    $e icursor end
	    $e xview end
	}
    }

    method _fs_ok {} {
	set e $top.fFileSel.eSel
	set f [$e get]
	if {[string length $f] > 0} {
	    set fsSelFile $directory[$e get]
	} else {
	    set fsSelFile ""
	}
    }

    method _fs_cancel {} {
	set fsSelFile ""
    }

    method _configDir {} {
	# backend private proc of public var "directory"
	global tkdesk

	set err [catch {set isdir [file isdirectory $dir]}]
	if !$err {
	    if !$isdir {
		catch {set dir [_make_path_valid $dir]}
		if ![winfo exists .dsk_welcome] {
		    # don't want this during startup
		    catch {dsk_bell}
		    cb_alert "The path you specified is not completely valid."
		}
	    } elseif ![file readable $dir] {
		dsk_errbell
		cb_error "[file tail $dir]: Permission denied."
		return
	    }
	} else {
	    cb_error "Path (or user?) does not exist. Opening home directory."
	    set dir ~
	}

	if $tkdesk(menu,control) {
	    dsk_FileList .dfl[dsk_FileList :: id] -directory $dir
    	    set tkdesk(menu,control) 0
	} else {
	    $this config -directory $dir
	}
    }

    proc id {{cmd ""}} {
	if {$cmd == ""} {
	    set i $id
	    incr id
	    return $i
	} elseif {$cmd == "reset"} {
	    set id 0
	}
    }

    proc status_bar {display} {
	global tkdesk

	foreach fl [itcl_info objects -class dsk_FileList] {
	    $fl display_statbar $display
	}
	if $display {
	    dsk_status_ready
	}
	set statbar $display
    }

    proc fileSelector {args} {
	
	set fs ::.flFileSel
	catch {$fs delete}
	eval dsk_FileList $fs -isFileSel 1 $args
	set w [$fs getToplevel]
	grab $w
	set tkdesk(active_viewer) $fs
	tkwait window $w
	return $fsSelFile
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    public dontmap 0

    public dir {} {

	if [winfo exists $top] {
	    _configDir
	}
    }

    public directory {} {
	global env tkdesk

	if ![string match {[~/]*} $directory] {
	    set directory [dsk_active dir]$directory
	}
	#set directory "[string trimright [glob $directory] "/"]/"
	set directory "[string trimright [cb_tilde $directory expand] "/"]/"
	set directory [dsk_canon_path $directory]
	dsk_debug "Directory $directory"

	$top.entry delete 0 end
	$top.entry insert end [cb_tilde $directory collapse]

	# right-justify the text in the path entry:
	if {[wm state $top] != "withdrawn"} {
	    $top.entry icursor end
	    $top.entry xview end
	}

	# save position of scrollbar:
	if {$last_directory != ""} {
	    set ypos($last_directory) \
		    [lindex [cb_old_sb_get \
		    [::[$top.flb getLbObj] getFrame].sb] 2]
	}

	if {[string first "$tkdesk(trashdir)/" $directory] > -1} {
	    $top.flb config -dont_refresh 1
	    if {$directory == "$tkdesk(trashdir)/"} {
		$top.flb config -notrivialdirs 1 -showall 1
	    } else {
		$top.flb config -notrivialdirs 0 -showall 1
	    }
	    $top.flb config -dont_refresh 0
	}
	
	$top.flb config -directory $directory
	if [info exists ypos($directory)] {
	    [$top.flb getLbObj] _yview $ypos($directory)
	}

	# add this directory to the path history:
	if {$last_directory != ""} {
	    if {[string first $env(HOME) $last_directory] == 0} {
		dir_history add [string_replace $last_directory $env(HOME) ~]
	    } else {
		dir_history add $last_directory
	    }
	}
	set last_directory $directory
	
	if {[string first "$tkdesk(trashdir)/" $directory] > -1} {
	    pack forget $top.fEntry
	    wm title $top Trash
	    wm iconname $top Trash
	    if $tkdesk(fvwm) {
		if {[llength [[$top.flb getLbObj] get]] == 0} {
		    $top-icon.label config \
			    -image [dsk_image $tkdesk(icon,trash-empty)]
		} else {
		    $top-icon.label config \
			    -image [dsk_image $tkdesk(icon,trash-full)]
		}
	    } else {
		if {[llength [[$top.flb getLbObj] get]] == 0} {
		    wm iconbitmap $top @$tkdesk(library)/images/xbm/trashcan.xbm
		} else {
		    wm iconbitmap $top \
			    @$tkdesk(library)/images/xbm/trashcan_full.xbm
		}
	    }
	} else {
	    if {[wm title $top] == "Trash"} {
		$top.flb config -notrivialdirs 0
		pack $top.fEntry -fill x -after $top.fButtonBar
	    }
	    #set wt [file tail [string trimright $directory "/"]]/
	    #wm title $top $wt
	    #wm iconname $top $wt
	    set_title
	    if $tkdesk(fvwm) {
		$top-icon.label config \
			-image [dsk_image $tkdesk(icon,filelist)]
	    } else {
		wm iconbitmap $top @$tkdesk(library)/images/xbm/filing_open.xbm
	    }
	}

	if !$height_set {
	    set height_set 1
	    if {$isFileSel} {
		set off 9
	    } else {
		set off 1
	    }
	    set h [cb_max \
		    [cb_min [expr [llength [[$top.flb getLbObj] get]] + $off] \
		            $tkdesk(file_lb,height)] \
		    $tkdesk(file_lb,minheight)]
	    set w [cb_max $tkdesk(file_lb,minwidth) \
		    [expr $tkdesk(file_lb,width) - 10]]
	    wm geometry $top ${w}x$h
	}
    }

    public pad {4} {
    }
    public isFileSel 0
    public fileSelTitle "Select File"
    public fileSelLabel "Selection:"

    protected height_set 0
    protected last_directory ""
    protected ypos
    protected lbname

    common id 0
    common statbar 0
    common fsSelFile ""
}


