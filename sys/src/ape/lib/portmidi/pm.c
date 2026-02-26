#include <u.h>
#include <libc.h>
#include "portmidi.h"

int
Pm_Initialize(void)
{
	return 0;
}

int
Pm_CountDevices(void)
{
	return 0;
}

int
Pm_OpenInput(PmStream **, PmDeviceID, void *, int, PmTimeProcPtr, void *)
{
	return -1;
}

PmDeviceInfo *
Pm_GetDeviceInfo(PmDeviceID)
{
	return nil;
}

int
Pm_Read(PmStream *, PmEvent *, int)
{
	return -1;
}
