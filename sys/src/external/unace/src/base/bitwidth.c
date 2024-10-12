#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_BITWIDTH

#include "base/includes.h"

tBASE_BITWIDTH BASE_BITWIDTH;

/*-----------------BASE_BITWIDTH_Init------------------------------------*/

void    BASE_BITWIDTH_Init(void)
{
INT       I,
          K,
          J;

  I   =
    K = 0;

  J = 1;

  do
  {
    if (I == J)
    {
      K++;
      J <<= 1;
    }

    BASE_BITWIDTH.BitWidthArray[I++] = K;
  }
  while (I < BASE_CPRDCPR_LZ77_MAXDIST2);

  for (I = -128; I <= 127; I++)
  {
    if (I < 0)
    {
      BASE_BITWIDTH.DifBitWidthArray[(UCHAR) I] =
        BASE_BITWIDTH.BitWidthArray[-2*I - 1];
    }
    else
    {
      BASE_BITWIDTH.DifBitWidthArray[(UCHAR) I] =
        BASE_BITWIDTH.BitWidthArray[2*I];
    }
  }
}

/*-----------------BASE_BITWIDTH_GetBitWidth-----------------------------*/

INT     BASE_BITWIDTH_GetBitWidth(INT Value)
{
  return Value < BASE_CPRDCPR_LZ77_MAXDIST2 ?
           BASE_BITWIDTH.BitWidthArray[Value] :
           BASE_BITWIDTH.BitWidthArray[Value >> BASE_CPRDCPR_LZ77_MAXDICBITS2]
             + BASE_CPRDCPR_LZ77_MAXDICBITS2;
}
