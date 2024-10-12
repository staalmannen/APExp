#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define INCL_BASE_ARCHIVES_ACE

#define INCL_BASE_ACESTRUC
#define INCL_BASE_ARCBLK
#define INCL_BASE_ARCHIVES_TEST
#define INCL_BASE_ARCHIVES_READ
#define INCL_BASE_CRC
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_DIRDATA
#define INCL_BASE_DOSFUNCS

#include "base/includes.h"

/*-----------------BASE_ARCHIVES_ACE_EXTERN_ArchiveTestAVCheck-----------*/
BOOL BASE_ARCHIVES_ACE_EXTERN_ArchiveTestAVCheck(BOOL IsUnRegistered)
{ /* arcace.c */
  if (!IsUnRegistered && BASE_DIRDATA_Dir1.HasAV
      && ((BASE_ARCBLK.Header.Main.RES2
            ^ (USHORT) (BASE_ARCBLK.Header.Main.TIME_CR >> 12))
          != BASE_ARCBLK.Header.Main.RES1))
  {
    BASE_ERROROUT_EXTERN_AVBroken();
  }

  return 1;
}



/*-----------------BASE_ARCHIVES_ACE_ArchiveTest-------------------------*/

INT     BASE_ARCHIVES_ACE_ArchiveTest(void)
{
BOOL      IsUnRegistered;
INT       I,
          Flags;
ULONGLONG FilePos,
          OldFilePos;

  OldFilePos = BASE_DOSFUNCS_Tell(BASE_ARCHIVES_TEST.ArchiveHandle);

  for (I = 0; I < 512; I++)
  {
    if (!memcmp(&BASE_ARCHIVES_TEST.TestBuffer[I], BASE_ACESTRUC_ACESIGN,
                BASE_ACESTRUC_ACESIGNLEN)
        && (FilePos = BASE_DIRDATA_Dir1.ArchiveBegin + I
                      - ((PCHAR) BASE_ARCBLK.Header.Main.ACESIGN
                       - (PCHAR) &BASE_ARCBLK.Header))
            >= 0)
    {
      Flags = ((PCHAR) BASE_ARCBLK.Header.Main.ACESIGN - (PCHAR) &BASE_ARCBLK.Header);
      Flags = ((PCHAR) &BASE_ARCBLK.Header.Main.ACESIGN - (PCHAR) &BASE_ARCBLK.Header);

      BASE_DOSFUNCS_LSeek(BASE_ARCHIVES_TEST.ArchiveHandle, FilePos, SEEK_SET);
      read(BASE_ARCHIVES_TEST.ArchiveHandle, (PCHAR) &BASE_ARCBLK.Header, 4);
      BASE_ARCBLK_AdjustEndiannessOfHeaderBase();  /* Adjusts .HEAD_CRC and .HEAD_SIZE */

      if (BASE_ARCBLK.Header.Basic.HEAD_SIZE <= sizeof(BASE_ARCBLK.Header) - 4)
      {
        read(BASE_ARCHIVES_TEST.ArchiveHandle, (PCHAR) &BASE_ARCBLK.Header.Basic.HEAD_TYPE,
                                       BASE_ARCBLK.Header.Basic.HEAD_SIZE);

        BASE_ARCBLK_ConvertHeader32ToHeader64();

        if (BASE_ARCBLK.Header.Basic.HEAD_CRC)
        {
          BASE_DIRDATA_Dir1.VersionToExtract = (BASE_ARCBLK.Header.Main.VER_EXTR % 10) |
                                       (BASE_ARCBLK.Header.Main.VER_EXTR / 10 << 8);

          BASE_DIRDATA_Dir1.VersionCreated   = (BASE_ARCBLK.Header.Main.VER_CR % 10) |
                                       (BASE_ARCBLK.Header.Main.VER_CR / 10 << 8);

          BASE_DIRDATA_Dir1.HostCreated      = BASE_ARCBLK.Header.Main.HOST_CR;

          BASE_DIRDATA_Dir1.ArchiveType    = 0;
          Flags                       = BASE_ARCBLK.Header.Main.HEAD_FLAGS;
          BASE_DIRDATA_Dir1.HasRecoveryRec = (Flags & BASE_ACESTRUC_FLAG_RECOVERYREC) > 0;
          BASE_DIRDATA_Dir1.IsSolid        = (Flags & BASE_ACESTRUC_FLAG_SOLID)       > 0;
          BASE_DIRDATA_Dir1.IsMultiVol     = (Flags & BASE_ACESTRUC_FLAG_MULTIVOLUME) > 0;
          BASE_DIRDATA_Dir1.VolumeNumber   = BASE_ARCBLK.Header.Main.VOL_NUM;
          BASE_DIRDATA_Dir1.HasAV          = (Flags & BASE_ACESTRUC_FLAG_AV)          > 0;
          BASE_DIRDATA_Dir1.HasMainCmt     = (Flags & BASE_ACESTRUC_FLAG_COMMENT)     > 0;
          BASE_DIRDATA_Dir1.IsLocked       = (Flags & BASE_ACESTRUC_FLAG_LOCK)        > 0;
          BASE_DIRDATA_Dir1.IsSFX         |= (Flags & BASE_ACESTRUC_FLAG_SFX)         > 0;
          BASE_DIRDATA_Dir1.ArchiveBegin   = FilePos;

          BASE_DIRDATA_Dir1.TimeCreated    =
           BASE_DOSFUNCS_CalcFileTime(BASE_ARCBLK.Header.Main.TIME_CR);

          IsUnRegistered                   =
            !memcmp(BASE_ARCBLK.Header.Main.AV, "*UNREGISTERED VERSION*", 22);

          BASE_DIRDATA_Dir1.IsAVOk         =
            BASE_ARCHIVES_ACE_EXTERN_ArchiveTestAVCheck(IsUnRegistered);

          BASE_DIRDATA_Dir1.IsNotCompatible  =
            BASE_ARCBLK.Header.Main.RES1  !=
              BASE_ARCHIVES_ACE_GETAVCHECKSUM(BASE_ARCBLK.Header.Main.AV,
                                              BASE_ARCBLK.Header.Main.AV_SIZE,
                                              BASE_ARCBLK.Header.Main.TIME_CR);

          if (IsUnRegistered)
          {
            BASE_DIRDATA_Dir1.HasAV = 0;
          }

          return 1;
        }
      }
  
      BASE_DOSFUNCS_LSeek(BASE_ARCHIVES_TEST.ArchiveHandle, OldFilePos, SEEK_SET);
    }
  }

  return 0;
}

/*-----------------BASE_ARCHIVES_ACE_ReadArchive-------------------------*/

void    BASE_ARCHIVES_ACE_ReadArchive(void)
{
INT       DicBits,
          Attributes,
          Read;
tLFN      ArchiveFileName;

  while (!BASE_ERROR.ErrorCode)
  {
    if (!(Read = read(BASE_ARCHIVES_TEST.ArchiveHandle,
                         (PCHAR) &BASE_ARCBLK.Header, 4)))
    {
      break;
    }

    BASE_ARCBLK_AdjustEndiannessOfHeaderBase();  /* Adjusts .HEAD_CRC and .HEAD_SIZE */
    
    if (Read < 4
        || BASE_ARCBLK.Header.Basic.HEAD_SIZE
             > sizeof(BASE_ARCBLK.Header.Basic) - 4
        || read(BASE_ARCHIVES_TEST.ArchiveHandle,
                (PCHAR) &BASE_ARCBLK.Header.Basic.HEAD_TYPE,
                BASE_ARCBLK.Header.Basic.HEAD_SIZE)
           < BASE_ARCBLK.Header.Basic.HEAD_SIZE)
    {
      BASE_DIRDATA_Dir1.IsBroken = 1;

      break;
    }

    BASE_ARCBLK_ConvertHeader32ToHeader64();

    if (!BASE_ARCBLK.Header.Basic.HEAD_CRC)
    {
      BASE_DIRDATA_Dir1.IsBroken = 1;
    }

    if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE)
    {
      BASE_ARCBLK_GetFileName(ArchiveFileName, &BASE_ARCBLK.Header);

      BASE_DIRDATA_Dir1.HasPassword  |=
        (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_PASSWORD) > 0;

      BASE_DIRDATA_Dir1.HasFileCmt   |=
        (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_COMMENT) > 0;

      BASE_DIRDATA_Dir1.UnPackedSize += BASE_ARCBLK.Header.File.SIZE;
      BASE_DIRDATA_Dir1.PackedSize   += BASE_ARCBLK.Header.File.PSIZE;

      Attributes = BASE_ARCBLK.Header.File.ATTR;

      if (!(Attributes & BASE_DOSFUNCS_SUBDIR))
      {
        BASE_DIRDATA_Dir1.FileNumber++;
      }

      if (BASE_ARCBLK.Header.File.TECH.TYPE == BASE_ACESTRUC_TECHNIQUE_LZ77_1
          || BASE_ARCBLK.Header.File.TECH.TYPE == BASE_ACESTRUC_TECHNIQUE_BLOCKED_1)
      {
        DicBits = BASE_ARCBLK.Header.File.TECH.PARM & 15;

        if (BASE_DIRDATA_Dir1.Dictionary < DicBits)
        {
          BASE_DIRDATA_Dir1.Dictionary = DicBits;
        }
      }

      if (BASE_ARCHIVES_READ.FileNumber == BASE_ARCHIVES_READ.MaxFileNumber)
      {
        BASE_ERROROUT_EXTERN_ManyFilesError();

        break;
      }

      BASE_ARCHIVES_READ.FileData[BASE_ARCHIVES_READ.FileNumber].Size        =
        BASE_ARCBLK.Header.File.SIZE;

      BASE_ARCHIVES_READ.FileData[BASE_ARCHIVES_READ.FileNumber].PackedSize  =
        BASE_ARCBLK.Header.File.PSIZE;

      BASE_ARCHIVES_READ.FileData[BASE_ARCHIVES_READ.FileNumber].Time.Fields =
        BASE_DOSFUNCS_CalcFileTime(BASE_ARCBLK.Header.File.FTIME);

      Attributes |=
        (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SPLITAFTER)  ?
          BASE_FILELIST_SPLITAFTER  : 0;

      Attributes |=
        (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SPLITBEFORE) ?
          BASE_FILELIST_SPLITBEFORE : 0;

      Attributes |=
        (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_PASSWORD)    ?
          BASE_FILELIST_ENCRYPTED   : 0;

      BASE_ARCHIVES_READ.FileData[BASE_ARCHIVES_READ.FileNumber].Attr = Attributes;

      BASE_ARCHIVES_READ.FileNumber++;

      strcpy(BASE_ARCHIVES_READ.FileNamesEnd, ArchiveFileName);
      BASE_ARCHIVES_READ.FileNamesEnd += strlen(ArchiveFileName) + 1;

    }

    if (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_ADDSIZE)
    {
      BASE_DOSFUNCS_LSeek(BASE_ARCHIVES_TEST.ArchiveHandle,
                     BASE_ARCBLK.Header.Basic.ADDSIZE, SEEK_CUR);
    }
  }

  BASE_DIRDATA_Dir1.Dictionary = BASE_DIRDATA_Dir1.Dictionary + 10;
}
