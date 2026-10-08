/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/del_virt.c"
#line 17 "lib_src/error.h"
enum an_error_code {
ec_none,
ec_abort_header,
ec_terminate_called,
ec_terminate_returned,
ec_already_marked_for_destruction,
ec_main_called_more_than_once,
ec_pure_virtual_called,
ec_bad_cast,
ec_bad_typeid,
ec_array_not_from_vec_new,
ec_terminate_called_more_than_once,
ec_negative_vla_size,
ec_vla_allocation_failed,
ec_deleted_virtual_called,
ec_thread_registration_failed,
ec_last};


extern void __abort_execution(enum an_error_code err_code);
#line 26 "lib_src/del_virt.c"
extern void __cxa_deleted_virtual(void); void __cxa_deleted_virtual(void)




{
__abort_execution(ec_deleted_virtual_called); 
}
