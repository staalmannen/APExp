#ifndef _BASE_BITWIDTH_H_INCLUDED
#define _BASE_BITWIDTH_H_INCLUDED

#include "base/dcpr/lz77.h"

typedef struct
{
        UCHAR   BitWidthArray[BASE_CPRDCPR_LZ77_MAXDIST2];
        UCHAR   DifBitWidthArray[256];
} tBASE_BITWIDTH;

extern tBASE_BITWIDTH BASE_BITWIDTH;

void    BASE_BITWIDTH_Init(void);
INT     BASE_BITWIDTH_GetBitWidth(INT Value);
#endif
