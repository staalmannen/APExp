#ifndef SLIBTOOL_DPRINTF_IMPL_H
#define SLIBTOOL_DPRINTF_IMPL_H

#ifdef  ARGV_DRIVER
#define argv_dprintf slbt_dprintf
#endif

int slbt_dprintf(int fd, const char * fmt, ...);

#endif
