
/*
 * Computer Algebra Kit (c) 1993,1994,2000 by David Stes.  All Rights Reserved.
 *
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
 *
 * $Id: zashaus.m,v 1.1 2025/06/09 10:28:18 stes Exp $
 *
 */

#include "zashaus.h"
#include "bigrand.h"
#include <ordcltn.h>
#include <stack.h>
#include <assert.h>
#include <limits.h>

/******************************************************************************
 * 
 * Modular Frobenius A-> A^p mod B.  This operation is important in the
 * polynomial factorization over finite fields.
 *
 * The process is speeded (sped?) up by keeping a table of powers in a List
 * object : 1,x^p mod B,x^p^2 mod B,x^p^3 mod B ...
 *
 * Computing this table of modular powers is expensive, hence in the
 * frobenius:modulo: method we assume that it is computed for a *multiple* of
 * the modulus, so that if the table is computed for some polynomial P, it
 * can be reused for divisors Q of P (instead of recomputing the table for Q).
 *
 * History :
 * 	may 31,94, stes - moved from finfieldfactor to this place
 *      jun 30,94 - stes - back to finfieldfactor !
 *
 *****************************************************************************/

id PolynomialModularFrobeniusTable(id x,int p,id P)
{
    int n;
    id E,table,frobx;
    assert(p > 0 && p != INT_MAX);
    
    n = [P degree];assert(n > 1);
    table = [OrdCltn new:n];
    
    frobx = [x power:p modulo:P];
    
    [table add:[P one]];
    [table add:frobx];
    
    n-=2;
    E = frobx;
    while(n--) {
	E = [E multiply:frobx modulo:P];
	[table add:E];
    }
    
    return table;
}

/******************************************************************************
 *
 * frob(Q) mod P := Q^p mod P = Sum(frob(ai) * (X^i*p mod P))
 *
 * table is a table of powers of 'x' modulo a multiple of P, ie. the degree of
 * the result is not necessary < deg(P).  This explains the modulo at the end.
 *
 * History :
 * 	may 31,94, stes - moved from finfieldfactor to this place
 * 	                - merged separate add/scalarmul into add:scalarMul
 *      jun 30,94 - stes - back to finfieldfactor !
 *
 *****************************************************************************/

id PolynomialModularFrobenius(id a,id m,id frobtable)
{
    int e;
    id ix,c,r,t;
    
    r  = [a zero];
    ix = [a eachTerm];
    
    while ((t = [ix next])) {
	e = [t exponent];assert(0 <= e && e < [frobtable size]);
	c = [[t coefficient] frobenius];
	r = [r add:[[frobtable at:e] multiplyCoefficient:c]];
    }
    
    return [r modulo:m];
}

/******************************************************************************
 *
 * Trace of degree "d" : Q + Q^p + (Q^p)^p + ... + Q^(p^d-1) modulo P
 *
 * History :
 * 	may 31,94, stes - cleanup
 *
 *****************************************************************************/

id ModularFrobeniusTrace(id Q,int d,id P,id frobtable)
{
    int i;
    id T,F;

    F = [Q modulo:P];
    T = F;

    for(i=1;i<d;i++) {
	F = PolynomialModularFrobenius(F,P,frobtable);
	T = [T add:F];
    }
    
    return [T modulo:P];
}

/******************************************************************************
 *
 * Norm of degree "d" : Q * Q^p * (Q^p)^p * ... * Q^(p^d-1) modulo P
 *
 * History :
 * 	may 31,94, stes - cleanup
 *
 *****************************************************************************/

id ModularFrobeniusNorm(id Q,int d,id P,id frobtable)
{
    int i;
    id N,F;

    F = [Q modulo:P];
    N = F;

    for(i=1;i<d;i++) {
	F = PolynomialModularFrobenius(F,P,frobtable);
	N = [N multiply:F];
    }
    
    return [N modulo:P];
}

/******************************************************************************
 *
 * Check whether the product of the objects in "list" equals "P"
 *
 * History :
 * 	may 31,94, stes - cleanup
 *
 *****************************************************************************/

BOOL CheckPartialFactorization(id list,id P)
{
    int i;id check;BOOL res;
    check = [P one];
    for(i=0;i<[list size];i++) check = [check multiply:[list at:i]];
    res = [check isEqual:P];
    return res;
}

/******************************************************************************
 *
 * random zero divisor of algebra K[x]/P(x) where P(x) is
 *	- monic & squarefree
 *	- product of irreducible factors of same degree 'd'
 *
 * the idea is to take the frobenius trace of degree d of a random polynomial,
 * then as a trace, G satisfies G == G^p mod P, deduce a zero divisor
 * for p==2, G(G-1) == 0 mod P, for p>2 G(G^pdiv2 -1)(G^pdiv2 +1) == 0 mod P
 *
 * actually we take the trace of degree d * mu (mu being the dimension of the
 * finite field over the prime field Fp)
 *
 * History :
 * 	may 31,94, stes - cleanup
 *
 *****************************************************************************/

id RandomZeroDivisor(id P,int d,int p,int mu,id frobtable)
{
    int pdiv2;
    id  R,G,O;
    
    R = randompolynomial(P);
    G = ModularFrobeniusTrace(R,d * mu,P,frobtable);

    if (p>2) {
	pdiv2 = (p-1)/2;
	O = [P one];
	G = [[G power:pdiv2 modulo:P] subtract:O];
    }
    
    return G;
}

/******************************************************************************
 *
 * Separate (and add to list) factors of the polynomial P where P is
 *
 *	- monic & squarefree
 *	- product of irreducible factors of same degree 'd'
 *
 * This is done by taking random zero divisors in K[X]/P and computing gcd.
 * 
 * History :
 * 	may 31,94, stes - cleanup
 *
 *****************************************************************************/

id SeparateFactors(id list,id P,int d,int p,int mu,id frobtable)
{
    int dd;
    id stack,R,Q;
    
    assert(([P degree] / d) * d == [P degree]);
    Q = P;
    if (d == [P degree]) return [list add:Q];

    // keep a stack of polynomials to process
    stack = [Stack new];
    
    while (1) {
	
	R  = RandomZeroDivisor(Q,d,p,mu,frobtable);
        if ([R degree] < d) continue;
	R  = [R gcd:Q];
	dd = [R degree];
	
	if (0 < dd && dd < [Q degree]) {
	    Q = [Q divide:R];
	    if (dd == d) [list add:R]; else [stack push:R];
	    dd = [Q degree];
	    if (dd == d) [list add:Q]; else [stack push:Q];
	    if ([stack depth]) Q = [stack pop]; else break; 
	}
	
	// it's possible that frobtable is now modulo a *multiple* of Q
	// which is ok (the table is just being used to speed up frobModulo
    }
    
    return list;
}

/******************************************************************************
 *
 * Distinct degree factorization : decomposition of a square free polynomial
 * into products of irreducible factors of equal degree
 *
 * (X^(q^i) - X is product of all irreducibles of deg <= i.  So we compute
 * gcd's with that polynomial for gradually increasing "i".  We make use of
 * the fact that gcd(X^q^i - X,P) = gcd((X^q^i mod P) - X,P).  
 *
 * X^q computed through mu modular frobenius operations
 *
 * History :
 * 	may 31,94, stes - cleanup
 *
 *****************************************************************************/

id FactorDistinctDegree(id X,id P,int p,int mu)
{
    int i,j;
    id factors,table,R,S;
    #ifndef NDEBUG
    id check = [P one];
    #endif

    assert([P isMonic] && [P degree] > 0);// && [P isSquareFree]
    factors = [OrdCltn new];
    if ([P degree]==1){[factors add:P];return factors;}

    table = PolynomialModularFrobeniusTable(X,p,P);
    S = [table at:1];

    for(j=1;j<mu;j++) S = PolynomialModularFrobenius(S,P,table);
    
    for(i=1;1;i++) {
    	// attempt to separate with (X^(q^i) mod P) - X
	R = [S subtract:X];
	R = [R gcd:P];
	
	if ([R degree] > 0) {
	
	    // add factors of R to "factors"
	    SeparateFactors(factors,R,i,p,mu,table);
	    
	    if ([P isEqual:R]) { break; }

	    #ifndef NDEBUG
	    check = [check multiply:R];
	    assert(CheckPartialFactorization(factors,check));
	    #endif
	    
	    // update P
	    P = [P divide:R];
	    
	    // now, P is a product of irreducibles of degree > i
	    // or irreducible itself
	    if (i >= ([P degree] / 2)) {
		[factors add:P]; break;
	    }
	    
	    // update S and table
	    S = [S modulo:P];j = [P degree]; while (j--) {
		[table at:j put:[[table at:j] modulo:P]];
	    }
	} else {
	    
	    if (i >= ([P degree] / 2)) {
		[factors add:P]; break;
	    }
	}
    
        for(j=0;j<mu;j++) S = PolynomialModularFrobenius(S,P,table);
    }
    
    return factors;
}

