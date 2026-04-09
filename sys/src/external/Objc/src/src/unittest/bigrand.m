
/*
 * Copyright (c) 2000 David Stes.
 *
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

#include <assert.h>
#include <stdlib.h>
#include <ocstring.h>
#include "bigrand.h"
#include "galfield.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void biginthex(id c)
{
  int n = [c numDigits];
  while (n--) { printf("%04x",[c digitAt:n]); }
}

id bigintu16(int dim,unsigned *p)
{
   int i;
   id r = [BigInt new];

   if (sizeof(DIGIT) == 2) {
     for(i=0;i<dim;i++) {
        [r insertDigit:p[i]];     
     }
   } else {
     [r notImplemented];
   }

   return r;
}

id bigintrandom(int numdigits)
{
  int i;
  id d = [BigInt new];

  for(i=0;i<numdigits;i++) {
     DIGIT l;
     do { l = (DIGIT)random(); } while (l==0);
     [d insertDigit:l];
  }

  return d;
}

id bigint2string(id value)
{
  id s;
  int i,n;
  char buf[2];
  DIGIT d,d1;

  assert(sizeof(DIGIT) == 2 * sizeof(char));

  s = [String new:sizeof(DIGIT) * [value numDigits]];
  for(i=0,n=[value numDigits];i<n;i++) {
     d = [value digitAt:i];
     d1 = d >> 8;
     buf[0] = d1; 
     buf[1] = d - (d1 << 8); 
     [s at:0 insert:buf count:2];
  }

  return s;
}

id string2bigint(id aString)
{
    int i,n;
    id e = [BigInt new];
    n = [aString size];
    for(i=0;i<n;i++) {
      DIGIT d = [aString charAt:i];
      if (i == 0 && d == 0) {
         [aString error:"First byte of data must be non-zero"];
      }
      e = [[e multiplyDigit:256] addDigit:d]; 
    }
    [e insertDigit:0];
    return e;
}

void seedrandomgen(char *randomsource)
{
  int fd;

  if ((fd = open(randomsource,O_RDONLY))) {
     unsigned int seed;
     if (sizeof(seed) == read(fd,&seed,sizeof(seed))) {
       srandom(seed);
     } else {
       perror("read /dev/random");
     }
  } else {
    perror("open /dev/random");
  }
  close(fd);
}

id randompolynomial(id p)
{
  id s;
  id w;
  int i;
  id termw;
  id r = [p empty];
  w = [[p termZero] symbol];
  s = [[p termZero] coefficient]; 
  for(i=0;i<[p degree];i++) {
    id u = [s random];
    termw = [Term scalar:u symbol:w exponent:i];
    [r insertTerm:termw];
  }

  return r;
}

