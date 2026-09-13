# =============================================================================
#
# File:		HistEntry.tcl
# Project:	TkDesk
#
# Started:	28.01.97
# Changed:	28.01.97
# Author:	cb
#
#
# Copyright (C) 1997  Christian Bolik
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
#s    itcl_class dsk_HistEntry
#s    method config {config}
#s    method ok_pressed {}
#s    method add_pressed {}
#s    method histmenu {}
#s    proc id {}
#
# -----------------------------------------------------------------------------

#
# =============================================================================
#
# Class:	dsk_HistEntry
# Desc:		Creates a dialog window with a text entry field plus
#               attached history.
#
# Methods:	
# Procs:	
# Publics:
#

itcl_class dsk_HistEntry {
    inherit Toplevel

    constructor {config} {
	global tkdesk [set this]

	if {$tkdesk(tcl_version) < 8.0} {
	    Toplevel::constructor
	}
	
	wm withdraw $top

	frame $top.f -bd 1 -relief raised
	pack $top.f -fill both -expand yes

	frame $top.fl
	pack $top.fl -in $top.f -fill x

	label $top.label -text $label
	pack $top.label -in $top.fl -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	set [set this](cbvar) $checkvalue
	if {$checklabel != ""} {
	    checkbutton $top.cbBrowser -text $checklabel \
		    -variable [set this](cbvar)
	    pack $top.cbBrowser -in $top.fl -side right \
		    -padx $tkdesk(pad) -pady $tkdesk(pad)
	}

	frame $top.fe
	pack $top.fe -in $top.f -fill both -expand yes

	entry $top.entry -width 40 -bd 2 -relief sunken \
		-exportselection no
	set sel ""
	if {$entrydefault != ""} {
	    $top.entry insert end $entrydefault
	    $top.entry icursor end
	    $top.entry xview end
	} elseif {$history != "" && $sel == ""} {
	    $top.entry insert end [$history last]
	    $top.entry icursor end
	    $top.entry xview end
	}
	
	pack $top.entry -in $top.fe -fill x -expand yes -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2
	
	bind $top.entry <Visibility> {%W selection range 0 end}
	bind $top.entry <Return> "$top.bOK.button invoke"
	bind $top.entry <Escape> "$top.bCancel.button invoke"
	bind $top.entry <Control-c> "$top.bCancel.button invoke; break"
	bind $top.entry <Menu> "$this _entry_popup"
	bind $top.entry <3> "$this _entry_popup"
	
	cb_bindForCompletion $top.entry <Control-Tab>
	blt_drag&drop target $top.entry handler file \
		"dd_handle_text $top.entry %v 1"

	if {$history != ""} {
	    menubutton $top.mbHist -bd 2 -relief raised \
		    -bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
		    -menu $top.mbHist.menu
	    pack $top.mbHist -in $top.fe -side right \
		    -padx $tkdesk(pad) -pady $tkdesk(pad) -ipadx 2 -ipady 2

	    menu $top.mbHist.menu -postcommand "$this histmenu"
	    # add dummy entry to work around bug in pre Tk 4.0p2:
	    $top.mbHist.menu add command -label "dummy"
	    $history changed
	}

	frame $top.fb -bd 1 -relief raised
	pack $top.fb -fill x

	cb_button $top.bOK -text "   OK   " \
		-underline 3 -default 1 -command "
	    set tkdesk(geometry,hist_entry) \[wm geometry $top\]
	    set [set this](entry) \[$top.entry get\]
	    destroy $top
	    update idletasks
	    $this ok_pressed
	"

	cb_button $top.bApply -text " Apply " \
		-underline 1 -command "
	    set [set this](entry) \[$top.entry get\]
	    $this ok_pressed 0
	"
	if $noapply {
	    $top.bApply.button config -state disabled
	}

	if {$addbutton != ""} {
	    set i 0
	    while {[string index $addbutton $i] == " "} {incr i}
	    set sc [string index $addbutton $i]
	    cb_button $top.bAdd -text $addbutton \
		    -underline $i -command "
	    set tkdesk(geometry,hist_entry) \[wm geometry $top\]
	    set [set this](entry) \[$top.entry get\]
	    destroy $top
	    update idletasks
	    $this add_pressed
	    "
	    cb_addShortcutBinding $top.entry $top.bAdd.button "$sc"
	}

	cb_button $top.bCancel -text " Cancel " \
		-underline 1 -command "
	    set tkdesk(geometry,hist_entry) \[wm geometry $top\]
	    $this delete
	"

	pack $top.bOK $top.bApply -in $top.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	if {$addbutton != ""} {
	    pack $top.bAdd -in $top.fb -side left \
		    -padx $tkdesk(pad) -pady $tkdesk(pad)
	}
	
	pack $top.bCancel -in $top.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	cb_addShortcutBinding $top.entry $top.bOK.button "o"
	cb_addShortcutBinding $top.entry $top.bCancel.button "c"
	if !$noapply {
	    cb_addShortcutBinding $top.entry $top.bApply.button "a"
	}
	bind $top <Any-Enter> "focus $top.entry"

	wm minsize $top 348 117
	if {$title == ""} {
	    set title $label
	}
	wm title $top $title
	wm protocol $top WM_DELETE_WINDOW "$top.bCancel.button invoke"

	if ![info exists tkdesk(geometry,hist_menu)] {
	    set tkdesk(geometry,hist_menu) ""
	}
	dsk_place_window $top hist_entry "" 0 1
	wm deiconify $top

	if !$nograb {
	    grab $top
	    set old_focus [focus]
	    focus -force $top.entry
	    tkwait window $top
	    catch {focus -force $old_focus}
	}
    }

    destructor {
        #after 10 rename $this-top {}		;# delete this name
        #catch {destroy $this}		;# destroy associated window
    }

    #
    # ----- Methods and Procs -------------------------------------------------
    #

    method config {config} {
    }

    method ok_pressed {{delete 1}} {
	global [set this]

	if {$callback != ""} {
	    eval $callback \
		    [list [set [set this](entry)]] [set [set this](cbvar)]
	}
	if $delete {
	    delete
	}
    }

    method add_pressed {} {
	global [set this]

	if {$addcallback != ""} {
	    eval $addcallback \
		    [list [set [set this](entry)]] [set [set this](cbvar)]
	}
	delete
    }

    method histmenu {} {
	global tkdesk

	catch "$top.mbHist.menu delete 0 last"
	if $tkdesk(sort_history) {
	    set l [lsort [$history get]]
	} else {
	    set l [$history get]
	}
	set ne 0
	set menu $top.mbHist.menu
	foreach ent $l {
	    $menu add command -label $ent \
		    -command "$top.entry delete 0 end ;\
		    $top.entry insert end [list $ent]" \
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

    method _entry_popup {} {
	if {$entrypopupproc != ""} {
	    $entrypopupproc $top.entry
	}
    }

    proc id {} {
	set i $id
	incr id
	return $i
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    common id              0

    public label           "dummy"
    public title           ""
    public checklabel      ""
    public checkvalue      0
    public entrydefault    ""
    public entrypopupproc  ""
    public history         ""
    public callback        ""
    public addbutton       ""
    public addcallback     ""
    public nograb          0
    public noapply         0
}

