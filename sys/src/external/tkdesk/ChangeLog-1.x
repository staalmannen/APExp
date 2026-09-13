
TkDesk Change Log for Version 1.x:

04/26/2002

  - Improved (hopefully) the way configure searches for tcl/tk/itcl
    installs.  Added --with-tclconfig, --with-tkconfig, --with-itclconfig
    options for using special *Config.sh versions.  Removed --enable-tcltk8
    option.
  - Changed date format in the CHANGES file from the logical dd.mm.yy to
    the U.S.-centric mm/dd/yyyy.  My apologies to the rest of the world,
    but it was giving me a headache.  What else would you expect from an
    American anyway?  After the next release, I'll expect you all to learn
    AMERICAN English, drink crappy light beer, and start calling soccer by
    its real name: "soccer".  You should all be playing ice hockey anyway.
    And not that sissy European pass-around-the-puck ice hockey either, but
    some real, manly, North-American open-ice body-checking ice hockey.
  - We'd like to apologize for the previous entry.  The maintainer evidently
    went off his medication.  This lapse has been remedied and hopefully
    there will not be any future repetition of such shameful behavior.

10/07/2001

  - Updated references to the TkDesk homepage URL and the maintainer
    email address.
  - Updated default Internet->Locations menu.

09/16/2001

  - Removed the TODO file pending a re-evaluation of the goals for
    future TkDesk releases
  - Merged previously released fixes into ver-1-2-1:
	appbar-dnd.diff
	empty-trash.diff
	exit-save-dd.diff
	find-dd.diff
  - Moved the CHANGES file from tcldesk/doc to the TkDesk source root
    dir.  Updated Makefile.in so that the CHANGES will still get installed
    along with the rest of the user docs.


11/14/1999   Released TkDesk 1.2

11/05/1999

  - In the past few days made multiple changes to work with BLT 2.4j
    to be able to support Tcl/Tk 8.1 and 8.2.

09/14/1999

  - In the copy dialog now accept file specifications of the forms
    "machine:/path" and "user@machine:/path" to allow for scp being used.

07/22/1999

  - If desktop items correspond to character or block special files they
    are now also configured as drop targets.  Useful for floppy disks,
    tape drives etc. in conjunction with the updated copy dialog popup
    menu (tar, untar, etc.).
  - The copy dialog's popup menu may now contain separators, denoted by entries
    consisting of a single "-" in the definition of tkdesk(fileops,popup).
    (CONFIG)
  - New option (in "Options/File Lists"): "Dot: Execs Regular".  If switched
    on executable files are treated like regular files wrt popup menus and
    opening, and display, if their name contains a dot.  Default is off.

07/07/1999

  - Added a simplistic "desktop" facility to TkDesk.  This is a configurable
    directory that is monitored by TkDesk which creates and deletes desktop
    items for files and directories in this dir, keeping its contents and
    associated desktop items (icons) in sync.  The directory to use as
    desktop folder is ~/desktop by default, but can be configured in the
    "System" config file using tkdesk(deskdir).  (CONFIG)
  - New configure flag: --enable-tkstep.  This will use the TkStep libraries
    when linking tkdesksh (libtkstep, libXpm, libtiff).  Note that the version
    of the TkStep library needs to be compatible with the version of Tk your
    compiling against.

05/15/1999

  - Added new option "Expand Dir Bookmarks" to "Options/Appearance" menu.
    If activated (default) directories in the "Bookmarks" menu will have
    cascaded submenus attached to them, if not they won't.
  - Added new option "Start Netscape" to "Options/Confirmation" menu.
    If activated (default) TkDesk will ask whether to start Netscape
    if no answer was received during execution of a dsk_netscape command.
    If deactivated, a new Netscape browser will be started only if
    ~/.netscape/lock doesn't exist.

05/03/1999

  - Editor window now are correctly centered again around the mouse pointer.
  - Pressing the right mouse button in the "File to edit:" dialog opens
    a cascading popup menu from which files can be selected.

04/30/1999

  - Further fix for itcl 3.0:  "return" in config bodies of public vars
    doesn't seem to be supported anymore.
  - Added menu entry "Same Dir..." to the editor's "File" menu to select
    a file from the cascading menu that's popped up.
  - Bug fix: Selecting an entry from the popup menu associated with the
    copy dialog's destination field gave an error.
    
03/12/1999

  - Added new option to the "Find Files" dialog: "Fail-Mask Case Sensitive"
    (and changed the option "Case Sensitive" to "String Case Sensitive).
    This new option defaults to true, but deactivated will find all names
    matching the given file mask, regardless of case.

03/04/1999

  - New config variable in "AppBar": tkdesk(appbar,dragger).  If set
    to 1 (default) the small drag/minimize button will be displayed
    at the top/left of the appbar, if set to 0 it won't.  (CONFIG)
  - New config variable in "System": tkdesk(file_selector_type).  May be
    used to choose the type of the file selector used, regardless of the
    "strict Motif" setting.  Allowed values are "tk" (Win*-like), "motif",
    and "default".  (CONFIG)

02/06/1999

  - New config variable: tkdesk(cmd,ps) set in the System config file.
    This is used by the "Job Control" window.  (CONFIG)
  - It's now possible to search backward in the built-in editor.  Added
    a new checkbutton "Backward" to its search dialog for this purpose.
  - New config var (System): tkdesk(editor,load_once).  If set to 1
    (default) files will be loaded only once, if set to 0, the same file
    may be loaded into multiple buffers (the old behavior).  (CONFIG)
  - Added new entry for this config variable into the editor's "Options"
    menu.

02/03/1999

  - New config variable: tkdesk(font,listboxes), to specify the font
    to be used by, um, listboxes.  (CONFIG)
  - The internal help viewer now picks up its fonts from $tkdesk(font,text)
    and tkdesk(font,listboxes), as defined in the System config file.
  
02/01/1999

  - Bug fix: The geometry of the "Periodic Execution" dialog wasn't
    saved properly.
  - Changed ed-tkdesk script to now wait until the editor window into
    which the file has been loaded is closed (provided the built-in
    editor is used).  The old behavior can be obtained by using the
    "-q" option with ed-tkdesk (same as for gnuclient).
  - Activated config var tkdesk(focus_width) for entries and buttons.
  - New config var ("System" config file): tkdesk(scrollbar_width).
    Can be used to configure the width of TkDesk's scrollbars.  (CONFIG)

01/17/1999

  - Added "Selection" menu to the built-in editor.  Entries allow to shift
    the selected area to the right/left, and to pipe the selection to a
    command, either replacing the selection with the result, inserting
    the result after the selection or to just view the result in a
    separate window.
  - Made bindings for accelerators/shortcuts in the editor configurable
    (to a certain extent).  By setting the new config variable
    tkdesk(editor,bindings) in the System config file to "nedit",
    the shortcuts will be changed to match those of the nedit editor
    (which happen to be used also by kedit and many Windows editors).
    The default setting ("classic") leaves the shortcuts unchanged with
    respect to previous versions.  (CONFIG)

01/06/1999

  - Added a status bar to the editor displaying current line, column
    and size of the buffer.  The status bar may be switched on (default)
    and off from the editor's Options menu.

12/29/1998

  - TkDesk now allows to change user and group of files not owned by the
    current user by running the command through dsk_exec_as_root (which
    requires knowledge of the root password).
  - When the mouse pointer is over a symbolic link in a file list window
    the link destination is displayed in the floating tip window.

12/16/1998

  - New config variable: tkdesk(conf_editor,cmd) in the "System"
    config file.  This can be used to specify the editor to use for
    editing the TkDesk config files (previously this was only possible
    using the built-in editor).  Its value defaults to the value of
    the tkdesk(editor,cmd) variable (which default to "builtin").
    (CONFIG)
  - The config files may now be reloaded either selectively from the
    "Reload" submenu of the "File/Configuration" menu, or automatically,
    provided menu entry "File/Configuration/Reload/Reload Automatically"
    is checked.  If it is, TkDesk checks every $tkdesk(update,file_lists)
    seconds to see whether any config file has been modified and then
    reloads only that one modified file.  (CONFIG)

12/15/1998

  - Rearranged the "Options" menu into a number of submenus.
  - Moved a few switch-like options from the "System" config file to
    the "Options" menu, e.g. tkdesk(ask_on_exit), tk_strictMotif etc.
    (CONFIG)
  - Now when rereading the "System" config file no longer invoke
    the tk_setPalette command.  This took a *long* time when a lot
    of widgets had already been created.

12/12/1998

  - Added new menu entry "Commands/Environment..."  This opens a new
    (non-modal) "Edit Environment" dialog box which can be used to
    modify the environment of TkDesk and processes started from it
    after the modification.

12/10/1998

  - Removed 2 memory leaks from dsk_ls.c.  There still seems to be a
    small leak in Tk's text image display code, so with "Add Icons"
    switched on you may still see TkDesk's memory consumption growing
    over time (very slowly though).
  - Removed another "leak" from appbar-load.tcl: load bars moved off
    the visible area weren't deleted properly, leading to a lot of
    unused canvas items consuming memory
    
12/03/1998

  - Enhanced the file list tool tips to display the annotation in
    addition to the file name, if one was added to the file the mouse
    pointer is over.
  - Further enhanced the tool tips for files ending with ".url" (these
    are used for storing WWW URL's): The tool tip adds the URL contained
    in that file to its display.

11/30/1998

  - Bug fix: TkDesk now correctly handles paths like /home/user2,
    where $HOME is /home/user (these were transformed to ~2 before).
  - Now display nice "screen tips" windows (a.k.a balloon help) when the
    mouse pointer is inside a file listbox, and over a file whose name
    is not complete visible.  Similiar to what Netscape and Micro$oft
    do with their multicolumn listboxes.  The tips are displayed only
    if "Options/Help Options/Balloon Help" is on.

11/24/1998

  - When tkdesksh has been built using the Tcl/Tk 8.0 libraries use
    real image annotations in the file listboxes instead of label
    widgets.  *Much* faster!
  - Changed default AppBar config file to have the mail header flasher
    to be disabled by default, as some people found it irritating and
    currently it's not obvious how to disable it.  (CONFIG)

11/18/1998

  - The background color of editor windows is no longer changed when
    read-only files are displayed, I realized that I never really liked
    that.  So, the only indication now is the title bar saying "read-only"
    and the "Save" brings up the file selection dialog.

11/15/1998

  - The "Find" dialog now updates the results listbox during the search,
    and files can be selected from there while the seach is still in progress.

11/14/1998

  - Port is almost complete!  Just need to do some thorough testing
    to track down the remaining compatibility issues, and after that
    TkDesk on Tcl/Tk 8.0 will be a reality!
  - When creating new files or directories now check whether the file
    or dir already exists.
  - Added "Open With..." to the "File" menu of browser and list windows.
  - F11 now posts the menu of the rightmost file listbox.

11/12/1998

  - Bug fix: "Save all" in the editor always saved the contents of
    the active buffer to all modified files opened in the same editor
    window.
  - Typo in config.tcl: wrote "mkdir" instead of "exec mkdir".

11/07/1998

  - Began some serious work on porting TkDesk to Tcl/Tk 8.0 and
    itcl 3.0 (and BLT 2.4).  The current plan is to make the next
    release compatible with all of Tcl/Tk 7.5, 7.6, and 8.0,
    and make a cut after that to clean up the sources and move the
    code to the new itcl syntax.


===========================================================================  

09/20/1998   Released TkDesk 1.1

09/20/1998

  - Using "." in menu definition lists makes this menu tear-off'able
    (much in the same way as "-" is used to add a separator).  (CONFIG)
  - Some minor editor/hypersearch fixes.
    

09/02/1998

  - Brought the User's Guide up to date

08/30/1998

  - Changed selection search in the editor (Meta-space) to not interpret
    the selection as a regexp, but as a straight string.  Also added the
    capability to restart at top if no more matches are found.
  - "Case sensitive" and "Regular expression" checkbuttons in the
    editor's search window may now be activated thru Ctrl-c/Ctr-r.
    
08/26/1998

  - Added a new option to dsk_find_files: "-doit".  This immediately starts
    the find process when dsk_find_files is invoked.  (CONFIG)
  - The "TkDesk" menu that appears in the editor's menu bar when config
    files are edited is now labeled "Configuration".  It also received
    2 new entries to load other config files and search through all of them.
  - Modified the dsk_edit and ed-tkdesk proc/command so a line number can be
    passed using vi/emacs notation, e.g. "dsk_edit +10 ~/.xinitrc". (CONFIG)
  - Added to keyboard navigation: Menu (available on W95 keyboard, for
    instance).  Pops up the currently selected file's popup menu that
    may also be operated with the keyboard.

08/17/1998

  - Added drag/toggle "thingie" to appbar to move the appbar around and
    minimize it.
  - Added a "Find..." entry to the "Configuration" menu.  Lets you find
    occurences of a certain string in your configuration files.
  - Fixed Y2K bug in dsk_ls.c.  Thanks to Stephane Legrand for reporting.
  - If the proc dsk_cb_callback is defined (e.g. in the "Local" config file)
    if will be called immediately before a new directory will be entered.
    The path of this directory is passed as the first argument to
    dsk_cb_callback.  (CONFIG)
  - Added "testdrive" script as suggested by Peter Funk.  Thanks Peter!

06/03/1998

  - In all dialogs displaying an entry field with a history popup attached
    to it the latest entry is put in the entry field by default.
  - Improved appbar's dialup-button:  The state of the link is now
    monitored using the ifconfig command, and a dialog is displayed
    that asks for a phone number to dial, which will be passed to the
    command specified in tkdesk(appbar,dialup,cmd_up).  Phone numbers
    entered are kept in a history list. (CONFIG)

05/24/1998

  - Made TkDesk server much safer by storing a key in /tmp/tkdesks* that
    needs to be passed by the client.
  - Added some entries provided by Dave Cinege to the Popup config file.

05/19/1998

  - TkDesk's built-in server now removes all removable /tmp/tkdesks*
    files on start-up.
  - Fixed (well, quite temporarily fixed) a problem with an editor
    window being deleted if a unreadable file was tried to be loaded
    using "File/Load".
  
05/12/1998

  - Added to keyboard navigation: PgUp, PgDown, Backspace (goes one
    level up).
  - Fixed communication between TkDesk server and tkdeskclient: the
    associated channel is now set to non-blocking, which allows
    tkdeskclient to read the server's response (i.e. the return value
    of the executed command).

05/07/1998

  - First cut at keyboard navigation: Up, down, home, end keys do what
    you would expect, a-z cycles case-insensitively through items in the
    rightmost file listbox, selecting them at the same time.

05/03/1998

  - If the editor's HyperSearch dialog is open its search function is
    automatically invoked when switching to another buffer.  Would like
    to change the regexp as well based on the type of buffer the user
    switches to, but we don't have that yet.
  - Now use Tcl's own "clock" command for displaying the current time in
    the appbar.
  - Fixed bug with large integers being used as file/directory names.

04/05/1998

  - Fixed bug where AppBar became visible and decorated by the window
    manager when the mail button was created.
  - Fixed bug "invalid variable name dsk_read_string" when dsk_read_string
    was used from ButtonBar or Commands config files.
  - Minor fixes for reloading Commands config file and reloading config
    files from the editor.
  - Changed default value of "Auto-save Layout" back to "on", as "off"
    seemed to cause even more confusion...
  - Added John Williams' popup menu for ZIP'ed files. Thanks!

===========================================================================  

02/26/1998   Pre-released TkDesk 1.0

02/24/1998

  - The AppBar's variable tkdesk(appbar,mail,notifier) may now be set to
    "bell" to let X's bell ring at arrival of new mail.
  - Changed default to add icons to file lists.  Hey, it's become faster
    since John wrote his article! ;-)
  - Fixed bug in bltBgexec.c which could lead to an "IOT trap" when being
    compiled against Tcl 7.5.
  - Reactivated "cat %s >/dev/audio" as the default sound playing command,
    but kept "Options/Use Sound" switched off by default.

02/22/1998

  - New command line option "-layout file": this loads TkDesk's window
    layout from "file" and saves it there as well.
  - TkDesk now remembers which AppBar definition was loaded last when
    restarted.  The configuration menu's entry "AppBar" now also loads
    the current appbar definition file.
  - Fixed 2 bugs in the editor's search/replace function.

02/18/1998

  - Fixed bug in misc.c where a statically sized buffer was used which
    could get too small.  Now allocate memory dynamically.
  - Now the popup menu for executables is used for all executable files
    again.  But now add the "Edit" entry for all files which "file" thinks
    are text or a script.  An alternative would be to merge both executable
    and regular popups, might add this in a later version.
  - The "Path" and "File-Mask" fields of the "Find Files" dialog now allow
    multiple paths/masks to be entered by separating them with a space.
    If paths or masks should contain spaces, they now need to be surrounded
    by quotes.

02/16/1998

  - Added a "Manual Page" entry to the "Help" menu.
  - Added "Subdirectories" and "Files" cascading submenus to the path entry
    popup menu of file browser and list windows.
  - Actions executed from a file's popup menu now execute in that file's
    path, as opposed to TkDesk's current directory.
  - Fixed bug: sometimes it was impossible to drop further icons on the
    desktop due to a missing check.
  - When clicking "Browse" in the file-selection "pre-dialog", a standard
    file selection dialog is now opened instead of a TkDesk file list window.
    Might reactive and refine this in the future though.  Tk's built-in
    file selection dialogs are used if available.

02/11/1998

  - The editors default geometry (System: tkdesk(editor,default_geometry))
    now may also be specified in the form {w}x{h}[+-]{x}[+-]{y} rather
    than just {w}x{h}.

01/29/1998

  - If directories are put into the "Bookmarks" menu they are added as
    cascading submenus.
  - Added two tkdeskclient scripts: op-tkdesk, to open the specified files
    using their default actions, and pop-tkdesk, to open the specified
    file's popup menu.
  - History menus now may also contain an "infinite" number of entries.
  - Now tkdesksh checks for the DISPLAY environment variable to be set
    before trying to initialize Tk.

01/20/1998

  - Added a "Save" button to the "mail bug report" dialog.
  - Fixed bug where files containing dollar signs or brackets couldn't
    be opened from the "Bookmarks" menu.
  - Bug fix: If nothing was entered in the text field of the "Delete"
    dialog, the directory currently displayed was deleted....  =8-O

01/12/1998

  - Put a new option into the "Options" menu: "Autoraise AppBar".  If switched
    on, the AppBar is automatically raised above all other windows if the
    mouse pointer enters it.

01/07/1998

  - Added menu entry "Execute as root..." to the "Commands" menu and to
    the file listbox menu.
  - Removed option "Exec as Superuser" because of above menu entries.
  - Put the file name into the label of the "Rename" dialog.
  - Reactivated the appbar's xemacs button coz it required some adjusting
    to work with b5.

01/04/1998

  - Fixes for building TkDesk under Solaris and IRIX.  Thanks to Chris
    Coppick and Chris Sterritt.
  - The "Info" dialog for the "." and ".." entries now displays the actual
    directory names rather than "." or "..".
  - Editor: made cut and paste operations undoable.

01/03/1998

  - Fixed bug with updating of the trash disk usage display in the
    appbar (resulted in a syntax error if usage > 1MB).  Thanks to
    everyone who pointed me to this problem.
  - Fixed bug in configure script that wouldn't pick up the directories
    supplied with --with-tcl and --with-tk options.

12/10/1997

  - Moved up default setting of tkdesk(library) in tkdesk.  The previous
    location made "test driving" impossible.
  - Incorporated John Blair's proc "dsk_exec_or_raise" which can be used
    to deiconify and raise an already running Tcl/Tk application, rather
    than launch it a second time.  It takes three arguments: the interpreter
    to check for, the command to execute if it's not already running, and
    optionally the window to raise if it is running.  See the default
    "AppBar" config file for two examples. (CONFIG)
  

===========================================================================  

12/08/1997   Released TkDesk 1.0b5

12/01/1997

  - Added new function dsk_path_view.  Does exactly the same as dsk_path_exec
    except it displays the output of the command that's been executed in a
    given path.  Syntax is "dsk_path_view path command".  (CONFIG)
  - Added an entry "Patch" to list tkdesk(fileops,popup) defined in the
    "Popups" config file.  When "Patch" is selected in the "Copy, Move, ..."
    dialog the source file will be fed into the "patch" command which
    will be executed in the directory given in the "Destination" entry.
    (CONFIG)
  - Introduced environment variable TKDESK_LIBRARY.  This may point to the
    path from where TkDesk should read its run-time library files.

11/30/1997

  - dsk_open_dir now returns the object name of the created window.
  - Added two new functions: "dsk_exec_as_root" and "dsk_view_as_root".
    Both work exactly like "dsk_exec" and "dsk_view", but use the commands
    specified in the new config variables tkdesk(cmd,su,exec) and
    tkdesk(cmd,su,view) (defined in the "System" config file) to put
    something like "su root -c" before the actual command.  This way
    selected commands may be run with superuser authority (provided you
    know the password...).  (CONFIG)
  - Added a new entry to the "Options" menu: "Exec as Superuser".  If this
    entry is checked, all commands will be run using the tkdesk(cmd,su,*)
    variables (see previous item).
  - Removed the "Local" config file from the distribution.  It's really
    supposed to be used for local extensions and for that reason TkDesk
    shouldn't depend on code that's in there, really.
  - The "Use Sound" entry in the "Options" menu is now disabled if no
    command for playing sound has been defined in the "Sounds" config
    file (this is the default).  (CONFIG)
  - Added "TkDesk" menu to the file list window menu bar.
  - Slightly rearranged the "File" menu.
  - Added an entry "Copy Names Only" to the "File" menu.  This copies
    only the names, not the paths, of all selected files to the X selection.
  - "." and ".." in paths are now "expanded" before being displayed in
    a file browser of list window.

11/24/1997

  - Extended dsk_netscape to support Netscape 4.0 ("Communicator"), based
    on code sent to the TkDesk mailing list by Paul H. Wilson.  Thanks!
    The new options are "dsk_netscape rcmd mail|news|send|edit".  See
    default "AppBar" config file for example usage.  (CONFIG)

11/23/1997

  - The file listbox that displayed the active directory when a command
    was started is now refreshed when the command exits.
  - Added a "Remove Entry" button to the "HyperSearch" dialog to remove
    an expression from the history menu.
  - The usual file and directory popup menus are now also accessible
    inside the history menus, the cascading directory and files menus,
    and the bookmarks menu.  They are accessed by pressing the left and
    right mouse button at the same time (it doesn't matter if one of the
    two buttons is pressed and held before the other one is pressed).
    (Oh, MSIE4 has a similar feature?  I didn't know... ;-))
  - When files are dropped on desk items representing executables the
    "Quick Drag'n'Drop" option is now honored.
  - "Tkdesk should now be 100% dockable/wharfable!" Thanks to Kenn Persinger.
  - The "Close" and "Refresh" buttons are now disabled in the "Disk Usage"
    window during refreshing.
  - The right mouse button pressed in the disk usage listbox now brings
    up the usual directory popup menu.
  - The "Options" menu has a new entry: "Status in List Windows".  This
    determines whether the file list windows provide a status bar similar
    to that of the multi-column file browser windows.

11/22/1997

  - The editor's "Buffers" menu is now sorted alphabetically and displays
    the full path of each buffer in braces.
  - The buffer menu and the cascading directory and files menus now have
    a "More..." entry at their end if not all entries fit into one menu.
    That entry opens another menu, and so on.  This allows for a virtually
    infinite number of entries...
  - Added some editor related entries to the "Commands" menu.
  - The "Search" and "Replace" fields of the respective editor dialog
    now also maintain a history list.
  - Added some editor related entries into the "Commands" menu (including
    a "Buffers" submenu for the built-in editor).
  - Added J. Chris Coppick's "mail header flasher" to the appbar's mail
    button.  Please look into the default "AppBar" config file to find
    out how to configure it.  (CONFIG)

11/10/1997

  - Changed the "Browse" button of the file selection dialog to open a
    standard non-modal TkDesk file list window (not for "Save as").
    Files can be dragged from here and dropped onto any open editor window,
    as usual.  Might refine this a little in the future.

11/09/1997

  - Added a new variable tkdesk(cmd,mail) to the System config file (CONFIG).
  - Added proc dsk_mail that's used for the standard file popup menu
    (entry "Mail to..."). (CONFIG)
  - Added an entry "Mail to" to the editor's File menu to mail the
    contents of the current buffer.
  - Added a "Find..." menu entry to the editor's File menu to find files
    in the directory of the current file.

11/06/1997

  - Added a history and "View Output" option to file listbox's "Execute
    here" menu entry.
  - Removed variables tkdesk(file_lb,min*) from System config file, they
    shouldn't be used anymore.  (CONFIG)
  - Added TkInfo to the default AppBar.

10/23/1997

  - Added a "Locate..." entry to the appbar "computer" icon.  Thanks to
    Graham Todd for making this available.

09/01/1997

  - Integrated John Blair's really nice RCS extension into TkDesk.
    For example usage, take a look at the "Popups" config file (look for
    jdb_rcs).  (CONFIG)
  - Also added his patch for letting the middle mouse button clicked
    on any of the permission buttons in the info window copy the respective
    setting to the corresponding button of the other permission group
    (like owner, group, world).
  - Added a Makefile popup menu to "Popups". (CONFIG)
  - Based on a proposal sent in by David Nugent, added "%a" to list of
    shortcuts.  As "%A", it expands to the names of all selected files,
    but without the path names.  (CONFIG)
  - A new variable tkdesk(at_exit) may now be set in the "System" config
    file that can be set to a script which will be evaluated right before
    shutdown of TkDesk.  (CONFIG)

08/31/1997

  - "Set Mask": multiple patterns separated by spaces may now be specified,
    and a checkbutton "Invert Mask" has also been added to display/select
    all files NOT matching any pattern.

08/28/1997

  - Fixed blatant bug where undo didn't care about which buffer was
    currently displayed in an editor window.  Now undo works on a per
    buffer basis.  The insertion cursor is now also placed properly
    after an undo.
  - Greatly improved the "About" box ;-).
  - The built-in help browser now contains a "Print" button to du just that.

08/27/1997

  - New shortcut for config files: "%X". Behaves just like "%x", but doesn't
    complain if the X selection is empty, and expands to an empty string
    then.  (CONFIG)
  - Based on a suggestion of Dave Cook, the appearance of the time display
    may now be configured in several ways: background and foreground colors,
    borderwidth, and relief.  The corresponding variables are defined
    in AppBar and are called tkdesk(appbar,time,...).  (CONFIG)
  - Following another suggestion made by Graham Todd, added a new variable
    to the System config file to define the location of the trash directory.
    Its name is tkdesk(trashdir).  (CONFIG)

08/24/1997

  - The button bar of file browser and list window may now span multiple
    lines.  Line breaks need to be inserted explicitly by a button definition
    of "\n" or "break" (similar to the "-" separator definition).  (CONFIG)

08/18/1997

  - Files that have an annotation associated with them are now underlined
    in the file listings.
  - The first 30 characters of an annotation is now included into the
    file's popup menu, right after the file name.
  - Added a popup menu for RPM's, thanks to John Williams.

08/13/1997

  - Fixed bug where drag&drop token windows could stay on screen,
    in the worst cases leading to "Bad Window" X errors.

08/11/1997

  - Fixed bug with undo not working when pasting text using the mouse
    into the editor.
  - An already opened file information window is now reused to display
    info about subsequently selected files.
  - The editor now has a "Quick Load" option that allows you to load
    files into that editor window by just selecting them in a file listbox.
  - Replaced configuration option tkdesk(editor,word_wrap) with
    tkdesk(editor,wrap).  This can be set to "word", "char", or "none".
    There's an entry in the editor's Options menu as well.  (CONFIG)
  - Some minor bug fixes.

08/10/1997

  OK, I was pretty sloppy with this ChangeLog in the past 3 months,
  so here's just a quick rundown of changes and features added since May,
  as far as I can remember...

  - TkDesk now uses GNU's autoconf for building and installation!
    This means a simple "./configure; make; make install" should compile
    and install TkDesk on most any platform withouth a hitch.
  - Extended popup menu of path entry field to give access to sibling
    directories.
  - Added cascading popup menus containing both directories and files
    to the standard directory popup menu.  These may also be added to
    the "Directories" menu by preceding the directory in the "Directories"
    config file with an "&" instead of an "*". (CONFIG)
  - Cascading directory popup menus may now also be added to the appbar,
    using entries like {&/etc}.  See "AppBar" config files for an example.
    (CONFIG)
  - The labels of desk-items are now broken into multiple lines at more
    pleasant places.  The line-width of a desk item is set in "System"
    by tkdesk(desk_items,label_width).  (CONFIG)
  - Revised the find dialog:
  
    o Only one path may be entered, as it might contain spaces.
    o Directories may be dropped over the "Path" field.
    o If files that contain a certain string are now double-clicked
      the editor now auto-scrolls to the first location of the search-string.
    o Added "Owner" and "Group" fields.
    o The proc dsk_find_files may now be called from any configuration
      file, with the following arguments:
      -path <path>, -file <file>, -string <string> or -regexp <regexp> or...
      You get the picture.  This lets you add preconfigured queries to
      your appbar, Commands menu etc.  (CONFIG)
      
  - Added a server to TkDesk.  A new stand-alone C program (tkdeskclient)
    connects to this server to execute Tcl/TkDesk commands.  All the
    xx-tkdesk scripts now use this clients as its much faster than
    the Tk "send" command.  The server can be switched on and off from
    the Options menu.
  - The appbar's new dialup-button now displays the time in seconds that
    the link has been up.
  - Added entries to the editor's TkDesk menu (appears when a configuration
    file has been loaded) to load the default version, and evaulate
    the currently selected lines.
  - Added more entries to the same menus to configure fonts, colors,
    icons, and sounds through GUI dialogs.  Hey, the first step at a
    GUI configuration!!  OK, the handling of these dialogs is not yet
    extremely intuitive, but at least consistent:  At the bottom, they
    all have three buttons: "Insert", "Select", and "Close".  "Insert"
    inserts the selected item at the current cursor position in the
    editor window, possibly replacing any previously selected text.
    "Select" copies the selected item as a string to the X selection,
    allowing for pasting the item at arbitrary places.  "Close" does
    just that.
  - Changed back to auto-loading of TkDesk's tcl library.  Split some
    of the larger files to have smaller "auto-load units".  Results in
    improved start-up time.

05/05/1997

  - Changed default configuration to not automatically save the window
    layout on exit of TkDesk.  This seems to cause too much confusion.

05/04/1997

  - The trash button in the application bar now optionally also displays
    the disk usage of the trash folder if tkdesk(appbar,trash,label) is
    set to 1 in "AppBar" (default). (CONFIG)
  - The "Print" dialog now also maintains a history.  Also added a printer
    button to the default configuration bar.
  - Added a "dial-up" special button to the default application bar.
    It displays the status of the dial-up connection by using two
    different icons.  Related to this button is a new command "dsk_dialup"
    that toggles the status of the link by executing a command to either
    bring the link up or down.  The button is controlled by variuos
    variables (tkdesk(appbar,dialup,...)) in "AppBar". (CONFIG)

05/03/1997

  - Performance improvement: Directories are now read and tagged in about
    half the time that was required before.  No kidding!
  - Made icon display ("Add Icons") much faster by creating the actual
    icons only when they become visible (after thoroughly studying the
    "text" manual page).
  - All scrollbars in the file browser and list window can now be
    displayed only when they are required.  Whether to have dynamic (default)
    or static scrollbars is controlled by the variable
    tkdesk(dynamic_scrollbars) in "System". (CONFIG)

05/01/1997

  - The "TkDesk" menu that appears when editing configuration files now
    contains additional menu entries for selecting colors, fonts, icons,
    and sounds.  Hopefully makes configuration just a little bit more
    convenient.

04/29/1997

  - Changed selection bindings in the file listboxes to follow the
    Motif and Tk standards more closely: non-contiguous selection is
    now bound to <Control-1>, while <Shift-1> does range selection.
    The old bindings may still be used by setting the variable
    tkdesk(use_old_modifiers) in "System" (CONFIG).

04/28/1997

  - The -fvwm command line switch has now become the default and is
    thus obsolete.  This switch was used to switch on icon windows for
    TkDesk.  This can be switched off now by the new -twm switch.
  - TkDesk now displays the available command line options if "-?"
    or "-help" is the only argument, and exits.

04/19/1997

  - dsk_view now also captures the standard error channel of the
    executed command.

04/05/1997

  - New config variable: If "tkdesk(after_startup)" is set to a Tcl script
    (in config file "System") it will be evaluated right after start-up
    of TkDesk has completed. (CONFIG)
  - The "TkDesk" menu that appears when a TkDesk config file is edited
    contains another new entry: "Load Default Version". This loads TkDesk's
    default version of the current config file.
  - Made configuration of fonts and colors MUCH more stable.  If a font or
    color config is invalid, a message is printed to stderr, and a fallback
    is used.  Now TkDesk should never break again because of missing fonts
    or colors.  Hopefully.

04/04/1997

  - If "Add Icons" is selected the icons take on the "selection color"
    if the corresponding file/directory is selected.
  - The popup menu of the path entries in file browser and list windows
    now gives also access to all subdirectories of each parent directory.
  - Major clean-up of fonts and color used by TkDesk.  Removed virtually
    all hard-coded font and color definitions (there are just a few left
    in the appbar "specials").  Please take a look at the new default
    "System" config file as some new variables have been introduced,
    while others have been removed or renamed.  New variables are assigned
    default values if not set in this config file, old ones are retained
    for backward compatibility. (CONFIG)
  - The "TkDesk" menu that appears when a TkDesk config file is edited
    contains a new entry: "Evaluate Selection". This evaluates any
    selected expression in the current buffer in the global scope.
    Useful for quick changes of the editor, utility commands etc.

04/03/1997

  - Fixed bug in file selector: file names starting with ~ caused it
    to choke.
  - New feature: the "Copy etc." dialog now contains a popup menu
    giving access to other file operations than copy and move. This menu
    defaults to link, symlink, diff, untar and cat.  It can be configured
    by defining the list tkdesk(fileops,popup) in "Popup" (CONFIG).
    Take a look at TkDesk's current default config for an example.
  - Fixed bug with backspace and undo.
  - Improved handling of file names containing spaces and brackets.
  - The popup menu of directories now contains a "Traverse" submenu
    with the entries "Directories" and "... and Files".  The latter
    also displays the files of each directory.
  - Directory entries in the "Directories" config file may now also be
    preceded by a "&".  This causes the files to be included in the
    recursive submenus. (CONFIG)
  - "AppBar" config file: If an entry has just one element and this
    starts either with "*" or "&", it is treated the same way as
    definitions in the "Directories" config file. E.g.: {&/usr/tmp} will
    create recursive submenus containing directories and files. (CONFIG)

03/23/1997

  - TkDesk now remembers the scrollbar position and file selection
    when file listboxes are refreshed.

03/17/1997

  - If entries of the history and bookmarks menus of the application bar
    are invoked while holding down the Shift-Key, a desk item for invoked
    entry is created at the current mouse position.
  - Control-doubleclick on desk items invokes the "Open with" dialog.
  - The default appbar now contains an entry to lower the appbar. (CONFIG)

03/13/1997

  - The editor no longer requires user input if a file is opened read-only
    or doesn't exist.  If it is read-only the title bar contains the string
    "(read only)" and the window background is the default background color.
    The buffer is still editable, but selecting "Save" invokes "Save as".

02/24/1997

  - Bug fix: Clicking on an icon in file list windows lead to an error.
  - Many other minor bug fixes.
  - You can now select different configurable application bars from the
    default appbar.  Look at the definition of the "Application Bar"
    submenu in the "comet" popup menu for an example. (CONFIG)

01/29/1997

  - The editor now uses a Win95'ish 2-phase file selector: the first phase
    is a simple history-enhanced text entry dialog, whilst the second is the
    old Motif-style file selector we all love and hate.  Yes, I might switch
    to using the Tk ones at some point.
  - The variable tkdesk(file_tags,ignore) can now be set in the "FileTags"
    config file to not display certain files (unless "Show All Files" is set).

01/27/1997

  - It is now possible to have directory-specific button bars in the file
    browser and list windows. The variable to set is tkdesk(dir_button_bar)
    in the "ButtonBar" config file. Scroll to its end for an example. (CONFIG)

01/26/1997

  - Changed code back to dynamic loading of library Tcl files.  Reduces
    start-up time especially for those starting up with the appbar only.
  - Added bindings for file-specific popup menu to third mouse button in
    editor windows.
  - Now a double-click in path entries of file list and browser windows
    is enough to X-select the complete path.
  - If nothing is selected and "Add Bookmark" is invoked, the current
    directory is now added to the Bookmarks menu.

01/21/1997

  - Bug fix: if a directory was selected and <Return> pressed, the window
    didn't change its directory.

01/14/1997

  - Fixed major memory leak in dsk_ls.c, discovered by J. Chris Coppick.

01/13/1997

  - Bug fix: If a file was selected for copy, delete, etc., and its name
    was changed in the respective dialog still the originally selected
    file was copied or deleted etc.
  - Minor bug fix with searching for an annotation.
  - Fixed bug with 12 hour time display in the appbar. Kudos to Chris Coppick.


===========================================================================  

01/06/1997   Released TkDesk 1.0b4

01/03/1997

  - Fixed bug with layout saving of toplevel windows.
  - Fixed bug with update of the appbar's recycle button.

12/21/1996

  - Added XEmacs button and extended XEmacs communication proc to the
    default configuration.  Both had been proposed by Erez Strauss
    (erez@newplaces.com). (CONFIG)
  - The default appbar's Netscape-button now contains an entry
    "X-Selection/Desk Item...".  This allows for creating desk items
    that correspond to URLs that have been X-selected (CONFIG).
  - Wrote a short QuickStart guide that's displayed when TkDesk is
    started for the first time.  It's also available via the "Help"
    menu.

12/18/1996

  - There's a new option now under the "Help" menu: "Use Netscape".
    TkDesk will use Netscape to display its online help only when this
    entry is checked.  Its setting is auto-saved.
  - There's a new configuration file: "Local".  This should be used as
    the only point to add your custom code or other fancy code you write
    to extend TkDesk.  This has been suggested by John Blair and is
    considered a Good Idea. (CONFIG)
  - The string used in the title of file browser and list windows can now
    be configured in config file "System".  See comment in the default
    System file for more info (search for "in the title"). (CONFIG)
  - Swapped the XPM icons used for file browser and list window as someone
    suggested that it makes more sense this way, and I think he's right.
  - Removed bug where files couldn't be dropped on the desktop if the
    internal help window was iconified.

12/15/1996

  - Fixed problem with appbar-only startup.
  - %A-substitution now better deals with spaces in filenames.
  - The default AppBar's action "New File" now creates a new buffer
    without any further questions.  Thanks to John Williams for this one.

12/10/1996

  - File listboxes now scroll to make newly created files or directories
    visible.
  - Added "Save all" entry to File-menu of the editor.  Does what you
    think it does.
  - TkDesk now overrides Xresource settings if tkdesk(color,basic) is set
    (by default set to #d9d9d9).  This was necessary to better cope with
    standard CDE settings which produced white on white windows.

12/08/1996

  - New boolean config variable for 12-hour display instead of the default
    24-hour display in the AppBar: tkdesk(appbar,12hour). (CONFIG)
  - TkDesk didn't use $tkdesk(path,images) to find the icons defined in
    FileTags for the file listboxes.  Now it does.
  - Added bindings to deal with "dead" keys of non-US keyboards.
  - Improved handling of directory names with spaces - again!

12/07/1996

  - Fixed bug with determining free space on NFS-mounted filesystems.
  - Display of quota is no longer supported.
  - Removed possibility of eternal loop if current directory is invalid.
  - The listbox icons (if "Add Icons" is turned on) now behave more like
    the textual items, esp. regarding drag&drop.  In fact, the only difference
    is that drag-selection is not yet possible via the listbox icons.
  - Parsing of the "uptime" command should now be more stable (hopefully).
  - "Clone Window" now creates a browser window with the same number of
    file listboxes as the one where the entry was invoked.

12/04/1996

  - Removed binding for <Shift-Button-2> and <Shift-B2-Motion> from
    the file listboxes as it got in the way with drag'n'drop bindings.
  - New checkbutton in the editor's search dialog: "Regular Expr.".
    This defaults to off as most users will never use the regular
    expression feature, and search strings may be invalid regexps
    (e.g. "*/").
  - Minor fixes.

11/28/1996

  - Made TkDesk work with Tcl 7.6/Tk 4.2.  Thanks to Peter Waltenberg
    for valuable hints.
  - The balloon help now behaves more like Netscape's does.

10/23/1996

  - The delete and copy dialogs now also can handle file specifications
    containing * and ?, for instance to delete all object files in the
    current directory.

10/21/1996

  - Minor fix in itcl/configure to not remove config.status on exit
    on some systems.
  - Auto-save files of the built-in editor (#...#) are now deleted when
    the file is saved by the user...
  - New option for the editor: "Create Backups".  If this is not checked
    no backup files will be created.  The default can be set in the
    editor section of the "System" config via the variable
    tkdesk(editor,do_backups). (CONFIG)
  - If a file is not writable by the user it is opened read-only.
    The associated buffer won't contain a cursor.
  - Editor windows now obey the "Windows At Cursor" setting.
  - New editor variable in "System" config file: tkdesk(editor,background)
    to set the background color of editor windows. (CONFIG)

10/20/1996

  - New %-shortcut contributed by John Blair: %c will be replaced with
    the filename's basename: /abc/def/ghi.j ==> %c = ghi (CONFIG)
  - Bug fix: when switching buffers in the built-in editor an additional
    newline was added.

10/06/1996

  - Improved tab handling of the built-in editor: Either "real tabs" can
    be inserted or a configurable number of spaces.
  - If "Auto Indent" is active in the editor, the Tab key binding is
    automatically invoked if the last character of a line is "{".


===========================================================================  

09/26/1996   Released TkDesk 1.0b3

09/25/1996

  - The "Execute..." entry of the appbar's comet button's popup menu is
    now able to also handle directories and files.
  - Added a new "special" button to the AppBar: "special:trash". This button's
    image corresponds to the fill state of the trash can.  The images to be
    used can be configured in the AppBar via tkdesk(appbar,trash,empty) and
    (appbar,trash,full). (CONFIG)
  - Added an entry "Bookmark" to the popup menu of each file/directory
    to add that item to the bookmark list.

09/24/1996

  - Converted all VOC sound files to AU sound files as these can usually
    be directly sent to /dev/audio (via "cat %s >/dev/audio"). The drawback
    of this move is the lower quality.  You can pick up higher quality VOC
    and WAV files from my TkDesk Web page.
  - Changed default sound command to cat %s >/dev/audio.
  - Changed the Makefile: all *LIBDIR settings now start with -L to allow
    for empty settings if the libraries are in default search paths.
  - The "Execute..." entry of the appbar's comet button's popup menu is
    now able to also handle directories and files.

09/23/1996

  - Picked up another suggestion from the list: as an alternative to
    dsk_exec one can now use dsk_path_exec to have a command executed
    in a certain path, for instance the home directory.  Apart from that,
    dsk_path_exec is identical to dsk_exec.  The syntax is:
    dsk_path_exec path cmd. (CONFIG)
  - The menubutton above every file list symbolizing the displayed directory
    can now also be dragged around, and dropped onto the root window.

09/22/1996

  - Files can now be inserted into a buffer of the built-in editor.
  - File names copied to the X selection (via "Copy to X Selection" or
    the "X" button of the button bar) are now separated by blanks instead
    of newlines to allow for shell command line usage.
  - Due to popular demand I changed the handling of executable files as
    follows:  If an ex. file has an extension, e.g. ".c", it is handled like
    a regular, non-executable file.  If the file does not have an extension,
    it is handled as usual: as an executable file.  If you have executables
    with extensions and don't want them to be handled as regular files, you
    can add an appropriate entry to the tkdesk(popup,regulars) list.
  - Major CONFIG change: Everything regarding the appearance of directories
    and files is now contained in the config file FileTags.  Settings in
    the System config file like "set tkdesk(color,directories)" will be
    overwritten from the settings in this file.  In addition to the list
    tkdesk(file_tags) two more lists have been defined for directories
    and executables: tkdesk(file_tags,directories) and tkdesk(file_tags,
    executables).  The format of each element of any of these lists is:
    {{patterns} {color} {font} {list_icon} {desk_icon}}. The latter
    three subelements are optional.
  - The position of the vertical scrollbar of file list windows is now
    remembered for each visited directory and window.
    
09/21/1996

  - TkDesk no longer uses "exec date" to get the current time, but has
    now its own C-function for this.  This should remove the "fork:
    resource unavailable" messages on some platforms after TkDesk had
    run for a few days.
  - If there is a running Netscape, TkDesk will use this one to display
    the User's Guide etc.  This has been suggested in the mailing list.
    The AppBar config file had to be slightly modified: all "dsk_cbhelp"
    lines needed to be changed. (CONFIG)
  - The default AppBar now contains a new entry under the "Edit" menu:
    "Buffers".  This is a submenu listing all buffers of the built-in
    editor. (CONFIG)

09/18/1996

  - Programs started from TkDesk now inherit the standard output channel
    from TkDesk. Previously everything printed to stdout was simply discarded.
  - The "Exit" message printed in file browsers' message bar now contains
    the program's exit code, like "Exit (0): ...".

09/16/1996

  - New binding in file listboxes: <Control-Shift-1> selects all files
    having the same extension as the one that is clicked on.  This provides
    a handy way to quickly select all files of a certain type.
  - The default image type is now XPM and no longer XBM.  This allows for
    using the Motif/CDE pixmaps directly.
  - NEW MAJOR FEATURE:  Files may now be dragged off any file list
    (including the one of the "Find Files" dialog) and be dropped
    directly onto the root window a.k.a. desktop to create icons!
    These desk items (as I prefer to call them to avoid confusion with
    minimized windows) behave exactly like file list items, i.e.  they
    provide the usual popup menus (with an entry "Remove Item" added),
    drag&drop facilities etc.

09/10/1996

  - Icons for file browser/list windows etc. can now be larger than 32x32.
  - Improved behavior when renaming/copying/moving files the user does
    not own.
  - New option "Ask On Delete". This determines if the "Delete" dialog
    appears even if "Really Delete" is not selected.

09/08/1996

  - Built-in editor:
     o A backup copy is created when a file is saved (filename~).
     o Every 500 inputs/deletes an auto-save file is created (#filename#).
     o At last: Implemented a virtually unlimited UNDO functionality!
       This is certainly not finished yet, however, it should be mature
       enough to be useful.
     o New option: word wrap. Default can be set in the System config
       file by setting the variable tkdesk(editor,word_wrap). (CONFIG)
  - The "Open with" dialog now uses the same dialog as "Execute".
  - The "Execute" dialog now contains a checkbutton "View Output" to
    view the command's output *after* it's finished.

08/29/1996

  - TkDesk now checks if files may be deleted before the shell complains.
  - Second go at displaying FS status: The available space on a file
    system is now obtained from the "df" command.  If the user has a
    quota on that FS (and quota is installed), the quota is printed
    in the status bar as well.
  - "Control-a" in the editor now selects the whole buffer.
  - Changed function of mark 0 in the editor: "Alt/Meta-0" now always
    jumps back after jumping to another mark.

08/26/1996

  - The "HyperSearch" dialog of the built-in editor now has a "Sort"
    checkbutton to optionally sort the "hyperlist".
  - New feature of the built-in editor: marks.  10 marks can be set
    via Control-<number> and jumped to via Alt/Meta-<number>.  The marks
    work across buffer and window boundaries.

08/25/1996

  - Improved balloon help. The font can now be configured in the "System"
    config file by setting tkdesk(font,balloon). (CONFIG)
  - Added some additional bindings to the appbar:
	  Alt/Meta-ButtonPress-1: Move the Appbar
	  Alt/Meta-ButtonPress-2: Popup-menu configuration files
	  Alt/Meta-ButtonPress-3: Popup-menu appbar functions
    These are automagically added to all appbar buttons.

08/24/1996

  - Changed default size of appbar buttons to 48x48. Also use much
    nicer NeXT-like buttons now, that I found in the AfterStep distribution.
  - Due to popular demand, the file lists of file browser windows now
    contain "." and ".." for shortening the currently displayed path.
  - The default button bar (underneath the menu bars) now contains
    webbrowser-like back and forward buttons to step through the
    directory history. (CONFIG)
  - Fixed the "Mail Bug Report To Author" facility!  Pretty embarrassing
    that I had broken it in 1.0b2...

08/20/1996

  - File selection dialog now also follows the value of the
    "Dialogs At Pointer" option.
  - The entries of the built-in editor's buffer menu now consist of
    parent directory and file name.
  - ~/.tkdesk/_version is now created at first time usage.

08/05/1996

  - TkDesk no longer relies on tkEntryPaste/tkTextPaste if $tk_version > 4.0.
  - Removed tkMenuInvoke error.
  - Fixed division by zero bug with the appbar's load display.
  

===========================================================================  

07/29/1996   Released TkDesk 1.0b2

07/22/1996

  - TkDesk now uses its own version of tk_dialog.  This one places the
    window near the mouse pointer if "Dialogs At Pointer" is set, and
    removes the *most dangerous* binding for <Return> introduced in Tk 4.1,
    as it doesn't follow the focus.
  - Added a printer icon to the default appbar where files may be dropped,
    the printer can be selected and its status observed (CONFIG).

07/21/1996

  - <Control-1> now has the same effect if option "Single Click" is set
    and a directory is clicked on as <Control-Double-1> with the option
    unset.
  - Improved handling of broken symbolic links (they can now be d&d'ed).
  - Default sort type can now be set via the "Options" menu.
  - Entries of the "Bookmarks" menu are now always sorted alphabetically.
  - Tkdesk now checks for read-only filesystems before most file operations.
  - The type char of sockets (=) wasn't stripped.
  - The "Delete Files" dialog now appears always, even if "Really Delete"
    is not set.  The old behaviour irritated a few people.

07/17/1996

  - Files can now also by copy-dragged from the "Find Files" dialog box
    if "Quick Drag'n'Drop" is set.
  - The menu of the file listboxes has a new entry: "Command...". This can
    be used to execute a shell command in the listbox's directory in the
    background. All the usual %-shortcuts may be used. Thanks to Kevin
    Rodgers for the inspiration.
  - The "Make tar.gz" entry of the directories popup menu now creates an
    archive relative to the directory's path. Thanks to Michael Beach.

07/15/1996

  - Further improvements concerning the handling files of with special
    Tcl-characters (ie: "[]{}) and spaces in their names.
  - Info bar is now updated when selecting files with <Shift-1>.
  - Some minor fixes.

07/11/1996

  - Fixed bug with history menus just having the "dummy" entry.
  - The "~" in dsk_exec commands is now always replaced by the user's
    home directory.
  - History menus of the appbar are now also "tearoffable".
  - Put the "Commands" history menu back into the default appbar (CONFIG).
  - Another appbar special (file AppBar): a notifier of new mail. Works
    similar to xbiff, just better: it has got three states, sound
    support, and provides the usual appbar functionality.
  - The dsk_view proc now first checks if the command is executable
    (i.e. the first element of the command).

07/10/1996

  - Removed "Append type char" from file listboxes of file list windows.
  - New appbar concept: In addition to simple buttons complex "special buttons"
    can be constructed and handled just like simple buttons (currently only
    from within the TkDesk code). I.e. they provide popup menus and drag'n'drop
    functionality just like the other buttons.  These special buttons are
    recognised by TkDesk by a button image-name of the form special:*.
  - Changed the appbar's date display into a special button with the name
    special:date. The special word "date" in the config file AppBar is still
    supported for backward compatibility. (CONFIG)
  - New appbar special (config file AppBar): an xload-like display
    (special:load). (CONFIG)
  - If the public proc dsk_edit is called without arguments a file selection
    dialog appears now.
  - Some minor fixes.

07/09/1996

  - The current X selection can now be accessed from the config files by %x
    (CONFIG).
  - The "Manual Page" entry of TkDesk's default appbar now understands lines
    like "col(1) socket(2) malloc(3)" (CONFIG).
  - Incorporated netscape-remote 1.1, written by Ken Hornstein, into TkDesk.
    Thanks a lot for that neat stuff Ken!
  - New public command: dsk_netscape "file|url" <file|url> <options>.
    Options may be "window" and/or "raise".  This command makes use of Ken's
    netscape-remote extension, and transparently starts Netscape if it's
    not running on the user's display yet.  See config files AppBar and
    Popups for example use. (CONFIG)
  - Changed the appbar's earth button into a "Netscape-button".  The X-
    selection can now be used to instruct Netscape to visit certain URLs.
    Files can be dropped on this button to let (maybe a running) Netscape
    display them.
  - The built-in editor has a new option: "Send to Netscape". If this option
    is set, the edited file is automagically reloaded by Netscape each time
    the file is saved, e.g. by pressing "Alt/Meta-s". 

07/08/1996

  - Appbar: If the right mouse button is pressed and released over the
    the same button of the appbar the corresponding menu remains posted.
  - File info: The rightmost button of the mode line now cycles through
    "-,x,t,T".
  - Improved behaviour when directory of trashcan window is changed.
  - Selected entries "." and ".." in file list windows are ignored now.
  - Fixed bug: built-in editor always added a newline when saving files. 

07/07/1996

  - Improved handling of focus: the models "focus follows mouse" and
    "click to focus" are now better supported. The default model can be
    set by the boolean config variable tkdesk(focus_follows_mouse) in
    System. (CONFIG)
  - Fixed bug with listboxes going mad when selecting files by dragging
    the mouse outside the window and releasing the mouse button there.

07/02/1996

  - Fixed the file type selection of the "Find Files" dialog.
  - Added config variable tkdesk(num_lbs) in config file "System"
    for setting the default number of listboxes of file browser
    windows (CONFIG).

06/23/1996

  - Removed 2 further possibilities for X "BadMatch" errors.
  - The "previous version" dialog box appeared even if TkDesk had not
    been used before.
  - Icons in file lists now support some mouse operations (single click,
    double click, right click).
  - Fixed editor bug with searching expressions starting with "-".
  - Auto-mounting didn't work because TkDesk switched working dir to
    directory that is to be opened before executing the on_open command.

06/18/1996

  - Fixed bug with icon display (first item was assigned 2 icons)
  - Added default config for tkdesk(editor,default_geometry)


===========================================================================  

05/20/1996   Released TkDesk 1.0b1

05/20/1996

  - Added new command line option "-default" to read default configuration
    rather then the user's one in ~/.tkdesk.
  - Updated the TkDesk User's Guide. Created a PostScript version of the
    guide which can be found in the "doc" subdirectory of the untar'ed
    TkDesk package.

05/19/1996

  - Added a "Help" button to the default application bar. Executables can
    be dropped here to display their manual page, if they've got one.
    The popup menu also offers remote access to TkMan. I could only test
    this with TkMan 1.7b3, but hopefully it also works with newer version.
  - Removed the "Preferences" config file. Options are now automatically
    saved. The settings from your old "Preferences" are read once
    when 1.0b1 is first started. (CONFIG)
  - Added a "Don't execute" checkbutton to the "Periodic Execution" dialog
    to temporarily pause the periodic execution.
  - The built-in editor now handles regular expressions containing "^"
    and "$" correctly.
  - Added a new option "Always In Browser". This affects the "In Browser"
    checkbutton of the "Open Directory" dialog, plus opening a directory
    with Control-Doubleclick.
  - Added an "Auto Save" menu to the "TkDesk" menu. Determines which parts
    of TkDesk will be automatically saved periodically and when quitting
    TkDesk.
  - "Rename File" now checks for existing file first.
  - Improved reseting of vertical scrollbars after refreshing.
  - Icons used for file browser/list windows and the help window can now
    be configured in the "System" config file. (CONFIG)
  - Implemented a new function/proc for configuration scripts:
    dsk_read_string label script: Executes script when entered string is
    not empty. "label" will be displayed in the dialog. (CONFIG)

05/17/1996

  - Files can now also be dropped on the menubutton right above each
    file listbox. Useful when directory contains lots of subdirectories.
  - Added an "Empty Trash" command to the "Directories" menu.
  - Made TkDesk more environmentally friendly by adding a "recycle" button
    to the default application bar. Files can also be dropped here, so
    you could as well delete the "Trash" icon. Or this button.
  - If "Quick Drag'n'Drop" is selected, files and directories are no longer
    tried to be copied on themselves.
  - When dragging files the mouse has to be moved at least 6 pixels in any
    direction to invoke the respective copy/move/etc. action.
  - Files can now be searched for a set of strings, regular expressions, or
    extended regular expressions.
  - The default window geometry of the built-in editor can now be configured
    by setting the variable tkdesk(editor,default_geometry) in the config
    file "System". (CONFIG)
  - TkDesk now always uses the built-in editor for editing the configuration
    files because of the easier reloading of the edited config files (F5/F6).
  - Built-in editor: Text deleted with Ctrl-k can now be yanked back by the
    usual Ctrl-y.
  - TkDesk is now much more stable when run by an "ordinary" user (ie. not
    superuser).
  - The editor can now also be opened if no files are selected, from the
    button bar of the file browser windows.

05/16/1996

  - Fixed highlighting of selections in file lists for b/w displays.
  - The menus of the application bar can now be browsed like normal
    menu bars (while pressing the right mouse button).
  - If the only file droppped over a file list is a tar file (compressed
    or uncompressed) the "Copy"-dialog has an additional button "Untar"
    to untar the file in the destination directory (hope you like this,
    Avery :-). Obviously, this does not work if the option "Quick D&D"
    has been selected.
  - If you enabled sound for TkDesk (via the config file "Sounds") the
    "Options" menu has a new entry "Use Sound".
  - New option "Single Click (Dirs)" allows to open directories with a
    single mouse click.
  - New option "Dialogs At Pointer" to always open dialogs (and new file
    windows) over the mouse pointer.
  - Changed popup menu for directories to contain entries for opening a
    new file list or file browser window.
  - The most annoying, nasty, wicked and ugly bug "error in config for
    public variable dsk_FileViewer::dir" should now be fixed! But keep
    fingers crossed...
  - The "AppBar" config file now contains an option to let the appbar be
    managed by the window manager, plus a DETAILED description of how to
    move the appbar. (CONFIG)
  - Made the file listboxes more Motif-conform and consistent with the
    rest of TkDesk by adding a small corner frame.
  - Search paths for image files (for app and button bars) and sound files
    can now be configured. Multiple search paths are possible. See defs
    of tkdesk(path,images) and tkdesk(path,sounds) in config file "System".
    (CONFIG)
  - Added 5 small sound files to the standard distribution.
  - The recursive creation of the cascaded directory menus is now
    abandoned if the resultant menu would no longer fit on screen.

05/14/1996

  - The fonts used in the "time- and date-button" of the appbar can now
    be configured. See default config file "AppBar". (CONFIG)
  - All file browser and list windows can now be closed, provided the
    application bar has not been removed. This way it is possible to reduce
    TkDesk to just the app bar or even the trash icon.
  - x-permission buttons (File-Info dialog) now toggle through "-, x, s, S"
  - Scripts in the tkdesk(action_on_open) can now also use the usual "%"-
    abbreviations (described in "Directories" config file). (CONFIG)
  - Changed the "Configuration" submenu of the first button of the appbar
    to contain directly the names of the config files. It is much easier to
    reload them from the editor window anyway.
  - Bug fix: Path "/" is now correctly handled in the "Find files" dialog.
  - Changed method of rereading all config files.
  - Files/Dirs may now contain "%"'. Just had to change a sprintf to a
    strcpy......
  - Removed disabled "Undo" entry from the editors "Edit" menu until
    I find time (and motivation...) to implement it.
  - Some minor bug and glitch fixes.

05/12/1996

  - Added an "Up" button to the default button bars.
  - "Sort by Size/Date/Extension" now leaves the "." and ".." entries
    at the top of the file lists.
  - Removed the dsk_statfs command and corresponding configuration options
    from the Makefile. Should improve portability. Will use the "df" utility
    for same/extended functionality.
  - Misc. Makefile changes: no more GNUmakefile, config. opts. now saved
    to a file which is read by BLT's and itcl's configure scripts, new
    macro for echo (ECHO) to deal with Solaris's echo.
  - Fixed "Set Mask" bug.
  - Cleaned up C-sources (removed stray backslashes, changed initialisation).

05/11/1996

  - Bug fix: An error occured when pasting text into an editor window
    with the middle mouse button if TkDesk was built with Tk 4.0.
  - Bug fix: Directories couldn't be packed ("Make tar.gz") because
    internal file name handling always surrounded file names with braces.
  - The home directory is now abbreviated with ~ in the path entries of
    file browser and file list windows as well.

05/03/1996

  - Rewrote Tk's tkMbMotion so that another menu is only posted if the
    corresponding menubutton is packed in the same widget as the active one.
    (I really think this should be standard Tk behaviour.)

05/02/1996

  - If the command entered in the "Execute" dialog box starts with dsk_,
    it is interpreted as a Tcl expression. This allows for instance
    to invoke the TkDesk editor on a file with "dsk_edit file".
  - Minor fixes.

04/29/1996

  - Button bars of browser and list windows are now more compact.
  - Updated menu "Others/Help" of file list windows.


=============================================================================  

04/28/1996   Released TkDesk 1.0a2

04/27/1996

  - New command line option: -startdir <dir>. If this option is given,
    the first file browser will open with directory <dir>.
  - A directory can now also be opened into a browser window (via the
    "Open Directory" dialog).
  - dsk_view now also prints the "Launched" and "Exit" status messages
    as dsk_exec does.
  - File list windows now may also have a button bar underneath the menu.
    This is also configured in the config file ButtonBar by setting the
    variable tkdesk(small_button_bar). The syntax is exactly the same as
    for tkdesk(button_bar). (CONFIG)
  - Created directories and files are now automatically selected.
  - Removed the "indicator" from the menubutton just above the file lists,
    for various reasons. The raised relief should be indicator enough.
  - There is now a central proc for printing files (dsk_print). It displays
    a dialog box where the command which is to be used for printing can be
    entered. The default can be set by setting the variable tkdesk(cmd,print)
    in the "System" configuration file. (CONFIG)
  - The "File" menu has a new entry: "Print..."
  - Now *all* of TkDesk's configuration files can be reloaded. But note
    that some changes to the "System" file only become visible when TkDesk
    is restarted.
  - The built-in editor has a new menu "TkDesk" which appears when editing
    one of the configuration files. Such files can then be saved and reloaded
    by pressing F5 and saved, reloaded and closed by pressing F6.
    Maybe TkDesk should always use the built-in editor for this reason
    when editing configs? What do you think?

04/26/1996

  - Updated the BLT parts of TkDesk to 2.1. TkDesk now works with Tcl 7.5
    and Tk 4.1 too.

04/22/1996

  - Modified editor buffers can now be saved when being closed.
  - Added a new command line option: -iconic. This will iconify all
    windows (ie browser and list windows) when TkDesk is started.
  - New command line option "-fvwm" to force fvwm support (esp.
    icon windows/pixmaps instead bitmaps).
  - Revamped installation. Now support multiple users.

04/21/1996

  - TkDesk now prints a message in all browsers' status bars when a
    dsk_exec'ed program exits. Handy when unpacking tar files, for instance.
    Also prints a message when a command is dsk_exed'ed. Using the "Sounds"
    configuration file different sounds can be associated with these events
    (dsk_exec_launch and dsk_exec_exit). (CONFIG)
  - Title bar of "Background" windows is now enumerated to tell how many
    copy, disk usage etc. jobs are currently running.
  - FileTags config file can now be reloaded from within TkDesk.
  - FileTags entries now overrule standard directory/executable tags.
  - Better date display if appbar is laid out horizontally.
  - Browser windows may now contain only one listbox
    (menu "Options/Number of Listboxes").
  - Number of listboxes in browser windows is now also saved to _layout,
    and restored next time tkdesk is started.
  - Directories have a new entry in their popup menu: "Traverse". This is
    a cascaded menu that lets you select a directory from the tree starting
    at the selected directory. Pressing Control at the same time (when
    releasing the right mouse button) opens a new file list window with the
    selected directory. Quite nice.
  - Much improved (but not perfect!) handling of files with special characters
    in their names, such as spaces,",[,{.

04/20/1996

  - Created a reduced tclInt.h for itcl which is compatible with Tcl 7.4 and
    7.5 and is automatically included. Should help with config problems.
  - File modification times are now correctly displayed for files older
    than a year.
  - Removed "Commands" from Appbar, didn't work right and was pretty
    useless anyway.

04/19/1996

  - Modified TkDesk's pixmaps to use only 32 colours - thanks to the
    excellent "pixy" program made available by Romano Giannetti
    (romano@iet.unipi.it) and Martin Kraemer (Martin.Kraemer@Mch.SNI.De).

04/15/1996

  - Revamped bug-mailing facility pf TkDesk. Now users can add their comments.
  - Some changes in the Makefile regarding libraries to link to TkDesk.
  - Improved quick drag'n'drop mode.
  - Files now may end with "+" etc. ...

04/13/1996

  - Removed a (self-discovered :-)) bug that could appear when action
    definitions e.g. in the Popups config file spanned multiple lines.
  - tkAppInit.c no longer references the variable tcl_RcFileName to avoid
    incompatibility with Tcl 7.5. Wasn't used anyway.

04/11/1996

  - "Directories" configuration file defines two new lists: (CONFIG)
	o tkdesk(strip_parents): When the path of a file browser window is
	  changed to a directory listed here, or below it, the parent dirs
	  of the listed dir will not be displayed (as is by default the
	  behavior for a user's home directory). Can speed up display, esp.
	  when working inside an AFS tree.
	o tkdesk(action_on_open): An action can now be invoked whenever
          one of the directories listed here is opened or refreshed. The
	  action is a Tcl script defined in the same list. This allows for
          auto-mounting of removable media, to name just one example.
  - Yes, TkDesk now can transparently access removable media, such as floppy
    disks and cdroms, made possible by the tkdesk(action_on_open) list
    just mentioned.

04/08/1996

  - Errors when trying to "open" executable files are now caught.
  - Removed annoying "tkPriv(oldGrab): no such variable" bug that
    occurred with unpatched versions of Tk 4.0. Made tkpatches.tcl
    compatible with these.
  - Added a "tkwait visibility" to avoid "BadMatch" error when placing
    window interactively (hopefully).
  - Fixed bug which set tkdesk(active_viewer) to a not existent browser.
  - Some more bug fixes.
	
04/07/1996

  - "make install" now creates directory $(LIBDIR)/.trash, chmod's all
    files under $(LIBDIR) as readable for all, and all binaries as executable
    by all


=============================================================================  
	
03/31/1996  Released TkDesk 1.0a1

