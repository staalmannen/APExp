
/* 
 * VICI Copyright (c) 1999,2000 David Stes
 *
 * $Id: e_stdmsg.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
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
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif

#include <ordcltn.h>
#include <node.h>
#include <def.h>
#include <var.h>
#include <scalar.h>
#include <type.h>
#include <expr.h>
#include <msgxpr.h>
#include <methdef.h>

#include "revmap.h"
#include "msgwrap.h"

static id e_id(IMP f,id r,SEL s,id keyw)
{
   return f(r,s);
}

static id trap_id(id r,SEL s)
{
   return [revmap(r,s) sentTo:r:s];
}

static id e_idid(IMP f,id r,SEL s,id keyw)
{
   id a = [[keyw at:0] go];
   return f(r,s,a);
}

static id trap_idid(id r,SEL s,id a)
{
   return [revmap(r,s) sentTo:r:s:a];
}

static id e_ididid(IMP f,id r,SEL s,id keyw)
{
   id a = [[keyw at:0] go];
   id b = [[keyw at:1] go];
   return f(r,s,a,b);
}

static id trap_ididid(id r,SEL s,id a,id b)
{
   return [revmap(r,s) sentTo:r:s:a:b];
}

static id e_bool(IMP f,id r,SEL s,id keyw)
{
   return [[Scalar new] u_char:((BOOL(*)(id,SEL))f)(r,s)];
}

static BOOL trap_bool(id r,SEL s)
{
   return [[revmap(r,s) sentTo:r:s] u_char];
}

static id e_idbool(IMP f,id r,SEL s,id keyw)
{
   BOOL a = [[[keyw at:0] go] u_char];
   return ((id(*)(id,SEL,BOOL))f)(r,s,a);
}

static id trap_idbool(id r,SEL s,BOOL a)
{
   id sa = [[Scalar new] u_char:a];
   return [revmap(r,s) sentTo:r:s:sa];
}

static id e_str(IMP f,id r,SEL s,id keyw)
{
   return [[Scalar new] u_str:((STR(*)(id,SEL))f)(r,s)];
}

static STR trap_str(id r,SEL s)
{
   return [[revmap(r,s) sentTo:r:s] u_str];
}

static id e_idstr(IMP f,id r,SEL s,id keyw)
{
   STR a = [[[keyw at:0] go] u_str];
   return ((id(*)(id,SEL,STR))f)(r,s,a);
}

static id trap_idstr(id r,SEL s,STR a)
{
   id sa = [[Scalar new] u_str:a];
   return [revmap(r,s) sentTo:r:s:sa];
}

static id e_int(IMP f,id r,SEL s,id keyw)
{
   return [[Scalar new] u_int:((int(*)(id,SEL))f)(r,s)];
}

static id e_uns(IMP f,id r,SEL s,id keyw)
{
   return [[Scalar new] u_uns:((unsigned(*)(id,SEL))f)(r,s)];
}

static int trap_int(id r,SEL s)
{
   return [[revmap(r,s) sentTo:r:s] u_int];
}

static unsigned trap_uns(id r,SEL s)
{
   return [[revmap(r,s) sentTo:r:s] u_uns];
}

static id e_idint(IMP f,id r,SEL s,id keyw)
{
   int a = [[[keyw at:0] go] u_int];
   return ((id(*)(id,SEL,int))f)(r,s,a);
}

static id trap_idint(id r,SEL s,int a)
{
   id sa = [[Scalar new] u_int:a];
   return [revmap(r,s) sentTo:r:s:sa];
}

MSGWRAP stdmsgwraps[] = {
{&t_id,	NULL,	NULL,	NULL,	NULL,NULL,NULL,NULL,e_id,(IMP)trap_id},
{&t_id,	&t_id,	NULL,	NULL,	NULL,NULL,NULL,NULL,e_idid,(IMP)trap_idid},
{&t_id,	&t_id,	&t_id,	NULL,	NULL,NULL,NULL,NULL,e_ididid,(IMP)trap_ididid},
{&t_bool,NULL,	NULL,	NULL,	NULL,NULL,NULL,NULL,e_bool,(IMP)trap_bool},
{&t_id,	&t_bool,NULL,	NULL,	NULL,NULL,NULL,NULL,e_idbool,(IMP)trap_idbool},
{&t_int,NULL,	NULL,	NULL,	NULL,NULL,NULL,NULL,e_int,(IMP)trap_int},
{&t_uns,NULL,	NULL,	NULL,	NULL,NULL,NULL,NULL,e_uns,(IMP)trap_uns},
{&t_id,&t_int,NULL,	NULL,	NULL,NULL,NULL,NULL,e_idint,(IMP)trap_idint},
{&t_str,NULL,	NULL,	NULL,	NULL,NULL,NULL,NULL,e_str,(IMP)trap_str},
{&t_id,&t_str,NULL,	NULL,	NULL,NULL,NULL,NULL,e_idstr,(IMP)trap_idstr},
{&t_id,&t_sel,NULL,	NULL,	NULL,NULL,NULL,NULL,e_idstr,(IMP)trap_idstr},
{NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL,NULL,NULL,NULL},
};

