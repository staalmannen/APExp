#ifndef _npe_SDL_h_
#define _npe_SDL_h_

#define SDL_MAJOR_VERSION 2
#define SDL_MINOR_VERSION 0
#define SDL_PATCHLEVEL 14

#pragma lib "libnpe_sdl2.a"

#include <npe.h>

typedef u8int Uint8;
typedef u16int Uint16;
typedef u32int Uint32;
typedef u64int Uint64;
typedef s8int Sint8;
typedef s16int Sint16;
typedef s32int Sint32;
typedef s64int Sint64;
typedef enum {SDL_FALSE, SDL_TRUE} SDL_bool;

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
typedef struct SDL_Texture SDL_Texture;
typedef struct SDL_Surface SDL_Surface;
typedef struct SDL_Rect SDL_Rect;
typedef int SDL_BlendMode;
typedef struct SDL_Cursor SDL_Cursor;
typedef struct SDL_PixelFormat SDL_PixelFormat;
typedef struct SDL_Point SDL_Point;
typedef int SDL_RendererFlip;
typedef struct SDL_DisplayMode SDL_DisplayMode;
typedef int SDL_SystemCursor;
typedef union SDL_Color SDL_Color;
typedef struct SDL_Palette SDL_Palette;
typedef struct SDL_RendererInfo SDL_RendererInfo;
typedef struct SDL_mutex SDL_mutex;

#pragma incomplete SDL_Cursor
#pragma incomplete SDL_Renderer
#pragma incomplete SDL_Surface
#pragma incomplete SDL_Texture
#pragma incomplete SDL_Window

#define SDLCALL

#define SDL_zero(x) do{ memset(&(x), 0, sizeof(x)); }while(0)
#define SDL_memset memset
#define SDL_malloc malloc
#define SDL_realloc realloc
#define SDL_calloc calloc
#define SDL_memcpy memcpy
#define SDL_memmove memmove
#define SDL_memcmp memcmp
#define SDL_printf printf
#define SDL_snprintf snprintf
#define SDL_strlen strlen
#define SDL_strlcpy strlcpy
#define SDL_strstr strstr
#define SDL_strncmp strncmp

#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_version.h>
#include <SDL2/SDL_video.h>

void SDL_StopTextInput(void);
SDL_bool SDL_HasSSE(void);
SDL_bool SDL_HasSSE2(void);
int SDL_Init(int);
int SDL_InitSubSystem(int);
int SDL_QuitSubSystem(int);
int SDL_SetRelativeMouseMode(SDL_bool enabled);
int SDL_GetRelativeMouseMode(void);
void SDL_SetWindowIcon(SDL_Window*,SDL_Surface*);
void SDL_SetWindowBordered(SDL_Window*,SDL_bool);
SDL_Keymod SDL_GetModState(void);
int SDL_ShowCursor(int toggle);
Uint64 SDL_GetPerformanceFrequency(void);
Uint64 SDL_GetPerformanceCounter(void);
char *SDL_GetError(void);
char *SDL_GetClipboardText(void);
int SDL_SetClipboardText(char *);
SDL_bool SDL_HasClipboardText(void);
void SDL_RestoreWindow(SDL_Window *window);
void SDL_RaiseWindow(SDL_Window *window);
int SDL_UpdateTexture(SDL_Texture *texture, SDL_Rect *rect, void *pixels, int pitch);
int SDL_RenderClear(SDL_Renderer *renderer);
int SDL_RenderFillRect(SDL_Renderer *r, SDL_Rect *rect);
int SDL_GetWindowDisplayIndex(SDL_Window *window);
void SDL_FreeSurface(SDL_Surface *surface);
Uint32 SDL_GetGlobalMouseState(int *x, int *y);
void SDL_Quit(void);
void SDL_free(void *);
SDL_Cursor *SDL_GetDefaultCursor(void);
void SDL_SetCursor(SDL_Cursor *cursor);
void SDL_FreeCursor(SDL_Cursor *cursor);
SDL_Surface *SDL_CreateRGBSurfaceWithFormat(Uint32 flags, int w, int h, int bpp, Uint32 fmt);
SDL_Surface *SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 rm, Uint32 gm, Uint32 bm, Uint32 am);
SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels, int w, int h, int bpp, int pitch, Uint32 rm, Uint32 gm, Uint32 bm, Uint32 am);
void SDL_GetRGB(Uint32 pixel, const SDL_PixelFormat *format, Uint8 *r, Uint8 *g, Uint8 *b);
Uint32 SDL_MapRGB(SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b);
int SDL_SetColorKey(SDL_Surface *surface, int flag, Uint32 key);
int SDL_SetSurfaceRLE(SDL_Surface *surface, int flag);
int SDL_LockSurface(SDL_Surface *surface);
int SDL_UnlockSurface(SDL_Surface *surface);
int SDL_SetSurfaceBlendMode(SDL_Surface *surface, SDL_BlendMode blendMode);
SDL_Cursor *SDL_CreateColorCursor(SDL_Surface *surface, int hot_x, int hot_y);
void SDL_WarpMouseInWindow(SDL_Window *window, int x, int y);
void SDL_RenderGetScale(SDL_Renderer *renderer, float *scaleX, float *scaleY);
void SDL_GetWindowSize(SDL_Window *window, int *w, int *h);
void SDL_GetWindowPosition(SDL_Window *window, int *x, int *y);
Uint32 SDL_GetMouseState(int *x, int *y);
SDL_bool SDL_IsTextInputActive(void);
void SDL_StartTextInput(void);
void SDL_Delay(Uint32 ms);
void SDL_SetMainReady(void);
int SDL_RenderReadPixels(SDL_Renderer *rend, SDL_Rect *rect, Uint32 fmt, void *pixels, int pitch);
int SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *srcrect, SDL_Rect *dstrect);
void SDL_RenderPresent(SDL_Renderer *renderer);
Uint32 SDL_GetWindowFlags(SDL_Window *window);
int SDL_RenderSetLogicalSize(SDL_Renderer *renderer, int w, int h);
void SDL_SetWindowSize(SDL_Window *window, int w, int h);
int SDL_ShowSimpleMessageBox(Uint32 flags, char *title, char *message, SDL_Window *window);
int SDL_SetWindowFullscreen(SDL_Window *window, Uint32 flags);
void SDL_SetWindowGrab(SDL_Window *window, SDL_bool grabbed);
void SDL_SetWindowPosition(SDL_Window *window, int x, int y);
void SDL_DestroyTexture(SDL_Texture *texture);
void SDL_DestroyRenderer(SDL_Renderer *renderer);
void SDL_DestroyWindow(SDL_Window *window);
int SDL_GetDisplayUsableBounds(int displayIndex, SDL_Rect *rect);
int SDL_GetDesktopDisplayMode(int displayIndex, SDL_DisplayMode *mode);
void SDL_SetWindowTitle(SDL_Window *window, char *title);
int SDL_SetTextureBlendMode(SDL_Texture *texture, SDL_BlendMode blendMode);
SDL_bool SDL_SetHint(char *name, char *value);
SDL_Window *SDL_CreateWindow(char *title, int x, int y, int w, int h, Uint32 flags);
SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags);
int SDL_CreateWindowAndRenderer(int width, int height, Uint32 window_flags, SDL_Window **window, SDL_Renderer **renderer);
int SDL_SetRenderDrawBlendMode(SDL_Renderer *renderer, SDL_BlendMode blendMode);
char *SDL_GetCurrentVideoDriver(void);
SDL_Texture *SDL_CreateTexture(SDL_Renderer *renderer, Uint32 format, int access, int w, int h);
void SDL_EnableScreenSaver(void);
Uint32 SDL_GetTicks(void);
int SDL_GetRendererOutputSize(SDL_Renderer *renderer, int *w, int *h);
void SDL_RenderGetViewport(SDL_Renderer *rebderer, SDL_Rect *rect);
int SDL_SaveBMP(SDL_Surface *s, const char *file);
void SDL_ClearError(void);
int SDL_SetTextureAlphaMod(SDL_Texture *texture, Uint8 alpha);
int SDL_SetTextureColorMod(SDL_Texture *texture, Uint8 r, Uint8 g, Uint8 b);
int SDL_OpenURL(char *url);
SDL_Cursor *SDL_CreateSystemCursor(SDL_SystemCursor id);
SDL_Texture *SDL_CreateTextureFromSurface(SDL_Renderer *r, SDL_Surface *s);
char *SDL_GetBasePath(void);
char *SDL_GetPrefPath(char *org, char *app);
int SDL_SetRenderDrawColor(SDL_Renderer *r, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode *mode);
int SDL_GetNumDisplayModes(int displayIndex);
void SDL_ShowWindow(SDL_Window *w);
int SDL_RenderSetIntegerScale(SDL_Renderer *r, SDL_bool enable);
int SDL_GetNumVideoDisplays(void);
void SDL_SetModState(SDL_Keymod modstate);
SDL_mutex* SDL_CreateMutex(void);
void SDL_DestroyMutex(SDL_mutex*);
int SDL_LockMutex(SDL_mutex*);
int SDL_UnlockMutex(SDL_mutex*);
#define SDL_mutexV(x) SDL_UnlockMutex(x)
#define SDL_mutexP(x) SDL_LockMutex(x)
int SDL_FillRect(SDL_Surface *dst, const SDL_Rect *rect, Uint32 color);
SDL_Palette *SDL_AllocPalette(int ncolors);
int SDL_SetPaletteColors(SDL_Palette *palette, const SDL_Color *colors, int firstcolor, int ncolors);
int SDL_SetSurfacePalette(SDL_Surface *s, SDL_Palette *palette);
int SDL_BlitSurface(SDL_Surface *src, const SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
int SDL_SoftStretch(SDL_Surface *src, const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect);
int SDL_LockTexture(SDL_Texture *texture, const SDL_Rect *rect, void **pixels, int *pitch);
int SDL_UnlockTexture(SDL_Texture *texture);
int SDL_GetWindowBordersSize(SDL_Window *window, int *top, int *left, int *bot, int *right);
 
enum {
	SDL_QUERY = -1,
	SDL_DISABLE,
	SDL_ENABLE,

	SDL_MESSAGEBOX_ERROR = 0,

	SDL_WINDOW_MINIMIZED = 1<<0,
	SDL_WINDOW_FULLSCREEN_DESKTOP = 1<<1,
	SDL_WINDOW_INPUT_FOCUS = 1<<2,
	SDL_WINDOW_ALLOW_HIGHDPI = 1<<3,
	SDL_WINDOW_SHOWN = 1<<4,
	SDL_WINDOW_RESIZABLE = 1<<5,
	SDL_WINDOW_HIDDEN = 1<<6,
	SDL_WINDOW_MAXIMIZED = 1<<7,
	SDL_WINDOW_FULLSCREEN = 1<<8,
	SDL_WINDOW_BORDERLESS = 1<<9,

	SDL_WINDOWPOS_CENTERED = -1,
	SDL_WINDOWPOS_UNDEFINED = -2,

	SDL_INIT_TIMER = 1<<0,
	SDL_INIT_AUDIO = 1<<1,
	SDL_INIT_VIDEO = 1<<2,
	SDL_INIT_JOYSTICK = 0,
	SDL_INIT_GAMECONTROLLER = 0,

	SDL_BLENDMODE_NONE = 0,
	SDL_BLENDMODE_BLEND,

	SDL_FLIP_NONE = 0,
	SDL_FLIP_HORIZONTAL,
	SDL_FLIP_VERTICAL,

	SDL_PIXELFORMAT_ARGB8888 = 0x30128888,
	SDL_PIXELFORMAT_XRGB8888 = 0x16161804,
	SDL_PIXELFORMAT_INDEX8 = 0x13000801,
	SDL_PIXELFORMAT_RGB24 = 0x17101803,
	SDL_PIXELFORMAT_ABGR8888 = 0x16762004,
	SDL_PIXELFORMAT_XBGR8888 = 0x16561804,
	SDL_PIXELFORMAT_BGR24 = 0x17401803,
	SDL_PIXELFORMAT_RGB888 = SDL_PIXELFORMAT_XRGB8888,
	SDL_PIXELFORMAT_BGR888 = SDL_PIXELFORMAT_XBGR8888,

	/* shit no one cares about */
	SDL_TEXTUREACCESS_STREAMING = 0,
	SDL_TEXTUREACCESS_STATIC = 0,
	SDL_TEXTUREACCESS_TARGET = 0,
	SDL_RENDERER_ACCELERATED = 0,
	SDL_RENDERER_PRESENTVSYNC = 0,
	SDL_INIT_NOPARACHUTE = 0,
	SDL_RENDERER_SOFTWARE = 0,
	SDL_SWSURFACE = 0,

	/* FIXME steal from rio and add missing? */
	SDL_SYSTEM_CURSOR_ARROW = 0,
	SDL_SYSTEM_CURSOR_IBEAM,
	SDL_SYSTEM_CURSOR_WAIT,
	SDL_SYSTEM_CURSOR_CROSSHAIR,
	SDL_SYSTEM_CURSOR_WAITARROW,
	SDL_SYSTEM_CURSOR_SIZENWSE,
	SDL_SYSTEM_CURSOR_SIZENESW,
	SDL_SYSTEM_CURSOR_SIZEWE,
	SDL_SYSTEM_CURSOR_SIZENS,

	SDL_ALPHA_OPAQUE = 0xff,
	SDL_ALPHA_TRANSPARENT = 0x00,
};

enum {
	SDL_BUTTON_LEFT = 0,
	SDL_BUTTON_MIDDLE = 1,
	SDL_BUTTON_RIGHT = 2,

	SDL_BUTTON_LMASK = 1<<SDL_BUTTON_LEFT,
	SDL_BUTTON_MMASK = 1<<SDL_BUTTON_MIDDLE,
	SDL_BUTTON_RMASK = 1<<SDL_BUTTON_RIGHT,

	KMOD_NONE = 0,
};


#define SDL_BUTTON(x) (1<<(x))

#define SDL_MUSTLOCK(surface) (SDL_FALSE)

#define SDL_HINT_RENDER_SCALE_QUALITY "SDL_HINT_RENDER_SCALE_QUALITY"
#define SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4 "SDL_WINDOWS_NO_CLOSE_ON_ALT_F4"
#define SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH "SDL_MOUSE_FOCUS_CLICKTHROUGH"
#define SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING "SDL_WINDOWS_DISABLE_THREAD_NAMING"
#define SDL_HINT_RENDER_VSYNC "SDL_RENDER_VSYNC"

struct SDL_Point {
	int x, y;
};

struct SDL_Rect {
	int x, y, w, h;
};

struct SDL_Surface {
	SDL_PixelFormat *format;
	SDL_Rect clip_rect;
	Uint32 flags;
	Uint32 key;
	int keyset;
	int w, h;
	int pitch;
	int n;
	void *i;
	uchar *pixels;
};

struct SDL_DisplayMode {
	int format;
	int w;
	int h;
	int refresh_rate;
};

union SDL_Color {
	struct {
		Uint8 r, g, b, a;
	};
};

struct SDL_Palette {
	int ncolors;
	SDL_Color *colors;
};

struct SDL_PixelFormat {
	SDL_Palette *palette;
	int format;
	int BytesPerPixel;
};

struct SDL_RendererInfo {
	int max_texture_width;
	int max_texture_height;
};

struct SDL_mutex {
	Lock l;
};

typedef enum {
	SDL_HITTEST_NORMAL,
	SDL_HITTEST_DRAGGABLE,
	SDL_HITTEST_RESIZE_TOPLEFT,
	SDL_HITTEST_RESIZE_TOP,
	SDL_HITTEST_RESIZE_TOPRIGHT,
	SDL_HITTEST_RESIZE_RIGHT,
	SDL_HITTEST_RESIZE_BOTTOMRIGHT,
	SDL_HITTEST_RESIZE_BOTTOM,
	SDL_HITTEST_RESIZE_BOTTOMLEFT,
	SDL_HITTEST_RESIZE_LEFT,
} SDL_HitTestResult;

#endif
