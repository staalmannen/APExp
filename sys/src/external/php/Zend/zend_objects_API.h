/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Zend Technologies Ltd. (http://www.zend.com)           |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@php.net>                                 |
   |          Zeev Suraski <zeev@php.net>                                 |
   +----------------------------------------------------------------------+
*/

#ifndef ZEND_OBJECTS_API_H
#define ZEND_OBJECTS_API_H

#include "zend_types.h"
#include "zend_gc.h"
#include "zend_alloc.h"
#include "zend_compile.h" /* For zend_property_info */

#define OBJ_BUCKET_INVALID			(1<<0)

#define IS_OBJ_VALID(o)				(!(((uintptr_t)(o)) & OBJ_BUCKET_INVALID))

#define SET_OBJ_INVALID(o)			((zend_object*)((((uintptr_t)(o)) | OBJ_BUCKET_INVALID)))

#define GET_OBJ_BUCKET_NUMBER(o)	(((intptr_t)(o)) >> 1)

#define SET_OBJ_BUCKET_NUMBER(o, n)	do { \
		(o) = (zend_object*)((((uintptr_t)(n)) << 1) | OBJ_BUCKET_INVALID); \
	} while (0)

#define ZEND_OBJECTS_STORE_ADD_TO_FREE_LIST(h) do { \
		SET_OBJ_BUCKET_NUMBER(EG(objects_store).object_buckets[(h)], EG(objects_store).free_list_head); \
		EG(objects_store).free_list_head = (h); \
	} while (0)

#define OBJ_RELEASE(obj) zend_object_release(obj)

typedef struct _zend_objects_store {
	zend_object **object_buckets;
	uint32_t top;
	uint32_t size;
	int free_list_head;
} zend_objects_store;

/* Global store handling functions */
BEGIN_EXTERN_C()
ZEND_API void ZEND_FASTCALL zend_objects_store_init(zend_objects_store *objects, uint32_t init_size);
ZEND_API void ZEND_FASTCALL zend_objects_store_call_destructors(zend_objects_store *objects);
ZEND_API void ZEND_FASTCALL zend_objects_store_mark_destructed(zend_objects_store *objects);
ZEND_API void ZEND_FASTCALL zend_objects_store_free_object_storage(zend_objects_store *objects, bool fast_shutdown);
ZEND_API void ZEND_FASTCALL zend_objects_store_destroy(zend_objects_store *objects);

/* Store API functions */
ZEND_API void ZEND_FASTCALL zend_objects_store_put(zend_object *object);
ZEND_API void ZEND_FASTCALL zend_objects_store_del(zend_object *object);

/* Called when the ctor was terminated by an exception */
static zend_always_inline void zend_object_store_ctor_failed(zend_object *obj)
{
	GC_ADD_FLAGS(obj, IS_OBJ_DESTRUCTOR_CALLED);
}

END_EXTERN_C()

static zend_always_inline void zend_object_release(zend_object *obj)
{
	if (GC_DELREF(obj) == 0) {
		zend_objects_store_del(obj);
	} else if (UNEXPECTED(GC_MAY_LEAK((zend_refcounted*)obj))) {
		gc_possible_root((zend_refcounted*)obj);
	}
}

static zend_always_inline size_t zend_object_properties_size(zend_class_entry *ce)
{
	/*
	 * ***THIS SUBTRACTION IS MEANT TO GO NEGATIVE, AND THE WHOLE
	 * EXPRESSION HAS TO BE EVALUATED AT size_t WIDTH FOR THAT TO
	 * WORK.***  `zend_object' ends in `zval properties_table[1]', so
	 * a class with NO properties wants one zval LESS than the
	 * struct -- the count is `int', the result is -1, and
	 * `sizeof(zval) * -1' is 2**64-16, which the caller's
	 * `sizeof(zend_object) + ...' wraps back to 40.  Upstream is
	 * right and relies on C: `sizeof' yields `size_t'.
	 *
	 * **kencc gives `sizeof' the type TULONG, which on amd64 is 32
	 * BITS** (`cc/com.c:894', deliberately, so an unprototyped call
	 * is not handed eight bytes). `size_t' here is 64. So the
	 * multiply happened in 32 bits and the result was ZERO-extended:
	 * `6c -S' is `SUBL' / `SALL $4' / **`MOVLQZX`**, giving
	 * 4294967280 where gcc gives 2**64-16.
	 *
	 * Every `exit()' in every script then asked the allocator for
	 * 4294967336 bytes, which it page-rounds to 4294971392 -- the
	 * number that killed `php -v'-sized scripts and the Phoronix
	 * Test Suite alike, at `zend_throw_unwind_exit' ->
	 * `zend_objects_new(&zend_ce_unwind_exit)', a class with zero
	 * properties and no guards.
	 *
	 * Doing the subtraction and the multiply in `ptrdiff_t' -- which
	 * is signed and size_t's width on every target -- makes kencc
	 * emit `MOVLQSX' / `SUBQ' / `SALQ' and agree with gcc. It is a
	 * no-op anywhere `sizeof' already has the width C requires.
	 *
	 * *The compiler is the deviation here, not php*; see
	 * `docs/notes/kencc.md'. This is the local fix, and the same
	 * idiom in any other package is still exposed.
	 */
	ptrdiff_t n = (ptrdiff_t)ce->default_properties_count
		- ((ce->ce_flags & ZEND_ACC_USE_GUARDS) ? 0 : 1);

	return (size_t)(n * (ptrdiff_t)sizeof(zval));
}

/* Allocates object type and zeros it, but not the standard zend_object and properties.
 * Standard object MUST be initialized using zend_object_std_init().
 * Properties MUST be initialized using object_properties_init(). */
static zend_always_inline void *zend_object_alloc(size_t obj_size, zend_class_entry *ce) {
	void *obj = emalloc(obj_size + zend_object_properties_size(ce));
	memset(obj, 0, obj_size - sizeof(zend_object));
	return obj;
}

ZEND_API ZEND_COLD zend_property_info *zend_get_property_info_for_slot_slow(zend_object *obj, zval *slot);

/* Use when 'slot' was obtained directly from obj->properties_table, or when
 * 'obj' can not be lazy. Otherwise, use zend_get_property_info_for_slot(). */
static inline zend_property_info *zend_get_property_info_for_slot_self(zend_object *obj, zval *slot)
{
	zend_property_info **table = obj->ce->properties_info_table;
	intptr_t prop_num = slot - obj->properties_table;
	ZEND_ASSERT(prop_num >= 0 && prop_num < obj->ce->default_properties_count);
	if (table[prop_num]) {
		return table[prop_num];
	} else {
		return zend_get_property_info_for_slot_slow(obj, slot);
	}
}

static inline zend_property_info *zend_get_property_info_for_slot(zend_object *obj, zval *slot)
{
	if (UNEXPECTED(zend_object_is_lazy_proxy(obj))) {
		return zend_lazy_object_get_property_info_for_slot(obj, slot);
	}
	zend_property_info **table = obj->ce->properties_info_table;
	intptr_t prop_num = slot - obj->properties_table;
	ZEND_ASSERT(prop_num >= 0 && prop_num < obj->ce->default_properties_count);
	if (table[prop_num]) {
		return table[prop_num];
	} else {
		return zend_get_property_info_for_slot_slow(obj, slot);
	}
}

/* Helper for cases where we're only interested in property info of typed properties. */
static inline zend_property_info *zend_get_typed_property_info_for_slot(zend_object *obj, zval *slot)
{
	zend_property_info *prop_info = zend_get_property_info_for_slot(obj, slot);
	if (prop_info && ZEND_TYPE_IS_SET(prop_info->type)) {
		return prop_info;
	}
	return NULL;
}

static zend_always_inline bool zend_check_method_accessible(const zend_function *fn, const zend_class_entry *scope)
{
	if (!(fn->common.fn_flags & ZEND_ACC_PUBLIC)
		&& fn->common.scope != scope
		&& (UNEXPECTED(fn->common.fn_flags & ZEND_ACC_PRIVATE)
			|| UNEXPECTED(!zend_check_protected(zend_get_function_root_class(fn), scope)))) {
		return false;
	}

	return true;
}

#endif /* ZEND_OBJECTS_H */
