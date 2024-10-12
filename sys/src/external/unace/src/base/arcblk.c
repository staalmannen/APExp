#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define INCL_BASE_ARCBLK

#define INCL_BASE_ARCHIVES_TEST
#define INCL_BASE_BUFREAD
#define INCL_BASE_COMMENTS
#define INCL_BASE_CONVERT
#define INCL_BASE_CRC
#define INCL_BASE_CRYPT
#define INCL_BASE_DCPR
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_EXTRACT
#define INCL_BASE_MEMORY
#define INCL_BASE_MSGOUT
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#define INCL_BASE_UNINORM
#define INCL_BASE_VOLUME
#include "base/includes.h"

#define INCL_APPS_EXE
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_STATE
#include "unace_includes.h"

tBASE_ARCBLK BASE_ARCBLK; // arcblk.h

// =============================================================================

/*-----------------BASE_ARCBLK_EXTERN_CloseArchive-----------------------*/
void    BASE_ARCBLK_EXTERN_CloseArchive(INT AddRecovery)
{
  BASE_BUFREAD_Close();
}

/*-----------------BASE_ARCBLK_EXTERN_CurrentArchiveName-----------------*/
PCHAR   BASE_ARCBLK_EXTERN_CurrentArchiveName(void)
{
  return BASE_ARCBLK.ArchiveFile;
}

/*-----------------BASE_ARCBLK_EXTERN_OpenArchivesSetVariables-----------*/
void    BASE_ARCBLK_EXTERN_OpenArchivesSetVariables(INT Access, BOOL DoResetCrypt)
{
  BASE_ARCBLK_EXTERN_OutputArchiveInfo(Access, DoResetCrypt);

  BASE_ARCBLK.Options.HasRecoveryRecord =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_RECOVERYREC;

  BASE_ARCBLK.Options.IsVolume          =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_MULTIVOLUME;

  BASE_ARCBLK.Options.IsSolid           =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SOLID;

  BASE_ARCBLK.Options.HasAuthenticityVerification =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_AV;

  BASE_ARCBLK.Options.IsLocked       =
    BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_LOCK;

  BASE_ARCBLK.ArchiveFilePos         = BASE_DIRDATA_Dir1.ArchiveBegin;
}

// =============================================================================


/*-----------------APPS_EXE_EXTERN_ARCBLK_OutputArchiveInfo--------------*/
static void APPS_EXE_EXTERN_ARCBLK_OutputArchiveInfo(BOOL DoOutputAV)
{
CHAR      OutputStr[80];

  if (BASE_ARCBLK.DoOutputComments)
  {
    BASE_COMMENTS_EXTERN_Output();
  }

  if (DoOutputAV
      && BASE_ARCBLK.Header.Main.HEAD_FLAGS & BASE_ACESTRUC_FLAG_AV)
  {
    snprintf (OutputStr, sizeof(OutputStr), "%s %d.%d.%d %s %d.%d %s", STR.created_on,
            BASE_DIRDATA_Dir1.TimeCreated.Day,
            BASE_DIRDATA_Dir1.TimeCreated.Month,
            1980 + BASE_DIRDATA_Dir1.TimeCreated.Year,
            STR.with_ver,
            BASE_DIRDATA_Dir1.VersionCreated >> 8,
            BASE_DIRDATA_Dir1.VersionCreated & 0xff,
            STR.by);

    BASE_STATE_EXTERN_OutputProcess(OutputStr, "", 1);

    strncpy(OutputStr, BASE_ARCBLK.Header.Main.AV,
            BASE_ARCBLK.Header.Main.AV_SIZE);

    OutputStr[BASE_ARCBLK.Header.Main.AV_SIZE] = 0;
    OutputStr[50] = 0;
    BASE_STATE_EXTERN_OutputProcess(OutputStr, "", 1);
    APPS_EXE_STATE_Delay(APPS_EXE_DELAYLENGTH);
  }
}

/*-----------------BASE_ARCBLK_EXTERN_OutputArchiveInfo------------------*/
void    BASE_ARCBLK_EXTERN_OutputArchiveInfo(INT AccesFlags,
                                             BOOL DoResetCrypt)
{
  APPS_EXE_EXTERN_ARCBLK_OutputArchiveInfo(1);
}

// =============================================================================

/*-----------------BASE_ARCBLK_MainHeaderCommentSizePos------------------*/

PUSHORT BASE_ARCBLK_MainHeaderCommentSizePos(pBASE_ACESTRUC_HEADER Header)
{
  return (PUSHORT) (Header->Main.AV + Header->Main.AV_SIZE);
}

/*-----------------BASE_ARCBLK_MainHeaderCommentSize---------------------*/

UINT    BASE_ARCBLK_MainHeaderCommentSize(pBASE_ACESTRUC_HEADER Header)
{
  return *BASE_ARCBLK_MainHeaderCommentSizePos(Header);
}

/*-----------------BASE_ARCBLK_MainHeaderComment-------------------------*/

PCHAR   BASE_ARCBLK_MainHeaderComment(pBASE_ACESTRUC_HEADER Header)
{
  return (PCHAR)BASE_ARCBLK_MainHeaderCommentSizePos(Header)
                           + sizeof(Header->Main.COMM_SIZE);
}

/*-----------------BASE_ARCBLK_MainHeaderStuff---------------------------*/

PCHAR   BASE_ARCBLK_MainHeaderStuff(pBASE_ACESTRUC_HEADER Header)
{
  return BASE_ARCBLK_MainHeaderComment(Header)
         + BASE_ARCBLK_MainHeaderCommentSize(Header);
}

/*-----------------BASE_ARCBLK_FileHeaderCommentSizePos------------------*/

PUSHORT BASE_ARCBLK_FileHeaderCommentSizePos(pBASE_ACESTRUC_HEADER Header)
{
  return (PUSHORT) (Header->File.FNAME + Header->File.FNAME_SIZE);
}

/*-----------------BASE_ARCBLK_FileHeaderCommentSize---------------------*/

UINT    BASE_ARCBLK_FileHeaderCommentSize(pBASE_ACESTRUC_HEADER Header)
{
  return *BASE_ARCBLK_FileHeaderCommentSizePos(Header);
}

/*-----------------BASE_ARCBLK_FileHeaderComment-------------------------*/

PCHAR   BASE_ARCBLK_FileHeaderComment(pBASE_ACESTRUC_HEADER Header)
{
  return (PCHAR)BASE_ARCBLK_FileHeaderCommentSizePos(Header)
                           + sizeof(Header->File.COMM_SIZE);
}

/*-----------------BASE_ARCBLK_FileHeaderSecuritySizePos-----------------*/

PUSHORT BASE_ARCBLK_FileHeaderSecuritySizePos(pBASE_ACESTRUC_HEADER Header)
{
  if (Header->File.HEAD_FLAGS & BASE_ACESTRUC_FLAG_COMMENT)
  {
    return (PUSHORT)(
      BASE_ARCBLK_FileHeaderComment(Header)
      + BASE_ARCBLK_FileHeaderCommentSize(Header));
  }
  else
  {
    return BASE_ARCBLK_FileHeaderCommentSizePos(Header);
  }
}

/*-----------------BASE_ARCBLK_FileHeaderSecuritySize--------------------*/

UINT    BASE_ARCBLK_FileHeaderSecuritySize(pBASE_ACESTRUC_HEADER Header)
{
  return *BASE_ARCBLK_FileHeaderSecuritySizePos(Header);
}

/*-----------------BASE_ARCBLK_FileHeaderSecurity------------------------*/

PCHAR   BASE_ARCBLK_FileHeaderSecurity(pBASE_ACESTRUC_HEADER Header)
{
  return (PCHAR)BASE_ARCBLK_FileHeaderSecuritySizePos(Header)
                           + sizeof(Header->File.SECURITY_SIZE);
}


/*-----------------BASE_ARCBLK_FileHeaderSecurityRead--------------------*/

void    BASE_ARCBLK_FileHeaderSecurityRead(pBASE_ACESTRUC_HEADER Header, PCHAR *Security, PUINT Size)
{
  *Size = 0;
  *Security = NULL;

  if ((Header->File.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SECURITY)
      && (*Size = BASE_ARCBLK_FileHeaderSecuritySize(Header)))
  {
    if ((*Security = BASE_MEMORY_GetMem(*Size)))
    {
      memcpy(*Security, BASE_ARCBLK_FileHeaderSecurity(Header), *Size);
    }
  }
}

/*-----------------BASE_ARCBLK_FileHeaderSecurityWrite-------------------*/

void    BASE_ARCBLK_FileHeaderSecurityWrite(pBASE_ACESTRUC_HEADER Header, PCHAR Security, UINT Size)
{
  if (Size && Security)
  {
    Header->File.HEAD_FLAGS |= BASE_ACESTRUC_FLAG_SECURITY;
    *BASE_ARCBLK_FileHeaderSecuritySizePos(Header) = Size;
    memcpy(BASE_ARCBLK_FileHeaderSecurity(Header), Security, Size);
  }
}

/*-----------------BASE_ARCBLK_CalculateHeaderCRC------------------------*/

UINT    BASE_ARCBLK_CalculateHeaderCRC(pBASE_ACESTRUC_HEADER Header)
{
  return BASE_CRC_GetCRC16(BASE_CRC_MASK, (PCHAR) &Header->Basic.HEAD_TYPE,
                           Header->Basic.HEAD_SIZE);
}

/*-----------------BASE_ARCBLK_GetAddSize--------------------------------*/
ULONGLONG BASE_ARCBLK_GetAddSize(pBASE_ACESTRUC_HEADER Header)
{
  return (Header->Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_ADDSIZE) ?
            Header->Basic.ADDSIZE : 0;
}

/*-----------------BASE_ARCBLK_GetFileName-------------------------------*/

PCHAR   BASE_ARCBLK_GetFileName(PCHAR FileName, pBASE_ACESTRUC_HEADER Header)
{
INT       I;

  I = Header->File.FNAME_SIZE;

  if (I >= BASE_LFN_MAXLEN)
  {
    I = BASE_LFN_MAXLEN - 1;
  }

  strncpy(FileName, Header->File.FNAME, I);
  FileName[I] = 0;
  strcpy(FileName, BASE_CONVERT_ToANSI(FileName));

  return FileName;
}

/*-----------------BASE_ARCBLK_SkipFileBlock-----------------------------*/

void    BASE_ARCBLK_SkipFileBlock(void)
{
tLFN      FileName;

  if (BASE_DCPR.IsInitialized && BASE_ARCBLK.SkipSize
      && BASE_ARCBLK.Options.IsSolid
      && BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE)
  {
    BASE_ARCBLK_GetFileName(FileName, &BASE_ARCBLK.Header);
    strcpy(BASE_STATE.CurrentFileName, FileName);

    BASE_MSGOUT_EXTERN_Analyzing(FileName);

    if (!BASE_ERROR.ErrorCode)
    {
      BASE_EXTRACT_DecompressFile(0, 0);
    }
  }
}


/*-----------------BASE_ARCBLK_ConvertHeader32ToHeader64-----------------*/

void    BASE_ARCBLK_ConvertHeader32ToHeader64(void)
{
  BASE_ARCBLK.Header.Basic.HEAD_CRC =
    BASE_ARCBLK.Header.Basic.HEAD_CRC
        == BASE_ARCBLK_CalculateHeaderCRC(&BASE_ARCBLK.Header);

  BASE_ARCBLK_AdjustEndiannessOfHeaderRest();

  if (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_ADDSIZE)
  {
      switch (BASE_ARCBLK.Header.Basic.HEAD_TYPE)
      {
        case BASE_ACESTRUC_BLOCK_FILE32:
        {
          ULONG PSIZE = BASE_ARCBLK.Header.File32.PSIZE;
          ULONG SIZE = BASE_ARCBLK.Header.File32.SIZE;

          memmove(&BASE_ARCBLK.Header.File.FTIME,
                  &BASE_ARCBLK.Header.File32.FTIME,
                  sizeof(BASE_ARCBLK.Header)
                  - ((PCHAR)&BASE_ARCBLK.Header.File.FTIME
                     - (PCHAR)&BASE_ARCBLK.Header));

          BASE_ARCBLK.Header.File.PSIZE = PSIZE;
          BASE_ARCBLK.Header.File.SIZE = SIZE;

          BASE_ARCBLK.Header.Basic.HEAD_TYPE = BASE_ACESTRUC_BLOCK_FILE;
          BASE_ARCBLK.Header.Basic.HEAD_SIZE += 8;
          BASE_ARCBLK.Header.Basic.HEAD_FLAGS |= BASE_ACESTRUC_FLAG_64BIT;

          break;
        }

        case BASE_ACESTRUC_BLOCK_RECOVERY32:
        {
          ULONG REC_BLK_SIZE = BASE_ARCBLK.Header.Recovery32.REC_BLK_SIZE;
          ULONG REL_STRT = BASE_ARCBLK.Header.Recovery32.REL_STRT;

          memmove(&BASE_ARCBLK.Header.Recovery.CLUSTER,
                  &BASE_ARCBLK.Header.Recovery32.CLUSTER,
                  sizeof(BASE_ARCBLK.Header)
                  - ((PCHAR)&BASE_ARCBLK.Header.Recovery.CLUSTER
                     - (PCHAR)&BASE_ARCBLK.Header));

          BASE_ARCBLK.Header.Recovery.REC_BLK_SIZE = REC_BLK_SIZE;
          BASE_ARCBLK.Header.Recovery.REL_STRT = REL_STRT;

          BASE_ARCBLK.Header.Basic.HEAD_TYPE = BASE_ACESTRUC_BLOCK_RECOVERY;
          BASE_ARCBLK.Header.Basic.HEAD_SIZE += 8;
          BASE_ARCBLK.Header.Basic.HEAD_FLAGS |= BASE_ACESTRUC_FLAG_64BIT;

          break;
        }
        default:
        {
          if (!(BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_64BIT))
          {
            ULONG ADDSIZE = BASE_ARCBLK.Header.Basic32.ADDSIZE;
              memmove(&BASE_ARCBLK.Header.Basic.other,
                &BASE_ARCBLK.Header.Basic32.other,
                sizeof(BASE_ARCBLK.Header)
                  - ((PCHAR)&BASE_ARCBLK.Header.Basic.other
                  - (PCHAR)&BASE_ARCBLK.Header));

            BASE_ARCBLK.Header.Basic.ADDSIZE = ADDSIZE; 

            BASE_ARCBLK.Header.Basic.HEAD_SIZE += 4;
            BASE_ARCBLK.Header.Basic.HEAD_FLAGS |= BASE_ACESTRUC_FLAG_64BIT;
          }
          
          break;
      }
    
    }
  }

  if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE)
  {
    BASE_PATHFUNC_ToSystemPathSeparatorN(
      BASE_ARCBLK.Header.File.FNAME, BASE_ARCBLK.Header.File.FNAME_SIZE);

#if !defined(_WIN32)
# if defined(__MACOSX__)
    BASE_ARCBLK.Header.File.FNAME_SIZE = BASE_UNINORM_CP850ToUTF8NFD(
      BASE_ARCBLK.Header.File.FNAME, BASE_ARCBLK.Header.File.FNAME_SIZE);
# else /* for unix, assume UTF-8 NFC normalization */
    BASE_ARCBLK.Header.File.FNAME_SIZE = BASE_UNINORM_CP850ToUTF8NFC( (unsigned char *)
      BASE_ARCBLK.Header.File.FNAME, BASE_ARCBLK.Header.File.FNAME_SIZE);
# endif
#endif
  }
}

/*-----------------BASE_ARCBLK_AdjustEndiannessOfHeaderBase--------------*/

void BASE_ARCBLK_AdjustEndiannessOfHeaderBase(void)
{
    ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Basic.HEAD_CRC);
    ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Basic.HEAD_SIZE);
}

/*-----------------BASE_ARCBLK_AdjustEndiannessOfHeaderRest--------------*/

void BASE_ARCBLK_AdjustEndiannessOfHeaderRest(void)
{
    ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Basic.HEAD_TYPE);
    ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Basic.HEAD_FLAGS);
      
    switch (BASE_ARCBLK.Header.Basic.HEAD_TYPE)
      {
        case BASE_ACESTRUC_BLOCK_MAIN:
        {
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Main.TIME_CR);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Main.RES1);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Main.RES2);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Main.RES);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Main.COMM_SIZE);
          break;
        }
                
        case BASE_ACESTRUC_BLOCK_FILE32:
        {
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File32.PSIZE);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File32.SIZE);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File32.FTIME);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File32.ATTR);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File32.CRC32);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File32.TECH.PARM);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File32.RESERVED);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File32.FNAME_SIZE);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File32.COMM_SIZE);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File32.SECURITY_SIZE);
          break;
        }
      
        case BASE_ACESTRUC_BLOCK_FILE:
        {
          ADJUST_ENDIANNESS64(&BASE_ARCBLK.Header.File.PSIZE);
          ADJUST_ENDIANNESS64(&BASE_ARCBLK.Header.File.SIZE);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File.FTIME);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File.ATTR);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.File.CRC32);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File.TECH.PARM);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File.RESERVED);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File.FNAME_SIZE);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File.COMM_SIZE);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.File.SECURITY_SIZE);
          break;
        }
        
        case BASE_ACESTRUC_BLOCK_RECOVERY32:
        {
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Recovery32.REC_BLK_SIZE);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Recovery32.REL_STRT);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Recovery32.CLUSTER);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Recovery32.CL_SIZE);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Recovery32.REC_CRC);
          break;
        }
        
        case BASE_ACESTRUC_BLOCK_RECOVERY:
        {
          ADJUST_ENDIANNESS64(&BASE_ARCBLK.Header.Recovery.REC_BLK_SIZE);
          ADJUST_ENDIANNESS64(&BASE_ARCBLK.Header.Recovery.REL_STRT);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Recovery.CLUSTER);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Recovery.CL_SIZE);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Recovery.REC_CRC);
          break;
        }

        case BASE_ACESTRUC_BLOCK_RECOVERY2:
        {
          ADJUST_ENDIANNESS64(&BASE_ARCBLK.Header.Recovery2.REC_BLK_SIZE);
          ADJUST_ENDIANNESS64(&BASE_ARCBLK.Header.Recovery2.REL_STRT);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Recovery2.SECTORS);
          ADJUST_ENDIANNESS16(&BASE_ARCBLK.Header.Recovery2.SECTORSPERCLUSTER);
          ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Recovery2.CL_SIZE);
          break;
        }
        
        default: /* Looks like this is not needed.. */
        {
          if (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_ADDSIZE)
          {
             if (!(BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_64BIT))
             {
                ADJUST_ENDIANNESS32(&BASE_ARCBLK.Header.Basic32.ADDSIZE);    
             }
             else
             {
                ADJUST_ENDIANNESS64(&BASE_ARCBLK.Header.Basic.ADDSIZE);
             }
          }
          
          break;
        }

     }
}

/*-----------------BASE_ARCBLK_CheckHeaderCRC---------------------------*/

BOOL  BASE_ARCBLK_CheckHeaderCRC(void)
{
  return BASE_ARCBLK.Header.Basic.HEAD_CRC == 
     BASE_ARCBLK_CalculateHeaderCRC(&BASE_ARCBLK.Header);
}

/*-----------------BASE_ARCBLK_LoadBlock---------------------------------*/

BOOL    BASE_ARCBLK_LoadBlock(void)
{
BOOL      Result;
INT       Read;

  BASE_ARCBLK_SkipFileBlock();
  BASE_ARCBLK.DoCopyBlockToTempArchive = 0;

  BASE_BUFREAD_Seek(BASE_ARCBLK.SkipSize, SEEK_CUR);
  BASE_ARCBLK.BlockPos = BASE_BUFREAD_Tell();

  if (BASE_BUFREAD_Read((PCHAR) &BASE_ARCBLK.Header, 4) == 0)
  {
    return
      (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE
       && BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SPLITAFTER) ?
         BASE_VOLUME_NextVolumeToProcess(1) : 0;
  }

  BASE_ARCBLK_AdjustEndiannessOfHeaderBase();
  
  Read = BASE_BUFREAD_Read((PCHAR) &BASE_ARCBLK.Header.Basic.HEAD_TYPE,
                              BASE_ARCBLK.Header.Basic.HEAD_SIZE);

  Result = BASE_ARCBLK.Header.Basic.HEAD_SIZE == Read;

  BASE_ARCBLK_ConvertHeader32ToHeader64();

  if (!BASE_ARCBLK.Header.Basic.HEAD_CRC)
  {
    BASE_ERROROUT_EXTERN_BrokenArchive();
    BASE_ERROR.ErrorCode = BASE_ERROR_BADCRC;

    return 0;
  }

  BASE_ARCBLK.SkipSize = BASE_ARCBLK_GetAddSize(&BASE_ARCBLK.Header);

  return Result;
}

/*-----------------BASE_ARCBLK_ReadAddSizeBlock-------------------------*/

INT     BASE_ARCBLK_ReadAddSizeBlock(PCHAR Buffer, INT Len)
{
BOOL      IsFile;
INT       Read,
          ReadLen,
          RestLen;
PCHAR     BufPos;

  Read    = 0;
  RestLen = Len;
  BufPos  = Buffer;

  IsFile = BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE;

  if (IsFile && (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_PASSWORD))
  {
    RestLen = BASE_CRYPT_CryptLen(RestLen);
  }

  while (!BASE_ERROR.ErrorCode && RestLen)
  {
    ReadLen = BASE_ARCBLK.SkipSize > RestLen ? RestLen : BASE_ARCBLK.SkipSize;

    BASE_ARCBLK.SkipSize -= ReadLen;
    Read += BASE_BUFREAD_Read(BufPos, ReadLen);

    if (IsFile && ReadLen)
    {
      BASE_STATE_OutputProgress(ReadLen, 0, 0, ReadLen, 0);
    }

    BufPos  += ReadLen;
    RestLen -= ReadLen;

    if (!BASE_ARCBLK.SkipSize)
    {
      if (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SPLITAFTER)
      {
        BASE_VOLUME_NextVolumeToProcess(0);
      }
      else
      {
        break;
      }
    }
  }

  if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE
      && (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_PASSWORD))
  {
    BASE_CRYPT_Decrypt(Buffer, Read);
  }

  Len = Read > Len ? Len : Read;

  return Len;
}

/*-----------------BASE_ARCBLK_OpenArchive-------------------------------*/

INT     BASE_ARCBLK_OpenArchive(PCHAR Path, INT Access, BOOL DoOutputError,
                                BOOL DoOutputComm, BOOL DoResetCrypt)
{
tBASE_DIRDATA_DirData
          TempDir;

  TempDir = BASE_DIRDATA_Dir1;

  BASE_ARCBLK.DoOutputComments =
    DoOutputComm && BASE_OPTIONS.ExtractOptions.DoShowComments;

  strcpy(BASE_ARCBLK.ArchiveFile, Path);

  BASE_PATHFUNC_CompletePath(BASE_ARCBLK.ArchiveFile);

  BASE_ARCBLK.SkipSize = 0;

  if (-1 == BASE_BUFREAD_Open(BASE_ARCBLK.ArchiveFile))
  {
    if (DoOutputError)
    {

      BASE_ERROROUT_EXTERN_OpenArchiveRead();
      BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;
    }

    return 0;
  }

  if (!BASE_ARCHIVES_TEST_ArchiveTest(BASE_ARCBLK_EXTERN_CurrentArchiveName(),
                                BASE_ARCHIVES_TEST.MaxTestSectors, 1))
  {
    strcpy (BASE_DIRDATA_Dir1.ArchiveName, BASE_ARCBLK_EXTERN_CurrentArchiveName());
    BASE_ERROROUT_EXTERN_IsNotArchive();
    BASE_DIRDATA_Dir1 = TempDir;    
    
    BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;

    BASE_BUFREAD_Close();

    return 0;
  }

  BASE_ARCBLK.ArchiveBegin = BASE_DIRDATA_Dir1.ArchiveBegin;
  BASE_BUFREAD_Seek(BASE_DIRDATA_Dir1.ArchiveBegin, SEEK_SET);
  BASE_ARCBLK_LoadBlock();

  BASE_ARCBLK_EXTERN_OpenArchivesSetVariables(Access, DoResetCrypt);

  if (DoResetCrypt)
  {
    BASE_CRYPT_InitCryptKey(&BASE_DCPR.Options.CryptionData);
  }

  BASE_DIRDATA_Dir1 = TempDir;

  return 1;
}

