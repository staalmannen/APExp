#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define INCL_BASE_ARCHIVES_READ

#define INCL_BASE_ARCBLK
#define INCL_BASE_ARCHIVES_TEST
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_FILELIST
#define INCL_BASE_LFN
#define INCL_BASE_MEMORY
#define INCL_BASE_MSGOUT
#define INCL_BASE_VOLUME
#define INCL_BASE_ARCHIVES_ACE

#include "base/includes.h"

#define INCL_APPS_EXE_MESSAGES
#include "unace_includes.h"

tBASE_ARCHIVES_READ BASE_ARCHIVES_READ; //read.h


/*-----------------BASE_ARCHIVES_READ_EXTERN_ReadArchiveProc-------------*/
void    BASE_ARCHIVES_READ_EXTERN_ReadArchiveProc(void)
{
  BASE_ARCHIVES_ACE_ReadArchive();
}
/*-----------------BASE_ARCHIVES_READ_EXTERN_GetArchiveDescription-------*/
void    BASE_ARCHIVES_READ_EXTERN_GetArchiveDescription(void)
{
  BASE_DIRDATA_Dir1.ArchiveDescription =
    STR.arcdiscr[(BASE_DIRDATA_Dir1.IsSolid << 2)
    + (BASE_DIRDATA_Dir1.IsSFX << 1) + BASE_DIRDATA_Dir1.IsMultiVol];
}


/*-----------------BASE_ARCHIVES_READ_FreeArchiveList--------------------*/

void    BASE_ARCHIVES_READ_FreeArchiveList(void)
{
  BASE_MEMORY_FreeCheck(BASE_ARCHIVES_READ.FileData);
  BASE_MEMORY_FreeCheck(BASE_ARCHIVES_READ.FileNames);
}

/*-----------------BASE_ARCHIVES_READ_GetArchiveList---------------------*/

void    BASE_ARCHIVES_READ_GetArchiveList(void)
{
INT       I;
tLFN      FileName;
PCHAR     ArchiveFileName;
//SHORT     Attr;

  ArchiveFileName = BASE_ARCHIVES_READ.FileNames;

  for (I = 0; I < BASE_ARCHIVES_READ.FileNumber; I++)
  {
    strcpy(FileName, ArchiveFileName);
    //Attr = BASE_ARCHIVES_READ.FileData[I].Attr;

    (*BASE_ARCHIVES_READ.ProcessFile)
      (FileName, BASE_ARCHIVES_READ.FileData[I]);

    ArchiveFileName += strlen(ArchiveFileName) + 1;

    if (BASE_ERROR.ErrorCode)
    {
      break;
    }
  }
}

/*-----------------BASE_ARCHIVES_READ_ReadArchive------------------------*/

INT     BASE_ARCHIVES_READ_ReadArchive(PCHAR ArchiveName)
{
PVOID     SavedScreenPtr;
INT       Result,
          BufSize;

  BASE_ARCHIVES_READ.FileNumber        =
    BASE_DIRDATA_Dir1.IsBroken         =
    BASE_DIRDATA_Dir1.Dictionary       =
    BASE_DIRDATA_Dir1.VersionToExtract =
    BASE_DIRDATA_Dir1.HasPassword      =
    BASE_DIRDATA_Dir1.FileNumber       =
    BASE_DIRDATA_Dir1.UnPackedSize     =
    BASE_DIRDATA_Dir1.PackedSize       =
    BASE_DIRDATA_Dir1.HasFileCmt       =
    BASE_DIRDATA_Dir1.HasRecoveryRec   = 0;

  BASE_MSGOUT_EXTERN_ReadingArchive(&SavedScreenPtr);

  Result = BASE_ARCHIVES_TEST_ArchiveTest(ArchiveName,
                  BASE_ARCHIVES_TEST.MaxTestSectors, 1);

  if (Result)
  {
    BASE_ARCHIVES_READ_FreeArchiveList();
    BufSize = BASE_MEMORY_MemAvailBase2(2);

    BASE_ARCHIVES_READ.MaxFileNumber =
      BufSize / sizeof(*BASE_ARCHIVES_READ.FileData);

	BASE_ARCHIVES_READ.FileData =
      (pBASE_FILELIST_FileData) BASE_MEMORY_GetMem(BufSize);

    if (!BASE_ARCHIVES_READ.FileData)
    {
      return 0;
    }
     
    BASE_ARCHIVES_READ.FileNames      =
      BASE_ARCHIVES_READ.FileNamesEnd =
          (PCHAR) BASE_MEMORY_GetMemBase2(0, 1);

    if (!BASE_ARCHIVES_READ.FileNames)
    {
      return 0;
    }

    BASE_ARCHIVES_TEST.ArchiveHandle = BASE_LFN_Open(ArchiveName, O_RDONLY | O_BINARY, 0644);
    if (BASE_ARCHIVES_TEST.ArchiveHandle ==  -1)
    {
      BASE_ERROROUT_EXTERN_OpenArchiveRead();
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }
    else
    {
      BASE_DOSFUNCS_LSeek(BASE_ARCHIVES_TEST.ArchiveHandle,
                     BASE_DIRDATA_Dir1.ArchiveBegin, SEEK_SET);

      BASE_ARCHIVES_READ_EXTERN_ReadArchiveProc();
      close(BASE_ARCHIVES_TEST.ArchiveHandle);
    }

    if (BASE_DIRDATA_Dir1.IsBroken)
    {
      BASE_ERROROUT_EXTERN_BrokenArchive();
      BASE_ERROR.ErrorCode = BASE_ERROR_BADCRC;
    }

    BASE_ARCHIVES_READ.FileData =
      (pBASE_FILELIST_FileData)
        BASE_MEMORY_ReAlloc((PVOID) BASE_ARCHIVES_READ.FileData,
                            BASE_ARCHIVES_READ.FileNumber
                              * sizeof(tBASE_FILELIST_FileData));

    BASE_ARCHIVES_READ.FileNames =
      (PCHAR) BASE_MEMORY_ReAlloc((PVOID) BASE_ARCHIVES_READ.FileNames,
                                  BASE_ARCHIVES_READ.FileNamesEnd
                                    - BASE_ARCHIVES_READ.FileNames);
 
    if (!BASE_FILELIST.List)
    {
      BASE_MEMORY_Optimize();
    }

    BASE_DIRDATA_Dir1.IsACE = !BASE_DIRDATA_Dir1.ArchiveType;

    BASE_ARCHIVES_READ_EXTERN_GetArchiveDescription();
  }
  else
  {
    if (!BASE_ERROR.ErrorCode)
    {
      BASE_ERROROUT_EXTERN_IsNotArchive();
      BASE_ERROR.ErrorCode = BASE_ERROR_OTHER;
    }
  }

  if (BASE_DIRDATA_Dir1.IsBroken)
  {
    BASE_ERROR.ErrorCode = BASE_ERROR_BADCRC;
  }

  return Result;
}
