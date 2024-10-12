#ifndef _BASE_DCPR_HUFF_H_INCLUDED
#define _BASE_DCPR_HUFF_H_INCLUDED


INT     BASE_DCPR_HUFF_MakeCodes(UINT MaxWidth, UINT TabSize,
                                 PUSHORT Widths, PUSHORT Codes);

INT     BASE_DCPR_HUFF_ReadWidths(UINT MaxWidth, PUSHORT Codes,
                                  PUSHORT Widths, UINT MaxSize);


#endif
