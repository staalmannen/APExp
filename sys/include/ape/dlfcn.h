/* dlfcn.h stub header, based on google ai suggestion on search */

#ifndef _DLFCN_H
#define _DLFCN_H

#ifdef __cplusplus
extern "C" {
#endif

// Mode flags
#define RTLD_LAZY 1
#define RTLD_NOW 2
#define RTLD_GLOBAL 4
#define RTLD_LOCAL 8

// Error message function
static inline char *dlerror(void) { return "Dynamic loading not supported"; }

// Function stubs
static inline void *dlopen(const char *filename, int flag) { return NULL; }
static inline void *dlsym(void *handle, const char *symbol) { return NULL; }
static inline int dlclose(void *handle) { return -1; }

#ifdef __cplusplus
}
#endif

#endif /* _DLFCN_H */


