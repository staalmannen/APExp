
#include <stdio.h>
#include <dlfcn.h>
#include "objpak.h"

void main()
{
    void *handle;
    id myObj= [String new];

    handle = dlopen("dynclass.so",1);
    if (!handle) [Object error:dlerror()];
    [[String subclasses] do:{ :each | printf("%s\n",[each name]); }];
    dlclose(handle);

    handle = dlopen("dynclass.so",1);
    if (!handle) [Object error:dlerror()];
    myObj = [[Object idOfSTR:"DynClass"] new];
    [myObj show];
}

