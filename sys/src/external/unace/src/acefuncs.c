#include <stdio.h>
#include <string.h>
#include <errno.h>

#define INCL_APPS_EXE_ACEFUNCS
#define INCL_APPS_EXE_OUTPTERR

#define INCL_BASE_ARCBLK
#define INCL_BASE_COMMENTS
#define INCL_BASE_CONVERT
#define INCL_BASE_DIRDATA
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_FILELIST
#define INCL_BASE_FUNCS
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#define INCL_BASE_VOLUME

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPTERR
#define INCL_APPS_EXE_OUTPUT

#include "unace_includes.h"


/*-----------------APPS_EXE_OUTPTERR_OutputError-------------------------*/
void    APPS_EXE_OUTPTERR_OutputError(PCHAR TextStr1, PCHAR TextStr2)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(
    STR.Error ? STR.Error : "Error", TextStr1, TextStr2);

  BASE_ERROR.HardwareError =
    errno             = 0;
}


/*-----------------APPS_EXE_ACEFUNCS_List--------------------------------*/
void    APPS_EXE_ACEFUNCS_List(BOOL Verbose)
{
CHAR      ShortStr[BASE_LFN_MAXLEN],
          SizeStr1[80],
          SizeStr2[80],
          OutputStr[160];
PCHAR     OutputFileName;
INT       I;
union {
tBASE_DOSFUNCS_FileTime Fields;
ULONG                   Raw;
} FileTime;

  BASE_FILELIST_Init();
  BASE_FILELIST_VolumeCreate();

  BASE_VOLUME.DoNotProcessNextVolume =
    BASE_ARCBLK.DoOpenForReadOnly    = 1;

  if (BASE_ARCBLK_OpenArchive(BASE_DIRDATA_Dir1.ArchiveName, 0, 1, 1, 1))
  {
    snprintf(OutputStr, sizeof(OutputStr),
            STR.Contents_of,
            BASE_DIRDATA_Dir1.IsLocked ? STR.__LOCKED_ : "",
            STR.archive,
            BASE_CONVERT_ToOEM(APPS_EXE_CONVERT_MakeStrShorter(ShortStr,
                                           BASE_DIRDATA_Dir1.ArchiveName, 35)));

    APPS_EXE_OUTPUT_WriteWait(OutputStr);
    APPS_EXE_OUTPUT_WriteWait("");

    APPS_EXE_OUTPUT_WriteWait(
      STR.Date_____Time__Packed______Size______Ratio_File);

    APPS_EXE_OUTPUT_WriteWait("");

    while (!BASE_ERROR_EXTERN_HandleCancel(1) && BASE_ARCBLK_LoadBlock())
    {
      if ((BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE)
          && !(BASE_ARCBLK.Header.File.ATTR & BASE_DOSFUNCS_SUBDIR)
          && BASE_FILELIST_Check(BASE_ARCBLK_GetFileName(ShortStr,
                                                      &BASE_ARCBLK.Header)))
      {
        OutputFileName = strrchr(ShortStr, '\\');

        if (Verbose || !OutputFileName)
        {
          OutputFileName = ShortStr;
        }
        else
        {
          OutputFileName++;
        }

        APPS_EXE_CONVERT_MakeStrShorter(ShortStr, OutputFileName, 35);

        FileTime.Raw = BASE_ARCBLK.Header.File.FTIME;

        BASE_STATE.SummaryUnComprBytes += BASE_ARCBLK.Header.File.SIZE;
        BASE_STATE.SummaryComprBytes   += BASE_ARCBLK.Header.File.PSIZE;
        BASE_STATE.SummaryFileCount++;

        snprintf(
          OutputStr, sizeof(OutputStr),
          "%2d.%2d.%2d_%2d:%2d %c%c%s %s %4d%% %c%s",
          FileTime.Fields.Day, FileTime.Fields.Month,
          (80 + FileTime.Fields.Year) % 100,
          FileTime.Fields.Hour, FileTime.Fields.Minute,
          BASE_ARCBLK.Header.File.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SPLITBEFORE ?
            '\x11' : ' ',
          BASE_ARCBLK.Header.File.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SPLITAFTER  ?
            '\x10' : ' ',
          APPS_EXE_CONVERT_FormatSize(SizeStr1, 0, BASE_ARCBLK.Header.File.PSIZE),
          APPS_EXE_CONVERT_FormatSize(SizeStr2, 0, BASE_ARCBLK.Header.File.SIZE),
          APPS_EXE_CONVERT_GetPercents((INT) BASE_ARCBLK.Header.File.PSIZE,
                                      (INT) BASE_ARCBLK.Header.File.SIZE) / 10,
          BASE_ARCBLK.Header.File.HEAD_FLAGS & BASE_ACESTRUC_FLAG_PASSWORD    ?
            '*' : ' ',
          BASE_CONVERT_ToOEM(ShortStr));

        for (I = 0; I < 14; I++)
        {
          switch (OutputStr[I])
          {
            case ' ': OutputStr[I] = '0';
 break;
            case '_': OutputStr[I] = ' ';
 break;
          }
        }

        APPS_EXE_OUTPUT_WriteWait(OutputStr);

        if (Verbose)
        {
          BASE_COMMENTS_EXTERN_Output();
        }
      }
    }

/*    if (!BASE_ERROR.ErrorCode)
    {
      APPS_EXE_OUTPUT_WriteWait("");

      sprintf(OutputStr, "                 %s³%s³%4d%%³ %d %s",
              APPS_EXE_CONVERT_FormatSize(SizeStr1, 0, PackedCount),
              APPS_EXE_CONVERT_FormatSize(SizeStr2, 0, SizeCount),
              APPS_EXE_CONVERT_GetPercents(PackedCount, SizeCount) / 10,
              FileCount, FileCount == 1 ? STR.file : STR.files);

      APPS_EXE_OUTPUT_WriteWait(OutputStr);
    }
*/
    BASE_ARCBLK_EXTERN_CloseArchive(0);
  }

  BASE_FILELIST_Done();

  BASE_ARCBLK.DoOpenForReadOnly = 0;
}

