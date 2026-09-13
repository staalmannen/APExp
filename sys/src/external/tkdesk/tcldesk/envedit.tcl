
proc dsk_env_edit {} {
    global tkdesk

    set pad 4
    
    set t .dsk_env_edit
    if [winfo exists $t] {
	if {[wm state $t] == "iconic"} {
	    wm deiconify $t
	} else {
	    raise $t
	}
	return $t
    }
    
    toplevel $t
    wm withdraw $t

    frame $t.fe -bd 1 -relief raised
    pack $t.fe -fill both -expand y

    label $t.header -text "Environment Variables:" -anchor w \
	    -font [cb_font $tkdesk(font,labels)]
    pack $t.header -in $t.fe -padx $pad -pady $pad -fill x
    
    cb_listbox $t.list -vscroll 1 -height 8 -lborder 1 \
	    -font [cb_font $tkdesk(font,entries)]
	    #-highlightthickness 2 -takefocus 1
    pack $t.list -in $t.fe -fill both -expand y

    entry $t.env -bd 2 -relief sunken -width 10
    pack $t.env -in $t.fe -padx $pad -pady $pad -fill x -ipadx 1 -ipady 1

    cb_text $t.val -bd 2 -relief sunken -vscroll 1 -width 10 -height 2 \
	    -setgrid 0
    pack $t.val -in $t.fe -padx $pad -pady $pad -fill both -expand y

    
    frame $t.fb -bd 1 -relief raised
    pack $t.fb -fill x

    cb_button $t.bOK -text "OK" -default 1 -width 6 -underline 0 \
	    -command "_dsk_env_set $t; $t.bClose.button invoke"
    cb_button $t.bApply -text "Apply" -width 6 -underline 0 \
	    -command "_dsk_env_set $t; _dsk_env_fill_listbox"
    cb_button $t.bClose -text "Close" -width 6 -underline 0 \
	    -command "set tkdesk(geometry,env_edit) \[wm geometry $t\];
                      destroy $t"
    cb_addShortcutBinding $t.env $t.bOK.button "o"
    cb_addShortcutBinding $t.env $t.bApply.button "a"
    cb_addShortcutBinding $t.env $t.bClose.button "c"
    bind $t.env <Escape> "$t.bClose.button invoke"
    cb_addShortcutBinding $t.val.text $t.bOK.button "o"
    cb_addShortcutBinding $t.val.text $t.bApply.button "a"
    cb_addShortcutBinding $t.val.text $t.bClose.button "c"
    bind $t.val.text <Escape> "$t.bClose.button invoke"

    pack $t.bOK $t.bApply $t.bClose -in $t.fb -side left \
	    -padx $pad -pady $pad

    _dsk_env_fill_listbox $t.list.lbox
    bind $t.list.lbox <ButtonRelease-1> "_dsk_env_list_click $t %y"

    dsk_place_window $t env_edit "" 1 1
    wm title $t "Edit Environment"
    wm minsize $t 258 288
    wm deiconify $t
    
    return $t
}


proc _dsk_env_fill_listbox {{lbox ""}} {
    global env

    if {$lbox == ""} {
	set lbox ".dsk_env_edit.list.lbox"
    }
    
    $lbox delete 0 end
    foreach ev [lsort [array names env]] {
	$lbox insert end $ev
    }
}


proc _dsk_env_list_click {t y} {
    global env

    set lb $t.list.lbox
    set ev [$lb get [$lb nearest $y]]
    $lb activate [$lb nearest $y]
    
    $t.env delete 0 end
    $t.env insert end $ev
    
    $t.val.text delete 1.0 end
    $t.val.text insert end $env($ev)
    
}


proc _dsk_env_set {t} {
    global env

    set ev  [$t.env get]
    if {$ev == ""} {
	return
    }
    
    set val [string trimright [$t.val.text get 1.0 end] "\n"]
    if {$val == ""} {
	catch {
	    unset env($ev)
	    $t.list.lbox delete active
	}
	return
    }

    set env($ev) $val
}
