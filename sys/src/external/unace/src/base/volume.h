#ifndef _BASE_VOLUME_H_INCLUDED
#define _BASE_VOLUME_H_INCLUDED

typedef struct
{
  BOOL    DoNotProcessNextVolume,
          DoProcessAllVolumes;
  UINT    CurrentVolumeNumber;
} tBASE_VOLUME;

extern tBASE_VOLUME BASE_VOLUME; //volume.c

PCHAR   BASE_VOLUME_GetVolumeName(PCHAR NewVolumeName, PCHAR VolumeName,
                                  INT AddToVolumeNumber, BOOL IsSFX);
INT     BASE_VOLUME_NextVolumeToProcess(BOOL IsZeroLengthFile);
void    BASE_VOLUME_PreviousVolumeToProcess(void);
INT     BASE_VOLUME_FirstVolumeToProcess(PCHAR VolumeName);
INT     BASE_VOLUME_EXTERN_ChangeVolumeToProcess(PCHAR VolumeName);

#endif
