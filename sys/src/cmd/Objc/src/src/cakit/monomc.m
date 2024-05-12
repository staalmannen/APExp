
/*
 * Computer Algebra Kit (c) 1995,98,99,2014 by David Stes.  All Rights Reserved.
 * $Id: monomc.m,v 1.7 2014/03/04 09:09:34 stes Exp $
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

@implementation monomialc
- empty 
{
  [self subclassResponsibility:_cmd];
  return nil;
}
- (BOOL)isEmpty 
{
  [self subclassResponsibility:_cmd];
  return NO;
}
- (int)numTerms 
{
  [self subclassResponsibility:_cmd];
  return 0;
}
- eachTerm 
{
  [self subclassResponsibility:_cmd];
  return nil;
}
- insertTerm:aTerm 
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- square
{
  id seq, term, res;
  res = [self empty];
  seq = [self eachTerm];
  while ((term = [seq next]))
    [res insertTerm:[term square]];
  return res;
}

- multiply:b
{
  id res, seq, term;
  res = [self empty];

  seq = [self eachTerm];
  while ((term = [seq next]))
    [res insertTerm:term];

  seq = [b eachTerm];
  while ((term = [seq next]))
    [res insertTerm:term];

  return res;
}

- divide:b
{
  id res, seq, term;
  res = [self empty];

  seq = [self eachTerm];
  while ((term = [seq next]))
    [res insertTerm:term];

  seq = [b eachTerm];
  while ((term = [seq next]))
    {
      term = [term inverse];
      assert ([term check]);
      if ([res insertTerm:term])
	{
	  continue;
	}
      else
	{
	  return nil;
	}
    }

  return res;
}

@end
 
