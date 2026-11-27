#include <u.h>
#include <libc.h>
#include "xs_win.h"

/*
 * The window tree inside the one rio window.  Each window is a rectangle in its
 * parent; the root is the rio window.  A window is visible only where it lies
 * inside every ancestor, and the stacking order is the child list order, with
 * the last child on top.
 */

static xs_win	*allwins;
static xs_win	*rootw;
static xs_win	*focusw;
static XID	nextid = 2;		/* XSHIM_ROOT is 1 */
static int	rootx, rooty;

static void
unlinkchild(xs_win *c)
{
	if(c->prev != nil)
		c->prev->next = c->next;
	else
		c->parent->first = c->next;
	if(c->next != nil)
		c->next->prev = c->prev;
	else
		c->parent->last = c->prev;
	c->prev = c->next = nil;
}

/* add c as the topmost child of its parent */
static void
linktop(xs_win *c)
{
	xs_win *p;

	p = c->parent;
	c->prev = p->last;
	c->next = nil;
	if(p->last != nil)
		p->last->next = c;
	else
		p->first = c;
	p->last = c;
}

/* add c as the bottommost child of its parent */
static void
linkbottom(xs_win *c)
{
	xs_win *p;

	p = c->parent;
	c->next = p->first;
	c->prev = nil;
	if(p->first != nil)
		p->first->prev = c;
	else
		p->last = c;
	p->first = c;
}

void
xs_win_setroot(int x, int y, unsigned int w, unsigned int h)
{
	rootx = x;
	rooty = y;
	if(rootw == nil){
		rootw = malloc(sizeof *rootw);
		if(rootw == nil)
			return;
		memset(rootw, 0, sizeof *rootw);
		rootw->id = 1;
		rootw->mapped = 1;
		rootw->allnext = allwins;
		allwins = rootw;
		focusw = rootw;
	}
	rootw->w = w;
	rootw->h = h;
}

xs_win*
xs_win_root(void)
{
	return rootw;
}

xs_win*
xs_win_all(void)
{
	return allwins;
}

xs_win*
xs_win_find(XID id)
{
	xs_win *w;

	for(w = allwins; w != nil; w = w->allnext)
		if(w->id == id)
			return w;
	return nil;
}

xs_win*
xs_win_create(xs_win *parent, int x, int y, unsigned int w, unsigned int h,
	unsigned long bg, long mask)
{
	xs_win *c;

	if(parent == nil)
		return nil;
	c = malloc(sizeof *c);
	if(c == nil)
		return nil;
	memset(c, 0, sizeof *c);
	c->id = nextid++;
	c->parent = parent;
	c->x = x;
	c->y = y;
	c->w = w;
	c->h = h;
	c->bg = bg;
	c->mask = mask;
	linktop(c);
	c->allnext = allwins;
	allwins = c;
	return c;
}

void
xs_win_destroy(xs_win *w)
{
	xs_win **pp;

	if(w == nil || w == rootw)
		return;
	while(w->first != nil)
		xs_win_destroy(w->first);
	unlinkchild(w);
	for(pp = &allwins; *pp != nil; pp = &(*pp)->allnext)
		if(*pp == w){
			*pp = w->allnext;
			break;
		}
	if(focusw == w)
		focusw = rootw;
	free(w);
}

/* top: move to the top of the stack; otherwise to the bottom */
void
xs_win_raise(xs_win *w, int top)
{
	if(w == nil || w->parent == nil)
		return;
	unlinkchild(w);
	if(top)
		linktop(w);
	else
		linkbottom(w);
}

/* the absolute top-left of w, in display coordinates */
void
xs_win_abs(xs_win *w, int *ax, int *ay)
{
	int x, y;

	x = rootx;
	y = rooty;
	for(; w != nil && w->parent != nil; w = w->parent){
		x += w->x;
		y += w->y;
	}
	*ax = x;
	*ay = y;
}

/* the part of w that is inside its window and every ancestor, absolute */
void
xs_win_visible(xs_win *w, int *x0, int *y0, int *x1, int *y1)
{
	xs_win *a;
	int ax, ay, px, py;

	xs_win_abs(w, &ax, &ay);
	*x0 = ax;
	*y0 = ay;
	*x1 = ax + w->w;
	*y1 = ay + w->h;
	for(a = w->parent; a != nil; a = a->parent){
		xs_win_abs(a, &px, &py);
		if(px > *x0) *x0 = px;
		if(py > *y0) *y0 = py;
		if(px + (int)a->w < *x1) *x1 = px + a->w;
		if(py + (int)a->h < *y1) *y1 = py + a->h;
	}
	if(*x1 < *x0) *x1 = *x0;
	if(*y1 < *y0) *y1 = *y0;
}

static int
inside(xs_win *c, int px, int py)
{
	int x0, y0, x1, y1;

	xs_win_visible(c, &x0, &y0, &x1, &y1);
	return px >= x0 && px < x1 && py >= y0 && py < y1;
}

/* the deepest mapped window under the point, searching top of stack first */
static xs_win*
hit(xs_win *w, int px, int py)
{
	xs_win *c;

	for(c = w->last; c != nil; c = c->prev){
		if(!c->mapped)
			continue;
		if(inside(c, px, py))
			return hit(c, px, py);
	}
	return w;
}

xs_win*
xs_win_at(int ax, int ay)
{
	if(rootw == nil)
		return nil;
	return hit(rootw, ax, ay);
}

void
xs_win_rel(xs_win *w, int ax, int ay, int *rx, int *ry)
{
	int ox, oy;

	xs_win_abs(w, &ox, &oy);
	*rx = ax - ox;
	*ry = ay - oy;
}

/* the window that receives an event needing bit: w, or its nearest ancestor
 * that selected it, as X propagates events */
xs_win*
xs_win_select(xs_win *w, long bit)
{
	for(; w != nil; w = w->parent)
		if(w->mask & bit)
			return w;
	return nil;
}

/* the window keys go to: the one set by XSetInputFocus, else the topmost
 * mapped top-level window, else the root */
xs_win*
xs_win_focus(void)
{
	xs_win *c;

	if(focusw != rootw && focusw != nil)
		return focusw;
	for(c = rootw->last; c != nil; c = c->prev)
		if(c->mapped)
			return c;
	return rootw;
}

void
xs_win_setfocus(xs_win *w)
{
	focusw = (w != nil) ? w : rootw;
}
