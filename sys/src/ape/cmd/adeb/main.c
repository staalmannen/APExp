#include <u.h>
#include <libc.h>

/* Minimalist /proc interface for Plan 9/9front */

typedef struct Proc Proc;
struct Proc {
    int pid;
    int ctl;
    int mem;
    int regs;
    int status;
};

Proc* proc_open(int pid) {
    Proc* p = malloc(sizeof(Proc));
    char buf[128];
    
    p->pid = pid;
    snprint(buf, sizeof(buf), "/proc/%d/ctl", pid);
    p->ctl = open(buf, OWRITE);
    
    snprint(buf, sizeof(buf), "/proc/%d/mem", pid);
    p->mem = open(buf, ORDWR);
    
    snprint(buf, sizeof(buf), "/proc/%d/regs", pid);
    p->regs = open(buf, OREAD);
    
    snprint(buf, sizeof(buf), "/proc/%d/status", pid);
    p->status = open(buf, OREAD);
    
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
        print("Usage: adeb <pid>\n");
        return 1;
    }
    
    int pid = atoi(argv[1]);
    Proc* p = proc_open(pid);
    
    if (p->ctl < 0) {
        perror("Failed to open proc");
        return 1;
    }
    
    print("Attached to process %d\n", pid);
    
    proc_command(p, "stop");
    
    /* Event loop would go here */
    
    proc_close(p);
    return 0;
}
