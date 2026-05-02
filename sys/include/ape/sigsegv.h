#ifndef _SIGSEGV_H
#define _SIGSEGV_H

#include <stddef.h>

typedef void (*sigsegv_handler_t) (void *address, int serious);
typedef void (*stackoverflow_handler_t) (int emergency, void *context);

int sigsegv_install_handler(sigsegv_handler_t);
int stackoverflow_install_handler(stackoverflow_handler_t, void *, size_t);
void sigsegv_deinstall_handler(void);
void stackoverflow_deinstall_handler(void);

#endif
