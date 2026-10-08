/*
 * cxa_atexit.c -- the Itanium C++ ABI's finalization pair.
 *
 * THIS FILE IS APExp's, NOT EDG's, and it is the only one in this
 * directory that is: everything else in `libedg.a' is generated C
 * carried verbatim from `sys/src/external/edg/lib_src'.  It is here
 * rather than there so that a regeneration of that corpus cannot
 * clobber it and so that `git log' can tell the two apart.
 *
 * FROM: the first link of `cmd/edg', which answered
 *
 *	_Z12__call_dtorsv: undefined: __cxa_finalize in _Z12__call_dtorsv
 *
 * and nothing else undefined.  `lib_src/static_init.c:49' is literally
 * `__cxa_finalize(((void *)0));' and `include_c++/cxxabi.h:184'
 * declares it -- **EDG declares this pair and defines neither**,
 * because on every platform it has ever targeted the C++ runtime
 * (libsupc++, libc++abi, MSVC's) supplies them.  There is no such
 * runtime here, so the gap is APExp's to fill.  *Filling a gap a
 * vendored tree deliberately leaves to the platform is not patching
 * the vendored tree.*
 *
 * NOT IN libap, DELIBERATELY.  These are C++ ABI entry points, and
 * libap is linked by every program in the tree: adding a name there
 * that a C++ runtime may also define is the `reject' shape this tree
 * has already paid a build for.  In `libedg.a' they are archive
 * members, so they reach a link only when something references them.
 *
 * THE SPEC IS THE SPECIFICATION, and the reason to say so is that
 * "do not invent semantics" applies hardest where the behaviour is
 * easy to approximate.  Itanium C++ ABI 3.3.5.3:
 *
 *   - `__cxa_atexit(f, p, d)' registers `f(p)' to be called at exit
 *     or when the DSO named by `d' is unloaded; it returns zero on
 *     success and non-zero on failure.
 *   - `__cxa_finalize(d)' calls, IN REVERSE REGISTRATION ORDER, every
 *     registered function whose handle is `d' -- or ALL of them when
 *     `d' is null -- removing each from the list BEFORE calling it,
 *     and re-examining the list afterwards, since a destructor may
 *     register more.
 *
 * The remove-before-call and the re-scan are the two halves that a
 * plain reverse `for' loop gets wrong, and both are observable: a
 * destructor that registers another one would be skipped, and one
 * that calls `exit' a second time would run everything twice.
 * Sections 3 and 4 of the test ask exactly those.
 *
 * Plan 9 has no dlopen, so there is exactly one DSO and `d' is always
 * null or `&__dso_handle'.  The handle is still COMPARED rather than
 * ignored -- a parameter that is accepted and discarded is the
 * stub-answering-the-wrong-thing shape, and here it would silently
 * run the wrong destructors if this tree ever grew a second handle.
 *
 * `__dso_handle' IS IN ITS OWN FILE beside this one, and the split
 * is not tidiness.  The host already has one -- glibc's `crtbeginS.o'
 * defines it -- so a test that links this file would not link at all
 * with the handle in here:
 *
 *	multiple definition of `__dso_handle';
 *	crtbeginS.o: first defined here
 *
 * *That collision is the measurement that says the symbol belongs to
 * the crt and not to the runtime*, and separating the two is what
 * lets the same test file run on both machines.
 */

#include <stdlib.h>
#include <string.h>

struct fn {
	void	(*func)(void *);
	void	*arg;
	void	*dso;
};

static struct fn *list;
static int nfn;			/* entries in use */
static int afn;			/* entries allocated */

int
__cxa_atexit(void (*func)(void *), void *arg, void *dso)
{
	struct fn *p;
	int n;

	if(func == 0)
		return -1;
	if(nfn >= afn) {
		/*
		 * GROWN RATHER THAN FIXED, and the alternative is worse
		 * than it looks: a fixed table that fills up loses
		 * destructors with no diagnostic anywhere, because the
		 * generated code that calls this ignores the return
		 * value.  Failing to allocate still returns non-zero,
		 * which is all the ABI offers.
		 */
		n = afn ? afn * 2 : 32;
		p = realloc(list, n * sizeof(*p));
		if(p == 0)
			return -1;
		list = p;
		afn = n;
	}
	list[nfn].func = func;
	list[nfn].arg = arg;
	list[nfn].dso = dso;
	nfn++;
	return 0;
}

void
__cxa_finalize(void *dso)
{
	struct fn f;
	int i;

	/*
	 * RE-SCANNED FROM THE END EACH TIME rather than walked with a
	 * single descending index, because a destructor may register
	 * another one and the ABI says those must run too.  `nfn' is
	 * re-read every turn for that reason; the entry is COPIED and
	 * the slot removed BEFORE the call, so a destructor that
	 * reaches `exit' again cannot run itself a second time.
	 */
	for(;;) {
		for(i = nfn - 1; i >= 0; i--)
			if(list[i].func != 0 && (dso == 0 || list[i].dso == dso))
				break;
		if(i < 0)
			return;
		f = list[i];
		list[i].func = 0;
		/*
		 * Only the tail shrinks.  A hole in the middle stays a
		 * hole -- the scan above skips a cleared slot -- because
		 * compacting would move entries a nested finalize is in
		 * the middle of looking at.
		 */
		while(nfn > 0 && list[nfn-1].func == 0)
			nfn--;
		(*f.func)(f.arg);
	}
}
