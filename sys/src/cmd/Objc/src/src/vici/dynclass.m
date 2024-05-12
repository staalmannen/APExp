
#include "dynclass.h"

= MyObject : String
+ new { return [super str:"hello world !"]; }
- printLine { return [super printLine]; }
=:

