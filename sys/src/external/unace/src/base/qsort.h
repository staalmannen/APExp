#ifndef _BASE_QSORT_H_INCLUDED
#define _BASE_QSORT_H_INCLUDED

#include "base/cprdcpr/huff.h"

typedef struct
{
        INT     Hyphen;
        USHORT  Elements   [BASE_CPRDCPR_HUFF_MAXCODE + 2],
                Frequencies[(BASE_CPRDCPR_HUFF_MAXCODE + 2) * 2];
} tBASE_QSORT;

extern tBASE_QSORT BASE_QSORT;

void    BASE_QSORT_SortRange(INT Left, INT Right);
void    BASE_QSORT_DoQuicksort(INT Elements);
void    BASE_QSORT_XchgElements(PUSHORT Var1, PUSHORT Var2);

#endif
