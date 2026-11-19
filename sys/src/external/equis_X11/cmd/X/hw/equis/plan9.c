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

#define _LOCK_EXTENSION
#define _QLOCK_EXTENSION
#define _PLAN9_SOURCE
#include <sys/types.h>
#include <lock.h>
#include <qlock.h>
#include <lib9.h>
#include <stdlib.h>
#include <string.h>
#include <bsd.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <utf.h>
#include <fmt.h>
#include <signal.h>
#include <select.h>
#include <sys/time.h>
#include <draw.h>
#include <keyboard.h>
#include "equis.h"

extern void ErrorF(char *, ...);
extern void FatalError(char *, ...);

EquisInfo equisInfo;

void
equisInfoInit(void)
{
    Rectangle r;
    char    buf[256];

    if (initdraw(0, 0, "equis") < 0)
        FatalError("can't open display");

    equisInfo.depth = screen->depth;
    equisInfo.width = Dx(screen->r);
    equisInfo.width -= equisInfo.width%(screen->depth/8);
    equisInfo.height = Dy(screen->r);
    equisInfo.dpi = 100;
    equisInfo.bpl = bytesperline(Rect(0, 0, equisInfo.width, equisInfo.height) , equisInfo.depth);

    equisInfo.fb = malloc(equisInfo.bpl * equisInfo.height);
    if (equisInfo.fb == nil)
        FatalError("can't allocate framebuffer");

    snprint(buf, sizeof buf, "%s/mouse", display->devdir);
    equisInfo.mouseFd = open(buf, O_RDWR | O_NONBLOCK);
    if (equisInfo.mouseFd < 0)
        FatalError("can't open mouse");

    snprint(buf, sizeof buf, "%s/cons", display->devdir);
    equisInfo.keybdFd = open(buf, O_RDONLY | O_NONBLOCK);
    if (equisInfo.keybdFd < 0)
        FatalError("can't open keyboard");

    snprint(buf, sizeof buf, "%s/consctl", display->devdir);
    equisInfo.consctlFd = open(buf, O_WRONLY);
    if (equisInfo.consctlFd < 0)
        FatalError("can't open consctl");
    if (write(equisInfo.consctlFd, "rawon", 5) != 5)
        FatalError("can't set rawon");
}


void
equisRefreshScreen(int x1, int y1, int x2, int y2)
{
    Rectangle r;
    uchar *p;
    int n;

    p = (uchar *)equisInfo.fb+(y1*equisInfo.width+x1)*(equisInfo.depth/8);
    r = rectaddpt(Rect(x1, y1, x2, y2), screen->r.min);
    if (Dx(r) == equisInfo.width) {
        if (loadimage(screen, r, p, equisInfo.bpl * Dy(r)) < 0)
            FatalError("can't load image");
        goto End;
    }
    n = Dx(r)*(equisInfo.depth/8);
    y2 += screen->r.min.y;
    while(r.min.y < y2) {
        r.max.y = r.min.y+1;
        if (loadimage(screen, r, p, n) < 0)
            FatalError("can't load image");
        p += equisInfo.bpl;
        r.min.y++;
    }

End:
    flushimage(display, 1);
}


static void
equisResize(void)
{
    if (getwindow(display, Refnone) < 0)
        FatalError("can't reattach to window");

    draw(screen, screen->r, display->white, nil, ZP);
    equisRefreshScreen(0, 0, equisInfo.width, equisInfo.height);
}


int
equisMouseRead(int *x, int *y, int *b)
{
    char    buf[1+4*12];
    int n;

    if ((n = read(equisInfo.mouseFd, buf, sizeof buf)) <= 0)
        return 0;

    if (n != 1 + 4 * 12)
        FatalError("Bad mouse event");

    if (buf[0] == 'r') {
        equisResize();
        return 0;
    }
    *x = atoi(buf + 1 + 0 * 12) - screen->r.min.x;
    *y = atoi(buf + 1 + 1 * 12) - screen->r.min.y;
    *b = atoi(buf + 1 + 2 * 12);

    return 1;
}


wchar_t
equisKeybdRead(void)
{
    static char s[3];
    static int  n = 0;
    wchar_t rune;

    if (read(equisInfo.keybdFd, s + n, 1) != 1)
        return 0;

    rune = s[0];
    if (n > 0 || (rune & 0x80) != 0x00) {
        if (mbtowc(&rune, s, n + 1) == -1) {
            /* incomplete rune; wait until next char */
            if (++n == 3)
                n = 0;
            return 0;
        }
        n = 0;
    }
    if (rune == Kdel) {
        ErrorF("delete\n");
        raise(SIGINT);
    }
    if (rune == Kdown)
        rune = 0x99;
    else if (rune & KF)
        rune = (rune&~KF) + 0x80;

    return rune;
}


