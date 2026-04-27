/*
 * plan9/tkUnixDefault.h --
 *
 *	Shim: shadows unix/tkUnixDefault.h so that plan9/ can appear on the
 *	include path without exposing unix/ (which drags in tkUnixPort.h and
 *	<X11/Xproto.h>).  We include the Unix defaults directly via relative
 *	path — that file has no #includes of its own, only #define macros.
 */
#include "../unix/tkUnixDefault.h"
