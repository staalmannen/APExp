/* ============================================================================
 *
 * File:	tkAppInit.c
 * Project:	TkDesk
 * Started:	02.10.94
 * Changed:	09.07.96
 *
 * Description:	Initializes Tcl, Tk and TkDesk. Is a modified tkAppInit.c.
 *
 * ----------------------------------------------------------------------------
 *
 * Functions:
 *	Tcl_AppInit --
 *
 *
 * ========================================================================= */

/* ========== Here follows the original header from tkAppInit.c: =========== */
/* 
 * tkAppInit.c --
 *
 *	Provides a default version of the Tcl_AppInit procedure for
 *	use in wish and similar Tk-based applications.
 *
 * Copyright (c) 1993 The Regents of the University of California.
 * Copyright (c) 1994 Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */
/*
#ifndef lint
static char sccsid[] = "@(#) tkAppInit.c 1.12 94/12/17 16:30:56";
#endif
*/
#include "config.h"
#include "tk.h"
#include "libdesk/ot.h"


/*
 * The following variable is a special hack that is needed in order for
 * Sun shared libraries to be used for Tcl.
 *
 * [Is this still needed? --JCC]
 */

#ifdef NEED_MATHERR
extern int matherr();
int *tclDummyMathPtr = (int *) matherr;
#endif

/*
 *----------------------------------------------------------------------
 *
 * main --
 *
 *	This is the main program for the application.
 *
 * Results:
 *	None: Tk_Main never returns here, so this procedure never
 *	returns either.
 *
 * Side effects:
 *	Whatever the application does.
 *
 *----------------------------------------------------------------------
 */

int
main(argc, argv)
    int argc;			/* Number of command-line arguments. */
    char **argv;		/* Values of command-line arguments. */
{
    
    if (getenv ("DISPLAY") == NULL) {
	fprintf (stderr, "\nTkDesk requires the X Window System to run and the DISPLAY\n");
	fprintf (stderr, "environment variable to be set.  If X is already running you\n");
	fprintf (stderr, "can set the DISPLAY variable for instance like this:\n\n");
	fprintf (stderr, "DISPLAY=:0.0; export DISPLAY\n\n");
	exit (1);
    }
    
    Tk_Main(argc, argv, Tcl_AppInit);
    return 0;			/* Needed only to prevent compiler warning. */
}

/*
 *----------------------------------------------------------------------
 *
 * Tcl_AppInit --
 *
 *	This procedure performs application-specific initialization.
 *	Most applications, especially those that incorporate additional
 *	packages, will have their own version of this procedure.
 *
 * Results:
 *	Returns a standard Tcl completion code, and leaves an error
 *	message in interp->result if an error occurs.
 *
 * Side effects:
 *	Depends on the startup script.
 *
 *----------------------------------------------------------------------
 */

int
Tcl_AppInit(interp)
    Tcl_Interp *interp;		/* Interpreter for application. */
{
    Tk_Window main;
    extern int Itcl_Init _ANSI_ARGS_((Tcl_Interp *));
    extern int Blt_Init _ANSI_ARGS_((Tcl_Interp *));
    extern int Netscape_remote_Init _ANSI_ARGS_((Tcl_Interp *));
    extern int Dsk_Init _ANSI_ARGS_((Tcl_Interp *));
    extern Tk_ImageType tixPixmapImageType;

    main = Tk_MainWindow(interp);

    if (Tcl_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
    if (Tk_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }

    Tk_CreateImageType(&tixPixmapImageType);
    
    /*
     * Call the init procedures for included packages.  Each call should
     * look like this:
     *
     * if (Mod_Init(interp) == TCL_ERROR) {
     *     return TCL_ERROR;
     * }
     *
     * where "Mod" is the name of the module.
     */

    if (Itcl_Init(interp) == TCL_ERROR) {
            return TCL_ERROR;
    }
    if (Blt_Init(interp) == TCL_ERROR) {
        return TCL_ERROR;
    }
    if (Ot_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
    if (Netscape_remote_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
    if (Dsk_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
    
    /*
     * Call Tcl_CreateCommand for application-specific commands, if
     * they weren't already created by the init procedures called above.
     */

    /*
     * Specify a user-specific startup file to invoke if the application
     * is run interactively.  Typically the startup file is "~/.apprc"
     * where "app" is the name of the application.  If this line is deleted
     * then no user-specific startup file will be run under any conditions.
     */

    /*tcl_RcFileName = "~/.tkdeskrc";*/
    return TCL_OK;
}

