# =============================================================================
#
# File:		cb_popup.tcl
# Project:	cb_tools
# Started:	?
# Changed:	23.09.94
#
# Description:	Implements popup menus. This has been copied from the XF-
#		package and has been only slightly modified.
#	 Note:  Cascaded menu must be children of the menu that's specified
#		by cb_MenuPopupAdd!
#
# -----------------------------------------------------------------------------
#
# Sections:
#	proc cb_MenuPopupAdd {xfW xfButton xfMenu {xfModifier ""} \
#		{xfCanvasTag ""} {showImm 0} {immX -1} {immY -1}}
#
#	... and lots of internal procs.
#
# =============================================================================

proc cb_menuPopup {w menu {mb 3}} {
    $menu config -tearoff 0
    cb_MenuPopupAdd $w $mb $menu "" "" 0 -1 -1 1    
}

# =============================================================================
# This is taken from the XF-Distribution and has been slightly modified.

proc cb_MenuPopupAdd {xfW xfButton xfMenu {xfModifier ""} {xfCanvasTag ""} {
   showImm 0} {immX -1} {immY -1} {dontDestroy 0}} {# xf ignore me 7
# the popup menu handling is from (I already gave up with popup handling :-):
#
# Copyright 1991,1992 by James Noble.
# Everyone is granted permission to copy, modify and redistribute.
# This notice must be preserved on all copies or derivates.
#
# cb: I have modified this to popup immediately to have selection-dependent
#     menus (call cb_MenuPopupAdd with showImm = 1).
#
##########
# Procedure: cb_MenuPopupAdd
# Description: attach a popup menu to widget
# Arguments: xfW - the widget
#            xfButton - the mouse button we use
#            xfMenu - the menu to attach
#            {xfModifier} - a optional modifier
#            {xfCanvasTag} - a canvas tagOrId
#	     {showImm} - post popup when called
#	     {immX}, {immY} - location for posting
#	     {dontDestroy} - true if menu should not be destroyed after posting
# Returns: none
# Sideeffects: none
##########
  global tk_popupPriv

  update

  set tk_popupPriv($xfMenu,focus) ""
  set tk_popupPriv($xfMenu,grab) ""
  if {"$xfModifier" != ""} {
    set press "$xfModifier-"
    set motion "$xfModifier-"
    set release "Any-"
  } {
    set press ""
    set motion ""
    set release ""
  }

  bind $xfMenu "<${motion}B${xfButton}-Motion>" \
    "cb_MenuPopupMotion $xfMenu %W %X %Y; break"
  bind $xfMenu "<${release}ButtonRelease-${xfButton}>" \
    "cb_MenuPopupRelease $xfMenu %W $dontDestroy; break"
  if {"$xfCanvasTag" == ""} {
    if {!$showImm} {
      bind $xfW "<${press}ButtonPress-${xfButton}>" \
        "cb_MenuPopupPost $xfMenu %X %Y; break"
    }
    bind $xfW "<${release}ButtonRelease-${xfButton}>" \
      "cb_MenuPopupRelease $xfMenu %W $dontDestroy; break"
  } {
    $xfW bind $xfCanvasTag "<${press}ButtonPress-${xfButton}>" \
      "cb_MenuPopupPost $xfMenu %X %Y; break"
    $xfW bind $xfCanvasTag "<${release}ButtonRelease-${xfButton}>" \
      "cb_MenuPopupRelease $xfMenu %W $dontDestroy; break"
  }
  if $showImm {
    cb_MenuPopupPost $xfMenu $immX $immY
  }
}

proc cb_MenuPopupPost {xfMenu xfX xfY} {# xf ignore me 7
##########
# Procedure: cb_MenuPopupPost
# Description: post the popup menu
# Arguments: xfMenu - the menu
#            xfX - the root x coordinate
#            xfY - the root x coordinate
# Returns: none
# Sideeffects: none
##########
  global tk_popupPriv

  if {"[info commands $xfMenu]" != ""} {
    if {![info exists tk_popupPriv($xfMenu,focus)]} {
      set tk_popupPriv($xfMenu,focus) [focus]
    } {
      if {"$tk_popupPriv($xfMenu,focus)" == ""} {
        set tk_popupPriv($xfMenu,focus) [focus]
      }
    }
    set tk_popupPriv($xfMenu,grab) $xfMenu

    catch "$xfMenu activate none"
    catch "$xfMenu post $xfX $xfY"

    catch "focus $xfMenu"
    catch "grab -global $xfMenu"
  }
}

proc cb_MenuPopupMotion {xfMenu xfW xfX xfY} {# xf ignore me 7
##########
# Procedure: cb_MenuPopupMotion
# Description: handle the popup menu motion
# Arguments: xfMenu - the topmost menu
#            xfW - the menu
#            xfX - the root x coordinate
#            xfY - the root x coordinate
# Returns: none
# Sideeffects: none
##########
  global tk_popupPriv

  if {"[info commands $xfW]" != "" && [winfo ismapped $xfW] &&
      "[winfo class $xfW]" == "Menu" &&
      [info exists tk_popupPriv($xfMenu,focus)] &&
      "$tk_popupPriv($xfMenu,focus)" != "" &&
      [info exists tk_popupPriv($xfMenu,grab)] &&
      "$tk_popupPriv($xfMenu,grab)" != ""} {
    set xfPopMinX [winfo rootx $xfW]
    set xfPopMaxX [expr $xfPopMinX+[winfo width $xfW]]
    if {$xfX >= $xfPopMinX && $xfX <= $xfPopMaxX} {
      $xfW activate @[expr $xfY-[winfo rooty $xfW]]
      if {![catch "$xfW entryconfig @[expr $xfY-[winfo rooty $xfW]] -menu" result]} {
        if {"[lindex $result 4]" != ""} {
          foreach binding [bind $xfMenu] {
            bind [lindex $result 4] $binding [bind $xfMenu $binding]
          }
        }
      }
    } else {
      $xfW activate none
    }
  }
}

proc cb_MenuPopupRelease {xfMenu xfW {dontDestroy 0}} {# xf ignore me 7
##########
# Procedure: cb_MenuPopupRelease
# Description: remove the popup menu
# Arguments: xfMenu - the topmost menu widget
#            xfW - the menu widget
# Returns: none
# Sideeffects: none
##########
  global tk_popupPriv
  global tk_version

  if {"[info commands $xfW]" != "" && [winfo ismapped $xfW] &&
      "[winfo class $xfW]" == "Menu" &&
      [info exists tk_popupPriv($xfMenu,focus)] &&
      "$tk_popupPriv($xfMenu,focus)" != "" &&
      [info exists tk_popupPriv($xfMenu,grab)] &&
      "$tk_popupPriv($xfMenu,grab)" != ""} {
    if {$tk_version >= 3.0} {
      catch "grab release $tk_popupPriv($xfMenu,grab)"
    } {
      catch "grab none"
    }
    catch "focus $tk_popupPriv($xfMenu,focus)"
    set tk_popupPriv($xfMenu,focus) ""
    set tk_popupPriv($xfMenu,grab) ""
    if {"[$xfW index active]" != "none"} {
      $xfW invoke active; catch "$xfMenu unpost"
    }
  }
  catch "$xfMenu unpost"

  if !$dontDestroy {
    catch "destroy $xfMenu"
  }
}
