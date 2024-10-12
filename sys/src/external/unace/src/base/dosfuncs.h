#ifndef _BASE_DOSFUNCS_H_INCLUDED
#define _BASE_DOSFUNCS_H_INCLUDED


#define BASE_DOSFUNCS_NORMAL       0x00
#define BASE_DOSFUNCS_RDONLY       0x01
#define BASE_DOSFUNCS_HIDDEN       0x02
#define BASE_DOSFUNCS_SYSTEM       0x04
#define BASE_DOSFUNCS_VOLID        0x08
#define BASE_DOSFUNCS_SUBDIR       0x10
#define BASE_DOSFUNCS_ARCH         0x20
#define BASE_DOSFUNCS_COMPRESSED   0x800

#if defined(_WIN32)
  #define BASE_DOSFUNCS_NULLDEVICE "NUL"
#else
  #define BASE_DOSFUNCS_NULLDEVICE "/dev/null"
#endif

#ifndef FINDI64_DEFINED
struct findi64_t {
        char reserved[21];      /* reserved for use by DOS     */
        char attrib;            /* attribute byte for file     */
        unsigned short wr_time; /* time of last write to file  */
        unsigned short wr_date; /* date of last write to file  */
        int64_t size;    	/* length of file in bytes     */
        char name[260];         /* null-terminated filename    */
        char SearchMask[260];   /* null-terminated search mask */
};
#endif

#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h

typedef struct
{
  UINT    Second:5;
  UINT    Minute:6;
  UINT    Hour:5;
  UINT    Day:5;
  UINT    Month:4;
  UINT    Year:7;
} tBASE_DOSFUNCS_FileTime,
 *pBASE_DOSFUNCS_FileTime;

#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h

void    BASE_DOSFUNCS_SetDir(PCHAR Dir);
BOOL    BASE_DOSFUNCS_FileExists(PCHAR FileName);
INT     BASE_DOSFUNCS_GetDrive(void);
void    BASE_DOSFUNCS_SetDrive(INT Drive);
void    BASE_DOSFUNCS_SetFileTime(PCHAR FileName, INT Handle, ULONG MSDOSTime);

tBASE_DOSFUNCS_FileTime 
		BASE_DOSFUNCS_CalcFileTime(ULONG MSDOSTime);

void    BASE_DOSFUNCS_SetDrive(INT Drive);

LONGLONG BASE_DOSFUNCS_LSeek(INT Handle, LONGLONG Offset, INT Origin);
LONGLONG BASE_DOSFUNCS_Tell(INT Handle);
LONGLONG BASE_DOSFUNCS_ChSize(INT Handle, LONGLONG Size);

UINT    BASE_DOSFUNCS_GetFileAttributes(PCHAR Path, PUINT Attr);
UINT    BASE_DOSFUNCS_SetFileAttributes(PCHAR Path, UINT Attr);
UINT    BASE_DOSFUNCS_GetCompressedFileAttributeByHandle(INT hFile);
BOOL	BASE_DOSFUNCS_IsDir(PCHAR Path);

void    BASE_DOSFUNCS_EXTERN_CopyFileInfoBegin(PCHAR TargetFileName,
                                               PCHAR SourceFileName);

#ifndef FINDI64_DEFINED
UINT    _dos_findfirsti64(CHAR *Path, UINT Attr, struct findi64_t *Bufi64);
UINT    _dos_findnexti64( struct findi64_t *Bufi64);
UINT    _dos_findclosei64( struct findi64_t *Bufi64);

LONGLONG __filelengthi64(INT Handle);
#endif

#endif
