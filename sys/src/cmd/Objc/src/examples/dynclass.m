
#include "objpak.h"

@interface DynClass : String {}
@end

@implementation DynClass
+ new { return [self str:"Hello world!"]; }
@end


