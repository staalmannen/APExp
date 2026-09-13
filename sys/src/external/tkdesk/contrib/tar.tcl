# tar.tcl
#
# Author:	J. Chris Coppick, 1996 (Adapted from code by Christian Bolik)
# Description:	Implements a toplevel for listing and extracting tar files.
#
# Changes:
#
#   - patched to work with TkDesk 1.2 (J. Chris Coppick, 11.02.99)
#

# ----------------------------------------------------------------------------
# dsk_tar_browser:
#

# We'll use the same geometry as the find_files dialog for now, so we
# don't have to muck with the layout routines...
if ![info exists tkdesk(geometry,dsk_find_files)] {
    set tkdesk(geometry,dsk_find_files) ""
}

if [catch {set tkdesk(cmd,zcat)}] {
   set tkdesk(cmd,zcat) "zcat"
}

if [catch {set tkdesk(cmd,tar)}] {
   set tkdesk(cmd,tar) "/bin/tar"
}

global dsk_tar
set dsk_tar(file) ""
set dsk_tar(destdir) ""
set dsk_tar(compressed) {{*.gz} {*.Z} {*.z} {*.tgz} {*.taz}}

proc dsk_tar_browser {{file ""} {destdir ""}} {
    global tkdesk dsk_tar

    if {$file != ""} {
       set dsk_tar(file) $file
    }
    if {$destdir != ""} {
       set dsk_tar(destdir) $destdir
    }

    set t .dsk_tar_browser
    if [winfo exists $t] {
	cb_raise $t
	dsk_do_tar_list
	return
    }

    toplevel $t
    wm withdraw $t
    frame $t.f -bd 1 -relief raised
    pack $t.f -fill x

    # ---- File:
    frame $t.f1
    pack $t.f1 -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    label $t.lf -text "File:" -width 17 -anchor w
    entry $t.ef -bd 2 -relief sunken -width 40 -textvar dsk_tar(file)
    bind $t.ef <Return> "$t.bList.button flash ; $t.bList.button invoke"
    bind $t.ef <Control-Tab> {
       set selectdir [file dirname $dsk_tar(file)]
       if {$selectdir == ""} {
          set selectdir [string trimright [dsk_active dir] /]
       }
       set selected [cb_fileSelector -filter "$selectdir/*.tar*" \
                    -label "Select archive:" -showall 1]
       if {$selected != ""} {
          set dsk_tar(file) $selected
       }
    }
    cb_balloonHelp $t.ef "The archive file to examine."
    
    pack $t.lf $t.ef -in $t.f1 -side left -pady $tkdesk(pad)
    pack config $t.ef -fill x -ipady 2 -expand yes

    # ---- Destdir:
    frame $t.f2
    pack $t.f2 -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    label $t.ld -text "Destination:" -width 17 -anchor w
    entry $t.ed -bd 2 -relief sunken -width 40 -textvar dsk_tar(destdir)
    bind $t.ed <Return> "$t.bExt.button flash ; $t.bExt.button invoke"
    cb_bindForCompletion $t.ed <Control-Tab>
    cb_balloonHelp $t.ed "Destination directory for extractions."

    frame $t.fd2 -width 8
    menubutton $t.mbDir -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/slash.xbm \
		-menu $t.mbDir.menu
    cb_balloonHelp $t.mbDir "This menu contains the custom directories from the Directories menu."
    menu [set m $t.mbDir.menu] \
	    -postcommand "_dsk_dmenu $t.mbDir.menu $t.ed"
    # add dummy entry to work around bug in pre Tk 4.0p2:
    $m add command -label "dummy"

    menubutton $t.mbHist -bd 2 -relief raised \
		-bitmap @$tkdesk(library)/cb_tools/bitmaps/combo.xbm \
		-menu $t.mbHist.menu
    cb_balloonHelp $t.mbHist "This menu contains the directories you have last visited."
    menu $t.mbHist.menu -postcommand "_dsk_hmenu $t.mbHist.menu $t.ed"
    # add dummy entry to work around bug in pre Tk 4.0p2:
    $t.mbHist.menu add command -label "dummy"

    pack $t.ld $t.ed $t.fd2 $t.mbDir $t.mbHist -in $t.f2 -side left \
	    -pady $tkdesk(pad)
    pack config $t.ed -fill x -ipady 2 -expand yes
    pack config $t.mbDir $t.mbHist -ipadx 2 -ipady 2
   
    # ---- Buttons:
    frame $t.f5
    pack $t.f5 -in $t.f -fill x -expand yes -padx $tkdesk(pad)

    cb_button $t.bList -text " List " -default 1 \
	    -command dsk_do_tar_list
    cb_balloonHelp $t.bList.button "List the contents of the archive."
    cb_button $t.bExt -text " Extract " -default 1 \
	    -command dsk_do_tar_ext
    cb_balloonHelp $t.bExt.button "Extract files from the archive."
    cb_button $t.bClear -text " Clear Selection " -default 1 \
	    -command "$t.dlb select clear"
    cb_balloonHelp $t.bClear.button "Clear archive contents selection."
    button $t.bClose -text "  Close  " -command \
	    "set tkdesk(geometry,dsk_find_files) \[wm geometry $t\] ;\
	    destroy $t"
    cb_balloonHelp $t.bClose "Closes this dialog."
    
    pack $t.bList $t.bExt $t.bClear $t.bClose -in $t.f5 -side left \
	    -padx $tkdesk(pad) -pady $tkdesk(pad)
    pack config $t.bExt -ipady 1
    pack config $t.bClose -ipady 1

    # ---- dsk_Listbox:
    frame $t.flb -bd 1 -relief raised
    pack $t.flb -fill both -expand yes
    frame $t.f6
    pack $t.f6 -in $t.flb -fill both -expand yes -pady $tkdesk(pad)
    
    label $t.llb -text "Archive Contents:" -anchor w
    pack $t.llb -in $t.f6 -anchor w -padx $tkdesk(pad) 
    
    pack [_dsk_tar_lb $t.dlb] -in $t.f6 -fill both -expand yes


    wm title $t "Archive Browser"
    wm minsize $t 10 2
    dsk_place_window $t dsk_tar_browser 40x20 1
    #if {$tkdesk(geometry,dsk_find_files) == ""} {
    #	 wm geometry $t 10x5	
    #} else {
    #	 wm geometry $t $tkdesk(geometry,dsk_find_files)
    #}
    wm protocol $t WM_DELETE_WINDOW "$t.bClose invoke"
    wm deiconify $t
    update idletasks
    dsk_do_tar_list
}

# ----------------------------------------------------------------------------
# dsk_do_tar_list:
# Lists the archive contents with the parameters set through the dialog.
#
proc dsk_do_tar_list {} {
    global dsk_tar tkdesk

    if {$dsk_tar(file) == ""} {
       return
    }

    set compressed 0
    foreach ext $dsk_tar(compressed) {
       if {[string match $ext $dsk_tar(file)]} {
          incr compressed
       }
    }

    if {$compressed} {
       set cmd $tkdesk(cmd,zcat)
       append cmd " [cb_tilde $dsk_tar(file) expand]"
       append cmd " | $tkdesk(cmd,tar) tf -"
    } else {
       set cmd $tkdesk(cmd,tar)
       append cmd " tf [cb_tilde $dsk_tar(file) expand]"
    }

    set cmd [string_replace $cmd \[ \\\[]
    set cmd [string_replace $cmd \] \\\]]
    append cmd " 2>/dev/null"
    if $tkdesk(debug) {
	catch {puts stderr "$cmd"}
    }

    set t .dsk_tar_browser
    $t.dlb config -list {}
    $t.bList.button config -state disabled
    $t.llb config -text "Listing contents..."
    set contents [dsk_bgexec $cmd "Listing contents..."]
    catch {$t.bList.button config -state normal} ;# button may not exist
    if {$contents != "break"} {
	set cl [split $contents \n]
	set ll [llength $cl]
	if {$ll == 1} {
	    $t.llb config -text "Contains 1 file:"
	} elseif {$ll == 0} {
	    $t.llb config -text "Empty archive."
	} else {
	    $t.llb config -text "Contains $ll files:"
	}
	$t.dlb config -list $cl
    } else {
	catch {$t.llb config -text "List operation abandoned."}
    }
}

# ----------------------------------------------------------------------------
# dsk_do_tar_ext:
# Extracts the entire archive contents, or just the given files.
#
proc dsk_do_tar_ext {{files ""}} {
    global tkdesk dsk_tar

    if {$dsk_tar(file) == ""} {
       return
    }

    set compressed 0
    foreach ext $dsk_tar(compressed) {
       if {[string match $ext $dsk_tar(file)]} {
          incr compressed
       }
    }

    if {$compressed} {
       set cmd $tkdesk(cmd,zcat)
       append cmd " [cb_tilde $dsk_tar(file) expand]"
       append cmd " | $tkdesk(cmd,tar) xf -"
    } else {
       set cmd $tkdesk(cmd,tar)
       append cmd " xf [cb_tilde $dsk_tar(file) expand]"
    }
    
    set dest $dsk_tar(destdir)
    if {$dest == ""} {
       set dest [string trimright [dsk_active dir] /]
    }

    set t .dsk_tar_browser
    if {$files == ""} {
       set indices [$t.dlb select get]
       if {$indices != ""} {
          foreach i $indices {
	     lappend files [$t.dlb get $i]
	  }
       }
    }

    if {$files == ""} {
       set ans [cb_okcancel \
               "Extract into $dest?"]
    } elseif {[llength $files] == 1} {
       set ans [cb_okcancel \
               "Extract $files into $dest?"]
    } else {
       set ans [cb_okcancel \
               "Extract selected files into $dest?"]
    }

    if {$ans != 0} {
       return
    }

    append cmd " $files"

    set cmd [string_replace $cmd \[ \\\[]
    set cmd [string_replace $cmd \] \\\]]
    append cmd " 2>/dev/null"
    if $tkdesk(debug) {
	catch {puts stderr "$cmd"}
    }

    $t.dlb select clear
    $t.bExt.button config -state disabled
    set status [dsk_tar_bgexec $cmd $dest "Extracting..."]
    catch {$t.bExt.button config -state normal} ;# button may not exist
    if {$status == "break"} {
       cb_error "Extract failed."
    }
}

# ----------------------------------------------------------------------------
# _dsk_tar_lb name:
# Creates a dsk_Listbox for the tar dialogs with name $name.
#
proc _dsk_tar_lb {name} {
    global tkdesk

    catch {$name delete}
    
    dsk_Listbox $name -width 10 -height 2 -font $tkdesk(font,file_lbs) \
	    -bg $tkdesk(color,background)
    set name_frame [$name getFrame]
    $name_frame config -relief flat
    $name_frame.text config -tabs {465 right 480 left 575 left  635 left 695 \
	    left 775 left 795 left}
    
    bind $name_frame.text <Any-Double-1> "_dsk_tar_lb_ext $name %s"

    return $name_frame
}

# binding for double click:
proc _dsk_tar_lb_ext {dlb shift} {
    global tkdesk
    
    set tkdesk(file_lb,control) [expr $shift & 4]
    set sel [$dlb select get]
    if {$sel != ""} {
	set tmpfile [lindex [lindex [$dlb get] $sel] 0]
	if {$tmpfile != ""} {
	    dsk_do_tar_ext $tmpfile
	}
    }
}

# Version of dsk_bgexec that accepts a working directory argument.
proc dsk_tar_bgexec {cmd wd label} {
    global dsk_bgexec tkdesk

    set pad 8

    # ---- first create the "stand by" window

    set cnt [incr dsk_bgexec(cnt)]
    set t ".dsk_bgexec$cnt"
    catch "destroy $t"
    toplevel $t
    wm withdraw $t

    frame $t.fl -bd 1 -relief raised
    pack $t.fl -fill x

    label $t.label -text "$label" \
		-font -*-helvetica-bold-r-*-*-14-*-*-*-*-*-*-*
    pack $t.label -in $t.fl -side left -padx $pad -pady $pad

    frame $t.fb -bd 1 -relief raised
    pack $t.fb -fill x

    button $t.bBreak -text "  Stop  " \
	    -command "set dsk_bgexec(out$cnt) break ;\
	    set dsk_bgexec(stat$cnt) {} ;\
	    destroy .dsk_bgexec$cnt"
    pack $t.bBreak -in $t.fb -side top -padx $pad -pady $pad -ipady 2

    #grab $t
    wm title $t "Background #$cnt"
    wm protocol $t WM_DELETE_WINDOW {# ignore}
    if {$tkdesk(geometry,dsk_bgexec) == ""} {
	cb_centerToplevel $t
    } else {
	set g [split $tkdesk(geometry,dsk_bgexec) +x]
	set vw [winfo vrootwidth .]
	set vh [winfo vrootheight .]
	set x [lindex $g 2]
	while {$x < 0} {incr x $vw}
	while {$x > $vw} {incr x -$vw}
	set y [lindex $g 3]
	while {$y < 0} {incr y $vh}
	while {$y > $vh} {incr y -$vh}
	wm geometry $t +$x+$y
	wm deiconify $t
    }
    update

    # ---- now execute cmd

    catch "unset dsk_bgexec(cmd$cnt)"
    catch "unset dsk_bgexec(err$cnt)"
    set owd [pwd]
    if {[catch "cd $wd"]} {
       catch "destroy $t"
       cb_error "Invalid working directory: $wd"
       return "error"
    }
    set tkdesk(bgexec,working) 1
    #eval blt_bgexec -errorvar dsk_bgexec(err$cnt) dsk_bgexec(out$cnt) $cmd
    eval blt_bgexec dsk_bgexec(stat$cnt) \
	    -output dsk_bgexec(out$cnt) \
	    -error dsk_bgexec(err$cnt) $cmd &
    tkwait variable dsk_bgexec(stat$cnt)
    
    set tkdesk(bgexec,working) 0
    catch {set tkdesk(geometry,dsk_bgexec) [wm geometry $t]}
    catch "destroy $t"
    if [catch "cd $owd"] {
	# maybe $owd has just been deleted
	cd $tkdesk(startdir)
    }
    incr dsk_bgexec(cnt) -1

    if ![info exists dsk_bgexec(err$cnt)] {
	return $dsk_bgexec(out$cnt)
    } elseif {$dsk_bgexec(err$cnt) != ""} {
	dsk_errbell
	cb_error "$dsk_bgexec(err$cnt)"
    	return "error"
    } else {
	return $dsk_bgexec(out$cnt)
    }
}
