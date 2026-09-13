
/*
 * bltText.c --
 *
 *	This module implements multi-line, rotate-able text for the BLT toolkit.
 *
 * Copyright 1993-1998 Lucent Technologies, Inc.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and warranty
 * disclaimer appear in supporting documentation, and that the names
 * of Lucent Technologies any of their entities not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * Lucent Technologies disclaims all warranties with regard to this
 * software, including all implied warranties of merchantability and
 * fitness.  In no event shall Lucent Technologies be liable for any
 * special, indirect or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether in
 * an action of contract, negligence or other tortuous action, arising
 * out of or in connection with the use or performance of this
 * software.
 */

#include "bltInt.h"
#include <X11/Xutil.h>

#define WINDEBUG	0


#define ROTATE_0	0
#define ROTATE_90	1
#define ROTATE_180	2
#define ROTATE_270	3

static Tcl_HashTable bitmapGCTable;
static int initialized;

static GC GetBitmapGC _ANSI_ARGS_((Tk_Window tkwin));

static void
DrawTextSegments(display, drawable, gc, x, y, layoutPtr)
    Display *display;
    Drawable drawable;
    GC gc;
    register int x, y;		/* Origin of text */
    TextLayout *layoutPtr;
{
    register TextSegment *segPtr = layoutPtr->segArr;
    register int i;

    for (i = 0; i < layoutPtr->nSegments; i++, segPtr++) {
#if HAVE_UTF
	Tk_DrawChars(display, drawable, gc, layoutPtr->font, segPtr->text,
	    segPtr->count, x + segPtr->x, y + segPtr->y);
#else
	XDrawString(display, drawable, gc, x + segPtr->x, y + segPtr->y,
	    segPtr->text, segPtr->count);
#endif /*HAVE_UTF*/
    }
}

/*
 * -----------------------------------------------------------------
 *
 * Blt_GetTextLayout --
 *
 *	Get the extents of a possibly multiple-lined text string.
 *
 * Results:
 *	Returns via *widthPtr* and *heightPtr* the dimensions of
 *	the text string.
 *
 * -----------------------------------------------------------------
 */
TextLayout *
Blt_GetTextLayout(string, stylePtr)
    char string[];
    TextStyle *stylePtr;
{
    int maxHeight, maxWidth;
    int count;			/* Count # of characters on each line */
    int nSegments;
    int width;			/* Running dimensions of the text */
    TextSegment *segPtr;
    TextLayout *layoutPtr;
    int lineHeight;
    int size;
    register char *p;
    register int i;
    Tk_FontMetrics fontMetrics;

    Tk_GetFontMetrics(stylePtr->font, &fontMetrics);
    lineHeight = fontMetrics.linespace + stylePtr->leader +
	stylePtr->shadow.offset;
    nSegments = 0;
    for (p = string; *p != '\0'; p++) {
	if (*p == '\n') {
	    nSegments++;
	}
    }
    if (*(p - 1) != '\n') {
	nSegments++;
    }
    size = sizeof(TextLayout) + (sizeof(TextSegment) * (nSegments - 1));
    layoutPtr = (TextLayout *)calloc(1, size);
    layoutPtr->nSegments = nSegments;
    layoutPtr->font = stylePtr->font;
    nSegments = count = 0;
    width = maxWidth = 0;
    maxHeight = stylePtr->padTop;
    segPtr = layoutPtr->segArr;
    for (p = string; *p != '\0'; p++) {
	if (*p == '\n') {
	    if (count > 0) {
		width = Tk_TextWidth(stylePtr->font, string, count) +
		    stylePtr->shadow.offset;
		if (width > maxWidth) {
		    maxWidth = width;
		}
	    }
	    segPtr->width = width;
	    segPtr->count = count;
	    segPtr->y = maxHeight + fontMetrics.ascent;
	    segPtr->text = string;
	    segPtr++;
	    nSegments++;
	    maxHeight += lineHeight;
	    string = p + 1;	/* Start the string on the next line */
	    count = 0;		/* Reset to indicate the start of a new line */
	    continue;
	}
	count++;
    }
    if (nSegments < layoutPtr->nSegments) {
	width = Tk_TextWidth(stylePtr->font, string, count) +
	    stylePtr->shadow.offset;
	if (width > maxWidth) {
	    maxWidth = width;
	}
	segPtr->width = width;
	segPtr->count = count;
	segPtr->y = maxHeight + fontMetrics.ascent;
	segPtr->text = string;
	maxHeight += lineHeight;
	nSegments++;
    }
    maxHeight += stylePtr->padBottom;
    maxWidth += PADDING(stylePtr->padX);
    segPtr = layoutPtr->segArr;
    for (i = 0; i < nSegments; i++, segPtr++) {
	switch (stylePtr->justify) {
	default:
	case TK_JUSTIFY_LEFT:
	    /* No offset for left justified text strings */
	    segPtr->x = stylePtr->padLeft;
	    break;
	case TK_JUSTIFY_RIGHT:
	    segPtr->x = (maxWidth - segPtr->width) - stylePtr->padRight;
	    break;
	case TK_JUSTIFY_CENTER:
	    segPtr->x = (maxWidth - segPtr->width) / 2;
	    break;
	}
    }
    layoutPtr->width = maxWidth;
    layoutPtr->height = maxHeight - stylePtr->leader;
    return layoutPtr;
}

/*
 * -----------------------------------------------------------------
 *
 * Blt_GetTextExtents --
 *
 *	Get the extents of a possibly multiple-lined text string.
 *
 * Results:
 *	Returns via *widthPtr* and *heightPtr* the dimensions of
 *	the text string.
 *
 * -----------------------------------------------------------------
 */
void
Blt_GetTextExtents(stylePtr, string, widthPtr, heightPtr)
    TextStyle *stylePtr;
    char string[];
    int *widthPtr, *heightPtr;
{
    int count;			/* Count # of characters on each line */
    int width, height;
    int w, lineHeight;
    register char *p;
    Tk_FontMetrics fontMetrics;

    if (string == NULL) {
	return;			/* NULL string? */
    }
    Tk_GetFontMetrics(stylePtr->font, &fontMetrics);
    lineHeight = fontMetrics.linespace + stylePtr->leader +
	stylePtr->shadow.offset;
    count = 0;
    width = height = 0;
    for (p = string; *p != '\0'; p++) {
	if (*p == '\n') {
	    if (count > 0) {
		w = Tk_TextWidth(stylePtr->font, string, count) +
		    stylePtr->shadow.offset;
		if (w > width) {
		    width = w;
		}
	    }
	    height += lineHeight;
	    string = p + 1;	/* Start the string on the next line */
	    count = 0;		/* Reset to indicate the start of a new line */
	    continue;
	}
	count++;
    }
    if ((count > 0) && (*(p - 1) != '\n')) {
	height += lineHeight;
	w = Tk_TextWidth(stylePtr->font, string, count) +
	    stylePtr->shadow.offset;
	if (w > width) {
	    width = w;
	}
    }
    *widthPtr = width + PADDING(stylePtr->padX);
    *heightPtr = height + PADDING(stylePtr->padY);
}

/*
 * -----------------------------------------------------------------
 *
 * Blt_GetBoundingBox
 *
 *	Computes the dimensions of the bounding box surrounding a
 *	rectangle rotated about its center.  If pointArr isn't NULL,
 *	the coordinates of the rotated rectangle are also returned.
 *
 *	The dimensions are determined by rotating the rectangle, and
 *	doubling the maximum x-coordinate and y-coordinate.
 *
 *		w = 2 * maxX,  h = 2 * maxY
 *
 *	Since the rectangle is centered at 0,0, the coordinates of
 *	the bounding box are (-w/2,-h/2 w/2,-h/2, w/2,h/2 -w/2,h/2).
 *
 *  		0 ------- 1
 *  		|         |
 *  		|    x    |
 *  		|         |
 *  		3 ------- 2
 *
 * Results:
 *	The width and height of the bounding box containing the
 *	rotated rectangle are returned.
 *
 * -----------------------------------------------------------------
 */
void
Blt_GetBoundingBox(width, height, theta, rotWidthPtr, rotHeightPtr, pointArr)
    int width, height;		/* Unrotated region */
    double theta;		/* Rotation of box */
    int *rotWidthPtr, *rotHeightPtr;	/* (out) Bounding box region */
    XPoint *pointArr;		/* (out) Points of the rotated box */
{
    register int i;
    double sinTheta, cosTheta;
    double xMax, yMax;
    register double x, y;
    Point2D corner[4];

    theta = FMOD(theta, 360.0);
    if (FMOD(theta, (double)90.0) == 0.0) {
	int ll, ur, ul, lr;
	int rotWidth, rotHeight;
	int quadrant;

	/* Handle right-angle rotations specifically */

	quadrant = (int)(theta / 90.0);
	switch (quadrant) {
	case ROTATE_270:	/* 270 degrees */
	    ul = 3, ur = 0, lr = 1, ll = 2;
	    rotWidth = height;
	    rotHeight = width;
	    break;
	case ROTATE_90:	/* 90 degrees */
	    ul = 1, ur = 2, lr = 3, ll = 0;
	    rotWidth = height;
	    rotHeight = width;
	    break;
	case ROTATE_180:	/* 180 degrees */
	    ul = 2, ur = 3, lr = 0, ll = 1;
	    rotWidth = width;
	    rotHeight = height;
	    break;
	default:
	case ROTATE_0:		/* 0 degrees */
	    ul = 0, ur = 1, lr = 2, ll = 3;
	    rotWidth = width;
	    rotHeight = height;
	    break;
	}
	if (pointArr != NULL) {
	    int sx, sy;

	    x = (double)rotWidth *0.5;
	    y = (double)rotHeight *0.5;
	    sx = ROUND(x);
	    sy = ROUND(y);
	    pointArr[ll].x = pointArr[ul].x = -sx;
	    pointArr[ur].y = pointArr[ul].y = -sy;
	    pointArr[lr].x = pointArr[ur].x = sx;
	    pointArr[ll].y = pointArr[lr].y = sy;
	}
	*rotWidthPtr = rotWidth;
	*rotHeightPtr = rotHeight;
	return;
    }
    /* Set the four corners of the rectangle whose center is the origin */

    corner[1].x = corner[2].x = (double)width *0.5;
    corner[0].x = corner[3].x = -corner[1].x;
    corner[2].y = corner[3].y = (double)height *0.5;
    corner[0].y = corner[1].y = -corner[2].y;

    theta = (-theta / 180.0) * M_PI;
    sinTheta = sin(theta), cosTheta = cos(theta);
    xMax = yMax = 0.0;

    /* Rotate the four corners and find the maximum X and Y coordinates */

    for (i = 0; i < 4; i++) {
	x = (corner[i].x * cosTheta) - (corner[i].y * sinTheta);
	y = (corner[i].x * sinTheta) + (corner[i].y * cosTheta);
	if (x > xMax) {
	    xMax = x;
	}
	if (y > yMax) {
	    yMax = y;
	}
	if (pointArr != NULL) {
	    pointArr[i].x = ROUND(x);
	    pointArr[i].y = ROUND(y);
	}
    }

    /*
     * By symmetry, the width and height of the bounding box are
     * twice the maximum x and y coordinates.
     */
    *rotWidthPtr = (int)((xMax + xMax) + 0.5);
    *rotHeightPtr = (int)((yMax + yMax) + 0.5);
}

/*
 * -----------------------------------------------------------------
 *
 * Blt_TranslateAnchor --
 *
 * 	Translate the coordinates of a given bounding box based
 *	upon the anchor specified.  The anchor indicates where
 *	the given xy position is in relation to the bounding box.
 *
 *  		nw --- n --- ne
 *  		|            |
 *  		w   center   e
 *  		|            |
 *  		sw --- s --- se
 *
 * 	The coordinates returned are translated to the origin of the
 * 	bounding box (suitable for giving to XCopyArea, XCopyPlane, etc.)
 *
 * Results:
 *	The translated coordinates of the bounding box are returned.
 *
 * -----------------------------------------------------------------
 */
void
Blt_TranslateAnchor(x, y, width, height, anchor, transXPtr, transYPtr)
    int x, y;			/* Window coordinates of anchor */
    int width, height;		/* Extents of the bounding box */
    Tk_Anchor anchor;		/* Direction of the anchor */
    int *transXPtr, *transYPtr;
{
    switch (anchor) {
    case TK_ANCHOR_NW:		/* Upper left corner */
	break;
    case TK_ANCHOR_W:		/* Left center */
	y -= (height / 2);
	break;
    case TK_ANCHOR_SW:		/* Lower left corner */
	y -= height;
	break;
    case TK_ANCHOR_N:		/* Top center */
	x -= (width / 2);
	break;
    case TK_ANCHOR_CENTER:	/* Center */
	x -= (width / 2);
	y -= (height / 2);
	break;
    case TK_ANCHOR_S:		/* Bottom center */
	x -= (width / 2);
	y -= height;
	break;
    case TK_ANCHOR_NE:		/* Upper right corner */
	x -= width;
	break;
    case TK_ANCHOR_E:		/* Right center */
	x -= width;
	y -= (height / 2);
	break;
    case TK_ANCHOR_SE:		/* Lower right corner */
	x -= width;
	y -= height;
	break;
    }
    *transXPtr = x;
    *transYPtr = y;
}

#ifdef	WIN32
/*
 * -----------------------------------------------------------------
 *
 * Blt_RotateBitmap --
 *
 *	Creates a new bitmap containing the rotated image of the given
 *	bitmap.  We also need a special GC of depth 1, so that we do
 *	not need to rotate more than one plane of the bitmap.
 *
 * Results:
 *	Returns a new bitmap containing the rotated image.
 *
 * -----------------------------------------------------------------
 */
Pixmap
Blt_RotateBitmap(tkwin, srcBitmap, srcWidth, srcHeight, theta,
    destWidthPtr, destHeightPtr)
    Tk_Window tkwin;
    Pixmap srcBitmap;		/* Source bitmap to be rotated */
    int srcWidth, srcHeight;	/* Width and height of the source bitmap */
    double theta;		/* Right angle rotation to perform */
    int *destWidthPtr, *destHeightPtr;
{
    Display *display;		/* X display */
    Window root;		/* Root window drawable */
    Pixmap destBitmap;
    int destWidth, destHeight;
    HDC srcDC, destDC;
    TkWinDCState srcState, destState;
    register int x, y;		/* Destination bitmap coordinates */
    register int sx, sy;	/* Source bitmap coordinates */
    unsigned long pixel;
    TkWinDrawable *drawPtr;
    BITMAPINFO *bmPtr;
    int size;
    unsigned char *srcBits, *destBits;
    int srcBytesPerRow, destBytesPerRow;

    display = Tk_Display(tkwin);
    root = RootWindow(Tk_Display(tkwin), Tk_ScreenNumber(tkwin));
    Blt_GetBoundingBox(srcWidth, srcHeight, theta, &destWidth, &destHeight,
	(XPoint *)NULL);
    destBitmap = Tk_GetPixmap(display, root, destWidth, destHeight, 1);
    if (destBitmap == None) {
	return None;		/* Can't allocate pixmap. */
    }
    srcDC = TkWinGetDrawableDC(display, srcBitmap, &srcState);
    drawPtr = (TkWinDrawable *) srcBitmap;
    destDC = TkWinGetDrawableDC(display, destBitmap, &destState);

    size = sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 2;
    bmPtr = (BITMAPINFO *) calloc(1, size);
    bmPtr->bmiColors[0].rgbBlue = bmPtr->bmiColors[0].rgbGreen =
	bmPtr->bmiColors[0].rgbRed = 0;
    bmPtr->bmiColors[1].rgbBlue = bmPtr->bmiColors[1].rgbGreen =
	bmPtr->bmiColors[1].rgbRed = 0xFF;
    bmPtr->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmPtr->bmiHeader.biPlanes = 1;
    bmPtr->bmiHeader.biBitCount = 1;
    bmPtr->bmiHeader.biCompression = BI_RGB;
    bmPtr->bmiHeader.biWidth = srcWidth;
    bmPtr->bmiHeader.biHeight = srcHeight;
    srcBytesPerRow = ((srcWidth + 31) & ~31) / 8;
    srcBits = (unsigned char *)malloc(srcHeight * srcBytesPerRow);
    if (!GetDIBits(destDC, drawPtr->bitmap.handle, 0, srcHeight,
	    (LPVOID) srcBits, bmPtr, DIB_RGB_COLORS)) {
#ifdef notdef
	PurifyPrintf("can't setDIBits: %s\n", Blt_LastError());
#endif
	goto error;
    }
    bmPtr->bmiHeader.biWidth = destWidth;
    bmPtr->bmiHeader.biHeight = destHeight;
    destBytesPerRow = ((destWidth + 31) & ~31) / 8;
    destBits = (unsigned char *)calloc(destHeight, destBytesPerRow);

#define GetBit(x, y) \
    srcBits[(srcBytesPerRow * y) + (x / 8)] & (0x80 >> (x % 8))
#define SetBit(x, y) \
    destBits[(destBytesPerRow * y) + (x / 8)] |= (0x80 >> (x % 8))

    theta = FMOD(theta, 360.0);
    if (FMOD(theta, (double)90.0) == 0.0) {
	int quadrant;

	/* Handle right-angle rotations specifically */

	quadrant = (int)(theta / 90.0);
	switch (quadrant) {
	case ROTATE_90:	/* 90 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    sx = y, sy = destWidth - x - 1;
		    pixel = GetBit(sx, sy);
		    if (pixel) {
			SetBit(x, y);
		    }
		}
	    }
	    break;

	case ROTATE_0:		/* 0 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    sx = destWidth - x - 1, sy = destHeight - y - 1;
		    pixel = GetBit(sx, sy);
		    if (pixel) {
			SetBit(x, y);
		    }
		}
	    }
	    break;

	case ROTATE_270:	/* 270 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    sx = destHeight - y - 1, sy = x;
		    pixel = GetBit(sx, sy);
		    if (pixel) {
			SetBit(x, y);
		    }
		}
	    }
	    break;

	case ROTATE_180:	/* 180 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    pixel = GetBit(x, y);
		    if (pixel) {
			SetBit(x, y);
		    }
		}
	    }
	    break;

	default:
	    /* The calling routine should never let this happen. */
	    break;
	}
    } else {
	double radians, sinTheta, cosTheta;
	double srcCX, srcCY;	/* Center of source rectangle */
	double destCX, destCY;	/* Center of destination rectangle */
	double tx, ty;
	double rx, ry;		/* Angle of rotation for x and y coordinates */

	radians = (theta / 180.0) * M_PI;
	sinTheta = sin(-radians), cosTheta = cos(-radians);

	/*
	 * Coordinates of the centers of the source and destination rectangles
	 */
	srcCX = srcWidth * 0.5;
	srcCY = srcHeight * 0.5;
	destCX = destWidth * 0.5;
	destCY = destHeight * 0.5;

	/* Rotate each pixel of dest image, placing results in source image */

	for (x = 0; x < destWidth; x++) {
	    for (y = 0; y < destHeight; y++) {

		/* Translate origin to center of destination image */
		tx = x - destCX;
		ty = y - destCY;

		/* Rotate the coordinates about the origin */
		rx = (tx * cosTheta) - (ty * sinTheta);
		ry = (tx * sinTheta) + (ty * cosTheta);

		/* Translate back to the center of the source image */
		rx += srcCX;
		ry += srcCY;

		sx = ROUND(rx);
		sy = ROUND(ry);

		/*
		 * Verify the coordinates, since the destination image can be
		 * bigger than the source
		 */

		if ((sx >= srcWidth) || (sx < 0) || (sy >= srcHeight) ||
		    (sy < 0)) {
		    continue;
		}
		pixel = GetBit(sx, sy);
		if (pixel) {
		    SetBit(x, y);
		}
	    }
	}
    }
    drawPtr = (TkWinDrawable *) destBitmap;
    if (!SetDIBits(destDC, drawPtr->bitmap.handle, 0, destHeight,
	    (LPVOID) destBits, bmPtr, DIB_RGB_COLORS)) {
#if WINDEBUG
	PurifyPrintf("can't setDIBits: %s\n", Blt_LastError());
#endif
    }
  error:
    free((char *)bmPtr);
    free((char *)destBits);
    free((char *)srcBits);

    TkWinReleaseDrawableDC(srcBitmap, srcDC, &srcState);
    TkWinReleaseDrawableDC(destBitmap, destDC, &destState);

    *destWidthPtr = destWidth;
    *destHeightPtr = destHeight;
    return destBitmap;
}

#else
/*
 * -----------------------------------------------------------------
 *
 * Blt_RotateBitmap --
 *
 *	Creates a new bitmap containing the rotated image of the given
 *	bitmap.  We also need a special GC of depth 1, so that we do
 *	not need to rotate more than one plane of the bitmap.
 *
 * Results:
 *	Returns a new bitmap containing the rotated image.
 *
 * -----------------------------------------------------------------
 */
Pixmap
Blt_RotateBitmap(tkwin, srcBitmap, srcWidth, srcHeight, theta,
    destWidthPtr, destHeightPtr)
    Tk_Window tkwin;
    Pixmap srcBitmap;		/* Source bitmap to be rotated */
    int srcWidth, srcHeight;	/* Width and height of the source bitmap */
    double theta;		/* Right angle rotation to perform */
    int *destWidthPtr, *destHeightPtr;
{
    Display *display;		/* X display */
    Window root;		/* Root window drawable */
    Pixmap destBitmap;
    int destWidth, destHeight;
    XImage *src, *dest;
    register int x, y;		/* Destination bitmap coordinates */
    register int sx, sy;	/* Source bitmap coordinates */
    unsigned long pixel;
    GC bitmapGC;

    display = Tk_Display(tkwin);
    root = RootWindow(Tk_Display(tkwin), Tk_ScreenNumber(tkwin));

    /* Create a bitmap and image big enough to contain the rotated text */
    Blt_GetBoundingBox(srcWidth, srcHeight, theta, &destWidth, &destHeight,
	(XPoint *)NULL);
    destBitmap = Tk_GetPixmap(display, root, destWidth, destHeight, 1);
    bitmapGC = GetBitmapGC(tkwin);
    XSetForeground(display, bitmapGC, 0x0);
    XFillRectangle(display, destBitmap, bitmapGC, 0, 0, destWidth, destHeight);

    src = XGetImage(display, srcBitmap, 0, 0, srcWidth, srcHeight, 1, ZPixmap);
    dest = XGetImage(display, destBitmap, 0, 0, destWidth, destHeight, 1,
	ZPixmap);
    theta = FMOD(theta, 360.0);
    if (FMOD(theta, (double)90.0) == 0.0) {
	int quadrant;

	/* Handle right-angle rotations specifically */

	quadrant = (int)(theta / 90.0);
	switch (quadrant) {
	case ROTATE_270:	/* 270 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    sx = y, sy = destWidth - x - 1;
		    pixel = XGetPixel(src, sx, sy);
		    if (pixel) {
			XPutPixel(dest, x, y, pixel);
		    }
		}
	    }
	    break;

	case ROTATE_180:	/* 180 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    sx = destWidth - x - 1, sy = destHeight - y - 1;
		    pixel = XGetPixel(src, sx, sy);
		    if (pixel) {
			XPutPixel(dest, x, y, pixel);
		    }
		}
	    }
	    break;

	case ROTATE_90:		/* 90 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    sx = destHeight - y - 1, sy = x;
		    pixel = XGetPixel(src, sx, sy);
		    if (pixel) {
			XPutPixel(dest, x, y, pixel);
		    }
		}
	    }
	    break;

	case ROTATE_0:		/* 0 degrees */
	    for (x = 0; x < destWidth; x++) {
		for (y = 0; y < destHeight; y++) {
		    pixel = XGetPixel(src, x, y);
		    if (pixel) {
			XPutPixel(dest, x, y, pixel);
		    }
		}
	    }
	    break;

	default:
	    /* The calling routine should never let this happen. */
	    break;
	}
    } else {
	double radians, sinTheta, cosTheta;
	double srcCX, srcCY;	/* Offset from the center of
				 * the source rectangle. */
	double destCX, destCY;	/* Offset to the center of the destination
				 * rectangle. */
	double tx, ty;		/* Translated coordinates from center */
	double rx, ry;		/* Angle of rotation for x and y coordinates */

	radians = (theta / 180.0) * M_PI;
	sinTheta = sin(radians), cosTheta = cos(radians);

	/*
	 * Coordinates of the centers of the source and destination rectangles
	 */
	srcCX = srcWidth * 0.5;
	srcCY = srcHeight * 0.5;
	destCX = destWidth * 0.5;
	destCY = destHeight * 0.5;

	/* Rotate each pixel of dest image, placing results in source image */

	for (x = 0; x < destWidth; x++) {
	    for (y = 0; y < destHeight; y++) {

		/* Translate origin to center of destination image */
		tx = x - destCX;
		ty = y - destCY;

		/* Rotate the coordinates about the origin */
		rx = (tx * cosTheta) - (ty * sinTheta);
		ry = (tx * sinTheta) + (ty * cosTheta);

		/* Translate back to the center of the source image */
		rx += srcCX;
		ry += srcCY;

		sx = ROUND(rx);
		sy = ROUND(ry);

		/*
		 * Verify the coordinates, since the destination image can be
		 * bigger than the source
		 */

		if ((sx >= srcWidth) || (sx < 0) || (sy >= srcHeight) ||
		    (sy < 0)) {
		    continue;
		}
		pixel = XGetPixel(src, sx, sy);
		if (pixel) {
		    XPutPixel(dest, x, y, pixel);
		}
	    }
	}
    }
    /* Write the rotated image into the destination bitmap */
    XPutImage(display, destBitmap, bitmapGC, dest, 0, 0, 0, 0, destWidth,
	destHeight);

    /* Clean up temporary resources used */
    XDestroyImage(src), XDestroyImage(dest);
    *destWidthPtr = destWidth;
    *destHeightPtr = destHeight;
    return destBitmap;
}

#endif /* WIN32 */

/*
 * -----------------------------------------------------------------
 *
 * Blt_CreateTextBitmap --
 *
 *	Draw a bitmap, using the the given window coordinates
 *	as an anchor for the text bounding box.
 *
 * Results:
 *	Returns the bitmap representing the text string.
 *
 * Side Effects:
 *	Bitmap is drawn using the given font and GC in the
 *	drawable at the given coordinates, anchor, and rotation.
 *
 * -----------------------------------------------------------------
 */
Pixmap
Blt_CreateTextBitmap(tkwin, layoutPtr, stylePtr, bmWidthPtr, bmHeightPtr)
    Tk_Window tkwin;
    TextLayout *layoutPtr;	/* Text string to draw */
    TextStyle *stylePtr;	/* Text attributes: rotation, color, font,
				 * linespacing, justification, etc. */
    int *bmWidthPtr;
    int *bmHeightPtr;		/* Extents of rotated text string */
{
    int width, height;
    Pixmap bitmap;
    Display *display;
    Window root;
    GC bitmapGC;
#ifdef WIN32
    HDC src;
    TkWinDCState state;
#endif
    display = Tk_Display(tkwin);

    width = layoutPtr->width + 2;
    height = layoutPtr->height + 2;

    /* Create a temporary bitmap to contain the text string */
    root = RootWindow(Tk_Display(tkwin), Tk_ScreenNumber(tkwin));
    bitmap = Tk_GetPixmap(display, root, width, height, 1);
    assert(bitmap != None);
    if (bitmap == None) {
	return None;		/* Can't allocate pixmap. */
    }
    /* Clear the pixmap and draw the text string into it */
    bitmapGC = GetBitmapGC(tkwin);
#ifdef WIN32
    src = TkWinGetDrawableDC(display, bitmap, &state);
    PatBlt(src, 0, 0, width, height, WHITENESS);
    TkWinReleaseDrawableDC(bitmap, src, &state);
#else
    XSetForeground(display, bitmapGC, 0);
    XFillRectangle(display, bitmap, bitmapGC, 0, 0, width, height);
#endif /* WIN32 */

    XSetFont(display, bitmapGC, Tk_FontId(stylePtr->font));
    XSetForeground(display, bitmapGC, 1);
    DrawTextSegments(display, bitmap, bitmapGC, 0, 0, layoutPtr);
#ifdef WIN32
    /*
     * Under Win32 when drawing into a bitmap, the bits are
     * reversed. Which is why we are inverting the bitmap here.
     */
    src = TkWinGetDrawableDC(display, bitmap, &state);
    PatBlt(src, 0, 0, layoutPtr->width, layoutPtr->height, DSTINVERT);
    TkWinReleaseDrawableDC(bitmap, src, &state);
#endif
    if (stylePtr->theta != 0.0) {
	Pixmap rotBitmap;

	/* Replace the text pixmap with a rotated one */

	rotBitmap = Blt_RotateBitmap(tkwin, bitmap, layoutPtr->width,
	    layoutPtr->height, stylePtr->theta, bmWidthPtr, bmHeightPtr);
	assert(rotBitmap);
	if (rotBitmap != None) {
	    Tk_FreePixmap(display, bitmap);
	    return rotBitmap;
	}
    }
    *bmWidthPtr = layoutPtr->width, *bmHeightPtr = layoutPtr->height;
    return bitmap;
}

#ifdef WIN32
/*
 * -----------------------------------------------------------------------
 *
 * Blt_ScaleBitmapRegion --
 *
 *	Creates a new scaled bitmap from another bitmap. The new bitmap
 *	is bounded by a specified region. Only this portion of the bitmap
 *	is scaled from the original bitmap.
 *
 *	By bounding scaling to a region we can generate a new bitmap
 *	which is no bigger than the specified viewport.
 *
 * Results:
 *	The new scaled bitmap is returned.
 *
 * Side Effects:
 *	A new pixmap is allocated. The caller must release this.
 *
 * -----------------------------------------------------------------------
 */
Pixmap
Blt_ScaleBitmapRegion(tkwin, srcBitmap, srcWidth, srcHeight,
    destWidth, destHeight, regionPtr)
    Tk_Window tkwin;
    Pixmap srcBitmap;
    int srcWidth, srcHeight, destWidth, destHeight;
    ImageRegion *regionPtr;
{
    TkWinDCState srcState, destState;
    HDC src, dest;
    Pixmap destBitmap;
    double xScale, yScale;
    register int sx, sy;	/* Source bitmap coordinates */
    Window root;
    Display *display;

    /* Create a new bitmap the size of the region and clear it */

    display = Tk_Display(tkwin);
    root = RootWindow(Tk_Display(tkwin), Tk_ScreenNumber(tkwin));
    destBitmap = Tk_GetPixmap(display, root, regionPtr->width,
	regionPtr->height, 1);
    if (destBitmap == None) {
	return None;
    }
    /* Compute scaling factors from destination to source bitmaps */
    xScale = (double)srcWidth / (double)destWidth;
    yScale = (double)srcHeight / (double)destHeight;

    src = TkWinGetDrawableDC(display, srcBitmap, &srcState);
    dest = TkWinGetDrawableDC(display, destBitmap, &destState);

    sx = ROUND(regionPtr->x * xScale);
    sy = ROUND(regionPtr->y * yScale);
    srcWidth = ROUND(regionPtr->width * xScale);
    srcHeight = ROUND(regionPtr->height * yScale);

    StretchBlt(dest, 0, 0, destWidth, destHeight, src, sx, sy,
	srcWidth, srcHeight, SRCCOPY);

    TkWinReleaseDrawableDC(srcBitmap, src, &srcState);
    TkWinReleaseDrawableDC(destBitmap, dest, &destState);
    return destBitmap;
}

#else
/*
 * -----------------------------------------------------------------------
 *
 * Blt_ScaleBitmapRegion --
 *
 *	Creates a new scaled bitmap from another bitmap. The new bitmap
 *	is bounded by a specified region. Only this portion of the bitmap
 *	is scaled from the original bitmap.
 *
 *	By bounding scaling to a region we can generate a new bitmap
 *	which is no bigger than the specified viewport.
 *
 * Results:
 *	The new scaled bitmap is returned.
 *
 * Side Effects:
 *	A new pixmap is allocated. The caller must release this.
 *
 * -----------------------------------------------------------------------
 */
Pixmap
Blt_ScaleBitmapRegion(tkwin, srcBitmap, srcWidth, srcHeight,
    destWidth, destHeight, regionPtr)
    Tk_Window tkwin;
    Pixmap srcBitmap;
    int srcWidth, srcHeight, destWidth, destHeight;
    ImageRegion *regionPtr;
{
    Display *display;
    Window root;
    XImage *src, *dest;
    Pixmap destBitmap;
    GC bitmapGC;
    double xScale, yScale;
    register int x, y;		/* Destination bitmap coordinates */
    register int sx, sy;	/* Source bitmap coordinates */
    unsigned long pixel;
    double tmp;

    /* Create a new bitmap the size of the region and clear it */

    display = Tk_Display(tkwin);
    root = RootWindow(Tk_Display(tkwin), Tk_ScreenNumber(tkwin));
    destBitmap = Tk_GetPixmap(display, root, regionPtr->width,
	regionPtr->height, 1);
    bitmapGC = GetBitmapGC(tkwin);
    XSetForeground(display, bitmapGC, 0x0);
    XFillRectangle(display, destBitmap, bitmapGC, 0, 0, regionPtr->width,
	regionPtr->height);

    src = XGetImage(display, srcBitmap, 0, 0, srcWidth, srcHeight, 1, ZPixmap);
    dest = XGetImage(display, destBitmap, 0, 0, regionPtr->width,
	regionPtr->height, 1, ZPixmap);

    /*
     * Scale each pixel of destination image from results of source
     * image. Verify the coordinates, since the destination image can
     * be bigger than the source
     */
    xScale = (double)srcWidth / (double)destWidth;
    yScale = (double)srcHeight / (double)destHeight;

    for (y = 0; y < regionPtr->height; y++) {
	tmp = (double)(y + regionPtr->y) * yScale;
	sy = ROUND(tmp);
	if (sy >= srcHeight) {
	    continue;
	}
	for (x = 0; x < regionPtr->width; x++) {
	    tmp = (double)(x + regionPtr->x) * xScale;
	    sx = ROUND(tmp);
	    if (sx >= srcWidth) {
		continue;
	    }
	    pixel = XGetPixel(src, sx, sy);
	    if (pixel) {
		XPutPixel(dest, x, y, pixel);
	    }
	}
    }

    /* Write the rotated image into the destination bitmap */

    XPutImage(display, destBitmap, bitmapGC, dest, 0, 0, 0, 0,
	regionPtr->width, regionPtr->height);
    XDestroyImage(src), XDestroyImage(dest);
    return destBitmap;
}

#endif /* WIN32 */

/*
 * -----------------------------------------------------------------------
 *
 * Blt_ScaleBitmap --
 *
 *	Same as Blt_ScaleBitmapRegion, except that the region is unbounded.
 *	The scaled bitmap will be a fully scaled version of the original,
 *	not a portion of it.
 *
 * Results:
 *	The new scaled bitmap is returned.
 *
 * Side Effects:
 *	A new pixmap is allocated. The caller must release this.
 *
 * -----------------------------------------------------------------------
 */
Pixmap
Blt_ScaleBitmap(tkwin, srcBitmap, srcWidth, srcHeight, scaledWidth,
    scaledHeight)
    Tk_Window tkwin;
    Pixmap srcBitmap;
    int srcWidth, srcHeight, scaledWidth, scaledHeight;
{
    ImageRegion region;

    region.x = region.y = 0;
    region.width = scaledWidth;
    region.height = scaledHeight;
    return Blt_ScaleBitmapRegion(tkwin, srcBitmap, srcWidth, srcHeight,
	scaledWidth, scaledHeight, &region);
}

/*LINTLIBRARY*/
void
Blt_InitTextStyle(stylePtr)
    TextStyle *stylePtr;
{
    /* Initialize these attributes to zero */
    stylePtr->leader = 0;
    stylePtr->shadow.offset = 0;
    stylePtr->padLeft = stylePtr->padRight = 0;
    stylePtr->padTop = stylePtr->padBottom = 0;
    stylePtr->shadow.color = stylePtr->activeColor =
	stylePtr->color = (XColor *)NULL;
    stylePtr->theta = 0.0;
    stylePtr->state = 0;
    stylePtr->anchor = TK_ANCHOR_CENTER;
    stylePtr->justify = TK_JUSTIFY_CENTER;
    stylePtr->font = NULL;
}

void
Blt_SetDrawTextStyle(stylePtr, font, gc, normalColor, activeColor,
    shadowColor, theta, anchor, justify, leader, shadowOffset)
    TextStyle *stylePtr;
    Tk_Font font;
    GC gc;
    XColor *normalColor, *activeColor, *shadowColor;
    double theta;
    Tk_Anchor anchor;
    Tk_Justify justify;
    int leader, shadowOffset;
{
    Blt_InitTextStyle(stylePtr);
    stylePtr->gc = gc;
    stylePtr->color = normalColor;
    stylePtr->activeColor = activeColor;
    stylePtr->shadow.color = shadowColor;
    stylePtr->font = font;
    stylePtr->theta = theta;
    stylePtr->anchor = anchor;
    stylePtr->justify = justify;
    stylePtr->leader = leader;
    stylePtr->shadow.offset = shadowOffset;
}

void
Blt_SetPrintTextStyle(stylePtr, font, fgColor, activeColor, shadowColor,
    theta, anchor, justify, leader, shadowOffset)
    TextStyle *stylePtr;
    Tk_Font font;
    XColor *fgColor, *activeColor, *shadowColor;
    double theta;
    Tk_Anchor anchor;
    Tk_Justify justify;
    int leader, shadowOffset;
{
    Blt_InitTextStyle(stylePtr);
    stylePtr->color = fgColor;
    stylePtr->activeColor = activeColor;
    stylePtr->shadow.color = shadowColor;
    stylePtr->font = font;
    stylePtr->theta = theta;
    stylePtr->anchor = anchor;
    stylePtr->justify = justify;
    stylePtr->leader = leader;
    stylePtr->shadow.offset = shadowOffset;
}

/*
 * -----------------------------------------------------------------
 *
 * DrawText --
 *
 *	Draw a text string, possibly rotated, using the the given
 *	window coordinates as an anchor for the text bounding box.
 *	If the text is not rotated, simply use the X text drawing
 *	routines. Otherwise, generate a bitmap of the rotated text.
 *
 * Results:
 *	Returns the x-coordinate to the right of the text.
 *
 * Side Effects:
 *	Text string is drawn using the given font and GC at the
 *	the given window coordinates.
 *
 *      The Stipple, FillStyle, and TSOrigin fields of the GC are
 *      modified for rotated text.  This assumes the GC is private,
 *      *not* shared (via Tk_GetGC)
 *
 * -----------------------------------------------------------------
 */
void
Blt_DrawTextLayout(tkwin, drawable, layoutPtr, stylePtr, x, y)
    Tk_Window tkwin;
    Drawable drawable;
    TextLayout *layoutPtr;
    TextStyle *stylePtr;	/* Text attribute information */
    int x, y;			/* Window coordinates to draw text */
{
    int width, height;
    double theta;
    Display *display;
    Pixmap bitmap;
    int active;

    display = Tk_Display(tkwin);
    theta = FMOD(stylePtr->theta, (double)360.0);
    if (theta < 0.0) {
	theta += 360.0;
    }
    active = stylePtr->state & STATE_ACTIVE;
    if (theta == 0.0) {

	/*
	 * This is the easy case of no rotation. Simply draw the text
	 * using the standard drawing routines.  Handle offset printing
	 * for engraved (disabled) and shadowed text.
	 */
	width = layoutPtr->width, height = layoutPtr->height;
	Blt_TranslateAnchor(x, y, width, height, stylePtr->anchor, &x, &y);
	if (stylePtr->state & (STATE_DISABLED | STATE_EMPHASIS)) {
	    TkBorder *borderPtr = (TkBorder *) stylePtr->border;
	    XColor *color1, *color2;

	    color1 = borderPtr->lightColor, color2 = borderPtr->darkColor;
	    if (stylePtr->state & STATE_EMPHASIS) {
		XColor *hold;

		hold = color1, color1 = color2, color2 = hold;
	    }
	    if (color1 != NULL) {
		XSetForeground(display, stylePtr->gc, color1->pixel);
	    }
	    DrawTextSegments(display, drawable, stylePtr->gc, x + 1, y + 1,
		layoutPtr);
	    if (color2 != NULL) {
		XSetForeground(display, stylePtr->gc, color2->pixel);
	    }
	    DrawTextSegments(display, drawable, stylePtr->gc, x, y, layoutPtr);

	    /* Reset the foreground color back to its original setting,
	     * so not to invalidate the GC cache. */
	    XSetForeground(display, stylePtr->gc, stylePtr->color->pixel);

	    return;		/* Done */
	}
	if ((stylePtr->shadow.offset > 0) && (stylePtr->shadow.color != NULL)) {
	    XSetForeground(display, stylePtr->gc, 
		stylePtr->shadow.color->pixel);
	    DrawTextSegments(display, drawable, stylePtr->gc,
		x + stylePtr->shadow.offset, y + stylePtr->shadow.offset, 
  	        layoutPtr);
	    XSetForeground(display, stylePtr->gc, stylePtr->color->pixel);
	}
	if (active) {
	    XSetForeground(display, stylePtr->gc, stylePtr->activeColor->pixel);
	}
	DrawTextSegments(display, drawable, stylePtr->gc, x, y, layoutPtr);
	if (active) {
	    XSetForeground(display, stylePtr->gc, stylePtr->color->pixel);
	}
	return;			/* Done */
    }
#ifdef WIN32
    if (Blt_DrawRotatedText(display, drawable, x, y, theta, stylePtr, 
		layoutPtr)) {
	return;
    }
#endif
    /*
     * Rotate the text by writing the text into a bitmap and rotating
     * the bitmap.  Set the clip mask and origin in the GC first.  And
     * make sure we restore the GC because it may be shared.
     */
    stylePtr->theta = theta;
    bitmap = Blt_CreateTextBitmap(tkwin, layoutPtr, stylePtr, &width, &height);
    if (bitmap == None) {
	return;
    }
    Blt_TranslateAnchor(x, y, width, height, stylePtr->anchor, &x, &y);
    theta = FMOD(theta, (double)90.0);
    XSetClipMask(display, stylePtr->gc, bitmap);

    if (stylePtr->state & (STATE_DISABLED | STATE_EMPHASIS)) {
	TkBorder *borderPtr = (TkBorder *) stylePtr->border;
	XColor *color1, *color2;

	color1 = borderPtr->lightColor, color2 = borderPtr->darkColor;
	if (stylePtr->state & STATE_EMPHASIS) {
	    XColor *hold;

	    hold = color1, color1 = color2, color2 = hold;
	}
	if (color1 != NULL) {
	    XSetForeground(display, stylePtr->gc, color1->pixel);
	}
	XSetClipOrigin(display, stylePtr->gc, x + 1, y + 1);
	XCopyPlane(display, bitmap, drawable, stylePtr->gc, 0, 0, width, height,
	    x + 1, y + 1, 1);
	if (color2 != NULL) {
	    XSetForeground(display, stylePtr->gc, color2->pixel);
	}
	XSetClipOrigin(display, stylePtr->gc, x, y);
	XCopyPlane(display, bitmap, drawable, stylePtr->gc, 0, 0, width, height,
	    x, y, 1);
	XSetForeground(display, stylePtr->gc, stylePtr->color->pixel);
    } else {
	if ((stylePtr->shadow.offset > 0) && (stylePtr->shadow.color != NULL)) {
	    XSetClipOrigin(display, stylePtr->gc, x + stylePtr->shadow.offset,
		y + stylePtr->shadow.offset);
	    XSetForeground(display, stylePtr->gc, 
		stylePtr->shadow.color->pixel);
	    XCopyPlane(display, bitmap, drawable, stylePtr->gc, 0, 0, width,
		height, x + stylePtr->shadow.offset, 
		y + stylePtr->shadow.offset, 1);
	    XSetForeground(display, stylePtr->gc, stylePtr->color->pixel);
	}
	if (active) {
	    XSetForeground(display, stylePtr->gc, stylePtr->activeColor->pixel);
	}
	XSetClipOrigin(display, stylePtr->gc, x, y);
	XCopyPlane(display, bitmap, drawable, stylePtr->gc, 0, 0, width, height,
	    x, y, 1);
	if (active) {
	    XSetForeground(display, stylePtr->gc, stylePtr->color->pixel);
	}
    }
    XSetClipMask(display, stylePtr->gc, None);
    Tk_FreePixmap(display, bitmap);
}

void
Blt_DrawText2(tkwin, drawable, string, stylePtr, x, y, areaPtr)
    Tk_Window tkwin;
    Drawable drawable;
    char string[];
    TextStyle *stylePtr;	/* Text attribute information */
    int x, y;			/* Window coordinates to draw text */
    Dim2D *areaPtr;
{
    TextLayout *layoutPtr;
    int width, height;
    double theta;

    if ((string == NULL) || (*string == '\0')) {
	return;			/* Empty string, do nothing */
    }
    layoutPtr = Blt_GetTextLayout(string, stylePtr);
    Blt_DrawTextLayout(tkwin, drawable, layoutPtr, stylePtr, x, y);
    theta = FMOD(stylePtr->theta, (double)360.0);
    if (theta < 0.0) {
	theta += 360.0;
    }
    width = layoutPtr->width;
    height = layoutPtr->height;
    if (theta != 0.0) {
	Blt_GetBoundingBox(width, height, theta, &width, &height,
	    (XPoint *)NULL);
    }
    free((char *)layoutPtr);
    areaPtr->width = width;
    areaPtr->height = height;
}

void
Blt_DrawText(tkwin, drawable, string, stylePtr, x, y)
    Tk_Window tkwin;
    Drawable drawable;
    char string[];
    TextStyle *stylePtr;	/* Text attribute information */
    int x, y;			/* Window coordinates to draw text */
{
    TextLayout *layoutPtr;

    if ((string == NULL) || (*string == '\0')) {
	return;			/* Empty string, do nothing */
    }
    layoutPtr = Blt_GetTextLayout(string, stylePtr);
    Blt_DrawTextLayout(tkwin, drawable, layoutPtr, stylePtr, x, y);
    free((char *)layoutPtr);
}

static GC
GetBitmapGC(tkwin)
    Tk_Window tkwin;
{
    int isNew;
    GC gc;
    Display *dpy;
    Tcl_HashEntry *hPtr;

    if (!initialized) {
	Tcl_InitHashTable(&bitmapGCTable, TCL_ONE_WORD_KEYS);
	initialized = TRUE;
    }
    dpy = Tk_Display(tkwin);
    hPtr = Tcl_CreateHashEntry(&bitmapGCTable, (char *)dpy, &isNew);
    if (isNew) {
	Pixmap bitmap;
	XGCValues gcValues;
	unsigned int gcMask;
	Window root;

	root = RootWindow(dpy, Tk_ScreenNumber(tkwin));
	bitmap = Tk_GetPixmap(dpy, root, 1, 1, 1);
	gcValues.foreground = gcValues.background = 0;
	gcMask = (GCForeground | GCBackground);
	gc = Blt_GetPrivateGCFromDrawable(tkwin, bitmap, gcMask, &gcValues);
	Tk_FreePixmap(dpy, bitmap);
	Tcl_SetHashValue(hPtr, (ClientData)gc);
    } else {
	gc = (GC)Tcl_GetHashValue(hPtr);
    }
    return gc;
}

void
Blt_ResetTextStyle(tkwin, stylePtr)
    Tk_Window tkwin;
    TextStyle *stylePtr;
{
    GC newGC;
    XGCValues gcValues;
    unsigned long gcMask;

    gcMask = GCFont;
    gcValues.font = Tk_FontId(stylePtr->font);
    if (stylePtr->color != NULL) {
	gcMask |= GCForeground;
	gcValues.foreground = stylePtr->color->pixel;
    }
    newGC = Tk_GetGC(tkwin, gcMask, &gcValues);
    if (stylePtr->gc != NULL) {
	Tk_FreeGC(Tk_Display(tkwin), stylePtr->gc);
    }
    stylePtr->gc = newGC;
}

void
Blt_FreeTextStyle(display, stylePtr)
    Display *display;
    TextStyle *stylePtr;
{
    if (stylePtr->gc != NULL) {
	Tk_FreeGC(display, stylePtr->gc);
    }
}
