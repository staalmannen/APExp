/* MinGW-specific implementation of wide-character functions.  */

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

#include <stddef.h>
#include <errno.h>
#include <stdbool.h>
#include "mbc32.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

bool mingw_using_utf8 (int);

/* No pretending hereafter... */
#ifndef _UCRT
#undef mbstate_t
#undef mbsinit
#endif	/* !_UCRT */
#undef mbrtoc32
#undef mbrlen
#undef c32rtomb

#ifndef _UCRT

static size_t
mbrtoc32 (char32_t *__restrict__ pc32, const char *__restrict__ s,
	  size_t n, mb32state_t *__restrict__ ps)
{
  static mb32state_t internal_state;
  unsigned char cbyte, length, remaining, mask;
  char32_t ch32;
  const char *start = s;

  if (!ps)
    ps = &internal_state;
  if (!s)
    {
      pc32 = NULL;
      s = "";
      n = 1;
    }
  if (!n)
    return (size_t)-2;
  
  if (!ps->rem)
    {
      /* Initial state.  */
      cbyte = *s++;
      if (!(cbyte & 0x80))
	length = 1;
      else if ((cbyte & 0xE0) == 0xC0)
	{
	  length = 2;
	  mask = 0x1F;
	}
      else if ((cbyte & 0xF0) == 0xE0)
	{
	  length = 3;
	  mask = 0x0F;
	}
      else if ((cbyte & 0xF8) == 0xF0)
	{
	  length = 4;
	  mask = 0x07;
	}
      else
	{
	  errno = EILSEQ;
	  internal_state.rem = 0;
	  return (size_t)-1;
	}
      remaining = length - 1;
      if (length == 1)
	{
	  /* ASCII.  */
	  ch32 = cbyte;
	  if (pc32)
	    *pc32 = ch32;
	  return ch32 ? 1 : 0;
	}
      else
	ch32 = cbyte & mask;
    }
  else
    {
      remaining = ps->rem;
      length = ps->total;
      ch32 = ps->ch;
      if (!((2 <= length && length <= 4)
	    && (1 <= remaining && remaining < length)
	    && (ch32 <= 0x43FF)))
	{
	  errno = EINVAL;
	  internal_state.rem = 0;
	  return (size_t)-1;
	}
    }

  while (s - start < n && remaining > 0)
    {
      cbyte = *s++;
      if (!((cbyte & 0xC0) == 0x80))
	{
	  errno = EILSEQ;
	  internal_state.rem = 0;
	  return (size_t)-1;
	}
      ch32 = (ch32 << 6) | (cbyte & 0x3F);
      remaining--;
    }
  if (remaining > 0)
    {
      ps->ch = ch32;
      ps->total = length;
      ps->rem = remaining;
      return (size_t)-2;
    }
  if (!((0x80 <= ch32 && ch32 <= 0x10FFFF)
	&& (ch32 < 0xD800 || ch32 > 0xDFFF)))
    {
      errno = EILSEQ;
      internal_state.rem = 0;
      return (size_t)-1;
    }
  switch (length)
    {
    case 3:
      if (ch32 < 0x800)
	{
	  errno = EILSEQ;
	  internal_state.rem = 0;
	  return (size_t)-1;
	}
      break;
    case 4:
      if (ch32 < 0x10000)
	{
	  errno = EILSEQ;
	  internal_state.rem = 0;
	  return (size_t)-1;
	}
      break;
    default:
      break;
    }
  
  if (pc32)
    *pc32 = ch32;
  ps->rem = 0;
  return length;
}

static size_t
c32rtomb (char *__restrict__ s, char32_t c32, mb32state_t *__restrict__ ps)
{
  wchar_t wc[2];
  size_t retval;
  int num_wc;

  /* We ignore the state, since conversion to UTF-8 is stateless, so
     pacify the compiler.  */
  ps = ps;

  if (!s)
    return 1;

  if (!(c32 & ~0x7F))
    {
      *s = c32 & 0x7F;
      return 1;
    }

  if (c32 > 0x10FFFF)
    {
      errno = EILSEQ;
      return (size_t) -1;
    }

  /* Convert C32 to UTF-16.  */
  if (c32 < 0x10000)
    {
      wc[0] = c32;
      wc[1] = 0;
    }
  else
    {
      wc[0] = ((c32 - 0x10000) >> 10) + 0xD800; /* high surrogate */
      wc[1] = (c32 & 0x3FF) + 0xDC00;	        /* low surrogate */
    }
  /* WideCharToMultiByte returns the number of bytes, including the
     terminating null, written to STR on success, zero on falure.  */
  num_wc = 1 + (wc[1] != 0);
  retval = WideCharToMultiByte (CP_UTF8, 0, wc, num_wc, s, 4, NULL, NULL);
  if (!retval
      /* Detect 0xFFFD as indication of invalid codepoint.  */
      || (retval == 3 && memcmp (s, "\xef\xbf\xbd", 3) == 0))
    {
      errno = EILSEQ;
      return (size_t) -1;
    }
  return retval;
}

size_t
mingw_mbrtoc32 (char32_t *__restrict__ pc32, const char *__restrict__ s,
		size_t n, mbstate32_t *__restrict__ ps)
{
  if (mingw_using_utf8 (UTF8_QUERY))
    {
      mb32state_t *state32 = ps ? &ps->mbs32 : NULL;
      return mbrtoc32 (pc32, s, n, state32);
    }
  else
    {
      /* Delegate to mbrtowc any non-UTF-8 cases.  */
      mbstate_t *state16 = ps ? &ps->mbs16 : NULL;
      wchar_t ch16 = *pc32 & 0xFFFF;
      size_t retval = mbrtowc (&ch16, s, n, state16);
      *pc32 = ch16;
      return retval;
    }
}

size_t
mbrlenc32 (const char *__restrict__ s, size_t n,
	   mbstate32_t *__restrict__ ps)
{
  mbstate32_t internal;
  if (!ps)
    {
      ps = &internal;
      memset (&internal, 0, sizeof(internal));
    }
  return mingw_mbrtoc32 (NULL, s, n, ps);
}

size_t
mingw_c32rtomb (char *__restrict__ s, char32_t c32,
		mbstate32_t *__restrict__ ps)
{
  if (mingw_using_utf8 (UTF8_QUERY))
    {
      mb32state_t *state32 = ps ? &ps->mbs32 : NULL;
      return c32rtomb (s, c32, state32);
    }
  else
    {
      mbstate_t *state16 = ps ? &ps->mbs16 : NULL;
      wchar_t c16 = c32 & 0xFFFF;
      size_t retval = wcrtomb (s, c16, state16);
      /* Evidently, at least MSVCRT wcrtomb returns zero for surrogates.  */
      if (!retval)
	retval = (size_t)-1;
      return retval;
    }
}

int
mingw_mbsinit (const mbstate32_t *ps)
{
  if (!ps)
    return 1;

  if (mingw_using_utf8 (UTF8_QUERY))
    {
      const mb32state_t *state32 = &ps->mbs32;
      return state32->rem == 0;
    }
  else
    {
      const mbstate_t *state16 = &ps->mbs16;
      return mbsinit (state16);
    }
}

#else	/* _UCRT */

size_t
mingw_mbrtoc32 (char32_t *__restrict__ pc32, const char *__restrict__ s,
		size_t n, mbstate_t *__restrict__ ps)
{
  if (mingw_using_utf8 (UTF8_QUERY))
    return mbrtoc32 (pc32, s, n, ps);
  else
    {
      /* Delegate to mbrtowc any non-UTF-8 cases.  */
      wchar_t ch16 = *pc32 & 0xFFFF;
      size_t retval = mbrtowc (&ch16, s, n, ps);
      *pc32 = ch16;
      return retval;
    }
}

size_t
mbrlenc32 (const char *__restrict__ s, size_t n,
	   mbstate_t *__restrict__ ps)
{
  mbstate_t internal;
  if (!ps)
    {
      ps = &internal;
      memset (&internal, 0, sizeof(internal));
    }
  return mingw_mbrtoc32 (NULL, s, n, ps);
}

size_t
mingw_c32rtomb (char *__restrict__ s, char32_t c32, mbstate_t *__restrict__ ps)
{
  if (mingw_using_utf8 (UTF8_QUERY))
    return c32rtomb (s, c32, ps);
  else
    {
      wchar_t c16 = c32 & 0xFFFF;
      size_t retval = wcrtomb (s, c16, ps);
      /* Evidently, at least MSVCRT wcrtomb returns zero for surrogates.  */
      if (!retval)
	retval = (size_t)-1;
      return retval;
    }
}

#endif	/* _UCRT */
