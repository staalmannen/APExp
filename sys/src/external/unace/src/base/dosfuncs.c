#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>

#define INCL_BASE_DOSFUNCS

#define INCL_BASE_CONVERT
#define INCL_BASE_ERROR
#define INCL_BASE_LFN
#define INCL_BASE_MEMORY
#define INCL_BASE_PATHFUNC
#define INCL_BASE_STATE
#include "base/includes.h"


/*-----------------BASE_DOSFUNCS_SetDir----------------------------------*/

void    BASE_DOSFUNCS_SetDir(PCHAR Dir)
{
tLFN 	  SystemDir;

  if (Dir[1] == ':')
  {
    BASE_DOSFUNCS_SetDrive(BASE_CONVERT_UpCase(Dir[0]) - 'A');
  }

  strcpy(SystemDir, Dir);
  BASE_PATHFUNC_ToSystemPathSeparatorN(SystemDir, strlen(SystemDir));

  BASE_LFN_ChangeDir(SystemDir);
}

/*-----------------BASE_DOSFUNCS_FileExists------------------------------*/

BOOL    BASE_DOSFUNCS_FileExists(PCHAR FileName)
{
  struct stat  StatBuf;

  return !stat(FileName, &StatBuf)
         && !strpbrk((PCHAR) FileName, "?*") && FileName[0];
}

/*-----------------BASE_DOSFUNCS_GetDrive--------------------------------*/

INT     BASE_DOSFUNCS_GetDrive(void)
{
tLFN      Directory;

  getcwd(Directory, sizeof(Directory));

  return Directory[0] >= 'a' ? Directory[0] - 'a' : Directory[0] - 'A';
}

/*-----------------BASE_DOSFUNCS_CalcFileTime----------------------------*/

tBASE_DOSFUNCS_FileTime BASE_DOSFUNCS_CalcFileTime(ULONG MSDOSTime)
{
tBASE_DOSFUNCS_FileTime Time;

  Time.Second   = ((MSDOSTime >>  0) & 31) << 1;
  Time.Minute   = (MSDOSTime >>  5) & 63;
  Time.Hour  = (MSDOSTime >>  11) & 31;
  Time.Day  = (MSDOSTime >> 16) & 31;
  Time.Month   = (MSDOSTime >> 21) & 15;
  Time.Year  = (MSDOSTime >> 25) & 127; /* since 1980 */
  
  return Time;
}



// ========================================================================
// lin.c

/*-----------------_dos_findfirsti64-------------------------------------*/

UINT    _dos_findfirsti64(CHAR *Path, UINT Attr, struct findi64_t *Bufi64)
{
  DIR      *DirStruc;
  struct stat StatBuf;
  tLFN  DirToOpen, SearchMask;
  PCHAR ChPtr;

  if (stat(Path, &StatBuf))
  {
    return 1;
  }
  else
  {
    strcpy(DirToOpen, Path);

    if (!(StatBuf.st_mode & S_IFDIR))
    {
      BASE_PATHFUNC_CompletePath(DirToOpen);

      if ((ChPtr = strrchr(DirToOpen, BASE_PATHFUNC_SEPARATOR)))
      {
        strcpy(SearchMask, ChPtr + 1);
    
        if (ChPtr == DirToOpen) {
          ChPtr++;
        }
        *ChPtr = 0;
      } else {
        return 1;
      }
    } else {
      strcpy(SearchMask, "*");
    }

    if ((DirStruc = opendir(DirToOpen)) == NULL)
    {
      return 1;
    }
    else
    {
      *(DIR**) &Bufi64->reserved[0] = DirStruc;
      strcpy(Bufi64->SearchMask, SearchMask);

      return _dos_findnexti64(Bufi64);
    }
  }
}

/*-----------------_dos_findnexti64--------------------------------------*/

UINT    _dos_findnexti64(struct findi64_t *Bufi64)
{
  DIR *Dir;
  struct dirent *Ent;
  Dir = *(DIR**) &Bufi64->reserved[0];

  while (1)
  {
    if ((Ent = readdir(Dir)) == NULL)
    {
      return 1;
    }
    else
    {
      if (BASE_PATHFUNC_WildCardCheck(Ent->d_name, Bufi64->SearchMask))
      {
        Bufi64->size = 0;//_filelengthi64(Dir->dd_handle);
        strcpy(Bufi64->name, Ent->d_name);
        *(DIR**) &Bufi64->reserved[0] = Dir;

        return 0;
      }
    }
  }
}

/*-----------------_dos_findclosei64-------------------------------------*/
UINT    _dos_findclosei64( struct findi64_t *Bufi64)
{
  return closedir(*(DIR**) &Bufi64->reserved[0]);
}

/*-----------------_filelengthi64----------------------------------------*/
LONGLONG __filelengthi64(INT Handle)
{
  LONGLONG OldPos, EndPos;
  OldPos = lseek(Handle, 0, SEEK_CUR);
  EndPos = lseek(Handle, 0, SEEK_END);
  lseek(Handle, OldPos, SEEK_SET);
  return EndPos;
}

/*-----------------BASE_DOSFUNCS_IsDir-----------------------------------*/

BOOL	BASE_DOSFUNCS_IsDir(PCHAR Name)
{
  struct stat StatBuf;
  if (!stat(Name, &StatBuf))
  {
    return !(StatBuf.st_mode & S_IFDIR);
  }
  return 0;
}

/*-----------------BASE_DOSFUNCS_SetFileTime-----------------------------*/

void  BASE_DOSFUNCS_SetFileTime(PCHAR FileName, INT Handle, ULONG MSDOSTime)
{
  struct utimbuf UTimeBuf;
  struct tm TimeTM;

  TimeTM.tm_sec   = ((MSDOSTime >>  0) & 31) << 1;
  TimeTM.tm_min   = (MSDOSTime >>  5) & 63;
  TimeTM.tm_hour  = (MSDOSTime >> 11) & 31;
  TimeTM.tm_mday  = (MSDOSTime >> 16) & 31;
  TimeTM.tm_mon   = (MSDOSTime >> 21) & 15;
  TimeTM.tm_year  = 80 + ((MSDOSTime >> 25) & 127);
  TimeTM.tm_isdst = -1; // divine, if tm_hour is summer or winter time

  UTimeBuf.modtime  = UTimeBuf.actime = mktime(&TimeTM);

  utime(FileName, &UTimeBuf);
}

/*-----------------BASE_DOSFUNCS_SetDrive--------------------------------*/

void    BASE_DOSFUNCS_SetDrive(INT Drive)
{
  tLFN      Directory;
  Directory[0] = 'A' + Drive;
  Directory[1] = ':';
  Directory[2] = 0;
  chdir(Directory);

  if (BASE_DOSFUNCS_GetDrive() != Drive)
  {
    BASE_ERROR.HardwareError      = 2;
    BASE_ERROR.HardwareErrorDrive = Drive;
  }
}

/*-----------------BASE_DOSFUNCS_GetFileAttributes-----------------------*/

UINT    BASE_DOSFUNCS_GetFileAttributes(PCHAR Path, PUINT Attr)
{
  struct stat StatBuf;

  if (stat(Path, &StatBuf) == 0)
  {
    *Attr = 0;
    if (!(StatBuf.st_mode & S_IWUSR)) {
      *Attr |= BASE_DOSFUNCS_RDONLY;
    }
    if (StatBuf.st_mode & S_IFDIR) {
      *Attr |= BASE_DOSFUNCS_SUBDIR;
    }
    return 0;
  }
  else
  {
    return 1; // error!
  }
}

/*-----------------BASE_DOSFUNCS_SetFileAttributes-----------------------*/
UINT    BASE_DOSFUNCS_SetFileAttributes(PCHAR Path, UINT Attr)
{
  struct stat StatBuf;
  if (Attr & BASE_DOSFUNCS_RDONLY)
  {
    if (!stat(Path, &StatBuf))
    {
      chmod(Path, StatBuf.st_mode & 0555);
    }
  }
  return 0;
}

// ========================================================================
// noi64.c

/*-----------------BASE_DOSFUNCS_LSeek-----------------------------------*/
LONGLONG BASE_DOSFUNCS_LSeek(INT Handle, LONGLONG Offset, INT Origin)
{
  return lseek(Handle, (INT)Offset, Origin);
}

/*-----------------BASE_DOSFUNCS_Tell------------------------------------*/
LONGLONG BASE_DOSFUNCS_Tell(INT Handle)
{
  return lseek(Handle, 0, SEEK_CUR);
}

// ========================================================================
// noi64lin.c

/*-----------------BASE_DOSFUNCS_ChSize----------------------------------*/
LONGLONG BASE_DOSFUNCS_ChSize(INT Handle, LONGLONG Size)
{
  return ftruncate(Handle , Size);
}
