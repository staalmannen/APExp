#ifndef _npe_SDL_events_h_
#define _npe_SDL_events_h_

enum {
	SDL_KEYDOWN,
	SDL_KEYUP,
	SDL_JOYAXISMOTION,
	SDL_JOYBUTTONDOWN,
	SDL_JOYBUTTONUP,
	SDL_MOUSEBUTTONDOWN,
	SDL_MOUSEBUTTONUP,
	SDL_MOUSEWHEEL,
	SDL_MOUSEMOTION,
	SDL_QUIT,
	SDL_DROPFILE,
	SDL_TEXTINPUT,
	SDL_WINDOWEVENT,
	SDL_WINDOWEVENT_HIDDEN,
	SDL_WINDOWEVENT_SHOWN,
	SDL_WINDOWEVENT_FOCUS_LOST,
	SDL_WINDOWEVENT_FOCUS_GAINED,
	SDL_WINDOWEVENT_MOVED,
	SDL_WINDOWEVENT_EXPOSED,
	SDL_WINDOWEVENT_SIZE_CHANGED,
	SDL_WINDOWEVENT_RESIZED = SDL_WINDOWEVENT_SIZE_CHANGED, /* FIXME I don't even fucking know... */
	SDL_WINDOWEVENT_MINIMIZED,
	SDL_WINDOWEVENT_MAXIMIZED,
	SDL_WINDOWEVENT_RESTORED,
	SDL_WINDOWEVENT_ENTER,
	SDL_WINDOWEVENT_LEAVE,
	SDL_WINDOWEVENT_CLOSE,
	SDL_JOYBALLMOTION,
	SDL_JOYHATMOTION,

	SDL_PRESSED = SDL_KEYDOWN,
	SDL_RELEASED = SDL_KEYUP,

	SDL_TEXTINPUTEVENT_TEXT_SIZE = UTFmax,

	SDL_ADDEVENT = 0,
	SDL_PEEKEVENT,
	SDL_GETEVENT,

	SDL_HAT_LEFTUP = 0,
	SDL_HAT_LEFT,
	SDL_HAT_LEFTDOWN,
	SDL_HAT_UP,
	SDL_HAT_CENTERED,
	SDL_HAT_DOWN,
	SDL_HAT_RIGHTUP,
	SDL_HAT_RIGHT,
	SDL_HAT_RIGHTDOWN,
};

typedef struct SDL_WindowEvent SDL_WindowEvent;
typedef struct SDL_MouseWheelEvent SDL_MouseWheelEvent;
typedef struct SDL_MouseButtonEvent SDL_MouseButtonEvent;
typedef struct SDL_Keysym SDL_Keysym;
typedef struct SDL_Event SDL_Event;
typedef int SDL_eventaction;
typedef int (*SDL_EventFilter)(void *userdata, SDL_Event *event);

struct SDL_WindowEvent {
	Uint32	type;
	Uint32	timestamp;
	Uint32	windowID;
	Uint8	event;
	Sint32	data1;
	Sint32	data;
};

struct SDL_Keysym {
	SDL_Scancode scancode;
	SDL_Keycode sym;
	Uint16 mod;
};

struct SDL_MouseWheelEvent {
	Uint32	type;
	Uint32	timestamp;
	Uint32	windowID;
	Uint32	which;
	Sint32	x;
	Sint32	y;
	Uint32	direction;
};

struct SDL_MouseButtonEvent {
	Uint32	type;
	Uint32	timestamp;
	Uint32	windowID;
	Uint32	which;
	Uint8	button;
	Uint8	state;
	Uint8	clicks;
	Sint32	x;
	Sint32	y;
};

struct SDL_Event {
	int type;
	SDL_WindowEvent window;
	struct {
		SDL_Keysym keysym;
		int repeat;
		int state;
	}key;
	SDL_MouseButtonEvent button;
	struct {
		int button;
		int state;
	}cbutton;
	struct {
		int button;
	}jbutton;
	struct {
		int value;
		int axis;
	}jaxis;
	struct {
		int xrel;
		int yrel;
	}jball;
	struct {
		int hat;
		int value;
	}jhat;
	struct {
		int x, y;
		int xrel, yrel;
		int state;
	}motion;
	struct {
		char text[SDL_TEXTINPUTEVENT_TEXT_SIZE+1];
	}text;
	SDL_MouseWheelEvent wheel;
	struct {
		char *file;
	}drop;
};

int SDL_EventState(Uint32, int);
int SDL_PollEvent(SDL_Event *event);
int SDL_PushEvent(SDL_Event *event);
int SDL_WaitEvent(SDL_Event *event);
Uint32 SDL_RegisterEvents(int);
int SDL_PeepEvents(SDL_Event *events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType);
Uint32 SDL_GetWindowID(SDL_Window *window);
void SDL_PumpEvents(void);
void SDL_SetEventFilter(SDL_EventFilter filter, void *userdata);
SDL_Scancode SDL_GetScancodeFromKey(SDL_Keycode key);
Uint8* SDL_GetKeyboardState(int *numkeys);
char* SDL_GetKeyName(SDL_Keycode key);
SDL_Keycode SDL_GetKeyFromName(char *name);

#endif
