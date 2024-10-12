#ifndef _BASE_ARCHIVES_ACE_H_INCLUDED
#define _BASE_ARCHIVES_ACE_H_INCLUDED

#define BASE_ARCHIVES_ACE_GETAVCHECKSUM(AV, Len, Time)  (BASE_CRC_GetCRC16(BASE_CRC_MASK,AV,Len)^((USHORT)Time)^((!Time)>>16))

INT     BASE_ARCHIVES_ACE_ArchiveTest(void);
void    BASE_ARCHIVES_ACE_ReadArchive(void);
BOOL    BASE_ARCHIVES_ACE_EXTERN_ArchiveTestAVCheck(BOOL IsUnRegistered);

#endif
