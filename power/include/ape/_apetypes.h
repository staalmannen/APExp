#if !defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN)
#define	__BYTE_ORDER	__BIG_ENDIAN
#endif

#if !defined(BYTE_ORDER) && defined(LITTLE_ENDIAN)
#define	BYTE_ORDER	BIG_ENDIAN
#endif
