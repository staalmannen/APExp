# =============================================================================
#
# File:		FileInfo.tcl
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
#s    itcl_class dsk_FileInfo
#s    method config {config}
#s    method touch {}
#s    method chown {}
#s    method chgrp {}
#s    method chmod {num}
#s    proc id {}
#s    proc dsk_fileinfo {args}
#
# -----------------------------------------------------------------------------

#
# =============================================================================
#
# Class:	dsk_FileInfo
# Desc:		Implements a class for file information windows.
#
# Methods:	
# Procs:	
# Publics:
#

itcl_class dsk_FileInfo {
    inherit Toplevel

    constructor {args} {
	global tkdesk

	if {$tkdesk(tcl_version) < 8.0} {
	    Toplevel::constructor
	}
	
	wm withdraw $top

	frame $top.fl -bd 1 -relief raised
	pack $top.fl -fill x

	set f [cb_font $tkdesk(font,labels)]
	catch {set f [join [lreplace [split $f -] 7 7 18] -]}
	label $top.label -text "$file" -font [cb_font $f]
	pack $top.label -in $top.fl -side top \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	frame $top.fi -bd 1 -relief raised
	pack $top.fi -fill x

	frame $top.f1
	pack $top.f1 -in $top.fi -side left -fill x -anchor n \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	label $top.lPath -text "Path....:" -font [cb_font $tkdesk(font,mono)]
	label $top.lSize -text "Size....:" -font [cb_font $tkdesk(font,mono)]
	label $top.lLink -text "Links...:" -font [cb_font $tkdesk(font,mono)]
	label $top.lMod  -text "Modified:" -font [cb_font $tkdesk(font,mono)]
	label $top.lOwn  -text "Owner...:" -font [cb_font $tkdesk(font,mono)]
	label $top.lGrp  -text "Group...:" -font [cb_font $tkdesk(font,mono)]
	label $top.lMode -text "Mode....:" -font [cb_font $tkdesk(font,mono)]
	label $top.lType -text "Type....:" -font [cb_font $tkdesk(font,mono)]

	pack $top.lPath $top.lSize $top.lMod $top.lOwn \
		$top.lGrp $top.lMode $top.lLink $top.lType \
		-in $top.f1 -side top

	frame $top.f2
	pack $top.f2 -in $top.fi -side left -fill x \
		-padx $tkdesk(pad) -pady $tkdesk(pad)

	label $top.lrPath -text "" -font [cb_font $tkdesk(font,mono)]
	label $top.lrSize -text "" -font [cb_font $tkdesk(font,mono)]
	label $top.lrLink -text "" -font [cb_font $tkdesk(font,mono)] -height 1
	button $top.bMod -text "" -font [cb_font $tkdesk(font,mono)] \
		-command "$this touch" \
		-padx 1 -pady 1 -highlightthickness 0
	button $top.bOwn -text "" -font [cb_font $tkdesk(font,mono)] \
		-command "$this chown" \
		-padx 1 -pady 1 -highlightthickness 0
	button $top.bGrp -text "" -font [cb_font $tkdesk(font,mono)] \
		-command "$this chgrp" \
		-padx 1 -pady 1 -highlightthickness 0
	message $top.mMagic -text "" -anchor w \
		-width 200 -font [cb_font $tkdesk(font,file_lbs)] 

	frame $top.fmod
	for {set i 1} {$i < 10} {incr i} {
	    button $top.bm($i) -width 2 -font [cb_font $tkdesk(font,mono)] \
		-command "$this chmod $i" \
		-padx 1 -pady 1 -highlightthickness 0
	    # additional button bindings -- added by jdblair, 5.feb.97
	    bind $top.bm($i) <Button-1> "$this chmod $i; break"
	    bind $top.bm($i) <Button-2> "$this chmod $i Button-2"
	    bind $top.bm($i) <Button-3> "$this chmod $i Button-3"
	    pack $top.bm($i) -in $top.fmod -side left

	    if {$i == 3 || $i == 6} {
		pack [frame $top.fm($i) -width 8] -in $top.fmod -side left
	    }
	}

	pack $top.lrPath $top.lrSize $top.bMod $top.bOwn \
		$top.bGrp $top.fmod $top.lrLink $top.mMagic \
		-in $top.f2 -side top -anchor w

	frame $top.fa -bd 1 -relief raised
	pack $top.fa -fill both -expand yes

	frame $top.fa1
	pack $top.fa1 -in $top.fa -fill both -expand yes -pady $tkdesk(pad)

	label $top.lComment -text "Annotation:" -anchor w
	pack $top.lComment -in $top.fa1 -fill x -expand no -anchor w \
		-padx $tkdesk(pad)
	
	cb_text $top.ft -vscroll 1 -lborder 1 -pad $tkdesk(pad) \
		-width 36 -height 6 \
		-wrap word -setgrid 1
	pack $top.ft -in $top.fa1 -fill both -expand yes

	frame $top.fb -bd 1 -relief raised
	pack $top.fb -fill x

	button $top.bClose -text " Close " -command "$this close"
	button $top.bChmod -text " Change Mode " -state disabled \
		-command "$this chmod set"

	pack $top.bClose $top.bChmod -in $top.fb -side left \
		-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1

	bind $top <Any-Enter> "focus $top.ft.text"

	wm title $top "File Information"
	wm protocol $top WM_DELETE_WINDOW "$this close"

	eval config $args
    }

    destructor {
    }

    #
    # ----- Methods and Procs -------------------------------------------------
    #

    method close {} {
	global tkdesk_anno
	
	set anno [string trimright [$top.ft.text get 1.0 end] \n]
	if {$anno != ""} {
	    set tkdesk_anno($file) $anno
	    dsk_refresh $file
	} elseif [info exists tkdesk_anno($file)] {
	    unset tkdesk_anno($file)
	    dsk_refresh $file
	}

	if {[info tclversion] >= 8.0} {
	    $this delete
	} else {
	    wm withdraw $top
	    dsk_FileInfo::cache add $this
	}
    }

    method config {config} {
    }

    method touch {} {
	if {![file owned $file] && ![dsk_is_superuser]} {
	    dsk_errbell
	    cb_error "Sorry, you're not the owner of [file tail $file]!"
	    return
	}

	if {[cb_okcancel "Touch [file tail $file]?"] == 0} {
	    set err [catch {exec touch $file} errmsg]
	    if $err {
		cb_error $errmsg
	    } else {
		$this config -file $file
	    }
	}
    }

    method chown {} {
	global o

	set as_root 0
	if {![file owned $file] && ![dsk_is_superuser]} {
	    set ret [cb_yesno \
		    "You're not the owner of [file tail $file].  Try as root?"]
	    if {$ret == 0} {
		set as_root 1
	    } else {
		return
	    }
	}

	set o $owner
	cb_readString "Change owner of [file tail $file] to:" o "Change Owner"
	if {$o != ""} {
	    if {!$as_root} {
		set err [catch {exec chown $o $file} errmsg]
		if $err {
		    cb_error $errmsg
		} else {
		    $this config -file $file
		}
	    } else {
		dsk_exec_as_root chown $o $file
		$this config -file $file
	    }
	}
    }

    method chgrp {} {
	global g

	set as_root 0
	if {![file owned $file] && ![dsk_is_superuser]} {
	    set ret [cb_yesno \
		    "You're not the owner of [file tail $file].  Try as root?"]
	    if {$ret == 0} {
		set as_root 1
	    } else {
		return
	    }
	}

	set g $group
	cb_readString "Change group of [file tail $file] to:" g "Change Group"
	if {$g != ""} {
	    if {!$as_root} {
		set err [catch {exec chgrp $g $file} errmsg]
		if $err {
		    cb_error $errmsg
		} else {
		    $this config -file $file
		}
	    } else {
		dsk_exec_as_root chgrp $g $file
		$this config -file $file
	    }
	}
    }

    method chmod {num {event Button-1}} {
	# num is: user r/w/x: 1/2/3, group r/w/x: 4/5/6, world r/w/x: 7/8/9,
	# 	  or "set"
	# fmode contains the current mode string

	if {![file owned $file] && ![dsk_is_superuser]} {
	    dsk_errbell
	    cb_error "Sorry, you're not the owner of [file tail $file]!"
	    return
	}
	if [dsk_on_rofs $file] {
	    dsk_errbell
	    cb_error "Read-only file system.  Can't change permissions, sorry."
	    return
	}

	$top.bChmod config -state normal

	for {set i 0} {$i < 10} {incr i} {
	    set m($i) [string index $fmode $i]
	}

	# modified by jdblair to deal with different button events
	# button 1: normal
	# button 2: all -- set this state in all ownership classes
	# button 3: leap -- toggle execute on or off, ignoring s, S, t, T.
	if {$event == "Button-2"} {
	    switch -- $m($num) {
		"r" -
		"w" -
		"x" -
		"-" {
		    set cycle [expr $num % 3]
		    if {$cycle == 0} {set cycle 3}
		    for {set i $cycle} {$i < 10} {incr i 3} {
			set m($i) $m($num)
			$top.bm($i) config -text $m($num)
	    }
		}
	    }
	} else {
	    switch $num {
		1	-
		4	-
		7   {
		    if {$m($num) == "r"} {
			set m($num) "-"
		    } else {
			set m($num) "r"
		    }
	        }
		2	-
		5	-
		8   {
		    if {$m($num) == "w"} {
			set m($num) "-"
		    } else {
			set m($num) "w"
		    }
		}
		3	-
		6	{
		    if {$event == "Button-3"} {
			if {$m($num) == "x"} {
			    set m($num)  "-"
			} else {
			    set m($num)  "x"
			}
		    } else {
			if {$m($num) == "x"} {
			    set m($num) "s"
			} elseif {$m($num) == "s"} {
			    set m($num) "S"
			} elseif {$m($num) == "S"} {
			    set m($num) "-"
			} else {
			    set m($num)  "x"
			}
		    }
	        }
		9	{
		    if {$event == "Button-3"} {
			if {$m($num) == "x"} {
			    set m($num)  "-"
			} else {
			    set m($num)  "x"
			}
		    } else {
			if {$m($num) == "x"} {
			    set m($num) "t"
			} elseif {$m($num) == "t"} {
			    set m($num) "T"
			} elseif {$m($num) == "T"} {
			    set m($num) "-"
			} else {
			    set m($num)  "x"
			}
		    }
	        }
	    }
  	}

	if {$num != "set"} {
	    $top.bm($num) config -text $m($num)
	    set fmode ""
	    for {set i 0} {$i < 10} {incr i} {
	    	append fmode $m($i)
	    }
	} else {
	    set s 0 ; set o 0 ; set g 0 ; set w 0
	    if {$m(1) == "r"} {incr o 4}
	    if {$m(2) == "w"} {incr o 2}
	    if {$m(3) == "x"} {
		incr o 1
	    } else {
		if {$m(3) != "-"} {
		    incr s 4
		    if {$m(3) == "s"} {incr o 1}
		}
	    }
	    if {$m(4) == "r"} {incr g 4}
	    if {$m(5) == "w"} {incr g 2}
	    if {$m(6) == "x"} {
		incr g 1
	    } else {
		if {$m(6) != "-"} {
		    incr s 2
		    if {$m(6) == "s"} {incr g 1}
		}
	    }
	    if {$m(7) == "r"} {incr w 4}
	    if {$m(8) == "w"} {incr w 2}
	    if {$m(9) == "x"} {
		incr w 1
	    } else {
		if {$m(9) != "-"} {
		    incr s 1
		    if {$m(9) == "t"} {incr w 1}
		}
	    }

	    set amode ""
	    append amode $s $o $g $w
	    set err [catch {exec chmod $amode $file} errmsg]
	    if $err {
		dsk_errbell
		cb_error $errmsg
	    }
	    dsk_refresh $file
	    catch {$top.bChmod config -state disabled}
	}
    }

    method _configFile {} {
	# backend private proc of the "file" public var
	global tkdesk tkdesk_anno
	
	dsk_busy
	if [file isdirectory $file] {
	    set file [string trimright $file "/"]/
	    set file [dsk_canon_path $file]
	    if {$file != "/"} {
		set file [string trimright $file "/"]
	    }
	}
	set n [file tail $file]
	if [string match $n ""] {set n "/"}
	$top.label config -text $n
	set p [file dirname $file]
	if {[string first $tkdesk(trashdir) $p] == 0} {
	    set p [string range $p \
		    [string length $tkdesk(trashdir)/] 1000]
	    if {$p == ""} {
		set p "Trash"
	    }
	}	
	$top.lrPath config -text [cb_tilde $p collapse]
	set lsl ""
	set lsl [lindex [dskC_ls -l -o $file] 0]
	#regsub -all {\\t} $lsl "\t" lsl
	set lsl [split $lsl "\t"]
	dsk_debug "$file: $lsl"
	$top.lrSize config -text "[lindex $lsl 1] Bytes"
	$top.lrLink config -text [string trimleft [lindex $lsl 6] " "]
	$top.bMod config -text "[lindex $lsl 2]"
	set owner [lindex $lsl 3]
	$top.bOwn config -text "$owner"
	set group [lindex $lsl 4]
	$top.bGrp config -text "$group"

	set fmode [lindex $lsl 5]
	for {set i 1} {$i < 10} {incr i} {
	    $top.bm($i) config -text [string index $fmode $i]
	}

	set err [catch {set m [exec file $file]} errmsg]
	if !$err {
	    $top.mMagic config -text [string trimleft [string range $m \
		    [expr [string first ":" $m] + 1] 10000] " "]
	} else {
	    $top.mMagic config -text $errmsg
	}

	$top.ft.text delete 1.0 end
	if [info exists tkdesk_anno($file)] {
	    $top.ft.text insert end $tkdesk_anno($file)
	}

	if {[file isdirectory $file] && ![winfo exists $top.bDU]} {
	    button $top.bDU -text " Disk Usage " -command "dsk_du \"$file\""
	    pack $top.bDU -in $top.fb -side left \
			-padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 2
	} else {
	    if [winfo exists $top.bDU] {
		destroy $top.bDU
	    }
	}

	update idletasks
	wm iconname $top "Info: [file tail $file]"
	wm sizefrom $top program
	if {[wm state $top] != "normal"} {
	    dsk_place_window $top fileinfo "36x6" 1
	    wm deiconify $top
	}
	dsk_lazy
    }

    proc id {} {
	set i $id
	incr id
	return $i
    }

    proc cache {cmd args} {
	switch $cmd {
	    "get" {
		if {$objectCache == {}} {
		    return [eval dsk_FileInfo .fi[dsk_FileInfo :: id] $args]
		} else {
		    #puts "objectCache before: $objectCache"
		    set obj [lindex $objectCache 0]
		    set objectCache [lrange $objectCache 1 end]
		    #puts "objectCache after:  $objectCache"
		    eval $obj config $args
		    return $obj
		}
	    }
	    "add" {
		lappend objectCache $args
	    }
	}
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    public file "" {

	set file [cb_tilde $file expand]
	dsk_debug "dsk_FileInfo config file: $file"	
	if [file exists $file] {
	    _configFile
	}
    }

    protected owner
    protected group
    protected fmode

    common id 0
    common objectCache {}
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_fileinfo
# Args:		none!
# Returns: 	""
# Desc:		Creates an object of class dsk_FileInfo on each selected file
#		in the calling file viewer.
# Side-FX:	
#

proc dsk_fileinfo {args} {
    global tkdesk

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
	set file [subst -nocommands -novariables $file]
	set file [dskC_striptc $file]
	if ![file exists $file] {
	    dsk_errbell
	    cb_info "[file tail $file]\nis a broken symbolic link or has been removed."
	    continue
	}
	
	if {$file != ""} {
	    if {[info tclversion] >= 8.0} {
		# itcl 3.x seems to disallow object creation through
		# class procs
		dsk_FileInfo .fi[dsk_FileInfo :: id] -file $file
	    } else {
		dsk_FileInfo :: cache get -file $file
	    }
	}
    }
}

