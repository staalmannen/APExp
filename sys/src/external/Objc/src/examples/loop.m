
#include <objpak.h>

@implementation MyClass : Object
- release { printf("release\n");return [super release]; }
- print { printf("print");return self; }
@end

main()
{
  id c = [OrdCltn new];
  [c add:[MyClass new]];
  [c add:[MyClass new]];
  [c do: { :e | [e printLine]; } ];
}

