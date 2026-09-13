/* ============================================================================
 *
 * File:	o_FileListbox.c
 * Project:	TkDesk
 * Started:	14.02.95
 * Changed:	14.02.95
 *
 * Description:	Contains optimizations of tcl code from the file
 *              ../tcldesk/FileListbox.tcl. These are implemented as
 *              tcl commands.
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

#include <string.h>
#include "libdesk.h"


/* the ignore list */
static int  iargc;
static char **iargv = NULL;

/* the tag list */
static int  targc;
static char **targv = NULL;

/* the pattern list */
static int  pargc;
static char **pargv = NULL;


/* ============================================================================
 * Name   : dsk_init_ftags_Cmd (tcl: dskC_init_ftags)
 * In     : ... (opt: argv[1]: dsk_FileListbox::taglist,
 *                    argv[2]: dsk_FileListbox::patlist,
 *                    argv[3]: dsk_FileListbox::ignorelist)
 * Out    : ...
 * Desc   : Initializes internal file tags structures.
 * ------------------------------------------------------------------------- */
int dsk_init_ftags_Cmd (clientData, interp, argc, argv)
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
     char *argv[];
{
    char *taglist, *ilist, *plist;

    /* get and split the taglist */
    if (targv != NULL)
	free ((char *)targv);
    if (argc > 1) {
	if (Tcl_SplitList (interp, argv[1], &targc, &targv) == TCL_ERROR)
	    return TCL_ERROR;
    } else {
	ot_getvar ("taglist", taglist);
	if (Tcl_SplitList (interp, taglist, &targc, &targv) == TCL_ERROR)
	    return TCL_ERROR;
    }

    /* get and split tag masks */
    if (pargv != NULL)
	free ((char *)pargv);
    if (argc > 2) {
	if (Tcl_SplitList (interp, argv[2], &pargc, &pargv) == TCL_ERROR)
	    return TCL_ERROR;
    } else {
	ot_getvar ("patlist", plist);
	if (Tcl_SplitList (interp, plist, &pargc, &pargv) == TCL_ERROR)
	    return TCL_ERROR;
    }
    
    /* get and split ignore masks */
    if (iargv != NULL)
	free ((char *)iargv);
    if (argc > 3) {
	if (Tcl_SplitList (interp, argv[3], &iargc, &iargv) == TCL_ERROR)
	    return TCL_ERROR;
    } else {
	ot_getvar ("ignorelist", ilist);
	if (Tcl_SplitList (interp, ilist, &iargc, &iargv) == TCL_ERROR)
	    return TCL_ERROR;
    }
    
    return TCL_OK;
} /* dsk_init_ftags_Cmd */



/* ============================================================================
 * Name   : dsk_ls_and_tag_Cmd (tcl: dskC_ls_and_tag)
 * In     : argv[1]: directory to read and tag
 * Out    : ...
 * Desc   : Reads file list by calling functions from dsk_ls.c, plus does
 *          additional processing like tagging and file masking.
 * Side-FX: none
 * ------------------------------------------------------------------------- */

int dsk_ls_and_tag_Cmd (clientData, interp, argc, argv)
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
     char *argv[];
{
    int i = 0, fargc, k, typechar, largc = 0, dotreg,
	mtags = 0, mtargc, ntd, add_images, notmatch, notmatch_set = 0,
        showall, mask_matches_all, lsargc, maskc = 0, invert_mask;
    char fnametc[256], **maskv, *mask, maskbuf[64], buf[256], *thisP, **lsargv,
	**mtargv, *bufp, filebuf[1024], *lscmd, escbuf[1024], annobuf[1024],
	*frame, this[256];
    Tcl_DString dbigcmd;
#if TCL_MAJOR_VERSION >= 8
    Tcl_Obj *notmatch_obj = Tcl_NewStringObj("mt_notmatch", -1);
    Tcl_Obj *anno_obj = Tcl_NewStringObj("tkdesk_anno", -1);
    Tcl_Obj *annotag_obj = Tcl_NewStringObj("annotag", -1);
    Tcl_Obj *mt_obj = Tcl_NewStringObj("mt", -1);
    Tcl_Obj *obj;
#endif

    if (argc != 2) {
	strcpy (interp->result, "usage: dskC_ls_and_tag path");
	return TCL_ERROR;
    }

    /*
     * get values of required class variables
     */
    ot_getvar ("this", thisP);
    strcpy (this, thisP);          /* need to save this for Tcl 8.x */
    ot_getvar ("frame", frame);
    ot_getboolean ("invert_mask", NULL, &invert_mask);
    ot_getvar ("mask", mask);
    if (strcmp (mask, "*") == 0 && !invert_mask)
       mask_matches_all = 1;
    else {
       mask_matches_all = 0;
       if (Tcl_SplitList (interp, mask, &maskc, &maskv) == TCL_ERROR)
	   return TCL_ERROR;
       /*printf ("%s: %d elements\n", mask, maskc);*/
    }
    ot_getboolean ("typechar", NULL, &typechar);
    ot_getboolean ("notrivialdirs", NULL, &ntd);
    ot_getboolean ("add_icons", NULL, &add_images);
    ot_getboolean ("showall", NULL, &showall);
    ot_getboolean ("dotregular", NULL, &dotreg);

    /* intialize dsk_ls */
    ot_getvar ("ls_cmd", lscmd);
    if (Tcl_SplitList (interp, lscmd, &lsargc, &lsargv) == TCL_ERROR)
	return TCL_ERROR;
    dsk_ls_init_and_parse_options (lsargc, lsargv, argv[1]);
    free (lsargv);
    
    /* now read and sort the file list */
    fargc = dsk_ls_read_and_sort (iargc, (showall ? NULL : iargv),
				  maskc, (mask_matches_all ? NULL : maskv),
				  invert_mask, dotreg);
    
    /* prepare for filling the list box with the filelist */
    Tcl_DStringInit (&dbigcmd);
    Tcl_DStringAppend (&dbigcmd, frame, -1);
    Tcl_DStringAppend (&dbigcmd, ".dlb config -list {", -1);
    
    /*
     *  Loop through the file list.
     *  Append the index of each file to the tag list it matches.
     */
    i = 0;
    strcpy (annobuf, argv[1]);
    while (dsk_ls_next_file (filebuf, fnametc)) {
	
	/* loop through $taglist until a matching tag is found */
	notmatch = 1;
	strcpy (buf, itoa(i));
	for (k = 0; k < targc; k++) {
	    /* if the filename matches this tag append its index */
	    if (Tcl_StringMatch (fnametc, pargv[k])) {
#if TCL_MAJOR_VERSION < 8
		if (!(Tcl_SetVar2 (interp, "mt", targv[k], buf,
		     TCL_LIST_ELEMENT | TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG)))
		  return TCL_ERROR;
#else
		if (!(Tcl_ObjSetVar2 (interp, mt_obj,
				      Tcl_NewStringObj(targv[k], -1),
				      Tcl_NewStringObj(buf, -1),
		     TCL_LIST_ELEMENT | TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG)))
		  return TCL_ERROR;
#endif
		mtags = 1;
		notmatch = 0;
		break;
	    }
	}

	/* add_images: need also line-nr.s of "normal" files */
	if (notmatch && add_images) {
	    notmatch_set = 1;
#if TCL_MAJOR_VERSION < 8
	    ot_setvar_with_flags ("mt_notmatch", buf,
		    TCL_LIST_ELEMENT | TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG);
#else
	    if (Tcl_ObjSetVar2 (interp, notmatch_obj, NULL,
				  Tcl_NewStringObj (buf, -1),
       	          TCL_LIST_ELEMENT | TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG)
		== NULL)
		return TCL_ERROR;
#endif
	}

	/* check whether there's an annotation for this file */
	strcpy (annobuf+strlen(argv[1]), fnametc);
	annobuf[strlen(annobuf) - 1] = '\0';
#if TCL_MAJOR_VERSION < 8
	if (Ot_GetVar2 (interp, "tkdesk_anno", annobuf, TCL_GLOBAL_ONLY)
	    != NULL)
	{
	    ot_setvar2_with_flags ("mt", "annotag", buf,
		    TCL_LIST_ELEMENT | TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG);
	    mtags = 1;
	}
#else
	if (Tcl_ObjGetVar2 (interp, anno_obj,
			    Tcl_NewStringObj (annobuf, -1), TCL_GLOBAL_ONLY)
	    != NULL)
	{
	    if (Tcl_ObjSetVar2 (interp, mt_obj, annotag_obj,
				  Tcl_NewStringObj (buf, -1),
       	          TCL_LIST_ELEMENT | TCL_APPEND_VALUE | TCL_LEAVE_ERR_MSG)
		== NULL)
		return TCL_ERROR;
	    mtags = 1;
	}
#endif

	/* append the file entry to the file list */
	unescape_chars (filebuf, escbuf);
	Tcl_DStringAppendElement (&dbigcmd, escbuf);

	i++;
	if (i % 10 == 0)
	    while (Tcl_DoOneEvent (TCL_ALL_EVENTS | TCL_DONT_WAIT) != 0);
    }

    Tcl_DStringAppend (&dbigcmd, "} ; ", -1);
    
    /* set the label of the menu button of this FileListbox */
    Tcl_DStringAppend (&dbigcmd, frame, -1);
    Tcl_DStringAppend (&dbigcmd, ".mb config -state normal -text \"[", -1);
    Tcl_DStringAppend (&dbigcmd, this, -1);
    Tcl_DStringAppend (&dbigcmd, " _mb_label]\" ; ", -1);

    /* repack the menu button (it may not be mapped) */
    Tcl_DStringAppend (&dbigcmd, "pack ", -1);
    Tcl_DStringAppend (&dbigcmd, frame, -1);
    Tcl_DStringAppend (&dbigcmd, ".mb -in ", -1);
    Tcl_DStringAppend (&dbigcmd, frame, -1);
    Tcl_DStringAppend (&dbigcmd, ".fMb -before ", -1);
    Tcl_DStringAppend (&dbigcmd, frame, -1);
    Tcl_DStringAppend (&dbigcmd, ".lFiles -fill x -side left -expand yes ; ", -1);
    /* update the listbox label */
    largc = (!ntd && mask_matches_all) ? fargc - 2 : fargc;
    if (largc == 1) {
	Tcl_DStringAppend (&dbigcmd, frame, -1);
	Tcl_DStringAppend (&dbigcmd, ".lFiles config -text \" 1 Item\" ;", -1);
    } else {
	Tcl_DStringAppend (&dbigcmd, frame, -1);
	Tcl_DStringAppend (&dbigcmd, ".lFiles config -text \" ", -1);
	Tcl_DStringAppend (&dbigcmd, itoa(largc), -1);
	Tcl_DStringAppend (&dbigcmd, " Items\" ; ", -1);
    }

    if (!mtags)
    {
	if (Tcl_Eval (interp, dbigcmd.string) == TCL_ERROR) {
	    return TCL_ERROR;
	}
	Tcl_DStringFree (&dbigcmd);
    }

    /* free memory allocated by dsk_ls */
    dsk_ls_cleanup();
    if (!mask_matches_all)
	free (maskv);

    /*
     * And now the tagging:
     */
    if (mtags) {
	ot_invoke ("array names mt");
	strcpy (buf, interp->result);
	if (Tcl_SplitList (interp, buf, &mtargc, &mtargv) == TCL_ERROR)
	  return TCL_ERROR;

	/*Tcl_DStringInit (&dbigcmd);*/
	for (k = 0; k < mtargc; k++) {
	    ot_getvar2 ("mt", mtargv[k], bufp);
	    Tcl_DStringAppend (&dbigcmd, frame, -1);
	    Tcl_DStringAppend (&dbigcmd, ".dlb tag add ", -1);
	    Tcl_DStringAppend (&dbigcmd, mtargv[k], -1);
	    Tcl_DStringAppend (&dbigcmd, " {", -1);
	    Tcl_DStringAppend (&dbigcmd, bufp, -1);
	    Tcl_DStringAppend (&dbigcmd, "} ; ", -1);	    

	    if (mtargv[k][0] == 'a')
		if (strcmp (mtargv[k], "annotag") == 0)
		    continue;
	    
	    if (add_images) {
		Tcl_DStringAppend (&dbigcmd, this, -1);
		Tcl_DStringAppend (&dbigcmd, " imginsert ", -1);
		Tcl_DStringAppend (&dbigcmd, mtargv[k], -1);
		Tcl_DStringAppend (&dbigcmd, " {", -1);
		Tcl_DStringAppend (&dbigcmd, bufp, -1);
		Tcl_DStringAppend (&dbigcmd, "} ; ", -1);	    
	    }

	    if (k % 10 == 0)
		while (Tcl_DoOneEvent (TCL_ALL_EVENTS | TCL_DONT_WAIT) != 0);
	}
	if (Tcl_Eval (interp, dbigcmd.string) == TCL_ERROR) {
	    return TCL_ERROR;
	}
	Tcl_DStringFree (&dbigcmd);

	free (mtargv);
    }
    
    if (add_images && notmatch_set) {
	ot_getvar ("mt_notmatch", bufp);
	Tcl_DStringInit (&dbigcmd);
	Tcl_DStringAppend (&dbigcmd, this, -1);
	Tcl_DStringAppend (&dbigcmd, " imginsert {} {", -1);
	Tcl_DStringAppend (&dbigcmd, bufp, -1);
	Tcl_DStringAppend (&dbigcmd, "}", -1);	    
	ot_invoke (dbigcmd.string);
	Tcl_DStringFree (&dbigcmd);
    }
	
    Tcl_ResetResult (interp);
    
    return TCL_OK;
} /* dsk_ls_and_tag_Cmd */

