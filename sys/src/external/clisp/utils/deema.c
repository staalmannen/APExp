/* Work around CPP deficiencies: put _EMA_ instead of Empty Macro Arguments.
   Equivalent to sed -e 's/, *)/,_EMA_)/g' -e 's/, *,/,_EMA_,/g'
   Bruno Haible 29.12.1993
   Sam Steingold 2007-10-29
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int c;
  int c1 = -1;
  while (1) {
    c = getchar(); if (c==EOF) break;
    if ((c1 == ',') && ((c == ')') || (c == ',')))
      fputs("_EMA_",stdout);
    putchar(c);
    if (c != ' ')
      c1 = c;
  }
  if (ferror(stdin) || ferror(stdout) || fclose(stdout)) { exit(1); }
  return 0;
}

