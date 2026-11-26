/*
 * X11/Xlib.h -- the Xlib API as the xshim library provides it.
 *
 * The old XdotOrg header set was removed with the deprecated Equis build.
 * Tk's Plan 9 backend does not use it: it has its own copy under
 * sys/src/external/tk/xlib/X11, which its include path puts first.  See
 * sys/include/ape/xshim.h for what is implemented.  Programs that need
 * Xutil.h, keysym.h or other X headers will not compile until those are
 * provided.
 */
#include <xshim.h>
