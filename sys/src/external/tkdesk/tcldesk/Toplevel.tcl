# =============================================================================
#
# File:		Toplevel.tcl
# Project:	TkDesk
#
# Started:	04.11.98
# Changed:	04.11.98
# Author:	cb
#
# Description:	Implements a generic Toplevel class which instantiates
#               a Tk toplevel widget to be used be subclasses implementing
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
# class Toplevel
# Instantiates a Tk toplevel widget.  Subclasses can access this widget
# through protected variable top.  An external interface is provided
# via the getToplevel method.
#

itcl_class Toplevel {

    constructor {config} {
	#puts "Toplevel $this"
	#puts "class [$this info class]"
	
	if {[info tclversion] >= 8.0} {
	    set top [::toplevel [namespace tail $this]-top \
		    -class [namespace tail [$this info class]]]
	} else {
	    set top [::toplevel [string trimleft $this-top ":"] \
		            -class [::$this info class]]
	}
	
	#puts "top: $top"
    }

    destructor {
	catch {destroy $top}
    }

    # ----- Methods and Procs -------------------------------------------------

    method config {config} {
    }
    
    method cget {var} {
	return [set [string trimleft $var -]]
    }

    method getToplevel {} {
	return $top
    }
    
    # ----- Class Variables --------------------------------------------------

    protected top "x"
}
