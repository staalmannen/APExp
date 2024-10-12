#include <stdlib.h>
#include <string.h>

#define INCL_BASE_DCPR_SOUND

#define INCL_BASE_ACESTRUC
#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_HUFF
#define INCL_BASE_DCPR_LZ77
#include "base/includes.h"

tBASE_DCPR_SOUND BASE_DCPR_SOUND;

/*-----------------BASE_DCPR_SOUND_GetPredictedChar----------------------*/

UCHAR   BASE_DCPR_SOUND_GetPredictedChar(INT Channel)
{
  return (UCHAR) ((8 * BASE_DCPR_SOUND.SoundVar.LastByte[Channel]
                + BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][0]
                  * BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][0]
                + BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][1]
                  * BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][1]
                + BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][2]
                  * BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][2]
                + BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][3]
                  * BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][3]) >> 3);
}


/*-----------------BASE_DCPR_SOUND_CalcDcprTabs--------------------------*/

INT     BASE_DCPR_SOUND_CalcDcprTabs(void)
{
INT       I;

  for (I = 0; I < BASE_DCPR_SOUND.SoundVar.Models; I++)
  {
    BASE_DCPR_HUFF_ReadWidths(BASE_CPRDCPR_SOUND_MAXCODEWIDTH,
                         (PUSHORT)&BASE_DCPR_SOUND.HuffSymbols[I],
                         (PUSHORT)&BASE_DCPR_SOUND.HuffWidths[I],
                         BASE_CPRDCPR_SOUND_MAXCODE);
  }

  BASE_DCPR_SOUND.SoundVar.BlockSize = BASE_DCPR.ReadCode >> (32 - 15);
  BASE_DCPR_AddBits(15);

  return 1;
}

/*-----------------BASE_DCPR_SOUND_GetSymbol-----------------------------*/

INT     BASE_DCPR_SOUND_GetSymbol(INT Model, INT Channel)
{
INT       Symbol;

  if (!BASE_DCPR_SOUND.SoundVar.BlockSize)
  {
    BASE_DCPR_SOUND_CalcDcprTabs();
  }

  Model <<= 1;

  if (!Model)
  {
    Model += BASE_DCPR_SOUND.SoundVar.AdaptiveModelUse[Channel];
  }

  Model += 3 * Channel;

  Symbol = BASE_DCPR_SOUND.HuffSymbols[Model][BASE_DCPR.ReadCode
             >> (32 - BASE_CPRDCPR_SOUND_MAXCODEWIDTH)];

  BASE_DCPR_AddBits(BASE_DCPR_SOUND.HuffWidths[Model][Symbol]);
  BASE_DCPR_SOUND.SoundVar.BlockSize--;

  return Symbol;
}

/*-----------------BASE_DCPR_SOUND_Get-----------------------------------*/

INT     BASE_DCPR_SOUND_Get(INT Channel)
{
INT       Err;

  if (BASE_DCPR_SOUND.SoundVar.State[Channel] != 2)
  {
    BASE_DCPR_SOUND.SoundVar.Code[Channel] =
      BASE_DCPR_SOUND_GetSymbol(BASE_DCPR_SOUND.SoundVar.State[Channel],
                                Channel);

    if (BASE_DCPR_SOUND.SoundVar.Code[Channel]
        == BASE_CPRDCPR_SOUND_TYPECODE)
    {
      BASE_DCPR.NextType = BASE_DCPR.ReadCode >> (32 - 8);
      BASE_DCPR_AddBits(8);

      switch (BASE_DCPR.NextType)
      {
        case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_DELTA:
        {
          BASE_DCPR_LZ77.NextDeltaDist = BASE_DCPR.ReadCode >> (32 - 8);
          BASE_DCPR_AddBits(8);
          BASE_DCPR_LZ77.NextDeltaLen  = BASE_DCPR.ReadCode >> (32 - 17);
          BASE_DCPR_AddBits(17);

          break;
        }

        case BASE_ACESTRUC_BLOCKEDTYPE_LZ77_EXE:
        {
          BASE_DCPR_LZ77.NextExeMode = BASE_DCPR.ReadCode >> (32 - 8);
          BASE_DCPR_AddBits(8);

          break;
        }
      }

      return -1;
    }
  }

  if (BASE_DCPR_SOUND.SoundVar.State[Channel] != 2)
  {
    if (!BASE_DCPR_SOUND.SoundVar.State[Channel]
        && BASE_DCPR_SOUND.SoundVar.Code[Channel]
           < BASE_CPRDCPR_SOUND_RUNLENCODES)
    {
      BASE_DCPR_SOUND.SoundVar.State[Channel] = 2;
    }
    else
    {
      if (BASE_DCPR_SOUND.SoundVar.State[Channel] == 1)
      {
        Err = BASE_DCPR_SOUND.SoundVar.Code[Channel];
        BASE_DCPR_SOUND.SoundVar.State[Channel] = 0;
      }
      else
      {
        Err = BASE_DCPR_SOUND.SoundVar.Code[Channel]
              - BASE_CPRDCPR_SOUND_RUNLENCODES;

        BASE_DCPR_SOUND.SoundVar.AdaptiveModelCnt[Channel] =
          (BASE_DCPR_SOUND.SoundVar.AdaptiveModelCnt[Channel] * 7 >> 3) + Err;

        BASE_DCPR_SOUND.SoundVar.AdaptiveModelUse[Channel] =
            BASE_DCPR_SOUND.SoundVar.AdaptiveModelCnt[Channel] > 40;
      }
    }
  }

  if (BASE_DCPR_SOUND.SoundVar.State[Channel] == 2)
  {
    if (!BASE_DCPR_SOUND.SoundVar.Code[Channel])
    {
      BASE_DCPR_SOUND.SoundVar.State[Channel] = 1;
    }
    else
    {
      BASE_DCPR_SOUND.SoundVar.Code[Channel]--;
    }

    Err = 0;
  }

  return Err = Err & 1 ? (255 - (Err >> 1)) : Err >> 1;
}


/*-----------------BASE_DCPR_SOUND_RarPredict----------------------------*/

INT     BASE_DCPR_SOUND_RarPredict(INT Channel)
{
INT       PCh;

  PCh = BASE_DCPR_SOUND_GetPredictedChar(Channel);

  if (BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][0]
      > BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][1])
  {
    PCh = BASE_DCPR_SOUND.SoundVar.LastByte[Channel];
  }

  return PCh - 128;
}

/*-----------------BASE_DCPR_SOUND_RarAdjust-----------------------------*/

void    BASE_DCPR_SOUND_RarAdjust(INT Channel, INT Ch)
{
INT       PredDif,
          I,
          MinDif,
          MinDifPos = 0,
          PCh;

  BASE_DCPR_SOUND.SoundVar.ByteCount[Channel]++;

  PCh = BASE_DCPR_SOUND_GetPredictedChar(Channel);

  PredDif = ((CHAR) (PCh - Ch)) << 3;

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][0] +=
    abs(PredDif - BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][0]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][1] +=
    abs(PredDif + BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][0]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][2] +=
    abs(PredDif - BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][1]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][3] +=
    abs(PredDif + BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][1]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][4] +=
    abs(PredDif - BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][2]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][5] +=
    abs(PredDif + BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][2]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][6] +=
    abs(PredDif - BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][3]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][7] +=
    abs(PredDif + BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][3]);

  BASE_DCPR_SOUND.SoundVar.RarDif[Channel][8] +=
    abs(PredDif);

  BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][0] +=
    BASE_CPRDCPR_SOUND.QUANTIZER[(UCHAR) (PredDif >> 3)];

  BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][1] +=
    BASE_CPRDCPR_SOUND.QUANTIZER[(UCHAR)
      (BASE_DCPR_SOUND.SoundVar.LastByte[Channel] - Ch)];

  BASE_DCPR_SOUND.SoundVar.LastDelta[Channel] =
    (CHAR) (Ch - BASE_DCPR_SOUND.SoundVar.LastByte[Channel]);

  BASE_DCPR_SOUND.SoundVar.LastByte[Channel]  = Ch;

  if (!(BASE_DCPR_SOUND.SoundVar.ByteCount[Channel] & 0x1f))
  {
    MinDif = 0xffff;

    for (I = 8; I >= 0; I--)
    {
      if (BASE_DCPR_SOUND.SoundVar.RarDif[Channel][I] <= MinDif)
      {
        MinDif = BASE_DCPR_SOUND.SoundVar.RarDif[Channel][I];
        MinDifPos = I;
      }

      BASE_DCPR_SOUND.SoundVar.RarDif[Channel][I] = 0;
    }

    if (MinDifPos != 8)
    {
      I = MinDifPos >> 1;

      if (!(MinDifPos & 1))
      {
        if (BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][I] >= -16)
        {
          BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][I]--;
        }
      }
      else
      {
        if (BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][I] <= 16)
        {
          BASE_DCPR_SOUND.SoundVar.RarCoefficient[Channel][I]++;
        }
      }
    }

    if (!(BASE_DCPR_SOUND.SoundVar.ByteCount[Channel] & 0xff))
    {
      BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][0] -=
        BASE_DCPR_SOUND.SoundVar.LastPredictorDifCnt[Channel][0];

      BASE_DCPR_SOUND.SoundVar.LastPredictorDifCnt[Channel][0] =
        BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][0];

      BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][1] -=
        BASE_DCPR_SOUND.SoundVar.LastPredictorDifCnt[Channel][1];

      BASE_DCPR_SOUND.SoundVar.LastPredictorDifCnt[Channel][1] =
        BASE_DCPR_SOUND.SoundVar.PredictorDifCnt[Channel][1];
    }
  }

  BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][3] =
    BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][2];

  BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][2] =
    BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][1];

  BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][1] =
    BASE_DCPR_SOUND.SoundVar.LastDelta[Channel]
    - BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][0];

  BASE_DCPR_SOUND.SoundVar.RarDifCnt[Channel][0] =
    BASE_DCPR_SOUND.SoundVar.LastDelta[Channel];
}

/*-----------------BASE_DCPR_SOUND_Block---------------------------------*/

INT     BASE_DCPR_SOUND_Block(PCHAR Buf, INT Len)
{
INT       I,
          Err,
          Channel,
          Sample;

  Len &= 0xfffffffc;

  if (Len > BASE_DCPR.FileSize)
  {
    Len = BASE_DCPR.FileSize;
  }

  for (I = 0; I < Len; I++)
  {
    Channel =
      BASE_CPRDCPR_SOUND_CHANNELNUM[BASE_DCPR_SOUND.SoundVar.Mode][I & 3];

    Err = BASE_DCPR_SOUND_Get(Channel);

    if (Err == -1)
    {
      break;
    }

    Sample = (UCHAR) (Err + BASE_DCPR_SOUND_RarPredict(Channel));
    Buf[I] = Sample + 128;
    BASE_DCPR_SOUND_RarAdjust(Channel, Buf[I]);
  }

  BASE_DCPR.FileSize -= I;

  return I;
}

/*-----------------BASE_DCPR_SOUND_Init----------------------------------*/

void    BASE_DCPR_SOUND_Init(INT Type)
{
  memset(&BASE_DCPR_SOUND.SoundVar, 0, sizeof(BASE_DCPR_SOUND.SoundVar));
  BASE_DCPR_SOUND.SoundVar.Mode = Type - BASE_ACESTRUC_BLOCKEDTYPE_SOUND_8;

  BASE_DCPR_SOUND.SoundVar.Models =
    BASE_CPRDCPR_SOUND_MODELS[BASE_DCPR_SOUND.SoundVar.Mode];
}
