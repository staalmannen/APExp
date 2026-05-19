#include <dwarf.h>
#include <libdwarf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Simple DWARF parsing wrapper for adeb */

typedef struct DebugInfo DebugInfo;
struct DebugInfo {
    Dwarf_Debug dbg;
    int fd;
};

DebugInfo* dwarf_init(const char* path) {
    DebugInfo* info = (DebugInfo*)malloc(sizeof(DebugInfo));
    Dwarf_Error err;
    
    info->fd = open(path, O_RDONLY);
    if (info->fd < 0) {
        free(info);
        return NULL;
    }
    
    if (dwarf_init_b(info->fd, DW_GROUPNUMBER_ANY, NULL, NULL, &info->dbg, &err) != DW_DLV_OK) {
        close(info->fd);
        free(info);
        return NULL;
    }
    
    return info;
}

void dwarf_close(DebugInfo* info) {
    dwarf_finish(info->dbg);
    close(info->fd);
    free(info);
}
