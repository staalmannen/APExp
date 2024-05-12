
/*
 * Portable Object Compiler (c) 1997,98.  All Rights Reserved.
 * $Id: treeseq.m,v 1.2 2020/04/16 19:16:09 stes Exp $
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
#include "treeseq.h"

@implementation TreeSequence
static objbbt_t 
first (objbbt_t p)
{
  while (p->llink)
    p = p->llink;
  return p;
}

static objbbt_t 
last (objbbt_t p)
{
  while (p->rlink)
    p = p->rlink;
  return p;
}

- setUpSort:aSort
{
  top = [aSort objbbtTop];
  prev = NULL;
  next = (top) ? first (top) : NULL;
  return self;
}

+ over:aSort
{
  id newObj = [super new];
  [newObj setUpSort:aSort];
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
size (objbbt_t self)
{
  int n = 1;
  if (self->llink)
    n += size (self->llink);
  if (self->rlink)
    n += size (self->rlink);
  return n;
}

- (unsigned) size
{
  return (top) ? size (top) : 0;
}

static objbbt_t 
nextulink (objbbt_t p, objbbt_t top)
{
  while (p != top)
    {
      objbbt_t ulink;
      ulink = p->ulink;
      if (p == ulink->llink)
	return ulink;
      p = ulink;
    }

  return NULL;
}

static objbbt_t 
nextnode (objbbt_t p, objbbt_t top)
{
  objbbt_t link;

  if ((link = p->rlink))
    {
      return first (link);
    }
  else
    {
      return nextulink (p, top);
    }
}

- next
{
  if (next)
    {
      prev = next;
      next = nextnode (next, top);
      return prev->key;
    }
  else
    {
      return nil;
    }
}

- peek
{
  return (next) ? next->key : nil;
}

- previous
{
  return (prev) ? prev->key : nil;
}

- first
{
  if (top)
    {
      objbbt_t f = first (top);
      return f->key;
    }
  else
    {
      return nil;
    }
}

- last
{
  if (top)
    {
      objbbt_t l = last (top);
      return l->key;
    }
  else
    {
      return nil;
    }
}

@end
 
