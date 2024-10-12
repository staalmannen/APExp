#ifndef _BASE_MEMORY_H_INCLUDED
#define _BASE_MEMORY_H_INCLUDED

#define BASE_MEMORY_MINGETMEMBASE2 4096

typedef struct
{
        LONG    MaxAllocate;
} tBASE_MEMORY;

extern tBASE_MEMORY BASE_MEMORY; //memory.c

void    BASE_MEMORY_CopyBytes(PCHAR Dest, PCHAR Source, INT Len);
void    BASE_MEMORY_MemCopy(PCHAR Dest, PCHAR Source, INT Len);
void    BASE_MEMORY_MemSet16(PUSHORT Buf, USHORT Code, INT Len);
void    BASE_MEMORY_MemSet32(PULONG Buf, ULONG Code, INT Len);
void    BASE_MEMORY_LowMemoryErr(void);
PVOID   BASE_MEMORY_GetMemCheck(BOOL DoCheck, INT Size);
PVOID   BASE_MEMORY_GetMem(INT Size);
INT     BASE_MEMORY_Size(PVOID Pointer);
PVOID   BASE_MEMORY_GetMemBase2(PINT Size, INT Base);
PVOID   BASE_MEMORY_GetMemBase2Max(PINT Size, INT Base, INT Maximum);

PVOID   BASE_MEMORY_GetMemBase2PlusMax(PINT Size, INT Base, INT Maximum,
                                       INT Plus);

void    BASE_MEMORY_FreeCheck_(PVOID Pointer);
#define BASE_MEMORY_FreeCheck(ptr) do { BASE_MEMORY_FreeCheck_(ptr); ptr=0; } while(0)
PVOID   BASE_MEMORY_ReAlloc(PVOID OldPointer, INT NewSize);
PVOID   BASE_MEMORY_ReAllocSameSize(PVOID OldPointer);
void    BASE_MEMORY_InitAlloc(void);
void    BASE_MEMORY_Optimize(void);
void    BASE_MEMORY_InitMaxAllocate(void);
INT     BASE_MEMORY_MemMax(void);
INT     BASE_MEMORY_MemAvail(void);
INT     BASE_MEMORY_MemAvailBase2(INT Base);
INT     BASE_MEMORY_MemAvailBase2Plus(INT Base, INT Plus);
ULONG   BASE_MEMORY_EXTERN_MaxMemoryRequirement(void);

#endif
