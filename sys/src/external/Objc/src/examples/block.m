
#include "objpak.h"

int main()
{
    int i = 13;
    id aCltn = [OrdCltn new];
    id aString = [String str:"hello"];

    [ { printf("value of i is %i\n",i);i = 14; } value ];

    printf("value of i is now %i\n",i);

    [ { [aCltn add:aString]; } value ];

    [aCltn show];

    printf("printing each element\n");
#ifndef OBJC_REFCNT
    [ aCltn do : { :e | [e print];printf("\n"); } ];
#endif

    [ { 
	if (i) {
	   [ { printf("block in block String: %s\n",[aString str]); } value];
	}
    } value ];
}

