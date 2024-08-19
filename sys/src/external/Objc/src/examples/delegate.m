
#include <objc.h>

static double delta;

@interface Foo : Object {}
+ delta:(double)x;
- (double)foo:(double)x;
- (double)bar:(double)x;
@end

@interface FooProxy : Object { id delegate; }
@end

@implementation Foo
+ delta:(double)x { delta = x; return self; }
- (double)foo:(double)x { return x - delta; }
- (double)bar:(double)x { return x + delta; }
@end

@implementation FooProxy
+ new { self = [super new];delegate = [Foo new]; return self; }
- doesNotUnderstand:msg { [msg sentTo:delegate]; return self; }
+ doesNotUnderstand:msg { [msg sentTo:Foo]; return self; }
@end

main()
{
  id x = [FooProxy new];
  [FooProxy delta:2.0];
  printf("%g\n",[x foo:0.5]);
  printf("%g\n",[x bar:0.5]);
}

