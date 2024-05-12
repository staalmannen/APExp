
#include <objpak.h>

main()
{
  id x = [Point new];
  id y = [String new];

  [y become:x];
  [y show];
}

