#include <stdlib.h>

#if defined(W_MTRACE) && defined(__GLIBC__)
#include <mcheck.h>
#endif

#define INCL_APPS_UNACE_EXE

#define INCL_BASE_ARCHIVES_TEST
#define INCL_BASE_BITWIDTH
#define INCL_BASE_COMMENTS
#define INCL_BASE_CRC
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_MEMORY
#define INCL_BASE_OPTIONS
#define INCL_BASE_PATHFUNC

#define INCL_APPS_EXE_COMMLINE
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_OUTPUT

#define INCL_APPS_UNACE_EXE_COMMLINE
#define INCL_APPS_UNACE_EXE_OUTPUT

#include "unace_includes.h"

/*-----------------APPS_UNACE_EXE_ProgramInit----------------------------*/

void    APPS_UNACE_EXE_ProgramInit(INT ArgumentsNumber, PCHAR Arguments[])
{
//_________________handle memory
  BASE_MEMORY_InitMaxAllocate();
  BASE_LFN_CompleteArg0(&Arguments[0]);

//_________________handle arguments, paths

  APPS_UNACE_EXE_COMMLINE_InitArguments(ArgumentsNumber, Arguments);
  BASE_LFN_GetCurrentDir(APPS_EXE_COMMLINE.StartDir, BASE_LFN_MAXLEN - 1);

//_________________init output

  APPS_EXE_MESSAGES_InitMessages();
  APPS_EXE_OUTPUT.StdOut = fopen(BASE_DOSFUNCS_NULLDEVICE, "w");
  APPS_EXE_OUTPUT.StdErr = fopen(BASE_DOSFUNCS_NULLDEVICE, "w");

  BASE_CRC_MakeCRCTable();
  BASE_BITWIDTH_Init();

  ///APPS_UNACE_EXE_InitOSSpecific (&APPS_EXE_COMMLINE.Arguments[0]);
  APPS_EXE_OUTPUT.IsNotRedirected = isatty(fileno(stdout));  
  APPS_EXE_OUTPUT.DoNotStdWait    = !APPS_EXE_OUTPUT.IsNotRedirected;
  APPS_EXE_OUTPUT.ScreenHeight 	  = 80;
  APPS_EXE_INPUT_LINUX_SetRawMode();

//_________________get environment strings

  if (!(APPS_EXE_COMMLINE.EnvironmentSwitches = getenv("UNACE")))
  {
    APPS_EXE_COMMLINE.EnvironmentSwitches = "";
  }

//_________________care about setup

  BASE_ERROR.DoNotHandleCancel = 0;
  BASE_OPTIONS.ExtractOptions.DoShowComments = 1;

//_________________initialize different variables

  BASE_ARCHIVES_TEST.MaxTestSectors = 1024;
}


/*-----------------APPS_UNACE_EXE_ProgramDone----------------------------*/

void    APPS_UNACE_EXE_ProgramDone(void)
{
  BASE_DOSFUNCS_SetDir(APPS_EXE_COMMLINE.StartDir);
  ///APPS_UNACE_EXE_DoneOSSpecific();
  APPS_EXE_INPUT_LINUX_UnSetRawMode();
}


/*-----------------main--------------------------------------------------*/

INT main(INT ArgumentsNumber, PCHAR Arguments[])
{
#if defined(W_MTRACE) && defined(__GLIBC__)
  mtrace();
#endif

  APPS_UNACE_EXE_ProgramInit(ArgumentsNumber, Arguments);

  APPS_UNACE_EXE_COMMLINE_Init();
  APPS_UNACE_EXE_COMMLINE_MainProc();
  APPS_UNACE_EXE_COMMLINE_Done();

  APPS_UNACE_EXE_ProgramDone();

  if (BASE_ERROR.ErrorCode == BASE_ERROR_USER)
  {
    APPS_EXE_OUTPUT_Error(STR.User_break);
  }

  return BASE_ERROR.ErrorCode ?
           BASE_ERROR.ErrorCode : (APPS_EXE_COMMLINE.Error ?
                              BASE_ERROR_USER : BASE_ERROR.DidFailCRCCheck);
}
