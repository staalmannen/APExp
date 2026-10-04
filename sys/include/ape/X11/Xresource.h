/*
 * Xresource.h -- minimal stub for Plan 9 Tk builds.
 * X resource manager types are not used by Tk on Plan 9.
 */
#ifndef _XRESOURCE_H_
#define _XRESOURCE_H_

typedef int XrmQuark;
typedef const char *XrmString;
typedef void *XrmDatabase;
typedef struct { int size; void *addr; } XrmValue;
typedef XrmValue *XrmValuePtr;

#endif /* _XRESOURCE_H_ */
