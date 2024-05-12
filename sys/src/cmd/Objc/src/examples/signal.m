
#include <objpak.h>
#include <signal.h>

void handler(int signo)
{
    [ String error:"division by zero"];
}

main(void)
{
    int a,b,c;
    signal(SIGFPE,handler);

    [{ a=0;b=1;c=b/a; } ifError:{ :msg :rcv | printf("got one\n"); }];
    [{ a=0;b=1;c=b/a; } ifError:{ :msg :rcv | printf("got second one\n"); }];

    a=0;b=1;c=b/a;
}

