#ifndef _npe_portmidi_h_
#define _npe_portmidi_h_

#pragma lib "libnpe_portmidi.a"

typedef struct PmStream PmStream;
typedef struct PmEvent PmEvent;
typedef struct PmDeviceInfo PmDeviceInfo;
typedef int PmError;
typedef int PmDeviceID;
typedef int PmTimestamp;
typedef PmTimestamp (*PmTimeProcPtr)(void *);

#pragma incomplete PmStream

struct PmEvent {
	int message;
};

struct PmDeviceInfo {
	char *name;
};

enum {
	pmNoError,
};

int Pm_Initialize(void);
int Pm_CountDevices(void);
int Pm_OpenInput(PmStream **, PmDeviceID, void *, int, PmTimeProcPtr, void *);
PmDeviceInfo *Pm_GetDeviceInfo(PmDeviceID);
int Pm_Read(PmStream *, PmEvent *, int);

#endif
