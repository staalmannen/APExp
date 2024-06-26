/*ident	"@(#)cls4:lib/complex/complex/const.h	1.3" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1993  UNIX System Laboratories, Inc.
Copyright (c) 1991, 1992 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
#include <float.h>

#define	ABS(x)	((x<0) ? -(x) : x)

#define	MAX_EXPONENT	88.0
#define MIN_EXPONENT	-88.0

#define	GREATEST 1.701411834604692293e38
#define HUGE		DBL_MAX
