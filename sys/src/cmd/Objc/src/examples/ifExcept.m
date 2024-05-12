
#include "objpak.h"

@implementation Foo : Object {}

+ new
{
    self = [super new];
    [self error:"Foo +new: uncaught exception"];
    return self;
}

@end

@implementation Bar : Object { id foo; }

+ new
{
    self = [super new];

    [{
	foo = [Foo new];
    } ifError: { :msg :rcv |
        foo = [String new];
	return self;
    }];

    return self;
}

+ new2
{
    self = [super new];
    foo  = [Foo new];
    return self;
}

@end

void main() 
{ 
    /* caught */
    [[Bar new] show]; 
    
    /* uncaught */
    [Bar new2];
}

