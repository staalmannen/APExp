#ifndef __STDCOUNTOF_H__
#define __STDCOUNTOF_H__

/*
 * C23 <stdcountof.h>.
 *
 * countof(a) is the number of elements of the array a, as a size_t.
 * It works for arrays declared at file scope and for local arrays, but
 * NOT for function parameters of array type, since those are really
 * pointers -- countof would then silently return
 * sizeof(pointer)/sizeof(element).
 *
 * Spelled with __VA_ARGS__ rather than a single parameter so that a
 * compound literal containing commas still works:
 *      countof(((int[]){ 1, 2, 3 }))
 *
 * gnulib's stdcountof.in.h adds a _gl_verify_is_array() check built on
 * __builtin_types_compatible_p to turn the pointer case into a compile
 * error. pcc swallows __builtin_* and yields 0, so the check cannot do
 * its job here and is left out rather than faked.
 */

#include <stddef.h>

#define countof(...) \
	((size_t)(sizeof(__VA_ARGS__) / sizeof((__VA_ARGS__)[0])))

#endif /* __STDCOUNTOF_H__ */
