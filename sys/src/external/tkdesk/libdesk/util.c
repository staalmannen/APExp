/* ============================================================================
 *
 * File:	util.c
 * Project:	TkDesk
 * Started:	12.07.96
 * Changed:	12.07.96
 *
 * Provides several utility C subroutines.
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libdesk.h"


/* ---------------------------------------------------------------------------
 * escape_chars:
 * Precedes each char of chars in str with a backslash. Puts the result into
 * buf, which must be big enough.
 */
char *escape_chars (str, chars, buf)
char *str;
char *chars;
char *buf;
{
    char *bp;

    bp = buf;
    while (*str) {
	if (strchr (chars, *str)) {
	    *bp++ = '\\';
	}
	*bp++ = *str++;
	    
    }
    *bp = '\0';

    return buf;
} /* escape_chars */

/* ---------------------------------------------------------------------------
 * unescape_chars:
 * Removes all backslashes from str, except before }. \t is replaced with
 * a real tab. Puts result at buf.
 */
char *unescape_chars (str, buf)
char *str;
char *buf;
{
    char *bp;

    bp = buf;
    while (*str) {
	if (*str != '\\') {
	    *bp++ = *str++;
	} else {
	    switch (*(str + 1)) {
	    case 't':
		str += 2; /* points just past t now */
		*bp++ = '\t';
		break;
#ifdef UNDEFINED
	    case '}':
		*bp++ = *str++; /* copy backslash in this case */
		break;
#endif
	    default:
		str++;
	    }
	}
    }
    *bp = '\0';

    return buf;
} /* unescape_chars */


/* ============================================================================
 * Name: itoa
 * Desc: Converts an unsigned long integer to a string.
 * In  : val - integer
 * Out : pointer to static string
 * ------------------------------------------------------------------------- */

char *itoa(val)
long val;
{
    static char str[16];
    int i = 0, r;

#define I2CHAR(a)                     \
    if (val >= (a)) {                 \
	r = val / (a);                \
	str[i++] = '0' + r;           \
	val -= r * (a);               \
    } else if (i > 0)                 \
        str[i++] = '0';
   
    I2CHAR(1000000000l);
    I2CHAR(100000000l);
    I2CHAR(10000000l);
    I2CHAR(1000000l);
    I2CHAR(100000l);
    I2CHAR(10000l);
    I2CHAR(1000l);
    I2CHAR(100l);
    I2CHAR(10l);
   
    str[i++] = '0' + (val % 10);
    str[i] = '\0';

    return str;
}


