#ifndef _npe_SDL_image_h_
#define _npe_SDL_image_h_

#define SDL_IMAGE_MAJOR_VERSION 2
#define SDL_IMAGE_MINOR_VERSION 0
#define SDL_IMAGE_PATCHLEVEL 6

enum {
	IMG_INIT_JPG = 1<<0,
	IMG_INIT_PNG = 1<<1,
	IMG_INIT_TIF = 1<<2,
};

int IMG_Init(int flags);
void IMG_Quit(void);

SDL_Surface *IMG_LoadTyped_RW(SDL_RWops *src, int freesrc, const char *type);
SDL_Surface *IMG_Load(const char *file);
SDL_Surface *IMG_Load_RW(SDL_RWops *src, int freesrc);

SDL_Texture *IMG_LoadTexture(SDL_Renderer *renderer, const char *file);
SDL_Texture *IMG_LoadTexture_RW(SDL_Renderer *renderer, SDL_RWops *src, int freesrc);
SDL_Texture *IMG_LoadTextureTyped_RW(SDL_Renderer *renderer, SDL_RWops *src, int freesrc, const char *type);

SDL_Surface *IMG_LoadBMP_RW(SDL_RWops *src);
SDL_Surface *IMG_LoadGIF_RW(SDL_RWops *src);
SDL_Surface *IMG_LoadJPG_RW(SDL_RWops *src);
SDL_Surface *IMG_LoadPNG_RW(SDL_RWops *src);
SDL_Surface *IMG_LoadPNM_RW(SDL_RWops *src);
SDL_Surface *IMG_LoadTGA_RW(SDL_RWops *src);
SDL_Surface *IMG_LoadTIF_RW(SDL_RWops *src);

int IMG_SavePNG(SDL_Surface *surface, const char *file);
int IMG_SavePNG_RW(SDL_Surface *surface, SDL_RWops *dst, int freedst);
int IMG_SaveJPG(SDL_Surface *surface, const char *file, int quality);
int IMG_SaveJPG_RW(SDL_Surface *surface, SDL_RWops *dst, int freedst, int quality);

#define IMG_SetError SDL_SetError
#define IMG_GetError SDL_GetError

#endif
