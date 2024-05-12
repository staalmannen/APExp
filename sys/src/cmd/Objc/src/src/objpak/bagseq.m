
/*
 * Portable Object Compiler (c) 1997.  All Rights Reserved.
 * $Id: bagseq.m,v 1.2 2020/04/16 19:16:07 stes Exp $
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
#include <stdlib.h>
#include "bagseq.h"

@implementation BagSequence
- (objbagseq_t) objbagseqvalue
{
  return &value;
}

static void 
objbagseq_init (objbagseq_t self, id bag)
{
  self->set = [bag objbagvalue];
  self->offset = -1;		/* current pos */
  self->cnt = 0;		/* how many left at current pos */
}

+ over:bag
{
  id newObj = [super new];
  objbagseq_init ([newObj objbagseqvalue], bag);
  return newObj;
}

- copy
{
  return [super copy];
}

- free
{
  return [super free];
}

static int 
ptrsize (id * p, int *m, int c)
{
  int n = 0;
  while (c--)
    {
      n += (*m++);
    }
  return n;
}

static int 
size (objbag_t self)
{
  /* count is the number of distinct elements (no multiplicities) */
  return ptrsize (self->ptr, self->cnts, self->capacity);
}

static int 
objbagseq_size (objbagseq_t self)
{
  return size (self->set);
}

static int 
cntat (objbag_t self, int i)
{
  assert (0 <= i && i < self->capacity);
  return (self->cnts) [i];
}

static id 
at (objbag_t self, int i)
{
  assert (0 <= i && i < self->capacity);
  return (self->ptr) [i];
}

- (unsigned) size
{
  return (unsigned) objbagseq_size ([self objbagseqvalue]);
}

static int 
ptrmatch (id * p, int i, int n)
{
  while (i < n)
    if (p [i])
      return i;
    else
      i++;
  return -1;
}

static int 
match (objbag_t self, int i)
{
  return ptrmatch (self->ptr, i, self->capacity);
}

static id 
next (objbagseq_t self)
{
  if (self->cnt > 0)
    {
      self->cnt--;
      return at (self->set, self->offset);
    }
  else
    {
      int i = match (self->set, self->offset + 1);
      if (i == -1)
	{
	  return nil;
	}
      else
	{
	  id obj = at (self->set, i);
	  self->cnt = cntat (self->set, i) - 1;		/* how many left */
	  assert (self->cnt >= 0);
	  self->offset = i;
	  return obj;
	}
    }
}

- next
{
  return next ([self objbagseqvalue]);
}

static id 
peek (objbagseq_t self)
{
  if (self->cnt)
    {
      return at (self->set, self->offset);
    }
  else
    {
      int i = match (self->set, self->offset + 1);
      if (i == -1)
	{
	  return nil;
	}
      else
	{
	  return at (self->set, i);
	}
    }
}

- peek
{
  return peek ([self objbagseqvalue]);
}

static int 
ptrprev (id * p, int i)
{
  while (--i)
    if (p [i])
      return i;
  return -1;
}

static int 
prev (objbag_t self, int i)
{
  return ptrprev (self->ptr, i);
}

static id 
objbagseq_prev (objbagseq_t self)
{
  int i = prev (self->set, self->offset);
  return (i == -1) ? nil : at (self->set, i);
}

- previous
{
  return objbagseq_prev ([self objbagseqvalue]);
}

static id 
objbagseq_first (objbagseq_t self)
{
  int i = match (self->set, 0);
  return (i == -1) ? nil : at (self->set, i);
}

- first
{
  return objbagseq_first ([self objbagseqvalue]);
}

static int 
last (objbag_t self)
{
  return prev (self, self->capacity);
}

static id 
objbagseq_last (objbagseq_t self)
{
  int i = last (self->set);
  return (i == -1) ? nil : at (self->set, i);
}

- last
{
  return objbagseq_last ([self objbagseqvalue]);
}

@end
 
