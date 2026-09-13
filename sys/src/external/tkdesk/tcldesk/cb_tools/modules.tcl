# =============================================================================
#
# File:		cb-modules.tcl
# Project:	cb-tools
# Started:	28.06.94
# Changed:	12.01.96
#
# Description:	Provides a collection of small toplevels (i.e. dialogs).
#
# -----------------------------------------------------------------------------
#
# from cb-dialog.tcl: 
#	proc cb_dialog {w title text bitmap default args}
#	(display $text in window $w with title $title; args is one or more
#	strings for buttons, where $default is the default-button)
#
# Sections:
#	proc cb_readStringASync {e_label e_var} 
#	proc cb_readString {e_label ?e_var? ?title?} 
#	proc cb_fileSelector {args}
#
# =============================================================================

# ----------------------------------------------------------------------------
# cb_readStringASync {e_label e_var}: creates a toplevel to read a string 
#               to $e_var. Returns immediately! Yes, it's asynchronous.

global cb_readStringASync
set cb_readStringASync(tmp) ""
set cb_readStringASync(focus) ""
set cb_readStringASync(num) 0

proc cb_readStringASync {e_label e_var} {
	global $e_var cb_readStringASync

	incr cb_readStringASync(num)
	set t .tcb_rS($cb_readStringASync(num))

	toplevel $t

	frame $t.f1 -relief raised -bd 1
	pack $t.f1 -fill x -side top

	label $t.lLabel -text $e_label
	pack $t.lLabel -in $t.f1 -padx 2m -side top

	entry $t.eEntry -textvariable cb_readStringASync(tmp) \
		-width 50 -relief sunken -bd 2
	$t.eEntry delete 0 end
	$t.eEntry insert 0 [set $e_var]
	pack $t.eEntry -in $t.f1 -padx 2m -pady 2m -ipady 2 -side top

	bind $t.eEntry <Return> "$t.bOK flash ; $t.bOK invoke"
	bind $t <Enter> "\
		set cb_readStringASync(focus) \[focus\] ;\
		focus $t.eEntry "
	bind $t <Leave> {focus $cb_readStringASync(focus)}

	frame $t.f2 -relief raised -bd 1
	pack $t.f2 -fill x -side top

	frame $t.fdOK -relief sunken -bd 1
	pack $t.fdOK -in $t.f2 -side left -padx 2m -pady 2m
	button $t.bOK -text "   OK   " -command "destroy $t ;\
		set $e_var \$cb_readStringASync(tmp) ;\
		focus $cb_readStringASync(focus) "
	pack $t.bOK -in $t.fdOK -padx 1m -pady 1m -ipady 0

	frame $t.fdCancel -relief flat -bd 1
	pack $t.fdCancel -in $t.f2 -side left -padx 2m -pady 2m
	button $t.bCancel -text " Cancel " -command "destroy $t ;\
		focus $cb_readStringASync(focus) "
	pack $t.bCancel -in $t.fdCancel -padx 1m -pady 1m -ipady 0

	wm title $t "[winfo name .]:"
}

# ----------------------------------------------------------------------------
# cb_readString {e_label}: creates a toplevel to read a string to e_var.
#               Does a local grab. Returns the read-in string.

global cb_readString
set cb_readString(tmp) ""

proc cb_readString {e_label {e_var cb_readString(tmp)} {title ""} \
	{ewidth 50}} {
	global $e_var cb_readString tk_strictMotif

	set t .tcb_rS

	catch {destroy $t}
	toplevel $t
	wm withdraw $t

	frame $t.f1 -relief raised -bd 1
	pack $t.f1 -fill x -side top

	label $t.lLabel -text $e_label
	pack $t.lLabel -in $t.f1 -padx 1m -pady 2m -side top -anchor w

	set cb_readString(tmp) ""	
	set e_tmp [set $e_var]
	entry $t.eEntry -textvariable e_tmp \
		-width $ewidth -relief sunken -bd 2
	$t.eEntry delete 0 end
	$t.eEntry insert 0 [set $e_var]
	if {[string index [set $e_var] 0] == " "} {
	    $t.eEntry icursor 0
	}
	pack $t.eEntry -in $t.f1 -padx 2m -pady 2m -ipady 2 -side top -fill x

	if !$tk_strictMotif {
	    bind $t.eEntry <Return> "$t.bOK flash ; $t.bOK invoke"
	    bind $t.eEntry <KP_Enter> "$t.bOK flash ; $t.bOK invoke"
	    bind $t.eEntry <Escape> "$t.bCancel flash ; $t.bCancel invoke"
	    bind $t.eEntry <Control-c> "$t.bCancel flash ; $t.bCancel invoke"
	} else {
	    bind $t.eEntry <Return> "$t.bOK invoke"
	    bind $t.eEntry <KP_Enter> "$t.bOK invoke"
	    bind $t.eEntry <Escape> "$t.bCancel invoke"
	    bind $t.eEntry <Control-c> "$t.bCancel invoke"
	}

	frame $t.f2 -relief raised -bd 1
	pack $t.f2 -fill x -side top

	frame $t.fdOK -relief sunken -bd 1
	pack $t.fdOK -in $t.f2 -side left -padx 2m -pady 2m
	button $t.bOK -text "   OK   " -command "destroy $t ;\
		set $e_var \$e_tmp"
	pack $t.bOK -in $t.fdOK -padx 1m -pady 1m

	frame $t.fdCancel -relief flat -bd 1
	pack $t.fdCancel -in $t.f2 -side left -padx 2m -pady 2m
	button $t.bCancel -text " Cancel " -command "destroy $t ;\
		set $e_var \"\" "
	pack $t.bCancel -in $t.fdCancel -padx 1m -pady 1m

	if {$title == ""} {
	    wm title $t "[winfo name .]"
	} else {
	    wm title $t $title
	}

	if {[info procs dsk_place_window] != ""} {
	    dsk_place_window $t cb_readString "" 0 1
	} else {
	    cb_centerToplevel $t
	}
	wm deiconify $t

    	catch {tkwait visibility $t}

    	grab $t
	set old_focus [focus]
	catch {
	    focus -force $t.eEntry
	    tkwait window $t
	    focus -force $old_focus
	}
	return [set $e_var]
}

# -----------------------------------------------------------------------------
# cb_fileSelector: Implements a Motif-style file-selector. 
#	Options: -filter <string>, -variable <varname>, -showall <boolean>,
#		 -label <string>

global cb_fileSelector
set cb_fileSelector(tmpsel) ""
set cb_fileSelector(filter) ""
set cb_fileSelector(showall) 0
set cb_fileSelector(selfile) ""

proc cb_fileSelector {args} {
    global cb_fileSelector env tkdesk

    set filter $env(HOME)
    catch {set filter [pwd]}
    set selfile cb_fileSelector(selfile)
    set label ""

    if [info exists tkdesk(append_type_char)] {
	if $tkdesk(append_type_char) {
	    set cb_fileSelector(slash) "/"
	} else {
	    set cb_fileSelector(slash) ""
	}
    } else {
	set cb_fileSelector(slash) "/"
    }

    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    switch -glob $o {
	    	"fil*"    {incr i; set filter [lindex $args $i]}
	    	"var*"  {incr i; set selfile [lindex $args $i]}
		"showall"   {incr i
			set cb_fileSelector(showall) [lindex $args $i]}
		"label"     {incr i; set label [lindex $args $i]}
	    	default	    {error "Don't understand option -$o."}
	    }
	}
    }

    upvar $selfile selected
    if ![info exists selected] {
	set selected ""
    }

    set t .tcb_fileSel

    catch {destroy $t}
    toplevel $t
    wm withdraw $t

    set pad 4

    # === message

    if {$label != ""} {
	message $t.mLabel -text $label -width 400 -relief raised -bd 1 \
		-font [cb_fontStr -family helvetica -size 14 -weight bold] \
		-justify center
	pack $t.mLabel -fill x -ipady 4
    }

    # === upper half frame

    frame $t.fUH -relief raised -bd 1
    pack $t.fUH -fill both -expand yes

    # --- filter entry frame

    frame $t.fFE
    pack $t.fFE -in $t.fUH -padx $pad -pady $pad -fill x

    label $t.lFE -text "Filter:"
    pack $t.lFE -in $t.fFE -anchor w

    entry $t.eFE -relief sunken -bd 2 ;#-textvariable filter
    $t.eFE delete 0 end
    $t.eFE insert 0 [cb_tilde $filter collapse]
    pack $t.eFE -in $t.fFE -fill x -ipadx 2 -ipady 2

    bind $t.eFE <Key-Tab> "focus $t.eSE ;\
	$t.bFilter config -relief flat ;\
	$t.bOK config -relief sunken; break"
    bind $t.eFE <Key-Return> "$t.bFilter.button flash ;\
	$t.bFilter.button invoke; break"
    bind $t.eFE <Key-KP_Enter> "$t.bFilter.button flash ;\
	$t.bFilter.button invoke; break"
    bind $t.eFE <1> "focus $t.eFE ;\
	$t.bOK config -relief flat ;\
	$t.bFilter config -relief sunken"
    cb_bindForCompletion $t.eFE <Control-Tab>

    # --- listbox frame

    frame $t.fLB
    pack $t.fLB -in $t.fUH -fill both -expand yes

    # --- left LB frame

    frame $t.fLBl
    pack $t.fLBl -in $t.fLB -side left -fill both -expand yes

    label $t.lLBl -text "Directories:"
    pack $t.lLBl -in $t.fLBl -anchor w -padx 4

    cb_listbox $t.lbl -lborder 1 -vscroll 1 -hscroll 1 -pad 4 \
		-width 24 -height 12 -setgrid 1
    $t.lbl.lbox config -font [cb_fontStr]
    pack $t.lbl -in $t.fLBl -expand yes -fill both
    $t.lbl.lbox config -selectmode browse

    #bind $t.lbl.lbox <Double-1> "\
	#cb_fileSelFilter $t.eFE \[%W get \[%W curselection\]\]; break"
    bind $t.lbl.lbox <Double-1> "cb_fileSelFilter $t.eFE %W; break"
    #bind $t.lbl.lbox <Return> [bind $t.lbl.lbox <Double-1>]
    #bind $t.lbl.lbox <space> [bind $t.lbl.lbox <Double-1>]

    # --- right LB frame

    frame $t.fLBr
    pack $t.fLBr -in $t.fLB -side left -fill both -expand yes

    label $t.lLBr -text "Files:"
    pack $t.lLBr -in $t.fLBr -anchor w -padx 4

    cb_listbox $t.lbr -vscroll 1 -hscroll 1 -pad 4 \
		-width 24 -height 12 -setgrid 1
    $t.lbr.lbox config -font [cb_fontStr]
    pack $t.lbr -in $t.fLBr -expand yes -fill both
    $t.lbr.lbox config -selectmode browse

    bind $t.lbr.lbox <ButtonRelease-1> "\
	#%W select set \[%W nearest %y\]
        _cb_fs_sel $t"
    bind $t.lbr.lbox <Double-1> "\
	[bind $t.lbr.lbox <1>]
	$t.bOK.button flash
	$t.bOK.button invoke; break"
    #bind $t.lbr.lbox <Return> [bind $t.lbr.lbox <Double-1>]
    #bind $t.lbr.lbox <space> [bind $t.lbr.lbox <Double-1>]

    # --- selection entry frame

    frame $t.fSE
    pack $t.fSE -in $t.fUH -padx $pad -pady $pad -fill x

    label $t.lSE -text "Selected file:"
    pack $t.lSE -in $t.fSE -anchor w

    entry $t.eSE -relief sunken -bd 2
    $t.eSE delete 0 end
    $t.eSE insert 0 $selected
    pack $t.eSE -in $t.fSE -fill x -ipadx 2 -ipady 2

    bind $t.eSE <Key-Tab> "focus $t.eFE ;\
	$t.bOK config -relief flat ;\
	$t.bFilter config -relief sunken; break"
    bind $t.eSE <Key-Return> "$t.bOK.button flash ;\
	$t.bOK.button invoke; break"
    bind $t.eSE <1> "focus $t.eSE ;\
	$t.bFilter config -relief flat ;\
	$t.bOK config -relief sunken"
    cb_bindForCompletion $t.eSE <Control-Tab>

    cb_fileSelUpdate $filter

    # === lower half frame

    frame $t.fLH -relief raised -bd 1
    pack $t.fLH -fill x

    # --- buttons

    set bPad 4
    cb_button $t.bOK -text "OK" -width 8 -default 1 -pad 4 \
	    -command "cb_fileSelOK $t"
    pack $t.bOK -in $t.fLH -side left -padx $bPad -pady $bPad -expand 1

    cb_button $t.bFilter -text "Filter" -width 8 -pad 4 \
	-command "cb_fileSelUpdate \[cb_tilde \[$t.eFE get\]\]"
    pack $t.bFilter -in $t.fLH -side left -padx $bPad -pady $bPad -expand 1

    cb_button $t.bHome -text "Home" -width 8 -pad 4 \
		-command "cb_fileSelUpdate $env(HOME) 1"
    pack $t.bHome -in $t.fLH -side left -padx $bPad -pady $bPad -expand 1

    cb_button $t.bCancel -text "Cancel" -width 8 -pad 4 \
		-command "set cb_fileSelector(tmpsel) \"\" ; destroy $t"
    pack $t.bCancel -in $t.fLH -side left -padx $bPad -pady $bPad -expand 1

    # === wm, grab, focus

    wm title $t "File-Selector ([winfo name .])"

    if {[info procs dsk_place_window] != ""} {
	dsk_place_window $t cb_readString "24x12" 1 1
    } else {
	cb_centerToplevel $t
    }
    wm deiconify $t
    wm minsize $t 24 12
#    wm minsize $t 0 0

    tkwait visibility $t
    grab $t
    set old_focus [focus]
    focus $t.eSE

    tkwait window $t

    catch {focus -force $old_focus}
    set selected $cb_fileSelector(tmpsel)
    if {[string index $selected 0] != "/" && $selected != ""} {
	if {[string index $selected 0] == "~"} {
	    if [catch {file dirname $selected}] {
		# e.g. ~march31
		set selected [file dirname $cb_fileSelector(filter)]/$selected
	    }
	} else {
	    set selected [file dirname $cb_fileSelector(filter)]/$selected
	}
    }
    return $selected
}

proc cb_fileSelOK {t} {
    global cb_fileSelector
    
    set cb_fileSelector(tmpsel) [$t.eSE get]
    set isdir 0
    catch {set isdir [file isdirectory $cb_fileSelector(tmpsel)]}

    set cb_fileSelector(filter) [cb_tilde [$t.eFE get]]
    set reldir \
	    [file dirname $cb_fileSelector(filter)]/$cb_fileSelector(tmpsel)
    set relisdir 0
    catch {set relisdir [file isdirectory $reldir]}
    
    if $isdir {
	cb_fileSelUpdate $cb_fileSelector(tmpsel) 1 1
    } elseif $relisdir {
	cb_fileSelUpdate $reldir 1 1
    } else {
	destroy $t
    }
}

proc cb_fileSelUpdate {filter {keep_ext 0} {clean_sel 0}} {
    global cb_fileSelector tkdesk env

    cb_BusyCursor
    set t .tcb_fileSel
    if ![winfo exists $t] {
	cb_NormalCursor
	return
    }

    if {$filter == ".."} {
	set filter [file dirname [file dirname $cb_fileSelector(filter)]]
    }
    #puts $filter
    set isdir 0
    catch {set isdir [file isdirectory $filter]}
    if $isdir {
	set filter [string trimright $filter /]
	append filter "/*"
	if {$keep_ext} {
	    append filter [file extension [cb_tilde [$t.eFE get]]]
	}
	$t.eFE delete 0 end
	$t.eFE insert 0 [cb_tilde $filter collapse]
	if {$clean_sel} {
	    $t.eSE delete 0 end
	}
    }

    $t.lbl.lbox selection clear 0 end
    $t.lbl.lbox delete 0 end
    if {[file dirname $filter] != "/"} {
    	$t.lbl.lbox insert 0 "..$cb_fileSelector(slash)"
    }
    $t.lbr.lbox selection clear 0 end
    $t.lbr.lbox delete 0 end

    set mask [file tail $filter]
    set old_dir $env(HOME)
    catch {set old_dir [pwd]}
    cd [file dirname $filter]
    set files ""
    if $cb_fileSelector(showall) {
	catch {set files [exec ls -a]}
    } else {
	catch {set files [exec ls]}
    }
    foreach f $files {
	set isdir 0
	catch {set isdir [file isdirectory $f]}
	if $isdir {
	    if {$f != "." && $f != ".."} {
	        $t.lbl.lbox insert end $f$cb_fileSelector(slash)
	    }
	} else {
	    if [string match $mask $f] {
	    	$t.lbr.lbox insert end $f
	    }
	}
    }

    cd $old_dir
    cb_NormalCursor
}

proc _cb_fs_sel {t} {
    $t.eSE delete 0 end
    set sel [$t.lbr.lbox curselection]
    if {$sel != ""} {
	$t.eSE insert 0 [$t.lbr.lbox get $sel]
    }
}

proc cb_fileSelFilter {e lb} {
    global cb_fileSelector

    set sel [$lb curselection]
    if {$sel == ""} return

    set newdir [string trimright [$lb get $sel] /]/
    set oldfilter [cb_tilde [$e get]]

    if {$newdir == "../"} {
	append newfilter [string range $oldfilter 0 \
		[string last / [file dirname $oldfilter]]] \
		[file tail $oldfilter]
    } else {
	if {[file dirname $oldfilter] == "/"} {
	    append newfilter / $newdir [file tail $oldfilter]
	} else {
	    append newfilter [file dirname $oldfilter]/ \
		    $newdir [file tail $oldfilter]
	}
    }

    cb_fileSelUpdate $newfilter
    $e delete 0 end
    $e insert 0 [cb_tilde $newfilter]
}

# -----------------------------------------------------------------------------
# cb_balloonHelp: A simple balloon help for arbitrary widgets.
# Options: w: widget name, text: help text
#

set cb_balloonHelp(screen_width) [winfo screenwidth .]
set cb_balloonHelp(screen_height) [winfo screenheight .]
set cb_balloonHelp(bltbusy) 0

proc cb_balloonHelp {w text {delay 500}} {
    global cb_balloonHelp

    set me ""
    if {[llength $w] > 1} {
	# 2nd element is the number of a menu entry
	set me [lindex $w 1]
	# 1st element the menu itself
	set w [lindex $w 0]
    }
    
    set cb_balloonHelp($w,cursor) [$w cget -cursor]
    set cb_balloonHelp($w,shown) 0

    if {$me == ""} {
	bind $w <Enter> "+set cb_balloonHelp(id) \
		\[after $delay _cb_balloonDisplay $w \\\{$text\\\} %X %Y\]"
	#bind $w <Motion> "
	#set tmp_w \[winfo containing %X %Y\]
        #catch \{destroy .cb_balloon\}
	#catch \{after cancel \$cb_balloonHelp(id)\}
	#catch \{after cancel \$cb_balloonHelp(id,timeout)\}
	##catch \{%W config -cursor \$cb_balloonHelp(%W,cursor)\}
	#if \{\$tmp_w == \"%W\"\} \{
	#    set cb_balloonHelp(id) \
	#	     \[after $delay _cb_balloonDisplay $w \\\{$text\\\} %X %Y\]
	#\}
	#unset tmp_w
	#"
	bind $w <Leave> {
	    if $cb_balloonHelp(bltbusy) continue
	    catch {destroy .cb_balloon}
	    catch {after cancel $cb_balloonHelp(id)}
	    catch {after cancel $cb_balloonHelp(id,timeout)}
	    #catch {%W config -cursor $cb_balloonHelp(%W,cursor)}
	    set cb_balloonHelp(%W,shown) 0
	}
	bind $w <Any-ButtonPress> {
	    catch {destroy .cb_balloon}
	    catch {after cancel $cb_balloonHelp(id)}
	    catch {after cancel $cb_balloonHelp(id),timeout}
	    #catch {%W config -cursor $cb_balloonHelp(%W,cursor)}
	    set cb_balloonHelp(%W,shown) 1
	}
	bind $w <Any-Key> [bind $w <Any-ButtonPress>]
    } else {
	set cb_balloonHelp($w,$me,text) $text
	bind $w <Enter> "
	set tmp_me \[%W index @%y\]
	if \[info exists cb_balloonHelp(%W,\$tmp_me,text)\] {
	    set cb_balloonHelp(id) \
		    \[after $delay _cb_balloonDisplay \
		    $w \\\{\$cb_balloonHelp(%W,\$tmp_me,text)\\\} %X %Y\]
	}
	unset tmp_me
	"
	bind $w <Motion> "
        catch \{destroy .cb_balloon\}
	catch \{after cancel \$cb_balloonHelp(id)\}
	catch \{after cancel \$cb_balloonHelp(id,timeout)\}
	#catch \{%W config -cursor \$cb_balloonHelp(%W,cursor)\}
	set tmp_me \[%W index @%y\]
	set cb_balloonHelp($w,shown) 0
	if \[info exists cb_balloonHelp(%W,\$tmp_me,text)\] {
	    set cb_balloonHelp(id) \
		    \[after $delay _cb_balloonDisplay \
		    $w \\\{\$cb_balloonHelp(%W,\$tmp_me,text)\\\} %X %Y\]
	}
	unset tmp_me
	"
	bind $w <Leave> {
	    catch {destroy .cb_balloon}
	    catch {after cancel $cb_balloonHelp(id)}
	    catch {after cancel $cb_balloonHelp(id,timeout)}
	    #catch {%W config -cursor $cb_balloonHelp(%W,cursor)}
	    set cb_balloonHelp(%W,shown) 0
	}
	bind $w <Any-ButtonPress> [bind $w <Leave>]
	bind $w <Any-Key> [bind $w <Any-ButtonPress>]
    }
}

if ![info exists cb_tools(balloon_help)] {
    set cb_tools(balloon_help) 1
}

proc _cb_balloonDisplay {w text rx ry} {
    global cb_balloonHelp cb_tools tkdesk

    #if $cb_tools(no_balloon) {
    #	 set cb_tools(no_balloon) 0
    #	 return
    #}
    if {$w != ""} {
	if {!$cb_tools(balloon_help) || $cb_balloonHelp($w,shown)} {
	    return
	}
	if {[winfo containing [winfo pointerx .] [winfo pointery .]] != $w} {
	    return
	}
	set cb_balloonHelp($w,shown) 1
    }
    
    catch {destroy [set t .cb_balloon]}
    toplevel $t -bg yellow
    wm withdraw $t
    label $t.l -text $text -wraplength 300 -justify left \
	    -bg \#ffffa8 -fg black -bd 1 -relief flat -padx 2 -pady 2 \
	    -highlightbackground black -highlightcolor black \
	    -highlightthickness 1 -cursor top_left_arrow
    set err [catch {$t.l config -font [cb_font $tkdesk(font,balloon)]}]
    if $err {$t.l config -font fixed}
    pack $t.l
    wm overrideredirect $t 1
    if {$w != ""} {
	set x [winfo pointerx $w]
	set y [expr [winfo pointery $w] + 16]
    } else {
	set x $rx
	set y $ry
    }
    if {$y < 0} {set y 0}
    set w [winfo reqwidth $t.l]
    set h [winfo reqheight $t.l]

    # make help window be completely visible
    if {$x + $w > $cb_balloonHelp(screen_width)} {
	set x [expr $cb_balloonHelp(screen_width) - $w]
    }
    if {$y + $h > $cb_balloonHelp(screen_height)} {
	set y [expr $cb_balloonHelp(screen_height) - $h]
    }

    wm geometry $t +$x+$y
    wm deiconify $t
    # the original cursor is saved in cb_balloonHelp
    #$w config -cursor arrow

    # remove the balloon window after 5 seconds:
    set cb_balloonHelp(id,timeout) \
        [after [expr 5000 + [string length $text] * 50] "catch \{destroy $t\}"]
    return $t
}

# --------------------------------------------------------------------------
# cb_aboutAnim window basename number ?delay? ?color?:
# Creates a funky animation in $window by successively displaying the bitmaps
# stored in files $basename-$number.xbm to $basename-1.xbm. The files may
# be gzipped. If $delay is specified it is the delay between updates in ms.
#
proc cb_aboutAnim {win base num {delay 0} {color ""}} {
    global cb_aboutAnim

    if [file readable $base-1.xbm] {
	# uncompressed files
	for {set i 1} {$i <= $num} {incr i} {
	    set fd [open $base-$i.xbm]
	    set cb_aboutAnim(bm$i) [read -nonewline $fd]
	    close $fd
	}
    } elseif [file readable $base-1.xbm.gz] {
	# gzipped files
	for {set i 1} {$i <= $num} {incr i} {
	    set cb_aboutAnim(bm$i) [exec gzip -cd $base-$i.xbm.gz]
	}
    } else {
	error "couldn't read $base-1.xbm (neither gzipped)"
    }

    image create bitmap cb_about -data $cb_aboutAnim(bm$num)
    if {$color == ""} {
	cb_about config -foreground [$win cget -background]
	set gr [string range [$win cget -background] 1 2]
	set cb_aboutAnim(coldec) [expr 0x$gr / $num.]
	set cb_aboutAnim(color) [format "%d" 0x$gr]
    } else {
	cb_about config -foreground $color
	set cb_aboutAnim(color) ""
    }
    $win config -image cb_about
    set cb_aboutAnim(frame) $num

    after $delay _cb_about_animate $win $delay
}

proc _cb_about_animate {win delay} {
    global cb_aboutAnim

    if ![winfo exists $win] {
	return
    }
    if {$cb_aboutAnim(frame) <= 0} {
	return
    }

    cb_about config -data $cb_aboutAnim(bm$cb_aboutAnim(frame))
    if {$cb_aboutAnim(color) != ""} {
	set cb_aboutAnim(color) [expr $cb_aboutAnim(color) \
		- $cb_aboutAnim(coldec)]
	set gr [format "%x" [expr round($cb_aboutAnim(color))]]
	cb_about config -foreground "#$gr$gr$gr"
    }
    update idletasks
    incr cb_aboutAnim(frame) -1

    after $delay _cb_about_animate $win $delay
}
