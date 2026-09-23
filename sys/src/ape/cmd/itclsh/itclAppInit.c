/*
 * itclAppInit.c -- a tclsh with [incr Tcl] linked in.
 *
 * WHY THIS FILE EXISTS AT ALL. itcl ships no appInit: upstream builds
 * it as a loadable extension, and `package require Itcl' reaches it
 * through Tcl's `load'. Plan 9 has no dlopen, so nothing is ever
 * loaded here -- the same wall perl's XS extensions ran into -- and
 * the package has to be compiled into an interpreter instead. Tk took
 * the same route: sys/src/ape/cmd/wish is Tcl's shell plus tkAppInit.c,
 * and this is its counterpart with the one difference that Tk supplies
 * its own appInit and itcl does not.
 *
 * Tcl_StaticLibrary IS THE LOAD-BEARING CALL, not Itcl_Init. Without
 * it Itcl_Init still runs and the commands still exist, but
 * `package require Itcl' goes looking for something to load, finds
 * nothing, and fails -- and itcl's own test suite opens with exactly
 * that line, as does every program that uses the package. Registering
 * it tells Tcl the package is already present and what its init
 * procedure was. Tk's appInit does the same thing one line after
 * Tk_Init (tkAppInit.c:149).
 *
 * THE TEST INTERPRETER IS THE SAME BINARY. Tcl and Tk keep their test
 * commands in separate objects and build a second binary (tcltest,
 * tktest); itcl does not -- itclTestRegisterC.c is in upstream's own
 * TEA_ADD_SOURCES, so the commands it registers are in libitcl.a
 * already. There is no itcltest target to write, and looking for one
 * is how a round gets spent.
 */

#include <tcl.h>
#include "itcl.h"

/*
 * Tcl 9 renamed this; itcl's own headers do the same dance in
 * itclStubLib.c. Spelled here so this file builds against either.
 */
#if TCL_MAJOR_VERSION < 9
#   define Tcl_StaticLibrary Tcl_StaticPackage
#endif

static int	AppInit(Tcl_Interp *interp);

int
main(
    int argc,
    char **argv)
{
    Tcl_Main(argc, argv, AppInit);
    return 0;			/* not reached; Tcl_Main exits */
}

static int
AppInit(
    Tcl_Interp *interp)
{
    if (Tcl_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
    if (Itcl_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
    Tcl_StaticLibrary(interp, "Itcl", Itcl_Init, Itcl_SafeInit);

    /*
     * Where an interactive shell looks for a user startup file. tclsh
     * uses ~/.tclshrc; this one is a different binary and gets its own
     * name so that running it does not quietly execute the other's.
     */
    Tcl_SetVar2(interp, "tcl_rcFileName", NULL, "~/.itclshrc",
	    TCL_GLOBAL_ONLY);
    return TCL_OK;
}
