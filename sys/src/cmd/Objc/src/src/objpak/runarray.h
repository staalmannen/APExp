
/*
 * Portable Object Compiler (c) 1997,98,99,03.  All Rights Reserved.
 * $Id: runarray.h,v 1.4 2020/04/16 19:16:08 stes Exp $
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

#ifndef __RUNARY_H__
#define __RUNARY_H__

#include "cltn.h"

@interface RunArray : Cltn
{
  id runs;
  id values;
  unsigned size;
  int laststart;
  int lastend;
  int lastsegment;
}

- reset;
- check;
+ new;
- free;

- values;
- runs;
- runs:r values:v;
- at:(unsigned)i;
- (unsigned) runLengthAt:(unsigned)i;
- (unsigned) size;
- calcsize;
- setsize:(unsigned)newsize;
- addAttribute:attrib to:v;
- breakat:(int)i;
- addAttribute:attrib from:(unsigned)p size:(unsigned)s;
- calcinsertsegment:(int)i;
- at:(unsigned)anOffset insert:(char*)aString count:(int)n;
- deleteFrom:(unsigned)p to:(unsigned)q;
- concat:b;
- coalesce;

- printOn:(IOD)aFile;
@end

#endif /* __RUNARY_H__ */
 
