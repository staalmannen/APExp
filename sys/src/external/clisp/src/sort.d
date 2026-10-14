/*
 * n log(n) - Sort function for CLISP
 * Bruno Haible 1992-2003
 * German comments and names translated into English: Reini Urban 2007-12

 Goal: Sort a fixed number n of elements,
 with maximal time costs of O(n log(n)),
 without needing too many and expensive data structures.

 Requires these predefinitions:
  Identifier SORTID :
    Identifier, identifies the incarnation of the Package
  Type SORT_ELEMENT :
    Type of the to be sorted elements.
  Type SORT_KEY :
    Type of the key, by which we sort.
  Function SORT_KEYOF, with signature
    local SORT_KEY SORT_KEYOF (SORT_ELEMENT element);
    returns the sort-key of an element.
  Function SORT_COMPARE, with signature
    local signean SORT_COMPARE (SORT_KEY key1, SORT_KEY key2);
    returns >0 if key1>key2, <0 if key1<key2, 0 if key1=key2.
  Function SORT_LESS, with
    local bool SORT_LESS (SORT_KEY key1, SORT_KEY key2);
    returns true if key1<key2, false if key1>=key2.
*/

#ifndef SORT
  /* Some kind of "SORT-Package" */
  #define SORT(incarnation,identifier)  CONCAT4(sort_,incarnation,_,identifier)
#endif

/* Source: Samuel P. Harbison, Guy L. Steele: C - A Reference Manual, p.61 */

/* Detect, if element1 < element2: */
#define less(element1,element2)                                 \
  SORT_LESS(SORT_KEYOF(element1),SORT_KEYOF(element2))

/* sort(v,n); sorts the array v[0]..v[n-1] in ascending order. */
local void SORT(SORTID,sort) (SORT_ELEMENT* v, uintL n)
{
  var SORT_ELEMENT* w = &v[-1];
  /* w[1]..w[n] point to the same elements as v[0]..v[n-1] .
     We collect the numbers 1,...,n to a balanced binary subtree,
     so that k has the children 2*k and 2*k+1.
     A part w[r]..w[s] is sorted, if for all k with r <= k <= s counts:
        If 2*k <= s, then w[k] >= w[2*k], and
        if 2*k+1 <= s, then w[k] >= w[2*k+1],
     i.e. if every element has a value >= the value of both of its children.
     Subgoal:
        Let 0<r<=s and w[r+1]..w[s] already sorted.
        Sort w[r]..w[s].
        Time cost: max. O(log(s)). */
 #define adjust(r,s)                                                     \
  { var uintL i = r;                                                    \
    while (1) { /* Put w[i] into the subtree below i */                 \
      var uintL j = 2*i; /* a child of i */                             \
      if (j > s) /* 2*i and 2*i+1 not existent anymore -> ready */      \
        break;                                                          \
      if ((j < s) && less(w[j],w[j+1])) /* evtl. j = 2*i+1, the other child of i */ \
        j++;                                                            \
      /* j is the child of i with the greater value */                  \
      if (less(w[i],w[j])) {            /* if w[i] < w[j], */           \
        swap(SORT_ELEMENT, w[i], w[j]); /* swap w[i] and w[j] */        \
      }                                                                 \
      /* w[i] is now the greatest of the three values w[i],w[2*i],w[2*i+1]. \
         But we lowered w[j], so we need a tail-rexursive adjust(j,s) */ \
      i = j;                                                            \
    }                                                                   \
  }
  if (n<=1) /* nothing to do? */
    return;
  { /* Because of 2*(floor(n/2)+1) > n,
       w[floor(n/2)+1]..w[n] is already sorted. */
    var uintL r;
    for (r = floor(n,2); r>0; r--) {
      /* Here w[r+1]..w[n] is sorted. */
      adjust(r,n);
      /* Here w[r]..w[n] is sorted. */
    }
  }
  { /* Now w[1]..w[n] is a sorted tree.
     Take the actual top element w[1] and put it to the end: */
    var uintL s;
    for (s = n-1; s>0; s--) {
      /* Here w[1]..w[s+1] is a sorted tree, and
         w[s+2]..w[n] the greatest elements, sorted ascending. */
      swap(SORT_ELEMENT, v[0], v[s]); /* swap w[1] and w[s+1] */
      /* Here w[2]..w[s] is a sorted tree, and
         w[s+1]..w[n] the greatest elements, sorted ascending. */
      adjust(1,s); /* Sort w[1] into the tree */
      /* Here w[1]..w[s] ein sortierter Baum, und
         w[s+1]..w[n] the greatest elements, sorted ascending. */
    }
  }
}

#undef adjust
#undef less
