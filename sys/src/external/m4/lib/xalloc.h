/* xalloc.h -- malloc with out-of-memory checking

   Copyright (C) 1990-2000, 2003-2004, 2006-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#ifndef XALLOC_H_
#define XALLOC_H_

#include <stddef.h>
#include <stdint.h>

#if GNULIB_XALLOC
# include "idx.h"
# include "intprops.h"
#endif

extern void *reallocarray(void *, size_t, size_t);

#ifndef _GL_INLINE_HEADER_BEGIN
 #error "Please include config.h first."
#endif
_GL_INLINE_HEADER_BEGIN
#ifndef XALLOC_INLINE
# define XALLOC_INLINE _GL_INLINE
#endif


#ifdef __cplusplus
extern "C" {
#endif


#if GNULIB_XALLOC_DIE

/* This function is always triggered when memory is exhausted.
   It must be defined by the application, either explicitly
   or by using gnulib's xalloc-die module.  This is the
   function to call when one wants the program to die because of a
   memory allocation failure.  */
/*extern*/ _Noreturn void xalloc_die (void);

#endif /* GNULIB_XALLOC_DIE */

#if GNULIB_XALLOC

void *xmalloc (size_t s)
      _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_ALLOC_SIZE ((1));
void *xzalloc (size_t s)
      _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_ALLOC_SIZE ((1));
void *xcalloc (size_t n, size_t s)
      _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_ALLOC_SIZE ((1, 2));
void *xrealloc (void *p, size_t s)
      _GL_ATTRIBUTE_ALLOC_SIZE ((2));
void *xreallocarray (void *p, size_t n, size_t s)
      _GL_ATTRIBUTE_ALLOC_SIZE ((2, 3));
void *x2realloc (void *p, size_t *pn);
void *xpalloc (void *pa, idx_t *nitems, idx_t nitems_incr_min,
               ptrdiff_t nitems_max, idx_t item_size);
void *xmemdup (void const *p, size_t s)
      _GL_ATTRIBUTE_ALLOC_SIZE ((2));
char *xstrdup (char const *str)
      _GL_ATTRIBUTE_MALLOC;

/* In the following macros, T must be an elementary or structure/union or
   typedef'ed type, or a pointer to such a type.  To apply one of the
   following macros to a function pointer or array type, you need to typedef
   it first and use the typedef name.  */

/* Allocate an object of type T dynamically, with error checking.  */
/* extern t *XMALLOC (typename t); */
# define XMALLOC(t) ((t *) xmalloc (sizeof (t)))

/* Allocate memory for N elements of type T, with error checking.  */
/* extern t *XNMALLOC (size_t n, typename t); */
# define XNMALLOC(n, t) \
    ((t *) (sizeof (t) == 1 ? xmalloc (n) : xnmalloc (n, sizeof (t))))

/* Allocate an object of type T dynamically, with error checking,
   and zero it.  */
/* extern t *XZALLOC (typename t); */
# define XZALLOC(t) ((t *) xzalloc (sizeof (t)))

/* Allocate memory for N elements of type T, with error checking,
   and zero it.  */
/* extern t *XCALLOC (size_t n, typename t); */
# define XCALLOC(n, t) \
    ((t *) (sizeof (t) == 1 ? xzalloc (n) : xcalloc (n, sizeof (t))))


/* Allocate an array of N objects, each with S bytes of memory,
   dynamically, with error checking.  S must be nonzero.  */

XALLOC_INLINE void *xnmalloc (size_t n, size_t s)
                    _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_ALLOC_SIZE ((1, 2));
XALLOC_INLINE void *
xnmalloc (size_t n, size_t s)
{
  return xreallocarray (NULL, n, s);
}

/* FIXME: Deprecate this in favor of xreallocarray?  */
/* Change the size of an allocated block of memory P to an array of N
   objects each of S bytes, with error checking.  S must be nonzero.  */

XALLOC_INLINE void *xnrealloc (void *p, size_t n, size_t s)
                    _GL_ATTRIBUTE_ALLOC_SIZE ((2, 3));
XALLOC_INLINE void *
xnrealloc (void *p, size_t n, size_t s)
{
  return xreallocarray (p, n, s);
}

/* If P is null, allocate a block of at least *PN such objects;
   otherwise, reallocate P so that it contains more than *PN objects
   each of S bytes.  S must be nonzero.  Set *PN to the new number of
   objects, and return the pointer to the new block.  *PN is never set
   to zero, and the returned pointer is never null.

   Repeated reallocations are guaranteed to make progress, either by
   allocating an initial block with a nonzero size, or by allocating a
   larger block.

   In the following implementation, nonzero sizes are increased by a
   factor of approximately 1.5 so that repeated reallocations have
   O(N) overall cost rather than O(N**2) cost, but the
   specification for this function does not guarantee that rate.

   Here is an example of use:

     int *p = NULL;
     size_t used = 0;
     size_t allocated = 0;

     void
     append_int (int value)
       {
         if (used == allocated)
           p = x2nrealloc (p, &allocated, sizeof *p);
         p[used++] = value;
       }

   This causes x2nrealloc to allocate a block of some nonzero size the
   first time it is called.

   To have finer-grained control over the initial size, set *PN to a
   nonzero value before calling this function with P == NULL.  For
   example:

     int *p = NULL;
     size_t used = 0;
     size_t allocated = 0;
     size_t allocated1 = 1000;

     void
     append_int (int value)
       {
         if (used == allocated)
           {
             p = x2nrealloc (p, &allocated1, sizeof *p);
             allocated = allocated1;
           }
         p[used++] = value;
       }

   */

XALLOC_INLINE void *
x2nrealloc (void *p, size_t *pn, size_t s)
{
  size_t n = *pn;

  if (! p)
    {
      if (! n)
        {
          /* The approximate size to use for initial small allocation
             requests, when the invoking code specifies an old size of
             zero.  This is the largest "small" request for the GNU C
             library malloc.  */
          enum { DEFAULT_MXFAST = 64 * sizeof (size_t) / 4 };

          n = DEFAULT_MXFAST / s;
          n += !n;
        }
    }
  else
    {
      /* Set N = floor (1.5 * N) + 1 to make progress even if N == 0.  */
      if (INT_ADD_WRAPV (n, (n >> 1) + 1, &n))
        xalloc_die ();
    }

  p = xreallocarray (p, n, s);
  *pn = n;
  return p;
}

/* Return a pointer to a new buffer of N bytes.  This is like xmalloc,
   except it returns char *.  */

XALLOC_INLINE char *xcharalloc (size_t n)
                    _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_ALLOC_SIZE ((1));
XALLOC_INLINE char *
xcharalloc (size_t n)
{
  return XNMALLOC (n, char);
}

#endif /* GNULIB_XALLOC */


#ifdef __cplusplus
}
#endif


#if GNULIB_XALLOC && defined __cplusplus

/* C++ does not allow conversions from void * to other pointer types
   without a cast.  Use templates to work around the problem when
   possible.  */

template <typename T> inline T *
xrealloc (T *p, size_t s)
{
  return (T *) xrealloc ((void *) p, s);
}

template <typename T> inline T *
xreallocarray (T *p, size_t n, size_t s)
{
  return (T *) xreallocarray ((void *) p, n, s);
}

/* FIXME: Deprecate this in favor of xreallocarray?  */
template <typename T> inline T *
xnrealloc (T *p, size_t n, size_t s)
{
  return xreallocarray (p, n, s);
}

template <typename T> inline T *
x2realloc (T *p, size_t *pn)
{
  return (T *) x2realloc ((void *) p, pn);
}

template <typename T> inline T *
x2nrealloc (T *p, size_t *pn, size_t s)
{
  return (T *) x2nrealloc ((void *) p, pn, s);
}

template <typename T> inline T *
xmemdup (T const *p, size_t s)
{
  return (T *) xmemdup ((void const *) p, s);
}

#endif /* GNULIB_XALLOC && C++ */


_GL_INLINE_HEADER_END

#endif /* !XALLOC_H_ */
