/*
 * netscape_remote.c,v 1.1.1.1 2004/02/29 21:52:24 jcc Exp
 *
 * netscape_remote - a Tcl/Tk extension to talk the remote command protocol
 *		     that Netscape uses
 *
 * This extension speaks the remote protocol that is used by the Netscape
 * web browser.  This lets us control netscape remotely without having to
 * start up a new netscape process (despite what the people at Netscape
 * say, starting up a whole new copy of Netscape takes too long for my
 * tastes).
 *
 * We also cache the window id used for Netscape so we don't have to call
 * XQueryTree for every command.
 *
 * Documentation on the protocol netscape uses can be found at the following
 * URL: http://home.netscape.com/newsref/std/x-remote-proto.html
 *
 * By Ken Hornstein <kenh@cmf.nrl.navy.mil>
 *
 */

/* 29.07.96 - Added #ifdef's to let it work with Tk 4.0. CB */
/* 05.08.96 - Removed newline inside a string. CB */

#ifndef LINT
static char rcsid[]=
	"netscape_remote.c,v 1.1.1.1 2004/02/29 21:52:24 jcc Exp";
#endif

#include "config.h"
#include <sys/types.h>
#include <unistd.h>
#ifdef HAVE_TCL8_0_H
#include <tcl8.0.h>
#include <tk8.0.h>
#else
#include <tk.h>
#endif
#include <X11/Xatom.h>
#include <X11/Xproto.h>

/*
 * Just include a prototype for XmuClientWindow here, since we bring
 * along a copy of ClientWin.c with this distribution
 */

extern Window XmuClientWindow _ANSI_ARGS_((Display *, Window));

/*
 * Names of some of the Netscape internal properties, and variables to
 * store them in.
 */

#define MOZILLA_VERSION_PROP	"_MOZILLA_VERSION"
#define MOZILLA_LOCK_PROP	"_MOZILLA_LOCK"
#define MOZILLA_COMMAND_PROP	"_MOZILLA_COMMAND"
#define MOZILLA_RESPONSE_PROP	"_MOZILLA_RESPONSE"
#define MOZILLA_URL_PROP	"_MOZILLA_URL"

static Atom XA_MOZILLA_VERSION	= 0;
static Atom XA_MOZILLA_LOCK	= 0;
static Atom XA_MOZILLA_COMMAND	= 0;
static Atom XA_MOZILLA_RESPONSE	= 0;
static Atom XA_MOZILLA_URL	= 0;

/*
 * This is a structure that contains all the info about pending things
 * happening on Netscape windows.  We use this to communicate between
 * NetscapeEventProc and what's happening now
 */

typedef struct PendingCommand {
	int state;		/* Type of sub-event we're waiting for */
	Window win;		/* Window we're waiting for */
	Atom atom;		/* Atom for PropertyChange/Delete */
	int response;		/* Did we get a response? */
} PendingCmd;

#define PENDING_OK 1
#define PENDING_TIMEOUT 2
#define PENDING_DESTROY 3

/*
 * Prototypes for internal functions
 */

static int Netscape_Remote_Cmd _ANSI_ARGS_((ClientData, Tcl_Interp *,
					    int, char *[]));
static Window GetWindow _ANSI_ARGS_((Tcl_Interp *, Tk_Window));
static int ListWindows _ANSI_ARGS_((Tcl_Interp *, Display *));
static int CheckForNetscape _ANSI_ARGS_((Display *, Window));
static int SendCommand _ANSI_ARGS_((Tcl_Interp *, Tk_Window, Window,
				    char *, PendingCmd *, int));
static int NetscapeEventHandler _ANSI_ARGS_((ClientData, XEvent *));
static int GetLock _ANSI_ARGS_((Tcl_Interp *, Display *, Window,
				PendingCmd *, int));
#if ((TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)) \
      || (TK_MAJOR_VERSION >= 8)
static Tk_RestrictAction NetscapeRestrict _ANSI_ARGS_((ClientData, XEvent *));
#else
static Tk_RestrictProc NetscapeRestrict;
#endif
static void LockTimeout _ANSI_ARGS_((ClientData));
static void ReleaseLock _ANSI_ARGS_((Display *, Window));
static int Netscape_Info_Cmd _ANSI_ARGS_((ClientData, Tcl_Interp *,
					  int, char*[]));

static Window CachedWindow = None;

#define DEFAULT_TIMEOUT 10000

/*
 * Our package init routine.  Set things up for our new interpreter commands.
 */

int
Netscape_remote_Init(interp)
Tcl_Interp *interp;
{
	Tk_Window main;

	if ((main = Tk_MainWindow(interp)) == NULL) {
		Tcl_AppendResult(interp, "No main window associated with ",
				 "this interpreter!", (char *) NULL);
		return TCL_ERROR;
	}

	/*
	 * Get the Atoms corresponding to these property names; we use
	 * them later.
	 */

	if (! XA_MOZILLA_VERSION)
		XA_MOZILLA_VERSION = Tk_InternAtom(main, MOZILLA_VERSION_PROP);

	if (! XA_MOZILLA_LOCK)
		XA_MOZILLA_LOCK = Tk_InternAtom(main, MOZILLA_LOCK_PROP);

	if (! XA_MOZILLA_COMMAND)
		XA_MOZILLA_COMMAND = Tk_InternAtom(main, MOZILLA_COMMAND_PROP);

	if (! XA_MOZILLA_RESPONSE)
		XA_MOZILLA_RESPONSE = Tk_InternAtom(main,
						    MOZILLA_RESPONSE_PROP);
	if (! XA_MOZILLA_URL)
		XA_MOZILLA_URL = Tk_InternAtom(main, MOZILLA_URL_PROP);

	/*
	 * Create our "send-netscape" and "info-netscape" interpreter
	 * commands
	 */
	
	Tcl_CreateCommand(interp, "send-netscape", Netscape_Remote_Cmd,
			  (ClientData) main, (void (*)()) NULL);
	Tcl_CreateCommand(interp, "info-netscape", Netscape_Info_Cmd,
			  (ClientData) main, (void (*)()) NULL);
	
	/*
	 * Tell the Tcl package interface that we exist
	 */

	if (Tcl_PkgProvide(interp, "netscape_remote", "1.2") != TCL_OK)
		return TCL_ERROR;

	return TCL_OK;
}

/*
 * This is the Tcl glue routine to the routines that do the real work
 * (in this case, SendCommand)
 */

static int
Netscape_Remote_Cmd(clientData, interp, argc, argv)
ClientData clientData;
Tcl_Interp *interp;
int argc;
char *argv[];
{
	Tk_Window main = (Tk_Window) clientData;
	Tk_ErrorHandler error;
	Window w = None;
	PendingCmd pending;
	int timeout = DEFAULT_TIMEOUT;
	char *idVar = NULL;
	char *arg = NULL;
	int i;

	if (argc < 2 || argc > 8) {
		goto usage;
	}

	/*
	 * Parse our command-line arguments
	 */

	for (i = 1; i < argc; i++) {
		arg = argv[i];

		if (arg[0] == '-') {

			/*
			 * Process the -id (specify the window id) option
			 */

			if (strcmp(arg, "-id") == 0) {
				i++;
				if (i >= argc) {
					Tcl_AppendResult(interp, "\"-id\" must",
						" be followed by a window id",
						(char *) NULL);
					return TCL_ERROR;
				}
				if (Tcl_GetInt(interp, argv[i], (int *) &w)
				    != TCL_OK) {
					return TCL_ERROR;
				}
			}

			/*
			 * Process -idvar (variable for window id) option
			 */

			else if (strcmp(argv[i], "-idvar") == 0) {
				i++;
				if (i >= argc) {
					Tcl_AppendResult(interp, "\"-idvar\" "
							 "must be followed ",
							 "by a variable name",
							 (char *) NULL);
					return TCL_ERROR;
				}
				idVar = argv[i];
			}

			/*
			 * Process the -timeout (for various protocol timeouts)
			 * option
			 */

			else if (strcmp(argv[i], "-timeout") == 0) {
				i++;
				if (i >= argc) {
					Tcl_AppendResult(interp,
							 "\"-timeout\" must ",
							 "be followed by an ",
							 "integer",
							 (char *) NULL);
					return TCL_ERROR;
				}
				if (Tcl_GetInt(interp, argv[i], &timeout)
				    != TCL_OK) {
					return TCL_ERROR;
				}
				if (timeout <= 0) {
					Tcl_AppendResult(interp, "\"timeout\" "
							 "must be a positive "
							 "interger.",
							 (char *) NULL);
					return TCL_ERROR;
				}
			} else {
				break;
			}
		} else {
			break;
		}
	}

	if (i != argc - 1) {
usage:
		Tcl_AppendResult(interp, "wrong # args: should be \"",
			argv[0], " ?-id id? ?-idvar idvar? ?-timeout timeout",
			" netscapeCommand\"", (char *) NULL);
		return TCL_ERROR;
	}
		

	/*
	 * Figure out which window to use.  Check to see if we have
	 * a cached window - if so, use that one, rather than iterating
	 * through all of the windows on our display.
	 *
	 * We need to setup an error handler here, otherwise we will
	 * exit if the window doesn't exist.
	 */

	error = Tk_CreateErrorHandler(Tk_Display(main), BadWindow,
				      X_GetProperty, -1, NULL, NULL);

	if (w != None) {
		if (! CheckForNetscape(Tk_Display(main), w)) {
			Tcl_AppendResult(interp, "Invalid window Id, or "
					 "window is not a Netscape window",
					 (char *) NULL);
			Tk_DeleteErrorHandler(error);
			return TCL_ERROR;
		}
	}

	if (CachedWindow != None && w == None) {
		if (CheckForNetscape(Tk_Display(main), CachedWindow)) {
			w = CachedWindow;
		} else {
			CachedWindow = None;
		}
	}

	if (w == None) {
		if ((w = GetWindow(interp, main)) == None) {
			Tk_DeleteErrorHandler(error);
			return TCL_ERROR;
		}
		CachedWindow = w;
	}

	Tk_DeleteErrorHandler(error);

	if (idVar) {
		char value[256];
		sprintf(value, "0x%08x", (int) w);
		if (Tcl_SetVar(interp, idVar, value, TCL_LEAVE_ERR_MSG) ==
		    NULL) {
			return TCL_ERROR;
		}
	}

	return SendCommand(interp, main, w, argv[i], &pending, timeout);
}

/*
 * This is the Tcl glue code for the "info-netscape" command
 */

static int
Netscape_Info_Cmd(clientData, interp, argc, argv)
ClientData clientData;
Tcl_Interp *interp;
int argc;
char *argv[];
{
	Tk_Window main = (Tk_Window) clientData;
	Window w;
	Tk_ErrorHandler error;
	Atom type;
	int format, status;
	unsigned long nitems, bytesafter;
	unsigned char *data;

	if (argc < 2) {
		Tcl_AppendResult(interp, "wrong # args, should be \"", argv[0],
				 " option ?arg arg ...?\"", (char *) NULL);
		return TCL_ERROR;
	}

	/*
	 * Check which option we were given
	 */

	if (strcmp(argv[1], "list") == 0) {

		return ListWindows(interp, Tk_Display(main));

	} else if (strcmp(argv[1], "version") == 0 ||
		   strcmp(argv[1], "url") == 0) {

		/*
		 * Handle the "version" or the "url" command.  This code
		 * is nearly identical, except that a different property
		 * is fetched at the last part.
		 */

		if (argc != 3) {
			Tcl_AppendResult(interp, "Wrong # args, must be: \"",
					 argv[0], " ", argv[1], " windowId\"",
					 (char *) NULL);
			return TCL_ERROR;
		}

		if (Tcl_GetInt(interp, argv[2], (int *) &w) != TCL_OK) {
			return TCL_ERROR;
		}

		error = Tk_CreateErrorHandler(Tk_Display(main), BadWindow,
				      X_GetProperty, -1, NULL, NULL);


		if (! CheckForNetscape(Tk_Display(main), w)) {
			Tcl_AppendResult(interp, "Window is either nonexistant"
					 " or is not a valid Netscape window",
					 (char *) NULL);
			return TCL_ERROR;
		}

		status = XGetWindowProperty(Tk_Display(main), w,
					    argv[1][0] == 'v' ?
					    XA_MOZILLA_VERSION :
					    XA_MOZILLA_URL,
					    0, 65536 / sizeof(long), False,
					    XA_STRING, &type, &format,
					    &nitems, &bytesafter, &data);

		Tk_DeleteErrorHandler(error);

		if (status != Success) {
			Tcl_AppendResult(interp, "Error while reading "
					 " Netscape ", argv[1], (char *) NULL);
			if (data)
				XFree(data);

			return TCL_ERROR;
		}

		Tcl_SetResult(interp, data, TCL_VOLATILE);

		XFree(data);

		return TCL_OK;

	} else {
		Tcl_AppendResult(interp, "Invalid option: \"", argv[1],
				 "\"; must be one of: list version url",
				 (char *) NULL);
		return TCL_ERROR;
	}

	return TCL_OK;
}

/*
 * Find the window to use on the remote display.  Most of this code is
 * taken from Netscape reference implementation.  We don't do any version
 * checking right now.
 */

static Window
GetWindow(interp, main)
Tcl_Interp *interp;
Tk_Window main;
{
	int i;
	Window root = RootWindowOfScreen(Tk_Screen(main));
	Window root2, parent, *kids;
	unsigned int nkids;
	Window result = None;

	/* (CB) Sync display to overcome timing problems: */
	XSync(Tk_Display(main), True);
	
	if (! XQueryTree(Tk_Display(main), root, &root2, &parent, &kids,
			 &nkids)) {
		Tcl_AppendResult(interp, "XQueryTree failed", (char *) NULL);
		return None;
	}

	if (root != root2) {
		Tcl_AppendResult(interp, "Root windows didn't match!",
				 (char *) NULL);
		return None;
	}

	if (parent != None) {
		Tcl_AppendResult(interp, "We got a valid parent window, but",
				 " we shouldn't have!", (char *) NULL);
		return None;
	}

	if (! (kids && nkids)) {
		Tcl_AppendResult(interp, "No children found!", (char *) NULL);
		return None;
	}

	for (i = 0; i < nkids; i++) {
		Window w = XmuClientWindow(Tk_Display(main), kids[i]);
		if (CheckForNetscape(Tk_Display(main), w)) {
			result = w;
			break;
		}
	}

	if (result == None) {
		Tcl_AppendResult(interp, "Couldn't find a netscape window",
				 (char *) NULL);
	}

	return result;
}

/*
 * Return all Netscape windows on a given display.
 */

static int
ListWindows(interp, d)
Tcl_Interp *interp;
Display *d;
{
	Window root = RootWindowOfScreen(DefaultScreenOfDisplay(d));
	Window root2, parent, *kids;
	unsigned int nkids;
	int i;
	char value[256];
	Tcl_DString dstr;

	Tcl_DStringInit(&dstr);

	/*
	 * Much of the work is the same as in GetWindow, but we're going
	 * to return all valid Netscape windows
	 */

	if (! XQueryTree(d, root, &root2, &parent, &kids, &nkids)) {
		Tcl_AppendResult(interp, "XQueryTree failed", (char *) NULL);
		return TCL_ERROR;
	}

	if (root != root2) {
		Tcl_AppendResult(interp, "Root windows didn't match!",
				 (char *) NULL);
		return TCL_ERROR;
	}

	if (parent != None) {
		Tcl_AppendResult(interp, "We got a valid parent window, but",
				 " we shouldn't have!", (char *) NULL);
		return TCL_ERROR;
	}

	if (! (kids && nkids)) {
		Tcl_AppendResult(interp, "No children found!", (char *) NULL);
		return TCL_ERROR;
	}

	for (i = 0; i < nkids; i++) {
		Window w = XmuClientWindow(d, kids[i]);
		if (CheckForNetscape(d, w)) {
			sprintf(value, "0x%08x", (int) w);
			Tcl_DStringAppendElement(&dstr, value);
		}
	}

	Tcl_DStringResult(interp, &dstr);

	return TCL_OK;
}

/*
 * See if the given window is a Netscape window by looking for the
 * XA_MOZILLA_VERSION property
 */

static int
CheckForNetscape(d, w)
Display *d;
Window w;
{
	Atom type;
	int format;
	unsigned long nitems, bytesafter;
	unsigned char *version = NULL;
	int status = XGetWindowProperty(d, w, XA_MOZILLA_VERSION, 0,
					65536 / sizeof(long), False,
					XA_STRING, &type, &format,
					&nitems, &bytesafter, &version);

	if (status != Success || !version) {
		if (version)
			XFree(version);
		return 0;
	}

	/*
	 * We don't do anything with the version right now
	 */

	XFree(version);

	return 1;
}

/*
 * Send a command to the Netscape window we found previously
 */

static int
SendCommand(interp, mainwin, win, command, pending, timeout)
Tcl_Interp *interp;
Tk_Window mainwin;
Window win;
char *command;
PendingCmd *pending;
int timeout;
{
	Tk_RestrictProc *prevRestrict;
#if ((TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)) \
      || (TK_MAJOR_VERSION >= 8)
	ClientData prevArgs;
#if (TK_MAJOR_VERSION >= 8)
	Tcl_TimerToken token;
#endif
#else
	char *prevArgs;
	Tk_TimerToken token;
#endif	
	int result;
	Atom actual_type;
	int actual_format;
	unsigned long nitems, bytes_after;
	unsigned char *data;
	Tk_ErrorHandler error;

	/*
	 * Select for PropertyChange events on the Netscape window
	 */
	
	XSelectInput(Tk_Display(mainwin), win, (PropertyChangeMask |
		     StructureNotifyMask));

	/*
	 * Create a generic event handler to get events on that window
	 */

	pending->state = 0;
	pending->win = None;
	pending->response = 0;

	Tk_CreateGenericHandler(NetscapeEventHandler, (ClientData) pending);

	if (GetLock(interp, Tk_Display(mainwin), win, pending, timeout) == 0) {
		Tk_DeleteGenericHandler(NetscapeEventHandler,
					(ClientData) pending);
		XSelectInput(Tk_Display(mainwin), win, 0);
		return TCL_ERROR;
	}

	/*
	 * We've got a successful lock, so send the command to Netscape
	 */

	XChangeProperty(Tk_Display(mainwin), win, XA_MOZILLA_COMMAND,
			XA_STRING, 8, PropModeReplace,
			(unsigned char *) command, strlen(command));

	/*
	 * Netscape should delete the property containing the command
	 * Wait for this to happen.
	 */

#if ((TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)) \
      || (TK_MAJOR_VERSION >= 8)
	prevRestrict = Tk_RestrictEvents(NetscapeRestrict,
				(ClientData) pending,
				&prevArgs);
#else
	prevRestrict = Tk_RestrictEvents(NetscapeRestrict,
				(char *) pending,
				&prevArgs);
#endif				
	pending->win = win;
	pending->state = PropertyDelete;
	pending->atom = XA_MOZILLA_COMMAND;
	pending->response = 0;

#if (TK_MAJOR_VERSION >= 8)
	token = Tcl_CreateTimerHandler(timeout, LockTimeout, 
					(ClientData) pending);
	while (!pending->response) {
	    Tcl_DoOneEvent(TCL_ALL_EVENTS);
	}
	Tcl_DeleteTimerHandler(token);
#else
#if (TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)
	Tcl_CreateModalTimeout(timeout, LockTimeout, (ClientData) pending);
	while (!pending->response) {
		Tcl_DoOneEvent(TCL_WINDOW_EVENTS);
	}
	Tcl_DeleteModalTimeout(LockTimeout, (ClientData)
			       pending);
#else
	token = Tk_CreateTimerHandler(timeout, LockTimeout, 
					(ClientData) pending);
	while (!pending->response) {
		Tk_DoOneEvent(TK_X_EVENTS);
	}
	Tk_DeleteTimerHandler(token);
#endif		
#endif		
	Tk_RestrictEvents(prevRestrict, prevArgs, &prevArgs);

	if (pending->response == PENDING_TIMEOUT) {
		Tcl_AppendResult(interp, "Timeout waiting for Netscape to ",
				 "acknowledge command", (char *) NULL);
		ReleaseLock(Tk_Display(mainwin), win);
		Tk_DeleteGenericHandler(NetscapeEventHandler,
					(ClientData) pending);
		XSelectInput(Tk_Display(mainwin), win, 0);
		return TCL_ERROR;
	} else if (pending->response == PENDING_DESTROY) {
		Tcl_AppendResult(interp, "Window was destroyed while waiting ",
				 "for acknowledgement", (char *) NULL);
		Tk_DeleteGenericHandler(NetscapeEventHandler,
					(ClientData) pending);
		return TCL_ERROR;
	}

	/*
	 * Wait for a response.  Netscape will write it's response code
	 * in the XA_MOZILLA_RESPONSE property -- check that for the
	 * response code
	 */

#if ((TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)) \
      || (TK_MAJOR_VERSION >= 8)
	prevRestrict = Tk_RestrictEvents(NetscapeRestrict,
				(ClientData) pending,
				&prevArgs);
#else
	prevRestrict = Tk_RestrictEvents(NetscapeRestrict,
				(char *) pending,
				&prevArgs);
#endif				
	pending->win = win;
	pending->state = PropertyNewValue;
	pending->atom = XA_MOZILLA_RESPONSE;
	pending->response = 0;

#if (TK_MAJOR_VERSION >= 8)
	token = Tcl_CreateTimerHandler(timeout, LockTimeout, 
					(ClientData) pending);
	while (!pending->response) {
	    Tcl_DoOneEvent(TCL_ALL_EVENTS);
	}
	Tcl_DeleteTimerHandler(token);
#else
#if (TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)
	Tcl_CreateModalTimeout(timeout, LockTimeout, (ClientData) pending);
	while (!pending->response) {
		Tcl_DoOneEvent(TCL_WINDOW_EVENTS);
	}
	Tcl_DeleteModalTimeout(LockTimeout, (ClientData)
			       pending);
#else
	token = Tk_CreateTimerHandler(timeout, LockTimeout, 
					(ClientData) pending);
	while (!pending->response) {
		Tk_DoOneEvent(TK_X_EVENTS);
	}
	Tk_DeleteTimerHandler(token);
#endif
#endif
	Tk_RestrictEvents(prevRestrict, prevArgs, &prevArgs);

	if (pending->response == PENDING_TIMEOUT) {
		Tcl_AppendResult(interp, "Timeout waiting for a response from",
				 " Netscape", (char *) NULL);
		ReleaseLock(Tk_Display(mainwin), win);
		Tk_DeleteGenericHandler(NetscapeEventHandler,
					(ClientData) pending);
		XSelectInput(Tk_Display(mainwin), win, 0);
		return TCL_ERROR;
	} else if (pending->response == PENDING_DESTROY) {
		Tcl_AppendResult(interp, "Window was destroyed while waiting ",
				 "for a response", (char *) NULL);
		Tk_DeleteGenericHandler(NetscapeEventHandler,
					(ClientData) pending);
		return TCL_ERROR;
	}

	/*
	 * Get the response string from Netscape
	 */
	
	result = XGetWindowProperty(Tk_Display(mainwin), win,
				    XA_MOZILLA_RESPONSE, 0,
				    65536 / sizeof(long), True /* delete */,
				    XA_STRING, &actual_type, &actual_format,
				    &nitems, &bytes_after, &data);
	
	if (result != Success) {
		Tcl_AppendResult(interp, "Failed to read response from "
				 "Netscape", (char *) NULL);
		ReleaseLock(Tk_Display(mainwin), win);
		Tk_DeleteGenericHandler(NetscapeEventHandler,
					(ClientData) pending);
		XSelectInput(Tk_Display(mainwin), win, 0);
		return TCL_ERROR;
	}

	if (! data) {
		Tcl_AppendResult(interp, "No data returned from Netscape",
				 (char *) NULL);
		ReleaseLock(Tk_Display(mainwin), win);
		Tk_DeleteGenericHandler(NetscapeEventHandler,
					(ClientData) pending);
		XSelectInput(Tk_Display(mainwin), win, 0);
		return TCL_ERROR;
	}

	Tcl_AppendResult(interp, data, (char *) NULL);

	XFree(data);

	/*
	 * Remove the lock on Netscape.  Note that first we install an
	 * error handler for BadWindow errors.  We do this because if we
	 * send Netscape a command such as delete() or exit(), Netscape
	 * will destroy that window before we can clean up completely.
	 * The error handler prevents our Tk application from exiting.
	 */

	error = Tk_CreateErrorHandler(Tk_Display(mainwin), BadWindow,
				      X_ChangeWindowAttributes, -1, NULL,
				      NULL);

	ReleaseLock(Tk_Display(mainwin), win);

	/*
	 * Delete the generic event handler (otherwise we would be getting
	 * _all_ X events, which would be wasteful)
	 */

	Tk_DeleteGenericHandler(NetscapeEventHandler, (ClientData) pending);

	/*
	 * Don't select these events anymore.
	 */

	XSelectInput(Tk_Display(mainwin), win, 0);

	Tk_DeleteErrorHandler(error);

	return TCL_OK;
}

static int
NetscapeEventHandler(clientData, event)
ClientData clientData;
XEvent *event;
{
	PendingCmd *pending = (PendingCmd *) clientData;

	if (pending->win == None)
		return 0;

	if (event->type == PropertyNotify && event->xproperty.window ==
	    pending->win && event->xproperty.state == pending->state &&
	    event->xproperty.atom == pending->atom) {
		pending->response = PENDING_OK;
	} else if (event->type == DestroyNotify &&
		   event->xdestroywindow.window == pending->win) {
		pending->response = PENDING_DESTROY;
	}

	return 0;
}

/*
 * Participate in the Netscape locking protocol so our commands don't
 * collide
 */

static int
GetLock(interp, d, win, pending, timeout)
Tcl_Interp *interp;
Display *d;
Window win;
PendingCmd *pending;
int timeout;
{
	char lock_data[255];
	Bool locked = False;
	Tk_RestrictProc *prevRestrict;
#if ((TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)) \
      || (TK_MAJOR_VERSION >= 8)
	ClientData prevArgs;
#if (TK_MAJOR_VERSION >= 8)
	Tcl_TimerToken token;
#endif
#else
	char *prevArgs;
	Tk_TimerToken token;
#endif		

	sprintf(lock_data, "TkApp-pid%d@", getpid());
	if (gethostname(lock_data + strlen(lock_data), 100) == -1) {
		Tcl_AppendResult(interp, "gethostname() returned an error",
				 (char *) NULL);
		return 0;
	}

	do {
		int result;
		Atom actual_type;
		int actual_format;
		unsigned long nitems, bytes_after;
		unsigned char *data = NULL;

		/*
		 * Grab the server so nobody else can do anything
		 */

		XGrabServer(d);

		/*
		 * See if it's locked
		 */

		result = XGetWindowProperty(d, win, XA_MOZILLA_LOCK,
					    0, (65536 / sizeof(long)),
					    False, XA_STRING,
					    &actual_type, &actual_format,
					    &nitems, &bytes_after,
					    &data);

		if (result != Success || actual_type == None) {
			/*
			 * It's not locked now, lock it!
			 */

			 XChangeProperty(d, win, XA_MOZILLA_LOCK, XA_STRING,
					 8, PropModeReplace,
					 (unsigned char *) lock_data,
					 strlen(lock_data));
			locked = True;
		}

		/*
		 * Release the server grab
		 */

		XUngrabServer(d);
		XSync(d, False);

		if (! locked) {
			/*
			 * There was already a lock in place.  Wait for
			 * a PropertyDelete event.  Use a RestrictProc
			 * to make sure we're synchronous
			 */

#if ((TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)) \
		  || (TK_MAJOR_VERSION >= 8)
			prevRestrict = Tk_RestrictEvents(NetscapeRestrict,
						(ClientData) pending,
						&prevArgs);
#else
			prevRestrict = Tk_RestrictEvents(NetscapeRestrict,
						(char *) pending,
						&prevArgs);
#endif						
			pending->win = win;
			pending->state = PropertyDelete;
			pending->atom = XA_MOZILLA_LOCK;
			pending->response = 0;
#if (TK_MAJOR_VERSION >= 8)
	token = Tcl_CreateTimerHandler(timeout, LockTimeout, 
					(ClientData) pending);
	while (!pending->response) {
	    Tcl_DoOneEvent(TCL_ALL_EVENTS);
	}
	Tcl_DeleteTimerHandler(token);
#else
#if (TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)
	Tcl_CreateModalTimeout(timeout, LockTimeout, (ClientData) pending);
			while (!pending->response) {
				Tcl_DoOneEvent(TCL_WINDOW_EVENTS);
			}
			Tcl_DeleteModalTimeout(LockTimeout, (ClientData)
					       pending);
#else
	token = Tk_CreateTimerHandler(timeout, LockTimeout, 
					(ClientData) pending);
	while (!pending->response) {
		Tk_DoOneEvent(TK_X_EVENTS);
	}
	Tk_DeleteTimerHandler(token);
#endif
#endif
			Tk_RestrictEvents(prevRestrict, prevArgs, &prevArgs);

			if (pending->response == PENDING_TIMEOUT) {
				Tcl_AppendResult(interp, "Timeout waiting for "
						 "locked to be released",
						 (char *) NULL);
				if (data) {
					Tcl_AppendResult(interp, " by ",
							 data, (char *) NULL);
					XFree(data);
				}
				break;
			} else if (pending->response == PENDING_DESTROY) {
				Tcl_AppendResult(interp, "Window was destoyed "
						 "while trying to get lock",
						 (char *) NULL);
				if (data)
					XFree(data);
				break;
			}
		}

		if (data)
			XFree(data);
	} while (! locked);

	return locked == True ? 1 : 0;
}

/*
 * Unlock our lock with Netscape.  We should check for errors, but this
 * routine doesn't
 */

static void
ReleaseLock(d, win)
Display *d;
Window win;
{
	Atom actual_type;
	int actual_format;
	unsigned long nitems, bytes_after;
	unsigned char *data;

	XGetWindowProperty(d, win, XA_MOZILLA_LOCK, 0,
			   65536 / sizeof(long), True /* delete */,
			   XA_STRING, &actual_type, &actual_format,
			   &nitems, &bytes_after, &data);
		
	if (data)
		XFree(data);
}

#if ((TK_MAJOR_VERSION == 4) && (TK_MINOR_VERSION > 0)) \
       || (TK_MAJOR_VERSION >= 8)
static Tk_RestrictAction
NetscapeRestrict(clientData, event)
ClientData clientData;
XEvent *event;
{
	PendingCmd *pending = (PendingCmd *) clientData;

	if ((event->type != PropertyNotify ||
	     event->xproperty.window != pending->win ||
	     event->xproperty.atom != pending->atom) &&
	    (event->type != DestroyNotify ||
	     event->xdestroywindow.window != pending->win)) {
		return TK_DEFER_EVENT;
	}

	return TK_PROCESS_EVENT;
}
#else
static Bool
NetscapeRestrict(display, event, arg)
Display *display;
XEvent *event;
char *arg;
{
	PendingCmd *pending = (PendingCmd *) arg;

	if ((event->type != PropertyNotify ||
	     event->xproperty.window != pending->win ||
	     event->xproperty.atom != pending->atom) &&
	    (event->type != DestroyNotify ||
	     event->xdestroywindow.window != pending->win)) {
		return False;
	}

	return True;
}
#endif

static void
LockTimeout(clientData)
ClientData clientData;
{
	PendingCmd *pending = (PendingCmd *) clientData;

	pending->response = PENDING_TIMEOUT;
}
