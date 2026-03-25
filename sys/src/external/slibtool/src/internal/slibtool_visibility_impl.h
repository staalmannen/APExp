#ifndef SLIBTOOL_VISIBILITY_IMPL_H
#define SLIBTOOL_VISIBILITY_IMPL_H

/**********************************************************************/
/* PE targets: __dllexport suffices for the purpose of exporting only */
/* the desired subset of global symbols; this makes the visibility    */
/* attribute not only redundant, but also tricky if not properly      */
/* supported by the toolchain.                                        */
/*                                                                    */
/* When targeting Midipix hosts, where elf-like visibility is fully   */
/* supported and may be detected via the __PE_VISIBILITY__ macro,     */
/* we utilize the attribute to render private symbols invisibile      */
/* to dlsym(), as well as reduce the size of the .gotstrs section.    */
/**********************************************************************/

#if defined(__PE_VISIBILITY__)
#define slbt_hidden _ATTR_VISIBILITY_HIDDEN
#elif defined(__PE__)
#define slbt_hidden
#elif defined(_ATTR_VISIBILITY_HIDDEN)
#define slbt_hidden _ATTR_VISIBILITY_HIDDEN
#else
#define slbt_hidden
#endif

#endif
