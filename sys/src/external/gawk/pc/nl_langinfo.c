/* Replacement for the missing nl_langinfo.  Only CODESET is currently
   supported.  */

/* 
 * Copyright (C) 2025-2026,
 * the Free Software Foundation, Inc.
 * 
 * This file is part of GAWK, the GNU implementation of the
 * AWK Progamming Language.
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

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <langinfo.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "mbc32.h"

char *
nl_langinfo (int item)
{
  switch (item)
    {
      case CODESET:
	{
	  /* Shamelessly stolen from Gnulib's nl_langinfo.c.  */
	  static char buf[2 + 10 + 1];
	  char const *locale = setlocale (LC_CTYPE, NULL);
	  char *codeset = buf;
	  size_t codesetlen;
	  codeset[0] = '\0';

	  if (locale && locale[0])
	    {
	      /* If the locale name contains an encoding after the
		 dot, return it.  */
	      char *dot = strchr (locale, '.');

	      if (dot)
		{
		  /* Look for the possible @... trailer and remove it,
		     if any.  */
		  char *codeset_start = dot + 1;
		  char const *modifier = strchr (codeset_start, '@');

		  if (! modifier)
		    codeset = codeset_start;
		  else
		    {
		      codesetlen = modifier - codeset_start;
		      if (codesetlen < sizeof buf)
			{
			  codeset = memcpy (buf, codeset_start, codesetlen);
			  codeset[codesetlen] = '\0';
			}
		    }
		}
	    }
	  /* If setlocale is successful, it returns the number of the
	     codepage, as a string.  Otherwise, fall back on Windows
	     API GetACP, which returns the locale's codepage as a
	     number (although this doesn't change according to what
	     the 'setlocale' call specified).  Either way, prepend
	     "CP" to make it a valid codeset name.  */
	  codesetlen = strlen (codeset);
	  if (0 < codesetlen && codesetlen < sizeof buf - 2)
	    memmove (buf + 2, codeset, codesetlen + 1);
	  else
	    sprintf (buf + 2, "%u", GetACP ());
	  codeset = memcpy (buf, "CP", 2);

	  /* Gawk is a console program, so allow the user to override
             the locale's codeset by using the chcp shell command.  */
	  if (strcmp (buf + 2, "65001") != 0)
	    {
	      UINT outcp = GetConsoleOutputCP ();
	      if (outcp == 65001)
		strcpy (buf + 2, "65001");
	    }
	  /* Impersonate UTF-8 locale for the benefit of Posix
             programs which know nothing about the Windows codepages
             in general and codepage 65001 in particular.  This is
             what Gnulib's nl_langinfo does.  */
	  if (strcmp (buf + 2, "65001") == 0
	      /* Windows 10 and later returns ".utf8" as UTF-8 codeset.  */
	      || strcmp (buf + 2, "utf8") == 0)
	    return (char *) "UTF-8";
	  return codeset;
	}
      default:
	return (char *) "";
    }
}

/* Whether the MinGW Gawk is using UTF-8.

   The SET argument is:
    1 -- to set the cached value according to whether the locale
	 and/or the console are set to use UTF-8.  Used when the
	 locale changes and setlocale is called.
   -1 -- to reset the cached value to zero.  Used when the -b
	 command-line option is specified.
   -2 -- to reset the cached value in a way that set = 1 cannot
	 override.  Used when we are forced to run in "C" locale.
    0 -- to return the cached value, unless it is not yet set, in
	 which case it works like 1.  */
bool
mingw_using_utf8 (enum mingw_set_utf8 set)
{
 static int is_utf8;

  if ((set != UTF8_QUERY || !is_utf8) && is_utf8 != -2)
    {
      if (set == UTF8_HARD_RESET)
	is_utf8 = -2;
      else
	{
	  if (strcmp (nl_langinfo (CODESET), "UTF-8") == 0
	      && (set == UTF8_QUERY || set == UTF8_SET))
	    is_utf8 = 1;
	  else	/* UTF8_RESET */
	    is_utf8 = -1;
	}
    }
  return is_utf8 == 1;
}

int
mingw_mb_cur_max (void)
{
  if (mingw_using_utf8 (UTF8_QUERY))
    return 4;
  /* __mb_cur_max is either a macro defined to call an internal CRT
     function, or an internal variable of CRT that is updated when
     setlocale is called.  */
  return __mb_cur_max;
}
