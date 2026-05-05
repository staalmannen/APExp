#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

pid_t setpgid(pid_t pid, pid_t pgid) { return 0; }
pid_t getpgrp(void) { return getpid(); }
int setpgrp(void) { return 0; }
int tcsetpgrp(int fd, pid_t pgrp) { return 0; }
pid_t tcgetpgrp(int fd) { return getpid(); }
