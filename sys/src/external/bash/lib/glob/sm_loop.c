/* Copyright (C) 1991-2023 Free Software Foundation, Inc.

   This file is part of GNU Bash, the Bourne Again SHell.
   
   Bash is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Bash is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Bash.  If not, see <http://www.gnu.org/licenses/>.
*/

extern int interrupt_state, terminating_signal;

struct STRUCT
{
  CHAR *pattern;
  CHAR *string;
};

int FCT (CHAR *, CHAR *, int);

static int GMATCH (CHAR *, CHAR *, CHAR *, CHAR *, struct STRUCT *, int);
static inline CHAR *PARSE_SUBBRACKET (CHAR *, int);
static CHAR *BRACKMATCH (CHAR *, U_CHAR, int);
static int EXTMATCH (INT, CHAR *, CHAR *, CHAR *, CHAR *, int);

extern void DEQUOTE_PATHNAME (CHAR *);

/*static*/ CHAR *PATSCAN (CHAR *, CHAR *, INT, int);

int
FCT (CHAR *pattern, CHAR *string, int flags)
{
  CHAR *se, *pe;

  if (string == 0 || pattern == 0)
    return FNM_NOMATCH;

  se = string + STRLEN ((XCHAR *)string);
  pe = pattern + STRLEN ((XCHAR *)pattern);

  return (GMATCH (string, se, pattern, pe, (struct  STRUCT *)NULL, flags));
}

/* Match STRING against the filename pattern PATTERN, returning zero if
   it matches, FNM_NOMATCH if not.  */
static int
GMATCH (CHAR *string, CHAR *se, CHAR *pattern, CHAR *pe, struct STRUCT *ends, int flags)
{
  CHAR *p, *n;		/* pattern, string */
  INT c;		/* current pattern character - XXX U_CHAR? */
  INT sc;		/* current string character - XXX U_CHAR? */

  p = pattern;
  n = string;

  if (string == 0 || pattern == 0)
    return FNM_NOMATCH;

#if DEBUG_MATCHING
fprintf(stderr, "gmatch: string = %s; se = %s\n", string, se);
fprintf(stderr, "gmatch: pattern = %s; pe = %s\n", pattern, pe);
#endif

  while (p < pe)
    {
      c = *p++;
      c = FOLD (c);

      sc = n < se ? *n : '\0';

      if (interrupt_state || terminating_signal)
	return FNM_NOMATCH;

#ifdef EXTENDED_GLOB
      /* EXTMATCH () will handle recursively calling GMATCH, so we can
	 just return what EXTMATCH() returns. */
      if ((flags & FNM_EXTMATCH) && *p == (int) L('(') &&
	  (c == (int) L('+') || c == (int) L('*') || c == (int) L('?') || c == (int) L('@') || c == (int) L('!'))) /* ) */
	{
	  int lflags;
	  /* If we're not matching the start of the string, we're not
	     concerned about the special cases for matching `.' */
	  lflags = (n == string) ? flags : (flags & ~(FNM_PERIOD|FNM_DOTDOT));
	  return (EXTMATCH (c, n, se, p, pe, lflags));
	}
#endif /* EXTENDED_GLOB */

      switch (c)
	{
	case (int) L('?'):		/* Match single character */
	  if (sc == '\0')
	    return FNM_NOMATCH;
	  else if ((flags & FNM_PATHNAME) && sc == (int) L('/'))
	    /* If we are matching a pathname, `?' can never match a `/'. */
	    return FNM_NOMATCH;
	  else if ((flags & FNM_PERIOD) && sc == (int) L('.') &&
		   (n == string || ((flags & FNM_PATHNAME) && n[-1] == (int) L('/'))))
	    /* `?' cannot match a `.' if it is the first character of the
	       string or if it is the first character following a slash and
	       we are matching a pathname. */
	    return FNM_NOMATCH;

	  /* `?' cannot match `.' or `..' if it is the first character of the
	     string or if it is the first character following a slash and
	     we are matching a pathname. */
	  if ((flags & FNM_DOTDOT) &&
	      ((n == string && SDOT_OR_DOTDOT(n)) ||
	       ((flags & FNM_PATHNAME) && n > string && n[-1] == (int) L('/') && PDOT_OR_DOTDOT(n))))
	    return FNM_NOMATCH;

	  break;

	case (int) L('\\'):		/* backslash escape removes special meaning */
	  if (p == pe && sc == '\\' && (n+1 == se))
	    break;

	  if (p == pe)
	    return FNM_NOMATCH;

	  if ((flags & FNM_NOESCAPE) == 0)
	    {
	      c = *p++;
	      /* A trailing `\' cannot match. */
	      if (p > pe)
		return FNM_NOMATCH;
	      c = FOLD (c);
	    }
	  if (FOLD (sc) != (U_CHAR)c)
	    return FNM_NOMATCH;
	  break;

	case (int) L('*'):		/* Match zero or more characters */
	  /* See below for the reason for using this. It avoids backtracking
	     back to a previous `*'.  Picked up from glibc. */
	  if (ends != NULL)
	    {
	      ends->pattern = p - 1;
	      ends->string = n;
	      return (0);
	    }

	  if ((flags & FNM_PERIOD) && sc == (int) L('.') &&
	      (n == string || ((flags & FNM_PATHNAME) && n[-1] == (int) L('/'))))
	    /* `*' cannot match a `.' if it is the first character of the
	       string or if it is the first character following a slash and
	       we are matching a pathname. */
	    return FNM_NOMATCH;

	  /* `*' cannot match `.' or `..' if it is the first character of the
	     string or if it is the first character following a slash and
	     we are matching a pathname. */
	  if ((flags & FNM_DOTDOT) &&
	      ((n == string && SDOT_OR_DOTDOT(n)) ||
	       ((flags & FNM_PATHNAME) && n > string && n[-1] == (int) L('/') && PDOT_OR_DOTDOT(n))))
	    return FNM_NOMATCH;

	  if (p == pe)
	    return 0;

	  /* Collapse multiple consecutive `*' and `?', but make sure that
	     one character of the string is consumed for each `?'. */
	  for (c = *p++; (c == (int) L('?') || c == (int) L('*')); c = *p++)
	    {
	      if ((flags & FNM_PATHNAME) && sc == (int) L('/'))
		/* A slash does not match a wildcard under FNM_PATHNAME. */
		return FNM_NOMATCH;
#ifdef EXTENDED_GLOB
	      else if ((flags & FNM_EXTMATCH) && c == (int) L('?') && *p == (int) L('(')) /* ) */
		{
		  CHAR *newn;

		  /* We can match 0 or 1 times.  If we match, return success */
		  if (EXTMATCH (c, n, se, p, pe, flags) == 0)
		    return (0);

		  /* We didn't match the extended glob pattern, but
		     that's OK, since we can match 0 or 1 occurrences.
		     We need to skip the glob pattern and see if we
		     match the rest of the string. */
		  newn = PATSCAN (p + 1, pe, 0, flags);
		  /* If NEWN is 0, we have an ill-formed pattern. */
		  p = newn ? newn : pe;
		}
#endif
	      else if (c == (int) L('?'))
		{
		  if (sc == (int) L('\0'))
		    return FNM_NOMATCH;
		  /* One character of the string is consumed in matching
		     this ? wildcard, so *??? won't match if there are
		     fewer than three characters. */
		  n++;
		  sc = n < se ? *n : '\0';
		}

#ifdef EXTENDED_GLOB
	      /* Handle ******(patlist) */
	      if ((flags & FNM_EXTMATCH) && c == (int) L('*') && *p == (int) L('('))  /*)*/
		{
		  CHAR *newn;
		  /* We need to check whether or not the extended glob
		     pattern matches the remainder of the string.
		     If it does, we match the entire pattern. */
		  for (newn = n; newn < se; ++newn)
		    {
		      if (EXTMATCH (c, newn, se, p, pe, flags) == 0)
			return (0);
		    }
		  /* We didn't match the extended glob pattern, but
		     that's OK, since we can match 0 or more occurrences.
		     We need to skip the glob pattern and see if we
		     match the rest of the string. */
		  newn = PATSCAN (p + 1, pe, 0, flags);
		  /* If NEWN is 0, we have an ill-formed pattern. */
		  p = newn ? newn : pe;
		}
#endif
	      if (p == pe)
		break;
	    }

	  /* The wildcards are the last element of the pattern.  The name
	     cannot match completely if we are looking for a pathname and
	     it contains another slash, unless FNM_LEADING_DIR is set. */
	  if (c == (int) L('\0'))
	    {
	      int r = (flags & FNM_PATHNAME) == 0 ? 0 : FNM_NOMATCH;
	      if (flags & FNM_PATHNAME)
		{
		  if (flags & FNM_LEADING_DIR)
		    r = 0;
		  else if (MEMCHR (n, (int) L('/'), se - n) == NULL)
		    r = 0;
		}
	      return r;
	    }

	  /* If we've hit the end of the pattern and the last character of
	     the pattern was handled by the loop above, we've succeeded.
	     Otherwise, we need to match that last character. */
	  if (p == pe && (c == (int) L('?') || c == (int) L('*')))
	    return (0);

	  /* If we've hit the end of the string and the rest of the pattern
	     is something that matches the empty string, we can succeed. */
#if defined (EXTENDED_GLOB)
	  if (n == se && ((flags & FNM_EXTMATCH) && (c == (int) L('!') || c == (int) L('?')) && *p == (int) L('(')))
	    {
	      --p;
	      if (EXTMATCH (c, n, se, p, pe, flags) == 0)
		return (c == (int) L('!') ? FNM_NOMATCH : 0);
	      return (c == (int) L('!') ? 0 : FNM_NOMATCH);
	    }
#endif

	  /* If we stop at a slash in the pattern and we are looking for a
	     pathname ([star]/foo), then consume enough of the string to stop
	     at any slash and then try to match the rest of the pattern.  If
	     the string doesn't contain a slash, fail */
	  if (c == (int) L('/') && (flags & FNM_PATHNAME))
	    {
	      while (n < se && *n != (int) L('/'))
		++n;
	      if (n < se && *n == (int) L('/') && (GMATCH (n+1, se, p, pe, NULL, flags) == 0))
		return 0;
	      return FNM_NOMATCH;	/* XXX */
	    }

	  /* General case, use recursion. */
	  {
	    U_CHAR c1;
	    const CHAR *endp;
	    struct STRUCT end;

	    end.pattern = NULL;
	    endp = MEMCHR (n, (flags & FNM_PATHNAME) ? (int) L('/') : (int) L('\0'), se - n);
	    if (endp == 0)
	      endp = se;

	    c1 = ((flags & FNM_NOESCAPE) == 0 && c == (int) L('\\')) ? *p : c;
	    c1 = FOLD (c1);
	    for (--p; n < endp; ++n)
	      {
		/* Only call strmatch if the first character indicates a
		   possible match.  We can check the first character if
		   we're not doing an extended glob match. */
		if ((flags & FNM_EXTMATCH) == 0 && c != (int) L('[') && FOLD (*n) != c1) /*]*/
		  continue;

		/* If we're doing an extended glob match and the pattern is not
		   one of the extended glob patterns, we can check the first
		   character. */
		if ((flags & FNM_EXTMATCH) && p[1] != (int) L('(') && /*)*/
		    STRCHR (L("?*+@!"), *p) == 0 && c != (int) L('[') && FOLD (*n) != c1) /*]*/
		  continue;

		/* Otherwise, we just recurse. */
		if (GMATCH (n, se, p, pe, &end, flags & ~(FNM_PERIOD|FNM_DOTDOT)) == 0)
		  {
		    if (end.pattern == NULL)
		      return (0);
		    break;
		  }
	      }
	    /* This is a clever idea from glibc, used to avoid backtracking
	       to a `*' that appears earlier in the pattern.  We get away
	       without saving se and pe because they are always the same,
	       even in the recursive calls to gmatch */ 
	    if (end.pattern != NULL)
	      {
		p = end.pattern;
		n = end.string;
		continue;
	      }

	    return FNM_NOMATCH;
	  }

	case (int) L('['):
	  {
	    if (sc == (int) L('\0') || n == se)
	      return FNM_NOMATCH;

	    /* A character class cannot match a `.' if it is the first
	       character of the string or if it is the first character
	       following a slash and we are matching a pathname. */
	    if ((flags & FNM_PERIOD) && sc == (int) L('.') &&
		(n == string || ((flags & FNM_PATHNAME) && n[-1] == (int) L('/'))))
	      return (FNM_NOMATCH);

	    /* If we are matching pathnames, we can't match a slash with a
	       bracket expression. */
	    if (sc == (int) L('/') && (flags & FNM_PATHNAME))
	      return (FNM_NOMATCH);

	    /* `?' cannot match `.' or `..' if it is the first character of the
	       string or if it is the first character following a slash and
	       we are matching a pathname. */
	    if ((flags & FNM_DOTDOT) &&
		((n == string && SDOT_OR_DOTDOT(n)) ||
		((flags & FNM_PATHNAME) && n > string && n[-1] == (int) L('/') && PDOT_OR_DOTDOT(n))))
	      return FNM_NOMATCH;

	    p = BRACKMATCH (p, sc, flags);
	    if (p == 0)
	      return FNM_NOMATCH;
	  }
	  break;

	default:
	  if ((U_CHAR)c != FOLD (sc))
	    return (FNM_NOMATCH);
	}

      ++n;
    }

  if (n == se)
    return (0);

  if ((flags & FNM_LEADING_DIR) && *n == (int) L('/'))
    /* The FNM_LEADING_DIR flag says that "foo*" matches "foobar/frobozz".  */
    return 0;
	  
  return (FNM_NOMATCH);
}

#define SLASH_PATHNAME(c)	(c == (int) L('/') && (flags & FNM_PATHNAME))

/* Parse a special bracket expression symbol ([.sym.], [=char=], [:cclass:]),
   starting at P, and return the position of the terminating .], =], or :].
   P points to the character after the opening bracket. Returns NULL if the
   symbol isn't correctly terminated. */
static inline CHAR *
PARSE_SUBBRACKET (CHAR *p, int flags)
{
  CHAR type;		/* the type of special bracket expression symbol */

  type = *p;

  /* POSIX allows a right bracket to appear in a collating symbol. */
  while (*++p != (int) L('\0') && SLASH_PATHNAME (*p) == 0 && type != (int) L('.') && *p == (int) L(']') == 0)
    if (*p == type && p[1] == (int) L(']'))
      return p;
  return NULL;
}

/* Use prototype definition here because of type promotion. */
static CHAR *
BRACKMATCH (CHAR *p, U_CHAR test, int flags)
{
  register CHAR cstart, cend, c;
  register int not;    /* Nonzero if the sense of the character class is inverted.  */
  int forcecoll, isrange;
  INT pc;
  CHAR *savep;
  CHAR *close;
  U_CHAR orig_test;

  orig_test = test;
  test = FOLD (orig_test);

  savep = p;

  /* POSIX.2 3.13.1 says that an exclamation mark (`!') shall replace the
     circumflex (`^') in its role in a `nonmatching list'.  A bracket
     expression starting with an unquoted circumflex character produces
     unspecified results.  This implementation treats the two identically. */
  if (not = (*p == (int) L('!') || *p == (int) L('^')))
    ++p;

  c = *p++;
  for (;;)
    {
      /* Initialize cstart and cend in case `-' is the last
	 character of the pattern. */
      cstart = cend = c;
      forcecoll = 0;

      /* POSIX.2 equivalence class:  [=c=].  See POSIX.2 2.8.3.2.  Find
	 the end of the equivalence class, move the pattern pointer past
	 it, and check for equivalence. */
      if (c == (int) L('[') && *p == (int) L('=') && (close = PARSE_SUBBRACKET (p, flags)) != NULL)
	{
	  p++;
	  pc = COLLSYM (p, close - p);
	  pc = FOLD (pc);
	  p = close + 2;

	  if (COLLEQUIV (test, pc))
	    {
/*[*/	      /* Move past the closing `]', since the first thing we do at
		 the `matched:' label is back p up one. */
	      p++;
	      goto matched;
	    }
	  else
	    {
	      c = *p++;
	      if (c == (int) L('\0'))
		return ((test == (int) L('[')) ? savep : (CHAR *)0); /*]*/
	      else if (c == (int) L('/') && (flags & FNM_PATHNAME))
		return ((test == (int) L('[')) ? savep : (CHAR *)0); /*]*/
	      else if (c == (int) L(']'))
		break;
	      c = FOLD (c);
	      continue;
	    }
	}

      /* POSIX.2 character class expression.  See POSIX.2 2.8.3.2. */
      if (c == (int) L('[') && *p == (int) L(':') && (close = PARSE_SUBBRACKET (p, flags)) != NULL)
	{
	  CHAR *ccname;

	  pc = 0;	/* make sure invalid char classes don't match. */

	  ccname = (CHAR *)malloc ((close - p) * sizeof (CHAR));
	  if (ccname)
	    {
	      bcopy (p + 1, ccname, (close - p - 1) * sizeof (CHAR));
	      *(ccname + (close - p - 1)) = (int) L('\0');
	      /* As a result of a POSIX discussion, char class names are
		 allowed to be quoted (?) */
	      DEQUOTE_PATHNAME (ccname);
	      pc = IS_CCLASS (orig_test, (XCHAR *)ccname);
	      if (pc == -1)
		{
		  /* CCNAME is not a valid character class in the current
		     locale. In addition to noting no match (pc = 0), we have
		     a choice about what to do with the invalid charclass.
		     Posix leaves the behavior unspecified, but we're going
		     to skip over the charclass and keep going instead of
		     testing ORIG_TEST against each character in the class
		     string. If we don't want to do that, take out the update
		     of P. */
		  pc = 0;
		}
	    }
	  free (ccname);

	  p = close + 2;

	  if (pc)
	    {
/*[*/	      /* Move past the closing `]', since the first thing we do at
		 the `matched:' label is back p up one. */
	      p++;
	      goto matched;
	    }
	  else
	    {
	      /* continue the loop here, since this expression can't be
		 the first part of a range expression. */
	      c = *p++;
	      if (c == (int) L('\0'))
		return ((test == (int) L('[')) ? savep : (CHAR *)0);
	      else if (c == (int) L('/') && (flags & FNM_PATHNAME))
		return ((test == (int) L('[')) ? savep : (CHAR *)0); /*]*/
	      else if (c == (int) L(']'))
		break;
	      c = FOLD (c);
	      continue;
	    }
	}
 
      /* POSIX.2 collating symbols.  See POSIX.2 2.8.3.2.  Find the end of
	 the symbol name, make sure it is terminated by `.]', translate
	 the name to a character using the external table, and do the
	 comparison. */
      if (c == (int) L('[') && *p == (int) L('.') && (close = PARSE_SUBBRACKET (p, flags)) != NULL)
	{
	  p++;
	  cstart = COLLSYM (p, close - p);
	  p = close + 2;
	  forcecoll = 1;
	}

      if (!(flags & FNM_NOESCAPE) && c == (int) L('\\'))
	{
	  if (*p == '\0')
	    return ((test == (int) L('[')) ? savep : (CHAR *)0);
	  else if (*p == (int) L('/') && (flags & FNM_PATHNAME))
	    return ((test == (int) L('[')) ? savep : (CHAR *)0);
	  cstart = cend = *p++;
	}

      cstart = cend = FOLD (cstart);
      isrange = 0;

      /* POSIX.2 2.8.3.1.2 says: `An expression containing a `[' that
	 is not preceded by a backslash and is not part of a bracket
	 expression produces undefined results.'  This implementation
	 treats the `[' as just a character to be matched if there is
	 not a closing `]'. */
      if (c == (int) L('\0'))
	return ((test == (int) L('[')) ? savep : (CHAR *)0);

      /* POSIX.2 2.13.3 says: `If a <slash> character is found following an
         unescaped <left-square-bracket> character before a corresponding
         <right-square-bracket> is found, the open bracket shall be treated
         as an ordinary character.' If we find a slash in a bracket
         expression and the flags indicate we're supposed to be treating the
         string like a pathname, we have to treat the `[' as just a character
         to be matched. */
      if (c == (int) L('/') && (flags & FNM_PATHNAME))
	return ((test == (int) L('[')) ? savep : (CHAR *)0);

      c = *p++;
      c = FOLD (c);

      if (c == (int) L('\0'))
	return ((test == (int) L('[')) ? savep : (CHAR *)0);
      else if (c == (int) L('/') && (flags & FNM_PATHNAME))
	return ((test == (int) L('[')) ? savep : (CHAR *)0);

      /* This introduces a range, unless the `-' is the last
	 character of the class.  Find the end of the range
	 and move past it. */
      if (c == (int) L('-') && *p != (int) L(']'))
	{
	  cend = *p++;
	  if (!(flags & FNM_NOESCAPE) && cend == (int) L('\\'))
	    cend = *p++;
	  if (cend == (int) L('\0'))
	    return ((test == (int) L('[')) ? savep : (CHAR *)0);
	  else if (cend == (int) L('/') && (flags & FNM_PATHNAME))
	    return ((test == (int) L('[')) ? savep : (CHAR *)0);
	  if (cend == (int) L('[') && *p == (int) L('.') && (close = PARSE_SUBBRACKET (p, flags)) != NULL)
	    {
	      p++;
	      cend = COLLSYM (p, close - p);
	      p = close + 2;
	      forcecoll = 1;
	    }
	  cend = FOLD (cend);

	  c = *p++;

	  /* POSIX.2 2.8.3.2:  ``The ending range point shall collate
	     equal to or higher than the starting range point; otherwise
	     the expression shall be treated as invalid.''  Note that this
	     applies to only the range expression; the rest of the bracket
	     expression is still checked for matches. */
	  if (RANGECMP (cstart, cend, forcecoll) > 0)
	    {
	      if (c == (int) L(']'))
		break;
	      c = FOLD (c);
	      continue;
	    }
	  isrange = 1;
	}

      if (isrange == 0 && test == cstart)
        goto matched;
      if (isrange && RANGECMP (test, cstart, forcecoll) >= 0 && RANGECMP (test, cend, forcecoll) <= 0)
	goto matched;

      if (c == (int) L(']'))
	break;
    }
  /* No match. */
  return (!not ? (CHAR *)0 : p);

matched:
  /* Skip the rest of the [...] that already matched.  */
  c = *--p;
  while (1)
    {
      /* A `[' without a matching `]' is just another character to match. */
      if (c == (int) L('\0'))
	return ((test == (int) L('[')) ? savep : (CHAR *)0);
      else if (c == (int) L('/') && (flags & FNM_PATHNAME))
	return ((test == (int) L('[')) ? savep : (CHAR *)0);

      c = *p++;
      if (c == (int) L('[') && (*p == (int) L('=') || *p == (int) L(':') || *p == (int) L('.')))
	{
	  if ((close = PARSE_SUBBRACKET (p, flags)) != NULL)
	    p = close + 2;
	}
      /* Left bracket loses its special meaning inside a bracket expression.
         It is only valid when followed by a `.', `=', or `:', which we check
         for above. Technically the right bracket can appear in a collating
         symbol, so we check for that as well. The right brackets terminating
         collating symbols, equivalence classes, or character classes are
         processed by PARSE_SUBBRACKET. Otherwise, a right bracket terminates
         the bracket expression. */
      else if (c == (int) L(']'))
	break;
      else if (!(flags & FNM_NOESCAPE) && c == (int) L('\\'))
	{
	  if (*p == '\0')
	    return ((test == (int) L('[')) ? savep : (CHAR *)0);
	  /* We don't allow backslash to quote slash if we're matching pathnames */
	  else if (*p == (int) L('/') && (flags & FNM_PATHNAME))
	    return ((test == (int) L('[')) ? savep : (CHAR *)0);
	  /* Posix issue 8 leaves this unspecified for the shell. */
	  ++p;
	}
    }
  return (not ? (CHAR *)0 : p);
}

#if defined (EXTENDED_GLOB)
/* ksh-like extended pattern matching:

	[?*+@!](pat-list)

   where pat-list is a list of one or patterns separated by `|'.  Operation
   is as follows:

	?(patlist)	match zero or one of the given patterns
	*(patlist)	match zero or more of the given patterns
	+(patlist)	match one or more of the given patterns
	@(patlist)	match exactly one of the given patterns
	!(patlist)	match anything except one of the given patterns
*/

/* Scan a pattern starting at STRING and ending at END, keeping track of
   embedded () and [].  If DELIM is 0, we scan until a matching `)'
   because we're scanning a `patlist'.  Otherwise, we scan until we see
   DELIM.  In all cases, we never scan past END.  The return value is the
   first character after the matching DELIM or NULL if the pattern is
   empty or invalid. */
/*static*/ CHAR *
PATSCAN (CHAR *string, CHAR *end, INT delim,  int flags)
{
  int pnest, bnest, skip;
  CHAR *s, c, *bfirst, *t;

  pnest = bnest = skip = 0;
  bfirst = NULL;

  if (string == end)
    return (NULL);

  for (s = string; c = *s; s++)
    {
      if (s >= end)
	return (s);
      if (skip)
	{
	  skip = 0;
	  continue;
	}
      switch (c)
	{
	case (int) L('\\'):
	  if ((flags & FNM_NOESCAPE) == 0)
	    skip = 1;
	  break;

	case (int) L('\0'):
	  return ((CHAR *)NULL);

	/* `[' is not special inside a bracket expression, but it may
	   introduce one of the special POSIX bracket expressions
	   ([.SYM.], [=c=], [: ... :]) that needs special handling. */
	case (int) L('['):
	  if (bnest == 0)
	    {
	      bfirst = s + 1;
	      if (*bfirst == (int) L('!') || *bfirst == (int) L('^'))
		bfirst++;
	      bnest++;
	    }
	  else if (s[1] == (int) L(':') || s[1] == (int) L('.') || s[1] == (int) L('='))
	    {
	      t = PARSE_SUBBRACKET (s + 1, flags);
	      if (t)
		s = t + 2 - 1;	/* -1 to cancel s++ in loop above */
	    }
	  break;

	/* `]' is not special if it's the first char (after a leading `!'
	   or `^') in a bracket expression or if it's part of one of the
	   special POSIX bracket expressions ([.SYM.], [=c=], [: ... :]) */
	case (int) L(']'):
	  if (bnest)
	    {
	      if (s != bfirst)
		{
		  bnest--;
		  bfirst = 0;
		}
	    }
	  break;

	case (int) L('('):
	  if (bnest == 0)
	    pnest++;
	  break;

	case (int) L(')'):
	  if (bnest == 0 && pnest-- <= 0)
	    return ++s;
	  break;

	case (int) L('|'):
	  if (bnest == 0 && pnest == 0 && delim == (int) L('|'))
	    return ++s;
	  break;
	}
    }

  return (NULL);
}

/* Return 0 if dequoted pattern matches S in the current locale. */
static int
STRCOMPARE (CHAR *p, CHAR *pe, CHAR *s, CHAR *se)
{
  int ret;
  CHAR c1, c2;
  int l1, l2;

  l1 = pe - p;
  l2 = se - s;

  if (l1 != l2)
    return (FNM_NOMATCH);	/* unequal lengths, can't be identical */
  
  c1 = *pe;
  c2 = *se;

  if (c1 != 0)
    *pe = '\0';
  if (c2 != 0)
    *se = '\0';
    
#if HAVE_MULTIBYTE || defined (HAVE_STRCOLL)
  ret = STRCOLL ((XCHAR *)p, (XCHAR *)s);
#else
  ret = STRCMP ((XCHAR *)p, (XCHAR *)s);
#endif

  if (c1 != 0)
    *pe = c1;
  if (c2 != 0)
    *se = c2;

  return (ret == 0 ? ret : FNM_NOMATCH);
}

/* Match a ksh extended pattern specifier.  Return FNM_NOMATCH on failure or
   0 on success.  This is handed the entire rest of the pattern and string
   the first time an extended pattern specifier is encountered, so it calls
   gmatch recursively. */
static int
EXTMATCH (INT xc, CHAR *s, CHAR *se, CHAR *p, CHAR *pe, int flags)
{
  CHAR *prest;			/* pointer to rest of pattern */
  CHAR *psub;			/* pointer to sub-pattern */
  CHAR *pnext;			/* pointer to next sub-pattern */
  CHAR *srest;			/* pointer to rest of string */
  int m1, m2, xflags;		/* xflags = flags passed to recursive matches */

#if DEBUG_MATCHING
fprintf(stderr, "extmatch: xc = %c\n", xc);
fprintf(stderr, "extmatch: s = %s; se = %s\n", s, se);
fprintf(stderr, "extmatch: p = %s; pe = %s\n", p, pe);
fprintf(stderr, "extmatch: flags = %d\n", flags);
#endif

  prest = PATSCAN (p + (*p == (int) L('(')), pe, 0, flags); /* ) */
  if (prest == 0)
    /* If PREST is 0, we failed to scan a valid pattern.  In this
       case, we just want to compare the two as strings. */
    return (STRCOMPARE (p - 1, pe, s, se));

  glob_recursion_depth++;

  switch (xc)
    {
    case (int) L('+'):		/* match one or more occurrences */
    case (int) L('*'):		/* match zero or more occurrences */
      /* If we can get away with no matches, don't even bother.  Just
	 call GMATCH on the rest of the pattern and return success if
	 it succeeds. */
      if (xc == (int) L('*') && (GMATCH (s, se, prest, pe, NULL, flags) == 0))
	return 0;

      /* OK, we have to do this the hard way.  First, we make sure one of
	 the subpatterns matches, then we try to match the rest of the
	 string. */
      for (psub = p + 1; ; psub = pnext)
	{
	  pnext = PATSCAN (psub, pe, (int) L('|'), flags);
	  for (srest = s; srest <= se; srest++)
	    {
	      /* Match this substring (S -> SREST) against this
		 subpattern (psub -> pnext - 1) */
	      m1 = GMATCH (s, srest, psub, pnext - 1, NULL, flags) == 0;
	      /* OK, we matched a subpattern, so make sure the rest of the
		 string matches the rest of the pattern.  Also handle
		 multiple matches of the pattern. */
	      if (m1)
		{
		  /* if srest > s, we are not at start of string */
		  xflags = (srest > s) ? (flags & ~(FNM_PERIOD|FNM_DOTDOT)) : flags;
		  m2 = (GMATCH (srest, se, prest, pe, NULL, xflags) == 0) ||
			(s != srest && GMATCH (srest, se, p - 1, pe, NULL, xflags) == 0);
		}
	      if (m1 && m2)
		return (0);
	    }
	  if (pnext == prest)
	    break;
	}
      return (FNM_NOMATCH);

    case (int) L('?'):		/* match zero or one of the patterns */
    case (int) L('@'):		/* match one (or more) of the patterns */
      /* If we can get away with no matches, don't even bother.  Just
	 call gmatch on the rest of the pattern and return success if
	 it succeeds. */
      if (xc == (int) L('?') && (GMATCH (s, se, prest, pe, NULL, flags) == 0))
	return 0;

      /* OK, we have to do this the hard way.  First, we see if one of
	 the subpatterns matches, then, if it does, we try to match the
	 rest of the string. */
      for (psub = p + 1; ; psub = pnext)
	{
	  pnext = PATSCAN (psub, pe, (int) L('|'), flags);
	  srest = (prest == pe) ? se : s;
	  for ( ; srest <= se; srest++)
	    {
	      /* if srest > s, we are not at start of string */
	      xflags = (srest > s) ? (flags & ~(FNM_PERIOD|FNM_DOTDOT)) : flags;
	      if (GMATCH (s, srest, psub, pnext - 1, NULL, flags) == 0 &&
		  GMATCH (srest, se, prest, pe, NULL, xflags) == 0)
		return (0);
	    }
	  if (pnext == prest)
	    break;
	}
      return (FNM_NOMATCH);

    case '!':		/* match anything *except* one of the patterns */
      for (srest = s; srest <= se; srest++)
	{
	  m1 = 0;
	  for (psub = p + 1; ; psub = pnext)
	    {
	      pnext = PATSCAN (psub, pe, (int) L('|'), flags);
	      /* If one of the patterns matches, just bail immediately. */
	      if (m1 = (GMATCH (s, srest, psub, pnext - 1, NULL, flags) == 0))
		break;
	      if (pnext == prest)
		break;
	    }

	  /* If nothing matched, but the string starts with a period and we
	     need to match periods explicitly, don't return this as a match,
	     even for negation. */
	  if (m1 == 0 && (flags & FNM_PERIOD) && *s == '.')
	    return (FNM_NOMATCH);

	  if (m1 == 0 && (flags & FNM_DOTDOT) && (SDOT_OR_DOTDOT (s)))
	    return (FNM_NOMATCH);

	  /* if srest > s, we are not at start of string */
	  xflags = (srest > s) ? (flags & ~(FNM_PERIOD|FNM_DOTDOT)) : flags;
	  if (m1 == 0 && GMATCH (srest, se, prest, pe, NULL, xflags) == 0)
	    return (0);
	}
      return (FNM_NOMATCH);
    }

  return (FNM_NOMATCH);
}
#endif /* EXTENDED_GLOB */

#undef IS_CCLASS
#undef FOLD
#undef CHAR
#undef U_CHAR
#undef XCHAR
#undef INT
#undef INVALID
#undef FCT
#undef GMATCH
#undef COLLSYM
#undef PARSE_SUBBRACKET
#undef PATSCAN
#undef STRCOMPARE
#undef EXTMATCH
#undef DEQUOTE_PATHNAME
#undef STRUCT
#undef BRACKMATCH
#undef STRCHR
#undef STRCOLL
#undef STRLEN
#undef STRCMP
#undef MEMCHR
#undef COLLEQUIV
#undef RANGECMP
#undef ISDIRSEP
#undef PATHSEP
#undef PDOT_OR_DOTDOT
#undef SDOT_OR_DOTDOT
#undef L
