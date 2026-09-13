# =============================================================================
#
# File:		cb_help.tcl
# Project:	cb_tools
# Requires:     Tcl 7.4, Tk 4.0
#
# Started:	19.04.95
# Changed:	10.07.95
# Author:       Christian Bolik (zzhibol@rrzn-user.uni-hannover.de)
#
# Description:	Provides a wrapper proc for (quite) simple help windows.
#               Needs the egrep utility to find the headings.
#
# =============================================================================


# (NOTE: The following applies only partially to this implementation.)
#
# =============================================================================
#
# Class:	cb_Help
# Desc:		Implements a class for rather sophisticated online help.
#               This creates a toplevel window that contains a listbox that
#               lists all the "headers" of the help file (which is simple
#               ascii), a text widget that displays the help file and an
#               entry for searching.
#               The help file is a simple ascii file that may be structured
#               by numbered or any other kind of headings. Cross references
#               are enclosed within `` and ''. If the first word inside the
#               cross reference is one of @file, @shell or @eval the reference
#               will be interpreted like this:
#
#                   ``@file <file> ?<regexp>?'' loads <file> into a new window.
#                            <file> may also be of the form "|<command>" and
#                            <filename>#<keyword>.
#                   ``@shell <command>'' executes <command> when clicked.
#                   ``@eval <script>'' evaluates the tcl-script <script> at
#                            global level.
#
# Interface:    None of the methods should be used from outside the class
#               since the functionality is provided at a higher level through
#               the following class procs:
#
#               cb_Help :: show <file> ?<regexp>? ?<indent>?
#                   If <file> has not yet been loaded this creates a new help
#                   window that displays <file>, else the respective window
#                   is made visible. <regexp> is used to define the "headings"
#                   of <file> and may be any egrep-style regular expression or
#                   one of: numbered, howto, subjects, man, c, tcl. If <regexp>
#                   is omitted the heading listbox will not be displayed.
#                   <indent> is a boolean value used to signal the headings
#                   should be indented depending on their respective level.
#                   This is only used if <regexp> is a true regular expression.
#
#               cb_Help :: bind_for_context <widgets> <refs> ?<fallback>?
#                   Binds all widgets in <widgets> so that F1 invokes the
#                   "show" proc on the value of the respective array-variable
#                   of <refs>. <refs> is a global array whose indices are the
#                   widget names for whom there is help available.
#                   <fallback> is a list like {<file> ?<regexp>?} and will
#                   be passed to cb_Help :: show when there is no item for
#                   the current widget.
#
#               cb_Help :: setfont <font>
#                   Makes <font> the standard font for help windows.
#

proc cb_help {cmd args} {
    switch $cmd {
	show {
	    return [eval _cb_help_proc:show $args]
	}
	context {
	    eval _cb_help_proc:context $args
	}
	bind_for_context {
	    eval _cb_help_proc:bind_for_context $args
	}
	id {
	    eval _cb_help_proc:id $args
	}
	setfont {
	    eval _cb_help_proc:setfont $args
	}
	textbg {
	    eval _cb_help_proc:textbg $args
	}
    }
}


proc _cb_help_create {args} {
    global cb_tools cb_help tk_strictMotif cb_help_context tkdesk

    #
    # Set configs
    #
    set this .cb_help[incr cb_help(number)]
    _cb_help_conf_defaults $this
    for {set i 0} {$i < [llength $args]} {incr i} {
	set var [string trimleft [lindex $args $i] "-"]
	set val [lindex $args [incr i]]
	#puts "$var: $val"
	set cb_help($this,public,$var) $val 
	if {[info procs _cb_help_conf:$var] != ""} {
	    _cb_help_conf:$var $this
	}
    }

    #
    # Create a new toplevel:
    #
    
    toplevel $this -class cb_help
    wm withdraw $this

    if {[winfo depth .] > 1} {set cb_help($this,private,is_color) 1} {set cb_help($this,private,is_color) 0}

    # the entry and button bar:
    frame $this.fb -bd 1 -relief raised
    pack $this.fb -fill x -side bottom

    label $this.ls -text "Search (regexp):"
    pack $this.ls -in $this.fb -side left -padx $cb_help($this,public,pad)

    entry $this.es -bd 2 -relief sunken -width 10 -font $cb_help(font)
    #if {$tbgcolor != ""} {
     #   $this.es config -bg $tbgcolor
    #}
    pack $this.es -in $this.fb -side left -pady $cb_help($this,public,pad) -ipady 2 \
    	-fill x -expand yes

    frame $this.fsep -width 16
    pack $this.fsep -in $this.fb -side left
    
    set ipad [expr $tk_strictMotif ? 2 : 0]
    
    button $this.bClose -text "  Close  " -command "_cb_help_delete $this" \
    	-underline 2
    pack $this.bClose -in $this.fb -side right -ipady $ipad \
	    -padx $cb_help($this,public,pad) -pady $cb_help($this,public,pad)
    if [info exists tkdesk(cmd,print)] {
	button $this.bPrint -text "  Print  " \
		-command "dsk_print_string \[$this.ft.text get 1.0 end\]" \
		-underline 2
	pack $this.bPrint -in $this.fb -side right -ipady $ipad \
		-padx $cb_help($this,public,pad) \
		-pady $cb_help($this,public,pad)
    }
    button $this.bBack -text "  Back  " \
	    -command "_cb_help__scroll $this back" \
	    -underline 2
    pack $this.bBack -in $this.fb -side right -ipady $ipad \
	    -padx $cb_help($this,public,pad) -pady $cb_help($this,public,pad)

    if {$cb_help($this,public,regexp) != "" && \
	    $cb_help($this,private,fmode) != "context"} {
        # the listbox:
        frame $this.fflb -bd 1 -relief raised
        pack $this.fflb -fill x -side top
        
        cb_listbox $this.flb -vscroll 1 -hscroll 0 -lborder 1 -uborder 0 \
    	    -rbuttons 1 -width 10 -height 8 \
    	    -bd 2 -relief sunken -takefocus 0
        $this.flb.lbox config -selectmode browse
	if {$cb_help(lbfont) != ""} {
	    $this.flb.lbox config -font $cb_help(lbfont)
	}
        pack $this.flb -in $this.fflb -fill both -expand yes -pady $cb_help($this,public,pad)

        bind $this.flb.lbox <1> "
    	%W select clear 0 end
    	%W select set \[%W nearest %y\]
    	_cb_help__scroll $this to \
    		\[lindex \[lindex \[_cb_help_headings $this\] \
    		\[%W nearest %y\]\] 0\]; break
        "

        bind $this.es <Tab> "_cb_help__scroll $this next; break"
        bind $this.es <Shift-Tab> "_cb_help__scroll $this previous; break"
        bind $this.es <Control-Tab> "_cb_help__scroll $this bottom; break"
        bind $this.es <Control-Shift-Tab> "_cb_help__scroll $this top; break"
    }

    # the textwidget:
    frame $this.fft -bd 1 -relief raised
    pack $this.fft -fill both -expand yes -side top
    
    cb_text $this.ft -vscroll 1 -lborder 1 -width 20 -height 5 \
    	-bd 2 -relief sunken -state disabled -setgrid 0 -wrap word \
    	-font $cb_help(font) -cursor top_left_arrow -highlightthickness 0
    if {$cb_help(tbgcolor) != ""} {
        $this.ft.text config -bg $cb_help(tbgcolor)
    }
    if [info exists cb_help(filemode,$cb_help($this,private,fmode),font,body)] {
        $this.ft.text config -font [cb_font $cb_help(filemode,$cb_help($this,private,fmode),font,body)]
    }
    pack $this.ft -in $this.fft -fill both -expand yes \
    	-pady $cb_help($this,public,pad)

    # create heading tags:
    if [info exists cb_help(filemode,$cb_help($this,private,fmode),font,body)] {
        $this.ft.text tag configure subject \
    	    -font [cb_font $cb_help(filemode,$cb_help($this,private,fmode),font,subject)] \
    	    -underline 1
    } else {
        $this.ft.text tag configure subject \
		-font $cb_help(headfonts,subject) \
		-underline 1
    }
    for {set i 1} {$i <= 6} {incr i} {
        $this.ft.text tag configure level$i -font $cb_help(headfonts,l$i) \
    	-underline 1
    }

    set cb_help($this,private,tag_bg) [lindex [$this.ft.text config -bg] 4]
    if {$cb_help($this,private,tag_bg) == ""} {set cb_help($this,private,tag_bg) [lindex [$this.ft.text config -bg] 4]}

    #bind $this <Enter> "focus $this.es"
    #bind $this <Leave> {focus .}
    bind $this.es <Return> "_cb_help_do_search $this \[%W get\]; break"
    bind $this.es <Down> "_cb_help__scroll $this down line; break"
    bind $this.es <Up> "_cb_help__scroll $this up line; break"
    bind $this.es <Next> "_cb_help__scroll $this down page; break"
    bind $this.es <Prior> "_cb_help__scroll $this up page; break"
    bind $this.es <Control-Home> "$this.ft.text yview 0; break"
    bind $this.es <Control-End> "_cb_help__scroll $this end; break"	
    bind $this.es <Escape> "_cb_help_delete $this; break"	
    bind $this.es <Alt-c> "_cb_help_delete $this; break"	
    bind $this.es <Alt-b> "_cb_help__scroll $this back; break"	
    bind $this.es <Alt-r> "
        _cb_help__scroll $this mark
        _cb_help_load $this 
        _cb_help__scroll $this back; break
    "

    # fill widgets:
    _cb_help_load $this
    if ![winfo exists $this] return

    #
    # Window manager settings
    #
    wm minsize $this 440 266
    if {$cb_help($this,private,fmode) != "context"} {
        wm geometry $this 610x448
    } else {
        wm geometry $this 556x292
    }
    wm protocol $this WM_DELETE_WINDOW "_cb_help_delete $this"

    if ![info exists tkdesk(fvwm)] {
	wm iconbitmap $this @$cb_tools(path)/bitmaps/help.xbm
    } else {
	if $tkdesk(fvwm) {
	    # create the icon window
	    toplevel $this-icon -bg [cb_col $tkdesk(color,icon)] \
		    -class Icon
	    wm withdraw $this-icon
	    label $this-icon.label \
		    -image [dsk_image $tkdesk(icon,help)] -bd 0 \
		    -bg [cb_col $tkdesk(color,icon)]
	    pack $this-icon.label -ipadx 2 -ipady 2
	    blt_drag&drop target $this-icon.label handler \
		    file "$this _dd_drophandler"
	    update idletasks
	    wm geometry $this-icon \
		    [winfo reqwidth $this-icon]x[winfo reqheight $this-icon]
	    wm protocol $this-icon WM_DELETE_WINDOW "$this delete"
	    wm iconwindow $this $this-icon
	} else {
	    wm iconbitmap $this @$cb_tools(path)/bitmaps/help.xbm
	}
    }
    wm deiconify $this
    update
    #focus $this.es
    bind $this <Enter> "focus $this.es"

    # bind for help:
    set cb_help_context($this) \
	    "$cb_help($this,public,file)#Help $cb_help($this,public,regexp)"
    cb_help bind_for_context $this cb_help_context

    return $this
}

proc _cb_help_delete {this} {
    catch {destroy $this}		;# destroy associated window
    catch {destroy $this-icon}		;# destroy associated iconwindow
}

#
# ----- Methods and Procs -------------------------------------------------
#

proc _cb_help_configure {this config} {
}

proc _cb_help_config {this config} {
}

proc _cb_help_load {this {file ""}} {
    global argv0 cb_help
    
    _cb_help__cursor $this busy
    set tw $this.ft.text

    set fref ""
    if {$file == ""} {
	set file $cb_help($this,public,file)
    }
    if {[string first "#" $file] > -1} {
        set flist [split $file "#"]
        set file [lindex $flist 0]
        set fref [lindex $flist 1]
	set cb_help($this,public,file) $file
    }

    if {[string index $file 0] == "|"} {
        # $file is a pipe
        set err [catch "set fd \[open \{$file\}\]"]
    } else {
        #foreach fake_ext {"" .gz .z .Z} {
            set ext [file extension $file];#$fake_ext
    	if {$ext == ".gz" || $ext == ".z"} {
    	    set err [catch  "set fd \[open \"|gzip -cd $file\"\]"]
    	} elseif {$ext == ".Z"} {
    	    set err [catch  "set fd \[open \"|zcat $file\"\]"]
    	} else {
    	    set err [catch {set fd [open $file]}]
    	}
    	#if !$err break
        #}
    }
    if $err {
        catch "cb_error \"Error: Couldn't open $file for reading!\""
	_cb_help__cursor $this lazy
        catch "_cb_help_delete $this"
        return
    }
    set cb_help($this,private,help_text) [read $fd]
    catch "close $fd"
    
    $tw config -state normal
    $tw delete 1.0 end
    $tw insert end $cb_help($this,private,help_text)
    $tw config -state disabled

    set cb_help($this,private,headings) ""
    set regexp $cb_help($this,public,regexp)
    if {$regexp != ""} {
        set lw $this.flb.lbox
        catch {$lw delete 0 end}
        set err [catch "set hs \[exec egrep -n \$regexp << \$cb_help($this,private,help_text)\]" \
    	    msg]
        if !$err {
    	set hs [split $hs \n]
    	foreach h $hs {
    	    set colon [string first : $h]
    	    set l [string range $h 0 [expr $colon - 1]]
    	    set t [string trimleft \
    		    [string range $h [expr $colon + 1] 1000] " "]
    	    if $cb_help($this,public,indent) {
    		set num [split [string trimright [lindex $t 0] .] .]
    		set numl [llength $num]
    		for {set i 1} {$i < $numl} {incr i} {
    		    set t "    $t"
    		}
    	    }
    	    catch {$lw insert end $t}
    	    lappend cb_help($this,private,headings) [list [expr $l - 1] $t]
    	}
        } else {
    	# puts "$msg ($regexp)"
        }
    }

    # tag the headings with a different font:
    $tw config -state normal
    foreach head $cb_help($this,private,headings) {
        set line [expr [lindex $head 0] + 1]
        set idx1 ${line}.0
        set idx2 [expr $line + 1].0
        if $cb_help($this,public,indent) {
    	set level [llength [split [string trimright \
    		[lindex [lindex $head 1] 0] .] .]]

    	# replace tabs with spaces
    	set hb [$tw get $idx1 $idx2]
    	if [regsub -all {	} $hb { } nhb] {
    	    set hb $nhb
    	}
    	$tw delete $idx1 $idx2
    	$tw insert $idx1 $hb

    	# determine number of leading blanks:
    	set h [string trimleft $hb " "]
    	set a [expr [string length $hb] - [string length $h]]
    	$tw tag add level$level "$idx1 + $a chars" $idx2
        } elseif $cb_help($this,private,tag_headings) {
    	$tw tag add subject $idx1 $idx2
        }
    }
    $tw config -state disabled

    # get and bind references to headings (``...'')
    # and to shell commands (``@Shell ...''):
    set stidx 1.0
    set what {``[^`]*''}
    set success [regexp -indices -- $what [$tw get $stidx end] mrange]
    while {$success != 0} {
        set mstart [expr [lindex $mrange 0] + 2]
        set mend [expr [lindex $mrange 1] - 1]
        
        set head [$tw get "$stidx + $mstart chars" "$stidx + $mend chars"]
        if [string match {@[Ss][Hh][Ee][Ll][Ll]*} $head] {
    	set hidx 1000
        } elseif [string match {@[Ee][Vv][Aa][Ll]*} $head] {
    	set hidx 1001
        } elseif [string match {@[Ff][Ii][Ll][Ee]*} $head] {
    	set hidx 1002
        } elseif [string match {@[Ll][Yy][Nn][Xx]*} $head] {
    	set hidx 1003
        } else {
    	set hidx 0
        }

        if {$hidx > -1} {
    	set reftag ref[incr cb_help($this,private,refcount)]

    	set rfont [lindex [$this.ft.text config -font] 4]
    	#if [regsub medium $rfont bold tmpfont] {
    	#    set rfont $tmpfont
    	#}
    	if $cb_help($this,private,is_color) {
    	    if {$hidx < 1000} {
    		$tw tag configure $reftag \
    			-foreground blue -borderwidth 0 \
    			-relief flat -background $cb_help($this,private,tag_bg) -font $rfont
    	    } else {
    		$tw tag configure $reftag \
    			-foreground $cb_[cb_col help(tagcolor,$hidx)] -borderwidth 0 \
    			-relief flat -background $cb_help($this,private,tag_bg) -font $rfont
    	    }
    	} else {
    	    $tw tag configure $reftag -underline 1 -font $rfont
    	}

    	if {$hidx == 0} {
    	    $tw tag bind $reftag <B1-ButtonRelease> \
    		    "_cb_help__headref $this \{$head\}; break"
    	} elseif {$hidx == 1000} {
    	    # $head contains a shell command
    	    set cmd [lrange $head 1 100]
    	    $tw tag bind $reftag <B1-ButtonRelease> \
    		    "_cb_help__shellref $this \{$cmd\}; break"
    	} elseif {$hidx == 1001} {
    	    # $head contains a tcl command to evaluate
    	    set script [lrange $head 1 100]
    	    $tw tag bind $reftag <B1-ButtonRelease> \
    		    "_cb_help__evalref $this \{$script\}; break"
    	} elseif {$hidx == 1002} {
    	    # $head contains a filename and perhaps regexp/filemode
    	    set fname [lindex $head 1]
    	    set cb_help($this,private,fmode) [lindex $head 2]
    	    $tw tag bind $reftag <B1-ButtonRelease> \
    		    "_cb_help__fileref $this \{$fname\} \{$cb_help($this,private,fmode)\}; break"
    	} elseif {$hidx == 1003} {
    	    # $head contains an URL to get via lynx
    	    set url [lindex $head 1]
    	    $tw tag bind $reftag <B1-ButtonRelease> \
    		    "_cb_help__lynxref $this \{$url\}; break"
    	}

    	$tw tag bind $reftag <Enter> "_cb_help__tag_entered $this; break"
    	$tw tag bind $reftag <Leave> "_cb_help__tag_left $this; break"
    	$tw tag add $reftag "$stidx + $mstart chars" \
    		"$stidx + $mend chars"
        } else {
    	#puts "Couldn't find a heading containing \"$head\","
        }
        
        set stidx [$tw index "$stidx + $mend chars"]
        set success [regexp -indices -- $what [$tw get $stidx end] mrange]
    }

    set an [file tail $argv0]
    if {$an == "tkdesk"} {
	set an "TkDesk"
    }
    wm title $this "$an: [file tail $file]"
    wm iconname $this "[file tail $file]"
    _cb_help__cursor $this lazy

    if {$fref != ""} {
        _cb_help__headref $this $fref
    }
}

proc _cb_help_do_search {this what} {
    global cb_help
    
    _cb_help__cursor $this busy
    set tw $this.ft.text
    catch "$tw tag remove sel 1.0 end"
    set stidx "insert"
    if {$what != $cb_help($this,private,last_what)} {
        $tw mark set insert 1.0
        set cb_help($this,private,last_matched) 0
    }
    set cb_help($this,private,last_what) $what

    set err [catch {
	set success [regexp -indices -nocase -- $what [$tw get insert end] mrange]
    } errmsg]
    if $err {
	cb_error $errmsg
    } elseif !$success {
        $tw mark set insert 1.0
        $this.es delete 0 end
        if $cb_help($this,private,last_matched) {
    	$this.es insert end "No more matches."
        } else {
    	$this.es insert end "No match."
        }
        _cb_help__cursor $this lazy
        after 1000 
        $this.es delete 0 end
        $this.es insert end $what
        
    } else {
        set cb_help($this,private,last_matched) 1
        set mstart [lindex $mrange 0]
        set mend [expr [lindex $mrange 1] + 1]
        lappend match_range [$tw index "$stidx + $mstart chars"]
        lappend match_range [$tw index "$stidx + $mend chars"]
        set cb_help($this,private,last_ypos) \
		[lindex [cb_sbGet $this.ft.vscroll] 2]
        $tw tag add sel "$stidx + $mstart chars" "$stidx + $mend chars"
        $tw yview -pickplace "$stidx + $mstart chars"
        $tw mark set insert "$stidx + $mend chars"
        _cb_help__cursor $this lazy
    }
}

proc _cb_help_headings {this} {
    global cb_help
    
    return $cb_help($this,private,headings)
}

proc _cb_help__scroll {this where {amount ""}} {
    global cb_help
    
    set sbset [$this.ft.vscroll get]
    set fr1 [lindex $sbset 0]
    set fr2 [lindex $sbset 1]
    set tunits [expr [$this.ft.text index end] - 1]
    set wunits [expr ($fr2 - $fr1) * $tunits]
    set pos1 [expr round($fr1 * $tunits)]
    set pos2 [expr round($fr2 * $tunits)]
    #puts "$tunits $wunits $pos1 $pos2, $where $amount"
    set lb $this.flb.lbox
    set tw $this.ft.text
    switch $where {
        end {
	    $this.ft.text yview [expr round($tunits - $wunits)]
        }
        down {
	    if {$pos1 + $wunits >= $tunits} return
	    if {$amount == "line"} {
		$this.ft.text yview [expr $pos1 + 1]
	    } else {
		set np [expr $pos2 - 1]
		if {$np + $wunits >= $tunits} {
		    set np [expr round($tunits - $wunits)]
		}
		$this.ft.text yview $np	
	    }
        }
        up {
	    if {$pos1 <= 0} return
	    if {$amount == "line"} {
		$this.ft.text yview [expr $pos1 - 1]
	    } else {
		set np [expr round($pos1 - $wunits) + 1]
		if {$np < 0} {set np 0}
		$this.ft.text yview $np
	    }
        }
        back {
	    set lpos $pos1
	    $this.ft.text yview $cb_help($this,private,last_ypos)
	    set cb_help($this,private,last_ypos) $lpos
        }
        mark {
	    set cb_help($this,private,last_ypos) $pos1
        }
        to {
	    set cb_help($this,private,last_ypos) $pos1
	    $this.ft.text yview $amount
        }
        next {
	    set csel [$lb curselection]
	    if {$csel == [llength $cb_help($this,private,headings)] - 1} return
	    if {$csel == ""} {set csel 0} {incr csel}
	    $lb select clear 0 end
	    $lb select set $csel
	    if {$csel > [lindex [cb_sbGet $this.flb.vscroll] 3]} {
		$lb yview $csel
	    }
	    _cb_help__scroll $this to [lindex [lindex $cb_help($this,private,headings) $csel] 0]
        }
        previous {
	    set csel [$lb curselection]
	    if {$csel == 0} return
	    if {$csel == ""} {
		set csel [expr [llength $cb_help($this,private,headings)] - 1]
	    } else {
		incr csel -1
	    }
	    $lb select clear 0 end
	    $lb select set $csel
	    if {$csel < [lindex [cb_sbGet $this.flb.vscroll] 2]} {
		set lbh [lindex [cb_sbGet $this.flb.vscroll] 1]
		set nyv [expr $csel - $lbh + 1]
		if {$nyv < 0} {set nyv 0}
		$lb yview $nyv
	    }
	    _cb_help__scroll $this to [lindex [lindex $cb_help($this,private,headings) $csel] 0]
        }
        top {
	    set csel 0
	    $lb select clear 0 end
	    $lb select set $csel
	    $lb yview 0
	    _cb_help__scroll $this to [lindex [lindex $cb_help($this,private,headings) $csel] 0]
        }
        bottom {
	    set csel [expr [llength $cb_help($this,private,headings)] - 1]
	    $lb select clear 0 end
	    $lb select set $csel
	    set sbg [cb_sbGet $this.flb.vscroll]
	    if {$csel > [lindex $sbg 3]} {
		$lb yview [expr [lindex $sbg 0] - [lindex $sbg 1]]
	    }
	    _cb_help__scroll $this to [lindex [lindex $cb_help($this,private,headings) $csel] 0]
        }
    }
}

proc _cb_help__headref {this head} {
    global cb_Text cb_help
    set cb_Text(skip_binding) 1

    # remove line break:
    if {[string first "\n" $head] > -1} {
	set head [split $head "\n"]
	set head "[lindex $head 0] [string trimleft [lindex $head 1] { }]"
    }
    
    set i 0
    set hidx -1
    foreach h $cb_help($this,private,headings) {
        if [string match "$head*" [string trimleft [lindex $h 1] " "]] {
    	set hidx $i
    	break
        }
        incr i
    }
    if {$hidx == -1} {
        set i 0
        foreach h $cb_help($this,private,headings) {
    	if [string match "*$head*" [lindex $h 1]] {
    	    set hidx $i
    	    break
    	}
    	incr i
        }
    }

    if {$hidx > -1} {
	$this.flb.lbox selection clear 0 end
	$this.flb.lbox selection set $hidx
	$this.flb.lbox yview $hidx
        $this.ft.text tag remove sel 1.0 end
        _cb_help__scroll $this to  [lindex [lindex $cb_help($this,private,headings) $hidx] 0]
    } else {
        $this.es delete 0 end
        $this.es insert end $head
        set cb_help($this,private,last_what) ""
        _cb_help_do_search $this $head
    }
    
}

proc _cb_help__shellref {this cmd} {
    global cb_help
    
    _cb_help__cursor $this busy
    set op [pwd]
    cd [file dirname $cb_help($this,public,file)]
    exec sh -c "$cmd" &
    cd $op
    _cb_help__cursor $this lazy
}

proc _cb_help__evalref {this script} {
    global cb_help
    
    set op [pwd]
    cd [file dirname $cb_help($this,public,file)]
    uplevel #0 eval $script
    cd $op
}

proc _cb_help__fileref {this fname freg} {
    global cb_help
    
    _cb_help__cursor $this busy
    set fc [string index $fname 0]
    if {$fc != "/" && $fc != "|" && $fc != "~"} {
        set fname [file dirname $cb_help($this,public,file)]/$fname
    }
    
    $this.ft.text tag remove sel 1.0 end
    cb_help show $fname $freg
    _cb_help__cursor $this lazy
}

proc _cb_help__lynxref {this url} {
    global cb_help
    
    _cb_help__cursor $this busy
    cb_help show "|lynx -dump $url" lynx
    _cb_help__cursor $this lazy
}

proc _cb_help__cursor {this cur} {
    global cb_tools cb_help

    set gw [grab current]
    set busy_cur "@$cb_tools(path)/bitmaps/timer.xbm \
    		$cb_tools(path)/bitmaps/timer.mask.xbm black white"

    if {![winfo exists $this.ft.text]} return
    
    switch $cur {
        busy {
    	if {$gw == ""} {
    	    cb_BusyCursor
    	    $this.ft.text config -cursor $busy_cur
    	    $this.es config -cursor $busy_cur
    	} else {
    	    $gw config -cursor $busy_cur
    	}
        }
        lazy {
    	if {$gw == ""} {
    	    cb_NormalCursor
    	    $this.ft.text config -cursor top_left_arrow
    	    $this.es config -cursor xterm
    	} else {
    	    $gw config -cursor arrow
    	}
        }
    }
    
    update idletasks
}

proc _cb_help__tag_entered {this} {
    global cb_help
    
    set cb_help($this,private,tag_entered) 1
    if {$cb_help($this,private,tag_left)} {
        set cb_help($this,private,tag_left) 0
        $this.ft.text config -cursor hand2
    }
}

proc _cb_help__tag_left {this} {
    global cb_help
    
    set cb_help($this,private,tag_entered) 0
    if {!$cb_help($this,private,tag_aftered)} {
        set cb_help($this,private,tag_aftered) 1
        after 50 "_cb_help__tag_really_left $this"
    }
}

proc _cb_help__tag_really_left {this} {
    global cb_help
    
    if {!$cb_help($this,private,tag_entered) && !$cb_help($this,private,tag_left)} {
        set cb_help($this,private,tag_left) 1
        $this.ft.text config -cursor top_left_arrow
    }
    set cb_help($this,private,tag_aftered) 0
}

# ----------------------------------------------------
# Procs

proc _cb_help_proc:show {fname {regexp ""} {indent ""}} {
    global cb_tools cb_help

    set fref ""
    set ofname $fname
    if {[string first "#" $fname] > -1} {
        set flist [split $fname "#"]
        set fname [lindex $flist 0]
        set fref [lindex $flist 1]
    }
    
    for {set i 0} {$i <= $cb_help(number)} {incr i} {
	set obj .cb_help$i
	if ![winfo exists $obj] {
	    continue
	}
	#puts $fname
	#puts "- $cb_help($obj,public,file)"
        if {$fname == $cb_help($obj,public,file)} {
    	# $fname has already been loaded
    	cb_raise $obj
    	if {$fref != ""} {
    	    _cb_help__headref $obj $fref
    	}
    	return $obj
        }
    }

    if {$indent != ""} {
        set obj [_cb_help_create \
    	    -file $ofname -regexp $regexp -indent $indent]
    } else {
        set obj [_cb_help_create \
    	    -file $ofname -regexp $regexp]
    }
    return $obj
}

proc _cb_help_proc:context {key refs {fallback ""}} {
    global $refs cb_tools cb_help

    if $cb_tools(in_development) {
        puts stderr $key
    }

    set tkey $key
    set ocur ""
    
    if [winfo exists $key] {
        catch {set ocur [lindex [$key config -cursor] 4]}
        catch {$key config -cursor watch}

        if {[winfo class $key] == "Menu"} {
    	# support for "Help on Menu Entry"
    	set active ""
    	catch {set active [$key index active]}
    	if {$active != ""} {
    	    if $cb_tools(in_development) {
    		puts stderr "active: $active"
    	    }
    	    if [info exists [set refs](${key}:$active)] {
    		set tkey ${key}:$active
    	    }
    	}
        }
    }
    
    set fname ""
    set ex 0

    while {!$ex && $tkey != ""} {
        if [info exists [set refs]($tkey)] {
    	set ref [set [set refs]($tkey)]
    	set fname [lindex $ref 0]
    	set freg [lindex $ref 1]
    	set ex 1
    	break
        } elseif [winfo exists $tkey] {
    	# if there's no entry for widget $key, try its parent:
    	set tkey [winfo parent $tkey]
        } else {
    	set tkey ""
        }
    }
    
    if {$ex == 0 && $fallback != ""} {
        set fname [lindex $fallback 0]
        set freg [lindex $fallback 1]
    }

    if {$fname != ""} {
        cb_help show $fname $freg
        set rc 1
    } else {
        set rc 0
    }

    catch {$key config -cursor $ocur}
    return $rc
}

proc _cb_help_proc:bind_for_context {widget_list ref_array {fallback ""}} {
    global cb_help
    
    foreach widget $widget_list {
        if 0 {
    	if {[winfo class $widget] != "Menu"} {
    	    bind $widget <Enter> {
    		# avoid conflicts with menu traversal:
    		if [winfo exists [focus]] {
    		    if {[winfo class [focus]] != "Menu"} {
    			focus %W
    		    }
    		} else {
    		    focus %W
    		}
    		break
    	    }
    	    bind $widget <Leave> {
    		focus [winfo toplevel %W]; break
    	    }
    	}
        }
        bind $widget <Key-F1> "
    	_cb_help_proc:context \[winfo containing %X %Y\] \
    		$ref_array $fallback; break
        "
        bind $widget <Key-Help> "
    	_cb_help_proc:context \[winfo containing %X %Y\] \
    		$ref_array $fallback; break
        "
    }
}

proc _cb_help_proc:id {{cmd ""}} {
    global cb_help
    
    if {$cmd == ""} {
        set i $cb_help(object_id)
        incr cb_help(object_id)
        return $i
    } elseif {$cmd == "reset"} {
        set cb_help(object_id) 0
    }
}

proc _cb_help_proc:setfont {newfont {lbfont ""}} {
    global cb_help
    
    #
    # Sets the common variables font_xxx.
    #
    set cb_help(font) $newfont
    set cb_help(lbfont) $lbfont
    set headfonts(subject) $cb_help(font)
    if [regsub medium $headfonts(subject) bold nf] {
        set headfonts(subject) $nf
    }
    if [regsub 12 $headfonts(subject) 14 nf] {
        set headfonts(subject) $nf
    }
    for {set i 0} {$i < $cb_help(number)} {incr i} {
	set obj .cb_help$i
	if ![winfo exists $obj] continue
	
        $obj.ft.text config -font $cb_help(font)
        $obj.es config -font $cb_help(font)
	if {$lbfont != ""} {
	    $this.flb.lbox config -font $lbfont
	}
    }
}

proc _cb_help_proc:textbg {color} {
    global cb_help
    
    set cb_help(tbgcolor) $color
    for {set i 0} {$i <= $cb_help(number)} {incr i} {
	if ![winfo exists .cb_help$i] continue
	
        .cb_help$i.ft.text config -bg $cb_help(tbgcolor)
        #$obj.es config -bg $tbgcolor
    }
}

#
# ----- Variables ---------------------------------------------------------
#

proc _cb_help_conf_defaults {this} {
    global cb_help
    
    # complete filename of the helpfile:
    set cb_help($this,public,file) ""
    # regular expression for getting the "headings":
    set cb_help($this,public,regexp) {}
    # indent headings in listbox?
    set cb_help($this,public,indent) 0
    set cb_help($this,public,pad) 4
    
    set cb_help($this,private,help_text) ""
    set cb_help($this,private,headings) ""
    set cb_help($this,private,last_what) ""
    set cb_help($this,private,last_matched) 0
    set cb_help($this,private,is_color) ""
    set cb_help($this,private,refcount) 0
    set cb_help($this,private,tag_bg) ""
    set cb_help($this,private,last_ypos) 0
    set cb_help($this,private,tag_headings) 1
    set cb_help($this,private,fmode) ""
    set cb_help($this,private,tag_entered) 0
    set cb_help($this,private,tag_left) 1
    set cb_help($this,private,tag_aftered) 0
}

proc _cb_help_conf:file {this} {
    if [winfo exists $this] {
        _cb_help_load $this
    }
}

proc _cb_help_conf:regexp {this} {
    global cb_help

    set regexp $cb_help($this,public,regexp)
    if [info exists cb_help(filemode,$regexp,regexp)] {
        set cb_help($this,private,fmode) $regexp
        set cb_help($this,public,indent) $cb_help(filemode,$regexp,indent)
        set cb_help($this,private,tag_headings) $cb_help(filemode,$regexp,tag)
        set cb_help($this,public,regexp) $cb_help(filemode,$regexp,regexp)
    }
    if [winfo exists $this] {
        _cb_help_load $this $file
    }
}

###### set common cb_help variables:

set cb_help(font) -*-courier-medium-r-*-*-12-*-*-*-*-*-*-*
set cb_help(lbfont) ""
set cb_help(object_id) 0

# With "@File" references the second argument can be any of these
# keywords: man, numbered, howto, subjects, c, tcl, context, lynx
set cb_help(filemode,man,regexp) {^[A-Z][-A-Z1-90 ]*$}
set cb_help(filemode,man,indent) 0
set cb_help(filemode,man,tag) 1
set cb_help(filemode,numbered,regexp) {^ *([1-9][1-90]*\.)+ }
set cb_help(filemode,numbered,indent) 1
set cb_help(filemode,numbered,tag) 1
set cb_help(filemode,howto,regexp) {^  ([1-9A-Z][1-90]*\.)+(  |	)}
set cb_help(filemode,howto,indent) 1
set cb_help(filemode,howto,tag) 1
set cb_help(filemode,subjects,regexp) {^Subject: }
set cb_help(filemode,subjects,indent) 0
set cb_help(filemode,subjects,tag) 1
set cb_help(filemode,c,regexp) {^[a-zA-Z].*[,)]$|^typedef}
set cb_help(filemode,c,indent) 0
set cb_help(filemode,c,tag) 0
set cb_help(filemode,tcl,regexp) {^proc|^itcl_class|^ *method}
set cb_help(filemode,tcl,indent) 0
set cb_help(filemode,tcl,tag) 0
set cb_help(filemode,context,regexp) {^ ?[A-Za-z]}
set cb_help(filemode,context,indent) 0
set cb_help(filemode,context,tag) 1
set cb_help(filemode,context,font,body) [cb_font -*-times-medium-r-*-*-14-*-*-*-*-*-*-*]
set cb_help(filemode,context,font,subject) [cb_font -*-times-bold-r-*-*-14-*-*-*-*-*-*-*]
set cb_help(filemode,lynx,regexp) {^ *[A-Z1-90][A-Z1-90 -:]+$|^[^ 	]}
set cb_help(filemode,lynx,indent) 0
set cb_help(filemode,lynx,tag) 0
set cb_help(filemode,khoros,regexp) {^[A-Z]\.}
set cb_help(filemode,khoros,indent) 1
set cb_help(filemode,khoros,tag) 1

# different colors for different types of tags (depends on hidx
# in method load above), in-file references are colored blue
set cb_help(tagcolor,1000) [cb_col red]
set cb_help(tagcolor,1001) [cb_col purple]
set cb_help(tagcolor,1002) [cb_col forestgreen]
set cb_help(tagcolor,1003) [cb_col darkorchid]

set cb_help(headfonts,subject) -*-courier-bold-r-*-*-14-*-*-*-*-*-*-*
set cb_help(headfonts,l1) -*-times-bold-r-*-*-24-*-*-*-*-*-*-*
set cb_help(headfonts,l2) -*-times-bold-r-*-*-18-*-*-*-*-*-*-*
set cb_help(headfonts,l3) -*-times-bold-r-*-*-14-*-*-*-*-*-*-*
set cb_help(headfonts,l4) -*-times-bold-r-*-*-14-*-*-*-*-*-*-*
set cb_help(headfonts,l5) -*-times-bold-r-*-*-12-*-*-*-*-*-*-*
set cb_help(headfonts,l6) -*-times-bold-r-*-*-12-*-*-*-*-*-*-*

set cb_help(tbgcolor) ""

set cb_help(number) -1

if [info exists tkdesk(font,mono)] {
    cb_help setfont [cb_font $tkdesk(font,mono)]
}
    
