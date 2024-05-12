
/*
 * Portable Object Compiler (c) 1997,2023.  All Rights Reserved.
 * $Id: Object.m,v 1.9 2023/02/19 17:15:56 stes Exp $
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

#ifndef __PORTABLE_OBJC__
#else

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include "Object.h"		/* Stepstone Object.h assumes #import */
#endif

#include "Block.h"		/* ifError: stuff */
#include "Message.h"		/* doesNotUnderstand: stuff */

@implementation Object
/*****************************************************************************
 *
 * Factory Initialization
 *
 ****************************************************************************/

+ initialize
{
  return self;
}

- initialize
{
  return self;
}

/*****************************************************************************
 *
 * Creating, Copying and Freeing
 *
 ****************************************************************************/


- str:(STR)s
{
  return [self shouldNotImplement];	/* dummy def. Stepstn */
}

+ new
{
  id newObject = (*_alloc) (self, 0);
  return newObject;
}

- new
{
  return [self shouldNotImplement];
}

- increfs
{
  return nil;
}

- copy
{
  id newObject = (*_copy) (self, 0);
  [newObject increfs];
  return newObject;
}

- deepCopy
{
  id newObject = (*_copy) (self, 0);
  [newObject increfs];
  return newObject;
}

- free
{
#ifdef OBJC_REFCNT
  return [self shouldNotImplement];	/* mixing the two models is a pain */
#else
  isa = nil;
  return (_dealloc) ? (*_dealloc) (self) : nil;
#endif
}

- decrefs
{
  return nil;
}

- release
{
#ifndef OBJC_REFCNT
  return [self shouldNotImplement];	/* mixing the two models is a pain */
#else
  [self decrefs];
  return (*_dealloc) (self);
#endif
}

+ free
{
  return nil;
}

+ release
{
  return nil;
}

/*****************************************************************************
 *
 * Identity
 *
 ****************************************************************************/


- self
{
  return self;
}

- yourself
{
  return self;
}

- class
{
  return [isa class];
}
- superclass
{
  return [isa superclass];
}
- superClass
{
  return [isa superClass];
}

+ class
{
  return self;
}

+ superclass
{
  return getcls (self)->clsSuper;
}

+ superClass
{
  return getcls (self)->clsSuper;
}

- add:anObject
{
  return [self shouldNotImplement];	/* mmh */
}

- (STR) name
{
  return [isa name];
}

+ (STR) name
{
  return getcls (self)->clsName;
}

- findClass:(STR)name
{
  return (*_cvtToId) (name);
}

- (SEL) findSel:(STR)name
{

  return (*_cvtToSel) (name);
}

- (SEL) selOfSTR:(STR)name
{
  SEL aSel = [self findSel:name];
  if (aSel)
    {
      return aSel;
    }
  else
    {
      [self error:"Selector not found in selector table."];
      return NULL;
    }
}

- idOfSTR:(STR)aClassName
{
  id aClass = [self findClass:aClassName];
  if (aClass)
    {
      return aClass;
    }
  else
    {
      return [self error:"Class not linked in application."];
    }
}

/*****************************************************************************
 *
 * Comparing
 *
 ****************************************************************************/


- (unsigned) hash
{
  /* MIPSpro 64bit : cast a size_t to unsigned and avoid a warning
     * it is not incorrect for |hash| to ignore the upper 32bit
   */

  return (unsigned) (self - nil);
}

- (BOOL) isEqual:anObject
{
  return (BOOL) (anObject == self);
}

- (STR) str
{
  return [isa name];
}

- (unsigned) size
{
  return 0;
}

+ (BOOL) isEqual:anObject
{
  return (BOOL) (self == anObject);
}

- (BOOL) isSame:anObject
{
  return (BOOL) (self == anObject);
}

- (BOOL) notEqual:anObject
{
  return [self isEqual:anObject] == NO;
}

- (BOOL) notSame:anObject
{
  return (BOOL) ! [self isSame:anObject];
}

- (int) compare:anObject
{
  [self notImplemented];
  return 0;
}

- (int) invertCompare:anObject
{
  int cmp = [self compare:anObject];
  return cmp ? -cmp : 0;
}

/*****************************************************************************
 *
 * Class and Methods
 *
 ****************************************************************************/


- (BOOL) respondsTo:(SEL)aSelector
{
  Cls_t cls;
  unsigned n;
  id ncls = isa;
  struct objcrt_slt *smt;

  do
    {
      cls = getcls (ncls);
      for (smt = cls->clsDispTable, n = cls->clsSizDict; n--; smt++)
	{
	  /* selectors can be compared with == */
	  if (smt->_cmd == aSelector)
	    return YES;
	}
    }
  while ((ncls = cls->clsSuper));

  return NO;
}

- (BOOL) isMemberOf:aClass
{
  return (BOOL) (isa == aClass);
}

- (BOOL) isKindOf:aClass
{
  id ncls = isa;
  Cls_t cls = getcls (isa);

  for (; ncls; (ncls = cls->clsSuper))
    {
      cls = getcls (ncls);
      if (ncls == aClass)
	return YES;
    }

  return NO;
}
/*****************************************************************************
 *
 * Object Tables
 *
 ****************************************************************************/

+ someInstance
{
#if OTBCRT
  return self->nextinst;
#else
  return [self shouldNotImplement];
#endif
}

- nextInstance
{
#if OTBCRT
  return self->nextinst;
#else
  return [self shouldNotImplement];
#endif
}

- become:other
{
#if OTBCRT
  struct OTB *fake = (struct OTB *) self;
  struct _PRIVATE *temp = fake->ptr;
  fake->ptr = other->ptr;
  other->ptr = temp;
  return self;
#else
  return [self shouldNotImplement];
#endif
}

+ become:other
{
#if OTBCRT
  return swapclass (self, other);
#else
  return [self shouldNotImplement];
#endif
}

/*****************************************************************************
 *
 * Class Management
 *
 ****************************************************************************/

+ subclasses
{
  id c = [[Object idOfSTR:"OrdCltn"] new];
  addSubclassesTo (c, [self name]);
  return c;
}
+ poseAs:superClass
{
  poseAs ((self), (superClass));
  return self;
}

+ addMethodsTo:superClass
{
  addMethods (self, superClass);
  return self;
}

+ subclass:(STR)name
{
  return [self subclass:name:0:0];
}

+ subclass:(STR)name:(int)ivars:(int)cvars
{
  return newsubclass (name, self, ivars, cvars);
}

+ load
{
  linkclass (self);
  return self;
}

+ unload
{
  unlinkclass (self);
  return nil;
}

static BOOL 
inherits (Cls_t aCls, STR name)
{
  id ncls = aCls->clsSuper;

  while (ncls)
    {
      Cls_t cls = getcls (ncls);
      if (strcmp (cls->clsName, name) == 0)
	return YES;
      ncls = cls->clsSuper;
    }

  return NO;
}

+ (BOOL) inheritsFrom:aClass
{
  return inherits (getcls (self), (STR) [aClass name]);
}

+ (BOOL) isSubclassOf:aClass
{
  return [self inheritsFrom:aClass];
}

/*****************************************************************************
 *
 * Error Handling
 *
 ****************************************************************************/


- subclassResponsibility
{
  return [self error:"Subclass should have implemented one of my methods."];
}

- subclassResponsibility:(SEL)aSelector
{
  return [self subclassResponsibility];
}

- notImplemented
{
  return [self error:"Does not implement this message."];
}


- notImplemented:(SEL)aSelector
{
  return [self notImplemented];
}

- shouldNotImplement
{
  return [self error:"Message is not appropriate for this class."];
}

- shouldNotImplement:(SEL)aSelector
{
  return [self shouldNotImplement];
}

- shouldNotImplement:(SEL)aSelector from:superClass
{
  return [self shouldNotImplement];
}

- vsprintf:(STR)format:(OC_VA_LIST *)ap
{
  return [self shouldNotImplement];
}

- error:(STR)format,...
{
  OC_VA_LIST ap;
  static id MsgClass;
  if (!MsgClass)
    MsgClass = [self findClass:"String"];

  /* use OC macros here for porting to SunOS4 */

  OC_VA_START (ap, format);
  if (MsgClass)
    {
      [self halt:[MsgClass vsprintf:format:&ap]];
    }
  else
    {
      (*_error) (self, format, ap);
    }
  OC_VA_END (ap);

  return self;
}

- halt:message
{
  [Block halt:message value:self];
  return self;
}


/*****************************************************************************
 *
 * Unknown Messages
 *
 ****************************************************************************/


- doesNotRecognize:(SEL)aSelector
{
  return [self error:"Message not recognized by this class."];
}
- doesNotUnderstand:aMessage
{
  return [self doesNotRecognize:[aMessage selector]];
}

/*****************************************************************************
 *
 * Method Implemenation Lookup
 *
 ****************************************************************************/


- (IMP) methodFor:(SEL)aSelector
{
  return _imp (self, aSelector);
}

+ (IMP) instanceMethodFor:(SEL)aSelector
{
  return _impSuper (self, aSelector);
}

/*****************************************************************************
 *
 * Method Performing
 *
 ****************************************************************************/


- perform:(SEL)aSelector
{
  return (*fwdimp (self, aSelector, selptrfwd)) (self, aSelector);
}

- perform:(SEL)aSelector with:anObject
{
  /* the usual all C cast */
  return (*fwdimp (self, aSelector, selptrfwd)) (self, aSelector, anObject);
}

- perform:(SEL)aSelector with:anObject with:otherObject
{
  /* the usual all C cast */
  return (*fwdimp (self, aSelector, selptrfwd)) (self, aSelector, anObject, otherObject);
}

- perform:(SEL)aSelector with:anObject with:otherObject with:thirdObj
{
  /* the usual all C cast */
  return (*fwdimp (self, aSelector, selptrfwd)) (self, aSelector, anObject, otherObject, thirdObj);
}
/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- print
{
  return [self printOn:stdout];
}

+ print
{
  printf ("%s", [self name]);
  return self;
}


- printLine
{
  [self print];
  printf ("\n");
  return self;
}

- show
{
  (*_showOn) (self, 0);
  return self;
}

- printToFile:(FILE *)aFile
{
  /* THIS METHOD WILL GO AWAY ! */

  /* it used to be precisely the opposite -- printOn was defined
   * in terms of our printToFile, but we decided against this
   * invention of ourselves (other runtimes don't have printToFile)
   * because subclasses sometimes already override printOn:
   * (cfr. Stepstone runtime)
   */

  return [self printOn:aFile];
}

- printOn:(IOD)anIOD
{
  return self;
}

/*****************************************************************************
 *
 * Version
 *
 ****************************************************************************/

+ (STR) objcrtRevision
{
  return __objcrt_revision__;
}

/*****************************************************************************
 *
 * AsciiFiler Methods for Object Class
 *
 ****************************************************************************/

+ readFrom:(STR)aFileName
{
  return (*_readFrom) (aFileName);
}
- (BOOL) storeOn:(STR)aFileName
{
  return (*_storeOn) (aFileName, self);
}
/*****************************************************************************
 *
 * AsciiFiler Methods for Object Class
 *
 ****************************************************************************/

- fileOutIdsFor:aFiler
{
  return self;			/* compiler generated normally */
}

- fileInIdsFrom:aFiler
{
  return self;			/* compiler generated normally */
}

- fileOutIdsFor
{
  return self;			/* compiler generated normally */
}

- fileInIdsFrom
{
  return self;			/* compiler generated normally */
}

- fileOutOn:aFiler
{
  [aFiler fileOut:&isa type:'#'];
  return [self fileOutIdsFor:aFiler];
}
+ fileInFrom:aFiler
{
  id newObject = (*_alloc) (self, 0);
  return [newObject fileInFrom:aFiler];
}

- fileInFrom:aFiler
{
  return [self fileInIdsFrom:aFiler];
}
- fileOut:(void *)value type:(char)typeDesc
{
  return [self subclassResponsibility];
}

- fileIn:(void *)value type:(char)typeDesc
{
  return [self subclassResponsibility];
}

- awake
{
  return self;
}

- awakeFrom:aFiler
{
  return [self awake];
}


@end

#endif /* __PORTABLE_OBJC__ */
 
