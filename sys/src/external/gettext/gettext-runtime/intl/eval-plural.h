/* Plural expression evaluation.
   Copyright (C) 2000-2003, 2007 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 2.1 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#ifndef STATIC
#define STATIC static
#endif

#include "plural-exp.h"

/* Evaluate the plural expression and return an index value.  */
unsigned long int 
plural_eval (const struct expression *pexp, unsigned long int n)
{
  switch (pexp->nargs)
    {
    case 0:
      switch (pexp->operation)
	{
	case var:
	  return n;
	case num:
	  return pexp->val.num;
	default:
	  break;
	}
      /* NOTREACHED */
      break;
    case 1:
      {
	/* pexp->operation must be lnot.  */
	unsigned long int arg = plural_eval (pexp->val.args[0], n);
	return ! arg;
      }
    case 2:
      {
	unsigned long int leftarg = plural_eval (pexp->val.args[0], n);
	if (pexp->operation == lor)
	  return leftarg || plural_eval (pexp->val.args[1], n);
	else if (pexp->operation == land)
	  return leftarg && plural_eval (pexp->val.args[1], n);
	else
	  {
	    unsigned long int rightarg = plural_eval (pexp->val.args[1], n);

	    switch (pexp->operation)
	      {
	      case mult:
		return leftarg * rightarg;
	      case divide:
#if !INTDIV0_RAISES_SIGFPE
		if (rightarg == 0)
		  raise (SIGFPE);
#endif
		return leftarg / rightarg;
	      case module:
#if !INTDIV0_RAISES_SIGFPE
		if (rightarg == 0)
		  raise (SIGFPE);
#endif
		return leftarg % rightarg;
	      case plus:
		return leftarg + rightarg;
	      case minus:
		return leftarg - rightarg;
	      case less_than:
		return leftarg < rightarg;
	      case greater_than:
		return leftarg > rightarg;
	      case less_or_equal:
		return leftarg <= rightarg;
	      case greater_or_equal:
		return leftarg >= rightarg;
	      case equal:
		return leftarg == rightarg;
	      case not_equal:
		return leftarg != rightarg;
	      default:
		break;
	      }
	  }
	/* NOTREACHED */
	break;
      }
    case 3:
      {
	/* pexp->operation must be qmop.  */
	unsigned long int boolarg = plural_eval (pexp->val.args[0], n);
	return plural_eval (pexp->val.args[boolarg ? 1 : 2], n);
      }
    }
  /* NOTREACHED */
  return 0;
}
