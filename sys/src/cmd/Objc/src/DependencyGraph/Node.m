
/* Node in graph of named nodes */

#include "objpak.h"
#include "Node.h"

@implementation Graphnode : String
  { BOOL isDefined, isMarked; id references; }
  
/* This node references anotherNode */
- addReference:anotherNode { /* extern id Set; */
  if (references == nil) references = [Set new];
  [references add:anotherNode];
  return self;
}

/* Mark myself and my dependents as reachable */
- mark { if (isMarked == YES) return nil;
  isMarked = YES;
  [references elementsPerform:@selector(mark)];
  return self;
}

/* Mark myself as defined */
- define { isDefined = YES; return self; }

/* Reply whether I'm reachable or defined */
- (BOOL)isMarked { return isMarked; }
- (BOOL)isDefined { return isDefined; }

@end

