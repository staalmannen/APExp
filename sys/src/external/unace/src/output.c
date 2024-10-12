#include <string.h>
#include <time.h>

#define INCL_APPS_EXE_OUTPUT

#define INCL_BASE_ERROR

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_MESSAGES

#include "unace_includes.h"

tAPPS_EXE_OUTPUT APPS_EXE_OUTPUT;

/*-----------------APPS_EXE_OUTPUT_EXTERN_Warning------------------------*/
void    APPS_EXE_OUTPUT_EXTERN_Warning(PCHAR TopStr, PCHAR TextStr1,
					 PCHAR TextStr2)
{
CHAR      ShortStr1[80],
          ShortStr2[80];
INT       Width;

  APPS_EXE_OUTPUT_InfoOrWarningProc(TopStr, TextStr1, TextStr2, 1,
                                ShortStr1, ShortStr2, &Width);
}
/*-----------------APPS_EXE_OUTPUT_EXTERN_Message------------------------*/
void    APPS_EXE_OUTPUT_EXTERN_Message(INT Width, PCHAR TopStr,
                                         PCHAR MessageText)
{
  APPS_EXE_OUTPUT_MessageProc(TopStr, MessageText);
}


/*-----------------APPS_EXE_OUTPUT_WriteRight----------------------------*/

void    APPS_EXE_OUTPUT_WriteRight(PCHAR Text)
{
  if (APPS_EXE_OUTPUT.IsNotRedirected)
  {
    printf("\x8\x8\x8\x8\x8\x8\x8\x8\x8\x8\x8\x8\x8\x8\x8");
  }

  printf("%s", Text);

#ifndef __sun__
  fflush(stdout);
#endif
}

/*-----------------APPS_EXE_OUTPUT_DeleteRight---------------------------*/

void    APPS_EXE_OUTPUT_DeleteRight(void)
{
  if (APPS_EXE_OUTPUT.IsNotRedirected && APPS_EXE_OUTPUT.DoStdDeleteRight)
  {
    APPS_EXE_OUTPUT_WriteRight("               ");
  }
}

/*-----------------APPS_EXE_OUTPUT_Error---------------------------------*/

void    APPS_EXE_OUTPUT_Error(PCHAR Error)
{
  if (APPS_EXE_OUTPUT.DoUseStdOutput)
  {
    APPS_EXE_OUTPUT_DeleteRight();
    APPS_EXE_OUTPUT.DoStdDeleteRight = 0;

    fprintf(APPS_EXE_OUTPUT.StdErr, "\n%s", Error);
  }

  fprintf(APPS_EXE_OUTPUT.StdErr, "\n%s", Error);
  fprintf(APPS_EXE_OUTPUT.StdOut, "\n%s", Error);

#ifndef __sun__
  fflush(stderr);
#endif
  fflush(APPS_EXE_OUTPUT.StdErr);
  fflush(APPS_EXE_OUTPUT.StdOut);
}

/*-----------------APPS_EXE_OUTPUT_Write---------------------------------*/

void    APPS_EXE_OUTPUT_Write(PCHAR Text)
{
CHAR      OutputStr[200];
INT       LineLen;

  if ((LineLen = APPS_EXE_OUTPUT.IsNotRedirected ? 74 : 59) > strlen(Text))
  {
    memset(OutputStr, ' ', sizeof(OutputStr));
    OutputStr[LineLen] = 0;
    memcpy(OutputStr, Text, strlen(Text));
  }
  else
  {
    strcpy(OutputStr, Text);
  }

  fprintf(APPS_EXE_OUTPUT.StdOut, "\n%s", OutputStr);

  if (!APPS_EXE_OUTPUT.DoNotStdLineFeed)
  {
    printf("\n");
  }

  APPS_EXE_OUTPUT.DoNotStdLineFeed = 0;

  printf("%s", OutputStr);
  
  fflush(APPS_EXE_OUTPUT.StdOut);
#ifndef __sun__
  fflush(stdout);
#endif

  APPS_EXE_OUTPUT.StdOutLineCount++;
}

/*-----------------APPS_EXE_OUTPUT_WriteWait-----------------------------*/

void    APPS_EXE_OUTPUT_WriteWait(PCHAR Text)
{
  APPS_EXE_OUTPUT_Write(Text);
  APPS_EXE_OUTPUT_FullScreenKeyWait();
}

/*-----------------APPS_EXE_OUTPUT_KeyWait-------------------------------*/

void    APPS_EXE_OUTPUT_KeyWait(void)
{
CHAR      DeleteStr[223];

  if (!APPS_EXE_OUTPUT.DoNotStdWait)
  {
    APPS_EXE_OUTPUT_Write(STR.__Press_any_key_to_continue__);

    while (!APPS_EXE_INPUT_KeyHit() && !BASE_ERROR.ErrorCode)
    {
    }

    BASE_ERROR_EXTERN_HandleCancel(1);

    memset(DeleteStr, 8, 222);
    memset(&DeleteStr[74], ' ', 74);
    DeleteStr[222] = 0;

    printf("%s", DeleteStr);
#ifndef __sun__
    fflush(stdout);
#endif
    APPS_EXE_OUTPUT.DoNotStdLineFeed = 1;
  }
}

/*-----------------APPS_EXE_OUTPUT_FullScreenKeyWait---------------------*/

void    APPS_EXE_OUTPUT_FullScreenKeyWait(void)
{
  if (APPS_EXE_OUTPUT.StdOutLineCount >= APPS_EXE_OUTPUT.ScreenHeight - 1)
  {
    APPS_EXE_OUTPUT_KeyWait();
    APPS_EXE_OUTPUT.StdOutLineCount = 0;
  }
}

/*-----------------APPS_EXE_OUTPUT_InfoOrWarningProc---------------------*/

void    APPS_EXE_OUTPUT_InfoOrWarningProc(PCHAR TopStr,
                       PCHAR TextStr1, PCHAR TextStr2, BOOL IsWarning,
                       PCHAR ShortStr1, PCHAR ShortStr2, PINT Width)
{
CHAR      ErrorStr[160];
INT       TextLen1,
          TextLen2;

  TextLen1 = strlen(TextStr1);
  TextLen2 = strlen(TextStr2);
  *Width   = (TextLen1 > TextLen2 ? TextLen1 : TextLen2) + 14;

  if (*Width > 74)
  {
    *Width = 74;
  }

  APPS_EXE_CONVERT_MakeStrShorter(ShortStr2, TextStr2, *Width - 6);
  APPS_EXE_CONVERT_MakeStrShorter(ShortStr1, TextStr1, *Width - 6);

  if (IsWarning)
  {
    snprintf (ErrorStr, sizeof(ErrorStr), "%s: %s", TopStr, ShortStr1);
    APPS_EXE_OUTPUT_Error(ErrorStr);
    snprintf (ErrorStr, sizeof(ErrorStr), " %s", ShortStr2);
    APPS_EXE_OUTPUT_Error(ErrorStr);
  }
}

/*-----------------APPS_EXE_OUTPUT_MessageProc---------------------------*/

void    APPS_EXE_OUTPUT_MessageProc(PCHAR TopStr, PCHAR MessageText)
{
CHAR      WindowTopStr[80];

  APPS_EXE_OUTPUT_DeleteRight();
  snprintf (WindowTopStr, sizeof(WindowTopStr), "%s: %s", TopStr, MessageText);
  APPS_EXE_OUTPUT_Write(WindowTopStr);
}
