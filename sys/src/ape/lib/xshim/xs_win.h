/*
 * xs_win.h -- the window tree.  Plain integers only, so the tree can be built
 * and tested on the host without libdraw.
 */
#include <xshim_types.h>

typedef struct xs_win xs_win;
struct xs_win {
	XID		id;
	xs_win		*parent;
	xs_win		*first, *last;	/* children, bottom of the stack first */
	xs_win		*prev, *next;	/* siblings */
	xs_win		*allnext;	/* every window, for lookup */
	int		x, y;		/* top-left, relative to the parent */
	unsigned int	w, h;
	int		mapped;
	unsigned long	bg;		/* background pixel */
	long		mask;		/* the event mask from XSelectInput */
};

/* the root window: the rio window's rectangle, in display coordinates */
extern void	xs_win_setroot(int x, int y, unsigned int w, unsigned int h);
extern xs_win*	xs_win_root(void);
extern xs_win*	xs_win_find(XID id);
extern xs_win*	xs_win_all(void);
extern xs_win*	xs_win_create(xs_win *parent, int x, int y, unsigned int w,
			unsigned int h, unsigned long bg, long mask);
extern void	xs_win_destroy(xs_win *w);
extern void	xs_win_raise(xs_win *w, int top);
extern void	xs_win_abs(xs_win *w, int *ax, int *ay);
extern void	xs_win_visible(xs_win *w, int *x0, int *y0, int *x1, int *y1);
extern xs_win*	xs_win_at(int ax, int ay);
extern void	xs_win_rel(xs_win *w, int ax, int ay, int *rx, int *ry);
extern xs_win*	xs_win_select(xs_win *w, long bit);
extern xs_win*	xs_win_focus(void);
extern void	xs_win_setfocus(xs_win *w);
