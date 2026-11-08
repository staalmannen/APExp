#include "_sdl.h"

enum {
	/* FIXME missing plumber→dropfile */
	Ckey,
	Ckeytype,
	Cmouse,
	Cresize,
	Cevent,
	Numchan,

	Rdown = 0,
	Rup,
	Rrepeat,
};

static int kmod;
static Rune rune;
static Keyboardctl kctl;
static int quitreq;
static SDL_Event evt;

static Alt salt[Numchan+1] = {
	[Ckey] = { nil, &rune, CHANRCV },
	[Ckeytype] = { nil, nil, CHANNOP },
	[Cmouse] = { nil, &npe_sdl.m, CHANRCV },
	[Cresize] = { nil, nil, CHANRCV },
	[Cevent] = { nil, &evt, CHANRCV },
	[Numchan] = { nil, nil, CHANNOBLK },
};

static void kbdproc(void *);
static void mouseproc(void *);

int
npe_sdl_init_input(void)
{
	if((npe_sdl.mctl = initmouse(nil, screen)) == nil)
		return -1;

	salt[Ckey].c = chancreate(sizeof(Rune), 20);
	salt[Ckeytype].c = chancreate(sizeof(int), 20);
	salt[Cmouse].c = chancreate(sizeof(Mouse), 20);
	salt[Cresize].c = npe_sdl.mctl->resizec;
	salt[Cevent].c = chancreate(sizeof(SDL_Event), 20);
	kctl.c = salt[Ckey].c; /* for enter() */

	if(salt[Ckey].c == nil || salt[Ckeytype].c == nil || salt[Cmouse].c == nil)
		return -1;

	if(proccreate(kbdproc, nil, 4096) < 0 || proccreate(mouseproc, nil, 4096) < 0)
		return -1;

	return 0;
}

Uint32
SDL_GetWindowID(SDL_Window *win)
{
	USED(win);
	return 1;
}

SDL_Keymod
SDL_GetModState(void)
{
	return kmod;
}

int
SDL_EventState(Uint32, int)
{
	return 0;
}

Uint32
SDL_RegisterEvents(int n)
{
	static Uint32 userevent = 0x1000;
	Uint32 u;

	if(userevent+n > 0x2000 || n < 0)
		u = (Uint32)-1;
	else
		u = userevent += n;

	return u;
}

int
SDL_PushEvent(SDL_Event *event)
{
	return send(salt[Cevent].c, event) > 0 ? 1 : -1;
}

int
SDL_QuitRequested(void)
{
	return quitreq;
}

struct {
	SDL_EventFilter f;
	void *aux;
} filter = {
	nil,
	nil,
};

void
SDL_SetEventFilter(SDL_EventFilter f, void *userdata)
{
	filter.f = f;
	filter.aux = userdata;
}

void
SDL_PumpEvents(void)
{
	/* FIXME does it matter? */
}

#define ISTEXT(r) ((r) >= 0x20 && ((r) < KF || (r) >= KF+0x1000))

int
SDL_PollEvent(SDL_Event *e)
{
	int t, down;

	if(e == nil) /* FIXME need to buffer the event so it won't get lost */
		return 0;

	switch(alt(salt)){
	case Ckey:
		memset(e, 0, sizeof(*e));
		recv(salt[Ckeytype].c, &t);
		if(npe_sdl.textinput && ISTEXT(rune)){
			if(t == Rup)
				break;
			e->type = SDL_TEXTINPUT;
			e->text.text[runetochar(e->text.text, &rune)] = 0;
			goto Filter;
		}else if((npe_sdl.hints & Altf4noclose) == 0 && (kmod & KMOD_LALT) != 0 && rune == (KF|4)){
			e->type = SDL_QUIT;
			quitreq = 1;
			goto Filter;
		}else{
			e->type = (t == Rup) ? SDL_KEYUP : SDL_KEYDOWN;
			e->key.repeat = t == Rrepeat;
			e->key.keysym.scancode = SDL_GetScancodeFromKey(rune);
			if(rune == '\n')
				rune = SDLK_RETURN;
			e->key.keysym.sym = rune;
			e->key.state = e->type;
			goto Filter;
		}
		break;

	case Cmouse:
		if(screen == nil)
			break;

		if(eqpt(npe_sdl.m.xy, Pt(-1, -1))){
			npe_sdl.m.xy = npe_sdl.center;
			npe_sdl.om.xy = npe_sdl.center;
			return 0; /* swallow */
		}

		memset(e, 0, sizeof(*e));
		e->motion.x = (npe_sdl.m.xy.x - screen->r.min.x) * npe_sdl.scale;
		e->motion.y = (npe_sdl.m.xy.y - screen->r.min.y) * npe_sdl.scale;
		e->motion.xrel = (npe_sdl.m.xy.x - npe_sdl.om.xy.x) * npe_sdl.scale;
		e->motion.yrel = (npe_sdl.m.xy.y - npe_sdl.om.xy.y) * npe_sdl.scale;

		if(!eqpt(npe_sdl.m.xy, npe_sdl.om.xy)){
			npe_sdl.mredraw = 1;
			if(npe_sdl.m.buttons == npe_sdl.om.buttons){
				e->type = SDL_MOUSEMOTION;
				e->motion.state = npe_sdl.m.buttons;
				goto Filter;
			}
		}
		if(npe_sdl.m.buttons == npe_sdl.om.buttons)
			break;
		/* FIXME there is a lot of hope for multiple buttons to never change its state at the same time */
		if((down = (npe_sdl.m.buttons & 1)) != (npe_sdl.om.buttons & 1)){ /* left */
			e->type = down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
			e->button.button = SDL_BUTTON_LEFT;
			npe_sdl.om.buttons = (npe_sdl.om.buttons & ~1) | (npe_sdl.m.buttons & 1);
			goto Filter;
		}
		if((down = (npe_sdl.m.buttons & 2)) != (npe_sdl.om.buttons & 2)){ /* middle */
			e->type = down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
			e->button.button = SDL_BUTTON_MIDDLE;
			npe_sdl.om.buttons = (npe_sdl.om.buttons & ~2) | (npe_sdl.m.buttons & 2);
			goto Filter;
		}
		if((down = (npe_sdl.m.buttons & 4)) != (npe_sdl.om.buttons & 4)){ /* right */
			e->type = down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
			e->button.button = SDL_BUTTON_RIGHT;
			npe_sdl.om.buttons = (npe_sdl.om.buttons & ~4) | (npe_sdl.m.buttons & 4);
			goto Filter;
		}
		if(npe_sdl.m.buttons & (8|16)){
			e->type = SDL_MOUSEWHEEL;
			e->wheel.x = 0;
			e->wheel.y = (npe_sdl.m.buttons & 8) ? 1 : -1;
			goto Filter;
		}
		break;

	case Cresize:
		memset(e, 0, sizeof(*e));
		npe_sdl.fullredraw = 1;
		while(getwindow(display, Refnone) != 1)
			;
		e->type = SDL_WINDOWEVENT;
		e->window.event = SDL_WINDOWEVENT_EXPOSED;
		e->window.windowID = 1; //TODO more then one?
		goto Filter;

	case Cevent:
		memcpy(e, &evt, sizeof(*e));
		goto Filter;
	}

	return 0;

Filter:
	if(filter.f != nil && filter.f(filter.aux, e) == 0)
		return 0;
	return 1;
}

int
SDL_WaitEvent(SDL_Event *e)
{
	int r;
	SDL_Event ee;

	salt[Numchan].op = CHANEND;
	if(e == nil){
		r = SDL_PollEvent(&ee);
		SDL_PushEvent(&ee);
	} else
		r = SDL_PollEvent(e);
	salt[Numchan].op = CHANNOBLK;

	return r;
}

SDL_Scancode
SDL_GetScancodeFromKey(SDL_Keycode r)
{
	if(r >= 'a' && r <= 'z')
		return r - 'a' + SDL_SCANCODE_A;
	if(r >= '1' && r <= '9')
		return r - '1' + SDL_SCANCODE_1;
	if(r == '0')  return SDL_SCANCODE_0;
	if(r == '\n') return SDL_SCANCODE_RETURN;
	if(r == Kesc) return SDL_SCANCODE_ESCAPE;
	if(r == Kbs)  return SDL_SCANCODE_BACKSPACE;
	if(r == '\t') return SDL_SCANCODE_TAB;
	if(r == ' ')  return SDL_SCANCODE_SPACE;
	if(r == '-')  return SDL_SCANCODE_MINUS;
	if(r == '=')  return SDL_SCANCODE_EQUALS;
	if(r == '[')  return SDL_SCANCODE_LEFTBRACKET;
	if(r == ']')  return SDL_SCANCODE_RIGHTBRACKET;
	if(r == '\\') return SDL_SCANCODE_BACKSLASH;
	if(r == ';')  return SDL_SCANCODE_SEMICOLON;
	if(r == '\'') return SDL_SCANCODE_APOSTROPHE;
	if(r == '/')  return SDL_SCANCODE_SLASH;

	if(r == Kright) return SDL_SCANCODE_RIGHT;
	if(r == Kleft) return SDL_SCANCODE_LEFT;
	if(r == Kdown) return SDL_SCANCODE_DOWN;
	if(r == Kup) return SDL_SCANCODE_UP;
	if(r == Kins) return SDL_SCANCODE_INSERT;
	if(r == Khome) return SDL_SCANCODE_HOME;
	if(r == Kpgup) return SDL_SCANCODE_PAGEUP;
	if(r == Kdel) return SDL_SCANCODE_DELETE;
	if(r == Kend) return SDL_SCANCODE_END;
	if(r == Kpgdown) return SDL_SCANCODE_PAGEDOWN;
	if(r == Kctl) return SDL_SCANCODE_LCTRL;
	if(r == Kshift) return SDL_SCANCODE_LSHIFT;
	if(r == Kalt) return SDL_SCANCODE_LALT;
	if(r == Kmod4) return SDL_SCANCODE_LGUI;
	if(r == Kaltgr) return SDL_SCANCODE_RALT;

	if(r >= (KF|1) && r <= (KF|12)) return SDL_SCANCODE_F1 + r - (KF|1);

/* FIXME
	SDL_SCANCODE_PRINTSCREEN = 0x46,
	SDL_SCANCODE_SCROLLLOCK,
	SDL_SCANCODE_NUMLOCKCLEAR,
	SDL_SCANCODE_KP_DIVIDE,
	SDL_SCANCODE_KP_MULTIPLY,
	SDL_SCANCODE_KP_MINUS,
	SDL_SCANCODE_KP_PLUS,
	SDL_SCANCODE_KP_ENTER,
	SDL_SCANCODE_KP_1,
	SDL_SCANCODE_KP_2,
	SDL_SCANCODE_KP_3,
	SDL_SCANCODE_KP_4,
	SDL_SCANCODE_KP_5,
	SDL_SCANCODE_KP_6,
	SDL_SCANCODE_KP_7,
	SDL_SCANCODE_KP_8,
	SDL_SCANCODE_KP_9,
	SDL_SCANCODE_KP_0,
	SDL_SCANCODE_KP_PERIOD,
	SDL_SCANCODE_NONUSBACKSLASH,
	SDL_SCANCODE_NONUSHASH,
*/
	/* FIXME there are some missing */

	if(r == L'`' || r == L'´') /* FIXME this is most likely wrong */
		return SDL_SCANCODE_GRAVE;

	return r;
}

static Uint8 kbdstate[SDL_NUM_SCANCODES];

Uint8*
SDL_GetKeyboardState(int *numkeys)
{
	if(numkeys != nil)
		*numkeys = SDL_NUM_SCANCODES;
	return kbdstate;
}

char*
SDL_GetKeyName(SDL_Keycode key)
{
	/* upstream quirk: return value is valid only until next call */
	static char res[64];

	res[0] = res[1] = '\0';
	if(key >= '0' && key <= '9' || key == '-' || key == '=' || key == '\'')
		res[0] = key;
	else if(key == '[' || key == ']' || key == '\\' || key == ';' || key == '/')
		res[0] = key;
	else if(key >= 'a' && key <= 'z')
		res[0] = toupper(key);
	else if(key >= (KF|1) && key <= (KF|12))
		snprint(res, sizeof(res), "F%d", key - KF);
	else if(key == '\n')
		return "Return";
	else if(key == Kesc)
		return "Escape";
	else if(key == Kbs)
		return "Backspace";
	else if(key == '\t')
		return "Tab";
	else if(key == ' ')
		return "Space";
	else if(key == Kright)
		return "Right";
	else if(key == Kleft)
		return "Left";
	else if(key == Kup)
		return "Up";
	else if(key == Kdown)
		return "Down";
	else if(key == Kins)
		return "Insert";
	else if(key == Khome)
		return "Home";
	else if(key == Kpgup)
		return "PageUp";
	else if(key == Kpgdown)
		return "PageDown";
	else if(key == Kdel)
		return "Delete";
	else if(key == Kend)
		return "End";
	else if(key == Kalt)
		return "Left Alt";
	else if(key == Kctl)
		return "Left Ctrl";
	else if(key == Kmod4)
		return "Left GUI";
	else if(key == Kaltgr)
		return "Right Alt";
	else if(key == Kshift)
		return "Left Shift";

	return res;
}

SDL_Keycode
SDL_GetKeyFromName(char *name)
{
	char *e;
	long p;

	if(strcmp(name, "Return") == 0) return '\n';
	if(strcmp(name, "Escape") == 0) return Kesc;
	if(strcmp(name, "Backspace") == 0) return Kbs;
	if(strcmp(name, "Tab") == 0) return '\t';
	if(strcmp(name, "Space") == 0) return ' ';
	if(strcmp(name, "Right") == 0) return Kright;
	if(strcmp(name, "Left") == 0) return Kleft;
	if(strcmp(name, "Up") == 0) return Kup;
	if(strcmp(name, "Down") == 0) return Kdown;
	if(strcmp(name, "Insert") == 0) return Kins;
	if(strcmp(name, "Home") == 0) return Khome;
	if(strcmp(name, "PageUp") == 0) return Kpgup;
	if(strcmp(name, "PageDown") == 0) return Kpgdown;
	if(strcmp(name, "Delete") == 0) return Kdel;
	if(strcmp(name, "End") == 0) return Kend;
	if(strcmp(name, "Left Alt") == 0) return Kalt;
	if(strcmp(name, "Left Ctrl") == 0) return Kctl;
	if(strcmp(name, "Left GUI") == 0) return Kmod4;
	if(strcmp(name, "Right Alt") == 0) return Kaltgr;
	if(strcmp(name, "Left Shift") == 0) return Kshift;
	if(name[0] == 'F' && name[1] != '\0'){
		p = strtol(name+1, &e, 10);
		if(e == name + 1 || p < 1 || p > 12)
			return SDLK_UNKNOWN;
		return KF | p;
	}
	if(name[0] >= '0' && name[0] <= '9')
		return name[0];
	if(name[0] >= 'A' && name[0] <= 'Z')
		return tolower(name[0]);
	if(name[0] >= 'a' && name[0] <= 'z')
		return name[0];
	if(name[0] == '-' || name[0] == '=' || name[0] == '\'')
		return name[0];
	if(name[0] == '[' || name[0] == ']' || name[0] == '\\' || name[0] == ';' || name[0] == '/')
		return name[0];
	return SDLK_UNKNOWN;
}

static void
kbdproc(void *)
{
	char buf[128], buf2[128], *s;
	int kfd, n, kbin, t;
	Rune r, scan, o;

	threadsetname("kbdproc");
	if((kfd = open("/dev/kbd", OREAD|OCEXEC)) < 0)
		sysfatal("/dev/kbd: %r");
	kbin = open("/dev/kbin", OWRITE|OCEXEC);

	buf2[0] = 0;
	buf2[1] = 0;
	buf[0] = 0;
	kmod = 0;
	for(;;){
		if(buf[0] != 0){
			n = strlen(buf)+1;
			memmove(buf, buf+n, sizeof(buf)-n);
		}
		if(buf[0] == 0){
			n = read(kfd, buf, sizeof(buf)-1);
			if(n <= 0)
				break;
			buf[n-1] = 0;
			buf[n] = 0;
		}

		switch(buf[0]){
		case 'c':
			if(chartorune(&r, buf+1) > 0 && r != Runeerror){
				if(ISTEXT(r))
					o = r;
				send(salt[Ckey].c, &o);
				send(salt[Ckeytype].c, &t);
				t = Rrepeat;
			}
		default:
			continue;

		case 'k':
			s = buf+1;
			memset(kbdstate, 0, sizeof(kbdstate));
			while(*s){
				s += chartorune(&r, s);
				scan = SDL_GetScancodeFromKey(r);
				if(scan < nelem(kbdstate))
					kbdstate[scan] = 1;
				if(utfrune(buf2+1, r) == nil){
					t = Rdown;
					if(r == Kalt){
						/* magic trick: write Alt scancode to disable the "compose" mode */
						/* FIXME: does this work in both native AND drawterm? */
						write(kbin, "\x46", 1);
						kmod |= KMOD_LALT;
					}else if (r == Kshift)
						kmod |= KMOD_LSHIFT;
					else if(r == Kctl)
						kmod |= KMOD_LCTRL;
					else if(r == Kaltgr)
						kmod |= KMOD_RALT;
					else if(r == Kmod4)
						kmod |= KMOD_LGUI;
					else{
						o = npe_sdl.textinput ? r : tolowerrune(r);
						continue;
					}
					o = r;
					send(salt[Ckey].c, &r);
					send(salt[Ckeytype].c, &t);
					t = Rrepeat;
				}
			}
			break;

		case 'K':
			s = buf2+1;
			memset(kbdstate, 0, sizeof(kbdstate));
			while(*s){
				s += chartorune(&r, s);
				scan = SDL_GetScancodeFromKey(r);
				if(scan < nelem(kbdstate))
					kbdstate[scan] = 1;
				if(utfrune(buf+1, r) == nil){
					if(r == Kalt)
						kmod &= ~KMOD_LALT;
					else if(r == Kshift)
						kmod &= ~KMOD_LSHIFT;
					else if(r == Kctl)
						kmod &= ~KMOD_LCTRL;

					t = Rup;
					send(salt[Ckey].c, &r);
					send(salt[Ckeytype].c, &t);
				}
			}
			break;
		}
		strcpy(buf2, buf);
	}

	threadexits(nil);
}

static void
mouseproc(void *)
{
	Mouse m;
	for(;;){
		recv(npe_sdl.mctl->c, &m);
		if(npe_sdl.mgrab == SDL_TRUE){
			if(!ptinrect(m.xy, npe_sdl.grabout)){
				moveto(npe_sdl.mctl, npe_sdl.center);
				m.xy = Pt(-1,-1);
			}
		}
		send(salt[Cmouse].c, &m);
	}
}
