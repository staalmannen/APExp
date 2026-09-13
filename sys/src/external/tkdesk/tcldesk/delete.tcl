# =============================================================================
#
# File:		delete.tcl
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
#s    proc dsk_delete {{files ""}}
#s    proc dsk_delete_action {cmd}
#s    proc dsk_empty_trash {}
#
# -----------------------------------------------------------------------------

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_delete
# Args:		files		(opt.) list of files
# Returns: 	""
# Desc:		Deletes the selected files or $files.
# Side-FX:	none
#

if ![info exists tkdesk(geometry,dsk_delete)] {
    set tkdesk(geometry,dsk_delete) ""
}

global dsk_delete
set dsk_delete(flist) ""	;# initial file list for dsk_copy
set dsk_delete(fcnt) 0		;# counter: that many files have been processed
set dsk_delete(fmax) 0		;# number of files to process - 1
set dsk_delete(really) 0	;# REALLY delete?

proc dsk_delete {{files ""}} {
    global tkdesk dsk_delete

    if {$files == ""} {
    	set files [dsk_active sel]
    }

    set dsk_delete(fcnt) 0
    set dsk_delete(fmax) [expr [llength $files] - 1]
    set dsk_delete(flist) $files
    set dsk_delete(all) $tkdesk(all_files)
    set dsk_delete(really) $tkdesk(really_delete)

    if {[string first "$tkdesk(trashdir)" [lindex $files 0]] > -1} {
	set dsk_delete(really) 1
    }

    if !$tkdesk(ask_on_delete) {
	if {!$dsk_delete(really) && $dsk_delete(flist) != ""} {
	    dsk_delete_action delete
	    return
	}
    }

    set t .dsk_delete
    if [winfo exists $t] {
	destroy $t
    }

    toplevel $t

    # ---- File Box

    frame $t.ff -bd 1 -relief raised
    pack $t.ff -fill both -expand yes

    frame $t.fff
    pack $t.fff -in $t.ff -fill both -expand yes \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

    entry $t.eFile -width 40 -bd 2 -relief sunken
    pack $t.eFile -in $t.fff -side bottom -fill x -expand yes -ipady 2
    $t.eFile insert end [lindex $dsk_delete(flist) 0]
    $t.eFile icursor end
    $t.eFile xview end
    bind $t.eFile <Return> "$t.bDelete invoke"
    bind $t.eFile <3> {dsk_popup %W [%W get] %X %Y}
    cb_bindForCompletion $t.eFile <Control-Tab>

    blt_drag&drop target $t.eFile handler file "dd_handle_text $t.eFile %v 1"

    label $t.lFile
    if {$files == ""} {
	$t.lFile config -text "File (no files selected):"
    } else {
	$t.lFile config \
  -text "File ([expr $dsk_delete(fcnt) + 1] of [expr $dsk_delete(fmax) + 1]):"
    }
    pack $t.lFile -in $t.fff -side left

    if {$dsk_delete(fmax) > 0} {
    	checkbutton $t.cbAll -text "all selected files" \
		-padx $tkdesk(pad) -relief flat -variable dsk_delete(all)
    	pack $t.cbAll -in $t.fff -side right
    }

    # ---- Buttons

    frame $t.fb -bd 1 -relief raised
    pack $t.fb -fill x

    button $t.bDelete -text "  Delete  " -command "dsk_delete_action delete"
    checkbutton $t.cbReally -text "Delete permanently" \
		-padx $tkdesk(pad) -relief flat -variable dsk_delete(really)
    button $t.bSkip -text "  Skip  " -command "dsk_delete_action skip"
    if {$dsk_delete(fmax) < 1} {
	$t.bSkip config -state disabled
    }
    button $t.bCancel -text " Cancel " -command  {
		set tkdesk(geometry,dsk_delete) [wm geometry .dsk_delete]
		destroy .dsk_delete }

    pack $t.bCancel $t.bSkip \
		-in $t.fb -side right \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1

    pack $t.bDelete $t.cbReally \
		-in $t.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1

    #bind $t <Any-Enter> "+focus $t.eFile"
    
    wm minsize $t 326 100
    wm title $t "Delete Files"
    wm protocol $t WM_DELETE_WINDOW {.dsk_delete.bCancel invoke}

    dsk_place_window $t dsk_delete 470x98
    focus -force $t.eFile
}

proc dsk_delete_action {cmd} {
    global dsk_delete tkdesk

    set t .dsk_delete
    #cd [$tkdesk(active_viewer) curdir]

    set alist ""
    if $dsk_delete(all) {
	if [winfo exists $t.eFile] {
	    set alist [list [$t.eFile get]]
	    if {$dsk_delete(fcnt) < $dsk_delete(fmax)} {
		set alist [concat $alist [lrange $dsk_delete(flist) \
			[expr $dsk_delete(fcnt) + 1] $dsk_delete(fmax)]]
	    }
	} else {
	    set alist [lrange $dsk_delete(flist) \
		    $dsk_delete(fcnt) $dsk_delete(fmax)]
	}
    }
    if {($alist == "" || !$dsk_delete(all)) && [winfo exists $t.eFile]} {
	set alist [$t.eFile get]
	if {$alist != ""} {
	    set alist [list $alist]
	    set err [catch {set alist [glob $alist]}]
	    if $err {
		set alist [list [$t.eFile get]]
	    }
	}
    }
    dsk_debug "dsk_delete_action: alist: $alist"
    if {$alist == "" || $alist == "{}" } {
	dsk_bell
	cb_info "Nothing to $cmd!"
	return
    }

    set tmplist ""
    foreach f $alist {
	catch {set f [cb_tilde $f expand]}
	if {[string index $f 0] != "/"} {
	    set f [dsk_active dir]$f
	}
	set err [catch {set fl [glob [_make_fname_safe $f]]}]
	if !$err {
	    foreach fe $fl {
		lappend tmplist $fe
	    }
	} else {
	    # check for a broken symbolic link
	    set err [catch {file readlink [_make_fname_safe $f]}]
	    if $err {
		dsk_errbell
		cb_error "$f: no match!"
	    } else {
		lappend tmplist $f
	    }
	}
	dsk_debug "tmplist: $tmplist"
    }
    if {$tmplist == ""} {
	return
    }
    set alist $tmplist
    set anum [llength $alist]

    set dest $tkdesk(trashdir)
    # make sure trashdir really exists
    if ![file exists $tkdesk(trashdir)] {
	exec $tkdesk(cmd,mkdir) $tkdesk(trashdir)
    }

    if $dsk_delete(all) {
	catch {$t.bCancel invoke}
    }

    if {$anum > 1} {set fll items} {set fll item}
    switch $cmd {
	skip {
	    if $dsk_delete(all) return
	    incr dsk_delete(fcnt)
	    $t.lFile config -text "File ([expr $dsk_delete(fcnt) + 1] of [expr $dsk_delete(fmax) + 1]):"
	    if {$dsk_delete(fcnt) > $dsk_delete(fmax)} {
		catch {$t.bCancel invoke}
		return
	    }
	    $t.eFile delete 0 end
	    $t.eFile insert end [lindex $dsk_delete(flist) $dsk_delete(fcnt)]
	    $t.eFile icursor end
	    $t.eFile xview end
	    return
	}
	delete {
	    #dsk_busy
	    foreach file $alist {
		if ![dsk_check_perm $file] {
		    dsk_errbell
		    set rc [cb_dialog $t-ED "Permission denied" \
		    "[file tail $file]:\nYou don't have permission to delete this item." \
			    error 0 " OK " "Cancel"]
		    if {$rc == 1} {
			return
		    } else {
			set i [lsearch $alist $file]
			set alist [lreplace $alist $i $i]
		    }
		}
	    }
	    if {$alist == ""} {
		return
	    }
	    if $dsk_delete(really) {
		dsk_sound dsk_really_deleting
	    	set out [dsk_bgexec "$tkdesk(cmd,rm) $alist" \
			"Deleting $anum $fll..."]
	    } else {
		
		set dir [string trimright $dest /]
		set rofs_checked 0
		foreach file $alist {
		    if !$rofs_checked {
			if [dsk_on_rofs $file] {
			    # all files in $alist live on the same file system
			    dsk_errbell
			    cb_error "The filesystem is mounted read-only."
			    return
			}
			set rofs_checked 1
		    }
		    set dfile $dir/[file tail $file]
		    if [file exists $dfile] {
			set ret [cb_dialog $t-ED "File exists" \
				"There already is a file \"[file tail $file]\" in the trash can!" questhead 0 \
				"Overwrite" "Overwrite all" "  Skip  "]
			if {$ret == 1} {
			    break
			} elseif {$ret == 2} {
			    set i [lsearch $alist $file]
			    if {$i > -1} {
				set alist [lreplace $alist $i $i]
			    } else {
				cb_error "?? Couldn't find $file !?"
			    }
			}
		    }
		}
		if {$alist == ""} {
		    return
		}
		set anum [llength $alist]

		# try to hide different file systems from user:
		file stat $dest s2
		set one 1
		foreach file $alist {
		    set s1(dev) $s2(dev)
		    catch {file stat $file s1}
		    set t file
		    catch {set t [file type $file]}
		    if {$s1(dev) != $s2(dev) && $t != "file"} {
			set one 0
			break
		    }
		}

		if $one {
	    	    set out [dsk_bgexec "$tkdesk(cmd,mv) $alist $dest" \
				"Moving $anum $fll to the trash can..."]
		} else {
	    	    set out [dsk_bgexec "$tkdesk(cmd,cp) $alist $dest" \
				"Copying $anum $fll to the trash can..."]
		    if {$out != "error" && $out != "break"} {
	    	    	set out [dsk_bgexec "$tkdesk(cmd,rm) $alist" \
				"Deleting $anum $fll..."]
		    }
		}

	    }
	    #dsk_lazy
	}
	default {
	    cb_error "dsk_delete_action: unknown cmd ($cmd)"
	    return
	}
    }

    if {$out != "error"} {
	if $dsk_delete(really) {
	    dsk_refresh "$alist"
	} else {
	    dsk_refresh "$alist $dest"
	}
	foreach f $alist {
	    dsk_DeskItem :: remove $f
	}
	if ![winfo exists $t] return
	if !$dsk_delete(all) {
	    incr dsk_delete(fcnt)
	    if {$dsk_delete(fcnt) > $dsk_delete(fmax)} {
		catch {$t.bCancel invoke}
		return
	    }
	    $t.eFile delete 0 end
	    $t.eFile insert end [lindex $dsk_delete(flist) $dsk_delete(fcnt)]
	    $t.eFile icursor end
	    $t.eFile xview end
	}	    
    }
}

# ----------------------------------------------------------------------------
# dsk_empty_trash:
# Empties the trash can.
#
proc dsk_empty_trash {} {
    global tkdesk

    set alist [dskC_ls -p -a $tkdesk(trashdir)]
    set anum [llength $alist]
    if {$anum == 0} {
	cb_info "The trash can is empty."
    } else {
	if {[cb_okcancel "Empty trash can?\nThis will delete ALL files in the trash can!"] == 0} {
	    dsk_sound dsk_really_deleting
	    if {$anum == 1} {set fll "File"} {set fll "Files"}
	    set tlist ""
	    foreach f $alist {
	    	 lappend tlist [string trimright \
	    		 $tkdesk(trashdir)/$f " "]
	    }
	    dsk_bgexec "$tkdesk(cmd,rm) $tlist" "Deleting $anum $fll..."
	    dsk_refresh $tkdesk(trashdir)
	}
    }
}
