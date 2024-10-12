#ifndef _BASE_FUNCS_H_INCLUDED
#define _BASE_FUNCS_H_INCLUDED

typedef struct
{
        BOOL    DidNotCopyAll,
                DoOverwriteAll,
                DoDeleteAll;
} tBASE_FUNCS;

extern tBASE_FUNCS BASE_FUNCS;

void    BASE_FUNCS_Copy(INT Mode);
INT     BASE_FUNCS_DeleteRealFile(PCHAR FileName, BOOL IsOverwriteDelete);
void    BASE_FUNCS_Delete(BOOL DoNotAsk);
void    BASE_FUNCS_CreatePathDirectories(PCHAR FileName);
INT     BASE_FUNCS_CreateDestinationFile(INT Attr);
void    BASE_FUNCS_EXTERN_DoCopy(INT Mode);
BOOL    BASE_FUNCS_EXTERN_RequestOverwriteSysFile(void);
INT     BASE_FUNCS_EXTERN_MoveDeleteRealSysFileRequest(void);
BOOL    BASE_FUNCS_EXTERN_CreateDestinationFileRequestOverwrite(void);
void    BASE_FUNCS_EXTERN_RemoveCreatedArchive(void);

#endif
