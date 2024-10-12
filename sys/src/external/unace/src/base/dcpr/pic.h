#ifndef _BASE_DCPR_PIC_H_INCLUDED
#define _BASE_DCPR_PIC_H_INCLUDED

#include "base/cprdcpr/pic.h"

typedef struct
{
        INT     Width,
                Planes;
        PCHAR   Data[2];
        INT     DataPos;
        tBASE_CPRDCPR_PIC_CONTEXT
                Context[2][BASE_CPRDCPR_PIC_CONTEXTNUMBER];
        pBASE_CPRDCPR_PIC_CONTEXT
                CurContext;
        INT     CurPlane,
                CurCol,
                CurState,
                CurPred;
        UCHAR   PixelA,
                PixelB,
                PixelC,
                PixelD,
                PixelX;
} tBASE_DCPR_PIC;

extern tBASE_DCPR_PIC BASE_DCPR_PIC;

INT     BASE_DCPR_PIC_GolombRice(INT K);
void    BASE_DCPR_PIC_InitModel(void);
void    BASE_DCPR_PIC_InitQuantizers(void);
void    BASE_DCPR_PIC_Init(void);
void    BASE_DCPR_PIC_Done(void);

INT     BASE_DCPR_PIC_Block(PCHAR Buf, INT Len);
INT     BASE_DCPR_PIC_GetContext(void);
void    BASE_DCPR_PIC_SetPixels1(void);
void    BASE_DCPR_PIC_SetPixels2(void);
void    BASE_DCPR_PIC_SetPixels3(void);
void    BASE_DCPR_PIC_SetPixelState(void);
void    BASE_DCPR_PIC_Pixel(void);
void    BASE_DCPR_PIC_Symbol(void);
void    BASE_DCPR_PIC_Line(void);

#endif
