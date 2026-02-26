#include "_sdl.h"
#include <bio.h>

typedef struct {
	uchar *memdata;
	int memn;
	int mempos;
} Membuf;

static vlong memsize(struct SDL_RWops *);
static vlong memseek(struct SDL_RWops *, vlong, int);
static size_t memread(struct SDL_RWops *, void *, size_t, size_t);
static size_t memwrite(struct SDL_RWops *, const void *, size_t, size_t);
static int memclose(struct SDL_RWops *);

struct npe_sdl_rwops {
	union {
		Biobuf;
		Membuf;
	};
};

static vlong bsize(struct SDL_RWops *);
static vlong bseek(struct SDL_RWops *, vlong, int);
static size_t bread(struct SDL_RWops *, void *, size_t, size_t);
static size_t bwrite(struct SDL_RWops *, const void *, size_t, size_t);
static int bclose(struct SDL_RWops *);

SDL_RWops *
SDL_RWFromFile(const char *file, const char *m)
{
	SDL_RWops *o;
	int f, mode;

	o = nil;
	mode = -1;
	for(; m != nil && *m; m++){
		if(*m == 'r'){
			if(mode == OWRITE){
badmode:
				werrstr("either read or write supported only");
				return nil;
			}
			mode = OREAD;
		}else if(*m == 'w'){
			if(mode == OREAD)
				goto badmode;
			mode = OWRITE;
		}
	}
	if(mode < 0)
		goto badmode;

	if((f = open(file, mode|OCEXEC)) >= 0 &&
	    (o = calloc(1, sizeof(*o)+sizeof(npe_sdl_rwops))) != nil &&
		Binit((o->p = (void*)(o+1)), f, mode) == 0){
		o->size = bsize;
		o->seek = bseek;
		o->read = bread;
		o->write = bwrite;
		o->close = bclose;
		return o;
	}

	if(f >= 0)
		close(f);
	free(o);

	return nil;
}

SDL_RWops*
SDL_RWFromMem(void *mem, int size)
{
	SDL_RWops *o;
	Membuf *b;

	o = calloc(1, sizeof(*o)+sizeof(npe_sdl_rwops));
	if(o == nil)
		return nil;
	o->p = (void*)(o+1);
	b = (void*)o->p;
	b->memdata = mem;
	b->memn = size;
	b->mempos = 0;


	o->size = memsize;
	o->seek = memseek;
	o->read = memread;
	o->write = memwrite;
	o->close = memclose;
	return o;
}

size_t
SDL_RWread(SDL_RWops *o, void *b, size_t sz, size_t n)
{
	return o->read ? o->read(o, b, sz, n) : 0;
}

size_t
SDL_RWwrite(SDL_RWops *o, const void *b, size_t sz, size_t n)
{
	return o->write ? o->write(o, b, sz, n) : 0;
}

vlong
SDL_RWseek(SDL_RWops *o, vlong off, int whence)
{
	return o->seek ? o->seek(o, off, whence) : -1;
}

vlong
SDL_RWtell(SDL_RWops *o)
{
	return o->seek ? o->seek(o, 0, 1) : -1;
}

vlong
SDL_RWsize(SDL_RWops *o)
{
	return o->size ? o->size(o) : -1;
}

int
SDL_RWclose(SDL_RWops *o)
{
	int r;

	r = o->close ? o->close(o) : 0;
	if(r == 0)
		free(o);

	return r;
}

static vlong
bseek(struct SDL_RWops *o, vlong off, int whence)
{
	return Bseek(o->p, off, whence);
}

static size_t
bread(struct SDL_RWops *o, void *b, size_t sz, size_t n)
{
	uchar *p;
	size_t i;
	vlong x;

	for(i = 0, p = b; i < n; i++, p += sz){
		if((x = Bread(o->p, p, sz)) != sz){
			if(x > 0)
				Bseek(o->p, -x, 1);
			break;
		}
	}

	return i;
}

static size_t
bwrite(struct SDL_RWops *o, const void *b, size_t sz, size_t n)
{
	const uchar *p;
	size_t i;

	for(i = 0, p = b; i < n; i++, p += sz){
		if(Bwrite(o->p, p, sz) != sz) /* FIXME dunno what to do with partial writes */
			break;
	}

	return i;
}

static vlong
bsize(struct SDL_RWops *o)
{
	Dir *s;
	vlong sz;

	sz = -1;
	if((s = dirfstat(Bfildes(o->p))) != nil){
		sz = s->length;
		free(s);
	}

	return sz;
}

static int
bclose(struct SDL_RWops *o)
{
	return Bterm(o->p);
}

static vlong
memseek(struct SDL_RWops *o, vlong off, int whence)
{
	Membuf *b;

	b = (Membuf*)o->p;
	switch(whence){
	case 0:
		b->mempos = off;
		break;
	case 1:
		b->mempos += off;
		break;
	case 2:
		b->mempos = b->memn - 1;
		b->mempos -= off;
		break;
	}
	if(b->mempos < 0)
		b->mempos = 0;

	return b->mempos;
}

static size_t
memread(struct SDL_RWops *o, void *b, size_t sz, size_t n)
{
	Membuf *buf;
	uchar *p, *dot;
	uchar *end;
	size_t i;

	buf = (Membuf*)o->p;
	end = buf->memdata + buf->memn;
	for(i = 0, p = b; i < n; i++, p += sz){
		dot = buf->memdata + buf->mempos;
		if(dot + sz >= end){
			memmove(p, dot, end - dot);
			buf->mempos = buf->memn;
			dot = end;
		}
		if(dot == end)
			return i;

		assert(dot < end);
		memmove(p, dot, sz);
		buf->mempos += sz;
	}

	return i;
}

static size_t
memwrite(struct SDL_RWops *o, const void *b, size_t sz, size_t n)
{
	Membuf *buf;
	const uchar *p;
	size_t i;

	buf = (Membuf*)o->p;
	for(i = 0, p = b; i < n; i++, p += sz){
		memmove(buf->mempos + buf->memdata, p, sz);
		buf->mempos += sz;
	}
	return i;
}

static vlong
memsize(struct SDL_RWops *o)
{
	Membuf *b;
	b = (Membuf*)o->p;

	return b->memn;
}

static int
memclose(struct SDL_RWops *o)
{
	USED(o);
	return 0;
}
