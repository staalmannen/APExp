
#include <cakit.h>

void
series(int n)
{
    id x = [BigInt int:n];

    do {
	[x printLine];

	if ([x isEven]) {
	    x = [x divideDigit:2];
	} else {
	    x = [[x multiplyDigit:3] increment];
	}
    } while (![x isOne]);
}

void
main(int argc,char * argv[])
{
    if (argc!=2) {fprintf(stderr,"usage: %s <n>\n",argv[0]);exit(1);}
    series(atoi(argv[1]));
}

