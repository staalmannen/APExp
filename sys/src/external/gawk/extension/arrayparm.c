/*
 * arrayparm.c --- figure out how to make a parameter be an array
 *
 * Arnold Robbins
 * arnold@skeeve.com
 * 10/2001
 *
 * Revised 7/2003
 * Revised 6/2004
 */

/*
 * Copyright (C) 2001, 2003, 2004, 2011 the Free Software Foundation, Inc.
 * 
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 * 
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "awk.h"

int plugin_is_GPL_compatible;

/*  do_mkarray --- turn a variable into an array */

/*
 * From awk, call
 *
 * 	mkarray(var, sub, val)
 */

static NODE *
do_mkarray(int args)
{
	int ret = -1;
	NODE *var, *sub, *val;
	NODE **elemval;

	if  (do_lint && get_curfunc_arg_count() > 3)
		lintwarn("mkarray: called with too many arguments");

	var = get_array_argument(0, FALSE);
	sub = get_scalar_argument(1, FALSE);
	val = get_scalar_argument(2, FALSE);

	printf("var->type = %s\n", nodetype2str(var->type));
	printf("sub->type = %s\n", nodetype2str(sub->type));
	printf("val->type = %s\n", nodetype2str(val->type));

	assoc_clear(var);

	elemval = assoc_lookup(var, sub, 0);
	*elemval = dupnode(val);
	ret = 0;

	/* Set the return value */
	return make_number((AWKNUM) ret);
}

/* dlload --- load new builtins in this library */

NODE *
dlload(tree, dl)
NODE *tree;
void *dl;
{
	make_builtin("mkarray", do_mkarray, 3);

	return make_number((AWKNUM) 0);
}
