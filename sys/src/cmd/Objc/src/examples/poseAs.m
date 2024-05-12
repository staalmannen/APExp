
#include "poseAs.h"

int
main()
{
    id zot = [Foo new];

    [zot foo];
    [[Zot new] foo];
    [[Bar new] foo];

    [Bar poseAs:[Foo self]];

    [zot foo];
    
    [[Foo new] foo];
    [[Bar new] foo];
    [[Zot new] foo];
    [[[Object findClass:"Foo"] new] foo];
}

