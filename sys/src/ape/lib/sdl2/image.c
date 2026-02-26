#include "_sdl.h"
#include <SDL2/SDL_image.h>

int
IMG_Init(int flags)
{
	USED(flags);
	werrstr("FIXME IMG_Init not implemented");

	return -1;
}

void
IMG_Quit(void)
{
}

SDL_Surface *
IMG_LoadTyped_RW(SDL_RWops *src, int freesrc, const char *type)
{
	USED(src, freesrc, type);
	return nil;
}

SDL_Surface *
IMG_Load(const char *file)
{
	USED(file);
	return nil;
}

SDL_Surface *
IMG_Load_RW(SDL_RWops *src, int freesrc)
{
	USED(src, freesrc);
	return nil;
}

SDL_Texture *
IMG_LoadTexture(SDL_Renderer *r, const char *file)
{
	USED(r, file);
	return nil;
}

SDL_Texture *
IMG_LoadTexture_RW(SDL_Renderer *r, SDL_RWops *src, int freesrc)
{
	USED(r, src, freesrc);
	return nil;
}

SDL_Texture *
IMG_LoadTextureTyped_RW(SDL_Renderer *r, SDL_RWops *src, int freesrc, const char *type)
{
	USED(r, src, freesrc, type);
	return nil;
}


SDL_Surface *
IMG_LoadBMP_RW(SDL_RWops *src)
{
	USED(src);
	return nil;
}

SDL_Surface *
IMG_LoadGIF_RW(SDL_RWops *src)
{
	USED(src);
	return nil;
}

SDL_Surface *
IMG_LoadJPG_RW(SDL_RWops *src)
{
	USED(src);
	return nil;
}

SDL_Surface *
IMG_LoadPNG_RW(SDL_RWops *src)
{
	USED(src);
	return nil;
}

SDL_Surface *
IMG_LoadPNM_RW(SDL_RWops *src)
{
	USED(src);
	return nil;
}

SDL_Surface *
IMG_LoadTGA_RW(SDL_RWops *src)
{
	USED(src);
	return nil;
}

SDL_Surface *
IMG_LoadTIF_RW(SDL_RWops *src)
{
	USED(src);
	return nil;
}

int
IMG_SavePNG(SDL_Surface *s, const char *file)
{
	USED(s, file);
	return -1;
}

int
IMG_SavePNG_RW(SDL_Surface *s, SDL_RWops *dst, int freedst)
{
	USED(s, dst, freedst);
	return -1;
}

int
IMG_SaveJPG(SDL_Surface *s, const char *file, int quality)
{
	USED(s, file, quality);
	return -1;
}

int
IMG_SaveJPG_RW(SDL_Surface *s, SDL_RWops *dst, int freedst, int quality)
{
	USED(s, dst, freedst, quality);
	return -1;
}
