#include <stdio.h>
#include <string.h>

#define INCL_BASE_PATHFUNC

#define INCL_BASE_CONVERT

#include "base/includes.h"

tBASE_PATHFUNC BASE_PATHFUNC;

/*-----------------BASE_PATHFUNC_ToDOSPathSeparatorN---------------------*/

void    BASE_PATHFUNC_ToDOSPathSeparatorN(PCHAR Path, INT N)
{
INT       I;

  for (I = 0; I < N; I++)
  {
    if (Path[I] == '/')
    {
      Path[I] = '\\';
    }
  }
}

/*-----------------BASE_PATHFUNC_ToSystemPathSeparatorN------------------*/

void    BASE_PATHFUNC_ToSystemPathSeparatorN(PCHAR Path, INT N)
{
INT       I;

  for (I = 0; I < N; I++)
  {
    if (Path[I] == '/' || Path[I] == '\\')
    {
      Path[I] = BASE_PATHFUNC_SEPARATOR;
    }
  }
}

/*-----------------BASE_PATHFUNC_ToDOSPathSeparator----------------------*/

void    BASE_PATHFUNC_ToDOSPathSeparator(PCHAR Path)
{
  BASE_PATHFUNC_ToDOSPathSeparatorN(Path, strlen(Path));
}

/*-----------------BASE_PATHFUNC_ToSystemPathSeparator-------------------*/

void    BASE_PATHFUNC_ToSystemPathSeparator(PCHAR Path)
{
  BASE_PATHFUNC_ToSystemPathSeparatorN(Path, strlen(Path));
}

/*-----------------BASE_PATHFUNC_RemoveSlash-----------------------------*/

PCHAR   BASE_PATHFUNC_RemoveSlash(PCHAR Path)
{
INT       Len;

  strcpy(BASE_PATHFUNC.AddSlashToEndStr, Path);
  Len = strlen(BASE_PATHFUNC.AddSlashToEndStr);

  if (Len && BASE_PATHFUNC.AddSlashToEndStr[--Len] == BASE_PATHFUNC_SEPARATOR)
  {
    BASE_PATHFUNC.AddSlashToEndStr[Len] = 0;
  }

  return BASE_PATHFUNC.AddSlashToEndStr;
}

/*-----------------BASE_PATHFUNC_AddSlashToEnd---------------------------*/

PCHAR   BASE_PATHFUNC_AddSlashToEnd(PCHAR Path)
{
  sprintf(BASE_PATHFUNC.AddSlashToEndStr, "%s%c", Path,
          Path[0]
          && Path[strlen(Path) - 1] != BASE_PATHFUNC_SEPARATOR
   	  && (!Path[1] || !Path[2] || Path[2] != BASE_PATHFUNC_SEPARATOR || Path[3]) ?
            BASE_PATHFUNC_SEPARATOR : 0);

  return BASE_PATHFUNC.AddSlashToEndStr;
}

/*-----------------BASE_PATHFUNC_WildCardCheck---------------------------*/

INT     BASE_PATHFUNC_WildCardCheck(PCHAR WildCardStr, PCHAR Path)
{
BOOL      DoRepeat;
PCHAR     SlashPos,
          NextSlashPos,
          WildCardDir,
          WildCardSpecification;
tLFN      TempWildCardStr,
          TempPath;
tBASE_LFN_DBL
          CompareStr1,
          CompareStr2;
INT       I,
          DirLen,
          J,
          CompareLen;

  strcpy(TempWildCardStr, WildCardStr);
  strcpy(TempPath, Path);
//  BASE_PATHFUNC_NTFSStreamGetFileName(Path);
  Path = TempPath;

  WildCardSpecification = strrchr(TempWildCardStr, BASE_PATHFUNC_SEPARATOR);

  if (WildCardSpecification)
  {
    WildCardDir = TempWildCardStr;
    *(WildCardSpecification++) = 0;
  }
  else
  {
    WildCardDir = "";
    WildCardSpecification = TempWildCardStr;
  }

  DirLen = strlen(WildCardDir);

  CompareLen =
    (!strpbrk(WildCardStr, "*?")
      && BASE_PATHFUNC.DoWildCardCheckMatchingPath) ?
    0 : strlen(Path) - DirLen - 1;

  for (J = 0; J <= CompareLen; J++)
  {
    if (!BASE_CONVERT_StrNICmp(WildCardDir, Path, DirLen)
        && (!J || Path[-1] == BASE_PATHFUNC_SEPARATOR)
        && WildCardSpecification[0]
        && (!DirLen || Path[DirLen] == BASE_PATHFUNC_SEPARATOR || !Path[DirLen]))
    {
      SlashPos = DirLen ? &Path[DirLen + 1] : Path;

      do
      {
        DoRepeat = 0;
        strcpy(CompareStr1, SlashPos);

        if ((NextSlashPos = strchr(SlashPos + 1, BASE_PATHFUNC_SEPARATOR)))
        {
          CompareStr1[NextSlashPos - SlashPos] = 0;
        }

        BASE_CONVERT_StrUpr(CompareStr1);
        BASE_PATHFUNC_ExtendWildCardStr(CompareStr1);

        strcpy(CompareStr2, WildCardSpecification);
        BASE_CONVERT_StrUpr(CompareStr2);
        BASE_PATHFUNC_ExtendWildCardStr(CompareStr2);

        for (I = 0; I < BASE_LFN_DOUBLEMAXLEN; I++)
        {
          if (CompareStr2[I] != '?' && CompareStr2[I] != CompareStr1[I])
          {
            DoRepeat = 1;

            break;
          }
        }

        if (!DoRepeat)
        {
          return 1;
        }

        SlashPos = NextSlashPos + 1;
      }
      while (NextSlashPos && strpbrk(WildCardStr, "?*"));
    }

    Path++;
  }

  return 0;
}

/*-----------------BASE_PATHFUNC_ExtendWildCardStr-----------------------*/

void    BASE_PATHFUNC_ExtendWildCardStr(PCHAR SourceStr)
{
tBASE_LFN_DBL
          TargetStr;
PCHAR     PointPos,
          WildcardPos;
INT       SourceIndex,
          TargetIndex,
          CharsToCopy;

  PointPos    = strrchr(SourceStr, '.'),
  WildcardPos = strchr(SourceStr, '*');

  if (WildcardPos < PointPos && WildcardPos)
  {
    SourceIndex = WildcardPos - SourceStr;
  }
  else
  {
    if (PointPos)
    {
      SourceIndex = PointPos - SourceStr;
    }
    else
    {
      SourceIndex = WildcardPos ?
                      WildcardPos - SourceStr :
                      strlen(SourceStr);
    }
  }

  strncpy(TargetStr, SourceStr, SourceIndex);
  TargetIndex = SourceIndex;

  if (SourceStr[SourceIndex] == '*')
  {
    memset(&TargetStr[TargetIndex], '?', BASE_LFN_MAXLEN - TargetIndex);
    TargetIndex = BASE_LFN_MAXLEN;
  }

  memset(&TargetStr[TargetIndex], '.', BASE_LFN_MAXLEN - TargetIndex);
  TargetIndex = BASE_LFN_MAXLEN;

  PointPos = strrchr(SourceStr, '.');

  if (PointPos)
  {
    SourceIndex = PointPos - SourceStr + 1;
    CharsToCopy = 0;

    while (SourceStr[SourceIndex] && SourceStr[SourceIndex] != '*')
    {
      SourceIndex++;
      CharsToCopy++;
    }

    strncpy(&TargetStr[BASE_LFN_MAXLEN],
            &SourceStr[SourceIndex - CharsToCopy], CharsToCopy);

    TargetIndex += CharsToCopy;
  }

  if (SourceStr[SourceIndex] == '*')
  {
    memset(&TargetStr[TargetIndex], '?', BASE_LFN_DOUBLEMAXLEN - TargetIndex);
    TargetIndex = BASE_LFN_DOUBLEMAXLEN - 1;
  }

  memset(&TargetStr[TargetIndex], '.', BASE_LFN_DOUBLEMAXLEN - TargetIndex);

  memcpy(SourceStr, TargetStr, BASE_LFN_DOUBLEMAXLEN);
}

/*-----------------BASE_PATHFUNC_GetDevicePathLen------------------------*/

INT     BASE_PATHFUNC_GetDevicePathLen(PCHAR Path)
{
PCHAR     SlashPos;
INT       Result;

  Result = 0;

  if (Path[0] == BASE_PATHFUNC_SEPARATOR)
  {
    if (Path[1] == BASE_PATHFUNC_SEPARATOR)
    {
      if (!(SlashPos = strchr(&Path[2], BASE_PATHFUNC_SEPARATOR)))
      {
        return 0;
      }

      if (!(SlashPos = strchr(SlashPos + 1, BASE_PATHFUNC_SEPARATOR)))
      {
        return 0;
      }

      Result = SlashPos - Path + 1;
    }
    else
    {
      Result = 1;
    }
  }
  else
  {
    if (Path[1] == ':')
    {
      Result = 2;

      if (Path[2] == BASE_PATHFUNC_SEPARATOR)
      {
        Result++;
      }
    }
  }

  return Result;
}

/*-----------------BASE_PATHFUNC_SplitFileName---------------------------*/

void    BASE_PATHFUNC_SplitFileName(PCHAR Dir, PCHAR FileName, PCHAR Path)
{
PCHAR     SlashPos;

  strcpy(FileName, Path);
  strcpy(Dir, FileName);
  SlashPos = strrchr(Dir, BASE_PATHFUNC_SEPARATOR);

  if (SlashPos)
  {
    if (SlashPos == Dir
        || *(SlashPos - 1) == ':' || *(SlashPos - 1) == BASE_PATHFUNC_SEPARATOR)
    {
      SlashPos++;
    }
  }
  else
  {
    SlashPos = Dir;
  }

  *SlashPos = 0;
  SlashPos  = SlashPos - Dir + FileName;

  if (*SlashPos == BASE_PATHFUNC_SEPARATOR)
  {
    SlashPos++;
  }

  strcpy(FileName, SlashPos);
}

/*-----------------BASE_PATHFUNC_CompletePath----------------------------*/

void    BASE_PATHFUNC_CompletePath(PCHAR Path)
{
tLFN      CurrentDir;
INT       CurrentDirLen;
/*
  if ((Path[0] == BASE_PATHFUNC_SEPARATOR
          && Path[1] != BASE_PATHFUNC_SEPARATOR
        || !strchr(Path, ':'))
      && Path[0] != '/')
*/
  if ((Path[0] == '\\' && Path[1] != '\\')
       || (Path[0] != BASE_PATHFUNC_SEPARATOR 
#if defined(_WIN32)
       && !strchr(Path, ':')
#endif
          )
       )
  {
    getcwd(CurrentDir, sizeof(CurrentDir));
    strcpy(CurrentDir, BASE_PATHFUNC_AddSlashToEnd(CurrentDir));

/* This is valid only under windows systems with "<drive letter>:" style file names */
#if defined(_WIN32)
    if (Path[0] == BASE_PATHFUNC_SEPARATOR)
    {
      CurrentDir[2] = 0;
    }
#endif

    CurrentDirLen = strlen(CurrentDir);
    memmove(&Path[CurrentDirLen], Path, strlen(Path) + 1);
    memmove(Path, CurrentDir, CurrentDirLen);
  }

/* This is valid only under windows systems with "<drive letter>:" style file names */
#if defined(_WIN32)
  if (Path[1] == ':' && Path[2] != BASE_PATHFUNC_SEPARATOR)
  {
    BASE_LFN_GetCurrentDirOfDrive(BASE_CONVERT_UpCase(Path[0]) - 'A',
                                  CurrentDir,
                                  BASE_LFN_MAXLEN);

    strcpy(Path, &Path[2]);

    BASE_CONVERT_StrCatBefore(
      Path[0] ? BASE_PATHFUNC_AddSlashToEnd(CurrentDir) : CurrentDir, Path);
  }
#endif
}

/*-----------------BASE_PATHFUNC_IsNTFSStreamName------------------------*/

BOOL    BASE_PATHFUNC_IsNTFSStreamName(PCHAR Path)
{
PCHAR     Ptr;

  if ((Ptr = strrchr(Path, ':')))
  {
    return *(Ptr + 1) != '\\';
  }
  else
  {
    return 0;
  }
}

/*-----------------BASE_PATHFUNC_NTFSStreamGetFileName-------------------*/

void    BASE_PATHFUNC_NTFSStreamGetFileName(PCHAR Path)
{
PCHAR     Ptr;

  if ((Ptr = strrchr(Path, ':')) && *(Ptr + 1) != '\\')
  {
    *Ptr = 0;
  }
}
