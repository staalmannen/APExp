# The widget operations from Tk's constraints.tcl, one at a time.
#
#	wish tk-widget-test.tcl
#
# Every Tk test file dies inside constraints.tcl. The source trace in
# tk-runtest.tcl put it there: bell.test -> main.tcl -> testutils.tcl
# (completes) -> constraints.tcl (never returns). The process dies at
# the C level -- Tcl's exit is never called, nothing catchable is
# raised, status 1, and not a word on stderr.
#
# constraints.tcl's first half is display and windowing-system queries
# and the childTkProcess handshake, which is fixed and verified at 20/20
# by tk-childproc-test.tcl. Its second half is the first thing in the
# entire chain that builds real widgets and renders text, which is the
# Plan 9 draw and font backend doing actual work:
#
#	entry .e -width 0 -font {Helvetica -12} -bd 1 -highlightthickness 1
#	.e insert end a.bcd
#	winfo reqwidth .e / winfo reqheight .e
#	text .t -width 80 -height 20 -font {Times -14} -bd 1
#	pack .t
#	.t insert end "This is\na dot."
#	update
#	.t bbox 1.3 / .t bbox 2.5
#
# This runs exactly those, with a flushed mark between each, so the last
# mark printed names the operation that kills wish.
#
# The expected values are Tk's own and will not match a Plan 9 font;
# constraints.tcl only uses them to decide whether the "fonts"
# constraint holds, so a mismatch is a skipped test, not a failure.
# What matters here is surviving the calls.

proc mark {m} {
    puts "MARK $m"
    flush stdout
}

proc try {label script} {
    mark "$label ..."
    if {[catch {uplevel 1 $script} result]} {
	mark "$label RAISED: $result"
	return ""
    }
    if {$result eq ""} {
	mark "$label ok"
    } else {
	mark "$label ok -> $result"
    }
    return $result
}

mark "start, [info nameofexecutable]"
mark "windowingsystem is [tk windowingsystem]"

# --- Pure font operations, no widgets -------------------------------
#
# These exercise TkpGetFontFromAttributes, tkp9_openfont and
# tkp9_measuretext without creating a window, a cursor, a 3D border or
# a GC. If one of these dies, it is the font backend; if they all pass
# and "create entry" still dies, the font path is exonerated and the
# fault is in one of the other things a widget allocates.

try "font families"			{font families}
try "font measure Helvetica"		{font measure {Helvetica -12} "abc"}
try "font metrics Helvetica"		{font metrics {Helvetica -12}}
try "font measure Times"		{font measure {Times -14} "abc"}
try "font actual Helvetica"		{font actual {Helvetica -12}}

# --- Widgets, simplest first ----------------------------------------
#
# A frame allocates a border and colours but no font; a label adds a
# font; an entry adds a cursor and an insertion cursor. Whichever is
# the first to die names what is at fault.

try "create frame"			{frame .f}
try "destroy frame"			{destroy .f}
try "create label"			{label .l -text hi}
try "destroy label"			{destroy .l}
try "create plain entry"		{entry .e2}
try "destroy plain entry"		{destroy .e2}
try "create entry with font"		{entry .e3 -font {Helvetica -12}}
try "destroy entry with font"		{destroy .e3}

# --- Exactly what constraints.tcl does ------------------------------

try "destroy .e (may not exist)"	{destroy .e}
try "create entry"			{entry .e -width 0 -font {Helvetica -12} -bd 1 -highlightthickness 1}
try "insert into entry"			{.e insert end a.bcd}
try "winfo reqwidth .e"			{winfo reqwidth .e}
try "winfo reqheight .e"		{winfo reqheight .e}
try "destroy .e"			{destroy .e}

try "destroy .t (may not exist)"	{destroy .t}
try "create text"			{text .t -width 80 -height 20 -font {Times -14} -bd 1}
try "pack .t"				{pack .t}
try "insert into text"			{.t insert end "This is\na dot."}
try "update"				{update}
try "bbox 1.3"				{.t bbox 1.3}
try "bbox 2.5"				{.t bbox 2.5}
try "destroy .t"			{destroy .t}

mark "all done"
exit 0
