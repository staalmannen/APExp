#ifndef _npe_SDL_rwops_h_
#define _npe_SDL_rwops_h_

typedef struct SDL_RWops SDL_RWops;
typedef struct npe_sdl_rwops npe_sdl_rwops;
#pragma incomplete npe_sdl_rwops

enum {
	RW_SEEK_SET,
	RW_SEEK_CUR,
	RW_SEEK_END,
};

struct SDL_RWops {
	vlong (*size)(struct SDL_RWops *);
	vlong (*seek)(struct SDL_RWops *, vlong, int);
	size_t (*read)(struct SDL_RWops *, void *, size_t, size_t);
	size_t (*write)(struct SDL_RWops *, const void *, size_t, size_t);
	int (*close)(struct SDL_RWops *);
	npe_sdl_rwops *p;
};

SDL_RWops *SDL_RWFromFile(const char *, const char *);
SDL_RWops *SDL_RWFromMem(void*, int);
size_t SDL_RWread(SDL_RWops *, void *, size_t, size_t);
size_t SDL_RWwrite(SDL_RWops *, const void *, size_t, size_t);
vlong SDL_RWseek(SDL_RWops *, vlong, int);
vlong SDL_RWtell(SDL_RWops *);
vlong SDL_RWsize(SDL_RWops *);
int SDL_RWclose(SDL_RWops *);

#endif
