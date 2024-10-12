#ifndef _BASE_FILELIST_H_INCLUDED
#define _BASE_FILELIST_H_INCLUDED

#include "base/dosfuncs.h"
#include "base/lfn.h"

#define BASE_FILELIST_NORMAL       BASE_DOSFUNCS_NORMAL
#define BASE_FILELIST_RDONLY       BASE_DOSFUNCS_RDONLY
#define BASE_FILELIST_HIDDEN       BASE_DOSFUNCS_HIDDEN
#define BASE_FILELIST_SYSTEM       BASE_DOSFUNCS_SYSTEM
#define BASE_FILELIST_VOLID        BASE_DOSFUNCS_VOLID
#define BASE_FILELIST_SUBDIR       BASE_DOSFUNCS_SUBDIR
#define BASE_FILELIST_ARCH         BASE_DOSFUNCS_ARCH
#define BASE_FILELIST_UPDIR        256
#define BASE_FILELIST_SELECTED     512
#define BASE_FILELIST_ISARCHIVE    1024
#define BASE_FILELIST_ARCHIVEUPDIR 2048
#define BASE_FILELIST_SPLITBEFORE  4096
#define BASE_FILELIST_SPLITAFTER   8192
#define BASE_FILELIST_ENCRYPTED    16384

#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h

typedef struct
{
  union {
    tBASE_DOSFUNCS_FileTime
          Fields;
    ULONG Raw;
  } Time;
  ULONGLONG
          Size,
          PackedSize;
  USHORT  Attr;
} tBASE_FILELIST_FileData,
 *pBASE_FILELIST_FileData;

#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h

typedef struct
{
  BOOL    DoRecurseSubDirectories,
          DoAddFileCheckIfValidFile,
          DoAddFileCheckIfFileIsInList;
  PCHAR   List,
          Pos,
          Last,
          SearchList,
          SearchListEnd,
          SearchListMax,
          SearchExcludeList,
          SearchExcludeListEnd,
          SearchExcludeListMax;
  tLFN    FileNameStr,
          AddDir;
  LONG    Number,
          MaxNumber,
          Count,
          AddMode;
  ULONGLONG
          SizeOfFiles,
          SkippedSize;
  pBASE_FILELIST_FileData
          ListFileData;
} tBASE_FILELIST;

extern tBASE_FILELIST BASE_FILELIST; //filelist.c


PCHAR   BASE_FILELIST_RemoveDrive(PCHAR Path);
PCHAR   BASE_FILELIST_Check(PCHAR FileName);
INT     BASE_FILELIST_ListStrLen(PCHAR FileName);
PCHAR   BASE_FILELIST_CheckExclusion(PCHAR FileName);
INT     BASE_FILELIST_AddCheck(PCHAR FileName);
void    BASE_FILELIST_Init(void);
void    BASE_FILELIST_Done(void);
LONG    BASE_FILELIST_Dir2FileTime(PCHAR FileName);

void    BASE_FILELIST_AddFile(PCHAR FileName, ULONGLONG FileSize,
                              ULONG FileTime, INT Attr);

INT     BASE_FILELIST_Create(BOOL DoAddDirFirst, INT Mode,
                             BOOL DoOutputNoFilesError);

void      BASE_FILELIST_SearchListArchiveCreateProcessFile(
           PCHAR FileName, tBASE_FILELIST_FileData FileData);

void    BASE_FILELIST_VolumeCreate(void);
void    BASE_FILELIST_SearchListArchiveCreate(void);
BOOL    BASE_FILELIST_EXTERN_CommandLineCheck(PCHAR FileName,
                                              PCHAR CompareFileName1,
                                              PCHAR CompareFileName2);
#endif
