#include <fcntl.h>
#include <string.h>

#define INCL_BASE_DCPR

#define INCL_BASE_ARCBLK
#define INCL_BASE_BITWIDTH
#define INCL_BASE_CRC
#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_DCPR_PIC
#define INCL_BASE_DCPR_SOUND
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_MEMORY
#define INCL_BASE_STATE

#include "base/includes.h"

tBASE_DCPR BASE_DCPR;

/*-----------------BASE_DCPR_AddBits-------------------------------------*/

void    BASE_DCPR_AddBits(INT Bits)
{
  ULONG B0, B1;

  BASE_DCPR.ReadBufPos     +=
    (BASE_DCPR.ReadCodeBitPos += Bits) >> 5;

  BASE_DCPR.ReadCodeBitPos &= 31;

  if (BASE_DCPR.ReadBufPos == (BASE_DCPR_READBUFSIZE - 2))
  {
    BASE_DCPR_FillReadBuf();
  }
  
  B0 = BASE_DCPR.ReadBuf[BASE_DCPR.ReadBufPos];
  ADJUST_ENDIANNESS32(&B0);
  
  B1 = BASE_DCPR.ReadBuf[BASE_DCPR.ReadBufPos+1];
  ADJUST_ENDIANNESS32(&B1);
    
  BASE_DCPR.ReadCode = (B0 << BASE_DCPR.ReadCodeBitPos) + ((B1 >> (32 - BASE_DCPR.ReadCodeBitPos))
     & (!BASE_DCPR.ReadCodeBitPos-1));
}

/*-----------------BASE_DCPR_DecompressV20Block--------------------------*/

INT     BASE_DCPR_DecompressV20Block(PCHAR Buf, INT Len)
{
INT       R,
          RestLen;

  RestLen = Len;

  do
  {
    if (BASE_DCPR.Type != BASE_DCPR.NextType)
    {
      switch (BASE_DCPR.NextType)
      {
        case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_8:
        case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_16:
        case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_32_1:
        case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_32_2:
        {
          BASE_DCPR_SOUND_Init(BASE_DCPR.NextType);

          break;
        }

        case BASE_ACESTRUC_BLOCKEDTYPE_PIC:
        {
          BASE_DCPR_PIC_Init();

          break;
        }
      }
    }

    BASE_DCPR.Type = BASE_DCPR.NextType;

    switch (BASE_DCPR.Type)
    {
      case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_NORM:
      case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA:
      case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_EXE:
      {
        R = BASE_DCPR_LZ77_PreprocessBlock(Buf, RestLen);

        break;
      }

      case BASE_ACESTRUC_BLOCKEDTYPE_PIC:
      {
        R = BASE_DCPR_PIC_Block(Buf, RestLen);
        BASE_DCPR_LZ77_CopyToDictionary(Buf, R);
        break;
      }

      case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_8:
      case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_16:
      case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_32_1:
      case BASE_ACESTRUC_BLOCKEDTYPE_SOUND_32_2:
      {
        R = BASE_DCPR_SOUND_Block(Buf, RestLen);
        BASE_DCPR_LZ77_CopyToDictionary(Buf, R);
        break;
      }

      default:
      {
        R = 0;

        break;
      }
    }

    BASE_DCPR.FilePos += R;
    Buf               += R;
    RestLen           -= R;
  }
  while ((R || BASE_DCPR.NextType != BASE_DCPR.Type
           || ((BASE_DCPR.NextType == BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA)
                && BASE_DCPR_LZ77.NextDeltaLen))
         && (RestLen > BASE_CPRDCPR_LZ77_MAXLEN));

  return Len - RestLen;
}

/*-----------------BASE_DCPR_UnstoreBlock--------------------------------*/

INT     BASE_DCPR_UnstoreBlock(PCHAR Buf, INT Len)
{
INT       Rd;

  Len = BASE_CRYPT_CryptLen(Len - 8);              /* because of decryption */

  Rd  = BASE_ARCBLK_ReadAddSizeBlock(Buf,
                                     Len > BASE_DCPR.FileSize ?
                                       BASE_DCPR.FileSize : Len);

  BASE_DCPR_LZ77_CopyToDictionary(Buf, Rd);
  BASE_DCPR.FileSize -= Rd;

  return Rd;
}

/*-----------------BASE_DCPR_Block---------------------------------------*/

INT     BASE_DCPR_Block(PCHAR Buf, INT Len)
{
INT       Result;

  switch (BASE_ARCBLK.Header.File.TECH.TYPE)
  {
    case BASE_ACESTRUC_TECHNIQUE_STORE:
    {
      Result = BASE_DCPR_UnstoreBlock(Buf, Len);
      break;
    }

    case BASE_ACESTRUC_TECHNIQUE_LZ77_1:
    {
      Result = BASE_DCPR_LZ77_Block(Buf, Len);

      break;
    }

    case BASE_ACESTRUC_TECHNIQUE_BLOCKED_1:
    {
      Result = BASE_DCPR_DecompressV20Block(Buf, Len);

      break;
    }

    default:
    {
      BASE_ERROROUT_EXTERN_UnknownMethod();
      BASE_ERROR.ErrorCode  = BASE_ERROR_OTHER;
      Result = 0;
    }
  }

  BASE_CRC.ReadCRC = BASE_CRC_GetCRC(BASE_CRC.ReadCRC, Buf, Result);

  return Result;
}

/*-----------------BASE_DCPR_Init----------------------------------------*/

void    BASE_DCPR_Init(void)
{
INT       I;

  if (!BASE_DCPR.IsInitialized)
  {
    BASE_MEMORY_Optimize();

    if (!(BASE_DCPR.ReadBuf =
            (PULONG) BASE_MEMORY_GetMem(BASE_DCPR_READBUFSIZE << 2)))
    {
      return;
    }

    BASE_DCPR.Options.DicBits = BASE_DIRDATA_Dir1.IsMultiVol ?
      BASE_CPRDCPR_LZ77_MAXDICBITS : BASE_DIRDATA_Dir1.Dictionary;

    while (!(BASE_DCPR_LZ77.Dictionary =
              (PCHAR) BASE_MEMORY_GetMemCheck(0, 1 << BASE_DCPR.Options.DicBits))
           && BASE_DCPR.Options.DicBits)
    {
      BASE_DCPR.Options.DicBits--;
    }

    if (!BASE_DCPR.Options.DicBits)
    {
      BASE_ERROROUT_EXTERN_Mem();

      return;
    }

    BASE_DCPR_LZ77.DictionaryAnd =
      (BASE_DCPR_LZ77.DictionarySize = 1 << BASE_DCPR.Options.DicBits) - 1;

    BASE_DCPR.IsFirstFile     =
      BASE_DCPR.IsInitialized = 1;

    for (I = 0; I <= 128; I++)
    {
      BASE_CPRDCPR_SOUND.QUANTIZER[256 - I] =
        BASE_CPRDCPR_SOUND.QUANTIZER[I]     = BASE_BITWIDTH.BitWidthArray[I];
    }
  }
}



/*-----------------BASE_DCPR_InitFile------------------------------------*/

void    BASE_DCPR_InitFile(void)
{
  BASE_CRYPT_ResetCryptKey(&BASE_DCPR.Options.CryptionData);

  BASE_CRC.ReadCRC   = BASE_CRC_MASK;
  BASE_DCPR.FileSize = BASE_ARCBLK.Header.File.SIZE;

  if (BASE_ARCBLK.Header.File.TECH.TYPE == BASE_ACESTRUC_TECHNIQUE_LZ77_1
      || BASE_ARCBLK.Header.File.TECH.TYPE == BASE_ACESTRUC_TECHNIQUE_BLOCKED_1)
  {
    if ((BASE_ARCBLK.Header.File.TECH.PARM & 15) + 10
          > BASE_DCPR.Options.DicBits)
    {
      BASE_ERROROUT_EXTERN_ExtractMem();
      BASE_ERROR.ErrorCode = BASE_ERROR_MEM;

      return;
    }

    BASE_ARCBLK_ReadAddSizeBlock((PCHAR) BASE_DCPR.ReadBuf,
                                 BASE_DCPR_READBUFSIZE << 2);
    
    BASE_DCPR.ReadCode = BASE_DCPR.ReadBuf[0];
    ADJUST_ENDIANNESS32(&BASE_DCPR.ReadCode);

    BASE_DCPR.ReadCodeBitPos           =
      BASE_DCPR.ReadBufPos             =
      BASE_DCPR.FilePos                =
      BASE_DCPR_LZ77.MainBufPos        =
      BASE_DCPR_LZ77.PartSize          =
      BASE_DCPR_LZ77.BlockSize         =
      BASE_DCPR_LZ77.PREP_NumKeptBytes =
      BASE_DCPR_LZ77.PREP_LastDelta    =
      BASE_DCPR_LZ77.DeltaBlockSize    = 0;

    BASE_DCPR.NextType =
      BASE_DCPR.Type   = BASE_ACESTRUC_BLOCKEDTYPE_LZ77_NORM;
  }

  if (!BASE_ARCBLK.Options.IsSolid || BASE_DCPR.IsFirstFile)
  {
    BASE_DCPR_LZ77.DictionaryPos = 0;
  }

  BASE_DCPR_LZ77.OldDistsPos = 0;
  memset(&BASE_DCPR_LZ77.OldDists, 0, sizeof(BASE_DCPR_LZ77.OldDists));

  BASE_DCPR.IsFirstFile = 0;
}

/*-----------------BASE_DCPR_Done----------------------------------------*/

void    BASE_DCPR_Done(void)
{
  if (BASE_DCPR.IsInitialized)
  {
    BASE_MEMORY_FreeCheck(BASE_DCPR.ReadBuf);
    BASE_MEMORY_FreeCheck(BASE_DCPR_LZ77.Dictionary);
    BASE_DCPR.IsInitialized = 0;
    BASE_MEMORY_Optimize();
  }
}

/*-----------------BASE_DCPR_DoneFile------------------------------------*/

void    BASE_DCPR_DoneFile(void)
{
  BASE_DCPR_PIC_Done();
}

/*-----------------BASE_DCPR_FillReadBuf---------------------------------*/

void    BASE_DCPR_FillReadBuf(void)
{
UINT      Len;

  Len                   = (BASE_DCPR_READBUFSIZE - 2) << 2;
  BASE_DCPR.ReadBufPos -= BASE_DCPR_READBUFSIZE - 2;
  BASE_DCPR.ReadBuf[0]  = BASE_DCPR.ReadBuf[BASE_DCPR_READBUFSIZE - 2];
  BASE_DCPR.ReadBuf[1]  = BASE_DCPR.ReadBuf[BASE_DCPR_READBUFSIZE - 1];

  BASE_ARCBLK_ReadAddSizeBlock((PCHAR) &BASE_DCPR.ReadBuf[2], Len);
}
