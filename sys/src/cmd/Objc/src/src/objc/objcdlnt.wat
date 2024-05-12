
/*
 * Portable Object Compiler - Postlink Auxiliary File
 * (c) 1997 David Stes. All rights reserved.
 *
 * WATCOM C postlink configuration file.
 * objc -dl initializer file for Windows NT DLL's.
 */

#include <stdio.h>
#include <windef.h>

extern void loadobjc(void *);
extern void unloadobjc(void *);

int __stdcall LibMain(HANDLE h,DWORD w,LPVOID r)
{
    if (w == DLL_PROCESS_ATTACH) {
	loadobjc(_msgControl);
    }
    if (w == DLL_PROCESS_DETACH) {
	unloadobjc(_msgControl);
    }

    return 1; /* success */
}

