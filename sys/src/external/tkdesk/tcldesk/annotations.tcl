# =============================================================================
#
# File:		annotation.tcl
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
#s    proc dsk_find_annotation {}
#s    proc dsk_anno_find {}
#s    proc dsk_anno_browse {}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_find_annotation
# Args:		none
# Returns: 	""
# Desc:		Creates a window for searching an annotation.
# Side-FX:	none
#

if ![info exists tkdesk(geometry,dsk_find_annotation)] {
    set tkdesk(geometry,dsk_find_annotation) ""
}

set dsk_anno(case_sensitive) 0

proc dsk_find_annotation {} {
    global tkdesk tkdesk_anno

    set t .dsk_find_annotation
    if [winfo exists $t] {
	cb_raise $t
	return
    }

    toplevel $t
    wm withdraw $t
    frame $t.fe -bd 1 -relief raised
    pack $t.fe -fill x

    frame $t.f1
    pack $t.f1 -in $t.fe -fill x \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)
    
    frame $t.fh1
    pack $t.fh1 -in $t.f1 -fill x
    label $t.le -text "Annotation to seach for (regexp):" -anchor w
    pack $t.le -in $t.fh1 -side left
    
    checkbutton $t.cbCase -text "Case sensitive" -relief flat \
	    -variable dsk_anno(case_sensitive)
    pack $t.cbCase -in $t.fh1 -side right

    entry $t.eAnno -bd 2 -relief sunken
    pack $t.eAnno -in $t.f1 -fill x -ipady 2 \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)
    bind $t.eAnno <Return> "$t.bSearch.button invoke"

    frame $t.fb
    pack $t.fb -in $t.f1 -fill x
    
    cb_button $t.bSearch -text " Search " -default 1 -command dsk_anno_find
    pack $t.bSearch -in $t.fb -side left -padx $tkdesk(pad) -pady $tkdesk(pad)
    button $t.bBrowse -text " Browse " -command "dsk_anno_browse"
    button $t.bClose -text "  Close  " -command \
	    "set tkdesk(geometry,dsk_find_annotation) \[wm geometry $t\] ;\
	    destroy $t"
    pack $t.bBrowse $t.bClose -in $t.fb -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1

    frame $t.flb -bd 1 -relief raised
    pack $t.flb -fill both -expand yes
    frame $t.f2
    pack $t.f2 -in $t.flb -fill both -expand yes -pady $tkdesk(pad)
    
    label $t.llb -text "Matching files:" -anchor w
    pack $t.llb -in $t.f2 -anchor w -padx $tkdesk(pad) 
    
    pack [_dsk_find_lb $t.dlb] -in $t.f2 -fill both -expand yes


    bind $t <Any-Enter> "focus $t.eAnno"

    wm title $t "Find Annotation"
    wm minsize $t 10 1
    dsk_place_window $t dsk_find_annotation 24x5 1
    wm protocol $t WM_DELETE_WINDOW "$t.bClose invoke"
    wm deiconify $t
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_anno_find
# Args:		none
# Returns: 	""
# Desc:		Searches in all annotated files for the annotation in the
#               entry widget.
# Side-FX:	none
#

proc dsk_anno_find {} {
    global tkdesk_anno dsk_anno

    if ![info exists tkdesk_anno] {
	dsk_bell
	cb_info "No file has been annotated yet."
	return
    }

    dsk_busy
    set t .dsk_find_annotation
    set re [$t.eAnno get]
    if {$re != ""} {
	set mfiles ""
	foreach afile [array names tkdesk_anno] {
	    if ![file exists $afile] {
		unset tkdesk_anno($afile)
		continue
	    }
	    if !$dsk_anno(case_sensitive) {
		if [regexp -nocase $re $tkdesk_anno($afile)] {
		    lappend mfiles $afile
		}
	    } else {
		if [regexp $re $tkdesk_anno($afile)] {
		    lappend mfiles $afile
		}
	    }
	}
	#$t.lbFiles.lbox delete 0 end
	#eval $t.lbFiles.lbox insert end $mfiles
	if {$mfiles != ""} {
	    set lbl ""
	    foreach file $mfiles {
		lappend lbl [file dirname $file]/[subst \
			[lindex [dskC_ls -l -o $file] 0]]
	    }
	    $t.dlb config -list $lbl
	} else {
	    dsk_bell
	    cb_info "No match."
	}
    }
    dsk_lazy
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_anno_browse
# Args:		none
# Returns: 	""
# Desc:		Fills a text window with all file annotations.
# Side-FX:	none
#

proc dsk_anno_browse {} {
    global tkdesk_anno

    if ![info exists tkdesk_anno] {
	dsk_bell
	cb_info "No file has been annotated yet."
	return
    }

    set afiles ""
    foreach afile [array names tkdesk_anno] {
	if ![file exists $afile] {
	    unset tkdesk_anno($afile)
	    continue
	}
	append afiles "$afile:\n"
	append afiles "$tkdesk_anno($afile)\n\n"
    }

    if {$afiles != ""} {
	dsk_editor string $afiles
    } else {
	dsk_bell
	cb_info "No file has been annotated yet."
    }
}

