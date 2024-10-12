#ifndef _BASE_DCPR_LZ77_H_INCLUDED
#define _BASE_DCPR_LZ77_H_INCLUDED

//#include "base/cprdcpr/lz77.h"
#define BASE_CPRDCPR_LZ77_MAXCODEWIDTH       11
#define BASE_CPRDCPR_LZ77_MAXLEN             259
#define BASE_CPRDCPR_LZ77_MAXDISTATLEN2      255
#define BASE_CPRDCPR_LZ77_MAXDISTATLEN3      8191

#define BASE_CPRDCPR_LZ77_MAXDICBITS         22
#define BASE_CPRDCPR_LZ77_MAXDICBITS2        (BASE_CPRDCPR_LZ77_MAXDICBITS >> 1)
#define BASE_CPRDCPR_LZ77_MAXDICSIZE         (1 << BASE_CPRDCPR_LZ77_MAXDICBITS)
#define BASE_CPRDCPR_LZ77_MAXDIST2           (1 << BASE_CPRDCPR_LZ77_MAXDICBITS2)

#define BASE_CPRDCPR_LZ77_DEFBLOCKSIZE       8500
#define BASE_CPRDCPR_LZ77_MAXBLOCKSIZE       9500
#define BASE_CPRDCPR_LZ77_MAXMAINCODE        (260 + BASE_CPRDCPR_LZ77_MAXDICBITS + 2)
#define BASE_CPRDCPR_LZ77_MAXLENCODE         (256 - 1)
#define BASE_CPRDCPR_LZ77_TYPECODE           (260 + BASE_CPRDCPR_LZ77_MAXDICBITS + 1)
#define BASE_CPRDCPR_LZ77_NUMDICSIZES        (BASE_CPRDCPR_LZ77_MAXDICBITS - 15 + 1)
#define BASE_CPRDCPR_LZ77_MAXDELTABLOCK      65536

//================================================


#define BASE_DCPR_LZ77_MAXPARTSIZE           1024

typedef struct
{
        USHORT  MainHuffSymbols[(1 << BASE_CPRDCPR_LZ77_MAXCODEWIDTH) + 1],
                MainHuffWidths[BASE_CPRDCPR_LZ77_MAXMAINCODE + 2],
                LenHuffSymbols[(1 << BASE_CPRDCPR_LZ77_MAXCODEWIDTH) + 1],
                LenHuffWidths[BASE_CPRDCPR_LZ77_MAXLENCODE + 3];
        USHORT  MainBuf[BASE_DCPR_LZ77_MAXPARTSIZE],
                LenBuf[BASE_DCPR_LZ77_MAXPARTSIZE];
        ULONG   DistBuf[BASE_DCPR_LZ77_MAXPARTSIZE],
                MainBufPos,
                LenDistBufPos;
        INT     OldDistsPos;
        ULONG   OldDists[4];
        PCHAR   Dictionary;
        ULONG   DictionaryPos,
                DictionarySize,
                DictionaryAnd;
        ULONG   BlockSize,
                PartSize,
                BLOCK_ByteCount,
                BLOCK_BufSize;
        INT     PREP_NumKeptBytes,
                PREP_KeptBytesPos;
        ULONG   PREP_LastDelta;
        INT     DeltaDist,
                NextDeltaDist,
                DeltaLen,
                NextDeltaLen,
                DeltaBlockSize,
                DeltaPlaneSize,
                DeltaPlane,
                DeltaPlanePos;
        INT     ExeMode,
                NextExeMode;
        UCHAR   PREP_KeptBytesBuf[BASE_CPRDCPR_LZ77_MAXDELTABLOCK
                                  + BASE_CPRDCPR_LZ77_MAXLEN];
} tBASE_DCPR_LZ77;


INT     BASE_DCPR_LZ77_ReadSymbols(void);
INT     BASE_DCPR_LZ77_CalcHuffTabs(void);
INT     BASE_DCPR_LZ77_Block(PCHAR Buf, INT Len);
INT     BASE_DCPR_LZ77_PreprocessBlock(PCHAR Buf, INT Len);
void    BASE_DCPR_LZ77_CopyToDictionary(PCHAR Buf, INT Len);

void    BASE_DCPR_LZ77_BlockCore(void);
void    BASE_DCPR_LZ77_ReadSymbolsCore(void);
void    BASE_DCPR_LZ77_WriteChar(CHAR Char);
void    BASE_DCPR_LZ77_CopyString(ULONG Dist, INT Len);

extern tBASE_DCPR_LZ77 BASE_DCPR_LZ77;

#endif
