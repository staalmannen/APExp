
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: polycseq.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

@implementation recpolcoef_sequence
- _setUpContent:aPolynomial
{
  assert ([aPolynomial isRecursive] && [aPolynomial isVariableDense]);
  content = aPolynomial;
  eachTerm = [aPolynomial eachTerm];
  return self;
}

+ content:aPolynomial
{
  return [[super new] _setUpContent:aPolynomial];
}

- toFirst
{
  [eachTerm toFirst];
  return self;
}

- toLast
{
  [eachTerm toLast];
  return self;
}

- (unsigned) size
{
  return [eachTerm size];
}

- (BOOL) isEmpty
{
  return [eachTerm isEmpty];
}

- toElementAt:(int)i
{
  [eachTerm toElementAt:i];
  return self;
}

- next
{
  id next = [eachTerm next];
  return (next) ? [next coefficient] : nil;
}
- previous
{
  id previous = [eachTerm previous];
  return (previous) ? [previous coefficient] : nil;
}

@end
 
