#ifndef _BASE_DIRDATA_H_INCLUDED
#define _BASE_DIRDATA_H_INCLUDED

#include "base/dosfuncs.h"
#include "base/lfn.h"

//------TypeDefines:

#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h

typedef struct
{
  tLFN    Dir,
          SavedFileName;
  INT     ListPrintPos;

/*- for archives -*/

  tLFN    ArchiveName,
          ArchiveDir;
  PCHAR   ArchiveDescription;

  BOOL    IsACE,
          IsBroken,
          IsSolid,
          IsMultiVol,
          IsLocked,
          IsSFX,
          IsNotCompatible,
          IsAVOk,
          HasAV,
          HasPassword,
          HasMainCmt,
          HasFileCmt,
          HasRecoveryRec,
          HasBeenModified;
  INT     ArchiveBegin;
  INT     ArchiveType,
          Dictionary,
          VolumeNumber,
          FileNumber,
          VersionToExtract,
          VersionCreated,
          HostCreated;
  ULONGLONG
          UnPackedSize,
          PackedSize;
  tBASE_DOSFUNCS_FileTime
          TimeCreated;
} tBASE_DIRDATA_DirData,
 *pBASE_DIRDATA_DirData;

#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h

//------VariableDefines:

#define BASE_DIRDATA_IsInArchive1 BASE_DIRDATA_Dir1.ArchiveName[0]
#define BASE_DIRDATA_IsInArchive2 BASE_DIRDATA_Dir2.ArchiveName[0]


//------Variables:

extern tBASE_DIRDATA_DirData // all.c
         BASE_DIRDATA_Dir1,
         BASE_DIRDATA_Dir2;
#endif
