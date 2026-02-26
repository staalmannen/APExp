#include "_sdl.h"

struct SDL_Thread {
	SDL_ThreadFunction f;
	const char *name;
	void *userdata;
	Channel *wait;
};

static int prio[] = {
	[SDL_THREAD_PRIORITY_LOW] = 5,
	[SDL_THREAD_PRIORITY_NORMAL] = 10,
	[SDL_THREAD_PRIORITY_HIGH] = 13,
	[SDL_THREAD_PRIORITY_TIME_CRITICAL] = 100,
};

static void sdlthread(void *p);

SDL_Thread *
SDL_CreateThreadWithStackSize(SDL_ThreadFunction f, const char *name, size_t stacksz, void *data)
{
	SDL_Thread *t;

	if((t = calloc(1, sizeof(*t))) == nil)
		return nil;

	t->f = f;
	t->name = name;
	t->userdata = data;
	t->wait = chancreate(sizeof(int), 0);

	if(t->wait == nil || proccreate(sdlthread, t, stacksz) < 0){
		if(t->wait != nil)
			chanfree(t->wait);
		free(t);
		t = nil;
	}

	return t;
}

SDL_Thread *
SDL_CreateThread(SDL_ThreadFunction f, char *name, void *data)
{
	return SDL_CreateThreadWithStackSize(f, name, mainstacksize, data);
}

void
SDL_DetachThread(SDL_Thread *t)
{
	if(t != nil)
		chanclose(t->wait);
}

void
SDL_WaitThread(SDL_Thread *t, int *status)
{
	int r;

	if(t != nil){
		recv(t->wait, &r);
		if(status != nil)
			*status = r;
	}
}

void
SDL_SetThreadPriority(int p)
{
	char t[32];
	int f;

	if(p < 0 || p >= nelem(prio))
		return;

	snprint(t, sizeof(t), "/proc/%d/ctl", getpid());
	if((f = open(t, OWRITE)) >= 0){
		fprint(f, "pri %d", prio[p]);
		close(f);
	}
}

static void
sdlthread(void *p)
{
	SDL_Thread *t;
	int res;

	t = p;
	if(t->name != nil)
		threadsetname(t->name);

	res = t->f(t->userdata);
	send(t->wait, &res);
	chanfree(t->wait);
	free(t);

	threadexits(res == 0 ? nil : "error");
}
