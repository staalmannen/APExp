
#include <Object.h>

@interface C1: Object
{}
-oneImp;
-multiImp;
@end

@interface C2: C1 {} @end
@interface C3: C2 {} @end
@interface C4: C3 {} @end
@interface C5: C4 {} @end

@implementation C1
-oneImp
{
  printf("This is oneImp in C1\n");
}
-multiImp
{
  printf("This is multiImp in C1\n");
}
@end

@implementation C2
-oneImp
{
  printf( " . "); [super oneImp];
}
-multiImp
{
  printf( " . "); [super multiImp];
}
@end


@implementation C3
-multiImp
{
  printf( " . "); [super multiImp];
}
@end
@implementation C4
-multiImp
{
  printf( " . "); [super multiImp];

}
@end
@implementation C5
-multiImp
{
  printf( " . "); [super multiImp];
}
@end

main()
{
  id obj;

  obj = [C5 new];

  printf("Calling oneImp  : ");  [obj oneImp];
  printf("Calling multiImp: "); [obj multiImp];
}

