/* ============================================================================
 *
 * File:	libdesk.h
 * Project:	TkDesk
 * Started:	07.10.94
 * Changed:	12.07.96
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
 * ========================================================================= */

#ifndef _LIBDESK_H
#define _LIBDESK_H

#include "config.h"
#include "ot.h"
#include <tcl.h>

extern Tcl_Interp *dsk_interp;


/* ===== Tcl commands created by libtv: */
extern Tcl_CmdProc dsk_ls_Cmd;
extern Tcl_CmdProc dsk_striptc_Cmd;
extern Tcl_CmdProc dsk_ppflist_Cmd;
extern Tcl_CmdProc dsk_ls_and_tag_Cmd;
extern Tcl_CmdProc dsk_init_ftags_Cmd;
extern Tcl_CmdProc dsk_esc_Cmd;
extern Tcl_CmdProc dsk_unesc_Cmd;
extern Tcl_CmdProc dsk_localtime_Cmd;
extern Tcl_CmdProc dsk_statfs_Cmd;

/* ===== Exported C functions: */

char *escape_chars                  _ANSI_ARGS_((char *str, char *chars,
						 char *buf));
char *unescape_chars                _ANSI_ARGS_((char *str, char *buf));
char *itoa                          _ANSI_ARGS_((long val));

int   dsk_ls_init_and_parse_options _ANSI_ARGS_((int argc, char **argv,
					      char *path));
int   dsk_ls_read_and_sort          _ANSI_ARGS_((int iargc, char **iargv,
						 int maskc, char **maskv,
						 int mask_invert,
						 int dot_reg));
int   dsk_ls_next_file              _ANSI_ARGS_((char *elembuf,
						 char *nametcbuf));
void  dsk_ls_cleanup                _ANSI_ARGS_(());

#endif /* _LIBDESK_H */
