#ifndef _BASE_ARCHIVES_READ_H_INCLUDED
#define _BASE_ARCHIVES_READ_H_INCLUDED

#include "base/filelist.h"

typedef struct
{
  pBASE_FILELIST_FileData
          FileData;
  PCHAR   FileNames,
          FileNamesEnd;
  INT     MaxFileNumber,
          FileNumber;
  void    (*ProcessFile)
             (PCHAR FileName, tBASE_FILELIST_FileData FileData);
} tBASE_ARCHIVES_READ;

extern tBASE_ARCHIVES_READ BASE_ARCHIVES_READ; //read.c

void    BASE_ARCHIVES_READ_FreeArchiveList(void);
void    BASE_ARCHIVES_READ_GetArchiveList(void);
INT     BASE_ARCHIVES_READ_ReadArchive(PCHAR ArchiveName);
void    BASE_ARCHIVES_READ_EXTERN_ReadArchiveProc(void);
void    BASE_ARCHIVES_READ_EXTERN_GetArchiveDescription(void);

#endif
