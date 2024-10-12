#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <select.h>

#include <sys/time.h>

#define INCL_APPS_EXE_INPUT

#define INCL_BASE_ERROR
#define INCL_BASE_CONVERT

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_COMMLINE
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT
#define INCL_APPS_EXE_STATE
#define INCL_APPS_EXE_COMMLINE

#include "unace_includes.h"

tAPPS_EXE_INPUT APPS_EXE_INPUT;

#ifndef _WIN32
#include <termios.h>
struct termios OldtiMode;
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

/*-----------------APPS_EXE_INPUT_Input------------------------------*/

void APPS_EXE_INPUT_Input (PCHAR StartStr, INT Width, PCHAR TopStr,
                           PCHAR Discription, BOOL IsPasswInput)
{
BOOL      IsFirstKeyPressed,
          IsTimeOut;
CHAR      InputStr[80],
          TempStr[80];
INT       TimeCount,
          InputLen;

  IsFirstKeyPressed = 1;

  IsTimeOut = 0;

  strcpy(InputStr, BASE_CONVERT_ToOEM(StartStr));
  InputLen = strlen(InputStr);

  APPS_EXE_OUTPUT_DeleteRight();

  snprintf (TempStr, sizeof(TempStr), "%s:", TopStr);
  APPS_EXE_OUTPUT_Write(TempStr);

  snprintf (TempStr, sizeof(TempStr), "  %s", Discription);
  APPS_EXE_OUTPUT_Write(TempStr);

  printf("\n  %s", InputStr);

#ifndef __sun__
  fflush(stdout);
#endif

  do
  {
    TimeCount = 0;

    while (!APPS_EXE_INPUT_KeyHit() && !BASE_ERROR.ErrorCode)
    {
      if (IsFirstKeyPressed)
      {
        if (APPS_EXE_COMMLINE.TimeOutLimit
            && TimeCount > APPS_EXE_COMMLINE.TimeOutLimit)
        {
          IsTimeOut = 1;

          break;
        }

        TimeCount++;
        APPS_EXE_STATE_Delay(100);
      }
    }

    if (IsTimeOut)
    {
      break;
    }

    BASE_ERROR_EXTERN_HandleCancel(0);

    if (APPS_EXE_INPUT.LastKey != 13 && APPS_EXE_INPUT.LastKey != 27)
    {
      if (APPS_EXE_INPUT.LastKey == 8)                 // Backspace
      {
        if (InputLen)
        {
          printf("\x8 \x8");
          InputLen--;
#ifndef __sun__
          fflush(stdout);
#endif
        }
      }
      else
      {
        if ((isprint(APPS_EXE_INPUT.LastKey))
            && InputLen < Width)
        {
            InputStr[InputLen++] = APPS_EXE_INPUT.LastKey;

            putchar(IsPasswInput ? '*' : APPS_EXE_INPUT.LastKey);
#ifndef __sun__
            fflush(stdout);
#endif
        }
      }
    }

    IsFirstKeyPressed = 0;
  }
  while (APPS_EXE_INPUT.LastKey != 13 && APPS_EXE_INPUT.LastKey != 27
         && !BASE_ERROR_EXTERN_HandleCancel(0));

  APPS_EXE_OUTPUT_Write("");

  if (IsTimeOut)
  {
    BASE_ERROR.ErrorCode = BASE_ERROR_OTHER;
    APPS_EXE_OUTPUT_Error(STR.Time_out_error_);
  }
  else
  {
    if (APPS_EXE_INPUT.LastKey != 13)
    {
      InputLen = 0;
    }

    InputStr[InputLen] = 0;

    if (APPS_EXE_INPUT.LastKey == 13)
    {
      strcpy(StartStr, BASE_CONVERT_ToANSI(InputStr));
    }
  }
}

/*-----------------APPS_EXE_INPUT_EXTERN_WarningYANC------------------------*/

INT APPS_EXE_INPUT_EXTERN_WarningYANC(PCHAR TopStr, PCHAR Description1, PCHAR Description2)
{
CHAR      ShortStr1[80],
          ShortStr2[80],
          TempStr[200];
INT       TimeCount;
UINT      ButtonNumber;
PCHAR     ButtonPtr;
PCHAR     Output = NULL;

  APPS_EXE_CONVERT_MakeStrShorter(ShortStr1, Description1, 79);
  APPS_EXE_CONVERT_MakeStrShorter(ShortStr2, Description2, 79);
  APPS_EXE_OUTPUT_DeleteRight();

  snprintf (TempStr, sizeof(TempStr),
           "%s:\n  %s\n  %s\n  (%s, %s, %s, %s)", TopStr,
           ShortStr1, ShortStr2, STR.Yes, STR.Always, STR.No, STR.Cancel);

  APPS_EXE_OUTPUT_Write(TempStr);

  do
  {
    TimeCount = 0;

    while (!APPS_EXE_INPUT_KeyHit() && !BASE_ERROR.ErrorCode)
    {
      if (APPS_EXE_COMMLINE.TimeOutLimit
          && TimeCount > APPS_EXE_COMMLINE.TimeOutLimit)
      {
        BASE_ERROR.ErrorCode = BASE_ERROR_OTHER;
        APPS_EXE_OUTPUT_Error(STR.Time_out_error_);

        return 3;
      }

      TimeCount++;
      APPS_EXE_STATE_Delay(100);
    }

    BASE_ERROR_EXTERN_HandleCancel(0);
    APPS_EXE_INPUT.LastKey = BASE_CONVERT_UpCase(APPS_EXE_INPUT.LastKey);

    if (APPS_EXE_INPUT.LastKey == 27)
    {
      APPS_EXE_INPUT.LastKey = APPS_EXE_MESSAGES.YANC[3];
    }
  }
  while (!(ButtonPtr =
             strchr(APPS_EXE_MESSAGES.YANC, APPS_EXE_INPUT.LastKey))
         && !BASE_ERROR_EXTERN_HandleCancel(0));

  ButtonNumber = ButtonPtr - APPS_EXE_MESSAGES.YANC;

  if (!BASE_ERROR.ErrorCode)
  {
    switch (ButtonNumber)
    {
      case 0: Output = STR.Yes;    break;
      case 1: Output = STR.Always; break;
      case 2: Output = STR.No;     break;
      case 3: Output = STR.Cancel; break;
    }
    APPS_EXE_OUTPUT_Write(Output);
  }

  return ButtonNumber;
}


// =================================================================
// lin.c

/*-----------------APPS_EXE_INPUT_GetKey---------------------------------*/
INT     APPS_EXE_INPUT_GetKey(void)
{
  CHAR      Ch;
  Ch = getchar();
  switch (Ch)
  {
    case 127:
      Ch = 8;
      break;
  }
  return Ch;
}

#if defined(_WIN32) || defined(MSDOS) // TODO
BOOL APPS_EXE_INPUT_KeyHit(void)
{
    // see BASE_ERROR_EXTERN_HandleCancel()
    // return FALSE otherwise it's an infinite loop
    return FALSE;
}
void APPS_EXE_INPUT_LINUX_SetRawMode(void) { }
void APPS_EXE_INPUT_LINUX_UnSetRawMode(void) { }

#else

BOOL    APPS_EXE_INPUT_KeyHit(void)
{
  fd_set fds;
  struct timeval tv;
  if (!isatty(0))
  {
    return 0;
  }
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  return select(1, &fds, NULL, NULL, &tv);
}

void    APPS_EXE_INPUT_LINUX_SetRawMode(void)
{
  struct termios ti;
  if (tcgetattr(STDIN_FILENO, &OldtiMode) < 0)
  {
    return;
  }

  ti = OldtiMode;

  ti.c_iflag &= ~ICRNL;
  ti.c_iflag |= IGNBRK | BRKINT;
  ti.c_lflag &= ~(ICANON | ECHO);
  ti.c_lflag |= ISIG;

  if (tcsetattr(STDIN_FILENO, TCSANOW, &ti) < 0)
  {
    return;
  }
  return;
}

void    APPS_EXE_INPUT_LINUX_UnSetRawMode(void)
{
  if (tcsetattr(STDIN_FILENO, TCSANOW, &OldtiMode) < 0)
  {
    return;
  }
  return;
}
#endif


