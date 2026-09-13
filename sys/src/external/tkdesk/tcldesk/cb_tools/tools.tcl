# =============================================================================
#
# File:		tools.tcl
# Project:	cb_tools
# Requires:     Tcl 7.4, Tk 4.0
#
# Started:	?
# Changed:	25.07.95
#
# Description:	This is the main file of the cb_tools. Contains a lot of
#		often used utitlity functions.
#
# -----------------------------------------------------------------------------
#
# Sections:
#	proc cb_tools_init {path {devel 0}}
#	proc cb_fontStr {args}
#	proc cb_centerToplevel {w {real_w 0} {real_h 0}}
#       proc cb_centerOnToplevel {w top}
#	proc cb_tilde {path}
#	proc cb_broadcast {interp_pattern command args}
#	proc cb_exec_in {interp command args}
#	proc cb_man {name}
#	proc cb_system {args}
#	proc cb_getTempFile {}
#	proc cb_flashLBSelection {lb {color "red"}}
#	proc cb_lines2list {sol}
#	proc cb_restart_application {}
#	proc cb_show_variable {name value}
#	proc cb_show_timing {script {desc ""}}
#	proc cb_BusyCursor {{window .}}
#	proc cb_NormalCursor {{window .}}
#	proc cb_lastElement {lst}
#	proc cb_lastChar {str}
#	proc cb_max {v1 v2}
#	proc cb_min {v1 v2}
#	proc file_executable {file}
#	proc string_replace {string what with}
#       proc cb_fontSel {}
#       proc cb_geometry {w}
#
# =============================================================================

#
# ==== Globals ================================================================
#

set cb_tools(version) 1.2		;# Version of these cb_tools

set cb_tools(color,grey) #c9c9c9
set cb_tools(color,blue) #909fff
set cb_tools(color,green) #60cfa0

set cb_tools(tmpcount) 0
set cb_tools(restarting) 0

#
# ==== Procs ==================================================================
#

# -----------------------------------------------------------------------------
# cb_tools_init:
#	Initializes cb-tools by setting global variables and sourcing
#	the other files if in development mode.
#
# Arguments:
#	path	Path where the cb-tools are located.
#	devel	Set to 1 if working on the cb-tools (internal).
#

proc cb_tools_init {{path ""} {devel 0} {do_source 0}} {
    global cb_tools auto_path

    option add *Scrollbar.highlightThickness 0
    option add *Canvas.highlightThickness 0
    option add *Label.highlightThickness 0

    #
    # Set global variables:
    #

    if ![info exists cb_tools(in_development)] {
	set cb_tools(in_development) $devel
    }
    if {$path != ""} {
	set cb_tools(path) $path		;# Path where cb_tools live
    }
    set cb_tools(startup_path) [pwd]

    #
    # And now source the appropriate files:
    #

    if {!$do_source} {
        lappend auto_path $cb_tools(path)
        
	# this has always to be sourced so that 
	# the bindings can take effect:
        uplevel \#0 source $cb_tools(path)/bindings.tcl
    } else {
	# if developping source all tcl-files that belong to cb-tools

	if {[info commands itcl_class] == ""} {
	    proc itcl_class {args} {}
	    set ugly_itcl_workaround 1
	}

	foreach f [glob $cb_tools(path)/*.tcl] {
	    if {[file tail $f] != "tools.tcl"} {
	        #puts "Sourcing $f ..."
	    	uplevel #0 source $f
	    }
	}

	if [info exists ugly_itcl_workaround] {
	    rename itcl_class ""
	    unset ugly_itcl_workaround
	}
    }
}


# -----------------------------------------------------------------------------
# cb_fontStr: Builds an X-Font-Name from the given options. 
#	Options: -family, -weight, -slant, -size
#	Default is Helvetica, medium, 12 pixel.

proc cb_fontStr {args} {
    set family	helvetica
    set weight	medium
    set slant	r
    set size	12

    if {$args != ""} {
	for {set i 0} {$i < [llength $args]} {incr i} {
	    set o [string range [lindex $args $i] 1 end]
	    switch $o {
		"family"	{incr i; set family [lindex $args $i]}
		"weight"	{incr i; set weight [lindex $args $i]}
		"slant"		{incr i; set slant [lindex $args $i]}
		"size"		{incr i; set size [lindex $args $i]}
		default	  	{error "unknown option \"$o\""}
	    }
	}
    }

    return "-*-$family-$weight-$slant-*-*-$size-*-*-*-*-*-*-*"
}

# -----------------------------------------------------------------------------
# cb_centerToplevel: centers the specified toplevel-window on the screen
#     This is partially stolen from dialog.tcl (tk-library).

proc cb_centerToplevel {w {real_w 0} {real_h 0}} {
   #wm withdraw $w
   update idletasks
   if {$real_w == 0} {
      set x [expr [winfo screenwidth $w]/2 - [winfo reqwidth $w]/2 \
         - [winfo vrootx [winfo parent $w]]]
   } else {
      set x [expr [winfo screenwidth $w]/2 - $real_w/2 \
         - [winfo vrootx [winfo parent $w]]]
   }
   if {$real_h == 0} {
      set y [expr [winfo screenheight $w]/2 - [winfo reqheight $w]/2 \
	      - [winfo vrooty [winfo parent $w]]]
   } else {
      set y [expr [winfo screenheight $w]/2 - $real_h/2 \
	      - [winfo vrooty [winfo parent $w]]]
   }
   wm geom $w +$x+$y
   #wm deiconify $w
}

# -----------------------------------------------------------------------------
# cb_centerOnToplevel: centers the given toplevel $w on another toplevel $top.

proc cb_centerOnToplevel {w top} {
    wm withdraw $w
    update idletasks

    set topgeom [split [winfo geometry $top] "+x"]
    set tw [lindex $topgeom 0]
    set th [lindex $topgeom 1]
    set tx [lindex $topgeom 2]
    set ty [lindex $topgeom 3]
    set rw [winfo reqwidth $w]
    set rh [winfo reqheight $w]

    set x [expr $tx + ($tw/2 - $rw/2)]
    set y [expr $ty + ($th/2 - $rh/2)]    

    wm geometry $w +$x+$y
    wm deiconify $w
}

# -----------------------------------------------------------------------------
# cb_tilde path - expands a leading "~" or "~user" or replaces the home dir,
#                 if it is contained in $path, with a ~ (this may be suppressed
#                 by adding a "1" to the command)
#                 
proc cb_tilde {path {mode "normal"}} {
    global env
    
    if {$mode != "collapse" && [string index $path 0] == "~"} {
	set fs [string first "/" $path]
	if {$fs < 0} {
	    set rpath $path
	    catch {set rpath [glob $path]}
	} else {
	    set gpath [string range $path 0 [expr $fs - 1]]
	    set err [catch {append rpath [glob $gpath] \
		    [string range $path $fs \
		    [string length $path]]}]
	    if $err {
		set rpath $path
	    }
	}
	return $rpath
    } elseif {$mode != "expand"} {
	set home [string trimright $env(HOME) "/"]/
	set hp [string first $home $path]
	if {$hp == 0 && ![string match $home "/"]} {
	    set path ~/[string range $path [string length $home] end]
	}
	return $path
    } else {
	return $path
    }
}

# -----------------------------------------------------------------------------
# cb_exec_in interp command - Executes $command in Interpreter $interp. If
#				$interp doesn't exist, it tries to load it.
proc cb_exec_in {interp command args} {
	if {[lsearch [winfo interps] $interp] > -1} {
		set err [catch {eval send $interp $command $args} errmsg]
		if $err {
#			set but [cb_dialog .t_cb_exec_in "Send Error" \
#				$interp:\n$errmsg error 0 "Cancel" "Try again"]
			return $errmsg
		} {return ""}
	} else {
		# try to load $interp
		eval exec $interp &
		# wait 5 seconds
		after 5000
		set but 1
		while {$but} {
			set err [catch {eval send $interp $command $args} errmsg]
			if $err {
#				set but [cb_dialog .t_cb_exec_in "Send Error" \
#					$interp:\n$errmsg error 0 "Cancel" "Try again"]
				return $errmsg
			} {return ""}
		}
	}
}

# -----------------------------------------------------------------------------
# cb_man name - Invokes tkman (thru cb_exec_in) to show the man page for $name.

proc cb_man {name} {
	cb_exec_in tkman wm deiconify .man
	cb_exec_in tkman raise .man
	cb_exec_in tkman manShowMan $name
}

# -----------------------------------------------------------------------------
# cb_getTempFile - Returns a name for a temporary file.
proc cb_getTempFile {} {
	global cb_tools

	set temp_file /tmp/
	# I don't know how to get the interpreter's name for non-tk-apps:
	if [catch {set interp [winfo name .]}] {set interp unknown}
	eval append temp_file $interp.$cb_tools(tmpcount)
	incr cb_tools(tmpcount)

	return $temp_file
}

# -----------------------------------------------------------------------------
# flashLBSelection lb [color] - flashes curselection of $lb
proc cb_flashLBSelection {lb {color "red"}} {
	set oldSelColor [lindex [$lb config -selectbackground] 4]
	$lb config -selectbackground $color
	update idletasks
	$lb config -selectbackground $oldSelColor
	
}


# -----------------------------------------------------------------------------
# lines2list: this converts a string of lines $sol into a tcl-list, where every
#             line is one element (lol)
proc cb_lines2list {sol} {
   
    return [split $sol "\n"]
}

# -----------------------------------------------------------------------------
# restart_application: Restarts the whole application by sourcing $argv0.
proc cb_restart_application {} {
    global argv0 cb_tools

    set cb_tools(restarting) 1
    if {[info commands "itcl_class"] == "itcl_class"} {
	eval itcl_unload [itcl_info classes]
    }

    foreach w [winfo children .] {catch {destroy $w}}
    auto_reset
    uplevel #0 "cd $cb_tools(startup_path)"
    uplevel #0 {source $argv0}
    set cb_tools(restarting) 0
}

# -----------------------------------------------------------------------------
# show_variable: Displays value of variable $name.
proc cb_show_variable {name} {
    upvar 1 $name value
   catch {destroy .temp}
   tk_dialog [toplevel .temp] "Show Variable" \
      "Value of $name: $value" info 0 OK
}

# -----------------------------------------------------------------------------
# show_timing: Displays t_exec for $script.
proc cb_show_timing {script {desc ""}} {
   set timing [time {uplevel 1 $script}]
   if {"$desc" == ""} {
      tk_dialog [toplevel .temp] "Show Timing" \
         "$script:\n\n $timing" info 0 OK
   } else {
      tk_dialog [toplevel .temp] "Show Timing" \
         "$desc:\n\n $timing" info 0 OK
   }
}

# -----------------------------------------------------------------------------
# BusyCursor, NormalCursor

proc cb_BusyCursor {{others ""}} {
    global cb_tools

    if [info exists cb_tools(busy_cmd)] {
	$cb_tools(busy_cmd)
	return
    }
    
    set window .
    
	foreach i [pack slaves $window] {
     	# $i config -cursor watch
     	catch "$i config -cursor \"@$cb_tools(path)/bitmaps/timer.xbm \
			$cb_tools(path)/bitmaps/timer.mask.xbm black white\""
	}
	foreach i [winfo children $window] {
     	# $i config -cursor watch
     	catch "$i config -cursor \"@$cb_tools(path)/bitmaps/timer.xbm \
			$cb_tools(path)/bitmaps/timer.mask.xbm black white\""
	}
	foreach i $others {
     	# $i config -cursor watch
     	catch "$i config -cursor \"@$cb_tools(path)/bitmaps/timer.xbm \
			$cb_tools(path)/bitmaps/timer.mask.xbm black white\""
	}
   update idletasks
}

proc cb_NormalCursor {{others ""}} {
    global cb_tools
    
    if [info exists cb_tools(lazy_cmd)] {
	$cb_tools(lazy_cmd)
	return
    }

    set window .
    
	foreach i [pack slaves $window] {
     	catch "$i config -cursor {}"
	}
	foreach i [winfo children $window] {
     	catch "$i config -cursor {}"
	}
	foreach i $others {
     	catch "$i config -cursor {}"
	}
#   update idletasks
}

# -----------------------------------------------------------------------------
# cb_lastElement lst - Returns the last element of lst.

proc cb_lastElement {lst} {
	return [lindex $lst end]
}


# -----------------------------------------------------------------------------
# cb_lastChar str - Returns the last character of string.

proc cb_lastChar {str} {
	return [string index $str [expr [string length $str] -1]]
}


# -----------------------------------------------------------------------------
# cb_max v1 v2 - Returns the maximum.
proc cb_max {v1 v2} {
	if {$v1 > $v2} {return $v1} {return $v2}
}

# -----------------------------------------------------------------------------
# cb_min v1 v2 - Returns the minimum.
proc cb_min {v1 v2} {
	if {$v1 < $v2} {return $v1} {return $v2}
}

# -----------------------------------------------------------------------------
# file_executable - returns 1 if $file is executable by anyone
#		(Note: This was needed for Tcl 7.3 seems to have problems
#		with the ext2fs of linux 1.1.52 (V0.5a).)

proc file_executable {file} {
    set err [catch {file stat "$file" stat}]

    if $err {
	return 0
    }

    if [expr $stat(mode) & 0111] {
	return 1
    } else {
	return 0
    }
}

# -----------------------------------------------------------------------------
# string_replace string what with - Replaces all occurrences of $what in
#				    $string with $with.

proc string_replace {string what with} {

    set wl [string length $what]
    set str $string
    set estr ""

    while {[set fm [string first $what $str]] > -1} {
	append estr [string range $str 0 [expr $fm - 1]]
	append estr $with
	set str [string range $str [expr $fm + $wl] end]
    }

    append estr $str
    return $estr
}

# -----------------------------------------------------------------------------
# cb_fontSel - Executes xfontsel and returns the selected font.
#

proc cb_fontSel {} {
    cb_info "Select a font in the following window, press the \"select\" button, and then select \"quit\"."
    update
    set font fixed
    set err [catch {set font [exec xfontsel -print]}]
    if $err {
	cb_error "Couldn't execute xfontsel."
    }
    return $font
}

# -----------------------------------------------------------------------------
#
# Proc:		cb_geometry
# Args:		w - toplevel window
# Returns:      usable geometry of $w
# Desc: 	The geometry of $w. The position is obtained via the winfo
#               command and the size comes from wm.
# Side-FX:	none
#

proc cb_geometry {w} {

    set tkgeom [split [winfo geometry $w] x+]
    set wmgeom [split [wm geometry $w] x+]

    set size [lindex $wmgeom 0]x[lindex $wmgeom 1]
    set pos +[expr [lindex $tkgeom 2] + 1]+[expr [lindex $tkgeom 3] + 1]

    return $size$pos
}

#
# -----------------------------------------------------------------------------
#
# Proc:		cb_color
# Args:		color: blue, green or grey
# Returns: 	""
# Desc:		
# Side-FX:	
#

proc cb_color {color} {
    global cb_tools

    if {[winfo depth .] > 1} {
	if [info exists cb_tools(color,$color)] {
	    tk_setPalette [cb_col $cb_tools(color,$color)]
	}
    } else {
	set tk_strictMotif 1
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		cb_old_sb_get
# Args:		name of scrollbar widget
# Returns: 	{totalUnits windowUnits firstUnit lastUnit}
# Desc:		Reimplements the Tk 3.6 scrollbar get method for Tk 4.0.
# Side-FX:	none
#

proc cb_old_sb_get {sb} {
    set tw [lindex [$sb cget -command] 0]
    if {[winfo class $tw] != "Text"} {
	error "cb_old_sb_get only supports scrollbars connected to text widgets"
    }
    set totalUnits [expr int([$tw index end]) - 1]
    set f1 [lindex [$sb get] 0]
    set f2 [lindex [$sb get] 1]
    set windowUnits [expr round(($f2 - $f1) * $totalUnits)]
    set firstUnit [expr round($f1 * $totalUnits)]
    set lastUnit [expr round($f2 * $totalUnits) - 1]
    return "$totalUnits $windowUnits $firstUnit $lastUnit"
}

#
# -----------------------------------------------------------------------------
#
# Proc:		cb_image
# Args:		file - name of picture file, args - image options
# Returns: 	name of new Tk image
# Desc:		Acts as a frontend to Tk's image command. When the same
#               file should be loaded twice, the old id is returned.
# Side-FX:	none
#

proc cb_image {file args} {
    global cb_tools

    if {$file == "!reset"} {
	foreach i [array names cb_tools image,*] {
	    unset cb_tools($i)
	}
	return
    }

    if {$args != "reread"} {
	if [info exists cb_tools(image,$file)] {
	    return $cb_tools(image,$file)
	}
    }
    
    switch [string trimleft [file extension $file] .] {
	xbm {
	    set img [image create bitmap -file $file]
	}
	ppm -
	pgm -
	gif {
	    set img [image create photo -file $file]
	}
	bmp {
	    if [auto_execok bmptoppm] {
		set img [image create photo -data [exec bmptoppm $file]]
	    } else {
		error "couldn't find bmptoppm"
	    }
	}
	pcx {
	    if [auto_execok pcxtoppm] {
		set img [image create photo -data [exec pcxtoppm $file]]
	    } else {
		error "couldn't find pcxtoppm"
	    }
	}
	pict {
	    if [auto_execok picttoppm] {
		set img [image create photo -data [exec picttoppm $file]]
	    } else {
		error "couldn't find picttoppm"
	    }
	}
	xpm -
	default {
	    # assume all other to be in X11 bitmap, no pixmap format...
	    #set img [image create bitmap -file $file]
	    if {[lsearch [image types] "pixmap"] > -1} {
		set img [image create pixmap -file $file]
	    } else {
		if [auto_execok xpmtoppm] {
		    exec xpmtoppm $file >/tmp/[pid].ppm 2>/dev/null
		    set img [image create photo -file /tmp/[pid].ppm]
		} else {
		    error "couldn't find xpmtoppm"
		}
	    }
	}
    }

    if {$args != ""} {
	catch {eval $img configure $args}
    }
    set cb_tools(image,$file) $img
    return $img
}

# ---------------------------------------------------------------------------
# cb_sbGet sb:
# Returns the current setting of scrollbar $sb in the old (Tk 3.6) format:
# totalUnits windowUnits firstUnit lastUnit.
#
proc cb_sbGet {sb} {
    set gl [$sb get]
    if {[llength $gl] == 4} {
	return $gl
    } else {
	set first [lindex $gl 0]
	set last [lindex $gl 1]
	set cw [lindex [$sb cget -command] 0]
	if {[winfo class $cw] == "Listbox"} {
	    set tu [llength [$cw get 0 end]]
	} elseif {[winfo class $cw] == "Text"} {
	    set tu [lindex [split [$cw index end] "."] 0]
	}
	set wu [expr round(($last - $first) * $tu)]
	set fu [expr round($first * $tu)]
	set lu [expr round($last * $tu) - 1]
	return "$tu $wu $fu $lu"
    }
}

# ---------------------------------------------------------------------------
# cb_raise top:
# Raises toplevel $top after deiconifying it, if necessary.
#
proc cb_raise {top} {
    
    if {[wm state $top] != "normal"} {
	wm deiconify $top
	tkwait visibility $top
    } else {
	raise $top
    }
}

# ---------------------------------------------------------------------------
# cb_col col:
# Checks if $col is a valid color. Returns $col, or black
# if $col was invalid.
#
if ![winfo exists .cb_col_font_check] {
    label .cb_col_font_check
}
proc cb_col {col {fallback ""}} {
    global cb_col argv0

    if ![info exists cb_col($col)] {
	set err [catch {.cb_col_font_check config -bg $col} errmsg]
	if $err {
	    catch {puts stderr "[file tail $argv0]: $errmsg"}
	    if {$fallback == ""} {
		set cb_col($col) black
	    } else {
		set cb_col($col) $fallback
	    }
	} else {
	    set cb_col($col) $col
	}
    }
    return $cb_col($col)
}

# ---------------------------------------------------------------------------
# cb_font font:
# Checks if $font is a valid font. Returns $font, or a fallback font
# such as "fixed" if $col was invalid.
#
proc cb_font {font {fallback ""}} {
    global cb_font tkdesk argv0

    if ![info exists cb_font($font)] {
	set err [catch {.cb_col_font_check config -font $font} errmsg]
	if $err {
	    catch {puts stderr "[file tail $argv0]: $errmsg"}
	    # try to determine a fall-back font:
	    set family [lindex [split $font -] 2]
	    if {$family != ""} {
		switch [string tolower $family] {
		    "lucidatypewriter" {
			set family courier
		    }
		    "helvetica" {
			set family times
		    }
		    "times" {
			set family helvetica
		    }
		    "new century schoolbook" {
			set family times
		    }
		}
		set nfont [join [lreplace [split $font -] 2 2 $family] -]
		set err [catch {.cb_col_font_check config -font $nfont} errmsg]
		if $err {
		    set family ""
		} else {
		    set cb_font($font) $nfont
		}
	    }
	    if {$family == ""} {
		if {$fallback != ""} {
		    set cb_font($font) $fallback
		} else {
		    if [info exists tkdesk(font,fallback)] {
			set cb_font($font) $tkdesk(font,fallback)
		    } else {
			set cb_font($font) fixed
		    }
		}
	    }
	} else {
	    set cb_font($font) $font
	}
    }
    return $cb_font($font)
}

# ---------------------------------------------------------------------------
# cb_manage_secondary prim sec:
# Arranges for $sec to be withdrawn whenever $prim get unmapped
# (or iconified), and to be remapped when $prim is remapped.
#
proc cb_manage_secondary {prim args} {
    foreach sec $args {
	bind $prim <Unmap> "+if \{\"%W\" == \"$prim\"\} \{ \
		    if \[winfo exists $sec\] \{wm withdraw $sec\} \
		\}"
	bind $prim <Map> "+if \{\"%W\" == \"$prim\"\} \{ \
		    if \[winfo exists $sec\] \{wm deiconify $sec\} \
		\}"
    }
}

# ---------------------------------------------------------------------------
# cb_deiconify window:
# Deiconifies $window if it exists and its state is not normal.
#
proc cb_deiconify {window} {
    if [winfo exists $window] {
	if {[wm state $window] != "normal"} {
	    catch {wm deiconify $window}
	}
    }
}

# ---------------------------------------------------------------------------
# cb_random limit ?seed?:
# Copied from the Tcl FAQ, this proc returns and int bw. 0 and limit-1.
# Seed value may be given as 2nd param, such as: [pid], [dev/kmem].
#
proc cb_random {args} {
    global RNG_seed
    
    set max 259200
    set argcnt [llength $args]
    if { $argcnt < 1 || $argcnt > 2 } {
	error "wrong # args: random limit | seed ?seedval?"
    }
    if ![string compare [lindex $args 0] seed] {
	if { $argcnt == 2 } {
	    set RNG_seed [lindex $args 1]
	} else {
	    set RNG_seed [expr \
                    ([pid]+[file atime /dev/kmem])%$max]
	}
	return
    }
    if ![info exists RNG_seed] {
	set RNG_seed [expr ([pid]+[file atime /dev/kmem])%$max]
    }
    set RNG_seed [expr ($RNG_seed*7141+54773) % $max]
    return [expr int(double($RNG_seed)*[lindex $args 0]/$max)]
}