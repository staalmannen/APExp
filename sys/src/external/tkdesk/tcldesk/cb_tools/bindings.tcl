# =============================================================================
#
# File:		cb_bindings.tcl
# Project:	cb_tools
# Started:	?
# Changed:	10.07.95
# Author:       Christian Bolik (zzhibol@rrzn-user.uni-hannover.de)
#
# Description:	This file contains additional bindings for several 
#		widget classes.
#
# -----------------------------------------------------------------------------
#
# Sections:
#	==== Entry-Bindings
#
# =============================================================================

if ![info exists cb_tools(keys_bound)] {
set cb_tools(keys_bound) 1

if {$tk_version >= 8.4} {

   # Hopefully the use of these will be temporary and we will
   # find a better way to deal with the effected bindings.

   ::tk::unsupported::ExposePrivateVariable tkPriv
   ::tk::unsupported::ExposePrivateCommand tkEntryTranspose
   ::tk::unsupported::ExposePrivateCommand tkTextTranspose
   ::tk::unsupported::ExposePrivateCommand tkTextPaste
   ::tk::unsupported::ExposePrivateCommand tkEntryPaste
   ::tk::unsupported::ExposePrivateCommand tkEntryInsert
   ::tk::unsupported::ExposePrivateCommand tkTextInsert

}


# Make some bindings available even if tk_strictMotif is true:
#if $tk_strictMotif {}

# Mouse wheel support
bind Text <Button-5> {%W yview scroll 5 units}
bind Text <Button-4> {%W yview scroll -5 units}
bind Text <Shift-Button-5> {%W yview scroll 1 units}
bind Text <Shift-Button-4> {%W yview scroll -1 units}
bind Text <Control-Button-5> {%W yview scroll 1 pages}
bind Text <Control-Button-4> {%W yview scroll -1 pages}
bind Listbox <Button-5> {%W yview scroll 5 units}
bind Listbox <Button-4> {%W yview scroll -5 units}
bind Listbox <Shift-Button-5> {%W yview scroll 1 units}
bind Listbox <Shift-Button-4> {%W yview scroll -1 units}
bind Listbox <Control-Button-5> {%W yview scroll 1 pages}
bind Listbox <Control-Button-4> {%W yview scroll -1 pages}
bind MouseWheelEnabled <Button-5> {%W yview scroll 5 units}
bind MouseWheelEnabled <Button-4> {%W yview scroll -5 units}
bind MouseWheelEnabled <Shift-Button-5> {%W yview scroll 1 units}
bind MouseWheelEnabled <Shift-Button-4> {%W yview scroll -1 units}
bind MouseWheelEnabled <Control-Button-5> {%W yview scroll 1 pages}
bind MouseWheelEnabled <Control-Button-4> {%W yview scroll -1 pages}


# Buttons:
bind Button <Return> "[bind Button <space>]; break"
bind Checkbutton <Return> [bind Button <space>]
bind Radiobutton <Return> [bind Button <space>]
bind Entry <Control-d> {%W delete insert}
bind Entry <Control-t> {catch {tkEntryTranspose %W}}
bind Text <Control-d> {%W delete insert}
bind Text <Control-t> {catch {tkTextTranspose %W}}

# Text:
bind Text <2> {
    %W scan mark %x %y
    set tkPriv(x) %x
    set tkPriv(y) %y
    set tkPriv(mouseMoved) 0
}

bind Text <B2-Motion> {
    if {(%x != $tkPriv(x)) || (%y != $tkPriv(y))} {
	set tkPriv(mouseMoved) 1
    }
    if $tkPriv(mouseMoved) {
	%W scan dragto %x %y
    }
}

bind Text <ButtonRelease-2> {
    if {!$tkPriv(mouseMoved)} {
	catch {
	    cb_Text_change_callback %W paste \
		    [list %x %y [selection get -displayof %W]]
	}
	if {[info proc tkTextPaste] == ""} {
	    catch {
		%W insert @%x,%y [selection get -displayof %W]
	    }
	} else {
	    tkTextPaste %W %x %y
	}
	%W see insert
    }
}

bind Text <Control-k> {
    if [%W compare insert == {insert lineend}] {
	%W delete insert
    } else {
	%W delete insert {insert lineend}
    }
}

# Entry:
bind Entry <2> {
    %W scan mark %x
    set tkPriv(x) %x
    set tkPriv(y) %y
    set tkPriv(mouseMoved) 0
}
bind Entry <B2-Motion> {
    if {abs(%x-$tkPriv(x)) > 2} {
	set tkPriv(mouseMoved) 1
    }
    %W scan dragto %x
}
bind Entry <ButtonRelease-2> {
    if {!$tkPriv(mouseMoved)} {
	if {[info proc tkEntryPaste] == ""} {
	    catch {
		%W insert @%x [selection get -displayof %W]
	    }
	} else {
	    tkEntryPaste %W %x
	}
    }
}
bind Entry <Control-k> {
    %W delete insert end
}


# ==== Entry-Bindings =========================================================

#bind Entry <FocusIn> {
#    %W selection range 0 end
#}
#bind Entry <FocusOut> {
#    %W selection clear
#}
catch {bind Entry <braceleft> {tkEntryInsert %W \{}}
catch {bind Entry <braceright> {tkEntryInsert %W \}}}
catch {bind Entry <bracketleft> {tkEntryInsert %W \[}}
catch {bind Entry <bracketright> {tkEntryInsert %W \]}}
catch {bind Entry <backslash> {tkEntryInsert %W \\}}
catch {bind Entry <at> {tkEntryInsert %W @}}
catch {bind Entry <mu> {tkEntryInsert %W µ}}
catch {bind Entry <bar> {tkEntryInsert %W |}}
catch {bind Entry <adiaeresis> {tkEntryInsert %W ä}}
catch {bind Entry <odiaeresis> {tkEntryInsert %W ö}}
catch {bind Entry <udiaeresis> {tkEntryInsert %W ü}}
catch {bind Entry <Adiaeresis> {tkEntryInsert %W Ä}}
catch {bind Entry <Odiaeresis> {tkEntryInsert %W Ö}}
catch {bind Entry <Udiaeresis> {tkEntryInsert %W Ü}}
catch {
    bind Entry <ssharp> {
	if {%s == 0} {
	    tkEntryInsert %W ß
	} else {
	    tkEntryInsert %W \\
	}
    }
}

# These might need to be commented out when using XKB:
catch {bind Entry <asciitilde> {tkEntryInsert %W ~}}
catch {bind Entry <grave> {tkEntryInsert %W `}}
catch {bind Entry <dead_tilde> {tkEntryInsert %W ~}}
catch {bind Entry <dead_grave> {tkEntryInsert %W `}}
catch {bind Entry <dead_acute> {tkEntryInsert %W ´}}
catch {bind Entry <dead_circumflex> {tkEntryInsert %W ^}}


# ==== Text-Bindings ==========================================================

catch {bind Text <braceleft> {cb_Text_change_callback %W insert \{; \
	tkTextInsert %W \{}}
catch {bind Text <braceright> {cb_Text_change_callback %W insert \}; \
	tkTextInsert %W \}}}
catch {bind Text <bracketleft> {cb_Text_change_callback %W insert \[; \
	tkTextInsert %W \[}}
catch {bind Text <bracketright> {cb_Text_change_callback %W insert \]; \
	tkTextInsert %W \]}}
catch {bind Text <backslash> {cb_Text_change_callback %W insert \\; \
	tkTextInsert %W \\}}
catch {bind Text <at> {cb_Text_change_callback %W insert @; \
	tkTextInsert %W @}}
catch {bind Text <mu> {cb_Text_change_callback %W insert µ; \
	tkTextInsert %W µ}}
catch {bind Text <bar> {cb_Text_change_callback %W insert |; \
	tkTextInsert %W |}}
catch {bind Text <adiaeresis> {cb_Text_change_callback %W insert ä; \
        tkTextInsert %W ä}}
catch {bind Text <odiaeresis> {cb_Text_change_callback %W insert ö; \
        tkTextInsert %W ö}}
catch {bind Text <udiaeresis> {cb_Text_change_callback %W insert ü; \
        tkTextInsert %W ü}}
catch {bind Text <Adiaeresis> {cb_Text_change_callback %W insert Ä; \
        tkTextInsert %W Ä}}
catch {bind Text <Odiaeresis> {cb_Text_change_callback %W insert Ö; \
        tkTextInsert %W Ö}}
catch {bind Text <Udiaeresis> {cb_Text_change_callback %W insert Ü; \
        tkTextInsert %W Ü}}
catch {
    bind Text <ssharp> {
	if {%s == 0} {
	    cb_Text_change_callback %W insert ß
	    tkTextInsert %W ß
	} else {
	    cb_Text_change_callback %W insert \\
	    tkTextInsert %W \\
	}
    }
}

# These might need to be commented out when using XKB:
catch {bind Text <asciitilde> {cb_Text_change_callback %W insert ~; \
	tkTextInsert %W ~}}
catch {bind Text <grave> {cb_Text_change_callback %W insert `; \
	tkTextInsert %W `}}
catch {bind Text <dead_tilde> {cb_Text_change_callback %W insert ~; \
	tkTextInsert %W ~}}
catch {bind Text <dead_grave> {cb_Text_change_callback %W insert `; \
	tkTextInsert %W `}}
catch {bind Text <dead_acute> {cb_Text_change_callback %W insert ´; \
	tkTextInsert %W ´}}
catch {bind Text <dead_circumflex> {cb_Text_change_callback %W insert ^; \
	tkTextInsert %W ^}}


bind Text <Control-Left> {
    %W mark set insert "insert - 1 chars"
    %W mark set insert "insert wordstart"
    %W yview -pickplace insert
    cb_Text_extend_sel %W    
}
bind Text <Control-Right> {
    %W mark set insert "insert wordend"
    %W yview -pickplace insert
    cb_Text_extend_sel %W    
}
bind Text <Alt-d> {
    cb_Text_change_callback %W delete word
    set tmpsel {insert "insert wordend"}
    set cb_Text(cutbuffer,%W) [eval %W get $tmpsel]
    eval %W delete $tmpsel
    catch "selection clear %W"
}
bind Text <Meta-d> [bind Text <Alt-d>]
bind Text <Control-space> {
    selection clear %W
    if [info exists cb_Text(selstart)] {
	if [%W compare cb_selstart == insert] {
	    %W mark unset cb_selstart
	    unset cb_Text(selstart)
	} else {
	    %W mark unset cb_selstart
	    %W mark set cb_selstart insert
	    set cb_Text(selstart) 1
	}
    } else {
	%W mark set cb_selstart insert
	set cb_Text(selstart) 1
    }
}
bind Text <Left> {+cb_Text_extend_sel %W}
bind Text <Right> {+cb_Text_extend_sel %W}
bind Text <Up> {+cb_Text_extend_sel %W}
bind Text <Down> {+cb_Text_extend_sel %W}
bind Text <Prior> {+cb_Text_extend_sel %W}
bind Text <Next> {+cb_Text_extend_sel %W}
bind Text <Home> {+cb_Text_extend_sel %W}
bind Text <End> {+cb_Text_extend_sel %W}
bind Text <Control-Home> {+cb_Text_extend_sel %W}
bind Text <Control-End> {+cb_Text_extend_sel %W}
bind Text <Button-1> {+if [info exists cb_Text(selstart)] {
    unset cb_Text(selstart)
    catch {%W mark unset cb_selstart}
}   }

bind Text <Control-k> {
    catch {
	clipboard clear -displayof %W
	clipboard append -displayof %W [%W get insert {insert lineend}]
    }
    if [%W compare insert == {insert lineend}] {
	cb_Text_change_callback %W delete char
	%W delete insert
    } else {
	cb_Text_change_callback %W delete lineend
	%W delete insert {insert lineend}
    }
}

bind Text <Key> "cb_Text_change_callback %W insert %A; [bind Text <Key>]"
bind Text <Control-d> "cb_Text_change_callback %W delete char; \
	[bind Text <Control-d>]"
bind Text <Control-h> "cb_Text_change_callback %W delete backchar; \
	[bind Text <Control-h>]"
bind Text <Control-i> "cb_Text_change_callback %W insert <tab>; \
	[bind Text <Control-i>]"
bind Text <Control-o> "cb_Text_change_callback %W; [bind Text <Control-o>]"
bind Text <Control-t> "cb_Text_change_callback %W; [bind Text <Control-t>]"
bind Text <BackSpace> "cb_Text_change_callback %W delete backchar; \
	[bind Text <BackSpace>]"
bind Text <Delete> "cb_Text_change_callback %W delete char; \
	[bind Text <Delete>]"
bind Text <F18> "cb_Text_change_callback %W; [bind Text <F18>]"
bind Text <F20> "cb_Text_change_callback %W; [bind Text <F20>]"
bind Text <Return> "cb_Text_change_callback %W insert return; \
	[bind Text <Return>]"
bind Text <Tab> "cb_Text_change_callback %W insert <tab>; \
	[bind Text <Tab>]"
bind Text <mu> "cb_Text_change_callback %W insert µ; [bind Text <mu>]"
bind Text <Meta-BackSpace> "cb_Text_change_callback %W delete backchar; \
	[bind Text <Meta-BackSpace>]"
bind Text <Meta-Delete> "cb_Text_change_callback %W delete char; \
	[bind Text <Meta-Delete>]"


#
# ==== Procs ==================================================================
#

#
# -----------------------------------------------------------------------------
#
# Proc:		cb_pointToType
# Args:		
# Returns: 	""
# Desc:		Adds bindings to toplevels, entries and texts to support
#		point-to-type focus model.
# Side-FX:	none
#

proc cb_pointToType {} {

    bind Toplevel <Any-Enter> "
	[bind Toplevel <Any-Enter>]
	focus %W
	"
    bind Text <Any-Enter> "
	[bind Text <Any-Enter>]
	focus %W
	"
    bind Entry <Any-Enter> "
	[bind Entry <Any-Enter>]
	focus %W
	"
    bind Toplevel <Any-Leave> "
	[bind Toplevel <Any-Leave>]
	if {\[focus\] == \"%W\"} {
	    focus none
	}
	"
    bind Text <Any-Leave> "
	[bind Text <Any-Leave>]
	if {\[focus\] == \"%W\"} {
	    focus none
	}
	"
    bind Entry <Any-Leave> "
	[bind Entry <Any-Leave>]
	if {\[focus\] == \"%W\"} {
	    focus none
	}
	"
}

#
# -----------------------------------------------------------------------------
#
# Proc:		cb_bindForCompletion
# Args:		w	entry widget name
#		ev	(opt.) event that triggers the completion (in <...>)
# Returns: 	""
# Desc:		This adds a binding to the entry widget $w that tries
#		to complete its contents to a filename.
# Side-FX:	none
#

proc cb_bindForCompletion {w {ev "<Tab>"}} {
    global cb_tools

    bind $w $ev {
	set tmp [%W get]*
	if {[set tmpspc [string first " " $tmp]] > -1} {
	    set tmp [string range $tmp [expr $tmpspc + 1] end]
	}
	set tmplist ""
	catch {set tmplist [glob $tmp]}
	set ll [llength $tmplist]
	set success 0
	if {$ll == 1} {
	    if [file isdirectory $tmplist] {
		set tmplist $tmplist/
	    }
	    set success 1
	} elseif {$ll > 1 && $ll <= 10} {
	    set tpath [file dirname [lindex $tmplist 0]]
	    set tl {}
	    foreach le $tmplist {
		lappend tl [file tail $le]
	    }
	    set lmin 1000
	    foreach le $tl {
		set l [string length $le]
		if {$l < $lmin} {
		    set lmin $l
		    set emin $le
		}
	    }
	    set l 0
	    set tn ""
	    while {$l < $lmin} {
		set i 0
		foreach le $tl {
		    if {$i == 0} {
			set c [string index $le $l]
		    } else {
			if {[string index $le $l] != $c} {
			    set tn [string range $le 0 [expr $l -1]]
			    break
			}
		    }
		    incr i
		}
		if {$tn != ""} break
		incr l
	    }
	    if {$tn == ""} {
		set tmplist $tpath/$emin
	    } else {
		set tmplist $tpath/$tn
	    }
	    set success 1
	}
	
	if $success {
	    %W delete [expr $tmpspc + 1] end
	    %W insert end [cb_tilde $tmplist collapse]
	    %W xview end
	} else {
	    if [info exists cb_tools(bell_cmd)] {
		eval $cb_tools(bell_cmd)
	    } else {
		bell
	    }
	}
	
	catch {unset tmp tmplist tmpspc i l le ll tpath tn lmin emin}
	break
    }
}

# -----------------------------------------------------------------------------
#
# Proc:    cb_Text_extend_sel
# Desc:    Extends the sel tag on the given window.
# In:      w: text widget
# Out:     ""
# Side FX: none
#

proc cb_Text_extend_sel {w} {
    global cb_Text

    if [info exists cb_Text(selstart)] {
	$w tag remove sel 1.0 end
	if [$w compare cb_selstart < insert] {
	    $w tag add sel cb_selstart insert
	} else {
	    $w tag add sel insert cb_selstart
	}
    }
}

# -----------------------------------------------------------------------------
#
# Proc:    cb_Text_change_callback
# Desc:    Invokes a callback when the text widget's contents has been changed.
# In:      w: text widget's name
# Out:     ""
# Side FX: none
#

proc cb_Text_change_callback {w {type unknown} {data x}} {
    global cb_Text

    if [info exists cb_Text(selstart)] {
	unset cb_Text(selstart)
	catch {$w mark unset cb_selstart}
    }
    if {$data != ""} {
	if [info exists cb_Text(change_callback,$w)] {
	    eval $cb_Text(change_callback,$w) $type [list $data]
	}
    }
}

}

# ----------------------------------------------------------------------------
# cb_addShortcutBinding button char args:
# Adds bindings <Meta-$char>, <Alt-$char>, <Control-$char> that invoke
# $button's command to $widget.
#
proc cb_addShortcutBinding {widget button char args} {

    set char [string tolower $char]
    if {[winfo class $button] == "Button"} {
	bind $widget <Alt-$char> \
		"$button config -relief sunken ;\
		update idletasks ;\
		after 100 ;\
		$button config -relief raised ;\
		update idletasks ;\
		$button invoke ;\
		break"
    } else {
	bind $widget <Alt-$char> \
		"$button invoke ;\
		break"
    }
    bind $widget <Meta-$char> [bind $widget <Alt-$char>]
    bind $widget <Control-$char> [bind $widget <Alt-$char>]
}

