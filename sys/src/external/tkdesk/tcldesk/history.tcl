# =============================================================================
#
# File:		history.tcl
# Project:	TkDesk
#
# Started:	12.10.94
# Changed:	18.09.96
# Author:	cb
#
# -----------------------------------------------------------------------------
#
# Sections:
#s    itcl_class dsk_history
#s    method add {entry {dontmove 0}}
#s    method get {}
#s    method forward {}
#s    method back {}
#s    method buildmenu {menu {open ""}}
#s    method _limit_entry {str}
#s    method changed {}
#
# =============================================================================

#
# =============================================================================
#
# Class:	dsk_history
# Desc:		Implements a generic class for managing history lists.
#
# Methods:	add <path>	adds $path to history
#		get		returns the history list
# Procs:	
# Publics:	size		size of history list
#

itcl_class dsk_history {

    constructor {config} {
    }

    destructor {
    }

    #
    # ----- Methods and Procs -------------------------------------------------
    #

    method add {entry {dontmove 0}} {
	global tkdesk

	if {$lock && !$dontmove} {
	    set lock 0
	    return
	}
	
	if {$entry != "/" && $command == "" && $callback == ""} {
	    set entry [string trimright $entry "/"]
	    if {[string first "$tkdesk(trashdir)" $entry] == 0 || \
		    [string first "$tkdesk(configdir)/.shelf" $entry] == 0} {
		return
	    }
	}
	if {[llength $entry] > 1} {
	    set entry [list $entry]
	}
	#puts "to add:   $entry"
	#puts "current:  $list"
	#puts "pointer:  $pointer"
	#puts "dontmove: $dontmove"
	set i [lsearch -exact $list [lindex $entry 0]]
	if {$i > -1} {
	    set list "$entry [lreplace $list $i $i]"
	} else {
	    set list "$entry $list"
	    if {[llength $list] > $size} {
		set list [lrange $list 0 [expr [llength $list] - 2]]
	    }
	}
	#puts "dirbuf:   $dirbuf"
	#puts ""
	set pointer 0
	set changed 1
	return $list
    }

    method get {} {
	return $list
    }

    method remove {entry} {
	set l [lsearch -exact $list $entry]
	if {$l > -1} {
	    set list [lreplace $list $l $l]
	    set changed 1
	} else {
	    dsk_errbell
	}
    }

    method forward {} {
	set lock 1
	if {$pointer > 0} {
	    incr pointer -1
	    return [lindex $list $pointer]
	} else {
	    set lock 0
	    dsk_bell
	    return ""
	}
    }

    method back {} {
	global env

	if {$pointer == 0} {
	    # add current directory to history
	    set curdir [dsk_active dir]
	    if {[string first $env(HOME) $curdir] == 0} {
		dir_history add [string_replace $curdir $env(HOME) ~]
	    } else {
		dir_history add $curdir
	    }
	}

	set lock 1
	if {$pointer < [llength $list] - 1} {
	    incr pointer
	    return [lindex $list $pointer]
	} else {
	    set lock 0
	    dsk_bell
	    return ""
	}
    }

    method last {} {
	# "last" means the latest entry which happens to be first in the list
	return [lindex $list 0]
    }

    method buildmenu {menu {open ""}} {
	global tkdesk

	if {!$changed && $menu == $last_menu} {
	    return
	}

	catch "$menu delete 0 last"
	# transform sth. like .fv0-frame.mbHist.menu into .fv0:
	if {$tkdesk(tcl_version) >= 8.0} {
	    set toplevel ::[lindex [split $menu -] 0]
	} else {
	    set toplevel [lindex [split $menu -] 0]
	}
	if {$tkdesk(sort_history)} {
	    set l [lsort $list]
	} else {
	    set l $list
	}
	if {$callback != ""} {
	    set ne 0
	    foreach entry $l {
		$menu add command -label [_limit_entry $entry] \
		-command "$callback $toplevel \{[dskC_esc $entry \{\}]\}" \
			-font [cb_font $tkdesk(font,entries)]
		incr ne
		if {$ne > $tkdesk(_max_menu_entries)} {
		    set om $menu
		    $menu add cascade -label "More..." \
			    -menu [set menu $menu.c$ne]
		    catch {destroy $menu}; menu $menu; set ne 0
		    foreach b [bind $om] {bind $menu $b [bind $om $b]}
		}
	    }
	} elseif {$command != ""} {
	    set ne 0
	    foreach entry $l {
		$menu add command -label [_limit_entry $entry] \
			-command "$command [list $entry]" \
			-font [cb_font $tkdesk(font,entries)]
		incr ne
		if {$ne > $tkdesk(_max_menu_entries)} {
		    set om $menu
		    $menu add cascade -label "More..." \
			    -menu [set menu $menu.c$ne]
		    catch {destroy $menu}; menu $menu; set ne 0
		    foreach b [bind $om] {bind $menu $b [bind $om $b]}
		}
	    }
	} else {
	    # history of directories
	    if {$open == ""} {
		set ne 0
		foreach entry $l {
		    # IMPORTANT: Don't use -directory below (but -dir) !!
		    $menu add command -label [_limit_entry $entry] \
			    -command "$toplevel config -dir \{$entry\}" \
			    -font [cb_font $tkdesk(font,entries)]
		    incr ne
		    if {$ne > $tkdesk(_max_menu_entries)} {
			set om $menu
			$menu add cascade -label "More..." \
				-menu [set menu $menu.c$ne]
			catch {destroy $menu}; menu $menu; set ne 0
			foreach b [bind $om] {bind $menu $b [bind $om $b]}
		    }
		}
	    } else {
		set ne 0
		foreach entry $l {
		    $menu add command -label [_limit_entry $entry] \
			    -command "dsk_open_dir [list $entry]" \
			    -font [cb_font $tkdesk(font,entries)]
		    incr ne
		    if {$ne > $tkdesk(_max_menu_entries)} {
			set om $menu
			$menu add cascade -label "More..." \
				-menu [set menu $menu.c$ne]
			catch {destroy $menu}; menu $menu; set ne 0
			foreach b [bind $om] {bind $menu $b [bind $om $b]}
		    }
		}
	    }
	}
	set changed 0
	set last_menu $menu

	if {$tkdesk(tcl_version) >= 8.0} {
	    set nthis [namespace tail $this]
	} else {
	    set nthis $this
	}
	if {$nthis == "dir_history" || $nthis == "file_history"} {
	    bind $menu <B3-ButtonPress-1> {
		#puts "[%W entrycget [%W index active] -label]"
		after 100
		dsk_popup {} [%W entrycget [%W index active] -label] %X %Y
		break
	    }
	    bind $menu <B3-ButtonRelease-1> break
	    bind $menu <B1-ButtonPress-3> [bind $menu <B3-ButtonPress-1>]
	    bind $menu <B1-ButtonRelease-3> break
	} else {
	    bind $menu <B3-ButtonPress-1> break
	    bind $menu <B3-ButtonRelease-1> break
	    bind $menu <B1-ButtonPress-3> break
	    bind $menu <B1-ButtonRelease-3> break
	}
    }

    method _limit_entry {str} {
	if {[string length $str] > $max_entry_length} {
	    return [string range $str 0 $max_entry_length]...
	} else {
	    return $str
	}
    }

    method changed {} {
	set changed 1
    }

    #
    # ----- Variables ---------------------------------------------------------
    #

    public size 20
    public command ""
    public callback ""

    protected list {}
    protected changed 1
    protected last_menu ""
    protected pointer 0
    protected lock 0
    protected dirbuf ""

    common max_entry_length 80
}

