
#include "objpak.h"

typedef struct { int x; } T;
extern int z(int a);

@implementation Foo : Object { int x;int z; }

- foo { int x;T s; x = 3; s.x = z(3); return self; }

@end

