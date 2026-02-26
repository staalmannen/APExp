#include "_sdl.h"

enum {
	Aout = 2,
	Arec,

	Audiosamples = 8192,
};

typedef struct Audiodev Audiodev;

struct Audiodev {
	Lock;
	void (*cb)(void *, Uint8 *, int);
	void *userdata;
	char *name;
	Channel *wait;
	Uint8 *buf;
	int bufsz;
	int paused;
	int fd;
	int pid;
	int pidconv;
	int mode;
};

/* FIXME extra USB audio devices? */
static Audiodev au[4] = {
	[0] = {.fd = -1, .mode = -1},
	[1] = {.fd = -1, .mode = -1},
	[Aout] = {.name = "/dev/audio", .fd = -1, .pid = -1, .mode = OWRITE},
	[Arec] = {.name = "/dev/audio", .fd = -1, .pid = -1, .mode = OREAD},
};

static struct {
	char *spec;
	int ssz; /* samples size */
}fmts[AUDIO_NUM_FORMATS] = {
	[AUDIO_U8] = {"u8", 1},
	[AUDIO_S8] = {"s8", 1},
	[AUDIO_U16LSB] = {"u16", 2},
	[AUDIO_S16LSB] = {"s16", 2},
	[AUDIO_U16MSB] = {"U16", 2},
	[AUDIO_S16MSB] = {"S16", 2},
	[AUDIO_S32LSB] = {"s32", 4},
	[AUDIO_S32MSB] = {"S32", 4},
	[AUDIO_F32LSB] = {"f32", 4},
	[AUDIO_F32MSB] = {"F32", -1}, /* FIXME big endian f32 not supported by pcmconv */
};

int
SDL_GetNumAudioDevices(int iscapture)
{
	/* FIXME look for extra USB devices? */
	USED(iscapture);
	return 1;
}

char *
SDL_GetAudioDeviceName(int index, int iscapture)
{
	/* FIXME look for extra USB devices? */
	USED(index);
	return au[iscapture ? Arec : Aout].name;
}

void
SDL_LockAudioDevice(SDL_AudioDeviceID id)
{
	lock(&au[id]);
}

void
SDL_UnlockAudioDevice(SDL_AudioDeviceID id)
{
	unlock(&au[id]);
}

static void
audiothread(void *p)
{
	Audiodev *a;

	a = p;
	threadsetname("%s (%s)", a->name, a->mode == OREAD ? "out" : "in");

	for(;;){
		if(a->mode == OREAD && readn(a->fd, a->buf, a->bufsz) != a->bufsz)
			break;

		lock(a);
		if(a->mode == OWRITE && a->paused)
			memset(a->buf, 0, a->bufsz);
		else
			a->cb(a->userdata, a->buf, a->bufsz);
		unlock(a);

		if(a->mode == OWRITE && write(a->fd, a->buf, a->bufsz) != a->bufsz)
			break;
	}

	lock(a);
	(a->mode == OWRITE ? write : read)(a->fd, a->buf, 0);
	chanclose(a->wait);
	unlock(a);

	threadexits(nil);
}

void
SDL_PauseAudioDevice(SDL_AudioDeviceID id, SDL_bool pause)
{
	Audiodev *a;

	a = &au[id];
	if(a->paused && !pause){
		if(a->pid < 0)
			a->pid = proccreate(audiothread, a, 4096);
		a->paused = 0;
	}else if(!a->paused && pause){
		a->paused = 1;
	}
}

static int
convspec(SDL_AudioSpec *s, char *spec, int n)
{
	int ssz;

	ssz = -1;
	if(s->format < 0 || s->format >= nelem(fmts))
		werrstr("invalid audio format: #%d", s->format);
	else if(fmts[s->format].ssz < 1)
		werrstr("unsupported audio format: #%d", s->format);
	else if(s->channels < 1)
		werrstr("invalid number of channels: %d", s->channels);
	else if(s->freq < 1)
		werrstr("invalid sampling rate: %d", s->freq);
	else if(snprint(spec, n, "%sc%dr%d", fmts[s->format].spec, s->channels, s->freq) >= n)
		werrstr("audio spec does not fit");
	else
		ssz = fmts[s->format].ssz;

	return ssz;
}

static void
setpipebuf(int f, int sz)
{
	Dir d;

	nulldir(&d);
	d.length = sz;
	dirfwstat(f, &d);
}

SDL_AudioDeviceID
SDL_OpenAudioDevice(char *dev, int rec, SDL_AudioSpec *want, SDL_AudioSpec *have, u32int change)
{
	SDL_AudioDeviceID id;
	int p[2], ssz, fd;
	char spec[16];
	Audiodev *a;

	/* FIXME look for extra USB devices? */
	USED(dev);

	id = rec ? Arec : Aout;
	a = &au[id];

	if(have == nil)
		have = want;
	*have = *want;
	if(have->freq < 44100 && (change & SDL_AUDIO_ALLOW_FREQUENCY_CHANGE) != 0)
		have->freq = 44100;
	if(have->format <= 0 || have->format >= nelem(fmts) || fmts[have->format].ssz < 1 && (change & SDL_AUDIO_ALLOW_FORMAT_CHANGE) != 0)
		have->format = AUDIO_S16;
	if(have->channels < 1 && (change & SDL_AUDIO_ALLOW_CHANNELS_CHANGE) != 0)
		have->channels = 2;
	if(have->samples < 2 || (have->samples & (have->samples-1)) != 0){
		if(change & SDL_AUDIO_ALLOW_SAMPLES_CHANGE)
			have->samples = Audiosamples;
		else{
			werrstr("invalid number of samples: %d", have->samples);
			goto err;
		}
	}

	if((ssz = convspec(have, spec, sizeof(spec))) < 1)
		goto err;

	a->userdata = have->userdata;
	a->cb = have->callback;
	a->wait = chancreate(sizeof(ulong), 0);
	a->bufsz = have->samples * ssz * have->channels;
	a->buf = malloc(a->bufsz);
	if(a->wait == nil || a->buf == nil){
		werrstr("memory");
		goto err;
	}

	a->paused = 1;
	a->pid = -1;
	a->pidconv = -1;
	if(have->freq != 44100 || have->format != AUDIO_S16 || have->channels != 2){
		if((fd = open(a->name, a->mode)) < 0)
			goto err;
		pipe(p);
		setpipebuf(p[0], a->bufsz);
		if((a->pidconv = rfork(RFPROC|RFNOTEG|RFFDG|RFCENVG)) == 0){
			dup(fd, rec ? 0 : 1); close(fd);
			dup(p[0], rec ? 1 : 0); close(p[0]);
			close(p[1]);
			//close(2);
			if(execl("/bin/audio/pcmconv", "pcmconv", rec ? "-o" : "-i", spec, nil) != 0)
				exits("%r");
		}else if(a->pidconv < 0){
			werrstr("pcmconv: %r");
			close(fd);
			goto err;
		}
		a->fd = p[1];
		close(p[0]);
		close(fd);
	}else if(a->fd < 0 && (a->fd = open(a->name, a->mode|OCEXEC)) < 0)
		goto err;

	return id;
err:
	werrstr("SDL_OpenAudioDevice: %r");
	if(a->fd >= 0){
		close(a->fd);
		a->fd = -1;
	}
	free(a->buf);
	a->buf = nil;
	if(a->wait != nil){
		chanfree(a->wait);
		a->wait = nil;
	}

	return 0;
}

void
SDL_CloseAudioDevice(SDL_AudioDeviceID id)
{
	Audiodev *a;
	Waitmsg *w;
	int pid;

	a = &au[id];

	if(a->fd < 0)
		return;

	lock(a);
		close(a->fd);
	unlock(a);

	if(a->pid >= 0)
		recvul(a->wait);
	chanfree(a->wait);

	free(a->buf);
	a->fd = -1;
	a->pid = -1;
again:
	if(a->pidconv >= 0 && (w = wait()) != nil){
		if(w->msg[0])
			fprint(2, "SDL_CloseAudioDevice: %s: %s\n", a->name, w->msg);
		pid = w->pid;
		free(w);
		if(pid != a->pidconv)
			goto again;
	}
}
