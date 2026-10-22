/*
 * iso646.h -- alternative spellings for the operators ISO 646 cannot
 * express.  Normative Addendum 1 to C90 (1995), C99 7.9, C11/C17 7.9.
 *
 * WHERE THIS CAME FROM.  EDG's front end ships two include directories,
 * and `include_c99' holds exactly ONE file: its own `iso646.h'.  Asking
 * what in that directory APExp did not already cover answered in one
 * command -- **this header did not exist here at all**, and it is the
 * whole of the gap.  A sweep of the 31 headers the C standards require
 * then named four more absentees (`stdalign.h', `threads.h',
 * `stdbit.h', `stdckdint.h'); those are C11 and C23 and are recorded in
 * `docs/releases/0.6.md' rather than written blind.
 *
 * *The directory's NAME is misleading and that is worth saying*: these
 * eleven macros are C95, not C99.  So "what C99 features does EDG need"
 * has the answer "none of them -- it needs a C95 header".
 *
 * THE BARE-WORD SWEEP WAS RUN FIRST, which is this tree's rule before
 * any name goes into a public APE header: `and', `or', `not' and the
 * rest are UNRESERVED, and declaring `reject' in `libnet.h' once cost a
 * build because `<sys/socket.h>' reached it and flex has
 * `extern int reject;'.  **The two cases are not alike, and the reason
 * is reachability**: nothing in `sys/include/ape' includes this file and
 * nothing ever should, so these macros exist only in a translation unit
 * that asked for them by name.  A program that spells a variable `or'
 * and also includes `<iso646.h>' is already ill-formed by the standard
 * that defines both.
 *
 * EMPTY IN C++, where all eleven are KEYWORDS rather than macros
 * (C++ [depr.c.headers], and `<ciso646>' has been empty since C++98).
 * Defining them would be a constraint violation.  EDG's own copy has no
 * such guard and does not need one -- `cpfe' searches
 * `edg/include_c99' ahead of `/sys/include/ape', so it never reaches
 * this file -- but a guard here costs nothing and does not depend on
 * that ordering staying true.
 */
#ifndef _ISO646_H
#define _ISO646_H

#ifndef __cplusplus

#define and	&&
#define and_eq	&=
#define bitand	&
#define bitor	|
#define compl	~
#define not	!
#define not_eq	!=
#define or	||
#define or_eq	|=
#define xor	^
#define xor_eq	^=

#endif /* !__cplusplus */

#endif /* _ISO646_H */
