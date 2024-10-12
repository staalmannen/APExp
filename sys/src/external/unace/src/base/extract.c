#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

#define INCL_BASE_EXTRACT

#define INCL_BASE_ARCBLK
#define INCL_BASE_COMMENTS
#define INCL_BASE_CRC
#define INCL_BASE_DCPR
#define INCL_BASE_DCPR_LZ77
#define INCL_BASE_DIRDATA
#define INCL_BASE_DOSFUNCS
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_FILELIST
#define INCL_BASE_FUNCS
#define INCL_BASE_MEMORY
#define INCL_BASE_MSGOUT
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#define INCL_BASE_VOLUME

#include "base/includes.h"

tBASE_EXTRACT BASE_EXTRACT;

void    BASE_FUNCS_EXTERN_DoCopy(INT Mode)
{
  BASE_EXTRACT_Extract(1, 1);
}


/*-----------------BASE_EXTRACT_DecompressFile---------------------------*/

void    BASE_EXTRACT_DecompressFile(BOOL DoWriteData, BOOL IsTest)
{
tLFN	  PureFileName;
BOOL      IsCRCOk;
SHORT     Attr;
LONG      Time;
PCHAR     Buf;
INT       Handle,
          BytesInBuf,
          Decompressed,
          BytesToWrite,
          BufSize,
          BufPos;
UINT	  OriginalAttr;
PCHAR     NTFSSecurity;
UINT	  NTFSSecuritySize;

  Attr   = BASE_ARCBLK.Header.File.ATTR;
  Time   = BASE_ARCBLK.Header.File.FTIME;
  Buf    = NULL;
  BufPos = 0;

  BASE_STATE.FileSize    = BASE_ARCBLK.Header.File.SIZE;
  BASE_STATE.NewSkipSize = BASE_ARCBLK.Header.File.SIZE;
  BASE_STATE.DoNotCount  = !DoWriteData && !IsTest;

  BASE_STATE_OutputProgress(0, 0, 0, 0, (INT) BASE_ARCBLK.Header.File.ATTR);

  BASE_CRC.ReadCRC = BASE_CRC_MASK;

  if (DoWriteData)
  {
    if (BASE_ARCBLK.DoOutputComments)
    {
      BASE_COMMENTS_EXTERN_Output();
    }

    if (BASE_PATHFUNC_IsNTFSStreamName(BASE_STATE.CurrentFileName))
    {
      snprintf (PureFileName, sizeof(PureFileName), "%s%s",
          BASE_PATHFUNC_GetDevicePathLen(BASE_STATE.CurrentFileName) ?
            "" : BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir2.Dir),
          BASE_STATE.CurrentFileName);

      BASE_PATHFUNC_NTFSStreamGetFileName(PureFileName);
      BASE_DOSFUNCS_GetFileAttributes(PureFileName, &OriginalAttr);
      BASE_DOSFUNCS_SetFileAttributes(PureFileName, OriginalAttr & (0xFFffFFff - BASE_FILELIST_RDONLY));

      Handle = BASE_FUNCS_CreateDestinationFile(Attr);

      BASE_DOSFUNCS_SetFileAttributes(PureFileName, OriginalAttr);
    }
    else
    {
      Handle = BASE_FUNCS_CreateDestinationFile(Attr);
    }
  }
  else
  {
    Handle = 0;
  }

  if (Handle == -2)
  {
    goto RETURN;
  }

  if (Handle == -1)
  {
    BASE_ERROR.ErrorCode = BASE_ERROR_OPEN;

    goto RETURN;
  }

  BufSize = BASE_MEMORY_MemAvailBase2(5);

  if (BufSize < 2048)
  {
    BufSize = 2048;
  }

  if (BufSize >= BASE_DCPR_LZ77.DictionarySize - BASE_CPRDCPR_LZ77_MAXLEN
      && BASE_DCPR_LZ77.DictionarySize > 1024)
  {
    BufSize = BASE_DCPR_LZ77.DictionarySize >> 1;
  }

  if (!(Buf = (PCHAR) BASE_MEMORY_GetMem(BufSize + BASE_CPRDCPR_LZ77_MAXLEN)))
  {
    goto RETURN;
  }

  if (DoWriteData)
  {
    BASE_ARCBLK_FileHeaderSecurityRead(&BASE_ARCBLK.Header, &NTFSSecurity, &NTFSSecuritySize);
  }

  if (!(Attr & BASE_DOSFUNCS_SUBDIR))
  {
    BASE_DCPR_InitFile();

    while (!BASE_ERROR_EXTERN_HandleCancel(1))
    {
      Decompressed = BASE_DCPR_Block(&Buf[BufPos], BufSize
                                     + BASE_CPRDCPR_LZ77_MAXLEN - BufPos);

      if ((!Decompressed && !BufPos) || BASE_ERROR_EXTERN_HandleCancel(1))
      {
        break;
      }

      BytesInBuf   = BufPos + Decompressed;
      BytesToWrite = BytesInBuf > BufSize ? BufSize : BytesInBuf;

      BASE_STATE_EXTERN_OutputProgressData(Buf, BytesToWrite);

      if (DoWriteData)
      {
        BASE_STATE_WriteFile(Handle, Buf, BytesToWrite, 1);
      }
      else
      {
        if (IsTest)
        {
          BASE_STATE_TestOnly(BytesToWrite, 1);
        }
        else
        {
          BASE_STATE_OutputProgress(0, 0, Decompressed, Decompressed, 0);
        }
      }

      if (BytesInBuf > BufSize)
      {
        BufPos = BytesInBuf & (BufSize - 1);
        memcpy(Buf, &Buf[BufSize], BufPos);
      }
      else
      {
        BufPos = 0;
      }

      if (BASE_ERROR.ErrorCode && DoWriteData && BASE_ERROR.ErrorCode != BASE_ERROR_USER)
      {
        BASE_ERROROUT_EXTERN_ExtractSpace();

        break;
      }

      if (errno == 12)
      {
        BASE_ERROROUT_EXTERN_ExtractSpace();

        BASE_ERROR.ErrorCode  =
          BASE_ERROR.DiskFull = BASE_ERROR_FULL;
      }
    }

    BASE_DCPR_DoneFile();

    if (DoWriteData)
    {
      BASE_DOSFUNCS_SetFileTime(BASE_STATE.DestinationFileName, Handle, Time);
      close(Handle);

      if (BASE_ERROR.ErrorCode)
      {
        BASE_LFN_RemoveFile(BASE_STATE.DestinationFileName);
      }
    }

    if (BASE_ERROR.ErrorCode)
    {
      if (Attr & BASE_DOSFUNCS_SUBDIR)
      {
        BASE_STATE.DirCount--;
      }
      else
      {
        BASE_STATE.SummaryFileCount--;
      }

      BASE_STATE.SummaryUnComprBytes = BASE_STATE.SavedUnComprBytes;
      BASE_STATE.SummaryComprBytes   = BASE_STATE.SavedComprBytes;
    }

    if (!(IsCRCOk = BASE_CRC.ReadCRC == BASE_ARCBLK.Header.File.CRC32))
    {
      BASE_ERROR.DidFailCRCCheck = BASE_ERROR_BADCRC;
    }

    BASE_FUNCS.DidNotCopyAll |= BASE_ERROR.DidFailCRCCheck;

    BASE_STATE_OutputCRCOk(IsCRCOk);
  }

  if (DoWriteData)
  {
    BASE_LFN_SetFileAttributes(BASE_STATE.DestinationFileName, Attr);
    // need to implement function to set ntfs security?
    ///BASE_DOSFUNCS_SetFileSecurity(BASE_STATE.DestinationFileName, NTFSSecurity);
    BASE_MEMORY_FreeCheck(NTFSSecurity);
  }

  BASE_MEMORY_FreeCheck(Buf);

  return;

RETURN:

  if (Attr & BASE_DOSFUNCS_SUBDIR)
  {
    BASE_STATE.DirCount--;
  }
  else
  {
    BASE_STATE.SummaryFileCount--;
  }

  BASE_STATE.DoNotCount = 0;
}

/*-----------------BASE_EXTRACT_ExtractFiles-----------------------------*/

void    BASE_EXTRACT_ExtractFiles(BOOL DoWriteData, BOOL IsTest)
{
tLFN      FileName;
PCHAR     FileNamePtr;
INT       FilesNumber;

  FilesNumber = BASE_FILELIST.Number;

  while (!BASE_ERROR_EXTERN_HandleCancel(1)
         && (BASE_EXTRACT.DoExtractAllVolumes
             || (BASE_ARCBLK.Options.IsVolume
                 && BASE_EXTRACT.DoProcessAllVolumes)
             || FilesNumber)
         && BASE_ARCBLK_LoadBlock())
  {
    if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE)
    {
      BASE_ARCBLK_GetFileName(FileName, &BASE_ARCBLK.Header);

      strcpy(BASE_STATE.CurrentFileName,
        FileName + strlen(BASE_PATHFUNC_AddSlashToEnd(
                                             BASE_DIRDATA_Dir1.ArchiveDir)));

      if (!(BASE_EXTRACT.DoRemovePaths
          && BASE_ARCBLK.Header.File.ATTR & BASE_DOSFUNCS_SUBDIR)
          && (BASE_FILELIST_Check(FileName)
              || BASE_EXTRACT.DoExtractAllVolumes))
      {
        if (BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_SPLITBEFORE)
        {
          BASE_VOLUME_PreviousVolumeToProcess();

          break;
        }
        else
        {
          if (BASE_EXTRACT.DoExtractAllVolumes)
          {
            strcpy(BASE_STATE.CurrentFileName, FileName);
          }

          if (BASE_EXTRACT.DoRemovePaths)
          {
            FileNamePtr = strrchr(BASE_STATE.CurrentFileName, BASE_PATHFUNC_SEPARATOR);
            
            if (FileNamePtr)
            {
              strcpy(FileName, FileNamePtr + 1);
              strcpy(BASE_STATE.CurrentFileName, FileName);
            }
          }

          BASE_MSGOUT_EXTERN_ExtractingOrTesting(DoWriteData);

          BASE_EXTRACT_DecompressFile(DoWriteData, IsTest);
          BASE_STATE.DestinationFileName[0] = 0;

          FilesNumber--;
        }
      }
    }
  }
}

/*-----------------BASE_EXTRACT_Extract----------------------------------*/

void    BASE_EXTRACT_Extract(BOOL DoWriteData, BOOL IsTest)
{
tLFN      ArchiveName;

  errno = 0;

  BASE_DCPR.Options       = BASE_OPTIONS.ExtractOptions;

  if (DoWriteData)
  {
    BASE_STATE_EXTERN_SetExtractString();
  }
  else
  {
    BASE_STATE_EXTERN_SetTestString();
  }

  BASE_ARCBLK.DoOpenForReadOnly = 1;

  snprintf (ArchiveName, sizeof(ArchiveName), "%s%s",
          BASE_PATHFUNC_AddSlashToEnd(BASE_DIRDATA_Dir1.Dir),
          BASE_DIRDATA_Dir1.ArchiveName);

  if (BASE_VOLUME_FirstVolumeToProcess(ArchiveName))
  {
    if ((!DoWriteData && BASE_ARCBLK.Options.IsSolid)
         || !BASE_FILELIST.Number)
    {
      BASE_EXTRACT.DoExtractAllVolumes = 1;
      BASE_FILELIST.SizeOfFiles = BASE_DIRDATA_Dir1.UnPackedSize;
    }

    BASE_DCPR_Init();
    BASE_EXTRACT_ExtractFiles(DoWriteData, IsTest);
    BASE_DCPR_Done();
    BASE_ARCBLK_EXTERN_CloseArchive(1);

    BASE_EXTRACT.DoExtractAllVolumes = 0;
  }

  BASE_ARCBLK.DoOpenForReadOnly = 0;
}

/*-----------------BASE_EXTRACT_Test-------------------------------------*/

void    BASE_EXTRACT_Test(PCHAR ArchiveName, BOOL IsTest)
{
tBASE_DIRDATA_DirData
          TempDirData;

  TempDirData = BASE_DIRDATA_Dir1;
  BASE_STATE.IsInitialized         = 0;
  BASE_EXTRACT.DoProcessAllVolumes = 1;

  if (ArchiveName)
  {
    BASE_PATHFUNC_SplitFileName(BASE_DIRDATA_Dir1.Dir,
                                BASE_DIRDATA_Dir1.ArchiveName,
                                ArchiveName);
  }

  if (!BASE_DOSFUNCS_FileExists(ArchiveName))
  {
    if (!BASE_VOLUME_EXTERN_ChangeVolumeToProcess(ArchiveName))
    {
      return;
    }

    BASE_ARCBLK_EXTERN_CloseArchive(0);
  }

  if (BASE_FILELIST_Create(0, 0, 0))
  {
    BASE_EXTRACT_Extract(0, IsTest);
    BASE_FILELIST_Done();
  }

  BASE_EXTRACT.DoProcessAllVolumes = 0;
  BASE_DIRDATA_Dir1 = TempDirData;
}
