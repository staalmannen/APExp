/*ident	"@(#)C++env:lib/task/task/erand.c	1.1" */
/**************************************************************************
			Copyright (c) 1984 AT&T
	  		  All Rights Reserved  	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
	
	The copyright notice above does not evidence any   	
	actual or intended publication of such source code.

*****************************************************************************/
#include <task.h>
#include <math.h>
#include <limits.h>

/* NOTE:  This function is in a separate file because it needs the
 * math library. Programs that bring in this file must link with -lm
 */
int
erand::draw()
{
	return (int)(-mean * log( (double)(((float)INT_MAX)-randint::draw())
				/ ((float)INT_MAX)) + .5);
}

