# tcl-stdchan-test.tcl -- what buffering the three standard channels get.
#
# WHERE THIS CAME FROM. io-14.1, io-14.2 and their chan-io twins -- four
# tests -- want
#
#	line line none
#
# for stdin, stdout and stderr, and APExp answers `line line line'.
# Tcl asks for exactly that itself, in tclUnixChan.c's
# TclpGetDefaultStdChannel:
#
#	case TCL_STDERR: ... bufMode = "none"; break;
#	...
#	Tcl_SetChannelOption(NULL, channel, "-buffering", bufMode);
#
# The interp there is NULL, so a failure of that call is silent. Reading
# further would be guessing between two stories, and this script tells
# them apart in one run instead:
#
#	A. the option call FAILS      -- then setting it here fails too
#	B. something RESETS it after  -- then setting it here works
#
# RUN IT TWICE, and the second one is the one the suite resembles:
#
#	tclsh tcl-stdchan-test.tcl
#	tclsh tcl-stdchan-test.tcl >/tmp/b.out 2>&1 ; cat /tmp/b.out
#
# If the answers differ, the redirect is the condition and the next
# question is TclOSseek(2,...) -- which is what decides whether
# TclpGetDefaultStdChannel returns a channel at all. If they are the
# same, the redirect is not involved.
#
# This is a PROBE of one system's behaviour, not a library rule: report
# what it prints, do not assert it.

proc line {label value} {
    puts [format "  %-34s %s" $label $value]
}

puts "--- 1. what the three channels say now ---"
set was(stderr) "?"
foreach ch {stdin stdout stderr} {
    set buf "?"
    catch {set buf [fconfigure $ch -buffering]}
    set was($ch) $buf
    set tty "?"
    # -mode is a serial-line option: it succeeds only on a terminal, so
    # this says whether the channel is one without needing tcltest.
    set tty [expr {[catch {fconfigure $ch -mode}] ? "no" : "yes"}]
    line "$ch -buffering" "$buf   (terminal: $tty)"
}
line "wanted" "line line none"

puts "--- 2. can stderr's buffering be SET at all? ---"
#
# This is the whole point of the file. Tcl's own startup makes exactly
# this call and cannot see whether it worked.
#
set err ""
if {$was(stderr) eq "none"} {
    #
    # On a system where section 1 is already right there is nothing for
    # this section to tell apart, and a verdict printed anyway would be
    # read as one. A check that draws its own conclusion has to do the
    # arithmetic the reader would.
    #
    line "stderr was already none" "nothing to diagnose on this system"
    line "VERDICT" "not applicable -- section 1 is correct here"
} elseif {[catch {fconfigure stderr -buffering none} err]} {
    line "setting it raised" $err
    line "VERDICT" "A: the option call itself fails"
} else {
    set now "?"
    catch {set now [fconfigure stderr -buffering]}
    line "after setting it to none it reads" $now
    if {$now eq "none"} {
	line "VERDICT" "B: the set works, so something reset it earlier"
    } else {
	line "VERDICT" "A: the set was accepted and did not take"
    }
}

puts "--- 3. the same question for a channel we open ourselves ---"
#
# If a fresh channel also refuses `none', the fault is not in anything
# to do with the standard channels.
#
set path [file join [expr {[file isdirectory /tmp] ? "/tmp" : "."}] \
    apexp-stdchan-probe]
if {[catch {set f [open $path w]} err]} {
    line "could not open a scratch file" $err
} else {
    catch {fconfigure $f -buffering none}
    set now "?"
    catch {set now [fconfigure $f -buffering]}
    line "a fresh file channel set to none reads" $now
    catch {close $f}
    catch {file delete $path}
}

puts "--- 4. which tcl is this ---"
line "patchlevel" [info patchlevel]
line "platform" $tcl_platform(platform)/$tcl_platform(os)
puts "done"
