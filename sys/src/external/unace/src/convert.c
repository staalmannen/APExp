#include <stdio.h>
#include <string.h>

#define INCL_APPS_EXE_CONVERT

#define INCL_BASE_CONVERT
#define INCL_BASE_FILELIST
#define INCL_BASE_PATHFUNC

#define INCL_APPS_EXE_MESSAGES

#include "unace_includes.h"

static CHAR ToPercentStrStr[20];

/*-----------------APPS_EXE_CONVERT_ToByteUnitStr------------------------*/
PCHAR   APPS_EXE_CONVERT_ToByteUnitStr(PCHAR Str, ULONGLONG ByteSize)
{
PCHAR     UNITCHARS = "\0KMG";
INT       StrLen,
          UnitCharNumber;

  UnitCharNumber =
    Str[0]       = 0;

  while (ByteSize > 1024 * 1024)
  {
    ByteSize >>= 10;
    UnitCharNumber++;
  }

  ByteSize = (ByteSize / 1000000) * 100000000 + (ByteSize / 1000) * 10000
             + ByteSize % 1000;

  sprintf(Str, "%llu ", (unsigned long long)ByteSize);

  StrLen      = strlen(Str) - 1;
  Str[StrLen] = UNITCHARS[UnitCharNumber];

  while ((StrLen -= 4) > 0)
  {
    Str[StrLen] = '.';
  }

  return Str;
}

/*-----------------APPS_EXE_CONVERT_MakeStrShorter-----------------------*/

PCHAR   APPS_EXE_CONVERT_MakeStrShorter(PCHAR DestStr, PCHAR SourceStr, INT Width)
{
  if (strlen(SourceStr) > Width)
  {
    memmove(DestStr, &SourceStr[strlen(SourceStr) - Width + 4], Width - 3);
    BASE_CONVERT_StrCatBefore(BASE_PATHFUNC_SEPARATORSTR "..", DestStr);
  }
  else
  {
    strcpy(DestStr, SourceStr);
  }

  return DestStr;
}

/*-----------------APPS_EXE_CONVERT_GetPercents---------------------------*/

INT     APPS_EXE_CONVERT_GetPercents(ULONGLONG Value1, ULONGLONG Value2)
{
  while (Value1 > 1 << 20)
  {
    Value1 >>= 1;
    Value2 >>= 1;
  }

  if (!Value2)
  {
    return 0;
  }

  return (Value1 * 1000 + (Value2 >> 1)) / Value2;
}

/*-----------------APPS_EXE_CONVERT_ToPercentStr--------------------------*/

PCHAR   APPS_EXE_CONVERT_ToPercentStr(ULONGLONG Value1, ULONGLONG Value2)
{
INT       Percents;

  Percents = APPS_EXE_CONVERT_GetPercents(Value1, Value2);

  snprintf (ToPercentStrStr, sizeof(ToPercentStrStr),
            "%d.%d%%", Percents / 10, Percents % 10);

  return ToPercentStrStr;
}

/*-----------------APPS_EXE_CONVERT_FormatSize---------------------------*/

PCHAR   APPS_EXE_CONVERT_FormatSize(PCHAR SizeStr, INT Attr, ULONGLONG Size)
{
PCHAR     UNITCHARS = "\0KMG";
INT       UnitCharNumber;

  if (Attr & BASE_FILELIST_SUBDIR)
  {
    sprintf(SizeStr, "\x10%s\x11",
            (Attr & BASE_FILELIST_UPDIR) ? STR.UP__DIR : STR.SUB_DIR);
  }
  else
  {
    UnitCharNumber = 0;

    while (Size > 999999999 || (UnitCharNumber && Size > 99999999))
    {
      Size >>= 10;
      UnitCharNumber++;
    }

    if (UnitCharNumber)
    {
      sprintf(SizeStr, "%8llu ", (unsigned long long)Size);
      SizeStr[strlen(SizeStr) - 1] = UNITCHARS[UnitCharNumber];
    }
    else
    {
      sprintf(SizeStr, "%9llu", (unsigned long long)Size);
    }
  }

  return SizeStr;
}
