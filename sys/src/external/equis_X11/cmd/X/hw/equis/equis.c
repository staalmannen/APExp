/*
 * Copyright (c) 2008 Federico G. Benavento <benavento@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <dix-config.h>
#include <X11/X.h>
#define NEED_EVENTS
#include <X11/Xproto.h>
#include <X11/Xos.h>
#include <X11/Xpoll.h>
#define XK_TECHNICA
#define XK_PUBLISHING
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "scrnintstr.h"
#include "servermd.h"
#define PSZ 8
#include "fb.h"
#include "mibstore.h"
#include "colormapst.h"
#include "gcstruct.h"
#include "input.h"
#include "mipointer.h"
#include "micmap.h"
#include "dix.h"
#include "miline.h"
#include "shadow.h"
#include "shadowfb.h"
#include "equis.h"
#include "keymap.h"

static DeviceIntPtr equisMouse;
static DeviceIntPtr equisKeybd;
static int  oldx, oldy, oldbut;

static KeySymsRec keysyms = {
    map,    MIN_KEYCODE,    MAX_KEYCODE,    MAP_WIDTH
};


static CARD8 modmap[MAP_LENGTH];

static PixmapFormatRec formats[] = {
    { 1,    1,  BITMAP_SCANLINE_PAD },
    { 8,    8,  BITMAP_SCANLINE_PAD },
    { 16,   16,     BITMAP_SCANLINE_PAD },
    { 24,   24,     BITMAP_SCANLINE_PAD },
    { 32,   32,     BITMAP_SCANLINE_PAD }
};
#define NUMFORMATS (sizeof(formats)/sizeof((formats)[0]))

#define equisSaveScreen (void *) NoopDDA
#define equisConstrainCursor    (void *) NoopDDA
#define equisDisplayCursor  (void *) NoopDDA
#define equisRealizeCursor  (void *) NoopDDA
#define equisUnrealizeCursor    (void *) NoopDDA
#define equisRecolorCursor  (void *) NoopDDA
#define equisSetCursorPosition  (void *) NoopDDA

void
OsVendorInit(void)
{
    char temp[] = "/tmp/equis.XXXXXX";
    LogInit(mktemp(temp), NULL);
}

void
ddxGiveUp(void)
{
}


void
AbortDDX(void)
{
}


/* we may need to do some weird stuff here in the future */
#if defined(DDXBEFORERESET)
void
ddxBeforeReset(void)
{
}
#endif


void
ddxUseMsg(void)
{
}


void
ddxInitGlobals(void)
{
    whiteRoot = TRUE;
    dispatchExceptionAtReset = FALSE;
}


void
DDXRingBell(int, int, int)
{
}


int
ddxProcessArgument(int argc, char *argv[], int i)
{
    return 0;
}


Bool
LegalModifier(unsigned int k, DeviceIntPtr pDev)
{
    return modmap[k] != 0;
}


void
ProcessInputEvents(void)
{
    mieqProcessInputEvents();
}


#define e    ev.u.u
#define ek    ev.u.keyButtonPointer
static void
equisSendKeybdEvent(int k, int t)
{
    xEvent ev;

    memset(&ev, 0, sizeof(xEvent));
    e.type = t;
    e.detail = k + MIN_KEYCODE;
    ek.time = GetTimeInMillis();
    mieqEnqueue(equisKeybd, &ev);
}


static void
equisSendMouseEvent(int x, int y, int b, int t)
{
    xEvent ev;

    memset(&ev, 0, sizeof(xEvent));
    e.type = t;
    e.detail = b;
    ek.rootX = x;
    ek.rootY = y;
    ek.time = GetTimeInMillis();
    mieqEnqueue(equisMouse, &ev);
}
#undef ek
#undef e


static int  
equisKeybdHandle(void)
{
    unsigned char   k, m;
    int c;

    c = equisKeybdRead();
    if (c == 0 || c > sizeof(rune2keycode))
        return 0;

    k = rune2keycode[c].key;
    if (k == 0)
        return 0;

    m = rune2keycode[c].mod;
    if (m) 
        equisSendKeybdEvent(m, KeyPress);

    equisSendKeybdEvent(k, KeyPress);
    equisSendKeybdEvent(k, KeyRelease);
    if (m) 
        equisSendKeybdEvent(m, KeyRelease);

    return 1;
}


static int  
equisMouseHandle(void)
{
    int x, y, b, but, t;

    if (!equisMouseRead(&x, &y, &but))
        return 0;

    t = b = 0;
    if (x != oldx || y != oldy) {
        t = MotionNotify;
        oldx = x, oldy = y;
    }
    if (but != oldbut) {
        b = oldbut ^ but;
        t = ButtonPress;
        if (oldbut & b)
            t = ButtonRelease;
        if (b == 4)
            b = 3;
        if (but & (8 | 16)) {
            if (b & 8)
                b = 4;
            else
                b = 5;
            equisSendMouseEvent(x, y, b, ButtonPress);
            equisSendMouseEvent(x, y, b, ButtonRelease);
            return 1;
        }
    }
    equisSendMouseEvent(x, y, b, t);
    oldbut = but;

    return 1;
}


extern fd_set EnabledDevices, LastSelectMask;

static void
equisWakeupHandler(int index, pointer blockData, unsigned long result, pointer pReadmask)
{

    fd_set fs;

    if (result <= 0)
        return;

    XFD_ANDSET(&fs, &LastSelectMask, &EnabledDevices);
    if (!XFD_ANYSET(&fs))
        return;

    while (equisMouseHandle())
        ;
    while (equisKeybdHandle())
        ;
}


static void
equisInitModmap(void)
{
    KeySym * ks;
    int i;

    for (i = 0; i < MAP_LENGTH; i++)
        modmap[i] = NoSymbol;

    for (i = MIN_KEYCODE, ks = map; i < (MIN_KEYCODE + NUM_KEYCODES); i++, ks += MAP_WIDTH)
        switch (*ks) {
        case XK_Shift_L:
        case XK_Shift_R:
            modmap[i] = ShiftMask;
            break;
        case XK_Control_L:
        case XK_Control_R:
            modmap[i] = ControlMask;
            break;
        case XK_Alt_L:
        case XK_Alt_R:
            modmap[i] = Mod1Mask;
            break;
        }
}


static int  
equisKeybdProc(DeviceIntPtr pDevice, int what)
{
    DevicePtr pDev = (DevicePtr)pDevice;

    switch (what) {
    case DEVICE_INIT:
        equisInitModmap();
        if (!InitKeyboardDeviceStruct(pDev, &keysyms, modmap, 
            (BellProcPtr)NoopDDA, (KbdCtrlProcPtr)NoopDDA))
            FatalError("can't init keyboard");
        break;

    case DEVICE_ON:
        pDev->on = TRUE;
        AddEnabledDevice(equisInfo.keybdFd);
        break;

    case DEVICE_CLOSE:
    case DEVICE_OFF:
        pDev->on = FALSE;
        RemoveEnabledDevice(equisInfo.keybdFd);
        break;
    }
    return Success;
}


static int  
equisMouseProc(DeviceIntPtr pDevice, int what)
{
    static unsigned char    map[] = {0, 1, 2, 3, 4, 5};
    DevicePtr pDev = (DevicePtr)pDevice;

    switch (what) {
    case DEVICE_INIT:
        InitPointerDeviceStruct(pDev, map, 3, GetMotionHistory,
            (PtrCtrlProcPtr)NoopDDA, GetMotionHistorySize(), 2 );
        break;

    case DEVICE_ON:
        pDev->on = TRUE;
        AddEnabledDevice(equisInfo.mouseFd);
        break;

    case DEVICE_CLOSE:
    case DEVICE_OFF:
        pDev->on = FALSE;
        RemoveEnabledDevice(equisInfo.mouseFd);
        break;
    }
    return Success;
}


void
InitInput(int argc, char *argv[])
{
    equisMouse = AddInputDevice(equisMouseProc, TRUE);
    RegisterPointerDevice(equisMouse);
    equisKeybd = AddInputDevice(equisKeybdProc, TRUE);
    RegisterKeyboardDevice(equisKeybd);
    mieqInit();
}


static void
equisCursorLimits(ScreenPtr, CursorPtr, BoxPtr hot, BoxPtr topleft)
{
    *topleft = *hot;
}


#ifdef SHADOWFB
static void
equisRefreshArea(ScrnInfoPtr, int nbox, BoxPtr pbox)
{
    int x1, y1, x2, y2;

    if(nbox <= 0)
        return;

    x1 = y1 = 100000;
    x2 = y2 = -100000;
    while(nbox--) {
        if(x1 > pbox->x1)
            x1 = pbox->x1;
        if(y1 > pbox->y1)
            y1 = pbox->y1;
        if(x2 < pbox->x2)
            x2 = pbox->x2;
        if(y2 < pbox->y2)
            y2 = pbox->y2;
        pbox++;
    }
    equisRefreshScreen(x1, y1, x2, y2);
}


#else


static void
equisShadowUpdate(ScreenPtr pScreen, shadowBufPtr pBuf)
{
    BoxPtr pbox;

    pbox = REGION_EXTENTS(pScreen, &pBuf->damage);
    equisRefreshScreen(pbox->x1, pbox->y1, pbox->x2, pbox->y2);
}


/* callback dance... */
static CreateScreenResourcesProcPtr equisCreateResourcesPtr;

static Bool
equisCreateResources(ScreenPtr pScreen)
{
    Bool ret;

    pScreen->CreateScreenResources = equisCreateResourcesPtr;
    if (pScreen->CreateScreenResources)
        ret = pScreen->CreateScreenResources(pScreen);

    equisCreateResourcesPtr = pScreen->CreateScreenResources;
    pScreen->CreateScreenResources = equisCreateResourcesPtr;
    if (ret == FALSE)
        return FALSE;

    shadowRemove(pScreen, pScreen->GetScreenPixmap(pScreen));
    if (!shadowAdd(pScreen, pScreen->GetScreenPixmap(pScreen), equisShadowUpdate, NULL, SHADOW_ROTATE_0, 0))
        return FALSE;

    return ret;
}


#endif



static Bool
equisScreenInit(int index, ScreenPtr pScreen, int argc, char *argv[])
{
    int v, i;
    unsigned long   r, g, b;
    static int  first = 1;

    assert(index == 0);
    if (first) {
        equisInfoInit();
        first = 0;
    }

    for (i = 0; i < NUMFORMATS; i++)
        fbSetVisualTypes(formats[i].depth, 0, 8);

    switch (equisInfo.depth) {
    case 16:
        r = 0xF800, g = 0x07E0, b = 0x001F;
        v = 1 << TrueColor;
        break;
    case 24:
    case 32:
        r = 0xFF0000, g = 0x00FF00, b = 0x0000FF;
        v = 1 << TrueColor;
        break;
    default:
        r = g = b = 0;
        v = 1 << PseudoColor;
    }
    if (!fbSetVisualTypesAndMasks(equisInfo.depth, v, 8, r, g, b))
        return FALSE;

    if (monitorResolution)
        equisInfo.dpi = monitorResolution;
    if (!fbScreenInit(pScreen, equisInfo.fb, equisInfo.width, equisInfo.height,
        equisInfo.dpi, equisInfo.dpi, equisInfo.width, equisInfo.depth))
        return FALSE;

    pScreen->mmWidth = equisInfo.width * 25.4 / equisInfo.dpi;
    pScreen->mmHeight = equisInfo.height * 25.4 / equisInfo.dpi;

    /* cursor */
    pScreen->ConstrainCursor = equisConstrainCursor;
    pScreen->CursorLimits = equisCursorLimits;
    pScreen->DisplayCursor = equisDisplayCursor;
    pScreen->RealizeCursor = equisRealizeCursor;
    pScreen->UnrealizeCursor = equisUnrealizeCursor;
    pScreen->RecolorCursor = equisRecolorCursor;
    pScreen->SetCursorPosition = equisSetCursorPosition;

    pScreen->SaveScreen = equisSaveScreen;
    pScreen->WakeupHandler = equisWakeupHandler;

#ifdef RENDER
    if (!fbPictureInit(pScreen, 0, 0))
        return FALSE;
#endif

    miInitializeBackingStore(pScreen);

#ifdef SHADOWFB
   if (!ShadowFBInit(pScreen, equisRefreshArea))
        return FALSE;
#else
   if (!shadowSetup(pScreen))
        return FALSE;

    equisCreateResourcesPtr = pScreen->CreateScreenResources;
    pScreen->CreateScreenResources = equisCreateResources;
#endif

    if (!fbCreateDefColormap(pScreen))
        return FALSE;

    return TRUE;
}


void
InitOutput(ScreenInfo *screenInfo, int argc, char *argv[])
{
    int i;

    screenInfo->imageByteOrder = IMAGE_BYTE_ORDER;
    screenInfo->bitmapScanlineUnit = BITMAP_SCANLINE_UNIT;
    screenInfo->bitmapScanlinePad = BITMAP_SCANLINE_PAD;
    screenInfo->bitmapBitOrder = BITMAP_BIT_ORDER;
    screenInfo->numPixmapFormats = NUMFORMATS;
    for (i = 0; i < NUMFORMATS; i++)
        screenInfo->formats[i] = formats[i];
    if (AddScreen(equisScreenInit, argc, argv) < 0)
        FatalError("InitOutput: can't addscreen");
}

