
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

#include "galfield.h"
#include "legendre.h"
#include "shanks.h"
#include "bezout.h"
#include "zashaus.h"
#include "bigrand.h"

#include <ordcltn.h>
#include <ocstring.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

@implementation GaloisField

/* irreducible polynomials to construct quotientfield representation */

int p47n2[] = {1,0,1};			 /* 1 + w^2 */
int p47n3[] = {46, 3, 13, 1};
int p47n4[] = {1, 46, 1, 46, 1};
int p47n5[] = {21, 46, 39, 7, 4, 1};
int p47n6[] = {1, 1, 0, 0, 0, 0, 1};
int p47n13[] = {46, 0, 39, 26, 22, 8, 29, 41, 1, 21, 2, 46, 19, 1};
int p47n20[] = 
   { 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 46, 0, 0, 0, 0, 36, 0, 0, 0, 0, 1};
int p47n23[] =
   {37, 38, 18, 22, 18, 37, 13, 41, 43, 12, 8, 29, 22, 1, 16, 45, 14, 
   15, 9, 25, 16, 15, 8, 1};
int p47n31[] = 
   {37, 28, 43, 25, 27, 18, 6, 9, 41, 19, 23, 14, 23, 17, 5, 20, 21, 
    18, 7, 40, 29, 19, 40, 0, 25, 20, 42, 36, 37, 46, 7, 1};
int p47n33[] = 
   {46, 5, 8, 26, 0, 44, 12, 13, 22, 27, 4, 9, 10, 40, 25, 12, 38, 3, 
    22, 30, 15, 43, 21, 32, 26, 30, 45, 41, 0, 33, 35, 39, 6, 1};
int p47n42[] = 
   {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1};
int p47n47[] = 
   {1, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 1};
int p47n61[] =
   {1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
int p47n66[] =
   {1, 5, 33, 2, 28, 24, 9, 46, 40, 27, 33, 2, 33, 24, 3, 2, 27, 9, 17, 
    12, 14, 21, 13, 5, 7, 24, 28, 38, 5, 35, 43, 5, 40, 17, 18, 35, 35, 24, 
    35, 44, 23, 31, 8, 19, 14, 6, 36, 8, 35, 37, 42, 28, 34, 33, 1, 0, 23, 
    0, 0, 11, 20, 18, 9, 24, 44, 41, 1};
int p47n99[] =
   {46, 26, 4, 13, 1, 35, 3, 11, 24, 15, 5, 5, 45, 18, 37, 0, 28, 16, 
    44, 12, 6, 45, 39, 31, 15, 11, 1, 41, 25, 28, 37, 43, 31, 10, 44, 31, 
    30, 38, 14, 33, 18, 17, 44, 42, 42, 3, 10, 46, 0, 43, 40, 31, 45, 3, 43, 
    43, 14, 44, 35, 20, 13, 18, 28, 9, 10, 33, 20, 20, 37, 21, 29, 29, 38, 
    28, 2, 18, 31, 25, 34, 4, 34, 0, 41, 23, 18, 5, 29, 9, 29, 8, 21, 0, 2, 
    10, 2, 44, 33, 2, 27, 1};
int p47n312[] =
   {1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,
    1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,
    46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,
    1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,
    46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,
    1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,
    46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,
    1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,
    46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,
    1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,
    46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1};

int p7n10[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int p7n30[] =
    {4, 0, 0, 1, 0, 0, 2, 0, 0, 4, 0, 0, 1, 0, 0, 2, 0, 0, 4, 0, 0, 1, 0, 
     0, 2, 0, 0, 4, 0, 0, 1};
int p7n74[] = 
    {1, 6, 5, 3, 1, 3, 0, 0, 0, 3, 1, 4, 2, 2, 3, 0, 0, 2, 3, 5, 1, 1, 
     4, 6, 1, 3, 0, 5, 4, 1, 6, 4, 5, 4, 0, 4, 4, 3, 4, 4, 0, 4, 5, 4, 6, 1, 
     4, 5, 0, 3, 1, 6, 4, 1, 1, 5, 3, 2, 0, 0, 3, 2, 2, 4, 1, 3, 0, 0, 0, 3, 
     1, 3, 5, 6, 1};
int p7n99[] = 
    {6, 4, 1, 1, 4, 3, 6, 2, 5, 6, 0, 4, 6, 3, 1, 6, 3, 5, 6, 1, 4, 4, 4, 
     2, 5, 3, 3, 1, 0, 1, 4, 3, 0, 0, 1, 6, 4, 5, 4, 5, 6, 6, 2, 0, 3, 5, 6, 
     4, 2, 5, 0, 0, 3, 3, 5, 0, 6, 2, 0, 1, 1, 2, 2, 5, 0, 1, 6, 6, 3, 0, 2, 
     2, 0, 4, 2, 1, 2, 0, 3, 3, 4, 5, 5, 5, 4, 4, 4, 3, 0, 5, 3, 4, 4, 3, 4, 
     6, 4, 1, 5, 1};
int p7n116[] =
   {1, 6, 0, 1, 6, 2, 6, 1, 0, 1, 2, 3, 6, 5, 3, 4, 2, 1, 5, 6, 1, 3, 
    1, 4, 2, 3, 0, 4, 3, 2, 5, 0, 4, 3, 3, 5, 5, 1, 4, 0, 3, 6, 0, 1, 2, 5, 
    6, 4, 3, 5, 1, 6, 3, 5, 1, 1, 3, 0, 1, 0, 3, 1, 1, 5, 3, 6, 1, 5, 3, 4, 
    6, 5, 2, 1, 0, 6, 3, 0, 4, 1, 5, 5, 3, 3, 4, 0, 5, 2, 3, 4, 0, 3, 2, 4, 
    1, 3, 1, 6, 5, 1, 2, 4, 3, 5, 6, 3, 2, 1, 0, 1, 6, 2, 6, 1, 0, 6, 1};
int p7n178[] = 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int p2n113[] = {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
int p2n163[] = {1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
int p46337n2[] = {1,1,1};
int p46337n6[] = {1,0,0,1,0,0,1};
int p46337n18[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int p46337n78[] =
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     1,1,1,1,1,1,1};

- (BOOL)inField
{
  return YES;
}

- cardinality
{
  return cardinality;
}

- w
{
  id w;
  id termw;
  w = [modulus empty];
  termw = [Term scalar:[scalarzero one] symbol:[Symbol str:"w"] exponent:1];
  [w insertTerm:termw];
  return [[super copy] value:w];
}

- findnonsquare
{
  id e,i,n;
  n = [self cardinality];
  for(i=[[self w] asBigInt];[i notEqual:n];i=[i increment]) {
    e = [self embed:i];
    if (![e isSquare]) { nonsquare = [e value];break; }
  }
  return self;
}

- calcfrobtab
{
  id w = [self w]; 
  frobtab = PolynomialModularFrobeniusTable([w value],characteristic,modulus);
  return self;
}

- (int)characteristic
{
  return characteristic;
}

- (int)degree
{
   return degree;
}

- characteristic:(int)p degree:(int)n
{
  id w;
  int i,*r;
  id termw;

  r = NULL;

  if (p == 2) { 
    if (n == 113) r = p2n113;
    if (n == 163) r = p2n163;
  } else if (p == 47) { 
    if (n == 2) r = p47n2;
    if (n == 3) r = p47n3;
    if (n == 4) r = p47n4;
    if (n == 5) r = p47n5;
    if (n == 6) r = p47n6;
    if (n == 13) r = p47n13;
    if (n == 20) r = p47n20;
    if (n == 23) r = p47n23;
    if (n == 31) r = p47n31;
    if (n == 33) r = p47n33;
    if (n == 42) r = p47n42;
    if (n == 47) r = p47n47;
    if (n == 61) r = p47n61;
    if (n == 66) r = p47n66;
    if (n == 99) r = p47n99;
    if (n == 312) r = p47n312;
  } else if (p == 46337) {
    if (n == 2) r = p46337n2;
    if (n == 6) r = p46337n6;
    if (n == 18) r = p46337n18;
    if (n == 78) r = p46337n78;
  } else if (p == 7) {
    if (n == 10) r = p7n10;
    if (n == 30) r = p7n30;
    if (n == 74) r = p7n74;
    if (n == 99) r = p7n99;
    if (n == 116) r = p7n116;
    if (n == 178) r = p7n178;
  } else {
    [self error:"unsupported characteristic finite field"];
  }

  if (!r) [self error:"unsupported degree finite field"];

  w = [Symbol str:"w"];
  scalarzero = [IntegerModp modulus:p];
  modulus = [Polynomial scalar:scalarzero];

  for(i=0;i<=n;i++) {
    if (r[i]) {
      termw = [Term scalar:[scalarzero intValue:r[i]] symbol:w exponent:i];
      [modulus insertTerm:termw];
    }
  }
  
  modulus = [modulus makeVariableDense];

  if (n < 200) {
    modulus = [modulus makeDegreeDense];
  }

  value = [modulus zero];
  degree = n;
  characteristic = p;
  cardinality = [[BigInt int:p] power:n];

  return self;
}

+ characteristic:(int)p degree:(int)n
{
  return [[super new] characteristic:p degree:n];
}

- asBigInt
{
  id t,b,v;
  id terms = [value eachTerm];
  b = [BigInt new];
  if (characteristic==0) [self error:"characteristic should be non-zero"];
  v = [b intValue:characteristic];
  while ((t=[terms next])) {
    int d = [[t coefficient] intValue];
    b = [b add:[[v power:[t exponent]] multiplyIntValue:d]];
  }
  return b;
}

id gfu16(id zero,int dim,unsigned *p)
{
  id t = bigintu16(dim,p);return [zero embed:t];
}

- embed:aBigInt
{
  id v;
  id w;
  id b;
  w = [[self w] value];
  v = [modulus empty];
  b = [modulus one];
  while ([aBigInt notZero]) {
    DIGIT rem;
    aBigInt = [aBigInt quotientDigit:characteristic remainder:&rem];
    v = [v add:[b multiplyIntValue:rem]];
    b = [b multiply:w];
  }
  if ([v degree] < [modulus degree]) {
    return [[self copy] value:v];
  } else {
    return [self error:"modulus too small to embed data"];
  }
}

- frobenius
{
  id f = PolynomialModularFrobenius(value,modulus,frobtab);
  return [[super copy] value:f];
}

- norm
{
  id n = ModularFrobeniusNorm(value,degree,modulus,frobtab);
  return [[super copy] value:n];
}

- trace
{
  id n = ModularFrobeniusTrace(value,degree,modulus,frobtab);
  return [[super copy] value:n];
}

- (BOOL)isSquare
{
  id v,p,n;
  if ([self isZero] || [self isOne]) return YES;
  p = [BigInt int:characteristic];
  n = [self norm];
  v = [n asBigInt];
  return legendre(v,p) >= 0; /* zero or +1 */
}

- squareRootShanks
{
  if (!nonsquare) [self error:"nonsquare"];
  return [[super copy] value:shanks(value,modulus,cardinality,nonsquare)]; 
}

- squareRootZassenhaus
{
  id factors;
  id S,X,Q,t;
  id z,qfrobtable;

  S = [Symbol str:"W"];

  z = [self zero];
  X = [Polynomial scalar:z];
  t = [Term scalar:[self one] symbol:S exponent:1];
  [X insertTerm:t];
  X = [X makeVariableDense];

  Q = [Polynomial scalar:z];
  t = [Term scalar:[self one] symbol:S exponent:2];
  [Q insertTerm:t];
  t = [Term scalar:[self negate] symbol:S exponent:0];
  [Q insertTerm:t];
  Q = [Q makeVariableDense];

  qfrobtable = PolynomialModularFrobeniusTable(X,characteristic,Q);
  
  // norm is a square, so Q is product of linear factors (d=1) over Fq 
  // degree of Fq over Fp is 'degree' (mu=degree)

  factors = [OrdCltn new];
  factors = SeparateFactors(factors,Q,1,characteristic,degree,qfrobtable);
  
  if ([factors size] == 2 && [ (z = [factors at:0]) isMonic]) {
    [z removeTerm];
    return [z asCoefficient];
  } else {
    [self printLine];
    [factors printLine];
    return [self error:"square root algorithm failed"];
  }
}

- squareRoot
{
  BOOL z = YES;
  if ([self isOne]) return self;
  if ([self isZero]) return self;
  return (z)?[self squareRootZassenhaus]:[self squareRootShanks];
}

- random
{
  id w;
  int i;
  id termw;
  id r = [value empty];

  w = [Symbol str:"w"];
  for(i=0;i<[modulus degree];i++) {
    int u;
    do { u = random(); } while ((u%characteristic) != 0);
    termw = [Term scalar:[scalarzero intValue:u] symbol:w exponent:i];
    [r insertTerm:termw];
  }

  return [[super copy] value:[r modulo:modulus]];
}

- (BOOL)printsLeadingSign
{
  return [value printsLeadingSign];
}

- (BOOL)printsProduct
{
  return [value printsProduct];
}

- (BOOL)printsSum
{
  return [value printsSum];
}

- printOn:(IOD)d
{
  [value printOn:d];
  return self;
}

- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  [aFiler fileOut:&degree type:'i'];
  [aFiler fileOut:&characteristic type:'i'];
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  [aFiler fileIn:&degree type:'i'];
  [aFiler fileIn:&characteristic type:'i'];
  return self;
}

@end

