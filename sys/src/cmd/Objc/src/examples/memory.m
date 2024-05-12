
#include "objpak.h"

/* 
 * This program works on FreeBSD (using objc1.5.12).
 * Here's the output :
 * 
 * recovering after 2099586 objects!!
 * recovering after 2099586 objects!!
 * recovering after 2099586 objects!!
 * recovering after 2099586 objects!!
 * finished
 *
 */

@implementation Foo : Object { id aCltn; }

- foo
{
    int i;
    for(i=0;i<10000000;i++) [aCltn add:[Object new]];
    return self;
}

- bar
{
    aCltn = [OrdCltn new];

    [{
	[self foo];
    } ifError: { :msg :rcv |
    	printf("recovering after %i objects!!\n",[aCltn size]);
	[aCltn freeContents];
    }];

    printf("finished\n");
}

@end

void main() { [[Foo new] bar]; }


