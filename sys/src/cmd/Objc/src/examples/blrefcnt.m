
#include <objpak.h>

id blk,blk2;

foo()
{
  id o,p,q;
  o = [Cltn new];
  p = [Set new];
  blk = { o = [Point new];q = [Bag new];[Stack new]; };
  blk2 = { o = nil; };
}

main()
{
  msgFlag++;
  foo();
  [blk value];
  blk = nil; /* doesn't free Point (2 refs) */
}

