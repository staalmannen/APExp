#ifndef _BASE_ARCHIVES_TEST_H_INCLUDED
#define _BASE_ARCHIVES_TEST_H_INCLUDED

#include "base/dirdata.h"

typedef struct
{
  INT     MaxTestSectors;
  CHAR    TestBuffer[512 + 32];
  INT     ArchiveHandle;

} tBASE_ARCHIVES_TEST;

extern tBASE_ARCHIVES_TEST BASE_ARCHIVES_TEST; //test.c

INT     BASE_ARCHIVES_TEST_ArchiveTest(PCHAR FileName, INT MaxTestSecs,
                                       BOOL IgnoreKeys);
#endif
