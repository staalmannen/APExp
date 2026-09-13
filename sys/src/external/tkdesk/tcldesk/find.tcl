# =============================================================================
#
# File:		find.tcl
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
#s    proc dsk_find_files {}
#s    proc dsk_do_find_files {}
#s    proc _dsk_find_lb {name}
#s    proc _dsk_find_dragcmd {}
#s    proc _dsk_find_lb_open {dlb shift}
#s    proc _dsk_find_lb_popup {dlb x y}
#s    proc _dsk_find_get_sel {dlb}
#s    proc find_dd_pkgcmd {dlb token}
#
# =============================================================================

# ----------------------------------------------------------------------------
# dsk_find_files:
# TkDesk's "Find Files..." dialog.
#

if ![info exists tkdesk(geometry,dsk_find_files)] {
    set tkdesk(geometry,dsk_find_files) ""
}

proc dsk_find_reset_fields {} {
    global dsk_find
    
    set dsk_find(path) ""
    set dsk_find(name) ""
    set dsk_find(string) ""
    set dsk_find(strtype) "String"
    set dsk_find(size) ""
    set dsk_find(days) ""
    set dsk_find(type) "All Types"
    set dsk_find(time) "Last Modified"
    set dsk_find(owner) ""
    set dsk_find(group) ""
    set dsk_find(samefs) 0
    set dsk_find(follow) 0
    set dsk_find(case) 0
    set dsk_find(caseFile) 1
    set dsk_find(wordRegexp) 0
    set dsk_find(doit) 0
}

dsk_find_reset_fields

proc dsk_find_files {args} {
    global tkdesk dsk_find

    if {$args != {}} {
	dsk_find_reset_fields
	set path_set [dsk_find_parse_args $args]
    } else {
	set dsk_find(doit) 0
	set path_set 0
    }

    set t .dsk_find_files
    if [winfo exists $t] {
	if !$path_set {
	    set p [dsk_active dir]
	    if {$p == "/"} {
		set dsk_find(path) "/"
	    } else {
		set dsk_find(path) [string trimright $p "/"]
	    }
	}
	cb_raise $t
	update
	if $dsk_find(doit) {
	    dsk_do_find_files
	}
	return
    }

    toplevel $t
    wm withdraw $t
    frame $t.f -bd 1 -relief raised
    pack $t.f -fill x

    # ---- Path:
    frame $t.f1
    pack $t.f1 -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    label $t.lsp -text "Path:" -width 10 -anchor w
    entry $t.esp -bd 2 -relief sunken -width 20 -textvar dsk_find(path)
    if !$path_set {
	set p [dsk_active dir]
	if {$p == "/"} {
	    set dsk_find(path) "/"
	} else {
	    set dsk_find(path) [string trimright $p "/"]
	}
    }
    bind $t.esp <Return> "$t.bSearch.button invoke"
    bind $t.esp <Escape> "$t.bClose invoke"
    bind $t.esp <Control-c> "$t.bClose invoke; break"
    blt_drag&drop target $t.esp handler file "dd_handle_text $t.esp %v 1"
    cb_bindForCompletion $t.esp <Control-Tab>
    cb_balloonHelp $t.esp "The search will start at this directory. If this field remains blank, search will start at the current directory of the last active file browser. You may specify multiple paths by separating them with a space."
    
    frame $t.fs1 -width 8
    menubutton $t.mbDir -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/slash.xbm \
		-menu $t.mbDir.menu
    cb_balloonHelp $t.mbDir "This menu contains the custom directories from the Directories menu."
    menu [set m $t.mbDir.menu] \
	    -postcommand "_dsk_dmenu $t.mbDir.menu $t.esp"
    # add dummy entry to work around bug in pre Tk 4.0p2:
    $m add command -label "dummy"

    menubutton $t.mbHist -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
		-menu $t.mbHist.menu
    cb_balloonHelp $t.mbHist "This menu contains the directories you have last visited."
    menu $t.mbHist.menu -postcommand "_dsk_hmenu $t.mbHist.menu $t.esp"
    # add dummy entry to work around bug in pre Tk 4.0p2:
    $t.mbHist.menu add command -label "dummy"

    pack $t.lsp $t.esp $t.fs1 $t.mbDir $t.mbHist -in $t.f1 -side left \
	    -pady $tkdesk(pad)
    pack config $t.esp -fill x -ipady 2 -expand yes
    pack config $t.mbDir $t.mbHist -ipadx 2 -ipady 2

    # ---- Name, String:
    frame $t.f2
    pack $t.f2 -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    label $t.ln -text "File-Masks:" -width 10 -anchor w
    entry $t.en -bd 2 -relief sunken -width 16 -textvar dsk_find(name)
    bind $t.en <Return> "$t.bSearch.button invoke"
    bind $t.en <Escape> "$t.bClose invoke"
    bind $t.en <Control-c> "$t.bClose invoke; break"
    cb_balloonHelp $t.en "Enter a shell-like glob pattern here (e.g. *.c) to search for files with a certain name. You may specify multiple masks by separating them with a space."
    frame $t.fs2 -width 8
    tk_optionMenu $t.mst dsk_find(strtype) "String" "RegExp" "ExtReg"
    $t.mst config -width 7 -anchor w
    cb_balloonHelp $t.mst "Whether to look for a set of strings (separated by ||), for a regular expression, or for an extended regular expression (see the grep manual-page for more)."
    #label $t.lst -text "String:"
    entry $t.est -bd 2 -relief sunken -width 34 -textvar dsk_find(string)
    bind $t.est <Return> "$t.bSearch.button invoke"
    bind $t.est	<Escape> "$t.bClose invoke"
    bind $t.est	<Control-c> "$t.bClose invoke; break"
    cb_balloonHelp $t.est "Enter a string or regular expression in this field if you're looking for files containing a certain string."
    pack $t.ln $t.en $t.fs2 $t.mst $t.est \
	    -in $t.f2 -side left -pady $tkdesk(pad)
    pack config $t.en -ipady 2
    pack config $t.est -fill x -ipady 2 -expand yes

    # ---- Owner, Groupd, Options:
    frame $t.f3b
    pack $t.f3b -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    label $t.lown -text "Owner:" -width 10 -anchor w
    entry $t.eown -bd 2 -relief sunken -width 16 -textvar dsk_find(owner)
    bind $t.en <Return> "$t.bSearch.button invoke"
    bind $t.en <Escape> "$t.bClose invoke"
    bind $t.en <Control-c> "$t.bClose invoke; break"
    cb_balloonHelp $t.eown "Enter a numeric or textual user ID to look for files belonging to that user."
    frame $t.fs3b -width 8
    label $t.lgrp -text "Group:" -anchor w
    entry $t.egrp -bd 2 -relief sunken -width 16 -textvar dsk_find(group)
    bind $t.egrp <Return> "$t.bSearch.button invoke"
    bind $t.egrp <Escape> "$t.bClose invoke"
    bind $t.egrp <Control-c> "$t.bClose invoke; break"
    cb_balloonHelp $t.egrp "Enter a numeric or textual group ID to look for files belonging to that group."
    frame $t.fs3b2 -width 8
    tk_optionMenu $t.mt dsk_find(type) "All Types" "Regular Files" \
	    "Directories" "Symbolic Links" "Sockets" "Named Pipes"
    $t.mt config -width 12 -anchor w
    cb_balloonHelp $t.mt "The type of files to look for."

    pack $t.lown $t.eown $t.fs3b $t.lgrp $t.egrp $t.fs3b2 $t.mt \
	    -in $t.f3b -side left -pady $tkdesk(pad)
    pack config $t.eown -ipady 2
    pack config $t.egrp -fill x -ipady 2 -expand yes
    
    # ---- Time, Type, Size:
    frame $t.f3
    pack $t.f3 -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    label $t.ls -text "Size (kB):" -width 10 -anchor w
    entry $t.es -bd 2 -relief sunken -width 16 -textvar dsk_find(size)
    bind $t.es <Return> "$t.bSearch.button invoke"
    bind $t.es <Escape> "$t.bClose invoke"
    bind $t.es <Control-c> "$t.bClose invoke; break"
    cb_balloonHelp $t.es "If the size of files is important, this either gives the exact number of kilobytes, or, if preceded with a + resp. -, files will be matched which are bigger resp. smaller than this number. E.g. +100 will match all files which are bigger than 100 kB."
    frame $t.fs3 -width 8
    tk_optionMenu $t.mtm  dsk_find(time) "Last Accessed" "Last Modified"
    $t.mtm config -width 13 -anchor w
    cb_balloonHelp $t.mtm "This setting relates to the entry field right to this menu button. The value entered there can either relate to when the file was last accessed or last modified."
    entry $t.etm -bd 2 -relief sunken -width 5 -textvar dsk_find(days)
    cb_balloonHelp $t.etm "10 will match files which are 10 days old, +10 will match all files older than 10 days, and -10 all newer than 10 days. Leave this field blank if this is not important for your search."
    bind $t.etm <Return> "$t.bSearch.button invoke"
    bind $t.etm	<Escape> "$t.bClose invoke"
    bind $t.etm	<Control-c> "$t.bClose invoke; break"
    frame $t.fs32 -width 8
    menubutton $t.mbOpts -text "Options..." -menu [set m $t.mbOpts.m] \
	    -padx 4 -relief raised -bd 2
    cb_balloonHelp $t.mbOpts "This is a menubutton giving access to several options related to the find operation."
    menu $m
    $m add checkbutton -label "Case Sensitive" \
	    -variable dsk_find(case)
    $m add checkbutton -label "Whole words" \
	    -variable dsk_find(wordRegexp)
    $m add checkbutton -label "File-Mask Case Sensitive" \
	    -variable dsk_find(caseFile)
    $m add separator
    $m add checkbutton -label "Same Filesystem" -variable dsk_find(samefs)
    $m add checkbutton -label "Follow Symbolic Links" \
	    -variable dsk_find(follow)

    pack $t.ls $t.es $t.fs3 $t.mtm $t.etm $t.fs32 \
	    -in $t.f3 -side left -pady $tkdesk(pad)
    pack config $t.es -ipady 2
    pack config $t.etm -fill x -ipady 2 -expand yes
    pack $t.mbOpts -in $t.f3 -side right -padx $tkdesk(pad) -pady $tkdesk(pad)

    # ---- Buttons:
    frame $t.f4
    pack $t.f4 -in $t.f -fill x -expand yes -padx $tkdesk(pad)
    
    frame $t.f4sep -height 6
    pack $t.f4sep -in $t.f4 -fill x

    cb_button $t.bSearch -text " Search " -default 1 \
	    -command dsk_do_find_files
    cb_balloonHelp $t.bSearch.button "Starts the search. The search will be carried out in the background."
    button $t.bClose -text "  Close  " -command \
	    "set tkdesk(geometry,dsk_find_files) \[wm geometry $t\] ;\
	    destroy $t; catch \{destroy $t-icon\}"
    cb_balloonHelp $t.bClose "Closes this dialog."
    
    pack $t.bSearch $t.bClose -in $t.f4 -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack config $t.bClose -ipady 1

    # ---- dsk_Listbox:
    frame $t.flb -bd 1 -relief raised
    pack $t.flb -fill both -expand yes
    frame $t.f5
    pack $t.f5 -in $t.flb -fill both -expand yes -pady $tkdesk(pad)
    
    label $t.llb -text "Matching files:" -anchor w
    pack $t.llb -in $t.f5 -anchor w -padx $tkdesk(pad) 
    
    pack [_dsk_find_lb $t.dlb] -in $t.f5 -fill both -expand yes

    wm title $t "Find Files"
    wm minsize $t 10 2
    dsk_place_window $t dsk_find_files 10x5 1
    wm protocol $t WM_DELETE_WINDOW "$t.bClose invoke"
    
    if $tkdesk(fvwm) {
	# create the icon window
	# (this code is based on the code posted by:
	# kennykb@dssv01.crd.ge.com (Kevin B. Kenny))
	toplevel $t-icon -bg [cb_col $tkdesk(color,icon)] \
		-class Icon
	wm withdraw $t-icon
	label $t-icon.label \
		-image [dsk_image $tkdesk(icon,find)] -bd 0 \
		-bg [cb_col $tkdesk(color,icon)]
	pack $t-icon.label -ipadx 2 -ipady 2
	#blt_drag&drop target $t-icon.label handler \
	#	file "$t _dd_drophandler"
	update idletasks
	wm geometry $t-icon \
		[winfo reqwidth $t-icon]x[winfo reqheight $t-icon]
	wm protocol $t-icon WM_DELETE_WINDOW "$t.bClose invoke"
	wm iconwindow $t $t-icon
    } else {
	wm iconbitmap $t @$tkdesk(library)/images/xbm/magnify_hand.xbm
    }
	
    update
    pack propagate $t 0
    wm deiconify $t

    if $dsk_find(doit) {
	dsk_do_find_files
    }
}

# ----------------------------------------------------------------------------
# dsk_find_parse_args:
# Parses the arguments passed to the dsk_find_files proc.
# Returns 1 if the path is set, 0 if it_s not.
#
proc dsk_find_parse_args {args} {
    global dsk_find

    if {$args == {}} {
	return
    }

    if {[llength $args] == 1} {
	set args [lindex $args 0]
    }

    set path_set 0
    for {set i 0} {$i < [llength $args]} {incr i} {
	switch -glob -- [lindex $args $i] {
	    -path {
		incr i
		set dsk_find(path) [lindex $args $i]
		set path_set 1
	    }
	    -name -
	    -mask {
		incr i
		set dsk_find(name) [lindex $args $i]
	    }
	    -string {
		incr i
		set dsk_find(string) [lindex $args $i]
		set dsk_find(strtype) "String"
	    }
	    -regexp {
		incr i
		set dsk_find(string) [lindex $args $i]
		set dsk_find(strtype) "RegExp"
	    }
	    -extreg {
		incr i
		set dsk_find(string) [lindex $args $i]
		set dsk_find(strtype) "ExtReg"
	    }
	    -type {
		incr i
		switch -glob [lindex $args $i] {
		    all {
			set dsk_find(type) "All Types"
		    }
		    fil* {
			set dsk_find(type) "Regular Files"
		    }
		    dir* {
			set dsk_find(type) "Directories"
		    }
		    sym* {
			set dsk_find(type) "Symbolic Links"
		    }
		    sock* {
			set dsk_find(type) "Sockets"
		    }
		    name* -
		    pipe* {
			set dsk_find(type) "Named Pipes"
		    }
		}
	    }
	    -user -
	    -own* {
		incr i
		set dsk_find(owner) [lindex $args $i]
	    }
	    -grp -
	    -group {
		incr i
		set dsk_find(group) [lindex $args $i]
	    }
	    -mod* {
		incr i
		set dsk_find(days) [lindex $args $i]
		set dsk_find(time) "Last Modified"
	    }
	    -acc* {
		incr i
		set dsk_find(days) [lindex $args $i]
		set dsk_find(time) "Last Accessed"
	    }
	    -size {
		incr i
		set dsk_find(size) [lindex $args $i]
	    }
	    -case* {
		set dsk_find(case) 1
	    }
	    -word* {
		set dsk_find(wordRegexp) 1
	    }
	    -same* {
		set dsk_find(samefs) 1
	    }
	    -follow* {
		set dsk_find(follow) 1
	    }
	    -doit {
		set dsk_find(doit) 1
	    }
	}
    }

    return $path_set
}

# ----------------------------------------------------------------------------
# dsk_do_find_files:
# Executes "find" with the parameters set thhrough the dialog.
#
proc dsk_do_find_files {} {
    global tkdesk dsk_find

    set cmd "find "
    
    if {$dsk_find(path) != ""} {
	foreach path $dsk_find(path) {
	    append cmd " \"[cb_tilde [string trimright $path /]/ expand]\""
	}
    } else {
	set path [dsk_active dir]
	if {$path == "/"} {
	    append cmd " /"
	} else {
	    append cmd " \"[cb_tilde [string trimright $path /] expand]\""
	}
    }

    switch $dsk_find(type) {
	"Regular Files" {
	    append cmd " -type f"
	}
	"Directories" {
	    append cmd " -type d"
	}
	"Symbolic Links" {
	    append cmd " -type l"
	}
	"Sockets" {
	    append cmd " -type s"
	}
	"Named Pipes" {
	    append cmd " -type p"
	}
    }
    
    if {$dsk_find(name) != ""} {
	if {[llength $dsk_find(name)] > 1} {
	    append cmd " \\( "
	    set do_or 0
	    foreach n $dsk_find(name) {
		if {!$dsk_find(caseFile)} {
		    set n2 ""
		    for {set i 0} {$i < [string length $n]} {incr i} {
			set c [string tolower [string index $n $i]]
			set uc [string toupper $c]
			if {$c != $uc} {
			    append n2 "\[$uc$c\]"
			} else {
			    append n2 $c
			}
		    }
		    set n $n2
		}
		if $do_or {
		    append cmd " -o -name \"$n\""
		} else {
		    append cmd " -name \"$n\""
		}
		set do_or 1
	    }
	    append cmd " \\) "
	} else {
	    set n $dsk_find(name)
	    if {!$dsk_find(caseFile)} {
		set n2 ""
		for {set i 0} {$i < [string length $n]} {incr i} {
		    set c [string tolower [string index $n $i]]
		    set uc [string toupper $c]
		    if {$c != $uc} {
			append n2 "\[$uc$c\]"
		    } else {
			append n2 $c
		    }
		}
		set n $n2
	    }
	    append cmd " -name \"[string trim $n \"]\""
	}
    }
    if {$dsk_find(size) != ""} {
	set rc [string index $dsk_find(size) 0]
	if {$rc != "+" && $rc != "-"} {
	    set rc ""
	}
	set num [string trimleft $dsk_find(size) "+-"]
	# 2 * $num, because -size argument is in blocks (512 bytes)
	if {[string length $num] > 0} {
	    append cmd " -size $rc[expr 2 * $num]"
	}
    }
    if {$dsk_find(days) != ""} {
	if {$dsk_find(time) == "Last Accessed"} {
	    append cmd " -atime $dsk_find(days)"
	} else {
	    append cmd " -mtime $dsk_find(days)"
	}
    }
    if {$dsk_find(owner) != ""} {
	append cmd " -user \"$dsk_find(owner)\""
    }
    if {$dsk_find(group) != ""} {
	append cmd " -group \"$dsk_find(group)\""
    }
    if $dsk_find(samefs) {
	if [regexp -nocase "irix" [exec uname]] {
	    append cmd " -local"
	} else {
	    append cmd " -xdev"
	}
    }
    if $dsk_find(follow) {
	append cmd " -follow"
    }
    
    if {$dsk_find(string) != ""} {
	set str $dsk_find(string)
	switch $dsk_find(strtype) {
	    "String" {
		set grep "fgrep"
		set str [string_replace $dsk_find(string) "||" "\n"]
	    }
	    "RegExp" {
		set grep "grep"
	    }
	    "ExtReg" {
		set grep "egrep -e"
	    }
	}
	if $dsk_find(wordRegexp) {
	    append grep " -w"
	}
	set str [dskC_esc $str { \"[]{}$;}]
	if $dsk_find(case) {
	    append cmd " -exec $grep -l \"$str\" \\\{\\\} \\\;"
	} else {
	    append cmd " -exec $grep -i -l \"$str\" \\\{\\\} \\\;"
	}
    } else {
	append cmd " -print"
    }

    set cmd [string_replace $cmd \[ \\\[]
    set cmd [string_replace $cmd \] \\\]]
    append cmd " 2>/dev/null"
    if $tkdesk(debug) {
	catch {puts stderr "$cmd"}
    }

    set t .dsk_find_files
    $t.dlb config -list {}
    $t.llb config -text "Looking for matches..."

    # perform search (may take a long time)
    #dsk_busy $t
    $t.bSearch.button config -state disabled
    $t.bClose config -state disabled
    
    set dsk_find(lbl) ""
    set matches [split [dsk_bgexec $cmd "Searching matches..." \
	    -onoutput _find_update] "\n"]
    dsk_debug $matches

    # OK, done with searching
    if {$matches != "break" || $dsk_find(lbl) != ""} {
	if {$matches != "break"} {
	    set ml [lsort $matches]
	    set abstr ""
	} else {
	    set ml [lsort $dsk_find(lbl)]
	    set abstr "(search was abandoned)"
	    dsk_debug $ml
	}
	set ll [llength $ml]

	wm deiconify $t
	raise $t
	if {$ll == 1} {
	    $t.llb config -text "Found 1 matching file: $abstr"
	} elseif {$ll == 0} {
	    $t.llb config -text "No matches found."
	} else {
	    $t.llb config -text "Found $ll matching files: $abstr"
	}
	set lbl ""
	set mbl ""
	foreach file $ml {
	    if [file exists $file] {
		lappend lbl [file dirname $file]/[subst \
			[lindex [dskC_ls -l -o $file] 0]]
		eval lappend lbl $mbl
		set mbl ""
	    } else {
		lappend mbl "      $file"
	    }
	}
	$t.dlb config -list $lbl
    } else {
	catch {$t.llb config -text "Search abandoned."}
    }
    
    #dsk_lazy $t
    $t.bSearch.button config -state normal
    $t.bClose config -state normal
}

proc _find_update {data} {
    global dsk_find

    # Warning: $data may hold multiple file names separated by newlines!
    eval lappend dsk_find(lbl) [split $data \n]
    
    #set file $data
    #[file dirname $file]/[subst [lindex [dskC_ls -l -o $file] 0]]
    .dsk_find_files.dlb config -list $dsk_find(lbl)
}


# ----------------------------------------------------------------------------
# dsk_find_lb name:
# Creates a dsk_Listbox for the find dialogs with name $name.
#
proc _dsk_find_lb {name} {
    global tkdesk

    catch {$name delete}
    
    dsk_Listbox $name -width 10 -height 2 \
	    -font [cb_font $tkdesk(font,file_lbs)] \
	    -bg [cb_col $tkdesk(color,filelb)]
    set frame [$name getFrame]
    $frame config -relief flat
    $frame.text config -tabs {465 right 480 left 575 left  635 left 695 \
	    left 775 left 795 left}
    
    bind $frame.text <Any-Double-1> "_dsk_find_lb_open $name %s"
    bind $frame.text <3> "[bind $frame.text <1>];\
	    _dsk_find_lb_popup $name %X %Y"

    blt_drag&drop source $frame.text  \
	    -button 2 -packagecmd "find_dd_pkgcmd $name %t" \
	    -rejectfg red -selftarget 0 -send {file text} \
	    -tokenanchor nw \
	    -tokencursor "@$tkdesk(library)/images/xbm/hand.xbm \
	    $tkdesk(library)/images/xbm/hand.mask.xbm \
	    [cb_col $tkdesk(color,foreground)] $tkdesk(color,drag)"

    blt_drag&drop source $frame.text handler file

    bind $frame.text <Shift-Button-2> "[bind Text <Button-2>]"
    bind $frame.text <Shift-B2-Motion> "[bind Text <B2-Motion>]"
    bind $frame.text <ButtonPress-2> "
        $name _sel_for_dd @%x,%y
        $name _dd_start %X %Y
        blt_drag&drop drag %W %X %Y
    "
    
    bind $frame.text <Control-ButtonPress-2> \
	    "[bind $frame.text <ButtonPress-2>]"
    
    bind $frame.text <Control-B2-Motion> \
	    "set tkdesk(file_lb,control) 1 ;\
	    _dsk_find_dragcmd"
    
    bind $frame.text <Control-ButtonRelease-2> \
	    "set tkdesk(file_lb,control) 1 ;\
 	     blt_drag&drop drop %W %X %Y ;\
             dsk_desktop_drop %X %Y \[_dsk_find_get_sel $name\]
             focus -force .
    "

    bind $frame.text <ButtonRelease-2> "
    set tkdesk(file_lb,control) 0
    blt_drag&drop drop %W %X %Y ;\
    dsk_desktop_drop %X %Y \[_dsk_find_get_sel $name\]
    focus -force .
    "

    bind $frame.text <B2-Motion> \
	    "set tkdesk(file_lb,control) 0;\
	    _dsk_find_dragcmd"

    bind $frame.text <B2-KeyRelease-Control_L> \
	    "set tkdesk(file_lb,control) 0; \
	    _dsk_find_dragcmd"
    
    bind $frame.text <B2-KeyPress-Control_L> \
	    "set tkdesk(file_lb,control) 1; \
	    _dsk_find_dragcmd"
    
    return $frame
}

proc _dsk_find_dragcmd {} {
    global tkdesk

    set token $tkdesk(dd_token_window)
    if $tkdesk(quick_dragndrop) {
	if $tkdesk(file_lb,control) {
	    $token.label config -text "Copying:"		
	} else {
	    $token.label config -text "Moving:"
	}
	update idletasks
    }
}
    
# binding for double click:
proc _dsk_find_lb_open {dlb shift} {
    global tkdesk dsk_find
    
    set tkdesk(file_lb,control) [expr $shift & 4]
    set sel [$dlb select get]
    if {$sel != ""} {
	set tmpfile [lindex [split [lindex [$dlb get] $sel] \t] 0]
	set tmpfile [string trimright $tmpfile " "]
	if {$tmpfile != ""} {
	    set tkdesk(editor,findexp) $dsk_find(string)
	    if {$dsk_find(strtype) == "String"} {
		set tkdesk(editor,findisreg) 0
	    } else {
		set tkdesk(editor,findisreg) 1
	    }
	    dsk_open $tkdesk(active_viewer) $tmpfile
	    set tkdesk(editor,findexp) ""
	}
    }
}

# binding for right click:
proc _dsk_find_lb_popup {dlb x y} {
    global tkdesk dsk_find
    
    set sel [$dlb select get]
    if {$sel != ""} {
	set tmpfile [lindex [split [lindex [$dlb get] $sel] \t] 0]
	set tmpfile [string trimright $tmpfile " "]
	if {$tmpfile != ""} {
	    set tkdesk(editor,findexp) $dsk_find(string)
	    if {$dsk_find(strtype) == "Strings:"} {
		set tkdesk(editor,findisreg) 0
	    } else {
		set tkdesk(editor,findisreg) 1
	    }
	    dsk_popup $dlb $tmpfile $x $y dir
	    set tkdesk(editor,findexp) ""
	}
    }
}

# binding for right click:
proc _dsk_find_get_sel {dlb} {

    set files ""
    set sel [$dlb select get]
    if {$sel != ""} {
	foreach s $sel {
	    set tmpfile [lindex [split [lindex [$dlb get] $s] \t] 0]
	    set tmpfile [string trimright $tmpfile " "]
	    if {$tmpfile != ""} {
		lappend files $tmpfile
	    }
	}
    }
    return $files
}

# package cmd for find's d&d:
proc find_dd_pkgcmd {dlb token} {
    global tkdesk

    set tkdesk(dd_token_window) $token
    set fl [$dlb select get]
    set flist ""
    set list [$dlb get]
    foreach f $fl {
	lappend flist [lindex [split [lindex $list $f] \t] 0]
    }

    set nfiles 0
    set ndirs 0
    foreach file $flist {
        if [file isdirectory $file] {
    	incr ndirs
        } else {
    	incr nfiles
        }
    }

    catch "destroy $token.label"	
    catch "destroy $token.lFiles"
    catch "destroy $token.lDirs"
    if $tkdesk(quick_dragndrop) {
	set f [cb_font $tkdesk(font,labels)]
	catch {
	    set f [join [lreplace [split $f -] 7 7 10] -]
	    set f [join [lreplace [split $f -] 3 3 medium] -]
	}
        label $token.label -text "Moving:" -font [cb_font $f]
        pack $token.label
    }
    if {$ndirs > 0} {
        if {$ndirs == 1} {
        	label $token.lDirs -text "  1 Directory "
        } else {
        	label $token.lDirs -text "  $ndirs Directories "
        }
        pack $token.lDirs -anchor w
    }
    if {$nfiles > 0} {
        if {$nfiles == 1} {
        	label $token.lFiles -text "  1 File "
        } else {
        	label $token.lFiles -text "  $nfiles Files "
        }
        pack $token.lFiles -anchor w
    }

    catch "wm deiconify $token"
    #update
    return [list $flist]
}

