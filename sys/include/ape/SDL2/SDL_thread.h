#ifndef _npe_SDL_thread_h_
#define _npe_SDL_thread_h_

enum {
	SDL_THREAD_PRIORITY_LOW,
	SDL_THREAD_PRIORITY_NORMAL,
	SDL_THREAD_PRIORITY_HIGH,
	SDL_THREAD_PRIORITY_TIME_CRITICAL,
};

typedef struct SDL_Thread SDL_Thread;
typedef int (*SDL_ThreadFunction)(void *);
#pragma incomplete SDL_Thread

SDL_Thread *SDL_CreateThread(SDL_ThreadFunction, char *, void *);
SDL_Thread *SDL_CreateThreadWithStackSize(SDL_ThreadFunction, const char *, size_t, void *);

void SDL_DetachThread(SDL_Thread *);
void SDL_WaitThread(SDL_Thread *, int *);

void SDL_SetThreadPriority(int);

#endif
