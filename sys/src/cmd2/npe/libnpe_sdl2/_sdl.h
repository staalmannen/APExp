#include <SDL2/SDL.h>
#include <sys/stat.h>
#include <stdint.h>
#include <string.h>
#include <tos.h>
#include <thread.h>
#include <draw.h>
#include <memdraw.h>
#include <mouse.h>
#include <cursor.h>
#include <plumb.h>
#include "_npe.h"

struct npe_sdl {
	Mousectl *mctl;
	Rectangle grabout;
	Point center;
	int mgrab;
	Mouse m, om;
	int hints;
	int mredraw;
	int fullredraw;
	int textinput;
	float scale;
};

enum {
	Altf4noclose = 1<<0,
};

extern struct npe_sdl npe_sdl;

int npe_sdl_init_input(void);
void *npe_sdl_scale(u32int *src, int iw, int ih, u32int *dst, int ow, int oh);
