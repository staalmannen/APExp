#ifndef _BASE_ERROR_H_INCLUDED
#define _BASE_ERROR_H_INCLUDED

//------ConstantDefines:

#define BASE_ERROR_NOERROR  0
#define BASE_ERROR_MEM      1
#define BASE_ERROR_FILES    2
#define BASE_ERROR_FOUND    3
#define BASE_ERROR_FULL     4
#define BASE_ERROR_OPEN     5
#define BASE_ERROR_READ     6
#define BASE_ERROR_WRITE    7
#define BASE_ERROR_CLINE    8
#define BASE_ERROR_BADCRC   9
#define BASE_ERROR_OTHER    10
#define BASE_ERROR_EXISTS   11
#define BASE_ERROR_USER     255

//------Variables:
typedef struct
{
        BOOL    DiskFull,
                DidFailCRCCheck,
                DoNotHandleCancel,
                UNCSpaceError;
        INT     ErrorCode,
                HardwareError,
                HardwareErrorDrive;
} tBASE_ERROR;

extern tBASE_ERROR BASE_ERROR; //error.c

INT     BASE_ERROR_EXTERN_HandleCancel(BOOL DoReadAllKeys);

#endif
