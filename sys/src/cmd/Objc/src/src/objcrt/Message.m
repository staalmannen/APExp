
/*
 * Portable Object Compiler (c) 1998,2023.  All Rights Reserved.
 * $Id: Message.m,v 1.3 2023/02/19 17:00:57 stes Exp $
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

#ifdef __PORTABLE_OBJC__

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include "Object.h"		/* Stepstone Object.h assumes #import */
#endif

#include "Message.h"

@implementation Message

/*****************************************************************************
 *
 * Creating Messages
 *
 ****************************************************************************/

- selector:(SEL)s dispatch:(ARGIMP)d args:(void*)a
{
  selector = s;
  args = a;
  dispatch = d;
  return self;
}

+ new
{
  return [self shouldNotImplement];
}

+ selector:(SEL)s dispatch:(ARGIMP)d args:(void *)a
{
  return [[super new] selector:s dispatch:d args:a];
}

/*****************************************************************************
 *
 * Querying 
 *
 ****************************************************************************/

- (SEL) selector
{
  return selector;
}

- printOn:(IOD)anIod
{
  fprintf (anIod, "#%s", selector);
  return self;
}

/*****************************************************************************
 *
 * Sending 
 *
 ****************************************************************************/

- sentTo:receiver
{
  (*dispatch) (receiver, selector, args);
  return self;
}

@end

#endif /* __PORTABLE_OBJC__ */
 
