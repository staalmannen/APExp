# =============================================================================
#
# File:		dsk_Listbox.tcl
# Project:	TkDesk
#
# Started:	07.10.94
# Changed:	09.10.94
# Author:	cb
#
# Description:	Implements a generic listbox widget, complete with scrollbar,
#		multiselection and tags.
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
#s    itcl_class dsk_Listbox
#s    method config {config} { 
#s    method textconfig {args}
#s    method sbconfig {args}
#s    method top {{line ""}}
#s    method get {{index ""}}
#s    method tag {cmd args}
#s    method select {cmd args}
#s    method _sel_entry {index}
#s    method _unsel_entry {index}
#s    method _sel_toggle {index}
#s    method _sel_toggle_all {}
#s    method _sel_first {index}
#s    method _sel_to {index {keep 0}}
#s    method _sel_get {tagname}
#s    method _sel_clear {}
#s    method _sel_drag {cmd {keep 0} {w ""} {x ""} {y ""}}
#s    method _sel_for_dd {index}
#s    method _dd_start {x y}
#s    method _dd_end {x y min}
#s    method _last_entry {index}
#s    method _yview {line}
#s    method _winunits {}
#s    method _resizeit {}
#s    method _pack_sb {{do_pack 0}}
#s    method show_hsb {show}
#s    proc autoscrollbar {{activate ""}}
#s    proc selcolor {color}
#s    proc modifier {use_old}
#
# =============================================================================

#
# =============================================================================
#
# Class:	dsk_Listbox
# Desc:		Generic listbox metawidget.
#
# Methods:	config ?options?	for options see Publics
#		textconfig ?options?	config for text widget (redundant)
#		sbconfig ?options?	config for scrollbar (redundant)
#		top ?line?		return or make line the first visible
#		get ?index?			returns the current list
#		select <list>		select all entries in <list>
#		select clear		clear selection
#		select get		return list of selected entries
#		tag <option> <args>	options are the same as for a text
#					widget, indices are listbox entries
#					(add and remove accept lists)
# Procs:	autoscrollbar ?bool?	dis-/enable automatic packing of sb
# Publics:	pad <int>		padding of the widgets (default 4)
#		list <list>		list for listbox (default {})
#		mode <single|multi>	selection mode
#		font			font for text widget
#		width			width of text widget
#		height			height of text widget
#		seltag			config of the selection tag
#		callback <proc>		<proc> will be called after double-
#					clicks. 
#					<proc> receives the following args:
#						object	name of sending obj
#						sel	selection list
#

itcl_class dsk_Listbox {
    inherit Frame

    constructor {args} {
	global tkdesk

	if {$tkdesk(tcl_version) < 8.0} {
	    Frame::constructor
	}
	
        scrollbar $frame.sb -relief sunken -command "$frame.text yview"
        scrollbar $frame.hsb -relief sunken -command "$frame.text xview" \
		-orient horizontal

        text $frame.text -wrap none -relief sunken -borderwidth 2 \
                -yscrollcommand "$frame.sb set" -width $width -height $height \
                -cursor top_left_arrow -setgrid 1 -padx 2 \
		-highlightthickness 0 -takefocus 0 -insertwidth 0 \
		-xscrollcommand "$frame.hsb set" \
		-exportselection 0 -bg $bg -fg $fg
	
	if {[winfo depth .] == 1} {
	    $frame.text config -background white
	}

	eval $frame.text tag config seltag $seltag_options
	eval $frame.text tag config annotag $annotag_options

	frame $frame.lframe -width $pad
	frame $frame.rframe -width $pad
	frame $frame.tframe -height $pad
	frame $frame.bsframe -height $pad
	#frame $frame.corner -width [expr $pad * 2 + 19]
	#frame $frame.fhs

	bindtags $frame.text "$frame.text MouseWheelEnabled all"
	
        bind $frame.text <1> "
	    focus [winfo toplevel $frame]
	    $this select clear
	    $this select @%x,%y
	    $this _sel_first @%x,%y
	"
	bind $frame.text <${mod_extend}-1> "$this _sel_to @%x,%y"
        bind $frame.text <B1-Motion> "$this _sel_to @%x,%y"
	bind $frame.text <B1-Leave> \
		"$this _sel_drag start \[expr %s != 256\] %W %x %y"
	bind $frame.text <B1-Enter> "$this _sel_drag stop"
	bind $frame.text <ButtonRelease-1> "$this _sel_drag stop"
	bind $frame.text <Shift-ButtonRelease-1> "$this _sel_drag stop"
	bind $frame.text <Control-ButtonRelease-1> "$this _sel_drag stop"
	set drag(afterId) {}
        bind $frame.text <Double-1> "
	    set tmp_cb \[$this info public callback -value\]
	    if {\$tmp_cb != \"\"} {
		eval \$tmp_cb $this \[$this select get\]
	    }
	"
        bind $frame.text <Triple-1> {break}

        bind $frame.text <${mod_toggle}-1> "
	    $this _sel_toggle @%x,%y
	    $this _sel_first @%x,%y
	"

        bind $frame.text <${mod_toggle}-B1-Motion> "$this _sel_to @%x,%y 1"
	# the following is hard-coded to Shift as <Control-Double-1>
	# is already used elsewhere
        bind $frame.text <Shift-Double-1> "$this _sel_toggle_all"
        bind $frame.text <Any-Key> {break}

	# enable (un)packing of scrollbar after resizing:
	bind $frame.text <Configure> \
		"after 200 \{catch \"$this _pack_sb\"\}; break"
	set autosb 1

	frame $frame.bframe
	pack $frame.bframe -side bottom -fill x
	frame $frame.corner \
		-width [expr $pad * 2 + [$frame.sb cget -width]]
	pack $frame.corner -in $frame.bframe -side $sbside -fill y
	pack $frame.hsb -in $frame.bframe -side left \
		-padx $pad -pady $pad -fill x -expand 1
	raise $frame.hsb
	raise $frame.corner
	
	if {$sbside == "right"} {
	    pack $frame.tframe -side top -fill x
	    pack $frame.lframe -side left -fill y
	    pack $frame.text -side left -fill both -expand yes
	    pack $frame.sb -side left -padx $pad -fill y
	} else {
	    pack $frame.tframe -side top -fill x
	    pack $frame.lframe -side right -fill y
	    pack $frame.text -side right -fill both -expand yes
	    pack $frame.sb -side right -padx $pad -fill y
	}
	
	eval config $args
	update ;# idletasks
    }

    destructor {
        #after 10 "rename $this-frame {}"		;# delete this name
        #catch {destroy $this}		;# destroy associated window
    }

    #
    # ----- Methods and Procs -------------------------------------------------
    #

    method config {config} { 
    }

    method textconfig {args} {
	eval $frame.text config $args
    }

    method sbconfig {args} {
	eval $frame.sb config $args
    }

    method top {{line ""}} {
	# this makes line $line the first visible entry in the listbox
	# or returns its index

	if {$line == ""} {
	    return [lindex [cb_old_sb_get $frame.sb] 2]
	}

	if {$line >= 0 && $line < [llength $list]} {
	    $frame.text yview $line
	}
    }

    method get {{index ""}} {
	if {$index == ""} {
	    return $list
	} else {
	    return [lindex $list $index]
	}
    }

    method tag {cmd args} {
	set tagname [lindex $args 0]
	set entry [lindex $args 0]
	set elist [lindex $args 1]
	set tagargs [lrange $args 1 [llength $args]]

	switch -glob -- $cmd {
	    add		{
		set i 0
		foreach e $elist {
		    $frame.text tag add $tagname \
			    [expr $e + 1].0 [expr $e + 2].0
		}
	    }
	    bind	{return [eval $frame.text tag bind $tagname $tagargs]}
	    conf*	{
		for {set i 0} {$i < [llength $tagargs]} {incr i 2} {
		    set err [catch {
			$frame.text tag config $tagname \
				[lindex $tagargs $i] \
				[lindex $tagargs [expr $i + 1]]
		    } errmsg]
		    if $err {
			catch {puts stderr "tkdesk: $errmsg"}
		    }
		}
	    }
	    del*	{eval $frame.text tag delete $tagname $tagargs}
	    lower	{eval $frame.text tag lower $tagname $tagargs}
	    names	{return [$frame.text tag names \
				[expr $entry + 1].0 ]
			}
	    nextrange	{error "nextrange is not implemented. Sorry."}
	    raise	{eval $frame.text tag raise $tagname $tagargs}
	    ranges	{return [$this _sel_get $tagname]}
	    remove	{foreach e $elist {
			    $frame.text tag remove $tagname \
				[expr $e + 1].0 [expr $e + 2].0
			}}
	}
    }

    method select {cmd {labels ""} {invert 0}} {
	set sellist ""
	switch -glob -- $cmd {
	    clear {
		$this _sel_clear
	    }
	    get	{
		return [$this _sel_get seltag]
	    }
	    getnames {
		set n ""
		foreach s [_sel_get seltag] {
		    set f [lindex [split [lindex $list $s] \t] 0]
		    lappend n [string range $f 0 [expr [string length $f] - 2]]
		}
		return $n
	    }
	    first {
		if {[llength $list] > 0} {
		    _sel_clear
		    _sel_entry 0
		    $frame.text see 1.0
		} else {
		    dsk_bell
		}
	    }
	    last {
		if {[llength $list] > 0} {
		    _sel_clear
		    _sel_entry [set fs [expr [llength $list] - 1]]
		    $frame.text see [expr $fs + 1].0
		} else {
		    dsk_bell
		}
	    }
	    up {
		set fs [lindex [select get] 0]
		if {$fs == ""} {
		    set fs [expr [llength $list] - 1]
		} else {
		    set fs [expr $fs - 1]
		    if {$fs <= 0} {
			#set fs [expr [llength $list] - 1]
			set fs 0
		    }
		}
		_sel_clear
		_sel_entry $fs
		$frame.text see [expr $fs + 1].0
	    }
	    down {
		set fs [lindex [select get] 0]
		if {$fs == ""} {
		    set fs 0
		} else {
		    set fs [expr $fs + 1]
		    if {$fs >= [llength $list]} {
			#set fs 0
			set fs [expr [llength $list] - 1]
		    }
		}
		_sel_clear
		_sel_entry $fs
		$frame.text see [expr $fs + 1].0
	    }
	    pgup {
		if {[set ll [llength $list]] > 0} {
		    set fs [lindex [select get] 0]
		    if {$fs == ""} {set fs 0}
		    ot_maplist [cb_old_sb_get $frame.sb] tot win f l
		    set fs [incr fs -[expr $win -1]]
		    if {$fs < 0} {
			set fs 0
		    }
		    _sel_clear
		    _sel_entry $fs
		    $frame.text see [expr $fs + 1].0
		} else {
		    dsk_bell
		}
	    }
	    pgdown {
		if {[set ll [llength $list]] > 0} {
		    set fs [lindex [select get] 0]
		    if {$fs == ""} {set fs 0}
		    ot_maplist [cb_old_sb_get $frame.sb] tot win f l
		    set fs [incr fs [expr $win -1]]
		    if {$fs >= $ll} {
			set fs [expr $ll -1]
		    }
		    _sel_clear
		    _sel_entry $fs
		    $frame.text see [expr $fs + 1].0
		} else {
		    dsk_bell
		}
	    }
	    letter {
		set l $labels
		set fe -1
		set fs [lindex [select get] 0]
		if {$fs == ""} {set fs -1}
		#puts "fs: $fs"
		_sel_clear

		# [todo] reverse search direction if $invert
		for {set i [expr $fs +1]} {$i < [llength $list]} {incr i} {
		    set le [lindex $list $i]
		    if [regexp -nocase "^$l" $le] {
			set fe $i
			_sel_entry $i
			break
		    }
		}
		if {$fe == -1} {
		    for {set i 0} {$i < $fs} {incr i} {
			set le [lindex $list $i]
			if [regexp -nocase "^$l" $le] {
			    set fe $i
			    _sel_entry $i
			    break
			}
		    }
		}
		
		#puts "fe: $fe"
		if {$fe > -1} {
		    $frame.text see [expr $fe + 1].0
		} else {
		    dsk_bell
		}
	    }
	    name {
		_sel_clear
		if $invert {
		    _sel_toggle_all
		}
		set fe -1
		foreach n $labels {
		    set e 0
		    foreach le $list {
			set fn [lindex [split $le \t] 0]
			if [string match ${n}? $fn] {
			    if !$invert {
				_sel_entry $e
				if {$fe == -1} {
				    set fe $e
				}
			    } else {
				_unsel_entry $e
			    }
			}
			incr e
		    }
		}
		if {$fe > -1} {
		    $frame.text see [expr $fe + 1].0
		}
	    }
	    default {
		# cmd is a list of entry numbers
		set sellist $cmd
		foreach entry $sellist {
		    $this _sel_entry $entry
		}
	    }
	}
    }

    method get_entry_at {x y} {
	set s [expr int([$frame.text index @$x,$y]) - 1]
	set f [lindex [split [lindex $list $s] \t] 0]
	return [string range $f 0 [expr [string length $f] - 2]]
    }

    method _sel_entry {index} {
	if {[string index $index 0] == "@" || \
		[regexp {^[1-90]+\.[1-90]$} $index]} {
	    if ![_last_entry $index] {
		$frame.text tag add seltag "$index linestart" \
			"$index + 1 lines linestart"
	    }
	} else {
	    if {$index >= 0 && $index < [llength $list]} {
	    	$frame.text tag add seltag [expr $index + 1].0 \
			[expr $index + 2].0
	    }
	}
	set sel_select 1
    }

    method _unsel_entry {index} {
	if {[string index $index 0] == "@" || \
		[regexp {^[1-90]+\.[1-90]$} $index]} {
	    $frame.text tag remove seltag "$index linestart" \
					"$index + 1 lines linestart"
	} else {
	    $frame.text tag remove seltag [expr $index + 1].0 \
						[expr $index + 2].0
	}
	set sel_select 0
    }

    method _sel_toggle {index} {
	# is bound to <${mod_toggle}-1>
	if {$mode == "single"} {
	    return
	}
	
	if {[string index $index 0] != "@" && \
		![regexp {^[1-90]+\.[1-90]$} $index]} {
	    set index [expr $index + 1].0
	}

	if [_last_entry $index] return

	if {[lsearch [$frame.text tag names $index] "seltag"] > -1} {
	    $this _unsel_entry $index
	    set was_selected 1
	} else {
	    $this _sel_entry $index
	    set was_selected 0
	}
    }

    method _sel_toggle_all {} {
	if {$mode != "single"} {
	    if {$was_selected} {
		$this select clear
	    } else {
		if $has_dots {
		    $frame.text tag add seltag 3.0 "end - 1 lines"
		} else {
		    $frame.text tag add seltag 1.0 "end - 1 lines"
		}
	    }
	}
    }

    method _sel_first {index} {
	# index has the form @%x,%y !
	# But I'm looking for the line number; that's what the hack 
	# below is for.

	if {[string index $index 0] == "@" || \
		[regexp {^[1-90]+\.[1-90]$} $index]} {
	    $frame.text tag add pos \
		    "$index linestart" "$index + 1 lines linestart"
	    set sel_start [lindex [$frame.text tag ranges pos] 0]
	    $frame.text tag remove pos "$index linestart" \
		    "$index + 1 lines linestart"
	} else {
	    set sel_start [expr $index + 1].0
	}
	if [_last_entry $sel_start] {
	    set sel_start [$frame.text index "end - 2 lines"]
	}

	if {$sel_start == ""} {
	    set sel_start [llength $list].0
	}
    }

    method _sel_to {index {keep 0}} {
	# is bound to <B1-Motion> ==> index has the form @x,y

	if {$mode == "single"} {
	    $this _sel_clear
	    $this _sel_entry $index
	} else {
	    #
	    #  @x,y ==> line.char:
	    #
	    if [_last_entry $index] return
	    if {$sel_start == ""} return
	    
	    set sel_end [$frame.text index "$index linestart"]

	    if [$frame.text compare $sel_start < $sel_end] {
		if {!$keep && $sel_select} {
	    	    $frame.text tag remove seltag 1.0 "$sel_start"
	    	    $frame.text tag remove seltag "$sel_end + 1 lines" end
		}
		if $sel_select {
	    	    $frame.text tag add seltag "$sel_start" "$sel_end + 1 lines"
		} else {
	    	    $frame.text tag remove seltag "$sel_start" \
					"$sel_end + 1 lines"
		}
	    } else {
		if {!$keep && $sel_select} {
	    	    $frame.text tag remove seltag 1.0 "$sel_end"
	    	    $frame.text tag remove seltag "$sel_start + 1 lines" end
		}
		if $sel_select {
	    	    $frame.text tag add seltag "$sel_end" "$sel_start + 1 lines"
		} else {
	    	    $frame.text tag remove seltag "$sel_end" \
					"$sel_start + 1 lines"
		}
	    }
	}
    }

    method _sel_get {tagname} {
	set sel ""
	set range [$frame.text tag ranges $tagname]
	for {set i 0} {$i < [llength $range]} {incr i} {
	    set from [expr int([lindex $range $i]) - 1]
	    incr i
	    set to [expr int([lindex $range $i]) - 1]
	    for {set j $from} {$j < $to} {incr j} {
		lappend sel $j
	    }
	}

	return $sel
    }

    method _sel_clear {} {
	$frame.text tag remove seltag 1.0 end
    }

    method _sel_drag {cmd {keep 0} {w ""} {x ""} {y ""} {dontsel 0}} {
	if {$cmd == "start"} {
	    set drag(x) $x
	    set drag(y) $y
	} elseif {$drag(afterId) == ""} {
	    return
	}

	
	if {$cmd == "start" || $cmd == "cont"} {
	    if {$drag(y) >= [winfo height $w]} {
		$w yview scroll 2 units
	    } elseif {$drag(y) < 0} {
		$w yview scroll -2 units
	    } elseif {$drag(x) >= [winfo width $w]} {
		$w xview scroll 2 units
	    } elseif {$drag(x) < 0} {
		$w xview scroll -2 units
	    } else {
		return
	    }
	    if {!$dontsel} {
		_sel_to @$drag(x),$drag(y) $keep
	    }
	    set drag(afterId) [after $sel_drag_delay \
		    $this _sel_drag cont $keep $w {} {} $dontsel] 
	} else {
	    after cancel $drag(afterId)
	    set drag(afterId) {}
	}
    }

    method _sel_for_dd {index} {
	# index has the form @x,y

	if {[string index $index 0] != "@" && \
		![regexp {^[1-90]+\.[1-90]$} $index]} {
	    set index [expr $index + 1].0
	}
	if {[lsearch [$frame.text tag names $index] "seltag"] == -1} {
	    $this select clear
	    if ![_last_entry $index] {
		$this select $index
		$this _sel_first $index
		#puts "selected $index"
	    }
	}
    }

    method _dd_start {x y} {
	global tkdesk
	
	set tkdesk(_dd_x) $x
	set tkdesk(_dd_y) $y
    }

    method _dd_end {x y min} {
	global tkdesk
	
	#puts "$x/$_dd_x, $y/$_dd_y, $min"
	if {(abs($x - $tkdesk(_dd_x)) >= $min) || \
		(abs($y - $tkdesk(_dd_y)) >= $min)} {
	    return 1
	} else {
	    return 0
	}
    }

    method _last_entry {index} {
	# tests if $index points to the last (empty) entry
	set ec [$frame.text get "$index linestart" "$index + 1 lines linestart"]
	if {$ec == "\n"} {
	    return 1
	} else {
	    return 0
	}
    }

    method _yview {line} {
	set size [$this _winunits]
	if {[expr $line + $size - 1] <= [llength $list]} {
	    $frame.text yview $line
	} else {
	    $frame.text yview [expr [llength $list] - $size + 1]
	}
    }

    method _winunits {} {
	# try to get window size thru scrollbar:
	set window_units [lindex [cb_old_sb_get $frame.sb] 1]
	if {$window_units == 0} {
	    # window's not visible yet
	    set window_units [lindex [$frame.text config -height] 4]
	}
	return $window_units
    }

    method _resizeit {} {
	# try to get window size thru scrollbar:
	update idletasks
	ot_maplist [cb_old_sb_get $frame.sb] tot win f l
	if {$tot > $win} {
	    return 1
	} else {
	    return 0
	}
    }

    method _pack_sb {{do_pack 0}} {
	global tkdesk
	
	if $_pack_sb_working {
	    return
	}
	set _pack_sb_working 1

	if {$do_pack || !$tkdesk(dynamic_scrollbars)} {
	    if !$sb_packed {
	    	pack forget $frame.rframe
	        pack $frame.sb -side left -padx $pad -fill y
		pack $frame.corner -in $frame.bframe -side $sbside -fill y \
			-before $frame.hsb
		raise $frame.corner
		set sb_packed 1
	    }
	    set _pack_sb_working 0
	    return
	}

	if [_resizeit] {
	    if !$sb_packed {
	    	pack forget $frame.rframe
	    	pack $frame.sb -side left -padx $pad -fill y
		pack $frame.corner -in $frame.bframe -side $sbside -fill y \
			-before $frame.hsb
		raise $frame.corner
	    	set sb_packed 1
	    }
	} elseif $sb_packed {
	    pack forget $frame.sb
	    pack $frame.rframe -side left -fill y
	    pack forget $frame.corner
	    set sb_packed 0
	}
	set _pack_sb_working 0
    }

    method show_hsb {show} {
	global tkdesk
	
	#puts "show_hsb: $show"
	if {$show || !$tkdesk(dynamic_scrollbars)} {
	    pack forget $frame.bsframe
	    pack $frame.hsb -in $frame.bframe -side left \
		    -padx $pad -pady $pad -fill x -expand 1
	} else {
	    pack forget $frame.hsb
	    pack $frame.bsframe -in $frame.bframe -side left -fill x -expand 1
	}
    }

    method getText {} {
	return $frame.text
    }

    proc autoscrollbar {{activate ""}} {
	if {$activate == ""} {
	    return $autosb
	}
	if {$activate == $autosb} {
	    return $autosb
	}

	set autosb $activate
	if $autosb {
	    # (un)packing of the sb while resizing works not too well:
	    foreach this [itcl_info objects -class dsk_Listbox] {
	    	bind $frame.text <Configure> \
			"after 200 \{catch \"$this _pack_sb\"\}; break"
	    	$this _pack_sb
	    }
	} else {
	    foreach this [itcl_info objects -class dsk_Listbox] {
	        bind $frame.text <Configure> {break}
		$this _pack_sb 1
	    }
	}
    }

    proc selcolor {color} {
	if {[winfo depth .] != 1} {
	    set seltag_options "-borderwidth 0 -background $color"
	} else {
	    set seltag_options "-borderwidth 0 \
			-foreground white -background black"
	}
    }

    proc modifier {use_old} {
	if $use_old {
	    set mod_toggle "Shift"
	    set mod_extend "Control"
	} else {
	    set mod_toggle "Control"
	    set mod_extend "Shift"
	}
    }

    proc scrollbarside {side} {
	set sbside $side
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    public pad 4 {
	pack $frame.hsb -side bottom -padx $pad -pady $pad -fill x
	if {$sb_packed} {
	    pack $frame.sb -side left -padx $pad -fill y
	}
	$frame.lframe config -width $pad
	$frame.rframe config -width $pad
	$frame.tframe config -height $pad
	if {$pad > 0} {
	    $frame config -bd 1
	} else {
	    $frame config -bd 0
	}
    }

    public list {} {

	$frame.text delete 1.0 end
	foreach entry $list {
	    $frame.text insert end "$entry\n"
	}

	if $autosb {
	    after 200 "catch \"$this _pack_sb\""
	}
    }

    public listtext {} {

	# substitute \t:
	#set list [subst -nocommands -novariables $list]
	#set list [dskC_unesc $list]
	#set list [string_replace $list \\t \t]
	#puts $list\n
	
	$frame.text delete 1.0 end
	$frame.text insert end $listtext
    }

    public font fixed {
	$frame.text config -font [cb_font $font]
    }

    public width 20 {
	$frame.text config -width $width
    }

    public height 10 {
	$frame.text config -height $height
    }

    public bg \#d9d9d9 {
	if {[winfo depth .] > 1} {
	    $frame.text config -background $bg
	}
    }

    public fg black {
	if {[winfo depth .] > 1} {
	    $frame.text config -foreground $fg
	}
    }

    public seltag {} {
	eval $frame.text tag config seltag $seltag
    }

    public mode "multi"
    public callback ""
    public has_dots 0

    # this is only for internal use
    public stop_dragging 1

    protected sb_packed 1
    protected _pack_sb_working 0
    protected sel_start ""
    protected sel_select ""
    protected was_selected 0
    protected drag
    set drag(afterId) ""

    common mod_toggle
    common mod_extend
    common sbside

    common autosb 0
    common seltag_options {-borderwidth 0 -background white}
    common annotag_options {-underline 1}
    common sel_drag_delay 80
}


