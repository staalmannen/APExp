
#include <stdio.h>
#include "dynclass.h"
#include <Object.h>
#include <ordcltn.h>

= MyCollection : OrderedCollection
{
  BOOL myBool;
  id myObject;
}

- (BOOL)myBool
{
  return myBool;
}

- myBool:(BOOL)flag
{
  myBool = flag;
  return self;
}

=:

main()
{
  id x = [MyCollection new];
  [x myBool:YES];
  printf("value is %i\n",[x myBool]);
}

