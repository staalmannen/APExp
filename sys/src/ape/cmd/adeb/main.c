#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Minimalist /proc interface for APE */

typedef struct Proc Proc;
struct Proc {
    int pid;
    int ctl;
    int mem;
    int regs;
    int status;
};

Proc* proc_open(int pid) {
    Proc* p = (Proc*)malloc(sizeof(Proc));
    char buf[128];
    
    p->pid = pid;
    snprintf(buf, sizeof(buf), "/proc/%d/ctl", pid);
    p->ctl = open(buf, O_WRONLY);
    
    snprintf(buf, sizeof(buf), "/proc/%d/mem", pid);
    p->mem = open(buf, O_RDWR);
    
    snprintf(buf, sizeof(buf), "/proc/%d/regs", pid);
    p->regs = open(buf, O_RDONLY);
    
    snprintf(buf, sizeof(buf), "/proc/%d/status", pid);
    p->status = open(buf, O_RDONLY);
    
    return p;
}

void proc_close(Proc* p) {
    if (p->ctl >= 0) close(p->ctl);
    if (p->mem >= 0) close(p->mem);
    if (p->regs >= 0) close(p->regs);
    if (p->status >= 0) close(p->status);
    free(p);
}

int proc_command(Proc* p, char* cmd) {
    return write(p->ctl, cmd, strlen(cmd));
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: adeb <pid>\n");
        return 1;
    }
    
    int pid = atoi(argv[1]);
    Proc* p = proc_open(pid);
    
    if (p->ctl < 0) {
        perror("Failed to open proc");
        return 1;
    }
    
    printf("Attached to process %d\n", pid);
    
    proc_command(p, "stop");
    
    /* Event loop would go here */
    
    proc_close(p);
    return 0;
}
