# =============================================================================
#
# File:		Frame.tcl
# Project:	TkDesk
#
# Started:	04.11.98
# Changed:	04.11.98
# Author:	cb
#
# Description:	Implements a generic Frame class which instantiates
#               a Tk frame widget to be used be subclasses implementing
#               megawidgets.
#
# Copyright (C) 1998  Christian Bolik
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
# See the file "COPYING" in the base directory of this distribution
# for more.
#
# =============================================================================

# -----------------------------------------------------------------------------
# class Frame
# Instantiates a Tk frame widget.  Subclasses can access this widget
# through protected variable frame.  An external interface is provided
# via the getFrame method.
#

itcl_class Frame {

    constructor {config} {
	#puts "Frame $this"
	#puts "class [::$this info class]"
	
	if {[info tclversion] >= 8.0} {
	    set frame [::frame [namespace tail $this]-frame \
		    -class [namespace tail [$this info class]]]
	} else {
	    set frame [::frame [string trimleft $this-frame ":"] \
		            -class [::$this info class]]
	}
	
	#puts "frame: $frame"
    }

    destructor {
	catch {destroy $frame}
    }

    # ----- Methods and Procs -------------------------------------------------

    method config {config} {
    }
    
    method cget {var} {
	return [set [string trimleft $var -]]
    }

    method getFrame {} {
	return $frame
    }
    
    # ----- Class Variables --------------------------------------------------

    protected frame ""

    public bd {} {
	config -borderwidth $bd
    }
    public borderwidth {} {
	if [winfo exists $frame] {
	    $frame config -bd $borderwidth
	}
    }
    public bg {} {
	config -background $bg
    }
    public background {} {
	if [winfo exists $frame] {
	    $frame config -bg $background
	}
    }
    public relief {} {
	if [winfo exists $frame] {
	    $frame config -relief $relief
	}
    }
}
