#ifndef _BASE_DCPR_H_INCLUDED
#define _BASE_DCPR_H_INCLUDED

#include "base/cprdcpr/huff.h"
#include "base/options.h"

//------ConstantDefines:

#define BASE_DCPR_READBUFSIZE                8192

#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h

typedef struct
{
        BOOL    DoFreeReadBuf,
                IsInitialized;
        INT     ReadBufPos,
                ReadCodeBitPos;
        PULONG  ReadBuf;
        ULONG   ReadCode;
        BOOL    IsFirstFile;
        ULONGLONG
                FilePos,
                FileSize;
        INT     Type,
                NextType,
                OverNextType;

        tBASE_OPTIONS_DCPR
                Options;
} tBASE_DCPR;

#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h

extern tBASE_DCPR BASE_DCPR;

void    BASE_DCPR_AddBits(INT Bits);
INT     BASE_DCPR_DecompressV20Block(PCHAR Buf, INT Len);
INT     BASE_DCPR_UnstoreBlock(PCHAR Buf, INT Len);
INT     BASE_DCPR_Block(PCHAR Buf, INT Len);
void    BASE_DCPR_Init(void);
void    BASE_DCPR_InitFile(void);
void    BASE_DCPR_Done(void);
void    BASE_DCPR_DoneFile(void);
void    BASE_DCPR_FillReadBuf(void);

#endif
