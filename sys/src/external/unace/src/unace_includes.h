#ifndef _APPS_INCLUDES_H_INCLUDED
#define _APPS_INCLUDES_H_INCLUDED

#include "base/includes.h"

//////////////////////////////////////////////////////////////////////////////

#if defined(INCL_APPS_EXE)
#  define APPS_EXE_DELAYLENGTH 500
#endif

#if defined(INCL_APPS_EXE_COMMLINE)
 #include "commline.h"
#endif

#if defined(INCL_APPS_EXE_ACEFUNCS)
	void APPS_EXE_ACEFUNCS_List(BOOL Verbose);
#endif

#if defined(INCL_APPS_EXE_CONVERT) // convert.h
PCHAR APPS_EXE_CONVERT_ToByteUnitStr(PCHAR Str, ULONGLONG ByteSize);
PCHAR APPS_EXE_CONVERT_MakeStrShorter(PCHAR DestStr, PCHAR SourceStr, INT Width);
INT   APPS_EXE_CONVERT_GetPercents(ULONGLONG Value1, ULONGLONG Value2);
PCHAR APPS_EXE_CONVERT_ToPercentStr(ULONGLONG Value1, ULONGLONG Value2);
PCHAR APPS_EXE_CONVERT_FormatSize(PCHAR SizeStr, INT Attr, ULONGLONG Size);
#endif


#if defined(INCL_APPS_EXE_INPUT) // input.h
typedef struct {
    INT LastKey;
} tAPPS_EXE_INPUT;
extern tAPPS_EXE_INPUT APPS_EXE_INPUT;
void APPS_EXE_INPUT_Input(PCHAR StartStr, INT Width, PCHAR TopStr,
                          PCHAR Discription, BOOL IsPasswInput);
INT  APPS_EXE_INPUT_GetKey(void);
BOOL APPS_EXE_INPUT_KeyHit(void);
INT  APPS_EXE_INPUT_EXTERN_WarningYANC(PCHAR TopStr, PCHAR Description1,
                                       PCHAR Description2);
void APPS_EXE_INPUT_LINUX_SetRawMode(void);
void APPS_EXE_INPUT_LINUX_UnSetRawMode(void);
#endif


#if defined(INCL_APPS_EXE_MESSAGES)
   #include "messages/messages.h"
#endif

#if defined(INCL_APPS_EXE_OUTPTERR)
void APPS_EXE_OUTPTERR_OutputError(PCHAR TextStr1, PCHAR TextStr2);
#endif

#if defined(INCL_APPS_EXE_OUTPUT)
   #include "output.h"
#endif

#if defined(INCL_APPS_EXE_STATE) // state.h
void APPS_EXE_STATE_Delay(INT MilliSeconds);
void APPS_EXE_EXTERN_STATE_StdOutputProgressEnd(void);
void APPS_EXE_EXTERN_STATE_OutputCRCOkEnd(BOOL CRCIsOk);
void APPS_EXE_EXTERN_STATE_CRCError(BOOL CRCIsOk);
#endif

#if defined(INCL_APPS_UNACE_EXE_COMMLINE)
       #include "commline.h"
#endif

#if defined(INCL_APPS_UNACE_EXE) // main.h
INT  main(INT ArgumentsNumber, PCHAR Arguments[]);
void APPS_UNACE_EXE_ProgramInit(INT ArgumentsNumber, PCHAR Arguments[]);
void APPS_UNACE_EXE_ProgramDone(void);
#endif


#endif
