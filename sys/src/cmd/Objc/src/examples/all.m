
#include "objpak.h"

@implementation Foo : String {}
@end

@implementation Bar : Foo {}
@end

static void 
p(int tabs,id c)
{
    while (tabs--) printf("\t");printf("%s\n",[c name]);
}

static void 
phierarchy(id c)
{
    int tabs = 0;
    id b = { :e | p(tabs++,e);[[e subclasses] do:b];tabs--;};
    [b value:c];
}

void
main()
{
    [Foo new];[Bar new];
    phierarchy(Object);
}

