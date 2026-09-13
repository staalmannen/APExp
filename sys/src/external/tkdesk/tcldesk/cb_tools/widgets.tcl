# =============================================================================
#
# File:		cb-widgets.tcl
# Project:	cb-tools
# Started:	28.06.94
# Changed:	23.09.94
#
# Description:	provides a set of compound widgets
#
# -----------------------------------------------------------------------------
#
# Sections:
#	proc cb_button {w args}
#	proc cb_listbox {w args}
#	proc cb_text {w args}
#	proc cb_canvas {w args}
#	proc cb_menu {w mlist}
#	proc cb_menubar {w mblist}
#	proc cb_buttonbar {w blist args}
#
# =============================================================================

# -----------------------------------------------------------------------------
# cb_button: Creates the frame(!) w that contains a button.
#	Additional options: -default and -pad.

proc cb_button {w args} {

    set default 0
    set pad 1m

    frame $w -relief flat -bd 1
    button $w.button


    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    if {$o != "default"} {
	    	switch $o {
		    "pad"	{incr i; set pad [lindex $args $i]}
		    default	{incr i
				$w.button config -$o [lindex $args $i]}
	    	}
	    } else {
		incr i
		set default [lindex $args $i]
	    }
	}
    }

    if {$default} {
	$w config -relief sunken
    }
    pack $w.button -in $w -padx $pad -pady $pad -ipady 1

    return $w
}

# -----------------------------------------------------------------------------
# cb_listbox: 
#	Creates the frame w, that contains a listbox and scrollbars.
#	Possible options:
#
#	-pad int	padding of scrollbars and borders
#	-vscroll bool	include vertical scrollbar?
#	-hscroll bool	include horizontal scrollbar?
#	-lborder bool	left border?
#	-uborder bool	upper border?
#       -rbuttons bool  resize-buttons?

proc cb_listbox {w args} {
    global cb_tools tk_strictMotif

    set pad 4
    set vscroll no
    set hscroll no
    set lborder no
    set uborder no
    set rbuttons no
    set lb_args ""

    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    switch $o {
		"pad"     {incr i; set pad [lindex $args $i]}
		"vscroll" {incr i; set vscroll [lindex $args $i]}
		"hscroll" {incr i; set hscroll [lindex $args $i]}
		"lborder" {incr i; set lborder [lindex $args $i]}
		"uborder" {incr i; set uborder [lindex $args $i]}
		"rbuttons" {incr i; set rbuttons [lindex $args $i]}
		default	  {incr i
			  lappend lb_args -$o [lindex $args $i]}
	    }
	}
    }
    # puts "$pad, $vscroll, $hscroll, $lborder, $uborder, $lb_args"

    frame $w

    if {$uborder} {
	frame $w.fUBorder -height $pad
	pack $w.fUBorder -in $w -side top -fill x
    }

    if {$lborder} {
	frame $w.fLBorder -width $pad
	pack $w.fLBorder -in $w -side left -fill y
    }

    frame $w.fLeft
    pack $w.fLeft -in $w -side left  -expand yes -fill both

    listbox $w.lbox -relief sunken -exportselection false -bd 2 \
	    -highlightthickness 0 -takefocus 0
    if {$lb_args != ""} {
    	eval $w.lbox configure $lb_args
    }
    pack $w.lbox -in $w.fLeft -side top -expand yes -fill both \
	    -padx 0 -pady 0 

    if {$hscroll} {
    	scrollbar $w.hscroll -orient horizontal -command "$w.lbox xview" \
		-bd 2 -relief sunken -highlightthickness 0 \
		-takefocus 0
    	pack $w.hscroll -in $w.fLeft -side top -fill x -padx 0 -pady $pad

	$w.lbox configure -xscroll "$w.hscroll set"
    }

    if {$vscroll} {
        frame $w.fRight
        pack $w.fRight -in $w -side left -fill y -padx 0 -pady 0
        
        scrollbar $w.vscroll -command "$w.lbox yview" -bd 2 -relief sunken \
		-highlightthickness 0 -takefocus 0
        pack $w.vscroll -in $w.fRight -expand yes -fill y -padx $pad -pady 0

	$w.lbox configure -yscroll "$w.vscroll set"

	if {$rbuttons} {
	    frame $w.frbuts -height $pad
	    button $w.bUp -bitmap @$cb_tools(path)/bitmaps/up.xbm \
		    -width 14 -bd 1 -padx 0 -pady 0 -highlightthickness 0 \
		    -command "cb_listbox_resize smaller $w"
	    set bgc [lindex [$w.bUp config -bg] 4]
	    $w.bUp config -activebackground $bgc
	    button $w.bDown -bitmap @$cb_tools(path)/bitmaps/down.xbm \
		    -width 14 -bd 1 -padx 0 -pady 0 -highlightthickness 0 \
		    -command "cb_listbox_resize bigger $w"
	    $w.bDown config -activebackground $bgc

	    if !$tk_strictMotif {
		pack $w.frbuts $w.bUp $w.bDown -in $w.fRight
	    } else {
		pack $w.frbuts $w.bUp $w.bDown -in $w.fRight -ipadx 1 -ipady 1
	    }
	} elseif {$hscroll} {    
            frame $w.vcorner -height [expr $pad * 2 + 19]
            pack $w.vcorner -in $w.fRight -fill both
	}
    }

    return $w
}

proc cb_listbox_resize {how cblb} {
    set height [$cblb.lbox cget -height]

    set h 17 ;# [winfo reqheight $cblb.bUp]
    set x [winfo pointerx .]
    set y [winfo pointery .]
    
    if {$how == "smaller"} {
	incr height -1
	#set w $cblb.bUp
	incr y -$h
    } else {
	incr height
	#set w $cblb.bDown
	incr y $h
    }

    if {[info commands ot_warp_pointer] != ""} {
	#ot_warp_pointer $w
	ot_warp_pointer $x $y
    }

    #update idletasks
    $cblb.lbox config -height $height
}

# -----------------------------------------------------------------------------
# cb_text: 
#	Creates the frame w, that contains a text-widget and scrollbars.
#	Possible options:
#
#	-pad int	padding of scrollbars and borders
#	-vscroll bool	include vertical scrollbar?
#	-lborder bool	left border?
#	-uborder bool	upper border?

proc cb_text {w args} {

    set pad 4
    set hscroll no
    set vscroll no
    set lborder no
    set uborder no
    set bborder no
    set t_args ""

    frame $w


    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    switch $o {
		"pad"     {incr i; set pad [lindex $args $i]}
		"hscroll" {incr i; set hscroll [lindex $args $i]}
		"vscroll" {incr i; set vscroll [lindex $args $i]}
		"lborder" {incr i; set lborder [lindex $args $i]}
		"uborder" {incr i; set uborder [lindex $args $i]}
		"bborder" {incr i; set bborder [lindex $args $i]}
		default	  {incr i
			   lappend t_args -$o [lindex $args $i]}
	    }
	}
    }
    # puts "$pad, $vscroll, $lborder, $uborder, $t_args"

    if {$uborder} {
	frame $w.fUBorder -height $pad
	pack $w.fUBorder -in $w -side top -fill x
    }

    if {$lborder} {
	frame $w.fLBorder -width $pad
	if {$vscroll == "left"} {
	    pack $w.fLBorder -in $w -side right -fill y
	} else {
	    pack $w.fLBorder -in $w -side left -fill y
	}
    }

    if {$bborder} {
	frame $w.fBBorder -height $pad
	pack $w.fBBorder -in $w -side bottom -fill x
    }

    frame $w.fLeft

    text $w.text -relief sunken -exportselection true -bd 2
    if {$t_args != ""} {
	eval $w.text configure $t_args
    }
    pack $w.text -in $w.fLeft -side top -expand yes -fill both

    if {$hscroll} {
    	scrollbar $w.hscroll -orient horizontal -command "$w.text xview" \
		-bd 2 -relief sunken -highlightthickness 0 -takefocus 0
    	pack $w.hscroll -in $w.fLeft -side top -fill x -padx 0 -pady $pad

	$w.text configure -xscroll "$w.hscroll set"
    }

    if {$vscroll != "no"} {
	if {$vscroll != "left"} {
	    set vscroll right
	}
	
        frame $w.fRight
	pack $w.fRight -in $w -side $vscroll -fill y
        
        scrollbar $w.vscroll -command "$w.text yview" -bd 2 -relief sunken \
		-highlightthickness 0 -takefocus 0
        pack $w.vscroll -in $w.fRight -expand yes -fill y -padx $pad

	$w.text configure -yscroll "$w.vscroll set"
	
	if {$hscroll} {    
            frame $w.vcorner -height [expr $pad * 2 + 19]
            pack $w.vcorner -in $w.fRight -fill both
	}
    }

    if {$vscroll != "left"} {
	pack $w.fLeft -in $w -side right  -expand yes -fill both
    } else {
	pack $w.fLeft -in $w -side left  -expand yes -fill both
    }
    
    return $w
}

# -----------------------------------------------------------------------------
# cb_canvas: 
#	Creates the frame w, that contains a canvas and scrollbars.
#	Possible options:
#
#	-pad int	padding of scrollbars and borders
#	-vscroll bool	include vertical scrollbar?
#	-hscroll bool	include horizontal scrollbar?
#	-lborder bool	left border?
#	-uborder bool	upper border?

proc cb_canvas {w args} {

    set pad 4
    set vscroll no
    set hscroll no
    set lborder no
    set uborder no
    set c_args ""

    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    switch $o {
		"pad"     {incr i; set pad [lindex $args $i]}
		"vscroll" {incr i; set vscroll [lindex $args $i]}
		"hscroll" {incr i; set hscroll [lindex $args $i]}
		"lborder" {incr i; set lborder [lindex $args $i]}
		"uborder" {incr i; set uborder [lindex $args $i]}
		default	  {incr i
			   lappend c_args -$o [lindex $args $i]}
	    }
	}
    }
    # puts "$pad, $vscroll, $hscroll, $lborder, $uborder, $c_args"

    frame $w

    if {$uborder} {
	frame $w.fUBorder -height $pad
	pack $w.fUBorder -in $w -side top -fill x
    }

    if {$lborder} {
	frame $w.fLBorder -width $pad
	pack $w.fLBorder -in $w -side left -fill y
    }

    frame $w.fLeft
    pack $w.fLeft -in $w -side left  -expand yes -fill both

    canvas $w.canvas -relief sunken -bd 2
    if {$c_args != ""} {
    	eval $w.canvas configure $c_args
    }
    pack $w.canvas -in $w.fLeft -side top -expand yes -fill both

    if {$hscroll} {
    	scrollbar $w.hscroll -orient horizontal -command "$w.canvas xview" \
		-bd 2 -relief sunken
    	pack $w.hscroll -in $w.fLeft -side top -fill x -pady $pad

	$w.canvas configure -xscrollcommand "$w.hscroll set"
    }

    if {$vscroll} {
        frame $w.fRight
        pack $w.fRight -in $w -side left -fill y
        
        scrollbar $w.vscroll -command "$w.canvas yview" -bd 2 -relief sunken
        pack $w.vscroll -in $w.fRight -expand yes -fill y -padx $pad

	$w.canvas configure -yscrollcommand "$w.vscroll set"

	if {$hscroll} {    
            frame $w.vcorner -height [expr $pad * 2 + 19]
            pack $w.vcorner -in $w.fRight -fill both
	}
    }

    return $w
}

# -----------------------------------------------------------------------------
# cb_menu: Creates a menu by processing a list of menu entries.
#	For example:
#
#		cb_menu .mb.m {
#		    {{&First Entry} {-command {puts "Oh yeah!"}}}
#		    {{&Second Entry} {-command {puts "Oh yeah?"} \
#					-state disabled}}
#		    {-}
#		    {{c} {Cascaded &Menu} {
#			{{Do you &get it?} {-command {puts "I think so."}}}
#		    }}
#		    {{cb} {This is a &checkbutton.} {}}
#		    {{rb} {This is a &radiobutton.} {}}
#		}

set cb_menu(rlevel) 0

proc cb_menu {w mlist} {
    global cb_menu

    menu $w

    set enum -1
    foreach me $mlist {
	incr enum
	if {$me == "-"} {
	    $w add separator
	    continue
	}

	if {[llength $me] == 2} {
	    set ml [lindex $me 0]
	} else {
	    set ml [lindex $me 1]
	}

	# look for character to underline:
	set uc [string first "&" $ml]

	# ml2 will hold the entry label:
	if {$uc >= 0} {
	    set ml2 ""
	    append ml2 [string range $ml 0 [expr $uc - 1]] \
			[string range $ml [expr $uc + 1] end]
	} else {
	    set ml2 $ml
	}

	if {[llength $me] == 2} {
	    $w add command -label $ml2 -underline $uc
	    eval $w entryconfigure $enum [lindex $me 1]
	} else {
	    switch [lindex $me 0] {
		"c"	{incr cb_menu(rlevel) ;# cascaded menu entry
			$w add cascade -label $ml2 -underline $uc \
			-menu [cb_menu $w.mc$cb_menu(rlevel) \
			[lindex $me 2]]}
		"cc"	{incr cb_menu(rlevel) ;# cascaded command entry \
			i.e. an entry with a dynamically created submenu
			$w add cascade -label $ml2 -underline $uc
			eval $w entryconfigure $enum [lindex $me 2]}
		"cb"	{$w add checkbutton -label $ml2	-underline $uc
	    		eval $w entryconfigure $enum [lindex $me 2]}
		"rb"	{$w add radiobutton -label $ml2	-underline $uc
	    		eval $w entryconfigure $enum [lindex $me 2]}
	    }
	}
    }

    return $w
}

# -----------------------------------------------------------------------------
# cb_menubar: Creates a menu bar by processing a list of menubutton with
#	associated menu. The menu may be a list as expected by cb_menu, or
#	may also be the name of a menu widget.

proc cb_menubar {w mblist} {

    frame $w -relief raised -bd 2

    set mbstr ""
    set mbnum 0
    foreach mb $mblist {
	incr mbnum
	set ml [lindex $mb 0]

	# look for character to underline:
	set uc [string first "&" $ml]

	# ml2 will hold the menubutton label:
	if {$uc >= 0} {
	    set ml2 ""
	    append ml2 [string range $ml 0 [expr $uc - 1]] \
			[string range $ml [expr $uc + 1] end]
	} else {
	    set ml2 $ml
	}

	menubutton $w.mb$mbnum -text $ml2 -underline $uc
	if {[string index [lindex $mb 1] 0] == "."} {
	    $w.mb$mbnum configure -menu [lindex $mb 1]
	} else {
	    $w.mb$mbnum configure -menu \
		[cb_menu $w.mb$mbnum.m [lindex $mb 1]]
	}

	if {[string first "Help" $ml2] == -1} {
	    pack $w.mb$mbnum -in $w -side left
	} else {
	    pack $w.mb$mbnum -in $w -side right
	}

	lappend mbstr $w.mb$mbnum
    }
}

# -----------------------------------------------------------------------------
# cb_buttonbar: Creates a button bar. blist is a list of 2-element lists, where
#	the first element specifies the bitmap and the 2nd element is a list
#	of options for that button.
#	Options: -pad <int>, -orient* <horizontal|vertical>

proc cb_buttonbar {w blist args} {

    set pad 3
    set packside left
    set c_args ""

    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    switch -glob $o {
		"pad"     {incr i; set pad [lindex $args $i]}
		"orient*" {incr i
				if {[lindex $args $i] == "vertical"} {
				    set packside top
				} 
			  }
		default	  {incr i
			   lappend c_args -$o [lindex $args $i]}
	    }
	}
    }

    frame $w -bd 1 -relief raised
    pack $w
    if {$c_args != ""} {
    	eval $w configure $c_args
    }

    set bnum 0
    foreach b $blist {
	incr bnum
	if {[lindex $b 0] != "-"} {
	    button $w.b$bnum -bitmap [lindex $b 0]
	    eval $w.b$bnum configure [lindex $b 1]
	    pack $w.b$bnum -in $w -side $packside -padx $pad -pady $pad
	} else {
	    frame $w.f$bnum
	    pack $w.f$bnum -in $w -side $packside -padx $pad -pady $pad
	}
    }
}

# -----------------------------------------------------------------------------
# cb_icon: Creates an icon. The frame $w then contains a bitmap $w.bitmap and
#	   and a label $w.label.

proc cb_icon {w args} {

    set pad 0
    set width 0
    set height 0
    set command ""
    set b_args ""	;# bitmap args
    set l_args ""	;# label args
    set f_args ""	;# frame args

    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    switch -glob $o {
		"pad"     	{incr i; set pad [lindex $args $i]}
		"command"     	{incr i; set command [lindex $args $i]}
		"bitmap"	{incr i
			   	lappend b_args -$o [lindex $args $i]}
		"font"		-
		"textv*"	-
		"text"      	{incr i
			   	lappend l_args -$o [lindex $args $i]}
		"width"		{incr i; set width [lindex $args $i]}
		"height"	{incr i; set height [lindex $args $i]}
		default	  	{incr i
			   	lappend f_args -$o [lindex $args $i]}
	    }
	}
    }

    eval frame $w $f_args
    if {$command != ""} {
	bind $w <Button-1> "$command"
    }

    eval label $w.bitmap $b_args
    pack $w.bitmap -padx $pad -pady $pad -fill both
    bind $w.bitmap <Button-1> "eval \[bind $w <Button-1>\]"
    bind $w.bitmap <Double-1> "eval \[bind $w <Double-1>\]"

    eval label $w.label $l_args
    pack $w.label -padx $pad -pady $pad -fill both
    bind $w.label <Button-1> "eval \[bind $w <Button-1>\]"
    bind $w.label <Double-1> "eval \[bind $w <Double-1>\]"
}

# ----------------------------------------------------------------------------
# cb_entry w options
# Creates an entry widget with an erase button.
#
proc cb_entry {w args} {
    global cb_tools
    
    frame $w
    eval entry $w.e $args -exportselection 1
    button $w.b -bitmap @$cb_tools(path)/bitmaps/erase.xbm \
	    -highlightthickness 0 -takefocus 0 \
	    -command "$w.e selection range 0 end; focus $w.e"
    cb_balloonHelp $w.b "Click to select the contents of the text entry field to type over it or paste it somewhere else."

    pack $w.b -side left -padx 0 -pady 0 -ipadx 2 -ipady 2
    pack $w.e -side left -padx 0 -pady 0 -ipadx 0 -ipady 2 \
	    -fill x -expand yes
    return $w
}
