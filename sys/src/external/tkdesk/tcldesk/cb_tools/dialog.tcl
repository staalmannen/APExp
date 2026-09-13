# =============================================================================
#
# File:		cb_dialog.tcl
# Project:	cb_tools
# Started:	?
# Changed:	10.07.95
#
# Description:	Contains several procs for simple dialog boxes.
#
# -----------------------------------------------------------------------------
#
# Sections:
#	proc cb_alert {text}
#	proc cb_info {text}
#	proc cb_error {text}
#	proc cb_yesno {text}
#	proc cb_okcancel {text}
#	proc cb_dialog {w title text bitmap default args}
#
# =============================================================================


# -----------------------------------------------------------------------------
# cb_alert: Shows an alert box with the label text.

proc cb_alert {text} {
    if [winfo exists .tcb_alert] return
    return [tk_dialog [toplevel .tcb_alert] \
	"Alert" \
	$text \
	warning \
	0 \
	"  OK  " \
	]
}

# -----------------------------------------------------------------------------
# cb_info: Shows an info box with the label text.

proc cb_info {text} {
    if [winfo exists .tcb_info] return    
    return [tk_dialog [toplevel .tcb_info] \
	"Info" \
	$text \
	info \
	0 \
	"  OK  " \
	]
}

# -----------------------------------------------------------------------------
# cb_error: Shows an error box with the label text.

proc cb_error {text} {
    if [winfo exists .tcb_error] return    
    return [tk_dialog [toplevel .tcb_error] \
	"Error" \
	$text \
	error \
	0 \
	"  OK  " \
	]
}

# -----------------------------------------------------------------------------
# cb_yesno: Shows a question box with the label text and yes/no buttons.

proc cb_yesno {text {default 0}} {
    if [winfo exists .tcb_yesno] return    
    return [tk_dialog [toplevel .tcb_yesno] \
	"Question" \
	$text \
	questhead \
	$default \
	" Yes " \
	" No "
	]
}

# -----------------------------------------------------------------------------
# cb_okcancel: Shows a question box with the label text and ok/cancel buttons.

proc cb_okcancel {text {default 0}} {
    if [winfo exists .tcb_okcancel] return    
    return [tk_dialog [toplevel .tcb_okcancel] \
	"Confirmation" \
	$text \
	questhead \
	$default \
	" OK " \
	" Cancel "
	]
}

#
# cb_dialog:
#
# This procedure displays a dialog box, waits for a button in the dialog
# to be invoked, then returns the index of the selected button.
#
# Arguments:
# w -		Window to use for dialog top-level.
# title -	Title to display in dialog's decorative frame.
# text -	Message to display in dialog.
# bitmap -	Bitmap to display in dialog (empty string means none).
# default -	Index of button that is to display the default ring
#		(-1 means none).
# args -	One or more strings to display in buttons across the
#		bottom of the dialog box.
#
# CB: (This is the Tk 4.1 version.) Removed the binding for <Return>
# as it didn't follow the focus. Uses dsk_place_window if available.

# Transitioning back to using tk_dialog instead for TkDesk 2.0 (we're not
# supposed to use tkPriv if we can avoid it).  Note that we'll have to use
# the tk option db to set the dialog font (*Dialog.msg.font).
#	-- JCC 
proc cb_dialog {w title text bitmap default args} {
   return [eval tk_dialog \$w \$title \$text \$bitmap \$default $args]
}

#proc cb_dialog {w title text bitmap default args} {
#    global tkPriv tkdesk
#
#    # 1. Create the top-level window and divide it into top
#    # and bottom parts.
#
#    catch {destroy $w}
#    toplevel $w -class Dialog
#    wm title $w $title
#    wm iconname $w Dialog
#    wm protocol $w WM_DELETE_WINDOW { }
#
#    # The following command has been removed because if it is present
#    # the dialog won't be posted if [winfo parent $w] is iconified.
#
#    #    wm transient $w [winfo toplevel [winfo parent $w]]
#    frame $w.bot -relief raised -bd 1
#    pack $w.bot -side bottom -fill both
#    frame $w.top -relief raised -bd 1
#    pack $w.top -side top -fill both -expand 1
#
#    # 2. Fill the top part with bitmap and message (use the option
#    # database for -wraplength so that it can be overridden by
#    # the caller).
#
#    option add *Dialog.msg.wrapLength 3i widgetDefault
#    label $w.msg -justify left -text $text
#    if [info exists tkdesk(font,dialogs)] {
#	$w.msg configure -font [cb_font $tkdesk(font,dialogs)]
#    } else {
#	$w.msg configure -font [cb_font -*-Times-Medium-R-*--*-180-*-*-*-*-*-*]
#    }
#    pack $w.msg -in $w.top -side right -expand 1 -fill both -padx 3m -pady 3m
#    if {$bitmap != ""} {
#	label $w.bitmap -bitmap $bitmap
#	pack $w.bitmap -in $w.top -side left -padx 3m -pady 3m
#    }
#
#    # 3. Create a row of buttons at the bottom of the dialog.
#
#    set i 0
#    foreach but $args {
#	button $w.button$i -text $but -command "set tkPriv(button) $i"
#	if {$i == $default} {
#	    frame $w.default -relief sunken -bd 1
#	    raise $w.button$i $w.default
#	    pack $w.default -in $w.bot -side left -expand 1 -padx 3m -pady 2m
#	    pack $w.button$i -in $w.default -padx 2m -pady 2m
#	} else {
#	    pack $w.button$i -in $w.bot -side left -expand 1 \
#		    -padx 3m -pady 2m
#	}
#	incr i
#    }
#
#    # 4. Create a binding for <Return> on the dialog if there is a
#    # default button.
#    # CB: This is most dangerous as this binding doesn't follow the focus.
#
#    #if {$default >= 0} {
#    #	 bind $w <Return> "
#    #	     $w.button$default configure -state active -relief sunken
#    #	     update idletasks
#    #	     after 100
#    #	     set tkPriv(button) $default
#    #	 "
#    #}
#
#    # 5. Withdraw the window, then update all the geometry information
#    # so we know how big it wants to be, then center the window in the
#    # display and de-iconify it.
#
#    wm withdraw $w
#    update idletasks
#    if {[info procs dsk_place_window] != ""} {
#	dsk_place_window $w cb_dialog "" 0 1
#    } else {
#	set x [expr [winfo screenwidth $w]/2 - [winfo reqwidth $w]/2 \
#		- [winfo vrootx [winfo parent $w]]]
#	set y [expr [winfo screenheight $w]/2 - [winfo reqheight $w]/2 \
#		- [winfo vrooty [winfo parent $w]]]
#	wm geom $w +$x+$y
#    }
#    wm transient $w .
#    wm deiconify $w
#
#    # 6. Set a grab and claim the focus too.
#
#    set oldFocus [focus]
#    set oldGrab [grab current $w]
#    if {$oldGrab != ""} {
#	set grabStatus [grab status $oldGrab]
#    }
#    grab $w
#    if {$default >= 0} {
#	focus $w.button$default
#    } else {
#	focus $w
#    }
#
#    # 7. Wait for the user to respond, then restore the focus and
#    # return the index of the selected button.  Restore the focus
#    # before deleting the window, since otherwise the window manager
#    # may take the focus away so we can't redirect it.  Finally,
#    # restore any grab that was in effect.
#
#    tkwait variable tkPriv(button)
#    catch {focus $oldFocus}
#    destroy $w
#    if {$oldGrab != ""} {
#	if {$grabStatus == "global"} {
#	    grab -global $oldGrab
#	} else {
#	    grab $oldGrab
#	}
#    }
#    return $tkPriv(button)
#}
