# =============================================================================
#
# File:		cpanels.tcl
# Project:	TkDesk
#
# Started:	30.04.97
# Changed:	30.04.97
# Author:	cb
#
# Description:	Implements the configuration panels for colors, fonts,
#               icons and sounds.
#
# Copyright (C) 1996, 1997  Christian Bolik
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
#s    proc dsk_config_panel {which text_widget}
#s    proc dsk_config_panel_return {which insert {text_widget ""}}
#s    proc _dsk_cpanel_retrieveX {which offset maxBytes}
#s    proc _dsk_cpanel_color {frame default}
#s    proc _dsk_cpanel_color_set {w dummy}
#s    proc _dsk_cpanel_font {frame def}
#s    proc _dsk_cpanel_font_reread {entry lbox {def ""}}
#s    proc _dsk_cpanel_font_set {lbox sample}
#s    proc _dsk_cpanel_icon {f def}
#s    proc _dsk_cpanel_icon_list_popup {dlb x y}
#s    proc _dsk_cpanel_icon_path_popup {entry x y}
#s    proc _dsk_cpanel_icon_reread {frame}
#s    proc _dsk_cpanel_icon_createimg {dlb line file}
#
# =============================================================================

proc dsk_config_panel {which {text_widget ""}} {
    global tkdesk dsk_config_panel

    if {$text_widget != ""} {
	if {[$text_widget tag nextrange sel 1.0 end] != ""} {
	    set def [subst [$text_widget get sel.first sel.last]]
	} else {
	    set def ""
	}
    } else {
	set def ""
    }

    set t .cpanel-$which
    if [winfo exists $t] {
	wm deiconify $t
	raise $t
	return
    }

    # create panel toplevel 
    toplevel $t
    wm withdraw $t
    frame $t.fTop -bd 1 -relief raised
    pack $t.fTop -fill both -expand yes

    # create lower part:
    frame $t.fBot -bd 1 -relief raised
    pack $t.fBot -fill x
    button $t.bOK -text "Insert" -width 7 -command \
	    "dsk_config_panel_return $which 1 $text_widget"
    button $t.bCopy -text "Select" -width 7 -command \
	    "dsk_config_panel_return $which 2 $text_widget"
    button $t.bCancel -text "Close" -width 7 -command \
	    "dsk_config_panel_return $which 0"
    pack $t.bOK $t.bCopy $t.bCancel -in $t.fBot -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad) -ipady 1

    # jump to subroutines to build and handle the upper part:
    set dsk_config_panel($which,sel) $def
    set grid 0
    set defgeom ""
    switch $which {
	colors {
	    _dsk_cpanel_color $t.fTop $def
	    wm resizable $t 0 0
	    set title "Choose a Color"
	}
	fonts {
	    if ![dsk_auto_execok xlsfonts] {
		destroy $t
		cb_error "Couldn't execute xlsfonts!"
		return
	    }
	    _dsk_cpanel_font $t.fTop $def
	    update idletasks
	    pack propagate $t.fTop 0
	    set title "Choose a Font"
	    set grid 1
	    set defgeom 60x10
	}
	icons {
	    _dsk_cpanel_iconsnd icons $t.fTop $def
	    set title "Choose an Icon"
	    set grid 1
	    set defgeom 20x20
	}
	sounds {
	    _dsk_cpanel_iconsnd sounds $t.fTop $def
	    set title "Choose a Sound"
	    set grid 1
	    set defgeom 20x15
	}
    }

    # make panel visible
    update idletasks
    wm title $t $title
    wm protocol $t WM_DELETE_WINDOW "dsk_config_panel_return $which 0"
    dsk_place_window $t "cpanel-$which" $defgeom $grid
    wm deiconify $t
}

proc dsk_config_panel_return {which insert {text_widget ""}} {
    global dsk_config_panel

    if {$insert == 1} {
	if [winfo exists $text_widget] {
	    set sel $dsk_config_panel($which,sel)
	    if {$sel != ""} {
		if {[$text_widget tag nextrange sel 1.0 end] != ""} {
		    cb_Text_change_callback $text_widget delete char
		    $text_widget delete sel.first sel.last
		}
		cb_Text_change_callback $text_widget insert $sel
		$text_widget insert insert $sel
		$text_widget see insert
	    }
	} else {
	    dsk_errbell
	    cb_error {The associated window has been deleted.  Please copy and paste the chosen value using the "Select" button.}
	}
    } elseif {$insert == 2} {
	selection handle .cpanel-$which "_dsk_cpanel_retrieveX $which"
	selection own .cpanel-$which
    } else {
	destroy .cpanel-$which
    }
}

proc _dsk_cpanel_retrieveX {which offset maxBytes} {
    global dsk_config_panel

    return $dsk_config_panel($which,sel)
}

proc _dsk_cpanel_color {frame default} {
    global tkdesk
    
    if {$default == ""} {
       set default $tkdesk(color,background)
    }
    tk_chooseColor -parent $frame -initialcolor $default
}

proc _dsk_cpanel_color_set {w dummy} {
    global _dsk_cpanel_color

    set _dsk_cpanel_color(color) [format \#%02x%02x%02x \
	    $_dsk_cpanel_color(red) \
	    $_dsk_cpanel_color(green) \
	    $_dsk_cpanel_color(blue)]
    
    $w config -bg $_dsk_cpanel_color(color)
}


proc _dsk_cpanel_font {frame def} {
    global tkdesk _dsk_cpanel_font

    frame [set f $frame.fmask]
    pack $f -fill x
    label $f.lMask -text "Mask:"    
    entry $f.eMask -bd 2 -relief sunken
    set entry $f.eMask
    $entry insert end "*"
    pack $f.lMask -side left -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $f.eMask -side left -fill x -padx $tkdesk(pad) -pady $tkdesk(pad) \
	    -expand yes -ipady 2

    frame [set f $frame.flist]
    pack $f -fill both -expand yes
    listbox $f.lbox -bd 2 -relief sunken -selectmode browse \
	    -font [cb_font $tkdesk(font,text)] -width 40 -height 5 \
	    -exportselection false -yscroll "$f.sb set" \
	    -takefocus 0 -highlightthickness 0 -setgrid 1
    set lbox $f.lbox
    bind $lbox <ButtonRelease-1> "_dsk_cpanel_font_set $lbox $frame.lSample"
    scrollbar $f.sb -orient vertical -command "$f.lbox yview"
    pack $f.lbox -side left -fill both -expand yes -padx $tkdesk(pad)
    pack $f.sb -side left -fill y
    frame $f.frb -width $tkdesk(pad)
    pack $f.frb -side left

    label $frame.lSample -text "The quick brown fox\njumps over the lazy dog -\n1234567890 times."
    if {$def != ""} {
	catch {$frame.lSample config -font $def}
    }
    pack $frame.lSample -padx $tkdesk(pad) -pady $tkdesk(pad)
    
    bind $entry <Return> "_dsk_cpanel_font_reread $entry $lbox"
    _dsk_cpanel_font_reread $entry $lbox $def
    
    wm minsize [winfo toplevel $frame] 40 5
}

proc _dsk_cpanel_font_reread {entry lbox {def ""}} {
    
    dsk_busy
    set flist ""
    catch {set flist [split [exec xlsfonts [$entry get]] \n]}
    set i 0
    set seli -1
    $lbox delete 0 end
    foreach f $flist {
	$lbox insert end $f
	if {$def != ""} {
	    if [string match $def $f] {
		set seli $i
	    }
	    incr i
	}
    }
    if {$seli > -1} {
	$lbox selection set $seli
	$lbox see $seli
    }
    dsk_lazy
}

proc _dsk_cpanel_font_set {lbox sample} {
    global dsk_config_panel

    set cs [$lbox curselection]
    if {$cs == ""} {
	set dsk_config_panel(fonts,sel) ""
	return
    }
    
    set font [$lbox get $cs]
    $sample config -font $font
    update idletasks
    set dsk_config_panel(fonts,sel) $font
}


proc _dsk_cpanel_iconsnd {which f def} {
    global tkdesk _dsk_cpanel_iconsnd

    set _dsk_cpanel_iconsnd([winfo toplevel $f],which) $which
    
    frame $f.fPath
    pack $f.fPath -fill x
    label $f.lPath -text "Path:" -width 5 -anchor w
    entry $f.ePath -bd 2 -width 5 -relief sunken
    
    set entry $f.ePath
    set ip ""
    #if {$def != ""} {
    #	 catch {set ip [file dirname $def]}
    #}
    if {$ip == "" || $ip == "."} {
	if {$which == "icons"} {
	    set plist [split $tkdesk(path,images) :]
	} else {
	    set plist [split $tkdesk(path,sounds) :]
	}
	set ip [lindex $plist 0]
    }
    $entry insert end [cb_tilde $ip collapse]
    $entry xview end
    blt_drag&drop target $entry handler file "dd_handle_text $entry %v 1"
    bind $entry <Return> "_dsk_cpanel_iconsnd_reread $f"
    bind $entry <3> {_dsk_cpanel_iconsnd_path_popup %W %X %Y}
    cb_bindForCompletion $entry <Control-Tab>
    
    menubutton $f.mbDirs -bd 2 -relief raised \
	    -bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
	    -menu $f.mbDirs.menu
    menu [set m $f.mbDirs.menu]
    
    pack $f.lPath -in $f.fPath -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $f.ePath -in $f.fPath -side left -fill x \
	    -padx $tkdesk(pad) -pady $tkdesk(pad) \
	    -expand yes -ipady 2
    pack $f.mbDirs -in $f.fPath -side left -ipadx 2 -ipady 2 \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)

    frame $f.fMask
    pack $f.fMask -fill x
    label $f.lMask -text "Mask:" -width 5 -anchor e
    entry $f.eMask -width 5 -bd 2 -relief sunken
    set mentry $f.eMask
    $mentry insert end "*"
    bind $mentry <Return> "_dsk_cpanel_iconsnd_reread $f"
    pack $f.lMask -in $f.fMask -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $f.eMask -in $f.fMask -side left -fill x \
	    -padx $tkdesk(pad) -pady $tkdesk(pad) \
	    -expand yes -ipady 2

    catch {$f.dlb delete}
    dsk_Listbox $f.dlb -width $tkdesk(file_lb,width) -height 10 \
	    -font [cb_font $tkdesk(font,file_lbs)] \
	    -bg [cb_col $tkdesk(color,filelb)] \
	    -fg $tkdesk(color,foreground)
    set fdlb [$f.dlb getFrame]
    if {$which == "icons"} {
	$fdlb.text config -tabs {56 left}
    } else {
	$fdlb.text config -tabs {24 left}
    }
    $f.dlb show_hsb 0
    $fdlb config -relief flat
    pack $fdlb -fill both -expand yes
    bind $fdlb.text <ButtonRelease-1> "+_dsk_cpanel_iconsnd_set $f.dlb"
    bind $fdlb.text <3> "\
	    [bind $fdlb.text <1>] ;\
	    update idletasks ;\
	    _dsk_cpanel_iconsnd_set $f.dlb ;\
	    _dsk_cpanel_iconsnd_list_popup $f.dlb %X %Y
    "
    if {$which == "sounds"} {
	bind $fdlb.text <Double-1> "_dsk_cpanel_iconsnd_play $f.dlb"
    }

    # bindtags for the icon widgets:
    bind cpanel-icon <1> "
	    $f.dlb select clear
	    $f.dlb select \[expr \[lindex \[split %W :\] 1\] - 1\]
	    $f.dlb _sel_first \[lindex \[split %W :\] 1\]
            _dsk_cpanel_iconsnd_set $f.dlb
   "
    bind cpanel-icon <Double-1> [bind $fdlb.text <Double-1>]
    bind cpanel-icon <3> "\
	    [bind cpanel-icon <1>] ;\
	    update idletasks ;\
	    _dsk_cpanel_iconsnd_set $f.dlb ;\
	    _dsk_cpanel_iconsnd_list_popup $f.dlb %X %Y
    "

    _dsk_cpanel_iconsnd_reread $f
    
    wm minsize [winfo toplevel $f] 16 2
}

proc _dsk_cpanel_iconsnd_list_popup {dlb x y} {
    global _dsk_cpanel_iconsnd
    
    set si [$dlb select get]
    if {$si != ""} {
	set file [string trimleft [lindex [$dlb get] $si] \t]
	dsk_popup "" $_dsk_cpanel_iconsnd([winfo toplevel [$dlb getFrame]],curpath)/$file $x $y
    }
}

proc _dsk_cpanel_iconsnd_path_popup {entry x y} {
    global tkdesk
    
    set dest [$entry get]
    if [file isdirectory $dest] {
	set this [winfo toplevel $entry]
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
			"_dsk_cpanel_iconsnd_read_from $p [winfo parent $entry]" \
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
			\{_dsk_cpanel_iconsnd_read_from %d [winfo parent $entry]\}"
		incr i
		if {$p == "/"} break
	    }
	    update
	    tk_popup $m $x $y
	}
    }
}

proc _dsk_cpanel_iconsnd_read_from {path frame} {
    $frame.ePath delete 0 end
    $frame.ePath insert end [cb_tilde $path collapse]
    $frame.ePath xview end
    _dsk_cpanel_iconsnd_reread $frame
}

proc _dsk_cpanel_iconsnd_reread {frame} {
    global tkdesk _dsk_cpanel_iconsnd
    
    dsk_busy
    set which $_dsk_cpanel_iconsnd([winfo toplevel $frame],which)
    set dir [string trimright [cb_tilde [$frame.ePath get] expand] "/"]
    set ndir $dir
    if {$dir == ""} {set dir "/"}
    if ![file isdirectory $dir] {
	dsk_lazy
	cb_error "$dir: not a directory."
	return
    }
    set _dsk_cpanel_iconsnd([winfo toplevel $frame],curpath) $dir
    set mask [$frame.eMask get]

    set flist [dskC_ls -f -s name $dir -M $mask]
    set list ""
    set dlist ""
    foreach f $flist {
	set f [string trimright $f]
	if ![file isdirectory $ndir/$f] {
	    if {$which == "icons"} {
		lappend list \t$f
	    } else {
		lappend list $f
	    }
	} else {
	    if {$f != "." && $f != ".."} {
		lappend dlist $f
	    }
	}
    }
    
    $frame.dlb config -list $list
    set fdlb [$frame.dlb getFrame]
    set l 1
    foreach f $list {
	set fn [list $ndir/[string trimleft $f \t]]
	if {$which == "icons"} {
	    $fdlb.text window create $l.0 \
		    -create "_dsk_cpanel_iconsnd_createimg $frame.dlb $l $fn" \
		    -padx 4 -pady 4
	} else {
	    set ext [file extension $f]
	    if {[lsearch {.au .voc .wav .aiff .raw .snd} $ext] > -1} {
		$fdlb.text window create $l.0 \
			-create "_dsk_cpanel_iconsnd_createimg $frame.dlb $l ficons16/speaker.xpm" \
			-padx 4 -pady 4
	    }
	}
	incr l
    }

    # update menu:
    $frame.mbDirs.menu delete 0 last
    if {[llength $dlist] > 0} {
	foreach d $dlist {
	    $frame.mbDirs.menu add command \
		    -label [cb_tilde [list $ndir/$d] collapse] \
		    -command "_dsk_cpanel_iconsnd_read_from [list $ndir/$d] $frame" \
		    -font [cb_font $tkdesk(font,file_lbs)]
	}
	$frame.mbDirs.menu add separator
    }
    if {$which == "icons"} {
	set plist [split $tkdesk(path,images) :]
    } else {
	set plist [split $tkdesk(path,sounds) :]
    }
    foreach p $plist {
	$frame.mbDirs.menu add command \
		-label [cb_tilde $p collapse] \
		-command "_dsk_cpanel_iconsnd_read_from [list $p] $frame" \
		-font [cb_font $tkdesk(font,file_lbs)]
    }
    
    dsk_lazy
}

proc _dsk_cpanel_iconsnd_createimg {dlb line file} {
    set dlb [$dlb getFrame]
    catch {label $dlb.text.l:$line}
    $dlb.text.l:$line config -image [dsk_image $file reread] -bd 0
    bindtags $dlb.text.l:$line cpanel-icon
    return $dlb.text.l:$line
}

proc _dsk_cpanel_iconsnd_set {dlb} {
    global tkdesk dsk_config_panel _dsk_cpanel_iconsnd

    set fdlb [$dlb getFrame]
    set which $_dsk_cpanel_iconsnd([winfo toplevel $fdlb],which)
    set si [lindex [$dlb select get] 0]
    if {$si != ""} {
	set file [string trimleft [lindex [$dlb get] $si] \t]
	set curpath $_dsk_cpanel_iconsnd([winfo toplevel $fdlb],curpath)
	if {$curpath != "/"} {
	    set file [cb_tilde $curpath/$file collapse]
	}

	# try to shorten path of file:
	set maxl 0
	if {$which == "icons"} {
	    set plist [split $tkdesk(path,images) :]
	} else {
	    set plist [split $tkdesk(path,sounds) :]
	}
	foreach p $plist {
	    set p [cb_tilde $p collapse]

	    if {[string first $p $file] == 0} {
		set l [string length $p]
		if {$l > $maxl} {
		    set maxl $l
		}
	    }
	}
	if {$maxl > 0} {
	    set file [string trimleft [string range $file $maxl 1000] /]
	}
	
	set dsk_config_panel($which,sel) $file
    } else {
	set dsk_config_panel($which,sel) ""
    }    
}

proc _dsk_cpanel_iconsnd_play {dlb} {
    global tkdesk dsk_config_panel _dsk_cpanel_iconsnd

    set fdlb [$dlb getFrame]
    set which $_dsk_cpanel_iconsnd([winfo toplevel $fdlb],which)
    set si [lindex [$dlb select get] 0]
    if {$si != ""} {
	set file [string trimleft [lindex [$dlb get] $si] \t]
	set curpath $_dsk_cpanel_iconsnd([winfo toplevel $fdlb],curpath)
	if {$curpath != "/"} {
	    set file [cb_tilde $curpath/$file collapse]
	}

	set us $tkdesk(use_sound)
	set tkdesk(use_sound) 1
	dsk_sound $file
	set tkdesk(use_sound) $us
    }
}
