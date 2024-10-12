#ifndef _BASE_BUFREAD_H_INCLUDED
#define _BASE_BUFREAD_H_INCLUDED

#include "base/lfn.h"

typedef struct
{
  INT     Handle;
  PCHAR   Buf;
  INT     BufSize;
  ULONG   BufPos;
  ULONGLONG

          FilePos,
          BufEnd,
          ReadPos;
  tLFN    FileName;
} tBASE_BUFREAD;

extern tBASE_BUFREAD BASE_BUFREAD;

INT     BASE_BUFREAD_Read(PCHAR Buf, UINT Len);
void    BASE_BUFREAD_Seek(ULONGLONG Pos, INT Mode);
INT     BASE_BUFREAD_Open(PCHAR FileName);
void    BASE_BUFREAD_Close(void);

ULONGLONG BASE_BUFREAD_Tell(void);
#endif
