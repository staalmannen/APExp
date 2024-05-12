
#include <objpak.h>

main(int argc,char *argv[])
{
    id set;
    int i,c,n = atoi(argv[1]);

    set = [Set new];
    for(i=1;i<=n;i++) [set add:[String sprintf:"%x",i]];

    for(i=n,c=0; i>0 ; i--) if ([set find:[String sprintf:"%d",i]]) c++;

    printf("%d\n",c);
}

