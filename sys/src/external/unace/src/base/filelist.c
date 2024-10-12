#include <errno.h>
#include <stdio.h>
#include <string.h>

#define INCL_BASE_FILELIST

#define INCL_BASE_ARCHIVES_READ
#define INCL_BASE_CONVERT
#define INCL_BASE_DIRDATA
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_MEMORY
#define INCL_BASE_MSGOUT
#define INCL_BASE_PATHFUNC
#define INCL_BASE_VOLUME

#include "base/includes.h"

#define INCL_APPS_EXE_COMMLINE
#include "unace_includes.h"

tBASE_FILELIST BASE_FILELIST; //filelist.h


/*-----------------BASE_FILELIST_EXTERN_CommandLineCheck-----------------*/
BOOL    BASE_FILELIST_EXTERN_CommandLineCheck(PCHAR FileName,
                                              PCHAR CompareFileName1,
                                              PCHAR CompareFileName2)
{
  return !BASE_CONVERT_StrICmp(CompareFileName2, APPS_EXE_COMMLINE.ErrorFile)
         || !BASE_CONVERT_StrICmp(CompareFileName2, APPS_EXE_COMMLINE.OutFile);
}

/*-----------------BASE_FILELIST_RemoveDrive-----------------------------*/

PCHAR   BASE_FILELIST_RemoveDrive(PCHAR Path)
{
  return Path + BASE_PATHFUNC_GetDevicePathLen(Path);
}

/*-----------------BASE_FILELIST_Check-----------------------------------*/

PCHAR   BASE_FILELIST_Check(PCHAR FileName)
{
PCHAR     ListPosition,
          ListPosition2;

  if (BASE_CONVERT_StrNICmp(BASE_FILELIST.AddDir, FileName,
               strlen(BASE_FILELIST.AddDir)))
  {
    return NULL;
  }

  ListPosition = BASE_FILELIST.List;

  while (ListPosition != BASE_FILELIST.Last)
  {
    ListPosition2 = strchr(FileName, ':') ?
    		      ListPosition : BASE_FILELIST_RemoveDrive(ListPosition);

    if (!BASE_CONVERT_StrICmp(ListPosition2, FileName)
        || /*strpbrk(ListPosition2, "*?") //if added, directory expressions without wildcards will not be understood
           &&*/ BASE_PATHFUNC_WildCardCheck(ListPosition2, FileName))
    {
      return ListPosition;
    }

    ListPosition += BASE_FILELIST_ListStrLen(ListPosition);
  }

  return NULL;
}

/*-----------------BASE_FILELIST_ListStrLen------------------------------*/

INT     BASE_FILELIST_ListStrLen(PCHAR FileName)
{
  return strlen((PCHAR) FileName) + 1;
}

/*-----------------BASE_FILELIST_CheckExclusion--------------------------*/

PCHAR    BASE_FILELIST_CheckExclusion(PCHAR FileName)
{
PCHAR      ListPosition;

  ListPosition = BASE_FILELIST.SearchExcludeList;

  while (ListPosition != BASE_FILELIST.SearchExcludeListEnd)
  {
    ListPosition = BASE_FILELIST_RemoveDrive(ListPosition);

    if (BASE_PATHFUNC_WildCardCheck(ListPosition, FileName))
    {
      return ListPosition;
    }

    ListPosition += BASE_FILELIST_ListStrLen(ListPosition);
  }

  return NULL;
}

/*-----------------BASE_FILELIST_AddCheck--------------------------------*/

INT     BASE_FILELIST_AddCheck(PCHAR FileName)
{
PCHAR      ListPosition;

  if (BASE_ERROR_EXTERN_HandleCancel(1))
  {
    return 1;
  }

  ListPosition = BASE_FILELIST.List;

  while (ListPosition != BASE_FILELIST.Last)
  {
    if (!BASE_CONVERT_StrICmp(ListPosition, FileName))
    {
      return 1;
    }

    ListPosition += BASE_FILELIST_ListStrLen(ListPosition);
  }

  return 0;
}

/*-----------------BASE_FILELIST_Dir2FileTime----------------------------*/

LONG    BASE_FILELIST_Dir2FileTime(PCHAR FileName)
{
tLFN      Path;

  if (BASE_DIRDATA_IsInArchive2)
  {
    return 0;
  }
  else
  {
    snprintf(Path, sizeof(Path), "%s%s",
            BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir2.Dir),
            FileName);

    return BASE_LFN_GetFileTime(Path);
  }
}

/*-----------------BASE_FILELIST_AddFile---------------------------------*/

void    BASE_FILELIST_AddFile(PCHAR FileName, ULONGLONG FileSize,
                              ULONG FileTime, INT Attr)
{
BOOL      SavedDoRecurseSubDirectories;
UINT      FreshFileTime;
PCHAR     ExtensionPos;
tBASE_LFN_DBL
          CompareFileName1,
          CompareFileName2;

  SavedDoRecurseSubDirectories          = BASE_FILELIST.DoRecurseSubDirectories;
  BASE_FILELIST.DoRecurseSubDirectories = 0;

  if (BASE_FILELIST.DoAddFileCheckIfFileIsInList
      && BASE_FILELIST_AddCheck(FileName))
  {
    goto RETURN;
  }

  strcpy(CompareFileName2, FileName);

  if (BASE_DIRDATA_Dir1.IsMultiVol
      && (ExtensionPos = strrchr(FileName, '.'))
          > strrchr(FileName, BASE_PATHFUNC_SEPARATOR))
  {
    ExtensionPos++;

    if ((BASE_CONVERT_UpCase(*ExtensionPos) == 'C'
          || in(*ExtensionPos, '0', '9'))
        && in(*(ExtensionPos + 1), '0', '9')
        && in(*(ExtensionPos + 2), '0', '9'))
    {
      BASE_VOLUME_GetVolumeName(CompareFileName2, CompareFileName2,
                                -1000, BASE_DIRDATA_Dir1.IsSFX);
    }
  }

  if (BASE_FILELIST.DoAddFileCheckIfValidFile)
  {
    if (!strchr(CompareFileName2, ':') && CompareFileName2[0] != BASE_PATHFUNC_SEPARATOR)
    {
      BASE_CONVERT_StrCatBefore(
        BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir1.Dir),
        CompareFileName2);
    }

    snprintf(CompareFileName1, sizeof(CompareFileName1), "%s%s",
            BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir2.Dir),
            BASE_DIRDATA_Dir2.ArchiveName);

    if (!BASE_CONVERT_StrICmp(CompareFileName1, CompareFileName2)
        || BASE_FILELIST_EXTERN_CommandLineCheck(FileName,
                                                 CompareFileName1,
                                                 CompareFileName2))
    {
      goto RETURN;
    }
  }

  if (BASE_FILELIST_CheckExclusion(FileName))
  {
    goto RETURN;
  }

  if (!BASE_DIRDATA_IsInArchive2
      && (BASE_FILELIST.AddMode == 2 || BASE_FILELIST.AddMode == 3))
  {
    FreshFileTime = BASE_FILELIST_Dir2FileTime(FileName);

    if (BASE_FILELIST.AddMode == 2
        && (!FreshFileTime || FreshFileTime >= FileTime))
    {
      goto RETURN;
    }

    if (BASE_FILELIST.AddMode == 3 && FreshFileTime >= FileTime)
    {
      goto RETURN;
    }
  }

  if ((BASE_FILELIST.Last + BASE_FILELIST_ListStrLen(FileName)) -
         BASE_FILELIST.List > BASE_MEMORY_Size(BASE_FILELIST.List))
  {
    BASE_ERROROUT_EXTERN_ManyFilesError();

    goto RETURN;
  }

  strcpy(BASE_FILELIST.Last, FileName);
  BASE_FILELIST.Last += BASE_FILELIST_ListStrLen(FileName);

  if (BASE_FILELIST.ListFileData)
  {
    if (BASE_FILELIST.Number > BASE_FILELIST.MaxNumber)
    {
      BASE_ERROROUT_EXTERN_ManyFilesError();
    }
    else
    {
      BASE_FILELIST.ListFileData[BASE_FILELIST.Number].Size = FileSize;

      BASE_FILELIST.ListFileData[BASE_FILELIST.Number].Time.Fields = 
        BASE_DOSFUNCS_CalcFileTime(FileTime);

      if ((BASE_FILELIST.ListFileData[BASE_FILELIST.Number].Attr = Attr)
           & BASE_FILELIST_SUBDIR)
      {
        BASE_FILELIST.ListFileData[BASE_FILELIST.Number].Size = 0;
      }
    }
  }

  BASE_FILELIST.Number++;

  if (!(BASE_DIRDATA_IsInArchive1 && BASE_DIRDATA_Dir1.IsMultiVol))
  {
    BASE_FILELIST.SizeOfFiles += FileSize;

    if (BASE_DIRDATA_IsInArchive1 && BASE_DIRDATA_Dir1.IsSolid)
    {
      BASE_FILELIST.SizeOfFiles += BASE_FILELIST.SkippedSize;
    }
  }

RETURN:

  BASE_FILELIST.DoRecurseSubDirectories = SavedDoRecurseSubDirectories;
}

/*-----------------BASE_FILELIST_Init------------------------------------*/

void    BASE_FILELIST_Init(void)
{
INT       BufSize;

  BufSize = BASE_MEMORY_MemAvailBase2(2);

  if (!(BASE_FILELIST.Pos=
          BASE_FILELIST.Last =
          BASE_FILELIST.List = (PCHAR) BASE_MEMORY_GetMem(BufSize)))
  {
    return;
  }

  if (!(BASE_FILELIST.ListFileData =
         (pBASE_FILELIST_FileData) BASE_MEMORY_GetMemBase2(&BufSize, 1)))
  {
    BASE_MEMORY_FreeCheck(BASE_FILELIST.List);

    return;
  }

  BASE_FILELIST.MaxNumber = BufSize / sizeof(tBASE_FILELIST_FileData);
  BASE_FILELIST.Number    = 0;
}

/*-----------------BASE_FILELIST_Done------------------------------------*/

void    BASE_FILELIST_Done(void)
{
  BASE_MEMORY_FreeCheck(BASE_FILELIST.List);
  BASE_MEMORY_FreeCheck(BASE_FILELIST.ListFileData);
  BASE_MEMORY_Optimize();
}

/*-----------------BASE_FILELIST_Create----------------------------------*/

INT     BASE_FILELIST_Create(BOOL DoAddDirFirst, INT Mode,
                             BOOL DoOutputNoFilesError)
{
PVOID     SavedScreenPtr;
ULONG     PosIndex, LastIndex;

  BASE_MSGOUT_EXTERN_ListCreateBegin(&SavedScreenPtr);

  BASE_FILELIST.AddMode       = Mode;

  BASE_FILELIST.SkippedSize   =
    BASE_FILELIST.SizeOfFiles = 0;

  BASE_FILELIST_Init();

  BASE_FILELIST_SearchListArchiveCreate(); //(DoAddDirFirst);

  errno = 0;

  if (!BASE_ERROR.ErrorCode
      && BASE_FILELIST.List == BASE_FILELIST.Last
      && BASE_FILELIST.AddMode < 2 && DoOutputNoFilesError)
  {
    BASE_ERROROUT_EXTERN_NoFiles();
    BASE_ERROR.ErrorCode = BASE_ERROR_FILES;
  }

  BASE_FILELIST.ListFileData =
    (pBASE_FILELIST_FileData) BASE_MEMORY_ReAlloc(
                                BASE_FILELIST.ListFileData,
                                BASE_FILELIST.Number
                                  * sizeof(tBASE_FILELIST_FileData));

  PosIndex  = BASE_FILELIST.Pos  - BASE_FILELIST.List;
  LastIndex = BASE_FILELIST.Last - BASE_FILELIST.List;
  
  BASE_FILELIST.List  = (PCHAR) BASE_MEMORY_ReAlloc(BASE_FILELIST.List,
                                                    LastIndex);

  BASE_FILELIST.Pos   = BASE_FILELIST.List + PosIndex;
  BASE_FILELIST.Last  = BASE_FILELIST.List + LastIndex;

  BASE_MEMORY_Optimize();

  if (BASE_ERROR.ErrorCode)
  {
    BASE_FILELIST_Done();

    return 0;
  }
  else
  {
    return 1;
  }
}

/*-----------------BASE_FILELIST_SearchListArchiveCreateProcessFile------*/

void    BASE_FILELIST_SearchListArchiveCreateProcessFile(PCHAR FileName,
                                              tBASE_FILELIST_FileData FileData)
{
PCHAR     ListPosition;
INT       AddDirLen;
tLFN	  PureFileName;

  AddDirLen = strlen(BASE_FILELIST.AddDir);

  if (BASE_CONVERT_StrNICmp(BASE_FILELIST.AddDir, FileName, AddDirLen))
  {
    return;
  }

  ListPosition = BASE_FILELIST.SearchList;

  while (ListPosition != BASE_FILELIST.SearchListEnd
         && !BASE_ERROR_EXTERN_HandleCancel(1))
  {
    strcpy(PureFileName, FileName);
    BASE_PATHFUNC_NTFSStreamGetFileName(PureFileName);

    if (BASE_PATHFUNC_WildCardCheck(ListPosition, PureFileName + AddDirLen))
    {
      BASE_FILELIST_AddFile(FileName, FileData.Size,
                       FileData.Time.Raw, FileData.Attr);

      return;
    }

    ListPosition += strlen(ListPosition) + 1;
  }

  BASE_FILELIST.SkippedSize += FileData.Size;
}

/*-----------------BASE_FILELIST_VolumeCreate----------------------------*/

void    BASE_FILELIST_VolumeCreate(void)
{
PCHAR      ListPosition;
tBASE_LFN_DBL
          FileName;

  ListPosition = BASE_FILELIST.SearchList;

  while (ListPosition != BASE_FILELIST.SearchListEnd
         && !BASE_ERROR_EXTERN_HandleCancel(1))
  {

    snprintf (FileName, sizeof(FileName), "%s%s", BASE_FILELIST.AddDir, ListPosition);
    BASE_FILELIST_AddFile(FileName, 0, 0, 0);

    ListPosition += strlen(ListPosition) + 1;
  }
}

/*-----------------BASE_FILELIST_SearchListArchiveCreate----------------*/

void    BASE_FILELIST_SearchListArchiveCreate(void)
{
tLFN      ArchiveName;

  if (BASE_DIRDATA_Dir1.IsMultiVol)
  {
    BASE_FILELIST_VolumeCreate();
  }
  else
  {
    BASE_ARCHIVES_READ.ProcessFile =
      BASE_FILELIST_SearchListArchiveCreateProcessFile;

    snprintf (ArchiveName, sizeof(ArchiveName), "%s%s",
            BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir1.Dir),
            BASE_DIRDATA_Dir1.ArchiveName);

    if (BASE_ARCHIVES_READ_ReadArchive(ArchiveName))
    {
      BASE_ARCHIVES_READ_GetArchiveList();
    }
  }
}
