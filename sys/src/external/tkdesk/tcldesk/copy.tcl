# =============================================================================
#
# File:		copy.tcl
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
#s    proc dsk_copy {{files ""} {dest ""}}
#s    proc dsk_copy_dest_popup {entry x y}
#s    proc dsk_copy_action {cmd}
#s    proc _dsk_hmenu {menu entry}
#s    proc _dsk_dmenu {menu entry}
#s    proc dsk_ddcopy {files dest}
#
# -----------------------------------------------------------------------------

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_copy
# Args:		files		(opt.) list of files to copy, move etc.
#		dest		(opt.) destination directory
# Returns: 	""
# Desc:		Creates a window for copying, moving and linking the selected
#		files or $files (opt. to $dest).
# Side-FX:	Rereads the concerned file listboxes.
#

if ![info exists tkdesk(geometry,dsk_copy)] {
    set tkdesk(geometry,dsk_copy) ""
}

global dsk_copy
set dsk_copy(num_cas_dirs) 0	;# number of cascaded dir menus
set dsk_copy(flist) ""		;# initial file list for dsk_copy
set dsk_copy(fcnt) 0		;# counter: that many files have been processed
set dsk_copy(fmax) 0		;# number of files to process - 1
set dsk_copy(ldest) ""		;# last destination

global dsk_copy_other
set dsk_copy_other ""

proc dsk_copy {{files ""} {dest ""}} {
    global tkdesk dsk_copy dsk_copy_other

    if {$files == ""} {
    	set files [dsk_active sel]
    }

    set dsk_copy(fcnt) 0
    set dsk_copy(fmax) [expr [llength $files] - 1]
    set dsk_copy(flist) $files
    set dsk_copy(all) $tkdesk(all_files)

    set t .dsk_copy
    if [winfo exists $t] {
	destroy $t
    }

    toplevel $t

    # ---- Source Files

    frame $t.ff -bd 1 -relief raised
    pack $t.ff -fill both -expand yes

    frame $t.fff
    pack $t.fff -in $t.ff -fill both -expand yes \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

    entry $t.eFile -width 40 -bd 2 -relief sunken
    pack $t.eFile -in $t.fff -side bottom -fill x -expand yes -ipady 2
    $t.eFile insert end [lindex $dsk_copy(flist) 0]
    $t.eFile icursor end
    $t.eFile xview end
    bind $t.eFile <Tab> "focus $t.eDest"
    bind $t.eFile <Return> {set dummy x ; unset dummy}
    bind $t.eFile <3> {dsk_popup %W [%W get] %X %Y}
    cb_bindForCompletion $t.eFile <Control-Tab>

    blt_drag&drop target $t.eFile handler file "dd_handle_text $t.eFile %v 1"

    label $t.lFile
    if {$files == ""} {
	$t.lFile config -text "File (no files selected):"
    } else {
	$t.lFile config \
      -text "File ([expr $dsk_copy(fcnt) + 1] of [expr $dsk_copy(fmax) + 1]):"
    }
    pack $t.lFile -in $t.fff -side left

    if {$dsk_copy(fmax) > 0} {
    	checkbutton $t.cbAll -text "all selected files" \
		-padx $tkdesk(pad) -relief flat -variable dsk_copy(all)
    	pack $t.cbAll -in $t.fff -side right
    }

    # ---- Destination

    frame $t.fd -bd 1 -relief raised
    pack $t.fd -fill both -expand yes

    frame $t.fdf
    pack $t.fdf -in $t.fd -fill both -expand yes \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

    entry $t.eDest -width 40 -bd 2 -relief sunken
    pack $t.eDest -in $t.fdf -side bottom -fill x -expand yes -ipady 2
    if {$dest == ""} {
    	$t.eDest insert end $dsk_copy(ldest)
    } else {
    	$t.eDest insert end $dest
    }
    $t.eDest icursor end
    $t.eDest xview end
    bind $t.eDest <3> {dsk_copy_dest_popup %W %X %Y}
    bind $t.eDest <Tab> "focus $t.eFile"
    bind $t.eDest <Return> "dsk_copy_action copy"
    cb_bindForCompletion $t.eDest <Control-Tab>

    blt_drag&drop target $t.eDest handler file "dd_handle_text $t.eDest %v 1"

    label $t.lDest -text "Destination:"
    pack $t.lDest -in $t.fdf -side left

    frame $t.fdlm
    pack $t.fdlm -in $t.fdf -side right

    menubutton $t.mbDir -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/slash.xbm \
		-menu $t.mbDir.menu
    pack $t.mbDir -in $t.fdlm -side left -ipadx 2 -ipady 2

    menu [set m $t.mbDir.menu] \
	    -postcommand "_dsk_dmenu $t.mbDir.menu $t.eDest"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$m add command -label "dummy"

    menubutton $t.mbHist -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
		-menu $t.mbHist.menu
    pack $t.mbHist -in $t.fdlm -side left -ipadx 2 -ipady 2

    menu $t.mbHist.menu -postcommand "_dsk_hmenu $t.mbHist.menu $t.eDest"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$t.mbHist.menu add command -label "dummy"

    # ---- Buttons

    frame $t.fb -bd 1 -relief raised
    pack $t.fb -fill x

    cb_button $t.bCopy -text " Copy " -command "dsk_copy_action copy" \
	    -default 1
    cb_button $t.bMove -text " Move " -command "dsk_copy_action move"
    #button $t.bLink -text " Link " -command "dsk_copy_action link"
    #button $t.bSymLink -text " SymLink " -command "dsk_copy_action symlink"
    
    cb_button $t.bOther -textvar dsk_copy_other \
	    -command "dsk_copy_action other"

    menubutton $t.mbOther -text " Other... " -menu [set m $t.mbOther.m] \
	    -bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
	    -bd 2 -relief raised 
    menu $m
    foreach me $tkdesk(fileops,popup) {
	if {$me == "-"} {
	    $m add separator
	} else {
	    set l [lindex $me 0]
	    set c [lindex $me 1]
	    $m add command -label $l -command "set dsk_copy_other [list $l]"
	    if {$dsk_copy_other == ""} {
		set dsk_copy_other $l
	    }
	}
    }

    cb_button $t.bCancel -text " Cancel " -command  {
		set dsk_copy(ldest) [.dsk_copy.eDest get]
		set tkdesk(geometry,dsk_copy) [wm geometry .dsk_copy]
		destroy .dsk_copy }
    pack $t.bCancel -in $t.fb -side right \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1
		
    if {$dsk_copy(fmax) > 0} {
	button $t.bSkip -text " Skip " -command "dsk_copy_action skip"
	pack $t.bSkip -in $t.fb -side right \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1
    }

    #pack $t.bCopy $t.bMove $t.bLink $t.bSymLink
    pack $t.bCopy $t.bMove $t.bOther \
	    -in $t.fb -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1
    pack $t.mbOther -in $t.fb -side left -ipadx 3 -ipady 3

    #bind $t <Any-Enter> "+focus $t.eFile"
    #focus $t.eFile
    bind $t.eFile <Escape> "$t.bCancel.button invoke"
    bind $t.eDest <Escape> "$t.bCancel.button invoke"

    wm minsize $t 486 167
    wm title $t "Copy, Move, Link Files"
    wm protocol $t WM_DELETE_WINDOW {.dsk_copy.bCancel.button invoke}
    
    dsk_place_window $t dsk_copy 486x162
    focus -force $t.eFile
}


proc dsk_copy_dest_popup {entry x y} {
    global tkdesk
    
    set dest [$entry get]
    if {![file isdirectory $dest]} {
	set dest [_make_path_valid $dest /]
    }
    if [file isdirectory $dest] {
	set this .dsk_copy
	set m $this-ppop
	catch {destroy $m}
	menu $m
	bind $m <ButtonRelease-3> "
		set tkdesk(menu,control) 0
		[bind Menu <ButtonRelease-3>]"
	bind $m <Control-ButtonRelease-3> "
		set tkdesk(menu,control) 1
		[bind Menu <ButtonRelease-3>]"
	
	set p [cb_tilde [string trimright $dest "/"] collapse]
	if {$p != ""} {
	    set op $p
	    while {1} {
		set p [file dirname $p]
		$m add command -label $p -command \
			"$entry delete 0 end; $entry insert end \[list $p\]" \
			-font [cb_font $tkdesk(font,file_lbs)]
		if {$p == "/"} break
	    }
	    $m add separator
	    set p $op
	    set i 0
	    while {1} {
		set p [file dirname $p]
		set cm $m.cas$i
		$m add cascade -label $p -menu $cm -font [cb_font $tkdesk(font,file_lbs)]
		catch {destroy $cm}
		menu $cm -postcommand "dsk_casdirs $p $cm 1 \
			\{$entry delete 0 end; $entry insert end \[list %d\]\}"
		incr i
		if {$p == "/"} break
	    }
	    update
	    tk_popup $m $x $y
	}
    } else {
	dsk_errbell
    }
}


proc dsk_copy_action {cmd} {
    global dsk_copy tkdesk tkdesk_anno dsk_copy_other

    dsk_debug "dsk_copy_action $cmd"

    set t .dsk_copy
    #cd [$tkdesk(active_viewer) curdir]

    set tlist ""
    if $dsk_copy(all) {
	if [winfo exists $t.eFile] {
	    set tlist [list [$t.eFile get]]
	    if {$dsk_copy(fcnt) < $dsk_copy(fmax)} {
		set tlist [concat $tlist [lrange $dsk_copy(flist) \
			[expr $dsk_copy(fcnt) + 1] $dsk_copy(fmax)]]
	    }
	} else {
	    set tlist [lrange $dsk_copy(flist) $dsk_copy(fcnt) $dsk_copy(fmax)]
	}
    }
    if {($tlist == "" || !$dsk_copy(all)) && [winfo exists $t.eFile]} {
	set tlist [list [$t.eFile get]]
	set err [catch {set tlist [glob $tlist]}]
	if $err {
	    set tlist [list [$t.eFile get]]
	}
    }
    if {$tlist == ""} {
	dsk_bell
	cb_info "Nothing to $cmd!"
	return
    }
    set anum [llength $tlist]
    dsk_debug " anum = $anum"

    set alist ""
    foreach f $tlist {
	catch {set f [cb_tilde $f expand]}
	if {[string index $f 0] != "/" && ![regexp {:/} $f]} {
	    set f [dsk_active dir]$f
	}
	set err [catch {set fl [glob [_make_fname_safe $f]]}]
	if !$err {
	    foreach fe $fl {
		lappend alist $fe
	    }
	} elseif {[regexp {:/} $f]} {
	    lappend alist $f
	} else {
	    dsk_errbell
	    cb_error "$f: no match!"
	}
    }
    if {$alist == ""} {
	return
    }

    set dest [$t.eDest get]
    if {$dest == "" && $cmd != "skip"} {
	cb_info "Please fill in the destination first!"
	return
    }
    catch {set dest [cb_tilde $dest expand]}
    if {[string index $dest 0] != "/"} {
	set dest [dsk_active dir]$dest
    }

    dsk_debug " alist = \{$alist\}"
    if [dsk_on_rofs $dest] {
	dsk_errbell
	cb_error "The target filesystem is mounted read-only."
	return
    }
    
    # check permissions:
    if {$dest != "/"} {
	set dest [string trimright $dest "/"]
    }
    if {![file writable $dest] && [file exists $dest]} {
	if  {$cmd != "other"} {
	    if [file isdirectory $dest] {
		cb_error "$dest:\ndirectory not writable."
	    } else {
		cb_error "[file tail $dest]:\nfile not writable."
	    }
	    return
	} else {
	    if [file isdirectory $dest] {
		set ret [cb_yesno "$dest:\ndirectory not writable.\nContinue anyway?"]
	    } else {
		set ret [cb_yesno "[file tail $dest]:\nfile not writable.\nContinue anyway?"]
	    }
	    if {$ret == 1} return
	}
    }
    foreach file $alist {
	if {$cmd == "move"} {
	    if ![dsk_check_perm $file] {
		cb_error "[file tail $file]:\nYou don't have permission to move this item."
		return
	    }
	} elseif {$cmd == "copy"} {
	    if {![file readable $file] && ![regexp {:/} $file]} {
		cb_error "[file tail $file]:\nnot readable."
		return
	    }
	}
    }

    # check for existing files in destination dir:
    if {[file exists $dest] && !$tkdesk(overwrite_always) && $cmd != "skip" \
	&& $cmd != "other"} {
	if ![file isdirectory $dest] {
	    if {[cb_dialog $t-ED "File exists" "$dest already exists!" \
			questhead 0 "Overwrite" "  Skip  "] == 1} {
	   	set cmd skip
	    }
	} elseif {[llength $alist] == 1} {
	    if {$cmd == "move"} {
		if [dsk_on_rofs $alist] {
		    # all files in $alist live on the same file system
		    dsk_errbell
		    cb_error "The source filesystem is mounted read-only."
		    return
		}
	    }
	    set dfile [string trimright $dest /]/[file tail $alist]
	    if [file exists $dfile] {
	    	if {[cb_dialog $t-ED "File exists" "$dfile already exists!" \
			questhead 0 "Overwrite" "  Skip  "] == 1} {
	    	    set cmd skip
	    	}
	    }
	} else {
	    # "all selected files" has been selected
	    set tlist $alist
	    set dir [string trimright $dest /]
	    set rofs_checked 0
	    foreach file $tlist {
		if {$cmd == "move" && !$rofs_checked} {
		    if [dsk_on_rofs $file] {
			# all files in $alist live on the same file system
			dsk_errbell
			cb_error "The source filesystem is mounted read-only."
			return
		    }
		    set rofs_checked 1
		}
		set dfile $dir/[file tail $file]
		if [file exists $dfile] {
		    set ret [cb_dialog $t-ED "File exists" \
				"$dfile already exists!" questhead 0 \
				"Overwrite" "Overwrite all" \
				"  Skip  " " Cancel "]
		    switch $ret {
			1 {
			    break
			}
			2 {
			    set i [lsearch $alist $file]
			    if {$i > -1} {
				set alist [lreplace $alist $i $i]
			    } else {
				cb_error "?? Couldn't find $file !?"
			    }
			}
			3 {
			    catch {$t.bCancel.button invoke}
			    return
			}
		    }
		}
	    }
	    if {$alist == ""} {
		catch {$t.bCancel.button invoke}
		return
	    }
	    set anum [llength $alist]
	}
    }

    if $dsk_copy(all) {
	catch {$t.bCancel.button invoke}
    }
    if {$anum > 1} {set fll items} {set fll item}
    dsk_debug " Files: $anum"
    switch $cmd {
	skip {
	    if $dsk_copy(all) return
	    incr dsk_copy(fcnt)
	    $t.lFile config -text "File ([expr $dsk_copy(fcnt) + 1] of [expr $dsk_copy(fmax) + 1]):"
	    if {$dsk_copy(fcnt) > $dsk_copy(fmax)} {
		catch {$t.bCancel.button invoke}
		return
	    }
	    $t.eFile delete 0 end
	    $t.eFile insert end [lindex $dsk_copy(flist) $dsk_copy(fcnt)]
	    $t.eFile icursor end
	    $t.eFile xview end
	    return
	}
	copy {
	    #dsk_busy
	    dsk_sound dsk_copying
	    set out [dsk_bgexec "$tkdesk(cmd,cp) $alist \"$dest\"" \
			"Copying $anum $fll..."]
	    #dsk_lazy
	}
	move {
	    #dsk_busy
	    dsk_sound dsk_moving
	    if ![file isdirectory $alist] {
	    	set out [dsk_bgexec "$tkdesk(cmd,mv) $alist \"$dest\"" \
			"Moving $anum $fll..."]
	    } else {
		# try to hide different file systems from user:
		file stat [lindex $alist 0] s1
		set s2(dev) 0
		catch "file stat $dest s2"
		if !$s2(dev) {
		    catch {file stat [file dirname $dest] s2}
		}
		if {$s1(dev) == $s2(dev) || !$s2(dev) \
		    || ([llength $alist] == 1 \
		    && ![file isdirectory [lindex $alist 0]])} {
	    	    set out [dsk_bgexec "$tkdesk(cmd,mv) $alist \"$dest\"" \
				"Moving $anum $fll..."]
		} else {
	    	    set out [dsk_bgexec "$tkdesk(cmd,cp) $alist $dest" \
				"Move: Copying $anum $fll..."]
		    if {$out != "error" && $out != "break"} {
	    	    	set out [dsk_bgexec "$tkdesk(cmd,rm) $alist" \
				"Move: Deleting $anum $fll..."]
		    }
		}
	    }
	    #dsk_lazy
	}
	other {
	    #dsk_busy
	    set c ""
	    foreach e $tkdesk(fileops,popup) {
		if {[lindex $e 0] == $dsk_copy_other} {
		    set c [subst -nocommands [lindex $e 1]]
		    break
		}
	    }
	    set err [catch {eval [_expand_pc $c \
		    [lindex $alist 0] $alist $dest]} errmsg]
	    if $err {
		dsk_errbell
		cb_error $errmsg
		set out error
	    } else {
		set out ok
	    }
	    #dsk_lazy
	}
	link {
	    #dsk_busy
	    dsk_sound dsk_linking
	    set out [dsk_bgexec "$tkdesk(cmd,ln) $alist \"$dest\"" \
			"Linking $anum $fll..."]
	    #dsk_lazy
	}
	symlink {
	    #dsk_busy
	    dsk_sound dsk_symlinking
	    set out [dsk_bgexec "$tkdesk(cmd,symln) $alist \"$dest\"" \
			"Linking $anum $fll symbolically..."]
	    #dsk_lazy
	}
	untar {
	    #dsk_busy
	    set f $alist ;# this can only be just one file
	    if {[string match "*.tar.gz" $f] || \
		    [string match "*.tgz" $f] || \
		    [string match "*.taz" $f] || \
		    [string match "*.tar.Z" $f]} {
		dsk_sound dsk_untaring
		set out [dsk_bgexec "gzip -cd $f | tar xf - -C \"$dest\"" \
			"Untaring [file tail $f]..."]
	    } elseif {[string match "*.tar" $f]} {
		dsk_sound dsk_untaring
		set out [dsk_bgexec "tar xf $f -C \"$dest\"" \
			"Untaring [file tail $f]..."]
	    } else {
		dsk_errbell
		cb_error "This file doesn't look like a tar file."
	    }
	    #dsk_lazy
	}
	default {
	    cb_error "dsk_copy_action: unknown cmd ($cmd)"
	    return
	}
    }

    if {$out != "error"} {
	# copy annotations and adjust desk items:
	set dest [string trimright $dest "/"]
	foreach f $alist {
	    if [info exists tkdesk_anno($f)] {
		if [file isdirectory $dest] {
		    set tkdesk_anno($dest/[file tail $f]) $tkdesk_anno($f)
		} else {
		    set tkdesk_anno($dest) $tkdesk_anno($f)
		}
		if {$cmd == "move"} {
		    unset tkdesk_anno($f)
		}
	    }
	    if {$cmd == "move"} {
		if [file isdirectory $dest] {
		    dsk_DeskItem :: move $f $dest/[file tail $f]
		} else {
		    dsk_DeskItem :: move $f $dest
		}
	    }
	}
	if {$cmd == "move"} {
	    dsk_refresh "$alist $dest"
	} else {
	    dsk_refresh "$dest"
	}
	if !$dsk_copy(all) {
	    incr dsk_copy(fcnt)
	    if {$dsk_copy(fcnt) > $dsk_copy(fmax)} {
		catch {$t.bCancel.button invoke}
		return
	    }
	    $t.eFile delete 0 end
	    $t.eFile insert end [lindex $dsk_copy(flist) $dsk_copy(fcnt)]
	    $t.eFile icursor end
	    $t.eFile xview end
	}	    
    }
}

proc _dsk_hmenu {menu entry} {
    global tkdesk

    catch "$menu delete 0 last"
    if $tkdesk(sort_history) {
	set l [lsort [dir_history get]]
    } else {
	set l [dir_history get]
    }
    set ne 0
    foreach dir $l {
	$menu add command -label $dir \
		-command "$entry delete 0 end;\
		$entry insert end \[list $dir\]" \
		-font [cb_font $tkdesk(font,entries)]
	incr ne
	if {$ne > $tkdesk(_max_menu_entries)} {
	    set om $menu
	    $menu add cascade -label "More..." \
		    -menu [set menu $menu.c$ne]
	    catch {destroy $menu}; menu $menu; set ne 0
	    foreach b [bind $om] {bind $menu $b [bind $om $b]}
	}
    }
}

proc _dsk_dmenu {menu entry} {
    global tkdesk _dsk_dmenu

    catch "$menu delete 0 last"
    set _dsk_dmenu(num_cas_dirs) 0
    if [info exists tkdesk(directories)] {
	foreach mdir $tkdesk(directories) {
	    if {$mdir == "-"} {
		$menu add separator
	    } else {
		_dsk_add_dir_to_menu $menu $mdir $entry
	    }
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_ddcopy
# Args:		files - list of files
#               dest - destination path
# Returns: 	""
# Desc:		Is called when files have been dropped onto a file listbox.
#               If quick_dragndrop is set, the files are copied or moved
#               (in case the Control-Key was pressed) without asking.
#               Else dsk_copy gets called with the arguments of dsk_ddcopy.
# Side-FX:	none
#

proc dsk_ddcopy {files dest} {
    global tkdesk

    set anum [llength $files]
    if {$anum == 1} {
	set fll "Item"
    } else {
	set fll "Items"
    }

    if {[string first "$tkdesk(configdir)/.shelf/" $dest] > -1} {
	set out [dsk_bgexec "$tkdesk(cmd,symln) $files $dest" \
		"Linking $anum $fll symbolically..."]
	dsk_refresh $dest
	return
    }	

    if !$tkdesk(quick_dragndrop) {
	dsk_copy $files $dest
	return
    } else {
	if {[llength $files] == 1} {
	    if {[file dirname $files] == [string trimright $dest /] || \
		$files == [string trimright $dest /]} {
		# avoid copying of files to themselves 
		return
	    }
	}
	
	set dir [string trimright $dest /]
	set rofs_checked 0
	foreach file $files {
	    if {!$tkdesk(file_lb,control) && !$rofs_checked} {
		if [dsk_on_rofs $file] {
		    # all files in $alist live on the same file system
		    dsk_errbell
		    cb_error "The source filesystem is mounted read-only."
		    return
		}
		set rofs_checked 1
	    }
	    set dfile $dir/[file tail $file]
	    if [file exists $dfile] {
		set ret [cb_dialog .ddcopy-ED "File exists" \
			"$dfile already exists!" questhead 0 \
			"Overwrite" "Overwrite all" "  Skip  "]
		if {$ret == 1} {
		    break
		} elseif {$ret == 2} {
		    set i [lsearch $files $file]
		    if {$i > -1} {
			set files [lreplace $files $i $i]
		    } else {
			cb_error "?? Couldn't find $file !?"
		    }
		}
	    }
	}
	if {$files == ""} {
	    return
	}

	if $tkdesk(file_lb,control) {
	    # copy files
	    dsk_sound dsk_copying
	    set out [dsk_bgexec "$tkdesk(cmd,cp) $files $dest" \
		    "Copying $anum $fll..."]
	} else {
	    # move files
	    # try to hide different file systems from user:
	    dsk_sound dsk_moving
	    file stat [lindex $files 0] s1
	    set s2(dev) 0
	    catch "file stat $dest s2"
	    if {$s1(dev) == $s2(dev) || !$s2(dev) \
		|| ([llength $files] == 1 \
		&& ![file isdirectory [lindex $files 0]]) } {
		set out [dsk_bgexec "$tkdesk(cmd,mv) $files $dest" \
			"Moving $anum $fll..."]
	    } else {
		set out [dsk_bgexec "$tkdesk(cmd,cp) $files $dest" \
			"Move: Copying $anum $fll..."]
		if {$out != "error" && $out != "break"} {
		    set out [dsk_bgexec "$tkdesk(cmd,rm) $files" \
			    "Move: Deleting $anum $fll..."]
		}
	    }
	}
	if {$out != "error"} {
	    if !$tkdesk(file_lb,control) {
		dsk_refresh "$files $dest"
	    } else {
		dsk_refresh "$dest"
	    }
	}
    }
}

