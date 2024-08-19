
#include <signal.h>
#include "objpak.h"

static id timedBlocks;

static void
myHandler(int signo)
{
    if (timedBlocks) [ timedBlocks do: { :aBlock | [aBlock value]; }];
    alarm(1);
}

@implementation Block (MyBlock)

- doEverySecond
{
    timedBlocks = [ (timedBlocks)?timedBlocks:[OrdCltn new] add: self ];
    signal(SIGALRM,myHandler);alarm(1);
    return self;
}

@end

int
main(void)
{
    int c = 0;
    [ { printf("invocation %d\n",c++); } doEverySecond];
    while (1) pause();
}

