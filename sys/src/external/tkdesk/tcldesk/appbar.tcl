# =============================================================================
#
# File:		appbar.tcl
# Project:	TkDesk
#
# Started:	13.11.94
# Changed:	13.11.94
# Author:	cb
#
# Description:	Implements an application bar. This features popup menus
#		and drag and drop targets.
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
#s    proc dsk_appbar {args}
#s    proc _appbar_create {}
#s    proc _appbar_mcheck {appmenu nr menu}
#s    proc _appbar_handle_special_entry {m me}
#s    proc _appbar_add_to_menu {menu cmd}
#s    proc _appbar_unpost_parents {menu}
#s    proc _appbar_dd_action {cmd}
#s    proc _appbar_show_menu {butnum rootx rooty {win ""}}
#s    proc _appbar_motion {lastnum x y {win ""}}
#s    proc _appbar_close {}
#s    proc _appbar_raise {}
#s    proc _appbar_lower {}
#s    proc _appbar_layout {orient}
#s    proc _appbar_move {}
#s    proc _appbar_bind_special {widgets count mw}
#s    proc _appbar_bind_global {}
#s    proc _appbar_get_button_width {}
#
# =============================================================================

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_appbar
# Args:		layout <horizontal|vertical>	change the layout
#		move		move the application bar around
# Returns: 	""
# Desc:		Meta proc for all things that concern the appbar.
# Side-FX:	none
#

proc dsk_appbar {args} {
    global tkdesk

    dsk_progress "Creating the application bar..."
    if ![info exists tkdesk(appbar)] {
	dsk_errbell
	cb_error "Couldn't read config file AppBar. Sorry, no application bar available."
	return
    }

    if {$args == ""} {
	_appbar_create
    } else {
	set cmd [lindex $args 0]
	set opts [lrange $args 1 [llength $args]]
	switch $cmd {
	    layout	{eval _appbar_layout $opts}
	    move	{eval _appbar_move $opts}
	    raise	{eval _appbar_raise}
	    lower	{eval _appbar_lower}
	    close	{eval _appbar_close}
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_create
# Args:		none
# Returns: 	""
# Desc:		Builds and displays the application bar.
# Side-FX:	none
#

if ![info exists tkdesk(geometry,dsk_appbar)] {
    set tkdesk(geometry,dsk_appbar) ""
}

set tkdesk(toggle,appbar) 0
set dsk_appbar(is_visible) 0

proc _appbar_create {} {
    global tkdesk dsk_appbar cb_tools

    set t .dsk_appbar
    if [winfo exists $t] {
	#cb_raise $t
	set tkdesk(toggle,appbar) 0
	_appbar_close
	return
    }

    if ![info exists tkdesk(appbar,max)] {
	set tkdesk(appbar,max) 100
    } elseif {$tkdesk(appbar,max) <= 0} {
	return
    }
    
    set tkdesk(toggle,appbar) 1
    dsk_busy 

    toplevel $t
    wm withdraw $t

    set ipad $tkdesk(appbar,ipad)
    set side top
    set fside left
    set dsk_appbar(layout) vertical
    if {$tkdesk(geometry,dsk_appbar) != ""} {
	set glist [split $tkdesk(geometry,dsk_appbar) x+]
	if {[lindex $glist 0] > [lindex $glist 1]} {
	    set side left
	    set fside top
	    set dsk_appbar(layout) horizontal
	}
    }
    set dsk_appbar(tmp_bh) $cb_tools(balloon_help)
    
    # Setup Quick Menus
    menu [set m .dsk_appbar.qmConfig]
    foreach cf $tkdesk(configfiles) {
	$m add command -label "$cf" \
		-command "dsk_edit_configs $cf"
    }
    menu [set m .dsk_appbar.qmAppbar]
    $m add command -label {Edit AppBar} -command {dsk_edit_configs AppBar}
    $m add command -label {Reload AppBar} -command {dsk_reread_config AppBar}
    $m add separator
    $m add command -label {Vertical} -command {dsk_appbar layout vertical}
    $m add command -label {Horizontal } -command {dsk_appbar layout horizontal}
    $m add command -label {Raise} -command {dsk_appbar raise}
    $m add command -label {Lower} -command {dsk_appbar lower}
    $m add command -label {Hide AppBar} -command {dsk_appbar close}
    $m add separator
    $m add command -label {Move Top Left} -command {dsk_appbar move topleft}
    $m add command -label {Move Bottom Left} \
	    -command {dsk_appbar move bottomleft}
    $m add command -label {Move Top Right} -command {dsk_appbar move topright}
    $m add command -label {Move Bottom Right} \
	    -command {dsk_appbar move bottomright}

    if {[llength [array names tkdesk appbar-*]] > 0} {
	# There's more than one AppBar defined -> create menu
	menubutton $t.mbBarSel -font fixed -text "Main" \
		-menu [set m $t.mbBarSel.m] \
		-bd 2 -relief flat -padx 0 -pady 0
	menu $m
	pack $t.mbBarSel -fill x
    }

    #
    # Create Drag/Toggle Area
    #
    if {$tkdesk(appbar,dragger)} {
	button $t.bDrag -bitmap gray12 \
		-height 8 -width 8 -cursor top_left_arrow \
		-padx 0 -pady 0 -highlightthickness 0 \
		-command _appbar_toggle_vis
	if {$dsk_appbar(layout) == "vertical"} {
	    pack $t.bDrag -padx 0 -pady 0 -fill x -side $side
	} else {
	    pack $t.bDrag -padx 0 -pady 0 -fill y -side $side
	}
	set cc white
	if {[winfo depth .] != 1} {
	    set cc [cb_col $tkdesk(color,drag)]
	}
	bindtags $t.bDrag "appbar $t.bDrag Button all"
	bind $t.bDrag <ButtonPress-1> {
	    set dsk_appbar(oldx) [winfo rootx .dsk_appbar]
	    _appbar_bind_global_b1 %W %X %Y
	    #break
	}
    }
    
    set count 0
    set fcount 0
    foreach but $tkdesk(appbar) {
	if {[expr $count % $tkdesk(appbar,max)] == 0} {
	    incr fcount	    
	    frame $t.f$fcount -bg [cb_col $tkdesk(color,icon)]
	    pack $t.f$fcount -side $fside -fill both
	}

	if {[llength $but] > 1} {
	    set bitmap [lindex $but 0]
	    set dsk_appbar(bgcolor) [cb_col $tkdesk(color,background)]
	    set dsk_appbar(fgcolor) [cb_col $tkdesk(color,foreground)]
	    if {[llength $bitmap] > 1} {
		if {[lindex $bitmap 1] != ""} {
		    set dsk_appbar(fgcolor) [lindex $bitmap 1]
		}
		if {[llength $bitmap] > 2} {
		    if {[lindex $bitmap 2] != ""} {
			set dsk_appbar(bgcolor) [lindex $bitmap 2]
		    }
		}
		set bitmap [lindex $bitmap 0]
	    }

	    set appmenu [lindex $but 1]
	    menu [set m $t.m$count] -disabledforeground blue2
	    bind $m <ButtonRelease-3> {
		if {[winfo containing %X %Y] != $dsk_appbar(lastbut)} {
		    event generate %W <ButtonRelease-1>
		}
		break
	    }
	    
	    set dsk_appbar(num_cas) 0
	    set dsk_appbar(defaction) ""
	    set dsk_appbar(deflabel) ""
	    set dsk_appbar(ddaction) ""
	    foreach me $appmenu {
		if {[llength $me] == 1} {
		    _appbar_handle_special_entry $m $me
		} else {
		    _appbar_add_to_menu $m $me
		}
	    }

	    if {[string first "special:" $bitmap] == 0} {
		switch $bitmap {
		    "special:date" {
			set mw [_appbar_date $t.f$fcount $side]
			_appbar_bind_date $count
			set dsk_appbar(date,countval) $count
		    }
		    "special:load" {
			if {[dsk_auto_execok uptime] || \
				$tkdesk(systype) == "Linux"} {
			    set mw [_appbar_load $t.f$fcount $side]
			    _appbar_bind_load $count
			    set dsk_appbar(load,countval) $count
			} else {
			    dsk_errbell
			    cb_error "Disabling load display as I don't know how to get the load on your system.  If you do, please send an email to Christian.Bolik@Mainz.netsurf.de.  Thank you."
			    #incr count -1
			}
		    }
		    "special:mail" {
			_appbar_mail $t.b$count
			pack $t.b$count -in $t.f$fcount -side $side \
				-fill both -ipadx $ipad -ipady $ipad
			bind $t.b$count <3> \
				"_appbar_show_menu $count %X %Y"
			bind $t.m$count <B3-Motion> \
				"_appbar_motion $count %X %Y"
			cb_balloonHelp $t.b$count  $dsk_appbar(deflabel)
			bindtags $t.b$count "appbar $t.b$count Button all"

			if {$dsk_appbar(ddaction) != ""} {
			    blt_drag&drop target $t.b$count handler file \
			    "_appbar_dd_action [list $dsk_appbar(ddaction)] %v"
			}
		    }
		    "special:dialup" {
			_appbar_dialup $t.b$count $count
			pack $t.b$count -in $t.f$fcount -side $side \
				-fill both -ipadx $ipad -ipady $ipad
			bind $t.b$count <3> \
				"_appbar_show_menu $count %X %Y"
			bind $t.m$count <B3-Motion> \
				"_appbar_motion $count %X %Y"
			cb_balloonHelp $t.b$count  $dsk_appbar(deflabel)
			bindtags $t.b$count "appbar $t.b$count Button all"

			if {$dsk_appbar(ddaction) != ""} {
			    blt_drag&drop target $t.b$count handler file \
			    "_appbar_dd_action [list $dsk_appbar(ddaction)] %v"
			}
		    }
		    "special:trash" {
			catch {unset dsk_appbar(trash,label)}
			_appbar_trash $t.b$count
			pack $t.b$count -in $t.f$fcount -side $side \
				-fill both -ipadx $ipad -ipady $ipad
			if [info exists dsk_appbar(trash,label)] {
			    pack $dsk_appbar(trash,label) \
				    -in $t.f$fcount -side $side -fill both
			    bindtags $dsk_appbar(trash,label) "appbar all"
			}
			bind $t.b$count <3> \
				"_appbar_show_menu $count %X %Y"
			bind $t.m$count <B3-Motion> \
				"_appbar_motion $count %X %Y"
			cb_balloonHelp $t.b$count  $dsk_appbar(deflabel)
			bindtags $t.b$count "appbar $t.b$count Button all"

			if {$dsk_appbar(ddaction) != ""} {
			    blt_drag&drop target $t.b$count handler file \
			    "_appbar_dd_action [list $dsk_appbar(ddaction)] %v"
			}
		    }
		}

	    } else {
		button $t.b$count \
			-image [dsk_image $bitmap \
			-background $dsk_appbar(bgcolor) \
			-foreground $dsk_appbar(fgcolor)] \
			-activebackground $dsk_appbar(bgcolor) \
			-activeforeground $dsk_appbar(fgcolor) \
			-cursor top_left_arrow \
			-command $dsk_appbar(defaction) \
			-padx 0 -pady 0 -highlightthickness 0
		pack $t.b$count -in $t.f$fcount -side $side -fill both \
			 -ipadx $ipad -ipady $ipad
		
		bind $t.b$count <3> "_appbar_show_menu $count %X %Y"
		bind $t.m$count <B3-Motion> "_appbar_motion $count %X %Y"
		cb_balloonHelp $t.b$count  $dsk_appbar(deflabel)
		#_appbar_bind_global $t.b$count
		bindtags $t.b$count "appbar $t.b$count Button all"

		if {$dsk_appbar(ddaction) != ""} {
		    blt_drag&drop target $t.b$count handler file \
			    "_appbar_dd_action [list $dsk_appbar(ddaction)] %v"
		}
	    }

	} else {
	    set special [lindex $but 0]
	    switch [lindex $special 0] {
		date {
		    _appbar_date $t.f$fcount $side
		    # the date occupies 2 buttons:
		    incr count
		}
	    }
	}

	incr count
    }
    set dsk_appbar(fcount) $fcount
    set dsk_appbar(is_visible) 1

    bind $t <Enter> {_appbar_auto_raise}

    wm title $t "TkDesk Application Bar"
    if {$tkdesk(geometry,dsk_appbar) == ""} {
	wm geometry $t +0+0
    } else {
	set pi [string first "+" $tkdesk(geometry,dsk_appbar)]
	set pi2 [string first "-" $tkdesk(geometry,dsk_appbar)]
	if {$pi2 > -1 && ($pi2 < $pi || $pi < 0)} {set pi $pi2}
	wm geometry $t [string range $tkdesk(geometry,dsk_appbar) $pi 1000]
    }

    if $tkdesk(appbar,wm_managed) {
	wm overrideredirect $t 0
    } else {
	wm overrideredirect $t 1
    }
    wm deiconify $t
    _appbar_bind_global

    dsk_Common :: adjustAppBarMenuEntry 1
    dsk_lazy
}

proc _appbar_toggle_vis {} {
    global dsk_appbar

    if [info exists dsk_appbar(oldx)] {
    	  if {$dsk_appbar(oldx) != [winfo rootx .dsk_appbar]} {
    	      return
    	  }
    }

    set t .dsk_appbar
    if $dsk_appbar(is_visible) {
	if {[winfo exists $t.bDrag]} {
	    if {$dsk_appbar(layout) == "vertical"} {
		$t.bDrag config -width [expr [winfo reqwidth $t] -4]
	    } else {
		$t.bDrag config -height [expr [winfo reqheight $t] -4]
	    }
	}
	for {set i 1} {$i <= $dsk_appbar(fcount)} {incr i} {
	    pack forget $t.f$i
	}
	set dsk_appbar(is_visible) 0
    } else {
	if {$dsk_appbar(layout) == "vertical"} {
	    set fside left
	} else {
	    set fside top
	}
	for {set i 1} {$i <= $dsk_appbar(fcount)} {incr i} {
	    pack $t.f$i -side $fside -fill both
	}
	if {[winfo exists $t.bDrag]} {
	    $t.bDrag config -width 8 -height 8
	}
	set dsk_appbar(is_visible) 1
    }
}

proc _appbar_mcheck {appmenu nr menu} {
    if {[$appmenu index active] != $nr && \
	[string first "tearoff" $menu] == -1} {
	$menu unpost
    }
}

set _appbar_special(cas) 0
proc _appbar_handle_special_entry {m me} {
    global tkdesk _appbar_special
    
    if [$m cget -tearoff] {
	set inr 1
    } else {
	set inr 0
    }
	    
    if {$me == "-"} {
	$m add separator
    } elseif {$me == "."} {
	$m config -tearoff 1
    } elseif {$me == "history:dirs"} {
	$m add cascade -label "Directories" -menu $m.mhd
	menu $m.mhd -postcommand \
		"dir_history buildmenu $m.mhd open; update"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$m.mhd add command -label "dummy"
	dir_history changed
	bind $m.mhd <Visibility> "_appbar_mcheck $m \
		[expr [$m index last] + $inr] %W"
    } elseif {$me == "history:files"} {
	$m add cascade -label "Files" -menu $m.mhf
	menu $m.mhf -postcommand \
		"file_history buildmenu $m.mhf; update"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$m.mhf add command -label "dummy"
	file_history changed
	bind $m.mhf <ButtonRelease-3> "
	      set tkdesk(file_lb,control) 0
	      [bind Menu <ButtonRelease-3>]"
	bind $m.mhf <Control-ButtonRelease-3> "
	      set tkdesk(file_lb,control) 1
	      [bind Menu <ButtonRelease-3>]"
	bind $m.mhf <Shift-ButtonRelease-3> "
	      set tkdesk(file_lb,control) 2
	      [bind Menu <ButtonRelease-3>]"
	bind $m.mhf <Visibility> "_appbar_mcheck $m \
		[expr [$m index last] + $inr] %W"
    } elseif {$me == "history:execs"} {
	$m add cascade -label "Commands" -menu $m.mhe
	menu $m.mhe -postcommand \
		"exec_history buildmenu $m.mhe; update"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$m.mhe add command -label "dummy"
	exec_history changed
	bind $m.mhe <ButtonRelease-3> "
	      set tkdesk(file_lb,control) 0
	      [bind Menu <ButtonRelease-3>]"
	bind $m.mhe <Control-ButtonRelease-3> "
	      set tkdesk(file_lb,control) 1
	      [bind Menu <ButtonRelease-3>]"
	bind $m.mhe <Shift-ButtonRelease-3> "
	      set tkdesk(file_lb,control) 2
	      [bind Menu <ButtonRelease-3>]"
	bind $m.mhe <Visibility> "_appbar_mcheck $m \
		[expr [$m index last] + $inr] %W"
    } elseif {$me == "bookmarks"} {
	$m add cascade -label "Bookmarks" -menu $m.book
	menu $m.book -postcommand "dsk_bookmark menu $m.book"
	# add dummy entry to work around bug in pre Tk 4.0p2:
	$m.book add command -label "dummy"
	bind $m.book <ButtonRelease-3> "
	   set tkdesk(file_lb,control) 0
	   [bind Menu <ButtonRelease-3>]"
	bind $m.book <Control-ButtonRelease-3> "
	   set tkdesk(file_lb,control) 1
	   [bind Menu <ButtonRelease-3>]"
	bind $m.book <Shift-ButtonRelease-3> "
	   set tkdesk(file_lb,control) 2
	   [bind Menu <ButtonRelease-3>]"
	bind $m.book <Visibility> "_appbar_mcheck $m \
		[expr [$m index last] + $inr] %W"
    } elseif {$me == "config"} {
	$m add cascade -label "Configuration" -menu $m.cfg
	menu [set tm $m.cfg] -tearoff 1
	#menu $m.cfg
	#$m.cfg add cascade -label "Edit Config Files" \
	#	 -menu $m.cfg.edmenu
	#$m.cfg add cascade -label "Reread Config Files" \
	#	 -menu $m.cfg.rdmenu
	#
	#menu [set tm $m.cfg.edmenu]
	foreach cf $tkdesk(configfiles) {
	    set cfs [format "%-12s" $cf]
	    $tm add command -label "$cfs    ($tkdesk(configxpl,$cf))" \
		    -command "dsk_edit_configs $cf"
	}
	$tm add separator
	$tm add cascade -label "Reload" -menu [set rm $tm.remenu]
	menu $rm -tearoff 1
	foreach cf $tkdesk(configfiles) {
	    $rm add command \
		    -label "$cf" \
		    -command "dsk_reread_config $cf"
	}
	$rm add separator
	$rm add checkbutton -label " Reload Automatically" \
		-variable tkdesk(auto_reload_conf)
	
	$tm add command -label "Find..." \
		-command "dsk_find_files -path $tkdesk(configdir) -name [list $tkdesk(configfiles)] -type file"
	$tm add command -label "Colors..." \
			-command "dsk_config_panel colors"
	$tm add command -label "Fonts..." \
			-command "dsk_config_panel fonts"
	$tm add command -label "Icons..." \
			-command "dsk_config_panel icons"
	$tm add command -label "Sounds..." \
			-command "dsk_config_panel sounds"
	
	#menu [set tm $m.cfg.rdmenu]
	#$tm add command -label "All" \
	#	 -command "dsk_reread_config"
	#$tm add separator
	#foreach cf $tkdesk(configfiles) {
	#    $tm add command -label $cf \
	#	     -command "dsk_reread_config $cf"
	#}
    } elseif {$me == "buffers"} {
	$m add cascade -label "Buffers" -menu $m.bufs
	menu [set tm $m.bufs] -postcommand \
		"dsk_Editor :: bufferMenu $tm"
    } elseif [regexp {^\*[^ ]} $me] {
	set cm $m.cas$_appbar_special(cas)
	incr _appbar_special(cas)
	set dir [string trimleft $me *]
	$m add cascade -label "$dir (*)" -menu $cm
	menu $cm -postcommand "dsk_casdirs $dir $cm 1"
	$cm add command -label "dummy"
    } elseif [regexp {^\&[^ ]} $me] {
	set cm $m.cas$_appbar_special(cas)
	incr _appbar_special(cas)
	set dir [string trimleft $me &]
	$m add cascade -label "$dir (&)" -menu $cm
	menu $cm -postcommand "dsk_casdirs $dir $cm 1 {} 1"
	$cm add command -label "dummy"
    } else {
	$m add command -label [subst [lindex $me 0]] \
		-state disabled
    }
}

proc _appbar_add_to_menu {menu cmd} {
	global tkdesk dsk_appbar

	if {[llength $cmd] == 2} {
	    set label [lindex $cmd 0]
	    set command [string_replace [lindex $cmd 1] \" \\\"]
	    if {$label != "dd" && $label != "DD"} {
	        $menu add command -label $label \
			-command "$menu unpost ;\
			_appbar_unpost_parents $menu ;\
			cd \[dsk_active dir\] ;\
			set tkdesk(error_source) {AppBar} ;\
			eval \[_expand_pc [list $command]\];\
			set tkdesk(error_source) {} ;\
			cd ~"
	        if {$dsk_appbar(defaction) == ""} {
		    set dsk_appbar(defaction) \
			    "cd \[dsk_active dir\] ;\
			    set tkdesk(error_source) {AppBar} ;\
			    eval \[_expand_pc [list $command]\] ;\
			    set tkdesk(error_source) {} ;\
			    cd ~"
		    set dsk_appbar(deflabel) $label
	    	}
	    } else {
		set dsk_appbar(ddaction) $command
	    }
	} elseif {[llength $cmd] == 1} {
	    _appbar_handle_special_entry $menu $cmd
	} else {
	    set m ${menu}.mc$dsk_appbar(num_cas)
	    incr dsk_appbar(num_cas)
	    $menu add cascade -label [lindex $cmd 0] -menu $m

	    menu $m
	    set cmd [lreplace $cmd 0 0]
	    foreach c $cmd {
	    	_appbar_add_to_menu $m $c
	    }
	}
}

proc _appbar_unpost_parents {menu} {

    set p [winfo parent $menu]
    while {$p != ""} {
	if {[winfo class $p] == "Menu"} {
	    catch "$p unpost"
	}
	set p [winfo parent $p]
    }
}

proc _appbar_dd_action {cmd args} {
    global tkdesk

    catch "wm withdraw $tkdesk(dd_token_window)"
    update
    
    set flist $args
    if {[string first %A $cmd] > -1} {
	set cmd [string_replace $cmd %A $flist]
    } else {
	set cmd [_expand_pc $cmd]
    }
    cd [dsk_active dir]
    eval $cmd
    cd ~
}

proc _appbar_show_menu {butnum rootx rooty {win ""}} {
    global dsk_appbar

    set t .dsk_appbar

    if {$win == ""} {
	set win $t.b$butnum
    }

    set geom [split [wm geometry $t] x+]
    set tw [lindex $geom 0]
    set th [lindex $geom 1]
#    set bx [lindex $geom 2]
#    set by [lindex $geom 3]
    set bgeom [split [winfo geometry $win] x+]
    set bw [lindex $bgeom 0]
    set bh [lindex $bgeom 1]
    set bx [winfo rootx $win]
    set by [winfo rooty $win]
    set sw [winfo screenwidth $t]
    set sh [winfo screenheight $t]
    set mw [winfo reqwidth $t.m$butnum]
    set mh [winfo reqheight $t.m$butnum]

    if {$tw > $th} {
	# horizontal layout
	set x [winfo rootx $win]
	if {$by > ($sh >> 1)} {
	    set y [expr $by - $mh]
	} else {
	    set y [expr $by + $bh]
	}
    } else {
	# vertical layout
	set y [winfo rooty $win]
	if {$bx > ($sw >> 1)} {
	    set x [expr $bx - $mw]
	} else {
	    set x [expr $bx + $bw]
	}
    }

    #cb_MenuPopupAdd $t.b$butnum 3 $t.m$butnum {} {} 1 $x $y 1
    update
    set dsk_appbar(lastbut) $win
    tk_popup $t.m$butnum $x $y
}

set dsk_appbar(motion) 0
proc _appbar_motion {lastnum x y {win ""}} {
    global dsk_appbar

    if $dsk_appbar(motion) return
    set dsk_appbar(motion) 1
    set t .dsk_appbar
    set new [winfo containing $x $y]
    
    if {$new != $dsk_appbar(lastbut)} {
	if {[string match $t.b* $new] && [winfo class $new] == "Button"} {
	    scan $new "$t.b%d" num
	    if [info exists num] {
		$t.m$lastnum unpost
		_appbar_show_menu $num $x $y
	    }
	} else {
	    catch {set num $dsk_appbar(num,$new)}
	    if [info exists num] {
		$t.m$lastnum unpost
		_appbar_show_menu $num $x $y $win
	    }
	}
    }
    set dsk_appbar(motion) 0
}


#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_close
# Args:		none
# Returns: 	""
# Desc:		Removes the application bar.
# Side-FX:	none
#

proc _appbar_close {} {
    global tkdesk

    if {[dsk_active viewer] != 0} {
	if [winfo exists .dsk_appbar] {
	    set tkdesk(geometry,dsk_appbar) [wm geometry .dsk_appbar]
	    destroy .dsk_appbar
	}
    } else {
	cb_info "The application bar cannot be closed because there is no file browser window on screen."
    }
    dsk_Common :: adjustAppBarMenuEntry 0
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_raise
# Args:		none
# Returns: 	""
# Desc:		Raises the application bar.
# Side-FX:	none
#

proc _appbar_raise {} {
    global tkdesk

    if [winfo exists .dsk_appbar] {
    	raise .dsk_appbar
    }
}

proc _appbar_auto_raise {} {
    global tkdesk

    if [winfo exists .dsk_appbar] {
	if $tkdesk(appbar,autoraise) {
	    raise .dsk_appbar
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_lower
# Args:		none
# Returns: 	""
# Desc:		Lowers the application bar.
# Side-FX:	none
#

proc _appbar_lower {} {
    global tkdesk

    if [winfo exists .dsk_appbar] {
    	lower .dsk_appbar
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_layout
# Args:		orient		orientation: horizontal or vertical
# Returns: 	""
# Desc:		Repacks the buttons of the appbar accordingly to $orient.
# Side-FX:	none
#

proc _appbar_layout {orient} {
    global dsk_appbar tkdesk

    if ![winfo exists .dsk_appbar] return

    if !$dsk_appbar(is_visible) {
	_appbar_toggle_vis
    }

    if {$orient == "horizontal"} {
	set side left
	set fside top
	set dsk_appbar(layout) horizontal
	if {[winfo exists .dsk_appbar.bDrag]} {
	    pack config .dsk_appbar.bDrag -padx 0 -pady 0 -fill y -side $side
	}
    } else {
	set side top
	set fside left
	set dsk_appbar(layout) vertical
	if {[winfo exists .dsk_appbar.bDrag]} {
	    pack config .dsk_appbar.bDrag -padx 0 -pady 0 -fill x -side $side
	}
    }

    foreach obj [winfo children .dsk_appbar] {
	if {[winfo class $obj] == "Button" || \
		[winfo class $obj] == "AppDate" || \
		[winfo class $obj] == "AppLoad"} {
	    if {[winfo class $obj] == "AppDate"} {
		_appbar_date "" $side
		catch {_appbar_bind_date $dsk_appbar(date,countval)}
	    } elseif {[winfo class $obj] == "AppLoad"} {
		_appbar_load "" $side
		catch {_appbar_bind_load $dsk_appbar(load,countval)}
	    }
	    pack config $obj -side $side
	} elseif {[winfo class $obj] == "Frame"} {
	    pack config $obj -side $fside
	} elseif {[winfo class $obj] == "Label"} {
	    pack config $obj -side $side -fill both
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_move
# Args:		none
# Returns: 	""
# Desc:		Displays a hand cursor to move the appbar around.
# Side-FX:	none
#

proc _appbar_move {{where ""}} {
    global dsk_appbar tkdesk cb_tools

    if {$where != ""} {
	switch $where {
	    topleft {
		wm geometry .dsk_appbar +0+0
	    }
	    bottomleft {
		wm geometry .dsk_appbar +0-0
	    }
	    topright {
		wm geometry .dsk_appbar -0+0
	    }
	    bottomright {
		wm geometry .dsk_appbar -0-0
	    }
	}
	return
    }

    if {[winfo depth .] != 1} {
	set cc [cb_col $tkdesk(color,drag)]
    } else {
	set cc white
    }

    catch "unset dsk_appbar(released)"
	catch {destroy .dsk_appbar._Busy}
    foreach but [winfo children .dsk_appbar] {
	if {[winfo class $but] != "Button"} continue
	
	$but config -cursor "@$tkdesk(library)/images/xbm/hand.xbm \
			$tkdesk(library)/images/xbm/hand.mask.xbm \
			[cb_col $tkdesk(color,foreground)] $cc"
	bind appmove <B1-Motion> {
		wm geometry .dsk_appbar +[expr %X - $dsk_appbar(mx)]+[expr %Y - $dsk_appbar(my)]; break}
	bind appmove <ButtonRelease-1> {set dsk_appbar(released) 1; break}
	bind appmove <ButtonPress-1> {
	    set dsk_appbar(mx) [expr %X - [winfo rootx .dsk_appbar]]
	    set dsk_appbar(my) [expr %Y - [winfo rooty .dsk_appbar]]
	    break
	}
	bindtags $but "appmove"
    }

    set cbbh $cb_tools(balloon_help)
    set cb_tools(balloon_help) 0
    set gl [split [wm geometry .dsk_appbar] x+]
    ot_warp_pointer [expr [lindex $gl 2] + 16] [expr [lindex $gl 3] + 16]
    grab -global .dsk_appbar
    tkwait variable dsk_appbar(released)
    grab release .dsk_appbar
    set cb_tools(balloon_help) $cbbh

    catch "unset dsk_appbar(released)"
    foreach but [winfo children .dsk_appbar] {
	if {[winfo class $but] != "Button"} continue
	
	$but config -cursor top_left_arrow
	bindtags $but "appbar $but Button all"
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_appbar_bind_special
# Args:		widgets count args
# Returns: 	""
# Desc:		Binds the widget of a "special" appbar button.
# Side-FX:	none
#

proc _appbar_bind_special {widgets count mw} {
    global dsk_appbar

    foreach w $widgets {
	bind $w	<ButtonPress-1> "$mw config -relief sunken"
	bind $w	<ButtonRelease-1> \
		"$dsk_appbar(defaction); $mw config -relief raised"
	bind $w	<3> "_appbar_show_menu $count %X %Y $mw"
	bindtags $w "appbar $w [winfo class $w] all"
    }
    foreach w $widgets {
	cb_balloonHelp $w $dsk_appbar(deflabel)
	if {$dsk_appbar(ddaction) != ""} {
	    blt_drag&drop target $w handler file \
		    "_appbar_dd_action \"$dsk_appbar(ddaction)\" %v"
	}
    }
}

# ----------------------------------------------------------------------------
# _appbar_bind_global:
# Adds bindings to the widget which apply to all widgets in the appbar
# (most of which are accessed by pressing Meta and mousebutton simultaneously.
#
proc _appbar_bind_global {} {

    bind appbar <Alt-Button-1> {
	_appbar_bind_global_b1 %W %X %Y
	break
    }
    bind appbar <Meta-Button-1> [bind appbar <Alt-Button-1>]
    bind appbar <B1-Motion> {
	if [info exists dsk_appbar(mx)] {
	    wm geometry .dsk_appbar +[expr %X - $dsk_appbar(mx)]+[expr %Y - $dsk_appbar(my)]
	}
	break
    }
    bind appbar <Alt-B1-Motion> {
	wm geometry .dsk_appbar +[expr %X - $dsk_appbar(mx)]+[expr %Y - $dsk_appbar(my)]
	break
    }
    bind appbar <Meta-B1-Motion> [bind appbar <Alt-B1-Motion>]
    bind appbar <ButtonRelease-1> {
	if [info exists dsk_appbar(mx)] {
	    unset dsk_appbar(mx)
	    unset dsk_appbar(my)
	    set cb_tools(balloon_help) $dsk_appbar(tmp_bh)
	    %W config -cursor top_left_arrow
	    #break
	}
    }

    # Quick Menus:
    bind appbar <Alt-Button-2> {
	tk_popup .dsk_appbar.qmConfig [expr %X + 1] [expr %Y + 1]
	break
    }
    bind appbar <Meta-Button-2> [bind appbar <Alt-Button-2>]
    bind appbar <Alt-Button-3> {
	tk_popup .dsk_appbar.qmAppbar [expr %X + 1] [expr %Y + 1]
	break
    }
    bind appbar <Meta-Button-3> [bind appbar <Alt-Button-3>]

    # work around bug (?) in Tk 4.0/4.1:
    bind appbar <Button-1> {
	if {%s == 8} {
	    set dsk_appbar(tmp_bh) $cb_tools(balloon_help)
	    set cb_tools(balloon_help) 0
	    set dsk_appbar(mx) [expr %X - [winfo rootx .dsk_appbar]]
	    set dsk_appbar(my) [expr %Y - [winfo rooty .dsk_appbar]]
	    %W config -cursor "@$tkdesk(library)/images/xbm/hand.xbm \
		    $tkdesk(library)/images/xbm/hand.mask.xbm \
		    [cb_col $tkdesk(color,foreground)] $tkdesk(color,drag)"
	    raise .dsk_appbar
	    break
	}
    }
    bind appbar <Button-2> {
	if {%s == 8} {
	    tk_popup .dsk_appbar.qmConfig [expr %X + 1] [expr %Y + 1]
	    break
	}
    }
    bind appbar <Button-3> {
	if {%s == 8} {
	    tk_popup .dsk_appbar.qmAppbar [expr %X + 1] [expr %Y + 1]
	    break
	}
    }
}

proc _appbar_bind_global_b1 {W X Y} {
    global dsk_appbar cb_tools tkdesk
    
    set dsk_appbar(tmp_bh) $cb_tools(balloon_help)
    set cb_tools(balloon_help) 0
    set dsk_appbar(mx) [expr $X - [winfo rootx .dsk_appbar]]
    set dsk_appbar(my) [expr $Y - [winfo rooty .dsk_appbar]]
    $W config -cursor "@$tkdesk(library)/images/xbm/hand.xbm \
	    $tkdesk(library)/images/xbm/hand.mask.xbm \
	    [cb_col $tkdesk(color,foreground)] $tkdesk(color,drag)"
    raise .dsk_appbar
}


# -----------------------------------------------------------------------------
# _appbar_get_button_width:
# Returns the width of the first button in the appbar - 4. This should
# correspond to the width of the associated pixmap.
#
proc _appbar_get_button_width {} {
    global tkdesk

    set w 32
    for {set i 0} {$i < [llength $tkdesk(appbar)]} {incr i} {
	if [winfo exists .dsk_appbar.b$i] {
	    #update idletasks
	    set w [expr [winfo reqwidth .dsk_appbar.b$i] - 4]
	    break
	}
    }
    return $w
}

# -----------------------------------------------------------------------------
# dsk_appbar_adjgeom geom:
# Swaps width and height info in $geom if appbar is currently minimized.
# (Called from config.tcl:save__layout)
#
proc dsk_appbar_adjgeom {geom} {
    global dsk_appbar

    if !$dsk_appbar(is_visible) {
	set gl [split $geom "x+-"]
	set pi [string first "+" $geom]
	set pi2 [string first "-" $geom]
	if {$pi2 > -1 && ($pi2 < $pi || $pi < 0)} {set pi $pi2}
	set geom [lindex $gl 1]x[lindex $gl 0][string range $geom $pi 1000]
	dsk_debug "geom: $geom"
    }
    return $geom
}
