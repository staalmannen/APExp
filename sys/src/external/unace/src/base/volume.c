#include <string.h>

#define INCL_BASE_VOLUME

#define INCL_BASE_ARCBLK
#define INCL_BASE_CONVERT
#define INCL_BASE_DIRDATA
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_EXTRACT
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#define INCL_BASE_VOLUME
#include "base/includes.h"

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPTERR
#define INCL_APPS_EXE_OUTPUT
#include "unace_includes.h"

tBASE_VOLUME BASE_VOLUME; //volume.h

#define ARCHIVEEXTENSIONS "ACE"

/*-----------------BASE_VOLUME_EXTERN_ChangeVolumeToProcess--------------*/

INT     BASE_VOLUME_EXTERN_ChangeVolumeToProcess(PCHAR VolumeName)
{
BOOL      DoAgain;
INT       Input;
tLFN      VolumeDirectory,
          ShortStr;

  BASE_STATE_EXTERN_OutputProcess(STR.looking_for, VolumeName, 1);

  do
  {
    DoAgain=0;

    if (!BASE_DOSFUNCS_FileExists(VolumeName)
        || !BASE_VOLUME.DoProcessAllVolumes)
    {
      do
      {
        Input = APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Copy, STR.Ready_to_process,
                  APPS_EXE_CONVERT_MakeStrShorter(ShortStr, VolumeName, 26));

        if (Input == 2)
        {
          BASE_PATHFUNC_SplitFileName(VolumeDirectory, VolumeName, VolumeName);

          APPS_EXE_INPUT_Input(VolumeDirectory, 70, STR.New_Path,
                                      STR.Enter_new_source_path, 0);

          BASE_CONVERT_StrCatBefore(BASE_PATHFUNC_AddSlashToEnd(VolumeDirectory),
                               VolumeName);
        }

        BASE_VOLUME.DoProcessAllVolumes = (Input == 1);

        if (Input == 3)
        {
          BASE_ERROR.ErrorCode = BASE_ERROR_USER;

          return 0;
        }
      }
      while (!BASE_DOSFUNCS_FileExists(VolumeName));
    }

    if (!BASE_ARCBLK_OpenArchive(VolumeName, 0, 0, 1, 0))
    {
      APPS_EXE_OUTPTERR_OutputError(STR.Error_while_reading_archive,
                               STR.File_not_found_or_archive_broken_);

      if (APPS_EXE_INPUT.LastKey != 27)
      {
        DoAgain = 1;
      }

      BASE_ERROR.ErrorCode = BASE_ERROR_USER;
    }
  }
  while (DoAgain);

  BASE_STATE_EXTERN_OutputProcess(STR.processing, VolumeName, 1);

  if (!BASE_ERROR.ErrorCode)
  {
  }

  return !BASE_ERROR.ErrorCode;
}


/*-----------------BASE_VOLUME_GetVolumeName-----------------------------*/

PCHAR BASE_VOLUME_GetVolumeName(PCHAR NewVolumeName, PCHAR VolumeName,
                                INT AddToVolumeNumber, BOOL IsSFX)
{
PCHAR     ExtensionPos;
INT       VolumeNumber;

  strcpy(NewVolumeName, VolumeName);

  if ((ExtensionPos = (PCHAR) strrchr(NewVolumeName, '.')) == NULL
      || !*(ExtensionPos + 1))
  {
    VolumeNumber = -1;
    ExtensionPos = NewVolumeName + strlen(NewVolumeName);
  }
  else
  {
    ExtensionPos++;

    VolumeNumber =
      (*(ExtensionPos + 1) - '0') * 10 + *(ExtensionPos + 2) - '0';

    if (!in(VolumeNumber, 0, 99))
    {
      VolumeNumber = -1;
    }

    if (in(*ExtensionPos, '0', '9'))
    {
      VolumeNumber += (*ExtensionPos - '0') * 100;
    }
  }

  VolumeNumber += AddToVolumeNumber;

  if (VolumeNumber < -1)
  {
    VolumeNumber = -1;
  }

  if (VolumeNumber == -1)
  {
    ///strcpy(ExtensionPos, ARCHIVEEXTENSIONS[IsSFX ? 4 : Type]);
    strcpy(ExtensionPos, ARCHIVEEXTENSIONS);
  }
  else
  {
    if (VolumeNumber < 100)
    {
      *ExtensionPos = 'C';
    }
    else
    {
      *ExtensionPos = VolumeNumber / 100 + '0';
    }

    *(ExtensionPos + 1) = (VolumeNumber / 10) % 10 + '0';
    *(ExtensionPos + 2) = VolumeNumber % 10 + '0';

    if (!BASE_DOSFUNCS_FileExists(NewVolumeName) && *ExtensionPos == 'C')
    {
      *ExtensionPos = 'c';
    }
  }

  return NewVolumeName;
}

/*-----------------BASE_VOLUME_NextVolumeToProcess-----------------------*/

INT     BASE_VOLUME_NextVolumeToProcess(BOOL IsZeroLengthFile)
{
INT       Result;

  if (BASE_VOLUME.DoNotProcessNextVolume)
  {
    return 0;
  }

  BASE_VOLUME.CurrentVolumeNumber++;

  BASE_ARCBLK_EXTERN_CloseArchive(1);

  BASE_VOLUME_GetVolumeName(BASE_ARCBLK.ArchiveFile,
                            BASE_ARCBLK.ArchiveFile, 1,
                            BASE_ARCBLK.Options.IsSFX);

  if (!BASE_VOLUME_EXTERN_ChangeVolumeToProcess(BASE_ARCBLK.ArchiveFile))
  {
    if (!BASE_ERROR.ErrorCode)
    {
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }

    return 0;
  }

  Result = BASE_ARCBLK_LoadBlock();

  if (Result && IsZeroLengthFile)
  {
    Result = BASE_ARCBLK_LoadBlock();
  }

  return Result;
}

/*-----------------BASE_VOLUME_PreviousVolumeToProcess-------------------*/

void    BASE_VOLUME_PreviousVolumeToProcess(void)
{
  BASE_ARCBLK_EXTERN_CloseArchive(1);

  BASE_VOLUME.CurrentVolumeNumber--;

  BASE_VOLUME_GetVolumeName(BASE_ARCBLK.ArchiveFile,
                            BASE_ARCBLK.ArchiveFile, -1,
                            BASE_DIRDATA_Dir1.IsSFX);

  if (!BASE_VOLUME_EXTERN_ChangeVolumeToProcess(BASE_ARCBLK.ArchiveFile))
  {
    if (!BASE_ERROR.ErrorCode)
    {
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }

    return;
  }

  return;
}

/*-----------------BASE_VOLUME_FirstVolumeToProcess----------------------*/

INT     BASE_VOLUME_FirstVolumeToProcess(PCHAR VolumeName)
{
tLFN      FirstVolumeName;

  if ((BASE_EXTRACT.DoExtractAllVolumes || BASE_DIRDATA_Dir1.IsSolid)
      && BASE_DIRDATA_Dir1.VolumeNumber)
  {
    strcpy(FirstVolumeName, VolumeName);
    BASE_VOLUME.CurrentVolumeNumber = 0;

    BASE_VOLUME_GetVolumeName(FirstVolumeName, FirstVolumeName, -100000,
                              BASE_DIRDATA_Dir1.IsSFX);

    if (!BASE_VOLUME_EXTERN_ChangeVolumeToProcess(FirstVolumeName))
    {
      return 0;
    }
  }
  else
  {
    if (!BASE_ARCBLK_OpenArchive(VolumeName, 0, 1, 1, 1))
    {
      return 0;
    }
  }

//  BASE_VOLUME.CurrentVolumeNumber = 0;

  return !BASE_ERROR.ErrorCode;
}
