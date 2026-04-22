/*
 * plan9/tkUnixPort.h --
 *
 *	Shim: redirects tkPort.h's #include "tkUnixPort.h" to the Plan 9
 *	port header.  The plan9/ directory appears first in the include
 *	path so this file shadows unix/tkUnixPort.h.
 */
#include "tkPlan9Port.h"
