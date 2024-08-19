
#include "objpak.h"

foo()  { id o = [OrdCltn new];[o at:5]; }

bar()  { [{ foo(); } ifError:{ :msg:rcv | printf("bar\n");[rcv halt:msg];}]; }

main() { [{ bar();} ifError:{ :msg:rcv | [msg printLine];[rcv halt:msg];}]; }

