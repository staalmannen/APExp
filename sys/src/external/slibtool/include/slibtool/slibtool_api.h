#ifndef SLIBTOOL_API_H
#define SLIBTOOL_API_H

#include <limits.h>

/* slbt_export */
#if	defined(__dllexport)
#define slbt_export __dllexport
#else
#define slbt_export
#endif

/* slbt_import */
#if	defined(__dllimport)
#define slbt_import __dllimport
#else
#define slbt_import
#endif

/* slbt_api */
#ifndef SLBT_APP
#if     defined (SLBT_EXPORT)
#define slbt_api slbt_export
#elif   defined (SLBT_IMPORT)
#define slbt_api slbt_import
#elif   defined (SLBT_STATIC)
#define slbt_api
#else
#define slbt_api
#endif
#else
#define slbt_api
#endif

#endif
