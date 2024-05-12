
#include "stdlib.h"
#include "objpak.h"

/*
 * sumit.m: simple program to sum integers.
 * 
 * example :
 *
 *  jot 10 0 1 | sumit -b   ---> 5 
 *  jot 10 0 1 | sumit -s   ---> 1
 *
 * sum() uses a Block with one argument.
 */

static int
sum(id c)
{
  int w = 0;
  [c do:{ :e | w += [e asInt]; }]; 
  return w;
}

static int
usage(void)
{
  printf("-s:Set -o:OrdCltn -b:Bag -t:SortCltn\n");
  exit(1); 
}

static id
options(int argc,char *argv[])
{
  id c = nil;

  if (argc==1) {
    usage();
  } else {
    char ch;
    while (EOF != (ch = getopt(argc,argv,"sobt"))) {
      switch (ch) {
	case 's': c = [Set new];break;
	case 'o': c = [OrdCltn new];break;
	case 'b': c = [Bag new];break;
	case 't': c = [SortCltn new];break;
	case '?': 
	default : usage();
      }
    }
  }

  return c;
}

int
main(int argc,char *argv[])
{
  char buf[BUFSIZ + 1];
  id c = options(argc,argv);

  while (NULL != fgets(buf,sizeof buf,stdin)) {
    [c add:[String str:buf]];
  }

  printf("%i\n",sum(c));
}

