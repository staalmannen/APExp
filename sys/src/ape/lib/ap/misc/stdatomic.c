#include <lock.h>
#include <stdatomic.h>

/* Global spinlock for all non-trivial atomic operations */
static Lock __p9_atomic_lock;

static void __p9_lock(void)
{
	lock(&__p9_atomic_lock);
}

static void __p9_unlock(void)
{
	unlock(&__p9_atomic_lock);
}

/* 4-byte helpers — cast to int* from whatever <=32-bit type the macro passes */

int __p9_atomic_exchange_4(int *obj, int val)
{
	int old;
	__p9_lock();
	old = *obj;
	*obj = val;
	__p9_unlock();
	return old;
}

long long __p9_atomic_exchange_8(long long *obj, long long val)
{
	long long old;
	__p9_lock();
	old = *obj;
	*obj = val;
	__p9_unlock();
	return old;
}

int __p9_atomic_compare_exchange_4(int *obj, int *expected, int desired)
{
	int ok;
	__p9_lock();
	if (*obj == *expected) {
		*obj = desired;
		ok = 1;
	} else {
		*expected = *obj;
		ok = 0;
	}
	__p9_unlock();
	return ok;
}

int __p9_atomic_compare_exchange_8(long long *obj, long long *expected, long long desired)
{
	int ok;
	__p9_lock();
	if (*obj == *expected) {
		*obj = desired;
		ok = 1;
	} else {
		*expected = *obj;
		ok = 0;
	}
	__p9_unlock();
	return ok;
}

int __p9_atomic_fetch_add_4(int *obj, int val)
{
	int old;
	__p9_lock();
	old = *obj;
	*obj = old + val;
	__p9_unlock();
	return old;
}

long long __p9_atomic_fetch_add_8(long long *obj, long long val)
{
	long long old;
	__p9_lock();
	old = *obj;
	*obj = old + val;
	__p9_unlock();
	return old;
}

int __p9_atomic_fetch_sub_4(int *obj, int val)
{
	int old;
	__p9_lock();
	old = *obj;
	*obj = old - val;
	__p9_unlock();
	return old;
}

long long __p9_atomic_fetch_sub_8(long long *obj, long long val)
{
	long long old;
	__p9_lock();
	old = *obj;
	*obj = old - val;
	__p9_unlock();
	return old;
}

int __p9_atomic_fetch_and_4(int *obj, int val)
{
	int old;
	__p9_lock();
	old = *obj;
	*obj = old & val;
	__p9_unlock();
	return old;
}

long long __p9_atomic_fetch_and_8(long long *obj, long long val)
{
	long long old;
	__p9_lock();
	old = *obj;
	*obj = old & val;
	__p9_unlock();
	return old;
}

int __p9_atomic_fetch_or_4(int *obj, int val)
{
	int old;
	__p9_lock();
	old = *obj;
	*obj = old | val;
	__p9_unlock();
	return old;
}

long long __p9_atomic_fetch_or_8(long long *obj, long long val)
{
	long long old;
	__p9_lock();
	old = *obj;
	*obj = old | val;
	__p9_unlock();
	return old;
}

int __p9_atomic_fetch_xor_4(int *obj, int val)
{
	int old;
	__p9_lock();
	old = *obj;
	*obj = old ^ val;
	__p9_unlock();
	return old;
}

long long __p9_atomic_fetch_xor_8(long long *obj, long long val)
{
	long long old;
	__p9_lock();
	old = *obj;
	*obj = old ^ val;
	__p9_unlock();
	return old;
}

/* atomic_flag: uses tas() directly — more efficient, avoids deadlock */
int atomic_flag_test_and_set_explicit(atomic_flag *obj, memory_order order)
{
	(void)order;
	return tas(&obj->_val);
}

void atomic_flag_clear_explicit(atomic_flag *obj, memory_order order)
{
	(void)order;
	obj->_val = 0;
}
