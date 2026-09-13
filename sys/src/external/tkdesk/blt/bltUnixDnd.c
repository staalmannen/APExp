/*
 *  bltUnixDnd.c --
 *
 *	This module implements a drag-and-drop manager for the BLT
 *	Toolkit.  Allows widgets to be registered as drag&drop sources
 *	and targets for handling "drag-and-drop" operations between
 *	Tcl/Tk applications.
 *
 * Copyright 1993-1998 Lucent Technologies, Inc.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and warranty
 * disclaimer appear in supporting documentation, and that the names
 * of Lucent Technologies any of their entities not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * Lucent Technologies disclaims all warranties with regard to this
 * software, including all implied warranties of merchantability and
 * fitness.  In no event shall Lucent Technologies be liable for any
 * special, indirect or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether in
 * an action of contract, negligence or other tortuous action, arising
 * out of or in connection with the use or performance of this
 * software.
 *
 *	The "drag&drop" command was created by Michael J. McLennan.
 */
#include "bltInt.h"

#ifndef NO_DRAGDROP

#include "bltChain.h"


#include <X11/Xatom.h>
#include <X11/Xproto.h>

#define DND_THREAD_KEY	"BLT Dnd Data"

#define PACK(lo,hi)	(((hi) << 16) | ((lo) & 0x0000FFFF))
#define UNPACK(x,lo,hi) ((lo) = (x & 0x0000FFFF), (hi) = (x >> 16))

#define WATCH_ENTER	(1<<0)
#define WATCH_LEAVE	(1<<1)
#define WATCH_MOTION	(1<<2)
#define WATCH_MASK	(WATCH_ENTER | WATCH_LEAVE | WATCH_MOTION)

#define DRAG_ENTER	0x1001
#define DRAG_LEAVE	0x1002
#define DRAG_MOTION	0x1003
#define DROP_REQUEST	0x1004
#define DRAG_RESPONSE	0x1005
#define DROP_RESPONSE	0x1006
#define DROP_START	0x1007

#define MESG_INDEX_WINDOW	1	/* Index of window id in message. */
#define MESG_INDEX_TIMESTAMP	2	/* Index of transaction timestamp. */
#define MESG_INDEX_POINT	3	/* Index of root X-Y coordinate. */
#define MESG_INDEX_STATE	4	/* Index of button #/key state. */
#define MESG_INDEX_RESP		3	/* Index of mouse event response. */
#define MESG_INDEX_FORMAT	3	/* Index of button #/key state. */
#define MESG_INDEX_PROPERTY	4	/* Index of button #/key state. */

#define DRAG_CAN_DROP		0
#define DRAG_CANT_DROP		1	
#define DRAG_CANCEL		-1

#define ACTION_CANCEL		-1
#define ACTION_COPY		0
#define ACTION_LINK		1
#define ACTION_MOVE		2

#define DROP_FAIL		-1
#define DROP_OK			0
#define DROP_CONTINUE		1
#define DROP_TIMEOUT		2


#define PROP_WATCH_FLAGS	0
#define PROP_DATA_FORMATS	1
#define PROP_MAX_SIZE		1000	/* Maximum size of property. */

#define PROTO_BLT		0
#define PROTO_XDND		1

#define TOKEN_OFFSET		0
#define TOKEN_REDRAW		(1<<0)

#define TOKEN_STATUS_REJECT	-1
#define TOKEN_STATUS_NORMAL	0
#define TOKEN_STATUS_ACTIVE	1

/*
 *	Each widget representing a drag & drop target is tagged with 
 *	a "BltDndTarget" property in XA_STRING format.  This property 
 *	identifies the window as a target.  It's formated as a Tcl list 
 *	and contains the following information:
 *
 *	    "flags DATA_TYPE DATA_TYPE ..."
 *
 *	    "INTERP_NAME TARGET_NAME WINDOW_ID DATA_TYPE DATA_TYPE ..."
 *
 *	  INTERP_NAME	Name of the target application's interpreter.
 *	  TARGET_NAME	Path name of widget registered as the drop target.  
 *	  WINDOW_ID	Window Id of the target's communication window. 
 *			Used to forward Enter/Leave/Motion event information 
 *			to the target.
 *	  DATA_TYPE	One or more "types" handled by the target.
 *
 *	When the user invokes the "drag" operation, the window hierarchy
 *	is progressively examined.  Window information is cached during
 *	the operation, to minimize X server traffic. Windows carrying a
 *	"BltDndTarget" property are identified.  When the token is dropped 
 *	over a valid site, the drop information is sent to the application 
 *	via the usual "send" command.  If communication fails, the drag&drop 
 *	facility automatically posts a rejection symbol on the token window.  
 */
/* 
 * Drop Protocol:
 *
 *		Source				Target
 *              ------                          ------
 *   ButtonRelease-? event.
 *   Invokes blt::dnd drop
 *		   +
 *   Send "drop" message to target (via 
 *   ClientMessage). Contains X-Y, key/ --> Gets "drop" message. 
 *   button state, source window XID.       Invokes LeaveCmd proc.
 *					    Gets property from source of ordered
 *					    matching formats.  
 *					            +
 *					    Invokes DropCmd proc. Arguments
 *					    are X-Y coordinate, key/button 
 *					    state, transaction timestamp, 
 *					    list of matching formats.  
 *						    +
 *					    Target selects format and invokes
 *					    blt::dnd pull to transfer the data
 *					    in the selected format.
 *						    +
 *					    Sends "drop start" message to 
 *					    source.  Contains selected format
 *   Gets "drop start" message.		<-- (as atom), ?action?, target window
 *   Invokes data handler for the     	    ID, transaction timestamp. 
 *   selected format.				    +
 *                +			    Waits for property to change on
 *   Places first packet of data in         its window.  Time out set for
 *   property on target window.         --> no response.
 *                +                                 +
 *   Waits for response property            After each packet, sets zero-length
 *   change. Time out set for no resp.  <-- property on source window.
 *   If non-zero length packet, error               +
 *   occurred, packet is error message.     Sends "drop finished" message.
 *					    Contains transaction timestamp, 
 *   Gets "drop finished" message.      <-- status, ?action?.
 *   Invokes FinishCmd proc. 
 */

/* Configuration Parameters */
#define DEF_TARGET_ENTER_COMMAND	(char *)NULL
#define DEF_TARGET_MOTION_COMMAND	(char *)NULL
#define DEF_TARGET_LEAVE_COMMAND	(char *)NULL

#define DEF_DND_BUTTON_BG_COLOR		RGB_YELLOW
#define DEF_DND_BUTTON_BG_MONO		STD_MONO_NORMAL_BG
#define DEF_DND_BUTTON_NUMBER		"3"
#define DEF_DND_PACKAGE_COMMAND		(char *)NULL
#define DEF_DND_SELF_TARGET		"no"
#define DEF_DND_SEND			(char *)NULL
#define DEF_DND_IS_TARGET		"no"
#define DEF_DND_IS_SOURCE		"no"
#define DEF_DND_SITE_COMMAND		(char *)NULL
#define DEF_TOKEN_ACTIVE_BG_COLOR	STD_COLOR_ACTIVE_BG
#define DEF_TOKEN_ACTIVE_BG_MONO	STD_MONO_ACTIVE_BG
#define DEF_TOKEN_ACTIVE_BORDERWIDTH	"3"
#define DEF_TOKEN_ACTIVE_RELIEF		"sunken"
#define DEF_TOKEN_ANCHOR		"se"
#define DEF_TOKEN_BG_COLOR		STD_COLOR_NORMAL_BG
#define DEF_TOKEN_BG_MONO		STD_MONO_NORMAL_BG
#define DEF_TOKEN_BORDERWIDTH		"3"
#define DEF_TOKEN_CURSOR		"top_left_arrow"
#define DEF_TOKEN_REJECT_BG_COLOR	STD_COLOR_NORMAL_BG
#define DEF_TOKEN_REJECT_BG_MONO	RGB_WHITE
#define DEF_TOKEN_REJECT_FG_COLOR	RGB_RED
#define DEF_TOKEN_REJECT_FG_MONO	RGB_BLACK
#define DEF_TOKEN_REJECT_STIPPLE_COLOR	(char *)NULL
#define DEF_TOKEN_REJECT_STIPPLE_MONO	RGB_GREY50
#define DEF_TOKEN_RELIEF		"raised"

static int StringToCursors _ANSI_ARGS_((ClientData clientData, 
	Tcl_Interp *interp, Tk_Window tkwin, char *string, char *widgRec, 
	int offset));
static char *CursorsToString _ANSI_ARGS_((ClientData clientData, Tk_Window tkwin,
	char *widgRec, int offset, Tcl_FreeProc **freeProcPtr));

Tk_CustomOption cursorsOption =
{
    StringToCursors, CursorsToString, (ClientData)0
};

typedef struct ThreadData {
    Tcl_HashTable dndTable;	/* Hash table of dnd structures keyed by 
				 * the address of the reference Tk window */
    Tk_Window mainWindow;
    Display *display;
    Atom mesgAtom;		/* Atom signifying a drag-and-drop message. */
    Atom formatsAtom;		/* Source formats property atom.  */
    Atom targetAtom;		/* Target property atom. */
    Atom commAtom;		/* Communication property atom. */

#ifdef HAVE_XDND
    Tcl_HashTable handlerTable; /* Table of toplevel windows with XdndAware 
				 * properties attached to them. */
    Atom XdndActionListAtom;
    Atom XdndAwareAtom;
    Atom XdndEnterAtom;
    Atom XdndFinishedAtom;
    Atom XdndLeaveAtom;
    Atom XdndPositionAtom;
    Atom XdndSelectionAtom;
    Atom XdndStatusAtom;
    Atom XdndTypeListAtom;

    Atom XdndActionCopyAtom;
    Atom XdndActionMoveAtom;
    Atom XdndActionLinkAtom;
    Atom XdndActionAskAtom;
    Atom XdndActionPrivateAtom;
    Atom XdndActionDescriptionAtom;
#endif
} ThreadData;


typedef struct DropPending {
    Tcl_DString dString;
    Window window;		/* Source/Target window */
    Display *display;
    Atom commAtom;		/* Data communication property atom. */
    int packetSize;
    Tcl_TimerToken timerToken;
    int status;			/* Status of transaction:  CONTINUE, OK, FAIL,
				 * or TIMEOUT. */
    int timestamp;		/* Timestamp of the transaction. */
    int offset;
    int protocol;		/* Drag-and-drop protocol used by the source:
				 * either PROTO_BLT or PROTO_XDND. */
} DropPending;

/* 
 * SubstDescriptors --
 *
 *	Structure to hold letter-value pairs for percent substitutions.
 */
typedef struct SubstDescriptors {
    char letter;		/* character like 'x' in "%x" */
    char *value;		/* value to be substituted in place of "%x" */
} SubstDescriptors;

/*
 *  Drag&Drop Registration Data
 */
typedef struct Token {
    Tk_Window tkwin;		/* Window that embodies the token.  NULL
				 * means that the window has been destroyed
				 * but the data structures haven't yet been
				 * cleaned up. */

    Display *display;		/* Display containing widget.  Used, among
				 * other things, so that resources can be
				 * freed even after tkwin has gone away. */
    Tcl_Interp *interp;		/* Interpreter associated with widget.  Used
				 * to delete widget command. */
    Tk_3DBorder border;		/* Structure used to draw 3-D border and
				 * background.  NULL means no background
				 * or border. */
    int borderWidth;		/* Width of 3-D border (if any). */
    int relief;			/* 3-d effect: TK_RELIEF_RAISED etc. */

    int flags;			/* Various flags;  see below for
				 * definitions. */

    /* Token specific fields */
    int x, y;			/* Last position of token window */
    int selectX, selectY;	/* Starting position of token window */
    int status;			/* Indicates the current status of the token:
				 * 0 is normal, 1 is active. */
    int lastStatus;		/* Indicates the last status of the token. */
    Tk_TimerToken timer;	/* token for routine to hide tokenwin */
    GC fillGC;			/* GC used to draw rejection fg: (\) */
    GC outlineGC;		/* GC used to draw rejection bg: (\) */
    int width, height;
    int reqWidth, reqHeight;

    /* User-configurable fields */

    Tk_Anchor anchor;		/* Position of token win relative to mouse */
    Tk_3DBorder normalBorder;	/* Border/background for token window */
    Tk_3DBorder activeBorder;	/* Border/background for token window */
    int activeRelief;
    int activeBorderWidth;	/* Border width in pixels */
    XColor *fillColor;		/* Color used to draw rejection fg: (\) */
    XColor *outlineColor;	/* Color used to draw rejection bg: (\) */
    Pixmap rejectStipple;	/* Stipple used to draw rejection: (\) */

    int nSteps;

} Token;

/*
 *  Winfo --
 *
 *	This structure represents a window hierarchy examined during a single
 *	"drag" operation.  It's used to cache information to reduce the round
 *	trip calls to the server needed to query window geometry information
 *	and grab the target property.  
 */
typedef struct Winfo {
    Window window;		/* Window in hierarchy. */

    int initialized;		/* If zero, the rest of this structure's
				 * information hasn't been set. */

    int x1, y1, x2, y2;		/* Extents of the window (upper-left and
				 * lower-right corners). */

    struct Winfo *parentPtr;	/* Parent node. NULL if root. Used to
				 * compute offset for X11 windows. */

    Blt_Chain *chainPtr;	/* List of this window's children. If NULL,
				 * there are no children. */

    int isTarget;		/* Indicates if this window is a drag&drop
				 * target. */
    int lookedForProperty;	/* Indicates if this window  */

    int eventFlags;		/* Retrieved from the target's drag&drop 
				 * property, indicates what kinds of pointer
				 * events should be relayed to the target via
				 * ClientMessages. Possible values are OR-ed 
				 * combinations of the following bits: 
				 *	001 Enter events.  
				 *	010 Motion events.
				 *	100 Leave events.  
				 */
    char *matches;

} Winfo;

/*
 *  Dnd --
 *
 *	This structure represents the drag&drop manager.  It is associated
 *	with a widget as a drag&drop source, target, or both.  It contains
 *	both the source and target components, since a widget can be both 
 *	a drag source and a drop target.  
 */
typedef struct {
    Tcl_Interp *interp;		/* Interpreter associated with the drag&drop
				 * manager. */

    Tk_Window tkwin;		/* Tk window representing the drag&drop 
				 * manager (can be source and/or target). */

    Display *display;		/* Display for drag&drop widget. Saved to free
				 * resources after window has been destroyed. */

    int isSource;		/* Indicates if this drag&drop manager can act
				 * as a drag source. */
    int isTarget;		/* Indicates if this drag&drop manager can act
				 * as a drop target. */

    int targetPropertyExists;	/* Indicates is the drop target property has 
				 * been set. */

    int timestamp;		/* Id of the current drag&drop transaction. */

    int x, y;			/* Last known location of the mouse pointer. */

    Tcl_HashEntry *hashPtr;

    ThreadData *dataPtr;	

    /* Source component. */
    
    Tcl_HashTable getDataTable;	/* Table of data handlers (converters)
				 * registered for this source. */

    int reqButton;		/* Button used to invoke drag operation. */

    int button;			/* Last button press detected. */
    int keyState;		/* Last key state.  */

    Tk_Cursor cursor;		/* Cursor restored after dragging */

    int selfTarget;		/* Indicated if the source should drop onto 
				 * itself. */

    char **reqFormats;		/* List of requested data formats. The
				 * list should be ordered with the more 
				 * desireable formats first. You can also
				 * temporarily turn off a source by setting 
				 * the value to the empty string. */

    Winfo *rootPtr;		/* Cached window information: Gathered
				 * and used during the "drag" operation 
				 * to see if the mouse pointer is over a 
				 * valid target. */

    Winfo *windowPtr;		/* Points to information about the last 
				 * target the pointer was over. If NULL, 
				 * the pointer was not over a valid target. */

    char *packageCmd;		/* Tcl command executed at start of the drag
				 * operation to initialize token. */

    int pkgCmdInProgress;	/* Indicates if a token package command is
				 * currently active. The user may invoke
				 * "update" or "tkwait" commands from within
				 * the package command script. This allows the
				 * "drag" operation to preempt itself. */

    char *resultCmd;		/* Tcl command executed at the end of the
				 * "drop" operation to indicate its status. */

    char *siteCmd;		/* Tcl command executed to update token 
				 * window. */

    int canceled;		/* Indicated if the drag operation was 
				 * canceled. */

    Token *tokenPtr;		/* Token used to provide special cursor. */
    

    Tcl_TimerToken timerToken;

    Tk_Cursor *cursors;		/* Array of drag-and-drop cursors. */
    int cursorPos;

    /* Target component. */

    Tcl_HashTable setDataTable;	/* Table of data handlers (converters)
				 * registered for this target. */
    char *enterCmd;		/* Tcl proc called when the mouse enters the
				 * target. */
    char *leaveCmd;		/* Tcl proc called when the mouse leaves the
				 * target. */
    char *motionCmd;		/* Tcl proc called when the mouse is moved
				 * over the target. */
    char *dropCmd;		/* Tcl proc called when the mouse button
				 * is released over the target. */

    char *matchingFormats;
    int lastId;			/* The last transaction id used. This is used
				 * to cache the above formats string. */

    DropPending *pendingPtr;	/* Points to structure containing information
				 * about a current drop in progress. If NULL,
				 * no drop is in progress. */

} Dnd;


typedef struct XDndHandler {
    Tk_Window tkwin;		/* Toplevel window of the drop target. */
    int refCount;		/* # of targets referencing this structure. */
    Dnd *dndPtr;		/* Last drop target selected.  Used the 
				 * implement Enter/Leave events for targets. 
				 * If NULL, indicates that no drop target was 
				 * previously selected. */
    int lastRepsonse;		/* Indicates what the last response was. */
    Window window;		/* Window id of the top-level window (ie.
				 * the wrapper). */
    char **formatArr;		/* List of formats available from source. 
				 * Must be pruned down to matching list. */
    ThreadData *dataPtr;
    int x, y;
    
} XDndHandler;

extern Tk_CustomOption bltListOption;

static Tk_ConfigSpec configSpecs[] =
{
    {TK_CONFIG_CUSTOM, "-allowformats", "allowFormats", "AllowFormats", 
	DEF_DND_SEND, Tk_Offset(Dnd, reqFormats), 
        TK_CONFIG_NULL_OK, &bltListOption},
    {TK_CONFIG_INT, "-button", "buttonNumber", "ButtonNumber",
	DEF_DND_BUTTON_NUMBER, Tk_Offset(Dnd, reqButton), 0},
    {TK_CONFIG_CUSTOM, "-cursors", "cursors", "cursors",
	DEF_TOKEN_CURSOR, Tk_Offset(Dnd, cursors), 
	TK_CONFIG_NULL_OK, &cursorsOption },
    {TK_CONFIG_STRING, "-onenter", "onEnter", "OnEnter",
	DEF_DND_PACKAGE_COMMAND, Tk_Offset(Dnd, enterCmd), 
	TK_CONFIG_NULL_OK},
    {TK_CONFIG_STRING, "-onmotion", "onMotion", "OnMotion",
	DEF_DND_PACKAGE_COMMAND, Tk_Offset(Dnd, motionCmd), 
	TK_CONFIG_NULL_OK},
    {TK_CONFIG_STRING, "-onleave", "onLeave", "OnLeave",
	DEF_DND_PACKAGE_COMMAND, Tk_Offset(Dnd, leaveCmd), 
	TK_CONFIG_NULL_OK},
    {TK_CONFIG_STRING, "-ondrop", "onDrop", "OnDrop",
	DEF_DND_PACKAGE_COMMAND, Tk_Offset(Dnd, dropCmd), 
	TK_CONFIG_NULL_OK},
    {TK_CONFIG_STRING, "-package", "packageCommand", "PackageCommand",
	DEF_DND_PACKAGE_COMMAND, Tk_Offset(Dnd, packageCmd), 
        TK_CONFIG_NULL_OK },
    {TK_CONFIG_STRING, "-result", "result", "Result",
	DEF_DND_PACKAGE_COMMAND, Tk_Offset(Dnd, resultCmd), 
	TK_CONFIG_NULL_OK},
    {TK_CONFIG_BOOLEAN, "-selftarget", "selfTarget", "SelfTarget",
	DEF_DND_SELF_TARGET, Tk_Offset(Dnd, selfTarget), 0},
    {TK_CONFIG_STRING, "-site", "siteCommand", "Command",
	DEF_DND_SITE_COMMAND, Tk_Offset(Dnd, siteCmd), 
        TK_CONFIG_NULL_OK},
    {TK_CONFIG_BOOLEAN, "-source", "source", "Source",
	DEF_DND_IS_SOURCE, Tk_Offset(Dnd, isSource), 0},
    {TK_CONFIG_BOOLEAN, "-target", "target", "Target",
	DEF_DND_IS_TARGET, Tk_Offset(Dnd, isTarget), 0},
    {TK_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL, (char *)NULL, 
	0, 0},
};

static Tk_ConfigSpec tokenConfigSpecs[] =
{
    {TK_CONFIG_BORDER, "-activebackground", "activeBackground",
	"ActiveBackground", DEF_TOKEN_ACTIVE_BG_COLOR,
	Tk_Offset(Token, activeBorder), TK_CONFIG_COLOR_ONLY},
    {TK_CONFIG_BORDER, "-activebackground", "activeBackground",
	"ActiveBackground", DEF_TOKEN_ACTIVE_BG_MONO, 
	Tk_Offset(Token, activeBorder), TK_CONFIG_MONO_ONLY},
    {TK_CONFIG_RELIEF, "-activerelief", "activeRelief", "activeRelief",
	DEF_TOKEN_ACTIVE_RELIEF, Tk_Offset(Token, activeRelief), 0},
    {TK_CONFIG_ANCHOR, "-anchor", "anchor", "Anchor",
	DEF_TOKEN_ANCHOR, Tk_Offset(Token, anchor), 0},
    {TK_CONFIG_PIXELS, "-activeborderwidth", "activeBorderWidth",
	"ActiveBorderWidth", DEF_TOKEN_ACTIVE_BORDERWIDTH, 
	Tk_Offset(Token, activeBorderWidth), 0},
    {TK_CONFIG_BORDER, "-background", "background", "Background",
	DEF_TOKEN_BG_COLOR, Tk_Offset(Token, normalBorder),
	TK_CONFIG_COLOR_ONLY},
    {TK_CONFIG_BORDER, "-background", "background", "Background",
	DEF_TOKEN_BG_MONO, Tk_Offset(Token, normalBorder),
	TK_CONFIG_MONO_ONLY},
    {TK_CONFIG_PIXELS, "-borderwidth", "borderWidth", "BorderWidth",
	DEF_TOKEN_BORDERWIDTH, Tk_Offset(Token, borderWidth), 0},
    {TK_CONFIG_COLOR, "-outline", "outline", "Outline",
	DEF_TOKEN_REJECT_BG_COLOR, Tk_Offset(Token, outlineColor), 
	TK_CONFIG_COLOR_ONLY},
    {TK_CONFIG_COLOR, "-outline", "outline", "Outline",
	DEF_TOKEN_REJECT_BG_MONO, Tk_Offset(Token, outlineColor), 
	TK_CONFIG_MONO_ONLY},
    {TK_CONFIG_COLOR, "-fill", "fill", "Fill",
	DEF_TOKEN_REJECT_FG_COLOR, Tk_Offset(Token, fillColor), 
	TK_CONFIG_COLOR_ONLY},
    {TK_CONFIG_COLOR, "-fill", "fill", "Fill",
	DEF_TOKEN_REJECT_BG_COLOR, Tk_Offset(Token, fillColor), 
	TK_CONFIG_MONO_ONLY},
    {TK_CONFIG_BITMAP, "-rejectstipple", "rejectStipple", "Stipple",
	DEF_TOKEN_REJECT_STIPPLE_COLOR, Tk_Offset(Token, rejectStipple),
	TK_CONFIG_COLOR_ONLY | TK_CONFIG_NULL_OK},
    {TK_CONFIG_BITMAP, "-rejectstipple", "rejectStipple", "Stipple",
	DEF_TOKEN_REJECT_STIPPLE_MONO, Tk_Offset(Token, rejectStipple),
	TK_CONFIG_MONO_ONLY},
    {TK_CONFIG_RELIEF, "-relief", "relief", "Relief",
	DEF_TOKEN_RELIEF, Tk_Offset(Token, relief), 0},
    {TK_CONFIG_END, (char *)NULL, (char *)NULL, (char *)NULL, (char *)NULL, 
	0, 0},
};

/*
 *  Forward Declarations
 */
static int DndCmd _ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp,
	int argc, char **argv));
static void TokenEventProc _ANSI_ARGS_((ClientData clientData, 
	XEvent *eventPtr));
static void MoveToken _ANSI_ARGS_((Dnd *dndPtr));
static void DisplayToken _ANSI_ARGS_((ClientData clientData));
static void HideToken _ANSI_ARGS_((Dnd *dndPtr));
static void DrawRejectSymbol _ANSI_ARGS_((Dnd *dndPtr));

static int GetDnd _ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
	char *name, Dnd **dndPtrPtr));
static Dnd *CreateDnd _ANSI_ARGS_((Tcl_Interp *interp, Tk_Window tkwin));
static void DestroyDnd _ANSI_ARGS_((Dnd *dndPtr));
static int DndEventProc _ANSI_ARGS_((ClientData clientData,
	XEvent *eventPtr));
static int ConfigureToken _ANSI_ARGS_((Tcl_Interp *interp, Dnd *dndPtr,
	int argc, char **argv, int flags));

static Winfo *OverTarget _ANSI_ARGS_((Dnd *dndPtr));
static void AddTargetProperty _ANSI_ARGS_((Tcl_Interp *interp, Dnd *dndPtr));

static Winfo *InitRoot _ANSI_ARGS_((Dnd *dndPtr));
static void FreeWinfo _ANSI_ARGS_((Winfo *wr));
static void GetWinfo _ANSI_ARGS_((Display *display, Winfo * windowPtr));

static void ExpandPercents _ANSI_ARGS_((char *str, SubstDescriptors * subs,
	int nsubs, Tcl_DString * dStrPtr));

/*
 * ----------------------------------------------------------------------------
 *
 * StringToCursors --
 *
 *	Converts the resize mode into its numeric representation.  Valid
 *	mode strings are "none", "expand", "shrink", or "both".
 *
 * ----------------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
StringToCursors(clientData, interp, tkwin, string, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    char *string;		/* String representing cursors. */
    char *widgRec;		/* Structure record */
    int offset;			/* Offset of field in record. */
{
    Tk_Cursor **cursorPtrPtr = (Tk_Cursor **)(widgRec + offset);
    int result = TCL_OK;
    int nElems;
    char **elemArr;

    if (*cursorPtrPtr != NULL) {
	free((char *)*cursorPtrPtr);
	*cursorPtrPtr = NULL;
    }
    if (string == NULL) {
	return TCL_OK;
    }
    if (Tcl_SplitList(interp, string, &nElems, &elemArr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (nElems > 0) {
	Tk_Cursor *cursorArr;
	register int i;

	cursorArr = (Tk_Cursor *)calloc(nElems + 1, sizeof(Tk_Cursor));
	for (i = 0; i < nElems; i++) {
	    cursorArr[i] = Tk_GetCursor(interp, tkwin, Tk_GetUid(elemArr[i]));
	    if (cursorArr[i] == None) {
		*cursorPtrPtr = cursorArr;
		result = TCL_ERROR;
		break;
	    }
	}    
	free((char *)elemArr);
	*cursorPtrPtr = cursorArr;
    }
    return result;
}

/*
 * ----------------------------------------------------------------------------
 *
 * CursorsToString --
 *
 *	Returns resize mode string based upon the resize flags.
 *
 * Results:
 *	The resize mode string is returned.
 *
 * ----------------------------------------------------------------------------
 */
/*ARGSUSED*/
static char *
CursorsToString(clientData, tkwin, widgRec, offset, freeProcPtr)
    ClientData clientData;	/* Not used. */
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;		/* Cursor record */
    int offset;			/* Offset of record. */
    Tcl_FreeProc **freeProcPtr;	/* Memory deallocation scheme to use */
{
    Tk_Cursor *cursorArr = *(Tk_Cursor **)(widgRec + offset);
    Tk_Cursor *cursorPtr;
    Tcl_DString dString;
    char *result;

    if (cursorArr == NULL) {
	return "";
    }
    Tcl_DStringInit(&dString);
    for (cursorPtr = cursorArr; *cursorPtr != NULL; cursorPtr++) {
	Tcl_DStringAppendElement(&dString, 
		 Tk_NameOfCursor(Tk_Display(tkwin), *cursorPtr));
    }
    result = strdup(Tcl_DStringValue(&dString));
    Tcl_DStringFree(&dString);
    *freeProcPtr = (Tcl_FreeProc *)free;
    return result;
}


/* ARGSUSED */
static int
XSendEventErrorProc(clientData, errEventPtr)
    ClientData clientData;
    XErrorEvent *errEventPtr;
{
    int *errorPtr = (int *)clientData;

    *errorPtr = TCL_ERROR;
    return 0;
}

static void
SendClientMsg(display, window, mesgAtom, data0, data1, data2, data3, data4)
    Display *display;
    Window window;
    Atom mesgAtom;
    int data0, data1, data2, data3, data4;
{
    XEvent event;
    Tk_ErrorHandler handler;
    int result;
    int any = -1;

    event.xclient.type = ClientMessage;
    event.xclient.serial = 0;
    event.xclient.send_event = True;
    event.xclient.display = display;
    event.xclient.window = window;
    event.xclient.message_type = mesgAtom;
    event.xclient.format = 32;
    event.xclient.data.l[0] = data0;
    event.xclient.data.l[1] = data1;
    event.xclient.data.l[2] = data2;
    event.xclient.data.l[3] = data3;
    event.xclient.data.l[4] = data4;

    result = TCL_OK;
    handler = Tk_CreateErrorHandler(display, any, X_SendEvent, any,
	XSendEventErrorProc, (ClientData)&result);
    if (!XSendEvent(display, window, False, ClientMessage, &event)) {
	result = TCL_ERROR;
    }
    Tk_DeleteErrorHandler(handler);
    XSync(display, False);
    if (result != TCL_OK) {
	fprintf(stderr, "XSendEvent response to drop: Protocol failed\n");
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetWindowZOrder --
 *
 *	Returns a chain of the child windows according to their stacking
 *	order. The window ids are ordered from top to bottom.
 *
 * ------------------------------------------------------------------------ 
 */
static Blt_Chain *
GetWindowZOrder(display, window)
    Display *display;
    Window window;
{
    Blt_Chain *chainPtr;
    Window *childArr;
    unsigned int nChildren;
    Window dummy;

    chainPtr = NULL;
    if ((XQueryTree(display, window, &dummy, &dummy, &childArr, &nChildren)) &&
	(nChildren > 0)) {
	register int i;

	chainPtr = Blt_ChainCreate();
	for (i = 0; i < nChildren; i++) {
	    /* 
	     * XQuery returns windows in bottom to top order.  We only care
	     * about the top window.  
	     */
	    Blt_ChainPrepend(chainPtr, (ClientData)childArr[i]);
	}
	if (childArr != NULL) {
	    XFree((char *)childArr);	/* done with list of kids */
	}
    }
    return chainPtr;
}

static int
GetMaxPropertySize(display)
    Display *display;
{
    int size;

#if (XT_REVISION < 6)
    size = XMaxRequestSize(display);
#else
    size = MAX(XExtendedMaxRequestSize(display), XMaxRequestSize(display));
#endif
    size *= 4;			/* Convert to bytes. */
    size -= 32;
    return size;
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetProperty --
 *
 *	Returns the data associated with the named property on the
 *	given window.  All data is assumed to be 8-bit string data.
 *
 * ------------------------------------------------------------------------ 
 */
static char *
GetProperty(display, window, atom)
    Display *display;
    Window window;
    Atom atom;
{
    char *data;
    int result, format;
    Atom typeAtom;
    unsigned long nItems, bytesAfter;

    if (window == None) {
	return NULL;
    }
    data = NULL;
    result = XGetWindowProperty(
        display,		/* Display of window. */
	window,			/* Window holding the property. */
        atom,			/* Name of property. */
        0,			/* Offset of data (for multiple reads). */
	GetMaxPropertySize(display), /* Maximum number of items to read. */
	False,			/* If true, delete the property. */
        XA_STRING,		/* Desired type of property. */
        &typeAtom,		/* (out) Actual type of the property. */
        &format,		/* (out) Actual format of the property. */
        &nItems,		/* (out) # of items in specified format. */
        &bytesAfter,		/* (out) # of bytes remaining to be read. */
	(unsigned char **)&data);
    if ((result != Success) || (format != 8) || (typeAtom != XA_STRING)) {
	if (data != NULL) {
	    XFree((char *)data);
	    data = NULL;
	}
    }
    return data;
}

/*
 * ------------------------------------------------------------------------
 *
 *  SetProperty --
 *
 *	Associates the given data with the a property on a given window.
 *	All data is assumed to be 8-bit string data.
 *
 * ------------------------------------------------------------------------ 
 */
static void
SetProperty(tkwin, atom, data)
    Tk_Window tkwin;
    Atom atom;
    char *data;
{
    XChangeProperty(Tk_Display(tkwin), Tk_WindowId(tkwin), atom, XA_STRING,
	8, PropModeReplace, (unsigned char *)data, strlen(data) + 1);
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetWindowRegion --
 *
 *	Queries for the upper-left and lower-right corners of the 
 *	given window.  
 *
 *  Results:
 *	Returns if the window is currently viewable.  The coordinates
 *	of the window are returned via parameters.
 *
 * ------------------------------------------------------------------------ 
 */
static int
GetWindowRegion(display, window, x1Ptr, y1Ptr, x2Ptr, y2Ptr)
    Display *display;
    Window window;
    int *x1Ptr, *y1Ptr, *x2Ptr, *y2Ptr;
{
    XWindowAttributes winAttrs;

    if (XGetWindowAttributes(display, window, &winAttrs)) {
	*x1Ptr = winAttrs.x;
	*y1Ptr = winAttrs.y;
	*x2Ptr = winAttrs.x + winAttrs.width - 1;
	*y2Ptr = winAttrs.y + winAttrs.height - 1;
    }
    return (winAttrs.map_state == IsViewable);
}

/*
 * ------------------------------------------------------------------------
 *
 *  FindTopWindow --
 *
 *	Searches for the topmost window at a given pair of X-Y coordinates.
 *
 *  Results:
 *	Returns a pointer to the node representing the window containing
 *	the point.  If one can't be found, NULL is returned.
 *
 * ------------------------------------------------------------------------
 */
static Winfo *
FindTopWindow(dndPtr, x, y)
    Dnd *dndPtr;
    int x, y;
{
    Winfo *rootPtr;
    register Blt_ChainLink *linkPtr;
    register Winfo *windowPtr;

    rootPtr = dndPtr->rootPtr;
    if (!rootPtr->initialized) {
	GetWinfo(dndPtr->display, rootPtr);
    }
    if ((x < rootPtr->x1) || (x > rootPtr->x2) ||
	(y < rootPtr->y1) || (y > rootPtr->y2)) {
	return NULL;		/* Point is not over window  */
    }
    windowPtr = rootPtr;

    /*  
     * The window list is ordered top to bottom, so stop when we find the
     * first child that contains the X-Y coordinate. It will be the topmost
     * window in that hierarchy.  If none exists, then we already have the
     * topmost window.  
     */
  descend:
    for (linkPtr = Blt_ChainFirstLink(rootPtr->chainPtr); linkPtr != NULL;
	linkPtr = Blt_ChainNextLink(linkPtr)) {
	rootPtr = (Winfo *) Blt_ChainGetValue(linkPtr);
	if (!rootPtr->initialized) {
	    GetWinfo(dndPtr->display, rootPtr);
	}
	if (rootPtr->window == Blt_GetRealWindowId(dndPtr->tokenPtr->tkwin)) {
	    continue;		/* Don't examine the token window. */
	}
	if ((x >= rootPtr->x1) && (x <= rootPtr->x2) &&
	    (y >= rootPtr->y1) && (y <= rootPtr->y2)) {
	    /*   
	     * Remember the last window containing the pointer and descend
	     * into its window hierarchy. We'll look for a child that also
	     * contains the pointer.  
	     */
	    windowPtr = rootPtr;
	    goto descend;
	}
    }
    return windowPtr;
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetWidgetCursor --
 *
 *	Queries a widget for its current cursor.   The given window
 *	may or may not be a Tk widget that has a -cursor option. 
 *
 *  Results:
 *	Returns the current cursor of the widget.
 *
 * ------------------------------------------------------------------------ 
 */
static Tk_Cursor
GetWidgetCursor(interp, tkwin)
    Tcl_Interp *interp;		/* Interpreter to evaluate widget command. */
    Tk_Window tkwin;		/* Window of drag&drop source. */
{
    Tk_Cursor cursor;
    Tcl_DString dString, savedResult;

    cursor = None;
    Tcl_DStringInit(&dString);
    Blt_DStringAppendElements(&dString, Tk_PathName(tkwin), "cget", "-cursor",
	      (char *)NULL);
    Tcl_DStringInit(&savedResult);
    Tcl_DStringGetResult(interp, &savedResult);
    if (Tcl_GlobalEval(interp, Tcl_DStringValue(&dString)) == TCL_OK) {
	char *name;

	name = Tcl_GetStringResult(interp);
	if ((name != NULL) && (name[0] != '\0')) {
	    cursor = Tk_GetCursor(interp, tkwin, Tk_GetUid(name));
	}
    }
    Tcl_DStringResult(interp, &savedResult);
    Tcl_DStringFree(&dString);
    return cursor;
}

/*
 * ------------------------------------------------------------------------
 *
 *  NameOfAction --
 *
 *	Converts a numeric drop result into its string representation.
 *
 *  Results:
 *	Returns a static string representing the drop result.
 *
 * ------------------------------------------------------------------------
 */
static char *
NameOfStatus(status)
    int status;
{
    switch (status) {
    case TOKEN_STATUS_ACTIVE:
	return "active";
    case TOKEN_STATUS_NORMAL:
	return "normal";
	break;
    case TOKEN_STATUS_REJECT:
	return "reject";
    default:
	return "unknown status value";
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  NameOfAction --
 *
 *	Converts a numeric drop result into its string representation.
 *
 *  Results:
 *	Returns a static string representing the drop result.
 *
 * ------------------------------------------------------------------------
 */
static char *
NameOfAction(action)
    int action;
{
    switch (action) {
    case ACTION_CANCEL:
	return "cancel";
    case ACTION_MOVE:
	return "move";
	break;
    case ACTION_LINK:
	return "link";
    case ACTION_COPY:
	return "copy";
    default:
	return "unknown action";
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetAction --
 *
 *	Converts a string to its numeric drop result value.
 *
 *  Results:
 *	Returns the drop result.
 *
 * ------------------------------------------------------------------------
 */
static int
GetAction(string)
    char *string;
{
    char c;

    c = string[0];
    if ((c == 'c') && (strcmp(string, "cancel") == 0)) {
	return ACTION_CANCEL;
    } else if ((c == 'm') && (strcmp(string, "move") == 0)) {
	return ACTION_MOVE;
    } else if ((c == 'l') && (strcmp(string, "link") == 0)) {
	return ACTION_LINK;
    } else if ((c == 'c') && (strcmp(string, "copy") == 0)) {
	return ACTION_COPY;
    } else {
	return ACTION_COPY;
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetDragResult --
 *
 *	Converts a string to its numeric drag result value.
 *
 *  Results:
 *	Returns the drag result.
 *
 * ------------------------------------------------------------------------
 */
static int
GetDragResult(interp, string)
    Tcl_Interp *interp;
    char *string;
{
    char c;
    int bool;

    c = string[0];
    if ((c == 'c') && (strcmp(string, "cancel") == 0)) {
	return DRAG_CANCEL;
    } else if (Tcl_GetBoolean(interp, string, &bool) != TCL_OK) {
	Tcl_BackgroundError(interp);
	return DRAG_CANCEL;
    }
    return bool;
}

static void
AnimateActiveCursor(clientData)
    ClientData clientData;
{
    Dnd *dndPtr = (Dnd *)clientData;    
    Tk_Cursor cursor;

    dndPtr->cursorPos++;
    cursor = dndPtr->cursors[dndPtr->cursorPos];
    if (cursor == None) {
	cursor = dndPtr->cursors[1];
	dndPtr->cursorPos = 1;
    }
    Tk_DefineCursor(dndPtr->tkwin, cursor);
    dndPtr->timerToken = Tk_CreateTimerHandler(100, AnimateActiveCursor,
	    (ClientData)dndPtr);
}

static void
StartActiveCursor(dndPtr)
    Dnd *dndPtr;    
{
    if (dndPtr->timerToken != NULL) {
	Tk_DeleteTimerHandler(dndPtr->timerToken);
    }
    if (dndPtr->cursors != NULL) {
	Tk_Cursor cursor;

	dndPtr->cursorPos = 1;
	cursor = dndPtr->cursors[1];
	if (cursor != None) {
	    Tk_DefineCursor(dndPtr->tkwin, cursor);
	    dndPtr->timerToken = Tk_CreateTimerHandler(125, AnimateActiveCursor,
		       (ClientData)dndPtr);
	}
    }
}

static void
StopActiveCursor(dndPtr)
    Dnd *dndPtr;    
{
    if (dndPtr->cursorPos > 0) {
	dndPtr->cursorPos = 0;
    }
    if (dndPtr->cursors != NULL) {
	Tk_DefineCursor(dndPtr->tkwin, dndPtr->cursors[0]);
    }
    if (dndPtr->timerToken != NULL) {
	Tk_DeleteTimerHandler(dndPtr->timerToken);
	dndPtr->timerToken = NULL;
    }
}

/*
 *----------------------------------------------------------------------
 *
 * EventuallyRedrawToken --
 *
 *	Queues a request to redraw the widget at the next idle point.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Information gets redisplayed.  Right now we don't do selective
 *	redisplays:  the whole window will be redrawn.
 *
 *----------------------------------------------------------------------
 */
static void
EventuallyRedrawToken(dndPtr)
    Dnd *dndPtr;
{
    Token *tokenPtr;

    if (dndPtr->tokenPtr == NULL) {
	return;
    }
    tokenPtr = dndPtr->tokenPtr;
    if ((tokenPtr->tkwin != NULL) && (tokenPtr->tkwin != NULL) && 
	!(tokenPtr->flags & TOKEN_REDRAW)) {
	tokenPtr->flags |= TOKEN_REDRAW;
	Tk_DoWhenIdle(DisplayToken, (ClientData)dndPtr);
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  RaiseToken --
 *
 * ------------------------------------------------------------------------
 */
static void
RaiseToken(tokenPtr)
    Token *tokenPtr;
{
    Blt_MapTopLevelWindow(tokenPtr->tkwin);
    Blt_RaiseTopLevelWindow(tokenPtr->tkwin);
}



/*
 * ------------------------------------------------------------------------
 *
 *  DisplayToken --
 *
 * ------------------------------------------------------------------------
 */
static void
DisplayToken(clientData)
    ClientData clientData;
{
    Dnd *dndPtr = (Dnd *)clientData;
    Token *tokenPtr = dndPtr->tokenPtr;
    int relief;
    Tk_3DBorder border;
    int borderWidth;

    tokenPtr->flags &= ~TOKEN_REDRAW;
    if (tokenPtr->reqWidth == 0) {
	tokenPtr->reqWidth = Tk_ReqWidth(tokenPtr->tkwin);
    }
    if (tokenPtr->reqHeight == 0) {
	tokenPtr->reqHeight = Tk_ReqHeight(tokenPtr->tkwin);
    }
    if (tokenPtr->status == TOKEN_STATUS_NORMAL) {
	relief = tokenPtr->relief;
	border = tokenPtr->normalBorder;
	borderWidth = tokenPtr->borderWidth;
	StopActiveCursor(dndPtr);
    } else {
	relief = tokenPtr->activeRelief;
	border = tokenPtr->activeBorder;
	borderWidth = tokenPtr->activeBorderWidth;
	if ((dndPtr->cursors != NULL) && (dndPtr->cursorPos == 0)) {
	    StartActiveCursor(dndPtr);
	}
    } 
    Tk_Fill3DRectangle(tokenPtr->tkwin, Tk_WindowId(tokenPtr->tkwin), border, 
	0, 0, Tk_Width(tokenPtr->tkwin), Tk_Height(tokenPtr->tkwin), 
	borderWidth, relief);
    tokenPtr->lastStatus = tokenPtr->status;
    if (tokenPtr->status == TOKEN_STATUS_REJECT) {
	DrawRejectSymbol(dndPtr);
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  FadeToken --
 *
 *	Fades the token into the target.
 *
 * ------------------------------------------------------------------------
 */
static void
FadeToken(dndPtr)
    Dnd *dndPtr;		/* drag&drop source window data */
{ 
    Token *tokenPtr = dndPtr->tokenPtr;
    int w, h;
    int dx, dy;
    Window window;

    if (tokenPtr->status == TOKEN_STATUS_REJECT) {
	tokenPtr->nSteps = 1;
	return;
    }
    if (tokenPtr->nSteps == 1) {
	HideToken(dndPtr);
	return;
    }
    tokenPtr->timer = Tk_CreateTimerHandler(10, (Tcl_TimerProc *)FadeToken,
	    (ClientData)dndPtr);
    tokenPtr->nSteps--;

    w = tokenPtr->reqWidth * tokenPtr->nSteps / 10;
    h = tokenPtr->reqHeight * tokenPtr->nSteps / 10;
    if (w < 1) {
	w = 1;
    } 
    if (h < 1) {
	h = 1;
    }
    dx = (tokenPtr->reqWidth - w) / 2;
    dy = (tokenPtr->reqHeight - h) / 2;
    window = Blt_GetRealWindowId(tokenPtr->tkwin);
    XMoveResizeWindow(dndPtr->display, window, tokenPtr->x + dx, 
	     tokenPtr->y + dy, (unsigned int)w, (unsigned int)h);
    tokenPtr->width = w, tokenPtr->height = h;
}

/*
 * ------------------------------------------------------------------------
 *
 *  SnapToken --
 *
 *	Snaps the token back to the source.
 *
 * ------------------------------------------------------------------------
 */
static void
SnapToken(dndPtr)
    Dnd *dndPtr;		/* drag&drop source window data */
{ 
    Token *tokenPtr = dndPtr->tokenPtr;

    if (tokenPtr->nSteps == 1) {
	HideToken(dndPtr);
	return;
    }
    tokenPtr->timer = Tk_CreateTimerHandler(10, (Tcl_TimerProc *)SnapToken,
	    (ClientData)dndPtr);
    tokenPtr->nSteps--;
    tokenPtr->x -= (tokenPtr->x - tokenPtr->selectX) / tokenPtr->nSteps;
    tokenPtr->y -= (tokenPtr->y - tokenPtr->selectY) / tokenPtr->nSteps;
    if ((tokenPtr->x != Tk_X(tokenPtr->tkwin)) || 
	(tokenPtr->y != Tk_Y(tokenPtr->tkwin))) {
	Tk_MoveToplevelWindow(tokenPtr->tkwin, tokenPtr->x, tokenPtr->y);
    }
    RaiseToken(tokenPtr);
}

/*
 * ------------------------------------------------------------------------
 *
 *  HideToken --
 *
 *	Unmaps the drag&drop token.  Invoked directly at the end of a
 *	successful communication, or after a delay if the communication
 *	fails (allowing the user to see a graphical picture of failure).
 *
 * ------------------------------------------------------------------------
 */
static void
HideToken(dndPtr)
    Dnd *dndPtr;
{
    Token *tokenPtr = dndPtr->tokenPtr;

    /* Reset the cursor back to its normal state.  */
    StopActiveCursor(dndPtr);
    if (dndPtr->cursor == None) {
	Tk_UndefineCursor(dndPtr->tkwin);
    } else {
	Tk_DefineCursor(dndPtr->tkwin, dndPtr->cursor);
    }
    if (tokenPtr->tkwin != NULL) {
	Tk_UnmapWindow(tokenPtr->tkwin); 
	Blt_ResizeTopLevelWindow(tokenPtr->tkwin, tokenPtr->reqWidth,
		 tokenPtr->reqHeight);
    }
    tokenPtr->timer = NULL;
    tokenPtr->status = TOKEN_STATUS_NORMAL;
}

/*
 * ------------------------------------------------------------------------
 *
 *  MoveToken --
 *
 *	Invoked during "drag" operations to move a token window to its
 *	current "drag" coordinate.
 *
 * ------------------------------------------------------------------------
 */
static void
MoveToken(dndPtr)
    Dnd *dndPtr;		/* drag&drop source window data */
{ 
    Token *tokenPtr = dndPtr->tokenPtr;
    int x, y;
    int maxX, maxY;
    int vx, vy, vw, vh;
    Screen *screenPtr;
    int anchor;
    /* Adjust current location for virtual root windows.  */
    Tk_GetVRootGeometry(dndPtr->tkwin, &vx, &vy, &vw, &vh);
    x = dndPtr->x + vx - TOKEN_OFFSET;
    y = dndPtr->y + vy - TOKEN_OFFSET;

    screenPtr = Tk_Screen(dndPtr->tkwin);
    maxX = WidthOfScreen(screenPtr) - Tk_Width(tokenPtr->tkwin);
    maxY = HeightOfScreen(screenPtr) - Tk_Height(tokenPtr->tkwin);
    anchor = (tokenPtr->status == TOKEN_STATUS_ACTIVE) 
	? TK_ANCHOR_NE : TK_ANCHOR_SE;
    Blt_TranslateAnchor(x, y, Tk_Width(tokenPtr->tkwin),
	Tk_Height(tokenPtr->tkwin), tokenPtr->anchor, &x, &y);
    if (x > maxX) {
	x = maxX;
    } else if (x < 0) {
	x = 0;
    }
    if (y > maxY) {
	y = maxY;
    } else if (y < 0) {
	y = 0;
    }
    tokenPtr->x = x, tokenPtr->y  = y;
    if ((x != Tk_X(tokenPtr->tkwin)) || (y != Tk_Y(tokenPtr->tkwin))) {
	Tk_MoveToplevelWindow(tokenPtr->tkwin, x, y);
    }
    RaiseToken(tokenPtr);
}


/*
 * ------------------------------------------------------------------------
 *
 *  ChangeToken --
 *
 *	Invoked when the event loop is idle to determine whether or not
 *	the current drag&drop token position is over another drag&drop
 *	target.
 *
 * ------------------------------------------------------------------------
 */
static void
ChangeToken(dndPtr)
    Dnd *dndPtr;
{
    Token *tokenPtr = dndPtr->tokenPtr;

    EventuallyRedrawToken(dndPtr);

    /*
     *  If the source has a site command, then invoke it to
     *  modify the appearance of the token window.  Pass any
     *  errors onto the drag&drop error handler.
     */
    if (dndPtr->siteCmd) {
	Tcl_Interp *interp = dndPtr->interp;
	Tcl_DString dString, savedResult;
	int result;
	SubstDescriptors subs[3];
	
	subs[0].letter = 's';
	subs[0].value = NameOfStatus(tokenPtr->status);
	subs[1].letter = 'W';
	subs[1].value = Tk_PathName(tokenPtr->tkwin);
	subs[2].letter = 't';
	subs[2].value = Blt_Itoa(dndPtr->timestamp);
	ExpandPercents(dndPtr->siteCmd, subs, 3, &dString);
	Tcl_DStringInit(&savedResult);
	Tcl_DStringGetResult(interp, &savedResult);
	result = Tcl_GlobalEval(interp, Tcl_DStringValue(&dString));
	Tcl_DStringFree(&dString);
	if (result != TCL_OK) {
	    Tcl_BackgroundError(interp);
	}
	Tcl_DStringResult(interp, &savedResult);
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  DrawRejectSymbol --
 *
 *	Draws a rejection mark on the current drag&drop token, and arranges
 *	for the token to be unmapped after a small delay.
 *
 * ------------------------------------------------------------------------
 */
static void
DrawRejectSymbol(dndPtr)
    Dnd *dndPtr;
{
    Token *tokenPtr = dndPtr->tokenPtr;
    int divisor = 6;		/* controls size of rejection symbol */
    int w, h, lineWidth, x, y, margin;

    margin = 2 * tokenPtr->borderWidth;
    w = Tk_Width(tokenPtr->tkwin) - 2 * margin;
    h = Tk_Height(tokenPtr->tkwin) - 2 * margin;
    lineWidth = (w < h) ? w / divisor : h / divisor;
    lineWidth = (lineWidth < 1) ? 1 : lineWidth;

    w = h = lineWidth * (divisor - 1);
    x = (Tk_Width(tokenPtr->tkwin) - w) / 2;
    y = (Tk_Height(tokenPtr->tkwin) - h) / 2;

    /*
     *  Draw the rejection symbol background (\) on the token window...
     */
    XSetLineAttributes(Tk_Display(tokenPtr->tkwin), tokenPtr->outlineGC,
	lineWidth + 2, LineSolid, CapButt, JoinBevel);

    XDrawArc(Tk_Display(tokenPtr->tkwin), Tk_WindowId(tokenPtr->tkwin),
	tokenPtr->outlineGC, x, y, w, h, 0, 23040);

    XDrawLine(Tk_Display(tokenPtr->tkwin), Tk_WindowId(tokenPtr->tkwin),
	tokenPtr->outlineGC, x + lineWidth, y + lineWidth, x + w - lineWidth,
	y + h - lineWidth);

    /*
     *  Draw the rejection symbol foreground (\) on the token window...
     */
    XSetLineAttributes(Tk_Display(tokenPtr->tkwin), tokenPtr->fillGC,
	lineWidth, LineSolid, CapButt, JoinBevel);

    XDrawArc(Tk_Display(tokenPtr->tkwin), Tk_WindowId(tokenPtr->tkwin),
	tokenPtr->fillGC, x, y, w, h, 0, 23040);

    XDrawLine(Tk_Display(tokenPtr->tkwin), Tk_WindowId(tokenPtr->tkwin),
	tokenPtr->fillGC, x + lineWidth, y + lineWidth, x + w - lineWidth,
	y + h - lineWidth);

    tokenPtr->status = TOKEN_STATUS_REJECT;
    /*
     *  Arrange for token window to disappear eventually.
     */
    tokenPtr->timer = Tk_CreateTimerHandler(1000, (Tcl_TimerProc *)HideToken,
	(ClientData)dndPtr);
    RaiseToken(tokenPtr);
}

/*
 * ------------------------------------------------------------------------
 *
 *  CreateToken --
 *
 *	Looks for a Source record in the hash table for drag&drop source
 *	widgets.  Creates a new record if the widget name is not already
 *	registered.  Returns a pointer to the desired record.
 *
 * ------------------------------------------------------------------------
 */
static void
DestroyToken(destroyData)
    DestroyData destroyData;
{
    Dnd *dndPtr = (Dnd *)destroyData;
    Token *tokenPtr = dndPtr->tokenPtr;

    if (tokenPtr != NULL) {
	if (tokenPtr->flags & TOKEN_REDRAW) {
	    Tk_CancelIdleCall(DisplayToken, (ClientData)dndPtr);
	}
	Tk_FreeOptions(tokenConfigSpecs, (char *)tokenPtr, dndPtr->display, 0);
	if (tokenPtr->timer) {
	    Tk_DeleteTimerHandler(tokenPtr->timer);
	}
	if (tokenPtr->fillGC != NULL) {
	    Tk_FreeGC(dndPtr->display, tokenPtr->fillGC);
	}
	if (tokenPtr->outlineGC != NULL) {
	    Tk_FreeGC(dndPtr->display, tokenPtr->outlineGC);
	}
	if (tokenPtr->tkwin != NULL) {
	    Tk_DeleteEventHandler(tokenPtr->tkwin, 
		ExposureMask | StructureNotifyMask, TokenEventProc, 
		  (ClientData)dndPtr);
	    Tk_DestroyWindow(tokenPtr->tkwin);
	}
	free((char *)tokenPtr);
    }
    dndPtr->tokenPtr = NULL;
}

/*
 * ------------------------------------------------------------------------
 *
 *  TokenEventProc --
 *
 *	Invoked by the Tk dispatcher to handle widget events.
 *	Manages redraws for the drag&drop token window.
 *
 * ------------------------------------------------------------------------
 */
static void
TokenEventProc(clientData, eventPtr)
    ClientData clientData;	/* data associated with widget */
    XEvent *eventPtr;		/* information about event */
{
    Dnd *dndPtr = (Dnd *)clientData;
    Token *tokenPtr = dndPtr->tokenPtr;

    if ((eventPtr->type == Expose) && (eventPtr->xexpose.count == 0)) {
	if (tokenPtr->tkwin != NULL) {
	    EventuallyRedrawToken(dndPtr);
	}
    } else if (eventPtr->type == DestroyNotify) {
	tokenPtr->tkwin = NULL;
	if (tokenPtr->flags & TOKEN_REDRAW) {
	    tokenPtr->flags &= ~TOKEN_REDRAW;
	    Tk_CancelIdleCall(DisplayToken, (ClientData)dndPtr);
	}
	Tcl_EventuallyFree((ClientData)dndPtr, DestroyToken);
    }
}

/*
 * ------------------------------------------------------------------------
 *
 *  CreateToken --
 *
 *	Looks for a Source record in the hash table for drag&drop source
 *	widgets.  Creates a new record if the widget name is not already
 *	registered.  Returns a pointer to the desired record.
 *
 * ------------------------------------------------------------------------
 */
static int
CreateToken(interp, dndPtr)
    Tcl_Interp *interp;
    Dnd *dndPtr;
{
    XSetWindowAttributes attrs;
    Tk_Window tkwin;
    unsigned int mask;
    Token *tokenPtr;

    tokenPtr = (Token *)calloc(1, sizeof(Token));
    assert(tokenPtr);
    tokenPtr->anchor = TK_ANCHOR_SE;
    tokenPtr->relief = TK_RELIEF_RAISED;
    tokenPtr->activeRelief = TK_RELIEF_SUNKEN;
    tokenPtr->borderWidth = tokenPtr->activeBorderWidth = 3;

    /* Create toplevel on parent's screen. */
    tkwin = Tk_CreateWindow(interp, dndPtr->tkwin, "dndtoken", "");
    if (tkwin == NULL) {
	free((char *)tokenPtr);
	return TCL_ERROR;
    }
    tokenPtr->tkwin = tkwin;
    Tk_SetClass(tkwin, "DndToken"); 
    Tk_CreateEventHandler(tkwin, ExposureMask | StructureNotifyMask,
	TokenEventProc, (ClientData)dndPtr);
    attrs.override_redirect = True;
    attrs.backing_store = WhenMapped;
    attrs.save_under = True;
    mask = CWOverrideRedirect | CWSaveUnder | CWBackingStore;
    Tk_ChangeWindowAttributes(tkwin, mask, &attrs);
    Tk_SetInternalBorder(tkwin, tokenPtr->borderWidth + 2);
    Tk_MakeWindowExist(tkwin);
    dndPtr->tokenPtr = tokenPtr;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  ConfigureToken --
 *
 *	Called to process an (argc,argv) list to configure (or
 *	reconfigure) a drag&drop source widget.
 *
 * ------------------------------------------------------------------------
 */
static int
ConfigureToken(interp, dndPtr, argc, argv, flags)
    Tcl_Interp *interp;		/* current interpreter */
    Dnd *dndPtr;		/* Drag&drop source widget record */
    int argc;			/* number of arguments */
    char **argv;		/* argument strings */
    int flags;			/* flags controlling interpretation */
{
    unsigned long gcMask;
    XGCValues gcValues;
    GC newGC;
    Token *tokenPtr = dndPtr->tokenPtr;

    Tk_MakeWindowExist(tokenPtr->tkwin);
    if (Tk_ConfigureWidget(interp, tokenPtr->tkwin, tokenConfigSpecs, argc, 
		argv, (char *)tokenPtr, flags) != TCL_OK) {
	return TCL_ERROR;
    }
    /*
     *  Set up the rejection outline GC for the token window...
     */
    gcValues.foreground = tokenPtr->outlineColor->pixel;
    gcValues.subwindow_mode = IncludeInferiors;
    gcValues.graphics_exposures = False;
    gcValues.line_style = LineSolid;
    gcValues.cap_style = CapButt;
    gcValues.join_style = JoinBevel;

    gcMask = GCForeground | GCSubwindowMode | GCLineStyle |
	GCCapStyle | GCJoinStyle | GCGraphicsExposures;
    newGC = Tk_GetGC(dndPtr->tkwin, gcMask, &gcValues);

    if (tokenPtr->outlineGC != NULL) {
	Tk_FreeGC(dndPtr->display, tokenPtr->outlineGC);
    }
    tokenPtr->outlineGC = newGC;

    /*
     *  Set up the rejection fill GC for the token window...
     */
    gcValues.foreground = tokenPtr->fillColor->pixel;
    if (tokenPtr->rejectStipple != None) {
	gcValues.stipple = tokenPtr->rejectStipple;
	gcValues.fill_style = FillStippled;
	gcMask |= GCStipple | GCFillStyle;
    }
    newGC = Tk_GetGC(dndPtr->tkwin, gcMask, &gcValues);

    if (tokenPtr->fillGC != NULL) {
	Tk_FreeGC(dndPtr->display, tokenPtr->fillGC);
    }
    tokenPtr->fillGC = newGC;


    /*
     *  Reset the border width in case it has changed...
     */
    Tk_SetInternalBorder(tokenPtr->tkwin, tokenPtr->borderWidth + 2);
    return TCL_OK;
}

static int
GetFormattedData(dndPtr, format, timestamp, dStrPtr)
    Dnd *dndPtr;
    char *format;
    int timestamp;
    Tcl_DString *dStrPtr;
{
    Tcl_Interp *interp = dndPtr->interp;
    Tcl_HashEntry *hPtr;
    char *formatCmd;
    SubstDescriptors subs[3];
    Tcl_DString savedResult;
    Tcl_DString dString;
    int result;

    /* Find the data converter for the prescribed format. */
    hPtr = Tcl_FindHashEntry(&(dndPtr->getDataTable), format);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "can't find format \"", format, 
	 "\" in source \"", Tk_PathName(dndPtr->tkwin), "\"", (char *)NULL);
	return TCL_ERROR;
    }
    formatCmd = (char *)Tcl_GetHashValue(hPtr);
    subs[0].letter = 't';
    subs[0].value = Blt_Itoa(timestamp);
    subs[1].letter = 'W';
    subs[1].value = Tk_PathName(dndPtr->tkwin);
    ExpandPercents(formatCmd, subs, 2, &dString);

    Tcl_DStringInit(&savedResult);
    /* Save the interpreter result. */
    Tcl_DStringGetResult(interp, &savedResult);	

    /* Invoke the converter, the interpreter result is the formatted data. */
    result = Tcl_GlobalEval(interp, Tcl_DStringValue(&dString));
    Tcl_DStringFree(&dString);

    if (result != TCL_OK) {
	Tcl_BackgroundError(interp);
	return TCL_ERROR;
    }
    Tcl_DStringInit(dStrPtr);
    Tcl_DStringGetResult(interp, dStrPtr);
    /* Restore the interpreter result. */
    Tcl_DStringResult(interp, &savedResult);
    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *
 *  DestroyDnd --
 *
 *	Free resources allocated for the drag&drop window.
 *
 * ------------------------------------------------------------------------
 */
static void
DestroyDnd(dndPtr)
    Dnd *dndPtr;
{
    Tcl_HashEntry *hPtr;
    Tcl_HashSearch cursor;
    char *cmd;

    Tk_FreeOptions(configSpecs, (char *)dndPtr, dndPtr->display, 0);
    Tk_DeleteGenericHandler(DndEventProc, (ClientData)dndPtr);
    for (hPtr = Tcl_FirstHashEntry(&(dndPtr->getDataTable), &cursor);
	hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	cmd = (char *)Tcl_GetHashValue(hPtr);
	if (cmd != NULL) {
	    free(cmd);
	}
    }
    Tcl_DeleteHashTable(&(dndPtr->getDataTable));

    for (hPtr = Tcl_FirstHashEntry(&(dndPtr->setDataTable), &cursor);
	hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	cmd = (char *)Tcl_GetHashValue(hPtr);
	if (cmd != NULL) {
	    free(cmd);
	}
    }
    Tcl_DeleteHashTable(&(dndPtr->setDataTable));
    if (dndPtr->rootPtr != NULL) {
	FreeWinfo(dndPtr->rootPtr);
    }
    if (dndPtr->cursor != None) {
	Tk_FreeCursor(dndPtr->display, dndPtr->cursor);
    }
    if (dndPtr->reqFormats != NULL) {
	free((char *)dndPtr->reqFormats);
    }
    if (dndPtr->matchingFormats != NULL) {
	free((char *)dndPtr->matchingFormats);
    }
    if (dndPtr->hashPtr != NULL) {
	Tcl_DeleteHashEntry(dndPtr->hashPtr);
    }
    if (dndPtr->tokenPtr != NULL) {
	DestroyToken((DestroyData)dndPtr);
    }
    if (dndPtr->tkwin != NULL) {
	XDeleteProperty(dndPtr->display, Tk_WindowId(dndPtr->tkwin),
			dndPtr->dataPtr->targetAtom);
	XDeleteProperty(dndPtr->display, Tk_WindowId(dndPtr->tkwin),
			dndPtr->dataPtr->commAtom);
    }
    free((char *)dndPtr);
}


/*
 * ------------------------------------------------------------------------
 *
 *  GetDnd --
 *
 *	Looks for a Source record in the hash table for drag&drop source
 *	widgets.  Returns a pointer to the desired record.
 *
 * ------------------------------------------------------------------------
 */
static int
GetDnd(clientData, interp, pathName, dndPtrPtr)
    ClientData clientData;
    Tcl_Interp *interp;
    char *pathName;		/* widget pathname for desired record */
    Dnd **dndPtrPtr;
{
    ThreadData *dataPtr = (ThreadData *)clientData;
    Tcl_HashEntry *hPtr;
    Tk_Window tkwin;

    tkwin = Tk_NameToWindow(interp, pathName, dataPtr->mainWindow);
    if (tkwin == NULL) {
	return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&(dataPtr->dndTable), (char *)tkwin);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "window \"", pathName,
	     "\" is not a drag&drop source/target", (char *)NULL);
	return TCL_ERROR;
    }
    *dndPtrPtr = (Dnd *)Tcl_GetHashValue(hPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  CreateDnd --
 *
 *	Looks for a Source record in the hash table for drag&drop source
 *	widgets.  Creates a new record if the widget name is not already
 *	registered.  Returns a pointer to the desired record.
 *
 * ------------------------------------------------------------------------
 */
static Dnd *
CreateDnd(interp, tkwin)
    Tcl_Interp *interp;
    Tk_Window tkwin;		/* widget for desired record */
{
    Dnd *dndPtr;

    dndPtr = (Dnd *) calloc(1, sizeof(Dnd));
    assert(dndPtr);
    dndPtr->interp = interp;
    dndPtr->display = Tk_Display(tkwin);
    dndPtr->tkwin = tkwin;
    Tk_MakeWindowExist(tkwin);
    Tcl_InitHashTable(&(dndPtr->setDataTable), TCL_STRING_KEYS);
    Tcl_InitHashTable(&(dndPtr->getDataTable), TCL_STRING_KEYS);
    Tk_CreateGenericHandler(DndEventProc, (ClientData)dndPtr);
    return dndPtr;
}

static int
ConfigureDnd(interp, dndPtr)
    Tcl_Interp *interp;
    Dnd *dndPtr;
{
    Tcl_CmdInfo cmdInfo;
    Tcl_DString dString;
    int button, result;

    if (!Tcl_GetCommandInfo(interp, "blt::DndInit", &cmdInfo)) {
	static char cmd[] = "source [file join $blt_library bltDnd.tcl]";
	/* 
	 * If the "DndInit" routine hasn't been sourced, do it now.
	 */
	if (Tcl_GlobalEval(interp, cmd) != TCL_OK) {
	    Tcl_AddErrorInfo(interp,
		     "\n    (while loading bindings for blt::drag&drop)");
	    return TCL_ERROR;
	}
    }
    if (dndPtr->isTarget) {
	if (!dndPtr->targetPropertyExists) {
	    AddTargetProperty(interp, dndPtr);
	}
    } else if (dndPtr->targetPropertyExists) {
	XDeleteProperty(dndPtr->display, Tk_WindowId(dndPtr->tkwin),
			dndPtr->dataPtr->targetAtom);
	dndPtr->targetPropertyExists = FALSE;
    }
    if (dndPtr->isSource) {
	/* Check the button binding for valid range (0 or 1-5) */
	if ((dndPtr->reqButton < 0) || (dndPtr->reqButton > 5)) {
	    Tcl_SetResult(interp, "button must be 1-5, or 0 for no bindings",
			  TCL_STATIC);
	    return TCL_ERROR;
	}
	button = dndPtr->reqButton;
    } else {
	button = 0;
    }
    Tcl_DStringInit(&dString);
    Blt_DStringAppendElements(&dString, "blt::DndInit", 
	Tk_PathName(dndPtr->tkwin), Blt_Itoa(button), (char *)NULL);
    result = Tcl_GlobalEval(interp, Tcl_DStringValue(&dString));
    Tcl_DStringFree(&dString);
    if (result != TCL_OK) {
	return TCL_ERROR;
    }
    return TCL_OK;
}


/*
 *----------------------------------------------------------------------
 *
 * RestrictProc --
 *
 *	This procedure filters incoming events when a "send" command
 *	is outstanding.  It defers all events except those containing
 *	send commands and results.
 *
 * Results:
 *	False is returned except for property-change events on a
 *	commWindow.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

/* ARGSUSED */
static Tk_RestrictAction
RestrictProc(clientData, eventPtr)
    ClientData clientData;		/* Drag-and-drop manager. */
    register XEvent *eventPtr;		/* Event that just arrived. */
{
    Dnd *dndPtr = (Dnd *)clientData;

    if (eventPtr->xproperty.window != Tk_WindowId(dndPtr->tkwin)) {
	return TK_PROCESS_EVENT; /* Event not in our window. */
    }
    if ((eventPtr->type == PropertyNotify) &&
	(eventPtr->xproperty.state == PropertyNewValue)) {
	return TK_PROCESS_EVENT; /* This is the one we want to process. */
    }
    if (eventPtr->type == Expose) {
	return TK_PROCESS_EVENT; /* Let expose events also get
				  * handled. */
    }
    return TK_DEFER_EVENT;	/* Defer everything else. */
}

/*
 *----------------------------------------------------------------------
 *
 * TimeoutProc --
 *
 *	Procedure called when the timer event elapses.  Used to wait
 *	between attempts checking for the designated window.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Sets a flag, indicating the timeout occurred.
 *
 *----------------------------------------------------------------------
 */
static void
TimeoutProc(clientData)
    ClientData clientData;
{
    int *statusPtr = (int *)clientData;

    /* An unusually long amount of time has elapsed since the drag
     * start message was sent.  Assume that the other party has died
     * and abort the operation.  */
#ifdef notdef
    fprintf(stderr, "TimeoutProc\n");
#endif
    *statusPtr = DROP_TIMEOUT;
}

#define WAIT_INTERVAL	2000	/* Twenty seconds. */

/*
 * ------------------------------------------------------------------------
 *
 *  TargetPropertyEventProc --
 *
 *	Invoked by the Tk dispatcher to handle widget events.
 *	Manages redraws for the drag&drop token window.
 *
 * ------------------------------------------------------------------------
 */
static void
TargetPropertyEventProc(clientData, eventPtr)
    ClientData clientData;	/* Data associated with transaction. */
    XEvent *eventPtr;		/* information about event */
{
    DropPending *pendingPtr = (DropPending *)clientData;
    char *data;
    int result, format;
    Atom typeAtom;
    unsigned long nItems, bytesAfter;

#ifdef notdef
    fprintf(stderr, "TargetPropertyEventProc\n");
#endif
    if ((eventPtr->type != PropertyNotify) ||
	(eventPtr->xproperty.atom != pendingPtr->commAtom) || 
	(eventPtr->xproperty.state != PropertyNewValue)) {
	return;
    }
    Tk_DeleteTimerHandler(pendingPtr->timerToken);
    data = NULL;
    result = XGetWindowProperty(
        eventPtr->xproperty.display,	/* Display of window. */
	eventPtr->xproperty.window,     /* Window holding the property. */
        eventPtr->xproperty.atom,	/* Name of property. */
        0,			/* Offset of data (for multiple reads). */
	pendingPtr->packetSize,	/* Maximum number of items to read. */
	False,			/* If true, delete the property. */
        XA_STRING,		/* Desired type of property. */
        &typeAtom,		/* (out) Actual type of the property. */
        &format,		/* (out) Actual format of the property. */
        &nItems,		/* (out) # of items in specified format. */
        &bytesAfter,		/* (out) # of bytes remaining to be read. */
	(unsigned char **)&data);
#ifdef notdef
    fprintf(stderr, 
	"TargetPropertyEventProc: result=%d, typeAtom=%d, format=%d, nItems=%d\n",
	    result, typeAtom, format, nItems);
#endif
    pendingPtr->status = DROP_FAIL;
    if ((result == Success) && (typeAtom == XA_STRING) && (format == 8)) {
	pendingPtr->status = DROP_OK;
#ifdef notdef
	fprintf(stderr, "data found is (%s)\n", data);
#endif
	Tcl_DStringAppend(&(pendingPtr->dString), data, -1);
	XFree(data);
	if (nItems == pendingPtr->packetSize) {
	    /* Normally, we'll receive the data in one chunk. But if
	     * more are required, reset the timer and go back into the 
	     * wait loop again. */
	    pendingPtr->timerToken = Tk_CreateTimerHandler(WAIT_INTERVAL, 
		TimeoutProc, (ClientData)&(pendingPtr->status));
	    pendingPtr->status = DROP_CONTINUE;
	}
    } 
    /* Set an empty, zero-length value on the source's property. This
     * acts as a handshake, indicating that the target received the
     * latest chunk. */
#ifdef notdef
    fprintf(stderr, "TargetPropertyEventProc: set response property\n");
#endif
    XChangeProperty(pendingPtr->display, pendingPtr->window, 
	pendingPtr->commAtom, XA_STRING, 8, PropModeReplace, 
	(unsigned char *)"", 0);
}

#ifdef HAVE_XDND

static int 
XDndSelectionProc(clientData, interp, portion)
    ClientData clientData;
    Tcl_Interp *interp;
    char *portion;
{
    DropPending *pendingPtr = (DropPending *)clientData;

    Tcl_DStringAppend(&(pendingPtr->dString), portion, -1);
#ifdef notdef
    fprintf(stderr, "-> XDndGetSelectionProc\n");
#endif
    return TCL_OK;
}

#endif /* HAVE_XDND */

static void
CompleteDataTransaction(dndPtr, format, pendingPtr)
    Dnd *dndPtr;
    char *format;
    DropPending *pendingPtr;
{
    ThreadData *dataPtr = dndPtr->dataPtr;
    Tk_Window tkwin;
    Atom formatAtom;

#ifdef notdef
    fprintf(stderr, "-> CompleteDataTransaction\n");
#endif
    /* Check if the source is local to the application. */
    tkwin = Tk_IdToWindow(dndPtr->display, pendingPtr->window);
    if (tkwin != NULL) {
	Tcl_HashEntry *hPtr;

	hPtr = Tcl_FindHashEntry(&(dndPtr->dataPtr->dndTable), (char *)tkwin);
	if (hPtr != NULL) {
	    Dnd *srcPtr;

	    srcPtr = (Dnd *)Tcl_GetHashValue(hPtr);
	    GetFormattedData(srcPtr, format, pendingPtr->timestamp, 
		&(pendingPtr->dString));
	}
	return;
    }

    formatAtom = XInternAtom(pendingPtr->display, format, False);

    if (pendingPtr->protocol == PROTO_XDND) { 
#ifdef HAVE_XDND
	if (Tk_GetSelection(dndPtr->interp, dndPtr->tkwin, 
		dataPtr->XdndSelectionAtom, formatAtom, XDndSelectionProc, 
		(ClientData)pendingPtr) != TCL_OK) {
	    pendingPtr->status = DROP_FAIL;
	}
#endif
	pendingPtr->status = DROP_OK;
    } else {
	Tk_RestrictProc *prevProc;
	ClientData prevArg;

	SendClientMsg(pendingPtr->display, pendingPtr->window, dataPtr->mesgAtom,
	      DROP_START, Tk_WindowId(dndPtr->tkwin), pendingPtr->timestamp, 
	      formatAtom, pendingPtr->commAtom);
	pendingPtr->commAtom = dndPtr->dataPtr->commAtom;
	pendingPtr->status = DROP_CONTINUE;
	pendingPtr->display = dndPtr->display;
	prevProc = Tk_RestrictEvents(RestrictProc, (ClientData)dndPtr, &prevArg);
	Tk_CreateEventHandler(dndPtr->tkwin, PropertyChangeMask, 
		TargetPropertyEventProc, (ClientData)pendingPtr);
	pendingPtr->timerToken = Tk_CreateTimerHandler(WAIT_INTERVAL, 
	       TimeoutProc, (ClientData)&(pendingPtr->status));
	/*  
	 * ----------------------------------------------------------
	 *
	 * Enter a loop processing X events until the all the data is
	 * received or the source is declared to be dead (i.e. we
	 * timeout).  While waiting for a result, restrict handling to
	 * just property-related events so that the transfer is
	 * synchronous with respect to other events in the widget.
	 *
	 * ---------------------------------------------------------- 
	 */
	while (pendingPtr->status == DROP_CONTINUE) { 
	    /* Wait for property event. */
	    Tcl_DoOneEvent(TCL_ALL_EVENTS);
	}
	Tk_RestrictEvents(prevProc, prevArg, &prevArg);
	Tk_DeleteTimerHandler(pendingPtr->timerToken);
	Tk_DeleteEventHandler(dndPtr->tkwin, PropertyChangeMask, 
	      TargetPropertyEventProc, (ClientData)pendingPtr);
    }
#ifdef notdef
    fprintf(stderr, "<- CompleteDataTransaction\n");
#endif
}

/*
 * ------------------------------------------------------------------------
 *
 *  SourcePropertyEventProc --
 *
 *	Invoked by the Tk dispatcher when a PropertyNotify event occurs
 *	on the source window.  The event acts as a handshake between the
 *	target and the source.  The source acknowledges the target has 
 *	received the last packet of data and sends the next packet.  
 *
 *	Note a special case.  If the data is divisible by the packetsize,
 *	then an extra zero-length packet is sent to mark the end of the
 *	data.  A packetsize length packet indicates more is to follow.
 *
 *	Normally the property is empty (zero-length).  But if an
 *	errored occurred on the target, it will contain the error
 *	message.
 *
 * ------------------------------------------------------------------------ 
 */
static void
SourcePropertyEventProc(clientData, eventPtr)
    ClientData clientData;	/* data associated with widget */
    XEvent *eventPtr;		/* information about event */
{
    DropPending *pendingPtr = (DropPending *)clientData;
    char *data;
    int result, format;
    Atom typeAtom;
    unsigned long nItems, bytesAfter;
    int size, bytesLeft;
    unsigned char *p;

#ifdef notdef
    fprintf(stderr, "-> SourcePropertyEventProc\n");
#endif
    if ((eventPtr->xproperty.atom != pendingPtr->commAtom)
	|| (eventPtr->xproperty.state != PropertyNewValue)) {
	return;
    }
    Tk_DeleteTimerHandler(pendingPtr->timerToken);
    data = NULL;
    result = XGetWindowProperty(
        eventPtr->xproperty.display,	/* Display of window. */
	eventPtr->xproperty.window,     /* Window holding the property. */
        eventPtr->xproperty.atom,	/* Name of property. */
        0,			/* Offset of data (for multiple reads). */
	pendingPtr->packetSize,	/* Maximum number of items to read. */
	True,			/* If true, delete the property. */
        XA_STRING,		/* Desired type of property. */
        &typeAtom,		/* (out) Actual type of the property. */
        &format,		/* (out) Actual format of the property. */
        &nItems,		/* (out) # of items in specified format. */
        &bytesAfter,		/* (out) # of bytes remaining to be read. */
	(unsigned char **)&data);

    if ((result != Success) || (typeAtom != XA_STRING) || (format != 8)) {
	pendingPtr->status = DROP_FAIL;
#ifdef notdef
    fprintf(stderr, "<- SourcePropertyEventProc: wrong format\n");
#endif
	return;			/* Wrong data format. */
    }
    if (nItems > 0) {
	pendingPtr->status = DROP_FAIL;
	Tcl_DStringFree(&(pendingPtr->dString));
	Tcl_DStringAppend(&(pendingPtr->dString), data, -1);
	XFree(data);
#ifdef notdef
    fprintf(stderr, "<- SourcePropertyEventProc: error\n");
#endif
	return;			/* Error occurred on target. */
    }    
    bytesLeft = Tcl_DStringLength(&(pendingPtr->dString)) - pendingPtr->offset;
    if (bytesLeft <= 0) {
#ifdef notdef
	fprintf(stderr, "<- SourcePropertyEventProc: done\n");
#endif
	pendingPtr->status = DROP_OK;
	size = 0;
    } else {
	size = MIN(bytesLeft, pendingPtr->packetSize);
	pendingPtr->status = DROP_CONTINUE;
    }
    p = (unsigned char *)Tcl_DStringValue(&(pendingPtr->dString)) + 
	pendingPtr->offset;
    XChangeProperty(pendingPtr->display, pendingPtr->window, 
	pendingPtr->commAtom, XA_STRING, 8, PropModeReplace, p, size);
    pendingPtr->offset += size;
    pendingPtr->timerToken = Tk_CreateTimerHandler(WAIT_INTERVAL, 
	   TimeoutProc, (ClientData)&(pendingPtr->status));
#ifdef notdef
    fprintf(stderr, "<- SourcePropertyEventProc\n");
#endif
}


static void
SendDataToTarget(dndPtr, pendingPtr)
    Dnd *dndPtr;
    DropPending *pendingPtr;
{
    int size;
    Tk_RestrictProc *prevProc;
    ClientData prevArg;

#ifdef notdef
    fprintf(stderr, "-> SendDataToTarget\n");
#endif
    Tk_CreateEventHandler(dndPtr->tkwin, PropertyChangeMask, 
	SourcePropertyEventProc, (ClientData)pendingPtr);
    pendingPtr->timerToken = Tk_CreateTimerHandler(WAIT_INTERVAL, TimeoutProc, 
	       (ClientData)&(pendingPtr->status));
    size = MIN(Tcl_DStringLength(&(pendingPtr->dString)), 
	pendingPtr->packetSize);

    prevProc = Tk_RestrictEvents(RestrictProc, (ClientData)dndPtr, &prevArg);

    /* 
     * Setting the property starts the process.  The target will
     * see the PropertyChange event and respond accordingly.  
     */
    XChangeProperty(dndPtr->display, pendingPtr->window, 
	pendingPtr->commAtom, XA_STRING, 8, PropModeReplace, 
	(unsigned char *)Tcl_DStringValue(&(pendingPtr->dString)), size);
    pendingPtr->offset += size;

    /*
     * Enter a loop processing X events until the result comes
     * in or the target is declared to be dead.  While waiting
     * for a result, look only at property-related events so that
     * the handshake is synchronous with respect to other events in
     * the application.
     */
    pendingPtr->status = DROP_CONTINUE;
    while (pendingPtr->status == DROP_CONTINUE) {
	/* Wait for the property change event. */
	Tcl_DoOneEvent(TCL_ALL_EVENTS);
    }
    Tk_RestrictEvents(prevProc, prevArg, &prevArg);
    Tk_DeleteTimerHandler(pendingPtr->timerToken);
    Tk_DeleteEventHandler(dndPtr->tkwin, PropertyChangeMask, 
	  SourcePropertyEventProc, (ClientData)pendingPtr);
#ifdef notdef
    fprintf(stderr, "<- SendDataToTarget\n");
#endif
}

static void
DoDrop(dndPtr, eventPtr)
    Dnd *dndPtr;
    XEvent *eventPtr;
{
    ThreadData *dataPtr = dndPtr->dataPtr;
    Tcl_Interp *interp = dndPtr->interp;
    struct DropRequest {
	int mesg;		/* DROP_RESPONSE message. */
	Window window;		/* Target window. */
	int timestamp;		/* Transaction timestamp. */
	Atom formatAtom;	/* Format requested. */
    } *dropPtr;
    char *format;
    DropPending pending;

    dropPtr = (struct DropRequest *)eventPtr->xclient.data.l;
    format = XGetAtomName(dndPtr->display, dropPtr->formatAtom);
#ifdef notdef
    fprintf(stderr, "DoDrop %s 0x%x\n", Tk_PathName(dndPtr->tkwin), 
	    dropPtr->window);
#endif
    if (GetFormattedData(dndPtr, format, dropPtr->timestamp, &(pending.dString)) 
	!= TCL_OK) {
	Tcl_BackgroundError(interp);
	/* Send empty string to break target's wait loop. */
	XChangeProperty(dndPtr->display, dropPtr->window, dataPtr->commAtom, 
		XA_STRING, 8, PropModeReplace, (unsigned char *)"", 0);
	return;
    } 
    pending.window = dropPtr->window;
    pending.display = dndPtr->display;
    pending.commAtom = dataPtr->commAtom;
    pending.offset = 0;
    pending.packetSize = GetMaxPropertySize(dndPtr->display);
    SendDataToTarget(dndPtr, &pending);
    Tcl_DStringFree(&(pending.dString));
#ifdef notdef
    fprintf(stderr, "<- DoDrop\n");
#endif
}

static void
DropFinished(dndPtr, eventPtr)
    Dnd *dndPtr;
    XEvent *eventPtr;
{
    Tcl_Interp *interp = dndPtr->interp;
    Tcl_DString dString, savedResult;
    int result;
    SubstDescriptors subs[3];
    struct DropResponse {
	int mesg;		/* DROP_RESPONSE message. */
	Window window;		/* Target window. */
	int timestamp;		/* Transaction timestamp. */
	int result;		/* Result of transaction. */
    } *dropPtr;

#ifdef notdef
    fprintf(stderr, "DropFinished\n");
#endif
    dropPtr = (struct DropResponse *)eventPtr->xclient.data.l;
    subs[0].letter = 'a';
    subs[0].value = NameOfAction(dropPtr->result);
    subs[1].letter = 'W';
    subs[1].value = Tk_PathName(dndPtr->tkwin);
    subs[2].letter = 't';
    subs[2].value = Blt_Itoa(dropPtr->timestamp);
    ExpandPercents(dndPtr->resultCmd, subs, 3, &dString);
    Tcl_DStringInit(&savedResult);
    Tcl_DStringGetResult(interp, &savedResult);
    result = Tcl_GlobalEval(interp, Tcl_DStringValue(&dString));
    Tcl_DStringFree(&dString);
    if (result != TCL_OK) {
	Tcl_BackgroundError(interp);
    }
    Tcl_DStringResult(interp, &savedResult);
}


static void
FreeFormats(dndPtr) 
    Dnd *dndPtr;
{
    if (dndPtr->matchingFormats != NULL) {
	free(dndPtr->matchingFormats);
	dndPtr->matchingFormats = NULL;
    }
    dndPtr->lastId = None;
}

static char *
GetSourceFormats(dndPtr, window, timestamp)
    Dnd *dndPtr;
    Window window;
    int timestamp;
{
    if (dndPtr->lastId != timestamp) {
	char *data;
	
	FreeFormats(dndPtr);
	data = GetProperty(dndPtr->display, window, 
		   dndPtr->dataPtr->formatsAtom);
	if (data != NULL) {
	    dndPtr->matchingFormats = strdup(data);
	    XFree(data);
	}
	dndPtr->lastId = timestamp;
    }
    if (dndPtr->matchingFormats == NULL) {
	return "";
    }
    return dndPtr->matchingFormats;
}
 

static int
InvokeCallback(dndPtr, cmd, x, y, formats, button, keyState)
    Dnd *dndPtr;
    char *cmd;
    int x, y;
    char *formats;
    int button;
    int keyState;
{
    Tcl_DString dString, savedResult;
    Tcl_Interp *interp = dndPtr->interp;
    int result;

    Tcl_DStringInit(&dString);
    Tcl_DStringAppendElement(&dString, cmd);
    Tcl_DStringAppendElement(&dString, Tk_PathName(dndPtr->tkwin));
    x -= Blt_RootX(dndPtr->tkwin); /* Send coordinates relative to target. */
    y -= Blt_RootY(dndPtr->tkwin);
    Tcl_DStringAppendElement(&dString, "x");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(x));
    Tcl_DStringAppendElement(&dString, "y");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(y));
    Tcl_DStringAppendElement(&dString, "formats");
    if (formats == NULL) {
	formats = "";
    }
    Tcl_DStringAppendElement(&dString, formats);
    Tcl_DStringAppendElement(&dString, "button");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(button));
    Tcl_DStringAppendElement(&dString, "state");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(keyState));
    Tcl_Preserve(interp);
    Tcl_DStringInit(&savedResult);
    Tcl_DStringGetResult(interp, &savedResult);
    result = Tcl_GlobalEval(interp, Tcl_DStringValue(&dString));
    Tcl_DStringFree(&dString);
    if (result == TCL_OK) {
	result = GetDragResult(interp, Tcl_GetStringResult(interp));
    } else {
	result = DRAG_CANCEL;
	Tcl_BackgroundError(interp);
    }
    Tcl_DStringResult(interp, &savedResult);
    Tcl_Release(interp);
    return result;
}

/* 
 * ------------------------------------------------------------------------
 *
 *  AcceptDrop --
 *	
 *	Invokes a Tcl procedure to handle the target's side of the
 *	drop.  A Tcl procedure is invoked, either one designated for 
 *	this target by the user (-ondrop) or a default Tcl procedure. 
 *	It is passed the following arguments:
 *
 *		widget		The path name of the target. 
 *		x		X-coordinate of the mouse relative to the 
 *				widget.
 *		y		Y-coordinate of the mouse relative to the 
 *				widget.
 *		formats		A list of data formats acceptable to both
 *				the source and target.
 *		button		Button pressed.
 *		state		Key state.
 *		action		Requested action from source.
 *
 *	If the Tcl procedure returns "cancel", this indicates that the drop was
 *	not accepted by the target and the reject symbol should be displayed.
 *	Otherwise one of the following strings may be recognized:
 *
 *		"cancel"	Drop was canceled.
 *		"copy"		Source data has been successfully copied.
 *		"link"		Target has made a link to the data. It's 
 *				Ok for the source to remove it's association
 *				with the data, but not to delete the data
 *				itself.
 *		"move"		Source data has been successfully copied,
 *				it's Ok for the source to delete its
 *				association with the data and the data itself.
 *
 *	The result is relayed back to the source via another client message.
 *	The source may or may not be waiting for the result.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	A Tcl procedure is invoked in the target to handle the drop event.
 *	The result of the drop is sent (via another ClientMessage) to the
 *	source.
 *
 * ------------------------------------------------------------------------
 */
static int
AcceptDrop(dndPtr, x, y, formats, button, keyState) 
    Dnd *dndPtr;		/* Target where the drop event occurred. */
    int x, y;
    char *formats;
    int button, keyState;
{
    Tcl_Interp *interp = dndPtr->interp;
    char *cmd;
    Tcl_DString dString, savedResult;
    int result;
    
    if (dndPtr->leaveCmd != NULL) {
	InvokeCallback(dndPtr, dndPtr->leaveCmd, x, y, formats, button, 
	       keyState);
    }
    cmd = dndPtr->dropCmd;
    if (cmd == NULL) {
	cmd = "blt::DndStdDrop";
    }
    Tcl_DStringInit(&dString);
    Tcl_DStringAppendElement(&dString, cmd);
    Tcl_DStringAppendElement(&dString, Tk_PathName(dndPtr->tkwin));
    x -= Blt_RootX(dndPtr->tkwin);
    y -= Blt_RootY(dndPtr->tkwin);
    Tcl_DStringAppendElement(&dString, "x");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(x));
    Tcl_DStringAppendElement(&dString, "y");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(y));
    Tcl_DStringAppendElement(&dString, "formats");
    Tcl_DStringAppendElement(&dString, formats);
    Tcl_DStringAppendElement(&dString, "button");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(button));
    Tcl_DStringAppendElement(&dString, "state");
    Tcl_DStringAppendElement(&dString, Blt_Itoa(keyState));
    Tcl_Preserve(interp);
    Tcl_DStringInit(&savedResult);
    Tcl_DStringGetResult(interp, &savedResult);
    result = Tcl_GlobalEval(interp, Tcl_DStringValue(&dString));
    Tcl_DStringFree(&dString);
    if (result == TCL_OK) {
	result = GetAction(Tcl_GetStringResult(interp));
    } else {
	result = ACTION_CANCEL;
	Tcl_BackgroundError(interp);
    }
    Tcl_DStringResult(interp, &savedResult);
    Tcl_Release(interp);
    return result;
}

/* 
 * ------------------------------------------------------------------------
 *
 *  HandleDropEvent --
 *	
 *	Invokes a Tcl procedure to handle the target's side of the
 *	drop.  This routine is triggered via a client message from the
 *	drag source indicating that the token was dropped over this
 *	target. The fields of the incoming message are:
 *
 *		data.l[0]	Message type.
 *		data.l[1]	Window Id of the source.
 *		data.l[2]	Screen X-coordinate of the pointer.
 *		data.l[3]	Screen Y-coordinate of the pointer.
 *		data.l[4]	Id of the drag&drop transaction.
 *
 *	A Tcl procedure is invoked, either one designated for this 
 *	target by the user (-ondrop) or a default Tcl procedure. It
 *	is passed the following arguments:
 *
 *		widget		The path name of the target. 
 *		x		X-coordinate of the mouse relative to the 
 *				widget.
 *		y		Y-coordinate of the mouse relative to the 
 *				widget.
 *		formats		A list of data formats acceptable to both
 *				the source and target.
 *
 *	If the Tcl procedure returns "cancel", this indicates that the drop was
 *	not accepted by the target and the reject symbol should be displayed.
 *	Otherwise one of the following strings may be recognized:
 *
 *		"cancel"	Drop was canceled.
 *		"copy"		Source data has been successfully copied.
 *		"link"		Target has made a link to the data. It's 
 *				Ok for the source to remove it's association
 *				with the data, but not to delete the data
 *				itself.
 *		"move"		Source data has been successfully copied,
 *				it's Ok for the source to delete its
 *				association with the data and the data itself.
 *
 *	The result is relayed back to the source via another client message.
 *	The source may or may not be waiting for the result.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	A Tcl procedure is invoked in the target to handle the drop event.
 *	The result of the drop is sent (via another ClientMessage) to the
 *	source.
 *
 * ------------------------------------------------------------------------
 */
static void
HandleDropEvent(dndPtr, eventPtr) 
    Dnd *dndPtr;		/* Target where the drop event occurred. */
    XEvent *eventPtr;		/* Message sent from the drag source. */
{
    int button, keyState;
    int x, y;
    char *formats;
    int result;
    struct DropInfo {
	int mesg;		/* DROP_START message. */
	Window window;		/* Source window. */
	int timestamp;		/* Transaction timestamp. */
	int point;		/* Root X-Y coordinate of pointer. */
	int flags;		/* Button/keystate information. */
    } *dropPtr;
    DropPending pending;

    dropPtr = (struct DropInfo *)eventPtr->xclient.data.l;
    UNPACK(dropPtr->point, x, y);
    UNPACK(dropPtr->flags, button, keyState);

    /* Set up temporary bookkeeping for the drop transaction */
    memset (&pending, 0, sizeof(pending));
    pending.window = dropPtr->window;
    pending.display = eventPtr->xclient.display;
    pending.timestamp = dropPtr->timestamp;
    pending.protocol = PROTO_BLT;
    pending.packetSize = GetMaxPropertySize(pending.display);
    Tcl_DStringInit(&(pending.dString));

    formats = GetSourceFormats(dndPtr, dropPtr->window, dropPtr->timestamp);

    dndPtr->pendingPtr = &pending;
    result = AcceptDrop(dndPtr, x, y, formats, button, keyState);
    dndPtr->pendingPtr = NULL;

    /* Target-to-Source: Drop result message. */
    SendClientMsg(dndPtr->display, dropPtr->window, dndPtr->dataPtr->mesgAtom,
       DROP_RESPONSE, Tk_WindowId(dndPtr->tkwin), dropPtr->timestamp, result, 0);
    FreeFormats(dndPtr);
}

/* 
 * ------------------------------------------------------------------------
 *
 *  HandleDragEvent --
 *	
 *	Invokes one of 3 Tcl procedures to handle the target's side of 
 *	the drag operation.  This routine is triggered via a ClientMessage 
 *	from the drag source indicating that the token as either entered,
 *	moved, or left this target.  The source sends messages only if
 *	Tcl procedures on the target have been defined to watch the 
 *	events. The message_type field can be either 
 *
 *	  DRAG_ENTER	The mouse has entered the target.
 *	  DRAG_MOTION	The mouse has moved within the target.
 *	  DRAG_LEAVE	The mouse has left the target.
 *
 *	The data fields are as follows:
 *	  data.l[0]		Message type.
 *	  data.l[1]		Window Id of the source.
 *	  data.l[2]		Timestamp of the drag&drop transaction.
 *	  data.l[3]		Root X-Y coordinate of the pointer.
 *	  data.l[4]		Button and key state information.
 *
 *	For any of the 3 Tcl procedures, the following arguments
 *	are passed:
 *
 *	  widget		The path name of the target. 
 *	  x			X-coordinate of the mouse in the widget.
 *	  y			Y-coordinate of the mouse in the widget.
 *	  formats		A list of data formats acceptable to both
 *				the source and target.
 *
 *	If the Tcl procedure returns "cancel", this indicates that the drag 
 *	operation has been canceled and the reject symbol should be displayed.
 *	Otherwise it should return a boolean:
 *
 *	  true			Target will accept drop.
 *	  false			Target will not accept the drop.
 *
 *	The purpose of the Enter and Leave procedure is to allow the
 *	target to provide visual feedback that the drop can occur or not.
 *	The Motion procedure is for cases where the drop area is a smaller
 *	area within the target, such as a canvas item on a canvas. The 
 *	procedure can determine (based upon the X-Y coordinates) whether 
 *	the pointer is over the canvas item and return a value accordingly.
 *
 *	The result of the Tcl procedure is then relayed back to the 
 *	source by a ClientMessage.  
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	A Tcl procedure is invoked in the target to handle the drag event.
 *	The result of the drag is sent (via another ClientMessage) to the
 *	source.
 *
 * ------------------------------------------------------------------------
 */
static void
HandleDragEvent(dndPtr, eventPtr) 
    Dnd *dndPtr;		/* Target where the drag event occurred. */
    XEvent *eventPtr;		/* Message sent from the drag source. */
{
    char *cmd;
    int resp;
    int x, y;
    int button, keyState;
    char *formats;
    struct DragInfo {
	int mesg;		/* Drag-and-drop message type. */
	Window window;		/* Source window. */
	int timestamp;		/* Transaction timestamp. */
	int point;		/* Root X-Y coordinate of pointer. */
	int flags;		/* Button/keystate information. */
    } *dragPtr;

    dragPtr = (struct DragInfo *)eventPtr->xclient.data.l;

    cmd = NULL;
    switch (dragPtr->mesg) {
    case DRAG_ENTER:
	cmd = dndPtr->enterCmd;
	break;
    case DRAG_MOTION:
	cmd = dndPtr->motionCmd;
	break;
    case DRAG_LEAVE:
	cmd = dndPtr->leaveCmd;
	break;
    } 
    if (cmd == NULL) {
	return;			/* Nothing to do. */
    }
    UNPACK(dragPtr->point, x, y);
    UNPACK(dragPtr->flags, button, keyState);
    formats = GetSourceFormats(dndPtr, dragPtr->window, dragPtr->timestamp);
    resp = InvokeCallback(dndPtr, cmd, x, y, formats, button, keyState);

    /* Target-to-Source: Drag result message. */
    SendClientMsg(dndPtr->display, dragPtr->window, dndPtr->dataPtr->mesgAtom,
	DRAG_RESPONSE, Tk_WindowId(dndPtr->tkwin), dragPtr->timestamp, resp, 0);
}

/*
 * ------------------------------------------------------------------------
 *
 *  DndEventProc --
 *
 *	Invoked by Tk_HandleEvent whenever a DestroyNotify event is received
 *	on a registered drag&drop source widget.
 *
 * ------------------------------------------------------------------------
 */
static int
DndEventProc(clientData, eventPtr)
    ClientData clientData;	/* Drag&drop record. */
    XEvent *eventPtr;		/* Event description. */
{
    Dnd *dndPtr = (Dnd *)clientData;

    if (eventPtr->xany.window != Tk_WindowId(dndPtr->tkwin)) {
	return 0;
    }
    if (eventPtr->type == DestroyNotify) {
	dndPtr->tkwin = NULL;
	DestroyDnd(dndPtr);
	return 0;		/* Other handlers have to see this event too. */
    } else if (eventPtr->type == ButtonPress) {
	dndPtr->keyState = eventPtr->xbutton.state;
	dndPtr->button =  eventPtr->xbutton.button;
	return 0;
    } else if (eventPtr->type == ButtonRelease) {
	dndPtr->keyState = eventPtr->xbutton.state;
	dndPtr->button =  eventPtr->xbutton.button;
	return 0;
    } else if (eventPtr->type == MotionNotify) {
	dndPtr->keyState = eventPtr->xmotion.state;
	return 0;
    } else if ((eventPtr->type == ClientMessage) &&
	(eventPtr->xclient.message_type == dndPtr->dataPtr->mesgAtom)) {
	int result;

	switch((unsigned int)eventPtr->xclient.data.l[0]) {
	case DROP_START:
	    DoDrop(dndPtr, eventPtr);
	    return 1;
	    
	case DROP_RESPONSE:
	    result = eventPtr->xclient.data.l[MESG_INDEX_RESP];
	    if (result != DROP_OK) {
		dndPtr->tokenPtr->status = TOKEN_STATUS_REJECT;
		EventuallyRedrawToken(dndPtr);
	    } else {
		dndPtr->tokenPtr->nSteps = 10;
		FadeToken(dndPtr);
	    }
	    if (dndPtr->resultCmd != NULL) {
		DropFinished(dndPtr, eventPtr);
	    }
	    return 1;

	case DRAG_RESPONSE:
	    dndPtr->tokenPtr->status = eventPtr->xclient.data.l[MESG_INDEX_RESP];
	    ChangeToken(dndPtr);
	    return 1;

	case DROP_REQUEST:
	    HandleDropEvent(dndPtr, eventPtr);
	    return 1;

	case DRAG_ENTER:
	case DRAG_MOTION:
	case DRAG_LEAVE:
	    HandleDragEvent(dndPtr, eventPtr);
	    return 1;
	}
    }
    return 0;
}

static void
SendPointerMessage(dndPtr, eventType, windowPtr, x, y)
    Dnd *dndPtr;		/* Source drag&drop manager. */
    int eventType;		/* Type of event to relay. */
    Winfo *windowPtr;		/* Generic window information. */
    int x, y;			/* Root coordinates of mouse. */
{
    /* Source-to-Target: Pointer event messages. */
    SendClientMsg(
	dndPtr->display,	/* Display of recipient window. */
	windowPtr->window,	/* Recipient window. */
	dndPtr->dataPtr->mesgAtom, /* Message type. */
	eventType,		/* Data 1 */
	Tk_WindowId(dndPtr->tkwin), /* Data 2 */
	dndPtr->timestamp,	/* Data 3  */
	PACK(x, y),		/* Data 4 */
	PACK(dndPtr->button, dndPtr->keyState)); /* Data 5 */
    /* Don't wait the response. */
}

static void
RelayEnterEvent(dndPtr, windowPtr, x, y)
    Dnd *dndPtr;
    Winfo *windowPtr;
    int x, y;
{
    if ((windowPtr != NULL) && (windowPtr->eventFlags & WATCH_ENTER)) {
	SendPointerMessage(dndPtr, DRAG_ENTER, windowPtr, x, y);
    }
}

static void
RelayLeaveEvent(dndPtr, windowPtr, x, y)
    Dnd *dndPtr;
    Winfo *windowPtr;
    int x, y;
{ 
    if ((windowPtr != NULL) && (windowPtr->eventFlags & WATCH_LEAVE)) {
	SendPointerMessage(dndPtr, DRAG_LEAVE, windowPtr, x, y);
    }
}

static void
RelayMotionEvent(dndPtr, windowPtr, x, y)
    Dnd *dndPtr;
    Winfo *windowPtr;
    int x, y;
{
    if ((windowPtr != NULL) && (windowPtr->eventFlags & WATCH_MOTION)) {
	SendPointerMessage(dndPtr, DRAG_MOTION, windowPtr, x, y);
    }
}

static void
RelayDropEvent(dndPtr, windowPtr, x, y)
    Dnd *dndPtr;
    Winfo *windowPtr;
    int x, y;
{
    SendPointerMessage(dndPtr, DROP_REQUEST, windowPtr, x, y);
}

/*
 * ------------------------------------------------------------------------
 *
 *  FreeWinfo --
 *
 * ------------------------------------------------------------------------
 */
static void
FreeWinfo(windowPtr)
    Winfo *windowPtr;		/* window rep to be freed */
{
    Winfo *childPtr;
    Blt_ChainLink *linkPtr;

    for (linkPtr = Blt_ChainFirstLink(windowPtr->chainPtr); linkPtr != NULL;
	linkPtr = Blt_ChainNextLink(linkPtr)) {
	childPtr = (Winfo *) Blt_ChainGetValue(linkPtr);
	FreeWinfo(childPtr);	/* Recursively free children. */
    }
    if (windowPtr->matches != NULL) {
	free(windowPtr->matches);
    }
    Blt_ChainDestroy(windowPtr->chainPtr);
    free((char *)windowPtr);
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetWinfo --
 *
 *	Invoked during "drag" operations. Digs into the root window
 *	hierarchy and caches the window-related information.
 *	If the current point lies over an uninitialized window (i.e.
 *	one that already has an allocated Winfo structure, but has
 *	not been filled in yet), this routine is called to query 
 *	window coordinates.  If the window has any children, more 
 *	uninitialized Winfo structures are allocated.  Further queries 
 *	will cause these structures to be initialized in turn.
 *
 * ------------------------------------------------------------------------
 */
static void
GetWinfo(display, windowPtr)
    Display *display;
    Winfo *windowPtr;		/* window rep to be initialized */
{
    int visible;

    if (windowPtr->initialized) {
	return;
    }
    /* Query for the window coordinates.  */
    visible = GetWindowRegion(display, windowPtr->window, 
      &(windowPtr->x1), &(windowPtr->y1), &(windowPtr->x2), &(windowPtr->y2));
    if (visible) {
	Blt_ChainLink *linkPtr;
	Blt_Chain *chainPtr;
	Winfo *childPtr;

	/* Add offset from parent's origin to coordinates */
	if (windowPtr->parentPtr != NULL) {
	    windowPtr->x1 += windowPtr->parentPtr->x1;
	    windowPtr->y1 += windowPtr->parentPtr->y1;
	    windowPtr->x2 += windowPtr->parentPtr->x1;
	    windowPtr->y2 += windowPtr->parentPtr->y1;
	}
	/*
	 * Collect a list of child windows, sorted in z-order.  The
	 * topmost window will be first in the list.
	 */
	chainPtr = GetWindowZOrder(display, windowPtr->window);

	/* Add and initialize extra slots if needed. */
	for (linkPtr = Blt_ChainFirstLink(chainPtr); linkPtr != NULL;
	    linkPtr = Blt_ChainNextLink(linkPtr)) {
	    childPtr = (Winfo *) calloc(1, sizeof(Winfo));
	    assert(childPtr);
	    childPtr->initialized = FALSE;
	    childPtr->window = (Window)Blt_ChainGetValue(linkPtr);
	    childPtr->parentPtr = windowPtr;
	    Blt_ChainSetValue(linkPtr, (ClientData)childPtr);
	}
	windowPtr->chainPtr = chainPtr;
    } else {
	/* If it's not viewable don't bother doing anything else. */
	windowPtr->x1 = windowPtr->y1 = windowPtr->x2 = windowPtr->y2 = -1;
	windowPtr->chainPtr = NULL;
    }
    windowPtr->initialized = TRUE;
}

/*
 * ------------------------------------------------------------------------
 *
 *  InitRoot --
 *
 *	Invoked at the start of a "drag" operation to capture the
 *	positions of all windows on the current root.  Queries the
 *	entire window hierarchy and determines the placement of each
 *	window.  Queries the "BltDndTarget" property info where
 *	appropriate.  This information is used during the drag
 *	operation to determine when the drag&drop token is over a
 *	valid drag&drop target.
 *
 *  Results:
 *	Returns the record for the root window, which contains records
 *	for all other windows as children.
 *
 * ------------------------------------------------------------------------
 */
static Winfo *
InitRoot(dndPtr)
    Dnd *dndPtr;
{
    Winfo *rootPtr;

    rootPtr = (Winfo *) calloc(1, sizeof(Winfo));
    assert(rootPtr);
    rootPtr->window = DefaultRootWindow(dndPtr->display);
    dndPtr->windowPtr = NULL;
    GetWinfo(dndPtr->display, rootPtr);
    return rootPtr;
}


static int
ParseProperty(interp, dndPtr, windowPtr, data)
    Tcl_Interp *interp;
    Dnd *dndPtr;
    Winfo *windowPtr;
    char *data;
{
    int nElems;
    char **elemArr;
    int eventFlags;
    Tcl_DString dString;
    int count;
    register int i;
    
    if (Tcl_SplitList(interp, data, &nElems, &elemArr) != TCL_OK) {
	return TCL_ERROR;		/* Malformed property list. */
    }
    if (nElems < 1) {
	Tcl_AppendResult(interp, "Malformed property \"", data, "\"", 
			 (char *)NULL);
	goto error;
    }
    if (Tcl_GetInt(interp, elemArr[PROP_WATCH_FLAGS], &eventFlags) != TCL_OK) {
	goto error;
    }

    /* target flags, type1, type2, ... */
    /*
     * The target property contains a list of possible formats.
     * Compare this with what formats the source is willing to
     * convert and compress the list down to just the matching
     * formats.  It's up to the target to request the specific 
     * type (or types) that it wants.
     */
    count = 0;
    Tcl_DStringInit(&dString);
    if (dndPtr->reqFormats == NULL) {
	Tcl_HashEntry *hPtr;
	Tcl_HashSearch cursor;
	char *fmt;

	for (i = 1; i < nElems; i++) {
	    for(hPtr = Tcl_FirstHashEntry(&(dndPtr->getDataTable), &cursor);
		hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
		fmt = Tcl_GetHashKey(&(dndPtr->getDataTable), hPtr);
		if ((*fmt == elemArr[i][0]) && (strcmp(fmt, elemArr[i]) == 0)) {
		    Tcl_DStringAppendElement(&dString, elemArr[i]);
		    count++;
		    break;
		}
	    }
	}
    } else {
	register char **s;

	for (i = 1; i < nElems; i++) {
	    for (s = dndPtr->reqFormats; *s != NULL; s++) {
		if ((**s == elemArr[i][0]) && (strcmp(*s, elemArr[i]) == 0)) {
		    Tcl_DStringAppendElement(&dString, elemArr[i]);
		    count++;
		}
	    }
	}
    }
    if (count == 0) {
#ifdef notdef
	fprintf(stderr, "source/target mismatch: No matching types\n");
#endif
	return TCL_BREAK;
    } 
    if (eventFlags != 0) {
	SetProperty(dndPtr->tkwin, dndPtr->dataPtr->formatsAtom, 
		Tcl_DStringValue(&dString));
	windowPtr->matches = NULL;
    } else {
	windowPtr->matches = strdup(Tcl_DStringValue(&dString));
    }
    Tcl_DStringFree(&dString);	
    windowPtr->eventFlags = eventFlags;
    return TCL_OK;
 error:
    free((char *)elemArr);
    return TCL_ERROR;
}

/*
 * ------------------------------------------------------------------------
 *
 *  OverTarget --
 *
 *      Checks to see if a compatible drag&drop target exists at the
 *      given position.  A target is "compatible" if it is a drag&drop
 *      window, and if it has a handler that is compatible with the
 *      current source window.
 *
 *  Results:
 *	Returns a pointer to a structure describing the target, or NULL
 *	if no compatible target is found.
 *
 * ------------------------------------------------------------------------
 */
static Winfo *
OverTarget(dndPtr)
    Dnd *dndPtr;		/* drag&drop source window */
{
    Tcl_Interp *interp = dndPtr->interp;
    int x, y;
    int vx, vy;
    int dummy;
    Winfo *windowPtr;

    /* 
     * If no window info has been been gathered yet for this target,
     * then abort this call.  This probably means that the token is
     * moved before it has been properly built.  
     */
    if (dndPtr->rootPtr == NULL) {
	fprintf(stderr, "Not initialized\n");
	return NULL;
    }
    /* Adjust current location for virtual root windows.  */
    Tk_GetVRootGeometry(dndPtr->tkwin, &vx, &vy, &dummy, &dummy);
    x = dndPtr->x + vx;
    y = dndPtr->y + vy;

    windowPtr = FindTopWindow(dndPtr, x, y);
    if (windowPtr == NULL) {
	return NULL;		/* Not over a window. */
    }
    if ((!dndPtr->selfTarget) && 
	(Tk_WindowId(dndPtr->tkwin) == windowPtr->window)) {
	return NULL;		/* If the self-target flag isn't set,
				 *  don't allow the source window to
				 *  drop onto itself.  */
    }
    if (!windowPtr->lookedForProperty) {
	char *data;
	int result;

	windowPtr->lookedForProperty = TRUE;
	/* See if this window has a "BltDndTarget" property. */
	data = GetProperty(dndPtr->display, windowPtr->window, 
		dndPtr->dataPtr->targetAtom);
	if (data == NULL) {
#ifdef notdef
	    fprintf(stderr, "No property on 0x%x\n", windowPtr->window);
#endif
	    return NULL;		/* No such property on window. */
	}
	result = ParseProperty(interp, dndPtr, windowPtr, data);
	XFree(data);
	if (result == TCL_BREAK) {
#ifdef notdef
	    fprintf(stderr, "No matching formats\n");
#endif
	    return NULL;
	}
	if (result != TCL_OK) {
	    Tcl_BackgroundError(interp);
	    return NULL;		/* Malformed property list. */
	} 
	windowPtr->isTarget = TRUE;
    }
    if (!windowPtr->isTarget) {
	return NULL;
    }
    return windowPtr;

}

/*
 * ------------------------------------------------------------------------
 *
 *  AddTargetProperty --
 *
 *	Attaches a drag&drop property to the given target window.
 *	This property allows us to recognize the window later as a
 *	valid target. It also stores important information including
 *	the interpreter managing the target and the pathname of the
 *	target window.  Usually this routine is called when the target
 *	is first registered or first exposed (so that the X-window
 *	really exists).
 *
 * ------------------------------------------------------------------------
 */
static void
AddTargetProperty(interp, dndPtr)
    Tcl_Interp *interp;
    Dnd *dndPtr;		/* drag&drop target window data */
{
    Tcl_DString dString;
    Tcl_HashEntry *hPtr;
    unsigned int eventFlags;
    Tcl_HashSearch cursor;
    char *fmt;
    char string[200];

    Tcl_DStringInit(&dString);
    /*
     * Each target window's dnd property contains
     *
     *	1. Mouse event flags.
     *  2. List of all the data types that can be handled. If none
     *     are listed, then all can be handled.
     */
    eventFlags = 0;
    if (dndPtr->enterCmd != NULL) {
	eventFlags |= WATCH_ENTER;
    }
    if (dndPtr->leaveCmd != NULL) {
	eventFlags |= WATCH_LEAVE;
    }
    if (dndPtr->motionCmd != NULL) {
	eventFlags |= WATCH_MOTION;
    }
    sprintf(string, "0x%x", eventFlags);
    Tcl_DStringAppendElement(&dString, string);
    for (hPtr = Tcl_FirstHashEntry(&(dndPtr->setDataTable), &cursor);
	hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	fmt = Tcl_GetHashKey(&(dndPtr->setDataTable), hPtr);
	Tcl_DStringAppendElement(&dString, fmt);
    }
    SetProperty(dndPtr->tkwin, dndPtr->dataPtr->targetAtom, 
	Tcl_DStringValue(&dString));
    dndPtr->targetPropertyExists = TRUE;
    Tcl_DStringFree(&dString);
}

/*
 * ------------------------------------------------------------------------
 *
 *  ExpandPercents --
 *
 *	Expands all percent substitutions found in the input "str"
 *	that match specifications in the "subs" list.  Any percent
 *	field that is not found in the "subs" list is left alone.
 *	Returns a string that remains valid until the next call to
 *	this routine.
 *
 * ------------------------------------------------------------------------
 */
static void
ExpandPercents(string, subsArr, nSubs, dStrPtr)
    char *string;		/* Incoming command string */
    SubstDescriptors *subsArr;	/* Array of known substitutions */
    int nSubs;			/* Number of elements in subs array */
    Tcl_DString *dStrPtr;
{
    register char *chunk, *p;
    char letter;
    char percentSign;
    int i;

    /*
     *  Scan through the copy of the input string, look for
     *  the next '%' character, and try to make the substitution.
     *  Continue doing this to the end of the string.
     */
    Tcl_DStringInit(dStrPtr);
    chunk = p = string;
    while ((p = strchr(p, '%')) != NULL) {

	/* Copy up to the percent sign.  Repair the string afterwards */
	percentSign = *p;
	*p = '\0';
	Tcl_DStringAppend(dStrPtr, chunk, -1);
	*p = percentSign;

	/* Search for a matching substition rule */
	letter = *(p + 1);
	for (i = 0; i < nSubs; i++) {
	    if (subsArr[i].letter == letter) {
		break;
	    }
	}
	if (i < nSubs) {
	    /* Make the substitution */
	    Tcl_DStringAppend(dStrPtr, subsArr[i].value, -1);
	} else {
	    /* Copy in the %letter verbatim */
	    char verbatim[3];

	    verbatim[0] = '%';
	    verbatim[1] = letter;
	    verbatim[2] = '\0';
	    Tcl_DStringAppend(dStrPtr, verbatim, -1);
	}
	p += 2;			/* Skip % + letter */
	if (letter == '\0') {
	    p += 1;		/* Premature % substitution (end of string) */
	}
	chunk = p;
    }
    /* Pick up last chunk if substition wasn't the last thing in the string. */
    if (*chunk != '\0') {
	Tcl_DStringAppend(dStrPtr, chunk, -1);
    }
}

static int
DragInit(dndPtr, x, y, timestamp)
    Dnd *dndPtr;
    int x, y;
    int timestamp;
{
    Token *tokenPtr = dndPtr->tokenPtr;

    if (dndPtr->rootPtr != NULL) {
	FreeWinfo(dndPtr->rootPtr);
    }

    dndPtr->rootPtr = InitRoot(dndPtr); /* Reset information cache. */ 
    dndPtr->timestamp = timestamp;
    dndPtr->canceled = FALSE;
    dndPtr->x = x;	/* Save current location. */
    dndPtr->y = y;

    if (dndPtr->packageCmd != NULL) {
	Tcl_DString dString;
	SubstDescriptors subs[3];
	int status;

	/* Execute command to initialize the token window.  */
	subs[0].letter = 'W';
	subs[0].value = Tk_PathName(dndPtr->tkwin);
	subs[1].letter = 't';
	subs[1].value = Tk_PathName(tokenPtr->tkwin);
	subs[2].letter = '#';
	subs[2].value = Blt_Itoa(dndPtr->timestamp);
	
	dndPtr->pkgCmdInProgress = TRUE;
	ExpandPercents(dndPtr->packageCmd, subs, 3, &dString);
	status = Tcl_Eval(dndPtr->interp, Tcl_DStringValue(&dString));
	Tcl_DStringFree(&dString);
	dndPtr->pkgCmdInProgress = FALSE;
	if (status != TCL_OK) {
	    return TCL_ERROR;
	}
    }

    if (dndPtr->cursor != None) {
	Tk_Cursor cursor;
	
	/* Save the old cursor */
	cursor = GetWidgetCursor(dndPtr->interp, dndPtr->tkwin);
	if (dndPtr->cursor != None) {
	    Tk_FreeCursor(dndPtr->display, dndPtr->cursor);
	}
	dndPtr->cursor = cursor;
	if (dndPtr->cursors != NULL) {
	    /* Temporarily install the drag-and-drop cursor. */
	    Tk_DefineCursor(dndPtr->tkwin, dndPtr->cursors[0]);
	}
    }
    if (Tk_WindowId(tokenPtr->tkwin) == None) {
	Tk_MakeWindowExist(tokenPtr->tkwin);
    }
    if (!Tk_IsMapped(tokenPtr->tkwin)) {
	Tk_MapWindow(tokenPtr->tkwin);
    }
    RaiseToken(tokenPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  CancelOp --
 *
 *	Cancels the current drag&drop operation for the source.  Calling
 *	this operation does not affect the transfer of data from the 
 *	source to the target, once the drop has been made.  From the 
 *	source's point of view, the drag&drop operation is already over. 
 *
 *	Example: dnd cancel .widget
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side Effects:
 *	Hides the token and sets a flag indicating that further "drag"
 *	and "drop" operations should be ignored.
 *
 * ------------------------------------------------------------------------
 */
static int
CancelOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Dnd *dndPtr;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (!dndPtr->isSource) {
	Tcl_AppendResult(interp, "widget \"", Tk_PathName(dndPtr->tkwin), 
	 "\" is not a registered drag&drop source.", (char *)NULL);
	return TCL_ERROR;
    }
    /* Send the target a Leave message so it can change back. */
    RelayLeaveEvent(dndPtr, dndPtr->windowPtr, 0, 0);
    dndPtr->canceled = TRUE;
    dndPtr->tokenPtr->nSteps = 10;
    SnapToken(dndPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  CgetOp --
 *
 *	Called to process an (argc,argv) list to configure (or
 *	reconfigure) a drag&drop widget.
 *
 * ------------------------------------------------------------------------
 */
/* ARGSUSED*/
static int
CgetOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;			/* Not used. */
    char **argv;
{
    Dnd *dndPtr;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    return Tk_ConfigureValue(interp, dndPtr->tkwin, configSpecs, (char *)dndPtr,
	argv[3], 0);
}

/*
 * ------------------------------------------------------------------------
 *
 *  ConfigureOp --
 *
 *	Called to process an (argc,argv) list to configure (or
 *	reconfigure) a drag&drop widget.
 *
 * ------------------------------------------------------------------------
 */
static int
ConfigureOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;		/* current interpreter */
    int argc;			/* number of arguments */
    char **argv;		/* argument strings */
{
    Dnd *dndPtr;
    int flags;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    flags = TK_CONFIG_ARGV_ONLY;
    if (argc == 3) {
	return Tk_ConfigureInfo(interp, dndPtr->tkwin, configSpecs, 
		(char *)dndPtr, (char *)NULL, flags);
    } else if (argc == 4) {
	return Tk_ConfigureInfo(interp, dndPtr->tkwin, configSpecs,
	    (char *)dndPtr, argv[3], flags);
    } 
    if (Tk_ConfigureWidget(interp, dndPtr->tkwin, configSpecs, argc - 3,
		   argv + 3, (char *)dndPtr, flags) != TCL_OK) {
	return TCL_ERROR;
    }
    if (ConfigureDnd(interp, dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  DeleteOp --
 *
 *	Deletes the drag&drop manager from the widget.  If a "-source"
 *	or "-target" switch is present, only that component of the
 *	drag&drop manager is shutdown.  The manager is not deleted
 *	unless both the target and source components are shutdown.
 *
 *	Example: dnd delete .widget
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side Effects:
 *	Deletes the drag&drop manager.  Also the source and target window 
 *	properties are removed from the widget.
 *
 * ------------------------------------------------------------------------ 
 */
static int
DeleteOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Dnd *dndPtr;
    register int i;

    for(i = 3; i < argc; i++) {
	if (GetDnd(clientData, interp, argv[i], &dndPtr) != TCL_OK) {
	    return TCL_ERROR;
	}
	DestroyDnd(dndPtr);
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  SelectOp --
 *
 *	Initializes a drag&drop transaction.  Typically this operation
 *	is called from a ButtonPress event on a source widget.  The
 *	window information cache is initialized, and the token is 
 *	initialized and displayed.  
 *
 *	Example: dnd pickup .widget x y 
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side Effects:
 *	The token is initialized and displayed.  This may require invoking
 *	a user-defined package command.  The window information cache is
 *	also initialized.
 *
 * ------------------------------------------------------------------------
 */
static int
SelectOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Winfo *newPtr;
    Dnd *dndPtr;
    int x, y, timestamp;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (!dndPtr->isSource) {
	Tcl_AppendResult(interp, "widget \"", Tk_PathName(dndPtr->tkwin), 
	 "\" is not a registered drag&drop source.", (char *)NULL);
	return TCL_ERROR;
    }
    if (dndPtr->tokenPtr == NULL) {
	Tcl_AppendResult(interp, "no drag&drop token created for \"", 
		 argv[2], "\"", (char *)NULL);
	return TCL_ERROR;
    }
    if ((Tcl_GetInt(interp, argv[3], &x) != TCL_OK) ||
	(Tcl_GetInt(interp, argv[4], &y) != TCL_OK)) {
	return TCL_ERROR;
    }
    if (Tcl_GetInt(interp, argv[5], &timestamp) != TCL_OK) {
	return TCL_ERROR;
    }
    /* 
     * Initialize the window cache and the drop token.  A Tcl command may 
     * be invoked to "package" the token.
     */
    if (DragInit(dndPtr, x, y, timestamp) != TCL_OK) {
	return TCL_ERROR;
    }
    newPtr = OverTarget(dndPtr);
    RelayEnterEvent(dndPtr, newPtr, x, y);
    dndPtr->windowPtr = newPtr;
    dndPtr->tokenPtr->status = (newPtr != NULL) 
	? TOKEN_STATUS_ACTIVE : TOKEN_STATUS_NORMAL;
    if (dndPtr->tokenPtr->lastStatus != dndPtr->tokenPtr->status) {
	EventuallyRedrawToken(dndPtr);
    }
    MoveToken(dndPtr);		/* Move token to current drag point. */ 
    dndPtr->tokenPtr->selectX = dndPtr->tokenPtr->x;
    dndPtr->tokenPtr->selectY = dndPtr->tokenPtr->y;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  DragOp --
 *
 *	Continues the drag&drop transaction.  Typically this operation
 *	is called from a button Motion event on a source widget.  Pointer
 *	event messages are possibly sent to the target, indicating Enter,
 *	Leave, and Motion events.
 *
 *	Example: dnd drag .widget x y 
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side Effects:
 *	Pointer events are relayed to the target (if the mouse is over
 *	one).
 *
 * ------------------------------------------------------------------------
 */
static int
DragOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Winfo *newPtr, *oldPtr;
    Dnd *dndPtr;
    int x, y;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (!dndPtr->isSource) {
	Tcl_AppendResult(interp, "widget \"", Tk_PathName(dndPtr->tkwin), 
	 "\" is not a registered drag&drop source.", (char *)NULL);
	return TCL_ERROR;
    }
    if (dndPtr->tokenPtr == NULL) {
	Tcl_AppendResult(interp, "no drag&drop token created for \"", 
		 argv[2], "\"", (char *)NULL);
	return TCL_ERROR;
    }
    if ((Tcl_GetInt(interp, argv[3], &x) != TCL_OK) ||
	(Tcl_GetInt(interp, argv[4], &y) != TCL_OK)) {
	return TCL_ERROR;
    }
    /* 
     * The following code gets tricky because the package command may 
     * call "update" or "tkwait".  A motion event may then trigger 
     * this routine, before the token has been initialized. Until the 
     * package command finishes, no target messages are sent and drops 
     * are silently ignored.  Note that we do still track mouse 
     * movements, so that when the package command completes, it will 
     * have the latest pointer position.  
     */
    dndPtr->x = x;	/* Save current location. */
    dndPtr->y = y;

    if ((dndPtr->canceled) || (dndPtr->pkgCmdInProgress)) {
	return TCL_OK;		/* Re-entered this routine. */
    }
    oldPtr = dndPtr->windowPtr;
    newPtr = OverTarget(dndPtr);
    if (newPtr == oldPtr) {
	RelayMotionEvent(dndPtr, oldPtr, x, y); 
	dndPtr->windowPtr = oldPtr;
    } else {
	RelayLeaveEvent(dndPtr, oldPtr, x, y);
	RelayEnterEvent(dndPtr, newPtr, x, y);
	dndPtr->windowPtr = newPtr;
    } 
    dndPtr->tokenPtr->status = (newPtr != NULL) 
	? TOKEN_STATUS_ACTIVE : TOKEN_STATUS_NORMAL;
    if (dndPtr->tokenPtr->lastStatus != dndPtr->tokenPtr->status) {
	EventuallyRedrawToken(dndPtr);
    }
    MoveToken(dndPtr);		/* Move token to current drag point. */ 
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  DropOp --
 *
 *	Finishes the drag&drop transaction by dropping the data on the
 *	selected target.  Typically this operation is called from a 
 *	ButtonRelease event on a source widget.  Note that a Leave message
 *	is always sent to the target so that is can un-highlight itself.
 *	The token is hidden and a drop message is sent to the target.
 *
 *	Example: dnd drop .widget x y 
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side Effects:
 *	The token is hidden and a drop message is sent to the target.
 *
 * ------------------------------------------------------------------------
 */
static int
DropOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Winfo *windowPtr;
    Dnd *dndPtr;
    int x, y;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (!dndPtr->isSource) {
	Tcl_AppendResult(interp, "widget \"", Tk_PathName(dndPtr->tkwin), 
	 "\" is not a registered drag&drop source.", (char *)NULL);
	return TCL_ERROR;
    }
    if ((Tcl_GetInt(interp, argv[3], &x) != TCL_OK) ||
	(Tcl_GetInt(interp, argv[4], &y) != TCL_OK)) {
	return TCL_ERROR;
    }
    if (dndPtr->rootPtr == NULL) {
	Tcl_AppendResult(interp, "no current drag&drop operation for source \"",
		 Tk_PathName(dndPtr->tkwin), (char *)NULL);
	return TCL_ERROR;
    }
    dndPtr->x = x;	/* Save drag&drop location */
    dndPtr->y = y;

    if (!dndPtr->canceled) {
	windowPtr = OverTarget(dndPtr);
	if ((!dndPtr->pkgCmdInProgress) && (windowPtr != NULL)) {
	    if (windowPtr->matches != NULL) {
		SetProperty(dndPtr->tkwin, dndPtr->dataPtr->formatsAtom, 
			    windowPtr->matches);
	    }
	    MoveToken(dndPtr);		/* Move token to current drag point. */ 
	    RelayDropEvent(dndPtr, windowPtr, x, y);
#ifdef notdef
	    dndPtr->tokenPtr->nSteps = 10;
	    FadeToken(dndPtr);
#endif
	} else {
	    dndPtr->tokenPtr->nSteps = 10;
	    SnapToken(dndPtr);
	}
    }
    StopActiveCursor(dndPtr);
    FreeWinfo(dndPtr->rootPtr);
    dndPtr->rootPtr = NULL;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  GetdataOp --
 *
 *	Registers one or more data formats with a drag&drop source.  
 *	Each format has a Tcl command associated with it.  This command
 *	is automatically invoked whenever data is pulled from the source
 *	to a target requesting the data in that particular format.  The 
 *	purpose of the Tcl command is to get the data from in the 
 *	application. When the Tcl command is invoked, special percent 
 *	substitutions are made:
 *
 *		%t		Drag&drop transaction timestamp.
 *		%W		Source widget.
 *
 *	If a converter (command) already exists for a format, it 
 *	overwrites the existing command.
 *
 *	Example: dnd getdata .widget "color" { %W cget -bg }
 *
 * Results:
 *	A standard Tcl result.  
 *
 * ------------------------------------------------------------------------
 */
static int
GetdataOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Dnd *dndPtr;
    Tcl_HashEntry *hPtr;
    Tcl_HashSearch cursor;
    int isNew;
    char *cmd;
    register int i;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (argc == 3) {
	/* Return list of source data formats */
	for (hPtr = Tcl_FirstHashEntry(&(dndPtr->getDataTable), &cursor);
	    hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	    Tcl_AppendElement(interp,
		Tcl_GetHashKey(&(dndPtr->getDataTable), hPtr));
	}
	return TCL_OK;
    }

    if (argc == 4) {
	hPtr = Tcl_FindHashEntry(&(dndPtr->getDataTable), argv[3]);
	if (hPtr == NULL) {
	    Tcl_AppendResult(interp, "can't find handler for format \"", 
	     argv[3], "\" for source \"", Tk_PathName(dndPtr->tkwin), "\"",
	     (char *)NULL);
	    return TCL_ERROR;
	}
	cmd = (char *)Tcl_GetHashValue(hPtr);
	if (cmd == NULL) {
	    cmd = "";
	}
	Tcl_SetResult(interp, cmd, TCL_STATIC);
	return TCL_OK;
    }

    for (i = 3; i < argc; i += 2) {
	hPtr = Tcl_CreateHashEntry(&(dndPtr->getDataTable), argv[i], &isNew);
	if (!isNew) {
	    cmd = Tcl_GetHashValue(hPtr);
	    free(cmd);
	}
	cmd = strdup(argv[i+1]);
	Tcl_SetHashValue(hPtr, (ClientData)cmd);
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  NamesOp --
 *
 *	Returns the names of all the drag&drop managers.  If either
 *	a "-source" or "-target" switch is present, only the names of
 *	managers acting as sources or targets respectively are returned.
 *	A pattern argument may also be given.  Only those managers
 *	matching the pattern are returned.
 *
 *	Examples: dnd names
 *		  dnd names -source
 *		  dnd names -target
 *		  dnd names .*label
 * Results:
 *	A standard Tcl result.  A Tcl list of drag&drop manager
 *	names is returned.
 *
 * ------------------------------------------------------------------------
 */
static int
NamesOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    ThreadData *dataPtr = (ThreadData *)clientData;
    Tcl_HashEntry *hPtr;
    Tcl_HashSearch cursor;
    Dnd *dndPtr;
    int findSources, findTargets;

    findSources = findTargets = TRUE;
    if (argc > 2) {
	if ((argv[2][0] == '-') && (strcmp(argv[2], "-source") == 0)) {
	    findTargets = FALSE;
	    argc--, argv++;
	} else if ((argv[2][0] == '-') && (strcmp(argv[2], "-target") == 0)) {
	    findSources = FALSE;
	    argc--, argv++;
	}
    }
    for (hPtr = Tcl_FirstHashEntry(&(dataPtr->dndTable), &cursor); 
	 hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	dndPtr = (Dnd *)Tcl_GetHashValue(hPtr);
	if ((argc > 3) && 
	    (!Tcl_StringMatch(Tk_PathName(dndPtr->tkwin), argv[3]))) {
	    continue;
	}
	if (((findSources) && (dndPtr->isSource)) ||
	    ((findTargets) && (dndPtr->isTarget))) {
	    Tcl_AppendElement(interp, Tk_PathName(dndPtr->tkwin));
	}
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  PullOp --
 *
 *	Pulls the current data from the source in the given format.
 *	application.
 *
 *	dnd pull .widget format data
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side Effects:
 *	Invokes the target's data converter to store the data. 
 *
 * ------------------------------------------------------------------------
 */
static int
PullOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;			/* Not used. */
    char **argv;
{
    Dnd *dndPtr;		/* drag&drop source record */
    int result;
    char *formatCmd;
    Tcl_HashEntry *hPtr;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (!dndPtr->isTarget) {
	Tcl_AppendResult(interp, "widget \"", Tk_PathName(dndPtr->tkwin), 
	 "\" is not a registered drag&drop target.", (char *)NULL);
	return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&(dndPtr->setDataTable), argv[3]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "can't find format \"", argv[3], 
	 "\" in target \"", Tk_PathName(dndPtr->tkwin), "\"", (char *)NULL);
	return TCL_ERROR;
    }
    formatCmd = (char *)Tcl_GetHashValue(hPtr);
    if (dndPtr->pendingPtr == NULL) {
	Tcl_AppendResult(interp, "no drop in progress", (char *)NULL);
	return TCL_ERROR;
    }

    CompleteDataTransaction(dndPtr, argv[3], dndPtr->pendingPtr);
    result = TCL_OK;
    if (Tcl_DStringLength(&(dndPtr->pendingPtr->dString)) > 0) {
	Tcl_DString dString;
	SubstDescriptors subs[3];

	/* Now run the "setdata" callback to save the data.  */
	subs[0].letter = 'v';
	subs[0].value = Tcl_DStringValue(&(dndPtr->pendingPtr->dString));
	subs[1].letter = 'W';
	subs[1].value = Tk_PathName(dndPtr->tkwin);
	subs[2].letter = 't';
	subs[2].value = Blt_Itoa(dndPtr->pendingPtr->timestamp);
	ExpandPercents(formatCmd, subs, 3, &dString);
	result = Tcl_GlobalEval(interp, Tcl_DStringValue(&dString));
	Tcl_DStringFree(&dString);
    }
    return result;
}

/*
 * ------------------------------------------------------------------------
 *
 *  SetdataOp --
 *
 *	Registers one or more data formats with a drag&drop target.  
 *	Each format has a Tcl command associated with it.  This command
 *	is automatically invoked whenever data arrives from a source
 *	to be converted to that particular format.  The purpose of the 
 *	command is to set the data somewhere in the application (either 
 *	using a Tcl command or variable).   When the Tcl command is invoked, 
 *	special percent substitutions are made:
 *
 *		%t		Drag&drop transaction timestamp.
 *		%W		Target widget.
 *		%v		Data value transfered from the source to
 *				be converted into the correct format.
 *
 *	If a converter (command) already exists for a format, it 
 *	overwrites the existing command.
 *
 *	Example: dnd setdata .widget color { . configure -bg %v }
 *
 * Results:
 *	A standard Tcl result.
 *
 * ------------------------------------------------------------------------
 */
static int
SetdataOp(clientData, interp, argc, argv)
    ClientData clientData;
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Dnd *dndPtr;
    Tcl_HashEntry *hPtr;
    Tcl_HashSearch cursor;
    int isNew;
    char *cmd;
    int i;

    if (GetDnd(clientData, interp, argv[2], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (argc == 3) {
	/* Show target handler data formats */
	for (hPtr = Tcl_FirstHashEntry(&(dndPtr->setDataTable), &cursor);
	    hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	    Tcl_AppendElement(interp,
		Tcl_GetHashKey(&(dndPtr->setDataTable), hPtr));
	}
	return TCL_OK;
    }
    if (argc == 4) {
	hPtr = Tcl_FindHashEntry(&(dndPtr->setDataTable), argv[3]);
	if (hPtr == NULL) {
	    Tcl_AppendResult(interp, "can't find handler for format \"", 
	     argv[3], "\" for target \"", Tk_PathName(dndPtr->tkwin), "\"",
	     (char *)NULL);
	    return TCL_ERROR;
	}
	cmd = (char *)Tcl_GetHashValue(hPtr);
	if (cmd == NULL) {
	    cmd = "";
	}
	Tcl_SetResult(interp, cmd, TCL_STATIC);
	return TCL_OK;
    }
    for (i = 3; i < argc; i += 2) {
	hPtr = Tcl_CreateHashEntry(&(dndPtr->setDataTable), argv[i], &isNew);
	if (!isNew) {
	    cmd = Tcl_GetHashValue(hPtr);
	    free(cmd);
	}
	cmd = strdup(argv[i+1]);
	Tcl_SetHashValue(hPtr, (ClientData)cmd);
    }
    AddTargetProperty(interp, dndPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  RegisterOp --
 *
 *  dnd register .window 
 * ------------------------------------------------------------------------
 */
static int
RegisterOp(clientData, interp, argc, argv)
    ClientData clientData;
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    ThreadData *dataPtr = (ThreadData *)clientData;
    Tk_Window tkwin;
    Tcl_HashEntry *hPtr;
    Dnd *dndPtr;
    int isNew;

    tkwin = Tk_NameToWindow(interp, argv[2], dataPtr->mainWindow);
    if (tkwin == NULL) {
	return TCL_ERROR;
    }
    hPtr = Tcl_CreateHashEntry(&(dataPtr->dndTable), (char *)tkwin, &isNew);
    if (!isNew) {
	Tcl_AppendResult(interp, "\"", Tk_PathName(tkwin), 
	     "\" is already registered as a drag&drop manager", (char *)NULL);
	return TCL_ERROR;
    }
    dndPtr = CreateDnd(interp, tkwin);
    dndPtr->hashPtr = hPtr;
    dndPtr->dataPtr = dataPtr;
    Tcl_SetHashValue(hPtr, (ClientData)dndPtr);
    if (Tk_ConfigureWidget(interp, dndPtr->tkwin, configSpecs, argc - 3,
	   argv + 3, (char *)dndPtr, 0) != TCL_OK) {
	return TCL_ERROR;
    }
    if (ConfigureDnd(interp, dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  TokenWindowOp --
 *
 * ------------------------------------------------------------------------
 */
static int
TokenWindowOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Dnd *dndPtr;
    int flags;

    if (GetDnd(clientData, interp, argv[3], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    flags = 0;
    if (dndPtr->tokenPtr == NULL) {
	if (CreateToken(interp, dndPtr) != TCL_OK) {
	    return TCL_ERROR;
	}
    } else {
	flags = TK_CONFIG_ARGV_ONLY;
    }
    if (ConfigureToken(interp, dndPtr, argc - 4, argv + 4, flags) != TCL_OK) {
	return TCL_ERROR;
    }
    Tcl_SetResult(interp, Tk_PathName(dndPtr->tokenPtr->tkwin), TCL_STATIC);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *
 *  TokenCgetOp --
 *
 *	Called to process an (argc,argv) list to configure (or
 *	reconfigure) a drag&drop widget.
 *
 * ------------------------------------------------------------------------
 */
/* ARGSUSED*/
static int
TokenCgetOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;			/* Not used. */
    char **argv;
{
    Dnd *dndPtr;

    if (GetDnd(clientData, interp, argv[3], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    if (dndPtr->tokenPtr == NULL) {
	Tcl_AppendResult(interp, "no token created for \"", argv[3], "\"",
		 (char *)NULL);
	return TCL_ERROR;
    }
    return Tk_ConfigureValue(interp, dndPtr->tokenPtr->tkwin, tokenConfigSpecs, 
	     (char *)dndPtr->tokenPtr, argv[4], TK_CONFIG_ARGV_ONLY);
}

/*
 * ------------------------------------------------------------------------
 *
 *  TokenConfigureOp --
 *
 * ------------------------------------------------------------------------
 */
static int
TokenConfigureOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Token *tokenPtr;
    Dnd *dndPtr;
    int flags;

    if (GetDnd(clientData, interp, argv[3], &dndPtr) != TCL_OK) {
	return TCL_ERROR;
    }
    flags = TK_CONFIG_ARGV_ONLY;
    if (dndPtr->tokenPtr == NULL) {
	Tcl_AppendResult(interp, "no token created for \"", argv[3], "\"",
		 (char *)NULL);
	return TCL_ERROR;
    }
    tokenPtr = dndPtr->tokenPtr;
    if (argc == 3) {
	return Tk_ConfigureInfo(interp, tokenPtr->tkwin, tokenConfigSpecs,
	    (char *)tokenPtr, (char *)NULL, flags);
    } else if (argc == 4) {
	return Tk_ConfigureInfo(interp, tokenPtr->tkwin, tokenConfigSpecs,
	    (char *)tokenPtr, argv[3], flags);
    } 
    return ConfigureToken(interp, dndPtr, argc - 4, argv + 4, flags);
}

static Blt_OpSpec tokenOps[] =
{
    {"cget", 2, (Blt_Operation)TokenCgetOp, 5, 5, "widget option",},
    {"configure", 2, (Blt_Operation)TokenConfigureOp, 4, 0, 
	"widget ?option value?...",},
    {"window", 5, (Blt_Operation)TokenWindowOp, 4, 0, 
	"widget ?option value?...",},
};

static int nTokenOps = sizeof(tokenOps) / sizeof(Blt_OpSpec);

/*
 * ------------------------------------------------------------------------
 *
 *  TokenOp --
 *
 * ------------------------------------------------------------------------
 */
static int
TokenOp(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
    int argc;
    char **argv;
{
    Blt_Operation proc;
    int result;

    proc = Blt_GetOperation(interp, nTokenOps, tokenOps, BLT_OPER_ARG2,
	argc, argv);
    if (proc == NULL) {
	return TCL_ERROR;
    }
    result = (*proc) (clientData, interp, argc, argv);
    return result;
}

static Blt_OpSpec dndOps[] =
{
    {"cancel", 2, (Blt_Operation)CancelOp, 3, 3, "widget",},
    {"cget", 2, (Blt_Operation)CgetOp, 4, 4, "widget option",},
    {"configure", 4, (Blt_Operation)ConfigureOp, 3, 0, 
	"widget ?option value?...",},
#ifdef notdef
    {"convert", 4, (Blt_Operation)ConvertOp, 5, 5, "widget data format",},
#endif
    {"delete", 2, (Blt_Operation)DeleteOp, 3, 0,"?-source|-target? widget...",},
    {"drag", 3, (Blt_Operation)DragOp, 3, 0, "widget x y ?token?",},
    {"drop", 3, (Blt_Operation)DropOp, 3, 0, "widget x y ?token?",},
    {"getdata", 1, (Blt_Operation)GetdataOp, 3, 0, "widget ?format command?",},
    {"names", 1, (Blt_Operation)NamesOp, 2, 4, "?-source|-target? ?pattern?",},
    {"pull", 1, (Blt_Operation)PullOp, 4, 4, "widget format",},
    {"register", 1, (Blt_Operation)RegisterOp, 3, 0, "widget ?option value?...",},
    {"select", 3, (Blt_Operation)SelectOp, 6, 6, "widget x y timestamp",},
    {"setdata", 3, (Blt_Operation)SetdataOp, 3, 0, "widget ?format command?",},
    {"token", 5, (Blt_Operation)TokenOp, 3, 0, "args...",},
};

static int nDndOps = sizeof(dndOps) / sizeof(Blt_OpSpec);

/*
 * ------------------------------------------------------------------------
 *
 *  DndCmd --
 *
 *	Invoked by TCL whenever the user issues a drag&drop command.
 *
 * ------------------------------------------------------------------------
 */
static int
DndCmd(clientData, interp, argc, argv)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;		/* current interpreter */
    int argc;			/* number of arguments */
    char **argv;		/* argument strings */
{
    Blt_Operation proc;
    int result;

    proc = Blt_GetOperation(interp, nDndOps, dndOps, BLT_OPER_ARG1,
	argc, argv);
    if (proc == NULL) {
	return TCL_ERROR;
    }
    result = (*proc) (clientData, interp, argc, argv);
    return result;
}

/*
 * -----------------------------------------------------------------------
 *
 * DndInterpDeleteProc --
 *
 *	This is called when the interpreter hosting the "dnd" command is 
 *	destroyed.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Destroys the hash table containing the drag&drop managers.
 *
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
static void
DndInterpDeleteProc(clientData, interp)
    ClientData clientData;	/* Thread-specific data. */
    Tcl_Interp *interp;
{
    ThreadData *dataPtr = (ThreadData *)clientData;
    Dnd *dndPtr;
    Tcl_HashEntry *hPtr;
    Tcl_HashSearch cursor;

    for (hPtr = Tcl_FirstHashEntry(&(dataPtr->dndTable), &cursor);
	 hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	dndPtr = (Dnd *)Tcl_GetHashValue(hPtr);
	dndPtr->hashPtr = NULL;
	DestroyDnd(dndPtr);
    }
    Tcl_DeleteHashTable(&(dataPtr->dndTable));
    Tcl_DeleteAssocData(interp, DND_THREAD_KEY);
    free((char *)dataPtr);
}

static ThreadData *
GetDndCmdData(interp)
     Tcl_Interp *interp;
{
    ThreadData *dataPtr;
    Tcl_InterpDeleteProc *proc;

    dataPtr = (ThreadData *)Tcl_GetAssocData(interp, DND_THREAD_KEY, &proc);
    if (dataPtr == NULL) {
	Display *display;
	Tk_Window tkwin;

	dataPtr = (ThreadData *)malloc(sizeof(ThreadData));
	assert(dataPtr);
	tkwin = Tk_MainWindow(interp);
	display = Tk_Display(tkwin);
	dataPtr->mainWindow = tkwin;
	dataPtr->display = display;
	Tcl_SetAssocData(interp, DND_THREAD_KEY, DndInterpDeleteProc,
		(ClientData)dataPtr);
	Tcl_InitHashTable(&(dataPtr->dndTable), TCL_ONE_WORD_KEYS);
	dataPtr->mesgAtom = XInternAtom(display, "BLT Dnd Message", False);
	dataPtr->targetAtom = XInternAtom(display, "BLT Dnd Target", False);
	dataPtr->formatsAtom = XInternAtom(display, "BLT Dnd Formats",False);
	dataPtr->commAtom = XInternAtom(display, "BLT Dnd CommData", False);

#ifdef HAVE_XDND
	dataPtr->XdndActionListAtom = XInternAtom(display, "XdndActionList", 
		False);
	dataPtr->XdndAwareAtom = XInternAtom(display, "XdndAware", False);
	dataPtr->XdndEnterAtom = XInternAtom(display, "XdndEnter", False);
	dataPtr->XdndFinishedAtom = XInternAtom(display, "XdndFinished", False);
	dataPtr->XdndLeaveAtom = XInternAtom(display, "XdndLeave", False);
	dataPtr->XdndPositionAtom = XInternAtom(display, "XdndPosition", False);
	dataPtr->XdndSelectionAtom = XInternAtom(display, "XdndSelection", 
						 False);
	dataPtr->XdndStatusAtom = XInternAtom(display, "XdndStatus", False);
	dataPtr->XdndTypeListAtom = XInternAtom(display, "XdndTypeList", False);
#endif /* HAVE_XDND */
    }
    return dataPtr;
}

/*
 * ------------------------------------------------------------------------
 *
 *  Blt_DndInit --
 *
 *	Adds the drag&drop command to the given interpreter.  Should
 *	be invoked to properly install the command whenever a new
 *	interpreter is created.
 *
 * ------------------------------------------------------------------------
 */
int
Blt_DndInit(interp)
    Tcl_Interp *interp;		/* interpreter to be updated */
{
    static Blt_CmdSpec cmdSpec =
    {
	"dnd", DndCmd
    };
    ThreadData *dataPtr;

    dataPtr = GetDndCmdData(interp);
    cmdSpec.clientData = (ClientData)dataPtr;
    if (Blt_InitCmd(interp, "blt", &cmdSpec) == NULL) {
	return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * Registers bitmap outline of dragged data, used to indicate
 * what is being dragged by source.  Bitmap is XOR-ed as cursor/token
 * is moved around the screen.
 */
static void
Blt_DndSetOutlineBitmap(tkwin, bitmap, x, y)
    Tk_Window tkwin;
    Pixmap bitmap;
    int x, y;
{
    
}

#ifdef HAVE_XDND

static void
XDndFreeFormats(handlerPtr) 
    XDndHandler *handlerPtr;
{
    if (handlerPtr->formatArr != NULL) {
	char **p;

	for (p = handlerPtr->formatArr; *p != NULL; p++) {
	    XFree(*p);
	}
	free((char *)handlerPtr->formatArr);
	handlerPtr->formatArr = NULL;
    }
}

static char **
XDndGetFormats(handlerPtr, eventPtr)
    XDndHandler *handlerPtr;
    XEvent *eventPtr;
{
    int flags;
    Window window;
    unsigned char *data;
    Atom typeAtom;
    Atom format;
    int nItems, bytesAfter;
    Atom *atomArr;
    char *nameArr[XDND_MAX_TYPES + 1];
    Display *display;

    XDndFreeFormats(handlerPtr);
    display = eventPtr->xclient.display;
    window = eventPtr->xclient.data.l[0];
    flags = eventPtr->xclient.data.l[1];
    data = NULL;
    if (flags & 0x01) {
	result = XGetWindowProperty(
	    display,		/* Display of window. */
	    window,		/* Window holding the property. */
	    handlerPtr->dataPtr->XdndTypeListAtom, /* Name of property. */
	    0,			/* Offset of data (for multiple reads). */
	    XDND_MAX_TYPES,	/* Maximum number of items to read. */
	    False,		/* If true, delete the property. */
	    XA_ATOM,		/* Desired type of property. */
	    &typeAtom,		/* (out) Actual type of the property. */
	    &format,		/* (out) Actual format of the property. */
	    &nItems,		/* (out) # of items in specified format. */
	    &bytesAfter,	/* (out) # of bytes remaining to be read. */
	    (unsigned char **)&data);
	if ((result != Success) || (format != 32) || (typeAtom != XA_ATOM)) {
	    if (data != NULL) {
		XFree((char *)data);
		return (char **)NULL;
	    }
	}
	atomArr = (Atom *)data;
	nAtoms = nItems;
    } else {
	atomArr = &(eventPtr->xclient.data.l[2]);
	nAtoms = 3;
    }
    formatArr = (char **)calloc(nAtoms + 1, sizeof(char *));
    for (i = 0; (i < nAtoms) && (atomArr[i] != None); i++) {
	formatArr[i] = XGetAtomName(display, atomArr[i]);
    }
    if (data != NULL) {
	XFree((char *)data);
    }
    handlerPtr->formatArr = formatArr;
}

static char *
GetMatchingFormats(dndPtr, formatArr)
    Dnd *dndPtr;
    char **formatArr;
{
    int nMatches;

    nMatches = 0;
    Tcl_DStringInit(&dString);
    for (p = formatArr; *p != NULL; p++) {
	for(hPtr = Tcl_FirstHashEntry(&(dndPtr->setDataTable), &cursor);
	    hPtr != NULL; hPtr = Tcl_NextHashEntry(&cursor)) {
	    fmt = Tcl_GetHashKey(&(dndPtr->setDataTable), hPtr);
	    if ((*fmt == **p) && (strcmp(fmt, *p) == 0)) {
		Tcl_DStringAppendElement(&dString, *p);
		nMatches++;
		break;
	    }
	}
    }
    if (nMatches > 0) {
	char *string;

	string = strdup(Tcl_DStringValue(&dString));
	Tcl_DStringFree(&dString);
	return string;
    }
    return NULL;
}

static void
XDndPointerEvent(handlerPtr, eventPtr)
    XDndHandler *handlerPtr;
    XEvent *eventPtr;
{
    Tk_Window tkwin;
    int flags;
    Atom action;
    Window window;
    
    flags = 0;
    action = None;
    window = eventPtr->xclient.data.l[MESG_INDEX_XDND_WINDOW];
    /* 
     * If the XDND source has no formats specified, don't process any further.
     * Simply send a "no accept" action with the message.
     */
    if (handlerPtr->formatArr != NULL) { 
	Dnd *newPtr, *oldPtr;
	int point;
	int button, keyState;
	int x, y;
	char *formats;

	point = (int)eventPtr->xclient.data.l[MESG_INDEX_XDND_POINT];
	UNPACK(point, x, y);

	/*  
	 * See if the mouse pointer currently over a drop target. We first
	 * determine what Tk window is under the mouse, and then check if 
	 * that window is registered as a drop target.  
	 */
	newPtr = NULL;
	tkwin = Tk_CoordsToWindow(x, y, handlerPtr->tkwin);
	if (tkwin != NULL) {
	    Tcl_HashEntry *hPtr;
	    
	    hPtr = Tcl_FindHashEntry(&(handlerPtr->dataPtr->dndTable), 
		(char *)tkwin);
	    if (hPtr != NULL) {
		newPtr = (Dnd *)Tcl_GetHashValue(hPtr);
		if (!newPtr->isTarget) {
		    newPtr = NULL; /* Not a DND target. */
		}
		formats = GetMatchingFormats(newPtr, handlerPtr->formatArr);
		if (formats == NULL) {
		    newPtr = NULL; /* Source has no matching formats. */
		} 
	    }
	}
	button = keyState = 0;
	oldPtr = handlerPtr->dndPtr;
	resp = DRAG_CANCEL;
	if (newPtr == oldPtr) {
	    if ((oldPtr != NULL) && (oldPtr->motionCmd != NULL)) {
		resp = InvokeCallback(oldPtr, oldPtr->motionCmd, x, y, formats,
			 button, keyState);
	    }
	} else {
	    if ((oldPtr != NULL) && (oldPtr->leaveCmd != NULL)) {
		InvokeCallback(oldPtr, oldPtr->leaveCmd, x, y, formats, button,
			 keyState);
	    }
	    if ((newPtr != NULL) && (newPtr->enterCmd != NULL)) {
		resp = InvokeCallback(newPtr, newPtr->enterCmd, x, y, formats, 
			button, keyState);
	    }
	    handlerPtr->dndPtr = newPtr;
	    /* 
	     * Save the current mouse position, since we get them from the
	     * drop message. 
	     */
	    newPtr->x = x;	
	    newPtr->y = y;
	} 
	if (formats != NULL) {
	    free(formats);
	}
	flags = XDND_FLAGS_WANT_POSITION_MSGS;
	if (resp) {
	    flags |= XDND_FLAGS_ACCEPT_DROP;
	    action = handlerPtr->dataPtr->XdndActionCopyAtom;
	}
    }
    /* Target-to-Source: Drag result message. */
    SendClientMsg(handlerPtr->display, window, 
	handlerPtr->dataPtr->XdndStatusAtom, handlerPtr->window, 
	flags, 0, 0, action);
}

static void
XDndDropEvent(handlerPtr, eventPtr)
    XDndHandler *handlerPtr;
    XEvent *eventPtr;
{
    Tk_Window tkwin;
    int flags;
    Atom action;
    Window window;
    int timestamp;

    flags = 0;
    action = None;
    window = eventPtr->xclient.data.l[MESG_INDEX_XDND_WINDOW];
    timestamp = eventPtr->xclient.data.l[MESG_INDEX_XDND_TIMESTAMP];

    /* 
     * If no formats were specified for the XDND source or if the last 
     * motion event did not place the mouse over a valid drop target, 
     * don't process any further. Simply send a "no accept" action with 
     * the message.
     */
    if ((handlerPtr->formatArr != NULL) && (handlerPtr->dndPtr != NULL)) { 
	int button, keyState;
	Dnd *dndPtr = handlerPtr->dndPtr;
	DropPending pending;
	int resp;

	button = keyState = 0;	/* Protocol doesn't supply this information. */

	/* Set up temporary bookkeeping for the drop transaction */
	memset (&pending, 0, sizeof(pending));
	pending.window = window;
	pending.display = eventPtr->xclient.display;
	pending.timestamp = timestamp;
	pending.protocol = PROTO_XDND;
	pending.packetSize = GetMaxPropertySize(pending.display);
	Tcl_DStringInit(&(pending.dString));
	
	formats = GetMatchingFormats(handlerPtr->dndPtr, handlerPtr->formatArr);
	if (formats == NULL) {
	}
	dndPtr->pendingPtr = &pending;
	resp = AcceptDrop(dndPtr, dndPtr->x, dndPtr->y, formats, button,
	     keyState, action);
	dndPtr->pendingPtr = NULL;
	if (resp) {
	    flags |= XDND_FLAGS_ACCEPT_DROP;
	    action = handlerPtr->dataPtr->XdndActionCopyAtom;
	}
    }
    /* Target-to-Source: Drag result message. */
    SendClientMsg(handlerPtr->display, window, 
	handlerPtr->dataPtr->XdndStatusAtom, handlerPtr->window, 
	flags, 0, 0, action);
}

/*
 * ------------------------------------------------------------------------
 *
 *  XDndProtoEventProc --
 *
 *	Invoked by Tk_HandleEvent whenever a DestroyNotify event is received
 *	on a registered drag&drop source widget.
 *
 * ------------------------------------------------------------------------
 */
static int
XDndProtoEventProc(clientData, eventPtr)
    ClientData clientData;	/* Drag&drop record. */
    XEvent *eventPtr;		/* Event description. */
{
    ThreadData *dataPtr = (ThreadData *)clientData;
    Tk_Window tkwin;
    Tcl_HashEntry *hPtr;
    XDndHandler *handlerPtr;
    int point;
    int x, y;
    Atom mesg;

    if (eventPtr->type != ClientMessage) {
	return 0;		/* Not a ClientMessage event. */
    }
    /* Was the recipient a registered toplevel window? */
    hPtr = Tcl_FindHashEntry(&(dataPtr->handlerTable), 
	     (char *)eventPtr->xclient.window);
    if (hPtr == NULL) {
	return 0;		/* No handler registered with window. */
    }
    handlerPtr = (XDndHandler *)Tcl_GetHashValue(hPtr);
    mesg = eventPtr->xclient.message_type;
    if (mesg == dataPtr->XdndEnterAtom) {
	XDndGetFormats(handlerPtr, eventPtr);
	handlerPtr->dndPtr = NULL;
    } else if (mesg == dataPtr->XdndPositionAtom) {
	XDndPointerEvent(handlerPtr, eventPtr);
    } else if (mesg == dataPtr->XdndLeaveAtom) {
	XDndFreeFormats(handlerPtr);	/* Free up any collected formats. */
	if (handlerPtr->dndPtr != NULL) {
	    InvokeCallback(handlerPtr->dndPtr, handlerPtr->dndPtr->leaveCmd, 
		-1, -1, NULL, 0, 0);
	    /* Send leave event to drop target. */
	}
    } else if (mesg == dataPtr->XdndDropAtom) {
	XDndDropEvent(handlerPtr, eventPtr);
    } else {
	fprintf(stderr, "Unknown client message type = 0x%x\n", mesg);
	return 0;		/* Unknown message type.  */
    }
    return 1;
}

static XDndHandler *
XDndCreateHandler(dndPtr) 
    Dnd *dndPtr;
{
    Tk_Window tkwin;
    Window window;
    Tcl_HashEntry *hPtr;
    int isNew;
    XDndHandler *handlerPtr;

    /* 
     * Find the containing toplevel of this window. See if an XDND 
     * handler is already registered for it.  
     */
    tkwin = Blt_GetToplevel(dndPtr->tkwin);
    window = Blt_GetRealWindowId(tkwin); /* Use the wrapper window as
					  * the real toplevel window. */
    hPtr = Tcl_CreateHashEntry(&(dataPtr->XDndHandlerTable), (char *)window, 
	&isNew);
    if (!isNew) {
	handlerPtr = (XDndHandler *)Tcl_GetHashEntry(hPtr);
	handlerPtr->refCount++;
    } else {
	handlerPtr = (XDndHandler *)malloc(sizeof(XDndHandler));
	handlerPtr->tkwin = tkwin;
	handlerPtr->dndPtr = NULL;
	handlerPtr->refCount = 1;
	handlerPtr->dataPtr = dataPtr;
	/* FIXME */
	SetProperty(window, dataPtr->XdndAwareAtom, "3");
	Tcl_SetHashValue(hPtr, (ClientData)handlerPtr);
    }
    return handlerPtr;
}

static void
XDndDeleteHandler(dndPtr) 
    Dnd *dndPtr;
{
    Tk_Window tkwin;
    Window window;
    Tcl_HashEntry *hPtr;

    tkwin = Blt_GetToplevel(dndPtr->tkwin);
    window = Blt_GetRealWindowId(tkwin); /* Use the wrapper window as the real 
					  * toplevel window. */
    hPtr = Tcl_FindHashEntry(&(dataPtr->XDndHandlerTable), (char *)window);
    if (hPtr != NULL) {
	XDndHandler *handlerPtr;

	handlerPtr = (XDndHandler *)Tcl_GetHashEntry(hPtr);
	handlerPtr->refCount--;
	if (handlerPtr->refCount == 0) {
	    XDndFreeFormats(handlerPtr); 
	    XDeleteProperty(dndPtr->display, window, 
		dndPtr->dataPtr->XdndAwareAtom);
	    Tcl_DeleteHashEntry(hPtr);
	    free((char *)handlerPtr);
	}
    }
}

#endif /* HAVE_XDND */

#endif /* NO_DRAGDROP */
