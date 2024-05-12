
/*
 * Portable Object Compiler (c) 1997,98,2003.  All Rights Reserved.
 * $Id: cltn.m,v 1.5 2023/02/19 17:01:00 stes Exp $
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
#include <stdlib.h>
#include "cltn.h"
#include "set.h"
#include "ordcltn.h"
#include "sequence.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

@implementation Cltn

- eachElement
{
  return [self subclassResponsibility:_cmd];
}

- (BOOL) includes:anObject
{
  [self subclassResponsibility:_cmd];
  return NO;
}


- add:anObject
{
  return [self subclassResponsibility:_cmd];
}

- remove:anObject
{
  return [self subclassResponsibility:_cmd];
}

- addYourself
{
  return [self subclassResponsibility:_cmd];
}

- emptyYourself
{
  return [self subclassResponsibility:_cmd];
}

- perform:(SEL)aSel with:a with:b with:c
{
  /* if Object.h doesn't have this, add this dummy */
  return [self subclassResponsibility:_cmd];
}

/*****************************************************************************
 *
 * Creating with contents.
 *
 ****************************************************************************/

+ with:(int)nArgs,...
{
  id newObject;

  /* use OC macros for porting to SunOS4 */
  OC_VA_LIST vp;

  newObject = [self new];

  /* #if 0 this piece of code if problems with stdarg
   * typically this means the driver is not configured with
   * the right -builtintype
   * or builtinfunction flags (because the macros might expand to these)
   * 
   * alternative solution: check the .P output (-retain) and 
   * do a setenv OBJCOPT -builtinfunction __builtin_foo
   * (and please let me know)
   */

#ifdef NSTDARG
  [self notImplemented];
#else
  OC_VA_START (vp, nArgs);
  while (nArgs-- > 0)
    {
      id anObject = OC_VA_ARG (vp, id);
      [newObject add:anObject];
    }
  OC_VA_END (vp);
#endif

  return newObject;
}

+ with:firstObject with:nextObject
{
  return [[[self new] add:firstObject] add:nextObject];
}

+ add:firstObject
{
  return [[self new] add:firstObject];
}

/*****************************************************************************
 *
 * Testing Contents
 *
 ****************************************************************************/

- (BOOL) includesAllOf:aCltn
{
  if (self == aCltn)
    {
      return YES;
    }
  else
    {
      BOOL res = YES;
      id e, seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  if (![self includes:e])
	    {
	      res = NO;
	      goto done;
	    }
	}
    done:
#ifndef OBJC_REFCNT
      [seq free];
#endif
      return res;
    }
}

- (BOOL) includesAnyOf:aCltn
{
  if (self == aCltn)
    {
      return YES;
    }
  else
    {
      BOOL res = NO;
      id e, seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  if ([self includes:e])
	    {
	      res = YES;
	      goto done;
	    }
	}
    done:
#ifndef OBJC_REFCNT
      [seq free];
#endif
      return res;
    }
}

/*****************************************************************************
 *
 * Adding and Removing Contents
 *
 ****************************************************************************/

- addAll:aCltn
{
  if (self == aCltn)
    {
      [self addYourself];
    }
  else
    {
      id e, seq;

      seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  [self add:e];
	}
#ifndef OBJC_REFCNT
      seq = [seq free];
#endif
    }

  return self;
}

- addContentsOf:aCltn
{
  return [self addAll:aCltn];
}

- addContentsTo:aCltn
{
  return [aCltn addAll:self];
}

- removeAll:aCltn
{
  if (self == aCltn)
    {
      [self emptyYourself];
    }
  else
    {
      id e, seq;

      seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  [self remove:e];
	}
#ifndef OBJC_REFCNT
      seq = [seq free];
#endif
    }

  return self;
}

- removeContentsFrom:aCltn
{
  return [aCltn removeAll:self];
}

- removeContentsOf:aCltn
{
  return [self removeAll:aCltn];
}

/*****************************************************************************
 *
 * Combining
 *
 ****************************************************************************/

- intersection:bag
{
  if (self == bag)
    {
      return [self copy];
    }
  else
    {
      id anElement, elements;
      id intersection = [isa new];

      elements = [self eachElement];
      while ((anElement = [elements next]))
	{
	  if ([bag find:anElement])
	    [intersection add:anElement];
	}
#ifndef OBJC_REFCNT
      elements = [elements free];
#endif

      return intersection;
    }
}

- union:bag
{
  if (self == bag)
    {
      return [self copy];
    }
  else
    {
      return [[self copy] addAll:bag];
    }
}

- difference:bag
{
  if (self == bag)
    {
      return [isa new];
    }
  else
    {
      return [[self copy] removeAll:bag];
    }
}

/*****************************************************************************
 *
 * Converting to different type of collection.
 *
 ****************************************************************************/

- asSet
{
  /* Stepstone isKindOf takes a id but class returns SHR */
  if ([self isKindOf:(id) [Set class]])
    {
      return self;
    }
  else
    {
      return [[Set new] addAll:self];
    }
}

- asOrdCltn
{
  /* Stepstone isKindOf takes a id but class returns SHR */
  if ([self isKindOf:(id) [OrdCltn class]])
    {
      return self;
    }
  else
    {
      return [[OrdCltn new] addAll:self];
    }
}

/*****************************************************************************
 *
 * Block methods
 *
 ****************************************************************************/

#if OBJC_BLOCKS
- detect:aBlock
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (([aBlock value:e]))
	{
#ifndef OBJC_REFCNT
	  seq = [seq free];
#endif
	  return e;
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return nil;
}

- detect:aBlock ifNone:noneBlock
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (([aBlock value:e]))
	{
#ifndef OBJC_REFCNT
	  seq = [seq free];
#endif
	  return e;
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return [noneBlock value];
}

- select:testBlock
{
  id e, seq;
  id newObject = [isa new];

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (([testBlock value:e]))
	{
	  [newObject add:e];
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return newObject;
}

- reject:testBlock
{
  id e, seq;
  id newObject = [isa new];

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (!([testBlock value:e]))
	{
	  [newObject add:e];
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return newObject;
}

- collect:transformBlock
{
  id e, seq;
  id newObject = [isa new];

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      id anImage = [transformBlock value:e];
      if (anImage)
	{
	  [newObject add:anImage];
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return newObject;
}

- (unsigned) count:aBlock
{
  id e, seq;
  unsigned c = 0;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      if ([aBlock value:e])
	{
	  c++;
	}
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return c;
}

#endif /* OBJC_BLOCKS */

/*****************************************************************************
 *
 * Making elements perform actions.
 *
 ****************************************************************************/

- elementsPerform:(SEL)aSelector
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}

- elementsPerform:(SEL)aSelector with:anObject
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector with:anObject];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}

- elementsPerform:(SEL)aSelector with:anObject with:otherObject
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector with:anObject with:otherObject];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}

- elementsPerform:(SEL)aSelector with:anObject with:otherObject with:thirdObj
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector with:anObject with:otherObject with:thirdObj];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}
/*****************************************************************************
 *
 * Do Blocks
 *
 ****************************************************************************/

#if OBJC_BLOCKS
- do:aBlock
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      [aBlock value:e];
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return self;
}
- do:aBlock until:(BOOL*)flag
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      [aBlock value:e];
      if (*flag)
	break;
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return self;
}
#endif /* OBJC_BLOCKS */

@end
 
