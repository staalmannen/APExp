/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "slibtool_snprintf_impl.h"
#include "slibtool_visibility_impl.h"


/*****************************************************************/
/* snprintf() wrapper that simplifies usage via the following:  */
/*                                                             */
/* (1) fail (return a negative result) in case the buffer is  */
/*     not sufficiently large for the formatted string plus  */
/*     the terminating null character.                      */
/*                                                         */
/**********************************************************/


slbt_hidden int slbt_snprintf(char * buf, size_t buflen, const char * fmt, ...)
{
	va_list	ap;
	size_t  nbytes;

	va_start(ap,fmt);
	nbytes = vsnprintf(buf,buflen,fmt,ap);
	va_end(ap);

	if (nbytes >= buflen)
		return -1;

	return nbytes;
}
