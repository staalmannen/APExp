#ifndef AIO_IMPL_H
#define AIO_IMPL_H

/* `hidden' is musl's internal visibility marker. It used to come
 * from the PUBLIC <features.h>, which also erased sqlite3.h's own
 * `unsigned char hidden[48];' member wherever that header came
 * second. Supplied here instead, the way `include/libm.h' and
 * `multibyte/internal.c' already did. */
#ifndef hidden
#define hidden
#endif
extern hidden volatile int __aio_fut;

extern hidden int __aio_close(int);
extern hidden void __aio_atfork(int);

#endif
