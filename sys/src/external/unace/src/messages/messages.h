#ifndef _APPS_EXE_MESSAGES_H_INCLUDED
#define _APPS_EXE_MESSAGES_H_INCLUDED

/* #include "ace/exe/messages/messages.h" */
#define APPS_ACE_EXE_MESSAGES_ARCHIVEOPTIONWINLINES             16
#define APPS_ACE_EXE_MESSAGES_CREATIONARCHIVINGOPTIONSLINES     17
#define APPS_ACE_EXE_MESSAGES_MAXHELPLINES                      19
#define APPS_ACE_EXE_MESSAGES_SHELLHELPPAGES                    6
#define APPS_ACE_EXE_MESSAGES_VIEWERHELPPAGES                   1
#define APPS_ACE_EXE_MESSAGES_COMMLINEHELPLINES                 46
#define APPS_ACE_EXE_MESSAGES_SFXDESCRIPTIONLINES               17
#define APPS_ACE_EXE_MESSAGES_CHANGEOPTIONSLINES                6
#define APPS_ACE_EXE_MESSAGES_HOTKEYLINES                       9
typedef struct
{
        INT     LevelDisPos[6],
                ChangeArchiveOptionsPos[6],
                ChangeFileOptionsPos[2],
                ChangeOptionsPos[APPS_ACE_EXE_MESSAGES_CHANGEOPTIONSLINES],
                ExternalProgramsPos[2];
} tAPPS_ACE_EXE_MESSAGES;

extern tAPPS_ACE_EXE_MESSAGES APPS_ACE_EXE_MESSAGES;

BOOL    APPS_ACE_EXE_MESSAGES_GetMessageFileInfo(tLFN FileName, tLFN LongTitle);

// =============================================================================

#define APPS_EXE_MESSAGES_ENGLISH      "default"
#define APPS_EXE_MESSAGES_COMMLINEHELPLINES 16

typedef struct
{
        tLFN    FileName;
        INT     LanguageIndex;
        INT     Handle;
        PCHAR   ReadPos;
        INT     YANCPos[4];
        CHAR    YANC[5];
        CHAR    FirstCommandLineHelpLine[85];
        PCHAR   MessagesBuf;
} tAPPS_EXE_MESSAGES;

extern tAPPS_EXE_MESSAGES APPS_EXE_MESSAGES;

void    APPS_EXE_MESSAGES_Open(PCHAR FileName);
INT     APPS_EXE_MESSAGES_Read(void *Buf, INT Len);
void    APPS_EXE_MESSAGES_Skip(INT Len);
void    APPS_EXE_MESSAGES_Close(void);
BOOL    APPS_EXE_MESSAGES_GetMessageFile(tLFN FileName, PULONG Size);

void    APPS_EXE_MESSAGES_LoadMessagesPROC(PCHAR *EndMarkerPos,
                                                  PCHAR EndMarker);

INT     APPS_EXE_MESSAGES_GetHotKey(PCHAR Str);
void    APPS_EXE_MESSAGES_InitMessages(void);
void    APPS_EXE_MESSAGES_EXTERN_InitProgramSpecific(void);
void    APPS_EXE_MESSAGES_EXTERN_LoadMessages(void);

#include "messages/msgstruc.h"

#endif
