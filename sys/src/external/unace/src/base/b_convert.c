#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INCL_BASE_CONVERT

#define INCL_BASE_FILELIST

#include "base/includes.h"

tBASE_CONVERT BASE_CONVERT; //convert.h


/*-----------------BASE_CONVERT_LowCase----------------------------------*/

INT     BASE_CONVERT_LowCase(INT CharCode)
{
  return in(CharCode, 'A', 'Z') ? CharCode + 32 : CharCode;
}

/*-----------------BASE_CONVERT_UpCase-----------------------------------*/

INT     BASE_CONVERT_UpCase(INT CharCode)
{
  return in(CharCode, 'a', 'z') ? CharCode - 32 : CharCode;
}

/*-----------------BASE_CONVERT_StrCatBefore-----------------------------*/

void    BASE_CONVERT_StrCatBefore(PCHAR Str1, PCHAR Str2)
{
tBASE_LFN_DBL     
	TempStr;

  strcpy(TempStr, Str2);
  sprintf(Str2, "%s%s", Str1, TempStr);
}


// =========================================================================
// lin.c

/*-----------------BASE_CONVERT_StrUpr------------------------------------*/
PCHAR   BASE_CONVERT_StrUpr(PCHAR Str)
{
  INT I;
  for (I = 0; I < strlen(Str); I++)
  {
    Str[I] = toupper(Str[I]);
  }
  return Str;
}

/*-----------------BASE_CONVERT_StrLwr----------------------------------*/
PCHAR   BASE_CONVERT_StrLwr(PCHAR Str)
{
  INT I;
  for (I = 0; I < strlen(Str); I++)
  {
    Str[I] = tolower(Str[I]);
  }
  return Str;
}

/*-----------------BASE_CONVERT_StrICmp----------------------------------*/
INT     BASE_CONVERT_StrICmp(PCHAR Str1, PCHAR Str2)
{
  return strcasecmp(Str1, Str2);
}

/*-----------------BASE_CONVERT_StrNICmp---------------------------------*/
INT     BASE_CONVERT_StrNICmp(PCHAR Str1, PCHAR Str2, INT Size)
{
  return strncasecmp(Str1, Str2, Size);
}


// =========================================================================
// NT.C - nont.c

#ifdef _WIN32

/*-----------------BASE_CONVERT_ToOEM------------------------------------*/
PCHAR   BASE_CONVERT_ToOEM(PCHAR Str)
{
  INT  StrLen;
  StrLen = strlen(Str);
  CharToOemBuffA(Str, BASE_CONVERT.ToOEMStr, StrLen);
  BASE_CONVERT.ToOEMStr[StrLen] = 0;
  return BASE_CONVERT.ToOEMStr;
}

/*-----------------BASE_CONVERT_ToANSI-----------------------------------*/
PCHAR   BASE_CONVERT_ToANSI(PCHAR Str)
{
  INT  StrLen;
  StrLen = strlen(Str);
  OemToCharBuffA(Str, BASE_CONVERT.ToANSIStr, StrLen);
  BASE_CONVERT.ToANSIStr[StrLen] = 0;
  return BASE_CONVERT.ToANSIStr;
}

#else

/*-----------------BASE_CONVERT_ToOEM------------------------------------*/
PCHAR   BASE_CONVERT_ToOEM(PCHAR Str)
{
  strcpy(BASE_CONVERT.ToOEMStr, Str);
  return BASE_CONVERT.ToOEMStr;
}

/*-----------------BASE_CONVERT_ToANSI-----------------------------------*/
PCHAR   BASE_CONVERT_ToANSI(PCHAR Str)
{
  strcpy(BASE_CONVERT.ToANSIStr, Str);
  return BASE_CONVERT.ToANSIStr;
}

#endif
