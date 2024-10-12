#include <stdlib.h>
#include <string.h>

#define INCL_BASE_MEMORY

#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_DCPR_PIC
#define INCL_BASE_ERROROUT
#define INCL_BASE_FILELIST

#define INCL_BASE_BITWIDTH
#include "base/includes.h"

tBASE_MEMORY BASE_MEMORY; //memory.h


/*-----------------BASE_MEMORY_EXTERN_MaxMemoryRequirement---------------*/
ULONG   BASE_MEMORY_EXTERN_MaxMemoryRequirement(void)
{
  return 16*1024*1024;
}


/*-----------------BASE_MEMORY_GetMemCheck-------------------------------*/

PVOID   BASE_MEMORY_GetMemCheck(BOOL DoCheck, INT Size)
{
PVOID     Pointer;
BOOL      MemIsMaxed;
INT       MemBlockSize;

  MemIsMaxed = 1;

  while (Size > (MemBlockSize = BASE_MEMORY_MemMax()) && MemIsMaxed)
  {
    BASE_MEMORY_Optimize();
    MemIsMaxed = MemBlockSize + 8 * 1024 < BASE_MEMORY_MemMax();
  }

  if (Size + 4 > BASE_MEMORY.MaxAllocate)
  {
    if (DoCheck)
    {
      BASE_ERROROUT_EXTERN_Mem();
    }

    return NULL;
  }

  if (!(Pointer = malloc(Size + 4)))
  {
    if (DoCheck)
    {
      BASE_ERROROUT_EXTERN_Mem();
    }
  }
  else
  {
    BASE_MEMORY.MaxAllocate -= Size + 4;

    *(PULONG) Pointer = Size;
    Pointer = (PVOID) ((PULONG) Pointer + 1);
  }

  return Pointer;
}

/*-----------------BASE_MEMORY_GetMem------------------------------------*/

PVOID   BASE_MEMORY_GetMem(INT Size)
{
  return BASE_MEMORY_GetMemCheck(1, Size);
}

/*-----------------BASE_MEMORY_Size--------------------------------------*/

INT     BASE_MEMORY_Size(PVOID Pointer)
{
  return *((PULONG) Pointer - 1);
}

/*-----------------BASE_MEMORY_GetMemBase2-------------------------------*/

PVOID   BASE_MEMORY_GetMemBase2(PINT Size, INT Base)
{
INT       MemSize;

  MemSize = BASE_MEMORY_MemAvailBase2(Base);

  if (MemSize <= BASE_MEMORY_MINGETMEMBASE2)
  {
    MemSize = BASE_MEMORY_MINGETMEMBASE2;
  }

  if (Size)
  {
    *Size = MemSize;
  }

  return BASE_MEMORY_GetMem(MemSize);
}

/*-----------------BASE_MEMORY_GetMemBase2Max----------------------------*/

PVOID  BASE_MEMORY_GetMemBase2Max(PINT Size, INT Base, INT Maximum)
{
INT       MemSize;

  MemSize = BASE_MEMORY_MemAvailBase2(Base);

  if (MemSize <= BASE_MEMORY_MINGETMEMBASE2)
  {
    MemSize = BASE_MEMORY_MINGETMEMBASE2;
  }

  if (MemSize > Maximum)
  {
    MemSize = Maximum;
  }

  if (Size)
  {
    *Size = MemSize;
  }

  return BASE_MEMORY_GetMem(MemSize);
}

/*-----------------BASE_MEMORY_GetMemBase2PlusMax------------------------*/

PVOID  BASE_MEMORY_GetMemBase2PlusMax(PINT Size, INT Base, INT Maximum,
                                        INT Plus)
{
INT       MemSize;

  MemSize = BASE_MEMORY_MemAvailBase2Plus(Base, Plus);

  if (MemSize <= BASE_MEMORY_MINGETMEMBASE2)
  {
    MemSize = BASE_MEMORY_MINGETMEMBASE2;
  }

  if (MemSize > Maximum)
  {
    MemSize = Maximum;
  }

  if (Size)
  {
    *Size = MemSize;
  }

  return BASE_MEMORY_GetMem(MemSize + Plus);
}

/*-----------------BASE_MEMORY_FreeCheck---------------------------------*/

void    BASE_MEMORY_FreeCheck_(PVOID Pointer)
{
  if (Pointer)
  {
    BASE_MEMORY.MaxAllocate += BASE_MEMORY_Size(Pointer);
    free((PVOID) (((PULONG) Pointer) - 1));
  }
}

/*-----------------BASE_MEMORY_ReAllocSameSize---------------------------*/

PVOID   BASE_MEMORY_ReAllocSameSize(PVOID OldPointer)
{
PVOID     NewPointer;
INT       OldSize,
          MemMaxSize;

  if (!OldPointer)
  {
    return NULL;
  }

  MemMaxSize = BASE_MEMORY_MemMax();
  OldSize    = BASE_MEMORY_Size(OldPointer);

  if (MemMaxSize < OldSize
      || !(NewPointer = BASE_MEMORY_GetMemCheck(0, OldSize)))
  {
    return OldPointer;
  }

  memcpy(NewPointer, OldPointer, OldSize);
  BASE_MEMORY_FreeCheck(OldPointer);

  if (BASE_MEMORY_MemMax() < MemMaxSize)
  {
    if (!(OldPointer = BASE_MEMORY_GetMemCheck(0, OldSize)))
    {
      return NewPointer;
    }

    memcpy(OldPointer, NewPointer, OldSize);
    BASE_MEMORY_FreeCheck(NewPointer);

    return OldPointer;
  }
  else
  {
    return NewPointer;
  }
}

/*-----------------BASE_MEMORY_InitAlloc---------------------------------*/

void    BASE_MEMORY_InitAlloc(void)
{
PVOID     Pointer;
INT       Size;

  Pointer = NULL;
  Size    = BASE_MEMORY.MaxAllocate;

  while (!Pointer && Size > 32768)
  {
    Pointer = malloc(Size);

    if (!Pointer)
    {
      Size -= Size / 4;
    }
  }

  if (Pointer)
  {
    free(Pointer);
    BASE_MEMORY.MaxAllocate = Size;
  }
}

/*-----------------BASE_MEMORY_Optimize----------------------------------*/

void    BASE_MEMORY_Optimize(void)
{
INT       I, J;

  I             = BASE_FILELIST.Last - BASE_FILELIST.List;
  J             = BASE_FILELIST.Pos  - BASE_FILELIST.List;
  BASE_FILELIST.List = (PCHAR)BASE_MEMORY_ReAllocSameSize(BASE_FILELIST.List);
  BASE_FILELIST.Last = BASE_FILELIST.List + I;
  BASE_FILELIST.Pos  = BASE_FILELIST.List + J;

  BASE_DCPR.ReadBuf               =
    (PULONG) BASE_MEMORY_ReAllocSameSize(BASE_DCPR.ReadBuf);

  BASE_DCPR_LZ77.Dictionary       =
    (PCHAR) BASE_MEMORY_ReAllocSameSize(BASE_DCPR_LZ77.Dictionary);

  for (I = 0; I < 2; I++)
  {
    BASE_DCPR_PIC.Data[I]         =
      (PCHAR) BASE_MEMORY_ReAllocSameSize(BASE_DCPR_PIC.Data[I]);
  }
}

// ========================================================================
// lin.c

/*-----------------BASE_MEMORY_InitMaxAllocate---------------------------*/
void    BASE_MEMORY_InitMaxAllocate(void)
{
  BASE_MEMORY.MaxAllocate  = BASE_MEMORY_EXTERN_MaxMemoryRequirement();

  BASE_MEMORY_InitAlloc();
}

/*-----------------BASE_MEMORY_MemMax------------------------------------*/
INT     BASE_MEMORY_MemMax(void)
{
  return BASE_MEMORY.MaxAllocate;
}

/*-----------------BASE_MEMORY_MemAvail----------------------------------*/
INT     BASE_MEMORY_MemAvail(void)
{
  return BASE_MEMORY_MemMax();
}

// ========================================================================
// nowat.c

/*-----------------BASE_MEMORY_MemCopy-----------------------------------*/
void    BASE_MEMORY_MemCopy(PCHAR Dest, PCHAR Source, INT Len)
{
  while (Len--)
  {
    *Dest++ = *Source++;
  }
}

/*-----------------BASE_MEMORY_MemSet16----------------------------------*/
void    BASE_MEMORY_MemSet16(PUSHORT Buf, USHORT Code, INT Len)
{
  while (Len--)
  {
    *Buf++ = Code;
  }
}

/*-----------------BASE_MEMORY_MemSet32----------------------------------*/
void    BASE_MEMORY_MemSet32(PULONG Buf, ULONG Code, INT Len)
{
  while (Len--)
  {
    *Buf++ = Code;
  }
}

// ========================================================================
// nodos32.c

/*-----------------BASE_MEMORY_ReAlloc-----------------------------------*/

PVOID  BASE_MEMORY_ReAlloc(PVOID OldPointer, INT NewSize)
{
PVOID     NewPointer;
INT       OldSize;

  OldSize = BASE_MEMORY_Size(OldPointer);

  if ((NewPointer = realloc((PVOID) ((PULONG) OldPointer - 1), NewSize + 4)))
  {
    BASE_MEMORY.MaxAllocate += OldSize - NewSize;
    *(PULONG) NewPointer = NewSize;
    NewPointer = (PVOID) ((PULONG) NewPointer + 1);

    return NewPointer;
  }
  else
  {
    return OldPointer;
  }
}

/*-----------------BASE_MEMORY_MemAvailBase2-----------------------------*/

INT     BASE_MEMORY_MemAvailBase2(INT Base)
{
PVOID     Pointer;
INT       I;

  I = BASE_MEMORY.MaxAllocate >> (Base + 11);

  I = 1 << ((I < 256 ? BASE_BITWIDTH_GetBitWidth(I)
                     : BASE_BITWIDTH_GetBitWidth(I >> 8) + 8) + 10);

  while (!(Pointer = malloc(I)))
  {
    I -= I >> 2;
  }

  free(Pointer);

  return I;
}

/*-----------------BASE_MEMORY_MemAvailBase2Plus-------------------------*/

INT     BASE_MEMORY_MemAvailBase2Plus(INT Base, INT Plus)
{
PVOID     Pointer;
INT       I;

  I = BASE_MEMORY.MaxAllocate >> (Base + 11);

  I = 1 << ((I < 256 ? BASE_BITWIDTH_GetBitWidth(I)
                     : BASE_BITWIDTH_GetBitWidth(I >> 8) + 8) + 10);

  while (!(Pointer = malloc(I + Plus)))
  {
    I >>= 1;
  }

  free(Pointer);

  return I;
}
