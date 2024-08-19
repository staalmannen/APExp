
/* Dependency Graph */

#include "objpak.h"
#include "Graph.h"
#include "Node.h"

@implementation Graph : Set {}

/* Add a new node */
- addNode:(STR)aCharPointer
  { return [self filter:[Graphnode str:aCharPointer]]; }

/* Add a new node and define it */
- defineNode:(STR)aCharPointer
  { return [[self addNode:aCharPointer] define]; }

/* Mark the given node (and all nodes referenced by it) */
- mark:(STR)aNodeName
  { return [[self addNode:aNodeName] mark]; }

@end


 
