
/*
 * Portable Object Compiler (c) 2003,2023.  All Rights Reserved.
 * $Id: outofbnd.h,v 1.5 2023/03/12 16:10:57 stes Exp $
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

#ifndef __OUTOFBND_H__
#define __OUTOFBND_H__

#include "Exceptn.h"

@interface OutOfBounds : Exception
{
  unsigned size;
  unsigned offset;
}
- (unsigned) size;
- at:(unsigned)n;
+ new:(unsigned)n;
- new:(unsigned)n;
- signal;
@end

#endif /* __OUTOFBND_H__ */
 
