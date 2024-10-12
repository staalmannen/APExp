#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

#define INCL_APPS_UNACE_EXE_COMMLINE

#define INCL_BASE_ARCBLK
#define INCL_BASE_ARCHIVES_TEST
#define INCL_BASE_BITWIDTH
#define INCL_BASE_COMMENTS
#define INCL_BASE_CONVERT
#define INCL_BASE_CRC
#define INCL_BASE_CRYPT
#define INCL_BASE_DCPR
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_EXTRACT
#define INCL_BASE_FILELIST
#define INCL_BASE_FUNCS
#define INCL_BASE_MEMORY
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#define INCL_BASE_VOLUME

#define INCL_APPS_EXE_ACEFUNCS
#define INCL_APPS_EXE_COMMLINE
#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT
#define INCL_APPS_EXE_OUTPTERR

#define INCL_APPS_UNACE_EXE_COMMLINE

#include "unace_includes.h"

tAPPS_EXE_COMMLINE APPS_EXE_COMMLINE;

PCHAR const APPS_UNACE_EXE_COMMLINE_EXTRACTCOMMANDS = "\x04\x00";
PCHAR const APPS_UNACE_EXE_COMMLINE_COMMANDSTRINGS
          [APPS_UNACE_EXE_COMMLINE_COMMANDSNUMBER + 1] =
{"E",   "L",                    // 0, 1
 "T",   "V",                    // 2, 3
 "X",   ""};                    // 4, 5

PCHAR const APPS_UNACE_EXE_COMMLINE_SWITCHESSTRINGS
          [APPS_UNACE_EXE_COMMLINE_SWITCHESNUMBER + 1] =
{"C*",   "ERR*",                // 0, 1
 "F*",   "O*",                  // 2, 3
 "OUT*", "P*",                  // 4, 5
 "X*",   "Y*",                  // 6, 7
 ""};                            // 8

tAPPS_UNACE_EXE_COMMLINE APPS_UNACE_EXE_COMMLINE;


/*-----------------APPS_UNACE_EXE_COMMLINE_HELP_PrintCommandLineHelp-----*/
void    APPS_UNACE_EXE_COMMLINE_HELP_PrintHelp(BOOL DoPrintCopyRight)
{
INT       I;

  for (I = (DoPrintCopyRight ? 0 : APPS_UNACE_EXE_COMMLINE_HELP_COPYRIGHTLINES);
       (I < (DoPrintCopyRight ? APPS_UNACE_EXE_COMMLINE_HELP_COPYRIGHTLINES :
             APPS_EXE_MESSAGES_COMMLINEHELPLINES))
       && !BASE_ERROR_EXTERN_HandleCancel(1); I++)
  {
    APPS_EXE_OUTPUT_Write(STR.CommlineHelp[I]);
    APPS_EXE_OUTPUT_FullScreenKeyWait();
  }
}


/*-----------------APPS_UNACE_EXE_COMMLINE_Init--------------------------*/

void    APPS_UNACE_EXE_COMMLINE_Init(void)
{
  INT SearchExcludeListMax;
  
  APPS_EXE_COMMLINE.TimeOutLimit = 600;

  BASE_FILELIST.SearchExcludeListEnd =
    BASE_FILELIST.SearchExcludeList  =
        (PCHAR) BASE_MEMORY_GetMemBase2(&SearchExcludeListMax,
                                        1);

  BASE_FILELIST.SearchExcludeListMax = SearchExcludeListMax + 
                                       BASE_FILELIST.SearchExcludeList;

  APPS_EXE_OUTPUT.DoUseStdOutput = 1;

  APPS_UNACE_EXE_COMMLINE.IsSFX  =
        BASE_ARCHIVES_TEST_ArchiveTest(APPS_EXE_COMMLINE.Arguments[0],
                                       BASE_ARCHIVES_TEST.MaxTestSectors, 1);

  if (APPS_UNACE_EXE_COMMLINE.IsSFX)
  {
    snprintf (APPS_EXE_MESSAGES.FirstCommandLineHelpLine, sizeof(APPS_EXE_MESSAGES.FirstCommandLineHelpLine),
            "ACE-SFX v" BASE_VERSION_VERSIONSTR "  %-42s"
            __DATE__ "  " __TIME__,
            STR.Copyright_by_ACE_Compression_Software);

    STR.CommlineHelp[3] = STR.SFXUsage;
  }

  APPS_UNACE_EXE_COMMLINE_HELP_PrintHelp(1);
}

/*-----------------APPS_UNACE_EXE_COMMLINE_Done--------------------------*/

void    APPS_UNACE_EXE_COMMLINE_Done(void)
{
PCHAR     ActionStr;
CHAR      OutputStr[160],
          SizeStr1[15],
          SizeStr2[15];

  if (BASE_STATE.SummaryFileCount)
  {
    switch (APPS_EXE_COMMLINE.Command)
    {
      case APPS_UNACE_EXE_COMMLINE_COMMAND_L:
      case APPS_UNACE_EXE_COMMLINE_COMMAND_V:
      {
        ActionStr = STR.listed;

        break;
      }

      case APPS_UNACE_EXE_COMMLINE_COMMAND_T:
      {
        ActionStr = STR.tested;

        break;
      }

      default:
      {
        ActionStr = STR.extracted;
      }
    }

    snprintf (OutputStr, sizeof(OutputStr),
            STR._s__d_files__totaling__s_bytes__compressed__s_,
            ActionStr, BASE_STATE.SummaryFileCount,
            APPS_EXE_CONVERT_ToByteUnitStr(SizeStr1, BASE_STATE.SummaryUnComprBytes),
            APPS_EXE_CONVERT_ToByteUnitStr(SizeStr2, BASE_STATE.SummaryComprBytes));

    APPS_EXE_OUTPUT_Write(OutputStr);

    if (BASE_STATE.SumErrors)
    {
      snprintf (OutputStr, sizeof(OutputStr), STR.Got_CRC_check_errors_on__d__s_,
                BASE_STATE.SumErrors, BASE_STATE.SumErrors == 1 ?
                STR.file : STR.files);

      APPS_EXE_OUTPUT_Write(OutputStr);
    }
  }

  #ifdef __unix__
    printf("\n");
  #endif
}

/*-----------------APPS_UNACE_EXE_COMMLINE_SignalHandler-----------------*/

void    APPS_UNACE_EXE_COMMLINE_SignalHandler(INT SignalNumber)
{
  BASE_ERROR.ErrorCode        = BASE_ERROR_USER;
  APPS_EXE_COMMLINE.IsHitCTRL = 1;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_ProcessingInit----------------*/

void    APPS_UNACE_EXE_COMMLINE_ProcessingInit(void)
{
  #ifdef SIGBREAK
    signal(SIGBREAK, APPS_UNACE_EXE_COMMLINE_SignalHandler);
  #endif
  
  signal(SIGINT, APPS_UNACE_EXE_COMMLINE_SignalHandler);
}

/*-----------------APPS_UNACE_EXE_COMMLINE_FileListAddFileName-----------*/

INT     APPS_UNACE_EXE_COMMLINE_FileListAddFileName(PCHAR FileName,
                                                      PCHAR *ListEnd,
                                                      PCHAR ListMax)
{
INT       StrLen;

  StrLen = strlen(FileName) + 1;

  if (*ListEnd + StrLen > ListMax)
  {
    BASE_ERROROUT_EXTERN_ManyFilesError();

    return 0;
  }
  else
  {
    BASE_CONVERT_StrUpr(FileName);
    memcpy(*ListEnd, FileName, StrLen);
    *ListEnd += StrLen;

    return 1;
  }
}

/*-----------------APPS_UNACE_EXE_COMMLINE_FileListAddFiles--------------*/

void    APPS_UNACE_EXE_COMMLINE_FileListAddFiles(PCHAR Files,
                                                   PCHAR *ListEnd,
                                                   PCHAR ListMax)
{
tBASE_LFN_DBL
          FileList;
PCHAR     FileNameEnd;
INT       Handle,
          Pos,
          Len,
          Read;

  BASE_PATHFUNC_ToSystemPathSeparator(Files);

  if (*Files == '@')
  {
    Files++;

    if ((Handle = BASE_LFN_Open(Files, O_BINARY | O_RDONLY,
                                S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
    {
      printf("\n%s: %s\n", STR.List_file_does_not_exist, Files);
      APPS_EXE_COMMLINE.Error = 1;

      return;
    }

    Read  =
      Pos = 0;

    do
    {
      if (Read < BASE_LFN_MAXLEN)
      {
        BASE_DOSFUNCS_LSeek(Handle, Pos + Read, SEEK_SET);

        if (!(Read += read(Handle, &FileList[Read], sizeof(FileList) - Read)))
        {
          break;
        }
      }

      if (!(FileNameEnd = strpbrk(FileList, ";\x0d\x0a")))
      {
        FileNameEnd = &FileList[Read];
      }

      if (FileNameEnd > &FileList[Read])
      {
        FileNameEnd = &FileList[Read];
      }

      *FileNameEnd = 0;

      Len = strlen(FileList);

      if (Len)
      {
//        APPS_UNACE_EXE_COMMLINE_FileListAddFileName(FileList, ListEnd, ListMax);
        APPS_UNACE_EXE_COMMLINE_FileListAddFileName(
	  BASE_CONVERT_ToANSI(FileList), ListEnd, ListMax);
      }

      if (Read > Len)
      {
        memcpy(FileList, &FileList[Len + 1], Read - Len - 1);
        Read -= Len + 1;
      }
      else
      {
        Read = 0;
      }

      Pos += Len + 1;
    }
    while (!BASE_ERROR.ErrorCode);

    close(Handle);
  }
  else
  {
    APPS_UNACE_EXE_COMMLINE_FileListAddFileName(Files, ListEnd, ListMax);
  }

  return;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_GetFileListInit---------------*/

void    APPS_UNACE_EXE_COMMLINE_GetFileListInit(void)
{
  INT SearchListMax;
  BASE_FILELIST.SearchListEnd =
    BASE_FILELIST.SearchList  =
       (PCHAR) BASE_MEMORY_GetMemBase2(&SearchListMax,1);

  BASE_FILELIST.SearchListMax = SearchListMax + BASE_FILELIST.SearchListEnd;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_GetFileListDone---------------*/

void    APPS_UNACE_EXE_COMMLINE_GetFileListDone(void)
{
INT       ListSize;

  if (BASE_FILELIST.SearchListEnd == BASE_FILELIST.SearchList)
  {
    strcpy(BASE_FILELIST.SearchList, "*.*");
    BASE_FILELIST.SearchListEnd += 4;
  }

  ListSize = BASE_FILELIST.SearchListEnd - BASE_FILELIST.SearchList;

  BASE_FILELIST.SearchList =
    (PCHAR) BASE_MEMORY_ReAlloc(BASE_FILELIST.SearchList, ListSize);

  BASE_FILELIST.SearchListEnd = BASE_FILELIST.SearchList + ListSize;

  ListSize = BASE_FILELIST.SearchExcludeListEnd - BASE_FILELIST.SearchExcludeList;

  BASE_FILELIST.SearchExcludeList =
    (PCHAR) BASE_MEMORY_ReAlloc(BASE_FILELIST.SearchExcludeList, ListSize);

  BASE_FILELIST.SearchExcludeListEnd = BASE_FILELIST.SearchExcludeList + ListSize;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_GetFileList-------------------*/

BOOL    APPS_UNACE_EXE_COMMLINE_GetFileList(void)
{
PCHAR     Files,
          FilesLastChar;

  while (APPS_EXE_COMMLINE.ArgumentCount < APPS_EXE_COMMLINE.ArgumentsNumber
         && APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount][0]
              != '-')
  {
    Files = APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount++];
    FilesLastChar = Files + strlen(Files) - 1;

    if (*FilesLastChar == BASE_PATHFUNC_SEPARATOR)
    {
      *FilesLastChar = 0;
    }

    if (*FilesLastChar == 0 && Files[0] != '@')
    {
      if (*(FilesLastChar - 1) == ':')
      {
        *FilesLastChar = BASE_PATHFUNC_SEPARATOR;
      }

      APPS_EXE_COMMLINE.TargetDir = Files;
    }
    else
    {
      APPS_UNACE_EXE_COMMLINE_FileListAddFiles(Files,
        &BASE_FILELIST.SearchListEnd,
        BASE_FILELIST.SearchListMax);
    }
  }

  return APPS_EXE_COMMLINE.Error;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_GetCommand--------------------*/

INT     APPS_UNACE_EXE_COMMLINE_GetCommand(void)
{
INT       I;

  if (APPS_EXE_COMMLINE.ArgumentCount == APPS_EXE_COMMLINE.ArgumentsNumber)
  {
    if (APPS_UNACE_EXE_COMMLINE.IsSFX)
    {
      APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount] = "x";
      APPS_EXE_COMMLINE.ArgumentsNumber++;

      APPS_UNACE_EXE_COMMLINE.IsSFXNoCommand = 1;
    }
    else
    {
      printf("\n%s", STR.Missing_command_);
      APPS_EXE_COMMLINE.Error = 1;

      return APPS_EXE_COMMLINE.Error;
    }
  }

  for (I = 0; I < APPS_UNACE_EXE_COMMLINE_COMMANDSNUMBER; I++)
  {
    if (!BASE_CONVERT_StrICmp(APPS_UNACE_EXE_COMMLINE_COMMANDSTRINGS[I],
               APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount]))
    {
      APPS_EXE_COMMLINE.Command = I;
      APPS_EXE_COMMLINE.ArgumentCount++;

      if (APPS_EXE_COMMLINE.Command == APPS_UNACE_EXE_COMMLINE_COMMAND_L
          || APPS_EXE_COMMLINE.Command == APPS_UNACE_EXE_COMMLINE_COMMAND_V)
      {
        APPS_EXE_OUTPUT.DoUseStdOutput = 1;
      }

      return APPS_EXE_COMMLINE.Error;
    }
  }

  printf("\n%s: %s\n", STR.Unknown_command,
         APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount]);

  APPS_EXE_COMMLINE.Error = 1;

  return APPS_EXE_COMMLINE.Error;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_ToggleSwitch------------------*/

void    APPS_UNACE_EXE_COMMLINE_ToggleSwitch(PCHAR SwitchChar, PINT Variable)
{
  if (!(*SwitchChar) || (*SwitchChar == '+' && *(SwitchChar + 1) == 0))
  {
    *Variable = 1;
  }
  else
  {
    if (*SwitchChar == '-' && *(SwitchChar + 1) == 0)
    {
      *Variable = 0;
    }
    else
    {
      printf("\n%s: %s\n", STR.Switch_error,
             APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount]);

      APPS_EXE_COMMLINE.Error = 1;
    }
  }
}

/*-----------------APPS_UNACE_EXE_COMMLINE_GetSwitches-------------------*/

BOOL    APPS_UNACE_EXE_COMMLINE_GetSwitches(void)
{
PCHAR     Switch;
INT       SwitchNumber,
          StrLen;

  while (!APPS_EXE_COMMLINE.Error &&
         APPS_EXE_COMMLINE.ArgumentCount < APPS_EXE_COMMLINE.ArgumentsNumber
         && APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount][0]
              == '-')
  {

    Switch = APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount] + 1;

    for (SwitchNumber = 0;
         SwitchNumber < APPS_UNACE_EXE_COMMLINE_SWITCHESNUMBER;
         SwitchNumber++)
    {
      StrLen = strlen(APPS_UNACE_EXE_COMMLINE_SWITCHESSTRINGS[SwitchNumber]);

      if (SwitchNumber == APPS_UNACE_EXE_COMMLINE_SWITCH_UNKNOWN
          || !BASE_CONVERT_StrICmp(
                APPS_UNACE_EXE_COMMLINE_SWITCHESSTRINGS[SwitchNumber], Switch)
          || (APPS_UNACE_EXE_COMMLINE_SWITCHESSTRINGS[
                SwitchNumber][StrLen - 1] == '*'
              && !BASE_CONVERT_StrNICmp(
                    APPS_UNACE_EXE_COMMLINE_SWITCHESSTRINGS[SwitchNumber],
                    Switch, StrLen - 1)))
      {
        switch (SwitchNumber)
        {
          case APPS_UNACE_EXE_COMMLINE_SWITCH_C:
          {
            APPS_UNACE_EXE_COMMLINE_ToggleSwitch(
              Switch + 1, &BASE_OPTIONS.ExtractOptions.DoShowComments);

            break;
          }

          case APPS_UNACE_EXE_COMMLINE_SWITCH_F:
          {
            APPS_UNACE_EXE_COMMLINE_ToggleSwitch(Switch + 1,
              &BASE_PATHFUNC.DoWildCardCheckMatchingPath);

            break;
          }

          case APPS_UNACE_EXE_COMMLINE_SWITCH_O:
          {
            APPS_UNACE_EXE_COMMLINE_ToggleSwitch(
              Switch + 1, &BASE_FUNCS.DoOverwriteAll);

            break;
          }

          case APPS_UNACE_EXE_COMMLINE_SWITCH_P:
          {
            const size_t size = sizeof(BASE_OPTIONS.ExtractOptions.CryptionData.Password) - 1;
            strncpy(BASE_OPTIONS.ExtractOptions.CryptionData.Password,
                    Switch + 1, size);
            BASE_OPTIONS.ExtractOptions.CryptionData.Password[size] = 0;

            BASE_CRYPT.DoUseCurrentPassword = 1;

            break;
          }

          case APPS_UNACE_EXE_COMMLINE_SWITCH_X:
          {
            APPS_UNACE_EXE_COMMLINE_FileListAddFiles(
              Switch + 1, &BASE_FILELIST.SearchExcludeListEnd,
              BASE_FILELIST.SearchExcludeListMax);

            break;
          }

          case APPS_UNACE_EXE_COMMLINE_SWITCH_Y:
          {
            APPS_UNACE_EXE_COMMLINE_ToggleSwitch(Switch + 1,
              &BASE_FUNCS.DoOverwriteAll);

            BASE_CRYPT.DoUseCurrentPassword   =
              BASE_VOLUME.DoProcessAllVolumes =
              BASE_FUNCS.DoDeleteAll          =
              APPS_EXE_OUTPUT.DoNotStdWait    = BASE_FUNCS.DoOverwriteAll;

            break;
          }

          case APPS_UNACE_EXE_COMMLINE_SWITCH_UNKNOWN:
          {
            printf("\n%s: %s\n", STR.Unknown_switch, Switch - 1);

            APPS_EXE_COMMLINE.Error = 1;

            return APPS_EXE_COMMLINE.Error;
          }
        }

        break;
      }
    }

    APPS_EXE_COMMLINE.ArgumentCount++;
  }

  return APPS_EXE_COMMLINE.Error;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_GetArchiveName----------------*/

BOOL    APPS_UNACE_EXE_COMMLINE_GetArchiveName(void)
{
PCHAR     PointPos;

  if (APPS_UNACE_EXE_COMMLINE.IsSFX)
  {
    strcpy(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName,
           APPS_EXE_COMMLINE.Arguments[0]);
  }
  else
  {
    if (APPS_EXE_COMMLINE.ArgumentCount < APPS_EXE_COMMLINE.ArgumentsNumber)
    {
      const size_t size = sizeof(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName) - 1;
      strncpy(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName,
              APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount++], size);
      APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName[size] = 0;

      BASE_PATHFUNC_ToSystemPathSeparator(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName);

      BASE_PATHFUNC_CompletePath(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName);

      PointPos = strrchr(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName, '.');

      if (strrchr(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName, BASE_PATHFUNC_SEPARATOR)
            > PointPos
          || !PointPos
          || (!BASE_CONVERT_StrICmp(PointPos, ".")
              && !BASE_CONVERT_StrICmp(PointPos, ".ace")
              && !BASE_CONVERT_StrICmp(PointPos, ".exe")))
      {
        if (size - strlen(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName) >=
            strlen(BASE_ACESTRUC_EXTENSION))
        strcat(APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName,
               BASE_ACESTRUC_EXTENSION);
      }
    }
    else
    {
      APPS_EXE_COMMLINE.Error = 1;
      printf("\n%s\n", STR.Error__archive_not_specified);
    }
  }

  return APPS_EXE_COMMLINE.Error;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_PrepareCommandExecution-------*/

void    APPS_UNACE_EXE_COMMLINE_PrepareCommandExecution(void)
{
BOOL      DoExtractToCurrentDir;

  if (!APPS_EXE_COMMLINE.Error)
  {
    BASE_DCPR.Options    = BASE_OPTIONS.ExtractOptions;

    BASE_STATE_EXTERN_OutputProcess(STR.processing_archive,
                                    APPS_EXE_COMMLINE.ArchiveName, 1);

    BASE_ARCHIVES_TEST_ArchiveTest(APPS_EXE_COMMLINE.ArchiveName,
                                   BASE_ARCHIVES_TEST.MaxTestSectors, 1);

    BASE_DIRDATA_Dir2 = BASE_DIRDATA_Dir1;

    BASE_LFN_GetCurrentDir(BASE_DIRDATA_Dir1.Dir, BASE_LFN_MAXLEN);
    BASE_DIRDATA_Dir1.ArchiveName[0] = 0;

    BASE_LFN_GetCurrentDir(BASE_DIRDATA_Dir2.Dir, BASE_LFN_MAXLEN);
    BASE_DIRDATA_Dir2.ArchiveName[0] = 0;

    switch (APPS_EXE_COMMLINE.Command)
    {
      case APPS_UNACE_EXE_COMMLINE_COMMAND_E:
      {
        BASE_EXTRACT.DoRemovePaths = 1;
      }

      case APPS_UNACE_EXE_COMMLINE_COMMAND_X:
      {
        BASE_EXTRACT.DoProcessAllVolumes = 1;

        if (APPS_EXE_COMMLINE.TargetDir)
        {
          strcpy(BASE_DIRDATA_Dir2.Dir, APPS_EXE_COMMLINE.TargetDir);
          BASE_PATHFUNC_CompletePath(BASE_DIRDATA_Dir2.Dir);
/*
          snprintf (TargetFile, sizeof(TargetFile), "%st.t",
                    BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir2.Dir));

          BASE_FUNCS_CreatePathDirectories(TargetFile);*/
        }
        else
        {
          if (APPS_UNACE_EXE_COMMLINE.IsSFXNoCommand
              && !BASE_VOLUME.DoProcessAllVolumes)
          {
            DoExtractToCurrentDir =
              APPS_EXE_INPUT_EXTERN_WarningYANC(STR.Extract,
                   STR.Extract_archive_to_current_directory_,
                   APPS_EXE_COMMLINE.ArchiveName);

            switch (DoExtractToCurrentDir)
            {
              case 2:
              {
                APPS_EXE_INPUT_Input(BASE_DIRDATA_Dir2.Dir,
                  75, STR.Extract,
                  STR.Please_enter_new_destination_directory_, 0);

                if (APPS_EXE_INPUT.LastKey == 27)
                {
                  BASE_ERROR.ErrorCode = BASE_ERROR_USER;
                }

                break;
              }

              case 3:
              {
                BASE_ERROR.ErrorCode = BASE_ERROR_USER;

                break;
              }
            }
          }
        }
      }

      case APPS_UNACE_EXE_COMMLINE_COMMAND_L:
      case APPS_UNACE_EXE_COMMLINE_COMMAND_V:
      {
        BASE_FILELIST.DoRecurseSubDirectories = 1;
      }

      default:
      {
        BASE_PATHFUNC_SplitFileName(BASE_DIRDATA_Dir1.Dir,
                                    BASE_DIRDATA_Dir1.ArchiveName,
                                    APPS_EXE_COMMLINE.ArchiveName);
      }
    }
  }
}

/*-----------------APPS_UNACE_EXE_COMMLINE_InitArguments-----------------*/

void    APPS_UNACE_EXE_COMMLINE_InitArguments(INT ArgumentsNumber,
                                                PCHAR Arguments[])
{
PCHAR     SlashPtr;
INT       I,
          StrLen;

  APPS_EXE_COMMLINE.ArgumentsNumber = ArgumentsNumber;

  for (I = 0; I < APPS_EXE_COMMLINE.ArgumentsNumber; I++)
  {
    APPS_EXE_COMMLINE.Arguments[I] = Arguments[I];
    StrLen = strlen(APPS_EXE_COMMLINE.Arguments[I]) - 1;
    
    if (APPS_EXE_COMMLINE.Arguments[I][StrLen] == '"')
    {
      APPS_EXE_COMMLINE.Arguments[I][StrLen] = BASE_PATHFUNC_SEPARATOR;
    }

    if (StrLen > BASE_LFN_MAXLEN)    
    {
      APPS_EXE_COMMLINE.Arguments[I][BASE_LFN_MAXLEN-1] = 0;
    }
  }

  strcpy(APPS_EXE_COMMLINE.ProgramPath, APPS_EXE_COMMLINE.Arguments[0]);
  SlashPtr = (PCHAR) strrchr(APPS_EXE_COMMLINE.ProgramPath, BASE_PATHFUNC_SEPARATOR);

  if (!SlashPtr)
  {
    BASE_LFN_GetCurrentDir(APPS_EXE_COMMLINE.ProgramDir, BASE_LFN_MAXLEN);

    if (!APPS_EXE_COMMLINE.ProgramDir[3])
    {
      BASE_CONVERT_StrCatBefore("\\", APPS_EXE_COMMLINE.ProgramPath);
    }

    BASE_CONVERT_StrCatBefore(APPS_EXE_COMMLINE.ProgramDir,
                              APPS_EXE_COMMLINE.ProgramPath);
  }
  else
  {

    if (SlashPtr == APPS_EXE_COMMLINE.ProgramPath + 2)
    {
      SlashPtr++;
    }

    strcpy(APPS_EXE_COMMLINE.ProgramDir, APPS_EXE_COMMLINE.ProgramPath);

    *(SlashPtr - APPS_EXE_COMMLINE.ProgramPath +
      APPS_EXE_COMMLINE.ProgramDir)        = 0;
  }
}

/*-----------------APPS_UNACE_EXE_COMMLINE_AddEnvironmentSwitches--------*/

void    APPS_UNACE_EXE_COMMLINE_AddEnvironmentSwitches(void)
{
INT       InsertPos;
PCHAR     EnvironmentSwitchesPos;

  InsertPos = 0;
  EnvironmentSwitchesPos = APPS_EXE_COMMLINE.EnvironmentSwitches - 1;

  do
  {
    EnvironmentSwitchesPos++;

    if (*EnvironmentSwitchesPos && *EnvironmentSwitchesPos != ' ')
    {
      InsertPos++;

      memmove(&APPS_EXE_COMMLINE.Arguments[InsertPos + 1],
              &APPS_EXE_COMMLINE.Arguments[InsertPos],
              sizeof(PCHAR) * (APPS_EXE_COMMLINE.ArgumentsNumber + 1
                - InsertPos));

      APPS_EXE_COMMLINE.Arguments[InsertPos] = EnvironmentSwitchesPos;
      APPS_EXE_COMMLINE.ArgumentsNumber++;
    }

    EnvironmentSwitchesPos = strchr(EnvironmentSwitchesPos, ' ');

    if (EnvironmentSwitchesPos)
    {
      *EnvironmentSwitchesPos = 0;
    }
  }
  while (EnvironmentSwitchesPos);
}

/*-----------------APPS_UNACE_EXE_COMMLINE_DoShowHelp--------------------*/

BOOL    APPS_UNACE_EXE_COMMLINE_DoShowHelp(void)
{
  if (APPS_EXE_COMMLINE.ArgumentsNumber <= 1
      && !APPS_UNACE_EXE_COMMLINE.IsSFX)
  {
    return 1;
  }

  if (APPS_EXE_COMMLINE.ArgumentsNumber == 2)
  {
    if (!APPS_EXE_COMMLINE.Arguments[1][2]
        && (APPS_EXE_COMMLINE.Arguments[1][0] == '/'
            || APPS_EXE_COMMLINE.Arguments[1][0] == '-')
        && (BASE_CONVERT_UpCase(APPS_EXE_COMMLINE.Arguments[1][1]) == 'H'
            || APPS_EXE_COMMLINE.Arguments[1][1] == '?'))
    {
      return 1;
    }
  }

  APPS_EXE_COMMLINE.ArgumentCount = 1;

  return 0;
}

/*-----------------APPS_UNACE_EXE_COMMLINE_MainProc----------------------*/

void    APPS_UNACE_EXE_COMMLINE_MainProc(void)
{
tLFN      ShorterStr;
tBASE_LFN_FINDSTRUCT
          DirStruc;

  if (APPS_UNACE_EXE_COMMLINE_DoShowHelp())
  {
    APPS_UNACE_EXE_COMMLINE_HELP_PrintHelp(0);

    return;
  }

  BASE_LFN_GetCurrentDir(APPS_EXE_COMMLINE.StartDir, BASE_LFN_MAXLEN);

  APPS_UNACE_EXE_COMMLINE_AddEnvironmentSwitches();

  if (APPS_UNACE_EXE_COMMLINE_GetSwitches())
  {
    return;
  }

  if (APPS_UNACE_EXE_COMMLINE_GetCommand())
  {
    return;
  }

  if (APPS_UNACE_EXE_COMMLINE_GetSwitches())
  {
    return;
  }

  if (APPS_UNACE_EXE_COMMLINE_GetArchiveName())
  {
    return;
  }


  APPS_UNACE_EXE_COMMLINE_GetFileListInit();

  while (APPS_EXE_COMMLINE.ArgumentCount < APPS_EXE_COMMLINE.ArgumentsNumber)
  {
    if (APPS_UNACE_EXE_COMMLINE_GetSwitches())
    {
      return;
    }

    if (APPS_UNACE_EXE_COMMLINE_GetFileList())
    {
      return;
    }
  }

  APPS_UNACE_EXE_COMMLINE_GetFileListDone();

  APPS_UNACE_EXE_COMMLINE_ProcessingInit();

  if (APPS_EXE_COMMLINE.ArgumentCount < APPS_EXE_COMMLINE.ArgumentsNumber)
  {
    printf("\n%s: ", STR.Extra_characters_on_line);

    while (APPS_EXE_COMMLINE.ArgumentCount < APPS_EXE_COMMLINE.ArgumentsNumber)
    {
      printf("%s ",
             APPS_EXE_COMMLINE.Arguments[APPS_EXE_COMMLINE.ArgumentCount++]);
    }

    APPS_EXE_COMMLINE.Error = 1;

    return;
  }

  if (BASE_LFN_FindFirst(/*"//h/execs", */APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName,
                         BASE_LFN_GetFindAllFilesAttr(), &DirStruc))
  {
    APPS_EXE_OUTPTERR_OutputError(STR.No_such_archive_found_,
      APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName);

    BASE_ERROR.ErrorCode = BASE_ERROR_FOUND;

    return;
  }

  do
  {
    if (DirStruc.Name[0] == '.')
    {
      continue;
    }

    strcpy(APPS_EXE_COMMLINE.ArchiveName,
           APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName);

    *((PCHAR) strrchr(APPS_EXE_COMMLINE.ArchiveName, BASE_PATHFUNC_SEPARATOR) + 1) = 0;
    strcat(APPS_EXE_COMMLINE.ArchiveName, DirStruc.Name);

    if (!BASE_ARCHIVES_TEST_ArchiveTest(APPS_EXE_COMMLINE.ArchiveName,
                                        BASE_ARCHIVES_TEST.MaxTestSectors, 1)
        || BASE_DIRDATA_Dir1.ArchiveType != 0)
    {
      if (!BASE_CONVERT_StrICmp(APPS_EXE_COMMLINE.ArchiveName,
                   APPS_UNACE_EXE_COMMLINE.WildcardedArchiveName))
       {
        APPS_EXE_OUTPTERR_OutputError(STR.Is_no_ACE_archive_,
          APPS_EXE_CONVERT_MakeStrShorter(ShorterStr,
                                          APPS_EXE_COMMLINE.ArchiveName, 30));

        BASE_ERROR.ErrorCode = BASE_ERROR_OTHER;

        return;
      }
      else
      {
        continue;
      }
    }

    BASE_PATHFUNC_CompletePath(APPS_EXE_COMMLINE.ArchiveName);

    APPS_UNACE_EXE_COMMLINE_PrepareCommandExecution();

    if (BASE_ERROR.ErrorCode)
    {
      return;
    }

    BASE_DOSFUNCS_SetDir(BASE_DIRDATA_Dir1.Dir);

    switch (APPS_EXE_COMMLINE.Command)
    {
      case APPS_UNACE_EXE_COMMLINE_COMMAND_E:
      case APPS_UNACE_EXE_COMMLINE_COMMAND_X:
      {
        BASE_FUNCS_Copy(0);

        break;
      }

      case APPS_UNACE_EXE_COMMLINE_COMMAND_V:
      case APPS_UNACE_EXE_COMMLINE_COMMAND_L:
      {
        APPS_EXE_ACEFUNCS_List(APPS_EXE_COMMLINE.Command ==
                                 APPS_UNACE_EXE_COMMLINE_COMMAND_V);

        break;
      }

      case APPS_UNACE_EXE_COMMLINE_COMMAND_T:
      {
        BASE_EXTRACT_Test(APPS_EXE_COMMLINE.ArchiveName, 1);

        break;
      }
    }

    BASE_DOSFUNCS_SetDir(APPS_EXE_COMMLINE.StartDir);

    if (APPS_EXE_COMMLINE.Command == APPS_UNACE_EXE_COMMLINE_COMMAND_L
        || APPS_EXE_COMMLINE.Command == APPS_UNACE_EXE_COMMLINE_COMMAND_V)
    {
      APPS_EXE_OUTPUT_WriteWait("");
    }
    else
    {
      APPS_EXE_OUTPUT_Write("");
    }

    if (BASE_ERROR.ErrorCode == BASE_ERROR_FILES)
    {
      BASE_ERROR.ErrorCode = 0;
    }
  }
  while (!BASE_LFN_FindNext(&DirStruc)
         && !BASE_ERROR_EXTERN_HandleCancel(1));

  BASE_LFN_FindClose(&DirStruc);
}
