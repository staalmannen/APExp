#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef _WIN32
	#include <io.h>
	#include <direct.h>
#else
	#define mkdir(_a) mkdir(_a,  S_IRWXU | S_IRWXG | S_IRWXO)
#endif

#define INCL_BASE_LFN

#define INCL_BASE_DOSFUNCS
#define INCL_BASE_MEMORY
#define INCL_BASE_PATHFUNC
#include "base/includes.h"

tBASE_LFN BASE_LFN;

/*-----------------BASE_LFN_ChangeDir------------------------------------*/

INT     BASE_LFN_ChangeDir(PCHAR Directory)
{
  return chdir(Directory);
}

/*-----------------BASE_LFN_GetCurrentDir--------------------------------*/

PCHAR   BASE_LFN_GetCurrentDir(PCHAR Directory, size_t Size)
{
  Directory = (PCHAR) getcwd(Directory, Size);

  return Directory;
}

/*-----------------BASE_LFN_GetCurrentDirOfDrive-------------------------*/

PCHAR   BASE_LFN_GetCurrentDirOfDrive(INT Drive, PCHAR Directory, size_t Size)
{
INT       SavedDrive;

  SavedDrive = BASE_DOSFUNCS_GetDrive();
  BASE_DOSFUNCS_SetDrive(Drive);
  BASE_LFN_GetCurrentDir(Directory, Size);
  BASE_DOSFUNCS_SetDrive(SavedDrive);

  return Directory;
}

/*-----------------BASE_LFN_Open-----------------------------------------*/

INT     BASE_LFN_Open(PCHAR Path, INT Access,...)
{
#if _WIN32
  INT Permission = _S_IWRITE; // ignored if not creating a file
#else
  INT Permission = 0644;
#endif
  va_list ArgumentList;

  if (Access & O_CREAT)
  {
    va_start(ArgumentList, Access);
    Permission = va_arg(ArgumentList, INT);
    va_end(ArgumentList);
  }
  return open(Path, Access, Permission);
}

/*-----------------BASE_LFN_GetFileAttributes----------------------------*/

UINT    BASE_LFN_GetFileAttributes(PCHAR Path, PUINT Attr)
{
  return BASE_DOSFUNCS_GetFileAttributes(Path, Attr);
}

/*-----------------BASE_LFN_SetFileAttributes----------------------------*/

UINT    BASE_LFN_SetFileAttributes(PCHAR Path, UINT Attr)
{
  return BASE_DOSFUNCS_SetFileAttributes(Path, Attr);
}

/*-----------------BASE_LFN_RemoveFile-----------------------------------*/

INT     BASE_LFN_RemoveFile(PCHAR Path)
{
  return remove(Path);
}

/*-----------------BASE_LFN_Access---------------------------------------*/

INT     BASE_LFN_Access(PCHAR Path, INT Mode)
{
  return access(Path, Mode);
}

/*-----------------BASE_LFN_GetFileTime----------------------------------*/

ULONG   BASE_LFN_GetFileTime(PCHAR FileName)
{
struct findi64_t
          FindStruc;
INT       Handle,
        Result;
  USHORT Date = 0;
  USHORT Time = 0;

  Handle = BASE_LFN_Open(FileName, O_RDONLY | O_BINARY);
  if (Handle == -1)
  {
    if (_dos_findfirsti64(FileName,
          BASE_LFN_GetFindAllFilesAndDirsAttr(), &FindStruc))
    {
      return 0;
    }

    Result = FindStruc.wr_date << 16 | FindStruc.wr_time;
    _dos_findclosei64(&FindStruc);

    return Result;
  }
  ///BASE_DOSFUNCS_GetFileTime(Handle, &Date, &Time);
  close(Handle);

  return Date << 16 | Time;
}



// ============================================================================
// lin.c

#if defined(_WIN32)
char *_strsep(char **stringp, const char *delim)
{
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0;
    }
    return rv;
}
#undef strsep
#define strsep _strsep
#endif

/*-----------------BASE_LFN_CompleteArg0---------------------------------*/
void    BASE_LFN_CompleteArg0(PCHAR *Arg0)
{
PCHAR  Env, SepStr;
struct stat st;
tLFN   SearchFile, Path;

  strcpy(SearchFile, *Arg0);

  if (SearchFile[0] != '.')
  {
    SepStr = getenv("PATH");

    if ((Env = (PCHAR) BASE_MEMORY_GetMem(strlen(SepStr) + 1)))
    {
      strcpy(Env, SepStr);
      SepStr = Env;

      while (SepStr)
      {
       snprintf (Path, sizeof(Path), "%s/%s", strsep( (char *) &SepStr, ":"), SearchFile);

        if (!stat(Path, &st))
        {
          strcpy(SearchFile, Path);

          break;
        }
      }

      BASE_MEMORY_FreeCheck(Env);
    }
  }

  strcpy(BASE_LFN.Arg0, SearchFile);
  *Arg0 = BASE_LFN.Arg0;
}

/*-----------------BASE_LFN_MakeDir--------------------------------------*/
INT     BASE_LFN_MakeDir(PCHAR Dir)
{
INT	  Result;

  Result = mkdir(Dir);
  if (!Result) chmod(Dir, 0755);
  return Result;
}


// ============================================================================
// nodos32.c

/*-----------------BASE_LFN_FindFirst------------------------------------*/
INT     BASE_LFN_FindFirst(PCHAR Specification, INT Attr,
                      pBASE_LFN_FINDSTRUCT DirStruc)
{
struct findi64_t *FindStruc;
  FindStruc = (struct findi64_t*) &DirStruc->DosFindStruct;

  if (_dos_findfirsti64(Specification, Attr, FindStruc))
  {
    errno = -1;
    return 1;
  }

  strcpy(DirStruc->Name, FindStruc->name);
  DirStruc->Attributes = FindStruc->attrib;
  DirStruc->Time = FindStruc->wr_time;
  DirStruc->Date = FindStruc->wr_date;
  DirStruc->Size = FindStruc->size;

  return 0;
}

/*-----------------BASE_LFN_FindNext-------------------------------------*/
INT     BASE_LFN_FindNext(pBASE_LFN_FINDSTRUCT DirStruc)
{
struct findi64_t *FindStruc;

  FindStruc = (struct findi64_t*) &DirStruc->DosFindStruct;

  if (_dos_findnexti64(FindStruc))
  {
    errno = -1;
    return 1;
  }
  strcpy(DirStruc->Name, FindStruc->name);

  DirStruc->Attributes = FindStruc->attrib;
  DirStruc->Time = FindStruc->wr_time;
  DirStruc->Date = FindStruc->wr_date;
  DirStruc->Size = FindStruc->size;

  return 0;
}

/*-----------------BASE_LFN_FindClose------------------------------------*/
INT     BASE_LFN_FindClose(pBASE_LFN_FINDSTRUCT DirStruc)
{
  if (_dos_findclosei64((struct findi64_t*)&DirStruc->DosFindStruct))
  {
    errno = -1;
    return 1;
  }

  return 0;
}

/*-----------------BASE_LFN_RemoveDir------------------------------------*/
INT     BASE_LFN_RemoveDir(PCHAR Dir)
{
  return rmdir(Dir);
}

// ============================================================================
// nont.c

/*-----------------BASE_LFN_ConvertFileName------------------------------*/

void    BASE_LFN_ConvertFileName(PCHAR Path, INT Attr)
{
  tLFN DriveStr;
  PCHAR NamePos;

  strcpy(DriveStr, Path);
  BASE_PATHFUNC_CompletePath(DriveStr);
  DriveStr[2] = 0;

  for (NamePos = Path; *NamePos; NamePos++)
  {
    if (strchr("*\x22<>|", *NamePos))
    {
      *NamePos = '_';
    }
  }
}

/*-----------------BASE_LFN_GetFindAllFilesAndDirsAttr-------------------*/

INT     BASE_LFN_GetFindAllFilesAndDirsAttr(void)
{
  return BASE_DOSFUNCS_RDONLY | BASE_DOSFUNCS_HIDDEN | BASE_DOSFUNCS_SYSTEM | BASE_DOSFUNCS_SUBDIR | BASE_DOSFUNCS_ARCH;
}

/*-----------------BASE_LFN_GetFindAllFilesAttr--------------------------*/

INT     BASE_LFN_GetFindAllFilesAttr(void)
{
  return BASE_DOSFUNCS_RDONLY | BASE_DOSFUNCS_HIDDEN | BASE_DOSFUNCS_SYSTEM | BASE_DOSFUNCS_ARCH;
}
