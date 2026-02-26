#ifndef _npe_SDL_version_h_
#define _npe_SDL_version_h_

typedef struct SDL_version SDL_version;

struct SDL_version {
	u8int major, minor, patch;
};

void SDL_GetVersion(SDL_version *v);

#endif
