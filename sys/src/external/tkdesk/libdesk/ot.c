/* ============================================================================
 *
 * File:	ot.c
 * Project:	ot - Optimizing Tcl
 * Started:	12.02.94
 * Changed:	12.02.94
 *
 * Description:	This file creates a few new tcl commands for optimizing
 *              tcl code and implements a few utility functions for using
 *              the Tcl/Tk C libraries.
 *
 * ----------------------------------------------------------------------------
 *
 * Sections:
 *     int Ot_Init
 *     ===== Tcl Commands
 *     int ot_timer_Cmd
 *     ===== Utility Functions
 *     int Ot_TclInvoke
 *     int Ot_GetInt
 *     int Ot_GetDouble
 *     int Ot_GetBoolean
 *
 * ========================================================================= */

#include "ot.h"

#ifdef OTTIMER
/* the following three includes are for gettimeofday() */
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#endif


/* ============================================================================
 * Name: Ot_Init
 * Desc: Initializes ot and creates the new Tcl-commands.
 * In  : interp - Adress of tcl interpreter
 * Out : TCL_OK
 * SFX : 
 * ------------------------------------------------------------------------- */

int Ot_Init (interp)
Tcl_Interp *interp;
{
#ifdef OTTIMER
    Tcl_CreateCommand (interp, "ot_timer", ot_timer_Cmd, NULL, NULL);
#endif
    Tcl_CreateCommand (interp, "ot_maplist", ot_maplist_Cmd, NULL, NULL);
#ifndef NO_TK
    Tcl_CreateCommand (interp, "ot_warp_pointer",
		       ot_warp_pointer_Cmd, NULL, NULL);
#endif

    return TCL_OK;
}



/* ===== Tcl Commands ====================================================== */


#ifdef OTTIMER
/* ============================================================================
 * Name   : ot_timer_Cmd
 * In     : ...
 * Out    : ...
 * Desc   : Implements the tcl command ot_timer <"set"|"get"> <varname>,
 *          that helps to measure the time between a call to "ot_timer set"
 *          and a call to "ot_timer get". $varname is the name of a variable
 *          where to store the timestamp ("set"). "ot_timer get <varname>"
 *          returns the time bw. this call and "ot_timer set <varname>" in
 *          seconds.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int ot_timer_Cmd (clientData, interp, argc, argv)
ClientData clientData;
Tcl_Interp *interp;
int argc;
char *argv[];
{
#ifdef __hpux
    extern struct timeval {
	unsigned long tv_sec;	/* seconds */
	long tv_usec;	        /* and microseconds */
    };
#endif
    struct timeval tv;
    double curtm, lasttm;
    char buf[32], *vp;
    
    if (argc != 3) {
	interp->result = "usage: ot_timer <\"set\"|\"get\"> <varname>";
	return TCL_ERROR;
    }

    gettimeofday (&tv, NULL);
    /* convert time to seconds (float): */
    curtm = tv.tv_sec + tv.tv_usec / 1000000.;
    
    if (strcmp (argv[1], "set") == 0) {
	sprintf (buf, "%f", curtm);
	if (Tcl_SetVar (interp, argv[2], buf, TCL_LEAVE_ERR_MSG) == NULL) {
	    return TCL_ERROR;
	} else {
	    strcpy (interp->result, buf);
	    return TCL_OK;
	}
	
    } else if (strcmp (argv[1], "get") == 0) {
	if ((vp = Tcl_GetVar (interp, argv[2], TCL_LEAVE_ERR_MSG)) == NULL) {
	    return TCL_ERROR;
	} else {
	    if (Tcl_GetDouble (interp, vp, &lasttm) != TCL_OK) {
		return TCL_ERROR;
	    }
	    sprintf (interp->result, "%f", curtm - lasttm);
	    return TCL_OK;
	}
	
    } else {
	interp->result = "usage: ot_timer <\"set\"|\"get\"> <varname>";
	return TCL_ERROR;
    }
} /* ot_time_Cmd */
#endif


/* ============================================================================
 * Name   : ot_maplist_Cmd
 * In     : ... (argv[1]: a tcl list, argv[2...n]: names of tcl variables)
 * Out    : ... ("")
 * Desc   : Implements the tcl command ot_maplist list ?var var ...?
 *          list is a tcl list, var are tcl variables. Each of the named
 *          tcl variable will be set to the respective element of list, i.e.
 *          the first variable will be set to the first element, the second
 *          to the second and so on.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int ot_maplist_Cmd (clientData, interp, argc, argv)
ClientData clientData;
Tcl_Interp *interp;
int argc;
char *argv[];
{
    int largc, i, j;
    char **largv;

    if (argc < 3) {
	interp->result = "usage: ot_maplist list var ?var ...?";
	return TCL_ERROR;
    }

    if (Tcl_SplitList (interp, argv[1], &largc, &largv) == TCL_ERROR) {
	return TCL_ERROR;
    }

    for (i = 0; i < largc; i++) {
	if (!Tcl_SetVar (interp, argv[i + 2], largv[i], TCL_LEAVE_ERR_MSG)) {
	    free (largv);
	    return TCL_ERROR;
	}

	if (i == argc - 3) {
	    /* last variable */
	    for (j = i + 1; j < largc; j++) {
		if (!Tcl_SetVar (interp, argv[i + 2], largv[j],
		       TCL_LEAVE_ERR_MSG|TCL_LIST_ELEMENT|TCL_APPEND_VALUE)) {
		    free (largv);
		    return TCL_ERROR;
		}
	    }
	    break;
	}
    }

    free (largv);
    return TCL_OK;
} /* ot_maplist_Cmd */

/* ============================================================================
 * Name   : ot_warp_pointer_Cmd
 * In     : ... (argv[1]: a tk window or x coordinate,
 *               argv[2]: (opt.) y coordinate)
 * Out    : ... ("")
 * Desc   : Implements the tcl command ot_warp_pointer win|x ?y?
 *          The mouse pointer will be centered over $win or be put at $x/$y.
 * Side-FX: Generates mouse motion events.
 * ------------------------------------------------------------------------- */

#ifndef NO_TK

int ot_warp_pointer_Cmd (clientData, interp, argc, argv)
ClientData clientData;
Tcl_Interp *interp;
int argc;
char *argv[];
{
    Tk_Window tkwin;
    Window wid;
    int x, y;
    
    if (argc != 2 && argc != 3) {
	interp->result = "usage: ot_warp_pointer window / ot_warp_pointer x y";
	return TCL_ERROR;
    }

    if (argc == 2) {
	tkwin = Tk_NameToWindow (interp, argv[1], Tk_MainWindow (interp));
	if (!tkwin)
	  return TCL_ERROR;

	x = Tk_Width (tkwin) / 2;
	y = Tk_Height (tkwin) / 2;
	wid = Tk_WindowId (tkwin);
    } else {
	tkwin = Tk_MainWindow (interp);
	tcl_getint (argv[1], &x);
	tcl_getint (argv[2], &y);
	wid = RootWindow (Tk_Display (tkwin), 0);
    }

    XWarpPointer (Tk_Display (tkwin), None, wid, 0, 0, 0, 0, x, y);

    return TCL_OK;
} /* ot_warp_pointer_Cmd */

#endif


/* ===== Utility Functions ================================================= */


/* ============================================================================
 * Name   : Ot_TclInvoke
 * In     : interp - Tcl interpreter
 *          cmd - command to invoke
 * Out    : return value of the invoked command
 * Desc   : This invokes the tcl command specified by argc and argv directly
 *          without performing any kind of substitution. That's why it should
 *          be considerably faster than Tcl_Eval.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int Ot_TclInvoke (interp, cmd)
Tcl_Interp *interp;
char *cmd;
{
    Tcl_CmdInfo cmdInfo;
    int argc, retval;
    char **argv;

#ifdef ODEBUG
    fprintf (stderr, "(Ot_TclInvoke) %s\n", cmd);
#endif

    if (Tcl_SplitList (interp, cmd, &argc, &argv) != TCL_OK) {
        return TCL_ERROR;
    }

    if (Tcl_GetCommandInfo (interp, argv[0], &cmdInfo) == 0) {
        sprintf (interp->result, "invalid command name \"%s\"", argv[0]);
	free (argv);
        return TCL_ERROR;
    }

    Tcl_ResetResult (interp);
    retval = (*cmdInfo.proc) (cmdInfo.clientData, interp, argc, argv);
    free (argv);
    return retval;
} /* Ot_TclInvoke */


/* ============================================================================
 * Name   : Ot_GetInt
 * In     : interp - tcl interpreter
 *          var - name of tcl variable
 *          index - NULL or name of index if var is an array variable
 *          val - pointer of type int (value of $var will be stored here)
 * Out    : TCL_OK or TCL_ERROR
 * Desc   : Stores the value of the given variable at *val as an integer.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int Ot_GetInt (interp, var, index, val)
Tcl_Interp *interp;
char *var;
char *index;
int *val;
{
    char *v_value;

    if (!index) {
	if (!(v_value = (char *) Tcl_GetVar (interp, var, TCL_LEAVE_ERR_MSG))) {
	    return TCL_ERROR;
	}
    } else {
	if (!(v_value = (char *) Tcl_GetVar2 (interp, var, index, TCL_LEAVE_ERR_MSG))) {
	    return TCL_ERROR;
	}
#ifdef ODEBUG
	fprintf (stderr, "(Ot_GetInt) %s(%s) : %s\n", var, index, v_value);
#endif
    }

    return Tcl_GetInt (interp, v_value, val);
} /* Ot_GetInt */


/* ============================================================================
 * Name   : Ot_GetDouble
 * In     : interp - tcl interpreter
 *          var - name of tcl variable
 *          index - NULL or name of index if var is an array variable
 *          val - pointer of type double (value of $var will be stored here)
 * Out    : TCL_OK or TCL_ERROR
 * Desc   : Stores the value of the given variable at *val as a double.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int Ot_GetDouble (interp, var, index, val)
Tcl_Interp *interp;
char *var;
char *index;
double *val;
{
    char *v_value;

    if (!index) {
	if (!(v_value = (char *) Tcl_GetVar (interp, var, TCL_LEAVE_ERR_MSG))) {
	    return TCL_ERROR;
	}
    } else {
	if (!(v_value = (char *) Tcl_GetVar2 (interp, var, index, TCL_LEAVE_ERR_MSG))) {
	    return TCL_ERROR;
	}
    }

    return Tcl_GetDouble (interp, v_value, val);
} /* Ot_GetDouble */


/* ============================================================================
 * Name   : Ot_GetBoolean
 * In     : interp - tcl interpreter
 *          var - name of tcl variable
 *          index - NULL or name of index if var is an array variable
 *          val - pointer of type int (value of $var will be stored here)
 * Out    : TCL_OK or TCL_ERROR
 * Desc   : Stores the value of the given variable at *val as an integer.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int Ot_GetBoolean (interp, var, index, val)
Tcl_Interp *interp;
char *var;
char *index;
int *val;
{
    char *v_value;

    if (!index) {
	if (!(v_value = (char *) Tcl_GetVar (interp, var, TCL_LEAVE_ERR_MSG))) {
	    return TCL_ERROR;
	}
    } else {
	if (!(v_value = (char *) Tcl_GetVar2 (interp, var, index, TCL_LEAVE_ERR_MSG))) {
	    return TCL_ERROR;
	}
    }

    return Tcl_GetBoolean (interp, v_value, val);
} /* Ot_GetBoolean */


/* ============================================================================
 * Name   : Ot_GetVar
 * In     : interp - tcl interpreter
 *          var - name of tcl variable
 *          flags - OR'ed Tcl flags
 * Out    : Pointer to var's value or NULL
 * ------------------------------------------------------------------------- */
char *Ot_GetVar (interp, var, flags)
     Tcl_Interp *interp;
     char       *var;
     int         flags;
{
#if TCL_MAJOR_VERSION < 8
    return Tcl_GetVar (interp, var, flags);
#else
    Tcl_Obj *obj;

    obj = Tcl_ObjGetVar2 (interp, Tcl_NewStringObj (var, -1), NULL, flags);
    if (obj != NULL)
	return Tcl_GetStringFromObj (obj, NULL);
    else
	return NULL;
#endif
}


/* ============================================================================
 * Name   : Ot_GetVar2
 * In     : interp - tcl interpreter
 *          var - name of tcl variable
 *          ind - "index" of array var
 *          flags - OR'ed Tcl flags
 * Out    : Pointer to var's value or NULL
 * ------------------------------------------------------------------------- */
char *Ot_GetVar2 (interp, var, ind, flags)
     Tcl_Interp *interp;
     char       *var;
     char       *ind;
     int         flags;
{
#if TCL_MAJOR_VERSION < 8
    return Tcl_GetVar2 (interp, var, ind, flags);
#else
    Tcl_Obj *obj;

    obj = Tcl_ObjGetVar2 (interp, Tcl_NewStringObj (var, -1),
			  Tcl_NewStringObj (ind, -1), flags);
    if (obj != NULL)
	return Tcl_GetStringFromObj (obj, NULL);
    else
	return NULL;
#endif
}


/* ============================================================================
 * Name   : Ot_SetVar
 * In     : interp - tcl interpreter
 *          var - name of tcl variable
 *          newval - new value of var
 *          flags - OR'ed Tcl flags
 * Out    : Pointer to var's value or NULL
 * ------------------------------------------------------------------------- */
char *Ot_SetVar (interp, var, newval, flags)
     Tcl_Interp *interp;
     char       *var;
     char       *newval;
     int         flags;
{
#if TCL_MAJOR_VERSION < 8
    return Tcl_SetVar (interp, var, newval, flags);
#else
    Tcl_Obj *obj;

    obj = Tcl_ObjSetVar2 (interp, Tcl_NewStringObj (var, -1), NULL,
			  Tcl_NewStringObj (newval, -1), flags);
    if (obj != NULL)
	return Tcl_GetStringFromObj (obj, NULL);
    else
	return NULL;
#endif
}


/* ============================================================================
 * Name   : Ot_SetVar2
 * In     : interp - tcl interpreter
 *          var - name of tcl variable
 *          newval - new value of var
 *          flags - OR'ed Tcl flags
 * Out    : Pointer to var's value or NULL
 * ------------------------------------------------------------------------- */
char *Ot_SetVar2 (interp, var, ind, newval, flags)
     Tcl_Interp *interp;
     char       *var;
     char       *ind;
     char       *newval;
     int         flags;
{
#if TCL_MAJOR_VERSION < 8
    return Tcl_SetVar2 (interp, var, ind, newval, flags);
#else
    Tcl_Obj *obj;

    obj = Tcl_ObjSetVar2 (interp, Tcl_NewStringObj (var, -1),
			  Tcl_NewStringObj (ind, -1),
			  Tcl_NewStringObj (newval, -1), flags);
    if (obj != NULL)
	return Tcl_GetStringFromObj (obj, NULL);
    else
	return NULL;
#endif
}
