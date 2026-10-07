/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/error.c"
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
# 17 "lib_src/error.h"
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
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 730 "/usr/include/stdlib.h" 3
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void abort(void);
# 236 "/usr/include/stdio.h" 3
extern int fflush(FILE *__stream);
# 357
extern int fprintf(FILE *__stream, const char *__format, ...);
# 20 "lib_src/error.c"
static const char *_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code(enum an_error_code err_code);
# 77
static void _ZN28_INTERNAL_7_error_c_96006b1021display_abort_messageE13an_error_code(enum an_error_code err_code);
# 91
extern __attribute__((__noreturn__)) void __abort_execution(enum an_error_code err_code);
# 150 "/usr/include/stdio.h" 3
extern FILE *stdout;
extern FILE *stderr;
# 20 "lib_src/error.c"
static const char *_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code( enum an_error_code __11009_45_err_code)



{
auto const char *__11014_15_s = ((const char *)0);

switch ((int)__11009_45_err_code) {
case 1:
__11014_15_s = ((const char *)"C++ runtime abort");
goto __T715988280;
case 2:
__11014_15_s = ((const char *)"terminate() called by the exception handling mechanism");
goto __T715988280;
case 3:
__11014_15_s = ((const char *)"returned from a user-defined terminate() routine");
goto __T715988280;
case 4:
__11014_15_s = ((const char *)"internal error: static object marked for destruction more than once");

goto __T715988280;
case 6:
__11014_15_s = ((const char *)"a pure virtual function was called");
goto __T715988280;
case 7:
__11014_15_s = ((const char *)"invalid dynamic cast");
goto __T715988280;
case 8:
__11014_15_s = ((const char *)"invalid typeid operation");
goto __T715988280;
case 9:
__11014_15_s = ((const char *)"freeing array not allocated by an array new operation");
goto __T715988280;
case 10:
__11014_15_s = ((const char *)"terminate() called itself recursively");
goto __T715988280;
case 11:
__11014_15_s = ((const char *)"negative size for variable-length array");
goto __T715988280;
case 12:
__11014_15_s = ((const char *)"VLA allocation failed");
goto __T715988280;
case 13:
__11014_15_s = ((const char *)"a deleted virtual function was called");
goto __T715988280;
case 14:
__11014_15_s = ((const char *)"registration for thread termination notification failed");
goto __T715988280;
case 5:
default:
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/error.c")), 70); abort(); } ;
goto __T715988280;
} __T715988280:;
return __11014_15_s;
}


static void _ZN28_INTERNAL_7_error_c_96006b1021display_abort_messageE13an_error_code( enum an_error_code __11066_49_err_code)



{ auto FILE *__T716010824; auto const char *__T716011472; auto const char *__T716012208;
(((__T716010824 = stderr) , (__T716011472 = (_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code(ec_abort_header)))) , (__T716012208 = (_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code(__11066_49_err_code)))) , (fprintf(__T716010824, ((const char *)"%s: %s\n"), __T716011472, 
# 82
__T716012208)); 

}
# 91
__attribute__((__noreturn__)) void __abort_execution( enum an_error_code __11080_56_err_code)


{


_ZN28_INTERNAL_7_error_c_96006b1021display_abort_messageE13an_error_code(__11080_56_err_code);


fflush(stdout);
fflush(stderr);

abort(); 



}
