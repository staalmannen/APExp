
#include <objpak.h>
#include <cakit.h>

#define NUMPRIMES 4

/*
 * Smalltalk code small perfect numbers
 * 
 * |d c|
 * d := Integer primesUpTo:7.
 * c := OrderedCollection new.
 * d do:[ :p | c add:((2 raisedToInteger:(p-1)) * ((2 raisedToInteger:p) - 1)). ].
 */

int smallprimes[] = {2,3,5,7};

id perfect(void) 
{
  id c;
  int i;
  id two,one;

  c = [OrdCltn new];
  one = [BigInt int:1];
  two = [BigInt int:2];

  for(i=0;i<NUMPRIMES;i++) {
     int p = smallprimes[i];
     [c add:[[two power:(p-1)] multiply:[[two power:p] subtract:one]]];
  } 

  return c;
}

int main(int n,char* argv[])
{
  id m = perfect();
  [m printLine];
}

