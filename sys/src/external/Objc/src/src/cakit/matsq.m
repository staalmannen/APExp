
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: matsq.m,v 1.7 2014/03/04 09:38:34 stes Exp $
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

#include "cakit.h"

@implementation CAMatrixSequenceScalars
- _setUpContent:aMatrix
{
  content = aMatrix;
  eachSequence = [aMatrix eachSequence];
  return self;
}

+ content:aMatrix
{
  return [[super new] _setUpContent:aMatrix];
}

- toFirst
{
  currentSequence = [eachSequence firstElement];
  [currentSequence toFirst];
  return self;
}

- toLast
{
  currentSequence = [eachSequence lastElement];
  [currentSequence toLast];
  return self;
}

- (BOOL) isEmpty
{
  return [eachSequence isEmpty];
}

- (unsigned) size
{
  [self doesNotRecognize:_cmd];
  return 0;
}

- toElementAt:(int)i
{
  [self doesNotRecognize:_cmd];
  return self;
}

- next
{
  id next;
  assert (currentSequence != nil);

  if ((next = [currentSequence next]))
    {
      return next;
    }
  else
    {
      if ((currentSequence = [eachSequence next]))
	{
	  [currentSequence toFirst];
	  return [self next];
	}
      else
	{
	  [self toLast];
	  return nil;
	}
    }
}

- previous
{
  id previous;
  assert (currentSequence != nil);

  if ((previous = [currentSequence previous]))
    {
      return previous;
    }
  else
    {
      if ((currentSequence = [eachSequence previous]))
	{
	  [currentSequence toLast];
	  return [self previous];
	}
      else
	{
	  [self toFirst];
	  return nil;
	}
    }
}

@end
 
