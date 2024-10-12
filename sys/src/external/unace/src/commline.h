#ifndef _APPS_UNACE_EXE_COMMLINE_H_INCLUDED
#define _APPS_UNACE_EXE_COMMLINE_H_INCLUDED

#include "base/lfn.h"

typedef struct
{
        BOOL    Error,
                IsHitCTRL;
        INT     ArgumentsNumber,
                ArgumentCount,
                TimeOutLimit;
        PCHAR   Arguments[64];
        tLFN    ErrorFile,
                OutFile;
        tLFN    ProgramPath,
                ProgramDir,
                StartDir;
        PCHAR   EnvironmentSwitches;
        INT     Command;
        tLFN    ArchiveName;
        PCHAR   TargetDir;
} tAPPS_EXE_COMMLINE;

extern tAPPS_EXE_COMMLINE APPS_EXE_COMMLINE;

// =====================================================================

#define APPS_UNACE_EXE_COMMLINE_HELP_COPYRIGHTLINES 2
void    APPS_UNACE_EXE_COMMLINE_HELP_PrintHelp(BOOL DoPrintCopyRight);
void    APPS_UNACE_EXE_COMMLINE_HELP_CreateFirstHelpLine(void);


#define APPS_UNACE_EXE_COMMLINE_COMMANDSNUMBER     5

#define APPS_UNACE_EXE_COMMLINE_COMMAND_E          0
#define APPS_UNACE_EXE_COMMLINE_COMMAND_L          1
#define APPS_UNACE_EXE_COMMLINE_COMMAND_T          2
#define APPS_UNACE_EXE_COMMLINE_COMMAND_V          3
#define APPS_UNACE_EXE_COMMLINE_COMMAND_X          4


#define APPS_UNACE_EXE_COMMLINE_SWITCHESNUMBER     9

#define APPS_UNACE_EXE_COMMLINE_SWITCH_C           0
#define APPS_UNACE_EXE_COMMLINE_SWITCH_ERR         1
#define APPS_UNACE_EXE_COMMLINE_SWITCH_F           2
#define APPS_UNACE_EXE_COMMLINE_SWITCH_O           3
#define APPS_UNACE_EXE_COMMLINE_SWITCH_OUT         4
#define APPS_UNACE_EXE_COMMLINE_SWITCH_P           5
#define APPS_UNACE_EXE_COMMLINE_SWITCH_X           6
#define APPS_UNACE_EXE_COMMLINE_SWITCH_Y           7
#define APPS_UNACE_EXE_COMMLINE_SWITCH_UNKNOWN     8

typedef struct
{
  tLFN    WildcardedArchiveName;
  BOOL    IsSFX,
          IsSFXNoCommand;
} tAPPS_UNACE_EXE_COMMLINE;


extern PCHAR const APPS_UNACE_EXE_COMMLINE_EXTRACTCOMMANDS ;
extern PCHAR const APPS_UNACE_EXE_COMMLINE_COMMANDSTRINGS
          [APPS_UNACE_EXE_COMMLINE_COMMANDSNUMBER + 1];
extern PCHAR const APPS_UNACE_EXE_COMMLINE_SWITCHESSTRINGS
          [APPS_UNACE_EXE_COMMLINE_SWITCHESNUMBER + 1];
extern tAPPS_UNACE_EXE_COMMLINE APPS_UNACE_EXE_COMMLINE;

void    APPS_UNACE_EXE_COMMLINE_Init(void);
void    APPS_UNACE_EXE_COMMLINE_Done(void);

void    APPS_UNACE_EXE_COMMLINE_SignalHandler(INT SignalNumber);
void    APPS_UNACE_EXE_COMMLINE_ProcessingInit(void);

INT     APPS_UNACE_EXE_COMMLINE_FileListAddFileName(PCHAR FileName,
          PCHAR *ListEnd, PCHAR ListMax);

void    APPS_UNACE_EXE_COMMLINE_FileListAddFiles(PCHAR Files, PCHAR *ListEnd,
                                                 PCHAR ListMax);

void    APPS_UNACE_EXE_COMMLINE_GetFileListInit(void);
void    APPS_UNACE_EXE_COMMLINE_GetFileListDone(void);
BOOL    APPS_UNACE_EXE_COMMLINE_GetFileList(void);
BOOL    APPS_UNACE_EXE_COMMLINE_GetCommand(void);
void    APPS_UNACE_EXE_COMMLINE_ToggleSwitch(PCHAR SwitchChar, PINT Variable);
BOOL    APPS_UNACE_EXE_COMMLINE_GetSwitches(void);
BOOL    APPS_UNACE_EXE_COMMLINE_GetArchiveName(void);
void    APPS_UNACE_EXE_COMMLINE_PrepareCommandExecution(void);

void    APPS_UNACE_EXE_COMMLINE_InitArguments(
          INT ArgumentsNumber, PCHAR Arguments[]);

void    APPS_UNACE_EXE_COMMLINE_AddEnvironmentSwitches(void);
BOOL    APPS_UNACE_EXE_COMMLINE_DoShowHelp(void);
void    APPS_UNACE_EXE_COMMLINE_MainProc(void);

#endif
