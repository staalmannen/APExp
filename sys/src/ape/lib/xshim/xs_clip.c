#include <u.h>
#include <libc.h>
#include <xshim_types.h>
#include "xs_clip.h"

/*
 * The clip-mask handle table.
 *
 * A GC's clip_mask field is a Pixmap, an unsigned long, but a clip mask is a
 * pointer to a record.  On kencc, long is 32 bits and pointers are 64, so
 * storing the pointer truncates it.  Instead the record lives here, and the GC
 * holds its slot index plus one, which fits in the field.  Handle None (0)
 * means no clip mask.
 */

static xs_clip	**clips;
static ulong	nclips;

/* store c in a free slot and return its handle, or None if out of memory */
Pixmap
xs_clip_new(xs_clip *c)
{
	ulong i, old, n;
	xs_clip **t;

	for(i = 0; i < nclips; i++)
		if(clips[i] == nil){
			clips[i] = c;
			return i + 1;
		}
	old = nclips;
	n = old ? old * 2 : 16;
	t = realloc(clips, n * sizeof *t);
	if(t == nil)
		return None;
	memset(t + old, 0, (n - old) * sizeof *t);
	clips = t;
	nclips = n;
	clips[old] = c;
	return old + 1;
}

/* the record for a handle, or nil for None and unknown handles */
xs_clip*
xs_clip_get(Pixmap h)
{
	if(h == None || h > nclips)
		return nil;
	return clips[h - 1];
}

/* free the slot of a handle; the record itself is the caller's to free */
void
xs_clip_release(Pixmap h)
{
	if(h == None || h > nclips)
		return;
	clips[h - 1] = nil;
}
