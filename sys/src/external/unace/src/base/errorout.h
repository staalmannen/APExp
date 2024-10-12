#ifndef _BASE_ERROROUT_H_INCLUDED
#define _BASE_ERROROUT_H_INCLUDED


void    BASE_ERROROUT_EXTERN_IsNotCompatible(void);
void    BASE_ERROROUT_EXTERN_BrokenArchive(void);
void    BASE_ERROROUT_EXTERN_Write(void);
void    BASE_ERROROUT_EXTERN_OpenArchiveRead(void);
void    BASE_ERROROUT_EXTERN_IsNotArchive(void);
void    BASE_ERROROUT_EXTERN_ManyFilesError(void);
void    BASE_ERROROUT_EXTERN_NoFiles(void);
void    BASE_ERROROUT_EXTERN_UnknownMethod(void);
void    BASE_ERROROUT_EXTERN_Mem(void);
void    BASE_ERROROUT_EXTERN_ExtractMem(void);
void    BASE_ERROROUT_EXTERN_ExcludePath(void);
void    BASE_ERROROUT_EXTERN_ExtractSpace(void);
void    BASE_ERROROUT_EXTERN_OverwriteDelete(void);
void    BASE_ERROROUT_EXTERN_MoveDelete(void);
void    BASE_ERROROUT_EXTERN_CreateDir(PCHAR Dir);
void    BASE_ERROROUT_EXTERN_NameInUse(void);
void    BASE_ERROROUT_EXTERN_CreateFile(void);
void    BASE_ERROROUT_EXTERN_AVBroken(void);
void    BASE_ERROROUT_EXTERN_ReadArchive(void);


#endif
