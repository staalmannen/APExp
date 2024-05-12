
/*
 * Portable Object Compiler (c) 1997.  All Rights Reserved.
 * $Id: setseq.m,v 1.2 2020/04/16 19:16:08 stes Exp $
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
#include "setseq.h"

@implementation SetSequence
- (objsetseq_t) objsetseqvalue
{
  return &value;
}

static void 
objsetseq_init (objsetseq_t self, id set)
{
  self->set = [set objsetvalue];
  self->offset = 0;
}

+ over:set
{
  id newObj = [super new];
  objsetseq_init ([newObj objsetseqvalue], set);
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
size (objset_t self)
{
  return self->count;
}

static int 
objsetseq_size (objsetseq_t self)
{
  return size (self->set);
}

static id 
at (objset_t self, int i)
{
  assert (0 <= i && i < self->capacity);
  return (self->ptr) [i];
}

- (unsigned) size
{
  return (unsigned) objsetseq_size ([self objsetseqvalue]);
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
match (objset_t self, int i)
{
  return ptrmatch (self->ptr, i, self->capacity);
}

static id 
next (objsetseq_t self)
{
  int i = match (self->set, self->offset);
  if (i == -1)
    {
      return nil;
    }
  else
    {
      id obj = at (self->set, i);
      self->offset = i + 1;
      return obj;
    }
}

- next
{
  return next ([self objsetseqvalue]);
}

static id 
peek (objsetseq_t self)
{
  int i = match (self->set, self->offset);
  if (i == -1)
    {
      return nil;
    }
  else
    {
      return at (self->set, i);
    }
}

- peek
{
  return peek ([self objsetseqvalue]);
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
prev (objset_t self, int i)
{
  return ptrprev (self->ptr, i);
}

static id 
objsetseq_prev (objsetseq_t self)
{
  int i = prev (self->set, self->offset);
  return (i == -1) ? nil : at (self->set, i);
}

- previous
{
  return objsetseq_prev ([self objsetseqvalue]);
}

static id 
objsetseq_first (objsetseq_t self)
{
  int i = match (self->set, 0);
  return (i == -1) ? nil : at (self->set, i);
}

- first
{
  return objsetseq_first ([self objsetseqvalue]);
}

static int 
last (objset_t self)
{
  return prev (self, self->capacity);
}

static id 
objsetseq_last (objsetseq_t self)
{
  int i = last (self->set);
  return (i == -1) ? nil : at (self->set, i);
}

- last
{
  return objsetseq_last ([self objsetseqvalue]);
}

@end
 
