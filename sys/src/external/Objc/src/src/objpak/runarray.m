
/*
 * Portable Object Compiler (c) 1997,98,99,03.  All Rights Reserved.
 * $Id: runarray.m,v 1.4 2020/04/16 19:16:08 stes Exp $
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "config.h"
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include "runarray.h"
#include "notfound.h"
#include "outofbnd.h"
#include "txtattr.h"
#include "ordcltn.h"
#include "intarray.h"

@implementation RunArray

- reset
{
  laststart = -1;
  return self;
}

- check
{
  int i, n;
  id attrs;
  unsigned s;
  unsigned totalsize = 0;

  assert ([runs capacity] >= [values size]);

  for (i = 0, n = [values size]; i < n; i++)
    {
      attrs = [values at:i];
      assert ([attrs isKindOf:(id) [OrdCltn class]]);
      s = [runs intAt:i];
      assert (s > 0);
      totalsize += s;
    }

  assert (totalsize == size);
  return self;
}

+ new
{
  return [[super new] runs:[IntArray new] values:[OrdCltn new]];
}

- free
{
  [values elementsPerform:@selector (freeContents)];
  [[values freeContents] free];
  [runs free];
  return [super free];
}


- values
{
  return values;
}

- runs
{
  return runs;
}

- runs:r values:v
{
  runs = r;
  values = v;
  [self reset];
  return self;
}

- at:(unsigned)i
{
  int j, n;
  unsigned p;

  if (i >= size)
    {
      [OutOfBounds signal];
      return nil;
    }

  /* most common cases */

  if (laststart != -1)
    {
      if (laststart <= i && i < lastend)
	return [values at:lastsegment];
      if (i == lastend)
	{
	  lastsegment++;
	  laststart = lastend;
	  lastend = laststart + [runs intAt:lastsegment];
	  return [values at:lastsegment];
	}
    }

  /* otherwise linear search */

  for (j = 0, p = 0, n = [values size]; j < n; j++)
    {
      unsigned q = p + [runs intAt:j];
      if (p <= i && i < q)
	{
	  laststart = p;
	  lastend = q;
	  lastsegment = j;
	  return [values at:j];
	}
      p = q;
    }

  [NotFound signal];
  return nil;
}

- (unsigned) runLengthAt:(unsigned)i
{
  int j, n;
  unsigned p;

  if (i >= size)
    {
      [OutOfBounds signal];
      return 0;
    }

  /* most common cases */

  if (laststart != -1)
    {
      if (laststart <= i && i < lastend)
	return lastend - i;
      if (i == lastend)
	{
	  lastsegment++;
	  laststart = lastend;
	  lastend = laststart + [runs intAt:lastsegment];
	  return lastend - i;
	}
    }

  /* otherwise linear search */

  for (j = 0, p = 0, n = [values size]; j < n; j++)
    {
      unsigned q = p + [runs intAt:j];
      if (p <= i && i < q)
	{
	  laststart = p;
	  lastend = q;
	  lastsegment = j;
	  return lastend - i;
	}
      p = q;
    }

  [NotFound signal];
  return 0;
}


- (unsigned) size
{
  return size;
}

- calcsize
{
  int i, n;
  int totalsize = 0;

  assert ([runs capacity] >= [values size]);

  for (i = 0, n = [values size]; i < n; i++)
    {
      int s = [runs intAt:i];

      totalsize += s;
    }

  size = totalsize;
  return self;
}

- setsize:(unsigned)newsize
{
  if (size == newsize)
    return self;

  if (size < newsize)
    {
      int n = [values size];
      int m = [runs capacity];
      if (m < (n + 1))
	[runs capacity:(2 * m + 1)];
      [values add:[OrdCltn new]];
      [runs intAt:n put:(newsize - size)];
      size = newsize;
    }
  else
    {
      [self notImplemented:_cmd];
    }

  assert ([self check]);
  return self;
}

- addAttribute:attrib to:v
{
  int n = [v size];

  [attrib reset];
  while (n--)
    {
      if ([attrib dominates:[v at:n]])
	{
	  id atb = [v removeAt:n];
#ifndef OBJC_REFCNT
	  [atb free];
#endif
	}
    }
  if ([attrib set])
    {
      [v add:attrib];
#ifndef OBJC_REFCNT
    }
  else
    {
      [attrib free];
#endif
    }
  return self;
}

- breakat:(int)i
{
  int j, k, p, n;

  for (j = 0, p = 0, n = [values size]; j < n; j++)
    {
      unsigned q = p + [runs intAt:j];

      if (p == i || q == i)
	return self;		/* nothing to break; */
      if (p < i && q > i)
	{
	  int m = [runs capacity];
	  id v = [[values at:j] deepCopy];

	  if (m < (n + 1))
	    [runs capacity:(2 * m + 1)];
	  [values at:j insert:v];
	  k = n;
	  while (--k >= j)
	    [runs intAt:k + 1 put:[runs intAt:k]];
	  [runs intAt:j put:i - p];
	  [runs intAt:j + 1 put:q - i];
	  return self;
	}
      p = q;
    }
  return [self error:"Error in run computation"];
}

- addAttribute:attrib from:(unsigned)p size:(unsigned)s
{
  int i;

  if (s == 0)
    return self;

  /* common case : append after end (expand) */

  if (p >= size)
    {
      if (p > size)
	[self setsize:p];	/* possibly a slice without formatting props */
      [self setsize:p + s];
      i = [values size];
      assert ([runs intAt:i - 1] == s);
      return [self addAttribute:attrib to:[values at:i - 1]];
    }

  /* common case : append at exactly the last run */

  i = [values size];
  if ((i != 0) && (p + s == size) && (s == [runs intAt:i - 1]))
    {
      return [self addAttribute:attrib to:[values at:i - 1]];
    }

  /* case we're using random offsets into text */
  /* this doesn't have to be super-fast */

  if (p + s > size)
    {
      [self setsize:p + s];
      [self breakat:p];
    }
  else
    {
      [self breakat:p];
      [self breakat:p + s];
    }

  [self reset];

  for (i = 0; i < size; i += [self runLengthAt:i])
    {
      if (i == p + s)
	break;
      if (i > p + s)
	[self error:"Error in run computation."];
      if (i >= p)
	[self addAttribute:[attrib copy] to:[self at:i]];
    }

#ifndef OBJC_REFCNT
  [attrib free];
#endif
  return self;
}

- calcinsertsegment:(int)i
{
  int j, n;
  unsigned p;

  if (i >= size)
    {
      [OutOfBounds signal];
      return nil;
    }

  /* most common cases */

  if (laststart != -1)
    {
      /* for insertion, don't move to next segment if i == lastend */
      if (laststart < i && i <= lastend)
	return self;
    }

  /* otherwise linear search */

  for (j = 0, p = 0, n = [values size]; j < n; j++)
    {
      unsigned q = p + [runs intAt:j];
      /* for insertion, don't move to next segment if i == lastend */
      if (p <= i && i <= q)
	{
	  laststart = p;
	  lastend = q;
	  lastsegment = j;
	  return self;
	}
      p = q;
    }

  [NotFound signal];
  return nil;
}

- at:(unsigned)anOffset insert:(char*)aString count:(int)n
{
  if (anOffset == size)
    {
      int s = [runs size];
      if (s)
	{
	  [runs intAt:s - 1 put:[runs intAt:s - 1] + n];	/* use same formatting */
	  size += n;
	}
      else
	{
	  [self setsize:size + n];	/* slice without formatting */
	}
    }
  else
    {
      [self calcinsertsegment:anOffset];	/* compute lastsegment */
      [runs intAt:lastsegment put:[runs intAt:lastsegment] + n];
      size += n;
    }
  [self reset];
  assert ([self check]);
  return self;
}

- deleteFrom:(unsigned)p to:(unsigned)q
{
  int i, is, j, je, n;

  if (p > q)
    {
      [OutOfBounds signal];
      return nil;
    }

  assert ([self check]);

  n = q - p + 1;
  [self at:p];			/* compute lastsegment */
  i = lastsegment;
  is = laststart;
  [self at:q];
  j = lastsegment;
  je = lastend;
  [self reset];

  if (i == j)
    {
      int m = [runs intAt:i];

      assert (m >= n);
      [runs intAt:i put:m - n];
      if (m == n)
	{
	  id atb = [values removeAt:i];
#ifndef OBJC_REFCNT
	  [[atb freeContents] free];
#endif
	}
    }
  else
    {
      int m, k, r;

      m = [runs intAt:i];
      assert (p >= is);
      [runs intAt:i put:p - is];
      for (k = i + 1; k < j; k++)
	[runs intAt:k put:0];
      m = [runs intAt:j];
      assert (q < je);
      [runs intAt:j put:je - q - 1];

      r = i;
      if (is == p)
	{
	  id atb = [values removeAt:r];
#ifndef OBJC_REFCNT
	  [[atb freeContents] free];
#endif
	}
      else
	{
	  r++;
	}
      for (k = i + 1; k < j; k++)
	{
	  id atb = [values removeAt:r];
#ifndef OBJC_REFCNT
	  [[atb freeContents] free];
#endif
	}
      if (je == q + 1)
	{
	  id atb = [values removeAt:r];
#ifndef OBJC_REFCNT
	  [[atb freeContents] free];
#endif
	}
    }

  size -= n;
  [runs packContents];		/* get rid of zeroes */

  assert ([self check]);
  return self;
}

- concat:b
{
  int i, m, n, k;
  id v, r = [b runs];

  k = [values size];
  n = [[b values] size];
  for (i = 0; i < n; i++)
    [runs intAt:k + i put:[r intAt:i]];

  v = [[b values] deepCopy];
  [values addAll:v];
#ifndef OBJC_REFCNT
  [v free];
#endif
  m = [runs capacity];
  if (m < k + n)
    [runs capacity:(k + n + 4)];

  size += [b size];
  assert ([self check]);
  return self;
}

- coalesce
{
  int n = [values size];

  while (n--)
    {
      id v, w;
      if (n == 0)
	break;
      v = [values at:n];
      w = [values at:n - 1];
      if ([v isEqual:w])
	{
	  id atb;
	  unsigned p = [runs intAt:n];
	  unsigned q = [runs intAt:n - 1];
	  [runs intAt:n - 1 put:p + q];
	  [runs intAt:n put:0];
	  atb = [values removeAt:n];
#ifndef OBJC_REFCNT
	  [[atb freeContents] free];
#endif
	  [runs packContents];
	}
    }

  return self;
}


- printOn:(IOD)aFile
{
  fprintf (aFile, "RunArray runs ");
  [runs printOn:aFile];
  [values printOn:aFile];
  return self;
}

@end
 
