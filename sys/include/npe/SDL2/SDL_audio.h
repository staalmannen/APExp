#ifndef _npe_SDL_audio_h_
#define _npe_SDL_audio_h_

enum {
	AUDIO_U8 = 1,
	AUDIO_S8,
	AUDIO_U16LSB,
	AUDIO_S16LSB,
	AUDIO_U16MSB,
	AUDIO_S16MSB,
	AUDIO_S32LSB,
	AUDIO_S32MSB,
	AUDIO_F32LSB,
	AUDIO_F32MSB, /* FIXME not supported */
	AUDIO_NUM_FORMATS,
	/* show me that BIG endian device of yours */
	AUDIO_U16 = AUDIO_U16LSB,
	AUDIO_S16 = AUDIO_S16LSB,
	AUDIO_S32 = AUDIO_S32LSB,
	AUDIO_F32 = AUDIO_F32LSB,
	AUDIO_U16SYS = AUDIO_U16,
	AUDIO_S16SYS = AUDIO_S16,
	AUDIO_S32SYS = AUDIO_S32,
	AUDIO_F32SYS = AUDIO_F32,

	SDL_AUDIO_ALLOW_FREQUENCY_CHANGE = 1<<0,
	SDL_AUDIO_ALLOW_FORMAT_CHANGE = 1<<1,
	SDL_AUDIO_ALLOW_CHANNELS_CHANGE = 1<<2,
	SDL_AUDIO_ALLOW_SAMPLES_CHANGE = 1<<3,
	SDL_AUDIO_ALLOW_ANY_CHANGE = ~0,
};

typedef struct SDL_AudioSpec SDL_AudioSpec;
typedef int SDL_AudioDeviceID;

struct SDL_AudioSpec {
	void (*callback)(void *, Uint8 *, int);
	void *userdata;
	int freq;
	int format;
	int channels;
	int samples;
};

char *SDL_GetAudioDeviceName(int, SDL_bool);
int SDL_GetNumAudioDevices(int);

void SDL_LockAudioDevice(SDL_AudioDeviceID);
void SDL_UnlockAudioDevice(SDL_AudioDeviceID);

SDL_AudioDeviceID SDL_OpenAudioDevice(char *, int, SDL_AudioSpec *, SDL_AudioSpec *, u32int);
void SDL_PauseAudioDevice(SDL_AudioDeviceID, SDL_bool);
void SDL_CloseAudioDevice(SDL_AudioDeviceID);

#endif
