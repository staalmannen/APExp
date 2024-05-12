
#include "objpak.h"

@implementation A : Object { int a_inst_1; } : { int a_class_1; }

- foo
{
   a_class_1 = 4;  /* this works
                    * and is a different variable than is referenced in
                    * the -foo method of class B
		    */

   return self;
}

@end

@implementation B : A { int b_inst_1; } : { int b_class_1; }

+ foo
{
   a_class_1 = 3;
   b_class_1 = 3;

   return self;
}

- foo 
{
   a_class_1 = 5; 
   a_inst_1 = 4;

   b_class_1 = 3;
   b_inst_1 = 2;

   return self;
}

@end


