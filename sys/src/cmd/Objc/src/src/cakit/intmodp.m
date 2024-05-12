
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: intmodp.m,v 1.8 2001/07/09 18:38:07 stes Exp $
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

static modp_args modp_getargs(id self)
{
   modp_args args;args.p = [self modulus];return args;
}

static int modp_size(modp_args args)
{
    return 1;				/* pointer increment */
}

static int modp_bsize(modp_args args)
{
    return sizeof(modp_c);		/* bytes */
}

static modp_t modp_id2t(id object)
{
    return [object modp_value];	/* read-only */
}

static modp_t modp_id2ref(id object,modp_c *ref)
{
    return [object modp_value];	/* read-only, scratch space "ref" */
}

static modp_c *modp_id2c(id object)
{
    return [object modp_reference];	/* write for inplace arithmetic */
}

static id modp_t2id(id proto,modp_t f)
{
    return [proto modp_value:f];	/* new object containing copy of "f" */
}

static id modp_c2id(id proto,modp_c* c)
{
    return [proto modp_reference:c];/* new object containing "c" */
}

static modp_t modp_fromintvalue(int i,modp_args args)
{
    modp_t red;
    
    if (i==0) return 0;
    if (i <0) {
	red = -i;
	red %= args.p;	/* it's dangerous to % int & unsigned */
	red = (red)?args.p-red:0;
    } else {
	red  = i;
	red %= args.p;	/* dito */
    }
    
    return red;
}

static int modp_check(modp_t self,modp_args args)
{
    assert(self < args.p);return 1;
}

static modp_t modp_zero(modp_args args)
{
    return 0;
}

static modp_t modp_one(modp_args args)
{
    return 1;
}

static unsigned modp_hash(modp_t a,modp_args args)
{
    return a;
}

static int modp_iseq(modp_t a,modp_t b,modp_args args)
{
    assert(modp_check(a,args) && modp_check(b,args));
    return (a == b);
}

static int modp_isop(modp_t a,modp_t b,modp_args args)
{
    assert(modp_check(a,args) && modp_check(b,args));
    return (a==0)?(b==0):(a+b==args.p);
}

static int modp_iszero(modp_t a,modp_args args)
{
    return a==0;
}

static int modp_isone(modp_t a,modp_args args)
{
    return a==1;
}

static int modp_isminusone(modp_t a,modp_args args)
{
    return (a+1)==args.p;
}

static modp_t modp_neg(modp_t a,modp_args args)
{
    assert(modp_check(a,args));return (a)?args.p-a:0;
}

static modp_t modp_dbl(modp_t a,modp_args args)
{
    modp_t c = a+a;
    assert(args.p != 2 && modp_check(a,args));
    if (c) return (c<args.p)?c:c-args.p; else return 0;
}

static modp_t modp_add(modp_t a,modp_t b,modp_args args)
{
    modp_t c = a+b;
    assert(modp_check(a,args) && modp_check(b,args));
    return ((c>=args.p)?c-args.p:c); /* compiles better than c<p?c:c-p */
}

static modp_t modp_sub(modp_t a,modp_t b,modp_args args)
{
    assert(modp_check(a,args) && modp_check(b,args));
    return (a>=b)?(a-b):(args.p-(b-a));
}

static modp_t modp_mul(modp_t a,modp_t b,modp_args args)
{
    unsigned c = a * b;		/* limitation to 16bits to be able to do this
				 * russian peasant 50% slower
                                 */
    assert(sizeof(unsigned) == 2 * sizeof(modp_t));
    return c % args.p;
}

static modp_t modp_sqr(modp_t a,modp_args args)
{
    unsigned c = a * a;
    assert(sizeof(unsigned) == 2 * sizeof(modp_t));
    return c % args.p;
}

static modp_t modp_inv(modp_t x,modp_args args)
{
    unsigned q,s;
    int u1,u2,us;  /* intermediate values can be negative */
    modp_t a,b,inv;
    
    assert(x != 0 && x != 1 && x+1 != args.p);
    
    a = x;b = args.p;u1 = 1;u2 = 0;
    while (b) {
	s  = a%b;q = a/b;
	a  = b;b = s;
	u1 -= q*u2;			
	us  = u1;u1 = u2;u2 = us;
    }
    
    inv = ((u1<0)?u1+args.p:u1); /* keep result positive */
    
    assert(modp_check(inv,args));
    assert(modp_isone(modp_mul(x,inv,args),args));
    return inv;
}

static modp_t modp_div(modp_t a,modp_t b,modp_args args)
{
    assert(b!=0);
    return modp_mul(a,modp_inv(b,args),args);
}

static modp_t modp_pow(modp_t a,int n,modp_args args)
{
    modp_t o;
    
    if (n==0) return modp_one(args);
    if (n==1) return a;
    if (n==2) return modp_sqr(a,args);
    
    o = modp_one(args);
    while (n>1) {
	if (n&1) o = modp_mul(o,a,args);
	a = modp_sqr(a,args);
	n >>= 1;
    }
    
    return modp_mul(o,a,args);
}

#if !modp_isvalue
#error "modp_copy_val.fab should not be included"
#endif

static void modp_clear(modp_c *c,modp_args args)
{
    /* nothing to clear, but the following might help... */
    #ifndef DEBUG
    *c = (modp_t)0xcafebabe;
    #endif
}

static void modp_copy(modp_c *c,modp_t a,modp_args args)
{
    *c = a;
}

static void modp_deepcopy(modp_c *c,modp_t a,modp_args args)
{
    *c = a;
}

static void modp_move(modp_c *c,modp_c *a,modp_args args)
{
    *c = *a;
    #ifndef DEBUG
    *a = (modp_t)0xcafebabe;
    #endif
}

#if !modp_isvalue
#error "modp_add_val.fab should not be included"
#endif

static void modp_oozero(modp_c *c,modp_args args)
{
    *c = modp_zero(args);
}

static void modp_inzero(modp_c *a,modp_args args)
{
    *a = modp_zero(args);
}

static void modp_inneg(modp_c *a,modp_args args)
{
    *a = modp_neg(*a,args);
}

static void modp_ooneg(modp_c *c,modp_t a,modp_args args)
{
    *c = modp_neg(a,args);
}

static modp_t modp_dblv(modp_t a,int v,modp_args args)
{
    modp_t c = modp_dbl(a,args);return (v==+1)?c:modp_neg(c,args);
}

static void modp_indbl(modp_c *a,int v,modp_args args)
{
    *a = modp_dblv(*a,v,args);
}

static void modp_oodbl(modp_c *c,modp_t a,int v,modp_args args)
{
    *c = modp_dblv(a,v,args);
}

static modp_t modp_addvw(modp_t a,int v,modp_t b,int w,modp_args args)
{
    modp_t c;assert(v*v == +1 && w*w == 1);
    
    if (v == +1) {
	if (w == +1) {
	    c = modp_add(a,b,args);
	} else {
	    c = modp_sub(a,b,args);
	}
    } else {
	if (w == +1) {
	    c = modp_sub(b,a,args);
	} else {
	    c = modp_neg(modp_add(a,b,args),args);
	}
    }
    
    return c;
}

static void modp_inadd(modp_c *a,int v,modp_t b,int w,modp_args args)
{
    *a = modp_addvw(*a,v,b,w,args);
}

static void modp_ooadd(modp_c *c,modp_t a,int v,modp_t b,int w,modp_args args)
{
    *c = modp_addvw(a,v,b,w,args);
}
#if !modp_isvalue
#error "modp_mul_val.fab should not be included"
#endif

static void modp_insqr(modp_c *a,modp_args args)
{
    *a = modp_sqr(*a,args);
}

static void modp_oosqr(modp_c *c,modp_t a,modp_args args)
{
    *c = modp_sqr(a,args);
}

static void modp_inmul(modp_c *a,modp_t b,modp_args args)
{
    *a = modp_mul(*a,b,args);
}

static void modp_oomul(modp_c *c,modp_t a,modp_t b,modp_args args)
{
    *c = modp_mul(a,b,args);
}
#if !modp_isvalue
#error "modp_inv_val.fab should not be included"
#endif

static void modp_ininv(modp_c *a,modp_args args)
{
    *a = modp_inv(*a,args);
}

static void modp_ooinv(modp_c *c,modp_t a,modp_args args)
{
    *c = modp_inv(a,args);
}

#if !modp_isvalue
#error "modp_div_val.fab should not be included"
#endif

static void modp_indiv(modp_c *a,modp_t b,modp_args args)
{
    *a = modp_div(*a,b,args);
}

static BOOL modp_oodiv(modp_c *c,modp_t a,modp_t b,modp_args args)
{
    *c = modp_div(a,b,args);return SUCCESS;
}
#if !modp_isvalue
#error "modp_add_val.fab should not be included"
#endif

static modp_t modp_mulv(modp_t a,modp_t b,int v,modp_args args)
{
    modp_t c = modp_mul(a,b,args);return (v==+1)?c:modp_neg(c,args);
}

static void modp_inmulv(modp_c *a,modp_t b,int v,modp_args args)
{
    *a = modp_mulv(*a,b,v,args);
}

static void modp_oomulv(modp_c *c,modp_t a,modp_t b,int v,modp_args args)
{
    *c = modp_mulv(a,b,v,args);
}

static modp_t modp_addmul(modp_t a,int v,modp_t b,modp_t s,int w,modp_args args)
{
    return modp_addvw(a,v,modp_mul(b,s,args),w,args);
}

static modp_t modp_addsqr(modp_t a,int v,modp_t b,int w,modp_args args)
{
    return modp_addvw(a,v,modp_sqr(b,args),w,args);
}

static modp_t modp_muladd(modp_t a,modp_t s,int v,modp_t b,int w,modp_args args)
{
    return modp_addvw(modp_mul(a,s,args),v,b,w,args);
}

static modp_t modp_muladdmul(modp_t a,modp_t s,int v,modp_t b,modp_t t,int w,modp_args args)
{
    return modp_addvw(modp_mul(a,s,args),v,modp_mul(b,t,args),w,args);
}

static void modp_inaddmul(modp_c *a,int v,modp_t b,modp_t t,int w,modp_args args)
{
    *a = modp_addmul(*a,v,b,t,w,args);
}

static void modp_ooaddmul(modp_c *c,modp_t a,int v,modp_t b,modp_t t,int w,modp_args args)
{
    *c = modp_addmul(a,v,b,t,w,args);
}

static void modp_inaddsqr(modp_c *a,int v,modp_t b,int w,modp_args args)
{
    *a = modp_addsqr(*a,v,b,w,args);
}

static void modp_ooaddsqr(modp_c *c,modp_t a,int v,modp_t b,int w,modp_args args)
{
    *c = modp_addsqr(a,v,b,w,args);
}

static void modp_inmuladd(modp_c *a,modp_t s,int v,modp_t b,int w,modp_args args)
{
    *a = modp_muladd(*a,s,v,b,w,args);
}

static void modp_oomuladd(modp_c *c,modp_t a,modp_t s,int v,modp_t b,int w,modp_args args)
{
    *c = modp_muladd(a,s,v,b,w,args);
}

static void modp_inmuladdmul(modp_c *a,modp_t s,int v,modp_t b,modp_t t,int w,modp_args args)
{
    *a = modp_muladdmul(*a,s,v,b,t,w,args);
}

static void modp_oomuladdmul(modp_c *c,modp_t a,modp_t s,int v,modp_t b,modp_t t,int w,modp_args args)
{
    *c = modp_muladdmul(a,s,v,b,t,w,args);
}
static void modp_args_fileOut(id aFiler,modp_args *args) {}
static void modp_args_fileIn(id aFiler,modp_args *args) {}

static void modp_fileOut(id aFiler,modp_c *c,modp_args args)
{
    [aFiler fileOut:c type:'S'];
}

static void modp_fileIn(id aFiler,modp_c *c,modp_args args)
{
    [aFiler fileIn:c type:'S'];
}

@implementation IntegerModp

+ new
{
    return [self error:"You can't create a IntegerModp without modulus"];
}

+ modulus:(unsigned short)aPrime
{
    return [self int:0 modulus:aPrime];
}

- _setUpIntValue:(int)intValue modulus:(unsigned short)aPrime
{
    modulus = aPrime;
    value   = modp_fromintvalue(intValue,modp_getargs(self));
    return self;
}

- int:(int)intValue modulus:(unsigned short)aPrime
{
    return [self notImplemented:_cmd];
}

+ int:(int)intValue modulus:(unsigned short)aPrime
{
    unsigned i,m = aPrime;
    
    if (m>USHRT_MAX_PRIME) [self error:"Modulus Too Big"];

    if (m != USHRT_MAX_PRIME) {
    for(i=2;i<=m/2;i++) if (m%i == 0) return [self error:"Modulus Not Prime"];
    }
    
    return [[super new] _setUpIntValue:intValue modulus:aPrime];
}

- class_vector
{
    return (id)[modp_vector class];
}

- class_vardnsrecdegsps_polynomial
{
    return (id)[modp_vardnsrecdegsps_polynomial class];
}

- class_vardnsrecdegdns_polynomial
{
    return (id)[modp_vardnsrecdegdns_polynomial class];
}

- class_vardnsexpdegsps_polynomial
{
    return (id)[modp_vardnsexpdegsps_polynomial class];
}

- setmodp_value:(modp_t)aValue
{
   assert(modulus);value = aValue;return self;
}

- clone
{
    return [[super clone] setmodp_value:0];
}

- (modp_t) modp_value
{
    return value;
}

- modp_value:(modp_t)aValue
{
    return [[self clone] setmodp_value:aValue];
}

- (modp_t *) modp_reference
{
    return &value;
}

- modp_reference:(modp_t *)aValue
{
    return [[self clone] setmodp_value:*aValue];
}

- (BOOL)sameClass:b			{ return isa == [b class] && modulus == [b modulus]; }
- (BOOL)inAdditiveSemiGroup		{ return YES; }
- (BOOL)inAdditiveMonoid		{ return YES; }
- (BOOL)inAdditiveGroup			{ return YES; }

- (BOOL)inSemiGroup			{ return YES; }
- (BOOL)inMonoid			{ return YES; }
- (BOOL)inGroup				{ return YES;  }

- (BOOL)inEuclideanDomain		{ return YES; }
- (BOOL)inIntegralDomain		{ return YES; }
- (BOOL)inField				{ return YES; }

- (BOOL)inOrderedSet			{ return NO; }



- (unsigned) hash
{
    return modp_hash(modp_id2t(self),modp_getargs(self));
}

- (BOOL) isEqual:b
{
    [self checkSameClass:b];
    if (self==b) {
    return YES;
    } else {
    return modp_iseq(modp_id2t(self),modp_id2t(b),modp_getargs(self));
    }
}

- (BOOL) notEqual:b
{
    [self checkSameClass:b];
    if (self==b) {
    return NO;
    } else {
    return !modp_iseq(modp_id2t(self),modp_id2t(b),modp_getargs(self));
    }
}

- (unsigned short) modulus
{
    return modulus;
}

- (int) intValue
{
    return value;
}

- intValue:(int)aValue
{
    modp_t a = modp_fromintvalue(aValue,modp_getargs(self));
    return [self modp_value:a];
}


- zero
{
    return [self intValue:0];
}

- (BOOL) isZero
{
    assert([self check]);
    return modp_iszero(modp_id2t(self),modp_getargs(self));
}

- (BOOL) notZero
{
    assert([self check]);
    return NO == modp_iszero(modp_id2t(self),modp_getargs(self));
}

- (BOOL) isOpposite:b
{
    [self checkSameClass:b];
    
    if (self == b) {
	return [self isZero] || [self isCharacteristicTwo];
    } else {
	return modp_isop(modp_id2t(self),modp_id2t(b),modp_getargs(self));
    }
}

- (BOOL) notOpposite:b
{
    [self checkSameClass:b];

    if (self == b) {
	return [self notZero] && [self notCharacteristicTwo];
    } else {
	return NO == modp_isop(modp_id2t(self),modp_id2t(b),modp_getargs(self));
    }
}

- negate
{
    if ([self isZero] || [self isCharacteristicTwo]) {
	return self ;
    } else {
	modp_c c;assert([self check]);
	modp_ooneg(&c,modp_id2t(self),modp_getargs(self));
	return modp_c2id(self,&c);
    }
}

- _double:(int)v
{
    if ([self isZero] || [self isCharacteristicTwo]) {
	return [self zero];
    } else {
	modp_c c;assert([self check]);
	modp_oodbl(&c,modp_id2t(self),v,modp_getargs(self));
	return modp_c2id(self,&c);
    }
}

- double
{
    if ([self isZero] || [self isCharacteristicTwo]) {
	return [self zero];
    } else {
	modp_c c;assert([self check]);
	modp_oodbl(&c,modp_id2t(self),+1,modp_getargs(self));
	return modp_c2id(self,&c);
    }
}

- _add:(int)v:b:(int)w
{
    assert([self sameClass:b] && v*v == 1 && w*w == 1);

    if (self == b) {
	return (v==w)?[self _double:v]:[self zero];
    } else {
	if ([self inAdditiveMonoid]) {
	    if ([self isZero]) return [b _negate:w];
	    if ([b isZero]) return [self _negate:v];
	}
	if (1) {
	    modp_c c;
	    modp_ooadd(&c,modp_id2t(self),v,modp_id2t(b),w,modp_getargs(self));
	    return modp_c2id(self,&c);
	}
    }

    return nil; /* to quiet some compilers, e.g. WATCOM */
}

- add:b
{
    [self checkSameClass:b];

    if (self == b) {
	return [self double];
    } else {
	if ([self inAdditiveMonoid]) {
	    if ([self isZero]) return b;
	    if ([b isZero]) return self;
	}
	if (1) {
	    modp_c c;
	    modp_ooadd(&c,modp_id2t(self),+1,modp_id2t(b),+1,modp_getargs(self));
	    return modp_c2id(self,&c);
	}
    }

    return nil;
}

- subtract:b
{
    [self checkSameClass:b];

    if (self == b) {
	return [self zero];
    } else {
	if ([self inAdditiveMonoid]) {
	    if ([self isZero]) return [b negate];
	    if ([b isZero]) return self;
	}
	if (1) {
	    modp_c c;
	    modp_ooadd(&c,modp_id2t(self),+1,modp_id2t(b),-1,modp_getargs(self));
	    return modp_c2id(self,&c);
	}
    }

    return nil;
}


- one
{
    return [self intValue:+1];
}

- minusOne
{
    return [self intValue:-1];
}

- (BOOL) isOne
{
    assert([self check]);
    return modp_isone(modp_id2t(self),modp_getargs(self));
}

- (BOOL) notOne
{
    assert([self check]);
    return NO == modp_isone(modp_id2t(self),modp_getargs(self));
}

- (BOOL) isMinusOne
{
    assert([self check]);
    return modp_isminusone(modp_id2t(self),modp_getargs(self));
}

- (BOOL) notMinusOne
{
    assert([self check]);
    return NO == modp_isminusone(modp_id2t(self),modp_getargs(self));
}

- square
{
    modp_c c;

    if ([self inMonoid] && [self isOne]) return self;
    if ([self inAdditiveMonoid]) {
	if ([self isMinusOne]) return [self one];
	if ([self isZero])     return self;
    }

    assert([self check]);
    modp_oosqr(&c,modp_id2t(self),modp_getargs(self));
    return modp_c2id(self,&c);
}

- multiply:b
{
    [self checkSameClass:b];

    if (self == b) {
	return [self square];
    } else {
	modp_c c;
	if ([self inMonoid]) {
	    if ([self isOne]) return b;
	    if ([b isOne]) return self;
	}
	if ([self inAdditiveMonoid]) {
	    if ([self isZero]||[b isZero]) return [self zero];
	    if ([self isMinusOne]) return [b negate];
	    if ([b isMinusOne]) return [self negate];
	}
        modp_oomul(&c,modp_id2t(self),modp_id2t(b),modp_getargs(self));
        return modp_c2id(self,&c);
    }
}

- inverse
{
    if ([self inMonoid] && [self isOne]) return self;
    if ([self inAdditiveMonoid]) {
	if ([self isMinusOne]) return self;
	if ([self isZero])     return nil;
    }
    if (1) {
	modp_c c;assert([self check]);
	modp_ooinv(&c,modp_id2t(self),modp_getargs(self));
	return modp_c2id(self,&c);
    }

    return nil;
}

- divide:b
{
    if ([b isZero]) return nil;
    if (self == b) {
	return [self one];
    } else {
	id inv = [b inverse];
	return [self multiply:inv];
    }
}

- _add:(int)v:B multiply:b:(int)w
{
    assert([self sameClass:B] && [self sameClass:b] && v*v == 1 && w*w == 1);

    if ([self isZero]) return [B _multiply:b:+w];
    if ([B isZero]) return [self _negate:v];
    if ([b isZero]) return [self _negate:v];

    if ([b isOne]) return [self _add:v:B:+w];
    if ([B isOne]) return [self _add:v:b:+w];
    if ([b isMinusOne]) return [self _add:v:B:-w];
    if ([B isMinusOne]) return [self _add:v:b:-w];

    if (1) {
	modp_c c;
	modp_ooaddmul(&c,modp_id2t(self),v,modp_id2t(B),modp_id2t(b),w,modp_getargs(self));
	return modp_c2id(self,&c);
    }

    return nil;
}

- _multiply:a:(int)v add:B:(int)w
{
    assert([self sameClass:a] && [self sameClass:B] && v*v == 1 && w*w == 1);

    if ([self isZero]) return [B _negate:+w];
    if ([a isZero]) return [B _negate:+w];
    if ([B isZero]) return [self _multiply:a:+v];

    if ([self isOne]) return [a _add:+v:B:+w];
    if ([a isOne]) return [self _add:+v:B:+w];
    if ([self isMinusOne]) return [a _add:-v:B:+w];
    if ([a isMinusOne]) return [self _add:-v:B:+w];

    if (1) {
	modp_c c;
	modp_oomuladd(&c,modp_id2t(self),modp_id2t(a),v,modp_id2t(B),w,modp_getargs(self));
	return modp_c2id(self,&c);
    }

    return nil;
}

- _multiply:a:(int)v add:B multiply:b:(int)w
{
    assert([self sameClass:a] && [self sameClass:B] && [self sameClass:b] && v*v == 1 && w*w == 1);

    if ([self isZero]) return [B _multiply:b:+w];
    if ([a isZero]) return [B _multiply:b:+w];
    if ([B isZero]) return [self _multiply:a:+v];
    if ([b isZero]) return [self _multiply:a:+v];

    if ([self isOne]) return [a _add:+v:B multiply:b:+w];
    if ([a isOne]) return [self _add:+v:B multiply:b:+w];
    if ([b isOne]) return [self _multiply:a:+v add:B:+w];
    if ([B isOne]) return [self _multiply:a:+v add:b:+w];

    if ([self isMinusOne]) return [a _add:-v:B multiply:b:+w];
    if ([a isMinusOne]) return [self _add:-v:B multiply:b:+w];
    if ([b isMinusOne]) return [self _multiply:a:+v add:B:-w];
    if ([B isMinusOne]) return [self _multiply:a:+v add:b:-w];

    if (1) {
	modp_c c;
	modp_oomuladdmul(&c,modp_id2t(self),modp_id2t(a),v,modp_id2t(B),modp_id2t(b),w,modp_getargs(self));
	return modp_c2id(self,&c);
    }

    return nil;
}


- (int) characteristic
{
    return modulus;
}

- frobenius
{
    return self;
}

- frobeniusInverse
{
    return self;
}


- (BOOL) printsLeadingSign
{
    return NO;
}

- printOn:(IOD)aFile
{
    fprintf(aFile,"%i",value);return self;
}


- fileOutOn:aFiler
{
    [super fileOutOn:aFiler];
    [aFiler fileOut:&value type:'S'];
    [aFiler fileOut:&modulus type:'S'];
    return self;
}

- fileInFrom:aFiler
{
    [super fileInFrom:aFiler];
    [aFiler fileIn:&value type:'S'];
    [aFiler fileIn:&modulus type:'S'];
    return self;
}

@end

