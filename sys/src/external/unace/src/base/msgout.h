#ifndef _BASE_MSGOUT_H_INCLUDED
#define _BASE_MSGOUT_H_INCLUDED
void    BASE_MSGOUT_EXTERN_ListCreateBegin(PVOID *SavedScreen);
void    BASE_MSGOUT_EXTERN_ReadingArchive(PVOID *SavedScreen);
void    BASE_MSGOUT_EXTERN_Analyzing(PCHAR FileName);
void    BASE_MSGOUT_EXTERN_ExtractingOrTesting(BOOL IsExtracting);
void    BASE_MSGOUT_EXTERN_TestBegin(PCHAR ArchiveName);
#endif
