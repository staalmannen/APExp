
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: polyeseq.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

@implementation exppolscalar_sequence
- _setUpContent:aPolynomial
{
  assert ([aPolynomial isExpanded]);
  content = aPolynomial;
  eachMonomial = [aPolynomial eachMonomial];
  return self;
}

+ content:aPolynomial
{
  return [[super new] _setUpContent:aPolynomial];
}

- toFirst
{
  [eachMonomial toFirst];
  return self;
}

- toLast
{
  [eachMonomial toLast];
  return self;
}

- (unsigned) size
{
  return [eachMonomial size];
}

- (BOOL) isEmpty
{
  return [eachMonomial isEmpty];
}

- toElementAt:(int)i
{
  [eachMonomial toElementAt:i];
  return self;
}

- next
{
  id next = [eachMonomial next];
  return (next) ? [next scalar] : nil;
}

- previous
{
  id previous = [eachMonomial previous];
  return (previous) ? [previous scalar] : nil;
}

@end
 
