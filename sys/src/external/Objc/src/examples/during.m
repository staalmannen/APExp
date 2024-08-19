
#include "during.h"

main()
{
  id c = [OrdCltn new];

  DURING
     [c at:10];
  HANDLER
     printf("catch\n");
  ENDHANDLER
}

