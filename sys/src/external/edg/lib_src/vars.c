/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:07 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/vars.c"
# 21 "lib_src/main.h"
struct __linkl;
# 347 "lib_src/eh.h"
struct an_eh_stack_entry;
# 115 "lib_src/runtime.h"
typedef void (*a_void_function_ptr)(void);
# 47 "lib_src/eh.h"
typedef unsigned short a_region_number;
# 346
typedef struct an_eh_stack_entry *an_eh_stack_entry_ptr;
# 58 "include_c++/new.stdh" 3
typedef void (*_ZSt11new_handler)(void);
# 436 "lib_src/eh.h"
extern void __default_terminate(void);
# 60 "include_c++/exception.stdh" 3
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void _ZSt9terminatev(void);
# 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
# 36 "lib_src/main.h"
extern struct __linkl *__head;
# 419 "lib_src/eh.h"
extern a_region_number __eh_curr_region;




extern an_eh_stack_entry_ptr __curr_eh_stack_entry;


int __catch_clause_number = 0;



void *__caught_object_address = 0;
# 439
extern a_void_function_ptr __default_terminate_routine;
# 446
extern a_void_function_ptr __default_unexpected_routine;
# 211 "lib_src/runtime.h"
_ZSt11new_handler _new_handler = ((_ZSt11new_handler)0);
# 36 "lib_src/main.h"
struct __linkl *__head = ((struct __linkl *)0);
# 419 "lib_src/eh.h"
a_region_number __eh_curr_region = ((a_region_number)0U);




an_eh_stack_entry_ptr __curr_eh_stack_entry = ((an_eh_stack_entry_ptr)0);
# 439
a_void_function_ptr __default_terminate_routine = (&__default_terminate);
# 446
a_void_function_ptr __default_unexpected_routine = ((void (*)(void))(&_ZSt9terminatev));
