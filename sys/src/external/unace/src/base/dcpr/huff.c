#include <string.h>

#define INCL_BASE_DCPR_HUFF

#define INCL_BASE_DCPR
#define INCL_BASE_MEMORY
#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_QSORT

#include "base/includes.h"


/*-----------------BASE_DCPR_HUFF_MakeCode-------------------------------*/

INT     BASE_DCPR_HUFF_MakeCodes(UINT MaxWidth, UINT TabSize,
                                 PUSHORT Widths, PUSHORT Codes)
{
UINT      NumCodes;
INT       Code,
          CodePos,
          I,
          MaxCodePos,
          ActualSize;

  memcpy(&BASE_QSORT.Frequencies, Widths, (TabSize + 1) * sizeof(SHORT));

  if (TabSize)
  {
    BASE_QSORT_DoQuicksort(TabSize);
  }
  else
  {
    BASE_QSORT.Elements[0] = 0;
  }

  BASE_QSORT.Frequencies[TabSize + 1] =
      ActualSize                     =
      CodePos                        = 0;

  while (BASE_QSORT.Frequencies[ActualSize])
  {
    ActualSize++;
  }

  if (ActualSize < 2)
  {
    Widths[BASE_QSORT.Elements[0]] = 1;
    ActualSize += (ActualSize == 0);
  }

  ActualSize--;

  MaxCodePos = 1 << MaxWidth;

  for (I = ActualSize; I >= 0 && CodePos < MaxCodePos; I--)
  {
    NumCodes = 1 << (MaxWidth - BASE_QSORT.Frequencies[I]);
    Code     = BASE_QSORT.Elements[I];

    if (CodePos + NumCodes > MaxCodePos)
    {
      I = (BASE_DCPR_LZ77.BLOCK_BufSize - BASE_DCPR_LZ77.BLOCK_ByteCount);

      if (BASE_DCPR_LZ77.DictionaryPos + I > BASE_DCPR_LZ77.DictionarySize)
      {
        I = BASE_DCPR_LZ77.DictionarySize - BASE_DCPR_LZ77.DictionaryPos;
      }

      memset(&BASE_DCPR_LZ77.Dictionary[BASE_DCPR_LZ77.DictionaryPos], 0, I);

      memset(BASE_DCPR_LZ77.Dictionary, 0,
             (BASE_DCPR_LZ77.BLOCK_BufSize - BASE_DCPR_LZ77.BLOCK_ByteCount) - I);

      BASE_DCPR_LZ77.BLOCK_ByteCount = BASE_DCPR_LZ77.BLOCK_BufSize;

      return 0;
    }

    BASE_MEMORY_MemSet16(&Codes[CodePos], Code, NumCodes);
    CodePos += NumCodes;
  }

  return 1;
}

/*-----------------BASE_DCPR_HUFF_ReadWidths-----------------------------*/

INT     BASE_DCPR_HUFF_ReadWidths(UINT MaxWidth, PUSHORT Codes,
                                  PUSHORT Widths, UINT MaxSize)
{
UINT      Code,
          I,
          WidthPos,
          NumWidths,
          Len,
          UpperWidth,
          LowerWidth;

  memset(Widths, 0, MaxSize * sizeof(SHORT));
  memset(Codes , 0, (1 << MaxWidth) * sizeof(SHORT));

  NumWidths = BASE_DCPR.ReadCode >> (32 - 9);
  BASE_DCPR_AddBits(9);

  if (NumWidths > MaxSize)
  {
    NumWidths = MaxSize;
  }

  LowerWidth = BASE_DCPR.ReadCode >> (32 - 4);
  BASE_DCPR_AddBits(4);

  UpperWidth = BASE_DCPR.ReadCode >> (32 - 4);
  BASE_DCPR_AddBits(4);

  for (I = 0; I <= UpperWidth; I++)
  {
    BASE_CPRDCPR_HUFF.SaveWidths[I] = BASE_DCPR.ReadCode >> (32 - 3);
    BASE_DCPR_AddBits(3);
  }

  if (!BASE_DCPR_HUFF_MakeCodes(BASE_CPRDCPR_HUFF_MAXWIDTHSVDWD,
                                UpperWidth,
                                (PUSHORT) &BASE_CPRDCPR_HUFF.SaveWidths,
                                Codes))
  {
    return 0;
  }

  WidthPos = 0;

  while (WidthPos <= NumWidths)
  {
    Code = Codes[BASE_DCPR.ReadCode >> (32 - BASE_CPRDCPR_HUFF_MAXWIDTHSVDWD)];
    BASE_DCPR_AddBits(BASE_CPRDCPR_HUFF.SaveWidths[Code]);

    if (Code < UpperWidth)
    {
      Widths[WidthPos++] = Code;
    }
    else
    {
      Len = (BASE_DCPR.ReadCode >> 28) + 4;
      BASE_DCPR_AddBits(4);

      while (Len-- && WidthPos <= NumWidths)
      {
        Widths[WidthPos++] = 0;
      }
    }
  }

  if (UpperWidth)
  {
    for (I = 1; I <= NumWidths; I++)
    {
      Widths[I] = (Widths[I] + Widths[I - 1]) % UpperWidth;
    }
  }

  for (I = 0; I <= NumWidths; I++)
  {
    if (Widths[I])
    {
      Widths[I] += LowerWidth;
    }
  }

  return BASE_DCPR_HUFF_MakeCodes(MaxWidth, NumWidths, Widths, Codes);
}
