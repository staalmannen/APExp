#ifndef _APPS_EXE_OUTPUT_H_INCLUDED
#define _APPS_EXE_OUTPUT_H_INCLUDED

#include <stdio.h>

typedef struct
{
        BOOL    IsNotRedirected,
                DoNotStdLineFeed,
                DoStdDeleteRight,
                DoUseStdOutput,
                DoNotStdWait;
        INT     ScreenHeight,
                StdOutLineCount;
        FILE   *StdOut,
               *StdErr;
} tAPPS_EXE_OUTPUT;

extern tAPPS_EXE_OUTPUT APPS_EXE_OUTPUT;

void    APPS_EXE_OUTPUT_WriteRight(PCHAR Text);
void    APPS_EXE_OUTPUT_DeleteRight(void);
void    APPS_EXE_OUTPUT_Error(PCHAR Error);
void    APPS_EXE_OUTPUT_Write(PCHAR Text);
void    APPS_EXE_OUTPUT_WriteWait(PCHAR Text);
void    APPS_EXE_OUTPUT_KeyWait(void);
void    APPS_EXE_OUTPUT_FullScreenKeyWait(void);

void    APPS_EXE_OUTPUT_InfoOrWarningProc(
          PCHAR TopStr, PCHAR TextStr1, PCHAR TextStr2, BOOL IsWarning,
          PCHAR ShortStr1, PCHAR ShortStr2, PINT Width);

void    APPS_EXE_OUTPUT_MessageProc(PCHAR TopStr, PCHAR MessageText);
void    APPS_EXE_OUTPUT_EXTERN_Warning(PCHAR TopStr,
                                       PCHAR TextStr1, PCHAR TextStr2);

void    APPS_EXE_OUTPUT_EXTERN_Message(INT Width, PCHAR TopStr,
                                       PCHAR MessageText);
#endif
