#include <dwarf.h>
#include <libdwarf.h>
#include <fcntl.h>
#include <stdio.h>

/* Simple DWARF parsing wrapper for adeb */

typedef struct DebugInfo DebugInfo;
struct DebugInfo {
    Dwarf_Debug dbg;
    int fd;
};

DebugInfo* dwarf_init(const char* path) {
    DebugInfo* info = malloc(sizeof(DebugInfo));
    Dwarf_Error err;
    
    info->fd = open(path, OREAD);
    if (info->fd < 0) {
        free(info);
        return NULL;
    }
    
    if (dwarf_init(info->fd, DW_DLC_READ, NULL, NULL, &info->dbg, &err) != DW_DLV_OK) {
        close(info->fd);
        free(info);
        return NULL;
    }
    
    return info;
}

void dwarf_close(DebugInfo* info) {
    Dwarf_Error err;
    dwarf_finish(info->dbg, &err);
    close(info->fd);
    free(info);
}
