
#include <stdio.h>
#include <dl.h>
#include <errno.h>
#include <string.h>
#include "objpak.h"

void main()
{
    shl_t handle;
    id s = [String new];

    /* compile with -dynamic, build dynclass.sl with -dl */

    handle = shl_load("dynclass.sl",BIND_IMMEDIATE | BIND_VERBOSE,0L);
    if (!handle) [String error:strerror(errno)];

    [[String subclasses] do:{ :each | printf("%s\n",[each name]); }];

    s = [[Object findClass:"DynClass"] new];
    [s show];
}

