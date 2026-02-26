#include "_sdl.h"

#include <SDL2/SDL_mixer.h>

static int forkerpid = -1;

static int musicvol = 128;
static int musicpaused = 0;

/* FIXME proper chains per channel */
Mix_EffectFunc_t effunc = nil;

static int doneinit = 0;
static int devopen = 0;

enum { Maxchan = 16 };
SDL_AudioSpec channels[Maxchan];
int nchannels = 0;

int
Mix_OpenAudio(int freq, Uint16 format, int nch, int chunk)
{
	SDL_AudioSpec *as;
	int sz;

	if(devopen)
		return 0;

	switch(format){
	case 1:
	case 2:
		sz = 1;
		break;
	case 3:
	case 4:
		sz = 2;
		break;
	default:
		werrstr("unsupported format");
		return -1;
	}

	as = &channels[nchannels++];
	assert(nchannels < Maxchan);
	as->freq = freq;
	as->format = format;
	as->channels = nch;
	as->samples = chunk / sz;
	return 0;
}

char*
Mix_GetError(void)
{
	return "";
}

static void
translate(void *arg, Uint8 *buf, int len)
{
	Mix_EffectFunc_t f;

	f = (Mix_EffectFunc_t)arg;

	f(0, buf, len, nil);
}

int
Mix_RegisterEffect(int chan, Mix_EffectFunc_t f, Mix_EffectDone_t d, void *arg)
{
	SDL_AudioSpec *as;
	int n;

	USED(arg); USED(d);
	as = channels + chan;
	as->userdata = f;
	as->callback = translate;
	if(devopen){
		werrstr("device already open");
		return -1;
	}
	n = SDL_OpenAudioDevice(nil, 0, as, nil, 0);
	assert(n >= 0);
	SDL_PauseAudioDevice(n, 0);
	return 1;
}

Mix_Chunk*
Mix_QuickLoad_RAW(Uint8 *mem, Uint32 len)
{
	USED(mem);
	USED(len);
	return nil;
}

int
Mix_PlayChannel(int chan, Mix_Chunk *chunk, int loops)
{
	USED(chan);
	USED(chunk);
	USED(loops);
	return -1;
}

int
Mix_HaltChannel(int channel)
{
	USED(channel);
	return 0;
}

void
Mix_FreeChunk(Mix_Chunk *c)
{
	USED(c);
}

void
Mix_CloseAudio(void)
{
}

int
Mix_Init(int flags)
{
	if(doneinit)
		return flags;
	doneinit = 1;
	memset(channels, 0, sizeof channels);
	rfork(RFNAMEG);
	if(fork() == 0){
		execl("/bin/audio/mixfs", "mixfs", nil);
		sysfatal("exec: %r\n");
	}
	waitpid();
	return flags;
}

int
Mix_VolumeMusic(int vol)
{
	if(vol < 0)
		vol = 0;
	else if(vol > 128)
		vol = 128;
	musicvol = vol;
	return 0;
}

int
Mix_PlayingMusic(void)
{
	return forkerpid > 0 && !musicpaused;
}

int
Mix_PausedMusic(void)
{
	return musicpaused;
}
void
Mix_ResumeMusic(void)
{
	musicpaused = 0;	
}

void
Mix_PauseMusic(void)
{
	musicpaused = 1;
}

int
Mix_HaltMusic(void)
{
	if(forkerpid < 0)
		return 0;

	postnote(PNGROUP, forkerpid, "halt");
	forkerpid = -1;
	return 0;
}

int
Mix_PlayMusic(Mix_Music *music, int loops)
{
	Waitmsg *wm;
	int n;

	if(forkerpid > 0)
		Mix_HaltMusic();

	if((forkerpid = rfork(RFPROC|RFNOTEG)) != 0)
		return 0;

	n = loops;
	while(loops == -1 || n-- > 0){
		switch(rfork(RFPROC|RFCFDG)){
		case 0:
			execl("/bin/play", "play", music->loc, nil);
			sysfatal("exec: %r");
			break;
		default:
			wm = wait();
			if(wm->msg != nil && wm->msg[0] != '\0'){
				fprint(2, "playmusic: %s\n", wm->msg);
				threadexits(nil);
			}
			free(wm);
			break;
		}
	}
	threadexits(nil);
}

Mix_Music*
Mix_LoadMUS(char *filename)
{
	Mix_Music *m;

	m = calloc(1, sizeof(*m));
	m->loc = strdup(filename);
	m->fd = open(filename, OREAD);
	if(m->fd < 0)
		sysfatal("LoadMUS: %r");
	return m;
}

Mix_Music*
Mix_LoadMUS_RW(SDL_RWops *src, int freesrc)
{
	Mix_Music *m;
	char buf[1024];
	int n;

	m = calloc(1, sizeof(*m));
	m->loc = smprint("/tmp/npesdl.mus.%d", getpid());
	m->fd = create(m->loc, ORDWR|ORCLOSE, 0666);
	while((n = SDL_RWread(src, buf, 1, sizeof buf)) > 0)
		write(m->fd, buf, n);
	seek(m->fd, 0, 0);

	if(freesrc)
		SDL_RWclose(src);
	return m;
}
