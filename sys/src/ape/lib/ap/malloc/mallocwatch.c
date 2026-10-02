/*
 * The heap watchdog's STATE and ENTRY POINT, deliberately in an object
 * of their own.
 *
 * ------------------------------------------------------------------
 * WHY THIS FILE EXISTS -- A LINK ERROR THAT TOOK ROUNDS TO ARRIVE.
 *
 * `_apemain' (plan9/callmain.c) calls `_malloc_watchinit()' once, after
 * `_envsetup()' and before main. While that function lived in
 * `malloc.c', the reference pulled `malloc.$O' out of `libap.a' for
 * EVERY APE program -- and `malloc.$O' defines `malloc', `wd_fail' and
 * the arena. So the first program with an allocator of its own could
 * not link:
 *
 *	malloc: /amd64/lib/ape/libap.a(_malloc_watchinit):
 *	        redefinition: malloc
 *	(2416)  TEXT   malloc+0(SB),$72
 *
 * **f2c is that program.** `external/f2c/src/malloc.c' is upstream's
 * optional replacement allocator; upstream's own `makefile.u' ships it
 * OFF (`MALLOC =') with the comment *"some other systems do not
 * tolerate replacement of the system's malloc"*, and `mkfile.plan9',
 * which APExp's mkfile follows, turns it on. That had been fine for
 * years: nothing in libap ever referenced a symbol that only
 * `malloc.$O' defines, so the linker took f2c's `malloc' and never
 * looked at libap's object at all.
 *
 * *The watchdog silently removed the ability of any APE program to
 * supply its own allocator*, and **only a full `mk distclean' relink
 * could reveal it** -- `mk install' alone rebuilds `libap.a' without
 * relinking programs already built against it, so the breakage sat
 * invisible for every round between.
 *
 * ------------------------------------------------------------------
 * WHAT THE SPLIT BUYS, STATED AS A DEPENDENCY DIRECTION.
 *
 *	callmain.$O  -> mallocwatch.$O              (and no further)
 *	malloc.$O    -> mallocwatch.$O              (reads _malloc_wdmax)
 *	mallocwatch.$O -> getenv, write             (never malloc)
 *
 * The arrow that used to run the other way is gone. A program with its
 * own allocator still runs `_malloc_watchinit()'; it just sets a
 * variable that nothing in that program reads, which is precisely what
 * "the watchdog is off here" should look like -- not a link error.
 *
 * **This file must never call malloc, directly or otherwise**, or the
 * cycle comes back. `getenv' is a plain scan of `environ'
 * (ap/env/getenv.c) and `write' is a system call; that is the whole of
 * what it uses.
 *
 * ------------------------------------------------------------------
 * AND THE ORDERING TRAP THE OLD COMMENT IN malloc.c RECORDS STILL
 * APPLIES, so it is repeated here where the code is.
 *
 * The first version of the watchdog read `$APEXP_MALLOCMAX' lazily, on
 * the first sbrk, and **broke every APE program in the tree**. The
 * question I checked was "does getenv allocate?" -- it does not. That
 * was the wrong question. `environ' is CREATED BY a malloc
 * (`plan9/_envsetup.c:140' is `environ = pp = malloc(...)'), so on the
 * first allocation of every program `environ' is still null and
 * getenv's `while(*p != NULL)' faults at address 0 before main.
 * *A circular dependency, not a re-entrancy bug: the allocator asked
 * for state that the allocation was being made to create.*
 *
 * Hence: called from `_apemain', never from inside the allocator.
 * Allocations before that point are unwatched, which is the safe
 * direction to be wrong in.
 */
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

/*
 * The limit in bytes; 0 means off. Read by `wd_note()' in malloc.c on
 * every sbrk, and cleared by `wd_fail()' there before it aborts.
 */
size_t	_malloc_wdmax;

static int	wd_init;

/*
 * Hand-rolled string and number formatting, plan9/_apdbg.c's idiom:
 * the watchdog fires when the heap is already exhausted, so it must
 * not reach printf. Shared with wd_fail() in malloc.c, which is why
 * these are not static.
 */
char *
_malloc_wdstr(char *p, char *e, const char *s)
{
	while(*s && p < e)
		*p++ = *s++;
	return p;
}

char *
_malloc_wdnum(char *p, char *e, size_t v)
{
	char n[24];
	int i;

	i = 0;
	do {
		n[i++] = '0' + (int)(v%10);
		v /= 10;
	} while(v != 0 && i < (int)sizeof n);
	while(i > 0 && p < e)
		*p++ = n[--i];
	return p;
}

/*
 * Called once from _apemain, after _envsetup() and before main. Calling
 * it twice is harmless, and never calling it leaves the watchdog off,
 * which is the safe direction.
 */
void
_malloc_watchinit(void)
{
	const char *s;
	size_t v;

	if(wd_init)
		return;
	wd_init = 1;
	if(environ == 0)		/* belt and braces: see above */
		return;
	s = getenv("APEXP_MALLOCMAX");
	if(s == 0)
		return;
	v = 0;
	while(*s >= '0' && *s <= '9')
		v = v*10 + (size_t)(*s++ - '0');
	_malloc_wdmax = v * 1024 * 1024;

	/*
	 * SAY SO, and the reason is a round that was spent on nothing.
	 *
	 * A run was made with `APEX__MALLOCMAX=8' -- two underscores, no
	 * P. The watchdog was simply not armed, bash ran to full
	 * exhaustion and was killed exactly as it had been for weeks, and
	 * the output was indistinguishable from a watchdog that had armed
	 * and never reached its limit. **A misspelled variable name is
	 * invisible**, and the instrument's silence when unset -- which is
	 * correct and must stay -- is what makes it so.
	 *
	 * One line when it IS set repairs that: no line means not armed,
	 * so "nothing happened" can be told from "nothing happened yet".
	 *
	 * *An instrument has to say whether it is running*, or a null
	 * result has two explanations.
	 */
	if(_malloc_wdmax != 0){
		char buf[100], *p, *e;

		p = buf;
		e = buf + sizeof buf - 2;
		p = _malloc_wdstr(p, e, "libap: heap watchdog ARMED at ");
		p = _malloc_wdnum(p, e, v);
		p = _malloc_wdstr(p, e, " MB");
		*p++ = '\r';
		*p++ = '\n';
		write(2, buf, p - buf);
	}
}
