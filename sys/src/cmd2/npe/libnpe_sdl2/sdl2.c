#include "_sdl.h"
#include <bio.h>

struct SDL_Window {
	int dummy;
};

struct SDL_Renderer {
	int logiw;
	int logih;
};

struct SDL_Texture {
	Memimage *m;
	SDL_BlendMode blend;
};

struct SDL_Cursor {
	Image *i;
	Image *m;
	Point hot;
};

static SDL_Window onewin;
static SDL_Renderer oneren;
static Memimage *back;
static u8int *backcopy;
static Image *front;
static int physw, physh;
static SDL_Cursor *oldcursor, *cursor;
static int showcursor = SDL_ENABLE;
static char basepath[PATH_MAX];
static u32int renddrawcol = DBlack;
struct {
	Uint32 r, g, b, a;
} defmask;

struct npe_sdl npe_sdl = {0};

static Cursor nocursor = {
	{0, 0},
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
};

int
SDL_InitSubSystem(int mask)
{
	/* FIXME implement */
	USED(mask);
	return 0;
}

int
SDL_QuitSubSystem(int mask)
{
	/* FIXME implement */
	USED(mask);
	return 0;
}

void
SDL_SetWindowIcon(SDL_Window *w, SDL_Surface *icon)
{
	USED(w); USED(icon);
}

void
SDL_SetWindowBordered(SDL_Window *w, SDL_bool flag)
{
	USED(w); USED(flag);
}

static int
chan2mask(Uint32 chan, Uint32 *rm, Uint32 *gm, Uint32 *bm, Uint32 *am)
{
	switch(chan){
	case ARGB32:
		*am = 0xFF000000;
	if(0){
	case XRGB32:
		*am = 0x00000000;
	}
	case RGB24:
		*rm = 0x00FF0000;
		*gm = 0x0000FF00;
		*bm = 0x000000FF;
		break;
	case ABGR32:
		*am = 0xFF000000;
	if(0){
	case XBGR32:
		*am = 0x00000000;
	}
	case BGR24:
		*bm = 0x00FF0000;
		*gm = 0x0000FF00;
		*rm = 0x000000FF;
		break;
	default:
		assert(0);
	}
	return 0;
}

static ulong
mask2chan(int bpp, Uint32 rm, Uint32 gm, Uint32 bm, Uint32 am)
{
	USED(gm, bm);

	switch(bpp){
	case 8:
		return CMAP8;
	case 24:
		if(rm & 0xFF0000)
			return RGB24;
		else
			return BGR24;
	case 32:
		if(am == 0){
			if(rm & 0xFF0000)
				return XRGB32;
			else
				return XBGR32;
		} else {
			if(rm & 0xFF0000)
				return ARGB32;
			else
				return ABGR32;
		}
	}
	assert(0);
	return 0;
}

static Uint32
chan2pixel(ulong chan)
{
	switch(chan){
	case ARGB32:
		return SDL_PIXELFORMAT_ARGB8888;
	case XRGB32:
		return SDL_PIXELFORMAT_XRGB8888;
	case RGB24:
		return SDL_PIXELFORMAT_RGB24;
	case ABGR32:
		return SDL_PIXELFORMAT_ABGR8888;
	case XBGR32:
		return SDL_PIXELFORMAT_XBGR8888;
	case BGR24:
		return SDL_PIXELFORMAT_BGR24;
	case CMAP8:
		return SDL_PIXELFORMAT_INDEX8;
	}
	assert(0);
	return 0;
}

static ulong
pixel2chan(Uint32 format)
{
	switch(format){
	case SDL_PIXELFORMAT_ARGB8888:
		return ARGB32;
	case SDL_PIXELFORMAT_XRGB8888:
		return XRGB32;
	case SDL_PIXELFORMAT_RGB24:
		return RGB24;
	case SDL_PIXELFORMAT_ABGR8888:
		return ABGR32;
	case SDL_PIXELFORMAT_XBGR8888:
		return XBGR32;
	case SDL_PIXELFORMAT_BGR24:
		return BGR24;
	case SDL_PIXELFORMAT_INDEX8:
		return CMAP8;
	}
	assert(0);
	return 0;
}

int
SDL_Init(int mask)
{
	/* FIXME actually use the mask? */
	USED(mask);

	if(getwd(basepath, sizeof(basepath)) == nil)
		strcpy(basepath, "/");

	if(mask == 0)
		return 0;

	if(memimageinit() < 0)
		goto err;
	if(initdraw(nil, nil, argv0) < 0)
		goto err;
	if(npe_sdl_init_input() != 0)
		goto err;
	npe_sdl.scale = 1;
	physw = Dx(screen->r);
	physh = Dy(screen->r);
	if(chan2mask(screen->chan, &defmask.r, &defmask.g, &defmask.b, &defmask.a) < 0){
		werrstr("SDL_Init: unsupported screen channel");
		return -1;
	}
	return 0;
err:
	werrstr("SDL_Init: %r");
	return -1;
}

int
SDL_ShowCursor(int toggle)
{
	if(toggle == SDL_QUERY)
		return showcursor;

	showcursor = toggle == SDL_ENABLE;
	setcursor(npe_sdl.mctl, (cursor == nil && showcursor) ? nil : &nocursor);

	return showcursor;
}

Uint64
SDL_GetPerformanceFrequency(void)
{
	return _tos->cyclefreq;
}

Uint64
SDL_GetPerformanceCounter(void)
{
	u64int x;

	cycles(&x);

	return x;
}

char *
SDL_GetError(void)
{
	static char err[256];

	snprint(err, sizeof(err), "%r");

	return err;
}

static void *
readfile(char *path, int *got)
{
	void *data, *data2;
	int f, n, r, sz;

	if((f = open(path, OREAD|OCEXEC)) < 0)
		return nil;

	sz = 32768;
	data = nil;
	for(n = 0;; n += r){
		if(sz-n < 65536){
			sz *= 2;
			if((data2 = realloc(data, sz)) == nil)
				goto err;
			data = data2;
		}
		if((r = read(f, (char*)data+n, sz-n-1)) < 0)
			goto err;
		if(r == 0)
			break;
	}

	if(got != nil)
		*got = n;
	((char*)data)[n] = 0;

	return data;
err:
	free(data);
	close(f);
	return nil;
}

char *
SDL_GetClipboardText(void)
{
	return readfile("/dev/snarf", nil);
}

int
SDL_SetClipboardText(char *s)
{
	int f, n;

	n = -1;
	if((f = open("/dev/snarf", OWRITE|OTRUNC|OCEXEC)) >= 0){
		n = strlen(s);
		n = write(f, s, n) == n ? 0 : -1;
		close(f);
	}

	if(n != 0)
		werrstr("SDL_SetClipboardText: %r");

	return n;
}

SDL_Texture *
SDL_CreateTexture(SDL_Renderer *, Uint32 format, int, int w, int h)
{
	SDL_Texture *t;
	int dformat;

	if((dformat = pixel2chan(format)) == 0){
		werrstr("SDL_CreateTexture: format is not supported");
		goto err;
	}
	if((t = malloc(sizeof(*t))) == nil)
		goto err;
	if((t->m = allocmemimage(Rect(0, 0, w, h), dformat)) == nil){
		free(t);
		goto err;
	}
	memfillcolor(t->m, DBlack);

	return t;
err:
	werrstr("SDL_CreateTexture: %r");
	return nil;
}

SDL_Texture *
SDL_CreateTextureFromSurface(SDL_Renderer *r, SDL_Surface *s)
{
	SDL_Texture *t;
	SDL_Rect re;

	if((t = SDL_CreateTexture(r, s->format->format, 0, s->w, s->h)) != nil){
		re.x = 0;
		re.y = 0;
		re.w = s->w;
		re.h = s->h;
		SDL_UpdateTexture(t, &re, s->pixels, s->pitch);
	}

	return t;
}

int
SDL_LockTexture(SDL_Texture *t, const SDL_Rect *re, void **pixels, int *pitch)
{
	Rectangle r;

	r = re ? Rect(re->x, re->y, re->x+re->w, re->y+re->h) : t->m->r;
	*pitch = Dx(r)*(t->m->depth/8);
	*pixels = t->m->data->bdata;
	return 0;
}

int
SDL_UnlockTexture(SDL_Texture *t)
{
	USED(t);
	return 0;
}

int
SDL_UpdateTexture(SDL_Texture *t, SDL_Rect *re, void *pixels, int pitch)
{
	Rectangle r;
	u8int *pix;
	int y, my;

	r = re ? Rect(re->x, re->y, re->x+re->w, re->y+re->h) : t->m->r;
	pix = pixels;
	if(pitch == Dx(r)*4){
		if(loadmemimage(t->m, r, pix, Dx(r)*Dy(r)*4) < 0){
			werrstr("SDL_UpdateTexture: %r");
			return -1;
		}
	}else{
		my = Dy(r);
		for(y = 0; y < my; y++, pix += pitch, r.min.y += 1){
			r.max.y = r.min.y + 1;
			if(loadmemimage(t->m, r, pix, Dx(r)*4) < 0){
				werrstr("SDL_UpdateTexture: %r");
				return -1;
			}
		}
	}

	return 0;
}

int
SDL_SetTextureAlphaMod(SDL_Texture *t, Uint8 alpha)
{
	/* FIXME */
	USED(t, alpha);

	return -1;
}

int
SDL_SetTextureColorMod(SDL_Texture *t, Uint8 r, Uint8 g, Uint8 b)
{
	/* FIXME */
	USED(t, r, g, b);

	return -1;
}

int
SDL_RenderClear(SDL_Renderer *)
{
	if(back != nil)
		memfillcolor(back, renddrawcol);

	return 0;
}

int
SDL_RenderFillRect(SDL_Renderer *r, SDL_Rect *rect)
{
	/* FIXME */
	assert(rect == nil);
	return SDL_RenderClear(r);
}

int
SDL_SetRenderDrawColor(SDL_Renderer *, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	renddrawcol = r<<24 | g<<16 | b<<8 | a;

	return 0;
}

int
SDL_GetWindowDisplayIndex(SDL_Window *)
{
	return 0;
}

void
SDL_Quit(void)
{
	/* FIXME deinitialize */
}

void
SDL_free(void *p)
{
	free(p);
}

SDL_Surface *
SDL_CreateRGBSurface(Uint32, int w, int h, int bpp, Uint32 rm, Uint32 gm, Uint32 bm, Uint32 am)
{
	SDL_Surface *s;
	int n;
	ulong chan;

	rm = rm ? rm : defmask.r;
	gm = gm ? gm : defmask.g;
	bm = bm ? bm : defmask.b;
	if((chan = mask2chan(bpp, rm, gm, bm, am)) == 0){
		werrstr("bad bpp and/or mask");
		return nil;
	}
	n = w*h*bpp/8;
	if((s = calloc(1, sizeof(*s))) == nil){
		werrstr("SDL_CreateRGBSurface: memory");
		return nil;
	}
	s->i = allocmemimage(Rect(0,0,w,h), chan == CMAP8 ? screen->chan : chan);
	s->format = calloc(1, sizeof(SDL_PixelFormat));
	s->format->BytesPerPixel = bpp/8;
	s->format->format = chan2pixel(chan);
	if(chan == CMAP8){
		s->i = allocmemimage(Rect(0,0,w,h), screen->chan);
		s->format->palette = calloc(1, sizeof(SDL_Palette));
		s->format->palette->ncolors = 256;
		s->format->palette->colors = calloc(1, sizeof(SDL_Color) * 256);
		s->pixels = calloc(1, n);
	}else{
		s->i = allocmemimage(Rect(0,0,w,h), chan);
		s->pixels = ((Memimage*)s->i)->data->bdata;
	}
	
	s->w = w;
	s->h = h;
	s->pitch = w*bpp/8;
	s->clip_rect.x = 0;
	s->clip_rect.y = 0;
	s->clip_rect.w = w;
	s->clip_rect.h = h;
	s->n = n;

	return s;
}

SDL_Surface *
SDL_CreateRGBSurfaceFrom(void *pixels, int w, int h, int bpp, int pitch, Uint32 rm, Uint32 gm, Uint32 bm, Uint32 am)
{
	SDL_Surface *s;
	u8int *p;
	int n, y;

	if((s = SDL_CreateRGBSurface(0, w, h, bpp, rm, gm, bm, am)) == nil)
		return nil;

	n = w*bpp/8;
	for(y = 0, p = pixels; y < h; y++, p += pitch)
		memmove(s->pixels + y*n, p, n);

	return s;
}

SDL_Surface *
SDL_CreateRGBSurfaceWithFormat(Uint32 flags, int w, int h, int bpp, Uint32 fmt)
{
	SDL_Surface *s;
	ulong chan;
	Uint32 rm, gm, bm, am;

	if((chan = pixel2chan(fmt)) == 0){
		werrstr("SDL_CreateRGBSurfaceWithFormat: FIXME format %8ux not implemented", fmt);
		return nil;
	}
	chan2mask(chan, &rm, &gm, &bm, &am);
	if((s = SDL_CreateRGBSurface(flags, w, h, bpp, rm, bm, gm, am)) == nil)
		return nil;
	return s;
}

int
SDL_FillRect(SDL_Surface *dst, const SDL_Rect *rect, Uint32 color)
{
	Uint32 *p;
	int i;
	USED(rect);

	switch(dst->format->format){
	case SDL_PIXELFORMAT_XRGB8888:
	case SDL_PIXELFORMAT_ARGB8888:
	case SDL_PIXELFORMAT_XBGR8888:
	case SDL_PIXELFORMAT_ABGR8888:
		p = (Uint32*)dst->pixels;
		for(i = 0; i < dst->n / sizeof(*p); i++)
			p[i] = color;
		break;
	case SDL_PIXELFORMAT_RGB24:
		for(i = 0; i < dst->n; i += 3){
			dst->pixels[i+0] = color;
			dst->pixels[i+1] = color>>8;
			dst->pixels[i+2] = color>>16;
		}
		break;
	case SDL_PIXELFORMAT_INDEX8:
		for(i = 0; i < dst->n; i++)
			dst->pixels[i] = color;
		break;
	}

	return 0;
}

SDL_Palette*
SDL_AllocPalette(int ncolors)
{
	SDL_Palette *p;

	p = malloc(sizeof(*p));
	p->ncolors = ncolors;
	p->colors = mallocz(sizeof(SDL_Color)*ncolors, 1);
	return p;
}

int
SDL_SetPaletteColors(SDL_Palette *palette, const SDL_Color *colors, int firstcolor, int ncolors)
{
	int i;

	assert(palette->ncolors >= firstcolor + ncolors);
	for(i = firstcolor; i < firstcolor + ncolors; i++)
		palette->colors[i] = colors[i - firstcolor];
	return 0;
}

int
SDL_SetSurfacePalette(SDL_Surface *s, SDL_Palette *palette)
{
	s->format->palette = palette;
	return 0;
}

static void
syncpalette(SDL_Surface *s)
{
	SDL_Color *c;
	Uint8 *to;
	int j;

	to = ((Memimage*)s->i)->data->bdata;
	for(j = 0; j < s->n; j++){
		c = s->format->palette->colors + s->pixels[j];
		*to++ = c->b;
		*to++ = c->g;
		*to++ = c->r;
		*to++ = c->a;
	}
}

static void
synctopalette(SDL_Surface *s)
{
	SDL_Color c, *f;
	Uint32 *from;
	int j, k;
	Memimage *i;
	SDL_PixelFormat fmt;

	i = s->i;
	fmt.format = chan2pixel(screen->chan);
	from = (void*)i->data->bdata;
	for(j = 0; j < s->n; j++){
		SDL_GetRGB(from[j], &fmt, &c.r, &c.g, &c.b);
		for(k = 0; k < s->format->palette->ncolors; k++){
			f = s->format->palette->colors + k;
			if(c.r == f->r && c.g == f->g && c.b == f->b)
				break;
		}
		if(k == s->format->palette->ncolors)
			s->pixels[j] = 0; /* FIXME */
		else
			s->pixels[j] = k;
	}
}

int
SDL_BlitSurface(SDL_Surface *src, const SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect)
{
	Rectangle r, r2;

	r = srcrect == nil ? Rect(0, 0, src->w, src->h) : Rect(srcrect->x, srcrect->y, srcrect->x+srcrect->w, srcrect->y+srcrect->h);
	r2 = dstrect == nil ? Rect(0, 0, dst->w, dst->h) : Rect(dstrect->x, dstrect->y, dstrect->x+dstrect->w, dstrect->y+dstrect->h);

	if(src->format->format == SDL_PIXELFORMAT_INDEX8)
		syncpalette(src);

	memimagedraw(dst->i, r2, src->i, ZP, nil, ZP, S);

	if(dst->format->format == SDL_PIXELFORMAT_INDEX8)
		synctopalette(dst);
	return 0;
}

int
SDL_SoftStretch(SDL_Surface *src, const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect)
{
	Rectangle r, r2;
	Memimage *rowimg;
	int w, h;
	int scale;
	ulong *s, *d, *e;
	ulong *out;
	int i, y;

	r = srcrect == nil ? Rect(0, 0, src->w, src->h) : Rect(srcrect->x, srcrect->y, srcrect->x+srcrect->w, srcrect->y+srcrect->h);
	r2 = dstrect == nil ? Rect(0, 0, dst->w, dst->h) : Rect(dstrect->x, dstrect->y, dstrect->x+dstrect->w, dstrect->y+dstrect->h);

	w = Dx(r);
	h = Dy(r);

	scale = Dx(r2)/w;
	if(scale <= 0)
		scale = 1;
	else if(scale > 12)
		scale = 12;

	rowimg = allocmemimage(Rect(0, 0, scale*w, 1), ((Memimage*)src->i)->chan);

	assert(dst->format->format != SDL_PIXELFORMAT_INDEX8);
	if(src->format->format == SDL_PIXELFORMAT_INDEX8)
		syncpalette(src);

	for(y = 0; y < h; y++){
		s = wordaddr(src->i, Pt(0, y));
		d = (ulong*)rowimg->data->bdata;
		e = s + w;
		for(; s < e; s++){
			switch(scale){
			case 12:
				*d++ = *s;
			case 11:
				*d++ = *s;
			case 10:
				*d++ = *s;
			case 9:
				*d++ = *s;
			case 8:
				*d++ = *s;
			case 7:
				*d++ = *s;
			case 6:
				*d++ = *s;
			case 5:
				*d++ = *s;
			case 4:
				*d++ = *s;
			case 3:
				*d++ = *s;
			case 2:
				*d++ = *s;
			case 1:
				*d++ = *s;
			}
		}
		d = (ulong*)rowimg->data->bdata;
		for(i = 0; i < scale; i++){
			out = wordaddr(dst->i, Pt(0, y*scale + i));
			memcpy(out, d, scale*w*4);
		}
	}
	freememimage(rowimg);
	return 0;
}

void
SDL_FreeSurface(SDL_Surface *surface)
{
	freememimage(surface->i);
	memset(surface, 0, sizeof(surface));
	free(surface);
}

void
SDL_GetRGB(Uint32 pixel, SDL_PixelFormat *fmt, Uint8 *r, Uint8 *g, Uint8 *b)
{
	SDL_Color *c;

	switch(fmt->format){
	case SDL_PIXELFORMAT_ARGB8888:
	case SDL_PIXELFORMAT_XRGB8888:
	case SDL_PIXELFORMAT_RGB24:
		*r = pixel>>16;
		*g = pixel>>8;
		*b = pixel;
		break;
	case SDL_PIXELFORMAT_ABGR8888:
	case SDL_PIXELFORMAT_XBGR8888:
	case SDL_PIXELFORMAT_BGR24:
		*b = pixel>>16;
		*g = pixel>>8;
		*r = pixel;
		break;
	case SDL_PIXELFORMAT_INDEX8:
		assert(fmt->palette);
		assert(pixel < fmt->palette->ncolors);
		c = fmt->palette->colors + pixel;
		*r = c->r;
		*g = c->g;
		*b = c->b;
		break;
	default:
		assert(0);
	}
}

Uint32
SDL_MapRGB(SDL_PixelFormat *fmt, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color *c;

	switch(fmt->format){
	case SDL_PIXELFORMAT_ARGB8888:
	case SDL_PIXELFORMAT_XRGB8888:
	case SDL_PIXELFORMAT_RGB24:
		return 0xff<<24 | r<<16 | g<<8 | b;
	case SDL_PIXELFORMAT_ABGR8888:
	case SDL_PIXELFORMAT_XBGR8888:
	case SDL_PIXELFORMAT_BGR24:
		return 0xff<<24 | b<<16 | g<<8 | r;
	case SDL_PIXELFORMAT_INDEX8:
		assert(fmt->palette);
		for(c = fmt->palette->colors; c < fmt->palette->colors + fmt->palette->ncolors; c++){
			if(c->r == r && c->g == g && c->b == b)
				return c - fmt->palette->colors;
		}
	default:
		assert(0);
		return 0;
	}
}

int
SDL_SetColorKey(SDL_Surface *s, int flag, Uint32 key)
{
	s->keyset = flag;
	s->key = key;
	return 0;
}

SDL_Cursor *
SDL_CreateColorCursor(SDL_Surface *s, int hot_x, int hot_y)
{
	SDL_Cursor *c;
	Rectangle r;
	uchar *m;
	int n;

	m = nil;
	if((c = calloc(1, sizeof(*c))) == nil){
		werrstr("memory");
		goto err;
	}

	r = Rect(0, 0, s->w, s->h);
	if(s->keyset){
		if((c->m = allocimage(display, r, GREY8, 0, DTransparent)) == nil)
			goto err;
		if((m = malloc(s->w * s->h)) == nil)
			goto err;
		for(n = 0; n < s->w * s->h; n++){
			m[n] = ((u32int*)s->pixels)[n] == s->key ? 0x00 : 0xff;
			if(m[n] == 0)
				((u32int*)s->pixels)[n] = 0;
		}
		if(loadimage(c->m, r, m, n) < 1)
			goto err;
		free(m);
		m = nil;
	}
	if((c->i = allocimage(display, r, s->keyset ? XRGB32 : ARGB32, 0, DTransparent)) == nil)
		goto err;
	n = s->w * s->h * 4; /* FIXME non-ARGB8888 */
	if(loadimage(c->i, r, s->pixels, n) < 1)
		goto err;

	c->hot = Pt(hot_x, hot_y);

	return c;
err:
	werrstr("SDL_CreateColorCursor: %r");
	if(c != nil){
		freeimage(c->i);
		freeimage(c->m);
	}
	free(c);
	free(m);
	return nil;
}

SDL_Cursor *
SDL_GetDefaultCursor(void)
{
	return nil;
}

SDL_Cursor *
SDL_CreateSystemCursor(SDL_SystemCursor id)
{
	/* FIXME */
	USED(id);

	return nil;
}

void
SDL_SetCursor(SDL_Cursor *c)
{
	if(cursor != c){
		cursor = c;
		npe_sdl.mredraw = 1;
		setcursor(npe_sdl.mctl, (cursor == nil && showcursor) ? nil : &nocursor);
	}
}

void
SDL_FreeCursor(SDL_Cursor *c)
{
	freeimage(c->i);
	free(c);
	if(cursor == c){
		oldcursor = nil;
		cursor = nil;
	}
}

void
SDL_WarpMouseInWindow(SDL_Window *, int x, int y)
{
	moveto(npe_sdl.mctl, Pt(screen->r.min.x+x, screen->r.min.y+y));
}

Uint32
SDL_GetGlobalMouseState(int *x, int *y)
{
	Uint32 b;

	if(x != nil)
		*x = npe_sdl.m.xy.x;
	if(y != nil)
		*y = npe_sdl.m.xy.y;

	b = 0;
	if(npe_sdl.m.buttons & 1)
		b |= SDL_BUTTON_LMASK;
	if(npe_sdl.m.buttons & 2)
		b |= SDL_BUTTON_MMASK;
	if(npe_sdl.m.buttons & 4)
		b |= SDL_BUTTON_RMASK;

	return b;
}

Uint32
SDL_GetMouseState(int *x, int *y)
{
	Uint32 b;

	b = SDL_GetGlobalMouseState(nil, nil);
	if(x != nil)
		*x = npe_sdl.m.xy.x - screen->r.min.x;
	if(y != nil)
		*y = npe_sdl.m.xy.y - screen->r.min.y;

	return b;
}

void
SDL_RenderGetScale(SDL_Renderer *, float *scaleX, float *scaleY)
{
	*scaleX = 1.0;
	*scaleY = 1.0;
}

int
SDL_RenderSetIntegerScale(SDL_Renderer *, SDL_bool enable)
{
	/* FIXME */
	USED(enable);
	return 0;
}

void
SDL_GetWindowSize(SDL_Window *, int *w, int *h)
{
	/* no matter what rio decides */
	*w = physw;
	*h = physh;
}

void
SDL_GL_GetDrawableSize(SDL_Window *, int *w, int *h)
{
	*w = Dx(screen->r);
	*h = Dy(screen->r);
}

void
SDL_GetWindowPosition(SDL_Window *, int *x, int *y)
{
	*x = screen->r.min.x;
	*y = screen->r.min.y;
}

SDL_bool
SDL_IsTextInputActive(void)
{
	return npe_sdl.textinput;
}

void
SDL_StartTextInput(void)
{
	npe_sdl.textinput = SDL_TRUE;
}

void
SDL_StopTextInput(void)
{
	npe_sdl.textinput = SDL_FALSE;
}

void
SDL_Delay(Uint32 ms)
{
	npe_nsleep((uvlong)ms * Nmsec);
}

static int
duff(SDL_BlendMode mode)
{
	if(mode == SDL_BLENDMODE_BLEND)
		return SoverD;

	return S;
}

int
SDL_RenderCopy(SDL_Renderer *rend, SDL_Texture *t, SDL_Rect *sre, SDL_Rect *dre)
{
	Rectangle sr, dr;
	int logiw, logih;
	ulong chan;

	if(rend->logiw > 0 && rend->logih > 0){
		logiw = rend->logiw;
		logih = rend->logih;
	}else{
		logiw = physw;
		logih = physh;
	}

	sr = t->m->r;
	if(sre != nil){
		sr.min = Pt(sre->x, sre->y);
		sr.max = addpt(sr.min, Pt(sre->w, sre->h));
	}

	dr = Rect(0, 0, logiw, logih);
	if(dre != nil){
		dr.min = Pt(dre->x, dre->y);
		dr.max = addpt(dr.min, Pt(dre->w, dre->h));
	}

	if(back == nil || Dx(back->r) != logiw || Dy(back->r) != logih){
		freememimage(back);
		if(screen)
			chan = screen->chan;
		else
			chan = ARGB32;
		back = allocmemimage(Rect(0, 0, logiw, logih), chan);
		if(back == nil){
			werrstr("SDL_RenderCopy: %r");
			return -1;
		}
		free(backcopy);
		backcopy = malloc(logiw*logih*4);
	}

	if(Dx(dr)/Dx(sr) > 1 || Dy(dr)/Dy(sr) > 1)
		npe_sdl_scale((u32int*)byteaddr(t->m, ZP), Dx(sr), Dy(sr), (u32int*)byteaddr(back, ZP), logiw, logih);
	else
		memimagedraw(back, dr, t->m, sr.min, nil, ZP, duff(t->blend));

	return 0;
}

void
SDL_RenderPresent(SDL_Renderer *rend)
{
	Rectangle r, clipr;
	static u32int *b;
	uchar *rb;
	int logiw, logih;

	if(rend->logiw > 0 && rend->logih > 0){
		logiw = rend->logiw;
		logih = rend->logih;
	}else{
		logiw = physw;
		logih = physh;
	}

	npe_sdl.scale = (float)logiw / (float)physw;

	if(!npe_sdl.fullredraw && (npe_sdl.fullredraw = memcmp(backcopy, byteaddr(back, ZP), logiw*logih*4)) == 0 && !npe_sdl.mredraw)
		return;

	r = Rect(0, 0, physw, physh);
	if(front != nil && (Dx(front->r) != physw || Dy(front->r) != physh)){
		freeimage(front);
		front = nil;
		free(b);
		b = nil;
	}
	if(b == nil && (b = realloc(b, physw*physh*4)) == nil){
		fprint(2, "SDL_RenderPresent: %r\n");
		return;
	}
	if(npe_sdl.fullredraw || front == nil){
		rb = npe_sdl_scale((u32int*)byteaddr(back, ZP), Dx(back->r), Dy(back->r), b, physw, physh);
		if(front == nil && (front = allocimage(display, r, XRGB32, 0, DNofill)) == nil){
			fprint(2, "SDL_RenderPresent: %r\n");
			return;
		}
		if(loadimage(front, r, rb, Dx(r)*Dy(r)*4) < 0){
			fprint(2, "SDL_RenderPresent: %r\n");
			return;
		}
	}

	if(cursor != nil && showcursor){
		r.min = subpt(npe_sdl.m.xy, cursor->hot);
		r.max = addpt(r.min, cursor->i->r.max);
		if(!npe_sdl.fullredraw && oldcursor != nil){
			clipr.min = subpt(npe_sdl.om.xy, oldcursor->hot);
			clipr.max = addpt(clipr.min, oldcursor->i->r.max);
			combinerect(&clipr, r);
			replclipr(screen, 0, clipr);
		}
	}
	while(screen == nil && getwindow(display, Refnone) != 1)
		/* drawterm window change lag */;
	draw(screen, screen->r, front, nil, ZP);
	if(cursor != nil && showcursor)
		draw(screen, r, cursor->i, cursor->m, ZP);
	npe_sdl.mredraw = 0;
	npe_sdl.om.xy = npe_sdl.m.xy;
	oldcursor = cursor;

	flushimage(display, 1);

	if(npe_sdl.fullredraw)
		memmove(backcopy, byteaddr(back, ZP), logiw*logih*4);
	else
		replclipr(screen, 0, screen->r);
	npe_sdl.fullredraw = 0;
}

int
SDL_RenderReadPixels(SDL_Renderer *rend, SDL_Rect *rect, Uint32 fmt, void *pixels, int pitch)
{
	Rectangle r, r2;
	Memimage *m;
	int n;

	USED(pitch); /* FIXME pitch */

	if(rect != nil)
		r = Rect(rect->x, rect->y, rect->x+rect->w, rect->y+rect->h);
	else
		r = Rect(0, 0, rend->logiw, rend->logih);

	n = Dx(r)*Dy(r);
	switch(fmt){
	case SDL_PIXELFORMAT_ARGB8888:
	case SDL_PIXELFORMAT_XRGB8888:
		n *= 4;
		m = back;
		break;
	case SDL_PIXELFORMAT_ABGR8888:
		n *= 4;
		r2 = Rect(0,0,Dx(r),Dy(r));
		if((m = allocmemimage(r2, ABGR32)) == nil)
			return -1;
		memfillcolor(m, DBlack);
		memimagedraw(m, r2, back, r.min, nil, ZP, S);
		break;
	case SDL_PIXELFORMAT_RGB24:
		n *= 3;
		r2 = Rect(0,0,Dx(r),Dy(r));
		if((m = allocmemimage(r2, RGB24)) == nil)
			return -1;
		memfillcolor(m, DBlack);
		memimagedraw(m, r2, back, r.min, nil, ZP, S);
		break;
	default:
		werrstr("SDL_RenderReadPixels: format not supported");
		return -1;
	}

	unloadmemimage(m, r, pixels, n);
	if(m != back)
		freememimage(m);

	return 0;
}

Uint32
SDL_GetWindowFlags(SDL_Window *)
{
	/* FIXME is this correct? */
	return SDL_WINDOW_INPUT_FOCUS;
}

int
SDL_RenderSetLogicalSize(SDL_Renderer *r, int w, int h)
{
	if(r->logiw != w || r->logih != h){
		r->logiw = w;
		r->logih = h;
		npe_sdl.fullredraw = 1;
	}

	return 0;
}

int
SDL_GetRendererOutputSize(SDL_Renderer *r, int *w, int *h)
{
	if(w != nil)
		*w = r->logiw;
	if(h != nil)
		*h = r->logih;

	return 0;
}

void
SDL_RenderGetViewport(SDL_Renderer *r, SDL_Rect *rect)
{
	rect->x = rect->y = 0;
	rect->w = r->logiw;
	rect->h = r->logih;
}

void
SDL_SetWindowSize(SDL_Window *, int w, int h)
{
	int f, n;

	if(w == 0 || h == 0)
		return;
	if(physw != w || physh != h){
		if((f = open("/dev/wctl", OWRITE|OCEXEC)) >= 0){
			n = fprint(f, "resize -dx %d -dy %d", w+Borderwidth*2, h+Borderwidth*2);
			if(n > 0){
				while(getwindow(display, Refnone) != 1)
					;
				physw = w;
				physh = h;
				npe_sdl.fullredraw = 1;
			}else{
				fprint(2, "SDL_SetWindowSize: resize: %r\n");
			}
			close(f);
		}else{
			fprint(2, "SDL_SetWindowSize: open: %r\n");
		}
	}
}

int
SDL_ShowSimpleMessageBox(Uint32, char *title, char *message, SDL_Window *)
{
	/* FIXME display a GUI window? */
	fprint(2, "%s: %s\n", title, message);
	return 0;
}

int
SDL_SetWindowFullscreen(SDL_Window *, Uint32)
{
	/* FIXME again, ft2 does NOT check the error code, figure something out */
	werrstr("SDL_SetWindowFullscreen: not implemented");
	return -1;
}

void
SDL_SetWindowGrab(SDL_Window *, SDL_bool grabbed)
{
	/* FIXME not sure if it's worth anything */
	USED(grabbed);
}

void
SDL_SetWindowPosition(SDL_Window *, int x, int y)
{
	int f, n;

	if((f = open("/dev/wctl", OWRITE|OCEXEC)) >= 0){
		n = fprint(f, "move -minx %d -miny %d", x, y);
		close(f);
		if(n > 0){
			while(getwindow(display, Refnone) != 1)
				;
			npe_sdl.fullredraw = 1;
			npe_sdl.grabout = insetrect(screen->r, Dx(screen->r)/8);
			npe_sdl.center = addpt(screen->r.min, Pt(Dx(screen->r)/2, Dy(screen->r)/2));
		}
	}
}

int
SDL_GetDisplayUsableBounds(int displayIndex, SDL_Rect *r)
{
	if(displayIndex != 0)
		return -1;

	if(r == nil)
		return 0;

	r->x = display->image->r.min.x;
	r->y = display->image->r.min.y;
	r->w = Dx(display->image->r);
	r->h = Dy(display->image->r);
	return 0;
}

int
SDL_GetDesktopDisplayMode(int displayIndex, SDL_DisplayMode *mode)
{
	if(displayIndex != 0)
		return -1;

	mode->w = Dx(display->image->r);
	mode->h = Dy(display->image->r);
	mode->format = SDL_PIXELFORMAT_ARGB8888;
	mode->refresh_rate = 0;

	return 0;
}

int
SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode *mode)
{
	return SDL_GetDesktopDisplayMode(displayIndex, mode);
}

int
SDL_GetNumDisplayModes(int displayIndex)
{
	if(displayIndex != 0)
		return -1;
	return 1;
}

int
SDL_GetDisplayMode(int displayIndex, int modeIndex, SDL_DisplayMode *mode)
{
	USED(modeIndex);
	return SDL_GetDesktopDisplayMode(displayIndex, mode);
}

void
SDL_SetWindowTitle(SDL_Window *, char *title)
{
	int f;

	if((f = open("/dev/label", OWRITE|OTRUNC|OCEXEC)) >= 0 || (f = open("/mnt/term/dev/label", OWRITE|OTRUNC|OCEXEC)) >= 0){
		write(f, title, strlen(title));
		close(f);
	}
}

int
SDL_GetNumVideoDisplays(void)
{
	/* FIXME implement multihead for plan9 */
	return 1;
}

void
SDL_DestroyTexture(SDL_Texture *t)
{
	freememimage(t->m);
	free(t);
}

int
SDL_SetTextureBlendMode(SDL_Texture *t, SDL_BlendMode blendMode)
{
	if(blendMode != SDL_BLENDMODE_NONE && blendMode != SDL_BLENDMODE_BLEND){
		werrstr("SDL_SetTextureBlendMode: unsupported blend mode %d", blendMode);
		return -1;
	}

	t->blend = blendMode;

	return 0;
}

SDL_bool
SDL_SetHint(char *name, char *value)
{
	/* FIXME anyone cares about name="SDL_RENDER_SCALE_QUALITY" value="(best|nearest)"? */
	if(strcmp(name, SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4) == 0){
		npe_sdl.hints = (npe_sdl.hints & ~Altf4noclose) | (atoi(value) ? Altf4noclose : 0);
		return SDL_TRUE;
	}

	return SDL_FALSE;
}

SDL_Window *
SDL_CreateWindow(char *title, int x, int y, int w, int h, Uint32)
{
	SDL_SetWindowTitle(&onewin, title);
	SDL_SetWindowSize(&onewin, w, h);

	if(x != SDL_WINDOWPOS_UNDEFINED && y != SDL_WINDOWPOS_UNDEFINED){ /* FIXME either of these can be undefined */
		if(x == SDL_WINDOWPOS_CENTERED)
			x = display->image->r.min.x + (Dx(display->image->r) - w)/2;
		if(y == SDL_WINDOWPOS_CENTERED)
			y = display->image->r.min.y + (Dy(display->image->r) - h)/2;
		SDL_SetWindowPosition(&onewin, x, y);
	}

	return &onewin;
}

SDL_Renderer *
SDL_CreateRenderer(SDL_Window *, int, Uint32)
{
	return &oneren;
}

int
SDL_CreateWindowAndRenderer(int w, int h, Uint32, SDL_Window **win, SDL_Renderer **rend)
{
	SDL_SetWindowSize(&onewin, w, h);
	*win = &onewin;
	*rend = &oneren;
	return 0;
}

int
SDL_SetRenderDrawBlendMode(SDL_Renderer *, SDL_BlendMode blendMode)
{
	if(blendMode != SDL_BLENDMODE_NONE){
		werrstr("SDL_SetRenderDrawBlendMode: only SDL_BLENDMODE_NONE is supported");
		return -1;
	}

	return 0;
}

char *
SDL_GetCurrentVideoDriver(void)
{
	return "/dev/draw";
}

Uint32
SDL_GetTicks(void)
{
	return npe_nanosec() / Nmsec;
}

int
SDL_OpenURL(char *url)
{
	char tmp[PATH_MAX];
	Plumbmsg m;
	int f, r;

	if((f = plumbopen("send", OWRITE|OCEXEC)) < 0)
		return -1;

	memset(&m, 0, sizeof(m));
	m.src = argv0;
	m.wdir = getwd(tmp, sizeof(tmp));
	m.type = "text";
	m.data = url;
	m.ndata = -1;
	r = plumbsend(f, &m);
	close(f);

	return r;
}

char *
SDL_GetBasePath(void)
{
	return strdup(basepath);
}

char *
SDL_GetPrefPath(char *org, char *app)
{
	char *home, *p;

	p = nil;
	if((home = getenv("home")) != nil){
		if((p = smprint("%s/lib/%s/%s", home, org, app)) != nil)
			npe_mkdirp(cleanname(p), 0755);
		free(home);
	}

	return p;
}

SDL_bool
SDL_HasClipboardText(void)
{
	/* most def */
	return SDL_TRUE;
}

void
SDL_RestoreWindow(SDL_Window *)
{
	/* nothing to do here */
}

void
SDL_RaiseWindow(SDL_Window *)
{
	/* nothing to do here */
}

void
SDL_ShowWindow(SDL_Window *)
{
	/* nothing to do here */
}

int
SDL_SetSurfaceRLE(SDL_Surface *, int)
{
	/* nothing to do here */
	return 0;
}

int
SDL_SetSurfaceBlendMode(SDL_Surface *, SDL_BlendMode blendMode)
{
	if(blendMode != SDL_BLENDMODE_NONE){
		werrstr("SDL_SetSurfaceBlendMode: only SDL_BLENDMODE_NONE is supported");
		return -1;
	}

	return 0;
}

int
SDL_LockSurface(SDL_Surface *)
{
	/* nothing to do here */
	return 0;
}

int
SDL_UnlockSurface(SDL_Surface *)
{
	/* nothing to do here */
	return 0;
}

void
SDL_DestroyRenderer(SDL_Renderer *)
{
	/* nothing to do here */
}

void
SDL_DestroyWindow(SDL_Window *)
{
}

SDL_bool
SDL_HasSSE(void)
{
	/* it's not like we have builtins anyway */
	return SDL_FALSE;
}

SDL_bool
SDL_HasSSE2(void)
{
	/* it's not like we have builtins anyway */
	return SDL_FALSE;
}

void
SDL_EnableScreenSaver(void)
{
}

int
SDL_SaveBMP(SDL_Surface *s, const char *file)
{
	u8int h[54];
	Biobuf *f;
	int sz, i;

	if(s->format->format != SDL_PIXELFORMAT_RGB24){
		werrstr("SDL_SaveBMP: not rgb24");
		return -1;
	}
	if((f = Bopen(file, OWRITE|OTRUNC)) == nil)
		return -1;
	sz = sizeof(h) + s->n;
	memset(h, 0, sizeof(h));
	h[0] = 'B';
	h[1] = 'M';
	h[0x02+0] = sz;
	h[0x02+1] = sz>>8;
	h[0x02+2] = sz>>16;
	h[0x02+3] = sz>>24;
	h[0x0a] = sizeof(h);
	h[0x0e] = sizeof(h) - 14;
	h[0x12+0] = s->w;
	h[0x12+1] = s->w>>8;
	h[0x12+2] = s->w>>16;
	h[0x12+3] = s->w>>24;
	h[0x16+0] = s->h;
	h[0x16+1] = s->h>>8;
	h[0x16+2] = s->h>>16;
	h[0x16+3] = s->h>>24;
	h[0x1a] = 1;
	h[0x1c] = 24;
	Bwrite(f, h, sizeof(h));
	memset(h, 0, 4);
	for(i = s->h-1; i >= 0; i--){
		Bwrite(f, s->pixels+i*s->w*3, s->w*3);
		if(s->w & 3)
			Bwrite(f, h, 4-(s->w&3));
	}
	Bterm(f);

	return 0;
}

void
SDL_ClearError(void)
{
}

int
SDL_PeepEvents(SDL_Event *events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType)
{
	/* FIXME implement */
	USED(events, numevents, action, minType, maxType);
	return 0;
}

int
SDL_NumJoysticks(void)
{
	/* FIXME implement */
	return 0;
}

SDL_Joystick *
SDL_JoystickOpen(int n)
{
	/* FIXME implement */
	USED(n);
	return nil;
}

void
SDL_JoystickClose(SDL_Joystick *js)
{
	USED(js);
}

int
SDL_JoystickNumAxes(SDL_Joystick *js)
{
	USED(js);
	return -1;
}

int
SDL_JoystickNumButtons(SDL_Joystick *js)
{
	USED(js);
	return -1;
}

int
SDL_JoystickNumHats(SDL_Joystick *js)
{
	USED(js);
	return -1;
}

int
SDL_JoystickNumBalls(SDL_Joystick *js)
{
	USED(js);
	return -1;
}

int
SDL_JoystickEventState(int state)
{
	USED(state);
	return 0;
}

void
SDL_JoystickUpdate(void)
{
}

char*
SDL_JoystickName(SDL_Joystick *js)
{
	USED(js);
	return nil;
}

Sint16
SDL_JoystickGetAxis(SDL_Joystick *js, int axis)
{
	USED(js); USED(axis);
	return 0;
}

Uint8
SDL_JoystickGetHat(SDL_Joystick *js, int hat)
{
	USED(js); USED(hat);
	return 0;
}

Uint8
SDL_JoystickGetButton(SDL_Joystick *js, int button)
{
	USED(js); USED(button);
	return 0;
}

int
SDL_SetRelativeMouseMode(SDL_bool enabled)
{
	if(screen){
		npe_sdl.grabout = insetrect(screen->r, Dx(screen->r)/8);
		npe_sdl.center = addpt(screen->r.min, Pt(Dx(screen->r)/2, Dy(screen->r)/2));
		if(enabled)
			SDL_ShowCursor(0);
		else
			SDL_ShowCursor(1);
	}
	npe_sdl.mgrab = enabled;
	return 0;
}

void
SDL_SetMainReady(void)
{
}

int
SDL_GetRelativeMouseMode(void)
{
	return npe_sdl.mgrab;
}

SDL_mutex*
SDL_CreateMutex(void)
{
	SDL_mutex *m;

	m = mallocz(sizeof(*m), 1);
	return m;
}

void
SDL_DestroyMutex(SDL_mutex *m)
{
	free(m);
}

int
SDL_LockMutex(SDL_mutex *m)
{
	lock(&m->l);
	return 0;
}

int
SDL_UnlockMutex(SDL_mutex *m)
{
	unlock(&m->l);
	return 0;
}

void
SDL_SetModState(SDL_Keymod modstate)
{
	/* FIXME: do we care? */
	USED(modstate);
}

void
SDL_GetVersion(SDL_version *v)
{
	/* these are arbitrary */
	v->major = 2;
	v->minor = 24;
	v->patch = 1;
}

int
SDL_GetWindowBordersSize(SDL_Window *, int *t, int *l, int *b, int *r)
{
	if(t != nil)
		*t = Borderwidth;
	if(l != nil)
		*l = Borderwidth;
	if(b != nil)
		*b = Borderwidth;
	if(r != nil)
		*r = Borderwidth;
	return 0;
}
