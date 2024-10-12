#ifndef _BASE_LFN_H_INCLUDED
#define _BASE_LFN_H_INCLUDED

#include <stdio.h>
#include <stdarg.h>

#ifdef _WIN32
	#include <io.h>
#else
	#include <unistd.h>
#endif

#ifndef O_BINARY
  #define O_BINARY 0x0
#endif

#ifndef S_IRWXU
  #define S_IRWXU 0x0
  #define S_IRWXG 0x0
  #define S_IRWXO 0x0
#endif

#define BASE_LFN_MAXLEN           350
#define BASE_LFN_DOUBLEMAXLEN     (2 * BASE_LFN_MAXLEN)

typedef CHAR tLFN[BASE_LFN_MAXLEN];
typedef tLFN *pLFN;
typedef CHAR tBASE_LFN_DBL[BASE_LFN_DOUBLEMAXLEN];
typedef tBASE_LFN_DBL *pBASE_LFN_DBL;

#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h

typedef struct
{
  CHAR   Reserved[21];
  CHAR   Attributes;
  USHORT Time;
  USHORT Date;
  ULONGLONG
         Size;
  tLFN   Name;
} tBASE_LFN_DOSFINDSTRUCT,
 *pBASE_LFN_DOSFINDSTRUCT;


typedef struct
{
  USHORT  Handle;
  ULONG   Attributes;
  ULONG   CreationLo;
  ULONG   CreationHi;
  ULONG   LastAccessLo;
  ULONG   LastAccessHi;
  USHORT  Time;
  USHORT  Date;
  ULONG   LastModifyLo;
  ULONG   LastModifyHi;
  ULONGLONG
          Size;
  CHAR    Reserved[8];
  tLFN    Name;
  CHAR    ShortName[14];
  BOOL    IsFirstReadDirCall,
          IsDosLFNCall;
  tBASE_LFN_DOSFINDSTRUCT
          DosFindStruct;
} tBASE_LFN_FINDSTRUCT,
 *pBASE_LFN_FINDSTRUCT;

#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h

typedef struct
{
  tLFN    ShortNameStr,
          LongNameStr;
  tLFN    Arg0;
} tBASE_LFN;

extern tBASE_LFN BASE_LFN; // lfn.c

INT     BASE_LFN_FindFirst(PCHAR Specification, INT Attr,
                           pBASE_LFN_FINDSTRUCT DirStruc);

INT     BASE_LFN_FindNext(pBASE_LFN_FINDSTRUCT DirStruc);
INT     BASE_LFN_FindClose(pBASE_LFN_FINDSTRUCT DirStruc);
INT     BASE_LFN_ChangeDir(PCHAR Dir);
PCHAR   BASE_LFN_GetCurrentDir(PCHAR Dir, size_t Size);
PCHAR   BASE_LFN_GetCurrentDirOfDrive(INT Drive, PCHAR Dir, size_t Size);
INT     BASE_LFN_Open(PCHAR Path, INT Access,...);
UINT    BASE_LFN_GetFileAttributes(PCHAR Path, PUINT Attr);
UINT    BASE_LFN_SetFileAttributes(PCHAR Path, UINT Attr);
INT     BASE_LFN_RemoveFile(PCHAR Path);
INT     BASE_LFN_Access(PCHAR Path, INT Mode);
ULONG   BASE_LFN_GetFileTime(PCHAR FileName);
void    BASE_LFN_CompleteArg0(PCHAR *Arg0);
void    BASE_LFN_ConvertFileName(PCHAR Path, INT Attr);
INT     BASE_LFN_MakeDir(PCHAR Dir);
INT     BASE_LFN_RemoveDir(PCHAR Dir);
INT     BASE_LFN_GetFindAllFilesAndDirsAttr(void);
INT     BASE_LFN_GetFindAllFilesAttr(void);

#endif
