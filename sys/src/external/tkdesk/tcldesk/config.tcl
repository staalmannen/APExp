# =============================================================================
#
# File:		config.tcl
# Project:	TkDesk
#
# Started:	11.10.94
# Changed:	22.11.94
# Author:	cb
#
# Description:	Reads the config files.
#
# Copyright (C) 1996  Christian Bolik
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
# -----------------------------------------------------------------------------
#
# Sections:
#s    proc dsk_read_config {}
#s    proc dsk_edit_configs {args}
#s    proc source_cfg {file}
#s    proc read_System {}
#s    proc read_ButtonBar {}
#s    proc read_FileTags {}
#s    proc read_Preferences {}
#s    proc read_Commands {}
#s    proc read_Directories {}
#s    proc read_Popups {}
#s    proc read_AppBar {{fname "AppBar"}}
#s    proc read_Sounds {}
#s    proc read_Local {}
#s    proc read__history {}
#s    proc read__layout {}
#s    proc read__annotations {}
#s    proc read__bookmarks {}
#s    proc dsk_save_config {{all 0}}
#s    proc save__history {}
#s    proc save__layout {}
#s    proc _shift_geom {top}
#s    proc save__annotations {}
#s    proc save__bookmarks {}
#s    proc save__options {}
#s    proc dsk_restore_layout {}
#s    proc dsk_reread_config {{cfgfile ""}}
#s    proc dsk_persave_config {}
#s    proc _add_cmd_to_menu {menu cmd}
#s    proc dsk_rebuild_cmdmenus {}
#s    proc _add_dir_to_menu {this menu mdir}
#s    proc dsk_rebuild_dirmenus {}
#
# =============================================================================


global tkdesk

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_read_config
# Args:		none
# Returns: 	""
# Desc:		Determines the config dir and reads all of the config files.
# Side-FX:	Exits TkDesk if an error occured. Sets tkdesk(configdir).
#

proc dsk_read_config {} {
    global tkdesk env

    if ![info exists tkdesk(configdir)] {

	set notice 0
	set version 1.0a1
	if ![file exists $env(HOME)/.tkdesk] {
	    set tkdesk(first_time_user) 1
	    exec mkdir $env(HOME)/.tkdesk
	    exec mkdir $env(HOME)/.tkdesk/.trash
	    catch {eval exec cp [glob $tkdesk(library)/configs/*] \
		    $env(HOME)/.tkdesk}
	    dsk_catch {
		set fd [open $env(HOME)/.tkdesk/_version w]
		puts $fd $tkdesk(version)
		catch {close $fd}
	    }
	} else {
	    if ![file readable $env(HOME)/.tkdesk/_version] {
		set notice 1
	    } else {
		dsk_catch {
		    set fd [open $env(HOME)/.tkdesk/_version r]
		    set version [gets $fd]
		    catch {close $fd}
		}
		if {$version != $tkdesk(version)} {
		    set notice 1
		}
	    }
	}

	if {$notice} {
	    cb_info "Apparently you've been running a previous version of TkDesk. Please take a look at menu entry \"Help/Changes\" to find out what has changed since version $version."
	    dsk_catch {
		set fd [open $env(HOME)/.tkdesk/_version w]
		puts $fd $tkdesk(version)
		catch {close $fd}
	    }
	}

    	#
    	# Look for configuration directory in:
    	# 1. home dir, 2. current dir, 3. library dir
    	#
    
    	if [file isdirectory $env(HOME)/.tkdesk] {
	    if [string match $env(HOME) "/"] {
		set tkdesk(configdir) /.tkdesk
	    } else {
		set tkdesk(configdir) $env(HOME)/.tkdesk
	    }
    	} elseif [file isdirectory [pwd]/.tkdesk] {
            set tkdesk(configdir) [pwd]/.tkdesk
    	} elseif [file isdirectory $tkdesk(library)/configs] {
            set tkdesk(configdir) $tkdesk(library)/configs
    	} else {
            exit 1
    	}

    } else {
	# else configdir has been set via command line
	dsk_debug "TkDesk: Reading configuration from $tkdesk(configdir)"
	if ![file isdirectory $env(HOME)/.tkdesk] {
	    set tkdesk(first_time_user) 1
	}
    }

    # Save current mtime for automatic reloading, and desk update
    set tkdesk(configdir_mtime) [file mtime $tkdesk(configdir)]
    
    if ![file writable $tkdesk(configdir)] {
	cb_alert "Will not be able to auto-save configuration (configuration directory is not writable)."
    }

    dsk_debug "Setting tkdesk(configdir) to $tkdesk(configdir)"

    set tkdesk(configfiles) {AppBar ButtonBar Commands Directories \
	    FileTags Local Popups Sounds System}
    set tkdesk(configxpl,AppBar) {Buttons of the Application Bar}
    set tkdesk(configxpl,ButtonBar) {Defines the Bar underneath the Menu Bar}
    set tkdesk(configxpl,Commands) {Entries of the "Commands" Menu}
    set tkdesk(configxpl,Directories) {Entries of the "Directories" Menu}
    set tkdesk(configxpl,FileTags) {Colors, Fonts, and Icons of Files etc.}
    set tkdesk(configxpl,Local) {Local Extensions}
    set tkdesk(configxpl,Popups) {Popup Menus for Files etc.}
    set tkdesk(configxpl,Sounds) {Sounds to use for TkDesk events}
    set tkdesk(configxpl,System) {Fonts and Colors used by TkDesk, etc.}
    #set tkdesk(configxpl,AppBar) {}
    #set tkdesk(configxpl,ButtonBar) {}
    #set tkdesk(configxpl,Commands) {}
    #set tkdesk(configxpl,Directories) {}
    #set tkdesk(configxpl,FileTags) {}
    #set tkdesk(configxpl,Local) {}
    #set tkdesk(configxpl,Popups) {}
    #set tkdesk(configxpl,Sounds) {}
    #set tkdesk(configxpl,System) {}

    read_System
    read_ButtonBar
    read_Preferences
    read_FileTags
    read_Commands
    read_Directories
    read_Popups
    read_AppBar
    read_Sounds
    read_Local
    read__history
    read__annotations
    read__bookmarks
    read__layout
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_edit_configs
# Args:		files		opt. list of config files to edit
# Returns: 	""
# Desc:		Calls the editor via dsk_edit on all or selected config files.
# Side-FX:	none
#

proc dsk_edit_configs {args} {
    global tkdesk

    set cdir [string trimright $tkdesk(configdir) "/"]
    set clist ""
    set files $args
    if {$files == ""} {
	foreach cfile $tkdesk(configfiles) {
	    if {$cfile == "AppBar"} {
		set cfile $tkdesk(appbar,deffile)
	    }
	    lappend clist $cdir/$cfile
	}
    } else {
	foreach cfile $files {
	    if {$cfile == "AppBar"} {
		set cfile $tkdesk(appbar,deffile)
	    }
	    lappend clist $cdir/$cfile
	}
    }

    #dsk_Editor .de[dsk_Editor :: id] -files $clist
    set ed $tkdesk(editor,cmd)
    if [info exists tkdesk(conf_editor,cmd)] {
	set tkdesk(editor,cmd) $tkdesk(conf_editor,cmd)
    }
    eval dsk_edit $clist
    set tkdesk(editor,cmd) $ed
}

#
# -----------------------------------------------------------------------------
#
# Proc:		source_cfg
# Args:		file - path of cfg file to source
# Returns: 	""
# Desc:		Sources the configuration file $file.
# Side-FX:	none
#

proc source_cfg {file} {
    global tkdesk tkdesk_anno tk_strictMotif cb_tools env

    set err [catch "source $file" errmsg]
    if $err {
	# [todo] where does this dsk_lazy come from???
	#dsk_lazy
	dsk_errbell
	cb_error "Error in file [file tail $file]: $errmsg"
    }
    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_System
# Args:		none
# Returns: 	""
# Desc:		Reads the "System" configuration file.
#		Sets colors, fonts and other system-wide parameters.
# Side-FX:	Exits TkDesk if it was not found.
#

# Defaults:
set tkdesk(file_lb,minwidth) 10  ;# this now gets set in read_System below
set tkdesk(file_lb,minheight) 3
set tkdesk(color,directories) blue2
set tkdesk(color,executables) red
set tkdesk(color,symlinks) black
set tkdesk(color,symdirectories) blue2
set tkdesk(color,symexecutables) red
set tkdesk(color,drag) wheat
set tkdesk(color,entry_bg) white
set tkdesk(color,entry_fg) black
set tkdesk(color,text_bg) white
set tkdesk(color,text_fg) black
set tkdesk(color,icon_background) \#185f6a
set tkdesk(font,directories) -*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,executables) -*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,symlinks) -*-helvetica-medium-o-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,symdirectories) -*-helvetica-bold-o-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,symexecutables) -*-helvetica-bold-o-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,file_lbs) -*-helvetica-medium-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,status) -*-helvetica-medium-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,balloon)      -*-helvetica-medium-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,dialogs)      -*-times-medium-r-*-*-18-*-*-*-*-*-*-*
set tkdesk(font,labels) -*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,listboxes)    $tkdesk(font,labels)
set tkdesk(font,buttons) -*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,menubuttons)  $tkdesk(font,labels)
set tkdesk(font,menus)        $tkdesk(font,menubuttons)
set tkdesk(font,entries)      -*-lucidatypewriter-medium-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(font,text)         $tkdesk(font,entries)
set tkdesk(font,mono)         -*-lucidatypewriter-medium-r-*-*-12-*-*-*-*-*-*-*
set tkdesk(num_lbs) 3
set tkdesk(path,images) "$tkdesk(library)/images"
set tkdesk(path,sounds) "$tkdesk(library)/sounds"
set tkdesk(icon,trash-empty) next/recycle.xpm
set tkdesk(icon,trash-full) next/recycle_full.xpm
set tkdesk(icon,filebrowser) next/cabinet.xpm
set tkdesk(icon,filelist) next/folders.xpm
set tkdesk(icon,help) next/BookOpen.xpm
set tkdesk(icon,editor) next/Write.xpm
set tkdesk(icon,find) next/magnify.xpm
set tkdesk(editor,default_geometry) "80x25"
set tkdesk(cmd,print) "lpr"
set tkdesk(cmd,netscape) "netscape"
set tkdesk(cmd,mail) "mail -s %s %a"
set tkdesk(cmd,xterm) "xterm"
set tkdesk(cmd,df) "df"
set tkdesk(cmd,ps) "ps"
set tkdesk(cmd,su,exec) {xterm -sb -T "%c" -n "%c" -e su root -c "%c"}
set tkdesk(cmd,su,view) {xterm -sb -T "%c" -n "%c" -e pauseme su root -c "%c"}
set tkdesk(focus_follows_mouse) 1
set tkdesk(editor,auto_indent) 1
set tkdesk(editor,brace_indent) 1
set tkdesk(editor,wrap) char
set tkdesk(editor,real_tabs) 1
set tkdesk(editor,tab_width) 8
set tkdesk(editor,do_backups) 1
set tkdesk(editor,load_once) 1
set tkdesk(editor,cursor) black
set tkdesk(editor,statbar) 1
set tkdesk(editor,bindings) "classic"
set tkdesk(editor,font) $tkdesk(font,entries)
set tkdesk(desk_items,wm_managed) 0
set tkdesk(desk_items,label_width) 12
set tkdesk(dynamic_scrollbars) 1
set tkdesk(use_old_modifiers) 0
set tkdesk(color,annotation) gray55
set tkdesk(side_of_scrollbars) right
set tkdesk(focus_width) 1
set tkdesk(scrollbar_width) 11
set tkdesk(file_selector_type) "default"
set tkdesk(deskdir) ~/desktop

set tkdesk(title,browser) "%p"
set tkdesk(title,list) "%d"
set tkdesk(title,icon) "%d"


proc read_System {} {
    global tkdesk tk_strictMotif

    dsk_debug "Reading $tkdesk(configdir)/System"

    if ![file readable $tkdesk(configdir)/System] {
        catch {puts stderr "Couldn't read $tkdesk(configdir)/System! Exiting..."}
        exit 1
    } else {
        source_cfg $tkdesk(configdir)/System
    }
    
    #
    # Set colors
    #

    frame .dummy
    frame .dummy.f
    entry .dummy.e
    text .dummy.t
    scrollbar .dummy.s
    listbox .dummy.lb
    button .dummy.b
    radiobutton .dummy.rb
    checkbutton .dummy.cb
    menubutton .dummy.mb
    menu .dummy.mb.menu
    label .dummy.l
    message .dummy.msg
    canvas .dummy.cv
    
    if ![info exists tkdesk(color,background)] {
	if [info exists tkdesk(color,basic)] {
	    # for backward compatibility
	    set tkdesk(color,background) [cb_col $tkdesk(color,basic) white]
	} else {
	    set tkdesk(color,background) [.dummy.e cget -background]
	}
    }
    if ![info exists tkdesk(color,foreground)] {
	set tkdesk(color,foreground) [.dummy.e cget -foreground]
    }
    if ![info exists tkdesk(color,select_bg)] {
	set tkdesk(color,select_bg) [.dummy.e cget -selectbackground]
    }
    if ![info exists tkdesk(color,select_fg)] {
	set tkdesk(color,select_fg) [.dummy.e cget -selectforeground]
    }
    if ![info exists tkdesk(color,check_on)] {
	set tkdesk(color,check_on) [.dummy.cb cget -selectcolor]
    }
    if ![info exists tkdesk(color,focus)] {
	set tkdesk(color,focus) [.dummy.e cget -highlightcolor]
    }
    if ![info exists tkdesk(color,nofocus)] {
	set tkdesk(color,nofocus) [.dummy.e cget -highlightbackground]
    }
    if ![info exists tkdesk(color,focus_width)] {
	set tkdesk(color,focus_width) [.dummy.e cget -highlightthickness]
    }
    if ![info exists tkdesk(color,insert)] {
	set tkdesk(color,insert) [.dummy.e cget -insertbackground]
    }
    if ![info exists tkdesk(color,filelb)] {
	# for backward compatibility
	set tkdesk(color,filelb) [cb_col $tkdesk(color,filelb_background)] 
    }
    if ![info exists tkdesk(color,icon)] {
	# for backward compatibility
	set tkdesk(color,icon) [cb_col $tkdesk(color,icon_background)] 
    }
    if ![info exists tkdesk(color,listsel)] {
	if {$tkdesk(color,filelb) != "white" \
	    && [winfo depth .] > 1} {
	    set tkdesk(color,listsel) white
	} else {
	    set tkdesk(color,listsel) black
	}
    }

    if ![info exists tkdesk(config_done)] {
	tk_setPalette \
		background [cb_col $tkdesk(color,background) white] \
		foreground [cb_col $tkdesk(color,foreground) black] \
		selectColor [cb_col $tkdesk(color,check_on)] \
		selectBackground [cb_col $tkdesk(color,select_bg)] \
		selectForeground [cb_col $tkdesk(color,select_fg)] \
		highlightBackground [cb_col $tkdesk(color,nofocus)] \
		highlightColor [cb_col $tkdesk(color,focus)] \
		insertBackground [cb_col $tkdesk(color,insert)]
    }

    option add *background [cb_col $tkdesk(color,background) white] userDefault
    option add *foreground [cb_col $tkdesk(color,foreground) black] userDefault
    option add *selectColor [cb_col $tkdesk(color,check_on)] userDefault
    option add *selectBackground [cb_col $tkdesk(color,select_bg)] userDefault
    option add *selectForeground [cb_col $tkdesk(color,select_fg)] userDefault
    option add *highlightBackground [cb_col $tkdesk(color,nofocus)] userDefault
    option add *highlightColor [cb_col $tkdesk(color,focus)] userDefault
    option add *insertBackground [cb_col $tkdesk(color,insert)] userDefault
	    
    option add *Entry.background [cb_col $tkdesk(color,entry_bg)]
    set tkdesk(color,entry) $tkdesk(color,entry_bg)
    option add *Entry.foreground [cb_col $tkdesk(color,entry_fg)]
    option add *Text.background [cb_col $tkdesk(color,text_bg)]
    set tkdesk(color,text) $tkdesk(color,text_bg)
    option add *Text.foreground [cb_col $tkdesk(color,text_fg)]
    
    if {[winfo depth .] > 1} {
	option add *Listbox.selectBackground [cb_col $tkdesk(color,listsel)]
	option add *Listbox.selectForeground [cb_col $tkdesk(color,foreground)]
    }
    
    #
    # Set fonts
    #
    
    option add *Label.font [cb_font $tkdesk(font,labels)]
    option add *Checkbutton.font [cb_font $tkdesk(font,labels)]
    option add *Radiobutton.font [cb_font $tkdesk(font,labels)]
    option add *Entry.font [cb_font $tkdesk(font,entries)]
    option add *Text.font [cb_font $tkdesk(font,entries)]
    option add *Button.font [cb_font $tkdesk(font,buttons)]
    option add *Menubutton.font [cb_font $tkdesk(font,menubuttons)]
    option add *Menu.font [cb_font $tkdesk(font,menus)]
    option add *Listbox.font [cb_font $tkdesk(font,listboxes)]
    option add *Dialog.msg.font [cb_font $tkdesk(font,dialogs)]

    _cb_help_proc:setfont \
	    [cb_font $tkdesk(font,entries)] \
	    [cb_font $tkdesk(font,listboxes)]
    
    option add *Menubutton.padX 3
    option add *Menubutton.padY 3
    option add *Scrollbar.borderWidth 2
    option add *Scrollbar.width $tkdesk(scrollbar_width)
    option add *Entry.highlightThickness $tkdesk(focus_width) userDefault
    option add *Button.highlightThickness $tkdesk(focus_width) userDefault

    if $tkdesk(focus_follows_mouse) {
	tk_focusFollowsMouse
    }

    if ![info exists tkdesk(trashdir)] {
	set tkdesk(trashdir) $tkdesk(configdir)/.trash
    } else {
	if ![file isdirectory $tkdesk(trashdir)] {
	    set err [catch {exec mkdir $tkdesk(trashdir)} errmsg]
	    if $err {
		cb_error "Error: \"$errmsg\". Using default trash directory."
		set tkdesk(trashdir) $tkdesk(configdir)/.trash
	    }
	}
    }
    set tkdesk(trashdir) [cb_tilde $tkdesk(trashdir) expand]

    dsk_Listbox :: selcolor [cb_col $tkdesk(color,listsel)]
    dsk_Listbox :: modifier $tkdesk(use_old_modifiers)
    dsk_Listbox :: scrollbarside $tkdesk(side_of_scrollbars)
    
    #set tkdesk(file_lb,minwidth) $tkdesk(file_lb,width)
    dsk_DeskItem :: set_width $tkdesk(desk_items,label_width)

    # Backward compatibility:
    set tkdesk(strict_motif) $tk_strictMotif

    # Desktop dir handling:
    if {[info exists tkdesk(deskdir)]} {
	if {[string length $tkdesk(deskdir)] > 0} {
	    set tkdesk(deskdir) [cb_tilde $tkdesk(deskdir) expand]
	    if {![file isdirectory $tkdesk(deskdir)]} {
		exec mkdir $tkdesk(deskdir)
	    }
	    set tkdesk(deskdir_mtime) [file mtime $tkdesk(deskdir)]
	}
    }
    
    catch {destroy .dummy}
    
    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_ButtonBar
# Args:		none
# Returns: 	""
# Desc:		Reads the "ButtonBar" config file.
# Side-FX:	sets the tkdesk(directories) list
#

proc read_ButtonBar {} {
    global tkdesk

    #
    # Read the button bar list
    #

    set tkdesk(small_button_bar) {}
    if [file readable $tkdesk(configdir)/ButtonBar] {
    	dsk_debug "Reading $tkdesk(configdir)/ButtonBar"
        source_cfg $tkdesk(configdir)/ButtonBar
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_FileTags
# Args:		none
# Returns: 	""
# Desc:		Reads the "FileTags" config file.
# Side-FX:	Creates tags for the file listboxes.
#

set tkdesk(file_tags,ignore) {}

proc read_FileTags {} {
    global tkdesk

    #
    # Read file tags
    #
    
    if [file readable $tkdesk(configdir)/FileTags] {
        dsk_debug "Reading $tkdesk(configdir)/FileTags"
        source_cfg $tkdesk(configdir)/FileTags

	if {[info commands dsk_FileListbox_fileTags] != ""} {
	    # exec only if a FileListbox has already been created
	    dsk_FileListbox_fileTags
	}
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_Preferences
# Args:		none
# Returns: 	""
# Desc:		Reads the "Preferences" config file.
# Side-FX:	
#

# Defaults:
set tkdesk(add_icons) 1		;# add icons to file lists?
set tkdesk(show_all_files) 0	;# show files starting with "." ?
set tkdesk(long_listing) 0	;# do long listings? ?
set tkdesk(folders_on_top) 1	;# put folders always on top ?
set tkdesk(append_type_char) 0	;# append "/" to folders etc. ?
set tkdesk(single_click) 0	;# Let dirs be opened by a single click?
set tkdesk(strip_home) 1	;# use $HOME as root dir if under ~ ?
set tkdesk(at_pointer) 1	;# Place dialogs at mouse pointer?
set tkdesk(overwrite_always) 0	;# Overwrite existing files /wo asking?
set tkdesk(really_delete) 0	;# Delete REALLY by default?
set tkdesk(quick_dragndrop) 0   ;# don't ask when dropping files?
set tkdesk(dot_regular) 0       ;# treat exec's containing dots as regulars?
set tkdesk(sort_history) 1      ;# sort history menus?
set tkdesk(use_sound) 0         ;# Use sound if available? (see file "Sounds")
set tkdesk(in_browser) 0        ;# open new file windows always as browsers?
set tkdesk(default_sort) name   ;# default sort style
set tkdesk(ask_on_delete) 1     ;# ask even if not really deleting
set tkdesk() 1	;# ask before exiting?
set tkdesk(tkdesk_server) 0     ;# start TkDesk server
set tkdesk(list_statbar) 0      ;# display status bar in file list windows?
set tkdesk(tearoff-menus) 0     ;# 1 if menus should be tear-off-able
set tkdesk(focus_follows_mouse) 1   ;# focus model to use
set tkdesk(strict_motif) 0      ;# strict Motif look-and-feel?
set tkdesk(auto_reload_conf) 1  ;# automatically reload modified conf files?
set tkdesk(expand_dir_bookmarks) 1  ;# expand dirs in Bookmarks menu?
set tkdesk(confirm_netscape) 1    ;# ask whether to start Netscape?

set tkdesk(confvars) { \
	long_listing show_all_files add_icons folders_on_top \
	append_type_char single_click strip_home at_pointer overwrite_always \
	really_delete quick_dragndrop sort_history use_sound default_sort \
        ask_on_delete ask_on_exit in_browser netscape_help tkdesk_server \
	editor,auto_indent editor,wrap editor,do_backups editor,load_once \
	editor,real_tabs editor,tab_width list_statbar appbar,autoraise \
	tearoff-menus focus_follows_mouse strict_motif confirm_netscape \
	auto_reload_conf editor,statbar expand_dir_bookmarks dot_regular
}

set tkdesk(autosave,history) 1
set tkdesk(autosave,layout) 1
set tkdesk(autosave,annotations) 1
set tkdesk(autosave,bookmarks) 1
set tkdesk(autosave,options) 1

set cb_tools(balloon_help) 1	;# display neat/annoying help popups?
set tkdesk(netscape_help) 0	;# display help thru netscape?

proc read_Preferences {} {
    global tkdesk tk_strictMotif

    #
    # Read preferences
    #

    if [file readable $tkdesk(configdir)/_options] {
	set pfile "_options"
    } elseif [file readable $tkdesk(configdir)/Preferences] {
	set pfile "Preferences"
    } else {
	set pfile "no-prefs" ;# fake file name for next test
    }
    
    if [file readable $tkdesk(configdir)/$pfile] {
    	dsk_debug "Reading $tkdesk(configdir)/$pfile"
	set nlb $tkdesk(num_lbs)  ;# for backward compatibilty
        source_cfg $tkdesk(configdir)/$pfile
	set tkdesk(num_lbs) $nlb
    }

    # always copy, move etc. all selected files by default:
    set tkdesk(all_files) 1

    # we don't want free selection!
    set tkdesk(free_selection) 0
    
    # disable this at start-up (backward comp.)
    set tkdesk(exec_as_root) 0
    
    if $tkdesk(tkdesk_server) {
	dsk_progress "Starting server..."
	dsk_setup_server
    }
    
    dsk_FileList :: status_bar $tkdesk(list_statbar)
    dsk_FileListbox :: dotregular $tkdesk(dot_regular)

    option add *Menu.tearOff $tkdesk(tearoff-menus)
    set tk_strictMotif $tkdesk(strict_motif)
    
    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_Commands
# Args:		none
# Returns: 	""
# Desc:		Reads the "Commands" config file.
# Side-FX:	sets the tkdesk(commands) list
#

proc read_Commands {} {
    global tkdesk

    #
    # Read directories
    #
    
    if [file readable $tkdesk(configdir)/Commands] {
    	dsk_debug "Reading $tkdesk(configdir)/Commands"
        source_cfg $tkdesk(configdir)/Commands
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_Directories
# Args:		none
# Returns: 	""
# Desc:		Reads the "Directories" config file.
# Side-FX:	sets the tkdesk(directories) list
#

proc read_Directories {} {
    global tkdesk

    #
    # Read directories
    #
    
    if [file readable $tkdesk(configdir)/Directories] {
    	dsk_debug "Reading $tkdesk(configdir)/Directories"
        source_cfg $tkdesk(configdir)/Directories
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_Popups
# Args:		none
# Returns: 	""
# Desc:		Reads the "Popups" config file.
# Side-FX:	sets the tkdesk(popup,...) lists
#

set tkdesk(fileops,popup) {
    {{Link (symbolic)} {
	dsk_exec $tkdesk(cmd,symln) %S %T
    }}
    {{Link (hard)} {
	dsk_exec $tkdesk(cmd,ln) %S %T
    }}
    {{Untar} {
	dsk_bgexec {gzip -cd %S | tar xf - -C %T} {Untaring %f...}
    }}
    {{Diff} {
	dsk_view diff -bc %S %T
    }}
    {{Patch} {
	dsk_path_exec %T xterm -sb -T "patch <%S" -n patch -e pauseme sh -c "patch <%S"
    }}
    {{Concatenate} {
	dsk_exec cat %S >%T
    }}
}

proc read_Popups {} {
    global tkdesk

    #
    # Read popups
    #
    
    if [file readable $tkdesk(configdir)/Popups] {
    	dsk_debug "Reading $tkdesk(configdir)/Popups"
        source_cfg $tkdesk(configdir)/Popups
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read_AppBar
# Args:		none
# Returns: 	""
# Desc:		Reads the "AppBar" config file.
# Side-FX:	sets the tkdesk(appbar) list
#

# some defaults:
set tkdesk(appbar,wm_managed) 0
set tkdesk(appbar,dragger) 0
set tkdesk(appbar,max) 19
set tkdesk(appbar,font,time) -*-courier-medium-r-*-*-10-*-*-*-*-*-*-*
set tkdesk(appbar,font,weekday) -*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*
set tkdesk(appbar,font,day) -*-times-bold-r-*-*-24-*-*-*-*-*-*-*
set tkdesk(appbar,font,month) -*-helvetica-medium-o-*-*-12-*-*-*-*-*-*-*
set tkdesk(appbar,12hour) 0
set tkdesk(appbar,time,background) black
set tkdesk(appbar,time,foreground) green
set tkdesk(appbar,time,borderwidth) 2
set tkdesk(appbar,time,relief) raised
set tkdesk(appbar,load,delay) 15
set tkdesk(appbar,mail,delay) 30
set tkdesk(appbar,mail,notifier) 0
set tkdesk(appbar,mail,nomail) mailbox_empty.xpm
set tkdesk(appbar,mail,oldmail) mailbox_old.xpm
set tkdesk(appbar,mail,newmail) mailbox_full.xpm
set tkdesk(appbar,mail,newbg) slategrey
set tkdesk(appbar,trash,empty) trashcan.xpm
set tkdesk(appbar,trash,full) trashcan_full.xpm
set tkdesk(appbar,trash,label) 1
set tkdesk(appbar,trash,font) fixed
set tkdesk(appbar,dialup,down) next/PhoneTT.xpm
set tkdesk(appbar,dialup,up)   next/PhoneTTOffhook.xpm
set tkdesk(appbar,autoraise)   0
set tkdesk(appbar,deffile) "AppBar"
set tkdesk(appbar,ipad) 2

proc read_AppBar {{fname "AppBar"}} {
    global tkdesk

    #
    # Read application bar
    #
    if [file readable $tkdesk(configdir)/$fname] {
    	dsk_debug "Reading $tkdesk(configdir)/$fname"
	set tkdesk(appbar,deffile) $fname
        source_cfg $tkdesk(configdir)/$fname
    }

    return
}

# -----------------------------------------------------------------------------
#
# Proc:		read_Sounds
# Args:		none
# Returns: 	""
# Desc:		Reads the "Sound" config file.
# Side-FX:	sets the tkdesk(sound,...) variables
#

proc read_Sounds {} {
    global tkdesk

    #
    # Read the sounds file
    #

    catch {unset tkdesk(soundcmd)}
    
    if [file readable $tkdesk(configdir)/Sounds] {
    	dsk_debug "Reading $tkdesk(configdir)/Sounds"
        source_cfg $tkdesk(configdir)/Sounds
    }

    if ![info exists tkdesk(soundcmd)] {
	set tkdesk(use_sound) 0
    }
    dsk_Common :: setSoundEntryState

    return
}

# -----------------------------------------------------------------------------
#
# Proc:		read_Local
# Args:		none
# Returns: 	""
# Desc:		Reads the "Local" config file.
# Side-FX:	depends on user skills...
#

proc read_Local {} {
    global tkdesk

    #
    # Read the local config file
    #
    
    if [file readable $tkdesk(configdir)/Local] {
    	dsk_debug "Reading $tkdesk(configdir)/Local"
        source_cfg $tkdesk(configdir)/Local
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read__history
# Args:		none
# Returns: 	""
# Desc:		Reads the _history file if it exists.
# Side-FX:	Sets the global path history.
#

proc read__history {} {
    global tkdesk

    if [file readable $tkdesk(configdir)/_history] {
    	dsk_debug "Reading $tkdesk(configdir)/_history"
	set fd [open $tkdesk(configdir)/_history]

	set tkdesk(history_list) ""
	while 1 {
	    set h [gets $fd]
	    if {$h == ""} {
		break
	    } else {
		lappend tkdesk(history_list) [list $h]
	    }
	}
	catch {close $fd}
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read__layout
# Args:		none
# Returns: 	""
# Desc:		Reads the _layout file if it exists.
# Side-FX:	none
#

proc read__layout {} {
    global tkdesk env

    if [info exists tkdesk(layout_file)] {
	set lf $tkdesk(layout_file)
    } else {
	set lf $tkdesk(configdir)/_layout
    }
    
    if [file readable $lf] {
    	dsk_debug "Reading $lf"
	set fd [open $lf]

	set tkdesk(layout) ""
	while 1 {
	    set l [gets $fd]
	    if {$l == ""} {
		break
	    } else {
		lappend tkdesk(layout) $l
	    }
	}
	catch {close $fd}
	if {$tkdesk(layout) == ""} {
	    catch {puts stderr "TkDesk: $f corrupted, skipping"}
	    unset tkdesk(layout)
	}
    } else {

	# start in new user's home directory
	set tkdesk(initdir) $env(HOME)
    }

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		read__annotations
# Args:		none
# Returns: 	""
# Desc:		Reads the _annotations file if it exists.
# Side-FX:	Sets the file annotations.
#

proc read__annotations {} {
    global tkdesk tkdesk_anno

    if [file readable $tkdesk(configdir)/_annotations] {
    	dsk_debug "Reading $tkdesk(configdir)/_annotations"
	source_cfg $tkdesk(configdir)/_annotations
    }

    return
}

# -----------------------------------------------------------------------------
#
# Proc:		read__bookmarks
# Args:		none
# Returns: 	""
# Desc:		Reads the _bookmarks file if it exists.
# Side-FX:	Sets the bookmarks list.
#

proc read__bookmarks {} {
    global tkdesk

    set tkdesk(bookmarks) {}
    if [file readable $tkdesk(configdir)/_bookmarks] {
    	dsk_debug "Reading $tkdesk(configdir)/_bookmarks"
	source_cfg $tkdesk(configdir)/_bookmarks
    }

    return
}

#
# =============================================================================
#

# -----------------------------------------------------------------------------
#
# Proc:		dsk_save_config
# Args:		none
# Returns: 	""
# Desc:		Saves the saveable configuration parameters to disk.
# Side-FX:	none
#

set dsk_save_config(busy) 0

proc dsk_save_config {{all 0}} {
    global tkdesk dsk_save_config

    if $dsk_save_config(busy) return
    set dsk_save_config(busy) 1

    if {$tkdesk(autosave,history) || $all} save__history
    if {$tkdesk(autosave,layout) || $all} save__layout
    if {$tkdesk(autosave,annotations) || $all} save__annotations
    if {$tkdesk(autosave,bookmarks) || $all} save__bookmarks
    if {$tkdesk(autosave,options) || $all} save__options
    dsk_status "Ready."

    set dsk_save_config(busy) 0
    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		save__history
# Args:		none
# Returns: 	""
# Desc:		Saves the global path history to _history.
# Side-FX:	none
#

proc save__history {} {
    global tkdesk

    set err [catch {set fd [open $tkdesk(configdir)/_history w]}]
    if !$err {
	dsk_catch {
	    dsk_status "Saving History Lists ..."
	    foreach histobj $tkdesk(histlist) {
		puts $fd "# $histobj"
		set hist [$histobj get]
		for {set i [expr [llength $hist] - 1]} {$i > -1} {incr i -1} {
		    puts $fd [lindex $hist $i]
		}
	    }
	    catch {close $fd}
	}
    } else {
	dsk_debug "Couldn't open $tkdesk(configdir)/_history for writing."
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		save__layout
# Args:		none
# Returns: 	""
# Desc:		Tries to save the window layout of TkDesk to _layout.
# Side-FX:	
#

proc save__layout {} {
    global tkdesk

    if [info exists tkdesk(layout_file)] {
	set lf $tkdesk(layout_file)
    } else {
	set lf $tkdesk(configdir)/_layout
    }
    
    set err [catch {set fd [open $lf w]}]
    if !$err {
	dsk_catch {
	    dsk_status "Saving Layout ..."
	    foreach class {dsk_FileViewer dsk_FileList dsk_DeskItem \
		    dsk_HistEntry} {
		set obj_list [itcl_info objects -class $class]
		foreach obj $obj_list {
		    set top [$obj getToplevel]
		    if ![winfo exists $top] continue
		    switch $class {
			dsk_FileViewer -
			dsk_FileList {
			    set state [wm state $top]
			    if {$state == "normal" || $state == "iconic"} {
				set geom [_shift_geom $top]
				puts -nonewline $fd "$class \{[$obj curdir]\} "
				puts -nonewline $fd "$geom "
				if {$class == "dsk_FileViewer"} {
				    puts -nonewline $fd "$state "
				    puts $fd "[$obj cget num_lbs]"
				} else {
				    puts $fd "$state"
				}
			    }
			}
			dsk_DeskItem {
			    puts -nonewline $fd "$class \{[$obj cget -file]\} "
			    set geom [_shift_geom $top]
			    puts $fd $geom
			}
			dsk_HistEntry {
			    puts -nonewline $fd "$class "
			    set geom [_shift_geom $top]
			    puts $fd $geom
			}
		    }
		}
	    }
	    foreach toplevel {dsk_jobs dsk_copy \
		    dsk_delete dsk_appbar dsk_find_annotation dsk_bgexec \
		    dsk_find_files periodic} {
		set geom ""
		if [winfo exists .$toplevel] {
		    set geom [_shift_geom .$toplevel]
		} else {
		    if [info exists tkdesk(geometry,$toplevel)] {
			set geom $tkdesk(geometry,$toplevel)
		    }
		}
		if {$geom != ""} {
		    if {$toplevel == "dsk_appbar"} {
			set geom [dsk_appbar_adjgeom $geom]
			puts $fd "Toplevel $toplevel [winfo exists .$toplevel] $geom $tkdesk(appbar,deffile)"
		    } else {
			puts $fd "Toplevel $toplevel [winfo exists .$toplevel] $geom"
		    }
		}
	    }
	    catch {close $fd}
	}
    } else {
	dsk_debug "Couldn't open $lf for writing."
    }

}

proc _shift_geom {top} {
    set geom [wm geometry $top]
    if {[string first "+-" $geom] > -1} {
	# shift the window into visible area
	set geom [split $geom x+]
	set w [lindex $geom 0]
	set h [lindex $geom 1]
	set x [lindex $geom 2]
	set y [lindex $geom 3]
	if {$x < 0} {
	    if {abs($x) >= [winfo width $top]} {
		set sw [winfo screenwidth $top]
		while {$x < 0} {incr x $sw}
	    }
	}
	if {$y < 0} {
	    if {abs($y) >= [winfo height $top]} {
		set sh [winfo screenheight $top]
		while {$y < 0} {incr y $sh}
	    }
	}
	set geom "${w}x${h}+${x}+${y}"
    }
    return $geom
}

#
# -----------------------------------------------------------------------------
#
# Proc:		save__annotations
# Args:		none
# Returns: 	""
# Desc:		Saves the file annotations to _annotations.
# Side-FX:	none
#

proc save__annotations {} {
    global tkdesk tkdesk_anno

    if ![info exists tkdesk_anno] return
    set err [catch {set fd [open $tkdesk(configdir)/_annotations w]}]
    if !$err {
	dsk_catch {
	    dsk_status "Saving File Annotations ..."
	    foreach name [array names tkdesk_anno] {
		puts $fd "set tkdesk_anno([_make_fname_safe $name]) \\"
		puts $fd \{$tkdesk_anno($name)\}
	    }
	    catch {close $fd}
	}
    } else {
	dsk_debug "Couldn't open $tkdesk(configdir)/_annotations for writing."
    }
}

# -----------------------------------------------------------------------------
#
# Proc:		save__bookmarks
# Args:		none
# Returns: 	""
# Desc:		Saves the bookmark list to _bookmarks.
# Side-FX:	none
#

proc save__bookmarks {} {
    global tkdesk

    set err [catch {set fd [open $tkdesk(configdir)/_bookmarks w]}]
    if !$err {
	dsk_catch {
	    dsk_status "Saving Bookmarks ..."
	    puts $fd "set tkdesk(bookmarks) {"
	    foreach bm $tkdesk(bookmarks) {
		puts $fd "\{$bm\}"
	    }
	    puts $fd "}"
	    catch {close $fd}
	}
    } else {
	dsk_debug "Couldn't open $tkdesk(configdir)/_annotations for writing."
    }
}

# -----------------------------------------------------------------------------
#
# Proc:		save__options
# Args:		none
# Returns: 	""
# Desc:		Saves the settings of the "Options" menu to _options.
# Side-FX:	none
#

proc save__options {} {
    global tkdesk cb_tools

    set err [catch {set fd [open $tkdesk(configdir)/_options w]}]
    if !$err {
	dsk_catch {
	    dsk_status "Saving Options ..."
	    foreach var $tkdesk(confvars) {
		puts $fd "set tkdesk($var) $tkdesk($var)"
	    }
	    puts $fd "set tkdesk(autosave,history) $tkdesk(autosave,history)"
	    puts $fd "set tkdesk(autosave,layout) $tkdesk(autosave,layout)"
	    puts $fd "set tkdesk(autosave,annotations) $tkdesk(autosave,annotations)"
	    puts $fd "set tkdesk(autosave,bookmarks) $tkdesk(autosave,bookmarks)"
	    puts $fd "set tkdesk(autosave,options) $tkdesk(autosave,options)"
	    puts $fd "set cb_tools(balloon_help) $cb_tools(balloon_help)"
	    catch {close $fd}
	}
    } else {
	dsk_debug "Couldn't open $tkdesk(configdir)/_options for writing."
    }
}

#
# =============================================================================
#

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_restore_layout
# Args:		none
# Returns: 	""
# Desc:		Tries to restore the layout of the last session.
# Side-FX:	Creates several windows, depending on the file _layout.
#

set tkdesk(have_window) 0

proc dsk_restore_layout {} {
    global tkdesk

    set tkdesk(restoring_layout) 1
    if [info exists tkdesk(layout)] {
	dsk_debug "Restoring layout..."
    	dsk_debug "tkdesk(ayout): $tkdesk(layout)"
    	foreach l $tkdesk(layout) {
	    set class [lindex $l 0]
	    switch $class {
	    	dsk_FileViewer {
		    set tkdesk(have_window) 1
		    dsk_progress "Creating a file browser..."
		    set win .fv[dsk_FileViewer :: id]
		    set nlb [lindex $l 4]
		    if {$nlb == ""} {
			set nlb $tkdesk(num_lbs)
		    }
		    if [info exists tkdesk(user,startdir)] {
			set dir $tkdesk(user,startdir)
			unset tkdesk(user,startdir)
		    } else {
			set dir [lindex $l 1]
		    }
		    dsk_FileViewer $win -dir $dir \
			    -num_lbs $nlb -dontmap 1
		    set win [$win getToplevel]
		    #wm withdraw $win
		    wm geometry $win [lindex $l 2]
		    if {[lindex $l 3] == "iconic" || $tkdesk(iconic)} {
			update
			wm iconify $win
		    } else {
			wm deiconify $win
			tkwait visibility $win
			catch "lower $win .dsk_welcome"
			update
		    }
		}
	    	dsk_FileList {
		    set tkdesk(have_window) 1
		    dsk_progress "Creating a file list..."
		    set win .dfl[dsk_FileList :: id]
		    dsk_FileList $win -dir [lindex $l 1] -dontmap 1
		    set win [$win getToplevel]
		    #wm withdraw $win
		    wm geometry $win [lindex $l 2]
		    if {[lindex $l 3] == "iconic" || $tkdesk(iconic)} {
		    	update
			wm iconify $win
		    } else {
			wm deiconify $win
			tkwait visibility $win
			catch "lower $win .dsk_welcome"
			update
		    }
		}
	    	dsk_DeskItem {
		    set itemname [lindex $l 1]
		    if {![file exists $itemname]} {
			continue
		    }
		    if [file isdirectory $itemname] {
			set tkdesk(have_window) 1
		    }
		    dsk_progress "Creating a desk item..."
		    set win .di[dsk_DeskItem :: id]
		    dsk_DeskItem $win -file $itemname -dontmap 1
		    set win [$win getToplevel]
		    #wm withdraw $win
		    set g [split [lindex $l 2] x+]
		    wm geometry $win +[lindex $g 2]+[lindex $g 3]
		    wm deiconify $win
		    tkwait visibility $win
		    catch "lower $win .dsk_welcome"
		    update
		}
	    	dsk_HistEntry {
		    ot_maplist $l type geom
		    set tkdesk(geometry,hist_entry) $geom
	    	}
	    	Toplevel {
		    set df ""
		    ot_maplist $l type func posted geom df
		    if {$func == "dsk_appbar"} {
			set tkdesk(have_window) 1
			if {$df != ""} {
			    set tkdesk(appbar,deffile) $df
			    if {$df != "AppBar"} {
				read_AppBar $df
			    }
			}
		    }
		    set tkdesk(geometry,$func) $geom
		    if $posted {
			eval $func
		    }
	    	}
	    }
    	}
    }
    set tkdesk(restoring_layout) 0

    return
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_reread_config
# Args:		none
# Returns: 	""
# Desc:		Rereads the config files.
# Side-FX:	Does a dsk_save_config.
#

proc dsk_reread_config {{cfgfile ""}} {
    global tkdesk

    if {$cfgfile != ""} {
	dsk_busy
	dsk_status "Rereading $cfgfile..."
	
	switch $cfgfile {
	    AppBar {
		if [winfo exists .dsk_appbar] {
		    dsk_appbar close
		    set open_appbar 1
		}
		cb_image !reset
		read_AppBar
		if [info exists open_appbar] {
		    dsk_appbar
		}
	    }
	    ButtonBar {
		cb_image !reset
		read_ButtonBar
		foreach br [itcl_info objects -class dsk_FileViewer] {
		    $br _button_bar
		}
		foreach fl [itcl_info objects -class dsk_FileList] {
		    $fl _button_bar
		}
	    }
	    Commands {
		read_Commands
		dsk_rebuild_cmdmenus
	    }
	    Directories {
		read_Directories
		dsk_rebuild_dirmenus
	    }
	    FileTags {
		#dsk_reread_config		
		dsk_FileListbox :: tag reset
		cb_image !reset
		read_FileTags
		foreach fl [itcl_info objects -class dsk_FileListbox] {
		    if [winfo exists [$fl getFrame]] {
			$fl refresh
		    }
		}
		foreach di [itcl_info objects -class dsk_DeskItem] {
		    if [winfo exists [$di getToplevel]] {
			$di refresh
		    }
		}
	    }
	    Local {
		read_Local
	    }
	    Popups {
		read_Popups
	    }
	    Preferences {
		read_Preferences
	    }
	    Sounds {
		read_Sounds
	    }
	    System {
		read_System
	    }
	    default {
		# assume unknown config file contains an application bar
		if [winfo exists .dsk_appbar] {
		    dsk_appbar close
		    set open_appbar 1
		}
		cb_image !reset
		read_AppBar $cfgfile
		if [info exists open_appbar] {
		    dsk_appbar
		}
	    }
	}
	
	dsk_status "Ready."
	dsk_lazy
	return
	
    } else {
	foreach cfg $tkdesk(configfiles) {
	    dsk_reread_config $cfg
	}
	return
    }

    # OBSOLETE - this is no longer executed
    #
    # Reread all config files:
    #

#    foreach obj [itcl_info objects -class dsk_Editor] {
#	if {[$obj close_win] == "cancel"} {
#	    return
#	}
#    }
#
#    dsk_busy
#
#    dsk_save_config
#    dsk_status "Rereading configuration..."
#    dsk_read_config
#
#    dsk_debug "Deleting old windows..."
#    foreach class {dsk_FileViewer dsk_FileList} {
#	foreach obj [itcl_info objects -class $class] {
#	    $obj delete
#	}
#	$class :: id reset
#    }
#    dsk_Editor :: id reset
#    foreach topname {dsk_ask_exec dsk_ask_dir dsk_jobs dsk_copy \
#		dsk_delete dsk_appbar dsk_find_annotation} {
#	catch "destroy .$topname"
#    }
#
#    dsk_restore_layout
#
#    dsk_lazy
#    return

}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_persave_config
# Args:		none
# Returns: 	""
# Desc:		Saves the configuration (i.e. history and layout) periodically.
# Side-FX:	none
#

proc dsk_persave_config {} {
    global tkdesk

    if {[itcl_info objects -class dsk_FileViewer] != ""} {
    	dsk_save_config
    	after [expr $tkdesk(update,config) * 60000] dsk_persave_config
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_add_cmd_to_menu
# Args:		menu - name of menu widget
#               cmd - list of commands (initially from the Commands cfgfile)
# Returns: 	""
# Desc:		Adds new menu entries to the given menu to invoke commands.
# Side-FX:	none
#

set tkdesk(_cmdmenu,cnt) 0
proc _add_cmd_to_menu {menu cmd} {
    global tkdesk

    if {[llength $cmd] == 2} {
	set command [string_replace [lindex $cmd 1] \" \\\"]
	$menu add command -label [lindex $cmd 0] \
		-command "cd \[dsk_active dir\] ;\
		set tkdesk(error_source) {Commands} ;\
		eval \[_expand_pc [list $command]\];\
		set tkdesk(error_source) {} ;\
		cd ~" 
		#-font $tkdesk(font,file_lbs)
    } elseif {[llength $cmd] == 1} {
	if {$cmd == "."} {
	    $menu config -tearoff 1
	} else {
	    $menu add separator
	}
    } else {
	incr tkdesk(_cmdmenu,cnt)
	set m ${menu}.c$tkdesk(_cmdmenu,cnt)
	$menu add cascade -label [lindex $cmd 0] -menu $m 
		#-font $tkdesk(font,file_lbs)

	catch "destroy $m"
	menu $m
	set cmd [lreplace $cmd 0 0]
	foreach c $cmd {
	    _add_cmd_to_menu $m $c
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_rebuild_cmdmenus
# Args:		none
# Returns: 	""
# Desc:		Rebuilds the Commands menus of all Viewers and Lists.
# Side-FX:	none
#

proc dsk_rebuild_cmdmenus {} {
    global tkdesk

    set tkdesk(_cmdmenu,cnt) 0
    if [info exists tkdesk(commands)] {
	foreach class "dsk_FileViewer dsk_FileList" {
	    foreach t [itcl_info objects -class $class] {
		if {$class == "dsk_FileViewer"} {
		    set m [$t getToplevel].fMenu.mbCmds.menu
		} else {
		    set m [$t getToplevel].fMenu.mbOthers.menu.cmd
		}
		set fe [expr [$m cget -tearoff] ? 12 : 11]
		catch "$m delete $fe last"
		foreach cmd $tkdesk(commands) {
		    if {[llength $cmd] > 1} {
			_add_cmd_to_menu $m $cmd
		    } else {
			if {$cmd == "."} {
			    $menu config -tearoff 1
			} else {
			    $menu add separator
			}
		    }
		}
		$m add separator
		$m add cascade -label "History" -menu $m.mhe
	    }
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		_add_dir_to_menu
# Args:		menu - name of menu widget
#               mdir - list of directories
# Returns: 	""
# Desc:		Adds directory menu entries to the given menu.
# Side-FX:	none
#

set tkdesk(_dirmenu,cnt) 0
proc _add_dir_to_menu {this menu mdir} {
    global tkdesk

    if {[llength $mdir] == 1} {
	if {[string index $mdir 0] == "*"} {
	    set mdir [string range $mdir 1 end]
	    incr tkdesk(_dirmenu,cnt)
	    set m ${menu}.cas$tkdesk(_dirmenu,cnt)
	    catch {destroy $m}
	    menu $m -postcommand "dsk_casdirs $mdir $m 1"
	    $menu add cascade -label "$mdir (*)" -menu $m \
		    -font [cb_font $tkdesk(font,file_lbs)]
	} elseif {[string index $mdir 0] == "&"} {
	    set mdir [string range $mdir 1 end]
	    incr tkdesk(_dirmenu,cnt)
	    set m ${menu}.cas$tkdesk(_dirmenu,cnt)
	    catch {destroy $m}
	    menu $m -postcommand "dsk_casdirs $mdir $m 1 {} 1"
	    $menu add cascade -label "$mdir (&)" -menu $m \
		    -font [cb_font $tkdesk(font,file_lbs)]
	} else {
	    $menu add command -label $mdir \
		    -command "$this config -dir $mdir" \
		    -font [cb_font $tkdesk(font,file_lbs)]
	}
    } else {
	incr tkdesk(_dirmenu,cnt)
	set m ${menu}.d$tkdesk(_dirmenu,cnt)
	$menu add cascade -label [lindex $mdir 0] -menu $m \
		-font [cb_font $tkdesk(font,file_lbs)]
	catch "destroy $m"
	menu $m
	bind $m <ButtonRelease-1> "
	set tkdesk(menu,control) 0
	[bind Menu <ButtonRelease-1>]"
	bind $m <Control-ButtonRelease-1> "
	set tkdesk(menu,control) 1
	[bind Menu <ButtonRelease-1>]"

	foreach d $mdir {
	    if {$d == "-"} {
		$m add separator
	    } elseif {$d == "."} {
		$m config -tearoff 1
	    } else {
		_add_dir_to_menu $this $m $d
	    }
	}
    }
}

#
# -----------------------------------------------------------------------------
#
# Proc:		dsk_rebuild_dirmenus
# Args:		none
# Returns: 	""
# Desc:		Rebuilds the Directories menus of all Viewers and Lists.
# Side-FX:	none
#

proc dsk_rebuild_dirmenus {} {
    global tkdesk env

    set tkdesk(_dirmenu,cnt) 0
    if [info exists tkdesk(directories)] {
	foreach class "dsk_FileViewer dsk_FileList" {
	    foreach t [itcl_info objects -class $class] {
		set m [$t getToplevel].fMenu.mbDirs.menu
		set fe [expr [$m cget -tearoff] ? 11 : 10]
		catch "$m delete $fe last"
		foreach mdir $tkdesk(directories) {
		    if {$mdir == "-"} {
			$m add separator
		    } elseif {$mdir == "."} {
			$m config -tearoff 1
		    } else {
			_add_dir_to_menu $t $m $mdir
		    }
		}
		
		$m add separator
		$m add cascade -label "Trees" -menu ${m}.fs
		$m add cascade -label "History" -menu $m.mhd
	    }
	}
    }
}

