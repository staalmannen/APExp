#include <string.h>

#define INCL_BASE_DCPR_COMMENTS

#define INCL_BASE_COMMENTS
#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_HUFF
#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_MEMORY

#include "base/includes.h"


/*-----------------BASE_DCPR_COMMENTS_Init-------------------------------*/

void    BASE_DCPR_COMMENTS_Init(void)
{
INT       I;

  BASE_DCPR.DoFreeReadBuf = !BASE_DCPR.ReadBuf;

  if (BASE_DCPR.DoFreeReadBuf)
  {
    BASE_DCPR.ReadBuf = (PULONG) BASE_MEMORY_GetMem(BASE_DCPR_READBUFSIZE << 2);
  }

  I = BASE_COMMENTS.CompressedSize > BASE_DCPR_READBUFSIZE * sizeof(LONG) ?
          BASE_DCPR_READBUFSIZE * sizeof(LONG) : BASE_COMMENTS.CompressedSize;

  if (BASE_DCPR.ReadBuf)
  {
    memcpy(BASE_DCPR.ReadBuf, BASE_COMMENTS.Comment, I);
  }

  BASE_DCPR.ReadCode = BASE_DCPR.ReadBuf[0];
  ADJUST_ENDIANNESS32(&BASE_DCPR.ReadCode);

  BASE_DCPR.ReadCodeBitPos =
    BASE_DCPR.ReadBufPos   = 0;
}

/*-----------------BASE_DCPR_COMMENTS_Done-------------------------------*/

void    BASE_DCPR_COMMENTS_Done(void)
{
  if (BASE_DCPR.DoFreeReadBuf)
  {
    BASE_MEMORY_FreeCheck(BASE_DCPR.ReadBuf);
  }
}

/*-----------------BASE_DCPR_COMMENTS_GetComment-------------------------*/

void    BASE_DCPR_COMMENTS_GetComment(void)
{
SHORT     Hash[BASE_COMMENTS_HASHFUNC(255, 255) + 1];
INT       CommentPos,
          Code,
          MatchPos,
          CommentLen,
          HashValue;

  if (BASE_COMMENTS.CompressedSize)
  {
    MatchPos = 0;
  
    CommentPos = 0;
    memset(&Hash, 0, sizeof(Hash));
    BASE_DCPR_COMMENTS_Init();

    CommentLen = BASE_DCPR.ReadCode >> (32 - 15);
    BASE_DCPR_AddBits(15);

    if (CommentLen >= sizeof(BASE_COMMENTS.Comment))
    {
      CommentLen = sizeof(BASE_COMMENTS.Comment) - 1;
    }

    if (BASE_DCPR_HUFF_ReadWidths(BASE_CPRDCPR_LZ77_MAXCODEWIDTH,
                                  (PUSHORT) BASE_DCPR_LZ77.MainHuffSymbols,
                                  (PUSHORT) BASE_DCPR_LZ77.MainHuffWidths,
                                  BASE_CPRDCPR_LZ77_MAXMAINCODE))
    {
      do
      {
        if (CommentPos > 1)
        {
          HashValue       =
            BASE_COMMENTS_HASHFUNC(BASE_COMMENTS.Comment[CommentPos - 1],
                              BASE_COMMENTS.Comment[CommentPos - 2]);

          MatchPos        = Hash[HashValue];
          Hash[HashValue] = CommentPos;
        }

        Code = BASE_DCPR_LZ77.MainHuffSymbols
                 [BASE_DCPR.ReadCode >> (32 - BASE_CPRDCPR_LZ77_MAXCODEWIDTH)];

        BASE_DCPR_AddBits(BASE_DCPR_LZ77.MainHuffWidths[Code]);

        if (BASE_DCPR.ReadBufPos == BASE_DCPR_READBUFSIZE - 3)
        {
          BASE_DCPR.ReadBufPos = 0;
        }

        if (Code > 255)
        {
          Code -= 256;
          Code += 2;

          BASE_MEMORY_MemCopy(&BASE_COMMENTS.Comment[CommentPos],
                         &BASE_COMMENTS.Comment[MatchPos], Code);

          CommentPos += Code;
        }
        else
        {
          BASE_COMMENTS.Comment[CommentPos++] = Code;
        }

      }
      while (CommentPos < CommentLen);
    }

    BASE_COMMENTS.Comment[CommentLen] = 0;
    BASE_DCPR_COMMENTS_Done();
  }
  else
  {
    BASE_COMMENTS.Comment[0] = 0;
  }
}
