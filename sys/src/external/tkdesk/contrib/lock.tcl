
# lock.tcl
#
# Author:	J. Chris Coppick, 1998
# Description:
#
#	Implements a menu for selecting Xlock modes.
#
#	(I did try just a normal appbar menu with a command for each mode,
#	but TkDesk, or more specifically Tcl7/Tk4, doesn't handle really
#	long menus very well.  At least, not for me.)
#
#	I hacked this up pretty fast, so caveat receptor.
#
# Usage:
#
#	Source this from your .tkdesk/Local file and add an entry for
#	dsk_lock_menu to your appbar.  Dsk_lock_menu displays a list
#	of lock modes for you to choose from.  I've included nearly
#	all the modes available in the Xlockmore distribution, but
#	the mode list is customizable.  The lock program to use
#	is customizable as well.  (As a matter of fact, this code could
#	be generalized as a way to provide a defined set of arguments
#	to an arbitrary command, but I'm not going to go there...)
#	Whatever command is used, it must except the selected mode name
#	as the first argument after the given command string.  For example...
#
#	Correct command string: "xlock -nolock -mode"
#
#	Incorrect command string: "xlock -mode -nolock"
#
# Variables:
#
#	You can use the following variables in your Appbar file to override
#	the defaults.
#
#	tkdesk(appbar,lock,program) - The default for this is ~/bin/screenlock
#	which is a script that I use to wrap xlock.  Makes it easier for
#	me to customize my xlock arguments, add sound, etc.
#
#	tkdesk(appbar,lock,modes) - List of available modes to provide.
#
#	tkdesk(appbar,lock,opts,MODE) - Options can be provided on a per-mode
#	basis by setting variables of this form where MODE is replaced by
#	a specific mode name, e.g. 'tkdesk(appbar,lock,opts,hop)'.  (See
#	examples below.)
#
# Example Appbar:
#
#   {{next/keys.xpm} {
#       {{Screen Locks}}
#       -
#       {{Default} {dsk_exec ~/bin/screenlock &}}
#       {{Blank Screen} {dsk_exec xlock -nolock -mode blank}}
#       {{Random} {dsk_exec ~/bin/screenlock random &}}
#       {{Mode Menu...} {dsk_lock_menu}}
#       -
#       {{X Saver On} {dsk_exec xset s on}}
#       {{X Saver Off} {dsk_exec xset s off}}
#   }}
#
########

# Variable defaults...

if [catch {set tkdesk(appbar,lock,program)}] {
   set tkdesk(appbar,lock,program) {~/bin/screenlock}
}

if [catch {set tkdesk(appbar,lock,modes)}] {
   set tkdesk(appbar,lock,modes) [list \
      ant ball bat blot bouboule bounce braid bug bubble \
      cartoon clock coral crystal daisy dclock deco demon dilemma drift \
      eyes fadeplot flag flame forest galaxy grav helix hop hyper \
      ico ifs image julia kaleid laser life life1d life3d lightning lisa \
      lissie loop mandelbrot marquee maze mountain munch nose pacman penrose \
      petal puzzle pyro qix roll rotor shape sierpinski slip sphere spiral \
      spline star strange swarm swirl triangle tube turtle vines voters \
      wator wire world worm \
   ]
}

# Example per-mode option variables
#set tkdesk(appbar,lock,opts,ball) {-size 100}
#set tkdesk(appbar,lock,opts,hop) {-sine}

# El programmo...

global dsk_LockMenu

# User hook to launch mode selector...
proc dsk_lock_menu {} {
    global tkdesk dsk_LockMenu

    set t .dsk_LockMenu
    if [winfo exists $t] {
	cb_raise $t
	return
    }

    toplevel $t
    wm withdraw $t
    frame $t.f -bd 1 -relief raised
    pack $t.f -fill x

    # Command entry...
    frame $t.f1
    pack $t.f1 -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    label $t.lf -text "Lock Command:" -width 17 -anchor w
    entry $t.ef -bd 2 -relief sunken -width 40 \
       -textvar tkdesk(appbar,lock,program)
    bind $t.ef <Control-Tab> {
       set selectdir [file dirname $tkdesk(appbar,lock,program)]
       if {$selectdir == ""} {
          set selectdir [string trimright [dsk_active dir] /]
       }
       set selected [cb_fileSelector -label "Select lock command:" -showall 1]
       if {$selected != ""} {
          set tkdesk(appbar,lock,program) $selected
       }
    }
    cb_balloonHelp $t.ef "Command to launch Xlock.  Use Ctrl-Tab to launch file selector."
    
    pack $t.lf $t.ef -in $t.f1 -side left -pady $tkdesk(pad)
    pack config $t.ef -fill x -ipady 2 -expand yes

    # Modes listbox...
    frame $t.flb -bd 1 -relief raised
    pack $t.flb -in $t.f -fill both -expand yes
    frame $t.f2
    pack $t.f2 -in $t.flb -fill both -expand yes -pady $tkdesk(pad)
    
    label $t.llb -text "Modes:" -anchor w
    pack $t.llb -in $t.f2 -anchor w -padx $tkdesk(pad) 

    set $t.dlb [dsk_Listbox $t.dlb -width 10 -height 10 \
                -font $tkdesk(font,file_lbs) \
	        -bg $tkdesk(color,background)]
    $t.dlb-frame config -relief flat
    
    bind $t.dlb.text <Any-Double-1> "_dsk_lock_exec $t.dlb"

    # load modes in selector...
    $t.dlb config -list $tkdesk(appbar,lock,modes)
    
    pack $t.dlb -in $t.flb -fill both -expand yes

    # Buttons...
    frame $t.f3
    pack $t.f3 -in $t.f -expand yes -padx $tkdesk(pad)

    cb_button $t.bLock -text " Lock " -default 1 \
	    -command "_dsk_lock_exec $t.dlb"
    cb_balloonHelp $t.bLock.button "Lock the screen."

    button $t.bClose -text "  Close  " -command \
	    "wm withdraw $t"
    cb_balloonHelp $t.bClose "Closes this dialog."
    
    pack $t.bLock $t.bClose -in $t.f3 -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack config $t.bClose -ipady 1

    wm title $t "Screen Lock Menu"
    wm minsize $t 10 10
    # dsk_place_window $t dsk_lock_menu 10x10 1
    wm protocol $t WM_DELETE_WINDOW "$t.bClose invoke"
    wm deiconify $t
    update idletasks
}

# Launch lock program (and close selector)...
proc _dsk_lock_exec {w} {
   global tkdesk .dsk_LockMenu

   set sel [$w select get]
   if {$sel != ""} {
      set mode [lindex [lindex [$w get] $sel] 0]
      if {$mode != ""} {
         .dsk_LockMenu.bClose invoke
         if [catch {set tkdesk(appbar,lock,opts,$mode)}] {
	    set opts ""
	 } else {
	    set opts $tkdesk(appbar,lock,opts,$mode)
	 }
	 append cmd $tkdesk(appbar,lock,program) " " $mode " " $opts " &"
         eval dsk_exec $cmd
      } else {
         cb_alert "No lock mode selected"
      }
   } else {
      cb_alert "No lock mode selected"
   }
}


