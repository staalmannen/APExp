#include <sigsegv.h>

int sigsegv_install_handler(sigsegv_handler_t handler) {
    return -1;
}

int stackoverflow_install_handler(stackoverflow_handler_t handler, void *extra_stack, size_t extra_stack_size) {
    return -1;
}

void sigsegv_deinstall_handler(void) {}
void stackoverflow_deinstall_handler(void) {}
