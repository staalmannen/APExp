#define INCL_APPS_EXE_STATE

#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <select.h>

#define INCL_BASE_CONVERT
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_FILELIST
#define INCL_BASE_STATE

#define INCL_APPS_EXE
#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT
#define INCL_APPS_EXE_STATE

#include "unace_includes.h"

static PCHAR ActionString;

/*-----------------APPS_EXE_STATE_Delay----------------------------------*/
void    APPS_EXE_STATE_Delay(INT MilliSeconds)
{
#ifdef _WIN32
  Sleep (MilliSeconds);
#else
  struct timeval tv;
  tv.tv_sec = MilliSeconds / 1000;
  tv.tv_usec = (MilliSeconds % 1000) * 100;
  select(0, NULL, NULL, NULL, &tv);
#endif
}


/*-----------------BASE_STATE_EXTERN_SetExtractString--------------------*/

void    BASE_STATE_EXTERN_SetExtractString(void)
{
  ActionString = STR.Extract;
}

/*-----------------BASE_STATE_EXTERN_SetTestString-----------------------*/

void    BASE_STATE_EXTERN_SetTestString(void)
{
  ActionString = STR.Test;
}

/*-----------------BASE_STATE_EXTERN_OutputProgressData------------------*/

void    BASE_STATE_EXTERN_OutputProgressData(PCHAR Buf, INT Bytes)
{
}

/*-----------------APPS_EXE_EXTERN_STATE_StdOutputProgressEnd------------*/

void   APPS_EXE_EXTERN_STATE_StdOutputProgressEnd(void)
{
CHAR      OutputStr1[80],
          OutputStr2[80];
BOOL      DoWriteCompressionPercents;

  if (APPS_EXE_OUTPUT.IsNotRedirected)
  {
    DoWriteCompressionPercents =
      BASE_STATE.FileUnComprBytes == BASE_STATE.FileSize;

    snprintf (OutputStr1, sizeof(OutputStr1), "(%s)",
              APPS_EXE_CONVERT_ToPercentStr(BASE_STATE.TotalUnComprBytes,
                                              BASE_FILELIST.SizeOfFiles));

    snprintf (OutputStr2, sizeof(OutputStr2), "%-8s", OutputStr1);

    snprintf (OutputStr1, sizeof(OutputStr1),
            DoWriteCompressionPercents ? "%6s         " : "%6s %s",
            DoWriteCompressionPercents ?
              APPS_EXE_CONVERT_ToPercentStr(BASE_STATE.FileComprBytes,
                                                BASE_STATE.FileSize) :
              APPS_EXE_CONVERT_ToPercentStr(BASE_STATE.FileUnComprBytes,
                                                BASE_STATE.FileSize),
            OutputStr2);

      APPS_EXE_OUTPUT_WriteRight(OutputStr1);
    }
}

/*-----------------APPS_EXE_EXTERN_STATE_OutputCRCOkEnd------------------*/

void    APPS_EXE_EXTERN_STATE_OutputCRCOkEnd(BOOL CRCIsOk)
{
  APPS_EXE_OUTPUT.DoStdDeleteRight = 1;

  if (CRCIsOk)
  {
    APPS_EXE_OUTPUT_WriteRight(STR.CRC_OK);
  }
  else
  {
    APPS_EXE_OUTPUT_DeleteRight();
  }

  APPS_EXE_OUTPUT.DoStdDeleteRight = 0;
}

/*-----------------APPS_EXE_EXTERN_STATE_CRCError------------------------*/

void    APPS_EXE_EXTERN_STATE_CRCError(BOOL CRCIsOk)
{
CHAR      OutputStr[80];

  if (!CRCIsOk)
  {
    BASE_STATE.SumErrors++;
    snprintf (OutputStr, sizeof(OutputStr), "%s %s", STR.CRC_check_error_on,
                       BASE_CONVERT_ToOEM(BASE_STATE.CurrentFileName));

    APPS_EXE_OUTPUT_Error(OutputStr);
    APPS_EXE_STATE_Delay(APPS_EXE_DELAYLENGTH);
  }
}
