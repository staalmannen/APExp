#ifndef _npe_SDL_mixer_h_
#define _npe_SDL_mixer_h_

#include <SDL2/SDL_rwops.h>

/* The internal format for an audio chunk */
typedef struct Mix_Chunk {
	int allocated;
	Uint8 *abuf;
	Uint32 alen;
	Uint8 volume;		/* Per-sample volume, 0-128 */
} Mix_Chunk;

typedef struct Mix_Music {
	int type;
	int loops;
	int fd;
	char *loc;
} Mix_Music;

typedef void (*Mix_EffectFunc_t)(int chan, void *stream, int len, void *udata);
typedef void (*Mix_EffectDone_t)(int chan, void *udata);

int Mix_OpenAudio(int,Uint16,int,int);
char* Mix_GetError(void);
int Mix_RegisterEffect(int,Mix_EffectFunc_t,Mix_EffectDone_t,void*);
Mix_Chunk* Mix_QuickLoad_RAW(Uint8*, Uint32);
int Mix_PlayChannel(int,Mix_Chunk*,int);
int Mix_HaltChannel(int);
void Mix_FreeChunk(Mix_Chunk*);
void Mix_CloseAudio(void);
int Mix_Init(int);
int Mix_VolumeMusic(int);
int Mix_PlayingMusic(void);
int Mix_PausedMusic(void);
void Mix_ResumeMusic(void);
void Mix_PauseMusic(void);
int Mix_PlayingMusic(void);
int Mix_PausedMusic(void);
int Mix_HaltMusic(void);
int Mix_PlayMusic(Mix_Music *music, int loops);
Mix_Music* Mix_LoadMUS_RW(SDL_RWops *src, int freesrc);
Mix_Music* Mix_LoadMUS(char *filename);

enum {
	MIX_INIT_MID = 1,

	MIX_DEFAULT_FORMAT = 1,

	SDL_MIX_MAXVOLUME = 100,
};

#endif
