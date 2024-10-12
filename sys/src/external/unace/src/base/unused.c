// unused stuff - this should probably be deleted

#define INCL_BASE_ARCINFO

#define INCL_BASE_ARCHIVES_READ
#define INCL_BASE_DIRDATA
#define INCL_BASE_VOLUME

#include "base/includes.h"

void BASE_ARCINFO_GetArchiveInfo(PCHAR ArchiveName)
{
  BASE_DIRDATA_Dir1.UnPackedSize = 0;

  if (!BASE_ARCHIVES_READ_ReadArchive(ArchiveName))
  {
      BASE_DIRDATA_Dir1.UnPackedSize =
        BASE_DIRDATA_Dir1.IsMultiVol = 0;

      BASE_DIRDATA_Dir1.Dictionary = 1;
  }

  BASE_VOLUME.CurrentVolumeNumber = BASE_DIRDATA_Dir1.VolumeNumber;

  BASE_FILELIST.SizeOfFiles =
    BASE_DIRDATA_Dir1.IsMultiVol ? 0 : BASE_DIRDATA_Dir1.UnPackedSize;
}
