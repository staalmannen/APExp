/* ============================================================================
 *
 * File:	misc.c
 * Project:	TkDesk
 * Started:	05.01.94
 * Changed:	31.03.96
 *
 * Description:	Implements several utility Tcl commands for TkDesk.
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
 *
 *
 * ========================================================================= */

#include "libdesk.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#ifdef HAVE_SYS_VFS_H
#include <sys/vfs.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#ifdef HAVE_SYS_MOUNT_H
#include <sys/mount.h>
#endif
#ifdef HAVE_STATVFS_H
#include <sys/types.h>
#include <statvfs.h>
#endif
#ifdef HAVE_SYS_STATVFS_H
#include <sys/types.h>
#include <sys/statvfs.h>
#endif

/* ============================================================================
 * Name   : dsk_stripc_Cmd
 * In     : ...
 * Out    : ...
 * Desc   : Syntax: dsk_stripc ?-keep? string
 *          This strips the file type character (one of "/@*+-_") from the
 *          string string. If the -keep option is given, only one of "+-_"
 *          will be removed.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int dsk_striptc_Cmd (clientData, interp, argc, argv)
    ClientData clientData;
    Tcl_Interp *interp;
    int argc;
    char *argv[];
{
    int keep = 0, i;
    char tc;
    char instr[TCL_RESULT_SIZE], outstr[TCL_RESULT_SIZE];
    
    if (argc < 2 || argc > 3) {
	sprintf (interp->result, "usage: dsk_striptc ?-keep? string");
	return (TCL_ERROR);
    }
    if (argc == 3) {
        if (strcmp ("-keep", argv[1]) == 0) {
            keep = 1;
            strcpy(instr, argv[2]);
        } else {
            sprintf (interp->result, "usage: dsk_striptc ?-keep? string");
            return (TCL_ERROR);
        }
    } else {
	strcpy(instr, argv[1]);
    }

    if (instr[0] == 0) {
	*interp->result = 0;
	return (TCL_OK);
    }

    strcpy (outstr, instr);
    i = 0;
    while (outstr[i+1]) {
	if (outstr[i+1] == '\\' && (outstr[i+2] == 't'))
	    break;
	i++;
    }
    /* outstr[i] now contains the type character */
    tc = outstr[i];
    if (!keep) {
	if (tc == '@' || tc == '*' || tc == '/' || tc == '+'
	    || tc == '-' || tc == '=' || tc == '_') {
	    if (outstr[i+1])
		outstr[i] = ' ';
	    else 
		outstr[i] = '\0';
	}
    } else {
	if (tc == '_') {
	    if (outstr[i+1])
		outstr[i] = ' ';
	    else 
		outstr[i] = '\0';
	}
    }

    strcpy (interp->result, outstr);
    return (TCL_OK);
} /* dsk_striptc_Cmd */


/* ----------------------------------------------------------------------------
 * dsk_esc_Cmd:
 * Tcl command: dsk_esc string chars
 * Precedes each char in $string if it is in $chars. Returns the result.
 */
int dsk_esc_Cmd (clientData, interp, argc, argv)
    ClientData clientData;
    Tcl_Interp *interp;
    int argc;
    char *argv[];
{
    char *buf;

    if (argc != 3) {
	sprintf (interp->result, "usage: dsk_esc string chars");
	return (TCL_ERROR);
    }

    /* assume every char needs to be backslashed, for safety reasons */
    buf = (char *) malloc (strlen (argv[1]) * 2);
    if (buf == NULL) {
	fprintf (stderr, "out of memory in dsk_esc_Cmd\n");
	exit (1);
    }

    escape_chars (argv[1], argv[2], buf);
    Tcl_SetResult (interp, buf, TCL_VOLATILE);
    free (buf);
    
    return TCL_OK;
} /* dsk_esc_Cmd */

/* ----------------------------------------------------------------------------
 * dsk_unesc_Cmd:
 * Tcl command: dsk_unesc string
 * Removes all the backslashes in $string except before }.
 */
int dsk_unesc_Cmd (clientData, interp, argc, argv)
    ClientData clientData;
    Tcl_Interp *interp;
    int argc;
    char *argv[];
{
    char *buf;

    if (argc != 2) {
	strcpy (interp->result, "usage: dsk_unesc string");
	return (TCL_ERROR);
    }

    /* assume every char needs to be backslashed, for safety reasons */
    buf = (char *) malloc (strlen (argv[1]) * 2);
    if (buf == NULL) {
	fprintf (stderr, "out of memory in dsk_esc_Cmd\n");
	exit (1);
    }

    unescape_chars (argv[1], buf);
    Tcl_SetResult (interp, buf, TCL_VOLATILE);
    free (buf);
    
    return TCL_OK;
} /* dsk_esc_Cmd */

/* ----------------------------------------------------------------------------
 * dsk_localtime_Cmd:
 * Tcl command: dsk_localtime_Cmd
 * Returns the current time in "array set" format.  The elements correspond
 * to the entries of "struct tm".
 */
int dsk_localtime_Cmd (clientData, interp, argc, argv)
    ClientData clientData;
    Tcl_Interp *interp;
    int argc;
    char *argv[];
{
    time_t t;
    struct tm *ts;
    char buf[10];

    t = time (NULL);
    ts = localtime (&t);

    sprintf (buf, "%02d ", ts->tm_sec);
    Tcl_AppendResult (interp, "sec ", buf, NULL);
    sprintf (buf, "%02d ", ts->tm_min);
    Tcl_AppendResult (interp, "min ", buf, NULL);
    sprintf (buf, "%02d ", ts->tm_hour);
    Tcl_AppendResult (interp, "hour ", buf, NULL);

    sprintf (buf, "%d ", ts->tm_mday);
    Tcl_AppendResult (interp, "mday ", buf, NULL);
    sprintf (buf, "%d ", ts->tm_mon);
    Tcl_AppendResult (interp, "mon ", buf, NULL);
    sprintf (buf, "%d ", ts->tm_year % 100);
    Tcl_AppendResult (interp, "year ", buf, NULL);
    
    sprintf (buf, "%d ", ts->tm_wday);
    Tcl_AppendResult (interp, "wday ", buf, NULL);
    sprintf (buf, "%d ", ts->tm_yday);
    Tcl_AppendResult (interp, "yday ", buf, NULL);
    sprintf (buf, "%d ", ts->tm_isdst);
    Tcl_AppendResult (interp, "isdst ", buf, NULL);

    return (TCL_OK);
} /* dsk_localtime_Cmd */

/* ----------------------------------------------------------------------------
 * dsk_statfs_Cmd:
 * Tcl command: dsk_statfs path?/file?
 * Returns info about the file system $path resides on, as a
 * list with three elements: {totalBlocks freeBlocks percentFree}
 */
int dsk_statfs_Cmd (clientData, interp, argc, argv)
    ClientData clientData;
    Tcl_Interp *interp;
    int argc;
    char *argv[];
{
#if defined(HAVE_STATFS) || defined(HAVE_STATVFS)
    
# ifdef HAVE_STATVFS
    struct statvfs fs;
# else
    struct statfs fs;
# endif
    char buf[64];
    
    if (argc != 2) {
	strcpy (interp->result, "usage: dskC_statfs path?/file?");
	return TCL_ERROR;
    }

# ifdef HAVE_STATVFS
    if (statvfs (argv[1], &fs) == 0) {
# else
    if (statfs (argv[1], &fs) == 0) {
# endif
	if (fs.f_bsize == 0)
	    fs.f_bsize = 1024;
	if (fs.f_blocks == 0)
	    fs.f_blocks = fs.f_bavail;
	
# ifdef HAVE_STATVFS
	strcpy (buf, itoa((long)((double)fs.f_blocks/(1024./fs.f_frsize))));
# else
	strcpy (buf, itoa((long)((double)fs.f_blocks/(1024./fs.f_bsize))));
# endif
	strcat (buf, " ");
# ifdef HAVE_STATVFS
	strcat (buf, itoa((long)((double)fs.f_bavail/(1024./fs.f_frsize))));
# else
	strcat (buf, itoa((long)((double)fs.f_bavail/(1024./fs.f_bsize))));
# endif
	strcat (buf, " ");
	if (fs.f_blocks > 0)
	    strcat (buf, itoa((long)((double)fs.f_bavail
				     / (double)fs.f_blocks * 100)));
	else
	    strcat (buf, "0");
	
	Tcl_AppendResult (interp, buf, NULL);
	return TCL_OK;
	
    } else {
	sprintf (interp->result, "Error %d", errno);
	return TCL_ERROR;
    }
    
#else
    
    strcpy (interp->result, "");
    return TCL_OK;
    
#endif    
} /*dsk_statfs_Cmd */
