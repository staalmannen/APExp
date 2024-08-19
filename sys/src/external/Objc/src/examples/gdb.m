
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "objpak.h"

int
foo()
{
    id c = [OrdCltn new];
    [c insert:[Point new] after:[Object new]];
}

int
main(int argc,STR *argv)
{
    [{
	foo(); 
    } ifError:{ :msg :rcv |
        char cmd[1024];
        pid_t pid = getpid();
	sprintf(cmd,"gdb %s %i",argv[0],pid);
	system(cmd);
    }];
}

