/* Copyright (C) 1991, 1992, 1993, 1996, 1997, 1998, 1999, 2021,
Free Software Foundation, Inc.
This file is part of the GNU C Library.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this library; see the file COPYING.LIB.  If not, write to the Free
Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
USA.  */

/* Enable GNU extensions in fnmatch.h.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE	1
#endif

#include <errno.h>
#include <fnmatch.h>
#include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include <wctype.h>
#define _btowc(c) btowc(c)
#define __btowc(c) btowc(c)
#define __iswctype(c,d) iswctype(c,d)

#  define ISASCII(c) isascii(c)
#  define ISBLANK(c) (ISASCII (c) && isblank (c))
#  define ISGRAPH(c) (ISASCII (c) && isgraph (c))

# define ISPRINT(c) (ISASCII (c) && isprint (c))
# define ISDIGIT(c) (ISASCII (c) && isdigit (c))
# define ISALNUM(c) (ISASCII (c) && isalnum (c))
# define ISALPHA(c) (ISASCII (c) && isalpha (c))
# define ISCNTRL(c) (ISASCII (c) && iscntrl (c))
# define ISLOWER(c) (ISASCII (c) && islower (c))
# define ISPUNCT(c) (ISASCII (c) && ispunct (c))
# define ISSPACE(c) (ISASCII (c) && isspace (c))
# define ISUPPER(c) (ISASCII (c) && isupper (c))
# define ISXDIGIT(c) (ISASCII (c) && isxdigit (c))

# define STREQ(s1, s2) ((strcmp (s1, s2) == 0))

#define CHAR_CLASS_MAX_LENGTH 256

#define IS_CHAR_CLASS(string) wctype (string)

/* Avoid depending on library functions or files
   whose names are inconsistent.  */

/* This function doesn't exist on most systems.  */
static char *
__strchrnul (const char *s, int c)
{
  char *result = strchr (s, c);
  if (result == NULL)
    result = strchr (s, '\0');
  return result;
}

# ifndef internal_function
/* Inside GNU libc we mark some function in a special way.  In other
   environments simply ignore the marking.  */
#  define internal_function
# endif

/* Match STRING against the filename pattern PATTERN, returning zero if
   it matches, nonzero if not.  */
static int internal_fnmatch __P ((const char *pattern, const char *string,
				  int no_leading_period, int flags))
     internal_function;
static int
internal_function
internal_fnmatch (pattern, string, no_leading_period, flags)
     const char *pattern;
     const char *string;
     int no_leading_period;
     int flags;
{
  register const char *p = pattern, *n = string;
  register unsigned char c;

#  define FOLD(c) ((flags & FNM_CASEFOLD) && ISUPPER (c) ? tolower (c) : (c))

  while ((c = *p++) != '\0')
    {
      c = FOLD (c);

      switch (c)
	{
	case '?':
	  if (*n == '\0')
	    return FNM_NOMATCH;
	  else if (*n == '/' && (flags & FNM_FILE_NAME))
	    return FNM_NOMATCH;
	  else if (*n == '.' && no_leading_period
		   && (n == string
		       || (n[-1] == '/' && (flags & FNM_FILE_NAME))))
	    return FNM_NOMATCH;
	  break;

	case '\\':
	  if (!(flags & FNM_NOESCAPE))
	    {
	      c = *p++;
	      if (c == '\0')
		/* Trailing \ loses.  */
		return FNM_NOMATCH;
	      c = FOLD (c);
	    }
	  if (FOLD ((unsigned char) *n) != c)
	    return FNM_NOMATCH;
	  break;

	case '*':
	  if (*n == '.' && no_leading_period
	      && (n == string
		  || (n[-1] == '/' && (flags & FNM_FILE_NAME))))
	    return FNM_NOMATCH;

	  for (c = *p++; c == '?' || c == '*'; c = *p++)
	    {
	      if (*n == '/' && (flags & FNM_FILE_NAME))
		/* A slash does not match a wildcard under FNM_FILE_NAME.  */
		return FNM_NOMATCH;
	      else if (c == '?')
		{
		  /* A ? needs to match one character.  */
		  if (*n == '\0')
		    /* There isn't another character; no match.  */
		    return FNM_NOMATCH;
		  else
		    /* One character of the string is consumed in matching
		       this ? wildcard, so *??? won't match if there are
		       less than three characters.  */
		    ++n;
		}
	    }

	  if (c == '\0')
	    /* The wildcard(s) is/are the last element of the pattern.
	       If the name is a file name and contains another slash
	       this does mean it cannot match.  */
	    return ((flags & FNM_FILE_NAME) && strchr (n, '/') != NULL
		    ? FNM_NOMATCH : 0);
	  else
	    {
	      const char *endp;

	      endp = __strchrnul (n, (flags & FNM_FILE_NAME) ? '/' : '\0');

	      if (c == '[')
		{
		  int flags2 = ((flags & FNM_FILE_NAME)
				? flags : (flags & ~FNM_PERIOD));

		  for (--p; n < endp; ++n)
		    if (internal_fnmatch (p, n,
					  (no_leading_period
					   && (n == string
					       || (n[-1] == '/'
						   && (flags
						       & FNM_FILE_NAME)))),
					  flags2)
			== 0)
		      return 0;
		}
	      else if (c == '/' && (flags & FNM_FILE_NAME))
		{
		  while (*n != '\0' && *n != '/')
		    ++n;
		  if (*n == '/'
		      && (internal_fnmatch (p, n + 1, flags & FNM_PERIOD,
					    flags) == 0))
		    return 0;
		}
	      else
		{
		  int flags2 = ((flags & FNM_FILE_NAME)
				? flags : (flags & ~FNM_PERIOD));

		  if (c == '\\' && !(flags & FNM_NOESCAPE))
		    c = *p;
		  c = FOLD (c);
		  for (--p; n < endp; ++n)
		    if (FOLD ((unsigned char) *n) == c
			&& (internal_fnmatch (p, n,
					      (no_leading_period
					       && (n == string
						   || (n[-1] == '/'
						       && (flags
							   & FNM_FILE_NAME)))),
					      flags2) == 0))
		      return 0;
		}
	    }

	  /* If we come here no match is possible with the wildcard.  */
	  return FNM_NOMATCH;

	case '[':
	  {
	    /* Nonzero if the sense of the character class is inverted.  */
	    static int posixly_correct;
	    register int not;
	    char cold;

	    if (posixly_correct == 0)
	      posixly_correct = getenv ("POSIXLY_CORRECT") != NULL ? 1 : -1;

	    if (*n == '\0')
	      return FNM_NOMATCH;

	    if (*n == '.' && no_leading_period && (n == string
						   || (n[-1] == '/'
						       && (flags
							   & FNM_FILE_NAME))))
	      return FNM_NOMATCH;

	    if (*n == '/' && (flags & FNM_FILE_NAME))
	      /* `/' cannot be matched.  */
	      return FNM_NOMATCH;

	    not = (*p == '!' || (posixly_correct < 0 && *p == '^'));
	    if (not)
	      ++p;

	    c = *p++;
	    for (;;)
	      {
		unsigned char fn = FOLD ((unsigned char) *n);

		if (!(flags & FNM_NOESCAPE) && c == '\\')
		  {
		    if (*p == '\0')
		      return FNM_NOMATCH;
		    c = FOLD ((unsigned char) *p);
		    ++p;

		    if (c == fn)
		      goto matched;

		    c = *p++;
		  }
		else if (c == '[' && *p == ':')
		  {
		    /* Leave room for the null.  */
		    char str[CHAR_CLASS_MAX_LENGTH + 1];
		    size_t c1 = 0;
		    wctype_t wt;
		    const char *startp = p;

		    for (;;)
		      {
			if (c1 == CHAR_CLASS_MAX_LENGTH)
			  /* The name is too long and therefore the pattern
			     is ill-formed.  */
			  return FNM_NOMATCH;

			c = *++p;
			if (c == ':' && p[1] == ']')
			  {
			    p += 2;
			    break;
			  }
			if (c < 'a' || c > 'z')
			  {
			    /* This cannot possibly be a character class name.
			       Match it as a normal range.  */
			    p = startp;
			    c = '[';
			    goto normal_bracket;
			  }
			str[c1++] = c;
		      }
		    str[c1] = '\0';

		    wt = IS_CHAR_CLASS (str);
		    if (wt == 0)
		      /* Invalid character class name.  */
		      return FNM_NOMATCH;

		    if (__iswctype (__btowc ((unsigned char) *n), wt))
		      goto matched;
		    c = *p++;
		  }
		else if (c == '\0')
		  /* [ (unterminated) loses.  */
		  return FNM_NOMATCH;
		else
		  {
		  normal_bracket:
		    if (FOLD (c) == fn)
		      goto matched;

		    cold = FOLD(c);
		    c = *p++;

		    if (c == '-' && *p != ']')
		      {
			/* It is a range.  */
			unsigned char cend = *p++;
			if (!(flags & FNM_NOESCAPE) && cend == '\\')
			  cend = *p++;
			if (cend == '\0')
			  return FNM_NOMATCH;

			if (cold <= fn && fn <= FOLD (cend))
			  goto matched;

			c = *p++;
		      }
		  }

		if (c == ']')
		  break;
	      }

	    if (!not)
	      return FNM_NOMATCH;
	    break;

	  matched:
	    /* Skip the rest of the [...] that already matched.  */
	    while (c != ']')
	      {
		if (c == '\0')
		  /* [... (unterminated) loses.  */
		  return FNM_NOMATCH;

		c = *p++;
		if (!(flags & FNM_NOESCAPE) && c == '\\')
		  {
		    if (*p == '\0')
		      return FNM_NOMATCH;
		    /* XXX 1003.2d11 is unclear if this is right.  */
		    ++p;
		  }
		else if (c == '[' && *p == ':')
		  {
		    do
		      if (*++p == '\0')
			return FNM_NOMATCH;
		    while (*p != ':' || p[1] == ']');
		    p += 2;
		    c = *p;
		  }
	      }
	    if (not)
	      return FNM_NOMATCH;
	  }
	  break;

	default:
	  if (c != FOLD ((unsigned char) *n))
	    return FNM_NOMATCH;
	}

      ++n;
    }

  if (*n == '\0')
    return 0;

  if ((flags & FNM_LEADING_DIR) && *n == '/')
    /* The FNM_LEADING_DIR flag says that "foo*" matches "foobar/frobozz".  */
    return 0;

  return FNM_NOMATCH;

# undef FOLD
}


int
fnmatch (pattern, string, flags)
     const char *pattern;
     const char *string;
     int flags;
{
  return internal_fnmatch (pattern, string, flags & FNM_PERIOD, flags);
}


