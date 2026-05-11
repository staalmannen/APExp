#!/usr/bin/env wish
#
# a graphical debugger for compiled CHICKEN programs
#
# Copyright (c) 2015-2022, The CHICKEN Team
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
# conditions are met:
#
#   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
#     disclaimer.
#   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided with the distribution.
#   Neither the name of the author nor the names of its contributors may be used to endorse or promote
#     products derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.


set version 0
set protocol_version 1
set debugger_port 9999

set events(1) call
set events(2) assign
set events(3) gc
set events(4) entry
set events(5) signal
set events(6) connect
set events(7) listen
set events(8) interrupted

set reply(SETMASK) 1
set reply(TERMINATE) 2
set reply(CONTINUE) 3
set reply(SET_BREAKPOINT) 4
set reply(CLEAR_BREAKPOINT) 5
set reply(LIST_EVENTS) 6
set reply(GET_BYTES) 7
set reply(GET_AV) 8
set reply(GET_SLOTS) 9
set reply(GET_GLOBAL) 10
set reply(GET_STATS) 11
set reply(GET_TRACE) 12

set colors(header_foreground) white
set colors(header_background) black
set colors(text_foreground) black
set colors(text_background) gray90
set colors(event_foreground) black
set colors(event_background) white
set colors(breakpoint_foreground) white
set colors(breakpoint_background) DarkRed
set colors(highlight_foreground) white
set colors(highlight_background) CornflowerBlue
set colors(mark_foreground) black
set colors(mark_background) yellow
set colors(trace_background) gray90
set colors(trace_foreground) black

set typecode(0) VECTOR
set typecode(1) SYMBOL
set typecode(66) STRING
set typecode(3) PAIR
set typecode(36) CLOSURE
set typecode(85) FLONUM
set typecode(39) PORT
set typecode(8) STRUCTURE
set typecode(41) POINTER
set typecode(42) LOCATIVE
set typecode(43) TAGGED_POINTER
set typecode(77) LAMBDA_INFO
set typecode(15) BUCKET

set EXEC_EVENT_MASK 32; # signal
set STEP_EVENT_MASK 54; # call, entry, assign, signal

set membar_height 50
set value_cutoff_limit 200; # must be lower than limit in dbg-stub.c

set the_name "feathers"
set header_text "$the_name - (c)MMXV The CHICKEN Team - Version $version"
set startup_file ".$the_name"

set client_addr ""
set client_file ""
set current_filename ""
set current_c_filename ""
set file_list {}
set bp_queue {}
set watched_queue {}
set value_queue {}
set current_line ""
set current_c_line ""
set current_bp_lines {}
set current_bp_globals {}
set font_name "Courier"
set font_size 12
set program_name ""
set search_path {"."}
set data_view ""
set c_view ""
set data_queue {}
set reply_queue {}
set starting_up 1
set stepping 0
set terminated 0
set arguments_item_id ""
set watched_variables {}
set current_variable ""
set current_value ""
set listening 0
set process_id 0
set statistics_data ""
set mark_start_index(.t) ""
set mark_start_index(.code.t) ""
set current_c_location ""
set last_marked_widget .t
set selected_filename ""
set trace_data ""
set last_location ""
set logging 0

set env(CHICKEN_DEBUGGER) "localhost:9999"


proc Log {msg} {
    global logging

    if {$logging} {puts stderr $msg}
}


proc SetupGUI {} {
    global font_name font_size colors the_name selected_filename
    label .h -height 1 -textvariable header_text -anchor w
    scrollbar .s -command {.t yview}
    text .t -wrap char -yscrollcommand {.s set} -cursor arrow -state disabled \
        -font [list $font_name $font_size]
    frame .f
    ttk::combobox .files -postcommand FilesList -textvariable selected_filename
    pack .h -side top -fill x
    pack .files -side top -fill x
    pack .f -side bottom -fill x
    pack .s -fill y -side right
    pack .t -fill both -expand 1

    for {set i 1} {$i <= 10} {incr i} {
        button .f.b$i -text "F$i" -font {Helvetica 10} -borderwidth 0 -relief flat \
            -pady 0
        pack .f.b$i -side left -expand 1 -fill x
    }

    .f.b1 configure -text "F1 Run"
    .f.b2 configure -text "F2 Where"
    .f.b3 configure -text "F3 AddDir"
    .f.b4 configure -text "F4 Data"
    .f.b5 configure -text "F5 Continue"
    .f.b6 configure -text "F6 Step"
    .f.b7 configure -text "F7 Find Prev"
    .f.b8 configure -text "F8 Find Next"
    .f.b9 configure -text "F9 C"
    .f.b10 configure -text "F10 Exit"
    .h configure -background $colors(header_background) \
        -foreground $colors(header_foreground) -font {Helvetica 12} \
        -borderwidth 0
    .t configure -background $colors(text_background) \
        -foreground $colors(text_foreground) \
        -insertbackground $colors(text_foreground) -borderwidth 0

    .t tag configure ev -background $colors(event_background) \
        -foreground $colors(event_foreground)
    .t tag configure bp -background $colors(breakpoint_background) \
        -foreground $colors(breakpoint_foreground)
    .t tag configure hl -background $colors(highlight_background) \
        -foreground $colors(highlight_foreground)
    .t tag configure mk -background $colors(mark_background) \
        -foreground $colors(mark_foreground)
    .t tag lower mk sel
    .t tag lower bp mk
    .t tag lower hl bp
    .t tag lower ev hl
    focus .t
    wm title . $the_name
}


proc SetupBindings {} {
    for {set i 1} {$i <= 10} {incr i} {
        bind . <F$i> [list .f.b$i invoke]
    }

    .f.b1 configure -command RunProcess
    .f.b2 configure -command LocateFocus
    .f.b3 configure -command AddDirectory
    .f.b4 configure -command ShowData
    .f.b5 configure -command ContinueExecution
    .f.b6 configure -command StepExecution
    .f.b7 configure -command FindPrevious
    .f.b8 configure -command FindNext
    .f.b9 configure -command OpenCView
    .f.b10 configure -command Terminate
    bind .t <ButtonPress-1> { focus .t; ToggleBreakpoint %y; break }
    bind .t <ButtonRelease-1> break
    bind .t <space> {StepExecution; break}
    bind .t <Return> {ToggleBreakpoint; break}
    bind .t <Up> {MoveFocus -1; break}
    bind .t <Down> {MoveFocus 1; break}
    bind .t <plus> {ResizeFont 1; break}
    bind .t <minus> {ResizeFont -1; break}
    bind .t <Escape> {Interrupt}
    bind .t <ButtonPress-3> {StartMark %W %x %y; break}
    bind .t <Motion> {MoveMark %W %x %y; break}
    bind .t <ButtonRelease-3> {EndMark %W; break}
    bind .files <<ComboboxSelected>> {SelectFile; focus .t}
    wm protocol . WM_DELETE_WINDOW Terminate
}


proc SetupDataView {} {
    global colors arguments_item_id stats membar_height the_name font_name font_size
    toplevel .data
    ttk::treeview .data.t -yscrollcommand {.data.s set} -columns {Values Addresses} \
        -selectmode browse
    .data.t heading 0 -text Value
    .data.t heading 1 -text Address
    scrollbar .data.s -command {.data.t yview}
    entry .data.e
    canvas .data.c -height $membar_height
    frame .data.f
    text .data.f.tr -state disabled -yscrollcommand {.data.f.trs set} -height 20 \
        -font [list $font_name $font_size] -foreground $colors(trace_foreground) \
        -background $colors(trace_background)
    scrollbar .data.f.trs -command {.data.f.tr yview}
    pack .data.f -side bottom -fill x
    pack .data.c -side bottom -fill x
    pack .data.e -side bottom -fill x
    pack .data.s -fill y -side right
    pack .data.t -fill both -expand 1
    pack .data.f.trs -fill y -side right
    pack .data.f.tr -side bottom -fill both -expand 1
    .data.t tag configure watched -foreground $colors(breakpoint_foreground) \
        -background $colors(breakpoint_background)
    set arguments_item_id [.data.t insert {} end -text "<arguments>"]
    set stats(fromspace_used) [.data.c create rectangle 0 0 0 0 -fill gray80]
    set stats(fromspace_unused) [.data.c create rectangle 0 0 0 0 -fill gray40]
    set stats(scratchspace_used) [.data.c create rectangle 0 0 0 0 -fill gray80]
    set stats(scratchspace_unused) [.data.c create rectangle 0 0 0 0 -fill gray40]
    set stats(nursery_used) [.data.c create rectangle 0 0 0 0 -fill gray80]
    set stats(nursery_unused) [.data.c create rectangle 0 0 0 0 -fill gray40]
    set mh [expr $membar_height / 3]
    set stats(fromspace_name) [.data.c create text 10 0 -anchor nw -text "heap"]
    set stats(scratchspace_name) [.data.c create text 10 $mh -anchor nw -text \
        "scratch"]
    set stats(nursery_name) [.data.c create text 10 [expr $mh * 2] -anchor nw \
        -text "nursery"]
    set stats(fromspace_percentage) [.data.c create text 0 0 -anchor center]
    set stats(scratchspace_percentage) [.data.c create text 0 0 -anchor center]
    set stats(nursery_percentage) [.data.c create text 0 0 -anchor center]
    set stats(fromspace_size) [.data.c create text 0 0 -anchor ne]
    set stats(scratchspace_size) [.data.c create text 0 0 -anchor ne]
    set stats(nursery_size) [.data.c create text 0 0 -anchor ne]
    wm title .data "$the_name - data view"
}


proc SetupDataViewBindings {} {
    bind .data <F3> AddDirectory
    bind .data <F4> ShowData
    bind .data <F5> ContinueExecution
    bind .data <F6> StepExecution
    bind .data <F10> Terminate
    bind .data.e <Return> {WatchGlobal; break}
    bind .data.t <BackSpace> {RemoveGlobal; break}
    bind .data.t <Delete> {RemoveGlobal; break}
    bind .data.t <<TreeviewOpen>> OpenDataItem
    bind .data.t <Return> {ToggleVariableWatch; break}
    bind .data.t <Double-Button-1> {ToggleVariableWatch %x %y; break}
    bind .data.t <<TreeviewSelect>> {Log [.data.t focus]; break}
    bind .data.c <Configure> {RedrawStatistics}
    wm protocol .data WM_DELETE_WINDOW CloseDataView
}


proc SetupCView {} {
    global font_name font_size colors the_name
    toplevel .code
    label .code.h -height 1 -text "" -anchor w
    scrollbar .code.s -command {.code.t yview}
    text .code.t -wrap char -yscrollcommand {.code.s set} -cursor arrow -state \
        disabled -font [list $font_name $font_size]
    frame .code.f
    pack .code.h -side top -fill x
    pack .code.s -fill y -side right
    pack .code.f -fill x -side bottom
    pack .code.t -fill both -expand 1
    .code.h configure -background $colors(header_background) \
        -foreground $colors(header_foreground) -font {Helvetica 12} \
        -borderwidth 0
    .code.t configure -background $colors(text_background) \
        -foreground $colors(text_foreground) \
        -insertbackground $colors(text_foreground) -borderwidth 0
    .code.t tag configure hl -background $colors(highlight_background) \
        -foreground $colors(highlight_foreground)
    .code.t tag configure mk -background $colors(mark_background) \
        -foreground $colors(mark_foreground)
    .code.t tag lower mk sel
    .code.t tag lower hl mk
    wm title .code "$the_name - code view"
    focus .code.t
}


proc SetupCViewBindings {} {
    bind .code <F3> AddDirectory
    bind .code <F4> ShowData
    bind .code <F5> ContinueExecution
    bind .code <F6> StepExecution
    bind .code <F7> {FindPrevious .code.t}
    bind .code <F8> {FindNext .code.t}
    bind .code <F10> Terminate
    bind .code.t <ButtonPress-1> {focus .code.t}
    bind .code.t <ButtonRelease-1> break
    bind .code <plus> {ResizeFont 1; break}
    bind .code <minus> {ResizeFont -1; break}
    bind .code.t <ButtonPress-3> {StartMark %W %x %y; break}
    bind .code.t <Motion> {MoveMark %W %x %y; break}
    bind .code.t <ButtonRelease-3> {EndMark %W; break}
    wm protocol .code WM_DELETE_WINDOW CloseCView
}


proc FilesList {} {
    global file_list
    .files configure -values $file_list
}


proc CloseDataView {} {
    global data_view

    if {$data_view != ""} {
        set data_view ""
        destroy .data
    }
}


proc CloseCView {} {
    global c_view

    if {$c_view != ""} {
        set c_view ""
        destroy .code
    }
}


proc ShowData {} {
    global data_view starting_up client_file program_name the_name

    if {$data_view == ""} {
        SetupDataView
        SetupDataViewBindings
        set data_view .data
        wm title .data "$the_name - $program_name - data view"

        if {!$starting_up && $client_file != ""} UpdateData
    }
}


proc OpenCView {} {
    global c_view starting_up current_c_location the_name program_name

    if {$c_view == ""} {
        SetupCView
        SetupCViewBindings
        set c_view .code
        wm title .code "$the_name - $program_name - code view"

        Log "$current_c_location"

        if {$current_c_location != ""} {
            LocateCSource $current_c_location
        }
    }
}


proc AddDirectory {} {
    global search_path current_filename
    set dir "."

    if {$current_filename != ""} {
        set dir [file dirname $current_filename]
    }

    set dir [tk_chooseDirectory -title "Select directory to add to search path" \
        -initialdir $dir]

    if {$dir != ""} {
        lappend search_path $dir
    }
}


proc ResizeFont {n} {
    global font_size font_name c_view
    incr font_size $n
    .t configure -font [list $font_name $font_size]

    if {$c_view != ""} {
        .code.t configure -font [list $font_name $font_size]
    }
}


proc Flash {{color red}} {
    global colors
    .t configure -background $color
    update
    after 100 {.t configure -background $colors(text_background)}
}


proc CheckListening {} {
    global listening

    if {!$listening} {
        Flash
        return 0
    }

    return 1
}


proc MoveFocus {amount} {
    global current_line
    set ln [expr $current_line + $amount]
    SetFocus $ln
}


proc LocateFocus {} {
    global last_location

    if {$last_location != ""} {
        SetFocus $last_location
    }
}


proc SetFocus {line} {
    global current_line

    if {$line > 0 && $line <= [.t count -lines 1.0 end]} {
        set old [.t tag ranges hl]

        if {$old != ""} {
            eval .t tag remove hl $old
        }

        set current_line $line
        .t tag add hl $line.0 "$line.0 lineend + 1 chars"
        .t see $line.0
    }
}


proc SetCFocus {line} {
    global current_c_line

    if {$line > 0 && $line <= [.code.t count -lines 1.0 end]} {
        set old [.code.t tag ranges hl]

        if {$old != ""} {
            eval .code.t tag remove hl $old
        }

        set current_c_line $line
        .code.t tag add hl $line.0 "$line.0 lineend + 1 chars"
        .code.t see $line.0
    }
}


proc Interrupt {} {
    global process_id listening

    if {$listening || $process_id == 0} return

    catch {exec kill -USR2 $process_id}
}


proc ToggleBreakpoint {{y ""}} {
    global current_filename bp_queue current_bp_lines
    global current_line client_file reply_queue

    if {$client_file == ""} return

    if {$y != ""} {
        if {[catch {set p [.t index @1,$y]}]} return

        if {![regexp {^(\d+)\.} $p _ line]} return
    } else {
        set line $current_line
    }

    set aname "file:$current_filename"
    global $aname
    set aref "$aname\($line\)"

    if {![CheckListening]} return

    if {[info exists $aref]} {
        set bps [set $aref]

        if {$bps != ""} {
            set bp1 [lindex $bps 0]
            set bprest [lrange $bps 1 end]
            set bp_queue [concat $bp_queue $bprest]

            if {[lsearch -exact $current_bp_lines $line] != -1} {
                UnmarkBP $line
                SendReply CLEAR_BREAKPOINT $bp1
                lappend reply_queue RemoveBPReply
            } else {
                MarkBP $line
                SendReply SET_BREAKPOINT $bp1
                lappend reply_queue AddBPReply
            }
        }
    }
}


proc ToggleVariableWatch {{x ""} {y ""}} {
    global globals current_bp_globals bp_queue

    if {![CheckListening]} return

    if {$x == ""} {
        set item [.data.t focus]
    } else {
        if {[catch {.data.t identify item $x $y} item]} return
    }

    if {$item == ""} return

    if {[.data.t parent $item] != ""} return

    set name [.data.t item $item -text]

    if {$name == "<arguments>"} return

    if {![info exists globals($name)]} return

    Log "globals: $name -> $globals($name)"

    set bps $globals($name)

    if {$bps != ""} {
        set bp1 [lindex $bps 0]
        set bprest [lrange $bps 1 end]
        set bp_queue [concat $bp_queue $bprest]

        if {[lsearch -exact $current_bp_globals $item] != -1} {
            UnmarkWatchedVariable $item
            SendReply CLEAR_BREAKPOINT $bp1
            lappend reply_queue RemoveBPReply
        } else {
            MarkWatchedVariable $item
            SendReply SET_BREAKPOINT $bp1
            lappend reply_queue AddBPReply
        }
    }
}


proc AddBPReply {} {
    global bp_queue reply_queue

    if {$bp_queue != ""} {
        set bp1 [lindex $bp_queue 0]
        set bp_queue [lrange $bp_queue 1 end]
        SendReply SET_BREAKPOINT $bp1

        if {$bp_queue != ""} {
            lappend reply_queue AddBPReply
        }
    }
}


proc RemoveBPReply {} {
    global bp_queue reply_queue

    if {$bp_queue != ""} {
        set bp1 [lindex $bp_queue 0]
        set bp_queue [lrange $bp_queue 1 end]
        SendReply CLEAR_BREAKPOINT $bp1

        if {$bp_queue != ""} {
            lappend reply_queue RemoveBPReply
        }
    }
}


proc MarkBP {line} {
    global current_bp_lines

    if {[lsearch -exact $current_bp_lines $line] == -1} {
        .t tag add bp $line.0 "$line.0 lineend"
        lappend current_bp_lines $line
    }
}


proc UnmarkBP {line} {
    global current_bp_lines
    set i [lsearch -exact $current_bp_lines $line]

    if {$i != -1} {
        set current_bp_lines [lreplace $current_bp_lines $i $i]
        .t tag remove bp $line.0 "$line.0 lineend"
    }
}


proc MarkWatchedVariable {item} {
    global current_bp_globals

    if {[lsearch -exact $current_bp_globals $item] == -1} {
        .data.t tag add watched $item
        lappend current_bp_globals $item
    }
}


proc UnmarkWatchedVariable {item} {
    global current_bp_globals
    set i [lsearch -exact $current_bp_globals $item]

    if {$i != -1} {
        set current_bp_globals [lreplace $current_bp_globals $i $i]
        .data.t tag remove watched $item
    }
}


proc Terminate {} {
    global client_file process_id

    if {$client_file != ""} {
        SendReply TERMINATE
        set f $client_file
        set client_file ""
        close $f
        catch {exec kill -9 $process_id}
    }

    exit
}


proc RunProcess {{prg ""}} {
    global env client_file program_name search_path reply_queue current_filename
    global data_queue bp_queue starting_up stepping terminated current_bp_lines
    global terminated watched_variables watched_queue listening file_list
    global value_queue process_id current_bp_globals data_view statistics_data
    global arguments_item_id trace_data last_location

    if {$client_file != ""} {
        if {!$terminated} {SendReply TERMINATE}

        set f $client_file
        set client_file ""
        close $f
    }

    set program_name $prg

    if {$program_name == ""} {
        set program_name [tk_getOpenFile -title "Select executable"]
    }

    if {$program_name == ""} return

    set args [lassign $program_name prgfname]
    set prgfname [file normalize $prgfname]

    if {![file exists $prgfname]} {
        .t configure -state normal
        .t insert end "Could not start program:\n\nfile `$prgfname' does not exist"
        .t see end
        .t configure -state disabled
    }

    lappend search_path [file dirname $prgfname]
    set reply_queue {}
    set data_queue {}
    set bp_queue {}
    set watched_queue {}
    set value_queue {}
    set last_location ""
    set starting_up 1
    set stepping 0
    set terminated 0
    set current_bp_lines {}
    set current_bp_globals {}
    set current_filename ""
    set watched_variables {}
    set listening 0
    set process_id 0
    set statistics_data ""
    set file_list {}
    set trace_data ""
    .t configure -state normal
    .t delete 1.0 end
    .t configure -state disabled

    if {$data_view != ""} {
        .data.t delete [lrange [.data.t children {}] 1 end]
        .data.t delete [.data.t children $arguments_item_id]
    }

    if {[catch {eval exec $prgfname {*}$args <@ stdin >@ stdout 2>@ stderr &} result]} {
        .t configure -state normal
        .t insert end "Could not start program:\n\n$result"
        .t see end
        .t configure -state disabled
    } else {
        set process_id $result
    }
}


proc UpdateHeader {{msg ""}} {
    global header_text current_filename client_addr current_line
    set header_text $client_addr

    if {$current_filename != ""} {
        set header_text $current_filename

        if {$current_line != ""} {
            append header_text ":$current_line"
        }
    }

    if {$msg != ""} {
        append header_text " - $msg"
    }
}


proc ProcessInput {} {
    global client_file terminated
    gets $client_file line

    if {[eof $client_file]} {
        close $client_file
        set client_file ""
        set terminated 1
        UpdateHeader "connection closed"
    } elseif {![fblocked $client_file]} {
        Log "Input: $line"
        ProcessLine $line
    }
}


proc ProcessLine {line} {
    if {[regexp {^\((\d+)\s+([^\s]*)\s+([^\s]*)\s+([^)]*)\)$} $line _ evt loc val cloc]} {
        set val [ProcessString $val]
        set loc [ProcessString $loc]
        set cloc [ProcessString $cloc]
        ProcessEvent $evt $loc $val $cloc
    } elseif {[regexp {^\(\*\s*(.*)\)$} $line _ data]} {
        ProcessData $data
    } else {
        UpdateHeader "invalid input: [string range $line 0 40]..."
    }
}


proc ProcessEvent {evt loc val cloc} {
    global events reply_queue starting_up EXEC_EVENT_MASK data_queue c_view
    global STEP_EVENT_MASK stepping data_view listening value_queue statistics_data
    global current_c_location protocol_version the_name program_name trace_data

    set listening 1

    if {[info exists events($evt)]} {
        set eventname $events($evt)
    } else {
        UpdateHeader "unrecognized event: $evt"
        return
    }

    if {$data_queue != ""} {
        set data_queue [lrange $data_queue 1 end]
    }

    Log "evt: $eventname, dq: $data_queue, rq: $reply_queue, vq: $value_queue"

    if {$eventname != "listen"} {
        set statistics_data ""
        set trace_data ""
    }

    set current_c_location $cloc

    if {$c_view != ""} {
        LocateCSource $cloc
    }

    switch $eventname {
        connect {
            if {![regexp {^([^:]+):([^:]+):(\d+)$} $loc _ name pid pv]} {
                UpdateHeader "invalid connection info: $loc"
                return
            }

            if {$pv > $protocol_version} {
                UpdateHeader "client protocol doesn't match: $pv"
                return
            }

            wm title . "$the_name - $program_name"

            Log "\n##################### CONNECT ##################"
            SendReply SETMASK $STEP_EVENT_MASK
            set stepping 1
            lappend reply_queue FetchEventListReply FirstStepReply
        }
        listen {
            if {$reply_queue != ""} {
                set action [lindex $reply_queue 0]
                set reply_queue [lrange $reply_queue 1 end]
                Log "action: $action"
                $action
            } elseif {$val == 1} {
                # new dbg-info was registered
                lappend reply_queue ApplyTags
                FetchEventListReply
            }
        }
        default {
            # call/entry/assign/signal/gc
            LocateEvent $loc $val
            UpdateHeader "\[$eventname\]"

            if {$starting_up} {
                SendReply SETMASK $EXEC_EVENT_MASK
                set starting_up 0
            } elseif {$data_view != ""} UpdateData
        }
    }
}


proc UpdateData {} {
    global data_queue reply_queue watched_variables
    global watched_queue
    set watched_queue $watched_variables
    lappend reply_queue GetGlobals
    lappend data_queue GetAVData
    SendReply GET_AV
}


proc GetAVData {data} {
    global arguments_item_id value_queue
    set vals [ParseValueList $data]
    set cs [.data.t children $arguments_item_id]
    set len [llength $vals]
    set clen [llength $cs]

    for {set i 0} {$i < $len} {incr i} {
        lassign [ValueData [lindex $vals $i]] type text addr

        if {$i >= $clen} {
            set c [.data.t insert $arguments_item_id end -text $type -values \
                [list $text $addr]]
        } else {
            set c [lindex $cs $i]
            .data.t item $c -text $type -values [list $text $addr]
        }

        if {$addr != ""} {
            lappend value_queue $c
        }

        incr i
    }

    if {$i < $clen} {
        .data.t delete [lrange $cs $i end]
    }

    .data.t item $arguments_item_id -open 1
}


proc GetGlobals {} {
    global data_queue reply_queue watched_queue current_variable
    global data_view value_queue

    if {$watched_queue != ""} {
        set current_variable [lindex $watched_queue 0]
        set watched_queue [lrange $watched_queue 1 end]
        lappend data_queue GetGlobalData
        set name [MangleSymbol [.data.t item $current_variable -text]]
        SendReply GET_GLOBAL "\"$name\""
        lappend reply_queue GetGlobals
    } elseif {$data_view != ""} {
        if {$value_queue != ""} {
            GetValues
        } else {
            GetStatistics
        }
    }
}


proc GetValues {} {
    global data_view value_queue current_value data_queue reply_queue

    if {$data_view != ""} {
        if {$value_queue != ""} {
            set current_value [lindex $value_queue 0]
            Log "get value: $current_value"
            set value_queue [lrange $value_queue 1 end]
            lappend data_queue GetValueData
            scan [.data.t set $current_value 1] %x addr
            SendReply GET_SLOTS $addr
            lappend reply_queue GetValues
        } else {
            UpdateValueText {}
            GetTrace
        }
    }
}


proc GetTrace {} {
    global data_queue trace_data reply_queue

    if {$trace_data == ""} {
        lappend reply_queue GetStatistics
        lappend data_queue GetTraceData
        SendReply GET_TRACE
    } else GetStatistics
}


proc GetTraceData {data} {
    global trace_data

    if {![regexp {^"([^"]*)"$} $data _ str]} {
        append trace_data "<invalid trace data>\n"
    } else {
        append trace_data "$str\n"
    }
}


proc RedrawTrace {} {
    global trace_data
    .data.f.tr configure -state normal
    .data.f.tr delete 1.0 end
    .data.f.tr insert 1.0 $trace_data
    .data.f.tr configure -state disabled
}


proc GetStatistics {} {
    global data_queue statistics_data reply_queue trace_data

    if {$trace_data != ""} RedrawTrace

    if {$statistics_data == ""} {
        lappend data_queue GetStatisticsData
        SendReply GET_STATS
    }
}


proc GetStatisticsData {data} {
    global statistics_data
    set addrs [ParseValueList $data]
    set statistics_data $addrs
    RedrawStatistics
}


proc RedrawStatistics {} {
    global statistics_data stats membar_height

    if {$statistics_data == ""} return

    set w [winfo width .data.c]
    set w2 [expr $w / 2]
    set w10 [expr $w - 10]
    set mh [expr $membar_height / 3]
    set mh2 [expr $mh * 2]

    # fromspace
    lassign [CalcSize [lindex $statistics_data 0] [lindex $statistics_data 1] \
        [lindex $statistics_data 6] $w] p pc sz
    .data.c coords $stats(fromspace_used) 0 0 $p $mh
    .data.c coords $stats(fromspace_unused) $p 0 $w $mh
    .data.c coords $stats(fromspace_percentage) $w2 [expr $mh / 2]
    .data.c itemconfigure $stats(fromspace_percentage) -text "$pc%"
    .data.c coords $stats(fromspace_size) $w10 0
    .data.c itemconfigure $stats(fromspace_size) -text "${sz}k"

    # scratchspace
    if {[lindex $statistics_data 2] != 0} {
        lassign [CalcSize [lindex $statistics_data 2] [lindex $statistics_data 3] \
            [lindex $statistics_data 7] $w] p pc sz
        .data.c coords $stats(scratchspace_used) 0 $mh $p $mh2
        .data.c coords $stats(scratchspace_unused) $p $mh $w $mh2
        .data.c coords $stats(scratchspace_percentage) $w2 [expr int($mh * 1.5)]
        .data.c itemconfigure $stats(scratchspace_percentage) -text "$pc%"
        .data.c coords $stats(scratchspace_size) $w10 $mh
        .data.c itemconfigure $stats(scratchspace_size) -text "${sz}k"
    }

    # nursery
    lassign [CalcSize [lindex $statistics_data 4] [lindex $statistics_data 5] \
        [lindex $statistics_data 8] $w 1] p pc sz
    .data.c coords $stats(nursery_used) 0 $mh2 $p $membar_height
    .data.c coords $stats(nursery_unused) $p $mh2 $w $membar_height
    .data.c coords $stats(nursery_percentage) $w2 [expr int($mh * 2.5)]
    .data.c itemconfigure $stats(nursery_percentage) -text "$pc%"
    .data.c coords $stats(nursery_size) $w10 $mh2
    .data.c itemconfigure $stats(nursery_size) -text "${sz}k"
}


proc CalcSize {start limit top width {inv 0}} {
    set total [expr $limit - $start]

    if {$inv} {
        set amount [expr $limit - $top]
    } else {
        set amount [expr $top - $start]
    }

    set p [expr int(double($amount) / $total * 100)]
    set sz [expr $total / 1024]
    return [list [expr int((double($width) / $total) * $amount)] $p $sz]
}


proc GetValueData {data} {
    global current_value value_queue typecode value_cutoff_limit

    set vals [ParseValueList $data]
    set bits [lindex $vals 1]

    if {[info exists typecode($bits)]} {
        set type $typecode($bits)
    } else {
        set type "<invalid: $bits>"
    }

    .data.t item $current_value -text $type
    set cs {}

    switch [lindex $vals 0] {
        "SPECIAL" {
            set cs [.data.t children $current_value]

            if {$cs == ""} {
                set c1 [.data.t insert $current_value end]
                set cs {}
            } else {
                set c1 [lindex $cs 0]
                set cs [lrange $cs 1 end]
            }

            .data.t item $c1 -text "<native pointer>" -values \
                [list "" [format 0x%x [lindex $vals 2]]]
            set vals [lrange $vals 3 end]
        }
        "VECTOR" {
            set vals [lrange $vals 2 end]
            set cs [.data.t children $current_value]
        }
        "BLOB" {
            if {$type == "STRING" || $type == "LAMBDA_INFO"} {
                set str "\""

                foreach c [lrange $vals 2 end] {
                    # XXX escape special chars
                    append str [format %c $c]
                }

                append str "\""
            } elseif {$type == "FLONUM"} {
                set bytes [binary format c* $vals]
                binary scan $bytes d str
            } else {
                set str "#\${"

                foreach c [lrange $vals 2 end] {
                    append str [format %02x $c]
                }

                append str "}"
            }

            .data.t set $current_value 0 $str
            set cs [.data.t children $current_value]

            if {$cs != ""} {.data.t delete $cs}

            return
        }
        default {
            UpdateHeader "invalid value: $data"
        }
    }

    set vlen [llength $vals]
    set clen [llength $cs]

    for {set i 0} {$i < $vlen} {incr i} {
        set val [lindex $vals $i]
        lassign [ValueData $val] type text addr

        if {$i >= $clen} {
            set c [.data.t insert $current_value end -text $type -values \
                [list $text $addr]]
            Log "insert: $c"
        } else {
            set c [lindex $cs $i]
            Log "reuse: $c"
            .data.t item $c -text $type -values [list $text $addr]
        }

        if {$i >= $value_cutoff_limit} {
            .data.t item $c -text ":" -values {"" ""}
            incr i
            break
        }

        if {$addr != ""} {
            if {[.data.t item [.data.t parent $c] -open]} {
                lappend value_queue $c
            }
        } else {
            .data.t delete [.data.t children $c]
        }
    }

    if {$i < $clen} {
        .data.t delete [lrange $cs $i end]
    }
}


proc UpdateValueText {node} {
    global value_cutoff_limit
    set cs [.data.t children $node]

    foreach c $cs {
        UpdateValueText $c
    }

    if {$node == ""} return

    set addr [.data.t set $node 1]

    if {$addr == ""} return

    set type [.data.t item $node -text]

    if {$type == ":"} return

    set str "..."

    switch $type {
        "" return
        "<arguments>" return
        "<native pointer>" return
        FLONUM return
        LAMBDA_INFO return
        STRING return
        PAIR {
            set car [.data.t set [lindex $cs 0] 0]
            set cdr [.data.t set [lindex $cs 1] 0]
            set str "($car"

            switch [.data.t item [lindex $cs 1] -text] {
                NULL {append str ")"}
                PAIR {append str " [string range $cdr 1 end]"}
                default {append str " . $cdr)"}
            }
        }
        VECTOR {
            if {$cs == ""} {
                set str "#()"
            } else {
                set x0 [.data.t set [lindex $cs 0] 0]
                set str "#($x0"

                foreach c [lrange $cs 1 end] {
                    set x [.data.t set $c 0]
                    append str " $x"
                }

                append str ")"
            }
        }
        SYMBOL {
            set name [.data.t set [lindex $cs 1] 0]
            set str [DemangleSymbol [string range $name 1 "end-1"]]
        }
        default {
            set str "#<$type $addr>"
        }
    }

    if {[string length $str] >= $value_cutoff_limit} {
        set str "[string range $str 0 $value_cutoff_limit]..."
     }

    .data.t set $node 0 $str
}


proc OpenDataItem {} {
    global value_queue listening
    set item [.data.t focus]

    if {$item == ""} return

    if {!$listening} return

    if {[.data.t parent $item] == ""} return

    set cs [.data.t children $item]

    foreach c $cs {
        if {[.data.t set $c 1] != "" && \
            [.data.t item $c -text] != "<native pointer>"} {
            lappend value_queue $c
        }
    }

    GetValues
}


proc WatchGlobal {} {
    global data_queue watched_variables current_variable reply_queue

    if {![CheckListening]} return

    set name [string trim [.data.e get]]
    .data.e delete 0 end

    if {$name == ""} return

    if {[lsearch -exact $watched_variables $name] != -1} return

    set id [.data.t insert {} end -text $name]
    lappend watched_variables $id
    lappend data_queue GetGlobalData
    set current_variable $id
    set name [MangleSymbol $name]
    SendReply GET_GLOBAL "\"$name\""
    lappend reply_queue GetValues
}


proc RemoveGlobal {} {
    global watched_variables arguments_item_id
    set f [.data.t focus]

    if {$f == $arguments_item_id || [.data.t parent $f] == $arguments_item_id} return

    .data.t delete $f

    if {$f == ""} return

    set p [lsearch -exact $watched_variables $f]
    set watched_variables [lreplace $watched_variables $p $p]
}


proc GetGlobalData {data} {
    global current_variable watched_variables value_queue

    if {$data == "UNKNOWN"} {
        .data.t set $current_variable 0 "UNKNOWN"
        set p [lsearch -exact $watched_variables $current_variable]
        set watched_variables [lreplace $watched_variables $p $p]
        return
    }

    set node [.data.t children $current_variable]

    if {$node == ""} {
        set node [.data.t insert $current_variable end]
        .data.t item $current_variable -open 1
    }

    set val [ParseValueList $data]
    lassign [ValueData $val] type text addr
    .data.t item $node -text $type
    .data.t set $node 0 $text
    .data.t set $node 1 $addr

    if {$addr != ""} {
        lappend value_queue $node
    }
}


# returns type, text and address
proc ValueData {val} {
    set c1 [string index $val 0]
    set rest [string range $val 1 end]

    switch $c1 {
        "@" {
            return [list "" "..." [format "0x%x" $rest]]
        }
        "=" {
            switch $rest {
                6 {return {"BOOLEAN" "#f" ""}}
                22 {return {"BOOLEAN" "#t" ""}}
                14 {return {"NULL" "()" ""}}
                30 {return {"UNDEFINED" "#<undefined>" ""}}
                46 {return {"UNBOUND" "#<unbound>" ""}}
                62 {return {"EOF" "#<eof>" ""}}
                default {
                    if {($val & 15) == 10} {
                        return [list "CHARACTER" [format "#\%c" [expr $val >> 8]] ""]
                    }

                    return [list "???" [format "#<unknown immediate value 0x%x>" \
                        $val] ""]
                }
            }
        }
        default {return [list "FIXNUM" $val ""]}
    }
}


proc MangleSymbol {str} {
    if {[regexp {^##([^#]+)#(.+)$} $str _ prefix name]} {
        set len [string length $prefix]
        return [binary format ca*a* $len $prefix $name]
    }

    return $str
}


proc DemangleSymbol {str} {
    set b1 ""
    binary scan $str ca* b1 name

    if {$b1 == ""} {
        return $str
    } elseif {$b1 == 0} {
        return "#:$name"
    } elseif {$b1 < 32} {
        return [format "##%s#%s" [string range $name 0 2] [string range $name 3 end]]
    }

    return $str
}


proc ParseValueList {str} {
    set vals {}

    while {[regexp {^\s*(\S+)(.*)$} $str _ val rest]} {
        lappend vals $val
        set str $rest
    }

    return $vals
}


proc FirstStepReply {} {
    global stepping
    set stepping 0
    SendReply CONTINUE
}


proc ProcessData {data} {
    global data_queue

    if {$data_queue == ""} {
        UpdateHeader "unexpected data: $data"
    }

    set handler [lindex $data_queue 0]
    $handler $data
}


proc ExtractLocation args {
    foreach data $args {
        if {[regexp {^([^:]+):(\d+)(: .*)?$} $data _ fname line]} {
            return [list $fname $line]
        }
    }

    return ""
}


proc LocateFile {fname} {
    global search_path

    foreach d $search_path {
        set fn [file join $d $fname]

        if {[file exists $fn]} {
            set fn [file normalize $fn]
            Log "Located: $fn"
            return $fn
        }
    }

    return ""
}


proc InsertDebugInfo {index event args} {
    global file_list globals
    set loc [eval ExtractLocation $args]

    # check for assignment event
    if {$event == 1} {
        set name [lindex $args 1]
        lappend globals($name) $index
    }

    if {$loc != ""} {
        set fname [LocateFile [lindex $loc 0]]

        if {[lsearch -exact $file_list $fname] == -1} {
            lappend file_list $fname
        }

        set line [lindex $loc 1]
        # icky: compute array variable name from filename:
        set tname "file:$fname"
        global $tname
        set xname "$tname\($line\)"
        lappend $xname $index
        return 1
    }

    return 0
}

proc ProcessString {str} {
    if {$str == "#f"} {
        return ""
    } elseif {[regexp {^"(.*)"$} $str _ strip]} {
        return $strip
    } else {
        return $str
    }
}

proc FetchEventListReply {} {
    global file_list reply_queue data_queue
    UpdateHeader "fetching debug information ..."
    lappend data_queue EventInfoData
    SendReply LIST_EVENTS {""}
}


proc EventInfoData {data} {
    if {[regexp {(\d+)\s+(\d+)\s+([^\s]*)\s+(.*)$} $data _ index event loc val]} {
        set loc [ProcessString $loc]
        set val [ProcessString $val]
        InsertDebugInfo $index $event $loc $val
    } else {
        UpdateHeader "invalid event data: $data"
    }
}


proc ContinueExecution {} {
    global client_file EXEC_EVENT_MASK stepping reply_queue listening
    global value_queue

    if {$client_file == ""} return

    if {![CheckListening]} return

    UpdateHeader "executing ..."

    if {$stepping} {
        set stepping 0
        SendReply SETMASK $EXEC_EVENT_MASK
        lappend reply_queue ContinueExecution
    } else {
        set value_queue {}
        set listening 0
        SendReply CONTINUE
    }
}


proc StepExecution {} {
    global STEP_EVENT_MASK client_file stepping listening value_queue reply_queue
    global watched_queue

    if {$client_file == ""} return

    if {![CheckListening]} return

    if {!$stepping} {
        set stepping 1
        SendReply SETMASK $STEP_EVENT_MASK
        lappend reply_queue StepExecution
    } else {
        set value_queue {}
        set watched_queue {}
        set listening 0
        SendReply CONTINUE
    }

    UpdateHeader "stepping ..."
}


proc StartMark {w x y} {
    global mark_start_index last_marked_widget
    set mark_start_index($w) ""
    set last_marked_widget $w
    set old [$w tag ranges mk]

    if {$old != ""} {
        eval $w tag remove mk $old
    }

    if {![catch {$w index "@$x,$y"} pos]} {
        set mark_start_index($w) $pos
    }
}


proc EndMark {w} {
    global mark_start_index
    set rng [$w tag ranges mk]

    if {$rng != ""} {
        set text [eval $w get $rng]
        set len [string length $text]
        set found [$w search -all $text 1.0 end]

        foreach f $found {
            $w tag add mk $f "$f + $len chars"
        }
    }

    set mark_start_index($w) ""
}


proc MoveMark {w x y} {
    global mark_start_index

    if {$mark_start_index($w) == ""} return

    if {![catch {$w index "@$x,$y"} pos]} {
        if {$pos == $mark_start_index($w)} return

        set old [$w tag ranges mk]

        if {$old != ""} {
            eval $w tag remove $old
        }

        if {[$w compare $pos < $mark_start_index($w)]} {
            set tmp $mark_start_index($w)
            set mark_start_index($w) $pos
            set pos $tmp
        }

        $w tag add mk $mark_start_index($w) $pos
    }
}


proc FindNext {{w ""}} {
    global last_marked_widget

    if {$w == ""} {set w $last_marked_widget}

    # not sure if this test is needed
    if {[catch {$w index "@1,1"} pos]} return

    while 1 {
        set rng [$w tag nextrange mk $pos end]

        if {$rng == ""} return

        lassign $rng p1 pos

        if {[$w dlineinfo $p1] == ""} {
            $w see $p1
            return
        }
    }
}


proc FindPrevious {{w ""}} {
    global last_marked_widget

    if {$w == ""} {set w $last_marked_widget}

    # not sure if this test is needed
    if {[catch {$w index "@1,1"} pos]} return

    set rng [$w tag prevrange mk $pos 1.0]

    if {$rng == ""} return

    set p1 [lindex $rng 0]
    $w see $p1
}


proc SendReply {rep args} {
    global client_file reply
    set rest ""

    if {$args != ""} {
        set rest " [join $args]"
    }

    set str "($reply($rep)$rest)"
    Log "send: $str"
    puts $client_file $str
}


proc SelectFile {} {
    global current_filename selected_filename

    if {$current_filename == $selected_filename} return

    if {![LoadFile $selected_filename]} return

    if {[SwitchFile $selected_filename]} ApplyTags
}


proc OpenFile {} {
    global current_filename file_list
    set dir "."

    if {$current_filename != ""} {
        set dir [file dirname $current_filename]
    }

    set fname [tk_getOpenFile -title "Select source file" -initialdir $dir]
    set fname [file normalize $fname]

    if {$fname == "" || $fname == $current_filename} return

    if {[lsearch -exact $file_list $fname] == -1} {
        tk_messageBox -message "No debug information available for \"$fname\"" \
            -type ok
        return
    }

    if {![LoadFile $fname]} return

    if {[SwitchFile $fname]} ApplyTags
}


proc SwitchFile {fname} {
    global current_bp_lines saved_bp_lines file_list current_filename

    Log "switch: $current_filename -> $fname"

    if {$current_filename != ""} {
        Log "saving bps: $current_bp_lines"
        set saved_bp_lines($current_filename) $current_bp_lines
    }

    set current_filename $fname
    Log "searching $fname in $file_list"

    if {[lsearch -exact $file_list $fname] != -1} {
        if {[info exists saved_bp_lines($fname)]} {
            set current_bp_lines {}
            foreach line $saved_bp_lines($fname) {MarkBP $line}
            Log "restoring bps: $current_bp_lines"
        } else {
            set current_bp_lines {}
        }

        return 1
    }

    return 0
}


proc LocateEvent {loc val} {
    global current_filename file_list saved_bp_lines search_path last_location
    set loc [ExtractLocation $loc $val]

    if {$loc != ""} {
        set fname0 [lindex $loc 0]
        set fname [LocateFile [lindex $loc 0]]
        set line [lindex $loc 1]

        if {$fname != $current_filename} {
            if {![LoadFile $fname]} return

            if {[SwitchFile $fname]} ApplyTags
        }

        set last_location $line
        SetFocus $line
    }
}


proc LocateCSource {cloc} {
    global current_c_filename search_path
    set loc [ExtractLocation $cloc]

    if {$loc != ""} {
        .code.h configure -text $cloc
        set fname [file normalize [lindex $loc 0]]
        set line [lindex $loc 1]

        if {$fname != $current_c_filename} {
            foreach d $search_path {
                set fn [file join $d $fname]

                if {[file exists $fn]} {
                    set fname $fn
                    break
                }
            }

            if {![LoadFile $fname .code.t]} return
        }

        SetCFocus $line
    }
}


proc LoadFile {fname {w .t}} {
    $w configure -state normal
    $w delete 1.0 end

    if {[file exists $fname]} {
        set f [open $fname]
        $w insert 1.0 [read $f]
        close $f
        $w configure -state disabled
        return 1
    } else {
        $w insert 1.0 "File not found: \"$fname\""
        $w configure -state disabled
        return 0
    }
}


proc ApplyTags {} {
    global current_filename
    set aname "file:$current_filename"
    global $aname
    set old [.t tag ranges ev]
    Log "apply tags: $current_filename"

    if {$old != ""} {
        eval .t tag remove $old
    }

    foreach line [array names $aname] {
        set evts [set $aname\($line\)]
        .t tag add ev $line.0 "$line.0 lineend + 1 chars"
    }

    UpdateHeader "events tagged"
}


proc Server {channel addr port} {
    global client_addr client_file

    if {$client_file != ""} {
        close $channel
        return
    }

    fconfigure $channel -buffering line -encoding binary -blocking 0
    fileevent $channel readable ProcessInput
    set client_addr $addr
    set client_file $channel
}


proc SetupServer {} {
    global debugger_port
    socket -server Server $debugger_port
    .t configure -state normal
    .t insert end "Waiting for connection from client ...\n"
    .t configure -state disabled
}


proc Usage {code} {
    global the_name
    set usage "Usage: $the_name "
    append usage {[-help] [-n] [-d] [-dir DIRNAME] [-port PORT] [PROGRAM ARGUMENTS ...]}
    puts stderr $usage
    exit $code
}


set load_startup_file 1

for {set i 0} {$i < $argc} {incr i} {
    set arg [lindex $argv $i]

    switch -regexp -- $arg {
        {^--?(h|help)$} {Usage 0}
        {^-dir$} {
            incr i
            lappend search_path [lindex $argv $i]
        }
        {^-n$} {set load_startup_file 0}
        {^-port$} {
            incr i
            set debugger_port [lindex $argv $i]
        }
        {^-d$} {set logging 1}
        {^-} {Usage 1}
        default {
            if {$program_name != ""} {Usage 0}

            set program_name [lrange $argv $i end]
            break
        }
    }
}


if {$load_startup_file} {
    if {[file exists $env(HOME)/$startup_file]} {
        source $env(HOME)/$startup_file
    }

    if {[file exists $startup_file]} {
        source $startup_file
    }
}


SetupGUI
SetupBindings
SetupServer

if {$program_name != ""} {
    RunProcess $program_name
}


# TODO:
#
# - F2 is mostly pointless
# - data-view update is slow
#   - modify only when necessary? or are we creating too many items on the fly?
#   - or too much TCP-traffic?
# - allow spawning gdb, probably in separate terminal window(?)
#   - may be covered by just running "gdb <program>" as client
# - setting breakpoints on yet unregistered (i.e. dynamically loaded) files
#   is not possible - a file must be registered first
# - check whether "listening" check works
# - when retrieved data is wrong, clear queues
# - must watched globals be mangled, when qualified? (GET_GLOBAL)
# - dview: monospace font (needs tags, it seems)
# - https://sourceware.org/gdb/current/onlinedocs/gdb/GDB_002fMI.html#GDB_002fMI
# - gdb interface:
#   - toggle bp in C-source line, step/execute
#   - needs a way to trigger gdb from running program (in dbg-stub.c)
#     (send signal to self (SIGUSR2?))
# - allow explicit connection to debugger from Scheme code
# - multiple dbg-info for identical filenames will cause havoc
# - interrupt takes rather long (was in bignum-heavy code, try other)
# - bignums are shown as raw strings (uses string-type for bitvec)
# - how to handle threads?
