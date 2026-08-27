#ifndef __STDARG
#define __STDARG

typedef char *va_list;

#define va_start(list, start) list = (char *)(&(start)+1)
#define va_end(list)
#define va_arg(list, mode) (sizeof(mode)==1 ? ((mode *) (list += 4))[-4] : \
sizeof(mode)==2 ? ((mode *) (list += 4))[-2] : ((mode *) (list += sizeof(mode)))[-1])

/* va_copy is C99. Plan 9's va_list is a plain char *, so copying the
   object is the whole of it. */
#ifndef va_copy
#define va_copy(dst, src) \
	((dst) = (src))
#endif

#endif /* __STDARG */
