/*ident	"@(#)cls4:src/Bits.h	1.4" */
/*******************************************************************************

C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1993  UNIX System Laboratories, Inc.
Copyright (c) 1991, 1992 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
#ifndef _BITS_H
#define _BITS_H

#include "Block.h"

typedef size_t Bits_chunk;
static const int Bits_shift_ATTLC = 5;
static const int Bits_len_ATTLC = 1 << Bits_shift_ATTLC;
static const int Bits_mask_ATTLC = Bits_len_ATTLC - 1;

Blockdeclare(Bits_chunk)

class Bits {
private:
	Block(Bits_chunk) b;
	size_t n;

	// the chunk number that contains bit n
	size_t chunk(size_t n) const {
		return n >> Bits_shift_ATTLC;
	}

	// the number of chunks needed to contain an n-bit string
	size_t bound(size_t n) const {
		return (n + Bits_len_ATTLC - 1) >> Bits_shift_ATTLC;
	}

	// a pointer to the (non-existent) chunk immediately
	// after the last one in this Bits
	Bits_chunk* limit() {
		return (Bits_chunk*)b + bound(n);
	}
	const Bits_chunk* limit() const {
		return (const Bits_chunk*)b + bound(n);
	}

	// turn off unused high-order bits in the high-order chunk
	void normalize() {
		/*register*/ int ct = n & Bits_mask_ATTLC;
		if (ct)
			b[chunk(n)] &= ~(~Bits_chunk(0) << ct);
	}

	int compare(const Bits&) const;
	int equal(const Bits&) const;

public:
	Bits() { n = 0; }
	Bits(Bits_chunk, size_t = 1);
	size_t size() const { return n; }
	size_t size(size_t);
	friend Bits operator& (const Bits&, const Bits&);
	friend Bits operator| (const Bits&, const Bits&);
	friend Bits operator^ (const Bits&, const Bits&);
	friend Bits operator~ (const Bits&);
	friend Bits operator<< (const Bits&, int);
	friend Bits operator>> (const Bits&, int);
	friend inline int operator< (const Bits&, const Bits&);
	friend inline int operator> (const Bits&, const Bits&);
	friend inline int operator<= (const Bits&, const Bits&);
	friend inline int operator>= (const Bits&, const Bits&);
	friend inline int operator== (const Bits&, const Bits&);
	friend inline int operator!= (const Bits&, const Bits&);
	Bits& operator&= (const Bits&);
	Bits& operator|= (const Bits&);
	Bits& operator^= (const Bits&);
	Bits& operator<<= (int);
	Bits& operator>>= (int);
	Bits& compl4();
	Bits& concat(const Bits&);
	Bits& set(size_t i) {
		if (i < n)
			b[chunk(i)] |= Bits_chunk(1) << (i&Bits_mask_ATTLC);
		return *this;
	}
	Bits& set(size_t i, size_t x) {
		if (i < n) {
			/*register*/ Bits_chunk* p = &b[chunk(i)];
			/*register*/ Bits_chunk mask = Bits_chunk(1) << (i&Bits_mask_ATTLC);
			if (x)
				*p |= mask;
			else
				*p &= ~mask;
		}
		return *this;
	}
	Bits& reset(size_t i) {
		if (i < n)
			b[chunk(i)] &= ~(Bits_chunk(1) << (i&Bits_mask_ATTLC));
		return *this;
	}
	Bits& compl4(size_t i) {
		if (i < n)
			b[chunk(i)] ^= Bits_chunk(1) << (i&Bits_mask_ATTLC);
		return *this;
	}
	size_t count() const;
	operator Bits_chunk() const;
	int operator[] (size_t i) const {
		if (i >= n)
			return 0;
		else
			return (b[chunk(i)] >> (i&Bits_mask_ATTLC)) & 1;
	}
	size_t signif() const;
	size_t trim() { return size(signif()); }
};

inline int
operator< (const Bits& a, const Bits& b)
{
	return a.compare(b) < 0;
}

inline int
operator> (const Bits& a, const Bits& b)
{
	return a.compare(b) > 0;
}

inline int
operator<= (const Bits& a, const Bits& b)
{
	return a.compare(b) <= 0;
}

inline int
operator>= (const Bits& a, const Bits& b)
{
	return a.compare(b) >= 0;
}

inline int
operator== (const Bits& a, const Bits& b)
{
	return a.equal(b);
}

inline int
operator!= (const Bits& a, const Bits& b)
{
	return !a.equal(b);
}

Bits concat(const Bits&, const Bits&);

#endif
