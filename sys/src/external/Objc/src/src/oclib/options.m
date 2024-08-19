
/*
 * Copyright (c) 1998,99,2002,2017,2019,2023 David Stes.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id: options.m,v 1.9 2023/01/27 20:19:10 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#include "options.h"

int o_warnings;
int o_gnu;
int o_darwin;
int o_vms;
int o_hpux;
int o_sunstudio;
int o_m64;
int o_refcnt;
int o_ppi;
int o_watcom;
int o_ibmvac;
int o_msdos;
int o_enableasm;
int o_nolinetags;
int o_buffered;
int o_quiet;
int o_outputcode;
int o_version;
int o_otb;
int o_llkeyw;
int o_comments;
int o_duptypedefs;
int o_seltranslation;
int o_categories;
int o_blocks;
int o_fwd;
int o_selptr;
int o_cache;
int o_filer;
int o_selfassign;
char *o_bind;
char *o_browsedir;
int o_refbind;
int o_inlinecache;
int o_cplus;
int o_gencode;
int o_st80;
int o_selfassign;
int o_nilrcvr;
int o_shareddata;
int o_oneperfile;
int o_cvars;
int o_warnlex;
int o_warnfwd;
int o_warnsuggest;
int o_warnintvar;
int o_warnclasstype;
int o_warntypeconflict;
int o_warnundefined;
int o_warnlocalnst;
int o_warnnotfound;
int o_warnmissingmethods;
int o_attrcommon;
int o_postlink;
char *o_infile;
char *o_outfile;
char *o_srcfilename;
char *o_initcall;
char *o_tagformat;
int o_linetag;
char *o_mainfun;
char *o_pathsep;
int o_debuginfo;
int o_checkbind;
int o_linemax;
int o_structassign;
id o_stepbreak;
int o_stepnext;

void 
defoptions(void)
{
  o_tagformat = "#line %d \"%s\"\n";
  o_quiet = 0;
  o_outputcode = 1;
  o_gencode = 1;
  o_st80 = 0;
  o_otb = 0;			/* object table (ie double indirection) */
  o_fwd = 1;			/* use fwdimp() */
  o_selptr = 1;			/* use selptrfwd optimization of fwdimp() */
  o_version = 0;
  o_infile = NULL;		/* stdin */
  o_outfile = NULL;		/* stdout */
  o_srcfilename = NULL;
  o_initcall = NULL;
  o_mainfun = "main";
  o_seltranslation = 1;
  o_inlinecache = 0;
  o_nolinetags = 0;
  o_attrcommon = 0;
  o_postlink = 0;
  o_shareddata = 1;
  o_refbind = 0;		/* force a reference to the BIND() function - Metrowerks */
  o_browsedir=NULL;
  o_checkbind = 0;
  o_warnlex = 0;
  o_warnfwd = 0;
  o_warnclasstype = 1;
  o_warntypeconflict = 1;
  o_warnundefined = 1;
  o_warnnotfound = 1;
  o_warnintvar = 1;
  o_warnmissingmethods = 1;
  o_warnlocalnst = 1;
  o_warnsuggest = 1;
  o_buffered = 1;
  o_comments = 0;
  o_duptypedefs = 0;
  o_msdos = 0;
  o_gnu = 0;
  o_darwin = 0; /* Apple darwin17.7 keyword swift,ios,macosx */
  o_sunstudio = 0;
  o_m64 = 0;
  o_warnings = 1;
  o_vms = 0;
  o_hpux = 0;
  o_refcnt = 0;
  o_cplus = 0;
  o_debuginfo = 0;
  o_ppi = 0;
  o_ibmvac = 0;
  o_pathsep = (char *) getenv("OBJCPATHSEP");
  if (!o_pathsep)
    o_pathsep = OBJCRT_DEFAULT_PATHSEPC;
  o_oneperfile = 0;
  o_cvars = 1;
  o_enableasm = 1;		/* DEC header defines an asm() function */
  o_llkeyw = 1;			/* __long_long irix type */
  o_blocks = 1;
  o_filer = 1;
  o_bind = "";			/* can be set to __declspec(export) -- may not be NULL */
  o_linemax = 0;
  o_structassign = 1;		/* in case some compiler would not allow this */
  o_cache = 1;
  o_nilrcvr = 1;
  o_selfassign = 1;
  o_categories = 1;
}
 
