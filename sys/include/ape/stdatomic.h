#ifndef _STDATOMIC_H
#define _STDATOMIC_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* kencc drops _Atomic as a qualifier; functional form is macro-handled below */
#define _Atomic(T) T

typedef enum {
	memory_order_relaxed = 0,
	memory_order_consume = 1,
	memory_order_acquire = 2,
	memory_order_release = 3,
	memory_order_acq_rel = 4,
	memory_order_seq_cst = 5
} memory_order;

/* Atomic types — plain types; Plan9 kencc has no hardware atomic qualifier */
typedef _Bool                   atomic_bool;
typedef char                    atomic_char;
typedef signed char             atomic_schar;
typedef unsigned char           atomic_uchar;
typedef short                   atomic_short;
typedef unsigned short          atomic_ushort;
typedef int                     atomic_int;
typedef unsigned int            atomic_uint;
typedef long                    atomic_long;
typedef unsigned long           atomic_ulong;
typedef long long               atomic_llong;
typedef unsigned long long      atomic_ullong;
typedef wchar_t                 atomic_wchar_t;
typedef int_least8_t            atomic_int_least8_t;
typedef uint_least8_t           atomic_uint_least8_t;
typedef int_least16_t           atomic_int_least16_t;
typedef uint_least16_t          atomic_uint_least16_t;
typedef int_least32_t           atomic_int_least32_t;
typedef uint_least32_t          atomic_uint_least32_t;
typedef int_least64_t           atomic_int_least64_t;
typedef uint_least64_t          atomic_uint_least64_t;
typedef int_fast8_t             atomic_int_fast8_t;
typedef uint_fast8_t            atomic_uint_fast8_t;
typedef int_fast16_t            atomic_int_fast16_t;
typedef uint_fast16_t           atomic_uint_fast16_t;
typedef int_fast32_t            atomic_int_fast32_t;
typedef uint_fast32_t           atomic_uint_fast32_t;
typedef int_fast64_t            atomic_int_fast64_t;
typedef uint_fast64_t           atomic_uint_fast64_t;
typedef intptr_t                atomic_intptr_t;
typedef uintptr_t               atomic_uintptr_t;
typedef size_t                  atomic_size_t;
typedef ptrdiff_t               atomic_ptrdiff_t;
typedef intmax_t                atomic_intmax_t;
typedef uintmax_t               atomic_uintmax_t;

/* atomic_flag: backed by int for tas() compatibility */
typedef struct { int _val; } atomic_flag;
#define ATOMIC_FLAG_INIT { 0 }

/* All operations use a global spinlock — lock-free = 0 */
#define ATOMIC_BOOL_LOCK_FREE     0
#define ATOMIC_CHAR_LOCK_FREE     0
#define ATOMIC_SHORT_LOCK_FREE    0
#define ATOMIC_INT_LOCK_FREE      0
#define ATOMIC_LONG_LOCK_FREE     0
#define ATOMIC_LLONG_LOCK_FREE    0
#define ATOMIC_WCHAR_T_LOCK_FREE  0
#define ATOMIC_POINTER_LOCK_FREE  0

#define ATOMIC_VAR_INIT(val) (val)

/* fence operations: Plan9 has a strong memory model; no explicit fence needed */
#define atomic_thread_fence(order) ((void)(order))
#define atomic_signal_fence(order) ((void)(order))

#define atomic_is_lock_free(obj)   0

/* Simple load/store via volatile — correct for single-threaded fence model */
#define atomic_init(obj, val)  (*(obj) = (val))

#define atomic_load_explicit(obj, order) \
	(*(volatile __typeof__(*(obj)) *)(obj))

#define atomic_store_explicit(obj, val, order) \
	(*(volatile __typeof__(*(obj)) *)(obj) = (val))

#define atomic_load(obj)       atomic_load_explicit(obj, memory_order_seq_cst)
#define atomic_store(obj, val) atomic_store_explicit(obj, val, memory_order_seq_cst)

/*
 * Helper functions implemented in stdatomic.c using Plan9's tas() spinlock.
 * Separate 4-byte and 8-byte variants because long=32-bit on amd64 in Plan9.
 */
extern int           __p9_atomic_exchange_4(int *, int);
extern long long     __p9_atomic_exchange_8(long long *, long long);
extern int           __p9_atomic_compare_exchange_4(int *, int *, int);
extern int           __p9_atomic_compare_exchange_8(long long *, long long *, long long);
extern int           __p9_atomic_fetch_add_4(int *, int);
extern long long     __p9_atomic_fetch_add_8(long long *, long long);
extern int           __p9_atomic_fetch_sub_4(int *, int);
extern long long     __p9_atomic_fetch_sub_8(long long *, long long);
extern int           __p9_atomic_fetch_and_4(int *, int);
extern long long     __p9_atomic_fetch_and_8(long long *, long long);
extern int           __p9_atomic_fetch_or_4(int *, int);
extern long long     __p9_atomic_fetch_or_8(long long *, long long);
extern int           __p9_atomic_fetch_xor_4(int *, int);
extern long long     __p9_atomic_fetch_xor_8(long long *, long long);
extern int           atomic_flag_test_and_set_explicit(atomic_flag *, memory_order);
extern void          atomic_flag_clear_explicit(atomic_flag *, memory_order);

#define atomic_flag_test_and_set(obj) \
	atomic_flag_test_and_set_explicit(obj, memory_order_seq_cst)
#define atomic_flag_clear(obj) \
	atomic_flag_clear_explicit(obj, memory_order_seq_cst)

/*
 * _Generic dispatch for the complex atomic operations.
 * Routes to 4-byte helpers for <=32-bit types, 8-byte helpers for 64-bit.
 * kencc supports _Generic (added 2026).
 */

/* atomic_exchange */
#define atomic_exchange_explicit(obj, val, order) \
	_Generic(*(obj), \
		long long:          __p9_atomic_exchange_8((long long *)(obj), (long long)(val)), \
		unsigned long long: __p9_atomic_exchange_8((long long *)(obj), (long long)(val)), \
		default:            __p9_atomic_exchange_4((int *)(obj), (int)(val)) \
	)
#define atomic_exchange(obj, val) \
	atomic_exchange_explicit(obj, val, memory_order_seq_cst)

/* atomic_compare_exchange_strong / weak (same implementation) */
#define atomic_compare_exchange_strong_explicit(obj, expected, desired, succ, fail) \
	_Generic(*(obj), \
		long long:          __p9_atomic_compare_exchange_8((long long *)(obj), (long long *)(expected), (long long)(desired)), \
		unsigned long long: __p9_atomic_compare_exchange_8((long long *)(obj), (long long *)(expected), (long long)(desired)), \
		default:            __p9_atomic_compare_exchange_4((int *)(obj), (int *)(expected), (int)(desired)) \
	)
#define atomic_compare_exchange_weak_explicit(obj, expected, desired, succ, fail) \
	atomic_compare_exchange_strong_explicit(obj, expected, desired, succ, fail)
#define atomic_compare_exchange_strong(obj, expected, desired) \
	atomic_compare_exchange_strong_explicit(obj, expected, desired, memory_order_seq_cst, memory_order_seq_cst)
#define atomic_compare_exchange_weak(obj, expected, desired) \
	atomic_compare_exchange_strong(obj, expected, desired)

/* atomic_fetch_add */
#define atomic_fetch_add_explicit(obj, val, order) \
	_Generic(*(obj), \
		long long:          __p9_atomic_fetch_add_8((long long *)(obj), (long long)(val)), \
		unsigned long long: __p9_atomic_fetch_add_8((long long *)(obj), (long long)(val)), \
		default:            __p9_atomic_fetch_add_4((int *)(obj), (int)(val)) \
	)
#define atomic_fetch_add(obj, val) \
	atomic_fetch_add_explicit(obj, val, memory_order_seq_cst)

/* atomic_fetch_sub */
#define atomic_fetch_sub_explicit(obj, val, order) \
	_Generic(*(obj), \
		long long:          __p9_atomic_fetch_sub_8((long long *)(obj), (long long)(val)), \
		unsigned long long: __p9_atomic_fetch_sub_8((long long *)(obj), (long long)(val)), \
		default:            __p9_atomic_fetch_sub_4((int *)(obj), (int)(val)) \
	)
#define atomic_fetch_sub(obj, val) \
	atomic_fetch_sub_explicit(obj, val, memory_order_seq_cst)

/* atomic_fetch_and */
#define atomic_fetch_and_explicit(obj, val, order) \
	_Generic(*(obj), \
		long long:          __p9_atomic_fetch_and_8((long long *)(obj), (long long)(val)), \
		unsigned long long: __p9_atomic_fetch_and_8((long long *)(obj), (long long)(val)), \
		default:            __p9_atomic_fetch_and_4((int *)(obj), (int)(val)) \
	)
#define atomic_fetch_and(obj, val) \
	atomic_fetch_and_explicit(obj, val, memory_order_seq_cst)

/* atomic_fetch_or */
#define atomic_fetch_or_explicit(obj, val, order) \
	_Generic(*(obj), \
		long long:          __p9_atomic_fetch_or_8((long long *)(obj), (long long)(val)), \
		unsigned long long: __p9_atomic_fetch_or_8((long long *)(obj), (long long)(val)), \
		default:            __p9_atomic_fetch_or_4((int *)(obj), (int)(val)) \
	)
#define atomic_fetch_or(obj, val) \
	atomic_fetch_or_explicit(obj, val, memory_order_seq_cst)

/* atomic_fetch_xor */
#define atomic_fetch_xor_explicit(obj, val, order) \
	_Generic(*(obj), \
		long long:          __p9_atomic_fetch_xor_8((long long *)(obj), (long long)(val)), \
		unsigned long long: __p9_atomic_fetch_xor_8((long long *)(obj), (long long)(val)), \
		default:            __p9_atomic_fetch_xor_4((int *)(obj), (int)(val)) \
	)
#define atomic_fetch_xor(obj, val) \
	atomic_fetch_xor_explicit(obj, val, memory_order_seq_cst)

#ifdef __cplusplus
}
#endif

#endif /* _STDATOMIC_H */
