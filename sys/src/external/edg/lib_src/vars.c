/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/vars.c"
#line 21 "lib_src/main.h"
struct __linkl;
#line 347 "lib_src/eh.h"
struct an_eh_stack_entry;
#line 115 "lib_src/runtime.h"
typedef void (*a_void_function_ptr)(void);
#line 47 "lib_src/eh.h"
typedef unsigned short a_region_number;
#line 346
typedef struct an_eh_stack_entry *an_eh_stack_entry_ptr;
#line 58 "include_c++/new.stdh"
typedef void (*_ZSt11new_handler)(void);
#line 436 "lib_src/eh.h"
extern void __default_terminate(void);
#line 60 "include_c++/exception.stdh"
extern void _ZSt9terminatev(void);
#line 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
#line 36 "lib_src/main.h"
extern struct __linkl *__head;
#line 419 "lib_src/eh.h"
extern a_region_number __eh_curr_region;




extern an_eh_stack_entry_ptr __curr_eh_stack_entry;


int __catch_clause_number = 0;



void *__caught_object_address = 0;
#line 439
extern a_void_function_ptr __default_terminate_routine;
#line 446
extern a_void_function_ptr __default_unexpected_routine;
#line 211 "lib_src/runtime.h"
_ZSt11new_handler _new_handler = ((_ZSt11new_handler)0);
#line 36 "lib_src/main.h"
struct __linkl *__head = ((struct __linkl *)0);
#line 419 "lib_src/eh.h"
a_region_number __eh_curr_region = ((a_region_number)0U);




an_eh_stack_entry_ptr __curr_eh_stack_entry = ((an_eh_stack_entry_ptr)0);
#line 439
a_void_function_ptr __default_terminate_routine = (&__default_terminate);
#line 446
a_void_function_ptr __default_unexpected_routine = ((void (*)(void))(&_ZSt9terminatev));
