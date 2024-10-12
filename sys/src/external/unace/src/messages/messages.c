#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define INCL_APPS_EXE_MESSAGES

#define INCL_BASE_COMMENTS
#define INCL_BASE_CONVERT
#define INCL_BASE_DCPR_COMMENTS
#define INCL_BASE_ERROROUT
#define INCL_BASE_MEMORY
#define INCL_BASE_PATHFUNC

#define INCL_APPS_EXE_COMMLINE

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPUT
#include "unace_includes.h"

#include "messages/messages_english.h"

tAPPS_ACE_EXE_MESSAGES APPS_ACE_EXE_MESSAGES;

tAPPS_EXE_MESSAGES APPS_EXE_MESSAGES;
tSTR STR; // msgstruc.h

/*-----------------APPS_EXE_MESSAGES_EXTERN_InitProgramSpecific----------*/
void    APPS_EXE_MESSAGES_EXTERN_InitProgramSpecific(void)
{
  snprintf (APPS_EXE_MESSAGES.FirstCommandLineHelpLine, sizeof(APPS_EXE_MESSAGES.FirstCommandLineHelpLine),
          "UNACE v" BASE_VERSION_VERSIONSTR "   %-44s"
          __DATE__ " " __TIME__
          , STR.Copyright_by_ACE_Compression_Software);  
  STR.CommlineHelp[0] = APPS_EXE_MESSAGES.FirstCommandLineHelpLine;
}

/*-----------------APPS_EXE_MESSAGES_EXTERN_LoadMessages-----------------*/
void    APPS_EXE_MESSAGES_EXTERN_LoadMessages(void)
{
  APPS_EXE_MESSAGES_LoadMessagesPROC(&STR.END_MARKER, "END OF UNACE PART");
}


/*-----------------APPS_EXE_MESSAGES_Open--------------------------------*/

void    APPS_EXE_MESSAGES_Open(PCHAR FileName)
{
  if (!BASE_CONVERT_StrICmp(FileName, APPS_EXE_MESSAGES_ENGLISH))
  {
    APPS_EXE_MESSAGES.ReadPos = (PCHAR) APPS_EXE_MESSAGES_EXTERN_ENGLISH;
    APPS_EXE_MESSAGES.Handle = -2;
  }
  else
  {
    APPS_EXE_MESSAGES.Handle = open(FileName, O_BINARY | O_RDONLY);
  }
}

/*-----------------APPS_EXE_MESSAGES_Read--------------------------------*/

INT     APPS_EXE_MESSAGES_Read(void *Buf, INT Len)
{
  if (APPS_EXE_MESSAGES.Handle == -2)
  {
    memcpy(Buf, APPS_EXE_MESSAGES.ReadPos, Len);
    APPS_EXE_MESSAGES.ReadPos += Len;

    return Len;
  }
  else
  {
    return read(APPS_EXE_MESSAGES.Handle, Buf, Len);
  }
}

/*-----------------APPS_EXE_MESSAGES_Skip--------------------------------*/

void    APPS_EXE_MESSAGES_Skip(INT Len)
{
  if (APPS_EXE_MESSAGES.Handle == -2)
  {
    APPS_EXE_MESSAGES.ReadPos += Len;
  }
  else
  {
    lseek(APPS_EXE_MESSAGES.Handle, Len, SEEK_CUR);
  }
}

/*-----------------APPS_EXE_MESSAGES_Close-------------------------------*/

void    APPS_EXE_MESSAGES_Close(void)
{
  if (APPS_EXE_MESSAGES.Handle != -2)
  {
    close(APPS_EXE_MESSAGES.Handle);
  }
}

/*-----------------APPS_EXE_MESSAGES_GetMessageFile----------------------*/

BOOL    APPS_EXE_MESSAGES_GetMessageFile(tLFN FileName, PULONG Size)
{
CHAR      Marker[4];
USHORT    Start;
ULONG     Bits;

  APPS_EXE_MESSAGES_Open(FileName);

  if (APPS_EXE_MESSAGES.Handle == -1)
  {
    goto RETURNERROR;
  }

  APPS_EXE_MESSAGES_Read(&Start, 2);
  ADJUST_ENDIANNESS16(&Start);
    
  APPS_EXE_MESSAGES_Read(&Marker, 4);

  if (memcmp(Marker, "MSGF", 4))
  {
    goto RETURNERROR;
  }

  APPS_EXE_MESSAGES_Read(&Bits, 4);
  ADJUST_ENDIANNESS32(&Bits);
  APPS_EXE_MESSAGES_Skip(2);
  APPS_EXE_MESSAGES_Read(&APPS_EXE_MESSAGES.LanguageIndex, 2);
  ADJUST_ENDIANNESS16(&APPS_EXE_MESSAGES.LanguageIndex);
  APPS_EXE_MESSAGES_Skip(4);
  APPS_EXE_MESSAGES_Read(Size, 4);
  ADJUST_ENDIANNESS32(Size);
    
  APPS_EXE_MESSAGES_Skip(Start - 22);

  BASE_MEMORY_FreeCheck(APPS_EXE_MESSAGES.MessagesBuf);

  if (!(APPS_EXE_MESSAGES.MessagesBuf =
        (PCHAR) BASE_MEMORY_GetMem(*Size + 1)))
  {
    goto RETURNERROR;
  }

  if (APPS_EXE_MESSAGES_Read(APPS_EXE_MESSAGES.MessagesBuf, *Size) < *Size)
  {
    goto RETURNERROR;
  }

  APPS_EXE_MESSAGES.MessagesBuf[*Size] = 0;

  close(APPS_EXE_MESSAGES.Handle);

  return 1;

RETURNERROR:

//  BASE_ERROROUT_EXTERN_ReadingMessagesFile(FileName);

  return 0;
}
/*-----------------APPS_EXE_MESSAGES_LoadMessagesPROC--------------------*/

void    APPS_EXE_MESSAGES_LoadMessagesPROC(PCHAR *EndMarkerPos,
                                             PCHAR EndMarker)
{
BOOL      UsingDefault;
ULONG     MessagesSize;
PCHAR    *STRPos;
PCHAR     MessagesBufEnd,
          EOLPos;

  snprintf (APPS_EXE_MESSAGES.FileName, sizeof(APPS_EXE_MESSAGES.FileName), "%sACE.MSG",
          BASE_PATHFUNC_AddSlashToEnd(APPS_EXE_COMMLINE.ProgramDir));

  for (UsingDefault = 0;; UsingDefault = 1)
  {
    if (APPS_EXE_MESSAGES_GetMessageFile(APPS_EXE_MESSAGES.FileName,
                                         &MessagesSize))
    {
      MessagesBufEnd =
        (EOLPos = APPS_EXE_MESSAGES.MessagesBuf) + MessagesSize;

      STRPos = &STR.BEGIN_MARKER + 1;
      *MessagesBufEnd = 10;

      while (EOLPos < MessagesBufEnd && STRPos <= EndMarkerPos)
      {
        *STRPos = EOLPos;
        STRPos++;

        EOLPos  = strchr(EOLPos, 10);
        *EOLPos = 0;
        EOLPos++;
      }

      if (*EndMarkerPos
          && !BASE_CONVERT_StrNICmp(*EndMarkerPos, EndMarker,
                                    strlen(EndMarker)))
      {
        return;
      }
    }

    strcpy(APPS_EXE_MESSAGES.FileName, APPS_EXE_MESSAGES_ENGLISH);

    if (UsingDefault)
    {
      break;
    }
  }
}

/*-----------------APPS_EXE_MESSAGES_GetHotKey---------------------------*/

INT     APPS_EXE_MESSAGES_GetHotKey(PCHAR Str)
{
PCHAR     AndPos;

  if ((AndPos = strchr(Str, '&')))
  {
    strcpy(AndPos, AndPos + 1);

    return AndPos - Str;
  }
  else
  {
    return 0;
  }
}

/*-----------------APPS_EXE_MESSAGES_InitMessages------------------------*/

void    APPS_EXE_MESSAGES_InitMessages(void)
{
  APPS_EXE_MESSAGES_EXTERN_LoadMessages();

  APPS_EXE_MESSAGES.YANC[0] =
    BASE_CONVERT_UpCase(STR.Yes[APPS_EXE_MESSAGES.YANCPos[0]    =
      APPS_EXE_MESSAGES_GetHotKey(STR.Yes)]);

  APPS_EXE_MESSAGES.YANC[1] =
    BASE_CONVERT_UpCase(STR.Always[APPS_EXE_MESSAGES.YANCPos[1] =
      APPS_EXE_MESSAGES_GetHotKey(STR.Always)]);

  APPS_EXE_MESSAGES.YANC[2] =
    BASE_CONVERT_UpCase(STR.No[APPS_EXE_MESSAGES.YANCPos[2]     =
      APPS_EXE_MESSAGES_GetHotKey(STR.No)]);

  APPS_EXE_MESSAGES.YANC[3] =
    BASE_CONVERT_UpCase(STR.Cancel[APPS_EXE_MESSAGES.YANCPos[3] =
      APPS_EXE_MESSAGES_GetHotKey(STR.Cancel)]);

  APPS_EXE_MESSAGES.YANC[4] = 0;

  APPS_EXE_MESSAGES_EXTERN_InitProgramSpecific();
}
