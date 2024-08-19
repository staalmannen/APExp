
/*
 * Portable Object Compiler (c) 1998,2023.  All Rights Reserved.
 * $Id: Message.h,v 1.2 2023/02/19 17:00:50 stes Exp $
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

#ifndef __MESSAG_H__
#define __MESSAG_H__

#ifdef __PORTABLE_OBJC__

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include "Object.h"		/* Stepstone Object.h assumes #import */
#endif

@interface Message : Object
{
  SEL selector;
  ARGIMP dispatch;
  void *args;
}

+ selector:(SEL)s dispatch:(ARGIMP)d args:(void *)a;

- (SEL) selector;

- sentTo:receiver;
@end

#endif /* __PORTABLE_OBJC__ */

#endif /* __MESSAG_H__ */
 
