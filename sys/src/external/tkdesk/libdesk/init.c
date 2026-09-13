/* ============================================================================
 *
 * File:	init.c
 * Project:	TkDesk
 * Started:	07.10.94
 * Changed:	20.04.96
 *
 * Description:	Initializes libdesk's new commands when starting up.
 *
 * Copyright (C) 1996  Christian Bolik
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * See the file "COPYING" in the base directory of this distribution
 * for more.
 *
 * ----------------------------------------------------------------------------
 *
 * Functions:
 *	Dsk_Init (Tcl_Interp *interp)
 *
 * ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef CATCH_SIGNALS
#include <signal.h>
#include <unistd.h>
#endif
#include "libdesk.h"

#if (TCL_MAJOR_VERSION != 8)
#error "tcl.h is not from version 8.x"
#endif

#ifdef CATCH_SIGNALS
void signal_handler (int signum);
#endif

#define TKDESK_VERSION "2.0b"

Tcl_Interp *dsk_interp;


/* ============================================================================
 * Name: Dsk_Init
 * Desc: Initializes libdesk when called from tkAppInit.
 * In  : interp - Adress of tcl interpreter
 * Out : TCL_OK or TCL_ERROR
 * ------------------------------------------------------------------------- */

int Dsk_Init (interp)
Tcl_Interp *interp;
{

    dsk_interp = interp;

    Tcl_CreateCommand (interp, "dskC_ls", dsk_ls_Cmd, NULL, NULL);
    Tcl_CreateCommand (interp, "dskC_striptc", dsk_striptc_Cmd, NULL, NULL);
    Tcl_CreateCommand (interp, "dskC_esc", dsk_esc_Cmd, NULL, NULL);
    Tcl_CreateCommand (interp, "dskC_unesc", dsk_unesc_Cmd, NULL, NULL);
    Tcl_CreateCommand (interp, "dskC_localtime", dsk_localtime_Cmd, NULL, NULL);
    Tcl_CreateCommand (interp, "dskC_statfs", dsk_statfs_Cmd, NULL, NULL);

    /* these commands are for tcl optimization: */
    Tcl_CreateCommand (interp, "dskC_ls_and_tag", dsk_ls_and_tag_Cmd, NULL, NULL);
    Tcl_CreateCommand (interp, "dskC_init_ftags", dsk_init_ftags_Cmd, NULL, NULL);

    Tcl_SetVar (interp, "dskC_version", TKDESK_VERSION, TCL_GLOBAL_ONLY);

#ifdef CATCH_SIGNALS
    /* signal handling */
    /* Unfortunately, there's not enough time for saving TkDesk's layout
       when a SIGHP is caught (eg. when X exits). */
    /*signal (SIGHUP, signal_handler);*/
#endif

    return (TCL_OK);
} /* Dsk_Init */


#ifdef CATCH_SIGNALS
/* ---------------------------------------------------------------------------
   signal_handler:
   A very simple and naive signal handler. Tries to invoke a Tcl command
   to handle the received signal.
   */

void signal_handler (signum)
int signum;
{
    
    signal (signum, SIG_IGN);
    /*fprintf (stderr, "Signal: %d\n", signum);*/

    switch (signum) {
    case SIGHUP:
	Tcl_GlobalEval (dsk_interp, "eval $tkdesk(signal_handler,SIGHUP)");
	break;
    case SIGCHLD:
	Tcl_GlobalEval (dsk_interp, "eval $tkdesk(signal_handler,SIGCHLD)");
	break;
    }

    /* ignore Tcl errors for now: */
    dsk_interp->result = "";
    
    signal (signum, signal_handler);
} /* signal_handler */
#endif
