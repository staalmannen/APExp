/*
 * xs_clip.h -- the clip-mask record and its handle table.  Depends only on the
 * shared types, so the table can be built and tested without libdraw.
 */
#include <xshim_types.h>

/* the clip mask a GC carries: a pixmap, or a region (Tk's TkpClipMask) */
typedef struct xs_clip {
	int type;
	union {
		Pixmap pixmap;
		Region region;
	} value;
} xs_clip;

/* the handle table in xs_clip.c: a GC stores a handle, never a pointer */
extern Pixmap	xs_clip_new(xs_clip *c);
extern xs_clip*	xs_clip_get(Pixmap h);
extern void	xs_clip_release(Pixmap h);
