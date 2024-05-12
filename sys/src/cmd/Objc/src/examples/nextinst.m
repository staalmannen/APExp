
#include "objpak.h"

main()
{
  id s = [String str:"hello world!"];

  for(s = [String someInstance];s;s = [s nextInstance]) {
    [s printLine];
  }
}

