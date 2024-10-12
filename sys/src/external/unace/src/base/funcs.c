#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define INCL_BASE_FUNCS

#define INCL_BASE_CONVERT
#define INCL_BASE_ARCBLK
#define INCL_BASE_DIRDATA
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_EXTRACT
#define INCL_BASE_FILELIST
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE

#include "base/includes.h"

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#include "unace_includes.h"

tBASE_FUNCS BASE_FUNCS;

/*-----------------BASE_FUNCS_EXTERN_MoveRealSysFileRequest--------------*/

INT     BASE_FUNCS_EXTERN_MoveDeleteRealSysFileRequest(void)
{
  return APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Delete_noun,
                           STR.Found_read_only__hidden_or_system_file_,
                           STR.Delete_it_anyway_);
// BASE_STATE.CurrentFileNameName
}

/*-----------------BASE_FUNCS_EXTERN_CreateDestinationFileRequestOverwrite----*/

BOOL    BASE_FUNCS_EXTERN_CreateDestinationFileRequestOverwrite(void)
{
CHAR      OutputStr[80],
          ShortStr[80];

  snprintf (OutputStr, sizeof(OutputStr), "%s %s", STR.File_already_exists_,
          APPS_EXE_CONVERT_MakeStrShorter(ShortStr, BASE_STATE.CurrentFileName, 30));

  return APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Copy_noun, OutputStr, STR.Overwrite_);
}

/*-----------------BASE_FUNCS_EXTERN_RequestOverwriteSysFile-------------*/

BOOL    BASE_FUNCS_EXTERN_RequestOverwriteSysFile(void)
{
CHAR      OutputStr[80],
          ShortStr[80];

  snprintf (OutputStr, sizeof(OutputStr), "%s %s",
          BASE_CONVERT_ToOEM(APPS_EXE_CONVERT_MakeStrShorter(ShortStr,
            BASE_STATE.CurrentFileName, 26)),
          STR.is_read_only__hidden_or_system_file_);

  return APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Copy, OutputStr,
                                           STR.Overwrite_it_anyway_);
}

// ====================================================================

/*-----------------BASE_FUNCS_Copy---------------------------------------*/

void    BASE_FUNCS_Copy(INT Mode)
{
  BASE_FILELIST.DoAddFileCheckIfValidFile =
    !BASE_DIRDATA_IsInArchive1 && BASE_DIRDATA_IsInArchive2;

  if ((BASE_EXTRACT.DoExtractAllVolumes
       && BASE_FILELIST_Create(1, 5, 1))
        ||
      (!BASE_EXTRACT.DoExtractAllVolumes
       && BASE_FILELIST_Create(1, Mode, 1)))
  {
    BASE_FUNCS_EXTERN_DoCopy(Mode);

    BASE_FILELIST_Done();
  }

  BASE_FILELIST.DoAddFileCheckIfValidFile = 0;
}

/*-----------------BASE_FUNCS_DeleteRealFile-----------------------------*/

INT     BASE_FUNCS_DeleteRealFile(PCHAR FileName, BOOL IsOverwriteDelete)
{
BOOL      Err = 0;
INT       Input;
UINT      Attr;

  if (!BASE_LFN_GetFileAttributes(FileName, &Attr))
  {
    if (Attr & BASE_DOSFUNCS_SUBDIR)
    {
      Err = BASE_LFN_RemoveDir(FileName);
    }
    else
    {
      if (Attr & (BASE_DOSFUNCS_RDONLY | BASE_DOSFUNCS_HIDDEN | BASE_DOSFUNCS_SYSTEM))
      {
        if (!BASE_FUNCS.DoDeleteAll)
        {
          if (IsOverwriteDelete)
          {
            Input = BASE_FUNCS_EXTERN_RequestOverwriteSysFile();
          }
          else
          {
            Input = BASE_FUNCS_EXTERN_MoveDeleteRealSysFileRequest();
          }

          BASE_FUNCS.DoDeleteAll = (Input == 1);

          if (Input == 3)
          {
            BASE_ERROR.ErrorCode = BASE_ERROR_USER;
          }
          
          if (Input > 1)
          {
            return 1;
          }
            
        }

        BASE_LFN_SetFileAttributes(FileName, BASE_DOSFUNCS_NORMAL);
      }

      Err = BASE_LFN_RemoveFile(FileName);
    }
  }

  if (Err && !BASE_ERROR.HardwareError)
  {
    if (IsOverwriteDelete)
    {
      BASE_ERROROUT_EXTERN_OverwriteDelete();
    }
    else
    {
      BASE_ERROROUT_EXTERN_MoveDelete();
    }

    return 1;
  }

  return 0;
}

/*-----------------BASE_FUNCS_CreatePathDirectories----------------------*/

void    BASE_FUNCS_CreatePathDirectories(PCHAR FileName)
{
PCHAR     SlashPos,
          NextSlashPos;
tBASE_LFN_DBL
          CreateDir;
tLFN      FullDir;
INT       BaseLen;

  BASE_PATHFUNC_SplitFileName(FullDir, CreateDir,
                              FileName);

  if (!FullDir[0])
  {
    return;
  }

  if (BASE_DOSFUNCS_FileExists(FullDir))
  {
    return;
  }

  BaseLen = BASE_PATHFUNC_GetDevicePathLen(FullDir);
  strncpy(CreateDir, FullDir, BaseLen);
  CreateDir[BaseLen] = 0;
  SlashPos = FullDir + BaseLen;

  do
  {
    if (!(NextSlashPos = strchr(SlashPos + 1, BASE_PATHFUNC_SEPARATOR)))
    {
      NextSlashPos = SlashPos + strlen(SlashPos);
    }

    strncat(CreateDir, SlashPos, NextSlashPos - SlashPos);

    if (!BASE_DOSFUNCS_FileExists(CreateDir)
          && BASE_LFN_MakeDir(CreateDir))
    {
      BASE_ERROROUT_EXTERN_CreateDir(CreateDir);
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }

    SlashPos = NextSlashPos;
  }
  while (*SlashPos);
}

/*-----------------BASE_FUNCS_CreateDestinationFile----------------------*/

INT     BASE_FUNCS_CreateDestinationFile(INT Attr)
{
INT       Handle,
          Input = 0,
          Len;

  snprintf (BASE_STATE.DestinationFileName, sizeof(BASE_STATE.DestinationFileName),
           "%s%s", BASE_PATHFUNC_GetDevicePathLen(BASE_STATE.CurrentFileName) ?
            "" : BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir2.Dir),
          BASE_STATE.CurrentFileName);

  BASE_LFN_ConvertFileName(BASE_STATE.DestinationFileName, Attr);
  BASE_FUNCS_CreatePathDirectories(BASE_STATE.DestinationFileName);

  if (Attr & BASE_DOSFUNCS_SUBDIR)
  {
    if (!BASE_DOSFUNCS_FileExists(BASE_STATE.DestinationFileName))
    {
      if (BASE_LFN_MakeDir(BASE_STATE.DestinationFileName))
      {
        Len = strlen(BASE_STATE.DestinationFileName);

        if (Len >= 4 &&
            !strcmp(&BASE_STATE.DestinationFileName[Len - 4], "\\*.*"))
        {
          BASE_STATE.DestinationFileName[Len - 4] = 0;
        }

        BASE_ERROROUT_EXTERN_CreateDir(BASE_STATE.DestinationFileName);

        return -1;
      }
    }
    else
    {
      if (!BASE_DOSFUNCS_IsDir(BASE_STATE.DestinationFileName))
      {
        BASE_ERROROUT_EXTERN_NameInUse();

        return -1;
      }
    }

    BASE_LFN_SetFileAttributes(BASE_STATE.DestinationFileName, Attr);

    return 0;
  }
  else
  {
    if (BASE_DOSFUNCS_FileExists(BASE_STATE.DestinationFileName))
    {
      if (!BASE_FUNCS.DoOverwriteAll)
      {

        Input = BASE_FUNCS_EXTERN_CreateDestinationFileRequestOverwrite();

        BASE_FUNCS.DoOverwriteAll = (Input == 1);

        if (Input == 3)
        {
          BASE_ERROR.ErrorCode = BASE_ERROR_USER;
        }
      }

      BASE_FUNCS.DidNotCopyAll |=
        (Input = ((Input && !BASE_FUNCS.DoOverwriteAll)
                  || BASE_FUNCS_DeleteRealFile(BASE_STATE.DestinationFileName, 1)));

      if (Input)
      {
        return -2;
      }
    }

    Handle = BASE_LFN_Open(BASE_STATE.DestinationFileName,
                           O_RDWR | O_CREAT | O_TRUNC | O_BINARY, 0644);
    if (Handle == -1)
    {
      BASE_ERROROUT_EXTERN_CreateFile();
    }

    return Handle;
  }
}
