
#################
# rcs routines
# created by John Blair, jdblair@uab.edu, mar.97
# these routines may be distributed under the same conditions as TkDesk (GPL)

#
# check in a file
#
proc jdb_rcs_ci {file} {
    global jdb_rcs_ci tkdesk

    # set important variables
    set jdb_rcs_ci(file) $file
    regexp {^(.+)/[^/]+$} $file match dir
    set jdb_rcs_ci(rcsdir) "$dir/RCS"
    set jdb_rcs_ci(filetail) [file tail $file]
    set t .jdb_rcs_ci

    # see if RCS exists or needs to be created
    if [file exists $jdb_rcs_ci(rcsdir)] {
	if ![file isdirectory $jdb_rcs_ci(rcsdir)] {
	    jdb_output {Error} "The file $jdb_rcs_ci(rcsdir) exists but is not a directory.\nIf you want to use RCS you'll need to move this file and\ncreate a directory called RCS."
	    return
	}
    } else {
	file mkdir $jdb_rcs_ci(rcsdir)
    }

    # draw window, contents
    toplevel $t
    wm withdraw $t

    frame $t.h -bd 1 -relief raised
    label $t.h.l -text "description of this version of $jdb_rcs_ci(filetail):"
    frame $t.tf -bd 1 -relief raised
    frame $t.tf.f
    frame $t.bf -bd 1 -relief raised

    text $t.tf.f.text -yscrollcommand [list $t.tf.f.sy set] -width 50 -height 6
    scrollbar $t.tf.f.sy -orient vertical -command [list $t.tf.f.text yview]
#    bind $t.tf.f.text <Tab> {focus .jdb_rcs_ci.bf.ok}

    pack $t.h -side top -fill x
    pack $t.h.l -side left -fill x
    pack $t.bf -side bottom -fill x
    pack $t.tf -fill both -expand yes -fill both
    pack $t.tf.f -fill both -expand yes -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $t.tf.f.sy -side right -fill y
    pack $t.tf.f.text -side left -fill both -expand true

    # define buttons
    cb_button $t.bf.ok -default 1 -text "  Check In  " -underline 2 -command {
	# 'ci' is actually called here
	# The log message is piped into STDIN.
	# Any output is caught with 'catch' and displayed.
	# The RCS archive file location is explicitly defined because I was
	# considering eventually adding a mechanism to handle central RCS dirs
	set ci [open "|ci $jdb_rcs_ci(comode) $jdb_rcs_ci(file) $jdb_rcs_ci(rcsdir)/$jdb_rcs_ci(filetail),v" w]
	puts $ci [.jdb_rcs_ci.tf.f.text get 0.1 end]
	puts $ci "."
	destroy .jdb_rcs_ci
	if [catch {set ci [close $ci]} result] {
	    jdb_output "Check In" $result
	}
	return true
    }

    cb_button $t.bf.cancel -text "  Cancel  " -underline 2 -command {
	destroy .jdb_rcs_ci
	return false
    }
    
    set jdb_rcs_ci(colabels) {
	{then check out locked}
	{then check out unlocked}
	{then don't check out}
    }

    set jdb_rcs_ci(comodes) {{-l} {-u} {}}
    
    menubutton $t.bf.mb -text "then check out locked" -menu $t.bf.mb.menu -relief raised -borderwidth 2
    set m [menu $t.bf.mb.menu -tearoff 1]
    set jdb_rcs_ci(comode) {-l}
    set labelnum 0
    foreach label $jdb_rcs_ci(colabels) {
	set mode [lindex $jdb_rcs_ci(comodes) $labelnum]
	$m add command -label $label -command "
	    .jdb_rcs_ci.bf.mb configure -text {$label}
	    set jdb_rcs_ci(comode) {$mode}"
	incr labelnum
    }

    pack $t.bf.ok -side left -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $t.bf.cancel -side left -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $t.bf.mb -side left -padx $tkdesk(pad) -pady $tkdesk(pad)

    wm minsize $t 268 107
    wm title $t "Check In"
    wm protocol $t WM_DELETE_WINDOW {$t.bf.close invoke}

    dsk_place_window $t sel_buffer "" 0 1
    wm deiconify $t
}

#
# pop up a list of files to check out
#
proc jdb_rcs_co {directory} {
    global jdb_rcs_co tkdesk

    set t .jdb_rcs_co

    if [winfo exists $t] {
	destroy $t
    }

    set jdb_rcs_co(dir) $directory
    set jdb_rcs_co(rcsdir) "$directory/RCS"
    
    toplevel $t
    wm withdraw $t
    
    frame $t.tf -bd 1 -relief raised
    frame $t.tf.f
    frame $t.bf -bd 1 -relief raised

    listbox $t.tf.f.list -yscrollcommand [list $t.tf.f.sy set] -selectmode single -height 5
    scrollbar $t.tf.f.sy -orient vertical -command [list $t.tf.f.list yview]
    bind $t.tf.f.list <Double-1> {.jdb_rcs_co.bf.co invoke}
    bind $t <KeyPress-Return> {.jdb_rcs_co.bf.co invoke}

    # fill contents of list
    set jdb_rcs_co(realfiles) {}
    set jdb_rcs_co(contents) [glob -nocomplain "$jdb_rcs_co(rcsdir)/*,v"]
    foreach item $jdb_rcs_co(contents) {
	regexp {^(.*),v$} $item match thefile
	set filetail [file tail $thefile]
	$t.tf.f.list insert end $filetail
	lappend jdb_rcs_co(realfiles) "$jdb_rcs_co(dir)/$filetail"
    }
    $t.tf.f.list selection set 0

    pack $t.bf -side bottom -fill x
    pack $t.tf -fill both -expand yes -fill both
    pack $t.tf.f -fill both -expand yes -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $t.tf.f.sy -side right -fill y
    pack $t.tf.f.list -side left -fill both -expand true

    button $t.bf.co -text "  Check Out  " -underline 2 -command {
	set jdb_rcs_co(doco) 1
	set cofile [ lindex $jdb_rcs_co(contents) [.jdb_rcs_co.tf.f.list curselection]]
	set realfile [lindex $jdb_rcs_co(realfiles) [.jdb_rcs_co.tf.f.list curselection]]
	set realfiletail [file tail $realfile]
	destroy .jdb_rcs_co
	if [file exists $realfile] {
	    set jdb_rcs_co(doco) 0
	    dsk_confirm "Are you sure you want to overwrite $realfiletail with the version last checked in?" "global jdb_rcs_co; file delete $realfile; set jdb_rcs_co(doco) 1"
	}
	if $jdb_rcs_co(doco) {
	    if [catch {exec co -l $cofile $realfile} result] {
		jdb_output "Check Out" $result
	    }
	}
    }

    button $t.bf.cancel -text "  Cancel  " -underline 2 -command {
	destroy .jdb_rcs_co
    }

    button $t.bf.rlog -text "  View Log  " -underline 2 -command {
	jdb_rcs_rlog [ lindex $jdb_rcs_co(contents) [.jdb_rcs_co.tf.f.list curselection]]
    }

    pack $t.bf.co -side left -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $t.bf.cancel -side left -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $t.bf.rlog -side left -padx $tkdesk(pad) -pady $tkdesk(pad)

    wm minsize $t 302 140
    wm title $t "Check Out"
    wm protocol $t WM_DELETE_WINDOW {$t.bf.close invoke}

    dsk_place_window $t sel_buffer "" 0 1
    wm deiconify $t
}


proc jdb_output {title msg {btnstring {OK}}} {
    global jdb_output tkdesk

    set t .jdb_output
    set jdb_output(done) false

    # draw window, contents
    toplevel $t
    wm withdraw $t

    frame $t.t -bd 1 -relief raised
    message $t.t.text -justify left -text $msg -width 500
    frame $t.b -bd 1 -relief raised
    cb_button $t.b.ok -text "  $btnstring  " -default 1 -underline 2 -command {
	destroy .jdb_output
	set jdb_output(done) true
    }

    pack $t.t -side top -fill both -expand yes
    pack $t.t.text -fill both -expand yes -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack $t.b -fill x -expand yes
    pack $t.b.ok -side left -expand yes -padx $tkdesk(pad) -pady $tkdesk(pad)

    wm title $t $title
    wm protocol $t WM_DELETE_WINDOW {$t.bf.close invoke}

    dsk_place_window $t sel_buffer "" 0 1
    wm deiconify $t

    vwait jdb_output(done)
}

#
# display the log associated with an RCS file
#
proc jdb_rcs_rlog {file} {
    dsk_view rlog $file
}

