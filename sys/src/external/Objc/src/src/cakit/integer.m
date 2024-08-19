
/*
 * Computer Algebra Kit (c) 1992,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: integer.m,v 1.7 2000/10/12 14:40:25 stes Exp $
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

static int 
bigintwrd_create (bigintdig_t self, DIGIT * digits, int numdigits)
{
  int n;
  assert (sizeof (DIGIT) == sizeof (bigintwrd_t));
  n = numdigits;
  while (n--)
    *self++ = *digits++;
  return numdigits;
}

static void 
bigintwrd_extract (bigintdig_t self, int count, DIGIT * digits, int numdigits)
{
  assert (numdigits == count);
  while (count--)
    *digits++ = *self++;
}

static int 
bigintwrd_numdigits (bigintdig_t a, int n)
{
  assert (n && sizeof (bigintwrd_t) == sizeof (DIGIT));
  return n;
}

static DIGIT 
bigintwrd_digitat (bigintdig_t a, int i, int n)
{
  assert (n && 0 <= i && i < n && sizeof (bigintwrd_t) == sizeof (DIGIT));
  return a [n - i - 1];
}

static int 
bigintwrd_insert (bigintdig_t a, int n, DIGIT d)
{
  assert (n && sizeof (bigintwrd_t) == sizeof (DIGIT));
  a [n] = d;
  return n + 1;
}

static int 
bigintwrd_remove (bigintdig_t a, int n)
{
  assert (n && sizeof (bigintwrd_t) == sizeof (DIGIT));
  return n - 1;
}

static bigintwrd_t 
bigintwrd_oodbl (bigintdig_t hic, bigintdig_t hia, int an)
{
  unsigned c = 0;
  while (an--)
    {
      bigintwrd_t w = *--hia;
      c = c + w + w;
      *--hic = c;
      c >>= 16;
    }
  return c;
}

static bigintwrd_t 
bigintwrd_indbl (bigintdig_t hia, int an)
{
  unsigned c = 0;
  while (an--)
    {
      bigintwrd_t w = *--hia;
      c = c + w + w;
      *hia = c;
      c >>= 16;
    }
  return c;
}

static bigintwrd_t 
bigintwrd_ooadd (bigintdig_t hic, bigintdig_t hia, bigintdig_t hib, int n, int m)
{
  unsigned c = 0;
  while (n--)
    {
      c = c + (*--hia) + (*--hib);
      *--hic = c;
      c >>= 16;
    }
  while (m--)
    {				/* don't stop if c == 0 ! */
      c += (*--hia);
      *--hic = c;
      c >>= 16;
    }
  return c;
}

static bigintwrd_t 
bigintwrd_inadd (bigintdig_t hia, bigintdig_t hib, int n, int m)
{
  unsigned c = 0;
  while (n--)
    {
      c = c + (*--hia) + (*--hib);
      *hia = c;
      c >>= 16;
    }
  while (c && m--)
    {				/* for inplace, don't need to continue if c == 0 */
      c += (*--hia);
      *hia = c;
      c >>= 16;
    }
  return c;
}

static bigintwrd_t 
bigintwrd_oosub (bigintdig_t hic, bigintdig_t hia, bigintdig_t hib, int n, int m)
{
  unsigned c = 0;
  bigintwrd_t cc = 0;		/* alternatively, we could use a negative "carry"
				 * by using c = 0xffff0000 + (c >> 16) and adding
				 */

  while (n--)
    {
      c = (*--hia) - (*--hib + cc);
      *--hic = c;
      cc = (c >> 16);
      cc = -cc;
    }
  while (m--)
    {				/* don't stop if cc == 0 ! */
      c = (*--hia) - cc;
      *--hic = c;
      cc = (c >> 16);
      cc = -cc;
    }

  return cc;
}

static bigintwrd_t 
bigintwrd_insub (bigintdig_t hia, bigintdig_t hib, int n, int m)
{
  unsigned c = 0;
  bigintwrd_t cc = 0;

  while (n--)
    {
      c = (*--hia) - (*--hib + cc);
      *hia = c;
      cc = (c >> 16);
      cc = -cc;
    }
  while (cc && m--)
    {				/* for inplace, don't need to continue if cc == 0 */
      c = (*--hia) - cc;
      *hia = c;
      cc = (c >> 16);
      cc = -cc;
    }

  return cc;
}

static bigintwrd_t 
bigintwrd_oomul (bigintdig_t hic, bigintwrd_t s, bigintdig_t hib, int n)
{
  unsigned c = 0;
  while (n--)
    {
      c = s * (*--hib) + c;
      *--hic = c;
      c >>= 16;
    }
  return c;
}

static bigintwrd_t 
bigintwrd_inaddmul (bigintdig_t hia, bigintwrd_t s, bigintdig_t hib, int n)
{
  unsigned c = 0;
  while (n--)
    {
      c = c + (*--hia) + s * (*--hib);
      *hia = c;
      c >>= 16;
    }
  return c;
}

static bigintwrd_t 
bigintwrd_insubmul (bigintdig_t hia, bigintwrd_t s, bigintdig_t hib, int n)
{
  unsigned c = 0;
  bigintwrd_t cc = 0;
  while (n--)
    {
      c = (*--hia) - (s * (*--hib) + cc);
      *hia = c;
      cc = (c >> 16);
      cc = -cc;			/* single precision negate */
    }
  return cc;
}

static bigintwrd_t 
bigintwrd_ooquorem (bigintdig_t q, bigintdig_t a, int n, bigintwrd_t b)
{
  unsigned c = 0;
  while (n--)
    {
      c = (c << 16) + (*a++);
      *q++ = (c / b);
      c %= b;
    }
  return c;
}

static bigintwrd_t 
bigintwrd_rem (bigintdig_t a, int n, bigintwrd_t b)
{
  unsigned c = 0;
  while (n--)
    {
      c = (c << 16) + (*a++);
      c %= b;
    }
  return c;
}

static int 
bigintwrd_ffo (bigintwrd_t a)
{
  int c;
  for (c = 0; c < 16; c++)
    if (a & 0x0008000)
      return c;
    else
      a <<= 1;
  return c;
}

static void 
bigintwrd_bsl (int cnt, bigintdig_t dst, int len)
{
  unsigned c;

  assert (0 <= cnt && cnt < 16 && len >= 1);

  while (--len)
    {
      c = (*dst << 16) + (*(dst + 1));
      c <<= cnt;
      c >>= 16;
      *dst++ = c;
    }

  c = 0;
  c = (*dst);
  c <<= cnt;
  *dst = c;
}

static void 
bigintwrd_bsr (int cnt, bigintdig_t dst, int len)
{
  unsigned c;

  assert (0 <= cnt && cnt < 16 && len >= 1);

  while (--len)
    {
      dst--;
      c = ((*(dst - 1)) << 16) + *dst;
      c >>= cnt;
      *dst = c;
    }

  c = 0;
  c = (*--dst);
  c >>= cnt;
  *dst = c;
}

static bigintwrd_t 
bigintwrd_qguess (bigintdig_t dvdd, bigintdig_t dvsr)
{
  unsigned r, s;
  bigintwrd_t a, b, q;

  if ((a = (*dvdd)) == (b = (*dvsr)))
    {
      q = -1;
      r = dvdd [1] + b;
      if (r > 0x0000ffff)
	return q;
    }
  else
    {
      r = (a << 16) + dvdd [1];
      q = (r / b);
      r = (r % b);
    }

  s = dvsr [1] * q;
  while (s > ((r << 16) + dvdd [2]))
    {
      q--;
      r += b;
      if (r > 0x0000ffff)
	return q;
      s -= dvsr [1];
    }

  return q;
}
static int 
bigintdig_check (bigintdig_t loptr, int n)
{
  if (n)
    assert (*loptr != 0);
  return 1;
}

static int 
bigintdig_hicheck (bigintdig_t hiptr, int n)
{
  if (n)
    assert (*(hiptr - n) != 0);
  return 1;
}

static int 
bigintdig_create (bigintdig_t self, DIGIT * digits, int numdigits)
{
  return (numdigits) ? bigintwrd_create (self, digits, numdigits) : 0;
}

static void 
bigintdig_extract (bigintdig_t self, int count, DIGIT * digits, int numdigits)
{
  if (numdigits == 0)
    {
      assert (count == 0);
    }
  else
    {
      bigintwrd_extract (self, count, digits, numdigits);
    }
}

static bigintdig_t 
bigintdig_alloc (int n)
{
  return (bigintdig_t) OC_MallocAtomic (n * sizeof (bigintwrd_t));
}

static bigintdig_t 
bigintdig_realloc (bigintdig_t loptr, int n)
{
  assert (bigintdig_check (loptr, n));
  return (bigintdig_t) OC_Realloc (loptr, n * sizeof (bigintwrd_t));
}

static void 
bigintdig_copy (bigintdig_t lodst, bigintdig_t losrc, int n)
{
  assert (n == 0 || lodst != losrc);
  assert (bigintdig_check (losrc, n));
  while (n--)
    *lodst++ = *losrc++;
}

static void 
bigintdig_hicopy (bigintdig_t hidst, bigintdig_t hisrc, int n)
{
  assert (n == 0 || hidst != hisrc);
  assert (bigintdig_check (hisrc - n, n));
  while (n--)
    *--hidst = *--hisrc;
}

static bigintdig_t 
bigintdig_free (bigintdig_t loptr)
{
  OC_Free (loptr);
  return NULL;
}

static unsigned 
bigintdig_hash (int sgn, bigintdig_t loptr, int n)
{
  assert (bigintdig_check (loptr, n));
  if (n)
    {
      unsigned s = 0;
      unsigned hash = 0;
      while (n--)
	{
	  hash ^= ((*loptr++) << s);
	  s = (s + 4) % 16;
	}
      return (sgn == -1) ? (0xf0000000 | hash) : hash;
    }
  else
    {
      return 0;
    }
}

static int 
bigintdig_isone (int asgn, bigintdig_t aloptr, int an)
{
  assert (bigintdig_check (aloptr, an));
  return (an == 1) ? (asgn == +1 && aloptr [0] == 1) : 0;
}

static int 
bigintdig_isminusone (int asgn, bigintdig_t aloptr, int an)
{
  assert (bigintdig_check (aloptr, an));
  return (an == 1) ? (asgn == -1 && aloptr [0] == 1) : 0;
}

static int 
bigintdig_isabseq (bigintdig_t a, int an, bigintdig_t b, int bn)
{
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn));
  if (an == bn)
    {
      while (an--)
	{
	  if (*a++ != *b++)
	    return 0;
	}
      return 1;
    }
  else
    {
      return 0;
    }
}

static int 
bigintdig_iseq (int asgn, bigintdig_t a, int an, int bsgn, bigintdig_t b, int bn)
{
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn));
  if (an && bn)
    {
      return asgn == bsgn && bigintdig_isabseq (a, an, b, bn);
    }
  else
    {
      /* don't depend on sign of zero */
      return an == 0 && bn == 0;
    }
}

static int 
bigintdig_isop (int asgn, bigintdig_t a, int an, int bsgn, bigintdig_t b, int bn)
{
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn));
  if (an && bn)
    {
      return asgn + bsgn == 0 && bigintdig_isabseq (a, an, b, bn);
    }
  else
    {
      /* don't depend on sign of zero */
      return an == 0 && bn == 0;
    }
}

static int 
bigintdig_abscmp (bigintdig_t a, int an, bigintdig_t b, int bn)
{
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn));
  if (an == bn)
    {
      while (an--)
	{
	  bigintwrd_t ad = *a++;
	  bigintwrd_t bd = *b++;
	  if (ad == bd)
	    continue;
	  else
	    return (ad > bd) ? +1 : -1;
	}
      return 0;
    }
  else
    {
      return (an < bn) ? -1 : +1;
    }
}

static int 
bigintdig_cmp (int asgn, bigintdig_t a, int an, int bsgn, bigintdig_t b, int bn)
{
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn));

  /* don't depend on sign of zero */
  if (an == 0)
    return (bn) ? -bsgn : 0;
  if (bn == 0)
    return (an) ? +asgn : 0;

  return (asgn != bsgn) ? asgn : asgn * bigintdig_abscmp (a, an, b, bn);
}

static int 
bigintdig_numdigits (bigintdig_t a, int n)
{
  assert (bigintdig_check (a, n));
  return (n) ? bigintwrd_numdigits (a, n) : 0;
}

static DIGIT 
bigintdig_digitat (bigintdig_t a, int i, int n)
{
  assert (bigintdig_check (a, n));
  return (n) ? bigintwrd_digitat (a, i, n) : 0;
}

static DIGIT 
bigintdig_lastdigit (bigintdig_t a, int n)
{
  assert (bigintdig_check (a, n));
  return (n) ? bigintwrd_digitat (a, 0, n) : 0;
}

static DIGIT 
bigintdig_firstdigit (bigintdig_t a, int n)
{
  assert (bigintdig_check (a, n));
  return (n) ? bigintwrd_digitat (a, bigintwrd_numdigits (a, n) - 1, n) : 0;
}

static int 
bigintdig_insert (bigintdig_t a, int n, DIGIT d)
{
  assert (bigintdig_check (a, n));
  if (n)
    {
      return bigintwrd_insert (a, n, d);
    }
  else
    {
      assert (d);
      a [0] = d;
      return 1;			/* regardless of wordsize */
    }
}

static int 
bigintdig_remove (bigintdig_t a, int n)
{
  assert (bigintdig_check (a, n));
  return (n) ? bigintwrd_remove (a, n) : 0;
}

static int 
bigintdig_adjust (bigintdig_t loptr, int n)
{
  while (n && *loptr == 0)
    {
      n--;
      loptr++;
    }
  return n;
}

static int 
bigintdig_oodbl (bigintdig_t hic, bigintdig_t hia, int an)
{
  bigintwrd_t cc;
  assert (bigintdig_hicheck (hia, an));
  cc = bigintwrd_oodbl (hic, hia, an);
  if (cc)
    {
      an++;
      *(hic - an) = 1;
    }
  return an;
}

static int 
bigintdig_indbl (bigintdig_t hia, int an)
{
  bigintwrd_t cc;
  assert (bigintdig_hicheck (hia, an));
  cc = bigintwrd_indbl (hia, an);
  if (cc)
    {
      an++;
      *(hia - an) = 1;
    }
  return an;
}

static int 
bigintdig_ooadd (bigintdig_t hic, int asgn, bigintdig_t hia, int an, int bsgn, bigintdig_t hib, int bn)
{
  assert (an >= bn && bigintdig_abscmp (hia - an, an, hib - bn, bn) > 0);
  assert (bigintdig_hicheck (hia, an) && bigintdig_hicheck (hib, bn));

  if (asgn == bsgn)
    {
      bigintwrd_t cc = bigintwrd_ooadd (hic, hia, hib, bn, an - bn);
      if (cc)
	{
	  an++;
	  *(hic - an) = 1;
	}
    }
  else
    {
#ifndef NDEBUG
      bigintwrd_t cc = bigintwrd_oosub (hic, hia, hib, bn, an - bn);
      assert (cc == 0);
#else
      bigintwrd_oosub (hic, hia, hib, bn, an - bn);
#endif
      an = bigintdig_adjust (hic - an, an);
    }

  assert (bigintdig_hicheck (hic, an));
  return an;
}

static int 
bigintdig_inadd (int asgn, bigintdig_t hia, int an, int bsgn, bigintdig_t hib, int bn)
{
  assert (an >= bn && bigintdig_abscmp (hia - an, an, hib - bn, bn) > 0);
  assert (bigintdig_hicheck (hia, an) && bigintdig_hicheck (hib, bn));

  if (asgn == bsgn)
    {
      bigintwrd_t cc = bigintwrd_inadd (hia, hib, bn, an - bn);
      if (cc)
	{
	  an++;
	  *(hia - an) = 1;
	}
    }
  else
    {
#ifndef NDEBUG
      bigintwrd_t cc = bigintwrd_insub (hia, hib, bn, an - bn);
      assert (cc == 0);
#else
      bigintwrd_insub (hia, hib, bn, an - bn);
#endif
      an = bigintdig_adjust (hia - an, an);
    }

  assert (bigintdig_hicheck (hia, an));
  return an;
}

static int 
bigintdig_oomul (bigintdig_t hic, bigintdig_t hia, int an, bigintdig_t hib, int bn)
{
  bigintwrd_t cc;
  int cn = an + bn;

  assert (an && an <= bn);
  assert (bigintdig_hicheck (hia, an) && bigintdig_hicheck (hib, bn));

  cc = *--hia;
  cc = bigintwrd_oomul (hic, cc, hib, bn);
  hic--;
  *(hic - bn) = cc;

  while (--an)
    {
      cc = *--hia;
      if (cc)
	{
	  cc = bigintwrd_inaddmul (hic, cc, hib, bn);
	}
      hic--;
      *(hic - bn) = cc;
    }

  return bigintdig_adjust (hic - bn, cn);
}

static int 
bigintdig_ooquoremword (bigintdig_t q, bigintdig_t loa, int n, bigintwrd_t b, bigintwrd_t * r)
{
  assert (bigintdig_check (loa, n) && b != 0);
  if (r)
    {
      *r = bigintwrd_ooquorem (q - n, loa, n, b);	/* lo-pointer for q ! */
    }
  else
    {
      bigintwrd_ooquorem (q - n, loa, n, b);
    }
  return bigintdig_adjust (q - n, n);
}

static bigintwrd_t 
bigintdig_remword (bigintdig_t loa, int n, bigintwrd_t b)
{
  assert (bigintdig_check (loa, n) && b != 0);
  return bigintwrd_rem (loa, n, b);
}

static int 
bigintdig_remquo (bigintdig_t dvd, bigintdig_t dvs, int n, int m, bigintdig_t quo, int *qnref)
{
  int i, f;
  bigintwrd_t cc, q;

  assert (n > 1 && m >= 0);
  f = bigintwrd_ffo (*dvs);
  if (f)
    bigintwrd_bsl (f, dvs, n);

  *--dvd = 0;
  m++;				/* also if "f" is zero */
  if (f)
    bigintwrd_bsl (f, dvd, n + m);

  assert (bigintwrd_ffo (*dvs) == 0);
  if (quo)
    quo -= m;			/* make quo a lo-pointer */

  for (i = 0; i < m; i++)
    {
      q = bigintwrd_qguess (dvd, dvs);
      if (q)
	{
	  cc = bigintwrd_insubmul (dvd + n + 1, q, dvs + n, n);
	  if (cc > *dvd)
	    {
	      bigintwrd_inadd (dvd + n + 1, dvs + n, n, 0);
	      q--;
	    }
	}
      *dvd++ = 0;
      if (quo)
	*quo++ = q;
    }

  if (f)
    bigintwrd_bsr (f, dvd + n, n);	/* denormalize takes hi-ptr */
  if (f)
    bigintwrd_bsr (f, dvs + n, n);	/* currenlty useless, but inexpensive */

  if (qnref)
    *qnref = bigintdig_adjust (quo - m, m);
  return bigintdig_adjust (dvd, n);
}

static int 
bigintdig_inremquo_gt (bigintdig_t a, int an, bigintdig_t b, int bn, bigintdig_t q, int *qnref)
{
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn) && 0 < bn && bn <= an);
  if (bn == 1)
    {
      bigintwrd_t rem;
      *qnref = bigintdig_ooquoremword (q, a, an, b [0], &rem);
      if (rem)
	{
	  a [an - 1] = rem;
	  return 1;
	}
      else
	{
	  return 0;
	}
    }
  else
    {
      return bigintdig_remquo (a, b, bn, an - bn, q, qnref);
    }
}

static int 
bigintdig_inremquo (bigintdig_t a, int an, bigintdig_t b, int bn, bigintdig_t q, int *qnref)
{
  int cmp;
  assert (q && bigintdig_check (a, an) && bigintdig_check (b, bn) && 0 < bn);
  if ((cmp = bigintdig_abscmp (a, an, b, bn)))
    {
      if (cmp < 0)
	{
	  *qnref = 0;
	  return an;
	}
      else
	{
	  return bigintdig_inremquo_gt (a, an, b, bn, q, qnref);
	}
    }
  else
    {
      *--q = 1;
      *qnref = 1;
      return 0;
    }
}

static int 
bigintdig_inrem_gt (bigintdig_t a, int an, bigintdig_t b, int bn)
{
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn) && 0 < bn && bn <= an);
  if (bn == 1)
    {
      bigintwrd_t rem = bigintdig_remword (a, an, b [0]);
      if (rem)
	{
	  a [an - 1] = rem;
	  return 1;
	}
      else
	{
	  return 0;
	}
    }
  else
    {
      return bigintdig_remquo (a, b, bn, an - bn, NULL, NULL);
    }
}

static int 
bigintdig_inrem (bigintdig_t a, int an, bigintdig_t b, int bn)
{
  int cmp;
  assert (bigintdig_check (a, an) && bigintdig_check (b, bn) && 0 < bn);
  if ((cmp = bigintdig_abscmp (a, an, b, bn)))
    {
      return (cmp < 0) ? an : bigintdig_inrem_gt (a, an, b, bn);
    }
  else
    {
      return 0;
    }
}
typedef struct bigintreg
{
  int sign;
  int count;
  bigintdig_t top;
  bigintdig_t base;		/* not used, just for malloc-debug */
  struct bigintreg *next;
}
 *bigintreg_t;

#define REGISTER_BSIZE (128 * 1024)	/* size in bytes */
#define REGISTER_SIZE (REGISTER_BSIZE / sizeof(bigintwrd_t))

static int 
bigintreg_check (bigintreg_t self)
{
  assert (self->sign == +1 || self->sign == -1);
  assert (self->top == self->base + REGISTER_SIZE);
  assert (bigintdig_hicheck (self->top, self->count));
  return 1;
}

static bigintreg_t avail;

static bigintreg_t 
bigintreg_init (bigintreg_t self)
{
  self->sign = +1;
  self->count = 0;
  /* malloc(pagesize) 
   * keep a reference to base, because malloc-debug doesn't know about hiptr
   */
  self->base = bigintdig_alloc (REGISTER_SIZE);
  self->top = self->base + REGISTER_SIZE;
  self->next = NULL;

  return self;
}

static bigintreg_t 
bigintreg_new ()
{
  bigintreg_t new;
  if (avail)
    {
      new = avail;
      avail = avail->next;
    }
  else
    {
      new = bigintreg_init ((bigintreg_t) OC_Malloc (sizeof (struct bigintreg)));
    }

  assert (bigintreg_check (new));
  return new;
}

static void 
bigintreg_clear (bigintreg_t self)
{
  assert (bigintreg_check (self));
  self->count = 0;
  assert (bigintreg_check (self));
}

static void 
bigintreg_free (bigintreg_t self)
{
  bigintreg_clear (self);
  self->next = avail;
  avail = self;
}

static void 
bigintreg_load (bigintreg_t r, bigint_t a)
{
  int count = a->count;
  assert (bigintreg_check (r) && r->count == 0);
  r->sign = a->sign;
  bigintdig_hicopy (r->top, a->digits + count, count);
  r->count = count;
  assert (bigintreg_check (r));
  assert (bigintdig_iseq (a->sign, a->digits, a->count, r->sign, r->top - r->count, r->count));
}

static void 
bigintreg_oodbl_aux (bigintreg_t self, int asgn, bigintdig_t a, int an)
{
  assert (self->count == 0);
  self->count = bigintdig_oodbl (self->top, a + an, an);
  self->sign = asgn;
  assert (self->count == an || self->count == an + 1);
}

static void 
bigintreg_oodbl (bigintreg_t self, bigint_t a, int v)
{
  assert (bigintreg_check (self) && v * v == 1);
  bigintreg_oodbl_aux (self, a->sign * v, a->digits, a->count);
  assert (bigintreg_check (self));
}

static void 
bigintreg_ooadd_aux (bigintreg_t self, int asgn, bigintdig_t a, int an, int bsgn, bigintdig_t b, int bn)
{
  int cmp = bigintdig_abscmp (a, an, b, bn);

  if (cmp == 0)
    {
      if (asgn == bsgn)
	{
	  bigintreg_oodbl_aux (self, asgn, a, an);
	}
      else
	{
	  assert (self->count == 0);
	}
    }
  else
    {
      assert (self->count == 0);

      if (cmp > 0)
	{
	  self->count = bigintdig_ooadd (self->top, asgn, a + an, an, bsgn, b + bn, bn);
	  self->sign = asgn;
	}
      else
	{
	  self->count = bigintdig_ooadd (self->top, bsgn, b + bn, bn, asgn, a + an, an);
	  self->sign = bsgn;
	}

      assert (self->count > 0);
    }
}

static void 
bigintreg_ooadd (bigintreg_t self, bigint_t a, int v, bigint_t b, int w)
{
  assert (a != b && bigintreg_check (self) && v * v == 1 && w * w == 1);
  bigintreg_ooadd_aux (self, a->sign * v, a->digits, a->count, b->sign * w, b->digits, b->count);
  assert (bigintreg_check (self));
}

static void 
bigintreg_inadd_aux (bigintreg_t * ar, int asgn, bigintdig_t a, int an, bigintreg_t * br, int bsgn, bigintdig_t b, int bn)
{
  int cmp = bigintdig_abscmp (a, an, b, bn);

  if (cmp == 0)
    {
      if (asgn == bsgn)
	{
	  (*ar)->count = bigintdig_indbl (a + an, an);
	  (*ar)->sign = asgn;
	}
      else
	{
	  (*ar)->count = 0;
	}
    }
  else
    {
      if (cmp > 0)
	{
	  (*ar)->count = bigintdig_inadd (asgn, a + an, an, bsgn, b + bn, bn);
	  (*ar)->sign = asgn;
	}
      else
	{
	  (*br)->count = bigintdig_inadd (bsgn, b + bn, bn, asgn, a + an, an);
	  (*br)->sign = bsgn;
	  if (1)
	    {
	      bigintreg_t t = *ar;
	      *ar = *br;
	      *br = t;
	    }
	}
    }
}

static void 
bigintreg_inadd (bigintreg_t * ar, int v, bigintreg_t * br, int w)
{
  int an, bn;
  bigintreg_t a, b;
  a = *ar;
  an = a->count;
  b = *br;
  bn = b->count;
  assert (a != b && bigintreg_check (a) && bigintreg_check (b) && v * v == 1 && w * w == 1);
  bigintreg_inadd_aux (ar, v * a->sign, a->top - an, an, br, w * b->sign, b->top - bn, bn);
  assert (bigintreg_check (*ar) && bigintreg_check (*br));
}

static void 
bigintreg_oomul_aux (bigintreg_t self, int sgn, bigintdig_t a, int an, bigintdig_t b, int bn)
{
  assert (self->count == 0);
  if (an <= bn)
    {
      if (an)
	{
	  self->sign = sgn;
	  self->count = bigintdig_oomul (self->top, a + an, an, b + bn, bn);
	}
    }
  else
    {
      if (bn)
	{
	  self->sign = sgn;
	  self->count = bigintdig_oomul (self->top, b + bn, bn, a + an, an);
	}
    }
  assert (self->count == 0 || self->count == an + bn - 1 || self->count == an + bn);
}

static void 
bigintreg_oomul (bigintreg_t self, bigint_t a, bigint_t b)
{
  assert ((a != b || a == b) && bigintreg_check (self));	/* allow a==b for sqr */
  bigintreg_oomul_aux (self, a->sign * b->sign, a->digits, a->count, b->digits, b->count);
  assert (bigintreg_check (self));
}

static void 
bigintreg_inremquo (bigintreg_t a, bigintreg_t b, bigintreg_t q)
{
  assert (bigintreg_check (q) && q->count == 0);
  assert (bigintreg_check (a) && bigintreg_check (b) && b->count);
  a->count = bigintdig_inremquo (a->top - a->count, a->count, b->top - b->count, b->count, q->top, &q->count);
  q->sign = a->sign * b->sign;
  assert (bigintreg_check (a) && bigintreg_check (b) && a->count <= b->count);
  assert (bigintreg_check (q));
}

static void 
bigintreg_inrem (bigintreg_t a, bigintreg_t b)
{
  assert (bigintreg_check (a) && bigintreg_check (b) && b->count);
  a->count = bigintdig_inrem (a->top - a->count, a->count, b->top - b->count, b->count);
  assert (bigintreg_check (a) && bigintreg_check (b) && b->count);
}

static void 
bigintreg_ooquoremword (bigintreg_t q, bigint_t a, bigintwrd_t b, bigintwrd_t * r)
{
  assert (b != 0 && bigintreg_check (q) && q->count == 0);
  q->count = bigintdig_ooquoremword (q->top, a->digits, a->count, b, r);
  q->sign = a->sign;
  assert (q->count == a->count || q->count == a->count - 1);
}
typedef struct bigint bigint_c;
typedef struct bigint *bigintseq_t;
typedef struct
  {
    unsigned unused;
  }
bigint_args;

#define bigint_isvalue	0
#define bigint_pervalue	0

static bigint_args 
bigint_getargs (id self)
{
  bigint_args args;
  args.unused = 0;
  return args;
}

static int 
bigint_size (bigint_args args)
{
  return 1;
}

static int 
bigint_bsize (bigint_args args)
{
  return sizeof (bigint_c);
}

static bigint_t 
bigint_id2t (id object)
{
  return [object bigint_value];	/* read-only */
}

static bigint_t 
bigint_id2ref (id object, bigint_c * ref)
{
  return [object bigint_value];	/* read-only, scratch space "ref" */
}

static bigint_c *
bigint_id2c (id object)
{
  return [object bigint_reference];	/* write for inplace arithmetic */
}

static id 
bigint_t2id (id proto, bigint_t f)
{
  return [proto bigint_value:f];	/* new object containing copy of "f" */
}

static id 
bigint_c2id (id proto, bigint_c * c)
{
  return [proto bigint_reference:c];	/* new object containing "c" */
}

static int 
bigint_check (bigint_t self, bigint_args args)
{
  assert (self->sign == -1 || self->sign == +1);
  assert (0 <= self->count && self->count <= self->capacity);
  assert (bigintdig_check (self->digits, self->count));
  return 1;
}

static void 
bigint_create (bigint_c * c, int sign, DIGIT * digits, int numdigits, bigint_args args)
{
  c->sign = sign;
  c->digits = bigintdig_alloc (numdigits);	/* that's enough */
  c->count = bigintdig_create (c->digits, digits, numdigits);
  c->capacity = numdigits;
  assert (c->count <= numdigits);
  assert (bigint_check (c, args));
}

static void 
bigint_extract (bigint_t a, DIGIT * digits, int numdigits, bigint_args args)
{
  assert (bigint_check (a, args));
  assert (numdigits == bigintdig_numdigits (a->digits, a->count));
  bigintdig_extract (a->digits, a->count, digits, numdigits);
  assert (bigint_check (a, args));
}

static void 
bigint_oozero (bigint_c * c, bigint_args args)
{
  c->sign = 1;
  c->count = 0;
  c->capacity = 4;
  c->digits = bigintdig_alloc (4);

  assert (bigint_check (c, args));
}

static void 
bigint_copy (bigint_c * c, bigint_t a, bigint_args args)
{
  int count;
  assert (c != a && bigint_check (a, args));

  if ((count = a->count))
    {
      c->sign = a->sign;
      c->count = count;
      c->capacity = count;
      c->digits = bigintdig_alloc (count);
      bigintdig_copy (c->digits, a->digits, count);
    }
  else
    {
      bigint_oozero (c, args);
    }

  assert (bigint_check (c, args) && bigint_check (a, args));
}

static void 
bigint_move (bigint_c * c, bigint_c * a, bigint_args args)
{
  assert (c != a && bigint_check (a, args));

  c->sign = a->sign;
  c->count = a->count;
  c->capacity = a->capacity;
  c->digits = a->digits;
#ifndef NDEBUG
  a->digits = NULL;
#endif

  assert (bigint_check (c, args));
}

static void 
bigint_clear (bigint_c * c, bigint_args args)
{
  bigint_check (c, args);
  c->digits = bigintdig_free (c->digits);
}

static void 
bigint_expand (bigint_c * c)
{
  c->capacity += 1 + c->count;
  c->digits = bigintdig_realloc (c->digits, c->capacity);
}

static void 
bigint_store (bigint_c * c, bigintreg_t r, bigint_args args)
{
  int count;
  assert (bigintreg_check (r));

  if ((count = r->count))
    {
      c->sign = r->sign;
      c->count = count;
      c->capacity = count;
      c->digits = bigintdig_alloc (count);
      bigintdig_hicopy (c->digits + count, r->top, count);
    }
  else
    {
      bigint_oozero (c, args);
    }

  assert (bigint_check (c, args) && bigintreg_check (r));
  assert (bigintdig_iseq (c->sign, c->digits, c->count, r->sign, r->top - r->count, r->count));
}

static void 
bigint_restore (bigint_c * c, bigintreg_t r, bigint_args args)
{
  int count;
  assert (bigint_check (c, args) && bigintreg_check (r));

  count = r->count;
  while (count > c->capacity)
    bigint_expand (c);
  c->sign = r->sign;
  c->count = count;
  bigintdig_hicopy (c->digits + count, r->top, count);

  assert (bigint_check (c, args) && bigintreg_check (r));
}

static unsigned 
bigint_hash (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_hash (a->sign, a->digits, a->count);
}

static int 
bigint_iseq (bigint_t a, bigint_t b, bigint_args args)
{
  assert (a != b && bigint_check (a, args) && bigint_check (b, args));
  return bigintdig_iseq (a->sign, a->digits, a->count, b->sign, b->digits, b->count);
}

static int 
bigint_sgn (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return (a->count) ? a->sign : 0;
}

static int 
bigint_cmp (bigint_t a, bigint_t b, bigint_args args)
{
  assert (a != b && bigint_check (a, args) && bigint_check (b, args));
  return bigintdig_cmp (a->sign, a->digits, a->count, b->sign, b->digits, b->count);
}

static int 
bigint_numdigits (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_numdigits (a->digits, a->count);
}

static DIGIT 
bigint_digitat (bigint_t a, int i, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_digitat (a->digits, i, a->count);
}

static DIGIT 
bigint_lastdigit (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_lastdigit (a->digits, a->count);
}

static DIGIT 
bigint_firstdigit (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_firstdigit (a->digits, a->count);
}

static void 
bigint_insert (bigint_t a, DIGIT d, bigint_args args)
{
  assert (bigint_check (a, args));
  if (a->count == 0 && d == 0)
    {
      /* don't insert - keep leading digit nonzero */
    }
  else
    {
      while (a->count + 1 > a->capacity)
	bigint_expand (a);
      a->count = bigintdig_insert (a->digits, a->count, d);
    }
  assert (bigint_check (a, args));
}

static DIGIT 
bigint_remove (bigint_t a, bigint_args args)
{
  DIGIT d;
  assert (bigint_check (a, args));
  if (a->count)
    {
      d = bigintdig_lastdigit (a->digits, a->count);
      a->count = bigintdig_remove (a->digits, a->count);
    }
  else
    {
      d = 0;
    }
  assert (bigint_check (a, args));
  return d;
}

static int 
bigint_iszero (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return (a->count == 0);
}

static int 
bigint_isop (bigint_t a, bigint_t b, bigint_args args)
{
  assert (a != b && bigint_check (a, args) && bigint_check (b, args));
  return bigintdig_isop (a->sign, a->digits, a->count, b->sign, b->digits, b->count);
}

static void 
bigint_ooneg (bigint_c * c, bigint_t a, bigint_args args)
{
  bigint_copy (c, a, args);
  c->sign = -c->sign;
  assert (bigint_check (c, args));
}

static void 
bigint_inneg (bigint_c * c, bigint_args args)
{
  assert (bigint_check (c, args));
  c->sign = -c->sign;
  assert (bigint_check (c, args));
}

static void 
bigint_oodbl (bigint_c * c, bigint_t a, int v, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (c != a && bigint_check (a, args));
  bigintreg_oodbl (r0, a, v);
  bigint_store (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (a, args));

  bigintreg_free (r0);
}

static void 
bigint_indbl (bigint_c * c, int v, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (bigint_check (c, args));
  bigintreg_oodbl (r0, c, v);
  bigint_restore (c, r0, args);
  assert (bigint_check (c, args));

  bigintreg_free (r0);
}

static void 
bigint_ooadd (bigint_c * c, bigint_t a, int v, bigint_t b, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (a != b && bigint_check (a, args) && bigint_check (b, args));
  bigintreg_ooadd (r0, a, v, b, w);
  bigint_store (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (a, args) && bigint_check (b, args));

  bigintreg_free (r0);
}

static void 
bigint_inadd (bigint_c * c, int v, bigint_t b, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (c != b && bigint_check (c, args));
  bigintreg_ooadd (r0, c, v, b, w);
  bigint_restore (c, r0, args);
  assert (bigint_check (c, args));

  bigintreg_free (r0);
}

static void 
bigint_ooaddword (bigint_c * c, bigint_t a, int v, bigintwrd_t b, int w, bigint_args args)
{
  struct bigint tmp;
  assert (b != 0);

  tmp.sign = +1;
  tmp.count = 1;
  tmp.capacity = 1;
  tmp.digits = &b;
  bigint_ooadd (c, a, v, &tmp, w, args);
}

static void 
bigint_inaddword (bigint_c * c, int v, bigintwrd_t b, int w, bigint_args args)
{
  struct bigint tmp;
  assert (b != 0);

  tmp.sign = +1;
  tmp.count = 1;
  tmp.capacity = 1;
  tmp.digits = &b;
  bigint_inadd (c, v, &tmp, w, args);
}

static int 
bigint_isone (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_isone (a->sign, a->digits, a->count);
}

static int 
bigint_isminusone (bigint_t a, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_isminusone (a->sign, a->digits, a->count);
}

static void 
bigint_oosqr (bigint_c * c, bigint_t a, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (c != a && bigint_check (a, args));
  bigintreg_oomul (r0, a, a);
  bigint_store (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (a, args));

  bigintreg_free (r0);
}

static void 
bigint_insqr (bigint_c * c, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (bigint_check (c, args));
  bigintreg_oomul (r0, c, c);
  bigint_restore (c, r0, args);
  assert (bigint_check (c, args));

  bigintreg_free (r0);
}

static void 
bigint_oomul (bigint_c * c, bigint_t a, bigint_t b, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (a != b && bigint_check (a, args) && bigint_check (b, args));
  bigintreg_oomul (r0, a, b);
  bigint_store (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (a, args) && bigint_check (b, args));

  bigintreg_free (r0);
}

static void 
bigint_inmul (bigint_c * c, bigint_t b, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (c != b && bigint_check (c, args));
  bigintreg_oomul (r0, c, b);
  bigint_restore (c, r0, args);
  assert (bigint_check (c, args));

  bigintreg_free (r0);
}

static void 
bigint_oomulword (bigint_c * c, bigint_t a, bigintwrd_t b, bigint_args args)
{
  struct bigint tmp;
  assert (b != 0);

  tmp.sign = +1;
  tmp.count = 1;
  tmp.capacity = 1;
  tmp.digits = &b;
  bigint_oomul (c, a, &tmp, args);
}

static void 
bigint_inmulword (bigint_c * c, bigintwrd_t b, bigint_args args)
{
  struct bigint tmp;
  assert (b != 0);

  tmp.sign = +1;
  tmp.count = 1;
  tmp.capacity = 1;
  tmp.digits = &b;
  bigint_inmul (c, &tmp, args);
}

static void 
bigint_ooaddmul (bigint_c * c, bigint_t a, int v, bigint_t b, bigint_t t, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();
  bigintreg_t r1 = bigintreg_new ();

  assert (bigint_check (a, args) && bigint_check (b, args) && bigint_check (t, args));
  bigintreg_load (r0, a);
  bigintreg_oomul (r1, b, t);
  bigintreg_inadd (&r0, v, &r1, w);
  bigint_store (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (a, args) && bigint_check (b, args) && bigint_check (t, args));

  bigintreg_free (r0);
  bigintreg_free (r1);
}

static void 
bigint_inaddmul (bigint_c * c, int v, bigint_t b, bigint_t t, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();
  bigintreg_t r1 = bigintreg_new ();

  assert (bigint_check (c, args) && bigint_check (b, args) && bigint_check (t, args));
  bigintreg_load (r0, c);
  bigintreg_oomul (r1, b, t);
  bigintreg_inadd (&r0, v, &r1, w);
  bigint_restore (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (b, args) && bigint_check (t, args));

  bigintreg_free (r0);
  bigintreg_free (r1);
}

static void 
bigint_oomuladd (bigint_c * c, bigint_t a, bigint_t s, int v, bigint_t b, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();
  bigintreg_t r1 = bigintreg_new ();

  assert (bigint_check (a, args) && bigint_check (s, args) && bigint_check (b, args));
  bigintreg_oomul (r0, a, s);
  bigintreg_load (r1, b);
  bigintreg_inadd (&r0, v, &r1, w);
  bigint_store (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (a, args) && bigint_check (s, args) && bigint_check (b, args));

  bigintreg_free (r0);
  bigintreg_free (r1);
}

static void 
bigint_inmuladd (bigint_c * c, bigint_t s, int v, bigint_t b, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();
  bigintreg_t r1 = bigintreg_new ();

  assert (bigint_check (c, args) && bigint_check (s, args) && bigint_check (b, args));
  bigintreg_oomul (r0, c, s);
  bigintreg_load (r1, b);
  bigintreg_inadd (&r0, v, &r1, w);
  bigint_restore (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (s, args) && bigint_check (b, args));

  bigintreg_free (r0);
  bigintreg_free (r1);
}

static void 
bigint_oomuladdmul (bigint_c * c, bigint_t a, bigint_t s, int v, bigint_t b, bigint_t t, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();
  bigintreg_t r1 = bigintreg_new ();

  assert (bigint_check (a, args) && bigint_check (s, args));
  assert (bigint_check (b, args) && bigint_check (t, args));
  bigintreg_oomul (r0, a, s);
  bigintreg_oomul (r1, b, t);
  bigintreg_inadd (&r0, v, &r1, w);
  bigint_store (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (a, args));
  assert (bigint_check (s, args) && bigint_check (b, args) && bigint_check (t, args));

  bigintreg_free (r0);
  bigintreg_free (r1);
}

static void 
bigint_inmuladdmul (bigint_c * c, bigint_t s, int v, bigint_t b, bigint_t t, int w, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();
  bigintreg_t r1 = bigintreg_new ();

  assert (bigint_check (c, args) && bigint_check (s, args));
  assert (bigint_check (b, args) && bigint_check (t, args));
  bigintreg_oomul (r0, c, s);
  bigintreg_oomul (r1, b, t);
  bigintreg_inadd (&r0, v, &r1, w);
  bigint_restore (c, r0, args);
  assert (bigint_check (c, args) && bigint_check (s, args));
  assert (bigint_check (b, args) && bigint_check (t, args));

  bigintreg_free (r0);
  bigintreg_free (r1);
}

static void 
bigint_ooremquo (bigint_c * r, bigint_t a, bigint_t b, bigint_c * q, bigint_args args)
{
  bigintreg_t dvdd = bigintreg_new ();
  bigintreg_t dvsr = bigintreg_new ();
  bigintreg_t quot = bigintreg_new ();

  assert (bigint_check (a, args) && bigint_check (b, args));
  bigintreg_load (dvdd, a);
  bigintreg_load (dvsr, b);
  bigintreg_inremquo (dvdd, dvsr, quot);
  bigint_store (r, dvdd, args);
  bigint_store (q, quot, args);
  assert (bigint_check (r, args) && bigint_check (q, args));
  assert (bigint_check (a, args) && bigint_check (b, args));

  bigintreg_free (dvdd);
  bigintreg_free (dvsr);
  bigintreg_free (quot);
}

static void 
bigint_inremquo (bigint_c * a, bigint_t b, bigint_c * q, bigint_args args)
{
  bigintreg_t dvdd = bigintreg_new ();
  bigintreg_t dvsr = bigintreg_new ();
  bigintreg_t quot = bigintreg_new ();

  assert (bigint_check (a, args) && bigint_check (b, args));
  bigintreg_load (dvdd, a);
  bigintreg_load (dvsr, b);
  bigintreg_inremquo (dvdd, dvsr, quot);
  bigint_restore (a, dvdd, args);
  bigint_store (q, quot, args);
  assert (bigint_check (q, args));
  assert (bigint_check (a, args) && bigint_check (b, args));

  bigintreg_free (dvdd);
  bigintreg_free (dvsr);
  bigintreg_free (quot);
}

static void 
bigint_oorem (bigint_c * r, bigint_t a, bigint_t b, bigint_args args)
{
  bigintreg_t dvdd = bigintreg_new ();
  bigintreg_t dvsr = bigintreg_new ();

  assert (bigint_check (a, args) && bigint_check (b, args));
  bigintreg_load (dvdd, a);
  bigintreg_load (dvsr, b);
  bigintreg_inrem (dvdd, dvsr);
  bigint_store (r, dvdd, args);
  assert (bigint_check (r, args));
  assert (bigint_check (a, args) && bigint_check (b, args));

  bigintreg_free (dvdd);
  bigintreg_free (dvsr);
}

static void 
bigint_inrem (bigint_c * a, bigint_t b, bigint_args args)
{
  bigintreg_t dvdd = bigintreg_new ();
  bigintreg_t dvsr = bigintreg_new ();

  assert (bigint_check (a, args) && bigint_check (b, args));
  bigintreg_load (dvdd, a);
  bigintreg_load (dvsr, b);
  bigintreg_inrem (dvdd, dvsr);
  bigint_restore (a, dvdd, args);
  assert (bigint_check (a, args) && bigint_check (b, args));

  bigintreg_free (dvdd);
  bigintreg_free (dvsr);
}

static void 
bigint_ooquoremword (bigint_c * q, bigint_t a, bigintwrd_t b, bigintwrd_t * r, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (bigint_check (a, args));
  bigintreg_ooquoremword (r0, a, b, r);
  bigint_store (q, r0, args);
  assert (bigint_check (q, args) && bigint_check (a, args));
  assert (r == NULL || *r < b);

  bigintreg_free (r0);
}

static void 
bigint_inquoremword (bigint_c * q, bigintwrd_t b, bigintwrd_t * r, bigint_args args)
{
  bigintreg_t r0 = bigintreg_new ();

  assert (bigint_check (q, args));
  bigintreg_ooquoremword (r0, q, b, r);
  bigint_restore (q, r0, args);
  assert (bigint_check (q, args) && (r == NULL || *r < b));

  bigintreg_free (r0);
}

static bigintwrd_t 
bigint_remword (bigint_t a, bigintwrd_t b, bigint_args args)
{
  assert (bigint_check (a, args));
  return bigintdig_remword (a->digits, a->count, b);
}

static void 
bigint_fileout (id aFiler, bigint_c * a, bigint_args args)
{
  DIGIT *digits;
  int sign, count, i;
  assert (bigint_check (a, args));

  sign = a->sign;
  count = bigint_numdigits (a, args);
  digits = (DIGIT *) OC_MallocAtomic (sizeof (DIGIT) * count);
  bigint_extract (a, digits, count, args);

  [aFiler fileOut:&sign type:'i'];
  [aFiler fileOut:&count type:'i'];
  for (i = 0; i < count; i++)
    [aFiler fileOut:digits + i type:'S'];
  OC_Free (digits);
  assert (bigint_check (a, args));
}

static void 
bigint_filein (id aFiler, bigint_c * c, bigint_args args)
{
  DIGIT *digits;
  int sign, count, i;

  [aFiler fileIn:&sign type:'i'];
  [aFiler fileIn:&count type:'i'];
  digits = (DIGIT *) OC_MallocAtomic (sizeof (DIGIT) * count);
  for (i = 0; i < count; i++)
    [aFiler fileIn:digits + i type:'S'];
  bigint_create (c, sign, digits, count, args);
  OC_Free (digits);
}

@implementation BigInt
- check
{
  [super check];
  bigint_check (&value, bigint_getargs (self));
  return self;
}


- _setUpInteger
{
  bigint_oozero (&value, bigint_getargs (self));
  return self;
}

+ new
{
  return [[super new] _setUpInteger];
}
+ str:(STR)aString
{
  static id dummy = nil;
  if (!dummy)
    dummy = [self new];
  return [dummy str:aString];
}

+ int:(int)intValue
{
  static id dummy = nil;
  if (!dummy)
    dummy = [self new];
  return [dummy intValue:intValue];
}

- factorial:(int)n
{
  return [self notImplemented:_cmd];
}

+ factorial:(int)n
{
  if (n < 0 || n > 10000)
    {
      return [self error:"Be Reasonable"];
    }
  else
    {
      DIGIT i, m;
      unsigned long j;
      id fac = [self int:1];

      m = (DIGIT) n;

      for (i = 2; j = i * (i + 1), j < USHRT_MAX && i + 1 <= m; i += 2)
	{
	  fac = [fac multiplyDigit:j];
	}

      for (; i <= m; i++)
	fac = [fac multiplyDigit:i];

      return fac;
    }
}

+ fibonacci:(int)n
{
  [self notImplemented:_cmd];
  return nil;
}

- copy
{
  id copy = [super copy];
  bigint_copy ([copy bigint_reference], &value, bigint_getargs (self));
  return copy;
}

- deepCopy
{
  return [self copy];
}

- release
{
  bigint_clear (&value, bigint_getargs (self));
  return [super release];
}

- doempty
{
  bigint_oozero (&value, bigint_getargs (self));
  return self;
}

- empty
{
  return [[self clone] doempty];
}

- (bigint_t) bigint_value
{
  return &value;
}

- dobigint_value:(bigint_t)aValue
{
  bigint_copy (&value, aValue, bigint_getargs (self));
  return self;
}

- bigint_value:(bigint_t)aValue
{
  return [[self clone] dobigint_value:aValue];
}

- (bigint_t) bigint_reference
{
  return &value;
}

- dobigint_reference:(bigint_t)aReference
{
  bigint_move (&value, aReference, bigint_getargs (self));
  return self;
}

- bigint_reference:(bigint_t)aReference
{
  return [[self clone] dobigint_reference:aReference];
}

- (BOOL)sameClass:b			
{
  return isa == [b class];
}
- (BOOL)inAdditiveSemiGroup		
{
  return YES;
}
- (BOOL)inAdditiveMonoid		
{
  return YES;
}
- (BOOL)inAdditiveGroup			
{
  return YES;
}

- (BOOL)inSemiGroup			
{
  return YES;
}
- (BOOL)inMonoid			
{
  return YES;
}
- (BOOL)inGroup				
{
  return NO;
}

- (BOOL)inEuclideanDomain		
{
  return YES;
}
- (BOOL)inIntegralDomain		
{
  return YES;
}
- (BOOL)inField				
{
  return NO;
}

- (BOOL)inOrderedSet			
{
  return YES;
}
- (int)characteristic			
{
  return 0;
}

- class_vector
{
  return (id) [bigintobj_vector class];
}

- class_vardnsrecdegsps_polynomial
{
  return (id) [bigintobj_vardnsrecdegsps_polynomial class];
}

- class_vardnsrecdegdns_polynomial
{
  return (id) [bigintobj_vardnsrecdegdns_polynomial class];
}

- class_vardnsexpdegsps_polynomial
{
  return (id) [bigintobj_vardnsexpdegsps_polynomial class];
}


- (unsigned) hash
{
  return bigint_hash (bigint_id2t (self), bigint_getargs (self));
}

- (BOOL) isEqual:b
{
  [self checkSameClass:b];
  if (self == b)
    {
      return YES;
    }
  else
    {
      return bigint_iseq (bigint_id2t (self), bigint_id2t (b), bigint_getargs (self));
    }
}

- (BOOL) notEqual:b
{
  [self checkSameClass:b];
  if (self == b)
    {
      return NO;
    }
  else
    {
      return !bigint_iseq (bigint_id2t (self), bigint_id2t (b), bigint_getargs (self));
    }
}

- (int) numDigits
{
  return bigint_numdigits (&value, bigint_getargs (self));
}
- (BOOL) isDigit
{
  return bigint_numdigits (&value, bigint_getargs (self)) == 1;
}

- insertDigit:(DIGIT)d
{
  if ([self isZero] && d == 0)
    {
      return self;
    }
  else
    {
      bigint_insert (&value, d, bigint_getargs (self));
      return [self invalidate];
    }
}
- (DIGIT) removeDigit
{
  DIGIT d;

  if ([self isZero])
    {
      d = 0;
    }
  else
    {
      d = bigint_remove (&value, bigint_getargs (self));
      [self invalidate];
    }

  return d;
}

- (DIGIT) digitAt:(int)i
{
  return bigint_digitat (&value, i, bigint_getargs (self));
}
- (DIGIT) lastDigit
{
  return bigint_lastdigit (&value, bigint_getargs (self));
}
- (DIGIT) leadingDigit
{
  return bigint_firstdigit (&value, bigint_getargs (self));
}

static char *
getChars (id self, int *cref, DIGIT base)
{
  id copy;
  int count, capacity;
  DIGIT r;
  char *stack;

  copy = [self copy];
  assert (0 < base <= 10);
  count = 0;
  stack = (char *) OC_MallocAtomic (sizeof (char) * (capacity = 100));

  copy = [copy quotientDigit:base remainder:&r];
  stack [count++] = r + '0';

  while ([copy notZero])
    {
      copy = [copy quotientDigit:base remainder:&r];
      stack [count++] = r + '0';
      if (count == capacity)
	stack = (char *) OC_Realloc (stack, capacity *= 2);
    }

  *cref = count;
  return stack;
}

- (STR) str
{
  /* might use getChars here instead of going through printOn: */
  return [super str];
}
static id 
fromDigits (id self, STR aString)
{
  int c;
  id res = [self zero];
  assert (aString != NULL && isdigit (*aString));

  while ((c = *aString++))
    {
      if (isdigit (c))
	{
	  res = [[res multiplyDigit:10] addDigit:c - '0'];
	}
      else
	{
	  break;
	}
    }

  return res;
}

- str:(STR)aString
{
  if (aString)
    {
      int c, sign = +1;
      while ((c = *aString))
	{
	  if (c == '+')
	    {
	      sign = +sign;
	      aString++;
	      continue;
	    }
	  if (c == '-')
	    {
	      sign = -sign;
	      aString++;
	      continue;
	    }
	  if (c == ' ' || c == '\t')
	    {
	      aString++;
	      continue;
	    }
	  if (isdigit (c))
	    {
	      id res = fromDigits (self, aString);
	      return (sign == +1) ? res : [res negate];
	    }
	  else
	    {
	      return nil;
	    }
	}
      return nil;
    }
  else
    {
      return nil;
    }
}

- asNumerical
{
  return [Float floatValue:[self floatValue]];
}
- asModp:(unsigned short)p
{
  if ([self sign] < 0)
    {
      return [IntegerModp int:-[self remainderDigit:p] modulus:p];
    }
  else
    {
      return [IntegerModp int:+[self remainderDigit:p] modulus:p];
    }
}
- (DIGIT) digitValue
{
  return [self lastDigit];
}
- digitValue:(DIGIT)aValue
{
  return [[self empty] insertDigit:aValue];
}
- (unsigned long) ulongValue
{
  if ([self numDigits] < 2)
    {
      return [self digitValue];
    }
  else
    {
      DIGIT d0 = [self digitAt:0];
      DIGIT d1 = [self digitAt:1];
      return d0 + (d1 << (CHAR_BIT * sizeof (DIGIT)));
    }
}
- ulongValue:(unsigned long)aValue
{
  id res;
  DIGIT d0 = aValue;
  DIGIT d1 = aValue >> (CHAR_BIT * sizeof (DIGIT));

  res = [self empty];
  if (d1)
    [res insertDigit:d1];
  if (d1 || d0)
    [res insertDigit:d0];
  return res;
}
- (int) intValue
{
  if ([self numDigits] <= 2)
    {
      unsigned long u = [self ulongValue];

      if ([self sign] < 0)
	{
	  return (u < INT_MAX) ? -u : INT_MIN;
	}
      else
	{
	  return (u < INT_MAX) ? +u : INT_MAX;
	}
    }
  else
    {
      return ([self sign] < 0) ? INT_MIN : INT_MAX;
    }
}

- intValue:(int)aValue
{
  id res;

  if (aValue < 0)
    {
      res = [[self ulongValue:-aValue] negate];
    }
  else
    {
      res = [self ulongValue:aValue];
    }

  return res;
}

- (double) doubleValue
{
  int i, numDigits;
  double doubleValue = 0.0;
  double bound = DBL_MAX / 2.0;

  for (numDigits = [self numDigits], i = numDigits - 1; i >= 0; i--)
    {
      DIGIT mask = (USHRT_MAX + 1) >> 1;
      DIGIT digit = [self digitAt:i];
      while (mask)
	{
	  if (doubleValue >= bound)
	    return ([self sign] < 0) ? DBL_MIN : DBL_MAX;
	  doubleValue *= 2.0;
	  if (mask & digit)
	    doubleValue += 1.0;
	  mask >>= 1;
	}
    }

  return [self sign] * doubleValue;
}

- (float) floatValue
{
  int i, numDigits;
  float floatValue = 0.0;
  float bound = FLT_MAX / 2.0;

  for (numDigits = [self numDigits], i = numDigits - 1; i >= 0; i--)
    {
      DIGIT mask = (USHRT_MAX + 1) >> 1;
      DIGIT digit = [self digitAt:i];
      while (mask)
	{
	  if (floatValue >= bound)
	    return ([self sign] < 0) ? FLT_MIN : FLT_MAX;
	  floatValue *= 2.0;
	  if (mask & digit)
	    floatValue += 1.0;
	  mask >>= 1;
	}
    }

  return [self sign] * floatValue;
}


- (int) sign
{
  return bigint_sgn (bigint_id2t (self), bigint_getargs (self));
}

- (int) compare:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return 0;
    }
  else
    {
      return bigint_cmp (bigint_id2t (self), bigint_id2t (b), bigint_getargs (self));
    }
}

- zero
{
  static id zero = nil;

  if (zero == nil)
    zero = [self intValue:0];

  return zero;
}

- (BOOL) isZero
{
  assert ([self check]);
  return bigint_iszero (bigint_id2t (self), bigint_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return NO == bigint_iszero (bigint_id2t (self), bigint_getargs (self));
}

- (BOOL) isOpposite:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self isZero] || [self isCharacteristicTwo];
    }
  else
    {
      return bigint_isop (bigint_id2t (self), bigint_id2t (b), bigint_getargs (self));
    }
}

- (BOOL) notOpposite:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self notZero] && [self notCharacteristicTwo];
    }
  else
    {
      return NO == bigint_isop (bigint_id2t (self), bigint_id2t (b), bigint_getargs (self));
    }
}

- negate
{
  if ([self isZero] || [self isCharacteristicTwo])
    {
      return self;
    }
  else
    {
      bigint_c c;
      assert ([self check]);
      bigint_ooneg (&c, bigint_id2t (self), bigint_getargs (self));
      return bigint_c2id (self, &c);
    }
}

- _double:(int)v
{
  if ([self isZero] || [self isCharacteristicTwo])
    {
      return [self zero];
    }
  else
    {
      bigint_c c;
      assert ([self check]);
      bigint_oodbl (&c, bigint_id2t (self), v, bigint_getargs (self));
      return bigint_c2id (self, &c);
    }
}

- double
{
  if ([self isZero] || [self isCharacteristicTwo])
    {
      return [self zero];
    }
  else
    {
      bigint_c c;
      assert ([self check]);
      bigint_oodbl (&c, bigint_id2t (self), +1, bigint_getargs (self));
      return bigint_c2id (self, &c);
    }
}

- _add:(int)v:b:(int)w
{
  assert ([self sameClass:b] && v * v == 1 && w * w == 1);

  if (self == b)
    {
      return (v == w) ? [self _double : v]:[self zero];
    }
  else
    {
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero])
	    return [b _negate:w];
	  if ([b isZero])
	    return [self _negate:v];
	}
      if (1)
	{
	  bigint_c c;
	  bigint_ooadd (&c, bigint_id2t (self), v, bigint_id2t (b), w, bigint_getargs (self));
	  return bigint_c2id (self, &c);
	}
    }

  return nil;			/* to quiet some compilers, e.g. WATCOM */
}

- add:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self double];
    }
  else
    {
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero])
	    return b;
	  if ([b isZero])
	    return self;
	}
      if (1)
	{
	  bigint_c c;
	  bigint_ooadd (&c, bigint_id2t (self), +1, bigint_id2t (b), +1, bigint_getargs (self));
	  return bigint_c2id (self, &c);
	}
    }

  return nil;
}

- subtract:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self zero];
    }
  else
    {
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero])
	    return [b negate];
	  if ([b isZero])
	    return self;
	}
      if (1)
	{
	  bigint_c c;
	  bigint_ooadd (&c, bigint_id2t (self), +1, bigint_id2t (b), -1, bigint_getargs (self));
	  return bigint_c2id (self, &c);
	}
    }

  return nil;
}

- addDigit:(DIGIT)d
{
  bigint_c c;
  if (d == 0)
    return self;
  if ([self isZero])
    return [self digitValue:d];
  bigint_ooaddword (&c, &value, +1, d, +1, bigint_getargs (self));
  return [self bigint_reference:&c];
}

- subtractDigit:(DIGIT)d
{
  bigint_c c;
  if (d == 0)
    return self;
  if ([self isZero])
    return [[self digitValue:d] negate];
  bigint_ooaddword (&c, &value, +1, d, -1, bigint_getargs (self));
  return [self bigint_reference:&c];
}


- one
{
  static id one = nil;

  if (one == nil)
    one = [self intValue:1];

  return one;
}

- minusOne
{
  static id minusOne = nil;

  if (minusOne == nil)
    minusOne = [self intValue:-1];

  return minusOne;
}

- _add:(int)v:B multiply:b:(int)w
{
  assert ([self sameClass:B] && [self sameClass:b] && v * v == 1 && w * w == 1);

  if ([self isZero])
    return [B _multiply:b:+w];
  if ([B isZero])
    return [self _negate:v];
  if ([b isZero])
    return [self _negate:v];

  if ([b isOne])
    return [self _add:v:B:+w];
  if ([B isOne])
    return [self _add:v:b:+w];
  if ([b isMinusOne])
    return [self _add:v:B:-w];
  if ([B isMinusOne])
    return [self _add:v:b:-w];

  if (1)
    {
      bigint_c c;
      bigint_ooaddmul (&c, bigint_id2t (self), v, bigint_id2t (B), bigint_id2t (b), w, bigint_getargs (self));
      return bigint_c2id (self, &c);
    }

  return nil;
}

- _multiply:a:(int)v add:B:(int)w
{
  assert ([self sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);

  if ([self isZero])
    return [B _negate:+w];
  if ([a isZero])
    return [B _negate:+w];
  if ([B isZero])
    return [self _multiply:a:+v];

  if ([self isOne])
    return [a _add:+v:B:+w];
  if ([a isOne])
    return [self _add:+v:B:+w];
  if ([self isMinusOne])
    return [a _add:-v:B:+w];
  if ([a isMinusOne])
    return [self _add:-v:B:+w];

  if (1)
    {
      bigint_c c;
      bigint_oomuladd (&c, bigint_id2t (self), bigint_id2t (a), v, bigint_id2t (B), w, bigint_getargs (self));
      return bigint_c2id (self, &c);
    }

  return nil;
}

- _multiply:a:(int)v add:B multiply:b:(int)w
{
  assert ([self sameClass:a] && [self sameClass:B] && [self sameClass:b] && v * v == 1 && w * w == 1);

  if ([self isZero])
    return [B _multiply:b:+w];
  if ([a isZero])
    return [B _multiply:b:+w];
  if ([B isZero])
    return [self _multiply:a:+v];
  if ([b isZero])
    return [self _multiply:a:+v];

  if ([self isOne])
    return [a _add:+v:B multiply:b:+w];
  if ([a isOne])
    return [self _add:+v:B multiply:b:+w];
  if ([b isOne])
    return [self _multiply:a:+v add:B:+w];
  if ([B isOne])
    return [self _multiply:a:+v add:b:+w];

  if ([self isMinusOne])
    return [a _add:-v:B multiply:b:+w];
  if ([a isMinusOne])
    return [self _add:-v:B multiply:b:+w];
  if ([b isMinusOne])
    return [self _multiply:a:+v add:B:-w];
  if ([B isMinusOne])
    return [self _multiply:a:+v add:b:-w];

  if (1)
    {
      bigint_c c;
      bigint_oomuladdmul (&c, bigint_id2t (self), bigint_id2t (a), v, bigint_id2t (B), bigint_id2t (b), w, bigint_getargs (self));
      return bigint_c2id (self, &c);
    }

  return nil;
}

- (BOOL) isOne
{
  assert ([self check]);
  return bigint_isone (bigint_id2t (self), bigint_getargs (self));
}

- (BOOL) notOne
{
  assert ([self check]);
  return NO == bigint_isone (bigint_id2t (self), bigint_getargs (self));
}

- (BOOL) isMinusOne
{
  assert ([self check]);
  return bigint_isminusone (bigint_id2t (self), bigint_getargs (self));
}

- (BOOL) notMinusOne
{
  assert ([self check]);
  return NO == bigint_isminusone (bigint_id2t (self), bigint_getargs (self));
}

- square
{
  bigint_c c;

  if ([self inMonoid] && [self isOne])
    return self;
  if ([self inAdditiveMonoid])
    {
      if ([self isMinusOne])
	return [self one];
      if ([self isZero])
	return self;
    }

  assert ([self check]);
  bigint_oosqr (&c, bigint_id2t (self), bigint_getargs (self));
  return bigint_c2id (self, &c);
}

- multiply:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self square];
    }
  else
    {
      bigint_c c;
      if ([self inMonoid])
	{
	  if ([self isOne])
	    return b;
	  if ([b isOne])
	    return self;
	}
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero] || [b isZero])
	    return [self zero];
	  if ([self isMinusOne])
	    return [b negate];
	  if ([b isMinusOne])
	    return [self negate];
	}
      bigint_oomul (&c, bigint_id2t (self), bigint_id2t (b), bigint_getargs (self));
      return bigint_c2id (self, &c);
    }
}

- multiplyDigit:(DIGIT)d
{
  bigint_c c;

  if (d == 0)
    return [self zero];
  if (d == 1)
    return [self negate];
  if (d == 2)
    return [self double];

  if ([self isZero])
    return [self zero];
  if ([self isOne])
    return [self digitValue:d];
  if ([self isMinusOne])
    return [[self digitValue:d] negate];

  bigint_oomulword (&c, &value, d, bigint_getargs (self));
  return [self bigint_reference:&c];
}

- inverse
{
  return ([self isOne] || [self isMinusOne]) ? self : nil;
}


- divide:b
{
  if ([b isZero])
    return nil;
  if (self == b)
    return [self one];
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  if ([b isDigit])
    {
      id q = [self divideDigit:[b digitValue]];
      return ([b sign] > 0) ? q : [q negate];
    }
  else
    {
      id q, r;
      r = [self remainder:b quotient:&q];
      if ([r notZero])
	{
	  return nil;
	}
      else
	{
	  return q;
	}
    }
}
- divideDigit:(DIGIT)b
{
  DIGIT r;
  id q;

  if (b == 0)
    return nil;
  if (b == +1)
    return self;

  q = [self quotientDigit:b remainder:&r];
  if (r)
    {
      return nil;
    }
  else
    {
      return q;
    }
}

- quotientDigit:(DIGIT)b
{
  return [self quotientDigit:b remainder:NULL];
}
- remainder:b quotient:(id *)q
{
  if ([b isZero])
    return nil;
  if ([b isOne])
    {
      if (q)
	*q = self;
      return [self zero];
    }
  if ([b isMinusOne])
    {
      if (q)
	*q = [self negate];
      return [self zero];
    }

  if ([self isZero])
    {
      if (q)
	*q = [self zero];
      return [self zero];
    }

  if (q)
    {
      bigint_c c, d;
      bigint_ooremquo (&c, &value, [b bigint_value], &d, bigint_getargs (self));
      *q = [self bigint_reference:&d];
      return [self bigint_reference:&c];
    }
  else
    {
      bigint_c c;
      bigint_oorem (&c, &value, [b bigint_value], bigint_getargs (self));
      return [self bigint_reference:&c];
    }
}

- quotientDigit:(DIGIT)d remainder:(DIGIT *)r
{
  bigint_c q;

  if (d == 0)
    return nil;
  if (d == 1)
    {
      if (r)
	*r = 0;
      return self;
    }
  if ([self isZero])
    {
      if (r)
	*r = 0;
      return [self zero];
    }

  if (r)
    {
      bigintwrd_t rw;
      bigint_ooquoremword (&q, &value, d, &rw, bigint_getargs (self));
      assert (rw <= d);
      *r = rw;
    }
  else
    {
      bigint_ooquoremword (&q, &value, d, NULL, bigint_getargs (self));
    }

  return [self bigint_reference:&q];
}

- (DIGIT) remainderDigit:(DIGIT)d
{
  if (d == 0)
    [self error:"Division by Zero"];
  if (d == 1)
    return 0;

  return bigint_remword (&value, d, bigint_getargs (self));
}

- (BOOL) isEven
{
  return (EVEN ([self lastDigit]));
}

- (BOOL) isOdd
{
  return (ODD ([self lastDigit]));
}


- gcd:b
{
  if (self == b)
    return self;
  if ([self isZero])
    return b;
  if ([b isZero])
    return self;

  if ([b isDigit])
    {
      DIGIT u, v;
      u = [self remainderDigit:v = [b digitValue]];
      while (v)
	{
	  DIGIT t = u % v;
	  u = v;
	  v = t;
	}
      return [self digitValue:u];
    }
  else
    {
      id a = [self copy];
      b = [b copy];
      while ([b notZero])
	{
	  id t = [a remainder:b];
	  a = b;
	  b = t;
	}
      return a;
    }
}


- (BOOL) printsLeadingSign
{
  return [self sign] < 0;
}

- printOn:(IOD)aFile
{
  if ([self isZero])
    {
      fprintf (aFile, "0");
    }
  else
    {
      char *stack;
      int n;
      if ([self sign] < 0)
	fprintf (aFile, "-");
      stack = getChars (self, &n, 10);
      while (n--)
	fprintf (aFile, "%c", stack [n]);
      OC_Free (stack);
    }

  return self;
}


- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  bigint_fileout (aFiler, &value, bigint_getargs (self));
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  bigint_filein (aFiler, &value, bigint_getargs (self));
  return self;
}

@end
 
